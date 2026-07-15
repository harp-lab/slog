
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const846f120b6b6ab883fe02a53a;
extern u64 v_consta22c7bfa7abc2d7d387fd7df;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_ce117930327306c0d(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid49Sj752 const846f120b6b6ab883fe02a53a) (let __trel87ul753 const1064263932db82f2cf6d4ac2) (let __tcol8zwN754 const5feceb66ffc86f38d952786c) (let __trel8cbp755 const1064263932db82f2cf6d4ac2) (let __tcol03Bp756 const6b86b273ff34fce19d6b804e)) (scan $sup5638x68x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid49Sj752 __trel87ul753 __tcol8zwN754 (1 2 3 4 0)) (tycheck k (accept int) __trid49Sj752 __trel8cbp755 __tcol03Bp756 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __41wd751 t k v)) map.slog:69 #f)
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
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("mbranch")->getStructId();
      sid2 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const846f120b6b6ab883fe02a53a;
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
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid0 || decode_struct_id(v_c7) == sid1 || decode_struct_id(v_c7) == sid2))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c7, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
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
  // (crule (pre (let __trid7MbP673 consta22c7bfa7abc2d7d387fd7df) (let __trel0y4j674 constdd7bbf31ce5f578b9805e840) (let __tcol9jrF675 const5feceb66ffc86f38d952786c) (let __trel11rN676 constdd7bbf31ce5f578b9805e840) (let __tcol2umO677 const6b86b273ff34fce19d6b804e)) (scan $sup5638x42x0x0x0 __d0 k l m p r v) (body) (head (tycheck k (accept int) __trid7MbP673 __trel0y4j674 __tcol9jrF675 (1 2 3 4 0)) (tycheck m (accept int) __trid7MbP673 __trel11rN676 __tcol2umO677 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __6h0E672 k m)) map.slog:43 #f)
  class ReadTask4 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta22c7bfa7abc2d7d387fd7df;
      u64 v_c10 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c17 = _t[5];
        u64 v_c8 = _t[6];
        ++_fires;
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c9, v_c10, v_c11, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c15)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c12, v_c13, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c15}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x0", _fires);
  
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
  // (crule (pre) (scan mp_union __t0116213 s __t8QAC212) (body (join mleaf (0 1 2) 1 __t8QAC212 k v)) (head (mkstruct mp_put_soft (1 2 3 0) __1yRr795 s k v)) map.slog:93 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex5;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord7({0, 1, 2});
      slog::Relation* readrel8 = db->getRelation("mleaf");
      mleafindex5 = readrel8->getIndex(ord7, false);
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(mleafindex5, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c6 = m9[1]; u64 v_c8 = m9[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c19, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan temp2mZ61026 __t09AU334 __t0sIx339 __t3why337) (body (let __t1Qmw338 (_0002a __t3why337 __t09AU334))) (head (emit-temp temp2PlQ1027 __t0sIx339 __t1Qmw338)) map.slog:22 #f)
  class ReadTask10 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2PlQ1027");
      outer_rel = db->getRelation("temp2mZ61026");
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[2];
        u64 v_c24 = _prim__0002a(db, v_c23, v_c21);
        if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c22, v_c24});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp2mZ61026", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan mp_put __t0PgJ163 __t5dUf162 k v) (body (join mleaf (0 1 2) 1 __t5dUf162 j w) (neq j k)) (head (emit-temp temp5R2q1072 __t5dUf162 j k v) (mkstruct mleaf (1 2 0) __t7RTp161 k v)) map.slog:39 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5R2q1072");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord13({0, 1, 2});
      slog::Relation* readrel14 = db->getRelation("mleaf");
      mleafindex11 = readrel14->getIndex(ord13, false);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c8 = _t[3];
        slog::join_probe<3,1>(mleafindex11, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m15) {
          u64 v_c27 = m15[1]; u64 v_c28 = m15[2];
          if (v_c27 == v_c6) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c26, v_c27, v_c6, v_c8});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c6, v_c8}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mbranch __t1Mtu99 q n u v) (body (exists $sup5638x98x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists mp_union (2 0 1) 1 __t1Mtu99) (exists mp_msk (1 2 0) 1 q) (join $sup5638x98x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t2uCs95 l m p r) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t1Mtu99 __t2uCs95) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 2 r __t1Mtu99) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t2uCs95 n q u v __t9ory98) (exists mp_msk (1 2 0) 3 q m __t9ory98) (exists mp_msk_ans (0 1) 2 __t9ory98 p) (join mbranch (1 2 3 4 0) 4 p m l r __t2SOF94) (join mp_union (0 1 2) 3 __t2uCs95 __t2SOF94 __t1Mtu99) (join mp_msk (1 2 0) 3 q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask35 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index16;  slog::Index** mp_unionindex17;  slog::Index** mp_mskindex18;  slog::Index** $sup5638x98x0x0x0index19;  slog::Index** mbranchindex20;  slog::Index** mp_unionindex21;  slog::Index** mp_mskindex22;  slog::Index** mp_msk_ansindex23;  slog::Index** mp_unionindex24;  slog::Index** $sup5638x98x0x0x1index25;  slog::Index** mp_mskindex26;  slog::Index** mp_msk_ansindex27;  slog::Index** mbranchindex28;  slog::Index** mp_unionindex29;  slog::Index** mp_mskindex30;  slog::Index** mp_msk_ansindex31;  slog::Index** mp_unionindex32;  slog::Index** mp_union_ansindex33;  slog::Index** mp_uniondelta34;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord36({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel37 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index16 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({2, 0, 1});
      slog::Relation* readrel39 = db->getRelation("mp_union");
      mp_unionindex17 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 0});
      slog::Relation* readrel41 = db->getRelation("mp_msk");
      mp_mskindex18 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel43 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index19 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 3, 4, 0});
      slog::Relation* readrel45 = db->getRelation("mbranch");
      mbranchindex20 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({2, 0, 1});
      slog::Relation* readrel47 = db->getRelation("mp_union");
      mp_unionindex21 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 0});
      slog::Relation* readrel49 = db->getRelation("mp_msk");
      mp_mskindex22 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex23 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("mp_union");
      mp_unionindex24 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel55 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index25 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 0});
      slog::Relation* readrel57 = db->getRelation("mp_msk");
      mp_mskindex26 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex27 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 3, 4, 0});
      slog::Relation* readrel61 = db->getRelation("mbranch");
      mbranchindex28 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1, 2});
      slog::Relation* readrel63 = db->getRelation("mp_union");
      mp_unionindex29 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("mp_msk");
      mp_mskindex30 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex31 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("mp_union");
      mp_unionindex32 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 2, 0});
      slog::Relation* readrel71 = db->getRelation("mp_union");
      mp_uniondelta34 = readrel71->getIndex(ord70, true);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("mp_union_ans");
      mp_union_ansindex33 = readrel73->getIndex(ord72, false);
  
    }
    ReadTask35(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c33 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x98x0x0x1index16, std::array<u64,10>{v_c32, v_c31, v_c33, v_c8, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex17, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex18, std::array<u64,3>{v_c31, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x98x0x0x0index19, std::array<u64,9>{v_c32, v_c31, v_c33, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m74) {
          u64 v_c34 = m74[4]; u64 v_c14 = m74[5]; u64 v_c15 = m74[6]; u64 v_c16 = m74[7]; u64 v_c17 = m74[8];
          u64 v_c35 = _prim_lt(db, v_c32, v_c15);
          if (v_c35 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c35) return;
          if (!slog::exists_probe<5,4>(mbranchindex20, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex21, std::array<u64,3>{v_c30, v_c34, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex22, std::array<u64,3>{v_c31, v_c15, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex23, std::array<u64,2>{v_c16, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex24, std::array<u64,3>{v_c17, v_c30, 0})) return;
          slog::join_probe<10,9>($sup5638x98x0x0x1index25, std::array<u64,10>{v_c17, v_c14, v_c15, v_c16, v_c34, v_c32, v_c31, v_c33, v_c8, 0}, [&](const std::array<u64,10>& m76) {
            u64 v_c36 = m76[9];
            if (!slog::exists_probe<3,3>(mp_mskindex26, std::array<u64,3>{v_c31, v_c15, v_c36})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex27, std::array<u64,2>{v_c36, v_c16})) return;
            slog::join_probe<5,4>(mbranchindex28, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0}, [&](const std::array<u64,5>& m77) {
              u64 v_c37 = m77[4];
              slog::join_probe<3,3>(mp_unionindex29, std::array<u64,3>{v_c34, v_c37, v_c30}, [&](const std::array<u64,3>& m78) {
                slog::join_probe<3,3>(mp_mskindex30, std::array<u64,3>{v_c31, v_c15, v_c36}, [&](const std::array<u64,3>& m79) {
                  slog::join_probe<2,2>(mp_msk_ansindex31, std::array<u64,2>{v_c36, v_c16}, [&](const std::array<u64,2>& m80) {
                    slog::join_probe_old<3,2>(mp_unionindex32, mp_uniondelta34, std::array<u64,3>{v_c17, v_c30, 0}, [&](const std::array<u64,3>& m81) {
                      u64 v_c38 = m81[2];
                      slog::join_probe<2,1>(mp_union_ansindex33, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m82) {
                        u64 v_c39 = m82[1];
                        u64 v_c40 = _prim_band(db, v_c31, v_c15);
                        if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c41 = _prim_gt(db, v_c40, v_c29);
                        if (v_c41 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c41) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c34, v_c39, v_c14, v_c15, v_c16});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c14, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask35* _cont = new ReadTask35(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask35(db,b), false);
  // (crule (pre) (scan mp_union __t4nmW316 __t9YDI315 __t5rgl314) (body (join mbranch (0 1 2 3 4) 1 __t5rgl314 p m u v) (join mbranch (0 1 2 3 4) 3 __t9YDI315 p m l r)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t4nmW316 l m p r u v)) map.slog:94 #f)
  class ReadTask86 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex84;  slog::Index** mbranchindex85;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord87({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel88 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel88->getIndex(ord87, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord89({0, 1, 2, 3, 4});
      slog::Relation* readrel90 = db->getRelation("mbranch");
      mbranchindex84 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({0, 1, 2, 3, 4});
      slog::Relation* readrel92 = db->getRelation("mbranch");
      mbranchindex85 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask86(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        slog::join_probe<5,1>(mbranchindex84, std::array<u64,5>{v_c44, 0, 0, 0, 0}, [&](const std::array<u64,5>& m93) {
          u64 v_c16 = m93[1]; u64 v_c15 = m93[2]; u64 v_c33 = m93[3]; u64 v_c8 = m93[4];
          slog::join_probe<5,3>(mbranchindex85, std::array<u64,5>{v_c43, v_c16, v_c15, 0, 0}, [&](const std::array<u64,5>& m94) {
            u64 v_c14 = m94[3]; u64 v_c17 = m94[4];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c42, v_c14, v_c15, v_c16, v_c17, v_c33, v_c8}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask86* _cont = new ReadTask86(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask86(db,b), false);
  // (crule (pre (let __tconst4J6Y274 const6b86b273ff34fce19d6b804e)) (scan mp_union __t8s9M273 __t7G5n272 __t04rT271) (body (join mbranch (0 1 2 3 4) 1 __t04rT271 q n u v) (join mbranch (0 1 2 3 4) 1 __t7G5n272 p m l r) (cmp lt m n) (let __t2pJK275 (band p n)) (cmp lt __t2pJK275 __tconst4J6Y274)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t8s9M273 u l m n p q r v)) map.slog:105 #f)
  class ReadTask97 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex95;  slog::Index** mbranchindex96;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord98({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel99 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel99->getIndex(ord98, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord100({0, 1, 2, 3, 4});
      slog::Relation* readrel101 = db->getRelation("mbranch");
      mbranchindex95 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1, 2, 3, 4});
      slog::Relation* readrel103 = db->getRelation("mbranch");
      mbranchindex96 = readrel103->getIndex(ord102, false);
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c46 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c48 = _t[2];
        slog::join_probe<5,1>(mbranchindex95, std::array<u64,5>{v_c48, 0, 0, 0, 0}, [&](const std::array<u64,5>& m104) {
          u64 v_c31 = m104[1]; u64 v_c32 = m104[2]; u64 v_c33 = m104[3]; u64 v_c8 = m104[4];
          slog::join_probe<5,1>(mbranchindex96, std::array<u64,5>{v_c47, 0, 0, 0, 0}, [&](const std::array<u64,5>& m105) {
            u64 v_c16 = m105[1]; u64 v_c15 = m105[2]; u64 v_c14 = m105[3]; u64 v_c17 = m105[4];
            u64 v_c49 = _prim_lt(db, v_c15, v_c32);
            if (v_c49 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c49) return;
            u64 v_c50 = _prim_band(db, v_c16, v_c32);
            if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c51 = _prim_lt(db, v_c50, v_c45);
            if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c51) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c46, v_c33, v_c14, v_c15, v_c32, v_c16, v_c31, v_c17, v_c8}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask97* _cont = new ReadTask97(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask97(db,b), false);
  // (crule (pre (let __tconst9i9x873 constd01925b37634a1a9d24159d8)) (scan mp_put __t6LFp12 __t8CAD11 k v) (body (join _enum (0 1) 2 __t8CAD11 __tconst9i9x873)) (head (emit-temp temp8fvz1067 __t6LFp12 k v) (mkstruct mleaf (1 2 0) __t2ggE10 k v)) map.slog:37 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8fvz1067");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord110({0, 1});
      slog::Relation* readrel111 = db->getRelation("_enum");
      _enumindex108 = readrel111->getIndex(ord110, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c8 = _t[3];
        slog::join_probe<2,2>(_enumindex108, std::array<u64,2>{v_c54, v_c52}, [&](const std::array<u64,2>& m112) {
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c53, v_c6, v_c8});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c6, v_c8}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:37", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), false);
  // (crule (pre (let __tconst0f4L40 const7902699be42c8a8e46fbbb45)) (scan canon m) (body) (head (mkstruct mp_has0 (1 2 0) __9DyB850 m __tconst0f4L40)) mp_basic.slog:20 #f)
  class ReadTask113 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c55}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:20", "delta:canon", _fires);
  
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
  // (crule (pre (let __tconst0j5f331 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t3IIE330 __t5kZo329 k) (body (join mbranch (0 1 2 3 4) 1 __t5kZo329 p m l r) (let __t1GZO332 (band k m)) (cmp lt __t1GZO332 __tconst0j5f331)) (head (emit $sup5638x60x0x0x0 (4 2 3 5 0 1) p l m r __t3IIE330 k)) map.slog:61 #f)
  class ReadTask115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord116({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel117 = db->getRelation("$sup5638x60x0x0x0");
      head_index[0] = readrel117->getIndex(ord116, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord118({0, 1, 2, 3, 4});
      slog::Relation* readrel119 = db->getRelation("mbranch");
      mbranchindex114 = readrel119->getIndex(ord118, false);
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<5,1>(mbranchindex114, std::array<u64,5>{v_c58, 0, 0, 0, 0}, [&](const std::array<u64,5>& m120) {
          u64 v_c16 = m120[1]; u64 v_c15 = m120[2]; u64 v_c14 = m120[3]; u64 v_c17 = m120[4];
          u64 v_c59 = _prim_band(db, v_c6, v_c15);
          if (v_c59 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          u64 v_c60 = _prim_lt(db, v_c59, v_c56);
          if (v_c60 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          if (!v_c60) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c16, v_c14, v_c15, v_c17, v_c57, v_c6}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_has0", _fires);
  
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
  // (crule (pre) (scan mp_join __t2ANq21 p __t50JB19 q __t6Pc120) (body (neq p q) (exists mbranch (0 1 2 3 4) 2 __t50JB19 p) (exists mbranch (0 1 2 3 4) 2 __t6Pc120 q) (exists mp_join_ans (0 1) 1 __t2ANq21) (join mp_union (1 2 0) 2 __t50JB19 __t6Pc120 __t9xCI18) (join mbranch (0 1 2 3 4) 2 __t50JB19 p m l r) (join mbranch (0 1 2 3 4) 3 __t6Pc120 q m u v) (join mp_join_ans (0 1) 1 __t2ANq21 res)) (head (emit mp_union_ans (0 1) __t9xCI18 res)) map.slog:114 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex122;  slog::Index** mbranchindex123;  slog::Index** mp_join_ansindex124;  slog::Index** mp_unionindex125;  slog::Index** mbranchindex126;  slog::Index** mbranchindex127;  slog::Index** mp_join_ansindex128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("mp_union_ans");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord132({0, 1, 2, 3, 4});
      slog::Relation* readrel133 = db->getRelation("mbranch");
      mbranchindex122 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1, 2, 3, 4});
      slog::Relation* readrel135 = db->getRelation("mbranch");
      mbranchindex123 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1});
      slog::Relation* readrel137 = db->getRelation("mp_join_ans");
      mp_join_ansindex124 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("mp_union");
      mp_unionindex125 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1, 2, 3, 4});
      slog::Relation* readrel141 = db->getRelation("mbranch");
      mbranchindex126 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1, 2, 3, 4});
      slog::Relation* readrel143 = db->getRelation("mbranch");
      mbranchindex127 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("mp_join_ans");
      mp_join_ansindex128 = readrel145->getIndex(ord144, false);
  
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
        u64 v_c61 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c62 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c63 = _t[4];
        if (v_c16 == v_c31) return;
        if (!slog::exists_probe<5,2>(mbranchindex122, std::array<u64,5>{v_c62, v_c16, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex123, std::array<u64,5>{v_c63, v_c31, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex124, std::array<u64,2>{v_c61, 0})) return;
        slog::join_probe<3,2>(mp_unionindex125, std::array<u64,3>{v_c62, v_c63, 0}, [&](const std::array<u64,3>& m146) {
          u64 v_c64 = m146[2];
          slog::join_probe<5,2>(mbranchindex126, std::array<u64,5>{v_c62, v_c16, 0, 0, 0}, [&](const std::array<u64,5>& m147) {
            u64 v_c15 = m147[2]; u64 v_c14 = m147[3]; u64 v_c17 = m147[4];
            slog::join_probe<5,3>(mbranchindex127, std::array<u64,5>{v_c63, v_c31, v_c15, 0, 0}, [&](const std::array<u64,5>& m148) {
              u64 v_c33 = m148[3]; u64 v_c8 = m148[4];
              slog::join_probe<2,1>(mp_join_ansindex128, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m149) {
                u64 v_c65 = m149[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c65}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_join", _fires);
  
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
  // (crule (pre) (scan mp_union __t2xZH196 __t4U3g195 t) (body (join mleaf (0 1 2) 1 __t4U3g195 k v)) (head (mkstruct mp_put (1 2 3 0) __6ToP809 t k v)) map.slog:92 #f)
  class ReadTask151 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex150;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord152({0, 1, 2});
      slog::Relation* readrel153 = db->getRelation("mleaf");
      mleafindex150 = readrel153->getIndex(ord152, false);
  
    }
    ReadTask151(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[2];
        slog::join_probe<3,1>(mleafindex150, std::array<u64,3>{v_c67, 0, 0}, [&](const std::array<u64,3>& m154) {
          u64 v_c6 = m154[1]; u64 v_c8 = m154[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c7, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask151* _cont = new ReadTask151(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask151(db,b), false);
  // (crule (pre (let __tconst0uEk118 const5feceb66ffc86f38d952786c)) (scan mp_del __t7lZr117 __t52bR116 k) (body (join mbranch (0 1 2 3 4) 1 __t52bR116 p m l r) (let __t2JJZ119 (band k m)) (cmp gt __t2JJZ119 __tconst0uEk118)) (head (emit $sup5638x84x0x0x0 (4 2 3 5 0 1) p l m r __t7lZr117 k)) map.slog:85 #f)
  class ReadTask156 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex155;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord157({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel158 = db->getRelation("$sup5638x84x0x0x0");
      head_index[0] = readrel158->getIndex(ord157, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord159({0, 1, 2, 3, 4});
      slog::Relation* readrel160 = db->getRelation("mbranch");
      mbranchindex155 = readrel160->getIndex(ord159, false);
  
    }
    ReadTask156(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<5,1>(mbranchindex155, std::array<u64,5>{v_c70, 0, 0, 0, 0}, [&](const std::array<u64,5>& m161) {
          u64 v_c16 = m161[1]; u64 v_c15 = m161[2]; u64 v_c14 = m161[3]; u64 v_c17 = m161[4];
          u64 v_c71 = _prim_band(db, v_c6, v_c15);
          if (v_c71 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          u64 v_c72 = _prim_gt(db, v_c71, v_c68);
          if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          if (!v_c72) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c16, v_c14, v_c15, v_c17, v_c69, v_c6}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
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
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_msk __t8rat400 p0 __v1) (body (exists mp_hsb_ans (1 0) 1 __v1) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x29x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join mp_msk_ans (0 1) 1 __t8rat400 __v2) (join mp_hsb_ans (1 0) 1 __v1 __t1lh0397) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t1lh0397) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t1lh0397) (exists mp_hsb_ans (0 1) 1 __t1lh0397) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v3) (join $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t1lh0397 __v1 __v3 p0 __t4lFL393 dup0XDZ1075 dup8FhK1076 __v0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join mp_hsb_ans (0 1) 2 __t1lh0397 __v0) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex163;  slog::Index** $sup5638x29x0x0x2index164;  slog::Index** $sup5638x29x0x0x1index165;  slog::Index** $sup5638x29x0x0x0index166;  slog::Index** mp_joinindex167;  slog::Index** mp_msk_ansindex168;  slog::Index** mp_hsb_ansindex169;  slog::Index** $sup5638x29x0x0x2index170;  slog::Index** $sup5638x29x0x0x1index171;  slog::Index** mp_hsb_ansindex172;  slog::Index** mp_hsb_ansindex173;  slog::Index** $sup5638x29x0x0x2index174;  slog::Index** $sup5638x29x0x0x1index175;  slog::Index** $sup5638x29x0x0x0index176;  slog::Index** mp_joinindex177;  slog::Index** mp_hsb_ansindex178;  slog::Index** mp_hsbindex179;  slog::Index** mp_joindelta180;  slog::Index** mp_hsbdelta181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex163 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel186 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index164 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel188 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index165 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0, 2, 3, 4});
      slog::Relation* readrel190 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index166 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 3, 4, 0});
      slog::Relation* readrel192 = db->getRelation("mp_join");
      mp_joinindex167 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex168 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 0});
      slog::Relation* readrel196 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex169 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel198 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index170 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel200 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index171 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1});
      slog::Relation* readrel202 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex172 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex173 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel206 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index174 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel208 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index175 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 0, 2, 3, 4});
      slog::Relation* readrel210 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index176 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 3, 4, 0});
      slog::Relation* readrel212 = db->getRelation("mp_join");
      mp_joinindex177 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 3, 4, 0});
      slog::Relation* readrel214 = db->getRelation("mp_join");
      mp_joindelta180 = readrel214->getIndex(ord213, true);
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex178 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("mp_hsb");
      mp_hsbindex179 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("mp_hsb");
      mp_hsbdelta181 = readrel220->getIndex(ord219, true);
  
    }
    ReadTask182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        u64 v_c75 = _t[1];
        u64 v_c76 = _t[2];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex163, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index164, std::array<u64,11>{v_c76, v_c75, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index165, std::array<u64,7>{v_c75, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup5638x29x0x0x0index166, std::array<u64,5>{v_c75, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex167, std::array<u64,5>{v_c75, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex168, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m221) {
          u64 v_c77 = m221[1];
          slog::join_probe<2,1>(mp_hsb_ansindex169, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m222) {
            u64 v_c78 = m222[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index170, std::array<u64,11>{v_c76, v_c75, v_c78, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index171, std::array<u64,7>{v_c75, v_c78, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex172, std::array<u64,2>{v_c78, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex173, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m223) {
              u64 v_c79 = m223[1];
              slog::join_probe<11,4>($sup5638x29x0x0x2index174, std::array<u64,11>{v_c78, v_c76, v_c79, v_c75, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m224) {
                u64 v_c80 = m224[4]; u64 v_c81 = m224[5]; u64 v_c82 = m224[6]; u64 v_c39 = m224[7]; u64 v_c83 = m224[8]; u64 v_c84 = m224[9]; u64 v_c85 = m224[10];
                if (v_c78 != v_c82) return;
                if (v_c78 != v_c81) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index175, std::array<u64,7>{v_c80, v_c75, v_c83, v_c84, v_c85, v_c78, v_c39}, [&](const std::array<u64,7>& m225) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index176, std::array<u64,5>{v_c75, v_c80, v_c83, v_c84, v_c85}, [&](const std::array<u64,5>& m226) {
                    slog::join_probe_old<5,5>(mp_joinindex177, mp_joindelta180, std::array<u64,5>{v_c75, v_c84, v_c83, v_c85, v_c80}, [&](const std::array<u64,5>& m227) {
                      slog::join_probe<2,2>(mp_hsb_ansindex178, std::array<u64,2>{v_c78, v_c39}, [&](const std::array<u64,2>& m228) {
                        u64 v_c86 = _prim_bxor(db, v_c75, v_c83);
                        if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex179, mp_hsbdelta181, std::array<u64,2>{v_c78, v_c86}, [&](const std::array<u64,2>& m229) {
                          u64 v_c87 = _prim_band(db, v_c75, v_c39);
                          if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c88 = _prim_gt(db, v_c87, v_c73);
                          if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c88) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c80, v_c77, v_c79, v_c84, v_c85});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c77, v_c79, v_c85, v_c84}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_msk", _fires);
  
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
  // (crule (pre) (scan mp_join __t9vyw431 k __t9k3L430 p __t51uB429) (body (exists mp_put (1 2 0 3) 2 __t51uB429 k) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 3 k p __t51uB429) (exists mbranch (0 1 2 3 4) 2 __t51uB429 p) (exists mp_msk (1 2 0) 1 k) (exists mp_join_ans (0 1) 1 __t9vyw431) (join mleaf (0 1 2) 2 __t9k3L430 k v) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 4 k p __t51uB429 v) (join mp_put (1 2 3 0) 3 __t51uB429 k v __t5vsG428) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 5 k v __t5vsG428 __t51uB429 p l m r) (join mbranch (1 2 3 4 0) 5 p m l r __t51uB429) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex231;  slog::Index** $sup5638x44x0x0x0index232;  slog::Index** mbranchindex233;  slog::Index** mp_mskindex234;  slog::Index** mp_join_ansindex235;  slog::Index** mleafindex236;  slog::Index** $sup5638x44x0x0x0index237;  slog::Index** mp_putindex238;  slog::Index** $sup5638x44x0x0x0index239;  slog::Index** mbranchindex240;  slog::Index** mp_mskindex241;  slog::Index** mp_msk_ansindex242;  slog::Index** mp_join_ansindex243;  slog::Index** mp_mskdelta244;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord246({0, 1});
      slog::Relation* readrel247 = db->getRelation("mp_put_ans");
      head_index[0] = readrel247->getIndex(ord246, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord248({1, 2, 0, 3});
      slog::Relation* readrel249 = db->getRelation("mp_put");
      mp_putindex231 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel251 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index232 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1, 2, 3, 4});
      slog::Relation* readrel253 = db->getRelation("mbranch");
      mbranchindex233 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("mp_msk");
      mp_mskindex234 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("mp_join_ans");
      mp_join_ansindex235 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({0, 1, 2});
      slog::Relation* readrel259 = db->getRelation("mleaf");
      mleafindex236 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel261 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index237 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 2, 3, 0});
      slog::Relation* readrel263 = db->getRelation("mp_put");
      mp_putindex238 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel265 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index239 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 3, 4, 0});
      slog::Relation* readrel267 = db->getRelation("mbranch");
      mbranchindex240 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("mp_msk");
      mp_mskindex241 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 2, 0});
      slog::Relation* readrel271 = db->getRelation("mp_msk");
      mp_mskdelta244 = readrel271->getIndex(ord270, true);
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex242 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 1});
      slog::Relation* readrel275 = db->getRelation("mp_join_ans");
      mp_join_ansindex243 = readrel275->getIndex(ord274, false);
  
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
        u64 v_c89 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c90 = _t[2];
        u64 v_c16 = _t[3];
        u64 v_c91 = _t[4];
        if (!slog::exists_probe<4,2>(mp_putindex231, std::array<u64,4>{v_c91, v_c6, 0, 0})) return;
        if (!slog::exists_probe<8,3>($sup5638x44x0x0x0index232, std::array<u64,8>{v_c6, v_c16, v_c91, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex233, std::array<u64,5>{v_c91, v_c16, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex234, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex235, std::array<u64,2>{v_c89, 0})) return;
        slog::join_probe<3,2>(mleafindex236, std::array<u64,3>{v_c90, v_c6, 0}, [&](const std::array<u64,3>& m276) {
          u64 v_c8 = m276[2];
          if (!slog::exists_probe<8,4>($sup5638x44x0x0x0index237, std::array<u64,8>{v_c6, v_c16, v_c91, v_c8, 0, 0, 0, 0})) return;
          slog::join_probe<4,3>(mp_putindex238, std::array<u64,4>{v_c91, v_c6, v_c8, 0}, [&](const std::array<u64,4>& m277) {
            u64 v_c92 = m277[3];
            slog::join_probe<8,5>($sup5638x44x0x0x0index239, std::array<u64,8>{v_c6, v_c8, v_c92, v_c91, v_c16, 0, 0, 0}, [&](const std::array<u64,8>& m278) {
              u64 v_c14 = m278[5]; u64 v_c15 = m278[6]; u64 v_c17 = m278[7];
              slog::join_probe<5,5>(mbranchindex240, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, v_c91}, [&](const std::array<u64,5>& m279) {
                slog::join_probe_old<3,2>(mp_mskindex241, mp_mskdelta244, std::array<u64,3>{v_c6, v_c15, 0}, [&](const std::array<u64,3>& m280) {
                  u64 v_c93 = m280[2];
                  slog::join_probe<2,1>(mp_msk_ansindex242, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m281) {
                    u64 v_c39 = m281[1];
                    if (v_c16 == v_c39) return;
                    slog::join_probe<2,1>(mp_join_ansindex243, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m282) {
                      u64 v_c65 = m282[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c92, v_c65}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_join", _fires);
  
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
  // (crule (pre) (scan mp_union __t9rnk262 __t2wpn261 __t5rXw260) (body (exists $sup5638x93x0x0x0 (0 1 2 3 4 5 6) 1 __t9rnk262) (join mbranch (0 1 2 3 4) 1 __t5rXw260 p m u v) (exists mbranch (0 1 2 3 4) 3 __t2wpn261 p m) (exists mp_union (2 0 1) 1 u) (exists mp_union (2 0 1) 1 v) (join $sup5638x93x0x0x0 (2 3 5 6 0 1 4) 5 m p u v __t9rnk262 l r) (join mbranch (1 2 3 4 0) 5 p m l r __t2wpn261) (exists mp_union (1 2 0) 2 r v) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t2Oaj263) (exists mp_union_ans (0 1) 1 __t2Oaj263) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (exists mp_union_ans (0 1) 1 __t0Kdo264) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask299 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index283;  slog::Index** mbranchindex284;  slog::Index** mbranchindex285;  slog::Index** mp_unionindex286;  slog::Index** mp_unionindex287;  slog::Index** $sup5638x93x0x0x0index288;  slog::Index** mbranchindex289;  slog::Index** mp_unionindex290;  slog::Index** mp_unionindex291;  slog::Index** mp_union_ansindex292;  slog::Index** mp_unionindex293;  slog::Index** mp_union_ansindex294;  slog::Index** mp_union_ansindex295;  slog::Index** mp_union_ansindex296;  slog::Index** mp_uniondelta297;  slog::Index** mp_uniondelta298;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord300({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel301 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index283 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1, 2, 3, 4});
      slog::Relation* readrel303 = db->getRelation("mbranch");
      mbranchindex284 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1, 2, 3, 4});
      slog::Relation* readrel305 = db->getRelation("mbranch");
      mbranchindex285 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({2, 0, 1});
      slog::Relation* readrel307 = db->getRelation("mp_union");
      mp_unionindex286 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({2, 0, 1});
      slog::Relation* readrel309 = db->getRelation("mp_union");
      mp_unionindex287 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel311 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index288 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("mbranch");
      mbranchindex289 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("mp_union");
      mp_unionindex290 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 2, 0});
      slog::Relation* readrel317 = db->getRelation("mp_union");
      mp_unionindex291 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("mp_union");
      mp_uniondelta297 = readrel319->getIndex(ord318, true);
      std::vector<u16> ord320({0, 1});
      slog::Relation* readrel321 = db->getRelation("mp_union_ans");
      mp_union_ansindex292 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("mp_union");
      mp_unionindex293 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("mp_union");
      mp_uniondelta298 = readrel325->getIndex(ord324, true);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("mp_union_ans");
      mp_union_ansindex294 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("mp_union_ans");
      mp_union_ansindex295 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 1});
      slog::Relation* readrel331 = db->getRelation("mp_union_ans");
      mp_union_ansindex296 = readrel331->getIndex(ord330, false);
  
    }
    ReadTask299(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c94 = _t[0];
        u64 v_c95 = _t[1];
        u64 v_c96 = _t[2];
        if (!slog::exists_probe<7,1>($sup5638x93x0x0x0index283, std::array<u64,7>{v_c94, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(mbranchindex284, std::array<u64,5>{v_c96, 0, 0, 0, 0}, [&](const std::array<u64,5>& m332) {
          u64 v_c16 = m332[1]; u64 v_c15 = m332[2]; u64 v_c33 = m332[3]; u64 v_c8 = m332[4];
          if (!slog::exists_probe<5,3>(mbranchindex285, std::array<u64,5>{v_c95, v_c16, v_c15, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex286, std::array<u64,3>{v_c33, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex287, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x93x0x0x0index288, std::array<u64,7>{v_c15, v_c16, v_c33, v_c8, v_c94, 0, 0}, [&](const std::array<u64,7>& m333) {
            u64 v_c14 = m333[5]; u64 v_c17 = m333[6];
            slog::join_probe<5,5>(mbranchindex289, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, v_c95}, [&](const std::array<u64,5>& m334) {
              if (!slog::exists_probe<3,2>(mp_unionindex290, std::array<u64,3>{v_c17, v_c8, 0})) return;
              slog::join_probe_old<3,2>(mp_unionindex291, mp_uniondelta297, std::array<u64,3>{v_c14, v_c33, 0}, [&](const std::array<u64,3>& m335) {
                u64 v_c97 = m335[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex292, std::array<u64,2>{v_c97, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex293, mp_uniondelta298, std::array<u64,3>{v_c17, v_c8, 0}, [&](const std::array<u64,3>& m336) {
                  u64 v_c98 = m336[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex294, std::array<u64,2>{v_c98, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex295, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m337) {
                    u64 v_c39 = m337[1];
                    slog::join_probe<2,1>(mp_union_ansindex296, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m338) {
                      u64 v_c76 = m338[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c94, v_c39, v_c76, v_c15, v_c16});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c39, v_c76}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask299* _cont = new ReadTask299(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask299(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan $sup5638x62x0x0x0 __t68rk111 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t68rk111 k) (exists mp_has0 (1 2 0) 2 r k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t032L110) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t68rk111 k __t032L110) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t6Hok114) (exists mp_has0_ans (0 1) 1 __t6Hok114) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9QiO115) (join mp_msk_ans (0 1) 2 __t9QiO115 p) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask354 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index339;  slog::Index** mp_has0index340;  slog::Index** mp_mskindex341;  slog::Index** mp_msk_ansindex342;  slog::Index** mbranchindex343;  slog::Index** mp_has0index344;  slog::Index** mp_has0index345;  slog::Index** mp_has0_ansindex346;  slog::Index** mp_mskindex347;  slog::Index** mp_msk_ansindex348;  slog::Index** mp_has0_ansindex349;  slog::Index** mbranchdelta350;  slog::Index** mp_has0delta351;  slog::Index** mp_has0delta352;  slog::Index** mp_mskdelta353;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel356->getIndex(ord355, false);
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord357({0, 2, 1});
      slog::Relation* readrel358 = db->getRelation("mp_has0");
      mp_has0index339 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 2, 0});
      slog::Relation* readrel360 = db->getRelation("mp_has0");
      mp_has0index340 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("mp_msk");
      mp_mskindex341 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex342 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 3, 4, 0});
      slog::Relation* readrel366 = db->getRelation("mbranch");
      mbranchindex343 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 3, 4, 0});
      slog::Relation* readrel368 = db->getRelation("mbranch");
      mbranchdelta350 = readrel368->getIndex(ord367, true);
      std::vector<u16> ord369({0, 2, 1});
      slog::Relation* readrel370 = db->getRelation("mp_has0");
      mp_has0index344 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 2, 1});
      slog::Relation* readrel372 = db->getRelation("mp_has0");
      mp_has0delta351 = readrel372->getIndex(ord371, true);
      std::vector<u16> ord373({1, 2, 0});
      slog::Relation* readrel374 = db->getRelation("mp_has0");
      mp_has0index345 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 2, 0});
      slog::Relation* readrel376 = db->getRelation("mp_has0");
      mp_has0delta352 = readrel376->getIndex(ord375, true);
      std::vector<u16> ord377({0, 1});
      slog::Relation* readrel378 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex346 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 2, 0});
      slog::Relation* readrel380 = db->getRelation("mp_msk");
      mp_mskindex347 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 2, 0});
      slog::Relation* readrel382 = db->getRelation("mp_msk");
      mp_mskdelta353 = readrel382->getIndex(ord381, true);
      std::vector<u16> ord383({0, 1});
      slog::Relation* readrel384 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex348 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({0, 1});
      slog::Relation* readrel386 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex349 = readrel386->getIndex(ord385, false);
  
    }
    ReadTask354(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c17 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index339, std::array<u64,3>{v_c100, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index340, std::array<u64,3>{v_c17, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex341, std::array<u64,3>{v_c6, v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex342, std::array<u64,2>{v_c16, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex343, mbranchdelta350, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0}, [&](const std::array<u64,5>& m387) {
          u64 v_c101 = m387[4];
          slog::join_probe_old<3,3>(mp_has0index344, mp_has0delta351, std::array<u64,3>{v_c100, v_c6, v_c101}, [&](const std::array<u64,3>& m388) {
            slog::join_probe_old<3,2>(mp_has0index345, mp_has0delta352, std::array<u64,3>{v_c17, v_c6, 0}, [&](const std::array<u64,3>& m389) {
              u64 v_c102 = m389[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex346, std::array<u64,2>{v_c102, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex347, mp_mskdelta353, std::array<u64,3>{v_c6, v_c15, 0}, [&](const std::array<u64,3>& m390) {
                u64 v_c103 = m390[2];
                slog::join_probe<2,2>(mp_msk_ansindex348, std::array<u64,2>{v_c103, v_c16}, [&](const std::array<u64,2>& m391) {
                  slog::join_probe<2,1>(mp_has0_ansindex349, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m392) {
                    u64 v_c104 = m392[1];
                    u64 v_c105 = _prim_band(db, v_c6, v_c15);
                    if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c106 = _prim_gt(db, v_c105, v_c99);
                    if (v_c106 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c106) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c100, v_c104}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask354* _cont = new ReadTask354(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask354(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t1mkY280 (bxor p0 p1))) (head (emit-temp temp1Yd51020 __t1mkY280)) map.slog:26 #f)
  class ReadTask394 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1Yd51020");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
  
    }
    ReadTask394(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c107 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c75 = _t[3];
        u64 v_c83 = _t[4];
        u64 v_c84 = _t[5];
        u64 v_c85 = _t[6];
        u64 v_c108 = _prim_bxor(db, v_c75, v_c83);
        if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c108});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask394* _cont = new ReadTask394(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask394(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mp_msk __t8lnB287 k m) (body (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_msk_ans (0 1) 1 __t8lnB287) (join $sup5638x42x0x0x1 (1 2 4 5 0 3 6 7) 3 __t8lnB287 k m p __t0ekw284 l r v) (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t0ekw284 k v) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join mbranch (1 2 3 4 0) 4 p m l r __t07OG283) (join mp_put (1 2 0 3) 4 __t07OG283 k __t0ekw284 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask410 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index395;  slog::Index** mbranchindex396;  slog::Index** mp_putindex397;  slog::Index** mp_msk_ansindex398;  slog::Index** $sup5638x42x0x0x1index399;  slog::Index** $sup5638x42x0x0x0index400;  slog::Index** mp_putindex401;  slog::Index** mp_putindex402;  slog::Index** mp_msk_ansindex403;  slog::Index** mbranchindex404;  slog::Index** mp_putindex405;  slog::Index** mp_putindex406;  slog::Index** mp_msk_ansindex407;  slog::Index** mp_put_ansindex408;  slog::Index** mp_putdelta409;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord411({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel412 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index395 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({2, 0, 1, 3, 4});
      slog::Relation* readrel414 = db->getRelation("mbranch");
      mbranchindex396 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({2, 3, 0, 1});
      slog::Relation* readrel416 = db->getRelation("mp_put");
      mp_putindex397 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1});
      slog::Relation* readrel418 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex398 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel420 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index399 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel422 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index400 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({2, 3, 0, 1});
      slog::Relation* readrel424 = db->getRelation("mp_put");
      mp_putindex401 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 2, 3, 0});
      slog::Relation* readrel426 = db->getRelation("mp_put");
      mp_putindex402 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex403 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 3, 4, 0});
      slog::Relation* readrel430 = db->getRelation("mbranch");
      mbranchindex404 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({1, 2, 0, 3});
      slog::Relation* readrel432 = db->getRelation("mp_put");
      mp_putindex405 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 3, 0});
      slog::Relation* readrel434 = db->getRelation("mp_put");
      mp_putindex406 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 3, 0});
      slog::Relation* readrel436 = db->getRelation("mp_put");
      mp_putdelta409 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex407 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("mp_put_ans");
      mp_put_ansindex408 = readrel440->getIndex(ord439, false);
  
    }
    ReadTask410(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c15 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x42x0x0x0index395, std::array<u64,7>{v_c6, v_c15, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex396, std::array<u64,5>{v_c15, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex397, std::array<u64,4>{v_c6, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex398, std::array<u64,2>{v_c110, 0})) return;
        slog::join_probe<8,3>($sup5638x42x0x0x1index399, std::array<u64,8>{v_c110, v_c6, v_c15, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m441) {
          u64 v_c16 = m441[3]; u64 v_c111 = m441[4]; u64 v_c14 = m441[5]; u64 v_c17 = m441[6]; u64 v_c8 = m441[7];
          slog::join_probe<7,7>($sup5638x42x0x0x0index400, std::array<u64,7>{v_c16, v_c14, v_c15, v_c17, v_c111, v_c6, v_c8}, [&](const std::array<u64,7>& m442) {
            if (!slog::exists_probe<4,3>(mp_putindex401, std::array<u64,4>{v_c6, v_c8, v_c111, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex402, std::array<u64,4>{v_c17, v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex403, std::array<u64,2>{v_c110, v_c16})) return;
            slog::join_probe<5,4>(mbranchindex404, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0}, [&](const std::array<u64,5>& m443) {
              u64 v_c112 = m443[4];
              slog::join_probe<4,4>(mp_putindex405, std::array<u64,4>{v_c112, v_c6, v_c111, v_c8}, [&](const std::array<u64,4>& m444) {
                slog::join_probe_old<4,3>(mp_putindex406, mp_putdelta409, std::array<u64,4>{v_c17, v_c6, v_c8, 0}, [&](const std::array<u64,4>& m445) {
                  u64 v_c113 = m445[3];
                  slog::join_probe<2,2>(mp_msk_ansindex407, std::array<u64,2>{v_c110, v_c16}, [&](const std::array<u64,2>& m446) {
                    slog::join_probe<2,1>(mp_put_ansindex408, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m447) {
                      u64 v_c39 = m447[1];
                      u64 v_c114 = _prim_band(db, v_c6, v_c15);
                      if (v_c114 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c115 = _prim_gt(db, v_c114, v_c109);
                      if (v_c115 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c115) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c111, v_c39, v_c14, v_c15, v_c16});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c14, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask410* _cont = new ReadTask410(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask410(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mbranch __t39oH43 p m l r) (body (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 4 l m p r) (exists mp_union (1 2 0) 1 __t39oH43) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 l) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t0mSQ44 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t0mSQ44 __t39oH43) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t0mSQ44 n q u v __t0xN947) (exists mp_msk (1 2 0) 3 q m __t0xN947) (exists mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t499t48) (join-old mp_union (0 1 2) 3 (0 1 2) __t0mSQ44 __t39oH43 __t499t48) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask471 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index449;  slog::Index** mp_unionindex450;  slog::Index** mp_mskindex451;  slog::Index** mp_msk_ansindex452;  slog::Index** mp_unionindex453;  slog::Index** $sup5638x95x0x0x0index454;  slog::Index** mbranchindex455;  slog::Index** mp_unionindex456;  slog::Index** mp_mskindex457;  slog::Index** $sup5638x95x0x0x1index458;  slog::Index** mp_mskindex459;  slog::Index** mp_msk_ansindex460;  slog::Index** mbranchindex461;  slog::Index** mp_unionindex462;  slog::Index** mp_mskindex463;  slog::Index** mp_msk_ansindex464;  slog::Index** mp_unionindex465;  slog::Index** mp_union_ansindex466;  slog::Index** mbranchdelta467;  slog::Index** mp_uniondelta468;  slog::Index** mp_mskdelta469;  slog::Index** mp_uniondelta470;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord472({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel473 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index449 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("mp_union");
      mp_unionindex450 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({2, 0, 1});
      slog::Relation* readrel477 = db->getRelation("mp_msk");
      mp_mskindex451 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0});
      slog::Relation* readrel479 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex452 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("mp_union");
      mp_unionindex453 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel483 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index454 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 3, 4, 0});
      slog::Relation* readrel485 = db->getRelation("mbranch");
      mbranchindex455 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 1, 2});
      slog::Relation* readrel487 = db->getRelation("mp_union");
      mp_unionindex456 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("mp_msk");
      mp_mskindex457 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel491 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index458 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("mp_msk");
      mp_mskindex459 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex460 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({1, 2, 3, 4, 0});
      slog::Relation* readrel497 = db->getRelation("mbranch");
      mbranchindex461 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 2, 3, 4, 0});
      slog::Relation* readrel499 = db->getRelation("mbranch");
      mbranchdelta467 = readrel499->getIndex(ord498, true);
      std::vector<u16> ord500({0, 1, 2});
      slog::Relation* readrel501 = db->getRelation("mp_union");
      mp_unionindex462 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 1, 2});
      slog::Relation* readrel503 = db->getRelation("mp_union");
      mp_uniondelta468 = readrel503->getIndex(ord502, true);
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("mp_msk");
      mp_mskindex463 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("mp_msk");
      mp_mskdelta469 = readrel507->getIndex(ord506, true);
      std::vector<u16> ord508({0, 1});
      slog::Relation* readrel509 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex464 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 2, 0});
      slog::Relation* readrel511 = db->getRelation("mp_union");
      mp_unionindex465 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 2, 0});
      slog::Relation* readrel513 = db->getRelation("mp_union");
      mp_uniondelta470 = readrel513->getIndex(ord512, true);
      std::vector<u16> ord514({0, 1});
      slog::Relation* readrel515 = db->getRelation("mp_union_ans");
      mp_union_ansindex466 = readrel515->getIndex(ord514, false);
  
    }
    ReadTask471(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c117 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c17 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x95x0x0x1index449, std::array<u64,10>{v_c14, v_c15, v_c16, v_c17, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex450, std::array<u64,3>{v_c117, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex451, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex452, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex453, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x95x0x0x0index454, std::array<u64,9>{v_c14, v_c15, v_c16, v_c17, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m516) {
          u64 v_c118 = m516[4]; u64 v_c32 = m516[5]; u64 v_c31 = m516[6]; u64 v_c33 = m516[7]; u64 v_c8 = m516[8];
          u64 v_c119 = _prim_lt(db, v_c32, v_c15);
          if (v_c119 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c119) return;
          if (!slog::exists_probe<5,4>(mbranchindex455, std::array<u64,5>{v_c31, v_c32, v_c33, v_c8, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex456, std::array<u64,3>{v_c118, v_c117, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex457, std::array<u64,3>{v_c31, v_c15, 0})) return;
          slog::join_probe<10,9>($sup5638x95x0x0x1index458, std::array<u64,10>{v_c14, v_c15, v_c16, v_c17, v_c118, v_c32, v_c31, v_c33, v_c8, 0}, [&](const std::array<u64,10>& m518) {
            u64 v_c120 = m518[9];
            if (!slog::exists_probe<3,3>(mp_mskindex459, std::array<u64,3>{v_c31, v_c15, v_c120})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex460, std::array<u64,2>{v_c120, v_c16})) return;
            slog::join_probe_old<5,4>(mbranchindex461, mbranchdelta467, std::array<u64,5>{v_c31, v_c32, v_c33, v_c8, 0}, [&](const std::array<u64,5>& m519) {
              u64 v_c121 = m519[4];
              slog::join_probe_old<3,3>(mp_unionindex462, mp_uniondelta468, std::array<u64,3>{v_c118, v_c117, v_c121}, [&](const std::array<u64,3>& m520) {
                slog::join_probe_old<3,3>(mp_mskindex463, mp_mskdelta469, std::array<u64,3>{v_c31, v_c15, v_c120}, [&](const std::array<u64,3>& m521) {
                  slog::join_probe<2,2>(mp_msk_ansindex464, std::array<u64,2>{v_c120, v_c16}, [&](const std::array<u64,2>& m522) {
                    slog::join_probe_old<3,2>(mp_unionindex465, mp_uniondelta470, std::array<u64,3>{v_c14, v_c121, 0}, [&](const std::array<u64,3>& m523) {
                      u64 v_c122 = m523[2];
                      slog::join_probe<2,1>(mp_union_ansindex466, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m524) {
                        u64 v_c39 = m524[1];
                        u64 v_c123 = _prim_band(db, v_c31, v_c15);
                        if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c124 = _prim_lt(db, v_c123, v_c116);
                        if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c124) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c118, v_c39, v_c15, v_c16, v_c17});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c39, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask471* _cont = new ReadTask471(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask471(db,b), false);
  // (crule (pre) (scan mleaf __t9k3L430 k v) (body (exists $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t9k3L430) (exists mp_msk (1 2 0) 1 k) (join mp_put (2 3 0 1) 2 k v __t5vsG428 __t51uB429) (exists mp_join (1 4 2 0 3) 3 k __t51uB429 __t9k3L430) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 4 k v __t5vsG428 __t51uB429 p l m r) (join mbranch (1 2 3 4 0) 5 p m l r __t51uB429) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) k __t9k3L430 p __t51uB429 __t9vyw431) (exists mp_join_ans (0 1) 1 __t9vyw431) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x44x0x0x0index526;  slog::Index** mp_joinindex527;  slog::Index** mp_mskindex528;  slog::Index** mp_putindex529;  slog::Index** mp_joinindex530;  slog::Index** $sup5638x44x0x0x0index531;  slog::Index** mbranchindex532;  slog::Index** mp_mskindex533;  slog::Index** mp_joinindex534;  slog::Index** mp_join_ansindex535;  slog::Index** mp_mskindex536;  slog::Index** mp_msk_ansindex537;  slog::Index** mp_join_ansindex538;  slog::Index** mp_joindelta539;  slog::Index** mp_mskdelta540;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("mp_put_ans");
      head_index[0] = readrel543->getIndex(ord542, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord544({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel545 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index526 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 3, 4, 0});
      slog::Relation* readrel547 = db->getRelation("mp_join");
      mp_joinindex527 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0});
      slog::Relation* readrel549 = db->getRelation("mp_msk");
      mp_mskindex528 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({2, 3, 0, 1});
      slog::Relation* readrel551 = db->getRelation("mp_put");
      mp_putindex529 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 4, 2, 0, 3});
      slog::Relation* readrel553 = db->getRelation("mp_join");
      mp_joinindex530 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel555 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index531 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 3, 4, 0});
      slog::Relation* readrel557 = db->getRelation("mbranch");
      mbranchindex532 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 2, 0});
      slog::Relation* readrel559 = db->getRelation("mp_msk");
      mp_mskindex533 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 3, 4, 0});
      slog::Relation* readrel561 = db->getRelation("mp_join");
      mp_joinindex534 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 3, 4, 0});
      slog::Relation* readrel563 = db->getRelation("mp_join");
      mp_joindelta539 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({0, 1});
      slog::Relation* readrel565 = db->getRelation("mp_join_ans");
      mp_join_ansindex535 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 2, 0});
      slog::Relation* readrel567 = db->getRelation("mp_msk");
      mp_mskindex536 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 2, 0});
      slog::Relation* readrel569 = db->getRelation("mp_msk");
      mp_mskdelta540 = readrel569->getIndex(ord568, true);
      std::vector<u16> ord570({0, 1});
      slog::Relation* readrel571 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex537 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("mp_join_ans");
      mp_join_ansindex538 = readrel573->getIndex(ord572, false);
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index526, std::array<u64,8>{v_c6, v_c8, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mp_joinindex527, std::array<u64,5>{v_c6, v_c90, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex528, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<4,2>(mp_putindex529, std::array<u64,4>{v_c6, v_c8, 0, 0}, [&](const std::array<u64,4>& m574) {
          u64 v_c92 = m574[2]; u64 v_c91 = m574[3];
          if (!slog::exists_probe<5,3>(mp_joinindex530, std::array<u64,5>{v_c6, v_c91, v_c90, 0, 0})) return;
          slog::join_probe<8,4>($sup5638x44x0x0x0index531, std::array<u64,8>{v_c6, v_c8, v_c92, v_c91, 0, 0, 0, 0}, [&](const std::array<u64,8>& m575) {
            u64 v_c16 = m575[4]; u64 v_c14 = m575[5]; u64 v_c15 = m575[6]; u64 v_c17 = m575[7];
            slog::join_probe<5,5>(mbranchindex532, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, v_c91}, [&](const std::array<u64,5>& m576) {
              if (!slog::exists_probe<3,2>(mp_mskindex533, std::array<u64,3>{v_c6, v_c15, 0})) return;
              slog::join_probe_old<5,4>(mp_joinindex534, mp_joindelta539, std::array<u64,5>{v_c6, v_c90, v_c16, v_c91, 0}, [&](const std::array<u64,5>& m577) {
                u64 v_c89 = m577[4];
                if (!slog::exists_probe<2,1>(mp_join_ansindex535, std::array<u64,2>{v_c89, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex536, mp_mskdelta540, std::array<u64,3>{v_c6, v_c15, 0}, [&](const std::array<u64,3>& m578) {
                  u64 v_c93 = m578[2];
                  slog::join_probe<2,1>(mp_msk_ansindex537, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m579) {
                    u64 v_c39 = m579[1];
                    if (v_c16 == v_c39) return;
                    slog::join_probe<2,1>(mp_join_ansindex538, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m580) {
                      u64 v_c65 = m580[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c92, v_c65}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask541* _cont = new ReadTask541(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask541(db,b), false);
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t9fJL76 __v0) (body (join-old mp_put (0 1 2 3) 1 (0 1 2 3) __t9fJL76 l k v) (exists $sup5638x40x0x0x1 (2 3 7 0 1 4 5 6) 3 k l v) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x40x0x0x0 (1 2 6 0 3 4 5) 3 (1 2 6 0 3 4 5) k l v __t1I5N72 m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t1I5N72 k v __t0q1c75) (exists mp_msk (1 2 0) 3 k m __t0q1c75) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t687K71) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t687K71 k __t1I5N72 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0q1c75) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask604 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex581;  slog::Index** $sup5638x40x0x0x1index582;  slog::Index** mbranchindex583;  slog::Index** mp_putindex584;  slog::Index** mp_mskindex585;  slog::Index** $sup5638x40x0x0x0index586;  slog::Index** mbranchindex587;  slog::Index** mp_putindex588;  slog::Index** mp_mskindex589;  slog::Index** mp_msk_ansindex590;  slog::Index** $sup5638x40x0x0x1index591;  slog::Index** mp_mskindex592;  slog::Index** mp_msk_ansindex593;  slog::Index** mbranchindex594;  slog::Index** mp_putindex595;  slog::Index** mp_mskindex596;  slog::Index** mp_msk_ansindex597;  slog::Index** mp_putdelta598;  slog::Index** $sup5638x40x0x0x0delta599;  slog::Index** $sup5638x40x0x0x1delta600;  slog::Index** mbranchdelta601;  slog::Index** mp_putdelta602;  slog::Index** mp_mskdelta603;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord605({0, 1, 2, 3});
      slog::Relation* readrel606 = db->getRelation("mp_put");
      mp_putindex581 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({0, 1, 2, 3});
      slog::Relation* readrel608 = db->getRelation("mp_put");
      mp_putdelta598 = readrel608->getIndex(ord607, true);
      std::vector<u16> ord609({2, 3, 7, 0, 1, 4, 5, 6});
      slog::Relation* readrel610 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index582 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({3, 0, 1, 2, 4});
      slog::Relation* readrel612 = db->getRelation("mbranch");
      mbranchindex583 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({2, 3, 0, 1});
      slog::Relation* readrel614 = db->getRelation("mp_put");
      mp_putindex584 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("mp_msk");
      mp_mskindex585 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel618 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index586 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel620 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0delta599 = readrel620->getIndex(ord619, true);
      std::vector<u16> ord621({1, 2, 3, 4, 0});
      slog::Relation* readrel622 = db->getRelation("mbranch");
      mbranchindex587 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({2, 3, 0, 1});
      slog::Relation* readrel624 = db->getRelation("mp_put");
      mp_putindex588 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("mp_msk");
      mp_mskindex589 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 0});
      slog::Relation* readrel628 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex590 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel630 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index591 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel632 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta600 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({1, 2, 0});
      slog::Relation* readrel634 = db->getRelation("mp_msk");
      mp_mskindex592 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex593 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 2, 3, 4, 0});
      slog::Relation* readrel638 = db->getRelation("mbranch");
      mbranchindex594 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 2, 3, 4, 0});
      slog::Relation* readrel640 = db->getRelation("mbranch");
      mbranchdelta601 = readrel640->getIndex(ord639, true);
      std::vector<u16> ord641({1, 2, 0, 3});
      slog::Relation* readrel642 = db->getRelation("mp_put");
      mp_putindex595 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 2, 0, 3});
      slog::Relation* readrel644 = db->getRelation("mp_put");
      mp_putdelta602 = readrel644->getIndex(ord643, true);
      std::vector<u16> ord645({1, 2, 0});
      slog::Relation* readrel646 = db->getRelation("mp_msk");
      mp_mskindex596 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({1, 2, 0});
      slog::Relation* readrel648 = db->getRelation("mp_msk");
      mp_mskdelta603 = readrel648->getIndex(ord647, true);
      std::vector<u16> ord649({0, 1});
      slog::Relation* readrel650 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex597 = readrel650->getIndex(ord649, false);
  
    }
    ReadTask604(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c126 = _t[0];
        u64 v_c39 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex581, mp_putdelta598, std::array<u64,4>{v_c126, 0, 0, 0}, [&](const std::array<u64,4>& m651) {
          u64 v_c14 = m651[1]; u64 v_c6 = m651[2]; u64 v_c8 = m651[3];
          if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index582, std::array<u64,8>{v_c6, v_c14, v_c8, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex583, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex584, std::array<u64,4>{v_c6, v_c8, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex585, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<7,3>($sup5638x40x0x0x0index586, $sup5638x40x0x0x0delta599, std::array<u64,7>{v_c6, v_c14, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,7>& m652) {
            u64 v_c127 = m652[3]; u64 v_c15 = m652[4]; u64 v_c16 = m652[5]; u64 v_c17 = m652[6];
            if (!slog::exists_probe<5,4>(mbranchindex587, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex588, std::array<u64,4>{v_c6, v_c8, v_c127, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex589, std::array<u64,3>{v_c6, v_c15, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex590, std::array<u64,2>{v_c16, 0})) return;
            slog::join_probe_old<8,7>($sup5638x40x0x0x1index591, $sup5638x40x0x0x1delta600, std::array<u64,8>{v_c14, v_c15, v_c16, v_c17, v_c127, v_c6, v_c8, 0}, [&](const std::array<u64,8>& m653) {
              u64 v_c128 = m653[7];
              if (!slog::exists_probe<3,3>(mp_mskindex592, std::array<u64,3>{v_c6, v_c15, v_c128})) return;
              if (!slog::exists_probe<2,2>(mp_msk_ansindex593, std::array<u64,2>{v_c128, v_c16})) return;
              slog::join_probe_old<5,4>(mbranchindex594, mbranchdelta601, std::array<u64,5>{v_c16, v_c15, v_c14, v_c17, 0}, [&](const std::array<u64,5>& m654) {
                u64 v_c129 = m654[4];
                slog::join_probe_old<4,4>(mp_putindex595, mp_putdelta602, std::array<u64,4>{v_c129, v_c6, v_c127, v_c8}, [&](const std::array<u64,4>& m655) {
                  slog::join_probe_old<3,3>(mp_mskindex596, mp_mskdelta603, std::array<u64,3>{v_c6, v_c15, v_c128}, [&](const std::array<u64,3>& m656) {
                    slog::join_probe<2,2>(mp_msk_ansindex597, std::array<u64,2>{v_c128, v_c16}, [&](const std::array<u64,2>& m657) {
                      u64 v_c130 = _prim_band(db, v_c6, v_c15);
                      if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c131 = _prim_lt(db, v_c130, v_c125);
                      if (v_c131 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c131) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c127, v_c39, v_c15, v_c16, v_c17});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c39, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask604* _cont = new ReadTask604(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask604(db,b), false);
  // (crule (pre (let __tconst3nEl614 constd01925b37634a1a9d24159d8) (let __tconst5JbS3 constff5a1ae012afa5d4c889c50a) (let __tconst00xS4 const7902699be42c8a8e46fbbb45) (let __tconst6RTh7 const624b60c58c9d8bfb6ff1886c) (let __tconst80wL8 const4e07408562bedb8b60ce05c1) (let __tconst69fL1 const4a44dc15364204a80fe80e90) (let __tconst9RBO2 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst80wL8 __tconst6RTh7 __t9KAP9 __v0) (body (exists _enum (1 0) 1 __tconst3nEl614) (exists mp_put_ans (1 0) 1 __v0) (exists mp_put_ans (0 1) 1 __t9KAP9) (join mp_put (2 3 0 1) 2 __tconst00xS4 __tconst5JbS3 __t5DYC6 __t5kVD5) (join _enum (0 1) 2 __t5kVD5 __tconst3nEl614) (join mp_put_ans (0 1) 2 __t5DYC6 __v0) (join mp_put_ans (0 1) 1 __t9KAP9 __v1)) (head (mkstruct mp_put (1 2 3 0) __2h5j615 __v1 __tconst9RBO2 __tconst69fL1)) mp_basic.slog:14 #f)
  class ReadTask666 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex659;  slog::Index** mp_put_ansindex660;  slog::Index** mp_put_ansindex661;  slog::Index** mp_putindex662;  slog::Index** _enumindex663;  slog::Index** mp_put_ansindex664;  slog::Index** mp_put_ansindex665;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      std::vector<u16> ord667({2, 3, 0, 1});
      slog::Relation* readrel668 = db->getRelation("mp_put");
      driver_index = readrel668->getIndex(ord667, true);
      std::vector<u16> ord669({1, 0});
      slog::Relation* readrel670 = db->getRelation("_enum");
      _enumindex659 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 0});
      slog::Relation* readrel672 = db->getRelation("mp_put_ans");
      mp_put_ansindex660 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 1});
      slog::Relation* readrel674 = db->getRelation("mp_put_ans");
      mp_put_ansindex661 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({2, 3, 0, 1});
      slog::Relation* readrel676 = db->getRelation("mp_put");
      mp_putindex662 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({0, 1});
      slog::Relation* readrel678 = db->getRelation("_enum");
      _enumindex663 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({0, 1});
      slog::Relation* readrel680 = db->getRelation("mp_put_ans");
      mp_put_ansindex664 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({0, 1});
      slog::Relation* readrel682 = db->getRelation("mp_put_ans");
      mp_put_ansindex665 = readrel682->getIndex(ord681, false);
  
    }
    ReadTask666(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_constd01925b37634a1a9d24159d8;
      u64 v_c133 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c134 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c135 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const4a44dc15364204a80fe80e90;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c136, v_c135, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m683) {
        u64 v_c139 = m683[2];
        u64 v_c39 = m683[3];
        if (buckethash(v_c139) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex659, std::array<u64,2>{v_c132, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex660, std::array<u64,2>{v_c39, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex661, std::array<u64,2>{v_c139, 0})) return;
        slog::join_probe<4,2>(mp_putindex662, std::array<u64,4>{v_c134, v_c133, 0, 0}, [&](const std::array<u64,4>& m684) {
          u64 v_c140 = m684[2]; u64 v_c141 = m684[3];
          slog::join_probe<2,2>(_enumindex663, std::array<u64,2>{v_c141, v_c132}, [&](const std::array<u64,2>& m685) {
            slog::join_probe<2,2>(mp_put_ansindex664, std::array<u64,2>{v_c140, v_c39}, [&](const std::array<u64,2>& m686) {
              slog::join_probe<2,1>(mp_put_ansindex665, std::array<u64,2>{v_c139, 0}, [&](const std::array<u64,2>& m687) {
                u64 v_c76 = m687[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c76, v_c138, v_c137}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask666* _cont = new ReadTask666(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask666(db,b), false);
}

