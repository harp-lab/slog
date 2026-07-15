
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const8c1f1046219ddd216a023f79;
extern u64 v_consta2d3b5b64cd0c50598de1133;
extern u64 v_constc99bf3037b4c2fce0fbaab85;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c692e503ff718572d(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid8smo839 consta2d3b5b64cd0c50598de1133) (let __trel3c98840 const3a655602588fe6d8c59d4a5a) (let __tcol6tVr841 const5feceb66ffc86f38d952786c) (let __trel4L3c842 const3a655602588fe6d8c59d4a5a) (let __tcol7ZfW843 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8smo839 __trel3c98840 __tcol6tVr841 (1 2 3 4 0)) (tycheck k (accept int) __trid8smo839 __trel4L3c842 __tcol7ZfW843 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __6hMm838 l k)) map.slog:61 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1;  u32 sid0;  u32 sid2;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("mbranch")->getStructId();
      sid2 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_consta2d3b5b64cd0c50598de1133;
      u64 v_c1 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const3a655602588fe6d8c59d4a5a;
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
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid0 || decode_struct_id(v_c7) == sid1 || decode_struct_id(v_c7) == sid2))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c7, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t0yI380 __v0) (body (exists mp_put (1 2 3 0) 3 __v0 __tconst35sq82 __tconst2cGK81) (exists _enum (1 0) 1 __tconst03sd851) (exists mp_put (2 3 0 1) 2 __tconst2ARJ85 __tconst4DUy84) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (exists _enum (0 1) 2 __t0J6w79 __tconst03sd851) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __v0 __tconst35sq82 __tconst2cGK81 __t1P9g83) (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (exists mp_put_ans (0 1) 1 __t1P9g83) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst2ARJ85 __tconst4DUy84 __t9RS986 __v1) (join-old mp_put_ans (0 1) 2 (0 1) __t1P9g83 __v1) (join-old mp_put_ans (0 1) 1 (0 1) __t9RS986 r)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex4;  slog::Index** _enumindex5;  slog::Index** mp_putindex6;  slog::Index** mp_putindex7;  slog::Index** _enumindex8;  slog::Index** mp_putindex9;  slog::Index** _enumindex10;  slog::Index** mp_put_ansindex11;  slog::Index** mp_putindex12;  slog::Index** mp_put_ansindex13;  slog::Index** mp_put_ansindex14;  slog::Index** mp_putdelta15;  slog::Index** mp_putdelta16;  slog::Index** mp_putdelta17;  slog::Index** mp_put_ansdelta18;  slog::Index** mp_put_ansdelta19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("canon");
      head_index[0] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord23({1, 2, 3, 0});
      slog::Relation* readrel24 = db->getRelation("mp_put");
      mp_putindex4 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("_enum");
      _enumindex5 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({2, 3, 0, 1});
      slog::Relation* readrel28 = db->getRelation("mp_put");
      mp_putindex6 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 3, 0, 1});
      slog::Relation* readrel30 = db->getRelation("mp_put");
      mp_putindex7 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({2, 3, 0, 1});
      slog::Relation* readrel32 = db->getRelation("mp_put");
      mp_putdelta15 = readrel32->getIndex(ord31, true);
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("_enum");
      _enumindex8 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 3, 0});
      slog::Relation* readrel36 = db->getRelation("mp_put");
      mp_putindex9 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 3, 0});
      slog::Relation* readrel38 = db->getRelation("mp_put");
      mp_putdelta16 = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("_enum");
      _enumindex10 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("mp_put_ans");
      mp_put_ansindex11 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({2, 3, 0, 1});
      slog::Relation* readrel44 = db->getRelation("mp_put");
      mp_putindex12 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({2, 3, 0, 1});
      slog::Relation* readrel46 = db->getRelation("mp_put");
      mp_putdelta17 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("mp_put_ans");
      mp_put_ansindex13 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("mp_put_ans");
      mp_put_ansdelta18 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("mp_put_ans");
      mp_put_ansindex14 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("mp_put_ans");
      mp_put_ansdelta19 = readrel54->getIndex(ord53, true);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constd01925b37634a1a9d24159d8;
      u64 v_c12 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c13 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c14 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
  
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
        if (!slog::exists_probe<4,3>(mp_putindex4, std::array<u64,4>{v_c19, v_c15, v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex5, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex6, std::array<u64,4>{v_c17, v_c16, 0, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex7, mp_putdelta15, std::array<u64,4>{v_c13, v_c12, v_c18, 0}, [&](const std::array<u64,4>& m55) {
          u64 v_c20 = m55[3];
          if (!slog::exists_probe<2,2>(_enumindex8, std::array<u64,2>{v_c20, v_c11})) return;
          slog::join_probe_old<4,3>(mp_putindex9, mp_putdelta16, std::array<u64,4>{v_c19, v_c15, v_c14, 0}, [&](const std::array<u64,4>& m56) {
            u64 v_c21 = m56[3];
            slog::join_probe<2,2>(_enumindex10, std::array<u64,2>{v_c20, v_c11}, [&](const std::array<u64,2>& m57) {
              if (!slog::exists_probe<2,1>(mp_put_ansindex11, std::array<u64,2>{v_c21, 0})) return;
              slog::join_probe_old<4,2>(mp_putindex12, mp_putdelta17, std::array<u64,4>{v_c17, v_c16, 0, 0}, [&](const std::array<u64,4>& m58) {
                u64 v_c22 = m58[2]; u64 v_c23 = m58[3];
                slog::join_probe_old<2,2>(mp_put_ansindex13, mp_put_ansdelta18, std::array<u64,2>{v_c21, v_c23}, [&](const std::array<u64,2>& m59) {
                  slog::join_probe_old<2,1>(mp_put_ansindex14, mp_put_ansdelta19, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m60) {
                    u64 v_c10 = m60[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c10}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put_ans", _fires);
  
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
  // (crule (pre) (scan $sup5638x107x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 q) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5usA297) (join-old mp_msk_ans (0 1) 2 (0 1) __t5usA297 q)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t5usA297 l m n p q r u)) map.slog:108 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex61;  slog::Index** mp_mskindex62;  slog::Index** mp_msk_ansindex63;  slog::Index** mp_mskdelta64;  slog::Index** mp_msk_ansdelta65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord67({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel68 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex61 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("mp_msk");
      mp_mskindex62 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("mp_msk");
      mp_mskdelta64 = readrel74->getIndex(ord73, true);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex63 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta65 = readrel78->getIndex(ord77, true);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c25 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c26 = _t[7];
        u64 v_c27 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex61, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex62, mp_mskdelta64, std::array<u64,3>{v_c9, v_c24, 0}, [&](const std::array<u64,3>& m79) {
          u64 v_c28 = m79[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex63, mp_msk_ansdelta65, std::array<u64,2>{v_c28, v_c25}, [&](const std::array<u64,2>& m80) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c5, v_c27, v_c28, v_c7, v_c8, v_c24, v_c9, v_c25, v_c10, v_c26}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mbranch __t499t48 q n u v) (body (exists $sup5638x95x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists mp_union (2 0 1) 1 __t499t48) (exists mp_msk (1 2 0) 1 q) (join $sup5638x95x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t0mSQ44 l m p r) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t499t48 __t0mSQ44) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 2 l __t499t48) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t0mSQ44 n q u v __t0xN947) (exists mp_msk (1 2 0) 3 q m __t0xN947) (exists mp_msk_ans (0 1) 2 __t0xN947 p) (join mbranch (1 2 3 4 0) 4 p m l r __t39oH43) (join mp_union (0 1 2) 3 __t0mSQ44 __t39oH43 __t499t48) (join mp_msk (1 2 0) 3 q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index81;  slog::Index** mp_unionindex82;  slog::Index** mp_mskindex83;  slog::Index** $sup5638x95x0x0x0index84;  slog::Index** mbranchindex85;  slog::Index** mp_unionindex86;  slog::Index** mp_mskindex87;  slog::Index** mp_msk_ansindex88;  slog::Index** mp_unionindex89;  slog::Index** $sup5638x95x0x0x1index90;  slog::Index** mp_mskindex91;  slog::Index** mp_msk_ansindex92;  slog::Index** mbranchindex93;  slog::Index** mp_unionindex94;  slog::Index** mp_mskindex95;  slog::Index** mp_msk_ansindex96;  slog::Index** mp_unionindex97;  slog::Index** mp_union_ansindex98;  slog::Index** mp_uniondelta99;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord101({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel102 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index81 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({2, 0, 1});
      slog::Relation* readrel104 = db->getRelation("mp_union");
      mp_unionindex82 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("mp_msk");
      mp_mskindex83 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel108 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index84 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 3, 4, 0});
      slog::Relation* readrel110 = db->getRelation("mbranch");
      mbranchindex85 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({2, 0, 1});
      slog::Relation* readrel112 = db->getRelation("mp_union");
      mp_unionindex86 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("mp_msk");
      mp_mskindex87 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 0});
      slog::Relation* readrel116 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex88 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 0});
      slog::Relation* readrel118 = db->getRelation("mp_union");
      mp_unionindex89 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel120 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index90 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("mp_msk");
      mp_mskindex91 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex92 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 3, 4, 0});
      slog::Relation* readrel126 = db->getRelation("mbranch");
      mbranchindex93 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1, 2});
      slog::Relation* readrel128 = db->getRelation("mp_union");
      mp_unionindex94 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({1, 2, 0});
      slog::Relation* readrel130 = db->getRelation("mp_msk");
      mp_mskindex95 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex96 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 0});
      slog::Relation* readrel134 = db->getRelation("mp_union");
      mp_unionindex97 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 0});
      slog::Relation* readrel136 = db->getRelation("mp_union");
      mp_uniondelta99 = readrel136->getIndex(ord135, true);
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("mp_union_ans");
      mp_union_ansindex98 = readrel138->getIndex(ord137, false);
  
    }
    ReadTask100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x95x0x0x1index81, std::array<u64,10>{v_c24, v_c25, v_c26, v_c27, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex82, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex83, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x95x0x0x0index84, std::array<u64,9>{v_c24, v_c25, v_c26, v_c27, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m139) {
          u64 v_c31 = m139[4]; u64 v_c7 = m139[5]; u64 v_c8 = m139[6]; u64 v_c9 = m139[7]; u64 v_c10 = m139[8];
          u64 v_c32 = _prim_lt(db, v_c24, v_c8);
          if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c32) return;
          if (!slog::exists_probe<5,4>(mbranchindex85, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex86, std::array<u64,3>{v_c30, v_c31, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex87, std::array<u64,3>{v_c25, v_c8, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex88, std::array<u64,2>{v_c9, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex89, std::array<u64,3>{v_c7, v_c30, 0})) return;
          slog::join_probe<10,9>($sup5638x95x0x0x1index90, std::array<u64,10>{v_c7, v_c8, v_c9, v_c10, v_c31, v_c24, v_c25, v_c26, v_c27, 0}, [&](const std::array<u64,10>& m141) {
            u64 v_c33 = m141[9];
            if (!slog::exists_probe<3,3>(mp_mskindex91, std::array<u64,3>{v_c25, v_c8, v_c33})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex92, std::array<u64,2>{v_c33, v_c9})) return;
            slog::join_probe<5,4>(mbranchindex93, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m142) {
              u64 v_c34 = m142[4];
              slog::join_probe<3,3>(mp_unionindex94, std::array<u64,3>{v_c31, v_c34, v_c30}, [&](const std::array<u64,3>& m143) {
                slog::join_probe<3,3>(mp_mskindex95, std::array<u64,3>{v_c25, v_c8, v_c33}, [&](const std::array<u64,3>& m144) {
                  slog::join_probe<2,2>(mp_msk_ansindex96, std::array<u64,2>{v_c33, v_c9}, [&](const std::array<u64,2>& m145) {
                    slog::join_probe_old<3,2>(mp_unionindex97, mp_uniondelta99, std::array<u64,3>{v_c7, v_c30, 0}, [&](const std::array<u64,3>& m146) {
                      u64 v_c35 = m146[2];
                      slog::join_probe<2,1>(mp_union_ansindex98, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m147) {
                        u64 v_c19 = m147[1];
                        u64 v_c36 = _prim_band(db, v_c25, v_c8);
                        if (v_c36 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c37 = _prim_lt(db, v_c36, v_c29);
                        if (v_c37 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c37) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c19, v_c8, v_c9, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c19, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask100* _cont = new ReadTask100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask100(db,b), false);
  // (crule (pre) (scan temp0EGL1024 l n q u v) (body (join mbranch (1 2 3 4 0) 4 q n u v __t62ZT317)) (head (mkstruct mp_union (1 2 0) __8YWO584 l __t62ZT317)) map.slog:96 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp0EGL1024");
      std::vector<u16> ord151({1, 2, 3, 4, 0});
      slog::Relation* readrel152 = db->getRelation("mbranch");
      mbranchindex149 = readrel152->getIndex(ord151, false);
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        slog::join_probe<5,4>(mbranchindex149, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0}, [&](const std::array<u64,5>& m153) {
          u64 v_c38 = m153[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c38}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:temp0EGL1024", _fires);
  
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
  // (crule (pre) (scan mp_join_ans __t9vyw431 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t9vyw431 k __t9k3L430 p __t51uB429) (exists mp_put (1 2 0 3) 2 __t51uB429 k) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 3 k p __t51uB429) (exists mbranch (0 1 2 3 4) 2 __t51uB429 p) (exists mp_msk (1 2 0) 1 k) (join-old mleaf (0 1 2) 2 (0 1 2) __t9k3L430 k v) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 4 k p __t51uB429 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __t51uB429 k v __t5vsG428) (join-old $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 5 (1 7 0 6 4 2 3 5) k v __t5vsG428 __t51uB429 p l m r) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t51uB429) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join-old mp_msk_ans (0 1) 1 (0 1) __t6MG8432 __v0) (neq p __v0)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask173 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex154;  slog::Index** mp_putindex155;  slog::Index** $sup5638x44x0x0x0index156;  slog::Index** mbranchindex157;  slog::Index** mp_mskindex158;  slog::Index** mleafindex159;  slog::Index** $sup5638x44x0x0x0index160;  slog::Index** mp_putindex161;  slog::Index** $sup5638x44x0x0x0index162;  slog::Index** mbranchindex163;  slog::Index** mp_mskindex164;  slog::Index** mp_msk_ansindex165;  slog::Index** mp_joindelta166;  slog::Index** mleafdelta167;  slog::Index** mp_putdelta168;  slog::Index** $sup5638x44x0x0x0delta169;  slog::Index** mbranchdelta170;  slog::Index** mp_mskdelta171;  slog::Index** mp_msk_ansdelta172;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord174({0, 1});
      slog::Relation* readrel175 = db->getRelation("mp_put_ans");
      head_index[0] = readrel175->getIndex(ord174, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord176({0, 1, 2, 3, 4});
      slog::Relation* readrel177 = db->getRelation("mp_join");
      mp_joinindex154 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({0, 1, 2, 3, 4});
      slog::Relation* readrel179 = db->getRelation("mp_join");
      mp_joindelta166 = readrel179->getIndex(ord178, true);
      std::vector<u16> ord180({1, 2, 0, 3});
      slog::Relation* readrel181 = db->getRelation("mp_put");
      mp_putindex155 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel183 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index156 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 1, 2, 3, 4});
      slog::Relation* readrel185 = db->getRelation("mbranch");
      mbranchindex157 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("mp_msk");
      mp_mskindex158 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1, 2});
      slog::Relation* readrel189 = db->getRelation("mleaf");
      mleafindex159 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1, 2});
      slog::Relation* readrel191 = db->getRelation("mleaf");
      mleafdelta167 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel193 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index160 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 3, 0});
      slog::Relation* readrel195 = db->getRelation("mp_put");
      mp_putindex161 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 3, 0});
      slog::Relation* readrel197 = db->getRelation("mp_put");
      mp_putdelta168 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel199 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index162 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel201 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0delta169 = readrel201->getIndex(ord200, true);
      std::vector<u16> ord202({1, 2, 3, 4, 0});
      slog::Relation* readrel203 = db->getRelation("mbranch");
      mbranchindex163 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 3, 4, 0});
      slog::Relation* readrel205 = db->getRelation("mbranch");
      mbranchdelta170 = readrel205->getIndex(ord204, true);
      std::vector<u16> ord206({1, 2, 0});
      slog::Relation* readrel207 = db->getRelation("mp_msk");
      mp_mskindex164 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 2, 0});
      slog::Relation* readrel209 = db->getRelation("mp_msk");
      mp_mskdelta171 = readrel209->getIndex(ord208, true);
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex165 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1});
      slog::Relation* readrel213 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta172 = readrel213->getIndex(ord212, true);
  
    }
    ReadTask173(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<5,1>(mp_joinindex154, mp_joindelta166, std::array<u64,5>{v_c39, 0, 0, 0, 0}, [&](const std::array<u64,5>& m214) {
          u64 v_c6 = m214[1]; u64 v_c41 = m214[2]; u64 v_c9 = m214[3]; u64 v_c42 = m214[4];
          if (!slog::exists_probe<4,2>(mp_putindex155, std::array<u64,4>{v_c42, v_c6, 0, 0})) return;
          if (!slog::exists_probe<8,3>($sup5638x44x0x0x0index156, std::array<u64,8>{v_c6, v_c9, v_c42, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex157, std::array<u64,5>{v_c42, v_c9, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex158, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex159, mleafdelta167, std::array<u64,3>{v_c41, v_c6, 0}, [&](const std::array<u64,3>& m215) {
            u64 v_c27 = m215[2];
            if (!slog::exists_probe<8,4>($sup5638x44x0x0x0index160, std::array<u64,8>{v_c6, v_c9, v_c42, v_c27, 0, 0, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex161, mp_putdelta168, std::array<u64,4>{v_c42, v_c6, v_c27, 0}, [&](const std::array<u64,4>& m216) {
              u64 v_c43 = m216[3];
              slog::join_probe_old<8,5>($sup5638x44x0x0x0index162, $sup5638x44x0x0x0delta169, std::array<u64,8>{v_c6, v_c27, v_c43, v_c42, v_c9, 0, 0, 0}, [&](const std::array<u64,8>& m217) {
                u64 v_c7 = m217[5]; u64 v_c8 = m217[6]; u64 v_c10 = m217[7];
                slog::join_probe_old<5,5>(mbranchindex163, mbranchdelta170, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c42}, [&](const std::array<u64,5>& m218) {
                  slog::join_probe_old<3,2>(mp_mskindex164, mp_mskdelta171, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m219) {
                    u64 v_c44 = m219[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex165, mp_msk_ansdelta172, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m220) {
                      u64 v_c19 = m220[1];
                      if (v_c9 == v_c19) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c40}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_join_ans", _fires);
  
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
  // (crule (pre (let __tconst0HVn828 constd01925b37634a1a9d24159d8) (let __tconst9FbD307 const8c1f1046219ddd216a023f79) (let __tconst465U308 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t0rdB310 s) (body (exists _enum (1 0) 1 __tconst0HVn828) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst465U308 __tconst9FbD307 __t0rdB310 __t3qgX309) (join _enum (0 1) 2 __t3qgX309 __tconst0HVn828) (join canon (0) 0 m)) (head (mkstruct mp_union (1 2 0) __4LkF829 s m)) mp_basic.slog:23 #f)
  class ReadTask226 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex221;  slog::Index** mp_putindex222;  slog::Index** _enumindex223;  slog::Index** canonindex224;  slog::Index** mp_putdelta225;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("_enum");
      _enumindex221 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({2, 3, 0, 1});
      slog::Relation* readrel230 = db->getRelation("mp_put");
      mp_putindex222 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({2, 3, 0, 1});
      slog::Relation* readrel232 = db->getRelation("mp_put");
      mp_putdelta225 = readrel232->getIndex(ord231, true);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("_enum");
      _enumindex223 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0});
      slog::Relation* readrel236 = db->getRelation("canon");
      canonindex224 = readrel236->getIndex(ord235, false);
  
    }
    ReadTask226(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_constd01925b37634a1a9d24159d8;
      u64 v_c46 = v_const8c1f1046219ddd216a023f79;
      u64 v_c47 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex221, std::array<u64,2>{v_c45, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex222, mp_putdelta225, std::array<u64,4>{v_c47, v_c46, v_c48, 0}, [&](const std::array<u64,4>& m237) {
          u64 v_c50 = m237[3];
          slog::join_probe<2,2>(_enumindex223, std::array<u64,2>{v_c50, v_c45}, [&](const std::array<u64,2>& m238) {
            slog::join_all<1>(canonindex224, [&](const std::array<u64,1>& m239) {
              u64 v_c8 = m239[0];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c49, v_c8}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:23", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask226* _cont = new ReadTask226(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask226(db,b), false);
  // (crule (pre) (scan temp5R2q1072 __t5dUf162 j k v) (body (join mleaf (1 2 0) 2 k v __t7RTp161)) (head (mkstruct mp_join (1 2 3 4 0) __0WDS635 k __t7RTp161 j __t5dUf162)) map.slog:39 #f)
  class ReadTask241 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex240;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("temp5R2q1072");
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("mleaf");
      mleafindex240 = readrel243->getIndex(ord242, false);
  
    }
    ReadTask241(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[2];
        u64 v_c27 = _t[3];
        slog::join_probe<3,2>(mleafindex240, std::array<u64,3>{v_c6, v_c27, 0}, [&](const std::array<u64,3>& m244) {
          u64 v_c53 = m244[2];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c53, v_c52, v_c51}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:temp5R2q1072", _fires);
  
      if (!_done)
      {
        ReadTask241* _cont = new ReadTask241(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask241(db,b), false);
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (scan mp_put __t4H3I279 t k v) (body (exists mp_put_soft (1 2 3 0) 3 t k v) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst6EKe278) (exists mp_put_ans (0 1) 1 __t4H3I279) (join $sup5638x68x0x0x0 (1 2 3 0) 3 k t v __t2Eey276) (join mp_put_soft (1 2 3 0) 4 t k v __t2Eey276) (join mp_has0 (1 2 0) 2 t k __t16yQ277) (join mp_has0_ans (0 1) 2 __t16yQ277 __tconst6EKe278) (join mp_put_ans (0 1) 1 __t4H3I279 r)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex245;  slog::Index** mp_has0index246;  slog::Index** mp_has0_ansindex247;  slog::Index** mp_put_ansindex248;  slog::Index** $sup5638x68x0x0x0index249;  slog::Index** mp_put_softindex250;  slog::Index** mp_has0index251;  slog::Index** mp_has0_ansindex252;  slog::Index** mp_put_ansindex253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord255({0, 1});
      slog::Relation* readrel256 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel256->getIndex(ord255, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord257({1, 2, 3, 0});
      slog::Relation* readrel258 = db->getRelation("mp_put_soft");
      mp_put_softindex245 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("mp_has0");
      mp_has0index246 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex247 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("mp_put_ans");
      mp_put_ansindex248 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 3, 0});
      slog::Relation* readrel266 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index249 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 3, 0});
      slog::Relation* readrel268 = db->getRelation("mp_put_soft");
      mp_put_softindex250 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("mp_has0");
      mp_has0index251 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({0, 1});
      slog::Relation* readrel272 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex252 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 1});
      slog::Relation* readrel274 = db->getRelation("mp_put_ans");
      mp_put_ansindex253 = readrel274->getIndex(ord273, false);
  
    }
    ReadTask254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c6 = _t[2];
        u64 v_c27 = _t[3];
        if (!slog::exists_probe<4,3>(mp_put_softindex245, std::array<u64,4>{v_c56, v_c6, v_c27, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index246, std::array<u64,3>{v_c56, v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(mp_has0_ansindex247, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex248, std::array<u64,2>{v_c55, 0})) return;
        slog::join_probe<4,3>($sup5638x68x0x0x0index249, std::array<u64,4>{v_c6, v_c56, v_c27, 0}, [&](const std::array<u64,4>& m275) {
          u64 v_c57 = m275[3];
          slog::join_probe<4,4>(mp_put_softindex250, std::array<u64,4>{v_c56, v_c6, v_c27, v_c57}, [&](const std::array<u64,4>& m276) {
            slog::join_probe<3,2>(mp_has0index251, std::array<u64,3>{v_c56, v_c6, 0}, [&](const std::array<u64,3>& m277) {
              u64 v_c58 = m277[2];
              slog::join_probe<2,2>(mp_has0_ansindex252, std::array<u64,2>{v_c58, v_c54}, [&](const std::array<u64,2>& m278) {
                slog::join_probe<2,1>(mp_put_ansindex253, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m279) {
                  u64 v_c10 = m279[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c10}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put", _fires);
  
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
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x1 __t0mSQ44 __t0xN947 l m n p q r u v) (body (cmp lt n m) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t0mSQ44 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 3 q m __t0xN947) (exists mp_msk_ans (0 1) 2 __t0xN947 p) (exists mp_union (1 2 0) 1 l) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t39oH43) (exists mp_union (0 1 2) 2 __t0mSQ44 __t39oH43) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t499t48) (join-old mp_union (0 1 2) 3 (0 1 2) __t0mSQ44 __t39oH43 __t499t48) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index280;  slog::Index** mbranchindex281;  slog::Index** mp_mskindex282;  slog::Index** mp_msk_ansindex283;  slog::Index** mp_unionindex284;  slog::Index** mbranchindex285;  slog::Index** mp_unionindex286;  slog::Index** mbranchindex287;  slog::Index** mp_unionindex288;  slog::Index** mp_mskindex289;  slog::Index** mp_msk_ansindex290;  slog::Index** mp_unionindex291;  slog::Index** mp_union_ansindex292;  slog::Index** mbranchdelta293;  slog::Index** mbranchdelta294;  slog::Index** mp_uniondelta295;  slog::Index** mp_mskdelta296;  slog::Index** mp_uniondelta297;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord299({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel300 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index280 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 3, 4, 0});
      slog::Relation* readrel302 = db->getRelation("mbranch");
      mbranchindex281 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("mp_msk");
      mp_mskindex282 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 1});
      slog::Relation* readrel306 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex283 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("mp_union");
      mp_unionindex284 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 2, 3, 4, 0});
      slog::Relation* readrel310 = db->getRelation("mbranch");
      mbranchindex285 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({1, 2, 3, 4, 0});
      slog::Relation* readrel312 = db->getRelation("mbranch");
      mbranchdelta293 = readrel312->getIndex(ord311, true);
      std::vector<u16> ord313({0, 1, 2});
      slog::Relation* readrel314 = db->getRelation("mp_union");
      mp_unionindex286 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 2, 3, 4, 0});
      slog::Relation* readrel316 = db->getRelation("mbranch");
      mbranchindex287 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 3, 4, 0});
      slog::Relation* readrel318 = db->getRelation("mbranch");
      mbranchdelta294 = readrel318->getIndex(ord317, true);
      std::vector<u16> ord319({0, 1, 2});
      slog::Relation* readrel320 = db->getRelation("mp_union");
      mp_unionindex288 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1, 2});
      slog::Relation* readrel322 = db->getRelation("mp_union");
      mp_uniondelta295 = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({1, 2, 0});
      slog::Relation* readrel324 = db->getRelation("mp_msk");
      mp_mskindex289 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("mp_msk");
      mp_mskdelta296 = readrel326->getIndex(ord325, true);
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex290 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("mp_union");
      mp_unionindex291 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("mp_union");
      mp_uniondelta297 = readrel332->getIndex(ord331, true);
      std::vector<u16> ord333({0, 1});
      slog::Relation* readrel334 = db->getRelation("mp_union_ans");
      mp_union_ansindex292 = readrel334->getIndex(ord333, false);
  
    }
    ReadTask298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c33 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c24 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c26 = _t[8];
        u64 v_c27 = _t[9];
        u64 v_c59 = _prim_lt(db, v_c24, v_c8);
        if (v_c59 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
        if (!v_c59) return;
        slog::join_probe<9,9>($sup5638x95x0x0x0index280, std::array<u64,9>{v_c7, v_c8, v_c9, v_c10, v_c31, v_c24, v_c25, v_c26, v_c27}, [&](const std::array<u64,9>& m336) {
          if (!slog::exists_probe<5,4>(mbranchindex281, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex282, std::array<u64,3>{v_c25, v_c8, v_c33})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex283, std::array<u64,2>{v_c33, v_c9})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex284, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex285, mbranchdelta293, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m337) {
            u64 v_c34 = m337[4];
            if (!slog::exists_probe<3,2>(mp_unionindex286, std::array<u64,3>{v_c31, v_c34, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex287, mbranchdelta294, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0}, [&](const std::array<u64,5>& m338) {
              u64 v_c30 = m338[4];
              slog::join_probe_old<3,3>(mp_unionindex288, mp_uniondelta295, std::array<u64,3>{v_c31, v_c34, v_c30}, [&](const std::array<u64,3>& m339) {
                slog::join_probe_old<3,3>(mp_mskindex289, mp_mskdelta296, std::array<u64,3>{v_c25, v_c8, v_c33}, [&](const std::array<u64,3>& m340) {
                  slog::join_probe<2,2>(mp_msk_ansindex290, std::array<u64,2>{v_c33, v_c9}, [&](const std::array<u64,2>& m341) {
                    slog::join_probe_old<3,2>(mp_unionindex291, mp_uniondelta297, std::array<u64,3>{v_c7, v_c30, 0}, [&](const std::array<u64,3>& m342) {
                      u64 v_c35 = m342[2];
                      slog::join_probe<2,1>(mp_union_ansindex292, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m343) {
                        u64 v_c19 = m343[1];
                        u64 v_c36 = _prim_band(db, v_c25, v_c8);
                        if (v_c36 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c60 = _prim_lt(db, v_c36, v_c29);
                        if (v_c60 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c60) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c19, v_c8, v_c9, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c19, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask298* _cont = new ReadTask298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask298(db,b), false);
  // (crule (pre (let __trid3f8K764 constc99bf3037b4c2fce0fbaab85) (let __trel5yzb765 constdd7bbf31ce5f578b9805e840) (let __tcol4iIK766 const5feceb66ffc86f38d952786c) (let __trel25dU767 constdd7bbf31ce5f578b9805e840) (let __tcol43qZ768 const6b86b273ff34fce19d6b804e)) (scan $sup5638x98x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid3f8K764 __trel5yzb765 __tcol4iIK766 (1 2 3 4 0)) (tycheck m (accept int) __trid3f8K764 __trel25dU767 __tcol43qZ768 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __6YDk763 q m)) map.slog:99 #f)
  class ReadTask345 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
  
    }
    ReadTask345(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_constc99bf3037b4c2fce0fbaab85;
      u64 v_c62 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
      u64 v_c64 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c25 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c26 = _t[7];
        u64 v_c27 = _t[8];
        ++_fires;
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c61, v_c62, v_c63, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c61, v_c64, v_c65, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c25, v_c8}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask345* _cont = new ReadTask345(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask345(db,b), false);
  // (crule (pre (let __trid63VA681 constc99bf3037b4c2fce0fbaab85) (let __trel8I6G682 const7f254967624b26d820569bd6) (let __tcol8XB8683 const5feceb66ffc86f38d952786c) (let __trel6G3M684 const72bac24066bb34077c1f6e71) (let __tcol1Siw685 const5feceb66ffc86f38d952786c) (let __trel1iSE686 const72bac24066bb34077c1f6e71) (let __tcol0s6k687 const6b86b273ff34fce19d6b804e) (let __trel15Qp688 const72bac24066bb34077c1f6e71) (let __tcol4tmD689 constd4735e3a265e16eee03f5971) (let __trel93J3690 const72bac24066bb34077c1f6e71) (let __tcol38Yr691 const4e07408562bedb8b60ce05c1)) (scan $sup5638x98x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid63VA681 __trel8I6G682 __tcol8XB8683 (1 2 3 4 0)) (tycheck q (accept int) __trid63VA681 __trel6G3M684 __tcol1Siw685 (1 2 3 4 0)) (tycheck n (accept int) __trid63VA681 __trel1iSE686 __tcol0s6k687 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid63VA681 __trel15Qp688 __tcol4tmD689 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid63VA681 __trel93J3690 __tcol38Yr691 (1 2 3 4 0)) (emit-temp temp6KDK1090 n q r u v) (mkstruct mbranch (1 2 3 4 0) __t9vqe281 q n u v)) map.slog:99 #f)
  class ReadTask349 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid347;  u32 sid346;  u32 sid348;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp6KDK1090");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x1");
      sid347 = db->getRelation("_enum")->getStructId();
      sid346 = db->getRelation("mbranch")->getStructId();
      sid348 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask349(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_constc99bf3037b4c2fce0fbaab85;
      u64 v_c67 = v_const7f254967624b26d820569bd6;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const72bac24066bb34077c1f6e71;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
      u64 v_c71 = v_const72bac24066bb34077c1f6e71;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const72bac24066bb34077c1f6e71;
      u64 v_c74 = v_constd4735e3a265e16eee03f5971;
      u64 v_c75 = v_const72bac24066bb34077c1f6e71;
      u64 v_c76 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c5 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c24 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c26 = _t[8];
        u64 v_c27 = _t[9];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid346 || decode_struct_id(v_c10) == sid347 || decode_struct_id(v_c10) == sid348))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c66, v_c67, v_c68, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c66, v_c69, v_c70, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c24)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c66, v_c71, v_c72, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid346 || decode_struct_id(v_c26) == sid347 || decode_struct_id(v_c26) == sid348))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c66, v_c73, v_c74, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid346 || decode_struct_id(v_c27) == sid347 || decode_struct_id(v_c27) == sid348))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c66, v_c75, v_c76, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c24, v_c25, v_c10, v_c26, v_c27});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c25, v_c24, v_c26, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t3jH2107 q) (body (exists $sup5638x104x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t3jH2107 q) (exists $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists mbranch (1 2 3 4 0) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t3jH2107 p n) (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists mbranch (1 2 3 4 0) 2 q n) (exists mbranch (1 2 3 4 0) 1 p) (join-old $sup5638x104x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t3jH2107 n p q __t38nk104 l m r u v) (cmp lt m n) (join-old $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t38nk104 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 1 u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t9OKP102) (exists mp_union (2 0 1) 2 __t9OKP102 __t38nk104) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_union (0 1 2) 3 (0 1 2) __t38nk104 __t6XhK108 __t9OKP102) (join-old mp_union (1 2 0) 2 (1 2 0) __t6XhK108 u __t109M109) (join-old mp_union_ans (0 1) 1 (0 1) __t109M109 __v0) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask375 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index350;  slog::Index** $sup5638x104x0x0x0index351;  slog::Index** mbranchindex352;  slog::Index** mp_mskindex353;  slog::Index** $sup5638x104x0x0x0index354;  slog::Index** mbranchindex355;  slog::Index** mbranchindex356;  slog::Index** $sup5638x104x0x0x1index357;  slog::Index** $sup5638x104x0x0x0index358;  slog::Index** mbranchindex359;  slog::Index** mp_unionindex360;  slog::Index** mbranchindex361;  slog::Index** mp_unionindex362;  slog::Index** mbranchindex363;  slog::Index** mp_unionindex364;  slog::Index** mp_unionindex365;  slog::Index** mp_union_ansindex366;  slog::Index** mp_mskdelta367;  slog::Index** $sup5638x104x0x0x1delta368;  slog::Index** $sup5638x104x0x0x0delta369;  slog::Index** mbranchdelta370;  slog::Index** mbranchdelta371;  slog::Index** mp_uniondelta372;  slog::Index** mp_uniondelta373;  slog::Index** mp_union_ansdelta374;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord376({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel377 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index350 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel379 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index351 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 3, 4, 0});
      slog::Relation* readrel381 = db->getRelation("mbranch");
      mbranchindex352 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({0, 1, 2});
      slog::Relation* readrel383 = db->getRelation("mp_msk");
      mp_mskindex353 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1, 2});
      slog::Relation* readrel385 = db->getRelation("mp_msk");
      mp_mskdelta367 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel387 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index354 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 3, 4, 0});
      slog::Relation* readrel389 = db->getRelation("mbranch");
      mbranchindex355 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 3, 4, 0});
      slog::Relation* readrel391 = db->getRelation("mbranch");
      mbranchindex356 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel393 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index357 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel395 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta368 = readrel395->getIndex(ord394, true);
      std::vector<u16> ord396({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel397 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index358 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel399 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0delta369 = readrel399->getIndex(ord398, true);
      std::vector<u16> ord400({1, 2, 3, 4, 0});
      slog::Relation* readrel401 = db->getRelation("mbranch");
      mbranchindex359 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({2, 0, 1});
      slog::Relation* readrel403 = db->getRelation("mp_union");
      mp_unionindex360 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 3, 4, 0});
      slog::Relation* readrel405 = db->getRelation("mbranch");
      mbranchindex361 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 3, 4, 0});
      slog::Relation* readrel407 = db->getRelation("mbranch");
      mbranchdelta370 = readrel407->getIndex(ord406, true);
      std::vector<u16> ord408({2, 0, 1});
      slog::Relation* readrel409 = db->getRelation("mp_union");
      mp_unionindex362 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 2, 3, 4, 0});
      slog::Relation* readrel411 = db->getRelation("mbranch");
      mbranchindex363 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 3, 4, 0});
      slog::Relation* readrel413 = db->getRelation("mbranch");
      mbranchdelta371 = readrel413->getIndex(ord412, true);
      std::vector<u16> ord414({0, 1, 2});
      slog::Relation* readrel415 = db->getRelation("mp_union");
      mp_unionindex364 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1, 2});
      slog::Relation* readrel417 = db->getRelation("mp_union");
      mp_uniondelta372 = readrel417->getIndex(ord416, true);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("mp_union");
      mp_unionindex365 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("mp_union");
      mp_uniondelta373 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("mp_union_ans");
      mp_union_ansindex366 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("mp_union_ans");
      mp_union_ansdelta374 = readrel425->getIndex(ord424, true);
  
    }
    ReadTask375(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c79 = _t[0];
        u64 v_c25 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index350, std::array<u64,10>{v_c79, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index351, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex352, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex353, mp_mskdelta367, std::array<u64,3>{v_c79, 0, 0}, [&](const std::array<u64,3>& m426) {
          u64 v_c9 = m426[1]; u64 v_c24 = m426[2];
          if (!slog::exists_probe<9,3>($sup5638x104x0x0x0index354, std::array<u64,9>{v_c24, v_c9, v_c25, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex355, std::array<u64,5>{v_c25, v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex356, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x104x0x0x1index357, $sup5638x104x0x0x1delta368, std::array<u64,10>{v_c79, v_c24, v_c9, v_c25, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m427) {
            u64 v_c80 = m427[4]; u64 v_c7 = m427[5]; u64 v_c8 = m427[6]; u64 v_c10 = m427[7]; u64 v_c26 = m427[8]; u64 v_c27 = m427[9];
            u64 v_c81 = _prim_lt(db, v_c8, v_c24);
            if (v_c81 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c81) return;
            slog::join_probe_old<9,9>($sup5638x104x0x0x0index358, $sup5638x104x0x0x0delta369, std::array<u64,9>{v_c25, v_c24, v_c26, v_c27, v_c80, v_c7, v_c8, v_c9, v_c10}, [&](const std::array<u64,9>& m429) {
              if (!slog::exists_probe<5,4>(mbranchindex359, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex360, std::array<u64,3>{v_c26, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex361, mbranchdelta370, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0}, [&](const std::array<u64,5>& m430) {
                u64 v_c82 = m430[4];
                if (!slog::exists_probe<3,2>(mp_unionindex362, std::array<u64,3>{v_c82, v_c80, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex363, mbranchdelta371, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m431) {
                  u64 v_c83 = m431[4];
                  slog::join_probe_old<3,3>(mp_unionindex364, mp_uniondelta372, std::array<u64,3>{v_c80, v_c83, v_c82}, [&](const std::array<u64,3>& m432) {
                    slog::join_probe_old<3,2>(mp_unionindex365, mp_uniondelta373, std::array<u64,3>{v_c83, v_c26, 0}, [&](const std::array<u64,3>& m433) {
                      u64 v_c84 = m433[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex366, mp_union_ansdelta374, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m434) {
                        u64 v_c19 = m434[1];
                        u64 v_c85 = _prim_band(db, v_c9, v_c24);
                        if (v_c85 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c86 = _prim_lt(db, v_c85, v_c78);
                        if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c86) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c80, v_c19, v_c24, v_c25, v_c27});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c19, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __trid2sEh857 const07d7fbed0aba019c07f7eb8a) (let __trel14Rx858 const20347926ddb307a8e2bdb71b) (let __tcol5gMF859 const4e07408562bedb8b60ce05c1)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7Ifn141) (join-old mp_msk_ans (0 1) 2 (0 1) __t7Ifn141 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t13lF142) (join-old mp_del_ans (0 1) 1 (0 1) __t13lF142 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2sEh857 __trel14Rx858 __tcol5gMF859 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __3uQ5856 p m __v0 r)) map.slog:83 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex436;  slog::Index** mp_delindex437;  slog::Index** mp_mskindex438;  slog::Index** mp_msk_ansindex439;  slog::Index** mp_delindex440;  slog::Index** mp_del_ansindex441;  slog::Index** mp_mskdelta442;  slog::Index** mp_msk_ansdelta443;  slog::Index** mp_deldelta444;  slog::Index** mp_del_ansdelta445;
    u32 sid447;  u32 sid446;  u32 sid448;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord450({1, 0});
      slog::Relation* readrel451 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex436 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("mp_del");
      mp_delindex437 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("mp_msk");
      mp_mskindex438 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("mp_msk");
      mp_mskdelta442 = readrel457->getIndex(ord456, true);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex439 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta443 = readrel461->getIndex(ord460, true);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("mp_del");
      mp_delindex440 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("mp_del");
      mp_deldelta444 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("mp_del_ans");
      mp_del_ansindex441 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({0, 1});
      slog::Relation* readrel469 = db->getRelation("mp_del_ans");
      mp_del_ansdelta445 = readrel469->getIndex(ord468, true);
      sid447 = db->getRelation("_enum")->getStructId();
      sid446 = db->getRelation("mbranch")->getStructId();
      sid448 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c88 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c89 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex436, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex437, std::array<u64,3>{v_c7, v_c6, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex438, mp_mskdelta442, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m470) {
          u64 v_c90 = m470[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex439, mp_msk_ansdelta443, std::array<u64,2>{v_c90, v_c9}, [&](const std::array<u64,2>& m471) {
            slog::join_probe_old<3,2>(mp_delindex440, mp_deldelta444, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m472) {
              u64 v_c91 = m472[2];
              slog::join_probe_old<2,1>(mp_del_ansindex441, mp_del_ansdelta445, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m473) {
                u64 v_c19 = m473[1];
                ++_fires;
                if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid446 || decode_struct_id(v_c10) == sid447 || decode_struct_id(v_c10) == sid448))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c87, v_c88, v_c89, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c19, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask449* _cont = new ReadTask449(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask449(db,b), false);
  // (crule (pre (let _00024sqc96G8453 constd4735e3a265e16eee03f5971) (let _00024sqc6cPp454 const5feceb66ffc86f38d952786c) (let _00024sqc6W8K455 const6b86b273ff34fce19d6b804e) (let _00024sqc1g9y458 const6b86b273ff34fce19d6b804e) (let _00024sqc9hYP459 const5feceb66ffc86f38d952786c) (let _00024sqc9QOZ460 const6b86b273ff34fce19d6b804e) (let _00024sqc7qLn461 const5feceb66ffc86f38d952786c) (let _00024sqo4y5c466 const5feceb66ffc86f38d952786c)) (scan mp_put __t4UIA381 __v0 k v) (body (exists mp_put_ans (0 1) 1 __t4UIA381) (exists $sup5638x127x0x0x0 (3 4 5 0 1 2) 2 k v) (exists $seq_at (1 0 2) 1 _00024sqo4y5c466) (join mp_fromlist_ans (1 0) 1 __v0 __t56xP380) (join mp_put_ans (0 1) 1 __t4UIA381 __v1) (join mp_fromlist (0 1) 1 __t56xP380 xs) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 3 k v xs _00024seq0 _00024seq1 __t3c2R379) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4y5c466 _00024seq0 _00024seq1) (join mp_fromlist (0 1) 2 __t3c2R379 _00024seq1) (letp _00024sql7ZXI456 (aslst _00024seq1)) (let _00024sqn1QVd457 (llen _00024sql7ZXI456)) (cmp ge _00024sqn1QVd457 _00024sqc1g9y458) (letp _00024sql6CzH451 (aslst _00024seq0)) (let chk87cn1048 (llen _00024sql6CzH451)) (eq _00024sqc96G8453 chk87cn1048) (letp chk6jCW1049 (lref _00024sql6CzH451 _00024sqc6cPp454)) (eq k chk6jCW1049) (letp chk2sbh1050 (lref _00024sql6CzH451 _00024sqc6W8K455)) (eq v chk2sbh1050) (letp chk92jO1051 (lref _00024sql7ZXI456 _00024sqc9hYP459)) (eq _00024seq0 chk92jO1051) (let _00024sqp3HUi462 (_0002d _00024sqn1QVd457 _00024sqc7qLn461)) (let chk1hA71052 (lslice _00024sql7ZXI456 _00024sqc9QOZ460 _00024sqp3HUi462)) (eq xs chk1hA71052)) (head (emit mp_fromlist_ans (1 0) __v1 __t3c2R379)) map.slog:128 #f)
  class ReadTask484 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex474;  slog::Index** $sup5638x127x0x0x0index475;  slog::Index** $seq_atindex476;  slog::Index** mp_fromlist_ansindex477;  slog::Index** mp_put_ansindex478;  slog::Index** mp_fromlistindex479;  slog::Index** $sup5638x127x0x0x0index480;  slog::Index** $seq_atindex481;  slog::Index** mp_fromlistindex482;  slog::Index** $seq_atdelta483;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord485({1, 0});
      slog::Relation* readrel486 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel486->getIndex(ord485, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("mp_put_ans");
      mp_put_ansindex474 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel490 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index475 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 0, 2});
      slog::Relation* readrel492 = db->getRelation("$seq_at");
      $seq_atindex476 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 0});
      slog::Relation* readrel494 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex477 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({0, 1});
      slog::Relation* readrel496 = db->getRelation("mp_put_ans");
      mp_put_ansindex478 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("mp_fromlist");
      mp_fromlistindex479 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel500 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index480 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 0, 2});
      slog::Relation* readrel502 = db->getRelation("$seq_at");
      $seq_atindex481 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 0, 2});
      slog::Relation* readrel504 = db->getRelation("$seq_at");
      $seq_atdelta483 = readrel504->getIndex(ord503, true);
      std::vector<u16> ord505({0, 1});
      slog::Relation* readrel506 = db->getRelation("mp_fromlist");
      mp_fromlistindex482 = readrel506->getIndex(ord505, false);
  
    }
    ReadTask484(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c92 = v_constd4735e3a265e16eee03f5971;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c96 = v_const5feceb66ffc86f38d952786c;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c27 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex474, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index475, std::array<u64,6>{v_c6, v_c27, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex476, std::array<u64,3>{v_c99, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlist_ansindex477, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m507) {
          u64 v_c101 = m507[1];
          slog::join_probe<2,1>(mp_put_ansindex478, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m508) {
            u64 v_c23 = m508[1];
            slog::join_probe<2,1>(mp_fromlistindex479, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m509) {
              u64 v_c102 = m509[1];
              slog::join_probe<6,3>($sup5638x127x0x0x0index480, std::array<u64,6>{v_c6, v_c27, v_c102, 0, 0, 0}, [&](const std::array<u64,6>& m510) {
                u64 v_c103 = m510[3]; u64 v_c104 = m510[4]; u64 v_c105 = m510[5];
                slog::join_probe_old<3,3>($seq_atindex481, $seq_atdelta483, std::array<u64,3>{v_c99, v_c103, v_c104}, [&](const std::array<u64,3>& m511) {
                  slog::join_probe<2,2>(mp_fromlistindex482, std::array<u64,2>{v_c105, v_c104}, [&](const std::array<u64,2>& m512) {
                    bool ok513 = true;
                    u64 v_c106 = _prim_aslst(db, v_c104, &ok513);
                    if (!ok513) return;
                    u64 v_c107 = _prim_llen(db, v_c106);
                    if (v_c107 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c108 = _prim_ge(db, v_c107, v_c95);
                    if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (!v_c108) return;
                    bool ok515 = true;
                    u64 v_c109 = _prim_aslst(db, v_c103, &ok515);
                    if (!ok515) return;
                    u64 v_c110 = _prim_llen(db, v_c109);
                    if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c92 != v_c110) return;
                    bool ok516 = true;
                    u64 v_c111 = _prim_lref(db, v_c109, v_c93, &ok516);
                    if (!ok516) return;
                    if (v_c6 != v_c111) return;
                    bool ok517 = true;
                    u64 v_c112 = _prim_lref(db, v_c109, v_c94, &ok517);
                    if (!ok517) return;
                    if (v_c27 != v_c112) return;
                    bool ok518 = true;
                    u64 v_c113 = _prim_lref(db, v_c106, v_c96, &ok518);
                    if (!ok518) return;
                    if (v_c103 != v_c113) return;
                    u64 v_c114 = _prim__0002d(db, v_c107, v_c98);
                    if (v_c114 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c115 = _prim_lslice(db, v_c106, v_c97, v_c114);
                    if (v_c115 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c102 != v_c115) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c105}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_put", _fires);
  
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
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (scan $sup5638x68x0x0x0 __t2Eey276 k t v) (body (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t2Eey276) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst6EKe278) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t4H3I279) (exists mp_put_ans (0 1) 1 __t4H3I279) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t16yQ277) (join mp_has0_ans (0 1) 2 __t16yQ277 __tconst6EKe278) (join mp_put_ans (0 1) 1 __t4H3I279 r)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask530 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex519;  slog::Index** mp_has0index520;  slog::Index** mp_has0_ansindex521;  slog::Index** mp_putindex522;  slog::Index** mp_put_ansindex523;  slog::Index** mp_has0index524;  slog::Index** mp_has0_ansindex525;  slog::Index** mp_put_ansindex526;  slog::Index** mp_put_softdelta527;  slog::Index** mp_putdelta528;  slog::Index** mp_has0delta529;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord531({0, 1});
      slog::Relation* readrel532 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel532->getIndex(ord531, false);
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord533({1, 2, 3, 0});
      slog::Relation* readrel534 = db->getRelation("mp_put_soft");
      mp_put_softindex519 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 3, 0});
      slog::Relation* readrel536 = db->getRelation("mp_put_soft");
      mp_put_softdelta527 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("mp_has0");
      mp_has0index520 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 0});
      slog::Relation* readrel540 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex521 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 3, 0});
      slog::Relation* readrel542 = db->getRelation("mp_put");
      mp_putindex522 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 2, 3, 0});
      slog::Relation* readrel544 = db->getRelation("mp_put");
      mp_putdelta528 = readrel544->getIndex(ord543, true);
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("mp_put_ans");
      mp_put_ansindex523 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("mp_has0");
      mp_has0index524 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("mp_has0");
      mp_has0delta529 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex525 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({0, 1});
      slog::Relation* readrel554 = db->getRelation("mp_put_ans");
      mp_put_ansindex526 = readrel554->getIndex(ord553, false);
  
    }
    ReadTask530(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c57 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c27 = _t[3];
        slog::join_probe_old<4,4>(mp_put_softindex519, mp_put_softdelta527, std::array<u64,4>{v_c56, v_c6, v_c27, v_c57}, [&](const std::array<u64,4>& m555) {
          if (!slog::exists_probe<3,2>(mp_has0index520, std::array<u64,3>{v_c56, v_c6, 0})) return;
          if (!slog::exists_probe<2,1>(mp_has0_ansindex521, std::array<u64,2>{v_c54, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex522, mp_putdelta528, std::array<u64,4>{v_c56, v_c6, v_c27, 0}, [&](const std::array<u64,4>& m556) {
            u64 v_c55 = m556[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex523, std::array<u64,2>{v_c55, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index524, mp_has0delta529, std::array<u64,3>{v_c56, v_c6, 0}, [&](const std::array<u64,3>& m557) {
              u64 v_c58 = m557[2];
              slog::join_probe<2,2>(mp_has0_ansindex525, std::array<u64,2>{v_c58, v_c54}, [&](const std::array<u64,2>& m558) {
                slog::join_probe<2,1>(mp_put_ansindex526, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m559) {
                  u64 v_c10 = m559[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c10}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask530* _cont = new ReadTask530(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask530(db,b), false);
  // (crule (pre (let __tconst1bCS13 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t2LCs15 __t3zLK14 k) (body (join mleaf (0 1 2) 2 __t3zLK14 k v)) (head (emit mp_has0_ans (0 1) __t2LCs15 __tconst1bCS13)) map.slog:58 #f)
  class ReadTask561 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex560;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord562({0, 1});
      slog::Relation* readrel563 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel563->getIndex(ord562, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord564({0, 1, 2});
      slog::Relation* readrel565 = db->getRelation("mleaf");
      mleafindex560 = readrel565->getIndex(ord564, false);
  
    }
    ReadTask561(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c6 = _t[2];
        slog::join_probe<3,2>(mleafindex560, std::array<u64,3>{v_c118, v_c6, 0}, [&](const std::array<u64,3>& m566) {
          u64 v_c27 = m566[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c117, v_c116}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:58", "delta:mp_has0", _fires);
  
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
  // (crule (pre (let __tconst1bCS13 const6b86b273ff34fce19d6b804e)) (scan mleaf __t3zLK14 k v) (body (join-old mp_has0 (1 2 0) 2 (1 2 0) __t3zLK14 k __t2LCs15)) (head (emit mp_has0_ans (0 1) __t2LCs15 __tconst1bCS13)) map.slog:58 #f)
  class ReadTask569 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index567;  slog::Index** mp_has0delta568;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord570({0, 1});
      slog::Relation* readrel571 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel571->getIndex(ord570, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("mp_has0");
      mp_has0index567 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("mp_has0");
      mp_has0delta568 = readrel575->getIndex(ord574, true);
  
    }
    ReadTask569(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c118 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c27 = _t[2];
        slog::join_probe_old<3,2>(mp_has0index567, mp_has0delta568, std::array<u64,3>{v_c118, v_c6, 0}, [&](const std::array<u64,3>& m576) {
          u64 v_c117 = m576[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c117, v_c116}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:58", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask569* _cont = new ReadTask569(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask569(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mbranch __t2SOF94 p m l r) (body (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 4 r l m p) (exists mp_union (1 2 0) 1 __t2SOF94) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 r) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 4 p l m r __t2uCs95 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t2uCs95 __t2SOF94) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t2uCs95 n q u v __t9ory98) (exists mp_msk (1 2 0) 3 q m __t9ory98) (exists mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_union (0 1 2) 3 (0 1 2) __t2uCs95 __t2SOF94 __t1Mtu99) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask599 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index577;  slog::Index** mp_unionindex578;  slog::Index** mp_mskindex579;  slog::Index** mp_msk_ansindex580;  slog::Index** mp_unionindex581;  slog::Index** $sup5638x98x0x0x0index582;  slog::Index** mbranchindex583;  slog::Index** mp_unionindex584;  slog::Index** mp_mskindex585;  slog::Index** $sup5638x98x0x0x1index586;  slog::Index** mp_mskindex587;  slog::Index** mp_msk_ansindex588;  slog::Index** mbranchindex589;  slog::Index** mp_unionindex590;  slog::Index** mp_mskindex591;  slog::Index** mp_msk_ansindex592;  slog::Index** mp_unionindex593;  slog::Index** mp_union_ansindex594;  slog::Index** mbranchdelta595;  slog::Index** mp_uniondelta596;  slog::Index** mp_mskdelta597;  slog::Index** mp_uniondelta598;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord600({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel601 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index577 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("mp_union");
      mp_unionindex578 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({2, 0, 1});
      slog::Relation* readrel605 = db->getRelation("mp_msk");
      mp_mskindex579 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex580 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 2, 0});
      slog::Relation* readrel609 = db->getRelation("mp_union");
      mp_unionindex581 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel611 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index582 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 2, 3, 4, 0});
      slog::Relation* readrel613 = db->getRelation("mbranch");
      mbranchindex583 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1, 2});
      slog::Relation* readrel615 = db->getRelation("mp_union");
      mp_unionindex584 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("mp_msk");
      mp_mskindex585 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel619 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index586 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("mp_msk");
      mp_mskindex587 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex588 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 3, 4, 0});
      slog::Relation* readrel625 = db->getRelation("mbranch");
      mbranchindex589 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 3, 4, 0});
      slog::Relation* readrel627 = db->getRelation("mbranch");
      mbranchdelta595 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({0, 1, 2});
      slog::Relation* readrel629 = db->getRelation("mp_union");
      mp_unionindex590 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({0, 1, 2});
      slog::Relation* readrel631 = db->getRelation("mp_union");
      mp_uniondelta596 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("mp_msk");
      mp_mskindex591 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 0});
      slog::Relation* readrel635 = db->getRelation("mp_msk");
      mp_mskdelta597 = readrel635->getIndex(ord634, true);
      std::vector<u16> ord636({0, 1});
      slog::Relation* readrel637 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex592 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 2, 0});
      slog::Relation* readrel639 = db->getRelation("mp_union");
      mp_unionindex593 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("mp_union");
      mp_uniondelta598 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("mp_union_ans");
      mp_union_ansindex594 = readrel643->getIndex(ord642, false);
  
    }
    ReadTask599(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x98x0x0x1index577, std::array<u64,10>{v_c10, v_c7, v_c8, v_c9, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex578, std::array<u64,3>{v_c120, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex579, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex580, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex581, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x98x0x0x0index582, std::array<u64,9>{v_c9, v_c7, v_c8, v_c10, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m644) {
          u64 v_c121 = m644[4]; u64 v_c24 = m644[5]; u64 v_c25 = m644[6]; u64 v_c26 = m644[7]; u64 v_c27 = m644[8];
          u64 v_c122 = _prim_lt(db, v_c24, v_c8);
          if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c122) return;
          if (!slog::exists_probe<5,4>(mbranchindex583, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex584, std::array<u64,3>{v_c121, v_c120, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex585, std::array<u64,3>{v_c25, v_c8, 0})) return;
          slog::join_probe<10,9>($sup5638x98x0x0x1index586, std::array<u64,10>{v_c10, v_c7, v_c8, v_c9, v_c121, v_c24, v_c25, v_c26, v_c27, 0}, [&](const std::array<u64,10>& m646) {
            u64 v_c123 = m646[9];
            if (!slog::exists_probe<3,3>(mp_mskindex587, std::array<u64,3>{v_c25, v_c8, v_c123})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex588, std::array<u64,2>{v_c123, v_c9})) return;
            slog::join_probe_old<5,4>(mbranchindex589, mbranchdelta595, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0}, [&](const std::array<u64,5>& m647) {
              u64 v_c124 = m647[4];
              slog::join_probe_old<3,3>(mp_unionindex590, mp_uniondelta596, std::array<u64,3>{v_c121, v_c120, v_c124}, [&](const std::array<u64,3>& m648) {
                slog::join_probe_old<3,3>(mp_mskindex591, mp_mskdelta597, std::array<u64,3>{v_c25, v_c8, v_c123}, [&](const std::array<u64,3>& m649) {
                  slog::join_probe<2,2>(mp_msk_ansindex592, std::array<u64,2>{v_c123, v_c9}, [&](const std::array<u64,2>& m650) {
                    slog::join_probe_old<3,2>(mp_unionindex593, mp_uniondelta598, std::array<u64,3>{v_c10, v_c124, 0}, [&](const std::array<u64,3>& m651) {
                      u64 v_c125 = m651[2];
                      slog::join_probe<2,1>(mp_union_ansindex594, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m652) {
                        u64 v_c19 = m652[1];
                        u64 v_c126 = _prim_band(db, v_c25, v_c8);
                        if (v_c126 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c127 = _prim_gt(db, v_c126, v_c119);
                        if (v_c127 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c127) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c19, v_c7, v_c8, v_c9});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask599* _cont = new ReadTask599(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask599(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mbranch __t07OG283 p m l r) (body (exists $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 4 l m p r) (exists mp_put (1 2 0 3) 1 __t07OG283) (exists mp_msk (2 0 1) 1 m) (exists mp_put (1 2 0 3) 1 r) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 4 p l m r __t0ekw284 k v) (exists mp_put (1 2 0 3) 4 __t07OG283 k __t0ekw284 v) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t0ekw284 k v __t8lnB287) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t07OG283 k __t0ekw284 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t8lnB287) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask673 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index654;  slog::Index** mp_putindex655;  slog::Index** mp_mskindex656;  slog::Index** mp_putindex657;  slog::Index** mp_msk_ansindex658;  slog::Index** $sup5638x42x0x0x0index659;  slog::Index** mp_putindex660;  slog::Index** mp_mskindex661;  slog::Index** mp_putindex662;  slog::Index** $sup5638x42x0x0x1index663;  slog::Index** mp_putindex664;  slog::Index** mp_mskindex665;  slog::Index** mp_msk_ansindex666;  slog::Index** mp_putindex667;  slog::Index** mp_msk_ansindex668;  slog::Index** mp_put_ansindex669;  slog::Index** mp_putdelta670;  slog::Index** mp_mskdelta671;  slog::Index** mp_putdelta672;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord674({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel675 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index654 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 0, 3});
      slog::Relation* readrel677 = db->getRelation("mp_put");
      mp_putindex655 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({2, 0, 1});
      slog::Relation* readrel679 = db->getRelation("mp_msk");
      mp_mskindex656 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0, 3});
      slog::Relation* readrel681 = db->getRelation("mp_put");
      mp_putindex657 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex658 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel685 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index659 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 0, 3});
      slog::Relation* readrel687 = db->getRelation("mp_put");
      mp_putindex660 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 2, 0});
      slog::Relation* readrel689 = db->getRelation("mp_msk");
      mp_mskindex661 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 3, 0});
      slog::Relation* readrel691 = db->getRelation("mp_put");
      mp_putindex662 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel693 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index663 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0, 3});
      slog::Relation* readrel695 = db->getRelation("mp_put");
      mp_putindex664 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 0, 3});
      slog::Relation* readrel697 = db->getRelation("mp_put");
      mp_putdelta670 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("mp_msk");
      mp_mskindex665 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("mp_msk");
      mp_mskdelta671 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({0, 1});
      slog::Relation* readrel703 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex666 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 3, 0});
      slog::Relation* readrel705 = db->getRelation("mp_put");
      mp_putindex667 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 3, 0});
      slog::Relation* readrel707 = db->getRelation("mp_put");
      mp_putdelta672 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1});
      slog::Relation* readrel709 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex668 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1});
      slog::Relation* readrel711 = db->getRelation("mp_put_ans");
      mp_put_ansindex669 = readrel711->getIndex(ord710, false);
  
    }
    ReadTask673(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c129 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<8,4>($sup5638x42x0x0x1index654, std::array<u64,8>{v_c7, v_c8, v_c9, v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex655, std::array<u64,4>{v_c129, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex656, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex657, std::array<u64,4>{v_c10, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex658, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe<7,4>($sup5638x42x0x0x0index659, std::array<u64,7>{v_c9, v_c7, v_c8, v_c10, 0, 0, 0}, [&](const std::array<u64,7>& m712) {
          u64 v_c130 = m712[4]; u64 v_c6 = m712[5]; u64 v_c27 = m712[6];
          if (!slog::exists_probe<4,4>(mp_putindex660, std::array<u64,4>{v_c129, v_c6, v_c130, v_c27})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex661, std::array<u64,3>{v_c6, v_c8, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex662, std::array<u64,4>{v_c10, v_c6, v_c27, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index663, std::array<u64,8>{v_c7, v_c8, v_c9, v_c10, v_c130, v_c6, v_c27, 0}, [&](const std::array<u64,8>& m713) {
            u64 v_c131 = m713[7];
            slog::join_probe_old<4,4>(mp_putindex664, mp_putdelta670, std::array<u64,4>{v_c129, v_c6, v_c130, v_c27}, [&](const std::array<u64,4>& m714) {
              slog::join_probe_old<3,3>(mp_mskindex665, mp_mskdelta671, std::array<u64,3>{v_c6, v_c8, v_c131}, [&](const std::array<u64,3>& m715) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex666, std::array<u64,2>{v_c131, v_c9})) return;
                slog::join_probe_old<4,3>(mp_putindex667, mp_putdelta672, std::array<u64,4>{v_c10, v_c6, v_c27, 0}, [&](const std::array<u64,4>& m716) {
                  u64 v_c132 = m716[3];
                  slog::join_probe<2,2>(mp_msk_ansindex668, std::array<u64,2>{v_c131, v_c9}, [&](const std::array<u64,2>& m717) {
                    slog::join_probe<2,1>(mp_put_ansindex669, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m718) {
                      u64 v_c19 = m718[1];
                      u64 v_c133 = _prim_band(db, v_c6, v_c8);
                      if (v_c133 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c134 = _prim_gt(db, v_c133, v_c128);
                      if (v_c134 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c134) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c130, v_c19, v_c7, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask673* _cont = new ReadTask673(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask673(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t1jAB158 p) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_bld (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t1jAB158 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (1 2 3 4 0) 2 p m) (join-old $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t8KQn154 l r) (exists mp_del (0 2 1) 2 __t8KQn154 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_del (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t85IU153) (join-old mp_del (0 2 1) 3 (0 2 1) __t8KQn154 k __t85IU153) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t0Lvo157 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join-old mp_del_ans (0 1) 2 (0 1) __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask746 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index720;  slog::Index** mbranchindex721;  slog::Index** mp_bldindex722;  slog::Index** mp_mskindex723;  slog::Index** mbranchindex724;  slog::Index** mp_delindex725;  slog::Index** mp_bldindex726;  slog::Index** $sup5638x82x0x0x0index727;  slog::Index** mp_delindex728;  slog::Index** mp_bldindex729;  slog::Index** mp_delindex730;  slog::Index** mbranchindex731;  slog::Index** mp_delindex732;  slog::Index** mp_bldindex733;  slog::Index** mp_del_ansindex734;  slog::Index** mp_bld_ansindex735;  slog::Index** mp_delindex736;  slog::Index** mp_del_ansindex737;  slog::Index** mp_bld_ansindex738;  slog::Index** mp_mskdelta739;  slog::Index** $sup5638x82x0x0x0delta740;  slog::Index** mbranchdelta741;  slog::Index** mp_deldelta742;  slog::Index** mp_blddelta743;  slog::Index** mp_deldelta744;  slog::Index** mp_del_ansdelta745;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord747({0, 1});
      slog::Relation* readrel748 = db->getRelation("mp_del_ans");
      head_index[0] = readrel748->getIndex(ord747, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord749({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel750 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index720 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 2, 3, 4, 0});
      slog::Relation* readrel752 = db->getRelation("mbranch");
      mbranchindex721 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({1, 2, 3, 4, 0});
      slog::Relation* readrel754 = db->getRelation("mp_bld");
      mp_bldindex722 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({0, 1, 2});
      slog::Relation* readrel756 = db->getRelation("mp_msk");
      mp_mskindex723 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({0, 1, 2});
      slog::Relation* readrel758 = db->getRelation("mp_msk");
      mp_mskdelta739 = readrel758->getIndex(ord757, true);
      std::vector<u16> ord759({1, 2, 3, 4, 0});
      slog::Relation* readrel760 = db->getRelation("mbranch");
      mbranchindex724 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({2, 0, 1});
      slog::Relation* readrel762 = db->getRelation("mp_del");
      mp_delindex725 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 3, 4, 0});
      slog::Relation* readrel764 = db->getRelation("mp_bld");
      mp_bldindex726 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel766 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index727 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel768 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta740 = readrel768->getIndex(ord767, true);
      std::vector<u16> ord769({0, 2, 1});
      slog::Relation* readrel770 = db->getRelation("mp_del");
      mp_delindex728 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({2, 1, 4, 0, 3});
      slog::Relation* readrel772 = db->getRelation("mp_bld");
      mp_bldindex729 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("mp_del");
      mp_delindex730 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 3, 4, 0});
      slog::Relation* readrel776 = db->getRelation("mbranch");
      mbranchindex731 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 3, 4, 0});
      slog::Relation* readrel778 = db->getRelation("mbranch");
      mbranchdelta741 = readrel778->getIndex(ord777, true);
      std::vector<u16> ord779({0, 2, 1});
      slog::Relation* readrel780 = db->getRelation("mp_del");
      mp_delindex732 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 2, 1});
      slog::Relation* readrel782 = db->getRelation("mp_del");
      mp_deldelta742 = readrel782->getIndex(ord781, true);
      std::vector<u16> ord783({2, 1, 4, 0, 3});
      slog::Relation* readrel784 = db->getRelation("mp_bld");
      mp_bldindex733 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({2, 1, 4, 0, 3});
      slog::Relation* readrel786 = db->getRelation("mp_bld");
      mp_blddelta743 = readrel786->getIndex(ord785, true);
      std::vector<u16> ord787({1, 0});
      slog::Relation* readrel788 = db->getRelation("mp_del_ans");
      mp_del_ansindex734 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({0, 1});
      slog::Relation* readrel790 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex735 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("mp_del");
      mp_delindex736 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("mp_del");
      mp_deldelta744 = readrel794->getIndex(ord793, true);
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("mp_del_ans");
      mp_del_ansindex737 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1});
      slog::Relation* readrel798 = db->getRelation("mp_del_ans");
      mp_del_ansdelta745 = readrel798->getIndex(ord797, true);
      std::vector<u16> ord799({0, 1});
      slog::Relation* readrel800 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex738 = readrel800->getIndex(ord799, false);
  
    }
    ReadTask746(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c136 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x82x0x0x0index720, std::array<u64,6>{v_c9, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex721, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex722, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex723, mp_mskdelta739, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m801) {
          u64 v_c6 = m801[1]; u64 v_c8 = m801[2];
          if (!slog::exists_probe<5,2>(mbranchindex724, std::array<u64,5>{v_c9, v_c8, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex725, std::array<u64,3>{v_c6, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex726, std::array<u64,5>{v_c9, v_c8, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x82x0x0x0index727, $sup5638x82x0x0x0delta740, std::array<u64,6>{v_c6, v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m802) {
            u64 v_c137 = m802[3]; u64 v_c7 = m802[4]; u64 v_c10 = m802[5];
            if (!slog::exists_probe<3,2>(mp_delindex728, std::array<u64,3>{v_c137, v_c6, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex729, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex730, std::array<u64,3>{v_c7, v_c6, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex731, mbranchdelta741, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m803) {
              u64 v_c138 = m803[4];
              slog::join_probe_old<3,3>(mp_delindex732, mp_deldelta742, std::array<u64,3>{v_c137, v_c6, v_c138}, [&](const std::array<u64,3>& m804) {
                slog::join_probe_old<5,3>(mp_bldindex733, mp_blddelta743, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0}, [&](const std::array<u64,5>& m805) {
                  u64 v_c139 = m805[3]; u64 v_c19 = m805[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex734, std::array<u64,2>{v_c19, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex735, std::array<u64,2>{v_c139, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex736, mp_deldelta744, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m806) {
                    u64 v_c140 = m806[2];
                    slog::join_probe_old<2,2>(mp_del_ansindex737, mp_del_ansdelta745, std::array<u64,2>{v_c140, v_c19}, [&](const std::array<u64,2>& m807) {
                      slog::join_probe<2,1>(mp_bld_ansindex738, std::array<u64,2>{v_c139, 0}, [&](const std::array<u64,2>& m808) {
                        u64 v_c40 = m808[1];
                        u64 v_c141 = _prim_band(db, v_c6, v_c8);
                        if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c142 = _prim_lt(db, v_c141, v_c135);
                        if (v_c142 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c142) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c137, v_c40}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask746* _cont = new ReadTask746(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask746(db,b), false);
  // (crule (pre) (scan temp1XD61034 __t2uCs95 __v0 l m p) (body (join mbranch (1 2 3 4 0) 4 p m l __v0 __t0Nlr92)) (head (emit mp_union_ans (0 1) __t2uCs95 __t0Nlr92)) map.slog:99 #f)
  class ReadTask811 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex810;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("mp_union_ans");
      head_index[0] = readrel813->getIndex(ord812, false);
      outer_rel = db->getRelation("temp1XD61034");
      std::vector<u16> ord814({1, 2, 3, 4, 0});
      slog::Relation* readrel815 = db->getRelation("mbranch");
      mbranchindex810 = readrel815->getIndex(ord814, false);
  
    }
    ReadTask811(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe<5,4>(mbranchindex810, std::array<u64,5>{v_c9, v_c8, v_c7, v_c19, 0}, [&](const std::array<u64,5>& m816) {
          u64 v_c143 = m816[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c121, v_c143}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:temp1XD61034", _fires);
  
      if (!_done)
      {
        ReadTask811* _cont = new ReadTask811(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask811(db,b), false);
  // (crule (pre (let __tconst6EKe278 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t4H3I279 r) (body (join mp_has0_ans (1 0) 1 __tconst6EKe278 __t16yQ277) (join-old mp_has0 (0 2 1) 1 (0 2 1) __t16yQ277 k t) (exists $sup5638x68x0x0x0 (1 2 3 0) 2 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (join-old mp_put (1 2 0 3) 3 (1 2 0 3) t k __t4H3I279 v) (exists mp_put_soft (1 2 3 0) 3 t k v) (join-old $sup5638x68x0x0x0 (1 2 3 0) 3 (1 2 3 0) k t v __t2Eey276) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t2Eey276)) (head (emit mp_put_soft_ans (0 1) __t2Eey276 r)) map.slog:69 #f)
  class ReadTask829 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex817;  slog::Index** mp_has0index818;  slog::Index** $sup5638x68x0x0x0index819;  slog::Index** mp_put_softindex820;  slog::Index** mp_putindex821;  slog::Index** mp_put_softindex822;  slog::Index** $sup5638x68x0x0x0index823;  slog::Index** mp_put_softindex824;  slog::Index** mp_has0delta825;  slog::Index** mp_putdelta826;  slog::Index** $sup5638x68x0x0x0delta827;  slog::Index** mp_put_softdelta828;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel831->getIndex(ord830, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord832({1, 0});
      slog::Relation* readrel833 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex817 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({0, 2, 1});
      slog::Relation* readrel835 = db->getRelation("mp_has0");
      mp_has0index818 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 2, 1});
      slog::Relation* readrel837 = db->getRelation("mp_has0");
      mp_has0delta825 = readrel837->getIndex(ord836, true);
      std::vector<u16> ord838({1, 2, 3, 0});
      slog::Relation* readrel839 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index819 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 3, 0});
      slog::Relation* readrel841 = db->getRelation("mp_put_soft");
      mp_put_softindex820 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 0, 3});
      slog::Relation* readrel843 = db->getRelation("mp_put");
      mp_putindex821 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({1, 2, 0, 3});
      slog::Relation* readrel845 = db->getRelation("mp_put");
      mp_putdelta826 = readrel845->getIndex(ord844, true);
      std::vector<u16> ord846({1, 2, 3, 0});
      slog::Relation* readrel847 = db->getRelation("mp_put_soft");
      mp_put_softindex822 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 2, 3, 0});
      slog::Relation* readrel849 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index823 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 2, 3, 0});
      slog::Relation* readrel851 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0delta827 = readrel851->getIndex(ord850, true);
      std::vector<u16> ord852({1, 2, 3, 0});
      slog::Relation* readrel853 = db->getRelation("mp_put_soft");
      mp_put_softindex824 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 3, 0});
      slog::Relation* readrel855 = db->getRelation("mp_put_soft");
      mp_put_softdelta828 = readrel855->getIndex(ord854, true);
  
    }
    ReadTask829(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c55 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe<2,1>(mp_has0_ansindex817, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m856) {
          u64 v_c58 = m856[1];
          slog::join_probe_old<3,1>(mp_has0index818, mp_has0delta825, std::array<u64,3>{v_c58, 0, 0}, [&](const std::array<u64,3>& m857) {
            u64 v_c6 = m857[1]; u64 v_c56 = m857[2];
            if (!slog::exists_probe<4,2>($sup5638x68x0x0x0index819, std::array<u64,4>{v_c6, v_c56, 0, 0})) return;
            if (!slog::exists_probe<4,2>(mp_put_softindex820, std::array<u64,4>{v_c56, v_c6, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex821, mp_putdelta826, std::array<u64,4>{v_c56, v_c6, v_c55, 0}, [&](const std::array<u64,4>& m858) {
              u64 v_c27 = m858[3];
              if (!slog::exists_probe<4,3>(mp_put_softindex822, std::array<u64,4>{v_c56, v_c6, v_c27, 0})) return;
              slog::join_probe_old<4,3>($sup5638x68x0x0x0index823, $sup5638x68x0x0x0delta827, std::array<u64,4>{v_c6, v_c56, v_c27, 0}, [&](const std::array<u64,4>& m859) {
                u64 v_c57 = m859[3];
                slog::join_probe_old<4,4>(mp_put_softindex824, mp_put_softdelta828, std::array<u64,4>{v_c56, v_c6, v_c27, v_c57}, [&](const std::array<u64,4>& m860) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c10}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask829* _cont = new ReadTask829(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask829(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan $sup5638x98x0x0x1 __t2uCs95 __t9ory98 l m n p q r u v) (body (cmp lt n m) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t2uCs95 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 3 q m __t9ory98) (exists mp_msk_ans (0 1) 2 __t9ory98 p) (exists mp_union (1 2 0) 1 r) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2SOF94) (exists mp_union (0 1 2) 2 __t2uCs95 __t2SOF94) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_union (0 1 2) 3 (0 1 2) __t2uCs95 __t2SOF94 __t1Mtu99) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t9ory98) (join mp_msk_ans (0 1) 2 __t9ory98 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join mp_union_ans (0 1) 1 __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask879 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index861;  slog::Index** mbranchindex862;  slog::Index** mp_mskindex863;  slog::Index** mp_msk_ansindex864;  slog::Index** mp_unionindex865;  slog::Index** mbranchindex866;  slog::Index** mp_unionindex867;  slog::Index** mbranchindex868;  slog::Index** mp_unionindex869;  slog::Index** mp_mskindex870;  slog::Index** mp_msk_ansindex871;  slog::Index** mp_unionindex872;  slog::Index** mp_union_ansindex873;  slog::Index** mbranchdelta874;  slog::Index** mbranchdelta875;  slog::Index** mp_uniondelta876;  slog::Index** mp_mskdelta877;  slog::Index** mp_uniondelta878;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord880({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel881 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index861 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 3, 4, 0});
      slog::Relation* readrel883 = db->getRelation("mbranch");
      mbranchindex862 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("mp_msk");
      mp_mskindex863 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({0, 1});
      slog::Relation* readrel887 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex864 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("mp_union");
      mp_unionindex865 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 3, 4, 0});
      slog::Relation* readrel891 = db->getRelation("mbranch");
      mbranchindex866 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 3, 4, 0});
      slog::Relation* readrel893 = db->getRelation("mbranch");
      mbranchdelta874 = readrel893->getIndex(ord892, true);
      std::vector<u16> ord894({0, 1, 2});
      slog::Relation* readrel895 = db->getRelation("mp_union");
      mp_unionindex867 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({1, 2, 3, 4, 0});
      slog::Relation* readrel897 = db->getRelation("mbranch");
      mbranchindex868 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 2, 3, 4, 0});
      slog::Relation* readrel899 = db->getRelation("mbranch");
      mbranchdelta875 = readrel899->getIndex(ord898, true);
      std::vector<u16> ord900({0, 1, 2});
      slog::Relation* readrel901 = db->getRelation("mp_union");
      mp_unionindex869 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({0, 1, 2});
      slog::Relation* readrel903 = db->getRelation("mp_union");
      mp_uniondelta876 = readrel903->getIndex(ord902, true);
      std::vector<u16> ord904({1, 2, 0});
      slog::Relation* readrel905 = db->getRelation("mp_msk");
      mp_mskindex870 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({1, 2, 0});
      slog::Relation* readrel907 = db->getRelation("mp_msk");
      mp_mskdelta877 = readrel907->getIndex(ord906, true);
      std::vector<u16> ord908({0, 1});
      slog::Relation* readrel909 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex871 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 0});
      slog::Relation* readrel911 = db->getRelation("mp_union");
      mp_unionindex872 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 0});
      slog::Relation* readrel913 = db->getRelation("mp_union");
      mp_uniondelta878 = readrel913->getIndex(ord912, true);
      std::vector<u16> ord914({0, 1});
      slog::Relation* readrel915 = db->getRelation("mp_union_ans");
      mp_union_ansindex873 = readrel915->getIndex(ord914, false);
  
    }
    ReadTask879(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[0];
        u64 v_c123 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c24 = _t[4];
        u64 v_c9 = _t[5];
        u64 v_c25 = _t[6];
        u64 v_c10 = _t[7];
        u64 v_c26 = _t[8];
        u64 v_c27 = _t[9];
        u64 v_c144 = _prim_lt(db, v_c24, v_c8);
        if (v_c144 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
        if (!v_c144) return;
        slog::join_probe<9,9>($sup5638x98x0x0x0index861, std::array<u64,9>{v_c9, v_c7, v_c8, v_c10, v_c121, v_c24, v_c25, v_c26, v_c27}, [&](const std::array<u64,9>& m917) {
          if (!slog::exists_probe<5,4>(mbranchindex862, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex863, std::array<u64,3>{v_c25, v_c8, v_c123})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex864, std::array<u64,2>{v_c123, v_c9})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex865, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex866, mbranchdelta874, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m918) {
            u64 v_c120 = m918[4];
            if (!slog::exists_probe<3,2>(mp_unionindex867, std::array<u64,3>{v_c121, v_c120, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex868, mbranchdelta875, std::array<u64,5>{v_c25, v_c24, v_c26, v_c27, 0}, [&](const std::array<u64,5>& m919) {
              u64 v_c124 = m919[4];
              slog::join_probe_old<3,3>(mp_unionindex869, mp_uniondelta876, std::array<u64,3>{v_c121, v_c120, v_c124}, [&](const std::array<u64,3>& m920) {
                slog::join_probe_old<3,3>(mp_mskindex870, mp_mskdelta877, std::array<u64,3>{v_c25, v_c8, v_c123}, [&](const std::array<u64,3>& m921) {
                  slog::join_probe<2,2>(mp_msk_ansindex871, std::array<u64,2>{v_c123, v_c9}, [&](const std::array<u64,2>& m922) {
                    slog::join_probe_old<3,2>(mp_unionindex872, mp_uniondelta878, std::array<u64,3>{v_c10, v_c124, 0}, [&](const std::array<u64,3>& m923) {
                      u64 v_c125 = m923[2];
                      slog::join_probe<2,1>(mp_union_ansindex873, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m924) {
                        u64 v_c19 = m924[1];
                        u64 v_c126 = _prim_band(db, v_c25, v_c8);
                        if (v_c126 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c145 = _prim_gt(db, v_c126, v_c119);
                        if (v_c145 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c145) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c19, v_c7, v_c8, v_c9});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask879* _cont = new ReadTask879(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask879(db,b), false);
}

