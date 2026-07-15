
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const2d2149bb550ad5e39952d8f4;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste09004dcc147461a8e3857fe;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf2664e0abda1016213c9fa90;


void slog_rules_c54d73746b0e79d0e(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid7AMG943 constf2664e0abda1016213c9fa90) (let __trel1lLE944 const26c89ee8ccc4ea998fd1a912) (let __tcol6Qdi945 const5feceb66ffc86f38d952786c) (let __trel7lgp946 const26c89ee8ccc4ea998fd1a912) (let __tcol7D5S947 const6b86b273ff34fce19d6b804e)) (scan st_diff_ans __t3HZn560 __v0) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t3HZn560 l u) (join $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 l u __d0 m p r v) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t6exy561) (join-old st_diff_ans (0 1) 1 (0 1) __t6exy561 __v1)) (head (tycheck p (accept int) __trid7AMG943 __trel1lLE944 __tcol6Qdi945 (1 2 3 4 0)) (tycheck m (accept int) __trid7AMG943 __trel7lgp946 __tcol7D5S947 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __7CRS942 p m __v0 __v1)) set.slog:137 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex0;  slog::Index** $sup9688x136x0x0x0index1;  slog::Index** st_diffindex2;  slog::Index** st_diff_ansindex3;  slog::Index** st_diffdelta4;  slog::Index** st_diffdelta5;  slog::Index** st_diff_ansdelta6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord8({0, 1, 2});
      slog::Relation* readrel9 = db->getRelation("st_diff");
      st_diffindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({0, 1, 2});
      slog::Relation* readrel11 = db->getRelation("st_diff");
      st_diffdelta4 = readrel11->getIndex(ord10, true);
      std::vector<u16> ord12({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel13 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 2, 0});
      slog::Relation* readrel15 = db->getRelation("st_diff");
      st_diffindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("st_diff");
      st_diffdelta5 = readrel17->getIndex(ord16, true);
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("st_diff_ans");
      st_diff_ansindex3 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("st_diff_ans");
      st_diff_ansdelta6 = readrel21->getIndex(ord20, true);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constf2664e0abda1016213c9fa90;
      u64 v_c1 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const26c89ee8ccc4ea998fd1a912;
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
        slog::join_probe_old<3,1>(st_diffindex0, st_diffdelta4, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m22) {
          u64 v_c7 = m22[1]; u64 v_c8 = m22[2];
          slog::join_probe<7,2>($sup9688x136x0x0x0index1, std::array<u64,7>{v_c7, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m23) {
            u64 v_c9 = m23[2]; u64 v_c10 = m23[3]; u64 v_c11 = m23[4]; u64 v_c12 = m23[5]; u64 v_c13 = m23[6];
            slog::join_probe_old<3,2>(st_diffindex2, st_diffdelta5, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m24) {
              u64 v_c14 = m24[2];
              slog::join_probe_old<2,1>(st_diff_ansindex3, st_diff_ansdelta6, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m25) {
                u64 v_c15 = m25[1];
                ++_fires;
                if (!(is_int(v_c11)))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                if (!(is_int(v_c10)))
                {
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c11, v_c10, v_c6, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre) (scan st_msk __t412X321 k m) (body (exists $sup9688x50x0x0x0 (1 3 4 0 2 5) 2 k m) (join st_msk_ans (0 1) 1 __t412X321 p) (join $sup9688x50x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r)) (head (emit $sup9688x50x0x0x1 (0 2 1 3 4 5 6) __d0 k __t412X321 l m p r)) set.slog:51 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x0index26;  slog::Index** st_msk_ansindex27;  slog::Index** $sup9688x50x0x0x0index28;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord30({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel31 = db->getRelation("$sup9688x50x0x0x1");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord32({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel33 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index26 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("st_msk_ans");
      st_msk_ansindex27 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel37 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index28 = readrel37->getIndex(ord36, false);
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x50x0x0x0index26, std::array<u64,6>{v_c17, v_c10, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex27, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m38) {
          u64 v_c11 = m38[1];
          slog::join_probe<6,3>($sup9688x50x0x0x0index28, std::array<u64,6>{v_c17, v_c10, v_c11, 0, 0, 0}, [&](const std::array<u64,6>& m39) {
            u64 v_c9 = m39[3]; u64 v_c7 = m39[4]; u64 v_c12 = m39[5];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c9, v_c17, v_c16, v_c7, v_c10, v_c11, v_c12}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_msk", _fires);
  
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
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan st_diff __t0F4S77 __t0L1D80 __t3eDW75) (body (exists $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) 1 __t0F4S77) (join-old st_diff (1 2 0) 1 (1 2 0) __t0L1D80 v __t8Vvm81) (exists $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0F4S77 v) (exists st_diff_ans (0 1) 1 __t8Vvm81) (join pbranch (4 0 1 2 3) 2 v __t3eDW75 q n u) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x151x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0F4S77 l m p r) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0L1D80) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join st_msk_ans (0 1) 2 __t1x4A82 q) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask55 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x151x0x0x0index40;  slog::Index** st_diffindex41;  slog::Index** $sup9688x151x0x0x0index42;  slog::Index** st_diff_ansindex43;  slog::Index** pbranchindex44;  slog::Index** st_mskindex45;  slog::Index** st_msk_ansindex46;  slog::Index** $sup9688x151x0x0x0index47;  slog::Index** pbranchindex48;  slog::Index** st_mskindex49;  slog::Index** st_msk_ansindex50;  slog::Index** st_diff_ansindex51;  slog::Index** st_diffdelta52;  slog::Index** pbranchdelta53;  slog::Index** st_mskdelta54;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("st_diff_ans");
      head_index[0] = readrel57->getIndex(ord56, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord58({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel59 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index40 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 0});
      slog::Relation* readrel61 = db->getRelation("st_diff");
      st_diffindex41 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("st_diff");
      st_diffdelta52 = readrel63->getIndex(ord62, true);
      std::vector<u16> ord64({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel65 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index42 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("st_diff_ans");
      st_diff_ansindex43 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({4, 0, 1, 2, 3});
      slog::Relation* readrel69 = db->getRelation("pbranch");
      pbranchindex44 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({2, 0, 1});
      slog::Relation* readrel71 = db->getRelation("st_msk");
      st_mskindex45 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("st_msk_ans");
      st_msk_ansindex46 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel75 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index47 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 3, 4, 0});
      slog::Relation* readrel77 = db->getRelation("pbranch");
      pbranchindex48 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 3, 4, 0});
      slog::Relation* readrel79 = db->getRelation("pbranch");
      pbranchdelta53 = readrel79->getIndex(ord78, true);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("st_msk");
      st_mskindex49 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("st_msk");
      st_mskdelta54 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("st_msk_ans");
      st_msk_ansindex50 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("st_diff_ans");
      st_diff_ansindex51 = readrel87->getIndex(ord86, false);
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c21 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x151x0x0x0index40, std::array<u64,9>{v_c19, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex41, st_diffdelta52, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m88) {
          u64 v_c13 = m88[1]; u64 v_c22 = m88[2];
          if (!slog::exists_probe<9,2>($sup9688x151x0x0x0index42, std::array<u64,9>{v_c19, v_c13, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex43, std::array<u64,2>{v_c22, 0})) return;
          slog::join_probe<5,2>(pbranchindex44, std::array<u64,5>{v_c13, v_c21, 0, 0, 0}, [&](const std::array<u64,5>& m89) {
            u64 v_c23 = m89[2]; u64 v_c24 = m89[3]; u64 v_c8 = m89[4];
            if (!slog::exists_probe<3,1>(st_mskindex45, std::array<u64,3>{v_c24, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex46, std::array<u64,2>{v_c23, 0})) return;
            slog::join_probe<9,5>($sup9688x151x0x0x0index47, std::array<u64,9>{v_c23, v_c24, v_c8, v_c13, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,9>& m90) {
              u64 v_c7 = m90[5]; u64 v_c10 = m90[6]; u64 v_c11 = m90[7]; u64 v_c12 = m90[8];
              u64 v_c25 = _prim_lt(db, v_c10, v_c24);
              if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
              if (!v_c25) return;
              slog::join_probe_old<5,5>(pbranchindex48, pbranchdelta53, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, v_c20}, [&](const std::array<u64,5>& m92) {
                slog::join_probe_old<3,2>(st_mskindex49, st_mskdelta54, std::array<u64,3>{v_c11, v_c24, 0}, [&](const std::array<u64,3>& m93) {
                  u64 v_c26 = m93[2];
                  slog::join_probe<2,2>(st_msk_ansindex50, std::array<u64,2>{v_c26, v_c23}, [&](const std::array<u64,2>& m94) {
                    slog::join_probe<2,1>(st_diff_ansindex51, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m95) {
                      u64 v_c27 = m95[1];
                      u64 v_c28 = _prim_band(db, v_c11, v_c24);
                      if (v_c28 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c29 = _prim_gt(db, v_c28, v_c18);
                      if (v_c29 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c29) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c27}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask55* _cont = new ReadTask55(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask55(db,b), false);
  // (crule (pre (let __tconst8pvP1063 conste3776bfed7f405de8017ecfa)) (scan st_ins __t2B3O85 __t5rnQ84 k) (body (join _enum (0 1) 2 __t5rnQ84 __tconst8pvP1063)) (head (emit-temp temp7u1Q1268 __t2B3O85 k) (mkstruct pleaf (1 0) __t88id83 k)) set.slog:48 #f)
  class ReadTask98 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex97;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7u1Q1268");
      head_rel[1] = db->getRelation("pleaf");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord99({0, 1});
      slog::Relation* readrel100 = db->getRelation("_enum");
      _enumindex97 = readrel100->getIndex(ord99, false);
  
    }
    ReadTask98(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_conste3776bfed7f405de8017ecfa;
  
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
        u64 v_c17 = _t[2];
        slog::join_probe<2,2>(_enumindex97, std::array<u64,2>{v_c32, v_c30}, [&](const std::array<u64,2>& m101) {
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c17});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:48", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask98* _cont = new ReadTask98(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask98(db,b), false);
  // (crule (pre (let __tconst3lre272 const5feceb66ffc86f38d952786c)) (scan st_hsb __t9G4L271 __t26Ir270) (body (join st_hsb_ans (0 1) 1 __t9G4L271 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t5swO273 (band p0 __v0)) (cmp gt __t5swO273 __tconst3lre272) (let chk7xqu1349 (bxor p0 p1)) (eq __t26Ir270 chk7xqu1349)) (head (emit $sup9688x40x0x0x1 (1 2 0 3 4 5 6) __t9G4L271 __v0 __d0 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex102;  slog::Index** $sup9688x40x0x0x0index103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord105({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel106 = db->getRelation("$sup9688x40x0x0x1");
      head_index[0] = readrel106->getIndex(ord105, false);
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex102 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0, 2, 3, 4});
      slog::Relation* readrel110 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index103 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        slog::join_probe<2,1>(st_hsb_ansindex102, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m111) {
          u64 v_c6 = m111[1];
          slog::join_all<5>($sup9688x40x0x0x0index103, [&](const std::array<u64,5>& m112) {
            u64 v_c36 = m112[0]; u64 v_c9 = m112[1]; u64 v_c37 = m112[2]; u64 v_c38 = m112[3]; u64 v_c39 = m112[4];
            u64 v_c40 = _prim_band(db, v_c36, v_c6);
            if (v_c40 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            u64 v_c41 = _prim_gt(db, v_c40, v_c33);
            if (v_c41 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            if (!v_c41) return;
            u64 v_c42 = _prim_bxor(db, v_c36, v_c37);
            if (v_c42 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            if (v_c35 != v_c42) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c34, v_c6, v_c9, v_c36, v_c37, v_c38, v_c39}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask104* _cont = new ReadTask104(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask104(db,b), false);
  // (crule (pre (let __trid9Z9h1106 const2d2149bb550ad5e39952d8f4) (let __trel09ZZ1107 const94d9c4e2675ef4bd8443d499) (let __tcol5CDz1108 const6b86b273ff34fce19d6b804e) (let __trel5vP41109 const66633592860a63ea6408b433) (let __tcol0nDj1110 const5feceb66ffc86f38d952786c) (let __trel77fA1111 const66633592860a63ea6408b433) (let __tcol0dec1112 const6b86b273ff34fce19d6b804e) (let __trel7AEN1113 const66633592860a63ea6408b433) (let __tcol6tjT1114 constd4735e3a265e16eee03f5971) (let __trel7dvW1115 const66633592860a63ea6408b433) (let __tcol76ej1116 const4e07408562bedb8b60ce05c1)) (scan $sup9688x117x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid9Z9h1106 __trel09ZZ1107 __tcol5CDz1108 (1 2 3 4 0)) (tycheck p (accept int) __trid9Z9h1106 __trel5vP41109 __tcol0nDj1110 (1 2 3 4 0)) (tycheck m (accept int) __trid9Z9h1106 __trel77fA1111 __tcol0dec1112 (1 2 3 4 0)) (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid9Z9h1106 __trel7AEN1113 __tcol6tjT1114 (1 2 3 4 0)) (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid9Z9h1106 __trel7dvW1115 __tcol76ej1116 (1 2 3 4 0)) (emit-temp temp16ye1280 l m p r v) (mkstruct pbranch (1 2 3 4 0) __t9fqm331 p m l r)) set.slog:118 #f)
  class ReadTask117 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid115;  u32 sid114;  u32 sid116;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp16ye1280");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x117x0x0x1");
      sid115 = db->getRelation("_enum")->getStructId();
      sid114 = db->getRelation("pbranch")->getStructId();
      sid116 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const2d2149bb550ad5e39952d8f4;
      u64 v_c44 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const66633592860a63ea6408b433;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c48 = v_const66633592860a63ea6408b433;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_const66633592860a63ea6408b433;
      u64 v_c51 = v_constd4735e3a265e16eee03f5971;
      u64 v_c52 = v_const66633592860a63ea6408b433;
      u64 v_c53 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c9 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c24 = _t[4];
        u64 v_c11 = _t[5];
        u64 v_c23 = _t[6];
        u64 v_c12 = _t[7];
        u64 v_c8 = _t[8];
        u64 v_c13 = _t[9];
        ++_fires;
        if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid114 || decode_struct_id(v_c13) == sid115 || decode_struct_id(v_c13) == sid116))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c43, v_c44, v_c45, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c11)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c43, v_c46, v_c47, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c43, v_c48, v_c49, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid114 || decode_struct_id(v_c7) == sid115 || decode_struct_id(v_c7) == sid116))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c43, v_c50, v_c51, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c12) && (decode_struct_id(v_c12) == sid114 || decode_struct_id(v_c12) == sid115 || decode_struct_id(v_c12) == sid116))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c43, v_c52, v_c53, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c7, v_c10, v_c11, v_c12, v_c13});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c11, v_c10, v_c7, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:$sup9688x117x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask117* _cont = new ReadTask117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask117(db,b), false);
  // (crule (pre) (scan pbranch __t52IG517 p m l r) (body (exists pbranch (2 0 1 3 4) 1 m) (exists st_union (1 2 0) 1 __t52IG517) (join-old st_join (1 2 3 4 0) 2 (1 2 3 4 0) p __t52IG517 q __t1VuF518 __t3WPW519) (neq p q) (exists st_union (1 2 0) 2 __t52IG517 __t1VuF518) (exists st_join_ans (0 1) 1 __t3WPW519) (join-old pbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t1VuF518 q m u v) (join st_union (1 2 0) 2 __t52IG517 __t1VuF518 __t5oQM516) (join st_join_ans (0 1) 1 __t3WPW519 res)) (head (emit st_union_ans (0 1) __t5oQM516 res)) set.slog:125 #f)
  class ReadTask128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex118;  slog::Index** st_unionindex119;  slog::Index** st_joinindex120;  slog::Index** st_unionindex121;  slog::Index** st_join_ansindex122;  slog::Index** pbranchindex123;  slog::Index** st_unionindex124;  slog::Index** st_join_ansindex125;  slog::Index** st_joindelta126;  slog::Index** pbranchdelta127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("st_union_ans");
      head_index[0] = readrel130->getIndex(ord129, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord131({2, 0, 1, 3, 4});
      slog::Relation* readrel132 = db->getRelation("pbranch");
      pbranchindex118 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 0});
      slog::Relation* readrel134 = db->getRelation("st_union");
      st_unionindex119 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 3, 4, 0});
      slog::Relation* readrel136 = db->getRelation("st_join");
      st_joinindex120 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 3, 4, 0});
      slog::Relation* readrel138 = db->getRelation("st_join");
      st_joindelta126 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("st_union");
      st_unionindex121 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({0, 1});
      slog::Relation* readrel142 = db->getRelation("st_join_ans");
      st_join_ansindex122 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({0, 1, 2, 3, 4});
      slog::Relation* readrel144 = db->getRelation("pbranch");
      pbranchindex123 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1, 2, 3, 4});
      slog::Relation* readrel146 = db->getRelation("pbranch");
      pbranchdelta127 = readrel146->getIndex(ord145, true);
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("st_union");
      st_unionindex124 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("st_join_ans");
      st_join_ansindex125 = readrel150->getIndex(ord149, false);
  
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
        u64 v_c55 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c12 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex118, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex119, std::array<u64,3>{v_c55, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex120, st_joindelta126, std::array<u64,5>{v_c11, v_c55, 0, 0, 0}, [&](const std::array<u64,5>& m151) {
          u64 v_c23 = m151[2]; u64 v_c56 = m151[3]; u64 v_c57 = m151[4];
          if (v_c11 == v_c23) return;
          if (!slog::exists_probe<3,2>(st_unionindex121, std::array<u64,3>{v_c55, v_c56, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex122, std::array<u64,2>{v_c57, 0})) return;
          slog::join_probe_old<5,3>(pbranchindex123, pbranchdelta127, std::array<u64,5>{v_c56, v_c23, v_c10, 0, 0}, [&](const std::array<u64,5>& m152) {
            u64 v_c8 = m152[3]; u64 v_c13 = m152[4];
            slog::join_probe<3,2>(st_unionindex124, std::array<u64,3>{v_c55, v_c56, 0}, [&](const std::array<u64,3>& m153) {
              u64 v_c58 = m153[2];
              slog::join_probe<2,1>(st_join_ansindex125, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m154) {
                u64 v_c27 = m154[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c27}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:pbranch", _fires);
  
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
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan $sup9688x40x0x0x2 __t4PzE464 __t2flT468 dup2gd61405 dup5ZAM1406 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join-old $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join-old $sup9688x40x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join-old st_msk_ans (0 1) 1 (0 1) __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask173 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x40x0x0x1index155;  slog::Index** $sup9688x40x0x0x0index156;  slog::Index** st_joinindex157;  slog::Index** st_hsb_ansindex158;  slog::Index** st_hsb_ansindex159;  slog::Index** st_hsb_ansindex160;  slog::Index** st_mskindex161;  slog::Index** st_msk_ansindex162;  slog::Index** st_hsbindex163;  slog::Index** $sup9688x40x0x0x1delta164;  slog::Index** $sup9688x40x0x0x0delta165;  slog::Index** st_joindelta166;  slog::Index** st_hsb_ansdelta167;  slog::Index** st_hsb_ansdelta168;  slog::Index** st_hsb_ansdelta169;  slog::Index** st_mskdelta170;  slog::Index** st_msk_ansdelta171;  slog::Index** st_hsbdelta172;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord174({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel175 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index155 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel177 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1delta164 = readrel177->getIndex(ord176, true);
      std::vector<u16> ord178({1, 0, 2, 3, 4});
      slog::Relation* readrel179 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index156 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 0, 2, 3, 4});
      slog::Relation* readrel181 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0delta165 = readrel181->getIndex(ord180, true);
      std::vector<u16> ord182({1, 2, 3, 4, 0});
      slog::Relation* readrel183 = db->getRelation("st_join");
      st_joinindex157 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 3, 4, 0});
      slog::Relation* readrel185 = db->getRelation("st_join");
      st_joindelta166 = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex158 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta167 = readrel189->getIndex(ord188, true);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex159 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta168 = readrel193->getIndex(ord192, true);
      std::vector<u16> ord194({0, 1});
      slog::Relation* readrel195 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex160 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta169 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({1, 2, 0});
      slog::Relation* readrel199 = db->getRelation("st_msk");
      st_mskindex161 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 0});
      slog::Relation* readrel201 = db->getRelation("st_msk");
      st_mskdelta170 = readrel201->getIndex(ord200, true);
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("st_msk_ans");
      st_msk_ansindex162 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("st_msk_ans");
      st_msk_ansdelta171 = readrel205->getIndex(ord204, true);
      std::vector<u16> ord206({0, 1});
      slog::Relation* readrel207 = db->getRelation("st_hsb");
      st_hsbindex163 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("st_hsb");
      st_hsbdelta172 = readrel209->getIndex(ord208, true);
  
    }
    ReadTask173(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        u64 v_c63 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c15 = _t[5];
        u64 v_c64 = _t[6];
        u64 v_c36 = _t[7];
        u64 v_c37 = _t[8];
        u64 v_c38 = _t[9];
        u64 v_c39 = _t[10];
        if (v_c61 != v_c63) return;
        if (v_c61 != v_c62) return;
        slog::join_probe_old<7,7>($sup9688x40x0x0x1index155, $sup9688x40x0x0x1delta164, std::array<u64,7>{v_c60, v_c36, v_c37, v_c38, v_c39, v_c61, v_c6}, [&](const std::array<u64,7>& m210) {
          slog::join_probe_old<5,5>($sup9688x40x0x0x0index156, $sup9688x40x0x0x0delta165, std::array<u64,5>{v_c36, v_c60, v_c37, v_c38, v_c39}, [&](const std::array<u64,5>& m211) {
            slog::join_probe_old<5,5>(st_joinindex157, st_joindelta166, std::array<u64,5>{v_c36, v_c38, v_c37, v_c39, v_c60}, [&](const std::array<u64,5>& m212) {
              slog::join_probe_old<2,2>(st_hsb_ansindex158, st_hsb_ansdelta167, std::array<u64,2>{v_c61, v_c64}, [&](const std::array<u64,2>& m213) {
                slog::join_probe_old<2,2>(st_hsb_ansindex159, st_hsb_ansdelta168, std::array<u64,2>{v_c61, v_c15}, [&](const std::array<u64,2>& m214) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex160, st_hsb_ansdelta169, std::array<u64,2>{v_c61, v_c6}, [&](const std::array<u64,2>& m215) {
                    slog::join_probe_old<3,2>(st_mskindex161, st_mskdelta170, std::array<u64,3>{v_c36, v_c15, 0}, [&](const std::array<u64,3>& m216) {
                      u64 v_c65 = m216[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex162, st_msk_ansdelta171, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m217) {
                        u64 v_c66 = m217[1];
                        u64 v_c67 = _prim_bxor(db, v_c36, v_c37);
                        if (v_c67 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex163, st_hsbdelta172, std::array<u64,2>{v_c61, v_c67}, [&](const std::array<u64,2>& m218) {
                          u64 v_c68 = _prim_band(db, v_c36, v_c6);
                          if (v_c68 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c69 = _prim_gt(db, v_c68, v_c59);
                          if (v_c69 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c69) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c60, v_c66, v_c64, v_c38, v_c39});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c66, v_c64, v_c39, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask173* _cont = new ReadTask173(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask173(db,b), false);
  // (crule (pre) (scan pbranch __t5rDd566 p m l r) (body (exists st_del (1 2 0) 1 __t5rDd566) (exists st_msk (2 0 1) 1 m) (join $sup9688x87x0x0x0 (2 3 4 5 0 1) 4 l m p r __t3SFe567 k) (join-old st_del (0 2 1) 3 (0 2 1) __t3SFe567 k __t5rDd566) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t0CrA568) (join st_msk_ans (0 1) 1 __t0CrA568 __v0) (neq p __v0)) (head (emit st_del_ans (0 1) __t3SFe567 __t5rDd566)) set.slog:88 #f)
  class ReadTask228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex220;  slog::Index** st_mskindex221;  slog::Index** $sup9688x87x0x0x0index222;  slog::Index** st_delindex223;  slog::Index** st_mskindex224;  slog::Index** st_msk_ansindex225;  slog::Index** st_deldelta226;  slog::Index** st_mskdelta227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("st_del_ans");
      head_index[0] = readrel230->getIndex(ord229, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord231({1, 2, 0});
      slog::Relation* readrel232 = db->getRelation("st_del");
      st_delindex220 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({2, 0, 1});
      slog::Relation* readrel234 = db->getRelation("st_msk");
      st_mskindex221 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel236 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0index222 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({0, 2, 1});
      slog::Relation* readrel238 = db->getRelation("st_del");
      st_delindex223 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 2, 1});
      slog::Relation* readrel240 = db->getRelation("st_del");
      st_deldelta226 = readrel240->getIndex(ord239, true);
      std::vector<u16> ord241({1, 2, 0});
      slog::Relation* readrel242 = db->getRelation("st_msk");
      st_mskindex224 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("st_msk");
      st_mskdelta227 = readrel244->getIndex(ord243, true);
      std::vector<u16> ord245({0, 1});
      slog::Relation* readrel246 = db->getRelation("st_msk_ans");
      st_msk_ansindex225 = readrel246->getIndex(ord245, false);
  
    }
    ReadTask228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c12 = _t[4];
        if (!slog::exists_probe<3,1>(st_delindex220, std::array<u64,3>{v_c70, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex221, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x87x0x0x0index222, std::array<u64,6>{v_c7, v_c10, v_c11, v_c12, 0, 0}, [&](const std::array<u64,6>& m247) {
          u64 v_c71 = m247[4]; u64 v_c17 = m247[5];
          slog::join_probe_old<3,3>(st_delindex223, st_deldelta226, std::array<u64,3>{v_c71, v_c17, v_c70}, [&](const std::array<u64,3>& m248) {
            slog::join_probe_old<3,2>(st_mskindex224, st_mskdelta227, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m249) {
              u64 v_c72 = m249[2];
              slog::join_probe<2,1>(st_msk_ansindex225, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m250) {
                u64 v_c6 = m250[1];
                if (v_c11 == v_c6) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c70}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask228* _cont = new ReadTask228(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask228(db,b), false);
  // (crule (pre (let __trid948K1032 conste09004dcc147461a8e3857fe) (let __trel91ND1033 consta10f76b4ec574de5d7b6908e) (let __tcol0WuN1034 const5feceb66ffc86f38d952786c) (let __trel4VXe1035 consta10f76b4ec574de5d7b6908e) (let __tcol9dlR1036 const6b86b273ff34fce19d6b804e)) (scan $sup9688x70x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid948K1032 __trel91ND1033 __tcol0WuN1034 (1 2 3 4 0)) (tycheck m (accept int) __trid948K1032 __trel4VXe1035 __tcol9dlR1036 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __3B4p1031 k m)) set.slog:71 #f)
  class ReadTask251 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x70x0x0x0");
  
    }
    ReadTask251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_conste09004dcc147461a8e3857fe;
      u64 v_c74 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
      u64 v_c76 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c9 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c12 = _t[5];
        ++_fires;
        if (!(is_int(v_c17)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c73, v_c74, v_c75, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c73, v_c76, v_c77, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c17, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:$sup9688x70x0x0x0", _fires);
  
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
  // (crule (pre (let __trid7Tcv991 const987d6cf2e5032ff135cc0c65) (let __trel3tRw992 consta10f76b4ec574de5d7b6908e) (let __tcol9KTf993 const5feceb66ffc86f38d952786c) (let __trel00cC994 consta10f76b4ec574de5d7b6908e) (let __tcol87oV995 const6b86b273ff34fce19d6b804e)) (scan $sup9688x139x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid7Tcv991 __trel3tRw992 __tcol9KTf993 (1 2 3 4 0)) (tycheck m (accept int) __trid7Tcv991 __trel00cC994 __tcol87oV995 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __2vDR990 q m)) set.slog:140 #f)
  class ReadTask252 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x139x0x0x0");
  
    }
    ReadTask252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c79 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c80 = v_const5feceb66ffc86f38d952786c;
      u64 v_c81 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c82 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c9 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c23 = _t[5];
        u64 v_c12 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c13 = _t[8];
        ++_fires;
        if (!(is_int(v_c23)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c78, v_c79, v_c80, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c78, v_c81, v_c82, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c23, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:$sup9688x139x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask252* _cont = new ReadTask252(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask252(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t4CDi47 a) (body (exists _enum (1 0) 1 __tconst9YUA1125) (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (exists st_union (1 2 0) 1 a) (join-old st_ins (0 2 1) 2 (0 2 1) __t4CDi47 __tconst35F246 __v0) (exists st_ins_ans (1 0) 1 __v0) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst7TTg43 __t8j8m45) (join st_ins_ans (0 1) 2 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (join-old st_ins_ans (0 1) 1 (0 1) __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join-old st_ins_ans (0 1) 1 (0 1) __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join-old st_union_ans (0 1) 1 (0 1) __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex253;  slog::Index** st_insindex254;  slog::Index** st_insindex255;  slog::Index** st_insindex256;  slog::Index** st_unionindex257;  slog::Index** st_insindex258;  slog::Index** st_ins_ansindex259;  slog::Index** _enumindex260;  slog::Index** st_insindex261;  slog::Index** st_insindex262;  slog::Index** st_ins_ansindex263;  slog::Index** st_insindex264;  slog::Index** st_ins_ansindex265;  slog::Index** st_insindex266;  slog::Index** st_ins_ansindex267;  slog::Index** st_unionindex268;  slog::Index** st_union_ansindex269;  slog::Index** st_insdelta270;  slog::Index** st_insdelta271;  slog::Index** st_insdelta272;  slog::Index** st_ins_ansdelta273;  slog::Index** st_insdelta274;  slog::Index** st_ins_ansdelta275;  slog::Index** st_uniondelta276;  slog::Index** st_union_ansdelta277;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord279({0});
      slog::Relation* readrel280 = db->getRelation("canon");
      head_index[0] = readrel280->getIndex(ord279, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord281({1, 0});
      slog::Relation* readrel282 = db->getRelation("_enum");
      _enumindex253 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({2, 0, 1});
      slog::Relation* readrel284 = db->getRelation("st_ins");
      st_insindex254 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({2, 0, 1});
      slog::Relation* readrel286 = db->getRelation("st_ins");
      st_insindex255 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({2, 0, 1});
      slog::Relation* readrel288 = db->getRelation("st_ins");
      st_insindex256 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0});
      slog::Relation* readrel290 = db->getRelation("st_union");
      st_unionindex257 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 2, 1});
      slog::Relation* readrel292 = db->getRelation("st_ins");
      st_insindex258 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 2, 1});
      slog::Relation* readrel294 = db->getRelation("st_ins");
      st_insdelta270 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({1, 0});
      slog::Relation* readrel296 = db->getRelation("st_ins_ans");
      st_ins_ansindex259 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 0});
      slog::Relation* readrel298 = db->getRelation("_enum");
      _enumindex260 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 0});
      slog::Relation* readrel300 = db->getRelation("st_ins");
      st_insindex261 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 0});
      slog::Relation* readrel302 = db->getRelation("st_ins");
      st_insindex262 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("st_ins");
      st_insdelta271 = readrel304->getIndex(ord303, true);
      std::vector<u16> ord305({0, 1});
      slog::Relation* readrel306 = db->getRelation("st_ins_ans");
      st_ins_ansindex263 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("st_ins");
      st_insindex264 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 2, 0});
      slog::Relation* readrel310 = db->getRelation("st_ins");
      st_insdelta272 = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("st_ins_ans");
      st_ins_ansindex265 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("st_ins_ans");
      st_ins_ansdelta273 = readrel314->getIndex(ord313, true);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("st_ins");
      st_insindex266 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("st_ins");
      st_insdelta274 = readrel318->getIndex(ord317, true);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("st_ins_ans");
      st_ins_ansindex267 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("st_ins_ans");
      st_ins_ansdelta275 = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({1, 2, 0});
      slog::Relation* readrel324 = db->getRelation("st_union");
      st_unionindex268 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("st_union");
      st_uniondelta276 = readrel326->getIndex(ord325, true);
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("st_union_ans");
      st_union_ansindex269 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("st_union_ans");
      st_union_ansdelta277 = readrel330->getIndex(ord329, true);
  
    }
    ReadTask278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c84 = v_constef2d127de37b942baad06145;
      u64 v_c85 = v_const2c624232cdd221771294dfbb;
      u64 v_c86 = v_constd4735e3a265e16eee03f5971;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c88 = _t[0];
        u64 v_c89 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex253, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex254, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex255, std::array<u64,3>{v_c86, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex256, std::array<u64,3>{v_c87, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex257, std::array<u64,3>{v_c89, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex258, st_insdelta270, std::array<u64,3>{v_c88, v_c85, 0}, [&](const std::array<u64,3>& m331) {
          u64 v_c6 = m331[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex259, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe<2,1>(_enumindex260, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m332) {
            u64 v_c90 = m332[1];
            if (!slog::exists_probe<3,2>(st_insindex261, std::array<u64,3>{v_c90, v_c86, 0})) return;
            slog::join_probe_old<3,2>(st_insindex262, st_insdelta271, std::array<u64,3>{v_c90, v_c84, 0}, [&](const std::array<u64,3>& m333) {
              u64 v_c91 = m333[2];
              slog::join_probe<2,2>(st_ins_ansindex263, std::array<u64,2>{v_c91, v_c6}, [&](const std::array<u64,2>& m334) {
                slog::join_probe_old<3,2>(st_insindex264, st_insdelta272, std::array<u64,3>{v_c90, v_c86, 0}, [&](const std::array<u64,3>& m335) {
                  u64 v_c92 = m335[2];
                  slog::join_probe_old<2,1>(st_ins_ansindex265, st_ins_ansdelta273, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m336) {
                    u64 v_c15 = m336[1];
                    slog::join_probe_old<3,2>(st_insindex266, st_insdelta274, std::array<u64,3>{v_c15, v_c87, 0}, [&](const std::array<u64,3>& m337) {
                      u64 v_c93 = m337[2];
                      slog::join_probe_old<2,1>(st_ins_ansindex267, st_ins_ansdelta275, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m338) {
                        u64 v_c94 = m338[1];
                        slog::join_probe_old<3,2>(st_unionindex268, st_uniondelta276, std::array<u64,3>{v_c89, v_c94, 0}, [&](const std::array<u64,3>& m339) {
                          u64 v_c95 = m339[2];
                          slog::join_probe_old<2,1>(st_union_ansindex269, st_union_ansdelta277, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m340) {
                            u64 v_c12 = m340[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask278* _cont = new ReadTask278(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask278(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan $sup9688x50x0x0x0 __t6bST316 k l m p r) (body (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 2 l k) (join-old $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 6 (3 4 5 6 0 2 1) l m p r __t6bST316 k __t5Q4t319) (exists st_msk (1 2 0) 3 k m __t5Q4t319) (exists st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8dDI315) (join-old st_ins (0 2 1) 3 (0 2 1) __t6bST316 k __t8dDI315) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask360 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex341;  slog::Index** st_insindex342;  slog::Index** st_mskindex343;  slog::Index** st_msk_ansindex344;  slog::Index** st_insindex345;  slog::Index** $sup9688x50x0x0x1index346;  slog::Index** st_mskindex347;  slog::Index** st_msk_ansindex348;  slog::Index** pbranchindex349;  slog::Index** st_insindex350;  slog::Index** st_mskindex351;  slog::Index** st_msk_ansindex352;  slog::Index** st_insindex353;  slog::Index** st_ins_ansindex354;  slog::Index** $sup9688x50x0x0x1delta355;  slog::Index** pbranchdelta356;  slog::Index** st_insdelta357;  slog::Index** st_mskdelta358;  slog::Index** st_insdelta359;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord361({1, 2, 3, 4, 0});
      slog::Relation* readrel362 = db->getRelation("pbranch");
      pbranchindex341 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({0, 2, 1});
      slog::Relation* readrel364 = db->getRelation("st_ins");
      st_insindex342 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 0});
      slog::Relation* readrel366 = db->getRelation("st_msk");
      st_mskindex343 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 0});
      slog::Relation* readrel368 = db->getRelation("st_msk_ans");
      st_msk_ansindex344 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 2, 0});
      slog::Relation* readrel370 = db->getRelation("st_ins");
      st_insindex345 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel372 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index346 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel374 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1delta355 = readrel374->getIndex(ord373, true);
      std::vector<u16> ord375({1, 2, 0});
      slog::Relation* readrel376 = db->getRelation("st_msk");
      st_mskindex347 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({0, 1});
      slog::Relation* readrel378 = db->getRelation("st_msk_ans");
      st_msk_ansindex348 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 2, 3, 4, 0});
      slog::Relation* readrel380 = db->getRelation("pbranch");
      pbranchindex349 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 2, 3, 4, 0});
      slog::Relation* readrel382 = db->getRelation("pbranch");
      pbranchdelta356 = readrel382->getIndex(ord381, true);
      std::vector<u16> ord383({0, 2, 1});
      slog::Relation* readrel384 = db->getRelation("st_ins");
      st_insindex350 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({0, 2, 1});
      slog::Relation* readrel386 = db->getRelation("st_ins");
      st_insdelta357 = readrel386->getIndex(ord385, true);
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("st_msk");
      st_mskindex351 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_msk");
      st_mskdelta358 = readrel390->getIndex(ord389, true);
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("st_msk_ans");
      st_msk_ansindex352 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 2, 0});
      slog::Relation* readrel394 = db->getRelation("st_ins");
      st_insindex353 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("st_ins");
      st_insdelta359 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({0, 1});
      slog::Relation* readrel398 = db->getRelation("st_ins_ans");
      st_ins_ansindex354 = readrel398->getIndex(ord397, false);
  
    }
    ReadTask360(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c97 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c12 = _t[5];
        if (!slog::exists_probe<5,4>(pbranchindex341, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex342, std::array<u64,3>{v_c97, v_c17, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex343, std::array<u64,3>{v_c17, v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex344, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex345, std::array<u64,3>{v_c7, v_c17, 0})) return;
        slog::join_probe_old<7,6>($sup9688x50x0x0x1index346, $sup9688x50x0x0x1delta355, std::array<u64,7>{v_c7, v_c10, v_c11, v_c12, v_c97, v_c17, 0}, [&](const std::array<u64,7>& m399) {
          u64 v_c98 = m399[6];
          if (!slog::exists_probe<3,3>(st_mskindex347, std::array<u64,3>{v_c17, v_c10, v_c98})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex348, std::array<u64,2>{v_c98, v_c11})) return;
          slog::join_probe_old<5,4>(pbranchindex349, pbranchdelta356, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0}, [&](const std::array<u64,5>& m400) {
            u64 v_c99 = m400[4];
            slog::join_probe_old<3,3>(st_insindex350, st_insdelta357, std::array<u64,3>{v_c97, v_c17, v_c99}, [&](const std::array<u64,3>& m401) {
              slog::join_probe_old<3,3>(st_mskindex351, st_mskdelta358, std::array<u64,3>{v_c17, v_c10, v_c98}, [&](const std::array<u64,3>& m402) {
                slog::join_probe<2,2>(st_msk_ansindex352, std::array<u64,2>{v_c98, v_c11}, [&](const std::array<u64,2>& m403) {
                  slog::join_probe_old<3,2>(st_insindex353, st_insdelta359, std::array<u64,3>{v_c7, v_c17, 0}, [&](const std::array<u64,3>& m404) {
                    u64 v_c100 = m404[2];
                    slog::join_probe<2,1>(st_ins_ansindex354, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m405) {
                      u64 v_c6 = m405[1];
                      u64 v_c101 = _prim_band(db, v_c17, v_c10);
                      if (v_c101 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c102 = _prim_lt(db, v_c101, v_c96);
                      if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c102) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c97, v_c6, v_c10, v_c11, v_c12});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c11, v_c10, v_c6, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:$sup9688x50x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst4ZAM787 conste3776bfed7f405de8017ecfa)) (scan st_del __t2cdK18 __t6VH917 k) (body (join _enum (0 1) 2 __t6VH917 __tconst4ZAM787)) (head (emit st_del_ans (0 1) __t2cdK18 __t6VH917)) set.slog:85 #f)
  class ReadTask408 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex407;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("st_del_ans");
      head_index[0] = readrel410->getIndex(ord409, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord411({0, 1});
      slog::Relation* readrel412 = db->getRelation("_enum");
      _enumindex407 = readrel412->getIndex(ord411, false);
  
    }
    ReadTask408(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c104 = _t[0];
        u64 v_c105 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<2,2>(_enumindex407, std::array<u64,2>{v_c105, v_c103}, [&](const std::array<u64,2>& m413) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c105}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:85", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask408* _cont = new ReadTask408(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask408(db,b), false);
  // (crule (pre (let __tconst0UIr907 conste3776bfed7f405de8017ecfa) (let __tconst67v2432 constef2d127de37b942baad06145) (let __tconst3Prp435 constd4735e3a265e16eee03f5971) (let __tconst4LVH431 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t2Qai434 __v0) (body (exists _enum (1 0) 1 __tconst0UIr907) (exists st_ins (2 0 1) 1 __tconst3Prp435) (join-old st_ins (0 2 1) 2 (0 2 1) __t2Qai434 __tconst67v2432 __t5QG4436) (join _enum (0 1) 2 __t5QG4436 __tconst0UIr907) (join-old st_ins (1 2 0) 2 (1 2 0) __t5QG4436 __tconst3Prp435 __t1RFt437) (join-old st_ins_ans (0 1) 1 (0 1) __t1RFt437 __v1)) (head (mkstruct st_ins (1 2 0) __12BV908 __v1 __tconst4LVH431)) st_basic.slog:18 #f)
  class ReadTask423 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex414;  slog::Index** st_insindex415;  slog::Index** st_insindex416;  slog::Index** _enumindex417;  slog::Index** st_insindex418;  slog::Index** st_ins_ansindex419;  slog::Index** st_insdelta420;  slog::Index** st_insdelta421;  slog::Index** st_ins_ansdelta422;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("_enum");
      _enumindex414 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({2, 0, 1});
      slog::Relation* readrel427 = db->getRelation("st_ins");
      st_insindex415 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 2, 1});
      slog::Relation* readrel429 = db->getRelation("st_ins");
      st_insindex416 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 2, 1});
      slog::Relation* readrel431 = db->getRelation("st_ins");
      st_insdelta420 = readrel431->getIndex(ord430, true);
      std::vector<u16> ord432({0, 1});
      slog::Relation* readrel433 = db->getRelation("_enum");
      _enumindex417 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("st_ins");
      st_insindex418 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("st_ins");
      st_insdelta421 = readrel437->getIndex(ord436, true);
      std::vector<u16> ord438({0, 1});
      slog::Relation* readrel439 = db->getRelation("st_ins_ans");
      st_ins_ansindex419 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("st_ins_ans");
      st_ins_ansdelta422 = readrel441->getIndex(ord440, true);
  
    }
    ReadTask423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c106 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c107 = v_constef2d127de37b942baad06145;
      u64 v_c108 = v_constd4735e3a265e16eee03f5971;
      u64 v_c109 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex414, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex415, std::array<u64,3>{v_c108, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex416, st_insdelta420, std::array<u64,3>{v_c110, v_c107, 0}, [&](const std::array<u64,3>& m442) {
          u64 v_c111 = m442[2];
          slog::join_probe<2,2>(_enumindex417, std::array<u64,2>{v_c111, v_c106}, [&](const std::array<u64,2>& m443) {
            slog::join_probe_old<3,2>(st_insindex418, st_insdelta421, std::array<u64,3>{v_c111, v_c108, 0}, [&](const std::array<u64,3>& m444) {
              u64 v_c112 = m444[2];
              slog::join_probe_old<2,1>(st_ins_ansindex419, st_ins_ansdelta422, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m445) {
                u64 v_c15 = m445[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c109}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask423* _cont = new ReadTask423(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask423(db,b), false);
  // (crule (pre) (scan st_del_ans __t8BXn276 r) (body (join-old st_del (0 2 1) 1 (0 2 1) __t8BXn276 k s) (exists st_diff (1 2 0) 1 s) (join-old pleaf (1 0) 1 (1 0) k __t5fUY274) (join-old st_diff (1 2 0) 2 (1 2 0) s __t5fUY274 __t6ID7275)) (head (emit st_diff_ans (0 1) __t6ID7275 r)) set.slog:133 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex446;  slog::Index** st_diffindex447;  slog::Index** pleafindex448;  slog::Index** st_diffindex449;  slog::Index** st_deldelta450;  slog::Index** pleafdelta451;  slog::Index** st_diffdelta452;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("st_diff_ans");
      head_index[0] = readrel455->getIndex(ord454, false);
      outer_rel = db->getRelation("st_del_ans");
      std::vector<u16> ord456({0, 2, 1});
      slog::Relation* readrel457 = db->getRelation("st_del");
      st_delindex446 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 2, 1});
      slog::Relation* readrel459 = db->getRelation("st_del");
      st_deldelta450 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("st_diff");
      st_diffindex447 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("pleaf");
      pleafindex448 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("pleaf");
      pleafdelta451 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("st_diff");
      st_diffindex449 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("st_diff");
      st_diffdelta452 = readrel469->getIndex(ord468, true);
  
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
        u64 v_c113 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe_old<3,1>(st_delindex446, st_deldelta450, std::array<u64,3>{v_c113, 0, 0}, [&](const std::array<u64,3>& m470) {
          u64 v_c17 = m470[1]; u64 v_c114 = m470[2];
          if (!slog::exists_probe<3,1>(st_diffindex447, std::array<u64,3>{v_c114, 0, 0})) return;
          slog::join_probe_old<2,1>(pleafindex448, pleafdelta451, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m471) {
            u64 v_c115 = m471[1];
            slog::join_probe_old<3,2>(st_diffindex449, st_diffdelta452, std::array<u64,3>{v_c114, v_c115, 0}, [&](const std::array<u64,3>& m472) {
              u64 v_c116 = m472[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c116, v_c12}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:st_del_ans", _fires);
  
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
  // (crule (pre) (scan st_join __t11qM6 p0 t0 p1 t1) (body) (head (emit $sup9688x40x0x0x0 (1 0 2 3 4) p0 __t11qM6 p1 t0 t1)) set.slog:41 #f)
  class ReadTask473 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord474({1, 0, 2, 3, 4});
      slog::Relation* readrel475 = db->getRelation("$sup9688x40x0x0x0");
      head_index[0] = readrel475->getIndex(ord474, false);
      outer_rel = db->getRelation("st_join");
  
    }
    ReadTask473(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c117 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c37 = _t[3];
        u64 v_c39 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c36, v_c117, v_c37, v_c38, v_c39}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask473* _cont = new ReadTask473(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask473(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan st_union_ans __t4u97350 __v0) (body (join-old st_union (0 1 2) 1 (0 1 2) __t4u97350 r __t0LeB349) (exists pbranch (4 0 1 2 3) 1 r) (exists $sup9688x106x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join-old st_union (2 0 1) 1 (2 0 1) __t0LeB349 __t7KDg345 __t4ii6344) (exists $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t7KDg345 r) (exists $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t7KDg345 r) (join-old pbranch (4 0 1 2 3) 2 (4 0 1 2 3) r __t4ii6344 p m l) (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t7KDg345) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 5 (4 1 2 6 0 3 5 7 8) p l m r __t7KDg345 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t0LeB349) (exists st_msk (1 2 0) 2 q m) (join-old $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t7KDg345 n q u v __t0gfm348) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask501 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex476;  slog::Index** pbranchindex477;  slog::Index** $sup9688x106x0x0x0index478;  slog::Index** $sup9688x106x0x0x1index479;  slog::Index** st_unionindex480;  slog::Index** $sup9688x106x0x0x0index481;  slog::Index** $sup9688x106x0x0x1index482;  slog::Index** pbranchindex483;  slog::Index** $sup9688x106x0x0x1index484;  slog::Index** st_mskindex485;  slog::Index** st_msk_ansindex486;  slog::Index** $sup9688x106x0x0x0index487;  slog::Index** pbranchindex488;  slog::Index** st_mskindex489;  slog::Index** $sup9688x106x0x0x1index490;  slog::Index** pbranchindex491;  slog::Index** st_mskindex492;  slog::Index** st_msk_ansindex493;  slog::Index** st_uniondelta494;  slog::Index** st_uniondelta495;  slog::Index** pbranchdelta496;  slog::Index** $sup9688x106x0x0x0delta497;  slog::Index** $sup9688x106x0x0x1delta498;  slog::Index** pbranchdelta499;  slog::Index** st_mskdelta500;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord502({0, 1, 2});
      slog::Relation* readrel503 = db->getRelation("st_union");
      st_unionindex476 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1, 2});
      slog::Relation* readrel505 = db->getRelation("st_union");
      st_uniondelta494 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({4, 0, 1, 2, 3});
      slog::Relation* readrel507 = db->getRelation("pbranch");
      pbranchindex477 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel509 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index478 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel511 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index479 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({2, 0, 1});
      slog::Relation* readrel513 = db->getRelation("st_union");
      st_unionindex480 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({2, 0, 1});
      slog::Relation* readrel515 = db->getRelation("st_union");
      st_uniondelta495 = readrel515->getIndex(ord514, true);
      std::vector<u16> ord516({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel517 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index481 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel519 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index482 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({4, 0, 1, 2, 3});
      slog::Relation* readrel521 = db->getRelation("pbranch");
      pbranchindex483 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({4, 0, 1, 2, 3});
      slog::Relation* readrel523 = db->getRelation("pbranch");
      pbranchdelta496 = readrel523->getIndex(ord522, true);
      std::vector<u16> ord524({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel525 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index484 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({2, 0, 1});
      slog::Relation* readrel527 = db->getRelation("st_msk");
      st_mskindex485 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({1, 0});
      slog::Relation* readrel529 = db->getRelation("st_msk_ans");
      st_msk_ansindex486 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel531 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index487 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel533 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0delta497 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({1, 2, 3, 4, 0});
      slog::Relation* readrel535 = db->getRelation("pbranch");
      pbranchindex488 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 2, 0});
      slog::Relation* readrel537 = db->getRelation("st_msk");
      st_mskindex489 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel539 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index490 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel541 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1delta498 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({1, 2, 3, 4, 0});
      slog::Relation* readrel543 = db->getRelation("pbranch");
      pbranchindex491 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 2, 3, 4, 0});
      slog::Relation* readrel545 = db->getRelation("pbranch");
      pbranchdelta499 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({1, 2, 0});
      slog::Relation* readrel547 = db->getRelation("st_msk");
      st_mskindex492 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0});
      slog::Relation* readrel549 = db->getRelation("st_msk");
      st_mskdelta500 = readrel549->getIndex(ord548, true);
      std::vector<u16> ord550({0, 1});
      slog::Relation* readrel551 = db->getRelation("st_msk_ans");
      st_msk_ansindex493 = readrel551->getIndex(ord550, false);
  
    }
    ReadTask501(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex476, st_uniondelta494, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m552) {
          u64 v_c12 = m552[1]; u64 v_c120 = m552[2];
          if (!slog::exists_probe<5,1>(pbranchindex477, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x106x0x0x0index478, std::array<u64,9>{v_c12, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup9688x106x0x0x1index479, std::array<u64,10>{v_c12, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_unionindex480, st_uniondelta495, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m553) {
            u64 v_c121 = m553[1]; u64 v_c122 = m553[2];
            if (!slog::exists_probe<9,2>($sup9688x106x0x0x0index481, std::array<u64,9>{v_c121, v_c12, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x106x0x0x1index482, std::array<u64,10>{v_c121, v_c12, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex483, pbranchdelta496, std::array<u64,5>{v_c12, v_c122, 0, 0, 0}, [&](const std::array<u64,5>& m554) {
              u64 v_c11 = m554[2]; u64 v_c10 = m554[3]; u64 v_c7 = m554[4];
              if (!slog::exists_probe<10,5>($sup9688x106x0x0x1index484, std::array<u64,10>{v_c12, v_c7, v_c10, v_c11, v_c121, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex485, std::array<u64,3>{v_c10, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex486, std::array<u64,2>{v_c11, 0})) return;
              slog::join_probe_old<9,5>($sup9688x106x0x0x0index487, $sup9688x106x0x0x0delta497, std::array<u64,9>{v_c11, v_c7, v_c10, v_c12, v_c121, 0, 0, 0, 0}, [&](const std::array<u64,9>& m555) {
                u64 v_c24 = m555[5]; u64 v_c23 = m555[6]; u64 v_c8 = m555[7]; u64 v_c13 = m555[8];
                u64 v_c123 = _prim_lt(db, v_c24, v_c10);
                if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                if (!v_c123) return;
                if (!slog::exists_probe<5,5>(pbranchindex488, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, v_c120})) return;
                if (!slog::exists_probe<3,2>(st_mskindex489, std::array<u64,3>{v_c23, v_c10, 0})) return;
                slog::join_probe_old<10,9>($sup9688x106x0x0x1index490, $sup9688x106x0x0x1delta498, std::array<u64,10>{v_c12, v_c7, v_c10, v_c11, v_c121, v_c24, v_c23, v_c8, v_c13, 0}, [&](const std::array<u64,10>& m557) {
                  u64 v_c124 = m557[9];
                  slog::join_probe_old<5,5>(pbranchindex491, pbranchdelta499, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, v_c120}, [&](const std::array<u64,5>& m558) {
                    slog::join_probe_old<3,3>(st_mskindex492, st_mskdelta500, std::array<u64,3>{v_c23, v_c10, v_c124}, [&](const std::array<u64,3>& m559) {
                      slog::join_probe<2,2>(st_msk_ansindex493, std::array<u64,2>{v_c124, v_c11}, [&](const std::array<u64,2>& m560) {
                        u64 v_c125 = _prim_band(db, v_c23, v_c10);
                        if (v_c125 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c126 = _prim_gt(db, v_c125, v_c118);
                        if (v_c126 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c126) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c6, v_c7, v_c10, v_c11});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c11, v_c10, v_c7, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask501* _cont = new ReadTask501(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask501(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_join __t0kmv352 p0 t0 p1 t1) (body (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (exists $sup9688x36x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t0kmv352 p0 p1 t0 t1) (exists st_msk (1 2 0) 1 p0) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 5 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (exists st_hsb_ans (0 1) 1 __t75bg356) (exists st_hsb_ans (0 1) 2 __t75bg356 __v0) (join $sup9688x36x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0 dup66Lo1333 dup68E21334 __v1 __v3) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join st_hsb_ans (0 1) 2 __t75bg356 __v3) (join st_hsb_ans (0 1) 2 __t75bg356 __v1) (join st_hsb_ans (0 1) 2 __t75bg356 __v0) (join st_msk (1 2 0) 2 p0 __v1 __t9xbE359) (join st_msk_ans (0 1) 1 __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join st_hsb (0 1) 2 __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask575 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x36x0x0x0index562;  slog::Index** $sup9688x36x0x0x2index563;  slog::Index** st_mskindex564;  slog::Index** $sup9688x36x0x0x1index565;  slog::Index** st_hsb_ansindex566;  slog::Index** st_hsb_ansindex567;  slog::Index** $sup9688x36x0x0x2index568;  slog::Index** st_hsb_ansindex569;  slog::Index** st_hsb_ansindex570;  slog::Index** st_hsb_ansindex571;  slog::Index** st_mskindex572;  slog::Index** st_msk_ansindex573;  slog::Index** st_hsbindex574;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord576({1, 0, 2, 3, 4});
      slog::Relation* readrel577 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index562 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel579 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index563 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("st_msk");
      st_mskindex564 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel583 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index565 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex566 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex567 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel589 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index568 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({0, 1});
      slog::Relation* readrel591 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex569 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({0, 1});
      slog::Relation* readrel593 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex570 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({0, 1});
      slog::Relation* readrel595 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex571 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 2, 0});
      slog::Relation* readrel597 = db->getRelation("st_msk");
      st_mskindex572 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({0, 1});
      slog::Relation* readrel599 = db->getRelation("st_msk_ans");
      st_msk_ansindex573 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({0, 1});
      slog::Relation* readrel601 = db->getRelation("st_hsb");
      st_hsbindex574 = readrel601->getIndex(ord600, false);
  
    }
    ReadTask575(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c128 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c37 = _t[3];
        u64 v_c39 = _t[4];
        slog::join_probe<5,5>($sup9688x36x0x0x0index562, std::array<u64,5>{v_c36, v_c128, v_c37, v_c38, v_c39}, [&](const std::array<u64,5>& m602) {
          if (!slog::exists_probe<11,5>($sup9688x36x0x0x2index563, std::array<u64,11>{v_c128, v_c36, v_c37, v_c38, v_c39, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex564, std::array<u64,3>{v_c36, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x36x0x0x1index565, std::array<u64,7>{v_c128, v_c36, v_c37, v_c38, v_c39, 0, 0}, [&](const std::array<u64,7>& m603) {
            u64 v_c129 = m603[5]; u64 v_c6 = m603[6];
            if (!slog::exists_probe<2,1>(st_hsb_ansindex566, std::array<u64,2>{v_c129, 0})) return;
            if (!slog::exists_probe<2,2>(st_hsb_ansindex567, std::array<u64,2>{v_c129, v_c6})) return;
            slog::join_probe<11,7>($sup9688x36x0x0x2index568, std::array<u64,11>{v_c128, v_c36, v_c37, v_c38, v_c39, v_c129, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,11>& m604) {
              u64 v_c130 = m604[7]; u64 v_c131 = m604[8]; u64 v_c15 = m604[9]; u64 v_c64 = m604[10];
              if (v_c129 != v_c131) return;
              if (v_c129 != v_c130) return;
              slog::join_probe<2,2>(st_hsb_ansindex569, std::array<u64,2>{v_c129, v_c64}, [&](const std::array<u64,2>& m605) {
                slog::join_probe<2,2>(st_hsb_ansindex570, std::array<u64,2>{v_c129, v_c15}, [&](const std::array<u64,2>& m606) {
                  slog::join_probe<2,2>(st_hsb_ansindex571, std::array<u64,2>{v_c129, v_c6}, [&](const std::array<u64,2>& m607) {
                    slog::join_probe<3,2>(st_mskindex572, std::array<u64,3>{v_c36, v_c15, 0}, [&](const std::array<u64,3>& m608) {
                      u64 v_c132 = m608[2];
                      slog::join_probe<2,1>(st_msk_ansindex573, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m609) {
                        u64 v_c66 = m609[1];
                        u64 v_c133 = _prim_bxor(db, v_c36, v_c37);
                        if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe<2,2>(st_hsbindex574, std::array<u64,2>{v_c129, v_c133}, [&](const std::array<u64,2>& m610) {
                          u64 v_c134 = _prim_band(db, v_c36, v_c6);
                          if (v_c134 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c135 = _prim_lt(db, v_c134, v_c127);
                          if (v_c135 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c135) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c128, v_c66, v_c64, v_c38, v_c39});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c66, v_c64, v_c38, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask575* _cont = new ReadTask575(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask575(db,b), false);
  // (crule (pre (let __tconst4IEm562 const5feceb66ffc86f38d952786c)) (scan pleaf __t4E8i563 j) (body (join-old st_mem0 (1 2 0) 1 (1 2 0) __t4E8i563 k __t9ujC564) (neq j k)) (head (emit st_mem0_ans (0 1) __t9ujC564 __tconst4IEm562)) set.slog:69 #f)
  class ReadTask614 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index612;  slog::Index** st_mem0delta613;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord615({0, 1});
      slog::Relation* readrel616 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel616->getIndex(ord615, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("st_mem0");
      st_mem0index612 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 2, 0});
      slog::Relation* readrel620 = db->getRelation("st_mem0");
      st_mem0delta613 = readrel620->getIndex(ord619, true);
  
    }
    ReadTask614(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c137 = _t[0];
        u64 v_c138 = _t[1];
        slog::join_probe_old<3,1>(st_mem0index612, st_mem0delta613, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m621) {
          u64 v_c17 = m621[1]; u64 v_c139 = m621[2];
          if (v_c138 == v_c17) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c136}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:69", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask614* _cont = new ReadTask614(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask614(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (scan st_fromlist_ans __t14PV427 r) (body (exists $seq_at (1 0 2) 2 _00024sqo8H0j604 _00024sqo8V65605) (exists $seq_at (1 0 2) 2 _00024sqo9fPL606 _00024sqo58Kv607) (exists $seq_at (1 0 2) 2 _00024sqo6mXs608 _00024sqo8Byv609) (exists $seq_atr (0 1 2) 2 _00024sqo1LyP611 _00024sqo7das610) (exists $seq_atr (0 1 2) 2 _00024sqo8vL7613 _00024sqo5GBE612) (exists $seq_atr (0 1 2) 2 _00024sqo1K4x615 _00024sqo0Oce614) (exists $seq_atr (0 1 2) 2 _00024sqo9RJN617 _00024sqo9a1a616) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (0 1) 2 __t14PV427 _00024seq0) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk71ru1287 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk71ru1287) (letp chk2znk1288 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk2znk1288) (letp chk9wTB1289 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk9wTB1289) (letp chk2Qw91290 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk2Qw91290) (letp chk2VBO1291 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk2VBO1291)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask646 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex622;  slog::Index** $seq_atindex623;  slog::Index** $seq_atindex624;  slog::Index** $seq_atrindex625;  slog::Index** $seq_atrindex626;  slog::Index** $seq_atrindex627;  slog::Index** $seq_atrindex628;  slog::Index** $seq_atindex629;  slog::Index** $seq_atindex630;  slog::Index** $seq_atindex631;  slog::Index** $seq_atindex632;  slog::Index** $seq_atrindex633;  slog::Index** $seq_atrindex634;  slog::Index** $seq_atrindex635;  slog::Index** $seq_atrindex636;  slog::Index** st_fromlistindex637;  slog::Index** $seq_atdelta638;  slog::Index** $seq_atdelta639;  slog::Index** $seq_atdelta640;  slog::Index** $seq_atdelta641;  slog::Index** $seq_atrdelta642;  slog::Index** $seq_atrdelta643;  slog::Index** $seq_atrdelta644;  slog::Index** $seq_atrdelta645;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord647({0});
      slog::Relation* readrel648 = db->getRelation("canon");
      head_index[0] = readrel648->getIndex(ord647, false);
      outer_rel = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord649({1, 0, 2});
      slog::Relation* readrel650 = db->getRelation("$seq_at");
      $seq_atindex622 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 0, 2});
      slog::Relation* readrel652 = db->getRelation("$seq_at");
      $seq_atindex623 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 0, 2});
      slog::Relation* readrel654 = db->getRelation("$seq_at");
      $seq_atindex624 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1, 2});
      slog::Relation* readrel656 = db->getRelation("$seq_atr");
      $seq_atrindex625 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({0, 1, 2});
      slog::Relation* readrel658 = db->getRelation("$seq_atr");
      $seq_atrindex626 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({0, 1, 2});
      slog::Relation* readrel660 = db->getRelation("$seq_atr");
      $seq_atrindex627 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({0, 1, 2});
      slog::Relation* readrel662 = db->getRelation("$seq_atr");
      $seq_atrindex628 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 0, 2});
      slog::Relation* readrel664 = db->getRelation("$seq_at");
      $seq_atindex629 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 0, 2});
      slog::Relation* readrel666 = db->getRelation("$seq_at");
      $seq_atdelta638 = readrel666->getIndex(ord665, true);
      std::vector<u16> ord667({1, 0, 2});
      slog::Relation* readrel668 = db->getRelation("$seq_at");
      $seq_atindex630 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 0, 2});
      slog::Relation* readrel670 = db->getRelation("$seq_at");
      $seq_atdelta639 = readrel670->getIndex(ord669, true);
      std::vector<u16> ord671({1, 0, 2});
      slog::Relation* readrel672 = db->getRelation("$seq_at");
      $seq_atindex631 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 0, 2});
      slog::Relation* readrel674 = db->getRelation("$seq_at");
      $seq_atdelta640 = readrel674->getIndex(ord673, true);
      std::vector<u16> ord675({1, 0, 2});
      slog::Relation* readrel676 = db->getRelation("$seq_at");
      $seq_atindex632 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 0, 2});
      slog::Relation* readrel678 = db->getRelation("$seq_at");
      $seq_atdelta641 = readrel678->getIndex(ord677, true);
      std::vector<u16> ord679({0, 1, 2});
      slog::Relation* readrel680 = db->getRelation("$seq_atr");
      $seq_atrindex633 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({0, 1, 2});
      slog::Relation* readrel682 = db->getRelation("$seq_atr");
      $seq_atrdelta642 = readrel682->getIndex(ord681, true);
      std::vector<u16> ord683({0, 1, 2});
      slog::Relation* readrel684 = db->getRelation("$seq_atr");
      $seq_atrindex634 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({0, 1, 2});
      slog::Relation* readrel686 = db->getRelation("$seq_atr");
      $seq_atrdelta643 = readrel686->getIndex(ord685, true);
      std::vector<u16> ord687({0, 1, 2});
      slog::Relation* readrel688 = db->getRelation("$seq_atr");
      $seq_atrindex635 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({0, 1, 2});
      slog::Relation* readrel690 = db->getRelation("$seq_atr");
      $seq_atrdelta644 = readrel690->getIndex(ord689, true);
      std::vector<u16> ord691({0, 1, 2});
      slog::Relation* readrel692 = db->getRelation("$seq_atr");
      $seq_atrindex636 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1, 2});
      slog::Relation* readrel694 = db->getRelation("$seq_atr");
      $seq_atrdelta645 = readrel694->getIndex(ord693, true);
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("st_fromlist");
      st_fromlistindex637 = readrel696->getIndex(ord695, false);
  
    }
    ReadTask646(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c141 = v_const5feceb66ffc86f38d952786c;
      u64 v_c142 = v_constef2d127de37b942baad06145;
      u64 v_c143 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c144 = v_constd4735e3a265e16eee03f5971;
      u64 v_c145 = v_constd4735e3a265e16eee03f5971;
      u64 v_c146 = v_const2c624232cdd221771294dfbb;
      u64 v_c147 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c149 = v_constef2d127de37b942baad06145;
      u64 v_c150 = v_const5feceb66ffc86f38d952786c;
      u64 v_c151 = v_constd4735e3a265e16eee03f5971;
      u64 v_c152 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c153 = v_const2c624232cdd221771294dfbb;
      u64 v_c154 = v_constd4735e3a265e16eee03f5971;
      u64 v_c155 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c156 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c157 = v_constef2d127de37b942baad06145;
      u64 v_c158 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c159 = v_constd4735e3a265e16eee03f5971;
      u64 v_c160 = v_constd4735e3a265e16eee03f5971;
      u64 v_c161 = v_const2c624232cdd221771294dfbb;
      u64 v_c162 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c165 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex622, std::array<u64,3>{v_c152, v_c151, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex623, std::array<u64,3>{v_c154, v_c153, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex624, std::array<u64,3>{v_c156, v_c155, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex625, std::array<u64,3>{v_c157, v_c158, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex626, std::array<u64,3>{v_c159, v_c160, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex627, std::array<u64,3>{v_c161, v_c162, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex628, std::array<u64,3>{v_c163, v_c164, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex629, $seq_atdelta638, std::array<u64,3>{v_c150, v_c149, 0}, [&](const std::array<u64,3>& m697) {
          u64 v_c166 = m697[2];
          slog::join_probe_old<3,3>($seq_atindex630, $seq_atdelta639, std::array<u64,3>{v_c152, v_c151, v_c166}, [&](const std::array<u64,3>& m698) {
            slog::join_probe_old<3,3>($seq_atindex631, $seq_atdelta640, std::array<u64,3>{v_c154, v_c153, v_c166}, [&](const std::array<u64,3>& m699) {
              slog::join_probe_old<3,3>($seq_atindex632, $seq_atdelta641, std::array<u64,3>{v_c156, v_c155, v_c166}, [&](const std::array<u64,3>& m700) {
                slog::join_probe_old<3,3>($seq_atrindex633, $seq_atrdelta642, std::array<u64,3>{v_c157, v_c158, v_c166}, [&](const std::array<u64,3>& m701) {
                  slog::join_probe_old<3,3>($seq_atrindex634, $seq_atrdelta643, std::array<u64,3>{v_c159, v_c160, v_c166}, [&](const std::array<u64,3>& m702) {
                    slog::join_probe_old<3,3>($seq_atrindex635, $seq_atrdelta644, std::array<u64,3>{v_c161, v_c162, v_c166}, [&](const std::array<u64,3>& m703) {
                      slog::join_probe_old<3,3>($seq_atrindex636, $seq_atrdelta645, std::array<u64,3>{v_c163, v_c164, v_c166}, [&](const std::array<u64,3>& m704) {
                        slog::join_probe<2,2>(st_fromlistindex637, std::array<u64,2>{v_c165, v_c166}, [&](const std::array<u64,2>& m705) {
                          bool ok706 = true;
                          u64 v_c167 = _prim_aslst(db, v_c166, &ok706);
                          if (!ok706) return;
                          u64 v_c168 = _prim_llen(db, v_c167);
                          if (v_c168 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c140 != v_c168) return;
                          bool ok707 = true;
                          u64 v_c169 = _prim_lref(db, v_c167, v_c141, &ok707);
                          if (!ok707) return;
                          if (v_c142 != v_c169) return;
                          bool ok708 = true;
                          u64 v_c170 = _prim_lref(db, v_c167, v_c143, &ok708);
                          if (!ok708) return;
                          if (v_c144 != v_c170) return;
                          bool ok709 = true;
                          u64 v_c171 = _prim_lref(db, v_c167, v_c145, &ok709);
                          if (!ok709) return;
                          if (v_c146 != v_c171) return;
                          bool ok710 = true;
                          u64 v_c172 = _prim_lref(db, v_c167, v_c147, &ok710);
                          if (!ok710) return;
                          if (v_c148 != v_c172) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:st_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask646* _cont = new ReadTask646(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask646(db,b), false);
  // (crule (pre) (scan temp7LNh1339 l n q u v) (body (join pbranch (1 2 3 4 0) 4 q n u v __t7pc5201)) (head (mkstruct st_diff (1 2 0) __9kFk765 l __t7pc5201)) set.slog:140 #f)
  class ReadTask712 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex711;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff");
      outer_rel = db->getRelation("temp7LNh1339");
      std::vector<u16> ord713({1, 2, 3, 4, 0});
      slog::Relation* readrel714 = db->getRelation("pbranch");
      pbranchindex711 = readrel714->getIndex(ord713, false);
  
    }
    ReadTask712(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c13 = _t[4];
        slog::join_probe<5,4>(pbranchindex711, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, 0}, [&](const std::array<u64,5>& m715) {
          u64 v_c173 = m715[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c173}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:temp7LNh1339", _fires);
  
      if (!_done)
      {
        ReadTask712* _cont = new ReadTask712(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask712(db,b), false);
  // (crule (pre (let __tconst6z9n537 const5feceb66ffc86f38d952786c)) (scan pbranch __t1Xgc534 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t1Xgc534 __t7CyZ536 __t3erE535) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3erE535 p m l r) (cmp lt m n) (let __t0JvE538 (band p n)) (cmp gt __t0JvE538 __tconst6z9n537)) (head (emit $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) __t7CyZ536 v l m n p q r u)) set.slog:152 #f)
  class ReadTask720 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex716;  slog::Index** pbranchindex717;  slog::Index** st_diffdelta718;  slog::Index** pbranchdelta719;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord721({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel722 = db->getRelation("$sup9688x151x0x0x0");
      head_index[0] = readrel722->getIndex(ord721, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord723({2, 0, 1});
      slog::Relation* readrel724 = db->getRelation("st_diff");
      st_diffindex716 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({2, 0, 1});
      slog::Relation* readrel726 = db->getRelation("st_diff");
      st_diffdelta718 = readrel726->getIndex(ord725, true);
      std::vector<u16> ord727({0, 1, 2, 3, 4});
      slog::Relation* readrel728 = db->getRelation("pbranch");
      pbranchindex717 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({0, 1, 2, 3, 4});
      slog::Relation* readrel730 = db->getRelation("pbranch");
      pbranchdelta719 = readrel730->getIndex(ord729, true);
  
    }
    ReadTask720(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c175 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c13 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex716, st_diffdelta718, std::array<u64,3>{v_c175, 0, 0}, [&](const std::array<u64,3>& m731) {
          u64 v_c176 = m731[1]; u64 v_c177 = m731[2];
          slog::join_probe_old<5,1>(pbranchindex717, pbranchdelta719, std::array<u64,5>{v_c177, 0, 0, 0, 0}, [&](const std::array<u64,5>& m732) {
            u64 v_c11 = m732[1]; u64 v_c10 = m732[2]; u64 v_c7 = m732[3]; u64 v_c12 = m732[4];
            u64 v_c178 = _prim_lt(db, v_c10, v_c24);
            if (v_c178 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c178) return;
            u64 v_c179 = _prim_band(db, v_c11, v_c24);
            if (v_c179 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            u64 v_c180 = _prim_gt(db, v_c179, v_c174);
            if (v_c180 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c180) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c176, v_c13, v_c7, v_c10, v_c24, v_c11, v_c23, v_c12, v_c8}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask720* _cont = new ReadTask720(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask720(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan pbranch __t88zt334 p m l r) (body (exists st_diff (1 2 0) 1 __t88zt334) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 r) (join $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 4 p l m r __t8Fy1335 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join-old st_diff (0 1 2) 3 (0 1 2) __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t7XLn338) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join st_diff_ans (0 1) 2 __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask759 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex735;  slog::Index** st_bldindex736;  slog::Index** st_mskindex737;  slog::Index** st_msk_ansindex738;  slog::Index** st_diffindex739;  slog::Index** $sup9688x142x0x0x0index740;  slog::Index** st_diffindex741;  slog::Index** st_mskindex742;  slog::Index** pbranchindex743;  slog::Index** st_diffindex744;  slog::Index** st_diffindex745;  slog::Index** st_bldindex746;  slog::Index** st_diff_ansindex747;  slog::Index** st_bld_ansindex748;  slog::Index** st_mskindex749;  slog::Index** st_msk_ansindex750;  slog::Index** st_diffindex751;  slog::Index** st_diff_ansindex752;  slog::Index** st_bld_ansindex753;  slog::Index** pbranchdelta754;  slog::Index** st_diffdelta755;  slog::Index** st_blddelta756;  slog::Index** st_mskdelta757;  slog::Index** st_diffdelta758;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("st_diff_ans");
      head_index[0] = readrel761->getIndex(ord760, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord762({1, 2, 0});
      slog::Relation* readrel763 = db->getRelation("st_diff");
      st_diffindex735 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 3, 4, 0});
      slog::Relation* readrel765 = db->getRelation("st_bld");
      st_bldindex736 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({2, 0, 1});
      slog::Relation* readrel767 = db->getRelation("st_msk");
      st_mskindex737 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 0});
      slog::Relation* readrel769 = db->getRelation("st_msk_ans");
      st_msk_ansindex738 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({1, 2, 0});
      slog::Relation* readrel771 = db->getRelation("st_diff");
      st_diffindex739 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel773 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index740 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 1, 2});
      slog::Relation* readrel775 = db->getRelation("st_diff");
      st_diffindex741 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("st_msk");
      st_mskindex742 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 3, 4, 0});
      slog::Relation* readrel779 = db->getRelation("pbranch");
      pbranchindex743 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 3, 4, 0});
      slog::Relation* readrel781 = db->getRelation("pbranch");
      pbranchdelta754 = readrel781->getIndex(ord780, true);
      std::vector<u16> ord782({0, 1, 2});
      slog::Relation* readrel783 = db->getRelation("st_diff");
      st_diffindex744 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({0, 1, 2});
      slog::Relation* readrel785 = db->getRelation("st_diff");
      st_diffdelta755 = readrel785->getIndex(ord784, true);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("st_diff");
      st_diffindex745 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 2, 3, 4, 0});
      slog::Relation* readrel789 = db->getRelation("st_bld");
      st_bldindex746 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 3, 4, 0});
      slog::Relation* readrel791 = db->getRelation("st_bld");
      st_blddelta756 = readrel791->getIndex(ord790, true);
      std::vector<u16> ord792({1, 0});
      slog::Relation* readrel793 = db->getRelation("st_diff_ans");
      st_diff_ansindex747 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("st_bld_ans");
      st_bld_ansindex748 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("st_msk");
      st_mskindex749 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("st_msk");
      st_mskdelta757 = readrel799->getIndex(ord798, true);
      std::vector<u16> ord800({0, 1});
      slog::Relation* readrel801 = db->getRelation("st_msk_ans");
      st_msk_ansindex750 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("st_diff");
      st_diffindex751 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("st_diff");
      st_diffdelta758 = readrel805->getIndex(ord804, true);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("st_diff_ans");
      st_diff_ansindex752 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({0, 1});
      slog::Relation* readrel809 = db->getRelation("st_bld_ans");
      st_bld_ansindex753 = readrel809->getIndex(ord808, false);
  
    }
    ReadTask759(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c182 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c12 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex735, std::array<u64,3>{v_c182, 0, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex736, std::array<u64,5>{v_c11, v_c10, v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex737, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex738, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex739, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x142x0x0x0index740, std::array<u64,9>{v_c11, v_c7, v_c10, v_c12, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m810) {
          u64 v_c183 = m810[4]; u64 v_c24 = m810[5]; u64 v_c23 = m810[6]; u64 v_c8 = m810[7]; u64 v_c13 = m810[8];
          u64 v_c184 = _prim_lt(db, v_c24, v_c10);
          if (v_c184 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
          if (!v_c184) return;
          if (!slog::exists_probe<3,2>(st_diffindex741, std::array<u64,3>{v_c183, v_c182, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex742, std::array<u64,3>{v_c23, v_c10, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex743, pbranchdelta754, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, 0}, [&](const std::array<u64,5>& m812) {
            u64 v_c185 = m812[4];
            slog::join_probe_old<3,3>(st_diffindex744, st_diffdelta755, std::array<u64,3>{v_c183, v_c182, v_c185}, [&](const std::array<u64,3>& m813) {
              if (!slog::exists_probe<3,2>(st_diffindex745, std::array<u64,3>{v_c12, v_c185, 0})) return;
              slog::join_probe_old<5,3>(st_bldindex746, st_blddelta756, std::array<u64,5>{v_c11, v_c10, v_c7, 0, 0}, [&](const std::array<u64,5>& m814) {
                u64 v_c6 = m814[3]; u64 v_c186 = m814[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex747, std::array<u64,2>{v_c6, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex748, std::array<u64,2>{v_c186, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex749, st_mskdelta757, std::array<u64,3>{v_c23, v_c10, 0}, [&](const std::array<u64,3>& m815) {
                  u64 v_c187 = m815[2];
                  slog::join_probe<2,2>(st_msk_ansindex750, std::array<u64,2>{v_c187, v_c11}, [&](const std::array<u64,2>& m816) {
                    slog::join_probe_old<3,2>(st_diffindex751, st_diffdelta758, std::array<u64,3>{v_c12, v_c185, 0}, [&](const std::array<u64,3>& m817) {
                      u64 v_c188 = m817[2];
                      slog::join_probe<2,2>(st_diff_ansindex752, std::array<u64,2>{v_c188, v_c6}, [&](const std::array<u64,2>& m818) {
                        slog::join_probe<2,1>(st_bld_ansindex753, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m819) {
                          u64 v_c27 = m819[1];
                          u64 v_c189 = _prim_band(db, v_c23, v_c10);
                          if (v_c189 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c190 = _prim_gt(db, v_c189, v_c181);
                          if (v_c190 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c190) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c183, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask759* _cont = new ReadTask759(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask759(db,b), false);
  // (crule (pre) (scan pleaf __t44oW413 k) (body (join-old st_ins (1 2 0) 2 (1 2 0) __t44oW413 k __t7MBh414)) (head (emit st_ins_ans (0 1) __t7MBh414 __t44oW413)) set.slog:49 #f)
  class ReadTask823 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex821;  slog::Index** st_insdelta822;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("st_ins_ans");
      head_index[0] = readrel825->getIndex(ord824, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("st_ins");
      st_insindex821 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("st_ins");
      st_insdelta822 = readrel829->getIndex(ord828, true);
  
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
        u64 v_c191 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe_old<3,2>(st_insindex821, st_insdelta822, std::array<u64,3>{v_c191, v_c17, 0}, [&](const std::array<u64,3>& m830) {
          u64 v_c192 = m830[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c192, v_c191}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:49", "delta:pleaf", _fires);
  
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
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan st_union __t3N33245 __t2RvE244 __t8HsZ249) (body (exists $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t3N33245) (exists $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) 1 __t3N33245) (join-old st_union (2 0 1) 1 (2 0 1) __t8HsZ249 __t4eoh250 l) (exists $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3N33245 l) (exists $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t3N33245 l) (exists st_union_ans (0 1) 1 __t4eoh250) (join pbranch (3 0 1 2 4) 2 l __t2RvE244 p m r) (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t3N33245) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t3N33245 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t8HsZ249) (exists st_msk (1 2 0) 2 q m) (join $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t3N33245 n q u v __t3q0j248) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask852 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x0index831;  slog::Index** $sup9688x103x0x0x1index832;  slog::Index** st_unionindex833;  slog::Index** $sup9688x103x0x0x0index834;  slog::Index** $sup9688x103x0x0x1index835;  slog::Index** st_union_ansindex836;  slog::Index** pbranchindex837;  slog::Index** $sup9688x103x0x0x1index838;  slog::Index** st_mskindex839;  slog::Index** st_msk_ansindex840;  slog::Index** $sup9688x103x0x0x0index841;  slog::Index** pbranchindex842;  slog::Index** st_mskindex843;  slog::Index** $sup9688x103x0x0x1index844;  slog::Index** pbranchindex845;  slog::Index** st_mskindex846;  slog::Index** st_msk_ansindex847;  slog::Index** st_union_ansindex848;  slog::Index** st_uniondelta849;  slog::Index** pbranchdelta850;  slog::Index** st_mskdelta851;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord853({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel854 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index831 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel856 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index832 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({2, 0, 1});
      slog::Relation* readrel858 = db->getRelation("st_union");
      st_unionindex833 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({2, 0, 1});
      slog::Relation* readrel860 = db->getRelation("st_union");
      st_uniondelta849 = readrel860->getIndex(ord859, true);
      std::vector<u16> ord861({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel862 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index834 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel864 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index835 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({0, 1});
      slog::Relation* readrel866 = db->getRelation("st_union_ans");
      st_union_ansindex836 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({3, 0, 1, 2, 4});
      slog::Relation* readrel868 = db->getRelation("pbranch");
      pbranchindex837 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel870 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index838 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({2, 0, 1});
      slog::Relation* readrel872 = db->getRelation("st_msk");
      st_mskindex839 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 0});
      slog::Relation* readrel874 = db->getRelation("st_msk_ans");
      st_msk_ansindex840 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel876 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index841 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 3, 4, 0});
      slog::Relation* readrel878 = db->getRelation("pbranch");
      pbranchindex842 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({1, 2, 0});
      slog::Relation* readrel880 = db->getRelation("st_msk");
      st_mskindex843 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel882 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index844 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 3, 4, 0});
      slog::Relation* readrel884 = db->getRelation("pbranch");
      pbranchindex845 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 3, 4, 0});
      slog::Relation* readrel886 = db->getRelation("pbranch");
      pbranchdelta850 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("st_msk");
      st_mskindex846 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("st_msk");
      st_mskdelta851 = readrel890->getIndex(ord889, true);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("st_msk_ans");
      st_msk_ansindex847 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({0, 1});
      slog::Relation* readrel894 = db->getRelation("st_union_ans");
      st_union_ansindex848 = readrel894->getIndex(ord893, false);
  
    }
    ReadTask852(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c194 = _t[0];
        u64 v_c195 = _t[1];
        u64 v_c196 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x103x0x0x0index831, std::array<u64,9>{v_c194, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x103x0x0x1index832, std::array<u64,10>{v_c194, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex833, st_uniondelta849, std::array<u64,3>{v_c196, 0, 0}, [&](const std::array<u64,3>& m895) {
          u64 v_c197 = m895[1]; u64 v_c7 = m895[2];
          if (!slog::exists_probe<9,2>($sup9688x103x0x0x0index834, std::array<u64,9>{v_c194, v_c7, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup9688x103x0x0x1index835, std::array<u64,10>{v_c194, v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_union_ansindex836, std::array<u64,2>{v_c197, 0})) return;
          slog::join_probe<5,2>(pbranchindex837, std::array<u64,5>{v_c7, v_c195, 0, 0, 0}, [&](const std::array<u64,5>& m896) {
            u64 v_c11 = m896[2]; u64 v_c10 = m896[3]; u64 v_c12 = m896[4];
            if (!slog::exists_probe<10,5>($sup9688x103x0x0x1index838, std::array<u64,10>{v_c7, v_c10, v_c11, v_c12, v_c194, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex839, std::array<u64,3>{v_c10, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex840, std::array<u64,2>{v_c11, 0})) return;
            slog::join_probe<9,5>($sup9688x103x0x0x0index841, std::array<u64,9>{v_c7, v_c10, v_c11, v_c12, v_c194, 0, 0, 0, 0}, [&](const std::array<u64,9>& m897) {
              u64 v_c24 = m897[5]; u64 v_c23 = m897[6]; u64 v_c8 = m897[7]; u64 v_c13 = m897[8];
              u64 v_c198 = _prim_lt(db, v_c24, v_c10);
              if (v_c198 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
              if (!v_c198) return;
              if (!slog::exists_probe<5,5>(pbranchindex842, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, v_c196})) return;
              if (!slog::exists_probe<3,2>(st_mskindex843, std::array<u64,3>{v_c23, v_c10, 0})) return;
              slog::join_probe<10,9>($sup9688x103x0x0x1index844, std::array<u64,10>{v_c7, v_c10, v_c11, v_c12, v_c194, v_c24, v_c23, v_c8, v_c13, 0}, [&](const std::array<u64,10>& m899) {
                u64 v_c199 = m899[9];
                slog::join_probe_old<5,5>(pbranchindex845, pbranchdelta850, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, v_c196}, [&](const std::array<u64,5>& m900) {
                  slog::join_probe_old<3,3>(st_mskindex846, st_mskdelta851, std::array<u64,3>{v_c23, v_c10, v_c199}, [&](const std::array<u64,3>& m901) {
                    slog::join_probe<2,2>(st_msk_ansindex847, std::array<u64,2>{v_c199, v_c11}, [&](const std::array<u64,2>& m902) {
                      slog::join_probe<2,1>(st_union_ansindex848, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m903) {
                        u64 v_c6 = m903[1];
                        u64 v_c200 = _prim_band(db, v_c23, v_c10);
                        if (v_c200 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c201 = _prim_lt(db, v_c200, v_c193);
                        if (v_c201 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c201) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c194, v_c6, v_c10, v_c11, v_c12});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c11, v_c10, v_c6, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask852* _cont = new ReadTask852(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask852(db,b), false);
  // (crule (pre) (scan temp4FcU1416 k p t) (body (join pleaf (1 0) 1 k __t9ved580)) (head (mkstruct st_join (1 2 3 4 0) __9BEY797 k __t9ved580 p t)) set.slog:55 #f)
  class ReadTask906 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex905;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join");
      outer_rel = db->getRelation("temp4FcU1416");
      std::vector<u16> ord907({1, 0});
      slog::Relation* readrel908 = db->getRelation("pleaf");
      pleafindex905 = readrel908->getIndex(ord907, false);
  
    }
    ReadTask906(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c202 = _t[2];
        slog::join_probe<2,1>(pleafindex905, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m909) {
          u64 v_c203 = m909[1];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c17, v_c203, v_c11, v_c202}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:temp4FcU1416", _fires);
  
      if (!_done)
      {
        ReadTask906* _cont = new ReadTask906(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask906(db,b), false);
  // (crule (pre) (scan pbranch __t6acj524 q n u v) (body (join st_union (2 0 1) 1 __t6acj524 __t5NEh522 __t7NAj523) (join pbranch (0 1 2 3 4) 1 __t7NAj523 p m l r) (cmp lt n m)) (head (emit $sup9688x110x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t5NEh522 l n p r __t7NAj523 __t6acj524 u v)) set.slog:111 #f)
  class ReadTask912 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex910;  slog::Index** pbranchindex911;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord913({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel914 = db->getRelation("$sup9688x110x0x0x0");
      head_index[0] = readrel914->getIndex(ord913, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord915({2, 0, 1});
      slog::Relation* readrel916 = db->getRelation("st_union");
      st_unionindex910 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({0, 1, 2, 3, 4});
      slog::Relation* readrel918 = db->getRelation("pbranch");
      pbranchindex911 = readrel918->getIndex(ord917, false);
  
    }
    ReadTask912(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c204 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c13 = _t[4];
        slog::join_probe<3,1>(st_unionindex910, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m919) {
          u64 v_c205 = m919[1]; u64 v_c206 = m919[2];
          slog::join_probe<5,1>(pbranchindex911, std::array<u64,5>{v_c206, 0, 0, 0, 0}, [&](const std::array<u64,5>& m920) {
            u64 v_c11 = m920[1]; u64 v_c10 = m920[2]; u64 v_c7 = m920[3]; u64 v_c12 = m920[4];
            u64 v_c207 = _prim_lt(db, v_c24, v_c10);
            if (v_c207 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
            if (!v_c207) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c10, v_c23, v_c205, v_c7, v_c24, v_c11, v_c12, v_c206, v_c204, v_c8, v_c13}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask912* _cont = new ReadTask912(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask912(db,b), false);
  // (crule (pre (let __tconst3inB738 conste3776bfed7f405de8017ecfa) (let __tconst4Wut540 const6b86b273ff34fce19d6b804e) (let __tconst5bud543 const2c624232cdd221771294dfbb) (let __tconst4ddf539 constd4735e3a265e16eee03f5971)) (probe st_ins (2 0 1) 1 __tconst5bud543 __t19Ry544 __v0) (body (exists st_ins (2 0 1) 1 __tconst4Wut540) (exists st_ins_ans (1 0) 1 __v0) (exists st_ins_ans (0 1) 1 __t19Ry544) (join _enum (1 0) 1 __tconst3inB738 __t86kg541) (join st_ins (1 2 0) 2 __t86kg541 __tconst4Wut540 __t7kvj542) (join st_ins_ans (0 1) 2 __t7kvj542 __v0) (join st_ins_ans (0 1) 1 __t19Ry544 __v1)) (head (mkstruct st_ins (1 2 0) __8Yai739 __v1 __tconst4ddf539)) st_basic.slog:15 #f)
  class ReadTask929 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex922;  slog::Index** st_ins_ansindex923;  slog::Index** st_ins_ansindex924;  slog::Index** _enumindex925;  slog::Index** st_insindex926;  slog::Index** st_ins_ansindex927;  slog::Index** st_ins_ansindex928;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord930({2, 0, 1});
      slog::Relation* readrel931 = db->getRelation("st_ins");
      driver_index = readrel931->getIndex(ord930, true);
      std::vector<u16> ord932({2, 0, 1});
      slog::Relation* readrel933 = db->getRelation("st_ins");
      st_insindex922 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 0});
      slog::Relation* readrel935 = db->getRelation("st_ins_ans");
      st_ins_ansindex923 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({0, 1});
      slog::Relation* readrel937 = db->getRelation("st_ins_ans");
      st_ins_ansindex924 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 0});
      slog::Relation* readrel939 = db->getRelation("_enum");
      _enumindex925 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 2, 0});
      slog::Relation* readrel941 = db->getRelation("st_ins");
      st_insindex926 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({0, 1});
      slog::Relation* readrel943 = db->getRelation("st_ins_ans");
      st_ins_ansindex927 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({0, 1});
      slog::Relation* readrel945 = db->getRelation("st_ins_ans");
      st_ins_ansindex928 = readrel945->getIndex(ord944, false);
  
    }
    ReadTask929(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c208 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c209 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c210 = v_const2c624232cdd221771294dfbb;
      u64 v_c211 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c210, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m946) {
        u64 v_c212 = m946[1];
        u64 v_c6 = m946[2];
        if (buckethash(v_c212) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex922, std::array<u64,3>{v_c209, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex923, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex924, std::array<u64,2>{v_c212, 0})) return;
        slog::join_probe<2,1>(_enumindex925, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m947) {
          u64 v_c213 = m947[1];
          slog::join_probe<3,2>(st_insindex926, std::array<u64,3>{v_c213, v_c209, 0}, [&](const std::array<u64,3>& m948) {
            u64 v_c214 = m948[2];
            slog::join_probe<2,2>(st_ins_ansindex927, std::array<u64,2>{v_c214, v_c6}, [&](const std::array<u64,2>& m949) {
              slog::join_probe<2,1>(st_ins_ansindex928, std::array<u64,2>{v_c212, 0}, [&](const std::array<u64,2>& m950) {
                u64 v_c15 = m950[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c211}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask929* _cont = new ReadTask929(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask929(db,b), false);
  // (crule (pre (let __tconst6nKu197 constd4735e3a265e16eee03f5971)) (scan canon s) (body) (head (mkstruct st_del (1 2 0) __2ubc973 s __tconst6nKu197)) st_basic.slog:23 #f)
  class ReadTask951 : public slog::Task
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
      head_rel[0] = db->getRelation("st_del");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask951(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c215 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c114 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c114, v_c215}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:23", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask951* _cont = new ReadTask951(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask951(db,b), false);
  // (crule (pre) (scan $sup9688x36x0x0x0 __d0 p0 p1 t0 t1) (body (let __t5HrQ362 (bxor p0 p1))) (head (emit-temp temp3vnE1273 __t5HrQ362)) set.slog:37 #f)
  class ReadTask952 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3vnE1273");
      outer_rel = db->getRelation("$sup9688x36x0x0x0");
  
    }
    ReadTask952(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c38 = _t[3];
        u64 v_c39 = _t[4];
        u64 v_c216 = _prim_bxor(db, v_c36, v_c37);
        if (v_c216 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c216});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask952* _cont = new ReadTask952(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask952(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk6vTN1327 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk6vTN1327) (letp chk9EjA1328 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk9EjA1328) (letp chk1Abp1329 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk1Abp1329) (letp chk1f4i1330 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk1f4i1330) (letp chk2JeN1331 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk2JeN1331)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask962 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex953;  slog::Index** $seq_atindex954;  slog::Index** $seq_atindex955;  slog::Index** $seq_atindex956;  slog::Index** $seq_atrindex957;  slog::Index** $seq_atrindex958;  slog::Index** $seq_atrindex959;  slog::Index** st_fromlistindex960;  slog::Index** st_fromlist_ansindex961;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord963({0});
      slog::Relation* readrel964 = db->getRelation("canon");
      head_index[0] = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({0, 1, 2});
      slog::Relation* readrel966 = db->getRelation("$seq_atr");
      driver_index = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({1, 0, 2});
      slog::Relation* readrel968 = db->getRelation("$seq_at");
      $seq_atindex953 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 0, 2});
      slog::Relation* readrel970 = db->getRelation("$seq_at");
      $seq_atindex954 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 0, 2});
      slog::Relation* readrel972 = db->getRelation("$seq_at");
      $seq_atindex955 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({1, 0, 2});
      slog::Relation* readrel974 = db->getRelation("$seq_at");
      $seq_atindex956 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 1, 2});
      slog::Relation* readrel976 = db->getRelation("$seq_atr");
      $seq_atrindex957 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({0, 1, 2});
      slog::Relation* readrel978 = db->getRelation("$seq_atr");
      $seq_atrindex958 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({0, 1, 2});
      slog::Relation* readrel980 = db->getRelation("$seq_atr");
      $seq_atrindex959 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 0});
      slog::Relation* readrel982 = db->getRelation("st_fromlist");
      st_fromlistindex960 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({0, 1});
      slog::Relation* readrel984 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex961 = readrel984->getIndex(ord983, false);
  
    }
    ReadTask962(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c141 = v_const5feceb66ffc86f38d952786c;
      u64 v_c142 = v_constef2d127de37b942baad06145;
      u64 v_c143 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c144 = v_constd4735e3a265e16eee03f5971;
      u64 v_c145 = v_constd4735e3a265e16eee03f5971;
      u64 v_c146 = v_const2c624232cdd221771294dfbb;
      u64 v_c147 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c149 = v_constef2d127de37b942baad06145;
      u64 v_c150 = v_const5feceb66ffc86f38d952786c;
      u64 v_c151 = v_constd4735e3a265e16eee03f5971;
      u64 v_c152 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c153 = v_const2c624232cdd221771294dfbb;
      u64 v_c154 = v_constd4735e3a265e16eee03f5971;
      u64 v_c155 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c156 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c157 = v_constef2d127de37b942baad06145;
      u64 v_c158 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c159 = v_constd4735e3a265e16eee03f5971;
      u64 v_c160 = v_constd4735e3a265e16eee03f5971;
      u64 v_c161 = v_const2c624232cdd221771294dfbb;
      u64 v_c162 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c163, v_c164, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m985) {
        u64 v_c166 = m985[2];
        if (buckethash(v_c166) != bucket) return;
        slog::join_probe<3,3>($seq_atindex953, std::array<u64,3>{v_c150, v_c149, v_c166}, [&](const std::array<u64,3>& m986) {
          slog::join_probe<3,3>($seq_atindex954, std::array<u64,3>{v_c152, v_c151, v_c166}, [&](const std::array<u64,3>& m987) {
            slog::join_probe<3,3>($seq_atindex955, std::array<u64,3>{v_c154, v_c153, v_c166}, [&](const std::array<u64,3>& m988) {
              slog::join_probe<3,3>($seq_atindex956, std::array<u64,3>{v_c156, v_c155, v_c166}, [&](const std::array<u64,3>& m989) {
                slog::join_probe<3,3>($seq_atrindex957, std::array<u64,3>{v_c157, v_c158, v_c166}, [&](const std::array<u64,3>& m990) {
                  slog::join_probe<3,3>($seq_atrindex958, std::array<u64,3>{v_c159, v_c160, v_c166}, [&](const std::array<u64,3>& m991) {
                    slog::join_probe<3,3>($seq_atrindex959, std::array<u64,3>{v_c161, v_c162, v_c166}, [&](const std::array<u64,3>& m992) {
                      slog::join_probe<2,1>(st_fromlistindex960, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m993) {
                        u64 v_c165 = m993[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex961, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m994) {
                          u64 v_c12 = m994[1];
                          bool ok995 = true;
                          u64 v_c167 = _prim_aslst(db, v_c166, &ok995);
                          if (!ok995) return;
                          u64 v_c217 = _prim_llen(db, v_c167);
                          if (v_c217 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c140 != v_c217) return;
                          bool ok996 = true;
                          u64 v_c218 = _prim_lref(db, v_c167, v_c141, &ok996);
                          if (!ok996) return;
                          if (v_c142 != v_c218) return;
                          bool ok997 = true;
                          u64 v_c219 = _prim_lref(db, v_c167, v_c143, &ok997);
                          if (!ok997) return;
                          if (v_c144 != v_c219) return;
                          bool ok998 = true;
                          u64 v_c220 = _prim_lref(db, v_c167, v_c145, &ok998);
                          if (!ok998) return;
                          if (v_c146 != v_c220) return;
                          bool ok999 = true;
                          u64 v_c221 = _prim_lref(db, v_c167, v_c147, &ok999);
                          if (!ok999) return;
                          if (v_c148 != v_c221) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask962* _cont = new ReadTask962(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask962(db,b), false);
  // (crule (pre) (scan st_ins __t7Vi1397 __t9Bxs396 k) (body (join pleaf (0 1) 1 __t9Bxs396 j) (neq j k)) (head (emit-temp temp7DYO1402 __t9Bxs396 j k) (mkstruct pleaf (1 0) __t4eWA395 k)) set.slog:50 #f)
  class ReadTask1001 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1000;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7DYO1402");
      head_rel[1] = db->getRelation("pleaf");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord1002({0, 1});
      slog::Relation* readrel1003 = db->getRelation("pleaf");
      pleafindex1000 = readrel1003->getIndex(ord1002, false);
  
    }
    ReadTask1001(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c222 = _t[0];
        u64 v_c223 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<2,1>(pleafindex1000, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1004) {
          u64 v_c138 = m1004[1];
          if (v_c138 == v_c17) return;
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c223, v_c138, v_c17});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1001* _cont = new ReadTask1001(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1001(db,b), false);
  // (crule (pre) (scan st_msk_ans __t3Qtm239 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t3Qtm239 p n) (exists $sup9688x120x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists st_join (1 2 3 4 0) 1 p) (join-old pbranch (1 2 3 4 0) 1 (1 2 3 4 0) p m l r __t7ZZP236) (cmp lt m n) (exists st_join (1 2 3 4 0) 2 p __t7ZZP236) (exists st_union (1 2 0) 1 __t7ZZP236) (join-old $sup9688x120x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 (1 2 4 6 7 3 0 5 8 9 10) l m p r __t7ZZP236 n __t3tZ8235 q __t8STz237 u v) (neq q __v0) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8STz237) (exists st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t7ZZP236 q __t8STz237 __t1ZYa238) (join-old st_union (0 1 2) 3 (0 1 2) __t3tZ8235 __t7ZZP236 __t8STz237) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask1024 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex1005;  slog::Index** $sup9688x120x0x0x0index1006;  slog::Index** pbranchindex1007;  slog::Index** st_joinindex1008;  slog::Index** pbranchindex1009;  slog::Index** st_joinindex1010;  slog::Index** st_unionindex1011;  slog::Index** $sup9688x120x0x0x0index1012;  slog::Index** pbranchindex1013;  slog::Index** st_unionindex1014;  slog::Index** st_joinindex1015;  slog::Index** st_unionindex1016;  slog::Index** st_join_ansindex1017;  slog::Index** st_mskdelta1018;  slog::Index** pbranchdelta1019;  slog::Index** $sup9688x120x0x0x0delta1020;  slog::Index** pbranchdelta1021;  slog::Index** st_joindelta1022;  slog::Index** st_uniondelta1023;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1025({0, 1});
      slog::Relation* readrel1026 = db->getRelation("st_union_ans");
      head_index[0] = readrel1026->getIndex(ord1025, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1027({0, 1, 2});
      slog::Relation* readrel1028 = db->getRelation("st_msk");
      st_mskindex1005 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({0, 1, 2});
      slog::Relation* readrel1030 = db->getRelation("st_msk");
      st_mskdelta1018 = readrel1030->getIndex(ord1029, true);
      std::vector<u16> ord1031({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel1032 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index1006 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({2, 0, 1, 3, 4});
      slog::Relation* readrel1034 = db->getRelation("pbranch");
      pbranchindex1007 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 3, 4, 0});
      slog::Relation* readrel1036 = db->getRelation("st_join");
      st_joinindex1008 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({1, 2, 3, 4, 0});
      slog::Relation* readrel1038 = db->getRelation("pbranch");
      pbranchindex1009 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({1, 2, 3, 4, 0});
      slog::Relation* readrel1040 = db->getRelation("pbranch");
      pbranchdelta1019 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({1, 2, 3, 4, 0});
      slog::Relation* readrel1042 = db->getRelation("st_join");
      st_joinindex1010 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({1, 2, 0});
      slog::Relation* readrel1044 = db->getRelation("st_union");
      st_unionindex1011 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1046 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index1012 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1048 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0delta1020 = readrel1048->getIndex(ord1047, true);
      std::vector<u16> ord1049({1, 2, 3, 4, 0});
      slog::Relation* readrel1050 = db->getRelation("pbranch");
      pbranchindex1013 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 2, 3, 4, 0});
      slog::Relation* readrel1052 = db->getRelation("pbranch");
      pbranchdelta1021 = readrel1052->getIndex(ord1051, true);
      std::vector<u16> ord1053({0, 1, 2});
      slog::Relation* readrel1054 = db->getRelation("st_union");
      st_unionindex1014 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({1, 2, 3, 4, 0});
      slog::Relation* readrel1056 = db->getRelation("st_join");
      st_joinindex1015 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({1, 2, 3, 4, 0});
      slog::Relation* readrel1058 = db->getRelation("st_join");
      st_joindelta1022 = readrel1058->getIndex(ord1057, true);
      std::vector<u16> ord1059({0, 1, 2});
      slog::Relation* readrel1060 = db->getRelation("st_union");
      st_unionindex1016 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({0, 1, 2});
      slog::Relation* readrel1062 = db->getRelation("st_union");
      st_uniondelta1023 = readrel1062->getIndex(ord1061, true);
      std::vector<u16> ord1063({0, 1});
      slog::Relation* readrel1064 = db->getRelation("st_join_ans");
      st_join_ansindex1017 = readrel1064->getIndex(ord1063, false);
  
    }
    ReadTask1024(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c224 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex1005, st_mskdelta1018, std::array<u64,3>{v_c224, 0, 0}, [&](const std::array<u64,3>& m1065) {
          u64 v_c11 = m1065[1]; u64 v_c24 = m1065[2];
          if (!slog::exists_probe<11,2>($sup9688x120x0x0x0index1006, std::array<u64,11>{v_c24, v_c11, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1007, std::array<u64,5>{v_c24, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(st_joinindex1008, std::array<u64,5>{v_c11, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(pbranchindex1009, pbranchdelta1019, std::array<u64,5>{v_c11, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1066) {
            u64 v_c10 = m1066[1]; u64 v_c7 = m1066[2]; u64 v_c12 = m1066[3]; u64 v_c225 = m1066[4];
            u64 v_c226 = _prim_lt(db, v_c10, v_c24);
            if (v_c226 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c226) return;
            if (!slog::exists_probe<5,2>(st_joinindex1010, std::array<u64,5>{v_c11, v_c225, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_unionindex1011, std::array<u64,3>{v_c225, 0, 0})) return;
            slog::join_probe_old<11,6>($sup9688x120x0x0x0index1012, $sup9688x120x0x0x0delta1020, std::array<u64,11>{v_c7, v_c10, v_c11, v_c12, v_c225, v_c24, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1068) {
              u64 v_c227 = m1068[6]; u64 v_c23 = m1068[7]; u64 v_c228 = m1068[8]; u64 v_c8 = m1068[9]; u64 v_c13 = m1068[10];
              if (v_c23 == v_c6) return;
              slog::join_probe_old<5,5>(pbranchindex1013, pbranchdelta1021, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, v_c228}, [&](const std::array<u64,5>& m1069) {
                if (!slog::exists_probe<3,3>(st_unionindex1014, std::array<u64,3>{v_c227, v_c225, v_c228})) return;
                slog::join_probe_old<5,4>(st_joinindex1015, st_joindelta1022, std::array<u64,5>{v_c11, v_c225, v_c23, v_c228, 0}, [&](const std::array<u64,5>& m1070) {
                  u64 v_c229 = m1070[4];
                  slog::join_probe_old<3,3>(st_unionindex1016, st_uniondelta1023, std::array<u64,3>{v_c227, v_c225, v_c228}, [&](const std::array<u64,3>& m1071) {
                    slog::join_probe<2,1>(st_join_ansindex1017, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1072) {
                      u64 v_c27 = m1072[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c227, v_c27}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1024* _cont = new ReadTask1024(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1024(db,b), false);
  // (crule (pre) (scan st_diff_ans __t6cu0410 __v0) (body (exists st_bld (3 0 1 2 4) 1 __v0) (join-old st_diff (0 1 2) 1 (0 1 2) __t6cu0410 l u) (exists pbranch (3 0 1 2 4) 1 u) (exists pbranch (3 0 1 2 4) 1 l) (join-old $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 (1 5 0 2 3 4 6) l u __t5pD6408 m p r v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_bld (1 2 3 4 0) 3 p m __v0) (exists st_diff (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t9ous406) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3cJ7407) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m __v0 __v1 __t9obY409) (exists st_diff_ans (1 0) 1 __v1) (exists st_bld_ans (0 1) 1 __t9obY409) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (join-old st_diff_ans (0 1) 2 (0 1) __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask1099 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex1073;  slog::Index** st_diffindex1074;  slog::Index** pbranchindex1075;  slog::Index** pbranchindex1076;  slog::Index** $sup9688x136x0x0x0index1077;  slog::Index** pbranchindex1078;  slog::Index** st_bldindex1079;  slog::Index** st_diffindex1080;  slog::Index** pbranchindex1081;  slog::Index** st_diffindex1082;  slog::Index** pbranchindex1083;  slog::Index** st_diffindex1084;  slog::Index** st_bldindex1085;  slog::Index** st_diff_ansindex1086;  slog::Index** st_bld_ansindex1087;  slog::Index** st_diffindex1088;  slog::Index** st_diff_ansindex1089;  slog::Index** st_bld_ansindex1090;  slog::Index** st_diffdelta1091;  slog::Index** $sup9688x136x0x0x0delta1092;  slog::Index** pbranchdelta1093;  slog::Index** pbranchdelta1094;  slog::Index** st_diffdelta1095;  slog::Index** st_blddelta1096;  slog::Index** st_diffdelta1097;  slog::Index** st_diff_ansdelta1098;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1100({0, 1});
      slog::Relation* readrel1101 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1101->getIndex(ord1100, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord1102({3, 0, 1, 2, 4});
      slog::Relation* readrel1103 = db->getRelation("st_bld");
      st_bldindex1073 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1, 2});
      slog::Relation* readrel1105 = db->getRelation("st_diff");
      st_diffindex1074 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({0, 1, 2});
      slog::Relation* readrel1107 = db->getRelation("st_diff");
      st_diffdelta1091 = readrel1107->getIndex(ord1106, true);
      std::vector<u16> ord1108({3, 0, 1, 2, 4});
      slog::Relation* readrel1109 = db->getRelation("pbranch");
      pbranchindex1075 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({3, 0, 1, 2, 4});
      slog::Relation* readrel1111 = db->getRelation("pbranch");
      pbranchindex1076 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1113 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index1077 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1115 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0delta1092 = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({1, 2, 3, 4, 0});
      slog::Relation* readrel1117 = db->getRelation("pbranch");
      pbranchindex1078 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 2, 3, 4, 0});
      slog::Relation* readrel1119 = db->getRelation("st_bld");
      st_bldindex1079 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 2, 0});
      slog::Relation* readrel1121 = db->getRelation("st_diff");
      st_diffindex1080 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 2, 3, 4, 0});
      slog::Relation* readrel1123 = db->getRelation("pbranch");
      pbranchindex1081 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 2, 3, 4, 0});
      slog::Relation* readrel1125 = db->getRelation("pbranch");
      pbranchdelta1093 = readrel1125->getIndex(ord1124, true);
      std::vector<u16> ord1126({2, 0, 1});
      slog::Relation* readrel1127 = db->getRelation("st_diff");
      st_diffindex1082 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 2, 3, 4, 0});
      slog::Relation* readrel1129 = db->getRelation("pbranch");
      pbranchindex1083 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 2, 3, 4, 0});
      slog::Relation* readrel1131 = db->getRelation("pbranch");
      pbranchdelta1094 = readrel1131->getIndex(ord1130, true);
      std::vector<u16> ord1132({0, 1, 2});
      slog::Relation* readrel1133 = db->getRelation("st_diff");
      st_diffindex1084 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({0, 1, 2});
      slog::Relation* readrel1135 = db->getRelation("st_diff");
      st_diffdelta1095 = readrel1135->getIndex(ord1134, true);
      std::vector<u16> ord1136({1, 2, 3, 4, 0});
      slog::Relation* readrel1137 = db->getRelation("st_bld");
      st_bldindex1085 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({1, 2, 3, 4, 0});
      slog::Relation* readrel1139 = db->getRelation("st_bld");
      st_blddelta1096 = readrel1139->getIndex(ord1138, true);
      std::vector<u16> ord1140({1, 0});
      slog::Relation* readrel1141 = db->getRelation("st_diff_ans");
      st_diff_ansindex1086 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({0, 1});
      slog::Relation* readrel1143 = db->getRelation("st_bld_ans");
      st_bld_ansindex1087 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 2, 0});
      slog::Relation* readrel1145 = db->getRelation("st_diff");
      st_diffindex1088 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({1, 2, 0});
      slog::Relation* readrel1147 = db->getRelation("st_diff");
      st_diffdelta1097 = readrel1147->getIndex(ord1146, true);
      std::vector<u16> ord1148({0, 1});
      slog::Relation* readrel1149 = db->getRelation("st_diff_ans");
      st_diff_ansindex1089 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({0, 1});
      slog::Relation* readrel1151 = db->getRelation("st_diff_ans");
      st_diff_ansdelta1098 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({0, 1});
      slog::Relation* readrel1153 = db->getRelation("st_bld_ans");
      st_bld_ansindex1090 = readrel1153->getIndex(ord1152, false);
  
    }
    ReadTask1099(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c230 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex1073, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex1074, st_diffdelta1091, std::array<u64,3>{v_c230, 0, 0}, [&](const std::array<u64,3>& m1154) {
          u64 v_c7 = m1154[1]; u64 v_c8 = m1154[2];
          if (!slog::exists_probe<5,1>(pbranchindex1075, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1076, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup9688x136x0x0x0index1077, $sup9688x136x0x0x0delta1092, std::array<u64,7>{v_c7, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1155) {
            u64 v_c231 = m1155[2]; u64 v_c10 = m1155[3]; u64 v_c11 = m1155[4]; u64 v_c12 = m1155[5]; u64 v_c13 = m1155[6];
            if (!slog::exists_probe<5,4>(pbranchindex1078, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex1079, std::array<u64,5>{v_c11, v_c10, v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex1080, std::array<u64,3>{v_c12, v_c13, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1081, pbranchdelta1093, std::array<u64,5>{v_c11, v_c10, v_c8, v_c13, 0}, [&](const std::array<u64,5>& m1156) {
              u64 v_c232 = m1156[4];
              if (!slog::exists_probe<3,2>(st_diffindex1082, std::array<u64,3>{v_c232, v_c231, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1083, pbranchdelta1094, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0}, [&](const std::array<u64,5>& m1157) {
                u64 v_c233 = m1157[4];
                slog::join_probe_old<3,3>(st_diffindex1084, st_diffdelta1095, std::array<u64,3>{v_c231, v_c233, v_c232}, [&](const std::array<u64,3>& m1158) {
                  slog::join_probe_old<5,3>(st_bldindex1085, st_blddelta1096, std::array<u64,5>{v_c11, v_c10, v_c6, 0, 0}, [&](const std::array<u64,5>& m1159) {
                    u64 v_c15 = m1159[3]; u64 v_c234 = m1159[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex1086, std::array<u64,2>{v_c15, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1087, std::array<u64,2>{v_c234, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex1088, st_diffdelta1097, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m1160) {
                      u64 v_c235 = m1160[2];
                      slog::join_probe_old<2,2>(st_diff_ansindex1089, st_diff_ansdelta1098, std::array<u64,2>{v_c235, v_c15}, [&](const std::array<u64,2>& m1161) {
                        slog::join_probe<2,1>(st_bld_ansindex1090, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1162) {
                          u64 v_c27 = m1162[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c231, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask1099* _cont = new ReadTask1099(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1099(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan $sup9688x103x0x0x0 __t3N33245 l m n p q r u v) (body (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 1 l) (join-old $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t3N33245 n q u v __t3q0j248) (exists st_msk (1 2 0) 3 q m __t3q0j248) (exists st_msk_ans (0 1) 2 __t3q0j248 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2RvE244) (exists st_union (0 1 2) 2 __t3N33245 __t2RvE244) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_union (0 1 2) 3 (0 1 2) __t3N33245 __t2RvE244 __t8HsZ249) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask1185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1163;  slog::Index** pbranchindex1164;  slog::Index** st_mskindex1165;  slog::Index** st_msk_ansindex1166;  slog::Index** st_unionindex1167;  slog::Index** $sup9688x103x0x0x1index1168;  slog::Index** st_mskindex1169;  slog::Index** st_msk_ansindex1170;  slog::Index** pbranchindex1171;  slog::Index** st_unionindex1172;  slog::Index** pbranchindex1173;  slog::Index** st_unionindex1174;  slog::Index** st_mskindex1175;  slog::Index** st_msk_ansindex1176;  slog::Index** st_unionindex1177;  slog::Index** st_union_ansindex1178;  slog::Index** $sup9688x103x0x0x1delta1179;  slog::Index** pbranchdelta1180;  slog::Index** pbranchdelta1181;  slog::Index** st_uniondelta1182;  slog::Index** st_mskdelta1183;  slog::Index** st_uniondelta1184;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord1186({1, 2, 3, 4, 0});
      slog::Relation* readrel1187 = db->getRelation("pbranch");
      pbranchindex1163 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 2, 3, 4, 0});
      slog::Relation* readrel1189 = db->getRelation("pbranch");
      pbranchindex1164 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 2, 0});
      slog::Relation* readrel1191 = db->getRelation("st_msk");
      st_mskindex1165 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 0});
      slog::Relation* readrel1193 = db->getRelation("st_msk_ans");
      st_msk_ansindex1166 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({1, 2, 0});
      slog::Relation* readrel1195 = db->getRelation("st_union");
      st_unionindex1167 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1197 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index1168 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1199 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1delta1179 = readrel1199->getIndex(ord1198, true);
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("st_msk");
      st_mskindex1169 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({0, 1});
      slog::Relation* readrel1203 = db->getRelation("st_msk_ans");
      st_msk_ansindex1170 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 2, 3, 4, 0});
      slog::Relation* readrel1205 = db->getRelation("pbranch");
      pbranchindex1171 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 2, 3, 4, 0});
      slog::Relation* readrel1207 = db->getRelation("pbranch");
      pbranchdelta1180 = readrel1207->getIndex(ord1206, true);
      std::vector<u16> ord1208({0, 1, 2});
      slog::Relation* readrel1209 = db->getRelation("st_union");
      st_unionindex1172 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 3, 4, 0});
      slog::Relation* readrel1211 = db->getRelation("pbranch");
      pbranchindex1173 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 3, 4, 0});
      slog::Relation* readrel1213 = db->getRelation("pbranch");
      pbranchdelta1181 = readrel1213->getIndex(ord1212, true);
      std::vector<u16> ord1214({0, 1, 2});
      slog::Relation* readrel1215 = db->getRelation("st_union");
      st_unionindex1174 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1, 2});
      slog::Relation* readrel1217 = db->getRelation("st_union");
      st_uniondelta1182 = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({1, 2, 0});
      slog::Relation* readrel1219 = db->getRelation("st_msk");
      st_mskindex1175 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 2, 0});
      slog::Relation* readrel1221 = db->getRelation("st_msk");
      st_mskdelta1183 = readrel1221->getIndex(ord1220, true);
      std::vector<u16> ord1222({0, 1});
      slog::Relation* readrel1223 = db->getRelation("st_msk_ans");
      st_msk_ansindex1176 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 2, 0});
      slog::Relation* readrel1225 = db->getRelation("st_union");
      st_unionindex1177 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 2, 0});
      slog::Relation* readrel1227 = db->getRelation("st_union");
      st_uniondelta1184 = readrel1227->getIndex(ord1226, true);
      std::vector<u16> ord1228({0, 1});
      slog::Relation* readrel1229 = db->getRelation("st_union_ans");
      st_union_ansindex1178 = readrel1229->getIndex(ord1228, false);
  
    }
    ReadTask1185(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c194 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c23 = _t[5];
        u64 v_c12 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c13 = _t[8];
        u64 v_c236 = _prim_lt(db, v_c24, v_c10);
        if (v_c236 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
        if (!v_c236) return;
        if (!slog::exists_probe<5,4>(pbranchindex1163, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0})) return;
        if (!slog::exists_probe<5,4>(pbranchindex1164, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex1165, std::array<u64,3>{v_c23, v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1166, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex1167, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe_old<10,9>($sup9688x103x0x0x1index1168, $sup9688x103x0x0x1delta1179, std::array<u64,10>{v_c7, v_c10, v_c11, v_c12, v_c194, v_c24, v_c23, v_c8, v_c13, 0}, [&](const std::array<u64,10>& m1231) {
          u64 v_c199 = m1231[9];
          if (!slog::exists_probe<3,3>(st_mskindex1169, std::array<u64,3>{v_c23, v_c10, v_c199})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex1170, std::array<u64,2>{v_c199, v_c11})) return;
          slog::join_probe_old<5,4>(pbranchindex1171, pbranchdelta1180, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0}, [&](const std::array<u64,5>& m1232) {
            u64 v_c195 = m1232[4];
            if (!slog::exists_probe<3,2>(st_unionindex1172, std::array<u64,3>{v_c194, v_c195, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1173, pbranchdelta1181, std::array<u64,5>{v_c23, v_c24, v_c8, v_c13, 0}, [&](const std::array<u64,5>& m1233) {
              u64 v_c196 = m1233[4];
              slog::join_probe_old<3,3>(st_unionindex1174, st_uniondelta1182, std::array<u64,3>{v_c194, v_c195, v_c196}, [&](const std::array<u64,3>& m1234) {
                slog::join_probe_old<3,3>(st_mskindex1175, st_mskdelta1183, std::array<u64,3>{v_c23, v_c10, v_c199}, [&](const std::array<u64,3>& m1235) {
                  slog::join_probe<2,2>(st_msk_ansindex1176, std::array<u64,2>{v_c199, v_c11}, [&](const std::array<u64,2>& m1236) {
                    slog::join_probe_old<3,2>(st_unionindex1177, st_uniondelta1184, std::array<u64,3>{v_c7, v_c196, 0}, [&](const std::array<u64,3>& m1237) {
                      u64 v_c197 = m1237[2];
                      slog::join_probe<2,1>(st_union_ansindex1178, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m1238) {
                        u64 v_c6 = m1238[1];
                        u64 v_c200 = _prim_band(db, v_c23, v_c10);
                        if (v_c200 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c237 = _prim_lt(db, v_c200, v_c193);
                        if (v_c237 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c237) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c194, v_c6, v_c10, v_c11, v_c12});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c11, v_c10, v_c6, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:$sup9688x103x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1185* _cont = new ReadTask1185(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1185(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst7TTg43 __t8j8m45 __t7Lp349) (body (join _enum (0 1) 2 __t7Lp349 __tconst9YUA1125) (exists st_ins_ans (0 1) 1 __t8j8m45) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (exists st_ins_ans (0 1) 1 __t3nMl50) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join st_ins_ans (0 1) 1 __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join st_ins_ans (0 1) 1 __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join st_union_ans (0 1) 1 __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask1259 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex1240;  slog::Index** st_ins_ansindex1241;  slog::Index** st_insindex1242;  slog::Index** st_insindex1243;  slog::Index** st_insindex1244;  slog::Index** st_ins_ansindex1245;  slog::Index** st_ins_ansindex1246;  slog::Index** st_insindex1247;  slog::Index** st_ins_ansindex1248;  slog::Index** st_unionindex1249;  slog::Index** st_ins_ansindex1250;  slog::Index** st_insindex1251;  slog::Index** st_ins_ansindex1252;  slog::Index** st_unionindex1253;  slog::Index** st_union_ansindex1254;  slog::Index** st_insdelta1255;  slog::Index** st_insdelta1256;  slog::Index** st_insdelta1257;  slog::Index** st_uniondelta1258;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1260({0});
      slog::Relation* readrel1261 = db->getRelation("canon");
      head_index[0] = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({2, 0, 1});
      slog::Relation* readrel1263 = db->getRelation("st_ins");
      driver_index = readrel1263->getIndex(ord1262, true);
      std::vector<u16> ord1264({0, 1});
      slog::Relation* readrel1265 = db->getRelation("_enum");
      _enumindex1240 = readrel1265->getIndex(ord1264, false);
      std::vector<u16> ord1266({0, 1});
      slog::Relation* readrel1267 = db->getRelation("st_ins_ans");
      st_ins_ansindex1241 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({2, 0, 1});
      slog::Relation* readrel1269 = db->getRelation("st_ins");
      st_insindex1242 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({2, 0, 1});
      slog::Relation* readrel1271 = db->getRelation("st_ins");
      st_insindex1243 = readrel1271->getIndex(ord1270, false);
      std::vector<u16> ord1272({1, 2, 0});
      slog::Relation* readrel1273 = db->getRelation("st_ins");
      st_insindex1244 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({1, 2, 0});
      slog::Relation* readrel1275 = db->getRelation("st_ins");
      st_insdelta1255 = readrel1275->getIndex(ord1274, true);
      std::vector<u16> ord1276({0, 1});
      slog::Relation* readrel1277 = db->getRelation("st_ins_ans");
      st_ins_ansindex1245 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({0, 1});
      slog::Relation* readrel1279 = db->getRelation("st_ins_ans");
      st_ins_ansindex1246 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({1, 2, 0});
      slog::Relation* readrel1281 = db->getRelation("st_ins");
      st_insindex1247 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({1, 2, 0});
      slog::Relation* readrel1283 = db->getRelation("st_ins");
      st_insdelta1256 = readrel1283->getIndex(ord1282, true);
      std::vector<u16> ord1284({0, 1});
      slog::Relation* readrel1285 = db->getRelation("st_ins_ans");
      st_ins_ansindex1248 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({1, 2, 0});
      slog::Relation* readrel1287 = db->getRelation("st_union");
      st_unionindex1249 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({0, 1});
      slog::Relation* readrel1289 = db->getRelation("st_ins_ans");
      st_ins_ansindex1250 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 2, 0});
      slog::Relation* readrel1291 = db->getRelation("st_ins");
      st_insindex1251 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({1, 2, 0});
      slog::Relation* readrel1293 = db->getRelation("st_ins");
      st_insdelta1257 = readrel1293->getIndex(ord1292, true);
      std::vector<u16> ord1294({0, 1});
      slog::Relation* readrel1295 = db->getRelation("st_ins_ans");
      st_ins_ansindex1252 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({1, 2, 0});
      slog::Relation* readrel1297 = db->getRelation("st_union");
      st_unionindex1253 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 2, 0});
      slog::Relation* readrel1299 = db->getRelation("st_union");
      st_uniondelta1258 = readrel1299->getIndex(ord1298, true);
      std::vector<u16> ord1300({0, 1});
      slog::Relation* readrel1301 = db->getRelation("st_union_ans");
      st_union_ansindex1254 = readrel1301->getIndex(ord1300, false);
  
    }
    ReadTask1259(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c84 = v_constef2d127de37b942baad06145;
      u64 v_c85 = v_const2c624232cdd221771294dfbb;
      u64 v_c86 = v_constd4735e3a265e16eee03f5971;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c84, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1302) {
        u64 v_c91 = m1302[1];
        u64 v_c90 = m1302[2];
        if (buckethash(v_c91) != bucket) return;
        slog::join_probe<2,2>(_enumindex1240, std::array<u64,2>{v_c90, v_c83}, [&](const std::array<u64,2>& m1303) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex1241, std::array<u64,2>{v_c91, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1242, std::array<u64,3>{v_c85, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1243, std::array<u64,3>{v_c87, 0, 0})) return;
          slog::join_probe_old<3,2>(st_insindex1244, st_insdelta1255, std::array<u64,3>{v_c90, v_c86, 0}, [&](const std::array<u64,3>& m1304) {
            u64 v_c92 = m1304[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex1245, std::array<u64,2>{v_c92, 0})) return;
            slog::join_probe<2,1>(st_ins_ansindex1246, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m1305) {
              u64 v_c6 = m1305[1];
              slog::join_probe_old<3,2>(st_insindex1247, st_insdelta1256, std::array<u64,3>{v_c6, v_c85, 0}, [&](const std::array<u64,3>& m1306) {
                u64 v_c88 = m1306[2];
                slog::join_probe<2,1>(st_ins_ansindex1248, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m1307) {
                  u64 v_c89 = m1307[1];
                  if (!slog::exists_probe<3,1>(st_unionindex1249, std::array<u64,3>{v_c89, 0, 0})) return;
                  slog::join_probe<2,1>(st_ins_ansindex1250, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m1308) {
                    u64 v_c15 = m1308[1];
                    slog::join_probe_old<3,2>(st_insindex1251, st_insdelta1257, std::array<u64,3>{v_c15, v_c87, 0}, [&](const std::array<u64,3>& m1309) {
                      u64 v_c93 = m1309[2];
                      slog::join_probe<2,1>(st_ins_ansindex1252, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1310) {
                        u64 v_c94 = m1310[1];
                        slog::join_probe_old<3,2>(st_unionindex1253, st_uniondelta1258, std::array<u64,3>{v_c89, v_c94, 0}, [&](const std::array<u64,3>& m1311) {
                          u64 v_c95 = m1311[2];
                          slog::join_probe<2,1>(st_union_ansindex1254, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m1312) {
                            u64 v_c12 = m1312[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1259* _cont = new ReadTask1259(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1259(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_bld_ans __t6UON282 res) (body (join-old st_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t6UON282 p m __v0 r) (exists $sup9688x88x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del_ans (1 0) 1 __v0) (join-old pbranch (1 2 4 0 3) 3 (1 2 4 0 3) p m r __t2u9k278 l) (exists st_del (1 2 0) 1 __t2u9k278) (exists st_del (1 2 0) 1 l) (join-old $sup9688x88x0x0x0 (4 3 5 2 0 1) 4 (4 3 5 2 0 1) p m r l __t3OU0279 k) (join-old st_del (0 2 1) 3 (0 2 1) __t3OU0279 k __t2u9k278) (exists st_del (1 2 0) 2 l k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join-old st_msk_ans (0 1) 2 (0 1) __t5pdy283 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join-old st_del_ans (0 1) 2 (0 1) __t62j9284 __v0) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask1336 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex1313;  slog::Index** $sup9688x88x0x0x0index1314;  slog::Index** st_mskindex1315;  slog::Index** st_msk_ansindex1316;  slog::Index** st_del_ansindex1317;  slog::Index** pbranchindex1318;  slog::Index** st_delindex1319;  slog::Index** st_delindex1320;  slog::Index** $sup9688x88x0x0x0index1321;  slog::Index** st_delindex1322;  slog::Index** st_delindex1323;  slog::Index** st_mskindex1324;  slog::Index** st_msk_ansindex1325;  slog::Index** st_delindex1326;  slog::Index** st_del_ansindex1327;  slog::Index** st_blddelta1328;  slog::Index** pbranchdelta1329;  slog::Index** $sup9688x88x0x0x0delta1330;  slog::Index** st_deldelta1331;  slog::Index** st_mskdelta1332;  slog::Index** st_msk_ansdelta1333;  slog::Index** st_deldelta1334;  slog::Index** st_del_ansdelta1335;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1337({0, 1});
      slog::Relation* readrel1338 = db->getRelation("st_del_ans");
      head_index[0] = readrel1338->getIndex(ord1337, false);
      outer_rel = db->getRelation("st_bld_ans");
      std::vector<u16> ord1339({0, 1, 2, 3, 4});
      slog::Relation* readrel1340 = db->getRelation("st_bld");
      st_bldindex1313 = readrel1340->getIndex(ord1339, false);
      std::vector<u16> ord1341({0, 1, 2, 3, 4});
      slog::Relation* readrel1342 = db->getRelation("st_bld");
      st_blddelta1328 = readrel1342->getIndex(ord1341, true);
      std::vector<u16> ord1343({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1344 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1314 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({2, 0, 1});
      slog::Relation* readrel1346 = db->getRelation("st_msk");
      st_mskindex1315 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({1, 0});
      slog::Relation* readrel1348 = db->getRelation("st_msk_ans");
      st_msk_ansindex1316 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 0});
      slog::Relation* readrel1350 = db->getRelation("st_del_ans");
      st_del_ansindex1317 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 2, 4, 0, 3});
      slog::Relation* readrel1352 = db->getRelation("pbranch");
      pbranchindex1318 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({1, 2, 4, 0, 3});
      slog::Relation* readrel1354 = db->getRelation("pbranch");
      pbranchdelta1329 = readrel1354->getIndex(ord1353, true);
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("st_del");
      st_delindex1319 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 2, 0});
      slog::Relation* readrel1358 = db->getRelation("st_del");
      st_delindex1320 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1360 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1321 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1362 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0delta1330 = readrel1362->getIndex(ord1361, true);
      std::vector<u16> ord1363({0, 2, 1});
      slog::Relation* readrel1364 = db->getRelation("st_del");
      st_delindex1322 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({0, 2, 1});
      slog::Relation* readrel1366 = db->getRelation("st_del");
      st_deldelta1331 = readrel1366->getIndex(ord1365, true);
      std::vector<u16> ord1367({1, 2, 0});
      slog::Relation* readrel1368 = db->getRelation("st_del");
      st_delindex1323 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 2, 0});
      slog::Relation* readrel1370 = db->getRelation("st_msk");
      st_mskindex1324 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({1, 2, 0});
      slog::Relation* readrel1372 = db->getRelation("st_msk");
      st_mskdelta1332 = readrel1372->getIndex(ord1371, true);
      std::vector<u16> ord1373({0, 1});
      slog::Relation* readrel1374 = db->getRelation("st_msk_ans");
      st_msk_ansindex1325 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({0, 1});
      slog::Relation* readrel1376 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1333 = readrel1376->getIndex(ord1375, true);
      std::vector<u16> ord1377({1, 2, 0});
      slog::Relation* readrel1378 = db->getRelation("st_del");
      st_delindex1326 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 2, 0});
      slog::Relation* readrel1380 = db->getRelation("st_del");
      st_deldelta1334 = readrel1380->getIndex(ord1379, true);
      std::vector<u16> ord1381({0, 1});
      slog::Relation* readrel1382 = db->getRelation("st_del_ans");
      st_del_ansindex1327 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({0, 1});
      slog::Relation* readrel1384 = db->getRelation("st_del_ans");
      st_del_ansdelta1335 = readrel1384->getIndex(ord1383, true);
  
    }
    ReadTask1336(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c238 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c239 = _t[0];
        u64 v_c27 = _t[1];
        slog::join_probe_old<5,1>(st_bldindex1313, st_blddelta1328, std::array<u64,5>{v_c239, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1385) {
          u64 v_c11 = m1385[1]; u64 v_c10 = m1385[2]; u64 v_c6 = m1385[3]; u64 v_c12 = m1385[4];
          if (!slog::exists_probe<6,3>($sup9688x88x0x0x0index1314, std::array<u64,6>{v_c11, v_c10, v_c12, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1315, std::array<u64,3>{v_c10, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex1316, std::array<u64,2>{v_c11, 0})) return;
          if (!slog::exists_probe<2,1>(st_del_ansindex1317, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe_old<5,3>(pbranchindex1318, pbranchdelta1329, std::array<u64,5>{v_c11, v_c10, v_c12, 0, 0}, [&](const std::array<u64,5>& m1386) {
            u64 v_c240 = m1386[3]; u64 v_c7 = m1386[4];
            if (!slog::exists_probe<3,1>(st_delindex1319, std::array<u64,3>{v_c240, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_delindex1320, std::array<u64,3>{v_c7, 0, 0})) return;
            slog::join_probe_old<6,4>($sup9688x88x0x0x0index1321, $sup9688x88x0x0x0delta1330, std::array<u64,6>{v_c11, v_c10, v_c12, v_c7, 0, 0}, [&](const std::array<u64,6>& m1387) {
              u64 v_c241 = m1387[4]; u64 v_c17 = m1387[5];
              slog::join_probe_old<3,3>(st_delindex1322, st_deldelta1331, std::array<u64,3>{v_c241, v_c17, v_c240}, [&](const std::array<u64,3>& m1388) {
                if (!slog::exists_probe<3,2>(st_delindex1323, std::array<u64,3>{v_c7, v_c17, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex1324, st_mskdelta1332, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m1389) {
                  u64 v_c242 = m1389[2];
                  slog::join_probe_old<2,2>(st_msk_ansindex1325, st_msk_ansdelta1333, std::array<u64,2>{v_c242, v_c11}, [&](const std::array<u64,2>& m1390) {
                    slog::join_probe_old<3,2>(st_delindex1326, st_deldelta1334, std::array<u64,3>{v_c7, v_c17, 0}, [&](const std::array<u64,3>& m1391) {
                      u64 v_c243 = m1391[2];
                      slog::join_probe_old<2,2>(st_del_ansindex1327, st_del_ansdelta1335, std::array<u64,2>{v_c243, v_c6}, [&](const std::array<u64,2>& m1392) {
                        u64 v_c244 = _prim_band(db, v_c17, v_c10);
                        if (v_c244 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c245 = _prim_lt(db, v_c244, v_c238);
                        if (v_c245 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c245) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c241, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask1336* _cont = new ReadTask1336(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1336(db,b), false);
  // (crule (pre (let __tconst9VVd93 const6b86b273ff34fce19d6b804e) (let __tconst8Blx94 constd4735e3a265e16eee03f5971)) (scan st_hsb __t8W3F96 __t1MAp95) (body (join st_hsb_ans (0 1) 1 __t8W3F96 __v0) (join st_hsb (0 1) 0 __t4kHg92 x) (cmp lt __tconst9VVd93 x) (let chk4fO01272 (_0002f x __tconst8Blx94)) (eq __t1MAp95 chk4fO01272) (let __t5SLx91 (_0002a __tconst8Blx94 __v0))) (head (emit-temp temp1gVy1270 __t4kHg92 __t5SLx91)) set.slog:29 #f)
  class ReadTask1396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1394;  slog::Index** st_hsbindex1395;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1gVy1270");
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord1397({0, 1});
      slog::Relation* readrel1398 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1394 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({0, 1});
      slog::Relation* readrel1400 = db->getRelation("st_hsb");
      st_hsbindex1395 = readrel1400->getIndex(ord1399, false);
  
    }
    ReadTask1396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c247 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c248 = _t[0];
        u64 v_c249 = _t[1];
        slog::join_probe<2,1>(st_hsb_ansindex1394, std::array<u64,2>{v_c248, 0}, [&](const std::array<u64,2>& m1401) {
          u64 v_c6 = m1401[1];
          slog::join_all<2>(st_hsbindex1395, [&](const std::array<u64,2>& m1402) {
            u64 v_c250 = m1402[0]; u64 v_c251 = m1402[1];
            u64 v_c252 = _prim_lt(db, v_c246, v_c251);
            if (v_c252 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            if (!v_c252) return;
            u64 v_c253 = _prim__0002f(db, v_c251, v_c247);
            if (v_c253 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            if (v_c249 != v_c253) return;
            u64 v_c254 = _prim__0002a(db, v_c247, v_c6);
            if (v_c254 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c250, v_c254});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1396* _cont = new ReadTask1396(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1396(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t57zq262 p) (body (exists $sup9688x52x0x0x1 (1 5 0 2 3 4 6) 2 __t57zq262 p) (exists $sup9688x52x0x0x0 (4 2 3 5 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t57zq262 k m) (exists $sup9688x52x0x0x0 (1 3 4 0 2 5) 3 k m p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_ins (2 0 1) 1 k) (join-old $sup9688x52x0x0x1 (1 2 4 5 0 3 6) 4 (1 2 4 5 0 3 6) __t57zq262 k m p __t7CbB259 l r) (join-old $sup9688x52x0x0x0 (4 2 3 5 0 1) 6 (4 2 3 5 0 1) p l m r __t7CbB259 k) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_ins (1 2 0) 2 r k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0vi9258) (join-old st_ins (0 2 1) 3 (0 2 1) __t7CbB259 k __t0vi9258) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join-old st_ins_ans (0 1) 1 (0 1) __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask1426 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x1index1404;  slog::Index** $sup9688x52x0x0x0index1405;  slog::Index** pbranchindex1406;  slog::Index** st_mskindex1407;  slog::Index** $sup9688x52x0x0x0index1408;  slog::Index** pbranchindex1409;  slog::Index** st_insindex1410;  slog::Index** $sup9688x52x0x0x1index1411;  slog::Index** $sup9688x52x0x0x0index1412;  slog::Index** st_insindex1413;  slog::Index** st_insindex1414;  slog::Index** pbranchindex1415;  slog::Index** st_insindex1416;  slog::Index** st_insindex1417;  slog::Index** st_ins_ansindex1418;  slog::Index** st_mskdelta1419;  slog::Index** $sup9688x52x0x0x1delta1420;  slog::Index** $sup9688x52x0x0x0delta1421;  slog::Index** pbranchdelta1422;  slog::Index** st_insdelta1423;  slog::Index** st_insdelta1424;  slog::Index** st_ins_ansdelta1425;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1427({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1428 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index1404 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1430 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index1405 = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({1, 2, 3, 4, 0});
      slog::Relation* readrel1432 = db->getRelation("pbranch");
      pbranchindex1406 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({0, 1, 2});
      slog::Relation* readrel1434 = db->getRelation("st_msk");
      st_mskindex1407 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({0, 1, 2});
      slog::Relation* readrel1436 = db->getRelation("st_msk");
      st_mskdelta1419 = readrel1436->getIndex(ord1435, true);
      std::vector<u16> ord1437({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1438 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index1408 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({1, 2, 3, 4, 0});
      slog::Relation* readrel1440 = db->getRelation("pbranch");
      pbranchindex1409 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({2, 0, 1});
      slog::Relation* readrel1442 = db->getRelation("st_ins");
      st_insindex1410 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel1444 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index1411 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel1446 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1delta1420 = readrel1446->getIndex(ord1445, true);
      std::vector<u16> ord1447({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1448 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index1412 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1450 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0delta1421 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({0, 2, 1});
      slog::Relation* readrel1452 = db->getRelation("st_ins");
      st_insindex1413 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({1, 2, 0});
      slog::Relation* readrel1454 = db->getRelation("st_ins");
      st_insindex1414 = readrel1454->getIndex(ord1453, false);
      std::vector<u16> ord1455({1, 2, 3, 4, 0});
      slog::Relation* readrel1456 = db->getRelation("pbranch");
      pbranchindex1415 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 2, 3, 4, 0});
      slog::Relation* readrel1458 = db->getRelation("pbranch");
      pbranchdelta1422 = readrel1458->getIndex(ord1457, true);
      std::vector<u16> ord1459({0, 2, 1});
      slog::Relation* readrel1460 = db->getRelation("st_ins");
      st_insindex1416 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({0, 2, 1});
      slog::Relation* readrel1462 = db->getRelation("st_ins");
      st_insdelta1423 = readrel1462->getIndex(ord1461, true);
      std::vector<u16> ord1463({1, 2, 0});
      slog::Relation* readrel1464 = db->getRelation("st_ins");
      st_insindex1417 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 2, 0});
      slog::Relation* readrel1466 = db->getRelation("st_ins");
      st_insdelta1424 = readrel1466->getIndex(ord1465, true);
      std::vector<u16> ord1467({0, 1});
      slog::Relation* readrel1468 = db->getRelation("st_ins_ans");
      st_ins_ansindex1418 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({0, 1});
      slog::Relation* readrel1470 = db->getRelation("st_ins_ans");
      st_ins_ansdelta1425 = readrel1470->getIndex(ord1469, true);
  
    }
    ReadTask1426(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c255 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c256 = _t[0];
        u64 v_c11 = _t[1];
        if (!slog::exists_probe<7,2>($sup9688x52x0x0x1index1404, std::array<u64,7>{v_c256, v_c11, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<6,1>($sup9688x52x0x0x0index1405, std::array<u64,6>{v_c11, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1406, std::array<u64,5>{v_c11, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1407, st_mskdelta1419, std::array<u64,3>{v_c256, 0, 0}, [&](const std::array<u64,3>& m1471) {
          u64 v_c17 = m1471[1]; u64 v_c10 = m1471[2];
          if (!slog::exists_probe<6,3>($sup9688x52x0x0x0index1408, std::array<u64,6>{v_c17, v_c10, v_c11, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1409, std::array<u64,5>{v_c11, v_c10, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1410, std::array<u64,3>{v_c17, 0, 0})) return;
          slog::join_probe_old<7,4>($sup9688x52x0x0x1index1411, $sup9688x52x0x0x1delta1420, std::array<u64,7>{v_c256, v_c17, v_c10, v_c11, 0, 0, 0}, [&](const std::array<u64,7>& m1472) {
            u64 v_c257 = m1472[4]; u64 v_c7 = m1472[5]; u64 v_c12 = m1472[6];
            slog::join_probe_old<6,6>($sup9688x52x0x0x0index1412, $sup9688x52x0x0x0delta1421, std::array<u64,6>{v_c11, v_c7, v_c10, v_c12, v_c257, v_c17}, [&](const std::array<u64,6>& m1473) {
              if (!slog::exists_probe<3,2>(st_insindex1413, std::array<u64,3>{v_c257, v_c17, 0})) return;
              if (!slog::exists_probe<3,2>(st_insindex1414, std::array<u64,3>{v_c12, v_c17, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1415, pbranchdelta1422, std::array<u64,5>{v_c11, v_c10, v_c7, v_c12, 0}, [&](const std::array<u64,5>& m1474) {
                u64 v_c258 = m1474[4];
                slog::join_probe_old<3,3>(st_insindex1416, st_insdelta1423, std::array<u64,3>{v_c257, v_c17, v_c258}, [&](const std::array<u64,3>& m1475) {
                  slog::join_probe_old<3,2>(st_insindex1417, st_insdelta1424, std::array<u64,3>{v_c12, v_c17, 0}, [&](const std::array<u64,3>& m1476) {
                    u64 v_c259 = m1476[2];
                    slog::join_probe_old<2,1>(st_ins_ansindex1418, st_ins_ansdelta1425, std::array<u64,2>{v_c259, 0}, [&](const std::array<u64,2>& m1477) {
                      u64 v_c6 = m1477[1];
                      u64 v_c260 = _prim_band(db, v_c17, v_c10);
                      if (v_c260 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c261 = _prim_gt(db, v_c260, v_c255);
                      if (v_c261 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c261) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c257, v_c6, v_c7, v_c10, v_c11});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c11, v_c10, v_c7, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1426* _cont = new ReadTask1426(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1426(db,b), false);
  // (crule (pre) (scan st_union __t419y99 __t2p3i100 __t9Qes101) (body (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t2p3i100 p m l r) (join-old pbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t9Qes101 q u v) (neq p q)) (head (mkstruct st_join (1 2 3 4 0) __7vjT940 p __t2p3i100 q __t9Qes101)) set.slog:125 #f)
  class ReadTask1483 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1479;  slog::Index** pbranchindex1480;  slog::Index** pbranchdelta1481;  slog::Index** pbranchdelta1482;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord1484({0, 1, 2, 3, 4});
      slog::Relation* readrel1485 = db->getRelation("pbranch");
      pbranchindex1479 = readrel1485->getIndex(ord1484, false);
      std::vector<u16> ord1486({0, 1, 2, 3, 4});
      slog::Relation* readrel1487 = db->getRelation("pbranch");
      pbranchdelta1481 = readrel1487->getIndex(ord1486, true);
      std::vector<u16> ord1488({2, 0, 1, 3, 4});
      slog::Relation* readrel1489 = db->getRelation("pbranch");
      pbranchindex1480 = readrel1489->getIndex(ord1488, false);
      std::vector<u16> ord1490({2, 0, 1, 3, 4});
      slog::Relation* readrel1491 = db->getRelation("pbranch");
      pbranchdelta1482 = readrel1491->getIndex(ord1490, true);
  
    }
    ReadTask1483(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c262 = _t[0];
        u64 v_c263 = _t[1];
        u64 v_c264 = _t[2];
        slog::join_probe_old<5,1>(pbranchindex1479, pbranchdelta1481, std::array<u64,5>{v_c263, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1492) {
          u64 v_c11 = m1492[1]; u64 v_c10 = m1492[2]; u64 v_c7 = m1492[3]; u64 v_c12 = m1492[4];
          slog::join_probe_old<5,2>(pbranchindex1480, pbranchdelta1482, std::array<u64,5>{v_c10, v_c264, 0, 0, 0}, [&](const std::array<u64,5>& m1493) {
            u64 v_c23 = m1493[2]; u64 v_c8 = m1493[3]; u64 v_c13 = m1493[4];
            if (v_c11 == v_c23) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c11, v_c263, v_c23, v_c264}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask1483* _cont = new ReadTask1483(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1483(db,b), false);
}

