
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const3b5b774db59f55c2fdaef73a;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const846f120b6b6ab883fe02a53a;
extern u64 v_const8c1f1046219ddd216a023f79;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_ca0ddd135f242cff4(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp8GS31028 __t2yWY168) (body) (head (mkstruct mp_hsb (1 0) __99RG580 __t2yWY168)) map.slog:26 #f)
  class ReadTask0 : public slog::Task
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
      outer_rel = db->getRelation("temp8GS31028");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp8GS31028", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mp_put __t0ekw284 __t07OG283 k v) (body (exists $sup5638x42x0x0x1 (0 2 7 1 3 4 5 6) 3 __t0ekw284 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put (2 3 0 1) 2 k v) (join $sup5638x42x0x0x0 (0 1 6 2 3 4 5) 3 __t0ekw284 k v l m p r) (exists mbranch (1 2 3 4 0) 5 p m l r __t07OG283) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t0ekw284 k v __t8lnB287) (join mbranch (1 2 3 4 0) 5 p m l r __t07OG283) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t8lnB287) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index1;  slog::Index** mp_mskindex2;  slog::Index** mp_putindex3;  slog::Index** $sup5638x42x0x0x0index4;  slog::Index** mbranchindex5;  slog::Index** mp_mskindex6;  slog::Index** mp_putindex7;  slog::Index** mp_msk_ansindex8;  slog::Index** $sup5638x42x0x0x1index9;  slog::Index** mbranchindex10;  slog::Index** mp_mskindex11;  slog::Index** mp_msk_ansindex12;  slog::Index** mp_putindex13;  slog::Index** mp_msk_ansindex14;  slog::Index** mp_put_ansindex15;  slog::Index** mp_mskdelta16;  slog::Index** mp_putdelta17;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord19({0, 2, 7, 1, 3, 4, 5, 6});
      slog::Relation* readrel20 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("mp_msk");
      mp_mskindex2 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 3, 0, 1});
      slog::Relation* readrel24 = db->getRelation("mp_put");
      mp_putindex3 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1, 6, 2, 3, 4, 5});
      slog::Relation* readrel26 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index4 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 3, 4, 0});
      slog::Relation* readrel28 = db->getRelation("mbranch");
      mbranchindex5 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 2, 0});
      slog::Relation* readrel30 = db->getRelation("mp_msk");
      mp_mskindex6 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 3, 0});
      slog::Relation* readrel32 = db->getRelation("mp_put");
      mp_putindex7 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex8 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel36 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index9 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 3, 4, 0});
      slog::Relation* readrel38 = db->getRelation("mbranch");
      mbranchindex10 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("mp_msk");
      mp_mskindex11 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("mp_msk");
      mp_mskdelta16 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex12 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 3, 0});
      slog::Relation* readrel46 = db->getRelation("mp_put");
      mp_putindex13 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 3, 0});
      slog::Relation* readrel48 = db->getRelation("mp_put");
      mp_putdelta17 = readrel48->getIndex(ord47, true);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex14 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("mp_put_ans");
      mp_put_ansindex15 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c5 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index1, std::array<u64,8>{v_c2, v_c4, v_c5, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex2, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex3, std::array<u64,4>{v_c4, v_c5, 0, 0})) return;
        slog::join_probe<7,3>($sup5638x42x0x0x0index4, std::array<u64,7>{v_c2, v_c4, v_c5, 0, 0, 0, 0}, [&](const std::array<u64,7>& m53) {
          u64 v_c6 = m53[3]; u64 v_c7 = m53[4]; u64 v_c8 = m53[5]; u64 v_c9 = m53[6];
          if (!slog::exists_probe<5,5>(mbranchindex5, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, v_c3})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex6, std::array<u64,3>{v_c4, v_c7, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex7, std::array<u64,4>{v_c9, v_c4, v_c5, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex8, std::array<u64,2>{v_c8, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index9, std::array<u64,8>{v_c6, v_c7, v_c8, v_c9, v_c2, v_c4, v_c5, 0}, [&](const std::array<u64,8>& m54) {
            u64 v_c10 = m54[7];
            slog::join_probe<5,5>(mbranchindex10, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, v_c3}, [&](const std::array<u64,5>& m55) {
              slog::join_probe_old<3,3>(mp_mskindex11, mp_mskdelta16, std::array<u64,3>{v_c4, v_c7, v_c10}, [&](const std::array<u64,3>& m56) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex12, std::array<u64,2>{v_c10, v_c8})) return;
                slog::join_probe_old<4,3>(mp_putindex13, mp_putdelta17, std::array<u64,4>{v_c9, v_c4, v_c5, 0}, [&](const std::array<u64,4>& m57) {
                  u64 v_c11 = m57[3];
                  slog::join_probe<2,2>(mp_msk_ansindex14, std::array<u64,2>{v_c10, v_c8}, [&](const std::array<u64,2>& m58) {
                    slog::join_probe<2,1>(mp_put_ansindex15, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m59) {
                      u64 v_c12 = m59[1];
                      u64 v_c13 = _prim_band(db, v_c4, v_c7);
                      if (v_c13 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c14 = _prim_gt(db, v_c13, v_c1);
                      if (v_c14 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c14) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c2, v_c12, v_c6, v_c7, v_c8});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c6, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask18* _cont = new ReadTask18(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), false);
  // (crule (pre) (scan mbranch __t3xpB250 p m l r) (body (exists mbranch (2 0 1 3 4) 1 m) (join mp_union (1 2 0) 1 __t3xpB250 __t8UiN251 __t1JFT249) (join-old mbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t8UiN251 q u v) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __9uYp581 p __t3xpB250 q __t8UiN251)) map.slog:114 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex61;  slog::Index** mp_unionindex62;  slog::Index** mbranchindex63;  slog::Index** mbranchdelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord66({2, 0, 1, 3, 4});
      slog::Relation* readrel67 = db->getRelation("mbranch");
      mbranchindex61 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("mp_union");
      mp_unionindex62 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({2, 0, 1, 3, 4});
      slog::Relation* readrel71 = db->getRelation("mbranch");
      mbranchindex63 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({2, 0, 1, 3, 4});
      slog::Relation* readrel73 = db->getRelation("mbranch");
      mbranchdelta64 = readrel73->getIndex(ord72, true);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c9 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex61, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(mp_unionindex62, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m74) {
          u64 v_c16 = m74[1]; u64 v_c17 = m74[2];
          slog::join_probe_old<5,2>(mbranchindex63, mbranchdelta64, std::array<u64,5>{v_c7, v_c16, 0, 0, 0}, [&](const std::array<u64,5>& m75) {
            u64 v_c18 = m75[2]; u64 v_c19 = m75[3]; u64 v_c5 = m75[4];
            if (v_c8 == v_c18) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c8, v_c15, v_c18, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre (let __tconst0PwW227 const5feceb66ffc86f38d952786c)) (scan mbranch __t8dlF225 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t8dlF225 k __t22eB226) (let __t6Vmq228 (band k m)) (cmp gt __t6Vmq228 __tconst0PwW227)) (head (emit $sup5638x62x0x0x0 (4 2 3 5 0 1) p l m r __t22eB226 k)) map.slog:63 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index76;  slog::Index** mp_has0delta77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord79({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel80 = db->getRelation("$sup5638x62x0x0x0");
      head_index[0] = readrel80->getIndex(ord79, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("mp_has0");
      mp_has0index76 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 0});
      slog::Relation* readrel84 = db->getRelation("mp_has0");
      mp_has0delta77 = readrel84->getIndex(ord83, true);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index76, mp_has0delta77, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m85) {
          u64 v_c4 = m85[1]; u64 v_c22 = m85[2];
          u64 v_c23 = _prim_band(db, v_c4, v_c7);
          if (v_c23 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          u64 v_c24 = _prim_gt(db, v_c23, v_c20);
          if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          if (!v_c24) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c8, v_c6, v_c7, v_c9, v_c22, v_c4}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre) (scan mp_join_ans __t2ANq21 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t2ANq21 p __t50JB19 q __t6Pc120) (neq p q) (exists mbranch (0 1 2 3 4) 2 __t50JB19 p) (exists mbranch (0 1 2 3 4) 2 __t6Pc120 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t50JB19 __t6Pc120 __t9xCI18) (join-old mbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t50JB19 p m l r) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t6Pc120 q m u v)) (head (emit mp_union_ans (0 1) __t9xCI18 res)) map.slog:114 #f)
  class ReadTask97 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex87;  slog::Index** mbranchindex88;  slog::Index** mbranchindex89;  slog::Index** mp_unionindex90;  slog::Index** mbranchindex91;  slog::Index** mbranchindex92;  slog::Index** mp_joindelta93;  slog::Index** mp_uniondelta94;  slog::Index** mbranchdelta95;  slog::Index** mbranchdelta96;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("mp_union_ans");
      head_index[0] = readrel99->getIndex(ord98, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord100({0, 1, 2, 3, 4});
      slog::Relation* readrel101 = db->getRelation("mp_join");
      mp_joinindex87 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1, 2, 3, 4});
      slog::Relation* readrel103 = db->getRelation("mp_join");
      mp_joindelta93 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({0, 1, 2, 3, 4});
      slog::Relation* readrel105 = db->getRelation("mbranch");
      mbranchindex88 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1, 2, 3, 4});
      slog::Relation* readrel107 = db->getRelation("mbranch");
      mbranchindex89 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("mp_union");
      mp_unionindex90 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("mp_union");
      mp_uniondelta94 = readrel111->getIndex(ord110, true);
      std::vector<u16> ord112({0, 1, 2, 3, 4});
      slog::Relation* readrel113 = db->getRelation("mbranch");
      mbranchindex91 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 1, 2, 3, 4});
      slog::Relation* readrel115 = db->getRelation("mbranch");
      mbranchdelta95 = readrel115->getIndex(ord114, true);
      std::vector<u16> ord116({0, 1, 2, 3, 4});
      slog::Relation* readrel117 = db->getRelation("mbranch");
      mbranchindex92 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({0, 1, 2, 3, 4});
      slog::Relation* readrel119 = db->getRelation("mbranch");
      mbranchdelta96 = readrel119->getIndex(ord118, true);
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex87, mp_joindelta93, std::array<u64,5>{v_c25, 0, 0, 0, 0}, [&](const std::array<u64,5>& m120) {
          u64 v_c8 = m120[1]; u64 v_c27 = m120[2]; u64 v_c18 = m120[3]; u64 v_c28 = m120[4];
          if (v_c8 == v_c18) return;
          if (!slog::exists_probe<5,2>(mbranchindex88, std::array<u64,5>{v_c27, v_c8, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex89, std::array<u64,5>{v_c28, v_c18, 0, 0, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex90, mp_uniondelta94, std::array<u64,3>{v_c27, v_c28, 0}, [&](const std::array<u64,3>& m121) {
            u64 v_c29 = m121[2];
            slog::join_probe_old<5,2>(mbranchindex91, mbranchdelta95, std::array<u64,5>{v_c27, v_c8, 0, 0, 0}, [&](const std::array<u64,5>& m122) {
              u64 v_c7 = m122[2]; u64 v_c6 = m122[3]; u64 v_c9 = m122[4];
              slog::join_probe_old<5,3>(mbranchindex92, mbranchdelta96, std::array<u64,5>{v_c28, v_c18, v_c7, 0, 0}, [&](const std::array<u64,5>& m123) {
                u64 v_c19 = m123[3]; u64 v_c5 = m123[4];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c26}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_join_ans", _fires);
  
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
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x1 __t38nk104 __t3jH2107 l m n p q r u v) (body (cmp lt m n) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t38nk104 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 3 p n __t3jH2107) (exists mp_msk_ans (0 1) 2 __t3jH2107 q) (exists mp_union (2 0 1) 1 u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t9OKP102) (exists mp_union (2 0 1) 2 __t9OKP102 __t38nk104) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_union (0 1 2) 3 (0 1 2) __t38nk104 __t6XhK108 __t9OKP102) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index124;  slog::Index** mbranchindex125;  slog::Index** mp_mskindex126;  slog::Index** mp_msk_ansindex127;  slog::Index** mp_unionindex128;  slog::Index** mbranchindex129;  slog::Index** mp_unionindex130;  slog::Index** mbranchindex131;  slog::Index** mp_unionindex132;  slog::Index** mp_mskindex133;  slog::Index** mp_msk_ansindex134;  slog::Index** mp_unionindex135;  slog::Index** mp_union_ansindex136;  slog::Index** mbranchdelta137;  slog::Index** mbranchdelta138;  slog::Index** mp_uniondelta139;  slog::Index** mp_mskdelta140;  slog::Index** mp_uniondelta141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord143({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel144 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index124 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({1, 2, 3, 4, 0});
      slog::Relation* readrel146 = db->getRelation("mbranch");
      mbranchindex125 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("mp_msk");
      mp_mskindex126 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex127 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 0, 1});
      slog::Relation* readrel152 = db->getRelation("mp_union");
      mp_unionindex128 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 3, 4, 0});
      slog::Relation* readrel154 = db->getRelation("mbranch");
      mbranchindex129 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 3, 4, 0});
      slog::Relation* readrel156 = db->getRelation("mbranch");
      mbranchdelta137 = readrel156->getIndex(ord155, true);
      std::vector<u16> ord157({2, 0, 1});
      slog::Relation* readrel158 = db->getRelation("mp_union");
      mp_unionindex130 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 3, 4, 0});
      slog::Relation* readrel160 = db->getRelation("mbranch");
      mbranchindex131 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 3, 4, 0});
      slog::Relation* readrel162 = db->getRelation("mbranch");
      mbranchdelta138 = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({0, 1, 2});
      slog::Relation* readrel164 = db->getRelation("mp_union");
      mp_unionindex132 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1, 2});
      slog::Relation* readrel166 = db->getRelation("mp_union");
      mp_uniondelta139 = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({1, 2, 0});
      slog::Relation* readrel168 = db->getRelation("mp_msk");
      mp_mskindex133 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("mp_msk");
      mp_mskdelta140 = readrel170->getIndex(ord169, true);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex134 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("mp_union");
      mp_unionindex135 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("mp_union");
      mp_uniondelta141 = readrel176->getIndex(ord175, true);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("mp_union_ans");
      mp_union_ansindex136 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c33 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c18 = _t[6];
        u64 v_c9 = _t[7];
        u64 v_c19 = _t[8];
        u64 v_c5 = _t[9];
        u64 v_c34 = _prim_lt(db, v_c7, v_c33);
        if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
        if (!v_c34) return;
        slog::join_probe<9,9>($sup5638x104x0x0x0index124, std::array<u64,9>{v_c18, v_c33, v_c19, v_c5, v_c31, v_c6, v_c7, v_c8, v_c9}, [&](const std::array<u64,9>& m180) {
          if (!slog::exists_probe<5,4>(mbranchindex125, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex126, std::array<u64,3>{v_c8, v_c33, v_c32})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex127, std::array<u64,2>{v_c32, v_c18})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex128, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex129, mbranchdelta137, std::array<u64,5>{v_c18, v_c33, v_c19, v_c5, 0}, [&](const std::array<u64,5>& m181) {
            u64 v_c35 = m181[4];
            if (!slog::exists_probe<3,2>(mp_unionindex130, std::array<u64,3>{v_c35, v_c31, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex131, mbranchdelta138, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0}, [&](const std::array<u64,5>& m182) {
              u64 v_c36 = m182[4];
              slog::join_probe_old<3,3>(mp_unionindex132, mp_uniondelta139, std::array<u64,3>{v_c31, v_c36, v_c35}, [&](const std::array<u64,3>& m183) {
                slog::join_probe_old<3,3>(mp_mskindex133, mp_mskdelta140, std::array<u64,3>{v_c8, v_c33, v_c32}, [&](const std::array<u64,3>& m184) {
                  slog::join_probe<2,2>(mp_msk_ansindex134, std::array<u64,2>{v_c32, v_c18}, [&](const std::array<u64,2>& m185) {
                    slog::join_probe_old<3,2>(mp_unionindex135, mp_uniondelta141, std::array<u64,3>{v_c36, v_c19, 0}, [&](const std::array<u64,3>& m186) {
                      u64 v_c37 = m186[2];
                      slog::join_probe<2,1>(mp_union_ansindex136, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m187) {
                        u64 v_c12 = m187[1];
                        u64 v_c38 = _prim_band(db, v_c8, v_c33);
                        if (v_c38 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c39 = _prim_lt(db, v_c38, v_c30);
                        if (v_c39 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c39) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c12, v_c33, v_c18, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c18, v_c33, v_c12, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask142* _cont = new ReadTask142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask142(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_del __t5pOj159 l k) (body (exists $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t5pOj159 __v0) (exists mp_bld (3 0 1 2 4) 1 __v0) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __t8KQn154 m p r) (exists mp_bld (1 2 3 4 0) 4 p m __v0 r) (exists mp_del (0 2 1) 2 __t8KQn154 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t85IU153) (exists mp_del (0 2 1) 3 __t8KQn154 k __t85IU153) (join mp_bld (1 2 3 4 0) 4 p m __v0 r __t0Lvo157) (join mp_del (0 2 1) 3 __t8KQn154 k __t85IU153) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join mp_msk (1 2 0) 2 k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask208 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index189;  slog::Index** mbranchindex190;  slog::Index** mp_delindex191;  slog::Index** mp_mskindex192;  slog::Index** mp_del_ansindex193;  slog::Index** mp_bldindex194;  slog::Index** $sup5638x82x0x0x0index195;  slog::Index** mp_bldindex196;  slog::Index** mp_delindex197;  slog::Index** mp_mskindex198;  slog::Index** mp_msk_ansindex199;  slog::Index** mbranchindex200;  slog::Index** mp_delindex201;  slog::Index** mp_bldindex202;  slog::Index** mp_delindex203;  slog::Index** mp_bld_ansindex204;  slog::Index** mp_mskindex205;  slog::Index** mp_msk_ansindex206;  slog::Index** mp_bld_ansindex207;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("mp_del_ans");
      head_index[0] = readrel210->getIndex(ord209, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord211({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel212 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index189 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({3, 0, 1, 2, 4});
      slog::Relation* readrel214 = db->getRelation("mbranch");
      mbranchindex190 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({2, 0, 1});
      slog::Relation* readrel216 = db->getRelation("mp_del");
      mp_delindex191 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("mp_msk");
      mp_mskindex192 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("mp_del_ans");
      mp_del_ansindex193 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({3, 0, 1, 2, 4});
      slog::Relation* readrel222 = db->getRelation("mp_bld");
      mp_bldindex194 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel224 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index195 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 3, 4, 0});
      slog::Relation* readrel226 = db->getRelation("mp_bld");
      mp_bldindex196 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({0, 2, 1});
      slog::Relation* readrel228 = db->getRelation("mp_del");
      mp_delindex197 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("mp_msk");
      mp_mskindex198 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex199 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 3, 4, 0});
      slog::Relation* readrel234 = db->getRelation("mbranch");
      mbranchindex200 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 2, 1});
      slog::Relation* readrel236 = db->getRelation("mp_del");
      mp_delindex201 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 3, 4, 0});
      slog::Relation* readrel238 = db->getRelation("mp_bld");
      mp_bldindex202 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 2, 1});
      slog::Relation* readrel240 = db->getRelation("mp_del");
      mp_delindex203 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex204 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("mp_msk");
      mp_mskindex205 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({0, 1});
      slog::Relation* readrel246 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex206 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex207 = readrel248->getIndex(ord247, false);
  
    }
    ReadTask208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index189, std::array<u64,6>{v_c4, v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex190, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex191, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex192, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex193, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m249) {
          u64 v_c12 = m249[1];
          if (!slog::exists_probe<5,1>(mp_bldindex194, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x82x0x0x0index195, std::array<u64,6>{v_c4, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m250) {
            u64 v_c42 = m250[2]; u64 v_c7 = m250[3]; u64 v_c8 = m250[4]; u64 v_c9 = m250[5];
            if (!slog::exists_probe<5,4>(mp_bldindex196, std::array<u64,5>{v_c8, v_c7, v_c12, v_c9, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex197, std::array<u64,3>{v_c42, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex198, std::array<u64,3>{v_c4, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex199, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe<5,4>(mbranchindex200, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0}, [&](const std::array<u64,5>& m251) {
              u64 v_c43 = m251[4];
              if (!slog::exists_probe<3,3>(mp_delindex201, std::array<u64,3>{v_c42, v_c4, v_c43})) return;
              slog::join_probe<5,4>(mp_bldindex202, std::array<u64,5>{v_c8, v_c7, v_c12, v_c9, 0}, [&](const std::array<u64,5>& m252) {
                u64 v_c44 = m252[4];
                slog::join_probe<3,3>(mp_delindex203, std::array<u64,3>{v_c42, v_c4, v_c43}, [&](const std::array<u64,3>& m253) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex204, std::array<u64,2>{v_c44, 0})) return;
                  slog::join_probe<3,2>(mp_mskindex205, std::array<u64,3>{v_c4, v_c7, 0}, [&](const std::array<u64,3>& m254) {
                    u64 v_c45 = m254[2];
                    slog::join_probe<2,2>(mp_msk_ansindex206, std::array<u64,2>{v_c45, v_c8}, [&](const std::array<u64,2>& m255) {
                      slog::join_probe<2,1>(mp_bld_ansindex207, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m256) {
                        u64 v_c26 = m256[1];
                        u64 v_c46 = _prim_band(db, v_c4, v_c7);
                        if (v_c46 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c47 = _prim_lt(db, v_c46, v_c40);
                        if (v_c47 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c47) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c26}, std::array<u16,2>{0, 1});
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
        ReadTask208* _cont = new ReadTask208(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask208(db,b), false);
  // (crule (pre (let _00024sqc96G8453 constd4735e3a265e16eee03f5971) (let _00024sqc6cPp454 const5feceb66ffc86f38d952786c) (let _00024sqc6W8K455 const6b86b273ff34fce19d6b804e) (let _00024sqc1g9y458 const6b86b273ff34fce19d6b804e) (let _00024sqc9hYP459 const5feceb66ffc86f38d952786c) (let _00024sqc9QOZ460 const6b86b273ff34fce19d6b804e) (let _00024sqc7qLn461 const5feceb66ffc86f38d952786c) (let _00024sqo4y5c466 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t4UIA381 __v1) (body (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo4y5c466 _00024seq0 _00024seq1) (exists $sup5638x127x0x0x0 (0 1 2 3 4 5) 2 _00024seq0 _00024seq1) (join mp_fromlist (1 0) 1 _00024seq1 __t3c2R379) (letp _00024sql6CzH451 (aslst _00024seq0)) (letp k (lref _00024sql6CzH451 _00024sqc6cPp454)) (letp v (lref _00024sql6CzH451 _00024sqc6W8K455)) (letp _00024sql7ZXI456 (aslst _00024seq1)) (let _00024sqn1QVd457 (llen _00024sql7ZXI456)) (cmp ge _00024sqn1QVd457 _00024sqc1g9y458) (let _00024sqp3HUi462 (_0002d _00024sqn1QVd457 _00024sqc7qLn461)) (let xs (lslice _00024sql7ZXI456 _00024sqc9QOZ460 _00024sqp3HUi462)) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 6 k v xs _00024seq0 _00024seq1 __t3c2R379) (exists mp_fromlist (1 0) 1 xs) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) k v __t4UIA381 __v0) (join mp_fromlist_ans (1 0) 1 __v0 __t56xP380) (join mp_fromlist (0 1) 2 __t56xP380 xs) (let chk5yBw1046 (llen _00024sql6CzH451)) (eq _00024sqc96G8453 chk5yBw1046) (letp chk2P5i1047 (lref _00024sql7ZXI456 _00024sqc9hYP459)) (eq _00024seq0 chk2P5i1047)) (head (emit mp_fromlist_ans (1 0) __v1 __t3c2R379)) map.slog:128 #f)
  class ReadTask268 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex258;  slog::Index** $sup5638x127x0x0x0index259;  slog::Index** mp_fromlistindex260;  slog::Index** $sup5638x127x0x0x0index261;  slog::Index** mp_fromlistindex262;  slog::Index** mp_putindex263;  slog::Index** mp_fromlist_ansindex264;  slog::Index** mp_fromlistindex265;  slog::Index** $seq_atdelta266;  slog::Index** mp_putdelta267;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord269({1, 0});
      slog::Relation* readrel270 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel270->getIndex(ord269, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord271({1, 0, 2});
      slog::Relation* readrel272 = db->getRelation("$seq_at");
      $seq_atindex258 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 0, 2});
      slog::Relation* readrel274 = db->getRelation("$seq_at");
      $seq_atdelta266 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel276 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index259 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 0});
      slog::Relation* readrel278 = db->getRelation("mp_fromlist");
      mp_fromlistindex260 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel280 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index261 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 0});
      slog::Relation* readrel282 = db->getRelation("mp_fromlist");
      mp_fromlistindex262 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({2, 3, 0, 1});
      slog::Relation* readrel284 = db->getRelation("mp_put");
      mp_putindex263 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({2, 3, 0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_put");
      mp_putdelta267 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex264 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("mp_fromlist");
      mp_fromlistindex265 = readrel290->getIndex(ord289, false);
  
    }
    ReadTask268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_constd4735e3a265e16eee03f5971;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
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
        u64 v_c57 = _t[1];
        slog::join_probe_old<3,1>($seq_atindex258, $seq_atdelta266, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m291) {
          u64 v_c58 = m291[1]; u64 v_c59 = m291[2];
          if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index259, std::array<u64,6>{v_c58, v_c59, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_fromlistindex260, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m292) {
            u64 v_c60 = m292[1];
            bool ok293 = true;
            u64 v_c61 = _prim_aslst(db, v_c58, &ok293);
            if (!ok293) return;
            bool ok294 = true;
            u64 v_c4 = _prim_lref(db, v_c61, v_c49, &ok294);
            if (!ok294) return;
            bool ok295 = true;
            u64 v_c5 = _prim_lref(db, v_c61, v_c50, &ok295);
            if (!ok295) return;
            bool ok296 = true;
            u64 v_c62 = _prim_aslst(db, v_c59, &ok296);
            if (!ok296) return;
            u64 v_c63 = _prim_llen(db, v_c62);
            if (v_c63 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c64 = _prim_ge(db, v_c63, v_c51);
            if (v_c64 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (!v_c64) return;
            u64 v_c65 = _prim__0002d(db, v_c63, v_c54);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c66 = _prim_lslice(db, v_c62, v_c53, v_c65);
            if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            slog::join_probe<6,6>($sup5638x127x0x0x0index261, std::array<u64,6>{v_c4, v_c5, v_c66, v_c58, v_c59, v_c60}, [&](const std::array<u64,6>& m298) {
              if (!slog::exists_probe<2,1>(mp_fromlistindex262, std::array<u64,2>{v_c66, 0})) return;
              slog::join_probe_old<4,3>(mp_putindex263, mp_putdelta267, std::array<u64,4>{v_c4, v_c5, v_c56, 0}, [&](const std::array<u64,4>& m299) {
                u64 v_c12 = m299[3];
                slog::join_probe<2,1>(mp_fromlist_ansindex264, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m300) {
                  u64 v_c67 = m300[1];
                  slog::join_probe<2,2>(mp_fromlistindex265, std::array<u64,2>{v_c67, v_c66}, [&](const std::array<u64,2>& m301) {
                    u64 v_c68 = _prim_llen(db, v_c61);
                    if (v_c68 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c48 != v_c68) return;
                    bool ok302 = true;
                    u64 v_c69 = _prim_lref(db, v_c62, v_c52, &ok302);
                    if (!ok302) return;
                    if (v_c58 != v_c69) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c60}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask268* _cont = new ReadTask268(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask268(db,b), false);
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9OKP102 q n u v) (body (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 4 u n q v) (exists mp_union (2 0 1) 1 __t9OKP102) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 u) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t38nk104 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t9OKP102 __t38nk104) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t38nk104 l m p r __t3jH2107) (exists mp_msk (1 2 0) 3 p n __t3jH2107) (exists mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_union (0 1 2) 3 (0 1 2) __t38nk104 __t6XhK108 __t9OKP102) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask325 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index303;  slog::Index** mp_unionindex304;  slog::Index** mp_mskindex305;  slog::Index** mp_msk_ansindex306;  slog::Index** mp_unionindex307;  slog::Index** $sup5638x104x0x0x0index308;  slog::Index** mbranchindex309;  slog::Index** mp_unionindex310;  slog::Index** mp_mskindex311;  slog::Index** $sup5638x104x0x0x1index312;  slog::Index** mp_mskindex313;  slog::Index** mp_msk_ansindex314;  slog::Index** mbranchindex315;  slog::Index** mp_unionindex316;  slog::Index** mp_mskindex317;  slog::Index** mp_msk_ansindex318;  slog::Index** mp_unionindex319;  slog::Index** mp_union_ansindex320;  slog::Index** mbranchdelta321;  slog::Index** mp_uniondelta322;  slog::Index** mp_mskdelta323;  slog::Index** mp_uniondelta324;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord326({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel327 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index303 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({2, 0, 1});
      slog::Relation* readrel329 = db->getRelation("mp_union");
      mp_unionindex304 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({2, 0, 1});
      slog::Relation* readrel331 = db->getRelation("mp_msk");
      mp_mskindex305 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0});
      slog::Relation* readrel333 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex306 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({2, 0, 1});
      slog::Relation* readrel335 = db->getRelation("mp_union");
      mp_unionindex307 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel337 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index308 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 3, 4, 0});
      slog::Relation* readrel339 = db->getRelation("mbranch");
      mbranchindex309 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({2, 0, 1});
      slog::Relation* readrel341 = db->getRelation("mp_union");
      mp_unionindex310 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 0});
      slog::Relation* readrel343 = db->getRelation("mp_msk");
      mp_mskindex311 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel345 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index312 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 2, 0});
      slog::Relation* readrel347 = db->getRelation("mp_msk");
      mp_mskindex313 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1});
      slog::Relation* readrel349 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex314 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 3, 4, 0});
      slog::Relation* readrel351 = db->getRelation("mbranch");
      mbranchindex315 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 3, 4, 0});
      slog::Relation* readrel353 = db->getRelation("mbranch");
      mbranchdelta321 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1, 2});
      slog::Relation* readrel355 = db->getRelation("mp_union");
      mp_unionindex316 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1, 2});
      slog::Relation* readrel357 = db->getRelation("mp_union");
      mp_uniondelta322 = readrel357->getIndex(ord356, true);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("mp_msk");
      mp_mskindex317 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 2, 0});
      slog::Relation* readrel361 = db->getRelation("mp_msk");
      mp_mskdelta323 = readrel361->getIndex(ord360, true);
      std::vector<u16> ord362({0, 1});
      slog::Relation* readrel363 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex318 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("mp_union");
      mp_unionindex319 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 2, 0});
      slog::Relation* readrel367 = db->getRelation("mp_union");
      mp_uniondelta324 = readrel367->getIndex(ord366, true);
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("mp_union_ans");
      mp_union_ansindex320 = readrel369->getIndex(ord368, false);
  
    }
    ReadTask325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c19 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x104x0x0x1index303, std::array<u64,10>{v_c19, v_c33, v_c18, v_c5, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex304, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex305, std::array<u64,3>{v_c33, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex306, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex307, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x104x0x0x0index308, std::array<u64,9>{v_c18, v_c33, v_c19, v_c5, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m370) {
          u64 v_c31 = m370[4]; u64 v_c6 = m370[5]; u64 v_c7 = m370[6]; u64 v_c8 = m370[7]; u64 v_c9 = m370[8];
          u64 v_c70 = _prim_lt(db, v_c7, v_c33);
          if (v_c70 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c70) return;
          if (!slog::exists_probe<5,4>(mbranchindex309, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex310, std::array<u64,3>{v_c35, v_c31, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex311, std::array<u64,3>{v_c8, v_c33, 0})) return;
          slog::join_probe<10,9>($sup5638x104x0x0x1index312, std::array<u64,10>{v_c19, v_c33, v_c18, v_c5, v_c31, v_c6, v_c7, v_c8, v_c9, 0}, [&](const std::array<u64,10>& m372) {
            u64 v_c32 = m372[9];
            if (!slog::exists_probe<3,3>(mp_mskindex313, std::array<u64,3>{v_c8, v_c33, v_c32})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex314, std::array<u64,2>{v_c32, v_c18})) return;
            slog::join_probe_old<5,4>(mbranchindex315, mbranchdelta321, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0}, [&](const std::array<u64,5>& m373) {
              u64 v_c36 = m373[4];
              slog::join_probe_old<3,3>(mp_unionindex316, mp_uniondelta322, std::array<u64,3>{v_c31, v_c36, v_c35}, [&](const std::array<u64,3>& m374) {
                slog::join_probe_old<3,3>(mp_mskindex317, mp_mskdelta323, std::array<u64,3>{v_c8, v_c33, v_c32}, [&](const std::array<u64,3>& m375) {
                  slog::join_probe<2,2>(mp_msk_ansindex318, std::array<u64,2>{v_c32, v_c18}, [&](const std::array<u64,2>& m376) {
                    slog::join_probe_old<3,2>(mp_unionindex319, mp_uniondelta324, std::array<u64,3>{v_c36, v_c19, 0}, [&](const std::array<u64,3>& m377) {
                      u64 v_c37 = m377[2];
                      slog::join_probe<2,1>(mp_union_ansindex320, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m378) {
                        u64 v_c12 = m378[1];
                        u64 v_c38 = _prim_band(db, v_c8, v_c33);
                        if (v_c38 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c71 = _prim_lt(db, v_c38, v_c30);
                        if (v_c71 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c71) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c12, v_c33, v_c18, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c18, v_c33, v_c12, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask325* _cont = new ReadTask325(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask325(db,b), false);
  // (crule (pre (let __tconst1avh200 const6b86b273ff34fce19d6b804e) (let __tconst2EOh201 constd4735e3a265e16eee03f5971)) (scan mp_hsb_ans __t3q4d203 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t3q4d203 __t6ICG202) (join-old mp_hsb (0 1) 0 (0 1) __t4c2e199 x) (cmp lt __tconst1avh200 x) (let chk1zcO1087 (_0002f x __tconst2EOh201)) (eq __t6ICG202 chk1zcO1087) (let __t4Iug198 (_0002a __tconst2EOh201 __v0))) (head (emit-temp temp2Hkq1086 __t4Iug198 __t4c2e199)) map.slog:19 #f)
  class ReadTask384 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex380;  slog::Index** mp_hsbindex381;  slog::Index** mp_hsbdelta382;  slog::Index** mp_hsbdelta383;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Hkq1086");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord385({0, 1});
      slog::Relation* readrel386 = db->getRelation("mp_hsb");
      mp_hsbindex380 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("mp_hsb");
      mp_hsbdelta382 = readrel388->getIndex(ord387, true);
      std::vector<u16> ord389({0, 1});
      slog::Relation* readrel390 = db->getRelation("mp_hsb");
      mp_hsbindex381 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("mp_hsb");
      mp_hsbdelta383 = readrel392->getIndex(ord391, true);
  
    }
    ReadTask384(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex380, mp_hsbdelta382, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m393) {
          u64 v_c75 = m393[1];
          slog::join_all_old<2>(mp_hsbindex381, mp_hsbdelta383, [&](const std::array<u64,2>& m394) {
            u64 v_c76 = m394[0]; u64 v_c77 = m394[1];
            u64 v_c78 = _prim_lt(db, v_c72, v_c77);
            if (v_c78 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (!v_c78) return;
            u64 v_c79 = _prim__0002f(db, v_c77, v_c73);
            if (v_c79 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (v_c75 != v_c79) return;
            u64 v_c80 = _prim__0002a(db, v_c73, v_c12);
            if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c80, v_c76});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb_ans", _fires);
  
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
  // (crule (pre (let __tconst1avh200 const6b86b273ff34fce19d6b804e) (let __tconst2EOh201 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t4c2e199 x) (body (cmp lt __tconst1avh200 x) (join mp_hsb_ans (0 1) 0 __t3q4d203 __v0) (let __t6ICG202 (_0002f x __tconst2EOh201)) (join-old mp_hsb (0 1) 2 (0 1) __t3q4d203 __t6ICG202) (let __t4Iug198 (_0002a __tconst2EOh201 __v0))) (head (emit-temp temp2Hkq1086 __t4Iug198 __t4c2e199)) map.slog:19 #f)
  class ReadTask399 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex396;  slog::Index** mp_hsbindex397;  slog::Index** mp_hsbdelta398;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Hkq1086");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex396 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("mp_hsb");
      mp_hsbindex397 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("mp_hsb");
      mp_hsbdelta398 = readrel405->getIndex(ord404, true);
  
    }
    ReadTask399(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c81 = _prim_lt(db, v_c72, v_c77);
        if (v_c81 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        if (!v_c81) return;
        slog::join_all<2>(mp_hsb_ansindex396, [&](const std::array<u64,2>& m407) {
          u64 v_c74 = m407[0]; u64 v_c12 = m407[1];
          u64 v_c75 = _prim__0002f(db, v_c77, v_c73);
          if (v_c75 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex397, mp_hsbdelta398, std::array<u64,2>{v_c74, v_c75}, [&](const std::array<u64,2>& m408) {
            u64 v_c80 = _prim__0002a(db, v_c73, v_c12);
            if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c80, v_c76});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask399* _cont = new ReadTask399(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask399(db,b), false);
  // (crule (pre) (scan mp_join __t7wmB418 p0 t0 p1 t1) (body) (head (emit $sup5638x25x0x0x0 (1 0 2 3 4) p0 __t7wmB418 p1 t0 t1)) map.slog:26 #f)
  class ReadTask409 : public slog::Task
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
      std::vector<u16> ord410({1, 0, 2, 3, 4});
      slog::Relation* readrel411 = db->getRelation("$sup5638x25x0x0x0");
      head_index[0] = readrel411->getIndex(ord410, false);
      outer_rel = db->getRelation("mp_join");
  
    }
    ReadTask409(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[1];
        u64 v_c84 = _t[2];
        u64 v_c85 = _t[3];
        u64 v_c86 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c83, v_c82, v_c85, v_c84, v_c86}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask409* _cont = new ReadTask409(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask409(db,b), false);
  // (crule (pre) (scan mp_union __t9xCI18 __t50JB19 __t6Pc120) (body (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t50JB19 __t6Pc120 __t2ANq21 p q) (neq p q) (exists mbranch (0 1 2 3 4) 2 __t6Pc120 q) (exists mp_join_ans (0 1) 1 __t2ANq21) (join-old mbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t50JB19 p m l r) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t6Pc120 q m u v) (join mp_join_ans (0 1) 1 __t2ANq21 res)) (head (emit mp_union_ans (0 1) __t9xCI18 res)) map.slog:114 #f)
  class ReadTask421 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex412;  slog::Index** mbranchindex413;  slog::Index** mp_join_ansindex414;  slog::Index** mbranchindex415;  slog::Index** mbranchindex416;  slog::Index** mp_join_ansindex417;  slog::Index** mp_joindelta418;  slog::Index** mbranchdelta419;  slog::Index** mbranchdelta420;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("mp_union_ans");
      head_index[0] = readrel423->getIndex(ord422, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord424({2, 4, 0, 1, 3});
      slog::Relation* readrel425 = db->getRelation("mp_join");
      mp_joinindex412 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({2, 4, 0, 1, 3});
      slog::Relation* readrel427 = db->getRelation("mp_join");
      mp_joindelta418 = readrel427->getIndex(ord426, true);
      std::vector<u16> ord428({0, 1, 2, 3, 4});
      slog::Relation* readrel429 = db->getRelation("mbranch");
      mbranchindex413 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("mp_join_ans");
      mp_join_ansindex414 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 1, 2, 3, 4});
      slog::Relation* readrel433 = db->getRelation("mbranch");
      mbranchindex415 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({0, 1, 2, 3, 4});
      slog::Relation* readrel435 = db->getRelation("mbranch");
      mbranchdelta419 = readrel435->getIndex(ord434, true);
      std::vector<u16> ord436({0, 1, 2, 3, 4});
      slog::Relation* readrel437 = db->getRelation("mbranch");
      mbranchindex416 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 1, 2, 3, 4});
      slog::Relation* readrel439 = db->getRelation("mbranch");
      mbranchdelta420 = readrel439->getIndex(ord438, true);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("mp_join_ans");
      mp_join_ansindex417 = readrel441->getIndex(ord440, false);
  
    }
    ReadTask421(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        slog::join_probe_old<5,2>(mp_joinindex412, mp_joindelta418, std::array<u64,5>{v_c27, v_c28, 0, 0, 0}, [&](const std::array<u64,5>& m442) {
          u64 v_c25 = m442[2]; u64 v_c8 = m442[3]; u64 v_c18 = m442[4];
          if (v_c8 == v_c18) return;
          if (!slog::exists_probe<5,2>(mbranchindex413, std::array<u64,5>{v_c28, v_c18, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex414, std::array<u64,2>{v_c25, 0})) return;
          slog::join_probe_old<5,2>(mbranchindex415, mbranchdelta419, std::array<u64,5>{v_c27, v_c8, 0, 0, 0}, [&](const std::array<u64,5>& m443) {
            u64 v_c7 = m443[2]; u64 v_c6 = m443[3]; u64 v_c9 = m443[4];
            slog::join_probe_old<5,3>(mbranchindex416, mbranchdelta420, std::array<u64,5>{v_c28, v_c18, v_c7, 0, 0}, [&](const std::array<u64,5>& m444) {
              u64 v_c19 = m444[3]; u64 v_c5 = m444[4];
              slog::join_probe<2,1>(mp_join_ansindex417, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m445) {
                u64 v_c26 = m445[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c26}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask421* _cont = new ReadTask421(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask421(db,b), false);
  // (crule (pre) (scan mleaf __t7TCq240 k v) (body (exists mp_union (1 2 0) 1 __t7TCq240) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) k v __t3dD4242 t) (exists mp_put_ans (0 1) 1 __t3dD4242) (join-old mp_union (1 2 0) 2 (1 2 0) __t7TCq240 t __t9sO9241) (join mp_put_ans (0 1) 1 __t3dD4242 r)) (head (emit mp_union_ans (0 1) __t9sO9241 r)) map.slog:92 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex446;  slog::Index** mp_putindex447;  slog::Index** mp_put_ansindex448;  slog::Index** mp_unionindex449;  slog::Index** mp_put_ansindex450;  slog::Index** mp_putdelta451;  slog::Index** mp_uniondelta452;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("mp_union_ans");
      head_index[0] = readrel455->getIndex(ord454, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("mp_union");
      mp_unionindex446 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({2, 3, 0, 1});
      slog::Relation* readrel459 = db->getRelation("mp_put");
      mp_putindex447 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({2, 3, 0, 1});
      slog::Relation* readrel461 = db->getRelation("mp_put");
      mp_putdelta451 = readrel461->getIndex(ord460, true);
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("mp_put_ans");
      mp_put_ansindex448 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("mp_union");
      mp_unionindex449 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("mp_union");
      mp_uniondelta452 = readrel467->getIndex(ord466, true);
      std::vector<u16> ord468({0, 1});
      slog::Relation* readrel469 = db->getRelation("mp_put_ans");
      mp_put_ansindex450 = readrel469->getIndex(ord468, false);
  
    }
    ReadTask453(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex446, std::array<u64,3>{v_c87, 0, 0})) return;
        slog::join_probe_old<4,2>(mp_putindex447, mp_putdelta451, std::array<u64,4>{v_c4, v_c5, 0, 0}, [&](const std::array<u64,4>& m470) {
          u64 v_c88 = m470[2]; u64 v_c89 = m470[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex448, std::array<u64,2>{v_c88, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex449, mp_uniondelta452, std::array<u64,3>{v_c87, v_c89, 0}, [&](const std::array<u64,3>& m471) {
            u64 v_c90 = m471[2];
            slog::join_probe<2,1>(mp_put_ansindex450, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m472) {
              u64 v_c9 = m472[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c90, v_c9}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask453* _cont = new ReadTask453(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask453(db,b), false);
  // (crule (pre (let __trid80V6817 const846f120b6b6ab883fe02a53a) (let __trel2pzg818 const3a655602588fe6d8c59d4a5a) (let __tcol5JyR819 const5feceb66ffc86f38d952786c) (let __trel2A7n820 const3a655602588fe6d8c59d4a5a) (let __tcol26x9821 const6b86b273ff34fce19d6b804e)) (scan $sup5638x68x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid80V6817 __trel2pzg818 __tcol5JyR819 (1 2 3 4 0)) (tycheck k (accept int) __trid80V6817 __trel2A7n820 __tcol26x9821 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __7t1i816 t k)) map.slog:69 #f)
  class ReadTask476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid474;  u32 sid473;  u32 sid475;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      sid474 = db->getRelation("_enum")->getStructId();
      sid473 = db->getRelation("mbranch")->getStructId();
      sid475 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const846f120b6b6ab883fe02a53a;
      u64 v_c92 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c96 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c89 = _t[2];
        u64 v_c5 = _t[3];
        ++_fires;
        if (!((is_struct(v_c89) && (decode_struct_id(v_c89) == sid473 || decode_struct_id(v_c89) == sid474 || decode_struct_id(v_c89) == sid475))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c91, v_c92, v_c93, v_c89}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c91, v_c94, v_c95, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c89, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask476* _cont = new ReadTask476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask476(db,b), false);
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t1P9g83 __v1) (body (exists mp_put (1 2 3 0) 3 __v1 __tconst2ARJ85 __tconst4DUy84) (exists mp_put (2 3 0 1) 2 __tconst1tgO78 __tconst3k9477) (exists _enum (1 0) 1 __tconst03sd851) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst35sq82 __tconst2cGK81 __t1P9g83 __v0) (exists mp_put_ans (1 0) 1 __v0) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __v1 __tconst2ARJ85 __tconst4DUy84 __t9RS986) (exists mp_put_ans (0 1) 1 __t9RS986) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (join mp_put_ans (0 1) 2 __t0yI380 __v0) (join-old mp_put_ans (0 1) 1 (0 1) __t9RS986 r)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask492 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex477;  slog::Index** mp_putindex478;  slog::Index** _enumindex479;  slog::Index** mp_putindex480;  slog::Index** mp_put_ansindex481;  slog::Index** mp_putindex482;  slog::Index** mp_put_ansindex483;  slog::Index** mp_putindex484;  slog::Index** _enumindex485;  slog::Index** mp_put_ansindex486;  slog::Index** mp_put_ansindex487;  slog::Index** mp_putdelta488;  slog::Index** mp_putdelta489;  slog::Index** mp_putdelta490;  slog::Index** mp_put_ansdelta491;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord493({0});
      slog::Relation* readrel494 = db->getRelation("canon");
      head_index[0] = readrel494->getIndex(ord493, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord495({1, 2, 3, 0});
      slog::Relation* readrel496 = db->getRelation("mp_put");
      mp_putindex477 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({2, 3, 0, 1});
      slog::Relation* readrel498 = db->getRelation("mp_put");
      mp_putindex478 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 0});
      slog::Relation* readrel500 = db->getRelation("_enum");
      _enumindex479 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({2, 3, 0, 1});
      slog::Relation* readrel502 = db->getRelation("mp_put");
      mp_putindex480 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({2, 3, 0, 1});
      slog::Relation* readrel504 = db->getRelation("mp_put");
      mp_putdelta488 = readrel504->getIndex(ord503, true);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("mp_put_ans");
      mp_put_ansindex481 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 2, 3, 0});
      slog::Relation* readrel508 = db->getRelation("mp_put");
      mp_putindex482 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 3, 0});
      slog::Relation* readrel510 = db->getRelation("mp_put");
      mp_putdelta489 = readrel510->getIndex(ord509, true);
      std::vector<u16> ord511({0, 1});
      slog::Relation* readrel512 = db->getRelation("mp_put_ans");
      mp_put_ansindex483 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({2, 3, 0, 1});
      slog::Relation* readrel514 = db->getRelation("mp_put");
      mp_putindex484 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({2, 3, 0, 1});
      slog::Relation* readrel516 = db->getRelation("mp_put");
      mp_putdelta490 = readrel516->getIndex(ord515, true);
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("_enum");
      _enumindex485 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("mp_put_ans");
      mp_put_ansindex486 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 1});
      slog::Relation* readrel522 = db->getRelation("mp_put_ans");
      mp_put_ansindex487 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1});
      slog::Relation* readrel524 = db->getRelation("mp_put_ans");
      mp_put_ansdelta491 = readrel524->getIndex(ord523, true);
  
    }
    ReadTask492(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_constd01925b37634a1a9d24159d8;
      u64 v_c98 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c99 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c100 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c101 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c102 = v_const4a44dc15364204a80fe80e90;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c104 = _t[0];
        u64 v_c57 = _t[1];
        if (!slog::exists_probe<4,3>(mp_putindex477, std::array<u64,4>{v_c57, v_c103, v_c102, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex478, std::array<u64,4>{v_c99, v_c98, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex479, std::array<u64,2>{v_c97, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex480, mp_putdelta488, std::array<u64,4>{v_c101, v_c100, v_c104, 0}, [&](const std::array<u64,4>& m525) {
          u64 v_c12 = m525[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex481, std::array<u64,2>{v_c12, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex482, mp_putdelta489, std::array<u64,4>{v_c57, v_c103, v_c102, 0}, [&](const std::array<u64,4>& m526) {
            u64 v_c105 = m526[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex483, std::array<u64,2>{v_c105, 0})) return;
            slog::join_probe_old<4,2>(mp_putindex484, mp_putdelta490, std::array<u64,4>{v_c99, v_c98, 0, 0}, [&](const std::array<u64,4>& m527) {
              u64 v_c106 = m527[2]; u64 v_c107 = m527[3];
              slog::join_probe<2,2>(_enumindex485, std::array<u64,2>{v_c107, v_c97}, [&](const std::array<u64,2>& m528) {
                slog::join_probe<2,2>(mp_put_ansindex486, std::array<u64,2>{v_c106, v_c12}, [&](const std::array<u64,2>& m529) {
                  slog::join_probe_old<2,1>(mp_put_ansindex487, mp_put_ansdelta491, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m530) {
                    u64 v_c9 = m530[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask492* _cont = new ReadTask492(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask492(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t6JeD58 p0 __v1) (body (exists mp_hsb_ans (1 0) 1 __v1) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x25x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join mp_msk_ans (0 1) 1 __t6JeD58 __v2) (join mp_hsb_ans (1 0) 1 __v1 __t2bXu55) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t2bXu55) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t2bXu55) (exists mp_hsb_ans (0 1) 1 __t2bXu55) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v3) (join $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t2bXu55 __v1 __v3 p0 __t6Puw51 dup3kne1056 dup92Cz1057 __v0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join mp_hsb_ans (0 1) 2 __t2bXu55 __v0) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex531;  slog::Index** $sup5638x25x0x0x2index532;  slog::Index** $sup5638x25x0x0x1index533;  slog::Index** $sup5638x25x0x0x0index534;  slog::Index** mp_joinindex535;  slog::Index** mp_msk_ansindex536;  slog::Index** mp_hsb_ansindex537;  slog::Index** $sup5638x25x0x0x2index538;  slog::Index** $sup5638x25x0x0x1index539;  slog::Index** mp_hsb_ansindex540;  slog::Index** mp_hsb_ansindex541;  slog::Index** $sup5638x25x0x0x2index542;  slog::Index** $sup5638x25x0x0x1index543;  slog::Index** $sup5638x25x0x0x0index544;  slog::Index** mp_joinindex545;  slog::Index** mp_hsb_ansindex546;  slog::Index** mp_hsbindex547;  slog::Index** mp_joindelta548;  slog::Index** mp_hsbdelta549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord551({1, 0});
      slog::Relation* readrel552 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex531 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel554 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index532 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel556 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index533 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({1, 0, 2, 3, 4});
      slog::Relation* readrel558 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index534 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 2, 3, 4, 0});
      slog::Relation* readrel560 = db->getRelation("mp_join");
      mp_joinindex535 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex536 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 0});
      slog::Relation* readrel564 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex537 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel566 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index538 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel568 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index539 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({0, 1});
      slog::Relation* readrel570 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex540 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex541 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel574 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index542 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel576 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index543 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 0, 2, 3, 4});
      slog::Relation* readrel578 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index544 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 3, 4, 0});
      slog::Relation* readrel580 = db->getRelation("mp_join");
      mp_joinindex545 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 3, 4, 0});
      slog::Relation* readrel582 = db->getRelation("mp_join");
      mp_joindelta548 = readrel582->getIndex(ord581, true);
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex546 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("mp_hsb");
      mp_hsbindex547 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("mp_hsb");
      mp_hsbdelta549 = readrel588->getIndex(ord587, true);
  
    }
    ReadTask550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c83 = _t[1];
        u64 v_c57 = _t[2];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex531, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index532, std::array<u64,11>{v_c57, v_c83, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index533, std::array<u64,7>{v_c83, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup5638x25x0x0x0index534, std::array<u64,5>{v_c83, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex535, std::array<u64,5>{v_c83, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex536, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m589) {
          u64 v_c110 = m589[1];
          slog::join_probe<2,1>(mp_hsb_ansindex537, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m590) {
            u64 v_c111 = m590[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index538, std::array<u64,11>{v_c57, v_c83, v_c111, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index539, std::array<u64,7>{v_c83, v_c111, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex540, std::array<u64,2>{v_c111, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex541, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m591) {
              u64 v_c112 = m591[1];
              slog::join_probe<11,4>($sup5638x25x0x0x2index542, std::array<u64,11>{v_c111, v_c57, v_c112, v_c83, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m592) {
                u64 v_c113 = m592[4]; u64 v_c114 = m592[5]; u64 v_c115 = m592[6]; u64 v_c12 = m592[7]; u64 v_c85 = m592[8]; u64 v_c84 = m592[9]; u64 v_c86 = m592[10];
                if (v_c111 != v_c115) return;
                if (v_c111 != v_c114) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index543, std::array<u64,7>{v_c113, v_c83, v_c85, v_c84, v_c86, v_c111, v_c12}, [&](const std::array<u64,7>& m593) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index544, std::array<u64,5>{v_c83, v_c113, v_c85, v_c84, v_c86}, [&](const std::array<u64,5>& m594) {
                    slog::join_probe_old<5,5>(mp_joinindex545, mp_joindelta548, std::array<u64,5>{v_c83, v_c84, v_c85, v_c86, v_c113}, [&](const std::array<u64,5>& m595) {
                      slog::join_probe<2,2>(mp_hsb_ansindex546, std::array<u64,2>{v_c111, v_c12}, [&](const std::array<u64,2>& m596) {
                        u64 v_c116 = _prim_bxor(db, v_c83, v_c85);
                        if (v_c116 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex547, mp_hsbdelta549, std::array<u64,2>{v_c111, v_c116}, [&](const std::array<u64,2>& m597) {
                          u64 v_c117 = _prim_band(db, v_c83, v_c12);
                          if (v_c117 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c118 = _prim_lt(db, v_c117, v_c108);
                          if (v_c118 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c118) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c113, v_c110, v_c112, v_c84, v_c86});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c112, v_c84, v_c86}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst0j5f331 const6b86b273ff34fce19d6b804e)) (scan mbranch __t5kZo329 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t5kZo329 k __t3IIE330) (let __t1GZO332 (band k m)) (cmp lt __t1GZO332 __tconst0j5f331)) (head (emit $sup5638x60x0x0x0 (4 2 3 5 0 1) p l m r __t3IIE330 k)) map.slog:61 #f)
  class ReadTask601 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index599;  slog::Index** mp_has0delta600;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord602({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel603 = db->getRelation("$sup5638x60x0x0x0");
      head_index[0] = readrel603->getIndex(ord602, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord604({1, 2, 0});
      slog::Relation* readrel605 = db->getRelation("mp_has0");
      mp_has0index599 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 2, 0});
      slog::Relation* readrel607 = db->getRelation("mp_has0");
      mp_has0delta600 = readrel607->getIndex(ord606, true);
  
    }
    ReadTask601(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c120 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index599, mp_has0delta600, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m608) {
          u64 v_c4 = m608[1]; u64 v_c121 = m608[2];
          u64 v_c122 = _prim_band(db, v_c4, v_c7);
          if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          u64 v_c123 = _prim_lt(db, v_c122, v_c119);
          if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          if (!v_c123) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c8, v_c6, v_c7, v_c9, v_c121, v_c4}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask601* _cont = new ReadTask601(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask601(db,b), false);
  // (crule (pre) (scan temp7FV11078 l m p r v) (body (join mbranch (1 2 3 4 0) 4 p m l r __t6sdQ66)) (head (mkstruct mp_union (1 2 0) __5jkz694 __t6sdQ66 v)) map.slog:108 #f)
  class ReadTask611 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex610;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp7FV11078");
      std::vector<u16> ord612({1, 2, 3, 4, 0});
      slog::Relation* readrel613 = db->getRelation("mbranch");
      mbranchindex610 = readrel613->getIndex(ord612, false);
  
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
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<5,4>(mbranchindex610, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, 0}, [&](const std::array<u64,5>& m614) {
          u64 v_c124 = m614[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c124, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:temp7FV11078", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre7BEl993 __errf5ACZ994 __errf8z3R995 __errf4S4P996) (body) (head (emit error (0) __erre7BEl993)) <internal>:1 #f)
  class ReadTask615 : public slog::Task
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
      std::vector<u16> ord616({0});
      slog::Relation* readrel617 = db->getRelation("error");
      head_index[0] = readrel617->getIndex(ord616, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask615(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[1];
        u64 v_c127 = _t[2];
        u64 v_c128 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c125}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask615* _cont = new ReadTask615(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask615(db,b), false);
  // (crule (pre (let __trid18PQ549 const3b5b774db59f55c2fdaef73a) (let __trel5qEe550 const3a655602588fe6d8c59d4a5a) (let __tcol45Hq551 const5feceb66ffc86f38d952786c) (let __trel45i0552 const3a655602588fe6d8c59d4a5a) (let __tcol0QB6553 const6b86b273ff34fce19d6b804e)) (scan $sup5638x62x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid18PQ549 __trel5qEe550 __tcol45Hq551 (1 2 3 4 0)) (tycheck k (accept int) __trid18PQ549 __trel45i0552 __tcol0QB6553 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __7eTz548 r k)) map.slog:63 #f)
  class ReadTask621 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid619;  u32 sid618;  u32 sid620;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
      sid619 = db->getRelation("_enum")->getStructId();
      sid618 = db->getRelation("mbranch")->getStructId();
      sid620 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask621(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c129 = v_const3b5b774db59f55c2fdaef73a;
      u64 v_c130 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c131 = v_const5feceb66ffc86f38d952786c;
      u64 v_c132 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c133 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c96 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c9 = _t[5];
        ++_fires;
        if (!((is_struct(v_c9) && (decode_struct_id(v_c9) == sid618 || decode_struct_id(v_c9) == sid619 || decode_struct_id(v_c9) == sid620))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c129, v_c130, v_c131, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c129, v_c132, v_c133, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c9, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask621* _cont = new ReadTask621(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask621(db,b), false);
  // (crule (pre (let __tconst03XK425 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x0 __d0 p0 p1 t0 t1) (body (join-old mp_hsb_ans (0 1) 0 (0 1) __t63mh424 __v0) (let __t5o85423 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t63mh424 __t5o85423) (let __t2zZo426 (band p0 __v0)) (cmp gt __t2zZo426 __tconst03XK425)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t63mh424 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask626 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex622;  slog::Index** mp_hsbindex623;  slog::Index** mp_hsb_ansdelta624;  slog::Index** mp_hsbdelta625;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord627({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel628 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel628->getIndex(ord627, false);
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex622 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({0, 1});
      slog::Relation* readrel632 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta624 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({0, 1});
      slog::Relation* readrel634 = db->getRelation("mp_hsb");
      mp_hsbindex623 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("mp_hsb");
      mp_hsbdelta625 = readrel636->getIndex(ord635, true);
  
    }
    ReadTask626(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c84 = _t[3];
        u64 v_c86 = _t[4];
        slog::join_all_old<2>(mp_hsb_ansindex622, mp_hsb_ansdelta624, [&](const std::array<u64,2>& m637) {
          u64 v_c135 = m637[0]; u64 v_c12 = m637[1];
          u64 v_c136 = _prim_bxor(db, v_c83, v_c85);
          if (v_c136 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex623, mp_hsbdelta625, std::array<u64,2>{v_c135, v_c136}, [&](const std::array<u64,2>& m638) {
            u64 v_c137 = _prim_band(db, v_c83, v_c12);
            if (v_c137 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c138 = _prim_gt(db, v_c137, v_c134);
            if (v_c138 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c138) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c135, v_c12, v_c96, v_c83, v_c85, v_c84, v_c86}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask626* _cont = new ReadTask626(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask626(db,b), false);
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst35sq82 __tconst2cGK81 __t1P9g83 __v0) (body (exists _enum (1 0) 1 __tconst03sd851) (exists mp_put_ans (1 0) 1 __v0) (exists mp_put (2 3 0 1) 2 __tconst2ARJ85 __tconst4DUy84) (exists mp_put_ans (0 1) 1 __t1P9g83) (join mp_put (2 3 0 1) 2 __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (join mp_put_ans (0 1) 2 __t0yI380 __v0) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst2ARJ85 __tconst4DUy84 __t9RS986 __v1) (join mp_put_ans (0 1) 2 __t1P9g83 __v1) (join mp_put_ans (0 1) 1 __t9RS986 r)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask651 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex640;  slog::Index** mp_put_ansindex641;  slog::Index** mp_putindex642;  slog::Index** mp_put_ansindex643;  slog::Index** mp_putindex644;  slog::Index** _enumindex645;  slog::Index** mp_put_ansindex646;  slog::Index** mp_putindex647;  slog::Index** mp_put_ansindex648;  slog::Index** mp_put_ansindex649;  slog::Index** mp_putdelta650;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord652({0});
      slog::Relation* readrel653 = db->getRelation("canon");
      head_index[0] = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({2, 3, 0, 1});
      slog::Relation* readrel655 = db->getRelation("mp_put");
      driver_index = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 0});
      slog::Relation* readrel657 = db->getRelation("_enum");
      _enumindex640 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 0});
      slog::Relation* readrel659 = db->getRelation("mp_put_ans");
      mp_put_ansindex641 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({2, 3, 0, 1});
      slog::Relation* readrel661 = db->getRelation("mp_put");
      mp_putindex642 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("mp_put_ans");
      mp_put_ansindex643 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({2, 3, 0, 1});
      slog::Relation* readrel665 = db->getRelation("mp_put");
      mp_putindex644 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("_enum");
      _enumindex645 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("mp_put_ans");
      mp_put_ansindex646 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({2, 3, 0, 1});
      slog::Relation* readrel671 = db->getRelation("mp_put");
      mp_putindex647 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({2, 3, 0, 1});
      slog::Relation* readrel673 = db->getRelation("mp_put");
      mp_putdelta650 = readrel673->getIndex(ord672, true);
      std::vector<u16> ord674({0, 1});
      slog::Relation* readrel675 = db->getRelation("mp_put_ans");
      mp_put_ansindex648 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({0, 1});
      slog::Relation* readrel677 = db->getRelation("mp_put_ans");
      mp_put_ansindex649 = readrel677->getIndex(ord676, false);
  
    }
    ReadTask651(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_constd01925b37634a1a9d24159d8;
      u64 v_c98 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c99 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c100 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c101 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c102 = v_const4a44dc15364204a80fe80e90;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c101, v_c100, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m678) {
        u64 v_c104 = m678[2];
        u64 v_c12 = m678[3];
        if (buckethash(v_c104) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex640, std::array<u64,2>{v_c97, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex641, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex642, std::array<u64,4>{v_c103, v_c102, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex643, std::array<u64,2>{v_c104, 0})) return;
        slog::join_probe<4,2>(mp_putindex644, std::array<u64,4>{v_c99, v_c98, 0, 0}, [&](const std::array<u64,4>& m679) {
          u64 v_c106 = m679[2]; u64 v_c107 = m679[3];
          slog::join_probe<2,2>(_enumindex645, std::array<u64,2>{v_c107, v_c97}, [&](const std::array<u64,2>& m680) {
            slog::join_probe<2,2>(mp_put_ansindex646, std::array<u64,2>{v_c106, v_c12}, [&](const std::array<u64,2>& m681) {
              slog::join_probe_old<4,2>(mp_putindex647, mp_putdelta650, std::array<u64,4>{v_c103, v_c102, 0, 0}, [&](const std::array<u64,4>& m682) {
                u64 v_c105 = m682[2]; u64 v_c57 = m682[3];
                slog::join_probe<2,2>(mp_put_ansindex648, std::array<u64,2>{v_c104, v_c57}, [&](const std::array<u64,2>& m683) {
                  slog::join_probe<2,1>(mp_put_ansindex649, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m684) {
                    u64 v_c9 = m684[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask651* _cont = new ReadTask651(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask651(db,b), false);
  // (crule (pre) (scan temp4kFO1073 __t1I5N72 __v0 m p r) (body (join mbranch (1 2 3 4 0) 4 p m __v0 r __t4uw870)) (head (emit mp_put_ans (0 1) __t1I5N72 __t4uw870)) map.slog:41 #f)
  class ReadTask686 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex685;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("mp_put_ans");
      head_index[0] = readrel688->getIndex(ord687, false);
      outer_rel = db->getRelation("temp4kFO1073");
      std::vector<u16> ord689({1, 2, 3, 4, 0});
      slog::Relation* readrel690 = db->getRelation("mbranch");
      mbranchindex685 = readrel690->getIndex(ord689, false);
  
    }
    ReadTask686(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe<5,4>(mbranchindex685, std::array<u64,5>{v_c8, v_c7, v_c12, v_c9, 0}, [&](const std::array<u64,5>& m691) {
          u64 v_c140 = m691[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c140}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:temp4kFO1073", _fires);
  
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
  // (crule (pre (let _00024sqc96G8453 constd4735e3a265e16eee03f5971) (let _00024sqc6cPp454 const5feceb66ffc86f38d952786c) (let _00024sqc6W8K455 const6b86b273ff34fce19d6b804e) (let _00024sqc1g9y458 const6b86b273ff34fce19d6b804e) (let _00024sqc9hYP459 const5feceb66ffc86f38d952786c) (let _00024sqc9QOZ460 const6b86b273ff34fce19d6b804e) (let _00024sqc7qLn461 const5feceb66ffc86f38d952786c) (let _00024sqo4y5c466 const5feceb66ffc86f38d952786c)) (scan mp_fromlist_ans __t56xP380 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo4y5c466) (exists mp_put (1 2 0 3) 1 __v0) (join mp_fromlist (0 1) 1 __t56xP380 xs) (exists $sup5638x127x0x0x0 (5 0 1 2 3 4) 1 xs) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo4y5c466 _00024seq0 _00024seq1) (letp _00024sql6CzH451 (aslst _00024seq0)) (letp k (lref _00024sql6CzH451 _00024sqc6cPp454)) (letp v (lref _00024sql6CzH451 _00024sqc6W8K455)) (exists mp_put (1 2 3 0) 3 __v0 k v) (exists mp_fromlist (1 0) 1 _00024seq1) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 5 k v xs _00024seq0 _00024seq1 __t3c2R379) (exists mp_fromlist (0 1) 2 __t3c2R379 _00024seq1) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __v0 k v __t4UIA381) (join mp_fromlist (0 1) 2 __t3c2R379 _00024seq1) (join-old mp_put_ans (0 1) 1 (0 1) __t4UIA381 __v1) (letp _00024sql7ZXI456 (aslst _00024seq1)) (let _00024sqn1QVd457 (llen _00024sql7ZXI456)) (cmp ge _00024sqn1QVd457 _00024sqc1g9y458) (let chk5NtT1043 (llen _00024sql6CzH451)) (eq _00024sqc96G8453 chk5NtT1043) (letp chk5z6b1044 (lref _00024sql7ZXI456 _00024sqc9hYP459)) (eq _00024seq0 chk5z6b1044) (let _00024sqp3HUi462 (_0002d _00024sqn1QVd457 _00024sqc7qLn461)) (let chk1Uen1045 (lslice _00024sql7ZXI456 _00024sqc9QOZ460 _00024sqp3HUi462)) (eq xs chk1Uen1045)) (head (emit mp_fromlist_ans (1 0) __v1 __t3c2R379)) map.slog:128 #f)
  class ReadTask707 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex692;  slog::Index** mp_putindex693;  slog::Index** mp_fromlistindex694;  slog::Index** $sup5638x127x0x0x0index695;  slog::Index** $seq_atindex696;  slog::Index** mp_putindex697;  slog::Index** mp_fromlistindex698;  slog::Index** $sup5638x127x0x0x0index699;  slog::Index** mp_fromlistindex700;  slog::Index** mp_putindex701;  slog::Index** mp_fromlistindex702;  slog::Index** mp_put_ansindex703;  slog::Index** $seq_atdelta704;  slog::Index** mp_putdelta705;  slog::Index** mp_put_ansdelta706;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord708({1, 0});
      slog::Relation* readrel709 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel709->getIndex(ord708, false);
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord710({1, 0, 2});
      slog::Relation* readrel711 = db->getRelation("$seq_at");
      $seq_atindex692 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 2, 0, 3});
      slog::Relation* readrel713 = db->getRelation("mp_put");
      mp_putindex693 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({0, 1});
      slog::Relation* readrel715 = db->getRelation("mp_fromlist");
      mp_fromlistindex694 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({5, 0, 1, 2, 3, 4});
      slog::Relation* readrel717 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index695 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 0, 2});
      slog::Relation* readrel719 = db->getRelation("$seq_at");
      $seq_atindex696 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 0, 2});
      slog::Relation* readrel721 = db->getRelation("$seq_at");
      $seq_atdelta704 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({1, 2, 3, 0});
      slog::Relation* readrel723 = db->getRelation("mp_put");
      mp_putindex697 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 0});
      slog::Relation* readrel725 = db->getRelation("mp_fromlist");
      mp_fromlistindex698 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel727 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index699 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("mp_fromlist");
      mp_fromlistindex700 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 3, 0});
      slog::Relation* readrel731 = db->getRelation("mp_put");
      mp_putindex701 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 2, 3, 0});
      slog::Relation* readrel733 = db->getRelation("mp_put");
      mp_putdelta705 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({0, 1});
      slog::Relation* readrel735 = db->getRelation("mp_fromlist");
      mp_fromlistindex702 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({0, 1});
      slog::Relation* readrel737 = db->getRelation("mp_put_ans");
      mp_put_ansindex703 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("mp_put_ans");
      mp_put_ansdelta706 = readrel739->getIndex(ord738, true);
  
    }
    ReadTask707(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_constd4735e3a265e16eee03f5971;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex692, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex693, std::array<u64,4>{v_c12, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlistindex694, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m740) {
          u64 v_c66 = m740[1];
          if (!slog::exists_probe<6,1>($sup5638x127x0x0x0index695, std::array<u64,6>{v_c66, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>($seq_atindex696, $seq_atdelta704, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m741) {
            u64 v_c58 = m741[1]; u64 v_c59 = m741[2];
            bool ok742 = true;
            u64 v_c61 = _prim_aslst(db, v_c58, &ok742);
            if (!ok742) return;
            bool ok743 = true;
            u64 v_c4 = _prim_lref(db, v_c61, v_c49, &ok743);
            if (!ok743) return;
            bool ok744 = true;
            u64 v_c5 = _prim_lref(db, v_c61, v_c50, &ok744);
            if (!ok744) return;
            if (!slog::exists_probe<4,3>(mp_putindex697, std::array<u64,4>{v_c12, v_c4, v_c5, 0})) return;
            if (!slog::exists_probe<2,1>(mp_fromlistindex698, std::array<u64,2>{v_c59, 0})) return;
            slog::join_probe<6,5>($sup5638x127x0x0x0index699, std::array<u64,6>{v_c4, v_c5, v_c66, v_c58, v_c59, 0}, [&](const std::array<u64,6>& m745) {
              u64 v_c60 = m745[5];
              if (!slog::exists_probe<2,2>(mp_fromlistindex700, std::array<u64,2>{v_c60, v_c59})) return;
              slog::join_probe_old<4,3>(mp_putindex701, mp_putdelta705, std::array<u64,4>{v_c12, v_c4, v_c5, 0}, [&](const std::array<u64,4>& m746) {
                u64 v_c56 = m746[3];
                slog::join_probe<2,2>(mp_fromlistindex702, std::array<u64,2>{v_c60, v_c59}, [&](const std::array<u64,2>& m747) {
                  slog::join_probe_old<2,1>(mp_put_ansindex703, mp_put_ansdelta706, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m748) {
                    u64 v_c57 = m748[1];
                    bool ok749 = true;
                    u64 v_c62 = _prim_aslst(db, v_c59, &ok749);
                    if (!ok749) return;
                    u64 v_c63 = _prim_llen(db, v_c62);
                    if (v_c63 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c141 = _prim_ge(db, v_c63, v_c51);
                    if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (!v_c141) return;
                    u64 v_c142 = _prim_llen(db, v_c61);
                    if (v_c142 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c48 != v_c142) return;
                    bool ok751 = true;
                    u64 v_c143 = _prim_lref(db, v_c62, v_c52, &ok751);
                    if (!ok751) return;
                    if (v_c58 != v_c143) return;
                    u64 v_c65 = _prim__0002d(db, v_c63, v_c54);
                    if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c144 = _prim_lslice(db, v_c62, v_c53, v_c65);
                    if (v_c144 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c66 != v_c144) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c60}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask707* _cont = new ReadTask707(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask707(db,b), false);
  // (crule (pre) (scan mp_msk __t6MG8432 k m) (body (exists mleaf (1 2 0) 1 k) (exists $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_join (1 2 3 4 0) 1 k) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (join mleaf (1 2 0) 1 k v __t9k3L430) (exists mp_put (2 3 0 1) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t9k3L430) (join $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 3 k m v __t5vsG428 l p r __t51uB429) (neq p __v0) (join mbranch (1 2 3 4 0) 5 p m l r __t51uB429) (join mp_put (1 2 0 3) 4 __t51uB429 k __t5vsG428 v) (join mp_join (1 2 3 4 0) 4 k __t9k3L430 p __t51uB429 __t9vyw431) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask766 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex752;  slog::Index** $sup5638x44x0x0x0index753;  slog::Index** mbranchindex754;  slog::Index** mp_putindex755;  slog::Index** mp_joinindex756;  slog::Index** mp_msk_ansindex757;  slog::Index** mleafindex758;  slog::Index** mp_putindex759;  slog::Index** mp_joinindex760;  slog::Index** $sup5638x44x0x0x0index761;  slog::Index** mbranchindex762;  slog::Index** mp_putindex763;  slog::Index** mp_joinindex764;  slog::Index** mp_join_ansindex765;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord767({0, 1});
      slog::Relation* readrel768 = db->getRelation("mp_put_ans");
      head_index[0] = readrel768->getIndex(ord767, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("mleaf");
      mleafindex752 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel772 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index753 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({2, 0, 1, 3, 4});
      slog::Relation* readrel774 = db->getRelation("mbranch");
      mbranchindex754 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({2, 3, 0, 1});
      slog::Relation* readrel776 = db->getRelation("mp_put");
      mp_putindex755 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 3, 4, 0});
      slog::Relation* readrel778 = db->getRelation("mp_join");
      mp_joinindex756 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({0, 1});
      slog::Relation* readrel780 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex757 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("mleaf");
      mleafindex758 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({2, 3, 0, 1});
      slog::Relation* readrel784 = db->getRelation("mp_put");
      mp_putindex759 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 2, 3, 4, 0});
      slog::Relation* readrel786 = db->getRelation("mp_join");
      mp_joinindex760 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel788 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index761 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 3, 4, 0});
      slog::Relation* readrel790 = db->getRelation("mbranch");
      mbranchindex762 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0, 3});
      slog::Relation* readrel792 = db->getRelation("mp_put");
      mp_putindex763 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 3, 4, 0});
      slog::Relation* readrel794 = db->getRelation("mp_join");
      mp_joinindex764 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("mp_join_ans");
      mp_join_ansindex765 = readrel796->getIndex(ord795, false);
  
    }
    ReadTask766(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c145 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(mleafindex752, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index753, std::array<u64,8>{v_c4, v_c7, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex754, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex755, std::array<u64,4>{v_c4, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex756, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex757, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m797) {
          u64 v_c12 = m797[1];
          slog::join_probe<3,1>(mleafindex758, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m798) {
            u64 v_c5 = m798[1]; u64 v_c146 = m798[2];
            if (!slog::exists_probe<4,2>(mp_putindex759, std::array<u64,4>{v_c4, v_c5, 0, 0})) return;
            if (!slog::exists_probe<5,2>(mp_joinindex760, std::array<u64,5>{v_c4, v_c146, 0, 0, 0})) return;
            slog::join_probe<8,3>($sup5638x44x0x0x0index761, std::array<u64,8>{v_c4, v_c7, v_c5, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m799) {
              u64 v_c147 = m799[3]; u64 v_c6 = m799[4]; u64 v_c8 = m799[5]; u64 v_c9 = m799[6]; u64 v_c148 = m799[7];
              if (v_c8 == v_c12) return;
              slog::join_probe<5,5>(mbranchindex762, std::array<u64,5>{v_c8, v_c7, v_c6, v_c9, v_c148}, [&](const std::array<u64,5>& m800) {
                slog::join_probe<4,4>(mp_putindex763, std::array<u64,4>{v_c148, v_c4, v_c147, v_c5}, [&](const std::array<u64,4>& m801) {
                  slog::join_probe<5,4>(mp_joinindex764, std::array<u64,5>{v_c4, v_c146, v_c8, v_c148, 0}, [&](const std::array<u64,5>& m802) {
                    u64 v_c149 = m802[4];
                    slog::join_probe<2,1>(mp_join_ansindex765, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m803) {
                      u64 v_c26 = m803[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c147, v_c26}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask766* _cont = new ReadTask766(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask766(db,b), false);
  // (crule (pre (let __tconst57IP579 constd01925b37634a1a9d24159d8) (let __tconst3BHG68 const6b86b273ff34fce19d6b804e) (let __tconst3Kbu67 const8c1f1046219ddd216a023f79)) (scan canon m) (body (join _enum (1 0) 1 __tconst57IP579 __t1XXZ69)) (head (mkstruct mp_put (1 2 3 0) __6gfh578 __t1XXZ69 __tconst3BHG68 __tconst3Kbu67)) mp_basic.slog:23 #f)
  class ReadTask805 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex804;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("canon");
      std::vector<u16> ord806({1, 0});
      slog::Relation* readrel807 = db->getRelation("_enum");
      _enumindex804 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask805(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c150 = v_constd01925b37634a1a9d24159d8;
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c152 = v_const8c1f1046219ddd216a023f79;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        slog::join_probe<2,1>(_enumindex804, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m808) {
          u64 v_c153 = m808[1];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c153, v_c151, v_c152}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:23", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask805* _cont = new ReadTask805(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask805(db,b), false);
}

