
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const3b5b774db59f55c2fdaef73a;
extern u64 v_const3cd26ab9ce3085a816a74a29;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const9cfb09b7c00913be7566a50e;
extern u64 v_constc742e02805b99df617265a41;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constfee494ff4827aeb0635bb714;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_cb43d5e633d046d7f(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan mp_msk __t1WO0167 k m) (body (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 2 k m) (join mp_msk_ans (0 1) 1 __t1WO0167 p) (join $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t1WO0167 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index0;  slog::Index** mp_msk_ansindex1;  slog::Index** $sup5638x42x0x0x0index2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord4({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel5 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord6({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel7 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel11 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index2 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<7,2>($sup5638x42x0x0x0index0, std::array<u64,7>{v_c1, v_c2, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c3 = m12[1];
          slog::join_probe<7,3>($sup5638x42x0x0x0index2, std::array<u64,7>{v_c1, v_c2, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,7>& m13) {
            u64 v_c4 = m13[3]; u64 v_c5 = m13[4]; u64 v_c6 = m13[5]; u64 v_c7 = m13[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c0, v_c3, v_c4, v_c1, v_c5, v_c2, v_c6, v_c7}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t4QPc174 p) (body (exists $sup5638x60x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4QPc174 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x60x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t5APc170 l r) (exists mp_has0 (0 2 1) 2 __t5APc170 k) (exists mp_has0 (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4G6v169) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t5APc170 k __t4G6v169) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t8KSH173) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index14;  slog::Index** mbranchindex15;  slog::Index** mp_mskindex16;  slog::Index** mbranchindex17;  slog::Index** mp_has0index18;  slog::Index** $sup5638x60x0x0x0index19;  slog::Index** mp_has0index20;  slog::Index** mp_has0index21;  slog::Index** mbranchindex22;  slog::Index** mp_has0index23;  slog::Index** mp_has0index24;  slog::Index** mp_has0_ansindex25;  slog::Index** mp_mskdelta26;  slog::Index** $sup5638x60x0x0x0delta27;  slog::Index** mbranchdelta28;  slog::Index** mp_has0delta29;  slog::Index** mp_has0delta30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord34({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel35 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index14 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 3, 4, 0});
      slog::Relation* readrel37 = db->getRelation("mbranch");
      mbranchindex15 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1, 2});
      slog::Relation* readrel39 = db->getRelation("mp_msk");
      mp_mskindex16 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 1, 2});
      slog::Relation* readrel41 = db->getRelation("mp_msk");
      mp_mskdelta26 = readrel41->getIndex(ord40, true);
      std::vector<u16> ord42({1, 2, 3, 4, 0});
      slog::Relation* readrel43 = db->getRelation("mbranch");
      mbranchindex17 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({2, 0, 1});
      slog::Relation* readrel45 = db->getRelation("mp_has0");
      mp_has0index18 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel47 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index19 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel49 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0delta27 = readrel49->getIndex(ord48, true);
      std::vector<u16> ord50({0, 2, 1});
      slog::Relation* readrel51 = db->getRelation("mp_has0");
      mp_has0index20 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("mp_has0");
      mp_has0index21 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 3, 4, 0});
      slog::Relation* readrel55 = db->getRelation("mbranch");
      mbranchindex22 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 3, 4, 0});
      slog::Relation* readrel57 = db->getRelation("mbranch");
      mbranchdelta28 = readrel57->getIndex(ord56, true);
      std::vector<u16> ord58({0, 2, 1});
      slog::Relation* readrel59 = db->getRelation("mp_has0");
      mp_has0index23 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({0, 2, 1});
      slog::Relation* readrel61 = db->getRelation("mp_has0");
      mp_has0delta29 = readrel61->getIndex(ord60, true);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("mp_has0");
      mp_has0index24 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("mp_has0");
      mp_has0delta30 = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex25 = readrel67->getIndex(ord66, false);
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x60x0x0x0index14, std::array<u64,6>{v_c3, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex15, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex16, mp_mskdelta26, std::array<u64,3>{v_c9, 0, 0}, [&](const std::array<u64,3>& m68) {
          u64 v_c1 = m68[1]; u64 v_c2 = m68[2];
          if (!slog::exists_probe<5,2>(mbranchindex17, std::array<u64,5>{v_c3, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index18, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x60x0x0x0index19, $sup5638x60x0x0x0delta27, std::array<u64,6>{v_c1, v_c2, v_c3, 0, 0, 0}, [&](const std::array<u64,6>& m69) {
            u64 v_c10 = m69[3]; u64 v_c5 = m69[4]; u64 v_c6 = m69[5];
            if (!slog::exists_probe<3,2>(mp_has0index20, std::array<u64,3>{v_c10, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index21, std::array<u64,3>{v_c5, v_c1, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex22, mbranchdelta28, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m70) {
              u64 v_c11 = m70[4];
              slog::join_probe_old<3,3>(mp_has0index23, mp_has0delta29, std::array<u64,3>{v_c10, v_c1, v_c11}, [&](const std::array<u64,3>& m71) {
                slog::join_probe_old<3,2>(mp_has0index24, mp_has0delta30, std::array<u64,3>{v_c5, v_c1, 0}, [&](const std::array<u64,3>& m72) {
                  u64 v_c12 = m72[2];
                  slog::join_probe<2,1>(mp_has0_ansindex25, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m73) {
                    u64 v_c13 = m73[1];
                    u64 v_c14 = _prim_band(db, v_c1, v_c2);
                    if (v_c14 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c15 = _prim_lt(db, v_c14, v_c8);
                    if (v_c15 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c15) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c13}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), false);
  // (crule (pre) (scan mleaf __t2G14362 k w) (body (join-old mp_put (1 2 0 3) 2 (1 2 0 3) __t2G14362 k __t2UPk363 v)) (head (emit-temp temp4cOw1069 __t2UPk363 k v) (mkstruct mleaf (1 2 0) __t9j1T361 k v)) map.slog:38 #f)
  class ReadTask77 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex75;  slog::Index** mp_putdelta76;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4cOw1069");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord78({1, 2, 0, 3});
      slog::Relation* readrel79 = db->getRelation("mp_put");
      mp_putindex75 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0, 3});
      slog::Relation* readrel81 = db->getRelation("mp_put");
      mp_putdelta76 = readrel81->getIndex(ord80, true);
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe_old<4,2>(mp_putindex75, mp_putdelta76, std::array<u64,4>{v_c16, v_c1, 0, 0}, [&](const std::array<u64,4>& m82) {
          u64 v_c18 = m82[2]; u64 v_c7 = m82[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c18, v_c1, v_c7});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c7}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask77* _cont = new ReadTask77(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask77(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_del_ans __t5pOj159 __v0) (body (exists mp_bld (3 0 1 2 4) 1 __v0) (join-old mp_del (0 2 1) 1 (0 2 1) __t5pOj159 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t8KQn154 m p r) (exists mp_bld (1 2 3 4 0) 4 p m __v0 r) (exists mp_del (0 2 1) 2 __t8KQn154 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t85IU153) (exists mp_del (0 2 1) 3 __t8KQn154 k __t85IU153) (join-old mp_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m __v0 r __t0Lvo157) (join-old mp_del (0 2 1) 3 (0 2 1) __t8KQn154 k __t85IU153) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask107 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex83;  slog::Index** mp_delindex84;  slog::Index** mbranchindex85;  slog::Index** mp_delindex86;  slog::Index** mp_mskindex87;  slog::Index** $sup5638x82x0x0x0index88;  slog::Index** mp_bldindex89;  slog::Index** mp_delindex90;  slog::Index** mp_mskindex91;  slog::Index** mp_msk_ansindex92;  slog::Index** mbranchindex93;  slog::Index** mp_delindex94;  slog::Index** mp_bldindex95;  slog::Index** mp_delindex96;  slog::Index** mp_bld_ansindex97;  slog::Index** mp_mskindex98;  slog::Index** mp_msk_ansindex99;  slog::Index** mp_bld_ansindex100;  slog::Index** mp_deldelta101;  slog::Index** $sup5638x82x0x0x0delta102;  slog::Index** mbranchdelta103;  slog::Index** mp_blddelta104;  slog::Index** mp_deldelta105;  slog::Index** mp_mskdelta106;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord108({0, 1});
      slog::Relation* readrel109 = db->getRelation("mp_del_ans");
      head_index[0] = readrel109->getIndex(ord108, false);
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord110({3, 0, 1, 2, 4});
      slog::Relation* readrel111 = db->getRelation("mp_bld");
      mp_bldindex83 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 2, 1});
      slog::Relation* readrel113 = db->getRelation("mp_del");
      mp_delindex84 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 2, 1});
      slog::Relation* readrel115 = db->getRelation("mp_del");
      mp_deldelta101 = readrel115->getIndex(ord114, true);
      std::vector<u16> ord116({3, 0, 1, 2, 4});
      slog::Relation* readrel117 = db->getRelation("mbranch");
      mbranchindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({2, 0, 1});
      slog::Relation* readrel119 = db->getRelation("mp_del");
      mp_delindex86 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("mp_msk");
      mp_mskindex87 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel123 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index88 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel125 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta102 = readrel125->getIndex(ord124, true);
      std::vector<u16> ord126({1, 2, 3, 4, 0});
      slog::Relation* readrel127 = db->getRelation("mp_bld");
      mp_bldindex89 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 2, 1});
      slog::Relation* readrel129 = db->getRelation("mp_del");
      mp_delindex90 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("mp_msk");
      mp_mskindex91 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex92 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 3, 4, 0});
      slog::Relation* readrel135 = db->getRelation("mbranch");
      mbranchindex93 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 3, 4, 0});
      slog::Relation* readrel137 = db->getRelation("mbranch");
      mbranchdelta103 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({0, 2, 1});
      slog::Relation* readrel139 = db->getRelation("mp_del");
      mp_delindex94 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 3, 4, 0});
      slog::Relation* readrel141 = db->getRelation("mp_bld");
      mp_bldindex95 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 3, 4, 0});
      slog::Relation* readrel143 = db->getRelation("mp_bld");
      mp_blddelta104 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({0, 2, 1});
      slog::Relation* readrel145 = db->getRelation("mp_del");
      mp_delindex96 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 2, 1});
      slog::Relation* readrel147 = db->getRelation("mp_del");
      mp_deldelta105 = readrel147->getIndex(ord146, true);
      std::vector<u16> ord148({0, 1});
      slog::Relation* readrel149 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex97 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 0});
      slog::Relation* readrel151 = db->getRelation("mp_msk");
      mp_mskindex98 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 2, 0});
      slog::Relation* readrel153 = db->getRelation("mp_msk");
      mp_mskdelta106 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex99 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 1});
      slog::Relation* readrel157 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex100 = readrel157->getIndex(ord156, false);
  
    }
    ReadTask107(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<5,1>(mp_bldindex83, std::array<u64,5>{v_c21, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_delindex84, mp_deldelta101, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m158) {
          u64 v_c1 = m158[1]; u64 v_c5 = m158[2];
          if (!slog::exists_probe<5,1>(mbranchindex85, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex86, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex87, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x82x0x0x0index88, $sup5638x82x0x0x0delta102, std::array<u64,6>{v_c1, v_c5, 0, 0, 0, 0}, [&](const std::array<u64,6>& m159) {
            u64 v_c22 = m159[2]; u64 v_c2 = m159[3]; u64 v_c3 = m159[4]; u64 v_c6 = m159[5];
            if (!slog::exists_probe<5,4>(mp_bldindex89, std::array<u64,5>{v_c3, v_c2, v_c21, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex90, std::array<u64,3>{v_c22, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex91, std::array<u64,3>{v_c1, v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex92, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex93, mbranchdelta103, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m160) {
              u64 v_c23 = m160[4];
              if (!slog::exists_probe<3,3>(mp_delindex94, std::array<u64,3>{v_c22, v_c1, v_c23})) return;
              slog::join_probe_old<5,4>(mp_bldindex95, mp_blddelta104, std::array<u64,5>{v_c3, v_c2, v_c21, v_c6, 0}, [&](const std::array<u64,5>& m161) {
                u64 v_c24 = m161[4];
                slog::join_probe_old<3,3>(mp_delindex96, mp_deldelta105, std::array<u64,3>{v_c22, v_c1, v_c23}, [&](const std::array<u64,3>& m162) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex97, std::array<u64,2>{v_c24, 0})) return;
                  slog::join_probe_old<3,2>(mp_mskindex98, mp_mskdelta106, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m163) {
                    u64 v_c25 = m163[2];
                    slog::join_probe<2,2>(mp_msk_ansindex99, std::array<u64,2>{v_c25, v_c3}, [&](const std::array<u64,2>& m164) {
                      slog::join_probe<2,1>(mp_bld_ansindex100, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m165) {
                        u64 v_c26 = m165[1];
                        u64 v_c27 = _prim_band(db, v_c1, v_c2);
                        if (v_c27 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c28 = _prim_lt(db, v_c27, v_c19);
                        if (v_c28 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c28) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c26}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask107* _cont = new ReadTask107(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask107(db,b), false);
  // (crule (pre (let __trid7vEV758 const9cfb09b7c00913be7566a50e) (let __trel46Xw759 const7f254967624b26d820569bd6) (let __tcol74wq760 const5feceb66ffc86f38d952786c) (let __trel7JvA761 const7f254967624b26d820569bd6) (let __tcol6GgZ762 const6b86b273ff34fce19d6b804e)) (scan $sup5638x93x0x0x0 __d0 l m p r u v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7vEV758 __trel46Xw759 __tcol74wq760 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7vEV758 __trel7JvA761 __tcol6GgZ762 (1 2 3 4 0)) (mkstruct mp_union (1 2 0) __07Op757 l u)) map.slog:94 #f)
  class ReadTask170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid168;  u32 sid167;  u32 sid169;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_union");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      sid168 = db->getRelation("_enum")->getStructId();
      sid167 = db->getRelation("mbranch")->getStructId();
      sid169 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const9cfb09b7c00913be7566a50e;
      u64 v_c30 = v_const7f254967624b26d820569bd6;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_const7f254967624b26d820569bd6;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c34 = _t[5];
        u64 v_c7 = _t[6];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid167 || decode_struct_id(v_c5) == sid168 || decode_struct_id(v_c5) == sid169))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c29, v_c30, v_c31, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c34) && (decode_struct_id(v_c34) == sid167 || decode_struct_id(v_c34) == sid168 || decode_struct_id(v_c34) == sid169))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c29, v_c32, v_c33, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c34}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask170* _cont = new ReadTask170(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask170(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t5usA297 q) (body (exists $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t5usA297 p n) (join $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t5usA297 l m n p q r u)) map.slog:108 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index171;  slog::Index** mp_mskindex172;  slog::Index** $sup5638x107x0x0x0index173;  slog::Index** mp_mskdelta174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord176({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel177 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel177->getIndex(ord176, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord178({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel179 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index171 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1, 2});
      slog::Relation* readrel181 = db->getRelation("mp_msk");
      mp_mskindex172 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({0, 1, 2});
      slog::Relation* readrel183 = db->getRelation("mp_msk");
      mp_mskdelta174 = readrel183->getIndex(ord182, true);
      std::vector<u16> ord184({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel185 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index173 = readrel185->getIndex(ord184, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[0];
        u64 v_c36 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index171, std::array<u64,9>{v_c36, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex172, mp_mskdelta174, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m186) {
          u64 v_c3 = m186[1]; u64 v_c37 = m186[2];
          slog::join_probe<9,3>($sup5638x107x0x0x0index173, std::array<u64,9>{v_c37, v_c3, v_c36, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m187) {
            u64 v_c4 = m187[3]; u64 v_c5 = m187[4]; u64 v_c2 = m187[5]; u64 v_c6 = m187[6]; u64 v_c34 = m187[7]; u64 v_c7 = m187[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c4, v_c7, v_c35, v_c5, v_c2, v_c37, v_c3, v_c36, v_c6, v_c34}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t0q1c75 k m) (body (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_msk_ans (0 1) 1 __t0q1c75) (join $sup5638x40x0x0x1 (1 2 4 5 0 3 6 7) 3 __t0q1c75 k m p __t1I5N72 l r v) (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t1I5N72 k v) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join mbranch (1 2 3 4 0) 4 p m l r __t687K71) (join mp_put (1 2 0 3) 4 __t687K71 k __t1I5N72 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index188;  slog::Index** mbranchindex189;  slog::Index** mp_putindex190;  slog::Index** mp_msk_ansindex191;  slog::Index** $sup5638x40x0x0x1index192;  slog::Index** $sup5638x40x0x0x0index193;  slog::Index** mp_putindex194;  slog::Index** mp_putindex195;  slog::Index** mp_msk_ansindex196;  slog::Index** mbranchindex197;  slog::Index** mp_putindex198;  slog::Index** mp_putindex199;  slog::Index** mp_msk_ansindex200;  slog::Index** mp_put_ansindex201;  slog::Index** mp_putdelta202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord204({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel205 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index188 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({2, 0, 1, 3, 4});
      slog::Relation* readrel207 = db->getRelation("mbranch");
      mbranchindex189 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({2, 3, 0, 1});
      slog::Relation* readrel209 = db->getRelation("mp_put");
      mp_putindex190 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex191 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel213 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index192 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel215 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index193 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({2, 3, 0, 1});
      slog::Relation* readrel217 = db->getRelation("mp_put");
      mp_putindex194 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 3, 0});
      slog::Relation* readrel219 = db->getRelation("mp_put");
      mp_putindex195 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex196 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 3, 4, 0});
      slog::Relation* readrel223 = db->getRelation("mbranch");
      mbranchindex197 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0, 3});
      slog::Relation* readrel225 = db->getRelation("mp_put");
      mp_putindex198 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 3, 0});
      slog::Relation* readrel227 = db->getRelation("mp_put");
      mp_putindex199 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 3, 0});
      slog::Relation* readrel229 = db->getRelation("mp_put");
      mp_putdelta202 = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex200 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("mp_put_ans");
      mp_put_ansindex201 = readrel233->getIndex(ord232, false);
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x40x0x0x0index188, std::array<u64,7>{v_c1, v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex189, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex190, std::array<u64,4>{v_c1, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex191, std::array<u64,2>{v_c39, 0})) return;
        slog::join_probe<8,3>($sup5638x40x0x0x1index192, std::array<u64,8>{v_c39, v_c1, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m234) {
          u64 v_c3 = m234[3]; u64 v_c40 = m234[4]; u64 v_c5 = m234[5]; u64 v_c6 = m234[6]; u64 v_c7 = m234[7];
          slog::join_probe<7,7>($sup5638x40x0x0x0index193, std::array<u64,7>{v_c3, v_c5, v_c2, v_c6, v_c40, v_c1, v_c7}, [&](const std::array<u64,7>& m235) {
            if (!slog::exists_probe<4,3>(mp_putindex194, std::array<u64,4>{v_c1, v_c7, v_c40, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex195, std::array<u64,4>{v_c5, v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex196, std::array<u64,2>{v_c39, v_c3})) return;
            slog::join_probe<5,4>(mbranchindex197, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m236) {
              u64 v_c41 = m236[4];
              slog::join_probe<4,4>(mp_putindex198, std::array<u64,4>{v_c41, v_c1, v_c40, v_c7}, [&](const std::array<u64,4>& m237) {
                slog::join_probe_old<4,3>(mp_putindex199, mp_putdelta202, std::array<u64,4>{v_c5, v_c1, v_c7, 0}, [&](const std::array<u64,4>& m238) {
                  u64 v_c42 = m238[3];
                  slog::join_probe<2,2>(mp_msk_ansindex200, std::array<u64,2>{v_c39, v_c3}, [&](const std::array<u64,2>& m239) {
                    slog::join_probe<2,1>(mp_put_ansindex201, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m240) {
                      u64 v_c21 = m240[1];
                      u64 v_c43 = _prim_band(db, v_c1, v_c2);
                      if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c44 = _prim_lt(db, v_c43, v_c38);
                      if (v_c44 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c44) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c40, v_c21, v_c2, v_c3, v_c6});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c2, v_c21, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask203* _cont = new ReadTask203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask203(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mp_put __t7iEH288 r k v) (body (exists $sup5638x42x0x0x1 (2 6 7 0 1 3 4 5) 3 k r v) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put_ans (0 1) 1 __t7iEH288) (join $sup5638x42x0x0x0 (1 5 6 0 2 3 4) 3 k r v __t0ekw284 l m p) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t0ekw284 k v __t8lnB287) (exists mp_msk (1 2 0) 3 k m __t8lnB287) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join mbranch (1 2 3 4 0) 4 p m l r __t07OG283) (join mp_put (1 2 0 3) 4 __t07OG283 k __t0ekw284 v) (join mp_msk (1 2 0) 3 k m __t8lnB287) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask260 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index242;  slog::Index** mbranchindex243;  slog::Index** mp_putindex244;  slog::Index** mp_mskindex245;  slog::Index** mp_put_ansindex246;  slog::Index** $sup5638x42x0x0x0index247;  slog::Index** mbranchindex248;  slog::Index** mp_putindex249;  slog::Index** mp_mskindex250;  slog::Index** mp_msk_ansindex251;  slog::Index** $sup5638x42x0x0x1index252;  slog::Index** mp_mskindex253;  slog::Index** mp_msk_ansindex254;  slog::Index** mbranchindex255;  slog::Index** mp_putindex256;  slog::Index** mp_mskindex257;  slog::Index** mp_msk_ansindex258;  slog::Index** mp_put_ansindex259;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord261({2, 6, 7, 0, 1, 3, 4, 5});
      slog::Relation* readrel262 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index242 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({4, 0, 1, 2, 3});
      slog::Relation* readrel264 = db->getRelation("mbranch");
      mbranchindex243 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({2, 3, 0, 1});
      slog::Relation* readrel266 = db->getRelation("mp_put");
      mp_putindex244 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("mp_msk");
      mp_mskindex245 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("mp_put_ans");
      mp_put_ansindex246 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel272 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index247 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 2, 3, 4, 0});
      slog::Relation* readrel274 = db->getRelation("mbranch");
      mbranchindex248 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({2, 3, 0, 1});
      slog::Relation* readrel276 = db->getRelation("mp_put");
      mp_putindex249 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 0});
      slog::Relation* readrel278 = db->getRelation("mp_msk");
      mp_mskindex250 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 0});
      slog::Relation* readrel280 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex251 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel282 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index252 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 0});
      slog::Relation* readrel284 = db->getRelation("mp_msk");
      mp_mskindex253 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex254 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 3, 4, 0});
      slog::Relation* readrel288 = db->getRelation("mbranch");
      mbranchindex255 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0, 3});
      slog::Relation* readrel290 = db->getRelation("mp_put");
      mp_putindex256 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("mp_msk");
      mp_mskindex257 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex258 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0, 1});
      slog::Relation* readrel296 = db->getRelation("mp_put_ans");
      mp_put_ansindex259 = readrel296->getIndex(ord295, false);
  
    }
    ReadTask260(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c46 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index242, std::array<u64,8>{v_c1, v_c6, v_c7, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex243, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex244, std::array<u64,4>{v_c1, v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex245, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex246, std::array<u64,2>{v_c46, 0})) return;
        slog::join_probe<7,3>($sup5638x42x0x0x0index247, std::array<u64,7>{v_c1, v_c6, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,7>& m297) {
          u64 v_c47 = m297[3]; u64 v_c5 = m297[4]; u64 v_c2 = m297[5]; u64 v_c3 = m297[6];
          if (!slog::exists_probe<5,4>(mbranchindex248, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex249, std::array<u64,4>{v_c1, v_c7, v_c47, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex250, std::array<u64,3>{v_c1, v_c2, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex251, std::array<u64,2>{v_c3, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index252, std::array<u64,8>{v_c5, v_c2, v_c3, v_c6, v_c47, v_c1, v_c7, 0}, [&](const std::array<u64,8>& m298) {
            u64 v_c48 = m298[7];
            if (!slog::exists_probe<3,3>(mp_mskindex253, std::array<u64,3>{v_c1, v_c2, v_c48})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex254, std::array<u64,2>{v_c48, v_c3})) return;
            slog::join_probe<5,4>(mbranchindex255, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m299) {
              u64 v_c49 = m299[4];
              slog::join_probe<4,4>(mp_putindex256, std::array<u64,4>{v_c49, v_c1, v_c47, v_c7}, [&](const std::array<u64,4>& m300) {
                slog::join_probe<3,3>(mp_mskindex257, std::array<u64,3>{v_c1, v_c2, v_c48}, [&](const std::array<u64,3>& m301) {
                  slog::join_probe<2,2>(mp_msk_ansindex258, std::array<u64,2>{v_c48, v_c3}, [&](const std::array<u64,2>& m302) {
                    slog::join_probe<2,1>(mp_put_ansindex259, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m303) {
                      u64 v_c21 = m303[1];
                      u64 v_c50 = _prim_band(db, v_c1, v_c2);
                      if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c51 = _prim_gt(db, v_c50, v_c45);
                      if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c51) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c47, v_c21, v_c5, v_c2, v_c3});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c2, v_c5, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask260* _cont = new ReadTask260(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask260(db,b), false);
  // (crule (pre) (scan mleaf __t4DNq324 j w) (body (exists mp_put (1 2 0 3) 1 __t4DNq324) (join-old mp_join (3 4 1 0 2) 2 (3 4 1 0 2) j __t4DNq324 k __t1dCZ326 __t6sa2325) (neq j k) (exists mp_put (1 2 0 3) 2 __t4DNq324 k) (exists mp_join_ans (0 1) 1 __t1dCZ326) (join-old mleaf (0 1 2) 2 (0 1 2) __t6sa2325 k v) (join mp_put (1 2 3 0) 3 __t4DNq324 k v __t529R323) (join mp_join_ans (0 1) 1 __t1dCZ326 r)) (head (emit mp_put_ans (0 1) __t529R323 r)) map.slog:39 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex305;  slog::Index** mp_joinindex306;  slog::Index** mp_putindex307;  slog::Index** mp_join_ansindex308;  slog::Index** mleafindex309;  slog::Index** mp_putindex310;  slog::Index** mp_join_ansindex311;  slog::Index** mp_joindelta312;  slog::Index** mleafdelta313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord315({0, 1});
      slog::Relation* readrel316 = db->getRelation("mp_put_ans");
      head_index[0] = readrel316->getIndex(ord315, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord317({1, 2, 0, 3});
      slog::Relation* readrel318 = db->getRelation("mp_put");
      mp_putindex305 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({3, 4, 1, 0, 2});
      slog::Relation* readrel320 = db->getRelation("mp_join");
      mp_joinindex306 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({3, 4, 1, 0, 2});
      slog::Relation* readrel322 = db->getRelation("mp_join");
      mp_joindelta312 = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({1, 2, 0, 3});
      slog::Relation* readrel324 = db->getRelation("mp_put");
      mp_putindex307 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({0, 1});
      slog::Relation* readrel326 = db->getRelation("mp_join_ans");
      mp_join_ansindex308 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({0, 1, 2});
      slog::Relation* readrel328 = db->getRelation("mleaf");
      mleafindex309 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 1, 2});
      slog::Relation* readrel330 = db->getRelation("mleaf");
      mleafdelta313 = readrel330->getIndex(ord329, true);
      std::vector<u16> ord331({1, 2, 3, 0});
      slog::Relation* readrel332 = db->getRelation("mp_put");
      mp_putindex310 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({0, 1});
      slog::Relation* readrel334 = db->getRelation("mp_join_ans");
      mp_join_ansindex311 = readrel334->getIndex(ord333, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<4,1>(mp_putindex305, std::array<u64,4>{v_c52, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex306, mp_joindelta312, std::array<u64,5>{v_c53, v_c52, 0, 0, 0}, [&](const std::array<u64,5>& m335) {
          u64 v_c1 = m335[2]; u64 v_c54 = m335[3]; u64 v_c55 = m335[4];
          if (v_c53 == v_c1) return;
          if (!slog::exists_probe<4,2>(mp_putindex307, std::array<u64,4>{v_c52, v_c1, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex308, std::array<u64,2>{v_c54, 0})) return;
          slog::join_probe_old<3,2>(mleafindex309, mleafdelta313, std::array<u64,3>{v_c55, v_c1, 0}, [&](const std::array<u64,3>& m336) {
            u64 v_c7 = m336[2];
            slog::join_probe<4,3>(mp_putindex310, std::array<u64,4>{v_c52, v_c1, v_c7, 0}, [&](const std::array<u64,4>& m337) {
              u64 v_c56 = m337[3];
              slog::join_probe<2,1>(mp_join_ansindex311, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m338) {
                u64 v_c6 = m338[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c6}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre7tFV1009 __errf0tNh1010 __errf0QIH1011 __errf3pxz1012 __errf0W5U1013) (body) (head (emit error (0) __erre7tFV1009)) <internal>:1 #f)
  class ReadTask339 : public slog::Task
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
      std::vector<u16> ord340({0});
      slog::Relation* readrel341 = db->getRelation("error");
      head_index[0] = readrel341->getIndex(ord340, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask339(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c61 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask339* _cont = new ReadTask339(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask339(db,b), false);
  // (crule (pre (let __tconst4J6Y274 const6b86b273ff34fce19d6b804e)) (scan mbranch __t7G5n272 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t7G5n272 __t04rT271 __t8s9M273) (join mbranch (0 1 2 3 4) 1 __t04rT271 q n u v) (cmp lt m n) (let __t2pJK275 (band p n)) (cmp lt __t2pJK275 __tconst4J6Y274)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t8s9M273 u l m n p q r v)) map.slog:105 #f)
  class ReadTask345 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex342;  slog::Index** mbranchindex343;  slog::Index** mp_uniondelta344;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord346({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel347 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel347->getIndex(ord346, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord348({1, 2, 0});
      slog::Relation* readrel349 = db->getRelation("mp_union");
      mp_unionindex342 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("mp_union");
      mp_uniondelta344 = readrel351->getIndex(ord350, true);
      std::vector<u16> ord352({0, 1, 2, 3, 4});
      slog::Relation* readrel353 = db->getRelation("mbranch");
      mbranchindex343 = readrel353->getIndex(ord352, false);
  
    }
    ReadTask345(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex342, mp_uniondelta344, std::array<u64,3>{v_c63, 0, 0}, [&](const std::array<u64,3>& m354) {
          u64 v_c64 = m354[1]; u64 v_c65 = m354[2];
          slog::join_probe<5,1>(mbranchindex343, std::array<u64,5>{v_c64, 0, 0, 0, 0}, [&](const std::array<u64,5>& m355) {
            u64 v_c36 = m355[1]; u64 v_c37 = m355[2]; u64 v_c34 = m355[3]; u64 v_c7 = m355[4];
            u64 v_c66 = _prim_lt(db, v_c2, v_c37);
            if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c66) return;
            u64 v_c67 = _prim_band(db, v_c3, v_c37);
            if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c68 = _prim_lt(db, v_c67, v_c62);
            if (v_c68 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c68) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c65, v_c34, v_c5, v_c2, v_c37, v_c3, v_c36, v_c6, v_c7}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask345* _cont = new ReadTask345(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask345(db,b), false);
  // (crule (pre (let __trid5qdI555 constfee494ff4827aeb0635bb714) (let __trel26ry556 const3cd26ab9ce3085a816a74a29) (let __tcol0yMK557 const5feceb66ffc86f38d952786c) (let __trel7Ewl558 const3cd26ab9ce3085a816a74a29) (let __tcol79YJ559 const6b86b273ff34fce19d6b804e)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5qdI555 __trel26ry556 __tcol0yMK557 (1 2 3 4 0)) (tycheck k (accept int) __trid5qdI555 __trel7Ewl558 __tcol79YJ559 (1 2 3 4 0)) (mkstruct mp_del (1 2 0) __5eVg554 r k)) map.slog:85 #f)
  class ReadTask361 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid359;  u32 sid358;  u32 sid360;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_del");
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      sid359 = db->getRelation("_enum")->getStructId();
      sid358 = db->getRelation("mbranch")->getStructId();
      sid360 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask361(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_constfee494ff4827aeb0635bb714;
      u64 v_c70 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
      u64 v_c72 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c73 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c6 = _t[5];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid358 || decode_struct_id(v_c6) == sid359 || decode_struct_id(v_c6) == sid360))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c69, v_c70, v_c71, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c69, v_c72, v_c73, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask361* _cont = new ReadTask361(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask361(db,b), false);
  // (crule (pre (let __trid4EVo585 constc742e02805b99df617265a41) (let __trel5d5x586 const7f254967624b26d820569bd6) (let __tcol63rG587 const5feceb66ffc86f38d952786c) (let __trel7brI588 const72bac24066bb34077c1f6e71) (let __tcol5XHD589 const5feceb66ffc86f38d952786c) (let __trel8zvI590 const72bac24066bb34077c1f6e71) (let __tcol3Jeb591 const6b86b273ff34fce19d6b804e) (let __trel7nVP592 const72bac24066bb34077c1f6e71) (let __tcol1fWi593 constd4735e3a265e16eee03f5971) (let __trel3WNs594 const72bac24066bb34077c1f6e71) (let __tcol1hM0595 const4e07408562bedb8b60ce05c1)) (scan $sup5638x95x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4EVo585 __trel5d5x586 __tcol63rG587 (1 2 3 4 0)) (tycheck q (accept int) __trid4EVo585 __trel7brI588 __tcol5XHD589 (1 2 3 4 0)) (tycheck n (accept int) __trid4EVo585 __trel8zvI590 __tcol3Jeb591 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4EVo585 __trel7nVP592 __tcol1fWi593 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4EVo585 __trel3WNs594 __tcol1hM0595 (1 2 3 4 0)) (emit-temp temp0EGL1024 l n q u v) (mkstruct mbranch (1 2 3 4 0) __t62ZT317 q n u v)) map.slog:96 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid363;  u32 sid362;  u32 sid364;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp0EGL1024");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x1");
      sid363 = db->getRelation("_enum")->getStructId();
      sid362 = db->getRelation("mbranch")->getStructId();
      sid364 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c74 = v_constc742e02805b99df617265a41;
      u64 v_c75 = v_const7f254967624b26d820569bd6;
      u64 v_c76 = v_const5feceb66ffc86f38d952786c;
      u64 v_c77 = v_const72bac24066bb34077c1f6e71;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_const72bac24066bb34077c1f6e71;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const72bac24066bb34077c1f6e71;
      u64 v_c82 = v_constd4735e3a265e16eee03f5971;
      u64 v_c83 = v_const72bac24066bb34077c1f6e71;
      u64 v_c84 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c4 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c37 = _t[4];
        u64 v_c3 = _t[5];
        u64 v_c36 = _t[6];
        u64 v_c6 = _t[7];
        u64 v_c34 = _t[8];
        u64 v_c7 = _t[9];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid362 || decode_struct_id(v_c5) == sid363 || decode_struct_id(v_c5) == sid364))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c74, v_c75, v_c76, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c36)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c74, v_c77, v_c78, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c37)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c74, v_c79, v_c80, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c34) && (decode_struct_id(v_c34) == sid362 || decode_struct_id(v_c34) == sid363 || decode_struct_id(v_c34) == sid364))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c74, v_c81, v_c82, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid362 || decode_struct_id(v_c7) == sid363 || decode_struct_id(v_c7) == sid364))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c74, v_c83, v_c84, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c5, v_c37, v_c36, v_c34, v_c7});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c36, v_c37, v_c34, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask365* _cont = new ReadTask365(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask365(db,b), false);
  // (crule (pre (let __tconst1tdf238 const5feceb66ffc86f38d952786c)) (scan mp_union __t7Vjh237 __t6hXy236 __t8FcE235) (body (join mbranch (0 1 2 3 4) 1 __t8FcE235 q n u v) (join mbranch (0 1 2 3 4) 1 __t6hXy236 p m l r) (cmp lt m n) (let __t7cw8239 (band p n)) (cmp gt __t7cw8239 __tconst1tdf238)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t7Vjh237 v l m n p q r u)) map.slog:108 #f)
  class ReadTask368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex366;  slog::Index** mbranchindex367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord369({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel370 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord371({0, 1, 2, 3, 4});
      slog::Relation* readrel372 = db->getRelation("mbranch");
      mbranchindex366 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({0, 1, 2, 3, 4});
      slog::Relation* readrel374 = db->getRelation("mbranch");
      mbranchindex367 = readrel374->getIndex(ord373, false);
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe<5,1>(mbranchindex366, std::array<u64,5>{v_c89, 0, 0, 0, 0}, [&](const std::array<u64,5>& m375) {
          u64 v_c36 = m375[1]; u64 v_c37 = m375[2]; u64 v_c34 = m375[3]; u64 v_c7 = m375[4];
          slog::join_probe<5,1>(mbranchindex367, std::array<u64,5>{v_c88, 0, 0, 0, 0}, [&](const std::array<u64,5>& m376) {
            u64 v_c3 = m376[1]; u64 v_c2 = m376[2]; u64 v_c5 = m376[3]; u64 v_c6 = m376[4];
            u64 v_c90 = _prim_lt(db, v_c2, v_c37);
            if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c90) return;
            u64 v_c91 = _prim_band(db, v_c3, v_c37);
            if (v_c91 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c92 = _prim_gt(db, v_c91, v_c86);
            if (v_c92 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c92) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c87, v_c7, v_c5, v_c2, v_c37, v_c3, v_c36, v_c6, v_c34}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask368* _cont = new ReadTask368(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask368(db,b), false);
  // (crule (pre (let __tconst2WsH770 constd01925b37634a1a9d24159d8) (let __tconst8cSV359 const7902699be42c8a8e46fbbb45) (let __tconst5f73358 constff5a1ae012afa5d4c889c50a)) (probe _enum (1 0) 1 __tconst2WsH770 __t0Lvr360) (body) (head (mkstruct mp_put (1 2 3 0) __6huB769 __t0Lvr360 __tconst8cSV359 __tconst5f73358)) mp_basic.slog:14 #f)
  class ReadTask379 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_put");
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("_enum");
      driver_index = readrel381->getIndex(ord380, true);
  
    }
    ReadTask379(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_constd01925b37634a1a9d24159d8;
      u64 v_c94 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c95 = v_constff5a1ae012afa5d4c889c50a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c93, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m382) {
        u64 v_c96 = m382[1];
        if (buckethash(v_c96) != bucket) return;
        ++_fires;
        slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c96, v_c94, v_c95}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask379* _cont = new ReadTask379(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask379(db,b), true);
  // (crule (pre) (scan temp8y4n1085 k p t v) (body (join mleaf (1 2 0) 2 k v __t8W6m138)) (head (mkstruct mp_join (1 2 3 4 0) __6ZyY777 k __t8W6m138 p t)) map.slog:45 #f)
  class ReadTask384 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex383;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("temp8y4n1085");
      std::vector<u16> ord385({1, 2, 0});
      slog::Relation* readrel386 = db->getRelation("mleaf");
      mleafindex383 = readrel386->getIndex(ord385, false);
  
    }
    ReadTask384(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c97 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe<3,2>(mleafindex383, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m387) {
          u64 v_c98 = m387[2];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c1, v_c98, v_c3, v_c97}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:temp8y4n1085", _fires);
  
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
  // (crule (pre (let __tconst8gcx596 constd01925b37634a1a9d24159d8)) (scan mp_del __t9IAM343 __t625g342 k) (body (join _enum (0 1) 2 __t625g342 __tconst8gcx596)) (head (emit mp_del_ans (0 1) __t9IAM343 __t625g342)) map.slog:79 #f)
  class ReadTask389 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex388;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord390({0, 1});
      slog::Relation* readrel391 = db->getRelation("mp_del_ans");
      head_index[0] = readrel391->getIndex(ord390, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("_enum");
      _enumindex388 = readrel393->getIndex(ord392, false);
  
    }
    ReadTask389(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c101 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<2,2>(_enumindex388, std::array<u64,2>{v_c101, v_c99}, [&](const std::array<u64,2>& m394) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c100, v_c101}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:79", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask389* _cont = new ReadTask389(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask389(db,b), false);
  // (crule (pre) (scan mbranch __t8hMI375 p m l r) (body (exists mp_join (1 2 3 4 0) 2 p __t8hMI375) (exists mp_union (1 2 0) 1 __t8hMI375) (exists mp_msk (2 0 1) 1 m) (join $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 5 l m p r __t8hMI375 q __t4ZhK374 n __t5XzA376 u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5XzA376) (exists mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t8hMI375 q __t5XzA376 __t35Cd377) (join mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_join_ans (0 1) 1 __t35Cd377) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask411 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex395;  slog::Index** mp_unionindex396;  slog::Index** mp_mskindex397;  slog::Index** $sup5638x101x0x0x0index398;  slog::Index** mbranchindex399;  slog::Index** mp_unionindex400;  slog::Index** mp_mskindex401;  slog::Index** mp_joinindex402;  slog::Index** mp_unionindex403;  slog::Index** mp_join_ansindex404;  slog::Index** mp_mskindex405;  slog::Index** mp_msk_ansindex406;  slog::Index** mp_join_ansindex407;  slog::Index** mbranchdelta408;  slog::Index** mp_joindelta409;  slog::Index** mp_mskdelta410;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("mp_union_ans");
      head_index[0] = readrel413->getIndex(ord412, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord414({1, 2, 3, 4, 0});
      slog::Relation* readrel415 = db->getRelation("mp_join");
      mp_joinindex395 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 2, 0});
      slog::Relation* readrel417 = db->getRelation("mp_union");
      mp_unionindex396 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({2, 0, 1});
      slog::Relation* readrel419 = db->getRelation("mp_msk");
      mp_mskindex397 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel421 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index398 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 3, 4, 0});
      slog::Relation* readrel423 = db->getRelation("mbranch");
      mbranchindex399 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 3, 4, 0});
      slog::Relation* readrel425 = db->getRelation("mbranch");
      mbranchdelta408 = readrel425->getIndex(ord424, true);
      std::vector<u16> ord426({0, 1, 2});
      slog::Relation* readrel427 = db->getRelation("mp_union");
      mp_unionindex400 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 2, 0});
      slog::Relation* readrel429 = db->getRelation("mp_msk");
      mp_mskindex401 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 2, 3, 4, 0});
      slog::Relation* readrel431 = db->getRelation("mp_join");
      mp_joinindex402 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 3, 4, 0});
      slog::Relation* readrel433 = db->getRelation("mp_join");
      mp_joindelta409 = readrel433->getIndex(ord432, true);
      std::vector<u16> ord434({0, 1, 2});
      slog::Relation* readrel435 = db->getRelation("mp_union");
      mp_unionindex403 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1});
      slog::Relation* readrel437 = db->getRelation("mp_join_ans");
      mp_join_ansindex404 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("mp_msk");
      mp_mskindex405 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("mp_msk");
      mp_mskdelta410 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({0, 1});
      slog::Relation* readrel443 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex406 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1});
      slog::Relation* readrel445 = db->getRelation("mp_join_ans");
      mp_join_ansindex407 = readrel445->getIndex(ord444, false);
  
    }
    ReadTask411(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex395, std::array<u64,5>{v_c3, v_c102, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex396, std::array<u64,3>{v_c102, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex397, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x101x0x0x0index398, std::array<u64,11>{v_c5, v_c2, v_c3, v_c6, v_c102, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m446) {
          u64 v_c36 = m446[5]; u64 v_c103 = m446[6]; u64 v_c37 = m446[7]; u64 v_c104 = m446[8]; u64 v_c34 = m446[9]; u64 v_c7 = m446[10];
          u64 v_c105 = _prim_lt(db, v_c37, v_c2);
          if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c105) return;
          slog::join_probe_old<5,5>(mbranchindex399, mbranchdelta408, std::array<u64,5>{v_c36, v_c37, v_c34, v_c7, v_c104}, [&](const std::array<u64,5>& m448) {
            if (!slog::exists_probe<3,3>(mp_unionindex400, std::array<u64,3>{v_c103, v_c102, v_c104})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex401, std::array<u64,3>{v_c36, v_c2, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex402, mp_joindelta409, std::array<u64,5>{v_c3, v_c102, v_c36, v_c104, 0}, [&](const std::array<u64,5>& m449) {
              u64 v_c106 = m449[4];
              slog::join_probe<3,3>(mp_unionindex403, std::array<u64,3>{v_c103, v_c102, v_c104}, [&](const std::array<u64,3>& m450) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex404, std::array<u64,2>{v_c106, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex405, mp_mskdelta410, std::array<u64,3>{v_c36, v_c2, 0}, [&](const std::array<u64,3>& m451) {
                  u64 v_c107 = m451[2];
                  slog::join_probe<2,1>(mp_msk_ansindex406, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m452) {
                    u64 v_c21 = m452[1];
                    if (v_c3 == v_c21) return;
                    slog::join_probe<2,1>(mp_join_ansindex407, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m453) {
                      u64 v_c26 = m453[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c103, v_c26}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask411* _cont = new ReadTask411(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask411(db,b), false);
  // (crule (pre (let __tconst0tqB177 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9qsM175 p m l r) (body (join-old mp_put (1 2 0 3) 1 (1 2 0 3) __t9qsM175 k __t4dVF176 v) (let __t82n0178 (band k m)) (cmp lt __t82n0178 __tconst0tqB177)) (head (emit $sup5638x40x0x0x0 (4 2 3 5 0 1 6) p l m r __t4dVF176 k v)) map.slog:41 #f)
  class ReadTask456 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex454;  slog::Index** mp_putdelta455;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord457({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel458 = db->getRelation("$sup5638x40x0x0x0");
      head_index[0] = readrel458->getIndex(ord457, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord459({1, 2, 0, 3});
      slog::Relation* readrel460 = db->getRelation("mp_put");
      mp_putindex454 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0, 3});
      slog::Relation* readrel462 = db->getRelation("mp_put");
      mp_putdelta455 = readrel462->getIndex(ord461, true);
  
    }
    ReadTask456(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c109 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        slog::join_probe_old<4,1>(mp_putindex454, mp_putdelta455, std::array<u64,4>{v_c109, 0, 0, 0}, [&](const std::array<u64,4>& m463) {
          u64 v_c1 = m463[1]; u64 v_c110 = m463[2]; u64 v_c7 = m463[3];
          u64 v_c111 = _prim_band(db, v_c1, v_c2);
          if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          u64 v_c112 = _prim_lt(db, v_c111, v_c108);
          if (v_c112 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          if (!v_c112) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c3, v_c5, v_c2, v_c6, v_c110, v_c1, v_c7}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask456* _cont = new ReadTask456(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask456(db,b), false);
  // (crule (pre) (scan nan_result __erre9pm3997 __errf82vg998 __errf9YJd999 __errf8NmK1000) (body) (head (emit error (0) __erre9pm3997)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord466({0});
      slog::Relation* readrel467 = db->getRelation("error");
      head_index[0] = readrel467->getIndex(ord466, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c113 = _t[0];
        u64 v_c114 = _t[1];
        u64 v_c115 = _t[2];
        u64 v_c116 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c113}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre (let __trid9sGf604 const3b5b774db59f55c2fdaef73a) (let __trel9I0G605 constdd7bbf31ce5f578b9805e840) (let __tcol3SDJ606 const5feceb66ffc86f38d952786c) (let __trel6eVl607 constdd7bbf31ce5f578b9805e840) (let __tcol9Rll608 const6b86b273ff34fce19d6b804e)) (scan $sup5638x62x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid9sGf604 __trel9I0G605 __tcol3SDJ606 (1 2 3 4 0)) (tycheck m (accept int) __trid9sGf604 __trel6eVl607 __tcol9Rll608 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __245w603 k m)) map.slog:63 #f)
  class ReadTask468 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
  
    }
    ReadTask468(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c117 = v_const3b5b774db59f55c2fdaef73a;
      u64 v_c118 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c6 = _t[5];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c117, v_c118, v_c119, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c117, v_c120, v_c121, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask468* _cont = new ReadTask468(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask468(db,b), false);
}

