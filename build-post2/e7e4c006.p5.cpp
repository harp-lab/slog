
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const22475024b8f1c7d620b83a7c;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const7d00193796cbe9983b9801f2;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constb0e9a61bdf716031c5ca8c29;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;


void slog_rules_c65bbed1236339abd(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst29FO717 conste3776bfed7f405de8017ecfa)) (scan st_diff __t3Hb9533 s __t7g8K532) (body (join _enum (0 1) 2 __t7g8K532 __tconst29FO717)) (head (emit st_diff_ans (0 1) __t3Hb9533 s)) set.slog:131 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("st_diff_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord4({0, 1});
      slog::Relation* readrel5 = db->getRelation("_enum");
      _enumindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_conste3776bfed7f405de8017ecfa;
  
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
        slog::join_probe<2,2>(_enumindex0, std::array<u64,2>{v_c3, v_c0}, [&](const std::array<u64,2>& m6) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:131", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre (let __trid3tqr879 const7d00193796cbe9983b9801f2) (let __trel4kBr880 consta10f76b4ec574de5d7b6908e) (let __tcol2vq2881 const5feceb66ffc86f38d952786c) (let __trel9ykK882 consta10f76b4ec574de5d7b6908e) (let __tcol93YB883 const6b86b273ff34fce19d6b804e)) (scan $sup9688x50x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid3tqr879 __trel4kBr880 __tcol2vq2881 (1 2 3 4 0)) (tycheck m (accept int) __trid3tqr879 __trel9ykK882 __tcol93YB883 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __92xI878 k m)) set.slog:51 #f)
  class ReadTask7 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x50x0x0x0");
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const7d00193796cbe9983b9801f2;
      u64 v_c5 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c14 = _t[5];
        ++_fires;
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c4, v_c5, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c12)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c4, v_c7, v_c8, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:$sup9688x50x0x0x0", _fires);
  
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
  // (crule (pre) (scan st_join_ans __t6WK8115 r) (body (join-old st_join (0 1 2 3 4) 1 (0 1 2 3 4) __t6WK8115 k __t3mOh114 j __t29mi113) (neq j k) (join-old pleaf (0 1) 2 (0 1) __t29mi113 j) (join-old pleaf (0 1) 2 (0 1) __t3mOh114 k) (join-old st_ins (1 2 0) 2 (1 2 0) __t29mi113 k __t1Tua112)) (head (emit st_ins_ans (0 1) __t1Tua112 r)) set.slog:50 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex8;  slog::Index** pleafindex9;  slog::Index** pleafindex10;  slog::Index** st_insindex11;  slog::Index** st_joindelta12;  slog::Index** pleafdelta13;  slog::Index** pleafdelta14;  slog::Index** st_insdelta15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("st_ins_ans");
      head_index[0] = readrel18->getIndex(ord17, false);
      outer_rel = db->getRelation("st_join_ans");
      std::vector<u16> ord19({0, 1, 2, 3, 4});
      slog::Relation* readrel20 = db->getRelation("st_join");
      st_joinindex8 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({0, 1, 2, 3, 4});
      slog::Relation* readrel22 = db->getRelation("st_join");
      st_joindelta12 = readrel22->getIndex(ord21, true);
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("pleaf");
      pleafindex9 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("pleaf");
      pleafdelta13 = readrel26->getIndex(ord25, true);
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("pleaf");
      pleafindex10 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("pleaf");
      pleafdelta14 = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("st_ins");
      st_insindex11 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("st_ins");
      st_insdelta15 = readrel34->getIndex(ord33, true);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        slog::join_probe_old<5,1>(st_joinindex8, st_joindelta12, std::array<u64,5>{v_c15, 0, 0, 0, 0}, [&](const std::array<u64,5>& m35) {
          u64 v_c10 = m35[1]; u64 v_c16 = m35[2]; u64 v_c17 = m35[3]; u64 v_c18 = m35[4];
          if (v_c17 == v_c10) return;
          slog::join_probe_old<2,2>(pleafindex9, pleafdelta13, std::array<u64,2>{v_c18, v_c17}, [&](const std::array<u64,2>& m36) {
            slog::join_probe_old<2,2>(pleafindex10, pleafdelta14, std::array<u64,2>{v_c16, v_c10}, [&](const std::array<u64,2>& m37) {
              slog::join_probe_old<3,2>(st_insindex11, st_insdelta15, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m38) {
                u64 v_c19 = m38[2];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c14}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:st_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), false);
  // (crule (pre) (scan pbranch __t78TS531 q n u v) (body (join st_union (2 0 1) 1 __t78TS531 __t3dip529 __t4nDr530) (join pbranch (0 1 2 3 4) 1 __t4nDr530 p m l r) (cmp lt m n)) (head (emit $sup9688x120x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t3dip529 l m q r __t4nDr530 __t78TS531 u v)) set.slog:121 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex39;  slog::Index** pbranchindex40;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord42({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel43 = db->getRelation("$sup9688x120x0x0x0");
      head_index[0] = readrel43->getIndex(ord42, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord44({2, 0, 1});
      slog::Relation* readrel45 = db->getRelation("st_union");
      st_unionindex39 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 1, 2, 3, 4});
      slog::Relation* readrel47 = db->getRelation("pbranch");
      pbranchindex40 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe<3,1>(st_unionindex39, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m48) {
          u64 v_c25 = m48[1]; u64 v_c26 = m48[2];
          slog::join_probe<5,1>(pbranchindex40, std::array<u64,5>{v_c26, 0, 0, 0, 0}, [&](const std::array<u64,5>& m49) {
            u64 v_c13 = m49[1]; u64 v_c12 = m49[2]; u64 v_c11 = m49[3]; u64 v_c14 = m49[4];
            u64 v_c27 = _prim_lt(db, v_c12, v_c22);
            if (v_c27 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c27) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c22, v_c13, v_c25, v_c11, v_c12, v_c21, v_c14, v_c26, v_c20, v_c23, v_c24}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask41* _cont = new ReadTask41(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask41(db,b), false);
  // (crule (pre) (scan pbranch __t7Veu484 q m u v) (body (exists pbranch (2 0 1 3 4) 1 m) (join-old st_diff (2 0 1) 1 (2 0 1) __t7Veu484 __t7G0O486 __t7Xsy485) (join-old pbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t7Xsy485 p l r) (neq p q)) (head (emit st_diff_ans (0 1) __t7G0O486 __t7Xsy485)) set.slog:158 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex51;  slog::Index** st_diffindex52;  slog::Index** pbranchindex53;  slog::Index** st_diffdelta54;  slog::Index** pbranchdelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("st_diff_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord59({2, 0, 1, 3, 4});
      slog::Relation* readrel60 = db->getRelation("pbranch");
      pbranchindex51 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({2, 0, 1});
      slog::Relation* readrel62 = db->getRelation("st_diff");
      st_diffindex52 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({2, 0, 1});
      slog::Relation* readrel64 = db->getRelation("st_diff");
      st_diffdelta54 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({2, 0, 1, 3, 4});
      slog::Relation* readrel66 = db->getRelation("pbranch");
      pbranchindex53 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({2, 0, 1, 3, 4});
      slog::Relation* readrel68 = db->getRelation("pbranch");
      pbranchdelta55 = readrel68->getIndex(ord67, true);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex51, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex52, st_diffdelta54, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m69) {
          u64 v_c29 = m69[1]; u64 v_c30 = m69[2];
          slog::join_probe_old<5,2>(pbranchindex53, pbranchdelta55, std::array<u64,5>{v_c12, v_c30, 0, 0, 0}, [&](const std::array<u64,5>& m70) {
            u64 v_c13 = m70[2]; u64 v_c11 = m70[3]; u64 v_c14 = m70[4];
            if (v_c13 == v_c21) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c30}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:158", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre) (scan st_msk __t8lOi420 p n) (body (exists $sup9688x154x0x0x0 (3 4 0 1 2 5 6 7 8) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (join st_msk_ans (0 1) 1 __t8lOi420 __v0) (join $sup9688x154x0x0x0 (3 4 0 1 2 5 6 7 8) 2 n p __t0EGY419 l m q r u v) (cmp lt m n) (neq q __v0) (exists pbranch (1 2 3 4 0) 4 p m l r) (join pbranch (1 2 3 4 0) 4 q n u v __t7ytQ417) (exists st_diff (2 0 1) 2 __t7ytQ417 __t0EGY419) (join pbranch (1 2 3 4 0) 4 p m l r __t1fgd418) (join st_diff (0 1 2) 3 __t0EGY419 __t1fgd418 __t7ytQ417)) (head (emit st_diff_ans (0 1) __t0EGY419 __t1fgd418)) set.slog:155 #f)
  class ReadTask81 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x154x0x0x0index71;  slog::Index** pbranchindex72;  slog::Index** pbranchindex73;  slog::Index** st_msk_ansindex74;  slog::Index** $sup9688x154x0x0x0index75;  slog::Index** pbranchindex76;  slog::Index** pbranchindex77;  slog::Index** st_diffindex78;  slog::Index** pbranchindex79;  slog::Index** st_diffindex80;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("st_diff_ans");
      head_index[0] = readrel83->getIndex(ord82, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord84({3, 4, 0, 1, 2, 5, 6, 7, 8});
      slog::Relation* readrel85 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index71 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({2, 0, 1, 3, 4});
      slog::Relation* readrel87 = db->getRelation("pbranch");
      pbranchindex72 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 3, 4, 0});
      slog::Relation* readrel89 = db->getRelation("pbranch");
      pbranchindex73 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("st_msk_ans");
      st_msk_ansindex74 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({3, 4, 0, 1, 2, 5, 6, 7, 8});
      slog::Relation* readrel93 = db->getRelation("$sup9688x154x0x0x0");
      $sup9688x154x0x0x0index75 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 2, 3, 4, 0});
      slog::Relation* readrel95 = db->getRelation("pbranch");
      pbranchindex76 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 3, 4, 0});
      slog::Relation* readrel97 = db->getRelation("pbranch");
      pbranchindex77 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({2, 0, 1});
      slog::Relation* readrel99 = db->getRelation("st_diff");
      st_diffindex78 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 3, 4, 0});
      slog::Relation* readrel101 = db->getRelation("pbranch");
      pbranchindex79 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1, 2});
      slog::Relation* readrel103 = db->getRelation("st_diff");
      st_diffindex80 = readrel103->getIndex(ord102, false);
  
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
        u64 v_c31 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x154x0x0x0index71, std::array<u64,9>{v_c22, v_c13, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex72, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex73, std::array<u64,5>{v_c13, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex74, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m104) {
          u64 v_c32 = m104[1];
          slog::join_probe<9,2>($sup9688x154x0x0x0index75, std::array<u64,9>{v_c22, v_c13, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m105) {
            u64 v_c33 = m105[2]; u64 v_c11 = m105[3]; u64 v_c12 = m105[4]; u64 v_c21 = m105[5]; u64 v_c14 = m105[6]; u64 v_c23 = m105[7]; u64 v_c24 = m105[8];
            u64 v_c34 = _prim_lt(db, v_c12, v_c22);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c34) return;
            if (v_c21 == v_c32) return;
            if (!slog::exists_probe<5,4>(pbranchindex76, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0})) return;
            slog::join_probe<5,4>(pbranchindex77, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m107) {
              u64 v_c35 = m107[4];
              if (!slog::exists_probe<3,2>(st_diffindex78, std::array<u64,3>{v_c35, v_c33, 0})) return;
              slog::join_probe<5,4>(pbranchindex79, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m108) {
                u64 v_c36 = m108[4];
                slog::join_probe<3,3>(st_diffindex80, std::array<u64,3>{v_c33, v_c36, v_c35}, [&](const std::array<u64,3>& m109) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c36}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:st_msk", _fires);
  
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
  // (crule (pre (let __tconst7OE6425 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t32gs424 t k) (body (join st_mem0_ans (0 1) 2 __t32gs424 __tconst7OE6425) (exists st_diff (2 0 1) 1 t) (join pleaf (1 0) 1 k __t2KDy422) (join st_diff (1 2 0) 2 __t2KDy422 t __t2CPR423)) (head (emit st_diff_ans (0 1) __t2CPR423 __t2KDy422)) set.slog:134 #f)
  class ReadTask114 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0_ansindex110;  slog::Index** st_diffindex111;  slog::Index** pleafindex112;  slog::Index** st_diffindex113;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("st_diff_ans");
      head_index[0] = readrel116->getIndex(ord115, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex110 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({2, 0, 1});
      slog::Relation* readrel120 = db->getRelation("st_diff");
      st_diffindex111 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 0});
      slog::Relation* readrel122 = db->getRelation("pleaf");
      pleafindex112 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("st_diff");
      st_diffindex113 = readrel124->getIndex(ord123, false);
  
    }
    ReadTask114(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c10 = _t[2];
        slog::join_probe<2,2>(st_mem0_ansindex110, std::array<u64,2>{v_c38, v_c37}, [&](const std::array<u64,2>& m125) {
          if (!slog::exists_probe<3,1>(st_diffindex111, std::array<u64,3>{v_c39, 0, 0})) return;
          slog::join_probe<2,1>(pleafindex112, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m126) {
            u64 v_c40 = m126[1];
            slog::join_probe<3,2>(st_diffindex113, std::array<u64,3>{v_c40, v_c39, 0}, [&](const std::array<u64,3>& m127) {
              u64 v_c41 = m127[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c40}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask114* _cont = new ReadTask114(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask114(db,b), false);
  // (crule (pre) (scan temp1Dk71281 __t2j0W61 __v0 n q v) (body (join pbranch (1 2 3 4 0) 4 q n __v0 v __t0srE58)) (head (emit st_union_ans (0 1) __t2j0W61 __t0srE58)) set.slog:115 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("st_union_ans");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("temp1Dk71281");
      std::vector<u16> ord132({1, 2, 3, 4, 0});
      slog::Relation* readrel133 = db->getRelation("pbranch");
      pbranchindex128 = readrel133->getIndex(ord132, false);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c21 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe<5,4>(pbranchindex128, std::array<u64,5>{v_c21, v_c22, v_c32, v_c24, 0}, [&](const std::array<u64,5>& m134) {
          u64 v_c43 = m134[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c43}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:temp1Dk71281", _fires);
  
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
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan $sup9688x52x0x0x1 __t7CbB259 __t57zq262 k l m p r) (body (join $sup9688x52x0x0x0 (4 2 3 5 0 1) 6 p l m r __t7CbB259 k) (exists st_ins (0 2 1) 2 __t7CbB259 k) (exists st_msk (1 2 0) 3 k m __t57zq262) (exists st_msk_ans (0 1) 2 __t57zq262 p) (exists st_ins (1 2 0) 2 r k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0vi9258) (join-old st_ins (0 2 1) 3 (0 2 1) __t7CbB259 k __t0vi9258) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x0index135;  slog::Index** st_insindex136;  slog::Index** st_mskindex137;  slog::Index** st_msk_ansindex138;  slog::Index** st_insindex139;  slog::Index** pbranchindex140;  slog::Index** st_insindex141;  slog::Index** st_mskindex142;  slog::Index** st_msk_ansindex143;  slog::Index** st_insindex144;  slog::Index** st_ins_ansindex145;  slog::Index** pbranchdelta146;  slog::Index** st_insdelta147;  slog::Index** st_mskdelta148;  slog::Index** st_insdelta149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord151({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel152 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index135 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({0, 2, 1});
      slog::Relation* readrel154 = db->getRelation("st_ins");
      st_insindex136 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("st_msk");
      st_mskindex137 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("st_msk_ans");
      st_msk_ansindex138 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("st_ins");
      st_insindex139 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 3, 4, 0});
      slog::Relation* readrel162 = db->getRelation("pbranch");
      pbranchindex140 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 3, 4, 0});
      slog::Relation* readrel164 = db->getRelation("pbranch");
      pbranchdelta146 = readrel164->getIndex(ord163, true);
      std::vector<u16> ord165({0, 2, 1});
      slog::Relation* readrel166 = db->getRelation("st_ins");
      st_insindex141 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 2, 1});
      slog::Relation* readrel168 = db->getRelation("st_ins");
      st_insdelta147 = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("st_msk");
      st_mskindex142 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("st_msk");
      st_mskdelta148 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("st_msk_ans");
      st_msk_ansindex143 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("st_ins");
      st_insindex144 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("st_ins");
      st_insdelta149 = readrel178->getIndex(ord177, true);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("st_ins_ans");
      st_ins_ansindex145 = readrel180->getIndex(ord179, false);
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        u64 v_c46 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c13 = _t[5];
        u64 v_c14 = _t[6];
        slog::join_probe<6,6>($sup9688x52x0x0x0index135, std::array<u64,6>{v_c13, v_c11, v_c12, v_c14, v_c45, v_c10}, [&](const std::array<u64,6>& m181) {
          if (!slog::exists_probe<3,2>(st_insindex136, std::array<u64,3>{v_c45, v_c10, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex137, std::array<u64,3>{v_c10, v_c12, v_c46})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex138, std::array<u64,2>{v_c46, v_c13})) return;
          if (!slog::exists_probe<3,2>(st_insindex139, std::array<u64,3>{v_c14, v_c10, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex140, pbranchdelta146, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m182) {
            u64 v_c47 = m182[4];
            slog::join_probe_old<3,3>(st_insindex141, st_insdelta147, std::array<u64,3>{v_c45, v_c10, v_c47}, [&](const std::array<u64,3>& m183) {
              slog::join_probe_old<3,3>(st_mskindex142, st_mskdelta148, std::array<u64,3>{v_c10, v_c12, v_c46}, [&](const std::array<u64,3>& m184) {
                slog::join_probe<2,2>(st_msk_ansindex143, std::array<u64,2>{v_c46, v_c13}, [&](const std::array<u64,2>& m185) {
                  slog::join_probe_old<3,2>(st_insindex144, st_insdelta149, std::array<u64,3>{v_c14, v_c10, 0}, [&](const std::array<u64,3>& m186) {
                    u64 v_c48 = m186[2];
                    slog::join_probe<2,1>(st_ins_ansindex145, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m187) {
                      u64 v_c32 = m187[1];
                      u64 v_c49 = _prim_band(db, v_c10, v_c12);
                      if (v_c49 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c50 = _prim_gt(db, v_c49, v_c44);
                      if (v_c50 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c50) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c45, v_c32, v_c11, v_c12, v_c13});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c11, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:$sup9688x52x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre) (scan div_by_zero __erre08NJ1238 __errf5Vs71239 __errf8JBb1240) (body) (head (emit error (0) __erre08NJ1238)) <internal>:1 #f)
  class ReadTask189 : public slog::Task
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
      std::vector<u16> ord190({0});
      slog::Relation* readrel191 = db->getRelation("error");
      head_index[0] = readrel191->getIndex(ord190, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let __tconst03yH266 const6b86b273ff34fce19d6b804e)) (scan st_hsb __t3jPx265 __t7lUk264) (body (join st_hsb_ans (0 1) 1 __t3jPx265 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t2kVi267 (band p0 __v0)) (cmp lt __t2kVi267 __tconst03yH266) (let chk8nNn1337 (bxor p0 p1)) (eq __t7lUk264 chk8nNn1337)) (head (emit $sup9688x36x0x0x1 (1 2 0 3 4 5 6) __t3jPx265 __v0 __d0 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask194 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex192;  slog::Index** $sup9688x36x0x0x0index193;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord195({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel196 = db->getRelation("$sup9688x36x0x0x1");
      head_index[0] = readrel196->getIndex(ord195, false);
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex192 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 0, 2, 3, 4});
      slog::Relation* readrel200 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index193 = readrel200->getIndex(ord199, false);
  
    }
    ReadTask194(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        slog::join_probe<2,1>(st_hsb_ansindex192, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m201) {
          u64 v_c32 = m201[1];
          slog::join_all<5>($sup9688x36x0x0x0index193, [&](const std::array<u64,5>& m202) {
            u64 v_c57 = m202[0]; u64 v_c9 = m202[1]; u64 v_c58 = m202[2]; u64 v_c59 = m202[3]; u64 v_c60 = m202[4];
            u64 v_c61 = _prim_band(db, v_c57, v_c32);
            if (v_c61 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            u64 v_c62 = _prim_lt(db, v_c61, v_c54);
            if (v_c62 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            if (!v_c62) return;
            u64 v_c63 = _prim_bxor(db, v_c57, v_c58);
            if (v_c63 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            if (v_c56 != v_c63) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c55, v_c32, v_c9, v_c57, v_c58, v_c59, v_c60}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask194* _cont = new ReadTask194(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask194(db,b), false);
  // (crule (pre) (scan pbranch __t7ZZP236 p m l r) (body (exists st_join (1 2 3 4 0) 2 p __t7ZZP236) (exists st_union (1 2 0) 1 __t7ZZP236) (exists st_msk (1 2 0) 1 p) (join $sup9688x120x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 5 l m p r __t7ZZP236 n __t3tZ8235 q __t8STz237 u v) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8STz237) (exists st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_msk (1 2 0) 2 p n) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t7ZZP236 q __t8STz237 __t1ZYa238) (join st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (exists st_join_ans (0 1) 1 __t1ZYa238) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (neq q __v0) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask220 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex204;  slog::Index** st_unionindex205;  slog::Index** st_mskindex206;  slog::Index** $sup9688x120x0x0x0index207;  slog::Index** pbranchindex208;  slog::Index** st_unionindex209;  slog::Index** st_mskindex210;  slog::Index** st_joinindex211;  slog::Index** st_unionindex212;  slog::Index** st_join_ansindex213;  slog::Index** st_mskindex214;  slog::Index** st_msk_ansindex215;  slog::Index** st_join_ansindex216;  slog::Index** pbranchdelta217;  slog::Index** st_joindelta218;  slog::Index** st_mskdelta219;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("st_union_ans");
      head_index[0] = readrel222->getIndex(ord221, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord223({1, 2, 3, 4, 0});
      slog::Relation* readrel224 = db->getRelation("st_join");
      st_joinindex204 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("st_union");
      st_unionindex205 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("st_msk");
      st_mskindex206 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel230 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index207 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 3, 4, 0});
      slog::Relation* readrel232 = db->getRelation("pbranch");
      pbranchindex208 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 3, 4, 0});
      slog::Relation* readrel234 = db->getRelation("pbranch");
      pbranchdelta217 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("st_union");
      st_unionindex209 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("st_msk");
      st_mskindex210 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 3, 4, 0});
      slog::Relation* readrel240 = db->getRelation("st_join");
      st_joinindex211 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 2, 3, 4, 0});
      slog::Relation* readrel242 = db->getRelation("st_join");
      st_joindelta218 = readrel242->getIndex(ord241, true);
      std::vector<u16> ord243({0, 1, 2});
      slog::Relation* readrel244 = db->getRelation("st_union");
      st_unionindex212 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({0, 1});
      slog::Relation* readrel246 = db->getRelation("st_join_ans");
      st_join_ansindex213 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 2, 0});
      slog::Relation* readrel248 = db->getRelation("st_msk");
      st_mskindex214 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("st_msk");
      st_mskdelta219 = readrel250->getIndex(ord249, true);
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("st_msk_ans");
      st_msk_ansindex215 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("st_join_ans");
      st_join_ansindex216 = readrel254->getIndex(ord253, false);
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c14 = _t[4];
        if (!slog::exists_probe<5,2>(st_joinindex204, std::array<u64,5>{v_c13, v_c64, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex205, std::array<u64,3>{v_c64, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex206, std::array<u64,3>{v_c13, 0, 0})) return;
        slog::join_probe<11,5>($sup9688x120x0x0x0index207, std::array<u64,11>{v_c11, v_c12, v_c13, v_c14, v_c64, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m255) {
          u64 v_c22 = m255[5]; u64 v_c65 = m255[6]; u64 v_c21 = m255[7]; u64 v_c66 = m255[8]; u64 v_c23 = m255[9]; u64 v_c24 = m255[10];
          u64 v_c67 = _prim_lt(db, v_c12, v_c22);
          if (v_c67 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
          if (!v_c67) return;
          slog::join_probe_old<5,5>(pbranchindex208, pbranchdelta217, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c66}, [&](const std::array<u64,5>& m257) {
            if (!slog::exists_probe<3,3>(st_unionindex209, std::array<u64,3>{v_c65, v_c64, v_c66})) return;
            if (!slog::exists_probe<3,2>(st_mskindex210, std::array<u64,3>{v_c13, v_c22, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex211, st_joindelta218, std::array<u64,5>{v_c13, v_c64, v_c21, v_c66, 0}, [&](const std::array<u64,5>& m258) {
              u64 v_c68 = m258[4];
              slog::join_probe<3,3>(st_unionindex212, std::array<u64,3>{v_c65, v_c64, v_c66}, [&](const std::array<u64,3>& m259) {
                if (!slog::exists_probe<2,1>(st_join_ansindex213, std::array<u64,2>{v_c68, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex214, st_mskdelta219, std::array<u64,3>{v_c13, v_c22, 0}, [&](const std::array<u64,3>& m260) {
                  u64 v_c69 = m260[2];
                  slog::join_probe<2,1>(st_msk_ansindex215, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m261) {
                    u64 v_c32 = m261[1];
                    if (v_c21 == v_c32) return;
                    slog::join_probe<2,1>(st_join_ansindex216, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m262) {
                      u64 v_c70 = m262[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c70}, std::array<u16,2>{0, 1});
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
        ReadTask220* _cont = new ReadTask220(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask220(db,b), false);
  // (crule (pre) (scan st_del __t3SFe567 __t5rDd566 k) (body (exists st_msk (1 2 0) 1 k) (join $sup9688x87x0x0x0 (0 1 2 3 4 5) 2 __t3SFe567 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t5rDd566) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t0CrA568) (join st_msk_ans (0 1) 1 __t0CrA568 __v0) (neq p __v0)) (head (emit st_del_ans (0 1) __t3SFe567 __t5rDd566)) set.slog:88 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex263;  slog::Index** $sup9688x87x0x0x0index264;  slog::Index** pbranchindex265;  slog::Index** st_mskindex266;  slog::Index** st_msk_ansindex267;  slog::Index** st_mskdelta268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("st_del_ans");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("st_msk");
      st_mskindex263 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel275 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0index264 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 3, 4, 0});
      slog::Relation* readrel277 = db->getRelation("pbranch");
      pbranchindex265 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 2, 0});
      slog::Relation* readrel279 = db->getRelation("st_msk");
      st_mskindex266 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 2, 0});
      slog::Relation* readrel281 = db->getRelation("st_msk");
      st_mskdelta268 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({0, 1});
      slog::Relation* readrel283 = db->getRelation("st_msk_ans");
      st_msk_ansindex267 = readrel283->getIndex(ord282, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c72 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<3,1>(st_mskindex263, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x87x0x0x0index264, std::array<u64,6>{v_c71, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,6>& m284) {
          u64 v_c11 = m284[2]; u64 v_c12 = m284[3]; u64 v_c13 = m284[4]; u64 v_c14 = m284[5];
          slog::join_probe<5,5>(pbranchindex265, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, v_c72}, [&](const std::array<u64,5>& m285) {
            slog::join_probe_old<3,2>(st_mskindex266, st_mskdelta268, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m286) {
              u64 v_c73 = m286[2];
              slog::join_probe<2,1>(st_msk_ansindex267, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m287) {
                u64 v_c32 = m287[1];
                if (v_c13 == v_c32) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c72}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan st_ins_ans __t7Z9l430 r) (body (join-old st_ins (0 2 1) 1 (0 2 1) __t7Z9l430 k s) (exists st_union (1 2 0) 1 s) (join-old pleaf (1 0) 1 (1 0) k __t65ux428) (join-old st_union (1 2 0) 2 (1 2 0) s __t65ux428 __t8LrU429)) (head (emit st_union_ans (0 1) __t8LrU429 r)) set.slog:99 #f)
  class ReadTask295 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex288;  slog::Index** st_unionindex289;  slog::Index** pleafindex290;  slog::Index** st_unionindex291;  slog::Index** st_insdelta292;  slog::Index** pleafdelta293;  slog::Index** st_uniondelta294;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("st_union_ans");
      head_index[0] = readrel297->getIndex(ord296, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord298({0, 2, 1});
      slog::Relation* readrel299 = db->getRelation("st_ins");
      st_insindex288 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 2, 1});
      slog::Relation* readrel301 = db->getRelation("st_ins");
      st_insdelta292 = readrel301->getIndex(ord300, true);
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("st_union");
      st_unionindex289 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("pleaf");
      pleafindex290 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 0});
      slog::Relation* readrel307 = db->getRelation("pleaf");
      pleafdelta293 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("st_union");
      st_unionindex291 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("st_union");
      st_uniondelta294 = readrel311->getIndex(ord310, true);
  
    }
    ReadTask295(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c74 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<3,1>(st_insindex288, st_insdelta292, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m312) {
          u64 v_c10 = m312[1]; u64 v_c2 = m312[2];
          if (!slog::exists_probe<3,1>(st_unionindex289, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>(pleafindex290, pleafdelta293, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m313) {
            u64 v_c75 = m313[1];
            slog::join_probe_old<3,2>(st_unionindex291, st_uniondelta294, std::array<u64,3>{v_c2, v_c75, 0}, [&](const std::array<u64,3>& m314) {
              u64 v_c76 = m314[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c76, v_c14}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask295* _cont = new ReadTask295(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask295(db,b), false);
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan $sup9688x148x0x0x0 __t5Ek2104 l m n p q r u v) (body (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 u) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6SZQ102) (exists st_diff (2 0 1) 2 __t6SZQ102 __t5Ek2104) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6qKy107) (join-old st_diff (0 1 2) 3 (0 1 2) __t5Ek2104 __t6qKy107 __t6SZQ102) (join-old st_diff (1 2 0) 2 (1 2 0) __t6qKy107 u __t4u9h108) (exists st_diff_ans (0 1) 1 __t4u9h108) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3oZy109) (join st_msk_ans (0 1) 2 __t3oZy109 q) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask333 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex315;  slog::Index** st_diffindex316;  slog::Index** st_mskindex317;  slog::Index** st_msk_ansindex318;  slog::Index** pbranchindex319;  slog::Index** st_diffindex320;  slog::Index** pbranchindex321;  slog::Index** st_diffindex322;  slog::Index** st_diffindex323;  slog::Index** st_diff_ansindex324;  slog::Index** st_mskindex325;  slog::Index** st_msk_ansindex326;  slog::Index** st_diff_ansindex327;  slog::Index** pbranchdelta328;  slog::Index** pbranchdelta329;  slog::Index** st_diffdelta330;  slog::Index** st_diffdelta331;  slog::Index** st_mskdelta332;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("st_diff_ans");
      head_index[0] = readrel335->getIndex(ord334, false);
      outer_rel = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord336({1, 2, 3, 4, 0});
      slog::Relation* readrel337 = db->getRelation("pbranch");
      pbranchindex315 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({2, 0, 1});
      slog::Relation* readrel339 = db->getRelation("st_diff");
      st_diffindex316 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 2, 0});
      slog::Relation* readrel341 = db->getRelation("st_msk");
      st_mskindex317 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 0});
      slog::Relation* readrel343 = db->getRelation("st_msk_ans");
      st_msk_ansindex318 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 3, 4, 0});
      slog::Relation* readrel345 = db->getRelation("pbranch");
      pbranchindex319 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 2, 3, 4, 0});
      slog::Relation* readrel347 = db->getRelation("pbranch");
      pbranchdelta328 = readrel347->getIndex(ord346, true);
      std::vector<u16> ord348({2, 0, 1});
      slog::Relation* readrel349 = db->getRelation("st_diff");
      st_diffindex320 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 3, 4, 0});
      slog::Relation* readrel351 = db->getRelation("pbranch");
      pbranchindex321 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 3, 4, 0});
      slog::Relation* readrel353 = db->getRelation("pbranch");
      pbranchdelta329 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1, 2});
      slog::Relation* readrel355 = db->getRelation("st_diff");
      st_diffindex322 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1, 2});
      slog::Relation* readrel357 = db->getRelation("st_diff");
      st_diffdelta330 = readrel357->getIndex(ord356, true);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("st_diff");
      st_diffindex323 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 2, 0});
      slog::Relation* readrel361 = db->getRelation("st_diff");
      st_diffdelta331 = readrel361->getIndex(ord360, true);
      std::vector<u16> ord362({0, 1});
      slog::Relation* readrel363 = db->getRelation("st_diff_ans");
      st_diff_ansindex324 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("st_msk");
      st_mskindex325 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 2, 0});
      slog::Relation* readrel367 = db->getRelation("st_msk");
      st_mskdelta332 = readrel367->getIndex(ord366, true);
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("st_msk_ans");
      st_msk_ansindex326 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({0, 1});
      slog::Relation* readrel371 = db->getRelation("st_diff_ans");
      st_diff_ansindex327 = readrel371->getIndex(ord370, false);
  
    }
    ReadTask333(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c78 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c23 = _t[7];
        u64 v_c24 = _t[8];
        u64 v_c79 = _prim_lt(db, v_c12, v_c22);
        if (v_c79 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
        if (!v_c79) return;
        if (!slog::exists_probe<5,4>(pbranchindex315, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex316, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex317, std::array<u64,3>{v_c13, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex318, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex319, pbranchdelta328, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m373) {
          u64 v_c80 = m373[4];
          if (!slog::exists_probe<3,2>(st_diffindex320, std::array<u64,3>{v_c80, v_c78, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex321, pbranchdelta329, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m374) {
            u64 v_c81 = m374[4];
            slog::join_probe_old<3,3>(st_diffindex322, st_diffdelta330, std::array<u64,3>{v_c78, v_c81, v_c80}, [&](const std::array<u64,3>& m375) {
              slog::join_probe_old<3,2>(st_diffindex323, st_diffdelta331, std::array<u64,3>{v_c81, v_c23, 0}, [&](const std::array<u64,3>& m376) {
                u64 v_c82 = m376[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex324, std::array<u64,2>{v_c82, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex325, st_mskdelta332, std::array<u64,3>{v_c13, v_c22, 0}, [&](const std::array<u64,3>& m377) {
                  u64 v_c83 = m377[2];
                  slog::join_probe<2,2>(st_msk_ansindex326, std::array<u64,2>{v_c83, v_c21}, [&](const std::array<u64,2>& m378) {
                    slog::join_probe<2,1>(st_diff_ansindex327, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m379) {
                      u64 v_c70 = m379[1];
                      u64 v_c84 = _prim_band(db, v_c13, v_c22);
                      if (v_c84 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c85 = _prim_lt(db, v_c84, v_c77);
                      if (v_c85 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c85) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c78, v_c70}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:$sup9688x148x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask333* _cont = new ReadTask333(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask333(db,b), false);
  // (crule (pre) (scan st_union __t3dip529 __t4nDr530 __t78TS531) (body (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t4nDr530 p m l r) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t78TS531 q n u v) (cmp lt m n)) (head (emit $sup9688x120x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t3dip529 l m q r __t4nDr530 __t78TS531 u v)) set.slog:121 #f)
  class ReadTask385 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex381;  slog::Index** pbranchindex382;  slog::Index** pbranchdelta383;  slog::Index** pbranchdelta384;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord386({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel387 = db->getRelation("$sup9688x120x0x0x0");
      head_index[0] = readrel387->getIndex(ord386, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord388({0, 1, 2, 3, 4});
      slog::Relation* readrel389 = db->getRelation("pbranch");
      pbranchindex381 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({0, 1, 2, 3, 4});
      slog::Relation* readrel391 = db->getRelation("pbranch");
      pbranchdelta383 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({0, 1, 2, 3, 4});
      slog::Relation* readrel393 = db->getRelation("pbranch");
      pbranchindex382 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1, 2, 3, 4});
      slog::Relation* readrel395 = db->getRelation("pbranch");
      pbranchdelta384 = readrel395->getIndex(ord394, true);
  
    }
    ReadTask385(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[2];
        slog::join_probe_old<5,1>(pbranchindex381, pbranchdelta383, std::array<u64,5>{v_c26, 0, 0, 0, 0}, [&](const std::array<u64,5>& m396) {
          u64 v_c13 = m396[1]; u64 v_c12 = m396[2]; u64 v_c11 = m396[3]; u64 v_c14 = m396[4];
          slog::join_probe_old<5,1>(pbranchindex382, pbranchdelta384, std::array<u64,5>{v_c20, 0, 0, 0, 0}, [&](const std::array<u64,5>& m397) {
            u64 v_c21 = m397[1]; u64 v_c22 = m397[2]; u64 v_c23 = m397[3]; u64 v_c24 = m397[4];
            u64 v_c86 = _prim_lt(db, v_c12, v_c22);
            if (v_c86 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c86) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c22, v_c13, v_c25, v_c11, v_c12, v_c21, v_c14, v_c26, v_c20, v_c23, v_c24}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask385* _cont = new ReadTask385(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask385(db,b), false);
  // (crule (pre (let __tconst7Gyt29 const6b86b273ff34fce19d6b804e)) (scan pleaf __t53uv30 k) (body (join-old st_mem0 (1 2 0) 2 (1 2 0) __t53uv30 k __t7Db431)) (head (emit st_mem0_ans (0 1) __t7Db431 __tconst7Gyt29)) set.slog:68 #f)
  class ReadTask401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index399;  slog::Index** st_mem0delta400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel403->getIndex(ord402, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("st_mem0");
      st_mem0index399 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("st_mem0");
      st_mem0delta400 = readrel407->getIndex(ord406, true);
  
    }
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,2>(st_mem0index399, st_mem0delta400, std::array<u64,3>{v_c88, v_c10, 0}, [&](const std::array<u64,3>& m408) {
          u64 v_c89 = m408[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c89, v_c87}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:68", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask401* _cont = new ReadTask401(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t9xbE359 __v2) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t9xbE359 p0 __v1) (exists $sup9688x36x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup9688x36x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup9688x36x0x0x0 (1 0 2 3 4) 1 p0) (exists st_join (1 2 3 4 0) 1 p0) (join-old st_hsb_ans (1 0) 1 (1 0) __v1 __t75bg356) (exists $sup9688x36x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t75bg356) (exists $sup9688x36x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t75bg356) (exists st_hsb_ans (0 1) 1 __t75bg356) (join st_hsb_ans (0 1) 1 __t75bg356 __v3) (join $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t75bg356 __v1 __v3 p0 __t0kmv352 dup66Lo1333 dup68E21334 __v0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v0) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex409;  slog::Index** $sup9688x36x0x0x2index410;  slog::Index** $sup9688x36x0x0x1index411;  slog::Index** $sup9688x36x0x0x0index412;  slog::Index** st_joinindex413;  slog::Index** st_hsb_ansindex414;  slog::Index** $sup9688x36x0x0x2index415;  slog::Index** $sup9688x36x0x0x1index416;  slog::Index** st_hsb_ansindex417;  slog::Index** st_hsb_ansindex418;  slog::Index** $sup9688x36x0x0x2index419;  slog::Index** $sup9688x36x0x0x1index420;  slog::Index** $sup9688x36x0x0x0index421;  slog::Index** st_joinindex422;  slog::Index** st_hsb_ansindex423;  slog::Index** st_hsbindex424;  slog::Index** st_mskdelta425;  slog::Index** st_hsb_ansdelta426;  slog::Index** st_joindelta427;  slog::Index** st_hsb_ansdelta428;  slog::Index** st_hsbdelta429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord431({0, 1, 2});
      slog::Relation* readrel432 = db->getRelation("st_msk");
      st_mskindex409 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({0, 1, 2});
      slog::Relation* readrel434 = db->getRelation("st_msk");
      st_mskdelta425 = readrel434->getIndex(ord433, true);
      std::vector<u16> ord435({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel436 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index410 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel438 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index411 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 0, 2, 3, 4});
      slog::Relation* readrel440 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index412 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 3, 4, 0});
      slog::Relation* readrel442 = db->getRelation("st_join");
      st_joinindex413 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 0});
      slog::Relation* readrel444 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex414 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 0});
      slog::Relation* readrel446 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta426 = readrel446->getIndex(ord445, true);
      std::vector<u16> ord447({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel448 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index415 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel450 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index416 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({0, 1});
      slog::Relation* readrel452 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex417 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 1});
      slog::Relation* readrel454 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex418 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel456 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index419 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel458 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index420 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 0, 2, 3, 4});
      slog::Relation* readrel460 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index421 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 3, 4, 0});
      slog::Relation* readrel462 = db->getRelation("st_join");
      st_joinindex422 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 3, 4, 0});
      slog::Relation* readrel464 = db->getRelation("st_join");
      st_joindelta427 = readrel464->getIndex(ord463, true);
      std::vector<u16> ord465({0, 1});
      slog::Relation* readrel466 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex423 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta428 = readrel468->getIndex(ord467, true);
      std::vector<u16> ord469({0, 1});
      slog::Relation* readrel470 = db->getRelation("st_hsb");
      st_hsbindex424 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 1});
      slog::Relation* readrel472 = db->getRelation("st_hsb");
      st_hsbdelta429 = readrel472->getIndex(ord471, true);
  
    }
    ReadTask430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c91 = _t[0];
        u64 v_c92 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex409, st_mskdelta425, std::array<u64,3>{v_c91, 0, 0}, [&](const std::array<u64,3>& m473) {
          u64 v_c57 = m473[1]; u64 v_c93 = m473[2];
          if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index410, std::array<u64,11>{v_c93, v_c57, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup9688x36x0x0x1index411, std::array<u64,7>{v_c57, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup9688x36x0x0x0index412, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(st_joinindex413, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex414, st_hsb_ansdelta426, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m474) {
            u64 v_c94 = m474[1];
            if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index415, std::array<u64,11>{v_c93, v_c57, v_c94, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index416, std::array<u64,7>{v_c57, v_c94, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_hsb_ansindex417, std::array<u64,2>{v_c94, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex418, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m475) {
              u64 v_c95 = m475[1];
              slog::join_probe<11,4>($sup9688x36x0x0x2index419, std::array<u64,11>{v_c94, v_c93, v_c95, v_c57, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m476) {
                u64 v_c96 = m476[4]; u64 v_c97 = m476[5]; u64 v_c98 = m476[6]; u64 v_c32 = m476[7]; u64 v_c58 = m476[8]; u64 v_c59 = m476[9]; u64 v_c60 = m476[10];
                if (v_c94 != v_c98) return;
                if (v_c94 != v_c97) return;
                slog::join_probe<7,7>($sup9688x36x0x0x1index420, std::array<u64,7>{v_c96, v_c57, v_c58, v_c59, v_c60, v_c94, v_c32}, [&](const std::array<u64,7>& m477) {
                  slog::join_probe<5,5>($sup9688x36x0x0x0index421, std::array<u64,5>{v_c57, v_c96, v_c58, v_c59, v_c60}, [&](const std::array<u64,5>& m478) {
                    slog::join_probe_old<5,5>(st_joinindex422, st_joindelta427, std::array<u64,5>{v_c57, v_c59, v_c58, v_c60, v_c96}, [&](const std::array<u64,5>& m479) {
                      slog::join_probe_old<2,2>(st_hsb_ansindex423, st_hsb_ansdelta428, std::array<u64,2>{v_c94, v_c32}, [&](const std::array<u64,2>& m480) {
                        u64 v_c99 = _prim_bxor(db, v_c57, v_c58);
                        if (v_c99 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex424, st_hsbdelta429, std::array<u64,2>{v_c94, v_c99}, [&](const std::array<u64,2>& m481) {
                          u64 v_c100 = _prim_band(db, v_c57, v_c32);
                          if (v_c100 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c101 = _prim_lt(db, v_c100, v_c90);
                          if (v_c101 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c101) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c96, v_c92, v_c95, v_c59, v_c60});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c92, v_c95, v_c59, v_c60}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask430* _cont = new ReadTask430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask430(db,b), false);
  // (crule (pre) (scan st_join __t6WK8115 k __t3mOh114 j __t29mi113) (body (neq j k) (join pleaf (0 1) 2 __t29mi113 j) (join pleaf (0 1) 2 __t3mOh114 k) (exists st_join_ans (0 1) 1 __t6WK8115) (join st_ins (1 2 0) 2 __t29mi113 k __t1Tua112) (join st_join_ans (0 1) 1 __t6WK8115 r)) (head (emit st_ins_ans (0 1) __t1Tua112 r)) set.slog:50 #f)
  class ReadTask488 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex483;  slog::Index** pleafindex484;  slog::Index** st_join_ansindex485;  slog::Index** st_insindex486;  slog::Index** st_join_ansindex487;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord489({0, 1});
      slog::Relation* readrel490 = db->getRelation("st_ins_ans");
      head_index[0] = readrel490->getIndex(ord489, false);
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("pleaf");
      pleafindex483 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({0, 1});
      slog::Relation* readrel494 = db->getRelation("pleaf");
      pleafindex484 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({0, 1});
      slog::Relation* readrel496 = db->getRelation("st_join_ans");
      st_join_ansindex485 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("st_ins");
      st_insindex486 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("st_join_ans");
      st_join_ansindex487 = readrel500->getIndex(ord499, false);
  
    }
    ReadTask488(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        u64 v_c16 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c18 = _t[4];
        if (v_c17 == v_c10) return;
        slog::join_probe<2,2>(pleafindex483, std::array<u64,2>{v_c18, v_c17}, [&](const std::array<u64,2>& m501) {
          slog::join_probe<2,2>(pleafindex484, std::array<u64,2>{v_c16, v_c10}, [&](const std::array<u64,2>& m502) {
            if (!slog::exists_probe<2,1>(st_join_ansindex485, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe<3,2>(st_insindex486, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m503) {
              u64 v_c19 = m503[2];
              slog::join_probe<2,1>(st_join_ansindex487, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m504) {
                u64 v_c14 = m504[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c14}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask488* _cont = new ReadTask488(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask488(db,b), false);
  // (crule (pre (let __trid2iJe844 constb0e9a61bdf716031c5ca8c29) (let __trel5hkg845 consta10f76b4ec574de5d7b6908e) (let __tcol0ZM7846 const5feceb66ffc86f38d952786c) (let __trel7OoZ847 consta10f76b4ec574de5d7b6908e) (let __tcol5WH8848 const6b86b273ff34fce19d6b804e)) (scan $sup9688x52x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid2iJe844 __trel5hkg845 __tcol0ZM7846 (1 2 3 4 0)) (tycheck m (accept int) __trid2iJe844 __trel7OoZ847 __tcol5WH8848 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __3XHq843 k m)) set.slog:53 #f)
  class ReadTask505 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x52x0x0x0");
  
    }
    ReadTask505(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_constb0e9a61bdf716031c5ca8c29;
      u64 v_c103 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c104 = v_const5feceb66ffc86f38d952786c;
      u64 v_c105 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c106 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c14 = _t[5];
        ++_fires;
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c102, v_c103, v_c104, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c12)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c102, v_c105, v_c106, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:$sup9688x52x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask505* _cont = new ReadTask505(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask505(db,b), false);
  // (crule (pre) (scan $sup9688x40x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t6JPy526 (bxor p0 p1))) (head (emit-temp temp9CLY1403 __t6JPy526)) set.slog:41 #f)
  class ReadTask506 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9CLY1403");
      outer_rel = db->getRelation("$sup9688x40x0x0x1");
  
    }
    ReadTask506(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c107 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c58 = _t[4];
        u64 v_c59 = _t[5];
        u64 v_c60 = _t[6];
        u64 v_c108 = _prim_bxor(db, v_c57, v_c58);
        if (v_c108 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c108});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask506* _cont = new ReadTask506(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask506(db,b), false);
  // (crule (pre (let __trid4bDq789 const76a4fedc25549f0939d52fb7) (let __trel1o0k790 const26c89ee8ccc4ea998fd1a912) (let __tcol6PPW791 const4e07408562bedb8b60ce05c1)) (scan st_msk_ans __t5gdG368 p) (body (exists $sup9688x88x0x0x0 (4 3 5 2 0 1) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t5gdG368 k m) (exists st_del (2 0 1) 1 k) (join $sup9688x88x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old st_del (1 2 0) 2 (1 2 0) l k __t8asA369) (join-old st_del_ans (0 1) 1 (0 1) __t8asA369 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bDq789 __trel1o0k790 __tcol6PPW791 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __3BTR788 p m __v0 r)) set.slog:89 #f)
  class ReadTask519 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index507;  slog::Index** st_mskindex508;  slog::Index** st_delindex509;  slog::Index** $sup9688x88x0x0x0index510;  slog::Index** st_delindex511;  slog::Index** st_del_ansindex512;  slog::Index** st_mskdelta513;  slog::Index** st_deldelta514;  slog::Index** st_del_ansdelta515;
    u32 sid517;  u32 sid516;  u32 sid518;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord520({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel521 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index507 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({0, 1, 2});
      slog::Relation* readrel523 = db->getRelation("st_msk");
      st_mskindex508 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({0, 1, 2});
      slog::Relation* readrel525 = db->getRelation("st_msk");
      st_mskdelta513 = readrel525->getIndex(ord524, true);
      std::vector<u16> ord526({2, 0, 1});
      slog::Relation* readrel527 = db->getRelation("st_del");
      st_delindex509 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel529 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index510 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("st_del");
      st_delindex511 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("st_del");
      st_deldelta514 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("st_del_ans");
      st_del_ansindex512 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("st_del_ans");
      st_del_ansdelta515 = readrel537->getIndex(ord536, true);
      sid517 = db->getRelation("_enum")->getStructId();
      sid516 = db->getRelation("pbranch")->getStructId();
      sid518 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask519(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c109 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c110 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c111 = v_const4e07408562bedb8b60ce05c1;
  
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
        if (!slog::exists_probe<6,1>($sup9688x88x0x0x0index507, std::array<u64,6>{v_c13, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex508, st_mskdelta513, std::array<u64,3>{v_c112, 0, 0}, [&](const std::array<u64,3>& m538) {
          u64 v_c10 = m538[1]; u64 v_c12 = m538[2];
          if (!slog::exists_probe<3,1>(st_delindex509, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x88x0x0x0index510, std::array<u64,6>{v_c10, v_c12, v_c13, 0, 0, 0}, [&](const std::array<u64,6>& m539) {
            u64 v_c9 = m539[3]; u64 v_c11 = m539[4]; u64 v_c14 = m539[5];
            slog::join_probe_old<3,2>(st_delindex511, st_deldelta514, std::array<u64,3>{v_c11, v_c10, 0}, [&](const std::array<u64,3>& m540) {
              u64 v_c113 = m540[2];
              slog::join_probe_old<2,1>(st_del_ansindex512, st_del_ansdelta515, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m541) {
                u64 v_c32 = m541[1];
                ++_fires;
                if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid516 || decode_struct_id(v_c14) == sid517 || decode_struct_id(v_c14) == sid518))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c109, v_c110, v_c111, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c32, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask519* _cont = new ReadTask519(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask519(db,b), false);
  // (crule (pre) (scan temp3Stv1345 __t7KDg345 __v0 l m p) (body (join pbranch (1 2 3 4 0) 4 p m l __v0 __t0u8a342)) (head (emit st_union_ans (0 1) __t7KDg345 __t0u8a342)) set.slog:107 #f)
  class ReadTask543 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex542;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("st_union_ans");
      head_index[0] = readrel545->getIndex(ord544, false);
      outer_rel = db->getRelation("temp3Stv1345");
      std::vector<u16> ord546({1, 2, 3, 4, 0});
      slog::Relation* readrel547 = db->getRelation("pbranch");
      pbranchindex542 = readrel547->getIndex(ord546, false);
  
    }
    ReadTask543(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c13 = _t[4];
        slog::join_probe<5,4>(pbranchindex542, std::array<u64,5>{v_c13, v_c12, v_c11, v_c32, 0}, [&](const std::array<u64,5>& m548) {
          u64 v_c115 = m548[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c114, v_c115}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:temp3Stv1345", _fires);
  
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
  // (crule (pre (let __tconst8eZh210 const5feceb66ffc86f38d952786c)) (scan st_ins __t90D6209 __t9thx208 k) (body (join pbranch (0 1 2 3 4) 1 __t9thx208 p m l r) (let __t6CjD211 (band k m)) (cmp gt __t6CjD211 __tconst8eZh210)) (head (emit $sup9688x52x0x0x0 (4 2 3 5 0 1) p l m r __t90D6209 k)) set.slog:53 #f)
  class ReadTask550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord551({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel552 = db->getRelation("$sup9688x52x0x0x0");
      head_index[0] = readrel552->getIndex(ord551, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord553({0, 1, 2, 3, 4});
      slog::Relation* readrel554 = db->getRelation("pbranch");
      pbranchindex549 = readrel554->getIndex(ord553, false);
  
    }
    ReadTask550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c10 = _t[2];
        slog::join_probe<5,1>(pbranchindex549, std::array<u64,5>{v_c118, 0, 0, 0, 0}, [&](const std::array<u64,5>& m555) {
          u64 v_c13 = m555[1]; u64 v_c12 = m555[2]; u64 v_c11 = m555[3]; u64 v_c14 = m555[4];
          u64 v_c119 = _prim_band(db, v_c10, v_c12);
          if (v_c119 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
          u64 v_c120 = _prim_gt(db, v_c119, v_c116);
          if (v_c120 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
          if (!v_c120) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c13, v_c11, v_c12, v_c14, v_c117, v_c10}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:st_ins", _fires);
  
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
  // (crule (pre) (scan temp1foc1411 __t8J2j229) (body) (head (mkstruct st_hsb (1 0) __8CGO686 __t8J2j229)) set.slog:41 #f)
  class ReadTask557 : public slog::Task
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
      outer_rel = db->getRelation("temp1foc1411");
  
    }
    ReadTask557(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c121}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:temp1foc1411", _fires);
  
      if (!_done)
      {
        ReadTask557* _cont = new ReadTask557(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask557(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan st_diff_ans __t9ide547 __v0) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t9ide547 l __t3QFk546) (exists $sup9688x139x0x0x0 (1 0 2 3 4 5 6 7 8) 1 l) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t3QFk546 q n u v) (exists st_msk (1 2 0) 1 q) (join $sup9688x139x0x0x0 (3 5 7 8 1 0 2 4 6) 5 n q u v l __d0 m p r) (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t9Eou545) (join st_msk_ans (0 1) 2 __t9Eou545 p)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask572 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex558;  slog::Index** $sup9688x139x0x0x0index559;  slog::Index** pbranchindex560;  slog::Index** st_mskindex561;  slog::Index** $sup9688x139x0x0x0index562;  slog::Index** st_msk_ansindex563;  slog::Index** st_mskindex564;  slog::Index** st_msk_ansindex565;  slog::Index** st_diffdelta566;  slog::Index** pbranchdelta567;  slog::Index** st_mskdelta568;
    u32 sid570;  u32 sid569;  u32 sid571;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord573({0, 1, 2});
      slog::Relation* readrel574 = db->getRelation("st_diff");
      st_diffindex558 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 1, 2});
      slog::Relation* readrel576 = db->getRelation("st_diff");
      st_diffdelta566 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({1, 0, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel578 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index559 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1, 2, 3, 4});
      slog::Relation* readrel580 = db->getRelation("pbranch");
      pbranchindex560 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({0, 1, 2, 3, 4});
      slog::Relation* readrel582 = db->getRelation("pbranch");
      pbranchdelta567 = readrel582->getIndex(ord581, true);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("st_msk");
      st_mskindex561 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({3, 5, 7, 8, 1, 0, 2, 4, 6});
      slog::Relation* readrel586 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index562 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 0});
      slog::Relation* readrel588 = db->getRelation("st_msk_ans");
      st_msk_ansindex563 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("st_msk");
      st_mskindex564 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 0});
      slog::Relation* readrel592 = db->getRelation("st_msk");
      st_mskdelta568 = readrel592->getIndex(ord591, true);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("st_msk_ans");
      st_msk_ansindex565 = readrel594->getIndex(ord593, false);
      sid570 = db->getRelation("_enum")->getStructId();
      sid569 = db->getRelation("pbranch")->getStructId();
      sid571 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask572(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c123 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c124 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c125 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex558, st_diffdelta566, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m595) {
          u64 v_c11 = m595[1]; u64 v_c126 = m595[2];
          if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index559, std::array<u64,9>{v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(pbranchindex560, pbranchdelta567, std::array<u64,5>{v_c126, 0, 0, 0, 0}, [&](const std::array<u64,5>& m596) {
            u64 v_c21 = m596[1]; u64 v_c22 = m596[2]; u64 v_c23 = m596[3]; u64 v_c24 = m596[4];
            if (!slog::exists_probe<3,1>(st_mskindex561, std::array<u64,3>{v_c21, 0, 0})) return;
            slog::join_probe<9,5>($sup9688x139x0x0x0index562, std::array<u64,9>{v_c22, v_c21, v_c23, v_c24, v_c11, 0, 0, 0, 0}, [&](const std::array<u64,9>& m597) {
              u64 v_c9 = m597[5]; u64 v_c12 = m597[6]; u64 v_c13 = m597[7]; u64 v_c14 = m597[8];
              if (!slog::exists_probe<2,1>(st_msk_ansindex563, std::array<u64,2>{v_c13, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex564, st_mskdelta568, std::array<u64,3>{v_c21, v_c12, 0}, [&](const std::array<u64,3>& m598) {
                u64 v_c127 = m598[2];
                slog::join_probe<2,2>(st_msk_ansindex565, std::array<u64,2>{v_c127, v_c13}, [&](const std::array<u64,2>& m599) {
                  ++_fires;
                  if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid569 || decode_struct_id(v_c14) == sid570 || decode_struct_id(v_c14) == sid571))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c122, v_c123, v_c124, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c32, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask572* _cont = new ReadTask572(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask572(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan $sup9688x151x0x0x0 __t0F4S77 l m n p q r u v) (body (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 v) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3eDW75) (exists st_diff (2 0 1) 2 __t3eDW75 __t0F4S77) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0L1D80) (join-old st_diff (0 1 2) 3 (0 1 2) __t0F4S77 __t0L1D80 __t3eDW75) (join-old st_diff (1 2 0) 2 (1 2 0) __t0L1D80 v __t8Vvm81) (exists st_diff_ans (0 1) 1 __t8Vvm81) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join st_msk_ans (0 1) 2 __t1x4A82 q) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask618 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex600;  slog::Index** st_diffindex601;  slog::Index** st_mskindex602;  slog::Index** st_msk_ansindex603;  slog::Index** pbranchindex604;  slog::Index** st_diffindex605;  slog::Index** pbranchindex606;  slog::Index** st_diffindex607;  slog::Index** st_diffindex608;  slog::Index** st_diff_ansindex609;  slog::Index** st_mskindex610;  slog::Index** st_msk_ansindex611;  slog::Index** st_diff_ansindex612;  slog::Index** pbranchdelta613;  slog::Index** pbranchdelta614;  slog::Index** st_diffdelta615;  slog::Index** st_diffdelta616;  slog::Index** st_mskdelta617;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("st_diff_ans");
      head_index[0] = readrel620->getIndex(ord619, false);
      outer_rel = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord621({1, 2, 3, 4, 0});
      slog::Relation* readrel622 = db->getRelation("pbranch");
      pbranchindex600 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({2, 0, 1});
      slog::Relation* readrel624 = db->getRelation("st_diff");
      st_diffindex601 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("st_msk");
      st_mskindex602 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 0});
      slog::Relation* readrel628 = db->getRelation("st_msk_ans");
      st_msk_ansindex603 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 2, 3, 4, 0});
      slog::Relation* readrel630 = db->getRelation("pbranch");
      pbranchindex604 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 2, 3, 4, 0});
      slog::Relation* readrel632 = db->getRelation("pbranch");
      pbranchdelta613 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({2, 0, 1});
      slog::Relation* readrel634 = db->getRelation("st_diff");
      st_diffindex605 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({1, 2, 3, 4, 0});
      slog::Relation* readrel636 = db->getRelation("pbranch");
      pbranchindex606 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 2, 3, 4, 0});
      slog::Relation* readrel638 = db->getRelation("pbranch");
      pbranchdelta614 = readrel638->getIndex(ord637, true);
      std::vector<u16> ord639({0, 1, 2});
      slog::Relation* readrel640 = db->getRelation("st_diff");
      st_diffindex607 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({0, 1, 2});
      slog::Relation* readrel642 = db->getRelation("st_diff");
      st_diffdelta615 = readrel642->getIndex(ord641, true);
      std::vector<u16> ord643({1, 2, 0});
      slog::Relation* readrel644 = db->getRelation("st_diff");
      st_diffindex608 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 0});
      slog::Relation* readrel646 = db->getRelation("st_diff");
      st_diffdelta616 = readrel646->getIndex(ord645, true);
      std::vector<u16> ord647({0, 1});
      slog::Relation* readrel648 = db->getRelation("st_diff_ans");
      st_diff_ansindex609 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({1, 2, 0});
      slog::Relation* readrel650 = db->getRelation("st_msk");
      st_mskindex610 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 2, 0});
      slog::Relation* readrel652 = db->getRelation("st_msk");
      st_mskdelta617 = readrel652->getIndex(ord651, true);
      std::vector<u16> ord653({0, 1});
      slog::Relation* readrel654 = db->getRelation("st_msk_ans");
      st_msk_ansindex611 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("st_diff_ans");
      st_diff_ansindex612 = readrel656->getIndex(ord655, false);
  
    }
    ReadTask618(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c129 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c23 = _t[7];
        u64 v_c24 = _t[8];
        u64 v_c130 = _prim_lt(db, v_c12, v_c22);
        if (v_c130 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
        if (!v_c130) return;
        if (!slog::exists_probe<5,4>(pbranchindex600, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex601, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex602, std::array<u64,3>{v_c13, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex603, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex604, pbranchdelta613, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m658) {
          u64 v_c131 = m658[4];
          if (!slog::exists_probe<3,2>(st_diffindex605, std::array<u64,3>{v_c131, v_c129, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex606, pbranchdelta614, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m659) {
            u64 v_c132 = m659[4];
            slog::join_probe_old<3,3>(st_diffindex607, st_diffdelta615, std::array<u64,3>{v_c129, v_c132, v_c131}, [&](const std::array<u64,3>& m660) {
              slog::join_probe_old<3,2>(st_diffindex608, st_diffdelta616, std::array<u64,3>{v_c132, v_c24, 0}, [&](const std::array<u64,3>& m661) {
                u64 v_c133 = m661[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex609, std::array<u64,2>{v_c133, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex610, st_mskdelta617, std::array<u64,3>{v_c13, v_c22, 0}, [&](const std::array<u64,3>& m662) {
                  u64 v_c134 = m662[2];
                  slog::join_probe<2,2>(st_msk_ansindex611, std::array<u64,2>{v_c134, v_c21}, [&](const std::array<u64,2>& m663) {
                    slog::join_probe<2,1>(st_diff_ansindex612, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m664) {
                      u64 v_c70 = m664[1];
                      u64 v_c135 = _prim_band(db, v_c13, v_c22);
                      if (v_c135 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c136 = _prim_gt(db, v_c135, v_c128);
                      if (v_c136 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c136) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c70}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:$sup9688x151x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask618* _cont = new ReadTask618(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask618(db,b), false);
  // (crule (pre (let __tconst0X5Q704 conste3776bfed7f405de8017ecfa) (let __tconst0saG225 const6b86b273ff34fce19d6b804e) (let __tconst4SDF224 const2c624232cdd221771294dfbb)) (scan st_ins_ans __t3VGi227 __v0) (body (exists _enum (1 0) 1 __tconst0X5Q704) (join-old st_ins (0 2 1) 2 (0 2 1) __t3VGi227 __tconst0saG225 __t5hb6226) (join _enum (0 1) 2 __t5hb6226 __tconst0X5Q704)) (head (mkstruct st_ins (1 2 0) __8Kcs705 __v0 __tconst4SDF224)) st_basic.slog:15 #f)
  class ReadTask670 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex666;  slog::Index** st_insindex667;  slog::Index** _enumindex668;  slog::Index** st_insdelta669;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord671({1, 0});
      slog::Relation* readrel672 = db->getRelation("_enum");
      _enumindex666 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 2, 1});
      slog::Relation* readrel674 = db->getRelation("st_ins");
      st_insindex667 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({0, 2, 1});
      slog::Relation* readrel676 = db->getRelation("st_ins");
      st_insdelta669 = readrel676->getIndex(ord675, true);
      std::vector<u16> ord677({0, 1});
      slog::Relation* readrel678 = db->getRelation("_enum");
      _enumindex668 = readrel678->getIndex(ord677, false);
  
    }
    ReadTask670(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c139 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c140 = _t[0];
        u64 v_c32 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex666, std::array<u64,2>{v_c137, 0})) return;
        slog::join_probe_old<3,2>(st_insindex667, st_insdelta669, std::array<u64,3>{v_c140, v_c138, 0}, [&](const std::array<u64,3>& m679) {
          u64 v_c141 = m679[2];
          slog::join_probe<2,2>(_enumindex668, std::array<u64,2>{v_c141, v_c137}, [&](const std::array<u64,2>& m680) {
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c32, v_c139}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask670* _cont = new ReadTask670(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask670(db,b), false);
  // (crule (pre (let __tconst9NmC41 const6b86b273ff34fce19d6b804e)) (scan pbranch __t6Xp338 q n u v) (body (join-old st_union (2 0 1) 1 (2 0 1) __t6Xp338 __t2Ywo40 __t4Scw39) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t4Scw39 p m l r) (cmp lt m n) (let __t6HP242 (band p n)) (cmp lt __t6HP242 __tconst9NmC41)) (head (emit $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) __t2Ywo40 u l m n p q r v)) set.slog:115 #f)
  class ReadTask685 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex681;  slog::Index** pbranchindex682;  slog::Index** st_uniondelta683;  slog::Index** pbranchdelta684;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord686({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel687 = db->getRelation("$sup9688x114x0x0x0");
      head_index[0] = readrel687->getIndex(ord686, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord688({2, 0, 1});
      slog::Relation* readrel689 = db->getRelation("st_union");
      st_unionindex681 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 0, 1});
      slog::Relation* readrel691 = db->getRelation("st_union");
      st_uniondelta683 = readrel691->getIndex(ord690, true);
      std::vector<u16> ord692({0, 1, 2, 3, 4});
      slog::Relation* readrel693 = db->getRelation("pbranch");
      pbranchindex682 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1, 2, 3, 4});
      slog::Relation* readrel695 = db->getRelation("pbranch");
      pbranchdelta684 = readrel695->getIndex(ord694, true);
  
    }
    ReadTask685(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex681, st_uniondelta683, std::array<u64,3>{v_c143, 0, 0}, [&](const std::array<u64,3>& m696) {
          u64 v_c144 = m696[1]; u64 v_c145 = m696[2];
          slog::join_probe_old<5,1>(pbranchindex682, pbranchdelta684, std::array<u64,5>{v_c145, 0, 0, 0, 0}, [&](const std::array<u64,5>& m697) {
            u64 v_c13 = m697[1]; u64 v_c12 = m697[2]; u64 v_c11 = m697[3]; u64 v_c14 = m697[4];
            u64 v_c146 = _prim_lt(db, v_c12, v_c22);
            if (v_c146 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c146) return;
            u64 v_c147 = _prim_band(db, v_c13, v_c22);
            if (v_c147 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            u64 v_c148 = _prim_lt(db, v_c147, v_c142);
            if (v_c148 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
            if (!v_c148) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c144, v_c23, v_c11, v_c12, v_c22, v_c13, v_c21, v_c14, v_c24}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask685* _cont = new ReadTask685(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask685(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan $sup9688x106x0x0x0 __t7KDg345 l m n p q r u v) (body (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 1 r) (join-old $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t7KDg345 n q u v __t0gfm348) (exists st_msk (1 2 0) 3 q m __t0gfm348) (exists st_msk_ans (0 1) 2 __t0gfm348 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4ii6344) (exists st_union (0 1 2) 2 __t7KDg345 __t4ii6344) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_union (0 1 2) 3 (0 1 2) __t7KDg345 __t4ii6344 __t0LeB349) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask722 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex700;  slog::Index** pbranchindex701;  slog::Index** st_mskindex702;  slog::Index** st_msk_ansindex703;  slog::Index** st_unionindex704;  slog::Index** $sup9688x106x0x0x1index705;  slog::Index** st_mskindex706;  slog::Index** st_msk_ansindex707;  slog::Index** pbranchindex708;  slog::Index** st_unionindex709;  slog::Index** pbranchindex710;  slog::Index** st_unionindex711;  slog::Index** st_mskindex712;  slog::Index** st_msk_ansindex713;  slog::Index** st_unionindex714;  slog::Index** st_union_ansindex715;  slog::Index** $sup9688x106x0x0x1delta716;  slog::Index** pbranchdelta717;  slog::Index** pbranchdelta718;  slog::Index** st_uniondelta719;  slog::Index** st_mskdelta720;  slog::Index** st_uniondelta721;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord723({1, 2, 3, 4, 0});
      slog::Relation* readrel724 = db->getRelation("pbranch");
      pbranchindex700 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 2, 3, 4, 0});
      slog::Relation* readrel726 = db->getRelation("pbranch");
      pbranchindex701 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 2, 0});
      slog::Relation* readrel728 = db->getRelation("st_msk");
      st_mskindex702 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("st_msk_ans");
      st_msk_ansindex703 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({1, 2, 0});
      slog::Relation* readrel732 = db->getRelation("st_union");
      st_unionindex704 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel734 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index705 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel736 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1delta716 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({1, 2, 0});
      slog::Relation* readrel738 = db->getRelation("st_msk");
      st_mskindex706 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("st_msk_ans");
      st_msk_ansindex707 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 2, 3, 4, 0});
      slog::Relation* readrel742 = db->getRelation("pbranch");
      pbranchindex708 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 2, 3, 4, 0});
      slog::Relation* readrel744 = db->getRelation("pbranch");
      pbranchdelta717 = readrel744->getIndex(ord743, true);
      std::vector<u16> ord745({0, 1, 2});
      slog::Relation* readrel746 = db->getRelation("st_union");
      st_unionindex709 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({1, 2, 3, 4, 0});
      slog::Relation* readrel748 = db->getRelation("pbranch");
      pbranchindex710 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 2, 3, 4, 0});
      slog::Relation* readrel750 = db->getRelation("pbranch");
      pbranchdelta718 = readrel750->getIndex(ord749, true);
      std::vector<u16> ord751({0, 1, 2});
      slog::Relation* readrel752 = db->getRelation("st_union");
      st_unionindex711 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({0, 1, 2});
      slog::Relation* readrel754 = db->getRelation("st_union");
      st_uniondelta719 = readrel754->getIndex(ord753, true);
      std::vector<u16> ord755({1, 2, 0});
      slog::Relation* readrel756 = db->getRelation("st_msk");
      st_mskindex712 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 2, 0});
      slog::Relation* readrel758 = db->getRelation("st_msk");
      st_mskdelta720 = readrel758->getIndex(ord757, true);
      std::vector<u16> ord759({0, 1});
      slog::Relation* readrel760 = db->getRelation("st_msk_ans");
      st_msk_ansindex713 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 2, 0});
      slog::Relation* readrel762 = db->getRelation("st_union");
      st_unionindex714 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("st_union");
      st_uniondelta721 = readrel764->getIndex(ord763, true);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("st_union_ans");
      st_union_ansindex715 = readrel766->getIndex(ord765, false);
  
    }
    ReadTask722(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c114 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c23 = _t[7];
        u64 v_c24 = _t[8];
        u64 v_c150 = _prim_lt(db, v_c22, v_c12);
        if (v_c150 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
        if (!v_c150) return;
        if (!slog::exists_probe<5,4>(pbranchindex700, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0})) return;
        if (!slog::exists_probe<5,4>(pbranchindex701, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex702, std::array<u64,3>{v_c21, v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex703, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex704, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe_old<10,9>($sup9688x106x0x0x1index705, $sup9688x106x0x0x1delta716, std::array<u64,10>{v_c14, v_c11, v_c12, v_c13, v_c114, v_c22, v_c21, v_c23, v_c24, 0}, [&](const std::array<u64,10>& m768) {
          u64 v_c151 = m768[9];
          if (!slog::exists_probe<3,3>(st_mskindex706, std::array<u64,3>{v_c21, v_c12, v_c151})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex707, std::array<u64,2>{v_c151, v_c13})) return;
          slog::join_probe_old<5,4>(pbranchindex708, pbranchdelta717, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m769) {
            u64 v_c152 = m769[4];
            if (!slog::exists_probe<3,2>(st_unionindex709, std::array<u64,3>{v_c114, v_c152, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex710, pbranchdelta718, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m770) {
              u64 v_c153 = m770[4];
              slog::join_probe_old<3,3>(st_unionindex711, st_uniondelta719, std::array<u64,3>{v_c114, v_c152, v_c153}, [&](const std::array<u64,3>& m771) {
                slog::join_probe_old<3,3>(st_mskindex712, st_mskdelta720, std::array<u64,3>{v_c21, v_c12, v_c151}, [&](const std::array<u64,3>& m772) {
                  slog::join_probe<2,2>(st_msk_ansindex713, std::array<u64,2>{v_c151, v_c13}, [&](const std::array<u64,2>& m773) {
                    slog::join_probe_old<3,2>(st_unionindex714, st_uniondelta721, std::array<u64,3>{v_c14, v_c153, 0}, [&](const std::array<u64,3>& m774) {
                      u64 v_c154 = m774[2];
                      slog::join_probe<2,1>(st_union_ansindex715, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m775) {
                        u64 v_c32 = m775[1];
                        u64 v_c155 = _prim_band(db, v_c21, v_c12);
                        if (v_c155 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c156 = _prim_gt(db, v_c155, v_c149);
                        if (v_c156 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c156) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c114, v_c32, v_c11, v_c12, v_c13});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c11, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:$sup9688x106x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask722* _cont = new ReadTask722(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask722(db,b), false);
  // (crule (pre) (scan st_join_ans __t744h135 res) (body (join-old st_join (0 1 2 3 4) 1 (0 1 2 3 4) __t744h135 p __t9DTf133 q __t972J134) (exists pbranch (0 1 2 3 4) 2 __t9DTf133 p) (exists pbranch (0 1 2 3 4) 2 __t972J134 q) (exists st_union (1 2 0) 2 __t9DTf133 __t972J134) (exists st_msk (1 2 0) 1 q) (join-old $sup9688x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t9DTf133 __t972J134 __t1PdV132 l m n r u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t9DTf133) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t972J134) (join-old st_union (0 1 2) 3 (0 1 2) __t1PdV132 __t9DTf133 __t972J134) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join-old st_msk_ans (0 1) 1 (0 1) __t4C16136 __v0) (neq p __v0)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask795 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex777;  slog::Index** pbranchindex778;  slog::Index** pbranchindex779;  slog::Index** st_unionindex780;  slog::Index** st_mskindex781;  slog::Index** $sup9688x110x0x0x0index782;  slog::Index** pbranchindex783;  slog::Index** pbranchindex784;  slog::Index** st_unionindex785;  slog::Index** st_mskindex786;  slog::Index** st_msk_ansindex787;  slog::Index** st_joindelta788;  slog::Index** $sup9688x110x0x0x0delta789;  slog::Index** pbranchdelta790;  slog::Index** pbranchdelta791;  slog::Index** st_uniondelta792;  slog::Index** st_mskdelta793;  slog::Index** st_msk_ansdelta794;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord796({0, 1});
      slog::Relation* readrel797 = db->getRelation("st_union_ans");
      head_index[0] = readrel797->getIndex(ord796, false);
      outer_rel = db->getRelation("st_join_ans");
      std::vector<u16> ord798({0, 1, 2, 3, 4});
      slog::Relation* readrel799 = db->getRelation("st_join");
      st_joinindex777 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({0, 1, 2, 3, 4});
      slog::Relation* readrel801 = db->getRelation("st_join");
      st_joindelta788 = readrel801->getIndex(ord800, true);
      std::vector<u16> ord802({0, 1, 2, 3, 4});
      slog::Relation* readrel803 = db->getRelation("pbranch");
      pbranchindex778 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({0, 1, 2, 3, 4});
      slog::Relation* readrel805 = db->getRelation("pbranch");
      pbranchindex779 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("st_union");
      st_unionindex780 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("st_msk");
      st_mskindex781 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel811 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index782 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel813 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0delta789 = readrel813->getIndex(ord812, true);
      std::vector<u16> ord814({1, 2, 3, 4, 0});
      slog::Relation* readrel815 = db->getRelation("pbranch");
      pbranchindex783 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({1, 2, 3, 4, 0});
      slog::Relation* readrel817 = db->getRelation("pbranch");
      pbranchdelta790 = readrel817->getIndex(ord816, true);
      std::vector<u16> ord818({1, 2, 3, 4, 0});
      slog::Relation* readrel819 = db->getRelation("pbranch");
      pbranchindex784 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 3, 4, 0});
      slog::Relation* readrel821 = db->getRelation("pbranch");
      pbranchdelta791 = readrel821->getIndex(ord820, true);
      std::vector<u16> ord822({0, 1, 2});
      slog::Relation* readrel823 = db->getRelation("st_union");
      st_unionindex785 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1, 2});
      slog::Relation* readrel825 = db->getRelation("st_union");
      st_uniondelta792 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("st_msk");
      st_mskindex786 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("st_msk");
      st_mskdelta793 = readrel829->getIndex(ord828, true);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("st_msk_ans");
      st_msk_ansindex787 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 1});
      slog::Relation* readrel833 = db->getRelation("st_msk_ans");
      st_msk_ansdelta794 = readrel833->getIndex(ord832, true);
  
    }
    ReadTask795(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c157 = _t[0];
        u64 v_c70 = _t[1];
        slog::join_probe_old<5,1>(st_joinindex777, st_joindelta788, std::array<u64,5>{v_c157, 0, 0, 0, 0}, [&](const std::array<u64,5>& m834) {
          u64 v_c13 = m834[1]; u64 v_c158 = m834[2]; u64 v_c21 = m834[3]; u64 v_c159 = m834[4];
          if (!slog::exists_probe<5,2>(pbranchindex778, std::array<u64,5>{v_c158, v_c13, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex779, std::array<u64,5>{v_c159, v_c21, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex780, std::array<u64,3>{v_c158, v_c159, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex781, std::array<u64,3>{v_c21, 0, 0})) return;
          slog::join_probe_old<11,4>($sup9688x110x0x0x0index782, $sup9688x110x0x0x0delta789, std::array<u64,11>{v_c13, v_c21, v_c158, v_c159, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m835) {
            u64 v_c160 = m835[4]; u64 v_c11 = m835[5]; u64 v_c12 = m835[6]; u64 v_c22 = m835[7]; u64 v_c14 = m835[8]; u64 v_c23 = m835[9]; u64 v_c24 = m835[10];
            u64 v_c161 = _prim_lt(db, v_c22, v_c12);
            if (v_c161 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
            if (!v_c161) return;
            slog::join_probe_old<5,5>(pbranchindex783, pbranchdelta790, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, v_c158}, [&](const std::array<u64,5>& m837) {
              slog::join_probe_old<5,5>(pbranchindex784, pbranchdelta791, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, v_c159}, [&](const std::array<u64,5>& m838) {
                slog::join_probe_old<3,3>(st_unionindex785, st_uniondelta792, std::array<u64,3>{v_c160, v_c158, v_c159}, [&](const std::array<u64,3>& m839) {
                  slog::join_probe_old<3,2>(st_mskindex786, st_mskdelta793, std::array<u64,3>{v_c21, v_c12, 0}, [&](const std::array<u64,3>& m840) {
                    u64 v_c162 = m840[2];
                    slog::join_probe_old<2,1>(st_msk_ansindex787, st_msk_ansdelta794, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m841) {
                      u64 v_c32 = m841[1];
                      if (v_c13 == v_c32) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c160, v_c70}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask795* _cont = new ReadTask795(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask795(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan st_msk __t3q0j248 q m) (body (exists $sup9688x103x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (2 0 1 3 4) 1 m) (exists pbranch (1 2 3 4 0) 1 q) (exists st_msk_ans (0 1) 1 __t3q0j248) (join $sup9688x103x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t3q0j248 m q p __t3N33245 l n r u v) (cmp lt n m) (join $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t3N33245 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_msk_ans (0 1) 2 __t3q0j248 p) (exists st_union (1 2 0) 1 l) (join pbranch (1 2 3 4 0) 4 p m l r __t2RvE244) (exists st_union (0 1 2) 2 __t3N33245 __t2RvE244) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8HsZ249) (join st_union (0 1 2) 3 __t3N33245 __t2RvE244 __t8HsZ249) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask860 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x0index842;  slog::Index** pbranchindex843;  slog::Index** pbranchindex844;  slog::Index** st_msk_ansindex845;  slog::Index** $sup9688x103x0x0x1index846;  slog::Index** $sup9688x103x0x0x0index847;  slog::Index** pbranchindex848;  slog::Index** st_msk_ansindex849;  slog::Index** st_unionindex850;  slog::Index** pbranchindex851;  slog::Index** st_unionindex852;  slog::Index** pbranchindex853;  slog::Index** st_unionindex854;  slog::Index** st_msk_ansindex855;  slog::Index** st_unionindex856;  slog::Index** st_union_ansindex857;  slog::Index** pbranchdelta858;  slog::Index** st_uniondelta859;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord861({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel862 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index842 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({2, 0, 1, 3, 4});
      slog::Relation* readrel864 = db->getRelation("pbranch");
      pbranchindex843 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 3, 4, 0});
      slog::Relation* readrel866 = db->getRelation("pbranch");
      pbranchindex844 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({0, 1});
      slog::Relation* readrel868 = db->getRelation("st_msk_ans");
      st_msk_ansindex845 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel870 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index846 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel872 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index847 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 3, 4, 0});
      slog::Relation* readrel874 = db->getRelation("pbranch");
      pbranchindex848 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("st_msk_ans");
      st_msk_ansindex849 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("st_union");
      st_unionindex850 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({1, 2, 3, 4, 0});
      slog::Relation* readrel880 = db->getRelation("pbranch");
      pbranchindex851 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({0, 1, 2});
      slog::Relation* readrel882 = db->getRelation("st_union");
      st_unionindex852 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 3, 4, 0});
      slog::Relation* readrel884 = db->getRelation("pbranch");
      pbranchindex853 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 3, 4, 0});
      slog::Relation* readrel886 = db->getRelation("pbranch");
      pbranchdelta858 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({0, 1, 2});
      slog::Relation* readrel888 = db->getRelation("st_union");
      st_unionindex854 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({0, 1});
      slog::Relation* readrel890 = db->getRelation("st_msk_ans");
      st_msk_ansindex855 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("st_union");
      st_unionindex856 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 2, 0});
      slog::Relation* readrel894 = db->getRelation("st_union");
      st_uniondelta859 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("st_union_ans");
      st_union_ansindex857 = readrel896->getIndex(ord895, false);
  
    }
    ReadTask860(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c164 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x103x0x0x0index842, std::array<u64,9>{v_c12, v_c21, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex843, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex844, std::array<u64,5>{v_c21, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex845, std::array<u64,2>{v_c164, 0})) return;
        slog::join_probe<10,3>($sup9688x103x0x0x1index846, std::array<u64,10>{v_c164, v_c12, v_c21, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m897) {
          u64 v_c13 = m897[3]; u64 v_c165 = m897[4]; u64 v_c11 = m897[5]; u64 v_c22 = m897[6]; u64 v_c14 = m897[7]; u64 v_c23 = m897[8]; u64 v_c24 = m897[9];
          u64 v_c166 = _prim_lt(db, v_c22, v_c12);
          if (v_c166 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
          if (!v_c166) return;
          slog::join_probe<9,9>($sup9688x103x0x0x0index847, std::array<u64,9>{v_c11, v_c12, v_c13, v_c14, v_c165, v_c22, v_c21, v_c23, v_c24}, [&](const std::array<u64,9>& m899) {
            if (!slog::exists_probe<5,4>(pbranchindex848, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex849, std::array<u64,2>{v_c164, v_c13})) return;
            if (!slog::exists_probe<3,1>(st_unionindex850, std::array<u64,3>{v_c11, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex851, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m900) {
              u64 v_c167 = m900[4];
              if (!slog::exists_probe<3,2>(st_unionindex852, std::array<u64,3>{v_c165, v_c167, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex853, pbranchdelta858, std::array<u64,5>{v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,5>& m901) {
                u64 v_c168 = m901[4];
                slog::join_probe<3,3>(st_unionindex854, std::array<u64,3>{v_c165, v_c167, v_c168}, [&](const std::array<u64,3>& m902) {
                  slog::join_probe<2,2>(st_msk_ansindex855, std::array<u64,2>{v_c164, v_c13}, [&](const std::array<u64,2>& m903) {
                    slog::join_probe_old<3,2>(st_unionindex856, st_uniondelta859, std::array<u64,3>{v_c11, v_c168, 0}, [&](const std::array<u64,3>& m904) {
                      u64 v_c169 = m904[2];
                      slog::join_probe<2,1>(st_union_ansindex857, std::array<u64,2>{v_c169, 0}, [&](const std::array<u64,2>& m905) {
                        u64 v_c32 = m905[1];
                        u64 v_c170 = _prim_band(db, v_c21, v_c12);
                        if (v_c170 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c171 = _prim_lt(db, v_c170, v_c163);
                        if (v_c171 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c171) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c165, v_c32, v_c12, v_c13, v_c14});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c32, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask860* _cont = new ReadTask860(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask860(db,b), false);
  // (crule (pre (let __tconst4S3D703 conste3776bfed7f405de8017ecfa)) (scan st_bld __t0t9x196 p m __t6DTO195 r) (body (join _enum (0 1) 2 __t6DTO195 __tconst4S3D703)) (head (emit st_bld_ans (0 1) __t0t9x196 r)) set.slog:78 #f)
  class ReadTask908 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex907;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_bld_ans");
      std::vector<u16> ord909({0, 1});
      slog::Relation* readrel910 = db->getRelation("st_bld_ans");
      head_index[0] = readrel910->getIndex(ord909, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord911({0, 1});
      slog::Relation* readrel912 = db->getRelation("_enum");
      _enumindex907 = readrel912->getIndex(ord911, false);
  
    }
    ReadTask908(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c172 = v_conste3776bfed7f405de8017ecfa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c173 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c174 = _t[3];
        u64 v_c14 = _t[4];
        slog::join_probe<2,2>(_enumindex907, std::array<u64,2>{v_c174, v_c172}, [&](const std::array<u64,2>& m913) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c173, v_c14}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:78", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask908* _cont = new ReadTask908(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask908(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan pbranch __t3QFk546 q n u v) (body (exists st_msk (1 2 0) 1 q) (exists st_diff (2 0 1) 1 __t3QFk546) (join $sup9688x139x0x0x0 (3 5 7 8 1 0 2 4 6) 4 n q u v l __d0 m p r) (exists st_msk_ans (1 0) 1 p) (exists st_diff (1 2 0) 2 l __t3QFk546) (join st_msk (1 2 0) 2 q m __t9Eou545) (join st_msk_ans (0 1) 2 __t9Eou545 p) (join-old st_diff (1 2 0) 2 (1 2 0) l __t3QFk546 __t9ide547) (join st_diff_ans (0 1) 1 __t9ide547 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask927 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex914;  slog::Index** st_diffindex915;  slog::Index** $sup9688x139x0x0x0index916;  slog::Index** st_msk_ansindex917;  slog::Index** st_diffindex918;  slog::Index** st_mskindex919;  slog::Index** st_msk_ansindex920;  slog::Index** st_diffindex921;  slog::Index** st_diff_ansindex922;  slog::Index** st_diffdelta923;
    u32 sid925;  u32 sid924;  u32 sid926;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("st_msk");
      st_mskindex914 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({2, 0, 1});
      slog::Relation* readrel931 = db->getRelation("st_diff");
      st_diffindex915 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({3, 5, 7, 8, 1, 0, 2, 4, 6});
      slog::Relation* readrel933 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index916 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 0});
      slog::Relation* readrel935 = db->getRelation("st_msk_ans");
      st_msk_ansindex917 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("st_diff");
      st_diffindex918 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 0});
      slog::Relation* readrel939 = db->getRelation("st_msk");
      st_mskindex919 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({0, 1});
      slog::Relation* readrel941 = db->getRelation("st_msk_ans");
      st_msk_ansindex920 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 2, 0});
      slog::Relation* readrel943 = db->getRelation("st_diff");
      st_diffindex921 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 2, 0});
      slog::Relation* readrel945 = db->getRelation("st_diff");
      st_diffdelta923 = readrel945->getIndex(ord944, true);
      std::vector<u16> ord946({0, 1});
      slog::Relation* readrel947 = db->getRelation("st_diff_ans");
      st_diff_ansindex922 = readrel947->getIndex(ord946, false);
      sid925 = db->getRelation("_enum")->getStructId();
      sid924 = db->getRelation("pbranch")->getStructId();
      sid926 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask927(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c123 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c124 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        if (!slog::exists_probe<3,1>(st_mskindex914, std::array<u64,3>{v_c21, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex915, std::array<u64,3>{v_c126, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x139x0x0x0index916, std::array<u64,9>{v_c22, v_c21, v_c23, v_c24, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m948) {
          u64 v_c11 = m948[4]; u64 v_c9 = m948[5]; u64 v_c12 = m948[6]; u64 v_c13 = m948[7]; u64 v_c14 = m948[8];
          if (!slog::exists_probe<2,1>(st_msk_ansindex917, std::array<u64,2>{v_c13, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex918, std::array<u64,3>{v_c11, v_c126, 0})) return;
          slog::join_probe<3,2>(st_mskindex919, std::array<u64,3>{v_c21, v_c12, 0}, [&](const std::array<u64,3>& m949) {
            u64 v_c127 = m949[2];
            slog::join_probe<2,2>(st_msk_ansindex920, std::array<u64,2>{v_c127, v_c13}, [&](const std::array<u64,2>& m950) {
              slog::join_probe_old<3,2>(st_diffindex921, st_diffdelta923, std::array<u64,3>{v_c11, v_c126, 0}, [&](const std::array<u64,3>& m951) {
                u64 v_c125 = m951[2];
                slog::join_probe<2,1>(st_diff_ansindex922, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m952) {
                  u64 v_c32 = m952[1];
                  ++_fires;
                  if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid924 || decode_struct_id(v_c14) == sid925 || decode_struct_id(v_c14) == sid926))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c122, v_c123, v_c124, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c12, v_c32, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask927* _cont = new ReadTask927(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask927(db,b), false);
  // (crule (pre (let _00024sqc374s650 const6b86b273ff34fce19d6b804e) (let _00024sqc70tB651 const5feceb66ffc86f38d952786c) (let _00024sqc9HvG652 const6b86b273ff34fce19d6b804e) (let _00024sqc2OSe653 const5feceb66ffc86f38d952786c) (let _00024sqo65nP658 const5feceb66ffc86f38d952786c)) (scan st_ins __t8MgF74 __v0 x) (body (exists $sup9688x168x0x0x0 (2 3 0 1) 1 x) (exists st_fromlist_ans (1 0) 1 __v0) (exists st_ins_ans (0 1) 1 __t8MgF74) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo65nP658 x _00024seq0) (letp _00024sql5p7m648 (aslst _00024seq0)) (let _00024sqn1lS2649 (llen _00024sql5p7m648)) (cmp ge _00024sqn1lS2649 _00024sqc374s650) (let _00024sqp836n654 (_0002d _00024sqn1lS2649 _00024sqc2OSe653)) (let xs (lslice _00024sql5p7m648 _00024sqc9HvG652 _00024sqp836n654)) (exists st_fromlist (1 0) 1 _00024seq0) (exists st_fromlist (1 0) 1 xs) (join $sup9688x168x0x0x0 (2 3 0 1) 3 x xs _00024seq0 __t9UzC72) (join st_fromlist (0 1) 2 __t9UzC72 _00024seq0) (join st_fromlist_ans (1 0) 1 __v0 __t6xe073) (join st_fromlist (0 1) 2 __t6xe073 xs) (join st_ins_ans (0 1) 1 __t8MgF74 __v1) (letp chk7Lfi1285 (lref _00024sql5p7m648 _00024sqc70tB651)) (eq x chk7Lfi1285)) (head (emit st_fromlist_ans (0 1) __t9UzC72 __v1)) set.slog:169 #f)
  class ReadTask965 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x168x0x0x0index953;  slog::Index** st_fromlist_ansindex954;  slog::Index** st_ins_ansindex955;  slog::Index** $seq_atindex956;  slog::Index** st_fromlistindex957;  slog::Index** st_fromlistindex958;  slog::Index** $sup9688x168x0x0x0index959;  slog::Index** st_fromlistindex960;  slog::Index** st_fromlist_ansindex961;  slog::Index** st_fromlistindex962;  slog::Index** st_ins_ansindex963;  slog::Index** $seq_atdelta964;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord966({0, 1});
      slog::Relation* readrel967 = db->getRelation("st_fromlist_ans");
      head_index[0] = readrel967->getIndex(ord966, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord968({2, 3, 0, 1});
      slog::Relation* readrel969 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index953 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 0});
      slog::Relation* readrel971 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex954 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1});
      slog::Relation* readrel973 = db->getRelation("st_ins_ans");
      st_ins_ansindex955 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 0, 2});
      slog::Relation* readrel975 = db->getRelation("$seq_at");
      $seq_atindex956 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 0, 2});
      slog::Relation* readrel977 = db->getRelation("$seq_at");
      $seq_atdelta964 = readrel977->getIndex(ord976, true);
      std::vector<u16> ord978({1, 0});
      slog::Relation* readrel979 = db->getRelation("st_fromlist");
      st_fromlistindex957 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({1, 0});
      slog::Relation* readrel981 = db->getRelation("st_fromlist");
      st_fromlistindex958 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({2, 3, 0, 1});
      slog::Relation* readrel983 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index959 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({0, 1});
      slog::Relation* readrel985 = db->getRelation("st_fromlist");
      st_fromlistindex960 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({1, 0});
      slog::Relation* readrel987 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex961 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("st_fromlist");
      st_fromlistindex962 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 1});
      slog::Relation* readrel991 = db->getRelation("st_ins_ans");
      st_ins_ansindex963 = readrel991->getIndex(ord990, false);
  
    }
    ReadTask965(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c175 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
      u64 v_c179 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c180 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c181 = _t[2];
        if (!slog::exists_probe<4,1>($sup9688x168x0x0x0index953, std::array<u64,4>{v_c181, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_fromlist_ansindex954, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex955, std::array<u64,2>{v_c180, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex956, $seq_atdelta964, std::array<u64,3>{v_c179, v_c181, 0}, [&](const std::array<u64,3>& m992) {
          u64 v_c182 = m992[2];
          bool ok993 = true;
          u64 v_c183 = _prim_aslst(db, v_c182, &ok993);
          if (!ok993) return;
          u64 v_c184 = _prim_llen(db, v_c183);
          if (v_c184 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
          u64 v_c185 = _prim_ge(db, v_c184, v_c175);
          if (v_c185 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
          if (!v_c185) return;
          u64 v_c186 = _prim__0002d(db, v_c184, v_c178);
          if (v_c186 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
          u64 v_c187 = _prim_lslice(db, v_c183, v_c177, v_c186);
          if (v_c187 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
          if (!slog::exists_probe<2,1>(st_fromlistindex957, std::array<u64,2>{v_c182, 0})) return;
          if (!slog::exists_probe<2,1>(st_fromlistindex958, std::array<u64,2>{v_c187, 0})) return;
          slog::join_probe<4,3>($sup9688x168x0x0x0index959, std::array<u64,4>{v_c181, v_c187, v_c182, 0}, [&](const std::array<u64,4>& m995) {
            u64 v_c188 = m995[3];
            slog::join_probe<2,2>(st_fromlistindex960, std::array<u64,2>{v_c188, v_c182}, [&](const std::array<u64,2>& m996) {
              slog::join_probe<2,1>(st_fromlist_ansindex961, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m997) {
                u64 v_c189 = m997[1];
                slog::join_probe<2,2>(st_fromlistindex962, std::array<u64,2>{v_c189, v_c187}, [&](const std::array<u64,2>& m998) {
                  slog::join_probe<2,1>(st_ins_ansindex963, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m999) {
                    u64 v_c93 = m999[1];
                    bool ok1000 = true;
                    u64 v_c190 = _prim_lref(db, v_c183, v_c176, &ok1000);
                    if (!ok1000) return;
                    if (v_c181 != v_c190) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c188, v_c93}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:169", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask965* _cont = new ReadTask965(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask965(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan st_msk __t4A7W507 k m) (body (exists $sup9688x72x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_mem0 (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t4A7W507 p) (exists pbranch (1 2 3 4 0) 2 p m) (join $sup9688x72x0x0x0 (1 3 4 0 2 5) 3 k m p __t6Rw6503 l r) (exists st_mem0 (2 0 1) 2 k __t6Rw6503) (exists st_mem0 (1 2 0) 2 r k) (join pbranch (1 2 3 4 0) 4 p m l r __t1XtO502) (join st_mem0 (0 1 2) 3 __t6Rw6503 __t1XtO502 k) (join st_mem0 (1 2 0) 2 r k __t9V8P506) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask1013 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x72x0x0x0index1001;  slog::Index** pbranchindex1002;  slog::Index** st_mem0index1003;  slog::Index** st_msk_ansindex1004;  slog::Index** pbranchindex1005;  slog::Index** $sup9688x72x0x0x0index1006;  slog::Index** st_mem0index1007;  slog::Index** st_mem0index1008;  slog::Index** pbranchindex1009;  slog::Index** st_mem0index1010;  slog::Index** st_mem0index1011;  slog::Index** st_mem0_ansindex1012;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1014({0, 1});
      slog::Relation* readrel1015 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1015->getIndex(ord1014, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1016({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1017 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index1001 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({2, 0, 1, 3, 4});
      slog::Relation* readrel1019 = db->getRelation("pbranch");
      pbranchindex1002 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({2, 0, 1});
      slog::Relation* readrel1021 = db->getRelation("st_mem0");
      st_mem0index1003 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({0, 1});
      slog::Relation* readrel1023 = db->getRelation("st_msk_ans");
      st_msk_ansindex1004 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 2, 3, 4, 0});
      slog::Relation* readrel1025 = db->getRelation("pbranch");
      pbranchindex1005 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1027 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index1006 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({2, 0, 1});
      slog::Relation* readrel1029 = db->getRelation("st_mem0");
      st_mem0index1007 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 0});
      slog::Relation* readrel1031 = db->getRelation("st_mem0");
      st_mem0index1008 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 2, 3, 4, 0});
      slog::Relation* readrel1033 = db->getRelation("pbranch");
      pbranchindex1009 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({0, 1, 2});
      slog::Relation* readrel1035 = db->getRelation("st_mem0");
      st_mem0index1010 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({1, 2, 0});
      slog::Relation* readrel1037 = db->getRelation("st_mem0");
      st_mem0index1011 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({0, 1});
      slog::Relation* readrel1039 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1012 = readrel1039->getIndex(ord1038, false);
  
    }
    ReadTask1013(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c192 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x72x0x0x0index1001, std::array<u64,6>{v_c10, v_c12, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1002, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index1003, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1004, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m1040) {
          u64 v_c13 = m1040[1];
          if (!slog::exists_probe<5,2>(pbranchindex1005, std::array<u64,5>{v_c13, v_c12, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x72x0x0x0index1006, std::array<u64,6>{v_c10, v_c12, v_c13, 0, 0, 0}, [&](const std::array<u64,6>& m1041) {
            u64 v_c193 = m1041[3]; u64 v_c11 = m1041[4]; u64 v_c14 = m1041[5];
            if (!slog::exists_probe<3,2>(st_mem0index1007, std::array<u64,3>{v_c10, v_c193, 0})) return;
            if (!slog::exists_probe<3,2>(st_mem0index1008, std::array<u64,3>{v_c14, v_c10, 0})) return;
            slog::join_probe<5,4>(pbranchindex1009, std::array<u64,5>{v_c13, v_c12, v_c11, v_c14, 0}, [&](const std::array<u64,5>& m1042) {
              u64 v_c194 = m1042[4];
              slog::join_probe<3,3>(st_mem0index1010, std::array<u64,3>{v_c193, v_c194, v_c10}, [&](const std::array<u64,3>& m1043) {
                slog::join_probe<3,2>(st_mem0index1011, std::array<u64,3>{v_c14, v_c10, 0}, [&](const std::array<u64,3>& m1044) {
                  u64 v_c195 = m1044[2];
                  slog::join_probe<2,1>(st_mem0_ansindex1012, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m1045) {
                    u64 v_c196 = m1045[1];
                    u64 v_c197 = _prim_band(db, v_c10, v_c12);
                    if (v_c197 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c198 = _prim_gt(db, v_c197, v_c191);
                    if (v_c198 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c198) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c193, v_c196}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1013* _cont = new ReadTask1013(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1013(db,b), false);
  // (crule (pre) (scan st_msk_ans __t88lr525 q) (body (exists $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t88lr525 p n) (join $sup9688x117x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t88lr525 l m n p q r u)) set.slog:118 #f)
  class ReadTask1051 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x0index1047;  slog::Index** st_mskindex1048;  slog::Index** $sup9688x117x0x0x0index1049;  slog::Index** st_mskdelta1050;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord1052({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1053 = db->getRelation("$sup9688x117x0x0x1");
      head_index[0] = readrel1053->getIndex(ord1052, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1054({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1055 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index1047 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({0, 1, 2});
      slog::Relation* readrel1057 = db->getRelation("st_msk");
      st_mskindex1048 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({0, 1, 2});
      slog::Relation* readrel1059 = db->getRelation("st_msk");
      st_mskdelta1050 = readrel1059->getIndex(ord1058, true);
      std::vector<u16> ord1060({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1061 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index1049 = readrel1061->getIndex(ord1060, false);
  
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
        u64 v_c199 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x117x0x0x0index1047, std::array<u64,9>{v_c21, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1048, st_mskdelta1050, std::array<u64,3>{v_c199, 0, 0}, [&](const std::array<u64,3>& m1062) {
          u64 v_c13 = m1062[1]; u64 v_c22 = m1062[2];
          slog::join_probe<9,3>($sup9688x117x0x0x0index1049, std::array<u64,9>{v_c22, v_c13, v_c21, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1063) {
            u64 v_c9 = m1063[3]; u64 v_c11 = m1063[4]; u64 v_c12 = m1063[5]; u64 v_c14 = m1063[6]; u64 v_c23 = m1063[7]; u64 v_c24 = m1063[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c9, v_c24, v_c199, v_c11, v_c12, v_c22, v_c13, v_c21, v_c14, v_c23}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre (let __trid8Zm7922 const22475024b8f1c7d620b83a7c) (let __trel2EjC923 const94d9c4e2675ef4bd8443d499) (let __tcol626k924 const5feceb66ffc86f38d952786c) (let __trel03Ey925 const66633592860a63ea6408b433) (let __tcol2wFa926 const5feceb66ffc86f38d952786c) (let __trel5viR927 const66633592860a63ea6408b433) (let __tcol3uDs928 const6b86b273ff34fce19d6b804e) (let __trel1JCH929 const66633592860a63ea6408b433) (let __tcol0pIe930 constd4735e3a265e16eee03f5971) (let __trel27kA931 const66633592860a63ea6408b433) (let __tcol2T41932 const4e07408562bedb8b60ce05c1)) (scan $sup9688x106x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8Zm7922 __trel2EjC923 __tcol626k924 (1 2 3 4 0)) (tycheck q (accept int) __trid8Zm7922 __trel03Ey925 __tcol2wFa926 (1 2 3 4 0)) (tycheck n (accept int) __trid8Zm7922 __trel5viR927 __tcol3uDs928 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8Zm7922 __trel1JCH929 __tcol0pIe930 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid8Zm7922 __trel27kA931 __tcol2T41932 (1 2 3 4 0)) (emit-temp temp18xQ1344 n q r u v) (mkstruct pbranch (1 2 3 4 0) __t1FMB110 q n u v)) set.slog:107 #f)
  class ReadTask1067 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1065;  u32 sid1064;  u32 sid1066;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp18xQ1344");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x106x0x0x1");
      sid1065 = db->getRelation("_enum")->getStructId();
      sid1064 = db->getRelation("pbranch")->getStructId();
      sid1066 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1067(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c200 = v_const22475024b8f1c7d620b83a7c;
      u64 v_c201 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c202 = v_const5feceb66ffc86f38d952786c;
      u64 v_c203 = v_const66633592860a63ea6408b433;
      u64 v_c204 = v_const5feceb66ffc86f38d952786c;
      u64 v_c205 = v_const66633592860a63ea6408b433;
      u64 v_c206 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c207 = v_const66633592860a63ea6408b433;
      u64 v_c208 = v_constd4735e3a265e16eee03f5971;
      u64 v_c209 = v_const66633592860a63ea6408b433;
      u64 v_c210 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c107 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c22 = _t[4];
        u64 v_c13 = _t[5];
        u64 v_c21 = _t[6];
        u64 v_c14 = _t[7];
        u64 v_c23 = _t[8];
        u64 v_c24 = _t[9];
        ++_fires;
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid1064 || decode_struct_id(v_c14) == sid1065 || decode_struct_id(v_c14) == sid1066))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c200, v_c201, v_c202, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c21)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c200, v_c203, v_c204, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c200, v_c205, v_c206, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid1064 || decode_struct_id(v_c23) == sid1065 || decode_struct_id(v_c23) == sid1066))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c200, v_c207, v_c208, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid1064 || decode_struct_id(v_c24) == sid1065 || decode_struct_id(v_c24) == sid1066))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c200, v_c209, v_c210, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c22, v_c21, v_c14, v_c23, v_c24});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c21, v_c22, v_c23, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:$sup9688x106x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1067* _cont = new ReadTask1067(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1067(db,b), false);
  // (crule (pre) (scan $sup9688x103x0x0x0 __d0 l m n p q r u v) (body (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8BWG393) (join-old st_msk_ans (0 1) 2 (0 1) __t8BWG393 p)) (head (emit $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t8BWG393 m n p q r u v)) set.slog:104 #f)
  class ReadTask1073 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex1068;  slog::Index** st_mskindex1069;  slog::Index** st_msk_ansindex1070;  slog::Index** st_mskdelta1071;  slog::Index** st_msk_ansdelta1072;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord1074({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel1075 = db->getRelation("$sup9688x103x0x0x1");
      head_index[0] = readrel1075->getIndex(ord1074, false);
      outer_rel = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord1076({1, 0});
      slog::Relation* readrel1077 = db->getRelation("st_msk_ans");
      st_msk_ansindex1068 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 2, 0});
      slog::Relation* readrel1079 = db->getRelation("st_msk");
      st_mskindex1069 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 2, 0});
      slog::Relation* readrel1081 = db->getRelation("st_msk");
      st_mskdelta1071 = readrel1081->getIndex(ord1080, true);
      std::vector<u16> ord1082({0, 1});
      slog::Relation* readrel1083 = db->getRelation("st_msk_ans");
      st_msk_ansindex1070 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({0, 1});
      slog::Relation* readrel1085 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1072 = readrel1085->getIndex(ord1084, true);
  
    }
    ReadTask1073(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c21 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c23 = _t[7];
        u64 v_c24 = _t[8];
        if (!slog::exists_probe<2,1>(st_msk_ansindex1068, std::array<u64,2>{v_c13, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex1069, st_mskdelta1071, std::array<u64,3>{v_c21, v_c12, 0}, [&](const std::array<u64,3>& m1086) {
          u64 v_c211 = m1086[2];
          slog::join_probe_old<2,2>(st_msk_ansindex1070, st_msk_ansdelta1072, std::array<u64,2>{v_c211, v_c13}, [&](const std::array<u64,2>& m1087) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c9, v_c11, v_c211, v_c12, v_c22, v_c13, v_c21, v_c14, v_c23, v_c24}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:$sup9688x103x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1073* _cont = new ReadTask1073(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1073(db,b), false);
  // (crule (pre (let __tconst3inB738 conste3776bfed7f405de8017ecfa) (let __tconst4Wut540 const6b86b273ff34fce19d6b804e) (let __tconst5bud543 const2c624232cdd221771294dfbb) (let __tconst4ddf539 constd4735e3a265e16eee03f5971)) (scan st_ins_ans __t7kvj542 __v0) (body (exists _enum (1 0) 1 __tconst3inB738) (exists st_ins (1 2 0) 2 __v0 __tconst5bud543) (join-old st_ins (0 2 1) 2 (0 2 1) __t7kvj542 __tconst4Wut540 __t86kg541) (join _enum (0 1) 2 __t86kg541 __tconst3inB738) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst5bud543 __t19Ry544) (join-old st_ins_ans (0 1) 1 (0 1) __t19Ry544 __v1)) (head (mkstruct st_ins (1 2 0) __8Yai739 __v1 __tconst4ddf539)) st_basic.slog:15 #f)
  class ReadTask1097 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1088;  slog::Index** st_insindex1089;  slog::Index** st_insindex1090;  slog::Index** _enumindex1091;  slog::Index** st_insindex1092;  slog::Index** st_ins_ansindex1093;  slog::Index** st_insdelta1094;  slog::Index** st_insdelta1095;  slog::Index** st_ins_ansdelta1096;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1098({1, 0});
      slog::Relation* readrel1099 = db->getRelation("_enum");
      _enumindex1088 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 0});
      slog::Relation* readrel1101 = db->getRelation("st_ins");
      st_insindex1089 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({0, 2, 1});
      slog::Relation* readrel1103 = db->getRelation("st_ins");
      st_insindex1090 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 2, 1});
      slog::Relation* readrel1105 = db->getRelation("st_ins");
      st_insdelta1094 = readrel1105->getIndex(ord1104, true);
      std::vector<u16> ord1106({0, 1});
      slog::Relation* readrel1107 = db->getRelation("_enum");
      _enumindex1091 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 2, 0});
      slog::Relation* readrel1109 = db->getRelation("st_ins");
      st_insindex1092 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 2, 0});
      slog::Relation* readrel1111 = db->getRelation("st_ins");
      st_insdelta1095 = readrel1111->getIndex(ord1110, true);
      std::vector<u16> ord1112({0, 1});
      slog::Relation* readrel1113 = db->getRelation("st_ins_ans");
      st_ins_ansindex1093 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({0, 1});
      slog::Relation* readrel1115 = db->getRelation("st_ins_ans");
      st_ins_ansdelta1096 = readrel1115->getIndex(ord1114, true);
  
    }
    ReadTask1097(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c212 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const2c624232cdd221771294dfbb;
      u64 v_c215 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c216 = _t[0];
        u64 v_c32 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex1088, std::array<u64,2>{v_c212, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex1089, std::array<u64,3>{v_c32, v_c214, 0})) return;
        slog::join_probe_old<3,2>(st_insindex1090, st_insdelta1094, std::array<u64,3>{v_c216, v_c213, 0}, [&](const std::array<u64,3>& m1116) {
          u64 v_c217 = m1116[2];
          slog::join_probe<2,2>(_enumindex1091, std::array<u64,2>{v_c217, v_c212}, [&](const std::array<u64,2>& m1117) {
            slog::join_probe_old<3,2>(st_insindex1092, st_insdelta1095, std::array<u64,3>{v_c32, v_c214, 0}, [&](const std::array<u64,3>& m1118) {
              u64 v_c218 = m1118[2];
              slog::join_probe_old<2,1>(st_ins_ansindex1093, st_ins_ansdelta1096, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1119) {
                u64 v_c93 = m1119[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c93, v_c215}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask1097* _cont = new ReadTask1097(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1097(db,b), false);
}

