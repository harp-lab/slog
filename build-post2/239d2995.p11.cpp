
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1b2483991f3f37e4463261cd;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const8c1f1046219ddd216a023f79;
extern u64 v_const9cfb09b7c00913be7566a50e;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd9f3167b950244706dc6dbb2;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c6ea2ad2d2425c003(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst7kPx37 const5feceb66ffc86f38d952786c)) (scan mleaf __t3oQK38 j v) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t3oQK38 k __t2e0k39) (neq j k)) (head (emit mp_has0_ans (0 1) __t2e0k39 __tconst7kPx37)) map.slog:59 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index0;  slog::Index** mp_has0delta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("mp_has0");
      mp_has0index0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("mp_has0");
      mp_has0delta1 = readrel8->getIndex(ord7, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(mp_has0index0, mp_has0delta1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c4 = m9[1]; u64 v_c5 = m9[2];
          if (v_c2 == v_c4) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c0}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:59", "delta:mleaf", _fires);
  
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
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (body (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (exists mp_put_ans (0 1) 1 __t0yI380) (exists mp_put (2 3 0 1) 2 __tconst2ARJ85 __tconst4DUy84) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst35sq82 __tconst2cGK81 __t1P9g83 __v0) (join mp_put_ans (0 1) 2 __t0yI380 __v0) (exists mp_put_ans (0 1) 1 __t1P9g83) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst2ARJ85 __tconst4DUy84 __t9RS986 __v1) (join mp_put_ans (0 1) 2 __t1P9g83 __v1) (join mp_put_ans (0 1) 1 __t9RS986 r)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex10;  slog::Index** mp_put_ansindex11;  slog::Index** mp_putindex12;  slog::Index** mp_putindex13;  slog::Index** mp_put_ansindex14;  slog::Index** mp_put_ansindex15;  slog::Index** mp_putindex16;  slog::Index** mp_put_ansindex17;  slog::Index** mp_put_ansindex18;  slog::Index** mp_putdelta19;  slog::Index** mp_putdelta20;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("canon");
      head_index[0] = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({2, 3, 0, 1});
      slog::Relation* readrel25 = db->getRelation("mp_put");
      driver_index = readrel25->getIndex(ord24, true);
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("_enum");
      _enumindex10 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("mp_put_ans");
      mp_put_ansindex11 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({2, 3, 0, 1});
      slog::Relation* readrel31 = db->getRelation("mp_put");
      mp_putindex12 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({2, 3, 0, 1});
      slog::Relation* readrel33 = db->getRelation("mp_put");
      mp_putindex13 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 3, 0, 1});
      slog::Relation* readrel35 = db->getRelation("mp_put");
      mp_putdelta19 = readrel35->getIndex(ord34, true);
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("mp_put_ans");
      mp_put_ansindex14 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1});
      slog::Relation* readrel39 = db->getRelation("mp_put_ans");
      mp_put_ansindex15 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({2, 3, 0, 1});
      slog::Relation* readrel41 = db->getRelation("mp_put");
      mp_putindex16 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({2, 3, 0, 1});
      slog::Relation* readrel43 = db->getRelation("mp_put");
      mp_putdelta20 = readrel43->getIndex(ord42, true);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("mp_put_ans");
      mp_put_ansindex17 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("mp_put_ans");
      mp_put_ansindex18 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd01925b37634a1a9d24159d8;
      u64 v_c7 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c8 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c9 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c10 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c11 = v_const4a44dc15364204a80fe80e90;
      u64 v_c12 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c8, v_c7, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m48) {
        u64 v_c13 = m48[2];
        u64 v_c14 = m48[3];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<2,2>(_enumindex10, std::array<u64,2>{v_c14, v_c6}, [&](const std::array<u64,2>& m49) {
          if (!slog::exists_probe<2,1>(mp_put_ansindex11, std::array<u64,2>{v_c13, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex12, std::array<u64,4>{v_c12, v_c11, 0, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex13, mp_putdelta19, std::array<u64,4>{v_c10, v_c9, 0, 0}, [&](const std::array<u64,4>& m50) {
            u64 v_c15 = m50[2]; u64 v_c16 = m50[3];
            slog::join_probe<2,2>(mp_put_ansindex14, std::array<u64,2>{v_c13, v_c16}, [&](const std::array<u64,2>& m51) {
              if (!slog::exists_probe<2,1>(mp_put_ansindex15, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe_old<4,2>(mp_putindex16, mp_putdelta20, std::array<u64,4>{v_c12, v_c11, 0, 0}, [&](const std::array<u64,4>& m52) {
                u64 v_c17 = m52[2]; u64 v_c18 = m52[3];
                slog::join_probe<2,2>(mp_put_ansindex17, std::array<u64,2>{v_c15, v_c18}, [&](const std::array<u64,2>& m53) {
                  slog::join_probe<2,1>(mp_put_ansindex18, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m54) {
                    u64 v_c19 = m54[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre (let __tconst1GO9299 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t6Y68302 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t6Y68302 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t0IP7301 l p r) (neq p __v0) (exists mp_has0 (0 2 1) 2 __t0IP7301 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8ocD300) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t0IP7301 k __t8ocD300)) (head (emit mp_has0_ans (0 1) __t0IP7301 __tconst1GO9299)) map.slog:60 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex55;  slog::Index** mbranchindex56;  slog::Index** mp_has0index57;  slog::Index** $sup5638x59x0x0x0index58;  slog::Index** mp_has0index59;  slog::Index** mbranchindex60;  slog::Index** mp_has0index61;  slog::Index** mp_mskdelta62;  slog::Index** $sup5638x59x0x0x0delta63;  slog::Index** mbranchdelta64;  slog::Index** mp_has0delta65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord69({0, 1, 2});
      slog::Relation* readrel70 = db->getRelation("mp_msk");
      mp_mskindex55 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 1, 2});
      slog::Relation* readrel72 = db->getRelation("mp_msk");
      mp_mskdelta62 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({2, 0, 1, 3, 4});
      slog::Relation* readrel74 = db->getRelation("mbranch");
      mbranchindex56 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({2, 0, 1});
      slog::Relation* readrel76 = db->getRelation("mp_has0");
      mp_has0index57 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel78 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index58 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel80 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0delta63 = readrel80->getIndex(ord79, true);
      std::vector<u16> ord81({0, 2, 1});
      slog::Relation* readrel82 = db->getRelation("mp_has0");
      mp_has0index59 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 3, 4, 0});
      slog::Relation* readrel84 = db->getRelation("mbranch");
      mbranchindex60 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 2, 3, 4, 0});
      slog::Relation* readrel86 = db->getRelation("mbranch");
      mbranchdelta64 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 2, 1});
      slog::Relation* readrel88 = db->getRelation("mp_has0");
      mp_has0index61 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 2, 1});
      slog::Relation* readrel90 = db->getRelation("mp_has0");
      mp_has0delta65 = readrel90->getIndex(ord89, true);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex55, mp_mskdelta62, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m91) {
          u64 v_c4 = m91[1]; u64 v_c22 = m91[2];
          if (!slog::exists_probe<5,1>(mbranchindex56, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index57, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x59x0x0x0index58, $sup5638x59x0x0x0delta63, std::array<u64,6>{v_c4, v_c22, 0, 0, 0, 0}, [&](const std::array<u64,6>& m92) {
            u64 v_c23 = m92[2]; u64 v_c24 = m92[3]; u64 v_c25 = m92[4]; u64 v_c19 = m92[5];
            if (v_c25 == v_c16) return;
            if (!slog::exists_probe<3,2>(mp_has0index59, std::array<u64,3>{v_c23, v_c4, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex60, mbranchdelta64, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m93) {
              u64 v_c26 = m93[4];
              slog::join_probe_old<3,3>(mp_has0index61, mp_has0delta65, std::array<u64,3>{v_c23, v_c4, v_c26}, [&](const std::array<u64,3>& m94) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c20}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __tconst0Xtg73 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x0 __t1I5N72 k l m p r v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t1I5N72) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t1I5N72 k v __t0q1c75) (exists mp_msk (1 2 0) 3 k m __t0q1c75) (exists mp_msk_ans (0 1) 2 __t0q1c75 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t687K71) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t687K71 k __t1I5N72 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0q1c75) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t9fJL76) (join mp_msk_ans (0 1) 2 __t0q1c75 p) (join mp_put_ans (0 1) 1 __t9fJL76 __v0) (let __t4r9774 (band k m)) (cmp lt __t4r9774 __tconst0Xtg73)) (head (emit-temp temp4kFO1073 __t1I5N72 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4uw870 p m __v0 r)) map.slog:41 #f)
  class ReadTask114 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex95;  slog::Index** mp_putindex96;  slog::Index** mp_mskindex97;  slog::Index** mp_putindex98;  slog::Index** mp_msk_ansindex99;  slog::Index** $sup5638x40x0x0x1index100;  slog::Index** mp_mskindex101;  slog::Index** mp_msk_ansindex102;  slog::Index** mbranchindex103;  slog::Index** mp_putindex104;  slog::Index** mp_mskindex105;  slog::Index** mp_putindex106;  slog::Index** mp_msk_ansindex107;  slog::Index** mp_put_ansindex108;  slog::Index** $sup5638x40x0x0x1delta109;  slog::Index** mbranchdelta110;  slog::Index** mp_putdelta111;  slog::Index** mp_mskdelta112;  slog::Index** mp_putdelta113;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4kFO1073");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord115({1, 2, 3, 4, 0});
      slog::Relation* readrel116 = db->getRelation("mbranch");
      mbranchindex95 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({2, 3, 0, 1});
      slog::Relation* readrel118 = db->getRelation("mp_put");
      mp_putindex96 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 2, 0});
      slog::Relation* readrel120 = db->getRelation("mp_msk");
      mp_mskindex97 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 3, 0});
      slog::Relation* readrel122 = db->getRelation("mp_put");
      mp_putindex98 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 0});
      slog::Relation* readrel124 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex99 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel126 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index100 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel128 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta109 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({1, 2, 0});
      slog::Relation* readrel130 = db->getRelation("mp_msk");
      mp_mskindex101 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex102 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 3, 4, 0});
      slog::Relation* readrel134 = db->getRelation("mbranch");
      mbranchindex103 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 3, 4, 0});
      slog::Relation* readrel136 = db->getRelation("mbranch");
      mbranchdelta110 = readrel136->getIndex(ord135, true);
      std::vector<u16> ord137({1, 2, 0, 3});
      slog::Relation* readrel138 = db->getRelation("mp_put");
      mp_putindex104 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 0, 3});
      slog::Relation* readrel140 = db->getRelation("mp_put");
      mp_putdelta111 = readrel140->getIndex(ord139, true);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("mp_msk");
      mp_mskindex105 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("mp_msk");
      mp_mskdelta112 = readrel144->getIndex(ord143, true);
      std::vector<u16> ord145({1, 2, 3, 0});
      slog::Relation* readrel146 = db->getRelation("mp_put");
      mp_putindex106 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 2, 3, 0});
      slog::Relation* readrel148 = db->getRelation("mp_put");
      mp_putdelta113 = readrel148->getIndex(ord147, true);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex107 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("mp_put_ans");
      mp_put_ansindex108 = readrel152->getIndex(ord151, false);
  
    }
    ReadTask114(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c19 = _t[5];
        u64 v_c3 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex95, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex96, std::array<u64,4>{v_c4, v_c3, v_c28, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex97, std::array<u64,3>{v_c4, v_c22, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex98, std::array<u64,4>{v_c24, v_c4, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex99, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe_old<8,7>($sup5638x40x0x0x1index100, $sup5638x40x0x0x1delta109, std::array<u64,8>{v_c24, v_c22, v_c25, v_c19, v_c28, v_c4, v_c3, 0}, [&](const std::array<u64,8>& m153) {
          u64 v_c29 = m153[7];
          if (!slog::exists_probe<3,3>(mp_mskindex101, std::array<u64,3>{v_c4, v_c22, v_c29})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex102, std::array<u64,2>{v_c29, v_c25})) return;
          slog::join_probe_old<5,4>(mbranchindex103, mbranchdelta110, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m154) {
            u64 v_c30 = m154[4];
            slog::join_probe_old<4,4>(mp_putindex104, mp_putdelta111, std::array<u64,4>{v_c30, v_c4, v_c28, v_c3}, [&](const std::array<u64,4>& m155) {
              slog::join_probe_old<3,3>(mp_mskindex105, mp_mskdelta112, std::array<u64,3>{v_c4, v_c22, v_c29}, [&](const std::array<u64,3>& m156) {
                slog::join_probe_old<4,3>(mp_putindex106, mp_putdelta113, std::array<u64,4>{v_c24, v_c4, v_c3, 0}, [&](const std::array<u64,4>& m157) {
                  u64 v_c31 = m157[3];
                  slog::join_probe<2,2>(mp_msk_ansindex107, std::array<u64,2>{v_c29, v_c25}, [&](const std::array<u64,2>& m158) {
                    slog::join_probe<2,1>(mp_put_ansindex108, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m159) {
                      u64 v_c16 = m159[1];
                      u64 v_c32 = _prim_band(db, v_c4, v_c22);
                      if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c33 = _prim_lt(db, v_c32, v_c27);
                      if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c33) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c28, v_c16, v_c22, v_c25, v_c19});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c22, v_c16, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x0", _fires);
  
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
  // (crule (pre) (scan temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (body (join mbranch (1 2 3 4 0) 4 __v2 __v3 t0 t1 __t8sDR50)) (head (emit mp_join_ans (0 1) __t6Puw51 __t8sDR50)) map.slog:26 #f)
  class ReadTask162 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex161;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join_ans");
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("mp_join_ans");
      head_index[0] = readrel164->getIndex(ord163, false);
      outer_rel = db->getRelation("temp7KpW1055");
      std::vector<u16> ord165({1, 2, 3, 4, 0});
      slog::Relation* readrel166 = db->getRelation("mbranch");
      mbranchindex161 = readrel166->getIndex(ord165, false);
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        u64 v_c38 = _t[4];
        slog::join_probe<5,4>(mbranchindex161, std::array<u64,5>{v_c35, v_c36, v_c37, v_c38, 0}, [&](const std::array<u64,5>& m167) {
          u64 v_c39 = m167[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c39}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp7KpW1055", _fires);
  
      if (!_done)
      {
        ReadTask162* _cont = new ReadTask162(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t1lh0397 __v1) (body (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t1lh0397 __v1) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t1lh0397) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v3) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t1lh0397 __v1 __v3) (join-old mp_hsb_ans (0 1) 1 (0 1) __t1lh0397 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t1lh0397 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t1lh0397 __v0 __v3 __v1 __t4lFL393 dup0XDZ1075 dup8FhK1076 p0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join mp_msk_ans (0 1) 1 __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask187 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex168;  slog::Index** $sup5638x29x0x0x2index169;  slog::Index** $sup5638x29x0x0x1index170;  slog::Index** mp_mskindex171;  slog::Index** mp_hsb_ansindex172;  slog::Index** $sup5638x29x0x0x2index173;  slog::Index** mp_hsb_ansindex174;  slog::Index** $sup5638x29x0x0x1index175;  slog::Index** $sup5638x29x0x0x2index176;  slog::Index** $sup5638x29x0x0x1index177;  slog::Index** $sup5638x29x0x0x0index178;  slog::Index** mp_joinindex179;  slog::Index** mp_mskindex180;  slog::Index** mp_msk_ansindex181;  slog::Index** mp_hsbindex182;  slog::Index** mp_hsb_ansdelta183;  slog::Index** mp_joindelta184;  slog::Index** mp_mskdelta185;  slog::Index** mp_hsbdelta186;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex168 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel191 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index169 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel193 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index170 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({2, 0, 1});
      slog::Relation* readrel195 = db->getRelation("mp_msk");
      mp_mskindex171 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex172 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel199 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index173 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex174 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta183 = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel205 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index175 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel207 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index176 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel209 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index177 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0, 2, 3, 4});
      slog::Relation* readrel211 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index178 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 3, 4, 0});
      slog::Relation* readrel213 = db->getRelation("mp_join");
      mp_joinindex179 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 3, 4, 0});
      slog::Relation* readrel215 = db->getRelation("mp_join");
      mp_joindelta184 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({1, 2, 0});
      slog::Relation* readrel217 = db->getRelation("mp_msk");
      mp_mskindex180 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("mp_msk");
      mp_mskdelta185 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex181 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("mp_hsb");
      mp_hsbindex182 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("mp_hsb");
      mp_hsbdelta186 = readrel225->getIndex(ord224, true);
  
    }
    ReadTask187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c18 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex168, std::array<u64,2>{v_c41, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index169, std::array<u64,11>{v_c41, v_c18, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index170, std::array<u64,7>{v_c41, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex171, std::array<u64,3>{v_c18, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex172, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m226) {
          u64 v_c36 = m226[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index173, std::array<u64,11>{v_c41, v_c18, v_c36, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex174, mp_hsb_ansdelta183, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m227) {
            u64 v_c16 = m227[1];
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index175, std::array<u64,7>{v_c41, v_c16, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index176, std::array<u64,11>{v_c41, v_c16, v_c36, v_c18, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m228) {
              u64 v_c42 = m228[4]; u64 v_c43 = m228[5]; u64 v_c44 = m228[6]; u64 v_c45 = m228[7]; u64 v_c46 = m228[8]; u64 v_c37 = m228[9]; u64 v_c38 = m228[10];
              if (v_c41 != v_c44) return;
              if (v_c41 != v_c43) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index177, std::array<u64,7>{v_c42, v_c45, v_c46, v_c37, v_c38, v_c41, v_c16}, [&](const std::array<u64,7>& m229) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index178, std::array<u64,5>{v_c45, v_c42, v_c46, v_c37, v_c38}, [&](const std::array<u64,5>& m230) {
                  slog::join_probe_old<5,5>(mp_joinindex179, mp_joindelta184, std::array<u64,5>{v_c45, v_c37, v_c46, v_c38, v_c42}, [&](const std::array<u64,5>& m231) {
                    slog::join_probe_old<3,2>(mp_mskindex180, mp_mskdelta185, std::array<u64,3>{v_c45, v_c18, 0}, [&](const std::array<u64,3>& m232) {
                      u64 v_c47 = m232[2];
                      slog::join_probe<2,1>(mp_msk_ansindex181, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m233) {
                        u64 v_c35 = m233[1];
                        u64 v_c48 = _prim_bxor(db, v_c45, v_c46);
                        if (v_c48 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex182, mp_hsbdelta186, std::array<u64,2>{v_c41, v_c48}, [&](const std::array<u64,2>& m234) {
                          u64 v_c49 = _prim_band(db, v_c45, v_c16);
                          if (v_c49 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c50 = _prim_gt(db, v_c49, v_c40);
                          if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c50) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c42, v_c35, v_c36, v_c37, v_c38});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c36, v_c38, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre) (scan mbranch __t9YDI315 p m l r) (body (exists mp_union (1 2 0) 1 __t9YDI315) (join mbranch (1 2 3 4 0) 2 p m u v __t5rgl314) (join-old mp_union (1 2 0) 2 (1 2 0) __t9YDI315 __t5rgl314 __t4nmW316)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t4nmW316 l m p r u v)) map.slog:94 #f)
  class ReadTask240 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex236;  slog::Index** mbranchindex237;  slog::Index** mp_unionindex238;  slog::Index** mp_uniondelta239;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord241({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel242 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel242->getIndex(ord241, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("mp_union");
      mp_unionindex236 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 2, 3, 4, 0});
      slog::Relation* readrel246 = db->getRelation("mbranch");
      mbranchindex237 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 2, 0});
      slog::Relation* readrel248 = db->getRelation("mp_union");
      mp_unionindex238 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("mp_union");
      mp_uniondelta239 = readrel250->getIndex(ord249, true);
  
    }
    ReadTask240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<3,1>(mp_unionindex236, std::array<u64,3>{v_c51, 0, 0})) return;
        slog::join_probe<5,2>(mbranchindex237, std::array<u64,5>{v_c25, v_c22, 0, 0, 0}, [&](const std::array<u64,5>& m251) {
          u64 v_c52 = m251[2]; u64 v_c3 = m251[3]; u64 v_c53 = m251[4];
          slog::join_probe_old<3,2>(mp_unionindex238, mp_uniondelta239, std::array<u64,3>{v_c51, v_c53, 0}, [&](const std::array<u64,3>& m252) {
            u64 v_c54 = m252[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c54, v_c24, v_c22, v_c25, v_c19, v_c52, v_c3}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask240* _cont = new ReadTask240(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask240(db,b), false);
  // (crule (pre) (scan mp_join __t7HEI219 p __t0o62217 q __t0BoC218) (body (exists mbranch (0 1 2 3 4) 2 __t0o62217 p) (exists mbranch (0 1 2 3 4) 2 __t0BoC218 q) (exists mp_union (1 2 0) 2 __t0o62217 __t0BoC218) (exists mp_msk (1 2 0) 1 p) (exists mp_join_ans (0 1) 1 __t7HEI219) (join $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t0o62217 __t0BoC218 __t5xrH216 l m n r u v) (cmp lt m n) (join mbranch (1 2 3 4 0) 5 p m l r __t0o62217) (join mbranch (1 2 3 4 0) 5 q n u v __t0BoC218) (join mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask266 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex253;  slog::Index** mbranchindex254;  slog::Index** mp_unionindex255;  slog::Index** mp_mskindex256;  slog::Index** mp_join_ansindex257;  slog::Index** $sup5638x110x0x0x0index258;  slog::Index** mbranchindex259;  slog::Index** mbranchindex260;  slog::Index** mp_unionindex261;  slog::Index** mp_mskindex262;  slog::Index** mp_msk_ansindex263;  slog::Index** mp_join_ansindex264;  slog::Index** mp_mskdelta265;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord267({0, 1});
      slog::Relation* readrel268 = db->getRelation("mp_union_ans");
      head_index[0] = readrel268->getIndex(ord267, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord269({0, 1, 2, 3, 4});
      slog::Relation* readrel270 = db->getRelation("mbranch");
      mbranchindex253 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({0, 1, 2, 3, 4});
      slog::Relation* readrel272 = db->getRelation("mbranch");
      mbranchindex254 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 2, 0});
      slog::Relation* readrel274 = db->getRelation("mp_union");
      mp_unionindex255 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({1, 2, 0});
      slog::Relation* readrel276 = db->getRelation("mp_msk");
      mp_mskindex256 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("mp_join_ans");
      mp_join_ansindex257 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel280 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index258 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 3, 4, 0});
      slog::Relation* readrel282 = db->getRelation("mbranch");
      mbranchindex259 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 3, 4, 0});
      slog::Relation* readrel284 = db->getRelation("mbranch");
      mbranchindex260 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1, 2});
      slog::Relation* readrel286 = db->getRelation("mp_union");
      mp_unionindex261 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 0});
      slog::Relation* readrel288 = db->getRelation("mp_msk");
      mp_mskindex262 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0});
      slog::Relation* readrel290 = db->getRelation("mp_msk");
      mp_mskdelta265 = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex263 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_join_ans");
      mp_join_ansindex264 = readrel294->getIndex(ord293, false);
  
    }
    ReadTask266(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c58 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex253, std::array<u64,5>{v_c56, v_c25, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex254, std::array<u64,5>{v_c58, v_c57, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex255, std::array<u64,3>{v_c56, v_c58, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex256, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex257, std::array<u64,2>{v_c55, 0})) return;
        slog::join_probe<11,4>($sup5638x110x0x0x0index258, std::array<u64,11>{v_c25, v_c57, v_c56, v_c58, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m295) {
          u64 v_c59 = m295[4]; u64 v_c24 = m295[5]; u64 v_c22 = m295[6]; u64 v_c60 = m295[7]; u64 v_c19 = m295[8]; u64 v_c52 = m295[9]; u64 v_c3 = m295[10];
          u64 v_c61 = _prim_lt(db, v_c22, v_c60);
          if (v_c61 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c61) return;
          slog::join_probe<5,5>(mbranchindex259, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c56}, [&](const std::array<u64,5>& m297) {
            slog::join_probe<5,5>(mbranchindex260, std::array<u64,5>{v_c57, v_c60, v_c52, v_c3, v_c58}, [&](const std::array<u64,5>& m298) {
              slog::join_probe<3,3>(mp_unionindex261, std::array<u64,3>{v_c59, v_c56, v_c58}, [&](const std::array<u64,3>& m299) {
                slog::join_probe_old<3,2>(mp_mskindex262, mp_mskdelta265, std::array<u64,3>{v_c25, v_c60, 0}, [&](const std::array<u64,3>& m300) {
                  u64 v_c62 = m300[2];
                  slog::join_probe<2,1>(mp_msk_ansindex263, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m301) {
                    u64 v_c16 = m301[1];
                    if (v_c57 == v_c16) return;
                    slog::join_probe<2,1>(mp_join_ansindex264, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m302) {
                      u64 v_c63 = m302[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask266* _cont = new ReadTask266(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask266(db,b), false);
  // (crule (pre) (scan $sup5638x101x0x0x0 __t4ZhK374 l m n p q r __t8hMI375 __t5XzA376 u v) (body (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t8hMI375) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5XzA376) (exists mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t8hMI375 q __t5XzA376 __t35Cd377) (join-old mp_union (0 1 2) 3 (0 1 2) __t4ZhK374 __t8hMI375 __t5XzA376) (exists mp_join_ans (0 1) 1 __t35Cd377) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask318 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex303;  slog::Index** mbranchindex304;  slog::Index** mp_unionindex305;  slog::Index** mp_mskindex306;  slog::Index** mp_joinindex307;  slog::Index** mp_unionindex308;  slog::Index** mp_join_ansindex309;  slog::Index** mp_mskindex310;  slog::Index** mp_msk_ansindex311;  slog::Index** mp_join_ansindex312;  slog::Index** mbranchdelta313;  slog::Index** mbranchdelta314;  slog::Index** mp_joindelta315;  slog::Index** mp_uniondelta316;  slog::Index** mp_mskdelta317;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("mp_union_ans");
      head_index[0] = readrel320->getIndex(ord319, false);
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord321({1, 2, 3, 4, 0});
      slog::Relation* readrel322 = db->getRelation("mbranch");
      mbranchindex303 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 2, 3, 4, 0});
      slog::Relation* readrel324 = db->getRelation("mbranch");
      mbranchdelta313 = readrel324->getIndex(ord323, true);
      std::vector<u16> ord325({1, 2, 3, 4, 0});
      slog::Relation* readrel326 = db->getRelation("mbranch");
      mbranchindex304 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 3, 4, 0});
      slog::Relation* readrel328 = db->getRelation("mbranch");
      mbranchdelta314 = readrel328->getIndex(ord327, true);
      std::vector<u16> ord329({0, 1, 2});
      slog::Relation* readrel330 = db->getRelation("mp_union");
      mp_unionindex305 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("mp_msk");
      mp_mskindex306 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 3, 4, 0});
      slog::Relation* readrel334 = db->getRelation("mp_join");
      mp_joinindex307 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 2, 3, 4, 0});
      slog::Relation* readrel336 = db->getRelation("mp_join");
      mp_joindelta315 = readrel336->getIndex(ord335, true);
      std::vector<u16> ord337({0, 1, 2});
      slog::Relation* readrel338 = db->getRelation("mp_union");
      mp_unionindex308 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1, 2});
      slog::Relation* readrel340 = db->getRelation("mp_union");
      mp_uniondelta316 = readrel340->getIndex(ord339, true);
      std::vector<u16> ord341({0, 1});
      slog::Relation* readrel342 = db->getRelation("mp_join_ans");
      mp_join_ansindex309 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("mp_msk");
      mp_mskindex310 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 2, 0});
      slog::Relation* readrel346 = db->getRelation("mp_msk");
      mp_mskdelta317 = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({0, 1});
      slog::Relation* readrel348 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex311 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1});
      slog::Relation* readrel350 = db->getRelation("mp_join_ans");
      mp_join_ansindex312 = readrel350->getIndex(ord349, false);
  
    }
    ReadTask318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c65 = _t[7];
        u64 v_c66 = _t[8];
        u64 v_c52 = _t[9];
        u64 v_c3 = _t[10];
        u64 v_c67 = _prim_lt(db, v_c60, v_c22);
        if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
        if (!v_c67) return;
        slog::join_probe_old<5,5>(mbranchindex303, mbranchdelta313, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c65}, [&](const std::array<u64,5>& m352) {
          slog::join_probe_old<5,5>(mbranchindex304, mbranchdelta314, std::array<u64,5>{v_c57, v_c60, v_c52, v_c3, v_c66}, [&](const std::array<u64,5>& m353) {
            if (!slog::exists_probe<3,3>(mp_unionindex305, std::array<u64,3>{v_c64, v_c65, v_c66})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex306, std::array<u64,3>{v_c57, v_c22, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex307, mp_joindelta315, std::array<u64,5>{v_c25, v_c65, v_c57, v_c66, 0}, [&](const std::array<u64,5>& m354) {
              u64 v_c68 = m354[4];
              slog::join_probe_old<3,3>(mp_unionindex308, mp_uniondelta316, std::array<u64,3>{v_c64, v_c65, v_c66}, [&](const std::array<u64,3>& m355) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex309, std::array<u64,2>{v_c68, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex310, mp_mskdelta317, std::array<u64,3>{v_c57, v_c22, 0}, [&](const std::array<u64,3>& m356) {
                  u64 v_c69 = m356[2];
                  slog::join_probe<2,1>(mp_msk_ansindex311, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m357) {
                    u64 v_c16 = m357[1];
                    if (v_c25 == v_c16) return;
                    slog::join_probe<2,1>(mp_join_ansindex312, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m358) {
                      u64 v_c63 = m358[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask318* _cont = new ReadTask318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask318(db,b), false);
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t9RS986 r) (body (exists mp_put (2 3 0 1) 2 __tconst1tgO78 __tconst3k9477) (exists _enum (1 0) 1 __tconst03sd851) (exists mp_put (2 3 0 1) 2 __tconst35sq82 __tconst2cGK81) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst2ARJ85 __tconst4DUy84 __t9RS986 __v1) (exists mp_put_ans (1 0) 1 __v1) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (exists mp_put_ans (0 1) 1 __t0yI380) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst35sq82 __tconst2cGK81 __t1P9g83 __v0) (join mp_put_ans (0 1) 2 __t0yI380 __v0) (join mp_put_ans (0 1) 2 __t1P9g83 __v1)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask373 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex359;  slog::Index** _enumindex360;  slog::Index** mp_putindex361;  slog::Index** mp_putindex362;  slog::Index** mp_put_ansindex363;  slog::Index** mp_putindex364;  slog::Index** _enumindex365;  slog::Index** mp_put_ansindex366;  slog::Index** mp_putindex367;  slog::Index** mp_put_ansindex368;  slog::Index** mp_put_ansindex369;  slog::Index** mp_putdelta370;  slog::Index** mp_putdelta371;  slog::Index** mp_putdelta372;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord374({0});
      slog::Relation* readrel375 = db->getRelation("canon");
      head_index[0] = readrel375->getIndex(ord374, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord376({2, 3, 0, 1});
      slog::Relation* readrel377 = db->getRelation("mp_put");
      mp_putindex359 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 0});
      slog::Relation* readrel379 = db->getRelation("_enum");
      _enumindex360 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({2, 3, 0, 1});
      slog::Relation* readrel381 = db->getRelation("mp_put");
      mp_putindex361 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({2, 3, 0, 1});
      slog::Relation* readrel383 = db->getRelation("mp_put");
      mp_putindex362 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({2, 3, 0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_put");
      mp_putdelta370 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({1, 0});
      slog::Relation* readrel387 = db->getRelation("mp_put_ans");
      mp_put_ansindex363 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 3, 0, 1});
      slog::Relation* readrel389 = db->getRelation("mp_put");
      mp_putindex364 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({2, 3, 0, 1});
      slog::Relation* readrel391 = db->getRelation("mp_put");
      mp_putdelta371 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("_enum");
      _enumindex365 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1});
      slog::Relation* readrel395 = db->getRelation("mp_put_ans");
      mp_put_ansindex366 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({2, 3, 0, 1});
      slog::Relation* readrel397 = db->getRelation("mp_put");
      mp_putindex367 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({2, 3, 0, 1});
      slog::Relation* readrel399 = db->getRelation("mp_put");
      mp_putdelta372 = readrel399->getIndex(ord398, true);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("mp_put_ans");
      mp_put_ansindex368 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("mp_put_ans");
      mp_put_ansindex369 = readrel403->getIndex(ord402, false);
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd01925b37634a1a9d24159d8;
      u64 v_c7 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c8 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c9 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c10 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c11 = v_const4a44dc15364204a80fe80e90;
      u64 v_c12 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c17 = _t[0];
        u64 v_c19 = _t[1];
        if (!slog::exists_probe<4,2>(mp_putindex359, std::array<u64,4>{v_c8, v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex360, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex361, std::array<u64,4>{v_c10, v_c9, 0, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex362, mp_putdelta370, std::array<u64,4>{v_c12, v_c11, v_c17, 0}, [&](const std::array<u64,4>& m404) {
          u64 v_c18 = m404[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex363, std::array<u64,2>{v_c18, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex364, mp_putdelta371, std::array<u64,4>{v_c8, v_c7, 0, 0}, [&](const std::array<u64,4>& m405) {
            u64 v_c13 = m405[2]; u64 v_c14 = m405[3];
            slog::join_probe<2,2>(_enumindex365, std::array<u64,2>{v_c14, v_c6}, [&](const std::array<u64,2>& m406) {
              if (!slog::exists_probe<2,1>(mp_put_ansindex366, std::array<u64,2>{v_c13, 0})) return;
              slog::join_probe_old<4,2>(mp_putindex367, mp_putdelta372, std::array<u64,4>{v_c10, v_c9, 0, 0}, [&](const std::array<u64,4>& m407) {
                u64 v_c15 = m407[2]; u64 v_c16 = m407[3];
                slog::join_probe<2,2>(mp_put_ansindex368, std::array<u64,2>{v_c13, v_c16}, [&](const std::array<u64,2>& m408) {
                  slog::join_probe<2,2>(mp_put_ansindex369, std::array<u64,2>{v_c15, v_c18}, [&](const std::array<u64,2>& m409) {
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  // (crule (pre (let __tconst5SJq610 constd01925b37634a1a9d24159d8)) (scan mp_union __t6qlN134 s __t6jVP133) (body (join _enum (0 1) 2 __t6jVP133 __tconst5SJq610)) (head (emit mp_union_ans (0 1) __t6qlN134 s)) map.slog:91 #f)
  class ReadTask411 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex410;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("mp_union_ans");
      head_index[0] = readrel413->getIndex(ord412, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("_enum");
      _enumindex410 = readrel415->getIndex(ord414, false);
  
    }
    ReadTask411(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_constd01925b37634a1a9d24159d8;
  
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
        u64 v_c73 = _t[2];
        slog::join_probe<2,2>(_enumindex410, std::array<u64,2>{v_c73, v_c70}, [&](const std::array<u64,2>& m416) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c72}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:91", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask411* _cont = new ReadTask411(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask411(db,b), false);
  // (crule (pre) (scan mp_del __t8UOT140 __t4LnY139 k) (body (join mbranch (0 1 2 3 4) 1 __t4LnY139 p m l r)) (head (emit $sup5638x81x0x0x0 (0 1 2 3 4 5) __t8UOT140 k l m p r)) map.slog:82 #f)
  class ReadTask418 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex417;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord419({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel420 = db->getRelation("$sup5638x81x0x0x0");
      head_index[0] = readrel420->getIndex(ord419, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord421({0, 1, 2, 3, 4});
      slog::Relation* readrel422 = db->getRelation("mbranch");
      mbranchindex417 = readrel422->getIndex(ord421, false);
  
    }
    ReadTask418(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c75 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<5,1>(mbranchindex417, std::array<u64,5>{v_c75, 0, 0, 0, 0}, [&](const std::array<u64,5>& m423) {
          u64 v_c25 = m423[1]; u64 v_c22 = m423[2]; u64 v_c24 = m423[3]; u64 v_c19 = m423[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c74, v_c4, v_c24, v_c22, v_c25, v_c19}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask418* _cont = new ReadTask418(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask418(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t6Hok114 r k) (body (exists $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (join $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 k r __t68rk111 l m p) (exists mp_has0 (0 2 1) 2 __t68rk111 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t032L110) (join mp_has0 (0 2 1) 3 __t68rk111 k __t032L110) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9QiO115) (join mp_msk_ans (0 1) 2 __t9QiO115 p) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index424;  slog::Index** mbranchindex425;  slog::Index** mp_has0index426;  slog::Index** mp_mskindex427;  slog::Index** mp_has0_ansindex428;  slog::Index** $sup5638x62x0x0x0index429;  slog::Index** mp_has0index430;  slog::Index** mp_mskindex431;  slog::Index** mp_msk_ansindex432;  slog::Index** mbranchindex433;  slog::Index** mp_has0index434;  slog::Index** mp_mskindex435;  slog::Index** mp_msk_ansindex436;  slog::Index** mp_mskdelta437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel440->getIndex(ord439, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord441({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel442 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index424 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({4, 0, 1, 2, 3});
      slog::Relation* readrel444 = db->getRelation("mbranch");
      mbranchindex425 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({2, 0, 1});
      slog::Relation* readrel446 = db->getRelation("mp_has0");
      mp_has0index426 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("mp_msk");
      mp_mskindex427 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({0, 1});
      slog::Relation* readrel450 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex428 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel452 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index429 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 2, 1});
      slog::Relation* readrel454 = db->getRelation("mp_has0");
      mp_has0index430 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 0});
      slog::Relation* readrel456 = db->getRelation("mp_msk");
      mp_mskindex431 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({1, 0});
      slog::Relation* readrel458 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex432 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 2, 3, 4, 0});
      slog::Relation* readrel460 = db->getRelation("mbranch");
      mbranchindex433 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({0, 2, 1});
      slog::Relation* readrel462 = db->getRelation("mp_has0");
      mp_has0index434 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 0});
      slog::Relation* readrel464 = db->getRelation("mp_msk");
      mp_mskindex435 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 0});
      slog::Relation* readrel466 = db->getRelation("mp_msk");
      mp_mskdelta437 = readrel466->getIndex(ord465, true);
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex436 = readrel468->getIndex(ord467, false);
  
    }
    ReadTask438(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c77 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x62x0x0x0index424, std::array<u64,6>{v_c4, v_c19, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex425, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index426, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex427, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(mp_has0_ansindex428, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m469) {
          u64 v_c78 = m469[1];
          slog::join_probe<6,2>($sup5638x62x0x0x0index429, std::array<u64,6>{v_c4, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,6>& m470) {
            u64 v_c79 = m470[2]; u64 v_c24 = m470[3]; u64 v_c22 = m470[4]; u64 v_c25 = m470[5];
            if (!slog::exists_probe<3,2>(mp_has0index430, std::array<u64,3>{v_c79, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex431, std::array<u64,3>{v_c4, v_c22, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex432, std::array<u64,2>{v_c25, 0})) return;
            slog::join_probe<5,4>(mbranchindex433, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m471) {
              u64 v_c80 = m471[4];
              slog::join_probe<3,3>(mp_has0index434, std::array<u64,3>{v_c79, v_c4, v_c80}, [&](const std::array<u64,3>& m472) {
                slog::join_probe_old<3,2>(mp_mskindex435, mp_mskdelta437, std::array<u64,3>{v_c4, v_c22, 0}, [&](const std::array<u64,3>& m473) {
                  u64 v_c81 = m473[2];
                  slog::join_probe<2,2>(mp_msk_ansindex436, std::array<u64,2>{v_c81, v_c25}, [&](const std::array<u64,2>& m474) {
                    u64 v_c82 = _prim_band(db, v_c4, v_c22);
                    if (v_c82 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c83 = _prim_gt(db, v_c82, v_c76);
                    if (v_c83 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c83) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c78}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0", _fires);
  
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
  // (crule (pre (let __trid3qEQ707 const1b2483991f3f37e4463261cd) (let __trel8IHU708 constdd7bbf31ce5f578b9805e840) (let __tcol90Az709 const5feceb66ffc86f38d952786c) (let __trel6T5V710 constdd7bbf31ce5f578b9805e840) (let __tcol3qTi711 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x0 __d0 k l m p r v) (body) (head (tycheck k (accept int) __trid3qEQ707 __trel8IHU708 __tcol90Az709 (1 2 3 4 0)) (tycheck m (accept int) __trid3qEQ707 __trel6T5V710 __tcol3qTi711 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __2vIW706 k m)) map.slog:41 #f)
  class ReadTask476 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const1b2483991f3f37e4463261cd;
      u64 v_c85 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
      u64 v_c87 = v_constdd7bbf31ce5f578b9805e840;
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
        u64 v_c89 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c19 = _t[5];
        u64 v_c3 = _t[6];
        ++_fires;
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c84, v_c85, v_c86, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c84, v_c87, v_c88, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c22}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask476* _cont = new ReadTask476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask476(db,b), false);
  // (crule (pre) (scan mp_msk __t185P265 q m) (body (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join mp_msk_ans (0 1) 1 __t185P265 p) (join $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t185P265 m n p q r u v)) map.slog:96 #f)
  class ReadTask480 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index477;  slog::Index** mp_msk_ansindex478;  slog::Index** $sup5638x95x0x0x0index479;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord481({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel482 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel482->getIndex(ord481, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord483({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel484 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index477 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex478 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel488 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index479 = readrel488->getIndex(ord487, false);
  
    }
    ReadTask480(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c90 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index477, std::array<u64,9>{v_c22, v_c57, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex478, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m489) {
          u64 v_c25 = m489[1];
          slog::join_probe<9,3>($sup5638x95x0x0x0index479, std::array<u64,9>{v_c22, v_c57, v_c25, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m490) {
            u64 v_c89 = m490[3]; u64 v_c24 = m490[4]; u64 v_c60 = m490[5]; u64 v_c19 = m490[6]; u64 v_c52 = m490[7]; u64 v_c3 = m490[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c89, v_c24, v_c90, v_c22, v_c60, v_c25, v_c57, v_c19, v_c52, v_c3}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask480* _cont = new ReadTask480(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask480(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t4mLe355 q) (body (exists $sup5638x107x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t4mLe355 q) (exists $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists mbranch (1 2 3 4 0) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4mLe355 p n) (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists mbranch (1 2 3 4 0) 2 q n) (exists mbranch (1 2 3 4 0) 1 p) (join-old $sup5638x107x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t4mLe355 n p q __t05l7352 l m r u v) (cmp lt m n) (join-old $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t05l7352 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 1 v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3rQ8350) (exists mp_union (2 0 1) 2 __t3rQ8350 __t05l7352) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_union (0 1 2) 3 (0 1 2) __t05l7352 __t6yxH356 __t3rQ8350) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join-old mp_union_ans (0 1) 1 (0 1) __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index491;  slog::Index** $sup5638x107x0x0x0index492;  slog::Index** mbranchindex493;  slog::Index** mp_mskindex494;  slog::Index** $sup5638x107x0x0x0index495;  slog::Index** mbranchindex496;  slog::Index** mbranchindex497;  slog::Index** $sup5638x107x0x0x1index498;  slog::Index** $sup5638x107x0x0x0index499;  slog::Index** mbranchindex500;  slog::Index** mp_unionindex501;  slog::Index** mbranchindex502;  slog::Index** mp_unionindex503;  slog::Index** mbranchindex504;  slog::Index** mp_unionindex505;  slog::Index** mp_unionindex506;  slog::Index** mp_union_ansindex507;  slog::Index** mp_mskdelta508;  slog::Index** $sup5638x107x0x0x1delta509;  slog::Index** $sup5638x107x0x0x0delta510;  slog::Index** mbranchdelta511;  slog::Index** mbranchdelta512;  slog::Index** mp_uniondelta513;  slog::Index** mp_uniondelta514;  slog::Index** mp_union_ansdelta515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord517({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel518 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index491 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel520 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index492 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 2, 3, 4, 0});
      slog::Relation* readrel522 = db->getRelation("mbranch");
      mbranchindex493 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1, 2});
      slog::Relation* readrel524 = db->getRelation("mp_msk");
      mp_mskindex494 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({0, 1, 2});
      slog::Relation* readrel526 = db->getRelation("mp_msk");
      mp_mskdelta508 = readrel526->getIndex(ord525, true);
      std::vector<u16> ord527({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel528 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index495 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 3, 4, 0});
      slog::Relation* readrel530 = db->getRelation("mbranch");
      mbranchindex496 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 3, 4, 0});
      slog::Relation* readrel532 = db->getRelation("mbranch");
      mbranchindex497 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel534 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index498 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel536 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta509 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel538 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index499 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel540 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0delta510 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({1, 2, 3, 4, 0});
      slog::Relation* readrel542 = db->getRelation("mbranch");
      mbranchindex500 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({2, 0, 1});
      slog::Relation* readrel544 = db->getRelation("mp_union");
      mp_unionindex501 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 2, 3, 4, 0});
      slog::Relation* readrel546 = db->getRelation("mbranch");
      mbranchindex502 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 3, 4, 0});
      slog::Relation* readrel548 = db->getRelation("mbranch");
      mbranchdelta511 = readrel548->getIndex(ord547, true);
      std::vector<u16> ord549({2, 0, 1});
      slog::Relation* readrel550 = db->getRelation("mp_union");
      mp_unionindex503 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 3, 4, 0});
      slog::Relation* readrel552 = db->getRelation("mbranch");
      mbranchindex504 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 3, 4, 0});
      slog::Relation* readrel554 = db->getRelation("mbranch");
      mbranchdelta512 = readrel554->getIndex(ord553, true);
      std::vector<u16> ord555({0, 1, 2});
      slog::Relation* readrel556 = db->getRelation("mp_union");
      mp_unionindex505 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("mp_union");
      mp_uniondelta513 = readrel558->getIndex(ord557, true);
      std::vector<u16> ord559({1, 2, 0});
      slog::Relation* readrel560 = db->getRelation("mp_union");
      mp_unionindex506 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("mp_union");
      mp_uniondelta514 = readrel562->getIndex(ord561, true);
      std::vector<u16> ord563({0, 1});
      slog::Relation* readrel564 = db->getRelation("mp_union_ans");
      mp_union_ansindex507 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({0, 1});
      slog::Relation* readrel566 = db->getRelation("mp_union_ans");
      mp_union_ansdelta515 = readrel566->getIndex(ord565, true);
  
    }
    ReadTask516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c92 = _t[0];
        u64 v_c57 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index491, std::array<u64,10>{v_c92, v_c57, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index492, std::array<u64,9>{v_c57, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex493, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex494, mp_mskdelta508, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m567) {
          u64 v_c25 = m567[1]; u64 v_c60 = m567[2];
          if (!slog::exists_probe<9,3>($sup5638x107x0x0x0index495, std::array<u64,9>{v_c60, v_c25, v_c57, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex496, std::array<u64,5>{v_c57, v_c60, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex497, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x107x0x0x1index498, $sup5638x107x0x0x1delta509, std::array<u64,10>{v_c92, v_c60, v_c25, v_c57, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m568) {
            u64 v_c93 = m568[4]; u64 v_c24 = m568[5]; u64 v_c22 = m568[6]; u64 v_c19 = m568[7]; u64 v_c52 = m568[8]; u64 v_c3 = m568[9];
            u64 v_c94 = _prim_lt(db, v_c22, v_c60);
            if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c94) return;
            slog::join_probe_old<9,9>($sup5638x107x0x0x0index499, $sup5638x107x0x0x0delta510, std::array<u64,9>{v_c57, v_c60, v_c52, v_c3, v_c93, v_c24, v_c22, v_c25, v_c19}, [&](const std::array<u64,9>& m570) {
              if (!slog::exists_probe<5,4>(mbranchindex500, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex501, std::array<u64,3>{v_c3, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex502, mbranchdelta511, std::array<u64,5>{v_c57, v_c60, v_c52, v_c3, 0}, [&](const std::array<u64,5>& m571) {
                u64 v_c95 = m571[4];
                if (!slog::exists_probe<3,2>(mp_unionindex503, std::array<u64,3>{v_c95, v_c93, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex504, mbranchdelta512, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m572) {
                  u64 v_c96 = m572[4];
                  slog::join_probe_old<3,3>(mp_unionindex505, mp_uniondelta513, std::array<u64,3>{v_c93, v_c96, v_c95}, [&](const std::array<u64,3>& m573) {
                    slog::join_probe_old<3,2>(mp_unionindex506, mp_uniondelta514, std::array<u64,3>{v_c96, v_c3, 0}, [&](const std::array<u64,3>& m574) {
                      u64 v_c97 = m574[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex507, mp_union_ansdelta515, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m575) {
                        u64 v_c16 = m575[1];
                        u64 v_c98 = _prim_band(db, v_c25, v_c60);
                        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c99 = _prim_gt(db, v_c98, v_c91);
                        if (v_c99 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c99) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c93, v_c16, v_c60, v_c57, v_c52});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c60, v_c52, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre) (scan temp6y6l1036 __t38nk104 __v0 n q v) (body (join mbranch (1 2 3 4 0) 4 q n __v0 v __t3cki101)) (head (emit mp_union_ans (0 1) __t38nk104 __t3cki101)) map.slog:105 #f)
  class ReadTask578 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex577;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("mp_union_ans");
      head_index[0] = readrel580->getIndex(ord579, false);
      outer_rel = db->getRelation("temp6y6l1036");
      std::vector<u16> ord581({1, 2, 3, 4, 0});
      slog::Relation* readrel582 = db->getRelation("mbranch");
      mbranchindex577 = readrel582->getIndex(ord581, false);
  
    }
    ReadTask578(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c100 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c60 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c3 = _t[4];
        slog::join_probe<5,4>(mbranchindex577, std::array<u64,5>{v_c57, v_c60, v_c16, v_c3, 0}, [&](const std::array<u64,5>& m583) {
          u64 v_c101 = m583[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c100, v_c101}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:temp6y6l1036", _fires);
  
      if (!_done)
      {
        ReadTask578* _cont = new ReadTask578(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask578(db,b), false);
  // (crule (pre (let __trid5C98695 constd9f3167b950244706dc6dbb2) (let __trel7K3r696 const7f254967624b26d820569bd6) (let __tcol5rwk697 const6b86b273ff34fce19d6b804e) (let __trel3FQQ698 const72bac24066bb34077c1f6e71) (let __tcol6YnW699 const5feceb66ffc86f38d952786c) (let __trel1MV4700 const72bac24066bb34077c1f6e71) (let __tcol6dFo701 const6b86b273ff34fce19d6b804e) (let __trel8sSW702 const72bac24066bb34077c1f6e71) (let __tcol4zI6703 constd4735e3a265e16eee03f5971) (let __trel9plu704 const72bac24066bb34077c1f6e71) (let __tcol68Mo705 const4e07408562bedb8b60ce05c1)) (scan $sup5638x107x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5C98695 __trel7K3r696 __tcol5rwk697 (1 2 3 4 0)) (tycheck p (accept int) __trid5C98695 __trel3FQQ698 __tcol6YnW699 (1 2 3 4 0)) (tycheck m (accept int) __trid5C98695 __trel1MV4700 __tcol6dFo701 (1 2 3 4 0)) (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5C98695 __trel8sSW702 __tcol4zI6703 (1 2 3 4 0)) (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5C98695 __trel9plu704 __tcol68Mo705 (1 2 3 4 0)) (emit-temp temp7FV11078 l m p r v) (mkstruct mbranch (1 2 3 4 0) __t6sdQ66 p m l r)) map.slog:108 #f)
  class ReadTask587 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid585;  u32 sid584;  u32 sid586;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp7FV11078");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x1");
      sid585 = db->getRelation("_enum")->getStructId();
      sid584 = db->getRelation("mbranch")->getStructId();
      sid586 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask587(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_constd9f3167b950244706dc6dbb2;
      u64 v_c103 = v_const7f254967624b26d820569bd6;
      u64 v_c104 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c105 = v_const72bac24066bb34077c1f6e71;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const72bac24066bb34077c1f6e71;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const72bac24066bb34077c1f6e71;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_const72bac24066bb34077c1f6e71;
      u64 v_c112 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c89 = _t[0];
        u64 v_c113 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c60 = _t[4];
        u64 v_c25 = _t[5];
        u64 v_c57 = _t[6];
        u64 v_c19 = _t[7];
        u64 v_c52 = _t[8];
        u64 v_c3 = _t[9];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid584 || decode_struct_id(v_c3) == sid585 || decode_struct_id(v_c3) == sid586))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c102, v_c103, v_c104, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c102, v_c105, v_c106, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c102, v_c107, v_c108, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid584 || decode_struct_id(v_c24) == sid585 || decode_struct_id(v_c24) == sid586))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c102, v_c109, v_c110, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c19) && (decode_struct_id(v_c19) == sid584 || decode_struct_id(v_c19) == sid585 || decode_struct_id(v_c19) == sid586))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c102, v_c111, v_c112, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c24, v_c22, v_c25, v_c19, v_c3});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c25, v_c22, v_c24, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst0HVn828 constd01925b37634a1a9d24159d8) (let __tconst9FbD307 const8c1f1046219ddd216a023f79) (let __tconst465U308 const6b86b273ff34fce19d6b804e)) (scan canon m) (body (exists _enum (1 0) 1 __tconst0HVn828) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst465U308 __tconst9FbD307 __t0rdB310 __t3qgX309) (join _enum (0 1) 2 __t3qgX309 __tconst0HVn828) (join-old mp_put_ans (0 1) 1 (0 1) __t0rdB310 s)) (head (mkstruct mp_union (1 2 0) __4LkF829 s m)) mp_basic.slog:23 #f)
  class ReadTask594 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex588;  slog::Index** mp_putindex589;  slog::Index** _enumindex590;  slog::Index** mp_put_ansindex591;  slog::Index** mp_putdelta592;  slog::Index** mp_put_ansdelta593;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("canon");
      std::vector<u16> ord595({1, 0});
      slog::Relation* readrel596 = db->getRelation("_enum");
      _enumindex588 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({2, 3, 0, 1});
      slog::Relation* readrel598 = db->getRelation("mp_put");
      mp_putindex589 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({2, 3, 0, 1});
      slog::Relation* readrel600 = db->getRelation("mp_put");
      mp_putdelta592 = readrel600->getIndex(ord599, true);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("_enum");
      _enumindex590 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("mp_put_ans");
      mp_put_ansindex591 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1});
      slog::Relation* readrel606 = db->getRelation("mp_put_ans");
      mp_put_ansdelta593 = readrel606->getIndex(ord605, true);
  
    }
    ReadTask594(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_constd01925b37634a1a9d24159d8;
      u64 v_c115 = v_const8c1f1046219ddd216a023f79;
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        if (!slog::exists_probe<2,1>(_enumindex588, std::array<u64,2>{v_c114, 0})) return;
        slog::join_probe_old<4,2>(mp_putindex589, mp_putdelta592, std::array<u64,4>{v_c116, v_c115, 0, 0}, [&](const std::array<u64,4>& m607) {
          u64 v_c117 = m607[2]; u64 v_c118 = m607[3];
          slog::join_probe<2,2>(_enumindex590, std::array<u64,2>{v_c118, v_c114}, [&](const std::array<u64,2>& m608) {
            slog::join_probe_old<2,1>(mp_put_ansindex591, mp_put_ansdelta593, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m609) {
              u64 v_c72 = m609[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c72, v_c22}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:23", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask594* _cont = new ReadTask594(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask594(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan $sup5638x42x0x0x0 __t0ekw284 k l m p r v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t0ekw284 k v __t8lnB287) (exists mp_msk (1 2 0) 3 k m __t8lnB287) (exists mp_msk_ans (0 1) 2 __t8lnB287 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t07OG283) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t07OG283 k __t0ekw284 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t8lnB287) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join mp_msk_ans (0 1) 2 __t8lnB287 p) (join mp_put_ans (0 1) 1 __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask629 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex610;  slog::Index** mp_putindex611;  slog::Index** mp_mskindex612;  slog::Index** mp_putindex613;  slog::Index** mp_msk_ansindex614;  slog::Index** $sup5638x42x0x0x1index615;  slog::Index** mp_mskindex616;  slog::Index** mp_msk_ansindex617;  slog::Index** mbranchindex618;  slog::Index** mp_putindex619;  slog::Index** mp_mskindex620;  slog::Index** mp_putindex621;  slog::Index** mp_msk_ansindex622;  slog::Index** mp_put_ansindex623;  slog::Index** $sup5638x42x0x0x1delta624;  slog::Index** mbranchdelta625;  slog::Index** mp_putdelta626;  slog::Index** mp_mskdelta627;  slog::Index** mp_putdelta628;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord630({1, 2, 3, 4, 0});
      slog::Relation* readrel631 = db->getRelation("mbranch");
      mbranchindex610 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({2, 3, 0, 1});
      slog::Relation* readrel633 = db->getRelation("mp_put");
      mp_putindex611 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 0});
      slog::Relation* readrel635 = db->getRelation("mp_msk");
      mp_mskindex612 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 2, 3, 0});
      slog::Relation* readrel637 = db->getRelation("mp_put");
      mp_putindex613 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0});
      slog::Relation* readrel639 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex614 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel641 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index615 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel643 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta624 = readrel643->getIndex(ord642, true);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("mp_msk");
      mp_mskindex616 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex617 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 3, 4, 0});
      slog::Relation* readrel649 = db->getRelation("mbranch");
      mbranchindex618 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 2, 3, 4, 0});
      slog::Relation* readrel651 = db->getRelation("mbranch");
      mbranchdelta625 = readrel651->getIndex(ord650, true);
      std::vector<u16> ord652({1, 2, 0, 3});
      slog::Relation* readrel653 = db->getRelation("mp_put");
      mp_putindex619 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0, 3});
      slog::Relation* readrel655 = db->getRelation("mp_put");
      mp_putdelta626 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("mp_msk");
      mp_mskindex620 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("mp_msk");
      mp_mskdelta627 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({1, 2, 3, 0});
      slog::Relation* readrel661 = db->getRelation("mp_put");
      mp_putindex621 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 3, 0});
      slog::Relation* readrel663 = db->getRelation("mp_put");
      mp_putdelta628 = readrel663->getIndex(ord662, true);
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex622 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("mp_put_ans");
      mp_put_ansindex623 = readrel667->getIndex(ord666, false);
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c19 = _t[5];
        u64 v_c3 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex610, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex611, std::array<u64,4>{v_c4, v_c3, v_c120, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex612, std::array<u64,3>{v_c4, v_c22, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex613, std::array<u64,4>{v_c19, v_c4, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex614, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe_old<8,7>($sup5638x42x0x0x1index615, $sup5638x42x0x0x1delta624, std::array<u64,8>{v_c24, v_c22, v_c25, v_c19, v_c120, v_c4, v_c3, 0}, [&](const std::array<u64,8>& m668) {
          u64 v_c121 = m668[7];
          if (!slog::exists_probe<3,3>(mp_mskindex616, std::array<u64,3>{v_c4, v_c22, v_c121})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex617, std::array<u64,2>{v_c121, v_c25})) return;
          slog::join_probe_old<5,4>(mbranchindex618, mbranchdelta625, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m669) {
            u64 v_c122 = m669[4];
            slog::join_probe_old<4,4>(mp_putindex619, mp_putdelta626, std::array<u64,4>{v_c122, v_c4, v_c120, v_c3}, [&](const std::array<u64,4>& m670) {
              slog::join_probe_old<3,3>(mp_mskindex620, mp_mskdelta627, std::array<u64,3>{v_c4, v_c22, v_c121}, [&](const std::array<u64,3>& m671) {
                slog::join_probe_old<4,3>(mp_putindex621, mp_putdelta628, std::array<u64,4>{v_c19, v_c4, v_c3, 0}, [&](const std::array<u64,4>& m672) {
                  u64 v_c123 = m672[3];
                  slog::join_probe<2,2>(mp_msk_ansindex622, std::array<u64,2>{v_c121, v_c25}, [&](const std::array<u64,2>& m673) {
                    slog::join_probe<2,1>(mp_put_ansindex623, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m674) {
                      u64 v_c16 = m674[1];
                      u64 v_c124 = _prim_band(db, v_c4, v_c22);
                      if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c125 = _prim_gt(db, v_c124, v_c119);
                      if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c125) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c120, v_c16, v_c24, v_c22, v_c25});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c22, v_c24, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask629* _cont = new ReadTask629(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask629(db,b), false);
  // (crule (pre) (scan mp_join __t0GCP91 p0 t0 p1 t1) (body) (head (emit $sup5638x29x0x0x0 (1 0 2 3 4) p0 __t0GCP91 p1 t0 t1)) map.slog:30 #f)
  class ReadTask676 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord677({1, 0, 2, 3, 4});
      slog::Relation* readrel678 = db->getRelation("$sup5638x29x0x0x0");
      head_index[0] = readrel678->getIndex(ord677, false);
      outer_rel = db->getRelation("mp_join");
  
    }
    ReadTask676(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c46 = _t[3];
        u64 v_c38 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c45, v_c126, v_c46, v_c37, v_c38}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask676* _cont = new ReadTask676(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask676(db,b), false);
  // (crule (pre) (scan mp_put __t5vsG428 __t51uB429 k v) (body (exists mp_join (1 4 2 0 3) 2 k __t51uB429) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 1 k) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 4 k v __t5vsG428 __t51uB429 p l m r) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t51uB429) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t51uB429 k __t9vyw431 __t9k3L430) (join-old mleaf (0 1 2) 3 (0 1 2) __t9k3L430 k v) (exists mp_join_ans (0 1) 1 __t9vyw431) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6MG8432) (join mp_msk_ans (0 1) 1 __t6MG8432 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t9vyw431 res)) (head (emit mp_put_ans (0 1) __t5vsG428 res)) map.slog:45 #f)
  class ReadTask695 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex679;  slog::Index** mleafindex680;  slog::Index** mp_mskindex681;  slog::Index** $sup5638x44x0x0x0index682;  slog::Index** mbranchindex683;  slog::Index** mp_mskindex684;  slog::Index** mp_joinindex685;  slog::Index** mleafindex686;  slog::Index** mp_join_ansindex687;  slog::Index** mp_mskindex688;  slog::Index** mp_msk_ansindex689;  slog::Index** mp_join_ansindex690;  slog::Index** mbranchdelta691;  slog::Index** mp_joindelta692;  slog::Index** mleafdelta693;  slog::Index** mp_mskdelta694;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("mp_put_ans");
      head_index[0] = readrel697->getIndex(ord696, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord698({1, 4, 2, 0, 3});
      slog::Relation* readrel699 = db->getRelation("mp_join");
      mp_joinindex679 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("mleaf");
      mleafindex680 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("mp_msk");
      mp_mskindex681 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel705 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index682 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 3, 4, 0});
      slog::Relation* readrel707 = db->getRelation("mbranch");
      mbranchindex683 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 2, 3, 4, 0});
      slog::Relation* readrel709 = db->getRelation("mbranch");
      mbranchdelta691 = readrel709->getIndex(ord708, true);
      std::vector<u16> ord710({1, 2, 0});
      slog::Relation* readrel711 = db->getRelation("mp_msk");
      mp_mskindex684 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({3, 4, 1, 0, 2});
      slog::Relation* readrel713 = db->getRelation("mp_join");
      mp_joinindex685 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({3, 4, 1, 0, 2});
      slog::Relation* readrel715 = db->getRelation("mp_join");
      mp_joindelta692 = readrel715->getIndex(ord714, true);
      std::vector<u16> ord716({0, 1, 2});
      slog::Relation* readrel717 = db->getRelation("mleaf");
      mleafindex686 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({0, 1, 2});
      slog::Relation* readrel719 = db->getRelation("mleaf");
      mleafdelta693 = readrel719->getIndex(ord718, true);
      std::vector<u16> ord720({0, 1});
      slog::Relation* readrel721 = db->getRelation("mp_join_ans");
      mp_join_ansindex687 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("mp_msk");
      mp_mskindex688 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 0});
      slog::Relation* readrel725 = db->getRelation("mp_msk");
      mp_mskdelta694 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex689 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("mp_join_ans");
      mp_join_ansindex690 = readrel729->getIndex(ord728, false);
  
    }
    ReadTask695(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c127 = _t[0];
        u64 v_c128 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<5,2>(mp_joinindex679, std::array<u64,5>{v_c4, v_c128, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mleafindex680, std::array<u64,3>{v_c4, v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex681, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<8,4>($sup5638x44x0x0x0index682, std::array<u64,8>{v_c4, v_c3, v_c127, v_c128, 0, 0, 0, 0}, [&](const std::array<u64,8>& m730) {
          u64 v_c25 = m730[4]; u64 v_c24 = m730[5]; u64 v_c22 = m730[6]; u64 v_c19 = m730[7];
          slog::join_probe_old<5,5>(mbranchindex683, mbranchdelta691, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c128}, [&](const std::array<u64,5>& m731) {
            if (!slog::exists_probe<3,2>(mp_mskindex684, std::array<u64,3>{v_c4, v_c22, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex685, mp_joindelta692, std::array<u64,5>{v_c25, v_c128, v_c4, 0, 0}, [&](const std::array<u64,5>& m732) {
              u64 v_c129 = m732[3]; u64 v_c130 = m732[4];
              slog::join_probe_old<3,3>(mleafindex686, mleafdelta693, std::array<u64,3>{v_c130, v_c4, v_c3}, [&](const std::array<u64,3>& m733) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex687, std::array<u64,2>{v_c129, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex688, mp_mskdelta694, std::array<u64,3>{v_c4, v_c22, 0}, [&](const std::array<u64,3>& m734) {
                  u64 v_c131 = m734[2];
                  slog::join_probe<2,1>(mp_msk_ansindex689, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m735) {
                    u64 v_c16 = m735[1];
                    if (v_c25 == v_c16) return;
                    slog::join_probe<2,1>(mp_join_ansindex690, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m736) {
                      u64 v_c63 = m736[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c127, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask695* _cont = new ReadTask695(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask695(db,b), false);
  // (crule (pre) (scan mp_put_soft __t9zZ9298 t k v) (body) (head (emit $sup5638x68x0x0x0 (1 2 3 0) k t v __t9zZ9298)) map.slog:69 #f)
  class ReadTask737 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord738({1, 2, 3, 0});
      slog::Relation* readrel739 = db->getRelation("$sup5638x68x0x0x0");
      head_index[0] = readrel739->getIndex(ord738, false);
      outer_rel = db->getRelation("mp_put_soft");
  
    }
    ReadTask737(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c132 = _t[0];
        u64 v_c133 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        ++_fires;
        slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c4, v_c133, v_c3, v_c132}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask737* _cont = new ReadTask737(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask737(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre1ocd1014 __errf5xaP1015 __errf3Wze1016) (body) (head (emit error (0) __erre1ocd1014)) <internal>:1 #f)
  class ReadTask740 : public slog::Task
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
      std::vector<u16> ord741({0});
      slog::Relation* readrel742 = db->getRelation("error");
      head_index[0] = readrel742->getIndex(ord741, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c134 = _t[0];
        u64 v_c135 = _t[1];
        u64 v_c136 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c134}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __trid8mHn811 const9cfb09b7c00913be7566a50e) (let __trel8eDb812 const7f254967624b26d820569bd6) (let __tcol4ZEt813 const5feceb66ffc86f38d952786c) (let __trel2Esi814 const7f254967624b26d820569bd6) (let __tcol469N815 const6b86b273ff34fce19d6b804e)) (scan $sup5638x93x0x0x0 __d0 l m p r u v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8mHn811 __trel8eDb812 __tcol4ZEt813 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8mHn811 __trel2Esi814 __tcol469N815 (1 2 3 4 0)) (mkstruct mp_union (1 2 0) __6sPq810 r v)) map.slog:94 #f)
  class ReadTask746 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid744;  u32 sid743;  u32 sid745;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_union");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      sid744 = db->getRelation("_enum")->getStructId();
      sid743 = db->getRelation("mbranch")->getStructId();
      sid745 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask746(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_const9cfb09b7c00913be7566a50e;
      u64 v_c138 = v_const7f254967624b26d820569bd6;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const7f254967624b26d820569bd6;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c89 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c19 = _t[4];
        u64 v_c52 = _t[5];
        u64 v_c3 = _t[6];
        ++_fires;
        if (!((is_struct(v_c19) && (decode_struct_id(v_c19) == sid743 || decode_struct_id(v_c19) == sid744 || decode_struct_id(v_c19) == sid745))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c137, v_c138, v_c139, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid743 || decode_struct_id(v_c3) == sid744 || decode_struct_id(v_c3) == sid745))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c137, v_c140, v_c141, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c19, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
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
  // (crule (pre (let __trid3DG6798 constd9f3167b950244706dc6dbb2) (let __trel1z52799 constdd7bbf31ce5f578b9805e840) (let __tcol28ai800 const5feceb66ffc86f38d952786c) (let __trel6HIB801 constdd7bbf31ce5f578b9805e840) (let __tcol7i6i802 const6b86b273ff34fce19d6b804e)) (scan $sup5638x107x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid3DG6798 __trel1z52799 __tcol28ai800 (1 2 3 4 0)) (tycheck n (accept int) __trid3DG6798 __trel6HIB801 __tcol7i6i802 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4ARQ797 p n)) map.slog:108 #f)
  class ReadTask747 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
  
    }
    ReadTask747(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_constd9f3167b950244706dc6dbb2;
      u64 v_c143 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c146 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c89 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c52 = _t[7];
        u64 v_c3 = _t[8];
        ++_fires;
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c142, v_c143, v_c144, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c60)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c142, v_c145, v_c146, v_c60}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c25, v_c60}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask747* _cont = new ReadTask747(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask747(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mp_union __t05l7352 __t6yxH356 __t3rQ8350) (body (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 1 __t05l7352) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 1 __t05l7352) (join-old mp_union (1 2 0) 1 (1 2 0) __t6yxH356 v __t9WRQ357) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t05l7352 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t05l7352 v) (exists mp_union_ans (0 1) 1 __t9WRQ357) (join mbranch (4 0 1 2 3) 2 v __t3rQ8350 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t05l7352) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t05l7352 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6yxH356) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t05l7352 l m p r __t4mLe355) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask769 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index748;  slog::Index** $sup5638x107x0x0x1index749;  slog::Index** mp_unionindex750;  slog::Index** $sup5638x107x0x0x0index751;  slog::Index** $sup5638x107x0x0x1index752;  slog::Index** mp_union_ansindex753;  slog::Index** mbranchindex754;  slog::Index** $sup5638x107x0x0x1index755;  slog::Index** mp_mskindex756;  slog::Index** mp_msk_ansindex757;  slog::Index** $sup5638x107x0x0x0index758;  slog::Index** mbranchindex759;  slog::Index** mp_mskindex760;  slog::Index** $sup5638x107x0x0x1index761;  slog::Index** mbranchindex762;  slog::Index** mp_mskindex763;  slog::Index** mp_msk_ansindex764;  slog::Index** mp_union_ansindex765;  slog::Index** mp_uniondelta766;  slog::Index** mbranchdelta767;  slog::Index** mp_mskdelta768;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord770({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel771 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index748 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel773 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index749 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 2, 0});
      slog::Relation* readrel775 = db->getRelation("mp_union");
      mp_unionindex750 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("mp_union");
      mp_uniondelta766 = readrel777->getIndex(ord776, true);
      std::vector<u16> ord778({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel779 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index751 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel781 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index752 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({0, 1});
      slog::Relation* readrel783 = db->getRelation("mp_union_ans");
      mp_union_ansindex753 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({4, 0, 1, 2, 3});
      slog::Relation* readrel785 = db->getRelation("mbranch");
      mbranchindex754 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel787 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index755 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({2, 0, 1});
      slog::Relation* readrel789 = db->getRelation("mp_msk");
      mp_mskindex756 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 0});
      slog::Relation* readrel791 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex757 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel793 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index758 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 3, 4, 0});
      slog::Relation* readrel795 = db->getRelation("mbranch");
      mbranchindex759 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("mp_msk");
      mp_mskindex760 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel799 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index761 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 3, 4, 0});
      slog::Relation* readrel801 = db->getRelation("mbranch");
      mbranchindex762 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 3, 4, 0});
      slog::Relation* readrel803 = db->getRelation("mbranch");
      mbranchdelta767 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("mp_msk");
      mp_mskindex763 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("mp_msk");
      mp_mskdelta768 = readrel807->getIndex(ord806, true);
      std::vector<u16> ord808({0, 1});
      slog::Relation* readrel809 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex764 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({0, 1});
      slog::Relation* readrel811 = db->getRelation("mp_union_ans");
      mp_union_ansindex765 = readrel811->getIndex(ord810, false);
  
    }
    ReadTask769(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c93 = _t[0];
        u64 v_c96 = _t[1];
        u64 v_c95 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index748, std::array<u64,9>{v_c93, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index749, std::array<u64,10>{v_c93, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex750, mp_uniondelta766, std::array<u64,3>{v_c96, 0, 0}, [&](const std::array<u64,3>& m812) {
          u64 v_c3 = m812[1]; u64 v_c97 = m812[2];
          if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index751, std::array<u64,9>{v_c93, v_c3, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index752, std::array<u64,10>{v_c93, v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex753, std::array<u64,2>{v_c97, 0})) return;
          slog::join_probe<5,2>(mbranchindex754, std::array<u64,5>{v_c3, v_c95, 0, 0, 0}, [&](const std::array<u64,5>& m813) {
            u64 v_c57 = m813[2]; u64 v_c60 = m813[3]; u64 v_c52 = m813[4];
            if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index755, std::array<u64,10>{v_c3, v_c60, v_c57, v_c52, v_c93, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex756, std::array<u64,3>{v_c60, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex757, std::array<u64,2>{v_c57, 0})) return;
            slog::join_probe<9,5>($sup5638x107x0x0x0index758, std::array<u64,9>{v_c57, v_c60, v_c52, v_c3, v_c93, 0, 0, 0, 0}, [&](const std::array<u64,9>& m814) {
              u64 v_c24 = m814[5]; u64 v_c22 = m814[6]; u64 v_c25 = m814[7]; u64 v_c19 = m814[8];
              u64 v_c147 = _prim_lt(db, v_c22, v_c60);
              if (v_c147 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
              if (!v_c147) return;
              if (!slog::exists_probe<5,5>(mbranchindex759, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c96})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex760, std::array<u64,3>{v_c25, v_c60, 0})) return;
              slog::join_probe<10,9>($sup5638x107x0x0x1index761, std::array<u64,10>{v_c3, v_c60, v_c57, v_c52, v_c93, v_c24, v_c22, v_c25, v_c19, 0}, [&](const std::array<u64,10>& m816) {
                u64 v_c92 = m816[9];
                slog::join_probe_old<5,5>(mbranchindex762, mbranchdelta767, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c96}, [&](const std::array<u64,5>& m817) {
                  slog::join_probe_old<3,3>(mp_mskindex763, mp_mskdelta768, std::array<u64,3>{v_c25, v_c60, v_c92}, [&](const std::array<u64,3>& m818) {
                    slog::join_probe<2,2>(mp_msk_ansindex764, std::array<u64,2>{v_c92, v_c57}, [&](const std::array<u64,2>& m819) {
                      slog::join_probe<2,1>(mp_union_ansindex765, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m820) {
                        u64 v_c16 = m820[1];
                        u64 v_c98 = _prim_band(db, v_c25, v_c60);
                        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c148 = _prim_gt(db, v_c98, v_c91);
                        if (v_c148 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c148) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c93, v_c16, v_c60, v_c57, v_c52});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c60, v_c52, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask769* _cont = new ReadTask769(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask769(db,b), false);
  // (crule (pre) (scan temp2Hkq1086 __t4Iug198 __t4c2e199) (body) (head (emit mp_hsb_ans (0 1) __t4c2e199 __t4Iug198)) map.slog:19 #f)
  class ReadTask822 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord823({0, 1});
      slog::Relation* readrel824 = db->getRelation("mp_hsb_ans");
      head_index[0] = readrel824->getIndex(ord823, false);
      outer_rel = db->getRelation("temp2Hkq1086");
  
    }
    ReadTask822(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c149 = _t[0];
        u64 v_c150 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c149}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:temp2Hkq1086", _fires);
  
      if (!_done)
      {
        ReadTask822* _cont = new ReadTask822(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask822(db,b), false);
  // (crule (pre (let __tconst3nEl614 constd01925b37634a1a9d24159d8) (let __tconst5JbS3 constff5a1ae012afa5d4c889c50a) (let __tconst00xS4 const7902699be42c8a8e46fbbb45) (let __tconst6RTh7 const624b60c58c9d8bfb6ff1886c) (let __tconst80wL8 const4e07408562bedb8b60ce05c1) (let __tconst69fL1 const4a44dc15364204a80fe80e90) (let __tconst9RBO2 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst00xS4 __tconst5JbS3 __t5DYC6 __t5kVD5) (body (join _enum (0 1) 2 __t5kVD5 __tconst3nEl614) (exists mp_put_ans (0 1) 1 __t5DYC6) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst80wL8 __tconst6RTh7 __t9KAP9 __v0) (join mp_put_ans (0 1) 2 __t5DYC6 __v0) (join mp_put_ans (0 1) 1 __t9KAP9 __v1)) (head (mkstruct mp_put (1 2 3 0) __2h5j615 __v1 __tconst9RBO2 __tconst69fL1)) mp_basic.slog:14 #f)
  class ReadTask831 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex825;  slog::Index** mp_put_ansindex826;  slog::Index** mp_putindex827;  slog::Index** mp_put_ansindex828;  slog::Index** mp_put_ansindex829;  slog::Index** mp_putdelta830;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      std::vector<u16> ord832({2, 3, 0, 1});
      slog::Relation* readrel833 = db->getRelation("mp_put");
      driver_index = readrel833->getIndex(ord832, true);
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("_enum");
      _enumindex825 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("mp_put_ans");
      mp_put_ansindex826 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({2, 3, 0, 1});
      slog::Relation* readrel839 = db->getRelation("mp_put");
      mp_putindex827 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({2, 3, 0, 1});
      slog::Relation* readrel841 = db->getRelation("mp_put");
      mp_putdelta830 = readrel841->getIndex(ord840, true);
      std::vector<u16> ord842({0, 1});
      slog::Relation* readrel843 = db->getRelation("mp_put_ans");
      mp_put_ansindex828 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1});
      slog::Relation* readrel845 = db->getRelation("mp_put_ans");
      mp_put_ansindex829 = readrel845->getIndex(ord844, false);
  
    }
    ReadTask831(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c151 = v_constd01925b37634a1a9d24159d8;
      u64 v_c152 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c153 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c154 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c155 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c156 = v_const4a44dc15364204a80fe80e90;
      u64 v_c157 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c153, v_c152, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m846) {
        u64 v_c158 = m846[2];
        u64 v_c159 = m846[3];
        if (buckethash(v_c158) != bucket) return;
        slog::join_probe<2,2>(_enumindex825, std::array<u64,2>{v_c159, v_c151}, [&](const std::array<u64,2>& m847) {
          if (!slog::exists_probe<2,1>(mp_put_ansindex826, std::array<u64,2>{v_c158, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex827, mp_putdelta830, std::array<u64,4>{v_c155, v_c154, 0, 0}, [&](const std::array<u64,4>& m848) {
            u64 v_c160 = m848[2]; u64 v_c16 = m848[3];
            slog::join_probe<2,2>(mp_put_ansindex828, std::array<u64,2>{v_c158, v_c16}, [&](const std::array<u64,2>& m849) {
              slog::join_probe<2,1>(mp_put_ansindex829, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m850) {
                u64 v_c18 = m850[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c18, v_c157, v_c156}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask831* _cont = new ReadTask831(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask831(db,b), false);
  // (crule (pre) (scan mbranch __t0BoC218 q n u v) (body (exists mp_join (3 4 1 0 2) 2 q __t0BoC218) (exists mp_union (2 0 1) 1 __t0BoC218) (exists mp_msk (2 0 1) 1 n) (join $sup5638x110x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t0BoC218 u v __t5xrH216 l m p r __t0o62217) (cmp lt m n) (join mbranch (1 2 3 4 0) 5 p m l r __t0o62217) (exists mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t0o62217 q __t0BoC218 __t7HEI219) (join mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (exists mp_join_ans (0 1) 1 __t7HEI219) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask866 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex851;  slog::Index** mp_unionindex852;  slog::Index** mp_mskindex853;  slog::Index** $sup5638x110x0x0x0index854;  slog::Index** mbranchindex855;  slog::Index** mp_unionindex856;  slog::Index** mp_mskindex857;  slog::Index** mp_joinindex858;  slog::Index** mp_unionindex859;  slog::Index** mp_join_ansindex860;  slog::Index** mp_mskindex861;  slog::Index** mp_msk_ansindex862;  slog::Index** mp_join_ansindex863;  slog::Index** mp_joindelta864;  slog::Index** mp_mskdelta865;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord867({0, 1});
      slog::Relation* readrel868 = db->getRelation("mp_union_ans");
      head_index[0] = readrel868->getIndex(ord867, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord869({3, 4, 1, 0, 2});
      slog::Relation* readrel870 = db->getRelation("mp_join");
      mp_joinindex851 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({2, 0, 1});
      slog::Relation* readrel872 = db->getRelation("mp_union");
      mp_unionindex852 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({2, 0, 1});
      slog::Relation* readrel874 = db->getRelation("mp_msk");
      mp_mskindex853 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel876 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index854 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 3, 4, 0});
      slog::Relation* readrel878 = db->getRelation("mbranch");
      mbranchindex855 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 1, 2});
      slog::Relation* readrel880 = db->getRelation("mp_union");
      mp_unionindex856 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 0});
      slog::Relation* readrel882 = db->getRelation("mp_msk");
      mp_mskindex857 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 3, 4, 0});
      slog::Relation* readrel884 = db->getRelation("mp_join");
      mp_joinindex858 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 3, 4, 0});
      slog::Relation* readrel886 = db->getRelation("mp_join");
      mp_joindelta864 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({0, 1, 2});
      slog::Relation* readrel888 = db->getRelation("mp_union");
      mp_unionindex859 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({0, 1});
      slog::Relation* readrel890 = db->getRelation("mp_join_ans");
      mp_join_ansindex860 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("mp_msk");
      mp_mskindex861 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 2, 0});
      slog::Relation* readrel894 = db->getRelation("mp_msk");
      mp_mskdelta865 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex862 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1});
      slog::Relation* readrel898 = db->getRelation("mp_join_ans");
      mp_join_ansindex863 = readrel898->getIndex(ord897, false);
  
    }
    ReadTask866(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c60 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c3 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex851, std::array<u64,5>{v_c57, v_c58, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex852, std::array<u64,3>{v_c58, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex853, std::array<u64,3>{v_c60, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x110x0x0x0index854, std::array<u64,11>{v_c60, v_c57, v_c58, v_c52, v_c3, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m899) {
          u64 v_c59 = m899[5]; u64 v_c24 = m899[6]; u64 v_c22 = m899[7]; u64 v_c25 = m899[8]; u64 v_c19 = m899[9]; u64 v_c56 = m899[10];
          u64 v_c161 = _prim_lt(db, v_c22, v_c60);
          if (v_c161 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c161) return;
          slog::join_probe<5,5>(mbranchindex855, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, v_c56}, [&](const std::array<u64,5>& m901) {
            if (!slog::exists_probe<3,3>(mp_unionindex856, std::array<u64,3>{v_c59, v_c56, v_c58})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex857, std::array<u64,3>{v_c25, v_c60, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex858, mp_joindelta864, std::array<u64,5>{v_c25, v_c56, v_c57, v_c58, 0}, [&](const std::array<u64,5>& m902) {
              u64 v_c55 = m902[4];
              slog::join_probe<3,3>(mp_unionindex859, std::array<u64,3>{v_c59, v_c56, v_c58}, [&](const std::array<u64,3>& m903) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex860, std::array<u64,2>{v_c55, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex861, mp_mskdelta865, std::array<u64,3>{v_c25, v_c60, 0}, [&](const std::array<u64,3>& m904) {
                  u64 v_c62 = m904[2];
                  slog::join_probe<2,1>(mp_msk_ansindex862, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m905) {
                    u64 v_c16 = m905[1];
                    if (v_c57 == v_c16) return;
                    slog::join_probe<2,1>(mp_join_ansindex863, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m906) {
                      u64 v_c63 = m906[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask866* _cont = new ReadTask866(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask866(db,b), false);
  // (crule (pre) (scan mbranch __t5w7I193 p m l r) (body (join mp_union (1 2 0) 1 __t5w7I193 __t9UVm194 __t0SXa192) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t9UVm194 q n u v) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t0SXa192 l n p r __t5w7I193 __t9UVm194 u v)) map.slog:102 #f)
  class ReadTask910 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex907;  slog::Index** mbranchindex908;  slog::Index** mbranchdelta909;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord911({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel912 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel912->getIndex(ord911, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord913({1, 2, 0});
      slog::Relation* readrel914 = db->getRelation("mp_union");
      mp_unionindex907 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({0, 1, 2, 3, 4});
      slog::Relation* readrel916 = db->getRelation("mbranch");
      mbranchindex908 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({0, 1, 2, 3, 4});
      slog::Relation* readrel918 = db->getRelation("mbranch");
      mbranchdelta909 = readrel918->getIndex(ord917, true);
  
    }
    ReadTask910(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c162 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe<3,1>(mp_unionindex907, std::array<u64,3>{v_c162, 0, 0}, [&](const std::array<u64,3>& m919) {
          u64 v_c163 = m919[1]; u64 v_c164 = m919[2];
          slog::join_probe_old<5,1>(mbranchindex908, mbranchdelta909, std::array<u64,5>{v_c163, 0, 0, 0, 0}, [&](const std::array<u64,5>& m920) {
            u64 v_c57 = m920[1]; u64 v_c60 = m920[2]; u64 v_c52 = m920[3]; u64 v_c3 = m920[4];
            u64 v_c165 = _prim_lt(db, v_c60, v_c22);
            if (v_c165 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c165) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c22, v_c57, v_c164, v_c24, v_c60, v_c25, v_c19, v_c162, v_c163, v_c52, v_c3}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask910* _cont = new ReadTask910(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask910(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x0 __t0mSQ44 l m n p q r u v) (body (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 l) (join-old $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t0mSQ44 n q u v __t0xN947) (exists mp_msk (1 2 0) 3 q m __t0xN947) (exists mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t39oH43) (exists mp_union (0 1 2) 2 __t0mSQ44 __t39oH43) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t499t48) (join-old mp_union (0 1 2) 3 (0 1 2) __t0mSQ44 __t39oH43 __t499t48) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask944 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex922;  slog::Index** mbranchindex923;  slog::Index** mp_mskindex924;  slog::Index** mp_msk_ansindex925;  slog::Index** mp_unionindex926;  slog::Index** $sup5638x95x0x0x1index927;  slog::Index** mp_mskindex928;  slog::Index** mp_msk_ansindex929;  slog::Index** mbranchindex930;  slog::Index** mp_unionindex931;  slog::Index** mbranchindex932;  slog::Index** mp_unionindex933;  slog::Index** mp_mskindex934;  slog::Index** mp_msk_ansindex935;  slog::Index** mp_unionindex936;  slog::Index** mp_union_ansindex937;  slog::Index** $sup5638x95x0x0x1delta938;  slog::Index** mbranchdelta939;  slog::Index** mbranchdelta940;  slog::Index** mp_uniondelta941;  slog::Index** mp_mskdelta942;  slog::Index** mp_uniondelta943;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord945({1, 2, 3, 4, 0});
      slog::Relation* readrel946 = db->getRelation("mbranch");
      mbranchindex922 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 3, 4, 0});
      slog::Relation* readrel948 = db->getRelation("mbranch");
      mbranchindex923 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 0});
      slog::Relation* readrel950 = db->getRelation("mp_msk");
      mp_mskindex924 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 0});
      slog::Relation* readrel952 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex925 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 2, 0});
      slog::Relation* readrel954 = db->getRelation("mp_union");
      mp_unionindex926 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel956 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index927 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel958 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta938 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("mp_msk");
      mp_mskindex928 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({0, 1});
      slog::Relation* readrel962 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex929 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 2, 3, 4, 0});
      slog::Relation* readrel964 = db->getRelation("mbranch");
      mbranchindex930 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 2, 3, 4, 0});
      slog::Relation* readrel966 = db->getRelation("mbranch");
      mbranchdelta939 = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({0, 1, 2});
      slog::Relation* readrel968 = db->getRelation("mp_union");
      mp_unionindex931 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 2, 3, 4, 0});
      slog::Relation* readrel970 = db->getRelation("mbranch");
      mbranchindex932 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 2, 3, 4, 0});
      slog::Relation* readrel972 = db->getRelation("mbranch");
      mbranchdelta940 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 1, 2});
      slog::Relation* readrel974 = db->getRelation("mp_union");
      mp_unionindex933 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 1, 2});
      slog::Relation* readrel976 = db->getRelation("mp_union");
      mp_uniondelta941 = readrel976->getIndex(ord975, true);
      std::vector<u16> ord977({1, 2, 0});
      slog::Relation* readrel978 = db->getRelation("mp_msk");
      mp_mskindex934 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({1, 2, 0});
      slog::Relation* readrel980 = db->getRelation("mp_msk");
      mp_mskdelta942 = readrel980->getIndex(ord979, true);
      std::vector<u16> ord981({0, 1});
      slog::Relation* readrel982 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex935 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 2, 0});
      slog::Relation* readrel984 = db->getRelation("mp_union");
      mp_unionindex936 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 2, 0});
      slog::Relation* readrel986 = db->getRelation("mp_union");
      mp_uniondelta943 = readrel986->getIndex(ord985, true);
      std::vector<u16> ord987({0, 1});
      slog::Relation* readrel988 = db->getRelation("mp_union_ans");
      mp_union_ansindex937 = readrel988->getIndex(ord987, false);
  
    }
    ReadTask944(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c166 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c167 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c52 = _t[7];
        u64 v_c3 = _t[8];
        u64 v_c168 = _prim_lt(db, v_c60, v_c22);
        if (v_c168 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
        if (!v_c168) return;
        if (!slog::exists_probe<5,4>(mbranchindex922, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex923, std::array<u64,5>{v_c57, v_c60, v_c52, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex924, std::array<u64,3>{v_c57, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex925, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex926, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x95x0x0x1index927, $sup5638x95x0x0x1delta938, std::array<u64,10>{v_c24, v_c22, v_c25, v_c19, v_c167, v_c60, v_c57, v_c52, v_c3, 0}, [&](const std::array<u64,10>& m990) {
          u64 v_c169 = m990[9];
          if (!slog::exists_probe<3,3>(mp_mskindex928, std::array<u64,3>{v_c57, v_c22, v_c169})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex929, std::array<u64,2>{v_c169, v_c25})) return;
          slog::join_probe_old<5,4>(mbranchindex930, mbranchdelta939, std::array<u64,5>{v_c25, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m991) {
            u64 v_c170 = m991[4];
            if (!slog::exists_probe<3,2>(mp_unionindex931, std::array<u64,3>{v_c167, v_c170, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex932, mbranchdelta940, std::array<u64,5>{v_c57, v_c60, v_c52, v_c3, 0}, [&](const std::array<u64,5>& m992) {
              u64 v_c171 = m992[4];
              slog::join_probe_old<3,3>(mp_unionindex933, mp_uniondelta941, std::array<u64,3>{v_c167, v_c170, v_c171}, [&](const std::array<u64,3>& m993) {
                slog::join_probe_old<3,3>(mp_mskindex934, mp_mskdelta942, std::array<u64,3>{v_c57, v_c22, v_c169}, [&](const std::array<u64,3>& m994) {
                  slog::join_probe<2,2>(mp_msk_ansindex935, std::array<u64,2>{v_c169, v_c25}, [&](const std::array<u64,2>& m995) {
                    slog::join_probe_old<3,2>(mp_unionindex936, mp_uniondelta943, std::array<u64,3>{v_c24, v_c171, 0}, [&](const std::array<u64,3>& m996) {
                      u64 v_c172 = m996[2];
                      slog::join_probe<2,1>(mp_union_ansindex937, std::array<u64,2>{v_c172, 0}, [&](const std::array<u64,2>& m997) {
                        u64 v_c16 = m997[1];
                        u64 v_c173 = _prim_band(db, v_c57, v_c22);
                        if (v_c173 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c174 = _prim_lt(db, v_c173, v_c166);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c174) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c167, v_c16, v_c22, v_c25, v_c19});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c22, v_c16, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask944* _cont = new ReadTask944(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask944(db,b), false);
}

