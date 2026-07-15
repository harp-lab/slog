
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const11445e6556bc59ce1e80cdf7;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c5e507d0827aa73d6(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan mleaf __t5dUf162 j w) (body (join-old mp_put (1 2 0 3) 1 (1 2 0 3) __t5dUf162 k __t0PgJ163 v) (neq j k)) (head (emit-temp temp5R2q1072 __t5dUf162 j k v) (mkstruct mleaf (1 2 0) __t7RTp161 k v)) map.slog:39 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex0;  slog::Index** mp_putdelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5R2q1072");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord3({1, 2, 0, 3});
      slog::Relation* readrel4 = db->getRelation("mp_put");
      mp_putindex0 = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({1, 2, 0, 3});
      slog::Relation* readrel6 = db->getRelation("mp_put");
      mp_putdelta1 = readrel6->getIndex(ord5, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<4,1>(mp_putindex0, mp_putdelta1, std::array<u64,4>{v_c0, 0, 0, 0}, [&](const std::array<u64,4>& m7) {
          u64 v_c3 = m7[1]; u64 v_c4 = m7[2]; u64 v_c5 = m7[3];
          if (v_c1 == v_c3) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c3, v_c5});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
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
  // (crule (pre) (scan temp5jzw1068 __t9UyG147 l m p r) (body (join mbranch (1 2 3 4 0) 4 p m l r __t9Cts146)) (head (emit mp_bld_ans (0 1) __t9UyG147 __t9Cts146)) map.slog:75 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel11->getIndex(ord10, false);
      outer_rel = db->getRelation("temp5jzw1068");
      std::vector<u16> ord12({1, 2, 3, 4, 0});
      slog::Relation* readrel13 = db->getRelation("mbranch");
      mbranchindex8 = readrel13->getIndex(ord12, false);
  
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
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c10 = _t[4];
        slog::join_probe<5,4>(mbranchindex8, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m14) {
          u64 v_c11 = m14[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c11}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:75", "delta:temp5jzw1068", _fires);
  
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
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t3jH2107 p n) (body (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_msk_ans (0 1) 1 __t3jH2107) (join $sup5638x104x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t3jH2107 n p q __t38nk104 l m r u v) (cmp lt m n) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t38nk104 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk_ans (0 1) 2 __t3jH2107 q) (exists mp_union (2 0 1) 1 u) (join mbranch (1 2 3 4 0) 4 q n u v __t9OKP102) (exists mp_union (2 0 1) 2 __t9OKP102 __t38nk104) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6XhK108) (join mp_union (0 1 2) 3 __t38nk104 __t6XhK108 __t9OKP102) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index15;  slog::Index** mbranchindex16;  slog::Index** mbranchindex17;  slog::Index** mp_msk_ansindex18;  slog::Index** $sup5638x104x0x0x1index19;  slog::Index** $sup5638x104x0x0x0index20;  slog::Index** mbranchindex21;  slog::Index** mp_msk_ansindex22;  slog::Index** mp_unionindex23;  slog::Index** mbranchindex24;  slog::Index** mp_unionindex25;  slog::Index** mbranchindex26;  slog::Index** mp_unionindex27;  slog::Index** mp_msk_ansindex28;  slog::Index** mp_unionindex29;  slog::Index** mp_union_ansindex30;  slog::Index** mbranchdelta31;  slog::Index** mp_uniondelta32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord34({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel35 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index15 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({2, 0, 1, 3, 4});
      slog::Relation* readrel37 = db->getRelation("mbranch");
      mbranchindex16 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 3, 4, 0});
      slog::Relation* readrel39 = db->getRelation("mbranch");
      mbranchindex17 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 1});
      slog::Relation* readrel41 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex18 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel43 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index19 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel45 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index20 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 3, 4, 0});
      slog::Relation* readrel47 = db->getRelation("mbranch");
      mbranchindex21 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex22 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({2, 0, 1});
      slog::Relation* readrel51 = db->getRelation("mp_union");
      mp_unionindex23 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 3, 4, 0});
      slog::Relation* readrel53 = db->getRelation("mbranch");
      mbranchindex24 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({2, 0, 1});
      slog::Relation* readrel55 = db->getRelation("mp_union");
      mp_unionindex25 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 3, 4, 0});
      slog::Relation* readrel57 = db->getRelation("mbranch");
      mbranchindex26 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 3, 4, 0});
      slog::Relation* readrel59 = db->getRelation("mbranch");
      mbranchdelta31 = readrel59->getIndex(ord58, true);
      std::vector<u16> ord60({0, 1, 2});
      slog::Relation* readrel61 = db->getRelation("mp_union");
      mp_unionindex27 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex28 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("mp_union");
      mp_unionindex29 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 2, 0});
      slog::Relation* readrel67 = db->getRelation("mp_union");
      mp_uniondelta32 = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({0, 1});
      slog::Relation* readrel69 = db->getRelation("mp_union_ans");
      mp_union_ansindex30 = readrel69->getIndex(ord68, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index15, std::array<u64,9>{v_c14, v_c9, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex16, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex17, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex18, std::array<u64,2>{v_c13, 0})) return;
        slog::join_probe<10,3>($sup5638x104x0x0x1index19, std::array<u64,10>{v_c13, v_c14, v_c9, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m70) {
          u64 v_c15 = m70[3]; u64 v_c16 = m70[4]; u64 v_c7 = m70[5]; u64 v_c8 = m70[6]; u64 v_c10 = m70[7]; u64 v_c17 = m70[8]; u64 v_c5 = m70[9];
          u64 v_c18 = _prim_lt(db, v_c8, v_c14);
          if (v_c18 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c18) return;
          slog::join_probe<9,9>($sup5638x104x0x0x0index20, std::array<u64,9>{v_c15, v_c14, v_c17, v_c5, v_c16, v_c7, v_c8, v_c9, v_c10}, [&](const std::array<u64,9>& m72) {
            if (!slog::exists_probe<5,4>(mbranchindex21, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex22, std::array<u64,2>{v_c13, v_c15})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex23, std::array<u64,3>{v_c17, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex24, std::array<u64,5>{v_c15, v_c14, v_c17, v_c5, 0}, [&](const std::array<u64,5>& m73) {
              u64 v_c19 = m73[4];
              if (!slog::exists_probe<3,2>(mp_unionindex25, std::array<u64,3>{v_c19, v_c16, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex26, mbranchdelta31, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m74) {
                u64 v_c20 = m74[4];
                slog::join_probe<3,3>(mp_unionindex27, std::array<u64,3>{v_c16, v_c20, v_c19}, [&](const std::array<u64,3>& m75) {
                  slog::join_probe<2,2>(mp_msk_ansindex28, std::array<u64,2>{v_c13, v_c15}, [&](const std::array<u64,2>& m76) {
                    slog::join_probe_old<3,2>(mp_unionindex29, mp_uniondelta32, std::array<u64,3>{v_c20, v_c17, 0}, [&](const std::array<u64,3>& m77) {
                      u64 v_c21 = m77[2];
                      slog::join_probe<2,1>(mp_union_ansindex30, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m78) {
                        u64 v_c22 = m78[1];
                        u64 v_c23 = _prim_band(db, v_c9, v_c14);
                        if (v_c23 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c24 = _prim_lt(db, v_c23, v_c12);
                        if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c24) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c16, v_c22, v_c14, v_c15, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c22, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __t5APc170 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t5APc170 k) (exists mp_has0 (1 2 0) 2 l k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4G6v169) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t5APc170 k __t4G6v169) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t8KSH173) (exists mp_has0_ans (0 1) 1 __t8KSH173) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4QPc174) (join mp_msk_ans (0 1) 2 __t4QPc174 p) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask95 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index80;  slog::Index** mp_has0index81;  slog::Index** mp_mskindex82;  slog::Index** mp_msk_ansindex83;  slog::Index** mbranchindex84;  slog::Index** mp_has0index85;  slog::Index** mp_has0index86;  slog::Index** mp_has0_ansindex87;  slog::Index** mp_mskindex88;  slog::Index** mp_msk_ansindex89;  slog::Index** mp_has0_ansindex90;  slog::Index** mbranchdelta91;  slog::Index** mp_has0delta92;  slog::Index** mp_has0delta93;  slog::Index** mp_mskdelta94;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel97->getIndex(ord96, false);
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord98({0, 2, 1});
      slog::Relation* readrel99 = db->getRelation("mp_has0");
      mp_has0index80 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("mp_has0");
      mp_has0index81 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 2, 0});
      slog::Relation* readrel103 = db->getRelation("mp_msk");
      mp_mskindex82 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex83 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 3, 4, 0});
      slog::Relation* readrel107 = db->getRelation("mbranch");
      mbranchindex84 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 3, 4, 0});
      slog::Relation* readrel109 = db->getRelation("mbranch");
      mbranchdelta91 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({0, 2, 1});
      slog::Relation* readrel111 = db->getRelation("mp_has0");
      mp_has0index85 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 2, 1});
      slog::Relation* readrel113 = db->getRelation("mp_has0");
      mp_has0delta92 = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({1, 2, 0});
      slog::Relation* readrel115 = db->getRelation("mp_has0");
      mp_has0index86 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("mp_has0");
      mp_has0delta93 = readrel117->getIndex(ord116, true);
      std::vector<u16> ord118({0, 1});
      slog::Relation* readrel119 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex87 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("mp_msk");
      mp_mskindex88 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("mp_msk");
      mp_mskdelta94 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex89 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1});
      slog::Relation* readrel127 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex90 = readrel127->getIndex(ord126, false);
  
    }
    ReadTask95(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index80, std::array<u64,3>{v_c26, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index81, std::array<u64,3>{v_c7, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex82, std::array<u64,3>{v_c3, v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex83, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex84, mbranchdelta91, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m128) {
          u64 v_c27 = m128[4];
          slog::join_probe_old<3,3>(mp_has0index85, mp_has0delta92, std::array<u64,3>{v_c26, v_c3, v_c27}, [&](const std::array<u64,3>& m129) {
            slog::join_probe_old<3,2>(mp_has0index86, mp_has0delta93, std::array<u64,3>{v_c7, v_c3, 0}, [&](const std::array<u64,3>& m130) {
              u64 v_c28 = m130[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex87, std::array<u64,2>{v_c28, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex88, mp_mskdelta94, std::array<u64,3>{v_c3, v_c8, 0}, [&](const std::array<u64,3>& m131) {
                u64 v_c29 = m131[2];
                slog::join_probe<2,2>(mp_msk_ansindex89, std::array<u64,2>{v_c29, v_c9}, [&](const std::array<u64,2>& m132) {
                  slog::join_probe<2,1>(mp_has0_ansindex90, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m133) {
                    u64 v_c30 = m133[1];
                    u64 v_c31 = _prim_band(db, v_c3, v_c8);
                    if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c32 = _prim_lt(db, v_c31, v_c25);
                    if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c32) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c30}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask95* _cont = new ReadTask95(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask95(db,b), false);
  // (crule (pre (let __tconst1DnK387 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t5Ake386 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t5Ake386 __t1scf385) (join $sup5638x25x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t9zeu388 (band p0 __v0)) (cmp lt __t9zeu388 __tconst1DnK387) (let chk9NsY1070 (bxor p0 p1)) (eq __t1scf385 chk9NsY1070)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t5Ake386 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask138 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex135;  slog::Index** $sup5638x25x0x0x0index136;  slog::Index** mp_hsbdelta137;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord139({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel140 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel140->getIndex(ord139, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord141({0, 1});
      slog::Relation* readrel142 = db->getRelation("mp_hsb");
      mp_hsbindex135 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({0, 1});
      slog::Relation* readrel144 = db->getRelation("mp_hsb");
      mp_hsbdelta137 = readrel144->getIndex(ord143, true);
      std::vector<u16> ord145({1, 0, 2, 3, 4});
      slog::Relation* readrel146 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index136 = readrel146->getIndex(ord145, false);
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex135, mp_hsbdelta137, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m147) {
          u64 v_c35 = m147[1];
          slog::join_all<5>($sup5638x25x0x0x0index136, [&](const std::array<u64,5>& m148) {
            u64 v_c36 = m148[0]; u64 v_c37 = m148[1]; u64 v_c38 = m148[2]; u64 v_c39 = m148[3]; u64 v_c40 = m148[4];
            u64 v_c41 = _prim_band(db, v_c36, v_c22);
            if (v_c41 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c42 = _prim_lt(db, v_c41, v_c33);
            if (v_c42 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c42) return;
            u64 v_c43 = _prim_bxor(db, v_c36, v_c38);
            if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (v_c35 != v_c43) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c34, v_c22, v_c37, v_c36, v_c38, v_c39, v_c40}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask138* _cont = new ReadTask138(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask138(db,b), false);
  // (crule (pre (let __tconst3nEl614 constd01925b37634a1a9d24159d8) (let __tconst5JbS3 constff5a1ae012afa5d4c889c50a) (let __tconst00xS4 const7902699be42c8a8e46fbbb45) (let __tconst6RTh7 const624b60c58c9d8bfb6ff1886c) (let __tconst80wL8 const4e07408562bedb8b60ce05c1) (let __tconst69fL1 const4a44dc15364204a80fe80e90) (let __tconst9RBO2 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t5DYC6 __v0) (body (exists mp_put (1 2 3 0) 3 __v0 __tconst80wL8 __tconst6RTh7) (exists _enum (1 0) 1 __tconst3nEl614) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst00xS4 __tconst5JbS3 __t5DYC6 __t5kVD5) (exists _enum (0 1) 2 __t5kVD5 __tconst3nEl614) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __v0 __tconst80wL8 __tconst6RTh7 __t9KAP9) (join _enum (0 1) 2 __t5kVD5 __tconst3nEl614) (join-old mp_put_ans (0 1) 1 (0 1) __t9KAP9 __v1)) (head (mkstruct mp_put (1 2 3 0) __2h5j615 __v1 __tconst9RBO2 __tconst69fL1)) mp_basic.slog:14 #f)
  class ReadTask160 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex150;  slog::Index** _enumindex151;  slog::Index** mp_putindex152;  slog::Index** _enumindex153;  slog::Index** mp_putindex154;  slog::Index** _enumindex155;  slog::Index** mp_put_ansindex156;  slog::Index** mp_putdelta157;  slog::Index** mp_putdelta158;  slog::Index** mp_put_ansdelta159;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord161({1, 2, 3, 0});
      slog::Relation* readrel162 = db->getRelation("mp_put");
      mp_putindex150 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 0});
      slog::Relation* readrel164 = db->getRelation("_enum");
      _enumindex151 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({2, 3, 0, 1});
      slog::Relation* readrel166 = db->getRelation("mp_put");
      mp_putindex152 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({2, 3, 0, 1});
      slog::Relation* readrel168 = db->getRelation("mp_put");
      mp_putdelta157 = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("_enum");
      _enumindex153 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 3, 0});
      slog::Relation* readrel172 = db->getRelation("mp_put");
      mp_putindex154 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 3, 0});
      slog::Relation* readrel174 = db->getRelation("mp_put");
      mp_putdelta158 = readrel174->getIndex(ord173, true);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("_enum");
      _enumindex155 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("mp_put_ans");
      mp_put_ansindex156 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("mp_put_ans");
      mp_put_ansdelta159 = readrel180->getIndex(ord179, true);
  
    }
    ReadTask160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constd01925b37634a1a9d24159d8;
      u64 v_c45 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c46 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c47 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c48 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c49 = v_const4a44dc15364204a80fe80e90;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c51 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<4,3>(mp_putindex150, std::array<u64,4>{v_c22, v_c48, v_c47, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex151, std::array<u64,2>{v_c44, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex152, mp_putdelta157, std::array<u64,4>{v_c46, v_c45, v_c51, 0}, [&](const std::array<u64,4>& m181) {
          u64 v_c52 = m181[3];
          if (!slog::exists_probe<2,2>(_enumindex153, std::array<u64,2>{v_c52, v_c44})) return;
          slog::join_probe_old<4,3>(mp_putindex154, mp_putdelta158, std::array<u64,4>{v_c22, v_c48, v_c47, 0}, [&](const std::array<u64,4>& m182) {
            u64 v_c53 = m182[3];
            slog::join_probe<2,2>(_enumindex155, std::array<u64,2>{v_c52, v_c44}, [&](const std::array<u64,2>& m183) {
              slog::join_probe_old<2,1>(mp_put_ansindex156, mp_put_ansdelta159, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m184) {
                u64 v_c54 = m184[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c54, v_c50, v_c49}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask160* _cont = new ReadTask160(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask160(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_bld __t8Ai5407 p m l __v0) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join mbranch (1 2 3 4 0) 3 p m l r __t0VzH403) (exists mp_del (1 2 0) 1 __t0VzH403) (exists mp_del (1 2 0) 1 r) (join $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 p l m r __t01YW404 k) (join mp_del (0 2 1) 3 __t01YW404 k __t0VzH403) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join mp_del_ans (0 1) 2 __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index185;  slog::Index** mp_mskindex186;  slog::Index** mp_msk_ansindex187;  slog::Index** mp_del_ansindex188;  slog::Index** mp_bld_ansindex189;  slog::Index** mbranchindex190;  slog::Index** mp_delindex191;  slog::Index** mp_delindex192;  slog::Index** $sup5638x84x0x0x0index193;  slog::Index** mp_delindex194;  slog::Index** mp_delindex195;  slog::Index** mp_mskindex196;  slog::Index** mp_msk_ansindex197;  slog::Index** mp_delindex198;  slog::Index** mp_del_ansindex199;  slog::Index** mp_bld_ansindex200;  slog::Index** mp_mskdelta201;  slog::Index** mp_deldelta202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("mp_del_ans");
      head_index[0] = readrel205->getIndex(ord204, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord206({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel207 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index185 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({2, 0, 1});
      slog::Relation* readrel209 = db->getRelation("mp_msk");
      mp_mskindex186 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex187 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 0});
      slog::Relation* readrel213 = db->getRelation("mp_del_ans");
      mp_del_ansindex188 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex189 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 2, 3, 4, 0});
      slog::Relation* readrel217 = db->getRelation("mbranch");
      mbranchindex190 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("mp_del");
      mp_delindex191 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("mp_del");
      mp_delindex192 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel223 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index193 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 2, 1});
      slog::Relation* readrel225 = db->getRelation("mp_del");
      mp_delindex194 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("mp_del");
      mp_delindex195 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("mp_msk");
      mp_mskindex196 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 0});
      slog::Relation* readrel231 = db->getRelation("mp_msk");
      mp_mskdelta201 = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex197 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("mp_del");
      mp_delindex198 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("mp_del");
      mp_deldelta202 = readrel237->getIndex(ord236, true);
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("mp_del_ans");
      mp_del_ansindex199 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex200 = readrel241->getIndex(ord240, false);
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c56 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c22 = _t[4];
        if (!slog::exists_probe<6,3>($sup5638x84x0x0x0index185, std::array<u64,6>{v_c9, v_c7, v_c8, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex186, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex187, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(mp_del_ansindex188, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(mp_bld_ansindex189, std::array<u64,2>{v_c56, 0})) return;
        slog::join_probe<5,3>(mbranchindex190, std::array<u64,5>{v_c9, v_c8, v_c7, 0, 0}, [&](const std::array<u64,5>& m242) {
          u64 v_c10 = m242[3]; u64 v_c57 = m242[4];
          if (!slog::exists_probe<3,1>(mp_delindex191, std::array<u64,3>{v_c57, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex192, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<6,4>($sup5638x84x0x0x0index193, std::array<u64,6>{v_c9, v_c7, v_c8, v_c10, 0, 0}, [&](const std::array<u64,6>& m243) {
            u64 v_c58 = m243[4]; u64 v_c3 = m243[5];
            slog::join_probe<3,3>(mp_delindex194, std::array<u64,3>{v_c58, v_c3, v_c57}, [&](const std::array<u64,3>& m244) {
              if (!slog::exists_probe<3,2>(mp_delindex195, std::array<u64,3>{v_c10, v_c3, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex196, mp_mskdelta201, std::array<u64,3>{v_c3, v_c8, 0}, [&](const std::array<u64,3>& m245) {
                u64 v_c59 = m245[2];
                slog::join_probe<2,2>(mp_msk_ansindex197, std::array<u64,2>{v_c59, v_c9}, [&](const std::array<u64,2>& m246) {
                  slog::join_probe_old<3,2>(mp_delindex198, mp_deldelta202, std::array<u64,3>{v_c10, v_c3, 0}, [&](const std::array<u64,3>& m247) {
                    u64 v_c60 = m247[2];
                    slog::join_probe<2,2>(mp_del_ansindex199, std::array<u64,2>{v_c60, v_c22}, [&](const std::array<u64,2>& m248) {
                      slog::join_probe<2,1>(mp_bld_ansindex200, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m249) {
                        u64 v_c61 = m249[1];
                        u64 v_c62 = _prim_band(db, v_c3, v_c8);
                        if (v_c62 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c63 = _prim_gt(db, v_c62, v_c55);
                        if (v_c63 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c63) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c61}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_bld", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre0wOX987 __errf1DLO988 __errf1O8X989) (body) (head (emit error (0) __erre0wOX987)) <internal>:1 #f)
  class ReadTask251 : public slog::Task
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
      std::vector<u16> ord252({0});
      slog::Relation* readrel253 = db->getRelation("error");
      head_index[0] = readrel253->getIndex(ord252, false);
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c64 = _t[0];
        u64 v_c65 = _t[1];
        u64 v_c66 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan $sup5638x42x0x0x1 __t0ekw284 __t8lnB287 k l m p r v) (body (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t0ekw284 k v) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_msk (1 2 0) 3 k m __t8lnB287) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t07OG283) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t07OG283 k __t0ekw284 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t8lnB287) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index254;  slog::Index** mp_putindex255;  slog::Index** mp_mskindex256;  slog::Index** mp_putindex257;  slog::Index** mp_msk_ansindex258;  slog::Index** mbranchindex259;  slog::Index** mp_putindex260;  slog::Index** mp_mskindex261;  slog::Index** mp_putindex262;  slog::Index** mp_msk_ansindex263;  slog::Index** mp_put_ansindex264;  slog::Index** mbranchdelta265;  slog::Index** mp_putdelta266;  slog::Index** mp_mskdelta267;  slog::Index** mp_putdelta268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord270({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel271 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index254 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({2, 3, 0, 1});
      slog::Relation* readrel273 = db->getRelation("mp_put");
      mp_putindex255 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 2, 0});
      slog::Relation* readrel275 = db->getRelation("mp_msk");
      mp_mskindex256 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 3, 0});
      slog::Relation* readrel277 = db->getRelation("mp_put");
      mp_putindex257 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex258 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 2, 3, 4, 0});
      slog::Relation* readrel281 = db->getRelation("mbranch");
      mbranchindex259 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 2, 3, 4, 0});
      slog::Relation* readrel283 = db->getRelation("mbranch");
      mbranchdelta265 = readrel283->getIndex(ord282, true);
      std::vector<u16> ord284({1, 2, 0, 3});
      slog::Relation* readrel285 = db->getRelation("mp_put");
      mp_putindex260 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 2, 0, 3});
      slog::Relation* readrel287 = db->getRelation("mp_put");
      mp_putdelta266 = readrel287->getIndex(ord286, true);
      std::vector<u16> ord288({1, 2, 0});
      slog::Relation* readrel289 = db->getRelation("mp_msk");
      mp_mskindex261 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 2, 0});
      slog::Relation* readrel291 = db->getRelation("mp_msk");
      mp_mskdelta267 = readrel291->getIndex(ord290, true);
      std::vector<u16> ord292({1, 2, 3, 0});
      slog::Relation* readrel293 = db->getRelation("mp_put");
      mp_putindex262 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 3, 0});
      slog::Relation* readrel295 = db->getRelation("mp_put");
      mp_putdelta268 = readrel295->getIndex(ord294, true);
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex263 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("mp_put_ans");
      mp_put_ansindex264 = readrel299->getIndex(ord298, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c5 = _t[7];
        slog::join_probe<7,7>($sup5638x42x0x0x0index254, std::array<u64,7>{v_c9, v_c7, v_c8, v_c10, v_c68, v_c3, v_c5}, [&](const std::array<u64,7>& m300) {
          if (!slog::exists_probe<4,3>(mp_putindex255, std::array<u64,4>{v_c3, v_c5, v_c68, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex256, std::array<u64,3>{v_c3, v_c8, v_c69})) return;
          if (!slog::exists_probe<4,3>(mp_putindex257, std::array<u64,4>{v_c10, v_c3, v_c5, 0})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex258, std::array<u64,2>{v_c69, v_c9})) return;
          slog::join_probe_old<5,4>(mbranchindex259, mbranchdelta265, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m301) {
            u64 v_c70 = m301[4];
            slog::join_probe_old<4,4>(mp_putindex260, mp_putdelta266, std::array<u64,4>{v_c70, v_c3, v_c68, v_c5}, [&](const std::array<u64,4>& m302) {
              slog::join_probe_old<3,3>(mp_mskindex261, mp_mskdelta267, std::array<u64,3>{v_c3, v_c8, v_c69}, [&](const std::array<u64,3>& m303) {
                slog::join_probe_old<4,3>(mp_putindex262, mp_putdelta268, std::array<u64,4>{v_c10, v_c3, v_c5, 0}, [&](const std::array<u64,4>& m304) {
                  u64 v_c71 = m304[3];
                  slog::join_probe<2,2>(mp_msk_ansindex263, std::array<u64,2>{v_c69, v_c9}, [&](const std::array<u64,2>& m305) {
                    slog::join_probe<2,1>(mp_put_ansindex264, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m306) {
                      u64 v_c22 = m306[1];
                      u64 v_c72 = _prim_band(db, v_c3, v_c8);
                      if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c73 = _prim_gt(db, v_c72, v_c67);
                      if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c73) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c22, v_c7, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan temp9B581035 __t05l7352 __v0 n q u) (body (join mbranch (1 2 3 4 0) 4 q n u __v0 __t3dsi349)) (head (emit mp_union_ans (0 1) __t05l7352 __t3dsi349)) map.slog:108 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("mp_union_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("temp9B581035");
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("mbranch");
      mbranchindex308 = readrel313->getIndex(ord312, false);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c74 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c17 = _t[4];
        slog::join_probe<5,4>(mbranchindex308, std::array<u64,5>{v_c15, v_c14, v_c17, v_c22, 0}, [&](const std::array<u64,5>& m314) {
          u64 v_c75 = m314[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c74, v_c75}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:temp9B581035", _fires);
  
      if (!_done)
      {
        ReadTask309* _cont = new ReadTask309(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask309(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t3J75224 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t3J75224 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (join-old $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t9Sl6223 l p r) (neq p __v0) (exists mp_del (0 2 1) 2 __t9Sl6223 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5VI4222) (join-old mp_del (0 2 1) 3 (0 2 1) __t9Sl6223 k __t5VI4222)) (head (emit mp_del_ans (0 1) __t9Sl6223 __t5VI4222)) map.slog:82 #f)
  class ReadTask326 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex315;  slog::Index** mbranchindex316;  slog::Index** mp_delindex317;  slog::Index** $sup5638x81x0x0x0index318;  slog::Index** mp_delindex319;  slog::Index** mbranchindex320;  slog::Index** mp_delindex321;  slog::Index** mp_mskdelta322;  slog::Index** $sup5638x81x0x0x0delta323;  slog::Index** mbranchdelta324;  slog::Index** mp_deldelta325;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("mp_del_ans");
      head_index[0] = readrel328->getIndex(ord327, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord329({0, 1, 2});
      slog::Relation* readrel330 = db->getRelation("mp_msk");
      mp_mskindex315 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 1, 2});
      slog::Relation* readrel332 = db->getRelation("mp_msk");
      mp_mskdelta322 = readrel332->getIndex(ord331, true);
      std::vector<u16> ord333({2, 0, 1, 3, 4});
      slog::Relation* readrel334 = db->getRelation("mbranch");
      mbranchindex316 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({2, 0, 1});
      slog::Relation* readrel336 = db->getRelation("mp_del");
      mp_delindex317 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel338 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index318 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel340 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0delta323 = readrel340->getIndex(ord339, true);
      std::vector<u16> ord341({0, 2, 1});
      slog::Relation* readrel342 = db->getRelation("mp_del");
      mp_delindex319 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 3, 4, 0});
      slog::Relation* readrel344 = db->getRelation("mbranch");
      mbranchindex320 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 2, 3, 4, 0});
      slog::Relation* readrel346 = db->getRelation("mbranch");
      mbranchdelta324 = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({0, 2, 1});
      slog::Relation* readrel348 = db->getRelation("mp_del");
      mp_delindex321 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 2, 1});
      slog::Relation* readrel350 = db->getRelation("mp_del");
      mp_deldelta325 = readrel350->getIndex(ord349, true);
  
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
        u64 v_c76 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex315, mp_mskdelta322, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m351) {
          u64 v_c3 = m351[1]; u64 v_c8 = m351[2];
          if (!slog::exists_probe<5,1>(mbranchindex316, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex317, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x81x0x0x0index318, $sup5638x81x0x0x0delta323, std::array<u64,6>{v_c3, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m352) {
            u64 v_c77 = m352[2]; u64 v_c7 = m352[3]; u64 v_c9 = m352[4]; u64 v_c10 = m352[5];
            if (v_c9 == v_c22) return;
            if (!slog::exists_probe<3,2>(mp_delindex319, std::array<u64,3>{v_c77, v_c3, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex320, mbranchdelta324, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m353) {
              u64 v_c78 = m353[4];
              slog::join_probe_old<3,3>(mp_delindex321, mp_deldelta325, std::array<u64,3>{v_c77, v_c3, v_c78}, [&](const std::array<u64,3>& m354) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c77, v_c78}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre) (scan $sup5638x95x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t185P265) (join-old mp_msk_ans (0 1) 2 (0 1) __t185P265 p)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t185P265 m n p q r u v)) map.slog:96 #f)
  class ReadTask360 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex355;  slog::Index** mp_mskindex356;  slog::Index** mp_msk_ansindex357;  slog::Index** mp_mskdelta358;  slog::Index** mp_msk_ansdelta359;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord361({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel362 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel362->getIndex(ord361, false);
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex355 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 0});
      slog::Relation* readrel366 = db->getRelation("mp_msk");
      mp_mskindex356 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 0});
      slog::Relation* readrel368 = db->getRelation("mp_msk");
      mp_mskdelta358 = readrel368->getIndex(ord367, true);
      std::vector<u16> ord369({0, 1});
      slog::Relation* readrel370 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex357 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1});
      slog::Relation* readrel372 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta359 = readrel372->getIndex(ord371, true);
  
    }
    ReadTask360(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c15 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c17 = _t[7];
        u64 v_c5 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex355, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex356, mp_mskdelta358, std::array<u64,3>{v_c15, v_c8, 0}, [&](const std::array<u64,3>& m373) {
          u64 v_c79 = m373[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex357, mp_msk_ansdelta359, std::array<u64,2>{v_c79, v_c9}, [&](const std::array<u64,2>& m374) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c37, v_c7, v_c79, v_c8, v_c14, v_c9, v_c15, v_c10, v_c17, v_c5}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask360* _cont = new ReadTask360(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask360(db,b), false);
  // (crule (pre) (scan mbranch __t5XzA376 q n u v) (body (exists mp_join (3 4 1 0 2) 2 q __t5XzA376) (exists mp_union (2 0 1) 1 __t5XzA376) (exists mp_msk (1 2 0) 1 q) (join $sup5638x101x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t5XzA376 u v __t4ZhK374 l m p r __t8hMI375) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 p m l r __t8hMI375) (exists mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t8hMI375 q __t5XzA376 __t35Cd377) (join mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_join_ans (0 1) 1 __t35Cd377) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask390 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex375;  slog::Index** mp_unionindex376;  slog::Index** mp_mskindex377;  slog::Index** $sup5638x101x0x0x0index378;  slog::Index** mbranchindex379;  slog::Index** mp_unionindex380;  slog::Index** mp_mskindex381;  slog::Index** mp_joinindex382;  slog::Index** mp_unionindex383;  slog::Index** mp_join_ansindex384;  slog::Index** mp_mskindex385;  slog::Index** mp_msk_ansindex386;  slog::Index** mp_join_ansindex387;  slog::Index** mp_joindelta388;  slog::Index** mp_mskdelta389;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("mp_union_ans");
      head_index[0] = readrel392->getIndex(ord391, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord393({3, 4, 1, 0, 2});
      slog::Relation* readrel394 = db->getRelation("mp_join");
      mp_joinindex375 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({2, 0, 1});
      slog::Relation* readrel396 = db->getRelation("mp_union");
      mp_unionindex376 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("mp_msk");
      mp_mskindex377 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel400 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index378 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 3, 4, 0});
      slog::Relation* readrel402 = db->getRelation("mbranch");
      mbranchindex379 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1, 2});
      slog::Relation* readrel404 = db->getRelation("mp_union");
      mp_unionindex380 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("mp_msk");
      mp_mskindex381 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 3, 4, 0});
      slog::Relation* readrel408 = db->getRelation("mp_join");
      mp_joinindex382 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 3, 4, 0});
      slog::Relation* readrel410 = db->getRelation("mp_join");
      mp_joindelta388 = readrel410->getIndex(ord409, true);
      std::vector<u16> ord411({0, 1, 2});
      slog::Relation* readrel412 = db->getRelation("mp_union");
      mp_unionindex383 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("mp_join_ans");
      mp_join_ansindex384 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 2, 0});
      slog::Relation* readrel416 = db->getRelation("mp_msk");
      mp_mskindex385 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("mp_msk");
      mp_mskdelta389 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({0, 1});
      slog::Relation* readrel420 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex386 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("mp_join_ans");
      mp_join_ansindex387 = readrel422->getIndex(ord421, false);
  
    }
    ReadTask390(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex375, std::array<u64,5>{v_c15, v_c80, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex376, std::array<u64,3>{v_c80, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex377, std::array<u64,3>{v_c15, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x101x0x0x0index378, std::array<u64,11>{v_c14, v_c15, v_c80, v_c17, v_c5, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m423) {
          u64 v_c81 = m423[5]; u64 v_c7 = m423[6]; u64 v_c8 = m423[7]; u64 v_c9 = m423[8]; u64 v_c10 = m423[9]; u64 v_c82 = m423[10];
          u64 v_c83 = _prim_lt(db, v_c14, v_c8);
          if (v_c83 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c83) return;
          slog::join_probe<5,5>(mbranchindex379, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c82}, [&](const std::array<u64,5>& m425) {
            if (!slog::exists_probe<3,3>(mp_unionindex380, std::array<u64,3>{v_c81, v_c82, v_c80})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex381, std::array<u64,3>{v_c15, v_c8, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex382, mp_joindelta388, std::array<u64,5>{v_c9, v_c82, v_c15, v_c80, 0}, [&](const std::array<u64,5>& m426) {
              u64 v_c84 = m426[4];
              slog::join_probe<3,3>(mp_unionindex383, std::array<u64,3>{v_c81, v_c82, v_c80}, [&](const std::array<u64,3>& m427) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex384, std::array<u64,2>{v_c84, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex385, mp_mskdelta389, std::array<u64,3>{v_c15, v_c8, 0}, [&](const std::array<u64,3>& m428) {
                  u64 v_c85 = m428[2];
                  slog::join_probe<2,1>(mp_msk_ansindex386, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m429) {
                    u64 v_c22 = m429[1];
                    if (v_c9 == v_c22) return;
                    slog::join_probe<2,1>(mp_join_ansindex387, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m430) {
                      u64 v_c61 = m430[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c61}, std::array<u16,2>{0, 1});
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
        ReadTask390* _cont = new ReadTask390(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask390(db,b), false);
  // (crule (pre (let __trid6Qzs660 const11445e6556bc59ce1e80cdf7) (let __trel7Q1f661 constdd7bbf31ce5f578b9805e840) (let __tcol7KRC662 const5feceb66ffc86f38d952786c) (let __trel7hDC663 constdd7bbf31ce5f578b9805e840) (let __tcol0OQ0664 const6b86b273ff34fce19d6b804e)) (scan $sup5638x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid6Qzs660 __trel7Q1f661 __tcol7KRC662 (1 2 3 4 0)) (tycheck n (accept int) __trid6Qzs660 __trel7hDC663 __tcol0OQ0664 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4wem659 p n)) map.slog:111 #f)
  class ReadTask431 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
  
    }
    ReadTask431(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_const11445e6556bc59ce1e80cdf7;
      u64 v_c87 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
      u64 v_c89 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c37 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c15 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c91 = _t[7];
        u64 v_c92 = _t[8];
        u64 v_c17 = _t[9];
        u64 v_c5 = _t[10];
        ++_fires;
        if (!(is_int(v_c9)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c86, v_c87, v_c88, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c14)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c86, v_c89, v_c90, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c9, v_c14}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:$sup5638x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask431* _cont = new ReadTask431(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask431(db,b), false);
  // (crule (pre) (scan temp4cOw1069 __t2UPk363 k v) (body (join mleaf (1 2 0) 2 k v __t9j1T361)) (head (emit mp_put_ans (0 1) __t2UPk363 __t9j1T361)) map.slog:38 #f)
  class ReadTask433 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex432;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord434({0, 1});
      slog::Relation* readrel435 = db->getRelation("mp_put_ans");
      head_index[0] = readrel435->getIndex(ord434, false);
      outer_rel = db->getRelation("temp4cOw1069");
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("mleaf");
      mleafindex432 = readrel437->getIndex(ord436, false);
  
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
        u64 v_c93 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<3,2>(mleafindex432, std::array<u64,3>{v_c3, v_c5, 0}, [&](const std::array<u64,3>& m438) {
          u64 v_c94 = m438[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c93, v_c94}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:temp4cOw1069", _fires);
  
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
  // (crule (pre) (scan mbranch __t1QPr36 q n u v) (body (join mp_union (2 0 1) 1 __t1QPr36 __t0lkv34 __t6xhm35) (join mbranch (0 1 2 3 4) 1 __t6xhm35 p m l r) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t0lkv34 l m q r __t6xhm35 __t1QPr36 u v)) map.slog:111 #f)
  class ReadTask441 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex439;  slog::Index** mbranchindex440;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord442({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel443 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel443->getIndex(ord442, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord444({2, 0, 1});
      slog::Relation* readrel445 = db->getRelation("mp_union");
      mp_unionindex439 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({0, 1, 2, 3, 4});
      slog::Relation* readrel447 = db->getRelation("mbranch");
      mbranchindex440 = readrel447->getIndex(ord446, false);
  
    }
    ReadTask441(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<3,1>(mp_unionindex439, std::array<u64,3>{v_c95, 0, 0}, [&](const std::array<u64,3>& m448) {
          u64 v_c96 = m448[1]; u64 v_c97 = m448[2];
          slog::join_probe<5,1>(mbranchindex440, std::array<u64,5>{v_c97, 0, 0, 0, 0}, [&](const std::array<u64,5>& m449) {
            u64 v_c9 = m449[1]; u64 v_c8 = m449[2]; u64 v_c7 = m449[3]; u64 v_c10 = m449[4];
            u64 v_c98 = _prim_lt(db, v_c8, v_c14);
            if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c98) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c14, v_c9, v_c96, v_c7, v_c8, v_c15, v_c10, v_c97, v_c95, v_c17, v_c5}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan mbranch __t6xhm35 p m l r) (body (join mp_union (1 2 0) 1 __t6xhm35 __t1QPr36 __t0lkv34) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t1QPr36 q n u v) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t0lkv34 l m q r __t6xhm35 __t1QPr36 u v)) map.slog:111 #f)
  class ReadTask454 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex451;  slog::Index** mbranchindex452;  slog::Index** mbranchdelta453;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord455({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel456 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel456->getIndex(ord455, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord457({1, 2, 0});
      slog::Relation* readrel458 = db->getRelation("mp_union");
      mp_unionindex451 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({0, 1, 2, 3, 4});
      slog::Relation* readrel460 = db->getRelation("mbranch");
      mbranchindex452 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({0, 1, 2, 3, 4});
      slog::Relation* readrel462 = db->getRelation("mbranch");
      mbranchdelta453 = readrel462->getIndex(ord461, true);
  
    }
    ReadTask454(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        slog::join_probe<3,1>(mp_unionindex451, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m463) {
          u64 v_c95 = m463[1]; u64 v_c96 = m463[2];
          slog::join_probe_old<5,1>(mbranchindex452, mbranchdelta453, std::array<u64,5>{v_c95, 0, 0, 0, 0}, [&](const std::array<u64,5>& m464) {
            u64 v_c15 = m464[1]; u64 v_c14 = m464[2]; u64 v_c17 = m464[3]; u64 v_c5 = m464[4];
            u64 v_c99 = _prim_lt(db, v_c8, v_c14);
            if (v_c99 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c99) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c14, v_c9, v_c96, v_c7, v_c8, v_c15, v_c10, v_c97, v_c95, v_c17, v_c5}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask454* _cont = new ReadTask454(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask454(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t7c7N419 (bxor p0 p1))) (head (emit-temp temp5uMp1022 __t7c7N419)) map.slog:30 #f)
  class ReadTask466 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5uMp1022");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
  
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
        u64 v_c37 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c38 = _t[4];
        u64 v_c39 = _t[5];
        u64 v_c40 = _t[6];
        u64 v_c101 = _prim_bxor(db, v_c36, v_c38);
        if (v_c101 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c101});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t4QPc174 k m) (body (exists $sup5638x60x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t4QPc174 p) (exists mbranch (1 2 3 4 0) 2 p m) (join $sup5638x60x0x0x0 (1 3 4 0 2 5) 3 k m p __t5APc170 l r) (exists mp_has0 (0 2 1) 2 __t5APc170 k) (exists mp_has0 (1 2 0) 2 l k) (join mbranch (1 2 3 4 0) 4 p m l r __t4G6v169) (join mp_has0 (0 2 1) 3 __t5APc170 k __t4G6v169) (join mp_has0 (1 2 0) 2 l k __t8KSH173) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask479 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index467;  slog::Index** mbranchindex468;  slog::Index** mp_has0index469;  slog::Index** mp_msk_ansindex470;  slog::Index** mbranchindex471;  slog::Index** $sup5638x60x0x0x0index472;  slog::Index** mp_has0index473;  slog::Index** mp_has0index474;  slog::Index** mbranchindex475;  slog::Index** mp_has0index476;  slog::Index** mp_has0index477;  slog::Index** mp_has0_ansindex478;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel481->getIndex(ord480, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord482({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel483 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index467 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({2, 0, 1, 3, 4});
      slog::Relation* readrel485 = db->getRelation("mbranch");
      mbranchindex468 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({2, 0, 1});
      slog::Relation* readrel487 = db->getRelation("mp_has0");
      mp_has0index469 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1});
      slog::Relation* readrel489 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex470 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 3, 4, 0});
      slog::Relation* readrel491 = db->getRelation("mbranch");
      mbranchindex471 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel493 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index472 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 2, 1});
      slog::Relation* readrel495 = db->getRelation("mp_has0");
      mp_has0index473 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({1, 2, 0});
      slog::Relation* readrel497 = db->getRelation("mp_has0");
      mp_has0index474 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 2, 3, 4, 0});
      slog::Relation* readrel499 = db->getRelation("mbranch");
      mbranchindex475 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 2, 1});
      slog::Relation* readrel501 = db->getRelation("mp_has0");
      mp_has0index476 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({1, 2, 0});
      slog::Relation* readrel503 = db->getRelation("mp_has0");
      mp_has0index477 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex478 = readrel505->getIndex(ord504, false);
  
    }
    ReadTask479(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c29 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x60x0x0x0index467, std::array<u64,6>{v_c3, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex468, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index469, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex470, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m506) {
          u64 v_c9 = m506[1];
          if (!slog::exists_probe<5,2>(mbranchindex471, std::array<u64,5>{v_c9, v_c8, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x60x0x0x0index472, std::array<u64,6>{v_c3, v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m507) {
            u64 v_c26 = m507[3]; u64 v_c7 = m507[4]; u64 v_c10 = m507[5];
            if (!slog::exists_probe<3,2>(mp_has0index473, std::array<u64,3>{v_c26, v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index474, std::array<u64,3>{v_c7, v_c3, 0})) return;
            slog::join_probe<5,4>(mbranchindex475, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m508) {
              u64 v_c27 = m508[4];
              slog::join_probe<3,3>(mp_has0index476, std::array<u64,3>{v_c26, v_c3, v_c27}, [&](const std::array<u64,3>& m509) {
                slog::join_probe<3,2>(mp_has0index477, std::array<u64,3>{v_c7, v_c3, 0}, [&](const std::array<u64,3>& m510) {
                  u64 v_c28 = m510[2];
                  slog::join_probe<2,1>(mp_has0_ansindex478, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m511) {
                    u64 v_c30 = m511[1];
                    u64 v_c31 = _prim_band(db, v_c3, v_c8);
                    if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c102 = _prim_lt(db, v_c31, v_c25);
                    if (v_c102 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c102) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c30}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask479* _cont = new ReadTask479(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask479(db,b), false);
  // (crule (pre (let __trid2sEh857 const07d7fbed0aba019c07f7eb8a) (let __trel14Rx858 const20347926ddb307a8e2bdb71b) (let __tcol5gMF859 const4e07408562bedb8b60ce05c1)) (scan mp_msk __t7Ifn141 k m) (body (exists $sup5638x82x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t7Ifn141 p) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t13lF142) (join mp_del_ans (0 1) 1 __t13lF142 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2sEh857 __trel14Rx858 __tcol5gMF859 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __3uQ5856 p m __v0 r)) map.slog:83 #f)
  class ReadTask523 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index513;  slog::Index** mp_delindex514;  slog::Index** mp_msk_ansindex515;  slog::Index** $sup5638x82x0x0x0index516;  slog::Index** mp_delindex517;  slog::Index** mp_del_ansindex518;  slog::Index** mp_deldelta519;
    u32 sid521;  u32 sid520;  u32 sid522;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord524({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel525 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index513 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({2, 0, 1});
      slog::Relation* readrel527 = db->getRelation("mp_del");
      mp_delindex514 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1});
      slog::Relation* readrel529 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex515 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel531 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index516 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("mp_del");
      mp_delindex517 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("mp_del");
      mp_deldelta519 = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_del_ans");
      mp_del_ansindex518 = readrel537->getIndex(ord536, false);
      sid521 = db->getRelation("_enum")->getStructId();
      sid520 = db->getRelation("mbranch")->getStructId();
      sid522 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask523(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c104 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c105 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index513, std::array<u64,6>{v_c3, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex514, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex515, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m538) {
          u64 v_c9 = m538[1];
          slog::join_probe<6,3>($sup5638x82x0x0x0index516, std::array<u64,6>{v_c3, v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m539) {
            u64 v_c37 = m539[3]; u64 v_c7 = m539[4]; u64 v_c10 = m539[5];
            slog::join_probe_old<3,2>(mp_delindex517, mp_deldelta519, std::array<u64,3>{v_c7, v_c3, 0}, [&](const std::array<u64,3>& m540) {
              u64 v_c107 = m540[2];
              slog::join_probe<2,1>(mp_del_ansindex518, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m541) {
                u64 v_c22 = m541[1];
                ++_fires;
                if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid520 || decode_struct_id(v_c10) == sid521 || decode_struct_id(v_c10) == sid522))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c103, v_c104, v_c105, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c22, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask523* _cont = new ReadTask523(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask523(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mp_union_ans __t2wnB100 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t2wnB100 r __t1Mtu99) (exists mbranch (4 0 1 2 3) 1 r) (exists $sup5638x98x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join-old mp_union (2 0 1) 1 (2 0 1) __t1Mtu99 __t2uCs95 __t2SOF94) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t2uCs95 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t2uCs95 r) (join-old mbranch (4 0 1 2 3) 2 (4 0 1 2 3) r __t2SOF94 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t2uCs95) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 (4 1 2 6 0 3 5 7 8) p l m r __t2uCs95 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t1Mtu99) (exists mp_msk (1 2 0) 2 q m) (join-old $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t2uCs95 n q u v __t9ory98) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask567 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex542;  slog::Index** mbranchindex543;  slog::Index** $sup5638x98x0x0x0index544;  slog::Index** $sup5638x98x0x0x1index545;  slog::Index** mp_unionindex546;  slog::Index** $sup5638x98x0x0x0index547;  slog::Index** $sup5638x98x0x0x1index548;  slog::Index** mbranchindex549;  slog::Index** $sup5638x98x0x0x1index550;  slog::Index** mp_mskindex551;  slog::Index** mp_msk_ansindex552;  slog::Index** $sup5638x98x0x0x0index553;  slog::Index** mbranchindex554;  slog::Index** mp_mskindex555;  slog::Index** $sup5638x98x0x0x1index556;  slog::Index** mbranchindex557;  slog::Index** mp_mskindex558;  slog::Index** mp_msk_ansindex559;  slog::Index** mp_uniondelta560;  slog::Index** mp_uniondelta561;  slog::Index** mbranchdelta562;  slog::Index** $sup5638x98x0x0x0delta563;  slog::Index** $sup5638x98x0x0x1delta564;  slog::Index** mbranchdelta565;  slog::Index** mp_mskdelta566;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord568({0, 1, 2});
      slog::Relation* readrel569 = db->getRelation("mp_union");
      mp_unionindex542 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({0, 1, 2});
      slog::Relation* readrel571 = db->getRelation("mp_union");
      mp_uniondelta560 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({4, 0, 1, 2, 3});
      slog::Relation* readrel573 = db->getRelation("mbranch");
      mbranchindex543 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel575 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index544 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel577 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index545 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({2, 0, 1});
      slog::Relation* readrel579 = db->getRelation("mp_union");
      mp_unionindex546 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({2, 0, 1});
      slog::Relation* readrel581 = db->getRelation("mp_union");
      mp_uniondelta561 = readrel581->getIndex(ord580, true);
      std::vector<u16> ord582({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel583 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index547 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel585 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index548 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({4, 0, 1, 2, 3});
      slog::Relation* readrel587 = db->getRelation("mbranch");
      mbranchindex549 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({4, 0, 1, 2, 3});
      slog::Relation* readrel589 = db->getRelation("mbranch");
      mbranchdelta562 = readrel589->getIndex(ord588, true);
      std::vector<u16> ord590({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel591 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index550 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({2, 0, 1});
      slog::Relation* readrel593 = db->getRelation("mp_msk");
      mp_mskindex551 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex552 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel597 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index553 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel599 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0delta563 = readrel599->getIndex(ord598, true);
      std::vector<u16> ord600({1, 2, 3, 4, 0});
      slog::Relation* readrel601 = db->getRelation("mbranch");
      mbranchindex554 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("mp_msk");
      mp_mskindex555 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel605 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index556 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel607 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta564 = readrel607->getIndex(ord606, true);
      std::vector<u16> ord608({1, 2, 3, 4, 0});
      slog::Relation* readrel609 = db->getRelation("mbranch");
      mbranchindex557 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 3, 4, 0});
      slog::Relation* readrel611 = db->getRelation("mbranch");
      mbranchdelta565 = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({1, 2, 0});
      slog::Relation* readrel613 = db->getRelation("mp_msk");
      mp_mskindex558 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 2, 0});
      slog::Relation* readrel615 = db->getRelation("mp_msk");
      mp_mskdelta566 = readrel615->getIndex(ord614, true);
      std::vector<u16> ord616({0, 1});
      slog::Relation* readrel617 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex559 = readrel617->getIndex(ord616, false);
  
    }
    ReadTask567(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c109 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex542, mp_uniondelta560, std::array<u64,3>{v_c109, 0, 0}, [&](const std::array<u64,3>& m618) {
          u64 v_c10 = m618[1]; u64 v_c110 = m618[2];
          if (!slog::exists_probe<5,1>(mbranchindex543, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index544, std::array<u64,9>{v_c10, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index545, std::array<u64,10>{v_c10, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex546, mp_uniondelta561, std::array<u64,3>{v_c110, 0, 0}, [&](const std::array<u64,3>& m619) {
            u64 v_c111 = m619[1]; u64 v_c112 = m619[2];
            if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index547, std::array<u64,9>{v_c111, v_c10, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index548, std::array<u64,10>{v_c111, v_c10, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex549, mbranchdelta562, std::array<u64,5>{v_c10, v_c112, 0, 0, 0}, [&](const std::array<u64,5>& m620) {
              u64 v_c9 = m620[2]; u64 v_c8 = m620[3]; u64 v_c7 = m620[4];
              if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index550, std::array<u64,10>{v_c10, v_c7, v_c8, v_c9, v_c111, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex551, std::array<u64,3>{v_c8, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex552, std::array<u64,2>{v_c9, 0})) return;
              slog::join_probe_old<9,5>($sup5638x98x0x0x0index553, $sup5638x98x0x0x0delta563, std::array<u64,9>{v_c9, v_c7, v_c8, v_c10, v_c111, 0, 0, 0, 0}, [&](const std::array<u64,9>& m621) {
                u64 v_c14 = m621[5]; u64 v_c15 = m621[6]; u64 v_c17 = m621[7]; u64 v_c5 = m621[8];
                u64 v_c113 = _prim_lt(db, v_c14, v_c8);
                if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                if (!v_c113) return;
                if (!slog::exists_probe<5,5>(mbranchindex554, std::array<u64,5>{v_c15, v_c14, v_c17, v_c5, v_c110})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex555, std::array<u64,3>{v_c15, v_c8, 0})) return;
                slog::join_probe_old<10,9>($sup5638x98x0x0x1index556, $sup5638x98x0x0x1delta564, std::array<u64,10>{v_c10, v_c7, v_c8, v_c9, v_c111, v_c14, v_c15, v_c17, v_c5, 0}, [&](const std::array<u64,10>& m623) {
                  u64 v_c114 = m623[9];
                  slog::join_probe_old<5,5>(mbranchindex557, mbranchdelta565, std::array<u64,5>{v_c15, v_c14, v_c17, v_c5, v_c110}, [&](const std::array<u64,5>& m624) {
                    slog::join_probe_old<3,3>(mp_mskindex558, mp_mskdelta566, std::array<u64,3>{v_c15, v_c8, v_c114}, [&](const std::array<u64,3>& m625) {
                      slog::join_probe<2,2>(mp_msk_ansindex559, std::array<u64,2>{v_c114, v_c9}, [&](const std::array<u64,2>& m626) {
                        u64 v_c115 = _prim_band(db, v_c15, v_c8);
                        if (v_c115 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c116 = _prim_gt(db, v_c115, v_c108);
                        if (v_c116 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c116) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c111, v_c22, v_c7, v_c8, v_c9});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask567* _cont = new ReadTask567(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask567(db,b), false);
  // (crule (pre) (scan mp_union __t2Oaj263 l u) (body (exists $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 l u) (exists mbranch (3 0 1 2 4) 1 u) (exists mbranch (3 0 1 2 4) 1 l) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0) (join $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 l u __t9rnk262 m p r v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 r v) (join mbranch (1 2 3 4 0) 4 p m u v __t5rXw260) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (join mbranch (1 2 3 4 0) 4 p m l r __t2wpn261) (join mp_union (0 1 2) 3 __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask642 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index628;  slog::Index** mbranchindex629;  slog::Index** mbranchindex630;  slog::Index** mp_union_ansindex631;  slog::Index** $sup5638x93x0x0x0index632;  slog::Index** mbranchindex633;  slog::Index** mp_unionindex634;  slog::Index** mbranchindex635;  slog::Index** mp_unionindex636;  slog::Index** mbranchindex637;  slog::Index** mp_unionindex638;  slog::Index** mp_unionindex639;  slog::Index** mp_union_ansindex640;  slog::Index** mp_uniondelta641;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord643({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel644 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index628 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({3, 0, 1, 2, 4});
      slog::Relation* readrel646 = db->getRelation("mbranch");
      mbranchindex629 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({3, 0, 1, 2, 4});
      slog::Relation* readrel648 = db->getRelation("mbranch");
      mbranchindex630 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({0, 1});
      slog::Relation* readrel650 = db->getRelation("mp_union_ans");
      mp_union_ansindex631 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel652 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index632 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 3, 4, 0});
      slog::Relation* readrel654 = db->getRelation("mbranch");
      mbranchindex633 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({1, 2, 0});
      slog::Relation* readrel656 = db->getRelation("mp_union");
      mp_unionindex634 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({1, 2, 3, 4, 0});
      slog::Relation* readrel658 = db->getRelation("mbranch");
      mbranchindex635 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({2, 0, 1});
      slog::Relation* readrel660 = db->getRelation("mp_union");
      mp_unionindex636 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 2, 3, 4, 0});
      slog::Relation* readrel662 = db->getRelation("mbranch");
      mbranchindex637 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({0, 1, 2});
      slog::Relation* readrel664 = db->getRelation("mp_union");
      mp_unionindex638 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("mp_union");
      mp_unionindex639 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 0});
      slog::Relation* readrel668 = db->getRelation("mp_union");
      mp_uniondelta641 = readrel668->getIndex(ord667, true);
      std::vector<u16> ord669({0, 1});
      slog::Relation* readrel670 = db->getRelation("mp_union_ans");
      mp_union_ansindex640 = readrel670->getIndex(ord669, false);
  
    }
    ReadTask642(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c117 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x93x0x0x0index628, std::array<u64,7>{v_c7, v_c17, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex629, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex630, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex631, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m671) {
          u64 v_c22 = m671[1];
          slog::join_probe<7,2>($sup5638x93x0x0x0index632, std::array<u64,7>{v_c7, v_c17, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m672) {
            u64 v_c118 = m672[2]; u64 v_c8 = m672[3]; u64 v_c9 = m672[4]; u64 v_c10 = m672[5]; u64 v_c5 = m672[6];
            if (!slog::exists_probe<5,4>(mbranchindex633, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex634, std::array<u64,3>{v_c10, v_c5, 0})) return;
            slog::join_probe<5,4>(mbranchindex635, std::array<u64,5>{v_c9, v_c8, v_c17, v_c5, 0}, [&](const std::array<u64,5>& m673) {
              u64 v_c119 = m673[4];
              if (!slog::exists_probe<3,2>(mp_unionindex636, std::array<u64,3>{v_c119, v_c118, 0})) return;
              slog::join_probe<5,4>(mbranchindex637, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m674) {
                u64 v_c120 = m674[4];
                slog::join_probe<3,3>(mp_unionindex638, std::array<u64,3>{v_c118, v_c120, v_c119}, [&](const std::array<u64,3>& m675) {
                  slog::join_probe_old<3,2>(mp_unionindex639, mp_uniondelta641, std::array<u64,3>{v_c10, v_c5, 0}, [&](const std::array<u64,3>& m676) {
                    u64 v_c121 = m676[2];
                    slog::join_probe<2,1>(mp_union_ansindex640, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m677) {
                      u64 v_c54 = m677[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c118, v_c22, v_c54, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c22, v_c54}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mp_union __t0mSQ44 __t39oH43 __t499t48) (body (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t0mSQ44) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 1 __t0mSQ44) (join-old mp_union (2 0 1) 1 (2 0 1) __t499t48 __t2OJC49 l) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t0mSQ44 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t0mSQ44 l) (exists mp_union_ans (0 1) 1 __t2OJC49) (join mbranch (3 0 1 2 4) 2 l __t39oH43 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t0mSQ44) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t0mSQ44 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t499t48) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t0mSQ44 n q u v __t0xN947) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t499t48) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask699 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index678;  slog::Index** $sup5638x95x0x0x1index679;  slog::Index** mp_unionindex680;  slog::Index** $sup5638x95x0x0x0index681;  slog::Index** $sup5638x95x0x0x1index682;  slog::Index** mp_union_ansindex683;  slog::Index** mbranchindex684;  slog::Index** $sup5638x95x0x0x1index685;  slog::Index** mp_mskindex686;  slog::Index** mp_msk_ansindex687;  slog::Index** $sup5638x95x0x0x0index688;  slog::Index** mbranchindex689;  slog::Index** mp_mskindex690;  slog::Index** $sup5638x95x0x0x1index691;  slog::Index** mbranchindex692;  slog::Index** mp_mskindex693;  slog::Index** mp_msk_ansindex694;  slog::Index** mp_union_ansindex695;  slog::Index** mp_uniondelta696;  slog::Index** mbranchdelta697;  slog::Index** mp_mskdelta698;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord700({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel701 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index678 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel703 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index679 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({2, 0, 1});
      slog::Relation* readrel705 = db->getRelation("mp_union");
      mp_unionindex680 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 0, 1});
      slog::Relation* readrel707 = db->getRelation("mp_union");
      mp_uniondelta696 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel709 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index681 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel711 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index682 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({0, 1});
      slog::Relation* readrel713 = db->getRelation("mp_union_ans");
      mp_union_ansindex683 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({3, 0, 1, 2, 4});
      slog::Relation* readrel715 = db->getRelation("mbranch");
      mbranchindex684 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel717 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index685 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({2, 0, 1});
      slog::Relation* readrel719 = db->getRelation("mp_msk");
      mp_mskindex686 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 0});
      slog::Relation* readrel721 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex687 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel723 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index688 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 3, 4, 0});
      slog::Relation* readrel725 = db->getRelation("mbranch");
      mbranchindex689 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 2, 0});
      slog::Relation* readrel727 = db->getRelation("mp_msk");
      mp_mskindex690 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel729 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index691 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 3, 4, 0});
      slog::Relation* readrel731 = db->getRelation("mbranch");
      mbranchindex692 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 2, 3, 4, 0});
      slog::Relation* readrel733 = db->getRelation("mbranch");
      mbranchdelta697 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({1, 2, 0});
      slog::Relation* readrel735 = db->getRelation("mp_msk");
      mp_mskindex693 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 2, 0});
      slog::Relation* readrel737 = db->getRelation("mp_msk");
      mp_mskdelta698 = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex694 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({0, 1});
      slog::Relation* readrel741 = db->getRelation("mp_union_ans");
      mp_union_ansindex695 = readrel741->getIndex(ord740, false);
  
    }
    ReadTask699(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c123 = _t[0];
        u64 v_c124 = _t[1];
        u64 v_c125 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index678, std::array<u64,9>{v_c123, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index679, std::array<u64,10>{v_c123, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex680, mp_uniondelta696, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m742) {
          u64 v_c126 = m742[1]; u64 v_c7 = m742[2];
          if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index681, std::array<u64,9>{v_c123, v_c7, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index682, std::array<u64,10>{v_c123, v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex683, std::array<u64,2>{v_c126, 0})) return;
          slog::join_probe<5,2>(mbranchindex684, std::array<u64,5>{v_c7, v_c124, 0, 0, 0}, [&](const std::array<u64,5>& m743) {
            u64 v_c9 = m743[2]; u64 v_c8 = m743[3]; u64 v_c10 = m743[4];
            if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index685, std::array<u64,10>{v_c7, v_c8, v_c9, v_c10, v_c123, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex686, std::array<u64,3>{v_c8, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex687, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<9,5>($sup5638x95x0x0x0index688, std::array<u64,9>{v_c7, v_c8, v_c9, v_c10, v_c123, 0, 0, 0, 0}, [&](const std::array<u64,9>& m744) {
              u64 v_c14 = m744[5]; u64 v_c15 = m744[6]; u64 v_c17 = m744[7]; u64 v_c5 = m744[8];
              u64 v_c127 = _prim_lt(db, v_c14, v_c8);
              if (v_c127 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
              if (!v_c127) return;
              if (!slog::exists_probe<5,5>(mbranchindex689, std::array<u64,5>{v_c15, v_c14, v_c17, v_c5, v_c125})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex690, std::array<u64,3>{v_c15, v_c8, 0})) return;
              slog::join_probe<10,9>($sup5638x95x0x0x1index691, std::array<u64,10>{v_c7, v_c8, v_c9, v_c10, v_c123, v_c14, v_c15, v_c17, v_c5, 0}, [&](const std::array<u64,10>& m746) {
                u64 v_c128 = m746[9];
                slog::join_probe_old<5,5>(mbranchindex692, mbranchdelta697, std::array<u64,5>{v_c15, v_c14, v_c17, v_c5, v_c125}, [&](const std::array<u64,5>& m747) {
                  slog::join_probe_old<3,3>(mp_mskindex693, mp_mskdelta698, std::array<u64,3>{v_c15, v_c8, v_c128}, [&](const std::array<u64,3>& m748) {
                    slog::join_probe<2,2>(mp_msk_ansindex694, std::array<u64,2>{v_c128, v_c9}, [&](const std::array<u64,2>& m749) {
                      slog::join_probe<2,1>(mp_union_ansindex695, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m750) {
                        u64 v_c22 = m750[1];
                        u64 v_c129 = _prim_band(db, v_c15, v_c8);
                        if (v_c129 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c130 = _prim_lt(db, v_c129, v_c122);
                        if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c130) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c123, v_c22, v_c8, v_c9, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c22, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask699* _cont = new ReadTask699(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask699(db,b), false);
  // (crule (pre) (scan mbranch __t51uB429 p m l r) (body (exists mp_put (1 2 0 3) 1 __t51uB429) (exists mp_join (3 4 1 0 2) 2 p __t51uB429) (exists mp_msk (2 0 1) 1 m) (join $sup5638x44x0x0x0 (2 3 4 5 6 0 1 7) 5 l m p r __t51uB429 __t5vsG428 k v) (join mp_put (1 2 0 3) 4 __t51uB429 k __t5vsG428 v) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t51uB429 k __t9vyw431 __t9k3L430) (join-old mleaf (0 1 2) 3 (0 1 2) __t9k3L430 k v) (exists mp_join_ans (0 1) 1 __t9vyw431) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask768 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex752;  slog::Index** mp_joinindex753;  slog::Index** mp_mskindex754;  slog::Index** $sup5638x44x0x0x0index755;  slog::Index** mp_putindex756;  slog::Index** mleafindex757;  slog::Index** mp_mskindex758;  slog::Index** mp_joinindex759;  slog::Index** mleafindex760;  slog::Index** mp_join_ansindex761;  slog::Index** mp_mskindex762;  slog::Index** mp_msk_ansindex763;  slog::Index** mp_join_ansindex764;  slog::Index** mp_joindelta765;  slog::Index** mleafdelta766;  slog::Index** mp_mskdelta767;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord769({0, 1});
      slog::Relation* readrel770 = db->getRelation("mp_put_ans");
      head_index[0] = readrel770->getIndex(ord769, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord771({1, 2, 0, 3});
      slog::Relation* readrel772 = db->getRelation("mp_put");
      mp_putindex752 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({3, 4, 1, 0, 2});
      slog::Relation* readrel774 = db->getRelation("mp_join");
      mp_joinindex753 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({2, 0, 1});
      slog::Relation* readrel776 = db->getRelation("mp_msk");
      mp_mskindex754 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({2, 3, 4, 5, 6, 0, 1, 7});
      slog::Relation* readrel778 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index755 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 2, 0, 3});
      slog::Relation* readrel780 = db->getRelation("mp_put");
      mp_putindex756 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("mleaf");
      mleafindex757 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 2, 0});
      slog::Relation* readrel784 = db->getRelation("mp_msk");
      mp_mskindex758 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({3, 4, 1, 0, 2});
      slog::Relation* readrel786 = db->getRelation("mp_join");
      mp_joinindex759 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({3, 4, 1, 0, 2});
      slog::Relation* readrel788 = db->getRelation("mp_join");
      mp_joindelta765 = readrel788->getIndex(ord787, true);
      std::vector<u16> ord789({0, 1, 2});
      slog::Relation* readrel790 = db->getRelation("mleaf");
      mleafindex760 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({0, 1, 2});
      slog::Relation* readrel792 = db->getRelation("mleaf");
      mleafdelta766 = readrel792->getIndex(ord791, true);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("mp_join_ans");
      mp_join_ansindex761 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 2, 0});
      slog::Relation* readrel796 = db->getRelation("mp_msk");
      mp_mskindex762 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 2, 0});
      slog::Relation* readrel798 = db->getRelation("mp_msk");
      mp_mskdelta767 = readrel798->getIndex(ord797, true);
      std::vector<u16> ord799({0, 1});
      slog::Relation* readrel800 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex763 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 1});
      slog::Relation* readrel802 = db->getRelation("mp_join_ans");
      mp_join_ansindex764 = readrel802->getIndex(ord801, false);
  
    }
    ReadTask768(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<4,1>(mp_putindex752, std::array<u64,4>{v_c131, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mp_joinindex753, std::array<u64,5>{v_c9, v_c131, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex754, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<8,5>($sup5638x44x0x0x0index755, std::array<u64,8>{v_c7, v_c8, v_c9, v_c10, v_c131, 0, 0, 0}, [&](const std::array<u64,8>& m803) {
          u64 v_c132 = m803[5]; u64 v_c3 = m803[6]; u64 v_c5 = m803[7];
          slog::join_probe<4,4>(mp_putindex756, std::array<u64,4>{v_c131, v_c3, v_c132, v_c5}, [&](const std::array<u64,4>& m804) {
            if (!slog::exists_probe<3,2>(mleafindex757, std::array<u64,3>{v_c3, v_c5, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex758, std::array<u64,3>{v_c3, v_c8, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex759, mp_joindelta765, std::array<u64,5>{v_c9, v_c131, v_c3, 0, 0}, [&](const std::array<u64,5>& m805) {
              u64 v_c133 = m805[3]; u64 v_c134 = m805[4];
              slog::join_probe_old<3,3>(mleafindex760, mleafdelta766, std::array<u64,3>{v_c134, v_c3, v_c5}, [&](const std::array<u64,3>& m806) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex761, std::array<u64,2>{v_c133, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex762, mp_mskdelta767, std::array<u64,3>{v_c3, v_c8, 0}, [&](const std::array<u64,3>& m807) {
                  u64 v_c135 = m807[2];
                  slog::join_probe<2,1>(mp_msk_ansindex763, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m808) {
                    u64 v_c22 = m808[1];
                    if (v_c9 == v_c22) return;
                    slog::join_probe<2,1>(mp_join_ansindex764, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m809) {
                      u64 v_c61 = m809[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c132, v_c61}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask768* _cont = new ReadTask768(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask768(db,b), false);
  // (crule (pre (let __tconst0Qj0123 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9IJy121 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t9IJy121 k __t8oJB122) (let __t0Fhz124 (band k m)) (cmp lt __t0Fhz124 __tconst0Qj0123)) (head (emit $sup5638x82x0x0x0 (4 3 5 2 0 1) p m r l __t8oJB122 k)) map.slog:83 #f)
  class ReadTask812 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex810;  slog::Index** mp_deldelta811;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord813({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel814 = db->getRelation("$sup5638x82x0x0x0");
      head_index[0] = readrel814->getIndex(ord813, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("mp_del");
      mp_delindex810 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("mp_del");
      mp_deldelta811 = readrel818->getIndex(ord817, true);
  
    }
    ReadTask812(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c137 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex810, mp_deldelta811, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m819) {
          u64 v_c3 = m819[1]; u64 v_c138 = m819[2];
          u64 v_c139 = _prim_band(db, v_c3, v_c8);
          if (v_c139 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          u64 v_c140 = _prim_lt(db, v_c139, v_c136);
          if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          if (!v_c140) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c9, v_c8, v_c10, v_c7, v_c138, v_c3}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask812* _cont = new ReadTask812(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask812(db,b), false);
  // (crule (pre) (scan mleaf __t9f1X151 j v) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t9f1X151 k __t24ml152) (neq j k)) (head (emit mp_del_ans (0 1) __t24ml152 __t9f1X151)) map.slog:81 #f)
  class ReadTask823 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex821;  slog::Index** mp_deldelta822;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("mp_del_ans");
      head_index[0] = readrel825->getIndex(ord824, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("mp_del");
      mp_delindex821 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("mp_del");
      mp_deldelta822 = readrel829->getIndex(ord828, true);
  
    }
    ReadTask823(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c141 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe_old<3,1>(mp_delindex821, mp_deldelta822, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m830) {
          u64 v_c3 = m830[1]; u64 v_c142 = m830[2];
          if (v_c1 == v_c3) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c142, v_c141}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:81", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask823* _cont = new ReadTask823(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask823(db,b), false);
}

