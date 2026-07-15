
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4a5462bd8cd8940b1e58a782;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const81906d9241165d9f6a541e47;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_cbabdb3c6024ae24d(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst4Rwd255 const5feceb66ffc86f38d952786c)) (scan pbranch __t4MB5252 q n u v) (body (join-old st_union (2 0 1) 1 (2 0 1) __t4MB5252 __t57tc254 __t3lRY253) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3lRY253 p m l r) (cmp lt m n) (let __t7ozQ256 (band p n)) (cmp gt __t7ozQ256 __tconst4Rwd255)) (head (emit $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) __t57tc254 v l m n p q r u)) set.slog:118 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex0;  slog::Index** pbranchindex1;  slog::Index** st_uniondelta2;  slog::Index** pbranchdelta3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord5({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel6 = db->getRelation("$sup9688x117x0x0x0");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord7({2, 0, 1});
      slog::Relation* readrel8 = db->getRelation("st_union");
      st_unionindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({2, 0, 1});
      slog::Relation* readrel10 = db->getRelation("st_union");
      st_uniondelta2 = readrel10->getIndex(ord9, true);
      std::vector<u16> ord11({0, 1, 2, 3, 4});
      slog::Relation* readrel12 = db->getRelation("pbranch");
      pbranchindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({0, 1, 2, 3, 4});
      slog::Relation* readrel14 = db->getRelation("pbranch");
      pbranchdelta3 = readrel14->getIndex(ord13, true);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(st_unionindex0, st_uniondelta2, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m15) {
          u64 v_c6 = m15[1]; u64 v_c7 = m15[2];
          slog::join_probe_old<5,1>(pbranchindex1, pbranchdelta3, std::array<u64,5>{v_c7, 0, 0, 0, 0}, [&](const std::array<u64,5>& m16) {
            u64 v_c8 = m16[1]; u64 v_c9 = m16[2]; u64 v_c10 = m16[3]; u64 v_c11 = m16[4];
            u64 v_c12 = _prim_lt(db, v_c9, v_c3);
            if (v_c12 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c12) return;
            u64 v_c13 = _prim_band(db, v_c8, v_c3);
            if (v_c13 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            u64 v_c14 = _prim_gt(db, v_c13, v_c0);
            if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c14) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c6, v_c5, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c4}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_msk __t19Mr339 q m) (body (exists $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (2 0 1 3 4) 1 m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_bld (2 1 4 0 3) 1 m) (join st_msk_ans (0 1) 1 __t19Mr339 p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __t8Fy1335 l n r u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_diff (1 2 0) 1 r) (join pbranch (1 2 3 4 0) 4 p m l r __t88zt334) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join st_diff (0 1 2) 3 __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join st_bld (1 2 3 4 0) 3 p m l __v0 __t7XLn338) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join st_diff_ans (0 1) 2 __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask43 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index19;  slog::Index** pbranchindex20;  slog::Index** pbranchindex21;  slog::Index** st_bldindex22;  slog::Index** st_msk_ansindex23;  slog::Index** pbranchindex24;  slog::Index** st_bldindex25;  slog::Index** $sup9688x142x0x0x0index26;  slog::Index** pbranchindex27;  slog::Index** st_bldindex28;  slog::Index** st_diffindex29;  slog::Index** pbranchindex30;  slog::Index** st_diffindex31;  slog::Index** pbranchindex32;  slog::Index** st_diffindex33;  slog::Index** st_diffindex34;  slog::Index** st_bldindex35;  slog::Index** st_diff_ansindex36;  slog::Index** st_bld_ansindex37;  slog::Index** st_diffindex38;  slog::Index** st_diff_ansindex39;  slog::Index** st_bld_ansindex40;  slog::Index** pbranchdelta41;  slog::Index** st_diffdelta42;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("st_diff_ans");
      head_index[0] = readrel45->getIndex(ord44, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord46({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel47 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index19 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({2, 0, 1, 3, 4});
      slog::Relation* readrel49 = db->getRelation("pbranch");
      pbranchindex20 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 2, 3, 4, 0});
      slog::Relation* readrel51 = db->getRelation("pbranch");
      pbranchindex21 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({2, 1, 4, 0, 3});
      slog::Relation* readrel53 = db->getRelation("st_bld");
      st_bldindex22 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("st_msk_ans");
      st_msk_ansindex23 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 3, 4, 0});
      slog::Relation* readrel57 = db->getRelation("pbranch");
      pbranchindex24 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 3, 4, 0});
      slog::Relation* readrel59 = db->getRelation("st_bld");
      st_bldindex25 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel61 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index26 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 3, 4, 0});
      slog::Relation* readrel63 = db->getRelation("pbranch");
      pbranchindex27 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 3, 4, 0});
      slog::Relation* readrel65 = db->getRelation("st_bld");
      st_bldindex28 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 2, 0});
      slog::Relation* readrel67 = db->getRelation("st_diff");
      st_diffindex29 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 3, 4, 0});
      slog::Relation* readrel69 = db->getRelation("pbranch");
      pbranchindex30 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1, 2});
      slog::Relation* readrel71 = db->getRelation("st_diff");
      st_diffindex31 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 2, 3, 4, 0});
      slog::Relation* readrel73 = db->getRelation("pbranch");
      pbranchindex32 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 2, 3, 4, 0});
      slog::Relation* readrel75 = db->getRelation("pbranch");
      pbranchdelta41 = readrel75->getIndex(ord74, true);
      std::vector<u16> ord76({0, 1, 2});
      slog::Relation* readrel77 = db->getRelation("st_diff");
      st_diffindex33 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("st_diff");
      st_diffindex34 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 3, 4, 0});
      slog::Relation* readrel81 = db->getRelation("st_bld");
      st_bldindex35 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("st_diff_ans");
      st_diff_ansindex36 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("st_bld_ans");
      st_bld_ansindex37 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("st_diff");
      st_diffindex38 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("st_diff");
      st_diffdelta42 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("st_diff_ans");
      st_diff_ansindex39 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("st_bld_ans");
      st_bld_ansindex40 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask43(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x142x0x0x0index19, std::array<u64,9>{v_c9, v_c2, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex20, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex21, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex22, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex23, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m94) {
          u64 v_c8 = m94[1];
          if (!slog::exists_probe<5,2>(pbranchindex24, std::array<u64,5>{v_c8, v_c9, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex25, std::array<u64,5>{v_c8, v_c9, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x142x0x0x0index26, std::array<u64,9>{v_c9, v_c2, v_c8, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m95) {
            u64 v_c17 = m95[3]; u64 v_c10 = m95[4]; u64 v_c3 = m95[5]; u64 v_c11 = m95[6]; u64 v_c4 = m95[7]; u64 v_c5 = m95[8];
            u64 v_c18 = _prim_lt(db, v_c3, v_c9);
            if (v_c18 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c18) return;
            if (!slog::exists_probe<5,4>(pbranchindex27, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex28, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex29, std::array<u64,3>{v_c11, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex30, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m97) {
              u64 v_c19 = m97[4];
              if (!slog::exists_probe<3,2>(st_diffindex31, std::array<u64,3>{v_c17, v_c19, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex32, pbranchdelta41, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m98) {
                u64 v_c20 = m98[4];
                slog::join_probe<3,3>(st_diffindex33, std::array<u64,3>{v_c17, v_c19, v_c20}, [&](const std::array<u64,3>& m99) {
                  if (!slog::exists_probe<3,2>(st_diffindex34, std::array<u64,3>{v_c11, v_c20, 0})) return;
                  slog::join_probe<5,3>(st_bldindex35, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0}, [&](const std::array<u64,5>& m100) {
                    u64 v_c21 = m100[3]; u64 v_c22 = m100[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex36, std::array<u64,2>{v_c21, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex37, std::array<u64,2>{v_c22, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex38, st_diffdelta42, std::array<u64,3>{v_c11, v_c20, 0}, [&](const std::array<u64,3>& m101) {
                      u64 v_c23 = m101[2];
                      slog::join_probe<2,2>(st_diff_ansindex39, std::array<u64,2>{v_c23, v_c21}, [&](const std::array<u64,2>& m102) {
                        slog::join_probe<2,1>(st_bld_ansindex40, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m103) {
                          u64 v_c24 = m103[1];
                          u64 v_c25 = _prim_band(db, v_c2, v_c9);
                          if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c26 = _prim_gt(db, v_c25, v_c15);
                          if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c26) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c24}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask43* _cont = new ReadTask43(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask43(db,b), false);
  // (crule (pre (let __trid7SjB860 const76a4fedc25549f0939d52fb7) (let __trel152W861 consta10f76b4ec574de5d7b6908e) (let __tcol5qDL862 const5feceb66ffc86f38d952786c) (let __trel26LN863 consta10f76b4ec574de5d7b6908e) (let __tcol91vd864 const6b86b273ff34fce19d6b804e)) (scan $sup9688x88x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid7SjB860 __trel152W861 __tcol5qDL862 (1 2 3 4 0)) (tycheck m (accept int) __trid7SjB860 __trel26LN863 __tcol91vd864 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __7P2A859 k m)) set.slog:89 #f)
  class ReadTask105 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x88x0x0x0");
  
    }
    ReadTask105(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c28 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c29 = v_const5feceb66ffc86f38d952786c;
      u64 v_c30 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c11 = _t[5];
        ++_fires;
        if (!(is_int(v_c33)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c27, v_c28, v_c29, v_c33}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c9)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c30, v_c31, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c33, v_c9}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:$sup9688x88x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask105* _cont = new ReadTask105(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask105(db,b), false);
  // (crule (pre) (scan st_msk_ans __t4C16136 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t4C16136 q m) (exists $sup9688x110x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists pbranch (1 2 3 4 0) 1 q) (exists st_join (3 4 0 1 2) 1 q) (join-old pbranch (2 0 1 3 4) 1 (2 0 1 3 4) m __t9DTf133 p l r) (neq p __v0) (exists st_join (1 2 3 4 0) 3 p __t9DTf133 q) (exists st_union (1 2 0) 1 __t9DTf133) (join-old $sup9688x110x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 (1 2 4 6 7 5 0 3 8 9 10) l m p r __t9DTf133 q __t1PdV132 n __t972J134 u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t972J134) (exists st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t9DTf133 q __t972J134 __t744h135) (join-old st_union (0 1 2) 3 (0 1 2) __t1PdV132 __t9DTf133 __t972J134) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask125 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex106;  slog::Index** $sup9688x110x0x0x0index107;  slog::Index** pbranchindex108;  slog::Index** st_joinindex109;  slog::Index** pbranchindex110;  slog::Index** st_joinindex111;  slog::Index** st_unionindex112;  slog::Index** $sup9688x110x0x0x0index113;  slog::Index** pbranchindex114;  slog::Index** st_unionindex115;  slog::Index** st_joinindex116;  slog::Index** st_unionindex117;  slog::Index** st_join_ansindex118;  slog::Index** st_mskdelta119;  slog::Index** pbranchdelta120;  slog::Index** $sup9688x110x0x0x0delta121;  slog::Index** pbranchdelta122;  slog::Index** st_joindelta123;  slog::Index** st_uniondelta124;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord126({0, 1});
      slog::Relation* readrel127 = db->getRelation("st_union_ans");
      head_index[0] = readrel127->getIndex(ord126, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord128({0, 1, 2});
      slog::Relation* readrel129 = db->getRelation("st_msk");
      st_mskindex106 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({0, 1, 2});
      slog::Relation* readrel131 = db->getRelation("st_msk");
      st_mskdelta119 = readrel131->getIndex(ord130, true);
      std::vector<u16> ord132({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel133 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index107 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 3, 4, 0});
      slog::Relation* readrel135 = db->getRelation("pbranch");
      pbranchindex108 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({3, 4, 0, 1, 2});
      slog::Relation* readrel137 = db->getRelation("st_join");
      st_joinindex109 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({2, 0, 1, 3, 4});
      slog::Relation* readrel139 = db->getRelation("pbranch");
      pbranchindex110 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({2, 0, 1, 3, 4});
      slog::Relation* readrel141 = db->getRelation("pbranch");
      pbranchdelta120 = readrel141->getIndex(ord140, true);
      std::vector<u16> ord142({1, 2, 3, 4, 0});
      slog::Relation* readrel143 = db->getRelation("st_join");
      st_joinindex111 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("st_union");
      st_unionindex112 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel147 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index113 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel149 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0delta121 = readrel149->getIndex(ord148, true);
      std::vector<u16> ord150({1, 2, 3, 4, 0});
      slog::Relation* readrel151 = db->getRelation("pbranch");
      pbranchindex114 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 2, 3, 4, 0});
      slog::Relation* readrel153 = db->getRelation("pbranch");
      pbranchdelta122 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({0, 1, 2});
      slog::Relation* readrel155 = db->getRelation("st_union");
      st_unionindex115 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 2, 3, 4, 0});
      slog::Relation* readrel157 = db->getRelation("st_join");
      st_joinindex116 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 3, 4, 0});
      slog::Relation* readrel159 = db->getRelation("st_join");
      st_joindelta123 = readrel159->getIndex(ord158, true);
      std::vector<u16> ord160({0, 1, 2});
      slog::Relation* readrel161 = db->getRelation("st_union");
      st_unionindex117 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({0, 1, 2});
      slog::Relation* readrel163 = db->getRelation("st_union");
      st_uniondelta124 = readrel163->getIndex(ord162, true);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("st_join_ans");
      st_join_ansindex118 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask125(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex106, st_mskdelta119, std::array<u64,3>{v_c34, 0, 0}, [&](const std::array<u64,3>& m166) {
          u64 v_c2 = m166[1]; u64 v_c9 = m166[2];
          if (!slog::exists_probe<11,2>($sup9688x110x0x0x0index107, std::array<u64,11>{v_c9, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex108, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(st_joinindex109, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(pbranchindex110, pbranchdelta120, std::array<u64,5>{v_c9, 0, 0, 0, 0}, [&](const std::array<u64,5>& m167) {
            u64 v_c35 = m167[1]; u64 v_c8 = m167[2]; u64 v_c10 = m167[3]; u64 v_c11 = m167[4];
            if (v_c8 == v_c21) return;
            if (!slog::exists_probe<5,3>(st_joinindex111, std::array<u64,5>{v_c8, v_c35, v_c2, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_unionindex112, std::array<u64,3>{v_c35, 0, 0})) return;
            slog::join_probe_old<11,6>($sup9688x110x0x0x0index113, $sup9688x110x0x0x0delta121, std::array<u64,11>{v_c10, v_c9, v_c8, v_c11, v_c35, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m168) {
              u64 v_c36 = m168[6]; u64 v_c3 = m168[7]; u64 v_c37 = m168[8]; u64 v_c4 = m168[9]; u64 v_c5 = m168[10];
              u64 v_c38 = _prim_lt(db, v_c3, v_c9);
              if (v_c38 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
              if (!v_c38) return;
              slog::join_probe_old<5,5>(pbranchindex114, pbranchdelta122, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c37}, [&](const std::array<u64,5>& m170) {
                if (!slog::exists_probe<3,3>(st_unionindex115, std::array<u64,3>{v_c36, v_c35, v_c37})) return;
                slog::join_probe_old<5,4>(st_joinindex116, st_joindelta123, std::array<u64,5>{v_c8, v_c35, v_c2, v_c37, 0}, [&](const std::array<u64,5>& m171) {
                  u64 v_c39 = m171[4];
                  slog::join_probe_old<3,3>(st_unionindex117, st_uniondelta124, std::array<u64,3>{v_c36, v_c35, v_c37}, [&](const std::array<u64,3>& m172) {
                    slog::join_probe<2,1>(st_join_ansindex118, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m173) {
                      u64 v_c24 = m173[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c24}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre) (scan pbranch __t9Qes101 q m u v) (body (exists pbranch (2 0 1 3 4) 1 m) (join st_union (2 0 1) 1 __t9Qes101 __t419y99 __t2p3i100) (join pbranch (2 0 1 3 4) 2 m __t2p3i100 p l r) (neq p q)) (head (mkstruct st_join (1 2 3 4 0) __7vjT940 p __t2p3i100 q __t9Qes101)) set.slog:125 #f)
  class ReadTask177 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex174;  slog::Index** st_unionindex175;  slog::Index** pbranchindex176;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord178({2, 0, 1, 3, 4});
      slog::Relation* readrel179 = db->getRelation("pbranch");
      pbranchindex174 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({2, 0, 1});
      slog::Relation* readrel181 = db->getRelation("st_union");
      st_unionindex175 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({2, 0, 1, 3, 4});
      slog::Relation* readrel183 = db->getRelation("pbranch");
      pbranchindex176 = readrel183->getIndex(ord182, false);
  
    }
    ReadTask177(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex174, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(st_unionindex175, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m184) {
          u64 v_c41 = m184[1]; u64 v_c42 = m184[2];
          slog::join_probe<5,2>(pbranchindex176, std::array<u64,5>{v_c9, v_c42, 0, 0, 0}, [&](const std::array<u64,5>& m185) {
            u64 v_c8 = m185[2]; u64 v_c10 = m185[3]; u64 v_c11 = m185[4];
            if (v_c8 == v_c2) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c8, v_c42, v_c2, v_c40}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask177* _cont = new ReadTask177(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask177(db,b), false);
  // (crule (pre (let __tconst0eJ4499 const6b86b273ff34fce19d6b804e)) (scan pbranch __t5Gbs497 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t5Gbs497 __t3WTc496 __t557L498) (join pbranch (0 1 2 3 4) 1 __t3WTc496 q n u v) (cmp lt m n) (let __t85kh500 (band p n)) (cmp lt __t85kh500 __tconst0eJ4499)) (head (emit $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) __t557L498 u l m n p q r v)) set.slog:149 #f)
  class ReadTask189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex186;  slog::Index** pbranchindex187;  slog::Index** st_diffdelta188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord190({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel191 = db->getRelation("$sup9688x148x0x0x0");
      head_index[0] = readrel191->getIndex(ord190, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord192({1, 2, 0});
      slog::Relation* readrel193 = db->getRelation("st_diff");
      st_diffindex186 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("st_diff");
      st_diffdelta188 = readrel195->getIndex(ord194, true);
      std::vector<u16> ord196({0, 1, 2, 3, 4});
      slog::Relation* readrel197 = db->getRelation("pbranch");
      pbranchindex187 = readrel197->getIndex(ord196, false);
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex186, st_diffdelta188, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m198) {
          u64 v_c45 = m198[1]; u64 v_c46 = m198[2];
          slog::join_probe<5,1>(pbranchindex187, std::array<u64,5>{v_c45, 0, 0, 0, 0}, [&](const std::array<u64,5>& m199) {
            u64 v_c2 = m199[1]; u64 v_c3 = m199[2]; u64 v_c4 = m199[3]; u64 v_c5 = m199[4];
            u64 v_c47 = _prim_lt(db, v_c9, v_c3);
            if (v_c47 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c47) return;
            u64 v_c48 = _prim_band(db, v_c8, v_c3);
            if (v_c48 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            u64 v_c49 = _prim_lt(db, v_c48, v_c43);
            if (v_c49 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c49) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c46, v_c4, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c5}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask189* _cont = new ReadTask189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask189(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre0swk1241 __errf3E1I1242 __errf7Xz21243) (body) (head (emit error (0) __erre0swk1241)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord203({0});
      slog::Relation* readrel204 = db->getRelation("error");
      head_index[0] = readrel204->getIndex(ord203, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c52 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let __tconst9VVd93 const6b86b273ff34fce19d6b804e) (let __tconst8Blx94 constd4735e3a265e16eee03f5971)) (scan st_hsb __t4kHg92 x) (body (cmp lt __tconst9VVd93 x) (join st_hsb_ans (0 1) 0 __t8W3F96 __v0) (let __t1MAp95 (_0002f x __tconst8Blx94)) (join-old st_hsb (0 1) 2 (0 1) __t8W3F96 __t1MAp95) (let __t5SLx91 (_0002a __tconst8Blx94 __v0))) (head (emit-temp temp1gVy1270 __t4kHg92 __t5SLx91)) set.slog:29 #f)
  class ReadTask208 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex205;  slog::Index** st_hsbindex206;  slog::Index** st_hsbdelta207;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1gVy1270");
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex205 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({0, 1});
      slog::Relation* readrel212 = db->getRelation("st_hsb");
      st_hsbindex206 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("st_hsb");
      st_hsbdelta207 = readrel214->getIndex(ord213, true);
  
    }
    ReadTask208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c57 = _prim_lt(db, v_c53, v_c56);
        if (v_c57 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
        if (!v_c57) return;
        slog::join_all<2>(st_hsb_ansindex205, [&](const std::array<u64,2>& m216) {
          u64 v_c58 = m216[0]; u64 v_c21 = m216[1];
          u64 v_c59 = _prim__0002f(db, v_c56, v_c54);
          if (v_c59 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
          slog::join_probe_old<2,2>(st_hsbindex206, st_hsbdelta207, std::array<u64,2>{v_c58, v_c59}, [&](const std::array<u64,2>& m217) {
            u64 v_c60 = _prim__0002a(db, v_c54, v_c21);
            if (v_c60 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c55, v_c60});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:st_hsb", _fires);
  
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
  // (crule (pre) (scan temp16ye1280 l m p r v) (body (join pbranch (1 2 3 4 0) 4 p m l r __t9fqm331)) (head (mkstruct st_union (1 2 0) __6uwa1105 __t9fqm331 v)) set.slog:118 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("temp16ye1280");
      std::vector<u16> ord220({1, 2, 3, 4, 0});
      slog::Relation* readrel221 = db->getRelation("pbranch");
      pbranchindex218 = readrel221->getIndex(ord220, false);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<5,4>(pbranchindex218, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m222) {
          u64 v_c61 = m222[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c61, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:temp16ye1280", _fires);
  
      if (!_done)
      {
        ReadTask219* _cont = new ReadTask219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), false);
  // (crule (pre) (scan st_msk __t7gQz149 q m) (body (exists $sup9688x145x0x0x0 (2 5 0 1 3 4 6 7 8) 2 m q) (exists pbranch (1 2 3 4 0) 1 q) (exists pbranch (2 0 1 3 4) 1 m) (join st_msk_ans (0 1) 1 __t7gQz149 __v0) (join $sup9688x145x0x0x0 (2 5 0 1 3 4 6 7 8) 2 m q __t3Vft148 l n p r u v) (cmp lt n m) (neq p __v0) (exists pbranch (1 2 3 4 0) 4 p m l r) (join pbranch (1 2 3 4 0) 4 q n u v __t0w8p146) (exists st_diff (2 0 1) 2 __t0w8p146 __t3Vft148) (join pbranch (1 2 3 4 0) 4 p m l r __t8pVe147) (join st_diff (0 1 2) 3 __t3Vft148 __t8pVe147 __t0w8p146)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask233 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x145x0x0x0index223;  slog::Index** pbranchindex224;  slog::Index** pbranchindex225;  slog::Index** st_msk_ansindex226;  slog::Index** $sup9688x145x0x0x0index227;  slog::Index** pbranchindex228;  slog::Index** pbranchindex229;  slog::Index** st_diffindex230;  slog::Index** pbranchindex231;  slog::Index** st_diffindex232;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("st_diff_ans");
      head_index[0] = readrel235->getIndex(ord234, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord236({2, 5, 0, 1, 3, 4, 6, 7, 8});
      slog::Relation* readrel237 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index223 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("pbranch");
      pbranchindex224 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({2, 0, 1, 3, 4});
      slog::Relation* readrel241 = db->getRelation("pbranch");
      pbranchindex225 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("st_msk_ans");
      st_msk_ansindex226 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 5, 0, 1, 3, 4, 6, 7, 8});
      slog::Relation* readrel245 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index227 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 2, 3, 4, 0});
      slog::Relation* readrel247 = db->getRelation("pbranch");
      pbranchindex228 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 3, 4, 0});
      slog::Relation* readrel249 = db->getRelation("pbranch");
      pbranchindex229 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({2, 0, 1});
      slog::Relation* readrel251 = db->getRelation("st_diff");
      st_diffindex230 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 3, 4, 0});
      slog::Relation* readrel253 = db->getRelation("pbranch");
      pbranchindex231 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 1, 2});
      slog::Relation* readrel255 = db->getRelation("st_diff");
      st_diffindex232 = readrel255->getIndex(ord254, false);
  
    }
    ReadTask233(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x145x0x0x0index223, std::array<u64,9>{v_c9, v_c2, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex224, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex225, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex226, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m256) {
          u64 v_c21 = m256[1];
          slog::join_probe<9,2>($sup9688x145x0x0x0index227, std::array<u64,9>{v_c9, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m257) {
            u64 v_c63 = m257[2]; u64 v_c10 = m257[3]; u64 v_c3 = m257[4]; u64 v_c8 = m257[5]; u64 v_c11 = m257[6]; u64 v_c4 = m257[7]; u64 v_c5 = m257[8];
            u64 v_c64 = _prim_lt(db, v_c3, v_c9);
            if (v_c64 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c64) return;
            if (v_c8 == v_c21) return;
            if (!slog::exists_probe<5,4>(pbranchindex228, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0})) return;
            slog::join_probe<5,4>(pbranchindex229, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m259) {
              u64 v_c65 = m259[4];
              if (!slog::exists_probe<3,2>(st_diffindex230, std::array<u64,3>{v_c65, v_c63, 0})) return;
              slog::join_probe<5,4>(pbranchindex231, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m260) {
                u64 v_c66 = m260[4];
                slog::join_probe<3,3>(st_diffindex232, std::array<u64,3>{v_c63, v_c66, v_c65}, [&](const std::array<u64,3>& m261) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c66}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask233* _cont = new ReadTask233(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask233(db,b), false);
  // (crule (pre (let __tconst5jMg913 conste3776bfed7f405de8017ecfa) (let __tconst0zHM198 const2c624232cdd221771294dfbb)) (scan st_ins_ans __t1mgk200 __v0) (body (exists _enum (1 0) 1 __tconst5jMg913) (join-old st_ins (0 2 1) 2 (0 2 1) __t1mgk200 __tconst0zHM198 __t9gYW199) (join _enum (0 1) 2 __t9gYW199 __tconst5jMg913) (join canon (0) 0 s)) (head (emit $sup97714x23x0x0x1 (1 0 2) __v0 __t1mgk200 s)) st_basic.slog:24 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex262;  slog::Index** st_insindex263;  slog::Index** _enumindex264;  slog::Index** canonindex265;  slog::Index** st_insdelta266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord268({1, 0, 2});
      slog::Relation* readrel269 = db->getRelation("$sup97714x23x0x0x1");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("_enum");
      _enumindex262 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 2, 1});
      slog::Relation* readrel273 = db->getRelation("st_ins");
      st_insindex263 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 2, 1});
      slog::Relation* readrel275 = db->getRelation("st_ins");
      st_insdelta266 = readrel275->getIndex(ord274, true);
      std::vector<u16> ord276({0, 1});
      slog::Relation* readrel277 = db->getRelation("_enum");
      _enumindex264 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0});
      slog::Relation* readrel279 = db->getRelation("canon");
      canonindex265 = readrel279->getIndex(ord278, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c68 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex262, std::array<u64,2>{v_c67, 0})) return;
        slog::join_probe_old<3,2>(st_insindex263, st_insdelta266, std::array<u64,3>{v_c69, v_c68, 0}, [&](const std::array<u64,3>& m280) {
          u64 v_c70 = m280[2];
          slog::join_probe<2,2>(_enumindex264, std::array<u64,2>{v_c70, v_c67}, [&](const std::array<u64,2>& m281) {
            slog::join_all<1>(canonindex265, [&](const std::array<u64,1>& m282) {
              u64 v_c71 = m282[0];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c69, v_c71}, std::array<u16,3>{1, 0, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask267* _cont = new ReadTask267(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask267(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan st_union __t6dzp66 __t5Obr65 u) (body (exists st_union (1 2 0) 1 __t5Obr65) (exists pbranch (3 0 1 2 4) 1 u) (exists $sup9688x114x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (join st_union (1 2 0) 1 __t5Obr65 __t2ifW59 __t2j0W61) (exists $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t2j0W61 u) (exists $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t2j0W61 u) (join pbranch (3 0 1 2 4) 2 u __t2ifW59 q n v) (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t2j0W61) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t2j0W61 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t5Obr65) (exists st_msk (1 2 0) 2 p n) (join $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t2j0W61 l m p r __t1Zy964) (join pbranch (1 2 3 4 0) 5 p m l r __t5Obr65) (join st_msk (1 2 0) 3 p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask302 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex283;  slog::Index** pbranchindex284;  slog::Index** $sup9688x114x0x0x0index285;  slog::Index** $sup9688x114x0x0x1index286;  slog::Index** st_union_ansindex287;  slog::Index** st_unionindex288;  slog::Index** $sup9688x114x0x0x0index289;  slog::Index** $sup9688x114x0x0x1index290;  slog::Index** pbranchindex291;  slog::Index** $sup9688x114x0x0x1index292;  slog::Index** st_mskindex293;  slog::Index** st_msk_ansindex294;  slog::Index** $sup9688x114x0x0x0index295;  slog::Index** pbranchindex296;  slog::Index** st_mskindex297;  slog::Index** $sup9688x114x0x0x1index298;  slog::Index** pbranchindex299;  slog::Index** st_mskindex300;  slog::Index** st_msk_ansindex301;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("st_union");
      st_unionindex283 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({3, 0, 1, 2, 4});
      slog::Relation* readrel306 = db->getRelation("pbranch");
      pbranchindex284 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel308 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index285 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel310 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index286 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("st_union_ans");
      st_union_ansindex287 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("st_union");
      st_unionindex288 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel316 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index289 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel318 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index290 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({3, 0, 1, 2, 4});
      slog::Relation* readrel320 = db->getRelation("pbranch");
      pbranchindex291 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel322 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index292 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({2, 0, 1});
      slog::Relation* readrel324 = db->getRelation("st_msk");
      st_mskindex293 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 0});
      slog::Relation* readrel326 = db->getRelation("st_msk_ans");
      st_msk_ansindex294 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel328 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index295 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 3, 4, 0});
      slog::Relation* readrel330 = db->getRelation("pbranch");
      pbranchindex296 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("st_msk");
      st_mskindex297 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel334 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index298 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 2, 3, 4, 0});
      slog::Relation* readrel336 = db->getRelation("pbranch");
      pbranchindex299 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 2, 0});
      slog::Relation* readrel338 = db->getRelation("st_msk");
      st_mskindex300 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1});
      slog::Relation* readrel340 = db->getRelation("st_msk_ans");
      st_msk_ansindex301 = readrel340->getIndex(ord339, false);
  
    }
    ReadTask302(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<3,1>(st_unionindex283, std::array<u64,3>{v_c74, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex284, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x114x0x0x0index285, std::array<u64,9>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x114x0x0x1index286, std::array<u64,10>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex287, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m341) {
          u64 v_c21 = m341[1];
          slog::join_probe<3,1>(st_unionindex288, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m342) {
            u64 v_c75 = m342[1]; u64 v_c76 = m342[2];
            if (!slog::exists_probe<9,2>($sup9688x114x0x0x0index289, std::array<u64,9>{v_c76, v_c4, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x114x0x0x1index290, std::array<u64,10>{v_c76, v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex291, std::array<u64,5>{v_c4, v_c75, 0, 0, 0}, [&](const std::array<u64,5>& m343) {
              u64 v_c2 = m343[2]; u64 v_c3 = m343[3]; u64 v_c5 = m343[4];
              if (!slog::exists_probe<10,5>($sup9688x114x0x0x1index292, std::array<u64,10>{v_c4, v_c3, v_c2, v_c5, v_c76, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex293, std::array<u64,3>{v_c3, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex294, std::array<u64,2>{v_c2, 0})) return;
              slog::join_probe<9,5>($sup9688x114x0x0x0index295, std::array<u64,9>{v_c2, v_c3, v_c4, v_c5, v_c76, 0, 0, 0, 0}, [&](const std::array<u64,9>& m344) {
                u64 v_c10 = m344[5]; u64 v_c9 = m344[6]; u64 v_c8 = m344[7]; u64 v_c11 = m344[8];
                u64 v_c77 = _prim_lt(db, v_c9, v_c3);
                if (v_c77 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                if (!v_c77) return;
                if (!slog::exists_probe<5,5>(pbranchindex296, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c74})) return;
                if (!slog::exists_probe<3,2>(st_mskindex297, std::array<u64,3>{v_c8, v_c3, 0})) return;
                slog::join_probe<10,9>($sup9688x114x0x0x1index298, std::array<u64,10>{v_c4, v_c3, v_c2, v_c5, v_c76, v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,10>& m346) {
                  u64 v_c78 = m346[9];
                  slog::join_probe<5,5>(pbranchindex299, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c74}, [&](const std::array<u64,5>& m347) {
                    slog::join_probe<3,3>(st_mskindex300, std::array<u64,3>{v_c8, v_c3, v_c78}, [&](const std::array<u64,3>& m348) {
                      slog::join_probe<2,2>(st_msk_ansindex301, std::array<u64,2>{v_c78, v_c2}, [&](const std::array<u64,2>& m349) {
                        u64 v_c79 = _prim_band(db, v_c8, v_c3);
                        if (v_c79 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c80 = _prim_lt(db, v_c79, v_c72);
                        if (v_c80 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c80) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c76, v_c21, v_c3, v_c2, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c21, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask302* _cont = new ReadTask302(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask302(db,b), false);
  // (crule (pre) (scan st_ins __t37YR310 __t0A4U311 k) (body (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t0A4U311 p m l r)) (head (emit $sup9688x54x0x0x0 (1 3 0 2 4 5 6) k m __t37YR310 l p r __t0A4U311)) set.slog:55 #f)
  class ReadTask353 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex351;  slog::Index** pbranchdelta352;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord354({1, 3, 0, 2, 4, 5, 6});
      slog::Relation* readrel355 = db->getRelation("$sup9688x54x0x0x0");
      head_index[0] = readrel355->getIndex(ord354, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord356({0, 1, 2, 3, 4});
      slog::Relation* readrel357 = db->getRelation("pbranch");
      pbranchindex351 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({0, 1, 2, 3, 4});
      slog::Relation* readrel359 = db->getRelation("pbranch");
      pbranchdelta352 = readrel359->getIndex(ord358, true);
  
    }
    ReadTask353(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[1];
        u64 v_c33 = _t[2];
        slog::join_probe_old<5,1>(pbranchindex351, pbranchdelta352, std::array<u64,5>{v_c82, 0, 0, 0, 0}, [&](const std::array<u64,5>& m360) {
          u64 v_c8 = m360[1]; u64 v_c9 = m360[2]; u64 v_c10 = m360[3]; u64 v_c11 = m360[4];
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c33, v_c9, v_c81, v_c10, v_c8, v_c11, v_c82}, std::array<u16,7>{1, 3, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_ins", _fires);
  
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
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan st_mem0 __t6uqp323 __t7Uqa322 k) (body (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join $sup9688x70x0x0x0 (0 1 2 3 4 5) 2 __t6uqp323 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t7Uqa322) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old st_mem0 (1 2 0) 2 (1 2 0) l k __t14DN326) (exists st_mem0_ans (0 1) 1 __t14DN326) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t3nJI327) (join st_msk_ans (0 1) 2 __t3nJI327 p) (join st_mem0_ans (0 1) 1 __t14DN326 a) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask374 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index361;  slog::Index** st_mskindex362;  slog::Index** $sup9688x70x0x0x0index363;  slog::Index** pbranchindex364;  slog::Index** st_mskindex365;  slog::Index** st_msk_ansindex366;  slog::Index** st_mem0index367;  slog::Index** st_mem0_ansindex368;  slog::Index** st_mskindex369;  slog::Index** st_msk_ansindex370;  slog::Index** st_mem0_ansindex371;  slog::Index** st_mem0delta372;  slog::Index** st_mskdelta373;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord375({0, 1});
      slog::Relation* readrel376 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel376->getIndex(ord375, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord377({2, 0, 1});
      slog::Relation* readrel378 = db->getRelation("st_mem0");
      st_mem0index361 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 2, 0});
      slog::Relation* readrel380 = db->getRelation("st_msk");
      st_mskindex362 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel382 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index363 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 2, 3, 4, 0});
      slog::Relation* readrel384 = db->getRelation("pbranch");
      pbranchindex364 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 2, 0});
      slog::Relation* readrel386 = db->getRelation("st_msk");
      st_mskindex365 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 0});
      slog::Relation* readrel388 = db->getRelation("st_msk_ans");
      st_msk_ansindex366 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_mem0");
      st_mem0index367 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("st_mem0");
      st_mem0delta372 = readrel392->getIndex(ord391, true);
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex368 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("st_msk");
      st_mskindex369 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("st_msk");
      st_mskdelta373 = readrel398->getIndex(ord397, true);
      std::vector<u16> ord399({0, 1});
      slog::Relation* readrel400 = db->getRelation("st_msk_ans");
      st_msk_ansindex370 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex371 = readrel402->getIndex(ord401, false);
  
    }
    ReadTask374(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c33 = _t[2];
        if (!slog::exists_probe<3,1>(st_mem0index361, std::array<u64,3>{v_c33, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex362, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x70x0x0x0index363, std::array<u64,6>{v_c84, v_c33, 0, 0, 0, 0}, [&](const std::array<u64,6>& m403) {
          u64 v_c10 = m403[2]; u64 v_c9 = m403[3]; u64 v_c8 = m403[4]; u64 v_c11 = m403[5];
          slog::join_probe<5,5>(pbranchindex364, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c85}, [&](const std::array<u64,5>& m404) {
            if (!slog::exists_probe<3,2>(st_mskindex365, std::array<u64,3>{v_c33, v_c9, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex366, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe_old<3,2>(st_mem0index367, st_mem0delta372, std::array<u64,3>{v_c10, v_c33, 0}, [&](const std::array<u64,3>& m405) {
              u64 v_c86 = m405[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex368, std::array<u64,2>{v_c86, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex369, st_mskdelta373, std::array<u64,3>{v_c33, v_c9, 0}, [&](const std::array<u64,3>& m406) {
                u64 v_c87 = m406[2];
                slog::join_probe<2,2>(st_msk_ansindex370, std::array<u64,2>{v_c87, v_c8}, [&](const std::array<u64,2>& m407) {
                  slog::join_probe<2,1>(st_mem0_ansindex371, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m408) {
                    u64 v_c88 = m408[1];
                    u64 v_c89 = _prim_band(db, v_c33, v_c9);
                    if (v_c89 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c90 = _prim_lt(db, v_c89, v_c83);
                    if (v_c90 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c90) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c88}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask374* _cont = new ReadTask374(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask374(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t6eAo458 a) (body (exists _enum (1 0) 1 __tconst19LZ687) (exists st_ins (2 0 1) 1 __tconst6nio451) (exists st_ins (2 0 1) 1 __tconst5Crw454) (exists st_ins (2 0 1) 1 __tconst776G459) (join-old st_ins (0 2 1) 2 (0 2 1) __t6eAo458 __tconst7cMm457 __v0) (exists st_ins_ans (1 0) 1 __v0) (join _enum (1 0) 1 __tconst19LZ687 __t82EP455) (exists st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst6nio451 __t6TRN453) (join st_ins_ans (0 1) 2 __t6TRN453 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst5Crw454 __t7k0a456) (join st_ins_ans (0 1) 1 __t7k0a456 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (join-old st_ins_ans (0 1) 1 (0 1) __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask429 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex410;  slog::Index** st_insindex411;  slog::Index** st_insindex412;  slog::Index** st_insindex413;  slog::Index** st_insindex414;  slog::Index** st_ins_ansindex415;  slog::Index** _enumindex416;  slog::Index** st_insindex417;  slog::Index** st_insindex418;  slog::Index** st_ins_ansindex419;  slog::Index** st_insindex420;  slog::Index** st_ins_ansindex421;  slog::Index** st_insindex422;  slog::Index** st_ins_ansindex423;  slog::Index** st_insdelta424;  slog::Index** st_insdelta425;  slog::Index** st_insdelta426;  slog::Index** st_insdelta427;  slog::Index** st_ins_ansdelta428;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("_enum");
      _enumindex410 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({2, 0, 1});
      slog::Relation* readrel433 = db->getRelation("st_ins");
      st_insindex411 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({2, 0, 1});
      slog::Relation* readrel435 = db->getRelation("st_ins");
      st_insindex412 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({2, 0, 1});
      slog::Relation* readrel437 = db->getRelation("st_ins");
      st_insindex413 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 2, 1});
      slog::Relation* readrel439 = db->getRelation("st_ins");
      st_insindex414 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 2, 1});
      slog::Relation* readrel441 = db->getRelation("st_ins");
      st_insdelta424 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({1, 0});
      slog::Relation* readrel443 = db->getRelation("st_ins_ans");
      st_ins_ansindex415 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 0});
      slog::Relation* readrel445 = db->getRelation("_enum");
      _enumindex416 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 2, 0});
      slog::Relation* readrel447 = db->getRelation("st_ins");
      st_insindex417 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({1, 2, 0});
      slog::Relation* readrel449 = db->getRelation("st_ins");
      st_insindex418 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 2, 0});
      slog::Relation* readrel451 = db->getRelation("st_ins");
      st_insdelta425 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1});
      slog::Relation* readrel453 = db->getRelation("st_ins_ans");
      st_ins_ansindex419 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("st_ins");
      st_insindex420 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("st_ins");
      st_insdelta426 = readrel457->getIndex(ord456, true);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("st_ins_ans");
      st_ins_ansindex421 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("st_ins");
      st_insindex422 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("st_ins");
      st_insdelta427 = readrel463->getIndex(ord462, true);
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("st_ins_ans");
      st_ins_ansindex423 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("st_ins_ans");
      st_ins_ansdelta428 = readrel467->getIndex(ord466, true);
  
    }
    ReadTask429(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c92 = v_constef2d127de37b942baad06145;
      u64 v_c93 = v_constd4735e3a265e16eee03f5971;
      u64 v_c94 = v_const2c624232cdd221771294dfbb;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        u64 v_c88 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex410, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex411, std::array<u64,3>{v_c92, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex412, std::array<u64,3>{v_c93, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex413, std::array<u64,3>{v_c95, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex414, st_insdelta424, std::array<u64,3>{v_c96, v_c94, 0}, [&](const std::array<u64,3>& m468) {
          u64 v_c21 = m468[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex415, std::array<u64,2>{v_c21, 0})) return;
          slog::join_probe<2,1>(_enumindex416, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m469) {
            u64 v_c97 = m469[1];
            if (!slog::exists_probe<3,2>(st_insindex417, std::array<u64,3>{v_c97, v_c93, 0})) return;
            slog::join_probe_old<3,2>(st_insindex418, st_insdelta425, std::array<u64,3>{v_c97, v_c92, 0}, [&](const std::array<u64,3>& m470) {
              u64 v_c98 = m470[2];
              slog::join_probe<2,2>(st_ins_ansindex419, std::array<u64,2>{v_c98, v_c21}, [&](const std::array<u64,2>& m471) {
                slog::join_probe_old<3,2>(st_insindex420, st_insdelta426, std::array<u64,3>{v_c97, v_c93, 0}, [&](const std::array<u64,3>& m472) {
                  u64 v_c99 = m472[2];
                  slog::join_probe<2,1>(st_ins_ansindex421, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m473) {
                    u64 v_c100 = m473[1];
                    slog::join_probe_old<3,2>(st_insindex422, st_insdelta427, std::array<u64,3>{v_c100, v_c95, 0}, [&](const std::array<u64,3>& m474) {
                      u64 v_c101 = m474[2];
                      slog::join_probe_old<2,1>(st_ins_ansindex423, st_ins_ansdelta428, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m475) {
                        u64 v_c102 = m475[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c88, v_c102}, std::array<u16,3>{1, 2, 0});
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
        ReadTask429* _cont = new ReadTask429(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask429(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst7Eph382 __t0FtX383 __v0) (body (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins_ans (1 0) 1 __v0) (exists st_ins_ans (0 1) 1 __t0FtX383) (exists st_ins (2 0 1) 1 __tconst4emd384) (exists st_ins (2 0 1) 1 __tconst2ksI386) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join st_ins (1 2 0) 2 __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 2 __t2Q6o381 __v0) (join st_ins_ans (0 1) 1 __t0FtX383 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4emd384 __t88YX385) (join st_ins_ans (0 1) 1 __t88YX385 __v2) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (join st_ins_ans (0 1) 1 __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex476;  slog::Index** st_ins_ansindex477;  slog::Index** st_ins_ansindex478;  slog::Index** st_insindex479;  slog::Index** st_insindex480;  slog::Index** _enumindex481;  slog::Index** st_insindex482;  slog::Index** st_ins_ansindex483;  slog::Index** st_ins_ansindex484;  slog::Index** st_insindex485;  slog::Index** st_ins_ansindex486;  slog::Index** st_insindex487;  slog::Index** st_ins_ansindex488;  slog::Index** st_insdelta489;  slog::Index** st_insdelta490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord492({0});
      slog::Relation* readrel493 = db->getRelation("canon");
      head_index[0] = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({2, 0, 1});
      slog::Relation* readrel495 = db->getRelation("st_ins");
      driver_index = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({2, 0, 1});
      slog::Relation* readrel497 = db->getRelation("st_ins");
      st_insindex476 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 0});
      slog::Relation* readrel499 = db->getRelation("st_ins_ans");
      st_ins_ansindex477 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 1});
      slog::Relation* readrel501 = db->getRelation("st_ins_ans");
      st_ins_ansindex478 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({2, 0, 1});
      slog::Relation* readrel503 = db->getRelation("st_ins");
      st_insindex479 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({2, 0, 1});
      slog::Relation* readrel505 = db->getRelation("st_ins");
      st_insindex480 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 0});
      slog::Relation* readrel507 = db->getRelation("_enum");
      _enumindex481 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("st_ins");
      st_insindex482 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({0, 1});
      slog::Relation* readrel511 = db->getRelation("st_ins_ans");
      st_ins_ansindex483 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("st_ins_ans");
      st_ins_ansindex484 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 2, 0});
      slog::Relation* readrel515 = db->getRelation("st_ins");
      st_insindex485 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("st_ins");
      st_insdelta489 = readrel517->getIndex(ord516, true);
      std::vector<u16> ord518({0, 1});
      slog::Relation* readrel519 = db->getRelation("st_ins_ans");
      st_ins_ansindex486 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 2, 0});
      slog::Relation* readrel521 = db->getRelation("st_ins");
      st_insindex487 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("st_ins");
      st_insdelta490 = readrel523->getIndex(ord522, true);
      std::vector<u16> ord524({0, 1});
      slog::Relation* readrel525 = db->getRelation("st_ins_ans");
      st_ins_ansindex488 = readrel525->getIndex(ord524, false);
  
    }
    ReadTask491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c104 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c105 = v_const2c624232cdd221771294dfbb;
      u64 v_c106 = v_constd4735e3a265e16eee03f5971;
      u64 v_c107 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c105, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m526) {
        u64 v_c108 = m526[1];
        u64 v_c21 = m526[2];
        if (buckethash(v_c108) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex476, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex477, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex478, std::array<u64,2>{v_c108, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex479, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex480, std::array<u64,3>{v_c107, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex481, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m527) {
          u64 v_c109 = m527[1];
          slog::join_probe<3,2>(st_insindex482, std::array<u64,3>{v_c109, v_c104, 0}, [&](const std::array<u64,3>& m528) {
            u64 v_c110 = m528[2];
            slog::join_probe<2,2>(st_ins_ansindex483, std::array<u64,2>{v_c110, v_c21}, [&](const std::array<u64,2>& m529) {
              slog::join_probe<2,1>(st_ins_ansindex484, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m530) {
                u64 v_c100 = m530[1];
                slog::join_probe_old<3,2>(st_insindex485, st_insdelta489, std::array<u64,3>{v_c100, v_c106, 0}, [&](const std::array<u64,3>& m531) {
                  u64 v_c111 = m531[2];
                  slog::join_probe<2,1>(st_ins_ansindex486, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m532) {
                    u64 v_c112 = m532[1];
                    slog::join_probe_old<3,2>(st_insindex487, st_insdelta490, std::array<u64,3>{v_c112, v_c107, 0}, [&](const std::array<u64,3>& m533) {
                      u64 v_c113 = m533[2];
                      slog::join_probe<2,1>(st_ins_ansindex488, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m534) {
                        u64 v_c11 = m534[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
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
        ReadTask491* _cont = new ReadTask491(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask491(db,b), false);
  // (crule (pre) (scan pleaf __t5fUY274 k) (body (exists st_del (2 0 1) 1 k) (join-old st_diff (2 0 1) 1 (2 0 1) __t5fUY274 __t6ID7275 s) (join-old st_del (1 2 0) 2 (1 2 0) s k __t8BXn276) (join st_del_ans (0 1) 1 __t8BXn276 r)) (head (emit st_diff_ans (0 1) __t6ID7275 r)) set.slog:133 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex535;  slog::Index** st_diffindex536;  slog::Index** st_delindex537;  slog::Index** st_del_ansindex538;  slog::Index** st_diffdelta539;  slog::Index** st_deldelta540;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("st_diff_ans");
      head_index[0] = readrel543->getIndex(ord542, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord544({2, 0, 1});
      slog::Relation* readrel545 = db->getRelation("st_del");
      st_delindex535 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({2, 0, 1});
      slog::Relation* readrel547 = db->getRelation("st_diff");
      st_diffindex536 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({2, 0, 1});
      slog::Relation* readrel549 = db->getRelation("st_diff");
      st_diffdelta539 = readrel549->getIndex(ord548, true);
      std::vector<u16> ord550({1, 2, 0});
      slog::Relation* readrel551 = db->getRelation("st_del");
      st_delindex537 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 0});
      slog::Relation* readrel553 = db->getRelation("st_del");
      st_deldelta540 = readrel553->getIndex(ord552, true);
      std::vector<u16> ord554({0, 1});
      slog::Relation* readrel555 = db->getRelation("st_del_ans");
      st_del_ansindex538 = readrel555->getIndex(ord554, false);
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c114 = _t[0];
        u64 v_c33 = _t[1];
        if (!slog::exists_probe<3,1>(st_delindex535, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex536, st_diffdelta539, std::array<u64,3>{v_c114, 0, 0}, [&](const std::array<u64,3>& m556) {
          u64 v_c115 = m556[1]; u64 v_c71 = m556[2];
          slog::join_probe_old<3,2>(st_delindex537, st_deldelta540, std::array<u64,3>{v_c71, v_c33, 0}, [&](const std::array<u64,3>& m557) {
            u64 v_c116 = m557[2];
            slog::join_probe<2,1>(st_del_ansindex538, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m558) {
              u64 v_c11 = m558[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c115, v_c11}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask541* _cont = new ReadTask541(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask541(db,b), false);
  // (crule (pre (let __tconst3xtE191 const6b86b273ff34fce19d6b804e)) (scan st_union __t1CMK190 __t8Eum189 __t1xmG188) (body (join pbranch (0 1 2 3 4) 1 __t1xmG188 q n u v) (join pbranch (0 1 2 3 4) 1 __t8Eum189 p m l r) (cmp lt n m) (let __t1Yb7192 (band q m)) (cmp lt __t1Yb7192 __tconst3xtE191)) (head (emit $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) __t1CMK190 l m n p q r u v)) set.slog:104 #f)
  class ReadTask561 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex559;  slog::Index** pbranchindex560;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord562({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel563 = db->getRelation("$sup9688x103x0x0x0");
      head_index[0] = readrel563->getIndex(ord562, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord564({0, 1, 2, 3, 4});
      slog::Relation* readrel565 = db->getRelation("pbranch");
      pbranchindex559 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1, 2, 3, 4});
      slog::Relation* readrel567 = db->getRelation("pbranch");
      pbranchindex560 = readrel567->getIndex(ord566, false);
  
    }
    ReadTask561(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c118 = _t[0];
        u64 v_c119 = _t[1];
        u64 v_c120 = _t[2];
        slog::join_probe<5,1>(pbranchindex559, std::array<u64,5>{v_c120, 0, 0, 0, 0}, [&](const std::array<u64,5>& m568) {
          u64 v_c2 = m568[1]; u64 v_c3 = m568[2]; u64 v_c4 = m568[3]; u64 v_c5 = m568[4];
          slog::join_probe<5,1>(pbranchindex560, std::array<u64,5>{v_c119, 0, 0, 0, 0}, [&](const std::array<u64,5>& m569) {
            u64 v_c8 = m569[1]; u64 v_c9 = m569[2]; u64 v_c10 = m569[3]; u64 v_c11 = m569[4];
            u64 v_c121 = _prim_lt(db, v_c3, v_c9);
            if (v_c121 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c121) return;
            u64 v_c122 = _prim_band(db, v_c2, v_c9);
            if (v_c122 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            u64 v_c123 = _prim_lt(db, v_c122, v_c117);
            if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c123) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c118, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c4, v_c5}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask561* _cont = new ReadTask561(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask561(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan pbranch __t6ACr164 q n u v) (body (exists st_diff (2 0 1) 1 __t6ACr164) (exists st_msk (1 2 0) 1 q) (join $sup9688x139x0x0x0 (3 5 7 8 1 0 2 4 6) 4 n q u v l __t3X8M159 m p r) (cmp lt n m) (exists st_diff (2 0 1) 2 __t6ACr164 __t3X8M159) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 2 l __t6ACr164) (join pbranch (1 2 3 4 0) 4 p m l r __t66RN158) (join st_diff (0 1 2) 3 __t3X8M159 __t66RN158 __t6ACr164) (join st_bld (2 1 4 0 3) 3 m p r __t1RXD162 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join st_msk (1 2 0) 2 q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask591 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex572;  slog::Index** st_mskindex573;  slog::Index** $sup9688x139x0x0x0index574;  slog::Index** st_diffindex575;  slog::Index** st_bldindex576;  slog::Index** st_mskindex577;  slog::Index** st_msk_ansindex578;  slog::Index** st_diffindex579;  slog::Index** pbranchindex580;  slog::Index** st_diffindex581;  slog::Index** st_bldindex582;  slog::Index** st_diff_ansindex583;  slog::Index** st_bld_ansindex584;  slog::Index** st_mskindex585;  slog::Index** st_msk_ansindex586;  slog::Index** st_diffindex587;  slog::Index** st_diff_ansindex588;  slog::Index** st_bld_ansindex589;  slog::Index** st_diffdelta590;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord592({0, 1});
      slog::Relation* readrel593 = db->getRelation("st_diff_ans");
      head_index[0] = readrel593->getIndex(ord592, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord594({2, 0, 1});
      slog::Relation* readrel595 = db->getRelation("st_diff");
      st_diffindex572 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 2, 0});
      slog::Relation* readrel597 = db->getRelation("st_msk");
      st_mskindex573 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({3, 5, 7, 8, 1, 0, 2, 4, 6});
      slog::Relation* readrel599 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index574 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({2, 0, 1});
      slog::Relation* readrel601 = db->getRelation("st_diff");
      st_diffindex575 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({2, 1, 4, 0, 3});
      slog::Relation* readrel603 = db->getRelation("st_bld");
      st_bldindex576 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 2, 0});
      slog::Relation* readrel605 = db->getRelation("st_msk");
      st_mskindex577 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("st_msk_ans");
      st_msk_ansindex578 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 2, 0});
      slog::Relation* readrel609 = db->getRelation("st_diff");
      st_diffindex579 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 3, 4, 0});
      slog::Relation* readrel611 = db->getRelation("pbranch");
      pbranchindex580 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({0, 1, 2});
      slog::Relation* readrel613 = db->getRelation("st_diff");
      st_diffindex581 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({2, 1, 4, 0, 3});
      slog::Relation* readrel615 = db->getRelation("st_bld");
      st_bldindex582 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 0});
      slog::Relation* readrel617 = db->getRelation("st_diff_ans");
      st_diff_ansindex583 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("st_bld_ans");
      st_bld_ansindex584 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("st_msk");
      st_mskindex585 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("st_msk_ans");
      st_msk_ansindex586 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("st_diff");
      st_diffindex587 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("st_diff");
      st_diffdelta590 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({0, 1});
      slog::Relation* readrel629 = db->getRelation("st_diff_ans");
      st_diff_ansindex588 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({0, 1});
      slog::Relation* readrel631 = db->getRelation("st_bld_ans");
      st_bld_ansindex589 = readrel631->getIndex(ord630, false);
  
    }
    ReadTask591(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c125 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex572, std::array<u64,3>{v_c125, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex573, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x139x0x0x0index574, std::array<u64,9>{v_c3, v_c2, v_c4, v_c5, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m632) {
          u64 v_c10 = m632[4]; u64 v_c126 = m632[5]; u64 v_c9 = m632[6]; u64 v_c8 = m632[7]; u64 v_c11 = m632[8];
          u64 v_c127 = _prim_lt(db, v_c3, v_c9);
          if (v_c127 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
          if (!v_c127) return;
          if (!slog::exists_probe<3,2>(st_diffindex575, std::array<u64,3>{v_c125, v_c126, 0})) return;
          if (!slog::exists_probe<5,3>(st_bldindex576, std::array<u64,5>{v_c9, v_c8, v_c11, 0, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex577, std::array<u64,3>{v_c2, v_c9, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex578, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex579, std::array<u64,3>{v_c10, v_c125, 0})) return;
          slog::join_probe<5,4>(pbranchindex580, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m634) {
            u64 v_c128 = m634[4];
            slog::join_probe<3,3>(st_diffindex581, std::array<u64,3>{v_c126, v_c128, v_c125}, [&](const std::array<u64,3>& m635) {
              slog::join_probe<5,3>(st_bldindex582, std::array<u64,5>{v_c9, v_c8, v_c11, 0, 0}, [&](const std::array<u64,5>& m636) {
                u64 v_c129 = m636[3]; u64 v_c21 = m636[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex583, std::array<u64,2>{v_c21, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex584, std::array<u64,2>{v_c129, 0})) return;
                slog::join_probe<3,2>(st_mskindex585, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m637) {
                  u64 v_c130 = m637[2];
                  slog::join_probe<2,2>(st_msk_ansindex586, std::array<u64,2>{v_c130, v_c8}, [&](const std::array<u64,2>& m638) {
                    slog::join_probe_old<3,2>(st_diffindex587, st_diffdelta590, std::array<u64,3>{v_c10, v_c125, 0}, [&](const std::array<u64,3>& m639) {
                      u64 v_c131 = m639[2];
                      slog::join_probe<2,2>(st_diff_ansindex588, std::array<u64,2>{v_c131, v_c21}, [&](const std::array<u64,2>& m640) {
                        slog::join_probe<2,1>(st_bld_ansindex589, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m641) {
                          u64 v_c24 = m641[1];
                          u64 v_c132 = _prim_band(db, v_c2, v_c9);
                          if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c133 = _prim_lt(db, v_c132, v_c124);
                          if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c133) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c126, v_c24}, std::array<u16,2>{0, 1});
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
        ReadTask591* _cont = new ReadTask591(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask591(db,b), false);
  // (crule (pre (let __trid4fMs901 const4a5462bd8cd8940b1e58a782) (let __trel8erD902 consta10f76b4ec574de5d7b6908e) (let __tcol4fug903 const5feceb66ffc86f38d952786c) (let __trel6kmL904 consta10f76b4ec574de5d7b6908e) (let __tcol29Pn905 const6b86b273ff34fce19d6b804e)) (scan $sup9688x120x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid4fMs901 __trel8erD902 __tcol4fug903 (1 2 3 4 0)) (tycheck n (accept int) __trid4fMs901 __trel6kmL904 __tcol29Pn905 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __6r6T900 p n)) set.slog:121 #f)
  class ReadTask643 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x120x0x0x0");
  
    }
    ReadTask643(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const4a5462bd8cd8940b1e58a782;
      u64 v_c135 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c136 = v_const5feceb66ffc86f38d952786c;
      u64 v_c137 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c32 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c11 = _t[6];
        u64 v_c71 = _t[7];
        u64 v_c139 = _t[8];
        u64 v_c4 = _t[9];
        u64 v_c5 = _t[10];
        ++_fires;
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c134, v_c135, v_c136, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c134, v_c137, v_c138, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:$sup9688x120x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask643* _cont = new ReadTask643(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask643(db,b), false);
  // (crule (pre (let __tconst01np70 const5feceb66ffc86f38d952786c)) (scan pbranch __t3Sw268 p m l r) (body (join-old st_mem0 (1 2 0) 1 (1 2 0) __t3Sw268 k __t2gxF69) (let __t3fsQ71 (band k m)) (cmp gt __t3fsQ71 __tconst01np70)) (head (emit $sup9688x72x0x0x0 (4 2 3 5 0 1) p l m r __t2gxF69 k)) set.slog:73 #f)
  class ReadTask646 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index644;  slog::Index** st_mem0delta645;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord647({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel648 = db->getRelation("$sup9688x72x0x0x0");
      head_index[0] = readrel648->getIndex(ord647, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord649({1, 2, 0});
      slog::Relation* readrel650 = db->getRelation("st_mem0");
      st_mem0index644 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 2, 0});
      slog::Relation* readrel652 = db->getRelation("st_mem0");
      st_mem0delta645 = readrel652->getIndex(ord651, true);
  
    }
    ReadTask646(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c141 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        slog::join_probe_old<3,1>(st_mem0index644, st_mem0delta645, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m653) {
          u64 v_c33 = m653[1]; u64 v_c142 = m653[2];
          u64 v_c143 = _prim_band(db, v_c33, v_c9);
          if (v_c143 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
          u64 v_c144 = _prim_gt(db, v_c143, v_c140);
          if (v_c144 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
          if (!v_c144) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c8, v_c10, v_c9, v_c11, v_c142, v_c33}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:pbranch", _fires);
  
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
  // (crule (pre) (scan malformed_deduction __erre8Wci1233 __errf7GKW1234 __errf5CLe1235 __errf7PWR1236 __errf8tr61237) (body) (head (emit error (0) __erre8Wci1233)) <internal>:1 #f)
  class ReadTask655 : public slog::Task
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
      std::vector<u16> ord656({0});
      slog::Relation* readrel657 = db->getRelation("error");
      head_index[0] = readrel657->getIndex(ord656, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask655(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[1];
        u64 v_c147 = _t[2];
        u64 v_c148 = _t[3];
        u64 v_c149 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c145}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask655* _cont = new ReadTask655(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask655(db,b), false);
  // (crule (pre) (scan st_diff __t5hAF513 __t1YwN512 __t2KHS511) (body (join pbranch (0 1 2 3 4) 1 __t2KHS511 q n u v) (join pbranch (0 1 2 3 4) 1 __t1YwN512 p m l r) (cmp lt n m)) (head (emit $sup9688x145x0x0x0 (0 1 2 3 4 5 6 7 8) __t5hAF513 l m n p q r u v)) set.slog:146 #f)
  class ReadTask660 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex658;  slog::Index** pbranchindex659;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord661({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel662 = db->getRelation("$sup9688x145x0x0x0");
      head_index[0] = readrel662->getIndex(ord661, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord663({0, 1, 2, 3, 4});
      slog::Relation* readrel664 = db->getRelation("pbranch");
      pbranchindex658 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({0, 1, 2, 3, 4});
      slog::Relation* readrel666 = db->getRelation("pbranch");
      pbranchindex659 = readrel666->getIndex(ord665, false);
  
    }
    ReadTask660(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c151 = _t[1];
        u64 v_c152 = _t[2];
        slog::join_probe<5,1>(pbranchindex658, std::array<u64,5>{v_c152, 0, 0, 0, 0}, [&](const std::array<u64,5>& m667) {
          u64 v_c2 = m667[1]; u64 v_c3 = m667[2]; u64 v_c4 = m667[3]; u64 v_c5 = m667[4];
          slog::join_probe<5,1>(pbranchindex659, std::array<u64,5>{v_c151, 0, 0, 0, 0}, [&](const std::array<u64,5>& m668) {
            u64 v_c8 = m668[1]; u64 v_c9 = m668[2]; u64 v_c10 = m668[3]; u64 v_c11 = m668[4];
            u64 v_c153 = _prim_lt(db, v_c3, v_c9);
            if (v_c153 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c153) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c150, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c4, v_c5}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask660* _cont = new ReadTask660(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask660(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan st_union __t7KDg345 __t4ii6344 __t0LeB349) (body (exists $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) 1 __t7KDg345) (exists $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) 1 __t7KDg345) (join-old st_union (2 0 1) 1 (2 0 1) __t0LeB349 __t4u97350 r) (exists $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t7KDg345 r) (exists $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t7KDg345 r) (exists st_union_ans (0 1) 1 __t4u97350) (join pbranch (4 0 1 2 3) 2 r __t4ii6344 p m l) (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t7KDg345) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t7KDg345 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t0LeB349) (exists st_msk (1 2 0) 2 q m) (join $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t7KDg345 n q u v __t0gfm348) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask691 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x0index670;  slog::Index** $sup9688x106x0x0x1index671;  slog::Index** st_unionindex672;  slog::Index** $sup9688x106x0x0x0index673;  slog::Index** $sup9688x106x0x0x1index674;  slog::Index** st_union_ansindex675;  slog::Index** pbranchindex676;  slog::Index** $sup9688x106x0x0x1index677;  slog::Index** st_mskindex678;  slog::Index** st_msk_ansindex679;  slog::Index** $sup9688x106x0x0x0index680;  slog::Index** pbranchindex681;  slog::Index** st_mskindex682;  slog::Index** $sup9688x106x0x0x1index683;  slog::Index** pbranchindex684;  slog::Index** st_mskindex685;  slog::Index** st_msk_ansindex686;  slog::Index** st_union_ansindex687;  slog::Index** st_uniondelta688;  slog::Index** pbranchdelta689;  slog::Index** st_mskdelta690;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord692({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel693 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index670 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel695 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index671 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({2, 0, 1});
      slog::Relation* readrel697 = db->getRelation("st_union");
      st_unionindex672 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({2, 0, 1});
      slog::Relation* readrel699 = db->getRelation("st_union");
      st_uniondelta688 = readrel699->getIndex(ord698, true);
      std::vector<u16> ord700({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel701 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index673 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel703 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index674 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 1});
      slog::Relation* readrel705 = db->getRelation("st_union_ans");
      st_union_ansindex675 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({4, 0, 1, 2, 3});
      slog::Relation* readrel707 = db->getRelation("pbranch");
      pbranchindex676 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel709 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index677 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({2, 0, 1});
      slog::Relation* readrel711 = db->getRelation("st_msk");
      st_mskindex678 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 0});
      slog::Relation* readrel713 = db->getRelation("st_msk_ans");
      st_msk_ansindex679 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel715 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index680 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 3, 4, 0});
      slog::Relation* readrel717 = db->getRelation("pbranch");
      pbranchindex681 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 2, 0});
      slog::Relation* readrel719 = db->getRelation("st_msk");
      st_mskindex682 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel721 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index683 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 3, 4, 0});
      slog::Relation* readrel723 = db->getRelation("pbranch");
      pbranchindex684 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 3, 4, 0});
      slog::Relation* readrel725 = db->getRelation("pbranch");
      pbranchdelta689 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({1, 2, 0});
      slog::Relation* readrel727 = db->getRelation("st_msk");
      st_mskindex685 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({1, 2, 0});
      slog::Relation* readrel729 = db->getRelation("st_msk");
      st_mskdelta690 = readrel729->getIndex(ord728, true);
      std::vector<u16> ord730({0, 1});
      slog::Relation* readrel731 = db->getRelation("st_msk_ans");
      st_msk_ansindex686 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 1});
      slog::Relation* readrel733 = db->getRelation("st_union_ans");
      st_union_ansindex687 = readrel733->getIndex(ord732, false);
  
    }
    ReadTask691(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c154 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c157 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x106x0x0x0index670, std::array<u64,9>{v_c155, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x106x0x0x1index671, std::array<u64,10>{v_c155, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex672, st_uniondelta688, std::array<u64,3>{v_c157, 0, 0}, [&](const std::array<u64,3>& m734) {
          u64 v_c158 = m734[1]; u64 v_c11 = m734[2];
          if (!slog::exists_probe<9,2>($sup9688x106x0x0x0index673, std::array<u64,9>{v_c155, v_c11, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup9688x106x0x0x1index674, std::array<u64,10>{v_c155, v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_union_ansindex675, std::array<u64,2>{v_c158, 0})) return;
          slog::join_probe<5,2>(pbranchindex676, std::array<u64,5>{v_c11, v_c156, 0, 0, 0}, [&](const std::array<u64,5>& m735) {
            u64 v_c8 = m735[2]; u64 v_c9 = m735[3]; u64 v_c10 = m735[4];
            if (!slog::exists_probe<10,5>($sup9688x106x0x0x1index677, std::array<u64,10>{v_c11, v_c10, v_c9, v_c8, v_c155, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex678, std::array<u64,3>{v_c9, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex679, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe<9,5>($sup9688x106x0x0x0index680, std::array<u64,9>{v_c8, v_c10, v_c9, v_c11, v_c155, 0, 0, 0, 0}, [&](const std::array<u64,9>& m736) {
              u64 v_c3 = m736[5]; u64 v_c2 = m736[6]; u64 v_c4 = m736[7]; u64 v_c5 = m736[8];
              u64 v_c159 = _prim_lt(db, v_c3, v_c9);
              if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
              if (!v_c159) return;
              if (!slog::exists_probe<5,5>(pbranchindex681, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c157})) return;
              if (!slog::exists_probe<3,2>(st_mskindex682, std::array<u64,3>{v_c2, v_c9, 0})) return;
              slog::join_probe<10,9>($sup9688x106x0x0x1index683, std::array<u64,10>{v_c11, v_c10, v_c9, v_c8, v_c155, v_c3, v_c2, v_c4, v_c5, 0}, [&](const std::array<u64,10>& m738) {
                u64 v_c160 = m738[9];
                slog::join_probe_old<5,5>(pbranchindex684, pbranchdelta689, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c157}, [&](const std::array<u64,5>& m739) {
                  slog::join_probe_old<3,3>(st_mskindex685, st_mskdelta690, std::array<u64,3>{v_c2, v_c9, v_c160}, [&](const std::array<u64,3>& m740) {
                    slog::join_probe<2,2>(st_msk_ansindex686, std::array<u64,2>{v_c160, v_c8}, [&](const std::array<u64,2>& m741) {
                      slog::join_probe<2,1>(st_union_ansindex687, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m742) {
                        u64 v_c21 = m742[1];
                        u64 v_c161 = _prim_band(db, v_c2, v_c9);
                        if (v_c161 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c162 = _prim_gt(db, v_c161, v_c154);
                        if (v_c162 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c162) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c155, v_c21, v_c10, v_c9, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c10, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask691* _cont = new ReadTask691(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask691(db,b), false);
  // (crule (pre (let __tconst0X5Q704 conste3776bfed7f405de8017ecfa) (let __tconst0saG225 const6b86b273ff34fce19d6b804e) (let __tconst4SDF224 const2c624232cdd221771294dfbb)) (probe st_ins (2 0 1) 1 __tconst0saG225 __t3VGi227 __t5hb6226) (body (join _enum (0 1) 2 __t5hb6226 __tconst0X5Q704) (join st_ins_ans (0 1) 1 __t3VGi227 __v0)) (head (mkstruct st_ins (1 2 0) __8Kcs705 __v0 __tconst4SDF224)) st_basic.slog:15 #f)
  class ReadTask746 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex744;  slog::Index** st_ins_ansindex745;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord747({2, 0, 1});
      slog::Relation* readrel748 = db->getRelation("st_ins");
      driver_index = readrel748->getIndex(ord747, true);
      std::vector<u16> ord749({0, 1});
      slog::Relation* readrel750 = db->getRelation("_enum");
      _enumindex744 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({0, 1});
      slog::Relation* readrel752 = db->getRelation("st_ins_ans");
      st_ins_ansindex745 = readrel752->getIndex(ord751, false);
  
    }
    ReadTask746(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c164 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c165 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c164, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m753) {
        u64 v_c166 = m753[1];
        u64 v_c167 = m753[2];
        if (buckethash(v_c166) != bucket) return;
        slog::join_probe<2,2>(_enumindex744, std::array<u64,2>{v_c167, v_c163}, [&](const std::array<u64,2>& m754) {
          slog::join_probe<2,1>(st_ins_ansindex745, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m755) {
            u64 v_c21 = m755[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c165}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask746* _cont = new ReadTask746(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask746(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan pbranch __t3eDW75 q n u v) (body (exists st_diff (2 0 1) 1 __t3eDW75) (exists st_diff (2 0 1) 1 v) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x151x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t0F4S77 l m p r) (cmp lt m n) (exists st_diff (2 0 1) 2 __t3eDW75 __t0F4S77) (exists st_msk (1 2 0) 2 p n) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0L1D80) (join-old st_diff (0 1 2) 3 (0 1 2) __t0F4S77 __t0L1D80 __t3eDW75) (join-old st_diff (1 2 0) 2 (1 2 0) __t0L1D80 v __t8Vvm81) (exists st_diff_ans (0 1) 1 __t8Vvm81) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join st_msk_ans (0 1) 2 __t1x4A82 q) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask774 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex756;  slog::Index** st_diffindex757;  slog::Index** st_mskindex758;  slog::Index** st_msk_ansindex759;  slog::Index** $sup9688x151x0x0x0index760;  slog::Index** st_diffindex761;  slog::Index** st_mskindex762;  slog::Index** pbranchindex763;  slog::Index** st_diffindex764;  slog::Index** st_diffindex765;  slog::Index** st_diff_ansindex766;  slog::Index** st_mskindex767;  slog::Index** st_msk_ansindex768;  slog::Index** st_diff_ansindex769;  slog::Index** pbranchdelta770;  slog::Index** st_diffdelta771;  slog::Index** st_diffdelta772;  slog::Index** st_mskdelta773;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord775({0, 1});
      slog::Relation* readrel776 = db->getRelation("st_diff_ans");
      head_index[0] = readrel776->getIndex(ord775, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord777({2, 0, 1});
      slog::Relation* readrel778 = db->getRelation("st_diff");
      st_diffindex756 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({2, 0, 1});
      slog::Relation* readrel780 = db->getRelation("st_diff");
      st_diffindex757 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({2, 0, 1});
      slog::Relation* readrel782 = db->getRelation("st_msk");
      st_mskindex758 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 0});
      slog::Relation* readrel784 = db->getRelation("st_msk_ans");
      st_msk_ansindex759 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel786 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index760 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({2, 0, 1});
      slog::Relation* readrel788 = db->getRelation("st_diff");
      st_diffindex761 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("st_msk");
      st_mskindex762 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 3, 4, 0});
      slog::Relation* readrel792 = db->getRelation("pbranch");
      pbranchindex763 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 3, 4, 0});
      slog::Relation* readrel794 = db->getRelation("pbranch");
      pbranchdelta770 = readrel794->getIndex(ord793, true);
      std::vector<u16> ord795({0, 1, 2});
      slog::Relation* readrel796 = db->getRelation("st_diff");
      st_diffindex764 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1, 2});
      slog::Relation* readrel798 = db->getRelation("st_diff");
      st_diffdelta771 = readrel798->getIndex(ord797, true);
      std::vector<u16> ord799({1, 2, 0});
      slog::Relation* readrel800 = db->getRelation("st_diff");
      st_diffindex765 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 2, 0});
      slog::Relation* readrel802 = db->getRelation("st_diff");
      st_diffdelta772 = readrel802->getIndex(ord801, true);
      std::vector<u16> ord803({0, 1});
      slog::Relation* readrel804 = db->getRelation("st_diff_ans");
      st_diff_ansindex766 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 2, 0});
      slog::Relation* readrel806 = db->getRelation("st_msk");
      st_mskindex767 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 2, 0});
      slog::Relation* readrel808 = db->getRelation("st_msk");
      st_mskdelta773 = readrel808->getIndex(ord807, true);
      std::vector<u16> ord809({0, 1});
      slog::Relation* readrel810 = db->getRelation("st_msk_ans");
      st_msk_ansindex768 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({0, 1});
      slog::Relation* readrel812 = db->getRelation("st_diff_ans");
      st_diff_ansindex769 = readrel812->getIndex(ord811, false);
  
    }
    ReadTask774(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c168 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c169 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex756, std::array<u64,3>{v_c169, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex757, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex758, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex759, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<9,4>($sup9688x151x0x0x0index760, std::array<u64,9>{v_c2, v_c3, v_c4, v_c5, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m813) {
          u64 v_c170 = m813[4]; u64 v_c10 = m813[5]; u64 v_c9 = m813[6]; u64 v_c8 = m813[7]; u64 v_c11 = m813[8];
          u64 v_c171 = _prim_lt(db, v_c9, v_c3);
          if (v_c171 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
          if (!v_c171) return;
          if (!slog::exists_probe<3,2>(st_diffindex761, std::array<u64,3>{v_c169, v_c170, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex762, std::array<u64,3>{v_c8, v_c3, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex763, pbranchdelta770, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m815) {
            u64 v_c172 = m815[4];
            slog::join_probe_old<3,3>(st_diffindex764, st_diffdelta771, std::array<u64,3>{v_c170, v_c172, v_c169}, [&](const std::array<u64,3>& m816) {
              slog::join_probe_old<3,2>(st_diffindex765, st_diffdelta772, std::array<u64,3>{v_c172, v_c5, 0}, [&](const std::array<u64,3>& m817) {
                u64 v_c173 = m817[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex766, std::array<u64,2>{v_c173, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex767, st_mskdelta773, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m818) {
                  u64 v_c174 = m818[2];
                  slog::join_probe<2,2>(st_msk_ansindex768, std::array<u64,2>{v_c174, v_c2}, [&](const std::array<u64,2>& m819) {
                    slog::join_probe<2,1>(st_diff_ansindex769, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m820) {
                      u64 v_c24 = m820[1];
                      u64 v_c175 = _prim_band(db, v_c8, v_c3);
                      if (v_c175 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c176 = _prim_gt(db, v_c175, v_c168);
                      if (v_c176 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c176) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c170, v_c24}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask774* _cont = new ReadTask774(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask774(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan st_msk __t5Q4t319 k m) (body (exists $sup9688x50x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_ins (2 0 1) 1 k) (exists st_msk_ans (0 1) 1 __t5Q4t319) (join $sup9688x50x0x0x1 (1 2 4 5 0 3 6) 3 __t5Q4t319 k m p __t6bST316 l r) (join $sup9688x50x0x0x0 (4 2 3 5 0 1) 6 p l m r __t6bST316 k) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_msk_ans (0 1) 2 __t5Q4t319 p) (exists st_ins (1 2 0) 2 l k) (join pbranch (1 2 3 4 0) 4 p m l r __t8dDI315) (join st_ins (0 2 1) 3 __t6bST316 k __t8dDI315) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask837 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x0index822;  slog::Index** pbranchindex823;  slog::Index** st_insindex824;  slog::Index** st_msk_ansindex825;  slog::Index** $sup9688x50x0x0x1index826;  slog::Index** $sup9688x50x0x0x0index827;  slog::Index** st_insindex828;  slog::Index** st_msk_ansindex829;  slog::Index** st_insindex830;  slog::Index** pbranchindex831;  slog::Index** st_insindex832;  slog::Index** st_msk_ansindex833;  slog::Index** st_insindex834;  slog::Index** st_ins_ansindex835;  slog::Index** st_insdelta836;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord838({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel839 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index822 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({2, 0, 1, 3, 4});
      slog::Relation* readrel841 = db->getRelation("pbranch");
      pbranchindex823 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({2, 0, 1});
      slog::Relation* readrel843 = db->getRelation("st_ins");
      st_insindex824 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1});
      slog::Relation* readrel845 = db->getRelation("st_msk_ans");
      st_msk_ansindex825 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel847 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index826 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel849 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index827 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({0, 2, 1});
      slog::Relation* readrel851 = db->getRelation("st_ins");
      st_insindex828 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({0, 1});
      slog::Relation* readrel853 = db->getRelation("st_msk_ans");
      st_msk_ansindex829 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 0});
      slog::Relation* readrel855 = db->getRelation("st_ins");
      st_insindex830 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 2, 3, 4, 0});
      slog::Relation* readrel857 = db->getRelation("pbranch");
      pbranchindex831 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 2, 1});
      slog::Relation* readrel859 = db->getRelation("st_ins");
      st_insindex832 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({0, 1});
      slog::Relation* readrel861 = db->getRelation("st_msk_ans");
      st_msk_ansindex833 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("st_ins");
      st_insindex834 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 2, 0});
      slog::Relation* readrel865 = db->getRelation("st_ins");
      st_insdelta836 = readrel865->getIndex(ord864, true);
      std::vector<u16> ord866({0, 1});
      slog::Relation* readrel867 = db->getRelation("st_ins_ans");
      st_ins_ansindex835 = readrel867->getIndex(ord866, false);
  
    }
    ReadTask837(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c178 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x50x0x0x0index822, std::array<u64,6>{v_c33, v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex823, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex824, std::array<u64,3>{v_c33, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex825, std::array<u64,2>{v_c178, 0})) return;
        slog::join_probe<7,3>($sup9688x50x0x0x1index826, std::array<u64,7>{v_c178, v_c33, v_c9, 0, 0, 0, 0}, [&](const std::array<u64,7>& m868) {
          u64 v_c8 = m868[3]; u64 v_c179 = m868[4]; u64 v_c10 = m868[5]; u64 v_c11 = m868[6];
          slog::join_probe<6,6>($sup9688x50x0x0x0index827, std::array<u64,6>{v_c8, v_c10, v_c9, v_c11, v_c179, v_c33}, [&](const std::array<u64,6>& m869) {
            if (!slog::exists_probe<3,2>(st_insindex828, std::array<u64,3>{v_c179, v_c33, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex829, std::array<u64,2>{v_c178, v_c8})) return;
            if (!slog::exists_probe<3,2>(st_insindex830, std::array<u64,3>{v_c10, v_c33, 0})) return;
            slog::join_probe<5,4>(pbranchindex831, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m870) {
              u64 v_c180 = m870[4];
              slog::join_probe<3,3>(st_insindex832, std::array<u64,3>{v_c179, v_c33, v_c180}, [&](const std::array<u64,3>& m871) {
                slog::join_probe<2,2>(st_msk_ansindex833, std::array<u64,2>{v_c178, v_c8}, [&](const std::array<u64,2>& m872) {
                  slog::join_probe_old<3,2>(st_insindex834, st_insdelta836, std::array<u64,3>{v_c10, v_c33, 0}, [&](const std::array<u64,3>& m873) {
                    u64 v_c181 = m873[2];
                    slog::join_probe<2,1>(st_ins_ansindex835, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m874) {
                      u64 v_c21 = m874[1];
                      u64 v_c182 = _prim_band(db, v_c33, v_c9);
                      if (v_c182 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c183 = _prim_lt(db, v_c182, v_c177);
                      if (v_c183 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c183) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c179, v_c21, v_c9, v_c8, v_c11});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c21, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask837* _cont = new ReadTask837(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask837(db,b), false);
  // (crule (pre) (scan pbranch __t75xj153 p m u v) (body (exists st_diff (2 0 1) 1 __t75xj153) (join-old pbranch (1 2 3 4 0) 2 (1 2 3 4 0) p m l r __t9bMl154) (join-old st_diff (1 2 0) 2 (1 2 0) __t9bMl154 __t75xj153 __t6llH155)) (head (emit $sup9688x136x0x0x0 (0 1 2 3 4 5 6) __t6llH155 l m p r u v)) set.slog:137 #f)
  class ReadTask881 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex876;  slog::Index** pbranchindex877;  slog::Index** st_diffindex878;  slog::Index** pbranchdelta879;  slog::Index** st_diffdelta880;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord882({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel883 = db->getRelation("$sup9688x136x0x0x0");
      head_index[0] = readrel883->getIndex(ord882, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord884({2, 0, 1});
      slog::Relation* readrel885 = db->getRelation("st_diff");
      st_diffindex876 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 2, 3, 4, 0});
      slog::Relation* readrel887 = db->getRelation("pbranch");
      pbranchindex877 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 3, 4, 0});
      slog::Relation* readrel889 = db->getRelation("pbranch");
      pbranchdelta879 = readrel889->getIndex(ord888, true);
      std::vector<u16> ord890({1, 2, 0});
      slog::Relation* readrel891 = db->getRelation("st_diff");
      st_diffindex878 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 0});
      slog::Relation* readrel893 = db->getRelation("st_diff");
      st_diffdelta880 = readrel893->getIndex(ord892, true);
  
    }
    ReadTask881(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c184 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex876, std::array<u64,3>{v_c184, 0, 0})) return;
        slog::join_probe_old<5,2>(pbranchindex877, pbranchdelta879, std::array<u64,5>{v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,5>& m894) {
          u64 v_c10 = m894[2]; u64 v_c11 = m894[3]; u64 v_c185 = m894[4];
          slog::join_probe_old<3,2>(st_diffindex878, st_diffdelta880, std::array<u64,3>{v_c185, v_c184, 0}, [&](const std::array<u64,3>& m895) {
            u64 v_c186 = m895[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c186, v_c10, v_c9, v_c8, v_c11, v_c4, v_c5}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask881* _cont = new ReadTask881(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask881(db,b), false);
  // (crule (pre (let __tconst5jMg913 conste3776bfed7f405de8017ecfa) (let __tconst0zHM198 const2c624232cdd221771294dfbb)) (probe st_ins (2 0 1) 1 __tconst0zHM198 __t1mgk200 __t9gYW199) (body (join _enum (0 1) 2 __t9gYW199 __tconst5jMg913) (join st_ins_ans (0 1) 1 __t1mgk200 __v0) (join canon (0) 0 s)) (head (emit $sup97714x23x0x0x1 (1 0 2) __v0 __t1mgk200 s)) st_basic.slog:24 #f)
  class ReadTask899 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex896;  slog::Index** st_ins_ansindex897;  slog::Index** canonindex898;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord900({1, 0, 2});
      slog::Relation* readrel901 = db->getRelation("$sup97714x23x0x0x1");
      head_index[0] = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({2, 0, 1});
      slog::Relation* readrel903 = db->getRelation("st_ins");
      driver_index = readrel903->getIndex(ord902, true);
      std::vector<u16> ord904({0, 1});
      slog::Relation* readrel905 = db->getRelation("_enum");
      _enumindex896 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1});
      slog::Relation* readrel907 = db->getRelation("st_ins_ans");
      st_ins_ansindex897 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({0});
      slog::Relation* readrel909 = db->getRelation("canon");
      canonindex898 = readrel909->getIndex(ord908, false);
  
    }
    ReadTask899(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c68 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c68, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m910) {
        u64 v_c69 = m910[1];
        u64 v_c70 = m910[2];
        if (buckethash(v_c69) != bucket) return;
        slog::join_probe<2,2>(_enumindex896, std::array<u64,2>{v_c70, v_c67}, [&](const std::array<u64,2>& m911) {
          slog::join_probe<2,1>(st_ins_ansindex897, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m912) {
            u64 v_c21 = m912[1];
            slog::join_all<1>(canonindex898, [&](const std::array<u64,1>& m913) {
              u64 v_c71 = m913[0];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c69, v_c71}, std::array<u16,3>{1, 0, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask899* _cont = new ReadTask899(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask899(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan st_diff_ans __t7sr4550 __v0) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t7sr4550 r __t3eTQ549) (exists $sup9688x142x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3eTQ549 q n u v) (exists st_msk (1 2 0) 1 q) (join $sup9688x142x0x0x0 (3 5 7 8 6 0 1 2 4) 5 n q u v r __d0 l m p) (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t3ZZb548) (join st_msk_ans (0 1) 2 __t3ZZb548 p)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask928 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex914;  slog::Index** $sup9688x142x0x0x0index915;  slog::Index** pbranchindex916;  slog::Index** st_mskindex917;  slog::Index** $sup9688x142x0x0x0index918;  slog::Index** st_msk_ansindex919;  slog::Index** st_mskindex920;  slog::Index** st_msk_ansindex921;  slog::Index** st_diffdelta922;  slog::Index** pbranchdelta923;  slog::Index** st_mskdelta924;
    u32 sid926;  u32 sid925;  u32 sid927;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord929({0, 1, 2});
      slog::Relation* readrel930 = db->getRelation("st_diff");
      st_diffindex914 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({0, 1, 2});
      slog::Relation* readrel932 = db->getRelation("st_diff");
      st_diffdelta922 = readrel932->getIndex(ord931, true);
      std::vector<u16> ord933({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel934 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index915 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({0, 1, 2, 3, 4});
      slog::Relation* readrel936 = db->getRelation("pbranch");
      pbranchindex916 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({0, 1, 2, 3, 4});
      slog::Relation* readrel938 = db->getRelation("pbranch");
      pbranchdelta923 = readrel938->getIndex(ord937, true);
      std::vector<u16> ord939({1, 2, 0});
      slog::Relation* readrel940 = db->getRelation("st_msk");
      st_mskindex917 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({3, 5, 7, 8, 6, 0, 1, 2, 4});
      slog::Relation* readrel942 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index918 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0});
      slog::Relation* readrel944 = db->getRelation("st_msk_ans");
      st_msk_ansindex919 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("st_msk");
      st_mskindex920 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("st_msk");
      st_mskdelta924 = readrel948->getIndex(ord947, true);
      std::vector<u16> ord949({0, 1});
      slog::Relation* readrel950 = db->getRelation("st_msk_ans");
      st_msk_ansindex921 = readrel950->getIndex(ord949, false);
      sid926 = db->getRelation("_enum")->getStructId();
      sid925 = db->getRelation("pbranch")->getStructId();
      sid927 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask928(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c187 = v_const81906d9241165d9f6a541e47;
      u64 v_c188 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c189 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c190 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex914, st_diffdelta922, std::array<u64,3>{v_c190, 0, 0}, [&](const std::array<u64,3>& m951) {
          u64 v_c11 = m951[1]; u64 v_c191 = m951[2];
          if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index915, std::array<u64,9>{v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(pbranchindex916, pbranchdelta923, std::array<u64,5>{v_c191, 0, 0, 0, 0}, [&](const std::array<u64,5>& m952) {
            u64 v_c2 = m952[1]; u64 v_c3 = m952[2]; u64 v_c4 = m952[3]; u64 v_c5 = m952[4];
            if (!slog::exists_probe<3,1>(st_mskindex917, std::array<u64,3>{v_c2, 0, 0})) return;
            slog::join_probe<9,5>($sup9688x142x0x0x0index918, std::array<u64,9>{v_c3, v_c2, v_c4, v_c5, v_c11, 0, 0, 0, 0}, [&](const std::array<u64,9>& m953) {
              u64 v_c32 = m953[5]; u64 v_c10 = m953[6]; u64 v_c9 = m953[7]; u64 v_c8 = m953[8];
              if (!slog::exists_probe<2,1>(st_msk_ansindex919, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex920, st_mskdelta924, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m954) {
                u64 v_c192 = m954[2];
                slog::join_probe<2,2>(st_msk_ansindex921, std::array<u64,2>{v_c192, v_c8}, [&](const std::array<u64,2>& m955) {
                  ++_fires;
                  if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid925 || decode_struct_id(v_c10) == sid926 || decode_struct_id(v_c10) == sid927))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c187, v_c188, v_c189, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c10, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask928* _cont = new ReadTask928(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask928(db,b), false);
  // (crule (pre (let __tconst0eJ4499 const6b86b273ff34fce19d6b804e)) (scan pbranch __t3WTc496 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t3WTc496 __t557L498 __t5Gbs497) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t5Gbs497 p m l r) (cmp lt m n) (let __t85kh500 (band p n)) (cmp lt __t85kh500 __tconst0eJ4499)) (head (emit $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) __t557L498 u l m n p q r v)) set.slog:149 #f)
  class ReadTask960 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex956;  slog::Index** pbranchindex957;  slog::Index** st_diffdelta958;  slog::Index** pbranchdelta959;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord961({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel962 = db->getRelation("$sup9688x148x0x0x0");
      head_index[0] = readrel962->getIndex(ord961, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord963({2, 0, 1});
      slog::Relation* readrel964 = db->getRelation("st_diff");
      st_diffindex956 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({2, 0, 1});
      slog::Relation* readrel966 = db->getRelation("st_diff");
      st_diffdelta958 = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({0, 1, 2, 3, 4});
      slog::Relation* readrel968 = db->getRelation("pbranch");
      pbranchindex957 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({0, 1, 2, 3, 4});
      slog::Relation* readrel970 = db->getRelation("pbranch");
      pbranchdelta959 = readrel970->getIndex(ord969, true);
  
    }
    ReadTask960(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex956, st_diffdelta958, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m971) {
          u64 v_c46 = m971[1]; u64 v_c44 = m971[2];
          slog::join_probe_old<5,1>(pbranchindex957, pbranchdelta959, std::array<u64,5>{v_c44, 0, 0, 0, 0}, [&](const std::array<u64,5>& m972) {
            u64 v_c8 = m972[1]; u64 v_c9 = m972[2]; u64 v_c10 = m972[3]; u64 v_c11 = m972[4];
            u64 v_c193 = _prim_lt(db, v_c9, v_c3);
            if (v_c193 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c193) return;
            u64 v_c48 = _prim_band(db, v_c8, v_c3);
            if (v_c48 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            u64 v_c194 = _prim_lt(db, v_c48, v_c43);
            if (v_c194 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c194) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c46, v_c4, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c5}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask960* _cont = new ReadTask960(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask960(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan st_ins __t6bST316 __t8dDI315 k) (body (exists $sup9688x50x0x0x1 (0 2 1 3 4 5 6) 2 __t6bST316 k) (exists st_msk (1 2 0) 1 k) (exists st_ins (2 0 1) 1 k) (join $sup9688x50x0x0x0 (0 1 2 3 4 5) 2 __t6bST316 k l m p r) (exists pbranch (1 2 3 4 0) 5 p m l r __t8dDI315) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 2 l k) (join $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t6bST316 k __t5Q4t319) (join pbranch (1 2 3 4 0) 5 p m l r __t8dDI315) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask991 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x1index975;  slog::Index** st_mskindex976;  slog::Index** st_insindex977;  slog::Index** $sup9688x50x0x0x0index978;  slog::Index** pbranchindex979;  slog::Index** st_mskindex980;  slog::Index** st_msk_ansindex981;  slog::Index** st_insindex982;  slog::Index** $sup9688x50x0x0x1index983;  slog::Index** pbranchindex984;  slog::Index** st_mskindex985;  slog::Index** st_msk_ansindex986;  slog::Index** st_insindex987;  slog::Index** st_ins_ansindex988;  slog::Index** st_mskdelta989;  slog::Index** st_insdelta990;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord992({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel993 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index975 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({1, 2, 0});
      slog::Relation* readrel995 = db->getRelation("st_msk");
      st_mskindex976 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({2, 0, 1});
      slog::Relation* readrel997 = db->getRelation("st_ins");
      st_insindex977 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel999 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index978 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 2, 3, 4, 0});
      slog::Relation* readrel1001 = db->getRelation("pbranch");
      pbranchindex979 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({1, 2, 0});
      slog::Relation* readrel1003 = db->getRelation("st_msk");
      st_mskindex980 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({1, 0});
      slog::Relation* readrel1005 = db->getRelation("st_msk_ans");
      st_msk_ansindex981 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({1, 2, 0});
      slog::Relation* readrel1007 = db->getRelation("st_ins");
      st_insindex982 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel1009 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index983 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({1, 2, 3, 4, 0});
      slog::Relation* readrel1011 = db->getRelation("pbranch");
      pbranchindex984 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 2, 0});
      slog::Relation* readrel1013 = db->getRelation("st_msk");
      st_mskindex985 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("st_msk");
      st_mskdelta989 = readrel1015->getIndex(ord1014, true);
      std::vector<u16> ord1016({0, 1});
      slog::Relation* readrel1017 = db->getRelation("st_msk_ans");
      st_msk_ansindex986 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 0});
      slog::Relation* readrel1019 = db->getRelation("st_ins");
      st_insindex987 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("st_ins");
      st_insdelta990 = readrel1021->getIndex(ord1020, true);
      std::vector<u16> ord1022({0, 1});
      slog::Relation* readrel1023 = db->getRelation("st_ins_ans");
      st_ins_ansindex988 = readrel1023->getIndex(ord1022, false);
  
    }
    ReadTask991(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c33 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x50x0x0x1index975, std::array<u64,7>{v_c179, v_c33, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex976, std::array<u64,3>{v_c33, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex977, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x50x0x0x0index978, std::array<u64,6>{v_c179, v_c33, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1024) {
          u64 v_c10 = m1024[2]; u64 v_c9 = m1024[3]; u64 v_c8 = m1024[4]; u64 v_c11 = m1024[5];
          if (!slog::exists_probe<5,5>(pbranchindex979, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c180})) return;
          if (!slog::exists_probe<3,2>(st_mskindex980, std::array<u64,3>{v_c33, v_c9, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex981, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<3,2>(st_insindex982, std::array<u64,3>{v_c10, v_c33, 0})) return;
          slog::join_probe<7,6>($sup9688x50x0x0x1index983, std::array<u64,7>{v_c10, v_c9, v_c8, v_c11, v_c179, v_c33, 0}, [&](const std::array<u64,7>& m1025) {
            u64 v_c178 = m1025[6];
            slog::join_probe<5,5>(pbranchindex984, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c180}, [&](const std::array<u64,5>& m1026) {
              slog::join_probe_old<3,3>(st_mskindex985, st_mskdelta989, std::array<u64,3>{v_c33, v_c9, v_c178}, [&](const std::array<u64,3>& m1027) {
                slog::join_probe<2,2>(st_msk_ansindex986, std::array<u64,2>{v_c178, v_c8}, [&](const std::array<u64,2>& m1028) {
                  slog::join_probe_old<3,2>(st_insindex987, st_insdelta990, std::array<u64,3>{v_c10, v_c33, 0}, [&](const std::array<u64,3>& m1029) {
                    u64 v_c181 = m1029[2];
                    slog::join_probe<2,1>(st_ins_ansindex988, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m1030) {
                      u64 v_c21 = m1030[1];
                      u64 v_c182 = _prim_band(db, v_c33, v_c9);
                      if (v_c182 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c195 = _prim_lt(db, v_c182, v_c177);
                      if (v_c195 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c195) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c179, v_c21, v_c9, v_c8, v_c11});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c21, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask991* _cont = new ReadTask991(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask991(db,b), false);
}

