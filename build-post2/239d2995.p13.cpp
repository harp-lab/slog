
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3cd26ab9ce3085a816a74a29;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6c3d8aa344844f80a370de02;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_consta2d3b5b64cd0c50598de1133;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;


void slog_rules_c04f93a1558b3b6fd(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst72QR693 constd01925b37634a1a9d24159d8)) (scan mp_bld __t746K136 p m l __t7KX2135) (body (join _enum (0 1) 2 __t7KX2135 __tconst72QR693)) (head (emit mp_bld_ans (0 1) __t746K136 l)) map.slog:74 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord4({0, 1});
      slog::Relation* readrel5 = db->getRelation("_enum");
      _enumindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<2,2>(_enumindex0, std::array<u64,2>{v_c5, v_c0}, [&](const std::array<u64,2>& m6) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c4}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:74", "delta:mp_bld", _fires);
  
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
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t1lh0397 __v3) (body (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists $sup5638x29x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t1lh0397 __v3) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t1lh0397) (join-old mp_hsb_ans (0 1) 1 (0 1) __t1lh0397 __v1) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t1lh0397 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join-old mp_hsb_ans (0 1) 1 (0 1) __t1lh0397 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t1lh0397 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t1lh0397 __v0 __v3 __v1 __t4lFL393 dup0XDZ1075 dup8FhK1076 p0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join-old mp_msk_ans (0 1) 1 (0 1) __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex7;  slog::Index** $sup5638x29x0x0x2index8;  slog::Index** $sup5638x29x0x0x1index9;  slog::Index** mp_hsb_ansindex10;  slog::Index** $sup5638x29x0x0x2index11;  slog::Index** mp_mskindex12;  slog::Index** mp_hsb_ansindex13;  slog::Index** $sup5638x29x0x0x1index14;  slog::Index** $sup5638x29x0x0x2index15;  slog::Index** $sup5638x29x0x0x1index16;  slog::Index** $sup5638x29x0x0x0index17;  slog::Index** mp_joinindex18;  slog::Index** mp_mskindex19;  slog::Index** mp_msk_ansindex20;  slog::Index** mp_hsbindex21;  slog::Index** mp_hsb_ansdelta22;  slog::Index** mp_hsb_ansdelta23;  slog::Index** mp_joindelta24;  slog::Index** mp_mskdelta25;  slog::Index** mp_msk_ansdelta26;  slog::Index** mp_hsbdelta27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex7 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel32 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index8 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel34 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index9 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex10 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta22 = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel40 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index11 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 0, 1});
      slog::Relation* readrel42 = db->getRelation("mp_msk");
      mp_mskindex12 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex13 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta23 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel48 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index14 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel50 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index15 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel52 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index16 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0, 2, 3, 4});
      slog::Relation* readrel54 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index17 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 3, 4, 0});
      slog::Relation* readrel56 = db->getRelation("mp_join");
      mp_joinindex18 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 3, 4, 0});
      slog::Relation* readrel58 = db->getRelation("mp_join");
      mp_joindelta24 = readrel58->getIndex(ord57, true);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("mp_msk");
      mp_mskindex19 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("mp_msk");
      mp_mskdelta25 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex20 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta26 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("mp_hsb");
      mp_hsbindex21 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("mp_hsb");
      mp_hsbdelta27 = readrel70->getIndex(ord69, true);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex7, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index8, std::array<u64,11>{v_c7, v_c8, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index9, std::array<u64,7>{v_c7, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(mp_hsb_ansindex10, mp_hsb_ansdelta22, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m71) {
          u64 v_c9 = m71[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index11, std::array<u64,11>{v_c7, v_c9, v_c8, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex12, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex13, mp_hsb_ansdelta23, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m72) {
            u64 v_c10 = m72[1];
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index14, std::array<u64,7>{v_c7, v_c10, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index15, std::array<u64,11>{v_c7, v_c10, v_c8, v_c9, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m73) {
              u64 v_c11 = m73[4]; u64 v_c12 = m73[5]; u64 v_c13 = m73[6]; u64 v_c14 = m73[7]; u64 v_c15 = m73[8]; u64 v_c16 = m73[9]; u64 v_c17 = m73[10];
              if (v_c7 != v_c13) return;
              if (v_c7 != v_c12) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index16, std::array<u64,7>{v_c11, v_c14, v_c15, v_c16, v_c17, v_c7, v_c10}, [&](const std::array<u64,7>& m74) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index17, std::array<u64,5>{v_c14, v_c11, v_c15, v_c16, v_c17}, [&](const std::array<u64,5>& m75) {
                  slog::join_probe_old<5,5>(mp_joinindex18, mp_joindelta24, std::array<u64,5>{v_c14, v_c16, v_c15, v_c17, v_c11}, [&](const std::array<u64,5>& m76) {
                    slog::join_probe_old<3,2>(mp_mskindex19, mp_mskdelta25, std::array<u64,3>{v_c14, v_c9, 0}, [&](const std::array<u64,3>& m77) {
                      u64 v_c18 = m77[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex20, mp_msk_ansdelta26, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m78) {
                        u64 v_c19 = m78[1];
                        u64 v_c20 = _prim_bxor(db, v_c14, v_c15);
                        if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex21, mp_hsbdelta27, std::array<u64,2>{v_c7, v_c20}, [&](const std::array<u64,2>& m79) {
                          u64 v_c21 = _prim_band(db, v_c14, v_c10);
                          if (v_c21 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c22 = _prim_gt(db, v_c21, v_c6);
                          if (v_c22 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c22) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c11, v_c19, v_c8, v_c16, v_c17});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c19, v_c8, v_c17, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan $sup5638x84x0x0x0 __t01YW404 k l m p r) (body (exists mp_del (0 2 1) 2 __t01YW404 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0VzH403) (join-old mp_del (0 2 1) 3 (0 2 1) __t01YW404 k __t0VzH403) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8Ai5407) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join mp_del_ans (0 1) 2 __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex81;  slog::Index** mp_bldindex82;  slog::Index** mp_mskindex83;  slog::Index** mp_msk_ansindex84;  slog::Index** mp_delindex85;  slog::Index** mbranchindex86;  slog::Index** mp_delindex87;  slog::Index** mp_bldindex88;  slog::Index** mp_del_ansindex89;  slog::Index** mp_bld_ansindex90;  slog::Index** mp_mskindex91;  slog::Index** mp_msk_ansindex92;  slog::Index** mp_delindex93;  slog::Index** mp_del_ansindex94;  slog::Index** mp_bld_ansindex95;  slog::Index** mbranchdelta96;  slog::Index** mp_deldelta97;  slog::Index** mp_blddelta98;  slog::Index** mp_mskdelta99;  slog::Index** mp_deldelta100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("mp_del_ans");
      head_index[0] = readrel103->getIndex(ord102, false);
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord104({0, 2, 1});
      slog::Relation* readrel105 = db->getRelation("mp_del");
      mp_delindex81 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 3, 4, 0});
      slog::Relation* readrel107 = db->getRelation("mp_bld");
      mp_bldindex82 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("mp_msk");
      mp_mskindex83 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex84 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("mp_del");
      mp_delindex85 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 2, 3, 4, 0});
      slog::Relation* readrel115 = db->getRelation("mbranch");
      mbranchindex86 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 3, 4, 0});
      slog::Relation* readrel117 = db->getRelation("mbranch");
      mbranchdelta96 = readrel117->getIndex(ord116, true);
      std::vector<u16> ord118({0, 2, 1});
      slog::Relation* readrel119 = db->getRelation("mp_del");
      mp_delindex87 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({0, 2, 1});
      slog::Relation* readrel121 = db->getRelation("mp_del");
      mp_deldelta97 = readrel121->getIndex(ord120, true);
      std::vector<u16> ord122({1, 2, 3, 4, 0});
      slog::Relation* readrel123 = db->getRelation("mp_bld");
      mp_bldindex88 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 3, 4, 0});
      slog::Relation* readrel125 = db->getRelation("mp_bld");
      mp_blddelta98 = readrel125->getIndex(ord124, true);
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("mp_del_ans");
      mp_del_ansindex89 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex90 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("mp_msk");
      mp_mskindex91 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("mp_msk");
      mp_mskdelta99 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({0, 1});
      slog::Relation* readrel135 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex92 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("mp_del");
      mp_delindex93 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("mp_del");
      mp_deldelta100 = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("mp_del_ans");
      mp_del_ansindex94 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex95 = readrel143->getIndex(ord142, false);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c26 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex81, std::array<u64,3>{v_c24, v_c25, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex82, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex83, std::array<u64,3>{v_c25, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex84, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex85, std::array<u64,3>{v_c26, v_c25, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex86, mbranchdelta96, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, 0}, [&](const std::array<u64,5>& m144) {
          u64 v_c27 = m144[4];
          slog::join_probe_old<3,3>(mp_delindex87, mp_deldelta97, std::array<u64,3>{v_c24, v_c25, v_c27}, [&](const std::array<u64,3>& m145) {
            slog::join_probe_old<5,3>(mp_bldindex88, mp_blddelta98, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0}, [&](const std::array<u64,5>& m146) {
              u64 v_c10 = m146[3]; u64 v_c28 = m146[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex89, std::array<u64,2>{v_c10, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex90, std::array<u64,2>{v_c28, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex91, mp_mskdelta99, std::array<u64,3>{v_c25, v_c3, 0}, [&](const std::array<u64,3>& m147) {
                u64 v_c29 = m147[2];
                slog::join_probe<2,2>(mp_msk_ansindex92, std::array<u64,2>{v_c29, v_c2}, [&](const std::array<u64,2>& m148) {
                  slog::join_probe_old<3,2>(mp_delindex93, mp_deldelta100, std::array<u64,3>{v_c26, v_c25, 0}, [&](const std::array<u64,3>& m149) {
                    u64 v_c30 = m149[2];
                    slog::join_probe<2,2>(mp_del_ansindex94, std::array<u64,2>{v_c30, v_c10}, [&](const std::array<u64,2>& m150) {
                      slog::join_probe<2,1>(mp_bld_ansindex95, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m151) {
                        u64 v_c31 = m151[1];
                        u64 v_c32 = _prim_band(db, v_c25, v_c3);
                        if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c33 = _prim_gt(db, v_c32, v_c23);
                        if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c33) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask101* _cont = new ReadTask101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask101(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_bld_ans __t0Lvo157 res) (body (join-old mp_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t0Lvo157 p m __v0 r) (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (join-old mbranch (1 2 4 0 3) 3 (1 2 4 0 3) p m r __t85IU153 l) (exists mp_del (1 2 0) 1 __t85IU153) (exists mp_del (1 2 0) 1 l) (join-old $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 (4 3 5 2 0 1) p m r l __t8KQn154 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t8KQn154 k __t85IU153) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join-old mp_msk_ans (0 1) 2 (0 1) __t1jAB158 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join-old mp_del_ans (0 1) 2 (0 1) __t5pOj159 __v0) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex153;  slog::Index** $sup5638x82x0x0x0index154;  slog::Index** mp_mskindex155;  slog::Index** mp_msk_ansindex156;  slog::Index** mp_del_ansindex157;  slog::Index** mbranchindex158;  slog::Index** mp_delindex159;  slog::Index** mp_delindex160;  slog::Index** $sup5638x82x0x0x0index161;  slog::Index** mp_delindex162;  slog::Index** mp_delindex163;  slog::Index** mp_mskindex164;  slog::Index** mp_msk_ansindex165;  slog::Index** mp_delindex166;  slog::Index** mp_del_ansindex167;  slog::Index** mp_blddelta168;  slog::Index** mbranchdelta169;  slog::Index** $sup5638x82x0x0x0delta170;  slog::Index** mp_deldelta171;  slog::Index** mp_mskdelta172;  slog::Index** mp_msk_ansdelta173;  slog::Index** mp_deldelta174;  slog::Index** mp_del_ansdelta175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("mp_del_ans");
      head_index[0] = readrel178->getIndex(ord177, false);
      outer_rel = db->getRelation("mp_bld_ans");
      std::vector<u16> ord179({0, 1, 2, 3, 4});
      slog::Relation* readrel180 = db->getRelation("mp_bld");
      mp_bldindex153 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1, 2, 3, 4});
      slog::Relation* readrel182 = db->getRelation("mp_bld");
      mp_blddelta168 = readrel182->getIndex(ord181, true);
      std::vector<u16> ord183({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel184 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index154 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({2, 0, 1});
      slog::Relation* readrel186 = db->getRelation("mp_msk");
      mp_mskindex155 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex156 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("mp_del_ans");
      mp_del_ansindex157 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 4, 0, 3});
      slog::Relation* readrel192 = db->getRelation("mbranch");
      mbranchindex158 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 4, 0, 3});
      slog::Relation* readrel194 = db->getRelation("mbranch");
      mbranchdelta169 = readrel194->getIndex(ord193, true);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("mp_del");
      mp_delindex159 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("mp_del");
      mp_delindex160 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel200 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index161 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel202 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta170 = readrel202->getIndex(ord201, true);
      std::vector<u16> ord203({0, 2, 1});
      slog::Relation* readrel204 = db->getRelation("mp_del");
      mp_delindex162 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 2, 1});
      slog::Relation* readrel206 = db->getRelation("mp_del");
      mp_deldelta171 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("mp_del");
      mp_delindex163 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("mp_msk");
      mp_mskindex164 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 0});
      slog::Relation* readrel212 = db->getRelation("mp_msk");
      mp_mskdelta172 = readrel212->getIndex(ord211, true);
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex165 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta173 = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("mp_del");
      mp_delindex166 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("mp_del");
      mp_deldelta174 = readrel220->getIndex(ord219, true);
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("mp_del_ans");
      mp_del_ansindex167 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({0, 1});
      slog::Relation* readrel224 = db->getRelation("mp_del_ans");
      mp_del_ansdelta175 = readrel224->getIndex(ord223, true);
  
    }
    ReadTask176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c31 = _t[1];
        slog::join_probe_old<5,1>(mp_bldindex153, mp_blddelta168, std::array<u64,5>{v_c35, 0, 0, 0, 0}, [&](const std::array<u64,5>& m225) {
          u64 v_c2 = m225[1]; u64 v_c3 = m225[2]; u64 v_c10 = m225[3]; u64 v_c26 = m225[4];
          if (!slog::exists_probe<6,3>($sup5638x82x0x0x0index154, std::array<u64,6>{v_c2, v_c3, v_c26, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex155, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex156, std::array<u64,2>{v_c2, 0})) return;
          if (!slog::exists_probe<2,1>(mp_del_ansindex157, std::array<u64,2>{v_c10, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex158, mbranchdelta169, std::array<u64,5>{v_c2, v_c3, v_c26, 0, 0}, [&](const std::array<u64,5>& m226) {
            u64 v_c36 = m226[3]; u64 v_c4 = m226[4];
            if (!slog::exists_probe<3,1>(mp_delindex159, std::array<u64,3>{v_c36, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_delindex160, std::array<u64,3>{v_c4, 0, 0})) return;
            slog::join_probe_old<6,4>($sup5638x82x0x0x0index161, $sup5638x82x0x0x0delta170, std::array<u64,6>{v_c2, v_c3, v_c26, v_c4, 0, 0}, [&](const std::array<u64,6>& m227) {
              u64 v_c37 = m227[4]; u64 v_c25 = m227[5];
              slog::join_probe_old<3,3>(mp_delindex162, mp_deldelta171, std::array<u64,3>{v_c37, v_c25, v_c36}, [&](const std::array<u64,3>& m228) {
                if (!slog::exists_probe<3,2>(mp_delindex163, std::array<u64,3>{v_c4, v_c25, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex164, mp_mskdelta172, std::array<u64,3>{v_c25, v_c3, 0}, [&](const std::array<u64,3>& m229) {
                  u64 v_c38 = m229[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex165, mp_msk_ansdelta173, std::array<u64,2>{v_c38, v_c2}, [&](const std::array<u64,2>& m230) {
                    slog::join_probe_old<3,2>(mp_delindex166, mp_deldelta174, std::array<u64,3>{v_c4, v_c25, 0}, [&](const std::array<u64,3>& m231) {
                      u64 v_c39 = m231[2];
                      slog::join_probe_old<2,2>(mp_del_ansindex167, mp_del_ansdelta175, std::array<u64,2>{v_c39, v_c10}, [&](const std::array<u64,2>& m232) {
                        u64 v_c40 = _prim_band(db, v_c25, v_c3);
                        if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c41 = _prim_lt(db, v_c40, v_c34);
                        if (v_c41 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c41) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c37, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask176* _cont = new ReadTask176(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask176(db,b), false);
  // (crule (pre (let __trid2sEh857 const07d7fbed0aba019c07f7eb8a) (let __trel14Rx858 const20347926ddb307a8e2bdb71b) (let __tcol5gMF859 const4e07408562bedb8b60ce05c1)) (scan mp_del_ans __t13lF142 __v0) (body (join-old mp_del (0 2 1) 1 (0 2 1) __t13lF142 k l) (exists mp_msk (1 2 0) 1 k) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7Ifn141) (join mp_msk_ans (0 1) 2 __t7Ifn141 p)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2sEh857 __trel14Rx858 __tcol5gMF859 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __3uQ5856 p m __v0 r)) map.slog:83 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex234;  slog::Index** mp_mskindex235;  slog::Index** $sup5638x82x0x0x0index236;  slog::Index** mp_msk_ansindex237;  slog::Index** mp_mskindex238;  slog::Index** mp_msk_ansindex239;  slog::Index** mp_deldelta240;  slog::Index** mp_mskdelta241;
    u32 sid243;  u32 sid242;  u32 sid244;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord246({0, 2, 1});
      slog::Relation* readrel247 = db->getRelation("mp_del");
      mp_delindex234 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 2, 1});
      slog::Relation* readrel249 = db->getRelation("mp_del");
      mp_deldelta240 = readrel249->getIndex(ord248, true);
      std::vector<u16> ord250({1, 2, 0});
      slog::Relation* readrel251 = db->getRelation("mp_msk");
      mp_mskindex235 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel253 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index236 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex237 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("mp_msk");
      mp_mskindex238 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 0});
      slog::Relation* readrel259 = db->getRelation("mp_msk");
      mp_mskdelta241 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex239 = readrel261->getIndex(ord260, false);
      sid243 = db->getRelation("_enum")->getStructId();
      sid242 = db->getRelation("mbranch")->getStructId();
      sid244 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask245(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c43 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c44 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(mp_delindex234, mp_deldelta240, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m262) {
          u64 v_c25 = m262[1]; u64 v_c4 = m262[2];
          if (!slog::exists_probe<3,1>(mp_mskindex235, std::array<u64,3>{v_c25, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x82x0x0x0index236, std::array<u64,6>{v_c25, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,6>& m263) {
            u64 v_c46 = m263[2]; u64 v_c3 = m263[3]; u64 v_c2 = m263[4]; u64 v_c26 = m263[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex237, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_mskindex238, mp_mskdelta241, std::array<u64,3>{v_c25, v_c3, 0}, [&](const std::array<u64,3>& m264) {
              u64 v_c47 = m264[2];
              slog::join_probe<2,2>(mp_msk_ansindex239, std::array<u64,2>{v_c47, v_c2}, [&](const std::array<u64,2>& m265) {
                ++_fires;
                if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid242 || decode_struct_id(v_c26) == sid243 || decode_struct_id(v_c26) == sid244))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c42, v_c43, v_c44, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del_ans", _fires);
  
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
  // (crule (pre (let __trid6rRL845 const07d7fbed0aba019c07f7eb8a) (let __trel70LR846 const3cd26ab9ce3085a816a74a29) (let __tcol3p7I847 const5feceb66ffc86f38d952786c) (let __trel7Vbs848 const3cd26ab9ce3085a816a74a29) (let __tcol4hat849 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6rRL845 __trel70LR846 __tcol3p7I847 (1 2 3 4 0)) (tycheck k (accept int) __trid6rRL845 __trel7Vbs848 __tcol4hat849 (1 2 3 4 0)) (mkstruct mp_del (1 2 0) __3PF5844 l k)) map.slog:83 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid267;  u32 sid266;  u32 sid268;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_del");
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      sid267 = db->getRelation("_enum")->getStructId();
      sid266 = db->getRelation("mbranch")->getStructId();
      sid268 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c49 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c46 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c26 = _t[5];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid266 || decode_struct_id(v_c4) == sid267 || decode_struct_id(v_c4) == sid268))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c48, v_c49, v_c50, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c51, v_c52, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c25}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
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
  // (crule (pre) (scan mp_del __t24ml152 __t9f1X151 k) (body (join mleaf (0 1 2) 1 __t9f1X151 j v) (neq j k)) (head (emit mp_del_ans (0 1) __t24ml152 __t9f1X151)) map.slog:81 #f)
  class ReadTask271 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex270;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("mp_del_ans");
      head_index[0] = readrel273->getIndex(ord272, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord274({0, 1, 2});
      slog::Relation* readrel275 = db->getRelation("mleaf");
      mleafindex270 = readrel275->getIndex(ord274, false);
  
    }
    ReadTask271(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c25 = _t[2];
        slog::join_probe<3,1>(mleafindex270, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m276) {
          u64 v_c55 = m276[1]; u64 v_c56 = m276[2];
          if (v_c55 == v_c25) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c53, v_c54}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:81", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask271* _cont = new ReadTask271(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask271(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t8NPe120 (bxor p0 p1))) (head (emit-temp temp03QX1021 __t8NPe120)) map.slog:26 #f)
  class ReadTask277 : public slog::Task
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
      head_rel[0] = db->getRelation("temp03QX1021");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
  
    }
    ReadTask277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c17 = _t[6];
        u64 v_c58 = _prim_bxor(db, v_c14, v_c15);
        if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c58});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask277* _cont = new ReadTask277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask277(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t1Rb9367 __v3) (body (join-old mp_hsb_ans (0 1) 1 (0 1) __t1Rb9367 __v1) (join-old mp_hsb (0 1) 1 (0 1) __t1Rb9367 __t3QgY368) (join-old $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk7oqz1064 (bxor p0 p1)) (eq __t3QgY368 chk7oqz1064)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t1Rb9367 __t1Rb9367 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask284 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex278;  slog::Index** mp_hsbindex279;  slog::Index** $sup5638x25x0x0x1index280;  slog::Index** mp_hsb_ansdelta281;  slog::Index** mp_hsbdelta282;  slog::Index** $sup5638x25x0x0x1delta283;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord285({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel286 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel286->getIndex(ord285, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex278 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta281 = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("mp_hsb");
      mp_hsbindex279 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_hsb");
      mp_hsbdelta282 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel296 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index280 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel298 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta283 = readrel298->getIndex(ord297, true);
  
    }
    ReadTask284(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        slog::join_probe_old<2,1>(mp_hsb_ansindex278, mp_hsb_ansdelta281, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m299) {
          u64 v_c9 = m299[1];
          slog::join_probe_old<2,1>(mp_hsbindex279, mp_hsbdelta282, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m300) {
            u64 v_c60 = m300[1];
            slog::join_all_old<7>($sup5638x25x0x0x1index280, $sup5638x25x0x0x1delta283, [&](const std::array<u64,7>& m301) {
              u64 v_c57 = m301[0]; u64 v_c10 = m301[1]; u64 v_c46 = m301[2]; u64 v_c14 = m301[3]; u64 v_c15 = m301[4]; u64 v_c16 = m301[5]; u64 v_c17 = m301[6];
              u64 v_c61 = _prim_bxor(db, v_c14, v_c15);
              if (v_c61 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c60 != v_c61) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c57, v_c10, v_c8, v_c9, v_c46, v_c59, v_c59, v_c14, v_c15, v_c16, v_c17}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask284* _cont = new ReadTask284(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask284(db,b), false);
  // (crule (pre (let __tconst7kPx37 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t2e0k39 __t3oQK38 k) (body (join mleaf (0 1 2) 1 __t3oQK38 j v) (neq j k)) (head (emit mp_has0_ans (0 1) __t2e0k39 __tconst7kPx37)) map.slog:59 #f)
  class ReadTask303 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex302;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel305->getIndex(ord304, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord306({0, 1, 2});
      slog::Relation* readrel307 = db->getRelation("mleaf");
      mleafindex302 = readrel307->getIndex(ord306, false);
  
    }
    ReadTask303(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c25 = _t[2];
        slog::join_probe<3,1>(mleafindex302, std::array<u64,3>{v_c64, 0, 0}, [&](const std::array<u64,3>& m308) {
          u64 v_c55 = m308[1]; u64 v_c56 = m308[2];
          if (v_c55 == v_c25) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c62}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:59", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask303* _cont = new ReadTask303(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask303(db,b), false);
  // (crule (pre (let __trid7r2d789 consta2d3b5b64cd0c50598de1133) (let __trel6RYL790 constdd7bbf31ce5f578b9805e840) (let __tcol5kB8791 const5feceb66ffc86f38d952786c) (let __trel78d8792 constdd7bbf31ce5f578b9805e840) (let __tcol2Zbd793 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid7r2d789 __trel6RYL790 __tcol5kB8791 (1 2 3 4 0)) (tycheck m (accept int) __trid7r2d789 __trel78d8792 __tcol2Zbd793 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __2WNF788 k m)) map.slog:61 #f)
  class ReadTask309 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_consta2d3b5b64cd0c50598de1133;
      u64 v_c66 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
      u64 v_c68 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c46 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c26 = _t[5];
        ++_fires;
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c65, v_c66, v_c67, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c65, v_c68, v_c69, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c25, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
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
  // (crule (pre) (scan mp_msk __t3J75224 k m) (body (exists $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t3J75224 __v0) (join $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 k m __t9Sl6223 l p r) (neq p __v0) (exists mp_del (0 2 1) 2 __t9Sl6223 k) (join mbranch (1 2 3 4 0) 4 p m l r __t5VI4222) (join mp_del (0 2 1) 3 __t9Sl6223 k __t5VI4222)) (head (emit mp_del_ans (0 1) __t9Sl6223 __t5VI4222)) map.slog:82 #f)
  class ReadTask318 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x81x0x0x0index310;  slog::Index** mbranchindex311;  slog::Index** mp_delindex312;  slog::Index** mp_msk_ansindex313;  slog::Index** $sup5638x81x0x0x0index314;  slog::Index** mp_delindex315;  slog::Index** mbranchindex316;  slog::Index** mp_delindex317;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("mp_del_ans");
      head_index[0] = readrel320->getIndex(ord319, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord321({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel322 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index310 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({2, 0, 1, 3, 4});
      slog::Relation* readrel324 = db->getRelation("mbranch");
      mbranchindex311 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({2, 0, 1});
      slog::Relation* readrel326 = db->getRelation("mp_del");
      mp_delindex312 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex313 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel330 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index314 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 2, 1});
      slog::Relation* readrel332 = db->getRelation("mp_del");
      mp_delindex315 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 3, 4, 0});
      slog::Relation* readrel334 = db->getRelation("mbranch");
      mbranchindex316 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({0, 2, 1});
      slog::Relation* readrel336 = db->getRelation("mp_del");
      mp_delindex317 = readrel336->getIndex(ord335, false);
  
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
        u64 v_c70 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x81x0x0x0index310, std::array<u64,6>{v_c25, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex311, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex312, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex313, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m337) {
          u64 v_c10 = m337[1];
          slog::join_probe<6,2>($sup5638x81x0x0x0index314, std::array<u64,6>{v_c25, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,6>& m338) {
            u64 v_c71 = m338[2]; u64 v_c4 = m338[3]; u64 v_c2 = m338[4]; u64 v_c26 = m338[5];
            if (v_c2 == v_c10) return;
            if (!slog::exists_probe<3,2>(mp_delindex315, std::array<u64,3>{v_c71, v_c25, 0})) return;
            slog::join_probe<5,4>(mbranchindex316, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, 0}, [&](const std::array<u64,5>& m339) {
              u64 v_c72 = m339[4];
              slog::join_probe<3,3>(mp_delindex317, std::array<u64,3>{v_c71, v_c25, v_c72}, [&](const std::array<u64,3>& m340) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c72}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mp_union __t2uCs95 __t2SOF94 __t1Mtu99) (body (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 1 __t2uCs95) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 1 __t2uCs95) (join-old mp_union (2 0 1) 1 (2 0 1) __t1Mtu99 __t2wnB100 r) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t2uCs95 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t2uCs95 r) (exists mp_union_ans (0 1) 1 __t2wnB100) (join mbranch (4 0 1 2 3) 2 r __t2SOF94 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t2uCs95) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t2uCs95 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t1Mtu99) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t2uCs95 n q u v __t9ory98) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index341;  slog::Index** $sup5638x98x0x0x1index342;  slog::Index** mp_unionindex343;  slog::Index** $sup5638x98x0x0x0index344;  slog::Index** $sup5638x98x0x0x1index345;  slog::Index** mp_union_ansindex346;  slog::Index** mbranchindex347;  slog::Index** $sup5638x98x0x0x1index348;  slog::Index** mp_mskindex349;  slog::Index** mp_msk_ansindex350;  slog::Index** $sup5638x98x0x0x0index351;  slog::Index** mbranchindex352;  slog::Index** mp_mskindex353;  slog::Index** $sup5638x98x0x0x1index354;  slog::Index** mbranchindex355;  slog::Index** mp_mskindex356;  slog::Index** mp_msk_ansindex357;  slog::Index** mp_union_ansindex358;  slog::Index** mp_uniondelta359;  slog::Index** mbranchdelta360;  slog::Index** mp_mskdelta361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord363({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel364 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index341 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel366 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index342 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({2, 0, 1});
      slog::Relation* readrel368 = db->getRelation("mp_union");
      mp_unionindex343 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({2, 0, 1});
      slog::Relation* readrel370 = db->getRelation("mp_union");
      mp_uniondelta359 = readrel370->getIndex(ord369, true);
      std::vector<u16> ord371({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel372 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index344 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel374 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index345 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({0, 1});
      slog::Relation* readrel376 = db->getRelation("mp_union_ans");
      mp_union_ansindex346 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({4, 0, 1, 2, 3});
      slog::Relation* readrel378 = db->getRelation("mbranch");
      mbranchindex347 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel380 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index348 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({2, 0, 1});
      slog::Relation* readrel382 = db->getRelation("mp_msk");
      mp_mskindex349 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 0});
      slog::Relation* readrel384 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex350 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel386 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index351 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 2, 3, 4, 0});
      slog::Relation* readrel388 = db->getRelation("mbranch");
      mbranchindex352 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("mp_msk");
      mp_mskindex353 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel392 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index354 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 2, 3, 4, 0});
      slog::Relation* readrel394 = db->getRelation("mbranch");
      mbranchindex355 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 3, 4, 0});
      slog::Relation* readrel396 = db->getRelation("mbranch");
      mbranchdelta360 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("mp_msk");
      mp_mskindex356 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("mp_msk");
      mp_mskdelta361 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex357 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("mp_union_ans");
      mp_union_ansindex358 = readrel404->getIndex(ord403, false);
  
    }
    ReadTask362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index341, std::array<u64,9>{v_c74, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index342, std::array<u64,10>{v_c74, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex343, mp_uniondelta359, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m405) {
          u64 v_c77 = m405[1]; u64 v_c26 = m405[2];
          if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index344, std::array<u64,9>{v_c74, v_c26, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index345, std::array<u64,10>{v_c74, v_c26, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex346, std::array<u64,2>{v_c77, 0})) return;
          slog::join_probe<5,2>(mbranchindex347, std::array<u64,5>{v_c26, v_c75, 0, 0, 0}, [&](const std::array<u64,5>& m406) {
            u64 v_c2 = m406[2]; u64 v_c3 = m406[3]; u64 v_c4 = m406[4];
            if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index348, std::array<u64,10>{v_c26, v_c4, v_c3, v_c2, v_c74, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex349, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex350, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<9,5>($sup5638x98x0x0x0index351, std::array<u64,9>{v_c2, v_c4, v_c3, v_c26, v_c74, 0, 0, 0, 0}, [&](const std::array<u64,9>& m407) {
              u64 v_c78 = m407[5]; u64 v_c79 = m407[6]; u64 v_c80 = m407[7]; u64 v_c56 = m407[8];
              u64 v_c81 = _prim_lt(db, v_c78, v_c3);
              if (v_c81 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
              if (!v_c81) return;
              if (!slog::exists_probe<5,5>(mbranchindex352, std::array<u64,5>{v_c79, v_c78, v_c80, v_c56, v_c76})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex353, std::array<u64,3>{v_c79, v_c3, 0})) return;
              slog::join_probe<10,9>($sup5638x98x0x0x1index354, std::array<u64,10>{v_c26, v_c4, v_c3, v_c2, v_c74, v_c78, v_c79, v_c80, v_c56, 0}, [&](const std::array<u64,10>& m409) {
                u64 v_c82 = m409[9];
                slog::join_probe_old<5,5>(mbranchindex355, mbranchdelta360, std::array<u64,5>{v_c79, v_c78, v_c80, v_c56, v_c76}, [&](const std::array<u64,5>& m410) {
                  slog::join_probe_old<3,3>(mp_mskindex356, mp_mskdelta361, std::array<u64,3>{v_c79, v_c3, v_c82}, [&](const std::array<u64,3>& m411) {
                    slog::join_probe<2,2>(mp_msk_ansindex357, std::array<u64,2>{v_c82, v_c2}, [&](const std::array<u64,2>& m412) {
                      slog::join_probe<2,1>(mp_union_ansindex358, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m413) {
                        u64 v_c10 = m413[1];
                        u64 v_c83 = _prim_band(db, v_c79, v_c3);
                        if (v_c83 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c84 = _prim_gt(db, v_c83, v_c73);
                        if (v_c84 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c84) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c74, v_c10, v_c4, v_c3, v_c2});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c4, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask362* _cont = new ReadTask362(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask362(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t6MG8432 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t6MG8432 k m) (exists $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_join (1 2 3 4 0) 1 k) (join-old mleaf (1 2 0) 1 (1 2 0) k v __t9k3L430) (exists mp_put (2 3 0 1) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t9k3L430) (join-old $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 3 (1 3 7 0 2 4 5 6) k m v __t5vsG428 l p r __t51uB429) (neq p __v0) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t51uB429) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t51uB429 k __t5vsG428 v) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) k __t9k3L430 p __t51uB429 __t9vyw431) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask434 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex415;  slog::Index** $sup5638x44x0x0x0index416;  slog::Index** mbranchindex417;  slog::Index** mp_putindex418;  slog::Index** mp_joinindex419;  slog::Index** mleafindex420;  slog::Index** mp_putindex421;  slog::Index** mp_joinindex422;  slog::Index** $sup5638x44x0x0x0index423;  slog::Index** mbranchindex424;  slog::Index** mp_putindex425;  slog::Index** mp_joinindex426;  slog::Index** mp_join_ansindex427;  slog::Index** mp_mskdelta428;  slog::Index** mleafdelta429;  slog::Index** $sup5638x44x0x0x0delta430;  slog::Index** mbranchdelta431;  slog::Index** mp_putdelta432;  slog::Index** mp_joindelta433;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord435({0, 1});
      slog::Relation* readrel436 = db->getRelation("mp_put_ans");
      head_index[0] = readrel436->getIndex(ord435, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord437({0, 1, 2});
      slog::Relation* readrel438 = db->getRelation("mp_msk");
      mp_mskindex415 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1, 2});
      slog::Relation* readrel440 = db->getRelation("mp_msk");
      mp_mskdelta428 = readrel440->getIndex(ord439, true);
      std::vector<u16> ord441({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel442 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index416 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({2, 0, 1, 3, 4});
      slog::Relation* readrel444 = db->getRelation("mbranch");
      mbranchindex417 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({2, 3, 0, 1});
      slog::Relation* readrel446 = db->getRelation("mp_put");
      mp_putindex418 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 3, 4, 0});
      slog::Relation* readrel448 = db->getRelation("mp_join");
      mp_joinindex419 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 2, 0});
      slog::Relation* readrel450 = db->getRelation("mleaf");
      mleafindex420 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 2, 0});
      slog::Relation* readrel452 = db->getRelation("mleaf");
      mleafdelta429 = readrel452->getIndex(ord451, true);
      std::vector<u16> ord453({2, 3, 0, 1});
      slog::Relation* readrel454 = db->getRelation("mp_put");
      mp_putindex421 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 3, 4, 0});
      slog::Relation* readrel456 = db->getRelation("mp_join");
      mp_joinindex422 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel458 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index423 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel460 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0delta430 = readrel460->getIndex(ord459, true);
      std::vector<u16> ord461({1, 2, 3, 4, 0});
      slog::Relation* readrel462 = db->getRelation("mbranch");
      mbranchindex424 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 3, 4, 0});
      slog::Relation* readrel464 = db->getRelation("mbranch");
      mbranchdelta431 = readrel464->getIndex(ord463, true);
      std::vector<u16> ord465({1, 2, 0, 3});
      slog::Relation* readrel466 = db->getRelation("mp_put");
      mp_putindex425 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0, 3});
      slog::Relation* readrel468 = db->getRelation("mp_put");
      mp_putdelta432 = readrel468->getIndex(ord467, true);
      std::vector<u16> ord469({1, 2, 3, 4, 0});
      slog::Relation* readrel470 = db->getRelation("mp_join");
      mp_joinindex426 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 3, 4, 0});
      slog::Relation* readrel472 = db->getRelation("mp_join");
      mp_joindelta433 = readrel472->getIndex(ord471, true);
      std::vector<u16> ord473({0, 1});
      slog::Relation* readrel474 = db->getRelation("mp_join_ans");
      mp_join_ansindex427 = readrel474->getIndex(ord473, false);
  
    }
    ReadTask434(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c85 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex415, mp_mskdelta428, std::array<u64,3>{v_c85, 0, 0}, [&](const std::array<u64,3>& m475) {
          u64 v_c25 = m475[1]; u64 v_c3 = m475[2];
          if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index416, std::array<u64,8>{v_c25, v_c3, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex417, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex418, std::array<u64,4>{v_c25, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex419, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mleafindex420, mleafdelta429, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m476) {
            u64 v_c56 = m476[1]; u64 v_c86 = m476[2];
            if (!slog::exists_probe<4,2>(mp_putindex421, std::array<u64,4>{v_c25, v_c56, 0, 0})) return;
            if (!slog::exists_probe<5,2>(mp_joinindex422, std::array<u64,5>{v_c25, v_c86, 0, 0, 0})) return;
            slog::join_probe_old<8,3>($sup5638x44x0x0x0index423, $sup5638x44x0x0x0delta430, std::array<u64,8>{v_c25, v_c3, v_c56, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m477) {
              u64 v_c87 = m477[3]; u64 v_c4 = m477[4]; u64 v_c2 = m477[5]; u64 v_c26 = m477[6]; u64 v_c88 = m477[7];
              if (v_c2 == v_c10) return;
              slog::join_probe_old<5,5>(mbranchindex424, mbranchdelta431, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, v_c88}, [&](const std::array<u64,5>& m478) {
                slog::join_probe_old<4,4>(mp_putindex425, mp_putdelta432, std::array<u64,4>{v_c88, v_c25, v_c87, v_c56}, [&](const std::array<u64,4>& m479) {
                  slog::join_probe_old<5,4>(mp_joinindex426, mp_joindelta433, std::array<u64,5>{v_c25, v_c86, v_c2, v_c88, 0}, [&](const std::array<u64,5>& m480) {
                    u64 v_c89 = m480[4];
                    slog::join_probe<2,1>(mp_join_ansindex427, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m481) {
                      u64 v_c31 = m481[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t1jAB158 k m) (body (exists $sup5638x82x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (2 1 4 0 3) 1 m) (join mp_msk_ans (0 1) 1 __t1jAB158 p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_bld (1 2 3 4 0) 2 p m) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __t8KQn154 l r) (exists mp_del (0 2 1) 2 __t8KQn154 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_del (1 2 0) 2 l k) (join mbranch (1 2 3 4 0) 4 p m l r __t85IU153) (join mp_del (0 2 1) 3 __t8KQn154 k __t85IU153) (join mp_bld (2 1 4 0 3) 3 m p r __t0Lvo157 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join mp_del_ans (0 1) 2 __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask502 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index482;  slog::Index** mbranchindex483;  slog::Index** mp_delindex484;  slog::Index** mp_bldindex485;  slog::Index** mp_msk_ansindex486;  slog::Index** mbranchindex487;  slog::Index** mp_bldindex488;  slog::Index** $sup5638x82x0x0x0index489;  slog::Index** mp_delindex490;  slog::Index** mp_bldindex491;  slog::Index** mp_delindex492;  slog::Index** mbranchindex493;  slog::Index** mp_delindex494;  slog::Index** mp_bldindex495;  slog::Index** mp_del_ansindex496;  slog::Index** mp_bld_ansindex497;  slog::Index** mp_delindex498;  slog::Index** mp_del_ansindex499;  slog::Index** mp_bld_ansindex500;  slog::Index** mp_deldelta501;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord503({0, 1});
      slog::Relation* readrel504 = db->getRelation("mp_del_ans");
      head_index[0] = readrel504->getIndex(ord503, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord505({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel506 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index482 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({2, 0, 1, 3, 4});
      slog::Relation* readrel508 = db->getRelation("mbranch");
      mbranchindex483 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({2, 0, 1});
      slog::Relation* readrel510 = db->getRelation("mp_del");
      mp_delindex484 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({2, 1, 4, 0, 3});
      slog::Relation* readrel512 = db->getRelation("mp_bld");
      mp_bldindex485 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex486 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 2, 3, 4, 0});
      slog::Relation* readrel516 = db->getRelation("mbranch");
      mbranchindex487 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 2, 3, 4, 0});
      slog::Relation* readrel518 = db->getRelation("mp_bld");
      mp_bldindex488 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel520 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index489 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 2, 1});
      slog::Relation* readrel522 = db->getRelation("mp_del");
      mp_delindex490 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({2, 1, 4, 0, 3});
      slog::Relation* readrel524 = db->getRelation("mp_bld");
      mp_bldindex491 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 0});
      slog::Relation* readrel526 = db->getRelation("mp_del");
      mp_delindex492 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 3, 4, 0});
      slog::Relation* readrel528 = db->getRelation("mbranch");
      mbranchindex493 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({0, 2, 1});
      slog::Relation* readrel530 = db->getRelation("mp_del");
      mp_delindex494 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({2, 1, 4, 0, 3});
      slog::Relation* readrel532 = db->getRelation("mp_bld");
      mp_bldindex495 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 0});
      slog::Relation* readrel534 = db->getRelation("mp_del_ans");
      mp_del_ansindex496 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex497 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("mp_del");
      mp_delindex498 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("mp_del");
      mp_deldelta501 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("mp_del_ans");
      mp_del_ansindex499 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({0, 1});
      slog::Relation* readrel544 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex500 = readrel544->getIndex(ord543, false);
  
    }
    ReadTask502(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index482, std::array<u64,6>{v_c25, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex483, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex484, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex485, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex486, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m545) {
          u64 v_c2 = m545[1];
          if (!slog::exists_probe<5,2>(mbranchindex487, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex488, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x82x0x0x0index489, std::array<u64,6>{v_c25, v_c3, v_c2, 0, 0, 0}, [&](const std::array<u64,6>& m546) {
            u64 v_c37 = m546[3]; u64 v_c4 = m546[4]; u64 v_c26 = m546[5];
            if (!slog::exists_probe<3,2>(mp_delindex490, std::array<u64,3>{v_c37, v_c25, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex491, std::array<u64,5>{v_c3, v_c2, v_c26, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex492, std::array<u64,3>{v_c4, v_c25, 0})) return;
            slog::join_probe<5,4>(mbranchindex493, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, 0}, [&](const std::array<u64,5>& m547) {
              u64 v_c36 = m547[4];
              slog::join_probe<3,3>(mp_delindex494, std::array<u64,3>{v_c37, v_c25, v_c36}, [&](const std::array<u64,3>& m548) {
                slog::join_probe<5,3>(mp_bldindex495, std::array<u64,5>{v_c3, v_c2, v_c26, 0, 0}, [&](const std::array<u64,5>& m549) {
                  u64 v_c35 = m549[3]; u64 v_c10 = m549[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex496, std::array<u64,2>{v_c10, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex497, std::array<u64,2>{v_c35, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex498, mp_deldelta501, std::array<u64,3>{v_c4, v_c25, 0}, [&](const std::array<u64,3>& m550) {
                    u64 v_c39 = m550[2];
                    slog::join_probe<2,2>(mp_del_ansindex499, std::array<u64,2>{v_c39, v_c10}, [&](const std::array<u64,2>& m551) {
                      slog::join_probe<2,1>(mp_bld_ansindex500, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m552) {
                        u64 v_c31 = m552[1];
                        u64 v_c40 = _prim_band(db, v_c25, v_c3);
                        if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c90 = _prim_lt(db, v_c40, v_c34);
                        if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c90) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c37, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask502* _cont = new ReadTask502(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask502(db,b), false);
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t5APc170 __t4G6v169 k) (body (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join $sup5638x60x0x0x0 (0 1 2 3 4 5) 2 __t5APc170 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t4G6v169) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t8KSH173) (exists mp_has0_ans (0 1) 1 __t8KSH173) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4QPc174) (join mp_msk_ans (0 1) 2 __t4QPc174 p) (join mp_has0_ans (0 1) 1 __t8KSH173 a) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask567 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index554;  slog::Index** mp_mskindex555;  slog::Index** $sup5638x60x0x0x0index556;  slog::Index** mbranchindex557;  slog::Index** mp_mskindex558;  slog::Index** mp_msk_ansindex559;  slog::Index** mp_has0index560;  slog::Index** mp_has0_ansindex561;  slog::Index** mp_mskindex562;  slog::Index** mp_msk_ansindex563;  slog::Index** mp_has0_ansindex564;  slog::Index** mp_has0delta565;  slog::Index** mp_mskdelta566;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord568({0, 1});
      slog::Relation* readrel569 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel569->getIndex(ord568, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord570({2, 0, 1});
      slog::Relation* readrel571 = db->getRelation("mp_has0");
      mp_has0index554 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("mp_msk");
      mp_mskindex555 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel575 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index556 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 3, 4, 0});
      slog::Relation* readrel577 = db->getRelation("mbranch");
      mbranchindex557 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 2, 0});
      slog::Relation* readrel579 = db->getRelation("mp_msk");
      mp_mskindex558 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 0});
      slog::Relation* readrel581 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex559 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("mp_has0");
      mp_has0index560 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("mp_has0");
      mp_has0delta565 = readrel585->getIndex(ord584, true);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex561 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 2, 0});
      slog::Relation* readrel589 = db->getRelation("mp_msk");
      mp_mskindex562 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 2, 0});
      slog::Relation* readrel591 = db->getRelation("mp_msk");
      mp_mskdelta566 = readrel591->getIndex(ord590, true);
      std::vector<u16> ord592({0, 1});
      slog::Relation* readrel593 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex563 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({0, 1});
      slog::Relation* readrel595 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex564 = readrel595->getIndex(ord594, false);
  
    }
    ReadTask567(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_has0index554, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex555, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x60x0x0x0index556, std::array<u64,6>{v_c92, v_c25, 0, 0, 0, 0}, [&](const std::array<u64,6>& m596) {
          u64 v_c4 = m596[2]; u64 v_c3 = m596[3]; u64 v_c2 = m596[4]; u64 v_c26 = m596[5];
          slog::join_probe<5,5>(mbranchindex557, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, v_c93}, [&](const std::array<u64,5>& m597) {
            if (!slog::exists_probe<3,2>(mp_mskindex558, std::array<u64,3>{v_c25, v_c3, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex559, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index560, mp_has0delta565, std::array<u64,3>{v_c4, v_c25, 0}, [&](const std::array<u64,3>& m598) {
              u64 v_c94 = m598[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex561, std::array<u64,2>{v_c94, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex562, mp_mskdelta566, std::array<u64,3>{v_c25, v_c3, 0}, [&](const std::array<u64,3>& m599) {
                u64 v_c95 = m599[2];
                slog::join_probe<2,2>(mp_msk_ansindex563, std::array<u64,2>{v_c95, v_c2}, [&](const std::array<u64,2>& m600) {
                  slog::join_probe<2,1>(mp_has0_ansindex564, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m601) {
                    u64 v_c96 = m601[1];
                    u64 v_c97 = _prim_band(db, v_c25, v_c3);
                    if (v_c97 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c98 = _prim_lt(db, v_c97, v_c91);
                    if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c98) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c92, v_c96}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan mleaf __t4k6G319 k v) (body (exists mp_union (2 0 1) 1 __t4k6G319) (join-old mp_put_soft (2 3 0 1) 2 (2 3 0 1) k v __t6FhG321 s) (exists mp_put_soft_ans (0 1) 1 __t6FhG321) (join-old mp_union (1 2 0) 2 (1 2 0) s __t4k6G319 __t4hCg320) (join mp_put_soft_ans (0 1) 1 __t6FhG321 r)) (head (emit mp_union_ans (0 1) __t4hCg320 r)) map.slog:93 #f)
  class ReadTask610 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex603;  slog::Index** mp_put_softindex604;  slog::Index** mp_put_soft_ansindex605;  slog::Index** mp_unionindex606;  slog::Index** mp_put_soft_ansindex607;  slog::Index** mp_put_softdelta608;  slog::Index** mp_uniondelta609;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("mp_union_ans");
      head_index[0] = readrel612->getIndex(ord611, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord613({2, 0, 1});
      slog::Relation* readrel614 = db->getRelation("mp_union");
      mp_unionindex603 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({2, 3, 0, 1});
      slog::Relation* readrel616 = db->getRelation("mp_put_soft");
      mp_put_softindex604 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({2, 3, 0, 1});
      slog::Relation* readrel618 = db->getRelation("mp_put_soft");
      mp_put_softdelta608 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex605 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("mp_union");
      mp_unionindex606 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 2, 0});
      slog::Relation* readrel624 = db->getRelation("mp_union");
      mp_uniondelta609 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({0, 1});
      slog::Relation* readrel626 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex607 = readrel626->getIndex(ord625, false);
  
    }
    ReadTask610(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c99 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c56 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex603, std::array<u64,3>{v_c99, 0, 0})) return;
        slog::join_probe_old<4,2>(mp_put_softindex604, mp_put_softdelta608, std::array<u64,4>{v_c25, v_c56, 0, 0}, [&](const std::array<u64,4>& m627) {
          u64 v_c100 = m627[2]; u64 v_c101 = m627[3];
          if (!slog::exists_probe<2,1>(mp_put_soft_ansindex605, std::array<u64,2>{v_c100, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex606, mp_uniondelta609, std::array<u64,3>{v_c101, v_c99, 0}, [&](const std::array<u64,3>& m628) {
            u64 v_c102 = m628[2];
            slog::join_probe<2,1>(mp_put_soft_ansindex607, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m629) {
              u64 v_c26 = m629[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c102, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask610* _cont = new ReadTask610(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask610(db,b), false);
  // (crule (pre) (scan mbranch __t8UiN251 q m u v) (body (exists mbranch (2 0 1 3 4) 1 m) (join mp_union (2 0 1) 1 __t8UiN251 __t1JFT249 __t3xpB250) (join mbranch (2 0 1 3 4) 2 m __t3xpB250 p l r) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __9uYp581 p __t3xpB250 q __t8UiN251)) map.slog:114 #f)
  class ReadTask633 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex630;  slog::Index** mp_unionindex631;  slog::Index** mbranchindex632;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord634({2, 0, 1, 3, 4});
      slog::Relation* readrel635 = db->getRelation("mbranch");
      mbranchindex630 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({2, 0, 1});
      slog::Relation* readrel637 = db->getRelation("mp_union");
      mp_unionindex631 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({2, 0, 1, 3, 4});
      slog::Relation* readrel639 = db->getRelation("mbranch");
      mbranchindex632 = readrel639->getIndex(ord638, false);
  
    }
    ReadTask633(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c80 = _t[3];
        u64 v_c56 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex630, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(mp_unionindex631, std::array<u64,3>{v_c103, 0, 0}, [&](const std::array<u64,3>& m640) {
          u64 v_c104 = m640[1]; u64 v_c105 = m640[2];
          slog::join_probe<5,2>(mbranchindex632, std::array<u64,5>{v_c3, v_c105, 0, 0, 0}, [&](const std::array<u64,5>& m641) {
            u64 v_c2 = m641[2]; u64 v_c4 = m641[3]; u64 v_c26 = m641[4];
            if (v_c2 == v_c79) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c2, v_c105, v_c79, v_c103}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask633* _cont = new ReadTask633(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask633(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mbranch __t6yxH356 p m l r) (body (exists $sup5638x107x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists mp_union (1 2 0) 1 __t6yxH356) (exists mp_msk (1 2 0) 1 p) (join $sup5638x107x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t05l7352 n q u v) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t05l7352 __t6yxH356) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (1 2 0) 2 __t6yxH356 v) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t05l7352 l m p r __t4mLe355) (exists mp_msk (1 2 0) 3 p n __t4mLe355) (exists mp_msk_ans (0 1) 2 __t4mLe355 q) (join mbranch (1 2 3 4 0) 4 q n u v __t3rQ8350) (join mp_union (0 1 2) 3 __t05l7352 __t6yxH356 __t3rQ8350) (join mp_msk (1 2 0) 3 p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask661 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index642;  slog::Index** mp_unionindex643;  slog::Index** mp_mskindex644;  slog::Index** $sup5638x107x0x0x0index645;  slog::Index** mbranchindex646;  slog::Index** mp_unionindex647;  slog::Index** mp_mskindex648;  slog::Index** mp_msk_ansindex649;  slog::Index** mp_unionindex650;  slog::Index** $sup5638x107x0x0x1index651;  slog::Index** mp_mskindex652;  slog::Index** mp_msk_ansindex653;  slog::Index** mbranchindex654;  slog::Index** mp_unionindex655;  slog::Index** mp_mskindex656;  slog::Index** mp_msk_ansindex657;  slog::Index** mp_unionindex658;  slog::Index** mp_union_ansindex659;  slog::Index** mp_uniondelta660;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord662({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel663 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index642 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("mp_union");
      mp_unionindex643 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("mp_msk");
      mp_mskindex644 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel669 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index645 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 2, 3, 4, 0});
      slog::Relation* readrel671 = db->getRelation("mbranch");
      mbranchindex646 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1, 2});
      slog::Relation* readrel673 = db->getRelation("mp_union");
      mp_unionindex647 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 0});
      slog::Relation* readrel675 = db->getRelation("mp_msk");
      mp_mskindex648 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 0});
      slog::Relation* readrel677 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex649 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("mp_union");
      mp_unionindex650 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel681 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index651 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("mp_msk");
      mp_mskindex652 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex653 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 3, 4, 0});
      slog::Relation* readrel687 = db->getRelation("mbranch");
      mbranchindex654 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1, 2});
      slog::Relation* readrel689 = db->getRelation("mp_union");
      mp_unionindex655 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 0});
      slog::Relation* readrel691 = db->getRelation("mp_msk");
      mp_mskindex656 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({0, 1});
      slog::Relation* readrel693 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex657 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("mp_union");
      mp_unionindex658 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 0});
      slog::Relation* readrel697 = db->getRelation("mp_union");
      mp_uniondelta660 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("mp_union_ans");
      mp_union_ansindex659 = readrel699->getIndex(ord698, false);
  
    }
    ReadTask661(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c107 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c26 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x107x0x0x1index642, std::array<u64,10>{v_c4, v_c3, v_c2, v_c26, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex643, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex644, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x107x0x0x0index645, std::array<u64,9>{v_c4, v_c3, v_c2, v_c26, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m700) {
          u64 v_c108 = m700[4]; u64 v_c78 = m700[5]; u64 v_c79 = m700[6]; u64 v_c80 = m700[7]; u64 v_c56 = m700[8];
          u64 v_c109 = _prim_lt(db, v_c3, v_c78);
          if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c109) return;
          if (!slog::exists_probe<5,4>(mbranchindex646, std::array<u64,5>{v_c79, v_c78, v_c80, v_c56, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex647, std::array<u64,3>{v_c108, v_c107, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex648, std::array<u64,3>{v_c2, v_c78, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex649, std::array<u64,2>{v_c79, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex650, std::array<u64,3>{v_c107, v_c56, 0})) return;
          slog::join_probe<10,9>($sup5638x107x0x0x1index651, std::array<u64,10>{v_c56, v_c78, v_c79, v_c80, v_c108, v_c4, v_c3, v_c2, v_c26, 0}, [&](const std::array<u64,10>& m702) {
            u64 v_c110 = m702[9];
            if (!slog::exists_probe<3,3>(mp_mskindex652, std::array<u64,3>{v_c2, v_c78, v_c110})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex653, std::array<u64,2>{v_c110, v_c79})) return;
            slog::join_probe<5,4>(mbranchindex654, std::array<u64,5>{v_c79, v_c78, v_c80, v_c56, 0}, [&](const std::array<u64,5>& m703) {
              u64 v_c111 = m703[4];
              slog::join_probe<3,3>(mp_unionindex655, std::array<u64,3>{v_c108, v_c107, v_c111}, [&](const std::array<u64,3>& m704) {
                slog::join_probe<3,3>(mp_mskindex656, std::array<u64,3>{v_c2, v_c78, v_c110}, [&](const std::array<u64,3>& m705) {
                  slog::join_probe<2,2>(mp_msk_ansindex657, std::array<u64,2>{v_c110, v_c79}, [&](const std::array<u64,2>& m706) {
                    slog::join_probe_old<3,2>(mp_unionindex658, mp_uniondelta660, std::array<u64,3>{v_c107, v_c56, 0}, [&](const std::array<u64,3>& m707) {
                      u64 v_c112 = m707[2];
                      slog::join_probe<2,1>(mp_union_ansindex659, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m708) {
                        u64 v_c10 = m708[1];
                        u64 v_c113 = _prim_band(db, v_c2, v_c78);
                        if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c114 = _prim_gt(db, v_c113, v_c106);
                        if (v_c114 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c114) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c108, v_c10, v_c78, v_c79, v_c80});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c79, v_c78, v_c80, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask661* _cont = new ReadTask661(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask661(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t2bXu55 __v1) (body (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t2bXu55 __v1) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t2bXu55) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v3) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2bXu55 __v1 __v3) (join-old mp_hsb_ans (0 1) 1 (0 1) __t2bXu55 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t2bXu55 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2bXu55 __v0 __v3 __v1 __t6Puw51 dup3kne1056 dup92Cz1057 p0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join mp_msk_ans (0 1) 1 __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask729 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex710;  slog::Index** $sup5638x25x0x0x2index711;  slog::Index** $sup5638x25x0x0x1index712;  slog::Index** mp_mskindex713;  slog::Index** mp_hsb_ansindex714;  slog::Index** $sup5638x25x0x0x2index715;  slog::Index** mp_hsb_ansindex716;  slog::Index** $sup5638x25x0x0x1index717;  slog::Index** $sup5638x25x0x0x2index718;  slog::Index** $sup5638x25x0x0x1index719;  slog::Index** $sup5638x25x0x0x0index720;  slog::Index** mp_joinindex721;  slog::Index** mp_mskindex722;  slog::Index** mp_msk_ansindex723;  slog::Index** mp_hsbindex724;  slog::Index** mp_hsb_ansdelta725;  slog::Index** mp_joindelta726;  slog::Index** mp_mskdelta727;  slog::Index** mp_hsbdelta728;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord730({0, 1});
      slog::Relation* readrel731 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex710 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel733 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index711 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel735 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index712 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({2, 0, 1});
      slog::Relation* readrel737 = db->getRelation("mp_msk");
      mp_mskindex713 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex714 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel741 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index715 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({0, 1});
      slog::Relation* readrel743 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex716 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta725 = readrel745->getIndex(ord744, true);
      std::vector<u16> ord746({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel747 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index717 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel749 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index718 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel751 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index719 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0, 2, 3, 4});
      slog::Relation* readrel753 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index720 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 3, 4, 0});
      slog::Relation* readrel755 = db->getRelation("mp_join");
      mp_joinindex721 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 2, 3, 4, 0});
      slog::Relation* readrel757 = db->getRelation("mp_join");
      mp_joindelta726 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("mp_msk");
      mp_mskindex722 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 2, 0});
      slog::Relation* readrel761 = db->getRelation("mp_msk");
      mp_mskdelta727 = readrel761->getIndex(ord760, true);
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex723 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1});
      slog::Relation* readrel765 = db->getRelation("mp_hsb");
      mp_hsbindex724 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1});
      slog::Relation* readrel767 = db->getRelation("mp_hsb");
      mp_hsbdelta728 = readrel767->getIndex(ord766, true);
  
    }
    ReadTask729(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex710, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index711, std::array<u64,11>{v_c116, v_c9, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index712, std::array<u64,7>{v_c116, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex713, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex714, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m768) {
          u64 v_c8 = m768[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index715, std::array<u64,11>{v_c116, v_c9, v_c8, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex716, mp_hsb_ansdelta725, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m769) {
            u64 v_c10 = m769[1];
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index717, std::array<u64,7>{v_c116, v_c10, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index718, std::array<u64,11>{v_c116, v_c10, v_c8, v_c9, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m770) {
              u64 v_c117 = m770[4]; u64 v_c118 = m770[5]; u64 v_c119 = m770[6]; u64 v_c14 = m770[7]; u64 v_c15 = m770[8]; u64 v_c16 = m770[9]; u64 v_c17 = m770[10];
              if (v_c116 != v_c119) return;
              if (v_c116 != v_c118) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index719, std::array<u64,7>{v_c117, v_c14, v_c15, v_c16, v_c17, v_c116, v_c10}, [&](const std::array<u64,7>& m771) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index720, std::array<u64,5>{v_c14, v_c117, v_c15, v_c16, v_c17}, [&](const std::array<u64,5>& m772) {
                  slog::join_probe_old<5,5>(mp_joinindex721, mp_joindelta726, std::array<u64,5>{v_c14, v_c16, v_c15, v_c17, v_c117}, [&](const std::array<u64,5>& m773) {
                    slog::join_probe_old<3,2>(mp_mskindex722, mp_mskdelta727, std::array<u64,3>{v_c14, v_c9, 0}, [&](const std::array<u64,3>& m774) {
                      u64 v_c120 = m774[2];
                      slog::join_probe<2,1>(mp_msk_ansindex723, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m775) {
                        u64 v_c19 = m775[1];
                        u64 v_c121 = _prim_bxor(db, v_c14, v_c15);
                        if (v_c121 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex724, mp_hsbdelta728, std::array<u64,2>{v_c116, v_c121}, [&](const std::array<u64,2>& m776) {
                          u64 v_c122 = _prim_band(db, v_c14, v_c10);
                          if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c123 = _prim_lt(db, v_c122, v_c115);
                          if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c123) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c117, v_c19, v_c8, v_c16, v_c17});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c19, v_c8, v_c16, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask729* _cont = new ReadTask729(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask729(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t8rat400 __v2) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t8rat400 p0 __v1) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x29x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join-old mp_hsb_ans (1 0) 1 (1 0) __v1 __t1lh0397) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t1lh0397) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t1lh0397) (exists mp_hsb_ans (0 1) 1 __t1lh0397) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v3) (join $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t1lh0397 __v1 __v3 p0 __t4lFL393 dup0XDZ1075 dup8FhK1076 __v0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v0) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask799 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex778;  slog::Index** $sup5638x29x0x0x2index779;  slog::Index** $sup5638x29x0x0x1index780;  slog::Index** $sup5638x29x0x0x0index781;  slog::Index** mp_joinindex782;  slog::Index** mp_hsb_ansindex783;  slog::Index** $sup5638x29x0x0x2index784;  slog::Index** $sup5638x29x0x0x1index785;  slog::Index** mp_hsb_ansindex786;  slog::Index** mp_hsb_ansindex787;  slog::Index** $sup5638x29x0x0x2index788;  slog::Index** $sup5638x29x0x0x1index789;  slog::Index** $sup5638x29x0x0x0index790;  slog::Index** mp_joinindex791;  slog::Index** mp_hsb_ansindex792;  slog::Index** mp_hsbindex793;  slog::Index** mp_mskdelta794;  slog::Index** mp_hsb_ansdelta795;  slog::Index** mp_joindelta796;  slog::Index** mp_hsb_ansdelta797;  slog::Index** mp_hsbdelta798;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord800({0, 1, 2});
      slog::Relation* readrel801 = db->getRelation("mp_msk");
      mp_mskindex778 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({0, 1, 2});
      slog::Relation* readrel803 = db->getRelation("mp_msk");
      mp_mskdelta794 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel805 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index779 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel807 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index780 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 0, 2, 3, 4});
      slog::Relation* readrel809 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index781 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 3, 4, 0});
      slog::Relation* readrel811 = db->getRelation("mp_join");
      mp_joinindex782 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({1, 0});
      slog::Relation* readrel813 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex783 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({1, 0});
      slog::Relation* readrel815 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta795 = readrel815->getIndex(ord814, true);
      std::vector<u16> ord816({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel817 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index784 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel819 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index785 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex786 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex787 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel825 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index788 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel827 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index789 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 0, 2, 3, 4});
      slog::Relation* readrel829 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index790 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 2, 3, 4, 0});
      slog::Relation* readrel831 = db->getRelation("mp_join");
      mp_joinindex791 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 3, 4, 0});
      slog::Relation* readrel833 = db->getRelation("mp_join");
      mp_joindelta796 = readrel833->getIndex(ord832, true);
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex792 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta797 = readrel837->getIndex(ord836, true);
      std::vector<u16> ord838({0, 1});
      slog::Relation* readrel839 = db->getRelation("mp_hsb");
      mp_hsbindex793 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({0, 1});
      slog::Relation* readrel841 = db->getRelation("mp_hsb");
      mp_hsbdelta798 = readrel841->getIndex(ord840, true);
  
    }
    ReadTask799(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex778, mp_mskdelta794, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m842) {
          u64 v_c14 = m842[1]; u64 v_c9 = m842[2];
          if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index779, std::array<u64,11>{v_c9, v_c14, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index780, std::array<u64,7>{v_c14, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup5638x29x0x0x0index781, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex782, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex783, mp_hsb_ansdelta795, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m843) {
            u64 v_c7 = m843[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index784, std::array<u64,11>{v_c9, v_c14, v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index785, std::array<u64,7>{v_c14, v_c7, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex786, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex787, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m844) {
              u64 v_c8 = m844[1];
              slog::join_probe<11,4>($sup5638x29x0x0x2index788, std::array<u64,11>{v_c7, v_c9, v_c8, v_c14, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m845) {
                u64 v_c11 = m845[4]; u64 v_c12 = m845[5]; u64 v_c13 = m845[6]; u64 v_c10 = m845[7]; u64 v_c15 = m845[8]; u64 v_c16 = m845[9]; u64 v_c17 = m845[10];
                if (v_c7 != v_c13) return;
                if (v_c7 != v_c12) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index789, std::array<u64,7>{v_c11, v_c14, v_c15, v_c16, v_c17, v_c7, v_c10}, [&](const std::array<u64,7>& m846) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index790, std::array<u64,5>{v_c14, v_c11, v_c15, v_c16, v_c17}, [&](const std::array<u64,5>& m847) {
                    slog::join_probe_old<5,5>(mp_joinindex791, mp_joindelta796, std::array<u64,5>{v_c14, v_c16, v_c15, v_c17, v_c11}, [&](const std::array<u64,5>& m848) {
                      slog::join_probe_old<2,2>(mp_hsb_ansindex792, mp_hsb_ansdelta797, std::array<u64,2>{v_c7, v_c10}, [&](const std::array<u64,2>& m849) {
                        u64 v_c20 = _prim_bxor(db, v_c14, v_c15);
                        if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex793, mp_hsbdelta798, std::array<u64,2>{v_c7, v_c20}, [&](const std::array<u64,2>& m850) {
                          u64 v_c21 = _prim_band(db, v_c14, v_c10);
                          if (v_c21 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c124 = _prim_gt(db, v_c21, v_c6);
                          if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c124) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c11, v_c19, v_c8, v_c16, v_c17});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c19, v_c8, v_c17, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask799* _cont = new ReadTask799(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask799(db,b), false);
  // (crule (pre (let __trid1iVl742 const6c3d8aa344844f80a370de02) (let __trel34DV743 consta24220c5193376967f1fa95e) (let __tcol6j9Q744 const5feceb66ffc86f38d952786c) (let __trel3nIG745 consta24220c5193376967f1fa95e) (let __tcol58Dp746 const6b86b273ff34fce19d6b804e) (let __trel5h54747 consta24220c5193376967f1fa95e) (let __tcol64NF748 constd4735e3a265e16eee03f5971) (let __trel8fwj749 consta24220c5193376967f1fa95e) (let __tcol2qUd750 const4e07408562bedb8b60ce05c1)) (scan $sup5638x101x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid1iVl742 __trel34DV743 __tcol6j9Q744 (1 2 3 4 0)) (tycheck s (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid1iVl742 __trel3nIG745 __tcol58Dp746 (1 2 3 4 0)) (tycheck q (accept int) __trid1iVl742 __trel5h54747 __tcol64NF748 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid1iVl742 __trel8fwj749 __tcol2qUd750 (1 2 3 4 0)) (mkstruct mp_join (1 2 3 4 0) __2fkT741 p s q t)) map.slog:102 #f)
  class ReadTask855 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid853;  u32 sid852;  u32 sid854;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("mp_join");
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
      sid853 = db->getRelation("_enum")->getStructId();
      sid852 = db->getRelation("mbranch")->getStructId();
      sid854 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask855(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_const6c3d8aa344844f80a370de02;
      u64 v_c126 = v_consta24220c5193376967f1fa95e;
      u64 v_c127 = v_const5feceb66ffc86f38d952786c;
      u64 v_c128 = v_consta24220c5193376967f1fa95e;
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c130 = v_consta24220c5193376967f1fa95e;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_consta24220c5193376967f1fa95e;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c46 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c79 = _t[5];
        u64 v_c26 = _t[6];
        u64 v_c101 = _t[7];
        u64 v_c134 = _t[8];
        u64 v_c80 = _t[9];
        u64 v_c56 = _t[10];
        ++_fires;
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c125, v_c126, v_c127, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c101) && (decode_struct_id(v_c101) == sid852 || decode_struct_id(v_c101) == sid853 || decode_struct_id(v_c101) == sid854))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c125, v_c128, v_c129, v_c101}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c79)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c125, v_c130, v_c131, v_c79}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c134) && (decode_struct_id(v_c134) == sid852 || decode_struct_id(v_c134) == sid853 || decode_struct_id(v_c134) == sid854))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c125, v_c132, v_c133, v_c134}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c2, v_c101, v_c79, v_c134}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask855* _cont = new ReadTask855(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask855(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t68rk111 __t032L110 k) (body (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join $sup5638x62x0x0x0 (0 1 2 3 4 5) 2 __t68rk111 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t032L110) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t6Hok114) (exists mp_has0_ans (0 1) 1 __t6Hok114) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9QiO115) (join mp_msk_ans (0 1) 2 __t9QiO115 p) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask869 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index856;  slog::Index** mp_mskindex857;  slog::Index** $sup5638x62x0x0x0index858;  slog::Index** mbranchindex859;  slog::Index** mp_mskindex860;  slog::Index** mp_msk_ansindex861;  slog::Index** mp_has0index862;  slog::Index** mp_has0_ansindex863;  slog::Index** mp_mskindex864;  slog::Index** mp_msk_ansindex865;  slog::Index** mp_has0_ansindex866;  slog::Index** mp_has0delta867;  slog::Index** mp_mskdelta868;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord870({0, 1});
      slog::Relation* readrel871 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel871->getIndex(ord870, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord872({2, 0, 1});
      slog::Relation* readrel873 = db->getRelation("mp_has0");
      mp_has0index856 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({1, 2, 0});
      slog::Relation* readrel875 = db->getRelation("mp_msk");
      mp_mskindex857 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel877 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index858 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({1, 2, 3, 4, 0});
      slog::Relation* readrel879 = db->getRelation("mbranch");
      mbranchindex859 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({1, 2, 0});
      slog::Relation* readrel881 = db->getRelation("mp_msk");
      mp_mskindex860 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 0});
      slog::Relation* readrel883 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex861 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("mp_has0");
      mp_has0index862 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 2, 0});
      slog::Relation* readrel887 = db->getRelation("mp_has0");
      mp_has0delta867 = readrel887->getIndex(ord886, true);
      std::vector<u16> ord888({0, 1});
      slog::Relation* readrel889 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex863 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 0});
      slog::Relation* readrel891 = db->getRelation("mp_msk");
      mp_mskindex864 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 0});
      slog::Relation* readrel893 = db->getRelation("mp_msk");
      mp_mskdelta868 = readrel893->getIndex(ord892, true);
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex865 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({0, 1});
      slog::Relation* readrel897 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex866 = readrel897->getIndex(ord896, false);
  
    }
    ReadTask869(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c136 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_has0index856, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex857, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x62x0x0x0index858, std::array<u64,6>{v_c136, v_c25, 0, 0, 0, 0}, [&](const std::array<u64,6>& m898) {
          u64 v_c4 = m898[2]; u64 v_c3 = m898[3]; u64 v_c2 = m898[4]; u64 v_c26 = m898[5];
          slog::join_probe<5,5>(mbranchindex859, std::array<u64,5>{v_c2, v_c3, v_c4, v_c26, v_c137}, [&](const std::array<u64,5>& m899) {
            if (!slog::exists_probe<3,2>(mp_mskindex860, std::array<u64,3>{v_c25, v_c3, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex861, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index862, mp_has0delta867, std::array<u64,3>{v_c26, v_c25, 0}, [&](const std::array<u64,3>& m900) {
              u64 v_c138 = m900[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex863, std::array<u64,2>{v_c138, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex864, mp_mskdelta868, std::array<u64,3>{v_c25, v_c3, 0}, [&](const std::array<u64,3>& m901) {
                u64 v_c139 = m901[2];
                slog::join_probe<2,2>(mp_msk_ansindex865, std::array<u64,2>{v_c139, v_c2}, [&](const std::array<u64,2>& m902) {
                  slog::join_probe<2,1>(mp_has0_ansindex866, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m903) {
                    u64 v_c96 = m903[1];
                    u64 v_c140 = _prim_band(db, v_c25, v_c3);
                    if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c141 = _prim_gt(db, v_c140, v_c135);
                    if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c141) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c136, v_c96}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0", _fires);
  
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
  // (crule (pre (let __tconst1tdf238 const5feceb66ffc86f38d952786c)) (scan mbranch __t6hXy236 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t6hXy236 __t8FcE235 __t7Vjh237) (join mbranch (0 1 2 3 4) 1 __t8FcE235 q n u v) (cmp lt m n) (let __t7cw8239 (band p n)) (cmp gt __t7cw8239 __tconst1tdf238)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t7Vjh237 v l m n p q r u)) map.slog:108 #f)
  class ReadTask908 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex905;  slog::Index** mbranchindex906;  slog::Index** mp_uniondelta907;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord909({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel910 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel910->getIndex(ord909, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord911({1, 2, 0});
      slog::Relation* readrel912 = db->getRelation("mp_union");
      mp_unionindex905 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({1, 2, 0});
      slog::Relation* readrel914 = db->getRelation("mp_union");
      mp_uniondelta907 = readrel914->getIndex(ord913, true);
      std::vector<u16> ord915({0, 1, 2, 3, 4});
      slog::Relation* readrel916 = db->getRelation("mbranch");
      mbranchindex906 = readrel916->getIndex(ord915, false);
  
    }
    ReadTask908(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c143 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c26 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex905, mp_uniondelta907, std::array<u64,3>{v_c143, 0, 0}, [&](const std::array<u64,3>& m917) {
          u64 v_c144 = m917[1]; u64 v_c145 = m917[2];
          slog::join_probe<5,1>(mbranchindex906, std::array<u64,5>{v_c144, 0, 0, 0, 0}, [&](const std::array<u64,5>& m918) {
            u64 v_c79 = m918[1]; u64 v_c78 = m918[2]; u64 v_c80 = m918[3]; u64 v_c56 = m918[4];
            u64 v_c146 = _prim_lt(db, v_c3, v_c78);
            if (v_c146 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c146) return;
            u64 v_c147 = _prim_band(db, v_c2, v_c78);
            if (v_c147 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c148 = _prim_gt(db, v_c147, v_c142);
            if (v_c148 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c148) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c145, v_c56, v_c4, v_c3, v_c78, v_c2, v_c79, v_c26, v_c80}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask908* _cont = new ReadTask908(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask908(db,b), false);
  // (crule (pre (let __tconst2TBF232 const5feceb66ffc86f38d952786c)) (scan mp_union __t7SeD231 __t0LiB230 __t2Hro229) (body (join mbranch (0 1 2 3 4) 1 __t2Hro229 q n u v) (join mbranch (0 1 2 3 4) 1 __t0LiB230 p m l r) (cmp lt n m) (let __t1wK1233 (band q m)) (cmp gt __t1wK1233 __tconst2TBF232)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t7SeD231 r l m n p q u v)) map.slog:99 #f)
  class ReadTask923 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex921;  slog::Index** mbranchindex922;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord924({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel925 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel925->getIndex(ord924, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord926({0, 1, 2, 3, 4});
      slog::Relation* readrel927 = db->getRelation("mbranch");
      mbranchindex921 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({0, 1, 2, 3, 4});
      slog::Relation* readrel929 = db->getRelation("mbranch");
      mbranchindex922 = readrel929->getIndex(ord928, false);
  
    }
    ReadTask923(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c150 = _t[0];
        u64 v_c151 = _t[1];
        u64 v_c152 = _t[2];
        slog::join_probe<5,1>(mbranchindex921, std::array<u64,5>{v_c152, 0, 0, 0, 0}, [&](const std::array<u64,5>& m930) {
          u64 v_c79 = m930[1]; u64 v_c78 = m930[2]; u64 v_c80 = m930[3]; u64 v_c56 = m930[4];
          slog::join_probe<5,1>(mbranchindex922, std::array<u64,5>{v_c151, 0, 0, 0, 0}, [&](const std::array<u64,5>& m931) {
            u64 v_c2 = m931[1]; u64 v_c3 = m931[2]; u64 v_c4 = m931[3]; u64 v_c26 = m931[4];
            u64 v_c153 = _prim_lt(db, v_c78, v_c3);
            if (v_c153 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c153) return;
            u64 v_c154 = _prim_band(db, v_c79, v_c3);
            if (v_c154 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c155 = _prim_gt(db, v_c154, v_c149);
            if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c155) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c150, v_c26, v_c4, v_c3, v_c78, v_c2, v_c79, v_c80, v_c56}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
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
}

