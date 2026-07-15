
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const1b2483991f3f37e4463261cd;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_constd01925b37634a1a9d24159d8;


void slog_rules_cfd10cb788fe91aa2(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid63DM823 const1b2483991f3f37e4463261cd) (let __trel8kgv824 const1064263932db82f2cf6d4ac2) (let __tcol4DTW825 const5feceb66ffc86f38d952786c) (let __trel1EPH826 const1064263932db82f2cf6d4ac2) (let __tcol1nYC827 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x1 __d0 __d1 k l m p r v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid63DM823 __trel8kgv824 __tcol4DTW825 (1 2 3 4 0)) (tycheck k (accept int) __trid63DM823 __trel1EPH826 __tcol1nYC827 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __3a4N822 l k v)) map.slog:41 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1;  u32 sid0;  u32 sid2;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup5638x40x0x0x1");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("mbranch")->getStructId();
      sid2 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const1b2483991f3f37e4463261cd;
      u64 v_c1 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c11 = _t[6];
        u64 v_c12 = _t[7];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid0 || decode_struct_id(v_c8) == sid1 || decode_struct_id(v_c8) == sid2))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c8, v_c7, v_c12}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let __tconst6eAo583 constd01925b37634a1a9d24159d8) (let _00024sqc6wkF529 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst6eAo583 __t73fy364) (body (join mp_fromlist (0 1) 0 __t2ahz365 _00024seq0) (letp _00024sql7nK3527 (aslst _00024seq0)) (let chk8mrx1060 (llen _00024sql7nK3527)) (eq _00024sqc6wkF529 chk8mrx1060)) (head (emit mp_fromlist_ans (1 0) __t73fy364 __t2ahz365)) map.slog:127 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_fromlistindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("_enum");
      driver_index = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("mp_fromlist");
      mp_fromlistindex4 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constd01925b37634a1a9d24159d8;
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c13, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m12) {
        u64 v_c15 = m12[1];
        if (buckethash(v_c15) != bucket) return;
        slog::join_all<2>(mp_fromlistindex4, [&](const std::array<u64,2>& m13) {
          u64 v_c16 = m13[0]; u64 v_c17 = m13[1];
          bool ok14 = true;
          u64 v_c18 = _prim_aslst(db, v_c17, &ok14);
          if (!ok14) return;
          u64 v_c19 = _prim_llen(db, v_c18);
          if (v_c19 == slog_error) { slog::emit_pending_error(db, "map.slog:127"); return; }
          if (v_c14 != v_c19) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c16}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:127", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), true);
  // (crule (pre (let __tconst1EMh391 const6b86b273ff34fce19d6b804e)) (probe mp_has0_ans (1 0) 1 __tconst1EMh391 __t3RjP390) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t3RjP390 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (join-old $sup5638x67x0x0x0 (1 2 0 3) 2 (1 2 0 3) k t __t51a7389 v) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t51a7389)) (head (emit mp_put_soft_ans (0 1) __t51a7389 t)) map.slog:68 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_has0index15;  slog::Index** mp_put_softindex16;  slog::Index** $sup5638x67x0x0x0index17;  slog::Index** mp_put_softindex18;  slog::Index** mp_has0delta19;  slog::Index** $sup5638x67x0x0x0delta20;  slog::Index** mp_put_softdelta21;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("mp_has0_ans");
      driver_index = readrel26->getIndex(ord25, true);
      std::vector<u16> ord27({0, 2, 1});
      slog::Relation* readrel28 = db->getRelation("mp_has0");
      mp_has0index15 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 2, 1});
      slog::Relation* readrel30 = db->getRelation("mp_has0");
      mp_has0delta19 = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({1, 2, 3, 0});
      slog::Relation* readrel32 = db->getRelation("mp_put_soft");
      mp_put_softindex16 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0, 3});
      slog::Relation* readrel34 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index17 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 0, 3});
      slog::Relation* readrel36 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0delta20 = readrel36->getIndex(ord35, true);
      std::vector<u16> ord37({1, 2, 3, 0});
      slog::Relation* readrel38 = db->getRelation("mp_put_soft");
      mp_put_softindex18 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 3, 0});
      slog::Relation* readrel40 = db->getRelation("mp_put_soft");
      mp_put_softdelta21 = readrel40->getIndex(ord39, true);
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c20, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m41) {
        u64 v_c21 = m41[1];
        if (buckethash(v_c21) != bucket) return;
        slog::join_probe_old<3,1>(mp_has0index15, mp_has0delta19, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m42) {
          u64 v_c7 = m42[1]; u64 v_c22 = m42[2];
          if (!slog::exists_probe<4,2>(mp_put_softindex16, std::array<u64,4>{v_c22, v_c7, 0, 0})) return;
          slog::join_probe_old<4,2>($sup5638x67x0x0x0index17, $sup5638x67x0x0x0delta20, std::array<u64,4>{v_c7, v_c22, 0, 0}, [&](const std::array<u64,4>& m43) {
            u64 v_c23 = m43[2]; u64 v_c12 = m43[3];
            slog::join_probe_old<4,4>(mp_put_softindex18, mp_put_softdelta21, std::array<u64,4>{v_c22, v_c7, v_c12, v_c23}, [&](const std::array<u64,4>& m44) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c22}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_has0_ans", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), false);
  // (crule (pre) (scan mp_put_soft __t6FhG321 s k v) (body (exists mp_union (1 2 0) 1 s) (exists mp_put_soft_ans (0 1) 1 __t6FhG321) (join mleaf (1 2 0) 2 k v __t4k6G319) (join mp_union (1 2 0) 2 s __t4k6G319 __t4hCg320) (join mp_put_soft_ans (0 1) 1 __t6FhG321 r)) (head (emit mp_union_ans (0 1) __t4hCg320 r)) map.slog:93 #f)
  class ReadTask50 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex45;  slog::Index** mp_put_soft_ansindex46;  slog::Index** mleafindex47;  slog::Index** mp_unionindex48;  slog::Index** mp_put_soft_ansindex49;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("mp_union_ans");
      head_index[0] = readrel52->getIndex(ord51, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("mp_union");
      mp_unionindex45 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex46 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 0});
      slog::Relation* readrel58 = db->getRelation("mleaf");
      mleafindex47 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("mp_union");
      mp_unionindex48 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex49 = readrel62->getIndex(ord61, false);
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c12 = _t[3];
        if (!slog::exists_probe<3,1>(mp_unionindex45, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_soft_ansindex46, std::array<u64,2>{v_c24, 0})) return;
        slog::join_probe<3,2>(mleafindex47, std::array<u64,3>{v_c7, v_c12, 0}, [&](const std::array<u64,3>& m63) {
          u64 v_c26 = m63[2];
          slog::join_probe<3,2>(mp_unionindex48, std::array<u64,3>{v_c25, v_c26, 0}, [&](const std::array<u64,3>& m64) {
            u64 v_c27 = m64[2];
            slog::join_probe<2,1>(mp_put_soft_ansindex49, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m65) {
              u64 v_c11 = m65[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c27, v_c11}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), false);
  // (crule (pre) (scan mp_has0 __t070u328 __t0fD4327 k) (body (join mbranch (0 1 2 3 4) 1 __t0fD4327 p m l r)) (head (emit $sup5638x59x0x0x0 (0 1 2 3 4 5) __t070u328 k l m p r)) map.slog:60 #f)
  class ReadTask67 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex66;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord68({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel69 = db->getRelation("$sup5638x59x0x0x0");
      head_index[0] = readrel69->getIndex(ord68, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord70({0, 1, 2, 3, 4});
      slog::Relation* readrel71 = db->getRelation("mbranch");
      mbranchindex66 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[2];
        slog::join_probe<5,1>(mbranchindex66, std::array<u64,5>{v_c29, 0, 0, 0, 0}, [&](const std::array<u64,5>& m72) {
          u64 v_c10 = m72[1]; u64 v_c9 = m72[2]; u64 v_c8 = m72[3]; u64 v_c11 = m72[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c28, v_c7, v_c8, v_c9, v_c10, v_c11}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_has0", _fires);
  
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
  // (crule (pre) (scan mp_msk __t5IgR220 p n) (body (exists mbranch (1 2 3 4 0) 1 p) (exists $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mp_join (1 2 3 4 0) 1 p) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (join mbranch (1 2 3 4 0) 1 p m l r __t0o62217) (cmp lt m n) (exists mp_join (1 2 3 4 0) 2 p __t0o62217) (exists mp_union (1 2 0) 1 __t0o62217) (join $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 l m p r __t0o62217 n __t5xrH216 q __t0BoC218 u v) (neq q __v0) (join mbranch (1 2 3 4 0) 5 q n u v __t0BoC218) (exists mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (join mp_join (1 2 3 4 0) 4 p __t0o62217 q __t0BoC218 __t7HEI219) (join mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask87 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex73;  slog::Index** $sup5638x110x0x0x0index74;  slog::Index** mbranchindex75;  slog::Index** mp_joinindex76;  slog::Index** mp_msk_ansindex77;  slog::Index** mbranchindex78;  slog::Index** mp_joinindex79;  slog::Index** mp_unionindex80;  slog::Index** $sup5638x110x0x0x0index81;  slog::Index** mbranchindex82;  slog::Index** mp_unionindex83;  slog::Index** mp_joinindex84;  slog::Index** mp_unionindex85;  slog::Index** mp_join_ansindex86;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("mp_union_ans");
      head_index[0] = readrel89->getIndex(ord88, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord90({1, 2, 3, 4, 0});
      slog::Relation* readrel91 = db->getRelation("mbranch");
      mbranchindex73 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel93 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index74 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({2, 0, 1, 3, 4});
      slog::Relation* readrel95 = db->getRelation("mbranch");
      mbranchindex75 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 3, 4, 0});
      slog::Relation* readrel97 = db->getRelation("mp_join");
      mp_joinindex76 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex77 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 3, 4, 0});
      slog::Relation* readrel101 = db->getRelation("mbranch");
      mbranchindex78 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 2, 3, 4, 0});
      slog::Relation* readrel103 = db->getRelation("mp_join");
      mp_joinindex79 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("mp_union");
      mp_unionindex80 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel107 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index81 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 3, 4, 0});
      slog::Relation* readrel109 = db->getRelation("mbranch");
      mbranchindex82 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({0, 1, 2});
      slog::Relation* readrel111 = db->getRelation("mp_union");
      mp_unionindex83 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 3, 4, 0});
      slog::Relation* readrel113 = db->getRelation("mp_join");
      mp_joinindex84 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 1, 2});
      slog::Relation* readrel115 = db->getRelation("mp_union");
      mp_unionindex85 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({0, 1});
      slog::Relation* readrel117 = db->getRelation("mp_join_ans");
      mp_join_ansindex86 = readrel117->getIndex(ord116, false);
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c31 = _t[2];
        if (!slog::exists_probe<5,1>(mbranchindex73, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x110x0x0x0index74, std::array<u64,11>{v_c31, v_c10, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex75, std::array<u64,5>{v_c31, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex76, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex77, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m118) {
          u64 v_c32 = m118[1];
          slog::join_probe<5,1>(mbranchindex78, std::array<u64,5>{v_c10, 0, 0, 0, 0}, [&](const std::array<u64,5>& m119) {
            u64 v_c9 = m119[1]; u64 v_c8 = m119[2]; u64 v_c11 = m119[3]; u64 v_c33 = m119[4];
            u64 v_c34 = _prim_lt(db, v_c9, v_c31);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c34) return;
            if (!slog::exists_probe<5,2>(mp_joinindex79, std::array<u64,5>{v_c10, v_c33, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex80, std::array<u64,3>{v_c33, 0, 0})) return;
            slog::join_probe<11,6>($sup5638x110x0x0x0index81, std::array<u64,11>{v_c8, v_c9, v_c10, v_c11, v_c33, v_c31, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m121) {
              u64 v_c35 = m121[6]; u64 v_c36 = m121[7]; u64 v_c37 = m121[8]; u64 v_c38 = m121[9]; u64 v_c12 = m121[10];
              if (v_c36 == v_c32) return;
              slog::join_probe<5,5>(mbranchindex82, std::array<u64,5>{v_c36, v_c31, v_c38, v_c12, v_c37}, [&](const std::array<u64,5>& m122) {
                if (!slog::exists_probe<3,3>(mp_unionindex83, std::array<u64,3>{v_c35, v_c33, v_c37})) return;
                slog::join_probe<5,4>(mp_joinindex84, std::array<u64,5>{v_c10, v_c33, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m123) {
                  u64 v_c39 = m123[4];
                  slog::join_probe<3,3>(mp_unionindex85, std::array<u64,3>{v_c35, v_c33, v_c37}, [&](const std::array<u64,3>& m124) {
                    slog::join_probe<2,1>(mp_join_ansindex86, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m125) {
                      u64 v_c40 = m125[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c40}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst1EMh391 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t3RjP390 t k) (body (join mp_has0_ans (0 1) 2 __t3RjP390 __tconst1EMh391) (exists mp_put_soft (1 2 3 0) 2 t k) (join $sup5638x67x0x0x0 (1 2 0 3) 2 k t __t51a7389 v) (join mp_put_soft (1 2 3 0) 4 t k v __t51a7389)) (head (emit mp_put_soft_ans (0 1) __t51a7389 t)) map.slog:68 #f)
  class ReadTask130 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex126;  slog::Index** mp_put_softindex127;  slog::Index** $sup5638x67x0x0x0index128;  slog::Index** mp_put_softindex129;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel132->getIndex(ord131, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex126 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 3, 0});
      slog::Relation* readrel136 = db->getRelation("mp_put_soft");
      mp_put_softindex127 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 0, 3});
      slog::Relation* readrel138 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index128 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 3, 0});
      slog::Relation* readrel140 = db->getRelation("mp_put_soft");
      mp_put_softindex129 = readrel140->getIndex(ord139, false);
  
    }
    ReadTask130(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[2];
        slog::join_probe<2,2>(mp_has0_ansindex126, std::array<u64,2>{v_c21, v_c20}, [&](const std::array<u64,2>& m141) {
          if (!slog::exists_probe<4,2>(mp_put_softindex127, std::array<u64,4>{v_c22, v_c7, 0, 0})) return;
          slog::join_probe<4,2>($sup5638x67x0x0x0index128, std::array<u64,4>{v_c7, v_c22, 0, 0}, [&](const std::array<u64,4>& m142) {
            u64 v_c23 = m142[2]; u64 v_c12 = m142[3];
            slog::join_probe<4,4>(mp_put_softindex129, std::array<u64,4>{v_c22, v_c7, v_c12, v_c23}, [&](const std::array<u64,4>& m143) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c22}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask130* _cont = new ReadTask130(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask130(db,b), false);
  // (crule (pre (let __tconst1EMh391 const6b86b273ff34fce19d6b804e)) (scan mp_put_soft __t51a7389 t k v) (body (join $sup5638x67x0x0x0 (1 2 0 3) 4 k t __t51a7389 v) (exists mp_has0_ans (1 0) 1 __tconst1EMh391) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t3RjP390) (join mp_has0_ans (0 1) 2 __t3RjP390 __tconst1EMh391)) (head (emit mp_put_soft_ans (0 1) __t51a7389 t)) map.slog:68 #f)
  class ReadTask149 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x67x0x0x0index144;  slog::Index** mp_has0_ansindex145;  slog::Index** mp_has0index146;  slog::Index** mp_has0_ansindex147;  slog::Index** mp_has0delta148;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel151->getIndex(ord150, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord152({1, 2, 0, 3});
      slog::Relation* readrel153 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index144 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 0});
      slog::Relation* readrel155 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex145 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 2, 0});
      slog::Relation* readrel157 = db->getRelation("mp_has0");
      mp_has0index146 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 0});
      slog::Relation* readrel159 = db->getRelation("mp_has0");
      mp_has0delta148 = readrel159->getIndex(ord158, true);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex147 = readrel161->getIndex(ord160, false);
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[2];
        u64 v_c12 = _t[3];
        slog::join_probe<4,4>($sup5638x67x0x0x0index144, std::array<u64,4>{v_c7, v_c22, v_c23, v_c12}, [&](const std::array<u64,4>& m162) {
          if (!slog::exists_probe<2,1>(mp_has0_ansindex145, std::array<u64,2>{v_c20, 0})) return;
          slog::join_probe_old<3,2>(mp_has0index146, mp_has0delta148, std::array<u64,3>{v_c22, v_c7, 0}, [&](const std::array<u64,3>& m163) {
            u64 v_c21 = m163[2];
            slog::join_probe<2,2>(mp_has0_ansindex147, std::array<u64,2>{v_c21, v_c20}, [&](const std::array<u64,2>& m164) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c22}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask149* _cont = new ReadTask149(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask149(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mbranch __t3rQ8350 q n u v) (body (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 4 v n q u) (exists mp_union (2 0 1) 1 __t3rQ8350) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 v) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t05l7352 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t3rQ8350 __t05l7352) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t05l7352 l m p r __t4mLe355) (exists mp_msk (1 2 0) 3 p n __t4mLe355) (exists mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_union (0 1 2) 3 (0 1 2) __t05l7352 __t6yxH356 __t3rQ8350) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask187 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index165;  slog::Index** mp_unionindex166;  slog::Index** mp_mskindex167;  slog::Index** mp_msk_ansindex168;  slog::Index** mp_unionindex169;  slog::Index** $sup5638x107x0x0x0index170;  slog::Index** mbranchindex171;  slog::Index** mp_unionindex172;  slog::Index** mp_mskindex173;  slog::Index** $sup5638x107x0x0x1index174;  slog::Index** mp_mskindex175;  slog::Index** mp_msk_ansindex176;  slog::Index** mbranchindex177;  slog::Index** mp_unionindex178;  slog::Index** mp_mskindex179;  slog::Index** mp_msk_ansindex180;  slog::Index** mp_unionindex181;  slog::Index** mp_union_ansindex182;  slog::Index** mbranchdelta183;  slog::Index** mp_uniondelta184;  slog::Index** mp_mskdelta185;  slog::Index** mp_uniondelta186;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord188({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel189 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index165 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({2, 0, 1});
      slog::Relation* readrel191 = db->getRelation("mp_union");
      mp_unionindex166 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({2, 0, 1});
      slog::Relation* readrel193 = db->getRelation("mp_msk");
      mp_mskindex167 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 0});
      slog::Relation* readrel195 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex168 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({2, 0, 1});
      slog::Relation* readrel197 = db->getRelation("mp_union");
      mp_unionindex169 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel199 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index170 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 3, 4, 0});
      slog::Relation* readrel201 = db->getRelation("mbranch");
      mbranchindex171 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({2, 0, 1});
      slog::Relation* readrel203 = db->getRelation("mp_union");
      mp_unionindex172 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 0});
      slog::Relation* readrel205 = db->getRelation("mp_msk");
      mp_mskindex173 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel207 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index174 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 2, 0});
      slog::Relation* readrel209 = db->getRelation("mp_msk");
      mp_mskindex175 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex176 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 3, 4, 0});
      slog::Relation* readrel213 = db->getRelation("mbranch");
      mbranchindex177 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 3, 4, 0});
      slog::Relation* readrel215 = db->getRelation("mbranch");
      mbranchdelta183 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({0, 1, 2});
      slog::Relation* readrel217 = db->getRelation("mp_union");
      mp_unionindex178 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1, 2});
      slog::Relation* readrel219 = db->getRelation("mp_union");
      mp_uniondelta184 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("mp_msk");
      mp_mskindex179 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("mp_msk");
      mp_mskdelta185 = readrel223->getIndex(ord222, true);
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex180 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("mp_union");
      mp_unionindex181 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("mp_union");
      mp_uniondelta186 = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("mp_union_ans");
      mp_union_ansindex182 = readrel231->getIndex(ord230, false);
  
    }
    ReadTask187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c38 = _t[3];
        u64 v_c12 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x107x0x0x1index165, std::array<u64,10>{v_c12, v_c31, v_c36, v_c38, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex166, std::array<u64,3>{v_c42, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex167, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex168, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex169, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x107x0x0x0index170, std::array<u64,9>{v_c36, v_c31, v_c38, v_c12, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m232) {
          u64 v_c43 = m232[4]; u64 v_c8 = m232[5]; u64 v_c9 = m232[6]; u64 v_c10 = m232[7]; u64 v_c11 = m232[8];
          u64 v_c44 = _prim_lt(db, v_c9, v_c31);
          if (v_c44 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c44) return;
          if (!slog::exists_probe<5,4>(mbranchindex171, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex172, std::array<u64,3>{v_c42, v_c43, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex173, std::array<u64,3>{v_c10, v_c31, 0})) return;
          slog::join_probe<10,9>($sup5638x107x0x0x1index174, std::array<u64,10>{v_c12, v_c31, v_c36, v_c38, v_c43, v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,10>& m234) {
            u64 v_c45 = m234[9];
            if (!slog::exists_probe<3,3>(mp_mskindex175, std::array<u64,3>{v_c10, v_c31, v_c45})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex176, std::array<u64,2>{v_c45, v_c36})) return;
            slog::join_probe_old<5,4>(mbranchindex177, mbranchdelta183, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,5>& m235) {
              u64 v_c46 = m235[4];
              slog::join_probe_old<3,3>(mp_unionindex178, mp_uniondelta184, std::array<u64,3>{v_c43, v_c46, v_c42}, [&](const std::array<u64,3>& m236) {
                slog::join_probe_old<3,3>(mp_mskindex179, mp_mskdelta185, std::array<u64,3>{v_c10, v_c31, v_c45}, [&](const std::array<u64,3>& m237) {
                  slog::join_probe<2,2>(mp_msk_ansindex180, std::array<u64,2>{v_c45, v_c36}, [&](const std::array<u64,2>& m238) {
                    slog::join_probe_old<3,2>(mp_unionindex181, mp_uniondelta186, std::array<u64,3>{v_c46, v_c12, 0}, [&](const std::array<u64,3>& m239) {
                      u64 v_c47 = m239[2];
                      slog::join_probe<2,1>(mp_union_ansindex182, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m240) {
                        u64 v_c32 = m240[1];
                        u64 v_c48 = _prim_band(db, v_c10, v_c31);
                        if (v_c48 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c49 = _prim_gt(db, v_c48, v_c41);
                        if (v_c49 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c49) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c43, v_c32, v_c31, v_c36, v_c38});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c36, v_c31, v_c38, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan $sup5638x40x0x0x0 __d0 k l m p r v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7eaA149) (join-old mp_msk_ans (0 1) 2 (0 1) __t7eaA149 p)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t7eaA149 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask247 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex242;  slog::Index** mp_mskindex243;  slog::Index** mp_msk_ansindex244;  slog::Index** mp_mskdelta245;  slog::Index** mp_msk_ansdelta246;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord248({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel249 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel249->getIndex(ord248, false);
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex242 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("mp_msk");
      mp_mskindex243 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("mp_msk");
      mp_mskdelta245 = readrel255->getIndex(ord254, true);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex244 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta246 = readrel259->getIndex(ord258, true);
  
    }
    ReadTask247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c10 = _t[4];
        u64 v_c11 = _t[5];
        u64 v_c12 = _t[6];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex242, std::array<u64,2>{v_c10, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex243, mp_mskdelta245, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m260) {
          u64 v_c50 = m260[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex244, mp_msk_ansdelta246, std::array<u64,2>{v_c50, v_c10}, [&](const std::array<u64,2>& m261) {
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c50, v_c10, v_c5, v_c7, v_c8, v_c9, v_c11, v_c12}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mp_put __t1I5N72 __t687K71 k v) (body (exists $sup5638x40x0x0x1 (0 2 7 1 3 4 5 6) 3 __t1I5N72 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put (2 3 0 1) 2 k v) (join $sup5638x40x0x0x0 (0 1 6 2 3 4 5) 3 __t1I5N72 k v l m p r) (exists mbranch (1 2 3 4 0) 5 p m l r __t687K71) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t1I5N72 k v __t0q1c75) (join mbranch (1 2 3 4 0) 5 p m l r __t687K71) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0q1c75) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask279 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index262;  slog::Index** mp_mskindex263;  slog::Index** mp_putindex264;  slog::Index** $sup5638x40x0x0x0index265;  slog::Index** mbranchindex266;  slog::Index** mp_mskindex267;  slog::Index** mp_putindex268;  slog::Index** mp_msk_ansindex269;  slog::Index** $sup5638x40x0x0x1index270;  slog::Index** mbranchindex271;  slog::Index** mp_mskindex272;  slog::Index** mp_msk_ansindex273;  slog::Index** mp_putindex274;  slog::Index** mp_msk_ansindex275;  slog::Index** mp_put_ansindex276;  slog::Index** mp_mskdelta277;  slog::Index** mp_putdelta278;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord280({0, 2, 7, 1, 3, 4, 5, 6});
      slog::Relation* readrel281 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index262 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 2, 0});
      slog::Relation* readrel283 = db->getRelation("mp_msk");
      mp_mskindex263 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({2, 3, 0, 1});
      slog::Relation* readrel285 = db->getRelation("mp_put");
      mp_putindex264 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({0, 1, 6, 2, 3, 4, 5});
      slog::Relation* readrel287 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index265 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 2, 3, 4, 0});
      slog::Relation* readrel289 = db->getRelation("mbranch");
      mbranchindex266 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 2, 0});
      slog::Relation* readrel291 = db->getRelation("mp_msk");
      mp_mskindex267 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 3, 0});
      slog::Relation* readrel293 = db->getRelation("mp_put");
      mp_putindex268 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex269 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel297 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index270 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 3, 4, 0});
      slog::Relation* readrel299 = db->getRelation("mbranch");
      mbranchindex271 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("mp_msk");
      mp_mskindex272 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("mp_msk");
      mp_mskdelta277 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex273 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 2, 3, 0});
      slog::Relation* readrel307 = db->getRelation("mp_put");
      mp_putindex274 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 3, 0});
      slog::Relation* readrel309 = db->getRelation("mp_put");
      mp_putdelta278 = readrel309->getIndex(ord308, true);
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex275 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("mp_put_ans");
      mp_put_ansindex276 = readrel313->getIndex(ord312, false);
  
    }
    ReadTask279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[2];
        u64 v_c12 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index262, std::array<u64,8>{v_c52, v_c7, v_c12, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex263, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex264, std::array<u64,4>{v_c7, v_c12, 0, 0})) return;
        slog::join_probe<7,3>($sup5638x40x0x0x0index265, std::array<u64,7>{v_c52, v_c7, v_c12, 0, 0, 0, 0}, [&](const std::array<u64,7>& m314) {
          u64 v_c8 = m314[3]; u64 v_c9 = m314[4]; u64 v_c10 = m314[5]; u64 v_c11 = m314[6];
          if (!slog::exists_probe<5,5>(mbranchindex266, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, v_c53})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex267, std::array<u64,3>{v_c7, v_c9, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex268, std::array<u64,4>{v_c8, v_c7, v_c12, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex269, std::array<u64,2>{v_c10, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index270, std::array<u64,8>{v_c8, v_c9, v_c10, v_c11, v_c52, v_c7, v_c12, 0}, [&](const std::array<u64,8>& m315) {
            u64 v_c54 = m315[7];
            slog::join_probe<5,5>(mbranchindex271, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, v_c53}, [&](const std::array<u64,5>& m316) {
              slog::join_probe_old<3,3>(mp_mskindex272, mp_mskdelta277, std::array<u64,3>{v_c7, v_c9, v_c54}, [&](const std::array<u64,3>& m317) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex273, std::array<u64,2>{v_c54, v_c10})) return;
                slog::join_probe_old<4,3>(mp_putindex274, mp_putdelta278, std::array<u64,4>{v_c8, v_c7, v_c12, 0}, [&](const std::array<u64,4>& m318) {
                  u64 v_c55 = m318[3];
                  slog::join_probe<2,2>(mp_msk_ansindex275, std::array<u64,2>{v_c54, v_c10}, [&](const std::array<u64,2>& m319) {
                    slog::join_probe<2,1>(mp_put_ansindex276, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m320) {
                      u64 v_c32 = m320[1];
                      u64 v_c56 = _prim_band(db, v_c7, v_c9);
                      if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c57 = _prim_lt(db, v_c56, v_c51);
                      if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c57) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c52, v_c32, v_c9, v_c10, v_c11});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c10, v_c9, v_c32, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put", _fires);
  
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
  // (crule (pre (let __tconst94WO292 const5feceb66ffc86f38d952786c)) (scan mbranch __t5ueb290 p m l r) (body (join-old mp_put (1 2 0 3) 1 (1 2 0 3) __t5ueb290 k __t5psG291 v) (let __t5cEt293 (band k m)) (cmp gt __t5cEt293 __tconst94WO292)) (head (emit $sup5638x42x0x0x0 (4 2 3 5 0 1 6) p l m r __t5psG291 k v)) map.slog:43 #f)
  class ReadTask324 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex322;  slog::Index** mp_putdelta323;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord325({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel326 = db->getRelation("$sup5638x42x0x0x0");
      head_index[0] = readrel326->getIndex(ord325, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord327({1, 2, 0, 3});
      slog::Relation* readrel328 = db->getRelation("mp_put");
      mp_putindex322 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 0, 3});
      slog::Relation* readrel330 = db->getRelation("mp_put");
      mp_putdelta323 = readrel330->getIndex(ord329, true);
  
    }
    ReadTask324(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c11 = _t[4];
        slog::join_probe_old<4,1>(mp_putindex322, mp_putdelta323, std::array<u64,4>{v_c59, 0, 0, 0}, [&](const std::array<u64,4>& m331) {
          u64 v_c7 = m331[1]; u64 v_c60 = m331[2]; u64 v_c12 = m331[3];
          u64 v_c61 = _prim_band(db, v_c7, v_c9);
          if (v_c61 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          u64 v_c62 = _prim_gt(db, v_c61, v_c58);
          if (v_c62 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          if (!v_c62) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c10, v_c8, v_c9, v_c11, v_c60, v_c7, v_c12}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask324* _cont = new ReadTask324(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask324(db,b), false);
  // (crule (pre) (scan mp_union __t0lkv34 __t6xhm35 __t1QPr36) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6xhm35 p m l r) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t1QPr36 q n u v) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t0lkv34 l m q r __t6xhm35 __t1QPr36 u v)) map.slog:111 #f)
  class ReadTask337 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex333;  slog::Index** mbranchindex334;  slog::Index** mbranchdelta335;  slog::Index** mbranchdelta336;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord338({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel339 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel339->getIndex(ord338, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord340({0, 1, 2, 3, 4});
      slog::Relation* readrel341 = db->getRelation("mbranch");
      mbranchindex333 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1, 2, 3, 4});
      slog::Relation* readrel343 = db->getRelation("mbranch");
      mbranchdelta335 = readrel343->getIndex(ord342, true);
      std::vector<u16> ord344({0, 1, 2, 3, 4});
      slog::Relation* readrel345 = db->getRelation("mbranch");
      mbranchindex334 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1, 2, 3, 4});
      slog::Relation* readrel347 = db->getRelation("mbranch");
      mbranchdelta336 = readrel347->getIndex(ord346, true);
  
    }
    ReadTask337(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[1];
        u64 v_c65 = _t[2];
        slog::join_probe_old<5,1>(mbranchindex333, mbranchdelta335, std::array<u64,5>{v_c64, 0, 0, 0, 0}, [&](const std::array<u64,5>& m348) {
          u64 v_c10 = m348[1]; u64 v_c9 = m348[2]; u64 v_c8 = m348[3]; u64 v_c11 = m348[4];
          slog::join_probe_old<5,1>(mbranchindex334, mbranchdelta336, std::array<u64,5>{v_c65, 0, 0, 0, 0}, [&](const std::array<u64,5>& m349) {
            u64 v_c36 = m349[1]; u64 v_c31 = m349[2]; u64 v_c38 = m349[3]; u64 v_c12 = m349[4];
            u64 v_c66 = _prim_lt(db, v_c9, v_c31);
            if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c66) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c31, v_c10, v_c63, v_c8, v_c9, v_c36, v_c11, v_c64, v_c65, v_c38, v_c12}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask337* _cont = new ReadTask337(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask337(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x2 __t4lFL393 __t1lh0397 dup0XDZ1075 dup8FhK1076 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join-old $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join-old $sup5638x29x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join-old mp_msk_ans (0 1) 1 (0 1) __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask369 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x1index351;  slog::Index** $sup5638x29x0x0x0index352;  slog::Index** mp_joinindex353;  slog::Index** mp_hsb_ansindex354;  slog::Index** mp_hsb_ansindex355;  slog::Index** mp_hsb_ansindex356;  slog::Index** mp_mskindex357;  slog::Index** mp_msk_ansindex358;  slog::Index** mp_hsbindex359;  slog::Index** $sup5638x29x0x0x1delta360;  slog::Index** $sup5638x29x0x0x0delta361;  slog::Index** mp_joindelta362;  slog::Index** mp_hsb_ansdelta363;  slog::Index** mp_hsb_ansdelta364;  slog::Index** mp_hsb_ansdelta365;  slog::Index** mp_mskdelta366;  slog::Index** mp_msk_ansdelta367;  slog::Index** mp_hsbdelta368;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord370({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel371 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index351 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel373 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta360 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({1, 0, 2, 3, 4});
      slog::Relation* readrel375 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index352 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0, 2, 3, 4});
      slog::Relation* readrel377 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0delta361 = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({1, 2, 3, 4, 0});
      slog::Relation* readrel379 = db->getRelation("mp_join");
      mp_joinindex353 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 3, 4, 0});
      slog::Relation* readrel381 = db->getRelation("mp_join");
      mp_joindelta362 = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({0, 1});
      slog::Relation* readrel383 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex354 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta363 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex355 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({0, 1});
      slog::Relation* readrel389 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta364 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({0, 1});
      slog::Relation* readrel391 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex356 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta365 = readrel393->getIndex(ord392, true);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("mp_msk");
      mp_mskindex357 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("mp_msk");
      mp_mskdelta366 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({0, 1});
      slog::Relation* readrel399 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex358 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta367 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("mp_hsb");
      mp_hsbindex359 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("mp_hsb");
      mp_hsbdelta368 = readrel405->getIndex(ord404, true);
  
    }
    ReadTask369(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c68 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        u64 v_c71 = _t[3];
        u64 v_c32 = _t[4];
        u64 v_c72 = _t[5];
        u64 v_c73 = _t[6];
        u64 v_c74 = _t[7];
        u64 v_c75 = _t[8];
        u64 v_c76 = _t[9];
        u64 v_c77 = _t[10];
        if (v_c69 != v_c71) return;
        if (v_c69 != v_c70) return;
        slog::join_probe_old<7,7>($sup5638x29x0x0x1index351, $sup5638x29x0x0x1delta360, std::array<u64,7>{v_c68, v_c74, v_c75, v_c76, v_c77, v_c69, v_c32}, [&](const std::array<u64,7>& m406) {
          slog::join_probe_old<5,5>($sup5638x29x0x0x0index352, $sup5638x29x0x0x0delta361, std::array<u64,5>{v_c74, v_c68, v_c75, v_c76, v_c77}, [&](const std::array<u64,5>& m407) {
            slog::join_probe_old<5,5>(mp_joinindex353, mp_joindelta362, std::array<u64,5>{v_c74, v_c76, v_c75, v_c77, v_c68}, [&](const std::array<u64,5>& m408) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex354, mp_hsb_ansdelta363, std::array<u64,2>{v_c69, v_c73}, [&](const std::array<u64,2>& m409) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex355, mp_hsb_ansdelta364, std::array<u64,2>{v_c69, v_c72}, [&](const std::array<u64,2>& m410) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex356, mp_hsb_ansdelta365, std::array<u64,2>{v_c69, v_c32}, [&](const std::array<u64,2>& m411) {
                    slog::join_probe_old<3,2>(mp_mskindex357, mp_mskdelta366, std::array<u64,3>{v_c74, v_c72, 0}, [&](const std::array<u64,3>& m412) {
                      u64 v_c78 = m412[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex358, mp_msk_ansdelta367, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m413) {
                        u64 v_c79 = m413[1];
                        u64 v_c80 = _prim_bxor(db, v_c74, v_c75);
                        if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex359, mp_hsbdelta368, std::array<u64,2>{v_c69, v_c80}, [&](const std::array<u64,2>& m414) {
                          u64 v_c81 = _prim_band(db, v_c74, v_c32);
                          if (v_c81 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c82 = _prim_gt(db, v_c81, v_c67);
                          if (v_c82 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c82) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c79, v_c73, v_c76, v_c77});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c79, v_c73, v_c77, v_c76}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask369* _cont = new ReadTask369(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask369(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_del __t8KQn154 __t85IU153 k) (body (exists mp_msk (1 2 0) 1 k) (exists mp_del (2 0 1) 1 k) (join $sup5638x82x0x0x0 (0 1 2 3 4 5) 2 __t8KQn154 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t85IU153) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t0Lvo157 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join mp_del_ans (0 1) 2 __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask434 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex416;  slog::Index** mp_delindex417;  slog::Index** $sup5638x82x0x0x0index418;  slog::Index** mbranchindex419;  slog::Index** mp_mskindex420;  slog::Index** mp_msk_ansindex421;  slog::Index** mp_delindex422;  slog::Index** mp_bldindex423;  slog::Index** mp_del_ansindex424;  slog::Index** mp_bld_ansindex425;  slog::Index** mp_mskindex426;  slog::Index** mp_msk_ansindex427;  slog::Index** mp_delindex428;  slog::Index** mp_del_ansindex429;  slog::Index** mp_bld_ansindex430;  slog::Index** mp_blddelta431;  slog::Index** mp_mskdelta432;  slog::Index** mp_deldelta433;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord435({0, 1});
      slog::Relation* readrel436 = db->getRelation("mp_del_ans");
      head_index[0] = readrel436->getIndex(ord435, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord437({1, 2, 0});
      slog::Relation* readrel438 = db->getRelation("mp_msk");
      mp_mskindex416 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({2, 0, 1});
      slog::Relation* readrel440 = db->getRelation("mp_del");
      mp_delindex417 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel442 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index418 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 3, 4, 0});
      slog::Relation* readrel444 = db->getRelation("mbranch");
      mbranchindex419 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 2, 0});
      slog::Relation* readrel446 = db->getRelation("mp_msk");
      mp_mskindex420 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 0});
      slog::Relation* readrel448 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex421 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 2, 0});
      slog::Relation* readrel450 = db->getRelation("mp_del");
      mp_delindex422 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({2, 1, 4, 0, 3});
      slog::Relation* readrel452 = db->getRelation("mp_bld");
      mp_bldindex423 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({2, 1, 4, 0, 3});
      slog::Relation* readrel454 = db->getRelation("mp_bld");
      mp_blddelta431 = readrel454->getIndex(ord453, true);
      std::vector<u16> ord455({1, 0});
      slog::Relation* readrel456 = db->getRelation("mp_del_ans");
      mp_del_ansindex424 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({0, 1});
      slog::Relation* readrel458 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex425 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 2, 0});
      slog::Relation* readrel460 = db->getRelation("mp_msk");
      mp_mskindex426 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0});
      slog::Relation* readrel462 = db->getRelation("mp_msk");
      mp_mskdelta432 = readrel462->getIndex(ord461, true);
      std::vector<u16> ord463({0, 1});
      slog::Relation* readrel464 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex427 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 0});
      slog::Relation* readrel466 = db->getRelation("mp_del");
      mp_delindex428 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("mp_del");
      mp_deldelta433 = readrel468->getIndex(ord467, true);
      std::vector<u16> ord469({0, 1});
      slog::Relation* readrel470 = db->getRelation("mp_del_ans");
      mp_del_ansindex429 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 1});
      slog::Relation* readrel472 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex430 = readrel472->getIndex(ord471, false);
  
    }
    ReadTask434(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex416, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex417, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x82x0x0x0index418, std::array<u64,6>{v_c84, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,6>& m473) {
          u64 v_c8 = m473[2]; u64 v_c9 = m473[3]; u64 v_c10 = m473[4]; u64 v_c11 = m473[5];
          slog::join_probe<5,5>(mbranchindex419, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, v_c85}, [&](const std::array<u64,5>& m474) {
            if (!slog::exists_probe<3,2>(mp_mskindex420, std::array<u64,3>{v_c7, v_c9, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex421, std::array<u64,2>{v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex422, std::array<u64,3>{v_c8, v_c7, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex423, mp_blddelta431, std::array<u64,5>{v_c9, v_c10, v_c11, 0, 0}, [&](const std::array<u64,5>& m475) {
              u64 v_c86 = m475[3]; u64 v_c32 = m475[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex424, std::array<u64,2>{v_c32, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex425, std::array<u64,2>{v_c86, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex426, mp_mskdelta432, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m476) {
                u64 v_c87 = m476[2];
                slog::join_probe<2,2>(mp_msk_ansindex427, std::array<u64,2>{v_c87, v_c10}, [&](const std::array<u64,2>& m477) {
                  slog::join_probe_old<3,2>(mp_delindex428, mp_deldelta433, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m478) {
                    u64 v_c88 = m478[2];
                    slog::join_probe<2,2>(mp_del_ansindex429, std::array<u64,2>{v_c88, v_c32}, [&](const std::array<u64,2>& m479) {
                      slog::join_probe<2,1>(mp_bld_ansindex430, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m480) {
                        u64 v_c40 = m480[1];
                        u64 v_c89 = _prim_band(db, v_c7, v_c9);
                        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c90 = _prim_lt(db, v_c89, v_c83);
                        if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c90) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c40}, std::array<u16,2>{0, 1});
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
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mp_msk __t9ory98 q m) (body (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists mbranch (2 0 1 3 4) 1 m) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_msk_ans (0 1) 1 __t9ory98) (join $sup5638x98x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t9ory98 m q p __t2uCs95 l n r u v) (cmp lt n m) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t2uCs95 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk_ans (0 1) 2 __t9ory98 p) (exists mp_union (1 2 0) 1 r) (join mbranch (1 2 3 4 0) 4 p m l r __t2SOF94) (exists mp_union (0 1 2) 2 __t2uCs95 __t2SOF94) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t1Mtu99) (join mp_union (0 1 2) 3 __t2uCs95 __t2SOF94 __t1Mtu99) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask500 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index482;  slog::Index** mbranchindex483;  slog::Index** mbranchindex484;  slog::Index** mp_msk_ansindex485;  slog::Index** $sup5638x98x0x0x1index486;  slog::Index** $sup5638x98x0x0x0index487;  slog::Index** mbranchindex488;  slog::Index** mp_msk_ansindex489;  slog::Index** mp_unionindex490;  slog::Index** mbranchindex491;  slog::Index** mp_unionindex492;  slog::Index** mbranchindex493;  slog::Index** mp_unionindex494;  slog::Index** mp_msk_ansindex495;  slog::Index** mp_unionindex496;  slog::Index** mp_union_ansindex497;  slog::Index** mbranchdelta498;  slog::Index** mp_uniondelta499;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord501({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel502 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index482 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({2, 0, 1, 3, 4});
      slog::Relation* readrel504 = db->getRelation("mbranch");
      mbranchindex483 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 2, 3, 4, 0});
      slog::Relation* readrel506 = db->getRelation("mbranch");
      mbranchindex484 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex485 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel510 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index486 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel512 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index487 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 3, 4, 0});
      slog::Relation* readrel514 = db->getRelation("mbranch");
      mbranchindex488 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex489 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 2, 0});
      slog::Relation* readrel518 = db->getRelation("mp_union");
      mp_unionindex490 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 3, 4, 0});
      slog::Relation* readrel520 = db->getRelation("mbranch");
      mbranchindex491 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 1, 2});
      slog::Relation* readrel522 = db->getRelation("mp_union");
      mp_unionindex492 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 2, 3, 4, 0});
      slog::Relation* readrel524 = db->getRelation("mbranch");
      mbranchindex493 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 3, 4, 0});
      slog::Relation* readrel526 = db->getRelation("mbranch");
      mbranchdelta498 = readrel526->getIndex(ord525, true);
      std::vector<u16> ord527({0, 1, 2});
      slog::Relation* readrel528 = db->getRelation("mp_union");
      mp_unionindex494 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex495 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 0});
      slog::Relation* readrel532 = db->getRelation("mp_union");
      mp_unionindex496 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 2, 0});
      slog::Relation* readrel534 = db->getRelation("mp_union");
      mp_uniondelta499 = readrel534->getIndex(ord533, true);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("mp_union_ans");
      mp_union_ansindex497 = readrel536->getIndex(ord535, false);
  
    }
    ReadTask500(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c36 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index482, std::array<u64,9>{v_c9, v_c36, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex483, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex484, std::array<u64,5>{v_c36, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex485, std::array<u64,2>{v_c92, 0})) return;
        slog::join_probe<10,3>($sup5638x98x0x0x1index486, std::array<u64,10>{v_c92, v_c9, v_c36, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m537) {
          u64 v_c10 = m537[3]; u64 v_c93 = m537[4]; u64 v_c8 = m537[5]; u64 v_c31 = m537[6]; u64 v_c11 = m537[7]; u64 v_c38 = m537[8]; u64 v_c12 = m537[9];
          u64 v_c94 = _prim_lt(db, v_c31, v_c9);
          if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c94) return;
          slog::join_probe<9,9>($sup5638x98x0x0x0index487, std::array<u64,9>{v_c10, v_c8, v_c9, v_c11, v_c93, v_c31, v_c36, v_c38, v_c12}, [&](const std::array<u64,9>& m539) {
            if (!slog::exists_probe<5,4>(mbranchindex488, std::array<u64,5>{v_c36, v_c31, v_c38, v_c12, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex489, std::array<u64,2>{v_c92, v_c10})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex490, std::array<u64,3>{v_c11, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex491, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,5>& m540) {
              u64 v_c95 = m540[4];
              if (!slog::exists_probe<3,2>(mp_unionindex492, std::array<u64,3>{v_c93, v_c95, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex493, mbranchdelta498, std::array<u64,5>{v_c36, v_c31, v_c38, v_c12, 0}, [&](const std::array<u64,5>& m541) {
                u64 v_c96 = m541[4];
                slog::join_probe<3,3>(mp_unionindex494, std::array<u64,3>{v_c93, v_c95, v_c96}, [&](const std::array<u64,3>& m542) {
                  slog::join_probe<2,2>(mp_msk_ansindex495, std::array<u64,2>{v_c92, v_c10}, [&](const std::array<u64,2>& m543) {
                    slog::join_probe_old<3,2>(mp_unionindex496, mp_uniondelta499, std::array<u64,3>{v_c11, v_c96, 0}, [&](const std::array<u64,3>& m544) {
                      u64 v_c97 = m544[2];
                      slog::join_probe<2,1>(mp_union_ansindex497, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m545) {
                        u64 v_c32 = m545[1];
                        u64 v_c98 = _prim_band(db, v_c36, v_c9);
                        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c99 = _prim_gt(db, v_c98, v_c91);
                        if (v_c99 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c99) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c93, v_c32, v_c8, v_c9, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c10, v_c9, v_c8, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask500* _cont = new ReadTask500(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask500(db,b), false);
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x1 __t1I5N72 __t0q1c75 k l m p r v) (body (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t1I5N72 k v) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_msk (1 2 0) 3 k m __t0q1c75) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t687K71) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t687K71 k __t1I5N72 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0q1c75) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask562 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index547;  slog::Index** mp_putindex548;  slog::Index** mp_mskindex549;  slog::Index** mp_putindex550;  slog::Index** mp_msk_ansindex551;  slog::Index** mbranchindex552;  slog::Index** mp_putindex553;  slog::Index** mp_mskindex554;  slog::Index** mp_putindex555;  slog::Index** mp_msk_ansindex556;  slog::Index** mp_put_ansindex557;  slog::Index** mbranchdelta558;  slog::Index** mp_putdelta559;  slog::Index** mp_mskdelta560;  slog::Index** mp_putdelta561;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord563({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel564 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index547 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({2, 3, 0, 1});
      slog::Relation* readrel566 = db->getRelation("mp_put");
      mp_putindex548 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 0});
      slog::Relation* readrel568 = db->getRelation("mp_msk");
      mp_mskindex549 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 3, 0});
      slog::Relation* readrel570 = db->getRelation("mp_put");
      mp_putindex550 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex551 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 3, 4, 0});
      slog::Relation* readrel574 = db->getRelation("mbranch");
      mbranchindex552 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 3, 4, 0});
      slog::Relation* readrel576 = db->getRelation("mbranch");
      mbranchdelta558 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({1, 2, 0, 3});
      slog::Relation* readrel578 = db->getRelation("mp_put");
      mp_putindex553 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 0, 3});
      slog::Relation* readrel580 = db->getRelation("mp_put");
      mp_putdelta559 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("mp_msk");
      mp_mskindex554 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("mp_msk");
      mp_mskdelta560 = readrel584->getIndex(ord583, true);
      std::vector<u16> ord585({1, 2, 3, 0});
      slog::Relation* readrel586 = db->getRelation("mp_put");
      mp_putindex555 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 2, 3, 0});
      slog::Relation* readrel588 = db->getRelation("mp_put");
      mp_putdelta561 = readrel588->getIndex(ord587, true);
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex556 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("mp_put_ans");
      mp_put_ansindex557 = readrel592->getIndex(ord591, false);
  
    }
    ReadTask562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c54 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c11 = _t[6];
        u64 v_c12 = _t[7];
        slog::join_probe<7,7>($sup5638x40x0x0x0index547, std::array<u64,7>{v_c10, v_c8, v_c9, v_c11, v_c52, v_c7, v_c12}, [&](const std::array<u64,7>& m593) {
          if (!slog::exists_probe<4,3>(mp_putindex548, std::array<u64,4>{v_c7, v_c12, v_c52, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex549, std::array<u64,3>{v_c7, v_c9, v_c54})) return;
          if (!slog::exists_probe<4,3>(mp_putindex550, std::array<u64,4>{v_c8, v_c7, v_c12, 0})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex551, std::array<u64,2>{v_c54, v_c10})) return;
          slog::join_probe_old<5,4>(mbranchindex552, mbranchdelta558, std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,5>& m594) {
            u64 v_c53 = m594[4];
            slog::join_probe_old<4,4>(mp_putindex553, mp_putdelta559, std::array<u64,4>{v_c53, v_c7, v_c52, v_c12}, [&](const std::array<u64,4>& m595) {
              slog::join_probe_old<3,3>(mp_mskindex554, mp_mskdelta560, std::array<u64,3>{v_c7, v_c9, v_c54}, [&](const std::array<u64,3>& m596) {
                slog::join_probe_old<4,3>(mp_putindex555, mp_putdelta561, std::array<u64,4>{v_c8, v_c7, v_c12, 0}, [&](const std::array<u64,4>& m597) {
                  u64 v_c55 = m597[3];
                  slog::join_probe<2,2>(mp_msk_ansindex556, std::array<u64,2>{v_c54, v_c10}, [&](const std::array<u64,2>& m598) {
                    slog::join_probe<2,1>(mp_put_ansindex557, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m599) {
                      u64 v_c32 = m599[1];
                      u64 v_c56 = _prim_band(db, v_c7, v_c9);
                      if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c100 = _prim_lt(db, v_c56, v_c51);
                      if (v_c100 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c100) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c52, v_c32, v_c9, v_c10, v_c11});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c10, v_c9, v_c32, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x1", _fires);
  
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
  // (crule (pre) (scan mbranch __t50JB19 p m l r) (body (exists mbranch (2 0 1 3 4) 1 m) (exists mp_union (1 2 0) 1 __t50JB19) (join-old mp_join (1 2 3 4 0) 2 (1 2 3 4 0) p __t50JB19 q __t6Pc120 __t2ANq21) (neq p q) (exists mp_union (1 2 0) 2 __t50JB19 __t6Pc120) (exists mp_join_ans (0 1) 1 __t2ANq21) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t6Pc120 q m u v) (join mp_union (1 2 0) 2 __t50JB19 __t6Pc120 __t9xCI18) (join mp_join_ans (0 1) 1 __t2ANq21 res)) (head (emit mp_union_ans (0 1) __t9xCI18 res)) map.slog:114 #f)
  class ReadTask611 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex601;  slog::Index** mp_unionindex602;  slog::Index** mp_joinindex603;  slog::Index** mp_unionindex604;  slog::Index** mp_join_ansindex605;  slog::Index** mbranchindex606;  slog::Index** mp_unionindex607;  slog::Index** mp_join_ansindex608;  slog::Index** mp_joindelta609;  slog::Index** mbranchdelta610;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("mp_union_ans");
      head_index[0] = readrel613->getIndex(ord612, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord614({2, 0, 1, 3, 4});
      slog::Relation* readrel615 = db->getRelation("mbranch");
      mbranchindex601 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("mp_union");
      mp_unionindex602 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 2, 3, 4, 0});
      slog::Relation* readrel619 = db->getRelation("mp_join");
      mp_joinindex603 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 3, 4, 0});
      slog::Relation* readrel621 = db->getRelation("mp_join");
      mp_joindelta609 = readrel621->getIndex(ord620, true);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("mp_union");
      mp_unionindex604 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({0, 1});
      slog::Relation* readrel625 = db->getRelation("mp_join_ans");
      mp_join_ansindex605 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({0, 1, 2, 3, 4});
      slog::Relation* readrel627 = db->getRelation("mbranch");
      mbranchindex606 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 1, 2, 3, 4});
      slog::Relation* readrel629 = db->getRelation("mbranch");
      mbranchdelta610 = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("mp_union");
      mp_unionindex607 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({0, 1});
      slog::Relation* readrel633 = db->getRelation("mp_join_ans");
      mp_join_ansindex608 = readrel633->getIndex(ord632, false);
  
    }
    ReadTask611(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex601, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex602, std::array<u64,3>{v_c101, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex603, mp_joindelta609, std::array<u64,5>{v_c10, v_c101, 0, 0, 0}, [&](const std::array<u64,5>& m634) {
          u64 v_c36 = m634[2]; u64 v_c102 = m634[3]; u64 v_c103 = m634[4];
          if (v_c10 == v_c36) return;
          if (!slog::exists_probe<3,2>(mp_unionindex604, std::array<u64,3>{v_c101, v_c102, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex605, std::array<u64,2>{v_c103, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex606, mbranchdelta610, std::array<u64,5>{v_c102, v_c36, v_c9, 0, 0}, [&](const std::array<u64,5>& m635) {
            u64 v_c38 = m635[3]; u64 v_c12 = m635[4];
            slog::join_probe<3,2>(mp_unionindex607, std::array<u64,3>{v_c101, v_c102, 0}, [&](const std::array<u64,3>& m636) {
              u64 v_c104 = m636[2];
              slog::join_probe<2,1>(mp_join_ansindex608, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m637) {
                u64 v_c40 = m637[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c40}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask611* _cont = new ReadTask611(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask611(db,b), false);
  // (crule (pre) (scan mp_msk __t0M9S378 q m) (body (exists mbranch (2 0 1 3 4) 1 m) (exists $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_join (3 4 1 0 2) 1 q) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (join mbranch (2 0 1 3 4) 1 m __t8hMI375 p l r) (neq p __v0) (exists mp_join (1 2 3 4 0) 3 p __t8hMI375 q) (exists mp_union (1 2 0) 1 __t8hMI375) (join $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 l m p r __t8hMI375 q __t4ZhK374 n __t5XzA376 u v) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 q n u v __t5XzA376) (exists mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (join mp_join (1 2 3 4 0) 4 p __t8hMI375 q __t5XzA376 __t35Cd377) (join mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask652 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex638;  slog::Index** $sup5638x101x0x0x0index639;  slog::Index** mbranchindex640;  slog::Index** mp_joinindex641;  slog::Index** mp_msk_ansindex642;  slog::Index** mbranchindex643;  slog::Index** mp_joinindex644;  slog::Index** mp_unionindex645;  slog::Index** $sup5638x101x0x0x0index646;  slog::Index** mbranchindex647;  slog::Index** mp_unionindex648;  slog::Index** mp_joinindex649;  slog::Index** mp_unionindex650;  slog::Index** mp_join_ansindex651;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord653({0, 1});
      slog::Relation* readrel654 = db->getRelation("mp_union_ans");
      head_index[0] = readrel654->getIndex(ord653, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord655({2, 0, 1, 3, 4});
      slog::Relation* readrel656 = db->getRelation("mbranch");
      mbranchindex638 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel658 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index639 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 3, 4, 0});
      slog::Relation* readrel660 = db->getRelation("mbranch");
      mbranchindex640 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({3, 4, 1, 0, 2});
      slog::Relation* readrel662 = db->getRelation("mp_join");
      mp_joinindex641 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({0, 1});
      slog::Relation* readrel664 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex642 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({2, 0, 1, 3, 4});
      slog::Relation* readrel666 = db->getRelation("mbranch");
      mbranchindex643 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 3, 4, 0});
      slog::Relation* readrel668 = db->getRelation("mp_join");
      mp_joinindex644 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("mp_union");
      mp_unionindex645 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel672 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index646 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 2, 3, 4, 0});
      slog::Relation* readrel674 = db->getRelation("mbranch");
      mbranchindex647 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({0, 1, 2});
      slog::Relation* readrel676 = db->getRelation("mp_union");
      mp_unionindex648 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 3, 4, 0});
      slog::Relation* readrel678 = db->getRelation("mp_join");
      mp_joinindex649 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({0, 1, 2});
      slog::Relation* readrel680 = db->getRelation("mp_union");
      mp_unionindex650 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({0, 1});
      slog::Relation* readrel682 = db->getRelation("mp_join_ans");
      mp_join_ansindex651 = readrel682->getIndex(ord681, false);
  
    }
    ReadTask652(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<5,1>(mbranchindex638, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x101x0x0x0index639, std::array<u64,11>{v_c9, v_c36, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex640, std::array<u64,5>{v_c36, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex641, std::array<u64,5>{v_c36, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex642, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m683) {
          u64 v_c32 = m683[1];
          slog::join_probe<5,1>(mbranchindex643, std::array<u64,5>{v_c9, 0, 0, 0, 0}, [&](const std::array<u64,5>& m684) {
            u64 v_c106 = m684[1]; u64 v_c10 = m684[2]; u64 v_c8 = m684[3]; u64 v_c11 = m684[4];
            if (v_c10 == v_c32) return;
            if (!slog::exists_probe<5,3>(mp_joinindex644, std::array<u64,5>{v_c10, v_c106, v_c36, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex645, std::array<u64,3>{v_c106, 0, 0})) return;
            slog::join_probe<11,6>($sup5638x101x0x0x0index646, std::array<u64,11>{v_c8, v_c9, v_c10, v_c11, v_c106, v_c36, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m685) {
              u64 v_c107 = m685[6]; u64 v_c31 = m685[7]; u64 v_c108 = m685[8]; u64 v_c38 = m685[9]; u64 v_c12 = m685[10];
              u64 v_c109 = _prim_lt(db, v_c31, v_c9);
              if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
              if (!v_c109) return;
              slog::join_probe<5,5>(mbranchindex647, std::array<u64,5>{v_c36, v_c31, v_c38, v_c12, v_c108}, [&](const std::array<u64,5>& m687) {
                if (!slog::exists_probe<3,3>(mp_unionindex648, std::array<u64,3>{v_c107, v_c106, v_c108})) return;
                slog::join_probe<5,4>(mp_joinindex649, std::array<u64,5>{v_c10, v_c106, v_c36, v_c108, 0}, [&](const std::array<u64,5>& m688) {
                  u64 v_c110 = m688[4];
                  slog::join_probe<3,3>(mp_unionindex650, std::array<u64,3>{v_c107, v_c106, v_c108}, [&](const std::array<u64,3>& m689) {
                    slog::join_probe<2,1>(mp_join_ansindex651, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m690) {
                      u64 v_c40 = m690[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c107, v_c40}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask652* _cont = new ReadTask652(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask652(db,b), false);
  // (crule (pre) (scan type_mismatch __erre3V1g1004 __errf1ND01005 __errf5jCQ1006 __errf2V7d1007 __errf73eC1008) (body) (head (emit error (0) __erre3V1g1004)) <internal>:1 #f)
  class ReadTask691 : public slog::Task
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
      std::vector<u16> ord692({0});
      slog::Relation* readrel693 = db->getRelation("error");
      head_index[0] = readrel693->getIndex(ord692, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask691(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c111 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c113 = _t[2];
        u64 v_c114 = _t[3];
        u64 v_c115 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c111}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan mp_put __t2UPk363 __t2G14362 k v) (body (join mleaf (0 1 2) 2 __t2G14362 k w)) (head (emit-temp temp4cOw1069 __t2UPk363 k v) (mkstruct mleaf (1 2 0) __t9j1T361 k v)) map.slog:38 #f)
  class ReadTask695 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex694;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4cOw1069");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("mleaf");
      mleafindex694 = readrel697->getIndex(ord696, false);
  
    }
    ReadTask695(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c116 = _t[0];
        u64 v_c117 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c12 = _t[3];
        slog::join_probe<3,2>(mleafindex694, std::array<u64,3>{v_c117, v_c7, 0}, [&](const std::array<u64,3>& m698) {
          u64 v_c118 = m698[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c116, v_c7, v_c12});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c7, v_c12}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask695* _cont = new ReadTask695(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask695(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_bld __t0Lvo157 p m __v0 r) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join mbranch (1 2 4 0 3) 3 p m r __t85IU153 l) (exists mp_del (1 2 0) 1 __t85IU153) (exists mp_del (1 2 0) 1 l) (join $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 p m r l __t8KQn154 k) (join mp_del (0 2 1) 3 __t8KQn154 k __t85IU153) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join mp_del_ans (0 1) 2 __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask717 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index699;  slog::Index** mp_mskindex700;  slog::Index** mp_msk_ansindex701;  slog::Index** mp_del_ansindex702;  slog::Index** mp_bld_ansindex703;  slog::Index** mbranchindex704;  slog::Index** mp_delindex705;  slog::Index** mp_delindex706;  slog::Index** $sup5638x82x0x0x0index707;  slog::Index** mp_delindex708;  slog::Index** mp_delindex709;  slog::Index** mp_mskindex710;  slog::Index** mp_msk_ansindex711;  slog::Index** mp_delindex712;  slog::Index** mp_del_ansindex713;  slog::Index** mp_bld_ansindex714;  slog::Index** mp_mskdelta715;  slog::Index** mp_deldelta716;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord718({0, 1});
      slog::Relation* readrel719 = db->getRelation("mp_del_ans");
      head_index[0] = readrel719->getIndex(ord718, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord720({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel721 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index699 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({2, 0, 1});
      slog::Relation* readrel723 = db->getRelation("mp_msk");
      mp_mskindex700 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 0});
      slog::Relation* readrel725 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex701 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 0});
      slog::Relation* readrel727 = db->getRelation("mp_del_ans");
      mp_del_ansindex702 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex703 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 4, 0, 3});
      slog::Relation* readrel731 = db->getRelation("mbranch");
      mbranchindex704 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 2, 0});
      slog::Relation* readrel733 = db->getRelation("mp_del");
      mp_delindex705 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 2, 0});
      slog::Relation* readrel735 = db->getRelation("mp_del");
      mp_delindex706 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel737 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index707 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 2, 1});
      slog::Relation* readrel739 = db->getRelation("mp_del");
      mp_delindex708 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("mp_del");
      mp_delindex709 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("mp_msk");
      mp_mskindex710 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 2, 0});
      slog::Relation* readrel745 = db->getRelation("mp_msk");
      mp_mskdelta715 = readrel745->getIndex(ord744, true);
      std::vector<u16> ord746({0, 1});
      slog::Relation* readrel747 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex711 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 2, 0});
      slog::Relation* readrel749 = db->getRelation("mp_del");
      mp_delindex712 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("mp_del");
      mp_deldelta716 = readrel751->getIndex(ord750, true);
      std::vector<u16> ord752({0, 1});
      slog::Relation* readrel753 = db->getRelation("mp_del_ans");
      mp_del_ansindex713 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({0, 1});
      slog::Relation* readrel755 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex714 = readrel755->getIndex(ord754, false);
  
    }
    ReadTask717(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c86 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<6,3>($sup5638x82x0x0x0index699, std::array<u64,6>{v_c10, v_c9, v_c11, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex700, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex701, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(mp_del_ansindex702, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(mp_bld_ansindex703, std::array<u64,2>{v_c86, 0})) return;
        slog::join_probe<5,3>(mbranchindex704, std::array<u64,5>{v_c10, v_c9, v_c11, 0, 0}, [&](const std::array<u64,5>& m756) {
          u64 v_c85 = m756[3]; u64 v_c8 = m756[4];
          if (!slog::exists_probe<3,1>(mp_delindex705, std::array<u64,3>{v_c85, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex706, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<6,4>($sup5638x82x0x0x0index707, std::array<u64,6>{v_c10, v_c9, v_c11, v_c8, 0, 0}, [&](const std::array<u64,6>& m757) {
            u64 v_c84 = m757[4]; u64 v_c7 = m757[5];
            slog::join_probe<3,3>(mp_delindex708, std::array<u64,3>{v_c84, v_c7, v_c85}, [&](const std::array<u64,3>& m758) {
              if (!slog::exists_probe<3,2>(mp_delindex709, std::array<u64,3>{v_c8, v_c7, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex710, mp_mskdelta715, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m759) {
                u64 v_c87 = m759[2];
                slog::join_probe<2,2>(mp_msk_ansindex711, std::array<u64,2>{v_c87, v_c10}, [&](const std::array<u64,2>& m760) {
                  slog::join_probe_old<3,2>(mp_delindex712, mp_deldelta716, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m761) {
                    u64 v_c88 = m761[2];
                    slog::join_probe<2,2>(mp_del_ansindex713, std::array<u64,2>{v_c88, v_c32}, [&](const std::array<u64,2>& m762) {
                      slog::join_probe<2,1>(mp_bld_ansindex714, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m763) {
                        u64 v_c40 = m763[1];
                        u64 v_c89 = _prim_band(db, v_c7, v_c9);
                        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c119 = _prim_lt(db, v_c89, v_c83);
                        if (v_c119 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c119) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c40}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_bld", _fires);
  
      if (!_done)
      {
        ReadTask717* _cont = new ReadTask717(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask717(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_bld_ans __t8Ai5407 res) (body (join-old mp_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t8Ai5407 p m l __v0) (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (join-old mbranch (1 2 3 4 0) 3 (1 2 3 4 0) p m l r __t0VzH403) (exists mp_del (1 2 0) 1 __t0VzH403) (exists mp_del (1 2 0) 1 r) (join-old $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 (4 2 3 5 0 1) p l m r __t01YW404 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t01YW404 k __t0VzH403) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join-old mp_msk_ans (0 1) 2 (0 1) __t7ikb408 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join-old mp_del_ans (0 1) 2 (0 1) __t3il5409 __v0) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask788 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex765;  slog::Index** $sup5638x84x0x0x0index766;  slog::Index** mp_mskindex767;  slog::Index** mp_msk_ansindex768;  slog::Index** mp_del_ansindex769;  slog::Index** mbranchindex770;  slog::Index** mp_delindex771;  slog::Index** mp_delindex772;  slog::Index** $sup5638x84x0x0x0index773;  slog::Index** mp_delindex774;  slog::Index** mp_delindex775;  slog::Index** mp_mskindex776;  slog::Index** mp_msk_ansindex777;  slog::Index** mp_delindex778;  slog::Index** mp_del_ansindex779;  slog::Index** mp_blddelta780;  slog::Index** mbranchdelta781;  slog::Index** $sup5638x84x0x0x0delta782;  slog::Index** mp_deldelta783;  slog::Index** mp_mskdelta784;  slog::Index** mp_msk_ansdelta785;  slog::Index** mp_deldelta786;  slog::Index** mp_del_ansdelta787;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord789({0, 1});
      slog::Relation* readrel790 = db->getRelation("mp_del_ans");
      head_index[0] = readrel790->getIndex(ord789, false);
      outer_rel = db->getRelation("mp_bld_ans");
      std::vector<u16> ord791({0, 1, 2, 3, 4});
      slog::Relation* readrel792 = db->getRelation("mp_bld");
      mp_bldindex765 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1, 2, 3, 4});
      slog::Relation* readrel794 = db->getRelation("mp_bld");
      mp_blddelta780 = readrel794->getIndex(ord793, true);
      std::vector<u16> ord795({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel796 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index766 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({2, 0, 1});
      slog::Relation* readrel798 = db->getRelation("mp_msk");
      mp_mskindex767 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 0});
      slog::Relation* readrel800 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex768 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 0});
      slog::Relation* readrel802 = db->getRelation("mp_del_ans");
      mp_del_ansindex769 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 2, 3, 4, 0});
      slog::Relation* readrel804 = db->getRelation("mbranch");
      mbranchindex770 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 2, 3, 4, 0});
      slog::Relation* readrel806 = db->getRelation("mbranch");
      mbranchdelta781 = readrel806->getIndex(ord805, true);
      std::vector<u16> ord807({1, 2, 0});
      slog::Relation* readrel808 = db->getRelation("mp_del");
      mp_delindex771 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 2, 0});
      slog::Relation* readrel810 = db->getRelation("mp_del");
      mp_delindex772 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel812 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index773 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel814 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta782 = readrel814->getIndex(ord813, true);
      std::vector<u16> ord815({0, 2, 1});
      slog::Relation* readrel816 = db->getRelation("mp_del");
      mp_delindex774 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({0, 2, 1});
      slog::Relation* readrel818 = db->getRelation("mp_del");
      mp_deldelta783 = readrel818->getIndex(ord817, true);
      std::vector<u16> ord819({1, 2, 0});
      slog::Relation* readrel820 = db->getRelation("mp_del");
      mp_delindex775 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({1, 2, 0});
      slog::Relation* readrel822 = db->getRelation("mp_msk");
      mp_mskindex776 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({1, 2, 0});
      slog::Relation* readrel824 = db->getRelation("mp_msk");
      mp_mskdelta784 = readrel824->getIndex(ord823, true);
      std::vector<u16> ord825({0, 1});
      slog::Relation* readrel826 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex777 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({0, 1});
      slog::Relation* readrel828 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta785 = readrel828->getIndex(ord827, true);
      std::vector<u16> ord829({1, 2, 0});
      slog::Relation* readrel830 = db->getRelation("mp_del");
      mp_delindex778 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({1, 2, 0});
      slog::Relation* readrel832 = db->getRelation("mp_del");
      mp_deldelta786 = readrel832->getIndex(ord831, true);
      std::vector<u16> ord833({0, 1});
      slog::Relation* readrel834 = db->getRelation("mp_del_ans");
      mp_del_ansindex779 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({0, 1});
      slog::Relation* readrel836 = db->getRelation("mp_del_ans");
      mp_del_ansdelta787 = readrel836->getIndex(ord835, true);
  
    }
    ReadTask788(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c121 = _t[0];
        u64 v_c40 = _t[1];
        slog::join_probe_old<5,1>(mp_bldindex765, mp_blddelta780, std::array<u64,5>{v_c121, 0, 0, 0, 0}, [&](const std::array<u64,5>& m837) {
          u64 v_c10 = m837[1]; u64 v_c9 = m837[2]; u64 v_c8 = m837[3]; u64 v_c32 = m837[4];
          if (!slog::exists_probe<6,3>($sup5638x84x0x0x0index766, std::array<u64,6>{v_c10, v_c8, v_c9, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex767, std::array<u64,3>{v_c9, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex768, std::array<u64,2>{v_c10, 0})) return;
          if (!slog::exists_probe<2,1>(mp_del_ansindex769, std::array<u64,2>{v_c32, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex770, mbranchdelta781, std::array<u64,5>{v_c10, v_c9, v_c8, 0, 0}, [&](const std::array<u64,5>& m838) {
            u64 v_c11 = m838[3]; u64 v_c122 = m838[4];
            if (!slog::exists_probe<3,1>(mp_delindex771, std::array<u64,3>{v_c122, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_delindex772, std::array<u64,3>{v_c11, 0, 0})) return;
            slog::join_probe_old<6,4>($sup5638x84x0x0x0index773, $sup5638x84x0x0x0delta782, std::array<u64,6>{v_c10, v_c8, v_c9, v_c11, 0, 0}, [&](const std::array<u64,6>& m839) {
              u64 v_c123 = m839[4]; u64 v_c7 = m839[5];
              slog::join_probe_old<3,3>(mp_delindex774, mp_deldelta783, std::array<u64,3>{v_c123, v_c7, v_c122}, [&](const std::array<u64,3>& m840) {
                if (!slog::exists_probe<3,2>(mp_delindex775, std::array<u64,3>{v_c11, v_c7, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex776, mp_mskdelta784, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m841) {
                  u64 v_c124 = m841[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex777, mp_msk_ansdelta785, std::array<u64,2>{v_c124, v_c10}, [&](const std::array<u64,2>& m842) {
                    slog::join_probe_old<3,2>(mp_delindex778, mp_deldelta786, std::array<u64,3>{v_c11, v_c7, 0}, [&](const std::array<u64,3>& m843) {
                      u64 v_c125 = m843[2];
                      slog::join_probe_old<2,2>(mp_del_ansindex779, mp_del_ansdelta787, std::array<u64,2>{v_c125, v_c32}, [&](const std::array<u64,2>& m844) {
                        u64 v_c126 = _prim_band(db, v_c7, v_c9);
                        if (v_c126 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c127 = _prim_gt(db, v_c126, v_c120);
                        if (v_c127 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c127) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c123, v_c40}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask788* _cont = new ReadTask788(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask788(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x0 __d0 p0 p1 t0 t1) (body (let __t0LEG246 (bxor p0 p1))) (head (emit-temp temp1bhg1089 __t0LEG246)) map.slog:30 #f)
  class ReadTask846 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1bhg1089");
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
  
    }
    ReadTask846(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c75 = _t[2];
        u64 v_c76 = _t[3];
        u64 v_c77 = _t[4];
        u64 v_c128 = _prim_bxor(db, v_c74, v_c75);
        if (v_c128 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c128});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask846* _cont = new ReadTask846(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask846(db,b), false);
  // (crule (pre) (scan temp2PlQ1027 __t0sIx339 __t1Qmw338) (body) (head (emit mp_msk_ans (0 1) __t0sIx339 __t1Qmw338)) map.slog:22 #f)
  class ReadTask847 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_msk_ans");
      std::vector<u16> ord848({0, 1});
      slog::Relation* readrel849 = db->getRelation("mp_msk_ans");
      head_index[0] = readrel849->getIndex(ord848, false);
      outer_rel = db->getRelation("temp2PlQ1027");
  
    }
    ReadTask847(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c129 = _t[0];
        u64 v_c130 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c130}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp2PlQ1027", _fires);
  
      if (!_done)
      {
        ReadTask847* _cont = new ReadTask847(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask847(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t5IgR220 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t5IgR220 p n) (exists $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mp_join (1 2 3 4 0) 1 p) (join-old mbranch (1 2 3 4 0) 1 (1 2 3 4 0) p m l r __t0o62217) (cmp lt m n) (exists mp_join (1 2 3 4 0) 2 p __t0o62217) (exists mp_union (1 2 0) 1 __t0o62217) (join-old $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 (1 2 4 6 7 3 0 5 8 9 10) l m p r __t0o62217 n __t5xrH216 q __t0BoC218 u v) (neq q __v0) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0BoC218) (exists mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t0o62217 q __t0BoC218 __t7HEI219) (join-old mp_union (0 1 2) 3 (0 1 2) __t5xrH216 __t0o62217 __t0BoC218) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask869 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex850;  slog::Index** $sup5638x110x0x0x0index851;  slog::Index** mbranchindex852;  slog::Index** mp_joinindex853;  slog::Index** mbranchindex854;  slog::Index** mp_joinindex855;  slog::Index** mp_unionindex856;  slog::Index** $sup5638x110x0x0x0index857;  slog::Index** mbranchindex858;  slog::Index** mp_unionindex859;  slog::Index** mp_joinindex860;  slog::Index** mp_unionindex861;  slog::Index** mp_join_ansindex862;  slog::Index** mp_mskdelta863;  slog::Index** mbranchdelta864;  slog::Index** $sup5638x110x0x0x0delta865;  slog::Index** mbranchdelta866;  slog::Index** mp_joindelta867;  slog::Index** mp_uniondelta868;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord870({0, 1});
      slog::Relation* readrel871 = db->getRelation("mp_union_ans");
      head_index[0] = readrel871->getIndex(ord870, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord872({0, 1, 2});
      slog::Relation* readrel873 = db->getRelation("mp_msk");
      mp_mskindex850 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1, 2});
      slog::Relation* readrel875 = db->getRelation("mp_msk");
      mp_mskdelta863 = readrel875->getIndex(ord874, true);
      std::vector<u16> ord876({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel877 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index851 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({2, 0, 1, 3, 4});
      slog::Relation* readrel879 = db->getRelation("mbranch");
      mbranchindex852 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({1, 2, 3, 4, 0});
      slog::Relation* readrel881 = db->getRelation("mp_join");
      mp_joinindex853 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 3, 4, 0});
      slog::Relation* readrel883 = db->getRelation("mbranch");
      mbranchindex854 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 3, 4, 0});
      slog::Relation* readrel885 = db->getRelation("mbranch");
      mbranchdelta864 = readrel885->getIndex(ord884, true);
      std::vector<u16> ord886({1, 2, 3, 4, 0});
      slog::Relation* readrel887 = db->getRelation("mp_join");
      mp_joinindex855 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("mp_union");
      mp_unionindex856 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel891 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index857 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel893 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0delta865 = readrel893->getIndex(ord892, true);
      std::vector<u16> ord894({1, 2, 3, 4, 0});
      slog::Relation* readrel895 = db->getRelation("mbranch");
      mbranchindex858 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({1, 2, 3, 4, 0});
      slog::Relation* readrel897 = db->getRelation("mbranch");
      mbranchdelta866 = readrel897->getIndex(ord896, true);
      std::vector<u16> ord898({0, 1, 2});
      slog::Relation* readrel899 = db->getRelation("mp_union");
      mp_unionindex859 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 2, 3, 4, 0});
      slog::Relation* readrel901 = db->getRelation("mp_join");
      mp_joinindex860 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 3, 4, 0});
      slog::Relation* readrel903 = db->getRelation("mp_join");
      mp_joindelta867 = readrel903->getIndex(ord902, true);
      std::vector<u16> ord904({0, 1, 2});
      slog::Relation* readrel905 = db->getRelation("mp_union");
      mp_unionindex861 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("mp_union");
      mp_uniondelta868 = readrel907->getIndex(ord906, true);
      std::vector<u16> ord908({0, 1});
      slog::Relation* readrel909 = db->getRelation("mp_join_ans");
      mp_join_ansindex862 = readrel909->getIndex(ord908, false);
  
    }
    ReadTask869(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex850, mp_mskdelta863, std::array<u64,3>{v_c30, 0, 0}, [&](const std::array<u64,3>& m910) {
          u64 v_c10 = m910[1]; u64 v_c31 = m910[2];
          if (!slog::exists_probe<11,2>($sup5638x110x0x0x0index851, std::array<u64,11>{v_c31, v_c10, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex852, std::array<u64,5>{v_c31, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex853, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(mbranchindex854, mbranchdelta864, std::array<u64,5>{v_c10, 0, 0, 0, 0}, [&](const std::array<u64,5>& m911) {
            u64 v_c9 = m911[1]; u64 v_c8 = m911[2]; u64 v_c11 = m911[3]; u64 v_c33 = m911[4];
            u64 v_c131 = _prim_lt(db, v_c9, v_c31);
            if (v_c131 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c131) return;
            if (!slog::exists_probe<5,2>(mp_joinindex855, std::array<u64,5>{v_c10, v_c33, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex856, std::array<u64,3>{v_c33, 0, 0})) return;
            slog::join_probe_old<11,6>($sup5638x110x0x0x0index857, $sup5638x110x0x0x0delta865, std::array<u64,11>{v_c8, v_c9, v_c10, v_c11, v_c33, v_c31, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m913) {
              u64 v_c35 = m913[6]; u64 v_c36 = m913[7]; u64 v_c37 = m913[8]; u64 v_c38 = m913[9]; u64 v_c12 = m913[10];
              if (v_c36 == v_c32) return;
              slog::join_probe_old<5,5>(mbranchindex858, mbranchdelta866, std::array<u64,5>{v_c36, v_c31, v_c38, v_c12, v_c37}, [&](const std::array<u64,5>& m914) {
                if (!slog::exists_probe<3,3>(mp_unionindex859, std::array<u64,3>{v_c35, v_c33, v_c37})) return;
                slog::join_probe_old<5,4>(mp_joinindex860, mp_joindelta867, std::array<u64,5>{v_c10, v_c33, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m915) {
                  u64 v_c39 = m915[4];
                  slog::join_probe_old<3,3>(mp_unionindex861, mp_uniondelta868, std::array<u64,3>{v_c35, v_c33, v_c37}, [&](const std::array<u64,3>& m916) {
                    slog::join_probe<2,1>(mp_join_ansindex862, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m917) {
                      u64 v_c40 = m917[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c40}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask869* _cont = new ReadTask869(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask869(db,b), false);
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t16yQ277 t k) (body (join mp_has0_ans (0 1) 2 __t16yQ277 __tconst6EKe278) (exists mp_put_soft (1 2 3 0) 2 t k) (exists mp_put (1 2 0 3) 2 t k) (join $sup5638x68x0x0x0 (1 2 3 0) 2 k t v __t2Eey276) (join mp_put_soft (1 2 3 0) 4 t k v __t2Eey276) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t4H3I279) (join mp_put_ans (0 1) 1 __t4H3I279 r)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask926 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex918;  slog::Index** mp_put_softindex919;  slog::Index** mp_putindex920;  slog::Index** $sup5638x68x0x0x0index921;  slog::Index** mp_put_softindex922;  slog::Index** mp_putindex923;  slog::Index** mp_put_ansindex924;  slog::Index** mp_putdelta925;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord927({0, 1});
      slog::Relation* readrel928 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel928->getIndex(ord927, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord929({0, 1});
      slog::Relation* readrel930 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex918 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({1, 2, 3, 0});
      slog::Relation* readrel932 = db->getRelation("mp_put_soft");
      mp_put_softindex919 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 2, 0, 3});
      slog::Relation* readrel934 = db->getRelation("mp_put");
      mp_putindex920 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 2, 3, 0});
      slog::Relation* readrel936 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index921 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 2, 3, 0});
      slog::Relation* readrel938 = db->getRelation("mp_put_soft");
      mp_put_softindex922 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 2, 3, 0});
      slog::Relation* readrel940 = db->getRelation("mp_put");
      mp_putindex923 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({1, 2, 3, 0});
      slog::Relation* readrel942 = db->getRelation("mp_put");
      mp_putdelta925 = readrel942->getIndex(ord941, true);
      std::vector<u16> ord943({0, 1});
      slog::Relation* readrel944 = db->getRelation("mp_put_ans");
      mp_put_ansindex924 = readrel944->getIndex(ord943, false);
  
    }
    ReadTask926(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c133 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<2,2>(mp_has0_ansindex918, std::array<u64,2>{v_c133, v_c132}, [&](const std::array<u64,2>& m945) {
          if (!slog::exists_probe<4,2>(mp_put_softindex919, std::array<u64,4>{v_c22, v_c7, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex920, std::array<u64,4>{v_c22, v_c7, 0, 0})) return;
          slog::join_probe<4,2>($sup5638x68x0x0x0index921, std::array<u64,4>{v_c7, v_c22, 0, 0}, [&](const std::array<u64,4>& m946) {
            u64 v_c12 = m946[2]; u64 v_c134 = m946[3];
            slog::join_probe<4,4>(mp_put_softindex922, std::array<u64,4>{v_c22, v_c7, v_c12, v_c134}, [&](const std::array<u64,4>& m947) {
              slog::join_probe_old<4,3>(mp_putindex923, mp_putdelta925, std::array<u64,4>{v_c22, v_c7, v_c12, 0}, [&](const std::array<u64,4>& m948) {
                u64 v_c135 = m948[3];
                slog::join_probe<2,1>(mp_put_ansindex924, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m949) {
                  u64 v_c11 = m949[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c11}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask926* _cont = new ReadTask926(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask926(db,b), false);
}

