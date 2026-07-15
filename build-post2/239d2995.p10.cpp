
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_consta22c7bfa7abc2d7d387fd7df;
extern u64 v_constc742e02805b99df617265a41;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_c135f00f5c4b371c2(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan mp_msk_ans __t4OmG128 q) (body (exists $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4OmG128 p n) (join $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t4OmG128 l m n p q r v)) map.slog:105 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index0;  slog::Index** mp_mskindex1;  slog::Index** $sup5638x104x0x0x0index2;  slog::Index** mp_mskdelta3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord5({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel6 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord7({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel8 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("mp_msk");
      mp_mskindex1 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1, 2});
      slog::Relation* readrel12 = db->getRelation("mp_msk");
      mp_mskdelta3 = readrel12->getIndex(ord11, true);
      std::vector<u16> ord13({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel14 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index2 = readrel14->getIndex(ord13, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index0, std::array<u64,9>{v_c1, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1, mp_mskdelta3, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m15) {
          u64 v_c2 = m15[1]; u64 v_c3 = m15[2];
          slog::join_probe<9,3>($sup5638x104x0x0x0index2, std::array<u64,9>{v_c3, v_c2, v_c1, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m16) {
            u64 v_c4 = m16[3]; u64 v_c5 = m16[4]; u64 v_c6 = m16[5]; u64 v_c7 = m16[6]; u64 v_c8 = m16[7]; u64 v_c9 = m16[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c4, v_c8, v_c0, v_c5, v_c6, v_c3, v_c2, v_c1, v_c7, v_c9}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre) (scan mleaf __t6sa2325 k v) (body (exists mp_join (1 2 3 4 0) 2 k __t6sa2325) (join mp_put (2 3 0 1) 2 k v __t529R323 __t4DNq324) (join-old mp_join (1 4 2 0 3) 3 (1 4 2 0 3) k __t4DNq324 __t6sa2325 __t1dCZ326 j) (neq j k) (exists mp_join_ans (0 1) 1 __t1dCZ326) (join mleaf (0 1 2) 2 __t4DNq324 j w) (join mp_join_ans (0 1) 1 __t1dCZ326 r)) (head (emit mp_put_ans (0 1) __t529R323 r)) map.slog:39 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex17;  slog::Index** mp_putindex18;  slog::Index** mp_joinindex19;  slog::Index** mp_join_ansindex20;  slog::Index** mleafindex21;  slog::Index** mp_join_ansindex22;  slog::Index** mp_joindelta23;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("mp_put_ans");
      head_index[0] = readrel26->getIndex(ord25, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord27({1, 2, 3, 4, 0});
      slog::Relation* readrel28 = db->getRelation("mp_join");
      mp_joinindex17 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 3, 0, 1});
      slog::Relation* readrel30 = db->getRelation("mp_put");
      mp_putindex18 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 4, 2, 0, 3});
      slog::Relation* readrel32 = db->getRelation("mp_join");
      mp_joinindex19 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 4, 2, 0, 3});
      slog::Relation* readrel34 = db->getRelation("mp_join");
      mp_joindelta23 = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("mp_join_ans");
      mp_join_ansindex20 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1, 2});
      slog::Relation* readrel38 = db->getRelation("mleaf");
      mleafindex21 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("mp_join_ans");
      mp_join_ansindex22 = readrel40->getIndex(ord39, false);
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<5,2>(mp_joinindex17, std::array<u64,5>{v_c11, v_c10, 0, 0, 0})) return;
        slog::join_probe<4,2>(mp_putindex18, std::array<u64,4>{v_c11, v_c9, 0, 0}, [&](const std::array<u64,4>& m41) {
          u64 v_c12 = m41[2]; u64 v_c13 = m41[3];
          slog::join_probe_old<5,3>(mp_joinindex19, mp_joindelta23, std::array<u64,5>{v_c11, v_c13, v_c10, 0, 0}, [&](const std::array<u64,5>& m42) {
            u64 v_c14 = m42[3]; u64 v_c15 = m42[4];
            if (v_c15 == v_c11) return;
            if (!slog::exists_probe<2,1>(mp_join_ansindex20, std::array<u64,2>{v_c14, 0})) return;
            slog::join_probe<3,2>(mleafindex21, std::array<u64,3>{v_c13, v_c15, 0}, [&](const std::array<u64,3>& m43) {
              u64 v_c16 = m43[2];
              slog::join_probe<2,1>(mp_join_ansindex22, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m44) {
                u64 v_c7 = m44[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c7}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mp_msk __t4mLe355 p n) (body (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_msk_ans (0 1) 1 __t4mLe355) (join $sup5638x107x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t4mLe355 n p q __t05l7352 l m r u v) (cmp lt m n) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t05l7352 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk_ans (0 1) 2 __t4mLe355 q) (exists mp_union (2 0 1) 1 v) (join mbranch (1 2 3 4 0) 4 q n u v __t3rQ8350) (exists mp_union (2 0 1) 2 __t3rQ8350 __t05l7352) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6yxH356) (join mp_union (0 1 2) 3 __t05l7352 __t6yxH356 __t3rQ8350) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index45;  slog::Index** mbranchindex46;  slog::Index** mbranchindex47;  slog::Index** mp_msk_ansindex48;  slog::Index** $sup5638x107x0x0x1index49;  slog::Index** $sup5638x107x0x0x0index50;  slog::Index** mbranchindex51;  slog::Index** mp_msk_ansindex52;  slog::Index** mp_unionindex53;  slog::Index** mbranchindex54;  slog::Index** mp_unionindex55;  slog::Index** mbranchindex56;  slog::Index** mp_unionindex57;  slog::Index** mp_msk_ansindex58;  slog::Index** mp_unionindex59;  slog::Index** mp_union_ansindex60;  slog::Index** mbranchdelta61;  slog::Index** mp_uniondelta62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord64({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel65 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index45 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({2, 0, 1, 3, 4});
      slog::Relation* readrel67 = db->getRelation("mbranch");
      mbranchindex46 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 3, 4, 0});
      slog::Relation* readrel69 = db->getRelation("mbranch");
      mbranchindex47 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex48 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel73 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index49 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel75 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index50 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 3, 4, 0});
      slog::Relation* readrel77 = db->getRelation("mbranch");
      mbranchindex51 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex52 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({2, 0, 1});
      slog::Relation* readrel81 = db->getRelation("mp_union");
      mp_unionindex53 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 3, 4, 0});
      slog::Relation* readrel83 = db->getRelation("mbranch");
      mbranchindex54 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({2, 0, 1});
      slog::Relation* readrel85 = db->getRelation("mp_union");
      mp_unionindex55 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 3, 4, 0});
      slog::Relation* readrel87 = db->getRelation("mbranch");
      mbranchindex56 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 3, 4, 0});
      slog::Relation* readrel89 = db->getRelation("mbranch");
      mbranchdelta61 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({0, 1, 2});
      slog::Relation* readrel91 = db->getRelation("mp_union");
      mp_unionindex57 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex58 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 2, 0});
      slog::Relation* readrel95 = db->getRelation("mp_union");
      mp_unionindex59 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("mp_union");
      mp_uniondelta62 = readrel97->getIndex(ord96, true);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("mp_union_ans");
      mp_union_ansindex60 = readrel99->getIndex(ord98, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c18 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index45, std::array<u64,9>{v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex46, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex47, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex48, std::array<u64,2>{v_c18, 0})) return;
        slog::join_probe<10,3>($sup5638x107x0x0x1index49, std::array<u64,10>{v_c18, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m100) {
          u64 v_c1 = m100[3]; u64 v_c19 = m100[4]; u64 v_c5 = m100[5]; u64 v_c6 = m100[6]; u64 v_c7 = m100[7]; u64 v_c8 = m100[8]; u64 v_c9 = m100[9];
          u64 v_c20 = _prim_lt(db, v_c6, v_c3);
          if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c20) return;
          slog::join_probe<9,9>($sup5638x107x0x0x0index50, std::array<u64,9>{v_c1, v_c3, v_c8, v_c9, v_c19, v_c5, v_c6, v_c2, v_c7}, [&](const std::array<u64,9>& m102) {
            if (!slog::exists_probe<5,4>(mbranchindex51, std::array<u64,5>{v_c2, v_c6, v_c5, v_c7, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex52, std::array<u64,2>{v_c18, v_c1})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex53, std::array<u64,3>{v_c9, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex54, std::array<u64,5>{v_c1, v_c3, v_c8, v_c9, 0}, [&](const std::array<u64,5>& m103) {
              u64 v_c21 = m103[4];
              if (!slog::exists_probe<3,2>(mp_unionindex55, std::array<u64,3>{v_c21, v_c19, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex56, mbranchdelta61, std::array<u64,5>{v_c2, v_c6, v_c5, v_c7, 0}, [&](const std::array<u64,5>& m104) {
                u64 v_c22 = m104[4];
                slog::join_probe<3,3>(mp_unionindex57, std::array<u64,3>{v_c19, v_c22, v_c21}, [&](const std::array<u64,3>& m105) {
                  slog::join_probe<2,2>(mp_msk_ansindex58, std::array<u64,2>{v_c18, v_c1}, [&](const std::array<u64,2>& m106) {
                    slog::join_probe_old<3,2>(mp_unionindex59, mp_uniondelta62, std::array<u64,3>{v_c22, v_c9, 0}, [&](const std::array<u64,3>& m107) {
                      u64 v_c23 = m107[2];
                      slog::join_probe<2,1>(mp_union_ansindex60, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m108) {
                        u64 v_c24 = m108[1];
                        u64 v_c25 = _prim_band(db, v_c2, v_c3);
                        if (v_c25 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c26 = _prim_gt(db, v_c25, v_c17);
                        if (v_c26 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c26) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c19, v_c24, v_c3, v_c1, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c3, v_c8, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x0 __d0 p0 p1 t0 t1) (body (let __t2yWY168 (bxor p0 p1))) (head (emit-temp temp8GS31028 __t2yWY168)) map.slog:26 #f)
  class ReadTask110 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8GS31028");
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
  
    }
    ReadTask110(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c31 = _prim_bxor(db, v_c27, v_c28);
        if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c31});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask110* _cont = new ReadTask110(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask110(db,b), false);
  // (crule (pre (let __tconst0CiD318 const4e07408562bedb8b60ce05c1)) (scan canon m) (body) (head (mkstruct mp_del (1 2 0) __2agQ566 m __tconst0CiD318)) mp_basic.slog:21 #f)
  class ReadTask111 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_del");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c32}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:21", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre) (scan mp_put __t3dD4242 t k v) (body (exists mp_union (2 0 1) 1 t) (exists mp_put_ans (0 1) 1 __t3dD4242) (join mleaf (1 2 0) 2 k v __t7TCq240) (join mp_union (1 2 0) 2 __t7TCq240 t __t9sO9241) (join mp_put_ans (0 1) 1 __t3dD4242 r)) (head (emit mp_union_ans (0 1) __t9sO9241 r)) map.slog:92 #f)
  class ReadTask117 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex112;  slog::Index** mp_put_ansindex113;  slog::Index** mleafindex114;  slog::Index** mp_unionindex115;  slog::Index** mp_put_ansindex116;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord118({0, 1});
      slog::Relation* readrel119 = db->getRelation("mp_union_ans");
      head_index[0] = readrel119->getIndex(ord118, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord120({2, 0, 1});
      slog::Relation* readrel121 = db->getRelation("mp_union");
      mp_unionindex112 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("mp_put_ans");
      mp_put_ansindex113 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("mleaf");
      mleafindex114 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("mp_union");
      mp_unionindex115 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("mp_put_ans");
      mp_put_ansindex116 = readrel129->getIndex(ord128, false);
  
    }
    ReadTask117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c9 = _t[3];
        if (!slog::exists_probe<3,1>(mp_unionindex112, std::array<u64,3>{v_c34, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex113, std::array<u64,2>{v_c33, 0})) return;
        slog::join_probe<3,2>(mleafindex114, std::array<u64,3>{v_c11, v_c9, 0}, [&](const std::array<u64,3>& m130) {
          u64 v_c35 = m130[2];
          slog::join_probe<3,2>(mp_unionindex115, std::array<u64,3>{v_c35, v_c34, 0}, [&](const std::array<u64,3>& m131) {
            u64 v_c36 = m131[2];
            slog::join_probe<2,1>(mp_put_ansindex116, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m132) {
              u64 v_c7 = m132[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c7}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask117* _cont = new ReadTask117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask117(db,b), false);
  // (crule (pre (let __tconst4Put678 constd01925b37634a1a9d24159d8)) (scan mp_bld __t6GVZ417 p m __t4gKM416 r) (body (join _enum (0 1) 2 __t4gKM416 __tconst4Put678)) (head (emit mp_bld_ans (0 1) __t6GVZ417 r)) map.slog:73 #f)
  class ReadTask134 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex133;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel136->getIndex(ord135, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("_enum");
      _enumindex133 = readrel138->getIndex(ord137, false);
  
    }
    ReadTask134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c39 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe<2,2>(_enumindex133, std::array<u64,2>{v_c39, v_c37}, [&](const std::array<u64,2>& m139) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c38, v_c7}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:73", "delta:mp_bld", _fires);
  
      if (!_done)
      {
        ReadTask134* _cont = new ReadTask134(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask134(db,b), false);
  // (crule (pre (let __trid6ihd862 consta22c7bfa7abc2d7d387fd7df) (let __trel5VK5863 const1064263932db82f2cf6d4ac2) (let __tcol6umP864 const5feceb66ffc86f38d952786c) (let __trel4UX8865 const1064263932db82f2cf6d4ac2) (let __tcol6e0s866 const6b86b273ff34fce19d6b804e)) (scan $sup5638x42x0x0x1 __d0 __d1 k l m p r v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6ihd862 __trel5VK5863 __tcol6umP864 (1 2 3 4 0)) (tycheck k (accept int) __trid6ihd862 __trel4UX8865 __tcol6e0s866 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __52tI861 r k v)) map.slog:43 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid141;  u32 sid140;  u32 sid142;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup5638x42x0x0x1");
      sid141 = db->getRelation("_enum")->getStructId();
      sid140 = db->getRelation("mbranch")->getStructId();
      sid142 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_consta22c7bfa7abc2d7d387fd7df;
      u64 v_c41 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c42 = v_const5feceb66ffc86f38d952786c;
      u64 v_c43 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c9 = _t[7];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid140 || decode_struct_id(v_c7) == sid141 || decode_struct_id(v_c7) == sid142))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c40, v_c41, v_c42, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c11)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c40, v_c43, v_c44, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c7, v_c11, v_c9}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre) (scan mp_put_soft __t5x4Y384 t k v) (body) (head (emit $sup5638x67x0x0x0 (1 2 0 3) k t __t5x4Y384 v)) map.slog:68 #f)
  class ReadTask144 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord145({1, 2, 0, 3});
      slog::Relation* readrel146 = db->getRelation("$sup5638x67x0x0x0");
      head_index[0] = readrel146->getIndex(ord145, false);
      outer_rel = db->getRelation("mp_put_soft");
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c9 = _t[3];
        ++_fires;
        slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c11, v_c34, v_c46, v_c9}, std::array<u16,4>{1, 2, 0, 3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask144* _cont = new ReadTask144(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask144(db,b), false);
  // (crule (pre) (scan mbranch __t2wpn261 p m l r) (body (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_union (1 2 0) 1 __t2wpn261) (exists mp_union (1 2 0) 1 l) (exists mp_union (1 2 0) 1 r) (join $sup5638x93x0x0x0 (1 2 3 4 0 5 6) 4 l m p r __t9rnk262 u v) (exists mp_union (0 1 2) 2 __t9rnk262 __t2wpn261) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join mbranch (1 2 3 4 0) 4 p m u v __t5rXw260) (join-old mp_union (0 1 2) 3 (0 1 2) __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t2Oaj263) (exists mp_union_ans (0 1) 1 __t2Oaj263) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (exists mp_union_ans (0 1) 1 __t0Kdo264) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex147;  slog::Index** mp_unionindex148;  slog::Index** mp_unionindex149;  slog::Index** mp_unionindex150;  slog::Index** $sup5638x93x0x0x0index151;  slog::Index** mp_unionindex152;  slog::Index** mp_unionindex153;  slog::Index** mp_unionindex154;  slog::Index** mbranchindex155;  slog::Index** mp_unionindex156;  slog::Index** mp_unionindex157;  slog::Index** mp_union_ansindex158;  slog::Index** mp_unionindex159;  slog::Index** mp_union_ansindex160;  slog::Index** mp_union_ansindex161;  slog::Index** mp_union_ansindex162;  slog::Index** mp_uniondelta163;  slog::Index** mp_uniondelta164;  slog::Index** mp_uniondelta165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord167({1, 2, 3, 4, 0});
      slog::Relation* readrel168 = db->getRelation("mbranch");
      mbranchindex147 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("mp_union");
      mp_unionindex148 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("mp_union");
      mp_unionindex149 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("mp_union");
      mp_unionindex150 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 3, 4, 0, 5, 6});
      slog::Relation* readrel176 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index151 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1, 2});
      slog::Relation* readrel178 = db->getRelation("mp_union");
      mp_unionindex152 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 0});
      slog::Relation* readrel180 = db->getRelation("mp_union");
      mp_unionindex153 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("mp_union");
      mp_unionindex154 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 3, 4, 0});
      slog::Relation* readrel184 = db->getRelation("mbranch");
      mbranchindex155 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({0, 1, 2});
      slog::Relation* readrel186 = db->getRelation("mp_union");
      mp_unionindex156 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0, 1, 2});
      slog::Relation* readrel188 = db->getRelation("mp_union");
      mp_uniondelta163 = readrel188->getIndex(ord187, true);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("mp_union");
      mp_unionindex157 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0});
      slog::Relation* readrel192 = db->getRelation("mp_union");
      mp_uniondelta164 = readrel192->getIndex(ord191, true);
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("mp_union_ans");
      mp_union_ansindex158 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("mp_union");
      mp_unionindex159 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("mp_union");
      mp_uniondelta165 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("mp_union_ans");
      mp_union_ansindex160 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1});
      slog::Relation* readrel202 = db->getRelation("mp_union_ans");
      mp_union_ansindex161 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("mp_union_ans");
      mp_union_ansindex162 = readrel204->getIndex(ord203, false);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex147, std::array<u64,5>{v_c2, v_c6, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex148, std::array<u64,3>{v_c47, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex149, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex150, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<7,4>($sup5638x93x0x0x0index151, std::array<u64,7>{v_c5, v_c6, v_c2, v_c7, 0, 0, 0}, [&](const std::array<u64,7>& m205) {
          u64 v_c48 = m205[4]; u64 v_c8 = m205[5]; u64 v_c9 = m205[6];
          if (!slog::exists_probe<3,2>(mp_unionindex152, std::array<u64,3>{v_c48, v_c47, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex153, std::array<u64,3>{v_c5, v_c8, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex154, std::array<u64,3>{v_c7, v_c9, 0})) return;
          slog::join_probe<5,4>(mbranchindex155, std::array<u64,5>{v_c2, v_c6, v_c8, v_c9, 0}, [&](const std::array<u64,5>& m206) {
            u64 v_c49 = m206[4];
            slog::join_probe_old<3,3>(mp_unionindex156, mp_uniondelta163, std::array<u64,3>{v_c48, v_c47, v_c49}, [&](const std::array<u64,3>& m207) {
              slog::join_probe_old<3,2>(mp_unionindex157, mp_uniondelta164, std::array<u64,3>{v_c5, v_c8, 0}, [&](const std::array<u64,3>& m208) {
                u64 v_c50 = m208[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex158, std::array<u64,2>{v_c50, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex159, mp_uniondelta165, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m209) {
                  u64 v_c51 = m209[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex160, std::array<u64,2>{v_c51, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex161, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m210) {
                    u64 v_c24 = m210[1];
                    slog::join_probe<2,1>(mp_union_ansindex162, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m211) {
                      u64 v_c52 = m211[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c48, v_c24, v_c52, v_c6, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c6, v_c24, v_c52}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask166* _cont = new ReadTask166(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask166(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mbranch __t0VzH403 p m l r) (body (exists mp_del (1 2 0) 1 __t0VzH403) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 1 r) (join $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 p l m r __t01YW404 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t01YW404 k __t0VzH403) (exists mp_msk (1 2 0) 2 k m) (exists mp_del (1 2 0) 2 r k) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8Ai5407) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join mp_del_ans (0 1) 2 __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask233 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex212;  slog::Index** mp_bldindex213;  slog::Index** mp_mskindex214;  slog::Index** mp_msk_ansindex215;  slog::Index** mp_delindex216;  slog::Index** $sup5638x84x0x0x0index217;  slog::Index** mp_delindex218;  slog::Index** mp_mskindex219;  slog::Index** mp_delindex220;  slog::Index** mp_bldindex221;  slog::Index** mp_del_ansindex222;  slog::Index** mp_bld_ansindex223;  slog::Index** mp_mskindex224;  slog::Index** mp_msk_ansindex225;  slog::Index** mp_delindex226;  slog::Index** mp_del_ansindex227;  slog::Index** mp_bld_ansindex228;  slog::Index** mp_deldelta229;  slog::Index** mp_blddelta230;  slog::Index** mp_mskdelta231;  slog::Index** mp_deldelta232;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("mp_del_ans");
      head_index[0] = readrel235->getIndex(ord234, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("mp_del");
      mp_delindex212 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("mp_bld");
      mp_bldindex213 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({2, 0, 1});
      slog::Relation* readrel241 = db->getRelation("mp_msk");
      mp_mskindex214 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex215 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("mp_del");
      mp_delindex216 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel247 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index217 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 2, 1});
      slog::Relation* readrel249 = db->getRelation("mp_del");
      mp_delindex218 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 2, 1});
      slog::Relation* readrel251 = db->getRelation("mp_del");
      mp_deldelta229 = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("mp_msk");
      mp_mskindex219 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("mp_del");
      mp_delindex220 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 3, 4, 0});
      slog::Relation* readrel257 = db->getRelation("mp_bld");
      mp_bldindex221 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 3, 4, 0});
      slog::Relation* readrel259 = db->getRelation("mp_bld");
      mp_blddelta230 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 0});
      slog::Relation* readrel261 = db->getRelation("mp_del_ans");
      mp_del_ansindex222 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex223 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("mp_msk");
      mp_mskindex224 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("mp_msk");
      mp_mskdelta231 = readrel267->getIndex(ord266, true);
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex225 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 2, 0});
      slog::Relation* readrel271 = db->getRelation("mp_del");
      mp_delindex226 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("mp_del");
      mp_deldelta232 = readrel273->getIndex(ord272, true);
      std::vector<u16> ord274({0, 1});
      slog::Relation* readrel275 = db->getRelation("mp_del_ans");
      mp_del_ansindex227 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1});
      slog::Relation* readrel277 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex228 = readrel277->getIndex(ord276, false);
  
    }
    ReadTask233(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c54 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<3,1>(mp_delindex212, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex213, std::array<u64,5>{v_c2, v_c6, v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex214, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex215, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex216, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x84x0x0x0index217, std::array<u64,6>{v_c2, v_c5, v_c6, v_c7, 0, 0}, [&](const std::array<u64,6>& m278) {
          u64 v_c55 = m278[4]; u64 v_c11 = m278[5];
          slog::join_probe_old<3,3>(mp_delindex218, mp_deldelta229, std::array<u64,3>{v_c55, v_c11, v_c54}, [&](const std::array<u64,3>& m279) {
            if (!slog::exists_probe<3,2>(mp_mskindex219, std::array<u64,3>{v_c11, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex220, std::array<u64,3>{v_c7, v_c11, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex221, mp_blddelta230, std::array<u64,5>{v_c2, v_c6, v_c5, 0, 0}, [&](const std::array<u64,5>& m280) {
              u64 v_c24 = m280[3]; u64 v_c56 = m280[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex222, std::array<u64,2>{v_c24, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex223, std::array<u64,2>{v_c56, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex224, mp_mskdelta231, std::array<u64,3>{v_c11, v_c6, 0}, [&](const std::array<u64,3>& m281) {
                u64 v_c57 = m281[2];
                slog::join_probe<2,2>(mp_msk_ansindex225, std::array<u64,2>{v_c57, v_c2}, [&](const std::array<u64,2>& m282) {
                  slog::join_probe_old<3,2>(mp_delindex226, mp_deldelta232, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m283) {
                    u64 v_c58 = m283[2];
                    slog::join_probe<2,2>(mp_del_ansindex227, std::array<u64,2>{v_c58, v_c24}, [&](const std::array<u64,2>& m284) {
                      slog::join_probe<2,1>(mp_bld_ansindex228, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m285) {
                        u64 v_c59 = m285[1];
                        u64 v_c60 = _prim_band(db, v_c11, v_c6);
                        if (v_c60 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c61 = _prim_gt(db, v_c60, v_c53);
                        if (v_c61 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c61) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c59}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan temp6KDK1090 n q r u v) (body (join mbranch (1 2 3 4 0) 4 q n u v __t9vqe281)) (head (mkstruct mp_union (1 2 0) __4bN9680 r __t9vqe281)) map.slog:99 #f)
  class ReadTask288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp6KDK1090");
      std::vector<u16> ord289({1, 2, 3, 4, 0});
      slog::Relation* readrel290 = db->getRelation("mbranch");
      mbranchindex287 = readrel290->getIndex(ord289, false);
  
    }
    ReadTask288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        slog::join_probe<5,4>(mbranchindex287, std::array<u64,5>{v_c1, v_c3, v_c8, v_c9, 0}, [&](const std::array<u64,5>& m291) {
          u64 v_c62 = m291[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c62}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:temp6KDK1090", _fires);
  
      if (!_done)
      {
        ReadTask288* _cont = new ReadTask288(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask288(db,b), false);
  // (crule (pre (let __tconst3nEl614 constd01925b37634a1a9d24159d8) (let __tconst5JbS3 constff5a1ae012afa5d4c889c50a) (let __tconst00xS4 const7902699be42c8a8e46fbbb45) (let __tconst6RTh7 const624b60c58c9d8bfb6ff1886c) (let __tconst80wL8 const4e07408562bedb8b60ce05c1) (let __tconst69fL1 const4a44dc15364204a80fe80e90) (let __tconst9RBO2 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t9KAP9 __v1) (body (exists mp_put (2 3 0 1) 2 __tconst00xS4 __tconst5JbS3) (exists _enum (1 0) 1 __tconst3nEl614) (join-old mp_put (2 3 0 1) 3 (2 3 0 1) __tconst80wL8 __tconst6RTh7 __t9KAP9 __v0) (exists mp_put_ans (1 0) 1 __v0) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) __tconst00xS4 __tconst5JbS3 __t5DYC6 __t5kVD5) (join _enum (0 1) 2 __t5kVD5 __tconst3nEl614) (join mp_put_ans (0 1) 2 __t5DYC6 __v0)) (head (mkstruct mp_put (1 2 3 0) __2h5j615 __v1 __tconst9RBO2 __tconst69fL1)) mp_basic.slog:14 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex292;  slog::Index** _enumindex293;  slog::Index** mp_putindex294;  slog::Index** mp_put_ansindex295;  slog::Index** mp_putindex296;  slog::Index** _enumindex297;  slog::Index** mp_put_ansindex298;  slog::Index** mp_putdelta299;  slog::Index** mp_putdelta300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord302({2, 3, 0, 1});
      slog::Relation* readrel303 = db->getRelation("mp_put");
      mp_putindex292 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("_enum");
      _enumindex293 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({2, 3, 0, 1});
      slog::Relation* readrel307 = db->getRelation("mp_put");
      mp_putindex294 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({2, 3, 0, 1});
      slog::Relation* readrel309 = db->getRelation("mp_put");
      mp_putdelta299 = readrel309->getIndex(ord308, true);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("mp_put_ans");
      mp_put_ansindex295 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({2, 3, 0, 1});
      slog::Relation* readrel313 = db->getRelation("mp_put");
      mp_putindex296 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({2, 3, 0, 1});
      slog::Relation* readrel315 = db->getRelation("mp_put");
      mp_putdelta300 = readrel315->getIndex(ord314, true);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("_enum");
      _enumindex297 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1});
      slog::Relation* readrel319 = db->getRelation("mp_put_ans");
      mp_put_ansindex298 = readrel319->getIndex(ord318, false);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c63 = v_constd01925b37634a1a9d24159d8;
      u64 v_c64 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c65 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c66 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c67 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c68 = v_const4a44dc15364204a80fe80e90;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c70 = _t[0];
        u64 v_c52 = _t[1];
        if (!slog::exists_probe<4,2>(mp_putindex292, std::array<u64,4>{v_c65, v_c64, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex293, std::array<u64,2>{v_c63, 0})) return;
        slog::join_probe_old<4,3>(mp_putindex294, mp_putdelta299, std::array<u64,4>{v_c67, v_c66, v_c70, 0}, [&](const std::array<u64,4>& m320) {
          u64 v_c24 = m320[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex295, std::array<u64,2>{v_c24, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex296, mp_putdelta300, std::array<u64,4>{v_c65, v_c64, 0, 0}, [&](const std::array<u64,4>& m321) {
            u64 v_c71 = m321[2]; u64 v_c72 = m321[3];
            slog::join_probe<2,2>(_enumindex297, std::array<u64,2>{v_c72, v_c63}, [&](const std::array<u64,2>& m322) {
              slog::join_probe<2,2>(mp_put_ansindex298, std::array<u64,2>{v_c71, v_c24}, [&](const std::array<u64,2>& m323) {
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c52, v_c69, v_c68}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:14", "delta:mp_put_ans", _fires);
  
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
  // (crule (pre) (scan mp_hsb __t8mLF130 __t8nJr131) (body (exists mp_hsb_ans (0 1) 1 __t8mLF130) (join mp_hsb_ans (0 1) 1 __t8mLF130 __v3) (join mp_hsb_ans (0 1) 1 __t8mLF130 __v1) (join $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk0CNK1019 (bxor p0 p1)) (eq __t8nJr131 chk0CNK1019)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t8mLF130 __t8mLF130 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex324;  slog::Index** mp_hsb_ansindex325;  slog::Index** mp_hsb_ansindex326;  slog::Index** $sup5638x29x0x0x1index327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord329({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel330 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel330->getIndex(ord329, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord331({0, 1});
      slog::Relation* readrel332 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex324 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({0, 1});
      slog::Relation* readrel334 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex325 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({0, 1});
      slog::Relation* readrel336 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex326 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel338 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index327 = readrel338->getIndex(ord337, false);
  
    }
    ReadTask328(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex324, std::array<u64,2>{v_c73, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex325, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m339) {
          u64 v_c75 = m339[1];
          slog::join_probe<2,1>(mp_hsb_ansindex326, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m340) {
            u64 v_c52 = m340[1];
            slog::join_all<7>($sup5638x29x0x0x1index327, [&](const std::array<u64,7>& m341) {
              u64 v_c45 = m341[0]; u64 v_c24 = m341[1]; u64 v_c4 = m341[2]; u64 v_c27 = m341[3]; u64 v_c28 = m341[4]; u64 v_c29 = m341[5]; u64 v_c30 = m341[6];
              u64 v_c76 = _prim_bxor(db, v_c27, v_c28);
              if (v_c76 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c74 != v_c76) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c45, v_c24, v_c75, v_c52, v_c4, v_c73, v_c73, v_c27, v_c28, v_c29, v_c30}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask328* _cont = new ReadTask328(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask328(db,b), false);
  // (crule (pre) (scan temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (body (join mbranch (1 2 3 4 0) 4 __v2 __v3 t1 t0 __t85Rb392)) (head (emit mp_join_ans (0 1) __t4lFL393 __t85Rb392)) map.slog:30 #f)
  class ReadTask343 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex342;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join_ans");
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("mp_join_ans");
      head_index[0] = readrel345->getIndex(ord344, false);
      outer_rel = db->getRelation("temp5z0Y1074");
      std::vector<u16> ord346({1, 2, 3, 4, 0});
      slog::Relation* readrel347 = db->getRelation("mbranch");
      mbranchindex342 = readrel347->getIndex(ord346, false);
  
    }
    ReadTask343(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c75 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe<5,4>(mbranchindex342, std::array<u64,5>{v_c78, v_c75, v_c30, v_c29, 0}, [&](const std::array<u64,5>& m348) {
          u64 v_c79 = m348[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c77, v_c79}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp5z0Y1074", _fires);
  
      if (!_done)
      {
        ReadTask343* _cont = new ReadTask343(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask343(db,b), false);
  // (crule (pre) (scan mp_join_ans __t35Cd377 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t35Cd377 p __t8hMI375 q __t5XzA376) (exists mbranch (0 1 2 3 4) 2 __t8hMI375 p) (exists mbranch (0 1 2 3 4) 2 __t5XzA376 q) (exists mp_union (1 2 0) 2 __t8hMI375 __t5XzA376) (exists mp_msk (1 2 0) 1 q) (join-old $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t8hMI375 __t5XzA376 __t4ZhK374 l m n r u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t8hMI375) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5XzA376) (join-old mp_union (0 1 2) 3 (0 1 2) __t4ZhK374 __t8hMI375 __t5XzA376) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join-old mp_msk_ans (0 1) 1 (0 1) __t0M9S378 __v0) (neq p __v0)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask367 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex349;  slog::Index** mbranchindex350;  slog::Index** mbranchindex351;  slog::Index** mp_unionindex352;  slog::Index** mp_mskindex353;  slog::Index** $sup5638x101x0x0x0index354;  slog::Index** mbranchindex355;  slog::Index** mbranchindex356;  slog::Index** mp_unionindex357;  slog::Index** mp_mskindex358;  slog::Index** mp_msk_ansindex359;  slog::Index** mp_joindelta360;  slog::Index** $sup5638x101x0x0x0delta361;  slog::Index** mbranchdelta362;  slog::Index** mbranchdelta363;  slog::Index** mp_uniondelta364;  slog::Index** mp_mskdelta365;  slog::Index** mp_msk_ansdelta366;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("mp_union_ans");
      head_index[0] = readrel369->getIndex(ord368, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord370({0, 1, 2, 3, 4});
      slog::Relation* readrel371 = db->getRelation("mp_join");
      mp_joinindex349 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 1, 2, 3, 4});
      slog::Relation* readrel373 = db->getRelation("mp_join");
      mp_joindelta360 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({0, 1, 2, 3, 4});
      slog::Relation* readrel375 = db->getRelation("mbranch");
      mbranchindex350 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 1, 2, 3, 4});
      slog::Relation* readrel377 = db->getRelation("mbranch");
      mbranchindex351 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("mp_union");
      mp_unionindex352 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("mp_msk");
      mp_mskindex353 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel383 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index354 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel385 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0delta361 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({1, 2, 3, 4, 0});
      slog::Relation* readrel387 = db->getRelation("mbranch");
      mbranchindex355 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 3, 4, 0});
      slog::Relation* readrel389 = db->getRelation("mbranch");
      mbranchdelta362 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({1, 2, 3, 4, 0});
      slog::Relation* readrel391 = db->getRelation("mbranch");
      mbranchindex356 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 2, 3, 4, 0});
      slog::Relation* readrel393 = db->getRelation("mbranch");
      mbranchdelta363 = readrel393->getIndex(ord392, true);
      std::vector<u16> ord394({0, 1, 2});
      slog::Relation* readrel395 = db->getRelation("mp_union");
      mp_unionindex357 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2});
      slog::Relation* readrel397 = db->getRelation("mp_union");
      mp_uniondelta364 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("mp_msk");
      mp_mskindex358 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("mp_msk");
      mp_mskdelta365 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex359 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta366 = readrel405->getIndex(ord404, true);
  
    }
    ReadTask367(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c59 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex349, mp_joindelta360, std::array<u64,5>{v_c80, 0, 0, 0, 0}, [&](const std::array<u64,5>& m406) {
          u64 v_c2 = m406[1]; u64 v_c81 = m406[2]; u64 v_c1 = m406[3]; u64 v_c82 = m406[4];
          if (!slog::exists_probe<5,2>(mbranchindex350, std::array<u64,5>{v_c81, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex351, std::array<u64,5>{v_c82, v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex352, std::array<u64,3>{v_c81, v_c82, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex353, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<11,4>($sup5638x101x0x0x0index354, $sup5638x101x0x0x0delta361, std::array<u64,11>{v_c2, v_c1, v_c81, v_c82, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m407) {
            u64 v_c83 = m407[4]; u64 v_c5 = m407[5]; u64 v_c6 = m407[6]; u64 v_c3 = m407[7]; u64 v_c7 = m407[8]; u64 v_c8 = m407[9]; u64 v_c9 = m407[10];
            u64 v_c84 = _prim_lt(db, v_c3, v_c6);
            if (v_c84 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c84) return;
            slog::join_probe_old<5,5>(mbranchindex355, mbranchdelta362, std::array<u64,5>{v_c2, v_c6, v_c5, v_c7, v_c81}, [&](const std::array<u64,5>& m409) {
              slog::join_probe_old<5,5>(mbranchindex356, mbranchdelta363, std::array<u64,5>{v_c1, v_c3, v_c8, v_c9, v_c82}, [&](const std::array<u64,5>& m410) {
                slog::join_probe_old<3,3>(mp_unionindex357, mp_uniondelta364, std::array<u64,3>{v_c83, v_c81, v_c82}, [&](const std::array<u64,3>& m411) {
                  slog::join_probe_old<3,2>(mp_mskindex358, mp_mskdelta365, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m412) {
                    u64 v_c85 = m412[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex359, mp_msk_ansdelta366, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m413) {
                      u64 v_c24 = m413[1];
                      if (v_c2 == v_c24) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c83, v_c59}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask367* _cont = new ReadTask367(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask367(db,b), false);
  // (crule (pre) (scan mp_join __t1dCZ326 k __t6sa2325 j __t4DNq324) (body (neq j k) (exists mleaf (0 1 2) 2 __t6sa2325 k) (exists mp_put (1 2 0 3) 2 __t4DNq324 k) (exists mp_join_ans (0 1) 1 __t1dCZ326) (join mleaf (0 1 2) 2 __t4DNq324 j w) (join mleaf (0 1 2) 2 __t6sa2325 k v) (join mp_put (1 2 3 0) 3 __t4DNq324 k v __t529R323) (join mp_join_ans (0 1) 1 __t1dCZ326 r)) (head (emit mp_put_ans (0 1) __t529R323 r)) map.slog:39 #f)
  class ReadTask421 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex414;  slog::Index** mp_putindex415;  slog::Index** mp_join_ansindex416;  slog::Index** mleafindex417;  slog::Index** mleafindex418;  slog::Index** mp_putindex419;  slog::Index** mp_join_ansindex420;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("mp_put_ans");
      head_index[0] = readrel423->getIndex(ord422, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord424({0, 1, 2});
      slog::Relation* readrel425 = db->getRelation("mleaf");
      mleafindex414 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 0, 3});
      slog::Relation* readrel427 = db->getRelation("mp_put");
      mp_putindex415 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("mp_join_ans");
      mp_join_ansindex416 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1, 2});
      slog::Relation* readrel431 = db->getRelation("mleaf");
      mleafindex417 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 1, 2});
      slog::Relation* readrel433 = db->getRelation("mleaf");
      mleafindex418 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 3, 0});
      slog::Relation* readrel435 = db->getRelation("mp_put");
      mp_putindex419 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1});
      slog::Relation* readrel437 = db->getRelation("mp_join_ans");
      mp_join_ansindex420 = readrel437->getIndex(ord436, false);
  
    }
    ReadTask421(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c13 = _t[4];
        if (v_c15 == v_c11) return;
        if (!slog::exists_probe<3,2>(mleafindex414, std::array<u64,3>{v_c10, v_c11, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex415, std::array<u64,4>{v_c13, v_c11, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex416, std::array<u64,2>{v_c14, 0})) return;
        slog::join_probe<3,2>(mleafindex417, std::array<u64,3>{v_c13, v_c15, 0}, [&](const std::array<u64,3>& m438) {
          u64 v_c16 = m438[2];
          slog::join_probe<3,2>(mleafindex418, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m439) {
            u64 v_c9 = m439[2];
            slog::join_probe<4,3>(mp_putindex419, std::array<u64,4>{v_c13, v_c11, v_c9, 0}, [&](const std::array<u64,4>& m440) {
              u64 v_c12 = m440[3];
              slog::join_probe<2,1>(mp_join_ansindex420, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m441) {
                u64 v_c7 = m441[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c7}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask421* _cont = new ReadTask421(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask421(db,b), false);
  // (crule (pre (let _00024sqc96G8453 constd4735e3a265e16eee03f5971) (let _00024sqc6cPp454 const5feceb66ffc86f38d952786c) (let _00024sqc6W8K455 const6b86b273ff34fce19d6b804e) (let _00024sqc1g9y458 const6b86b273ff34fce19d6b804e) (let _00024sqc9hYP459 const5feceb66ffc86f38d952786c) (let _00024sqc9QOZ460 const6b86b273ff34fce19d6b804e) (let _00024sqc7qLn461 const5feceb66ffc86f38d952786c) (let _00024sqo4y5c466 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo4y5c466 _00024seq0 _00024seq1) (body (exists $sup5638x127x0x0x0 (0 1 2 3 4 5) 2 _00024seq0 _00024seq1) (join mp_fromlist (1 0) 1 _00024seq1 __t3c2R379) (letp _00024sql6CzH451 (aslst _00024seq0)) (letp k (lref _00024sql6CzH451 _00024sqc6cPp454)) (letp v (lref _00024sql6CzH451 _00024sqc6W8K455)) (letp _00024sql7ZXI456 (aslst _00024seq1)) (let _00024sqn1QVd457 (llen _00024sql7ZXI456)) (cmp ge _00024sqn1QVd457 _00024sqc1g9y458) (let _00024sqp3HUi462 (_0002d _00024sqn1QVd457 _00024sqc7qLn461)) (let xs (lslice _00024sql7ZXI456 _00024sqc9QOZ460 _00024sqp3HUi462)) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 6 k v xs _00024seq0 _00024seq1 __t3c2R379) (exists mp_fromlist (1 0) 1 xs) (join mp_put (2 3 0 1) 2 k v __t4UIA381 __v0) (exists mp_put_ans (0 1) 1 __t4UIA381) (join mp_fromlist_ans (1 0) 1 __v0 __t56xP380) (join mp_fromlist (0 1) 2 __t56xP380 xs) (join mp_put_ans (0 1) 1 __t4UIA381 __v1) (let chk7mft1053 (llen _00024sql6CzH451)) (eq _00024sqc96G8453 chk7mft1053) (letp chk2EoC1054 (lref _00024sql7ZXI456 _00024sqc9hYP459)) (eq _00024seq0 chk2EoC1054)) (head (emit mp_fromlist_ans (1 0) __v1 __t3c2R379)) map.slog:128 #f)
  class ReadTask451 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $sup5638x127x0x0x0index442;  slog::Index** mp_fromlistindex443;  slog::Index** $sup5638x127x0x0x0index444;  slog::Index** mp_fromlistindex445;  slog::Index** mp_putindex446;  slog::Index** mp_put_ansindex447;  slog::Index** mp_fromlist_ansindex448;  slog::Index** mp_fromlistindex449;  slog::Index** mp_put_ansindex450;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord452({1, 0});
      slog::Relation* readrel453 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 0, 2});
      slog::Relation* readrel455 = db->getRelation("$seq_at");
      driver_index = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel457 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index442 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("mp_fromlist");
      mp_fromlistindex443 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel461 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index444 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("mp_fromlist");
      mp_fromlistindex445 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({2, 3, 0, 1});
      slog::Relation* readrel465 = db->getRelation("mp_put");
      mp_putindex446 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("mp_put_ans");
      mp_put_ansindex447 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex448 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({0, 1});
      slog::Relation* readrel471 = db->getRelation("mp_fromlist");
      mp_fromlistindex449 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 1});
      slog::Relation* readrel473 = db->getRelation("mp_put_ans");
      mp_put_ansindex450 = readrel473->getIndex(ord472, false);
  
    }
    ReadTask451(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_constd4735e3a265e16eee03f5971;
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c93, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m474) {
        u64 v_c94 = m474[1];
        u64 v_c95 = m474[2];
        if (buckethash(v_c94) != bucket) return;
        if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index442, std::array<u64,6>{v_c94, v_c95, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlistindex443, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m475) {
          u64 v_c96 = m475[1];
          bool ok476 = true;
          u64 v_c97 = _prim_aslst(db, v_c94, &ok476);
          if (!ok476) return;
          bool ok477 = true;
          u64 v_c11 = _prim_lref(db, v_c97, v_c87, &ok477);
          if (!ok477) return;
          bool ok478 = true;
          u64 v_c9 = _prim_lref(db, v_c97, v_c88, &ok478);
          if (!ok478) return;
          bool ok479 = true;
          u64 v_c98 = _prim_aslst(db, v_c95, &ok479);
          if (!ok479) return;
          u64 v_c99 = _prim_llen(db, v_c98);
          if (v_c99 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          u64 v_c100 = _prim_ge(db, v_c99, v_c89);
          if (v_c100 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          if (!v_c100) return;
          u64 v_c101 = _prim__0002d(db, v_c99, v_c92);
          if (v_c101 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          u64 v_c102 = _prim_lslice(db, v_c98, v_c91, v_c101);
          if (v_c102 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          slog::join_probe<6,6>($sup5638x127x0x0x0index444, std::array<u64,6>{v_c11, v_c9, v_c102, v_c94, v_c95, v_c96}, [&](const std::array<u64,6>& m481) {
            if (!slog::exists_probe<2,1>(mp_fromlistindex445, std::array<u64,2>{v_c102, 0})) return;
            slog::join_probe<4,2>(mp_putindex446, std::array<u64,4>{v_c11, v_c9, 0, 0}, [&](const std::array<u64,4>& m482) {
              u64 v_c103 = m482[2]; u64 v_c24 = m482[3];
              if (!slog::exists_probe<2,1>(mp_put_ansindex447, std::array<u64,2>{v_c103, 0})) return;
              slog::join_probe<2,1>(mp_fromlist_ansindex448, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m483) {
                u64 v_c104 = m483[1];
                slog::join_probe<2,2>(mp_fromlistindex449, std::array<u64,2>{v_c104, v_c102}, [&](const std::array<u64,2>& m484) {
                  slog::join_probe<2,1>(mp_put_ansindex450, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m485) {
                    u64 v_c52 = m485[1];
                    u64 v_c105 = _prim_llen(db, v_c97);
                    if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c86 != v_c105) return;
                    bool ok486 = true;
                    u64 v_c106 = _prim_lref(db, v_c98, v_c90, &ok486);
                    if (!ok486) return;
                    if (v_c94 != v_c106) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c96}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask451* _cont = new ReadTask451(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask451(db,b), false);
  // (crule (pre (let __tconst0V5A29 const6b86b273ff34fce19d6b804e)) (scan mbranch __t8PYQ27 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t8PYQ27 __t0FDo26 __t45uF28) (join mbranch (0 1 2 3 4) 1 __t0FDo26 q n u v) (cmp lt n m) (let __t1fk230 (band q m)) (cmp lt __t1fk230 __tconst0V5A29)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t45uF28 l m n p q r u v)) map.slog:96 #f)
  class ReadTask490 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex487;  slog::Index** mbranchindex488;  slog::Index** mp_uniondelta489;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord491({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel492 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel492->getIndex(ord491, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("mp_union");
      mp_unionindex487 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("mp_union");
      mp_uniondelta489 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 1, 2, 3, 4});
      slog::Relation* readrel498 = db->getRelation("mbranch");
      mbranchindex488 = readrel498->getIndex(ord497, false);
  
    }
    ReadTask490(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c108 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex487, mp_uniondelta489, std::array<u64,3>{v_c108, 0, 0}, [&](const std::array<u64,3>& m499) {
          u64 v_c109 = m499[1]; u64 v_c110 = m499[2];
          slog::join_probe<5,1>(mbranchindex488, std::array<u64,5>{v_c109, 0, 0, 0, 0}, [&](const std::array<u64,5>& m500) {
            u64 v_c1 = m500[1]; u64 v_c3 = m500[2]; u64 v_c8 = m500[3]; u64 v_c9 = m500[4];
            u64 v_c111 = _prim_lt(db, v_c3, v_c6);
            if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c111) return;
            u64 v_c112 = _prim_band(db, v_c1, v_c6);
            if (v_c112 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c113 = _prim_lt(db, v_c112, v_c107);
            if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c113) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c110, v_c5, v_c6, v_c3, v_c2, v_c1, v_c7, v_c8, v_c9}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask490* _cont = new ReadTask490(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask490(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t1WO0167 p) (body (exists $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t1WO0167 k m) (join $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t1WO0167 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask507 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index503;  slog::Index** mp_mskindex504;  slog::Index** $sup5638x42x0x0x0index505;  slog::Index** mp_mskdelta506;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord508({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel509 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel509->getIndex(ord508, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord510({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel511 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index503 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1, 2});
      slog::Relation* readrel513 = db->getRelation("mp_msk");
      mp_mskindex504 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1, 2});
      slog::Relation* readrel515 = db->getRelation("mp_msk");
      mp_mskdelta506 = readrel515->getIndex(ord514, true);
      std::vector<u16> ord516({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel517 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index505 = readrel517->getIndex(ord516, false);
  
    }
    ReadTask507(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<7,1>($sup5638x42x0x0x0index503, std::array<u64,7>{v_c2, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex504, mp_mskdelta506, std::array<u64,3>{v_c114, 0, 0}, [&](const std::array<u64,3>& m518) {
          u64 v_c11 = m518[1]; u64 v_c6 = m518[2];
          slog::join_probe<7,3>($sup5638x42x0x0x0index505, std::array<u64,7>{v_c11, v_c6, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,7>& m519) {
            u64 v_c4 = m519[3]; u64 v_c5 = m519[4]; u64 v_c7 = m519[5]; u64 v_c9 = m519[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c114, v_c2, v_c4, v_c11, v_c5, v_c6, v_c7, v_c9}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask507* _cont = new ReadTask507(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask507(db,b), false);
  // (crule (pre) (scan $sup5638x98x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t61OZ179) (join-old mp_msk_ans (0 1) 2 (0 1) __t61OZ179 p)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t61OZ179 l m n p q u v)) map.slog:99 #f)
  class ReadTask525 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex520;  slog::Index** mp_mskindex521;  slog::Index** mp_msk_ansindex522;  slog::Index** mp_mskdelta523;  slog::Index** mp_msk_ansdelta524;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord526({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel527 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel527->getIndex(ord526, false);
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord528({1, 0});
      slog::Relation* readrel529 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex520 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("mp_msk");
      mp_mskindex521 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("mp_msk");
      mp_mskdelta523 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex522 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta524 = readrel537->getIndex(ord536, true);
  
    }
    ReadTask525(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c1 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c9 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex520, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex521, mp_mskdelta523, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m538) {
          u64 v_c115 = m538[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex522, mp_msk_ansdelta524, std::array<u64,2>{v_c115, v_c2}, [&](const std::array<u64,2>& m539) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c4, v_c7, v_c115, v_c5, v_c6, v_c3, v_c2, v_c1, v_c8, v_c9}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask525* _cont = new ReadTask525(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask525(db,b), false);
  // (crule (pre (let __tconst7JRN647 constd01925b37634a1a9d24159d8)) (scan mp_union __t3Xxz421 __t0DPX420 t) (body (join _enum (0 1) 2 __t0DPX420 __tconst7JRN647)) (head (emit mp_union_ans (0 1) __t3Xxz421 t)) map.slog:90 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex540;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("mp_union_ans");
      head_index[0] = readrel543->getIndex(ord542, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("_enum");
      _enumindex540 = readrel545->getIndex(ord544, false);
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_constd01925b37634a1a9d24159d8;
  
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
        u64 v_c34 = _t[2];
        slog::join_probe<2,2>(_enumindex540, std::array<u64,2>{v_c118, v_c116}, [&](const std::array<u64,2>& m546) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c117, v_c34}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:90", "delta:mp_union", _fires);
  
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
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan mp_hsb __t1lh0397 __t82fz401) (body (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t1lh0397) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t1lh0397) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v3) (exists $sup5638x29x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t1lh0397 __v3) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v1) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t1lh0397 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t1lh0397 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t1lh0397 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t1lh0397 __v0 __v3 __v1 __t4lFL393 dup0XDZ1075 dup8FhK1076 p0 p1 t0 t1) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join mp_msk (1 2 0) 2 p0 __v1 __t8rat400) (join mp_msk_ans (0 1) 1 __t8rat400 __v2) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394) (let chk80EJ1077 (bxor p0 p1)) (eq __t82fz401 chk80EJ1077)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask564 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex547;  slog::Index** $sup5638x29x0x0x2index548;  slog::Index** $sup5638x29x0x0x1index549;  slog::Index** mp_hsb_ansindex550;  slog::Index** $sup5638x29x0x0x2index551;  slog::Index** mp_hsb_ansindex552;  slog::Index** $sup5638x29x0x0x2index553;  slog::Index** mp_mskindex554;  slog::Index** mp_hsb_ansindex555;  slog::Index** $sup5638x29x0x0x1index556;  slog::Index** $sup5638x29x0x0x2index557;  slog::Index** $sup5638x29x0x0x1index558;  slog::Index** $sup5638x29x0x0x0index559;  slog::Index** mp_joinindex560;  slog::Index** mp_mskindex561;  slog::Index** mp_msk_ansindex562;  slog::Index** mp_joindelta563;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord565({0, 1});
      slog::Relation* readrel566 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex547 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel568 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index548 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel570 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index549 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex550 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel574 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index551 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 1});
      slog::Relation* readrel576 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex552 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel578 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index553 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({2, 0, 1});
      slog::Relation* readrel580 = db->getRelation("mp_msk");
      mp_mskindex554 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({0, 1});
      slog::Relation* readrel582 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex555 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel584 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index556 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel586 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index557 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel588 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index558 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 0, 2, 3, 4});
      slog::Relation* readrel590 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index559 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 3, 4, 0});
      slog::Relation* readrel592 = db->getRelation("mp_join");
      mp_joinindex560 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 2, 3, 4, 0});
      slog::Relation* readrel594 = db->getRelation("mp_join");
      mp_joindelta563 = readrel594->getIndex(ord593, true);
      std::vector<u16> ord595({1, 2, 0});
      slog::Relation* readrel596 = db->getRelation("mp_msk");
      mp_mskindex561 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({0, 1});
      slog::Relation* readrel598 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex562 = readrel598->getIndex(ord597, false);
  
    }
    ReadTask564(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex547, std::array<u64,2>{v_c120, 0})) return;
        if (!slog::exists_probe<11,1>($sup5638x29x0x0x2index548, std::array<u64,11>{v_c120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index549, std::array<u64,7>{v_c120, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex550, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m599) {
          u64 v_c75 = m599[1];
          if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index551, std::array<u64,11>{v_c120, v_c75, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex552, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m600) {
            u64 v_c52 = m600[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index553, std::array<u64,11>{v_c120, v_c52, v_c75, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex554, std::array<u64,3>{v_c52, 0, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex555, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m601) {
              u64 v_c24 = m601[1];
              if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index556, std::array<u64,7>{v_c120, v_c24, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup5638x29x0x0x2index557, std::array<u64,11>{v_c120, v_c24, v_c75, v_c52, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m602) {
                u64 v_c77 = m602[4]; u64 v_c122 = m602[5]; u64 v_c123 = m602[6]; u64 v_c27 = m602[7]; u64 v_c28 = m602[8]; u64 v_c29 = m602[9]; u64 v_c30 = m602[10];
                if (v_c120 != v_c123) return;
                if (v_c120 != v_c122) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index558, std::array<u64,7>{v_c77, v_c27, v_c28, v_c29, v_c30, v_c120, v_c24}, [&](const std::array<u64,7>& m603) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index559, std::array<u64,5>{v_c27, v_c77, v_c28, v_c29, v_c30}, [&](const std::array<u64,5>& m604) {
                    slog::join_probe_old<5,5>(mp_joinindex560, mp_joindelta563, std::array<u64,5>{v_c27, v_c29, v_c28, v_c30, v_c77}, [&](const std::array<u64,5>& m605) {
                      slog::join_probe<3,2>(mp_mskindex561, std::array<u64,3>{v_c27, v_c52, 0}, [&](const std::array<u64,3>& m606) {
                        u64 v_c124 = m606[2];
                        slog::join_probe<2,1>(mp_msk_ansindex562, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m607) {
                          u64 v_c78 = m607[1];
                          u64 v_c125 = _prim_band(db, v_c27, v_c24);
                          if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c126 = _prim_gt(db, v_c125, v_c119);
                          if (v_c126 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c126) return;
                          u64 v_c127 = _prim_bxor(db, v_c27, v_c28);
                          if (v_c127 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (v_c121 != v_c127) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c77, v_c78, v_c75, v_c29, v_c30});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c78, v_c75, v_c30, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask564* _cont = new ReadTask564(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask564(db,b), false);
  // (crule (pre (let __trid8kM8804 constc742e02805b99df617265a41) (let __trel25wO805 constdd7bbf31ce5f578b9805e840) (let __tcol0cwL806 const5feceb66ffc86f38d952786c) (let __trel3Xns807 constdd7bbf31ce5f578b9805e840) (let __tcol5eC3808 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid8kM8804 __trel25wO805 __tcol0cwL806 (1 2 3 4 0)) (tycheck m (accept int) __trid8kM8804 __trel3Xns807 __tcol5eC3808 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __5w4Y803 q m)) map.slog:96 #f)
  class ReadTask609 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
  
    }
    ReadTask609(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c128 = v_constc742e02805b99df617265a41;
      u64 v_c129 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c132 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c1 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c9 = _t[8];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c128, v_c129, v_c130, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c128, v_c131, v_c132, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask609* _cont = new ReadTask609(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask609(db,b), false);
  // (crule (pre) (scan mp_join_ans __t7HEI219 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t7HEI219 p __t0o62217 q __t0BoC218) (exists mbranch (0 1 2 3 4) 2 __t0o62217 p) (exists mbranch (0 1 2 3 4) 2 __t0BoC218 q) (exists mp_union (1 2 0) 2 __t0o62217 __t0BoC218) (exists mp_msk (1 2 0) 1 p) (join-old $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t0o62217 __t0BoC218 __t5xrH216 l m n r u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0o62217) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0BoC218) (join-old mp_union (0 1 2) 3 (0 1 2) __t5xrH216 __t0o62217 __t0BoC218) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join-old mp_msk_ans (0 1) 1 (0 1) __t5IgR220 __v0) (neq q __v0)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask628 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex610;  slog::Index** mbranchindex611;  slog::Index** mbranchindex612;  slog::Index** mp_unionindex613;  slog::Index** mp_mskindex614;  slog::Index** $sup5638x110x0x0x0index615;  slog::Index** mbranchindex616;  slog::Index** mbranchindex617;  slog::Index** mp_unionindex618;  slog::Index** mp_mskindex619;  slog::Index** mp_msk_ansindex620;  slog::Index** mp_joindelta621;  slog::Index** $sup5638x110x0x0x0delta622;  slog::Index** mbranchdelta623;  slog::Index** mbranchdelta624;  slog::Index** mp_uniondelta625;  slog::Index** mp_mskdelta626;  slog::Index** mp_msk_ansdelta627;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("mp_union_ans");
      head_index[0] = readrel630->getIndex(ord629, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord631({0, 1, 2, 3, 4});
      slog::Relation* readrel632 = db->getRelation("mp_join");
      mp_joinindex610 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({0, 1, 2, 3, 4});
      slog::Relation* readrel634 = db->getRelation("mp_join");
      mp_joindelta621 = readrel634->getIndex(ord633, true);
      std::vector<u16> ord635({0, 1, 2, 3, 4});
      slog::Relation* readrel636 = db->getRelation("mbranch");
      mbranchindex611 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({0, 1, 2, 3, 4});
      slog::Relation* readrel638 = db->getRelation("mbranch");
      mbranchindex612 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 2, 0});
      slog::Relation* readrel640 = db->getRelation("mp_union");
      mp_unionindex613 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 2, 0});
      slog::Relation* readrel642 = db->getRelation("mp_msk");
      mp_mskindex614 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel644 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index615 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel646 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0delta622 = readrel646->getIndex(ord645, true);
      std::vector<u16> ord647({1, 2, 3, 4, 0});
      slog::Relation* readrel648 = db->getRelation("mbranch");
      mbranchindex616 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({1, 2, 3, 4, 0});
      slog::Relation* readrel650 = db->getRelation("mbranch");
      mbranchdelta623 = readrel650->getIndex(ord649, true);
      std::vector<u16> ord651({1, 2, 3, 4, 0});
      slog::Relation* readrel652 = db->getRelation("mbranch");
      mbranchindex617 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 3, 4, 0});
      slog::Relation* readrel654 = db->getRelation("mbranch");
      mbranchdelta624 = readrel654->getIndex(ord653, true);
      std::vector<u16> ord655({0, 1, 2});
      slog::Relation* readrel656 = db->getRelation("mp_union");
      mp_unionindex618 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({0, 1, 2});
      slog::Relation* readrel658 = db->getRelation("mp_union");
      mp_uniondelta625 = readrel658->getIndex(ord657, true);
      std::vector<u16> ord659({1, 2, 0});
      slog::Relation* readrel660 = db->getRelation("mp_msk");
      mp_mskindex619 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 2, 0});
      slog::Relation* readrel662 = db->getRelation("mp_msk");
      mp_mskdelta626 = readrel662->getIndex(ord661, true);
      std::vector<u16> ord663({0, 1});
      slog::Relation* readrel664 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex620 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({0, 1});
      slog::Relation* readrel666 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta627 = readrel666->getIndex(ord665, true);
  
    }
    ReadTask628(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex610, mp_joindelta621, std::array<u64,5>{v_c133, 0, 0, 0, 0}, [&](const std::array<u64,5>& m667) {
          u64 v_c2 = m667[1]; u64 v_c134 = m667[2]; u64 v_c1 = m667[3]; u64 v_c135 = m667[4];
          if (!slog::exists_probe<5,2>(mbranchindex611, std::array<u64,5>{v_c134, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex612, std::array<u64,5>{v_c135, v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex613, std::array<u64,3>{v_c134, v_c135, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex614, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<11,4>($sup5638x110x0x0x0index615, $sup5638x110x0x0x0delta622, std::array<u64,11>{v_c2, v_c1, v_c134, v_c135, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m668) {
            u64 v_c136 = m668[4]; u64 v_c5 = m668[5]; u64 v_c6 = m668[6]; u64 v_c3 = m668[7]; u64 v_c7 = m668[8]; u64 v_c8 = m668[9]; u64 v_c9 = m668[10];
            u64 v_c137 = _prim_lt(db, v_c6, v_c3);
            if (v_c137 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c137) return;
            slog::join_probe_old<5,5>(mbranchindex616, mbranchdelta623, std::array<u64,5>{v_c2, v_c6, v_c5, v_c7, v_c134}, [&](const std::array<u64,5>& m670) {
              slog::join_probe_old<5,5>(mbranchindex617, mbranchdelta624, std::array<u64,5>{v_c1, v_c3, v_c8, v_c9, v_c135}, [&](const std::array<u64,5>& m671) {
                slog::join_probe_old<3,3>(mp_unionindex618, mp_uniondelta625, std::array<u64,3>{v_c136, v_c134, v_c135}, [&](const std::array<u64,3>& m672) {
                  slog::join_probe_old<3,2>(mp_mskindex619, mp_mskdelta626, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m673) {
                    u64 v_c138 = m673[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex620, mp_msk_ansdelta627, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m674) {
                      u64 v_c24 = m674[1];
                      if (v_c1 == v_c24) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c136, v_c59}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask628* _cont = new ReadTask628(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask628(db,b), false);
}

