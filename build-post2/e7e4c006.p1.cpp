
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1d9eff40314d54862fee3942;
extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_conste5e223bf70bc83faf3ce3a31;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf2664e0abda1016213c9fa90;


void slog_rules_c823fae8cf812f2da(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_hsb __t75bg356 __t5oQR360) (body (exists st_hsb_ans (0 1) 1 __t75bg356) (exists $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t75bg356) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 1 __t75bg356) (join st_hsb_ans (0 1) 1 __t75bg356 __v3) (exists $sup9688x36x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t75bg356 __v3) (join st_hsb_ans (0 1) 1 __t75bg356 __v1) (exists $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t75bg356 __v1 __v3) (exists st_msk (2 0 1) 1 __v1) (join st_hsb_ans (0 1) 1 __t75bg356 __v0) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 2 __t75bg356 __v0) (join $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t75bg356 __v0 __v3 __v1 __t0kmv352 dup66Lo1333 dup68E21334 p0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join st_msk (1 2 0) 2 p0 __v1 __t9xbE359) (join st_msk_ans (0 1) 1 __t9xbE359 __v2) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353) (let chk11t41335 (bxor p0 p1)) (eq __t5oQR360 chk11t41335)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex0;  slog::Index** $sup9688x36x0x0x2index1;  slog::Index** $sup9688x36x0x0x1index2;  slog::Index** st_hsb_ansindex3;  slog::Index** $sup9688x36x0x0x2index4;  slog::Index** st_hsb_ansindex5;  slog::Index** $sup9688x36x0x0x2index6;  slog::Index** st_mskindex7;  slog::Index** st_hsb_ansindex8;  slog::Index** $sup9688x36x0x0x1index9;  slog::Index** $sup9688x36x0x0x2index10;  slog::Index** $sup9688x36x0x0x1index11;  slog::Index** $sup9688x36x0x0x0index12;  slog::Index** st_joinindex13;  slog::Index** st_mskindex14;  slog::Index** st_msk_ansindex15;  slog::Index** st_joindelta16;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex0 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel21 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel23 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index2 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex3 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel27 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index4 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex5 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel31 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index6 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({2, 0, 1});
      slog::Relation* readrel33 = db->getRelation("st_msk");
      st_mskindex7 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex8 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel37 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index9 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel39 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index10 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel41 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index11 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0, 2, 3, 4});
      slog::Relation* readrel43 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index12 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 3, 4, 0});
      slog::Relation* readrel45 = db->getRelation("st_join");
      st_joinindex13 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 3, 4, 0});
      slog::Relation* readrel47 = db->getRelation("st_join");
      st_joindelta16 = readrel47->getIndex(ord46, true);
      std::vector<u16> ord48({1, 2, 0});
      slog::Relation* readrel49 = db->getRelation("st_msk");
      st_mskindex14 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("st_msk_ans");
      st_msk_ansindex15 = readrel51->getIndex(ord50, false);
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<11,1>($sup9688x36x0x0x2index1, std::array<u64,11>{v_c1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x36x0x0x1index2, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m52) {
          u64 v_c3 = m52[1];
          if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index4, std::array<u64,11>{v_c1, v_c3, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(st_hsb_ansindex5, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m53) {
            u64 v_c4 = m53[1];
            if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index6, std::array<u64,11>{v_c1, v_c4, v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex7, std::array<u64,3>{v_c4, 0, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex8, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m54) {
              u64 v_c5 = m54[1];
              if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index9, std::array<u64,7>{v_c1, v_c5, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup9688x36x0x0x2index10, std::array<u64,11>{v_c1, v_c5, v_c3, v_c4, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m55) {
                u64 v_c6 = m55[4]; u64 v_c7 = m55[5]; u64 v_c8 = m55[6]; u64 v_c9 = m55[7]; u64 v_c10 = m55[8]; u64 v_c11 = m55[9]; u64 v_c12 = m55[10];
                if (v_c1 != v_c8) return;
                if (v_c1 != v_c7) return;
                slog::join_probe<7,7>($sup9688x36x0x0x1index11, std::array<u64,7>{v_c6, v_c9, v_c10, v_c11, v_c12, v_c1, v_c5}, [&](const std::array<u64,7>& m56) {
                  slog::join_probe<5,5>($sup9688x36x0x0x0index12, std::array<u64,5>{v_c9, v_c6, v_c10, v_c11, v_c12}, [&](const std::array<u64,5>& m57) {
                    slog::join_probe_old<5,5>(st_joinindex13, st_joindelta16, std::array<u64,5>{v_c9, v_c11, v_c10, v_c12, v_c6}, [&](const std::array<u64,5>& m58) {
                      slog::join_probe<3,2>(st_mskindex14, std::array<u64,3>{v_c9, v_c4, 0}, [&](const std::array<u64,3>& m59) {
                        u64 v_c13 = m59[2];
                        slog::join_probe<2,1>(st_msk_ansindex15, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m60) {
                          u64 v_c14 = m60[1];
                          u64 v_c15 = _prim_band(db, v_c9, v_c5);
                          if (v_c15 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c16 = _prim_lt(db, v_c15, v_c0);
                          if (v_c16 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c16) return;
                          u64 v_c17 = _prim_bxor(db, v_c9, v_c10);
                          if (v_c17 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (v_c2 != v_c17) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c6, v_c14, v_c3, v_c11, v_c12});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c14, v_c3, v_c11, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask17* _cont = new ReadTask17(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), false);
  // (crule (pre (let __tconst2CmQ450 const7902699be42c8a8e46fbbb45)) (scan canon s) (body) (head (mkstruct st_ins (1 2 0) __65lD720 s __tconst2CmQ450)) st_basic.slog:25 #f)
  class ReadTask62 : public slog::Task
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
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c19, v_c18}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:25", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask62* _cont = new ReadTask62(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask62(db,b), false);
  // (crule (pre (let __tconst3xtE191 const6b86b273ff34fce19d6b804e)) (scan pbranch __t8Eum189 p m l r) (body (join-old st_union (1 2 0) 1 (1 2 0) __t8Eum189 __t1xmG188 __t1CMK190) (join pbranch (0 1 2 3 4) 1 __t1xmG188 q n u v) (cmp lt n m) (let __t1Yb7192 (band q m)) (cmp lt __t1Yb7192 __tconst3xtE191)) (head (emit $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) __t1CMK190 l m n p q r u v)) set.slog:104 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex63;  slog::Index** pbranchindex64;  slog::Index** st_uniondelta65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord67({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel68 = db->getRelation("$sup9688x103x0x0x0");
      head_index[0] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("st_union");
      st_unionindex63 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("st_union");
      st_uniondelta65 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({0, 1, 2, 3, 4});
      slog::Relation* readrel74 = db->getRelation("pbranch");
      pbranchindex64 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex63, st_uniondelta65, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m75) {
          u64 v_c26 = m75[1]; u64 v_c27 = m75[2];
          slog::join_probe<5,1>(pbranchindex64, std::array<u64,5>{v_c26, 0, 0, 0, 0}, [&](const std::array<u64,5>& m76) {
            u64 v_c28 = m76[1]; u64 v_c29 = m76[2]; u64 v_c30 = m76[3]; u64 v_c31 = m76[4];
            u64 v_c32 = _prim_lt(db, v_c29, v_c23);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c32) return;
            u64 v_c33 = _prim_band(db, v_c28, v_c23);
            if (v_c33 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            u64 v_c34 = _prim_lt(db, v_c33, v_c20);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c34) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c27, v_c24, v_c23, v_c29, v_c22, v_c28, v_c25, v_c30, v_c31}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), false);
  // (crule (pre) (scan pleaf __t1ano193 k) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t1ano193 t __t6McK194)) (head (mkstruct st_mem0 (1 2 0) __2xP61117 t k)) set.slog:135 #f)
  class ReadTask81 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex79;  slog::Index** st_diffdelta80;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("st_diff");
      st_diffindex79 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 2, 0});
      slog::Relation* readrel85 = db->getRelation("st_diff");
      st_diffdelta80 = readrel85->getIndex(ord84, true);
  
    }
    ReadTask81(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(st_diffindex79, st_diffdelta80, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m86) {
          u64 v_c37 = m86[1]; u64 v_c38 = m86[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c37, v_c36}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask81* _cont = new ReadTask81(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask81(db,b), false);
  // (crule (pre) (scan st_union __t5oQM516 __t52IG517 __t1VuF518) (body (join-old st_join (2 4 0 1 3) 2 (2 4 0 1 3) __t52IG517 __t1VuF518 __t3WPW519 p q) (neq p q) (exists pbranch (0 1 2 3 4) 2 __t1VuF518 q) (exists st_join_ans (0 1) 1 __t3WPW519) (join-old pbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t52IG517 p m l r) (join-old pbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t1VuF518 q m u v) (join st_join_ans (0 1) 1 __t3WPW519 res)) (head (emit st_union_ans (0 1) __t5oQM516 res)) set.slog:125 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex87;  slog::Index** pbranchindex88;  slog::Index** st_join_ansindex89;  slog::Index** pbranchindex90;  slog::Index** pbranchindex91;  slog::Index** st_join_ansindex92;  slog::Index** st_joindelta93;  slog::Index** pbranchdelta94;  slog::Index** pbranchdelta95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("st_union_ans");
      head_index[0] = readrel98->getIndex(ord97, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord99({2, 4, 0, 1, 3});
      slog::Relation* readrel100 = db->getRelation("st_join");
      st_joinindex87 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({2, 4, 0, 1, 3});
      slog::Relation* readrel102 = db->getRelation("st_join");
      st_joindelta93 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({0, 1, 2, 3, 4});
      slog::Relation* readrel104 = db->getRelation("pbranch");
      pbranchindex88 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("st_join_ans");
      st_join_ansindex89 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1, 2, 3, 4});
      slog::Relation* readrel108 = db->getRelation("pbranch");
      pbranchindex90 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1, 2, 3, 4});
      slog::Relation* readrel110 = db->getRelation("pbranch");
      pbranchdelta94 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({0, 1, 2, 3, 4});
      slog::Relation* readrel112 = db->getRelation("pbranch");
      pbranchindex91 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 1, 2, 3, 4});
      slog::Relation* readrel114 = db->getRelation("pbranch");
      pbranchdelta95 = readrel114->getIndex(ord113, true);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("st_join_ans");
      st_join_ansindex92 = readrel116->getIndex(ord115, false);
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c41 = _t[2];
        slog::join_probe_old<5,2>(st_joinindex87, st_joindelta93, std::array<u64,5>{v_c40, v_c41, 0, 0, 0}, [&](const std::array<u64,5>& m117) {
          u64 v_c42 = m117[2]; u64 v_c22 = m117[3]; u64 v_c28 = m117[4];
          if (v_c22 == v_c28) return;
          if (!slog::exists_probe<5,2>(pbranchindex88, std::array<u64,5>{v_c41, v_c28, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex89, std::array<u64,2>{v_c42, 0})) return;
          slog::join_probe_old<5,2>(pbranchindex90, pbranchdelta94, std::array<u64,5>{v_c40, v_c22, 0, 0, 0}, [&](const std::array<u64,5>& m118) {
            u64 v_c23 = m118[2]; u64 v_c24 = m118[3]; u64 v_c25 = m118[4];
            slog::join_probe_old<5,3>(pbranchindex91, pbranchdelta95, std::array<u64,5>{v_c41, v_c28, v_c23, 0, 0}, [&](const std::array<u64,5>& m119) {
              u64 v_c30 = m119[3]; u64 v_c31 = m119[4];
              slog::join_probe<2,1>(st_join_ansindex92, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m120) {
                u64 v_c43 = m120[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c39, v_c43}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst6ZQr51 __t7CuH52 __v1) (body (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins_ans (1 0) 1 __v1) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_ins_ans (0 1) 1 __t7CuH52) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join st_ins (1 2 0) 2 __t7Lp349 __tconst7TTg43 __t8j8m45) (exists st_ins_ans (0 1) 1 __t8j8m45) (join st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48 __t3nMl50) (join st_ins_ans (0 1) 2 __t3nMl50 __v1) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join st_ins (1 2 0) 2 __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join st_ins_ans (0 1) 1 __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join st_union_ans (0 1) 1 __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask140 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex121;  slog::Index** st_insindex122;  slog::Index** st_ins_ansindex123;  slog::Index** st_insindex124;  slog::Index** st_ins_ansindex125;  slog::Index** _enumindex126;  slog::Index** st_insindex127;  slog::Index** st_insindex128;  slog::Index** st_ins_ansindex129;  slog::Index** st_insindex130;  slog::Index** st_ins_ansindex131;  slog::Index** st_ins_ansindex132;  slog::Index** st_insindex133;  slog::Index** st_ins_ansindex134;  slog::Index** st_unionindex135;  slog::Index** st_ins_ansindex136;  slog::Index** st_unionindex137;  slog::Index** st_union_ansindex138;  slog::Index** st_uniondelta139;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord141({0});
      slog::Relation* readrel142 = db->getRelation("canon");
      head_index[0] = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({2, 0, 1});
      slog::Relation* readrel144 = db->getRelation("st_ins");
      driver_index = readrel144->getIndex(ord143, true);
      std::vector<u16> ord145({2, 0, 1});
      slog::Relation* readrel146 = db->getRelation("st_ins");
      st_insindex121 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({2, 0, 1});
      slog::Relation* readrel148 = db->getRelation("st_ins");
      st_insindex122 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("st_ins_ans");
      st_ins_ansindex123 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 0, 1});
      slog::Relation* readrel152 = db->getRelation("st_ins");
      st_insindex124 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({0, 1});
      slog::Relation* readrel154 = db->getRelation("st_ins_ans");
      st_ins_ansindex125 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("_enum");
      _enumindex126 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("st_ins");
      st_insindex127 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("st_ins");
      st_insindex128 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0, 1});
      slog::Relation* readrel162 = db->getRelation("st_ins_ans");
      st_ins_ansindex129 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("st_ins");
      st_insindex130 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("st_ins_ans");
      st_ins_ansindex131 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("st_ins_ans");
      st_ins_ansindex132 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("st_ins");
      st_insindex133 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("st_ins_ans");
      st_ins_ansindex134 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("st_union");
      st_unionindex135 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("st_ins_ans");
      st_ins_ansindex136 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("st_union");
      st_unionindex137 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 0});
      slog::Relation* readrel180 = db->getRelation("st_union");
      st_uniondelta139 = readrel180->getIndex(ord179, true);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("st_union_ans");
      st_union_ansindex138 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c45 = v_constef2d127de37b942baad06145;
      u64 v_c46 = v_const2c624232cdd221771294dfbb;
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c48, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m183) {
        u64 v_c49 = m183[1];
        u64 v_c4 = m183[2];
        if (buckethash(v_c49) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex121, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex122, std::array<u64,3>{v_c47, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex123, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex124, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex125, std::array<u64,2>{v_c49, 0})) return;
        slog::join_probe<2,1>(_enumindex126, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m184) {
          u64 v_c50 = m184[1];
          if (!slog::exists_probe<3,2>(st_insindex127, std::array<u64,3>{v_c50, v_c47, 0})) return;
          slog::join_probe<3,2>(st_insindex128, std::array<u64,3>{v_c50, v_c45, 0}, [&](const std::array<u64,3>& m185) {
            u64 v_c51 = m185[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex129, std::array<u64,2>{v_c51, 0})) return;
            slog::join_probe<3,2>(st_insindex130, std::array<u64,3>{v_c50, v_c47, 0}, [&](const std::array<u64,3>& m186) {
              u64 v_c52 = m186[2];
              slog::join_probe<2,2>(st_ins_ansindex131, std::array<u64,2>{v_c52, v_c4}, [&](const std::array<u64,2>& m187) {
                slog::join_probe<2,1>(st_ins_ansindex132, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m188) {
                  u64 v_c5 = m188[1];
                  slog::join_probe<3,2>(st_insindex133, std::array<u64,3>{v_c5, v_c46, 0}, [&](const std::array<u64,3>& m189) {
                    u64 v_c53 = m189[2];
                    slog::join_probe<2,1>(st_ins_ansindex134, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m190) {
                      u64 v_c54 = m190[1];
                      if (!slog::exists_probe<3,1>(st_unionindex135, std::array<u64,3>{v_c54, 0, 0})) return;
                      slog::join_probe<2,1>(st_ins_ansindex136, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m191) {
                        u64 v_c55 = m191[1];
                        slog::join_probe_old<3,2>(st_unionindex137, st_uniondelta139, std::array<u64,3>{v_c54, v_c55, 0}, [&](const std::array<u64,3>& m192) {
                          u64 v_c56 = m192[2];
                          slog::join_probe<2,1>(st_union_ansindex138, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m193) {
                            u64 v_c25 = m193[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
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
        ReadTask140* _cont = new ReadTask140(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask140(db,b), false);
  // (crule (pre) (scan temp4PCZ1408 n q r u v) (body (join pbranch (1 2 3 4 0) 4 q n u v __t3E7r174)) (head (mkstruct st_diff (1 2 0) __0ANf1074 r __t3E7r174)) set.slog:143 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff");
      outer_rel = db->getRelation("temp4PCZ1408");
      std::vector<u16> ord196({1, 2, 3, 4, 0});
      slog::Relation* readrel197 = db->getRelation("pbranch");
      pbranchindex194 = readrel197->getIndex(ord196, false);
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        slog::join_probe<5,4>(pbranchindex194, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m198) {
          u64 v_c57 = m198[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c57}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:temp4PCZ1408", _fires);
  
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
  // (crule (pre (let __tconst6iyh571 constd4735e3a265e16eee03f5971)) (scan st_msk __t1yUC575 k m) (body (let __t6hEH570 (_0002a __tconst6iyh571 m))) (head (emit-temp temp44eI1413 __t1yUC575 __t6hEH570 k)) set.slog:33 #f)
  class ReadTask199 : public slog::Task
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
      head_rel[0] = db->getRelation("temp44eI1413");
      outer_rel = db->getRelation("st_msk");
  
    }
    ReadTask199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c60 = _prim__0002a(db, v_c58, v_c23);
        if (v_c60 == slog_error) { slog::emit_pending_error(db, "set.slog:33"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c59, v_c60, v_c36});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:33", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask199* _cont = new ReadTask199(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask199(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_bld __t7XLn338 p m l __v0) (body (exists $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 3 p l m) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join pbranch (1 2 3 4 0) 3 p m l r __t88zt334) (exists st_diff (1 2 0) 1 __t88zt334) (exists st_diff (1 2 0) 1 r) (join $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 4 p l m r __t8Fy1335 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join st_diff (0 1 2) 3 __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join st_diff_ans (0 1) 2 __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask222 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index200;  slog::Index** st_mskindex201;  slog::Index** st_msk_ansindex202;  slog::Index** st_diff_ansindex203;  slog::Index** st_bld_ansindex204;  slog::Index** pbranchindex205;  slog::Index** st_diffindex206;  slog::Index** st_diffindex207;  slog::Index** $sup9688x142x0x0x0index208;  slog::Index** st_diffindex209;  slog::Index** st_mskindex210;  slog::Index** pbranchindex211;  slog::Index** st_diffindex212;  slog::Index** st_diffindex213;  slog::Index** st_mskindex214;  slog::Index** st_msk_ansindex215;  slog::Index** st_diffindex216;  slog::Index** st_diff_ansindex217;  slog::Index** st_bld_ansindex218;  slog::Index** pbranchdelta219;  slog::Index** st_mskdelta220;  slog::Index** st_diffdelta221;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord223({0, 1});
      slog::Relation* readrel224 = db->getRelation("st_diff_ans");
      head_index[0] = readrel224->getIndex(ord223, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord225({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel226 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index200 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({2, 0, 1});
      slog::Relation* readrel228 = db->getRelation("st_msk");
      st_mskindex201 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 0});
      slog::Relation* readrel230 = db->getRelation("st_msk_ans");
      st_msk_ansindex202 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("st_diff_ans");
      st_diff_ansindex203 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("st_bld_ans");
      st_bld_ansindex204 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 2, 3, 4, 0});
      slog::Relation* readrel236 = db->getRelation("pbranch");
      pbranchindex205 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("st_diff");
      st_diffindex206 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 0});
      slog::Relation* readrel240 = db->getRelation("st_diff");
      st_diffindex207 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel242 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index208 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1, 2});
      slog::Relation* readrel244 = db->getRelation("st_diff");
      st_diffindex209 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 2, 0});
      slog::Relation* readrel246 = db->getRelation("st_msk");
      st_mskindex210 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 2, 3, 4, 0});
      slog::Relation* readrel248 = db->getRelation("pbranch");
      pbranchindex211 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 3, 4, 0});
      slog::Relation* readrel250 = db->getRelation("pbranch");
      pbranchdelta219 = readrel250->getIndex(ord249, true);
      std::vector<u16> ord251({0, 1, 2});
      slog::Relation* readrel252 = db->getRelation("st_diff");
      st_diffindex212 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 2, 0});
      slog::Relation* readrel254 = db->getRelation("st_diff");
      st_diffindex213 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("st_msk");
      st_mskindex214 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 2, 0});
      slog::Relation* readrel258 = db->getRelation("st_msk");
      st_mskdelta220 = readrel258->getIndex(ord257, true);
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("st_msk_ans");
      st_msk_ansindex215 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 0});
      slog::Relation* readrel262 = db->getRelation("st_diff");
      st_diffindex216 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("st_diff");
      st_diffdelta221 = readrel264->getIndex(ord263, true);
      std::vector<u16> ord265({0, 1});
      slog::Relation* readrel266 = db->getRelation("st_diff_ans");
      st_diff_ansindex217 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({0, 1});
      slog::Relation* readrel268 = db->getRelation("st_bld_ans");
      st_bld_ansindex218 = readrel268->getIndex(ord267, false);
  
    }
    ReadTask222(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c62 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<9,3>($sup9688x142x0x0x0index200, std::array<u64,9>{v_c22, v_c24, v_c23, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex201, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex202, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_diff_ansindex203, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(st_bld_ansindex204, std::array<u64,2>{v_c62, 0})) return;
        slog::join_probe<5,3>(pbranchindex205, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0}, [&](const std::array<u64,5>& m269) {
          u64 v_c25 = m269[3]; u64 v_c63 = m269[4];
          if (!slog::exists_probe<3,1>(st_diffindex206, std::array<u64,3>{v_c63, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex207, std::array<u64,3>{v_c25, 0, 0})) return;
          slog::join_probe<9,4>($sup9688x142x0x0x0index208, std::array<u64,9>{v_c22, v_c24, v_c23, v_c25, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m270) {
            u64 v_c64 = m270[4]; u64 v_c29 = m270[5]; u64 v_c28 = m270[6]; u64 v_c30 = m270[7]; u64 v_c31 = m270[8];
            u64 v_c65 = _prim_lt(db, v_c29, v_c23);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c65) return;
            if (!slog::exists_probe<3,2>(st_diffindex209, std::array<u64,3>{v_c64, v_c63, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex210, std::array<u64,3>{v_c28, v_c23, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex211, pbranchdelta219, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m272) {
              u64 v_c66 = m272[4];
              slog::join_probe<3,3>(st_diffindex212, std::array<u64,3>{v_c64, v_c63, v_c66}, [&](const std::array<u64,3>& m273) {
                if (!slog::exists_probe<3,2>(st_diffindex213, std::array<u64,3>{v_c25, v_c66, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex214, st_mskdelta220, std::array<u64,3>{v_c28, v_c23, 0}, [&](const std::array<u64,3>& m274) {
                  u64 v_c67 = m274[2];
                  slog::join_probe<2,2>(st_msk_ansindex215, std::array<u64,2>{v_c67, v_c22}, [&](const std::array<u64,2>& m275) {
                    slog::join_probe_old<3,2>(st_diffindex216, st_diffdelta221, std::array<u64,3>{v_c25, v_c66, 0}, [&](const std::array<u64,3>& m276) {
                      u64 v_c68 = m276[2];
                      slog::join_probe<2,2>(st_diff_ansindex217, std::array<u64,2>{v_c68, v_c5}, [&](const std::array<u64,2>& m277) {
                        slog::join_probe<2,1>(st_bld_ansindex218, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m278) {
                          u64 v_c43 = m278[1];
                          u64 v_c69 = _prim_band(db, v_c28, v_c23);
                          if (v_c69 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c70 = _prim_gt(db, v_c69, v_c61);
                          if (v_c70 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c70) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c43}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask222* _cont = new ReadTask222(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask222(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst2ksI386 __t7LWC387 __v2) (body (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins (2 0 1) 1 __tconst7Eph382) (exists st_ins (2 0 1) 1 __tconst4emd384) (exists st_ins_ans (1 0) 1 __v2) (exists st_ins_ans (0 1) 1 __t7LWC387) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join st_ins (1 2 0) 2 __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 1 __t2Q6o381 __v0) (join st_ins (1 2 0) 2 __v0 __tconst7Eph382 __t0FtX383) (join st_ins_ans (0 1) 1 __t0FtX383 __v1) (join st_ins (1 2 0) 2 __v1 __tconst4emd384 __t88YX385) (join st_ins_ans (0 1) 2 __t88YX385 __v2) (join st_ins_ans (0 1) 1 __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask293 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex280;  slog::Index** st_insindex281;  slog::Index** st_insindex282;  slog::Index** st_ins_ansindex283;  slog::Index** st_ins_ansindex284;  slog::Index** _enumindex285;  slog::Index** st_insindex286;  slog::Index** st_ins_ansindex287;  slog::Index** st_insindex288;  slog::Index** st_ins_ansindex289;  slog::Index** st_insindex290;  slog::Index** st_ins_ansindex291;  slog::Index** st_ins_ansindex292;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord294({0});
      slog::Relation* readrel295 = db->getRelation("canon");
      head_index[0] = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({2, 0, 1});
      slog::Relation* readrel297 = db->getRelation("st_ins");
      driver_index = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({2, 0, 1});
      slog::Relation* readrel299 = db->getRelation("st_ins");
      st_insindex280 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({2, 0, 1});
      slog::Relation* readrel301 = db->getRelation("st_ins");
      st_insindex281 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({2, 0, 1});
      slog::Relation* readrel303 = db->getRelation("st_ins");
      st_insindex282 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("st_ins_ans");
      st_ins_ansindex283 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("st_ins_ans");
      st_ins_ansindex284 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 0});
      slog::Relation* readrel309 = db->getRelation("_enum");
      _enumindex285 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("st_ins");
      st_insindex286 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("st_ins_ans");
      st_ins_ansindex287 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("st_ins");
      st_insindex288 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("st_ins_ans");
      st_ins_ansindex289 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("st_ins");
      st_insindex290 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1});
      slog::Relation* readrel321 = db->getRelation("st_ins_ans");
      st_ins_ansindex291 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("st_ins_ans");
      st_ins_ansindex292 = readrel323->getIndex(ord322, false);
  
    }
    ReadTask293(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const2c624232cdd221771294dfbb;
      u64 v_c74 = v_constd4735e3a265e16eee03f5971;
      u64 v_c75 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c75, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m324) {
        u64 v_c76 = m324[1];
        u64 v_c14 = m324[2];
        if (buckethash(v_c76) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex280, std::array<u64,3>{v_c72, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex281, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex282, std::array<u64,3>{v_c74, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex283, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex284, std::array<u64,2>{v_c76, 0})) return;
        slog::join_probe<2,1>(_enumindex285, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m325) {
          u64 v_c77 = m325[1];
          slog::join_probe<3,2>(st_insindex286, std::array<u64,3>{v_c77, v_c72, 0}, [&](const std::array<u64,3>& m326) {
            u64 v_c78 = m326[2];
            slog::join_probe<2,1>(st_ins_ansindex287, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m327) {
              u64 v_c5 = m327[1];
              slog::join_probe<3,2>(st_insindex288, std::array<u64,3>{v_c5, v_c73, 0}, [&](const std::array<u64,3>& m328) {
                u64 v_c79 = m328[2];
                slog::join_probe<2,1>(st_ins_ansindex289, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m329) {
                  u64 v_c4 = m329[1];
                  slog::join_probe<3,2>(st_insindex290, std::array<u64,3>{v_c4, v_c74, 0}, [&](const std::array<u64,3>& m330) {
                    u64 v_c80 = m330[2];
                    slog::join_probe<2,2>(st_ins_ansindex291, std::array<u64,2>{v_c80, v_c14}, [&](const std::array<u64,2>& m331) {
                      slog::join_probe<2,1>(st_ins_ansindex292, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m332) {
                        u64 v_c25 = m332[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
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
        ReadTask293* _cont = new ReadTask293(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask293(db,b), false);
  // (crule (pre) (scan st_msk_ans __t8BWG393 p) (body (exists $sup9688x103x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t8BWG393 q m) (join $sup9688x103x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t8BWG393 m n p q r u v)) set.slog:104 #f)
  class ReadTask337 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x0index333;  slog::Index** st_mskindex334;  slog::Index** $sup9688x103x0x0x0index335;  slog::Index** st_mskdelta336;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord338({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel339 = db->getRelation("$sup9688x103x0x0x1");
      head_index[0] = readrel339->getIndex(ord338, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord340({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel341 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index333 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1, 2});
      slog::Relation* readrel343 = db->getRelation("st_msk");
      st_mskindex334 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0, 1, 2});
      slog::Relation* readrel345 = db->getRelation("st_msk");
      st_mskdelta336 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel347 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index335 = readrel347->getIndex(ord346, false);
  
    }
    ReadTask337(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c81 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x103x0x0x0index333, std::array<u64,9>{v_c22, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex334, st_mskdelta336, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m348) {
          u64 v_c28 = m348[1]; u64 v_c23 = m348[2];
          slog::join_probe<9,3>($sup9688x103x0x0x0index335, std::array<u64,9>{v_c23, v_c28, v_c22, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m349) {
            u64 v_c82 = m349[3]; u64 v_c24 = m349[4]; u64 v_c29 = m349[5]; u64 v_c25 = m349[6]; u64 v_c30 = m349[7]; u64 v_c31 = m349[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c82, v_c24, v_c81, v_c23, v_c29, v_c22, v_c28, v_c25, v_c30, v_c31}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask337* _cont = new ReadTask337(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask337(db,b), false);
  // (crule (pre (let __trid0RNT826 constf2664e0abda1016213c9fa90) (let __trel8eZH827 const1d9eff40314d54862fee3942) (let __tcol2bR9828 const5feceb66ffc86f38d952786c) (let __trel9V7Z829 const1d9eff40314d54862fee3942) (let __tcol4n7g830 const6b86b273ff34fce19d6b804e)) (scan $sup9688x136x0x0x0 __d0 l m p r u v) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0RNT826 __trel8eZH827 __tcol2bR9828 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0RNT826 __trel9V7Z829 __tcol4n7g830 (1 2 3 4 0)) (mkstruct st_diff (1 2 0) __16KM825 l u)) set.slog:137 #f)
  class ReadTask353 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid351;  u32 sid350;  u32 sid352;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_diff");
      outer_rel = db->getRelation("$sup9688x136x0x0x0");
      sid351 = db->getRelation("_enum")->getStructId();
      sid350 = db->getRelation("pbranch")->getStructId();
      sid352 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask353(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_constf2664e0abda1016213c9fa90;
      u64 v_c84 = v_const1d9eff40314d54862fee3942;
      u64 v_c85 = v_const5feceb66ffc86f38d952786c;
      u64 v_c86 = v_const1d9eff40314d54862fee3942;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c82 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c30 = _t[5];
        u64 v_c31 = _t[6];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid350 || decode_struct_id(v_c24) == sid351 || decode_struct_id(v_c24) == sid352))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c83, v_c84, v_c85, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c30) && (decode_struct_id(v_c30) == sid350 || decode_struct_id(v_c30) == sid351 || decode_struct_id(v_c30) == sid352))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c83, v_c86, v_c87, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c24, v_c30}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:$sup9688x136x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask353* _cont = new ReadTask353(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask353(db,b), false);
  // (crule (pre (let __tconst9k1p217 const6b86b273ff34fce19d6b804e)) (scan pbranch __t1kmq214 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t1kmq214 __t0V4b216 __t3Raq215) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3Raq215 p m l r) (cmp lt n m) (let __t76JX218 (band q m)) (cmp lt __t76JX218 __tconst9k1p217)) (head (emit $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) __t0V4b216 l m n p q r u v)) set.slog:140 #f)
  class ReadTask358 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex354;  slog::Index** pbranchindex355;  slog::Index** st_diffdelta356;  slog::Index** pbranchdelta357;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord359({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel360 = db->getRelation("$sup9688x139x0x0x0");
      head_index[0] = readrel360->getIndex(ord359, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord361({2, 0, 1});
      slog::Relation* readrel362 = db->getRelation("st_diff");
      st_diffindex354 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({2, 0, 1});
      slog::Relation* readrel364 = db->getRelation("st_diff");
      st_diffdelta356 = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({0, 1, 2, 3, 4});
      slog::Relation* readrel366 = db->getRelation("pbranch");
      pbranchindex355 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 1, 2, 3, 4});
      slog::Relation* readrel368 = db->getRelation("pbranch");
      pbranchdelta357 = readrel368->getIndex(ord367, true);
  
    }
    ReadTask358(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c89 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex354, st_diffdelta356, std::array<u64,3>{v_c89, 0, 0}, [&](const std::array<u64,3>& m369) {
          u64 v_c90 = m369[1]; u64 v_c91 = m369[2];
          slog::join_probe_old<5,1>(pbranchindex355, pbranchdelta357, std::array<u64,5>{v_c91, 0, 0, 0, 0}, [&](const std::array<u64,5>& m370) {
            u64 v_c22 = m370[1]; u64 v_c23 = m370[2]; u64 v_c24 = m370[3]; u64 v_c25 = m370[4];
            u64 v_c92 = _prim_lt(db, v_c29, v_c23);
            if (v_c92 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c92) return;
            u64 v_c93 = _prim_band(db, v_c28, v_c23);
            if (v_c93 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            u64 v_c94 = _prim_lt(db, v_c93, v_c88);
            if (v_c94 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c94) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c90, v_c24, v_c23, v_c29, v_c22, v_c28, v_c25, v_c30, v_c31}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask358* _cont = new ReadTask358(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask358(db,b), false);
  // (crule (pre (let __trid5ToT1057 conste5e223bf70bc83faf3ce3a31) (let __trel3z0S1058 consta10f76b4ec574de5d7b6908e) (let __tcol3Npx1059 const5feceb66ffc86f38d952786c) (let __trel5wyd1060 consta10f76b4ec574de5d7b6908e) (let __tcol2ESx1061 const6b86b273ff34fce19d6b804e)) (scan $sup9688x154x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid5ToT1057 __trel3z0S1058 __tcol3Npx1059 (1 2 3 4 0)) (tycheck n (accept int) __trid5ToT1057 __trel5wyd1060 __tcol2ESx1061 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __2YGI1056 p n)) set.slog:155 #f)
  class ReadTask373 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x154x0x0x0");
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_conste5e223bf70bc83faf3ce3a31;
      u64 v_c96 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c97 = v_const5feceb66ffc86f38d952786c;
      u64 v_c98 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c82 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c22 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c30 = _t[7];
        u64 v_c31 = _t[8];
        ++_fires;
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c95, v_c96, v_c97, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c29)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c95, v_c98, v_c99, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c22, v_c29}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:$sup9688x154x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask373* _cont = new ReadTask373(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask373(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_del __t3j4h490 __t4hkT489 k) (body (exists st_msk (1 2 0) 1 k) (exists st_del (2 0 1) 1 k) (join $sup9688x90x0x0x0 (0 1 2 3 4 5) 2 __t3j4h490 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t4hkT489) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 r k) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8CKV493) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join st_del_ans (0 1) 2 __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask392 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex374;  slog::Index** st_delindex375;  slog::Index** $sup9688x90x0x0x0index376;  slog::Index** pbranchindex377;  slog::Index** st_mskindex378;  slog::Index** st_msk_ansindex379;  slog::Index** st_delindex380;  slog::Index** st_bldindex381;  slog::Index** st_del_ansindex382;  slog::Index** st_bld_ansindex383;  slog::Index** st_mskindex384;  slog::Index** st_msk_ansindex385;  slog::Index** st_delindex386;  slog::Index** st_del_ansindex387;  slog::Index** st_bld_ansindex388;  slog::Index** st_blddelta389;  slog::Index** st_mskdelta390;  slog::Index** st_deldelta391;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("st_del_ans");
      head_index[0] = readrel394->getIndex(ord393, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("st_msk");
      st_mskindex374 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({2, 0, 1});
      slog::Relation* readrel398 = db->getRelation("st_del");
      st_delindex375 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel400 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index376 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 3, 4, 0});
      slog::Relation* readrel402 = db->getRelation("pbranch");
      pbranchindex377 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("st_msk");
      st_mskindex378 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 0});
      slog::Relation* readrel406 = db->getRelation("st_msk_ans");
      st_msk_ansindex379 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 0});
      slog::Relation* readrel408 = db->getRelation("st_del");
      st_delindex380 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 3, 4, 0});
      slog::Relation* readrel410 = db->getRelation("st_bld");
      st_bldindex381 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 3, 4, 0});
      slog::Relation* readrel412 = db->getRelation("st_bld");
      st_blddelta389 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({1, 0});
      slog::Relation* readrel414 = db->getRelation("st_del_ans");
      st_del_ansindex382 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("st_bld_ans");
      st_bld_ansindex383 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("st_msk");
      st_mskindex384 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("st_msk");
      st_mskdelta390 = readrel420->getIndex(ord419, true);
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("st_msk_ans");
      st_msk_ansindex385 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("st_del");
      st_delindex386 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 2, 0});
      slog::Relation* readrel426 = db->getRelation("st_del");
      st_deldelta391 = readrel426->getIndex(ord425, true);
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("st_del_ans");
      st_del_ansindex387 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1});
      slog::Relation* readrel430 = db->getRelation("st_bld_ans");
      st_bld_ansindex388 = readrel430->getIndex(ord429, false);
  
    }
    ReadTask392(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c36 = _t[2];
        if (!slog::exists_probe<3,1>(st_mskindex374, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex375, std::array<u64,3>{v_c36, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x90x0x0x0index376, std::array<u64,6>{v_c101, v_c36, 0, 0, 0, 0}, [&](const std::array<u64,6>& m431) {
          u64 v_c24 = m431[2]; u64 v_c23 = m431[3]; u64 v_c22 = m431[4]; u64 v_c25 = m431[5];
          slog::join_probe<5,5>(pbranchindex377, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c102}, [&](const std::array<u64,5>& m432) {
            if (!slog::exists_probe<3,2>(st_mskindex378, std::array<u64,3>{v_c36, v_c23, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex379, std::array<u64,2>{v_c22, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex380, std::array<u64,3>{v_c25, v_c36, 0})) return;
            slog::join_probe_old<5,3>(st_bldindex381, st_blddelta389, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0}, [&](const std::array<u64,5>& m433) {
              u64 v_c5 = m433[3]; u64 v_c103 = m433[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex382, std::array<u64,2>{v_c5, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex383, std::array<u64,2>{v_c103, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex384, st_mskdelta390, std::array<u64,3>{v_c36, v_c23, 0}, [&](const std::array<u64,3>& m434) {
                u64 v_c104 = m434[2];
                slog::join_probe<2,2>(st_msk_ansindex385, std::array<u64,2>{v_c104, v_c22}, [&](const std::array<u64,2>& m435) {
                  slog::join_probe_old<3,2>(st_delindex386, st_deldelta391, std::array<u64,3>{v_c25, v_c36, 0}, [&](const std::array<u64,3>& m436) {
                    u64 v_c105 = m436[2];
                    slog::join_probe<2,2>(st_del_ansindex387, std::array<u64,2>{v_c105, v_c5}, [&](const std::array<u64,2>& m437) {
                      slog::join_probe<2,1>(st_bld_ansindex388, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m438) {
                        u64 v_c43 = m438[1];
                        u64 v_c106 = _prim_band(db, v_c36, v_c23);
                        if (v_c106 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c107 = _prim_gt(db, v_c106, v_c100);
                        if (v_c107 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c107) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c43}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask392* _cont = new ReadTask392(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask392(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t6TRN453 __v0) (body (exists _enum (1 0) 1 __tconst19LZ687) (exists st_ins (2 0 1) 1 __tconst5Crw454) (exists st_ins (1 2 0) 2 __v0 __tconst7cMm457) (exists st_ins (2 0 1) 1 __tconst776G459) (join-old st_ins (0 2 1) 2 (0 2 1) __t6TRN453 __tconst6nio451 __t82EP455) (join _enum (0 1) 2 __t82EP455 __tconst19LZ687) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst5Crw454 __t7k0a456) (exists st_ins_ans (0 1) 1 __t7k0a456) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7cMm457 __t6eAo458) (exists st_ins_ans (0 1) 1 __t6eAo458) (join-old st_ins_ans (0 1) 1 (0 1) __t7k0a456 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (exists st_ins_ans (0 1) 1 __t7DB2460) (join-old st_ins_ans (0 1) 1 (0 1) __t6eAo458 a) (join-old st_ins_ans (0 1) 1 (0 1) __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask462 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex440;  slog::Index** st_insindex441;  slog::Index** st_insindex442;  slog::Index** st_insindex443;  slog::Index** st_insindex444;  slog::Index** _enumindex445;  slog::Index** st_insindex446;  slog::Index** st_ins_ansindex447;  slog::Index** st_insindex448;  slog::Index** st_ins_ansindex449;  slog::Index** st_ins_ansindex450;  slog::Index** st_insindex451;  slog::Index** st_ins_ansindex452;  slog::Index** st_ins_ansindex453;  slog::Index** st_ins_ansindex454;  slog::Index** st_insdelta455;  slog::Index** st_insdelta456;  slog::Index** st_insdelta457;  slog::Index** st_ins_ansdelta458;  slog::Index** st_insdelta459;  slog::Index** st_ins_ansdelta460;  slog::Index** st_ins_ansdelta461;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord463({1, 0});
      slog::Relation* readrel464 = db->getRelation("_enum");
      _enumindex440 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({2, 0, 1});
      slog::Relation* readrel466 = db->getRelation("st_ins");
      st_insindex441 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("st_ins");
      st_insindex442 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({2, 0, 1});
      slog::Relation* readrel470 = db->getRelation("st_ins");
      st_insindex443 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 2, 1});
      slog::Relation* readrel472 = db->getRelation("st_ins");
      st_insindex444 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({0, 2, 1});
      slog::Relation* readrel474 = db->getRelation("st_ins");
      st_insdelta455 = readrel474->getIndex(ord473, true);
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("_enum");
      _enumindex445 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0});
      slog::Relation* readrel478 = db->getRelation("st_ins");
      st_insindex446 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 0});
      slog::Relation* readrel480 = db->getRelation("st_ins");
      st_insdelta456 = readrel480->getIndex(ord479, true);
      std::vector<u16> ord481({0, 1});
      slog::Relation* readrel482 = db->getRelation("st_ins_ans");
      st_ins_ansindex447 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("st_ins");
      st_insindex448 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 0});
      slog::Relation* readrel486 = db->getRelation("st_ins");
      st_insdelta457 = readrel486->getIndex(ord485, true);
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("st_ins_ans");
      st_ins_ansindex449 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({0, 1});
      slog::Relation* readrel490 = db->getRelation("st_ins_ans");
      st_ins_ansindex450 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("st_ins_ans");
      st_ins_ansdelta458 = readrel492->getIndex(ord491, true);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("st_ins");
      st_insindex451 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("st_ins");
      st_insdelta459 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("st_ins_ans");
      st_ins_ansindex452 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("st_ins_ans");
      st_ins_ansindex453 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({0, 1});
      slog::Relation* readrel502 = db->getRelation("st_ins_ans");
      st_ins_ansdelta460 = readrel502->getIndex(ord501, true);
      std::vector<u16> ord503({0, 1});
      slog::Relation* readrel504 = db->getRelation("st_ins_ans");
      st_ins_ansindex454 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({0, 1});
      slog::Relation* readrel506 = db->getRelation("st_ins_ans");
      st_ins_ansdelta461 = readrel506->getIndex(ord505, true);
  
    }
    ReadTask462(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c109 = v_constef2d127de37b942baad06145;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_const2c624232cdd221771294dfbb;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c113 = _t[0];
        u64 v_c5 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex440, std::array<u64,2>{v_c108, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex441, std::array<u64,3>{v_c110, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex442, std::array<u64,3>{v_c5, v_c111, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex443, std::array<u64,3>{v_c112, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex444, st_insdelta455, std::array<u64,3>{v_c113, v_c109, 0}, [&](const std::array<u64,3>& m507) {
          u64 v_c114 = m507[2];
          slog::join_probe<2,2>(_enumindex445, std::array<u64,2>{v_c114, v_c108}, [&](const std::array<u64,2>& m508) {
            slog::join_probe_old<3,2>(st_insindex446, st_insdelta456, std::array<u64,3>{v_c114, v_c110, 0}, [&](const std::array<u64,3>& m509) {
              u64 v_c115 = m509[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex447, std::array<u64,2>{v_c115, 0})) return;
              slog::join_probe_old<3,2>(st_insindex448, st_insdelta457, std::array<u64,3>{v_c5, v_c111, 0}, [&](const std::array<u64,3>& m510) {
                u64 v_c116 = m510[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex449, std::array<u64,2>{v_c116, 0})) return;
                slog::join_probe_old<2,1>(st_ins_ansindex450, st_ins_ansdelta458, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m511) {
                  u64 v_c4 = m511[1];
                  slog::join_probe_old<3,2>(st_insindex451, st_insdelta459, std::array<u64,3>{v_c4, v_c112, 0}, [&](const std::array<u64,3>& m512) {
                    u64 v_c117 = m512[2];
                    if (!slog::exists_probe<2,1>(st_ins_ansindex452, std::array<u64,2>{v_c117, 0})) return;
                    slog::join_probe_old<2,1>(st_ins_ansindex453, st_ins_ansdelta460, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m513) {
                      u64 v_c54 = m513[1];
                      slog::join_probe_old<2,1>(st_ins_ansindex454, st_ins_ansdelta461, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m514) {
                        u64 v_c55 = m514[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c54, v_c55}, std::array<u16,3>{1, 2, 0});
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
        ReadTask462* _cont = new ReadTask462(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask462(db,b), false);
  // (crule (pre (let __tconst5qiO758 conste3776bfed7f405de8017ecfa) (let __tconst5MZ7439 constef2d127de37b942baad06145) (let __tconst7dws442 constd4735e3a265e16eee03f5971) (let __tconst4Zv7438 const2c624232cdd221771294dfbb)) (probe st_ins (2 0 1) 1 __tconst5MZ7439 __t1gci441 __t8JV0443) (body (join _enum (0 1) 2 __t8JV0443 __tconst5qiO758) (exists st_ins_ans (0 1) 1 __t1gci441) (join-old st_ins (1 2 0) 2 (1 2 0) __t8JV0443 __tconst7dws442 __t1qxx444) (exists st_ins_ans (0 1) 1 __t1qxx444) (join st_ins_ans (0 1) 1 __t1gci441 __v0) (join st_ins_ans (0 1) 1 __t1qxx444 __v1)) (head (mkstruct st_ins (1 2 0) __0kE5759 __v0 __tconst4Zv7438)) st_basic.slog:18 #f)
  class ReadTask522 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex515;  slog::Index** st_ins_ansindex516;  slog::Index** st_insindex517;  slog::Index** st_ins_ansindex518;  slog::Index** st_ins_ansindex519;  slog::Index** st_ins_ansindex520;  slog::Index** st_insdelta521;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord523({2, 0, 1});
      slog::Relation* readrel524 = db->getRelation("st_ins");
      driver_index = readrel524->getIndex(ord523, true);
      std::vector<u16> ord525({0, 1});
      slog::Relation* readrel526 = db->getRelation("_enum");
      _enumindex515 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("st_ins_ans");
      st_ins_ansindex516 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 0});
      slog::Relation* readrel530 = db->getRelation("st_ins");
      st_insindex517 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 0});
      slog::Relation* readrel532 = db->getRelation("st_ins");
      st_insdelta521 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({0, 1});
      slog::Relation* readrel534 = db->getRelation("st_ins_ans");
      st_ins_ansindex518 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("st_ins_ans");
      st_ins_ansindex519 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({0, 1});
      slog::Relation* readrel538 = db->getRelation("st_ins_ans");
      st_ins_ansindex520 = readrel538->getIndex(ord537, false);
  
    }
    ReadTask522(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c119 = v_constef2d127de37b942baad06145;
      u64 v_c120 = v_constd4735e3a265e16eee03f5971;
      u64 v_c121 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c119, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m539) {
        u64 v_c122 = m539[1];
        u64 v_c123 = m539[2];
        if (buckethash(v_c122) != bucket) return;
        slog::join_probe<2,2>(_enumindex515, std::array<u64,2>{v_c123, v_c118}, [&](const std::array<u64,2>& m540) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex516, std::array<u64,2>{v_c122, 0})) return;
          slog::join_probe_old<3,2>(st_insindex517, st_insdelta521, std::array<u64,3>{v_c123, v_c120, 0}, [&](const std::array<u64,3>& m541) {
            u64 v_c124 = m541[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex518, std::array<u64,2>{v_c124, 0})) return;
            slog::join_probe<2,1>(st_ins_ansindex519, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m542) {
              u64 v_c5 = m542[1];
              slog::join_probe<2,1>(st_ins_ansindex520, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m543) {
                u64 v_c4 = m543[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c121}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask522* _cont = new ReadTask522(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask522(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan $sup9688x106x0x0x1 __t7KDg345 __t0gfm348 l m n p q r u v) (body (cmp lt n m) (join $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t7KDg345 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk (1 2 0) 3 q m __t0gfm348) (exists st_msk_ans (0 1) 2 __t0gfm348 p) (exists st_union (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4ii6344) (exists st_union (0 1 2) 2 __t7KDg345 __t4ii6344) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_union (0 1 2) 3 (0 1 2) __t7KDg345 __t4ii6344 __t0LeB349) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask562 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x0index544;  slog::Index** pbranchindex545;  slog::Index** st_mskindex546;  slog::Index** st_msk_ansindex547;  slog::Index** st_unionindex548;  slog::Index** pbranchindex549;  slog::Index** st_unionindex550;  slog::Index** pbranchindex551;  slog::Index** st_unionindex552;  slog::Index** st_mskindex553;  slog::Index** st_msk_ansindex554;  slog::Index** st_unionindex555;  slog::Index** st_union_ansindex556;  slog::Index** pbranchdelta557;  slog::Index** pbranchdelta558;  slog::Index** st_uniondelta559;  slog::Index** st_mskdelta560;  slog::Index** st_uniondelta561;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord563({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel564 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index544 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 3, 4, 0});
      slog::Relation* readrel566 = db->getRelation("pbranch");
      pbranchindex545 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 0});
      slog::Relation* readrel568 = db->getRelation("st_msk");
      st_mskindex546 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({0, 1});
      slog::Relation* readrel570 = db->getRelation("st_msk_ans");
      st_msk_ansindex547 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("st_union");
      st_unionindex548 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 3, 4, 0});
      slog::Relation* readrel574 = db->getRelation("pbranch");
      pbranchindex549 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 3, 4, 0});
      slog::Relation* readrel576 = db->getRelation("pbranch");
      pbranchdelta557 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1, 2});
      slog::Relation* readrel578 = db->getRelation("st_union");
      st_unionindex550 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 3, 4, 0});
      slog::Relation* readrel580 = db->getRelation("pbranch");
      pbranchindex551 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 3, 4, 0});
      slog::Relation* readrel582 = db->getRelation("pbranch");
      pbranchdelta558 = readrel582->getIndex(ord581, true);
      std::vector<u16> ord583({0, 1, 2});
      slog::Relation* readrel584 = db->getRelation("st_union");
      st_unionindex552 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1, 2});
      slog::Relation* readrel586 = db->getRelation("st_union");
      st_uniondelta559 = readrel586->getIndex(ord585, true);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("st_msk");
      st_mskindex553 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("st_msk");
      st_mskdelta560 = readrel590->getIndex(ord589, true);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("st_msk_ans");
      st_msk_ansindex554 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 2, 0});
      slog::Relation* readrel594 = db->getRelation("st_union");
      st_unionindex555 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 2, 0});
      slog::Relation* readrel596 = db->getRelation("st_union");
      st_uniondelta561 = readrel596->getIndex(ord595, true);
      std::vector<u16> ord597({0, 1});
      slog::Relation* readrel598 = db->getRelation("st_union_ans");
      st_union_ansindex556 = readrel598->getIndex(ord597, false);
  
    }
    ReadTask562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c127 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c29 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c25 = _t[7];
        u64 v_c30 = _t[8];
        u64 v_c31 = _t[9];
        u64 v_c128 = _prim_lt(db, v_c29, v_c23);
        if (v_c128 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
        if (!v_c128) return;
        slog::join_probe<9,9>($sup9688x106x0x0x0index544, std::array<u64,9>{v_c22, v_c24, v_c23, v_c25, v_c126, v_c29, v_c28, v_c30, v_c31}, [&](const std::array<u64,9>& m600) {
          if (!slog::exists_probe<5,4>(pbranchindex545, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex546, std::array<u64,3>{v_c28, v_c23, v_c127})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex547, std::array<u64,2>{v_c127, v_c22})) return;
          if (!slog::exists_probe<3,1>(st_unionindex548, std::array<u64,3>{v_c25, 0, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex549, pbranchdelta557, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m601) {
            u64 v_c129 = m601[4];
            if (!slog::exists_probe<3,2>(st_unionindex550, std::array<u64,3>{v_c126, v_c129, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex551, pbranchdelta558, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m602) {
              u64 v_c130 = m602[4];
              slog::join_probe_old<3,3>(st_unionindex552, st_uniondelta559, std::array<u64,3>{v_c126, v_c129, v_c130}, [&](const std::array<u64,3>& m603) {
                slog::join_probe_old<3,3>(st_mskindex553, st_mskdelta560, std::array<u64,3>{v_c28, v_c23, v_c127}, [&](const std::array<u64,3>& m604) {
                  slog::join_probe<2,2>(st_msk_ansindex554, std::array<u64,2>{v_c127, v_c22}, [&](const std::array<u64,2>& m605) {
                    slog::join_probe_old<3,2>(st_unionindex555, st_uniondelta561, std::array<u64,3>{v_c25, v_c130, 0}, [&](const std::array<u64,3>& m606) {
                      u64 v_c131 = m606[2];
                      slog::join_probe<2,1>(st_union_ansindex556, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m607) {
                        u64 v_c5 = m607[1];
                        u64 v_c132 = _prim_band(db, v_c28, v_c23);
                        if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c133 = _prim_gt(db, v_c132, v_c125);
                        if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c133) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c126, v_c5, v_c24, v_c23, v_c22});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:$sup9688x106x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask562* _cont = new ReadTask562(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask562(db,b), false);
  // (crule (pre) (scan st_join_ans __t3WPW519 res) (body (join-old st_join (0 1 2 3 4) 1 (0 1 2 3 4) __t3WPW519 p __t52IG517 q __t1VuF518) (neq p q) (exists pbranch (0 1 2 3 4) 2 __t52IG517 p) (exists pbranch (0 1 2 3 4) 2 __t1VuF518 q) (join-old st_union (1 2 0) 2 (1 2 0) __t52IG517 __t1VuF518 __t5oQM516) (join-old pbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t52IG517 p m l r) (join-old pbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t1VuF518 q m u v)) (head (emit st_union_ans (0 1) __t5oQM516 res)) set.slog:125 #f)
  class ReadTask619 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex609;  slog::Index** pbranchindex610;  slog::Index** pbranchindex611;  slog::Index** st_unionindex612;  slog::Index** pbranchindex613;  slog::Index** pbranchindex614;  slog::Index** st_joindelta615;  slog::Index** st_uniondelta616;  slog::Index** pbranchdelta617;  slog::Index** pbranchdelta618;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord620({0, 1});
      slog::Relation* readrel621 = db->getRelation("st_union_ans");
      head_index[0] = readrel621->getIndex(ord620, false);
      outer_rel = db->getRelation("st_join_ans");
      std::vector<u16> ord622({0, 1, 2, 3, 4});
      slog::Relation* readrel623 = db->getRelation("st_join");
      st_joinindex609 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({0, 1, 2, 3, 4});
      slog::Relation* readrel625 = db->getRelation("st_join");
      st_joindelta615 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({0, 1, 2, 3, 4});
      slog::Relation* readrel627 = db->getRelation("pbranch");
      pbranchindex610 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 1, 2, 3, 4});
      slog::Relation* readrel629 = db->getRelation("pbranch");
      pbranchindex611 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("st_union");
      st_unionindex612 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("st_union");
      st_uniondelta616 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({0, 1, 2, 3, 4});
      slog::Relation* readrel635 = db->getRelation("pbranch");
      pbranchindex613 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({0, 1, 2, 3, 4});
      slog::Relation* readrel637 = db->getRelation("pbranch");
      pbranchdelta617 = readrel637->getIndex(ord636, true);
      std::vector<u16> ord638({0, 1, 2, 3, 4});
      slog::Relation* readrel639 = db->getRelation("pbranch");
      pbranchindex614 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({0, 1, 2, 3, 4});
      slog::Relation* readrel641 = db->getRelation("pbranch");
      pbranchdelta618 = readrel641->getIndex(ord640, true);
  
    }
    ReadTask619(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<5,1>(st_joinindex609, st_joindelta615, std::array<u64,5>{v_c42, 0, 0, 0, 0}, [&](const std::array<u64,5>& m642) {
          u64 v_c22 = m642[1]; u64 v_c40 = m642[2]; u64 v_c28 = m642[3]; u64 v_c41 = m642[4];
          if (v_c22 == v_c28) return;
          if (!slog::exists_probe<5,2>(pbranchindex610, std::array<u64,5>{v_c40, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex611, std::array<u64,5>{v_c41, v_c28, 0, 0, 0})) return;
          slog::join_probe_old<3,2>(st_unionindex612, st_uniondelta616, std::array<u64,3>{v_c40, v_c41, 0}, [&](const std::array<u64,3>& m643) {
            u64 v_c39 = m643[2];
            slog::join_probe_old<5,2>(pbranchindex613, pbranchdelta617, std::array<u64,5>{v_c40, v_c22, 0, 0, 0}, [&](const std::array<u64,5>& m644) {
              u64 v_c23 = m644[2]; u64 v_c24 = m644[3]; u64 v_c25 = m644[4];
              slog::join_probe_old<5,3>(pbranchindex614, pbranchdelta618, std::array<u64,5>{v_c41, v_c28, v_c23, 0, 0}, [&](const std::array<u64,5>& m645) {
                u64 v_c30 = m645[3]; u64 v_c31 = m645[4];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c39, v_c43}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:st_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask619* _cont = new ReadTask619(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask619(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t44Py494 p) (body (exists $sup9688x90x0x0x0 (4 2 3 5 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (exists st_bld (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t44Py494 k m) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_del (2 0 1) 1 k) (exists st_bld (1 2 3 4 0) 2 p m) (join-old $sup9688x90x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t3j4h490 l r) (exists st_del (0 2 1) 2 __t3j4h490 k) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_del (1 2 0) 2 r k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4hkT489) (join-old st_del (0 2 1) 3 (0 2 1) __t3j4h490 k __t4hkT489) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8CKV493) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join-old st_del_ans (0 1) 2 (0 1) __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask672 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index646;  slog::Index** pbranchindex647;  slog::Index** st_bldindex648;  slog::Index** st_mskindex649;  slog::Index** pbranchindex650;  slog::Index** st_delindex651;  slog::Index** st_bldindex652;  slog::Index** $sup9688x90x0x0x0index653;  slog::Index** st_delindex654;  slog::Index** st_bldindex655;  slog::Index** st_delindex656;  slog::Index** pbranchindex657;  slog::Index** st_delindex658;  slog::Index** st_bldindex659;  slog::Index** st_del_ansindex660;  slog::Index** st_bld_ansindex661;  slog::Index** st_delindex662;  slog::Index** st_del_ansindex663;  slog::Index** st_bld_ansindex664;  slog::Index** st_mskdelta665;  slog::Index** $sup9688x90x0x0x0delta666;  slog::Index** pbranchdelta667;  slog::Index** st_deldelta668;  slog::Index** st_blddelta669;  slog::Index** st_deldelta670;  slog::Index** st_del_ansdelta671;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord673({0, 1});
      slog::Relation* readrel674 = db->getRelation("st_del_ans");
      head_index[0] = readrel674->getIndex(ord673, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord675({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel676 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index646 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 3, 4, 0});
      slog::Relation* readrel678 = db->getRelation("pbranch");
      pbranchindex647 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 2, 3, 4, 0});
      slog::Relation* readrel680 = db->getRelation("st_bld");
      st_bldindex648 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({0, 1, 2});
      slog::Relation* readrel682 = db->getRelation("st_msk");
      st_mskindex649 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({0, 1, 2});
      slog::Relation* readrel684 = db->getRelation("st_msk");
      st_mskdelta665 = readrel684->getIndex(ord683, true);
      std::vector<u16> ord685({1, 2, 3, 4, 0});
      slog::Relation* readrel686 = db->getRelation("pbranch");
      pbranchindex650 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({2, 0, 1});
      slog::Relation* readrel688 = db->getRelation("st_del");
      st_delindex651 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 3, 4, 0});
      slog::Relation* readrel690 = db->getRelation("st_bld");
      st_bldindex652 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel692 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index653 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel694 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0delta666 = readrel694->getIndex(ord693, true);
      std::vector<u16> ord695({0, 2, 1});
      slog::Relation* readrel696 = db->getRelation("st_del");
      st_delindex654 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 2, 3, 4, 0});
      slog::Relation* readrel698 = db->getRelation("st_bld");
      st_bldindex655 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("st_del");
      st_delindex656 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 3, 4, 0});
      slog::Relation* readrel702 = db->getRelation("pbranch");
      pbranchindex657 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 3, 4, 0});
      slog::Relation* readrel704 = db->getRelation("pbranch");
      pbranchdelta667 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({0, 2, 1});
      slog::Relation* readrel706 = db->getRelation("st_del");
      st_delindex658 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 2, 1});
      slog::Relation* readrel708 = db->getRelation("st_del");
      st_deldelta668 = readrel708->getIndex(ord707, true);
      std::vector<u16> ord709({1, 2, 3, 4, 0});
      slog::Relation* readrel710 = db->getRelation("st_bld");
      st_bldindex659 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 3, 4, 0});
      slog::Relation* readrel712 = db->getRelation("st_bld");
      st_blddelta669 = readrel712->getIndex(ord711, true);
      std::vector<u16> ord713({1, 0});
      slog::Relation* readrel714 = db->getRelation("st_del_ans");
      st_del_ansindex660 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("st_bld_ans");
      st_bld_ansindex661 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("st_del");
      st_delindex662 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 0});
      slog::Relation* readrel720 = db->getRelation("st_del");
      st_deldelta670 = readrel720->getIndex(ord719, true);
      std::vector<u16> ord721({0, 1});
      slog::Relation* readrel722 = db->getRelation("st_del_ans");
      st_del_ansindex663 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({0, 1});
      slog::Relation* readrel724 = db->getRelation("st_del_ans");
      st_del_ansdelta671 = readrel724->getIndex(ord723, true);
      std::vector<u16> ord725({0, 1});
      slog::Relation* readrel726 = db->getRelation("st_bld_ans");
      st_bld_ansindex664 = readrel726->getIndex(ord725, false);
  
    }
    ReadTask672(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c104 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x90x0x0x0index646, std::array<u64,6>{v_c22, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex647, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex648, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex649, st_mskdelta665, std::array<u64,3>{v_c104, 0, 0}, [&](const std::array<u64,3>& m727) {
          u64 v_c36 = m727[1]; u64 v_c23 = m727[2];
          if (!slog::exists_probe<5,2>(pbranchindex650, std::array<u64,5>{v_c22, v_c23, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex651, std::array<u64,3>{v_c36, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex652, std::array<u64,5>{v_c22, v_c23, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup9688x90x0x0x0index653, $sup9688x90x0x0x0delta666, std::array<u64,6>{v_c36, v_c23, v_c22, 0, 0, 0}, [&](const std::array<u64,6>& m728) {
            u64 v_c101 = m728[3]; u64 v_c24 = m728[4]; u64 v_c25 = m728[5];
            if (!slog::exists_probe<3,2>(st_delindex654, std::array<u64,3>{v_c101, v_c36, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex655, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex656, std::array<u64,3>{v_c25, v_c36, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex657, pbranchdelta667, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m729) {
              u64 v_c102 = m729[4];
              slog::join_probe_old<3,3>(st_delindex658, st_deldelta668, std::array<u64,3>{v_c101, v_c36, v_c102}, [&](const std::array<u64,3>& m730) {
                slog::join_probe_old<5,3>(st_bldindex659, st_blddelta669, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0}, [&](const std::array<u64,5>& m731) {
                  u64 v_c5 = m731[3]; u64 v_c103 = m731[4];
                  if (!slog::exists_probe<2,1>(st_del_ansindex660, std::array<u64,2>{v_c5, 0})) return;
                  if (!slog::exists_probe<2,1>(st_bld_ansindex661, std::array<u64,2>{v_c103, 0})) return;
                  slog::join_probe_old<3,2>(st_delindex662, st_deldelta670, std::array<u64,3>{v_c25, v_c36, 0}, [&](const std::array<u64,3>& m732) {
                    u64 v_c105 = m732[2];
                    slog::join_probe_old<2,2>(st_del_ansindex663, st_del_ansdelta671, std::array<u64,2>{v_c105, v_c5}, [&](const std::array<u64,2>& m733) {
                      slog::join_probe<2,1>(st_bld_ansindex664, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m734) {
                        u64 v_c43 = m734[1];
                        u64 v_c106 = _prim_band(db, v_c36, v_c23);
                        if (v_c106 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c134 = _prim_gt(db, v_c106, v_c100);
                        if (v_c134 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c134) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c43}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask672* _cont = new ReadTask672(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask672(db,b), false);
  // (crule (pre (let __trid7AMG943 constf2664e0abda1016213c9fa90) (let __trel1lLE944 const26c89ee8ccc4ea998fd1a912) (let __tcol6Qdi945 const5feceb66ffc86f38d952786c) (let __trel7lgp946 const26c89ee8ccc4ea998fd1a912) (let __tcol7D5S947 const6b86b273ff34fce19d6b804e)) (scan st_diff __t3HZn560 l u) (body (exists $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 l u) (join st_diff_ans (0 1) 1 __t3HZn560 __v0) (join $sup9688x136x0x0x0 (1 5 0 2 3 4 6) 2 l u __d0 m p r v) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t6exy561) (join st_diff_ans (0 1) 1 __t6exy561 __v1)) (head (tycheck p (accept int) __trid7AMG943 __trel1lLE944 __tcol6Qdi945 (1 2 3 4 0)) (tycheck m (accept int) __trid7AMG943 __trel7lgp946 __tcol7D5S947 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __7CRS942 p m __v0 __v1)) set.slog:137 #f)
  class ReadTask742 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index736;  slog::Index** st_diff_ansindex737;  slog::Index** $sup9688x136x0x0x0index738;  slog::Index** st_diffindex739;  slog::Index** st_diff_ansindex740;  slog::Index** st_diffdelta741;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord743({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel744 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index736 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({0, 1});
      slog::Relation* readrel746 = db->getRelation("st_diff_ans");
      st_diff_ansindex737 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel748 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index738 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 2, 0});
      slog::Relation* readrel750 = db->getRelation("st_diff");
      st_diffindex739 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 2, 0});
      slog::Relation* readrel752 = db->getRelation("st_diff");
      st_diffdelta741 = readrel752->getIndex(ord751, true);
      std::vector<u16> ord753({0, 1});
      slog::Relation* readrel754 = db->getRelation("st_diff_ans");
      st_diff_ansindex740 = readrel754->getIndex(ord753, false);
  
    }
    ReadTask742(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_constf2664e0abda1016213c9fa90;
      u64 v_c136 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c140 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c30 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index736, std::array<u64,7>{v_c24, v_c30, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex737, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m755) {
          u64 v_c5 = m755[1];
          slog::join_probe<7,2>($sup9688x136x0x0x0index738, std::array<u64,7>{v_c24, v_c30, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m756) {
            u64 v_c82 = m756[2]; u64 v_c23 = m756[3]; u64 v_c22 = m756[4]; u64 v_c25 = m756[5]; u64 v_c31 = m756[6];
            slog::join_probe_old<3,2>(st_diffindex739, st_diffdelta741, std::array<u64,3>{v_c25, v_c31, 0}, [&](const std::array<u64,3>& m757) {
              u64 v_c141 = m757[2];
              slog::join_probe<2,1>(st_diff_ansindex740, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m758) {
                u64 v_c4 = m758[1];
                ++_fires;
                if (!(is_int(v_c22)))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c135, v_c136, v_c137, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                if (!(is_int(v_c23)))
                {
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c135, v_c138, v_c139, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c22, v_c23, v_c5, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask742* _cont = new ReadTask742(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask742(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_bld __t1RXD162 p m __v0 r) (body (exists $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 3 p m r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join pbranch (1 2 4 0 3) 3 p m r __t66RN158 l) (exists st_diff (1 2 0) 1 __t66RN158) (exists st_diff (1 2 0) 1 l) (join $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 4 p m r l __t3X8M159 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join st_diff (0 1 2) 3 __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index759;  slog::Index** st_mskindex760;  slog::Index** st_msk_ansindex761;  slog::Index** st_diff_ansindex762;  slog::Index** st_bld_ansindex763;  slog::Index** pbranchindex764;  slog::Index** st_diffindex765;  slog::Index** st_diffindex766;  slog::Index** $sup9688x139x0x0x0index767;  slog::Index** st_diffindex768;  slog::Index** st_mskindex769;  slog::Index** pbranchindex770;  slog::Index** st_diffindex771;  slog::Index** st_diffindex772;  slog::Index** st_mskindex773;  slog::Index** st_msk_ansindex774;  slog::Index** st_diffindex775;  slog::Index** st_diff_ansindex776;  slog::Index** st_bld_ansindex777;  slog::Index** pbranchdelta778;  slog::Index** st_mskdelta779;  slog::Index** st_diffdelta780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord782({0, 1});
      slog::Relation* readrel783 = db->getRelation("st_diff_ans");
      head_index[0] = readrel783->getIndex(ord782, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord784({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel785 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index759 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({2, 0, 1});
      slog::Relation* readrel787 = db->getRelation("st_msk");
      st_mskindex760 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 0});
      slog::Relation* readrel789 = db->getRelation("st_msk_ans");
      st_msk_ansindex761 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 0});
      slog::Relation* readrel791 = db->getRelation("st_diff_ans");
      st_diff_ansindex762 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("st_bld_ans");
      st_bld_ansindex763 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 4, 0, 3});
      slog::Relation* readrel795 = db->getRelation("pbranch");
      pbranchindex764 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("st_diff");
      st_diffindex765 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("st_diff");
      st_diffindex766 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel801 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index767 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({0, 1, 2});
      slog::Relation* readrel803 = db->getRelation("st_diff");
      st_diffindex768 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("st_msk");
      st_mskindex769 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 3, 4, 0});
      slog::Relation* readrel807 = db->getRelation("pbranch");
      pbranchindex770 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 3, 4, 0});
      slog::Relation* readrel809 = db->getRelation("pbranch");
      pbranchdelta778 = readrel809->getIndex(ord808, true);
      std::vector<u16> ord810({0, 1, 2});
      slog::Relation* readrel811 = db->getRelation("st_diff");
      st_diffindex771 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({1, 2, 0});
      slog::Relation* readrel813 = db->getRelation("st_diff");
      st_diffindex772 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({1, 2, 0});
      slog::Relation* readrel815 = db->getRelation("st_msk");
      st_mskindex773 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("st_msk");
      st_mskdelta779 = readrel817->getIndex(ord816, true);
      std::vector<u16> ord818({0, 1});
      slog::Relation* readrel819 = db->getRelation("st_msk_ans");
      st_msk_ansindex774 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("st_diff");
      st_diffindex775 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("st_diff");
      st_diffdelta780 = readrel823->getIndex(ord822, true);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("st_diff_ans");
      st_diff_ansindex776 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({0, 1});
      slog::Relation* readrel827 = db->getRelation("st_bld_ans");
      st_bld_ansindex777 = readrel827->getIndex(ord826, false);
  
    }
    ReadTask781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c143 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<9,3>($sup9688x139x0x0x0index759, std::array<u64,9>{v_c22, v_c23, v_c25, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex760, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex761, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_diff_ansindex762, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(st_bld_ansindex763, std::array<u64,2>{v_c143, 0})) return;
        slog::join_probe<5,3>(pbranchindex764, std::array<u64,5>{v_c22, v_c23, v_c25, 0, 0}, [&](const std::array<u64,5>& m828) {
          u64 v_c144 = m828[3]; u64 v_c24 = m828[4];
          if (!slog::exists_probe<3,1>(st_diffindex765, std::array<u64,3>{v_c144, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex766, std::array<u64,3>{v_c24, 0, 0})) return;
          slog::join_probe<9,4>($sup9688x139x0x0x0index767, std::array<u64,9>{v_c22, v_c23, v_c25, v_c24, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m829) {
            u64 v_c145 = m829[4]; u64 v_c29 = m829[5]; u64 v_c28 = m829[6]; u64 v_c30 = m829[7]; u64 v_c31 = m829[8];
            u64 v_c146 = _prim_lt(db, v_c29, v_c23);
            if (v_c146 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c146) return;
            if (!slog::exists_probe<3,2>(st_diffindex768, std::array<u64,3>{v_c145, v_c144, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex769, std::array<u64,3>{v_c28, v_c23, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex770, pbranchdelta778, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m831) {
              u64 v_c147 = m831[4];
              slog::join_probe<3,3>(st_diffindex771, std::array<u64,3>{v_c145, v_c144, v_c147}, [&](const std::array<u64,3>& m832) {
                if (!slog::exists_probe<3,2>(st_diffindex772, std::array<u64,3>{v_c24, v_c147, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex773, st_mskdelta779, std::array<u64,3>{v_c28, v_c23, 0}, [&](const std::array<u64,3>& m833) {
                  u64 v_c148 = m833[2];
                  slog::join_probe<2,2>(st_msk_ansindex774, std::array<u64,2>{v_c148, v_c22}, [&](const std::array<u64,2>& m834) {
                    slog::join_probe_old<3,2>(st_diffindex775, st_diffdelta780, std::array<u64,3>{v_c24, v_c147, 0}, [&](const std::array<u64,3>& m835) {
                      u64 v_c149 = m835[2];
                      slog::join_probe<2,2>(st_diff_ansindex776, std::array<u64,2>{v_c149, v_c5}, [&](const std::array<u64,2>& m836) {
                        slog::join_probe<2,1>(st_bld_ansindex777, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m837) {
                          u64 v_c43 = m837[1];
                          u64 v_c150 = _prim_band(db, v_c28, v_c23);
                          if (v_c150 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c151 = _prim_lt(db, v_c150, v_c142);
                          if (v_c151 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c151) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c145, v_c43}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask781* _cont = new ReadTask781(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask781(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan pbranch __t69OA340 q n u v) (body (exists st_diff (2 0 1) 1 __t69OA340) (exists st_msk (1 2 0) 1 q) (join $sup9688x142x0x0x0 (3 5 7 8 6 0 1 2 4) 4 n q u v r __t8Fy1335 l m p) (cmp lt n m) (exists st_diff (2 0 1) 2 __t69OA340 __t8Fy1335) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 2 r __t69OA340) (join pbranch (1 2 3 4 0) 4 p m l r __t88zt334) (join st_diff (0 1 2) 3 __t8Fy1335 __t88zt334 __t69OA340) (join st_bld (1 2 3 4 0) 3 p m l __v0 __t7XLn338) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join st_msk (1 2 0) 2 q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join st_diff_ans (0 1) 2 __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask858 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex839;  slog::Index** st_mskindex840;  slog::Index** $sup9688x142x0x0x0index841;  slog::Index** st_diffindex842;  slog::Index** st_bldindex843;  slog::Index** st_mskindex844;  slog::Index** st_msk_ansindex845;  slog::Index** st_diffindex846;  slog::Index** pbranchindex847;  slog::Index** st_diffindex848;  slog::Index** st_bldindex849;  slog::Index** st_diff_ansindex850;  slog::Index** st_bld_ansindex851;  slog::Index** st_mskindex852;  slog::Index** st_msk_ansindex853;  slog::Index** st_diffindex854;  slog::Index** st_diff_ansindex855;  slog::Index** st_bld_ansindex856;  slog::Index** st_diffdelta857;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord859({0, 1});
      slog::Relation* readrel860 = db->getRelation("st_diff_ans");
      head_index[0] = readrel860->getIndex(ord859, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord861({2, 0, 1});
      slog::Relation* readrel862 = db->getRelation("st_diff");
      st_diffindex839 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 2, 0});
      slog::Relation* readrel864 = db->getRelation("st_msk");
      st_mskindex840 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({3, 5, 7, 8, 6, 0, 1, 2, 4});
      slog::Relation* readrel866 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index841 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({2, 0, 1});
      slog::Relation* readrel868 = db->getRelation("st_diff");
      st_diffindex842 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 2, 3, 4, 0});
      slog::Relation* readrel870 = db->getRelation("st_bld");
      st_bldindex843 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("st_msk");
      st_mskindex844 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 0});
      slog::Relation* readrel874 = db->getRelation("st_msk_ans");
      st_msk_ansindex845 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("st_diff");
      st_diffindex846 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 3, 4, 0});
      slog::Relation* readrel878 = db->getRelation("pbranch");
      pbranchindex847 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 1, 2});
      slog::Relation* readrel880 = db->getRelation("st_diff");
      st_diffindex848 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 3, 4, 0});
      slog::Relation* readrel882 = db->getRelation("st_bld");
      st_bldindex849 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 0});
      slog::Relation* readrel884 = db->getRelation("st_diff_ans");
      st_diff_ansindex850 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({0, 1});
      slog::Relation* readrel886 = db->getRelation("st_bld_ans");
      st_bld_ansindex851 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("st_msk");
      st_mskindex852 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({0, 1});
      slog::Relation* readrel890 = db->getRelation("st_msk_ans");
      st_msk_ansindex853 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("st_diff");
      st_diffindex854 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 2, 0});
      slog::Relation* readrel894 = db->getRelation("st_diff");
      st_diffdelta857 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("st_diff_ans");
      st_diff_ansindex855 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1});
      slog::Relation* readrel898 = db->getRelation("st_bld_ans");
      st_bld_ansindex856 = readrel898->getIndex(ord897, false);
  
    }
    ReadTask858(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex839, std::array<u64,3>{v_c66, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex840, std::array<u64,3>{v_c28, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x142x0x0x0index841, std::array<u64,9>{v_c29, v_c28, v_c30, v_c31, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m899) {
          u64 v_c25 = m899[4]; u64 v_c64 = m899[5]; u64 v_c24 = m899[6]; u64 v_c23 = m899[7]; u64 v_c22 = m899[8];
          u64 v_c152 = _prim_lt(db, v_c29, v_c23);
          if (v_c152 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
          if (!v_c152) return;
          if (!slog::exists_probe<3,2>(st_diffindex842, std::array<u64,3>{v_c66, v_c64, 0})) return;
          if (!slog::exists_probe<5,3>(st_bldindex843, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex844, std::array<u64,3>{v_c28, v_c23, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex845, std::array<u64,2>{v_c22, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex846, std::array<u64,3>{v_c25, v_c66, 0})) return;
          slog::join_probe<5,4>(pbranchindex847, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m901) {
            u64 v_c63 = m901[4];
            slog::join_probe<3,3>(st_diffindex848, std::array<u64,3>{v_c64, v_c63, v_c66}, [&](const std::array<u64,3>& m902) {
              slog::join_probe<5,3>(st_bldindex849, std::array<u64,5>{v_c22, v_c23, v_c24, 0, 0}, [&](const std::array<u64,5>& m903) {
                u64 v_c5 = m903[3]; u64 v_c62 = m903[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex850, std::array<u64,2>{v_c5, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex851, std::array<u64,2>{v_c62, 0})) return;
                slog::join_probe<3,2>(st_mskindex852, std::array<u64,3>{v_c28, v_c23, 0}, [&](const std::array<u64,3>& m904) {
                  u64 v_c67 = m904[2];
                  slog::join_probe<2,2>(st_msk_ansindex853, std::array<u64,2>{v_c67, v_c22}, [&](const std::array<u64,2>& m905) {
                    slog::join_probe_old<3,2>(st_diffindex854, st_diffdelta857, std::array<u64,3>{v_c25, v_c66, 0}, [&](const std::array<u64,3>& m906) {
                      u64 v_c68 = m906[2];
                      slog::join_probe<2,2>(st_diff_ansindex855, std::array<u64,2>{v_c68, v_c5}, [&](const std::array<u64,2>& m907) {
                        slog::join_probe<2,1>(st_bld_ansindex856, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m908) {
                          u64 v_c43 = m908[1];
                          u64 v_c69 = _prim_band(db, v_c28, v_c23);
                          if (v_c69 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c153 = _prim_gt(db, v_c69, v_c61);
                          if (v_c153 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c153) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask858* _cont = new ReadTask858(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask858(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan $sup9688x50x0x0x1 __t6bST316 __t5Q4t319 k l m p r) (body (join $sup9688x50x0x0x0 (4 2 3 5 0 1) 6 p l m r __t6bST316 k) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_msk (1 2 0) 3 k m __t5Q4t319) (exists st_msk_ans (0 1) 2 __t5Q4t319 p) (exists st_ins (1 2 0) 2 l k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8dDI315) (join-old st_ins (0 2 1) 3 (0 2 1) __t6bST316 k __t8dDI315) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask925 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x0index910;  slog::Index** st_insindex911;  slog::Index** st_mskindex912;  slog::Index** st_msk_ansindex913;  slog::Index** st_insindex914;  slog::Index** pbranchindex915;  slog::Index** st_insindex916;  slog::Index** st_mskindex917;  slog::Index** st_msk_ansindex918;  slog::Index** st_insindex919;  slog::Index** st_ins_ansindex920;  slog::Index** pbranchdelta921;  slog::Index** st_insdelta922;  slog::Index** st_mskdelta923;  slog::Index** st_insdelta924;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord926({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel927 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index910 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({0, 2, 1});
      slog::Relation* readrel929 = db->getRelation("st_ins");
      st_insindex911 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("st_msk");
      st_mskindex912 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({0, 1});
      slog::Relation* readrel933 = db->getRelation("st_msk_ans");
      st_msk_ansindex913 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("st_ins");
      st_insindex914 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 3, 4, 0});
      slog::Relation* readrel937 = db->getRelation("pbranch");
      pbranchindex915 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 3, 4, 0});
      slog::Relation* readrel939 = db->getRelation("pbranch");
      pbranchdelta921 = readrel939->getIndex(ord938, true);
      std::vector<u16> ord940({0, 2, 1});
      slog::Relation* readrel941 = db->getRelation("st_ins");
      st_insindex916 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({0, 2, 1});
      slog::Relation* readrel943 = db->getRelation("st_ins");
      st_insdelta922 = readrel943->getIndex(ord942, true);
      std::vector<u16> ord944({1, 2, 0});
      slog::Relation* readrel945 = db->getRelation("st_msk");
      st_mskindex917 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 2, 0});
      slog::Relation* readrel947 = db->getRelation("st_msk");
      st_mskdelta923 = readrel947->getIndex(ord946, true);
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("st_msk_ans");
      st_msk_ansindex918 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 2, 0});
      slog::Relation* readrel951 = db->getRelation("st_ins");
      st_insindex919 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("st_ins");
      st_insdelta924 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("st_ins_ans");
      st_ins_ansindex920 = readrel955->getIndex(ord954, false);
  
    }
    ReadTask925(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c154 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c155 = _t[0];
        u64 v_c156 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c23 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c25 = _t[6];
        slog::join_probe<6,6>($sup9688x50x0x0x0index910, std::array<u64,6>{v_c22, v_c24, v_c23, v_c25, v_c155, v_c36}, [&](const std::array<u64,6>& m956) {
          if (!slog::exists_probe<3,2>(st_insindex911, std::array<u64,3>{v_c155, v_c36, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex912, std::array<u64,3>{v_c36, v_c23, v_c156})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex913, std::array<u64,2>{v_c156, v_c22})) return;
          if (!slog::exists_probe<3,2>(st_insindex914, std::array<u64,3>{v_c24, v_c36, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex915, pbranchdelta921, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m957) {
            u64 v_c157 = m957[4];
            slog::join_probe_old<3,3>(st_insindex916, st_insdelta922, std::array<u64,3>{v_c155, v_c36, v_c157}, [&](const std::array<u64,3>& m958) {
              slog::join_probe_old<3,3>(st_mskindex917, st_mskdelta923, std::array<u64,3>{v_c36, v_c23, v_c156}, [&](const std::array<u64,3>& m959) {
                slog::join_probe<2,2>(st_msk_ansindex918, std::array<u64,2>{v_c156, v_c22}, [&](const std::array<u64,2>& m960) {
                  slog::join_probe_old<3,2>(st_insindex919, st_insdelta924, std::array<u64,3>{v_c24, v_c36, 0}, [&](const std::array<u64,3>& m961) {
                    u64 v_c158 = m961[2];
                    slog::join_probe<2,1>(st_ins_ansindex920, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m962) {
                      u64 v_c5 = m962[1];
                      u64 v_c159 = _prim_band(db, v_c36, v_c23);
                      if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c160 = _prim_lt(db, v_c159, v_c154);
                      if (v_c160 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c160) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c155, v_c5, v_c23, v_c22, v_c25});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c5, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:$sup9688x50x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask925* _cont = new ReadTask925(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask925(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan st_ins __t7CbB259 __t0vi9258 k) (body (exists $sup9688x52x0x0x1 (0 2 1 3 4 5 6) 2 __t7CbB259 k) (exists st_msk (1 2 0) 1 k) (exists st_ins (2 0 1) 1 k) (join $sup9688x52x0x0x0 (0 1 2 3 4 5) 2 __t7CbB259 k l m p r) (exists pbranch (1 2 3 4 0) 5 p m l r __t0vi9258) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 2 r k) (join $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t7CbB259 k __t57zq262) (join pbranch (1 2 3 4 0) 5 p m l r __t0vi9258) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask980 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x1index964;  slog::Index** st_mskindex965;  slog::Index** st_insindex966;  slog::Index** $sup9688x52x0x0x0index967;  slog::Index** pbranchindex968;  slog::Index** st_mskindex969;  slog::Index** st_msk_ansindex970;  slog::Index** st_insindex971;  slog::Index** $sup9688x52x0x0x1index972;  slog::Index** pbranchindex973;  slog::Index** st_mskindex974;  slog::Index** st_msk_ansindex975;  slog::Index** st_insindex976;  slog::Index** st_ins_ansindex977;  slog::Index** st_mskdelta978;  slog::Index** st_insdelta979;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord981({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel982 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index964 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 2, 0});
      slog::Relation* readrel984 = db->getRelation("st_msk");
      st_mskindex965 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({2, 0, 1});
      slog::Relation* readrel986 = db->getRelation("st_ins");
      st_insindex966 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel988 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index967 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 2, 3, 4, 0});
      slog::Relation* readrel990 = db->getRelation("pbranch");
      pbranchindex968 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 2, 0});
      slog::Relation* readrel992 = db->getRelation("st_msk");
      st_mskindex969 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 0});
      slog::Relation* readrel994 = db->getRelation("st_msk_ans");
      st_msk_ansindex970 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 0});
      slog::Relation* readrel996 = db->getRelation("st_ins");
      st_insindex971 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel998 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index972 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 2, 3, 4, 0});
      slog::Relation* readrel1000 = db->getRelation("pbranch");
      pbranchindex973 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 2, 0});
      slog::Relation* readrel1002 = db->getRelation("st_msk");
      st_mskindex974 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 2, 0});
      slog::Relation* readrel1004 = db->getRelation("st_msk");
      st_mskdelta978 = readrel1004->getIndex(ord1003, true);
      std::vector<u16> ord1005({0, 1});
      slog::Relation* readrel1006 = db->getRelation("st_msk_ans");
      st_msk_ansindex975 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("st_ins");
      st_insindex976 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 0});
      slog::Relation* readrel1010 = db->getRelation("st_ins");
      st_insdelta979 = readrel1010->getIndex(ord1009, true);
      std::vector<u16> ord1011({0, 1});
      slog::Relation* readrel1012 = db->getRelation("st_ins_ans");
      st_ins_ansindex977 = readrel1012->getIndex(ord1011, false);
  
    }
    ReadTask980(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c161 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c163 = _t[1];
        u64 v_c36 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x52x0x0x1index964, std::array<u64,7>{v_c162, v_c36, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex965, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex966, std::array<u64,3>{v_c36, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x52x0x0x0index967, std::array<u64,6>{v_c162, v_c36, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1013) {
          u64 v_c24 = m1013[2]; u64 v_c23 = m1013[3]; u64 v_c22 = m1013[4]; u64 v_c25 = m1013[5];
          if (!slog::exists_probe<5,5>(pbranchindex968, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c163})) return;
          if (!slog::exists_probe<3,2>(st_mskindex969, std::array<u64,3>{v_c36, v_c23, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex970, std::array<u64,2>{v_c22, 0})) return;
          if (!slog::exists_probe<3,2>(st_insindex971, std::array<u64,3>{v_c25, v_c36, 0})) return;
          slog::join_probe<7,6>($sup9688x52x0x0x1index972, std::array<u64,7>{v_c24, v_c23, v_c22, v_c25, v_c162, v_c36, 0}, [&](const std::array<u64,7>& m1014) {
            u64 v_c164 = m1014[6];
            slog::join_probe<5,5>(pbranchindex973, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c163}, [&](const std::array<u64,5>& m1015) {
              slog::join_probe_old<3,3>(st_mskindex974, st_mskdelta978, std::array<u64,3>{v_c36, v_c23, v_c164}, [&](const std::array<u64,3>& m1016) {
                slog::join_probe<2,2>(st_msk_ansindex975, std::array<u64,2>{v_c164, v_c22}, [&](const std::array<u64,2>& m1017) {
                  slog::join_probe_old<3,2>(st_insindex976, st_insdelta979, std::array<u64,3>{v_c25, v_c36, 0}, [&](const std::array<u64,3>& m1018) {
                    u64 v_c165 = m1018[2];
                    slog::join_probe<2,1>(st_ins_ansindex977, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m1019) {
                      u64 v_c5 = m1019[1];
                      u64 v_c166 = _prim_band(db, v_c36, v_c23);
                      if (v_c166 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c167 = _prim_gt(db, v_c166, v_c161);
                      if (v_c167 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c167) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c162, v_c5, v_c24, v_c23, v_c22});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask980* _cont = new ReadTask980(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask980(db,b), false);
  // (crule (pre) (scan temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (body (join pbranch (1 2 3 4 0) 4 p m __v0 __v1 __t6nPF285)) (head (emit st_union_ans (0 1) __t2Q3U288 __t6nPF285)) set.slog:101 #f)
  class ReadTask1022 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1021;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1023({0, 1});
      slog::Relation* readrel1024 = db->getRelation("st_union_ans");
      head_index[0] = readrel1024->getIndex(ord1023, false);
      outer_rel = db->getRelation("temp6bMv1274");
      std::vector<u16> ord1025({1, 2, 3, 4, 0});
      slog::Relation* readrel1026 = db->getRelation("pbranch");
      pbranchindex1021 = readrel1026->getIndex(ord1025, false);
  
    }
    ReadTask1022(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c22 = _t[4];
        slog::join_probe<5,4>(pbranchindex1021, std::array<u64,5>{v_c22, v_c23, v_c5, v_c4, 0}, [&](const std::array<u64,5>& m1027) {
          u64 v_c169 = m1027[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c168, v_c169}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:temp6bMv1274", _fires);
  
      if (!_done)
      {
        ReadTask1022* _cont = new ReadTask1022(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1022(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan $sup9688x114x0x0x1 __t2j0W61 __t1Zy964 l m n p q r u v) (body (cmp lt m n) (join $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t2j0W61 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 3 p n __t1Zy964) (exists st_msk_ans (0 1) 2 __t1Zy964 q) (exists st_union (2 0 1) 1 u) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2ifW59) (exists st_union (2 0 1) 2 __t2ifW59 __t2j0W61) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_union (0 1 2) 3 (0 1 2) __t2j0W61 __t5Obr65 __t2ifW59) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask1046 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x0index1028;  slog::Index** pbranchindex1029;  slog::Index** st_mskindex1030;  slog::Index** st_msk_ansindex1031;  slog::Index** st_unionindex1032;  slog::Index** pbranchindex1033;  slog::Index** st_unionindex1034;  slog::Index** pbranchindex1035;  slog::Index** st_unionindex1036;  slog::Index** st_mskindex1037;  slog::Index** st_msk_ansindex1038;  slog::Index** st_unionindex1039;  slog::Index** st_union_ansindex1040;  slog::Index** pbranchdelta1041;  slog::Index** pbranchdelta1042;  slog::Index** st_uniondelta1043;  slog::Index** st_mskdelta1044;  slog::Index** st_uniondelta1045;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord1047({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1048 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1028 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 2, 3, 4, 0});
      slog::Relation* readrel1050 = db->getRelation("pbranch");
      pbranchindex1029 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 2, 0});
      slog::Relation* readrel1052 = db->getRelation("st_msk");
      st_mskindex1030 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({0, 1});
      slog::Relation* readrel1054 = db->getRelation("st_msk_ans");
      st_msk_ansindex1031 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({2, 0, 1});
      slog::Relation* readrel1056 = db->getRelation("st_union");
      st_unionindex1032 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({1, 2, 3, 4, 0});
      slog::Relation* readrel1058 = db->getRelation("pbranch");
      pbranchindex1033 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 2, 3, 4, 0});
      slog::Relation* readrel1060 = db->getRelation("pbranch");
      pbranchdelta1041 = readrel1060->getIndex(ord1059, true);
      std::vector<u16> ord1061({2, 0, 1});
      slog::Relation* readrel1062 = db->getRelation("st_union");
      st_unionindex1034 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 2, 3, 4, 0});
      slog::Relation* readrel1064 = db->getRelation("pbranch");
      pbranchindex1035 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({1, 2, 3, 4, 0});
      slog::Relation* readrel1066 = db->getRelation("pbranch");
      pbranchdelta1042 = readrel1066->getIndex(ord1065, true);
      std::vector<u16> ord1067({0, 1, 2});
      slog::Relation* readrel1068 = db->getRelation("st_union");
      st_unionindex1036 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({0, 1, 2});
      slog::Relation* readrel1070 = db->getRelation("st_union");
      st_uniondelta1043 = readrel1070->getIndex(ord1069, true);
      std::vector<u16> ord1071({1, 2, 0});
      slog::Relation* readrel1072 = db->getRelation("st_msk");
      st_mskindex1037 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 2, 0});
      slog::Relation* readrel1074 = db->getRelation("st_msk");
      st_mskdelta1044 = readrel1074->getIndex(ord1073, true);
      std::vector<u16> ord1075({0, 1});
      slog::Relation* readrel1076 = db->getRelation("st_msk_ans");
      st_msk_ansindex1038 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({1, 2, 0});
      slog::Relation* readrel1078 = db->getRelation("st_union");
      st_unionindex1039 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 2, 0});
      slog::Relation* readrel1080 = db->getRelation("st_union");
      st_uniondelta1045 = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({0, 1});
      slog::Relation* readrel1082 = db->getRelation("st_union_ans");
      st_union_ansindex1040 = readrel1082->getIndex(ord1081, false);
  
    }
    ReadTask1046(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c171 = _t[0];
        u64 v_c172 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c29 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c25 = _t[7];
        u64 v_c30 = _t[8];
        u64 v_c31 = _t[9];
        u64 v_c173 = _prim_lt(db, v_c23, v_c29);
        if (v_c173 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
        if (!v_c173) return;
        slog::join_probe<9,9>($sup9688x114x0x0x0index1028, std::array<u64,9>{v_c28, v_c29, v_c30, v_c31, v_c171, v_c24, v_c23, v_c22, v_c25}, [&](const std::array<u64,9>& m1084) {
          if (!slog::exists_probe<5,4>(pbranchindex1029, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex1030, std::array<u64,3>{v_c22, v_c29, v_c172})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex1031, std::array<u64,2>{v_c172, v_c28})) return;
          if (!slog::exists_probe<3,1>(st_unionindex1032, std::array<u64,3>{v_c30, 0, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex1033, pbranchdelta1041, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m1085) {
            u64 v_c174 = m1085[4];
            if (!slog::exists_probe<3,2>(st_unionindex1034, std::array<u64,3>{v_c174, v_c171, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1035, pbranchdelta1042, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m1086) {
              u64 v_c175 = m1086[4];
              slog::join_probe_old<3,3>(st_unionindex1036, st_uniondelta1043, std::array<u64,3>{v_c171, v_c175, v_c174}, [&](const std::array<u64,3>& m1087) {
                slog::join_probe_old<3,3>(st_mskindex1037, st_mskdelta1044, std::array<u64,3>{v_c22, v_c29, v_c172}, [&](const std::array<u64,3>& m1088) {
                  slog::join_probe<2,2>(st_msk_ansindex1038, std::array<u64,2>{v_c172, v_c28}, [&](const std::array<u64,2>& m1089) {
                    slog::join_probe_old<3,2>(st_unionindex1039, st_uniondelta1045, std::array<u64,3>{v_c175, v_c30, 0}, [&](const std::array<u64,3>& m1090) {
                      u64 v_c176 = m1090[2];
                      slog::join_probe<2,1>(st_union_ansindex1040, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m1091) {
                        u64 v_c5 = m1091[1];
                        u64 v_c177 = _prim_band(db, v_c22, v_c29);
                        if (v_c177 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c178 = _prim_lt(db, v_c177, v_c170);
                        if (v_c178 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c178) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c171, v_c5, v_c29, v_c28, v_c31});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c29, v_c5, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:$sup9688x114x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1046* _cont = new ReadTask1046(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1046(db,b), false);
  // (crule (pre) (scan pleaf __t9Bxs396 j) (body (join-old st_ins (1 2 0) 1 (1 2 0) __t9Bxs396 k __t7Vi1397) (neq j k)) (head (emit-temp temp7DYO1402 __t9Bxs396 j k) (mkstruct pleaf (1 0) __t4eWA395 k)) set.slog:50 #f)
  class ReadTask1095 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1093;  slog::Index** st_insdelta1094;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7DYO1402");
      head_rel[1] = db->getRelation("pleaf");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1096({1, 2, 0});
      slog::Relation* readrel1097 = db->getRelation("st_ins");
      st_insindex1093 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("st_ins");
      st_insdelta1094 = readrel1099->getIndex(ord1098, true);
  
    }
    ReadTask1095(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        slog::join_probe_old<3,1>(st_insindex1093, st_insdelta1094, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m1100) {
          u64 v_c36 = m1100[1]; u64 v_c181 = m1100[2];
          if (v_c180 == v_c36) return;
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c179, v_c180, v_c36});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1095* _cont = new ReadTask1095(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1095(db,b), false);
  // (crule (pre) (scan temp5IQT1412 __t8nF2228) (body) (head (mkstruct st_hsb (1 0) __6dG8914 __t8nF2228)) set.slog:37 #f)
  class ReadTask1101 : public slog::Task
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
      outer_rel = db->getRelation("temp5IQT1412");
  
    }
    ReadTask1101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c182 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c182}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:temp5IQT1412", _fires);
  
      if (!_done)
      {
        ReadTask1101* _cont = new ReadTask1101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1101(db,b), false);
  // (crule (pre (let __tconst0XIw307 const5feceb66ffc86f38d952786c)) (scan pbranch __t3Mhw304 q n u v) (body (join-old st_union (2 0 1) 1 (2 0 1) __t3Mhw304 __t8fFv306 __t4jxi305) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t4jxi305 p m l r) (cmp lt n m) (let __t3ur5308 (band q m)) (cmp gt __t3ur5308 __tconst0XIw307)) (head (emit $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) __t8fFv306 r l m n p q u v)) set.slog:107 #f)
  class ReadTask1106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex1102;  slog::Index** pbranchindex1103;  slog::Index** st_uniondelta1104;  slog::Index** pbranchdelta1105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord1107({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1108 = db->getRelation("$sup9688x106x0x0x0");
      head_index[0] = readrel1108->getIndex(ord1107, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1109({2, 0, 1});
      slog::Relation* readrel1110 = db->getRelation("st_union");
      st_unionindex1102 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 0, 1});
      slog::Relation* readrel1112 = db->getRelation("st_union");
      st_uniondelta1104 = readrel1112->getIndex(ord1111, true);
      std::vector<u16> ord1113({0, 1, 2, 3, 4});
      slog::Relation* readrel1114 = db->getRelation("pbranch");
      pbranchindex1103 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({0, 1, 2, 3, 4});
      slog::Relation* readrel1116 = db->getRelation("pbranch");
      pbranchdelta1105 = readrel1116->getIndex(ord1115, true);
  
    }
    ReadTask1106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c184 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex1102, st_uniondelta1104, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m1117) {
          u64 v_c185 = m1117[1]; u64 v_c186 = m1117[2];
          slog::join_probe_old<5,1>(pbranchindex1103, pbranchdelta1105, std::array<u64,5>{v_c186, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1118) {
            u64 v_c22 = m1118[1]; u64 v_c23 = m1118[2]; u64 v_c24 = m1118[3]; u64 v_c25 = m1118[4];
            u64 v_c187 = _prim_lt(db, v_c29, v_c23);
            if (v_c187 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c187) return;
            u64 v_c188 = _prim_band(db, v_c28, v_c23);
            if (v_c188 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            u64 v_c189 = _prim_gt(db, v_c188, v_c183);
            if (v_c189 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c189) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c185, v_c25, v_c24, v_c23, v_c29, v_c22, v_c28, v_c30, v_c31}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1106* _cont = new ReadTask1106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1106(db,b), false);
  // (crule (pre) (scan pleaf __t5zQO240 k) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t5zQO240 __t60WQ241 s)) (head (mkstruct st_del (1 2 0) __14DP1086 s k)) set.slog:133 #f)
  class ReadTask1123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1121;  slog::Index** st_diffdelta1122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1124({2, 0, 1});
      slog::Relation* readrel1125 = db->getRelation("st_diff");
      st_diffindex1121 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({2, 0, 1});
      slog::Relation* readrel1127 = db->getRelation("st_diff");
      st_diffdelta1122 = readrel1127->getIndex(ord1126, true);
  
    }
    ReadTask1123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c190 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex1121, st_diffdelta1122, std::array<u64,3>{v_c190, 0, 0}, [&](const std::array<u64,3>& m1128) {
          u64 v_c191 = m1128[1]; u64 v_c19 = m1128[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c19, v_c36}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1123* _cont = new ReadTask1123(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1123(db,b), false);
  // (crule (pre (let __trid0O8l910 const1e44311dd5d36c3a7dc21dfa) (let __trel2X7j911 const26c89ee8ccc4ea998fd1a912) (let __tcol3tdZ912 constd4735e3a265e16eee03f5971)) (scan $sup9688x90x0x0x0 __d0 k l m p r) (body (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 r k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t8Ytg398) (join-old st_msk_ans (0 1) 2 (0 1) __t8Ytg398 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t56Eo399) (join-old st_del_ans (0 1) 1 (0 1) __t56Eo399 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0O8l910 __trel2X7j911 __tcol3tdZ912 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __6yFQ909 p m l __v0)) set.slog:91 #f)
  class ReadTask1142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex1129;  slog::Index** st_delindex1130;  slog::Index** st_mskindex1131;  slog::Index** st_msk_ansindex1132;  slog::Index** st_delindex1133;  slog::Index** st_del_ansindex1134;  slog::Index** st_mskdelta1135;  slog::Index** st_msk_ansdelta1136;  slog::Index** st_deldelta1137;  slog::Index** st_del_ansdelta1138;
    u32 sid1140;  u32 sid1139;  u32 sid1141;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord1143({1, 0});
      slog::Relation* readrel1144 = db->getRelation("st_msk_ans");
      st_msk_ansindex1129 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({1, 2, 0});
      slog::Relation* readrel1146 = db->getRelation("st_del");
      st_delindex1130 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({1, 2, 0});
      slog::Relation* readrel1148 = db->getRelation("st_msk");
      st_mskindex1131 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({1, 2, 0});
      slog::Relation* readrel1150 = db->getRelation("st_msk");
      st_mskdelta1135 = readrel1150->getIndex(ord1149, true);
      std::vector<u16> ord1151({0, 1});
      slog::Relation* readrel1152 = db->getRelation("st_msk_ans");
      st_msk_ansindex1132 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({0, 1});
      slog::Relation* readrel1154 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1136 = readrel1154->getIndex(ord1153, true);
      std::vector<u16> ord1155({1, 2, 0});
      slog::Relation* readrel1156 = db->getRelation("st_del");
      st_delindex1133 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 2, 0});
      slog::Relation* readrel1158 = db->getRelation("st_del");
      st_deldelta1137 = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({0, 1});
      slog::Relation* readrel1160 = db->getRelation("st_del_ans");
      st_del_ansindex1134 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({0, 1});
      slog::Relation* readrel1162 = db->getRelation("st_del_ans");
      st_del_ansdelta1138 = readrel1162->getIndex(ord1161, true);
      sid1140 = db->getRelation("_enum")->getStructId();
      sid1139 = db->getRelation("pbranch")->getStructId();
      sid1141 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c192 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c193 = v_const26c89ee8ccc4ea998fd1a912;
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
        u64 v_c82 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c22 = _t[4];
        u64 v_c25 = _t[5];
        if (!slog::exists_probe<2,1>(st_msk_ansindex1129, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<3,2>(st_delindex1130, std::array<u64,3>{v_c25, v_c36, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex1131, st_mskdelta1135, std::array<u64,3>{v_c36, v_c23, 0}, [&](const std::array<u64,3>& m1163) {
          u64 v_c195 = m1163[2];
          slog::join_probe_old<2,2>(st_msk_ansindex1132, st_msk_ansdelta1136, std::array<u64,2>{v_c195, v_c22}, [&](const std::array<u64,2>& m1164) {
            slog::join_probe_old<3,2>(st_delindex1133, st_deldelta1137, std::array<u64,3>{v_c25, v_c36, 0}, [&](const std::array<u64,3>& m1165) {
              u64 v_c196 = m1165[2];
              slog::join_probe_old<2,1>(st_del_ansindex1134, st_del_ansdelta1138, std::array<u64,2>{v_c196, 0}, [&](const std::array<u64,2>& m1166) {
                u64 v_c5 = m1166[1];
                ++_fires;
                if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid1139 || decode_struct_id(v_c24) == sid1140 || decode_struct_id(v_c24) == sid1141))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c192, v_c193, v_c194, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:$sup9688x90x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1142* _cont = new ReadTask1142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1142(db,b), false);
  // (crule (pre) (scan $sup9688x117x0x0x0 __d0 l m n p q r u v) (body (exists st_msk_ans (1 0) 1 q) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t88lr525) (join-old st_msk_ans (0 1) 2 (0 1) __t88lr525 q)) (head (emit $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t88lr525 l m n p q r u)) set.slog:118 #f)
  class ReadTask1172 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex1167;  slog::Index** st_mskindex1168;  slog::Index** st_msk_ansindex1169;  slog::Index** st_mskdelta1170;  slog::Index** st_msk_ansdelta1171;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord1173({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1174 = db->getRelation("$sup9688x117x0x0x1");
      head_index[0] = readrel1174->getIndex(ord1173, false);
      outer_rel = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord1175({1, 0});
      slog::Relation* readrel1176 = db->getRelation("st_msk_ans");
      st_msk_ansindex1167 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({1, 2, 0});
      slog::Relation* readrel1178 = db->getRelation("st_msk");
      st_mskindex1168 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({1, 2, 0});
      slog::Relation* readrel1180 = db->getRelation("st_msk");
      st_mskdelta1170 = readrel1180->getIndex(ord1179, true);
      std::vector<u16> ord1181({0, 1});
      slog::Relation* readrel1182 = db->getRelation("st_msk_ans");
      st_msk_ansindex1169 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({0, 1});
      slog::Relation* readrel1184 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1171 = readrel1184->getIndex(ord1183, true);
  
    }
    ReadTask1172(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c22 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c30 = _t[7];
        u64 v_c31 = _t[8];
        if (!slog::exists_probe<2,1>(st_msk_ansindex1167, std::array<u64,2>{v_c28, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex1168, st_mskdelta1170, std::array<u64,3>{v_c22, v_c29, 0}, [&](const std::array<u64,3>& m1185) {
          u64 v_c197 = m1185[2];
          slog::join_probe_old<2,2>(st_msk_ansindex1169, st_msk_ansdelta1171, std::array<u64,2>{v_c197, v_c28}, [&](const std::array<u64,2>& m1186) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c82, v_c31, v_c197, v_c24, v_c23, v_c29, v_c22, v_c28, v_c25, v_c30}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:$sup9688x117x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1172* _cont = new ReadTask1172(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1172(db,b), false);
  // (crule (pre (let __tconst4ng4400 const5feceb66ffc86f38d952786c)) (scan pbranch __t4Y7m401 p m l r) (body (exists st_mem0 (1 2 0) 1 __t4Y7m401) (exists st_msk (2 0 1) 1 m) (join $sup9688x69x0x0x0 (2 3 4 5 0 1) 4 l m p r __t26uy402 k) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t26uy402 __t4Y7m401 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t7rLj403) (join st_msk_ans (0 1) 1 __t7rLj403 __v0) (neq p __v0)) (head (emit st_mem0_ans (0 1) __t26uy402 __tconst4ng4400)) set.slog:70 #f)
  class ReadTask1195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index1187;  slog::Index** st_mskindex1188;  slog::Index** $sup9688x69x0x0x0index1189;  slog::Index** st_mem0index1190;  slog::Index** st_mskindex1191;  slog::Index** st_msk_ansindex1192;  slog::Index** st_mem0delta1193;  slog::Index** st_mskdelta1194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1196({0, 1});
      slog::Relation* readrel1197 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1197->getIndex(ord1196, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1198({1, 2, 0});
      slog::Relation* readrel1199 = db->getRelation("st_mem0");
      st_mem0index1187 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({2, 0, 1});
      slog::Relation* readrel1201 = db->getRelation("st_msk");
      st_mskindex1188 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0index1189 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({0, 1, 2});
      slog::Relation* readrel1205 = db->getRelation("st_mem0");
      st_mem0index1190 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({0, 1, 2});
      slog::Relation* readrel1207 = db->getRelation("st_mem0");
      st_mem0delta1193 = readrel1207->getIndex(ord1206, true);
      std::vector<u16> ord1208({1, 2, 0});
      slog::Relation* readrel1209 = db->getRelation("st_msk");
      st_mskindex1191 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("st_msk");
      st_mskdelta1194 = readrel1211->getIndex(ord1210, true);
      std::vector<u16> ord1212({0, 1});
      slog::Relation* readrel1213 = db->getRelation("st_msk_ans");
      st_msk_ansindex1192 = readrel1213->getIndex(ord1212, false);
  
    }
    ReadTask1195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c198 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c199 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<3,1>(st_mem0index1187, std::array<u64,3>{v_c199, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1188, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x69x0x0x0index1189, std::array<u64,6>{v_c24, v_c23, v_c22, v_c25, 0, 0}, [&](const std::array<u64,6>& m1214) {
          u64 v_c200 = m1214[4]; u64 v_c36 = m1214[5];
          slog::join_probe_old<3,3>(st_mem0index1190, st_mem0delta1193, std::array<u64,3>{v_c200, v_c199, v_c36}, [&](const std::array<u64,3>& m1215) {
            slog::join_probe_old<3,2>(st_mskindex1191, st_mskdelta1194, std::array<u64,3>{v_c36, v_c23, 0}, [&](const std::array<u64,3>& m1216) {
              u64 v_c201 = m1216[2];
              slog::join_probe<2,1>(st_msk_ansindex1192, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1217) {
                u64 v_c5 = m1217[1];
                if (v_c22 == v_c5) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c200, v_c198}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1195* _cont = new ReadTask1195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1195(db,b), false);
  // (crule (pre) (scan st_del __t3YAz313 __t3ubB312 k) (body (join pbranch (0 1 2 3 4) 1 __t3ubB312 p m l r)) (head (emit $sup9688x87x0x0x0 (0 1 2 3 4 5) __t3YAz313 k l m p r)) set.slog:88 #f)
  class ReadTask1219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord1220({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1221 = db->getRelation("$sup9688x87x0x0x0");
      head_index[0] = readrel1221->getIndex(ord1220, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord1222({0, 1, 2, 3, 4});
      slog::Relation* readrel1223 = db->getRelation("pbranch");
      pbranchindex1218 = readrel1223->getIndex(ord1222, false);
  
    }
    ReadTask1219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c202 = _t[0];
        u64 v_c203 = _t[1];
        u64 v_c36 = _t[2];
        slog::join_probe<5,1>(pbranchindex1218, std::array<u64,5>{v_c203, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1224) {
          u64 v_c22 = m1224[1]; u64 v_c23 = m1224[2]; u64 v_c24 = m1224[3]; u64 v_c25 = m1224[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c202, v_c36, v_c24, v_c23, v_c22, v_c25}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask1219* _cont = new ReadTask1219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1219(db,b), false);
  // (crule (pre (let __tconst3w2v824 conste3776bfed7f405de8017ecfa)) (scan st_union __t3hML269 s __t1DtJ268) (body (join _enum (0 1) 2 __t1DtJ268 __tconst3w2v824)) (head (emit st_union_ans (0 1) __t3hML269 s)) set.slog:97 #f)
  class ReadTask1226 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1225;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1227({0, 1});
      slog::Relation* readrel1228 = db->getRelation("st_union_ans");
      head_index[0] = readrel1228->getIndex(ord1227, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord1229({0, 1});
      slog::Relation* readrel1230 = db->getRelation("_enum");
      _enumindex1225 = readrel1230->getIndex(ord1229, false);
  
    }
    ReadTask1226(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c204 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c205 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c206 = _t[2];
        slog::join_probe<2,2>(_enumindex1225, std::array<u64,2>{v_c206, v_c204}, [&](const std::array<u64,2>& m1231) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c205, v_c19}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:97", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask1226* _cont = new ReadTask1226(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1226(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t1x4A82 q) (body (exists $sup9688x151x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists pbranch (1 2 3 4 0) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t1x4A82 p n) (exists pbranch (1 2 3 4 0) 2 q n) (exists pbranch (1 2 3 4 0) 1 p) (join-old $sup9688x151x0x0x0 (3 4 5 0 1 2 6 7 8) 3 (3 4 5 0 1 2 6 7 8) n p q __t0F4S77 l m r u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3eDW75) (exists st_diff (2 0 1) 2 __t3eDW75 __t0F4S77) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0L1D80) (join-old st_diff (0 1 2) 3 (0 1 2) __t0F4S77 __t0L1D80 __t3eDW75) (join-old st_diff (1 2 0) 2 (1 2 0) __t0L1D80 v __t8Vvm81) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask1252 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x151x0x0x0index1232;  slog::Index** pbranchindex1233;  slog::Index** st_mskindex1234;  slog::Index** pbranchindex1235;  slog::Index** pbranchindex1236;  slog::Index** $sup9688x151x0x0x0index1237;  slog::Index** pbranchindex1238;  slog::Index** st_diffindex1239;  slog::Index** pbranchindex1240;  slog::Index** st_diffindex1241;  slog::Index** pbranchindex1242;  slog::Index** st_diffindex1243;  slog::Index** st_diffindex1244;  slog::Index** st_diff_ansindex1245;  slog::Index** st_mskdelta1246;  slog::Index** $sup9688x151x0x0x0delta1247;  slog::Index** pbranchdelta1248;  slog::Index** pbranchdelta1249;  slog::Index** st_diffdelta1250;  slog::Index** st_diffdelta1251;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1253({0, 1});
      slog::Relation* readrel1254 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1254->getIndex(ord1253, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1255({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1256 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index1232 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({1, 2, 3, 4, 0});
      slog::Relation* readrel1258 = db->getRelation("pbranch");
      pbranchindex1233 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({0, 1, 2});
      slog::Relation* readrel1260 = db->getRelation("st_msk");
      st_mskindex1234 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({0, 1, 2});
      slog::Relation* readrel1262 = db->getRelation("st_msk");
      st_mskdelta1246 = readrel1262->getIndex(ord1261, true);
      std::vector<u16> ord1263({1, 2, 3, 4, 0});
      slog::Relation* readrel1264 = db->getRelation("pbranch");
      pbranchindex1235 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 2, 3, 4, 0});
      slog::Relation* readrel1266 = db->getRelation("pbranch");
      pbranchindex1236 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1268 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index1237 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1270 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0delta1247 = readrel1270->getIndex(ord1269, true);
      std::vector<u16> ord1271({1, 2, 3, 4, 0});
      slog::Relation* readrel1272 = db->getRelation("pbranch");
      pbranchindex1238 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({2, 0, 1});
      slog::Relation* readrel1274 = db->getRelation("st_diff");
      st_diffindex1239 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({1, 2, 3, 4, 0});
      slog::Relation* readrel1276 = db->getRelation("pbranch");
      pbranchindex1240 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 2, 3, 4, 0});
      slog::Relation* readrel1278 = db->getRelation("pbranch");
      pbranchdelta1248 = readrel1278->getIndex(ord1277, true);
      std::vector<u16> ord1279({2, 0, 1});
      slog::Relation* readrel1280 = db->getRelation("st_diff");
      st_diffindex1241 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 2, 3, 4, 0});
      slog::Relation* readrel1282 = db->getRelation("pbranch");
      pbranchindex1242 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({1, 2, 3, 4, 0});
      slog::Relation* readrel1284 = db->getRelation("pbranch");
      pbranchdelta1249 = readrel1284->getIndex(ord1283, true);
      std::vector<u16> ord1285({0, 1, 2});
      slog::Relation* readrel1286 = db->getRelation("st_diff");
      st_diffindex1243 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({0, 1, 2});
      slog::Relation* readrel1288 = db->getRelation("st_diff");
      st_diffdelta1250 = readrel1288->getIndex(ord1287, true);
      std::vector<u16> ord1289({1, 2, 0});
      slog::Relation* readrel1290 = db->getRelation("st_diff");
      st_diffindex1244 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({1, 2, 0});
      slog::Relation* readrel1292 = db->getRelation("st_diff");
      st_diffdelta1251 = readrel1292->getIndex(ord1291, true);
      std::vector<u16> ord1293({0, 1});
      slog::Relation* readrel1294 = db->getRelation("st_diff_ans");
      st_diff_ansindex1245 = readrel1294->getIndex(ord1293, false);
  
    }
    ReadTask1252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c208 = _t[0];
        u64 v_c28 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x151x0x0x0index1232, std::array<u64,9>{v_c28, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1233, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1234, st_mskdelta1246, std::array<u64,3>{v_c208, 0, 0}, [&](const std::array<u64,3>& m1295) {
          u64 v_c22 = m1295[1]; u64 v_c29 = m1295[2];
          if (!slog::exists_probe<5,2>(pbranchindex1235, std::array<u64,5>{v_c28, v_c29, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1236, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          slog::join_probe_old<9,3>($sup9688x151x0x0x0index1237, $sup9688x151x0x0x0delta1247, std::array<u64,9>{v_c29, v_c22, v_c28, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1296) {
            u64 v_c209 = m1296[3]; u64 v_c24 = m1296[4]; u64 v_c23 = m1296[5]; u64 v_c25 = m1296[6]; u64 v_c30 = m1296[7]; u64 v_c31 = m1296[8];
            u64 v_c210 = _prim_lt(db, v_c23, v_c29);
            if (v_c210 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c210) return;
            if (!slog::exists_probe<5,4>(pbranchindex1238, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex1239, std::array<u64,3>{v_c31, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1240, pbranchdelta1248, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m1298) {
              u64 v_c211 = m1298[4];
              if (!slog::exists_probe<3,2>(st_diffindex1241, std::array<u64,3>{v_c211, v_c209, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1242, pbranchdelta1249, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m1299) {
                u64 v_c212 = m1299[4];
                slog::join_probe_old<3,3>(st_diffindex1243, st_diffdelta1250, std::array<u64,3>{v_c209, v_c212, v_c211}, [&](const std::array<u64,3>& m1300) {
                  slog::join_probe_old<3,2>(st_diffindex1244, st_diffdelta1251, std::array<u64,3>{v_c212, v_c31, 0}, [&](const std::array<u64,3>& m1301) {
                    u64 v_c213 = m1301[2];
                    slog::join_probe<2,1>(st_diff_ansindex1245, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m1302) {
                      u64 v_c43 = m1302[1];
                      u64 v_c214 = _prim_band(db, v_c22, v_c29);
                      if (v_c214 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c215 = _prim_gt(db, v_c214, v_c207);
                      if (v_c215 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c215) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c209, v_c43}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1252* _cont = new ReadTask1252(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1252(db,b), false);
  // (crule (pre) (scan st_join_ans __t1ZYa238 res) (body (join-old st_join (0 1 2 3 4) 1 (0 1 2 3 4) __t1ZYa238 p __t7ZZP236 q __t8STz237) (exists pbranch (0 1 2 3 4) 2 __t7ZZP236 p) (exists pbranch (0 1 2 3 4) 2 __t8STz237 q) (exists st_union (1 2 0) 2 __t7ZZP236 __t8STz237) (exists st_msk (1 2 0) 1 p) (join-old $sup9688x120x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t7ZZP236 __t8STz237 __t3tZ8235 l m n r u v) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t7ZZP236) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8STz237) (join-old st_union (0 1 2) 3 (0 1 2) __t3tZ8235 __t7ZZP236 __t8STz237) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join-old st_msk_ans (0 1) 1 (0 1) __t3Qtm239 __v0) (neq q __v0)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask1322 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex1304;  slog::Index** pbranchindex1305;  slog::Index** pbranchindex1306;  slog::Index** st_unionindex1307;  slog::Index** st_mskindex1308;  slog::Index** $sup9688x120x0x0x0index1309;  slog::Index** pbranchindex1310;  slog::Index** pbranchindex1311;  slog::Index** st_unionindex1312;  slog::Index** st_mskindex1313;  slog::Index** st_msk_ansindex1314;  slog::Index** st_joindelta1315;  slog::Index** $sup9688x120x0x0x0delta1316;  slog::Index** pbranchdelta1317;  slog::Index** pbranchdelta1318;  slog::Index** st_uniondelta1319;  slog::Index** st_mskdelta1320;  slog::Index** st_msk_ansdelta1321;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1323({0, 1});
      slog::Relation* readrel1324 = db->getRelation("st_union_ans");
      head_index[0] = readrel1324->getIndex(ord1323, false);
      outer_rel = db->getRelation("st_join_ans");
      std::vector<u16> ord1325({0, 1, 2, 3, 4});
      slog::Relation* readrel1326 = db->getRelation("st_join");
      st_joinindex1304 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({0, 1, 2, 3, 4});
      slog::Relation* readrel1328 = db->getRelation("st_join");
      st_joindelta1315 = readrel1328->getIndex(ord1327, true);
      std::vector<u16> ord1329({0, 1, 2, 3, 4});
      slog::Relation* readrel1330 = db->getRelation("pbranch");
      pbranchindex1305 = readrel1330->getIndex(ord1329, false);
      std::vector<u16> ord1331({0, 1, 2, 3, 4});
      slog::Relation* readrel1332 = db->getRelation("pbranch");
      pbranchindex1306 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({1, 2, 0});
      slog::Relation* readrel1334 = db->getRelation("st_union");
      st_unionindex1307 = readrel1334->getIndex(ord1333, false);
      std::vector<u16> ord1335({1, 2, 0});
      slog::Relation* readrel1336 = db->getRelation("st_msk");
      st_mskindex1308 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1338 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index1309 = readrel1338->getIndex(ord1337, false);
      std::vector<u16> ord1339({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1340 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0delta1316 = readrel1340->getIndex(ord1339, true);
      std::vector<u16> ord1341({1, 2, 3, 4, 0});
      slog::Relation* readrel1342 = db->getRelation("pbranch");
      pbranchindex1310 = readrel1342->getIndex(ord1341, false);
      std::vector<u16> ord1343({1, 2, 3, 4, 0});
      slog::Relation* readrel1344 = db->getRelation("pbranch");
      pbranchdelta1317 = readrel1344->getIndex(ord1343, true);
      std::vector<u16> ord1345({1, 2, 3, 4, 0});
      slog::Relation* readrel1346 = db->getRelation("pbranch");
      pbranchindex1311 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({1, 2, 3, 4, 0});
      slog::Relation* readrel1348 = db->getRelation("pbranch");
      pbranchdelta1318 = readrel1348->getIndex(ord1347, true);
      std::vector<u16> ord1349({0, 1, 2});
      slog::Relation* readrel1350 = db->getRelation("st_union");
      st_unionindex1312 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({0, 1, 2});
      slog::Relation* readrel1352 = db->getRelation("st_union");
      st_uniondelta1319 = readrel1352->getIndex(ord1351, true);
      std::vector<u16> ord1353({1, 2, 0});
      slog::Relation* readrel1354 = db->getRelation("st_msk");
      st_mskindex1313 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("st_msk");
      st_mskdelta1320 = readrel1356->getIndex(ord1355, true);
      std::vector<u16> ord1357({0, 1});
      slog::Relation* readrel1358 = db->getRelation("st_msk_ans");
      st_msk_ansindex1314 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({0, 1});
      slog::Relation* readrel1360 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1321 = readrel1360->getIndex(ord1359, true);
  
    }
    ReadTask1322(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c216 = _t[0];
        u64 v_c43 = _t[1];
        slog::join_probe_old<5,1>(st_joinindex1304, st_joindelta1315, std::array<u64,5>{v_c216, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1361) {
          u64 v_c22 = m1361[1]; u64 v_c217 = m1361[2]; u64 v_c28 = m1361[3]; u64 v_c218 = m1361[4];
          if (!slog::exists_probe<5,2>(pbranchindex1305, std::array<u64,5>{v_c217, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1306, std::array<u64,5>{v_c218, v_c28, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex1307, std::array<u64,3>{v_c217, v_c218, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1308, std::array<u64,3>{v_c22, 0, 0})) return;
          slog::join_probe_old<11,4>($sup9688x120x0x0x0index1309, $sup9688x120x0x0x0delta1316, std::array<u64,11>{v_c22, v_c28, v_c217, v_c218, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1362) {
            u64 v_c219 = m1362[4]; u64 v_c24 = m1362[5]; u64 v_c23 = m1362[6]; u64 v_c29 = m1362[7]; u64 v_c25 = m1362[8]; u64 v_c30 = m1362[9]; u64 v_c31 = m1362[10];
            u64 v_c220 = _prim_lt(db, v_c23, v_c29);
            if (v_c220 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c220) return;
            slog::join_probe_old<5,5>(pbranchindex1310, pbranchdelta1317, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c217}, [&](const std::array<u64,5>& m1364) {
              slog::join_probe_old<5,5>(pbranchindex1311, pbranchdelta1318, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, v_c218}, [&](const std::array<u64,5>& m1365) {
                slog::join_probe_old<3,3>(st_unionindex1312, st_uniondelta1319, std::array<u64,3>{v_c219, v_c217, v_c218}, [&](const std::array<u64,3>& m1366) {
                  slog::join_probe_old<3,2>(st_mskindex1313, st_mskdelta1320, std::array<u64,3>{v_c22, v_c29, 0}, [&](const std::array<u64,3>& m1367) {
                    u64 v_c221 = m1367[2];
                    slog::join_probe_old<2,1>(st_msk_ansindex1314, st_msk_ansdelta1321, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m1368) {
                      u64 v_c5 = m1368[1];
                      if (v_c28 == v_c5) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c219, v_c43}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask1322* _cont = new ReadTask1322(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1322(db,b), false);
  // (crule (pre) (scan pleaf __t3mOh114 k) (body (exists st_ins (2 0 1) 1 k) (join-old st_join (1 2 3 4 0) 2 (1 2 3 4 0) k __t3mOh114 j __t29mi113 __t6WK8115) (neq j k) (join pleaf (0 1) 2 __t29mi113 j) (exists st_join_ans (0 1) 1 __t6WK8115) (join st_ins (1 2 0) 2 __t29mi113 k __t1Tua112) (join st_join_ans (0 1) 1 __t6WK8115 r)) (head (emit st_ins_ans (0 1) __t1Tua112 r)) set.slog:50 #f)
  class ReadTask1376 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1369;  slog::Index** st_joinindex1370;  slog::Index** pleafindex1371;  slog::Index** st_join_ansindex1372;  slog::Index** st_insindex1373;  slog::Index** st_join_ansindex1374;  slog::Index** st_joindelta1375;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord1377({0, 1});
      slog::Relation* readrel1378 = db->getRelation("st_ins_ans");
      head_index[0] = readrel1378->getIndex(ord1377, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1379({2, 0, 1});
      slog::Relation* readrel1380 = db->getRelation("st_ins");
      st_insindex1369 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 2, 3, 4, 0});
      slog::Relation* readrel1382 = db->getRelation("st_join");
      st_joinindex1370 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 2, 3, 4, 0});
      slog::Relation* readrel1384 = db->getRelation("st_join");
      st_joindelta1375 = readrel1384->getIndex(ord1383, true);
      std::vector<u16> ord1385({0, 1});
      slog::Relation* readrel1386 = db->getRelation("pleaf");
      pleafindex1371 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("st_join_ans");
      st_join_ansindex1372 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 2, 0});
      slog::Relation* readrel1390 = db->getRelation("st_ins");
      st_insindex1373 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({0, 1});
      slog::Relation* readrel1392 = db->getRelation("st_join_ans");
      st_join_ansindex1374 = readrel1392->getIndex(ord1391, false);
  
    }
    ReadTask1376(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c222 = _t[0];
        u64 v_c36 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex1369, std::array<u64,3>{v_c36, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex1370, st_joindelta1375, std::array<u64,5>{v_c36, v_c222, 0, 0, 0}, [&](const std::array<u64,5>& m1393) {
          u64 v_c180 = m1393[2]; u64 v_c223 = m1393[3]; u64 v_c224 = m1393[4];
          if (v_c180 == v_c36) return;
          slog::join_probe<2,2>(pleafindex1371, std::array<u64,2>{v_c223, v_c180}, [&](const std::array<u64,2>& m1394) {
            if (!slog::exists_probe<2,1>(st_join_ansindex1372, std::array<u64,2>{v_c224, 0})) return;
            slog::join_probe<3,2>(st_insindex1373, std::array<u64,3>{v_c223, v_c36, 0}, [&](const std::array<u64,3>& m1395) {
              u64 v_c225 = m1395[2];
              slog::join_probe<2,1>(st_join_ansindex1374, std::array<u64,2>{v_c224, 0}, [&](const std::array<u64,2>& m1396) {
                u64 v_c25 = m1396[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c225, v_c25}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1376* _cont = new ReadTask1376(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1376(db,b), false);
  // (crule (pre) (scan pleaf __t7CbK487 k) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t7CbK487 t __t3Y70488)) (head (mkstruct st_mem0 (1 2 0) __1sow933 t k)) set.slog:134 #f)
  class ReadTask1399 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1397;  slog::Index** st_diffdelta1398;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1400({1, 2, 0});
      slog::Relation* readrel1401 = db->getRelation("st_diff");
      st_diffindex1397 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({1, 2, 0});
      slog::Relation* readrel1403 = db->getRelation("st_diff");
      st_diffdelta1398 = readrel1403->getIndex(ord1402, true);
  
    }
    ReadTask1399(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c226 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex1397, st_diffdelta1398, std::array<u64,3>{v_c226, 0, 0}, [&](const std::array<u64,3>& m1404) {
          u64 v_c37 = m1404[1]; u64 v_c227 = m1404[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c37, v_c36}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1399* _cont = new ReadTask1399(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1399(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t0gfm348 p) (body (exists $sup9688x106x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t0gfm348 p) (exists $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t0gfm348 q m) (exists $sup9688x106x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists pbranch (1 2 3 4 0) 2 p m) (exists pbranch (1 2 3 4 0) 1 q) (join-old $sup9688x106x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t0gfm348 m q p __t7KDg345 l n r u v) (cmp lt n m) (join-old $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 9 (4 1 2 6 0 3 5 7 8) p l m r __t7KDg345 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4ii6344) (exists st_union (0 1 2) 2 __t7KDg345 __t4ii6344) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_union (0 1 2) 3 (0 1 2) __t7KDg345 __t4ii6344 __t0LeB349) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join-old st_union_ans (0 1) 1 (0 1) __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask1430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x1index1405;  slog::Index** $sup9688x106x0x0x0index1406;  slog::Index** pbranchindex1407;  slog::Index** st_mskindex1408;  slog::Index** $sup9688x106x0x0x0index1409;  slog::Index** pbranchindex1410;  slog::Index** pbranchindex1411;  slog::Index** $sup9688x106x0x0x1index1412;  slog::Index** $sup9688x106x0x0x0index1413;  slog::Index** pbranchindex1414;  slog::Index** st_unionindex1415;  slog::Index** pbranchindex1416;  slog::Index** st_unionindex1417;  slog::Index** pbranchindex1418;  slog::Index** st_unionindex1419;  slog::Index** st_unionindex1420;  slog::Index** st_union_ansindex1421;  slog::Index** st_mskdelta1422;  slog::Index** $sup9688x106x0x0x1delta1423;  slog::Index** $sup9688x106x0x0x0delta1424;  slog::Index** pbranchdelta1425;  slog::Index** pbranchdelta1426;  slog::Index** st_uniondelta1427;  slog::Index** st_uniondelta1428;  slog::Index** st_union_ansdelta1429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1431({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel1432 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index1405 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1434 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index1406 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({1, 2, 3, 4, 0});
      slog::Relation* readrel1436 = db->getRelation("pbranch");
      pbranchindex1407 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({0, 1, 2});
      slog::Relation* readrel1438 = db->getRelation("st_msk");
      st_mskindex1408 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({0, 1, 2});
      slog::Relation* readrel1440 = db->getRelation("st_msk");
      st_mskdelta1422 = readrel1440->getIndex(ord1439, true);
      std::vector<u16> ord1441({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1442 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index1409 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 2, 3, 4, 0});
      slog::Relation* readrel1444 = db->getRelation("pbranch");
      pbranchindex1410 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 2, 3, 4, 0});
      slog::Relation* readrel1446 = db->getRelation("pbranch");
      pbranchindex1411 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel1448 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index1412 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel1450 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1delta1423 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1452 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index1413 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1454 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0delta1424 = readrel1454->getIndex(ord1453, true);
      std::vector<u16> ord1455({1, 2, 3, 4, 0});
      slog::Relation* readrel1456 = db->getRelation("pbranch");
      pbranchindex1414 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 2, 0});
      slog::Relation* readrel1458 = db->getRelation("st_union");
      st_unionindex1415 = readrel1458->getIndex(ord1457, false);
      std::vector<u16> ord1459({1, 2, 3, 4, 0});
      slog::Relation* readrel1460 = db->getRelation("pbranch");
      pbranchindex1416 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({1, 2, 3, 4, 0});
      slog::Relation* readrel1462 = db->getRelation("pbranch");
      pbranchdelta1425 = readrel1462->getIndex(ord1461, true);
      std::vector<u16> ord1463({0, 1, 2});
      slog::Relation* readrel1464 = db->getRelation("st_union");
      st_unionindex1417 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 2, 3, 4, 0});
      slog::Relation* readrel1466 = db->getRelation("pbranch");
      pbranchindex1418 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({1, 2, 3, 4, 0});
      slog::Relation* readrel1468 = db->getRelation("pbranch");
      pbranchdelta1426 = readrel1468->getIndex(ord1467, true);
      std::vector<u16> ord1469({0, 1, 2});
      slog::Relation* readrel1470 = db->getRelation("st_union");
      st_unionindex1419 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({0, 1, 2});
      slog::Relation* readrel1472 = db->getRelation("st_union");
      st_uniondelta1427 = readrel1472->getIndex(ord1471, true);
      std::vector<u16> ord1473({1, 2, 0});
      slog::Relation* readrel1474 = db->getRelation("st_union");
      st_unionindex1420 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({1, 2, 0});
      slog::Relation* readrel1476 = db->getRelation("st_union");
      st_uniondelta1428 = readrel1476->getIndex(ord1475, true);
      std::vector<u16> ord1477({0, 1});
      slog::Relation* readrel1478 = db->getRelation("st_union_ans");
      st_union_ansindex1421 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({0, 1});
      slog::Relation* readrel1480 = db->getRelation("st_union_ans");
      st_union_ansdelta1429 = readrel1480->getIndex(ord1479, true);
  
    }
    ReadTask1430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c127 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<10,2>($sup9688x106x0x0x1index1405, std::array<u64,10>{v_c127, v_c22, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x106x0x0x0index1406, std::array<u64,9>{v_c22, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1407, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1408, st_mskdelta1422, std::array<u64,3>{v_c127, 0, 0}, [&](const std::array<u64,3>& m1481) {
          u64 v_c28 = m1481[1]; u64 v_c23 = m1481[2];
          if (!slog::exists_probe<9,3>($sup9688x106x0x0x0index1409, std::array<u64,9>{v_c23, v_c28, v_c22, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1410, std::array<u64,5>{v_c22, v_c23, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1411, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup9688x106x0x0x1index1412, $sup9688x106x0x0x1delta1423, std::array<u64,10>{v_c127, v_c23, v_c28, v_c22, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1482) {
            u64 v_c126 = m1482[4]; u64 v_c24 = m1482[5]; u64 v_c29 = m1482[6]; u64 v_c25 = m1482[7]; u64 v_c30 = m1482[8]; u64 v_c31 = m1482[9];
            u64 v_c228 = _prim_lt(db, v_c29, v_c23);
            if (v_c228 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c228) return;
            slog::join_probe_old<9,9>($sup9688x106x0x0x0index1413, $sup9688x106x0x0x0delta1424, std::array<u64,9>{v_c22, v_c24, v_c23, v_c25, v_c126, v_c29, v_c28, v_c30, v_c31}, [&](const std::array<u64,9>& m1484) {
              if (!slog::exists_probe<5,4>(pbranchindex1414, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0})) return;
              if (!slog::exists_probe<3,1>(st_unionindex1415, std::array<u64,3>{v_c25, 0, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1416, pbranchdelta1425, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m1485) {
                u64 v_c129 = m1485[4];
                if (!slog::exists_probe<3,2>(st_unionindex1417, std::array<u64,3>{v_c126, v_c129, 0})) return;
                slog::join_probe_old<5,4>(pbranchindex1418, pbranchdelta1426, std::array<u64,5>{v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,5>& m1486) {
                  u64 v_c130 = m1486[4];
                  slog::join_probe_old<3,3>(st_unionindex1419, st_uniondelta1427, std::array<u64,3>{v_c126, v_c129, v_c130}, [&](const std::array<u64,3>& m1487) {
                    slog::join_probe_old<3,2>(st_unionindex1420, st_uniondelta1428, std::array<u64,3>{v_c25, v_c130, 0}, [&](const std::array<u64,3>& m1488) {
                      u64 v_c131 = m1488[2];
                      slog::join_probe_old<2,1>(st_union_ansindex1421, st_union_ansdelta1429, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m1489) {
                        u64 v_c5 = m1489[1];
                        u64 v_c132 = _prim_band(db, v_c28, v_c23);
                        if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c229 = _prim_gt(db, v_c132, v_c125);
                        if (v_c229 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c229) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c126, v_c5, v_c24, v_c23, v_c22});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1430* _cont = new ReadTask1430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1430(db,b), false);
}

