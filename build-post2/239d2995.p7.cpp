
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const1ef5dd96b7ac876a994a9ca1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_consta0e8b3efb8cecb7adf11ee61;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;


void slog_rules_c53642b523c6cca89(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst1avh200 const6b86b273ff34fce19d6b804e) (let __tconst2EOh201 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t3q4d203 __t6ICG202) (body (join mp_hsb_ans (0 1) 1 __t3q4d203 __v0) (join mp_hsb (0 1) 0 __t4c2e199 x) (cmp lt __tconst1avh200 x) (let chk2oAG1088 (_0002f x __tconst2EOh201)) (eq __t6ICG202 chk2oAG1088) (let __t4Iug198 (_0002a __tconst2EOh201 __v0))) (head (emit-temp temp2Hkq1086 __t4Iug198 __t4c2e199)) map.slog:19 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex0;  slog::Index** mp_hsbindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Hkq1086");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex0 = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("mp_hsb");
      mp_hsbindex1 = readrel6->getIndex(ord5, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c3 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex0, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m7) {
          u64 v_c4 = m7[1];
          slog::join_all<2>(mp_hsbindex1, [&](const std::array<u64,2>& m8) {
            u64 v_c5 = m8[0]; u64 v_c6 = m8[1];
            u64 v_c7 = _prim_lt(db, v_c0, v_c6);
            if (v_c7 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (!v_c7) return;
            u64 v_c8 = _prim__0002f(db, v_c6, v_c1);
            if (v_c8 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (v_c3 != v_c8) return;
            u64 v_c9 = _prim__0002a(db, v_c1, v_c4);
            if (v_c9 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c9, v_c5});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
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
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan $sup5638x107x0x0x0 __t05l7352 l m n p q r u v) (body (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 v) (join-old $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t05l7352 l m p r __t4mLe355) (exists mp_msk (1 2 0) 3 p n __t4mLe355) (exists mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3rQ8350) (exists mp_union (2 0 1) 2 __t3rQ8350 __t05l7352) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_union (0 1 2) 3 (0 1 2) __t05l7352 __t6yxH356 __t3rQ8350) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex10;  slog::Index** mbranchindex11;  slog::Index** mp_mskindex12;  slog::Index** mp_msk_ansindex13;  slog::Index** mp_unionindex14;  slog::Index** $sup5638x107x0x0x1index15;  slog::Index** mp_mskindex16;  slog::Index** mp_msk_ansindex17;  slog::Index** mbranchindex18;  slog::Index** mp_unionindex19;  slog::Index** mbranchindex20;  slog::Index** mp_unionindex21;  slog::Index** mp_mskindex22;  slog::Index** mp_msk_ansindex23;  slog::Index** mp_unionindex24;  slog::Index** mp_union_ansindex25;  slog::Index** $sup5638x107x0x0x1delta26;  slog::Index** mbranchdelta27;  slog::Index** mbranchdelta28;  slog::Index** mp_uniondelta29;  slog::Index** mp_mskdelta30;  slog::Index** mp_uniondelta31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord33({1, 2, 3, 4, 0});
      slog::Relation* readrel34 = db->getRelation("mbranch");
      mbranchindex10 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 3, 4, 0});
      slog::Relation* readrel36 = db->getRelation("mbranch");
      mbranchindex11 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("mp_msk");
      mp_mskindex12 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex13 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 0, 1});
      slog::Relation* readrel42 = db->getRelation("mp_union");
      mp_unionindex14 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel44 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index15 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel46 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta26 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("mp_msk");
      mp_mskindex16 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex17 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 3, 4, 0});
      slog::Relation* readrel52 = db->getRelation("mbranch");
      mbranchindex18 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 3, 4, 0});
      slog::Relation* readrel54 = db->getRelation("mbranch");
      mbranchdelta27 = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({2, 0, 1});
      slog::Relation* readrel56 = db->getRelation("mp_union");
      mp_unionindex19 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 3, 4, 0});
      slog::Relation* readrel58 = db->getRelation("mbranch");
      mbranchindex20 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 3, 4, 0});
      slog::Relation* readrel60 = db->getRelation("mbranch");
      mbranchdelta28 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0, 1, 2});
      slog::Relation* readrel62 = db->getRelation("mp_union");
      mp_unionindex21 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1, 2});
      slog::Relation* readrel64 = db->getRelation("mp_union");
      mp_uniondelta29 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("mp_msk");
      mp_mskindex22 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("mp_msk");
      mp_mskdelta30 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex23 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("mp_union");
      mp_unionindex24 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("mp_union");
      mp_uniondelta31 = readrel74->getIndex(ord73, true);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("mp_union_ans");
      mp_union_ansindex25 = readrel76->getIndex(ord75, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c17 = _t[6];
        u64 v_c18 = _t[7];
        u64 v_c19 = _t[8];
        u64 v_c20 = _prim_lt(db, v_c13, v_c14);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
        if (!v_c20) return;
        if (!slog::exists_probe<5,4>(mbranchindex10, std::array<u64,5>{v_c16, v_c14, v_c18, v_c19, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex11, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex12, std::array<u64,3>{v_c15, v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex13, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex14, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x107x0x0x1index15, $sup5638x107x0x0x1delta26, std::array<u64,10>{v_c19, v_c14, v_c16, v_c18, v_c11, v_c12, v_c13, v_c15, v_c17, 0}, [&](const std::array<u64,10>& m78) {
          u64 v_c21 = m78[9];
          if (!slog::exists_probe<3,3>(mp_mskindex16, std::array<u64,3>{v_c15, v_c14, v_c21})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex17, std::array<u64,2>{v_c21, v_c16})) return;
          slog::join_probe_old<5,4>(mbranchindex18, mbranchdelta27, std::array<u64,5>{v_c16, v_c14, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m79) {
            u64 v_c22 = m79[4];
            if (!slog::exists_probe<3,2>(mp_unionindex19, std::array<u64,3>{v_c22, v_c11, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex20, mbranchdelta28, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m80) {
              u64 v_c23 = m80[4];
              slog::join_probe_old<3,3>(mp_unionindex21, mp_uniondelta29, std::array<u64,3>{v_c11, v_c23, v_c22}, [&](const std::array<u64,3>& m81) {
                slog::join_probe_old<3,3>(mp_mskindex22, mp_mskdelta30, std::array<u64,3>{v_c15, v_c14, v_c21}, [&](const std::array<u64,3>& m82) {
                  slog::join_probe<2,2>(mp_msk_ansindex23, std::array<u64,2>{v_c21, v_c16}, [&](const std::array<u64,2>& m83) {
                    slog::join_probe_old<3,2>(mp_unionindex24, mp_uniondelta31, std::array<u64,3>{v_c23, v_c19, 0}, [&](const std::array<u64,3>& m84) {
                      u64 v_c24 = m84[2];
                      slog::join_probe<2,1>(mp_union_ansindex25, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m85) {
                        u64 v_c4 = m85[1];
                        u64 v_c25 = _prim_band(db, v_c15, v_c14);
                        if (v_c25 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c26 = _prim_gt(db, v_c25, v_c10);
                        if (v_c26 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c26) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c11, v_c4, v_c14, v_c16, v_c18});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c14, v_c18, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask32* _cont = new ReadTask32(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), false);
  // (crule (pre (let _00024sqc3YKs469 constd4735e3a265e16eee03f5971) (let _00024sqc3l4i470 const5feceb66ffc86f38d952786c) (let _00024sqc1plA471 const6b86b273ff34fce19d6b804e) (let _00024sqc0uMH474 const6b86b273ff34fce19d6b804e) (let _00024sqc0QlG475 const5feceb66ffc86f38d952786c) (let _00024sqc8yW9476 const6b86b273ff34fce19d6b804e) (let _00024sqc2Cu3477 const5feceb66ffc86f38d952786c) (let __trid3QtD732 const1ef5dd96b7ac876a994a9ca1) (let __trel6Jje733 const1064263932db82f2cf6d4ac2) (let __tcol2KG2734 const6b86b273ff34fce19d6b804e)) (scan mp_fromlist_ans __t7GcH340 __v0) (body (join mp_fromlist (0 1) 1 __t7GcH340 xs) (join $sup5638x127x0x0x0 (5 0 1 2 3 4) 1 xs _00024seq0 _00024seq1 __d0 k v) (letp _00024sql1wuY472 (aslst _00024seq1)) (let _00024sqn6ks0473 (llen _00024sql1wuY472)) (cmp ge _00024sqn6ks0473 _00024sqc0uMH474) (letp _00024sql8L6F467 (aslst _00024seq0)) (let chk9Kex1037 (llen _00024sql8L6F467)) (eq _00024sqc3YKs469 chk9Kex1037) (letp chk0bbD1038 (lref _00024sql8L6F467 _00024sqc3l4i470)) (eq k chk0bbD1038) (letp chk17vJ1039 (lref _00024sql8L6F467 _00024sqc1plA471)) (eq v chk17vJ1039) (letp chk4OY41040 (lref _00024sql1wuY472 _00024sqc0QlG475)) (eq _00024seq0 chk4OY41040) (let _00024sqp4OtM478 (_0002d _00024sqn6ks0473 _00024sqc2Cu3477)) (let chk00XB1041 (lslice _00024sql1wuY472 _00024sqc8yW9476 _00024sqp4OtM478)) (eq xs chk00XB1041)) (head (tycheck k (accept int) __trid3QtD732 __trel6Jje733 __tcol2KG2734 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __55QJ731 __v0 k v)) map.slog:128 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_fromlistindex87;  slog::Index** $sup5638x127x0x0x0index88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("mp_fromlist");
      mp_fromlistindex87 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({5, 0, 1, 2, 3, 4});
      slog::Relation* readrel93 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index88 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_constd4735e3a265e16eee03f5971;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = v_const1ef5dd96b7ac876a994a9ca1;
      u64 v_c35 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe<2,1>(mp_fromlistindex87, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m94) {
          u64 v_c38 = m94[1];
          slog::join_probe<6,1>($sup5638x127x0x0x0index88, std::array<u64,6>{v_c38, 0, 0, 0, 0, 0}, [&](const std::array<u64,6>& m95) {
            u64 v_c39 = m95[1]; u64 v_c40 = m95[2]; u64 v_c41 = m95[3]; u64 v_c42 = m95[4]; u64 v_c19 = m95[5];
            bool ok96 = true;
            u64 v_c43 = _prim_aslst(db, v_c40, &ok96);
            if (!ok96) return;
            u64 v_c44 = _prim_llen(db, v_c43);
            if (v_c44 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c45 = _prim_ge(db, v_c44, v_c30);
            if (v_c45 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (!v_c45) return;
            bool ok98 = true;
            u64 v_c46 = _prim_aslst(db, v_c39, &ok98);
            if (!ok98) return;
            u64 v_c47 = _prim_llen(db, v_c46);
            if (v_c47 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (v_c27 != v_c47) return;
            bool ok99 = true;
            u64 v_c48 = _prim_lref(db, v_c46, v_c28, &ok99);
            if (!ok99) return;
            if (v_c42 != v_c48) return;
            bool ok100 = true;
            u64 v_c49 = _prim_lref(db, v_c46, v_c29, &ok100);
            if (!ok100) return;
            if (v_c19 != v_c49) return;
            bool ok101 = true;
            u64 v_c50 = _prim_lref(db, v_c43, v_c31, &ok101);
            if (!ok101) return;
            if (v_c39 != v_c50) return;
            u64 v_c51 = _prim__0002d(db, v_c44, v_c33);
            if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c52 = _prim_lslice(db, v_c43, v_c32, v_c51);
            if (v_c52 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (v_c38 != v_c52) return;
            ++_fires;
            if (!(is_int(v_c42)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c35, v_c36, v_c42}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c4, v_c42, v_c19}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask89* _cont = new ReadTask89(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask89(db,b), false);
  // (crule (pre (let __tconst4J6Y274 const6b86b273ff34fce19d6b804e)) (scan mbranch __t04rT271 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t04rT271 __t8s9M273 __t7G5n272) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t7G5n272 p m l r) (cmp lt m n) (let __t2pJK275 (band p n)) (cmp lt __t2pJK275 __tconst4J6Y274)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t8s9M273 u l m n p q r v)) map.slog:105 #f)
  class ReadTask106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex102;  slog::Index** mbranchindex103;  slog::Index** mp_uniondelta104;  slog::Index** mbranchdelta105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord107({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel108 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel108->getIndex(ord107, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord109({2, 0, 1});
      slog::Relation* readrel110 = db->getRelation("mp_union");
      mp_unionindex102 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({2, 0, 1});
      slog::Relation* readrel112 = db->getRelation("mp_union");
      mp_uniondelta104 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({0, 1, 2, 3, 4});
      slog::Relation* readrel114 = db->getRelation("mbranch");
      mbranchindex103 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1, 2, 3, 4});
      slog::Relation* readrel116 = db->getRelation("mbranch");
      mbranchdelta105 = readrel116->getIndex(ord115, true);
  
    }
    ReadTask106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c54 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex102, mp_uniondelta104, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m117) {
          u64 v_c55 = m117[1]; u64 v_c56 = m117[2];
          slog::join_probe_old<5,1>(mbranchindex103, mbranchdelta105, std::array<u64,5>{v_c56, 0, 0, 0, 0}, [&](const std::array<u64,5>& m118) {
            u64 v_c15 = m118[1]; u64 v_c13 = m118[2]; u64 v_c12 = m118[3]; u64 v_c17 = m118[4];
            u64 v_c57 = _prim_lt(db, v_c13, v_c14);
            if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c57) return;
            u64 v_c58 = _prim_band(db, v_c15, v_c14);
            if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c59 = _prim_lt(db, v_c58, v_c53);
            if (v_c59 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c59) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c55, v_c18, v_c12, v_c13, v_c14, v_c15, v_c16, v_c17, v_c19}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask106* _cont = new ReadTask106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask106(db,b), false);
  // (crule (pre (let __tconst1tdf238 const5feceb66ffc86f38d952786c)) (scan mbranch __t8FcE235 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t8FcE235 __t7Vjh237 __t6hXy236) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6hXy236 p m l r) (cmp lt m n) (let __t7cw8239 (band p n)) (cmp gt __t7cw8239 __tconst1tdf238)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t7Vjh237 v l m n p q r u)) map.slog:108 #f)
  class ReadTask125 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex121;  slog::Index** mbranchindex122;  slog::Index** mp_uniondelta123;  slog::Index** mbranchdelta124;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord126({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel127 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel127->getIndex(ord126, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord128({2, 0, 1});
      slog::Relation* readrel129 = db->getRelation("mp_union");
      mp_unionindex121 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({2, 0, 1});
      slog::Relation* readrel131 = db->getRelation("mp_union");
      mp_uniondelta123 = readrel131->getIndex(ord130, true);
      std::vector<u16> ord132({0, 1, 2, 3, 4});
      slog::Relation* readrel133 = db->getRelation("mbranch");
      mbranchindex122 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1, 2, 3, 4});
      slog::Relation* readrel135 = db->getRelation("mbranch");
      mbranchdelta124 = readrel135->getIndex(ord134, true);
  
    }
    ReadTask125(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c14 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex121, mp_uniondelta123, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m136) {
          u64 v_c62 = m136[1]; u64 v_c63 = m136[2];
          slog::join_probe_old<5,1>(mbranchindex122, mbranchdelta124, std::array<u64,5>{v_c63, 0, 0, 0, 0}, [&](const std::array<u64,5>& m137) {
            u64 v_c15 = m137[1]; u64 v_c13 = m137[2]; u64 v_c12 = m137[3]; u64 v_c17 = m137[4];
            u64 v_c64 = _prim_lt(db, v_c13, v_c14);
            if (v_c64 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c64) return;
            u64 v_c65 = _prim_band(db, v_c15, v_c14);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c66 = _prim_gt(db, v_c65, v_c60);
            if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c66) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c62, v_c19, v_c12, v_c13, v_c14, v_c15, v_c16, v_c17, v_c18}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask125* _cont = new ReadTask125(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask125(db,b), false);
  // (crule (pre (let __trid8cGK641 consta0e8b3efb8cecb7adf11ee61) (let __trel3loT642 constdd7bbf31ce5f578b9805e840) (let __tcol8nDz643 const5feceb66ffc86f38d952786c) (let __trel9bZA644 constdd7bbf31ce5f578b9805e840) (let __tcol7oRd645 const6b86b273ff34fce19d6b804e)) (scan $sup5638x59x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid8cGK641 __trel3loT642 __tcol8nDz643 (1 2 3 4 0)) (tycheck m (accept int) __trid8cGK641 __trel9bZA644 __tcol7oRd645 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __5Ert640 k m)) map.slog:60 #f)
  class ReadTask140 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x59x0x0x0");
  
    }
    ReadTask140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_consta0e8b3efb8cecb7adf11ee61;
      u64 v_c68 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c17 = _t[5];
        ++_fires;
        if (!(is_int(v_c42)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c67, v_c68, v_c69, v_c42}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c13)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c67, v_c70, v_c71, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c42, v_c13}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:$sup5638x59x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask140* _cont = new ReadTask140(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask140(db,b), false);
  // (crule (pre) (scan mp_put __t3qfB304 __t7hGG305 k v) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t7hGG305 p m l r)) (head (emit $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) k m v __t3qfB304 l p r __t7hGG305)) map.slog:45 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex141;  slog::Index** mbranchdelta142;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord144({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel145 = db->getRelation("$sup5638x44x0x0x0");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord146({0, 1, 2, 3, 4});
      slog::Relation* readrel147 = db->getRelation("mbranch");
      mbranchindex141 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1, 2, 3, 4});
      slog::Relation* readrel149 = db->getRelation("mbranch");
      mbranchdelta142 = readrel149->getIndex(ord148, true);
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[1];
        u64 v_c42 = _t[2];
        u64 v_c19 = _t[3];
        slog::join_probe_old<5,1>(mbranchindex141, mbranchdelta142, std::array<u64,5>{v_c73, 0, 0, 0, 0}, [&](const std::array<u64,5>& m150) {
          u64 v_c15 = m150[1]; u64 v_c13 = m150[2]; u64 v_c12 = m150[3]; u64 v_c17 = m150[4];
          ++_fires;
          slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c42, v_c13, v_c19, v_c72, v_c12, v_c15, v_c17, v_c73}, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan mbranch __t687K71 p m l r) (body (exists $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 4 l m p r) (exists mp_put (1 2 0 3) 1 __t687K71) (exists mp_msk (2 0 1) 1 m) (exists mp_put (1 2 0 3) 1 l) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 4 p l m r __t1I5N72 k v) (exists mp_put (1 2 0 3) 4 __t687K71 k __t1I5N72 v) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t1I5N72 k v __t0q1c75) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t687K71 k __t1I5N72 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0q1c75) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index151;  slog::Index** mp_putindex152;  slog::Index** mp_mskindex153;  slog::Index** mp_putindex154;  slog::Index** mp_msk_ansindex155;  slog::Index** $sup5638x40x0x0x0index156;  slog::Index** mp_putindex157;  slog::Index** mp_mskindex158;  slog::Index** mp_putindex159;  slog::Index** $sup5638x40x0x0x1index160;  slog::Index** mp_putindex161;  slog::Index** mp_mskindex162;  slog::Index** mp_msk_ansindex163;  slog::Index** mp_putindex164;  slog::Index** mp_msk_ansindex165;  slog::Index** mp_put_ansindex166;  slog::Index** mp_putdelta167;  slog::Index** mp_mskdelta168;  slog::Index** mp_putdelta169;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord171({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel172 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index151 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0, 3});
      slog::Relation* readrel174 = db->getRelation("mp_put");
      mp_putindex152 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({2, 0, 1});
      slog::Relation* readrel176 = db->getRelation("mp_msk");
      mp_mskindex153 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0, 3});
      slog::Relation* readrel178 = db->getRelation("mp_put");
      mp_putindex154 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex155 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel182 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index156 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0, 3});
      slog::Relation* readrel184 = db->getRelation("mp_put");
      mp_putindex157 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("mp_msk");
      mp_mskindex158 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 3, 0});
      slog::Relation* readrel188 = db->getRelation("mp_put");
      mp_putindex159 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel190 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index160 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0, 3});
      slog::Relation* readrel192 = db->getRelation("mp_put");
      mp_putindex161 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 0, 3});
      slog::Relation* readrel194 = db->getRelation("mp_put");
      mp_putdelta167 = readrel194->getIndex(ord193, true);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("mp_msk");
      mp_mskindex162 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("mp_msk");
      mp_mskdelta168 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex163 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 3, 0});
      slog::Relation* readrel202 = db->getRelation("mp_put");
      mp_putindex164 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 3, 0});
      slog::Relation* readrel204 = db->getRelation("mp_put");
      mp_putdelta169 = readrel204->getIndex(ord203, true);
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex165 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 1});
      slog::Relation* readrel208 = db->getRelation("mp_put_ans");
      mp_put_ansindex166 = readrel208->getIndex(ord207, false);
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c17 = _t[4];
        if (!slog::exists_probe<8,4>($sup5638x40x0x0x1index151, std::array<u64,8>{v_c12, v_c13, v_c15, v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex152, std::array<u64,4>{v_c75, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex153, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex154, std::array<u64,4>{v_c12, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex155, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<7,4>($sup5638x40x0x0x0index156, std::array<u64,7>{v_c15, v_c12, v_c13, v_c17, 0, 0, 0}, [&](const std::array<u64,7>& m209) {
          u64 v_c76 = m209[4]; u64 v_c42 = m209[5]; u64 v_c19 = m209[6];
          if (!slog::exists_probe<4,4>(mp_putindex157, std::array<u64,4>{v_c75, v_c42, v_c76, v_c19})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex158, std::array<u64,3>{v_c42, v_c13, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex159, std::array<u64,4>{v_c12, v_c42, v_c19, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index160, std::array<u64,8>{v_c12, v_c13, v_c15, v_c17, v_c76, v_c42, v_c19, 0}, [&](const std::array<u64,8>& m210) {
            u64 v_c77 = m210[7];
            slog::join_probe_old<4,4>(mp_putindex161, mp_putdelta167, std::array<u64,4>{v_c75, v_c42, v_c76, v_c19}, [&](const std::array<u64,4>& m211) {
              slog::join_probe_old<3,3>(mp_mskindex162, mp_mskdelta168, std::array<u64,3>{v_c42, v_c13, v_c77}, [&](const std::array<u64,3>& m212) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex163, std::array<u64,2>{v_c77, v_c15})) return;
                slog::join_probe_old<4,3>(mp_putindex164, mp_putdelta169, std::array<u64,4>{v_c12, v_c42, v_c19, 0}, [&](const std::array<u64,4>& m213) {
                  u64 v_c78 = m213[3];
                  slog::join_probe<2,2>(mp_msk_ansindex165, std::array<u64,2>{v_c77, v_c15}, [&](const std::array<u64,2>& m214) {
                    slog::join_probe<2,1>(mp_put_ansindex166, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m215) {
                      u64 v_c4 = m215[1];
                      u64 v_c79 = _prim_band(db, v_c42, v_c13);
                      if (v_c79 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c80 = _prim_lt(db, v_c79, v_c74);
                      if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c80) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c76, v_c4, v_c13, v_c15, v_c17});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c13, v_c4, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mp_has0_ans __t6Hok114 a) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t6Hok114 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t68rk111 l m p) (exists mp_has0 (0 2 1) 2 __t68rk111 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t032L110) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t68rk111 k __t032L110) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9QiO115) (join-old mp_msk_ans (0 1) 2 (0 1) __t9QiO115 p) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask235 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index217;  slog::Index** mbranchindex218;  slog::Index** mp_has0index219;  slog::Index** mp_mskindex220;  slog::Index** $sup5638x62x0x0x0index221;  slog::Index** mp_has0index222;  slog::Index** mp_mskindex223;  slog::Index** mp_msk_ansindex224;  slog::Index** mbranchindex225;  slog::Index** mp_has0index226;  slog::Index** mp_mskindex227;  slog::Index** mp_msk_ansindex228;  slog::Index** mp_has0delta229;  slog::Index** $sup5638x62x0x0x0delta230;  slog::Index** mbranchdelta231;  slog::Index** mp_has0delta232;  slog::Index** mp_mskdelta233;  slog::Index** mp_msk_ansdelta234;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord236({0, 1});
      slog::Relation* readrel237 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel237->getIndex(ord236, false);
      outer_rel = db->getRelation("mp_has0_ans");
      std::vector<u16> ord238({0, 2, 1});
      slog::Relation* readrel239 = db->getRelation("mp_has0");
      mp_has0index217 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 2, 1});
      slog::Relation* readrel241 = db->getRelation("mp_has0");
      mp_has0delta229 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({4, 0, 1, 2, 3});
      slog::Relation* readrel243 = db->getRelation("mbranch");
      mbranchindex218 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 0, 1});
      slog::Relation* readrel245 = db->getRelation("mp_has0");
      mp_has0index219 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("mp_msk");
      mp_mskindex220 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel249 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index221 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel251 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0delta230 = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({0, 2, 1});
      slog::Relation* readrel253 = db->getRelation("mp_has0");
      mp_has0index222 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("mp_msk");
      mp_mskindex223 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0});
      slog::Relation* readrel257 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex224 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 3, 4, 0});
      slog::Relation* readrel259 = db->getRelation("mbranch");
      mbranchindex225 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 2, 3, 4, 0});
      slog::Relation* readrel261 = db->getRelation("mbranch");
      mbranchdelta231 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({0, 2, 1});
      slog::Relation* readrel263 = db->getRelation("mp_has0");
      mp_has0index226 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({0, 2, 1});
      slog::Relation* readrel265 = db->getRelation("mp_has0");
      mp_has0delta232 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("mp_msk");
      mp_mskindex227 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("mp_msk");
      mp_mskdelta233 = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex228 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta234 = readrel273->getIndex(ord272, true);
  
    }
    ReadTask235(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c82 = _t[0];
        u64 v_c83 = _t[1];
        slog::join_probe_old<3,1>(mp_has0index217, mp_has0delta229, std::array<u64,3>{v_c82, 0, 0}, [&](const std::array<u64,3>& m274) {
          u64 v_c42 = m274[1]; u64 v_c17 = m274[2];
          if (!slog::exists_probe<5,1>(mbranchindex218, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index219, std::array<u64,3>{v_c42, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex220, std::array<u64,3>{v_c42, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x62x0x0x0index221, $sup5638x62x0x0x0delta230, std::array<u64,6>{v_c42, v_c17, 0, 0, 0, 0}, [&](const std::array<u64,6>& m275) {
            u64 v_c84 = m275[2]; u64 v_c12 = m275[3]; u64 v_c13 = m275[4]; u64 v_c15 = m275[5];
            if (!slog::exists_probe<3,2>(mp_has0index222, std::array<u64,3>{v_c84, v_c42, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex223, std::array<u64,3>{v_c42, v_c13, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex224, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex225, mbranchdelta231, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m276) {
              u64 v_c85 = m276[4];
              slog::join_probe_old<3,3>(mp_has0index226, mp_has0delta232, std::array<u64,3>{v_c84, v_c42, v_c85}, [&](const std::array<u64,3>& m277) {
                slog::join_probe_old<3,2>(mp_mskindex227, mp_mskdelta233, std::array<u64,3>{v_c42, v_c13, 0}, [&](const std::array<u64,3>& m278) {
                  u64 v_c86 = m278[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex228, mp_msk_ansdelta234, std::array<u64,2>{v_c86, v_c15}, [&](const std::array<u64,2>& m279) {
                    u64 v_c87 = _prim_band(db, v_c42, v_c13);
                    if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c88 = _prim_gt(db, v_c87, v_c81);
                    if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c88) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c83}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0_ans", _fires);
  
      if (!_done)
      {
        ReadTask235* _cont = new ReadTask235(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask235(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t1Rb9367 __v1) (body (join mp_hsb_ans (0 1) 1 __t1Rb9367 __v3) (join-old mp_hsb (0 1) 1 (0 1) __t1Rb9367 __t3QgY368) (join-old $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk0Dth1065 (bxor p0 p1)) (eq __t3QgY368 chk0Dth1065)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t1Rb9367 __t1Rb9367 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask286 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex281;  slog::Index** mp_hsbindex282;  slog::Index** $sup5638x25x0x0x1index283;  slog::Index** mp_hsbdelta284;  slog::Index** $sup5638x25x0x0x1delta285;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord287({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel288 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel288->getIndex(ord287, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex281 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("mp_hsb");
      mp_hsbindex282 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_hsb");
      mp_hsbdelta284 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel296 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index283 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel298 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta285 = readrel298->getIndex(ord297, true);
  
    }
    ReadTask286(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c90 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex281, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m299) {
          u64 v_c91 = m299[1];
          slog::join_probe_old<2,1>(mp_hsbindex282, mp_hsbdelta284, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m300) {
            u64 v_c92 = m300[1];
            slog::join_all_old<7>($sup5638x25x0x0x1index283, $sup5638x25x0x0x1delta285, [&](const std::array<u64,7>& m301) {
              u64 v_c93 = m301[0]; u64 v_c4 = m301[1]; u64 v_c41 = m301[2]; u64 v_c94 = m301[3]; u64 v_c95 = m301[4]; u64 v_c96 = m301[5]; u64 v_c97 = m301[6];
              u64 v_c98 = _prim_bxor(db, v_c94, v_c95);
              if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c92 != v_c98) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c93, v_c4, v_c91, v_c90, v_c41, v_c89, v_c89, v_c94, v_c95, v_c96, v_c97}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask286* _cont = new ReadTask286(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask286(db,b), false);
  // (crule (pre) (scan mp_join_ans __t1dCZ326 r) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t1dCZ326 k __t6sa2325 j __t4DNq324) (neq j k) (exists mleaf (0 1 2) 2 __t6sa2325 k) (exists mp_put (1 2 0 3) 2 __t4DNq324 k) (join-old mleaf (0 1 2) 2 (0 1 2) __t4DNq324 j w) (join-old mleaf (0 1 2) 2 (0 1 2) __t6sa2325 k v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __t4DNq324 k v __t529R323)) (head (emit mp_put_ans (0 1) __t529R323 r)) map.slog:39 #f)
  class ReadTask312 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex302;  slog::Index** mleafindex303;  slog::Index** mp_putindex304;  slog::Index** mleafindex305;  slog::Index** mleafindex306;  slog::Index** mp_putindex307;  slog::Index** mp_joindelta308;  slog::Index** mleafdelta309;  slog::Index** mleafdelta310;  slog::Index** mp_putdelta311;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("mp_put_ans");
      head_index[0] = readrel314->getIndex(ord313, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord315({0, 1, 2, 3, 4});
      slog::Relation* readrel316 = db->getRelation("mp_join");
      mp_joinindex302 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({0, 1, 2, 3, 4});
      slog::Relation* readrel318 = db->getRelation("mp_join");
      mp_joindelta308 = readrel318->getIndex(ord317, true);
      std::vector<u16> ord319({0, 1, 2});
      slog::Relation* readrel320 = db->getRelation("mleaf");
      mleafindex303 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 2, 0, 3});
      slog::Relation* readrel322 = db->getRelation("mp_put");
      mp_putindex304 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({0, 1, 2});
      slog::Relation* readrel324 = db->getRelation("mleaf");
      mleafindex305 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({0, 1, 2});
      slog::Relation* readrel326 = db->getRelation("mleaf");
      mleafdelta309 = readrel326->getIndex(ord325, true);
      std::vector<u16> ord327({0, 1, 2});
      slog::Relation* readrel328 = db->getRelation("mleaf");
      mleafindex306 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 1, 2});
      slog::Relation* readrel330 = db->getRelation("mleaf");
      mleafdelta310 = readrel330->getIndex(ord329, true);
      std::vector<u16> ord331({1, 2, 3, 0});
      slog::Relation* readrel332 = db->getRelation("mp_put");
      mp_putindex307 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 3, 0});
      slog::Relation* readrel334 = db->getRelation("mp_put");
      mp_putdelta311 = readrel334->getIndex(ord333, true);
  
    }
    ReadTask312(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex302, mp_joindelta308, std::array<u64,5>{v_c99, 0, 0, 0, 0}, [&](const std::array<u64,5>& m335) {
          u64 v_c42 = m335[1]; u64 v_c100 = m335[2]; u64 v_c101 = m335[3]; u64 v_c102 = m335[4];
          if (v_c101 == v_c42) return;
          if (!slog::exists_probe<3,2>(mleafindex303, std::array<u64,3>{v_c100, v_c42, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex304, std::array<u64,4>{v_c102, v_c42, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex305, mleafdelta309, std::array<u64,3>{v_c102, v_c101, 0}, [&](const std::array<u64,3>& m336) {
            u64 v_c103 = m336[2];
            slog::join_probe_old<3,2>(mleafindex306, mleafdelta310, std::array<u64,3>{v_c100, v_c42, 0}, [&](const std::array<u64,3>& m337) {
              u64 v_c19 = m337[2];
              slog::join_probe_old<4,3>(mp_putindex307, mp_putdelta311, std::array<u64,4>{v_c102, v_c42, v_c19, 0}, [&](const std::array<u64,4>& m338) {
                u64 v_c104 = m338[3];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c17}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_join_ans", _fires);
  
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
  // (crule (pre) (scan temp2ytq1023 __t9rnk262 __v0 __v1 m p) (body (join mbranch (1 2 3 4 0) 4 p m __v0 __v1 __t2msK259)) (head (emit mp_union_ans (0 1) __t9rnk262 __t2msK259)) map.slog:94 #f)
  class ReadTask340 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex339;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord341({0, 1});
      slog::Relation* readrel342 = db->getRelation("mp_union_ans");
      head_index[0] = readrel342->getIndex(ord341, false);
      outer_rel = db->getRelation("temp2ytq1023");
      std::vector<u16> ord343({1, 2, 3, 4, 0});
      slog::Relation* readrel344 = db->getRelation("mbranch");
      mbranchindex339 = readrel344->getIndex(ord343, false);
  
    }
    ReadTask340(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c90 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c15 = _t[4];
        slog::join_probe<5,4>(mbranchindex339, std::array<u64,5>{v_c15, v_c13, v_c4, v_c90, 0}, [&](const std::array<u64,5>& m345) {
          u64 v_c106 = m345[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c106}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:temp2ytq1023", _fires);
  
      if (!_done)
      {
        ReadTask340* _cont = new ReadTask340(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask340(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t7iEH288 __v0) (body (join-old mp_put (0 1 2 3) 1 (0 1 2 3) __t7iEH288 r k v) (exists $sup5638x42x0x0x1 (2 6 7 0 1 3 4 5) 3 k r v) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x42x0x0x0 (1 5 6 0 2 3 4) 3 (1 5 6 0 2 3 4) k r v __t0ekw284 l m p) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t0ekw284 k v __t8lnB287) (exists mp_msk (1 2 0) 3 k m __t8lnB287) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t07OG283) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t07OG283 k __t0ekw284 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t8lnB287) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask369 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex346;  slog::Index** $sup5638x42x0x0x1index347;  slog::Index** mbranchindex348;  slog::Index** mp_putindex349;  slog::Index** mp_mskindex350;  slog::Index** $sup5638x42x0x0x0index351;  slog::Index** mbranchindex352;  slog::Index** mp_putindex353;  slog::Index** mp_mskindex354;  slog::Index** mp_msk_ansindex355;  slog::Index** $sup5638x42x0x0x1index356;  slog::Index** mp_mskindex357;  slog::Index** mp_msk_ansindex358;  slog::Index** mbranchindex359;  slog::Index** mp_putindex360;  slog::Index** mp_mskindex361;  slog::Index** mp_msk_ansindex362;  slog::Index** mp_putdelta363;  slog::Index** $sup5638x42x0x0x0delta364;  slog::Index** $sup5638x42x0x0x1delta365;  slog::Index** mbranchdelta366;  slog::Index** mp_putdelta367;  slog::Index** mp_mskdelta368;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord370({0, 1, 2, 3});
      slog::Relation* readrel371 = db->getRelation("mp_put");
      mp_putindex346 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 1, 2, 3});
      slog::Relation* readrel373 = db->getRelation("mp_put");
      mp_putdelta363 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({2, 6, 7, 0, 1, 3, 4, 5});
      slog::Relation* readrel375 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index347 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({4, 0, 1, 2, 3});
      slog::Relation* readrel377 = db->getRelation("mbranch");
      mbranchindex348 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({2, 3, 0, 1});
      slog::Relation* readrel379 = db->getRelation("mp_put");
      mp_putindex349 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("mp_msk");
      mp_mskindex350 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel383 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index351 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel385 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0delta364 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({1, 2, 3, 4, 0});
      slog::Relation* readrel387 = db->getRelation("mbranch");
      mbranchindex352 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 3, 0, 1});
      slog::Relation* readrel389 = db->getRelation("mp_put");
      mp_putindex353 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("mp_msk");
      mp_mskindex354 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex355 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel395 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index356 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel397 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta365 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("mp_msk");
      mp_mskindex357 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex358 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 2, 3, 4, 0});
      slog::Relation* readrel403 = db->getRelation("mbranch");
      mbranchindex359 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 3, 4, 0});
      slog::Relation* readrel405 = db->getRelation("mbranch");
      mbranchdelta366 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({1, 2, 0, 3});
      slog::Relation* readrel407 = db->getRelation("mp_put");
      mp_putindex360 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0, 3});
      slog::Relation* readrel409 = db->getRelation("mp_put");
      mp_putdelta367 = readrel409->getIndex(ord408, true);
      std::vector<u16> ord410({1, 2, 0});
      slog::Relation* readrel411 = db->getRelation("mp_msk");
      mp_mskindex361 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("mp_msk");
      mp_mskdelta368 = readrel413->getIndex(ord412, true);
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex362 = readrel415->getIndex(ord414, false);
  
    }
    ReadTask369(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c108 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex346, mp_putdelta363, std::array<u64,4>{v_c108, 0, 0, 0}, [&](const std::array<u64,4>& m416) {
          u64 v_c17 = m416[1]; u64 v_c42 = m416[2]; u64 v_c19 = m416[3];
          if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index347, std::array<u64,8>{v_c42, v_c17, v_c19, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex348, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex349, std::array<u64,4>{v_c42, v_c19, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex350, std::array<u64,3>{v_c42, 0, 0})) return;
          slog::join_probe_old<7,3>($sup5638x42x0x0x0index351, $sup5638x42x0x0x0delta364, std::array<u64,7>{v_c42, v_c17, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,7>& m417) {
            u64 v_c109 = m417[3]; u64 v_c12 = m417[4]; u64 v_c13 = m417[5]; u64 v_c15 = m417[6];
            if (!slog::exists_probe<5,4>(mbranchindex352, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex353, std::array<u64,4>{v_c42, v_c19, v_c109, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex354, std::array<u64,3>{v_c42, v_c13, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex355, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe_old<8,7>($sup5638x42x0x0x1index356, $sup5638x42x0x0x1delta365, std::array<u64,8>{v_c12, v_c13, v_c15, v_c17, v_c109, v_c42, v_c19, 0}, [&](const std::array<u64,8>& m418) {
              u64 v_c110 = m418[7];
              if (!slog::exists_probe<3,3>(mp_mskindex357, std::array<u64,3>{v_c42, v_c13, v_c110})) return;
              if (!slog::exists_probe<2,2>(mp_msk_ansindex358, std::array<u64,2>{v_c110, v_c15})) return;
              slog::join_probe_old<5,4>(mbranchindex359, mbranchdelta366, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m419) {
                u64 v_c111 = m419[4];
                slog::join_probe_old<4,4>(mp_putindex360, mp_putdelta367, std::array<u64,4>{v_c111, v_c42, v_c109, v_c19}, [&](const std::array<u64,4>& m420) {
                  slog::join_probe_old<3,3>(mp_mskindex361, mp_mskdelta368, std::array<u64,3>{v_c42, v_c13, v_c110}, [&](const std::array<u64,3>& m421) {
                    slog::join_probe<2,2>(mp_msk_ansindex362, std::array<u64,2>{v_c110, v_c15}, [&](const std::array<u64,2>& m422) {
                      u64 v_c112 = _prim_band(db, v_c42, v_c13);
                      if (v_c112 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c113 = _prim_gt(db, v_c112, v_c107);
                      if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c113) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c109, v_c4, v_c12, v_c13, v_c15});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c13, v_c12, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put_ans", _fires);
  
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
  // (crule (pre) (scan $sup5638x93x0x0x0 __t9rnk262 l m p r u v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t5rXw260) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2wpn261) (join-old mp_union (0 1 2) 3 (0 1 2) __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t2Oaj263) (exists mp_union_ans (0 1) 1 __t2Oaj263) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (exists mp_union_ans (0 1) 1 __t0Kdo264) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask442 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex424;  slog::Index** mp_unionindex425;  slog::Index** mp_unionindex426;  slog::Index** mbranchindex427;  slog::Index** mp_unionindex428;  slog::Index** mbranchindex429;  slog::Index** mp_unionindex430;  slog::Index** mp_unionindex431;  slog::Index** mp_union_ansindex432;  slog::Index** mp_unionindex433;  slog::Index** mp_union_ansindex434;  slog::Index** mp_union_ansindex435;  slog::Index** mp_union_ansindex436;  slog::Index** mbranchdelta437;  slog::Index** mbranchdelta438;  slog::Index** mp_uniondelta439;  slog::Index** mp_uniondelta440;  slog::Index** mp_uniondelta441;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord443({1, 2, 3, 4, 0});
      slog::Relation* readrel444 = db->getRelation("mbranch");
      mbranchindex424 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 2, 0});
      slog::Relation* readrel446 = db->getRelation("mp_union");
      mp_unionindex425 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("mp_union");
      mp_unionindex426 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 2, 3, 4, 0});
      slog::Relation* readrel450 = db->getRelation("mbranch");
      mbranchindex427 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 2, 3, 4, 0});
      slog::Relation* readrel452 = db->getRelation("mbranch");
      mbranchdelta437 = readrel452->getIndex(ord451, true);
      std::vector<u16> ord453({2, 0, 1});
      slog::Relation* readrel454 = db->getRelation("mp_union");
      mp_unionindex428 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 3, 4, 0});
      slog::Relation* readrel456 = db->getRelation("mbranch");
      mbranchindex429 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({1, 2, 3, 4, 0});
      slog::Relation* readrel458 = db->getRelation("mbranch");
      mbranchdelta438 = readrel458->getIndex(ord457, true);
      std::vector<u16> ord459({0, 1, 2});
      slog::Relation* readrel460 = db->getRelation("mp_union");
      mp_unionindex430 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({0, 1, 2});
      slog::Relation* readrel462 = db->getRelation("mp_union");
      mp_uniondelta439 = readrel462->getIndex(ord461, true);
      std::vector<u16> ord463({1, 2, 0});
      slog::Relation* readrel464 = db->getRelation("mp_union");
      mp_unionindex431 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 0});
      slog::Relation* readrel466 = db->getRelation("mp_union");
      mp_uniondelta440 = readrel466->getIndex(ord465, true);
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("mp_union_ans");
      mp_union_ansindex432 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 2, 0});
      slog::Relation* readrel470 = db->getRelation("mp_union");
      mp_unionindex433 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("mp_union");
      mp_uniondelta441 = readrel472->getIndex(ord471, true);
      std::vector<u16> ord473({0, 1});
      slog::Relation* readrel474 = db->getRelation("mp_union_ans");
      mp_union_ansindex434 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("mp_union_ans");
      mp_union_ansindex435 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("mp_union_ans");
      mp_union_ansindex436 = readrel478->getIndex(ord477, false);
  
    }
    ReadTask442(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c18 = _t[5];
        u64 v_c19 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex424, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex425, std::array<u64,3>{v_c12, v_c18, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex426, std::array<u64,3>{v_c17, v_c19, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex427, mbranchdelta437, std::array<u64,5>{v_c15, v_c13, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m479) {
          u64 v_c114 = m479[4];
          if (!slog::exists_probe<3,2>(mp_unionindex428, std::array<u64,3>{v_c114, v_c105, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex429, mbranchdelta438, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m480) {
            u64 v_c115 = m480[4];
            slog::join_probe_old<3,3>(mp_unionindex430, mp_uniondelta439, std::array<u64,3>{v_c105, v_c115, v_c114}, [&](const std::array<u64,3>& m481) {
              slog::join_probe_old<3,2>(mp_unionindex431, mp_uniondelta440, std::array<u64,3>{v_c12, v_c18, 0}, [&](const std::array<u64,3>& m482) {
                u64 v_c116 = m482[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex432, std::array<u64,2>{v_c116, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex433, mp_uniondelta441, std::array<u64,3>{v_c17, v_c19, 0}, [&](const std::array<u64,3>& m483) {
                  u64 v_c117 = m483[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex434, std::array<u64,2>{v_c117, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex435, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m484) {
                    u64 v_c4 = m484[1];
                    slog::join_probe<2,1>(mp_union_ansindex436, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m485) {
                      u64 v_c90 = m485[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c105, v_c4, v_c90, v_c13, v_c15});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c13, v_c4, v_c90}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask442* _cont = new ReadTask442(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask442(db,b), false);
  // (crule (pre (let __tconst0V5A29 const6b86b273ff34fce19d6b804e)) (scan mp_union __t45uF28 __t8PYQ27 __t0FDo26) (body (join mbranch (0 1 2 3 4) 1 __t0FDo26 q n u v) (join mbranch (0 1 2 3 4) 1 __t8PYQ27 p m l r) (cmp lt n m) (let __t1fk230 (band q m)) (cmp lt __t1fk230 __tconst0V5A29)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t45uF28 l m n p q r u v)) map.slog:96 #f)
  class ReadTask488 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex486;  slog::Index** mbranchindex487;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord489({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel490 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel490->getIndex(ord489, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord491({0, 1, 2, 3, 4});
      slog::Relation* readrel492 = db->getRelation("mbranch");
      mbranchindex486 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({0, 1, 2, 3, 4});
      slog::Relation* readrel494 = db->getRelation("mbranch");
      mbranchindex487 = readrel494->getIndex(ord493, false);
  
    }
    ReadTask488(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        slog::join_probe<5,1>(mbranchindex486, std::array<u64,5>{v_c121, 0, 0, 0, 0}, [&](const std::array<u64,5>& m495) {
          u64 v_c16 = m495[1]; u64 v_c14 = m495[2]; u64 v_c18 = m495[3]; u64 v_c19 = m495[4];
          slog::join_probe<5,1>(mbranchindex487, std::array<u64,5>{v_c120, 0, 0, 0, 0}, [&](const std::array<u64,5>& m496) {
            u64 v_c15 = m496[1]; u64 v_c13 = m496[2]; u64 v_c12 = m496[3]; u64 v_c17 = m496[4];
            u64 v_c122 = _prim_lt(db, v_c14, v_c13);
            if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c122) return;
            u64 v_c123 = _prim_band(db, v_c16, v_c13);
            if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c124 = _prim_lt(db, v_c123, v_c118);
            if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c124) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c119, v_c12, v_c13, v_c14, v_c15, v_c16, v_c17, v_c18, v_c19}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask488* _cont = new ReadTask488(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask488(db,b), false);
  // (crule (pre) (scan mp_union __t0Kdo264 r v) (body (exists $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 r v) (exists mbranch (4 0 1 2 3) 1 v) (exists mbranch (4 0 1 2 3) 1 r) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1) (join $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 r v __t9rnk262 l m p u) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (join mbranch (1 2 3 4 0) 4 p m u v __t5rXw260) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (join mbranch (1 2 3 4 0) 4 p m l r __t2wpn261) (join mp_union (0 1 2) 3 __t9rnk262 __t2wpn261 __t5rXw260) (join mp_union (1 2 0) 2 l u __t2Oaj263) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask512 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index499;  slog::Index** mbranchindex500;  slog::Index** mbranchindex501;  slog::Index** mp_union_ansindex502;  slog::Index** $sup5638x93x0x0x0index503;  slog::Index** mbranchindex504;  slog::Index** mp_unionindex505;  slog::Index** mbranchindex506;  slog::Index** mp_unionindex507;  slog::Index** mbranchindex508;  slog::Index** mp_unionindex509;  slog::Index** mp_unionindex510;  slog::Index** mp_union_ansindex511;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord513({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel514 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index499 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({4, 0, 1, 2, 3});
      slog::Relation* readrel516 = db->getRelation("mbranch");
      mbranchindex500 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({4, 0, 1, 2, 3});
      slog::Relation* readrel518 = db->getRelation("mbranch");
      mbranchindex501 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("mp_union_ans");
      mp_union_ansindex502 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel522 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index503 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 2, 3, 4, 0});
      slog::Relation* readrel524 = db->getRelation("mbranch");
      mbranchindex504 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 0});
      slog::Relation* readrel526 = db->getRelation("mp_union");
      mp_unionindex505 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 3, 4, 0});
      slog::Relation* readrel528 = db->getRelation("mbranch");
      mbranchindex506 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({2, 0, 1});
      slog::Relation* readrel530 = db->getRelation("mp_union");
      mp_unionindex507 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 3, 4, 0});
      slog::Relation* readrel532 = db->getRelation("mbranch");
      mbranchindex508 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({0, 1, 2});
      slog::Relation* readrel534 = db->getRelation("mp_union");
      mp_unionindex509 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 0});
      slog::Relation* readrel536 = db->getRelation("mp_union");
      mp_unionindex510 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({0, 1});
      slog::Relation* readrel538 = db->getRelation("mp_union_ans");
      mp_union_ansindex511 = readrel538->getIndex(ord537, false);
  
    }
    ReadTask512(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x93x0x0x0index499, std::array<u64,7>{v_c17, v_c19, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex500, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex501, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex502, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m539) {
          u64 v_c90 = m539[1];
          slog::join_probe<7,2>($sup5638x93x0x0x0index503, std::array<u64,7>{v_c17, v_c19, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m540) {
            u64 v_c105 = m540[2]; u64 v_c12 = m540[3]; u64 v_c13 = m540[4]; u64 v_c15 = m540[5]; u64 v_c18 = m540[6];
            if (!slog::exists_probe<5,4>(mbranchindex504, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex505, std::array<u64,3>{v_c12, v_c18, 0})) return;
            slog::join_probe<5,4>(mbranchindex506, std::array<u64,5>{v_c15, v_c13, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m541) {
              u64 v_c114 = m541[4];
              if (!slog::exists_probe<3,2>(mp_unionindex507, std::array<u64,3>{v_c114, v_c105, 0})) return;
              slog::join_probe<5,4>(mbranchindex508, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m542) {
                u64 v_c115 = m542[4];
                slog::join_probe<3,3>(mp_unionindex509, std::array<u64,3>{v_c105, v_c115, v_c114}, [&](const std::array<u64,3>& m543) {
                  slog::join_probe<3,2>(mp_unionindex510, std::array<u64,3>{v_c12, v_c18, 0}, [&](const std::array<u64,3>& m544) {
                    u64 v_c116 = m544[2];
                    slog::join_probe<2,1>(mp_union_ansindex511, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m545) {
                      u64 v_c4 = m545[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c105, v_c4, v_c90, v_c13, v_c15});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c13, v_c4, v_c90}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask512* _cont = new ReadTask512(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask512(db,b), false);
  // (crule (pre) (scan mp_hsb __t1Rb9367 __t3QgY368) (body (exists mp_hsb_ans (0 1) 1 __t1Rb9367) (join mp_hsb_ans (0 1) 1 __t1Rb9367 __v3) (join mp_hsb_ans (0 1) 1 __t1Rb9367 __v1) (join $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk6gOk1066 (bxor p0 p1)) (eq __t3QgY368 chk6gOk1066)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t1Rb9367 __t1Rb9367 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex546;  slog::Index** mp_hsb_ansindex547;  slog::Index** mp_hsb_ansindex548;  slog::Index** $sup5638x25x0x0x1index549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord551({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel552 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel552->getIndex(ord551, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord553({0, 1});
      slog::Relation* readrel554 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex546 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 1});
      slog::Relation* readrel556 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex547 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1});
      slog::Relation* readrel558 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex548 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel560 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index549 = readrel560->getIndex(ord559, false);
  
    }
    ReadTask550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c92 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex546, std::array<u64,2>{v_c89, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex547, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m561) {
          u64 v_c91 = m561[1];
          slog::join_probe<2,1>(mp_hsb_ansindex548, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m562) {
            u64 v_c90 = m562[1];
            slog::join_all<7>($sup5638x25x0x0x1index549, [&](const std::array<u64,7>& m563) {
              u64 v_c93 = m563[0]; u64 v_c4 = m563[1]; u64 v_c41 = m563[2]; u64 v_c94 = m563[3]; u64 v_c95 = m563[4]; u64 v_c96 = m563[5]; u64 v_c97 = m563[6];
              u64 v_c125 = _prim_bxor(db, v_c94, v_c95);
              if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c92 != v_c125) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c93, v_c4, v_c91, v_c90, v_c41, v_c89, v_c89, v_c94, v_c95, v_c96, v_c97}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask550* _cont = new ReadTask550(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask550(db,b), false);
  // (crule (pre) (scan temp1bhg1089 __t0LEG246) (body) (head (mkstruct mp_hsb (1 0) __7MRK692 __t0LEG246)) map.slog:30 #f)
  class ReadTask564 : public slog::Task
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
      outer_rel = db->getRelation("temp1bhg1089");
  
    }
    ReadTask564(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c126}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp1bhg1089", _fires);
  
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
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join mp_hsb_ans (0 1) 0 __t8mLF130 __v3) (join mp_hsb_ans (0 1) 1 __t8mLF130 __v1) (let __t8nJr131 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8mLF130 __t8nJr131)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t8mLF130 __t8mLF130 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask569 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex565;  slog::Index** mp_hsb_ansindex566;  slog::Index** mp_hsbindex567;  slog::Index** mp_hsbdelta568;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord570({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel571 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel571->getIndex(ord570, false);
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex565 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({0, 1});
      slog::Relation* readrel575 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex566 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("mp_hsb");
      mp_hsbindex567 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0, 1});
      slog::Relation* readrel579 = db->getRelation("mp_hsb");
      mp_hsbdelta568 = readrel579->getIndex(ord578, true);
  
    }
    ReadTask569(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c93 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c94 = _t[3];
        u64 v_c95 = _t[4];
        u64 v_c96 = _t[5];
        u64 v_c97 = _t[6];
        slog::join_all<2>(mp_hsb_ansindex565, [&](const std::array<u64,2>& m580) {
          u64 v_c127 = m580[0]; u64 v_c91 = m580[1];
          slog::join_probe<2,1>(mp_hsb_ansindex566, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m581) {
            u64 v_c90 = m581[1];
            u64 v_c128 = _prim_bxor(db, v_c94, v_c95);
            if (v_c128 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            slog::join_probe_old<2,2>(mp_hsbindex567, mp_hsbdelta568, std::array<u64,2>{v_c127, v_c128}, [&](const std::array<u64,2>& m582) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c93, v_c4, v_c91, v_c90, v_c41, v_c127, v_c127, v_c94, v_c95, v_c96, v_c97}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask569* _cont = new ReadTask569(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask569(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t0xN947 p) (body (exists $sup5638x95x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t0xN947 p) (exists $sup5638x95x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t0xN947 q m) (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mbranch (1 2 3 4 0) 1 q) (join-old $sup5638x95x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t0xN947 m q p __t0mSQ44 l n r u v) (cmp lt n m) (join-old $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 (1 2 4 6 0 3 5 7 8) l m p r __t0mSQ44 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (1 2 0) 1 l) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t39oH43) (exists mp_union (0 1 2) 2 __t0mSQ44 __t39oH43) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t499t48) (join-old mp_union (0 1 2) 3 (0 1 2) __t0mSQ44 __t39oH43 __t499t48) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join-old mp_union_ans (0 1) 1 (0 1) __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index583;  slog::Index** $sup5638x95x0x0x0index584;  slog::Index** mbranchindex585;  slog::Index** mp_mskindex586;  slog::Index** $sup5638x95x0x0x0index587;  slog::Index** mbranchindex588;  slog::Index** mbranchindex589;  slog::Index** $sup5638x95x0x0x1index590;  slog::Index** $sup5638x95x0x0x0index591;  slog::Index** mbranchindex592;  slog::Index** mp_unionindex593;  slog::Index** mbranchindex594;  slog::Index** mp_unionindex595;  slog::Index** mbranchindex596;  slog::Index** mp_unionindex597;  slog::Index** mp_unionindex598;  slog::Index** mp_union_ansindex599;  slog::Index** mp_mskdelta600;  slog::Index** $sup5638x95x0x0x1delta601;  slog::Index** $sup5638x95x0x0x0delta602;  slog::Index** mbranchdelta603;  slog::Index** mbranchdelta604;  slog::Index** mp_uniondelta605;  slog::Index** mp_uniondelta606;  slog::Index** mp_union_ansdelta607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord609({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel610 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index583 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel612 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index584 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 2, 3, 4, 0});
      slog::Relation* readrel614 = db->getRelation("mbranch");
      mbranchindex585 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({0, 1, 2});
      slog::Relation* readrel616 = db->getRelation("mp_msk");
      mp_mskindex586 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({0, 1, 2});
      slog::Relation* readrel618 = db->getRelation("mp_msk");
      mp_mskdelta600 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel620 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index587 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 3, 4, 0});
      slog::Relation* readrel622 = db->getRelation("mbranch");
      mbranchindex588 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 2, 3, 4, 0});
      slog::Relation* readrel624 = db->getRelation("mbranch");
      mbranchindex589 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel626 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index590 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel628 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta601 = readrel628->getIndex(ord627, true);
      std::vector<u16> ord629({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel630 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index591 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel632 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0delta602 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({1, 2, 3, 4, 0});
      slog::Relation* readrel634 = db->getRelation("mbranch");
      mbranchindex592 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({1, 2, 0});
      slog::Relation* readrel636 = db->getRelation("mp_union");
      mp_unionindex593 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 2, 3, 4, 0});
      slog::Relation* readrel638 = db->getRelation("mbranch");
      mbranchindex594 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 2, 3, 4, 0});
      slog::Relation* readrel640 = db->getRelation("mbranch");
      mbranchdelta603 = readrel640->getIndex(ord639, true);
      std::vector<u16> ord641({0, 1, 2});
      slog::Relation* readrel642 = db->getRelation("mp_union");
      mp_unionindex595 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 2, 3, 4, 0});
      slog::Relation* readrel644 = db->getRelation("mbranch");
      mbranchindex596 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 3, 4, 0});
      slog::Relation* readrel646 = db->getRelation("mbranch");
      mbranchdelta604 = readrel646->getIndex(ord645, true);
      std::vector<u16> ord647({0, 1, 2});
      slog::Relation* readrel648 = db->getRelation("mp_union");
      mp_unionindex597 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({0, 1, 2});
      slog::Relation* readrel650 = db->getRelation("mp_union");
      mp_uniondelta605 = readrel650->getIndex(ord649, true);
      std::vector<u16> ord651({1, 2, 0});
      slog::Relation* readrel652 = db->getRelation("mp_union");
      mp_unionindex598 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 0});
      slog::Relation* readrel654 = db->getRelation("mp_union");
      mp_uniondelta606 = readrel654->getIndex(ord653, true);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("mp_union_ans");
      mp_union_ansindex599 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({0, 1});
      slog::Relation* readrel658 = db->getRelation("mp_union_ans");
      mp_union_ansdelta607 = readrel658->getIndex(ord657, true);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c15 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index583, std::array<u64,10>{v_c130, v_c15, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index584, std::array<u64,9>{v_c15, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex585, std::array<u64,5>{v_c15, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex586, mp_mskdelta600, std::array<u64,3>{v_c130, 0, 0}, [&](const std::array<u64,3>& m659) {
          u64 v_c16 = m659[1]; u64 v_c13 = m659[2];
          if (!slog::exists_probe<9,3>($sup5638x95x0x0x0index587, std::array<u64,9>{v_c13, v_c16, v_c15, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex588, std::array<u64,5>{v_c15, v_c13, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex589, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x95x0x0x1index590, $sup5638x95x0x0x1delta601, std::array<u64,10>{v_c130, v_c13, v_c16, v_c15, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m660) {
            u64 v_c131 = m660[4]; u64 v_c12 = m660[5]; u64 v_c14 = m660[6]; u64 v_c17 = m660[7]; u64 v_c18 = m660[8]; u64 v_c19 = m660[9];
            u64 v_c132 = _prim_lt(db, v_c14, v_c13);
            if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c132) return;
            slog::join_probe_old<9,9>($sup5638x95x0x0x0index591, $sup5638x95x0x0x0delta602, std::array<u64,9>{v_c12, v_c13, v_c15, v_c17, v_c131, v_c14, v_c16, v_c18, v_c19}, [&](const std::array<u64,9>& m662) {
              if (!slog::exists_probe<5,4>(mbranchindex592, std::array<u64,5>{v_c16, v_c14, v_c18, v_c19, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex593, std::array<u64,3>{v_c12, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex594, mbranchdelta603, std::array<u64,5>{v_c15, v_c13, v_c12, v_c17, 0}, [&](const std::array<u64,5>& m663) {
                u64 v_c133 = m663[4];
                if (!slog::exists_probe<3,2>(mp_unionindex595, std::array<u64,3>{v_c131, v_c133, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex596, mbranchdelta604, std::array<u64,5>{v_c16, v_c14, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m664) {
                  u64 v_c134 = m664[4];
                  slog::join_probe_old<3,3>(mp_unionindex597, mp_uniondelta605, std::array<u64,3>{v_c131, v_c133, v_c134}, [&](const std::array<u64,3>& m665) {
                    slog::join_probe_old<3,2>(mp_unionindex598, mp_uniondelta606, std::array<u64,3>{v_c12, v_c134, 0}, [&](const std::array<u64,3>& m666) {
                      u64 v_c135 = m666[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex599, mp_union_ansdelta607, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m667) {
                        u64 v_c4 = m667[1];
                        u64 v_c136 = _prim_band(db, v_c16, v_c13);
                        if (v_c136 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c137 = _prim_lt(db, v_c136, v_c129);
                        if (v_c137 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c137) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c131, v_c4, v_c13, v_c15, v_c17});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c13, v_c4, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
}

