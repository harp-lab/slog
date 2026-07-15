
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const35c71810897f279c2099acbb;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5e6127cdd5ea2629462053c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const78643ffd185a1863a6e6997e;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_const99e1cbf3d792d4a87847a801;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c78f902bcfebb45d1(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst3q0e391 const5feceb66ffc86f38d952786c)) (scan pbranch __t91mZ389 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t91mZ389 __t4x1d388 __t3g0Z390) (join pbranch (0 1 2 3 4) 1 __t4x1d388 q n u v) (cmp lt n m) (let __t2V1B392 (band q m)) (cmp gt __t2V1B392 __tconst3q0e391)) (head (emit $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) __t3g0Z390 r l m n p q u v)) set.slog:143 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex0;  slog::Index** pbranchindex1;  slog::Index** st_diffdelta2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord4({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel5 = db->getRelation("$sup9688x142x0x0x0");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord6({1, 2, 0});
      slog::Relation* readrel7 = db->getRelation("st_diff");
      st_diffindex0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 2, 0});
      slog::Relation* readrel9 = db->getRelation("st_diff");
      st_diffdelta2 = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({0, 1, 2, 3, 4});
      slog::Relation* readrel11 = db->getRelation("pbranch");
      pbranchindex1 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe_old<3,1>(st_diffindex0, st_diffdelta2, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m12) {
          u64 v_c6 = m12[1]; u64 v_c7 = m12[2];
          slog::join_probe<5,1>(pbranchindex1, std::array<u64,5>{v_c6, 0, 0, 0, 0}, [&](const std::array<u64,5>& m13) {
            u64 v_c8 = m13[1]; u64 v_c9 = m13[2]; u64 v_c10 = m13[3]; u64 v_c11 = m13[4];
            u64 v_c12 = _prim_lt(db, v_c9, v_c3);
            if (v_c12 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c12) return;
            u64 v_c13 = _prim_band(db, v_c8, v_c3);
            if (v_c13 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            u64 v_c14 = _prim_gt(db, v_c13, v_c0);
            if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c14) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c7, v_c5, v_c4, v_c3, v_c9, v_c2, v_c8, v_c10, v_c11}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:pbranch", _fires);
  
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
  // (crule (pre (let __tconst03yH266 const6b86b273ff34fce19d6b804e)) (scan $sup9688x36x0x0x0 __d0 p0 p1 t0 t1) (body (join-old st_hsb_ans (0 1) 0 (0 1) __t3jPx265 __v0) (let __t7lUk264 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t3jPx265 __t7lUk264) (let __t2kVi267 (band p0 __v0)) (cmp lt __t2kVi267 __tconst03yH266)) (head (emit $sup9688x36x0x0x1 (1 2 0 3 4 5 6) __t3jPx265 __v0 __d0 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex16;  slog::Index** st_hsbindex17;  slog::Index** st_hsb_ansdelta18;  slog::Index** st_hsbdelta19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord21({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel22 = db->getRelation("$sup9688x36x0x0x1");
      head_index[0] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex16 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta18 = readrel26->getIndex(ord25, true);
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("st_hsb");
      st_hsbindex17 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("st_hsb");
      st_hsbdelta19 = readrel30->getIndex(ord29, true);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c19 = _t[3];
        u64 v_c20 = _t[4];
        slog::join_all_old<2>(st_hsb_ansindex16, st_hsb_ansdelta18, [&](const std::array<u64,2>& m31) {
          u64 v_c21 = m31[0]; u64 v_c22 = m31[1];
          u64 v_c23 = _prim_bxor(db, v_c17, v_c18);
          if (v_c23 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
          slog::join_probe_old<2,2>(st_hsbindex17, st_hsbdelta19, std::array<u64,2>{v_c21, v_c23}, [&](const std::array<u64,2>& m32) {
            u64 v_c24 = _prim_band(db, v_c17, v_c22);
            if (v_c24 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            u64 v_c25 = _prim_lt(db, v_c24, v_c15);
            if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            if (!v_c25) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c21, v_c22, v_c16, v_c17, v_c18, v_c19, v_c20}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre) (scan $sup9688x154x0x0x0 __t0EGY419 l m n p q r u v) (body (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 2 p n) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t7ytQ417) (exists st_diff (2 0 1) 2 __t7ytQ417 __t0EGY419) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1fgd418) (join-old st_diff (0 1 2) 3 (0 1 2) __t0EGY419 __t1fgd418 __t7ytQ417) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t8lOi420) (join st_msk_ans (0 1) 1 __t8lOi420 __v0) (neq q __v0)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex34;  slog::Index** st_mskindex35;  slog::Index** pbranchindex36;  slog::Index** st_diffindex37;  slog::Index** pbranchindex38;  slog::Index** st_diffindex39;  slog::Index** st_mskindex40;  slog::Index** st_msk_ansindex41;  slog::Index** pbranchdelta42;  slog::Index** pbranchdelta43;  slog::Index** st_diffdelta44;  slog::Index** st_mskdelta45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("st_diff_ans");
      head_index[0] = readrel48->getIndex(ord47, false);
      outer_rel = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord49({1, 2, 3, 4, 0});
      slog::Relation* readrel50 = db->getRelation("pbranch");
      pbranchindex34 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("st_msk");
      st_mskindex35 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 3, 4, 0});
      slog::Relation* readrel54 = db->getRelation("pbranch");
      pbranchindex36 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 3, 4, 0});
      slog::Relation* readrel56 = db->getRelation("pbranch");
      pbranchdelta42 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({2, 0, 1});
      slog::Relation* readrel58 = db->getRelation("st_diff");
      st_diffindex37 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 3, 4, 0});
      slog::Relation* readrel60 = db->getRelation("pbranch");
      pbranchindex38 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 3, 4, 0});
      slog::Relation* readrel62 = db->getRelation("pbranch");
      pbranchdelta43 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1, 2});
      slog::Relation* readrel64 = db->getRelation("st_diff");
      st_diffindex39 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1, 2});
      slog::Relation* readrel66 = db->getRelation("st_diff");
      st_diffdelta44 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("st_msk");
      st_mskindex40 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("st_msk");
      st_mskdelta45 = readrel70->getIndex(ord69, true);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("st_msk_ans");
      st_msk_ansindex41 = readrel72->getIndex(ord71, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c5 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c11 = _t[8];
        u64 v_c27 = _prim_lt(db, v_c3, v_c9);
        if (v_c27 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
        if (!v_c27) return;
        if (!slog::exists_probe<5,4>(pbranchindex34, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex35, std::array<u64,3>{v_c2, v_c9, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex36, pbranchdelta42, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m74) {
          u64 v_c28 = m74[4];
          if (!slog::exists_probe<3,2>(st_diffindex37, std::array<u64,3>{v_c28, v_c26, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex38, pbranchdelta43, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m75) {
            u64 v_c29 = m75[4];
            slog::join_probe_old<3,3>(st_diffindex39, st_diffdelta44, std::array<u64,3>{v_c26, v_c29, v_c28}, [&](const std::array<u64,3>& m76) {
              slog::join_probe_old<3,2>(st_mskindex40, st_mskdelta45, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m77) {
                u64 v_c30 = m77[2];
                slog::join_probe<2,1>(st_msk_ansindex41, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m78) {
                  u64 v_c22 = m78[1];
                  if (v_c8 == v_c22) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c29}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:$sup9688x154x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask46* _cont = new ReadTask46(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask46(db,b), false);
  // (crule (pre) (scan temp7u1Q1268 __t2B3O85 k) (body (join pleaf (1 0) 1 k __t88id83)) (head (emit st_ins_ans (0 1) __t2B3O85 __t88id83)) set.slog:48 #f)
  class ReadTask80 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex79;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("st_ins_ans");
      head_index[0] = readrel82->getIndex(ord81, false);
      outer_rel = db->getRelation("temp7u1Q1268");
      std::vector<u16> ord83({1, 0});
      slog::Relation* readrel84 = db->getRelation("pleaf");
      pleafindex79 = readrel84->getIndex(ord83, false);
  
    }
    ReadTask80(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe<2,1>(pleafindex79, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m85) {
          u64 v_c33 = m85[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c33}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:48", "delta:temp7u1Q1268", _fires);
  
      if (!_done)
      {
        ReadTask80* _cont = new ReadTask80(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask80(db,b), false);
  // (crule (pre (let __tconst9s1r696 conste3776bfed7f405de8017ecfa)) (scan st_del __t6cBI510 __t0pJC509 k) (body (join pleaf (0 1) 2 __t0pJC509 k) (join _enum (1 0) 1 __tconst9s1r696 __t3Ch3508)) (head (emit st_del_ans (0 1) __t6cBI510 __t3Ch3508)) set.slog:86 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex86;  slog::Index** _enumindex87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("st_del_ans");
      head_index[0] = readrel90->getIndex(ord89, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("pleaf");
      pleafindex86 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("_enum");
      _enumindex87 = readrel94->getIndex(ord93, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_conste3776bfed7f405de8017ecfa;
  
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
        u64 v_c32 = _t[2];
        slog::join_probe<2,2>(pleafindex86, std::array<u64,2>{v_c36, v_c32}, [&](const std::array<u64,2>& m95) {
          slog::join_probe<2,1>(_enumindex87, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m96) {
            u64 v_c37 = m96[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c37}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:86", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), false);
  // (crule (pre (let __tconst8MXc56 const6b86b273ff34fce19d6b804e)) (scan pbranch __t8Tgk54 p m l r) (body (join-old st_ins (1 2 0) 1 (1 2 0) __t8Tgk54 k __t8YRN55) (let __t3NtX57 (band k m)) (cmp lt __t3NtX57 __tconst8MXc56)) (head (emit $sup9688x50x0x0x0 (4 2 3 5 0 1) p l m r __t8YRN55 k)) set.slog:51 #f)
  class ReadTask99 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex97;  slog::Index** st_insdelta98;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord100({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel101 = db->getRelation("$sup9688x50x0x0x0");
      head_index[0] = readrel101->getIndex(ord100, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord102({1, 2, 0});
      slog::Relation* readrel103 = db->getRelation("st_ins");
      st_insindex97 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("st_ins");
      st_insdelta98 = readrel105->getIndex(ord104, true);
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe_old<3,1>(st_insindex97, st_insdelta98, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m106) {
          u64 v_c32 = m106[1]; u64 v_c40 = m106[2];
          u64 v_c41 = _prim_band(db, v_c32, v_c3);
          if (v_c41 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
          u64 v_c42 = _prim_lt(db, v_c41, v_c38);
          if (v_c42 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
          if (!v_c42) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c4, v_c3, v_c5, v_c40, v_c32}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask99* _cont = new ReadTask99(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask99(db,b), false);
  // (crule (pre (let __tconst3u0P481 const6b86b273ff34fce19d6b804e)) (scan st_del __t1Omm480 __t64JH479 k) (body (join pbranch (0 1 2 3 4) 1 __t64JH479 p m l r) (let __t5Pxk482 (band k m)) (cmp lt __t5Pxk482 __tconst3u0P481)) (head (emit $sup9688x88x0x0x0 (4 3 5 2 0 1) p m r l __t1Omm480 k)) set.slog:89 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord110({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel111 = db->getRelation("$sup9688x88x0x0x0");
      head_index[0] = readrel111->getIndex(ord110, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord112({0, 1, 2, 3, 4});
      slog::Relation* readrel113 = db->getRelation("pbranch");
      pbranchindex108 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c32 = _t[2];
        slog::join_probe<5,1>(pbranchindex108, std::array<u64,5>{v_c45, 0, 0, 0, 0}, [&](const std::array<u64,5>& m114) {
          u64 v_c2 = m114[1]; u64 v_c3 = m114[2]; u64 v_c4 = m114[3]; u64 v_c5 = m114[4];
          u64 v_c46 = _prim_band(db, v_c32, v_c3);
          if (v_c46 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
          u64 v_c47 = _prim_lt(db, v_c46, v_c43);
          if (v_c47 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
          if (!v_c47) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c3, v_c5, v_c4, v_c44, v_c32}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_del", _fires);
  
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
  // (crule (pre (let __tconst8eZh210 const5feceb66ffc86f38d952786c)) (scan pbranch __t9thx208 p m l r) (body (join-old st_ins (1 2 0) 1 (1 2 0) __t9thx208 k __t90D6209) (let __t6CjD211 (band k m)) (cmp gt __t6CjD211 __tconst8eZh210)) (head (emit $sup9688x52x0x0x0 (4 2 3 5 0 1) p l m r __t90D6209 k)) set.slog:53 #f)
  class ReadTask118 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex116;  slog::Index** st_insdelta117;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord119({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel120 = db->getRelation("$sup9688x52x0x0x0");
      head_index[0] = readrel120->getIndex(ord119, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("st_ins");
      st_insindex116 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("st_ins");
      st_insdelta117 = readrel124->getIndex(ord123, true);
  
    }
    ReadTask118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c49 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe_old<3,1>(st_insindex116, st_insdelta117, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m125) {
          u64 v_c32 = m125[1]; u64 v_c50 = m125[2];
          u64 v_c51 = _prim_band(db, v_c32, v_c3);
          if (v_c51 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
          u64 v_c52 = _prim_gt(db, v_c51, v_c48);
          if (v_c52 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
          if (!v_c52) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c4, v_c3, v_c5, v_c50, v_c32}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask118* _cont = new ReadTask118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask118(db,b), false);
  // (crule (pre) (scan $sup9688x36x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t9i2T156 (bxor p0 p1))) (head (emit-temp temp7aSv1347 __t9i2T156)) set.slog:37 #f)
  class ReadTask127 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7aSv1347");
      outer_rel = db->getRelation("$sup9688x36x0x0x1");
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c18 = _t[4];
        u64 v_c19 = _t[5];
        u64 v_c20 = _t[6];
        u64 v_c54 = _prim_bxor(db, v_c17, v_c18);
        if (v_c54 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c54});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan st_msk_ans __t9Eou545 p) (body (exists $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t9Eou545 q m) (exists pbranch (1 2 3 4 0) 1 q) (join $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v) (exists st_diff (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3QFk546) (join-old st_diff (1 2 0) 2 (1 2 0) l __t3QFk546 __t9ide547) (join-old st_diff_ans (0 1) 1 (0 1) __t9ide547 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index128;  slog::Index** st_mskindex129;  slog::Index** pbranchindex130;  slog::Index** $sup9688x139x0x0x0index131;  slog::Index** st_diffindex132;  slog::Index** pbranchindex133;  slog::Index** st_diffindex134;  slog::Index** st_diff_ansindex135;  slog::Index** st_mskdelta136;  slog::Index** pbranchdelta137;  slog::Index** st_diffdelta138;  slog::Index** st_diff_ansdelta139;
    u32 sid141;  u32 sid140;  u32 sid142;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord144({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel145 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index128 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1, 2});
      slog::Relation* readrel147 = db->getRelation("st_msk");
      st_mskindex129 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1, 2});
      slog::Relation* readrel149 = db->getRelation("st_msk");
      st_mskdelta136 = readrel149->getIndex(ord148, true);
      std::vector<u16> ord150({1, 2, 3, 4, 0});
      slog::Relation* readrel151 = db->getRelation("pbranch");
      pbranchindex130 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel153 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index131 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 0});
      slog::Relation* readrel155 = db->getRelation("st_diff");
      st_diffindex132 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 2, 3, 4, 0});
      slog::Relation* readrel157 = db->getRelation("pbranch");
      pbranchindex133 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 3, 4, 0});
      slog::Relation* readrel159 = db->getRelation("pbranch");
      pbranchdelta137 = readrel159->getIndex(ord158, true);
      std::vector<u16> ord160({1, 2, 0});
      slog::Relation* readrel161 = db->getRelation("st_diff");
      st_diffindex134 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 2, 0});
      slog::Relation* readrel163 = db->getRelation("st_diff");
      st_diffdelta138 = readrel163->getIndex(ord162, true);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("st_diff_ans");
      st_diff_ansindex135 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("st_diff_ans");
      st_diff_ansdelta139 = readrel167->getIndex(ord166, true);
      sid141 = db->getRelation("_enum")->getStructId();
      sid140 = db->getRelation("pbranch")->getStructId();
      sid142 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c56 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c57 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c58 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index128, std::array<u64,9>{v_c2, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex129, st_mskdelta136, std::array<u64,3>{v_c58, 0, 0}, [&](const std::array<u64,3>& m168) {
          u64 v_c8 = m168[1]; u64 v_c3 = m168[2];
          if (!slog::exists_probe<5,1>(pbranchindex130, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x139x0x0x0index131, std::array<u64,9>{v_c3, v_c8, v_c2, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m169) {
            u64 v_c16 = m169[3]; u64 v_c4 = m169[4]; u64 v_c9 = m169[5]; u64 v_c5 = m169[6]; u64 v_c10 = m169[7]; u64 v_c11 = m169[8];
            if (!slog::exists_probe<3,1>(st_diffindex132, std::array<u64,3>{v_c4, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex133, pbranchdelta137, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m170) {
              u64 v_c59 = m170[4];
              slog::join_probe_old<3,2>(st_diffindex134, st_diffdelta138, std::array<u64,3>{v_c4, v_c59, 0}, [&](const std::array<u64,3>& m171) {
                u64 v_c60 = m171[2];
                slog::join_probe_old<2,1>(st_diff_ansindex135, st_diff_ansdelta139, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m172) {
                  u64 v_c22 = m172[1];
                  ++_fires;
                  if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid140 || decode_struct_id(v_c5) == sid141 || decode_struct_id(v_c5) == sid142))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c55, v_c56, v_c57, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c22, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst87Bp297 __t3icK299 __t1S8l298) (body (join _enum (0 1) 2 __t1S8l298 __tconst80a51002) (exists st_ins (2 0 1) 1 __tconst9HiA300) (exists st_ins (2 0 1) 1 __tconst4xiW302) (join st_ins_ans (0 1) 1 __t3icK299 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst9HiA300 __t8YZs301) (join st_ins_ans (0 1) 1 __t8YZs301 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4xiW302 __t43hI303) (join st_ins_ans (0 1) 1 __t43hI303 __v2)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex173;  slog::Index** st_insindex174;  slog::Index** st_insindex175;  slog::Index** st_ins_ansindex176;  slog::Index** st_insindex177;  slog::Index** st_ins_ansindex178;  slog::Index** st_insindex179;  slog::Index** st_ins_ansindex180;  slog::Index** st_insdelta181;  slog::Index** st_insdelta182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord184({2, 0, 1});
      slog::Relation* readrel185 = db->getRelation("st_ins");
      driver_index = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("_enum");
      _enumindex173 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({2, 0, 1});
      slog::Relation* readrel189 = db->getRelation("st_ins");
      st_insindex174 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({2, 0, 1});
      slog::Relation* readrel191 = db->getRelation("st_ins");
      st_insindex175 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("st_ins_ans");
      st_ins_ansindex176 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("st_ins");
      st_insindex177 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("st_ins");
      st_insdelta181 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({0, 1});
      slog::Relation* readrel199 = db->getRelation("st_ins_ans");
      st_ins_ansindex178 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 0});
      slog::Relation* readrel201 = db->getRelation("st_ins");
      st_insindex179 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 2, 0});
      slog::Relation* readrel203 = db->getRelation("st_ins");
      st_insdelta182 = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("st_ins_ans");
      st_ins_ansindex180 = readrel205->getIndex(ord204, false);
  
    }
    ReadTask183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const2c624232cdd221771294dfbb;
      u64 v_c64 = v_constd4735e3a265e16eee03f5971;
      u64 v_c65 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c62, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m206) {
        u64 v_c66 = m206[1];
        u64 v_c67 = m206[2];
        if (buckethash(v_c66) != bucket) return;
        slog::join_probe<2,2>(_enumindex173, std::array<u64,2>{v_c67, v_c61}, [&](const std::array<u64,2>& m207) {
          if (!slog::exists_probe<3,1>(st_insindex174, std::array<u64,3>{v_c63, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex175, std::array<u64,3>{v_c64, 0, 0})) return;
          slog::join_probe<2,1>(st_ins_ansindex176, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m208) {
            u64 v_c22 = m208[1];
            slog::join_probe_old<3,2>(st_insindex177, st_insdelta181, std::array<u64,3>{v_c22, v_c63, 0}, [&](const std::array<u64,3>& m209) {
              u64 v_c68 = m209[2];
              slog::join_probe<2,1>(st_ins_ansindex178, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m210) {
                u64 v_c69 = m210[1];
                slog::join_probe_old<3,2>(st_insindex179, st_insdelta182, std::array<u64,3>{v_c69, v_c64, 0}, [&](const std::array<u64,3>& m211) {
                  u64 v_c70 = m211[2];
                  slog::join_probe<2,1>(st_ins_ansindex180, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m212) {
                    u64 v_c71 = m212[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c71, v_c65}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask183* _cont = new ReadTask183(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask183(db,b), false);
  // (crule (pre) (scan temp8kS01399 __t6bST316 __v0 m p r) (body (join pbranch (1 2 3 4 0) 4 p m __v0 r __t4IGt314)) (head (emit st_ins_ans (0 1) __t6bST316 __t4IGt314)) set.slog:51 #f)
  class ReadTask214 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex213;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("st_ins_ans");
      head_index[0] = readrel216->getIndex(ord215, false);
      outer_rel = db->getRelation("temp8kS01399");
      std::vector<u16> ord217({1, 2, 3, 4, 0});
      slog::Relation* readrel218 = db->getRelation("pbranch");
      pbranchindex213 = readrel218->getIndex(ord217, false);
  
    }
    ReadTask214(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<5,4>(pbranchindex213, std::array<u64,5>{v_c2, v_c3, v_c22, v_c5, 0}, [&](const std::array<u64,5>& m219) {
          u64 v_c73 = m219[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c72, v_c73}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:temp8kS01399", _fires);
  
      if (!_done)
      {
        ReadTask214* _cont = new ReadTask214(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask214(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_hsb_ans __t75bg356 __v0) (body (exists st_hsb_ans (0 1) 1 __t75bg356) (exists $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t75bg356 __v0) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 2 __t75bg356 __v0) (join st_hsb_ans (0 1) 1 __t75bg356 __v3) (exists $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t75bg356 __v0 __v3) (join st_hsb_ans (0 1) 1 __t75bg356 __v1) (exists st_msk (2 0 1) 1 __v1) (join $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t75bg356 __v0 __v3 __v1 __t0kmv352 dup66Lo1333 dup68E21334 p0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join st_msk_ans (0 1) 1 __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask237 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex220;  slog::Index** $sup9688x36x0x0x2index221;  slog::Index** $sup9688x36x0x0x1index222;  slog::Index** st_hsb_ansindex223;  slog::Index** $sup9688x36x0x0x2index224;  slog::Index** st_hsb_ansindex225;  slog::Index** st_mskindex226;  slog::Index** $sup9688x36x0x0x2index227;  slog::Index** $sup9688x36x0x0x1index228;  slog::Index** $sup9688x36x0x0x0index229;  slog::Index** st_joinindex230;  slog::Index** st_mskindex231;  slog::Index** st_msk_ansindex232;  slog::Index** st_hsbindex233;  slog::Index** st_joindelta234;  slog::Index** st_mskdelta235;  slog::Index** st_hsbdelta236;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex220 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel241 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index221 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel243 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index222 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 1});
      slog::Relation* readrel245 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex223 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel247 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index224 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex225 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({2, 0, 1});
      slog::Relation* readrel251 = db->getRelation("st_msk");
      st_mskindex226 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel253 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index227 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel255 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index228 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0, 2, 3, 4});
      slog::Relation* readrel257 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index229 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 3, 4, 0});
      slog::Relation* readrel259 = db->getRelation("st_join");
      st_joinindex230 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 2, 3, 4, 0});
      slog::Relation* readrel261 = db->getRelation("st_join");
      st_joindelta234 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({1, 2, 0});
      slog::Relation* readrel263 = db->getRelation("st_msk");
      st_mskindex231 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("st_msk");
      st_mskdelta235 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({0, 1});
      slog::Relation* readrel267 = db->getRelation("st_msk_ans");
      st_msk_ansindex232 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("st_hsb");
      st_hsbindex233 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("st_hsb");
      st_hsbdelta236 = readrel271->getIndex(ord270, true);
  
    }
    ReadTask237(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex220, std::array<u64,2>{v_c75, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index221, std::array<u64,11>{v_c75, v_c22, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index222, std::array<u64,7>{v_c75, v_c22, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex223, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m272) {
          u64 v_c76 = m272[1];
          if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index224, std::array<u64,11>{v_c75, v_c22, v_c76, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(st_hsb_ansindex225, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m273) {
            u64 v_c69 = m273[1];
            if (!slog::exists_probe<3,1>(st_mskindex226, std::array<u64,3>{v_c69, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x36x0x0x2index227, std::array<u64,11>{v_c75, v_c22, v_c76, v_c69, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m274) {
              u64 v_c77 = m274[4]; u64 v_c78 = m274[5]; u64 v_c79 = m274[6]; u64 v_c17 = m274[7]; u64 v_c18 = m274[8]; u64 v_c19 = m274[9]; u64 v_c20 = m274[10];
              if (v_c75 != v_c79) return;
              if (v_c75 != v_c78) return;
              slog::join_probe<7,7>($sup9688x36x0x0x1index228, std::array<u64,7>{v_c77, v_c17, v_c18, v_c19, v_c20, v_c75, v_c22}, [&](const std::array<u64,7>& m275) {
                slog::join_probe<5,5>($sup9688x36x0x0x0index229, std::array<u64,5>{v_c17, v_c77, v_c18, v_c19, v_c20}, [&](const std::array<u64,5>& m276) {
                  slog::join_probe_old<5,5>(st_joinindex230, st_joindelta234, std::array<u64,5>{v_c17, v_c19, v_c18, v_c20, v_c77}, [&](const std::array<u64,5>& m277) {
                    slog::join_probe_old<3,2>(st_mskindex231, st_mskdelta235, std::array<u64,3>{v_c17, v_c69, 0}, [&](const std::array<u64,3>& m278) {
                      u64 v_c80 = m278[2];
                      slog::join_probe<2,1>(st_msk_ansindex232, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m279) {
                        u64 v_c71 = m279[1];
                        u64 v_c81 = _prim_bxor(db, v_c17, v_c18);
                        if (v_c81 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex233, st_hsbdelta236, std::array<u64,2>{v_c75, v_c81}, [&](const std::array<u64,2>& m280) {
                          u64 v_c82 = _prim_band(db, v_c17, v_c22);
                          if (v_c82 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c83 = _prim_lt(db, v_c82, v_c74);
                          if (v_c83 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c83) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c77, v_c71, v_c76, v_c19, v_c20});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c76, v_c19, v_c20}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask237* _cont = new ReadTask237(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask237(db,b), false);
  // (crule (pre) (scan pbranch __t1pUK287 p m l r) (body (exists pbranch (1 2 3 4 0) 2 p m) (exists st_union (1 2 0) 1 __t1pUK287) (exists st_union (1 2 0) 1 l) (exists st_union (1 2 0) 1 r) (join $sup9688x100x0x0x0 (1 2 3 4 0 5 6) 4 l m p r __t2Q3U288 u v) (exists st_union (0 1 2) 2 __t2Q3U288 __t1pUK287) (exists st_union (1 2 0) 2 l u) (exists st_union (1 2 0) 2 r v) (join pbranch (1 2 3 4 0) 4 p m u v __t22FG286) (join-old st_union (0 1 2) 3 (0 1 2) __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) l u __t1gnX289) (exists st_union_ans (0 1) 1 __t1gnX289) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (exists st_union_ans (0 1) 1 __t8LsM290) (join st_union_ans (0 1) 1 __t1gnX289 __v0) (join st_union_ans (0 1) 1 __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex282;  slog::Index** st_unionindex283;  slog::Index** st_unionindex284;  slog::Index** st_unionindex285;  slog::Index** $sup9688x100x0x0x0index286;  slog::Index** st_unionindex287;  slog::Index** st_unionindex288;  slog::Index** st_unionindex289;  slog::Index** pbranchindex290;  slog::Index** st_unionindex291;  slog::Index** st_unionindex292;  slog::Index** st_union_ansindex293;  slog::Index** st_unionindex294;  slog::Index** st_union_ansindex295;  slog::Index** st_union_ansindex296;  slog::Index** st_union_ansindex297;  slog::Index** st_uniondelta298;  slog::Index** st_uniondelta299;  slog::Index** st_uniondelta300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord302({1, 2, 3, 4, 0});
      slog::Relation* readrel303 = db->getRelation("pbranch");
      pbranchindex282 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("st_union");
      st_unionindex283 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 2, 0});
      slog::Relation* readrel307 = db->getRelation("st_union");
      st_unionindex284 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("st_union");
      st_unionindex285 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 3, 4, 0, 5, 6});
      slog::Relation* readrel311 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index286 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 1, 2});
      slog::Relation* readrel313 = db->getRelation("st_union");
      st_unionindex287 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("st_union");
      st_unionindex288 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 2, 0});
      slog::Relation* readrel317 = db->getRelation("st_union");
      st_unionindex289 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 3, 4, 0});
      slog::Relation* readrel319 = db->getRelation("pbranch");
      pbranchindex290 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("st_union");
      st_unionindex291 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1, 2});
      slog::Relation* readrel323 = db->getRelation("st_union");
      st_uniondelta298 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("st_union");
      st_unionindex292 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 0});
      slog::Relation* readrel327 = db->getRelation("st_union");
      st_uniondelta299 = readrel327->getIndex(ord326, true);
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("st_union_ans");
      st_union_ansindex293 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("st_union");
      st_unionindex294 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 0});
      slog::Relation* readrel333 = db->getRelation("st_union");
      st_uniondelta300 = readrel333->getIndex(ord332, true);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("st_union_ans");
      st_union_ansindex295 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("st_union_ans");
      st_union_ansindex296 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("st_union_ans");
      st_union_ansindex297 = readrel339->getIndex(ord338, false);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex282, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex283, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex284, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex285, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<7,4>($sup9688x100x0x0x0index286, std::array<u64,7>{v_c4, v_c3, v_c2, v_c5, 0, 0, 0}, [&](const std::array<u64,7>& m340) {
          u64 v_c85 = m340[4]; u64 v_c10 = m340[5]; u64 v_c11 = m340[6];
          if (!slog::exists_probe<3,2>(st_unionindex287, std::array<u64,3>{v_c85, v_c84, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex288, std::array<u64,3>{v_c4, v_c10, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex289, std::array<u64,3>{v_c5, v_c11, 0})) return;
          slog::join_probe<5,4>(pbranchindex290, std::array<u64,5>{v_c2, v_c3, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m341) {
            u64 v_c86 = m341[4];
            slog::join_probe_old<3,3>(st_unionindex291, st_uniondelta298, std::array<u64,3>{v_c85, v_c84, v_c86}, [&](const std::array<u64,3>& m342) {
              slog::join_probe_old<3,2>(st_unionindex292, st_uniondelta299, std::array<u64,3>{v_c4, v_c10, 0}, [&](const std::array<u64,3>& m343) {
                u64 v_c87 = m343[2];
                if (!slog::exists_probe<2,1>(st_union_ansindex293, std::array<u64,2>{v_c87, 0})) return;
                slog::join_probe_old<3,2>(st_unionindex294, st_uniondelta300, std::array<u64,3>{v_c5, v_c11, 0}, [&](const std::array<u64,3>& m344) {
                  u64 v_c88 = m344[2];
                  if (!slog::exists_probe<2,1>(st_union_ansindex295, std::array<u64,2>{v_c88, 0})) return;
                  slog::join_probe<2,1>(st_union_ansindex296, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m345) {
                    u64 v_c22 = m345[1];
                    slog::join_probe<2,1>(st_union_ansindex297, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m346) {
                      u64 v_c69 = m346[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c85, v_c22, v_c69, v_c3, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c22, v_c69}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask301* _cont = new ReadTask301(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask301(db,b), false);
  // (crule (pre (let __tconst4IEm562 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t9ujC564 __t4E8i563 k) (body (join pleaf (0 1) 1 __t4E8i563 j) (neq j k)) (head (emit st_mem0_ans (0 1) __t9ujC564 __tconst4IEm562)) set.slog:69 #f)
  class ReadTask348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex347;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord349({0, 1});
      slog::Relation* readrel350 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel350->getIndex(ord349, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("pleaf");
      pleafindex347 = readrel352->getIndex(ord351, false);
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c32 = _t[2];
        slog::join_probe<2,1>(pleafindex347, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m353) {
          u64 v_c92 = m353[1];
          if (v_c92 == v_c32) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c90, v_c89}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:69", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask348* _cont = new ReadTask348(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask348(db,b), false);
  // (crule (pre (let __trid7GXs691 const78643ffd185a1863a6e6997e) (let __trel7Rkn692 consta10f76b4ec574de5d7b6908e) (let __tcol7BBx693 const5feceb66ffc86f38d952786c) (let __trel23SU694 consta10f76b4ec574de5d7b6908e) (let __tcol01OM695 const6b86b273ff34fce19d6b804e)) (scan $sup9688x103x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid7GXs691 __trel7Rkn692 __tcol7BBx693 (1 2 3 4 0)) (tycheck m (accept int) __trid7GXs691 __trel23SU694 __tcol01OM695 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __89wa690 q m)) set.slog:104 #f)
  class ReadTask354 : public slog::Task
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
      head_rel[2] = db->getRelation("st_msk");
      outer_rel = db->getRelation("$sup9688x103x0x0x0");
  
    }
    ReadTask354(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const78643ffd185a1863a6e6997e;
      u64 v_c94 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c5 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c11 = _t[8];
        ++_fires;
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c93, v_c94, v_c95, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c93, v_c96, v_c97, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:$sup9688x103x0x0x0", _fires);
  
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
  // (crule (pre) (scan $sup9688x114x0x0x0 __d0 l m n p q r u v) (body (exists st_msk_ans (1 0) 1 q) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1TTr141) (join-old st_msk_ans (0 1) 2 (0 1) __t1TTr141 q)) (head (emit $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t1TTr141 l m n p q r v)) set.slog:115 #f)
  class ReadTask360 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex355;  slog::Index** st_mskindex356;  slog::Index** st_msk_ansindex357;  slog::Index** st_mskdelta358;  slog::Index** st_msk_ansdelta359;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord361({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel362 = db->getRelation("$sup9688x114x0x0x1");
      head_index[0] = readrel362->getIndex(ord361, false);
      outer_rel = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("st_msk_ans");
      st_msk_ansindex355 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 0});
      slog::Relation* readrel366 = db->getRelation("st_msk");
      st_mskindex356 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 0});
      slog::Relation* readrel368 = db->getRelation("st_msk");
      st_mskdelta358 = readrel368->getIndex(ord367, true);
      std::vector<u16> ord369({0, 1});
      slog::Relation* readrel370 = db->getRelation("st_msk_ans");
      st_msk_ansindex357 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1});
      slog::Relation* readrel372 = db->getRelation("st_msk_ans");
      st_msk_ansdelta359 = readrel372->getIndex(ord371, true);
  
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c5 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c11 = _t[8];
        if (!slog::exists_probe<2,1>(st_msk_ansindex355, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex356, st_mskdelta358, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m373) {
          u64 v_c98 = m373[2];
          slog::join_probe_old<2,2>(st_msk_ansindex357, st_msk_ansdelta359, std::array<u64,2>{v_c98, v_c8}, [&](const std::array<u64,2>& m374) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c16, v_c10, v_c98, v_c4, v_c3, v_c9, v_c2, v_c8, v_c5, v_c11}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:$sup9688x114x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan pbranch __t6SZQ102 q n u v) (body (exists st_diff (2 0 1) 1 __t6SZQ102) (exists st_diff (2 0 1) 1 u) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x148x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t5Ek2104 l m p r) (cmp lt m n) (exists st_diff (2 0 1) 2 __t6SZQ102 __t5Ek2104) (exists st_msk (1 2 0) 2 p n) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6qKy107) (join-old st_diff (0 1 2) 3 (0 1 2) __t5Ek2104 __t6qKy107 __t6SZQ102) (join-old st_diff (1 2 0) 2 (1 2 0) __t6qKy107 u __t4u9h108) (exists st_diff_ans (0 1) 1 __t4u9h108) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join st_msk_ans (0 1) 2 __t3oZy109 q) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask393 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex375;  slog::Index** st_diffindex376;  slog::Index** st_mskindex377;  slog::Index** st_msk_ansindex378;  slog::Index** $sup9688x148x0x0x0index379;  slog::Index** st_diffindex380;  slog::Index** st_mskindex381;  slog::Index** pbranchindex382;  slog::Index** st_diffindex383;  slog::Index** st_diffindex384;  slog::Index** st_diff_ansindex385;  slog::Index** st_mskindex386;  slog::Index** st_msk_ansindex387;  slog::Index** st_diff_ansindex388;  slog::Index** pbranchdelta389;  slog::Index** st_diffdelta390;  slog::Index** st_diffdelta391;  slog::Index** st_mskdelta392;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord394({0, 1});
      slog::Relation* readrel395 = db->getRelation("st_diff_ans");
      head_index[0] = readrel395->getIndex(ord394, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord396({2, 0, 1});
      slog::Relation* readrel397 = db->getRelation("st_diff");
      st_diffindex375 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({2, 0, 1});
      slog::Relation* readrel399 = db->getRelation("st_diff");
      st_diffindex376 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({2, 0, 1});
      slog::Relation* readrel401 = db->getRelation("st_msk");
      st_mskindex377 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0});
      slog::Relation* readrel403 = db->getRelation("st_msk_ans");
      st_msk_ansindex378 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel405 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index379 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({2, 0, 1});
      slog::Relation* readrel407 = db->getRelation("st_diff");
      st_diffindex380 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0});
      slog::Relation* readrel409 = db->getRelation("st_msk");
      st_mskindex381 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 2, 3, 4, 0});
      slog::Relation* readrel411 = db->getRelation("pbranch");
      pbranchindex382 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 3, 4, 0});
      slog::Relation* readrel413 = db->getRelation("pbranch");
      pbranchdelta389 = readrel413->getIndex(ord412, true);
      std::vector<u16> ord414({0, 1, 2});
      slog::Relation* readrel415 = db->getRelation("st_diff");
      st_diffindex383 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1, 2});
      slog::Relation* readrel417 = db->getRelation("st_diff");
      st_diffdelta390 = readrel417->getIndex(ord416, true);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("st_diff");
      st_diffindex384 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("st_diff");
      st_diffdelta391 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("st_diff_ans");
      st_diff_ansindex385 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 0});
      slog::Relation* readrel425 = db->getRelation("st_msk");
      st_mskindex386 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 0});
      slog::Relation* readrel427 = db->getRelation("st_msk");
      st_mskdelta392 = readrel427->getIndex(ord426, true);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("st_msk_ans");
      st_msk_ansindex387 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("st_diff_ans");
      st_diff_ansindex388 = readrel431->getIndex(ord430, false);
  
    }
    ReadTask393(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex375, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex376, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex377, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex378, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<9,4>($sup9688x148x0x0x0index379, std::array<u64,9>{v_c8, v_c9, v_c10, v_c11, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m432) {
          u64 v_c101 = m432[4]; u64 v_c4 = m432[5]; u64 v_c3 = m432[6]; u64 v_c2 = m432[7]; u64 v_c5 = m432[8];
          u64 v_c102 = _prim_lt(db, v_c3, v_c9);
          if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
          if (!v_c102) return;
          if (!slog::exists_probe<3,2>(st_diffindex380, std::array<u64,3>{v_c100, v_c101, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex381, std::array<u64,3>{v_c2, v_c9, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex382, pbranchdelta389, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m434) {
            u64 v_c103 = m434[4];
            slog::join_probe_old<3,3>(st_diffindex383, st_diffdelta390, std::array<u64,3>{v_c101, v_c103, v_c100}, [&](const std::array<u64,3>& m435) {
              slog::join_probe_old<3,2>(st_diffindex384, st_diffdelta391, std::array<u64,3>{v_c103, v_c10, 0}, [&](const std::array<u64,3>& m436) {
                u64 v_c104 = m436[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex385, std::array<u64,2>{v_c104, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex386, st_mskdelta392, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m437) {
                  u64 v_c105 = m437[2];
                  slog::join_probe<2,2>(st_msk_ansindex387, std::array<u64,2>{v_c105, v_c8}, [&](const std::array<u64,2>& m438) {
                    slog::join_probe<2,1>(st_diff_ansindex388, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m439) {
                      u64 v_c106 = m439[1];
                      u64 v_c107 = _prim_band(db, v_c2, v_c9);
                      if (v_c107 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c108 = _prim_lt(db, v_c107, v_c99);
                      if (v_c108 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c108) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c106}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask393* _cont = new ReadTask393(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask393(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan st_msk __t0gfm348 q m) (body (exists $sup9688x106x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (2 0 1 3 4) 1 m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_msk_ans (0 1) 1 __t0gfm348) (join $sup9688x106x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t0gfm348 m q p __t7KDg345 l n r u v) (cmp lt n m) (join $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t7KDg345 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk_ans (0 1) 2 __t0gfm348 p) (exists st_union (1 2 0) 1 r) (join pbranch (1 2 3 4 0) 4 p m l r __t4ii6344) (exists st_union (0 1 2) 2 __t7KDg345 __t4ii6344) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0LeB349) (join st_union (0 1 2) 3 __t7KDg345 __t4ii6344 __t0LeB349) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x0index441;  slog::Index** pbranchindex442;  slog::Index** pbranchindex443;  slog::Index** st_msk_ansindex444;  slog::Index** $sup9688x106x0x0x1index445;  slog::Index** $sup9688x106x0x0x0index446;  slog::Index** pbranchindex447;  slog::Index** st_msk_ansindex448;  slog::Index** st_unionindex449;  slog::Index** pbranchindex450;  slog::Index** st_unionindex451;  slog::Index** pbranchindex452;  slog::Index** st_unionindex453;  slog::Index** st_msk_ansindex454;  slog::Index** st_unionindex455;  slog::Index** st_union_ansindex456;  slog::Index** pbranchdelta457;  slog::Index** st_uniondelta458;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord460({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel461 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index441 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({2, 0, 1, 3, 4});
      slog::Relation* readrel463 = db->getRelation("pbranch");
      pbranchindex442 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 3, 4, 0});
      slog::Relation* readrel465 = db->getRelation("pbranch");
      pbranchindex443 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("st_msk_ans");
      st_msk_ansindex444 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel469 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index445 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel471 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index446 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 2, 3, 4, 0});
      slog::Relation* readrel473 = db->getRelation("pbranch");
      pbranchindex447 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({0, 1});
      slog::Relation* readrel475 = db->getRelation("st_msk_ans");
      st_msk_ansindex448 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("st_union");
      st_unionindex449 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 3, 4, 0});
      slog::Relation* readrel479 = db->getRelation("pbranch");
      pbranchindex450 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1, 2});
      slog::Relation* readrel481 = db->getRelation("st_union");
      st_unionindex451 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 3, 4, 0});
      slog::Relation* readrel483 = db->getRelation("pbranch");
      pbranchindex452 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 3, 4, 0});
      slog::Relation* readrel485 = db->getRelation("pbranch");
      pbranchdelta457 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({0, 1, 2});
      slog::Relation* readrel487 = db->getRelation("st_union");
      st_unionindex453 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1});
      slog::Relation* readrel489 = db->getRelation("st_msk_ans");
      st_msk_ansindex454 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("st_union");
      st_unionindex455 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("st_union");
      st_uniondelta458 = readrel493->getIndex(ord492, true);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("st_union_ans");
      st_union_ansindex456 = readrel495->getIndex(ord494, false);
  
    }
    ReadTask459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x106x0x0x0index441, std::array<u64,9>{v_c3, v_c8, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex442, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex443, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex444, std::array<u64,2>{v_c110, 0})) return;
        slog::join_probe<10,3>($sup9688x106x0x0x1index445, std::array<u64,10>{v_c110, v_c3, v_c8, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m496) {
          u64 v_c2 = m496[3]; u64 v_c111 = m496[4]; u64 v_c4 = m496[5]; u64 v_c9 = m496[6]; u64 v_c5 = m496[7]; u64 v_c10 = m496[8]; u64 v_c11 = m496[9];
          u64 v_c112 = _prim_lt(db, v_c9, v_c3);
          if (v_c112 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
          if (!v_c112) return;
          slog::join_probe<9,9>($sup9688x106x0x0x0index446, std::array<u64,9>{v_c2, v_c4, v_c3, v_c5, v_c111, v_c9, v_c8, v_c10, v_c11}, [&](const std::array<u64,9>& m498) {
            if (!slog::exists_probe<5,4>(pbranchindex447, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex448, std::array<u64,2>{v_c110, v_c2})) return;
            if (!slog::exists_probe<3,1>(st_unionindex449, std::array<u64,3>{v_c5, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex450, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m499) {
              u64 v_c113 = m499[4];
              if (!slog::exists_probe<3,2>(st_unionindex451, std::array<u64,3>{v_c111, v_c113, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex452, pbranchdelta457, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m500) {
                u64 v_c114 = m500[4];
                slog::join_probe<3,3>(st_unionindex453, std::array<u64,3>{v_c111, v_c113, v_c114}, [&](const std::array<u64,3>& m501) {
                  slog::join_probe<2,2>(st_msk_ansindex454, std::array<u64,2>{v_c110, v_c2}, [&](const std::array<u64,2>& m502) {
                    slog::join_probe_old<3,2>(st_unionindex455, st_uniondelta458, std::array<u64,3>{v_c5, v_c114, 0}, [&](const std::array<u64,3>& m503) {
                      u64 v_c115 = m503[2];
                      slog::join_probe<2,1>(st_union_ansindex456, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m504) {
                        u64 v_c22 = m504[1];
                        u64 v_c116 = _prim_band(db, v_c8, v_c3);
                        if (v_c116 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c117 = _prim_gt(db, v_c116, v_c109);
                        if (v_c117 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c117) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c111, v_c22, v_c4, v_c3, v_c2});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c4, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask459* _cont = new ReadTask459(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask459(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan st_union __t0ttd124 __t32HA128 __t43ng122) (body (exists $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) 1 __t0ttd124) (exists $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) 1 __t0ttd124) (join-old st_union (1 2 0) 1 (1 2 0) __t32HA128 v __t4LMh129) (exists $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0ttd124 v) (exists $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t0ttd124 v) (exists st_union_ans (0 1) 1 __t4LMh129) (join pbranch (4 0 1 2 3) 2 v __t43ng122 q n u) (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t0ttd124) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0ttd124 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t32HA128) (exists st_msk (1 2 0) 2 p n) (join $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t0ttd124 l m p r __t3TTE127) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t32HA128) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask527 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x0index506;  slog::Index** $sup9688x117x0x0x1index507;  slog::Index** st_unionindex508;  slog::Index** $sup9688x117x0x0x0index509;  slog::Index** $sup9688x117x0x0x1index510;  slog::Index** st_union_ansindex511;  slog::Index** pbranchindex512;  slog::Index** $sup9688x117x0x0x1index513;  slog::Index** st_mskindex514;  slog::Index** st_msk_ansindex515;  slog::Index** $sup9688x117x0x0x0index516;  slog::Index** pbranchindex517;  slog::Index** st_mskindex518;  slog::Index** $sup9688x117x0x0x1index519;  slog::Index** pbranchindex520;  slog::Index** st_mskindex521;  slog::Index** st_msk_ansindex522;  slog::Index** st_union_ansindex523;  slog::Index** st_uniondelta524;  slog::Index** pbranchdelta525;  slog::Index** st_mskdelta526;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord528({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel529 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index506 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel531 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index507 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("st_union");
      st_unionindex508 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("st_union");
      st_uniondelta524 = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel537 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index509 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel539 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index510 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({0, 1});
      slog::Relation* readrel541 = db->getRelation("st_union_ans");
      st_union_ansindex511 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({4, 0, 1, 2, 3});
      slog::Relation* readrel543 = db->getRelation("pbranch");
      pbranchindex512 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel545 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index513 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({2, 0, 1});
      slog::Relation* readrel547 = db->getRelation("st_msk");
      st_mskindex514 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 0});
      slog::Relation* readrel549 = db->getRelation("st_msk_ans");
      st_msk_ansindex515 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel551 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index516 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 3, 4, 0});
      slog::Relation* readrel553 = db->getRelation("pbranch");
      pbranchindex517 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 0});
      slog::Relation* readrel555 = db->getRelation("st_msk");
      st_mskindex518 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel557 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index519 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 2, 3, 4, 0});
      slog::Relation* readrel559 = db->getRelation("pbranch");
      pbranchindex520 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 3, 4, 0});
      slog::Relation* readrel561 = db->getRelation("pbranch");
      pbranchdelta525 = readrel561->getIndex(ord560, true);
      std::vector<u16> ord562({1, 2, 0});
      slog::Relation* readrel563 = db->getRelation("st_msk");
      st_mskindex521 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 0});
      slog::Relation* readrel565 = db->getRelation("st_msk");
      st_mskdelta526 = readrel565->getIndex(ord564, true);
      std::vector<u16> ord566({0, 1});
      slog::Relation* readrel567 = db->getRelation("st_msk_ans");
      st_msk_ansindex522 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({0, 1});
      slog::Relation* readrel569 = db->getRelation("st_union_ans");
      st_union_ansindex523 = readrel569->getIndex(ord568, false);
  
    }
    ReadTask527(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x117x0x0x0index506, std::array<u64,9>{v_c119, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x117x0x0x1index507, std::array<u64,10>{v_c119, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex508, st_uniondelta524, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m570) {
          u64 v_c11 = m570[1]; u64 v_c122 = m570[2];
          if (!slog::exists_probe<9,2>($sup9688x117x0x0x0index509, std::array<u64,9>{v_c119, v_c11, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup9688x117x0x0x1index510, std::array<u64,10>{v_c119, v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_union_ansindex511, std::array<u64,2>{v_c122, 0})) return;
          slog::join_probe<5,2>(pbranchindex512, std::array<u64,5>{v_c11, v_c121, 0, 0, 0}, [&](const std::array<u64,5>& m571) {
            u64 v_c8 = m571[2]; u64 v_c9 = m571[3]; u64 v_c10 = m571[4];
            if (!slog::exists_probe<10,5>($sup9688x117x0x0x1index513, std::array<u64,10>{v_c11, v_c9, v_c8, v_c10, v_c119, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex514, std::array<u64,3>{v_c9, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex515, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe<9,5>($sup9688x117x0x0x0index516, std::array<u64,9>{v_c8, v_c9, v_c10, v_c11, v_c119, 0, 0, 0, 0}, [&](const std::array<u64,9>& m572) {
              u64 v_c4 = m572[5]; u64 v_c3 = m572[6]; u64 v_c2 = m572[7]; u64 v_c5 = m572[8];
              u64 v_c123 = _prim_lt(db, v_c3, v_c9);
              if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
              if (!v_c123) return;
              if (!slog::exists_probe<5,5>(pbranchindex517, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c120})) return;
              if (!slog::exists_probe<3,2>(st_mskindex518, std::array<u64,3>{v_c2, v_c9, 0})) return;
              slog::join_probe<10,9>($sup9688x117x0x0x1index519, std::array<u64,10>{v_c11, v_c9, v_c8, v_c10, v_c119, v_c4, v_c3, v_c2, v_c5, 0}, [&](const std::array<u64,10>& m574) {
                u64 v_c124 = m574[9];
                slog::join_probe_old<5,5>(pbranchindex520, pbranchdelta525, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c120}, [&](const std::array<u64,5>& m575) {
                  slog::join_probe_old<3,3>(st_mskindex521, st_mskdelta526, std::array<u64,3>{v_c2, v_c9, v_c124}, [&](const std::array<u64,3>& m576) {
                    slog::join_probe<2,2>(st_msk_ansindex522, std::array<u64,2>{v_c124, v_c8}, [&](const std::array<u64,2>& m577) {
                      slog::join_probe<2,1>(st_union_ansindex523, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m578) {
                        u64 v_c22 = m578[1];
                        u64 v_c125 = _prim_band(db, v_c2, v_c9);
                        if (v_c125 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c126 = _prim_gt(db, v_c125, v_c118);
                        if (v_c126 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c126) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c119, v_c22, v_c9, v_c8, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c10, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask527* _cont = new ReadTask527(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask527(db,b), false);
  // (crule (pre (let __tconst7OE6425 const5feceb66ffc86f38d952786c)) (scan pleaf __t2KDy422 k) (body (exists st_mem0 (2 0 1) 1 k) (exists st_diff (1 2 0) 1 __t2KDy422) (join st_mem0_ans (1 0) 1 __tconst7OE6425 __t32gs424) (join-old st_mem0 (2 0 1) 2 (2 0 1) k __t32gs424 t) (join-old st_diff (1 2 0) 2 (1 2 0) __t2KDy422 t __t2CPR423)) (head (emit st_diff_ans (0 1) __t2CPR423 __t2KDy422)) set.slog:134 #f)
  class ReadTask587 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index580;  slog::Index** st_diffindex581;  slog::Index** st_mem0_ansindex582;  slog::Index** st_mem0index583;  slog::Index** st_diffindex584;  slog::Index** st_mem0delta585;  slog::Index** st_diffdelta586;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord588({0, 1});
      slog::Relation* readrel589 = db->getRelation("st_diff_ans");
      head_index[0] = readrel589->getIndex(ord588, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord590({2, 0, 1});
      slog::Relation* readrel591 = db->getRelation("st_mem0");
      st_mem0index580 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 0});
      slog::Relation* readrel593 = db->getRelation("st_diff");
      st_diffindex581 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex582 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({2, 0, 1});
      slog::Relation* readrel597 = db->getRelation("st_mem0");
      st_mem0index583 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({2, 0, 1});
      slog::Relation* readrel599 = db->getRelation("st_mem0");
      st_mem0delta585 = readrel599->getIndex(ord598, true);
      std::vector<u16> ord600({1, 2, 0});
      slog::Relation* readrel601 = db->getRelation("st_diff");
      st_diffindex584 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("st_diff");
      st_diffdelta586 = readrel603->getIndex(ord602, true);
  
    }
    ReadTask587(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c127 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c128 = _t[0];
        u64 v_c32 = _t[1];
        if (!slog::exists_probe<3,1>(st_mem0index580, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex581, std::array<u64,3>{v_c128, 0, 0})) return;
        slog::join_probe<2,1>(st_mem0_ansindex582, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m604) {
          u64 v_c129 = m604[1];
          slog::join_probe_old<3,2>(st_mem0index583, st_mem0delta585, std::array<u64,3>{v_c32, v_c129, 0}, [&](const std::array<u64,3>& m605) {
            u64 v_c130 = m605[2];
            slog::join_probe_old<3,2>(st_diffindex584, st_diffdelta586, std::array<u64,3>{v_c128, v_c130, 0}, [&](const std::array<u64,3>& m606) {
              u64 v_c131 = m606[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c128}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask587* _cont = new ReadTask587(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask587(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t19Mr339 p) (body (exists $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (exists st_bld (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t19Mr339 q m) (exists pbranch (1 2 3 4 0) 2 p m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_bld (1 2 3 4 0) 2 p m) (join-old $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 3 (2 5 4 0 1 3 6 7 8) m q p __t8Fy1335 l n r u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_diff (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t88zt334) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join-old st_diff (0 1 2) 3 (0 1 2) __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t7XLn338) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join-old st_diff_ans (0 1) 2 (0 1) __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask637 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index607;  slog::Index** pbranchindex608;  slog::Index** st_bldindex609;  slog::Index** st_mskindex610;  slog::Index** pbranchindex611;  slog::Index** pbranchindex612;  slog::Index** st_bldindex613;  slog::Index** $sup9688x142x0x0x0index614;  slog::Index** pbranchindex615;  slog::Index** st_bldindex616;  slog::Index** st_diffindex617;  slog::Index** pbranchindex618;  slog::Index** st_diffindex619;  slog::Index** pbranchindex620;  slog::Index** st_diffindex621;  slog::Index** st_diffindex622;  slog::Index** st_bldindex623;  slog::Index** st_diff_ansindex624;  slog::Index** st_bld_ansindex625;  slog::Index** st_diffindex626;  slog::Index** st_diff_ansindex627;  slog::Index** st_bld_ansindex628;  slog::Index** st_mskdelta629;  slog::Index** $sup9688x142x0x0x0delta630;  slog::Index** pbranchdelta631;  slog::Index** pbranchdelta632;  slog::Index** st_diffdelta633;  slog::Index** st_blddelta634;  slog::Index** st_diffdelta635;  slog::Index** st_diff_ansdelta636;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord638({0, 1});
      slog::Relation* readrel639 = db->getRelation("st_diff_ans");
      head_index[0] = readrel639->getIndex(ord638, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord640({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel641 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index607 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 3, 4, 0});
      slog::Relation* readrel643 = db->getRelation("pbranch");
      pbranchindex608 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 3, 4, 0});
      slog::Relation* readrel645 = db->getRelation("st_bld");
      st_bldindex609 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1, 2});
      slog::Relation* readrel647 = db->getRelation("st_msk");
      st_mskindex610 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1, 2});
      slog::Relation* readrel649 = db->getRelation("st_msk");
      st_mskdelta629 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({1, 2, 3, 4, 0});
      slog::Relation* readrel651 = db->getRelation("pbranch");
      pbranchindex611 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 3, 4, 0});
      slog::Relation* readrel653 = db->getRelation("pbranch");
      pbranchindex612 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 3, 4, 0});
      slog::Relation* readrel655 = db->getRelation("st_bld");
      st_bldindex613 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel657 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index614 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel659 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0delta630 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({1, 2, 3, 4, 0});
      slog::Relation* readrel661 = db->getRelation("pbranch");
      pbranchindex615 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 3, 4, 0});
      slog::Relation* readrel663 = db->getRelation("st_bld");
      st_bldindex616 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("st_diff");
      st_diffindex617 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 3, 4, 0});
      slog::Relation* readrel667 = db->getRelation("pbranch");
      pbranchindex618 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 3, 4, 0});
      slog::Relation* readrel669 = db->getRelation("pbranch");
      pbranchdelta631 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({0, 1, 2});
      slog::Relation* readrel671 = db->getRelation("st_diff");
      st_diffindex619 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 3, 4, 0});
      slog::Relation* readrel673 = db->getRelation("pbranch");
      pbranchindex620 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 3, 4, 0});
      slog::Relation* readrel675 = db->getRelation("pbranch");
      pbranchdelta632 = readrel675->getIndex(ord674, true);
      std::vector<u16> ord676({0, 1, 2});
      slog::Relation* readrel677 = db->getRelation("st_diff");
      st_diffindex621 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({0, 1, 2});
      slog::Relation* readrel679 = db->getRelation("st_diff");
      st_diffdelta633 = readrel679->getIndex(ord678, true);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("st_diff");
      st_diffindex622 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 3, 4, 0});
      slog::Relation* readrel683 = db->getRelation("st_bld");
      st_bldindex623 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 3, 4, 0});
      slog::Relation* readrel685 = db->getRelation("st_bld");
      st_blddelta634 = readrel685->getIndex(ord684, true);
      std::vector<u16> ord686({1, 0});
      slog::Relation* readrel687 = db->getRelation("st_diff_ans");
      st_diff_ansindex624 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("st_bld_ans");
      st_bld_ansindex625 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 0});
      slog::Relation* readrel691 = db->getRelation("st_diff");
      st_diffindex626 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("st_diff");
      st_diffdelta635 = readrel693->getIndex(ord692, true);
      std::vector<u16> ord694({0, 1});
      slog::Relation* readrel695 = db->getRelation("st_diff_ans");
      st_diff_ansindex627 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("st_diff_ans");
      st_diff_ansdelta636 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("st_bld_ans");
      st_bld_ansindex628 = readrel699->getIndex(ord698, false);
  
    }
    ReadTask637(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index607, std::array<u64,9>{v_c2, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex608, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex609, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex610, st_mskdelta629, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m700) {
          u64 v_c8 = m700[1]; u64 v_c3 = m700[2];
          if (!slog::exists_probe<5,2>(pbranchindex611, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex612, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex613, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          slog::join_probe_old<9,3>($sup9688x142x0x0x0index614, $sup9688x142x0x0x0delta630, std::array<u64,9>{v_c3, v_c8, v_c2, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m701) {
            u64 v_c134 = m701[3]; u64 v_c4 = m701[4]; u64 v_c9 = m701[5]; u64 v_c5 = m701[6]; u64 v_c10 = m701[7]; u64 v_c11 = m701[8];
            u64 v_c135 = _prim_lt(db, v_c9, v_c3);
            if (v_c135 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c135) return;
            if (!slog::exists_probe<5,4>(pbranchindex615, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex616, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex617, std::array<u64,3>{v_c5, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex618, pbranchdelta631, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m703) {
              u64 v_c136 = m703[4];
              if (!slog::exists_probe<3,2>(st_diffindex619, std::array<u64,3>{v_c134, v_c136, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex620, pbranchdelta632, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m704) {
                u64 v_c137 = m704[4];
                slog::join_probe_old<3,3>(st_diffindex621, st_diffdelta633, std::array<u64,3>{v_c134, v_c136, v_c137}, [&](const std::array<u64,3>& m705) {
                  if (!slog::exists_probe<3,2>(st_diffindex622, std::array<u64,3>{v_c5, v_c137, 0})) return;
                  slog::join_probe_old<5,3>(st_bldindex623, st_blddelta634, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0}, [&](const std::array<u64,5>& m706) {
                    u64 v_c22 = m706[3]; u64 v_c138 = m706[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex624, std::array<u64,2>{v_c22, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex625, std::array<u64,2>{v_c138, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex626, st_diffdelta635, std::array<u64,3>{v_c5, v_c137, 0}, [&](const std::array<u64,3>& m707) {
                      u64 v_c139 = m707[2];
                      slog::join_probe_old<2,2>(st_diff_ansindex627, st_diff_ansdelta636, std::array<u64,2>{v_c139, v_c22}, [&](const std::array<u64,2>& m708) {
                        slog::join_probe<2,1>(st_bld_ansindex628, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m709) {
                          u64 v_c106 = m709[1];
                          u64 v_c140 = _prim_band(db, v_c8, v_c3);
                          if (v_c140 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c141 = _prim_gt(db, v_c140, v_c132);
                          if (v_c141 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c141) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c106}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask637* _cont = new ReadTask637(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask637(db,b), false);
  // (crule (pre (let __trid8ixp997 const35c71810897f279c2099acbb) (let __trel9AeA998 const94d9c4e2675ef4bd8443d499) (let __tcol3NE6999 const5feceb66ffc86f38d952786c) (let __trel7fpi1000 const94d9c4e2675ef4bd8443d499) (let __tcol4x4G1001 const6b86b273ff34fce19d6b804e)) (scan $sup9688x100x0x0x0 __d0 l m p r u v) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8ixp997 __trel9AeA998 __tcol3NE6999 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8ixp997 __trel7fpi1000 __tcol4x4G1001 (1 2 3 4 0)) (mkstruct st_union (1 2 0) __3fvo996 l u)) set.slog:101 #f)
  class ReadTask714 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid712;  u32 sid711;  u32 sid713;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_union");
      outer_rel = db->getRelation("$sup9688x100x0x0x0");
      sid712 = db->getRelation("_enum")->getStructId();
      sid711 = db->getRelation("pbranch")->getStructId();
      sid713 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask714(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const35c71810897f279c2099acbb;
      u64 v_c143 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c146 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c5 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c11 = _t[6];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid711 || decode_struct_id(v_c4) == sid712 || decode_struct_id(v_c4) == sid713))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c142, v_c143, v_c144, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid711 || decode_struct_id(v_c10) == sid712 || decode_struct_id(v_c10) == sid713))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c142, v_c145, v_c146, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:$sup9688x100x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask714* _cont = new ReadTask714(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask714(db,b), false);
  // (crule (pre) (scan st_diff __t6cu0410 l u) (body (exists $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 l u) (exists pbranch (3 0 1 2 4) 1 u) (exists pbranch (3 0 1 2 4) 1 l) (join st_diff_ans (0 1) 1 __t6cu0410 __v0) (exists st_bld (3 0 1 2 4) 1 __v0) (join $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 l u __t5pD6408 m p r v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_bld (1 2 3 4 0) 3 p m __v0) (exists st_diff (1 2 0) 2 r v) (join pbranch (1 2 3 4 0) 4 p m u v __t9ous406) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (join pbranch (1 2 3 4 0) 4 p m l r __t3cJ7407) (join st_diff (0 1 2) 3 __t5pD6408 __t3cJ7407 __t9ous406) (join st_bld (1 2 3 4 0) 3 p m __v0 __v1 __t9obY409) (exists st_diff_ans (1 0) 1 __v1) (exists st_bld_ans (0 1) 1 __t9obY409) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask735 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index715;  slog::Index** pbranchindex716;  slog::Index** pbranchindex717;  slog::Index** st_diff_ansindex718;  slog::Index** st_bldindex719;  slog::Index** $sup9688x136x0x0x0index720;  slog::Index** pbranchindex721;  slog::Index** st_bldindex722;  slog::Index** st_diffindex723;  slog::Index** pbranchindex724;  slog::Index** st_diffindex725;  slog::Index** pbranchindex726;  slog::Index** st_diffindex727;  slog::Index** st_bldindex728;  slog::Index** st_diff_ansindex729;  slog::Index** st_bld_ansindex730;  slog::Index** st_diffindex731;  slog::Index** st_diff_ansindex732;  slog::Index** st_bld_ansindex733;  slog::Index** st_diffdelta734;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord736({0, 1});
      slog::Relation* readrel737 = db->getRelation("st_diff_ans");
      head_index[0] = readrel737->getIndex(ord736, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord738({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel739 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index715 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({3, 0, 1, 2, 4});
      slog::Relation* readrel741 = db->getRelation("pbranch");
      pbranchindex716 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({3, 0, 1, 2, 4});
      slog::Relation* readrel743 = db->getRelation("pbranch");
      pbranchindex717 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("st_diff_ans");
      st_diff_ansindex718 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({3, 0, 1, 2, 4});
      slog::Relation* readrel747 = db->getRelation("st_bld");
      st_bldindex719 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel749 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index720 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 3, 4, 0});
      slog::Relation* readrel751 = db->getRelation("pbranch");
      pbranchindex721 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 3, 4, 0});
      slog::Relation* readrel753 = db->getRelation("st_bld");
      st_bldindex722 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 0});
      slog::Relation* readrel755 = db->getRelation("st_diff");
      st_diffindex723 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 2, 3, 4, 0});
      slog::Relation* readrel757 = db->getRelation("pbranch");
      pbranchindex724 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({2, 0, 1});
      slog::Relation* readrel759 = db->getRelation("st_diff");
      st_diffindex725 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 2, 3, 4, 0});
      slog::Relation* readrel761 = db->getRelation("pbranch");
      pbranchindex726 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({0, 1, 2});
      slog::Relation* readrel763 = db->getRelation("st_diff");
      st_diffindex727 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 3, 4, 0});
      slog::Relation* readrel765 = db->getRelation("st_bld");
      st_bldindex728 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 0});
      slog::Relation* readrel767 = db->getRelation("st_diff_ans");
      st_diff_ansindex729 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({0, 1});
      slog::Relation* readrel769 = db->getRelation("st_bld_ans");
      st_bld_ansindex730 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({1, 2, 0});
      slog::Relation* readrel771 = db->getRelation("st_diff");
      st_diffindex731 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 2, 0});
      slog::Relation* readrel773 = db->getRelation("st_diff");
      st_diffdelta734 = readrel773->getIndex(ord772, true);
      std::vector<u16> ord774({0, 1});
      slog::Relation* readrel775 = db->getRelation("st_diff_ans");
      st_diff_ansindex732 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({0, 1});
      slog::Relation* readrel777 = db->getRelation("st_bld_ans");
      st_bld_ansindex733 = readrel777->getIndex(ord776, false);
  
    }
    ReadTask735(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c147 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index715, std::array<u64,7>{v_c4, v_c10, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex716, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex717, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex718, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m778) {
          u64 v_c22 = m778[1];
          if (!slog::exists_probe<5,1>(st_bldindex719, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          slog::join_probe<7,2>($sup9688x136x0x0x0index720, std::array<u64,7>{v_c4, v_c10, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m779) {
            u64 v_c148 = m779[2]; u64 v_c3 = m779[3]; u64 v_c2 = m779[4]; u64 v_c5 = m779[5]; u64 v_c11 = m779[6];
            if (!slog::exists_probe<5,4>(pbranchindex721, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex722, std::array<u64,5>{v_c2, v_c3, v_c22, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex723, std::array<u64,3>{v_c5, v_c11, 0})) return;
            slog::join_probe<5,4>(pbranchindex724, std::array<u64,5>{v_c2, v_c3, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m780) {
              u64 v_c149 = m780[4];
              if (!slog::exists_probe<3,2>(st_diffindex725, std::array<u64,3>{v_c149, v_c148, 0})) return;
              slog::join_probe<5,4>(pbranchindex726, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m781) {
                u64 v_c150 = m781[4];
                slog::join_probe<3,3>(st_diffindex727, std::array<u64,3>{v_c148, v_c150, v_c149}, [&](const std::array<u64,3>& m782) {
                  slog::join_probe<5,3>(st_bldindex728, std::array<u64,5>{v_c2, v_c3, v_c22, 0, 0}, [&](const std::array<u64,5>& m783) {
                    u64 v_c69 = m783[3]; u64 v_c151 = m783[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex729, std::array<u64,2>{v_c69, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex730, std::array<u64,2>{v_c151, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex731, st_diffdelta734, std::array<u64,3>{v_c5, v_c11, 0}, [&](const std::array<u64,3>& m784) {
                      u64 v_c152 = m784[2];
                      slog::join_probe<2,2>(st_diff_ansindex732, std::array<u64,2>{v_c152, v_c69}, [&](const std::array<u64,2>& m785) {
                        slog::join_probe<2,1>(st_bld_ansindex733, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m786) {
                          u64 v_c106 = m786[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c106}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask735* _cont = new ReadTask735(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask735(db,b), false);
  // (crule (pre) (scan pleaf __t65ux428 k) (body (exists st_ins (2 0 1) 1 k) (join-old st_union (2 0 1) 1 (2 0 1) __t65ux428 __t8LrU429 s) (join-old st_ins (1 2 0) 2 (1 2 0) s k __t7Z9l430) (join st_ins_ans (0 1) 1 __t7Z9l430 r)) (head (emit st_union_ans (0 1) __t8LrU429 r)) set.slog:99 #f)
  class ReadTask793 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex787;  slog::Index** st_unionindex788;  slog::Index** st_insindex789;  slog::Index** st_ins_ansindex790;  slog::Index** st_uniondelta791;  slog::Index** st_insdelta792;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("st_union_ans");
      head_index[0] = readrel795->getIndex(ord794, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord796({2, 0, 1});
      slog::Relation* readrel797 = db->getRelation("st_ins");
      st_insindex787 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({2, 0, 1});
      slog::Relation* readrel799 = db->getRelation("st_union");
      st_unionindex788 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({2, 0, 1});
      slog::Relation* readrel801 = db->getRelation("st_union");
      st_uniondelta791 = readrel801->getIndex(ord800, true);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("st_ins");
      st_insindex789 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("st_ins");
      st_insdelta792 = readrel805->getIndex(ord804, true);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("st_ins_ans");
      st_ins_ansindex790 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask793(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c153 = _t[0];
        u64 v_c32 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex787, std::array<u64,3>{v_c32, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex788, st_uniondelta791, std::array<u64,3>{v_c153, 0, 0}, [&](const std::array<u64,3>& m808) {
          u64 v_c154 = m808[1]; u64 v_c155 = m808[2];
          slog::join_probe_old<3,2>(st_insindex789, st_insdelta792, std::array<u64,3>{v_c155, v_c32, 0}, [&](const std::array<u64,3>& m809) {
            u64 v_c156 = m809[2];
            slog::join_probe<2,1>(st_ins_ansindex790, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m810) {
              u64 v_c5 = m810[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c154, v_c5}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask793* _cont = new ReadTask793(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask793(db,b), false);
  // (crule (pre (let __tconst01np70 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t2gxF69 __t3Sw268 k) (body (join pbranch (0 1 2 3 4) 1 __t3Sw268 p m l r) (let __t3fsQ71 (band k m)) (cmp gt __t3fsQ71 __tconst01np70)) (head (emit $sup9688x72x0x0x0 (4 2 3 5 0 1) p l m r __t2gxF69 k)) set.slog:73 #f)
  class ReadTask812 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex811;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord813({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel814 = db->getRelation("$sup9688x72x0x0x0");
      head_index[0] = readrel814->getIndex(ord813, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord815({0, 1, 2, 3, 4});
      slog::Relation* readrel816 = db->getRelation("pbranch");
      pbranchindex811 = readrel816->getIndex(ord815, false);
  
    }
    ReadTask812(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c158 = _t[0];
        u64 v_c159 = _t[1];
        u64 v_c32 = _t[2];
        slog::join_probe<5,1>(pbranchindex811, std::array<u64,5>{v_c159, 0, 0, 0, 0}, [&](const std::array<u64,5>& m817) {
          u64 v_c2 = m817[1]; u64 v_c3 = m817[2]; u64 v_c4 = m817[3]; u64 v_c5 = m817[4];
          u64 v_c160 = _prim_band(db, v_c32, v_c3);
          if (v_c160 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
          u64 v_c161 = _prim_gt(db, v_c160, v_c157);
          if (v_c161 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
          if (!v_c161) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c4, v_c3, v_c5, v_c158, v_c32}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:st_mem0", _fires);
  
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
  // (crule (pre (let __tconst9NmC41 const6b86b273ff34fce19d6b804e)) (scan pbranch __t4Scw39 p m l r) (body (join-old st_union (1 2 0) 1 (1 2 0) __t4Scw39 __t6Xp338 __t2Ywo40) (join pbranch (0 1 2 3 4) 1 __t6Xp338 q n u v) (cmp lt m n) (let __t6HP242 (band p n)) (cmp lt __t6HP242 __tconst9NmC41)) (head (emit $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) __t2Ywo40 u l m n p q r v)) set.slog:115 #f)
  class ReadTask822 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex819;  slog::Index** pbranchindex820;  slog::Index** st_uniondelta821;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord823({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel824 = db->getRelation("$sup9688x114x0x0x0");
      head_index[0] = readrel824->getIndex(ord823, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("st_union");
      st_unionindex819 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 2, 0});
      slog::Relation* readrel828 = db->getRelation("st_union");
      st_uniondelta821 = readrel828->getIndex(ord827, true);
      std::vector<u16> ord829({0, 1, 2, 3, 4});
      slog::Relation* readrel830 = db->getRelation("pbranch");
      pbranchindex820 = readrel830->getIndex(ord829, false);
  
    }
    ReadTask822(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c162 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c163 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex819, st_uniondelta821, std::array<u64,3>{v_c163, 0, 0}, [&](const std::array<u64,3>& m831) {
          u64 v_c164 = m831[1]; u64 v_c165 = m831[2];
          slog::join_probe<5,1>(pbranchindex820, std::array<u64,5>{v_c164, 0, 0, 0, 0}, [&](const std::array<u64,5>& m832) {
            u64 v_c8 = m832[1]; u64 v_c9 = m832[2]; u64 v_c10 = m832[3]; u64 v_c11 = m832[4];
            u64 v_c166 = _prim_lt(db, v_c3, v_c9);
            if (v_c166 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c166) return;
            u64 v_c167 = _prim_band(db, v_c2, v_c9);
            if (v_c167 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            u64 v_c168 = _prim_lt(db, v_c167, v_c162);
            if (v_c168 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c168) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c165, v_c10, v_c4, v_c3, v_c9, v_c2, v_c8, v_c5, v_c11}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask822* _cont = new ReadTask822(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask822(db,b), false);
  // (crule (pre (let __trid0O8l910 const1e44311dd5d36c3a7dc21dfa) (let __trel2X7j911 const26c89ee8ccc4ea998fd1a912) (let __tcol3tdZ912 constd4735e3a265e16eee03f5971)) (scan st_del_ans __t56Eo399 __v0) (body (join-old st_del (0 2 1) 1 (0 2 1) __t56Eo399 k r) (exists st_msk (1 2 0) 1 k) (join $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t8Ytg398) (join st_msk_ans (0 1) 2 __t8Ytg398 p)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0O8l910 __trel2X7j911 __tcol3tdZ912 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __6yFQ909 p m l __v0)) set.slog:91 #f)
  class ReadTask846 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex835;  slog::Index** st_mskindex836;  slog::Index** $sup9688x90x0x0x0index837;  slog::Index** st_msk_ansindex838;  slog::Index** st_mskindex839;  slog::Index** st_msk_ansindex840;  slog::Index** st_deldelta841;  slog::Index** st_mskdelta842;
    u32 sid844;  u32 sid843;  u32 sid845;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_del_ans");
      std::vector<u16> ord847({0, 2, 1});
      slog::Relation* readrel848 = db->getRelation("st_del");
      st_delindex835 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({0, 2, 1});
      slog::Relation* readrel850 = db->getRelation("st_del");
      st_deldelta841 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({1, 2, 0});
      slog::Relation* readrel852 = db->getRelation("st_msk");
      st_mskindex836 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel854 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index837 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 0});
      slog::Relation* readrel856 = db->getRelation("st_msk_ans");
      st_msk_ansindex838 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 0});
      slog::Relation* readrel858 = db->getRelation("st_msk");
      st_mskindex839 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("st_msk");
      st_mskdelta842 = readrel860->getIndex(ord859, true);
      std::vector<u16> ord861({0, 1});
      slog::Relation* readrel862 = db->getRelation("st_msk_ans");
      st_msk_ansindex840 = readrel862->getIndex(ord861, false);
      sid844 = db->getRelation("_enum")->getStructId();
      sid843 = db->getRelation("pbranch")->getStructId();
      sid845 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask846(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c169 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c170 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c171 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c172 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(st_delindex835, st_deldelta841, std::array<u64,3>{v_c172, 0, 0}, [&](const std::array<u64,3>& m863) {
          u64 v_c32 = m863[1]; u64 v_c5 = m863[2];
          if (!slog::exists_probe<3,1>(st_mskindex836, std::array<u64,3>{v_c32, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x90x0x0x0index837, std::array<u64,6>{v_c32, v_c5, 0, 0, 0, 0}, [&](const std::array<u64,6>& m864) {
            u64 v_c16 = m864[2]; u64 v_c4 = m864[3]; u64 v_c3 = m864[4]; u64 v_c2 = m864[5];
            if (!slog::exists_probe<2,1>(st_msk_ansindex838, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(st_mskindex839, st_mskdelta842, std::array<u64,3>{v_c32, v_c3, 0}, [&](const std::array<u64,3>& m865) {
              u64 v_c173 = m865[2];
              slog::join_probe<2,2>(st_msk_ansindex840, std::array<u64,2>{v_c173, v_c2}, [&](const std::array<u64,2>& m866) {
                ++_fires;
                if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid843 || decode_struct_id(v_c4) == sid844 || decode_struct_id(v_c4) == sid845))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c169, v_c170, v_c171, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c4, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del_ans", _fires);
  
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
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan pbranch __t66RN158 p m l r) (body (exists st_diff (1 2 0) 1 __t66RN158) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 l) (join $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 4 p m r l __t3X8M159 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join-old st_diff (0 1 2) 3 (0 1 2) __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t1RXD162 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask891 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex867;  slog::Index** st_bldindex868;  slog::Index** st_mskindex869;  slog::Index** st_msk_ansindex870;  slog::Index** st_diffindex871;  slog::Index** $sup9688x139x0x0x0index872;  slog::Index** st_diffindex873;  slog::Index** st_mskindex874;  slog::Index** pbranchindex875;  slog::Index** st_diffindex876;  slog::Index** st_diffindex877;  slog::Index** st_bldindex878;  slog::Index** st_diff_ansindex879;  slog::Index** st_bld_ansindex880;  slog::Index** st_mskindex881;  slog::Index** st_msk_ansindex882;  slog::Index** st_diffindex883;  slog::Index** st_diff_ansindex884;  slog::Index** st_bld_ansindex885;  slog::Index** pbranchdelta886;  slog::Index** st_diffdelta887;  slog::Index** st_blddelta888;  slog::Index** st_mskdelta889;  slog::Index** st_diffdelta890;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("st_diff_ans");
      head_index[0] = readrel893->getIndex(ord892, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord894({1, 2, 0});
      slog::Relation* readrel895 = db->getRelation("st_diff");
      st_diffindex867 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({2, 1, 4, 0, 3});
      slog::Relation* readrel897 = db->getRelation("st_bld");
      st_bldindex868 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({2, 0, 1});
      slog::Relation* readrel899 = db->getRelation("st_msk");
      st_mskindex869 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 0});
      slog::Relation* readrel901 = db->getRelation("st_msk_ans");
      st_msk_ansindex870 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("st_diff");
      st_diffindex871 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel905 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index872 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("st_diff");
      st_diffindex873 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 2, 0});
      slog::Relation* readrel909 = db->getRelation("st_msk");
      st_mskindex874 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 3, 4, 0});
      slog::Relation* readrel911 = db->getRelation("pbranch");
      pbranchindex875 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 3, 4, 0});
      slog::Relation* readrel913 = db->getRelation("pbranch");
      pbranchdelta886 = readrel913->getIndex(ord912, true);
      std::vector<u16> ord914({0, 1, 2});
      slog::Relation* readrel915 = db->getRelation("st_diff");
      st_diffindex876 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({0, 1, 2});
      slog::Relation* readrel917 = db->getRelation("st_diff");
      st_diffdelta887 = readrel917->getIndex(ord916, true);
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("st_diff");
      st_diffindex877 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({2, 1, 4, 0, 3});
      slog::Relation* readrel921 = db->getRelation("st_bld");
      st_bldindex878 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({2, 1, 4, 0, 3});
      slog::Relation* readrel923 = db->getRelation("st_bld");
      st_blddelta888 = readrel923->getIndex(ord922, true);
      std::vector<u16> ord924({1, 0});
      slog::Relation* readrel925 = db->getRelation("st_diff_ans");
      st_diff_ansindex879 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({0, 1});
      slog::Relation* readrel927 = db->getRelation("st_bld_ans");
      st_bld_ansindex880 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("st_msk");
      st_mskindex881 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("st_msk");
      st_mskdelta889 = readrel931->getIndex(ord930, true);
      std::vector<u16> ord932({0, 1});
      slog::Relation* readrel933 = db->getRelation("st_msk_ans");
      st_msk_ansindex882 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("st_diff");
      st_diffindex883 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("st_diff");
      st_diffdelta890 = readrel937->getIndex(ord936, true);
      std::vector<u16> ord938({0, 1});
      slog::Relation* readrel939 = db->getRelation("st_diff_ans");
      st_diff_ansindex884 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({0, 1});
      slog::Relation* readrel941 = db->getRelation("st_bld_ans");
      st_bld_ansindex885 = readrel941->getIndex(ord940, false);
  
    }
    ReadTask891(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c175 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex867, std::array<u64,3>{v_c175, 0, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex868, std::array<u64,5>{v_c3, v_c2, v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex869, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex870, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex871, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x139x0x0x0index872, std::array<u64,9>{v_c2, v_c3, v_c5, v_c4, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m942) {
          u64 v_c176 = m942[4]; u64 v_c9 = m942[5]; u64 v_c8 = m942[6]; u64 v_c10 = m942[7]; u64 v_c11 = m942[8];
          u64 v_c177 = _prim_lt(db, v_c9, v_c3);
          if (v_c177 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
          if (!v_c177) return;
          if (!slog::exists_probe<3,2>(st_diffindex873, std::array<u64,3>{v_c176, v_c175, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex874, std::array<u64,3>{v_c8, v_c3, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex875, pbranchdelta886, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m944) {
            u64 v_c178 = m944[4];
            slog::join_probe_old<3,3>(st_diffindex876, st_diffdelta887, std::array<u64,3>{v_c176, v_c175, v_c178}, [&](const std::array<u64,3>& m945) {
              if (!slog::exists_probe<3,2>(st_diffindex877, std::array<u64,3>{v_c4, v_c178, 0})) return;
              slog::join_probe_old<5,3>(st_bldindex878, st_blddelta888, std::array<u64,5>{v_c3, v_c2, v_c5, 0, 0}, [&](const std::array<u64,5>& m946) {
                u64 v_c179 = m946[3]; u64 v_c22 = m946[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex879, std::array<u64,2>{v_c22, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex880, std::array<u64,2>{v_c179, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex881, st_mskdelta889, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m947) {
                  u64 v_c180 = m947[2];
                  slog::join_probe<2,2>(st_msk_ansindex882, std::array<u64,2>{v_c180, v_c2}, [&](const std::array<u64,2>& m948) {
                    slog::join_probe_old<3,2>(st_diffindex883, st_diffdelta890, std::array<u64,3>{v_c4, v_c178, 0}, [&](const std::array<u64,3>& m949) {
                      u64 v_c181 = m949[2];
                      slog::join_probe<2,2>(st_diff_ansindex884, std::array<u64,2>{v_c181, v_c22}, [&](const std::array<u64,2>& m950) {
                        slog::join_probe<2,1>(st_bld_ansindex885, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m951) {
                          u64 v_c106 = m951[1];
                          u64 v_c182 = _prim_band(db, v_c8, v_c3);
                          if (v_c182 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c183 = _prim_lt(db, v_c182, v_c174);
                          if (v_c183 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c183) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c176, v_c106}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask891* _cont = new ReadTask891(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask891(db,b), false);
  // (crule (pre (let __tconst4Rwd255 const5feceb66ffc86f38d952786c)) (scan st_union __t57tc254 __t3lRY253 __t4MB5252) (body (join pbranch (0 1 2 3 4) 1 __t4MB5252 q n u v) (join pbranch (0 1 2 3 4) 1 __t3lRY253 p m l r) (cmp lt m n) (let __t7ozQ256 (band p n)) (cmp gt __t7ozQ256 __tconst4Rwd255)) (head (emit $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) __t57tc254 v l m n p q r u)) set.slog:118 #f)
  class ReadTask955 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex953;  slog::Index** pbranchindex954;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord956({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel957 = db->getRelation("$sup9688x117x0x0x0");
      head_index[0] = readrel957->getIndex(ord956, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord958({0, 1, 2, 3, 4});
      slog::Relation* readrel959 = db->getRelation("pbranch");
      pbranchindex953 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({0, 1, 2, 3, 4});
      slog::Relation* readrel961 = db->getRelation("pbranch");
      pbranchindex954 = readrel961->getIndex(ord960, false);
  
    }
    ReadTask955(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c184 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c185 = _t[0];
        u64 v_c186 = _t[1];
        u64 v_c187 = _t[2];
        slog::join_probe<5,1>(pbranchindex953, std::array<u64,5>{v_c187, 0, 0, 0, 0}, [&](const std::array<u64,5>& m962) {
          u64 v_c8 = m962[1]; u64 v_c9 = m962[2]; u64 v_c10 = m962[3]; u64 v_c11 = m962[4];
          slog::join_probe<5,1>(pbranchindex954, std::array<u64,5>{v_c186, 0, 0, 0, 0}, [&](const std::array<u64,5>& m963) {
            u64 v_c2 = m963[1]; u64 v_c3 = m963[2]; u64 v_c4 = m963[3]; u64 v_c5 = m963[4];
            u64 v_c188 = _prim_lt(db, v_c3, v_c9);
            if (v_c188 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c188) return;
            u64 v_c189 = _prim_band(db, v_c2, v_c9);
            if (v_c189 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            u64 v_c190 = _prim_gt(db, v_c189, v_c184);
            if (v_c190 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c190) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c185, v_c11, v_c4, v_c3, v_c9, v_c2, v_c8, v_c5, v_c10}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask955* _cont = new ReadTask955(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask955(db,b), false);
  // (crule (pre (let __trid3lt61120 const5e6127cdd5ea2629462053c9) (let __trel8XES1121 const99e1cbf3d792d4a87847a801) (let __tcol1cWD1122 const5feceb66ffc86f38d952786c) (let __tconst4G8Z67 constd4735e3a265e16eee03f5971)) (scan $sup97714x23x0x0x1 __d0 __v0 s) (body) (head (tycheck __v0 (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid3lt61120 __trel8XES1121 __tcol1cWD1122 (1 2 3 4 0)) (mkstruct st_ins (1 2 0) __0yKf1119 __v0 __tconst4G8Z67)) st_basic.slog:24 #f)
  class ReadTask969 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid967;  u32 sid966;  u32 sid968;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_ins");
      outer_rel = db->getRelation("$sup97714x23x0x0x1");
      sid967 = db->getRelation("_enum")->getStructId();
      sid966 = db->getRelation("pbranch")->getStructId();
      sid968 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask969(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c191 = v_const5e6127cdd5ea2629462053c9;
      u64 v_c192 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c193 = v_const5feceb66ffc86f38d952786c;
      u64 v_c194 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c22 = _t[1];
        u64 v_c155 = _t[2];
        ++_fires;
        if (!((is_struct(v_c22) && (decode_struct_id(v_c22) == sid966 || decode_struct_id(v_c22) == sid967 || decode_struct_id(v_c22) == sid968))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c191, v_c192, v_c193, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c22, v_c194}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:$sup97714x23x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask969* _cont = new ReadTask969(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask969(db,b), false);
}

