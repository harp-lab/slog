
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4a5462bd8cd8940b1e58a782;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_const9899bd1a9f17c17561973172;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdee70e0c1571644b5844be78;
extern u64 v_conste19dc92e0d47b9f7f5bc6441;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_consteea677b485376be09c1a9cc9;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_cd02a570b13bbad42(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan st_diff __t6llH155 __t9bMl154 __t75xj153) (body (join pbranch (0 1 2 3 4) 1 __t75xj153 p m u v) (join pbranch (0 1 2 3 4) 3 __t9bMl154 p m l r)) (head (emit $sup9688x136x0x0x0 (0 1 2 3 4 5 6) __t6llH155 l m p r u v)) set.slog:137 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex0;  slog::Index** pbranchindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord3({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel4 = db->getRelation("$sup9688x136x0x0x0");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord5({0, 1, 2, 3, 4});
      slog::Relation* readrel6 = db->getRelation("pbranch");
      pbranchindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({0, 1, 2, 3, 4});
      slog::Relation* readrel8 = db->getRelation("pbranch");
      pbranchindex1 = readrel8->getIndex(ord7, false);
  
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
        u64 v_c2 = _t[2];
        slog::join_probe<5,1>(pbranchindex0, std::array<u64,5>{v_c2, 0, 0, 0, 0}, [&](const std::array<u64,5>& m9) {
          u64 v_c3 = m9[1]; u64 v_c4 = m9[2]; u64 v_c5 = m9[3]; u64 v_c6 = m9[4];
          slog::join_probe<5,3>(pbranchindex1, std::array<u64,5>{v_c1, v_c3, v_c4, 0, 0}, [&](const std::array<u64,5>& m10) {
            u64 v_c7 = m10[3]; u64 v_c8 = m10[4];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c0, v_c7, v_c4, v_c3, v_c8, v_c5, v_c6}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff", _fires);
  
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
  // (crule (pre (let __tconst9NmC41 const6b86b273ff34fce19d6b804e)) (scan st_union __t2Ywo40 __t4Scw39 __t6Xp338) (body (join pbranch (0 1 2 3 4) 1 __t6Xp338 q n u v) (join pbranch (0 1 2 3 4) 1 __t4Scw39 p m l r) (cmp lt m n) (let __t6HP242 (band p n)) (cmp lt __t6HP242 __tconst9NmC41)) (head (emit $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) __t2Ywo40 u l m n p q r v)) set.slog:115 #f)
  class ReadTask13 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex11;  slog::Index** pbranchindex12;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord14({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel15 = db->getRelation("$sup9688x114x0x0x0");
      head_index[0] = readrel15->getIndex(ord14, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord16({0, 1, 2, 3, 4});
      slog::Relation* readrel17 = db->getRelation("pbranch");
      pbranchindex11 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1, 2, 3, 4});
      slog::Relation* readrel19 = db->getRelation("pbranch");
      pbranchindex12 = readrel19->getIndex(ord18, false);
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<5,1>(pbranchindex11, std::array<u64,5>{v_c12, 0, 0, 0, 0}, [&](const std::array<u64,5>& m20) {
          u64 v_c13 = m20[1]; u64 v_c14 = m20[2]; u64 v_c5 = m20[3]; u64 v_c6 = m20[4];
          slog::join_probe<5,1>(pbranchindex12, std::array<u64,5>{v_c11, 0, 0, 0, 0}, [&](const std::array<u64,5>& m21) {
            u64 v_c3 = m21[1]; u64 v_c4 = m21[2]; u64 v_c7 = m21[3]; u64 v_c8 = m21[4];
            u64 v_c15 = _prim_lt(db, v_c4, v_c14);
            if (v_c15 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c15) return;
            u64 v_c16 = _prim_band(db, v_c3, v_c14);
            if (v_c16 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            u64 v_c17 = _prim_lt(db, v_c16, v_c9);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c17) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c10, v_c5, v_c7, v_c4, v_c14, v_c3, v_c13, v_c8, v_c6}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask13* _cont = new ReadTask13(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask13(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan st_msk __t3nJI327 k m) (body (exists $sup9688x70x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_mem0 (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t3nJI327 p) (exists pbranch (1 2 3 4 0) 2 p m) (join $sup9688x70x0x0x0 (1 3 4 0 2 5) 3 k m p __t6uqp323 l r) (exists st_mem0 (2 0 1) 2 k __t6uqp323) (exists st_mem0 (1 2 0) 2 l k) (join pbranch (1 2 3 4 0) 4 p m l r __t7Uqa322) (join st_mem0 (0 1 2) 3 __t6uqp323 __t7Uqa322 k) (join st_mem0 (1 2 0) 2 l k __t14DN326) (join st_mem0_ans (0 1) 1 __t14DN326 a) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask36 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x70x0x0x0index24;  slog::Index** pbranchindex25;  slog::Index** st_mem0index26;  slog::Index** st_msk_ansindex27;  slog::Index** pbranchindex28;  slog::Index** $sup9688x70x0x0x0index29;  slog::Index** st_mem0index30;  slog::Index** st_mem0index31;  slog::Index** pbranchindex32;  slog::Index** st_mem0index33;  slog::Index** st_mem0index34;  slog::Index** st_mem0_ansindex35;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel38->getIndex(ord37, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord39({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel40 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index24 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 0, 1, 3, 4});
      slog::Relation* readrel42 = db->getRelation("pbranch");
      pbranchindex25 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({2, 0, 1});
      slog::Relation* readrel44 = db->getRelation("st_mem0");
      st_mem0index26 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("st_msk_ans");
      st_msk_ansindex27 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 3, 4, 0});
      slog::Relation* readrel48 = db->getRelation("pbranch");
      pbranchindex28 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel50 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index29 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({2, 0, 1});
      slog::Relation* readrel52 = db->getRelation("st_mem0");
      st_mem0index30 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("st_mem0");
      st_mem0index31 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 3, 4, 0});
      slog::Relation* readrel56 = db->getRelation("pbranch");
      pbranchindex32 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("st_mem0");
      st_mem0index33 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("st_mem0");
      st_mem0index34 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex35 = readrel62->getIndex(ord61, false);
  
    }
    ReadTask36(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x70x0x0x0index24, std::array<u64,6>{v_c20, v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex25, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index26, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex27, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m63) {
          u64 v_c3 = m63[1];
          if (!slog::exists_probe<5,2>(pbranchindex28, std::array<u64,5>{v_c3, v_c4, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x70x0x0x0index29, std::array<u64,6>{v_c20, v_c4, v_c3, 0, 0, 0}, [&](const std::array<u64,6>& m64) {
            u64 v_c21 = m64[3]; u64 v_c7 = m64[4]; u64 v_c8 = m64[5];
            if (!slog::exists_probe<3,2>(st_mem0index30, std::array<u64,3>{v_c20, v_c21, 0})) return;
            if (!slog::exists_probe<3,2>(st_mem0index31, std::array<u64,3>{v_c7, v_c20, 0})) return;
            slog::join_probe<5,4>(pbranchindex32, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m65) {
              u64 v_c22 = m65[4];
              slog::join_probe<3,3>(st_mem0index33, std::array<u64,3>{v_c21, v_c22, v_c20}, [&](const std::array<u64,3>& m66) {
                slog::join_probe<3,2>(st_mem0index34, std::array<u64,3>{v_c7, v_c20, 0}, [&](const std::array<u64,3>& m67) {
                  u64 v_c23 = m67[2];
                  slog::join_probe<2,1>(st_mem0_ansindex35, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m68) {
                    u64 v_c24 = m68[1];
                    u64 v_c25 = _prim_band(db, v_c20, v_c4);
                    if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c26 = _prim_lt(db, v_c25, v_c18);
                    if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c26) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c24}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask36* _cont = new ReadTask36(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask36(db,b), false);
  // (crule (pre) (scan $sup9688x36x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t8nF2228 (bxor p0 p1))) (head (emit-temp temp5IQT1412 __t8nF2228)) set.slog:37 #f)
  class ReadTask70 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5IQT1412");
      outer_rel = db->getRelation("$sup9688x36x0x0x1");
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        u64 v_c32 = _t[5];
        u64 v_c33 = _t[6];
        u64 v_c34 = _prim_bxor(db, v_c30, v_c31);
        if (v_c34 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c34});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask70* _cont = new ReadTask70(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), false);
  // (crule (pre (let __tconst7OE6425 const5feceb66ffc86f38d952786c)) (scan st_diff __t2CPR423 __t2KDy422 t) (body (exists st_mem0 (1 2 0) 1 t) (join st_mem0_ans (1 0) 1 __tconst7OE6425 __t32gs424) (join-old st_mem0 (0 1 2) 2 (0 1 2) __t32gs424 t k) (join pleaf (0 1) 2 __t2KDy422 k)) (head (emit st_diff_ans (0 1) __t2CPR423 __t2KDy422)) set.slog:134 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index71;  slog::Index** st_mem0_ansindex72;  slog::Index** st_mem0index73;  slog::Index** pleafindex74;  slog::Index** st_mem0delta75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("st_diff_ans");
      head_index[0] = readrel78->getIndex(ord77, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("st_mem0");
      st_mem0index71 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 0});
      slog::Relation* readrel82 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex72 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1, 2});
      slog::Relation* readrel84 = db->getRelation("st_mem0");
      st_mem0index73 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2});
      slog::Relation* readrel86 = db->getRelation("st_mem0");
      st_mem0delta75 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("pleaf");
      pleafindex74 = readrel88->getIndex(ord87, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c38 = _t[2];
        if (!slog::exists_probe<3,1>(st_mem0index71, std::array<u64,3>{v_c38, 0, 0})) return;
        slog::join_probe<2,1>(st_mem0_ansindex72, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m89) {
          u64 v_c39 = m89[1];
          slog::join_probe_old<3,2>(st_mem0index73, st_mem0delta75, std::array<u64,3>{v_c39, v_c38, 0}, [&](const std::array<u64,3>& m90) {
            u64 v_c20 = m90[2];
            slog::join_probe<2,2>(pleafindex74, std::array<u64,2>{v_c37, v_c20}, [&](const std::array<u64,2>& m91) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c37}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask76* _cont = new ReadTask76(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask76(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk0Aa91322 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk0Aa91322) (letp chk3piW1323 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk3piW1323) (letp chk5jta1324 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk5jta1324) (letp chk3pO71325 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk3pO71325) (letp chk4FVL1326 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk4FVL1326)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask102 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex92;  slog::Index** $seq_atindex93;  slog::Index** $seq_atindex94;  slog::Index** $seq_atindex95;  slog::Index** $seq_atrindex96;  slog::Index** $seq_atrindex97;  slog::Index** $seq_atrindex98;  slog::Index** st_fromlistindex99;  slog::Index** st_fromlist_ansindex100;  slog::Index** $seq_atrdelta101;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord103({0});
      slog::Relation* readrel104 = db->getRelation("canon");
      head_index[0] = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1, 2});
      slog::Relation* readrel106 = db->getRelation("$seq_atr");
      driver_index = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({1, 0, 2});
      slog::Relation* readrel108 = db->getRelation("$seq_at");
      $seq_atindex92 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0, 2});
      slog::Relation* readrel110 = db->getRelation("$seq_at");
      $seq_atindex93 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0, 2});
      slog::Relation* readrel112 = db->getRelation("$seq_at");
      $seq_atindex94 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 0, 2});
      slog::Relation* readrel114 = db->getRelation("$seq_at");
      $seq_atindex95 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1, 2});
      slog::Relation* readrel116 = db->getRelation("$seq_atr");
      $seq_atrindex96 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({0, 1, 2});
      slog::Relation* readrel118 = db->getRelation("$seq_atr");
      $seq_atrindex97 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1, 2});
      slog::Relation* readrel120 = db->getRelation("$seq_atr");
      $seq_atrindex98 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({0, 1, 2});
      slog::Relation* readrel122 = db->getRelation("$seq_atr");
      $seq_atrdelta101 = readrel122->getIndex(ord121, true);
      std::vector<u16> ord123({1, 0});
      slog::Relation* readrel124 = db->getRelation("st_fromlist");
      st_fromlistindex99 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex100 = readrel126->getIndex(ord125, false);
  
    }
    ReadTask102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_constef2d127de37b942baad06145;
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c44 = v_constd4735e3a265e16eee03f5971;
      u64 v_c45 = v_constd4735e3a265e16eee03f5971;
      u64 v_c46 = v_const2c624232cdd221771294dfbb;
      u64 v_c47 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c48 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c49 = v_constef2d127de37b942baad06145;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_constd4735e3a265e16eee03f5971;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c53 = v_const2c624232cdd221771294dfbb;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c56 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c57 = v_constef2d127de37b942baad06145;
      u64 v_c58 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_constd4735e3a265e16eee03f5971;
      u64 v_c60 = v_constd4735e3a265e16eee03f5971;
      u64 v_c61 = v_const2c624232cdd221771294dfbb;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c61, v_c62, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m127) {
        u64 v_c65 = m127[2];
        if (buckethash(v_c65) != bucket) return;
        slog::join_probe<3,3>($seq_atindex92, std::array<u64,3>{v_c50, v_c49, v_c65}, [&](const std::array<u64,3>& m128) {
          slog::join_probe<3,3>($seq_atindex93, std::array<u64,3>{v_c52, v_c51, v_c65}, [&](const std::array<u64,3>& m129) {
            slog::join_probe<3,3>($seq_atindex94, std::array<u64,3>{v_c54, v_c53, v_c65}, [&](const std::array<u64,3>& m130) {
              slog::join_probe<3,3>($seq_atindex95, std::array<u64,3>{v_c56, v_c55, v_c65}, [&](const std::array<u64,3>& m131) {
                slog::join_probe<3,3>($seq_atrindex96, std::array<u64,3>{v_c57, v_c58, v_c65}, [&](const std::array<u64,3>& m132) {
                  slog::join_probe<3,3>($seq_atrindex97, std::array<u64,3>{v_c59, v_c60, v_c65}, [&](const std::array<u64,3>& m133) {
                    slog::join_probe_old<3,3>($seq_atrindex98, $seq_atrdelta101, std::array<u64,3>{v_c63, v_c64, v_c65}, [&](const std::array<u64,3>& m134) {
                      slog::join_probe<2,1>(st_fromlistindex99, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m135) {
                        u64 v_c66 = m135[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex100, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m136) {
                          u64 v_c8 = m136[1];
                          bool ok137 = true;
                          u64 v_c67 = _prim_aslst(db, v_c65, &ok137);
                          if (!ok137) return;
                          u64 v_c68 = _prim_llen(db, v_c67);
                          if (v_c68 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c40 != v_c68) return;
                          bool ok138 = true;
                          u64 v_c69 = _prim_lref(db, v_c67, v_c41, &ok138);
                          if (!ok138) return;
                          if (v_c42 != v_c69) return;
                          bool ok139 = true;
                          u64 v_c70 = _prim_lref(db, v_c67, v_c43, &ok139);
                          if (!ok139) return;
                          if (v_c44 != v_c70) return;
                          bool ok140 = true;
                          u64 v_c71 = _prim_lref(db, v_c67, v_c45, &ok140);
                          if (!ok140) return;
                          if (v_c46 != v_c71) return;
                          bool ok141 = true;
                          u64 v_c72 = _prim_lref(db, v_c67, v_c47, &ok141);
                          if (!ok141) return;
                          if (v_c48 != v_c72) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
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
        ReadTask102* _cont = new ReadTask102(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask102(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan st_diff __t9ide547 l __t3QFk546) (body (exists $sup9688x139x0x0x0 (1 0 2 3 4 5 6 7 8) 1 l) (join st_diff_ans (0 1) 1 __t9ide547 __v0) (join pbranch (0 1 2 3 4) 1 __t3QFk546 q n u v) (exists st_msk (1 2 0) 1 q) (join $sup9688x139x0x0x0 (3 5 7 8 1 0 2 4 6) 5 n q u v l __d0 m p r) (exists st_msk_ans (1 0) 1 p) (join st_msk (1 2 0) 2 q m __t9Eou545) (join st_msk_ans (0 1) 2 __t9Eou545 p)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask153 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index142;  slog::Index** st_diff_ansindex143;  slog::Index** pbranchindex144;  slog::Index** st_mskindex145;  slog::Index** $sup9688x139x0x0x0index146;  slog::Index** st_msk_ansindex147;  slog::Index** st_mskindex148;  slog::Index** st_msk_ansindex149;
    u32 sid151;  u32 sid150;  u32 sid152;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord154({1, 0, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel155 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index142 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 1});
      slog::Relation* readrel157 = db->getRelation("st_diff_ans");
      st_diff_ansindex143 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 1, 2, 3, 4});
      slog::Relation* readrel159 = db->getRelation("pbranch");
      pbranchindex144 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({1, 2, 0});
      slog::Relation* readrel161 = db->getRelation("st_msk");
      st_mskindex145 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({3, 5, 7, 8, 1, 0, 2, 4, 6});
      slog::Relation* readrel163 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index146 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 0});
      slog::Relation* readrel165 = db->getRelation("st_msk_ans");
      st_msk_ansindex147 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 0});
      slog::Relation* readrel167 = db->getRelation("st_msk");
      st_mskindex148 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1});
      slog::Relation* readrel169 = db->getRelation("st_msk_ans");
      st_msk_ansindex149 = readrel169->getIndex(ord168, false);
      sid151 = db->getRelation("_enum")->getStructId();
      sid150 = db->getRelation("pbranch")->getStructId();
      sid152 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask153(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c74 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c75 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c77 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index142, std::array<u64,9>{v_c7, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex143, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m170) {
          u64 v_c29 = m170[1];
          slog::join_probe<5,1>(pbranchindex144, std::array<u64,5>{v_c77, 0, 0, 0, 0}, [&](const std::array<u64,5>& m171) {
            u64 v_c13 = m171[1]; u64 v_c14 = m171[2]; u64 v_c5 = m171[3]; u64 v_c6 = m171[4];
            if (!slog::exists_probe<3,1>(st_mskindex145, std::array<u64,3>{v_c13, 0, 0})) return;
            slog::join_probe<9,5>($sup9688x139x0x0x0index146, std::array<u64,9>{v_c14, v_c13, v_c5, v_c6, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,9>& m172) {
              u64 v_c27 = m172[5]; u64 v_c4 = m172[6]; u64 v_c3 = m172[7]; u64 v_c8 = m172[8];
              if (!slog::exists_probe<2,1>(st_msk_ansindex147, std::array<u64,2>{v_c3, 0})) return;
              slog::join_probe<3,2>(st_mskindex148, std::array<u64,3>{v_c13, v_c4, 0}, [&](const std::array<u64,3>& m173) {
                u64 v_c78 = m173[2];
                slog::join_probe<2,2>(st_msk_ansindex149, std::array<u64,2>{v_c78, v_c3}, [&](const std::array<u64,2>& m174) {
                  ++_fires;
                  if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid150 || decode_struct_id(v_c8) == sid151 || decode_struct_id(v_c8) == sid152))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c73, v_c74, v_c75, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c4, v_c29, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask153* _cont = new ReadTask153(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask153(db,b), false);
  // (crule (pre (let __trid1hwL968 conste19dc92e0d47b9f7f5bc6441) (let __trel58SM969 constdee70e0c1571644b5844be78) (let __tcol6g6y970 const5feceb66ffc86f38d952786c) (let __trel4G1k971 constdee70e0c1571644b5844be78) (let __tcol9eco972 const6b86b273ff34fce19d6b804e)) (scan $sup9688x72x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid1hwL968 __trel58SM969 __tcol6g6y970 (1 2 3 4 0)) (tycheck k (accept int) __trid1hwL968 __trel4G1k971 __tcol9eco972 (1 2 3 4 0)) (mkstruct st_mem0 (1 2 0) __6GVI967 r k)) set.slog:73 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid176;  u32 sid175;  u32 sid177;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("$sup9688x72x0x0x0");
      sid176 = db->getRelation("_enum")->getStructId();
      sid175 = db->getRelation("pbranch")->getStructId();
      sid177 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_conste19dc92e0d47b9f7f5bc6441;
      u64 v_c80 = v_constdee70e0c1571644b5844be78;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = v_constdee70e0c1571644b5844be78;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c27 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c8 = _t[5];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid175 || decode_struct_id(v_c8) == sid176 || decode_struct_id(v_c8) == sid177))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c79, v_c80, v_c81, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c20)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c79, v_c82, v_c83, v_c20}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c20}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:$sup9688x72x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), false);
  // (crule (pre (let __tconst7zIc377 const5feceb66ffc86f38d952786c)) (scan pbranch __t3NTP375 p m l r) (body (join-old st_del (1 2 0) 1 (1 2 0) __t3NTP375 k __t0BrC376) (let __t8Ehr378 (band k m)) (cmp gt __t8Ehr378 __tconst7zIc377)) (head (emit $sup9688x90x0x0x0 (4 2 3 5 0 1) p l m r __t0BrC376 k)) set.slog:91 #f)
  class ReadTask181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex179;  slog::Index** st_deldelta180;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord182({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel183 = db->getRelation("$sup9688x90x0x0x0");
      head_index[0] = readrel183->getIndex(ord182, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("st_del");
      st_delindex179 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("st_del");
      st_deldelta180 = readrel187->getIndex(ord186, true);
  
    }
    ReadTask181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c85 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_delindex179, st_deldelta180, std::array<u64,3>{v_c85, 0, 0}, [&](const std::array<u64,3>& m188) {
          u64 v_c20 = m188[1]; u64 v_c86 = m188[2];
          u64 v_c87 = _prim_band(db, v_c20, v_c4);
          if (v_c87 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
          u64 v_c88 = _prim_gt(db, v_c87, v_c84);
          if (v_c88 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
          if (!v_c88) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c3, v_c7, v_c4, v_c8, v_c86, v_c20}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask181* _cont = new ReadTask181(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask181(db,b), false);
  // (crule (pre (let __tconst4ng4400 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t26uy402 __t4Y7m401 k) (body (exists st_msk (1 2 0) 1 k) (join $sup9688x69x0x0x0 (0 1 2 3 4 5) 2 __t26uy402 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t4Y7m401) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t7rLj403) (join st_msk_ans (0 1) 1 __t7rLj403 __v0) (neq p __v0)) (head (emit st_mem0_ans (0 1) __t26uy402 __tconst4ng4400)) set.slog:70 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex190;  slog::Index** $sup9688x69x0x0x0index191;  slog::Index** pbranchindex192;  slog::Index** st_mskindex193;  slog::Index** st_msk_ansindex194;  slog::Index** st_mskdelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel198->getIndex(ord197, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("st_msk");
      st_mskindex190 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel202 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0index191 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 3, 4, 0});
      slog::Relation* readrel204 = db->getRelation("pbranch");
      pbranchindex192 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 0});
      slog::Relation* readrel206 = db->getRelation("st_msk");
      st_mskindex193 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("st_msk");
      st_mskdelta195 = readrel208->getIndex(ord207, true);
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("st_msk_ans");
      st_msk_ansindex194 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[2];
        if (!slog::exists_probe<3,1>(st_mskindex190, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x69x0x0x0index191, std::array<u64,6>{v_c90, v_c20, 0, 0, 0, 0}, [&](const std::array<u64,6>& m211) {
          u64 v_c7 = m211[2]; u64 v_c4 = m211[3]; u64 v_c3 = m211[4]; u64 v_c8 = m211[5];
          slog::join_probe<5,5>(pbranchindex192, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, v_c91}, [&](const std::array<u64,5>& m212) {
            slog::join_probe_old<3,2>(st_mskindex193, st_mskdelta195, std::array<u64,3>{v_c20, v_c4, 0}, [&](const std::array<u64,3>& m213) {
              u64 v_c92 = m213[2];
              slog::join_probe<2,1>(st_msk_ansindex194, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m214) {
                u64 v_c29 = m214[1];
                if (v_c3 == v_c29) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c90, v_c89}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask196* _cont = new ReadTask196(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask196(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan $sup9688x40x0x0x0 __t4PzE464 p0 p1 t0 t1) (body (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (exists $sup9688x40x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t4PzE464 p0 p1 t0 t1) (exists st_msk (1 2 0) 1 p0) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 5 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (exists st_hsb_ans (0 1) 1 __t2flT468) (exists st_hsb_ans (0 1) 2 __t2flT468 __v0) (join $sup9688x40x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0 dup2gd61405 dup5ZAM1406 __v1 __v3) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join-old st_msk_ans (0 1) 1 (0 1) __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask235 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex215;  slog::Index** $sup9688x40x0x0x2index216;  slog::Index** st_mskindex217;  slog::Index** $sup9688x40x0x0x1index218;  slog::Index** st_hsb_ansindex219;  slog::Index** st_hsb_ansindex220;  slog::Index** $sup9688x40x0x0x2index221;  slog::Index** st_hsb_ansindex222;  slog::Index** st_hsb_ansindex223;  slog::Index** st_hsb_ansindex224;  slog::Index** st_mskindex225;  slog::Index** st_msk_ansindex226;  slog::Index** st_hsbindex227;  slog::Index** st_joindelta228;  slog::Index** st_hsb_ansdelta229;  slog::Index** st_hsb_ansdelta230;  slog::Index** st_hsb_ansdelta231;  slog::Index** st_mskdelta232;  slog::Index** st_msk_ansdelta233;  slog::Index** st_hsbdelta234;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord236({1, 2, 3, 4, 0});
      slog::Relation* readrel237 = db->getRelation("st_join");
      st_joinindex215 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("st_join");
      st_joindelta228 = readrel239->getIndex(ord238, true);
      std::vector<u16> ord240({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel241 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index216 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("st_msk");
      st_mskindex217 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel245 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index218 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({0, 1});
      slog::Relation* readrel247 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex219 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex220 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel251 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index221 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex222 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta229 = readrel255->getIndex(ord254, true);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex223 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta230 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex224 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta231 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("st_msk");
      st_mskindex225 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("st_msk");
      st_mskdelta232 = readrel267->getIndex(ord266, true);
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("st_msk_ans");
      st_msk_ansindex226 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("st_msk_ans");
      st_msk_ansdelta233 = readrel271->getIndex(ord270, true);
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("st_hsb");
      st_hsbindex227 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 1});
      slog::Relation* readrel275 = db->getRelation("st_hsb");
      st_hsbdelta234 = readrel275->getIndex(ord274, true);
  
    }
    ReadTask235(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c94 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c33 = _t[4];
        slog::join_probe_old<5,5>(st_joinindex215, st_joindelta228, std::array<u64,5>{v_c30, v_c32, v_c31, v_c33, v_c94}, [&](const std::array<u64,5>& m276) {
          if (!slog::exists_probe<11,5>($sup9688x40x0x0x2index216, std::array<u64,11>{v_c94, v_c30, v_c31, v_c32, v_c33, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex217, std::array<u64,3>{v_c30, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x40x0x0x1index218, std::array<u64,7>{v_c94, v_c30, v_c31, v_c32, v_c33, 0, 0}, [&](const std::array<u64,7>& m277) {
            u64 v_c95 = m277[5]; u64 v_c29 = m277[6];
            if (!slog::exists_probe<2,1>(st_hsb_ansindex219, std::array<u64,2>{v_c95, 0})) return;
            if (!slog::exists_probe<2,2>(st_hsb_ansindex220, std::array<u64,2>{v_c95, v_c29})) return;
            slog::join_probe<11,7>($sup9688x40x0x0x2index221, std::array<u64,11>{v_c94, v_c30, v_c31, v_c32, v_c33, v_c95, v_c29, 0, 0, 0, 0}, [&](const std::array<u64,11>& m278) {
              u64 v_c96 = m278[7]; u64 v_c97 = m278[8]; u64 v_c98 = m278[9]; u64 v_c99 = m278[10];
              if (v_c95 != v_c97) return;
              if (v_c95 != v_c96) return;
              slog::join_probe_old<2,2>(st_hsb_ansindex222, st_hsb_ansdelta229, std::array<u64,2>{v_c95, v_c99}, [&](const std::array<u64,2>& m279) {
                slog::join_probe_old<2,2>(st_hsb_ansindex223, st_hsb_ansdelta230, std::array<u64,2>{v_c95, v_c98}, [&](const std::array<u64,2>& m280) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex224, st_hsb_ansdelta231, std::array<u64,2>{v_c95, v_c29}, [&](const std::array<u64,2>& m281) {
                    slog::join_probe_old<3,2>(st_mskindex225, st_mskdelta232, std::array<u64,3>{v_c30, v_c98, 0}, [&](const std::array<u64,3>& m282) {
                      u64 v_c100 = m282[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex226, st_msk_ansdelta233, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m283) {
                        u64 v_c101 = m283[1];
                        u64 v_c102 = _prim_bxor(db, v_c30, v_c31);
                        if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex227, st_hsbdelta234, std::array<u64,2>{v_c95, v_c102}, [&](const std::array<u64,2>& m284) {
                          u64 v_c103 = _prim_band(db, v_c30, v_c29);
                          if (v_c103 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c104 = _prim_gt(db, v_c103, v_c93);
                          if (v_c104 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c104) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c94, v_c101, v_c99, v_c32, v_c33});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c101, v_c99, v_c33, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x0", _fires);
  
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
  // (crule (pre) (scan temp1pqw1409 l n q u v) (body (join pbranch (1 2 3 4 0) 4 q n u v __t9ac335)) (head (mkstruct st_union (1 2 0) __9QWp1019 l __t9ac335)) set.slog:104 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("temp1pqw1409");
      std::vector<u16> ord288({1, 2, 3, 4, 0});
      slog::Relation* readrel289 = db->getRelation("pbranch");
      pbranchindex286 = readrel289->getIndex(ord288, false);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        slog::join_probe<5,4>(pbranchindex286, std::array<u64,5>{v_c13, v_c14, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m290) {
          u64 v_c105 = m290[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c105}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:temp1pqw1409", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __trid4bDq789 const76a4fedc25549f0939d52fb7) (let __trel1o0k790 const26c89ee8ccc4ea998fd1a912) (let __tcol6PPW791 const4e07408562bedb8b60ce05c1)) (scan st_msk __t5gdG368 k m) (body (exists $sup9688x88x0x0x0 (1 3 4 0 2 5) 2 k m) (exists st_del (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t5gdG368 p) (join $sup9688x88x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old st_del (1 2 0) 2 (1 2 0) l k __t8asA369) (join st_del_ans (0 1) 1 __t8asA369 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bDq789 __trel1o0k790 __tcol6PPW791 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __3BTR788 p m __v0 r)) set.slog:89 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index291;  slog::Index** st_delindex292;  slog::Index** st_msk_ansindex293;  slog::Index** $sup9688x88x0x0x0index294;  slog::Index** st_delindex295;  slog::Index** st_del_ansindex296;  slog::Index** st_deldelta297;
    u32 sid299;  u32 sid298;  u32 sid300;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord302({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel303 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index291 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({2, 0, 1});
      slog::Relation* readrel305 = db->getRelation("st_del");
      st_delindex292 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("st_msk_ans");
      st_msk_ansindex293 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel309 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index294 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("st_del");
      st_delindex295 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("st_del");
      st_deldelta297 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("st_del_ans");
      st_del_ansindex296 = readrel315->getIndex(ord314, false);
      sid299 = db->getRelation("_enum")->getStructId();
      sid298 = db->getRelation("pbranch")->getStructId();
      sid300 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c106 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c107 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c108 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c20 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x88x0x0x0index291, std::array<u64,6>{v_c20, v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex292, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex293, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m316) {
          u64 v_c3 = m316[1];
          slog::join_probe<6,3>($sup9688x88x0x0x0index294, std::array<u64,6>{v_c20, v_c4, v_c3, 0, 0, 0}, [&](const std::array<u64,6>& m317) {
            u64 v_c27 = m317[3]; u64 v_c7 = m317[4]; u64 v_c8 = m317[5];
            slog::join_probe_old<3,2>(st_delindex295, st_deldelta297, std::array<u64,3>{v_c7, v_c20, 0}, [&](const std::array<u64,3>& m318) {
              u64 v_c110 = m318[2];
              slog::join_probe<2,1>(st_del_ansindex296, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m319) {
                u64 v_c29 = m319[1];
                ++_fires;
                if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid298 || decode_struct_id(v_c8) == sid299 || decode_struct_id(v_c8) == sid300))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c106, v_c107, v_c108, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c4, v_c29, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_msk", _fires);
  
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
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan pbranch __t8HsZ249 q n u v) (body (exists $sup9688x103x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists st_union (2 0 1) 1 __t8HsZ249) (exists st_msk (1 2 0) 1 q) (join $sup9688x103x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t3N33245 l m p r) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 2 __t8HsZ249 __t3N33245) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 2 l __t8HsZ249) (join $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t3N33245 n q u v __t3q0j248) (exists st_msk (1 2 0) 3 q m __t3q0j248) (exists st_msk_ans (0 1) 2 __t3q0j248 p) (join pbranch (1 2 3 4 0) 4 p m l r __t2RvE244) (join st_union (0 1 2) 3 __t3N33245 __t2RvE244 __t8HsZ249) (join st_msk (1 2 0) 3 q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask339 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x1index320;  slog::Index** st_unionindex321;  slog::Index** st_mskindex322;  slog::Index** $sup9688x103x0x0x0index323;  slog::Index** pbranchindex324;  slog::Index** st_unionindex325;  slog::Index** st_mskindex326;  slog::Index** st_msk_ansindex327;  slog::Index** st_unionindex328;  slog::Index** $sup9688x103x0x0x1index329;  slog::Index** st_mskindex330;  slog::Index** st_msk_ansindex331;  slog::Index** pbranchindex332;  slog::Index** st_unionindex333;  slog::Index** st_mskindex334;  slog::Index** st_msk_ansindex335;  slog::Index** st_unionindex336;  slog::Index** st_union_ansindex337;  slog::Index** st_uniondelta338;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord340({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel341 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index320 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({2, 0, 1});
      slog::Relation* readrel343 = db->getRelation("st_union");
      st_unionindex321 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 0});
      slog::Relation* readrel345 = db->getRelation("st_msk");
      st_mskindex322 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel347 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index323 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 2, 3, 4, 0});
      slog::Relation* readrel349 = db->getRelation("pbranch");
      pbranchindex324 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({2, 0, 1});
      slog::Relation* readrel351 = db->getRelation("st_union");
      st_unionindex325 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 0});
      slog::Relation* readrel353 = db->getRelation("st_msk");
      st_mskindex326 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({1, 0});
      slog::Relation* readrel355 = db->getRelation("st_msk_ans");
      st_msk_ansindex327 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({1, 2, 0});
      slog::Relation* readrel357 = db->getRelation("st_union");
      st_unionindex328 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel359 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index329 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 2, 0});
      slog::Relation* readrel361 = db->getRelation("st_msk");
      st_mskindex330 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({0, 1});
      slog::Relation* readrel363 = db->getRelation("st_msk_ans");
      st_msk_ansindex331 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 3, 4, 0});
      slog::Relation* readrel365 = db->getRelation("pbranch");
      pbranchindex332 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1, 2});
      slog::Relation* readrel367 = db->getRelation("st_union");
      st_unionindex333 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 2, 0});
      slog::Relation* readrel369 = db->getRelation("st_msk");
      st_mskindex334 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({0, 1});
      slog::Relation* readrel371 = db->getRelation("st_msk_ans");
      st_msk_ansindex335 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 0});
      slog::Relation* readrel373 = db->getRelation("st_union");
      st_unionindex336 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("st_union");
      st_uniondelta338 = readrel375->getIndex(ord374, true);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("st_union_ans");
      st_union_ansindex337 = readrel377->getIndex(ord376, false);
  
    }
    ReadTask339(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c112 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x103x0x0x1index320, std::array<u64,10>{v_c14, v_c13, v_c5, v_c6, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex321, std::array<u64,3>{v_c112, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex322, std::array<u64,3>{v_c13, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x103x0x0x0index323, std::array<u64,9>{v_c14, v_c13, v_c5, v_c6, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m378) {
          u64 v_c113 = m378[4]; u64 v_c7 = m378[5]; u64 v_c4 = m378[6]; u64 v_c3 = m378[7]; u64 v_c8 = m378[8];
          u64 v_c114 = _prim_lt(db, v_c14, v_c4);
          if (v_c114 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
          if (!v_c114) return;
          if (!slog::exists_probe<5,4>(pbranchindex324, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex325, std::array<u64,3>{v_c112, v_c113, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex326, std::array<u64,3>{v_c13, v_c4, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex327, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex328, std::array<u64,3>{v_c7, v_c112, 0})) return;
          slog::join_probe<10,9>($sup9688x103x0x0x1index329, std::array<u64,10>{v_c7, v_c4, v_c3, v_c8, v_c113, v_c14, v_c13, v_c5, v_c6, 0}, [&](const std::array<u64,10>& m380) {
            u64 v_c115 = m380[9];
            if (!slog::exists_probe<3,3>(st_mskindex330, std::array<u64,3>{v_c13, v_c4, v_c115})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex331, std::array<u64,2>{v_c115, v_c3})) return;
            slog::join_probe<5,4>(pbranchindex332, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m381) {
              u64 v_c116 = m381[4];
              slog::join_probe<3,3>(st_unionindex333, std::array<u64,3>{v_c113, v_c116, v_c112}, [&](const std::array<u64,3>& m382) {
                slog::join_probe<3,3>(st_mskindex334, std::array<u64,3>{v_c13, v_c4, v_c115}, [&](const std::array<u64,3>& m383) {
                  slog::join_probe<2,2>(st_msk_ansindex335, std::array<u64,2>{v_c115, v_c3}, [&](const std::array<u64,2>& m384) {
                    slog::join_probe_old<3,2>(st_unionindex336, st_uniondelta338, std::array<u64,3>{v_c7, v_c112, 0}, [&](const std::array<u64,3>& m385) {
                      u64 v_c117 = m385[2];
                      slog::join_probe<2,1>(st_union_ansindex337, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m386) {
                        u64 v_c29 = m386[1];
                        u64 v_c118 = _prim_band(db, v_c13, v_c4);
                        if (v_c118 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c119 = _prim_lt(db, v_c118, v_c111);
                        if (v_c119 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c119) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c113, v_c29, v_c4, v_c3, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c4, v_c29, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask339* _cont = new ReadTask339(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask339(db,b), false);
  // (crule (pre) (scan pbranch __t7NAj523 p m l r) (body (join st_union (1 2 0) 1 __t7NAj523 __t6acj524 __t5NEh522) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6acj524 q n u v) (cmp lt n m)) (head (emit $sup9688x110x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t5NEh522 l n p r __t7NAj523 __t6acj524 u v)) set.slog:111 #f)
  class ReadTask391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex388;  slog::Index** pbranchindex389;  slog::Index** pbranchdelta390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord392({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel393 = db->getRelation("$sup9688x110x0x0x0");
      head_index[0] = readrel393->getIndex(ord392, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("st_union");
      st_unionindex388 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2, 3, 4});
      slog::Relation* readrel397 = db->getRelation("pbranch");
      pbranchindex389 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0, 1, 2, 3, 4});
      slog::Relation* readrel399 = db->getRelation("pbranch");
      pbranchdelta390 = readrel399->getIndex(ord398, true);
  
    }
    ReadTask391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c120 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<3,1>(st_unionindex388, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m400) {
          u64 v_c121 = m400[1]; u64 v_c122 = m400[2];
          slog::join_probe_old<5,1>(pbranchindex389, pbranchdelta390, std::array<u64,5>{v_c121, 0, 0, 0, 0}, [&](const std::array<u64,5>& m401) {
            u64 v_c13 = m401[1]; u64 v_c14 = m401[2]; u64 v_c5 = m401[3]; u64 v_c6 = m401[4];
            u64 v_c123 = _prim_lt(db, v_c14, v_c4);
            if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
            if (!v_c123) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c4, v_c13, v_c122, v_c7, v_c14, v_c3, v_c8, v_c120, v_c121, v_c5, v_c6}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask391* _cont = new ReadTask391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask391(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan st_diff __t4u9h108 __t6qKy107 u) (body (exists st_diff (1 2 0) 1 __t6qKy107) (exists pbranch (3 0 1 2 4) 1 u) (exists $sup9688x148x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (join st_diff_ans (0 1) 1 __t4u9h108 res) (join st_diff (1 2 0) 1 __t6qKy107 __t6SZQ102 __t5Ek2104) (exists $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t5Ek2104 u) (join pbranch (3 0 1 2 4) 2 u __t6SZQ102 q n v) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x148x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t5Ek2104 l m p r) (cmp lt m n) (join pbranch (1 2 3 4 0) 5 p m l r __t6qKy107) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join st_msk_ans (0 1) 2 __t3oZy109 q) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask417 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex403;  slog::Index** pbranchindex404;  slog::Index** $sup9688x148x0x0x0index405;  slog::Index** st_diff_ansindex406;  slog::Index** st_diffindex407;  slog::Index** $sup9688x148x0x0x0index408;  slog::Index** pbranchindex409;  slog::Index** st_mskindex410;  slog::Index** st_msk_ansindex411;  slog::Index** $sup9688x148x0x0x0index412;  slog::Index** pbranchindex413;  slog::Index** st_mskindex414;  slog::Index** st_msk_ansindex415;  slog::Index** st_mskdelta416;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord418({0, 1});
      slog::Relation* readrel419 = db->getRelation("st_diff_ans");
      head_index[0] = readrel419->getIndex(ord418, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("st_diff");
      st_diffindex403 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({3, 0, 1, 2, 4});
      slog::Relation* readrel423 = db->getRelation("pbranch");
      pbranchindex404 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel425 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index405 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("st_diff_ans");
      st_diff_ansindex406 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 2, 0});
      slog::Relation* readrel429 = db->getRelation("st_diff");
      st_diffindex407 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel431 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index408 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({3, 0, 1, 2, 4});
      slog::Relation* readrel433 = db->getRelation("pbranch");
      pbranchindex409 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({2, 0, 1});
      slog::Relation* readrel435 = db->getRelation("st_msk");
      st_mskindex410 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 0});
      slog::Relation* readrel437 = db->getRelation("st_msk_ans");
      st_msk_ansindex411 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel439 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index412 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 3, 4, 0});
      slog::Relation* readrel441 = db->getRelation("pbranch");
      pbranchindex413 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({1, 2, 0});
      slog::Relation* readrel443 = db->getRelation("st_msk");
      st_mskindex414 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 2, 0});
      slog::Relation* readrel445 = db->getRelation("st_msk");
      st_mskdelta416 = readrel445->getIndex(ord444, true);
      std::vector<u16> ord446({0, 1});
      slog::Relation* readrel447 = db->getRelation("st_msk_ans");
      st_msk_ansindex415 = readrel447->getIndex(ord446, false);
  
    }
    ReadTask417(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(st_diffindex403, std::array<u64,3>{v_c126, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex404, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x148x0x0x0index405, std::array<u64,9>{v_c5, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex406, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m448) {
          u64 v_c127 = m448[1];
          slog::join_probe<3,1>(st_diffindex407, std::array<u64,3>{v_c126, 0, 0}, [&](const std::array<u64,3>& m449) {
            u64 v_c128 = m449[1]; u64 v_c129 = m449[2];
            if (!slog::exists_probe<9,2>($sup9688x148x0x0x0index408, std::array<u64,9>{v_c129, v_c5, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex409, std::array<u64,5>{v_c5, v_c128, 0, 0, 0}, [&](const std::array<u64,5>& m450) {
              u64 v_c13 = m450[2]; u64 v_c14 = m450[3]; u64 v_c6 = m450[4];
              if (!slog::exists_probe<3,1>(st_mskindex410, std::array<u64,3>{v_c14, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex411, std::array<u64,2>{v_c13, 0})) return;
              slog::join_probe<9,5>($sup9688x148x0x0x0index412, std::array<u64,9>{v_c13, v_c14, v_c5, v_c6, v_c129, 0, 0, 0, 0}, [&](const std::array<u64,9>& m451) {
                u64 v_c7 = m451[5]; u64 v_c4 = m451[6]; u64 v_c3 = m451[7]; u64 v_c8 = m451[8];
                u64 v_c130 = _prim_lt(db, v_c4, v_c14);
                if (v_c130 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                if (!v_c130) return;
                slog::join_probe<5,5>(pbranchindex413, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, v_c126}, [&](const std::array<u64,5>& m453) {
                  slog::join_probe_old<3,2>(st_mskindex414, st_mskdelta416, std::array<u64,3>{v_c3, v_c14, 0}, [&](const std::array<u64,3>& m454) {
                    u64 v_c131 = m454[2];
                    slog::join_probe<2,2>(st_msk_ansindex415, std::array<u64,2>{v_c131, v_c13}, [&](const std::array<u64,2>& m455) {
                      u64 v_c132 = _prim_band(db, v_c3, v_c14);
                      if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c133 = _prim_lt(db, v_c132, v_c124);
                      if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c133) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c127}, std::array<u16,2>{0, 1});
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
        ReadTask417* _cont = new ReadTask417(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask417(db,b), false);
  // (crule (pre) (scan st_union __t8WQ2213 s __t6Nl9212) (body (join pleaf (0 1) 1 __t6Nl9212 k)) (head (mkstruct st_ins (1 2 0) __0IHY906 s k)) set.slog:99 #f)
  class ReadTask458 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex457;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord459({0, 1});
      slog::Relation* readrel460 = db->getRelation("pleaf");
      pleafindex457 = readrel460->getIndex(ord459, false);
  
    }
    ReadTask458(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c134 = _t[0];
        u64 v_c135 = _t[1];
        u64 v_c136 = _t[2];
        slog::join_probe<2,1>(pleafindex457, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m461) {
          u64 v_c20 = m461[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c135, v_c20}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask458* _cont = new ReadTask458(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask458(db,b), false);
  // (crule (pre (let __trid88IQ729 const4a5462bd8cd8940b1e58a782) (let __trel2qUP730 const9899bd1a9f17c17561973172) (let __tcol3IGp731 const5feceb66ffc86f38d952786c) (let __trel2u0q732 const9899bd1a9f17c17561973172) (let __tcol6uH5733 const6b86b273ff34fce19d6b804e) (let __trel0wsQ734 const9899bd1a9f17c17561973172) (let __tcol7iCh735 constd4735e3a265e16eee03f5971) (let __trel0GDf736 const9899bd1a9f17c17561973172) (let __tcol3EwP737 const4e07408562bedb8b60ce05c1)) (scan $sup9688x120x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid88IQ729 __trel2qUP730 __tcol3IGp731 (1 2 3 4 0)) (tycheck s (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid88IQ729 __trel2u0q732 __tcol6uH5733 (1 2 3 4 0)) (tycheck q (accept int) __trid88IQ729 __trel0wsQ734 __tcol7iCh735 (1 2 3 4 0)) (tycheck t (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid88IQ729 __trel0GDf736 __tcol3EwP737 (1 2 3 4 0)) (mkstruct st_join (1 2 3 4 0) __1M0b728 p s q t)) set.slog:121 #f)
  class ReadTask465 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid463;  u32 sid462;  u32 sid464;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("st_join");
      outer_rel = db->getRelation("$sup9688x120x0x0x0");
      sid463 = db->getRelation("_enum")->getStructId();
      sid462 = db->getRelation("pbranch")->getStructId();
      sid464 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_const4a5462bd8cd8940b1e58a782;
      u64 v_c138 = v_const9899bd1a9f17c17561973172;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const9899bd1a9f17c17561973172;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const9899bd1a9f17c17561973172;
      u64 v_c143 = v_constd4735e3a265e16eee03f5971;
      u64 v_c144 = v_const9899bd1a9f17c17561973172;
      u64 v_c145 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c27 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c13 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c135 = _t[7];
        u64 v_c38 = _t[8];
        u64 v_c5 = _t[9];
        u64 v_c6 = _t[10];
        ++_fires;
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c137, v_c138, v_c139, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c135) && (decode_struct_id(v_c135) == sid462 || decode_struct_id(v_c135) == sid463 || decode_struct_id(v_c135) == sid464))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c137, v_c140, v_c141, v_c135}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c13)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c137, v_c142, v_c143, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c38) && (decode_struct_id(v_c38) == sid462 || decode_struct_id(v_c38) == sid463 || decode_struct_id(v_c38) == sid464))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c137, v_c144, v_c145, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c3, v_c135, v_c13, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:$sup9688x120x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask465* _cont = new ReadTask465(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask465(db,b), false);
  // (crule (pre) (scan st_msk __t0CrA568 k m) (body (exists $sup9688x87x0x0x0 (1 3 0 2 4 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_del (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t0CrA568 __v0) (join $sup9688x87x0x0x0 (1 3 0 2 4 5) 2 k m __t3SFe567 l p r) (neq p __v0) (exists st_del (0 2 1) 2 __t3SFe567 k) (join pbranch (1 2 3 4 0) 4 p m l r __t5rDd566) (join st_del (0 2 1) 3 __t3SFe567 k __t5rDd566)) (head (emit st_del_ans (0 1) __t3SFe567 __t5rDd566)) set.slog:88 #f)
  class ReadTask474 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x87x0x0x0index466;  slog::Index** pbranchindex467;  slog::Index** st_delindex468;  slog::Index** st_msk_ansindex469;  slog::Index** $sup9688x87x0x0x0index470;  slog::Index** st_delindex471;  slog::Index** pbranchindex472;  slog::Index** st_delindex473;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("st_del_ans");
      head_index[0] = readrel476->getIndex(ord475, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord477({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel478 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0index466 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({2, 0, 1, 3, 4});
      slog::Relation* readrel480 = db->getRelation("pbranch");
      pbranchindex467 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({2, 0, 1});
      slog::Relation* readrel482 = db->getRelation("st_del");
      st_delindex468 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({0, 1});
      slog::Relation* readrel484 = db->getRelation("st_msk_ans");
      st_msk_ansindex469 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel486 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0index470 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({0, 2, 1});
      slog::Relation* readrel488 = db->getRelation("st_del");
      st_delindex471 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 2, 3, 4, 0});
      slog::Relation* readrel490 = db->getRelation("pbranch");
      pbranchindex472 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 2, 1});
      slog::Relation* readrel492 = db->getRelation("st_del");
      st_delindex473 = readrel492->getIndex(ord491, false);
  
    }
    ReadTask474(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x87x0x0x0index466, std::array<u64,6>{v_c20, v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex467, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex468, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex469, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m493) {
          u64 v_c29 = m493[1];
          slog::join_probe<6,2>($sup9688x87x0x0x0index470, std::array<u64,6>{v_c20, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,6>& m494) {
            u64 v_c147 = m494[2]; u64 v_c7 = m494[3]; u64 v_c3 = m494[4]; u64 v_c8 = m494[5];
            if (v_c3 == v_c29) return;
            if (!slog::exists_probe<3,2>(st_delindex471, std::array<u64,3>{v_c147, v_c20, 0})) return;
            slog::join_probe<5,4>(pbranchindex472, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m495) {
              u64 v_c148 = m495[4];
              slog::join_probe<3,3>(st_delindex473, std::array<u64,3>{v_c147, v_c20, v_c148}, [&](const std::array<u64,3>& m496) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c147, v_c148}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask474* _cont = new ReadTask474(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask474(db,b), false);
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst9HiA300 __t8YZs301 __v0) (body (exists st_ins (2 0 1) 1 __tconst87Bp297) (exists st_ins_ans (1 0) 1 __v0) (exists st_ins_ans (0 1) 1 __t8YZs301) (exists st_ins (2 0 1) 1 __tconst4xiW302) (join _enum (1 0) 1 __tconst80a51002 __t1S8l298) (join st_ins (1 2 0) 2 __t1S8l298 __tconst87Bp297 __t3icK299) (join st_ins_ans (0 1) 2 __t3icK299 __v0) (join st_ins_ans (0 1) 1 __t8YZs301 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4xiW302 __t43hI303) (join st_ins_ans (0 1) 1 __t43hI303 __v2)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask508 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex497;  slog::Index** st_ins_ansindex498;  slog::Index** st_ins_ansindex499;  slog::Index** st_insindex500;  slog::Index** _enumindex501;  slog::Index** st_insindex502;  slog::Index** st_ins_ansindex503;  slog::Index** st_ins_ansindex504;  slog::Index** st_insindex505;  slog::Index** st_ins_ansindex506;  slog::Index** st_insdelta507;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord509({2, 0, 1});
      slog::Relation* readrel510 = db->getRelation("st_ins");
      driver_index = readrel510->getIndex(ord509, true);
      std::vector<u16> ord511({2, 0, 1});
      slog::Relation* readrel512 = db->getRelation("st_ins");
      st_insindex497 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 0});
      slog::Relation* readrel514 = db->getRelation("st_ins_ans");
      st_ins_ansindex498 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("st_ins_ans");
      st_ins_ansindex499 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({2, 0, 1});
      slog::Relation* readrel518 = db->getRelation("st_ins");
      st_insindex500 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 0});
      slog::Relation* readrel520 = db->getRelation("_enum");
      _enumindex501 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 2, 0});
      slog::Relation* readrel522 = db->getRelation("st_ins");
      st_insindex502 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1});
      slog::Relation* readrel524 = db->getRelation("st_ins_ans");
      st_ins_ansindex503 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({0, 1});
      slog::Relation* readrel526 = db->getRelation("st_ins_ans");
      st_ins_ansindex504 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 0});
      slog::Relation* readrel528 = db->getRelation("st_ins");
      st_insindex505 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 0});
      slog::Relation* readrel530 = db->getRelation("st_ins");
      st_insdelta507 = readrel530->getIndex(ord529, true);
      std::vector<u16> ord531({0, 1});
      slog::Relation* readrel532 = db->getRelation("st_ins_ans");
      st_ins_ansindex506 = readrel532->getIndex(ord531, false);
  
    }
    ReadTask508(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const2c624232cdd221771294dfbb;
      u64 v_c152 = v_constd4735e3a265e16eee03f5971;
      u64 v_c153 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c151, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m533) {
        u64 v_c154 = m533[1];
        u64 v_c29 = m533[2];
        if (buckethash(v_c154) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex497, std::array<u64,3>{v_c150, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex498, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex499, std::array<u64,2>{v_c154, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex500, std::array<u64,3>{v_c152, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex501, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m534) {
          u64 v_c155 = m534[1];
          slog::join_probe<3,2>(st_insindex502, std::array<u64,3>{v_c155, v_c150, 0}, [&](const std::array<u64,3>& m535) {
            u64 v_c156 = m535[2];
            slog::join_probe<2,2>(st_ins_ansindex503, std::array<u64,2>{v_c156, v_c29}, [&](const std::array<u64,2>& m536) {
              slog::join_probe<2,1>(st_ins_ansindex504, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m537) {
                u64 v_c98 = m537[1];
                slog::join_probe_old<3,2>(st_insindex505, st_insdelta507, std::array<u64,3>{v_c98, v_c152, 0}, [&](const std::array<u64,3>& m538) {
                  u64 v_c157 = m538[2];
                  slog::join_probe<2,1>(st_ins_ansindex506, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m539) {
                    u64 v_c101 = m539[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c101, v_c153}, std::array<u16,3>{1, 2, 0});
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
        ReadTask508* _cont = new ReadTask508(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask508(db,b), false);
  // (crule (pre (let __trid4Efs722 const1e44311dd5d36c3a7dc21dfa) (let __trel1LPU723 consteea677b485376be09c1a9cc9) (let __tcol0Dqz724 const5feceb66ffc86f38d952786c) (let __trel6DFc725 consteea677b485376be09c1a9cc9) (let __tcol8NDi726 const6b86b273ff34fce19d6b804e)) (scan $sup9688x90x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4Efs722 __trel1LPU723 __tcol0Dqz724 (1 2 3 4 0)) (tycheck k (accept int) __trid4Efs722 __trel6DFc725 __tcol8NDi726 (1 2 3 4 0)) (mkstruct st_del (1 2 0) __0swg721 r k)) set.slog:91 #f)
  class ReadTask543 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid541;  u32 sid540;  u32 sid542;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_del");
      outer_rel = db->getRelation("$sup9688x90x0x0x0");
      sid541 = db->getRelation("_enum")->getStructId();
      sid540 = db->getRelation("pbranch")->getStructId();
      sid542 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask543(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c158 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c159 = v_consteea677b485376be09c1a9cc9;
      u64 v_c160 = v_const5feceb66ffc86f38d952786c;
      u64 v_c161 = v_consteea677b485376be09c1a9cc9;
      u64 v_c162 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c27 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c8 = _t[5];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid540 || decode_struct_id(v_c8) == sid541 || decode_struct_id(v_c8) == sid542))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c158, v_c159, v_c160, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c20)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c158, v_c161, v_c162, v_c20}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c20}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:$sup9688x90x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask543* _cont = new ReadTask543(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask543(db,b), false);
  // (crule (pre (let __tconst5jMg913 conste3776bfed7f405de8017ecfa) (let __tconst0zHM198 const2c624232cdd221771294dfbb)) (scan canon s) (body (exists st_ins (2 0 1) 1 __tconst0zHM198) (join _enum (1 0) 1 __tconst5jMg913 __t9gYW199) (join-old st_ins (1 2 0) 2 (1 2 0) __t9gYW199 __tconst0zHM198 __t1mgk200) (join-old st_ins_ans (0 1) 1 (0 1) __t1mgk200 __v0)) (head (emit $sup97714x23x0x0x1 (1 0 2) __v0 __t1mgk200 s)) st_basic.slog:24 #f)
  class ReadTask550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex544;  slog::Index** _enumindex545;  slog::Index** st_insindex546;  slog::Index** st_ins_ansindex547;  slog::Index** st_insdelta548;  slog::Index** st_ins_ansdelta549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord551({1, 0, 2});
      slog::Relation* readrel552 = db->getRelation("$sup97714x23x0x0x1");
      head_index[0] = readrel552->getIndex(ord551, false);
      outer_rel = db->getRelation("canon");
      std::vector<u16> ord553({2, 0, 1});
      slog::Relation* readrel554 = db->getRelation("st_ins");
      st_insindex544 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 0});
      slog::Relation* readrel556 = db->getRelation("_enum");
      _enumindex545 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({1, 2, 0});
      slog::Relation* readrel558 = db->getRelation("st_ins");
      st_insindex546 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 2, 0});
      slog::Relation* readrel560 = db->getRelation("st_ins");
      st_insdelta548 = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("st_ins_ans");
      st_ins_ansindex547 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({0, 1});
      slog::Relation* readrel564 = db->getRelation("st_ins_ans");
      st_ins_ansdelta549 = readrel564->getIndex(ord563, true);
  
    }
    ReadTask550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c164 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c135 = _t[0];
        if (!slog::exists_probe<3,1>(st_insindex544, std::array<u64,3>{v_c164, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex545, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m565) {
          u64 v_c165 = m565[1];
          slog::join_probe_old<3,2>(st_insindex546, st_insdelta548, std::array<u64,3>{v_c165, v_c164, 0}, [&](const std::array<u64,3>& m566) {
            u64 v_c166 = m566[2];
            slog::join_probe_old<2,1>(st_ins_ansindex547, st_ins_ansdelta549, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m567) {
              u64 v_c29 = m567[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c29, v_c166, v_c135}, std::array<u16,3>{1, 0, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:canon", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre4OGJ1255 __errf4tyb1256 __errf3o8Z1257 __errf7O6T1258 __errf1PUr1259) (body) (head (emit error (0) __erre4OGJ1255)) <internal>:1 #f)
  class ReadTask568 : public slog::Task
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
      std::vector<u16> ord569({0});
      slog::Relation* readrel570 = db->getRelation("error");
      head_index[0] = readrel570->getIndex(ord569, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask568(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c167 = _t[0];
        u64 v_c168 = _t[1];
        u64 v_c169 = _t[2];
        u64 v_c170 = _t[3];
        u64 v_c171 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c167}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask568* _cont = new ReadTask568(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask568(db,b), false);
  // (crule (pre (let __tconst3inB738 conste3776bfed7f405de8017ecfa) (let __tconst4Wut540 const6b86b273ff34fce19d6b804e) (let __tconst5bud543 const2c624232cdd221771294dfbb) (let __tconst4ddf539 constd4735e3a265e16eee03f5971)) (probe st_ins (2 0 1) 1 __tconst4Wut540 __t7kvj542 __t86kg541) (body (join _enum (0 1) 2 __t86kg541 __tconst3inB738) (exists st_ins (2 0 1) 1 __tconst5bud543) (join st_ins_ans (0 1) 1 __t7kvj542 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst5bud543 __t19Ry544) (join st_ins_ans (0 1) 1 __t19Ry544 __v1)) (head (mkstruct st_ins (1 2 0) __8Yai739 __v1 __tconst4ddf539)) st_basic.slog:15 #f)
  class ReadTask577 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex571;  slog::Index** st_insindex572;  slog::Index** st_ins_ansindex573;  slog::Index** st_insindex574;  slog::Index** st_ins_ansindex575;  slog::Index** st_insdelta576;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord578({2, 0, 1});
      slog::Relation* readrel579 = db->getRelation("st_ins");
      driver_index = readrel579->getIndex(ord578, true);
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("_enum");
      _enumindex571 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({2, 0, 1});
      slog::Relation* readrel583 = db->getRelation("st_ins");
      st_insindex572 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("st_ins_ans");
      st_ins_ansindex573 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({1, 2, 0});
      slog::Relation* readrel587 = db->getRelation("st_ins");
      st_insindex574 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 2, 0});
      slog::Relation* readrel589 = db->getRelation("st_ins");
      st_insdelta576 = readrel589->getIndex(ord588, true);
      std::vector<u16> ord590({0, 1});
      slog::Relation* readrel591 = db->getRelation("st_ins_ans");
      st_ins_ansindex575 = readrel591->getIndex(ord590, false);
  
    }
    ReadTask577(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c172 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c173 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c174 = v_const2c624232cdd221771294dfbb;
      u64 v_c175 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c173, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m592) {
        u64 v_c176 = m592[1];
        u64 v_c177 = m592[2];
        if (buckethash(v_c176) != bucket) return;
        slog::join_probe<2,2>(_enumindex571, std::array<u64,2>{v_c177, v_c172}, [&](const std::array<u64,2>& m593) {
          if (!slog::exists_probe<3,1>(st_insindex572, std::array<u64,3>{v_c174, 0, 0})) return;
          slog::join_probe<2,1>(st_ins_ansindex573, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m594) {
            u64 v_c29 = m594[1];
            slog::join_probe_old<3,2>(st_insindex574, st_insdelta576, std::array<u64,3>{v_c29, v_c174, 0}, [&](const std::array<u64,3>& m595) {
              u64 v_c178 = m595[2];
              slog::join_probe<2,1>(st_ins_ansindex575, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m596) {
                u64 v_c98 = m596[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c98, v_c175}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask577* _cont = new ReadTask577(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask577(db,b), false);
  // (crule (pre) (scan temp4rmF1269 l m p r v) (body (join pbranch (1 2 3 4 0) 4 p m l r __t1NYA370)) (head (mkstruct st_diff (1 2 0) __7AVX888 __t1NYA370 v)) set.slog:152 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex597;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff");
      outer_rel = db->getRelation("temp4rmF1269");
      std::vector<u16> ord599({1, 2, 3, 4, 0});
      slog::Relation* readrel600 = db->getRelation("pbranch");
      pbranchindex597 = readrel600->getIndex(ord599, false);
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c6 = _t[4];
        slog::join_probe<5,4>(pbranchindex597, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m601) {
          u64 v_c179 = m601[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c179, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:temp4rmF1269", _fires);
  
      if (!_done)
      {
        ReadTask598* _cont = new ReadTask598(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), false);
  // (crule (pre (let _00024sqc374s650 const6b86b273ff34fce19d6b804e) (let _00024sqc70tB651 const5feceb66ffc86f38d952786c) (let _00024sqc9HvG652 const6b86b273ff34fce19d6b804e) (let _00024sqc2OSe653 const5feceb66ffc86f38d952786c) (let _00024sqo65nP658 const5feceb66ffc86f38d952786c)) (scan st_fromlist_ans __t6xe073 __v0) (body (exists st_ins (1 2 0) 1 __v0) (exists $seq_at (1 0 2) 1 _00024sqo65nP658) (join st_fromlist (0 1) 1 __t6xe073 xs) (exists $sup9688x168x0x0x0 (3 0 1 2) 1 xs) (join-old st_ins (1 2 0) 1 (1 2 0) __v0 x __t8MgF74) (exists $sup9688x168x0x0x0 (2 3 0 1) 2 x xs) (exists st_ins_ans (0 1) 1 __t8MgF74) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo65nP658 x _00024seq0) (exists st_fromlist (1 0) 1 _00024seq0) (join $sup9688x168x0x0x0 (2 3 0 1) 3 x xs _00024seq0 __t9UzC72) (join st_fromlist (0 1) 2 __t9UzC72 _00024seq0) (join-old st_ins_ans (0 1) 1 (0 1) __t8MgF74 __v1) (letp _00024sql5p7m648 (aslst _00024seq0)) (let _00024sqn1lS2649 (llen _00024sql5p7m648)) (cmp ge _00024sqn1lS2649 _00024sqc374s650) (letp chk0q4Z1282 (lref _00024sql5p7m648 _00024sqc70tB651)) (eq x chk0q4Z1282) (let _00024sqp836n654 (_0002d _00024sqn1lS2649 _00024sqc2OSe653)) (let chk6AhU1283 (lslice _00024sql5p7m648 _00024sqc9HvG652 _00024sqp836n654)) (eq xs chk6AhU1283)) (head (emit st_fromlist_ans (0 1) __t9UzC72 __v1)) set.slog:169 #f)
  class ReadTask617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex602;  slog::Index** $seq_atindex603;  slog::Index** st_fromlistindex604;  slog::Index** $sup9688x168x0x0x0index605;  slog::Index** st_insindex606;  slog::Index** $sup9688x168x0x0x0index607;  slog::Index** st_ins_ansindex608;  slog::Index** $seq_atindex609;  slog::Index** st_fromlistindex610;  slog::Index** $sup9688x168x0x0x0index611;  slog::Index** st_fromlistindex612;  slog::Index** st_ins_ansindex613;  slog::Index** st_insdelta614;  slog::Index** $seq_atdelta615;  slog::Index** st_ins_ansdelta616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("st_fromlist_ans");
      head_index[0] = readrel619->getIndex(ord618, false);
      outer_rel = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("st_ins");
      st_insindex602 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0, 2});
      slog::Relation* readrel623 = db->getRelation("$seq_at");
      $seq_atindex603 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({0, 1});
      slog::Relation* readrel625 = db->getRelation("st_fromlist");
      st_fromlistindex604 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({3, 0, 1, 2});
      slog::Relation* readrel627 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index605 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("st_ins");
      st_insindex606 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("st_ins");
      st_insdelta614 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({2, 3, 0, 1});
      slog::Relation* readrel633 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index607 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("st_ins_ans");
      st_ins_ansindex608 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 0, 2});
      slog::Relation* readrel637 = db->getRelation("$seq_at");
      $seq_atindex609 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0, 2});
      slog::Relation* readrel639 = db->getRelation("$seq_at");
      $seq_atdelta615 = readrel639->getIndex(ord638, true);
      std::vector<u16> ord640({1, 0});
      slog::Relation* readrel641 = db->getRelation("st_fromlist");
      st_fromlistindex610 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({2, 3, 0, 1});
      slog::Relation* readrel643 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index611 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("st_fromlist");
      st_fromlistindex612 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("st_ins_ans");
      st_ins_ansindex613 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("st_ins_ans");
      st_ins_ansdelta616 = readrel649->getIndex(ord648, true);
  
    }
    ReadTask617(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c181 = v_const5feceb66ffc86f38d952786c;
      u64 v_c182 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
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
        u64 v_c29 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex602, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex603, std::array<u64,3>{v_c184, 0, 0})) return;
        slog::join_probe<2,1>(st_fromlistindex604, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m650) {
          u64 v_c186 = m650[1];
          if (!slog::exists_probe<4,1>($sup9688x168x0x0x0index605, std::array<u64,4>{v_c186, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_insindex606, st_insdelta614, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m651) {
            u64 v_c187 = m651[1]; u64 v_c188 = m651[2];
            if (!slog::exists_probe<4,2>($sup9688x168x0x0x0index607, std::array<u64,4>{v_c187, v_c186, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_ins_ansindex608, std::array<u64,2>{v_c188, 0})) return;
            slog::join_probe_old<3,2>($seq_atindex609, $seq_atdelta615, std::array<u64,3>{v_c184, v_c187, 0}, [&](const std::array<u64,3>& m652) {
              u64 v_c65 = m652[2];
              if (!slog::exists_probe<2,1>(st_fromlistindex610, std::array<u64,2>{v_c65, 0})) return;
              slog::join_probe<4,3>($sup9688x168x0x0x0index611, std::array<u64,4>{v_c187, v_c186, v_c65, 0}, [&](const std::array<u64,4>& m653) {
                u64 v_c189 = m653[3];
                slog::join_probe<2,2>(st_fromlistindex612, std::array<u64,2>{v_c189, v_c65}, [&](const std::array<u64,2>& m654) {
                  slog::join_probe_old<2,1>(st_ins_ansindex613, st_ins_ansdelta616, std::array<u64,2>{v_c188, 0}, [&](const std::array<u64,2>& m655) {
                    u64 v_c98 = m655[1];
                    bool ok656 = true;
                    u64 v_c190 = _prim_aslst(db, v_c65, &ok656);
                    if (!ok656) return;
                    u64 v_c191 = _prim_llen(db, v_c190);
                    if (v_c191 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
                    u64 v_c192 = _prim_ge(db, v_c191, v_c180);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
                    if (!v_c192) return;
                    bool ok658 = true;
                    u64 v_c193 = _prim_lref(db, v_c190, v_c181, &ok658);
                    if (!ok658) return;
                    if (v_c187 != v_c193) return;
                    u64 v_c194 = _prim__0002d(db, v_c191, v_c183);
                    if (v_c194 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
                    u64 v_c195 = _prim_lslice(db, v_c190, v_c182, v_c194);
                    if (v_c195 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
                    if (v_c186 != v_c195) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c189, v_c98}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:169", "delta:st_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask617* _cont = new ReadTask617(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask617(db,b), false);
  // (crule (pre) (scan $sup9688x100x0x0x0 __t2Q3U288 l m p r u v) (body (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (1 2 0) 2 l u) (exists st_union (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t22FG286) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1pUK287) (join-old st_union (0 1 2) 3 (0 1 2) __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) l u __t1gnX289) (exists st_union_ans (0 1) 1 __t1gnX289) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (exists st_union_ans (0 1) 1 __t8LsM290) (join st_union_ans (0 1) 1 __t1gnX289 __v0) (join st_union_ans (0 1) 1 __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask677 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex659;  slog::Index** st_unionindex660;  slog::Index** st_unionindex661;  slog::Index** pbranchindex662;  slog::Index** st_unionindex663;  slog::Index** pbranchindex664;  slog::Index** st_unionindex665;  slog::Index** st_unionindex666;  slog::Index** st_union_ansindex667;  slog::Index** st_unionindex668;  slog::Index** st_union_ansindex669;  slog::Index** st_union_ansindex670;  slog::Index** st_union_ansindex671;  slog::Index** pbranchdelta672;  slog::Index** pbranchdelta673;  slog::Index** st_uniondelta674;  slog::Index** st_uniondelta675;  slog::Index** st_uniondelta676;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord678({1, 2, 3, 4, 0});
      slog::Relation* readrel679 = db->getRelation("pbranch");
      pbranchindex659 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("st_union");
      st_unionindex660 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("st_union");
      st_unionindex661 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 3, 4, 0});
      slog::Relation* readrel685 = db->getRelation("pbranch");
      pbranchindex662 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 3, 4, 0});
      slog::Relation* readrel687 = db->getRelation("pbranch");
      pbranchdelta672 = readrel687->getIndex(ord686, true);
      std::vector<u16> ord688({2, 0, 1});
      slog::Relation* readrel689 = db->getRelation("st_union");
      st_unionindex663 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 3, 4, 0});
      slog::Relation* readrel691 = db->getRelation("pbranch");
      pbranchindex664 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 3, 4, 0});
      slog::Relation* readrel693 = db->getRelation("pbranch");
      pbranchdelta673 = readrel693->getIndex(ord692, true);
      std::vector<u16> ord694({0, 1, 2});
      slog::Relation* readrel695 = db->getRelation("st_union");
      st_unionindex665 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("st_union");
      st_uniondelta674 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("st_union");
      st_unionindex666 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("st_union");
      st_uniondelta675 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({0, 1});
      slog::Relation* readrel703 = db->getRelation("st_union_ans");
      st_union_ansindex667 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("st_union");
      st_unionindex668 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 0});
      slog::Relation* readrel707 = db->getRelation("st_union");
      st_uniondelta676 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1});
      slog::Relation* readrel709 = db->getRelation("st_union_ans");
      st_union_ansindex669 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1});
      slog::Relation* readrel711 = db->getRelation("st_union_ans");
      st_union_ansindex670 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({0, 1});
      slog::Relation* readrel713 = db->getRelation("st_union_ans");
      st_union_ansindex671 = readrel713->getIndex(ord712, false);
  
    }
    ReadTask677(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c5 = _t[5];
        u64 v_c6 = _t[6];
        if (!slog::exists_probe<5,4>(pbranchindex659, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0})) return;
        if (!slog::exists_probe<3,2>(st_unionindex660, std::array<u64,3>{v_c7, v_c5, 0})) return;
        if (!slog::exists_probe<3,2>(st_unionindex661, std::array<u64,3>{v_c8, v_c6, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex662, pbranchdelta672, std::array<u64,5>{v_c3, v_c4, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m714) {
          u64 v_c197 = m714[4];
          if (!slog::exists_probe<3,2>(st_unionindex663, std::array<u64,3>{v_c197, v_c196, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex664, pbranchdelta673, std::array<u64,5>{v_c3, v_c4, v_c7, v_c8, 0}, [&](const std::array<u64,5>& m715) {
            u64 v_c198 = m715[4];
            slog::join_probe_old<3,3>(st_unionindex665, st_uniondelta674, std::array<u64,3>{v_c196, v_c198, v_c197}, [&](const std::array<u64,3>& m716) {
              slog::join_probe_old<3,2>(st_unionindex666, st_uniondelta675, std::array<u64,3>{v_c7, v_c5, 0}, [&](const std::array<u64,3>& m717) {
                u64 v_c199 = m717[2];
                if (!slog::exists_probe<2,1>(st_union_ansindex667, std::array<u64,2>{v_c199, 0})) return;
                slog::join_probe_old<3,2>(st_unionindex668, st_uniondelta676, std::array<u64,3>{v_c8, v_c6, 0}, [&](const std::array<u64,3>& m718) {
                  u64 v_c200 = m718[2];
                  if (!slog::exists_probe<2,1>(st_union_ansindex669, std::array<u64,2>{v_c200, 0})) return;
                  slog::join_probe<2,1>(st_union_ansindex670, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m719) {
                    u64 v_c29 = m719[1];
                    slog::join_probe<2,1>(st_union_ansindex671, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m720) {
                      u64 v_c98 = m720[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c196, v_c29, v_c98, v_c4, v_c3});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c4, v_c29, v_c98}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:$sup9688x100x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask677* _cont = new ReadTask677(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask677(db,b), false);
  // (crule (pre) (scan st_msk_ans __t6jwI501 p) (body (exists $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t6jwI501 q m) (join $sup9688x106x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t6jwI501 l m n p q u v)) set.slog:107 #f)
  class ReadTask725 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x0index721;  slog::Index** st_mskindex722;  slog::Index** $sup9688x106x0x0x0index723;  slog::Index** st_mskdelta724;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord726({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel727 = db->getRelation("$sup9688x106x0x0x1");
      head_index[0] = readrel727->getIndex(ord726, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord728({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel729 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index721 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({0, 1, 2});
      slog::Relation* readrel731 = db->getRelation("st_msk");
      st_mskindex722 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 1, 2});
      slog::Relation* readrel733 = db->getRelation("st_msk");
      st_mskdelta724 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel735 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index723 = readrel735->getIndex(ord734, false);
  
    }
    ReadTask725(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c201 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x106x0x0x0index721, std::array<u64,9>{v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex722, st_mskdelta724, std::array<u64,3>{v_c201, 0, 0}, [&](const std::array<u64,3>& m736) {
          u64 v_c13 = m736[1]; u64 v_c4 = m736[2];
          slog::join_probe<9,3>($sup9688x106x0x0x0index723, std::array<u64,9>{v_c4, v_c13, v_c3, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m737) {
            u64 v_c27 = m737[3]; u64 v_c7 = m737[4]; u64 v_c14 = m737[5]; u64 v_c8 = m737[6]; u64 v_c5 = m737[7]; u64 v_c6 = m737[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c27, v_c8, v_c201, v_c7, v_c4, v_c14, v_c3, v_c13, v_c5, v_c6}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask725* _cont = new ReadTask725(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask725(db,b), false);
  // (crule (pre) (scan st_ins __t5aIA185 t k) (body (exists pleaf (1 0) 1 k) (exists st_union (2 0 1) 1 t) (join st_ins_ans (0 1) 1 __t5aIA185 r) (join pleaf (1 0) 1 k __t7Mu9183) (join st_union (1 2 0) 2 __t7Mu9183 t __t2rFM184)) (head (emit st_union_ans (0 1) __t2rFM184 r)) set.slog:98 #f)
  class ReadTask743 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex738;  slog::Index** st_unionindex739;  slog::Index** st_ins_ansindex740;  slog::Index** pleafindex741;  slog::Index** st_unionindex742;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("st_union_ans");
      head_index[0] = readrel745->getIndex(ord744, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord746({1, 0});
      slog::Relation* readrel747 = db->getRelation("pleaf");
      pleafindex738 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({2, 0, 1});
      slog::Relation* readrel749 = db->getRelation("st_union");
      st_unionindex739 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({0, 1});
      slog::Relation* readrel751 = db->getRelation("st_ins_ans");
      st_ins_ansindex740 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0});
      slog::Relation* readrel753 = db->getRelation("pleaf");
      pleafindex741 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 0});
      slog::Relation* readrel755 = db->getRelation("st_union");
      st_unionindex742 = readrel755->getIndex(ord754, false);
  
    }
    ReadTask743(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[1];
        u64 v_c20 = _t[2];
        if (!slog::exists_probe<2,1>(pleafindex738, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex739, std::array<u64,3>{v_c38, 0, 0})) return;
        slog::join_probe<2,1>(st_ins_ansindex740, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m756) {
          u64 v_c8 = m756[1];
          slog::join_probe<2,1>(pleafindex741, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m757) {
            u64 v_c203 = m757[1];
            slog::join_probe<3,2>(st_unionindex742, std::array<u64,3>{v_c203, v_c38, 0}, [&](const std::array<u64,3>& m758) {
              u64 v_c204 = m758[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c204, v_c8}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask743* _cont = new ReadTask743(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask743(db,b), false);
}

