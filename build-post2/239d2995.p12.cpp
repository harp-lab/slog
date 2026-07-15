
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5f7e60cb3d02e4170101c2bc;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const5fedc35d1451fa93f8022abf;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_constbb851acf11177e0e526ed8e5;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constfee494ff4827aeb0635bb714;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c738f16f39e0507e0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst0V5A29 const6b86b273ff34fce19d6b804e)) (scan mbranch __t0FDo26 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t0FDo26 __t45uF28 __t8PYQ27) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t8PYQ27 p m l r) (cmp lt n m) (let __t1fk230 (band q m)) (cmp lt __t1fk230 __tconst0V5A29)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t45uF28 l m n p q r u v)) map.slog:96 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex0;  slog::Index** mbranchindex1;  slog::Index** mp_uniondelta2;  slog::Index** mbranchdelta3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord5({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel6 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord7({2, 0, 1});
      slog::Relation* readrel8 = db->getRelation("mp_union");
      mp_unionindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({2, 0, 1});
      slog::Relation* readrel10 = db->getRelation("mp_union");
      mp_uniondelta2 = readrel10->getIndex(ord9, true);
      std::vector<u16> ord11({0, 1, 2, 3, 4});
      slog::Relation* readrel12 = db->getRelation("mbranch");
      mbranchindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({0, 1, 2, 3, 4});
      slog::Relation* readrel14 = db->getRelation("mbranch");
      mbranchdelta3 = readrel14->getIndex(ord13, true);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex0, mp_uniondelta2, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m15) {
          u64 v_c6 = m15[1]; u64 v_c7 = m15[2];
          slog::join_probe_old<5,1>(mbranchindex1, mbranchdelta3, std::array<u64,5>{v_c7, 0, 0, 0, 0}, [&](const std::array<u64,5>& m16) {
            u64 v_c8 = m16[1]; u64 v_c9 = m16[2]; u64 v_c10 = m16[3]; u64 v_c11 = m16[4];
            u64 v_c12 = _prim_lt(db, v_c3, v_c9);
            if (v_c12 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c12) return;
            u64 v_c13 = _prim_band(db, v_c2, v_c9);
            if (v_c13 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c14 = _prim_lt(db, v_c13, v_c0);
            if (v_c14 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c14) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c6, v_c10, v_c9, v_c3, v_c8, v_c2, v_c11, v_c4, v_c5}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __trid4uau561 const5fedc35d1451fa93f8022abf) (let __trel0Fqo562 const3a655602588fe6d8c59d4a5a) (let __tcol5oOO563 const5feceb66ffc86f38d952786c) (let __trel1W1w564 const3a655602588fe6d8c59d4a5a) (let __tcol6T3O565 const6b86b273ff34fce19d6b804e)) (scan $sup5638x67x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4uau561 __trel0Fqo562 __tcol5oOO563 (1 2 3 4 0)) (tycheck k (accept int) __trid4uau561 __trel1W1w564 __tcol6T3O565 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __52qd560 t k)) map.slog:68 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid20;  u32 sid19;  u32 sid21;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x67x0x0x0");
      sid20 = db->getRelation("_enum")->getStructId();
      sid19 = db->getRelation("mbranch")->getStructId();
      sid21 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const5fedc35d1451fa93f8022abf;
      u64 v_c16 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
      u64 v_c18 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c19 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c5 = _t[3];
        ++_fires;
        if (!((is_struct(v_c22) && (decode_struct_id(v_c22) == sid19 || decode_struct_id(v_c22) == sid20 || decode_struct_id(v_c22) == sid21))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c15, v_c16, v_c17, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c21)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c18, v_c19, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c22, v_c21}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:$sup5638x67x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t8mLF130 __v1) (body (join mp_hsb_ans (0 1) 1 __t8mLF130 __v3) (join-old mp_hsb (0 1) 1 (0 1) __t8mLF130 __t8nJr131) (join-old $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk1rUk1018 (bxor p0 p1)) (eq __t8nJr131 chk1rUk1018)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t8mLF130 __t8mLF130 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex23;  slog::Index** mp_hsbindex24;  slog::Index** $sup5638x29x0x0x1index25;  slog::Index** mp_hsbdelta26;  slog::Index** $sup5638x29x0x0x1delta27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord29({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel30 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex23 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("mp_hsb");
      mp_hsbindex24 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("mp_hsb");
      mp_hsbdelta26 = readrel36->getIndex(ord35, true);
      std::vector<u16> ord37({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel38 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index25 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel40 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta27 = readrel40->getIndex(ord39, true);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex23, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m41) {
          u64 v_c25 = m41[1];
          slog::join_probe_old<2,1>(mp_hsbindex24, mp_hsbdelta26, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m42) {
            u64 v_c26 = m42[1];
            slog::join_all_old<7>($sup5638x29x0x0x1index25, $sup5638x29x0x0x1delta27, [&](const std::array<u64,7>& m43) {
              u64 v_c27 = m43[0]; u64 v_c28 = m43[1]; u64 v_c20 = m43[2]; u64 v_c29 = m43[3]; u64 v_c30 = m43[4]; u64 v_c31 = m43[5]; u64 v_c32 = m43[6];
              u64 v_c33 = _prim_bxor(db, v_c29, v_c30);
              if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c26 != v_c33) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c27, v_c28, v_c25, v_c24, v_c20, v_c23, v_c23, v_c29, v_c30, v_c31, v_c32}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre (let __tconst6ZYU658 constd01925b37634a1a9d24159d8) (let __tconst66qs209 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t2lFA211 __t3lDC210 k) (body (join _enum (0 1) 2 __t3lDC210 __tconst6ZYU658)) (head (emit mp_has0_ans (0 1) __t2lFA211 __tconst66qs209)) map.slog:57 #f)
  class ReadTask45 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex44;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel47->getIndex(ord46, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("_enum");
      _enumindex44 = readrel49->getIndex(ord48, false);
  
    }
    ReadTask45(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_constd01925b37634a1a9d24159d8;
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
        u64 v_c21 = _t[2];
        slog::join_probe<2,2>(_enumindex44, std::array<u64,2>{v_c37, v_c34}, [&](const std::array<u64,2>& m50) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c35}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:57", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask45* _cont = new ReadTask45(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask45(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mp_union __t2wnB100 r __t1Mtu99) (body (exists mp_union (2 0 1) 1 __t1Mtu99) (exists mbranch (4 0 1 2 3) 1 r) (exists $sup5638x98x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (join mp_union (2 0 1) 1 __t1Mtu99 __t2uCs95 __t2SOF94) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t2uCs95 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t2uCs95 r) (join mbranch (4 0 1 2 3) 2 r __t2SOF94 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t2uCs95) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t2uCs95 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t1Mtu99) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t2uCs95 n q u v __t9ory98) (join mbranch (1 2 3 4 0) 5 q n u v __t1Mtu99) (join mp_msk (1 2 0) 3 q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex51;  slog::Index** mbranchindex52;  slog::Index** $sup5638x98x0x0x0index53;  slog::Index** $sup5638x98x0x0x1index54;  slog::Index** mp_union_ansindex55;  slog::Index** mp_unionindex56;  slog::Index** $sup5638x98x0x0x0index57;  slog::Index** $sup5638x98x0x0x1index58;  slog::Index** mbranchindex59;  slog::Index** $sup5638x98x0x0x1index60;  slog::Index** mp_mskindex61;  slog::Index** mp_msk_ansindex62;  slog::Index** $sup5638x98x0x0x0index63;  slog::Index** mbranchindex64;  slog::Index** mp_mskindex65;  slog::Index** $sup5638x98x0x0x1index66;  slog::Index** mbranchindex67;  slog::Index** mp_mskindex68;  slog::Index** mp_msk_ansindex69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord71({2, 0, 1});
      slog::Relation* readrel72 = db->getRelation("mp_union");
      mp_unionindex51 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({4, 0, 1, 2, 3});
      slog::Relation* readrel74 = db->getRelation("mbranch");
      mbranchindex52 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel76 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index53 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel78 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index54 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("mp_union_ans");
      mp_union_ansindex55 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({2, 0, 1});
      slog::Relation* readrel82 = db->getRelation("mp_union");
      mp_unionindex56 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel84 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index57 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel86 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index58 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({4, 0, 1, 2, 3});
      slog::Relation* readrel88 = db->getRelation("mbranch");
      mbranchindex59 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel90 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index60 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({2, 0, 1});
      slog::Relation* readrel92 = db->getRelation("mp_msk");
      mp_mskindex61 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex62 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel96 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index63 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 2, 3, 4, 0});
      slog::Relation* readrel98 = db->getRelation("mbranch");
      mbranchindex64 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("mp_msk");
      mp_mskindex65 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel102 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index66 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 3, 4, 0});
      slog::Relation* readrel104 = db->getRelation("mbranch");
      mbranchindex67 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("mp_msk");
      mp_mskindex68 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex69 = readrel108->getIndex(ord107, false);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c40 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex51, std::array<u64,3>{v_c40, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex52, std::array<u64,5>{v_c11, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index53, std::array<u64,9>{v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index54, std::array<u64,10>{v_c11, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex55, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m109) {
          u64 v_c28 = m109[1];
          slog::join_probe<3,1>(mp_unionindex56, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m110) {
            u64 v_c41 = m110[1]; u64 v_c42 = m110[2];
            if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index57, std::array<u64,9>{v_c41, v_c11, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index58, std::array<u64,10>{v_c41, v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex59, std::array<u64,5>{v_c11, v_c42, 0, 0, 0}, [&](const std::array<u64,5>& m111) {
              u64 v_c8 = m111[2]; u64 v_c9 = m111[3]; u64 v_c10 = m111[4];
              if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index60, std::array<u64,10>{v_c11, v_c10, v_c9, v_c8, v_c41, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex61, std::array<u64,3>{v_c9, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex62, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe<9,5>($sup5638x98x0x0x0index63, std::array<u64,9>{v_c8, v_c10, v_c9, v_c11, v_c41, 0, 0, 0, 0}, [&](const std::array<u64,9>& m112) {
                u64 v_c3 = m112[5]; u64 v_c2 = m112[6]; u64 v_c4 = m112[7]; u64 v_c5 = m112[8];
                u64 v_c43 = _prim_lt(db, v_c3, v_c9);
                if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                if (!v_c43) return;
                if (!slog::exists_probe<5,5>(mbranchindex64, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c40})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex65, std::array<u64,3>{v_c2, v_c9, 0})) return;
                slog::join_probe<10,9>($sup5638x98x0x0x1index66, std::array<u64,10>{v_c11, v_c10, v_c9, v_c8, v_c41, v_c3, v_c2, v_c4, v_c5, 0}, [&](const std::array<u64,10>& m114) {
                  u64 v_c44 = m114[9];
                  slog::join_probe<5,5>(mbranchindex67, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c40}, [&](const std::array<u64,5>& m115) {
                    slog::join_probe<3,3>(mp_mskindex68, std::array<u64,3>{v_c2, v_c9, v_c44}, [&](const std::array<u64,3>& m116) {
                      slog::join_probe<2,2>(mp_msk_ansindex69, std::array<u64,2>{v_c44, v_c8}, [&](const std::array<u64,2>& m117) {
                        u64 v_c45 = _prim_band(db, v_c2, v_c9);
                        if (v_c45 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c46 = _prim_gt(db, v_c45, v_c38);
                        if (v_c46 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c46) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c41, v_c28, v_c10, v_c9, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c10, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
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
  // (crule (pre) (scan temp03QX1021 __t8NPe120) (body) (head (mkstruct mp_hsb (1 0) __049z712 __t8NPe120)) map.slog:26 #f)
  class ReadTask119 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb");
      outer_rel = db->getRelation("temp03QX1021");
  
    }
    ReadTask119(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp03QX1021", _fires);
  
      if (!_done)
      {
        ReadTask119* _cont = new ReadTask119(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask119(db,b), false);
  // (crule (pre (let __trid25V6630 constbb851acf11177e0e526ed8e5) (let __trel2bNE631 constdd7bbf31ce5f578b9805e840) (let __tcol8NA2632 const5feceb66ffc86f38d952786c) (let __trel871y633 constdd7bbf31ce5f578b9805e840) (let __tcol4msF634 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid25V6630 __trel2bNE631 __tcol8NA2632 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid25V6630 __trel871y633 __tcol4msF634 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __2Sx1629 p0 __v1)) map.slog:26 #f)
  class ReadTask120 : public slog::Task
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
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x25x0x0x2");
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_constbb851acf11177e0e526ed8e5;
      u64 v_c49 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c20 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c53 = _t[2];
        u64 v_c54 = _t[3];
        u64 v_c28 = _t[4];
        u64 v_c24 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c29 = _t[7];
        u64 v_c30 = _t[8];
        u64 v_c31 = _t[9];
        u64 v_c32 = _t[10];
        ++_fires;
        if (!(is_int(v_c29)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c48, v_c49, v_c50, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c24)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c51, v_c52, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c29, v_c24}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x2", _fires);
  
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
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t1lh0397 __v0) (body (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t1lh0397 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t1lh0397 __v0) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v3) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t1lh0397 __v0 __v3) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v1) (exists mp_msk (2 0 1) 1 __v1) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t1lh0397 __v0 __v3 __v1 __t4lFL393 dup0XDZ1075 dup8FhK1076 p0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join mp_msk_ans (0 1) 1 __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask138 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex121;  slog::Index** $sup5638x29x0x0x2index122;  slog::Index** $sup5638x29x0x0x1index123;  slog::Index** mp_hsb_ansindex124;  slog::Index** $sup5638x29x0x0x2index125;  slog::Index** mp_hsb_ansindex126;  slog::Index** mp_mskindex127;  slog::Index** $sup5638x29x0x0x2index128;  slog::Index** $sup5638x29x0x0x1index129;  slog::Index** $sup5638x29x0x0x0index130;  slog::Index** mp_joinindex131;  slog::Index** mp_mskindex132;  slog::Index** mp_msk_ansindex133;  slog::Index** mp_hsbindex134;  slog::Index** mp_joindelta135;  slog::Index** mp_mskdelta136;  slog::Index** mp_hsbdelta137;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord139({0, 1});
      slog::Relation* readrel140 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex121 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel142 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index122 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel144 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index123 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex124 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel148 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index125 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex126 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 0, 1});
      slog::Relation* readrel152 = db->getRelation("mp_msk");
      mp_mskindex127 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel154 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index128 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel156 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index129 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0, 2, 3, 4});
      slog::Relation* readrel158 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index130 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 3, 4, 0});
      slog::Relation* readrel160 = db->getRelation("mp_join");
      mp_joinindex131 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 3, 4, 0});
      slog::Relation* readrel162 = db->getRelation("mp_join");
      mp_joindelta135 = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("mp_msk");
      mp_mskindex132 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("mp_msk");
      mp_mskdelta136 = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex133 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("mp_hsb");
      mp_hsbindex134 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mp_hsb");
      mp_hsbdelta137 = readrel172->getIndex(ord171, true);
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c56 = _t[0];
        u64 v_c28 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex121, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index122, std::array<u64,11>{v_c56, v_c28, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index123, std::array<u64,7>{v_c56, v_c28, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex124, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m173) {
          u64 v_c25 = m173[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index125, std::array<u64,11>{v_c56, v_c28, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex126, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m174) {
            u64 v_c24 = m174[1];
            if (!slog::exists_probe<3,1>(mp_mskindex127, std::array<u64,3>{v_c24, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index128, std::array<u64,11>{v_c56, v_c28, v_c25, v_c24, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m175) {
              u64 v_c57 = m175[4]; u64 v_c58 = m175[5]; u64 v_c59 = m175[6]; u64 v_c29 = m175[7]; u64 v_c30 = m175[8]; u64 v_c31 = m175[9]; u64 v_c32 = m175[10];
              if (v_c56 != v_c59) return;
              if (v_c56 != v_c58) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index129, std::array<u64,7>{v_c57, v_c29, v_c30, v_c31, v_c32, v_c56, v_c28}, [&](const std::array<u64,7>& m176) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index130, std::array<u64,5>{v_c29, v_c57, v_c30, v_c31, v_c32}, [&](const std::array<u64,5>& m177) {
                  slog::join_probe_old<5,5>(mp_joinindex131, mp_joindelta135, std::array<u64,5>{v_c29, v_c31, v_c30, v_c32, v_c57}, [&](const std::array<u64,5>& m178) {
                    slog::join_probe_old<3,2>(mp_mskindex132, mp_mskdelta136, std::array<u64,3>{v_c29, v_c24, 0}, [&](const std::array<u64,3>& m179) {
                      u64 v_c60 = m179[2];
                      slog::join_probe<2,1>(mp_msk_ansindex133, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m180) {
                        u64 v_c61 = m180[1];
                        u64 v_c62 = _prim_bxor(db, v_c29, v_c30);
                        if (v_c62 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex134, mp_hsbdelta137, std::array<u64,2>{v_c56, v_c62}, [&](const std::array<u64,2>& m181) {
                          u64 v_c63 = _prim_band(db, v_c29, v_c28);
                          if (v_c63 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c64 = _prim_gt(db, v_c63, v_c55);
                          if (v_c64 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c64) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c57, v_c61, v_c25, v_c31, v_c32});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c61, v_c25, v_c32, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask138* _cont = new ReadTask138(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask138(db,b), false);
  // (crule (pre (let __tconst74CV622 constd01925b37634a1a9d24159d8)) (scan mleaf __t9xNA244 k v) (body (exists _enum (1 0) 1 __tconst74CV622) (join-old mp_del (1 2 0) 2 (1 2 0) __t9xNA244 k __t63g3245) (join _enum (1 0) 1 __tconst74CV622 __t4Y7b243)) (head (emit mp_del_ans (0 1) __t63g3245 __t4Y7b243)) map.slog:80 #f)
  class ReadTask187 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex183;  slog::Index** mp_delindex184;  slog::Index** _enumindex185;  slog::Index** mp_deldelta186;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("mp_del_ans");
      head_index[0] = readrel189->getIndex(ord188, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord190({1, 0});
      slog::Relation* readrel191 = db->getRelation("_enum");
      _enumindex183 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 2, 0});
      slog::Relation* readrel193 = db->getRelation("mp_del");
      mp_delindex184 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("mp_del");
      mp_deldelta186 = readrel195->getIndex(ord194, true);
      std::vector<u16> ord196({1, 0});
      slog::Relation* readrel197 = db->getRelation("_enum");
      _enumindex185 = readrel197->getIndex(ord196, false);
  
    }
    ReadTask187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex183, std::array<u64,2>{v_c65, 0})) return;
        slog::join_probe_old<3,2>(mp_delindex184, mp_deldelta186, std::array<u64,3>{v_c66, v_c21, 0}, [&](const std::array<u64,3>& m198) {
          u64 v_c67 = m198[2];
          slog::join_probe<2,1>(_enumindex185, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m199) {
            u64 v_c68 = m199[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c68}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:80", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask187* _cont = new ReadTask187(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask187(db,b), false);
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (probe mp_has0_ans (1 0) 1 __tconst6EKe278 __t16yQ277) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t16yQ277 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (exists mp_put (1 2 0 3) 2 t k) (join-old $sup5638x68x0x0x0 (1 2 3 0) 2 (1 2 3 0) k t v __t2Eey276) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t2Eey276) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t4H3I279) (join-old mp_put_ans (0 1) 1 (0 1) __t4H3I279 r)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_has0index200;  slog::Index** mp_put_softindex201;  slog::Index** mp_putindex202;  slog::Index** $sup5638x68x0x0x0index203;  slog::Index** mp_put_softindex204;  slog::Index** mp_putindex205;  slog::Index** mp_put_ansindex206;  slog::Index** mp_has0delta207;  slog::Index** $sup5638x68x0x0x0delta208;  slog::Index** mp_put_softdelta209;  slog::Index** mp_putdelta210;  slog::Index** mp_put_ansdelta211;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("mp_has0_ans");
      driver_index = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({0, 2, 1});
      slog::Relation* readrel218 = db->getRelation("mp_has0");
      mp_has0index200 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({0, 2, 1});
      slog::Relation* readrel220 = db->getRelation("mp_has0");
      mp_has0delta207 = readrel220->getIndex(ord219, true);
      std::vector<u16> ord221({1, 2, 3, 0});
      slog::Relation* readrel222 = db->getRelation("mp_put_soft");
      mp_put_softindex201 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 0, 3});
      slog::Relation* readrel224 = db->getRelation("mp_put");
      mp_putindex202 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 3, 0});
      slog::Relation* readrel226 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index203 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 3, 0});
      slog::Relation* readrel228 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0delta208 = readrel228->getIndex(ord227, true);
      std::vector<u16> ord229({1, 2, 3, 0});
      slog::Relation* readrel230 = db->getRelation("mp_put_soft");
      mp_put_softindex204 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 3, 0});
      slog::Relation* readrel232 = db->getRelation("mp_put_soft");
      mp_put_softdelta209 = readrel232->getIndex(ord231, true);
      std::vector<u16> ord233({1, 2, 3, 0});
      slog::Relation* readrel234 = db->getRelation("mp_put");
      mp_putindex205 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 2, 3, 0});
      slog::Relation* readrel236 = db->getRelation("mp_put");
      mp_putdelta210 = readrel236->getIndex(ord235, true);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("mp_put_ans");
      mp_put_ansindex206 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 1});
      slog::Relation* readrel240 = db->getRelation("mp_put_ans");
      mp_put_ansdelta211 = readrel240->getIndex(ord239, true);
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c69, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m241) {
        u64 v_c70 = m241[1];
        if (buckethash(v_c70) != bucket) return;
        slog::join_probe_old<3,1>(mp_has0index200, mp_has0delta207, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m242) {
          u64 v_c21 = m242[1]; u64 v_c22 = m242[2];
          if (!slog::exists_probe<4,2>(mp_put_softindex201, std::array<u64,4>{v_c22, v_c21, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex202, std::array<u64,4>{v_c22, v_c21, 0, 0})) return;
          slog::join_probe_old<4,2>($sup5638x68x0x0x0index203, $sup5638x68x0x0x0delta208, std::array<u64,4>{v_c21, v_c22, 0, 0}, [&](const std::array<u64,4>& m243) {
            u64 v_c5 = m243[2]; u64 v_c71 = m243[3];
            slog::join_probe_old<4,4>(mp_put_softindex204, mp_put_softdelta209, std::array<u64,4>{v_c22, v_c21, v_c5, v_c71}, [&](const std::array<u64,4>& m244) {
              slog::join_probe_old<4,3>(mp_putindex205, mp_putdelta210, std::array<u64,4>{v_c22, v_c21, v_c5, 0}, [&](const std::array<u64,4>& m245) {
                u64 v_c72 = m245[3];
                slog::join_probe_old<2,1>(mp_put_ansindex206, mp_put_ansdelta211, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m246) {
                  u64 v_c11 = m246[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c11}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_has0_ans", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre (let _00024sqc9Gvh435 const4e07408562bedb8b60ce05c1) (let _00024sqc2pCX436 const624b60c58c9d8bfb6ff1886c) (let _00024sqc8NFs439 const7902699be42c8a8e46fbbb45) (let _00024sqc4tos440 constff5a1ae012afa5d4c889c50a) (let _00024sqc0EIl443 const6b86b273ff34fce19d6b804e) (let _00024sqc26Hv444 const4a44dc15364204a80fe80e90) (let _00024sqc6F3D447 const4e07408562bedb8b60ce05c1) (let _00024sqc39qs448 const5feceb66ffc86f38d952786c) (let _00024sqc1E69449 const6b86b273ff34fce19d6b804e) (let _00024sqc8pyr450 constd4735e3a265e16eee03f5971) (let _00024sqb0KXc433 (lempty)) (let _00024sqb6wOs434 (lpush _00024sqb0KXc433 _00024sqc9Gvh435)) (let _00024seq0 (lpush _00024sqb6wOs434 _00024sqc2pCX436)) (let _00024sqb3Fij437 (lempty)) (let _00024sqb4woH438 (lpush _00024sqb3Fij437 _00024sqc8NFs439)) (let _00024seq1 (lpush _00024sqb4woH438 _00024sqc4tos440)) (let _00024sqb9Uxs441 (lempty)) (let _00024sqb0lKj442 (lpush _00024sqb9Uxs441 _00024sqc0EIl443)) (let _00024seq2 (lpush _00024sqb0lKj442 _00024sqc26Hv444))) (scan mp_fromlist_ans __t0tcH289 r) (body (join mp_fromlist (0 1) 1 __t0tcH289 _00024seq3) (letp _00024sql38Vc445 (aslst _00024seq3)) (let chk3Wie1079 (llen _00024sql38Vc445)) (eq _00024sqc6F3D447 chk3Wie1079) (letp chk4POp1080 (lref _00024sql38Vc445 _00024sqc39qs448)) (eq _00024seq0 chk4POp1080) (letp chk1MDi1081 (lref _00024sql38Vc445 _00024sqc1E69449)) (eq _00024seq1 chk1MDi1081) (letp chk3wxQ1082 (lref _00024sql38Vc445 _00024sqc8pyr450)) (eq _00024seq2 chk3wxQ1082)) (head (emit canon (0) r)) mp_basic.slog:16 #f)
  class ReadTask248 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_fromlistindex247;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord249({0});
      slog::Relation* readrel250 = db->getRelation("canon");
      head_index[0] = readrel250->getIndex(ord249, false);
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("mp_fromlist");
      mp_fromlistindex247 = readrel252->getIndex(ord251, false);
  
    }
    ReadTask248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c74 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c75 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c76 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c78 = v_const4a44dc15364204a80fe80e90;
      u64 v_c79 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c80 = v_const5feceb66ffc86f38d952786c;
      u64 v_c81 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c82 = v_constd4735e3a265e16eee03f5971;
      u64 v_c83 = _prim_lempty(db);
      if (v_c83 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c84 = _prim_lpush(db, v_c83, v_c73);
      if (v_c84 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c85 = _prim_lpush(db, v_c84, v_c74);
      if (v_c85 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c86 = _prim_lempty(db);
      if (v_c86 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c87 = _prim_lpush(db, v_c86, v_c75);
      if (v_c87 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c88 = _prim_lpush(db, v_c87, v_c76);
      if (v_c88 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c89 = _prim_lempty(db);
      if (v_c89 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c90 = _prim_lpush(db, v_c89, v_c77);
      if (v_c90 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c91 = _prim_lpush(db, v_c90, v_c78);
      if (v_c91 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c92 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe<2,1>(mp_fromlistindex247, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m253) {
          u64 v_c93 = m253[1];
          bool ok254 = true;
          u64 v_c94 = _prim_aslst(db, v_c93, &ok254);
          if (!ok254) return;
          u64 v_c95 = _prim_llen(db, v_c94);
          if (v_c95 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return; }
          if (v_c79 != v_c95) return;
          bool ok255 = true;
          u64 v_c96 = _prim_lref(db, v_c94, v_c80, &ok255);
          if (!ok255) return;
          if (v_c85 != v_c96) return;
          bool ok256 = true;
          u64 v_c97 = _prim_lref(db, v_c94, v_c81, &ok256);
          if (!ok256) return;
          if (v_c88 != v_c97) return;
          bool ok257 = true;
          u64 v_c98 = _prim_lref(db, v_c94, v_c82, &ok257);
          if (!ok257) return;
          if (v_c91 != v_c98) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:16", "delta:mp_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask248* _cont = new ReadTask248(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask248(db,b), false);
  // (crule (pre (let __trid2hJI853 constfee494ff4827aeb0635bb714) (let __trel0l7X854 const20347926ddb307a8e2bdb71b) (let __tcol3G8h855 constd4735e3a265e16eee03f5971)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1DER257) (join-old mp_msk_ans (0 1) 2 (0 1) __t1DER257 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t4tTw258) (join-old mp_del_ans (0 1) 1 (0 1) __t4tTw258 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2hJI853 __trel0l7X854 __tcol3G8h855 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __5v59852 p m l __v0)) map.slog:85 #f)
  class ReadTask271 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex258;  slog::Index** mp_delindex259;  slog::Index** mp_mskindex260;  slog::Index** mp_msk_ansindex261;  slog::Index** mp_delindex262;  slog::Index** mp_del_ansindex263;  slog::Index** mp_mskdelta264;  slog::Index** mp_msk_ansdelta265;  slog::Index** mp_deldelta266;  slog::Index** mp_del_ansdelta267;
    u32 sid269;  u32 sid268;  u32 sid270;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord272({1, 0});
      slog::Relation* readrel273 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex258 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 2, 0});
      slog::Relation* readrel275 = db->getRelation("mp_del");
      mp_delindex259 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 0});
      slog::Relation* readrel277 = db->getRelation("mp_msk");
      mp_mskindex260 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 2, 0});
      slog::Relation* readrel279 = db->getRelation("mp_msk");
      mp_mskdelta264 = readrel279->getIndex(ord278, true);
      std::vector<u16> ord280({0, 1});
      slog::Relation* readrel281 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex261 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 1});
      slog::Relation* readrel283 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta265 = readrel283->getIndex(ord282, true);
      std::vector<u16> ord284({1, 2, 0});
      slog::Relation* readrel285 = db->getRelation("mp_del");
      mp_delindex262 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 2, 0});
      slog::Relation* readrel287 = db->getRelation("mp_del");
      mp_deldelta266 = readrel287->getIndex(ord286, true);
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("mp_del_ans");
      mp_del_ansindex263 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("mp_del_ans");
      mp_del_ansdelta267 = readrel291->getIndex(ord290, true);
      sid269 = db->getRelation("_enum")->getStructId();
      sid268 = db->getRelation("mbranch")->getStructId();
      sid270 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask271(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_constfee494ff4827aeb0635bb714;
      u64 v_c100 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c101 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c11 = _t[5];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex258, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex259, std::array<u64,3>{v_c11, v_c21, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex260, mp_mskdelta264, std::array<u64,3>{v_c21, v_c9, 0}, [&](const std::array<u64,3>& m292) {
          u64 v_c102 = m292[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex261, mp_msk_ansdelta265, std::array<u64,2>{v_c102, v_c8}, [&](const std::array<u64,2>& m293) {
            slog::join_probe_old<3,2>(mp_delindex262, mp_deldelta266, std::array<u64,3>{v_c11, v_c21, 0}, [&](const std::array<u64,3>& m294) {
              u64 v_c103 = m294[2];
              slog::join_probe_old<2,1>(mp_del_ansindex263, mp_del_ansdelta267, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m295) {
                u64 v_c28 = m295[1];
                ++_fires;
                if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid268 || decode_struct_id(v_c10) == sid269 || decode_struct_id(v_c10) == sid270))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c99, v_c100, v_c101, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c9, v_c10, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask271* _cont = new ReadTask271(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask271(db,b), false);
  // (crule (pre (let __tconst1GO9299 const5feceb66ffc86f38d952786c)) (scan mbranch __t8ocD300 p m l r) (body (exists mp_has0 (1 2 0) 1 __t8ocD300) (exists mp_msk (2 0 1) 1 m) (join $sup5638x59x0x0x0 (2 3 4 5 0 1) 4 l m p r __t0IP7301 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t0IP7301 k __t8ocD300) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6Y68302) (join mp_msk_ans (0 1) 1 __t6Y68302 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t0IP7301 __tconst1GO9299)) map.slog:60 #f)
  class ReadTask304 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index296;  slog::Index** mp_mskindex297;  slog::Index** $sup5638x59x0x0x0index298;  slog::Index** mp_has0index299;  slog::Index** mp_mskindex300;  slog::Index** mp_msk_ansindex301;  slog::Index** mp_has0delta302;  slog::Index** mp_mskdelta303;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord305({0, 1});
      slog::Relation* readrel306 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel306->getIndex(ord305, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("mp_has0");
      mp_has0index296 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({2, 0, 1});
      slog::Relation* readrel310 = db->getRelation("mp_msk");
      mp_mskindex297 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel312 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index298 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 2, 1});
      slog::Relation* readrel314 = db->getRelation("mp_has0");
      mp_has0index299 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({0, 2, 1});
      slog::Relation* readrel316 = db->getRelation("mp_has0");
      mp_has0delta302 = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("mp_msk");
      mp_mskindex300 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 2, 0});
      slog::Relation* readrel320 = db->getRelation("mp_msk");
      mp_mskdelta303 = readrel320->getIndex(ord319, true);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex301 = readrel322->getIndex(ord321, false);
  
    }
    ReadTask304(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c105 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index296, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex297, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x59x0x0x0index298, std::array<u64,6>{v_c10, v_c9, v_c8, v_c11, 0, 0}, [&](const std::array<u64,6>& m323) {
          u64 v_c106 = m323[4]; u64 v_c21 = m323[5];
          slog::join_probe_old<3,3>(mp_has0index299, mp_has0delta302, std::array<u64,3>{v_c106, v_c21, v_c105}, [&](const std::array<u64,3>& m324) {
            slog::join_probe_old<3,2>(mp_mskindex300, mp_mskdelta303, std::array<u64,3>{v_c21, v_c9, 0}, [&](const std::array<u64,3>& m325) {
              u64 v_c107 = m325[2];
              slog::join_probe<2,1>(mp_msk_ansindex301, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m326) {
                u64 v_c28 = m326[1];
                if (v_c8 == v_c28) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c106, v_c104}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask304* _cont = new ReadTask304(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask304(db,b), false);
  // (crule (pre) (scan mp_union __t0SXa192 __t5w7I193 __t9UVm194) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t5w7I193 p m l r) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t9UVm194 q n u v) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t0SXa192 l n p r __t5w7I193 __t9UVm194 u v)) map.slog:102 #f)
  class ReadTask331 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex327;  slog::Index** mbranchindex328;  slog::Index** mbranchdelta329;  slog::Index** mbranchdelta330;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord332({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel333 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel333->getIndex(ord332, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord334({0, 1, 2, 3, 4});
      slog::Relation* readrel335 = db->getRelation("mbranch");
      mbranchindex327 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({0, 1, 2, 3, 4});
      slog::Relation* readrel337 = db->getRelation("mbranch");
      mbranchdelta329 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({0, 1, 2, 3, 4});
      slog::Relation* readrel339 = db->getRelation("mbranch");
      mbranchindex328 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1, 2, 3, 4});
      slog::Relation* readrel341 = db->getRelation("mbranch");
      mbranchdelta330 = readrel341->getIndex(ord340, true);
  
    }
    ReadTask331(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c109 = _t[1];
        u64 v_c110 = _t[2];
        slog::join_probe_old<5,1>(mbranchindex327, mbranchdelta329, std::array<u64,5>{v_c109, 0, 0, 0, 0}, [&](const std::array<u64,5>& m342) {
          u64 v_c8 = m342[1]; u64 v_c9 = m342[2]; u64 v_c10 = m342[3]; u64 v_c11 = m342[4];
          slog::join_probe_old<5,1>(mbranchindex328, mbranchdelta330, std::array<u64,5>{v_c110, 0, 0, 0, 0}, [&](const std::array<u64,5>& m343) {
            u64 v_c2 = m343[1]; u64 v_c3 = m343[2]; u64 v_c4 = m343[3]; u64 v_c5 = m343[4];
            u64 v_c111 = _prim_lt(db, v_c3, v_c9);
            if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c111) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c9, v_c2, v_c108, v_c10, v_c3, v_c8, v_c11, v_c109, v_c110, v_c4, v_c5}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask331* _cont = new ReadTask331(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask331(db,b), false);
  // (crule (pre (let __trid0KF0714 const5f7e60cb3d02e4170101c2bc) (let __trel0TAV715 const7f254967624b26d820569bd6) (let __tcol6xa7716 const6b86b273ff34fce19d6b804e) (let __trel8DoH717 const72bac24066bb34077c1f6e71) (let __tcol6L2F718 const5feceb66ffc86f38d952786c) (let __trel7syr719 const72bac24066bb34077c1f6e71) (let __tcol7HKz720 const6b86b273ff34fce19d6b804e) (let __trel5Acv721 const72bac24066bb34077c1f6e71) (let __tcol0ILJ722 constd4735e3a265e16eee03f5971) (let __trel1QCu723 const72bac24066bb34077c1f6e71) (let __tcol2fu2724 const4e07408562bedb8b60ce05c1)) (scan $sup5638x104x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid0KF0714 __trel0TAV715 __tcol6xa7716 (1 2 3 4 0)) (tycheck p (accept int) __trid0KF0714 __trel8DoH717 __tcol6L2F718 (1 2 3 4 0)) (tycheck m (accept int) __trid0KF0714 __trel7syr719 __tcol7HKz720 (1 2 3 4 0)) (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid0KF0714 __trel5Acv721 __tcol0ILJ722 (1 2 3 4 0)) (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid0KF0714 __trel1QCu723 __tcol2fu2724 (1 2 3 4 0)) (emit-temp temp1Gnx1042 l m p r u) (mkstruct mbranch (1 2 3 4 0) __t9u4W344 p m l r)) map.slog:105 #f)
  class ReadTask348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid346;  u32 sid345;  u32 sid347;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp1Gnx1042");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x1");
      sid346 = db->getRelation("_enum")->getStructId();
      sid345 = db->getRelation("mbranch")->getStructId();
      sid347 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c112 = v_const5f7e60cb3d02e4170101c2bc;
      u64 v_c113 = v_const7f254967624b26d820569bd6;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const72bac24066bb34077c1f6e71;
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
      u64 v_c117 = v_const72bac24066bb34077c1f6e71;
      u64 v_c118 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c119 = v_const72bac24066bb34077c1f6e71;
      u64 v_c120 = v_constd4735e3a265e16eee03f5971;
      u64 v_c121 = v_const72bac24066bb34077c1f6e71;
      u64 v_c122 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c20 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c2 = _t[6];
        u64 v_c11 = _t[7];
        u64 v_c4 = _t[8];
        u64 v_c5 = _t[9];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid345 || decode_struct_id(v_c4) == sid346 || decode_struct_id(v_c4) == sid347))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c112, v_c113, v_c114, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c112, v_c115, v_c116, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c112, v_c117, v_c118, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid345 || decode_struct_id(v_c10) == sid346 || decode_struct_id(v_c10) == sid347))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c112, v_c119, v_c120, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c11) && (decode_struct_id(v_c11) == sid345 || decode_struct_id(v_c11) == sid346 || decode_struct_id(v_c11) == sid347))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c112, v_c121, v_c122, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c10, v_c9, v_c8, v_c11, v_c4});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c8, v_c9, v_c10, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x1", _fires);
  
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
  // (crule (pre) (scan temp1Yd51020 __t1mkY280) (body) (head (mkstruct mp_hsb (1 0) __4aej665 __t1mkY280)) map.slog:26 #f)
  class ReadTask349 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb");
      outer_rel = db->getRelation("temp1Yd51020");
  
    }
    ReadTask349(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c123 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c123}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp1Yd51020", _fires);
  
      if (!_done)
      {
        ReadTask349* _cont = new ReadTask349(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask349(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x1 __t6Puw51 __t2bXu55 __v0 p0 p1 t0 t1) (body (exists $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (exists mp_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t6Puw51) (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists mp_hsb_ans (0 1) 2 __t2bXu55 __v0) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0 dup3kne1056 dup92Cz1057 __v1 __v3) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join-old $sup5638x25x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join-old mp_msk_ans (0 1) 1 (0 1) __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask372 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x0index350;  slog::Index** mp_joinindex351;  slog::Index** mp_hsb_ansindex352;  slog::Index** mp_hsb_ansindex353;  slog::Index** mp_mskindex354;  slog::Index** $sup5638x25x0x0x2index355;  slog::Index** $sup5638x25x0x0x0index356;  slog::Index** mp_joinindex357;  slog::Index** mp_hsb_ansindex358;  slog::Index** mp_hsb_ansindex359;  slog::Index** mp_hsb_ansindex360;  slog::Index** mp_mskindex361;  slog::Index** mp_msk_ansindex362;  slog::Index** mp_hsbindex363;  slog::Index** $sup5638x25x0x0x0delta364;  slog::Index** mp_joindelta365;  slog::Index** mp_hsb_ansdelta366;  slog::Index** mp_hsb_ansdelta367;  slog::Index** mp_hsb_ansdelta368;  slog::Index** mp_mskdelta369;  slog::Index** mp_msk_ansdelta370;  slog::Index** mp_hsbdelta371;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord373({1, 0, 2, 3, 4});
      slog::Relation* readrel374 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index350 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 2, 3, 4, 0});
      slog::Relation* readrel376 = db->getRelation("mp_join");
      mp_joinindex351 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({0, 1});
      slog::Relation* readrel378 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex352 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({0, 1});
      slog::Relation* readrel380 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex353 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 2, 0});
      slog::Relation* readrel382 = db->getRelation("mp_msk");
      mp_mskindex354 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel384 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index355 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 0, 2, 3, 4});
      slog::Relation* readrel386 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index356 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 0, 2, 3, 4});
      slog::Relation* readrel388 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0delta364 = readrel388->getIndex(ord387, true);
      std::vector<u16> ord389({1, 2, 3, 4, 0});
      slog::Relation* readrel390 = db->getRelation("mp_join");
      mp_joinindex357 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 3, 4, 0});
      slog::Relation* readrel392 = db->getRelation("mp_join");
      mp_joindelta365 = readrel392->getIndex(ord391, true);
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex358 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0, 1});
      slog::Relation* readrel396 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta366 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({0, 1});
      slog::Relation* readrel398 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex359 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1});
      slog::Relation* readrel400 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta367 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex360 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta368 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("mp_msk");
      mp_mskindex361 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 0});
      slog::Relation* readrel408 = db->getRelation("mp_msk");
      mp_mskdelta369 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex362 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({0, 1});
      slog::Relation* readrel412 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta370 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("mp_hsb");
      mp_hsbindex363 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("mp_hsb");
      mp_hsbdelta371 = readrel416->getIndex(ord415, true);
  
    }
    ReadTask372(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c126 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c31 = _t[5];
        u64 v_c32 = _t[6];
        if (!slog::exists_probe<5,5>($sup5638x25x0x0x0index350, std::array<u64,5>{v_c29, v_c125, v_c30, v_c31, v_c32})) return;
        if (!slog::exists_probe<5,5>(mp_joinindex351, std::array<u64,5>{v_c29, v_c31, v_c30, v_c32, v_c125})) return;
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex352, std::array<u64,2>{v_c126, 0})) return;
        if (!slog::exists_probe<2,2>(mp_hsb_ansindex353, std::array<u64,2>{v_c126, v_c28})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex354, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe<11,7>($sup5638x25x0x0x2index355, std::array<u64,11>{v_c125, v_c29, v_c30, v_c31, v_c32, v_c126, v_c28, 0, 0, 0, 0}, [&](const std::array<u64,11>& m417) {
          u64 v_c127 = m417[7]; u64 v_c128 = m417[8]; u64 v_c24 = m417[9]; u64 v_c25 = m417[10];
          if (v_c126 != v_c128) return;
          if (v_c126 != v_c127) return;
          slog::join_probe_old<5,5>($sup5638x25x0x0x0index356, $sup5638x25x0x0x0delta364, std::array<u64,5>{v_c29, v_c125, v_c30, v_c31, v_c32}, [&](const std::array<u64,5>& m418) {
            slog::join_probe_old<5,5>(mp_joinindex357, mp_joindelta365, std::array<u64,5>{v_c29, v_c31, v_c30, v_c32, v_c125}, [&](const std::array<u64,5>& m419) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex358, mp_hsb_ansdelta366, std::array<u64,2>{v_c126, v_c25}, [&](const std::array<u64,2>& m420) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex359, mp_hsb_ansdelta367, std::array<u64,2>{v_c126, v_c24}, [&](const std::array<u64,2>& m421) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex360, mp_hsb_ansdelta368, std::array<u64,2>{v_c126, v_c28}, [&](const std::array<u64,2>& m422) {
                    slog::join_probe_old<3,2>(mp_mskindex361, mp_mskdelta369, std::array<u64,3>{v_c29, v_c24, 0}, [&](const std::array<u64,3>& m423) {
                      u64 v_c129 = m423[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex362, mp_msk_ansdelta370, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m424) {
                        u64 v_c61 = m424[1];
                        u64 v_c130 = _prim_bxor(db, v_c29, v_c30);
                        if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex363, mp_hsbdelta371, std::array<u64,2>{v_c126, v_c130}, [&](const std::array<u64,2>& m425) {
                          u64 v_c131 = _prim_band(db, v_c29, v_c28);
                          if (v_c131 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c132 = _prim_lt(db, v_c131, v_c124);
                          if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c132) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c125, v_c61, v_c25, v_c31, v_c32});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c61, v_c25, v_c31, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask372* _cont = new ReadTask372(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask372(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t0M9S378 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t0M9S378 q m) (exists $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_join (3 4 1 0 2) 1 q) (join-old mbranch (2 0 1 3 4) 1 (2 0 1 3 4) m __t8hMI375 p l r) (neq p __v0) (exists mp_join (1 2 3 4 0) 3 p __t8hMI375 q) (exists mp_union (1 2 0) 1 __t8hMI375) (join-old $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 (1 2 4 6 7 5 0 3 8 9 10) l m p r __t8hMI375 q __t4ZhK374 n __t5XzA376 u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5XzA376) (exists mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t8hMI375 q __t5XzA376 __t35Cd377) (join-old mp_union (0 1 2) 3 (0 1 2) __t4ZhK374 __t8hMI375 __t5XzA376) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask446 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex427;  slog::Index** $sup5638x101x0x0x0index428;  slog::Index** mbranchindex429;  slog::Index** mp_joinindex430;  slog::Index** mbranchindex431;  slog::Index** mp_joinindex432;  slog::Index** mp_unionindex433;  slog::Index** $sup5638x101x0x0x0index434;  slog::Index** mbranchindex435;  slog::Index** mp_unionindex436;  slog::Index** mp_joinindex437;  slog::Index** mp_unionindex438;  slog::Index** mp_join_ansindex439;  slog::Index** mp_mskdelta440;  slog::Index** mbranchdelta441;  slog::Index** $sup5638x101x0x0x0delta442;  slog::Index** mbranchdelta443;  slog::Index** mp_joindelta444;  slog::Index** mp_uniondelta445;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord447({0, 1});
      slog::Relation* readrel448 = db->getRelation("mp_union_ans");
      head_index[0] = readrel448->getIndex(ord447, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord449({0, 1, 2});
      slog::Relation* readrel450 = db->getRelation("mp_msk");
      mp_mskindex427 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({0, 1, 2});
      slog::Relation* readrel452 = db->getRelation("mp_msk");
      mp_mskdelta440 = readrel452->getIndex(ord451, true);
      std::vector<u16> ord453({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel454 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index428 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 3, 4, 0});
      slog::Relation* readrel456 = db->getRelation("mbranch");
      mbranchindex429 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({3, 4, 1, 0, 2});
      slog::Relation* readrel458 = db->getRelation("mp_join");
      mp_joinindex430 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({2, 0, 1, 3, 4});
      slog::Relation* readrel460 = db->getRelation("mbranch");
      mbranchindex431 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({2, 0, 1, 3, 4});
      slog::Relation* readrel462 = db->getRelation("mbranch");
      mbranchdelta441 = readrel462->getIndex(ord461, true);
      std::vector<u16> ord463({1, 2, 3, 4, 0});
      slog::Relation* readrel464 = db->getRelation("mp_join");
      mp_joinindex432 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 0});
      slog::Relation* readrel466 = db->getRelation("mp_union");
      mp_unionindex433 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel468 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index434 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel470 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0delta442 = readrel470->getIndex(ord469, true);
      std::vector<u16> ord471({1, 2, 3, 4, 0});
      slog::Relation* readrel472 = db->getRelation("mbranch");
      mbranchindex435 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 2, 3, 4, 0});
      slog::Relation* readrel474 = db->getRelation("mbranch");
      mbranchdelta443 = readrel474->getIndex(ord473, true);
      std::vector<u16> ord475({0, 1, 2});
      slog::Relation* readrel476 = db->getRelation("mp_union");
      mp_unionindex436 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 3, 4, 0});
      slog::Relation* readrel478 = db->getRelation("mp_join");
      mp_joinindex437 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 4, 0});
      slog::Relation* readrel480 = db->getRelation("mp_join");
      mp_joindelta444 = readrel480->getIndex(ord479, true);
      std::vector<u16> ord481({0, 1, 2});
      slog::Relation* readrel482 = db->getRelation("mp_union");
      mp_unionindex438 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({0, 1, 2});
      slog::Relation* readrel484 = db->getRelation("mp_union");
      mp_uniondelta445 = readrel484->getIndex(ord483, true);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("mp_join_ans");
      mp_join_ansindex439 = readrel486->getIndex(ord485, false);
  
    }
    ReadTask446(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c133 = _t[0];
        u64 v_c28 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex427, mp_mskdelta440, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m487) {
          u64 v_c2 = m487[1]; u64 v_c9 = m487[2];
          if (!slog::exists_probe<11,2>($sup5638x101x0x0x0index428, std::array<u64,11>{v_c9, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex429, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex430, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(mbranchindex431, mbranchdelta441, std::array<u64,5>{v_c9, 0, 0, 0, 0}, [&](const std::array<u64,5>& m488) {
            u64 v_c134 = m488[1]; u64 v_c8 = m488[2]; u64 v_c10 = m488[3]; u64 v_c11 = m488[4];
            if (v_c8 == v_c28) return;
            if (!slog::exists_probe<5,3>(mp_joinindex432, std::array<u64,5>{v_c8, v_c134, v_c2, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex433, std::array<u64,3>{v_c134, 0, 0})) return;
            slog::join_probe_old<11,6>($sup5638x101x0x0x0index434, $sup5638x101x0x0x0delta442, std::array<u64,11>{v_c10, v_c9, v_c8, v_c11, v_c134, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m489) {
              u64 v_c135 = m489[6]; u64 v_c3 = m489[7]; u64 v_c136 = m489[8]; u64 v_c4 = m489[9]; u64 v_c5 = m489[10];
              u64 v_c137 = _prim_lt(db, v_c3, v_c9);
              if (v_c137 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
              if (!v_c137) return;
              slog::join_probe_old<5,5>(mbranchindex435, mbranchdelta443, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, v_c136}, [&](const std::array<u64,5>& m491) {
                if (!slog::exists_probe<3,3>(mp_unionindex436, std::array<u64,3>{v_c135, v_c134, v_c136})) return;
                slog::join_probe_old<5,4>(mp_joinindex437, mp_joindelta444, std::array<u64,5>{v_c8, v_c134, v_c2, v_c136, 0}, [&](const std::array<u64,5>& m492) {
                  u64 v_c138 = m492[4];
                  slog::join_probe_old<3,3>(mp_unionindex438, mp_uniondelta445, std::array<u64,3>{v_c135, v_c134, v_c136}, [&](const std::array<u64,3>& m493) {
                    slog::join_probe<2,1>(mp_join_ansindex439, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m494) {
                      u64 v_c139 = m494[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c135, v_c139}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask446* _cont = new ReadTask446(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask446(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mbranch __t85IU153 p m l r) (body (exists mp_del (1 2 0) 1 __t85IU153) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 1 l) (join $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 p m r l __t8KQn154 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t8KQn154 k __t85IU153) (exists mp_msk (1 2 0) 2 k m) (exists mp_del (1 2 0) 2 l k) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t0Lvo157 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join mp_del_ans (0 1) 2 __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex495;  slog::Index** mp_bldindex496;  slog::Index** mp_mskindex497;  slog::Index** mp_msk_ansindex498;  slog::Index** mp_delindex499;  slog::Index** $sup5638x82x0x0x0index500;  slog::Index** mp_delindex501;  slog::Index** mp_mskindex502;  slog::Index** mp_delindex503;  slog::Index** mp_bldindex504;  slog::Index** mp_del_ansindex505;  slog::Index** mp_bld_ansindex506;  slog::Index** mp_mskindex507;  slog::Index** mp_msk_ansindex508;  slog::Index** mp_delindex509;  slog::Index** mp_del_ansindex510;  slog::Index** mp_bld_ansindex511;  slog::Index** mp_deldelta512;  slog::Index** mp_blddelta513;  slog::Index** mp_mskdelta514;  slog::Index** mp_deldelta515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("mp_del_ans");
      head_index[0] = readrel518->getIndex(ord517, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("mp_del");
      mp_delindex495 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({2, 1, 4, 0, 3});
      slog::Relation* readrel522 = db->getRelation("mp_bld");
      mp_bldindex496 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({2, 0, 1});
      slog::Relation* readrel524 = db->getRelation("mp_msk");
      mp_mskindex497 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 0});
      slog::Relation* readrel526 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex498 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 0});
      slog::Relation* readrel528 = db->getRelation("mp_del");
      mp_delindex499 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel530 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index500 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 2, 1});
      slog::Relation* readrel532 = db->getRelation("mp_del");
      mp_delindex501 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({0, 2, 1});
      slog::Relation* readrel534 = db->getRelation("mp_del");
      mp_deldelta512 = readrel534->getIndex(ord533, true);
      std::vector<u16> ord535({1, 2, 0});
      slog::Relation* readrel536 = db->getRelation("mp_msk");
      mp_mskindex502 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("mp_del");
      mp_delindex503 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({2, 1, 4, 0, 3});
      slog::Relation* readrel540 = db->getRelation("mp_bld");
      mp_bldindex504 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({2, 1, 4, 0, 3});
      slog::Relation* readrel542 = db->getRelation("mp_bld");
      mp_blddelta513 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({1, 0});
      slog::Relation* readrel544 = db->getRelation("mp_del_ans");
      mp_del_ansindex505 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex506 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("mp_msk");
      mp_mskindex507 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("mp_msk");
      mp_mskdelta514 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex508 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 0});
      slog::Relation* readrel554 = db->getRelation("mp_del");
      mp_delindex509 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 2, 0});
      slog::Relation* readrel556 = db->getRelation("mp_del");
      mp_deldelta515 = readrel556->getIndex(ord555, true);
      std::vector<u16> ord557({0, 1});
      slog::Relation* readrel558 = db->getRelation("mp_del_ans");
      mp_del_ansindex510 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1});
      slog::Relation* readrel560 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex511 = readrel560->getIndex(ord559, false);
  
    }
    ReadTask516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
  
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
        if (!slog::exists_probe<3,1>(mp_delindex495, std::array<u64,3>{v_c141, 0, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex496, std::array<u64,5>{v_c9, v_c8, v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex497, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex498, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex499, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x82x0x0x0index500, std::array<u64,6>{v_c8, v_c9, v_c11, v_c10, 0, 0}, [&](const std::array<u64,6>& m561) {
          u64 v_c142 = m561[4]; u64 v_c21 = m561[5];
          slog::join_probe_old<3,3>(mp_delindex501, mp_deldelta512, std::array<u64,3>{v_c142, v_c21, v_c141}, [&](const std::array<u64,3>& m562) {
            if (!slog::exists_probe<3,2>(mp_mskindex502, std::array<u64,3>{v_c21, v_c9, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex503, std::array<u64,3>{v_c10, v_c21, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex504, mp_blddelta513, std::array<u64,5>{v_c9, v_c8, v_c11, 0, 0}, [&](const std::array<u64,5>& m563) {
              u64 v_c143 = m563[3]; u64 v_c28 = m563[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex505, std::array<u64,2>{v_c28, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex506, std::array<u64,2>{v_c143, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex507, mp_mskdelta514, std::array<u64,3>{v_c21, v_c9, 0}, [&](const std::array<u64,3>& m564) {
                u64 v_c144 = m564[2];
                slog::join_probe<2,2>(mp_msk_ansindex508, std::array<u64,2>{v_c144, v_c8}, [&](const std::array<u64,2>& m565) {
                  slog::join_probe_old<3,2>(mp_delindex509, mp_deldelta515, std::array<u64,3>{v_c10, v_c21, 0}, [&](const std::array<u64,3>& m566) {
                    u64 v_c145 = m566[2];
                    slog::join_probe<2,2>(mp_del_ansindex510, std::array<u64,2>{v_c145, v_c28}, [&](const std::array<u64,2>& m567) {
                      slog::join_probe<2,1>(mp_bld_ansindex511, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m568) {
                        u64 v_c139 = m568[1];
                        u64 v_c146 = _prim_band(db, v_c21, v_c9);
                        if (v_c146 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c147 = _prim_lt(db, v_c146, v_c140);
                        if (v_c147 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c147) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c142, v_c139}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mbranch __t6XhK108 p m l r) (body (exists $sup5638x104x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists mp_union (1 2 0) 1 __t6XhK108) (exists mp_msk (1 2 0) 1 p) (join $sup5638x104x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t38nk104 n q u v) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t38nk104 __t6XhK108) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (1 2 0) 2 __t6XhK108 u) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t38nk104 l m p r __t3jH2107) (exists mp_msk (1 2 0) 3 p n __t3jH2107) (exists mp_msk_ans (0 1) 2 __t3jH2107 q) (join mbranch (1 2 3 4 0) 4 q n u v __t9OKP102) (join mp_union (0 1 2) 3 __t38nk104 __t6XhK108 __t9OKP102) (join mp_msk (1 2 0) 3 p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask589 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index570;  slog::Index** mp_unionindex571;  slog::Index** mp_mskindex572;  slog::Index** $sup5638x104x0x0x0index573;  slog::Index** mbranchindex574;  slog::Index** mp_unionindex575;  slog::Index** mp_mskindex576;  slog::Index** mp_msk_ansindex577;  slog::Index** mp_unionindex578;  slog::Index** $sup5638x104x0x0x1index579;  slog::Index** mp_mskindex580;  slog::Index** mp_msk_ansindex581;  slog::Index** mbranchindex582;  slog::Index** mp_unionindex583;  slog::Index** mp_mskindex584;  slog::Index** mp_msk_ansindex585;  slog::Index** mp_unionindex586;  slog::Index** mp_union_ansindex587;  slog::Index** mp_uniondelta588;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord590({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel591 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index570 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 0});
      slog::Relation* readrel593 = db->getRelation("mp_union");
      mp_unionindex571 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 2, 0});
      slog::Relation* readrel595 = db->getRelation("mp_msk");
      mp_mskindex572 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel597 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index573 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 2, 3, 4, 0});
      slog::Relation* readrel599 = db->getRelation("mbranch");
      mbranchindex574 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({0, 1, 2});
      slog::Relation* readrel601 = db->getRelation("mp_union");
      mp_unionindex575 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("mp_msk");
      mp_mskindex576 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 0});
      slog::Relation* readrel605 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex577 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 2, 0});
      slog::Relation* readrel607 = db->getRelation("mp_union");
      mp_unionindex578 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel609 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index579 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 0});
      slog::Relation* readrel611 = db->getRelation("mp_msk");
      mp_mskindex580 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex581 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 2, 3, 4, 0});
      slog::Relation* readrel615 = db->getRelation("mbranch");
      mbranchindex582 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({0, 1, 2});
      slog::Relation* readrel617 = db->getRelation("mp_union");
      mp_unionindex583 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 2, 0});
      slog::Relation* readrel619 = db->getRelation("mp_msk");
      mp_mskindex584 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({0, 1});
      slog::Relation* readrel621 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex585 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("mp_union");
      mp_unionindex586 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("mp_union");
      mp_uniondelta588 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({0, 1});
      slog::Relation* readrel627 = db->getRelation("mp_union_ans");
      mp_union_ansindex587 = readrel627->getIndex(ord626, false);
  
    }
    ReadTask589(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x104x0x0x1index570, std::array<u64,10>{v_c10, v_c9, v_c8, v_c11, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex571, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex572, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x104x0x0x0index573, std::array<u64,9>{v_c10, v_c9, v_c8, v_c11, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m628) {
          u64 v_c150 = m628[4]; u64 v_c3 = m628[5]; u64 v_c2 = m628[6]; u64 v_c4 = m628[7]; u64 v_c5 = m628[8];
          u64 v_c151 = _prim_lt(db, v_c9, v_c3);
          if (v_c151 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c151) return;
          if (!slog::exists_probe<5,4>(mbranchindex574, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex575, std::array<u64,3>{v_c150, v_c149, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex576, std::array<u64,3>{v_c8, v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex577, std::array<u64,2>{v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex578, std::array<u64,3>{v_c149, v_c4, 0})) return;
          slog::join_probe<10,9>($sup5638x104x0x0x1index579, std::array<u64,10>{v_c4, v_c3, v_c2, v_c5, v_c150, v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,10>& m630) {
            u64 v_c152 = m630[9];
            if (!slog::exists_probe<3,3>(mp_mskindex580, std::array<u64,3>{v_c8, v_c3, v_c152})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex581, std::array<u64,2>{v_c152, v_c2})) return;
            slog::join_probe<5,4>(mbranchindex582, std::array<u64,5>{v_c2, v_c3, v_c4, v_c5, 0}, [&](const std::array<u64,5>& m631) {
              u64 v_c153 = m631[4];
              slog::join_probe<3,3>(mp_unionindex583, std::array<u64,3>{v_c150, v_c149, v_c153}, [&](const std::array<u64,3>& m632) {
                slog::join_probe<3,3>(mp_mskindex584, std::array<u64,3>{v_c8, v_c3, v_c152}, [&](const std::array<u64,3>& m633) {
                  slog::join_probe<2,2>(mp_msk_ansindex585, std::array<u64,2>{v_c152, v_c2}, [&](const std::array<u64,2>& m634) {
                    slog::join_probe_old<3,2>(mp_unionindex586, mp_uniondelta588, std::array<u64,3>{v_c149, v_c4, 0}, [&](const std::array<u64,3>& m635) {
                      u64 v_c154 = m635[2];
                      slog::join_probe<2,1>(mp_union_ansindex587, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m636) {
                        u64 v_c28 = m636[1];
                        u64 v_c155 = _prim_band(db, v_c8, v_c3);
                        if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c156 = _prim_lt(db, v_c155, v_c148);
                        if (v_c156 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c156) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c150, v_c28, v_c3, v_c2, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c28, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask589* _cont = new ReadTask589(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask589(db,b), false);
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mp_union __t38nk104 __t6XhK108 __t9OKP102) (body (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 1 __t38nk104) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 1 __t38nk104) (join-old mp_union (1 2 0) 1 (1 2 0) __t6XhK108 u __t109M109) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t38nk104 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t38nk104 u) (exists mp_union_ans (0 1) 1 __t109M109) (join mbranch (3 0 1 2 4) 2 u __t9OKP102 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t38nk104) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t38nk104 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6XhK108) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t38nk104 l m p r __t3jH2107) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (join mp_union_ans (0 1) 1 __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask659 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index638;  slog::Index** $sup5638x104x0x0x1index639;  slog::Index** mp_unionindex640;  slog::Index** $sup5638x104x0x0x0index641;  slog::Index** $sup5638x104x0x0x1index642;  slog::Index** mp_union_ansindex643;  slog::Index** mbranchindex644;  slog::Index** $sup5638x104x0x0x1index645;  slog::Index** mp_mskindex646;  slog::Index** mp_msk_ansindex647;  slog::Index** $sup5638x104x0x0x0index648;  slog::Index** mbranchindex649;  slog::Index** mp_mskindex650;  slog::Index** $sup5638x104x0x0x1index651;  slog::Index** mbranchindex652;  slog::Index** mp_mskindex653;  slog::Index** mp_msk_ansindex654;  slog::Index** mp_union_ansindex655;  slog::Index** mp_uniondelta656;  slog::Index** mbranchdelta657;  slog::Index** mp_mskdelta658;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord660({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel661 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index638 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel663 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index639 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("mp_union");
      mp_unionindex640 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("mp_union");
      mp_uniondelta656 = readrel667->getIndex(ord666, true);
      std::vector<u16> ord668({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel669 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index641 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel671 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index642 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1});
      slog::Relation* readrel673 = db->getRelation("mp_union_ans");
      mp_union_ansindex643 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({3, 0, 1, 2, 4});
      slog::Relation* readrel675 = db->getRelation("mbranch");
      mbranchindex644 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel677 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index645 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({2, 0, 1});
      slog::Relation* readrel679 = db->getRelation("mp_msk");
      mp_mskindex646 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 0});
      slog::Relation* readrel681 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex647 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel683 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index648 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 3, 4, 0});
      slog::Relation* readrel685 = db->getRelation("mbranch");
      mbranchindex649 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 0});
      slog::Relation* readrel687 = db->getRelation("mp_msk");
      mp_mskindex650 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel689 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index651 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 3, 4, 0});
      slog::Relation* readrel691 = db->getRelation("mbranch");
      mbranchindex652 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 3, 4, 0});
      slog::Relation* readrel693 = db->getRelation("mbranch");
      mbranchdelta657 = readrel693->getIndex(ord692, true);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("mp_msk");
      mp_mskindex653 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 0});
      slog::Relation* readrel697 = db->getRelation("mp_msk");
      mp_mskdelta658 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex654 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1});
      slog::Relation* readrel701 = db->getRelation("mp_union_ans");
      mp_union_ansindex655 = readrel701->getIndex(ord700, false);
  
    }
    ReadTask659(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c150 = _t[0];
        u64 v_c149 = _t[1];
        u64 v_c153 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index638, std::array<u64,9>{v_c150, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index639, std::array<u64,10>{v_c150, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex640, mp_uniondelta656, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m702) {
          u64 v_c4 = m702[1]; u64 v_c154 = m702[2];
          if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index641, std::array<u64,9>{v_c150, v_c4, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index642, std::array<u64,10>{v_c150, v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex643, std::array<u64,2>{v_c154, 0})) return;
          slog::join_probe<5,2>(mbranchindex644, std::array<u64,5>{v_c4, v_c153, 0, 0, 0}, [&](const std::array<u64,5>& m703) {
            u64 v_c2 = m703[2]; u64 v_c3 = m703[3]; u64 v_c5 = m703[4];
            if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index645, std::array<u64,10>{v_c4, v_c3, v_c2, v_c5, v_c150, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex646, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex647, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<9,5>($sup5638x104x0x0x0index648, std::array<u64,9>{v_c2, v_c3, v_c4, v_c5, v_c150, 0, 0, 0, 0}, [&](const std::array<u64,9>& m704) {
              u64 v_c10 = m704[5]; u64 v_c9 = m704[6]; u64 v_c8 = m704[7]; u64 v_c11 = m704[8];
              u64 v_c157 = _prim_lt(db, v_c9, v_c3);
              if (v_c157 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
              if (!v_c157) return;
              if (!slog::exists_probe<5,5>(mbranchindex649, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c149})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex650, std::array<u64,3>{v_c8, v_c3, 0})) return;
              slog::join_probe<10,9>($sup5638x104x0x0x1index651, std::array<u64,10>{v_c4, v_c3, v_c2, v_c5, v_c150, v_c10, v_c9, v_c8, v_c11, 0}, [&](const std::array<u64,10>& m706) {
                u64 v_c152 = m706[9];
                slog::join_probe_old<5,5>(mbranchindex652, mbranchdelta657, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, v_c149}, [&](const std::array<u64,5>& m707) {
                  slog::join_probe_old<3,3>(mp_mskindex653, mp_mskdelta658, std::array<u64,3>{v_c8, v_c3, v_c152}, [&](const std::array<u64,3>& m708) {
                    slog::join_probe<2,2>(mp_msk_ansindex654, std::array<u64,2>{v_c152, v_c2}, [&](const std::array<u64,2>& m709) {
                      slog::join_probe<2,1>(mp_union_ansindex655, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m710) {
                        u64 v_c28 = m710[1];
                        u64 v_c155 = _prim_band(db, v_c8, v_c3);
                        if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c158 = _prim_lt(db, v_c155, v_c148);
                        if (v_c158 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c158) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c150, v_c28, v_c3, v_c2, v_c5});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c28, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask659* _cont = new ReadTask659(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask659(db,b), false);
  // (crule (pre (let __tconst6PdE830 constd01925b37634a1a9d24159d8) (let __tconst4TD6412 constff5a1ae012afa5d4c889c50a) (let __tconst93JF413 const7902699be42c8a8e46fbbb45) (let __tconst1wzT410 const624b60c58c9d8bfb6ff1886c) (let __tconst98iL411 const4e07408562bedb8b60ce05c1)) (scan mp_put_ans __t33kH415 __v0) (body (exists _enum (1 0) 1 __tconst6PdE830) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst93JF413 __tconst4TD6412 __t33kH415 __t0LaQ414) (join _enum (0 1) 2 __t0LaQ414 __tconst6PdE830)) (head (mkstruct mp_put (1 2 3 0) __5VOt831 __v0 __tconst98iL411 __tconst1wzT410)) mp_basic.slog:14 #f)
  class ReadTask716 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex712;  slog::Index** mp_putindex713;  slog::Index** _enumindex714;  slog::Index** mp_putdelta715;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord717({1, 0});
      slog::Relation* readrel718 = db->getRelation("_enum");
      _enumindex712 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({2, 3, 0, 1});
      slog::Relation* readrel720 = db->getRelation("mp_put");
      mp_putindex713 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({2, 3, 0, 1});
      slog::Relation* readrel722 = db->getRelation("mp_put");
      mp_putdelta715 = readrel722->getIndex(ord721, true);
      std::vector<u16> ord723({0, 1});
      slog::Relation* readrel724 = db->getRelation("_enum");
      _enumindex714 = readrel724->getIndex(ord723, false);
  
    }
    ReadTask716(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c159 = v_constd01925b37634a1a9d24159d8;
      u64 v_c160 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c161 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c162 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c163 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c164 = _t[0];
        u64 v_c28 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex712, std::array<u64,2>{v_c159, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex713, mp_putdelta715, std::array<u64,4>{v_c161, v_c160, v_c164, 0}, [&](const std::array<u64,4>& m725) {
          u64 v_c165 = m725[3];
          slog::join_probe<2,2>(_enumindex714, std::array<u64,2>{v_c165, v_c159}, [&](const std::array<u64,2>& m726) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c28, v_c163, v_c162}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask716* _cont = new ReadTask716(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask716(db,b), false);
  // (crule (pre (let __trid992U617 const5f7e60cb3d02e4170101c2bc) (let __trel9tWF618 constdd7bbf31ce5f578b9805e840) (let __tcol80vF619 const5feceb66ffc86f38d952786c) (let __trel6UQh620 constdd7bbf31ce5f578b9805e840) (let __tcol0kCD621 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid992U617 __trel9tWF618 __tcol80vF619 (1 2 3 4 0)) (tycheck n (accept int) __trid992U617 __trel6UQh620 __tcol0kCD621 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __82oc616 p n)) map.slog:105 #f)
  class ReadTask727 : public slog::Task
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
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x104x0x0x0");
  
    }
    ReadTask727(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c166 = v_const5f7e60cb3d02e4170101c2bc;
      u64 v_c167 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c168 = v_const5feceb66ffc86f38d952786c;
      u64 v_c169 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c20 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c11 = _t[6];
        u64 v_c4 = _t[7];
        u64 v_c5 = _t[8];
        ++_fires;
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c166, v_c167, v_c168, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c166, v_c169, v_c170, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask727* _cont = new ReadTask727(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask727(db,b), false);
  // (crule (pre) (scan mleaf __t8QAC212 k v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t8QAC212 __t0116213 s)) (head (mkstruct mp_put_soft (1 2 3 0) __1yRr795 s k v)) map.slog:93 #f)
  class ReadTask730 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex728;  slog::Index** mp_uniondelta729;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord731({2, 0, 1});
      slog::Relation* readrel732 = db->getRelation("mp_union");
      mp_unionindex728 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({2, 0, 1});
      slog::Relation* readrel734 = db->getRelation("mp_union");
      mp_uniondelta729 = readrel734->getIndex(ord733, true);
  
    }
    ReadTask730(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c171 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe_old<3,1>(mp_unionindex728, mp_uniondelta729, std::array<u64,3>{v_c171, 0, 0}, [&](const std::array<u64,3>& m735) {
          u64 v_c172 = m735[1]; u64 v_c173 = m735[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c173, v_c21, v_c5}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask730* _cont = new ReadTask730(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask730(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t61OZ179 p) (body (exists $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t61OZ179 q m) (join $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t61OZ179 l m n p q u v)) map.slog:99 #f)
  class ReadTask740 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index736;  slog::Index** mp_mskindex737;  slog::Index** $sup5638x98x0x0x0index738;  slog::Index** mp_mskdelta739;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord741({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel742 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel742->getIndex(ord741, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord743({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel744 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index736 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({0, 1, 2});
      slog::Relation* readrel746 = db->getRelation("mp_msk");
      mp_mskindex737 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({0, 1, 2});
      slog::Relation* readrel748 = db->getRelation("mp_msk");
      mp_mskdelta739 = readrel748->getIndex(ord747, true);
      std::vector<u16> ord749({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel750 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index738 = readrel750->getIndex(ord749, false);
  
    }
    ReadTask740(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c174 = _t[0];
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index736, std::array<u64,9>{v_c8, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex737, mp_mskdelta739, std::array<u64,3>{v_c174, 0, 0}, [&](const std::array<u64,3>& m751) {
          u64 v_c2 = m751[1]; u64 v_c9 = m751[2];
          slog::join_probe<9,3>($sup5638x98x0x0x0index738, std::array<u64,9>{v_c9, v_c2, v_c8, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m752) {
            u64 v_c20 = m752[3]; u64 v_c10 = m752[4]; u64 v_c3 = m752[5]; u64 v_c11 = m752[6]; u64 v_c4 = m752[7]; u64 v_c5 = m752[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c20, v_c11, v_c174, v_c10, v_c9, v_c3, v_c8, v_c2, v_c4, v_c5}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask740* _cont = new ReadTask740(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask740(db,b), false);
  // (crule (pre (let __tconst1GO9299 const5feceb66ffc86f38d952786c)) (scan mp_msk __t6Y68302 k m) (body (exists $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t6Y68302 __v0) (join $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 k m __t0IP7301 l p r) (neq p __v0) (exists mp_has0 (0 2 1) 2 __t0IP7301 k) (join mbranch (1 2 3 4 0) 4 p m l r __t8ocD300) (join mp_has0 (0 2 1) 3 __t0IP7301 k __t8ocD300)) (head (emit mp_has0_ans (0 1) __t0IP7301 __tconst1GO9299)) map.slog:60 #f)
  class ReadTask761 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x59x0x0x0index753;  slog::Index** mbranchindex754;  slog::Index** mp_has0index755;  slog::Index** mp_msk_ansindex756;  slog::Index** $sup5638x59x0x0x0index757;  slog::Index** mp_has0index758;  slog::Index** mbranchindex759;  slog::Index** mp_has0index760;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel763->getIndex(ord762, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord764({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel765 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index753 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({2, 0, 1, 3, 4});
      slog::Relation* readrel767 = db->getRelation("mbranch");
      mbranchindex754 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({2, 0, 1});
      slog::Relation* readrel769 = db->getRelation("mp_has0");
      mp_has0index755 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1});
      slog::Relation* readrel771 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex756 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel773 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index757 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 2, 1});
      slog::Relation* readrel775 = db->getRelation("mp_has0");
      mp_has0index758 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 3, 4, 0});
      slog::Relation* readrel777 = db->getRelation("mbranch");
      mbranchindex759 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 2, 1});
      slog::Relation* readrel779 = db->getRelation("mp_has0");
      mp_has0index760 = readrel779->getIndex(ord778, false);
  
    }
    ReadTask761(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c107 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x59x0x0x0index753, std::array<u64,6>{v_c21, v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex754, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index755, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex756, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m780) {
          u64 v_c28 = m780[1];
          slog::join_probe<6,2>($sup5638x59x0x0x0index757, std::array<u64,6>{v_c21, v_c9, 0, 0, 0, 0}, [&](const std::array<u64,6>& m781) {
            u64 v_c106 = m781[2]; u64 v_c10 = m781[3]; u64 v_c8 = m781[4]; u64 v_c11 = m781[5];
            if (v_c8 == v_c28) return;
            if (!slog::exists_probe<3,2>(mp_has0index758, std::array<u64,3>{v_c106, v_c21, 0})) return;
            slog::join_probe<5,4>(mbranchindex759, std::array<u64,5>{v_c8, v_c9, v_c10, v_c11, 0}, [&](const std::array<u64,5>& m782) {
              u64 v_c105 = m782[4];
              slog::join_probe<3,3>(mp_has0index760, std::array<u64,3>{v_c106, v_c21, v_c105}, [&](const std::array<u64,3>& m783) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c106, v_c104}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask761* _cont = new ReadTask761(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask761(db,b), false);
}

