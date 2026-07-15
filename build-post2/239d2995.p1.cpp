
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const11445e6556bc59ce1e80cdf7;
extern u64 v_const1ca60a80dbae6414bef23d65;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6c3d8aa344844f80a370de02;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_cc6157e7c6a73b0a1(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan mbranch __t4LnY139 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t4LnY139 k __t8UOT140)) (head (emit $sup5638x81x0x0x0 (0 1 2 3 4 5) __t8UOT140 k l m p r)) map.slog:82 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex0;  slog::Index** mp_deldelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord3({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel4 = db->getRelation("$sup5638x81x0x0x0");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("mp_del");
      mp_delindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("mp_del");
      mp_deldelta1 = readrel8->getIndex(ord7, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex0, mp_deldelta1, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c5 = m9[1]; u64 v_c6 = m9[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c6, v_c5, v_c3, v_c2, v_c1, v_c4}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre) (scan mp_msk __t5usA297 p n) (body (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join mp_msk_ans (0 1) 1 __t5usA297 q) (join $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t5usA297 l m n p q r u)) map.slog:108 #f)
  class ReadTask13 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index10;  slog::Index** mp_msk_ansindex11;  slog::Index** $sup5638x107x0x0x0index12;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord14({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel15 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel15->getIndex(ord14, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord16({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel17 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index10 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex11 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel21 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index12 = readrel21->getIndex(ord20, false);
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index10, std::array<u64,9>{v_c8, v_c1, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex11, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m22) {
          u64 v_c9 = m22[1];
          slog::join_probe<9,3>($sup5638x107x0x0x0index12, std::array<u64,9>{v_c8, v_c1, v_c9, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m23) {
            u64 v_c10 = m23[3]; u64 v_c3 = m23[4]; u64 v_c2 = m23[5]; u64 v_c4 = m23[6]; u64 v_c11 = m23[7]; u64 v_c12 = m23[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c10, v_c12, v_c7, v_c3, v_c2, v_c8, v_c1, v_c9, v_c4, v_c11}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask13* _cont = new ReadTask13(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask13(db,b), false);
  // (crule (pre (let __trid80h4624 const6c3d8aa344844f80a370de02) (let __trel8MXk625 constdd7bbf31ce5f578b9805e840) (let __tcol0hBE626 const5feceb66ffc86f38d952786c) (let __trel2xNd627 constdd7bbf31ce5f578b9805e840) (let __tcol9xBa628 const6b86b273ff34fce19d6b804e)) (scan $sup5638x101x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck q (accept int) __trid80h4624 __trel8MXk625 __tcol0hBE626 (1 2 3 4 0)) (tycheck m (accept int) __trid80h4624 __trel2xNd627 __tcol9xBa628 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __3dI4623 q m)) map.slog:102 #f)
  class ReadTask24 : public slog::Task
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
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6c3d8aa344844f80a370de02;
      u64 v_c14 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c15 = v_const5feceb66ffc86f38d952786c;
      u64 v_c16 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c4 = _t[6];
        u64 v_c18 = _t[7];
        u64 v_c19 = _t[8];
        u64 v_c11 = _t[9];
        u64 v_c12 = _t[10];
        ++_fires;
        if (!(is_int(v_c9)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c13, v_c14, v_c15, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c16, v_c17, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c9, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre (let __tconst2TBF232 const5feceb66ffc86f38d952786c)) (scan mbranch __t2Hro229 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t2Hro229 __t7SeD231 __t0LiB230) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t0LiB230 p m l r) (cmp lt n m) (let __t1wK1233 (band q m)) (cmp gt __t1wK1233 __tconst2TBF232)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t7SeD231 r l m n p q u v)) map.slog:99 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex25;  slog::Index** mbranchindex26;  slog::Index** mp_uniondelta27;  slog::Index** mbranchdelta28;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord30({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel31 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord32({2, 0, 1});
      slog::Relation* readrel33 = db->getRelation("mp_union");
      mp_unionindex25 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 0, 1});
      slog::Relation* readrel35 = db->getRelation("mp_union");
      mp_uniondelta27 = readrel35->getIndex(ord34, true);
      std::vector<u16> ord36({0, 1, 2, 3, 4});
      slog::Relation* readrel37 = db->getRelation("mbranch");
      mbranchindex26 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1, 2, 3, 4});
      slog::Relation* readrel39 = db->getRelation("mbranch");
      mbranchdelta28 = readrel39->getIndex(ord38, true);
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c12 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex25, mp_uniondelta27, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m40) {
          u64 v_c22 = m40[1]; u64 v_c23 = m40[2];
          slog::join_probe_old<5,1>(mbranchindex26, mbranchdelta28, std::array<u64,5>{v_c23, 0, 0, 0, 0}, [&](const std::array<u64,5>& m41) {
            u64 v_c1 = m41[1]; u64 v_c2 = m41[2]; u64 v_c3 = m41[3]; u64 v_c4 = m41[4];
            u64 v_c24 = _prim_lt(db, v_c8, v_c2);
            if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c24) return;
            u64 v_c25 = _prim_band(db, v_c9, v_c2);
            if (v_c25 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c26 = _prim_gt(db, v_c25, v_c20);
            if (v_c26 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c26) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c22, v_c4, v_c3, v_c2, v_c8, v_c1, v_c9, v_c11, v_c12}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask29* _cont = new ReadTask29(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask29(db,b), false);
  // (crule (pre) (scan mp_union __t1JFT249 __t3xpB250 __t8UiN251) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3xpB250 p m l r) (join-old mbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t8UiN251 q u v) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __9uYp581 p __t3xpB250 q __t8UiN251)) map.slog:114 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex44;  slog::Index** mbranchindex45;  slog::Index** mbranchdelta46;  slog::Index** mbranchdelta47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord49({0, 1, 2, 3, 4});
      slog::Relation* readrel50 = db->getRelation("mbranch");
      mbranchindex44 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1, 2, 3, 4});
      slog::Relation* readrel52 = db->getRelation("mbranch");
      mbranchdelta46 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({2, 0, 1, 3, 4});
      slog::Relation* readrel54 = db->getRelation("mbranch");
      mbranchindex45 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({2, 0, 1, 3, 4});
      slog::Relation* readrel56 = db->getRelation("mbranch");
      mbranchdelta47 = readrel56->getIndex(ord55, true);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<5,1>(mbranchindex44, mbranchdelta46, std::array<u64,5>{v_c28, 0, 0, 0, 0}, [&](const std::array<u64,5>& m57) {
          u64 v_c1 = m57[1]; u64 v_c2 = m57[2]; u64 v_c3 = m57[3]; u64 v_c4 = m57[4];
          slog::join_probe_old<5,2>(mbranchindex45, mbranchdelta47, std::array<u64,5>{v_c2, v_c29, 0, 0, 0}, [&](const std::array<u64,5>& m58) {
            u64 v_c9 = m58[2]; u64 v_c11 = m58[3]; u64 v_c12 = m58[4];
            if (v_c1 == v_c9) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c1, v_c28, v_c9, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre) (scan $sup5638x44x0x0x0 __t5vsG428 k l m p r __t51uB429 v) (body (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t51uB429) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t51uB429 k __t5vsG428 v) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t51uB429 k __t9vyw431 __t9k3L430) (join-old mleaf (0 1 2) 3 (0 1 2) __t9k3L430 k v) (exists mp_join_ans (0 1) 1 __t9vyw431) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask74 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex59;  slog::Index** mp_putindex60;  slog::Index** mleafindex61;  slog::Index** mp_mskindex62;  slog::Index** mp_joinindex63;  slog::Index** mleafindex64;  slog::Index** mp_join_ansindex65;  slog::Index** mp_mskindex66;  slog::Index** mp_msk_ansindex67;  slog::Index** mp_join_ansindex68;  slog::Index** mbranchdelta69;  slog::Index** mp_putdelta70;  slog::Index** mp_joindelta71;  slog::Index** mleafdelta72;  slog::Index** mp_mskdelta73;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("mp_put_ans");
      head_index[0] = readrel76->getIndex(ord75, false);
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord77({1, 2, 3, 4, 0});
      slog::Relation* readrel78 = db->getRelation("mbranch");
      mbranchindex59 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 3, 4, 0});
      slog::Relation* readrel80 = db->getRelation("mbranch");
      mbranchdelta69 = readrel80->getIndex(ord79, true);
      std::vector<u16> ord81({1, 2, 0, 3});
      slog::Relation* readrel82 = db->getRelation("mp_put");
      mp_putindex60 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 0, 3});
      slog::Relation* readrel84 = db->getRelation("mp_put");
      mp_putdelta70 = readrel84->getIndex(ord83, true);
      std::vector<u16> ord85({1, 2, 0});
      slog::Relation* readrel86 = db->getRelation("mleaf");
      mleafindex61 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("mp_msk");
      mp_mskindex62 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({3, 4, 1, 0, 2});
      slog::Relation* readrel90 = db->getRelation("mp_join");
      mp_joinindex63 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({3, 4, 1, 0, 2});
      slog::Relation* readrel92 = db->getRelation("mp_join");
      mp_joindelta71 = readrel92->getIndex(ord91, true);
      std::vector<u16> ord93({0, 1, 2});
      slog::Relation* readrel94 = db->getRelation("mleaf");
      mleafindex64 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("mleaf");
      mleafdelta72 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("mp_join_ans");
      mp_join_ansindex65 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("mp_msk");
      mp_mskindex66 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 0});
      slog::Relation* readrel102 = db->getRelation("mp_msk");
      mp_mskdelta73 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex67 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("mp_join_ans");
      mp_join_ansindex68 = readrel106->getIndex(ord105, false);
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c4 = _t[5];
        u64 v_c31 = _t[6];
        u64 v_c12 = _t[7];
        slog::join_probe_old<5,5>(mbranchindex59, mbranchdelta69, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, v_c31}, [&](const std::array<u64,5>& m107) {
          slog::join_probe_old<4,4>(mp_putindex60, mp_putdelta70, std::array<u64,4>{v_c31, v_c5, v_c30, v_c12}, [&](const std::array<u64,4>& m108) {
            if (!slog::exists_probe<3,2>(mleafindex61, std::array<u64,3>{v_c5, v_c12, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex62, std::array<u64,3>{v_c5, v_c2, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex63, mp_joindelta71, std::array<u64,5>{v_c1, v_c31, v_c5, 0, 0}, [&](const std::array<u64,5>& m109) {
              u64 v_c32 = m109[3]; u64 v_c33 = m109[4];
              slog::join_probe_old<3,3>(mleafindex64, mleafdelta72, std::array<u64,3>{v_c33, v_c5, v_c12}, [&](const std::array<u64,3>& m110) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex65, std::array<u64,2>{v_c32, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex66, mp_mskdelta73, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m111) {
                  u64 v_c34 = m111[2];
                  slog::join_probe<2,1>(mp_msk_ansindex67, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m112) {
                    u64 v_c35 = m112[1];
                    if (v_c1 == v_c35) return;
                    slog::join_probe<2,1>(mp_join_ansindex68, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m113) {
                      u64 v_c36 = m113[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c36}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  // (crule (pre (let __tconst0uEk118 const5feceb66ffc86f38d952786c)) (scan mbranch __t52bR116 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t52bR116 k __t7lZr117) (let __t2JJZ119 (band k m)) (cmp gt __t2JJZ119 __tconst0uEk118)) (head (emit $sup5638x84x0x0x0 (4 2 3 5 0 1) p l m r __t7lZr117 k)) map.slog:85 #f)
  class ReadTask116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex114;  slog::Index** mp_deldelta115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord117({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel118 = db->getRelation("$sup5638x84x0x0x0");
      head_index[0] = readrel118->getIndex(ord117, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord119({1, 2, 0});
      slog::Relation* readrel120 = db->getRelation("mp_del");
      mp_delindex114 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("mp_del");
      mp_deldelta115 = readrel122->getIndex(ord121, true);
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex114, mp_deldelta115, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m123) {
          u64 v_c5 = m123[1]; u64 v_c39 = m123[2];
          u64 v_c40 = _prim_band(db, v_c5, v_c2);
          if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          u64 v_c41 = _prim_gt(db, v_c40, v_c37);
          if (v_c41 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          if (!v_c41) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c1, v_c3, v_c2, v_c4, v_c39, v_c5}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan mp_msk __t61OZ179 q m) (body (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join mp_msk_ans (0 1) 1 __t61OZ179 p) (join $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t61OZ179 l m n p q u v)) map.slog:99 #f)
  class ReadTask128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index125;  slog::Index** mp_msk_ansindex126;  slog::Index** $sup5638x98x0x0x0index127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord129({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel130 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel130->getIndex(ord129, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord131({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel132 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index125 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex126 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel136 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index127 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index125, std::array<u64,9>{v_c2, v_c9, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex126, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m137) {
          u64 v_c1 = m137[1];
          slog::join_probe<9,3>($sup5638x98x0x0x0index127, std::array<u64,9>{v_c2, v_c9, v_c1, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m138) {
            u64 v_c10 = m138[3]; u64 v_c3 = m138[4]; u64 v_c8 = m138[5]; u64 v_c4 = m138[6]; u64 v_c11 = m138[7]; u64 v_c12 = m138[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c10, v_c4, v_c42, v_c3, v_c2, v_c8, v_c1, v_c9, v_c11, v_c12}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask128* _cont = new ReadTask128(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask128(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t2bXu55 __v0) (body (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t2bXu55 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t2bXu55 __v0) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v3) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t2bXu55 __v0 __v3) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v1) (exists mp_msk (2 0 1) 1 __v1) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2bXu55 __v0 __v3 __v1 __t6Puw51 dup3kne1056 dup92Cz1057 p0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join mp_msk_ans (0 1) 1 __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask156 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex139;  slog::Index** $sup5638x25x0x0x2index140;  slog::Index** $sup5638x25x0x0x1index141;  slog::Index** mp_hsb_ansindex142;  slog::Index** $sup5638x25x0x0x2index143;  slog::Index** mp_hsb_ansindex144;  slog::Index** mp_mskindex145;  slog::Index** $sup5638x25x0x0x2index146;  slog::Index** $sup5638x25x0x0x1index147;  slog::Index** $sup5638x25x0x0x0index148;  slog::Index** mp_joinindex149;  slog::Index** mp_mskindex150;  slog::Index** mp_msk_ansindex151;  slog::Index** mp_hsbindex152;  slog::Index** mp_joindelta153;  slog::Index** mp_mskdelta154;  slog::Index** mp_hsbdelta155;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex139 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel160 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index140 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel162 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index141 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex142 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel166 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index143 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex144 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({2, 0, 1});
      slog::Relation* readrel170 = db->getRelation("mp_msk");
      mp_mskindex145 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel172 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index146 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel174 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index147 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0, 2, 3, 4});
      slog::Relation* readrel176 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index148 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 3, 4, 0});
      slog::Relation* readrel178 = db->getRelation("mp_join");
      mp_joinindex149 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 3, 4, 0});
      slog::Relation* readrel180 = db->getRelation("mp_join");
      mp_joindelta153 = readrel180->getIndex(ord179, true);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("mp_msk");
      mp_mskindex150 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0});
      slog::Relation* readrel184 = db->getRelation("mp_msk");
      mp_mskdelta154 = readrel184->getIndex(ord183, true);
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex151 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0, 1});
      slog::Relation* readrel188 = db->getRelation("mp_hsb");
      mp_hsbindex152 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("mp_hsb");
      mp_hsbdelta155 = readrel190->getIndex(ord189, true);
  
    }
    ReadTask156(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c35 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex139, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index140, std::array<u64,11>{v_c44, v_c35, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index141, std::array<u64,7>{v_c44, v_c35, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex142, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m191) {
          u64 v_c45 = m191[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index143, std::array<u64,11>{v_c44, v_c35, v_c45, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex144, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m192) {
            u64 v_c46 = m192[1];
            if (!slog::exists_probe<3,1>(mp_mskindex145, std::array<u64,3>{v_c46, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index146, std::array<u64,11>{v_c44, v_c35, v_c45, v_c46, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m193) {
              u64 v_c47 = m193[4]; u64 v_c48 = m193[5]; u64 v_c49 = m193[6]; u64 v_c50 = m193[7]; u64 v_c51 = m193[8]; u64 v_c52 = m193[9]; u64 v_c53 = m193[10];
              if (v_c44 != v_c49) return;
              if (v_c44 != v_c48) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index147, std::array<u64,7>{v_c47, v_c50, v_c51, v_c52, v_c53, v_c44, v_c35}, [&](const std::array<u64,7>& m194) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index148, std::array<u64,5>{v_c50, v_c47, v_c51, v_c52, v_c53}, [&](const std::array<u64,5>& m195) {
                  slog::join_probe_old<5,5>(mp_joinindex149, mp_joindelta153, std::array<u64,5>{v_c50, v_c52, v_c51, v_c53, v_c47}, [&](const std::array<u64,5>& m196) {
                    slog::join_probe_old<3,2>(mp_mskindex150, mp_mskdelta154, std::array<u64,3>{v_c50, v_c46, 0}, [&](const std::array<u64,3>& m197) {
                      u64 v_c54 = m197[2];
                      slog::join_probe<2,1>(mp_msk_ansindex151, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m198) {
                        u64 v_c55 = m198[1];
                        u64 v_c56 = _prim_bxor(db, v_c50, v_c51);
                        if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex152, mp_hsbdelta155, std::array<u64,2>{v_c44, v_c56}, [&](const std::array<u64,2>& m199) {
                          u64 v_c57 = _prim_band(db, v_c50, v_c35);
                          if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c58 = _prim_lt(db, v_c57, v_c43);
                          if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c58) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c47, v_c55, v_c45, v_c52, v_c53});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c45, v_c52, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask156* _cont = new ReadTask156(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask156(db,b), false);
  // (crule (pre (let __tconst74CV622 constd01925b37634a1a9d24159d8)) (scan mp_del __t63g3245 __t9xNA244 k) (body (exists _enum (1 0) 1 __tconst74CV622) (join mleaf (0 1 2) 2 __t9xNA244 k v) (join _enum (1 0) 1 __tconst74CV622 __t4Y7b243)) (head (emit mp_del_ans (0 1) __t63g3245 __t4Y7b243)) map.slog:80 #f)
  class ReadTask204 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex201;  slog::Index** mleafindex202;  slog::Index** _enumindex203;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("mp_del_ans");
      head_index[0] = readrel206->getIndex(ord205, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("_enum");
      _enumindex201 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({0, 1, 2});
      slog::Relation* readrel210 = db->getRelation("mleaf");
      mleafindex202 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("_enum");
      _enumindex203 = readrel212->getIndex(ord211, false);
  
    }
    ReadTask204(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_constd01925b37634a1a9d24159d8;
  
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
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex201, std::array<u64,2>{v_c59, 0})) return;
        slog::join_probe<3,2>(mleafindex202, std::array<u64,3>{v_c61, v_c5, 0}, [&](const std::array<u64,3>& m213) {
          u64 v_c12 = m213[2];
          slog::join_probe<2,1>(_enumindex203, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m214) {
            u64 v_c62 = m214[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c60, v_c62}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:80", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask204* _cont = new ReadTask204(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask204(db,b), false);
  // (crule (pre) (scan mp_union __t4hCg320 s __t4k6G319) (body (exists mp_put_soft (1 2 3 0) 1 s) (join mleaf (0 1 2) 1 __t4k6G319 k v) (join-old mp_put_soft (1 2 3 0) 3 (1 2 3 0) s k v __t6FhG321) (join mp_put_soft_ans (0 1) 1 __t6FhG321 r)) (head (emit mp_union_ans (0 1) __t4hCg320 r)) map.slog:93 #f)
  class ReadTask220 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex215;  slog::Index** mleafindex216;  slog::Index** mp_put_softindex217;  slog::Index** mp_put_soft_ansindex218;  slog::Index** mp_put_softdelta219;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("mp_union_ans");
      head_index[0] = readrel222->getIndex(ord221, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord223({1, 2, 3, 0});
      slog::Relation* readrel224 = db->getRelation("mp_put_soft");
      mp_put_softindex215 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1, 2});
      slog::Relation* readrel226 = db->getRelation("mleaf");
      mleafindex216 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 3, 0});
      slog::Relation* readrel228 = db->getRelation("mp_put_soft");
      mp_put_softindex217 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 3, 0});
      slog::Relation* readrel230 = db->getRelation("mp_put_soft");
      mp_put_softdelta219 = readrel230->getIndex(ord229, true);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex218 = readrel232->getIndex(ord231, false);
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        u64 v_c64 = _t[2];
        if (!slog::exists_probe<4,1>(mp_put_softindex215, std::array<u64,4>{v_c18, 0, 0, 0})) return;
        slog::join_probe<3,1>(mleafindex216, std::array<u64,3>{v_c64, 0, 0}, [&](const std::array<u64,3>& m233) {
          u64 v_c5 = m233[1]; u64 v_c12 = m233[2];
          slog::join_probe_old<4,3>(mp_put_softindex217, mp_put_softdelta219, std::array<u64,4>{v_c18, v_c5, v_c12, 0}, [&](const std::array<u64,4>& m234) {
            u64 v_c65 = m234[3];
            slog::join_probe<2,1>(mp_put_soft_ansindex218, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m235) {
              u64 v_c4 = m235[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c4}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_union", _fires);
  
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
  // (crule (pre) (scan mp_put __t529R323 __t4DNq324 k v) (body (exists mp_join (1 4 2 0 3) 2 k __t4DNq324) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t6sa2325) (join-old mp_join (1 4 2 0 3) 3 (1 4 2 0 3) k __t4DNq324 __t6sa2325 __t1dCZ326 j) (neq j k) (exists mp_join_ans (0 1) 1 __t1dCZ326) (join-old mleaf (0 1 2) 2 (0 1 2) __t4DNq324 j w) (join mp_join_ans (0 1) 1 __t1dCZ326 r)) (head (emit mp_put_ans (0 1) __t529R323 r)) map.slog:39 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex236;  slog::Index** mleafindex237;  slog::Index** mp_joinindex238;  slog::Index** mp_join_ansindex239;  slog::Index** mleafindex240;  slog::Index** mp_join_ansindex241;  slog::Index** mleafdelta242;  slog::Index** mp_joindelta243;  slog::Index** mleafdelta244;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord246({0, 1});
      slog::Relation* readrel247 = db->getRelation("mp_put_ans");
      head_index[0] = readrel247->getIndex(ord246, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord248({1, 4, 2, 0, 3});
      slog::Relation* readrel249 = db->getRelation("mp_join");
      mp_joinindex236 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 2, 0});
      slog::Relation* readrel251 = db->getRelation("mleaf");
      mleafindex237 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("mleaf");
      mleafdelta242 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 4, 2, 0, 3});
      slog::Relation* readrel255 = db->getRelation("mp_join");
      mp_joinindex238 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 4, 2, 0, 3});
      slog::Relation* readrel257 = db->getRelation("mp_join");
      mp_joindelta243 = readrel257->getIndex(ord256, true);
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("mp_join_ans");
      mp_join_ansindex239 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({0, 1, 2});
      slog::Relation* readrel261 = db->getRelation("mleaf");
      mleafindex240 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({0, 1, 2});
      slog::Relation* readrel263 = db->getRelation("mleaf");
      mleafdelta244 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({0, 1});
      slog::Relation* readrel265 = db->getRelation("mp_join_ans");
      mp_join_ansindex241 = readrel265->getIndex(ord264, false);
  
    }
    ReadTask245(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c12 = _t[3];
        if (!slog::exists_probe<5,2>(mp_joinindex236, std::array<u64,5>{v_c5, v_c67, 0, 0, 0})) return;
        slog::join_probe_old<3,2>(mleafindex237, mleafdelta242, std::array<u64,3>{v_c5, v_c12, 0}, [&](const std::array<u64,3>& m266) {
          u64 v_c68 = m266[2];
          slog::join_probe_old<5,3>(mp_joinindex238, mp_joindelta243, std::array<u64,5>{v_c5, v_c67, v_c68, 0, 0}, [&](const std::array<u64,5>& m267) {
            u64 v_c69 = m267[3]; u64 v_c70 = m267[4];
            if (v_c70 == v_c5) return;
            if (!slog::exists_probe<2,1>(mp_join_ansindex239, std::array<u64,2>{v_c69, 0})) return;
            slog::join_probe_old<3,2>(mleafindex240, mleafdelta244, std::array<u64,3>{v_c67, v_c70, 0}, [&](const std::array<u64,3>& m268) {
              u64 v_c71 = m268[2];
              slog::join_probe<2,1>(mp_join_ansindex241, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m269) {
                u64 v_c4 = m269[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c66, v_c4}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask245* _cont = new ReadTask245(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask245(db,b), false);
  // (crule (pre) (scan temp5uMp1022 __t7c7N419) (body) (head (mkstruct mp_hsb (1 0) __00nI776 __t7c7N419)) map.slog:30 #f)
  class ReadTask270 : public slog::Task
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
      outer_rel = db->getRelation("temp5uMp1022");
  
    }
    ReadTask270(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c72}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp5uMp1022", _fires);
  
      if (!_done)
      {
        ReadTask270* _cont = new ReadTask270(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask270(db,b), false);
  // (crule (pre) (scan $sup5638x42x0x0x0 __d0 k l m p r v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1WO0167) (join-old mp_msk_ans (0 1) 2 (0 1) __t1WO0167 p)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t1WO0167 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask276 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex271;  slog::Index** mp_mskindex272;  slog::Index** mp_msk_ansindex273;  slog::Index** mp_mskdelta274;  slog::Index** mp_msk_ansdelta275;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord277({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel278 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel278->getIndex(ord277, false);
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord279({1, 0});
      slog::Relation* readrel280 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex271 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("mp_msk");
      mp_mskindex272 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 0});
      slog::Relation* readrel284 = db->getRelation("mp_msk");
      mp_mskdelta274 = readrel284->getIndex(ord283, true);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex273 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta275 = readrel288->getIndex(ord287, true);
  
    }
    ReadTask276(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c4 = _t[5];
        u64 v_c12 = _t[6];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex271, std::array<u64,2>{v_c1, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex272, mp_mskdelta274, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m289) {
          u64 v_c73 = m289[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex273, mp_msk_ansdelta275, std::array<u64,2>{v_c73, v_c1}, [&](const std::array<u64,2>& m290) {
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c73, v_c1, v_c10, v_c5, v_c3, v_c2, v_c4, v_c12}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask276* _cont = new ReadTask276(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask276(db,b), false);
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t0q1c75 p) (body (exists $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) 2 __t0q1c75 p) (exists $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t0q1c75 k m) (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_put (2 3 0 1) 1 k) (join-old $sup5638x40x0x0x1 (1 2 4 5 0 3 6 7) 4 (1 2 4 5 0 3 6 7) __t0q1c75 k m p __t1I5N72 l r v) (join-old $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 (4 2 3 5 0 1 6) p l m r __t1I5N72 k v) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_put (1 2 3 0) 3 l k v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t687K71) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t687K71 k __t1I5N72 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join-old mp_put_ans (0 1) 1 (0 1) __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask313 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index291;  slog::Index** $sup5638x40x0x0x0index292;  slog::Index** mbranchindex293;  slog::Index** mp_mskindex294;  slog::Index** $sup5638x40x0x0x0index295;  slog::Index** mbranchindex296;  slog::Index** mp_putindex297;  slog::Index** $sup5638x40x0x0x1index298;  slog::Index** $sup5638x40x0x0x0index299;  slog::Index** mp_putindex300;  slog::Index** mp_putindex301;  slog::Index** mbranchindex302;  slog::Index** mp_putindex303;  slog::Index** mp_putindex304;  slog::Index** mp_put_ansindex305;  slog::Index** mp_mskdelta306;  slog::Index** $sup5638x40x0x0x1delta307;  slog::Index** $sup5638x40x0x0x0delta308;  slog::Index** mbranchdelta309;  slog::Index** mp_putdelta310;  slog::Index** mp_putdelta311;  slog::Index** mp_put_ansdelta312;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord314({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel315 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index291 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel317 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index292 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 3, 4, 0});
      slog::Relation* readrel319 = db->getRelation("mbranch");
      mbranchindex293 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("mp_msk");
      mp_mskindex294 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1, 2});
      slog::Relation* readrel323 = db->getRelation("mp_msk");
      mp_mskdelta306 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel325 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index295 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 3, 4, 0});
      slog::Relation* readrel327 = db->getRelation("mbranch");
      mbranchindex296 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({2, 3, 0, 1});
      slog::Relation* readrel329 = db->getRelation("mp_put");
      mp_putindex297 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel331 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index298 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel333 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta307 = readrel333->getIndex(ord332, true);
      std::vector<u16> ord334({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel335 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index299 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel337 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0delta308 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({2, 3, 0, 1});
      slog::Relation* readrel339 = db->getRelation("mp_put");
      mp_putindex300 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 2, 3, 0});
      slog::Relation* readrel341 = db->getRelation("mp_put");
      mp_putindex301 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 3, 4, 0});
      slog::Relation* readrel343 = db->getRelation("mbranch");
      mbranchindex302 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 3, 4, 0});
      slog::Relation* readrel345 = db->getRelation("mbranch");
      mbranchdelta309 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({1, 2, 0, 3});
      slog::Relation* readrel347 = db->getRelation("mp_put");
      mp_putindex303 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 2, 0, 3});
      slog::Relation* readrel349 = db->getRelation("mp_put");
      mp_putdelta310 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({1, 2, 3, 0});
      slog::Relation* readrel351 = db->getRelation("mp_put");
      mp_putindex304 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 3, 0});
      slog::Relation* readrel353 = db->getRelation("mp_put");
      mp_putdelta311 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1});
      slog::Relation* readrel355 = db->getRelation("mp_put_ans");
      mp_put_ansindex305 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("mp_put_ans");
      mp_put_ansdelta312 = readrel357->getIndex(ord356, true);
  
    }
    ReadTask313(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<8,2>($sup5638x40x0x0x1index291, std::array<u64,8>{v_c75, v_c1, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x40x0x0x0index292, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex293, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex294, mp_mskdelta306, std::array<u64,3>{v_c75, 0, 0}, [&](const std::array<u64,3>& m358) {
          u64 v_c5 = m358[1]; u64 v_c2 = m358[2];
          if (!slog::exists_probe<7,3>($sup5638x40x0x0x0index295, std::array<u64,7>{v_c5, v_c2, v_c1, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex296, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex297, std::array<u64,4>{v_c5, 0, 0, 0})) return;
          slog::join_probe_old<8,4>($sup5638x40x0x0x1index298, $sup5638x40x0x0x1delta307, std::array<u64,8>{v_c75, v_c5, v_c2, v_c1, 0, 0, 0, 0}, [&](const std::array<u64,8>& m359) {
            u64 v_c76 = m359[4]; u64 v_c3 = m359[5]; u64 v_c4 = m359[6]; u64 v_c12 = m359[7];
            slog::join_probe_old<7,7>($sup5638x40x0x0x0index299, $sup5638x40x0x0x0delta308, std::array<u64,7>{v_c1, v_c3, v_c2, v_c4, v_c76, v_c5, v_c12}, [&](const std::array<u64,7>& m360) {
              if (!slog::exists_probe<4,3>(mp_putindex300, std::array<u64,4>{v_c5, v_c12, v_c76, 0})) return;
              if (!slog::exists_probe<4,3>(mp_putindex301, std::array<u64,4>{v_c3, v_c5, v_c12, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex302, mbranchdelta309, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m361) {
                u64 v_c77 = m361[4];
                slog::join_probe_old<4,4>(mp_putindex303, mp_putdelta310, std::array<u64,4>{v_c77, v_c5, v_c76, v_c12}, [&](const std::array<u64,4>& m362) {
                  slog::join_probe_old<4,3>(mp_putindex304, mp_putdelta311, std::array<u64,4>{v_c3, v_c5, v_c12, 0}, [&](const std::array<u64,4>& m363) {
                    u64 v_c78 = m363[3];
                    slog::join_probe_old<2,1>(mp_put_ansindex305, mp_put_ansdelta312, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m364) {
                      u64 v_c35 = m364[1];
                      u64 v_c79 = _prim_band(db, v_c5, v_c2);
                      if (v_c79 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c80 = _prim_lt(db, v_c79, v_c74);
                      if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c80) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c76, v_c35, v_c2, v_c1, v_c4});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c35, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask313* _cont = new ReadTask313(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask313(db,b), false);
  // (crule (pre) (scan mp_union_ans __t0Kdo264 __v1) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t0Kdo264 r v) (exists mbranch (4 0 1 2 3) 1 v) (exists mbranch (4 0 1 2 3) 1 r) (join-old $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 (4 6 0 1 2 3 5) r v __t9rnk262 l m p u) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t5rXw260) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2wpn261) (join-old mp_union (0 1 2) 3 (0 1 2) __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t2Oaj263) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask384 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex366;  slog::Index** mbranchindex367;  slog::Index** mbranchindex368;  slog::Index** $sup5638x93x0x0x0index369;  slog::Index** mbranchindex370;  slog::Index** mp_unionindex371;  slog::Index** mbranchindex372;  slog::Index** mp_unionindex373;  slog::Index** mbranchindex374;  slog::Index** mp_unionindex375;  slog::Index** mp_unionindex376;  slog::Index** mp_union_ansindex377;  slog::Index** mp_uniondelta378;  slog::Index** $sup5638x93x0x0x0delta379;  slog::Index** mbranchdelta380;  slog::Index** mbranchdelta381;  slog::Index** mp_uniondelta382;  slog::Index** mp_uniondelta383;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord385({0, 1, 2});
      slog::Relation* readrel386 = db->getRelation("mp_union");
      mp_unionindex366 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 1, 2});
      slog::Relation* readrel388 = db->getRelation("mp_union");
      mp_uniondelta378 = readrel388->getIndex(ord387, true);
      std::vector<u16> ord389({4, 0, 1, 2, 3});
      slog::Relation* readrel390 = db->getRelation("mbranch");
      mbranchindex367 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({4, 0, 1, 2, 3});
      slog::Relation* readrel392 = db->getRelation("mbranch");
      mbranchindex368 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel394 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index369 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel396 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0delta379 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({1, 2, 3, 4, 0});
      slog::Relation* readrel398 = db->getRelation("mbranch");
      mbranchindex370 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("mp_union");
      mp_unionindex371 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 3, 4, 0});
      slog::Relation* readrel402 = db->getRelation("mbranch");
      mbranchindex372 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 3, 4, 0});
      slog::Relation* readrel404 = db->getRelation("mbranch");
      mbranchdelta380 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({2, 0, 1});
      slog::Relation* readrel406 = db->getRelation("mp_union");
      mp_unionindex373 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 3, 4, 0});
      slog::Relation* readrel408 = db->getRelation("mbranch");
      mbranchindex374 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 3, 4, 0});
      slog::Relation* readrel410 = db->getRelation("mbranch");
      mbranchdelta381 = readrel410->getIndex(ord409, true);
      std::vector<u16> ord411({0, 1, 2});
      slog::Relation* readrel412 = db->getRelation("mp_union");
      mp_unionindex375 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({0, 1, 2});
      slog::Relation* readrel414 = db->getRelation("mp_union");
      mp_uniondelta382 = readrel414->getIndex(ord413, true);
      std::vector<u16> ord415({1, 2, 0});
      slog::Relation* readrel416 = db->getRelation("mp_union");
      mp_unionindex376 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("mp_union");
      mp_uniondelta383 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({0, 1});
      slog::Relation* readrel420 = db->getRelation("mp_union_ans");
      mp_union_ansindex377 = readrel420->getIndex(ord419, false);
  
    }
    ReadTask384(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c81 = _t[0];
        u64 v_c46 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex366, mp_uniondelta378, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m421) {
          u64 v_c4 = m421[1]; u64 v_c12 = m421[2];
          if (!slog::exists_probe<5,1>(mbranchindex367, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex368, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup5638x93x0x0x0index369, $sup5638x93x0x0x0delta379, std::array<u64,7>{v_c4, v_c12, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m422) {
            u64 v_c82 = m422[2]; u64 v_c3 = m422[3]; u64 v_c2 = m422[4]; u64 v_c1 = m422[5]; u64 v_c11 = m422[6];
            if (!slog::exists_probe<5,4>(mbranchindex370, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex371, std::array<u64,3>{v_c3, v_c11, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex372, mbranchdelta380, std::array<u64,5>{v_c1, v_c2, v_c11, v_c12, 0}, [&](const std::array<u64,5>& m423) {
              u64 v_c83 = m423[4];
              if (!slog::exists_probe<3,2>(mp_unionindex373, std::array<u64,3>{v_c83, v_c82, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex374, mbranchdelta381, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m424) {
                u64 v_c84 = m424[4];
                slog::join_probe_old<3,3>(mp_unionindex375, mp_uniondelta382, std::array<u64,3>{v_c82, v_c84, v_c83}, [&](const std::array<u64,3>& m425) {
                  slog::join_probe_old<3,2>(mp_unionindex376, mp_uniondelta383, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m426) {
                    u64 v_c85 = m426[2];
                    slog::join_probe<2,1>(mp_union_ansindex377, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m427) {
                      u64 v_c35 = m427[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c82, v_c35, v_c46, v_c2, v_c1});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c35, v_c46}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union_ans", _fires);
  
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
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_join __t6Puw51 p0 t0 p1 t1) (body (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (exists $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t6Puw51 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 5 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists mp_hsb_ans (0 1) 2 __t2bXu55 __v0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0 dup3kne1056 dup92Cz1057 __v1 __v3) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join mp_hsb_ans (0 1) 2 __t2bXu55 __v3) (join mp_hsb_ans (0 1) 2 __t2bXu55 __v1) (join mp_hsb_ans (0 1) 2 __t2bXu55 __v0) (join mp_msk (1 2 0) 2 p0 __v1 __t6JeD58) (join mp_msk_ans (0 1) 1 __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join mp_hsb (0 1) 2 __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask441 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x0index428;  slog::Index** $sup5638x25x0x0x2index429;  slog::Index** mp_mskindex430;  slog::Index** $sup5638x25x0x0x1index431;  slog::Index** mp_hsb_ansindex432;  slog::Index** mp_hsb_ansindex433;  slog::Index** $sup5638x25x0x0x2index434;  slog::Index** mp_hsb_ansindex435;  slog::Index** mp_hsb_ansindex436;  slog::Index** mp_hsb_ansindex437;  slog::Index** mp_mskindex438;  slog::Index** mp_msk_ansindex439;  slog::Index** mp_hsbindex440;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord442({1, 0, 2, 3, 4});
      slog::Relation* readrel443 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index428 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel445 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index429 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 2, 0});
      slog::Relation* readrel447 = db->getRelation("mp_msk");
      mp_mskindex430 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel449 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index431 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({0, 1});
      slog::Relation* readrel451 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex432 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({0, 1});
      slog::Relation* readrel453 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex433 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel455 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index434 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 1});
      slog::Relation* readrel457 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex435 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex436 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex437 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("mp_msk");
      mp_mskindex438 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex439 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("mp_hsb");
      mp_hsbindex440 = readrel467->getIndex(ord466, false);
  
    }
    ReadTask441(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c52 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c53 = _t[4];
        slog::join_probe<5,5>($sup5638x25x0x0x0index428, std::array<u64,5>{v_c50, v_c47, v_c51, v_c52, v_c53}, [&](const std::array<u64,5>& m468) {
          if (!slog::exists_probe<11,5>($sup5638x25x0x0x2index429, std::array<u64,11>{v_c47, v_c50, v_c51, v_c52, v_c53, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex430, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x25x0x0x1index431, std::array<u64,7>{v_c47, v_c50, v_c51, v_c52, v_c53, 0, 0}, [&](const std::array<u64,7>& m469) {
            u64 v_c44 = m469[5]; u64 v_c35 = m469[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex432, std::array<u64,2>{v_c44, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex433, std::array<u64,2>{v_c44, v_c35})) return;
            slog::join_probe<11,7>($sup5638x25x0x0x2index434, std::array<u64,11>{v_c47, v_c50, v_c51, v_c52, v_c53, v_c44, v_c35, 0, 0, 0, 0}, [&](const std::array<u64,11>& m470) {
              u64 v_c48 = m470[7]; u64 v_c49 = m470[8]; u64 v_c46 = m470[9]; u64 v_c45 = m470[10];
              if (v_c44 != v_c49) return;
              if (v_c44 != v_c48) return;
              slog::join_probe<2,2>(mp_hsb_ansindex435, std::array<u64,2>{v_c44, v_c45}, [&](const std::array<u64,2>& m471) {
                slog::join_probe<2,2>(mp_hsb_ansindex436, std::array<u64,2>{v_c44, v_c46}, [&](const std::array<u64,2>& m472) {
                  slog::join_probe<2,2>(mp_hsb_ansindex437, std::array<u64,2>{v_c44, v_c35}, [&](const std::array<u64,2>& m473) {
                    slog::join_probe<3,2>(mp_mskindex438, std::array<u64,3>{v_c50, v_c46, 0}, [&](const std::array<u64,3>& m474) {
                      u64 v_c54 = m474[2];
                      slog::join_probe<2,1>(mp_msk_ansindex439, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m475) {
                        u64 v_c55 = m475[1];
                        u64 v_c56 = _prim_bxor(db, v_c50, v_c51);
                        if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe<2,2>(mp_hsbindex440, std::array<u64,2>{v_c44, v_c56}, [&](const std::array<u64,2>& m476) {
                          u64 v_c57 = _prim_band(db, v_c50, v_c35);
                          if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c86 = _prim_lt(db, v_c57, v_c43);
                          if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c86) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c47, v_c55, v_c45, v_c52, v_c53});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c45, v_c52, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask441* _cont = new ReadTask441(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask441(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan $sup5638x98x0x0x0 __t2uCs95 l m n p q r u v) (body (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 r) (join-old $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t2uCs95 n q u v __t9ory98) (exists mp_msk (1 2 0) 3 q m __t9ory98) (exists mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2SOF94) (exists mp_union (0 1 2) 2 __t2uCs95 __t2SOF94) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_union (0 1 2) 3 (0 1 2) __t2uCs95 __t2SOF94 __t1Mtu99) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask500 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex478;  slog::Index** mbranchindex479;  slog::Index** mp_mskindex480;  slog::Index** mp_msk_ansindex481;  slog::Index** mp_unionindex482;  slog::Index** $sup5638x98x0x0x1index483;  slog::Index** mp_mskindex484;  slog::Index** mp_msk_ansindex485;  slog::Index** mbranchindex486;  slog::Index** mp_unionindex487;  slog::Index** mbranchindex488;  slog::Index** mp_unionindex489;  slog::Index** mp_mskindex490;  slog::Index** mp_msk_ansindex491;  slog::Index** mp_unionindex492;  slog::Index** mp_union_ansindex493;  slog::Index** $sup5638x98x0x0x1delta494;  slog::Index** mbranchdelta495;  slog::Index** mbranchdelta496;  slog::Index** mp_uniondelta497;  slog::Index** mp_mskdelta498;  slog::Index** mp_uniondelta499;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord501({1, 2, 3, 4, 0});
      slog::Relation* readrel502 = db->getRelation("mbranch");
      mbranchindex478 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 3, 4, 0});
      slog::Relation* readrel504 = db->getRelation("mbranch");
      mbranchindex479 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 2, 0});
      slog::Relation* readrel506 = db->getRelation("mp_msk");
      mp_mskindex480 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 0});
      slog::Relation* readrel508 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex481 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 0});
      slog::Relation* readrel510 = db->getRelation("mp_union");
      mp_unionindex482 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel512 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index483 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel514 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta494 = readrel514->getIndex(ord513, true);
      std::vector<u16> ord515({1, 2, 0});
      slog::Relation* readrel516 = db->getRelation("mp_msk");
      mp_mskindex484 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex485 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 3, 4, 0});
      slog::Relation* readrel520 = db->getRelation("mbranch");
      mbranchindex486 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 2, 3, 4, 0});
      slog::Relation* readrel522 = db->getRelation("mbranch");
      mbranchdelta495 = readrel522->getIndex(ord521, true);
      std::vector<u16> ord523({0, 1, 2});
      slog::Relation* readrel524 = db->getRelation("mp_union");
      mp_unionindex487 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 3, 4, 0});
      slog::Relation* readrel526 = db->getRelation("mbranch");
      mbranchindex488 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 3, 4, 0});
      slog::Relation* readrel528 = db->getRelation("mbranch");
      mbranchdelta496 = readrel528->getIndex(ord527, true);
      std::vector<u16> ord529({0, 1, 2});
      slog::Relation* readrel530 = db->getRelation("mp_union");
      mp_unionindex489 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1, 2});
      slog::Relation* readrel532 = db->getRelation("mp_union");
      mp_uniondelta497 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({1, 2, 0});
      slog::Relation* readrel534 = db->getRelation("mp_msk");
      mp_mskindex490 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 0});
      slog::Relation* readrel536 = db->getRelation("mp_msk");
      mp_mskdelta498 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({0, 1});
      slog::Relation* readrel538 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex491 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("mp_union");
      mp_unionindex492 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 0});
      slog::Relation* readrel542 = db->getRelation("mp_union");
      mp_uniondelta499 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({0, 1});
      slog::Relation* readrel544 = db->getRelation("mp_union_ans");
      mp_union_ansindex493 = readrel544->getIndex(ord543, false);
  
    }
    ReadTask500(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c88 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c4 = _t[6];
        u64 v_c11 = _t[7];
        u64 v_c12 = _t[8];
        u64 v_c89 = _prim_lt(db, v_c8, v_c2);
        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
        if (!v_c89) return;
        if (!slog::exists_probe<5,4>(mbranchindex478, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex479, std::array<u64,5>{v_c9, v_c8, v_c11, v_c12, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex480, std::array<u64,3>{v_c9, v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex481, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex482, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x98x0x0x1index483, $sup5638x98x0x0x1delta494, std::array<u64,10>{v_c4, v_c3, v_c2, v_c1, v_c88, v_c8, v_c9, v_c11, v_c12, 0}, [&](const std::array<u64,10>& m546) {
          u64 v_c90 = m546[9];
          if (!slog::exists_probe<3,3>(mp_mskindex484, std::array<u64,3>{v_c9, v_c2, v_c90})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex485, std::array<u64,2>{v_c90, v_c1})) return;
          slog::join_probe_old<5,4>(mbranchindex486, mbranchdelta495, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m547) {
            u64 v_c91 = m547[4];
            if (!slog::exists_probe<3,2>(mp_unionindex487, std::array<u64,3>{v_c88, v_c91, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex488, mbranchdelta496, std::array<u64,5>{v_c9, v_c8, v_c11, v_c12, 0}, [&](const std::array<u64,5>& m548) {
              u64 v_c92 = m548[4];
              slog::join_probe_old<3,3>(mp_unionindex489, mp_uniondelta497, std::array<u64,3>{v_c88, v_c91, v_c92}, [&](const std::array<u64,3>& m549) {
                slog::join_probe_old<3,3>(mp_mskindex490, mp_mskdelta498, std::array<u64,3>{v_c9, v_c2, v_c90}, [&](const std::array<u64,3>& m550) {
                  slog::join_probe<2,2>(mp_msk_ansindex491, std::array<u64,2>{v_c90, v_c1}, [&](const std::array<u64,2>& m551) {
                    slog::join_probe_old<3,2>(mp_unionindex492, mp_uniondelta499, std::array<u64,3>{v_c4, v_c92, 0}, [&](const std::array<u64,3>& m552) {
                      u64 v_c93 = m552[2];
                      slog::join_probe<2,1>(mp_union_ansindex493, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m553) {
                        u64 v_c35 = m553[1];
                        u64 v_c94 = _prim_band(db, v_c9, v_c2);
                        if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c95 = _prim_gt(db, v_c94, v_c87);
                        if (v_c95 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c95) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c88, v_c35, v_c3, v_c2, v_c1});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c3, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
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
  // (crule (pre (let __trid9jln649 const11445e6556bc59ce1e80cdf7) (let __trel3RCI650 consta24220c5193376967f1fa95e) (let __tcol3EqM651 const5feceb66ffc86f38d952786c) (let __trel1Q3W652 consta24220c5193376967f1fa95e) (let __tcol2JBD653 const6b86b273ff34fce19d6b804e) (let __trel5xKz654 consta24220c5193376967f1fa95e) (let __tcol4a7t655 constd4735e3a265e16eee03f5971) (let __trel0yMd656 consta24220c5193376967f1fa95e) (let __tcol6Uyq657 const4e07408562bedb8b60ce05c1)) (scan $sup5638x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid9jln649 __trel3RCI650 __tcol3EqM651 (1 2 3 4 0)) (tycheck s (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid9jln649 __trel1Q3W652 __tcol2JBD653 (1 2 3 4 0)) (tycheck q (accept int) __trid9jln649 __trel5xKz654 __tcol4a7t655 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid9jln649 __trel0yMd656 __tcol6Uyq657 (1 2 3 4 0)) (mkstruct mp_join (1 2 3 4 0) __79fY648 p s q t)) map.slog:111 #f)
  class ReadTask558 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid556;  u32 sid555;  u32 sid557;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("mp_join");
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
      sid556 = db->getRelation("_enum")->getStructId();
      sid555 = db->getRelation("mbranch")->getStructId();
      sid557 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c96 = v_const11445e6556bc59ce1e80cdf7;
      u64 v_c97 = v_consta24220c5193376967f1fa95e;
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_consta24220c5193376967f1fa95e;
      u64 v_c100 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c101 = v_consta24220c5193376967f1fa95e;
      u64 v_c102 = v_constd4735e3a265e16eee03f5971;
      u64 v_c103 = v_consta24220c5193376967f1fa95e;
      u64 v_c104 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c10 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c4 = _t[6];
        u64 v_c18 = _t[7];
        u64 v_c19 = _t[8];
        u64 v_c11 = _t[9];
        u64 v_c12 = _t[10];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c96, v_c97, v_c98, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid555 || decode_struct_id(v_c18) == sid556 || decode_struct_id(v_c18) == sid557))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c96, v_c99, v_c100, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c96, v_c101, v_c102, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c19) && (decode_struct_id(v_c19) == sid555 || decode_struct_id(v_c19) == sid556 || decode_struct_id(v_c19) == sid557))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c96, v_c103, v_c104, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c1, v_c18, v_c9, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:$sup5638x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask558* _cont = new ReadTask558(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask558(db,b), false);
  // (crule (pre (let __trid482j833 const1ca60a80dbae6414bef23d65) (let __trel8eIU834 constdd7bbf31ce5f578b9805e840) (let __tcol6HnD835 const5feceb66ffc86f38d952786c) (let __trel6ylf836 constdd7bbf31ce5f578b9805e840) (let __tcol9y0W837 const6b86b273ff34fce19d6b804e)) (scan $sup5638x44x0x0x0 __d0 k l m p r t v) (body) (head (tycheck k (accept int) __trid482j833 __trel8eIU834 __tcol6HnD835 (1 2 3 4 0)) (tycheck m (accept int) __trid482j833 __trel6ylf836 __tcol9y0W837 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4X2A832 k m)) map.slog:45 #f)
  class ReadTask559 : public slog::Task
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
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
  
    }
    ReadTask559(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const1ca60a80dbae6414bef23d65;
      u64 v_c106 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
      u64 v_c108 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c109 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c4 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c12 = _t[7];
        ++_fires;
        if (!(is_int(v_c5)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c105, v_c106, v_c107, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c105, v_c108, v_c109, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask559* _cont = new ReadTask559(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask559(db,b), false);
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mp_put __t9fJL76 l k v) (body (exists $sup5638x40x0x0x1 (2 3 7 0 1 4 5 6) 3 k l v) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put_ans (0 1) 1 __t9fJL76) (join $sup5638x40x0x0x0 (1 2 6 0 3 4 5) 3 k l v __t1I5N72 m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t1I5N72 k v __t0q1c75) (exists mp_msk (1 2 0) 3 k m __t0q1c75) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join mbranch (1 2 3 4 0) 4 p m l r __t687K71) (join mp_put (1 2 0 3) 4 __t687K71 k __t1I5N72 v) (join mp_msk (1 2 0) 3 k m __t0q1c75) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask578 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index560;  slog::Index** mbranchindex561;  slog::Index** mp_putindex562;  slog::Index** mp_mskindex563;  slog::Index** mp_put_ansindex564;  slog::Index** $sup5638x40x0x0x0index565;  slog::Index** mbranchindex566;  slog::Index** mp_putindex567;  slog::Index** mp_mskindex568;  slog::Index** mp_msk_ansindex569;  slog::Index** $sup5638x40x0x0x1index570;  slog::Index** mp_mskindex571;  slog::Index** mp_msk_ansindex572;  slog::Index** mbranchindex573;  slog::Index** mp_putindex574;  slog::Index** mp_mskindex575;  slog::Index** mp_msk_ansindex576;  slog::Index** mp_put_ansindex577;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord579({2, 3, 7, 0, 1, 4, 5, 6});
      slog::Relation* readrel580 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index560 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({3, 0, 1, 2, 4});
      slog::Relation* readrel582 = db->getRelation("mbranch");
      mbranchindex561 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({2, 3, 0, 1});
      slog::Relation* readrel584 = db->getRelation("mp_put");
      mp_putindex562 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 2, 0});
      slog::Relation* readrel586 = db->getRelation("mp_msk");
      mp_mskindex563 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("mp_put_ans");
      mp_put_ansindex564 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel590 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index565 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 3, 4, 0});
      slog::Relation* readrel592 = db->getRelation("mbranch");
      mbranchindex566 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({2, 3, 0, 1});
      slog::Relation* readrel594 = db->getRelation("mp_put");
      mp_putindex567 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 2, 0});
      slog::Relation* readrel596 = db->getRelation("mp_msk");
      mp_mskindex568 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 0});
      slog::Relation* readrel598 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex569 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel600 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index570 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 0});
      slog::Relation* readrel602 = db->getRelation("mp_msk");
      mp_mskindex571 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex572 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({1, 2, 3, 4, 0});
      slog::Relation* readrel606 = db->getRelation("mbranch");
      mbranchindex573 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 2, 0, 3});
      slog::Relation* readrel608 = db->getRelation("mp_put");
      mp_putindex574 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 2, 0});
      slog::Relation* readrel610 = db->getRelation("mp_msk");
      mp_mskindex575 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex576 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({0, 1});
      slog::Relation* readrel614 = db->getRelation("mp_put_ans");
      mp_put_ansindex577 = readrel614->getIndex(ord613, false);
  
    }
    ReadTask578(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c78 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c12 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index560, std::array<u64,8>{v_c5, v_c3, v_c12, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex561, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex562, std::array<u64,4>{v_c5, v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex563, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex564, std::array<u64,2>{v_c78, 0})) return;
        slog::join_probe<7,3>($sup5638x40x0x0x0index565, std::array<u64,7>{v_c5, v_c3, v_c12, 0, 0, 0, 0}, [&](const std::array<u64,7>& m615) {
          u64 v_c76 = m615[3]; u64 v_c2 = m615[4]; u64 v_c1 = m615[5]; u64 v_c4 = m615[6];
          if (!slog::exists_probe<5,4>(mbranchindex566, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex567, std::array<u64,4>{v_c5, v_c12, v_c76, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex568, std::array<u64,3>{v_c5, v_c2, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex569, std::array<u64,2>{v_c1, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index570, std::array<u64,8>{v_c3, v_c2, v_c1, v_c4, v_c76, v_c5, v_c12, 0}, [&](const std::array<u64,8>& m616) {
            u64 v_c75 = m616[7];
            if (!slog::exists_probe<3,3>(mp_mskindex571, std::array<u64,3>{v_c5, v_c2, v_c75})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex572, std::array<u64,2>{v_c75, v_c1})) return;
            slog::join_probe<5,4>(mbranchindex573, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m617) {
              u64 v_c77 = m617[4];
              slog::join_probe<4,4>(mp_putindex574, std::array<u64,4>{v_c77, v_c5, v_c76, v_c12}, [&](const std::array<u64,4>& m618) {
                slog::join_probe<3,3>(mp_mskindex575, std::array<u64,3>{v_c5, v_c2, v_c75}, [&](const std::array<u64,3>& m619) {
                  slog::join_probe<2,2>(mp_msk_ansindex576, std::array<u64,2>{v_c75, v_c1}, [&](const std::array<u64,2>& m620) {
                    slog::join_probe<2,1>(mp_put_ansindex577, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m621) {
                      u64 v_c35 = m621[1];
                      u64 v_c79 = _prim_band(db, v_c5, v_c2);
                      if (v_c79 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c110 = _prim_lt(db, v_c79, v_c74);
                      if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c110) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c76, v_c35, v_c2, v_c1, v_c4});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c35, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask578* _cont = new ReadTask578(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask578(db,b), false);
  // (crule (pre (let __trid2hJI853 constfee494ff4827aeb0635bb714) (let __trel0l7X854 const20347926ddb307a8e2bdb71b) (let __tcol3G8h855 constd4735e3a265e16eee03f5971)) (scan mp_msk_ans __t1DER257 p) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t1DER257 k m) (exists mp_del (2 0 1) 1 k) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t4tTw258) (join-old mp_del_ans (0 1) 1 (0 1) __t4tTw258 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2hJI853 __trel0l7X854 __tcol3G8h855 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __5v59852 p m l __v0)) map.slog:85 #f)
  class ReadTask635 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index623;  slog::Index** mp_mskindex624;  slog::Index** mp_delindex625;  slog::Index** $sup5638x84x0x0x0index626;  slog::Index** mp_delindex627;  slog::Index** mp_del_ansindex628;  slog::Index** mp_mskdelta629;  slog::Index** mp_deldelta630;  slog::Index** mp_del_ansdelta631;
    u32 sid633;  u32 sid632;  u32 sid634;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord636({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel637 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index623 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({0, 1, 2});
      slog::Relation* readrel639 = db->getRelation("mp_msk");
      mp_mskindex624 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({0, 1, 2});
      slog::Relation* readrel641 = db->getRelation("mp_msk");
      mp_mskdelta629 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({2, 0, 1});
      slog::Relation* readrel643 = db->getRelation("mp_del");
      mp_delindex625 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel645 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index626 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 2, 0});
      slog::Relation* readrel647 = db->getRelation("mp_del");
      mp_delindex627 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("mp_del");
      mp_deldelta630 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("mp_del_ans");
      mp_del_ansindex628 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("mp_del_ans");
      mp_del_ansdelta631 = readrel653->getIndex(ord652, true);
      sid633 = db->getRelation("_enum")->getStructId();
      sid632 = db->getRelation("mbranch")->getStructId();
      sid634 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask635(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c111 = v_constfee494ff4827aeb0635bb714;
      u64 v_c112 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c113 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c114 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x84x0x0x0index623, std::array<u64,6>{v_c1, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex624, mp_mskdelta629, std::array<u64,3>{v_c114, 0, 0}, [&](const std::array<u64,3>& m654) {
          u64 v_c5 = m654[1]; u64 v_c2 = m654[2];
          if (!slog::exists_probe<3,1>(mp_delindex625, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x84x0x0x0index626, std::array<u64,6>{v_c5, v_c2, v_c1, 0, 0, 0}, [&](const std::array<u64,6>& m655) {
            u64 v_c10 = m655[3]; u64 v_c3 = m655[4]; u64 v_c4 = m655[5];
            slog::join_probe_old<3,2>(mp_delindex627, mp_deldelta630, std::array<u64,3>{v_c4, v_c5, 0}, [&](const std::array<u64,3>& m656) {
              u64 v_c115 = m656[2];
              slog::join_probe_old<2,1>(mp_del_ansindex628, mp_del_ansdelta631, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m657) {
                u64 v_c35 = m657[1];
                ++_fires;
                if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid632 || decode_struct_id(v_c3) == sid633 || decode_struct_id(v_c3) == sid634))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c111, v_c112, v_c113, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c3, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst0Qj0123 const6b86b273ff34fce19d6b804e)) (scan mp_del __t8oJB122 __t9IJy121 k) (body (join mbranch (0 1 2 3 4) 1 __t9IJy121 p m l r) (let __t0Fhz124 (band k m)) (cmp lt __t0Fhz124 __tconst0Qj0123)) (head (emit $sup5638x82x0x0x0 (4 3 5 2 0 1) p m r l __t8oJB122 k)) map.slog:83 #f)
  class ReadTask659 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex658;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord660({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel661 = db->getRelation("$sup5638x82x0x0x0");
      head_index[0] = readrel661->getIndex(ord660, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord662({0, 1, 2, 3, 4});
      slog::Relation* readrel663 = db->getRelation("mbranch");
      mbranchindex658 = readrel663->getIndex(ord662, false);
  
    }
    ReadTask659(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c117 = _t[0];
        u64 v_c118 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<5,1>(mbranchindex658, std::array<u64,5>{v_c118, 0, 0, 0, 0}, [&](const std::array<u64,5>& m664) {
          u64 v_c1 = m664[1]; u64 v_c2 = m664[2]; u64 v_c3 = m664[3]; u64 v_c4 = m664[4];
          u64 v_c119 = _prim_band(db, v_c5, v_c2);
          if (v_c119 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          u64 v_c120 = _prim_lt(db, v_c119, v_c116);
          if (v_c120 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          if (!v_c120) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c1, v_c2, v_c4, v_c3, v_c117, v_c5}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask659* _cont = new ReadTask659(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask659(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x0 __t6Puw51 p0 p1 t0 t1) (body (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (exists $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t6Puw51 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 5 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists mp_hsb_ans (0 1) 2 __t2bXu55 __v0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0 dup3kne1056 dup92Cz1057 __v1 __v3) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join-old mp_msk_ans (0 1) 1 (0 1) __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask686 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex666;  slog::Index** $sup5638x25x0x0x2index667;  slog::Index** mp_mskindex668;  slog::Index** $sup5638x25x0x0x1index669;  slog::Index** mp_hsb_ansindex670;  slog::Index** mp_hsb_ansindex671;  slog::Index** $sup5638x25x0x0x2index672;  slog::Index** mp_hsb_ansindex673;  slog::Index** mp_hsb_ansindex674;  slog::Index** mp_hsb_ansindex675;  slog::Index** mp_mskindex676;  slog::Index** mp_msk_ansindex677;  slog::Index** mp_hsbindex678;  slog::Index** mp_joindelta679;  slog::Index** mp_hsb_ansdelta680;  slog::Index** mp_hsb_ansdelta681;  slog::Index** mp_hsb_ansdelta682;  slog::Index** mp_mskdelta683;  slog::Index** mp_msk_ansdelta684;  slog::Index** mp_hsbdelta685;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord687({1, 2, 3, 4, 0});
      slog::Relation* readrel688 = db->getRelation("mp_join");
      mp_joinindex666 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 3, 4, 0});
      slog::Relation* readrel690 = db->getRelation("mp_join");
      mp_joindelta679 = readrel690->getIndex(ord689, true);
      std::vector<u16> ord691({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel692 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index667 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("mp_msk");
      mp_mskindex668 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel696 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index669 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex670 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex671 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel702 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index672 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({0, 1});
      slog::Relation* readrel704 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex673 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta680 = readrel706->getIndex(ord705, true);
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex674 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({0, 1});
      slog::Relation* readrel710 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta681 = readrel710->getIndex(ord709, true);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex675 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta682 = readrel714->getIndex(ord713, true);
      std::vector<u16> ord715({1, 2, 0});
      slog::Relation* readrel716 = db->getRelation("mp_msk");
      mp_mskindex676 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("mp_msk");
      mp_mskdelta683 = readrel718->getIndex(ord717, true);
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex677 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({0, 1});
      slog::Relation* readrel722 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta684 = readrel722->getIndex(ord721, true);
      std::vector<u16> ord723({0, 1});
      slog::Relation* readrel724 = db->getRelation("mp_hsb");
      mp_hsbindex678 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({0, 1});
      slog::Relation* readrel726 = db->getRelation("mp_hsb");
      mp_hsbdelta685 = readrel726->getIndex(ord725, true);
  
    }
    ReadTask686(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        slog::join_probe_old<5,5>(mp_joinindex666, mp_joindelta679, std::array<u64,5>{v_c50, v_c52, v_c51, v_c53, v_c47}, [&](const std::array<u64,5>& m727) {
          if (!slog::exists_probe<11,5>($sup5638x25x0x0x2index667, std::array<u64,11>{v_c47, v_c50, v_c51, v_c52, v_c53, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex668, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x25x0x0x1index669, std::array<u64,7>{v_c47, v_c50, v_c51, v_c52, v_c53, 0, 0}, [&](const std::array<u64,7>& m728) {
            u64 v_c44 = m728[5]; u64 v_c35 = m728[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex670, std::array<u64,2>{v_c44, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex671, std::array<u64,2>{v_c44, v_c35})) return;
            slog::join_probe<11,7>($sup5638x25x0x0x2index672, std::array<u64,11>{v_c47, v_c50, v_c51, v_c52, v_c53, v_c44, v_c35, 0, 0, 0, 0}, [&](const std::array<u64,11>& m729) {
              u64 v_c48 = m729[7]; u64 v_c49 = m729[8]; u64 v_c46 = m729[9]; u64 v_c45 = m729[10];
              if (v_c44 != v_c49) return;
              if (v_c44 != v_c48) return;
              slog::join_probe_old<2,2>(mp_hsb_ansindex673, mp_hsb_ansdelta680, std::array<u64,2>{v_c44, v_c45}, [&](const std::array<u64,2>& m730) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex674, mp_hsb_ansdelta681, std::array<u64,2>{v_c44, v_c46}, [&](const std::array<u64,2>& m731) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex675, mp_hsb_ansdelta682, std::array<u64,2>{v_c44, v_c35}, [&](const std::array<u64,2>& m732) {
                    slog::join_probe_old<3,2>(mp_mskindex676, mp_mskdelta683, std::array<u64,3>{v_c50, v_c46, 0}, [&](const std::array<u64,3>& m733) {
                      u64 v_c54 = m733[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex677, mp_msk_ansdelta684, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m734) {
                        u64 v_c55 = m734[1];
                        u64 v_c56 = _prim_bxor(db, v_c50, v_c51);
                        if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex678, mp_hsbdelta685, std::array<u64,2>{v_c44, v_c56}, [&](const std::array<u64,2>& m735) {
                          u64 v_c57 = _prim_band(db, v_c50, v_c35);
                          if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c121 = _prim_lt(db, v_c57, v_c43);
                          if (v_c121 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c121) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c47, v_c55, v_c45, v_c52, v_c53});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c45, v_c52, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask686* _cont = new ReadTask686(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask686(db,b), false);
  // (crule (pre (let __trid2hJI853 constfee494ff4827aeb0635bb714) (let __trel0l7X854 const20347926ddb307a8e2bdb71b) (let __tcol3G8h855 constd4735e3a265e16eee03f5971)) (scan mp_del __t4tTw258 r k) (body (exists $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t4tTw258 __v0) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists mp_msk_ans (1 0) 1 p) (join mp_msk (1 2 0) 2 k m __t1DER257) (join mp_msk_ans (0 1) 2 __t1DER257 p)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2hJI853 __trel0l7X854 __tcol3G8h855 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __5v59852 p m l __v0)) map.slog:85 #f)
  class ReadTask747 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index737;  slog::Index** mp_mskindex738;  slog::Index** mp_del_ansindex739;  slog::Index** $sup5638x84x0x0x0index740;  slog::Index** mp_msk_ansindex741;  slog::Index** mp_mskindex742;  slog::Index** mp_msk_ansindex743;
    u32 sid745;  u32 sid744;  u32 sid746;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord748({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel749 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index737 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("mp_msk");
      mp_mskindex738 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({0, 1});
      slog::Relation* readrel753 = db->getRelation("mp_del_ans");
      mp_del_ansindex739 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel755 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index740 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 0});
      slog::Relation* readrel757 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex741 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("mp_msk");
      mp_mskindex742 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex743 = readrel761->getIndex(ord760, false);
      sid745 = db->getRelation("_enum")->getStructId();
      sid744 = db->getRelation("mbranch")->getStructId();
      sid746 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask747(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c111 = v_constfee494ff4827aeb0635bb714;
      u64 v_c112 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c113 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c115 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index737, std::array<u64,6>{v_c5, v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex738, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex739, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m762) {
          u64 v_c35 = m762[1];
          slog::join_probe<6,2>($sup5638x84x0x0x0index740, std::array<u64,6>{v_c5, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,6>& m763) {
            u64 v_c10 = m763[2]; u64 v_c3 = m763[3]; u64 v_c2 = m763[4]; u64 v_c1 = m763[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex741, std::array<u64,2>{v_c1, 0})) return;
            slog::join_probe<3,2>(mp_mskindex742, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m764) {
              u64 v_c114 = m764[2];
              slog::join_probe<2,2>(mp_msk_ansindex743, std::array<u64,2>{v_c114, v_c1}, [&](const std::array<u64,2>& m765) {
                ++_fires;
                if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid744 || decode_struct_id(v_c3) == sid745 || decode_struct_id(v_c3) == sid746))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c111, v_c112, v_c113, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c3, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask747* _cont = new ReadTask747(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask747(db,b), false);
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mbranch __t4G6v169 p m l r) (body (exists mp_has0 (1 2 0) 1 __t4G6v169) (exists mp_has0 (1 2 0) 1 l) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x60x0x0x0 (4 2 3 5 0 1) 4 p l m r __t5APc170 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t5APc170 k __t4G6v169) (exists mp_msk (1 2 0) 2 k m) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t8KSH173) (exists mp_has0_ans (0 1) 1 __t8KSH173) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4QPc174) (join mp_msk_ans (0 1) 2 __t4QPc174 p) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index766;  slog::Index** mp_has0index767;  slog::Index** mp_mskindex768;  slog::Index** mp_msk_ansindex769;  slog::Index** $sup5638x60x0x0x0index770;  slog::Index** mp_has0index771;  slog::Index** mp_mskindex772;  slog::Index** mp_has0index773;  slog::Index** mp_has0_ansindex774;  slog::Index** mp_mskindex775;  slog::Index** mp_msk_ansindex776;  slog::Index** mp_has0_ansindex777;  slog::Index** mp_has0delta778;  slog::Index** mp_has0delta779;  slog::Index** mp_mskdelta780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord782({0, 1});
      slog::Relation* readrel783 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel783->getIndex(ord782, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord784({1, 2, 0});
      slog::Relation* readrel785 = db->getRelation("mp_has0");
      mp_has0index766 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("mp_has0");
      mp_has0index767 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({2, 0, 1});
      slog::Relation* readrel789 = db->getRelation("mp_msk");
      mp_mskindex768 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 0});
      slog::Relation* readrel791 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex769 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel793 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index770 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({0, 2, 1});
      slog::Relation* readrel795 = db->getRelation("mp_has0");
      mp_has0index771 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({0, 2, 1});
      slog::Relation* readrel797 = db->getRelation("mp_has0");
      mp_has0delta778 = readrel797->getIndex(ord796, true);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("mp_msk");
      mp_mskindex772 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("mp_has0");
      mp_has0index773 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("mp_has0");
      mp_has0delta779 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({0, 1});
      slog::Relation* readrel805 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex774 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("mp_msk");
      mp_mskindex775 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("mp_msk");
      mp_mskdelta780 = readrel809->getIndex(ord808, true);
      std::vector<u16> ord810({0, 1});
      slog::Relation* readrel811 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex776 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex777 = readrel813->getIndex(ord812, false);
  
    }
    ReadTask781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c123 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index766, std::array<u64,3>{v_c123, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index767, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex768, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex769, std::array<u64,2>{v_c1, 0})) return;
        slog::join_probe<6,4>($sup5638x60x0x0x0index770, std::array<u64,6>{v_c1, v_c3, v_c2, v_c4, 0, 0}, [&](const std::array<u64,6>& m814) {
          u64 v_c124 = m814[4]; u64 v_c5 = m814[5];
          slog::join_probe_old<3,3>(mp_has0index771, mp_has0delta778, std::array<u64,3>{v_c124, v_c5, v_c123}, [&](const std::array<u64,3>& m815) {
            if (!slog::exists_probe<3,2>(mp_mskindex772, std::array<u64,3>{v_c5, v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index773, mp_has0delta779, std::array<u64,3>{v_c3, v_c5, 0}, [&](const std::array<u64,3>& m816) {
              u64 v_c125 = m816[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex774, std::array<u64,2>{v_c125, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex775, mp_mskdelta780, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m817) {
                u64 v_c126 = m817[2];
                slog::join_probe<2,2>(mp_msk_ansindex776, std::array<u64,2>{v_c126, v_c1}, [&](const std::array<u64,2>& m818) {
                  slog::join_probe<2,1>(mp_has0_ansindex777, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m819) {
                    u64 v_c127 = m819[1];
                    u64 v_c128 = _prim_band(db, v_c5, v_c2);
                    if (v_c128 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c129 = _prim_lt(db, v_c128, v_c122);
                    if (v_c129 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c129) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c124, v_c127}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mbranch", _fires);
  
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
}

