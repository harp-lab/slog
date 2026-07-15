
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c7adbd30ff68a90cb(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst6PdE830 constd01925b37634a1a9d24159d8) (let __tconst4TD6412 constff5a1ae012afa5d4c889c50a) (let __tconst93JF413 const7902699be42c8a8e46fbbb45) (let __tconst1wzT410 const624b60c58c9d8bfb6ff1886c) (let __tconst98iL411 const4e07408562bedb8b60ce05c1)) (probe mp_put (2 3 0 1) 2 __tconst93JF413 __tconst4TD6412 __t33kH415 __t0LaQ414) (body (join _enum (0 1) 2 __t0LaQ414 __tconst6PdE830) (join mp_put_ans (0 1) 1 __t33kH415 __v0)) (head (mkstruct mp_put (1 2 3 0) __5VOt831 __v0 __tconst98iL411 __tconst1wzT410)) mp_basic.slog:14 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex0;  slog::Index** mp_put_ansindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      std::vector<u16> ord3({2, 3, 0, 1});
      slog::Relation* readrel4 = db->getRelation("mp_put");
      driver_index = readrel4->getIndex(ord3, true);
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("_enum");
      _enumindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({0, 1});
      slog::Relation* readrel8 = db->getRelation("mp_put_ans");
      mp_put_ansindex1 = readrel8->getIndex(ord7, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constd01925b37634a1a9d24159d8;
      u64 v_c1 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c4 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c2, v_c1, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m9) {
        u64 v_c5 = m9[2];
        u64 v_c6 = m9[3];
        if (buckethash(v_c5) != bucket) return;
        slog::join_probe<2,2>(_enumindex0, std::array<u64,2>{v_c6, v_c0}, [&](const std::array<u64,2>& m10) {
          slog::join_probe<2,1>(mp_put_ansindex1, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m11) {
            u64 v_c7 = m11[1];
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c7, v_c4, v_c3}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t8KSH173 l k) (body (exists $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (join $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 k l __t5APc170 m p r) (exists mp_has0 (0 2 1) 2 __t5APc170 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t4G6v169) (join mp_has0 (0 2 1) 3 __t5APc170 k __t4G6v169) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4QPc174) (join mp_msk_ans (0 1) 2 __t4QPc174 p) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index12;  slog::Index** mbranchindex13;  slog::Index** mp_has0index14;  slog::Index** mp_mskindex15;  slog::Index** mp_has0_ansindex16;  slog::Index** $sup5638x60x0x0x0index17;  slog::Index** mp_has0index18;  slog::Index** mp_mskindex19;  slog::Index** mp_msk_ansindex20;  slog::Index** mbranchindex21;  slog::Index** mp_has0index22;  slog::Index** mp_mskindex23;  slog::Index** mp_msk_ansindex24;  slog::Index** mp_mskdelta25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel28->getIndex(ord27, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord29({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel30 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index12 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({3, 0, 1, 2, 4});
      slog::Relation* readrel32 = db->getRelation("mbranch");
      mbranchindex13 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({2, 0, 1});
      slog::Relation* readrel34 = db->getRelation("mp_has0");
      mp_has0index14 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 0});
      slog::Relation* readrel36 = db->getRelation("mp_msk");
      mp_mskindex15 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex16 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel40 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index17 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 2, 1});
      slog::Relation* readrel42 = db->getRelation("mp_has0");
      mp_has0index18 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("mp_msk");
      mp_mskindex19 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex20 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 3, 4, 0});
      slog::Relation* readrel48 = db->getRelation("mbranch");
      mbranchindex21 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 2, 1});
      slog::Relation* readrel50 = db->getRelation("mp_has0");
      mp_has0index22 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("mp_msk");
      mp_mskindex23 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("mp_msk");
      mp_mskdelta25 = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex24 = readrel56->getIndex(ord55, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x60x0x0x0index12, std::array<u64,6>{v_c11, v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex13, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index14, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex15, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<2,1>(mp_has0_ansindex16, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m57) {
          u64 v_c12 = m57[1];
          slog::join_probe<6,2>($sup5638x60x0x0x0index17, std::array<u64,6>{v_c11, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,6>& m58) {
            u64 v_c13 = m58[2]; u64 v_c14 = m58[3]; u64 v_c15 = m58[4]; u64 v_c16 = m58[5];
            if (!slog::exists_probe<3,2>(mp_has0index18, std::array<u64,3>{v_c13, v_c11, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex19, std::array<u64,3>{v_c11, v_c14, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex20, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe<5,4>(mbranchindex21, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0}, [&](const std::array<u64,5>& m59) {
              u64 v_c17 = m59[4];
              slog::join_probe<3,3>(mp_has0index22, std::array<u64,3>{v_c13, v_c11, v_c17}, [&](const std::array<u64,3>& m60) {
                slog::join_probe_old<3,2>(mp_mskindex23, mp_mskdelta25, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m61) {
                  u64 v_c18 = m61[2];
                  slog::join_probe<2,2>(mp_msk_ansindex24, std::array<u64,2>{v_c18, v_c15}, [&](const std::array<u64,2>& m62) {
                    u64 v_c19 = _prim_band(db, v_c11, v_c14);
                    if (v_c19 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c20 = _prim_lt(db, v_c19, v_c8);
                    if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c20) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c12}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre39sS990 __errf6w0g991 __errf3jkN992) (body) (head (emit error (0) __erre39sS990)) <internal>:1 #f)
  class ReadTask64 : public slog::Task
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
      std::vector<u16> ord65({0});
      slog::Relation* readrel66 = db->getRelation("error");
      head_index[0] = readrel66->getIndex(ord65, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask64* _cont = new ReadTask64(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask64(db,b), false);
  // (crule (pre (let __tconst2TBF232 const5feceb66ffc86f38d952786c)) (scan mbranch __t0LiB230 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t0LiB230 __t2Hro229 __t7SeD231) (join mbranch (0 1 2 3 4) 1 __t2Hro229 q n u v) (cmp lt n m) (let __t1wK1233 (band q m)) (cmp gt __t1wK1233 __tconst2TBF232)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t7SeD231 r l m n p q u v)) map.slog:99 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex67;  slog::Index** mbranchindex68;  slog::Index** mp_uniondelta69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord71({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel72 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel72->getIndex(ord71, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("mp_union");
      mp_unionindex67 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("mp_union");
      mp_uniondelta69 = readrel76->getIndex(ord75, true);
      std::vector<u16> ord77({0, 1, 2, 3, 4});
      slog::Relation* readrel78 = db->getRelation("mbranch");
      mbranchindex68 = readrel78->getIndex(ord77, false);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c25 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex67, mp_uniondelta69, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m79) {
          u64 v_c26 = m79[1]; u64 v_c27 = m79[2];
          slog::join_probe<5,1>(mbranchindex68, std::array<u64,5>{v_c26, 0, 0, 0, 0}, [&](const std::array<u64,5>& m80) {
            u64 v_c28 = m80[1]; u64 v_c29 = m80[2]; u64 v_c30 = m80[3]; u64 v_c31 = m80[4];
            u64 v_c32 = _prim_lt(db, v_c29, v_c14);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c32) return;
            u64 v_c33 = _prim_band(db, v_c28, v_c14);
            if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c34 = _prim_gt(db, v_c33, v_c24);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c34) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c27, v_c16, v_c10, v_c14, v_c29, v_c15, v_c28, v_c30, v_c31}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask70* _cont = new ReadTask70(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), false);
  // (crule (pre (let __tconst18Hz90 const6b86b273ff34fce19d6b804e) (let __tconst9Tbc87 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t9ZZh89 x) (body (cmp lt __tconst18Hz90 x) (let __t0Ny888 (_0002f x __tconst9Tbc87))) (head (emit-temp temp2oEt1084 __t0Ny888)) map.slog:19 #f)
  class ReadTask83 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2oEt1084");
      outer_rel = db->getRelation("mp_hsb");
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c36 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _prim_lt(db, v_c35, v_c38);
        if (v_c39 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        if (!v_c39) return;
        u64 v_c40 = _prim__0002f(db, v_c38, v_c36);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c40});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), false);
  // (crule (pre (let _00024sqc9fm8532 const7902699be42c8a8e46fbbb45) (let _00024sqc5Ei6533 constff5a1ae012afa5d4c889c50a) (let _00024sqc5VV5536 const6b86b273ff34fce19d6b804e) (let _00024sqc5iw6537 const4a44dc15364204a80fe80e90) (let _00024sqc7khv540 const4e07408562bedb8b60ce05c1) (let _00024sqc8p4s541 const624b60c58c9d8bfb6ff1886c) (let _00024sqc8B5i544 const4e07408562bedb8b60ce05c1) (let _00024sqc47Sw545 const5feceb66ffc86f38d952786c) (let _00024sqc1sL8546 const6b86b273ff34fce19d6b804e) (let _00024sqc6lX1547 constd4735e3a265e16eee03f5971) (let _00024sqb3Qju530 (lempty)) (let _00024sqb2jbJ531 (lpush _00024sqb3Qju530 _00024sqc9fm8532)) (let _00024seq0 (lpush _00024sqb2jbJ531 _00024sqc5Ei6533)) (let _00024sqb4ySz534 (lempty)) (let _00024sqb6WQf535 (lpush _00024sqb4ySz534 _00024sqc5VV5536)) (let _00024seq1 (lpush _00024sqb6WQf535 _00024sqc5iw6537)) (let _00024sqb4V4h538 (lempty)) (let _00024sqb801I539 (lpush _00024sqb4V4h538 _00024sqc7khv540)) (let _00024seq2 (lpush _00024sqb801I539 _00024sqc8p4s541))) (scan mp_fromlist_ans __t1Xpx31 r) (body (join mp_fromlist (0 1) 1 __t1Xpx31 _00024seq3) (letp _00024sql9Drv542 (aslst _00024seq3)) (let chk3zQ11029 (llen _00024sql9Drv542)) (eq _00024sqc8B5i544 chk3zQ11029) (letp chk1JH51030 (lref _00024sql9Drv542 _00024sqc47Sw545)) (eq _00024seq0 chk1JH51030) (letp chk4FeT1031 (lref _00024sql9Drv542 _00024sqc1sL8546)) (eq _00024seq1 chk4FeT1031) (letp chk7VEp1032 (lref _00024sql9Drv542 _00024sqc6lX1547)) (eq _00024seq2 chk7VEp1032)) (head (emit canon (0) r)) mp_basic.slog:15 #f)
  class ReadTask86 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_fromlistindex85;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord87({0});
      slog::Relation* readrel88 = db->getRelation("canon");
      head_index[0] = readrel88->getIndex(ord87, false);
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("mp_fromlist");
      mp_fromlistindex85 = readrel90->getIndex(ord89, false);
  
    }
    ReadTask86(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c42 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c44 = v_const4a44dc15364204a80fe80e90;
      u64 v_c45 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c46 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c47 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_constd4735e3a265e16eee03f5971;
      u64 v_c51 = _prim_lempty(db);
      if (v_c51 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c52 = _prim_lpush(db, v_c51, v_c41);
      if (v_c52 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c53 = _prim_lpush(db, v_c52, v_c42);
      if (v_c53 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c54 = _prim_lempty(db);
      if (v_c54 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c55 = _prim_lpush(db, v_c54, v_c43);
      if (v_c55 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c56 = _prim_lpush(db, v_c55, v_c44);
      if (v_c56 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c57 = _prim_lempty(db);
      if (v_c57 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c58 = _prim_lpush(db, v_c57, v_c45);
      if (v_c58 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c59 = _prim_lpush(db, v_c58, v_c46);
      if (v_c59 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c60 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe<2,1>(mp_fromlistindex85, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m91) {
          u64 v_c61 = m91[1];
          bool ok92 = true;
          u64 v_c62 = _prim_aslst(db, v_c61, &ok92);
          if (!ok92) return;
          u64 v_c63 = _prim_llen(db, v_c62);
          if (v_c63 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return; }
          if (v_c47 != v_c63) return;
          bool ok93 = true;
          u64 v_c64 = _prim_lref(db, v_c62, v_c48, &ok93);
          if (!ok93) return;
          if (v_c53 != v_c64) return;
          bool ok94 = true;
          u64 v_c65 = _prim_lref(db, v_c62, v_c49, &ok94);
          if (!ok94) return;
          if (v_c56 != v_c65) return;
          bool ok95 = true;
          u64 v_c66 = _prim_lref(db, v_c62, v_c50, &ok95);
          if (!ok95) return;
          if (v_c59 != v_c66) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:15", "delta:mp_fromlist_ans", _fires);
  
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
  // (crule (pre) (scan mp_put_soft_ans __t6FhG321 r) (body (join-old mp_put_soft (0 1 2 3) 1 (0 1 2 3) __t6FhG321 s k v) (exists mp_union (1 2 0) 1 s) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t4k6G319) (join-old mp_union (1 2 0) 2 (1 2 0) s __t4k6G319 __t4hCg320)) (head (emit mp_union_ans (0 1) __t4hCg320 r)) map.slog:93 #f)
  class ReadTask103 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex96;  slog::Index** mp_unionindex97;  slog::Index** mleafindex98;  slog::Index** mp_unionindex99;  slog::Index** mp_put_softdelta100;  slog::Index** mleafdelta101;  slog::Index** mp_uniondelta102;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord104({0, 1});
      slog::Relation* readrel105 = db->getRelation("mp_union_ans");
      head_index[0] = readrel105->getIndex(ord104, false);
      outer_rel = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord106({0, 1, 2, 3});
      slog::Relation* readrel107 = db->getRelation("mp_put_soft");
      mp_put_softindex96 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 1, 2, 3});
      slog::Relation* readrel109 = db->getRelation("mp_put_soft");
      mp_put_softdelta100 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("mp_union");
      mp_unionindex97 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("mleaf");
      mleafindex98 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 2, 0});
      slog::Relation* readrel115 = db->getRelation("mleaf");
      mleafdelta101 = readrel115->getIndex(ord114, true);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("mp_union");
      mp_unionindex99 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("mp_union");
      mp_uniondelta102 = readrel119->getIndex(ord118, true);
  
    }
    ReadTask103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe_old<4,1>(mp_put_softindex96, mp_put_softdelta100, std::array<u64,4>{v_c67, 0, 0, 0}, [&](const std::array<u64,4>& m120) {
          u64 v_c68 = m120[1]; u64 v_c11 = m120[2]; u64 v_c31 = m120[3];
          if (!slog::exists_probe<3,1>(mp_unionindex97, std::array<u64,3>{v_c68, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex98, mleafdelta101, std::array<u64,3>{v_c11, v_c31, 0}, [&](const std::array<u64,3>& m121) {
            u64 v_c69 = m121[2];
            slog::join_probe_old<3,2>(mp_unionindex99, mp_uniondelta102, std::array<u64,3>{v_c68, v_c69, 0}, [&](const std::array<u64,3>& m122) {
              u64 v_c70 = m122[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c16}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_put_soft_ans", _fires);
  
      if (!_done)
      {
        ReadTask103* _cont = new ReadTask103(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask103(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_join __t4lFL393 p0 t0 p1 t1) (body (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (exists $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t4lFL393 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 5 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists mp_hsb_ans (0 1) 2 __t1lh0397 __v0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0 dup0XDZ1075 dup8FhK1076 __v1 __v3) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join mp_hsb_ans (0 1) 2 __t1lh0397 __v3) (join mp_hsb_ans (0 1) 2 __t1lh0397 __v1) (join mp_hsb_ans (0 1) 2 __t1lh0397 __v0) (join mp_msk (1 2 0) 2 p0 __v1 __t8rat400) (join mp_msk_ans (0 1) 1 __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join mp_hsb (0 1) 2 __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask136 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x0index123;  slog::Index** $sup5638x29x0x0x2index124;  slog::Index** mp_mskindex125;  slog::Index** $sup5638x29x0x0x1index126;  slog::Index** mp_hsb_ansindex127;  slog::Index** mp_hsb_ansindex128;  slog::Index** $sup5638x29x0x0x2index129;  slog::Index** mp_hsb_ansindex130;  slog::Index** mp_hsb_ansindex131;  slog::Index** mp_hsb_ansindex132;  slog::Index** mp_mskindex133;  slog::Index** mp_msk_ansindex134;  slog::Index** mp_hsbindex135;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord137({1, 0, 2, 3, 4});
      slog::Relation* readrel138 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index123 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel140 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index124 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("mp_msk");
      mp_mskindex125 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel144 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index126 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex127 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex128 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel150 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index129 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex130 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({0, 1});
      slog::Relation* readrel154 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex131 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex132 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("mp_msk");
      mp_mskindex133 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex134 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0, 1});
      slog::Relation* readrel162 = db->getRelation("mp_hsb");
      mp_hsbindex135 = readrel162->getIndex(ord161, false);
  
    }
    ReadTask136(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c74 = _t[2];
        u64 v_c75 = _t[3];
        u64 v_c76 = _t[4];
        slog::join_probe<5,5>($sup5638x29x0x0x0index123, std::array<u64,5>{v_c73, v_c72, v_c75, v_c74, v_c76}, [&](const std::array<u64,5>& m163) {
          if (!slog::exists_probe<11,5>($sup5638x29x0x0x2index124, std::array<u64,11>{v_c72, v_c73, v_c75, v_c74, v_c76, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex125, std::array<u64,3>{v_c73, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x29x0x0x1index126, std::array<u64,7>{v_c72, v_c73, v_c75, v_c74, v_c76, 0, 0}, [&](const std::array<u64,7>& m164) {
            u64 v_c77 = m164[5]; u64 v_c7 = m164[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex127, std::array<u64,2>{v_c77, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex128, std::array<u64,2>{v_c77, v_c7})) return;
            slog::join_probe<11,7>($sup5638x29x0x0x2index129, std::array<u64,11>{v_c72, v_c73, v_c75, v_c74, v_c76, v_c77, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,11>& m165) {
              u64 v_c78 = m165[7]; u64 v_c79 = m165[8]; u64 v_c80 = m165[9]; u64 v_c81 = m165[10];
              if (v_c77 != v_c79) return;
              if (v_c77 != v_c78) return;
              slog::join_probe<2,2>(mp_hsb_ansindex130, std::array<u64,2>{v_c77, v_c81}, [&](const std::array<u64,2>& m166) {
                slog::join_probe<2,2>(mp_hsb_ansindex131, std::array<u64,2>{v_c77, v_c80}, [&](const std::array<u64,2>& m167) {
                  slog::join_probe<2,2>(mp_hsb_ansindex132, std::array<u64,2>{v_c77, v_c7}, [&](const std::array<u64,2>& m168) {
                    slog::join_probe<3,2>(mp_mskindex133, std::array<u64,3>{v_c73, v_c80, 0}, [&](const std::array<u64,3>& m169) {
                      u64 v_c82 = m169[2];
                      slog::join_probe<2,1>(mp_msk_ansindex134, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m170) {
                        u64 v_c83 = m170[1];
                        u64 v_c84 = _prim_bxor(db, v_c73, v_c75);
                        if (v_c84 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe<2,2>(mp_hsbindex135, std::array<u64,2>{v_c77, v_c84}, [&](const std::array<u64,2>& m171) {
                          u64 v_c85 = _prim_band(db, v_c73, v_c7);
                          if (v_c85 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c86 = _prim_gt(db, v_c85, v_c71);
                          if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c86) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c72, v_c83, v_c81, v_c74, v_c76});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c83, v_c81, v_c76, v_c74}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask136* _cont = new ReadTask136(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask136(db,b), false);
  // (crule (pre) (scan mp_union __t9sO9241 __t7TCq240 t) (body (exists mp_put (1 2 0 3) 1 t) (join mleaf (0 1 2) 1 __t7TCq240 k v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t3dD4242) (join mp_put_ans (0 1) 1 __t3dD4242 r)) (head (emit mp_union_ans (0 1) __t9sO9241 r)) map.slog:92 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex173;  slog::Index** mleafindex174;  slog::Index** mp_putindex175;  slog::Index** mp_put_ansindex176;  slog::Index** mp_putdelta177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("mp_union_ans");
      head_index[0] = readrel180->getIndex(ord179, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord181({1, 2, 0, 3});
      slog::Relation* readrel182 = db->getRelation("mp_put");
      mp_putindex173 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1, 2});
      slog::Relation* readrel184 = db->getRelation("mleaf");
      mleafindex174 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 3, 0});
      slog::Relation* readrel186 = db->getRelation("mp_put");
      mp_putindex175 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 3, 0});
      slog::Relation* readrel188 = db->getRelation("mp_put");
      mp_putdelta177 = readrel188->getIndex(ord187, true);
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("mp_put_ans");
      mp_put_ansindex176 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c87 = _t[0];
        u64 v_c88 = _t[1];
        u64 v_c89 = _t[2];
        if (!slog::exists_probe<4,1>(mp_putindex173, std::array<u64,4>{v_c89, 0, 0, 0})) return;
        slog::join_probe<3,1>(mleafindex174, std::array<u64,3>{v_c88, 0, 0}, [&](const std::array<u64,3>& m191) {
          u64 v_c11 = m191[1]; u64 v_c31 = m191[2];
          slog::join_probe_old<4,3>(mp_putindex175, mp_putdelta177, std::array<u64,4>{v_c89, v_c11, v_c31, 0}, [&](const std::array<u64,4>& m192) {
            u64 v_c90 = m192[3];
            slog::join_probe<2,1>(mp_put_ansindex176, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m193) {
              u64 v_c16 = m193[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c16}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), false);
  // (crule (pre (let __tconst94WO292 const5feceb66ffc86f38d952786c)) (scan mp_put __t5psG291 __t5ueb290 k v) (body (join mbranch (0 1 2 3 4) 1 __t5ueb290 p m l r) (let __t5cEt293 (band k m)) (cmp gt __t5cEt293 __tconst94WO292)) (head (emit $sup5638x42x0x0x0 (4 2 3 5 0 1 6) p l m r __t5psG291 k v)) map.slog:43 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord196({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel197 = db->getRelation("$sup5638x42x0x0x0");
      head_index[0] = readrel197->getIndex(ord196, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord198({0, 1, 2, 3, 4});
      slog::Relation* readrel199 = db->getRelation("mbranch");
      mbranchindex194 = readrel199->getIndex(ord198, false);
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c92 = _t[0];
        u64 v_c93 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c31 = _t[3];
        slog::join_probe<5,1>(mbranchindex194, std::array<u64,5>{v_c93, 0, 0, 0, 0}, [&](const std::array<u64,5>& m200) {
          u64 v_c15 = m200[1]; u64 v_c14 = m200[2]; u64 v_c10 = m200[3]; u64 v_c16 = m200[4];
          u64 v_c94 = _prim_band(db, v_c11, v_c14);
          if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          u64 v_c95 = _prim_gt(db, v_c94, v_c91);
          if (v_c95 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          if (!v_c95) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c15, v_c10, v_c14, v_c16, v_c92, v_c11, v_c31}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask195* _cont = new ReadTask195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask195(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t0wz7137 (bxor p0 p1))) (head (emit-temp temp61Si1083 __t0wz7137)) map.slog:30 #f)
  class ReadTask202 : public slog::Task
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
      head_rel[0] = db->getRelation("temp61Si1083");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
  
    }
    ReadTask202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c97 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c73 = _t[3];
        u64 v_c75 = _t[4];
        u64 v_c74 = _t[5];
        u64 v_c76 = _t[6];
        u64 v_c98 = _prim_bxor(db, v_c73, v_c75);
        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c98});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask202* _cont = new ReadTask202(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask202(db,b), false);
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (scan mp_put_soft __t2Eey276 t k v) (body (join $sup5638x68x0x0x0 (1 2 3 0) 4 k t v __t2Eey276) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst6EKe278) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t4H3I279) (exists mp_put_ans (0 1) 1 __t4H3I279) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t16yQ277) (join mp_has0_ans (0 1) 2 __t16yQ277 __tconst6EKe278) (join mp_put_ans (0 1) 1 __t4H3I279 r)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x68x0x0x0index203;  slog::Index** mp_has0index204;  slog::Index** mp_has0_ansindex205;  slog::Index** mp_putindex206;  slog::Index** mp_put_ansindex207;  slog::Index** mp_has0index208;  slog::Index** mp_has0_ansindex209;  slog::Index** mp_put_ansindex210;  slog::Index** mp_putdelta211;  slog::Index** mp_has0delta212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel215->getIndex(ord214, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord216({1, 2, 3, 0});
      slog::Relation* readrel217 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index203 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("mp_has0");
      mp_has0index204 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex205 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 3, 0});
      slog::Relation* readrel223 = db->getRelation("mp_put");
      mp_putindex206 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 3, 0});
      slog::Relation* readrel225 = db->getRelation("mp_put");
      mp_putdelta211 = readrel225->getIndex(ord224, true);
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("mp_put_ans");
      mp_put_ansindex207 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("mp_has0");
      mp_has0index208 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 0});
      slog::Relation* readrel231 = db->getRelation("mp_has0");
      mp_has0delta212 = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex209 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("mp_put_ans");
      mp_put_ansindex210 = readrel235->getIndex(ord234, false);
  
    }
    ReadTask213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c89 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c31 = _t[3];
        slog::join_probe<4,4>($sup5638x68x0x0x0index203, std::array<u64,4>{v_c11, v_c89, v_c31, v_c100}, [&](const std::array<u64,4>& m236) {
          if (!slog::exists_probe<3,2>(mp_has0index204, std::array<u64,3>{v_c89, v_c11, 0})) return;
          if (!slog::exists_probe<2,1>(mp_has0_ansindex205, std::array<u64,2>{v_c99, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex206, mp_putdelta211, std::array<u64,4>{v_c89, v_c11, v_c31, 0}, [&](const std::array<u64,4>& m237) {
            u64 v_c101 = m237[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex207, std::array<u64,2>{v_c101, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index208, mp_has0delta212, std::array<u64,3>{v_c89, v_c11, 0}, [&](const std::array<u64,3>& m238) {
              u64 v_c102 = m238[2];
              slog::join_probe<2,2>(mp_has0_ansindex209, std::array<u64,2>{v_c102, v_c99}, [&](const std::array<u64,2>& m239) {
                slog::join_probe<2,1>(mp_put_ansindex210, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m240) {
                  u64 v_c16 = m240[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c100, v_c16}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask213* _cont = new ReadTask213(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask213(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mp_msk __t9QiO115 k m) (body (exists $sup5638x62x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t9QiO115 p) (exists mbranch (1 2 3 4 0) 2 p m) (join $sup5638x62x0x0x0 (1 3 4 0 2 5) 3 k m p __t68rk111 l r) (exists mp_has0 (0 2 1) 2 __t68rk111 k) (exists mp_has0 (1 2 0) 2 r k) (join mbranch (1 2 3 4 0) 4 p m l r __t032L110) (join mp_has0 (0 2 1) 3 __t68rk111 k __t032L110) (join mp_has0 (1 2 0) 2 r k __t6Hok114) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask253 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index241;  slog::Index** mbranchindex242;  slog::Index** mp_has0index243;  slog::Index** mp_msk_ansindex244;  slog::Index** mbranchindex245;  slog::Index** $sup5638x62x0x0x0index246;  slog::Index** mp_has0index247;  slog::Index** mp_has0index248;  slog::Index** mbranchindex249;  slog::Index** mp_has0index250;  slog::Index** mp_has0index251;  slog::Index** mp_has0_ansindex252;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel255->getIndex(ord254, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord256({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel257 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index241 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({2, 0, 1, 3, 4});
      slog::Relation* readrel259 = db->getRelation("mbranch");
      mbranchindex242 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({2, 0, 1});
      slog::Relation* readrel261 = db->getRelation("mp_has0");
      mp_has0index243 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex244 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 3, 4, 0});
      slog::Relation* readrel265 = db->getRelation("mbranch");
      mbranchindex245 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel267 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index246 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0, 2, 1});
      slog::Relation* readrel269 = db->getRelation("mp_has0");
      mp_has0index247 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 2, 0});
      slog::Relation* readrel271 = db->getRelation("mp_has0");
      mp_has0index248 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 3, 4, 0});
      slog::Relation* readrel273 = db->getRelation("mbranch");
      mbranchindex249 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 2, 1});
      slog::Relation* readrel275 = db->getRelation("mp_has0");
      mp_has0index250 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 0});
      slog::Relation* readrel277 = db->getRelation("mp_has0");
      mp_has0index251 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex252 = readrel279->getIndex(ord278, false);
  
    }
    ReadTask253(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c104 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x62x0x0x0index241, std::array<u64,6>{v_c11, v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex242, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index243, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex244, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m280) {
          u64 v_c15 = m280[1];
          if (!slog::exists_probe<5,2>(mbranchindex245, std::array<u64,5>{v_c15, v_c14, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x62x0x0x0index246, std::array<u64,6>{v_c11, v_c14, v_c15, 0, 0, 0}, [&](const std::array<u64,6>& m281) {
            u64 v_c105 = m281[3]; u64 v_c10 = m281[4]; u64 v_c16 = m281[5];
            if (!slog::exists_probe<3,2>(mp_has0index247, std::array<u64,3>{v_c105, v_c11, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index248, std::array<u64,3>{v_c16, v_c11, 0})) return;
            slog::join_probe<5,4>(mbranchindex249, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0}, [&](const std::array<u64,5>& m282) {
              u64 v_c106 = m282[4];
              slog::join_probe<3,3>(mp_has0index250, std::array<u64,3>{v_c105, v_c11, v_c106}, [&](const std::array<u64,3>& m283) {
                slog::join_probe<3,2>(mp_has0index251, std::array<u64,3>{v_c16, v_c11, 0}, [&](const std::array<u64,3>& m284) {
                  u64 v_c107 = m284[2];
                  slog::join_probe<2,1>(mp_has0_ansindex252, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m285) {
                    u64 v_c12 = m285[1];
                    u64 v_c108 = _prim_band(db, v_c11, v_c14);
                    if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c109 = _prim_gt(db, v_c108, v_c103);
                    if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c109) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c12}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask253* _cont = new ReadTask253(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask253(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre8TMD982 __errf6bbI983 __errf5YDg984 __errf9i85985 __errf5pg5986) (body) (head (emit error (0) __erre8TMD982)) <internal>:1 #f)
  class ReadTask287 : public slog::Task
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
      std::vector<u16> ord288({0});
      slog::Relation* readrel289 = db->getRelation("error");
      head_index[0] = readrel289->getIndex(ord288, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c110 = _t[0];
        u64 v_c111 = _t[1];
        u64 v_c112 = _t[2];
        u64 v_c113 = _t[3];
        u64 v_c114 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c110}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mp_union_ans __t2OJC49 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t2OJC49 l __t499t48) (exists mbranch (3 0 1 2 4) 1 l) (exists $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join-old mp_union (2 0 1) 1 (2 0 1) __t499t48 __t0mSQ44 __t39oH43) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t0mSQ44 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t0mSQ44 l) (join-old mbranch (3 0 1 2 4) 2 (3 0 1 2 4) l __t39oH43 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t0mSQ44) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 (1 2 4 6 0 3 5 7 8) l m p r __t0mSQ44 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t499t48) (exists mp_msk (1 2 0) 2 q m) (join-old $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t0mSQ44 n q u v __t0xN947) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t499t48) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask315 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex290;  slog::Index** mbranchindex291;  slog::Index** $sup5638x95x0x0x0index292;  slog::Index** $sup5638x95x0x0x1index293;  slog::Index** mp_unionindex294;  slog::Index** $sup5638x95x0x0x0index295;  slog::Index** $sup5638x95x0x0x1index296;  slog::Index** mbranchindex297;  slog::Index** $sup5638x95x0x0x1index298;  slog::Index** mp_mskindex299;  slog::Index** mp_msk_ansindex300;  slog::Index** $sup5638x95x0x0x0index301;  slog::Index** mbranchindex302;  slog::Index** mp_mskindex303;  slog::Index** $sup5638x95x0x0x1index304;  slog::Index** mbranchindex305;  slog::Index** mp_mskindex306;  slog::Index** mp_msk_ansindex307;  slog::Index** mp_uniondelta308;  slog::Index** mp_uniondelta309;  slog::Index** mbranchdelta310;  slog::Index** $sup5638x95x0x0x0delta311;  slog::Index** $sup5638x95x0x0x1delta312;  slog::Index** mbranchdelta313;  slog::Index** mp_mskdelta314;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord316({0, 1, 2});
      slog::Relation* readrel317 = db->getRelation("mp_union");
      mp_unionindex290 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1, 2});
      slog::Relation* readrel319 = db->getRelation("mp_union");
      mp_uniondelta308 = readrel319->getIndex(ord318, true);
      std::vector<u16> ord320({3, 0, 1, 2, 4});
      slog::Relation* readrel321 = db->getRelation("mbranch");
      mbranchindex291 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel323 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index292 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel325 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index293 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({2, 0, 1});
      slog::Relation* readrel327 = db->getRelation("mp_union");
      mp_unionindex294 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({2, 0, 1});
      slog::Relation* readrel329 = db->getRelation("mp_union");
      mp_uniondelta309 = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel331 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index295 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel333 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index296 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({3, 0, 1, 2, 4});
      slog::Relation* readrel335 = db->getRelation("mbranch");
      mbranchindex297 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({3, 0, 1, 2, 4});
      slog::Relation* readrel337 = db->getRelation("mbranch");
      mbranchdelta310 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel339 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index298 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({2, 0, 1});
      slog::Relation* readrel341 = db->getRelation("mp_msk");
      mp_mskindex299 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 0});
      slog::Relation* readrel343 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex300 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel345 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index301 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel347 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0delta311 = readrel347->getIndex(ord346, true);
      std::vector<u16> ord348({1, 2, 3, 4, 0});
      slog::Relation* readrel349 = db->getRelation("mbranch");
      mbranchindex302 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("mp_msk");
      mp_mskindex303 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel353 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index304 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel355 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta312 = readrel355->getIndex(ord354, true);
      std::vector<u16> ord356({1, 2, 3, 4, 0});
      slog::Relation* readrel357 = db->getRelation("mbranch");
      mbranchindex305 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 2, 3, 4, 0});
      slog::Relation* readrel359 = db->getRelation("mbranch");
      mbranchdelta313 = readrel359->getIndex(ord358, true);
      std::vector<u16> ord360({1, 2, 0});
      slog::Relation* readrel361 = db->getRelation("mp_msk");
      mp_mskindex306 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 2, 0});
      slog::Relation* readrel363 = db->getRelation("mp_msk");
      mp_mskdelta314 = readrel363->getIndex(ord362, true);
      std::vector<u16> ord364({0, 1});
      slog::Relation* readrel365 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex307 = readrel365->getIndex(ord364, false);
  
    }
    ReadTask315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex290, mp_uniondelta308, std::array<u64,3>{v_c116, 0, 0}, [&](const std::array<u64,3>& m366) {
          u64 v_c10 = m366[1]; u64 v_c117 = m366[2];
          if (!slog::exists_probe<5,1>(mbranchindex291, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index292, std::array<u64,9>{v_c10, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index293, std::array<u64,10>{v_c10, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex294, mp_uniondelta309, std::array<u64,3>{v_c117, 0, 0}, [&](const std::array<u64,3>& m367) {
            u64 v_c118 = m367[1]; u64 v_c119 = m367[2];
            if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index295, std::array<u64,9>{v_c118, v_c10, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index296, std::array<u64,10>{v_c118, v_c10, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex297, mbranchdelta310, std::array<u64,5>{v_c10, v_c119, 0, 0, 0}, [&](const std::array<u64,5>& m368) {
              u64 v_c15 = m368[2]; u64 v_c14 = m368[3]; u64 v_c16 = m368[4];
              if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index298, std::array<u64,10>{v_c10, v_c14, v_c15, v_c16, v_c118, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex299, std::array<u64,3>{v_c14, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex300, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe_old<9,5>($sup5638x95x0x0x0index301, $sup5638x95x0x0x0delta311, std::array<u64,9>{v_c10, v_c14, v_c15, v_c16, v_c118, 0, 0, 0, 0}, [&](const std::array<u64,9>& m369) {
                u64 v_c29 = m369[5]; u64 v_c28 = m369[6]; u64 v_c30 = m369[7]; u64 v_c31 = m369[8];
                u64 v_c120 = _prim_lt(db, v_c29, v_c14);
                if (v_c120 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                if (!v_c120) return;
                if (!slog::exists_probe<5,5>(mbranchindex302, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, v_c117})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex303, std::array<u64,3>{v_c28, v_c14, 0})) return;
                slog::join_probe_old<10,9>($sup5638x95x0x0x1index304, $sup5638x95x0x0x1delta312, std::array<u64,10>{v_c10, v_c14, v_c15, v_c16, v_c118, v_c29, v_c28, v_c30, v_c31, 0}, [&](const std::array<u64,10>& m371) {
                  u64 v_c121 = m371[9];
                  slog::join_probe_old<5,5>(mbranchindex305, mbranchdelta313, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, v_c117}, [&](const std::array<u64,5>& m372) {
                    slog::join_probe_old<3,3>(mp_mskindex306, mp_mskdelta314, std::array<u64,3>{v_c28, v_c14, v_c121}, [&](const std::array<u64,3>& m373) {
                      slog::join_probe<2,2>(mp_msk_ansindex307, std::array<u64,2>{v_c121, v_c15}, [&](const std::array<u64,2>& m374) {
                        u64 v_c122 = _prim_band(db, v_c28, v_c14);
                        if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c123 = _prim_lt(db, v_c122, v_c115);
                        if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c123) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c118, v_c7, v_c14, v_c15, v_c16});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c7, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask315* _cont = new ReadTask315(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask315(db,b), false);
  // (crule (pre) (scan temp1Gnx1042 l m p r u) (body (join mbranch (1 2 3 4 0) 4 p m l r __t9u4W344)) (head (mkstruct mp_union (1 2 0) __7oYX713 __t9u4W344 u)) map.slog:105 #f)
  class ReadTask377 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex376;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp1Gnx1042");
      std::vector<u16> ord378({1, 2, 3, 4, 0});
      slog::Relation* readrel379 = db->getRelation("mbranch");
      mbranchindex376 = readrel379->getIndex(ord378, false);
  
    }
    ReadTask377(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c16 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe<5,4>(mbranchindex376, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0}, [&](const std::array<u64,5>& m380) {
          u64 v_c124 = m380[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c124, v_c30}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:temp1Gnx1042", _fires);
  
      if (!_done)
      {
        ReadTask377* _cont = new ReadTask377(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask377(db,b), false);
  // (crule (pre) (scan mleaf __t4U3g195 k v) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t4U3g195 t __t2xZH196)) (head (mkstruct mp_put (1 2 3 0) __6ToP809 t k v)) map.slog:92 #f)
  class ReadTask383 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex381;  slog::Index** mp_uniondelta382;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("mp_union");
      mp_unionindex381 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 0});
      slog::Relation* readrel387 = db->getRelation("mp_union");
      mp_uniondelta382 = readrel387->getIndex(ord386, true);
  
    }
    ReadTask383(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe_old<3,1>(mp_unionindex381, mp_uniondelta382, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m388) {
          u64 v_c89 = m388[1]; u64 v_c126 = m388[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c89, v_c11, v_c31}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask383* _cont = new ReadTask383(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask383(db,b), false);
  // (crule (pre) (scan mp_put_ans __t3dD4242 r) (body (join-old mp_put (0 1 2 3) 1 (0 1 2 3) __t3dD4242 t k v) (exists mp_union (2 0 1) 1 t) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t7TCq240) (join-old mp_union (1 2 0) 2 (1 2 0) __t7TCq240 t __t9sO9241)) (head (emit mp_union_ans (0 1) __t9sO9241 r)) map.slog:92 #f)
  class ReadTask396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex389;  slog::Index** mp_unionindex390;  slog::Index** mleafindex391;  slog::Index** mp_unionindex392;  slog::Index** mp_putdelta393;  slog::Index** mleafdelta394;  slog::Index** mp_uniondelta395;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord397({0, 1});
      slog::Relation* readrel398 = db->getRelation("mp_union_ans");
      head_index[0] = readrel398->getIndex(ord397, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord399({0, 1, 2, 3});
      slog::Relation* readrel400 = db->getRelation("mp_put");
      mp_putindex389 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({0, 1, 2, 3});
      slog::Relation* readrel402 = db->getRelation("mp_put");
      mp_putdelta393 = readrel402->getIndex(ord401, true);
      std::vector<u16> ord403({2, 0, 1});
      slog::Relation* readrel404 = db->getRelation("mp_union");
      mp_unionindex390 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("mleaf");
      mleafindex391 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 0});
      slog::Relation* readrel408 = db->getRelation("mleaf");
      mleafdelta394 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({1, 2, 0});
      slog::Relation* readrel410 = db->getRelation("mp_union");
      mp_unionindex392 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("mp_union");
      mp_uniondelta395 = readrel412->getIndex(ord411, true);
  
    }
    ReadTask396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex389, mp_putdelta393, std::array<u64,4>{v_c90, 0, 0, 0}, [&](const std::array<u64,4>& m413) {
          u64 v_c89 = m413[1]; u64 v_c11 = m413[2]; u64 v_c31 = m413[3];
          if (!slog::exists_probe<3,1>(mp_unionindex390, std::array<u64,3>{v_c89, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex391, mleafdelta394, std::array<u64,3>{v_c11, v_c31, 0}, [&](const std::array<u64,3>& m414) {
            u64 v_c88 = m414[2];
            slog::join_probe_old<3,2>(mp_unionindex392, mp_uniondelta395, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m415) {
              u64 v_c87 = m415[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c16}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask396* _cont = new ReadTask396(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask396(db,b), false);
  // (crule (pre (let __trid2sEh857 const07d7fbed0aba019c07f7eb8a) (let __trel14Rx858 const20347926ddb307a8e2bdb71b) (let __tcol5gMF859 const4e07408562bedb8b60ce05c1)) (scan mp_del __t13lF142 l k) (body (exists $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t13lF142 __v0) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists mp_msk_ans (1 0) 1 p) (join mp_msk (1 2 0) 2 k m __t7Ifn141) (join mp_msk_ans (0 1) 2 __t7Ifn141 p)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2sEh857 __trel14Rx858 __tcol5gMF859 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __3uQ5856 p m __v0 r)) map.slog:83 #f)
  class ReadTask426 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index416;  slog::Index** mp_mskindex417;  slog::Index** mp_del_ansindex418;  slog::Index** $sup5638x82x0x0x0index419;  slog::Index** mp_msk_ansindex420;  slog::Index** mp_mskindex421;  slog::Index** mp_msk_ansindex422;
    u32 sid424;  u32 sid423;  u32 sid425;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord427({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel428 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index416 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("mp_msk");
      mp_mskindex417 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("mp_del_ans");
      mp_del_ansindex418 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel434 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index419 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 0});
      slog::Relation* readrel436 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex420 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({1, 2, 0});
      slog::Relation* readrel438 = db->getRelation("mp_msk");
      mp_mskindex421 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex422 = readrel440->getIndex(ord439, false);
      sid424 = db->getRelation("_enum")->getStructId();
      sid423 = db->getRelation("mbranch")->getStructId();
      sid425 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask426(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c127 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c128 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c129 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index416, std::array<u64,6>{v_c11, v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex417, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex418, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m441) {
          u64 v_c7 = m441[1];
          slog::join_probe<6,2>($sup5638x82x0x0x0index419, std::array<u64,6>{v_c11, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,6>& m442) {
            u64 v_c96 = m442[2]; u64 v_c14 = m442[3]; u64 v_c15 = m442[4]; u64 v_c16 = m442[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex420, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe<3,2>(mp_mskindex421, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m443) {
              u64 v_c131 = m443[2];
              slog::join_probe<2,2>(mp_msk_ansindex422, std::array<u64,2>{v_c131, v_c15}, [&](const std::array<u64,2>& m444) {
                ++_fires;
                if (!((is_struct(v_c16) && (decode_struct_id(v_c16) == sid423 || decode_struct_id(v_c16) == sid424 || decode_struct_id(v_c16) == sid425))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c127, v_c128, v_c129, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c7, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask426* _cont = new ReadTask426(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask426(db,b), false);
  // (crule (pre) (scan temp2oEt1084 __t0Ny888) (body) (head (mkstruct mp_hsb (1 0) __4Y3D679 __t0Ny888)) map.slog:19 #f)
  class ReadTask445 : public slog::Task
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
      outer_rel = db->getRelation("temp2oEt1084");
  
    }
    ReadTask445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:temp2oEt1084", _fires);
  
      if (!_done)
      {
        ReadTask445* _cont = new ReadTask445(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask445(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_msk __t7ikb408 k m) (body (exists $sup5638x84x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (2 1 4 0 3) 1 m) (join mp_msk_ans (0 1) 1 __t7ikb408 p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_bld (1 2 3 4 0) 2 p m) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __t01YW404 l r) (exists mp_del (0 2 1) 2 __t01YW404 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_del (1 2 0) 2 r k) (join mbranch (1 2 3 4 0) 4 p m l r __t0VzH403) (join mp_del (0 2 1) 3 __t01YW404 k __t0VzH403) (join mp_bld (1 2 3 4 0) 3 p m l __v0 __t8Ai5407) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join mp_del_ans (0 1) 2 __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index446;  slog::Index** mbranchindex447;  slog::Index** mp_delindex448;  slog::Index** mp_bldindex449;  slog::Index** mp_msk_ansindex450;  slog::Index** mbranchindex451;  slog::Index** mp_bldindex452;  slog::Index** $sup5638x84x0x0x0index453;  slog::Index** mp_delindex454;  slog::Index** mp_bldindex455;  slog::Index** mp_delindex456;  slog::Index** mbranchindex457;  slog::Index** mp_delindex458;  slog::Index** mp_bldindex459;  slog::Index** mp_del_ansindex460;  slog::Index** mp_bld_ansindex461;  slog::Index** mp_delindex462;  slog::Index** mp_del_ansindex463;  slog::Index** mp_bld_ansindex464;  slog::Index** mp_deldelta465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("mp_del_ans");
      head_index[0] = readrel468->getIndex(ord467, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord469({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel470 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index446 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({2, 0, 1, 3, 4});
      slog::Relation* readrel472 = db->getRelation("mbranch");
      mbranchindex447 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({2, 0, 1});
      slog::Relation* readrel474 = db->getRelation("mp_del");
      mp_delindex448 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({2, 1, 4, 0, 3});
      slog::Relation* readrel476 = db->getRelation("mp_bld");
      mp_bldindex449 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex450 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 4, 0});
      slog::Relation* readrel480 = db->getRelation("mbranch");
      mbranchindex451 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 2, 3, 4, 0});
      slog::Relation* readrel482 = db->getRelation("mp_bld");
      mp_bldindex452 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel484 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index453 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 2, 1});
      slog::Relation* readrel486 = db->getRelation("mp_del");
      mp_delindex454 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 2, 3, 4, 0});
      slog::Relation* readrel488 = db->getRelation("mp_bld");
      mp_bldindex455 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 2, 0});
      slog::Relation* readrel490 = db->getRelation("mp_del");
      mp_delindex456 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 2, 3, 4, 0});
      slog::Relation* readrel492 = db->getRelation("mbranch");
      mbranchindex457 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({0, 2, 1});
      slog::Relation* readrel494 = db->getRelation("mp_del");
      mp_delindex458 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 3, 4, 0});
      slog::Relation* readrel496 = db->getRelation("mp_bld");
      mp_bldindex459 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 0});
      slog::Relation* readrel498 = db->getRelation("mp_del_ans");
      mp_del_ansindex460 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex461 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("mp_del");
      mp_delindex462 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("mp_del");
      mp_deldelta465 = readrel504->getIndex(ord503, true);
      std::vector<u16> ord505({0, 1});
      slog::Relation* readrel506 = db->getRelation("mp_del_ans");
      mp_del_ansindex463 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex464 = readrel508->getIndex(ord507, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index446, std::array<u64,6>{v_c11, v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex447, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex448, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex449, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex450, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m509) {
          u64 v_c15 = m509[1];
          if (!slog::exists_probe<5,2>(mbranchindex451, std::array<u64,5>{v_c15, v_c14, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex452, std::array<u64,5>{v_c15, v_c14, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x84x0x0x0index453, std::array<u64,6>{v_c11, v_c14, v_c15, 0, 0, 0}, [&](const std::array<u64,6>& m510) {
            u64 v_c134 = m510[3]; u64 v_c10 = m510[4]; u64 v_c16 = m510[5];
            if (!slog::exists_probe<3,2>(mp_delindex454, std::array<u64,3>{v_c134, v_c11, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex455, std::array<u64,5>{v_c15, v_c14, v_c10, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex456, std::array<u64,3>{v_c16, v_c11, 0})) return;
            slog::join_probe<5,4>(mbranchindex457, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0}, [&](const std::array<u64,5>& m511) {
              u64 v_c135 = m511[4];
              slog::join_probe<3,3>(mp_delindex458, std::array<u64,3>{v_c134, v_c11, v_c135}, [&](const std::array<u64,3>& m512) {
                slog::join_probe<5,3>(mp_bldindex459, std::array<u64,5>{v_c15, v_c14, v_c10, 0, 0}, [&](const std::array<u64,5>& m513) {
                  u64 v_c7 = m513[3]; u64 v_c136 = m513[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex460, std::array<u64,2>{v_c7, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex461, std::array<u64,2>{v_c136, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex462, mp_deldelta465, std::array<u64,3>{v_c16, v_c11, 0}, [&](const std::array<u64,3>& m514) {
                    u64 v_c137 = m514[2];
                    slog::join_probe<2,2>(mp_del_ansindex463, std::array<u64,2>{v_c137, v_c7}, [&](const std::array<u64,2>& m515) {
                      slog::join_probe<2,1>(mp_bld_ansindex464, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m516) {
                        u64 v_c138 = m516[1];
                        u64 v_c139 = _prim_band(db, v_c11, v_c14);
                        if (v_c139 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c140 = _prim_gt(db, v_c139, v_c132);
                        if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c140) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c138}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst1DnK387 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x0 __d0 p0 p1 t0 t1) (body (join-old mp_hsb_ans (0 1) 0 (0 1) __t5Ake386 __v0) (let __t1scf385 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t5Ake386 __t1scf385) (let __t9zeu388 (band p0 __v0)) (cmp lt __t9zeu388 __tconst1DnK387)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t5Ake386 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask522 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex518;  slog::Index** mp_hsbindex519;  slog::Index** mp_hsb_ansdelta520;  slog::Index** mp_hsbdelta521;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord523({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel524 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel524->getIndex(ord523, false);
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord525({0, 1});
      slog::Relation* readrel526 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex518 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta520 = readrel528->getIndex(ord527, true);
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("mp_hsb");
      mp_hsbindex519 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1});
      slog::Relation* readrel532 = db->getRelation("mp_hsb");
      mp_hsbdelta521 = readrel532->getIndex(ord531, true);
  
    }
    ReadTask522(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c75 = _t[2];
        u64 v_c74 = _t[3];
        u64 v_c76 = _t[4];
        slog::join_all_old<2>(mp_hsb_ansindex518, mp_hsb_ansdelta520, [&](const std::array<u64,2>& m533) {
          u64 v_c142 = m533[0]; u64 v_c7 = m533[1];
          u64 v_c143 = _prim_bxor(db, v_c73, v_c75);
          if (v_c143 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex519, mp_hsbdelta521, std::array<u64,2>{v_c142, v_c143}, [&](const std::array<u64,2>& m534) {
            u64 v_c144 = _prim_band(db, v_c73, v_c7);
            if (v_c144 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c145 = _prim_lt(db, v_c144, v_c141);
            if (v_c145 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c145) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c142, v_c7, v_c96, v_c73, v_c75, v_c74, v_c76}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask522* _cont = new ReadTask522(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask522(db,b), false);
  // (crule (pre) (scan temp5A4p1059 __t0ekw284 __v0 l m p) (body (join mbranch (1 2 3 4 0) 4 p m l __v0 __t4v0n282)) (head (emit mp_put_ans (0 1) __t0ekw284 __t4v0n282)) map.slog:43 #f)
  class ReadTask537 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex536;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord538({0, 1});
      slog::Relation* readrel539 = db->getRelation("mp_put_ans");
      head_index[0] = readrel539->getIndex(ord538, false);
      outer_rel = db->getRelation("temp5A4p1059");
      std::vector<u16> ord540({1, 2, 3, 4, 0});
      slog::Relation* readrel541 = db->getRelation("mbranch");
      mbranchindex536 = readrel541->getIndex(ord540, false);
  
    }
    ReadTask537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        slog::join_probe<5,4>(mbranchindex536, std::array<u64,5>{v_c15, v_c14, v_c10, v_c7, 0}, [&](const std::array<u64,5>& m542) {
          u64 v_c147 = m542[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c146, v_c147}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:temp5A4p1059", _fires);
  
      if (!_done)
      {
        ReadTask537* _cont = new ReadTask537(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask537(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t6JeD58 __v2) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t6JeD58 p0 __v1) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x25x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join-old mp_hsb_ans (1 0) 1 (1 0) __v1 __t2bXu55) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t2bXu55) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t2bXu55) (exists mp_hsb_ans (0 1) 1 __t2bXu55) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v3) (join $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t2bXu55 __v1 __v3 p0 __t6Puw51 dup3kne1056 dup92Cz1057 __v0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v0) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask564 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex543;  slog::Index** $sup5638x25x0x0x2index544;  slog::Index** $sup5638x25x0x0x1index545;  slog::Index** $sup5638x25x0x0x0index546;  slog::Index** mp_joinindex547;  slog::Index** mp_hsb_ansindex548;  slog::Index** $sup5638x25x0x0x2index549;  slog::Index** $sup5638x25x0x0x1index550;  slog::Index** mp_hsb_ansindex551;  slog::Index** mp_hsb_ansindex552;  slog::Index** $sup5638x25x0x0x2index553;  slog::Index** $sup5638x25x0x0x1index554;  slog::Index** $sup5638x25x0x0x0index555;  slog::Index** mp_joinindex556;  slog::Index** mp_hsb_ansindex557;  slog::Index** mp_hsbindex558;  slog::Index** mp_mskdelta559;  slog::Index** mp_hsb_ansdelta560;  slog::Index** mp_joindelta561;  slog::Index** mp_hsb_ansdelta562;  slog::Index** mp_hsbdelta563;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord565({0, 1, 2});
      slog::Relation* readrel566 = db->getRelation("mp_msk");
      mp_mskindex543 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1, 2});
      slog::Relation* readrel568 = db->getRelation("mp_msk");
      mp_mskdelta559 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel570 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index544 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel572 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index545 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 0, 2, 3, 4});
      slog::Relation* readrel574 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index546 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 3, 4, 0});
      slog::Relation* readrel576 = db->getRelation("mp_join");
      mp_joinindex547 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 0});
      slog::Relation* readrel578 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex548 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta560 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel582 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index549 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel584 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index550 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex551 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex552 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel590 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index553 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel592 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index554 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 0, 2, 3, 4});
      slog::Relation* readrel594 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index555 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 2, 3, 4, 0});
      slog::Relation* readrel596 = db->getRelation("mp_join");
      mp_joinindex556 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 2, 3, 4, 0});
      slog::Relation* readrel598 = db->getRelation("mp_join");
      mp_joindelta561 = readrel598->getIndex(ord597, true);
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex557 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta562 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("mp_hsb");
      mp_hsbindex558 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1});
      slog::Relation* readrel606 = db->getRelation("mp_hsb");
      mp_hsbdelta563 = readrel606->getIndex(ord605, true);
  
    }
    ReadTask564(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c149 = _t[0];
        u64 v_c83 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex543, mp_mskdelta559, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m607) {
          u64 v_c73 = m607[1]; u64 v_c80 = m607[2];
          if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index544, std::array<u64,11>{v_c80, v_c73, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index545, std::array<u64,7>{v_c73, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup5638x25x0x0x0index546, std::array<u64,5>{v_c73, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex547, std::array<u64,5>{v_c73, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex548, mp_hsb_ansdelta560, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m608) {
            u64 v_c150 = m608[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index549, std::array<u64,11>{v_c80, v_c73, v_c150, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index550, std::array<u64,7>{v_c73, v_c150, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex551, std::array<u64,2>{v_c150, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex552, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m609) {
              u64 v_c81 = m609[1];
              slog::join_probe<11,4>($sup5638x25x0x0x2index553, std::array<u64,11>{v_c150, v_c80, v_c81, v_c73, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m610) {
                u64 v_c151 = m610[4]; u64 v_c152 = m610[5]; u64 v_c153 = m610[6]; u64 v_c7 = m610[7]; u64 v_c75 = m610[8]; u64 v_c74 = m610[9]; u64 v_c76 = m610[10];
                if (v_c150 != v_c153) return;
                if (v_c150 != v_c152) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index554, std::array<u64,7>{v_c151, v_c73, v_c75, v_c74, v_c76, v_c150, v_c7}, [&](const std::array<u64,7>& m611) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index555, std::array<u64,5>{v_c73, v_c151, v_c75, v_c74, v_c76}, [&](const std::array<u64,5>& m612) {
                    slog::join_probe_old<5,5>(mp_joinindex556, mp_joindelta561, std::array<u64,5>{v_c73, v_c74, v_c75, v_c76, v_c151}, [&](const std::array<u64,5>& m613) {
                      slog::join_probe_old<2,2>(mp_hsb_ansindex557, mp_hsb_ansdelta562, std::array<u64,2>{v_c150, v_c7}, [&](const std::array<u64,2>& m614) {
                        u64 v_c154 = _prim_bxor(db, v_c73, v_c75);
                        if (v_c154 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex558, mp_hsbdelta563, std::array<u64,2>{v_c150, v_c154}, [&](const std::array<u64,2>& m615) {
                          u64 v_c155 = _prim_band(db, v_c73, v_c7);
                          if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c156 = _prim_lt(db, v_c155, v_c148);
                          if (v_c156 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c156) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c151, v_c83, v_c81, v_c74, v_c76});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c83, v_c81, v_c74, v_c76}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask564* _cont = new ReadTask564(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask564(db,b), false);
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x0 __t38nk104 l m n p q r u v) (body (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 u) (join-old $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t38nk104 l m p r __t3jH2107) (exists mp_msk (1 2 0) 3 p n __t3jH2107) (exists mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t9OKP102) (exists mp_union (2 0 1) 2 __t9OKP102 __t38nk104) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_union (0 1 2) 3 (0 1 2) __t38nk104 __t6XhK108 __t9OKP102) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask639 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex617;  slog::Index** mbranchindex618;  slog::Index** mp_mskindex619;  slog::Index** mp_msk_ansindex620;  slog::Index** mp_unionindex621;  slog::Index** $sup5638x104x0x0x1index622;  slog::Index** mp_mskindex623;  slog::Index** mp_msk_ansindex624;  slog::Index** mbranchindex625;  slog::Index** mp_unionindex626;  slog::Index** mbranchindex627;  slog::Index** mp_unionindex628;  slog::Index** mp_mskindex629;  slog::Index** mp_msk_ansindex630;  slog::Index** mp_unionindex631;  slog::Index** mp_union_ansindex632;  slog::Index** $sup5638x104x0x0x1delta633;  slog::Index** mbranchdelta634;  slog::Index** mbranchdelta635;  slog::Index** mp_uniondelta636;  slog::Index** mp_mskdelta637;  slog::Index** mp_uniondelta638;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord640({1, 2, 3, 4, 0});
      slog::Relation* readrel641 = db->getRelation("mbranch");
      mbranchindex617 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 3, 4, 0});
      slog::Relation* readrel643 = db->getRelation("mbranch");
      mbranchindex618 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("mp_msk");
      mp_mskindex619 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0});
      slog::Relation* readrel647 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex620 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({2, 0, 1});
      slog::Relation* readrel649 = db->getRelation("mp_union");
      mp_unionindex621 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel651 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index622 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel653 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta633 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("mp_msk");
      mp_mskindex623 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex624 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 2, 3, 4, 0});
      slog::Relation* readrel659 = db->getRelation("mbranch");
      mbranchindex625 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 3, 4, 0});
      slog::Relation* readrel661 = db->getRelation("mbranch");
      mbranchdelta634 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({2, 0, 1});
      slog::Relation* readrel663 = db->getRelation("mp_union");
      mp_unionindex626 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 3, 4, 0});
      slog::Relation* readrel665 = db->getRelation("mbranch");
      mbranchindex627 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 3, 4, 0});
      slog::Relation* readrel667 = db->getRelation("mbranch");
      mbranchdelta635 = readrel667->getIndex(ord666, true);
      std::vector<u16> ord668({0, 1, 2});
      slog::Relation* readrel669 = db->getRelation("mp_union");
      mp_unionindex628 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({0, 1, 2});
      slog::Relation* readrel671 = db->getRelation("mp_union");
      mp_uniondelta636 = readrel671->getIndex(ord670, true);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("mp_msk");
      mp_mskindex629 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 0});
      slog::Relation* readrel675 = db->getRelation("mp_msk");
      mp_mskdelta637 = readrel675->getIndex(ord674, true);
      std::vector<u16> ord676({0, 1});
      slog::Relation* readrel677 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex630 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("mp_union");
      mp_unionindex631 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("mp_union");
      mp_uniondelta638 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("mp_union_ans");
      mp_union_ansindex632 = readrel683->getIndex(ord682, false);
  
    }
    ReadTask639(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c16 = _t[6];
        u64 v_c30 = _t[7];
        u64 v_c31 = _t[8];
        u64 v_c159 = _prim_lt(db, v_c14, v_c29);
        if (v_c159 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
        if (!v_c159) return;
        if (!slog::exists_probe<5,4>(mbranchindex617, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex618, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex619, std::array<u64,3>{v_c15, v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex620, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex621, std::array<u64,3>{v_c30, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x104x0x0x1index622, $sup5638x104x0x0x1delta633, std::array<u64,10>{v_c30, v_c29, v_c28, v_c31, v_c158, v_c10, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,10>& m685) {
          u64 v_c160 = m685[9];
          if (!slog::exists_probe<3,3>(mp_mskindex623, std::array<u64,3>{v_c15, v_c29, v_c160})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex624, std::array<u64,2>{v_c160, v_c28})) return;
          slog::join_probe_old<5,4>(mbranchindex625, mbranchdelta634, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m686) {
            u64 v_c161 = m686[4];
            if (!slog::exists_probe<3,2>(mp_unionindex626, std::array<u64,3>{v_c161, v_c158, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex627, mbranchdelta635, std::array<u64,5>{v_c15, v_c14, v_c10, v_c16, 0}, [&](const std::array<u64,5>& m687) {
              u64 v_c162 = m687[4];
              slog::join_probe_old<3,3>(mp_unionindex628, mp_uniondelta636, std::array<u64,3>{v_c158, v_c162, v_c161}, [&](const std::array<u64,3>& m688) {
                slog::join_probe_old<3,3>(mp_mskindex629, mp_mskdelta637, std::array<u64,3>{v_c15, v_c29, v_c160}, [&](const std::array<u64,3>& m689) {
                  slog::join_probe<2,2>(mp_msk_ansindex630, std::array<u64,2>{v_c160, v_c28}, [&](const std::array<u64,2>& m690) {
                    slog::join_probe_old<3,2>(mp_unionindex631, mp_uniondelta638, std::array<u64,3>{v_c162, v_c30, 0}, [&](const std::array<u64,3>& m691) {
                      u64 v_c163 = m691[2];
                      slog::join_probe<2,1>(mp_union_ansindex632, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m692) {
                        u64 v_c7 = m692[1];
                        u64 v_c164 = _prim_band(db, v_c15, v_c29);
                        if (v_c164 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c165 = _prim_lt(db, v_c164, v_c157);
                        if (v_c165 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c165) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c158, v_c7, v_c29, v_c28, v_c31});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c29, v_c7, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
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
}

