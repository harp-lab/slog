
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1d9eff40314d54862fee3942;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5e6127cdd5ea2629462053c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7d00193796cbe9983b9801f2;
extern u64 v_const9899bd1a9f17c17561973172;
extern u64 v_const99e1cbf3d792d4a87847a801;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constc49bf1a249fe0ece92ed8fd8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste19dc92e0d47b9f7f5bc6441;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c00af38e888f83b07(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan pleaf __t6Nl9212 k) (body (join-old st_union (2 0 1) 1 (2 0 1) __t6Nl9212 __t8WQ2213 s)) (head (mkstruct st_ins (1 2 0) __0IHY906 s k)) set.slog:99 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex0;  slog::Index** st_uniondelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord3({2, 0, 1});
      slog::Relation* readrel4 = db->getRelation("st_union");
      st_unionindex0 = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({2, 0, 1});
      slog::Relation* readrel6 = db->getRelation("st_union");
      st_uniondelta1 = readrel6->getIndex(ord5, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(st_unionindex0, st_uniondelta1, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m7) {
          u64 v_c2 = m7[1]; u64 v_c3 = m7[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:pleaf", _fires);
  
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
  // (crule (pre) (scan pbranch __t9bMl154 p m l r) (body (exists st_diff (1 2 0) 1 __t9bMl154) (join pbranch (1 2 3 4 0) 2 p m u v __t75xj153) (join-old st_diff (1 2 0) 2 (1 2 0) __t9bMl154 __t75xj153 __t6llH155)) (head (emit $sup9688x136x0x0x0 (0 1 2 3 4 5 6) __t6llH155 l m p r u v)) set.slog:137 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex8;  slog::Index** pbranchindex9;  slog::Index** st_diffindex10;  slog::Index** st_diffdelta11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord13({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel14 = db->getRelation("$sup9688x136x0x0x0");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord15({1, 2, 0});
      slog::Relation* readrel16 = db->getRelation("st_diff");
      st_diffindex8 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 2, 3, 4, 0});
      slog::Relation* readrel18 = db->getRelation("pbranch");
      pbranchindex9 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("st_diff");
      st_diffindex10 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("st_diff");
      st_diffdelta11 = readrel22->getIndex(ord21, true);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex8, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<5,2>(pbranchindex9, std::array<u64,5>{v_c5, v_c6, 0, 0, 0}, [&](const std::array<u64,5>& m23) {
          u64 v_c9 = m23[2]; u64 v_c10 = m23[3]; u64 v_c11 = m23[4];
          slog::join_probe_old<3,2>(st_diffindex10, st_diffdelta11, std::array<u64,3>{v_c4, v_c11, 0}, [&](const std::array<u64,3>& m24) {
            u64 v_c12 = m24[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c12, v_c7, v_c6, v_c5, v_c8, v_c9, v_c10}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan $sup9688x139x0x0x0 __t3X8M159 l m n p q r u v) (body (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t66RN158) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join-old st_diff (0 1 2) 3 (0 1 2) __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t1RXD162 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask49 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex25;  slog::Index** st_bldindex26;  slog::Index** st_mskindex27;  slog::Index** st_msk_ansindex28;  slog::Index** st_diffindex29;  slog::Index** pbranchindex30;  slog::Index** st_diffindex31;  slog::Index** pbranchindex32;  slog::Index** st_diffindex33;  slog::Index** st_diffindex34;  slog::Index** st_bldindex35;  slog::Index** st_diff_ansindex36;  slog::Index** st_bld_ansindex37;  slog::Index** st_mskindex38;  slog::Index** st_msk_ansindex39;  slog::Index** st_diffindex40;  slog::Index** st_diff_ansindex41;  slog::Index** st_bld_ansindex42;  slog::Index** pbranchdelta43;  slog::Index** pbranchdelta44;  slog::Index** st_diffdelta45;  slog::Index** st_blddelta46;  slog::Index** st_mskdelta47;  slog::Index** st_diffdelta48;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("st_diff_ans");
      head_index[0] = readrel51->getIndex(ord50, false);
      outer_rel = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord52({1, 2, 3, 4, 0});
      slog::Relation* readrel53 = db->getRelation("pbranch");
      pbranchindex25 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({2, 1, 4, 0, 3});
      slog::Relation* readrel55 = db->getRelation("st_bld");
      st_bldindex26 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 0});
      slog::Relation* readrel57 = db->getRelation("st_msk");
      st_mskindex27 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("st_msk_ans");
      st_msk_ansindex28 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 0});
      slog::Relation* readrel61 = db->getRelation("st_diff");
      st_diffindex29 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 3, 4, 0});
      slog::Relation* readrel63 = db->getRelation("pbranch");
      pbranchindex30 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 3, 4, 0});
      slog::Relation* readrel65 = db->getRelation("pbranch");
      pbranchdelta43 = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({0, 1, 2});
      slog::Relation* readrel67 = db->getRelation("st_diff");
      st_diffindex31 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 3, 4, 0});
      slog::Relation* readrel69 = db->getRelation("pbranch");
      pbranchindex32 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 2, 3, 4, 0});
      slog::Relation* readrel71 = db->getRelation("pbranch");
      pbranchdelta44 = readrel71->getIndex(ord70, true);
      std::vector<u16> ord72({0, 1, 2});
      slog::Relation* readrel73 = db->getRelation("st_diff");
      st_diffindex33 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0, 1, 2});
      slog::Relation* readrel75 = db->getRelation("st_diff");
      st_diffdelta45 = readrel75->getIndex(ord74, true);
      std::vector<u16> ord76({1, 2, 0});
      slog::Relation* readrel77 = db->getRelation("st_diff");
      st_diffindex34 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({2, 1, 4, 0, 3});
      slog::Relation* readrel79 = db->getRelation("st_bld");
      st_bldindex35 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({2, 1, 4, 0, 3});
      slog::Relation* readrel81 = db->getRelation("st_bld");
      st_blddelta46 = readrel81->getIndex(ord80, true);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("st_diff_ans");
      st_diff_ansindex36 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("st_bld_ans");
      st_bld_ansindex37 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("st_msk");
      st_mskindex38 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("st_msk");
      st_mskdelta47 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("st_msk_ans");
      st_msk_ansindex39 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("st_diff");
      st_diffindex40 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 2, 0});
      slog::Relation* readrel95 = db->getRelation("st_diff");
      st_diffdelta48 = readrel95->getIndex(ord94, true);
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("st_diff_ans");
      st_diff_ansindex41 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("st_bld_ans");
      st_bld_ansindex42 = readrel99->getIndex(ord98, false);
  
    }
    ReadTask49(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c5 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c9 = _t[7];
        u64 v_c10 = _t[8];
        u64 v_c17 = _prim_lt(db, v_c15, v_c6);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
        if (!v_c17) return;
        if (!slog::exists_probe<5,4>(pbranchindex25, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex26, std::array<u64,5>{v_c6, v_c5, v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex27, std::array<u64,3>{v_c16, v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex28, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex29, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex30, pbranchdelta43, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m101) {
          u64 v_c18 = m101[4];
          if (!slog::exists_probe<3,2>(st_diffindex31, std::array<u64,3>{v_c14, v_c18, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex32, pbranchdelta44, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m102) {
            u64 v_c19 = m102[4];
            slog::join_probe_old<3,3>(st_diffindex33, st_diffdelta45, std::array<u64,3>{v_c14, v_c18, v_c19}, [&](const std::array<u64,3>& m103) {
              if (!slog::exists_probe<3,2>(st_diffindex34, std::array<u64,3>{v_c7, v_c19, 0})) return;
              slog::join_probe_old<5,3>(st_bldindex35, st_blddelta46, std::array<u64,5>{v_c6, v_c5, v_c8, 0, 0}, [&](const std::array<u64,5>& m104) {
                u64 v_c20 = m104[3]; u64 v_c21 = m104[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex36, std::array<u64,2>{v_c21, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex37, std::array<u64,2>{v_c20, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex38, st_mskdelta47, std::array<u64,3>{v_c16, v_c6, 0}, [&](const std::array<u64,3>& m105) {
                  u64 v_c22 = m105[2];
                  slog::join_probe<2,2>(st_msk_ansindex39, std::array<u64,2>{v_c22, v_c5}, [&](const std::array<u64,2>& m106) {
                    slog::join_probe_old<3,2>(st_diffindex40, st_diffdelta48, std::array<u64,3>{v_c7, v_c19, 0}, [&](const std::array<u64,3>& m107) {
                      u64 v_c23 = m107[2];
                      slog::join_probe<2,2>(st_diff_ansindex41, std::array<u64,2>{v_c23, v_c21}, [&](const std::array<u64,2>& m108) {
                        slog::join_probe<2,1>(st_bld_ansindex42, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m109) {
                          u64 v_c24 = m109[1];
                          u64 v_c25 = _prim_band(db, v_c16, v_c6);
                          if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c26 = _prim_lt(db, v_c25, v_c13);
                          if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c26) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c24}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:$sup9688x139x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask49* _cont = new ReadTask49(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask49(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan st_ins __t1WXl320 l k) (body (exists $sup9688x50x0x0x0 (1 2 0 3 4 5) 2 k l) (exists $sup9688x50x0x0x1 (2 3 0 1 4 5 6) 2 k l) (exists pbranch (3 0 1 2 4) 1 l) (exists st_ins (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (join $sup9688x50x0x0x0 (1 2 0 3 4 5) 2 k l __t6bST316 m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t6bST316 k __t5Q4t319) (exists st_msk (1 2 0) 3 k m __t5Q4t319) (exists st_msk_ans (0 1) 2 __t5Q4t319 p) (join pbranch (1 2 3 4 0) 4 p m l r __t8dDI315) (join st_ins (0 2 1) 3 __t6bST316 k __t8dDI315) (join st_msk (1 2 0) 3 k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x0index111;  slog::Index** $sup9688x50x0x0x1index112;  slog::Index** pbranchindex113;  slog::Index** st_insindex114;  slog::Index** st_mskindex115;  slog::Index** st_ins_ansindex116;  slog::Index** $sup9688x50x0x0x0index117;  slog::Index** pbranchindex118;  slog::Index** st_insindex119;  slog::Index** st_mskindex120;  slog::Index** st_msk_ansindex121;  slog::Index** $sup9688x50x0x0x1index122;  slog::Index** st_mskindex123;  slog::Index** st_msk_ansindex124;  slog::Index** pbranchindex125;  slog::Index** st_insindex126;  slog::Index** st_mskindex127;  slog::Index** st_msk_ansindex128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord130({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel131 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index111 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({2, 3, 0, 1, 4, 5, 6});
      slog::Relation* readrel133 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index112 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({3, 0, 1, 2, 4});
      slog::Relation* readrel135 = db->getRelation("pbranch");
      pbranchindex113 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({2, 0, 1});
      slog::Relation* readrel137 = db->getRelation("st_ins");
      st_insindex114 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("st_msk");
      st_mskindex115 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("st_ins_ans");
      st_ins_ansindex116 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel143 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index117 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 3, 4, 0});
      slog::Relation* readrel145 = db->getRelation("pbranch");
      pbranchindex118 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 2, 1});
      slog::Relation* readrel147 = db->getRelation("st_ins");
      st_insindex119 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 0});
      slog::Relation* readrel149 = db->getRelation("st_msk");
      st_mskindex120 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 0});
      slog::Relation* readrel151 = db->getRelation("st_msk_ans");
      st_msk_ansindex121 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel153 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index122 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 0});
      slog::Relation* readrel155 = db->getRelation("st_msk");
      st_mskindex123 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 1});
      slog::Relation* readrel157 = db->getRelation("st_msk_ans");
      st_msk_ansindex124 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 3, 4, 0});
      slog::Relation* readrel159 = db->getRelation("pbranch");
      pbranchindex125 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 2, 1});
      slog::Relation* readrel161 = db->getRelation("st_ins");
      st_insindex126 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 2, 0});
      slog::Relation* readrel163 = db->getRelation("st_msk");
      st_mskindex127 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("st_msk_ans");
      st_msk_ansindex128 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x50x0x0x0index111, std::array<u64,6>{v_c1, v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup9688x50x0x0x1index112, std::array<u64,7>{v_c1, v_c7, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex113, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex114, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex115, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(st_ins_ansindex116, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m166) {
          u64 v_c21 = m166[1];
          slog::join_probe<6,2>($sup9688x50x0x0x0index117, std::array<u64,6>{v_c1, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,6>& m167) {
            u64 v_c29 = m167[2]; u64 v_c6 = m167[3]; u64 v_c5 = m167[4]; u64 v_c8 = m167[5];
            if (!slog::exists_probe<5,4>(pbranchindex118, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_insindex119, std::array<u64,3>{v_c29, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex120, std::array<u64,3>{v_c1, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex121, std::array<u64,2>{v_c5, 0})) return;
            slog::join_probe<7,6>($sup9688x50x0x0x1index122, std::array<u64,7>{v_c7, v_c6, v_c5, v_c8, v_c29, v_c1, 0}, [&](const std::array<u64,7>& m168) {
              u64 v_c30 = m168[6];
              if (!slog::exists_probe<3,3>(st_mskindex123, std::array<u64,3>{v_c1, v_c6, v_c30})) return;
              if (!slog::exists_probe<2,2>(st_msk_ansindex124, std::array<u64,2>{v_c30, v_c5})) return;
              slog::join_probe<5,4>(pbranchindex125, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m169) {
                u64 v_c31 = m169[4];
                slog::join_probe<3,3>(st_insindex126, std::array<u64,3>{v_c29, v_c1, v_c31}, [&](const std::array<u64,3>& m170) {
                  slog::join_probe<3,3>(st_mskindex127, std::array<u64,3>{v_c1, v_c6, v_c30}, [&](const std::array<u64,3>& m171) {
                    slog::join_probe<2,2>(st_msk_ansindex128, std::array<u64,2>{v_c30, v_c5}, [&](const std::array<u64,2>& m172) {
                      u64 v_c32 = _prim_band(db, v_c1, v_c6);
                      if (v_c32 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c33 = _prim_lt(db, v_c32, v_c27);
                      if (v_c33 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c33) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c29, v_c21, v_c6, v_c5, v_c8});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c5, v_c6, v_c21, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask129* _cont = new ReadTask129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask129(db,b), false);
  // (crule (pre (let __tconst5qiO758 conste3776bfed7f405de8017ecfa) (let __tconst5MZ7439 constef2d127de37b942baad06145) (let __tconst7dws442 constd4735e3a265e16eee03f5971) (let __tconst4Zv7438 const2c624232cdd221771294dfbb)) (scan st_ins_ans __t1qxx444 __v1) (body (exists _enum (1 0) 1 __tconst5qiO758) (exists st_ins (2 0 1) 1 __tconst5MZ7439) (join-old st_ins (0 2 1) 2 (0 2 1) __t1qxx444 __tconst7dws442 __t8JV0443) (join _enum (0 1) 2 __t8JV0443 __tconst5qiO758) (join-old st_ins (1 2 0) 2 (1 2 0) __t8JV0443 __tconst5MZ7439 __t1gci441) (join st_ins_ans (0 1) 1 __t1gci441 __v0)) (head (mkstruct st_ins (1 2 0) __0kE5759 __v0 __tconst4Zv7438)) st_basic.slog:18 #f)
  class ReadTask182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex174;  slog::Index** st_insindex175;  slog::Index** st_insindex176;  slog::Index** _enumindex177;  slog::Index** st_insindex178;  slog::Index** st_ins_ansindex179;  slog::Index** st_insdelta180;  slog::Index** st_insdelta181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("_enum");
      _enumindex174 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({2, 0, 1});
      slog::Relation* readrel186 = db->getRelation("st_ins");
      st_insindex175 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0, 2, 1});
      slog::Relation* readrel188 = db->getRelation("st_ins");
      st_insindex176 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({0, 2, 1});
      slog::Relation* readrel190 = db->getRelation("st_ins");
      st_insdelta180 = readrel190->getIndex(ord189, true);
      std::vector<u16> ord191({0, 1});
      slog::Relation* readrel192 = db->getRelation("_enum");
      _enumindex177 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 0});
      slog::Relation* readrel194 = db->getRelation("st_ins");
      st_insindex178 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("st_ins");
      st_insdelta181 = readrel196->getIndex(ord195, true);
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("st_ins_ans");
      st_ins_ansindex179 = readrel198->getIndex(ord197, false);
  
    }
    ReadTask182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c35 = v_constef2d127de37b942baad06145;
      u64 v_c36 = v_constd4735e3a265e16eee03f5971;
      u64 v_c37 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c39 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex174, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex175, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex176, st_insdelta180, std::array<u64,3>{v_c38, v_c36, 0}, [&](const std::array<u64,3>& m199) {
          u64 v_c40 = m199[2];
          slog::join_probe<2,2>(_enumindex177, std::array<u64,2>{v_c40, v_c34}, [&](const std::array<u64,2>& m200) {
            slog::join_probe_old<3,2>(st_insindex178, st_insdelta181, std::array<u64,3>{v_c40, v_c35, 0}, [&](const std::array<u64,3>& m201) {
              u64 v_c41 = m201[2];
              slog::join_probe<2,1>(st_ins_ansindex179, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m202) {
                u64 v_c21 = m202[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c37}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask182* _cont = new ReadTask182(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask182(db,b), false);
  // (crule (pre) (scan pbranch __t4nDr530 p m l r) (body (join st_union (1 2 0) 1 __t4nDr530 __t78TS531 __t3dip529) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t78TS531 q n u v) (cmp lt m n)) (head (emit $sup9688x120x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t3dip529 l m q r __t4nDr530 __t78TS531 u v)) set.slog:121 #f)
  class ReadTask206 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex203;  slog::Index** pbranchindex204;  slog::Index** pbranchdelta205;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord207({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel208 = db->getRelation("$sup9688x120x0x0x0");
      head_index[0] = readrel208->getIndex(ord207, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("st_union");
      st_unionindex203 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({0, 1, 2, 3, 4});
      slog::Relation* readrel212 = db->getRelation("pbranch");
      pbranchindex204 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({0, 1, 2, 3, 4});
      slog::Relation* readrel214 = db->getRelation("pbranch");
      pbranchdelta205 = readrel214->getIndex(ord213, true);
  
    }
    ReadTask206(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<3,1>(st_unionindex203, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m215) {
          u64 v_c43 = m215[1]; u64 v_c44 = m215[2];
          slog::join_probe_old<5,1>(pbranchindex204, pbranchdelta205, std::array<u64,5>{v_c43, 0, 0, 0, 0}, [&](const std::array<u64,5>& m216) {
            u64 v_c16 = m216[1]; u64 v_c15 = m216[2]; u64 v_c9 = m216[3]; u64 v_c10 = m216[4];
            u64 v_c45 = _prim_lt(db, v_c6, v_c15);
            if (v_c45 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c45) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c15, v_c5, v_c44, v_c7, v_c6, v_c16, v_c8, v_c42, v_c43, v_c9, v_c10}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask206* _cont = new ReadTask206(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask206(db,b), false);
  // (crule (pre (let __tconst7mvQ823 conste3776bfed7f405de8017ecfa) (let __tconst3LBJ363 const2c624232cdd221771294dfbb)) (scan canon s) (body (join _enum (1 0) 1 __tconst7mvQ823 __t070I364)) (head (mkstruct st_ins (1 2 0) __4O67822 __t070I364 __tconst3LBJ363)) st_basic.slog:24 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("canon");
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("_enum");
      _enumindex218 = readrel221->getIndex(ord220, false);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c46 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c47 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        slog::join_probe<2,1>(_enumindex218, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m222) {
          u64 v_c48 = m222[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c48, v_c47}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:canon", _fires);
  
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
  // (crule (pre) (scan temp7DYO1402 __t9Bxs396 j k) (body (join pleaf (1 0) 1 k __t4eWA395)) (head (mkstruct st_join (1 2 3 4 0) __9V2f689 k __t4eWA395 j __t9Bxs396)) set.slog:50 #f)
  class ReadTask224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join");
      outer_rel = db->getRelation("temp7DYO1402");
      std::vector<u16> ord225({1, 0});
      slog::Relation* readrel226 = db->getRelation("pleaf");
      pleafindex223 = readrel226->getIndex(ord225, false);
  
    }
    ReadTask224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<2,1>(pleafindex223, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m227) {
          u64 v_c51 = m227[1];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c1, v_c51, v_c50, v_c49}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:temp7DYO1402", _fires);
  
      if (!_done)
      {
        ReadTask224* _cont = new ReadTask224(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask224(db,b), false);
  // (crule (pre) (scan st_msk __t4C16136 q m) (body (exists pbranch (2 0 1 3 4) 1 m) (exists $sup9688x110x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists pbranch (1 2 3 4 0) 1 q) (exists st_join (3 4 0 1 2) 1 q) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (join pbranch (2 0 1 3 4) 1 m __t9DTf133 p l r) (neq p __v0) (exists st_join (1 2 3 4 0) 3 p __t9DTf133 q) (exists st_union (1 2 0) 1 __t9DTf133) (join $sup9688x110x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 l m p r __t9DTf133 q __t1PdV132 n __t972J134 u v) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 q n u v __t972J134) (exists st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (join st_join (1 2 3 4 0) 4 p __t9DTf133 q __t972J134 __t744h135) (join st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask242 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex228;  slog::Index** $sup9688x110x0x0x0index229;  slog::Index** pbranchindex230;  slog::Index** st_joinindex231;  slog::Index** st_msk_ansindex232;  slog::Index** pbranchindex233;  slog::Index** st_joinindex234;  slog::Index** st_unionindex235;  slog::Index** $sup9688x110x0x0x0index236;  slog::Index** pbranchindex237;  slog::Index** st_unionindex238;  slog::Index** st_joinindex239;  slog::Index** st_unionindex240;  slog::Index** st_join_ansindex241;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord243({0, 1});
      slog::Relation* readrel244 = db->getRelation("st_union_ans");
      head_index[0] = readrel244->getIndex(ord243, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord245({2, 0, 1, 3, 4});
      slog::Relation* readrel246 = db->getRelation("pbranch");
      pbranchindex228 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel248 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index229 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 3, 4, 0});
      slog::Relation* readrel250 = db->getRelation("pbranch");
      pbranchindex230 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({3, 4, 0, 1, 2});
      slog::Relation* readrel252 = db->getRelation("st_join");
      st_joinindex231 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("st_msk_ans");
      st_msk_ansindex232 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 0, 1, 3, 4});
      slog::Relation* readrel256 = db->getRelation("pbranch");
      pbranchindex233 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 2, 3, 4, 0});
      slog::Relation* readrel258 = db->getRelation("st_join");
      st_joinindex234 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("st_union");
      st_unionindex235 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel262 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index236 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 3, 4, 0});
      slog::Relation* readrel264 = db->getRelation("pbranch");
      pbranchindex237 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({0, 1, 2});
      slog::Relation* readrel266 = db->getRelation("st_union");
      st_unionindex238 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 3, 4, 0});
      slog::Relation* readrel268 = db->getRelation("st_join");
      st_joinindex239 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1, 2});
      slog::Relation* readrel270 = db->getRelation("st_union");
      st_unionindex240 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({0, 1});
      slog::Relation* readrel272 = db->getRelation("st_join_ans");
      st_join_ansindex241 = readrel272->getIndex(ord271, false);
  
    }
    ReadTask242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<5,1>(pbranchindex228, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x110x0x0x0index229, std::array<u64,11>{v_c6, v_c16, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex230, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_joinindex231, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex232, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m273) {
          u64 v_c21 = m273[1];
          slog::join_probe<5,1>(pbranchindex233, std::array<u64,5>{v_c6, 0, 0, 0, 0}, [&](const std::array<u64,5>& m274) {
            u64 v_c53 = m274[1]; u64 v_c5 = m274[2]; u64 v_c7 = m274[3]; u64 v_c8 = m274[4];
            if (v_c5 == v_c21) return;
            if (!slog::exists_probe<5,3>(st_joinindex234, std::array<u64,5>{v_c5, v_c53, v_c16, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_unionindex235, std::array<u64,3>{v_c53, 0, 0})) return;
            slog::join_probe<11,6>($sup9688x110x0x0x0index236, std::array<u64,11>{v_c7, v_c6, v_c5, v_c8, v_c53, v_c16, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m275) {
              u64 v_c54 = m275[6]; u64 v_c15 = m275[7]; u64 v_c55 = m275[8]; u64 v_c9 = m275[9]; u64 v_c10 = m275[10];
              u64 v_c56 = _prim_lt(db, v_c15, v_c6);
              if (v_c56 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
              if (!v_c56) return;
              slog::join_probe<5,5>(pbranchindex237, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, v_c55}, [&](const std::array<u64,5>& m277) {
                if (!slog::exists_probe<3,3>(st_unionindex238, std::array<u64,3>{v_c54, v_c53, v_c55})) return;
                slog::join_probe<5,4>(st_joinindex239, std::array<u64,5>{v_c5, v_c53, v_c16, v_c55, 0}, [&](const std::array<u64,5>& m278) {
                  u64 v_c57 = m278[4];
                  slog::join_probe<3,3>(st_unionindex240, std::array<u64,3>{v_c54, v_c53, v_c55}, [&](const std::array<u64,3>& m279) {
                    slog::join_probe<2,1>(st_join_ansindex241, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m280) {
                      u64 v_c24 = m280[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c54, v_c24}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask242* _cont = new ReadTask242(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask242(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan $sup9688x36x0x0x0 __t0kmv352 p0 p1 t0 t1) (body (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (exists $sup9688x36x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t0kmv352 p0 p1 t0 t1) (exists st_msk (1 2 0) 1 p0) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 5 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (exists st_hsb_ans (0 1) 1 __t75bg356) (exists st_hsb_ans (0 1) 2 __t75bg356 __v0) (join $sup9688x36x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0 dup66Lo1333 dup68E21334 __v1 __v3) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join-old st_msk_ans (0 1) 1 (0 1) __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex281;  slog::Index** $sup9688x36x0x0x2index282;  slog::Index** st_mskindex283;  slog::Index** $sup9688x36x0x0x1index284;  slog::Index** st_hsb_ansindex285;  slog::Index** st_hsb_ansindex286;  slog::Index** $sup9688x36x0x0x2index287;  slog::Index** st_hsb_ansindex288;  slog::Index** st_hsb_ansindex289;  slog::Index** st_hsb_ansindex290;  slog::Index** st_mskindex291;  slog::Index** st_msk_ansindex292;  slog::Index** st_hsbindex293;  slog::Index** st_joindelta294;  slog::Index** st_hsb_ansdelta295;  slog::Index** st_hsb_ansdelta296;  slog::Index** st_hsb_ansdelta297;  slog::Index** st_mskdelta298;  slog::Index** st_msk_ansdelta299;  slog::Index** st_hsbdelta300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord302({1, 2, 3, 4, 0});
      slog::Relation* readrel303 = db->getRelation("st_join");
      st_joinindex281 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 3, 4, 0});
      slog::Relation* readrel305 = db->getRelation("st_join");
      st_joindelta294 = readrel305->getIndex(ord304, true);
      std::vector<u16> ord306({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel307 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index282 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("st_msk");
      st_mskindex283 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel311 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index284 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex285 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex286 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel317 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index287 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1});
      slog::Relation* readrel319 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex288 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1});
      slog::Relation* readrel321 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta295 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex289 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta296 = readrel325->getIndex(ord324, true);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex290 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta297 = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("st_msk");
      st_mskindex291 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 0});
      slog::Relation* readrel333 = db->getRelation("st_msk");
      st_mskdelta298 = readrel333->getIndex(ord332, true);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("st_msk_ans");
      st_msk_ansindex292 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("st_msk_ans");
      st_msk_ansdelta299 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("st_hsb");
      st_hsbindex293 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("st_hsb");
      st_hsbdelta300 = readrel341->getIndex(ord340, true);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        u64 v_c62 = _t[3];
        u64 v_c63 = _t[4];
        slog::join_probe_old<5,5>(st_joinindex281, st_joindelta294, std::array<u64,5>{v_c60, v_c62, v_c61, v_c63, v_c59}, [&](const std::array<u64,5>& m342) {
          if (!slog::exists_probe<11,5>($sup9688x36x0x0x2index282, std::array<u64,11>{v_c59, v_c60, v_c61, v_c62, v_c63, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex283, std::array<u64,3>{v_c60, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x36x0x0x1index284, std::array<u64,7>{v_c59, v_c60, v_c61, v_c62, v_c63, 0, 0}, [&](const std::array<u64,7>& m343) {
            u64 v_c64 = m343[5]; u64 v_c21 = m343[6];
            if (!slog::exists_probe<2,1>(st_hsb_ansindex285, std::array<u64,2>{v_c64, 0})) return;
            if (!slog::exists_probe<2,2>(st_hsb_ansindex286, std::array<u64,2>{v_c64, v_c21})) return;
            slog::join_probe<11,7>($sup9688x36x0x0x2index287, std::array<u64,11>{v_c59, v_c60, v_c61, v_c62, v_c63, v_c64, v_c21, 0, 0, 0, 0}, [&](const std::array<u64,11>& m344) {
              u64 v_c65 = m344[7]; u64 v_c66 = m344[8]; u64 v_c39 = m344[9]; u64 v_c67 = m344[10];
              if (v_c64 != v_c66) return;
              if (v_c64 != v_c65) return;
              slog::join_probe_old<2,2>(st_hsb_ansindex288, st_hsb_ansdelta295, std::array<u64,2>{v_c64, v_c67}, [&](const std::array<u64,2>& m345) {
                slog::join_probe_old<2,2>(st_hsb_ansindex289, st_hsb_ansdelta296, std::array<u64,2>{v_c64, v_c39}, [&](const std::array<u64,2>& m346) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex290, st_hsb_ansdelta297, std::array<u64,2>{v_c64, v_c21}, [&](const std::array<u64,2>& m347) {
                    slog::join_probe_old<3,2>(st_mskindex291, st_mskdelta298, std::array<u64,3>{v_c60, v_c39, 0}, [&](const std::array<u64,3>& m348) {
                      u64 v_c68 = m348[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex292, st_msk_ansdelta299, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m349) {
                        u64 v_c69 = m349[1];
                        u64 v_c70 = _prim_bxor(db, v_c60, v_c61);
                        if (v_c70 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex293, st_hsbdelta300, std::array<u64,2>{v_c64, v_c70}, [&](const std::array<u64,2>& m350) {
                          u64 v_c71 = _prim_band(db, v_c60, v_c21);
                          if (v_c71 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c72 = _prim_lt(db, v_c71, v_c58);
                          if (v_c72 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c72) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c59, v_c69, v_c67, v_c62, v_c63});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c69, v_c67, v_c62, v_c63}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x0", _fires);
  
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
  // (crule (pre (let __trid5BrO981 constc49bf1a249fe0ece92ed8fd8) (let __trel0jGk982 const9899bd1a9f17c17561973172) (let __tcol3OAP983 const5feceb66ffc86f38d952786c) (let __trel1e0N984 const9899bd1a9f17c17561973172) (let __tcol5ws6985 const6b86b273ff34fce19d6b804e) (let __trel7YsZ986 const9899bd1a9f17c17561973172) (let __tcol7dAk987 constd4735e3a265e16eee03f5971) (let __trel0ctu988 const9899bd1a9f17c17561973172) (let __tcol1Lln989 const4e07408562bedb8b60ce05c1)) (scan $sup9688x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid5BrO981 __trel0jGk982 __tcol3OAP983 (1 2 3 4 0)) (tycheck s (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BrO981 __trel1e0N984 __tcol5ws6985 (1 2 3 4 0)) (tycheck q (accept int) __trid5BrO981 __trel7YsZ986 __tcol7dAk987 (1 2 3 4 0)) (tycheck t (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BrO981 __trel0ctu988 __tcol1Lln989 (1 2 3 4 0)) (mkstruct st_join (1 2 3 4 0) __3ES0980 p s q t)) set.slog:111 #f)
  class ReadTask355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid353;  u32 sid352;  u32 sid354;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("st_join");
      outer_rel = db->getRelation("$sup9688x110x0x0x0");
      sid353 = db->getRelation("_enum")->getStructId();
      sid352 = db->getRelation("pbranch")->getStructId();
      sid354 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_constc49bf1a249fe0ece92ed8fd8;
      u64 v_c74 = v_const9899bd1a9f17c17561973172;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
      u64 v_c76 = v_const9899bd1a9f17c17561973172;
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c78 = v_const9899bd1a9f17c17561973172;
      u64 v_c79 = v_constd4735e3a265e16eee03f5971;
      u64 v_c80 = v_const9899bd1a9f17c17561973172;
      u64 v_c81 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c82 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c5 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c3 = _t[7];
        u64 v_c83 = _t[8];
        u64 v_c9 = _t[9];
        u64 v_c10 = _t[10];
        ++_fires;
        if (!(is_int(v_c5)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c73, v_c74, v_c75, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid352 || decode_struct_id(v_c3) == sid353 || decode_struct_id(v_c3) == sid354))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c73, v_c76, v_c77, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c73, v_c78, v_c79, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c83) && (decode_struct_id(v_c83) == sid352 || decode_struct_id(v_c83) == sid353 || decode_struct_id(v_c83) == sid354))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c73, v_c80, v_c81, v_c83}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c5, v_c3, v_c16, v_c83}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:$sup9688x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask355* _cont = new ReadTask355(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask355(db,b), false);
  // (crule (pre (let __trid5eCR832 conste19dc92e0d47b9f7f5bc6441) (let __trel7pEX833 consta10f76b4ec574de5d7b6908e) (let __tcol3C6w834 const5feceb66ffc86f38d952786c) (let __trel7ZlY835 consta10f76b4ec574de5d7b6908e) (let __tcol7i04836 const6b86b273ff34fce19d6b804e)) (scan $sup9688x72x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid5eCR832 __trel7pEX833 __tcol3C6w834 (1 2 3 4 0)) (tycheck m (accept int) __trid5eCR832 __trel7ZlY835 __tcol7i04836 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __3U6a831 k m)) set.slog:73 #f)
  class ReadTask356 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x72x0x0x0");
  
    }
    ReadTask356(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_conste19dc92e0d47b9f7f5bc6441;
      u64 v_c85 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
      u64 v_c87 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c1 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c5 = _t[4];
        u64 v_c8 = _t[5];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c84, v_c85, v_c86, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c84, v_c87, v_c88, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:$sup9688x72x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask356* _cont = new ReadTask356(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask356(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan st_diff_ans __t4u9h108 res) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t4u9h108 __t6qKy107 u) (exists pbranch (3 0 1 2 4) 1 u) (exists $sup9688x148x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (join-old st_diff (1 2 0) 1 (1 2 0) __t6qKy107 __t6SZQ102 __t5Ek2104) (exists $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t5Ek2104 u) (join-old pbranch (3 0 1 2 4) 2 (3 0 1 2 4) u __t6SZQ102 q n v) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join-old $sup9688x148x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t5Ek2104 l m p r) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6qKy107) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join-old st_msk_ans (0 1) 2 (0 1) __t3oZy109 q) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask376 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex357;  slog::Index** pbranchindex358;  slog::Index** $sup9688x148x0x0x0index359;  slog::Index** st_diffindex360;  slog::Index** $sup9688x148x0x0x0index361;  slog::Index** pbranchindex362;  slog::Index** st_mskindex363;  slog::Index** st_msk_ansindex364;  slog::Index** $sup9688x148x0x0x0index365;  slog::Index** pbranchindex366;  slog::Index** st_mskindex367;  slog::Index** st_msk_ansindex368;  slog::Index** st_diffdelta369;  slog::Index** st_diffdelta370;  slog::Index** pbranchdelta371;  slog::Index** $sup9688x148x0x0x0delta372;  slog::Index** pbranchdelta373;  slog::Index** st_mskdelta374;  slog::Index** st_msk_ansdelta375;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord377({0, 1});
      slog::Relation* readrel378 = db->getRelation("st_diff_ans");
      head_index[0] = readrel378->getIndex(ord377, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord379({0, 1, 2});
      slog::Relation* readrel380 = db->getRelation("st_diff");
      st_diffindex357 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({0, 1, 2});
      slog::Relation* readrel382 = db->getRelation("st_diff");
      st_diffdelta369 = readrel382->getIndex(ord381, true);
      std::vector<u16> ord383({3, 0, 1, 2, 4});
      slog::Relation* readrel384 = db->getRelation("pbranch");
      pbranchindex358 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel386 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index359 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("st_diff");
      st_diffindex360 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_diff");
      st_diffdelta370 = readrel390->getIndex(ord389, true);
      std::vector<u16> ord391({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel392 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index361 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({3, 0, 1, 2, 4});
      slog::Relation* readrel394 = db->getRelation("pbranch");
      pbranchindex362 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({3, 0, 1, 2, 4});
      slog::Relation* readrel396 = db->getRelation("pbranch");
      pbranchdelta371 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({2, 0, 1});
      slog::Relation* readrel398 = db->getRelation("st_msk");
      st_mskindex363 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 0});
      slog::Relation* readrel400 = db->getRelation("st_msk_ans");
      st_msk_ansindex364 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel402 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index365 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel404 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0delta372 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({1, 2, 3, 4, 0});
      slog::Relation* readrel406 = db->getRelation("pbranch");
      pbranchindex366 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 3, 4, 0});
      slog::Relation* readrel408 = db->getRelation("pbranch");
      pbranchdelta373 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({1, 2, 0});
      slog::Relation* readrel410 = db->getRelation("st_msk");
      st_mskindex367 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("st_msk");
      st_mskdelta374 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("st_msk_ans");
      st_msk_ansindex368 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("st_msk_ans");
      st_msk_ansdelta375 = readrel416->getIndex(ord415, true);
  
    }
    ReadTask376(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c24 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex357, st_diffdelta369, std::array<u64,3>{v_c90, 0, 0}, [&](const std::array<u64,3>& m417) {
          u64 v_c91 = m417[1]; u64 v_c9 = m417[2];
          if (!slog::exists_probe<5,1>(pbranchindex358, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x148x0x0x0index359, std::array<u64,9>{v_c9, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_diffindex360, st_diffdelta370, std::array<u64,3>{v_c91, 0, 0}, [&](const std::array<u64,3>& m418) {
            u64 v_c92 = m418[1]; u64 v_c93 = m418[2];
            if (!slog::exists_probe<9,2>($sup9688x148x0x0x0index361, std::array<u64,9>{v_c93, v_c9, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex362, pbranchdelta371, std::array<u64,5>{v_c9, v_c92, 0, 0, 0}, [&](const std::array<u64,5>& m419) {
              u64 v_c16 = m419[2]; u64 v_c15 = m419[3]; u64 v_c10 = m419[4];
              if (!slog::exists_probe<3,1>(st_mskindex363, std::array<u64,3>{v_c15, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex364, std::array<u64,2>{v_c16, 0})) return;
              slog::join_probe_old<9,5>($sup9688x148x0x0x0index365, $sup9688x148x0x0x0delta372, std::array<u64,9>{v_c16, v_c15, v_c9, v_c10, v_c93, 0, 0, 0, 0}, [&](const std::array<u64,9>& m420) {
                u64 v_c7 = m420[5]; u64 v_c6 = m420[6]; u64 v_c5 = m420[7]; u64 v_c8 = m420[8];
                u64 v_c94 = _prim_lt(db, v_c6, v_c15);
                if (v_c94 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                if (!v_c94) return;
                slog::join_probe_old<5,5>(pbranchindex366, pbranchdelta373, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, v_c91}, [&](const std::array<u64,5>& m422) {
                  slog::join_probe_old<3,2>(st_mskindex367, st_mskdelta374, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m423) {
                    u64 v_c95 = m423[2];
                    slog::join_probe_old<2,2>(st_msk_ansindex368, st_msk_ansdelta375, std::array<u64,2>{v_c95, v_c16}, [&](const std::array<u64,2>& m424) {
                      u64 v_c96 = _prim_band(db, v_c5, v_c15);
                      if (v_c96 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c97 = _prim_lt(db, v_c96, v_c89);
                      if (v_c97 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c97) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c93, v_c24}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask376* _cont = new ReadTask376(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask376(db,b), false);
  // (crule (pre) (scan st_diff __t3Y70488 __t7CbK487 t) (body (join pleaf (0 1) 1 __t7CbK487 k)) (head (mkstruct st_mem0 (1 2 0) __1sow933 t k)) set.slog:134 #f)
  class ReadTask427 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex426;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("pleaf");
      pleafindex426 = readrel429->getIndex(ord428, false);
  
    }
    ReadTask427(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c98 = _t[0];
        u64 v_c99 = _t[1];
        u64 v_c83 = _t[2];
        slog::join_probe<2,1>(pleafindex426, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m430) {
          u64 v_c1 = m430[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c83, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask427* _cont = new ReadTask427(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask427(db,b), false);
  // (crule (pre) (scan temp20p21276 l m p r u) (body (join pbranch (1 2 3 4 0) 4 p m l r __t6qba207)) (head (mkstruct st_union (1 2 0) __0CcV740 __t6qba207 u)) set.slog:115 #f)
  class ReadTask432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex431;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("temp20p21276");
      std::vector<u16> ord433({1, 2, 3, 4, 0});
      slog::Relation* readrel434 = db->getRelation("pbranch");
      pbranchindex431 = readrel434->getIndex(ord433, false);
  
    }
    ReadTask432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe<5,4>(pbranchindex431, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m435) {
          u64 v_c100 = m435[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c100, v_c9}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:temp20p21276", _fires);
  
      if (!_done)
      {
        ReadTask432* _cont = new ReadTask432(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask432(db,b), false);
  // (crule (pre) (scan pbranch __t3ubB312 p m l r) (body (join-old st_del (1 2 0) 1 (1 2 0) __t3ubB312 k __t3YAz313)) (head (emit $sup9688x87x0x0x0 (0 1 2 3 4 5) __t3YAz313 k l m p r)) set.slog:88 #f)
  class ReadTask438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex436;  slog::Index** st_deldelta437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord439({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel440 = db->getRelation("$sup9688x87x0x0x0");
      head_index[0] = readrel440->getIndex(ord439, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("st_del");
      st_delindex436 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("st_del");
      st_deldelta437 = readrel444->getIndex(ord443, true);
  
    }
    ReadTask438(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_delindex436, st_deldelta437, std::array<u64,3>{v_c101, 0, 0}, [&](const std::array<u64,3>& m445) {
          u64 v_c1 = m445[1]; u64 v_c102 = m445[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c102, v_c1, v_c7, v_c6, v_c5, v_c8}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask438* _cont = new ReadTask438(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask438(db,b), false);
  // (crule (pre) (scan pbranch __t1fgd418 p m l r) (body (exists st_diff (1 2 0) 1 __t1fgd418) (exists st_msk (1 2 0) 1 p) (join $sup9688x154x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t0EGY419 n q u v) (cmp lt m n) (exists st_diff (0 1 2) 2 __t0EGY419 __t1fgd418) (exists st_msk (1 2 0) 2 p n) (join pbranch (1 2 3 4 0) 4 q n u v __t7ytQ417) (join-old st_diff (0 1 2) 3 (0 1 2) __t0EGY419 __t1fgd418 __t7ytQ417) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t8lOi420) (join st_msk_ans (0 1) 1 __t8lOi420 __v0) (neq q __v0)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask457 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex446;  slog::Index** st_mskindex447;  slog::Index** $sup9688x154x0x0x0index448;  slog::Index** st_diffindex449;  slog::Index** st_mskindex450;  slog::Index** pbranchindex451;  slog::Index** st_diffindex452;  slog::Index** st_mskindex453;  slog::Index** st_msk_ansindex454;  slog::Index** st_diffdelta455;  slog::Index** st_mskdelta456;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("st_diff_ans");
      head_index[0] = readrel459->getIndex(ord458, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("st_diff");
      st_diffindex446 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("st_msk");
      st_mskindex447 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel465 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index448 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1, 2});
      slog::Relation* readrel467 = db->getRelation("st_diff");
      st_diffindex449 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("st_msk");
      st_mskindex450 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 3, 4, 0});
      slog::Relation* readrel471 = db->getRelation("pbranch");
      pbranchindex451 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 1, 2});
      slog::Relation* readrel473 = db->getRelation("st_diff");
      st_diffindex452 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({0, 1, 2});
      slog::Relation* readrel475 = db->getRelation("st_diff");
      st_diffdelta455 = readrel475->getIndex(ord474, true);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("st_msk");
      st_mskindex453 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("st_msk");
      st_mskdelta456 = readrel479->getIndex(ord478, true);
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("st_msk_ans");
      st_msk_ansindex454 = readrel481->getIndex(ord480, false);
  
    }
    ReadTask457(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex446, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex447, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x154x0x0x0index448, std::array<u64,9>{v_c7, v_c6, v_c5, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m482) {
          u64 v_c104 = m482[4]; u64 v_c15 = m482[5]; u64 v_c16 = m482[6]; u64 v_c9 = m482[7]; u64 v_c10 = m482[8];
          u64 v_c105 = _prim_lt(db, v_c6, v_c15);
          if (v_c105 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
          if (!v_c105) return;
          if (!slog::exists_probe<3,2>(st_diffindex449, std::array<u64,3>{v_c104, v_c103, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex450, std::array<u64,3>{v_c5, v_c15, 0})) return;
          slog::join_probe<5,4>(pbranchindex451, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m484) {
            u64 v_c106 = m484[4];
            slog::join_probe_old<3,3>(st_diffindex452, st_diffdelta455, std::array<u64,3>{v_c104, v_c103, v_c106}, [&](const std::array<u64,3>& m485) {
              slog::join_probe_old<3,2>(st_mskindex453, st_mskdelta456, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m486) {
                u64 v_c107 = m486[2];
                slog::join_probe<2,1>(st_msk_ansindex454, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m487) {
                  u64 v_c21 = m487[1];
                  if (v_c16 == v_c21) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c103}, std::array<u16,2>{0, 1});
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
        ReadTask457* _cont = new ReadTask457(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask457(db,b), false);
  // (crule (pre) (scan temp8v341350 __t7CbB259 __v0 l m p) (body (join pbranch (1 2 3 4 0) 4 p m l __v0 __t4EZL257)) (head (emit st_ins_ans (0 1) __t7CbB259 __t4EZL257)) set.slog:53 #f)
  class ReadTask489 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex488;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("st_ins_ans");
      head_index[0] = readrel491->getIndex(ord490, false);
      outer_rel = db->getRelation("temp8v341350");
      std::vector<u16> ord492({1, 2, 3, 4, 0});
      slog::Relation* readrel493 = db->getRelation("pbranch");
      pbranchindex488 = readrel493->getIndex(ord492, false);
  
    }
    ReadTask489(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe<5,4>(pbranchindex488, std::array<u64,5>{v_c5, v_c6, v_c7, v_c21, 0}, [&](const std::array<u64,5>& m494) {
          u64 v_c109 = m494[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c108, v_c109}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:temp8v341350", _fires);
  
      if (!_done)
      {
        ReadTask489* _cont = new ReadTask489(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask489(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan pbranch __t0L1D80 p m l r) (body (exists st_diff (1 2 0) 1 __t0L1D80) (exists st_msk (1 2 0) 1 p) (join $sup9688x151x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t0F4S77 n q u v) (cmp lt m n) (exists st_diff (0 1 2) 2 __t0F4S77 __t0L1D80) (exists st_diff (1 2 0) 2 __t0L1D80 v) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (join pbranch (1 2 3 4 0) 4 q n u v __t3eDW75) (join st_diff (0 1 2) 3 __t0F4S77 __t0L1D80 __t3eDW75) (join-old st_diff (1 2 0) 2 (1 2 0) __t0L1D80 v __t8Vvm81) (exists st_diff_ans (0 1) 1 __t8Vvm81) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join st_msk_ans (0 1) 2 __t1x4A82 q) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask511 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex495;  slog::Index** st_mskindex496;  slog::Index** $sup9688x151x0x0x0index497;  slog::Index** st_diffindex498;  slog::Index** st_diffindex499;  slog::Index** st_mskindex500;  slog::Index** st_msk_ansindex501;  slog::Index** pbranchindex502;  slog::Index** st_diffindex503;  slog::Index** st_diffindex504;  slog::Index** st_diff_ansindex505;  slog::Index** st_mskindex506;  slog::Index** st_msk_ansindex507;  slog::Index** st_diff_ansindex508;  slog::Index** st_diffdelta509;  slog::Index** st_mskdelta510;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("st_diff_ans");
      head_index[0] = readrel513->getIndex(ord512, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord514({1, 2, 0});
      slog::Relation* readrel515 = db->getRelation("st_diff");
      st_diffindex495 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("st_msk");
      st_mskindex496 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel519 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index497 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({0, 1, 2});
      slog::Relation* readrel521 = db->getRelation("st_diff");
      st_diffindex498 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("st_diff");
      st_diffindex499 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 2, 0});
      slog::Relation* readrel525 = db->getRelation("st_msk");
      st_mskindex500 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 0});
      slog::Relation* readrel527 = db->getRelation("st_msk_ans");
      st_msk_ansindex501 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({1, 2, 3, 4, 0});
      slog::Relation* readrel529 = db->getRelation("pbranch");
      pbranchindex502 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 1, 2});
      slog::Relation* readrel531 = db->getRelation("st_diff");
      st_diffindex503 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("st_diff");
      st_diffindex504 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("st_diff");
      st_diffdelta509 = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("st_diff_ans");
      st_diff_ansindex505 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 2, 0});
      slog::Relation* readrel539 = db->getRelation("st_msk");
      st_mskindex506 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("st_msk");
      st_mskdelta510 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("st_msk_ans");
      st_msk_ansindex507 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("st_diff_ans");
      st_diff_ansindex508 = readrel545->getIndex(ord544, false);
  
    }
    ReadTask511(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c111 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex495, std::array<u64,3>{v_c111, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex496, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x151x0x0x0index497, std::array<u64,9>{v_c7, v_c6, v_c5, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m546) {
          u64 v_c112 = m546[4]; u64 v_c15 = m546[5]; u64 v_c16 = m546[6]; u64 v_c9 = m546[7]; u64 v_c10 = m546[8];
          u64 v_c113 = _prim_lt(db, v_c6, v_c15);
          if (v_c113 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
          if (!v_c113) return;
          if (!slog::exists_probe<3,2>(st_diffindex498, std::array<u64,3>{v_c112, v_c111, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex499, std::array<u64,3>{v_c111, v_c10, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex500, std::array<u64,3>{v_c5, v_c15, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex501, std::array<u64,2>{v_c16, 0})) return;
          slog::join_probe<5,4>(pbranchindex502, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m548) {
            u64 v_c114 = m548[4];
            slog::join_probe<3,3>(st_diffindex503, std::array<u64,3>{v_c112, v_c111, v_c114}, [&](const std::array<u64,3>& m549) {
              slog::join_probe_old<3,2>(st_diffindex504, st_diffdelta509, std::array<u64,3>{v_c111, v_c10, 0}, [&](const std::array<u64,3>& m550) {
                u64 v_c115 = m550[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex505, std::array<u64,2>{v_c115, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex506, st_mskdelta510, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m551) {
                  u64 v_c116 = m551[2];
                  slog::join_probe<2,2>(st_msk_ansindex507, std::array<u64,2>{v_c116, v_c16}, [&](const std::array<u64,2>& m552) {
                    slog::join_probe<2,1>(st_diff_ansindex508, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m553) {
                      u64 v_c24 = m553[1];
                      u64 v_c117 = _prim_band(db, v_c5, v_c15);
                      if (v_c117 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c118 = _prim_gt(db, v_c117, v_c110);
                      if (v_c118 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c118) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c112, v_c24}, std::array<u16,2>{0, 1});
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
        ReadTask511* _cont = new ReadTask511(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask511(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_hsb_ans __t2flT468 __v1) (body (exists st_hsb_ans (0 1) 1 __t2flT468) (exists $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t2flT468 __v1) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 1 __t2flT468) (exists st_msk (2 0 1) 1 __v1) (join st_hsb_ans (0 1) 1 __t2flT468 __v3) (exists $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2flT468 __v1 __v3) (join-old st_hsb_ans (0 1) 1 (0 1) __t2flT468 __v0) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 2 __t2flT468 __v0) (join $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2flT468 __v0 __v3 __v1 __t4PzE464 dup2gd61405 dup5ZAM1406 p0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join st_msk_ans (0 1) 1 __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask574 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex555;  slog::Index** $sup9688x40x0x0x2index556;  slog::Index** $sup9688x40x0x0x1index557;  slog::Index** st_mskindex558;  slog::Index** st_hsb_ansindex559;  slog::Index** $sup9688x40x0x0x2index560;  slog::Index** st_hsb_ansindex561;  slog::Index** $sup9688x40x0x0x1index562;  slog::Index** $sup9688x40x0x0x2index563;  slog::Index** $sup9688x40x0x0x1index564;  slog::Index** $sup9688x40x0x0x0index565;  slog::Index** st_joinindex566;  slog::Index** st_mskindex567;  slog::Index** st_msk_ansindex568;  slog::Index** st_hsbindex569;  slog::Index** st_hsb_ansdelta570;  slog::Index** st_joindelta571;  slog::Index** st_mskdelta572;  slog::Index** st_hsbdelta573;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord575({0, 1});
      slog::Relation* readrel576 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex555 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel578 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index556 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel580 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index557 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({2, 0, 1});
      slog::Relation* readrel582 = db->getRelation("st_msk");
      st_mskindex558 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex559 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel586 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index560 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex561 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta570 = readrel590->getIndex(ord589, true);
      std::vector<u16> ord591({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel592 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index562 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel594 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index563 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel596 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index564 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 0, 2, 3, 4});
      slog::Relation* readrel598 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index565 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 3, 4, 0});
      slog::Relation* readrel600 = db->getRelation("st_join");
      st_joinindex566 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 3, 4, 0});
      slog::Relation* readrel602 = db->getRelation("st_join");
      st_joindelta571 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("st_msk");
      st_mskindex567 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({1, 2, 0});
      slog::Relation* readrel606 = db->getRelation("st_msk");
      st_mskdelta572 = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({0, 1});
      slog::Relation* readrel608 = db->getRelation("st_msk_ans");
      st_msk_ansindex568 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("st_hsb");
      st_hsbindex569 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("st_hsb");
      st_hsbdelta573 = readrel612->getIndex(ord611, true);
  
    }
    ReadTask574(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c120 = _t[0];
        u64 v_c39 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex555, std::array<u64,2>{v_c120, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index556, std::array<u64,11>{v_c120, v_c39, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x40x0x0x1index557, std::array<u64,7>{v_c120, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex558, std::array<u64,3>{v_c39, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex559, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m613) {
          u64 v_c67 = m613[1];
          if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index560, std::array<u64,11>{v_c120, v_c39, v_c67, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex561, st_hsb_ansdelta570, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m614) {
            u64 v_c21 = m614[1];
            if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index562, std::array<u64,7>{v_c120, v_c21, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x40x0x0x2index563, std::array<u64,11>{v_c120, v_c21, v_c67, v_c39, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m615) {
              u64 v_c121 = m615[4]; u64 v_c122 = m615[5]; u64 v_c123 = m615[6]; u64 v_c60 = m615[7]; u64 v_c61 = m615[8]; u64 v_c62 = m615[9]; u64 v_c63 = m615[10];
              if (v_c120 != v_c123) return;
              if (v_c120 != v_c122) return;
              slog::join_probe<7,7>($sup9688x40x0x0x1index564, std::array<u64,7>{v_c121, v_c60, v_c61, v_c62, v_c63, v_c120, v_c21}, [&](const std::array<u64,7>& m616) {
                slog::join_probe<5,5>($sup9688x40x0x0x0index565, std::array<u64,5>{v_c60, v_c121, v_c61, v_c62, v_c63}, [&](const std::array<u64,5>& m617) {
                  slog::join_probe_old<5,5>(st_joinindex566, st_joindelta571, std::array<u64,5>{v_c60, v_c62, v_c61, v_c63, v_c121}, [&](const std::array<u64,5>& m618) {
                    slog::join_probe_old<3,2>(st_mskindex567, st_mskdelta572, std::array<u64,3>{v_c60, v_c39, 0}, [&](const std::array<u64,3>& m619) {
                      u64 v_c124 = m619[2];
                      slog::join_probe<2,1>(st_msk_ansindex568, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m620) {
                        u64 v_c69 = m620[1];
                        u64 v_c125 = _prim_bxor(db, v_c60, v_c61);
                        if (v_c125 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex569, st_hsbdelta573, std::array<u64,2>{v_c120, v_c125}, [&](const std::array<u64,2>& m621) {
                          u64 v_c126 = _prim_band(db, v_c60, v_c21);
                          if (v_c126 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c127 = _prim_gt(db, v_c126, v_c119);
                          if (v_c127 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c127) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c69, v_c67, v_c62, v_c63});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c69, v_c67, v_c63, v_c62}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask574* _cont = new ReadTask574(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask574(db,b), false);
  // (crule (pre (let __tconst6u6w168 constd4735e3a265e16eee03f5971) (let __trid3Iw3761 const5e6127cdd5ea2629462053c9) (let __trel3BQx762 const1d9eff40314d54862fee3942) (let __tcol9eoL763 const5feceb66ffc86f38d952786c)) (probe st_ins (2 0 1) 1 __tconst6u6w168 __t70EZ169 __v0) (body (exists $sup97714x23x0x0x1 (1 0 2) 1 __v0) (join st_ins_ans (0 1) 1 __t70EZ169 o) (join $sup97714x23x0x0x1 (1 0 2) 1 __v0 __d0 s)) (head (tycheck s (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid3Iw3761 __trel3BQx762 __tcol9eoL763 (1 2 3 4 0)) (mkstruct st_diff (1 2 0) __1G6J760 s o)) st_basic.slog:24 #f)
  class ReadTask629 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $sup97714x23x0x0x1index623;  slog::Index** st_ins_ansindex624;  slog::Index** $sup97714x23x0x0x1index625;
    u32 sid627;  u32 sid626;  u32 sid628;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_diff");
      std::vector<u16> ord630({2, 0, 1});
      slog::Relation* readrel631 = db->getRelation("st_ins");
      driver_index = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({1, 0, 2});
      slog::Relation* readrel633 = db->getRelation("$sup97714x23x0x0x1");
      $sup97714x23x0x0x1index623 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("st_ins_ans");
      st_ins_ansindex624 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 0, 2});
      slog::Relation* readrel637 = db->getRelation("$sup97714x23x0x0x1");
      $sup97714x23x0x0x1index625 = readrel637->getIndex(ord636, false);
      sid627 = db->getRelation("_enum")->getStructId();
      sid626 = db->getRelation("pbranch")->getStructId();
      sid628 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c128 = v_constd4735e3a265e16eee03f5971;
      u64 v_c129 = v_const5e6127cdd5ea2629462053c9;
      u64 v_c130 = v_const1d9eff40314d54862fee3942;
      u64 v_c131 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c128, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m638) {
        u64 v_c132 = m638[1];
        u64 v_c21 = m638[2];
        if (buckethash(v_c132) != bucket) return;
        if (!slog::exists_probe<3,1>($sup97714x23x0x0x1index623, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe<2,1>(st_ins_ansindex624, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m639) {
          u64 v_c133 = m639[1];
          slog::join_probe<3,1>($sup97714x23x0x0x1index625, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m640) {
            u64 v_c82 = m640[1]; u64 v_c3 = m640[2];
            ++_fires;
            if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid626 || decode_struct_id(v_c3) == sid627 || decode_struct_id(v_c3) == sid628))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c129, v_c130, v_c131, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c133}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask629* _cont = new ReadTask629(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask629(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan st_union __t4eoh250 l __t8HsZ249) (body (exists st_union (2 0 1) 1 __t8HsZ249) (exists pbranch (3 0 1 2 4) 1 l) (exists $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (join st_union (2 0 1) 1 __t8HsZ249 __t3N33245 __t2RvE244) (exists $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3N33245 l) (exists $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t3N33245 l) (join pbranch (3 0 1 2 4) 2 l __t2RvE244 p m r) (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t3N33245) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t3N33245 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t8HsZ249) (exists st_msk (1 2 0) 2 q m) (join $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t3N33245 n q u v __t3q0j248) (join pbranch (1 2 3 4 0) 5 q n u v __t8HsZ249) (join st_msk (1 2 0) 3 q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask660 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex641;  slog::Index** pbranchindex642;  slog::Index** $sup9688x103x0x0x0index643;  slog::Index** $sup9688x103x0x0x1index644;  slog::Index** st_union_ansindex645;  slog::Index** st_unionindex646;  slog::Index** $sup9688x103x0x0x0index647;  slog::Index** $sup9688x103x0x0x1index648;  slog::Index** pbranchindex649;  slog::Index** $sup9688x103x0x0x1index650;  slog::Index** st_mskindex651;  slog::Index** st_msk_ansindex652;  slog::Index** $sup9688x103x0x0x0index653;  slog::Index** pbranchindex654;  slog::Index** st_mskindex655;  slog::Index** $sup9688x103x0x0x1index656;  slog::Index** pbranchindex657;  slog::Index** st_mskindex658;  slog::Index** st_msk_ansindex659;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord661({2, 0, 1});
      slog::Relation* readrel662 = db->getRelation("st_union");
      st_unionindex641 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({3, 0, 1, 2, 4});
      slog::Relation* readrel664 = db->getRelation("pbranch");
      pbranchindex642 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel666 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index643 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel668 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index644 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({0, 1});
      slog::Relation* readrel670 = db->getRelation("st_union_ans");
      st_union_ansindex645 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({2, 0, 1});
      slog::Relation* readrel672 = db->getRelation("st_union");
      st_unionindex646 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel674 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index647 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel676 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index648 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({3, 0, 1, 2, 4});
      slog::Relation* readrel678 = db->getRelation("pbranch");
      pbranchindex649 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel680 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index650 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({2, 0, 1});
      slog::Relation* readrel682 = db->getRelation("st_msk");
      st_mskindex651 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({1, 0});
      slog::Relation* readrel684 = db->getRelation("st_msk_ans");
      st_msk_ansindex652 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel686 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index653 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 3, 4, 0});
      slog::Relation* readrel688 = db->getRelation("pbranch");
      pbranchindex654 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("st_msk");
      st_mskindex655 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel692 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index656 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 3, 4, 0});
      slog::Relation* readrel694 = db->getRelation("pbranch");
      pbranchindex657 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 0});
      slog::Relation* readrel696 = db->getRelation("st_msk");
      st_mskindex658 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("st_msk_ans");
      st_msk_ansindex659 = readrel698->getIndex(ord697, false);
  
    }
    ReadTask660(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c135 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c136 = _t[2];
        if (!slog::exists_probe<3,1>(st_unionindex641, std::array<u64,3>{v_c136, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex642, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x103x0x0x0index643, std::array<u64,9>{v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x103x0x0x1index644, std::array<u64,10>{v_c7, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex645, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m699) {
          u64 v_c21 = m699[1];
          slog::join_probe<3,1>(st_unionindex646, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m700) {
            u64 v_c137 = m700[1]; u64 v_c138 = m700[2];
            if (!slog::exists_probe<9,2>($sup9688x103x0x0x0index647, std::array<u64,9>{v_c137, v_c7, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x103x0x0x1index648, std::array<u64,10>{v_c137, v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex649, std::array<u64,5>{v_c7, v_c138, 0, 0, 0}, [&](const std::array<u64,5>& m701) {
              u64 v_c5 = m701[2]; u64 v_c6 = m701[3]; u64 v_c8 = m701[4];
              if (!slog::exists_probe<10,5>($sup9688x103x0x0x1index650, std::array<u64,10>{v_c7, v_c6, v_c5, v_c8, v_c137, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex651, std::array<u64,3>{v_c6, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex652, std::array<u64,2>{v_c5, 0})) return;
              slog::join_probe<9,5>($sup9688x103x0x0x0index653, std::array<u64,9>{v_c7, v_c6, v_c5, v_c8, v_c137, 0, 0, 0, 0}, [&](const std::array<u64,9>& m702) {
                u64 v_c15 = m702[5]; u64 v_c16 = m702[6]; u64 v_c9 = m702[7]; u64 v_c10 = m702[8];
                u64 v_c139 = _prim_lt(db, v_c15, v_c6);
                if (v_c139 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                if (!v_c139) return;
                if (!slog::exists_probe<5,5>(pbranchindex654, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, v_c136})) return;
                if (!slog::exists_probe<3,2>(st_mskindex655, std::array<u64,3>{v_c16, v_c6, 0})) return;
                slog::join_probe<10,9>($sup9688x103x0x0x1index656, std::array<u64,10>{v_c7, v_c6, v_c5, v_c8, v_c137, v_c15, v_c16, v_c9, v_c10, 0}, [&](const std::array<u64,10>& m704) {
                  u64 v_c140 = m704[9];
                  slog::join_probe<5,5>(pbranchindex657, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, v_c136}, [&](const std::array<u64,5>& m705) {
                    slog::join_probe<3,3>(st_mskindex658, std::array<u64,3>{v_c16, v_c6, v_c140}, [&](const std::array<u64,3>& m706) {
                      slog::join_probe<2,2>(st_msk_ansindex659, std::array<u64,2>{v_c140, v_c5}, [&](const std::array<u64,2>& m707) {
                        u64 v_c141 = _prim_band(db, v_c16, v_c6);
                        if (v_c141 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c142 = _prim_lt(db, v_c141, v_c134);
                        if (v_c142 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c142) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c137, v_c21, v_c6, v_c5, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c5, v_c6, v_c21, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (scan st_ins_ans __t8YZs301 __v1) (body (exists st_ins (1 2 0) 2 __v1 __tconst4xiW302) (exists _enum (1 0) 1 __tconst80a51002) (exists st_ins (2 0 1) 1 __tconst87Bp297) (join-old st_ins (0 2 1) 2 (0 2 1) __t8YZs301 __tconst9HiA300 __v0) (exists st_ins_ans (1 0) 1 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4xiW302 __t43hI303) (exists st_ins_ans (0 1) 1 __t43hI303) (join _enum (1 0) 1 __tconst80a51002 __t1S8l298) (join-old st_ins (1 2 0) 2 (1 2 0) __t1S8l298 __tconst87Bp297 __t3icK299) (join st_ins_ans (0 1) 2 __t3icK299 __v0) (join-old st_ins_ans (0 1) 1 (0 1) __t43hI303 __v2)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask724 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex709;  slog::Index** _enumindex710;  slog::Index** st_insindex711;  slog::Index** st_insindex712;  slog::Index** st_ins_ansindex713;  slog::Index** st_insindex714;  slog::Index** st_ins_ansindex715;  slog::Index** _enumindex716;  slog::Index** st_insindex717;  slog::Index** st_ins_ansindex718;  slog::Index** st_ins_ansindex719;  slog::Index** st_insdelta720;  slog::Index** st_insdelta721;  slog::Index** st_insdelta722;  slog::Index** st_ins_ansdelta723;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord725({1, 2, 0});
      slog::Relation* readrel726 = db->getRelation("st_ins");
      st_insindex709 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 0});
      slog::Relation* readrel728 = db->getRelation("_enum");
      _enumindex710 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({2, 0, 1});
      slog::Relation* readrel730 = db->getRelation("st_ins");
      st_insindex711 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({0, 2, 1});
      slog::Relation* readrel732 = db->getRelation("st_ins");
      st_insindex712 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({0, 2, 1});
      slog::Relation* readrel734 = db->getRelation("st_ins");
      st_insdelta720 = readrel734->getIndex(ord733, true);
      std::vector<u16> ord735({1, 0});
      slog::Relation* readrel736 = db->getRelation("st_ins_ans");
      st_ins_ansindex713 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 2, 0});
      slog::Relation* readrel738 = db->getRelation("st_ins");
      st_insindex714 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 2, 0});
      slog::Relation* readrel740 = db->getRelation("st_ins");
      st_insdelta721 = readrel740->getIndex(ord739, true);
      std::vector<u16> ord741({0, 1});
      slog::Relation* readrel742 = db->getRelation("st_ins_ans");
      st_ins_ansindex715 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 0});
      slog::Relation* readrel744 = db->getRelation("_enum");
      _enumindex716 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({1, 2, 0});
      slog::Relation* readrel746 = db->getRelation("st_ins");
      st_insindex717 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({1, 2, 0});
      slog::Relation* readrel748 = db->getRelation("st_ins");
      st_insdelta722 = readrel748->getIndex(ord747, true);
      std::vector<u16> ord749({0, 1});
      slog::Relation* readrel750 = db->getRelation("st_ins_ans");
      st_ins_ansindex718 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({0, 1});
      slog::Relation* readrel752 = db->getRelation("st_ins_ans");
      st_ins_ansindex719 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({0, 1});
      slog::Relation* readrel754 = db->getRelation("st_ins_ans");
      st_ins_ansdelta723 = readrel754->getIndex(ord753, true);
  
    }
    ReadTask724(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c143 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c144 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c145 = v_const2c624232cdd221771294dfbb;
      u64 v_c146 = v_constd4735e3a265e16eee03f5971;
      u64 v_c147 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c148 = _t[0];
        u64 v_c39 = _t[1];
        if (!slog::exists_probe<3,2>(st_insindex709, std::array<u64,3>{v_c39, v_c146, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex710, std::array<u64,2>{v_c143, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex711, std::array<u64,3>{v_c144, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex712, st_insdelta720, std::array<u64,3>{v_c148, v_c145, 0}, [&](const std::array<u64,3>& m755) {
          u64 v_c21 = m755[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex713, std::array<u64,2>{v_c21, 0})) return;
          slog::join_probe_old<3,2>(st_insindex714, st_insdelta721, std::array<u64,3>{v_c39, v_c146, 0}, [&](const std::array<u64,3>& m756) {
            u64 v_c149 = m756[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex715, std::array<u64,2>{v_c149, 0})) return;
            slog::join_probe<2,1>(_enumindex716, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m757) {
              u64 v_c150 = m757[1];
              slog::join_probe_old<3,2>(st_insindex717, st_insdelta722, std::array<u64,3>{v_c150, v_c144, 0}, [&](const std::array<u64,3>& m758) {
                u64 v_c151 = m758[2];
                slog::join_probe<2,2>(st_ins_ansindex718, std::array<u64,2>{v_c151, v_c21}, [&](const std::array<u64,2>& m759) {
                  slog::join_probe_old<2,1>(st_ins_ansindex719, st_ins_ansdelta723, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m760) {
                    u64 v_c69 = m760[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c147}, std::array<u16,3>{1, 2, 0});
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
        ReadTask724* _cont = new ReadTask724(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask724(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan $sup9688x103x0x0x1 __t3N33245 __t3q0j248 l m n p q r u v) (body (cmp lt n m) (join $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t3N33245 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk (1 2 0) 3 q m __t3q0j248) (exists st_msk_ans (0 1) 2 __t3q0j248 p) (exists st_union (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2RvE244) (exists st_union (0 1 2) 2 __t3N33245 __t2RvE244) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_union (0 1 2) 3 (0 1 2) __t3N33245 __t2RvE244 __t8HsZ249) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask779 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x0index761;  slog::Index** pbranchindex762;  slog::Index** st_mskindex763;  slog::Index** st_msk_ansindex764;  slog::Index** st_unionindex765;  slog::Index** pbranchindex766;  slog::Index** st_unionindex767;  slog::Index** pbranchindex768;  slog::Index** st_unionindex769;  slog::Index** st_mskindex770;  slog::Index** st_msk_ansindex771;  slog::Index** st_unionindex772;  slog::Index** st_union_ansindex773;  slog::Index** pbranchdelta774;  slog::Index** pbranchdelta775;  slog::Index** st_uniondelta776;  slog::Index** st_mskdelta777;  slog::Index** st_uniondelta778;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord780({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel781 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index761 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 3, 4, 0});
      slog::Relation* readrel783 = db->getRelation("pbranch");
      pbranchindex762 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 2, 0});
      slog::Relation* readrel785 = db->getRelation("st_msk");
      st_mskindex763 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({0, 1});
      slog::Relation* readrel787 = db->getRelation("st_msk_ans");
      st_msk_ansindex764 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("st_union");
      st_unionindex765 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 3, 4, 0});
      slog::Relation* readrel791 = db->getRelation("pbranch");
      pbranchindex766 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 3, 4, 0});
      slog::Relation* readrel793 = db->getRelation("pbranch");
      pbranchdelta774 = readrel793->getIndex(ord792, true);
      std::vector<u16> ord794({0, 1, 2});
      slog::Relation* readrel795 = db->getRelation("st_union");
      st_unionindex767 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 3, 4, 0});
      slog::Relation* readrel797 = db->getRelation("pbranch");
      pbranchindex768 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 3, 4, 0});
      slog::Relation* readrel799 = db->getRelation("pbranch");
      pbranchdelta775 = readrel799->getIndex(ord798, true);
      std::vector<u16> ord800({0, 1, 2});
      slog::Relation* readrel801 = db->getRelation("st_union");
      st_unionindex769 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({0, 1, 2});
      slog::Relation* readrel803 = db->getRelation("st_union");
      st_uniondelta776 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("st_msk");
      st_mskindex770 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("st_msk");
      st_mskdelta777 = readrel807->getIndex(ord806, true);
      std::vector<u16> ord808({0, 1});
      slog::Relation* readrel809 = db->getRelation("st_msk_ans");
      st_msk_ansindex771 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 0});
      slog::Relation* readrel811 = db->getRelation("st_union");
      st_unionindex772 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({1, 2, 0});
      slog::Relation* readrel813 = db->getRelation("st_union");
      st_uniondelta778 = readrel813->getIndex(ord812, true);
      std::vector<u16> ord814({0, 1});
      slog::Relation* readrel815 = db->getRelation("st_union_ans");
      st_union_ansindex773 = readrel815->getIndex(ord814, false);
  
    }
    ReadTask779(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c137 = _t[0];
        u64 v_c140 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c5 = _t[5];
        u64 v_c16 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c9 = _t[8];
        u64 v_c10 = _t[9];
        u64 v_c152 = _prim_lt(db, v_c15, v_c6);
        if (v_c152 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
        if (!v_c152) return;
        slog::join_probe<9,9>($sup9688x103x0x0x0index761, std::array<u64,9>{v_c7, v_c6, v_c5, v_c8, v_c137, v_c15, v_c16, v_c9, v_c10}, [&](const std::array<u64,9>& m817) {
          if (!slog::exists_probe<5,4>(pbranchindex762, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex763, std::array<u64,3>{v_c16, v_c6, v_c140})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex764, std::array<u64,2>{v_c140, v_c5})) return;
          if (!slog::exists_probe<3,1>(st_unionindex765, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex766, pbranchdelta774, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m818) {
            u64 v_c138 = m818[4];
            if (!slog::exists_probe<3,2>(st_unionindex767, std::array<u64,3>{v_c137, v_c138, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex768, pbranchdelta775, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m819) {
              u64 v_c136 = m819[4];
              slog::join_probe_old<3,3>(st_unionindex769, st_uniondelta776, std::array<u64,3>{v_c137, v_c138, v_c136}, [&](const std::array<u64,3>& m820) {
                slog::join_probe_old<3,3>(st_mskindex770, st_mskdelta777, std::array<u64,3>{v_c16, v_c6, v_c140}, [&](const std::array<u64,3>& m821) {
                  slog::join_probe<2,2>(st_msk_ansindex771, std::array<u64,2>{v_c140, v_c5}, [&](const std::array<u64,2>& m822) {
                    slog::join_probe_old<3,2>(st_unionindex772, st_uniondelta778, std::array<u64,3>{v_c7, v_c136, 0}, [&](const std::array<u64,3>& m823) {
                      u64 v_c135 = m823[2];
                      slog::join_probe<2,1>(st_union_ansindex773, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m824) {
                        u64 v_c21 = m824[1];
                        u64 v_c141 = _prim_band(db, v_c16, v_c6);
                        if (v_c141 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c153 = _prim_lt(db, v_c141, v_c134);
                        if (v_c153 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c153) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c137, v_c21, v_c6, v_c5, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c5, v_c6, v_c21, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:$sup9688x103x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask779* _cont = new ReadTask779(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask779(db,b), false);
  // (crule (pre) (scan $sup9688x50x0x0x0 __d0 k l m p r) (body (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t412X321) (join-old st_msk_ans (0 1) 2 (0 1) __t412X321 p)) (head (emit $sup9688x50x0x0x1 (0 2 1 3 4 5 6) __d0 k __t412X321 l m p r)) set.slog:51 #f)
  class ReadTask831 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex826;  slog::Index** st_mskindex827;  slog::Index** st_msk_ansindex828;  slog::Index** st_mskdelta829;  slog::Index** st_msk_ansdelta830;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord832({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel833 = db->getRelation("$sup9688x50x0x0x1");
      head_index[0] = readrel833->getIndex(ord832, false);
      outer_rel = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord834({1, 0});
      slog::Relation* readrel835 = db->getRelation("st_msk_ans");
      st_msk_ansindex826 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({1, 2, 0});
      slog::Relation* readrel837 = db->getRelation("st_msk");
      st_mskindex827 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("st_msk");
      st_mskdelta829 = readrel839->getIndex(ord838, true);
      std::vector<u16> ord840({0, 1});
      slog::Relation* readrel841 = db->getRelation("st_msk_ans");
      st_msk_ansindex828 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({0, 1});
      slog::Relation* readrel843 = db->getRelation("st_msk_ans");
      st_msk_ansdelta830 = readrel843->getIndex(ord842, true);
  
    }
    ReadTask831(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c5 = _t[4];
        u64 v_c8 = _t[5];
        if (!slog::exists_probe<2,1>(st_msk_ansindex826, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex827, st_mskdelta829, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m844) {
          u64 v_c154 = m844[2];
          slog::join_probe_old<2,2>(st_msk_ansindex828, st_msk_ansdelta830, std::array<u64,2>{v_c154, v_c5}, [&](const std::array<u64,2>& m845) {
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c82, v_c1, v_c154, v_c7, v_c6, v_c5, v_c8}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:$sup9688x50x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask831* _cont = new ReadTask831(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask831(db,b), false);
  // (crule (pre) (scan st_join __t3WPW519 p __t52IG517 q __t1VuF518) (body (neq p q) (exists pbranch (0 1 2 3 4) 2 __t52IG517 p) (exists pbranch (0 1 2 3 4) 2 __t1VuF518 q) (exists st_join_ans (0 1) 1 __t3WPW519) (join st_union (1 2 0) 2 __t52IG517 __t1VuF518 __t5oQM516) (join pbranch (0 1 2 3 4) 2 __t52IG517 p m l r) (join pbranch (0 1 2 3 4) 3 __t1VuF518 q m u v) (join st_join_ans (0 1) 1 __t3WPW519 res)) (head (emit st_union_ans (0 1) __t5oQM516 res)) set.slog:125 #f)
  class ReadTask853 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex846;  slog::Index** pbranchindex847;  slog::Index** st_join_ansindex848;  slog::Index** st_unionindex849;  slog::Index** pbranchindex850;  slog::Index** pbranchindex851;  slog::Index** st_join_ansindex852;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord854({0, 1});
      slog::Relation* readrel855 = db->getRelation("st_union_ans");
      head_index[0] = readrel855->getIndex(ord854, false);
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord856({0, 1, 2, 3, 4});
      slog::Relation* readrel857 = db->getRelation("pbranch");
      pbranchindex846 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 1, 2, 3, 4});
      slog::Relation* readrel859 = db->getRelation("pbranch");
      pbranchindex847 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({0, 1});
      slog::Relation* readrel861 = db->getRelation("st_join_ans");
      st_join_ansindex848 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("st_union");
      st_unionindex849 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({0, 1, 2, 3, 4});
      slog::Relation* readrel865 = db->getRelation("pbranch");
      pbranchindex850 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1, 2, 3, 4});
      slog::Relation* readrel867 = db->getRelation("pbranch");
      pbranchindex851 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1});
      slog::Relation* readrel869 = db->getRelation("st_join_ans");
      st_join_ansindex852 = readrel869->getIndex(ord868, false);
  
    }
    ReadTask853(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c155 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c156 = _t[2];
        u64 v_c16 = _t[3];
        u64 v_c157 = _t[4];
        if (v_c5 == v_c16) return;
        if (!slog::exists_probe<5,2>(pbranchindex846, std::array<u64,5>{v_c156, v_c5, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(pbranchindex847, std::array<u64,5>{v_c157, v_c16, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_join_ansindex848, std::array<u64,2>{v_c155, 0})) return;
        slog::join_probe<3,2>(st_unionindex849, std::array<u64,3>{v_c156, v_c157, 0}, [&](const std::array<u64,3>& m870) {
          u64 v_c158 = m870[2];
          slog::join_probe<5,2>(pbranchindex850, std::array<u64,5>{v_c156, v_c5, 0, 0, 0}, [&](const std::array<u64,5>& m871) {
            u64 v_c6 = m871[2]; u64 v_c7 = m871[3]; u64 v_c8 = m871[4];
            slog::join_probe<5,3>(pbranchindex851, std::array<u64,5>{v_c157, v_c16, v_c6, 0, 0}, [&](const std::array<u64,5>& m872) {
              u64 v_c9 = m872[3]; u64 v_c10 = m872[4];
              slog::join_probe<2,1>(st_join_ansindex852, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m873) {
                u64 v_c24 = m873[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c158, v_c24}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask853* _cont = new ReadTask853(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask853(db,b), false);
  // (crule (pre) (scan st_msk_ans __t9Q9j15 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t9Q9j15 k m) (exists st_join (1 2 3 4 0) 1 k) (exists $sup9688x54x0x0x0 (1 3 0 2 4 5 6) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_ins (2 0 1) 1 k) (join-old pleaf (1 0) 1 (1 0) k __t4JtR13) (join-old st_join (1 2 3 4 0) 2 (1 2 3 4 0) k __t4JtR13 p __t4iIu12 __t4hUr14) (neq p __v0) (exists pbranch (0 1 2 3 4) 3 __t4iIu12 p m) (exists st_ins (1 2 0) 2 __t4iIu12 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join-old $sup9688x54x0x0x0 (1 4 6 3 0 2 5) 4 (1 4 6 3 0 2 5) k p __t4iIu12 m __t2YgE11 l r) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t4iIu12) (join-old st_ins (0 2 1) 3 (0 2 1) __t2YgE11 k __t4iIu12) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask894 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex874;  slog::Index** st_joinindex875;  slog::Index** $sup9688x54x0x0x0index876;  slog::Index** pbranchindex877;  slog::Index** st_insindex878;  slog::Index** pleafindex879;  slog::Index** st_joinindex880;  slog::Index** pbranchindex881;  slog::Index** st_insindex882;  slog::Index** st_join_ansindex883;  slog::Index** $sup9688x54x0x0x0index884;  slog::Index** pbranchindex885;  slog::Index** st_insindex886;  slog::Index** st_join_ansindex887;  slog::Index** st_mskdelta888;  slog::Index** pleafdelta889;  slog::Index** st_joindelta890;  slog::Index** $sup9688x54x0x0x0delta891;  slog::Index** pbranchdelta892;  slog::Index** st_insdelta893;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("st_ins_ans");
      head_index[0] = readrel896->getIndex(ord895, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("st_msk");
      st_mskindex874 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({0, 1, 2});
      slog::Relation* readrel900 = db->getRelation("st_msk");
      st_mskdelta888 = readrel900->getIndex(ord899, true);
      std::vector<u16> ord901({1, 2, 3, 4, 0});
      slog::Relation* readrel902 = db->getRelation("st_join");
      st_joinindex875 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 3, 0, 2, 4, 5, 6});
      slog::Relation* readrel904 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index876 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({2, 0, 1, 3, 4});
      slog::Relation* readrel906 = db->getRelation("pbranch");
      pbranchindex877 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({2, 0, 1});
      slog::Relation* readrel908 = db->getRelation("st_ins");
      st_insindex878 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({1, 0});
      slog::Relation* readrel910 = db->getRelation("pleaf");
      pleafindex879 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({1, 0});
      slog::Relation* readrel912 = db->getRelation("pleaf");
      pleafdelta889 = readrel912->getIndex(ord911, true);
      std::vector<u16> ord913({1, 2, 3, 4, 0});
      slog::Relation* readrel914 = db->getRelation("st_join");
      st_joinindex880 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 2, 3, 4, 0});
      slog::Relation* readrel916 = db->getRelation("st_join");
      st_joindelta890 = readrel916->getIndex(ord915, true);
      std::vector<u16> ord917({0, 1, 2, 3, 4});
      slog::Relation* readrel918 = db->getRelation("pbranch");
      pbranchindex881 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 2, 0});
      slog::Relation* readrel920 = db->getRelation("st_ins");
      st_insindex882 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("st_join_ans");
      st_join_ansindex883 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel924 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index884 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel926 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0delta891 = readrel926->getIndex(ord925, true);
      std::vector<u16> ord927({1, 2, 3, 4, 0});
      slog::Relation* readrel928 = db->getRelation("pbranch");
      pbranchindex885 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 2, 3, 4, 0});
      slog::Relation* readrel930 = db->getRelation("pbranch");
      pbranchdelta892 = readrel930->getIndex(ord929, true);
      std::vector<u16> ord931({0, 2, 1});
      slog::Relation* readrel932 = db->getRelation("st_ins");
      st_insindex886 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({0, 2, 1});
      slog::Relation* readrel934 = db->getRelation("st_ins");
      st_insdelta893 = readrel934->getIndex(ord933, true);
      std::vector<u16> ord935({0, 1});
      slog::Relation* readrel936 = db->getRelation("st_join_ans");
      st_join_ansindex887 = readrel936->getIndex(ord935, false);
  
    }
    ReadTask894(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c159 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex874, st_mskdelta888, std::array<u64,3>{v_c159, 0, 0}, [&](const std::array<u64,3>& m937) {
          u64 v_c1 = m937[1]; u64 v_c6 = m937[2];
          if (!slog::exists_probe<5,1>(st_joinindex875, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,2>($sup9688x54x0x0x0index876, std::array<u64,7>{v_c1, v_c6, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex877, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex878, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<2,1>(pleafindex879, pleafdelta889, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m938) {
            u64 v_c160 = m938[1];
            slog::join_probe_old<5,2>(st_joinindex880, st_joindelta890, std::array<u64,5>{v_c1, v_c160, 0, 0, 0}, [&](const std::array<u64,5>& m939) {
              u64 v_c5 = m939[2]; u64 v_c161 = m939[3]; u64 v_c162 = m939[4];
              if (v_c5 == v_c21) return;
              if (!slog::exists_probe<5,3>(pbranchindex881, std::array<u64,5>{v_c161, v_c5, v_c6, 0, 0})) return;
              if (!slog::exists_probe<3,2>(st_insindex882, std::array<u64,3>{v_c161, v_c1, 0})) return;
              if (!slog::exists_probe<2,1>(st_join_ansindex883, std::array<u64,2>{v_c162, 0})) return;
              slog::join_probe_old<7,4>($sup9688x54x0x0x0index884, $sup9688x54x0x0x0delta891, std::array<u64,7>{v_c1, v_c5, v_c161, v_c6, 0, 0, 0}, [&](const std::array<u64,7>& m940) {
                u64 v_c163 = m940[4]; u64 v_c7 = m940[5]; u64 v_c8 = m940[6];
                slog::join_probe_old<5,5>(pbranchindex885, pbranchdelta892, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, v_c161}, [&](const std::array<u64,5>& m941) {
                  slog::join_probe_old<3,3>(st_insindex886, st_insdelta893, std::array<u64,3>{v_c163, v_c1, v_c161}, [&](const std::array<u64,3>& m942) {
                    slog::join_probe<2,1>(st_join_ansindex887, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m943) {
                      u64 v_c24 = m943[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c163, v_c24}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask894* _cont = new ReadTask894(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask894(db,b), false);
  // (crule (pre (let __tconst9k1p217 const6b86b273ff34fce19d6b804e)) (scan pbranch __t3Raq215 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t3Raq215 __t1kmq214 __t0V4b216) (join pbranch (0 1 2 3 4) 1 __t1kmq214 q n u v) (cmp lt n m) (let __t76JX218 (band q m)) (cmp lt __t76JX218 __tconst9k1p217)) (head (emit $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) __t0V4b216 l m n p q r u v)) set.slog:140 #f)
  class ReadTask947 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex944;  slog::Index** pbranchindex945;  slog::Index** st_diffdelta946;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord948({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel949 = db->getRelation("$sup9688x139x0x0x0");
      head_index[0] = readrel949->getIndex(ord948, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord950({1, 2, 0});
      slog::Relation* readrel951 = db->getRelation("st_diff");
      st_diffindex944 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("st_diff");
      st_diffdelta946 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({0, 1, 2, 3, 4});
      slog::Relation* readrel955 = db->getRelation("pbranch");
      pbranchindex945 = readrel955->getIndex(ord954, false);
  
    }
    ReadTask947(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c164 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c165 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex944, st_diffdelta946, std::array<u64,3>{v_c165, 0, 0}, [&](const std::array<u64,3>& m956) {
          u64 v_c166 = m956[1]; u64 v_c167 = m956[2];
          slog::join_probe<5,1>(pbranchindex945, std::array<u64,5>{v_c166, 0, 0, 0, 0}, [&](const std::array<u64,5>& m957) {
            u64 v_c16 = m957[1]; u64 v_c15 = m957[2]; u64 v_c9 = m957[3]; u64 v_c10 = m957[4];
            u64 v_c168 = _prim_lt(db, v_c15, v_c6);
            if (v_c168 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c168) return;
            u64 v_c169 = _prim_band(db, v_c16, v_c6);
            if (v_c169 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            u64 v_c170 = _prim_lt(db, v_c169, v_c164);
            if (v_c170 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c170) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c167, v_c7, v_c6, v_c15, v_c5, v_c16, v_c8, v_c9, v_c10}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask947* _cont = new ReadTask947(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask947(db,b), false);
  // (crule (pre (let __trid1zVR1065 const7d00193796cbe9983b9801f2) (let __trel6OtI1066 const99e1cbf3d792d4a87847a801) (let __tcol7rlv1067 const5feceb66ffc86f38d952786c) (let __trel8jbe1068 const99e1cbf3d792d4a87847a801) (let __tcol43VY1069 const6b86b273ff34fce19d6b804e)) (scan $sup9688x50x0x0x1 __d0 __d1 k l m p r) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid1zVR1065 __trel6OtI1066 __tcol7rlv1067 (1 2 3 4 0)) (tycheck k (accept int) __trid1zVR1065 __trel8jbe1068 __tcol43VY1069 (1 2 3 4 0)) (mkstruct st_ins (1 2 0) __1EoB1064 l k)) set.slog:51 #f)
  class ReadTask963 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid961;  u32 sid960;  u32 sid962;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_ins");
      outer_rel = db->getRelation("$sup9688x50x0x0x1");
      sid961 = db->getRelation("_enum")->getStructId();
      sid960 = db->getRelation("pbranch")->getStructId();
      sid962 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask963(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c171 = v_const7d00193796cbe9983b9801f2;
      u64 v_c172 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c173 = v_const5feceb66ffc86f38d952786c;
      u64 v_c174 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c175 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c176 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c5 = _t[5];
        u64 v_c8 = _t[6];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid960 || decode_struct_id(v_c7) == sid961 || decode_struct_id(v_c7) == sid962))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c171, v_c172, v_c173, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c171, v_c174, v_c175, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c7, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:$sup9688x50x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask963* _cont = new ReadTask963(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask963(db,b), false);
  // (crule (pre) (scan pleaf __t7Mu9183 k) (body (exists st_ins (2 0 1) 1 k) (join-old st_union (1 2 0) 1 (1 2 0) __t7Mu9183 t __t2rFM184) (join-old st_ins (1 2 0) 2 (1 2 0) t k __t5aIA185) (join st_ins_ans (0 1) 1 __t5aIA185 r)) (head (emit st_union_ans (0 1) __t2rFM184 r)) set.slog:98 #f)
  class ReadTask970 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex964;  slog::Index** st_unionindex965;  slog::Index** st_insindex966;  slog::Index** st_ins_ansindex967;  slog::Index** st_uniondelta968;  slog::Index** st_insdelta969;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord971({0, 1});
      slog::Relation* readrel972 = db->getRelation("st_union_ans");
      head_index[0] = readrel972->getIndex(ord971, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord973({2, 0, 1});
      slog::Relation* readrel974 = db->getRelation("st_ins");
      st_insindex964 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({1, 2, 0});
      slog::Relation* readrel976 = db->getRelation("st_union");
      st_unionindex965 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({1, 2, 0});
      slog::Relation* readrel978 = db->getRelation("st_union");
      st_uniondelta968 = readrel978->getIndex(ord977, true);
      std::vector<u16> ord979({1, 2, 0});
      slog::Relation* readrel980 = db->getRelation("st_ins");
      st_insindex966 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 2, 0});
      slog::Relation* readrel982 = db->getRelation("st_ins");
      st_insdelta969 = readrel982->getIndex(ord981, true);
      std::vector<u16> ord983({0, 1});
      slog::Relation* readrel984 = db->getRelation("st_ins_ans");
      st_ins_ansindex967 = readrel984->getIndex(ord983, false);
  
    }
    ReadTask970(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c177 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex964, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex965, st_uniondelta968, std::array<u64,3>{v_c177, 0, 0}, [&](const std::array<u64,3>& m985) {
          u64 v_c83 = m985[1]; u64 v_c178 = m985[2];
          slog::join_probe_old<3,2>(st_insindex966, st_insdelta969, std::array<u64,3>{v_c83, v_c1, 0}, [&](const std::array<u64,3>& m986) {
            u64 v_c179 = m986[2];
            slog::join_probe<2,1>(st_ins_ansindex967, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m987) {
              u64 v_c8 = m987[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c178, v_c8}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask970* _cont = new ReadTask970(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask970(db,b), false);
  // (crule (pre) (scan st_msk __t6jwI501 q m) (body (exists $sup9688x106x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join st_msk_ans (0 1) 1 __t6jwI501 p) (join $sup9688x106x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t6jwI501 l m n p q u v)) set.slog:107 #f)
  class ReadTask991 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x0index988;  slog::Index** st_msk_ansindex989;  slog::Index** $sup9688x106x0x0x0index990;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord992({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel993 = db->getRelation("$sup9688x106x0x0x1");
      head_index[0] = readrel993->getIndex(ord992, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord994({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel995 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index988 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({0, 1});
      slog::Relation* readrel997 = db->getRelation("st_msk_ans");
      st_msk_ansindex989 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel999 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index990 = readrel999->getIndex(ord998, false);
  
    }
    ReadTask991(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x106x0x0x0index988, std::array<u64,9>{v_c6, v_c16, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex989, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m1000) {
          u64 v_c5 = m1000[1];
          slog::join_probe<9,3>($sup9688x106x0x0x0index990, std::array<u64,9>{v_c6, v_c16, v_c5, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1001) {
            u64 v_c82 = m1001[3]; u64 v_c7 = m1001[4]; u64 v_c15 = m1001[5]; u64 v_c8 = m1001[6]; u64 v_c9 = m1001[7]; u64 v_c10 = m1001[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c82, v_c8, v_c180, v_c7, v_c6, v_c15, v_c5, v_c16, v_c9, v_c10}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_msk", _fires);
  
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
  // (crule (pre (let __tconst9s1r696 conste3776bfed7f405de8017ecfa)) (scan pleaf __t0pJC509 k) (body (exists _enum (1 0) 1 __tconst9s1r696) (join-old st_del (1 2 0) 2 (1 2 0) __t0pJC509 k __t6cBI510) (join _enum (1 0) 1 __tconst9s1r696 __t3Ch3508)) (head (emit st_del_ans (0 1) __t6cBI510 __t3Ch3508)) set.slog:86 #f)
  class ReadTask1006 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1002;  slog::Index** st_delindex1003;  slog::Index** _enumindex1004;  slog::Index** st_deldelta1005;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1007({0, 1});
      slog::Relation* readrel1008 = db->getRelation("st_del_ans");
      head_index[0] = readrel1008->getIndex(ord1007, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1009({1, 0});
      slog::Relation* readrel1010 = db->getRelation("_enum");
      _enumindex1002 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 0});
      slog::Relation* readrel1012 = db->getRelation("st_del");
      st_delindex1003 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 2, 0});
      slog::Relation* readrel1014 = db->getRelation("st_del");
      st_deldelta1005 = readrel1014->getIndex(ord1013, true);
      std::vector<u16> ord1015({1, 0});
      slog::Relation* readrel1016 = db->getRelation("_enum");
      _enumindex1004 = readrel1016->getIndex(ord1015, false);
  
    }
    ReadTask1006(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c182 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex1002, std::array<u64,2>{v_c181, 0})) return;
        slog::join_probe_old<3,2>(st_delindex1003, st_deldelta1005, std::array<u64,3>{v_c182, v_c1, 0}, [&](const std::array<u64,3>& m1017) {
          u64 v_c183 = m1017[2];
          slog::join_probe<2,1>(_enumindex1004, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m1018) {
            u64 v_c184 = m1018[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c183, v_c184}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:86", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1006* _cont = new ReadTask1006(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1006(db,b), false);
  // (crule (pre (let __tconst03UB810 conste3776bfed7f405de8017ecfa) (let __tconst71XF295 const6b86b273ff34fce19d6b804e)) (scan st_diff __t8FIc293 __t1D2a292 t) (body (exists st_mem0_ans (1 0) 1 __tconst71XF295) (exists st_mem0 (1 2 0) 1 t) (join _enum (1 0) 1 __tconst03UB810 __t26at291) (join st_mem0_ans (1 0) 1 __tconst71XF295 __t38OP294) (join-old st_mem0 (0 1 2) 2 (0 1 2) __t38OP294 t k) (join pleaf (0 1) 2 __t1D2a292 k)) (head (emit st_diff_ans (0 1) __t8FIc293 __t26at291)) set.slog:135 #f)
  class ReadTask1026 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0_ansindex1019;  slog::Index** st_mem0index1020;  slog::Index** _enumindex1021;  slog::Index** st_mem0_ansindex1022;  slog::Index** st_mem0index1023;  slog::Index** pleafindex1024;  slog::Index** st_mem0delta1025;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1027({0, 1});
      slog::Relation* readrel1028 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1028->getIndex(ord1027, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1029({1, 0});
      slog::Relation* readrel1030 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1019 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 0});
      slog::Relation* readrel1032 = db->getRelation("st_mem0");
      st_mem0index1020 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 0});
      slog::Relation* readrel1034 = db->getRelation("_enum");
      _enumindex1021 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 0});
      slog::Relation* readrel1036 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1022 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({0, 1, 2});
      slog::Relation* readrel1038 = db->getRelation("st_mem0");
      st_mem0index1023 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1, 2});
      slog::Relation* readrel1040 = db->getRelation("st_mem0");
      st_mem0delta1025 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({0, 1});
      slog::Relation* readrel1042 = db->getRelation("pleaf");
      pleafindex1024 = readrel1042->getIndex(ord1041, false);
  
    }
    ReadTask1026(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c186 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c187 = _t[0];
        u64 v_c188 = _t[1];
        u64 v_c83 = _t[2];
        if (!slog::exists_probe<2,1>(st_mem0_ansindex1019, std::array<u64,2>{v_c186, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index1020, std::array<u64,3>{v_c83, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex1021, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m1043) {
          u64 v_c189 = m1043[1];
          slog::join_probe<2,1>(st_mem0_ansindex1022, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m1044) {
            u64 v_c190 = m1044[1];
            slog::join_probe_old<3,2>(st_mem0index1023, st_mem0delta1025, std::array<u64,3>{v_c190, v_c83, 0}, [&](const std::array<u64,3>& m1045) {
              u64 v_c1 = m1045[2];
              slog::join_probe<2,2>(pleafindex1024, std::array<u64,2>{v_c188, v_c1}, [&](const std::array<u64,2>& m1046) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c187, v_c189}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1026* _cont = new ReadTask1026(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1026(db,b), false);
  // (crule (pre) (scan pbranch __t7Xsy485 p m l r) (body (exists pbranch (2 0 1 3 4) 1 m) (join-old st_diff (1 2 0) 1 (1 2 0) __t7Xsy485 __t7Veu484 __t7G0O486) (join pbranch (2 0 1 3 4) 2 m __t7Veu484 q u v) (neq p q)) (head (emit st_diff_ans (0 1) __t7G0O486 __t7Xsy485)) set.slog:158 #f)
  class ReadTask1051 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1047;  slog::Index** st_diffindex1048;  slog::Index** pbranchindex1049;  slog::Index** st_diffdelta1050;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1052({0, 1});
      slog::Relation* readrel1053 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1053->getIndex(ord1052, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1054({2, 0, 1, 3, 4});
      slog::Relation* readrel1055 = db->getRelation("pbranch");
      pbranchindex1047 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 2, 0});
      slog::Relation* readrel1057 = db->getRelation("st_diff");
      st_diffindex1048 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 2, 0});
      slog::Relation* readrel1059 = db->getRelation("st_diff");
      st_diffdelta1050 = readrel1059->getIndex(ord1058, true);
      std::vector<u16> ord1060({2, 0, 1, 3, 4});
      slog::Relation* readrel1061 = db->getRelation("pbranch");
      pbranchindex1049 = readrel1061->getIndex(ord1060, false);
  
    }
    ReadTask1051(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex1047, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex1048, st_diffdelta1050, std::array<u64,3>{v_c191, 0, 0}, [&](const std::array<u64,3>& m1062) {
          u64 v_c192 = m1062[1]; u64 v_c193 = m1062[2];
          slog::join_probe<5,2>(pbranchindex1049, std::array<u64,5>{v_c6, v_c192, 0, 0, 0}, [&](const std::array<u64,5>& m1063) {
            u64 v_c16 = m1063[2]; u64 v_c9 = m1063[3]; u64 v_c10 = m1063[4];
            if (v_c5 == v_c16) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c193, v_c191}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:158", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1051* _cont = new ReadTask1051(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1051(db,b), false);
  // (crule (pre (let __tconst6e891006 conste3776bfed7f405de8017ecfa) (let __tconst83Ow461 const6b86b273ff34fce19d6b804e)) (probe _enum (1 0) 1 __tconst6e891006 __t5Rai462) (body) (head (mkstruct st_ins (1 2 0) __6mmC1005 __t5Rai462 __tconst83Ow461)) st_basic.slog:15 #f)
  class ReadTask1064 : public slog::Task
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
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord1065({1, 0});
      slog::Relation* readrel1066 = db->getRelation("_enum");
      driver_index = readrel1066->getIndex(ord1065, true);
  
    }
    ReadTask1064(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c194 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c195 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c194, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1067) {
        u64 v_c196 = m1067[1];
        if (buckethash(v_c196) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c196, v_c195}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask1064* _cont = new ReadTask1064(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1064(db,b), true);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t8DQ7163 p) (body (exists $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (exists st_bld (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t8DQ7163 q m) (exists pbranch (1 2 3 4 0) 2 p m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_bld (1 2 3 4 0) 2 p m) (join-old $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 3 (2 5 4 0 1 3 6 7 8) m q p __t3X8M159 l n r u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_diff (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t66RN158) (exists st_diff (0 1 2) 2 __t3X8M159 __t66RN158) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6ACr164) (join-old st_diff (0 1 2) 3 (0 1 2) __t3X8M159 __t66RN158 __t6ACr164) (exists st_diff (1 2 0) 2 l __t6ACr164) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t1RXD162 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_diff (1 2 0) 2 (1 2 0) l __t6ACr164 __t0YPK165) (join-old st_diff_ans (0 1) 2 (0 1) __t0YPK165 __v0) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask1098 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index1068;  slog::Index** pbranchindex1069;  slog::Index** st_bldindex1070;  slog::Index** st_mskindex1071;  slog::Index** pbranchindex1072;  slog::Index** pbranchindex1073;  slog::Index** st_bldindex1074;  slog::Index** $sup9688x139x0x0x0index1075;  slog::Index** pbranchindex1076;  slog::Index** st_bldindex1077;  slog::Index** st_diffindex1078;  slog::Index** pbranchindex1079;  slog::Index** st_diffindex1080;  slog::Index** pbranchindex1081;  slog::Index** st_diffindex1082;  slog::Index** st_diffindex1083;  slog::Index** st_bldindex1084;  slog::Index** st_diff_ansindex1085;  slog::Index** st_bld_ansindex1086;  slog::Index** st_diffindex1087;  slog::Index** st_diff_ansindex1088;  slog::Index** st_bld_ansindex1089;  slog::Index** st_mskdelta1090;  slog::Index** $sup9688x139x0x0x0delta1091;  slog::Index** pbranchdelta1092;  slog::Index** pbranchdelta1093;  slog::Index** st_diffdelta1094;  slog::Index** st_blddelta1095;  slog::Index** st_diffdelta1096;  slog::Index** st_diff_ansdelta1097;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1100->getIndex(ord1099, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1101({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel1102 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1068 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 2, 3, 4, 0});
      slog::Relation* readrel1104 = db->getRelation("pbranch");
      pbranchindex1069 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({1, 2, 3, 4, 0});
      slog::Relation* readrel1106 = db->getRelation("st_bld");
      st_bldindex1070 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({0, 1, 2});
      slog::Relation* readrel1108 = db->getRelation("st_msk");
      st_mskindex1071 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({0, 1, 2});
      slog::Relation* readrel1110 = db->getRelation("st_msk");
      st_mskdelta1090 = readrel1110->getIndex(ord1109, true);
      std::vector<u16> ord1111({1, 2, 3, 4, 0});
      slog::Relation* readrel1112 = db->getRelation("pbranch");
      pbranchindex1072 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 2, 3, 4, 0});
      slog::Relation* readrel1114 = db->getRelation("pbranch");
      pbranchindex1073 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({1, 2, 3, 4, 0});
      slog::Relation* readrel1116 = db->getRelation("st_bld");
      st_bldindex1074 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1118 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1075 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1120 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0delta1091 = readrel1120->getIndex(ord1119, true);
      std::vector<u16> ord1121({1, 2, 3, 4, 0});
      slog::Relation* readrel1122 = db->getRelation("pbranch");
      pbranchindex1076 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({2, 1, 4, 0, 3});
      slog::Relation* readrel1124 = db->getRelation("st_bld");
      st_bldindex1077 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("st_diff");
      st_diffindex1078 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 3, 4, 0});
      slog::Relation* readrel1128 = db->getRelation("pbranch");
      pbranchindex1079 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 3, 4, 0});
      slog::Relation* readrel1130 = db->getRelation("pbranch");
      pbranchdelta1092 = readrel1130->getIndex(ord1129, true);
      std::vector<u16> ord1131({0, 1, 2});
      slog::Relation* readrel1132 = db->getRelation("st_diff");
      st_diffindex1080 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 2, 3, 4, 0});
      slog::Relation* readrel1134 = db->getRelation("pbranch");
      pbranchindex1081 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 2, 3, 4, 0});
      slog::Relation* readrel1136 = db->getRelation("pbranch");
      pbranchdelta1093 = readrel1136->getIndex(ord1135, true);
      std::vector<u16> ord1137({0, 1, 2});
      slog::Relation* readrel1138 = db->getRelation("st_diff");
      st_diffindex1082 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({0, 1, 2});
      slog::Relation* readrel1140 = db->getRelation("st_diff");
      st_diffdelta1094 = readrel1140->getIndex(ord1139, true);
      std::vector<u16> ord1141({1, 2, 0});
      slog::Relation* readrel1142 = db->getRelation("st_diff");
      st_diffindex1083 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({2, 1, 4, 0, 3});
      slog::Relation* readrel1144 = db->getRelation("st_bld");
      st_bldindex1084 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({2, 1, 4, 0, 3});
      slog::Relation* readrel1146 = db->getRelation("st_bld");
      st_blddelta1095 = readrel1146->getIndex(ord1145, true);
      std::vector<u16> ord1147({1, 0});
      slog::Relation* readrel1148 = db->getRelation("st_diff_ans");
      st_diff_ansindex1085 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({0, 1});
      slog::Relation* readrel1150 = db->getRelation("st_bld_ans");
      st_bld_ansindex1086 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({1, 2, 0});
      slog::Relation* readrel1152 = db->getRelation("st_diff");
      st_diffindex1087 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({1, 2, 0});
      slog::Relation* readrel1154 = db->getRelation("st_diff");
      st_diffdelta1096 = readrel1154->getIndex(ord1153, true);
      std::vector<u16> ord1155({0, 1});
      slog::Relation* readrel1156 = db->getRelation("st_diff_ans");
      st_diff_ansindex1088 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({0, 1});
      slog::Relation* readrel1158 = db->getRelation("st_diff_ans");
      st_diff_ansdelta1097 = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({0, 1});
      slog::Relation* readrel1160 = db->getRelation("st_bld_ans");
      st_bld_ansindex1089 = readrel1160->getIndex(ord1159, false);
  
    }
    ReadTask1098(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c5 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index1068, std::array<u64,9>{v_c5, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1069, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex1070, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1071, st_mskdelta1090, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m1161) {
          u64 v_c16 = m1161[1]; u64 v_c6 = m1161[2];
          if (!slog::exists_probe<5,2>(pbranchindex1072, std::array<u64,5>{v_c5, v_c6, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1073, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex1074, std::array<u64,5>{v_c5, v_c6, 0, 0, 0})) return;
          slog::join_probe_old<9,3>($sup9688x139x0x0x0index1075, $sup9688x139x0x0x0delta1091, std::array<u64,9>{v_c6, v_c16, v_c5, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1162) {
            u64 v_c14 = m1162[3]; u64 v_c7 = m1162[4]; u64 v_c15 = m1162[5]; u64 v_c8 = m1162[6]; u64 v_c9 = m1162[7]; u64 v_c10 = m1162[8];
            u64 v_c197 = _prim_lt(db, v_c15, v_c6);
            if (v_c197 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c197) return;
            if (!slog::exists_probe<5,4>(pbranchindex1076, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex1077, std::array<u64,5>{v_c6, v_c5, v_c8, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex1078, std::array<u64,3>{v_c7, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1079, pbranchdelta1092, std::array<u64,5>{v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m1164) {
              u64 v_c18 = m1164[4];
              if (!slog::exists_probe<3,2>(st_diffindex1080, std::array<u64,3>{v_c14, v_c18, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1081, pbranchdelta1093, std::array<u64,5>{v_c16, v_c15, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m1165) {
                u64 v_c19 = m1165[4];
                slog::join_probe_old<3,3>(st_diffindex1082, st_diffdelta1094, std::array<u64,3>{v_c14, v_c18, v_c19}, [&](const std::array<u64,3>& m1166) {
                  if (!slog::exists_probe<3,2>(st_diffindex1083, std::array<u64,3>{v_c7, v_c19, 0})) return;
                  slog::join_probe_old<5,3>(st_bldindex1084, st_blddelta1095, std::array<u64,5>{v_c6, v_c5, v_c8, 0, 0}, [&](const std::array<u64,5>& m1167) {
                    u64 v_c20 = m1167[3]; u64 v_c21 = m1167[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex1085, std::array<u64,2>{v_c21, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1086, std::array<u64,2>{v_c20, 0})) return;
                    slog::join_probe_old<3,2>(st_diffindex1087, st_diffdelta1096, std::array<u64,3>{v_c7, v_c19, 0}, [&](const std::array<u64,3>& m1168) {
                      u64 v_c23 = m1168[2];
                      slog::join_probe_old<2,2>(st_diff_ansindex1088, st_diff_ansdelta1097, std::array<u64,2>{v_c23, v_c21}, [&](const std::array<u64,2>& m1169) {
                        slog::join_probe<2,1>(st_bld_ansindex1089, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m1170) {
                          u64 v_c24 = m1170[1];
                          u64 v_c25 = _prim_band(db, v_c16, v_c6);
                          if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c198 = _prim_lt(db, v_c25, v_c13);
                          if (v_c198 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c198) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c24}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1098* _cont = new ReadTask1098(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1098(db,b), false);
  // (crule (pre) (scan st_hsb_ans __t81zv171 __v1) (body (join st_hsb_ans (0 1) 1 __t81zv171 __v3) (join-old st_hsb (0 1) 1 (0 1) __t81zv171 __t7IWy172) (join-old $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk5UVl1341 (bxor p0 p1)) (eq __t7IWy172 chk5UVl1341)) (head (emit $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t81zv171 __t81zv171 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask1177 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1172;  slog::Index** st_hsbindex1173;  slog::Index** $sup9688x40x0x0x1index1174;  slog::Index** st_hsbdelta1175;  slog::Index** $sup9688x40x0x0x1delta1176;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord1178({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1179 = db->getRelation("$sup9688x40x0x0x2");
      head_index[0] = readrel1179->getIndex(ord1178, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1180({0, 1});
      slog::Relation* readrel1181 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1172 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({0, 1});
      slog::Relation* readrel1183 = db->getRelation("st_hsb");
      st_hsbindex1173 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({0, 1});
      slog::Relation* readrel1185 = db->getRelation("st_hsb");
      st_hsbdelta1175 = readrel1185->getIndex(ord1184, true);
      std::vector<u16> ord1186({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1187 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1174 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1189 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1delta1176 = readrel1189->getIndex(ord1188, true);
  
    }
    ReadTask1177(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c199 = _t[0];
        u64 v_c39 = _t[1];
        slog::join_probe<2,1>(st_hsb_ansindex1172, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1190) {
          u64 v_c67 = m1190[1];
          slog::join_probe_old<2,1>(st_hsbindex1173, st_hsbdelta1175, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1191) {
            u64 v_c200 = m1191[1];
            slog::join_all_old<7>($sup9688x40x0x0x1index1174, $sup9688x40x0x0x1delta1176, [&](const std::array<u64,7>& m1192) {
              u64 v_c176 = m1192[0]; u64 v_c21 = m1192[1]; u64 v_c82 = m1192[2]; u64 v_c60 = m1192[3]; u64 v_c61 = m1192[4]; u64 v_c62 = m1192[5]; u64 v_c63 = m1192[6];
              u64 v_c201 = _prim_bxor(db, v_c60, v_c61);
              if (v_c201 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
              if (v_c200 != v_c201) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c176, v_c21, v_c67, v_c39, v_c82, v_c199, v_c199, v_c60, v_c61, v_c62, v_c63}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1177* _cont = new ReadTask1177(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1177(db,b), false);
}

