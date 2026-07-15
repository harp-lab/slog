
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const81906d9241165d9f6a541e47;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constb9bc7505101241ebf0c7cf59;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdee70e0c1571644b5844be78;
extern u64 v_conste09004dcc147461a8e3857fe;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf2664e0abda1016213c9fa90;


void slog_rules_c7cf27517710f1393(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_msk __t5pdy283 k m) (body (exists $sup9688x88x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_del (2 0 1) 1 k) (exists st_bld (2 1 4 0 3) 1 m) (join st_msk_ans (0 1) 1 __t5pdy283 p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x88x0x0x0 (1 3 4 0 2 5) 3 k m p __t3OU0279 l r) (exists st_del (0 2 1) 2 __t3OU0279 k) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_del (1 2 0) 2 l k) (join pbranch (1 2 3 4 0) 4 p m l r __t2u9k278) (join st_del (0 2 1) 3 __t3OU0279 k __t2u9k278) (join st_bld (2 1 4 0 3) 3 m p r __t6UON282 __v0) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join st_del_ans (0 1) 2 __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index0;  slog::Index** pbranchindex1;  slog::Index** st_delindex2;  slog::Index** st_bldindex3;  slog::Index** st_msk_ansindex4;  slog::Index** pbranchindex5;  slog::Index** st_bldindex6;  slog::Index** $sup9688x88x0x0x0index7;  slog::Index** st_delindex8;  slog::Index** st_bldindex9;  slog::Index** st_delindex10;  slog::Index** pbranchindex11;  slog::Index** st_delindex12;  slog::Index** st_bldindex13;  slog::Index** st_del_ansindex14;  slog::Index** st_bld_ansindex15;  slog::Index** st_delindex16;  slog::Index** st_del_ansindex17;  slog::Index** st_bld_ansindex18;  slog::Index** st_deldelta19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("st_del_ans");
      head_index[0] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord23({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel24 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index0 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({2, 0, 1, 3, 4});
      slog::Relation* readrel26 = db->getRelation("pbranch");
      pbranchindex1 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({2, 0, 1});
      slog::Relation* readrel28 = db->getRelation("st_del");
      st_delindex2 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 1, 4, 0, 3});
      slog::Relation* readrel30 = db->getRelation("st_bld");
      st_bldindex3 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("st_msk_ans");
      st_msk_ansindex4 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 3, 4, 0});
      slog::Relation* readrel34 = db->getRelation("pbranch");
      pbranchindex5 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 3, 4, 0});
      slog::Relation* readrel36 = db->getRelation("st_bld");
      st_bldindex6 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel38 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index7 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 2, 1});
      slog::Relation* readrel40 = db->getRelation("st_del");
      st_delindex8 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 1, 4, 0, 3});
      slog::Relation* readrel42 = db->getRelation("st_bld");
      st_bldindex9 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("st_del");
      st_delindex10 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 3, 4, 0});
      slog::Relation* readrel46 = db->getRelation("pbranch");
      pbranchindex11 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 2, 1});
      slog::Relation* readrel48 = db->getRelation("st_del");
      st_delindex12 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({2, 1, 4, 0, 3});
      slog::Relation* readrel50 = db->getRelation("st_bld");
      st_bldindex13 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("st_del_ans");
      st_del_ansindex14 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("st_bld_ans");
      st_bld_ansindex15 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("st_del");
      st_delindex16 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 0});
      slog::Relation* readrel58 = db->getRelation("st_del");
      st_deldelta19 = readrel58->getIndex(ord57, true);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("st_del_ans");
      st_del_ansindex17 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("st_bld_ans");
      st_bld_ansindex18 = readrel62->getIndex(ord61, false);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
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
        if (!slog::exists_probe<6,2>($sup9688x88x0x0x0index0, std::array<u64,6>{v_c2, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex2, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex3, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex4, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m63) {
          u64 v_c4 = m63[1];
          if (!slog::exists_probe<5,2>(pbranchindex5, std::array<u64,5>{v_c4, v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex6, std::array<u64,5>{v_c4, v_c3, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x88x0x0x0index7, std::array<u64,6>{v_c2, v_c3, v_c4, 0, 0, 0}, [&](const std::array<u64,6>& m64) {
            u64 v_c5 = m64[3]; u64 v_c6 = m64[4]; u64 v_c7 = m64[5];
            if (!slog::exists_probe<3,2>(st_delindex8, std::array<u64,3>{v_c5, v_c2, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex9, std::array<u64,5>{v_c3, v_c4, v_c7, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex10, std::array<u64,3>{v_c6, v_c2, 0})) return;
            slog::join_probe<5,4>(pbranchindex11, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m65) {
              u64 v_c8 = m65[4];
              slog::join_probe<3,3>(st_delindex12, std::array<u64,3>{v_c5, v_c2, v_c8}, [&](const std::array<u64,3>& m66) {
                slog::join_probe<5,3>(st_bldindex13, std::array<u64,5>{v_c3, v_c4, v_c7, 0, 0}, [&](const std::array<u64,5>& m67) {
                  u64 v_c9 = m67[3]; u64 v_c10 = m67[4];
                  if (!slog::exists_probe<2,1>(st_del_ansindex14, std::array<u64,2>{v_c10, 0})) return;
                  if (!slog::exists_probe<2,1>(st_bld_ansindex15, std::array<u64,2>{v_c9, 0})) return;
                  slog::join_probe_old<3,2>(st_delindex16, st_deldelta19, std::array<u64,3>{v_c6, v_c2, 0}, [&](const std::array<u64,3>& m68) {
                    u64 v_c11 = m68[2];
                    slog::join_probe<2,2>(st_del_ansindex17, std::array<u64,2>{v_c11, v_c10}, [&](const std::array<u64,2>& m69) {
                      slog::join_probe<2,1>(st_bld_ansindex18, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m70) {
                        u64 v_c12 = m70[1];
                        u64 v_c13 = _prim_band(db, v_c2, v_c3);
                        if (v_c13 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c14 = _prim_lt(db, v_c13, v_c0);
                        if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c14) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_msk", _fires);
  
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
  // (crule (pre (let __tconst03yH266 const6b86b273ff34fce19d6b804e)) (scan st_hsb_ans __t3jPx265 __v0) (body (join-old st_hsb (0 1) 1 (0 1) __t3jPx265 __t7lUk264) (join $sup9688x36x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t2kVi267 (band p0 __v0)) (cmp lt __t2kVi267 __tconst03yH266) (let chk1rcU1336 (bxor p0 p1)) (eq __t7lUk264 chk1rcU1336)) (head (emit $sup9688x36x0x0x1 (1 2 0 3 4 5 6) __t3jPx265 __v0 __d0 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask75 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsbindex72;  slog::Index** $sup9688x36x0x0x0index73;  slog::Index** st_hsbdelta74;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord76({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel77 = db->getRelation("$sup9688x36x0x0x1");
      head_index[0] = readrel77->getIndex(ord76, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("st_hsb");
      st_hsbindex72 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("st_hsb");
      st_hsbdelta74 = readrel81->getIndex(ord80, true);
      std::vector<u16> ord82({1, 0, 2, 3, 4});
      slog::Relation* readrel83 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index73 = readrel83->getIndex(ord82, false);
  
    }
    ReadTask75(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        slog::join_probe_old<2,1>(st_hsbindex72, st_hsbdelta74, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m84) {
          u64 v_c17 = m84[1];
          slog::join_all<5>($sup9688x36x0x0x0index73, [&](const std::array<u64,5>& m85) {
            u64 v_c18 = m85[0]; u64 v_c19 = m85[1]; u64 v_c20 = m85[2]; u64 v_c21 = m85[3]; u64 v_c22 = m85[4];
            u64 v_c23 = _prim_band(db, v_c18, v_c10);
            if (v_c23 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            u64 v_c24 = _prim_lt(db, v_c23, v_c15);
            if (v_c24 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            if (!v_c24) return;
            u64 v_c25 = _prim_bxor(db, v_c18, v_c20);
            if (v_c25 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            if (v_c17 != v_c25) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c16, v_c10, v_c19, v_c18, v_c20, v_c21, v_c22}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask75* _cont = new ReadTask75(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask75(db,b), false);
  // (crule (pre (let __tconst6HIV120 const4e07408562bedb8b60ce05c1)) (scan canon s) (body) (head (mkstruct st_mem0 (1 2 0) __3Poa1118 s __tconst6HIV120)) st_basic.slog:21 #f)
  class ReadTask87 : public slog::Task
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
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c27 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c26}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:21", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask87* _cont = new ReadTask87(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask87(db,b), false);
  // (crule (pre) (scan $sup9688x52x0x0x0 __d0 k l m p r) (body (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t43e0330) (join-old st_msk_ans (0 1) 2 (0 1) __t43e0330 p)) (head (emit $sup9688x52x0x0x1 (0 2 1 3 4 5 6) __d0 k __t43e0330 l m p r)) set.slog:53 #f)
  class ReadTask93 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex88;  slog::Index** st_mskindex89;  slog::Index** st_msk_ansindex90;  slog::Index** st_mskdelta91;  slog::Index** st_msk_ansdelta92;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord94({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel95 = db->getRelation("$sup9688x52x0x0x1");
      head_index[0] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("st_msk_ans");
      st_msk_ansindex88 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 2, 0});
      slog::Relation* readrel99 = db->getRelation("st_msk");
      st_mskindex89 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("st_msk");
      st_mskdelta91 = readrel101->getIndex(ord100, true);
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("st_msk_ans");
      st_msk_ansindex90 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({0, 1});
      slog::Relation* readrel105 = db->getRelation("st_msk_ans");
      st_msk_ansdelta92 = readrel105->getIndex(ord104, true);
  
    }
    ReadTask93(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c7 = _t[5];
        if (!slog::exists_probe<2,1>(st_msk_ansindex88, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex89, st_mskdelta91, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m106) {
          u64 v_c28 = m106[2];
          slog::join_probe_old<2,2>(st_msk_ansindex90, st_msk_ansdelta92, std::array<u64,2>{v_c28, v_c4}, [&](const std::array<u64,2>& m107) {
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c19, v_c2, v_c28, v_c6, v_c3, v_c4, v_c7}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:$sup9688x52x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask93* _cont = new ReadTask93(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask93(db,b), false);
  // (crule (pre (let __trid8UbW935 constb9bc7505101241ebf0c7cf59) (let __trel1Naa936 consta10f76b4ec574de5d7b6908e) (let __tcol0tYG937 const5feceb66ffc86f38d952786c) (let __trel3nKA938 consta10f76b4ec574de5d7b6908e) (let __tcol6t3E939 const6b86b273ff34fce19d6b804e)) (scan $sup9688x40x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid8UbW935 __trel1Naa936 __tcol0tYG937 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid8UbW935 __trel3nKA938 __tcol6t3E939 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __7JHc934 p0 __v1)) set.slog:41 #f)
  class ReadTask108 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x40x0x0x2");
  
    }
    ReadTask108(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constb9bc7505101241ebf0c7cf59;
      u64 v_c30 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c19 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c10 = _t[4];
        u64 v_c37 = _t[5];
        u64 v_c38 = _t[6];
        u64 v_c18 = _t[7];
        u64 v_c20 = _t[8];
        u64 v_c21 = _t[9];
        u64 v_c22 = _t[10];
        ++_fires;
        if (!(is_int(v_c18)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c29, v_c30, v_c31, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c37)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c29, v_c32, v_c33, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c18, v_c37}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask108* _cont = new ReadTask108(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask108(db,b), false);
  // (crule (pre) (scan pbranch __t3cJ7407 p m l r) (body (exists pbranch (1 2 3 4 0) 2 p m) (exists st_diff (1 2 0) 1 __t3cJ7407) (exists st_diff (1 2 0) 1 l) (exists st_diff (1 2 0) 1 r) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x136x0x0x0 (2 3 1 4 0 5 6) 4 m p l r __t5pD6408 u v) (exists st_diff (0 1 2) 2 __t5pD6408 __t3cJ7407) (exists st_diff (1 2 0) 2 l u) (exists st_diff (1 2 0) 2 r v) (join pbranch (1 2 3 4 0) 4 p m u v __t9ous406) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (exists st_diff_ans (0 1) 1 __t6cu0410) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (exists st_diff_ans (0 1) 1 __t8u30411) (join-old st_bld (1 2 3 4 0) 2 (1 2 3 4 0) p m __v0 __v1 __t9obY409) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask132 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex109;  slog::Index** st_diffindex110;  slog::Index** st_diffindex111;  slog::Index** st_diffindex112;  slog::Index** st_bldindex113;  slog::Index** $sup9688x136x0x0x0index114;  slog::Index** st_diffindex115;  slog::Index** st_diffindex116;  slog::Index** st_diffindex117;  slog::Index** pbranchindex118;  slog::Index** st_diffindex119;  slog::Index** st_diffindex120;  slog::Index** st_diff_ansindex121;  slog::Index** st_diffindex122;  slog::Index** st_diff_ansindex123;  slog::Index** st_bldindex124;  slog::Index** st_diff_ansindex125;  slog::Index** st_diff_ansindex126;  slog::Index** st_bld_ansindex127;  slog::Index** st_diffdelta128;  slog::Index** st_diffdelta129;  slog::Index** st_diffdelta130;  slog::Index** st_blddelta131;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("st_diff_ans");
      head_index[0] = readrel134->getIndex(ord133, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord135({1, 2, 3, 4, 0});
      slog::Relation* readrel136 = db->getRelation("pbranch");
      pbranchindex109 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 0});
      slog::Relation* readrel138 = db->getRelation("st_diff");
      st_diffindex110 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("st_diff");
      st_diffindex111 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("st_diff");
      st_diffindex112 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 3, 4, 0});
      slog::Relation* readrel144 = db->getRelation("st_bld");
      st_bldindex113 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({2, 3, 1, 4, 0, 5, 6});
      slog::Relation* readrel146 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index114 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({0, 1, 2});
      slog::Relation* readrel148 = db->getRelation("st_diff");
      st_diffindex115 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 2, 0});
      slog::Relation* readrel150 = db->getRelation("st_diff");
      st_diffindex116 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 0});
      slog::Relation* readrel152 = db->getRelation("st_diff");
      st_diffindex117 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 3, 4, 0});
      slog::Relation* readrel154 = db->getRelation("pbranch");
      pbranchindex118 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1, 2});
      slog::Relation* readrel156 = db->getRelation("st_diff");
      st_diffindex119 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1, 2});
      slog::Relation* readrel158 = db->getRelation("st_diff");
      st_diffdelta128 = readrel158->getIndex(ord157, true);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("st_diff");
      st_diffindex120 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("st_diff");
      st_diffdelta129 = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("st_diff_ans");
      st_diff_ansindex121 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("st_diff");
      st_diffindex122 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 2, 0});
      slog::Relation* readrel168 = db->getRelation("st_diff");
      st_diffdelta130 = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("st_diff_ans");
      st_diff_ansindex123 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 3, 4, 0});
      slog::Relation* readrel172 = db->getRelation("st_bld");
      st_bldindex124 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 3, 4, 0});
      slog::Relation* readrel174 = db->getRelation("st_bld");
      st_blddelta131 = readrel174->getIndex(ord173, true);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("st_diff_ans");
      st_diff_ansindex125 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("st_diff_ans");
      st_diff_ansindex126 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("st_bld_ans");
      st_bld_ansindex127 = readrel180->getIndex(ord179, false);
  
    }
    ReadTask132(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex109, std::array<u64,5>{v_c4, v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex110, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex111, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex112, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<5,2>(st_bldindex113, std::array<u64,5>{v_c4, v_c3, 0, 0, 0})) return;
        slog::join_probe<7,4>($sup9688x136x0x0x0index114, std::array<u64,7>{v_c3, v_c4, v_c6, v_c7, 0, 0, 0}, [&](const std::array<u64,7>& m181) {
          u64 v_c40 = m181[4]; u64 v_c41 = m181[5]; u64 v_c42 = m181[6];
          if (!slog::exists_probe<3,2>(st_diffindex115, std::array<u64,3>{v_c40, v_c39, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex116, std::array<u64,3>{v_c6, v_c41, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex117, std::array<u64,3>{v_c7, v_c42, 0})) return;
          slog::join_probe<5,4>(pbranchindex118, std::array<u64,5>{v_c4, v_c3, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m182) {
            u64 v_c43 = m182[4];
            slog::join_probe_old<3,3>(st_diffindex119, st_diffdelta128, std::array<u64,3>{v_c40, v_c39, v_c43}, [&](const std::array<u64,3>& m183) {
              slog::join_probe_old<3,2>(st_diffindex120, st_diffdelta129, std::array<u64,3>{v_c6, v_c41, 0}, [&](const std::array<u64,3>& m184) {
                u64 v_c44 = m184[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex121, std::array<u64,2>{v_c44, 0})) return;
                slog::join_probe_old<3,2>(st_diffindex122, st_diffdelta130, std::array<u64,3>{v_c7, v_c42, 0}, [&](const std::array<u64,3>& m185) {
                  u64 v_c45 = m185[2];
                  if (!slog::exists_probe<2,1>(st_diff_ansindex123, std::array<u64,2>{v_c45, 0})) return;
                  slog::join_probe_old<5,2>(st_bldindex124, st_blddelta131, std::array<u64,5>{v_c4, v_c3, 0, 0, 0}, [&](const std::array<u64,5>& m186) {
                    u64 v_c10 = m186[2]; u64 v_c37 = m186[3]; u64 v_c46 = m186[4];
                    slog::join_probe<2,2>(st_diff_ansindex125, std::array<u64,2>{v_c44, v_c10}, [&](const std::array<u64,2>& m187) {
                      slog::join_probe<2,2>(st_diff_ansindex126, std::array<u64,2>{v_c45, v_c37}, [&](const std::array<u64,2>& m188) {
                        slog::join_probe<2,1>(st_bld_ansindex127, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m189) {
                          u64 v_c12 = m189[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c40, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask132* _cont = new ReadTask132(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask132(db,b), false);
  // (crule (pre (let __tconst1O9J948 conste3776bfed7f405de8017ecfa)) (scan st_bld __t4rEg577 p m l r) (body (join _enum (1 0) 1 __tconst1O9J948 __t5kJu578) (neq l __t5kJu578) (neq r __t5kJu578)) (head (emit-temp temp5Bov1275 __t4rEg577 l m p r) (mkstruct pbranch (1 2 3 4 0) __t94LO576 p m l r)) set.slog:80 #f)
  class ReadTask191 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex190;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5Bov1275");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("_enum");
      _enumindex190 = readrel193->getIndex(ord192, false);
  
    }
    ReadTask191(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c48 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe<2,1>(_enumindex190, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m194) {
          u64 v_c49 = m194[1];
          if (v_c6 == v_c49) return;
          if (v_c7 == v_c49) return;
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c48, v_c6, v_c3, v_c4, v_c7});
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c6, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:80", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask191* _cont = new ReadTask191(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask191(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan $sup9688x139x0x0x0 __d0 l m n p q r u v) (body (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3QFk546) (exists st_diff (1 2 0) 2 l __t3QFk546) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t9Eou545) (join-old st_msk_ans (0 1) 2 (0 1) __t9Eou545 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t3QFk546 __t9ide547) (join-old st_diff_ans (0 1) 1 (0 1) __t9ide547 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex195;  slog::Index** st_msk_ansindex196;  slog::Index** st_diffindex197;  slog::Index** pbranchindex198;  slog::Index** st_diffindex199;  slog::Index** st_mskindex200;  slog::Index** st_msk_ansindex201;  slog::Index** st_diffindex202;  slog::Index** st_diff_ansindex203;  slog::Index** pbranchdelta204;  slog::Index** st_mskdelta205;  slog::Index** st_msk_ansdelta206;  slog::Index** st_diffdelta207;  slog::Index** st_diff_ansdelta208;
    u32 sid210;  u32 sid209;  u32 sid211;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("st_msk");
      st_mskindex195 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("st_msk_ans");
      st_msk_ansindex196 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("st_diff");
      st_diffindex197 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 3, 4, 0});
      slog::Relation* readrel220 = db->getRelation("pbranch");
      pbranchindex198 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 3, 4, 0});
      slog::Relation* readrel222 = db->getRelation("pbranch");
      pbranchdelta204 = readrel222->getIndex(ord221, true);
      std::vector<u16> ord223({1, 2, 0});
      slog::Relation* readrel224 = db->getRelation("st_diff");
      st_diffindex199 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("st_msk");
      st_mskindex200 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("st_msk");
      st_mskdelta205 = readrel228->getIndex(ord227, true);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("st_msk_ans");
      st_msk_ansindex201 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("st_msk_ans");
      st_msk_ansdelta206 = readrel232->getIndex(ord231, true);
      std::vector<u16> ord233({1, 2, 0});
      slog::Relation* readrel234 = db->getRelation("st_diff");
      st_diffindex202 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 2, 0});
      slog::Relation* readrel236 = db->getRelation("st_diff");
      st_diffdelta207 = readrel236->getIndex(ord235, true);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("st_diff_ans");
      st_diff_ansindex203 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 1});
      slog::Relation* readrel240 = db->getRelation("st_diff_ans");
      st_diff_ansdelta208 = readrel240->getIndex(ord239, true);
      sid210 = db->getRelation("_enum")->getStructId();
      sid209 = db->getRelation("pbranch")->getStructId();
      sid211 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c51 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c52 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c54 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c41 = _t[7];
        u64 v_c42 = _t[8];
        if (!slog::exists_probe<3,2>(st_mskindex195, std::array<u64,3>{v_c54, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex196, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex197, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex198, pbranchdelta204, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m241) {
          u64 v_c55 = m241[4];
          if (!slog::exists_probe<3,2>(st_diffindex199, std::array<u64,3>{v_c6, v_c55, 0})) return;
          slog::join_probe_old<3,2>(st_mskindex200, st_mskdelta205, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m242) {
            u64 v_c56 = m242[2];
            slog::join_probe_old<2,2>(st_msk_ansindex201, st_msk_ansdelta206, std::array<u64,2>{v_c56, v_c4}, [&](const std::array<u64,2>& m243) {
              slog::join_probe_old<3,2>(st_diffindex202, st_diffdelta207, std::array<u64,3>{v_c6, v_c55, 0}, [&](const std::array<u64,3>& m244) {
                u64 v_c57 = m244[2];
                slog::join_probe_old<2,1>(st_diff_ansindex203, st_diff_ansdelta208, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m245) {
                  u64 v_c10 = m245[1];
                  ++_fires;
                  if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid209 || decode_struct_id(v_c7) == sid210 || decode_struct_id(v_c7) == sid211))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c50, v_c51, v_c52, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c10, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:$sup9688x139x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_diff __t8Fy1335 __t88zt334 __t69OA340) (body (exists $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) 1 __t8Fy1335) (join-old st_diff (2 0 1) 1 (2 0 1) __t69OA340 __t95th341 r) (exists $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t8Fy1335 r) (exists st_diff_ans (0 1) 1 __t95th341) (join pbranch (4 0 1 2 3) 2 r __t88zt334 p m l) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t8Fy1335 n q u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t69OA340) (exists st_msk (1 2 0) 2 q m) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t7XLn338) (join st_diff_ans (0 1) 2 __t95th341 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index246;  slog::Index** st_diffindex247;  slog::Index** $sup9688x142x0x0x0index248;  slog::Index** st_diff_ansindex249;  slog::Index** pbranchindex250;  slog::Index** st_bldindex251;  slog::Index** st_mskindex252;  slog::Index** st_msk_ansindex253;  slog::Index** $sup9688x142x0x0x0index254;  slog::Index** pbranchindex255;  slog::Index** st_mskindex256;  slog::Index** st_bldindex257;  slog::Index** st_diff_ansindex258;  slog::Index** st_bld_ansindex259;  slog::Index** st_mskindex260;  slog::Index** st_msk_ansindex261;  slog::Index** st_bld_ansindex262;  slog::Index** st_diffdelta263;  slog::Index** pbranchdelta264;  slog::Index** st_blddelta265;  slog::Index** st_mskdelta266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("st_diff_ans");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord270({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel271 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index246 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({2, 0, 1});
      slog::Relation* readrel273 = db->getRelation("st_diff");
      st_diffindex247 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({2, 0, 1});
      slog::Relation* readrel275 = db->getRelation("st_diff");
      st_diffdelta263 = readrel275->getIndex(ord274, true);
      std::vector<u16> ord276({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel277 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index248 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("st_diff_ans");
      st_diff_ansindex249 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({4, 0, 1, 2, 3});
      slog::Relation* readrel281 = db->getRelation("pbranch");
      pbranchindex250 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 2, 3, 4, 0});
      slog::Relation* readrel283 = db->getRelation("st_bld");
      st_bldindex251 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({2, 0, 1});
      slog::Relation* readrel285 = db->getRelation("st_msk");
      st_mskindex252 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 0});
      slog::Relation* readrel287 = db->getRelation("st_msk_ans");
      st_msk_ansindex253 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel289 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index254 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 2, 3, 4, 0});
      slog::Relation* readrel291 = db->getRelation("pbranch");
      pbranchindex255 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 3, 4, 0});
      slog::Relation* readrel293 = db->getRelation("pbranch");
      pbranchdelta264 = readrel293->getIndex(ord292, true);
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("st_msk");
      st_mskindex256 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 3, 4, 0});
      slog::Relation* readrel297 = db->getRelation("st_bld");
      st_bldindex257 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 3, 4, 0});
      slog::Relation* readrel299 = db->getRelation("st_bld");
      st_blddelta265 = readrel299->getIndex(ord298, true);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("st_diff_ans");
      st_diff_ansindex258 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("st_bld_ans");
      st_bld_ansindex259 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("st_msk");
      st_mskindex260 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 2, 0});
      slog::Relation* readrel307 = db->getRelation("st_msk");
      st_mskdelta266 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({0, 1});
      slog::Relation* readrel309 = db->getRelation("st_msk_ans");
      st_msk_ansindex261 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("st_bld_ans");
      st_bld_ansindex262 = readrel311->getIndex(ord310, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index246, std::array<u64,9>{v_c59, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex247, st_diffdelta263, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m312) {
          u64 v_c62 = m312[1]; u64 v_c7 = m312[2];
          if (!slog::exists_probe<9,2>($sup9688x142x0x0x0index248, std::array<u64,9>{v_c59, v_c7, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex249, std::array<u64,2>{v_c62, 0})) return;
          slog::join_probe<5,2>(pbranchindex250, std::array<u64,5>{v_c7, v_c60, 0, 0, 0}, [&](const std::array<u64,5>& m313) {
            u64 v_c4 = m313[2]; u64 v_c3 = m313[3]; u64 v_c6 = m313[4];
            if (!slog::exists_probe<5,3>(st_bldindex251, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex252, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex253, std::array<u64,2>{v_c4, 0})) return;
            slog::join_probe<9,5>($sup9688x142x0x0x0index254, std::array<u64,9>{v_c4, v_c6, v_c3, v_c7, v_c59, 0, 0, 0, 0}, [&](const std::array<u64,9>& m314) {
              u64 v_c53 = m314[5]; u64 v_c54 = m314[6]; u64 v_c41 = m314[7]; u64 v_c42 = m314[8];
              u64 v_c63 = _prim_lt(db, v_c53, v_c3);
              if (v_c63 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
              if (!v_c63) return;
              slog::join_probe_old<5,5>(pbranchindex255, pbranchdelta264, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, v_c61}, [&](const std::array<u64,5>& m316) {
                if (!slog::exists_probe<3,2>(st_mskindex256, std::array<u64,3>{v_c54, v_c3, 0})) return;
                slog::join_probe_old<5,3>(st_bldindex257, st_blddelta265, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0}, [&](const std::array<u64,5>& m317) {
                  u64 v_c10 = m317[3]; u64 v_c64 = m317[4];
                  slog::join_probe<2,2>(st_diff_ansindex258, std::array<u64,2>{v_c62, v_c10}, [&](const std::array<u64,2>& m318) {
                    if (!slog::exists_probe<2,1>(st_bld_ansindex259, std::array<u64,2>{v_c64, 0})) return;
                    slog::join_probe_old<3,2>(st_mskindex260, st_mskdelta266, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m319) {
                      u64 v_c65 = m319[2];
                      slog::join_probe<2,2>(st_msk_ansindex261, std::array<u64,2>{v_c65, v_c4}, [&](const std::array<u64,2>& m320) {
                        slog::join_probe<2,1>(st_bld_ansindex262, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m321) {
                          u64 v_c12 = m321[1];
                          u64 v_c66 = _prim_band(db, v_c54, v_c3);
                          if (v_c66 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c67 = _prim_gt(db, v_c66, v_c58);
                          if (v_c67 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c67) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_diff", _fires);
  
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
  // (crule (pre) (scan st_diff __t2Ttf9 __t0y5a8 __t9yhk7) (body (join pbranch (0 1 2 3 4) 1 __t9yhk7 q n u v) (join pbranch (0 1 2 3 4) 1 __t0y5a8 p m l r) (cmp lt m n)) (head (emit $sup9688x154x0x0x0 (0 1 2 3 4 5 6 7 8) __t2Ttf9 l m n p q r u v)) set.slog:155 #f)
  class ReadTask325 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex323;  slog::Index** pbranchindex324;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord326({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel327 = db->getRelation("$sup9688x154x0x0x0");
      head_index[0] = readrel327->getIndex(ord326, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord328({0, 1, 2, 3, 4});
      slog::Relation* readrel329 = db->getRelation("pbranch");
      pbranchindex323 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 1, 2, 3, 4});
      slog::Relation* readrel331 = db->getRelation("pbranch");
      pbranchindex324 = readrel331->getIndex(ord330, false);
  
    }
    ReadTask325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        slog::join_probe<5,1>(pbranchindex323, std::array<u64,5>{v_c70, 0, 0, 0, 0}, [&](const std::array<u64,5>& m332) {
          u64 v_c54 = m332[1]; u64 v_c53 = m332[2]; u64 v_c41 = m332[3]; u64 v_c42 = m332[4];
          slog::join_probe<5,1>(pbranchindex324, std::array<u64,5>{v_c69, 0, 0, 0, 0}, [&](const std::array<u64,5>& m333) {
            u64 v_c4 = m333[1]; u64 v_c3 = m333[2]; u64 v_c6 = m333[3]; u64 v_c7 = m333[4];
            u64 v_c71 = _prim_lt(db, v_c3, v_c53);
            if (v_c71 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c71) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c68, v_c6, v_c3, v_c53, v_c4, v_c54, v_c7, v_c41, v_c42}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:st_diff", _fires);
  
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
  // (crule (pre (let __tconst4ng4400 const5feceb66ffc86f38d952786c)) (scan $sup9688x69x0x0x0 __t26uy402 k l m p r) (body (exists st_mem0 (2 0 1) 2 k __t26uy402) (exists st_msk (1 2 0) 2 k m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4Y7m401) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t26uy402 __t4Y7m401 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t7rLj403) (join st_msk_ans (0 1) 1 __t7rLj403 __v0) (neq p __v0)) (head (emit st_mem0_ans (0 1) __t26uy402 __tconst4ng4400)) set.slog:70 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index335;  slog::Index** st_mskindex336;  slog::Index** pbranchindex337;  slog::Index** st_mem0index338;  slog::Index** st_mskindex339;  slog::Index** st_msk_ansindex340;  slog::Index** pbranchdelta341;  slog::Index** st_mem0delta342;  slog::Index** st_mskdelta343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel346->getIndex(ord345, false);
      outer_rel = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord347({2, 0, 1});
      slog::Relation* readrel348 = db->getRelation("st_mem0");
      st_mem0index335 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("st_msk");
      st_mskindex336 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 3, 4, 0});
      slog::Relation* readrel352 = db->getRelation("pbranch");
      pbranchindex337 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 3, 4, 0});
      slog::Relation* readrel354 = db->getRelation("pbranch");
      pbranchdelta341 = readrel354->getIndex(ord353, true);
      std::vector<u16> ord355({0, 1, 2});
      slog::Relation* readrel356 = db->getRelation("st_mem0");
      st_mem0index338 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1, 2});
      slog::Relation* readrel358 = db->getRelation("st_mem0");
      st_mem0delta342 = readrel358->getIndex(ord357, true);
      std::vector<u16> ord359({1, 2, 0});
      slog::Relation* readrel360 = db->getRelation("st_msk");
      st_mskindex339 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("st_msk");
      st_mskdelta343 = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("st_msk_ans");
      st_msk_ansindex340 = readrel364->getIndex(ord363, false);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c7 = _t[5];
        if (!slog::exists_probe<3,2>(st_mem0index335, std::array<u64,3>{v_c2, v_c73, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex336, std::array<u64,3>{v_c2, v_c3, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex337, pbranchdelta341, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m365) {
          u64 v_c74 = m365[4];
          slog::join_probe_old<3,3>(st_mem0index338, st_mem0delta342, std::array<u64,3>{v_c73, v_c74, v_c2}, [&](const std::array<u64,3>& m366) {
            slog::join_probe_old<3,2>(st_mskindex339, st_mskdelta343, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m367) {
              u64 v_c75 = m367[2];
              slog::join_probe<2,1>(st_msk_ansindex340, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m368) {
                u64 v_c10 = m368[1];
                if (v_c4 == v_c10) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c72}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:$sup9688x69x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask344* _cont = new ReadTask344(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask344(db,b), false);
  // (crule (pre (let __trid7AMG943 constf2664e0abda1016213c9fa90) (let __trel1lLE944 const26c89ee8ccc4ea998fd1a912) (let __tcol6Qdi945 const5feceb66ffc86f38d952786c) (let __trel7lgp946 const26c89ee8ccc4ea998fd1a912) (let __tcol7D5S947 const6b86b273ff34fce19d6b804e)) (scan st_diff_ans __t6exy561 __v1) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t6exy561 r v) (join $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 r v __d0 l m p u) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t3HZn560) (join st_diff_ans (0 1) 1 __t3HZn560 __v0)) (head (tycheck p (accept int) __trid7AMG943 __trel1lLE944 __tcol6Qdi945 (1 2 3 4 0)) (tycheck m (accept int) __trid7AMG943 __trel7lgp946 __tcol7D5S947 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __7CRS942 p m __v0 __v1)) set.slog:137 #f)
  class ReadTask375 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex369;  slog::Index** $sup9688x136x0x0x0index370;  slog::Index** st_diffindex371;  slog::Index** st_diff_ansindex372;  slog::Index** st_diffdelta373;  slog::Index** st_diffdelta374;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord376({0, 1, 2});
      slog::Relation* readrel377 = db->getRelation("st_diff");
      st_diffindex369 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1, 2});
      slog::Relation* readrel379 = db->getRelation("st_diff");
      st_diffdelta373 = readrel379->getIndex(ord378, true);
      std::vector<u16> ord380({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel381 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index370 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("st_diff");
      st_diffindex371 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("st_diff");
      st_diffdelta374 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("st_diff_ans");
      st_diff_ansindex372 = readrel387->getIndex(ord386, false);
  
    }
    ReadTask375(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_constf2664e0abda1016213c9fa90;
      u64 v_c77 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c81 = _t[0];
        u64 v_c37 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex369, st_diffdelta373, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m388) {
          u64 v_c7 = m388[1]; u64 v_c42 = m388[2];
          slog::join_probe<7,2>($sup9688x136x0x0x0index370, std::array<u64,7>{v_c7, v_c42, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m389) {
            u64 v_c19 = m389[2]; u64 v_c6 = m389[3]; u64 v_c3 = m389[4]; u64 v_c4 = m389[5]; u64 v_c41 = m389[6];
            slog::join_probe_old<3,2>(st_diffindex371, st_diffdelta374, std::array<u64,3>{v_c6, v_c41, 0}, [&](const std::array<u64,3>& m390) {
              u64 v_c82 = m390[2];
              slog::join_probe<2,1>(st_diff_ansindex372, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m391) {
                u64 v_c10 = m391[1];
                ++_fires;
                if (!(is_int(v_c4)))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c77, v_c78, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                if (!(is_int(v_c3)))
                {
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c76, v_c79, v_c80, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c4, v_c3, v_c10, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask375* _cont = new ReadTask375(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask375(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan $sup9688x90x0x0x0 __t3j4h490 k l m p r) (body (exists st_del (0 2 1) 2 __t3j4h490 k) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 r k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4hkT489) (join-old st_del (0 2 1) 3 (0 2 1) __t3j4h490 k __t4hkT489) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8CKV493) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join st_del_ans (0 1) 2 __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask412 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex392;  slog::Index** st_bldindex393;  slog::Index** st_mskindex394;  slog::Index** st_msk_ansindex395;  slog::Index** st_delindex396;  slog::Index** pbranchindex397;  slog::Index** st_delindex398;  slog::Index** st_bldindex399;  slog::Index** st_del_ansindex400;  slog::Index** st_bld_ansindex401;  slog::Index** st_mskindex402;  slog::Index** st_msk_ansindex403;  slog::Index** st_delindex404;  slog::Index** st_del_ansindex405;  slog::Index** st_bld_ansindex406;  slog::Index** pbranchdelta407;  slog::Index** st_deldelta408;  slog::Index** st_blddelta409;  slog::Index** st_mskdelta410;  slog::Index** st_deldelta411;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("st_del_ans");
      head_index[0] = readrel414->getIndex(ord413, false);
      outer_rel = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord415({0, 2, 1});
      slog::Relation* readrel416 = db->getRelation("st_del");
      st_delindex392 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 3, 4, 0});
      slog::Relation* readrel418 = db->getRelation("st_bld");
      st_bldindex393 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("st_msk");
      st_mskindex394 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 0});
      slog::Relation* readrel422 = db->getRelation("st_msk_ans");
      st_msk_ansindex395 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("st_del");
      st_delindex396 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 2, 3, 4, 0});
      slog::Relation* readrel426 = db->getRelation("pbranch");
      pbranchindex397 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 3, 4, 0});
      slog::Relation* readrel428 = db->getRelation("pbranch");
      pbranchdelta407 = readrel428->getIndex(ord427, true);
      std::vector<u16> ord429({0, 2, 1});
      slog::Relation* readrel430 = db->getRelation("st_del");
      st_delindex398 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 2, 1});
      slog::Relation* readrel432 = db->getRelation("st_del");
      st_deldelta408 = readrel432->getIndex(ord431, true);
      std::vector<u16> ord433({1, 2, 3, 4, 0});
      slog::Relation* readrel434 = db->getRelation("st_bld");
      st_bldindex399 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 3, 4, 0});
      slog::Relation* readrel436 = db->getRelation("st_bld");
      st_blddelta409 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({1, 0});
      slog::Relation* readrel438 = db->getRelation("st_del_ans");
      st_del_ansindex400 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("st_bld_ans");
      st_bld_ansindex401 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("st_msk");
      st_mskindex402 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("st_msk");
      st_mskdelta410 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("st_msk_ans");
      st_msk_ansindex403 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("st_del");
      st_delindex404 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 2, 0});
      slog::Relation* readrel450 = db->getRelation("st_del");
      st_deldelta411 = readrel450->getIndex(ord449, true);
      std::vector<u16> ord451({0, 1});
      slog::Relation* readrel452 = db->getRelation("st_del_ans");
      st_del_ansindex405 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 1});
      slog::Relation* readrel454 = db->getRelation("st_bld_ans");
      st_bld_ansindex406 = readrel454->getIndex(ord453, false);
  
    }
    ReadTask412(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c7 = _t[5];
        if (!slog::exists_probe<3,2>(st_delindex392, std::array<u64,3>{v_c84, v_c2, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex393, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex394, std::array<u64,3>{v_c2, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex395, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,2>(st_delindex396, std::array<u64,3>{v_c7, v_c2, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex397, pbranchdelta407, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m455) {
          u64 v_c85 = m455[4];
          slog::join_probe_old<3,3>(st_delindex398, st_deldelta408, std::array<u64,3>{v_c84, v_c2, v_c85}, [&](const std::array<u64,3>& m456) {
            slog::join_probe_old<5,3>(st_bldindex399, st_blddelta409, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0}, [&](const std::array<u64,5>& m457) {
              u64 v_c10 = m457[3]; u64 v_c86 = m457[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex400, std::array<u64,2>{v_c10, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex401, std::array<u64,2>{v_c86, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex402, st_mskdelta410, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m458) {
                u64 v_c87 = m458[2];
                slog::join_probe<2,2>(st_msk_ansindex403, std::array<u64,2>{v_c87, v_c4}, [&](const std::array<u64,2>& m459) {
                  slog::join_probe_old<3,2>(st_delindex404, st_deldelta411, std::array<u64,3>{v_c7, v_c2, 0}, [&](const std::array<u64,3>& m460) {
                    u64 v_c88 = m460[2];
                    slog::join_probe<2,2>(st_del_ansindex405, std::array<u64,2>{v_c88, v_c10}, [&](const std::array<u64,2>& m461) {
                      slog::join_probe<2,1>(st_bld_ansindex406, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m462) {
                        u64 v_c12 = m462[1];
                        u64 v_c89 = _prim_band(db, v_c2, v_c3);
                        if (v_c89 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c90 = _prim_gt(db, v_c89, v_c83);
                        if (v_c90 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c90) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:$sup9688x90x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask412* _cont = new ReadTask412(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask412(db,b), false);
  // (crule (pre) (scan $sup9688x110x0x0x0 __t1PdV132 l m n p q r __t9DTf133 __t972J134 u v) (body (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t9DTf133) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t972J134) (exists st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (exists st_msk (1 2 0) 2 q m) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t9DTf133 q __t972J134 __t744h135) (join-old st_union (0 1 2) 3 (0 1 2) __t1PdV132 __t9DTf133 __t972J134) (exists st_join_ans (0 1) 1 __t744h135) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask479 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex464;  slog::Index** pbranchindex465;  slog::Index** st_unionindex466;  slog::Index** st_mskindex467;  slog::Index** st_joinindex468;  slog::Index** st_unionindex469;  slog::Index** st_join_ansindex470;  slog::Index** st_mskindex471;  slog::Index** st_msk_ansindex472;  slog::Index** st_join_ansindex473;  slog::Index** pbranchdelta474;  slog::Index** pbranchdelta475;  slog::Index** st_joindelta476;  slog::Index** st_uniondelta477;  slog::Index** st_mskdelta478;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("st_union_ans");
      head_index[0] = readrel481->getIndex(ord480, false);
      outer_rel = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord482({1, 2, 3, 4, 0});
      slog::Relation* readrel483 = db->getRelation("pbranch");
      pbranchindex464 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 3, 4, 0});
      slog::Relation* readrel485 = db->getRelation("pbranch");
      pbranchdelta474 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({1, 2, 3, 4, 0});
      slog::Relation* readrel487 = db->getRelation("pbranch");
      pbranchindex465 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 3, 4, 0});
      slog::Relation* readrel489 = db->getRelation("pbranch");
      pbranchdelta475 = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({0, 1, 2});
      slog::Relation* readrel491 = db->getRelation("st_union");
      st_unionindex466 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("st_msk");
      st_mskindex467 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({1, 2, 3, 4, 0});
      slog::Relation* readrel495 = db->getRelation("st_join");
      st_joinindex468 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({1, 2, 3, 4, 0});
      slog::Relation* readrel497 = db->getRelation("st_join");
      st_joindelta476 = readrel497->getIndex(ord496, true);
      std::vector<u16> ord498({0, 1, 2});
      slog::Relation* readrel499 = db->getRelation("st_union");
      st_unionindex469 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 1, 2});
      slog::Relation* readrel501 = db->getRelation("st_union");
      st_uniondelta477 = readrel501->getIndex(ord500, true);
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("st_join_ans");
      st_join_ansindex470 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("st_msk");
      st_mskindex471 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("st_msk");
      st_mskdelta478 = readrel507->getIndex(ord506, true);
      std::vector<u16> ord508({0, 1});
      slog::Relation* readrel509 = db->getRelation("st_msk_ans");
      st_msk_ansindex472 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({0, 1});
      slog::Relation* readrel511 = db->getRelation("st_join_ans");
      st_join_ansindex473 = readrel511->getIndex(ord510, false);
  
    }
    ReadTask479(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c91 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c54 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c92 = _t[7];
        u64 v_c93 = _t[8];
        u64 v_c41 = _t[9];
        u64 v_c42 = _t[10];
        u64 v_c94 = _prim_lt(db, v_c53, v_c3);
        if (v_c94 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
        if (!v_c94) return;
        slog::join_probe_old<5,5>(pbranchindex464, pbranchdelta474, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, v_c92}, [&](const std::array<u64,5>& m513) {
          slog::join_probe_old<5,5>(pbranchindex465, pbranchdelta475, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, v_c93}, [&](const std::array<u64,5>& m514) {
            if (!slog::exists_probe<3,3>(st_unionindex466, std::array<u64,3>{v_c91, v_c92, v_c93})) return;
            if (!slog::exists_probe<3,2>(st_mskindex467, std::array<u64,3>{v_c54, v_c3, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex468, st_joindelta476, std::array<u64,5>{v_c4, v_c92, v_c54, v_c93, 0}, [&](const std::array<u64,5>& m515) {
              u64 v_c95 = m515[4];
              slog::join_probe_old<3,3>(st_unionindex469, st_uniondelta477, std::array<u64,3>{v_c91, v_c92, v_c93}, [&](const std::array<u64,3>& m516) {
                if (!slog::exists_probe<2,1>(st_join_ansindex470, std::array<u64,2>{v_c95, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex471, st_mskdelta478, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m517) {
                  u64 v_c96 = m517[2];
                  slog::join_probe<2,1>(st_msk_ansindex472, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m518) {
                    u64 v_c10 = m518[1];
                    if (v_c4 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex473, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m519) {
                      u64 v_c12 = m519[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c91, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:$sup9688x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask479* _cont = new ReadTask479(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask479(db,b), false);
  // (crule (pre) (scan pbranch __t8STz237 q n u v) (body (exists st_join (3 4 0 1 2) 2 q __t8STz237) (exists st_union (2 0 1) 1 __t8STz237) (exists st_msk (2 0 1) 1 n) (join $sup9688x120x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t8STz237 u v __t3tZ8235 l m p r __t7ZZP236) (cmp lt m n) (join pbranch (1 2 3 4 0) 5 p m l r __t7ZZP236) (exists st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_msk (1 2 0) 2 p n) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t7ZZP236 q __t8STz237 __t1ZYa238) (join st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_join_ans (0 1) 1 __t1ZYa238) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (neq q __v0) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask535 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex520;  slog::Index** st_unionindex521;  slog::Index** st_mskindex522;  slog::Index** $sup9688x120x0x0x0index523;  slog::Index** pbranchindex524;  slog::Index** st_unionindex525;  slog::Index** st_mskindex526;  slog::Index** st_joinindex527;  slog::Index** st_unionindex528;  slog::Index** st_join_ansindex529;  slog::Index** st_mskindex530;  slog::Index** st_msk_ansindex531;  slog::Index** st_join_ansindex532;  slog::Index** st_joindelta533;  slog::Index** st_mskdelta534;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("st_union_ans");
      head_index[0] = readrel537->getIndex(ord536, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord538({3, 4, 0, 1, 2});
      slog::Relation* readrel539 = db->getRelation("st_join");
      st_joinindex520 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({2, 0, 1});
      slog::Relation* readrel541 = db->getRelation("st_union");
      st_unionindex521 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({2, 0, 1});
      slog::Relation* readrel543 = db->getRelation("st_msk");
      st_mskindex522 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel545 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index523 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 3, 4, 0});
      slog::Relation* readrel547 = db->getRelation("pbranch");
      pbranchindex524 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({0, 1, 2});
      slog::Relation* readrel549 = db->getRelation("st_union");
      st_unionindex525 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 2, 0});
      slog::Relation* readrel551 = db->getRelation("st_msk");
      st_mskindex526 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 3, 4, 0});
      slog::Relation* readrel553 = db->getRelation("st_join");
      st_joinindex527 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 3, 4, 0});
      slog::Relation* readrel555 = db->getRelation("st_join");
      st_joindelta533 = readrel555->getIndex(ord554, true);
      std::vector<u16> ord556({0, 1, 2});
      slog::Relation* readrel557 = db->getRelation("st_union");
      st_unionindex528 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({0, 1});
      slog::Relation* readrel559 = db->getRelation("st_join_ans");
      st_join_ansindex529 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 0});
      slog::Relation* readrel561 = db->getRelation("st_msk");
      st_mskindex530 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 0});
      slog::Relation* readrel563 = db->getRelation("st_msk");
      st_mskdelta534 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({0, 1});
      slog::Relation* readrel565 = db->getRelation("st_msk_ans");
      st_msk_ansindex531 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1});
      slog::Relation* readrel567 = db->getRelation("st_join_ans");
      st_join_ansindex532 = readrel567->getIndex(ord566, false);
  
    }
    ReadTask535(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c97 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c53 = _t[2];
        u64 v_c41 = _t[3];
        u64 v_c42 = _t[4];
        if (!slog::exists_probe<5,2>(st_joinindex520, std::array<u64,5>{v_c54, v_c97, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex521, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex522, std::array<u64,3>{v_c53, 0, 0})) return;
        slog::join_probe<11,5>($sup9688x120x0x0x0index523, std::array<u64,11>{v_c53, v_c54, v_c97, v_c41, v_c42, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m568) {
          u64 v_c98 = m568[5]; u64 v_c6 = m568[6]; u64 v_c3 = m568[7]; u64 v_c4 = m568[8]; u64 v_c7 = m568[9]; u64 v_c99 = m568[10];
          u64 v_c100 = _prim_lt(db, v_c3, v_c53);
          if (v_c100 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
          if (!v_c100) return;
          slog::join_probe<5,5>(pbranchindex524, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, v_c99}, [&](const std::array<u64,5>& m570) {
            if (!slog::exists_probe<3,3>(st_unionindex525, std::array<u64,3>{v_c98, v_c99, v_c97})) return;
            if (!slog::exists_probe<3,2>(st_mskindex526, std::array<u64,3>{v_c4, v_c53, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex527, st_joindelta533, std::array<u64,5>{v_c4, v_c99, v_c54, v_c97, 0}, [&](const std::array<u64,5>& m571) {
              u64 v_c101 = m571[4];
              slog::join_probe<3,3>(st_unionindex528, std::array<u64,3>{v_c98, v_c99, v_c97}, [&](const std::array<u64,3>& m572) {
                if (!slog::exists_probe<2,1>(st_join_ansindex529, std::array<u64,2>{v_c101, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex530, st_mskdelta534, std::array<u64,3>{v_c4, v_c53, 0}, [&](const std::array<u64,3>& m573) {
                  u64 v_c102 = m573[2];
                  slog::join_probe<2,1>(st_msk_ansindex531, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m574) {
                    u64 v_c10 = m574[1];
                    if (v_c54 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex532, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m575) {
                      u64 v_c12 = m575[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c98, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask535* _cont = new ReadTask535(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask535(db,b), false);
  // (crule (pre) (scan st_msk_ans __t1TTr141 q) (body (exists $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t1TTr141 p n) (join $sup9688x114x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t1TTr141 l m n p q r v)) set.slog:115 #f)
  class ReadTask580 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x0index576;  slog::Index** st_mskindex577;  slog::Index** $sup9688x114x0x0x0index578;  slog::Index** st_mskdelta579;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord581({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel582 = db->getRelation("$sup9688x114x0x0x1");
      head_index[0] = readrel582->getIndex(ord581, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord583({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel584 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index576 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1, 2});
      slog::Relation* readrel586 = db->getRelation("st_msk");
      st_mskindex577 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1, 2});
      slog::Relation* readrel588 = db->getRelation("st_msk");
      st_mskdelta579 = readrel588->getIndex(ord587, true);
      std::vector<u16> ord589({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel590 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index578 = readrel590->getIndex(ord589, false);
  
    }
    ReadTask580(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x114x0x0x0index576, std::array<u64,9>{v_c54, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex577, st_mskdelta579, std::array<u64,3>{v_c103, 0, 0}, [&](const std::array<u64,3>& m591) {
          u64 v_c4 = m591[1]; u64 v_c53 = m591[2];
          slog::join_probe<9,3>($sup9688x114x0x0x0index578, std::array<u64,9>{v_c53, v_c4, v_c54, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m592) {
            u64 v_c19 = m592[3]; u64 v_c6 = m592[4]; u64 v_c3 = m592[5]; u64 v_c7 = m592[6]; u64 v_c41 = m592[7]; u64 v_c42 = m592[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c19, v_c41, v_c103, v_c6, v_c3, v_c53, v_c4, v_c54, v_c7, v_c42}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask580* _cont = new ReadTask580(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask580(db,b), false);
  // (crule (pre) (scan pbranch __t2p3i100 p m l r) (body (exists pbranch (2 0 1 3 4) 1 m) (join st_union (1 2 0) 1 __t2p3i100 __t9Qes101 __t419y99) (join-old pbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t9Qes101 q u v) (neq p q)) (head (mkstruct st_join (1 2 3 4 0) __7vjT940 p __t2p3i100 q __t9Qes101)) set.slog:125 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex593;  slog::Index** st_unionindex594;  slog::Index** pbranchindex595;  slog::Index** pbranchdelta596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord598({2, 0, 1, 3, 4});
      slog::Relation* readrel599 = db->getRelation("pbranch");
      pbranchindex593 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 2, 0});
      slog::Relation* readrel601 = db->getRelation("st_union");
      st_unionindex594 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({2, 0, 1, 3, 4});
      slog::Relation* readrel603 = db->getRelation("pbranch");
      pbranchindex595 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({2, 0, 1, 3, 4});
      slog::Relation* readrel605 = db->getRelation("pbranch");
      pbranchdelta596 = readrel605->getIndex(ord604, true);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c104 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex593, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(st_unionindex594, std::array<u64,3>{v_c104, 0, 0}, [&](const std::array<u64,3>& m606) {
          u64 v_c105 = m606[1]; u64 v_c106 = m606[2];
          slog::join_probe_old<5,2>(pbranchindex595, pbranchdelta596, std::array<u64,5>{v_c3, v_c105, 0, 0, 0}, [&](const std::array<u64,5>& m607) {
            u64 v_c54 = m607[2]; u64 v_c41 = m607[3]; u64 v_c42 = m607[4];
            if (v_c4 == v_c54) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c4, v_c104, v_c54, v_c105}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask597* _cont = new ReadTask597(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask597(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan $sup9688x142x0x0x0 __d0 l m n p q r u v) (body (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3eTQ549) (exists st_diff (1 2 0) 2 r __t3eTQ549) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t3ZZb548) (join-old st_msk_ans (0 1) 2 (0 1) __t3ZZb548 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t3eTQ549 __t7sr4550) (join-old st_diff_ans (0 1) 1 (0 1) __t7sr4550 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask625 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex608;  slog::Index** st_msk_ansindex609;  slog::Index** st_diffindex610;  slog::Index** pbranchindex611;  slog::Index** st_diffindex612;  slog::Index** st_mskindex613;  slog::Index** st_msk_ansindex614;  slog::Index** st_diffindex615;  slog::Index** st_diff_ansindex616;  slog::Index** pbranchdelta617;  slog::Index** st_mskdelta618;  slog::Index** st_msk_ansdelta619;  slog::Index** st_diffdelta620;  slog::Index** st_diff_ansdelta621;
    u32 sid623;  u32 sid622;  u32 sid624;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("st_msk");
      st_mskindex608 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 0});
      slog::Relation* readrel629 = db->getRelation("st_msk_ans");
      st_msk_ansindex609 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("st_diff");
      st_diffindex610 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 3, 4, 0});
      slog::Relation* readrel633 = db->getRelation("pbranch");
      pbranchindex611 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 3, 4, 0});
      slog::Relation* readrel635 = db->getRelation("pbranch");
      pbranchdelta617 = readrel635->getIndex(ord634, true);
      std::vector<u16> ord636({1, 2, 0});
      slog::Relation* readrel637 = db->getRelation("st_diff");
      st_diffindex612 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 2, 0});
      slog::Relation* readrel639 = db->getRelation("st_msk");
      st_mskindex613 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("st_msk");
      st_mskdelta618 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("st_msk_ans");
      st_msk_ansindex614 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("st_msk_ans");
      st_msk_ansdelta619 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({1, 2, 0});
      slog::Relation* readrel647 = db->getRelation("st_diff");
      st_diffindex615 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("st_diff");
      st_diffdelta620 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("st_diff_ans");
      st_diff_ansindex616 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("st_diff_ans");
      st_diff_ansdelta621 = readrel653->getIndex(ord652, true);
      sid623 = db->getRelation("_enum")->getStructId();
      sid622 = db->getRelation("pbranch")->getStructId();
      sid624 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask625(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const81906d9241165d9f6a541e47;
      u64 v_c108 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c109 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c54 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c41 = _t[7];
        u64 v_c42 = _t[8];
        if (!slog::exists_probe<3,2>(st_mskindex608, std::array<u64,3>{v_c54, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex609, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex610, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex611, pbranchdelta617, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m654) {
          u64 v_c110 = m654[4];
          if (!slog::exists_probe<3,2>(st_diffindex612, std::array<u64,3>{v_c7, v_c110, 0})) return;
          slog::join_probe_old<3,2>(st_mskindex613, st_mskdelta618, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m655) {
            u64 v_c111 = m655[2];
            slog::join_probe_old<2,2>(st_msk_ansindex614, st_msk_ansdelta619, std::array<u64,2>{v_c111, v_c4}, [&](const std::array<u64,2>& m656) {
              slog::join_probe_old<3,2>(st_diffindex615, st_diffdelta620, std::array<u64,3>{v_c7, v_c110, 0}, [&](const std::array<u64,3>& m657) {
                u64 v_c112 = m657[2];
                slog::join_probe_old<2,1>(st_diff_ansindex616, st_diff_ansdelta621, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m658) {
                  u64 v_c10 = m658[1];
                  ++_fires;
                  if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid622 || decode_struct_id(v_c6) == sid623 || decode_struct_id(v_c6) == sid624))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c107, v_c108, v_c109, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:$sup9688x142x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask625* _cont = new ReadTask625(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask625(db,b), false);
  // (crule (pre) (scan $sup9688x40x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join st_hsb_ans (0 1) 0 __t81zv171 __v3) (join st_hsb_ans (0 1) 1 __t81zv171 __v1) (let __t7IWy172 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t81zv171 __t7IWy172)) (head (emit $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t81zv171 __t81zv171 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask663 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex659;  slog::Index** st_hsb_ansindex660;  slog::Index** st_hsbindex661;  slog::Index** st_hsbdelta662;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord664({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel665 = db->getRelation("$sup9688x40x0x0x2");
      head_index[0] = readrel665->getIndex(ord664, false);
      outer_rel = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex659 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex660 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({0, 1});
      slog::Relation* readrel671 = db->getRelation("st_hsb");
      st_hsbindex661 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1});
      slog::Relation* readrel673 = db->getRelation("st_hsb");
      st_hsbdelta662 = readrel673->getIndex(ord672, true);
  
    }
    ReadTask663(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c20 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c22 = _t[6];
        slog::join_all<2>(st_hsb_ansindex659, [&](const std::array<u64,2>& m674) {
          u64 v_c113 = m674[0]; u64 v_c38 = m674[1];
          slog::join_probe<2,1>(st_hsb_ansindex660, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m675) {
            u64 v_c37 = m675[1];
            u64 v_c114 = _prim_bxor(db, v_c18, v_c20);
            if (v_c114 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            slog::join_probe_old<2,2>(st_hsbindex661, st_hsbdelta662, std::array<u64,2>{v_c113, v_c114}, [&](const std::array<u64,2>& m676) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c34, v_c10, v_c38, v_c37, v_c19, v_c113, v_c113, v_c18, v_c20, v_c21, v_c22}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask663* _cont = new ReadTask663(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask663(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan st_msk __t57zq262 k m) (body (exists $sup9688x52x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_ins (2 0 1) 1 k) (exists st_msk_ans (0 1) 1 __t57zq262) (join $sup9688x52x0x0x1 (1 2 4 5 0 3 6) 3 __t57zq262 k m p __t7CbB259 l r) (join $sup9688x52x0x0x0 (4 2 3 5 0 1) 6 p l m r __t7CbB259 k) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_msk_ans (0 1) 2 __t57zq262 p) (exists st_ins (1 2 0) 2 r k) (join pbranch (1 2 3 4 0) 4 p m l r __t0vi9258) (join st_ins (0 2 1) 3 __t7CbB259 k __t0vi9258) (join st_msk_ans (0 1) 2 __t57zq262 p) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask692 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x0index677;  slog::Index** pbranchindex678;  slog::Index** st_insindex679;  slog::Index** st_msk_ansindex680;  slog::Index** $sup9688x52x0x0x1index681;  slog::Index** $sup9688x52x0x0x0index682;  slog::Index** st_insindex683;  slog::Index** st_msk_ansindex684;  slog::Index** st_insindex685;  slog::Index** pbranchindex686;  slog::Index** st_insindex687;  slog::Index** st_msk_ansindex688;  slog::Index** st_insindex689;  slog::Index** st_ins_ansindex690;  slog::Index** st_insdelta691;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord693({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel694 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index677 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({2, 0, 1, 3, 4});
      slog::Relation* readrel696 = db->getRelation("pbranch");
      pbranchindex678 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({2, 0, 1});
      slog::Relation* readrel698 = db->getRelation("st_ins");
      st_insindex679 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("st_msk_ans");
      st_msk_ansindex680 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel702 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index681 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel704 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index682 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 2, 1});
      slog::Relation* readrel706 = db->getRelation("st_ins");
      st_insindex683 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("st_msk_ans");
      st_msk_ansindex684 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("st_ins");
      st_insindex685 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 3, 4, 0});
      slog::Relation* readrel712 = db->getRelation("pbranch");
      pbranchindex686 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({0, 2, 1});
      slog::Relation* readrel714 = db->getRelation("st_ins");
      st_insindex687 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("st_msk_ans");
      st_msk_ansindex688 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("st_ins");
      st_insindex689 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 0});
      slog::Relation* readrel720 = db->getRelation("st_ins");
      st_insdelta691 = readrel720->getIndex(ord719, true);
      std::vector<u16> ord721({0, 1});
      slog::Relation* readrel722 = db->getRelation("st_ins_ans");
      st_ins_ansindex690 = readrel722->getIndex(ord721, false);
  
    }
    ReadTask692(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x52x0x0x0index677, std::array<u64,6>{v_c2, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex678, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex679, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex680, std::array<u64,2>{v_c116, 0})) return;
        slog::join_probe<7,3>($sup9688x52x0x0x1index681, std::array<u64,7>{v_c116, v_c2, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,7>& m723) {
          u64 v_c4 = m723[3]; u64 v_c117 = m723[4]; u64 v_c6 = m723[5]; u64 v_c7 = m723[6];
          slog::join_probe<6,6>($sup9688x52x0x0x0index682, std::array<u64,6>{v_c4, v_c6, v_c3, v_c7, v_c117, v_c2}, [&](const std::array<u64,6>& m724) {
            if (!slog::exists_probe<3,2>(st_insindex683, std::array<u64,3>{v_c117, v_c2, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex684, std::array<u64,2>{v_c116, v_c4})) return;
            if (!slog::exists_probe<3,2>(st_insindex685, std::array<u64,3>{v_c7, v_c2, 0})) return;
            slog::join_probe<5,4>(pbranchindex686, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m725) {
              u64 v_c118 = m725[4];
              slog::join_probe<3,3>(st_insindex687, std::array<u64,3>{v_c117, v_c2, v_c118}, [&](const std::array<u64,3>& m726) {
                slog::join_probe<2,2>(st_msk_ansindex688, std::array<u64,2>{v_c116, v_c4}, [&](const std::array<u64,2>& m727) {
                  slog::join_probe_old<3,2>(st_insindex689, st_insdelta691, std::array<u64,3>{v_c7, v_c2, 0}, [&](const std::array<u64,3>& m728) {
                    u64 v_c119 = m728[2];
                    slog::join_probe<2,1>(st_ins_ansindex690, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m729) {
                      u64 v_c10 = m729[1];
                      u64 v_c120 = _prim_band(db, v_c2, v_c3);
                      if (v_c120 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c121 = _prim_gt(db, v_c120, v_c115);
                      if (v_c121 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c121) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c117, v_c10, v_c6, v_c3, v_c4});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask692* _cont = new ReadTask692(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask692(db,b), false);
  // (crule (pre (let __tconst6z9n537 const5feceb66ffc86f38d952786c)) (scan st_diff __t7CyZ536 __t3erE535 __t1Xgc534) (body (join pbranch (0 1 2 3 4) 1 __t1Xgc534 q n u v) (join pbranch (0 1 2 3 4) 1 __t3erE535 p m l r) (cmp lt m n) (let __t0JvE538 (band p n)) (cmp gt __t0JvE538 __tconst6z9n537)) (head (emit $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) __t7CyZ536 v l m n p q r u)) set.slog:152 #f)
  class ReadTask733 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex731;  slog::Index** pbranchindex732;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord734({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel735 = db->getRelation("$sup9688x151x0x0x0");
      head_index[0] = readrel735->getIndex(ord734, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord736({0, 1, 2, 3, 4});
      slog::Relation* readrel737 = db->getRelation("pbranch");
      pbranchindex731 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 1, 2, 3, 4});
      slog::Relation* readrel739 = db->getRelation("pbranch");
      pbranchindex732 = readrel739->getIndex(ord738, false);
  
    }
    ReadTask733(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c123 = _t[0];
        u64 v_c124 = _t[1];
        u64 v_c125 = _t[2];
        slog::join_probe<5,1>(pbranchindex731, std::array<u64,5>{v_c125, 0, 0, 0, 0}, [&](const std::array<u64,5>& m740) {
          u64 v_c54 = m740[1]; u64 v_c53 = m740[2]; u64 v_c41 = m740[3]; u64 v_c42 = m740[4];
          slog::join_probe<5,1>(pbranchindex732, std::array<u64,5>{v_c124, 0, 0, 0, 0}, [&](const std::array<u64,5>& m741) {
            u64 v_c4 = m741[1]; u64 v_c3 = m741[2]; u64 v_c6 = m741[3]; u64 v_c7 = m741[4];
            u64 v_c126 = _prim_lt(db, v_c3, v_c53);
            if (v_c126 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c126) return;
            u64 v_c127 = _prim_band(db, v_c4, v_c53);
            if (v_c127 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            u64 v_c128 = _prim_gt(db, v_c127, v_c122);
            if (v_c128 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c128) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c123, v_c42, v_c6, v_c3, v_c53, v_c4, v_c54, v_c7, v_c41}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask733* _cont = new ReadTask733(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask733(db,b), false);
  // (crule (pre) (scan pbranch __t8pVe147 p m l r) (body (exists st_diff (1 2 0) 1 __t8pVe147) (exists st_msk (2 0 1) 1 m) (join $sup9688x145x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t3Vft148 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t3Vft148 __t8pVe147) (exists st_msk (1 2 0) 2 q m) (join pbranch (1 2 3 4 0) 4 q n u v __t0w8p146) (join-old st_diff (0 1 2) 3 (0 1 2) __t3Vft148 __t8pVe147 __t0w8p146) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t7gQz149) (join st_msk_ans (0 1) 1 __t7gQz149 __v0) (neq p __v0)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask755 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex744;  slog::Index** st_mskindex745;  slog::Index** $sup9688x145x0x0x0index746;  slog::Index** st_diffindex747;  slog::Index** st_mskindex748;  slog::Index** pbranchindex749;  slog::Index** st_diffindex750;  slog::Index** st_mskindex751;  slog::Index** st_msk_ansindex752;  slog::Index** st_diffdelta753;  slog::Index** st_mskdelta754;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord756({0, 1});
      slog::Relation* readrel757 = db->getRelation("st_diff_ans");
      head_index[0] = readrel757->getIndex(ord756, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("st_diff");
      st_diffindex744 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({2, 0, 1});
      slog::Relation* readrel761 = db->getRelation("st_msk");
      st_mskindex745 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel763 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index746 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("st_diff");
      st_diffindex747 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 0});
      slog::Relation* readrel767 = db->getRelation("st_msk");
      st_mskindex748 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 2, 3, 4, 0});
      slog::Relation* readrel769 = db->getRelation("pbranch");
      pbranchindex749 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1, 2});
      slog::Relation* readrel771 = db->getRelation("st_diff");
      st_diffindex750 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 1, 2});
      slog::Relation* readrel773 = db->getRelation("st_diff");
      st_diffdelta753 = readrel773->getIndex(ord772, true);
      std::vector<u16> ord774({1, 2, 0});
      slog::Relation* readrel775 = db->getRelation("st_msk");
      st_mskindex751 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("st_msk");
      st_mskdelta754 = readrel777->getIndex(ord776, true);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("st_msk_ans");
      st_msk_ansindex752 = readrel779->getIndex(ord778, false);
  
    }
    ReadTask755(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c129 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex744, std::array<u64,3>{v_c129, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex745, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x145x0x0x0index746, std::array<u64,9>{v_c6, v_c3, v_c4, v_c7, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m780) {
          u64 v_c130 = m780[4]; u64 v_c53 = m780[5]; u64 v_c54 = m780[6]; u64 v_c41 = m780[7]; u64 v_c42 = m780[8];
          u64 v_c131 = _prim_lt(db, v_c53, v_c3);
          if (v_c131 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
          if (!v_c131) return;
          if (!slog::exists_probe<3,2>(st_diffindex747, std::array<u64,3>{v_c130, v_c129, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex748, std::array<u64,3>{v_c54, v_c3, 0})) return;
          slog::join_probe<5,4>(pbranchindex749, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m782) {
            u64 v_c132 = m782[4];
            slog::join_probe_old<3,3>(st_diffindex750, st_diffdelta753, std::array<u64,3>{v_c130, v_c129, v_c132}, [&](const std::array<u64,3>& m783) {
              slog::join_probe_old<3,2>(st_mskindex751, st_mskdelta754, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m784) {
                u64 v_c133 = m784[2];
                slog::join_probe<2,1>(st_msk_ansindex752, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m785) {
                  u64 v_c10 = m785[1];
                  if (v_c4 == v_c10) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c130, v_c129}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask755* _cont = new ReadTask755(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask755(db,b), false);
  // (crule (pre (let __tconst34xN821 conste3776bfed7f405de8017ecfa)) (scan st_bld __t3cRW37 p m l __t6aGB36) (body (join _enum (0 1) 2 __t6aGB36 __tconst34xN821)) (head (emit st_bld_ans (0 1) __t3cRW37 l)) set.slog:79 #f)
  class ReadTask787 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex786;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_bld_ans");
      std::vector<u16> ord788({0, 1});
      slog::Relation* readrel789 = db->getRelation("st_bld_ans");
      head_index[0] = readrel789->getIndex(ord788, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord790({0, 1});
      slog::Relation* readrel791 = db->getRelation("_enum");
      _enumindex786 = readrel791->getIndex(ord790, false);
  
    }
    ReadTask787(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c135 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c136 = _t[4];
        slog::join_probe<2,2>(_enumindex786, std::array<u64,2>{v_c136, v_c134}, [&](const std::array<u64,2>& m792) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c135, v_c6}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:79", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask787* _cont = new ReadTask787(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask787(db,b), false);
  // (crule (pre) (scan temp76Kg1410 __t9uxT138) (body) (head (mkstruct st_hsb (1 0) __0RbW719 __t9uxT138)) set.slog:29 #f)
  class ReadTask793 : public slog::Task
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
      outer_rel = db->getRelation("temp76Kg1410");
  
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
        u64 v_c137 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:temp76Kg1410", _fires);
  
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
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan $sup9688x52x0x0x0 __t7CbB259 k l m p r) (body (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 2 r k) (join-old $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 6 (3 4 5 6 0 2 1) l m p r __t7CbB259 k __t57zq262) (exists st_msk (1 2 0) 3 k m __t57zq262) (exists st_msk_ans (0 1) 2 __t57zq262 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0vi9258) (join-old st_ins (0 2 1) 3 (0 2 1) __t7CbB259 k __t0vi9258) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask813 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex794;  slog::Index** st_insindex795;  slog::Index** st_mskindex796;  slog::Index** st_msk_ansindex797;  slog::Index** st_insindex798;  slog::Index** $sup9688x52x0x0x1index799;  slog::Index** st_mskindex800;  slog::Index** st_msk_ansindex801;  slog::Index** pbranchindex802;  slog::Index** st_insindex803;  slog::Index** st_mskindex804;  slog::Index** st_msk_ansindex805;  slog::Index** st_insindex806;  slog::Index** st_ins_ansindex807;  slog::Index** $sup9688x52x0x0x1delta808;  slog::Index** pbranchdelta809;  slog::Index** st_insdelta810;  slog::Index** st_mskdelta811;  slog::Index** st_insdelta812;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord814({1, 2, 3, 4, 0});
      slog::Relation* readrel815 = db->getRelation("pbranch");
      pbranchindex794 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({0, 2, 1});
      slog::Relation* readrel817 = db->getRelation("st_ins");
      st_insindex795 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("st_msk");
      st_mskindex796 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 0});
      slog::Relation* readrel821 = db->getRelation("st_msk_ans");
      st_msk_ansindex797 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("st_ins");
      st_insindex798 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel825 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index799 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel827 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1delta808 = readrel827->getIndex(ord826, true);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("st_msk");
      st_mskindex800 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("st_msk_ans");
      st_msk_ansindex801 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 3, 4, 0});
      slog::Relation* readrel833 = db->getRelation("pbranch");
      pbranchindex802 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 3, 4, 0});
      slog::Relation* readrel835 = db->getRelation("pbranch");
      pbranchdelta809 = readrel835->getIndex(ord834, true);
      std::vector<u16> ord836({0, 2, 1});
      slog::Relation* readrel837 = db->getRelation("st_ins");
      st_insindex803 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({0, 2, 1});
      slog::Relation* readrel839 = db->getRelation("st_ins");
      st_insdelta810 = readrel839->getIndex(ord838, true);
      std::vector<u16> ord840({1, 2, 0});
      slog::Relation* readrel841 = db->getRelation("st_msk");
      st_mskindex804 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 0});
      slog::Relation* readrel843 = db->getRelation("st_msk");
      st_mskdelta811 = readrel843->getIndex(ord842, true);
      std::vector<u16> ord844({0, 1});
      slog::Relation* readrel845 = db->getRelation("st_msk_ans");
      st_msk_ansindex805 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("st_ins");
      st_insindex806 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 2, 0});
      slog::Relation* readrel849 = db->getRelation("st_ins");
      st_insdelta812 = readrel849->getIndex(ord848, true);
      std::vector<u16> ord850({0, 1});
      slog::Relation* readrel851 = db->getRelation("st_ins_ans");
      st_ins_ansindex807 = readrel851->getIndex(ord850, false);
  
    }
    ReadTask813(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c7 = _t[5];
        if (!slog::exists_probe<5,4>(pbranchindex794, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex795, std::array<u64,3>{v_c117, v_c2, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex796, std::array<u64,3>{v_c2, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex797, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex798, std::array<u64,3>{v_c7, v_c2, 0})) return;
        slog::join_probe_old<7,6>($sup9688x52x0x0x1index799, $sup9688x52x0x0x1delta808, std::array<u64,7>{v_c6, v_c3, v_c4, v_c7, v_c117, v_c2, 0}, [&](const std::array<u64,7>& m852) {
          u64 v_c116 = m852[6];
          if (!slog::exists_probe<3,3>(st_mskindex800, std::array<u64,3>{v_c2, v_c3, v_c116})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex801, std::array<u64,2>{v_c116, v_c4})) return;
          slog::join_probe_old<5,4>(pbranchindex802, pbranchdelta809, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m853) {
            u64 v_c118 = m853[4];
            slog::join_probe_old<3,3>(st_insindex803, st_insdelta810, std::array<u64,3>{v_c117, v_c2, v_c118}, [&](const std::array<u64,3>& m854) {
              slog::join_probe_old<3,3>(st_mskindex804, st_mskdelta811, std::array<u64,3>{v_c2, v_c3, v_c116}, [&](const std::array<u64,3>& m855) {
                slog::join_probe<2,2>(st_msk_ansindex805, std::array<u64,2>{v_c116, v_c4}, [&](const std::array<u64,2>& m856) {
                  slog::join_probe_old<3,2>(st_insindex806, st_insdelta812, std::array<u64,3>{v_c7, v_c2, 0}, [&](const std::array<u64,3>& m857) {
                    u64 v_c119 = m857[2];
                    slog::join_probe<2,1>(st_ins_ansindex807, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m858) {
                      u64 v_c10 = m858[1];
                      u64 v_c120 = _prim_band(db, v_c2, v_c3);
                      if (v_c120 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c138 = _prim_gt(db, v_c120, v_c115);
                      if (v_c138 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c138) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c117, v_c10, v_c6, v_c3, v_c4});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:$sup9688x52x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask813* _cont = new ReadTask813(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask813(db,b), false);
  // (crule (pre) (scan st_union __t0Mc03 __t66nq2 __t6Gju1) (body (join pbranch (0 1 2 3 4) 1 __t6Gju1 p m u v) (join pbranch (0 1 2 3 4) 3 __t66nq2 p m l r)) (head (emit $sup9688x100x0x0x0 (0 1 2 3 4 5 6) __t0Mc03 l m p r u v)) set.slog:101 #f)
  class ReadTask862 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex860;  slog::Index** pbranchindex861;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord863({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel864 = db->getRelation("$sup9688x100x0x0x0");
      head_index[0] = readrel864->getIndex(ord863, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord865({0, 1, 2, 3, 4});
      slog::Relation* readrel866 = db->getRelation("pbranch");
      pbranchindex860 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({0, 1, 2, 3, 4});
      slog::Relation* readrel868 = db->getRelation("pbranch");
      pbranchindex861 = readrel868->getIndex(ord867, false);
  
    }
    ReadTask862(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c140 = _t[1];
        u64 v_c141 = _t[2];
        slog::join_probe<5,1>(pbranchindex860, std::array<u64,5>{v_c141, 0, 0, 0, 0}, [&](const std::array<u64,5>& m869) {
          u64 v_c4 = m869[1]; u64 v_c3 = m869[2]; u64 v_c41 = m869[3]; u64 v_c42 = m869[4];
          slog::join_probe<5,3>(pbranchindex861, std::array<u64,5>{v_c140, v_c4, v_c3, 0, 0}, [&](const std::array<u64,5>& m870) {
            u64 v_c6 = m870[3]; u64 v_c7 = m870[4];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c139, v_c6, v_c3, v_c4, v_c7, v_c41, v_c42}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask862* _cont = new ReadTask862(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask862(db,b), false);
  // (crule (pre (let __tconst8SGO1124 conste3776bfed7f405de8017ecfa)) (scan st_union __t4IQ0405 __t1DuV404 t) (body (join _enum (0 1) 2 __t1DuV404 __tconst8SGO1124)) (head (emit st_union_ans (0 1) __t4IQ0405 t)) set.slog:96 #f)
  class ReadTask872 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex871;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord873({0, 1});
      slog::Relation* readrel874 = db->getRelation("st_union_ans");
      head_index[0] = readrel874->getIndex(ord873, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("_enum");
      _enumindex871 = readrel876->getIndex(ord875, false);
  
    }
    ReadTask872(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c143 = _t[0];
        u64 v_c144 = _t[1];
        u64 v_c145 = _t[2];
        slog::join_probe<2,2>(_enumindex871, std::array<u64,2>{v_c144, v_c142}, [&](const std::array<u64,2>& m877) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c143, v_c145}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:96", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask872* _cont = new ReadTask872(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask872(db,b), false);
  // (crule (pre) (scan st_msk __t9Q9j15 k m) (body (exists pleaf (1 0) 1 k) (exists st_join (1 2 3 4 0) 1 k) (exists $sup9688x54x0x0x0 (1 3 0 2 4 5 6) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_ins (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (join pleaf (1 0) 1 k __t4JtR13) (join st_join (1 2 3 4 0) 2 k __t4JtR13 p __t4iIu12 __t4hUr14) (neq p __v0) (exists pbranch (0 1 2 3 4) 3 __t4iIu12 p m) (exists st_ins (1 2 0) 2 __t4iIu12 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join $sup9688x54x0x0x0 (1 4 6 3 0 2 5) 4 k p __t4iIu12 m __t2YgE11 l r) (join pbranch (1 2 3 4 0) 5 p m l r __t4iIu12) (join st_ins (0 2 1) 3 __t2YgE11 k __t4iIu12) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask893 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex878;  slog::Index** st_joinindex879;  slog::Index** $sup9688x54x0x0x0index880;  slog::Index** pbranchindex881;  slog::Index** st_insindex882;  slog::Index** st_msk_ansindex883;  slog::Index** pleafindex884;  slog::Index** st_joinindex885;  slog::Index** pbranchindex886;  slog::Index** st_insindex887;  slog::Index** st_join_ansindex888;  slog::Index** $sup9688x54x0x0x0index889;  slog::Index** pbranchindex890;  slog::Index** st_insindex891;  slog::Index** st_join_ansindex892;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("st_ins_ans");
      head_index[0] = readrel895->getIndex(ord894, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord896({1, 0});
      slog::Relation* readrel897 = db->getRelation("pleaf");
      pleafindex878 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 2, 3, 4, 0});
      slog::Relation* readrel899 = db->getRelation("st_join");
      st_joinindex879 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 3, 0, 2, 4, 5, 6});
      slog::Relation* readrel901 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index880 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({2, 0, 1, 3, 4});
      slog::Relation* readrel903 = db->getRelation("pbranch");
      pbranchindex881 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({2, 0, 1});
      slog::Relation* readrel905 = db->getRelation("st_ins");
      st_insindex882 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1});
      slog::Relation* readrel907 = db->getRelation("st_msk_ans");
      st_msk_ansindex883 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 0});
      slog::Relation* readrel909 = db->getRelation("pleaf");
      pleafindex884 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 3, 4, 0});
      slog::Relation* readrel911 = db->getRelation("st_join");
      st_joinindex885 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({0, 1, 2, 3, 4});
      slog::Relation* readrel913 = db->getRelation("pbranch");
      pbranchindex886 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 0});
      slog::Relation* readrel915 = db->getRelation("st_ins");
      st_insindex887 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({0, 1});
      slog::Relation* readrel917 = db->getRelation("st_join_ans");
      st_join_ansindex888 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel919 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index889 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 2, 3, 4, 0});
      slog::Relation* readrel921 = db->getRelation("pbranch");
      pbranchindex890 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({0, 2, 1});
      slog::Relation* readrel923 = db->getRelation("st_ins");
      st_insindex891 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({0, 1});
      slog::Relation* readrel925 = db->getRelation("st_join_ans");
      st_join_ansindex892 = readrel925->getIndex(ord924, false);
  
    }
    ReadTask893(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<2,1>(pleafindex878, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<5,1>(st_joinindex879, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup9688x54x0x0x0index880, std::array<u64,7>{v_c2, v_c3, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex881, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex882, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex883, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m926) {
          u64 v_c10 = m926[1];
          slog::join_probe<2,1>(pleafindex884, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m927) {
            u64 v_c147 = m927[1];
            slog::join_probe<5,2>(st_joinindex885, std::array<u64,5>{v_c2, v_c147, 0, 0, 0}, [&](const std::array<u64,5>& m928) {
              u64 v_c4 = m928[2]; u64 v_c148 = m928[3]; u64 v_c149 = m928[4];
              if (v_c4 == v_c10) return;
              if (!slog::exists_probe<5,3>(pbranchindex886, std::array<u64,5>{v_c148, v_c4, v_c3, 0, 0})) return;
              if (!slog::exists_probe<3,2>(st_insindex887, std::array<u64,3>{v_c148, v_c2, 0})) return;
              if (!slog::exists_probe<2,1>(st_join_ansindex888, std::array<u64,2>{v_c149, 0})) return;
              slog::join_probe<7,4>($sup9688x54x0x0x0index889, std::array<u64,7>{v_c2, v_c4, v_c148, v_c3, 0, 0, 0}, [&](const std::array<u64,7>& m929) {
                u64 v_c150 = m929[4]; u64 v_c6 = m929[5]; u64 v_c7 = m929[6];
                slog::join_probe<5,5>(pbranchindex890, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, v_c148}, [&](const std::array<u64,5>& m930) {
                  slog::join_probe<3,3>(st_insindex891, std::array<u64,3>{v_c150, v_c2, v_c148}, [&](const std::array<u64,3>& m931) {
                    slog::join_probe<2,1>(st_join_ansindex892, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m932) {
                      u64 v_c12 = m932[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask893* _cont = new ReadTask893(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask893(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan st_msk __t3oZy109 p n) (body (exists $sup9688x148x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (join st_msk_ans (0 1) 1 __t3oZy109 q) (exists pbranch (1 2 3 4 0) 2 q n) (join $sup9688x148x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __t5Ek2104 l m r u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 u) (join pbranch (1 2 3 4 0) 4 q n u v __t6SZQ102) (exists st_diff (2 0 1) 2 __t6SZQ102 __t5Ek2104) (join pbranch (1 2 3 4 0) 4 p m l r __t6qKy107) (join st_diff (0 1 2) 3 __t5Ek2104 __t6qKy107 __t6SZQ102) (join st_diff (1 2 0) 2 __t6qKy107 u __t4u9h108) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask947 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x148x0x0x0index933;  slog::Index** pbranchindex934;  slog::Index** pbranchindex935;  slog::Index** st_msk_ansindex936;  slog::Index** pbranchindex937;  slog::Index** $sup9688x148x0x0x0index938;  slog::Index** pbranchindex939;  slog::Index** st_diffindex940;  slog::Index** pbranchindex941;  slog::Index** st_diffindex942;  slog::Index** pbranchindex943;  slog::Index** st_diffindex944;  slog::Index** st_diffindex945;  slog::Index** st_diff_ansindex946;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("st_diff_ans");
      head_index[0] = readrel949->getIndex(ord948, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord950({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel951 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index933 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({2, 0, 1, 3, 4});
      slog::Relation* readrel953 = db->getRelation("pbranch");
      pbranchindex934 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({1, 2, 3, 4, 0});
      slog::Relation* readrel955 = db->getRelation("pbranch");
      pbranchindex935 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({0, 1});
      slog::Relation* readrel957 = db->getRelation("st_msk_ans");
      st_msk_ansindex936 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 3, 4, 0});
      slog::Relation* readrel959 = db->getRelation("pbranch");
      pbranchindex937 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel961 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index938 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 2, 3, 4, 0});
      slog::Relation* readrel963 = db->getRelation("pbranch");
      pbranchindex939 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({2, 0, 1});
      slog::Relation* readrel965 = db->getRelation("st_diff");
      st_diffindex940 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 2, 3, 4, 0});
      slog::Relation* readrel967 = db->getRelation("pbranch");
      pbranchindex941 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({2, 0, 1});
      slog::Relation* readrel969 = db->getRelation("st_diff");
      st_diffindex942 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 2, 3, 4, 0});
      slog::Relation* readrel971 = db->getRelation("pbranch");
      pbranchindex943 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("st_diff");
      st_diffindex944 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("st_diff");
      st_diffindex945 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({0, 1});
      slog::Relation* readrel977 = db->getRelation("st_diff_ans");
      st_diff_ansindex946 = readrel977->getIndex(ord976, false);
  
    }
    ReadTask947(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c152 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c53 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x148x0x0x0index933, std::array<u64,9>{v_c53, v_c4, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex934, std::array<u64,5>{v_c53, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex935, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex936, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m978) {
          u64 v_c54 = m978[1];
          if (!slog::exists_probe<5,2>(pbranchindex937, std::array<u64,5>{v_c54, v_c53, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x148x0x0x0index938, std::array<u64,9>{v_c53, v_c4, v_c54, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m979) {
            u64 v_c153 = m979[3]; u64 v_c6 = m979[4]; u64 v_c3 = m979[5]; u64 v_c7 = m979[6]; u64 v_c41 = m979[7]; u64 v_c42 = m979[8];
            u64 v_c154 = _prim_lt(db, v_c3, v_c53);
            if (v_c154 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c154) return;
            if (!slog::exists_probe<5,4>(pbranchindex939, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex940, std::array<u64,3>{v_c41, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex941, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m981) {
              u64 v_c155 = m981[4];
              if (!slog::exists_probe<3,2>(st_diffindex942, std::array<u64,3>{v_c155, v_c153, 0})) return;
              slog::join_probe<5,4>(pbranchindex943, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m982) {
                u64 v_c156 = m982[4];
                slog::join_probe<3,3>(st_diffindex944, std::array<u64,3>{v_c153, v_c156, v_c155}, [&](const std::array<u64,3>& m983) {
                  slog::join_probe<3,2>(st_diffindex945, std::array<u64,3>{v_c156, v_c41, 0}, [&](const std::array<u64,3>& m984) {
                    u64 v_c157 = m984[2];
                    slog::join_probe<2,1>(st_diff_ansindex946, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m985) {
                      u64 v_c12 = m985[1];
                      u64 v_c158 = _prim_band(db, v_c4, v_c53);
                      if (v_c158 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c159 = _prim_lt(db, v_c158, v_c151);
                      if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c159) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c153, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:st_msk", _fires);
  
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
  // (crule (pre) (scan st_diff __t7G0O486 __t7Xsy485 __t7Veu484) (body (join pbranch (0 1 2 3 4) 1 __t7Veu484 q m u v) (join pbranch (2 0 1 3 4) 2 m __t7Xsy485 p l r) (neq p q)) (head (emit st_diff_ans (0 1) __t7G0O486 __t7Xsy485)) set.slog:158 #f)
  class ReadTask989 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex987;  slog::Index** pbranchindex988;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord990({0, 1});
      slog::Relation* readrel991 = db->getRelation("st_diff_ans");
      head_index[0] = readrel991->getIndex(ord990, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord992({0, 1, 2, 3, 4});
      slog::Relation* readrel993 = db->getRelation("pbranch");
      pbranchindex987 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({2, 0, 1, 3, 4});
      slog::Relation* readrel995 = db->getRelation("pbranch");
      pbranchindex988 = readrel995->getIndex(ord994, false);
  
    }
    ReadTask989(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c160 = _t[0];
        u64 v_c161 = _t[1];
        u64 v_c162 = _t[2];
        slog::join_probe<5,1>(pbranchindex987, std::array<u64,5>{v_c162, 0, 0, 0, 0}, [&](const std::array<u64,5>& m996) {
          u64 v_c54 = m996[1]; u64 v_c3 = m996[2]; u64 v_c41 = m996[3]; u64 v_c42 = m996[4];
          slog::join_probe<5,2>(pbranchindex988, std::array<u64,5>{v_c3, v_c161, 0, 0, 0}, [&](const std::array<u64,5>& m997) {
            u64 v_c4 = m997[2]; u64 v_c6 = m997[3]; u64 v_c7 = m997[4];
            if (v_c4 == v_c54) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c160, v_c161}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:158", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask989* _cont = new ReadTask989(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask989(db,b), false);
  // (crule (pre) (scan st_msk_ans __t412X321 p) (body (exists $sup9688x50x0x0x0 (4 2 3 5 0 1) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t412X321 k m) (join $sup9688x50x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r)) (head (emit $sup9688x50x0x0x1 (0 2 1 3 4 5 6) __d0 k __t412X321 l m p r)) set.slog:51 #f)
  class ReadTask1002 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x0index998;  slog::Index** st_mskindex999;  slog::Index** $sup9688x50x0x0x0index1000;  slog::Index** st_mskdelta1001;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord1003({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel1004 = db->getRelation("$sup9688x50x0x0x1");
      head_index[0] = readrel1004->getIndex(ord1003, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1005({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1006 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index998 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({0, 1, 2});
      slog::Relation* readrel1008 = db->getRelation("st_msk");
      st_mskindex999 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({0, 1, 2});
      slog::Relation* readrel1010 = db->getRelation("st_msk");
      st_mskdelta1001 = readrel1010->getIndex(ord1009, true);
      std::vector<u16> ord1011({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1012 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index1000 = readrel1012->getIndex(ord1011, false);
  
    }
    ReadTask1002(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c163 = _t[0];
        u64 v_c4 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x50x0x0x0index998, std::array<u64,6>{v_c4, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex999, st_mskdelta1001, std::array<u64,3>{v_c163, 0, 0}, [&](const std::array<u64,3>& m1013) {
          u64 v_c2 = m1013[1]; u64 v_c3 = m1013[2];
          slog::join_probe<6,3>($sup9688x50x0x0x0index1000, std::array<u64,6>{v_c2, v_c3, v_c4, 0, 0, 0}, [&](const std::array<u64,6>& m1014) {
            u64 v_c19 = m1014[3]; u64 v_c6 = m1014[4]; u64 v_c7 = m1014[5];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c19, v_c2, v_c163, v_c6, v_c3, v_c4, v_c7}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1002* _cont = new ReadTask1002(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1002(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan pbranch __t6qKy107 p m l r) (body (exists st_diff (1 2 0) 1 __t6qKy107) (exists st_msk (1 2 0) 1 p) (join $sup9688x148x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t5Ek2104 n q u v) (cmp lt m n) (exists st_diff (0 1 2) 2 __t5Ek2104 __t6qKy107) (exists st_diff (1 2 0) 2 __t6qKy107 u) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (join pbranch (1 2 3 4 0) 4 q n u v __t6SZQ102) (join st_diff (0 1 2) 3 __t5Ek2104 __t6qKy107 __t6SZQ102) (join-old st_diff (1 2 0) 2 (1 2 0) __t6qKy107 u __t4u9h108) (exists st_diff_ans (0 1) 1 __t4u9h108) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join st_msk_ans (0 1) 2 __t3oZy109 q) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask1031 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1015;  slog::Index** st_mskindex1016;  slog::Index** $sup9688x148x0x0x0index1017;  slog::Index** st_diffindex1018;  slog::Index** st_diffindex1019;  slog::Index** st_mskindex1020;  slog::Index** st_msk_ansindex1021;  slog::Index** pbranchindex1022;  slog::Index** st_diffindex1023;  slog::Index** st_diffindex1024;  slog::Index** st_diff_ansindex1025;  slog::Index** st_mskindex1026;  slog::Index** st_msk_ansindex1027;  slog::Index** st_diff_ansindex1028;  slog::Index** st_diffdelta1029;  slog::Index** st_mskdelta1030;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1032({0, 1});
      slog::Relation* readrel1033 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1033->getIndex(ord1032, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1034({1, 2, 0});
      slog::Relation* readrel1035 = db->getRelation("st_diff");
      st_diffindex1015 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({1, 2, 0});
      slog::Relation* readrel1037 = db->getRelation("st_msk");
      st_mskindex1016 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1039 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index1017 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({0, 1, 2});
      slog::Relation* readrel1041 = db->getRelation("st_diff");
      st_diffindex1018 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 2, 0});
      slog::Relation* readrel1043 = db->getRelation("st_diff");
      st_diffindex1019 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 2, 0});
      slog::Relation* readrel1045 = db->getRelation("st_msk");
      st_mskindex1020 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 0});
      slog::Relation* readrel1047 = db->getRelation("st_msk_ans");
      st_msk_ansindex1021 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({1, 2, 3, 4, 0});
      slog::Relation* readrel1049 = db->getRelation("pbranch");
      pbranchindex1022 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({0, 1, 2});
      slog::Relation* readrel1051 = db->getRelation("st_diff");
      st_diffindex1023 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({1, 2, 0});
      slog::Relation* readrel1053 = db->getRelation("st_diff");
      st_diffindex1024 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 2, 0});
      slog::Relation* readrel1055 = db->getRelation("st_diff");
      st_diffdelta1029 = readrel1055->getIndex(ord1054, true);
      std::vector<u16> ord1056({0, 1});
      slog::Relation* readrel1057 = db->getRelation("st_diff_ans");
      st_diff_ansindex1025 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 2, 0});
      slog::Relation* readrel1059 = db->getRelation("st_msk");
      st_mskindex1026 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({1, 2, 0});
      slog::Relation* readrel1061 = db->getRelation("st_msk");
      st_mskdelta1030 = readrel1061->getIndex(ord1060, true);
      std::vector<u16> ord1062({0, 1});
      slog::Relation* readrel1063 = db->getRelation("st_msk_ans");
      st_msk_ansindex1027 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({0, 1});
      slog::Relation* readrel1065 = db->getRelation("st_diff_ans");
      st_diff_ansindex1028 = readrel1065->getIndex(ord1064, false);
  
    }
    ReadTask1031(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c156 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex1015, std::array<u64,3>{v_c156, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1016, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x148x0x0x0index1017, std::array<u64,9>{v_c6, v_c3, v_c4, v_c7, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1066) {
          u64 v_c153 = m1066[4]; u64 v_c53 = m1066[5]; u64 v_c54 = m1066[6]; u64 v_c41 = m1066[7]; u64 v_c42 = m1066[8];
          u64 v_c164 = _prim_lt(db, v_c3, v_c53);
          if (v_c164 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
          if (!v_c164) return;
          if (!slog::exists_probe<3,2>(st_diffindex1018, std::array<u64,3>{v_c153, v_c156, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex1019, std::array<u64,3>{v_c156, v_c41, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex1020, std::array<u64,3>{v_c4, v_c53, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex1021, std::array<u64,2>{v_c54, 0})) return;
          slog::join_probe<5,4>(pbranchindex1022, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m1068) {
            u64 v_c155 = m1068[4];
            slog::join_probe<3,3>(st_diffindex1023, std::array<u64,3>{v_c153, v_c156, v_c155}, [&](const std::array<u64,3>& m1069) {
              slog::join_probe_old<3,2>(st_diffindex1024, st_diffdelta1029, std::array<u64,3>{v_c156, v_c41, 0}, [&](const std::array<u64,3>& m1070) {
                u64 v_c157 = m1070[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex1025, std::array<u64,2>{v_c157, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex1026, st_mskdelta1030, std::array<u64,3>{v_c4, v_c53, 0}, [&](const std::array<u64,3>& m1071) {
                  u64 v_c152 = m1071[2];
                  slog::join_probe<2,2>(st_msk_ansindex1027, std::array<u64,2>{v_c152, v_c54}, [&](const std::array<u64,2>& m1072) {
                    slog::join_probe<2,1>(st_diff_ansindex1028, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m1073) {
                      u64 v_c12 = m1073[1];
                      u64 v_c158 = _prim_band(db, v_c4, v_c53);
                      if (v_c158 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c165 = _prim_lt(db, v_c158, v_c151);
                      if (v_c165 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c165) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c153, v_c12}, std::array<u16,2>{0, 1});
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
        ReadTask1031* _cont = new ReadTask1031(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1031(db,b), false);
  // (crule (pre) (scan st_hsb_ans __t5IW626 __v3) (body (join-old st_hsb_ans (0 1) 1 (0 1) __t5IW626 __v1) (join-old st_hsb (0 1) 1 (0 1) __t5IW626 __t8vKi27) (join-old $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk37YX1277 (bxor p0 p1)) (eq __t8vKi27 chk37YX1277)) (head (emit $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t5IW626 __t5IW626 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask1081 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1075;  slog::Index** st_hsbindex1076;  slog::Index** $sup9688x36x0x0x1index1077;  slog::Index** st_hsb_ansdelta1078;  slog::Index** st_hsbdelta1079;  slog::Index** $sup9688x36x0x0x1delta1080;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord1082({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1083 = db->getRelation("$sup9688x36x0x0x2");
      head_index[0] = readrel1083->getIndex(ord1082, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1084({0, 1});
      slog::Relation* readrel1085 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1075 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({0, 1});
      slog::Relation* readrel1087 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1078 = readrel1087->getIndex(ord1086, true);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("st_hsb");
      st_hsbindex1076 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({0, 1});
      slog::Relation* readrel1091 = db->getRelation("st_hsb");
      st_hsbdelta1079 = readrel1091->getIndex(ord1090, true);
      std::vector<u16> ord1092({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1093 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1077 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1095 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1delta1080 = readrel1095->getIndex(ord1094, true);
  
    }
    ReadTask1081(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c166 = _t[0];
        u64 v_c38 = _t[1];
        slog::join_probe_old<2,1>(st_hsb_ansindex1075, st_hsb_ansdelta1078, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1096) {
          u64 v_c37 = m1096[1];
          slog::join_probe_old<2,1>(st_hsbindex1076, st_hsbdelta1079, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1097) {
            u64 v_c167 = m1097[1];
            slog::join_all_old<7>($sup9688x36x0x0x1index1077, $sup9688x36x0x0x1delta1080, [&](const std::array<u64,7>& m1098) {
              u64 v_c34 = m1098[0]; u64 v_c10 = m1098[1]; u64 v_c19 = m1098[2]; u64 v_c18 = m1098[3]; u64 v_c20 = m1098[4]; u64 v_c21 = m1098[5]; u64 v_c22 = m1098[6];
              u64 v_c168 = _prim_bxor(db, v_c18, v_c20);
              if (v_c168 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
              if (v_c167 != v_c168) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c34, v_c10, v_c38, v_c37, v_c19, v_c166, v_c166, v_c18, v_c20, v_c21, v_c22}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1081* _cont = new ReadTask1081(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1081(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk7QfM1312 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk7QfM1312) (letp chk9UGk1313 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk9UGk1313) (letp chk4bUG1314 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk4bUG1314) (letp chk2mTo1315 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk2mTo1315) (letp chk4T5F1316 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk4T5F1316)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask1111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1099;  slog::Index** $seq_atindex1100;  slog::Index** $seq_atindex1101;  slog::Index** $seq_atindex1102;  slog::Index** $seq_atrindex1103;  slog::Index** $seq_atrindex1104;  slog::Index** $seq_atrindex1105;  slog::Index** st_fromlistindex1106;  slog::Index** st_fromlist_ansindex1107;  slog::Index** $seq_atrdelta1108;  slog::Index** $seq_atrdelta1109;  slog::Index** $seq_atrdelta1110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1112({0});
      slog::Relation* readrel1113 = db->getRelation("canon");
      head_index[0] = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({0, 1, 2});
      slog::Relation* readrel1115 = db->getRelation("$seq_atr");
      driver_index = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({1, 0, 2});
      slog::Relation* readrel1117 = db->getRelation("$seq_at");
      $seq_atindex1099 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 0, 2});
      slog::Relation* readrel1119 = db->getRelation("$seq_at");
      $seq_atindex1100 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 0, 2});
      slog::Relation* readrel1121 = db->getRelation("$seq_at");
      $seq_atindex1101 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 0, 2});
      slog::Relation* readrel1123 = db->getRelation("$seq_at");
      $seq_atindex1102 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({0, 1, 2});
      slog::Relation* readrel1125 = db->getRelation("$seq_atr");
      $seq_atrindex1103 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({0, 1, 2});
      slog::Relation* readrel1127 = db->getRelation("$seq_atr");
      $seq_atrdelta1108 = readrel1127->getIndex(ord1126, true);
      std::vector<u16> ord1128({0, 1, 2});
      slog::Relation* readrel1129 = db->getRelation("$seq_atr");
      $seq_atrindex1104 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({0, 1, 2});
      slog::Relation* readrel1131 = db->getRelation("$seq_atr");
      $seq_atrdelta1109 = readrel1131->getIndex(ord1130, true);
      std::vector<u16> ord1132({0, 1, 2});
      slog::Relation* readrel1133 = db->getRelation("$seq_atr");
      $seq_atrindex1105 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({0, 1, 2});
      slog::Relation* readrel1135 = db->getRelation("$seq_atr");
      $seq_atrdelta1110 = readrel1135->getIndex(ord1134, true);
      std::vector<u16> ord1136({1, 0});
      slog::Relation* readrel1137 = db->getRelation("st_fromlist");
      st_fromlistindex1106 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1107 = readrel1139->getIndex(ord1138, false);
  
    }
    ReadTask1111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c169 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c170 = v_const5feceb66ffc86f38d952786c;
      u64 v_c171 = v_constef2d127de37b942baad06145;
      u64 v_c172 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c173 = v_constd4735e3a265e16eee03f5971;
      u64 v_c174 = v_constd4735e3a265e16eee03f5971;
      u64 v_c175 = v_const2c624232cdd221771294dfbb;
      u64 v_c176 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c178 = v_constef2d127de37b942baad06145;
      u64 v_c179 = v_const5feceb66ffc86f38d952786c;
      u64 v_c180 = v_constd4735e3a265e16eee03f5971;
      u64 v_c181 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c182 = v_const2c624232cdd221771294dfbb;
      u64 v_c183 = v_constd4735e3a265e16eee03f5971;
      u64 v_c184 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c185 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c186 = v_constef2d127de37b942baad06145;
      u64 v_c187 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
      u64 v_c189 = v_constd4735e3a265e16eee03f5971;
      u64 v_c190 = v_const2c624232cdd221771294dfbb;
      u64 v_c191 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c192 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c193 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c186, v_c187, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1140) {
        u64 v_c194 = m1140[2];
        if (buckethash(v_c194) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1099, std::array<u64,3>{v_c179, v_c178, v_c194}, [&](const std::array<u64,3>& m1141) {
          slog::join_probe<3,3>($seq_atindex1100, std::array<u64,3>{v_c181, v_c180, v_c194}, [&](const std::array<u64,3>& m1142) {
            slog::join_probe<3,3>($seq_atindex1101, std::array<u64,3>{v_c183, v_c182, v_c194}, [&](const std::array<u64,3>& m1143) {
              slog::join_probe<3,3>($seq_atindex1102, std::array<u64,3>{v_c185, v_c184, v_c194}, [&](const std::array<u64,3>& m1144) {
                slog::join_probe_old<3,3>($seq_atrindex1103, $seq_atrdelta1108, std::array<u64,3>{v_c188, v_c189, v_c194}, [&](const std::array<u64,3>& m1145) {
                  slog::join_probe_old<3,3>($seq_atrindex1104, $seq_atrdelta1109, std::array<u64,3>{v_c190, v_c191, v_c194}, [&](const std::array<u64,3>& m1146) {
                    slog::join_probe_old<3,3>($seq_atrindex1105, $seq_atrdelta1110, std::array<u64,3>{v_c192, v_c193, v_c194}, [&](const std::array<u64,3>& m1147) {
                      slog::join_probe<2,1>(st_fromlistindex1106, std::array<u64,2>{v_c194, 0}, [&](const std::array<u64,2>& m1148) {
                        u64 v_c195 = m1148[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1107, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m1149) {
                          u64 v_c7 = m1149[1];
                          bool ok1150 = true;
                          u64 v_c196 = _prim_aslst(db, v_c194, &ok1150);
                          if (!ok1150) return;
                          u64 v_c197 = _prim_llen(db, v_c196);
                          if (v_c197 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c169 != v_c197) return;
                          bool ok1151 = true;
                          u64 v_c198 = _prim_lref(db, v_c196, v_c170, &ok1151);
                          if (!ok1151) return;
                          if (v_c171 != v_c198) return;
                          bool ok1152 = true;
                          u64 v_c199 = _prim_lref(db, v_c196, v_c172, &ok1152);
                          if (!ok1152) return;
                          if (v_c173 != v_c199) return;
                          bool ok1153 = true;
                          u64 v_c200 = _prim_lref(db, v_c196, v_c174, &ok1153);
                          if (!ok1153) return;
                          if (v_c175 != v_c200) return;
                          bool ok1154 = true;
                          u64 v_c201 = _prim_lref(db, v_c196, v_c176, &ok1154);
                          if (!ok1154) return;
                          if (v_c177 != v_c201) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
        ReadTask1111* _cont = new ReadTask1111(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1111(db,b), false);
  // (crule (pre (let __trid2f261088 conste09004dcc147461a8e3857fe) (let __trel7jih1089 constdee70e0c1571644b5844be78) (let __tcol496J1090 const5feceb66ffc86f38d952786c) (let __trel8pq71091 constdee70e0c1571644b5844be78) (let __tcol1Lnd1092 const6b86b273ff34fce19d6b804e)) (scan $sup9688x70x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid2f261088 __trel7jih1089 __tcol496J1090 (1 2 3 4 0)) (tycheck k (accept int) __trid2f261088 __trel8pq71091 __tcol1Lnd1092 (1 2 3 4 0)) (mkstruct st_mem0 (1 2 0) __0zCe1087 l k)) set.slog:71 #f)
  class ReadTask1158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1156;  u32 sid1155;  u32 sid1157;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("$sup9688x70x0x0x0");
      sid1156 = db->getRelation("_enum")->getStructId();
      sid1155 = db->getRelation("pbranch")->getStructId();
      sid1157 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c202 = v_conste09004dcc147461a8e3857fe;
      u64 v_c203 = v_constdee70e0c1571644b5844be78;
      u64 v_c204 = v_const5feceb66ffc86f38d952786c;
      u64 v_c205 = v_constdee70e0c1571644b5844be78;
      u64 v_c206 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c19 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c7 = _t[5];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid1155 || decode_struct_id(v_c6) == sid1156 || decode_struct_id(v_c6) == sid1157))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c202, v_c203, v_c204, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c202, v_c205, v_c206, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:$sup9688x70x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1158* _cont = new ReadTask1158(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1158(db,b), false);
  // (crule (pre) (scan temp5Bov1275 __t4rEg577 l m p r) (body (join pbranch (1 2 3 4 0) 4 p m l r __t94LO576)) (head (emit st_bld_ans (0 1) __t4rEg577 __t94LO576)) set.slog:80 #f)
  class ReadTask1160 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1159;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_bld_ans");
      std::vector<u16> ord1161({0, 1});
      slog::Relation* readrel1162 = db->getRelation("st_bld_ans");
      head_index[0] = readrel1162->getIndex(ord1161, false);
      outer_rel = db->getRelation("temp5Bov1275");
      std::vector<u16> ord1163({1, 2, 3, 4, 0});
      slog::Relation* readrel1164 = db->getRelation("pbranch");
      pbranchindex1159 = readrel1164->getIndex(ord1163, false);
  
    }
    ReadTask1160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe<5,4>(pbranchindex1159, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1165) {
          u64 v_c207 = m1165[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c207}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:80", "delta:temp5Bov1275", _fires);
  
      if (!_done)
      {
        ReadTask1160* _cont = new ReadTask1160(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1160(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan $sup9688x142x0x0x0 __t8Fy1335 l m n p q r u v) (body (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t88zt334) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join-old st_diff (0 1 2) 3 (0 1 2) __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t7XLn338) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join st_diff_ans (0 1) 2 __t95th341 __v0) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask1190 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1166;  slog::Index** st_bldindex1167;  slog::Index** st_mskindex1168;  slog::Index** st_msk_ansindex1169;  slog::Index** st_diffindex1170;  slog::Index** pbranchindex1171;  slog::Index** st_diffindex1172;  slog::Index** pbranchindex1173;  slog::Index** st_diffindex1174;  slog::Index** st_diffindex1175;  slog::Index** st_bldindex1176;  slog::Index** st_diff_ansindex1177;  slog::Index** st_bld_ansindex1178;  slog::Index** st_mskindex1179;  slog::Index** st_msk_ansindex1180;  slog::Index** st_diffindex1181;  slog::Index** st_diff_ansindex1182;  slog::Index** st_bld_ansindex1183;  slog::Index** pbranchdelta1184;  slog::Index** pbranchdelta1185;  slog::Index** st_diffdelta1186;  slog::Index** st_blddelta1187;  slog::Index** st_mskdelta1188;  slog::Index** st_diffdelta1189;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1191({0, 1});
      slog::Relation* readrel1192 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1192->getIndex(ord1191, false);
      outer_rel = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord1193({1, 2, 3, 4, 0});
      slog::Relation* readrel1194 = db->getRelation("pbranch");
      pbranchindex1166 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 2, 3, 4, 0});
      slog::Relation* readrel1196 = db->getRelation("st_bld");
      st_bldindex1167 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({1, 2, 0});
      slog::Relation* readrel1198 = db->getRelation("st_msk");
      st_mskindex1168 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 0});
      slog::Relation* readrel1200 = db->getRelation("st_msk_ans");
      st_msk_ansindex1169 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({1, 2, 0});
      slog::Relation* readrel1202 = db->getRelation("st_diff");
      st_diffindex1170 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({1, 2, 3, 4, 0});
      slog::Relation* readrel1204 = db->getRelation("pbranch");
      pbranchindex1171 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 2, 3, 4, 0});
      slog::Relation* readrel1206 = db->getRelation("pbranch");
      pbranchdelta1184 = readrel1206->getIndex(ord1205, true);
      std::vector<u16> ord1207({0, 1, 2});
      slog::Relation* readrel1208 = db->getRelation("st_diff");
      st_diffindex1172 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 2, 3, 4, 0});
      slog::Relation* readrel1210 = db->getRelation("pbranch");
      pbranchindex1173 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({1, 2, 3, 4, 0});
      slog::Relation* readrel1212 = db->getRelation("pbranch");
      pbranchdelta1185 = readrel1212->getIndex(ord1211, true);
      std::vector<u16> ord1213({0, 1, 2});
      slog::Relation* readrel1214 = db->getRelation("st_diff");
      st_diffindex1174 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({0, 1, 2});
      slog::Relation* readrel1216 = db->getRelation("st_diff");
      st_diffdelta1186 = readrel1216->getIndex(ord1215, true);
      std::vector<u16> ord1217({1, 2, 0});
      slog::Relation* readrel1218 = db->getRelation("st_diff");
      st_diffindex1175 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 2, 3, 4, 0});
      slog::Relation* readrel1220 = db->getRelation("st_bld");
      st_bldindex1176 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 2, 3, 4, 0});
      slog::Relation* readrel1222 = db->getRelation("st_bld");
      st_blddelta1187 = readrel1222->getIndex(ord1221, true);
      std::vector<u16> ord1223({1, 0});
      slog::Relation* readrel1224 = db->getRelation("st_diff_ans");
      st_diff_ansindex1177 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({0, 1});
      slog::Relation* readrel1226 = db->getRelation("st_bld_ans");
      st_bld_ansindex1178 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({1, 2, 0});
      slog::Relation* readrel1228 = db->getRelation("st_msk");
      st_mskindex1179 = readrel1228->getIndex(ord1227, false);
      std::vector<u16> ord1229({1, 2, 0});
      slog::Relation* readrel1230 = db->getRelation("st_msk");
      st_mskdelta1188 = readrel1230->getIndex(ord1229, true);
      std::vector<u16> ord1231({0, 1});
      slog::Relation* readrel1232 = db->getRelation("st_msk_ans");
      st_msk_ansindex1180 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({1, 2, 0});
      slog::Relation* readrel1234 = db->getRelation("st_diff");
      st_diffindex1181 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 2, 0});
      slog::Relation* readrel1236 = db->getRelation("st_diff");
      st_diffdelta1189 = readrel1236->getIndex(ord1235, true);
      std::vector<u16> ord1237({0, 1});
      slog::Relation* readrel1238 = db->getRelation("st_diff_ans");
      st_diff_ansindex1182 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({0, 1});
      slog::Relation* readrel1240 = db->getRelation("st_bld_ans");
      st_bld_ansindex1183 = readrel1240->getIndex(ord1239, false);
  
    }
    ReadTask1190(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c54 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c41 = _t[7];
        u64 v_c42 = _t[8];
        u64 v_c208 = _prim_lt(db, v_c53, v_c3);
        if (v_c208 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
        if (!v_c208) return;
        if (!slog::exists_probe<5,4>(pbranchindex1166, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex1167, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex1168, std::array<u64,3>{v_c54, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1169, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex1170, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex1171, pbranchdelta1184, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1242) {
          u64 v_c60 = m1242[4];
          if (!slog::exists_probe<3,2>(st_diffindex1172, std::array<u64,3>{v_c59, v_c60, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex1173, pbranchdelta1185, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m1243) {
            u64 v_c61 = m1243[4];
            slog::join_probe_old<3,3>(st_diffindex1174, st_diffdelta1186, std::array<u64,3>{v_c59, v_c60, v_c61}, [&](const std::array<u64,3>& m1244) {
              if (!slog::exists_probe<3,2>(st_diffindex1175, std::array<u64,3>{v_c7, v_c61, 0})) return;
              slog::join_probe_old<5,3>(st_bldindex1176, st_blddelta1187, std::array<u64,5>{v_c4, v_c3, v_c6, 0, 0}, [&](const std::array<u64,5>& m1245) {
                u64 v_c10 = m1245[3]; u64 v_c64 = m1245[4];
                if (!slog::exists_probe<2,1>(st_diff_ansindex1177, std::array<u64,2>{v_c10, 0})) return;
                if (!slog::exists_probe<2,1>(st_bld_ansindex1178, std::array<u64,2>{v_c64, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex1179, st_mskdelta1188, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m1246) {
                  u64 v_c65 = m1246[2];
                  slog::join_probe<2,2>(st_msk_ansindex1180, std::array<u64,2>{v_c65, v_c4}, [&](const std::array<u64,2>& m1247) {
                    slog::join_probe_old<3,2>(st_diffindex1181, st_diffdelta1189, std::array<u64,3>{v_c7, v_c61, 0}, [&](const std::array<u64,3>& m1248) {
                      u64 v_c62 = m1248[2];
                      slog::join_probe<2,2>(st_diff_ansindex1182, std::array<u64,2>{v_c62, v_c10}, [&](const std::array<u64,2>& m1249) {
                        slog::join_probe<2,1>(st_bld_ansindex1183, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m1250) {
                          u64 v_c12 = m1250[1];
                          u64 v_c66 = _prim_band(db, v_c54, v_c3);
                          if (v_c66 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c209 = _prim_gt(db, v_c66, v_c58);
                          if (v_c209 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c209) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:$sup9688x142x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1190* _cont = new ReadTask1190(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1190(db,b), false);
  // (crule (pre) (scan pbranch __t4iIu12 p m l r) (body (exists st_ins (1 2 0) 1 __t4iIu12) (exists st_join (3 4 0 1 2) 2 p __t4iIu12) (exists st_msk (2 0 1) 1 m) (join $sup9688x54x0x0x0 (2 3 4 5 6 0 1) 5 l m p r __t4iIu12 __t2YgE11 k) (join st_ins (0 2 1) 3 __t2YgE11 k __t4iIu12) (exists pleaf (1 0) 1 k) (exists st_msk (1 2 0) 2 k m) (join-old st_join (1 4 3 0 2) 3 (1 4 3 0 2) k __t4iIu12 p __t4hUr14 __t4JtR13) (join-old pleaf (0 1) 2 (0 1) __t4JtR13 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask1268 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1252;  slog::Index** st_joinindex1253;  slog::Index** st_mskindex1254;  slog::Index** $sup9688x54x0x0x0index1255;  slog::Index** st_insindex1256;  slog::Index** pleafindex1257;  slog::Index** st_mskindex1258;  slog::Index** st_joinindex1259;  slog::Index** pleafindex1260;  slog::Index** st_join_ansindex1261;  slog::Index** st_mskindex1262;  slog::Index** st_msk_ansindex1263;  slog::Index** st_join_ansindex1264;  slog::Index** st_joindelta1265;  slog::Index** pleafdelta1266;  slog::Index** st_mskdelta1267;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("st_ins_ans");
      head_index[0] = readrel1270->getIndex(ord1269, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1271({1, 2, 0});
      slog::Relation* readrel1272 = db->getRelation("st_ins");
      st_insindex1252 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({3, 4, 0, 1, 2});
      slog::Relation* readrel1274 = db->getRelation("st_join");
      st_joinindex1253 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({2, 0, 1});
      slog::Relation* readrel1276 = db->getRelation("st_msk");
      st_mskindex1254 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({2, 3, 4, 5, 6, 0, 1});
      slog::Relation* readrel1278 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index1255 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({0, 2, 1});
      slog::Relation* readrel1280 = db->getRelation("st_ins");
      st_insindex1256 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 0});
      slog::Relation* readrel1282 = db->getRelation("pleaf");
      pleafindex1257 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({1, 2, 0});
      slog::Relation* readrel1284 = db->getRelation("st_msk");
      st_mskindex1258 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({1, 4, 3, 0, 2});
      slog::Relation* readrel1286 = db->getRelation("st_join");
      st_joinindex1259 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({1, 4, 3, 0, 2});
      slog::Relation* readrel1288 = db->getRelation("st_join");
      st_joindelta1265 = readrel1288->getIndex(ord1287, true);
      std::vector<u16> ord1289({0, 1});
      slog::Relation* readrel1290 = db->getRelation("pleaf");
      pleafindex1260 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({0, 1});
      slog::Relation* readrel1292 = db->getRelation("pleaf");
      pleafdelta1266 = readrel1292->getIndex(ord1291, true);
      std::vector<u16> ord1293({0, 1});
      slog::Relation* readrel1294 = db->getRelation("st_join_ans");
      st_join_ansindex1261 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({1, 2, 0});
      slog::Relation* readrel1296 = db->getRelation("st_msk");
      st_mskindex1262 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({1, 2, 0});
      slog::Relation* readrel1298 = db->getRelation("st_msk");
      st_mskdelta1267 = readrel1298->getIndex(ord1297, true);
      std::vector<u16> ord1299({0, 1});
      slog::Relation* readrel1300 = db->getRelation("st_msk_ans");
      st_msk_ansindex1263 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({0, 1});
      slog::Relation* readrel1302 = db->getRelation("st_join_ans");
      st_join_ansindex1264 = readrel1302->getIndex(ord1301, false);
  
    }
    ReadTask1268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c148 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<3,1>(st_insindex1252, std::array<u64,3>{v_c148, 0, 0})) return;
        if (!slog::exists_probe<5,2>(st_joinindex1253, std::array<u64,5>{v_c4, v_c148, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1254, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<7,5>($sup9688x54x0x0x0index1255, std::array<u64,7>{v_c6, v_c3, v_c4, v_c7, v_c148, 0, 0}, [&](const std::array<u64,7>& m1303) {
          u64 v_c150 = m1303[5]; u64 v_c2 = m1303[6];
          slog::join_probe<3,3>(st_insindex1256, std::array<u64,3>{v_c150, v_c2, v_c148}, [&](const std::array<u64,3>& m1304) {
            if (!slog::exists_probe<2,1>(pleafindex1257, std::array<u64,2>{v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1258, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<5,3>(st_joinindex1259, st_joindelta1265, std::array<u64,5>{v_c2, v_c148, v_c4, 0, 0}, [&](const std::array<u64,5>& m1305) {
              u64 v_c149 = m1305[3]; u64 v_c147 = m1305[4];
              slog::join_probe_old<2,2>(pleafindex1260, pleafdelta1266, std::array<u64,2>{v_c147, v_c2}, [&](const std::array<u64,2>& m1306) {
                if (!slog::exists_probe<2,1>(st_join_ansindex1261, std::array<u64,2>{v_c149, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex1262, st_mskdelta1267, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1307) {
                  u64 v_c146 = m1307[2];
                  slog::join_probe<2,1>(st_msk_ansindex1263, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m1308) {
                    u64 v_c10 = m1308[1];
                    if (v_c4 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex1264, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1309) {
                      u64 v_c12 = m1309[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1268* _cont = new ReadTask1268(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1268(db,b), false);
  // (crule (pre) (scan st_msk __t43e0330 k m) (body (exists $sup9688x52x0x0x0 (1 3 4 0 2 5) 2 k m) (join st_msk_ans (0 1) 1 __t43e0330 p) (join $sup9688x52x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r)) (head (emit $sup9688x52x0x0x1 (0 2 1 3 4 5 6) __d0 k __t43e0330 l m p r)) set.slog:53 #f)
  class ReadTask1313 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x0index1310;  slog::Index** st_msk_ansindex1311;  slog::Index** $sup9688x52x0x0x0index1312;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord1314({0, 2, 1, 3, 4, 5, 6});
      slog::Relation* readrel1315 = db->getRelation("$sup9688x52x0x0x1");
      head_index[0] = readrel1315->getIndex(ord1314, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1316({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1317 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index1310 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("st_msk_ans");
      st_msk_ansindex1311 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1321 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index1312 = readrel1321->getIndex(ord1320, false);
  
    }
    ReadTask1313(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x52x0x0x0index1310, std::array<u64,6>{v_c2, v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1311, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1322) {
          u64 v_c4 = m1322[1];
          slog::join_probe<6,3>($sup9688x52x0x0x0index1312, std::array<u64,6>{v_c2, v_c3, v_c4, 0, 0, 0}, [&](const std::array<u64,6>& m1323) {
            u64 v_c19 = m1323[3]; u64 v_c6 = m1323[4]; u64 v_c7 = m1323[5];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c19, v_c2, v_c28, v_c6, v_c3, v_c4, v_c7}, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1313* _cont = new ReadTask1313(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1313(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan pbranch __t8dDI315 p m l r) (body (exists $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 4 l m p r) (exists st_ins (1 2 0) 1 __t8dDI315) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 1 l) (join $sup9688x50x0x0x0 (4 2 3 5 0 1) 4 p l m r __t6bST316 k) (exists st_ins (0 2 1) 3 __t6bST316 k __t8dDI315) (exists st_msk (1 2 0) 2 k m) (exists st_ins (1 2 0) 2 l k) (join $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t6bST316 k __t5Q4t319) (join-old st_ins (0 2 1) 3 (0 2 1) __t6bST316 k __t8dDI315) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join st_ins_ans (0 1) 1 __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask1342 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x1index1324;  slog::Index** st_insindex1325;  slog::Index** st_mskindex1326;  slog::Index** st_msk_ansindex1327;  slog::Index** st_insindex1328;  slog::Index** $sup9688x50x0x0x0index1329;  slog::Index** st_insindex1330;  slog::Index** st_mskindex1331;  slog::Index** st_insindex1332;  slog::Index** $sup9688x50x0x0x1index1333;  slog::Index** st_insindex1334;  slog::Index** st_mskindex1335;  slog::Index** st_msk_ansindex1336;  slog::Index** st_insindex1337;  slog::Index** st_ins_ansindex1338;  slog::Index** st_insdelta1339;  slog::Index** st_mskdelta1340;  slog::Index** st_insdelta1341;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1343({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel1344 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index1324 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({1, 2, 0});
      slog::Relation* readrel1346 = db->getRelation("st_ins");
      st_insindex1325 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({2, 0, 1});
      slog::Relation* readrel1348 = db->getRelation("st_msk");
      st_mskindex1326 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 0});
      slog::Relation* readrel1350 = db->getRelation("st_msk_ans");
      st_msk_ansindex1327 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 2, 0});
      slog::Relation* readrel1352 = db->getRelation("st_ins");
      st_insindex1328 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1354 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index1329 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({0, 2, 1});
      slog::Relation* readrel1356 = db->getRelation("st_ins");
      st_insindex1330 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 2, 0});
      slog::Relation* readrel1358 = db->getRelation("st_msk");
      st_mskindex1331 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({1, 2, 0});
      slog::Relation* readrel1360 = db->getRelation("st_ins");
      st_insindex1332 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel1362 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index1333 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({0, 2, 1});
      slog::Relation* readrel1364 = db->getRelation("st_ins");
      st_insindex1334 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({0, 2, 1});
      slog::Relation* readrel1366 = db->getRelation("st_ins");
      st_insdelta1339 = readrel1366->getIndex(ord1365, true);
      std::vector<u16> ord1367({1, 2, 0});
      slog::Relation* readrel1368 = db->getRelation("st_msk");
      st_mskindex1335 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 2, 0});
      slog::Relation* readrel1370 = db->getRelation("st_msk");
      st_mskdelta1340 = readrel1370->getIndex(ord1369, true);
      std::vector<u16> ord1371({0, 1});
      slog::Relation* readrel1372 = db->getRelation("st_msk_ans");
      st_msk_ansindex1336 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({1, 2, 0});
      slog::Relation* readrel1374 = db->getRelation("st_ins");
      st_insindex1337 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 0});
      slog::Relation* readrel1376 = db->getRelation("st_ins");
      st_insdelta1341 = readrel1376->getIndex(ord1375, true);
      std::vector<u16> ord1377({0, 1});
      slog::Relation* readrel1378 = db->getRelation("st_ins_ans");
      st_ins_ansindex1338 = readrel1378->getIndex(ord1377, false);
  
    }
    ReadTask1342(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c211 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<7,4>($sup9688x50x0x0x1index1324, std::array<u64,7>{v_c6, v_c3, v_c4, v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1325, std::array<u64,3>{v_c211, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1326, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1327, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1328, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x50x0x0x0index1329, std::array<u64,6>{v_c4, v_c6, v_c3, v_c7, 0, 0}, [&](const std::array<u64,6>& m1379) {
          u64 v_c212 = m1379[4]; u64 v_c2 = m1379[5];
          if (!slog::exists_probe<3,3>(st_insindex1330, std::array<u64,3>{v_c212, v_c2, v_c211})) return;
          if (!slog::exists_probe<3,2>(st_mskindex1331, std::array<u64,3>{v_c2, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(st_insindex1332, std::array<u64,3>{v_c6, v_c2, 0})) return;
          slog::join_probe<7,6>($sup9688x50x0x0x1index1333, std::array<u64,7>{v_c6, v_c3, v_c4, v_c7, v_c212, v_c2, 0}, [&](const std::array<u64,7>& m1380) {
            u64 v_c213 = m1380[6];
            slog::join_probe_old<3,3>(st_insindex1334, st_insdelta1339, std::array<u64,3>{v_c212, v_c2, v_c211}, [&](const std::array<u64,3>& m1381) {
              slog::join_probe_old<3,3>(st_mskindex1335, st_mskdelta1340, std::array<u64,3>{v_c2, v_c3, v_c213}, [&](const std::array<u64,3>& m1382) {
                slog::join_probe<2,2>(st_msk_ansindex1336, std::array<u64,2>{v_c213, v_c4}, [&](const std::array<u64,2>& m1383) {
                  slog::join_probe_old<3,2>(st_insindex1337, st_insdelta1341, std::array<u64,3>{v_c6, v_c2, 0}, [&](const std::array<u64,3>& m1384) {
                    u64 v_c214 = m1384[2];
                    slog::join_probe<2,1>(st_ins_ansindex1338, std::array<u64,2>{v_c214, 0}, [&](const std::array<u64,2>& m1385) {
                      u64 v_c10 = m1385[1];
                      u64 v_c215 = _prim_band(db, v_c2, v_c3);
                      if (v_c215 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c216 = _prim_lt(db, v_c215, v_c210);
                      if (v_c216 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c216) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c212, v_c10, v_c3, v_c4, v_c7});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c3, v_c10, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1342* _cont = new ReadTask1342(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1342(db,b), false);
  // (crule (pre) (scan st_hsb __t5IW626 __t8vKi27) (body (exists st_hsb_ans (0 1) 1 __t5IW626) (join st_hsb_ans (0 1) 1 __t5IW626 __v3) (join st_hsb_ans (0 1) 1 __t5IW626 __v1) (join $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk2wud1279 (bxor p0 p1)) (eq __t8vKi27 chk2wud1279)) (head (emit $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t5IW626 __t5IW626 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask1391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1387;  slog::Index** st_hsb_ansindex1388;  slog::Index** st_hsb_ansindex1389;  slog::Index** $sup9688x36x0x0x1index1390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord1392({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1393 = db->getRelation("$sup9688x36x0x0x2");
      head_index[0] = readrel1393->getIndex(ord1392, false);
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord1394({0, 1});
      slog::Relation* readrel1395 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1387 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({0, 1});
      slog::Relation* readrel1397 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1388 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({0, 1});
      slog::Relation* readrel1399 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1389 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1401 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1390 = readrel1401->getIndex(ord1400, false);
  
    }
    ReadTask1391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c166 = _t[0];
        u64 v_c167 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1387, std::array<u64,2>{v_c166, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex1388, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1402) {
          u64 v_c38 = m1402[1];
          slog::join_probe<2,1>(st_hsb_ansindex1389, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1403) {
            u64 v_c37 = m1403[1];
            slog::join_all<7>($sup9688x36x0x0x1index1390, [&](const std::array<u64,7>& m1404) {
              u64 v_c34 = m1404[0]; u64 v_c10 = m1404[1]; u64 v_c19 = m1404[2]; u64 v_c18 = m1404[3]; u64 v_c20 = m1404[4]; u64 v_c21 = m1404[5]; u64 v_c22 = m1404[6];
              u64 v_c217 = _prim_bxor(db, v_c18, v_c20);
              if (v_c217 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
              if (v_c167 != v_c217) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c34, v_c10, v_c38, v_c37, v_c19, v_c166, v_c166, v_c18, v_c20, v_c21, v_c22}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1391* _cont = new ReadTask1391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1391(db,b), false);
  // (crule (pre (let __tconst8lGk118 const6b86b273ff34fce19d6b804e)) (scan st_mem0 __t5R5p117 __t8tCR116 k) (body (join pbranch (0 1 2 3 4) 1 __t8tCR116 p m l r) (let __t7KqF119 (band k m)) (cmp lt __t7KqF119 __tconst8lGk118)) (head (emit $sup9688x70x0x0x0 (4 2 3 5 0 1) p l m r __t5R5p117 k)) set.slog:71 #f)
  class ReadTask1406 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1405;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord1407({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1408 = db->getRelation("$sup9688x70x0x0x0");
      head_index[0] = readrel1408->getIndex(ord1407, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord1409({0, 1, 2, 3, 4});
      slog::Relation* readrel1410 = db->getRelation("pbranch");
      pbranchindex1405 = readrel1410->getIndex(ord1409, false);
  
    }
    ReadTask1406(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c218 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c219 = _t[0];
        u64 v_c220 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<5,1>(pbranchindex1405, std::array<u64,5>{v_c220, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1411) {
          u64 v_c4 = m1411[1]; u64 v_c3 = m1411[2]; u64 v_c6 = m1411[3]; u64 v_c7 = m1411[4];
          u64 v_c221 = _prim_band(db, v_c2, v_c3);
          if (v_c221 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
          u64 v_c222 = _prim_lt(db, v_c221, v_c218);
          if (v_c222 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
          if (!v_c222) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c4, v_c6, v_c3, v_c7, v_c219, v_c2}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask1406* _cont = new ReadTask1406(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1406(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan $sup9688x114x0x0x0 __t2j0W61 l m n p q r u v) (body (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (exists st_union (2 0 1) 1 u) (join-old $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t2j0W61 l m p r __t1Zy964) (exists st_msk (1 2 0) 3 p n __t1Zy964) (exists st_msk_ans (0 1) 2 __t1Zy964 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2ifW59) (exists st_union (2 0 1) 2 __t2ifW59 __t2j0W61) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_union (0 1 2) 3 (0 1 2) __t2j0W61 __t5Obr65 __t2ifW59) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask1435 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1413;  slog::Index** pbranchindex1414;  slog::Index** st_mskindex1415;  slog::Index** st_msk_ansindex1416;  slog::Index** st_unionindex1417;  slog::Index** $sup9688x114x0x0x1index1418;  slog::Index** st_mskindex1419;  slog::Index** st_msk_ansindex1420;  slog::Index** pbranchindex1421;  slog::Index** st_unionindex1422;  slog::Index** pbranchindex1423;  slog::Index** st_unionindex1424;  slog::Index** st_mskindex1425;  slog::Index** st_msk_ansindex1426;  slog::Index** st_unionindex1427;  slog::Index** st_union_ansindex1428;  slog::Index** $sup9688x114x0x0x1delta1429;  slog::Index** pbranchdelta1430;  slog::Index** pbranchdelta1431;  slog::Index** st_uniondelta1432;  slog::Index** st_mskdelta1433;  slog::Index** st_uniondelta1434;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord1436({1, 2, 3, 4, 0});
      slog::Relation* readrel1437 = db->getRelation("pbranch");
      pbranchindex1413 = readrel1437->getIndex(ord1436, false);
      std::vector<u16> ord1438({1, 2, 3, 4, 0});
      slog::Relation* readrel1439 = db->getRelation("pbranch");
      pbranchindex1414 = readrel1439->getIndex(ord1438, false);
      std::vector<u16> ord1440({1, 2, 0});
      slog::Relation* readrel1441 = db->getRelation("st_msk");
      st_mskindex1415 = readrel1441->getIndex(ord1440, false);
      std::vector<u16> ord1442({1, 0});
      slog::Relation* readrel1443 = db->getRelation("st_msk_ans");
      st_msk_ansindex1416 = readrel1443->getIndex(ord1442, false);
      std::vector<u16> ord1444({2, 0, 1});
      slog::Relation* readrel1445 = db->getRelation("st_union");
      st_unionindex1417 = readrel1445->getIndex(ord1444, false);
      std::vector<u16> ord1446({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1447 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index1418 = readrel1447->getIndex(ord1446, false);
      std::vector<u16> ord1448({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1449 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1delta1429 = readrel1449->getIndex(ord1448, true);
      std::vector<u16> ord1450({1, 2, 0});
      slog::Relation* readrel1451 = db->getRelation("st_msk");
      st_mskindex1419 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({0, 1});
      slog::Relation* readrel1453 = db->getRelation("st_msk_ans");
      st_msk_ansindex1420 = readrel1453->getIndex(ord1452, false);
      std::vector<u16> ord1454({1, 2, 3, 4, 0});
      slog::Relation* readrel1455 = db->getRelation("pbranch");
      pbranchindex1421 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({1, 2, 3, 4, 0});
      slog::Relation* readrel1457 = db->getRelation("pbranch");
      pbranchdelta1430 = readrel1457->getIndex(ord1456, true);
      std::vector<u16> ord1458({2, 0, 1});
      slog::Relation* readrel1459 = db->getRelation("st_union");
      st_unionindex1422 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 2, 3, 4, 0});
      slog::Relation* readrel1461 = db->getRelation("pbranch");
      pbranchindex1423 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({1, 2, 3, 4, 0});
      slog::Relation* readrel1463 = db->getRelation("pbranch");
      pbranchdelta1431 = readrel1463->getIndex(ord1462, true);
      std::vector<u16> ord1464({0, 1, 2});
      slog::Relation* readrel1465 = db->getRelation("st_union");
      st_unionindex1424 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({0, 1, 2});
      slog::Relation* readrel1467 = db->getRelation("st_union");
      st_uniondelta1432 = readrel1467->getIndex(ord1466, true);
      std::vector<u16> ord1468({1, 2, 0});
      slog::Relation* readrel1469 = db->getRelation("st_msk");
      st_mskindex1425 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({1, 2, 0});
      slog::Relation* readrel1471 = db->getRelation("st_msk");
      st_mskdelta1433 = readrel1471->getIndex(ord1470, true);
      std::vector<u16> ord1472({0, 1});
      slog::Relation* readrel1473 = db->getRelation("st_msk_ans");
      st_msk_ansindex1426 = readrel1473->getIndex(ord1472, false);
      std::vector<u16> ord1474({1, 2, 0});
      slog::Relation* readrel1475 = db->getRelation("st_union");
      st_unionindex1427 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({1, 2, 0});
      slog::Relation* readrel1477 = db->getRelation("st_union");
      st_uniondelta1434 = readrel1477->getIndex(ord1476, true);
      std::vector<u16> ord1478({0, 1});
      slog::Relation* readrel1479 = db->getRelation("st_union_ans");
      st_union_ansindex1428 = readrel1479->getIndex(ord1478, false);
  
    }
    ReadTask1435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c223 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c224 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c54 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c41 = _t[7];
        u64 v_c42 = _t[8];
        u64 v_c225 = _prim_lt(db, v_c3, v_c53);
        if (v_c225 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
        if (!v_c225) return;
        if (!slog::exists_probe<5,4>(pbranchindex1413, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0})) return;
        if (!slog::exists_probe<5,4>(pbranchindex1414, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex1415, std::array<u64,3>{v_c4, v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1416, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex1417, std::array<u64,3>{v_c41, 0, 0})) return;
        slog::join_probe_old<10,9>($sup9688x114x0x0x1index1418, $sup9688x114x0x0x1delta1429, std::array<u64,10>{v_c41, v_c53, v_c54, v_c42, v_c224, v_c6, v_c3, v_c4, v_c7, 0}, [&](const std::array<u64,10>& m1481) {
          u64 v_c226 = m1481[9];
          if (!slog::exists_probe<3,3>(st_mskindex1419, std::array<u64,3>{v_c4, v_c53, v_c226})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex1420, std::array<u64,2>{v_c226, v_c54})) return;
          slog::join_probe_old<5,4>(pbranchindex1421, pbranchdelta1430, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m1482) {
            u64 v_c227 = m1482[4];
            if (!slog::exists_probe<3,2>(st_unionindex1422, std::array<u64,3>{v_c227, v_c224, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1423, pbranchdelta1431, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1483) {
              u64 v_c228 = m1483[4];
              slog::join_probe_old<3,3>(st_unionindex1424, st_uniondelta1432, std::array<u64,3>{v_c224, v_c228, v_c227}, [&](const std::array<u64,3>& m1484) {
                slog::join_probe_old<3,3>(st_mskindex1425, st_mskdelta1433, std::array<u64,3>{v_c4, v_c53, v_c226}, [&](const std::array<u64,3>& m1485) {
                  slog::join_probe<2,2>(st_msk_ansindex1426, std::array<u64,2>{v_c226, v_c54}, [&](const std::array<u64,2>& m1486) {
                    slog::join_probe_old<3,2>(st_unionindex1427, st_uniondelta1434, std::array<u64,3>{v_c228, v_c41, 0}, [&](const std::array<u64,3>& m1487) {
                      u64 v_c229 = m1487[2];
                      slog::join_probe<2,1>(st_union_ansindex1428, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1488) {
                        u64 v_c10 = m1488[1];
                        u64 v_c230 = _prim_band(db, v_c4, v_c53);
                        if (v_c230 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c231 = _prim_lt(db, v_c230, v_c223);
                        if (v_c231 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c231) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c224, v_c10, v_c53, v_c54, v_c42});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c54, v_c53, v_c10, v_c42}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:$sup9688x114x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1435* _cont = new ReadTask1435(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1435(db,b), false);
  // (crule (pre) (scan pbranch __t9yhk7 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t9yhk7 __t2Ttf9 __t0y5a8) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t0y5a8 p m l r) (cmp lt m n)) (head (emit $sup9688x154x0x0x0 (0 1 2 3 4 5 6 7 8) __t2Ttf9 l m n p q r u v)) set.slog:155 #f)
  class ReadTask1494 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1490;  slog::Index** pbranchindex1491;  slog::Index** st_diffdelta1492;  slog::Index** pbranchdelta1493;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord1495({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1496 = db->getRelation("$sup9688x154x0x0x0");
      head_index[0] = readrel1496->getIndex(ord1495, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1497({2, 0, 1});
      slog::Relation* readrel1498 = db->getRelation("st_diff");
      st_diffindex1490 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({2, 0, 1});
      slog::Relation* readrel1500 = db->getRelation("st_diff");
      st_diffdelta1492 = readrel1500->getIndex(ord1499, true);
      std::vector<u16> ord1501({0, 1, 2, 3, 4});
      slog::Relation* readrel1502 = db->getRelation("pbranch");
      pbranchindex1491 = readrel1502->getIndex(ord1501, false);
      std::vector<u16> ord1503({0, 1, 2, 3, 4});
      slog::Relation* readrel1504 = db->getRelation("pbranch");
      pbranchdelta1493 = readrel1504->getIndex(ord1503, true);
  
    }
    ReadTask1494(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[1];
        u64 v_c53 = _t[2];
        u64 v_c41 = _t[3];
        u64 v_c42 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex1490, st_diffdelta1492, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m1505) {
          u64 v_c68 = m1505[1]; u64 v_c69 = m1505[2];
          slog::join_probe_old<5,1>(pbranchindex1491, pbranchdelta1493, std::array<u64,5>{v_c69, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1506) {
            u64 v_c4 = m1506[1]; u64 v_c3 = m1506[2]; u64 v_c6 = m1506[3]; u64 v_c7 = m1506[4];
            u64 v_c232 = _prim_lt(db, v_c3, v_c53);
            if (v_c232 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c232) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c68, v_c6, v_c3, v_c53, v_c4, v_c54, v_c7, v_c41, v_c42}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1494* _cont = new ReadTask1494(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1494(db,b), false);
  // (crule (pre) (scan st_msk __t8BWG393 q m) (body (exists $sup9688x103x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join st_msk_ans (0 1) 1 __t8BWG393 p) (join $sup9688x103x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t8BWG393 m n p q r u v)) set.slog:104 #f)
  class ReadTask1511 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x0index1508;  slog::Index** st_msk_ansindex1509;  slog::Index** $sup9688x103x0x0x0index1510;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord1512({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel1513 = db->getRelation("$sup9688x103x0x0x1");
      head_index[0] = readrel1513->getIndex(ord1512, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1514({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1515 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1508 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({0, 1});
      slog::Relation* readrel1517 = db->getRelation("st_msk_ans");
      st_msk_ansindex1509 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1519 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1510 = readrel1519->getIndex(ord1518, false);
  
    }
    ReadTask1511(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c233 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x103x0x0x0index1508, std::array<u64,9>{v_c3, v_c54, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1509, std::array<u64,2>{v_c233, 0}, [&](const std::array<u64,2>& m1520) {
          u64 v_c4 = m1520[1];
          slog::join_probe<9,3>($sup9688x103x0x0x0index1510, std::array<u64,9>{v_c3, v_c54, v_c4, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1521) {
            u64 v_c19 = m1521[3]; u64 v_c6 = m1521[4]; u64 v_c53 = m1521[5]; u64 v_c7 = m1521[6]; u64 v_c41 = m1521[7]; u64 v_c42 = m1521[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c19, v_c6, v_c233, v_c3, v_c53, v_c4, v_c54, v_c7, v_c41, v_c42}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1511* _cont = new ReadTask1511(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1511(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan $sup9688x40x0x0x1 __t4PzE464 __t2flT468 __v0 p0 p1 t0 t1) (body (exists $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (exists st_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t4PzE464) (exists st_hsb_ans (0 1) 1 __t2flT468) (exists st_hsb_ans (0 1) 2 __t2flT468 __v0) (exists st_msk (1 2 0) 1 p0) (join $sup9688x40x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0 dup2gd61405 dup5ZAM1406 __v1 __v3) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join-old $sup9688x40x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join-old st_msk_ans (0 1) 1 (0 1) __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask1544 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x40x0x0x0index1522;  slog::Index** st_joinindex1523;  slog::Index** st_hsb_ansindex1524;  slog::Index** st_hsb_ansindex1525;  slog::Index** st_mskindex1526;  slog::Index** $sup9688x40x0x0x2index1527;  slog::Index** $sup9688x40x0x0x0index1528;  slog::Index** st_joinindex1529;  slog::Index** st_hsb_ansindex1530;  slog::Index** st_hsb_ansindex1531;  slog::Index** st_hsb_ansindex1532;  slog::Index** st_mskindex1533;  slog::Index** st_msk_ansindex1534;  slog::Index** st_hsbindex1535;  slog::Index** $sup9688x40x0x0x0delta1536;  slog::Index** st_joindelta1537;  slog::Index** st_hsb_ansdelta1538;  slog::Index** st_hsb_ansdelta1539;  slog::Index** st_hsb_ansdelta1540;  slog::Index** st_mskdelta1541;  slog::Index** st_msk_ansdelta1542;  slog::Index** st_hsbdelta1543;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord1545({1, 0, 2, 3, 4});
      slog::Relation* readrel1546 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index1522 = readrel1546->getIndex(ord1545, false);
      std::vector<u16> ord1547({1, 2, 3, 4, 0});
      slog::Relation* readrel1548 = db->getRelation("st_join");
      st_joinindex1523 = readrel1548->getIndex(ord1547, false);
      std::vector<u16> ord1549({0, 1});
      slog::Relation* readrel1550 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1524 = readrel1550->getIndex(ord1549, false);
      std::vector<u16> ord1551({0, 1});
      slog::Relation* readrel1552 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1525 = readrel1552->getIndex(ord1551, false);
      std::vector<u16> ord1553({1, 2, 0});
      slog::Relation* readrel1554 = db->getRelation("st_msk");
      st_mskindex1526 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1556 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1527 = readrel1556->getIndex(ord1555, false);
      std::vector<u16> ord1557({1, 0, 2, 3, 4});
      slog::Relation* readrel1558 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index1528 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({1, 0, 2, 3, 4});
      slog::Relation* readrel1560 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0delta1536 = readrel1560->getIndex(ord1559, true);
      std::vector<u16> ord1561({1, 2, 3, 4, 0});
      slog::Relation* readrel1562 = db->getRelation("st_join");
      st_joinindex1529 = readrel1562->getIndex(ord1561, false);
      std::vector<u16> ord1563({1, 2, 3, 4, 0});
      slog::Relation* readrel1564 = db->getRelation("st_join");
      st_joindelta1537 = readrel1564->getIndex(ord1563, true);
      std::vector<u16> ord1565({0, 1});
      slog::Relation* readrel1566 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1530 = readrel1566->getIndex(ord1565, false);
      std::vector<u16> ord1567({0, 1});
      slog::Relation* readrel1568 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1538 = readrel1568->getIndex(ord1567, true);
      std::vector<u16> ord1569({0, 1});
      slog::Relation* readrel1570 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1531 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({0, 1});
      slog::Relation* readrel1572 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1539 = readrel1572->getIndex(ord1571, true);
      std::vector<u16> ord1573({0, 1});
      slog::Relation* readrel1574 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1532 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({0, 1});
      slog::Relation* readrel1576 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1540 = readrel1576->getIndex(ord1575, true);
      std::vector<u16> ord1577({1, 2, 0});
      slog::Relation* readrel1578 = db->getRelation("st_msk");
      st_mskindex1533 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({1, 2, 0});
      slog::Relation* readrel1580 = db->getRelation("st_msk");
      st_mskdelta1541 = readrel1580->getIndex(ord1579, true);
      std::vector<u16> ord1581({0, 1});
      slog::Relation* readrel1582 = db->getRelation("st_msk_ans");
      st_msk_ansindex1534 = readrel1582->getIndex(ord1581, false);
      std::vector<u16> ord1583({0, 1});
      slog::Relation* readrel1584 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1542 = readrel1584->getIndex(ord1583, true);
      std::vector<u16> ord1585({0, 1});
      slog::Relation* readrel1586 = db->getRelation("st_hsb");
      st_hsbindex1535 = readrel1586->getIndex(ord1585, false);
      std::vector<u16> ord1587({0, 1});
      slog::Relation* readrel1588 = db->getRelation("st_hsb");
      st_hsbdelta1543 = readrel1588->getIndex(ord1587, true);
  
    }
    ReadTask1544(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c234 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c235 = _t[0];
        u64 v_c236 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c20 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c22 = _t[6];
        if (!slog::exists_probe<5,5>($sup9688x40x0x0x0index1522, std::array<u64,5>{v_c18, v_c235, v_c20, v_c21, v_c22})) return;
        if (!slog::exists_probe<5,5>(st_joinindex1523, std::array<u64,5>{v_c18, v_c21, v_c20, v_c22, v_c235})) return;
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1524, std::array<u64,2>{v_c236, 0})) return;
        if (!slog::exists_probe<2,2>(st_hsb_ansindex1525, std::array<u64,2>{v_c236, v_c10})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1526, std::array<u64,3>{v_c18, 0, 0})) return;
        slog::join_probe<11,7>($sup9688x40x0x0x2index1527, std::array<u64,11>{v_c235, v_c18, v_c20, v_c21, v_c22, v_c236, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1589) {
          u64 v_c237 = m1589[7]; u64 v_c238 = m1589[8]; u64 v_c37 = m1589[9]; u64 v_c38 = m1589[10];
          if (v_c236 != v_c238) return;
          if (v_c236 != v_c237) return;
          slog::join_probe_old<5,5>($sup9688x40x0x0x0index1528, $sup9688x40x0x0x0delta1536, std::array<u64,5>{v_c18, v_c235, v_c20, v_c21, v_c22}, [&](const std::array<u64,5>& m1590) {
            slog::join_probe_old<5,5>(st_joinindex1529, st_joindelta1537, std::array<u64,5>{v_c18, v_c21, v_c20, v_c22, v_c235}, [&](const std::array<u64,5>& m1591) {
              slog::join_probe_old<2,2>(st_hsb_ansindex1530, st_hsb_ansdelta1538, std::array<u64,2>{v_c236, v_c38}, [&](const std::array<u64,2>& m1592) {
                slog::join_probe_old<2,2>(st_hsb_ansindex1531, st_hsb_ansdelta1539, std::array<u64,2>{v_c236, v_c37}, [&](const std::array<u64,2>& m1593) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex1532, st_hsb_ansdelta1540, std::array<u64,2>{v_c236, v_c10}, [&](const std::array<u64,2>& m1594) {
                    slog::join_probe_old<3,2>(st_mskindex1533, st_mskdelta1541, std::array<u64,3>{v_c18, v_c37, 0}, [&](const std::array<u64,3>& m1595) {
                      u64 v_c239 = m1595[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex1534, st_msk_ansdelta1542, std::array<u64,2>{v_c239, 0}, [&](const std::array<u64,2>& m1596) {
                        u64 v_c240 = m1596[1];
                        u64 v_c241 = _prim_bxor(db, v_c18, v_c20);
                        if (v_c241 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex1535, st_hsbdelta1543, std::array<u64,2>{v_c236, v_c241}, [&](const std::array<u64,2>& m1597) {
                          u64 v_c242 = _prim_band(db, v_c18, v_c10);
                          if (v_c242 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c243 = _prim_gt(db, v_c242, v_c234);
                          if (v_c243 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c243) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c235, v_c240, v_c38, v_c21, v_c22});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c240, v_c38, v_c22, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1544* _cont = new ReadTask1544(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1544(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t1Zy964 q) (body (exists $sup9688x114x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t1Zy964 q) (exists $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists pbranch (1 2 3 4 0) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t1Zy964 p n) (exists $sup9688x114x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists pbranch (1 2 3 4 0) 2 q n) (exists pbranch (1 2 3 4 0) 1 p) (join-old $sup9688x114x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t1Zy964 n p q __t2j0W61 l m r u v) (cmp lt m n) (join-old $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t2j0W61 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 1 u) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2ifW59) (exists st_union (2 0 1) 2 __t2ifW59 __t2j0W61) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_union (0 1 2) 3 (0 1 2) __t2j0W61 __t5Obr65 __t2ifW59) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join-old st_union_ans (0 1) 1 (0 1) __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask1624 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x1index1599;  slog::Index** $sup9688x114x0x0x0index1600;  slog::Index** pbranchindex1601;  slog::Index** st_mskindex1602;  slog::Index** $sup9688x114x0x0x0index1603;  slog::Index** pbranchindex1604;  slog::Index** pbranchindex1605;  slog::Index** $sup9688x114x0x0x1index1606;  slog::Index** $sup9688x114x0x0x0index1607;  slog::Index** pbranchindex1608;  slog::Index** st_unionindex1609;  slog::Index** pbranchindex1610;  slog::Index** st_unionindex1611;  slog::Index** pbranchindex1612;  slog::Index** st_unionindex1613;  slog::Index** st_unionindex1614;  slog::Index** st_union_ansindex1615;  slog::Index** st_mskdelta1616;  slog::Index** $sup9688x114x0x0x1delta1617;  slog::Index** $sup9688x114x0x0x0delta1618;  slog::Index** pbranchdelta1619;  slog::Index** pbranchdelta1620;  slog::Index** st_uniondelta1621;  slog::Index** st_uniondelta1622;  slog::Index** st_union_ansdelta1623;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1625({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel1626 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index1599 = readrel1626->getIndex(ord1625, false);
      std::vector<u16> ord1627({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1628 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1600 = readrel1628->getIndex(ord1627, false);
      std::vector<u16> ord1629({1, 2, 3, 4, 0});
      slog::Relation* readrel1630 = db->getRelation("pbranch");
      pbranchindex1601 = readrel1630->getIndex(ord1629, false);
      std::vector<u16> ord1631({0, 1, 2});
      slog::Relation* readrel1632 = db->getRelation("st_msk");
      st_mskindex1602 = readrel1632->getIndex(ord1631, false);
      std::vector<u16> ord1633({0, 1, 2});
      slog::Relation* readrel1634 = db->getRelation("st_msk");
      st_mskdelta1616 = readrel1634->getIndex(ord1633, true);
      std::vector<u16> ord1635({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1636 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1603 = readrel1636->getIndex(ord1635, false);
      std::vector<u16> ord1637({1, 2, 3, 4, 0});
      slog::Relation* readrel1638 = db->getRelation("pbranch");
      pbranchindex1604 = readrel1638->getIndex(ord1637, false);
      std::vector<u16> ord1639({1, 2, 3, 4, 0});
      slog::Relation* readrel1640 = db->getRelation("pbranch");
      pbranchindex1605 = readrel1640->getIndex(ord1639, false);
      std::vector<u16> ord1641({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel1642 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index1606 = readrel1642->getIndex(ord1641, false);
      std::vector<u16> ord1643({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel1644 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1delta1617 = readrel1644->getIndex(ord1643, true);
      std::vector<u16> ord1645({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1646 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index1607 = readrel1646->getIndex(ord1645, false);
      std::vector<u16> ord1647({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1648 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0delta1618 = readrel1648->getIndex(ord1647, true);
      std::vector<u16> ord1649({1, 2, 3, 4, 0});
      slog::Relation* readrel1650 = db->getRelation("pbranch");
      pbranchindex1608 = readrel1650->getIndex(ord1649, false);
      std::vector<u16> ord1651({2, 0, 1});
      slog::Relation* readrel1652 = db->getRelation("st_union");
      st_unionindex1609 = readrel1652->getIndex(ord1651, false);
      std::vector<u16> ord1653({1, 2, 3, 4, 0});
      slog::Relation* readrel1654 = db->getRelation("pbranch");
      pbranchindex1610 = readrel1654->getIndex(ord1653, false);
      std::vector<u16> ord1655({1, 2, 3, 4, 0});
      slog::Relation* readrel1656 = db->getRelation("pbranch");
      pbranchdelta1619 = readrel1656->getIndex(ord1655, true);
      std::vector<u16> ord1657({2, 0, 1});
      slog::Relation* readrel1658 = db->getRelation("st_union");
      st_unionindex1611 = readrel1658->getIndex(ord1657, false);
      std::vector<u16> ord1659({1, 2, 3, 4, 0});
      slog::Relation* readrel1660 = db->getRelation("pbranch");
      pbranchindex1612 = readrel1660->getIndex(ord1659, false);
      std::vector<u16> ord1661({1, 2, 3, 4, 0});
      slog::Relation* readrel1662 = db->getRelation("pbranch");
      pbranchdelta1620 = readrel1662->getIndex(ord1661, true);
      std::vector<u16> ord1663({0, 1, 2});
      slog::Relation* readrel1664 = db->getRelation("st_union");
      st_unionindex1613 = readrel1664->getIndex(ord1663, false);
      std::vector<u16> ord1665({0, 1, 2});
      slog::Relation* readrel1666 = db->getRelation("st_union");
      st_uniondelta1621 = readrel1666->getIndex(ord1665, true);
      std::vector<u16> ord1667({1, 2, 0});
      slog::Relation* readrel1668 = db->getRelation("st_union");
      st_unionindex1614 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 2, 0});
      slog::Relation* readrel1670 = db->getRelation("st_union");
      st_uniondelta1622 = readrel1670->getIndex(ord1669, true);
      std::vector<u16> ord1671({0, 1});
      slog::Relation* readrel1672 = db->getRelation("st_union_ans");
      st_union_ansindex1615 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({0, 1});
      slog::Relation* readrel1674 = db->getRelation("st_union_ans");
      st_union_ansdelta1623 = readrel1674->getIndex(ord1673, true);
  
    }
    ReadTask1624(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c223 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c226 = _t[0];
        u64 v_c54 = _t[1];
        if (!slog::exists_probe<10,2>($sup9688x114x0x0x1index1599, std::array<u64,10>{v_c226, v_c54, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x114x0x0x0index1600, std::array<u64,9>{v_c54, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1601, std::array<u64,5>{v_c54, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1602, st_mskdelta1616, std::array<u64,3>{v_c226, 0, 0}, [&](const std::array<u64,3>& m1675) {
          u64 v_c4 = m1675[1]; u64 v_c53 = m1675[2];
          if (!slog::exists_probe<9,3>($sup9688x114x0x0x0index1603, std::array<u64,9>{v_c53, v_c4, v_c54, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1604, std::array<u64,5>{v_c54, v_c53, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1605, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup9688x114x0x0x1index1606, $sup9688x114x0x0x1delta1617, std::array<u64,10>{v_c226, v_c53, v_c4, v_c54, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1676) {
            u64 v_c224 = m1676[4]; u64 v_c6 = m1676[5]; u64 v_c3 = m1676[6]; u64 v_c7 = m1676[7]; u64 v_c41 = m1676[8]; u64 v_c42 = m1676[9];
            u64 v_c244 = _prim_lt(db, v_c3, v_c53);
            if (v_c244 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c244) return;
            slog::join_probe_old<9,9>($sup9688x114x0x0x0index1607, $sup9688x114x0x0x0delta1618, std::array<u64,9>{v_c54, v_c53, v_c41, v_c42, v_c224, v_c6, v_c3, v_c4, v_c7}, [&](const std::array<u64,9>& m1678) {
              if (!slog::exists_probe<5,4>(pbranchindex1608, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0})) return;
              if (!slog::exists_probe<3,1>(st_unionindex1609, std::array<u64,3>{v_c41, 0, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1610, pbranchdelta1619, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m1679) {
                u64 v_c227 = m1679[4];
                if (!slog::exists_probe<3,2>(st_unionindex1611, std::array<u64,3>{v_c227, v_c224, 0})) return;
                slog::join_probe_old<5,4>(pbranchindex1612, pbranchdelta1620, std::array<u64,5>{v_c4, v_c3, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1680) {
                  u64 v_c228 = m1680[4];
                  slog::join_probe_old<3,3>(st_unionindex1613, st_uniondelta1621, std::array<u64,3>{v_c224, v_c228, v_c227}, [&](const std::array<u64,3>& m1681) {
                    slog::join_probe_old<3,2>(st_unionindex1614, st_uniondelta1622, std::array<u64,3>{v_c228, v_c41, 0}, [&](const std::array<u64,3>& m1682) {
                      u64 v_c229 = m1682[2];
                      slog::join_probe_old<2,1>(st_union_ansindex1615, st_union_ansdelta1623, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1683) {
                        u64 v_c10 = m1683[1];
                        u64 v_c230 = _prim_band(db, v_c4, v_c53);
                        if (v_c230 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c245 = _prim_lt(db, v_c230, v_c223);
                        if (v_c245 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c245) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c224, v_c10, v_c53, v_c54, v_c42});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c54, v_c53, v_c10, v_c42}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1624* _cont = new ReadTask1624(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1624(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_diff __t3X8M159 __t66RN158 __t6ACr164) (body (exists $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t3X8M159) (join-old st_diff (2 0 1) 1 (2 0 1) __t6ACr164 __t0YPK165 l) (exists $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3X8M159 l) (exists st_diff_ans (0 1) 1 __t0YPK165) (join pbranch (3 0 1 2 4) 2 l __t66RN158 p m r) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 5 p m r l __t3X8M159 n q u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t6ACr164) (exists st_msk (1 2 0) 2 q m) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t1RXD162 __v0) (join st_diff_ans (0 1) 2 __t0YPK165 __v0) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask1706 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index1685;  slog::Index** st_diffindex1686;  slog::Index** $sup9688x139x0x0x0index1687;  slog::Index** st_diff_ansindex1688;  slog::Index** pbranchindex1689;  slog::Index** st_bldindex1690;  slog::Index** st_mskindex1691;  slog::Index** st_msk_ansindex1692;  slog::Index** $sup9688x139x0x0x0index1693;  slog::Index** pbranchindex1694;  slog::Index** st_mskindex1695;  slog::Index** st_bldindex1696;  slog::Index** st_diff_ansindex1697;  slog::Index** st_bld_ansindex1698;  slog::Index** st_mskindex1699;  slog::Index** st_msk_ansindex1700;  slog::Index** st_bld_ansindex1701;  slog::Index** st_diffdelta1702;  slog::Index** pbranchdelta1703;  slog::Index** st_blddelta1704;  slog::Index** st_mskdelta1705;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1707({0, 1});
      slog::Relation* readrel1708 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1708->getIndex(ord1707, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1709({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1710 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1685 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({2, 0, 1});
      slog::Relation* readrel1712 = db->getRelation("st_diff");
      st_diffindex1686 = readrel1712->getIndex(ord1711, false);
      std::vector<u16> ord1713({2, 0, 1});
      slog::Relation* readrel1714 = db->getRelation("st_diff");
      st_diffdelta1702 = readrel1714->getIndex(ord1713, true);
      std::vector<u16> ord1715({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1716 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1687 = readrel1716->getIndex(ord1715, false);
      std::vector<u16> ord1717({0, 1});
      slog::Relation* readrel1718 = db->getRelation("st_diff_ans");
      st_diff_ansindex1688 = readrel1718->getIndex(ord1717, false);
      std::vector<u16> ord1719({3, 0, 1, 2, 4});
      slog::Relation* readrel1720 = db->getRelation("pbranch");
      pbranchindex1689 = readrel1720->getIndex(ord1719, false);
      std::vector<u16> ord1721({2, 1, 4, 0, 3});
      slog::Relation* readrel1722 = db->getRelation("st_bld");
      st_bldindex1690 = readrel1722->getIndex(ord1721, false);
      std::vector<u16> ord1723({2, 0, 1});
      slog::Relation* readrel1724 = db->getRelation("st_msk");
      st_mskindex1691 = readrel1724->getIndex(ord1723, false);
      std::vector<u16> ord1725({1, 0});
      slog::Relation* readrel1726 = db->getRelation("st_msk_ans");
      st_msk_ansindex1692 = readrel1726->getIndex(ord1725, false);
      std::vector<u16> ord1727({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel1728 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1693 = readrel1728->getIndex(ord1727, false);
      std::vector<u16> ord1729({1, 2, 3, 4, 0});
      slog::Relation* readrel1730 = db->getRelation("pbranch");
      pbranchindex1694 = readrel1730->getIndex(ord1729, false);
      std::vector<u16> ord1731({1, 2, 3, 4, 0});
      slog::Relation* readrel1732 = db->getRelation("pbranch");
      pbranchdelta1703 = readrel1732->getIndex(ord1731, true);
      std::vector<u16> ord1733({1, 2, 0});
      slog::Relation* readrel1734 = db->getRelation("st_msk");
      st_mskindex1695 = readrel1734->getIndex(ord1733, false);
      std::vector<u16> ord1735({2, 1, 4, 0, 3});
      slog::Relation* readrel1736 = db->getRelation("st_bld");
      st_bldindex1696 = readrel1736->getIndex(ord1735, false);
      std::vector<u16> ord1737({2, 1, 4, 0, 3});
      slog::Relation* readrel1738 = db->getRelation("st_bld");
      st_blddelta1704 = readrel1738->getIndex(ord1737, true);
      std::vector<u16> ord1739({0, 1});
      slog::Relation* readrel1740 = db->getRelation("st_diff_ans");
      st_diff_ansindex1697 = readrel1740->getIndex(ord1739, false);
      std::vector<u16> ord1741({0, 1});
      slog::Relation* readrel1742 = db->getRelation("st_bld_ans");
      st_bld_ansindex1698 = readrel1742->getIndex(ord1741, false);
      std::vector<u16> ord1743({1, 2, 0});
      slog::Relation* readrel1744 = db->getRelation("st_msk");
      st_mskindex1699 = readrel1744->getIndex(ord1743, false);
      std::vector<u16> ord1745({1, 2, 0});
      slog::Relation* readrel1746 = db->getRelation("st_msk");
      st_mskdelta1705 = readrel1746->getIndex(ord1745, true);
      std::vector<u16> ord1747({0, 1});
      slog::Relation* readrel1748 = db->getRelation("st_msk_ans");
      st_msk_ansindex1700 = readrel1748->getIndex(ord1747, false);
      std::vector<u16> ord1749({0, 1});
      slog::Relation* readrel1750 = db->getRelation("st_bld_ans");
      st_bld_ansindex1701 = readrel1750->getIndex(ord1749, false);
  
    }
    ReadTask1706(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c247 = _t[0];
        u64 v_c248 = _t[1];
        u64 v_c249 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index1685, std::array<u64,9>{v_c247, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex1686, st_diffdelta1702, std::array<u64,3>{v_c249, 0, 0}, [&](const std::array<u64,3>& m1751) {
          u64 v_c250 = m1751[1]; u64 v_c6 = m1751[2];
          if (!slog::exists_probe<9,2>($sup9688x139x0x0x0index1687, std::array<u64,9>{v_c247, v_c6, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex1688, std::array<u64,2>{v_c250, 0})) return;
          slog::join_probe<5,2>(pbranchindex1689, std::array<u64,5>{v_c6, v_c248, 0, 0, 0}, [&](const std::array<u64,5>& m1752) {
            u64 v_c4 = m1752[2]; u64 v_c3 = m1752[3]; u64 v_c7 = m1752[4];
            if (!slog::exists_probe<5,3>(st_bldindex1690, std::array<u64,5>{v_c3, v_c4, v_c7, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex1691, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex1692, std::array<u64,2>{v_c4, 0})) return;
            slog::join_probe<9,5>($sup9688x139x0x0x0index1693, std::array<u64,9>{v_c4, v_c3, v_c7, v_c6, v_c247, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1753) {
              u64 v_c53 = m1753[5]; u64 v_c54 = m1753[6]; u64 v_c41 = m1753[7]; u64 v_c42 = m1753[8];
              u64 v_c251 = _prim_lt(db, v_c53, v_c3);
              if (v_c251 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
              if (!v_c251) return;
              slog::join_probe_old<5,5>(pbranchindex1694, pbranchdelta1703, std::array<u64,5>{v_c54, v_c53, v_c41, v_c42, v_c249}, [&](const std::array<u64,5>& m1755) {
                if (!slog::exists_probe<3,2>(st_mskindex1695, std::array<u64,3>{v_c54, v_c3, 0})) return;
                slog::join_probe_old<5,3>(st_bldindex1696, st_blddelta1704, std::array<u64,5>{v_c3, v_c4, v_c7, 0, 0}, [&](const std::array<u64,5>& m1756) {
                  u64 v_c252 = m1756[3]; u64 v_c10 = m1756[4];
                  slog::join_probe<2,2>(st_diff_ansindex1697, std::array<u64,2>{v_c250, v_c10}, [&](const std::array<u64,2>& m1757) {
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1698, std::array<u64,2>{v_c252, 0})) return;
                    slog::join_probe_old<3,2>(st_mskindex1699, st_mskdelta1705, std::array<u64,3>{v_c54, v_c3, 0}, [&](const std::array<u64,3>& m1758) {
                      u64 v_c253 = m1758[2];
                      slog::join_probe<2,2>(st_msk_ansindex1700, std::array<u64,2>{v_c253, v_c4}, [&](const std::array<u64,2>& m1759) {
                        slog::join_probe<2,1>(st_bld_ansindex1701, std::array<u64,2>{v_c252, 0}, [&](const std::array<u64,2>& m1760) {
                          u64 v_c12 = m1760[1];
                          u64 v_c254 = _prim_band(db, v_c54, v_c3);
                          if (v_c254 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c255 = _prim_lt(db, v_c254, v_c246);
                          if (v_c255 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c255) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c247, v_c12}, std::array<u16,2>{0, 1});
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
        ReadTask1706* _cont = new ReadTask1706(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1706(db,b), false);
  // (crule (pre (let __trid7AMG943 constf2664e0abda1016213c9fa90) (let __trel1lLE944 const26c89ee8ccc4ea998fd1a912) (let __tcol6Qdi945 const5feceb66ffc86f38d952786c) (let __trel7lgp946 const26c89ee8ccc4ea998fd1a912) (let __tcol7D5S947 const6b86b273ff34fce19d6b804e)) (scan st_diff __t6exy561 r v) (body (exists $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 r v) (join st_diff_ans (0 1) 1 __t6exy561 __v1) (join $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 r v __d0 l m p u) (join st_diff (1 2 0) 2 l u __t3HZn560) (join st_diff_ans (0 1) 1 __t3HZn560 __v0)) (head (tycheck p (accept int) __trid7AMG943 __trel1lLE944 __tcol6Qdi945 (1 2 3 4 0)) (tycheck m (accept int) __trid7AMG943 __trel7lgp946 __tcol7D5S947 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __7CRS942 p m __v0 __v1)) set.slog:137 #f)
  class ReadTask1767 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index1762;  slog::Index** st_diff_ansindex1763;  slog::Index** $sup9688x136x0x0x0index1764;  slog::Index** st_diffindex1765;  slog::Index** st_diff_ansindex1766;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1768({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel1769 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index1762 = readrel1769->getIndex(ord1768, false);
      std::vector<u16> ord1770({0, 1});
      slog::Relation* readrel1771 = db->getRelation("st_diff_ans");
      st_diff_ansindex1763 = readrel1771->getIndex(ord1770, false);
      std::vector<u16> ord1772({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel1773 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index1764 = readrel1773->getIndex(ord1772, false);
      std::vector<u16> ord1774({1, 2, 0});
      slog::Relation* readrel1775 = db->getRelation("st_diff");
      st_diffindex1765 = readrel1775->getIndex(ord1774, false);
      std::vector<u16> ord1776({0, 1});
      slog::Relation* readrel1777 = db->getRelation("st_diff_ans");
      st_diff_ansindex1766 = readrel1777->getIndex(ord1776, false);
  
    }
    ReadTask1767(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_constf2664e0abda1016213c9fa90;
      u64 v_c77 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c81 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c42 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index1762, std::array<u64,7>{v_c7, v_c42, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex1763, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1778) {
          u64 v_c37 = m1778[1];
          slog::join_probe<7,2>($sup9688x136x0x0x0index1764, std::array<u64,7>{v_c7, v_c42, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1779) {
            u64 v_c19 = m1779[2]; u64 v_c6 = m1779[3]; u64 v_c3 = m1779[4]; u64 v_c4 = m1779[5]; u64 v_c41 = m1779[6];
            slog::join_probe<3,2>(st_diffindex1765, std::array<u64,3>{v_c6, v_c41, 0}, [&](const std::array<u64,3>& m1780) {
              u64 v_c82 = m1780[2];
              slog::join_probe<2,1>(st_diff_ansindex1766, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1781) {
                u64 v_c10 = m1781[1];
                ++_fires;
                if (!(is_int(v_c4)))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c77, v_c78, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                if (!(is_int(v_c3)))
                {
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c76, v_c79, v_c80, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c4, v_c3, v_c10, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1767* _cont = new ReadTask1767(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1767(db,b), false);
  // (crule (pre) (scan toint_range __erre4IJV1252 __errf1SKk1253 __errf4Caa1254) (body) (head (emit error (0) __erre4IJV1252)) <internal>:1 #f)
  class ReadTask1782 : public slog::Task
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
      std::vector<u16> ord1783({0});
      slog::Relation* readrel1784 = db->getRelation("error");
      head_index[0] = readrel1784->getIndex(ord1783, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask1782(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c256 = _t[0];
        u64 v_c257 = _t[1];
        u64 v_c258 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c256}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask1782* _cont = new ReadTask1782(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1782(db,b), false);
}

