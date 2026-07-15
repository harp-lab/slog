
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const35c71810897f279c2099acbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const81906d9241165d9f6a541e47;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constcbf5a4e983555adcacc7f2e9;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c73ff02b198ad68e4(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan st_msk_ans __t8lOi420 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t8lOi420 p n) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (join-old $sup9688x154x0x0x0 (3 4 0 1 2 5 6 7 8) 2 (3 4 0 1 2 5 6 7 8) n p __t0EGY419 l m q r u v) (cmp lt m n) (neq q __v0) (exists pbranch (1 2 3 4 0) 4 p m l r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t7ytQ417) (exists st_diff (2 0 1) 2 __t7ytQ417 __t0EGY419) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1fgd418) (join-old st_diff (0 1 2) 3 (0 1 2) __t0EGY419 __t1fgd418 __t7ytQ417)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex0;  slog::Index** pbranchindex1;  slog::Index** pbranchindex2;  slog::Index** $sup9688x154x0x0x0index3;  slog::Index** pbranchindex4;  slog::Index** pbranchindex5;  slog::Index** st_diffindex6;  slog::Index** pbranchindex7;  slog::Index** st_diffindex8;  slog::Index** st_mskdelta9;  slog::Index** $sup9688x154x0x0x0delta10;  slog::Index** pbranchdelta11;  slog::Index** pbranchdelta12;  slog::Index** st_diffdelta13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("st_diff_ans");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("st_msk");
      st_mskindex0 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1, 2});
      slog::Relation* readrel20 = db->getRelation("st_msk");
      st_mskdelta9 = readrel20->getIndex(ord19, true);
      std::vector<u16> ord21({2, 0, 1, 3, 4});
      slog::Relation* readrel22 = db->getRelation("pbranch");
      pbranchindex1 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 2, 3, 4, 0});
      slog::Relation* readrel24 = db->getRelation("pbranch");
      pbranchindex2 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({3, 4, 0, 1, 2, 5, 6, 7, 8});
      slog::Relation* readrel26 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index3 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({3, 4, 0, 1, 2, 5, 6, 7, 8});
      slog::Relation* readrel28 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0delta10 = readrel28->getIndex(ord27, true);
      std::vector<u16> ord29({1, 2, 3, 4, 0});
      slog::Relation* readrel30 = db->getRelation("pbranch");
      pbranchindex4 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 3, 4, 0});
      slog::Relation* readrel32 = db->getRelation("pbranch");
      pbranchindex5 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 3, 4, 0});
      slog::Relation* readrel34 = db->getRelation("pbranch");
      pbranchdelta11 = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({2, 0, 1});
      slog::Relation* readrel36 = db->getRelation("st_diff");
      st_diffindex6 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 3, 4, 0});
      slog::Relation* readrel38 = db->getRelation("pbranch");
      pbranchindex7 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 3, 4, 0});
      slog::Relation* readrel40 = db->getRelation("pbranch");
      pbranchdelta12 = readrel40->getIndex(ord39, true);
      std::vector<u16> ord41({0, 1, 2});
      slog::Relation* readrel42 = db->getRelation("st_diff");
      st_diffindex8 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("st_diff");
      st_diffdelta13 = readrel44->getIndex(ord43, true);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(st_mskindex0, st_mskdelta9, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m45) {
          u64 v_c2 = m45[1]; u64 v_c3 = m45[2];
          if (!slog::exists_probe<5,1>(pbranchindex1, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex2, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<9,2>($sup9688x154x0x0x0index3, $sup9688x154x0x0x0delta10, std::array<u64,9>{v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m46) {
            u64 v_c4 = m46[2]; u64 v_c5 = m46[3]; u64 v_c6 = m46[4]; u64 v_c7 = m46[5]; u64 v_c8 = m46[6]; u64 v_c9 = m46[7]; u64 v_c10 = m46[8];
            u64 v_c11 = _prim_lt(db, v_c6, v_c3);
            if (v_c11 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c11) return;
            if (v_c7 == v_c1) return;
            if (!slog::exists_probe<5,4>(pbranchindex4, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex5, pbranchdelta11, std::array<u64,5>{v_c7, v_c3, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m48) {
              u64 v_c12 = m48[4];
              if (!slog::exists_probe<3,2>(st_diffindex6, std::array<u64,3>{v_c12, v_c4, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex7, pbranchdelta12, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m49) {
                u64 v_c13 = m49[4];
                slog::join_probe_old<3,3>(st_diffindex8, st_diffdelta13, std::array<u64,3>{v_c4, v_c13, v_c12}, [&](const std::array<u64,3>& m50) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c13}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre) (scan st_union __t1gnX289 l u) (body (exists $sup9688x100x0x0x0 (1 5 0 2 3 4 6) 2 l u) (exists pbranch (3 0 1 2 4) 1 u) (exists pbranch (3 0 1 2 4) 1 l) (join st_union_ans (0 1) 1 __t1gnX289 __v0) (join $sup9688x100x0x0x0 (1 5 0 2 3 4 6) 2 l u __t2Q3U288 m p r v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (1 2 0) 2 r v) (join pbranch (1 2 3 4 0) 4 p m u v __t22FG286) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (join pbranch (1 2 3 4 0) 4 p m l r __t1pUK287) (join st_union (0 1 2) 3 __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (join st_union_ans (0 1) 1 __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x100x0x0x0index51;  slog::Index** pbranchindex52;  slog::Index** pbranchindex53;  slog::Index** st_union_ansindex54;  slog::Index** $sup9688x100x0x0x0index55;  slog::Index** pbranchindex56;  slog::Index** st_unionindex57;  slog::Index** pbranchindex58;  slog::Index** st_unionindex59;  slog::Index** pbranchindex60;  slog::Index** st_unionindex61;  slog::Index** st_unionindex62;  slog::Index** st_union_ansindex63;  slog::Index** st_uniondelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord66({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel67 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index51 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({3, 0, 1, 2, 4});
      slog::Relation* readrel69 = db->getRelation("pbranch");
      pbranchindex52 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({3, 0, 1, 2, 4});
      slog::Relation* readrel71 = db->getRelation("pbranch");
      pbranchindex53 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("st_union_ans");
      st_union_ansindex54 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel75 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index55 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 3, 4, 0});
      slog::Relation* readrel77 = db->getRelation("pbranch");
      pbranchindex56 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("st_union");
      st_unionindex57 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 3, 4, 0});
      slog::Relation* readrel81 = db->getRelation("pbranch");
      pbranchindex58 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 0, 1});
      slog::Relation* readrel83 = db->getRelation("st_union");
      st_unionindex59 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 2, 3, 4, 0});
      slog::Relation* readrel85 = db->getRelation("pbranch");
      pbranchindex60 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 1, 2});
      slog::Relation* readrel87 = db->getRelation("st_union");
      st_unionindex61 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("st_union");
      st_unionindex62 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("st_union");
      st_uniondelta64 = readrel91->getIndex(ord90, true);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("st_union_ans");
      st_union_ansindex63 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x100x0x0x0index51, std::array<u64,7>{v_c5, v_c9, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex52, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex53, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex54, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m94) {
          u64 v_c1 = m94[1];
          slog::join_probe<7,2>($sup9688x100x0x0x0index55, std::array<u64,7>{v_c5, v_c9, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m95) {
            u64 v_c15 = m95[2]; u64 v_c6 = m95[3]; u64 v_c2 = m95[4]; u64 v_c8 = m95[5]; u64 v_c10 = m95[6];
            if (!slog::exists_probe<5,4>(pbranchindex56, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_unionindex57, std::array<u64,3>{v_c8, v_c10, 0})) return;
            slog::join_probe<5,4>(pbranchindex58, std::array<u64,5>{v_c2, v_c6, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m96) {
              u64 v_c16 = m96[4];
              if (!slog::exists_probe<3,2>(st_unionindex59, std::array<u64,3>{v_c16, v_c15, 0})) return;
              slog::join_probe<5,4>(pbranchindex60, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m97) {
                u64 v_c17 = m97[4];
                slog::join_probe<3,3>(st_unionindex61, std::array<u64,3>{v_c15, v_c17, v_c16}, [&](const std::array<u64,3>& m98) {
                  slog::join_probe_old<3,2>(st_unionindex62, st_uniondelta64, std::array<u64,3>{v_c8, v_c10, 0}, [&](const std::array<u64,3>& m99) {
                    u64 v_c18 = m99[2];
                    slog::join_probe<2,1>(st_union_ansindex63, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m100) {
                      u64 v_c19 = m100[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c15, v_c1, v_c19, v_c6, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c6, v_c1, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre) (scan st_diff __t60WQ241 s __t5zQO240) (body (join pleaf (0 1) 1 __t5zQO240 k)) (head (mkstruct st_del (1 2 0) __14DP1086 s k)) set.slog:133 #f)
  class ReadTask102 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex101;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("pleaf");
      pleafindex101 = readrel104->getIndex(ord103, false);
  
    }
    ReadTask102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe<2,1>(pleafindex101, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m105) {
          u64 v_c23 = m105[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask102* _cont = new ReadTask102(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask102(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan st_ins_ans __t2KGA263 __v0) (body (join-old st_ins (0 2 1) 1 (0 2 1) __t2KGA263 k r) (exists $sup9688x52x0x0x1 (2 6 0 1 3 4 5) 2 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_ins (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x52x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t7CbB259 l m p) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 6 (3 4 5 6 0 2 1) l m p r __t7CbB259 k __t57zq262) (exists st_msk (1 2 0) 3 k m __t57zq262) (exists st_msk_ans (0 1) 2 __t57zq262 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0vi9258) (join-old st_ins (0 2 1) 3 (0 2 1) __t7CbB259 k __t0vi9258) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex106;  slog::Index** $sup9688x52x0x0x1index107;  slog::Index** pbranchindex108;  slog::Index** st_insindex109;  slog::Index** st_mskindex110;  slog::Index** $sup9688x52x0x0x0index111;  slog::Index** pbranchindex112;  slog::Index** st_insindex113;  slog::Index** st_mskindex114;  slog::Index** st_msk_ansindex115;  slog::Index** $sup9688x52x0x0x1index116;  slog::Index** st_mskindex117;  slog::Index** st_msk_ansindex118;  slog::Index** pbranchindex119;  slog::Index** st_insindex120;  slog::Index** st_mskindex121;  slog::Index** st_msk_ansindex122;  slog::Index** st_insdelta123;  slog::Index** $sup9688x52x0x0x0delta124;  slog::Index** $sup9688x52x0x0x1delta125;  slog::Index** pbranchdelta126;  slog::Index** st_insdelta127;  slog::Index** st_mskdelta128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord130({0, 2, 1});
      slog::Relation* readrel131 = db->getRelation("st_ins");
      st_insindex106 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({0, 2, 1});
      slog::Relation* readrel133 = db->getRelation("st_ins");
      st_insdelta123 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({2, 6, 0, 1, 3, 4, 5});
      slog::Relation* readrel135 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index107 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({4, 0, 1, 2, 3});
      slog::Relation* readrel137 = db->getRelation("pbranch");
      pbranchindex108 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({2, 0, 1});
      slog::Relation* readrel139 = db->getRelation("st_ins");
      st_insindex109 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("st_msk");
      st_mskindex110 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel143 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index111 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel145 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0delta124 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({1, 2, 3, 4, 0});
      slog::Relation* readrel147 = db->getRelation("pbranch");
      pbranchindex112 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 2, 1});
      slog::Relation* readrel149 = db->getRelation("st_ins");
      st_insindex113 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 0});
      slog::Relation* readrel151 = db->getRelation("st_msk");
      st_mskindex114 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 0});
      slog::Relation* readrel153 = db->getRelation("st_msk_ans");
      st_msk_ansindex115 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel155 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index116 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel157 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1delta125 = readrel157->getIndex(ord156, true);
      std::vector<u16> ord158({1, 2, 0});
      slog::Relation* readrel159 = db->getRelation("st_msk");
      st_mskindex117 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("st_msk_ans");
      st_msk_ansindex118 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 2, 3, 4, 0});
      slog::Relation* readrel163 = db->getRelation("pbranch");
      pbranchindex119 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 3, 4, 0});
      slog::Relation* readrel165 = db->getRelation("pbranch");
      pbranchdelta126 = readrel165->getIndex(ord164, true);
      std::vector<u16> ord166({0, 2, 1});
      slog::Relation* readrel167 = db->getRelation("st_ins");
      st_insindex120 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 2, 1});
      slog::Relation* readrel169 = db->getRelation("st_ins");
      st_insdelta127 = readrel169->getIndex(ord168, true);
      std::vector<u16> ord170({1, 2, 0});
      slog::Relation* readrel171 = db->getRelation("st_msk");
      st_mskindex121 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 0});
      slog::Relation* readrel173 = db->getRelation("st_msk");
      st_mskdelta128 = readrel173->getIndex(ord172, true);
      std::vector<u16> ord174({0, 1});
      slog::Relation* readrel175 = db->getRelation("st_msk_ans");
      st_msk_ansindex122 = readrel175->getIndex(ord174, false);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c25 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<3,1>(st_insindex106, st_insdelta123, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m176) {
          u64 v_c23 = m176[1]; u64 v_c8 = m176[2];
          if (!slog::exists_probe<7,2>($sup9688x52x0x0x1index107, std::array<u64,7>{v_c23, v_c8, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex108, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex109, std::array<u64,3>{v_c23, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex110, std::array<u64,3>{v_c23, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x52x0x0x0index111, $sup9688x52x0x0x0delta124, std::array<u64,6>{v_c23, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m177) {
            u64 v_c26 = m177[2]; u64 v_c5 = m177[3]; u64 v_c6 = m177[4]; u64 v_c2 = m177[5];
            if (!slog::exists_probe<5,4>(pbranchindex112, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_insindex113, std::array<u64,3>{v_c26, v_c23, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex114, std::array<u64,3>{v_c23, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex115, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<7,6>($sup9688x52x0x0x1index116, $sup9688x52x0x0x1delta125, std::array<u64,7>{v_c5, v_c6, v_c2, v_c8, v_c26, v_c23, 0}, [&](const std::array<u64,7>& m178) {
              u64 v_c27 = m178[6];
              if (!slog::exists_probe<3,3>(st_mskindex117, std::array<u64,3>{v_c23, v_c6, v_c27})) return;
              if (!slog::exists_probe<2,2>(st_msk_ansindex118, std::array<u64,2>{v_c27, v_c2})) return;
              slog::join_probe_old<5,4>(pbranchindex119, pbranchdelta126, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m179) {
                u64 v_c28 = m179[4];
                slog::join_probe_old<3,3>(st_insindex120, st_insdelta127, std::array<u64,3>{v_c26, v_c23, v_c28}, [&](const std::array<u64,3>& m180) {
                  slog::join_probe_old<3,3>(st_mskindex121, st_mskdelta128, std::array<u64,3>{v_c23, v_c6, v_c27}, [&](const std::array<u64,3>& m181) {
                    slog::join_probe<2,2>(st_msk_ansindex122, std::array<u64,2>{v_c27, v_c2}, [&](const std::array<u64,2>& m182) {
                      u64 v_c29 = _prim_band(db, v_c23, v_c6);
                      if (v_c29 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c30 = _prim_gt(db, v_c29, v_c24);
                      if (v_c30 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c30) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c26, v_c1, v_c5, v_c6, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c6, v_c5, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_ins_ans", _fires);
  
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
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_hsb_ans __t2flT468 __v0) (body (exists st_hsb_ans (0 1) 1 __t2flT468) (exists $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t2flT468 __v0) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 2 __t2flT468 __v0) (join st_hsb_ans (0 1) 1 __t2flT468 __v3) (exists $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t2flT468 __v0 __v3) (join st_hsb_ans (0 1) 1 __t2flT468 __v1) (exists st_msk (2 0 1) 1 __v1) (join $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2flT468 __v0 __v3 __v1 __t4PzE464 dup2gd61405 dup5ZAM1406 p0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t0rt9471) (join st_msk_ans (0 1) 1 __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask201 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex184;  slog::Index** $sup9688x40x0x0x2index185;  slog::Index** $sup9688x40x0x0x1index186;  slog::Index** st_hsb_ansindex187;  slog::Index** $sup9688x40x0x0x2index188;  slog::Index** st_hsb_ansindex189;  slog::Index** st_mskindex190;  slog::Index** $sup9688x40x0x0x2index191;  slog::Index** $sup9688x40x0x0x1index192;  slog::Index** $sup9688x40x0x0x0index193;  slog::Index** st_joinindex194;  slog::Index** st_mskindex195;  slog::Index** st_msk_ansindex196;  slog::Index** st_hsbindex197;  slog::Index** st_joindelta198;  slog::Index** st_mskdelta199;  slog::Index** st_hsbdelta200;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex184 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel205 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index185 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel207 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index186 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex187 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel211 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index188 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1});
      slog::Relation* readrel213 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex189 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({2, 0, 1});
      slog::Relation* readrel215 = db->getRelation("st_msk");
      st_mskindex190 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel217 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index191 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel219 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index192 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0, 2, 3, 4});
      slog::Relation* readrel221 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index193 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 3, 4, 0});
      slog::Relation* readrel223 = db->getRelation("st_join");
      st_joinindex194 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 3, 4, 0});
      slog::Relation* readrel225 = db->getRelation("st_join");
      st_joindelta198 = readrel225->getIndex(ord224, true);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("st_msk");
      st_mskindex195 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("st_msk");
      st_mskdelta199 = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("st_msk_ans");
      st_msk_ansindex196 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("st_hsb");
      st_hsbindex197 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("st_hsb");
      st_hsbdelta200 = readrel235->getIndex(ord234, true);
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex184, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index185, std::array<u64,11>{v_c32, v_c1, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index186, std::array<u64,7>{v_c32, v_c1, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex187, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m236) {
          u64 v_c33 = m236[1];
          if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index188, std::array<u64,11>{v_c32, v_c1, v_c33, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(st_hsb_ansindex189, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m237) {
            u64 v_c19 = m237[1];
            if (!slog::exists_probe<3,1>(st_mskindex190, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x40x0x0x2index191, std::array<u64,11>{v_c32, v_c1, v_c33, v_c19, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m238) {
              u64 v_c34 = m238[4]; u64 v_c35 = m238[5]; u64 v_c36 = m238[6]; u64 v_c37 = m238[7]; u64 v_c38 = m238[8]; u64 v_c39 = m238[9]; u64 v_c40 = m238[10];
              if (v_c32 != v_c36) return;
              if (v_c32 != v_c35) return;
              slog::join_probe<7,7>($sup9688x40x0x0x1index192, std::array<u64,7>{v_c34, v_c37, v_c38, v_c39, v_c40, v_c32, v_c1}, [&](const std::array<u64,7>& m239) {
                slog::join_probe<5,5>($sup9688x40x0x0x0index193, std::array<u64,5>{v_c37, v_c34, v_c38, v_c39, v_c40}, [&](const std::array<u64,5>& m240) {
                  slog::join_probe_old<5,5>(st_joinindex194, st_joindelta198, std::array<u64,5>{v_c37, v_c39, v_c38, v_c40, v_c34}, [&](const std::array<u64,5>& m241) {
                    slog::join_probe_old<3,2>(st_mskindex195, st_mskdelta199, std::array<u64,3>{v_c37, v_c19, 0}, [&](const std::array<u64,3>& m242) {
                      u64 v_c41 = m242[2];
                      slog::join_probe<2,1>(st_msk_ansindex196, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m243) {
                        u64 v_c42 = m243[1];
                        u64 v_c43 = _prim_bxor(db, v_c37, v_c38);
                        if (v_c43 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex197, st_hsbdelta200, std::array<u64,2>{v_c32, v_c43}, [&](const std::array<u64,2>& m244) {
                          u64 v_c44 = _prim_band(db, v_c37, v_c1);
                          if (v_c44 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c45 = _prim_gt(db, v_c44, v_c31);
                          if (v_c45 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c45) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c34, v_c42, v_c33, v_c39, v_c40});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c42, v_c33, v_c40, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask201* _cont = new ReadTask201(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask201(db,b), false);
  // (crule (pre) (scan st_diff __t0EGY419 __t1fgd418 __t7ytQ417) (body (exists $sup9688x154x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t0EGY419) (join pbranch (0 1 2 3 4) 1 __t7ytQ417 q n u v) (exists st_msk (2 0 1) 1 n) (join $sup9688x154x0x0x0 (3 5 7 8 0 1 2 4 6) 5 n q u v __t0EGY419 l m p r) (cmp lt m n) (join pbranch (1 2 3 4 0) 5 p m l r __t1fgd418) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t8lOi420) (join st_msk_ans (0 1) 1 __t8lOi420 __v0) (neq q __v0)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x154x0x0x0index246;  slog::Index** pbranchindex247;  slog::Index** st_mskindex248;  slog::Index** $sup9688x154x0x0x0index249;  slog::Index** pbranchindex250;  slog::Index** st_mskindex251;  slog::Index** st_msk_ansindex252;  slog::Index** st_mskdelta253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord255({0, 1});
      slog::Relation* readrel256 = db->getRelation("st_diff_ans");
      head_index[0] = readrel256->getIndex(ord255, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord257({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel258 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index246 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({0, 1, 2, 3, 4});
      slog::Relation* readrel260 = db->getRelation("pbranch");
      pbranchindex247 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({2, 0, 1});
      slog::Relation* readrel262 = db->getRelation("st_msk");
      st_mskindex248 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel264 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index249 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 3, 4, 0});
      slog::Relation* readrel266 = db->getRelation("pbranch");
      pbranchindex250 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("st_msk");
      st_mskindex251 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("st_msk");
      st_mskdelta253 = readrel270->getIndex(ord269, true);
      std::vector<u16> ord271({0, 1});
      slog::Relation* readrel272 = db->getRelation("st_msk_ans");
      st_msk_ansindex252 = readrel272->getIndex(ord271, false);
  
    }
    ReadTask254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x154x0x0x0index246, std::array<u64,9>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(pbranchindex247, std::array<u64,5>{v_c12, 0, 0, 0, 0}, [&](const std::array<u64,5>& m273) {
          u64 v_c7 = m273[1]; u64 v_c3 = m273[2]; u64 v_c9 = m273[3]; u64 v_c10 = m273[4];
          if (!slog::exists_probe<3,1>(st_mskindex248, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<9,5>($sup9688x154x0x0x0index249, std::array<u64,9>{v_c3, v_c7, v_c9, v_c10, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,9>& m274) {
            u64 v_c5 = m274[5]; u64 v_c6 = m274[6]; u64 v_c2 = m274[7]; u64 v_c8 = m274[8];
            u64 v_c46 = _prim_lt(db, v_c6, v_c3);
            if (v_c46 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c46) return;
            slog::join_probe<5,5>(pbranchindex250, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, v_c13}, [&](const std::array<u64,5>& m276) {
              slog::join_probe_old<3,2>(st_mskindex251, st_mskdelta253, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m277) {
                u64 v_c0 = m277[2];
                slog::join_probe<2,1>(st_msk_ansindex252, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m278) {
                  u64 v_c1 = m278[1];
                  if (v_c7 == v_c1) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c13}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask254* _cont = new ReadTask254(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask254(db,b), false);
  // (crule (pre) (scan st_diff __t5pD6408 __t3cJ7407 __t9ous406) (body (exists $sup9688x136x0x0x0 (0 1 2 3 4 5 6) 1 __t5pD6408) (join pbranch (0 1 2 3 4) 1 __t9ous406 p m u v) (exists pbranch (0 1 2 3 4) 3 __t3cJ7407 p m) (exists st_diff (2 0 1) 1 u) (exists st_diff (2 0 1) 1 v) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x136x0x0x0 (2 3 5 6 0 1 4) 5 m p u v __t5pD6408 l r) (join pbranch (1 2 3 4 0) 5 p m l r __t3cJ7407) (exists st_diff (1 2 0) 2 r v) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (exists st_diff_ans (0 1) 1 __t6cu0410) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (exists st_diff_ans (0 1) 1 __t8u30411) (join-old st_bld (1 2 3 4 0) 2 (1 2 3 4 0) p m __v0 __v1 __t9obY409) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask299 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index279;  slog::Index** pbranchindex280;  slog::Index** pbranchindex281;  slog::Index** st_diffindex282;  slog::Index** st_diffindex283;  slog::Index** st_bldindex284;  slog::Index** $sup9688x136x0x0x0index285;  slog::Index** pbranchindex286;  slog::Index** st_diffindex287;  slog::Index** st_diffindex288;  slog::Index** st_diff_ansindex289;  slog::Index** st_diffindex290;  slog::Index** st_diff_ansindex291;  slog::Index** st_bldindex292;  slog::Index** st_diff_ansindex293;  slog::Index** st_diff_ansindex294;  slog::Index** st_bld_ansindex295;  slog::Index** st_diffdelta296;  slog::Index** st_diffdelta297;  slog::Index** st_blddelta298;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("st_diff_ans");
      head_index[0] = readrel301->getIndex(ord300, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord302({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel303 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index279 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1, 2, 3, 4});
      slog::Relation* readrel305 = db->getRelation("pbranch");
      pbranchindex280 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1, 2, 3, 4});
      slog::Relation* readrel307 = db->getRelation("pbranch");
      pbranchindex281 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({2, 0, 1});
      slog::Relation* readrel309 = db->getRelation("st_diff");
      st_diffindex282 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({2, 0, 1});
      slog::Relation* readrel311 = db->getRelation("st_diff");
      st_diffindex283 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("st_bld");
      st_bldindex284 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel315 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index285 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 2, 3, 4, 0});
      slog::Relation* readrel317 = db->getRelation("pbranch");
      pbranchindex286 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("st_diff");
      st_diffindex287 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 0});
      slog::Relation* readrel321 = db->getRelation("st_diff");
      st_diffindex288 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("st_diff");
      st_diffdelta296 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("st_diff_ans");
      st_diff_ansindex289 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 0});
      slog::Relation* readrel327 = db->getRelation("st_diff");
      st_diffindex290 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("st_diff");
      st_diffdelta297 = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({0, 1});
      slog::Relation* readrel331 = db->getRelation("st_diff_ans");
      st_diff_ansindex291 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 3, 4, 0});
      slog::Relation* readrel333 = db->getRelation("st_bld");
      st_bldindex292 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 3, 4, 0});
      slog::Relation* readrel335 = db->getRelation("st_bld");
      st_blddelta298 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("st_diff_ans");
      st_diff_ansindex293 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("st_diff_ans");
      st_diff_ansindex294 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("st_bld_ans");
      st_bld_ansindex295 = readrel341->getIndex(ord340, false);
  
    }
    ReadTask299(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c49 = _t[2];
        if (!slog::exists_probe<7,1>($sup9688x136x0x0x0index279, std::array<u64,7>{v_c47, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(pbranchindex280, std::array<u64,5>{v_c49, 0, 0, 0, 0}, [&](const std::array<u64,5>& m342) {
          u64 v_c2 = m342[1]; u64 v_c6 = m342[2]; u64 v_c9 = m342[3]; u64 v_c10 = m342[4];
          if (!slog::exists_probe<5,3>(pbranchindex281, std::array<u64,5>{v_c48, v_c2, v_c6, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex282, std::array<u64,3>{v_c9, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex283, std::array<u64,3>{v_c10, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex284, std::array<u64,5>{v_c2, v_c6, 0, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x136x0x0x0index285, std::array<u64,7>{v_c6, v_c2, v_c9, v_c10, v_c47, 0, 0}, [&](const std::array<u64,7>& m343) {
            u64 v_c5 = m343[5]; u64 v_c8 = m343[6];
            slog::join_probe<5,5>(pbranchindex286, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, v_c48}, [&](const std::array<u64,5>& m344) {
              if (!slog::exists_probe<3,2>(st_diffindex287, std::array<u64,3>{v_c8, v_c10, 0})) return;
              slog::join_probe_old<3,2>(st_diffindex288, st_diffdelta296, std::array<u64,3>{v_c5, v_c9, 0}, [&](const std::array<u64,3>& m345) {
                u64 v_c50 = m345[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex289, std::array<u64,2>{v_c50, 0})) return;
                slog::join_probe_old<3,2>(st_diffindex290, st_diffdelta297, std::array<u64,3>{v_c8, v_c10, 0}, [&](const std::array<u64,3>& m346) {
                  u64 v_c51 = m346[2];
                  if (!slog::exists_probe<2,1>(st_diff_ansindex291, std::array<u64,2>{v_c51, 0})) return;
                  slog::join_probe_old<5,2>(st_bldindex292, st_blddelta298, std::array<u64,5>{v_c2, v_c6, 0, 0, 0}, [&](const std::array<u64,5>& m347) {
                    u64 v_c1 = m347[2]; u64 v_c19 = m347[3]; u64 v_c52 = m347[4];
                    slog::join_probe<2,2>(st_diff_ansindex293, std::array<u64,2>{v_c50, v_c1}, [&](const std::array<u64,2>& m348) {
                      slog::join_probe<2,2>(st_diff_ansindex294, std::array<u64,2>{v_c51, v_c19}, [&](const std::array<u64,2>& m349) {
                        slog::join_probe<2,1>(st_bld_ansindex295, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m350) {
                          u64 v_c53 = m350[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c47, v_c53}, std::array<u16,2>{0, 1});
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
        ReadTask299* _cont = new ReadTask299(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask299(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t3nJI327 p) (body (exists $sup9688x70x0x0x0 (4 2 3 5 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t3nJI327 k m) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_mem0 (2 0 1) 1 k) (join-old $sup9688x70x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t6uqp323 l r) (exists st_mem0 (2 0 1) 2 k __t6uqp323) (exists st_mem0 (1 2 0) 2 l k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t7Uqa322) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6uqp323 __t7Uqa322 k) (join-old st_mem0 (1 2 0) 2 (1 2 0) l k __t14DN326) (join st_mem0_ans (0 1) 1 __t14DN326 a) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x70x0x0x0index351;  slog::Index** pbranchindex352;  slog::Index** st_mskindex353;  slog::Index** pbranchindex354;  slog::Index** st_mem0index355;  slog::Index** $sup9688x70x0x0x0index356;  slog::Index** st_mem0index357;  slog::Index** st_mem0index358;  slog::Index** pbranchindex359;  slog::Index** st_mem0index360;  slog::Index** st_mem0index361;  slog::Index** st_mem0_ansindex362;  slog::Index** st_mskdelta363;  slog::Index** $sup9688x70x0x0x0delta364;  slog::Index** pbranchdelta365;  slog::Index** st_mem0delta366;  slog::Index** st_mem0delta367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord369({0, 1});
      slog::Relation* readrel370 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord371({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel372 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index351 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({1, 2, 3, 4, 0});
      slog::Relation* readrel374 = db->getRelation("pbranch");
      pbranchindex352 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({0, 1, 2});
      slog::Relation* readrel376 = db->getRelation("st_msk");
      st_mskindex353 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({0, 1, 2});
      slog::Relation* readrel378 = db->getRelation("st_msk");
      st_mskdelta363 = readrel378->getIndex(ord377, true);
      std::vector<u16> ord379({1, 2, 3, 4, 0});
      slog::Relation* readrel380 = db->getRelation("pbranch");
      pbranchindex354 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({2, 0, 1});
      slog::Relation* readrel382 = db->getRelation("st_mem0");
      st_mem0index355 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel384 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index356 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel386 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0delta364 = readrel386->getIndex(ord385, true);
      std::vector<u16> ord387({2, 0, 1});
      slog::Relation* readrel388 = db->getRelation("st_mem0");
      st_mem0index357 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_mem0");
      st_mem0index358 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 3, 4, 0});
      slog::Relation* readrel392 = db->getRelation("pbranch");
      pbranchindex359 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 2, 3, 4, 0});
      slog::Relation* readrel394 = db->getRelation("pbranch");
      pbranchdelta365 = readrel394->getIndex(ord393, true);
      std::vector<u16> ord395({0, 1, 2});
      slog::Relation* readrel396 = db->getRelation("st_mem0");
      st_mem0index360 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("st_mem0");
      st_mem0delta366 = readrel398->getIndex(ord397, true);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("st_mem0");
      st_mem0index361 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 0});
      slog::Relation* readrel402 = db->getRelation("st_mem0");
      st_mem0delta367 = readrel402->getIndex(ord401, true);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex362 = readrel404->getIndex(ord403, false);
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c55 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x70x0x0x0index351, std::array<u64,6>{v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex352, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex353, st_mskdelta363, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m405) {
          u64 v_c23 = m405[1]; u64 v_c6 = m405[2];
          if (!slog::exists_probe<5,2>(pbranchindex354, std::array<u64,5>{v_c2, v_c6, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mem0index355, std::array<u64,3>{v_c23, 0, 0})) return;
          slog::join_probe_old<6,3>($sup9688x70x0x0x0index356, $sup9688x70x0x0x0delta364, std::array<u64,6>{v_c23, v_c6, v_c2, 0, 0, 0}, [&](const std::array<u64,6>& m406) {
            u64 v_c56 = m406[3]; u64 v_c5 = m406[4]; u64 v_c8 = m406[5];
            if (!slog::exists_probe<3,2>(st_mem0index357, std::array<u64,3>{v_c23, v_c56, 0})) return;
            if (!slog::exists_probe<3,2>(st_mem0index358, std::array<u64,3>{v_c5, v_c23, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex359, pbranchdelta365, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m407) {
              u64 v_c57 = m407[4];
              slog::join_probe_old<3,3>(st_mem0index360, st_mem0delta366, std::array<u64,3>{v_c56, v_c57, v_c23}, [&](const std::array<u64,3>& m408) {
                slog::join_probe_old<3,2>(st_mem0index361, st_mem0delta367, std::array<u64,3>{v_c5, v_c23, 0}, [&](const std::array<u64,3>& m409) {
                  u64 v_c58 = m409[2];
                  slog::join_probe<2,1>(st_mem0_ansindex362, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m410) {
                    u64 v_c59 = m410[1];
                    u64 v_c60 = _prim_band(db, v_c23, v_c6);
                    if (v_c60 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c61 = _prim_lt(db, v_c60, v_c54);
                    if (v_c61 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c61) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c59}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre) (scan st_diff __t3Vft148 __t8pVe147 __t0w8p146) (body (exists $sup9688x145x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t3Vft148) (join pbranch (0 1 2 3 4) 1 __t0w8p146 q n u v) (exists st_msk (1 2 0) 1 q) (join $sup9688x145x0x0x0 (3 5 7 8 0 1 2 4 6) 5 n q u v __t3Vft148 l m p r) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 p m l r __t8pVe147) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t7gQz149) (join st_msk_ans (0 1) 1 __t7gQz149 __v0) (neq p __v0)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask420 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x145x0x0x0index412;  slog::Index** pbranchindex413;  slog::Index** st_mskindex414;  slog::Index** $sup9688x145x0x0x0index415;  slog::Index** pbranchindex416;  slog::Index** st_mskindex417;  slog::Index** st_msk_ansindex418;  slog::Index** st_mskdelta419;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("st_diff_ans");
      head_index[0] = readrel422->getIndex(ord421, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord423({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel424 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index412 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1, 2, 3, 4});
      slog::Relation* readrel426 = db->getRelation("pbranch");
      pbranchindex413 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 0});
      slog::Relation* readrel428 = db->getRelation("st_msk");
      st_mskindex414 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel430 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index415 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({1, 2, 3, 4, 0});
      slog::Relation* readrel432 = db->getRelation("pbranch");
      pbranchindex416 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 0});
      slog::Relation* readrel434 = db->getRelation("st_msk");
      st_mskindex417 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 0});
      slog::Relation* readrel436 = db->getRelation("st_msk");
      st_mskdelta419 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("st_msk_ans");
      st_msk_ansindex418 = readrel438->getIndex(ord437, false);
  
    }
    ReadTask420(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x145x0x0x0index412, std::array<u64,9>{v_c62, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(pbranchindex413, std::array<u64,5>{v_c64, 0, 0, 0, 0}, [&](const std::array<u64,5>& m439) {
          u64 v_c7 = m439[1]; u64 v_c3 = m439[2]; u64 v_c9 = m439[3]; u64 v_c10 = m439[4];
          if (!slog::exists_probe<3,1>(st_mskindex414, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe<9,5>($sup9688x145x0x0x0index415, std::array<u64,9>{v_c3, v_c7, v_c9, v_c10, v_c62, 0, 0, 0, 0}, [&](const std::array<u64,9>& m440) {
            u64 v_c5 = m440[5]; u64 v_c6 = m440[6]; u64 v_c2 = m440[7]; u64 v_c8 = m440[8];
            u64 v_c65 = _prim_lt(db, v_c3, v_c6);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c65) return;
            slog::join_probe<5,5>(pbranchindex416, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, v_c63}, [&](const std::array<u64,5>& m442) {
              slog::join_probe_old<3,2>(st_mskindex417, st_mskdelta419, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m443) {
                u64 v_c66 = m443[2];
                slog::join_probe<2,1>(st_msk_ansindex418, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m444) {
                  u64 v_c1 = m444[1];
                  if (v_c2 == v_c1) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c63}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask420* _cont = new ReadTask420(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask420(db,b), false);
  // (crule (pre) (scan st_hsb_ans __t5IW626 __v1) (body (join st_hsb_ans (0 1) 1 __t5IW626 __v3) (join-old st_hsb (0 1) 1 (0 1) __t5IW626 __t8vKi27) (join-old $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk2iuo1278 (bxor p0 p1)) (eq __t8vKi27 chk2iuo1278)) (head (emit $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t5IW626 __t5IW626 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask450 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex445;  slog::Index** st_hsbindex446;  slog::Index** $sup9688x36x0x0x1index447;  slog::Index** st_hsbdelta448;  slog::Index** $sup9688x36x0x0x1delta449;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord451({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel452 = db->getRelation("$sup9688x36x0x0x2");
      head_index[0] = readrel452->getIndex(ord451, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord453({0, 1});
      slog::Relation* readrel454 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex445 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({0, 1});
      slog::Relation* readrel456 = db->getRelation("st_hsb");
      st_hsbindex446 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({0, 1});
      slog::Relation* readrel458 = db->getRelation("st_hsb");
      st_hsbdelta448 = readrel458->getIndex(ord457, true);
      std::vector<u16> ord459({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel460 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index447 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel462 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1delta449 = readrel462->getIndex(ord461, true);
  
    }
    ReadTask450(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe<2,1>(st_hsb_ansindex445, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m463) {
          u64 v_c33 = m463[1];
          slog::join_probe_old<2,1>(st_hsbindex446, st_hsbdelta448, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m464) {
            u64 v_c68 = m464[1];
            slog::join_all_old<7>($sup9688x36x0x0x1index447, $sup9688x36x0x0x1delta449, [&](const std::array<u64,7>& m465) {
              u64 v_c69 = m465[0]; u64 v_c1 = m465[1]; u64 v_c70 = m465[2]; u64 v_c37 = m465[3]; u64 v_c38 = m465[4]; u64 v_c39 = m465[5]; u64 v_c40 = m465[6];
              u64 v_c71 = _prim_bxor(db, v_c37, v_c38);
              if (v_c71 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
              if (v_c68 != v_c71) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c69, v_c1, v_c33, v_c19, v_c70, v_c67, v_c67, v_c37, v_c38, v_c39, v_c40}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask450* _cont = new ReadTask450(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask450(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan st_mem0_ans __t9V8P506 a) (body (join-old st_mem0 (0 1 2) 1 (0 1 2) __t9V8P506 r k) (exists pbranch (4 0 1 2 3) 1 r) (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x72x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t6Rw6503 l m p) (exists st_mem0 (2 0 1) 2 k __t6Rw6503) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1XtO502) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6Rw6503 __t1XtO502 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t4A7W507) (join-old st_msk_ans (0 1) 2 (0 1) __t4A7W507 p) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask484 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index466;  slog::Index** pbranchindex467;  slog::Index** st_mem0index468;  slog::Index** st_mskindex469;  slog::Index** $sup9688x72x0x0x0index470;  slog::Index** st_mem0index471;  slog::Index** st_mskindex472;  slog::Index** st_msk_ansindex473;  slog::Index** pbranchindex474;  slog::Index** st_mem0index475;  slog::Index** st_mskindex476;  slog::Index** st_msk_ansindex477;  slog::Index** st_mem0delta478;  slog::Index** $sup9688x72x0x0x0delta479;  slog::Index** pbranchdelta480;  slog::Index** st_mem0delta481;  slog::Index** st_mskdelta482;  slog::Index** st_msk_ansdelta483;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel486->getIndex(ord485, false);
      outer_rel = db->getRelation("st_mem0_ans");
      std::vector<u16> ord487({0, 1, 2});
      slog::Relation* readrel488 = db->getRelation("st_mem0");
      st_mem0index466 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({0, 1, 2});
      slog::Relation* readrel490 = db->getRelation("st_mem0");
      st_mem0delta478 = readrel490->getIndex(ord489, true);
      std::vector<u16> ord491({4, 0, 1, 2, 3});
      slog::Relation* readrel492 = db->getRelation("pbranch");
      pbranchindex467 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({2, 0, 1});
      slog::Relation* readrel494 = db->getRelation("st_mem0");
      st_mem0index468 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("st_msk");
      st_mskindex469 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel498 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index470 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel500 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0delta479 = readrel500->getIndex(ord499, true);
      std::vector<u16> ord501({2, 0, 1});
      slog::Relation* readrel502 = db->getRelation("st_mem0");
      st_mem0index471 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("st_msk");
      st_mskindex472 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("st_msk_ans");
      st_msk_ansindex473 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 2, 3, 4, 0});
      slog::Relation* readrel508 = db->getRelation("pbranch");
      pbranchindex474 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 3, 4, 0});
      slog::Relation* readrel510 = db->getRelation("pbranch");
      pbranchdelta480 = readrel510->getIndex(ord509, true);
      std::vector<u16> ord511({0, 1, 2});
      slog::Relation* readrel512 = db->getRelation("st_mem0");
      st_mem0index475 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1, 2});
      slog::Relation* readrel514 = db->getRelation("st_mem0");
      st_mem0delta481 = readrel514->getIndex(ord513, true);
      std::vector<u16> ord515({1, 2, 0});
      slog::Relation* readrel516 = db->getRelation("st_msk");
      st_mskindex476 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 2, 0});
      slog::Relation* readrel518 = db->getRelation("st_msk");
      st_mskdelta482 = readrel518->getIndex(ord517, true);
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("st_msk_ans");
      st_msk_ansindex477 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 1});
      slog::Relation* readrel522 = db->getRelation("st_msk_ans");
      st_msk_ansdelta483 = readrel522->getIndex(ord521, true);
  
    }
    ReadTask484(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        slog::join_probe_old<3,1>(st_mem0index466, st_mem0delta478, std::array<u64,3>{v_c73, 0, 0}, [&](const std::array<u64,3>& m523) {
          u64 v_c8 = m523[1]; u64 v_c23 = m523[2];
          if (!slog::exists_probe<5,1>(pbranchindex467, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mem0index468, std::array<u64,3>{v_c23, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex469, std::array<u64,3>{v_c23, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x72x0x0x0index470, $sup9688x72x0x0x0delta479, std::array<u64,6>{v_c23, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m524) {
            u64 v_c74 = m524[2]; u64 v_c5 = m524[3]; u64 v_c6 = m524[4]; u64 v_c2 = m524[5];
            if (!slog::exists_probe<3,2>(st_mem0index471, std::array<u64,3>{v_c23, v_c74, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex472, std::array<u64,3>{v_c23, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex473, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex474, pbranchdelta480, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m525) {
              u64 v_c75 = m525[4];
              slog::join_probe_old<3,3>(st_mem0index475, st_mem0delta481, std::array<u64,3>{v_c74, v_c75, v_c23}, [&](const std::array<u64,3>& m526) {
                slog::join_probe_old<3,2>(st_mskindex476, st_mskdelta482, std::array<u64,3>{v_c23, v_c6, 0}, [&](const std::array<u64,3>& m527) {
                  u64 v_c76 = m527[2];
                  slog::join_probe_old<2,2>(st_msk_ansindex477, st_msk_ansdelta483, std::array<u64,2>{v_c76, v_c2}, [&](const std::array<u64,2>& m528) {
                    u64 v_c77 = _prim_band(db, v_c23, v_c6);
                    if (v_c77 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c78 = _prim_gt(db, v_c77, v_c72);
                    if (v_c78 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c78) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c74, v_c59}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:st_mem0_ans", _fires);
  
      if (!_done)
      {
        ReadTask484* _cont = new ReadTask484(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask484(db,b), false);
  // (crule (pre) (scan st_union __t1PdV132 __t9DTf133 __t972J134) (body (exists $sup9688x110x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t1PdV132 __t9DTf133 __t972J134) (join-old st_join (2 4 0 1 3) 2 (2 4 0 1 3) __t9DTf133 __t972J134 __t744h135 p q) (exists pbranch (0 1 2 3 4) 2 __t9DTf133 p) (exists pbranch (0 1 2 3 4) 2 __t972J134 q) (exists st_msk (1 2 0) 1 q) (exists st_join_ans (0 1) 1 __t744h135) (join $sup9688x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t9DTf133 __t972J134 __t1PdV132 l m n r u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t9DTf133) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t972J134) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask546 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x110x0x0x0index530;  slog::Index** st_joinindex531;  slog::Index** pbranchindex532;  slog::Index** pbranchindex533;  slog::Index** st_mskindex534;  slog::Index** st_join_ansindex535;  slog::Index** $sup9688x110x0x0x0index536;  slog::Index** pbranchindex537;  slog::Index** pbranchindex538;  slog::Index** st_mskindex539;  slog::Index** st_msk_ansindex540;  slog::Index** st_join_ansindex541;  slog::Index** st_joindelta542;  slog::Index** pbranchdelta543;  slog::Index** pbranchdelta544;  slog::Index** st_mskdelta545;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("st_union_ans");
      head_index[0] = readrel548->getIndex(ord547, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord549({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel550 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index530 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({2, 4, 0, 1, 3});
      slog::Relation* readrel552 = db->getRelation("st_join");
      st_joinindex531 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({2, 4, 0, 1, 3});
      slog::Relation* readrel554 = db->getRelation("st_join");
      st_joindelta542 = readrel554->getIndex(ord553, true);
      std::vector<u16> ord555({0, 1, 2, 3, 4});
      slog::Relation* readrel556 = db->getRelation("pbranch");
      pbranchindex532 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1, 2, 3, 4});
      slog::Relation* readrel558 = db->getRelation("pbranch");
      pbranchindex533 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 2, 0});
      slog::Relation* readrel560 = db->getRelation("st_msk");
      st_mskindex534 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("st_join_ans");
      st_join_ansindex535 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel564 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index536 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 3, 4, 0});
      slog::Relation* readrel566 = db->getRelation("pbranch");
      pbranchindex537 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 3, 4, 0});
      slog::Relation* readrel568 = db->getRelation("pbranch");
      pbranchdelta543 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({1, 2, 3, 4, 0});
      slog::Relation* readrel570 = db->getRelation("pbranch");
      pbranchindex538 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("pbranch");
      pbranchdelta544 = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("st_msk");
      st_mskindex539 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("st_msk");
      st_mskdelta545 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("st_msk_ans");
      st_msk_ansindex540 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("st_join_ans");
      st_join_ansindex541 = readrel580->getIndex(ord579, false);
  
    }
    ReadTask546(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[0];
        u64 v_c80 = _t[1];
        u64 v_c81 = _t[2];
        if (!slog::exists_probe<11,3>($sup9688x110x0x0x0index530, std::array<u64,11>{v_c79, v_c80, v_c81, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex531, st_joindelta542, std::array<u64,5>{v_c80, v_c81, 0, 0, 0}, [&](const std::array<u64,5>& m581) {
          u64 v_c82 = m581[2]; u64 v_c2 = m581[3]; u64 v_c7 = m581[4];
          if (!slog::exists_probe<5,2>(pbranchindex532, std::array<u64,5>{v_c80, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex533, std::array<u64,5>{v_c81, v_c7, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex534, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex535, std::array<u64,2>{v_c82, 0})) return;
          slog::join_probe<11,5>($sup9688x110x0x0x0index536, std::array<u64,11>{v_c2, v_c7, v_c80, v_c81, v_c79, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m582) {
            u64 v_c5 = m582[5]; u64 v_c6 = m582[6]; u64 v_c3 = m582[7]; u64 v_c8 = m582[8]; u64 v_c9 = m582[9]; u64 v_c10 = m582[10];
            u64 v_c83 = _prim_lt(db, v_c3, v_c6);
            if (v_c83 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
            if (!v_c83) return;
            slog::join_probe_old<5,5>(pbranchindex537, pbranchdelta543, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, v_c80}, [&](const std::array<u64,5>& m584) {
              slog::join_probe_old<5,5>(pbranchindex538, pbranchdelta544, std::array<u64,5>{v_c7, v_c3, v_c9, v_c10, v_c81}, [&](const std::array<u64,5>& m585) {
                slog::join_probe_old<3,2>(st_mskindex539, st_mskdelta545, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m586) {
                  u64 v_c84 = m586[2];
                  slog::join_probe<2,1>(st_msk_ansindex540, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m587) {
                    u64 v_c1 = m587[1];
                    if (v_c2 == v_c1) return;
                    slog::join_probe<2,1>(st_join_ansindex541, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m588) {
                      u64 v_c53 = m588[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c53}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask546* _cont = new ReadTask546(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask546(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t5pdy283 p) (body (exists $sup9688x88x0x0x0 (4 3 5 2 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (exists st_bld (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t5pdy283 k m) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_del (2 0 1) 1 k) (exists st_bld (1 2 3 4 0) 2 p m) (join-old $sup9688x88x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t3OU0279 l r) (exists st_del (0 2 1) 2 __t3OU0279 k) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_del (1 2 0) 2 l k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2u9k278) (join-old st_del (0 2 1) 3 (0 2 1) __t3OU0279 k __t2u9k278) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t6UON282 __v0) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join-old st_del_ans (0 1) 2 (0 1) __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask615 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index589;  slog::Index** pbranchindex590;  slog::Index** st_bldindex591;  slog::Index** st_mskindex592;  slog::Index** pbranchindex593;  slog::Index** st_delindex594;  slog::Index** st_bldindex595;  slog::Index** $sup9688x88x0x0x0index596;  slog::Index** st_delindex597;  slog::Index** st_bldindex598;  slog::Index** st_delindex599;  slog::Index** pbranchindex600;  slog::Index** st_delindex601;  slog::Index** st_bldindex602;  slog::Index** st_del_ansindex603;  slog::Index** st_bld_ansindex604;  slog::Index** st_delindex605;  slog::Index** st_del_ansindex606;  slog::Index** st_bld_ansindex607;  slog::Index** st_mskdelta608;  slog::Index** $sup9688x88x0x0x0delta609;  slog::Index** pbranchdelta610;  slog::Index** st_deldelta611;  slog::Index** st_blddelta612;  slog::Index** st_deldelta613;  slog::Index** st_del_ansdelta614;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord616({0, 1});
      slog::Relation* readrel617 = db->getRelation("st_del_ans");
      head_index[0] = readrel617->getIndex(ord616, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord618({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel619 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index589 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 3, 4, 0});
      slog::Relation* readrel621 = db->getRelation("pbranch");
      pbranchindex590 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 3, 4, 0});
      slog::Relation* readrel623 = db->getRelation("st_bld");
      st_bldindex591 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({0, 1, 2});
      slog::Relation* readrel625 = db->getRelation("st_msk");
      st_mskindex592 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({0, 1, 2});
      slog::Relation* readrel627 = db->getRelation("st_msk");
      st_mskdelta608 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({1, 2, 3, 4, 0});
      slog::Relation* readrel629 = db->getRelation("pbranch");
      pbranchindex593 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({2, 0, 1});
      slog::Relation* readrel631 = db->getRelation("st_del");
      st_delindex594 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 3, 4, 0});
      slog::Relation* readrel633 = db->getRelation("st_bld");
      st_bldindex595 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel635 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index596 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel637 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0delta609 = readrel637->getIndex(ord636, true);
      std::vector<u16> ord638({0, 2, 1});
      slog::Relation* readrel639 = db->getRelation("st_del");
      st_delindex597 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({2, 1, 4, 0, 3});
      slog::Relation* readrel641 = db->getRelation("st_bld");
      st_bldindex598 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("st_del");
      st_delindex599 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 3, 4, 0});
      slog::Relation* readrel645 = db->getRelation("pbranch");
      pbranchindex600 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 2, 3, 4, 0});
      slog::Relation* readrel647 = db->getRelation("pbranch");
      pbranchdelta610 = readrel647->getIndex(ord646, true);
      std::vector<u16> ord648({0, 2, 1});
      slog::Relation* readrel649 = db->getRelation("st_del");
      st_delindex601 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({0, 2, 1});
      slog::Relation* readrel651 = db->getRelation("st_del");
      st_deldelta611 = readrel651->getIndex(ord650, true);
      std::vector<u16> ord652({2, 1, 4, 0, 3});
      slog::Relation* readrel653 = db->getRelation("st_bld");
      st_bldindex602 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({2, 1, 4, 0, 3});
      slog::Relation* readrel655 = db->getRelation("st_bld");
      st_blddelta612 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 0});
      slog::Relation* readrel657 = db->getRelation("st_del_ans");
      st_del_ansindex603 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("st_bld_ans");
      st_bld_ansindex604 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("st_del");
      st_delindex605 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("st_del");
      st_deldelta613 = readrel663->getIndex(ord662, true);
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("st_del_ans");
      st_del_ansindex606 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("st_del_ans");
      st_del_ansdelta614 = readrel667->getIndex(ord666, true);
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("st_bld_ans");
      st_bld_ansindex607 = readrel669->getIndex(ord668, false);
  
    }
    ReadTask615(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c85 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c86 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x88x0x0x0index589, std::array<u64,6>{v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex590, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex591, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex592, st_mskdelta608, std::array<u64,3>{v_c86, 0, 0}, [&](const std::array<u64,3>& m670) {
          u64 v_c23 = m670[1]; u64 v_c6 = m670[2];
          if (!slog::exists_probe<5,2>(pbranchindex593, std::array<u64,5>{v_c2, v_c6, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex594, std::array<u64,3>{v_c23, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex595, std::array<u64,5>{v_c2, v_c6, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup9688x88x0x0x0index596, $sup9688x88x0x0x0delta609, std::array<u64,6>{v_c23, v_c6, v_c2, 0, 0, 0}, [&](const std::array<u64,6>& m671) {
            u64 v_c87 = m671[3]; u64 v_c5 = m671[4]; u64 v_c8 = m671[5];
            if (!slog::exists_probe<3,2>(st_delindex597, std::array<u64,3>{v_c87, v_c23, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex598, std::array<u64,5>{v_c6, v_c2, v_c8, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex599, std::array<u64,3>{v_c5, v_c23, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex600, pbranchdelta610, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m672) {
              u64 v_c88 = m672[4];
              slog::join_probe_old<3,3>(st_delindex601, st_deldelta611, std::array<u64,3>{v_c87, v_c23, v_c88}, [&](const std::array<u64,3>& m673) {
                slog::join_probe_old<5,3>(st_bldindex602, st_blddelta612, std::array<u64,5>{v_c6, v_c2, v_c8, 0, 0}, [&](const std::array<u64,5>& m674) {
                  u64 v_c89 = m674[3]; u64 v_c1 = m674[4];
                  if (!slog::exists_probe<2,1>(st_del_ansindex603, std::array<u64,2>{v_c1, 0})) return;
                  if (!slog::exists_probe<2,1>(st_bld_ansindex604, std::array<u64,2>{v_c89, 0})) return;
                  slog::join_probe_old<3,2>(st_delindex605, st_deldelta613, std::array<u64,3>{v_c5, v_c23, 0}, [&](const std::array<u64,3>& m675) {
                    u64 v_c90 = m675[2];
                    slog::join_probe_old<2,2>(st_del_ansindex606, st_del_ansdelta614, std::array<u64,2>{v_c90, v_c1}, [&](const std::array<u64,2>& m676) {
                      slog::join_probe<2,1>(st_bld_ansindex607, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m677) {
                        u64 v_c53 = m677[1];
                        u64 v_c91 = _prim_band(db, v_c23, v_c6);
                        if (v_c91 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c92 = _prim_lt(db, v_c91, v_c85);
                        if (v_c92 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c92) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c53}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre (let __trid5HTB850 constcbf5a4e983555adcacc7f2e9) (let __trel6sPV851 consta10f76b4ec574de5d7b6908e) (let __tcol6w1E852 const5feceb66ffc86f38d952786c) (let __trel7ZhX853 consta10f76b4ec574de5d7b6908e) (let __tcol2oP7854 const6b86b273ff34fce19d6b804e)) (scan $sup9688x151x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid5HTB850 __trel6sPV851 __tcol6w1E852 (1 2 3 4 0)) (tycheck n (accept int) __trid5HTB850 __trel7ZhX853 __tcol2oP7854 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __7lTv849 p n)) set.slog:152 #f)
  class ReadTask679 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x151x0x0x0");
  
    }
    ReadTask679(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_constcbf5a4e983555adcacc7f2e9;
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
        u64 v_c70 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c7 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c9 = _t[7];
        u64 v_c10 = _t[8];
        ++_fires;
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c93, v_c94, v_c95, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c93, v_c96, v_c97, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:$sup9688x151x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask679* _cont = new ReadTask679(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask679(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (scan st_ins_ans __t7LWC387 r) (body (exists _enum (1 0) 1 __tconst8Ksp764) (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins (2 0 1) 1 __tconst7Eph382) (exists st_ins (2 0 1) 1 __tconst4emd384) (join-old st_ins (0 2 1) 2 (0 2 1) __t7LWC387 __tconst2ksI386 __v2) (exists st_ins_ans (1 0) 1 __v2) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join-old st_ins (1 2 0) 2 (1 2 0) __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 1 __t2Q6o381 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7Eph382 __t0FtX383) (join st_ins_ans (0 1) 1 __t0FtX383 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4emd384 __t88YX385) (join st_ins_ans (0 1) 2 __t88YX385 __v2)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask697 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex680;  slog::Index** st_insindex681;  slog::Index** st_insindex682;  slog::Index** st_insindex683;  slog::Index** st_insindex684;  slog::Index** st_ins_ansindex685;  slog::Index** _enumindex686;  slog::Index** st_insindex687;  slog::Index** st_ins_ansindex688;  slog::Index** st_insindex689;  slog::Index** st_ins_ansindex690;  slog::Index** st_insindex691;  slog::Index** st_ins_ansindex692;  slog::Index** st_insdelta693;  slog::Index** st_insdelta694;  slog::Index** st_insdelta695;  slog::Index** st_insdelta696;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord698({0});
      slog::Relation* readrel699 = db->getRelation("canon");
      head_index[0] = readrel699->getIndex(ord698, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("_enum");
      _enumindex680 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({2, 0, 1});
      slog::Relation* readrel703 = db->getRelation("st_ins");
      st_insindex681 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({2, 0, 1});
      slog::Relation* readrel705 = db->getRelation("st_ins");
      st_insindex682 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 0, 1});
      slog::Relation* readrel707 = db->getRelation("st_ins");
      st_insindex683 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({0, 2, 1});
      slog::Relation* readrel709 = db->getRelation("st_ins");
      st_insindex684 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 2, 1});
      slog::Relation* readrel711 = db->getRelation("st_ins");
      st_insdelta693 = readrel711->getIndex(ord710, true);
      std::vector<u16> ord712({1, 0});
      slog::Relation* readrel713 = db->getRelation("st_ins_ans");
      st_ins_ansindex685 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("_enum");
      _enumindex686 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 0});
      slog::Relation* readrel717 = db->getRelation("st_ins");
      st_insindex687 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 2, 0});
      slog::Relation* readrel719 = db->getRelation("st_ins");
      st_insdelta694 = readrel719->getIndex(ord718, true);
      std::vector<u16> ord720({0, 1});
      slog::Relation* readrel721 = db->getRelation("st_ins_ans");
      st_ins_ansindex688 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("st_ins");
      st_insindex689 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 0});
      slog::Relation* readrel725 = db->getRelation("st_ins");
      st_insdelta695 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("st_ins_ans");
      st_ins_ansindex690 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({1, 2, 0});
      slog::Relation* readrel729 = db->getRelation("st_ins");
      st_insindex691 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 0});
      slog::Relation* readrel731 = db->getRelation("st_ins");
      st_insdelta696 = readrel731->getIndex(ord730, true);
      std::vector<u16> ord732({0, 1});
      slog::Relation* readrel733 = db->getRelation("st_ins_ans");
      st_ins_ansindex692 = readrel733->getIndex(ord732, false);
  
    }
    ReadTask697(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c100 = v_const2c624232cdd221771294dfbb;
      u64 v_c101 = v_constd4735e3a265e16eee03f5971;
      u64 v_c102 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c103 = _t[0];
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex680, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex681, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex682, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex683, std::array<u64,3>{v_c101, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex684, st_insdelta693, std::array<u64,3>{v_c103, v_c102, 0}, [&](const std::array<u64,3>& m734) {
          u64 v_c42 = m734[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex685, std::array<u64,2>{v_c42, 0})) return;
          slog::join_probe<2,1>(_enumindex686, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m735) {
            u64 v_c104 = m735[1];
            slog::join_probe_old<3,2>(st_insindex687, st_insdelta694, std::array<u64,3>{v_c104, v_c99, 0}, [&](const std::array<u64,3>& m736) {
              u64 v_c105 = m736[2];
              slog::join_probe<2,1>(st_ins_ansindex688, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m737) {
                u64 v_c1 = m737[1];
                slog::join_probe_old<3,2>(st_insindex689, st_insdelta695, std::array<u64,3>{v_c1, v_c100, 0}, [&](const std::array<u64,3>& m738) {
                  u64 v_c106 = m738[2];
                  slog::join_probe<2,1>(st_ins_ansindex690, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m739) {
                    u64 v_c19 = m739[1];
                    slog::join_probe_old<3,2>(st_insindex691, st_insdelta696, std::array<u64,3>{v_c19, v_c101, 0}, [&](const std::array<u64,3>& m740) {
                      u64 v_c107 = m740[2];
                      slog::join_probe<2,2>(st_ins_ansindex692, std::array<u64,2>{v_c107, v_c42}, [&](const std::array<u64,2>& m741) {
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
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask697* _cont = new ReadTask697(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask697(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk0rcV1384 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk0rcV1384) (letp chk2TLU1385 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk2TLU1385) (letp chk4A8w1386 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk4A8w1386) (letp chk42rb1387 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk42rb1387) (letp chk84Xq1388 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk84Xq1388)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask753 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex742;  slog::Index** $seq_atindex743;  slog::Index** $seq_atindex744;  slog::Index** $seq_atindex745;  slog::Index** $seq_atrindex746;  slog::Index** $seq_atrindex747;  slog::Index** $seq_atrindex748;  slog::Index** st_fromlistindex749;  slog::Index** st_fromlist_ansindex750;  slog::Index** $seq_atrdelta751;  slog::Index** $seq_atrdelta752;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord754({0});
      slog::Relation* readrel755 = db->getRelation("canon");
      head_index[0] = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("$seq_atr");
      driver_index = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({1, 0, 2});
      slog::Relation* readrel759 = db->getRelation("$seq_at");
      $seq_atindex742 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0, 2});
      slog::Relation* readrel761 = db->getRelation("$seq_at");
      $seq_atindex743 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0, 2});
      slog::Relation* readrel763 = db->getRelation("$seq_at");
      $seq_atindex744 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 0, 2});
      slog::Relation* readrel765 = db->getRelation("$seq_at");
      $seq_atindex745 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("$seq_atr");
      $seq_atrindex746 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({0, 1, 2});
      slog::Relation* readrel769 = db->getRelation("$seq_atr");
      $seq_atrindex747 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1, 2});
      slog::Relation* readrel771 = db->getRelation("$seq_atr");
      $seq_atrdelta751 = readrel771->getIndex(ord770, true);
      std::vector<u16> ord772({0, 1, 2});
      slog::Relation* readrel773 = db->getRelation("$seq_atr");
      $seq_atrindex748 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 1, 2});
      slog::Relation* readrel775 = db->getRelation("$seq_atr");
      $seq_atrdelta752 = readrel775->getIndex(ord774, true);
      std::vector<u16> ord776({1, 0});
      slog::Relation* readrel777 = db->getRelation("st_fromlist");
      st_fromlistindex749 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex750 = readrel779->getIndex(ord778, false);
  
    }
    ReadTask753(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const2c624232cdd221771294dfbb;
      u64 v_c113 = v_constd4735e3a265e16eee03f5971;
      u64 v_c114 = v_constd4735e3a265e16eee03f5971;
      u64 v_c115 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c116 = v_constef2d127de37b942baad06145;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
      u64 v_c119 = v_const2c624232cdd221771294dfbb;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_constd4735e3a265e16eee03f5971;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_constef2d127de37b942baad06145;
      u64 v_c124 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c127 = v_const2c624232cdd221771294dfbb;
      u64 v_c128 = v_constd4735e3a265e16eee03f5971;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c131 = v_constef2d127de37b942baad06145;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c127, v_c128, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m780) {
        u64 v_c133 = m780[2];
        if (buckethash(v_c133) != bucket) return;
        slog::join_probe<3,3>($seq_atindex742, std::array<u64,3>{v_c118, v_c117, v_c133}, [&](const std::array<u64,3>& m781) {
          slog::join_probe<3,3>($seq_atindex743, std::array<u64,3>{v_c120, v_c119, v_c133}, [&](const std::array<u64,3>& m782) {
            slog::join_probe<3,3>($seq_atindex744, std::array<u64,3>{v_c122, v_c121, v_c133}, [&](const std::array<u64,3>& m783) {
              slog::join_probe<3,3>($seq_atindex745, std::array<u64,3>{v_c124, v_c123, v_c133}, [&](const std::array<u64,3>& m784) {
                slog::join_probe<3,3>($seq_atrindex746, std::array<u64,3>{v_c125, v_c126, v_c133}, [&](const std::array<u64,3>& m785) {
                  slog::join_probe_old<3,3>($seq_atrindex747, $seq_atrdelta751, std::array<u64,3>{v_c129, v_c130, v_c133}, [&](const std::array<u64,3>& m786) {
                    slog::join_probe_old<3,3>($seq_atrindex748, $seq_atrdelta752, std::array<u64,3>{v_c131, v_c132, v_c133}, [&](const std::array<u64,3>& m787) {
                      slog::join_probe<2,1>(st_fromlistindex749, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m788) {
                        u64 v_c134 = m788[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex750, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m789) {
                          u64 v_c8 = m789[1];
                          bool ok790 = true;
                          u64 v_c135 = _prim_aslst(db, v_c133, &ok790);
                          if (!ok790) return;
                          u64 v_c136 = _prim_llen(db, v_c135);
                          if (v_c136 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c108 != v_c136) return;
                          bool ok791 = true;
                          u64 v_c137 = _prim_lref(db, v_c135, v_c109, &ok791);
                          if (!ok791) return;
                          if (v_c110 != v_c137) return;
                          bool ok792 = true;
                          u64 v_c138 = _prim_lref(db, v_c135, v_c111, &ok792);
                          if (!ok792) return;
                          if (v_c112 != v_c138) return;
                          bool ok793 = true;
                          u64 v_c139 = _prim_lref(db, v_c135, v_c113, &ok793);
                          if (!ok793) return;
                          if (v_c114 != v_c139) return;
                          bool ok794 = true;
                          u64 v_c140 = _prim_lref(db, v_c135, v_c115, &ok794);
                          if (!ok794) return;
                          if (v_c116 != v_c140) return;
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
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask753* _cont = new ReadTask753(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask753(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan st_ins __t2KGA263 r k) (body (exists $sup9688x52x0x0x0 (1 5 0 2 3 4) 2 k r) (exists $sup9688x52x0x0x1 (2 6 0 1 3 4 5) 2 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_ins (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (join $sup9688x52x0x0x0 (1 5 0 2 3 4) 2 k r __t7CbB259 l m p) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t7CbB259 k __t57zq262) (exists st_msk (1 2 0) 3 k m __t57zq262) (exists st_msk_ans (0 1) 2 __t57zq262 p) (join pbranch (1 2 3 4 0) 4 p m l r __t0vi9258) (join st_ins (0 2 1) 3 __t7CbB259 k __t0vi9258) (join st_msk (1 2 0) 3 k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask813 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x0index795;  slog::Index** $sup9688x52x0x0x1index796;  slog::Index** pbranchindex797;  slog::Index** st_insindex798;  slog::Index** st_mskindex799;  slog::Index** st_ins_ansindex800;  slog::Index** $sup9688x52x0x0x0index801;  slog::Index** pbranchindex802;  slog::Index** st_insindex803;  slog::Index** st_mskindex804;  slog::Index** st_msk_ansindex805;  slog::Index** $sup9688x52x0x0x1index806;  slog::Index** st_mskindex807;  slog::Index** st_msk_ansindex808;  slog::Index** pbranchindex809;  slog::Index** st_insindex810;  slog::Index** st_mskindex811;  slog::Index** st_msk_ansindex812;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord814({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel815 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index795 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({2, 6, 0, 1, 3, 4, 5});
      slog::Relation* readrel817 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index796 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({4, 0, 1, 2, 3});
      slog::Relation* readrel819 = db->getRelation("pbranch");
      pbranchindex797 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({2, 0, 1});
      slog::Relation* readrel821 = db->getRelation("st_ins");
      st_insindex798 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("st_msk");
      st_mskindex799 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("st_ins_ans");
      st_ins_ansindex800 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel827 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index801 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 3, 4, 0});
      slog::Relation* readrel829 = db->getRelation("pbranch");
      pbranchindex802 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 2, 1});
      slog::Relation* readrel831 = db->getRelation("st_ins");
      st_insindex803 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 0});
      slog::Relation* readrel833 = db->getRelation("st_msk");
      st_mskindex804 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 0});
      slog::Relation* readrel835 = db->getRelation("st_msk_ans");
      st_msk_ansindex805 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel837 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index806 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("st_msk");
      st_mskindex807 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({0, 1});
      slog::Relation* readrel841 = db->getRelation("st_msk_ans");
      st_msk_ansindex808 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 3, 4, 0});
      slog::Relation* readrel843 = db->getRelation("pbranch");
      pbranchindex809 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 2, 1});
      slog::Relation* readrel845 = db->getRelation("st_ins");
      st_insindex810 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("st_msk");
      st_mskindex811 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({0, 1});
      slog::Relation* readrel849 = db->getRelation("st_msk_ans");
      st_msk_ansindex812 = readrel849->getIndex(ord848, false);
  
    }
    ReadTask813(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c25 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c23 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x52x0x0x0index795, std::array<u64,6>{v_c23, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup9688x52x0x0x1index796, std::array<u64,7>{v_c23, v_c8, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex797, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex798, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex799, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<2,1>(st_ins_ansindex800, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m850) {
          u64 v_c1 = m850[1];
          slog::join_probe<6,2>($sup9688x52x0x0x0index801, std::array<u64,6>{v_c23, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m851) {
            u64 v_c26 = m851[2]; u64 v_c5 = m851[3]; u64 v_c6 = m851[4]; u64 v_c2 = m851[5];
            if (!slog::exists_probe<5,4>(pbranchindex802, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_insindex803, std::array<u64,3>{v_c26, v_c23, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex804, std::array<u64,3>{v_c23, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex805, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<7,6>($sup9688x52x0x0x1index806, std::array<u64,7>{v_c5, v_c6, v_c2, v_c8, v_c26, v_c23, 0}, [&](const std::array<u64,7>& m852) {
              u64 v_c27 = m852[6];
              if (!slog::exists_probe<3,3>(st_mskindex807, std::array<u64,3>{v_c23, v_c6, v_c27})) return;
              if (!slog::exists_probe<2,2>(st_msk_ansindex808, std::array<u64,2>{v_c27, v_c2})) return;
              slog::join_probe<5,4>(pbranchindex809, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m853) {
                u64 v_c28 = m853[4];
                slog::join_probe<3,3>(st_insindex810, std::array<u64,3>{v_c26, v_c23, v_c28}, [&](const std::array<u64,3>& m854) {
                  slog::join_probe<3,3>(st_mskindex811, std::array<u64,3>{v_c23, v_c6, v_c27}, [&](const std::array<u64,3>& m855) {
                    slog::join_probe<2,2>(st_msk_ansindex812, std::array<u64,2>{v_c27, v_c2}, [&](const std::array<u64,2>& m856) {
                      u64 v_c29 = _prim_band(db, v_c23, v_c6);
                      if (v_c29 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c141 = _prim_gt(db, v_c29, v_c24);
                      if (v_c141 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c141) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c26, v_c1, v_c5, v_c6, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c6, v_c5, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __tconst3dNc809 conste3776bfed7f405de8017ecfa) (let __tconst6lQI150 constd4735e3a265e16eee03f5971)) (probe _enum (1 0) 1 __tconst3dNc809 __t1sTP151) (body) (head (mkstruct st_ins (1 2 0) __6CEJ808 __t1sTP151 __tconst6lQI150)) st_basic.slog:18 #f)
  class ReadTask858 : public slog::Task
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
      std::vector<u16> ord859({1, 0});
      slog::Relation* readrel860 = db->getRelation("_enum");
      driver_index = readrel860->getIndex(ord859, true);
  
    }
    ReadTask858(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c143 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c142, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m861) {
        u64 v_c144 = m861[1];
        if (buckethash(v_c144) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c144, v_c143}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask858* _cont = new ReadTask858(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask858(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre3TEG1265 __errf7hJW1266 __errf7ZFj1267) (body) (head (emit error (0) __erre3TEG1265)) <internal>:1 #f)
  class ReadTask862 : public slog::Task
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
      std::vector<u16> ord863({0});
      slog::Relation* readrel864 = db->getRelation("error");
      head_index[0] = readrel864->getIndex(ord863, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c145 = _t[0];
        u64 v_c146 = _t[1];
        u64 v_c147 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c145}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan $sup9688x117x0x0x0 __t0ttd124 l m n p q r u v) (body (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (exists st_union (2 0 1) 1 v) (join-old $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t0ttd124 l m p r __t3TTE127) (exists st_msk (1 2 0) 3 p n __t3TTE127) (exists st_msk_ans (0 1) 2 __t3TTE127 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t43ng122) (exists st_union (2 0 1) 2 __t43ng122 __t0ttd124) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t32HA128) (join-old st_union (0 1 2) 3 (0 1 2) __t0ttd124 __t32HA128 __t43ng122) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask887 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex865;  slog::Index** pbranchindex866;  slog::Index** st_mskindex867;  slog::Index** st_msk_ansindex868;  slog::Index** st_unionindex869;  slog::Index** $sup9688x117x0x0x1index870;  slog::Index** st_mskindex871;  slog::Index** st_msk_ansindex872;  slog::Index** pbranchindex873;  slog::Index** st_unionindex874;  slog::Index** pbranchindex875;  slog::Index** st_unionindex876;  slog::Index** st_mskindex877;  slog::Index** st_msk_ansindex878;  slog::Index** st_unionindex879;  slog::Index** st_union_ansindex880;  slog::Index** $sup9688x117x0x0x1delta881;  slog::Index** pbranchdelta882;  slog::Index** pbranchdelta883;  slog::Index** st_uniondelta884;  slog::Index** st_mskdelta885;  slog::Index** st_uniondelta886;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord888({1, 2, 3, 4, 0});
      slog::Relation* readrel889 = db->getRelation("pbranch");
      pbranchindex865 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 3, 4, 0});
      slog::Relation* readrel891 = db->getRelation("pbranch");
      pbranchindex866 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 0});
      slog::Relation* readrel893 = db->getRelation("st_msk");
      st_mskindex867 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({1, 0});
      slog::Relation* readrel895 = db->getRelation("st_msk_ans");
      st_msk_ansindex868 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({2, 0, 1});
      slog::Relation* readrel897 = db->getRelation("st_union");
      st_unionindex869 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel899 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index870 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel901 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1delta881 = readrel901->getIndex(ord900, true);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("st_msk");
      st_mskindex871 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({0, 1});
      slog::Relation* readrel905 = db->getRelation("st_msk_ans");
      st_msk_ansindex872 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({1, 2, 3, 4, 0});
      slog::Relation* readrel907 = db->getRelation("pbranch");
      pbranchindex873 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 2, 3, 4, 0});
      slog::Relation* readrel909 = db->getRelation("pbranch");
      pbranchdelta882 = readrel909->getIndex(ord908, true);
      std::vector<u16> ord910({2, 0, 1});
      slog::Relation* readrel911 = db->getRelation("st_union");
      st_unionindex874 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 3, 4, 0});
      slog::Relation* readrel913 = db->getRelation("pbranch");
      pbranchindex875 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 3, 4, 0});
      slog::Relation* readrel915 = db->getRelation("pbranch");
      pbranchdelta883 = readrel915->getIndex(ord914, true);
      std::vector<u16> ord916({0, 1, 2});
      slog::Relation* readrel917 = db->getRelation("st_union");
      st_unionindex876 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({0, 1, 2});
      slog::Relation* readrel919 = db->getRelation("st_union");
      st_uniondelta884 = readrel919->getIndex(ord918, true);
      std::vector<u16> ord920({1, 2, 0});
      slog::Relation* readrel921 = db->getRelation("st_msk");
      st_mskindex877 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({1, 2, 0});
      slog::Relation* readrel923 = db->getRelation("st_msk");
      st_mskdelta885 = readrel923->getIndex(ord922, true);
      std::vector<u16> ord924({0, 1});
      slog::Relation* readrel925 = db->getRelation("st_msk_ans");
      st_msk_ansindex878 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 2, 0});
      slog::Relation* readrel927 = db->getRelation("st_union");
      st_unionindex879 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("st_union");
      st_uniondelta886 = readrel929->getIndex(ord928, true);
      std::vector<u16> ord930({0, 1});
      slog::Relation* readrel931 = db->getRelation("st_union_ans");
      st_union_ansindex880 = readrel931->getIndex(ord930, false);
  
    }
    ReadTask887(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c149 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c7 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c9 = _t[7];
        u64 v_c10 = _t[8];
        u64 v_c150 = _prim_lt(db, v_c6, v_c3);
        if (v_c150 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
        if (!v_c150) return;
        if (!slog::exists_probe<5,4>(pbranchindex865, std::array<u64,5>{v_c7, v_c3, v_c9, v_c10, 0})) return;
        if (!slog::exists_probe<5,4>(pbranchindex866, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex867, std::array<u64,3>{v_c2, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex868, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex869, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe_old<10,9>($sup9688x117x0x0x1index870, $sup9688x117x0x0x1delta881, std::array<u64,10>{v_c10, v_c3, v_c7, v_c9, v_c149, v_c5, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,10>& m933) {
          u64 v_c151 = m933[9];
          if (!slog::exists_probe<3,3>(st_mskindex871, std::array<u64,3>{v_c2, v_c3, v_c151})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex872, std::array<u64,2>{v_c151, v_c7})) return;
          slog::join_probe_old<5,4>(pbranchindex873, pbranchdelta882, std::array<u64,5>{v_c7, v_c3, v_c9, v_c10, 0}, [&](const std::array<u64,5>& m934) {
            u64 v_c152 = m934[4];
            if (!slog::exists_probe<3,2>(st_unionindex874, std::array<u64,3>{v_c152, v_c149, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex875, pbranchdelta883, std::array<u64,5>{v_c2, v_c6, v_c5, v_c8, 0}, [&](const std::array<u64,5>& m935) {
              u64 v_c153 = m935[4];
              slog::join_probe_old<3,3>(st_unionindex876, st_uniondelta884, std::array<u64,3>{v_c149, v_c153, v_c152}, [&](const std::array<u64,3>& m936) {
                slog::join_probe_old<3,3>(st_mskindex877, st_mskdelta885, std::array<u64,3>{v_c2, v_c3, v_c151}, [&](const std::array<u64,3>& m937) {
                  slog::join_probe<2,2>(st_msk_ansindex878, std::array<u64,2>{v_c151, v_c7}, [&](const std::array<u64,2>& m938) {
                    slog::join_probe_old<3,2>(st_unionindex879, st_uniondelta886, std::array<u64,3>{v_c153, v_c10, 0}, [&](const std::array<u64,3>& m939) {
                      u64 v_c154 = m939[2];
                      slog::join_probe<2,1>(st_union_ansindex880, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m940) {
                        u64 v_c1 = m940[1];
                        u64 v_c155 = _prim_band(db, v_c2, v_c3);
                        if (v_c155 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c156 = _prim_gt(db, v_c155, v_c148);
                        if (v_c156 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c156) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c149, v_c1, v_c3, v_c7, v_c9});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c7, v_c3, v_c9, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:$sup9688x117x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask887* _cont = new ReadTask887(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask887(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan pbranch __t7Uqa322 p m l r) (body (exists st_mem0 (1 2 0) 1 __t7Uqa322) (exists st_mem0 (1 2 0) 1 l) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x70x0x0x0 (4 2 3 5 0 1) 4 p l m r __t6uqp323 k) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6uqp323 __t7Uqa322 k) (exists st_msk (1 2 0) 2 k m) (join-old st_mem0 (1 2 0) 2 (1 2 0) l k __t14DN326) (exists st_mem0_ans (0 1) 1 __t14DN326) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t3nJI327) (join st_msk_ans (0 1) 2 __t3nJI327 p) (join st_mem0_ans (0 1) 1 __t14DN326 a) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask957 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index942;  slog::Index** st_mem0index943;  slog::Index** st_mskindex944;  slog::Index** st_msk_ansindex945;  slog::Index** $sup9688x70x0x0x0index946;  slog::Index** st_mem0index947;  slog::Index** st_mskindex948;  slog::Index** st_mem0index949;  slog::Index** st_mem0_ansindex950;  slog::Index** st_mskindex951;  slog::Index** st_msk_ansindex952;  slog::Index** st_mem0_ansindex953;  slog::Index** st_mem0delta954;  slog::Index** st_mem0delta955;  slog::Index** st_mskdelta956;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord958({0, 1});
      slog::Relation* readrel959 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel959->getIndex(ord958, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("st_mem0");
      st_mem0index942 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 2, 0});
      slog::Relation* readrel963 = db->getRelation("st_mem0");
      st_mem0index943 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({2, 0, 1});
      slog::Relation* readrel965 = db->getRelation("st_msk");
      st_mskindex944 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 0});
      slog::Relation* readrel967 = db->getRelation("st_msk_ans");
      st_msk_ansindex945 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel969 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index946 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({0, 1, 2});
      slog::Relation* readrel971 = db->getRelation("st_mem0");
      st_mem0index947 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("st_mem0");
      st_mem0delta954 = readrel973->getIndex(ord972, true);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("st_msk");
      st_mskindex948 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 0});
      slog::Relation* readrel977 = db->getRelation("st_mem0");
      st_mem0index949 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({1, 2, 0});
      slog::Relation* readrel979 = db->getRelation("st_mem0");
      st_mem0delta955 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({0, 1});
      slog::Relation* readrel981 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex950 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 2, 0});
      slog::Relation* readrel983 = db->getRelation("st_msk");
      st_mskindex951 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({1, 2, 0});
      slog::Relation* readrel985 = db->getRelation("st_msk");
      st_mskdelta956 = readrel985->getIndex(ord984, true);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("st_msk_ans");
      st_msk_ansindex952 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex953 = readrel989->getIndex(ord988, false);
  
    }
    ReadTask957(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c57 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(st_mem0index942, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index943, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex944, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex945, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<6,4>($sup9688x70x0x0x0index946, std::array<u64,6>{v_c2, v_c5, v_c6, v_c8, 0, 0}, [&](const std::array<u64,6>& m990) {
          u64 v_c56 = m990[4]; u64 v_c23 = m990[5];
          slog::join_probe_old<3,3>(st_mem0index947, st_mem0delta954, std::array<u64,3>{v_c56, v_c57, v_c23}, [&](const std::array<u64,3>& m991) {
            if (!slog::exists_probe<3,2>(st_mskindex948, std::array<u64,3>{v_c23, v_c6, 0})) return;
            slog::join_probe_old<3,2>(st_mem0index949, st_mem0delta955, std::array<u64,3>{v_c5, v_c23, 0}, [&](const std::array<u64,3>& m992) {
              u64 v_c58 = m992[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex950, std::array<u64,2>{v_c58, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex951, st_mskdelta956, std::array<u64,3>{v_c23, v_c6, 0}, [&](const std::array<u64,3>& m993) {
                u64 v_c55 = m993[2];
                slog::join_probe<2,2>(st_msk_ansindex952, std::array<u64,2>{v_c55, v_c2}, [&](const std::array<u64,2>& m994) {
                  slog::join_probe<2,1>(st_mem0_ansindex953, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m995) {
                    u64 v_c59 = m995[1];
                    u64 v_c60 = _prim_band(db, v_c23, v_c6);
                    if (v_c60 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c157 = _prim_lt(db, v_c60, v_c54);
                    if (v_c157 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c157) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c59}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask957* _cont = new ReadTask957(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask957(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan pbranch __t3eTQ549 q n u v) (body (exists st_msk (1 2 0) 1 q) (exists st_diff (2 0 1) 1 __t3eTQ549) (join $sup9688x142x0x0x0 (3 5 7 8 6 0 1 2 4) 4 n q u v r __d0 l m p) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 2 r __t3eTQ549) (join st_msk (1 2 0) 2 q m __t3ZZb548) (join st_msk_ans (0 1) 2 __t3ZZb548 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t3eTQ549 __t7sr4550) (join st_diff_ans (0 1) 1 __t7sr4550 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask1010 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex997;  slog::Index** st_diffindex998;  slog::Index** $sup9688x142x0x0x0index999;  slog::Index** st_msk_ansindex1000;  slog::Index** st_diffindex1001;  slog::Index** st_mskindex1002;  slog::Index** st_msk_ansindex1003;  slog::Index** st_diffindex1004;  slog::Index** st_diff_ansindex1005;  slog::Index** st_diffdelta1006;
    u32 sid1008;  u32 sid1007;  u32 sid1009;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1011({1, 2, 0});
      slog::Relation* readrel1012 = db->getRelation("st_msk");
      st_mskindex997 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({2, 0, 1});
      slog::Relation* readrel1014 = db->getRelation("st_diff");
      st_diffindex998 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({3, 5, 7, 8, 6, 0, 1, 2, 4});
      slog::Relation* readrel1016 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index999 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 0});
      slog::Relation* readrel1018 = db->getRelation("st_msk_ans");
      st_msk_ansindex1000 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 2, 0});
      slog::Relation* readrel1020 = db->getRelation("st_diff");
      st_diffindex1001 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 0});
      slog::Relation* readrel1022 = db->getRelation("st_msk");
      st_mskindex1002 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({0, 1});
      slog::Relation* readrel1024 = db->getRelation("st_msk_ans");
      st_msk_ansindex1003 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 0});
      slog::Relation* readrel1026 = db->getRelation("st_diff");
      st_diffindex1004 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("st_diff");
      st_diffdelta1006 = readrel1028->getIndex(ord1027, true);
      std::vector<u16> ord1029({0, 1});
      slog::Relation* readrel1030 = db->getRelation("st_diff_ans");
      st_diff_ansindex1005 = readrel1030->getIndex(ord1029, false);
      sid1008 = db->getRelation("_enum")->getStructId();
      sid1007 = db->getRelation("pbranch")->getStructId();
      sid1009 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1010(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c158 = v_const81906d9241165d9f6a541e47;
      u64 v_c159 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c160 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c161 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<3,1>(st_mskindex997, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex998, std::array<u64,3>{v_c161, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x142x0x0x0index999, std::array<u64,9>{v_c3, v_c7, v_c9, v_c10, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1031) {
          u64 v_c8 = m1031[4]; u64 v_c70 = m1031[5]; u64 v_c5 = m1031[6]; u64 v_c6 = m1031[7]; u64 v_c2 = m1031[8];
          if (!slog::exists_probe<2,1>(st_msk_ansindex1000, std::array<u64,2>{v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex1001, std::array<u64,3>{v_c8, v_c161, 0})) return;
          slog::join_probe<3,2>(st_mskindex1002, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m1032) {
            u64 v_c162 = m1032[2];
            slog::join_probe<2,2>(st_msk_ansindex1003, std::array<u64,2>{v_c162, v_c2}, [&](const std::array<u64,2>& m1033) {
              slog::join_probe_old<3,2>(st_diffindex1004, st_diffdelta1006, std::array<u64,3>{v_c8, v_c161, 0}, [&](const std::array<u64,3>& m1034) {
                u64 v_c163 = m1034[2];
                slog::join_probe<2,1>(st_diff_ansindex1005, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m1035) {
                  u64 v_c1 = m1035[1];
                  ++_fires;
                  if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid1007 || decode_struct_id(v_c5) == sid1008 || decode_struct_id(v_c5) == sid1009))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c158, v_c159, v_c160, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c6, v_c5, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1010* _cont = new ReadTask1010(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1010(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_diff __t95th341 r __t69OA340) (body (exists st_diff (2 0 1) 1 __t69OA340) (exists pbranch (4 0 1 2 3) 1 r) (exists $sup9688x142x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (join st_diff_ans (0 1) 1 __t95th341 __v0) (exists st_bld (4 0 1 2 3) 1 __v0) (join st_diff (2 0 1) 1 __t69OA340 __t8Fy1335 __t88zt334) (exists $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t8Fy1335 r) (join pbranch (4 0 1 2 3) 2 r __t88zt334 p m l) (exists st_bld (1 2 3 4 0) 4 p m l __v0) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t8Fy1335 n q u v) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 q n u v __t69OA340) (exists st_msk (1 2 0) 2 q m) (join st_bld (1 2 3 4 0) 4 p m l __v0 __t7XLn338) (exists st_bld_ans (0 1) 1 __t7XLn338) (join st_msk (1 2 0) 2 q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask1055 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1036;  slog::Index** pbranchindex1037;  slog::Index** $sup9688x142x0x0x0index1038;  slog::Index** st_diff_ansindex1039;  slog::Index** st_bldindex1040;  slog::Index** st_diffindex1041;  slog::Index** $sup9688x142x0x0x0index1042;  slog::Index** pbranchindex1043;  slog::Index** st_bldindex1044;  slog::Index** st_mskindex1045;  slog::Index** st_msk_ansindex1046;  slog::Index** $sup9688x142x0x0x0index1047;  slog::Index** pbranchindex1048;  slog::Index** st_mskindex1049;  slog::Index** st_bldindex1050;  slog::Index** st_bld_ansindex1051;  slog::Index** st_mskindex1052;  slog::Index** st_msk_ansindex1053;  slog::Index** st_bld_ansindex1054;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1056({0, 1});
      slog::Relation* readrel1057 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1057->getIndex(ord1056, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1058({2, 0, 1});
      slog::Relation* readrel1059 = db->getRelation("st_diff");
      st_diffindex1036 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({4, 0, 1, 2, 3});
      slog::Relation* readrel1061 = db->getRelation("pbranch");
      pbranchindex1037 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1063 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1038 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({0, 1});
      slog::Relation* readrel1065 = db->getRelation("st_diff_ans");
      st_diff_ansindex1039 = readrel1065->getIndex(ord1064, false);
      std::vector<u16> ord1066({4, 0, 1, 2, 3});
      slog::Relation* readrel1067 = db->getRelation("st_bld");
      st_bldindex1040 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({2, 0, 1});
      slog::Relation* readrel1069 = db->getRelation("st_diff");
      st_diffindex1041 = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1071 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1042 = readrel1071->getIndex(ord1070, false);
      std::vector<u16> ord1072({4, 0, 1, 2, 3});
      slog::Relation* readrel1073 = db->getRelation("pbranch");
      pbranchindex1043 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 2, 3, 4, 0});
      slog::Relation* readrel1075 = db->getRelation("st_bld");
      st_bldindex1044 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({2, 0, 1});
      slog::Relation* readrel1077 = db->getRelation("st_msk");
      st_mskindex1045 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 0});
      slog::Relation* readrel1079 = db->getRelation("st_msk_ans");
      st_msk_ansindex1046 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1081 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1047 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 2, 3, 4, 0});
      slog::Relation* readrel1083 = db->getRelation("pbranch");
      pbranchindex1048 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 0});
      slog::Relation* readrel1085 = db->getRelation("st_msk");
      st_mskindex1049 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 2, 3, 4, 0});
      slog::Relation* readrel1087 = db->getRelation("st_bld");
      st_bldindex1050 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("st_bld_ans");
      st_bld_ansindex1051 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 2, 0});
      slog::Relation* readrel1091 = db->getRelation("st_msk");
      st_mskindex1052 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({0, 1});
      slog::Relation* readrel1093 = db->getRelation("st_msk_ans");
      st_msk_ansindex1053 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 1});
      slog::Relation* readrel1095 = db->getRelation("st_bld_ans");
      st_bld_ansindex1054 = readrel1095->getIndex(ord1094, false);
  
    }
    ReadTask1055(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c8 = _t[1];
        u64 v_c166 = _t[2];
        if (!slog::exists_probe<3,1>(st_diffindex1036, std::array<u64,3>{v_c166, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1037, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index1038, std::array<u64,9>{v_c8, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex1039, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m1096) {
          u64 v_c1 = m1096[1];
          if (!slog::exists_probe<5,1>(st_bldindex1040, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(st_diffindex1041, std::array<u64,3>{v_c166, 0, 0}, [&](const std::array<u64,3>& m1097) {
            u64 v_c167 = m1097[1]; u64 v_c168 = m1097[2];
            if (!slog::exists_probe<9,2>($sup9688x142x0x0x0index1042, std::array<u64,9>{v_c167, v_c8, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex1043, std::array<u64,5>{v_c8, v_c168, 0, 0, 0}, [&](const std::array<u64,5>& m1098) {
              u64 v_c2 = m1098[2]; u64 v_c6 = m1098[3]; u64 v_c5 = m1098[4];
              if (!slog::exists_probe<5,4>(st_bldindex1044, std::array<u64,5>{v_c2, v_c6, v_c5, v_c1, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex1045, std::array<u64,3>{v_c6, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex1046, std::array<u64,2>{v_c2, 0})) return;
              slog::join_probe<9,5>($sup9688x142x0x0x0index1047, std::array<u64,9>{v_c2, v_c5, v_c6, v_c8, v_c167, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1099) {
                u64 v_c3 = m1099[5]; u64 v_c7 = m1099[6]; u64 v_c9 = m1099[7]; u64 v_c10 = m1099[8];
                u64 v_c169 = _prim_lt(db, v_c3, v_c6);
                if (v_c169 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                if (!v_c169) return;
                slog::join_probe<5,5>(pbranchindex1048, std::array<u64,5>{v_c7, v_c3, v_c9, v_c10, v_c166}, [&](const std::array<u64,5>& m1101) {
                  if (!slog::exists_probe<3,2>(st_mskindex1049, std::array<u64,3>{v_c7, v_c6, 0})) return;
                  slog::join_probe<5,4>(st_bldindex1050, std::array<u64,5>{v_c2, v_c6, v_c5, v_c1, 0}, [&](const std::array<u64,5>& m1102) {
                    u64 v_c170 = m1102[4];
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1051, std::array<u64,2>{v_c170, 0})) return;
                    slog::join_probe<3,2>(st_mskindex1052, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m1103) {
                      u64 v_c171 = m1103[2];
                      slog::join_probe<2,2>(st_msk_ansindex1053, std::array<u64,2>{v_c171, v_c2}, [&](const std::array<u64,2>& m1104) {
                        slog::join_probe<2,1>(st_bld_ansindex1054, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m1105) {
                          u64 v_c53 = m1105[1];
                          u64 v_c172 = _prim_band(db, v_c7, v_c6);
                          if (v_c172 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c173 = _prim_gt(db, v_c172, v_c164);
                          if (v_c173 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c173) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c167, v_c53}, std::array<u16,2>{0, 1});
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
        ReadTask1055* _cont = new ReadTask1055(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1055(db,b), false);
  // (crule (pre (let __trid708K812 const35c71810897f279c2099acbb) (let __trel1Gqj813 const94d9c4e2675ef4bd8443d499) (let __tcol6iSV814 const5feceb66ffc86f38d952786c) (let __trel14E2815 const94d9c4e2675ef4bd8443d499) (let __tcol7NJT816 const6b86b273ff34fce19d6b804e)) (scan $sup9688x100x0x0x0 __d0 l m p r u v) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid708K812 __trel1Gqj813 __tcol6iSV814 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid708K812 __trel14E2815 __tcol7NJT816 (1 2 3 4 0)) (mkstruct st_union (1 2 0) __8MMW811 r v)) set.slog:101 #f)
  class ReadTask1110 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1108;  u32 sid1107;  u32 sid1109;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_union");
      outer_rel = db->getRelation("$sup9688x100x0x0x0");
      sid1108 = db->getRelation("_enum")->getStructId();
      sid1107 = db->getRelation("pbranch")->getStructId();
      sid1109 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1110(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_const35c71810897f279c2099acbb;
      u64 v_c175 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c70 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c10 = _t[6];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid1107 || decode_struct_id(v_c8) == sid1108 || decode_struct_id(v_c8) == sid1109))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c174, v_c175, v_c176, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid1107 || decode_struct_id(v_c10) == sid1108 || decode_struct_id(v_c10) == sid1109))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c174, v_c177, v_c178, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:$sup9688x100x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1110* _cont = new ReadTask1110(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1110(db,b), false);
}

