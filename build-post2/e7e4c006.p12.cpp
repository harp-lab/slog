
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1d9eff40314d54862fee3942;
extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5e6127cdd5ea2629462053c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const78643ffd185a1863a6e6997e;
extern u64 v_const7ce11965015db325c92ba444;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c41f2ec6a574d4d3d(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_hsb_ans __t75bg356 __v1) (body (exists st_hsb_ans (0 1) 1 __t75bg356) (exists $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t75bg356 __v1) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 1 __t75bg356) (exists st_msk (2 0 1) 1 __v1) (join st_hsb_ans (0 1) 1 __t75bg356 __v3) (exists $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t75bg356 __v1 __v3) (join-old st_hsb_ans (0 1) 1 (0 1) __t75bg356 __v0) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 2 __t75bg356 __v0) (join $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t75bg356 __v0 __v3 __v1 __t0kmv352 dup66Lo1333 dup68E21334 p0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join st_msk_ans (0 1) 1 __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask19 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex0;  slog::Index** $sup9688x36x0x0x2index1;  slog::Index** $sup9688x36x0x0x1index2;  slog::Index** st_mskindex3;  slog::Index** st_hsb_ansindex4;  slog::Index** $sup9688x36x0x0x2index5;  slog::Index** st_hsb_ansindex6;  slog::Index** $sup9688x36x0x0x1index7;  slog::Index** $sup9688x36x0x0x2index8;  slog::Index** $sup9688x36x0x0x1index9;  slog::Index** $sup9688x36x0x0x0index10;  slog::Index** st_joinindex11;  slog::Index** st_mskindex12;  slog::Index** st_msk_ansindex13;  slog::Index** st_hsbindex14;  slog::Index** st_hsb_ansdelta15;  slog::Index** st_joindelta16;  slog::Index** st_mskdelta17;  slog::Index** st_hsbdelta18;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex0 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel23 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel25 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index2 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({2, 0, 1});
      slog::Relation* readrel27 = db->getRelation("st_msk");
      st_mskindex3 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex4 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel31 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index5 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex6 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta15 = readrel35->getIndex(ord34, true);
      std::vector<u16> ord36({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel37 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index7 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel39 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index8 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel41 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index9 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0, 2, 3, 4});
      slog::Relation* readrel43 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index10 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 3, 4, 0});
      slog::Relation* readrel45 = db->getRelation("st_join");
      st_joinindex11 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 3, 4, 0});
      slog::Relation* readrel47 = db->getRelation("st_join");
      st_joindelta16 = readrel47->getIndex(ord46, true);
      std::vector<u16> ord48({1, 2, 0});
      slog::Relation* readrel49 = db->getRelation("st_msk");
      st_mskindex12 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 2, 0});
      slog::Relation* readrel51 = db->getRelation("st_msk");
      st_mskdelta17 = readrel51->getIndex(ord50, true);
      std::vector<u16> ord52({0, 1});
      slog::Relation* readrel53 = db->getRelation("st_msk_ans");
      st_msk_ansindex13 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("st_hsb");
      st_hsbindex14 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("st_hsb");
      st_hsbdelta18 = readrel57->getIndex(ord56, true);
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index1, std::array<u64,11>{v_c1, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x36x0x0x1index2, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex3, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex4, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m58) {
          u64 v_c3 = m58[1];
          if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index5, std::array<u64,11>{v_c1, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex6, st_hsb_ansdelta15, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m59) {
            u64 v_c4 = m59[1];
            if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index7, std::array<u64,7>{v_c1, v_c4, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x36x0x0x2index8, std::array<u64,11>{v_c1, v_c4, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m60) {
              u64 v_c5 = m60[4]; u64 v_c6 = m60[5]; u64 v_c7 = m60[6]; u64 v_c8 = m60[7]; u64 v_c9 = m60[8]; u64 v_c10 = m60[9]; u64 v_c11 = m60[10];
              if (v_c1 != v_c7) return;
              if (v_c1 != v_c6) return;
              slog::join_probe<7,7>($sup9688x36x0x0x1index9, std::array<u64,7>{v_c5, v_c8, v_c9, v_c10, v_c11, v_c1, v_c4}, [&](const std::array<u64,7>& m61) {
                slog::join_probe<5,5>($sup9688x36x0x0x0index10, std::array<u64,5>{v_c8, v_c5, v_c9, v_c10, v_c11}, [&](const std::array<u64,5>& m62) {
                  slog::join_probe_old<5,5>(st_joinindex11, st_joindelta16, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c5}, [&](const std::array<u64,5>& m63) {
                    slog::join_probe_old<3,2>(st_mskindex12, st_mskdelta17, std::array<u64,3>{v_c8, v_c2, 0}, [&](const std::array<u64,3>& m64) {
                      u64 v_c12 = m64[2];
                      slog::join_probe<2,1>(st_msk_ansindex13, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m65) {
                        u64 v_c13 = m65[1];
                        u64 v_c14 = _prim_bxor(db, v_c8, v_c9);
                        if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex14, st_hsbdelta18, std::array<u64,2>{v_c1, v_c14}, [&](const std::array<u64,2>& m66) {
                          u64 v_c15 = _prim_band(db, v_c8, v_c4);
                          if (v_c15 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c16 = _prim_lt(db, v_c15, v_c0);
                          if (v_c16 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c16) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c13, v_c3, v_c10, v_c11});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c3, v_c10, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask19* _cont = new ReadTask19(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask19(db,b), false);
  // (crule (pre (let __tconst7zIc377 const5feceb66ffc86f38d952786c)) (scan st_del __t0BrC376 __t3NTP375 k) (body (join pbranch (0 1 2 3 4) 1 __t3NTP375 p m l r) (let __t8Ehr378 (band k m)) (cmp gt __t8Ehr378 __tconst7zIc377)) (head (emit $sup9688x90x0x0x0 (4 2 3 5 0 1) p l m r __t0BrC376 k)) set.slog:91 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord70({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel71 = db->getRelation("$sup9688x90x0x0x0");
      head_index[0] = readrel71->getIndex(ord70, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord72({0, 1, 2, 3, 4});
      slog::Relation* readrel73 = db->getRelation("pbranch");
      pbranchindex68 = readrel73->getIndex(ord72, false);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe<5,1>(pbranchindex68, std::array<u64,5>{v_c19, 0, 0, 0, 0}, [&](const std::array<u64,5>& m74) {
          u64 v_c21 = m74[1]; u64 v_c22 = m74[2]; u64 v_c23 = m74[3]; u64 v_c24 = m74[4];
          u64 v_c25 = _prim_band(db, v_c20, v_c22);
          if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
          u64 v_c26 = _prim_gt(db, v_c25, v_c17);
          if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
          if (!v_c26) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c21, v_c23, v_c22, v_c24, v_c18, v_c20}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  // (crule (pre) (scan st_msk_ans __t43e0330 p) (body (exists $sup9688x52x0x0x0 (4 2 3 5 0 1) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t43e0330 k m) (join $sup9688x52x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r)) (head (emit $sup9688x52x0x0x1 (0 2 1 3 4 5 6) __d0 k __t43e0330 l m p r)) set.slog:53 #f)
  class ReadTask80 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x0index76;  slog::Index** st_mskindex77;  slog::Index** $sup9688x52x0x0x0index78;  slog::Index** st_mskdelta79;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord81({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel82 = db->getRelation("$sup9688x52x0x0x1");
      head_index[0] = readrel82->getIndex(ord81, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord83({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel84 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index76 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2});
      slog::Relation* readrel86 = db->getRelation("st_msk");
      st_mskindex77 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1, 2});
      slog::Relation* readrel88 = db->getRelation("st_msk");
      st_mskdelta79 = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel90 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index78 = readrel90->getIndex(ord89, false);
  
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
        u64 v_c27 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x52x0x0x0index76, std::array<u64,6>{v_c21, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex77, st_mskdelta79, std::array<u64,3>{v_c27, 0, 0}, [&](const std::array<u64,3>& m91) {
          u64 v_c20 = m91[1]; u64 v_c22 = m91[2];
          slog::join_probe<6,3>($sup9688x52x0x0x0index78, std::array<u64,6>{v_c20, v_c22, v_c21, 0, 0, 0}, [&](const std::array<u64,6>& m92) {
            u64 v_c28 = m92[3]; u64 v_c23 = m92[4]; u64 v_c24 = m92[5];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c28, v_c20, v_c27, v_c23, v_c22, v_c21, v_c24}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_bld_ans __t1RXD162 res) (body (join-old st_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t1RXD162 p m __v0 r) (exists $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 3 p m r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff_ans (1 0) 1 __v0) (join-old pbranch (1 2 4 0 3) 3 (1 2 4 0 3) p m r __t66RN158 l) (exists st_diff (1 2 0) 1 __t66RN158) (exists st_diff (1 2 0) 1 l) (join-old $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 4 (4 2 6 1 0 3 5 7 8) p m r l __t3X8M159 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join-old st_diff (0 1 2) 3 (0 1 2) __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join-old st_msk_ans (0 1) 2 (0 1) __t8DQ7163 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join-old st_diff_ans (0 1) 2 (0 1) __t0YPK165 __v0) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask120 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex93;  slog::Index** $sup9688x139x0x0x0index94;  slog::Index** st_mskindex95;  slog::Index** st_msk_ansindex96;  slog::Index** st_diff_ansindex97;  slog::Index** pbranchindex98;  slog::Index** st_diffindex99;  slog::Index** st_diffindex100;  slog::Index** $sup9688x139x0x0x0index101;  slog::Index** st_diffindex102;  slog::Index** st_mskindex103;  slog::Index** pbranchindex104;  slog::Index** st_diffindex105;  slog::Index** st_diffindex106;  slog::Index** st_mskindex107;  slog::Index** st_msk_ansindex108;  slog::Index** st_diffindex109;  slog::Index** st_diff_ansindex110;  slog::Index** st_blddelta111;  slog::Index** pbranchdelta112;  slog::Index** $sup9688x139x0x0x0delta113;  slog::Index** pbranchdelta114;  slog::Index** st_diffdelta115;  slog::Index** st_mskdelta116;  slog::Index** st_msk_ansdelta117;  slog::Index** st_diffdelta118;  slog::Index** st_diff_ansdelta119;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord121({0, 1});
      slog::Relation* readrel122 = db->getRelation("st_diff_ans");
      head_index[0] = readrel122->getIndex(ord121, false);
      outer_rel = db->getRelation("st_bld_ans");
      std::vector<u16> ord123({0, 1, 2, 3, 4});
      slog::Relation* readrel124 = db->getRelation("st_bld");
      st_bldindex93 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1, 2, 3, 4});
      slog::Relation* readrel126 = db->getRelation("st_bld");
      st_blddelta111 = readrel126->getIndex(ord125, true);
      std::vector<u16> ord127({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel128 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index94 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({2, 0, 1});
      slog::Relation* readrel130 = db->getRelation("st_msk");
      st_mskindex95 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 0});
      slog::Relation* readrel132 = db->getRelation("st_msk_ans");
      st_msk_ansindex96 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("st_diff_ans");
      st_diff_ansindex97 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 4, 0, 3});
      slog::Relation* readrel136 = db->getRelation("pbranch");
      pbranchindex98 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 4, 0, 3});
      slog::Relation* readrel138 = db->getRelation("pbranch");
      pbranchdelta112 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("st_diff");
      st_diffindex99 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("st_diff");
      st_diffindex100 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel144 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index101 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel146 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0delta113 = readrel146->getIndex(ord145, true);
      std::vector<u16> ord147({0, 1, 2});
      slog::Relation* readrel148 = db->getRelation("st_diff");
      st_diffindex102 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 2, 0});
      slog::Relation* readrel150 = db->getRelation("st_msk");
      st_mskindex103 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 3, 4, 0});
      slog::Relation* readrel152 = db->getRelation("pbranch");
      pbranchindex104 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 3, 4, 0});
      slog::Relation* readrel154 = db->getRelation("pbranch");
      pbranchdelta114 = readrel154->getIndex(ord153, true);
      std::vector<u16> ord155({0, 1, 2});
      slog::Relation* readrel156 = db->getRelation("st_diff");
      st_diffindex105 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1, 2});
      slog::Relation* readrel158 = db->getRelation("st_diff");
      st_diffdelta115 = readrel158->getIndex(ord157, true);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("st_diff");
      st_diffindex106 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("st_msk");
      st_mskindex107 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("st_msk");
      st_mskdelta116 = readrel164->getIndex(ord163, true);
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("st_msk_ans");
      st_msk_ansindex108 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("st_msk_ans");
      st_msk_ansdelta117 = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("st_diff");
      st_diffindex109 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("st_diff");
      st_diffdelta118 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("st_diff_ans");
      st_diff_ansindex110 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("st_diff_ans");
      st_diff_ansdelta119 = readrel176->getIndex(ord175, true);
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        slog::join_probe_old<5,1>(st_bldindex93, st_blddelta111, std::array<u64,5>{v_c30, 0, 0, 0, 0}, [&](const std::array<u64,5>& m177) {
          u64 v_c21 = m177[1]; u64 v_c22 = m177[2]; u64 v_c4 = m177[3]; u64 v_c24 = m177[4];
          if (!slog::exists_probe<9,3>($sup9688x139x0x0x0index94, std::array<u64,9>{v_c21, v_c22, v_c24, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex95, std::array<u64,3>{v_c22, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex96, std::array<u64,2>{v_c21, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex97, std::array<u64,2>{v_c4, 0})) return;
          slog::join_probe_old<5,3>(pbranchindex98, pbranchdelta112, std::array<u64,5>{v_c21, v_c22, v_c24, 0, 0}, [&](const std::array<u64,5>& m178) {
            u64 v_c32 = m178[3]; u64 v_c23 = m178[4];
            if (!slog::exists_probe<3,1>(st_diffindex99, std::array<u64,3>{v_c32, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex100, std::array<u64,3>{v_c23, 0, 0})) return;
            slog::join_probe_old<9,4>($sup9688x139x0x0x0index101, $sup9688x139x0x0x0delta113, std::array<u64,9>{v_c21, v_c22, v_c24, v_c23, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m179) {
              u64 v_c33 = m179[4]; u64 v_c34 = m179[5]; u64 v_c35 = m179[6]; u64 v_c36 = m179[7]; u64 v_c37 = m179[8];
              u64 v_c38 = _prim_lt(db, v_c34, v_c22);
              if (v_c38 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
              if (!v_c38) return;
              if (!slog::exists_probe<3,2>(st_diffindex102, std::array<u64,3>{v_c33, v_c32, 0})) return;
              if (!slog::exists_probe<3,2>(st_mskindex103, std::array<u64,3>{v_c35, v_c22, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex104, pbranchdelta114, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m181) {
                u64 v_c39 = m181[4];
                slog::join_probe_old<3,3>(st_diffindex105, st_diffdelta115, std::array<u64,3>{v_c33, v_c32, v_c39}, [&](const std::array<u64,3>& m182) {
                  if (!slog::exists_probe<3,2>(st_diffindex106, std::array<u64,3>{v_c23, v_c39, 0})) return;
                  slog::join_probe_old<3,2>(st_mskindex107, st_mskdelta116, std::array<u64,3>{v_c35, v_c22, 0}, [&](const std::array<u64,3>& m183) {
                    u64 v_c40 = m183[2];
                    slog::join_probe_old<2,2>(st_msk_ansindex108, st_msk_ansdelta117, std::array<u64,2>{v_c40, v_c21}, [&](const std::array<u64,2>& m184) {
                      slog::join_probe_old<3,2>(st_diffindex109, st_diffdelta118, std::array<u64,3>{v_c23, v_c39, 0}, [&](const std::array<u64,3>& m185) {
                        u64 v_c41 = m185[2];
                        slog::join_probe_old<2,2>(st_diff_ansindex110, st_diff_ansdelta119, std::array<u64,2>{v_c41, v_c4}, [&](const std::array<u64,2>& m186) {
                          u64 v_c42 = _prim_band(db, v_c35, v_c22);
                          if (v_c42 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c43 = _prim_lt(db, v_c42, v_c29);
                          if (v_c43 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c43) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask120* _cont = new ReadTask120(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask120(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_diff __t0YPK165 l __t6ACr164) (body (exists st_diff (2 0 1) 1 __t6ACr164) (exists pbranch (3 0 1 2 4) 1 l) (exists $sup9688x139x0x0x0 (1 0 2 3 4 5 6 7 8) 1 l) (join st_diff_ans (0 1) 1 __t0YPK165 __v0) (exists st_bld (3 0 1 2 4) 1 __v0) (join st_diff (2 0 1) 1 __t6ACr164 __t3X8M159 __t66RN158) (exists $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3X8M159 l) (join pbranch (3 0 1 2 4) 2 l __t66RN158 p m r) (exists st_bld (1 2 3 4 0) 4 p m __v0 r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 5 p m r l __t3X8M159 n q u v) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 q n u v __t6ACr164) (exists st_msk (1 2 0) 2 q m) (join st_bld (1 2 3 4 0) 4 p m __v0 r __t1RXD162) (exists st_bld_ans (0 1) 1 __t1RXD162) (join st_msk (1 2 0) 2 q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask207 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex188;  slog::Index** pbranchindex189;  slog::Index** $sup9688x139x0x0x0index190;  slog::Index** st_diff_ansindex191;  slog::Index** st_bldindex192;  slog::Index** st_diffindex193;  slog::Index** $sup9688x139x0x0x0index194;  slog::Index** pbranchindex195;  slog::Index** st_bldindex196;  slog::Index** st_mskindex197;  slog::Index** st_msk_ansindex198;  slog::Index** $sup9688x139x0x0x0index199;  slog::Index** pbranchindex200;  slog::Index** st_mskindex201;  slog::Index** st_bldindex202;  slog::Index** st_bld_ansindex203;  slog::Index** st_mskindex204;  slog::Index** st_msk_ansindex205;  slog::Index** st_bld_ansindex206;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("st_diff_ans");
      head_index[0] = readrel209->getIndex(ord208, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord210({2, 0, 1});
      slog::Relation* readrel211 = db->getRelation("st_diff");
      st_diffindex188 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({3, 0, 1, 2, 4});
      slog::Relation* readrel213 = db->getRelation("pbranch");
      pbranchindex189 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 0, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel215 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index190 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("st_diff_ans");
      st_diff_ansindex191 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({3, 0, 1, 2, 4});
      slog::Relation* readrel219 = db->getRelation("st_bld");
      st_bldindex192 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({2, 0, 1});
      slog::Relation* readrel221 = db->getRelation("st_diff");
      st_diffindex193 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel223 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index194 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({3, 0, 1, 2, 4});
      slog::Relation* readrel225 = db->getRelation("pbranch");
      pbranchindex195 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 3, 4, 0});
      slog::Relation* readrel227 = db->getRelation("st_bld");
      st_bldindex196 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({2, 0, 1});
      slog::Relation* readrel229 = db->getRelation("st_msk");
      st_mskindex197 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("st_msk_ans");
      st_msk_ansindex198 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel233 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index199 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 3, 4, 0});
      slog::Relation* readrel235 = db->getRelation("pbranch");
      pbranchindex200 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("st_msk");
      st_mskindex201 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("st_bld");
      st_bldindex202 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("st_bld_ans");
      st_bld_ansindex203 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("st_msk");
      st_mskindex204 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 1});
      slog::Relation* readrel245 = db->getRelation("st_msk_ans");
      st_msk_ansindex205 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({0, 1});
      slog::Relation* readrel247 = db->getRelation("st_bld_ans");
      st_bld_ansindex206 = readrel247->getIndex(ord246, false);
  
    }
    ReadTask207(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c39 = _t[2];
        if (!slog::exists_probe<3,1>(st_diffindex188, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex189, std::array<u64,5>{v_c23, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index190, std::array<u64,9>{v_c23, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex191, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m248) {
          u64 v_c4 = m248[1];
          if (!slog::exists_probe<5,1>(st_bldindex192, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(st_diffindex193, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m249) {
            u64 v_c33 = m249[1]; u64 v_c32 = m249[2];
            if (!slog::exists_probe<9,2>($sup9688x139x0x0x0index194, std::array<u64,9>{v_c33, v_c23, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex195, std::array<u64,5>{v_c23, v_c32, 0, 0, 0}, [&](const std::array<u64,5>& m250) {
              u64 v_c21 = m250[2]; u64 v_c22 = m250[3]; u64 v_c24 = m250[4];
              if (!slog::exists_probe<5,4>(st_bldindex196, std::array<u64,5>{v_c21, v_c22, v_c4, v_c24, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex197, std::array<u64,3>{v_c22, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex198, std::array<u64,2>{v_c21, 0})) return;
              slog::join_probe<9,5>($sup9688x139x0x0x0index199, std::array<u64,9>{v_c21, v_c22, v_c24, v_c23, v_c33, 0, 0, 0, 0}, [&](const std::array<u64,9>& m251) {
                u64 v_c34 = m251[5]; u64 v_c35 = m251[6]; u64 v_c36 = m251[7]; u64 v_c37 = m251[8];
                u64 v_c44 = _prim_lt(db, v_c34, v_c22);
                if (v_c44 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                if (!v_c44) return;
                slog::join_probe<5,5>(pbranchindex200, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, v_c39}, [&](const std::array<u64,5>& m253) {
                  if (!slog::exists_probe<3,2>(st_mskindex201, std::array<u64,3>{v_c35, v_c22, 0})) return;
                  slog::join_probe<5,4>(st_bldindex202, std::array<u64,5>{v_c21, v_c22, v_c4, v_c24, 0}, [&](const std::array<u64,5>& m254) {
                    u64 v_c30 = m254[4];
                    if (!slog::exists_probe<2,1>(st_bld_ansindex203, std::array<u64,2>{v_c30, 0})) return;
                    slog::join_probe<3,2>(st_mskindex204, std::array<u64,3>{v_c35, v_c22, 0}, [&](const std::array<u64,3>& m255) {
                      u64 v_c40 = m255[2];
                      slog::join_probe<2,2>(st_msk_ansindex205, std::array<u64,2>{v_c40, v_c21}, [&](const std::array<u64,2>& m256) {
                        slog::join_probe<2,1>(st_bld_ansindex206, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m257) {
                          u64 v_c31 = m257[1];
                          u64 v_c42 = _prim_band(db, v_c35, v_c22);
                          if (v_c42 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c45 = _prim_lt(db, v_c42, v_c29);
                          if (v_c45 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c45) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask207* _cont = new ReadTask207(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask207(db,b), false);
  // (crule (pre) (scan st_join_ans __t4hUr14 res) (body (join-old st_join (0 1 2 3 4) 1 (0 1 2 3 4) __t4hUr14 k __t4JtR13 p __t4iIu12) (join-old pleaf (0 1) 2 (0 1) __t4JtR13 k) (exists $sup9688x54x0x0x0 (1 4 6 3 0 2 5) 3 k p __t4iIu12) (exists pbranch (0 1 2 3 4) 2 __t4iIu12 p) (exists st_msk (1 2 0) 1 k) (join-old st_ins (1 2 0) 2 (1 2 0) __t4iIu12 k __t2YgE11) (join-old $sup9688x54x0x0x0 (0 1 6 4 2 3 5) 4 (0 1 6 4 2 3 5) __t2YgE11 k __t4iIu12 p l m r) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t4iIu12) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join-old st_msk_ans (0 1) 1 (0 1) __t9Q9j15 __v0) (neq p __v0)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask276 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex259;  slog::Index** pleafindex260;  slog::Index** $sup9688x54x0x0x0index261;  slog::Index** pbranchindex262;  slog::Index** st_mskindex263;  slog::Index** st_insindex264;  slog::Index** $sup9688x54x0x0x0index265;  slog::Index** pbranchindex266;  slog::Index** st_mskindex267;  slog::Index** st_msk_ansindex268;  slog::Index** st_joindelta269;  slog::Index** pleafdelta270;  slog::Index** st_insdelta271;  slog::Index** $sup9688x54x0x0x0delta272;  slog::Index** pbranchdelta273;  slog::Index** st_mskdelta274;  slog::Index** st_msk_ansdelta275;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("st_ins_ans");
      head_index[0] = readrel278->getIndex(ord277, false);
      outer_rel = db->getRelation("st_join_ans");
      std::vector<u16> ord279({0, 1, 2, 3, 4});
      slog::Relation* readrel280 = db->getRelation("st_join");
      st_joinindex259 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({0, 1, 2, 3, 4});
      slog::Relation* readrel282 = db->getRelation("st_join");
      st_joindelta269 = readrel282->getIndex(ord281, true);
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("pleaf");
      pleafindex260 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("pleaf");
      pleafdelta270 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel288 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index261 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2, 3, 4});
      slog::Relation* readrel290 = db->getRelation("pbranch");
      pbranchindex262 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("st_msk");
      st_mskindex263 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("st_ins");
      st_insindex264 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 2, 0});
      slog::Relation* readrel296 = db->getRelation("st_ins");
      st_insdelta271 = readrel296->getIndex(ord295, true);
      std::vector<u16> ord297({0, 1, 6, 4, 2, 3, 5});
      slog::Relation* readrel298 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index265 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 1, 6, 4, 2, 3, 5});
      slog::Relation* readrel300 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0delta272 = readrel300->getIndex(ord299, true);
      std::vector<u16> ord301({1, 2, 3, 4, 0});
      slog::Relation* readrel302 = db->getRelation("pbranch");
      pbranchindex266 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 3, 4, 0});
      slog::Relation* readrel304 = db->getRelation("pbranch");
      pbranchdelta273 = readrel304->getIndex(ord303, true);
      std::vector<u16> ord305({1, 2, 0});
      slog::Relation* readrel306 = db->getRelation("st_msk");
      st_mskindex267 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("st_msk");
      st_mskdelta274 = readrel308->getIndex(ord307, true);
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("st_msk_ans");
      st_msk_ansindex268 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("st_msk_ans");
      st_msk_ansdelta275 = readrel312->getIndex(ord311, true);
  
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
        u64 v_c46 = _t[0];
        u64 v_c31 = _t[1];
        slog::join_probe_old<5,1>(st_joinindex259, st_joindelta269, std::array<u64,5>{v_c46, 0, 0, 0, 0}, [&](const std::array<u64,5>& m313) {
          u64 v_c20 = m313[1]; u64 v_c47 = m313[2]; u64 v_c21 = m313[3]; u64 v_c48 = m313[4];
          slog::join_probe_old<2,2>(pleafindex260, pleafdelta270, std::array<u64,2>{v_c47, v_c20}, [&](const std::array<u64,2>& m314) {
            if (!slog::exists_probe<7,3>($sup9688x54x0x0x0index261, std::array<u64,7>{v_c20, v_c21, v_c48, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<5,2>(pbranchindex262, std::array<u64,5>{v_c48, v_c21, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex263, std::array<u64,3>{v_c20, 0, 0})) return;
            slog::join_probe_old<3,2>(st_insindex264, st_insdelta271, std::array<u64,3>{v_c48, v_c20, 0}, [&](const std::array<u64,3>& m315) {
              u64 v_c49 = m315[2];
              slog::join_probe_old<7,4>($sup9688x54x0x0x0index265, $sup9688x54x0x0x0delta272, std::array<u64,7>{v_c49, v_c20, v_c48, v_c21, 0, 0, 0}, [&](const std::array<u64,7>& m316) {
                u64 v_c23 = m316[4]; u64 v_c22 = m316[5]; u64 v_c24 = m316[6];
                slog::join_probe_old<5,5>(pbranchindex266, pbranchdelta273, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c48}, [&](const std::array<u64,5>& m317) {
                  slog::join_probe_old<3,2>(st_mskindex267, st_mskdelta274, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m318) {
                    u64 v_c50 = m318[2];
                    slog::join_probe_old<2,1>(st_msk_ansindex268, st_msk_ansdelta275, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m319) {
                      u64 v_c4 = m319[1];
                      if (v_c21 == v_c4) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_join_ans", _fires);
  
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
  // (crule (pre) (scan pbranch __t7ytQ417 q n u v) (body (exists st_diff (2 0 1) 1 __t7ytQ417) (exists st_msk (2 0 1) 1 n) (join $sup9688x154x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t0EGY419 l m p r) (cmp lt m n) (exists st_diff (2 0 1) 2 __t7ytQ417 __t0EGY419) (exists st_msk (1 2 0) 2 p n) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1fgd418) (join-old st_diff (0 1 2) 3 (0 1 2) __t0EGY419 __t1fgd418 __t7ytQ417) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t8lOi420) (join st_msk_ans (0 1) 1 __t8lOi420 __v0) (neq q __v0)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask332 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex320;  slog::Index** st_mskindex321;  slog::Index** $sup9688x154x0x0x0index322;  slog::Index** st_diffindex323;  slog::Index** st_mskindex324;  slog::Index** pbranchindex325;  slog::Index** st_diffindex326;  slog::Index** st_mskindex327;  slog::Index** st_msk_ansindex328;  slog::Index** pbranchdelta329;  slog::Index** st_diffdelta330;  slog::Index** st_mskdelta331;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord333({0, 1});
      slog::Relation* readrel334 = db->getRelation("st_diff_ans");
      head_index[0] = readrel334->getIndex(ord333, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord335({2, 0, 1});
      slog::Relation* readrel336 = db->getRelation("st_diff");
      st_diffindex320 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({2, 0, 1});
      slog::Relation* readrel338 = db->getRelation("st_msk");
      st_mskindex321 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel340 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index322 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({2, 0, 1});
      slog::Relation* readrel342 = db->getRelation("st_diff");
      st_diffindex323 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("st_msk");
      st_mskindex324 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 2, 3, 4, 0});
      slog::Relation* readrel346 = db->getRelation("pbranch");
      pbranchindex325 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 2, 3, 4, 0});
      slog::Relation* readrel348 = db->getRelation("pbranch");
      pbranchdelta329 = readrel348->getIndex(ord347, true);
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("st_diff");
      st_diffindex326 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({0, 1, 2});
      slog::Relation* readrel352 = db->getRelation("st_diff");
      st_diffdelta330 = readrel352->getIndex(ord351, true);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("st_msk");
      st_mskindex327 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 0});
      slog::Relation* readrel356 = db->getRelation("st_msk");
      st_mskdelta331 = readrel356->getIndex(ord355, true);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("st_msk_ans");
      st_msk_ansindex328 = readrel358->getIndex(ord357, false);
  
    }
    ReadTask332(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c37 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex320, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex321, std::array<u64,3>{v_c34, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x154x0x0x0index322, std::array<u64,9>{v_c34, v_c35, v_c36, v_c37, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m359) {
          u64 v_c52 = m359[4]; u64 v_c23 = m359[5]; u64 v_c22 = m359[6]; u64 v_c21 = m359[7]; u64 v_c24 = m359[8];
          u64 v_c53 = _prim_lt(db, v_c22, v_c34);
          if (v_c53 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
          if (!v_c53) return;
          if (!slog::exists_probe<3,2>(st_diffindex323, std::array<u64,3>{v_c51, v_c52, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex324, std::array<u64,3>{v_c21, v_c34, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex325, pbranchdelta329, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m361) {
            u64 v_c54 = m361[4];
            slog::join_probe_old<3,3>(st_diffindex326, st_diffdelta330, std::array<u64,3>{v_c52, v_c54, v_c51}, [&](const std::array<u64,3>& m362) {
              slog::join_probe_old<3,2>(st_mskindex327, st_mskdelta331, std::array<u64,3>{v_c21, v_c34, 0}, [&](const std::array<u64,3>& m363) {
                u64 v_c55 = m363[2];
                slog::join_probe<2,1>(st_msk_ansindex328, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m364) {
                  u64 v_c4 = m364[1];
                  if (v_c35 == v_c4) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c54}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask332* _cont = new ReadTask332(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask332(db,b), false);
  // (crule (pre) (scan st_msk __t88lr525 p n) (body (exists $sup9688x117x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join st_msk_ans (0 1) 1 __t88lr525 q) (join $sup9688x117x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t88lr525 l m n p q r u)) set.slog:118 #f)
  class ReadTask368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x0index365;  slog::Index** st_msk_ansindex366;  slog::Index** $sup9688x117x0x0x0index367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord369({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel370 = db->getRelation("$sup9688x117x0x0x1");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord371({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel372 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index365 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({0, 1});
      slog::Relation* readrel374 = db->getRelation("st_msk_ans");
      st_msk_ansindex366 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel376 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index367 = readrel376->getIndex(ord375, false);
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x117x0x0x0index365, std::array<u64,9>{v_c34, v_c21, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex366, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m377) {
          u64 v_c35 = m377[1];
          slog::join_probe<9,3>($sup9688x117x0x0x0index367, std::array<u64,9>{v_c34, v_c21, v_c35, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m378) {
            u64 v_c28 = m378[3]; u64 v_c23 = m378[4]; u64 v_c22 = m378[5]; u64 v_c24 = m378[6]; u64 v_c36 = m378[7]; u64 v_c37 = m378[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c28, v_c37, v_c56, v_c23, v_c22, v_c34, v_c21, v_c35, v_c24, v_c36}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_msk", _fires);
  
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
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk63FT1302 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk63FT1302) (letp chk8wKs1303 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk8wKs1303) (letp chk1T9y1304 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk1T9y1304) (letp chk4Xf51305 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk4Xf51305) (letp chk1kjP1306 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk1kjP1306)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask393 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex379;  slog::Index** $seq_atindex380;  slog::Index** $seq_atindex381;  slog::Index** $seq_atrindex382;  slog::Index** $seq_atrindex383;  slog::Index** $seq_atrindex384;  slog::Index** $seq_atrindex385;  slog::Index** st_fromlistindex386;  slog::Index** st_fromlist_ansindex387;  slog::Index** $seq_atdelta388;  slog::Index** $seq_atrdelta389;  slog::Index** $seq_atrdelta390;  slog::Index** $seq_atrdelta391;  slog::Index** $seq_atrdelta392;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord394({0});
      slog::Relation* readrel395 = db->getRelation("canon");
      head_index[0] = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0, 2});
      slog::Relation* readrel397 = db->getRelation("$seq_at");
      driver_index = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({1, 0, 2});
      slog::Relation* readrel399 = db->getRelation("$seq_at");
      $seq_atindex379 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 0, 2});
      slog::Relation* readrel401 = db->getRelation("$seq_at");
      $seq_atindex380 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0, 2});
      slog::Relation* readrel403 = db->getRelation("$seq_at");
      $seq_atindex381 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 0, 2});
      slog::Relation* readrel405 = db->getRelation("$seq_at");
      $seq_atdelta388 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({0, 1, 2});
      slog::Relation* readrel407 = db->getRelation("$seq_atr");
      $seq_atrindex382 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({0, 1, 2});
      slog::Relation* readrel409 = db->getRelation("$seq_atr");
      $seq_atrdelta389 = readrel409->getIndex(ord408, true);
      std::vector<u16> ord410({0, 1, 2});
      slog::Relation* readrel411 = db->getRelation("$seq_atr");
      $seq_atrindex383 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({0, 1, 2});
      slog::Relation* readrel413 = db->getRelation("$seq_atr");
      $seq_atrdelta390 = readrel413->getIndex(ord412, true);
      std::vector<u16> ord414({0, 1, 2});
      slog::Relation* readrel415 = db->getRelation("$seq_atr");
      $seq_atrindex384 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1, 2});
      slog::Relation* readrel417 = db->getRelation("$seq_atr");
      $seq_atrdelta391 = readrel417->getIndex(ord416, true);
      std::vector<u16> ord418({0, 1, 2});
      slog::Relation* readrel419 = db->getRelation("$seq_atr");
      $seq_atrindex385 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 1, 2});
      slog::Relation* readrel421 = db->getRelation("$seq_atr");
      $seq_atrdelta392 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({1, 0});
      slog::Relation* readrel423 = db->getRelation("st_fromlist");
      st_fromlistindex386 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex387 = readrel425->getIndex(ord424, false);
  
    }
    ReadTask393(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constef2d127de37b942baad06145;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_constd4735e3a265e16eee03f5971;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_const2c624232cdd221771294dfbb;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c66 = v_constef2d127de37b942baad06145;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const2c624232cdd221771294dfbb;
      u64 v_c71 = v_constd4735e3a265e16eee03f5971;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c74 = v_constef2d127de37b942baad06145;
      u64 v_c75 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c76 = v_constd4735e3a265e16eee03f5971;
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const2c624232cdd221771294dfbb;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c71, v_c70, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m426) {
        u64 v_c82 = m426[2];
        if (buckethash(v_c82) != bucket) return;
        slog::join_probe<3,3>($seq_atindex379, std::array<u64,3>{v_c67, v_c66, v_c82}, [&](const std::array<u64,3>& m427) {
          slog::join_probe<3,3>($seq_atindex380, std::array<u64,3>{v_c69, v_c68, v_c82}, [&](const std::array<u64,3>& m428) {
            slog::join_probe_old<3,3>($seq_atindex381, $seq_atdelta388, std::array<u64,3>{v_c73, v_c72, v_c82}, [&](const std::array<u64,3>& m429) {
              slog::join_probe_old<3,3>($seq_atrindex382, $seq_atrdelta389, std::array<u64,3>{v_c74, v_c75, v_c82}, [&](const std::array<u64,3>& m430) {
                slog::join_probe_old<3,3>($seq_atrindex383, $seq_atrdelta390, std::array<u64,3>{v_c76, v_c77, v_c82}, [&](const std::array<u64,3>& m431) {
                  slog::join_probe_old<3,3>($seq_atrindex384, $seq_atrdelta391, std::array<u64,3>{v_c78, v_c79, v_c82}, [&](const std::array<u64,3>& m432) {
                    slog::join_probe_old<3,3>($seq_atrindex385, $seq_atrdelta392, std::array<u64,3>{v_c80, v_c81, v_c82}, [&](const std::array<u64,3>& m433) {
                      slog::join_probe<2,1>(st_fromlistindex386, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m434) {
                        u64 v_c83 = m434[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex387, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m435) {
                          u64 v_c24 = m435[1];
                          bool ok436 = true;
                          u64 v_c84 = _prim_aslst(db, v_c82, &ok436);
                          if (!ok436) return;
                          u64 v_c85 = _prim_llen(db, v_c84);
                          if (v_c85 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c57 != v_c85) return;
                          bool ok437 = true;
                          u64 v_c86 = _prim_lref(db, v_c84, v_c58, &ok437);
                          if (!ok437) return;
                          if (v_c59 != v_c86) return;
                          bool ok438 = true;
                          u64 v_c87 = _prim_lref(db, v_c84, v_c60, &ok438);
                          if (!ok438) return;
                          if (v_c61 != v_c87) return;
                          bool ok439 = true;
                          u64 v_c88 = _prim_lref(db, v_c84, v_c62, &ok439);
                          if (!ok439) return;
                          if (v_c63 != v_c88) return;
                          bool ok440 = true;
                          u64 v_c89 = _prim_lref(db, v_c84, v_c64, &ok440);
                          if (!ok440) return;
                          if (v_c65 != v_c89) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask393* _cont = new ReadTask393(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask393(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan st_diff __t5Ek2104 __t6qKy107 __t6SZQ102) (body (exists $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) 1 __t5Ek2104) (join-old st_diff (1 2 0) 1 (1 2 0) __t6qKy107 u __t4u9h108) (exists $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t5Ek2104 u) (exists st_diff_ans (0 1) 1 __t4u9h108) (join pbranch (3 0 1 2 4) 2 u __t6SZQ102 q n v) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x148x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t5Ek2104 l m p r) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6qKy107) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join st_msk_ans (0 1) 2 __t3oZy109 q) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask456 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x148x0x0x0index441;  slog::Index** st_diffindex442;  slog::Index** $sup9688x148x0x0x0index443;  slog::Index** st_diff_ansindex444;  slog::Index** pbranchindex445;  slog::Index** st_mskindex446;  slog::Index** st_msk_ansindex447;  slog::Index** $sup9688x148x0x0x0index448;  slog::Index** pbranchindex449;  slog::Index** st_mskindex450;  slog::Index** st_msk_ansindex451;  slog::Index** st_diff_ansindex452;  slog::Index** st_diffdelta453;  slog::Index** pbranchdelta454;  slog::Index** st_mskdelta455;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord457({0, 1});
      slog::Relation* readrel458 = db->getRelation("st_diff_ans");
      head_index[0] = readrel458->getIndex(ord457, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord459({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel460 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index441 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0});
      slog::Relation* readrel462 = db->getRelation("st_diff");
      st_diffindex442 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 0});
      slog::Relation* readrel464 = db->getRelation("st_diff");
      st_diffdelta453 = readrel464->getIndex(ord463, true);
      std::vector<u16> ord465({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel466 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index443 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("st_diff_ans");
      st_diff_ansindex444 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({3, 0, 1, 2, 4});
      slog::Relation* readrel470 = db->getRelation("pbranch");
      pbranchindex445 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({2, 0, 1});
      slog::Relation* readrel472 = db->getRelation("st_msk");
      st_mskindex446 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 0});
      slog::Relation* readrel474 = db->getRelation("st_msk_ans");
      st_msk_ansindex447 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel476 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index448 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 3, 4, 0});
      slog::Relation* readrel478 = db->getRelation("pbranch");
      pbranchindex449 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 4, 0});
      slog::Relation* readrel480 = db->getRelation("pbranch");
      pbranchdelta454 = readrel480->getIndex(ord479, true);
      std::vector<u16> ord481({1, 2, 0});
      slog::Relation* readrel482 = db->getRelation("st_msk");
      st_mskindex450 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("st_msk");
      st_mskdelta455 = readrel484->getIndex(ord483, true);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("st_msk_ans");
      st_msk_ansindex451 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("st_diff_ans");
      st_diff_ansindex452 = readrel488->getIndex(ord487, false);
  
    }
    ReadTask456(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c91 = _t[0];
        u64 v_c92 = _t[1];
        u64 v_c93 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x148x0x0x0index441, std::array<u64,9>{v_c91, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex442, st_diffdelta453, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m489) {
          u64 v_c36 = m489[1]; u64 v_c94 = m489[2];
          if (!slog::exists_probe<9,2>($sup9688x148x0x0x0index443, std::array<u64,9>{v_c91, v_c36, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex444, std::array<u64,2>{v_c94, 0})) return;
          slog::join_probe<5,2>(pbranchindex445, std::array<u64,5>{v_c36, v_c93, 0, 0, 0}, [&](const std::array<u64,5>& m490) {
            u64 v_c35 = m490[2]; u64 v_c34 = m490[3]; u64 v_c37 = m490[4];
            if (!slog::exists_probe<3,1>(st_mskindex446, std::array<u64,3>{v_c34, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex447, std::array<u64,2>{v_c35, 0})) return;
            slog::join_probe<9,5>($sup9688x148x0x0x0index448, std::array<u64,9>{v_c35, v_c34, v_c36, v_c37, v_c91, 0, 0, 0, 0}, [&](const std::array<u64,9>& m491) {
              u64 v_c23 = m491[5]; u64 v_c22 = m491[6]; u64 v_c21 = m491[7]; u64 v_c24 = m491[8];
              u64 v_c95 = _prim_lt(db, v_c22, v_c34);
              if (v_c95 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
              if (!v_c95) return;
              slog::join_probe_old<5,5>(pbranchindex449, pbranchdelta454, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c92}, [&](const std::array<u64,5>& m493) {
                slog::join_probe_old<3,2>(st_mskindex450, st_mskdelta455, std::array<u64,3>{v_c21, v_c34, 0}, [&](const std::array<u64,3>& m494) {
                  u64 v_c96 = m494[2];
                  slog::join_probe<2,2>(st_msk_ansindex451, std::array<u64,2>{v_c96, v_c35}, [&](const std::array<u64,2>& m495) {
                    slog::join_probe<2,1>(st_diff_ansindex452, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m496) {
                      u64 v_c31 = m496[1];
                      u64 v_c97 = _prim_band(db, v_c21, v_c34);
                      if (v_c97 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c98 = _prim_lt(db, v_c97, v_c90);
                      if (v_c98 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c98) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c91, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:st_diff", _fires);
  
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
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan st_msk __t1Zy964 p n) (body (exists $sup9688x114x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (exists st_msk_ans (0 1) 1 __t1Zy964) (join $sup9688x114x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t1Zy964 n p q __t2j0W61 l m r u v) (cmp lt m n) (join $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t2j0W61 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk_ans (0 1) 2 __t1Zy964 q) (exists st_union (2 0 1) 1 u) (join pbranch (1 2 3 4 0) 4 q n u v __t2ifW59) (exists st_union (2 0 1) 2 __t2ifW59 __t2j0W61) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5Obr65) (join st_union (0 1 2) 3 __t2j0W61 __t5Obr65 __t2ifW59) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x0index498;  slog::Index** pbranchindex499;  slog::Index** pbranchindex500;  slog::Index** st_msk_ansindex501;  slog::Index** $sup9688x114x0x0x1index502;  slog::Index** $sup9688x114x0x0x0index503;  slog::Index** pbranchindex504;  slog::Index** st_msk_ansindex505;  slog::Index** st_unionindex506;  slog::Index** pbranchindex507;  slog::Index** st_unionindex508;  slog::Index** pbranchindex509;  slog::Index** st_unionindex510;  slog::Index** st_msk_ansindex511;  slog::Index** st_unionindex512;  slog::Index** st_union_ansindex513;  slog::Index** pbranchdelta514;  slog::Index** st_uniondelta515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord517({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel518 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index498 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({2, 0, 1, 3, 4});
      slog::Relation* readrel520 = db->getRelation("pbranch");
      pbranchindex499 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 2, 3, 4, 0});
      slog::Relation* readrel522 = db->getRelation("pbranch");
      pbranchindex500 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1});
      slog::Relation* readrel524 = db->getRelation("st_msk_ans");
      st_msk_ansindex501 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel526 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index502 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel528 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index503 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 3, 4, 0});
      slog::Relation* readrel530 = db->getRelation("pbranch");
      pbranchindex504 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1});
      slog::Relation* readrel532 = db->getRelation("st_msk_ans");
      st_msk_ansindex505 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({2, 0, 1});
      slog::Relation* readrel534 = db->getRelation("st_union");
      st_unionindex506 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 3, 4, 0});
      slog::Relation* readrel536 = db->getRelation("pbranch");
      pbranchindex507 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({2, 0, 1});
      slog::Relation* readrel538 = db->getRelation("st_union");
      st_unionindex508 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 3, 4, 0});
      slog::Relation* readrel540 = db->getRelation("pbranch");
      pbranchindex509 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 3, 4, 0});
      slog::Relation* readrel542 = db->getRelation("pbranch");
      pbranchdelta514 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({0, 1, 2});
      slog::Relation* readrel544 = db->getRelation("st_union");
      st_unionindex510 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("st_msk_ans");
      st_msk_ansindex511 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("st_union");
      st_unionindex512 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("st_union");
      st_uniondelta515 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("st_union_ans");
      st_union_ansindex513 = readrel552->getIndex(ord551, false);
  
    }
    ReadTask516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x114x0x0x0index498, std::array<u64,9>{v_c34, v_c21, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex499, std::array<u64,5>{v_c34, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex500, std::array<u64,5>{v_c21, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex501, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<10,3>($sup9688x114x0x0x1index502, std::array<u64,10>{v_c100, v_c34, v_c21, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m553) {
          u64 v_c35 = m553[3]; u64 v_c101 = m553[4]; u64 v_c23 = m553[5]; u64 v_c22 = m553[6]; u64 v_c24 = m553[7]; u64 v_c36 = m553[8]; u64 v_c37 = m553[9];
          u64 v_c102 = _prim_lt(db, v_c22, v_c34);
          if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
          if (!v_c102) return;
          slog::join_probe<9,9>($sup9688x114x0x0x0index503, std::array<u64,9>{v_c35, v_c34, v_c36, v_c37, v_c101, v_c23, v_c22, v_c21, v_c24}, [&](const std::array<u64,9>& m555) {
            if (!slog::exists_probe<5,4>(pbranchindex504, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex505, std::array<u64,2>{v_c100, v_c35})) return;
            if (!slog::exists_probe<3,1>(st_unionindex506, std::array<u64,3>{v_c36, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex507, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m556) {
              u64 v_c103 = m556[4];
              if (!slog::exists_probe<3,2>(st_unionindex508, std::array<u64,3>{v_c103, v_c101, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex509, pbranchdelta514, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m557) {
                u64 v_c104 = m557[4];
                slog::join_probe<3,3>(st_unionindex510, std::array<u64,3>{v_c101, v_c104, v_c103}, [&](const std::array<u64,3>& m558) {
                  slog::join_probe<2,2>(st_msk_ansindex511, std::array<u64,2>{v_c100, v_c35}, [&](const std::array<u64,2>& m559) {
                    slog::join_probe_old<3,2>(st_unionindex512, st_uniondelta515, std::array<u64,3>{v_c104, v_c36, 0}, [&](const std::array<u64,3>& m560) {
                      u64 v_c105 = m560[2];
                      slog::join_probe<2,1>(st_union_ansindex513, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m561) {
                        u64 v_c4 = m561[1];
                        u64 v_c106 = _prim_band(db, v_c21, v_c34);
                        if (v_c106 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c107 = _prim_lt(db, v_c106, v_c99);
                        if (v_c107 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c107) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c101, v_c4, v_c34, v_c35, v_c37});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c34, v_c4, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask516* _cont = new ReadTask516(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask516(db,b), false);
  // (crule (pre) (scan temp3vnE1273 __t5HrQ362) (body) (head (mkstruct st_hsb (1 0) __2ib4871 __t5HrQ362)) set.slog:37 #f)
  class ReadTask563 : public slog::Task
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
      head_rel[0] = db->getRelation("st_hsb");
      outer_rel = db->getRelation("temp3vnE1273");
  
    }
    ReadTask563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c108 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c108}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:temp3vnE1273", _fires);
  
      if (!_done)
      {
        ReadTask563* _cont = new ReadTask563(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask563(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_bld_ans __t8CKV493 res) (body (join-old st_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t8CKV493 p m l __v0) (exists $sup9688x90x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del_ans (1 0) 1 __v0) (join-old pbranch (1 2 3 4 0) 3 (1 2 3 4 0) p m l r __t4hkT489) (exists st_del (1 2 0) 1 __t4hkT489) (exists st_del (1 2 0) 1 r) (join-old $sup9688x90x0x0x0 (4 2 3 5 0 1) 4 (4 2 3 5 0 1) p l m r __t3j4h490 k) (join-old st_del (0 2 1) 3 (0 2 1) __t3j4h490 k __t4hkT489) (exists st_del (1 2 0) 2 r k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join-old st_msk_ans (0 1) 2 (0 1) __t44Py494 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join-old st_del_ans (0 1) 2 (0 1) __t9BRr495 __v0) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask587 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex564;  slog::Index** $sup9688x90x0x0x0index565;  slog::Index** st_mskindex566;  slog::Index** st_msk_ansindex567;  slog::Index** st_del_ansindex568;  slog::Index** pbranchindex569;  slog::Index** st_delindex570;  slog::Index** st_delindex571;  slog::Index** $sup9688x90x0x0x0index572;  slog::Index** st_delindex573;  slog::Index** st_delindex574;  slog::Index** st_mskindex575;  slog::Index** st_msk_ansindex576;  slog::Index** st_delindex577;  slog::Index** st_del_ansindex578;  slog::Index** st_blddelta579;  slog::Index** pbranchdelta580;  slog::Index** $sup9688x90x0x0x0delta581;  slog::Index** st_deldelta582;  slog::Index** st_mskdelta583;  slog::Index** st_msk_ansdelta584;  slog::Index** st_deldelta585;  slog::Index** st_del_ansdelta586;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord588({0, 1});
      slog::Relation* readrel589 = db->getRelation("st_del_ans");
      head_index[0] = readrel589->getIndex(ord588, false);
      outer_rel = db->getRelation("st_bld_ans");
      std::vector<u16> ord590({0, 1, 2, 3, 4});
      slog::Relation* readrel591 = db->getRelation("st_bld");
      st_bldindex564 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({0, 1, 2, 3, 4});
      slog::Relation* readrel593 = db->getRelation("st_bld");
      st_blddelta579 = readrel593->getIndex(ord592, true);
      std::vector<u16> ord594({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel595 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index565 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({2, 0, 1});
      slog::Relation* readrel597 = db->getRelation("st_msk");
      st_mskindex566 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 0});
      slog::Relation* readrel599 = db->getRelation("st_msk_ans");
      st_msk_ansindex567 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 0});
      slog::Relation* readrel601 = db->getRelation("st_del_ans");
      st_del_ansindex568 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 3, 4, 0});
      slog::Relation* readrel603 = db->getRelation("pbranch");
      pbranchindex569 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 2, 3, 4, 0});
      slog::Relation* readrel605 = db->getRelation("pbranch");
      pbranchdelta580 = readrel605->getIndex(ord604, true);
      std::vector<u16> ord606({1, 2, 0});
      slog::Relation* readrel607 = db->getRelation("st_del");
      st_delindex570 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 2, 0});
      slog::Relation* readrel609 = db->getRelation("st_del");
      st_delindex571 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel611 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index572 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel613 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0delta581 = readrel613->getIndex(ord612, true);
      std::vector<u16> ord614({0, 2, 1});
      slog::Relation* readrel615 = db->getRelation("st_del");
      st_delindex573 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({0, 2, 1});
      slog::Relation* readrel617 = db->getRelation("st_del");
      st_deldelta582 = readrel617->getIndex(ord616, true);
      std::vector<u16> ord618({1, 2, 0});
      slog::Relation* readrel619 = db->getRelation("st_del");
      st_delindex574 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("st_msk");
      st_mskindex575 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("st_msk");
      st_mskdelta583 = readrel623->getIndex(ord622, true);
      std::vector<u16> ord624({0, 1});
      slog::Relation* readrel625 = db->getRelation("st_msk_ans");
      st_msk_ansindex576 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({0, 1});
      slog::Relation* readrel627 = db->getRelation("st_msk_ans");
      st_msk_ansdelta584 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("st_del");
      st_delindex577 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("st_del");
      st_deldelta585 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({0, 1});
      slog::Relation* readrel633 = db->getRelation("st_del_ans");
      st_del_ansindex578 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("st_del_ans");
      st_del_ansdelta586 = readrel635->getIndex(ord634, true);
  
    }
    ReadTask587(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        u64 v_c31 = _t[1];
        slog::join_probe_old<5,1>(st_bldindex564, st_blddelta579, std::array<u64,5>{v_c110, 0, 0, 0, 0}, [&](const std::array<u64,5>& m636) {
          u64 v_c21 = m636[1]; u64 v_c22 = m636[2]; u64 v_c23 = m636[3]; u64 v_c4 = m636[4];
          if (!slog::exists_probe<6,3>($sup9688x90x0x0x0index565, std::array<u64,6>{v_c21, v_c23, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex566, std::array<u64,3>{v_c22, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex567, std::array<u64,2>{v_c21, 0})) return;
          if (!slog::exists_probe<2,1>(st_del_ansindex568, std::array<u64,2>{v_c4, 0})) return;
          slog::join_probe_old<5,3>(pbranchindex569, pbranchdelta580, std::array<u64,5>{v_c21, v_c22, v_c23, 0, 0}, [&](const std::array<u64,5>& m637) {
            u64 v_c24 = m637[3]; u64 v_c111 = m637[4];
            if (!slog::exists_probe<3,1>(st_delindex570, std::array<u64,3>{v_c111, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_delindex571, std::array<u64,3>{v_c24, 0, 0})) return;
            slog::join_probe_old<6,4>($sup9688x90x0x0x0index572, $sup9688x90x0x0x0delta581, std::array<u64,6>{v_c21, v_c23, v_c22, v_c24, 0, 0}, [&](const std::array<u64,6>& m638) {
              u64 v_c112 = m638[4]; u64 v_c20 = m638[5];
              slog::join_probe_old<3,3>(st_delindex573, st_deldelta582, std::array<u64,3>{v_c112, v_c20, v_c111}, [&](const std::array<u64,3>& m639) {
                if (!slog::exists_probe<3,2>(st_delindex574, std::array<u64,3>{v_c24, v_c20, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex575, st_mskdelta583, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m640) {
                  u64 v_c113 = m640[2];
                  slog::join_probe_old<2,2>(st_msk_ansindex576, st_msk_ansdelta584, std::array<u64,2>{v_c113, v_c21}, [&](const std::array<u64,2>& m641) {
                    slog::join_probe_old<3,2>(st_delindex577, st_deldelta585, std::array<u64,3>{v_c24, v_c20, 0}, [&](const std::array<u64,3>& m642) {
                      u64 v_c114 = m642[2];
                      slog::join_probe_old<2,2>(st_del_ansindex578, st_del_ansdelta586, std::array<u64,2>{v_c114, v_c4}, [&](const std::array<u64,2>& m643) {
                        u64 v_c115 = _prim_band(db, v_c20, v_c22);
                        if (v_c115 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c116 = _prim_gt(db, v_c115, v_c109);
                        if (v_c116 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c116) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c112, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_bld_ans", _fires);
  
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
  // (crule (pre) (scan st_union __t5NEh522 __t7NAj523 __t6acj524) (body (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t7NAj523 p m l r) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6acj524 q n u v) (cmp lt n m)) (head (emit $sup9688x110x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t5NEh522 l n p r __t7NAj523 __t6acj524 u v)) set.slog:111 #f)
  class ReadTask649 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex645;  slog::Index** pbranchindex646;  slog::Index** pbranchdelta647;  slog::Index** pbranchdelta648;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord650({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel651 = db->getRelation("$sup9688x110x0x0x0");
      head_index[0] = readrel651->getIndex(ord650, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord652({0, 1, 2, 3, 4});
      slog::Relation* readrel653 = db->getRelation("pbranch");
      pbranchindex645 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({0, 1, 2, 3, 4});
      slog::Relation* readrel655 = db->getRelation("pbranch");
      pbranchdelta647 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({0, 1, 2, 3, 4});
      slog::Relation* readrel657 = db->getRelation("pbranch");
      pbranchindex646 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 1, 2, 3, 4});
      slog::Relation* readrel659 = db->getRelation("pbranch");
      pbranchdelta648 = readrel659->getIndex(ord658, true);
  
    }
    ReadTask649(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c118 = _t[1];
        u64 v_c119 = _t[2];
        slog::join_probe_old<5,1>(pbranchindex645, pbranchdelta647, std::array<u64,5>{v_c118, 0, 0, 0, 0}, [&](const std::array<u64,5>& m660) {
          u64 v_c21 = m660[1]; u64 v_c22 = m660[2]; u64 v_c23 = m660[3]; u64 v_c24 = m660[4];
          slog::join_probe_old<5,1>(pbranchindex646, pbranchdelta648, std::array<u64,5>{v_c119, 0, 0, 0, 0}, [&](const std::array<u64,5>& m661) {
            u64 v_c35 = m661[1]; u64 v_c34 = m661[2]; u64 v_c36 = m661[3]; u64 v_c37 = m661[4];
            u64 v_c120 = _prim_lt(db, v_c34, v_c22);
            if (v_c120 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
            if (!v_c120) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c22, v_c35, v_c117, v_c23, v_c34, v_c21, v_c24, v_c118, v_c119, v_c36, v_c37}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask649* _cont = new ReadTask649(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask649(db,b), false);
  // (crule (pre) (scan st_diff_ans __t8u30411 __v1) (body (exists st_bld (4 0 1 2 3) 1 __v1) (join-old st_diff (0 1 2) 1 (0 1 2) __t8u30411 r v) (exists pbranch (4 0 1 2 3) 1 v) (exists pbranch (4 0 1 2 3) 1 r) (join-old $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 (4 6 0 1 2 3 5) r v __t5pD6408 l m p u) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_bld (2 1 4 0 3) 3 m p __v1) (exists st_diff (1 2 0) 2 l u) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t9ous406) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3cJ7407) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p __v1 __t9obY409 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t9obY409) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask688 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex663;  slog::Index** st_diffindex664;  slog::Index** pbranchindex665;  slog::Index** pbranchindex666;  slog::Index** $sup9688x136x0x0x0index667;  slog::Index** pbranchindex668;  slog::Index** st_bldindex669;  slog::Index** st_diffindex670;  slog::Index** pbranchindex671;  slog::Index** st_diffindex672;  slog::Index** pbranchindex673;  slog::Index** st_diffindex674;  slog::Index** st_bldindex675;  slog::Index** st_diff_ansindex676;  slog::Index** st_bld_ansindex677;  slog::Index** st_diffindex678;  slog::Index** st_diff_ansindex679;  slog::Index** st_bld_ansindex680;  slog::Index** st_diffdelta681;  slog::Index** $sup9688x136x0x0x0delta682;  slog::Index** pbranchdelta683;  slog::Index** pbranchdelta684;  slog::Index** st_diffdelta685;  slog::Index** st_blddelta686;  slog::Index** st_diffdelta687;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord689({0, 1});
      slog::Relation* readrel690 = db->getRelation("st_diff_ans");
      head_index[0] = readrel690->getIndex(ord689, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord691({4, 0, 1, 2, 3});
      slog::Relation* readrel692 = db->getRelation("st_bld");
      st_bldindex663 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1, 2});
      slog::Relation* readrel694 = db->getRelation("st_diff");
      st_diffindex664 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1, 2});
      slog::Relation* readrel696 = db->getRelation("st_diff");
      st_diffdelta681 = readrel696->getIndex(ord695, true);
      std::vector<u16> ord697({4, 0, 1, 2, 3});
      slog::Relation* readrel698 = db->getRelation("pbranch");
      pbranchindex665 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({4, 0, 1, 2, 3});
      slog::Relation* readrel700 = db->getRelation("pbranch");
      pbranchindex666 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel702 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index667 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel704 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0delta682 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({1, 2, 3, 4, 0});
      slog::Relation* readrel706 = db->getRelation("pbranch");
      pbranchindex668 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({2, 1, 4, 0, 3});
      slog::Relation* readrel708 = db->getRelation("st_bld");
      st_bldindex669 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("st_diff");
      st_diffindex670 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 3, 4, 0});
      slog::Relation* readrel712 = db->getRelation("pbranch");
      pbranchindex671 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 3, 4, 0});
      slog::Relation* readrel714 = db->getRelation("pbranch");
      pbranchdelta683 = readrel714->getIndex(ord713, true);
      std::vector<u16> ord715({2, 0, 1});
      slog::Relation* readrel716 = db->getRelation("st_diff");
      st_diffindex672 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 3, 4, 0});
      slog::Relation* readrel718 = db->getRelation("pbranch");
      pbranchindex673 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 3, 4, 0});
      slog::Relation* readrel720 = db->getRelation("pbranch");
      pbranchdelta684 = readrel720->getIndex(ord719, true);
      std::vector<u16> ord721({0, 1, 2});
      slog::Relation* readrel722 = db->getRelation("st_diff");
      st_diffindex674 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({0, 1, 2});
      slog::Relation* readrel724 = db->getRelation("st_diff");
      st_diffdelta685 = readrel724->getIndex(ord723, true);
      std::vector<u16> ord725({2, 1, 4, 0, 3});
      slog::Relation* readrel726 = db->getRelation("st_bld");
      st_bldindex675 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({2, 1, 4, 0, 3});
      slog::Relation* readrel728 = db->getRelation("st_bld");
      st_blddelta686 = readrel728->getIndex(ord727, true);
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("st_diff_ans");
      st_diff_ansindex676 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({0, 1});
      slog::Relation* readrel732 = db->getRelation("st_bld_ans");
      st_bld_ansindex677 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 0});
      slog::Relation* readrel734 = db->getRelation("st_diff");
      st_diffindex678 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 2, 0});
      slog::Relation* readrel736 = db->getRelation("st_diff");
      st_diffdelta687 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({0, 1});
      slog::Relation* readrel738 = db->getRelation("st_diff_ans");
      st_diff_ansindex679 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("st_bld_ans");
      st_bld_ansindex680 = readrel740->getIndex(ord739, false);
  
    }
    ReadTask688(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex663, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex664, st_diffdelta681, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m741) {
          u64 v_c24 = m741[1]; u64 v_c37 = m741[2];
          if (!slog::exists_probe<5,1>(pbranchindex665, std::array<u64,5>{v_c37, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex666, std::array<u64,5>{v_c24, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup9688x136x0x0x0index667, $sup9688x136x0x0x0delta682, std::array<u64,7>{v_c24, v_c37, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m742) {
            u64 v_c122 = m742[2]; u64 v_c23 = m742[3]; u64 v_c22 = m742[4]; u64 v_c21 = m742[5]; u64 v_c36 = m742[6];
            if (!slog::exists_probe<5,4>(pbranchindex668, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex669, std::array<u64,5>{v_c22, v_c21, v_c2, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex670, std::array<u64,3>{v_c23, v_c36, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex671, pbranchdelta683, std::array<u64,5>{v_c21, v_c22, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m743) {
              u64 v_c123 = m743[4];
              if (!slog::exists_probe<3,2>(st_diffindex672, std::array<u64,3>{v_c123, v_c122, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex673, pbranchdelta684, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m744) {
                u64 v_c124 = m744[4];
                slog::join_probe_old<3,3>(st_diffindex674, st_diffdelta685, std::array<u64,3>{v_c122, v_c124, v_c123}, [&](const std::array<u64,3>& m745) {
                  slog::join_probe_old<5,3>(st_bldindex675, st_blddelta686, std::array<u64,5>{v_c22, v_c21, v_c2, 0, 0}, [&](const std::array<u64,5>& m746) {
                    u64 v_c125 = m746[3]; u64 v_c4 = m746[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex676, std::array<u64,2>{v_c4, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex677, std::array<u64,2>{v_c125, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex678, st_diffdelta687, std::array<u64,3>{v_c23, v_c36, 0}, [&](const std::array<u64,3>& m747) {
                      u64 v_c126 = m747[2];
                      slog::join_probe<2,2>(st_diff_ansindex679, std::array<u64,2>{v_c126, v_c4}, [&](const std::array<u64,2>& m748) {
                        slog::join_probe<2,1>(st_bld_ansindex680, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m749) {
                          u64 v_c31 = m749[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c122, v_c31}, std::array<u16,2>{0, 1});
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
        ReadTask688* _cont = new ReadTask688(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask688(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan $sup9688x70x0x0x0 __t6uqp323 k l m p r) (body (exists st_mem0 (2 0 1) 2 k __t6uqp323) (exists st_mem0 (1 2 0) 2 l k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t7Uqa322) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6uqp323 __t7Uqa322 k) (join-old st_mem0 (1 2 0) 2 (1 2 0) l k __t14DN326) (exists st_mem0_ans (0 1) 1 __t14DN326) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t3nJI327) (join st_msk_ans (0 1) 2 __t3nJI327 p) (join st_mem0_ans (0 1) 1 __t14DN326 a) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask765 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index750;  slog::Index** st_mem0index751;  slog::Index** st_mskindex752;  slog::Index** st_msk_ansindex753;  slog::Index** pbranchindex754;  slog::Index** st_mem0index755;  slog::Index** st_mem0index756;  slog::Index** st_mem0_ansindex757;  slog::Index** st_mskindex758;  slog::Index** st_msk_ansindex759;  slog::Index** st_mem0_ansindex760;  slog::Index** pbranchdelta761;  slog::Index** st_mem0delta762;  slog::Index** st_mem0delta763;  slog::Index** st_mskdelta764;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord766({0, 1});
      slog::Relation* readrel767 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel767->getIndex(ord766, false);
      outer_rel = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord768({2, 0, 1});
      slog::Relation* readrel769 = db->getRelation("st_mem0");
      st_mem0index750 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({1, 2, 0});
      slog::Relation* readrel771 = db->getRelation("st_mem0");
      st_mem0index751 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 2, 0});
      slog::Relation* readrel773 = db->getRelation("st_msk");
      st_mskindex752 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 0});
      slog::Relation* readrel775 = db->getRelation("st_msk_ans");
      st_msk_ansindex753 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 3, 4, 0});
      slog::Relation* readrel777 = db->getRelation("pbranch");
      pbranchindex754 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 3, 4, 0});
      slog::Relation* readrel779 = db->getRelation("pbranch");
      pbranchdelta761 = readrel779->getIndex(ord778, true);
      std::vector<u16> ord780({0, 1, 2});
      slog::Relation* readrel781 = db->getRelation("st_mem0");
      st_mem0index755 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({0, 1, 2});
      slog::Relation* readrel783 = db->getRelation("st_mem0");
      st_mem0delta762 = readrel783->getIndex(ord782, true);
      std::vector<u16> ord784({1, 2, 0});
      slog::Relation* readrel785 = db->getRelation("st_mem0");
      st_mem0index756 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("st_mem0");
      st_mem0delta763 = readrel787->getIndex(ord786, true);
      std::vector<u16> ord788({0, 1});
      slog::Relation* readrel789 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex757 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("st_msk");
      st_mskindex758 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("st_msk");
      st_mskdelta764 = readrel793->getIndex(ord792, true);
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("st_msk_ans");
      st_msk_ansindex759 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({0, 1});
      slog::Relation* readrel797 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex760 = readrel797->getIndex(ord796, false);
  
    }
    ReadTask765(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c128 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c24 = _t[5];
        if (!slog::exists_probe<3,2>(st_mem0index750, std::array<u64,3>{v_c20, v_c128, 0})) return;
        if (!slog::exists_probe<3,2>(st_mem0index751, std::array<u64,3>{v_c23, v_c20, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex752, std::array<u64,3>{v_c20, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex753, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex754, pbranchdelta761, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m798) {
          u64 v_c129 = m798[4];
          slog::join_probe_old<3,3>(st_mem0index755, st_mem0delta762, std::array<u64,3>{v_c128, v_c129, v_c20}, [&](const std::array<u64,3>& m799) {
            slog::join_probe_old<3,2>(st_mem0index756, st_mem0delta763, std::array<u64,3>{v_c23, v_c20, 0}, [&](const std::array<u64,3>& m800) {
              u64 v_c130 = m800[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex757, std::array<u64,2>{v_c130, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex758, st_mskdelta764, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m801) {
                u64 v_c131 = m801[2];
                slog::join_probe<2,2>(st_msk_ansindex759, std::array<u64,2>{v_c131, v_c21}, [&](const std::array<u64,2>& m802) {
                  slog::join_probe<2,1>(st_mem0_ansindex760, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m803) {
                    u64 v_c132 = m803[1];
                    u64 v_c133 = _prim_band(db, v_c20, v_c22);
                    if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c134 = _prim_lt(db, v_c133, v_c127);
                    if (v_c134 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c134) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c128, v_c132}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:$sup9688x70x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask765* _cont = new ReadTask765(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask765(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan st_msk __t1x4A82 p n) (body (exists $sup9688x151x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (join st_msk_ans (0 1) 1 __t1x4A82 q) (exists pbranch (1 2 3 4 0) 2 q n) (join $sup9688x151x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __t0F4S77 l m r u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 v) (join pbranch (1 2 3 4 0) 4 q n u v __t3eDW75) (exists st_diff (2 0 1) 2 __t3eDW75 __t0F4S77) (join pbranch (1 2 3 4 0) 4 p m l r __t0L1D80) (join st_diff (0 1 2) 3 __t0F4S77 __t0L1D80 __t3eDW75) (join st_diff (1 2 0) 2 __t0L1D80 v __t8Vvm81) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask819 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x151x0x0x0index805;  slog::Index** pbranchindex806;  slog::Index** pbranchindex807;  slog::Index** st_msk_ansindex808;  slog::Index** pbranchindex809;  slog::Index** $sup9688x151x0x0x0index810;  slog::Index** pbranchindex811;  slog::Index** st_diffindex812;  slog::Index** pbranchindex813;  slog::Index** st_diffindex814;  slog::Index** pbranchindex815;  slog::Index** st_diffindex816;  slog::Index** st_diffindex817;  slog::Index** st_diff_ansindex818;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("st_diff_ans");
      head_index[0] = readrel821->getIndex(ord820, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord822({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel823 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index805 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({2, 0, 1, 3, 4});
      slog::Relation* readrel825 = db->getRelation("pbranch");
      pbranchindex806 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 2, 3, 4, 0});
      slog::Relation* readrel827 = db->getRelation("pbranch");
      pbranchindex807 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("st_msk_ans");
      st_msk_ansindex808 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 2, 3, 4, 0});
      slog::Relation* readrel831 = db->getRelation("pbranch");
      pbranchindex809 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel833 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index810 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 3, 4, 0});
      slog::Relation* readrel835 = db->getRelation("pbranch");
      pbranchindex811 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({2, 0, 1});
      slog::Relation* readrel837 = db->getRelation("st_diff");
      st_diffindex812 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 3, 4, 0});
      slog::Relation* readrel839 = db->getRelation("pbranch");
      pbranchindex813 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({2, 0, 1});
      slog::Relation* readrel841 = db->getRelation("st_diff");
      st_diffindex814 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 3, 4, 0});
      slog::Relation* readrel843 = db->getRelation("pbranch");
      pbranchindex815 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("st_diff");
      st_diffindex816 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("st_diff");
      st_diffindex817 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({0, 1});
      slog::Relation* readrel849 = db->getRelation("st_diff_ans");
      st_diff_ansindex818 = readrel849->getIndex(ord848, false);
  
    }
    ReadTask819(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x151x0x0x0index805, std::array<u64,9>{v_c34, v_c21, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex806, std::array<u64,5>{v_c34, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex807, std::array<u64,5>{v_c21, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex808, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m850) {
          u64 v_c35 = m850[1];
          if (!slog::exists_probe<5,2>(pbranchindex809, std::array<u64,5>{v_c35, v_c34, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x151x0x0x0index810, std::array<u64,9>{v_c34, v_c21, v_c35, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m851) {
            u64 v_c137 = m851[3]; u64 v_c23 = m851[4]; u64 v_c22 = m851[5]; u64 v_c24 = m851[6]; u64 v_c36 = m851[7]; u64 v_c37 = m851[8];
            u64 v_c138 = _prim_lt(db, v_c22, v_c34);
            if (v_c138 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c138) return;
            if (!slog::exists_probe<5,4>(pbranchindex811, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex812, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex813, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m853) {
              u64 v_c139 = m853[4];
              if (!slog::exists_probe<3,2>(st_diffindex814, std::array<u64,3>{v_c139, v_c137, 0})) return;
              slog::join_probe<5,4>(pbranchindex815, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m854) {
                u64 v_c140 = m854[4];
                slog::join_probe<3,3>(st_diffindex816, std::array<u64,3>{v_c137, v_c140, v_c139}, [&](const std::array<u64,3>& m855) {
                  slog::join_probe<3,2>(st_diffindex817, std::array<u64,3>{v_c140, v_c37, 0}, [&](const std::array<u64,3>& m856) {
                    u64 v_c141 = m856[2];
                    slog::join_probe<2,1>(st_diff_ansindex818, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m857) {
                      u64 v_c31 = m857[1];
                      u64 v_c142 = _prim_band(db, v_c21, v_c34);
                      if (v_c142 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c143 = _prim_gt(db, v_c142, v_c135);
                      if (v_c143 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c143) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c137, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask819* _cont = new ReadTask819(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask819(db,b), false);
  // (crule (pre (let __tconst1su1140 const6b86b273ff34fce19d6b804e) (let __tconst23b9137 constd4735e3a265e16eee03f5971)) (scan st_hsb __t3pgB139 x) (body (cmp lt __tconst1su1140 x) (let __t9uxT138 (_0002f x __tconst23b9137))) (head (emit-temp temp76Kg1410 __t9uxT138)) set.slog:29 #f)
  class ReadTask859 : public slog::Task
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
      head_rel[0] = db->getRelation("temp76Kg1410");
      outer_rel = db->getRelation("st_hsb");
  
    }
    ReadTask859(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c144 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c145 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c146 = _t[0];
        u64 v_c147 = _t[1];
        u64 v_c148 = _prim_lt(db, v_c144, v_c147);
        if (v_c148 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
        if (!v_c148) return;
        u64 v_c149 = _prim__0002f(db, v_c147, v_c145);
        if (v_c149 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c149});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask859* _cont = new ReadTask859(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask859(db,b), false);
  // (crule (pre) (scan $sup9688x120x0x0x0 __t3tZ8235 l m n p q r __t7ZZP236 __t8STz237 u v) (body (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t7ZZP236) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8STz237) (exists st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_msk (1 2 0) 2 p n) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t7ZZP236 q __t8STz237 __t1ZYa238) (join-old st_union (0 1 2) 3 (0 1 2) __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_join_ans (0 1) 1 __t1ZYa238) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (neq q __v0) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask876 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex861;  slog::Index** pbranchindex862;  slog::Index** st_unionindex863;  slog::Index** st_mskindex864;  slog::Index** st_joinindex865;  slog::Index** st_unionindex866;  slog::Index** st_join_ansindex867;  slog::Index** st_mskindex868;  slog::Index** st_msk_ansindex869;  slog::Index** st_join_ansindex870;  slog::Index** pbranchdelta871;  slog::Index** pbranchdelta872;  slog::Index** st_joindelta873;  slog::Index** st_uniondelta874;  slog::Index** st_mskdelta875;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord877({0, 1});
      slog::Relation* readrel878 = db->getRelation("st_union_ans");
      head_index[0] = readrel878->getIndex(ord877, false);
      outer_rel = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord879({1, 2, 3, 4, 0});
      slog::Relation* readrel880 = db->getRelation("pbranch");
      pbranchindex861 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 3, 4, 0});
      slog::Relation* readrel882 = db->getRelation("pbranch");
      pbranchdelta871 = readrel882->getIndex(ord881, true);
      std::vector<u16> ord883({1, 2, 3, 4, 0});
      slog::Relation* readrel884 = db->getRelation("pbranch");
      pbranchindex862 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 3, 4, 0});
      slog::Relation* readrel886 = db->getRelation("pbranch");
      pbranchdelta872 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({0, 1, 2});
      slog::Relation* readrel888 = db->getRelation("st_union");
      st_unionindex863 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("st_msk");
      st_mskindex864 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 3, 4, 0});
      slog::Relation* readrel892 = db->getRelation("st_join");
      st_joinindex865 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 2, 3, 4, 0});
      slog::Relation* readrel894 = db->getRelation("st_join");
      st_joindelta873 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({0, 1, 2});
      slog::Relation* readrel896 = db->getRelation("st_union");
      st_unionindex866 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("st_union");
      st_uniondelta874 = readrel898->getIndex(ord897, true);
      std::vector<u16> ord899({0, 1});
      slog::Relation* readrel900 = db->getRelation("st_join_ans");
      st_join_ansindex867 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 2, 0});
      slog::Relation* readrel902 = db->getRelation("st_msk");
      st_mskindex868 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 0});
      slog::Relation* readrel904 = db->getRelation("st_msk");
      st_mskdelta875 = readrel904->getIndex(ord903, true);
      std::vector<u16> ord905({0, 1});
      slog::Relation* readrel906 = db->getRelation("st_msk_ans");
      st_msk_ansindex869 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("st_join_ans");
      st_join_ansindex870 = readrel908->getIndex(ord907, false);
  
    }
    ReadTask876(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c150 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c35 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c151 = _t[7];
        u64 v_c152 = _t[8];
        u64 v_c36 = _t[9];
        u64 v_c37 = _t[10];
        u64 v_c153 = _prim_lt(db, v_c22, v_c34);
        if (v_c153 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
        if (!v_c153) return;
        slog::join_probe_old<5,5>(pbranchindex861, pbranchdelta871, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c151}, [&](const std::array<u64,5>& m910) {
          slog::join_probe_old<5,5>(pbranchindex862, pbranchdelta872, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, v_c152}, [&](const std::array<u64,5>& m911) {
            if (!slog::exists_probe<3,3>(st_unionindex863, std::array<u64,3>{v_c150, v_c151, v_c152})) return;
            if (!slog::exists_probe<3,2>(st_mskindex864, std::array<u64,3>{v_c21, v_c34, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex865, st_joindelta873, std::array<u64,5>{v_c21, v_c151, v_c35, v_c152, 0}, [&](const std::array<u64,5>& m912) {
              u64 v_c154 = m912[4];
              slog::join_probe_old<3,3>(st_unionindex866, st_uniondelta874, std::array<u64,3>{v_c150, v_c151, v_c152}, [&](const std::array<u64,3>& m913) {
                if (!slog::exists_probe<2,1>(st_join_ansindex867, std::array<u64,2>{v_c154, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex868, st_mskdelta875, std::array<u64,3>{v_c21, v_c34, 0}, [&](const std::array<u64,3>& m914) {
                  u64 v_c155 = m914[2];
                  slog::join_probe<2,1>(st_msk_ansindex869, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m915) {
                    u64 v_c4 = m915[1];
                    if (v_c35 == v_c4) return;
                    slog::join_probe<2,1>(st_join_ansindex870, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m916) {
                      u64 v_c31 = m916[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:$sup9688x120x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask876* _cont = new ReadTask876(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask876(db,b), false);
  // (crule (pre) (scan pbranch __t972J134 q n u v) (body (exists st_join (3 4 0 1 2) 2 q __t972J134) (exists st_union (2 0 1) 1 __t972J134) (exists st_msk (1 2 0) 1 q) (join $sup9688x110x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t972J134 u v __t1PdV132 l m p r __t9DTf133) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 p m l r __t9DTf133) (exists st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (exists st_msk (1 2 0) 2 q m) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t9DTf133 q __t972J134 __t744h135) (join st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (exists st_join_ans (0 1) 1 __t744h135) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask932 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex917;  slog::Index** st_unionindex918;  slog::Index** st_mskindex919;  slog::Index** $sup9688x110x0x0x0index920;  slog::Index** pbranchindex921;  slog::Index** st_unionindex922;  slog::Index** st_mskindex923;  slog::Index** st_joinindex924;  slog::Index** st_unionindex925;  slog::Index** st_join_ansindex926;  slog::Index** st_mskindex927;  slog::Index** st_msk_ansindex928;  slog::Index** st_join_ansindex929;  slog::Index** st_joindelta930;  slog::Index** st_mskdelta931;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord933({0, 1});
      slog::Relation* readrel934 = db->getRelation("st_union_ans");
      head_index[0] = readrel934->getIndex(ord933, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord935({3, 4, 0, 1, 2});
      slog::Relation* readrel936 = db->getRelation("st_join");
      st_joinindex917 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({2, 0, 1});
      slog::Relation* readrel938 = db->getRelation("st_union");
      st_unionindex918 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 2, 0});
      slog::Relation* readrel940 = db->getRelation("st_msk");
      st_mskindex919 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel942 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index920 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 3, 4, 0});
      slog::Relation* readrel944 = db->getRelation("pbranch");
      pbranchindex921 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({0, 1, 2});
      slog::Relation* readrel946 = db->getRelation("st_union");
      st_unionindex922 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("st_msk");
      st_mskindex923 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 3, 4, 0});
      slog::Relation* readrel950 = db->getRelation("st_join");
      st_joinindex924 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 2, 3, 4, 0});
      slog::Relation* readrel952 = db->getRelation("st_join");
      st_joindelta930 = readrel952->getIndex(ord951, true);
      std::vector<u16> ord953({0, 1, 2});
      slog::Relation* readrel954 = db->getRelation("st_union");
      st_unionindex925 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({0, 1});
      slog::Relation* readrel956 = db->getRelation("st_join_ans");
      st_join_ansindex926 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("st_msk");
      st_mskindex927 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("st_msk");
      st_mskdelta931 = readrel960->getIndex(ord959, true);
      std::vector<u16> ord961({0, 1});
      slog::Relation* readrel962 = db->getRelation("st_msk_ans");
      st_msk_ansindex928 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({0, 1});
      slog::Relation* readrel964 = db->getRelation("st_join_ans");
      st_join_ansindex929 = readrel964->getIndex(ord963, false);
  
    }
    ReadTask932(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c156 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c37 = _t[4];
        if (!slog::exists_probe<5,2>(st_joinindex917, std::array<u64,5>{v_c35, v_c156, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex918, std::array<u64,3>{v_c156, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex919, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<11,5>($sup9688x110x0x0x0index920, std::array<u64,11>{v_c34, v_c35, v_c156, v_c36, v_c37, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m965) {
          u64 v_c157 = m965[5]; u64 v_c23 = m965[6]; u64 v_c22 = m965[7]; u64 v_c21 = m965[8]; u64 v_c24 = m965[9]; u64 v_c158 = m965[10];
          u64 v_c159 = _prim_lt(db, v_c34, v_c22);
          if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
          if (!v_c159) return;
          slog::join_probe<5,5>(pbranchindex921, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c158}, [&](const std::array<u64,5>& m967) {
            if (!slog::exists_probe<3,3>(st_unionindex922, std::array<u64,3>{v_c157, v_c158, v_c156})) return;
            if (!slog::exists_probe<3,2>(st_mskindex923, std::array<u64,3>{v_c35, v_c22, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex924, st_joindelta930, std::array<u64,5>{v_c21, v_c158, v_c35, v_c156, 0}, [&](const std::array<u64,5>& m968) {
              u64 v_c160 = m968[4];
              slog::join_probe<3,3>(st_unionindex925, std::array<u64,3>{v_c157, v_c158, v_c156}, [&](const std::array<u64,3>& m969) {
                if (!slog::exists_probe<2,1>(st_join_ansindex926, std::array<u64,2>{v_c160, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex927, st_mskdelta931, std::array<u64,3>{v_c35, v_c22, 0}, [&](const std::array<u64,3>& m970) {
                  u64 v_c161 = m970[2];
                  slog::join_probe<2,1>(st_msk_ansindex928, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m971) {
                    u64 v_c4 = m971[1];
                    if (v_c21 == v_c4) return;
                    slog::join_probe<2,1>(st_join_ansindex929, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m972) {
                      u64 v_c31 = m972[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c157, v_c31}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask932* _cont = new ReadTask932(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask932(db,b), false);
  // (crule (pre) (scan st_union_ans __t1gnX289 __v0) (body (join-old st_union (0 1 2) 1 (0 1 2) __t1gnX289 l u) (exists pbranch (3 0 1 2 4) 1 u) (exists pbranch (3 0 1 2 4) 1 l) (join-old $sup9688x100x0x0x0 (1 5 0 2 3 4 6) 2 (1 5 0 2 3 4 6) l u __t2Q3U288 m p r v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t22FG286) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1pUK287) (join-old st_union (0 1 2) 3 (0 1 2) __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (join-old st_union_ans (0 1) 1 (0 1) __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask992 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex973;  slog::Index** pbranchindex974;  slog::Index** pbranchindex975;  slog::Index** $sup9688x100x0x0x0index976;  slog::Index** pbranchindex977;  slog::Index** st_unionindex978;  slog::Index** pbranchindex979;  slog::Index** st_unionindex980;  slog::Index** pbranchindex981;  slog::Index** st_unionindex982;  slog::Index** st_unionindex983;  slog::Index** st_union_ansindex984;  slog::Index** st_uniondelta985;  slog::Index** $sup9688x100x0x0x0delta986;  slog::Index** pbranchdelta987;  slog::Index** pbranchdelta988;  slog::Index** st_uniondelta989;  slog::Index** st_uniondelta990;  slog::Index** st_union_ansdelta991;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord993({0, 1, 2});
      slog::Relation* readrel994 = db->getRelation("st_union");
      st_unionindex973 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({0, 1, 2});
      slog::Relation* readrel996 = db->getRelation("st_union");
      st_uniondelta985 = readrel996->getIndex(ord995, true);
      std::vector<u16> ord997({3, 0, 1, 2, 4});
      slog::Relation* readrel998 = db->getRelation("pbranch");
      pbranchindex974 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({3, 0, 1, 2, 4});
      slog::Relation* readrel1000 = db->getRelation("pbranch");
      pbranchindex975 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1002 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index976 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1004 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0delta986 = readrel1004->getIndex(ord1003, true);
      std::vector<u16> ord1005({1, 2, 3, 4, 0});
      slog::Relation* readrel1006 = db->getRelation("pbranch");
      pbranchindex977 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("st_union");
      st_unionindex978 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 3, 4, 0});
      slog::Relation* readrel1010 = db->getRelation("pbranch");
      pbranchindex979 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 3, 4, 0});
      slog::Relation* readrel1012 = db->getRelation("pbranch");
      pbranchdelta987 = readrel1012->getIndex(ord1011, true);
      std::vector<u16> ord1013({2, 0, 1});
      slog::Relation* readrel1014 = db->getRelation("st_union");
      st_unionindex980 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 2, 3, 4, 0});
      slog::Relation* readrel1016 = db->getRelation("pbranch");
      pbranchindex981 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 2, 3, 4, 0});
      slog::Relation* readrel1018 = db->getRelation("pbranch");
      pbranchdelta988 = readrel1018->getIndex(ord1017, true);
      std::vector<u16> ord1019({0, 1, 2});
      slog::Relation* readrel1020 = db->getRelation("st_union");
      st_unionindex982 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({0, 1, 2});
      slog::Relation* readrel1022 = db->getRelation("st_union");
      st_uniondelta989 = readrel1022->getIndex(ord1021, true);
      std::vector<u16> ord1023({1, 2, 0});
      slog::Relation* readrel1024 = db->getRelation("st_union");
      st_unionindex983 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 0});
      slog::Relation* readrel1026 = db->getRelation("st_union");
      st_uniondelta990 = readrel1026->getIndex(ord1025, true);
      std::vector<u16> ord1027({0, 1});
      slog::Relation* readrel1028 = db->getRelation("st_union_ans");
      st_union_ansindex984 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({0, 1});
      slog::Relation* readrel1030 = db->getRelation("st_union_ans");
      st_union_ansdelta991 = readrel1030->getIndex(ord1029, true);
  
    }
    ReadTask992(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c162 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex973, st_uniondelta985, std::array<u64,3>{v_c162, 0, 0}, [&](const std::array<u64,3>& m1031) {
          u64 v_c23 = m1031[1]; u64 v_c36 = m1031[2];
          if (!slog::exists_probe<5,1>(pbranchindex974, std::array<u64,5>{v_c36, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex975, std::array<u64,5>{v_c23, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup9688x100x0x0x0index976, $sup9688x100x0x0x0delta986, std::array<u64,7>{v_c23, v_c36, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1032) {
            u64 v_c163 = m1032[2]; u64 v_c22 = m1032[3]; u64 v_c21 = m1032[4]; u64 v_c24 = m1032[5]; u64 v_c37 = m1032[6];
            if (!slog::exists_probe<5,4>(pbranchindex977, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<3,2>(st_unionindex978, std::array<u64,3>{v_c24, v_c37, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex979, pbranchdelta987, std::array<u64,5>{v_c21, v_c22, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m1033) {
              u64 v_c164 = m1033[4];
              if (!slog::exists_probe<3,2>(st_unionindex980, std::array<u64,3>{v_c164, v_c163, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex981, pbranchdelta988, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m1034) {
                u64 v_c165 = m1034[4];
                slog::join_probe_old<3,3>(st_unionindex982, st_uniondelta989, std::array<u64,3>{v_c163, v_c165, v_c164}, [&](const std::array<u64,3>& m1035) {
                  slog::join_probe_old<3,2>(st_unionindex983, st_uniondelta990, std::array<u64,3>{v_c24, v_c37, 0}, [&](const std::array<u64,3>& m1036) {
                    u64 v_c166 = m1036[2];
                    slog::join_probe_old<2,1>(st_union_ansindex984, st_union_ansdelta991, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1037) {
                      u64 v_c2 = m1037[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c163, v_c4, v_c2, v_c22, v_c21});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c22, v_c4, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask992* _cont = new ReadTask992(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask992(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan $sup9688x36x0x0x1 __t0kmv352 __t75bg356 __v0 p0 p1 t0 t1) (body (exists $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (exists st_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t0kmv352) (exists st_hsb_ans (0 1) 1 __t75bg356) (exists st_hsb_ans (0 1) 2 __t75bg356 __v0) (exists st_msk (1 2 0) 1 p0) (join $sup9688x36x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0 dup66Lo1333 dup68E21334 __v1 __v3) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join-old $sup9688x36x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join-old st_msk_ans (0 1) 1 (0 1) __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask1060 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x36x0x0x0index1038;  slog::Index** st_joinindex1039;  slog::Index** st_hsb_ansindex1040;  slog::Index** st_hsb_ansindex1041;  slog::Index** st_mskindex1042;  slog::Index** $sup9688x36x0x0x2index1043;  slog::Index** $sup9688x36x0x0x0index1044;  slog::Index** st_joinindex1045;  slog::Index** st_hsb_ansindex1046;  slog::Index** st_hsb_ansindex1047;  slog::Index** st_hsb_ansindex1048;  slog::Index** st_mskindex1049;  slog::Index** st_msk_ansindex1050;  slog::Index** st_hsbindex1051;  slog::Index** $sup9688x36x0x0x0delta1052;  slog::Index** st_joindelta1053;  slog::Index** st_hsb_ansdelta1054;  slog::Index** st_hsb_ansdelta1055;  slog::Index** st_hsb_ansdelta1056;  slog::Index** st_mskdelta1057;  slog::Index** st_msk_ansdelta1058;  slog::Index** st_hsbdelta1059;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord1061({1, 0, 2, 3, 4});
      slog::Relation* readrel1062 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index1038 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 2, 3, 4, 0});
      slog::Relation* readrel1064 = db->getRelation("st_join");
      st_joinindex1039 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({0, 1});
      slog::Relation* readrel1066 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1040 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({0, 1});
      slog::Relation* readrel1068 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1041 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 2, 0});
      slog::Relation* readrel1070 = db->getRelation("st_msk");
      st_mskindex1042 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1072 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1043 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 0, 2, 3, 4});
      slog::Relation* readrel1074 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index1044 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({1, 0, 2, 3, 4});
      slog::Relation* readrel1076 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0delta1052 = readrel1076->getIndex(ord1075, true);
      std::vector<u16> ord1077({1, 2, 3, 4, 0});
      slog::Relation* readrel1078 = db->getRelation("st_join");
      st_joinindex1045 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 2, 3, 4, 0});
      slog::Relation* readrel1080 = db->getRelation("st_join");
      st_joindelta1053 = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({0, 1});
      slog::Relation* readrel1082 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1046 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({0, 1});
      slog::Relation* readrel1084 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1054 = readrel1084->getIndex(ord1083, true);
      std::vector<u16> ord1085({0, 1});
      slog::Relation* readrel1086 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1047 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({0, 1});
      slog::Relation* readrel1088 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1055 = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({0, 1});
      slog::Relation* readrel1090 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1048 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1});
      slog::Relation* readrel1092 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1056 = readrel1092->getIndex(ord1091, true);
      std::vector<u16> ord1093({1, 2, 0});
      slog::Relation* readrel1094 = db->getRelation("st_msk");
      st_mskindex1049 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("st_msk");
      st_mskdelta1057 = readrel1096->getIndex(ord1095, true);
      std::vector<u16> ord1097({0, 1});
      slog::Relation* readrel1098 = db->getRelation("st_msk_ans");
      st_msk_ansindex1050 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1058 = readrel1100->getIndex(ord1099, true);
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("st_hsb");
      st_hsbindex1051 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({0, 1});
      slog::Relation* readrel1104 = db->getRelation("st_hsb");
      st_hsbdelta1059 = readrel1104->getIndex(ord1103, true);
  
    }
    ReadTask1060(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c11 = _t[6];
        if (!slog::exists_probe<5,5>($sup9688x36x0x0x0index1038, std::array<u64,5>{v_c8, v_c5, v_c9, v_c10, v_c11})) return;
        if (!slog::exists_probe<5,5>(st_joinindex1039, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c5})) return;
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1040, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,2>(st_hsb_ansindex1041, std::array<u64,2>{v_c1, v_c4})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1042, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<11,7>($sup9688x36x0x0x2index1043, std::array<u64,11>{v_c5, v_c8, v_c9, v_c10, v_c11, v_c1, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1105) {
          u64 v_c6 = m1105[7]; u64 v_c7 = m1105[8]; u64 v_c2 = m1105[9]; u64 v_c3 = m1105[10];
          if (v_c1 != v_c7) return;
          if (v_c1 != v_c6) return;
          slog::join_probe_old<5,5>($sup9688x36x0x0x0index1044, $sup9688x36x0x0x0delta1052, std::array<u64,5>{v_c8, v_c5, v_c9, v_c10, v_c11}, [&](const std::array<u64,5>& m1106) {
            slog::join_probe_old<5,5>(st_joinindex1045, st_joindelta1053, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c5}, [&](const std::array<u64,5>& m1107) {
              slog::join_probe_old<2,2>(st_hsb_ansindex1046, st_hsb_ansdelta1054, std::array<u64,2>{v_c1, v_c3}, [&](const std::array<u64,2>& m1108) {
                slog::join_probe_old<2,2>(st_hsb_ansindex1047, st_hsb_ansdelta1055, std::array<u64,2>{v_c1, v_c2}, [&](const std::array<u64,2>& m1109) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex1048, st_hsb_ansdelta1056, std::array<u64,2>{v_c1, v_c4}, [&](const std::array<u64,2>& m1110) {
                    slog::join_probe_old<3,2>(st_mskindex1049, st_mskdelta1057, std::array<u64,3>{v_c8, v_c2, 0}, [&](const std::array<u64,3>& m1111) {
                      u64 v_c12 = m1111[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex1050, st_msk_ansdelta1058, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m1112) {
                        u64 v_c13 = m1112[1];
                        u64 v_c14 = _prim_bxor(db, v_c8, v_c9);
                        if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex1051, st_hsbdelta1059, std::array<u64,2>{v_c1, v_c14}, [&](const std::array<u64,2>& m1113) {
                          u64 v_c15 = _prim_band(db, v_c8, v_c4);
                          if (v_c15 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c167 = _prim_lt(db, v_c15, v_c0);
                          if (v_c167 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c167) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c13, v_c3, v_c10, v_c11});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c3, v_c10, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1060* _cont = new ReadTask1060(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1060(db,b), false);
  // (crule (pre) (scan st_diff __t6McK194 __t1ano193 t) (body (join pleaf (0 1) 1 __t1ano193 k)) (head (mkstruct st_mem0 (1 2 0) __2xP61117 t k)) set.slog:135 #f)
  class ReadTask1116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1117({0, 1});
      slog::Relation* readrel1118 = db->getRelation("pleaf");
      pleafindex1115 = readrel1118->getIndex(ord1117, false);
  
    }
    ReadTask1116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c168 = _t[0];
        u64 v_c169 = _t[1];
        u64 v_c170 = _t[2];
        slog::join_probe<2,1>(pleafindex1115, std::array<u64,2>{v_c169, 0}, [&](const std::array<u64,2>& m1119) {
          u64 v_c20 = m1119[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c170, v_c20}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1116* _cont = new ReadTask1116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1116(db,b), false);
  // (crule (pre (let __tconst0XIw307 const5feceb66ffc86f38d952786c)) (scan st_union __t8fFv306 __t4jxi305 __t3Mhw304) (body (join pbranch (0 1 2 3 4) 1 __t3Mhw304 q n u v) (join pbranch (0 1 2 3 4) 1 __t4jxi305 p m l r) (cmp lt n m) (let __t3ur5308 (band q m)) (cmp gt __t3ur5308 __tconst0XIw307)) (head (emit $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) __t8fFv306 r l m n p q u v)) set.slog:107 #f)
  class ReadTask1122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1120;  slog::Index** pbranchindex1121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord1123({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1124 = db->getRelation("$sup9688x106x0x0x0");
      head_index[0] = readrel1124->getIndex(ord1123, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord1125({0, 1, 2, 3, 4});
      slog::Relation* readrel1126 = db->getRelation("pbranch");
      pbranchindex1120 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({0, 1, 2, 3, 4});
      slog::Relation* readrel1128 = db->getRelation("pbranch");
      pbranchindex1121 = readrel1128->getIndex(ord1127, false);
  
    }
    ReadTask1122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c171 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c172 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c174 = _t[2];
        slog::join_probe<5,1>(pbranchindex1120, std::array<u64,5>{v_c174, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1129) {
          u64 v_c35 = m1129[1]; u64 v_c34 = m1129[2]; u64 v_c36 = m1129[3]; u64 v_c37 = m1129[4];
          slog::join_probe<5,1>(pbranchindex1121, std::array<u64,5>{v_c173, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1130) {
            u64 v_c21 = m1130[1]; u64 v_c22 = m1130[2]; u64 v_c23 = m1130[3]; u64 v_c24 = m1130[4];
            u64 v_c175 = _prim_lt(db, v_c34, v_c22);
            if (v_c175 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c175) return;
            u64 v_c176 = _prim_band(db, v_c35, v_c22);
            if (v_c176 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            u64 v_c177 = _prim_gt(db, v_c176, v_c171);
            if (v_c177 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c177) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c172, v_c24, v_c23, v_c22, v_c34, v_c21, v_c35, v_c36, v_c37}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask1122* _cont = new ReadTask1122(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1122(db,b), false);
  // (crule (pre) (scan st_msk __t1TTr141 p n) (body (exists $sup9688x114x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join st_msk_ans (0 1) 1 __t1TTr141 q) (join $sup9688x114x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t1TTr141 l m n p q r v)) set.slog:115 #f)
  class ReadTask1136 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x0index1133;  slog::Index** st_msk_ansindex1134;  slog::Index** $sup9688x114x0x0x0index1135;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord1137({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel1138 = db->getRelation("$sup9688x114x0x0x1");
      head_index[0] = readrel1138->getIndex(ord1137, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1139({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1140 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1133 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({0, 1});
      slog::Relation* readrel1142 = db->getRelation("st_msk_ans");
      st_msk_ansindex1134 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1144 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1135 = readrel1144->getIndex(ord1143, false);
  
    }
    ReadTask1136(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c178 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x114x0x0x0index1133, std::array<u64,9>{v_c34, v_c21, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1134, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m1145) {
          u64 v_c35 = m1145[1];
          slog::join_probe<9,3>($sup9688x114x0x0x0index1135, std::array<u64,9>{v_c34, v_c21, v_c35, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1146) {
            u64 v_c28 = m1146[3]; u64 v_c23 = m1146[4]; u64 v_c22 = m1146[5]; u64 v_c24 = m1146[6]; u64 v_c36 = m1146[7]; u64 v_c37 = m1146[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c28, v_c36, v_c178, v_c23, v_c22, v_c34, v_c21, v_c35, v_c24, v_c37}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1136* _cont = new ReadTask1136(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1136(db,b), false);
  // (crule (pre (let __tconst6u6w168 constd4735e3a265e16eee03f5971) (let __trid3Iw3761 const5e6127cdd5ea2629462053c9) (let __trel3BQx762 const1d9eff40314d54862fee3942) (let __tcol9eoL763 const5feceb66ffc86f38d952786c)) (scan $sup97714x23x0x0x1 __d0 __v0 s) (body (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst6u6w168 __t70EZ169) (join-old st_ins_ans (0 1) 1 (0 1) __t70EZ169 o)) (head (tycheck s (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid3Iw3761 __trel3BQx762 __tcol9eoL763 (1 2 3 4 0)) (mkstruct st_diff (1 2 0) __1G6J760 s o)) st_basic.slog:24 #f)
  class ReadTask1154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1147;  slog::Index** st_ins_ansindex1148;  slog::Index** st_insdelta1149;  slog::Index** st_ins_ansdelta1150;
    u32 sid1152;  u32 sid1151;  u32 sid1153;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_diff");
      outer_rel = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord1155({1, 2, 0});
      slog::Relation* readrel1156 = db->getRelation("st_ins");
      st_insindex1147 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 2, 0});
      slog::Relation* readrel1158 = db->getRelation("st_ins");
      st_insdelta1149 = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({0, 1});
      slog::Relation* readrel1160 = db->getRelation("st_ins_ans");
      st_ins_ansindex1148 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({0, 1});
      slog::Relation* readrel1162 = db->getRelation("st_ins_ans");
      st_ins_ansdelta1150 = readrel1162->getIndex(ord1161, true);
      sid1152 = db->getRelation("_enum")->getStructId();
      sid1151 = db->getRelation("pbranch")->getStructId();
      sid1153 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c179 = v_constd4735e3a265e16eee03f5971;
      u64 v_c180 = v_const5e6127cdd5ea2629462053c9;
      u64 v_c181 = v_const1d9eff40314d54862fee3942;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c183 = _t[2];
        slog::join_probe_old<3,2>(st_insindex1147, st_insdelta1149, std::array<u64,3>{v_c4, v_c179, 0}, [&](const std::array<u64,3>& m1163) {
          u64 v_c184 = m1163[2];
          slog::join_probe_old<2,1>(st_ins_ansindex1148, st_ins_ansdelta1150, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m1164) {
            u64 v_c185 = m1164[1];
            ++_fires;
            if (!((is_struct(v_c183) && (decode_struct_id(v_c183) == sid1151 || decode_struct_id(v_c183) == sid1152 || decode_struct_id(v_c183) == sid1153))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c180, v_c181, v_c182, v_c183}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c183, v_c185}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:$sup97714x23x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1154* _cont = new ReadTask1154(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1154(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_msk __t8DQ7163 q m) (body (exists $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (2 0 1 3 4) 1 m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_bld (2 1 4 0 3) 1 m) (join st_msk_ans (0 1) 1 __t8DQ7163 p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __t3X8M159 l n r u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_diff (1 2 0) 1 l) (join pbranch (1 2 3 4 0) 4 p m l r __t66RN158) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join st_diff (0 1 2) 3 __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join st_bld (2 1 4 0 3) 3 m p r __t1RXD162 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask1189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index1165;  slog::Index** pbranchindex1166;  slog::Index** pbranchindex1167;  slog::Index** st_bldindex1168;  slog::Index** st_msk_ansindex1169;  slog::Index** pbranchindex1170;  slog::Index** st_bldindex1171;  slog::Index** $sup9688x139x0x0x0index1172;  slog::Index** pbranchindex1173;  slog::Index** st_bldindex1174;  slog::Index** st_diffindex1175;  slog::Index** pbranchindex1176;  slog::Index** st_diffindex1177;  slog::Index** pbranchindex1178;  slog::Index** st_diffindex1179;  slog::Index** st_diffindex1180;  slog::Index** st_bldindex1181;  slog::Index** st_diff_ansindex1182;  slog::Index** st_bld_ansindex1183;  slog::Index** st_diffindex1184;  slog::Index** st_diff_ansindex1185;  slog::Index** st_bld_ansindex1186;  slog::Index** pbranchdelta1187;  slog::Index** st_diffdelta1188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1190({0, 1});
      slog::Relation* readrel1191 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1191->getIndex(ord1190, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1192({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1193 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1165 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({2, 0, 1, 3, 4});
      slog::Relation* readrel1195 = db->getRelation("pbranch");
      pbranchindex1166 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 2, 3, 4, 0});
      slog::Relation* readrel1197 = db->getRelation("pbranch");
      pbranchindex1167 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({2, 1, 4, 0, 3});
      slog::Relation* readrel1199 = db->getRelation("st_bld");
      st_bldindex1168 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({0, 1});
      slog::Relation* readrel1201 = db->getRelation("st_msk_ans");
      st_msk_ansindex1169 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 2, 3, 4, 0});
      slog::Relation* readrel1203 = db->getRelation("pbranch");
      pbranchindex1170 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 2, 3, 4, 0});
      slog::Relation* readrel1205 = db->getRelation("st_bld");
      st_bldindex1171 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1207 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1172 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 2, 3, 4, 0});
      slog::Relation* readrel1209 = db->getRelation("pbranch");
      pbranchindex1173 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({2, 1, 4, 0, 3});
      slog::Relation* readrel1211 = db->getRelation("st_bld");
      st_bldindex1174 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0});
      slog::Relation* readrel1213 = db->getRelation("st_diff");
      st_diffindex1175 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 2, 3, 4, 0});
      slog::Relation* readrel1215 = db->getRelation("pbranch");
      pbranchindex1176 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1, 2});
      slog::Relation* readrel1217 = db->getRelation("st_diff");
      st_diffindex1177 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 2, 3, 4, 0});
      slog::Relation* readrel1219 = db->getRelation("pbranch");
      pbranchindex1178 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 2, 3, 4, 0});
      slog::Relation* readrel1221 = db->getRelation("pbranch");
      pbranchdelta1187 = readrel1221->getIndex(ord1220, true);
      std::vector<u16> ord1222({0, 1, 2});
      slog::Relation* readrel1223 = db->getRelation("st_diff");
      st_diffindex1179 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 2, 0});
      slog::Relation* readrel1225 = db->getRelation("st_diff");
      st_diffindex1180 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({2, 1, 4, 0, 3});
      slog::Relation* readrel1227 = db->getRelation("st_bld");
      st_bldindex1181 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 0});
      slog::Relation* readrel1229 = db->getRelation("st_diff_ans");
      st_diff_ansindex1182 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 1});
      slog::Relation* readrel1231 = db->getRelation("st_bld_ans");
      st_bld_ansindex1183 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 2, 0});
      slog::Relation* readrel1233 = db->getRelation("st_diff");
      st_diffindex1184 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({1, 2, 0});
      slog::Relation* readrel1235 = db->getRelation("st_diff");
      st_diffdelta1188 = readrel1235->getIndex(ord1234, true);
      std::vector<u16> ord1236({0, 1});
      slog::Relation* readrel1237 = db->getRelation("st_diff_ans");
      st_diff_ansindex1185 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({0, 1});
      slog::Relation* readrel1239 = db->getRelation("st_bld_ans");
      st_bld_ansindex1186 = readrel1239->getIndex(ord1238, false);
  
    }
    ReadTask1189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x139x0x0x0index1165, std::array<u64,9>{v_c22, v_c35, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1166, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1167, std::array<u64,5>{v_c35, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex1168, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1169, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m1240) {
          u64 v_c21 = m1240[1];
          if (!slog::exists_probe<5,2>(pbranchindex1170, std::array<u64,5>{v_c21, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex1171, std::array<u64,5>{v_c21, v_c22, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x139x0x0x0index1172, std::array<u64,9>{v_c22, v_c35, v_c21, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1241) {
            u64 v_c33 = m1241[3]; u64 v_c23 = m1241[4]; u64 v_c34 = m1241[5]; u64 v_c24 = m1241[6]; u64 v_c36 = m1241[7]; u64 v_c37 = m1241[8];
            u64 v_c186 = _prim_lt(db, v_c34, v_c22);
            if (v_c186 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c186) return;
            if (!slog::exists_probe<5,4>(pbranchindex1173, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex1174, std::array<u64,5>{v_c22, v_c21, v_c24, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex1175, std::array<u64,3>{v_c23, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex1176, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m1243) {
              u64 v_c32 = m1243[4];
              if (!slog::exists_probe<3,2>(st_diffindex1177, std::array<u64,3>{v_c33, v_c32, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1178, pbranchdelta1187, std::array<u64,5>{v_c35, v_c34, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m1244) {
                u64 v_c39 = m1244[4];
                slog::join_probe<3,3>(st_diffindex1179, std::array<u64,3>{v_c33, v_c32, v_c39}, [&](const std::array<u64,3>& m1245) {
                  if (!slog::exists_probe<3,2>(st_diffindex1180, std::array<u64,3>{v_c23, v_c39, 0})) return;
                  slog::join_probe<5,3>(st_bldindex1181, std::array<u64,5>{v_c22, v_c21, v_c24, 0, 0}, [&](const std::array<u64,5>& m1246) {
                    u64 v_c30 = m1246[3]; u64 v_c4 = m1246[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex1182, std::array<u64,2>{v_c4, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1183, std::array<u64,2>{v_c30, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex1184, st_diffdelta1188, std::array<u64,3>{v_c23, v_c39, 0}, [&](const std::array<u64,3>& m1247) {
                      u64 v_c41 = m1247[2];
                      slog::join_probe<2,2>(st_diff_ansindex1185, std::array<u64,2>{v_c41, v_c4}, [&](const std::array<u64,2>& m1248) {
                        slog::join_probe<2,1>(st_bld_ansindex1186, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1249) {
                          u64 v_c31 = m1249[1];
                          u64 v_c42 = _prim_band(db, v_c35, v_c22);
                          if (v_c42 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c187 = _prim_lt(db, v_c42, v_c29);
                          if (v_c187 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c187) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1189* _cont = new ReadTask1189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1189(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_hsb_ans __t2flT468 __v3) (body (exists st_hsb_ans (0 1) 1 __t2flT468) (exists $sup9688x40x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t2flT468 __v3) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 1 __t2flT468) (join-old st_hsb_ans (0 1) 1 (0 1) __t2flT468 __v1) (exists $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2flT468 __v1 __v3) (exists st_msk (2 0 1) 1 __v1) (join-old st_hsb_ans (0 1) 1 (0 1) __t2flT468 __v0) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 2 __t2flT468 __v0) (join $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2flT468 __v0 __v3 __v1 __t4PzE464 dup2gd61405 dup5ZAM1406 p0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join-old st_msk_ans (0 1) 1 (0 1) __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask1272 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1251;  slog::Index** $sup9688x40x0x0x2index1252;  slog::Index** $sup9688x40x0x0x1index1253;  slog::Index** st_hsb_ansindex1254;  slog::Index** $sup9688x40x0x0x2index1255;  slog::Index** st_mskindex1256;  slog::Index** st_hsb_ansindex1257;  slog::Index** $sup9688x40x0x0x1index1258;  slog::Index** $sup9688x40x0x0x2index1259;  slog::Index** $sup9688x40x0x0x1index1260;  slog::Index** $sup9688x40x0x0x0index1261;  slog::Index** st_joinindex1262;  slog::Index** st_mskindex1263;  slog::Index** st_msk_ansindex1264;  slog::Index** st_hsbindex1265;  slog::Index** st_hsb_ansdelta1266;  slog::Index** st_hsb_ansdelta1267;  slog::Index** st_joindelta1268;  slog::Index** st_mskdelta1269;  slog::Index** st_msk_ansdelta1270;  slog::Index** st_hsbdelta1271;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1273({0, 1});
      slog::Relation* readrel1274 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1251 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel1276 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1252 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1278 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1253 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({0, 1});
      slog::Relation* readrel1280 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1254 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({0, 1});
      slog::Relation* readrel1282 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1266 = readrel1282->getIndex(ord1281, true);
      std::vector<u16> ord1283({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1284 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1255 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({2, 0, 1});
      slog::Relation* readrel1286 = db->getRelation("st_msk");
      st_mskindex1256 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({0, 1});
      slog::Relation* readrel1288 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1257 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({0, 1});
      slog::Relation* readrel1290 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1267 = readrel1290->getIndex(ord1289, true);
      std::vector<u16> ord1291({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1292 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1258 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1294 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1259 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1296 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1260 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({1, 0, 2, 3, 4});
      slog::Relation* readrel1298 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index1261 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 2, 3, 4, 0});
      slog::Relation* readrel1300 = db->getRelation("st_join");
      st_joinindex1262 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({1, 2, 3, 4, 0});
      slog::Relation* readrel1302 = db->getRelation("st_join");
      st_joindelta1268 = readrel1302->getIndex(ord1301, true);
      std::vector<u16> ord1303({1, 2, 0});
      slog::Relation* readrel1304 = db->getRelation("st_msk");
      st_mskindex1263 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({1, 2, 0});
      slog::Relation* readrel1306 = db->getRelation("st_msk");
      st_mskdelta1269 = readrel1306->getIndex(ord1305, true);
      std::vector<u16> ord1307({0, 1});
      slog::Relation* readrel1308 = db->getRelation("st_msk_ans");
      st_msk_ansindex1264 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1270 = readrel1310->getIndex(ord1309, true);
      std::vector<u16> ord1311({0, 1});
      slog::Relation* readrel1312 = db->getRelation("st_hsb");
      st_hsbindex1265 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({0, 1});
      slog::Relation* readrel1314 = db->getRelation("st_hsb");
      st_hsbdelta1271 = readrel1314->getIndex(ord1313, true);
  
    }
    ReadTask1272(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c188 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c189 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1251, std::array<u64,2>{v_c189, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index1252, std::array<u64,11>{v_c189, v_c3, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x40x0x0x1index1253, std::array<u64,7>{v_c189, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(st_hsb_ansindex1254, st_hsb_ansdelta1266, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1315) {
          u64 v_c2 = m1315[1];
          if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index1255, std::array<u64,11>{v_c189, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1256, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex1257, st_hsb_ansdelta1267, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1316) {
            u64 v_c4 = m1316[1];
            if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index1258, std::array<u64,7>{v_c189, v_c4, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x40x0x0x2index1259, std::array<u64,11>{v_c189, v_c4, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1317) {
              u64 v_c190 = m1317[4]; u64 v_c191 = m1317[5]; u64 v_c192 = m1317[6]; u64 v_c8 = m1317[7]; u64 v_c9 = m1317[8]; u64 v_c10 = m1317[9]; u64 v_c11 = m1317[10];
              if (v_c189 != v_c192) return;
              if (v_c189 != v_c191) return;
              slog::join_probe<7,7>($sup9688x40x0x0x1index1260, std::array<u64,7>{v_c190, v_c8, v_c9, v_c10, v_c11, v_c189, v_c4}, [&](const std::array<u64,7>& m1318) {
                slog::join_probe<5,5>($sup9688x40x0x0x0index1261, std::array<u64,5>{v_c8, v_c190, v_c9, v_c10, v_c11}, [&](const std::array<u64,5>& m1319) {
                  slog::join_probe_old<5,5>(st_joinindex1262, st_joindelta1268, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c190}, [&](const std::array<u64,5>& m1320) {
                    slog::join_probe_old<3,2>(st_mskindex1263, st_mskdelta1269, std::array<u64,3>{v_c8, v_c2, 0}, [&](const std::array<u64,3>& m1321) {
                      u64 v_c193 = m1321[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex1264, st_msk_ansdelta1270, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m1322) {
                        u64 v_c13 = m1322[1];
                        u64 v_c194 = _prim_bxor(db, v_c8, v_c9);
                        if (v_c194 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex1265, st_hsbdelta1271, std::array<u64,2>{v_c189, v_c194}, [&](const std::array<u64,2>& m1323) {
                          u64 v_c195 = _prim_band(db, v_c8, v_c4);
                          if (v_c195 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c196 = _prim_gt(db, v_c195, v_c188);
                          if (v_c196 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c196) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c190, v_c13, v_c3, v_c10, v_c11});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c3, v_c11, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1272* _cont = new ReadTask1272(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1272(db,b), false);
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (scan st_ins_ans __t3icK299 __v0) (body (exists _enum (1 0) 1 __tconst80a51002) (exists st_ins (1 2 0) 2 __v0 __tconst9HiA300) (exists st_ins (2 0 1) 1 __tconst4xiW302) (join-old st_ins (0 2 1) 2 (0 2 1) __t3icK299 __tconst87Bp297 __t1S8l298) (join _enum (0 1) 2 __t1S8l298 __tconst80a51002) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst9HiA300 __t8YZs301) (join-old st_ins_ans (0 1) 1 (0 1) __t8YZs301 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4xiW302 __t43hI303) (join-old st_ins_ans (0 1) 1 (0 1) __t43hI303 __v2)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask1339 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1325;  slog::Index** st_insindex1326;  slog::Index** st_insindex1327;  slog::Index** st_insindex1328;  slog::Index** _enumindex1329;  slog::Index** st_insindex1330;  slog::Index** st_ins_ansindex1331;  slog::Index** st_insindex1332;  slog::Index** st_ins_ansindex1333;  slog::Index** st_insdelta1334;  slog::Index** st_insdelta1335;  slog::Index** st_ins_ansdelta1336;  slog::Index** st_insdelta1337;  slog::Index** st_ins_ansdelta1338;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1340({1, 0});
      slog::Relation* readrel1341 = db->getRelation("_enum");
      _enumindex1325 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({1, 2, 0});
      slog::Relation* readrel1343 = db->getRelation("st_ins");
      st_insindex1326 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({2, 0, 1});
      slog::Relation* readrel1345 = db->getRelation("st_ins");
      st_insindex1327 = readrel1345->getIndex(ord1344, false);
      std::vector<u16> ord1346({0, 2, 1});
      slog::Relation* readrel1347 = db->getRelation("st_ins");
      st_insindex1328 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({0, 2, 1});
      slog::Relation* readrel1349 = db->getRelation("st_ins");
      st_insdelta1334 = readrel1349->getIndex(ord1348, true);
      std::vector<u16> ord1350({0, 1});
      slog::Relation* readrel1351 = db->getRelation("_enum");
      _enumindex1329 = readrel1351->getIndex(ord1350, false);
      std::vector<u16> ord1352({1, 2, 0});
      slog::Relation* readrel1353 = db->getRelation("st_ins");
      st_insindex1330 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 2, 0});
      slog::Relation* readrel1355 = db->getRelation("st_ins");
      st_insdelta1335 = readrel1355->getIndex(ord1354, true);
      std::vector<u16> ord1356({0, 1});
      slog::Relation* readrel1357 = db->getRelation("st_ins_ans");
      st_ins_ansindex1331 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({0, 1});
      slog::Relation* readrel1359 = db->getRelation("st_ins_ans");
      st_ins_ansdelta1336 = readrel1359->getIndex(ord1358, true);
      std::vector<u16> ord1360({1, 2, 0});
      slog::Relation* readrel1361 = db->getRelation("st_ins");
      st_insindex1332 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({1, 2, 0});
      slog::Relation* readrel1363 = db->getRelation("st_ins");
      st_insdelta1337 = readrel1363->getIndex(ord1362, true);
      std::vector<u16> ord1364({0, 1});
      slog::Relation* readrel1365 = db->getRelation("st_ins_ans");
      st_ins_ansindex1333 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({0, 1});
      slog::Relation* readrel1367 = db->getRelation("st_ins_ans");
      st_ins_ansdelta1338 = readrel1367->getIndex(ord1366, true);
  
    }
    ReadTask1339(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c197 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const2c624232cdd221771294dfbb;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c202 = _t[0];
        u64 v_c4 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex1325, std::array<u64,2>{v_c197, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex1326, std::array<u64,3>{v_c4, v_c199, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1327, std::array<u64,3>{v_c200, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex1328, st_insdelta1334, std::array<u64,3>{v_c202, v_c198, 0}, [&](const std::array<u64,3>& m1368) {
          u64 v_c203 = m1368[2];
          slog::join_probe<2,2>(_enumindex1329, std::array<u64,2>{v_c203, v_c197}, [&](const std::array<u64,2>& m1369) {
            slog::join_probe_old<3,2>(st_insindex1330, st_insdelta1335, std::array<u64,3>{v_c4, v_c199, 0}, [&](const std::array<u64,3>& m1370) {
              u64 v_c204 = m1370[2];
              slog::join_probe_old<2,1>(st_ins_ansindex1331, st_ins_ansdelta1336, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m1371) {
                u64 v_c2 = m1371[1];
                slog::join_probe_old<3,2>(st_insindex1332, st_insdelta1337, std::array<u64,3>{v_c2, v_c200, 0}, [&](const std::array<u64,3>& m1372) {
                  u64 v_c205 = m1372[2];
                  slog::join_probe_old<2,1>(st_ins_ansindex1333, st_ins_ansdelta1338, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1373) {
                    u64 v_c13 = m1373[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c201}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask1339* _cont = new ReadTask1339(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1339(db,b), false);
  // (crule (pre (let __trid0b07766 const987d6cf2e5032ff135cc0c65) (let __trel1NZB767 const1d9eff40314d54862fee3942) (let __tcol5b1a768 const5feceb66ffc86f38d952786c) (let __trel5R1O769 const66633592860a63ea6408b433) (let __tcol0EO5770 const5feceb66ffc86f38d952786c) (let __trel0TxM771 const66633592860a63ea6408b433) (let __tcol6MBI772 const6b86b273ff34fce19d6b804e) (let __trel5Er6773 const66633592860a63ea6408b433) (let __tcol2Uyr774 constd4735e3a265e16eee03f5971) (let __trel9Dok775 const66633592860a63ea6408b433) (let __tcol94er776 const4e07408562bedb8b60ce05c1)) (scan $sup9688x139x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0b07766 __trel1NZB767 __tcol5b1a768 (1 2 3 4 0)) (tycheck q (accept int) __trid0b07766 __trel5R1O769 __tcol0EO5770 (1 2 3 4 0)) (tycheck n (accept int) __trid0b07766 __trel0TxM771 __tcol6MBI772 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0b07766 __trel5Er6773 __tcol2Uyr774 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0b07766 __trel9Dok775 __tcol94er776 (1 2 3 4 0)) (emit-temp temp7LNh1339 l n q u v) (mkstruct pbranch (1 2 3 4 0) __t7pc5201 q n u v)) set.slog:140 #f)
  class ReadTask1377 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1375;  u32 sid1374;  u32 sid1376;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp7LNh1339");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x139x0x0x0");
      sid1375 = db->getRelation("_enum")->getStructId();
      sid1374 = db->getRelation("pbranch")->getStructId();
      sid1376 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1377(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c207 = v_const1d9eff40314d54862fee3942;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_const66633592860a63ea6408b433;
      u64 v_c210 = v_const5feceb66ffc86f38d952786c;
      u64 v_c211 = v_const66633592860a63ea6408b433;
      u64 v_c212 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c213 = v_const66633592860a63ea6408b433;
      u64 v_c214 = v_constd4735e3a265e16eee03f5971;
      u64 v_c215 = v_const66633592860a63ea6408b433;
      u64 v_c216 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c28 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c35 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c36 = _t[7];
        u64 v_c37 = _t[8];
        ++_fires;
        if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid1374 || decode_struct_id(v_c23) == sid1375 || decode_struct_id(v_c23) == sid1376))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c206, v_c207, v_c208, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c35)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c206, v_c209, v_c210, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c34)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c206, v_c211, v_c212, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c36) && (decode_struct_id(v_c36) == sid1374 || decode_struct_id(v_c36) == sid1375 || decode_struct_id(v_c36) == sid1376))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c206, v_c213, v_c214, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c37) && (decode_struct_id(v_c37) == sid1374 || decode_struct_id(v_c37) == sid1375 || decode_struct_id(v_c37) == sid1376))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c206, v_c215, v_c216, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c23, v_c34, v_c35, v_c36, v_c37});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c35, v_c34, v_c36, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:$sup9688x139x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1377* _cont = new ReadTask1377(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1377(db,b), false);
  // (crule (pre (let __trid4bzk1020 const78643ffd185a1863a6e6997e) (let __trel9Hn81021 const94d9c4e2675ef4bd8443d499) (let __tcol3D5O1022 const5feceb66ffc86f38d952786c) (let __trel9FD61023 const66633592860a63ea6408b433) (let __tcol62Yd1024 const5feceb66ffc86f38d952786c) (let __trel3b0A1025 const66633592860a63ea6408b433) (let __tcol1zG11026 const6b86b273ff34fce19d6b804e) (let __trel3Hbw1027 const66633592860a63ea6408b433) (let __tcol4Z9H1028 constd4735e3a265e16eee03f5971) (let __trel8CKs1029 const66633592860a63ea6408b433) (let __tcol5pAe1030 const4e07408562bedb8b60ce05c1)) (scan $sup9688x103x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bzk1020 __trel9Hn81021 __tcol3D5O1022 (1 2 3 4 0)) (tycheck q (accept int) __trid4bzk1020 __trel9FD61023 __tcol62Yd1024 (1 2 3 4 0)) (tycheck n (accept int) __trid4bzk1020 __trel3b0A1025 __tcol1zG11026 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bzk1020 __trel3Hbw1027 __tcol4Z9H1028 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bzk1020 __trel8CKs1029 __tcol5pAe1030 (1 2 3 4 0)) (emit-temp temp1pqw1409 l n q u v) (mkstruct pbranch (1 2 3 4 0) __t9ac335 q n u v)) set.slog:104 #f)
  class ReadTask1381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1379;  u32 sid1378;  u32 sid1380;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp1pqw1409");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x103x0x0x1");
      sid1379 = db->getRelation("_enum")->getStructId();
      sid1378 = db->getRelation("pbranch")->getStructId();
      sid1380 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c217 = v_const78643ffd185a1863a6e6997e;
      u64 v_c218 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c219 = v_const5feceb66ffc86f38d952786c;
      u64 v_c220 = v_const66633592860a63ea6408b433;
      u64 v_c221 = v_const5feceb66ffc86f38d952786c;
      u64 v_c222 = v_const66633592860a63ea6408b433;
      u64 v_c223 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c224 = v_const66633592860a63ea6408b433;
      u64 v_c225 = v_constd4735e3a265e16eee03f5971;
      u64 v_c226 = v_const66633592860a63ea6408b433;
      u64 v_c227 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c28 = _t[0];
        u64 v_c228 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c34 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c35 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c36 = _t[8];
        u64 v_c37 = _t[9];
        ++_fires;
        if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid1378 || decode_struct_id(v_c23) == sid1379 || decode_struct_id(v_c23) == sid1380))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c217, v_c218, v_c219, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c35)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c217, v_c220, v_c221, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c34)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c217, v_c222, v_c223, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c36) && (decode_struct_id(v_c36) == sid1378 || decode_struct_id(v_c36) == sid1379 || decode_struct_id(v_c36) == sid1380))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c217, v_c224, v_c225, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c37) && (decode_struct_id(v_c37) == sid1378 || decode_struct_id(v_c37) == sid1379 || decode_struct_id(v_c37) == sid1380))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c217, v_c226, v_c227, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c23, v_c34, v_c35, v_c36, v_c37});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c35, v_c34, v_c36, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:$sup9688x103x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1381* _cont = new ReadTask1381(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1381(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst4emd384 __t88YX385 __v1) (body (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins (2 0 1) 1 __tconst7Eph382) (exists st_ins_ans (1 0) 1 __v1) (exists st_ins_ans (0 1) 1 __t88YX385) (exists st_ins (2 0 1) 1 __tconst2ksI386) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join st_ins (1 2 0) 2 __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 1 __t2Q6o381 __v0) (join st_ins (1 2 0) 2 __v0 __tconst7Eph382 __t0FtX383) (join st_ins_ans (0 1) 2 __t0FtX383 __v1) (join st_ins_ans (0 1) 1 __t88YX385 __v2) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (join st_ins_ans (0 1) 1 __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask1396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex1382;  slog::Index** st_insindex1383;  slog::Index** st_ins_ansindex1384;  slog::Index** st_ins_ansindex1385;  slog::Index** st_insindex1386;  slog::Index** _enumindex1387;  slog::Index** st_insindex1388;  slog::Index** st_ins_ansindex1389;  slog::Index** st_insindex1390;  slog::Index** st_ins_ansindex1391;  slog::Index** st_ins_ansindex1392;  slog::Index** st_insindex1393;  slog::Index** st_ins_ansindex1394;  slog::Index** st_insdelta1395;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1397({0});
      slog::Relation* readrel1398 = db->getRelation("canon");
      head_index[0] = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({2, 0, 1});
      slog::Relation* readrel1400 = db->getRelation("st_ins");
      driver_index = readrel1400->getIndex(ord1399, true);
      std::vector<u16> ord1401({2, 0, 1});
      slog::Relation* readrel1402 = db->getRelation("st_ins");
      st_insindex1382 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({2, 0, 1});
      slog::Relation* readrel1404 = db->getRelation("st_ins");
      st_insindex1383 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 0});
      slog::Relation* readrel1406 = db->getRelation("st_ins_ans");
      st_ins_ansindex1384 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({0, 1});
      slog::Relation* readrel1408 = db->getRelation("st_ins_ans");
      st_ins_ansindex1385 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({2, 0, 1});
      slog::Relation* readrel1410 = db->getRelation("st_ins");
      st_insindex1386 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({1, 0});
      slog::Relation* readrel1412 = db->getRelation("_enum");
      _enumindex1387 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({1, 2, 0});
      slog::Relation* readrel1414 = db->getRelation("st_ins");
      st_insindex1388 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({0, 1});
      slog::Relation* readrel1416 = db->getRelation("st_ins_ans");
      st_ins_ansindex1389 = readrel1416->getIndex(ord1415, false);
      std::vector<u16> ord1417({1, 2, 0});
      slog::Relation* readrel1418 = db->getRelation("st_ins");
      st_insindex1390 = readrel1418->getIndex(ord1417, false);
      std::vector<u16> ord1419({0, 1});
      slog::Relation* readrel1420 = db->getRelation("st_ins_ans");
      st_ins_ansindex1391 = readrel1420->getIndex(ord1419, false);
      std::vector<u16> ord1421({0, 1});
      slog::Relation* readrel1422 = db->getRelation("st_ins_ans");
      st_ins_ansindex1392 = readrel1422->getIndex(ord1421, false);
      std::vector<u16> ord1423({1, 2, 0});
      slog::Relation* readrel1424 = db->getRelation("st_ins");
      st_insindex1393 = readrel1424->getIndex(ord1423, false);
      std::vector<u16> ord1425({1, 2, 0});
      slog::Relation* readrel1426 = db->getRelation("st_ins");
      st_insdelta1395 = readrel1426->getIndex(ord1425, true);
      std::vector<u16> ord1427({0, 1});
      slog::Relation* readrel1428 = db->getRelation("st_ins_ans");
      st_ins_ansindex1394 = readrel1428->getIndex(ord1427, false);
  
    }
    ReadTask1396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c229 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c230 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c231 = v_const2c624232cdd221771294dfbb;
      u64 v_c232 = v_constd4735e3a265e16eee03f5971;
      u64 v_c233 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c232, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1429) {
        u64 v_c234 = m1429[1];
        u64 v_c2 = m1429[2];
        if (buckethash(v_c234) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex1382, std::array<u64,3>{v_c230, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1383, std::array<u64,3>{v_c231, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex1384, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex1385, std::array<u64,2>{v_c234, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1386, std::array<u64,3>{v_c233, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex1387, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1430) {
          u64 v_c235 = m1430[1];
          slog::join_probe<3,2>(st_insindex1388, std::array<u64,3>{v_c235, v_c230, 0}, [&](const std::array<u64,3>& m1431) {
            u64 v_c236 = m1431[2];
            slog::join_probe<2,1>(st_ins_ansindex1389, std::array<u64,2>{v_c236, 0}, [&](const std::array<u64,2>& m1432) {
              u64 v_c4 = m1432[1];
              slog::join_probe<3,2>(st_insindex1390, std::array<u64,3>{v_c4, v_c231, 0}, [&](const std::array<u64,3>& m1433) {
                u64 v_c237 = m1433[2];
                slog::join_probe<2,2>(st_ins_ansindex1391, std::array<u64,2>{v_c237, v_c2}, [&](const std::array<u64,2>& m1434) {
                  slog::join_probe<2,1>(st_ins_ansindex1392, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1435) {
                    u64 v_c13 = m1435[1];
                    slog::join_probe_old<3,2>(st_insindex1393, st_insdelta1395, std::array<u64,3>{v_c13, v_c233, 0}, [&](const std::array<u64,3>& m1436) {
                      u64 v_c238 = m1436[2];
                      slog::join_probe<2,1>(st_ins_ansindex1394, std::array<u64,2>{v_c238, 0}, [&](const std::array<u64,2>& m1437) {
                        u64 v_c24 = m1437[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1396* _cont = new ReadTask1396(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1396(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk8qS81292 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk8qS81292) (letp chk07wV1293 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk07wV1293) (letp chk0Zuc1294 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk0Zuc1294) (letp chk0gdJ1295 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk0gdJ1295) (letp chk4rmC1296 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk4rmC1296)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask1454 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1438;  slog::Index** $seq_atindex1439;  slog::Index** $seq_atindex1440;  slog::Index** $seq_atrindex1441;  slog::Index** $seq_atrindex1442;  slog::Index** $seq_atrindex1443;  slog::Index** $seq_atrindex1444;  slog::Index** st_fromlistindex1445;  slog::Index** st_fromlist_ansindex1446;  slog::Index** $seq_atdelta1447;  slog::Index** $seq_atdelta1448;  slog::Index** $seq_atdelta1449;  slog::Index** $seq_atrdelta1450;  slog::Index** $seq_atrdelta1451;  slog::Index** $seq_atrdelta1452;  slog::Index** $seq_atrdelta1453;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1455({0});
      slog::Relation* readrel1456 = db->getRelation("canon");
      head_index[0] = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 0, 2});
      slog::Relation* readrel1458 = db->getRelation("$seq_at");
      driver_index = readrel1458->getIndex(ord1457, true);
      std::vector<u16> ord1459({1, 0, 2});
      slog::Relation* readrel1460 = db->getRelation("$seq_at");
      $seq_atindex1438 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({1, 0, 2});
      slog::Relation* readrel1462 = db->getRelation("$seq_at");
      $seq_atdelta1447 = readrel1462->getIndex(ord1461, true);
      std::vector<u16> ord1463({1, 0, 2});
      slog::Relation* readrel1464 = db->getRelation("$seq_at");
      $seq_atindex1439 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 0, 2});
      slog::Relation* readrel1466 = db->getRelation("$seq_at");
      $seq_atdelta1448 = readrel1466->getIndex(ord1465, true);
      std::vector<u16> ord1467({1, 0, 2});
      slog::Relation* readrel1468 = db->getRelation("$seq_at");
      $seq_atindex1440 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 0, 2});
      slog::Relation* readrel1470 = db->getRelation("$seq_at");
      $seq_atdelta1449 = readrel1470->getIndex(ord1469, true);
      std::vector<u16> ord1471({0, 1, 2});
      slog::Relation* readrel1472 = db->getRelation("$seq_atr");
      $seq_atrindex1441 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({0, 1, 2});
      slog::Relation* readrel1474 = db->getRelation("$seq_atr");
      $seq_atrdelta1450 = readrel1474->getIndex(ord1473, true);
      std::vector<u16> ord1475({0, 1, 2});
      slog::Relation* readrel1476 = db->getRelation("$seq_atr");
      $seq_atrindex1442 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({0, 1, 2});
      slog::Relation* readrel1478 = db->getRelation("$seq_atr");
      $seq_atrdelta1451 = readrel1478->getIndex(ord1477, true);
      std::vector<u16> ord1479({0, 1, 2});
      slog::Relation* readrel1480 = db->getRelation("$seq_atr");
      $seq_atrindex1443 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({0, 1, 2});
      slog::Relation* readrel1482 = db->getRelation("$seq_atr");
      $seq_atrdelta1452 = readrel1482->getIndex(ord1481, true);
      std::vector<u16> ord1483({0, 1, 2});
      slog::Relation* readrel1484 = db->getRelation("$seq_atr");
      $seq_atrindex1444 = readrel1484->getIndex(ord1483, false);
      std::vector<u16> ord1485({0, 1, 2});
      slog::Relation* readrel1486 = db->getRelation("$seq_atr");
      $seq_atrdelta1453 = readrel1486->getIndex(ord1485, true);
      std::vector<u16> ord1487({1, 0});
      slog::Relation* readrel1488 = db->getRelation("st_fromlist");
      st_fromlistindex1445 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({0, 1});
      slog::Relation* readrel1490 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1446 = readrel1490->getIndex(ord1489, false);
  
    }
    ReadTask1454(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constef2d127de37b942baad06145;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_constd4735e3a265e16eee03f5971;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_const2c624232cdd221771294dfbb;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c66 = v_constef2d127de37b942baad06145;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const2c624232cdd221771294dfbb;
      u64 v_c71 = v_constd4735e3a265e16eee03f5971;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c74 = v_constef2d127de37b942baad06145;
      u64 v_c75 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c76 = v_constd4735e3a265e16eee03f5971;
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const2c624232cdd221771294dfbb;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c67, v_c66, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1491) {
        u64 v_c82 = m1491[2];
        if (buckethash(v_c82) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1438, $seq_atdelta1447, std::array<u64,3>{v_c69, v_c68, v_c82}, [&](const std::array<u64,3>& m1492) {
          slog::join_probe_old<3,3>($seq_atindex1439, $seq_atdelta1448, std::array<u64,3>{v_c71, v_c70, v_c82}, [&](const std::array<u64,3>& m1493) {
            slog::join_probe_old<3,3>($seq_atindex1440, $seq_atdelta1449, std::array<u64,3>{v_c73, v_c72, v_c82}, [&](const std::array<u64,3>& m1494) {
              slog::join_probe_old<3,3>($seq_atrindex1441, $seq_atrdelta1450, std::array<u64,3>{v_c74, v_c75, v_c82}, [&](const std::array<u64,3>& m1495) {
                slog::join_probe_old<3,3>($seq_atrindex1442, $seq_atrdelta1451, std::array<u64,3>{v_c76, v_c77, v_c82}, [&](const std::array<u64,3>& m1496) {
                  slog::join_probe_old<3,3>($seq_atrindex1443, $seq_atrdelta1452, std::array<u64,3>{v_c78, v_c79, v_c82}, [&](const std::array<u64,3>& m1497) {
                    slog::join_probe_old<3,3>($seq_atrindex1444, $seq_atrdelta1453, std::array<u64,3>{v_c80, v_c81, v_c82}, [&](const std::array<u64,3>& m1498) {
                      slog::join_probe<2,1>(st_fromlistindex1445, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1499) {
                        u64 v_c83 = m1499[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1446, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m1500) {
                          u64 v_c24 = m1500[1];
                          bool ok1501 = true;
                          u64 v_c84 = _prim_aslst(db, v_c82, &ok1501);
                          if (!ok1501) return;
                          u64 v_c239 = _prim_llen(db, v_c84);
                          if (v_c239 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c57 != v_c239) return;
                          bool ok1502 = true;
                          u64 v_c240 = _prim_lref(db, v_c84, v_c58, &ok1502);
                          if (!ok1502) return;
                          if (v_c59 != v_c240) return;
                          bool ok1503 = true;
                          u64 v_c241 = _prim_lref(db, v_c84, v_c60, &ok1503);
                          if (!ok1503) return;
                          if (v_c61 != v_c241) return;
                          bool ok1504 = true;
                          u64 v_c242 = _prim_lref(db, v_c84, v_c62, &ok1504);
                          if (!ok1504) return;
                          if (v_c63 != v_c242) return;
                          bool ok1505 = true;
                          u64 v_c243 = _prim_lref(db, v_c84, v_c64, &ok1505);
                          if (!ok1505) return;
                          if (v_c65 != v_c243) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1454* _cont = new ReadTask1454(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1454(db,b), false);
  // (crule (pre) (scan pbranch __t66nq2 p m l r) (body (exists st_union (1 2 0) 1 __t66nq2) (join pbranch (1 2 3 4 0) 2 p m u v __t6Gju1) (join-old st_union (1 2 0) 2 (1 2 0) __t66nq2 __t6Gju1 __t0Mc03)) (head (emit $sup9688x100x0x0x0 (0 1 2 3 4 5 6) __t0Mc03 l m p r u v)) set.slog:101 #f)
  class ReadTask1510 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex1506;  slog::Index** pbranchindex1507;  slog::Index** st_unionindex1508;  slog::Index** st_uniondelta1509;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord1511({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel1512 = db->getRelation("$sup9688x100x0x0x0");
      head_index[0] = readrel1512->getIndex(ord1511, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1513({1, 2, 0});
      slog::Relation* readrel1514 = db->getRelation("st_union");
      st_unionindex1506 = readrel1514->getIndex(ord1513, false);
      std::vector<u16> ord1515({1, 2, 3, 4, 0});
      slog::Relation* readrel1516 = db->getRelation("pbranch");
      pbranchindex1507 = readrel1516->getIndex(ord1515, false);
      std::vector<u16> ord1517({1, 2, 0});
      slog::Relation* readrel1518 = db->getRelation("st_union");
      st_unionindex1508 = readrel1518->getIndex(ord1517, false);
      std::vector<u16> ord1519({1, 2, 0});
      slog::Relation* readrel1520 = db->getRelation("st_union");
      st_uniondelta1509 = readrel1520->getIndex(ord1519, true);
  
    }
    ReadTask1510(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c244 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        if (!slog::exists_probe<3,1>(st_unionindex1506, std::array<u64,3>{v_c244, 0, 0})) return;
        slog::join_probe<5,2>(pbranchindex1507, std::array<u64,5>{v_c21, v_c22, 0, 0, 0}, [&](const std::array<u64,5>& m1521) {
          u64 v_c36 = m1521[2]; u64 v_c37 = m1521[3]; u64 v_c245 = m1521[4];
          slog::join_probe_old<3,2>(st_unionindex1508, st_uniondelta1509, std::array<u64,3>{v_c244, v_c245, 0}, [&](const std::array<u64,3>& m1522) {
            u64 v_c246 = m1522[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c246, v_c23, v_c22, v_c21, v_c24, v_c36, v_c37}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1510* _cont = new ReadTask1510(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1510(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk9s061379 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk9s061379) (letp chk62kW1380 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk62kW1380) (letp chk9OcN1381 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk9OcN1381) (letp chk3CtT1382 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk3CtT1382) (letp chk7Mwq1383 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk7Mwq1383)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask1535 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1523;  slog::Index** $seq_atindex1524;  slog::Index** $seq_atindex1525;  slog::Index** $seq_atindex1526;  slog::Index** $seq_atrindex1527;  slog::Index** $seq_atrindex1528;  slog::Index** $seq_atrindex1529;  slog::Index** st_fromlistindex1530;  slog::Index** st_fromlist_ansindex1531;  slog::Index** $seq_atrdelta1532;  slog::Index** $seq_atrdelta1533;  slog::Index** $seq_atrdelta1534;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1536({0});
      slog::Relation* readrel1537 = db->getRelation("canon");
      head_index[0] = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({0, 1, 2});
      slog::Relation* readrel1539 = db->getRelation("$seq_atr");
      driver_index = readrel1539->getIndex(ord1538, true);
      std::vector<u16> ord1540({1, 0, 2});
      slog::Relation* readrel1541 = db->getRelation("$seq_at");
      $seq_atindex1523 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({1, 0, 2});
      slog::Relation* readrel1543 = db->getRelation("$seq_at");
      $seq_atindex1524 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({1, 0, 2});
      slog::Relation* readrel1545 = db->getRelation("$seq_at");
      $seq_atindex1525 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({1, 0, 2});
      slog::Relation* readrel1547 = db->getRelation("$seq_at");
      $seq_atindex1526 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({0, 1, 2});
      slog::Relation* readrel1549 = db->getRelation("$seq_atr");
      $seq_atrindex1527 = readrel1549->getIndex(ord1548, false);
      std::vector<u16> ord1550({0, 1, 2});
      slog::Relation* readrel1551 = db->getRelation("$seq_atr");
      $seq_atrdelta1532 = readrel1551->getIndex(ord1550, true);
      std::vector<u16> ord1552({0, 1, 2});
      slog::Relation* readrel1553 = db->getRelation("$seq_atr");
      $seq_atrindex1528 = readrel1553->getIndex(ord1552, false);
      std::vector<u16> ord1554({0, 1, 2});
      slog::Relation* readrel1555 = db->getRelation("$seq_atr");
      $seq_atrdelta1533 = readrel1555->getIndex(ord1554, true);
      std::vector<u16> ord1556({0, 1, 2});
      slog::Relation* readrel1557 = db->getRelation("$seq_atr");
      $seq_atrindex1529 = readrel1557->getIndex(ord1556, false);
      std::vector<u16> ord1558({0, 1, 2});
      slog::Relation* readrel1559 = db->getRelation("$seq_atr");
      $seq_atrdelta1534 = readrel1559->getIndex(ord1558, true);
      std::vector<u16> ord1560({1, 0});
      slog::Relation* readrel1561 = db->getRelation("st_fromlist");
      st_fromlistindex1530 = readrel1561->getIndex(ord1560, false);
      std::vector<u16> ord1562({0, 1});
      slog::Relation* readrel1563 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1531 = readrel1563->getIndex(ord1562, false);
  
    }
    ReadTask1535(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c247 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c248 = v_const5feceb66ffc86f38d952786c;
      u64 v_c249 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c250 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c251 = v_const2c624232cdd221771294dfbb;
      u64 v_c252 = v_constd4735e3a265e16eee03f5971;
      u64 v_c253 = v_constd4735e3a265e16eee03f5971;
      u64 v_c254 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c255 = v_constef2d127de37b942baad06145;
      u64 v_c256 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c257 = v_const5feceb66ffc86f38d952786c;
      u64 v_c258 = v_const2c624232cdd221771294dfbb;
      u64 v_c259 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c260 = v_constd4735e3a265e16eee03f5971;
      u64 v_c261 = v_constd4735e3a265e16eee03f5971;
      u64 v_c262 = v_constef2d127de37b942baad06145;
      u64 v_c263 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c264 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c265 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c266 = v_const2c624232cdd221771294dfbb;
      u64 v_c267 = v_constd4735e3a265e16eee03f5971;
      u64 v_c268 = v_constd4735e3a265e16eee03f5971;
      u64 v_c269 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c270 = v_constef2d127de37b942baad06145;
      u64 v_c271 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c264, v_c265, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1564) {
        u64 v_c82 = m1564[2];
        if (buckethash(v_c82) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1523, std::array<u64,3>{v_c257, v_c256, v_c82}, [&](const std::array<u64,3>& m1565) {
          slog::join_probe<3,3>($seq_atindex1524, std::array<u64,3>{v_c259, v_c258, v_c82}, [&](const std::array<u64,3>& m1566) {
            slog::join_probe<3,3>($seq_atindex1525, std::array<u64,3>{v_c261, v_c260, v_c82}, [&](const std::array<u64,3>& m1567) {
              slog::join_probe<3,3>($seq_atindex1526, std::array<u64,3>{v_c263, v_c262, v_c82}, [&](const std::array<u64,3>& m1568) {
                slog::join_probe_old<3,3>($seq_atrindex1527, $seq_atrdelta1532, std::array<u64,3>{v_c266, v_c267, v_c82}, [&](const std::array<u64,3>& m1569) {
                  slog::join_probe_old<3,3>($seq_atrindex1528, $seq_atrdelta1533, std::array<u64,3>{v_c268, v_c269, v_c82}, [&](const std::array<u64,3>& m1570) {
                    slog::join_probe_old<3,3>($seq_atrindex1529, $seq_atrdelta1534, std::array<u64,3>{v_c270, v_c271, v_c82}, [&](const std::array<u64,3>& m1571) {
                      slog::join_probe<2,1>(st_fromlistindex1530, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1572) {
                        u64 v_c272 = m1572[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1531, std::array<u64,2>{v_c272, 0}, [&](const std::array<u64,2>& m1573) {
                          u64 v_c24 = m1573[1];
                          bool ok1574 = true;
                          u64 v_c273 = _prim_aslst(db, v_c82, &ok1574);
                          if (!ok1574) return;
                          u64 v_c274 = _prim_llen(db, v_c273);
                          if (v_c274 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c247 != v_c274) return;
                          bool ok1575 = true;
                          u64 v_c275 = _prim_lref(db, v_c273, v_c248, &ok1575);
                          if (!ok1575) return;
                          if (v_c249 != v_c275) return;
                          bool ok1576 = true;
                          u64 v_c276 = _prim_lref(db, v_c273, v_c250, &ok1576);
                          if (!ok1576) return;
                          if (v_c251 != v_c276) return;
                          bool ok1577 = true;
                          u64 v_c277 = _prim_lref(db, v_c273, v_c252, &ok1577);
                          if (!ok1577) return;
                          if (v_c253 != v_c277) return;
                          bool ok1578 = true;
                          u64 v_c278 = _prim_lref(db, v_c273, v_c254, &ok1578);
                          if (!ok1578) return;
                          if (v_c255 != v_c278) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1535* _cont = new ReadTask1535(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1535(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan $sup9688x72x0x0x0 __t6Rw6503 k l m p r) (body (exists st_mem0 (2 0 1) 2 k __t6Rw6503) (exists st_mem0 (1 2 0) 2 r k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1XtO502) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6Rw6503 __t1XtO502 k) (join-old st_mem0 (1 2 0) 2 (1 2 0) r k __t9V8P506) (exists st_mem0_ans (0 1) 1 __t9V8P506) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t4A7W507) (join st_msk_ans (0 1) 2 __t4A7W507 p) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask1594 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index1579;  slog::Index** st_mem0index1580;  slog::Index** st_mskindex1581;  slog::Index** st_msk_ansindex1582;  slog::Index** pbranchindex1583;  slog::Index** st_mem0index1584;  slog::Index** st_mem0index1585;  slog::Index** st_mem0_ansindex1586;  slog::Index** st_mskindex1587;  slog::Index** st_msk_ansindex1588;  slog::Index** st_mem0_ansindex1589;  slog::Index** pbranchdelta1590;  slog::Index** st_mem0delta1591;  slog::Index** st_mem0delta1592;  slog::Index** st_mskdelta1593;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1595({0, 1});
      slog::Relation* readrel1596 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1596->getIndex(ord1595, false);
      outer_rel = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord1597({2, 0, 1});
      slog::Relation* readrel1598 = db->getRelation("st_mem0");
      st_mem0index1579 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({1, 2, 0});
      slog::Relation* readrel1600 = db->getRelation("st_mem0");
      st_mem0index1580 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({1, 2, 0});
      slog::Relation* readrel1602 = db->getRelation("st_msk");
      st_mskindex1581 = readrel1602->getIndex(ord1601, false);
      std::vector<u16> ord1603({1, 0});
      slog::Relation* readrel1604 = db->getRelation("st_msk_ans");
      st_msk_ansindex1582 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({1, 2, 3, 4, 0});
      slog::Relation* readrel1606 = db->getRelation("pbranch");
      pbranchindex1583 = readrel1606->getIndex(ord1605, false);
      std::vector<u16> ord1607({1, 2, 3, 4, 0});
      slog::Relation* readrel1608 = db->getRelation("pbranch");
      pbranchdelta1590 = readrel1608->getIndex(ord1607, true);
      std::vector<u16> ord1609({0, 1, 2});
      slog::Relation* readrel1610 = db->getRelation("st_mem0");
      st_mem0index1584 = readrel1610->getIndex(ord1609, false);
      std::vector<u16> ord1611({0, 1, 2});
      slog::Relation* readrel1612 = db->getRelation("st_mem0");
      st_mem0delta1591 = readrel1612->getIndex(ord1611, true);
      std::vector<u16> ord1613({1, 2, 0});
      slog::Relation* readrel1614 = db->getRelation("st_mem0");
      st_mem0index1585 = readrel1614->getIndex(ord1613, false);
      std::vector<u16> ord1615({1, 2, 0});
      slog::Relation* readrel1616 = db->getRelation("st_mem0");
      st_mem0delta1592 = readrel1616->getIndex(ord1615, true);
      std::vector<u16> ord1617({0, 1});
      slog::Relation* readrel1618 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1586 = readrel1618->getIndex(ord1617, false);
      std::vector<u16> ord1619({1, 2, 0});
      slog::Relation* readrel1620 = db->getRelation("st_msk");
      st_mskindex1587 = readrel1620->getIndex(ord1619, false);
      std::vector<u16> ord1621({1, 2, 0});
      slog::Relation* readrel1622 = db->getRelation("st_msk");
      st_mskdelta1593 = readrel1622->getIndex(ord1621, true);
      std::vector<u16> ord1623({0, 1});
      slog::Relation* readrel1624 = db->getRelation("st_msk_ans");
      st_msk_ansindex1588 = readrel1624->getIndex(ord1623, false);
      std::vector<u16> ord1625({0, 1});
      slog::Relation* readrel1626 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1589 = readrel1626->getIndex(ord1625, false);
  
    }
    ReadTask1594(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c279 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c280 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c24 = _t[5];
        if (!slog::exists_probe<3,2>(st_mem0index1579, std::array<u64,3>{v_c20, v_c280, 0})) return;
        if (!slog::exists_probe<3,2>(st_mem0index1580, std::array<u64,3>{v_c24, v_c20, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex1581, std::array<u64,3>{v_c20, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1582, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex1583, pbranchdelta1590, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m1627) {
          u64 v_c281 = m1627[4];
          slog::join_probe_old<3,3>(st_mem0index1584, st_mem0delta1591, std::array<u64,3>{v_c280, v_c281, v_c20}, [&](const std::array<u64,3>& m1628) {
            slog::join_probe_old<3,2>(st_mem0index1585, st_mem0delta1592, std::array<u64,3>{v_c24, v_c20, 0}, [&](const std::array<u64,3>& m1629) {
              u64 v_c282 = m1629[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex1586, std::array<u64,2>{v_c282, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex1587, st_mskdelta1593, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m1630) {
                u64 v_c283 = m1630[2];
                slog::join_probe<2,2>(st_msk_ansindex1588, std::array<u64,2>{v_c283, v_c21}, [&](const std::array<u64,2>& m1631) {
                  slog::join_probe<2,1>(st_mem0_ansindex1589, std::array<u64,2>{v_c282, 0}, [&](const std::array<u64,2>& m1632) {
                    u64 v_c132 = m1632[1];
                    u64 v_c284 = _prim_band(db, v_c20, v_c22);
                    if (v_c284 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c285 = _prim_gt(db, v_c284, v_c279);
                    if (v_c285 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c285) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c280, v_c132}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:$sup9688x72x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1594* _cont = new ReadTask1594(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1594(db,b), false);
  // (crule (pre (let __trid4bDq789 const76a4fedc25549f0939d52fb7) (let __trel1o0k790 const26c89ee8ccc4ea998fd1a912) (let __tcol6PPW791 const4e07408562bedb8b60ce05c1)) (scan st_del_ans __t8asA369 __v0) (body (join-old st_del (0 2 1) 1 (0 2 1) __t8asA369 k l) (exists st_msk (1 2 0) 1 k) (join $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5gdG368) (join st_msk_ans (0 1) 2 __t5gdG368 p)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bDq789 __trel1o0k790 __tcol6PPW791 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __3BTR788 p m __v0 r)) set.slog:89 #f)
  class ReadTask1645 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex1634;  slog::Index** st_mskindex1635;  slog::Index** $sup9688x88x0x0x0index1636;  slog::Index** st_msk_ansindex1637;  slog::Index** st_mskindex1638;  slog::Index** st_msk_ansindex1639;  slog::Index** st_deldelta1640;  slog::Index** st_mskdelta1641;
    u32 sid1643;  u32 sid1642;  u32 sid1644;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_del_ans");
      std::vector<u16> ord1646({0, 2, 1});
      slog::Relation* readrel1647 = db->getRelation("st_del");
      st_delindex1634 = readrel1647->getIndex(ord1646, false);
      std::vector<u16> ord1648({0, 2, 1});
      slog::Relation* readrel1649 = db->getRelation("st_del");
      st_deldelta1640 = readrel1649->getIndex(ord1648, true);
      std::vector<u16> ord1650({1, 2, 0});
      slog::Relation* readrel1651 = db->getRelation("st_msk");
      st_mskindex1635 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1653 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1636 = readrel1653->getIndex(ord1652, false);
      std::vector<u16> ord1654({1, 0});
      slog::Relation* readrel1655 = db->getRelation("st_msk_ans");
      st_msk_ansindex1637 = readrel1655->getIndex(ord1654, false);
      std::vector<u16> ord1656({1, 2, 0});
      slog::Relation* readrel1657 = db->getRelation("st_msk");
      st_mskindex1638 = readrel1657->getIndex(ord1656, false);
      std::vector<u16> ord1658({1, 2, 0});
      slog::Relation* readrel1659 = db->getRelation("st_msk");
      st_mskdelta1641 = readrel1659->getIndex(ord1658, true);
      std::vector<u16> ord1660({0, 1});
      slog::Relation* readrel1661 = db->getRelation("st_msk_ans");
      st_msk_ansindex1639 = readrel1661->getIndex(ord1660, false);
      sid1643 = db->getRelation("_enum")->getStructId();
      sid1642 = db->getRelation("pbranch")->getStructId();
      sid1644 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1645(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c286 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c287 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c288 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c289 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<3,1>(st_delindex1634, st_deldelta1640, std::array<u64,3>{v_c289, 0, 0}, [&](const std::array<u64,3>& m1662) {
          u64 v_c20 = m1662[1]; u64 v_c23 = m1662[2];
          if (!slog::exists_probe<3,1>(st_mskindex1635, std::array<u64,3>{v_c20, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x88x0x0x0index1636, std::array<u64,6>{v_c20, v_c23, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1663) {
            u64 v_c28 = m1663[2]; u64 v_c22 = m1663[3]; u64 v_c21 = m1663[4]; u64 v_c24 = m1663[5];
            if (!slog::exists_probe<2,1>(st_msk_ansindex1637, std::array<u64,2>{v_c21, 0})) return;
            slog::join_probe_old<3,2>(st_mskindex1638, st_mskdelta1641, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m1664) {
              u64 v_c290 = m1664[2];
              slog::join_probe<2,2>(st_msk_ansindex1639, std::array<u64,2>{v_c290, v_c21}, [&](const std::array<u64,2>& m1665) {
                ++_fires;
                if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid1642 || decode_struct_id(v_c24) == sid1643 || decode_struct_id(v_c24) == sid1644))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c286, v_c287, v_c288, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c22, v_c4, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask1645* _cont = new ReadTask1645(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1645(db,b), false);
  // (crule (pre (let __trid0O8l910 const1e44311dd5d36c3a7dc21dfa) (let __trel2X7j911 const26c89ee8ccc4ea998fd1a912) (let __tcol3tdZ912 constd4735e3a265e16eee03f5971)) (scan st_msk __t8Ytg398 k m) (body (exists $sup9688x90x0x0x0 (1 3 4 0 2 5) 2 k m) (exists st_del (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t8Ytg398 p) (join $sup9688x90x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old st_del (1 2 0) 2 (1 2 0) r k __t56Eo399) (join st_del_ans (0 1) 1 __t56Eo399 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0O8l910 __trel2X7j911 __tcol3tdZ912 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __6yFQ909 p m l __v0)) set.slog:91 #f)
  class ReadTask1676 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index1666;  slog::Index** st_delindex1667;  slog::Index** st_msk_ansindex1668;  slog::Index** $sup9688x90x0x0x0index1669;  slog::Index** st_delindex1670;  slog::Index** st_del_ansindex1671;  slog::Index** st_deldelta1672;
    u32 sid1674;  u32 sid1673;  u32 sid1675;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1677({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1678 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index1666 = readrel1678->getIndex(ord1677, false);
      std::vector<u16> ord1679({2, 0, 1});
      slog::Relation* readrel1680 = db->getRelation("st_del");
      st_delindex1667 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({0, 1});
      slog::Relation* readrel1682 = db->getRelation("st_msk_ans");
      st_msk_ansindex1668 = readrel1682->getIndex(ord1681, false);
      std::vector<u16> ord1683({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1684 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index1669 = readrel1684->getIndex(ord1683, false);
      std::vector<u16> ord1685({1, 2, 0});
      slog::Relation* readrel1686 = db->getRelation("st_del");
      st_delindex1670 = readrel1686->getIndex(ord1685, false);
      std::vector<u16> ord1687({1, 2, 0});
      slog::Relation* readrel1688 = db->getRelation("st_del");
      st_deldelta1672 = readrel1688->getIndex(ord1687, true);
      std::vector<u16> ord1689({0, 1});
      slog::Relation* readrel1690 = db->getRelation("st_del_ans");
      st_del_ansindex1671 = readrel1690->getIndex(ord1689, false);
      sid1674 = db->getRelation("_enum")->getStructId();
      sid1673 = db->getRelation("pbranch")->getStructId();
      sid1675 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1676(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c291 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c292 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c293 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c294 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x90x0x0x0index1666, std::array<u64,6>{v_c20, v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex1667, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1668, std::array<u64,2>{v_c294, 0}, [&](const std::array<u64,2>& m1691) {
          u64 v_c21 = m1691[1];
          slog::join_probe<6,3>($sup9688x90x0x0x0index1669, std::array<u64,6>{v_c20, v_c22, v_c21, 0, 0, 0}, [&](const std::array<u64,6>& m1692) {
            u64 v_c28 = m1692[3]; u64 v_c23 = m1692[4]; u64 v_c24 = m1692[5];
            slog::join_probe_old<3,2>(st_delindex1670, st_deldelta1672, std::array<u64,3>{v_c24, v_c20, 0}, [&](const std::array<u64,3>& m1693) {
              u64 v_c295 = m1693[2];
              slog::join_probe<2,1>(st_del_ansindex1671, std::array<u64,2>{v_c295, 0}, [&](const std::array<u64,2>& m1694) {
                u64 v_c4 = m1694[1];
                ++_fires;
                if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid1673 || decode_struct_id(v_c23) == sid1674 || decode_struct_id(v_c23) == sid1675))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c291, v_c292, v_c293, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c22, v_c23, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1676* _cont = new ReadTask1676(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1676(db,b), false);
  // (crule (pre) (scan st_union __t8LsM290 r v) (body (exists $sup9688x100x0x0x0 (4 6 0 1 2 3 5) 2 r v) (exists pbranch (4 0 1 2 3) 1 v) (exists pbranch (4 0 1 2 3) 1 r) (join st_union_ans (0 1) 1 __t8LsM290 __v1) (join $sup9688x100x0x0x0 (4 6 0 1 2 3 5) 2 r v __t2Q3U288 l m p u) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (1 2 0) 2 l u) (join pbranch (1 2 3 4 0) 4 p m u v __t22FG286) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (join pbranch (1 2 3 4 0) 4 p m l r __t1pUK287) (join st_union (0 1 2) 3 __t2Q3U288 __t1pUK287 __t22FG286) (join st_union (1 2 0) 2 l u __t1gnX289) (join st_union_ans (0 1) 1 __t1gnX289 __v0)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask1708 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x100x0x0x0index1695;  slog::Index** pbranchindex1696;  slog::Index** pbranchindex1697;  slog::Index** st_union_ansindex1698;  slog::Index** $sup9688x100x0x0x0index1699;  slog::Index** pbranchindex1700;  slog::Index** st_unionindex1701;  slog::Index** pbranchindex1702;  slog::Index** st_unionindex1703;  slog::Index** pbranchindex1704;  slog::Index** st_unionindex1705;  slog::Index** st_unionindex1706;  slog::Index** st_union_ansindex1707;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord1709({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel1710 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index1695 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({4, 0, 1, 2, 3});
      slog::Relation* readrel1712 = db->getRelation("pbranch");
      pbranchindex1696 = readrel1712->getIndex(ord1711, false);
      std::vector<u16> ord1713({4, 0, 1, 2, 3});
      slog::Relation* readrel1714 = db->getRelation("pbranch");
      pbranchindex1697 = readrel1714->getIndex(ord1713, false);
      std::vector<u16> ord1715({0, 1});
      slog::Relation* readrel1716 = db->getRelation("st_union_ans");
      st_union_ansindex1698 = readrel1716->getIndex(ord1715, false);
      std::vector<u16> ord1717({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel1718 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index1699 = readrel1718->getIndex(ord1717, false);
      std::vector<u16> ord1719({1, 2, 3, 4, 0});
      slog::Relation* readrel1720 = db->getRelation("pbranch");
      pbranchindex1700 = readrel1720->getIndex(ord1719, false);
      std::vector<u16> ord1721({1, 2, 0});
      slog::Relation* readrel1722 = db->getRelation("st_union");
      st_unionindex1701 = readrel1722->getIndex(ord1721, false);
      std::vector<u16> ord1723({1, 2, 3, 4, 0});
      slog::Relation* readrel1724 = db->getRelation("pbranch");
      pbranchindex1702 = readrel1724->getIndex(ord1723, false);
      std::vector<u16> ord1725({2, 0, 1});
      slog::Relation* readrel1726 = db->getRelation("st_union");
      st_unionindex1703 = readrel1726->getIndex(ord1725, false);
      std::vector<u16> ord1727({1, 2, 3, 4, 0});
      slog::Relation* readrel1728 = db->getRelation("pbranch");
      pbranchindex1704 = readrel1728->getIndex(ord1727, false);
      std::vector<u16> ord1729({0, 1, 2});
      slog::Relation* readrel1730 = db->getRelation("st_union");
      st_unionindex1705 = readrel1730->getIndex(ord1729, false);
      std::vector<u16> ord1731({1, 2, 0});
      slog::Relation* readrel1732 = db->getRelation("st_union");
      st_unionindex1706 = readrel1732->getIndex(ord1731, false);
      std::vector<u16> ord1733({0, 1});
      slog::Relation* readrel1734 = db->getRelation("st_union_ans");
      st_union_ansindex1707 = readrel1734->getIndex(ord1733, false);
  
    }
    ReadTask1708(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c166 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c37 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x100x0x0x0index1695, std::array<u64,7>{v_c24, v_c37, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1696, std::array<u64,5>{v_c37, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1697, std::array<u64,5>{v_c24, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex1698, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1735) {
          u64 v_c2 = m1735[1];
          slog::join_probe<7,2>($sup9688x100x0x0x0index1699, std::array<u64,7>{v_c24, v_c37, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1736) {
            u64 v_c163 = m1736[2]; u64 v_c23 = m1736[3]; u64 v_c22 = m1736[4]; u64 v_c21 = m1736[5]; u64 v_c36 = m1736[6];
            if (!slog::exists_probe<5,4>(pbranchindex1700, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<3,2>(st_unionindex1701, std::array<u64,3>{v_c23, v_c36, 0})) return;
            slog::join_probe<5,4>(pbranchindex1702, std::array<u64,5>{v_c21, v_c22, v_c36, v_c37, 0}, [&](const std::array<u64,5>& m1737) {
              u64 v_c164 = m1737[4];
              if (!slog::exists_probe<3,2>(st_unionindex1703, std::array<u64,3>{v_c164, v_c163, 0})) return;
              slog::join_probe<5,4>(pbranchindex1704, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m1738) {
                u64 v_c165 = m1738[4];
                slog::join_probe<3,3>(st_unionindex1705, std::array<u64,3>{v_c163, v_c165, v_c164}, [&](const std::array<u64,3>& m1739) {
                  slog::join_probe<3,2>(st_unionindex1706, std::array<u64,3>{v_c23, v_c36, 0}, [&](const std::array<u64,3>& m1740) {
                    u64 v_c162 = m1740[2];
                    slog::join_probe<2,1>(st_union_ansindex1707, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m1741) {
                      u64 v_c4 = m1741[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c163, v_c4, v_c2, v_c22, v_c21});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c22, v_c4, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask1708* _cont = new ReadTask1708(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1708(db,b), false);
  // (crule (pre (let __trid1Ly3838 const7ce11965015db325c92ba444) (let __trel8rT8839 consta10f76b4ec574de5d7b6908e) (let __tcol0PBi840 const5feceb66ffc86f38d952786c) (let __trel0QX8841 consta10f76b4ec574de5d7b6908e) (let __tcol5raW842 const6b86b273ff34fce19d6b804e)) (scan $sup9688x148x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid1Ly3838 __trel8rT8839 __tcol0PBi840 (1 2 3 4 0)) (tycheck n (accept int) __trid1Ly3838 __trel0QX8841 __tcol5raW842 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __0rO8837 p n)) set.slog:149 #f)
  class ReadTask1742 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x148x0x0x0");
  
    }
    ReadTask1742(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c296 = v_const7ce11965015db325c92ba444;
      u64 v_c297 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c35 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c36 = _t[7];
        u64 v_c37 = _t[8];
        ++_fires;
        if (!(is_int(v_c21)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c296, v_c297, v_c298, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c34)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c296, v_c299, v_c300, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c21, v_c34}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:$sup9688x148x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1742* _cont = new ReadTask1742(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1742(db,b), false);
  // (crule (pre) (scan st_hsb_ans __t81zv171 __v3) (body (join-old st_hsb_ans (0 1) 1 (0 1) __t81zv171 __v1) (join-old st_hsb (0 1) 1 (0 1) __t81zv171 __t7IWy172) (join-old $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk0lin1340 (bxor p0 p1)) (eq __t7IWy172 chk0lin1340)) (head (emit $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t81zv171 __t81zv171 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask1749 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1743;  slog::Index** st_hsbindex1744;  slog::Index** $sup9688x40x0x0x1index1745;  slog::Index** st_hsb_ansdelta1746;  slog::Index** st_hsbdelta1747;  slog::Index** $sup9688x40x0x0x1delta1748;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord1750({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1751 = db->getRelation("$sup9688x40x0x0x2");
      head_index[0] = readrel1751->getIndex(ord1750, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1752({0, 1});
      slog::Relation* readrel1753 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1743 = readrel1753->getIndex(ord1752, false);
      std::vector<u16> ord1754({0, 1});
      slog::Relation* readrel1755 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1746 = readrel1755->getIndex(ord1754, true);
      std::vector<u16> ord1756({0, 1});
      slog::Relation* readrel1757 = db->getRelation("st_hsb");
      st_hsbindex1744 = readrel1757->getIndex(ord1756, false);
      std::vector<u16> ord1758({0, 1});
      slog::Relation* readrel1759 = db->getRelation("st_hsb");
      st_hsbdelta1747 = readrel1759->getIndex(ord1758, true);
      std::vector<u16> ord1760({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1761 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1745 = readrel1761->getIndex(ord1760, false);
      std::vector<u16> ord1762({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1763 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1delta1748 = readrel1763->getIndex(ord1762, true);
  
    }
    ReadTask1749(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c301 = _t[0];
        u64 v_c3 = _t[1];
        slog::join_probe_old<2,1>(st_hsb_ansindex1743, st_hsb_ansdelta1746, std::array<u64,2>{v_c301, 0}, [&](const std::array<u64,2>& m1764) {
          u64 v_c2 = m1764[1];
          slog::join_probe_old<2,1>(st_hsbindex1744, st_hsbdelta1747, std::array<u64,2>{v_c301, 0}, [&](const std::array<u64,2>& m1765) {
            u64 v_c302 = m1765[1];
            slog::join_all_old<7>($sup9688x40x0x0x1index1745, $sup9688x40x0x0x1delta1748, [&](const std::array<u64,7>& m1766) {
              u64 v_c228 = m1766[0]; u64 v_c4 = m1766[1]; u64 v_c28 = m1766[2]; u64 v_c8 = m1766[3]; u64 v_c9 = m1766[4]; u64 v_c10 = m1766[5]; u64 v_c11 = m1766[6];
              u64 v_c303 = _prim_bxor(db, v_c8, v_c9);
              if (v_c303 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
              if (v_c302 != v_c303) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c228, v_c4, v_c3, v_c2, v_c28, v_c301, v_c301, v_c8, v_c9, v_c10, v_c11}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1749* _cont = new ReadTask1749(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1749(db,b), false);
  // (crule (pre (let __tconst3q0e391 const5feceb66ffc86f38d952786c)) (scan pbranch __t4x1d388 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t4x1d388 __t3g0Z390 __t91mZ389) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t91mZ389 p m l r) (cmp lt n m) (let __t2V1B392 (band q m)) (cmp gt __t2V1B392 __tconst3q0e391)) (head (emit $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) __t3g0Z390 r l m n p q u v)) set.slog:143 #f)
  class ReadTask1771 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1767;  slog::Index** pbranchindex1768;  slog::Index** st_diffdelta1769;  slog::Index** pbranchdelta1770;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord1772({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1773 = db->getRelation("$sup9688x142x0x0x0");
      head_index[0] = readrel1773->getIndex(ord1772, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1774({2, 0, 1});
      slog::Relation* readrel1775 = db->getRelation("st_diff");
      st_diffindex1767 = readrel1775->getIndex(ord1774, false);
      std::vector<u16> ord1776({2, 0, 1});
      slog::Relation* readrel1777 = db->getRelation("st_diff");
      st_diffdelta1769 = readrel1777->getIndex(ord1776, true);
      std::vector<u16> ord1778({0, 1, 2, 3, 4});
      slog::Relation* readrel1779 = db->getRelation("pbranch");
      pbranchindex1768 = readrel1779->getIndex(ord1778, false);
      std::vector<u16> ord1780({0, 1, 2, 3, 4});
      slog::Relation* readrel1781 = db->getRelation("pbranch");
      pbranchdelta1770 = readrel1781->getIndex(ord1780, true);
  
    }
    ReadTask1771(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c304 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c305 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c37 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex1767, st_diffdelta1769, std::array<u64,3>{v_c305, 0, 0}, [&](const std::array<u64,3>& m1782) {
          u64 v_c306 = m1782[1]; u64 v_c307 = m1782[2];
          slog::join_probe_old<5,1>(pbranchindex1768, pbranchdelta1770, std::array<u64,5>{v_c307, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1783) {
            u64 v_c21 = m1783[1]; u64 v_c22 = m1783[2]; u64 v_c23 = m1783[3]; u64 v_c24 = m1783[4];
            u64 v_c308 = _prim_lt(db, v_c34, v_c22);
            if (v_c308 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c308) return;
            u64 v_c309 = _prim_band(db, v_c35, v_c22);
            if (v_c309 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            u64 v_c310 = _prim_gt(db, v_c309, v_c304);
            if (v_c310 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c310) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c306, v_c24, v_c23, v_c22, v_c34, v_c21, v_c35, v_c36, v_c37}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1771* _cont = new ReadTask1771(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1771(db,b), false);
  // (crule (pre) (scan st_union __t8LrU429 s __t65ux428) (body (exists st_ins (1 2 0) 1 s) (join pleaf (0 1) 1 __t65ux428 k) (join-old st_ins (1 2 0) 2 (1 2 0) s k __t7Z9l430) (join st_ins_ans (0 1) 1 __t7Z9l430 r)) (head (emit st_union_ans (0 1) __t8LrU429 r)) set.slog:99 #f)
  class ReadTask1791 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1786;  slog::Index** pleafindex1787;  slog::Index** st_insindex1788;  slog::Index** st_ins_ansindex1789;  slog::Index** st_insdelta1790;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1792({0, 1});
      slog::Relation* readrel1793 = db->getRelation("st_union_ans");
      head_index[0] = readrel1793->getIndex(ord1792, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord1794({1, 2, 0});
      slog::Relation* readrel1795 = db->getRelation("st_ins");
      st_insindex1786 = readrel1795->getIndex(ord1794, false);
      std::vector<u16> ord1796({0, 1});
      slog::Relation* readrel1797 = db->getRelation("pleaf");
      pleafindex1787 = readrel1797->getIndex(ord1796, false);
      std::vector<u16> ord1798({1, 2, 0});
      slog::Relation* readrel1799 = db->getRelation("st_ins");
      st_insindex1788 = readrel1799->getIndex(ord1798, false);
      std::vector<u16> ord1800({1, 2, 0});
      slog::Relation* readrel1801 = db->getRelation("st_ins");
      st_insdelta1790 = readrel1801->getIndex(ord1800, true);
      std::vector<u16> ord1802({0, 1});
      slog::Relation* readrel1803 = db->getRelation("st_ins_ans");
      st_ins_ansindex1789 = readrel1803->getIndex(ord1802, false);
  
    }
    ReadTask1791(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c311 = _t[0];
        u64 v_c183 = _t[1];
        u64 v_c312 = _t[2];
        if (!slog::exists_probe<3,1>(st_insindex1786, std::array<u64,3>{v_c183, 0, 0})) return;
        slog::join_probe<2,1>(pleafindex1787, std::array<u64,2>{v_c312, 0}, [&](const std::array<u64,2>& m1804) {
          u64 v_c20 = m1804[1];
          slog::join_probe_old<3,2>(st_insindex1788, st_insdelta1790, std::array<u64,3>{v_c183, v_c20, 0}, [&](const std::array<u64,3>& m1805) {
            u64 v_c313 = m1805[2];
            slog::join_probe<2,1>(st_ins_ansindex1789, std::array<u64,2>{v_c313, 0}, [&](const std::array<u64,2>& m1806) {
              u64 v_c24 = m1806[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c311, v_c24}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask1791* _cont = new ReadTask1791(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1791(db,b), false);
  // (crule (pre (let __trid8WsX956 const7ce11965015db325c92ba444) (let __trel6oYN957 const1d9eff40314d54862fee3942) (let __tcol5Xl7958 const6b86b273ff34fce19d6b804e) (let __trel6zG2959 const66633592860a63ea6408b433) (let __tcol9PA6960 const5feceb66ffc86f38d952786c) (let __trel4g4E961 const66633592860a63ea6408b433) (let __tcol4JFu962 const6b86b273ff34fce19d6b804e) (let __trel4QJ7963 const66633592860a63ea6408b433) (let __tcol5Qy1964 constd4735e3a265e16eee03f5971) (let __trel2wFK965 const66633592860a63ea6408b433) (let __tcol0kER966 const4e07408562bedb8b60ce05c1)) (scan $sup9688x148x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8WsX956 __trel6oYN957 __tcol5Xl7958 (1 2 3 4 0)) (tycheck p (accept int) __trid8WsX956 __trel6zG2959 __tcol9PA6960 (1 2 3 4 0)) (tycheck m (accept int) __trid8WsX956 __trel4g4E961 __tcol4JFu962 (1 2 3 4 0)) (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8WsX956 __trel4QJ7963 __tcol5Qy1964 (1 2 3 4 0)) (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8WsX956 __trel2wFK965 __tcol0kER966 (1 2 3 4 0)) (emit-temp temp3LID1346 l m p r u) (mkstruct pbranch (1 2 3 4 0) __t16OH277 p m l r)) set.slog:149 #f)
  class ReadTask1810 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1808;  u32 sid1807;  u32 sid1809;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp3LID1346");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x148x0x0x0");
      sid1808 = db->getRelation("_enum")->getStructId();
      sid1807 = db->getRelation("pbranch")->getStructId();
      sid1809 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1810(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c314 = v_const7ce11965015db325c92ba444;
      u64 v_c315 = v_const1d9eff40314d54862fee3942;
      u64 v_c316 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c317 = v_const66633592860a63ea6408b433;
      u64 v_c318 = v_const5feceb66ffc86f38d952786c;
      u64 v_c319 = v_const66633592860a63ea6408b433;
      u64 v_c320 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c321 = v_const66633592860a63ea6408b433;
      u64 v_c322 = v_constd4735e3a265e16eee03f5971;
      u64 v_c323 = v_const66633592860a63ea6408b433;
      u64 v_c324 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c28 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c35 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c36 = _t[7];
        u64 v_c37 = _t[8];
        ++_fires;
        if (!((is_struct(v_c36) && (decode_struct_id(v_c36) == sid1807 || decode_struct_id(v_c36) == sid1808 || decode_struct_id(v_c36) == sid1809))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c314, v_c315, v_c316, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c21)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c314, v_c317, v_c318, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c314, v_c319, v_c320, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid1807 || decode_struct_id(v_c23) == sid1808 || decode_struct_id(v_c23) == sid1809))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c314, v_c321, v_c322, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid1807 || decode_struct_id(v_c24) == sid1808 || decode_struct_id(v_c24) == sid1809))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c314, v_c323, v_c324, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c23, v_c22, v_c21, v_c24, v_c36});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c21, v_c22, v_c23, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:$sup9688x148x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1810* _cont = new ReadTask1810(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1810(db,b), false);
  // (crule (pre) (scan temp8c8A1414 __t1yUC575 __t6hEH570 __t7Tml573) (body (let __t5cKm574 (_0002a __t7Tml573 __t6hEH570))) (head (emit-temp temp00v81415 __t1yUC575 __t5cKm574)) set.slog:33 #f)
  class ReadTask1811 : public slog::Task
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
      head_rel[0] = db->getRelation("temp00v81415");
      outer_rel = db->getRelation("temp8c8A1414");
  
    }
    ReadTask1811(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c325 = _t[0];
        u64 v_c326 = _t[1];
        u64 v_c327 = _t[2];
        u64 v_c328 = _prim__0002a(db, v_c327, v_c326);
        if (v_c328 == slog_error) { slog::emit_pending_error(db, "set.slog:33"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c325, v_c328});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:33", "delta:temp8c8A1414", _fires);
  
      if (!_done)
      {
        ReadTask1811* _cont = new ReadTask1811(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1811(db,b), false);
}

