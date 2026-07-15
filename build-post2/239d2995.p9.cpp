
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const1ca60a80dbae6414bef23d65;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76237108756d80d8c9f21f56;
extern u64 v_const8c1f1046219ddd216a023f79;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_cb145c2cedadd9aea(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t2bXu55 __v3) (body (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists $sup5638x25x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t2bXu55 __v3) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t2bXu55) (join-old mp_hsb_ans (0 1) 1 (0 1) __t2bXu55 __v1) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2bXu55 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join-old mp_hsb_ans (0 1) 1 (0 1) __t2bXu55 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t2bXu55 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2bXu55 __v0 __v3 __v1 __t6Puw51 dup3kne1056 dup92Cz1057 p0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join-old mp_msk_ans (0 1) 1 (0 1) __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex0;  slog::Index** $sup5638x25x0x0x2index1;  slog::Index** $sup5638x25x0x0x1index2;  slog::Index** mp_hsb_ansindex3;  slog::Index** $sup5638x25x0x0x2index4;  slog::Index** mp_mskindex5;  slog::Index** mp_hsb_ansindex6;  slog::Index** $sup5638x25x0x0x1index7;  slog::Index** $sup5638x25x0x0x2index8;  slog::Index** $sup5638x25x0x0x1index9;  slog::Index** $sup5638x25x0x0x0index10;  slog::Index** mp_joinindex11;  slog::Index** mp_mskindex12;  slog::Index** mp_msk_ansindex13;  slog::Index** mp_hsbindex14;  slog::Index** mp_hsb_ansdelta15;  slog::Index** mp_hsb_ansdelta16;  slog::Index** mp_joindelta17;  slog::Index** mp_mskdelta18;  slog::Index** mp_msk_ansdelta19;  slog::Index** mp_hsbdelta20;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord22({0, 1});
      slog::Relation* readrel23 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex0 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel25 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel27 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index2 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex3 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta15 = readrel31->getIndex(ord30, true);
      std::vector<u16> ord32({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel33 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index4 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 0, 1});
      slog::Relation* readrel35 = db->getRelation("mp_msk");
      mp_mskindex5 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex6 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1});
      slog::Relation* readrel39 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta16 = readrel39->getIndex(ord38, true);
      std::vector<u16> ord40({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel41 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index7 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel43 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index8 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel45 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index9 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0, 2, 3, 4});
      slog::Relation* readrel47 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index10 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 3, 4, 0});
      slog::Relation* readrel49 = db->getRelation("mp_join");
      mp_joinindex11 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 2, 3, 4, 0});
      slog::Relation* readrel51 = db->getRelation("mp_join");
      mp_joindelta17 = readrel51->getIndex(ord50, true);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("mp_msk");
      mp_mskindex12 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 0});
      slog::Relation* readrel55 = db->getRelation("mp_msk");
      mp_mskdelta18 = readrel55->getIndex(ord54, true);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex13 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta19 = readrel59->getIndex(ord58, true);
      std::vector<u16> ord60({0, 1});
      slog::Relation* readrel61 = db->getRelation("mp_hsb");
      mp_hsbindex14 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("mp_hsb");
      mp_hsbdelta20 = readrel63->getIndex(ord62, true);
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index1, std::array<u64,11>{v_c1, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index2, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(mp_hsb_ansindex3, mp_hsb_ansdelta15, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m64) {
          u64 v_c3 = m64[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index4, std::array<u64,11>{v_c1, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex5, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex6, mp_hsb_ansdelta16, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m65) {
            u64 v_c4 = m65[1];
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index7, std::array<u64,7>{v_c1, v_c4, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index8, std::array<u64,11>{v_c1, v_c4, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m66) {
              u64 v_c5 = m66[4]; u64 v_c6 = m66[5]; u64 v_c7 = m66[6]; u64 v_c8 = m66[7]; u64 v_c9 = m66[8]; u64 v_c10 = m66[9]; u64 v_c11 = m66[10];
              if (v_c1 != v_c7) return;
              if (v_c1 != v_c6) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index9, std::array<u64,7>{v_c5, v_c8, v_c9, v_c10, v_c11, v_c1, v_c4}, [&](const std::array<u64,7>& m67) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index10, std::array<u64,5>{v_c8, v_c5, v_c9, v_c10, v_c11}, [&](const std::array<u64,5>& m68) {
                  slog::join_probe_old<5,5>(mp_joinindex11, mp_joindelta17, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c5}, [&](const std::array<u64,5>& m69) {
                    slog::join_probe_old<3,2>(mp_mskindex12, mp_mskdelta18, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m70) {
                      u64 v_c12 = m70[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex13, mp_msk_ansdelta19, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m71) {
                        u64 v_c13 = m71[1];
                        u64 v_c14 = _prim_bxor(db, v_c8, v_c9);
                        if (v_c14 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex14, mp_hsbdelta20, std::array<u64,2>{v_c1, v_c14}, [&](const std::array<u64,2>& m72) {
                          u64 v_c15 = _prim_band(db, v_c8, v_c4);
                          if (v_c15 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c16 = _prim_lt(db, v_c15, v_c0);
                          if (v_c16 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c16) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c13, v_c2, v_c10, v_c11});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c2, v_c10, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre) (scan $sup5638x104x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 q) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t4OmG128) (join-old mp_msk_ans (0 1) 2 (0 1) __t4OmG128 q)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t4OmG128 l m n p q r v)) map.slog:105 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex74;  slog::Index** mp_mskindex75;  slog::Index** mp_msk_ansindex76;  slog::Index** mp_mskdelta77;  slog::Index** mp_msk_ansdelta78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord80({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel81 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel81->getIndex(ord80, false);
      outer_rel = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex74 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 2, 0});
      slog::Relation* readrel85 = db->getRelation("mp_msk");
      mp_mskindex75 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("mp_msk");
      mp_mskdelta77 = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex76 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta78 = readrel91->getIndex(ord90, true);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c20 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c23 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c25 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex74, std::array<u64,2>{v_c22, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex75, mp_mskdelta77, std::array<u64,3>{v_c21, v_c20, 0}, [&](const std::array<u64,3>& m92) {
          u64 v_c26 = m92[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex76, mp_msk_ansdelta78, std::array<u64,2>{v_c26, v_c22}, [&](const std::array<u64,2>& m93) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c17, v_c24, v_c26, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c25}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mp_union __t9WRQ357 __t6yxH356 v) (body (exists mp_union (1 2 0) 1 __t6yxH356) (exists mbranch (4 0 1 2 3) 1 v) (exists $sup5638x107x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (join mp_union (1 2 0) 1 __t6yxH356 __t3rQ8350 __t05l7352) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t05l7352 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t05l7352 v) (join mbranch (4 0 1 2 3) 2 v __t3rQ8350 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t05l7352) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t05l7352 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6yxH356) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t05l7352 l m p r __t4mLe355) (join mbranch (1 2 3 4 0) 5 p m l r __t6yxH356) (join mp_msk (1 2 0) 3 p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex94;  slog::Index** mbranchindex95;  slog::Index** $sup5638x107x0x0x0index96;  slog::Index** $sup5638x107x0x0x1index97;  slog::Index** mp_union_ansindex98;  slog::Index** mp_unionindex99;  slog::Index** $sup5638x107x0x0x0index100;  slog::Index** $sup5638x107x0x0x1index101;  slog::Index** mbranchindex102;  slog::Index** $sup5638x107x0x0x1index103;  slog::Index** mp_mskindex104;  slog::Index** mp_msk_ansindex105;  slog::Index** $sup5638x107x0x0x0index106;  slog::Index** mbranchindex107;  slog::Index** mp_mskindex108;  slog::Index** $sup5638x107x0x0x1index109;  slog::Index** mbranchindex110;  slog::Index** mp_mskindex111;  slog::Index** mp_msk_ansindex112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord114({1, 2, 0});
      slog::Relation* readrel115 = db->getRelation("mp_union");
      mp_unionindex94 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({4, 0, 1, 2, 3});
      slog::Relation* readrel117 = db->getRelation("mbranch");
      mbranchindex95 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel119 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index96 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel121 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index97 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("mp_union_ans");
      mp_union_ansindex98 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("mp_union");
      mp_unionindex99 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel127 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index100 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel129 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index101 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({4, 0, 1, 2, 3});
      slog::Relation* readrel131 = db->getRelation("mbranch");
      mbranchindex102 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel133 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index103 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({2, 0, 1});
      slog::Relation* readrel135 = db->getRelation("mp_msk");
      mp_mskindex104 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex105 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel139 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index106 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 3, 4, 0});
      slog::Relation* readrel141 = db->getRelation("mbranch");
      mbranchindex107 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("mp_msk");
      mp_mskindex108 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel145 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index109 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 2, 3, 4, 0});
      slog::Relation* readrel147 = db->getRelation("mbranch");
      mbranchindex110 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 0});
      slog::Relation* readrel149 = db->getRelation("mp_msk");
      mp_mskindex111 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex112 = readrel151->getIndex(ord150, false);
  
    }
    ReadTask113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c29 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex94, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex95, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index96, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index97, std::array<u64,10>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex98, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m152) {
          u64 v_c4 = m152[1];
          slog::join_probe<3,1>(mp_unionindex99, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m153) {
            u64 v_c30 = m153[1]; u64 v_c31 = m153[2];
            if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index100, std::array<u64,9>{v_c31, v_c25, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index101, std::array<u64,10>{v_c31, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex102, std::array<u64,5>{v_c25, v_c30, 0, 0, 0}, [&](const std::array<u64,5>& m154) {
              u64 v_c22 = m154[2]; u64 v_c20 = m154[3]; u64 v_c24 = m154[4];
              if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index103, std::array<u64,10>{v_c25, v_c20, v_c22, v_c24, v_c31, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex104, std::array<u64,3>{v_c20, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex105, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe<9,5>($sup5638x107x0x0x0index106, std::array<u64,9>{v_c22, v_c20, v_c24, v_c25, v_c31, 0, 0, 0, 0}, [&](const std::array<u64,9>& m155) {
                u64 v_c18 = m155[5]; u64 v_c19 = m155[6]; u64 v_c21 = m155[7]; u64 v_c23 = m155[8];
                u64 v_c32 = _prim_lt(db, v_c19, v_c20);
                if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                if (!v_c32) return;
                if (!slog::exists_probe<5,5>(mbranchindex107, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c29})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex108, std::array<u64,3>{v_c21, v_c20, 0})) return;
                slog::join_probe<10,9>($sup5638x107x0x0x1index109, std::array<u64,10>{v_c25, v_c20, v_c22, v_c24, v_c31, v_c18, v_c19, v_c21, v_c23, 0}, [&](const std::array<u64,10>& m157) {
                  u64 v_c33 = m157[9];
                  slog::join_probe<5,5>(mbranchindex110, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c29}, [&](const std::array<u64,5>& m158) {
                    slog::join_probe<3,3>(mp_mskindex111, std::array<u64,3>{v_c21, v_c20, v_c33}, [&](const std::array<u64,3>& m159) {
                      slog::join_probe<2,2>(mp_msk_ansindex112, std::array<u64,2>{v_c33, v_c22}, [&](const std::array<u64,2>& m160) {
                        u64 v_c34 = _prim_band(db, v_c21, v_c20);
                        if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c35 = _prim_gt(db, v_c34, v_c27);
                        if (v_c35 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c35) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c4, v_c20, v_c22, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c20, v_c24, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask113* _cont = new ReadTask113(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask113(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join mp_hsb_ans (0 1) 0 __t1Rb9367 __v3) (join mp_hsb_ans (0 1) 1 __t1Rb9367 __v1) (let __t3QgY368 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1Rb9367 __t3QgY368)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t1Rb9367 __t1Rb9367 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex162;  slog::Index** mp_hsb_ansindex163;  slog::Index** mp_hsbindex164;  slog::Index** mp_hsbdelta165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord167({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel168 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel168->getIndex(ord167, false);
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex162 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex163 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("mp_hsb");
      mp_hsbindex164 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("mp_hsb");
      mp_hsbdelta165 = readrel176->getIndex(ord175, true);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c11 = _t[6];
        slog::join_all<2>(mp_hsb_ansindex162, [&](const std::array<u64,2>& m177) {
          u64 v_c37 = m177[0]; u64 v_c2 = m177[1];
          slog::join_probe<2,1>(mp_hsb_ansindex163, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m178) {
            u64 v_c3 = m178[1];
            u64 v_c38 = _prim_bxor(db, v_c8, v_c9);
            if (v_c38 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            slog::join_probe_old<2,2>(mp_hsbindex164, mp_hsbdelta165, std::array<u64,2>{v_c37, v_c38}, [&](const std::array<u64,2>& m179) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c36, v_c4, v_c2, v_c3, v_c17, v_c37, v_c37, v_c8, v_c9, v_c10, v_c11}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan mp_union_ans __t9WRQ357 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t9WRQ357 __t6yxH356 v) (exists mbranch (4 0 1 2 3) 1 v) (exists $sup5638x107x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join-old mp_union (1 2 0) 1 (1 2 0) __t6yxH356 __t3rQ8350 __t05l7352) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t05l7352 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t05l7352 v) (join-old mbranch (4 0 1 2 3) 2 (4 0 1 2 3) v __t3rQ8350 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t05l7352) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join-old $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t05l7352 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6yxH356) (exists mp_msk (1 2 0) 2 p n) (join-old $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t05l7352 l m p r __t4mLe355) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask205 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex180;  slog::Index** mbranchindex181;  slog::Index** $sup5638x107x0x0x0index182;  slog::Index** $sup5638x107x0x0x1index183;  slog::Index** mp_unionindex184;  slog::Index** $sup5638x107x0x0x0index185;  slog::Index** $sup5638x107x0x0x1index186;  slog::Index** mbranchindex187;  slog::Index** $sup5638x107x0x0x1index188;  slog::Index** mp_mskindex189;  slog::Index** mp_msk_ansindex190;  slog::Index** $sup5638x107x0x0x0index191;  slog::Index** mbranchindex192;  slog::Index** mp_mskindex193;  slog::Index** $sup5638x107x0x0x1index194;  slog::Index** mbranchindex195;  slog::Index** mp_mskindex196;  slog::Index** mp_msk_ansindex197;  slog::Index** mp_uniondelta198;  slog::Index** mp_uniondelta199;  slog::Index** mbranchdelta200;  slog::Index** $sup5638x107x0x0x0delta201;  slog::Index** $sup5638x107x0x0x1delta202;  slog::Index** mbranchdelta203;  slog::Index** mp_mskdelta204;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord206({0, 1, 2});
      slog::Relation* readrel207 = db->getRelation("mp_union");
      mp_unionindex180 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1, 2});
      slog::Relation* readrel209 = db->getRelation("mp_union");
      mp_uniondelta198 = readrel209->getIndex(ord208, true);
      std::vector<u16> ord210({4, 0, 1, 2, 3});
      slog::Relation* readrel211 = db->getRelation("mbranch");
      mbranchindex181 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel213 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index182 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel215 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index183 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 2, 0});
      slog::Relation* readrel217 = db->getRelation("mp_union");
      mp_unionindex184 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("mp_union");
      mp_uniondelta199 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel221 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index185 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel223 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index186 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({4, 0, 1, 2, 3});
      slog::Relation* readrel225 = db->getRelation("mbranch");
      mbranchindex187 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({4, 0, 1, 2, 3});
      slog::Relation* readrel227 = db->getRelation("mbranch");
      mbranchdelta200 = readrel227->getIndex(ord226, true);
      std::vector<u16> ord228({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel229 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index188 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({2, 0, 1});
      slog::Relation* readrel231 = db->getRelation("mp_msk");
      mp_mskindex189 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex190 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel235 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index191 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel237 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0delta201 = readrel237->getIndex(ord236, true);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("mbranch");
      mbranchindex192 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("mp_msk");
      mp_mskindex193 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel243 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index194 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel245 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta202 = readrel245->getIndex(ord244, true);
      std::vector<u16> ord246({1, 2, 3, 4, 0});
      slog::Relation* readrel247 = db->getRelation("mbranch");
      mbranchindex195 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 3, 4, 0});
      slog::Relation* readrel249 = db->getRelation("mbranch");
      mbranchdelta203 = readrel249->getIndex(ord248, true);
      std::vector<u16> ord250({1, 2, 0});
      slog::Relation* readrel251 = db->getRelation("mp_msk");
      mp_mskindex196 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("mp_msk");
      mp_mskdelta204 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex197 = readrel255->getIndex(ord254, false);
  
    }
    ReadTask205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe_old<3,1>(mp_unionindex180, mp_uniondelta198, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m256) {
          u64 v_c29 = m256[1]; u64 v_c25 = m256[2];
          if (!slog::exists_probe<5,1>(mbranchindex181, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index182, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index183, std::array<u64,10>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex184, mp_uniondelta199, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m257) {
            u64 v_c30 = m257[1]; u64 v_c31 = m257[2];
            if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index185, std::array<u64,9>{v_c31, v_c25, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index186, std::array<u64,10>{v_c31, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex187, mbranchdelta200, std::array<u64,5>{v_c25, v_c30, 0, 0, 0}, [&](const std::array<u64,5>& m258) {
              u64 v_c22 = m258[2]; u64 v_c20 = m258[3]; u64 v_c24 = m258[4];
              if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index188, std::array<u64,10>{v_c25, v_c20, v_c22, v_c24, v_c31, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex189, std::array<u64,3>{v_c20, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex190, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe_old<9,5>($sup5638x107x0x0x0index191, $sup5638x107x0x0x0delta201, std::array<u64,9>{v_c22, v_c20, v_c24, v_c25, v_c31, 0, 0, 0, 0}, [&](const std::array<u64,9>& m259) {
                u64 v_c18 = m259[5]; u64 v_c19 = m259[6]; u64 v_c21 = m259[7]; u64 v_c23 = m259[8];
                u64 v_c39 = _prim_lt(db, v_c19, v_c20);
                if (v_c39 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                if (!v_c39) return;
                if (!slog::exists_probe<5,5>(mbranchindex192, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c29})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex193, std::array<u64,3>{v_c21, v_c20, 0})) return;
                slog::join_probe_old<10,9>($sup5638x107x0x0x1index194, $sup5638x107x0x0x1delta202, std::array<u64,10>{v_c25, v_c20, v_c22, v_c24, v_c31, v_c18, v_c19, v_c21, v_c23, 0}, [&](const std::array<u64,10>& m261) {
                  u64 v_c33 = m261[9];
                  slog::join_probe_old<5,5>(mbranchindex195, mbranchdelta203, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c29}, [&](const std::array<u64,5>& m262) {
                    slog::join_probe_old<3,3>(mp_mskindex196, mp_mskdelta204, std::array<u64,3>{v_c21, v_c20, v_c33}, [&](const std::array<u64,3>& m263) {
                      slog::join_probe<2,2>(mp_msk_ansindex197, std::array<u64,2>{v_c33, v_c22}, [&](const std::array<u64,2>& m264) {
                        u64 v_c34 = _prim_band(db, v_c21, v_c20);
                        if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c40 = _prim_gt(db, v_c34, v_c27);
                        if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c40) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c31, v_c4, v_c20, v_c22, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c20, v_c24, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask205* _cont = new ReadTask205(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask205(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan mp_hsb __t2bXu55 __t9Mxe59) (body (exists mp_hsb_ans (0 1) 1 __t2bXu55) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t2bXu55) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t2bXu55) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v3) (exists $sup5638x25x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t2bXu55 __v3) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v1) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2bXu55 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t2bXu55 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t2bXu55 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2bXu55 __v0 __v3 __v1 __t6Puw51 dup3kne1056 dup92Cz1057 p0 p1 t0 t1) (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join mp_msk (1 2 0) 2 p0 __v1 __t6JeD58) (join mp_msk_ans (0 1) 1 __t6JeD58 __v2) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52) (let chk1WDr1058 (bxor p0 p1)) (eq __t9Mxe59 chk1WDr1058)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask283 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex266;  slog::Index** $sup5638x25x0x0x2index267;  slog::Index** $sup5638x25x0x0x1index268;  slog::Index** mp_hsb_ansindex269;  slog::Index** $sup5638x25x0x0x2index270;  slog::Index** mp_hsb_ansindex271;  slog::Index** $sup5638x25x0x0x2index272;  slog::Index** mp_mskindex273;  slog::Index** mp_hsb_ansindex274;  slog::Index** $sup5638x25x0x0x1index275;  slog::Index** $sup5638x25x0x0x2index276;  slog::Index** $sup5638x25x0x0x1index277;  slog::Index** $sup5638x25x0x0x0index278;  slog::Index** mp_joinindex279;  slog::Index** mp_mskindex280;  slog::Index** mp_msk_ansindex281;  slog::Index** mp_joindelta282;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord284({0, 1});
      slog::Relation* readrel285 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex266 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel287 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index267 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel289 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index268 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex269 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel293 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index270 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({0, 1});
      slog::Relation* readrel295 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex271 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel297 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index272 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({2, 0, 1});
      slog::Relation* readrel299 = db->getRelation("mp_msk");
      mp_mskindex273 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex274 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel303 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index275 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel305 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index276 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel307 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index277 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 0, 2, 3, 4});
      slog::Relation* readrel309 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index278 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 3, 4, 0});
      slog::Relation* readrel311 = db->getRelation("mp_join");
      mp_joinindex279 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("mp_join");
      mp_joindelta282 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("mp_msk");
      mp_mskindex280 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex281 = readrel317->getIndex(ord316, false);
  
    }
    ReadTask283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex266, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<11,1>($sup5638x25x0x0x2index267, std::array<u64,11>{v_c1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index268, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex269, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m318) {
          u64 v_c2 = m318[1];
          if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index270, std::array<u64,11>{v_c1, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex271, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m319) {
            u64 v_c3 = m319[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index272, std::array<u64,11>{v_c1, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex273, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex274, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m320) {
              u64 v_c4 = m320[1];
              if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index275, std::array<u64,7>{v_c1, v_c4, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup5638x25x0x0x2index276, std::array<u64,11>{v_c1, v_c4, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m321) {
                u64 v_c5 = m321[4]; u64 v_c6 = m321[5]; u64 v_c7 = m321[6]; u64 v_c8 = m321[7]; u64 v_c9 = m321[8]; u64 v_c10 = m321[9]; u64 v_c11 = m321[10];
                if (v_c1 != v_c7) return;
                if (v_c1 != v_c6) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index277, std::array<u64,7>{v_c5, v_c8, v_c9, v_c10, v_c11, v_c1, v_c4}, [&](const std::array<u64,7>& m322) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index278, std::array<u64,5>{v_c8, v_c5, v_c9, v_c10, v_c11}, [&](const std::array<u64,5>& m323) {
                    slog::join_probe_old<5,5>(mp_joinindex279, mp_joindelta282, std::array<u64,5>{v_c8, v_c10, v_c9, v_c11, v_c5}, [&](const std::array<u64,5>& m324) {
                      slog::join_probe<3,2>(mp_mskindex280, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m325) {
                        u64 v_c12 = m325[2];
                        slog::join_probe<2,1>(mp_msk_ansindex281, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m326) {
                          u64 v_c13 = m326[1];
                          u64 v_c15 = _prim_band(db, v_c8, v_c4);
                          if (v_c15 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c41 = _prim_lt(db, v_c15, v_c0);
                          if (v_c41 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c41) return;
                          u64 v_c42 = _prim_bxor(db, v_c8, v_c9);
                          if (v_c42 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (v_c14 != v_c42) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c13, v_c2, v_c10, v_c11});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c2, v_c10, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask283* _cont = new ReadTask283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask283(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mp_union __t2OJC49 l __t499t48) (body (exists mp_union (2 0 1) 1 __t499t48) (exists mbranch (3 0 1 2 4) 1 l) (exists $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (join mp_union (2 0 1) 1 __t499t48 __t0mSQ44 __t39oH43) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t0mSQ44 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t0mSQ44 l) (join mbranch (3 0 1 2 4) 2 l __t39oH43 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t0mSQ44) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t0mSQ44 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t499t48) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t0mSQ44 n q u v __t0xN947) (join mbranch (1 2 3 4 0) 5 q n u v __t499t48) (join mp_msk (1 2 0) 3 q m __t0xN947) (join mp_msk_ans (0 1) 2 __t0xN947 p) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask347 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex328;  slog::Index** mbranchindex329;  slog::Index** $sup5638x95x0x0x0index330;  slog::Index** $sup5638x95x0x0x1index331;  slog::Index** mp_union_ansindex332;  slog::Index** mp_unionindex333;  slog::Index** $sup5638x95x0x0x0index334;  slog::Index** $sup5638x95x0x0x1index335;  slog::Index** mbranchindex336;  slog::Index** $sup5638x95x0x0x1index337;  slog::Index** mp_mskindex338;  slog::Index** mp_msk_ansindex339;  slog::Index** $sup5638x95x0x0x0index340;  slog::Index** mbranchindex341;  slog::Index** mp_mskindex342;  slog::Index** $sup5638x95x0x0x1index343;  slog::Index** mbranchindex344;  slog::Index** mp_mskindex345;  slog::Index** mp_msk_ansindex346;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord348({2, 0, 1});
      slog::Relation* readrel349 = db->getRelation("mp_union");
      mp_unionindex328 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({3, 0, 1, 2, 4});
      slog::Relation* readrel351 = db->getRelation("mbranch");
      mbranchindex329 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel353 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index330 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel355 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index331 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("mp_union_ans");
      mp_union_ansindex332 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({2, 0, 1});
      slog::Relation* readrel359 = db->getRelation("mp_union");
      mp_unionindex333 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel361 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index334 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel363 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index335 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({3, 0, 1, 2, 4});
      slog::Relation* readrel365 = db->getRelation("mbranch");
      mbranchindex336 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel367 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index337 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({2, 0, 1});
      slog::Relation* readrel369 = db->getRelation("mp_msk");
      mp_mskindex338 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 0});
      slog::Relation* readrel371 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex339 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel373 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index340 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 3, 4, 0});
      slog::Relation* readrel375 = db->getRelation("mbranch");
      mbranchindex341 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("mp_msk");
      mp_mskindex342 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel379 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index343 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 3, 4, 0});
      slog::Relation* readrel381 = db->getRelation("mbranch");
      mbranchindex344 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("mp_msk");
      mp_mskindex345 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex346 = readrel385->getIndex(ord384, false);
  
    }
    ReadTask347(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex328, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex329, std::array<u64,5>{v_c18, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index330, std::array<u64,9>{v_c18, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index331, std::array<u64,10>{v_c18, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex332, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m386) {
          u64 v_c4 = m386[1];
          slog::join_probe<3,1>(mp_unionindex333, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m387) {
            u64 v_c46 = m387[1]; u64 v_c47 = m387[2];
            if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index334, std::array<u64,9>{v_c46, v_c18, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index335, std::array<u64,10>{v_c46, v_c18, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex336, std::array<u64,5>{v_c18, v_c47, 0, 0, 0}, [&](const std::array<u64,5>& m388) {
              u64 v_c21 = m388[2]; u64 v_c19 = m388[3]; u64 v_c23 = m388[4];
              if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index337, std::array<u64,10>{v_c18, v_c19, v_c21, v_c23, v_c46, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex338, std::array<u64,3>{v_c19, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex339, std::array<u64,2>{v_c21, 0})) return;
              slog::join_probe<9,5>($sup5638x95x0x0x0index340, std::array<u64,9>{v_c18, v_c19, v_c21, v_c23, v_c46, 0, 0, 0, 0}, [&](const std::array<u64,9>& m389) {
                u64 v_c20 = m389[5]; u64 v_c22 = m389[6]; u64 v_c24 = m389[7]; u64 v_c25 = m389[8];
                u64 v_c48 = _prim_lt(db, v_c20, v_c19);
                if (v_c48 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                if (!v_c48) return;
                if (!slog::exists_probe<5,5>(mbranchindex341, std::array<u64,5>{v_c22, v_c20, v_c24, v_c25, v_c45})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex342, std::array<u64,3>{v_c22, v_c19, 0})) return;
                slog::join_probe<10,9>($sup5638x95x0x0x1index343, std::array<u64,10>{v_c18, v_c19, v_c21, v_c23, v_c46, v_c20, v_c22, v_c24, v_c25, 0}, [&](const std::array<u64,10>& m391) {
                  u64 v_c49 = m391[9];
                  slog::join_probe<5,5>(mbranchindex344, std::array<u64,5>{v_c22, v_c20, v_c24, v_c25, v_c45}, [&](const std::array<u64,5>& m392) {
                    slog::join_probe<3,3>(mp_mskindex345, std::array<u64,3>{v_c22, v_c19, v_c49}, [&](const std::array<u64,3>& m393) {
                      slog::join_probe<2,2>(mp_msk_ansindex346, std::array<u64,2>{v_c49, v_c21}, [&](const std::array<u64,2>& m394) {
                        u64 v_c50 = _prim_band(db, v_c22, v_c19);
                        if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c51 = _prim_lt(db, v_c50, v_c43);
                        if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c51) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c46, v_c4, v_c19, v_c21, v_c23});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c19, v_c4, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask347* _cont = new ReadTask347(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask347(db,b), false);
  // (crule (pre (let __tconst1DnK387 const6b86b273ff34fce19d6b804e)) (scan mp_hsb __t5Ake386 __t1scf385) (body (join mp_hsb_ans (0 1) 1 __t5Ake386 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t9zeu388 (band p0 __v0)) (cmp lt __t9zeu388 __tconst1DnK387) (let chk0IwW1071 (bxor p0 p1)) (eq __t1scf385 chk0IwW1071)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t5Ake386 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask398 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex396;  slog::Index** $sup5638x25x0x0x0index397;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord399({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel400 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel400->getIndex(ord399, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex396 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 0, 2, 3, 4});
      slog::Relation* readrel404 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index397 = readrel404->getIndex(ord403, false);
  
    }
    ReadTask398(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex396, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m405) {
          u64 v_c4 = m405[1];
          slog::join_all<5>($sup5638x25x0x0x0index397, [&](const std::array<u64,5>& m406) {
            u64 v_c8 = m406[0]; u64 v_c17 = m406[1]; u64 v_c9 = m406[2]; u64 v_c10 = m406[3]; u64 v_c11 = m406[4];
            u64 v_c55 = _prim_band(db, v_c8, v_c4);
            if (v_c55 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c56 = _prim_lt(db, v_c55, v_c52);
            if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c56) return;
            u64 v_c57 = _prim_bxor(db, v_c8, v_c9);
            if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (v_c54 != v_c57) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c53, v_c4, v_c17, v_c8, v_c9, v_c10, v_c11}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask398* _cont = new ReadTask398(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask398(db,b), false);
  // (crule (pre (let __tconst7QaM371 const6b86b273ff34fce19d6b804e) (let __tconst9R3I370 const8c1f1046219ddd216a023f79)) (scan canon m) (body) (head (mkstruct mp_put (1 2 3 0) __0KyY646 m __tconst7QaM371 __tconst9R3I370)) mp_basic.slog:22 #f)
  class ReadTask408 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask408(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const8c1f1046219ddd216a023f79;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        ++_fires;
        slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c19, v_c58, v_c59}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:22", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask408* _cont = new ReadTask408(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask408(db,b), false);
  // (crule (pre (let __trid94SO778 const1ca60a80dbae6414bef23d65) (let __trel5S04779 consta24220c5193376967f1fa95e) (let __tcol7hK9780 const5feceb66ffc86f38d952786c) (let __trel05kX781 consta24220c5193376967f1fa95e) (let __tcol0DbG782 constd4735e3a265e16eee03f5971) (let __trel5135783 consta24220c5193376967f1fa95e) (let __tcol58RB784 const4e07408562bedb8b60ce05c1) (let __trel4vgw785 const76237108756d80d8c9f21f56) (let __tcol1c3H786 const5feceb66ffc86f38d952786c)) (scan $sup5638x44x0x0x0 __d0 k l m p r t v) (body) (head (tycheck k (accept int) __trid94SO778 __trel5S04779 __tcol7hK9780 (1 2 3 4 0)) (tycheck p (accept int) __trid94SO778 __trel05kX781 __tcol0DbG782 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid94SO778 __trel5135783 __tcol58RB784 (1 2 3 4 0)) (tycheck k (accept int) __trid94SO778 __trel4vgw785 __tcol1c3H786 (1 2 3 4 0)) (emit-temp temp8y4n1085 k p t v) (mkstruct mleaf (1 2 0) __t8W6m138 k v)) map.slog:45 #f)
  class ReadTask412 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid410;  u32 sid409;  u32 sid411;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("temp8y4n1085");
      head_rel[5] = db->getRelation("mleaf");
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
      sid410 = db->getRelation("_enum")->getStructId();
      sid409 = db->getRelation("mbranch")->getStructId();
      sid411 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask412(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const1ca60a80dbae6414bef23d65;
      u64 v_c61 = v_consta24220c5193376967f1fa95e;
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
      u64 v_c63 = v_consta24220c5193376967f1fa95e;
      u64 v_c64 = v_constd4735e3a265e16eee03f5971;
      u64 v_c65 = v_consta24220c5193376967f1fa95e;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_const76237108756d80d8c9f21f56;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c17 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c19 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c23 = _t[5];
        u64 v_c70 = _t[6];
        u64 v_c25 = _t[7];
        ++_fires;
        if (!(is_int(v_c69)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c60, v_c61, v_c62, v_c69}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c21)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c60, v_c63, v_c64, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c70) && (decode_struct_id(v_c70) == sid409 || decode_struct_id(v_c70) == sid410 || decode_struct_id(v_c70) == sid411))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c60, v_c65, v_c66, v_c70}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c69)))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c60, v_c67, v_c68, v_c69}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<4>(head_rel[4], newbatch[4], std::array<u64,4>{v_c69, v_c21, v_c70, v_c25});
        slog::emit_struct<3>(head_rel[5], newbatch[5], std::array<u64,2>{v_c69, v_c25}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
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
  // (crule (pre (let __trid2sEh857 const07d7fbed0aba019c07f7eb8a) (let __trel14Rx858 const20347926ddb307a8e2bdb71b) (let __tcol5gMF859 const4e07408562bedb8b60ce05c1)) (scan mp_msk_ans __t7Ifn141 p) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t7Ifn141 k m) (exists mp_del (2 0 1) 1 k) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t13lF142) (join-old mp_del_ans (0 1) 1 (0 1) __t13lF142 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2sEh857 __trel14Rx858 __tcol5gMF859 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __3uQ5856 p m __v0 r)) map.slog:83 #f)
  class ReadTask425 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index413;  slog::Index** mp_mskindex414;  slog::Index** mp_delindex415;  slog::Index** $sup5638x82x0x0x0index416;  slog::Index** mp_delindex417;  slog::Index** mp_del_ansindex418;  slog::Index** mp_mskdelta419;  slog::Index** mp_deldelta420;  slog::Index** mp_del_ansdelta421;
    u32 sid423;  u32 sid422;  u32 sid424;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord426({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel427 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index413 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 1, 2});
      slog::Relation* readrel429 = db->getRelation("mp_msk");
      mp_mskindex414 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1, 2});
      slog::Relation* readrel431 = db->getRelation("mp_msk");
      mp_mskdelta419 = readrel431->getIndex(ord430, true);
      std::vector<u16> ord432({2, 0, 1});
      slog::Relation* readrel433 = db->getRelation("mp_del");
      mp_delindex415 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel435 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index416 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("mp_del");
      mp_delindex417 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("mp_del");
      mp_deldelta420 = readrel439->getIndex(ord438, true);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("mp_del_ans");
      mp_del_ansindex418 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({0, 1});
      slog::Relation* readrel443 = db->getRelation("mp_del_ans");
      mp_del_ansdelta421 = readrel443->getIndex(ord442, true);
      sid423 = db->getRelation("_enum")->getStructId();
      sid422 = db->getRelation("mbranch")->getStructId();
      sid424 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask425(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c72 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c73 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x82x0x0x0index413, std::array<u64,6>{v_c21, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex414, mp_mskdelta419, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m444) {
          u64 v_c69 = m444[1]; u64 v_c19 = m444[2];
          if (!slog::exists_probe<3,1>(mp_delindex415, std::array<u64,3>{v_c69, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x82x0x0x0index416, std::array<u64,6>{v_c69, v_c19, v_c21, 0, 0, 0}, [&](const std::array<u64,6>& m445) {
            u64 v_c17 = m445[3]; u64 v_c18 = m445[4]; u64 v_c23 = m445[5];
            slog::join_probe_old<3,2>(mp_delindex417, mp_deldelta420, std::array<u64,3>{v_c18, v_c69, 0}, [&](const std::array<u64,3>& m446) {
              u64 v_c75 = m446[2];
              slog::join_probe_old<2,1>(mp_del_ansindex418, mp_del_ansdelta421, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m447) {
                u64 v_c4 = m447[1];
                ++_fires;
                if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid422 || decode_struct_id(v_c23) == sid423 || decode_struct_id(v_c23) == sid424))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c71, v_c72, v_c73, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c19, v_c4, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask425* _cont = new ReadTask425(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask425(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mbranch __t032L110 p m l r) (body (exists mp_has0 (1 2 0) 1 __t032L110) (exists mp_has0 (1 2 0) 1 r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x62x0x0x0 (4 2 3 5 0 1) 4 p l m r __t68rk111 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t68rk111 k __t032L110) (exists mp_msk (1 2 0) 2 k m) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t6Hok114) (exists mp_has0_ans (0 1) 1 __t6Hok114) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9QiO115) (join mp_msk_ans (0 1) 2 __t9QiO115 p) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask463 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index448;  slog::Index** mp_has0index449;  slog::Index** mp_mskindex450;  slog::Index** mp_msk_ansindex451;  slog::Index** $sup5638x62x0x0x0index452;  slog::Index** mp_has0index453;  slog::Index** mp_mskindex454;  slog::Index** mp_has0index455;  slog::Index** mp_has0_ansindex456;  slog::Index** mp_mskindex457;  slog::Index** mp_msk_ansindex458;  slog::Index** mp_has0_ansindex459;  slog::Index** mp_has0delta460;  slog::Index** mp_has0delta461;  slog::Index** mp_mskdelta462;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel465->getIndex(ord464, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("mp_has0");
      mp_has0index448 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("mp_has0");
      mp_has0index449 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({2, 0, 1});
      slog::Relation* readrel471 = db->getRelation("mp_msk");
      mp_mskindex450 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex451 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel475 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index452 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({0, 2, 1});
      slog::Relation* readrel477 = db->getRelation("mp_has0");
      mp_has0index453 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({0, 2, 1});
      slog::Relation* readrel479 = db->getRelation("mp_has0");
      mp_has0delta460 = readrel479->getIndex(ord478, true);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("mp_msk");
      mp_mskindex454 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("mp_has0");
      mp_has0index455 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 0});
      slog::Relation* readrel485 = db->getRelation("mp_has0");
      mp_has0delta461 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex456 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("mp_msk");
      mp_mskindex457 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("mp_msk");
      mp_mskdelta462 = readrel491->getIndex(ord490, true);
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex458 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex459 = readrel495->getIndex(ord494, false);
  
    }
    ReadTask463(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c23 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index448, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index449, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex450, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex451, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<6,4>($sup5638x62x0x0x0index452, std::array<u64,6>{v_c21, v_c18, v_c19, v_c23, 0, 0}, [&](const std::array<u64,6>& m496) {
          u64 v_c78 = m496[4]; u64 v_c69 = m496[5];
          slog::join_probe_old<3,3>(mp_has0index453, mp_has0delta460, std::array<u64,3>{v_c78, v_c69, v_c77}, [&](const std::array<u64,3>& m497) {
            if (!slog::exists_probe<3,2>(mp_mskindex454, std::array<u64,3>{v_c69, v_c19, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index455, mp_has0delta461, std::array<u64,3>{v_c23, v_c69, 0}, [&](const std::array<u64,3>& m498) {
              u64 v_c79 = m498[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex456, std::array<u64,2>{v_c79, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex457, mp_mskdelta462, std::array<u64,3>{v_c69, v_c19, 0}, [&](const std::array<u64,3>& m499) {
                u64 v_c80 = m499[2];
                slog::join_probe<2,2>(mp_msk_ansindex458, std::array<u64,2>{v_c80, v_c21}, [&](const std::array<u64,2>& m500) {
                  slog::join_probe<2,1>(mp_has0_ansindex459, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m501) {
                    u64 v_c81 = m501[1];
                    u64 v_c82 = _prim_band(db, v_c69, v_c19);
                    if (v_c82 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c83 = _prim_gt(db, v_c82, v_c76);
                    if (v_c83 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c83) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c78, v_c81}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask463* _cont = new ReadTask463(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask463(db,b), false);
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mp_union_ans __t109M109 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t109M109 __t6XhK108 u) (exists mbranch (3 0 1 2 4) 1 u) (exists $sup5638x104x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join-old mp_union (1 2 0) 1 (1 2 0) __t6XhK108 __t9OKP102 __t38nk104) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t38nk104 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t38nk104 u) (join-old mbranch (3 0 1 2 4) 2 (3 0 1 2 4) u __t9OKP102 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t38nk104) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join-old $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t38nk104 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6XhK108) (exists mp_msk (1 2 0) 2 p n) (join-old $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t38nk104 l m p r __t3jH2107) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6XhK108) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask528 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex503;  slog::Index** mbranchindex504;  slog::Index** $sup5638x104x0x0x0index505;  slog::Index** $sup5638x104x0x0x1index506;  slog::Index** mp_unionindex507;  slog::Index** $sup5638x104x0x0x0index508;  slog::Index** $sup5638x104x0x0x1index509;  slog::Index** mbranchindex510;  slog::Index** $sup5638x104x0x0x1index511;  slog::Index** mp_mskindex512;  slog::Index** mp_msk_ansindex513;  slog::Index** $sup5638x104x0x0x0index514;  slog::Index** mbranchindex515;  slog::Index** mp_mskindex516;  slog::Index** $sup5638x104x0x0x1index517;  slog::Index** mbranchindex518;  slog::Index** mp_mskindex519;  slog::Index** mp_msk_ansindex520;  slog::Index** mp_uniondelta521;  slog::Index** mp_uniondelta522;  slog::Index** mbranchdelta523;  slog::Index** $sup5638x104x0x0x0delta524;  slog::Index** $sup5638x104x0x0x1delta525;  slog::Index** mbranchdelta526;  slog::Index** mp_mskdelta527;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord529({0, 1, 2});
      slog::Relation* readrel530 = db->getRelation("mp_union");
      mp_unionindex503 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1, 2});
      slog::Relation* readrel532 = db->getRelation("mp_union");
      mp_uniondelta521 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({3, 0, 1, 2, 4});
      slog::Relation* readrel534 = db->getRelation("mbranch");
      mbranchindex504 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel536 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index505 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel538 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index506 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("mp_union");
      mp_unionindex507 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 0});
      slog::Relation* readrel542 = db->getRelation("mp_union");
      mp_uniondelta522 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel544 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index508 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel546 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index509 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({3, 0, 1, 2, 4});
      slog::Relation* readrel548 = db->getRelation("mbranch");
      mbranchindex510 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({3, 0, 1, 2, 4});
      slog::Relation* readrel550 = db->getRelation("mbranch");
      mbranchdelta523 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel552 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index511 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({2, 0, 1});
      slog::Relation* readrel554 = db->getRelation("mp_msk");
      mp_mskindex512 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 0});
      slog::Relation* readrel556 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex513 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel558 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index514 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel560 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0delta524 = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({1, 2, 3, 4, 0});
      slog::Relation* readrel562 = db->getRelation("mbranch");
      mbranchindex515 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 0});
      slog::Relation* readrel564 = db->getRelation("mp_msk");
      mp_mskindex516 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel566 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index517 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel568 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta525 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({1, 2, 3, 4, 0});
      slog::Relation* readrel570 = db->getRelation("mbranch");
      mbranchindex518 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("mbranch");
      mbranchdelta526 = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("mp_msk");
      mp_mskindex519 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("mp_msk");
      mp_mskdelta527 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex520 = readrel578->getIndex(ord577, false);
  
    }
    ReadTask528(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c85 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex503, mp_uniondelta521, std::array<u64,3>{v_c85, 0, 0}, [&](const std::array<u64,3>& m579) {
          u64 v_c86 = m579[1]; u64 v_c24 = m579[2];
          if (!slog::exists_probe<5,1>(mbranchindex504, std::array<u64,5>{v_c24, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index505, std::array<u64,9>{v_c24, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index506, std::array<u64,10>{v_c24, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex507, mp_uniondelta522, std::array<u64,3>{v_c86, 0, 0}, [&](const std::array<u64,3>& m580) {
            u64 v_c87 = m580[1]; u64 v_c88 = m580[2];
            if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index508, std::array<u64,9>{v_c88, v_c24, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index509, std::array<u64,10>{v_c88, v_c24, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex510, mbranchdelta523, std::array<u64,5>{v_c24, v_c87, 0, 0, 0}, [&](const std::array<u64,5>& m581) {
              u64 v_c22 = m581[2]; u64 v_c20 = m581[3]; u64 v_c25 = m581[4];
              if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index511, std::array<u64,10>{v_c24, v_c20, v_c22, v_c25, v_c88, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex512, std::array<u64,3>{v_c20, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex513, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe_old<9,5>($sup5638x104x0x0x0index514, $sup5638x104x0x0x0delta524, std::array<u64,9>{v_c22, v_c20, v_c24, v_c25, v_c88, 0, 0, 0, 0}, [&](const std::array<u64,9>& m582) {
                u64 v_c18 = m582[5]; u64 v_c19 = m582[6]; u64 v_c21 = m582[7]; u64 v_c23 = m582[8];
                u64 v_c89 = _prim_lt(db, v_c19, v_c20);
                if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                if (!v_c89) return;
                if (!slog::exists_probe<5,5>(mbranchindex515, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c86})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex516, std::array<u64,3>{v_c21, v_c20, 0})) return;
                slog::join_probe_old<10,9>($sup5638x104x0x0x1index517, $sup5638x104x0x0x1delta525, std::array<u64,10>{v_c24, v_c20, v_c22, v_c25, v_c88, v_c18, v_c19, v_c21, v_c23, 0}, [&](const std::array<u64,10>& m584) {
                  u64 v_c90 = m584[9];
                  slog::join_probe_old<5,5>(mbranchindex518, mbranchdelta526, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c86}, [&](const std::array<u64,5>& m585) {
                    slog::join_probe_old<3,3>(mp_mskindex519, mp_mskdelta527, std::array<u64,3>{v_c21, v_c20, v_c90}, [&](const std::array<u64,3>& m586) {
                      slog::join_probe<2,2>(mp_msk_ansindex520, std::array<u64,2>{v_c90, v_c22}, [&](const std::array<u64,2>& m587) {
                        u64 v_c91 = _prim_band(db, v_c21, v_c20);
                        if (v_c91 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c92 = _prim_lt(db, v_c91, v_c84);
                        if (v_c92 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c92) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c88, v_c4, v_c20, v_c22, v_c25});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c20, v_c4, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask528* _cont = new ReadTask528(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask528(db,b), false);
  // (crule (pre (let __tconst2Aaf422 constef2d127de37b942baad06145)) (scan canon m) (body) (head (mkstruct mp_has0 (1 2 0) __8iey609 m __tconst2Aaf422)) mp_basic.slog:19 #f)
  class ReadTask589 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask589(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c19, v_c93}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:19", "delta:canon", _fires);
  
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
  // (crule (pre) (scan $sup5638x110x0x0x0 __t5xrH216 l m n p q r __t0o62217 __t0BoC218 u v) (body (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0o62217) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0BoC218) (exists mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t0o62217 q __t0BoC218 __t7HEI219) (join-old mp_union (0 1 2) 3 (0 1 2) __t5xrH216 __t0o62217 __t0BoC218) (exists mp_join_ans (0 1) 1 __t7HEI219) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask605 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex590;  slog::Index** mbranchindex591;  slog::Index** mp_unionindex592;  slog::Index** mp_mskindex593;  slog::Index** mp_joinindex594;  slog::Index** mp_unionindex595;  slog::Index** mp_join_ansindex596;  slog::Index** mp_mskindex597;  slog::Index** mp_msk_ansindex598;  slog::Index** mp_join_ansindex599;  slog::Index** mbranchdelta600;  slog::Index** mbranchdelta601;  slog::Index** mp_joindelta602;  slog::Index** mp_uniondelta603;  slog::Index** mp_mskdelta604;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord606({0, 1});
      slog::Relation* readrel607 = db->getRelation("mp_union_ans");
      head_index[0] = readrel607->getIndex(ord606, false);
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord608({1, 2, 3, 4, 0});
      slog::Relation* readrel609 = db->getRelation("mbranch");
      mbranchindex590 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 3, 4, 0});
      slog::Relation* readrel611 = db->getRelation("mbranch");
      mbranchdelta600 = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({1, 2, 3, 4, 0});
      slog::Relation* readrel613 = db->getRelation("mbranch");
      mbranchindex591 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 2, 3, 4, 0});
      slog::Relation* readrel615 = db->getRelation("mbranch");
      mbranchdelta601 = readrel615->getIndex(ord614, true);
      std::vector<u16> ord616({0, 1, 2});
      slog::Relation* readrel617 = db->getRelation("mp_union");
      mp_unionindex592 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 2, 0});
      slog::Relation* readrel619 = db->getRelation("mp_msk");
      mp_mskindex593 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 3, 4, 0});
      slog::Relation* readrel621 = db->getRelation("mp_join");
      mp_joinindex594 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 3, 4, 0});
      slog::Relation* readrel623 = db->getRelation("mp_join");
      mp_joindelta602 = readrel623->getIndex(ord622, true);
      std::vector<u16> ord624({0, 1, 2});
      slog::Relation* readrel625 = db->getRelation("mp_union");
      mp_unionindex595 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({0, 1, 2});
      slog::Relation* readrel627 = db->getRelation("mp_union");
      mp_uniondelta603 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({0, 1});
      slog::Relation* readrel629 = db->getRelation("mp_join_ans");
      mp_join_ansindex596 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("mp_msk");
      mp_mskindex597 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("mp_msk");
      mp_mskdelta604 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex598 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({0, 1});
      slog::Relation* readrel637 = db->getRelation("mp_join_ans");
      mp_join_ansindex599 = readrel637->getIndex(ord636, false);
  
    }
    ReadTask605(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c94 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c20 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c23 = _t[6];
        u64 v_c95 = _t[7];
        u64 v_c96 = _t[8];
        u64 v_c24 = _t[9];
        u64 v_c25 = _t[10];
        u64 v_c97 = _prim_lt(db, v_c19, v_c20);
        if (v_c97 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
        if (!v_c97) return;
        slog::join_probe_old<5,5>(mbranchindex590, mbranchdelta600, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, v_c95}, [&](const std::array<u64,5>& m639) {
          slog::join_probe_old<5,5>(mbranchindex591, mbranchdelta601, std::array<u64,5>{v_c22, v_c20, v_c24, v_c25, v_c96}, [&](const std::array<u64,5>& m640) {
            if (!slog::exists_probe<3,3>(mp_unionindex592, std::array<u64,3>{v_c94, v_c95, v_c96})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex593, std::array<u64,3>{v_c21, v_c20, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex594, mp_joindelta602, std::array<u64,5>{v_c21, v_c95, v_c22, v_c96, 0}, [&](const std::array<u64,5>& m641) {
              u64 v_c98 = m641[4];
              slog::join_probe_old<3,3>(mp_unionindex595, mp_uniondelta603, std::array<u64,3>{v_c94, v_c95, v_c96}, [&](const std::array<u64,3>& m642) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex596, std::array<u64,2>{v_c98, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex597, mp_mskdelta604, std::array<u64,3>{v_c21, v_c20, 0}, [&](const std::array<u64,3>& m643) {
                  u64 v_c99 = m643[2];
                  slog::join_probe<2,1>(mp_msk_ansindex598, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m644) {
                    u64 v_c4 = m644[1];
                    if (v_c22 == v_c4) return;
                    slog::join_probe<2,1>(mp_join_ansindex599, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m645) {
                      u64 v_c100 = m645[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c94, v_c100}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:$sup5638x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask605* _cont = new ReadTask605(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask605(db,b), false);
  // (crule (pre) (scan mbranch __t6Pc120 q m u v) (body (exists mbranch (2 0 1 3 4) 1 m) (exists mp_union (2 0 1) 1 __t6Pc120) (join-old mp_join (3 4 1 0 2) 2 (3 4 1 0 2) q __t6Pc120 p __t2ANq21 __t50JB19) (neq p q) (exists mp_union (1 2 0) 2 __t50JB19 __t6Pc120) (exists mp_join_ans (0 1) 1 __t2ANq21) (join mbranch (0 1 2 3 4) 3 __t50JB19 p m l r) (join mp_union (1 2 0) 2 __t50JB19 __t6Pc120 __t9xCI18) (join mp_join_ans (0 1) 1 __t2ANq21 res)) (head (emit mp_union_ans (0 1) __t9xCI18 res)) map.slog:114 #f)
  class ReadTask655 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex646;  slog::Index** mp_unionindex647;  slog::Index** mp_joinindex648;  slog::Index** mp_unionindex649;  slog::Index** mp_join_ansindex650;  slog::Index** mbranchindex651;  slog::Index** mp_unionindex652;  slog::Index** mp_join_ansindex653;  slog::Index** mp_joindelta654;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("mp_union_ans");
      head_index[0] = readrel657->getIndex(ord656, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord658({2, 0, 1, 3, 4});
      slog::Relation* readrel659 = db->getRelation("mbranch");
      mbranchindex646 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({2, 0, 1});
      slog::Relation* readrel661 = db->getRelation("mp_union");
      mp_unionindex647 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({3, 4, 1, 0, 2});
      slog::Relation* readrel663 = db->getRelation("mp_join");
      mp_joinindex648 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({3, 4, 1, 0, 2});
      slog::Relation* readrel665 = db->getRelation("mp_join");
      mp_joindelta654 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("mp_union");
      mp_unionindex649 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("mp_join_ans");
      mp_join_ansindex650 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({0, 1, 2, 3, 4});
      slog::Relation* readrel671 = db->getRelation("mbranch");
      mbranchindex651 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("mp_union");
      mp_unionindex652 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1});
      slog::Relation* readrel675 = db->getRelation("mp_join_ans");
      mp_join_ansindex653 = readrel675->getIndex(ord674, false);
  
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
        u64 v_c101 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex646, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex647, std::array<u64,3>{v_c101, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex648, mp_joindelta654, std::array<u64,5>{v_c22, v_c101, 0, 0, 0}, [&](const std::array<u64,5>& m676) {
          u64 v_c21 = m676[2]; u64 v_c102 = m676[3]; u64 v_c103 = m676[4];
          if (v_c21 == v_c22) return;
          if (!slog::exists_probe<3,2>(mp_unionindex649, std::array<u64,3>{v_c103, v_c101, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex650, std::array<u64,2>{v_c102, 0})) return;
          slog::join_probe<5,3>(mbranchindex651, std::array<u64,5>{v_c103, v_c21, v_c19, 0, 0}, [&](const std::array<u64,5>& m677) {
            u64 v_c18 = m677[3]; u64 v_c23 = m677[4];
            slog::join_probe<3,2>(mp_unionindex652, std::array<u64,3>{v_c103, v_c101, 0}, [&](const std::array<u64,3>& m678) {
              u64 v_c104 = m678[2];
              slog::join_probe<2,1>(mp_join_ansindex653, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m679) {
                u64 v_c100 = m679[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c100}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan $sup5638x81x0x0x0 __t9Sl6223 k l m p r) (body (exists mp_del (0 2 1) 2 __t9Sl6223 k) (exists mp_msk (1 2 0) 2 k m) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5VI4222) (join-old mp_del (0 2 1) 3 (0 2 1) __t9Sl6223 k __t5VI4222) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t3J75224) (join mp_msk_ans (0 1) 1 __t3J75224 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t9Sl6223 __t5VI4222)) map.slog:82 #f)
  class ReadTask689 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex680;  slog::Index** mp_mskindex681;  slog::Index** mbranchindex682;  slog::Index** mp_delindex683;  slog::Index** mp_mskindex684;  slog::Index** mp_msk_ansindex685;  slog::Index** mbranchdelta686;  slog::Index** mp_deldelta687;  slog::Index** mp_mskdelta688;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord690({0, 1});
      slog::Relation* readrel691 = db->getRelation("mp_del_ans");
      head_index[0] = readrel691->getIndex(ord690, false);
      outer_rel = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord692({0, 2, 1});
      slog::Relation* readrel693 = db->getRelation("mp_del");
      mp_delindex680 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("mp_msk");
      mp_mskindex681 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 3, 4, 0});
      slog::Relation* readrel697 = db->getRelation("mbranch");
      mbranchindex682 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 2, 3, 4, 0});
      slog::Relation* readrel699 = db->getRelation("mbranch");
      mbranchdelta686 = readrel699->getIndex(ord698, true);
      std::vector<u16> ord700({0, 2, 1});
      slog::Relation* readrel701 = db->getRelation("mp_del");
      mp_delindex683 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 2, 1});
      slog::Relation* readrel703 = db->getRelation("mp_del");
      mp_deldelta687 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("mp_msk");
      mp_mskindex684 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 0});
      slog::Relation* readrel707 = db->getRelation("mp_msk");
      mp_mskdelta688 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1});
      slog::Relation* readrel709 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex685 = readrel709->getIndex(ord708, false);
  
    }
    ReadTask689(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c19 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c23 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex680, std::array<u64,3>{v_c105, v_c69, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex681, std::array<u64,3>{v_c69, v_c19, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex682, mbranchdelta686, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, 0}, [&](const std::array<u64,5>& m710) {
          u64 v_c106 = m710[4];
          slog::join_probe_old<3,3>(mp_delindex683, mp_deldelta687, std::array<u64,3>{v_c105, v_c69, v_c106}, [&](const std::array<u64,3>& m711) {
            slog::join_probe_old<3,2>(mp_mskindex684, mp_mskdelta688, std::array<u64,3>{v_c69, v_c19, 0}, [&](const std::array<u64,3>& m712) {
              u64 v_c107 = m712[2];
              slog::join_probe<2,1>(mp_msk_ansindex685, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m713) {
                u64 v_c4 = m713[1];
                if (v_c21 == v_c4) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c106}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:$sup5638x81x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask689* _cont = new ReadTask689(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask689(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t8mLF130 __v3) (body (join-old mp_hsb_ans (0 1) 1 (0 1) __t8mLF130 __v1) (join-old mp_hsb (0 1) 1 (0 1) __t8mLF130 __t8nJr131) (join-old $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk9XCP1017 (bxor p0 p1)) (eq __t8nJr131 chk9XCP1017)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t8mLF130 __t8mLF130 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask720 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex714;  slog::Index** mp_hsbindex715;  slog::Index** $sup5638x29x0x0x1index716;  slog::Index** mp_hsb_ansdelta717;  slog::Index** mp_hsbdelta718;  slog::Index** $sup5638x29x0x0x1delta719;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord721({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel722 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel722->getIndex(ord721, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord723({0, 1});
      slog::Relation* readrel724 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex714 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({0, 1});
      slog::Relation* readrel726 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta717 = readrel726->getIndex(ord725, true);
      std::vector<u16> ord727({0, 1});
      slog::Relation* readrel728 = db->getRelation("mp_hsb");
      mp_hsbindex715 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({0, 1});
      slog::Relation* readrel730 = db->getRelation("mp_hsb");
      mp_hsbdelta718 = readrel730->getIndex(ord729, true);
      std::vector<u16> ord731({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel732 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index716 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel734 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta719 = readrel734->getIndex(ord733, true);
  
    }
    ReadTask720(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        slog::join_probe_old<2,1>(mp_hsb_ansindex714, mp_hsb_ansdelta717, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m735) {
          u64 v_c3 = m735[1];
          slog::join_probe_old<2,1>(mp_hsbindex715, mp_hsbdelta718, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m736) {
            u64 v_c109 = m736[1];
            slog::join_all_old<7>($sup5638x29x0x0x1index716, $sup5638x29x0x0x1delta719, [&](const std::array<u64,7>& m737) {
              u64 v_c36 = m737[0]; u64 v_c4 = m737[1]; u64 v_c17 = m737[2]; u64 v_c8 = m737[3]; u64 v_c9 = m737[4]; u64 v_c10 = m737[5]; u64 v_c11 = m737[6];
              u64 v_c110 = _prim_bxor(db, v_c8, v_c9);
              if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c109 != v_c110) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c36, v_c4, v_c2, v_c3, v_c17, v_c108, v_c108, v_c8, v_c9, v_c10, v_c11}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask720* _cont = new ReadTask720(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask720(db,b), false);
  // (crule (pre) (scan temp4Eqs1025 __t09AU334 __t0sIx339 k) (body (let __t3why337 (_0002f k __t09AU334))) (head (emit-temp temp2mZ61026 __t09AU334 __t0sIx339 __t3why337)) map.slog:22 #f)
  class ReadTask738 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2mZ61026");
      outer_rel = db->getRelation("temp4Eqs1025");
  
    }
    ReadTask738(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c111 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c69 = _t[2];
        u64 v_c113 = _prim__0002f(db, v_c69, v_c111);
        if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c111, v_c112, v_c113});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp4Eqs1025", _fires);
  
      if (!_done)
      {
        ReadTask738* _cont = new ReadTask738(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask738(db,b), false);
  // (crule (pre (let __trid26eb598 const07d7fbed0aba019c07f7eb8a) (let __trel1FpG599 constdd7bbf31ce5f578b9805e840) (let __tcol6duS600 const5feceb66ffc86f38d952786c) (let __trel7XCe601 constdd7bbf31ce5f578b9805e840) (let __tcol8IMf602 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid26eb598 __trel1FpG599 __tcol6duS600 (1 2 3 4 0)) (tycheck m (accept int) __trid26eb598 __trel7XCe601 __tcol8IMf602 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __0NXb597 k m)) map.slog:83 #f)
  class ReadTask739 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
  
    }
    ReadTask739(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c115 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
      u64 v_c117 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c118 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c17 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c19 = _t[3];
        u64 v_c21 = _t[4];
        u64 v_c23 = _t[5];
        ++_fires;
        if (!(is_int(v_c69)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c114, v_c115, v_c116, v_c69}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c19)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c114, v_c117, v_c118, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c69, v_c19}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask739* _cont = new ReadTask739(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask739(db,b), false);
  // (crule (pre (let __tconst0eZn112 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t9QiO115 p) (body (exists $sup5638x62x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t9QiO115 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x62x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t68rk111 l r) (exists mp_has0 (0 2 1) 2 __t68rk111 k) (exists mp_has0 (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t032L110) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t68rk111 k __t032L110) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t6Hok114) (join mp_has0_ans (0 1) 1 __t6Hok114 a) (let __t0AA7113 (band k m)) (cmp gt __t0AA7113 __tconst0eZn112)) (head (emit mp_has0_ans (0 1) __t68rk111 a)) map.slog:63 #f)
  class ReadTask757 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index740;  slog::Index** mbranchindex741;  slog::Index** mp_mskindex742;  slog::Index** mbranchindex743;  slog::Index** mp_has0index744;  slog::Index** $sup5638x62x0x0x0index745;  slog::Index** mp_has0index746;  slog::Index** mp_has0index747;  slog::Index** mbranchindex748;  slog::Index** mp_has0index749;  slog::Index** mp_has0index750;  slog::Index** mp_has0_ansindex751;  slog::Index** mp_mskdelta752;  slog::Index** $sup5638x62x0x0x0delta753;  slog::Index** mbranchdelta754;  slog::Index** mp_has0delta755;  slog::Index** mp_has0delta756;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord758({0, 1});
      slog::Relation* readrel759 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel759->getIndex(ord758, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord760({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel761 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index740 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 3, 4, 0});
      slog::Relation* readrel763 = db->getRelation("mbranch");
      mbranchindex741 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("mp_msk");
      mp_mskindex742 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("mp_msk");
      mp_mskdelta752 = readrel767->getIndex(ord766, true);
      std::vector<u16> ord768({1, 2, 3, 4, 0});
      slog::Relation* readrel769 = db->getRelation("mbranch");
      mbranchindex743 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("mp_has0");
      mp_has0index744 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel773 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index745 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel775 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0delta753 = readrel775->getIndex(ord774, true);
      std::vector<u16> ord776({0, 2, 1});
      slog::Relation* readrel777 = db->getRelation("mp_has0");
      mp_has0index746 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 0});
      slog::Relation* readrel779 = db->getRelation("mp_has0");
      mp_has0index747 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 3, 4, 0});
      slog::Relation* readrel781 = db->getRelation("mbranch");
      mbranchindex748 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 3, 4, 0});
      slog::Relation* readrel783 = db->getRelation("mbranch");
      mbranchdelta754 = readrel783->getIndex(ord782, true);
      std::vector<u16> ord784({0, 2, 1});
      slog::Relation* readrel785 = db->getRelation("mp_has0");
      mp_has0index749 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({0, 2, 1});
      slog::Relation* readrel787 = db->getRelation("mp_has0");
      mp_has0delta755 = readrel787->getIndex(ord786, true);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("mp_has0");
      mp_has0index750 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("mp_has0");
      mp_has0delta756 = readrel791->getIndex(ord790, true);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex751 = readrel793->getIndex(ord792, false);
  
    }
    ReadTask757(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x62x0x0x0index740, std::array<u64,6>{v_c21, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex741, std::array<u64,5>{v_c21, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex742, mp_mskdelta752, std::array<u64,3>{v_c80, 0, 0}, [&](const std::array<u64,3>& m794) {
          u64 v_c69 = m794[1]; u64 v_c19 = m794[2];
          if (!slog::exists_probe<5,2>(mbranchindex743, std::array<u64,5>{v_c21, v_c19, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index744, std::array<u64,3>{v_c69, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x62x0x0x0index745, $sup5638x62x0x0x0delta753, std::array<u64,6>{v_c69, v_c19, v_c21, 0, 0, 0}, [&](const std::array<u64,6>& m795) {
            u64 v_c78 = m795[3]; u64 v_c18 = m795[4]; u64 v_c23 = m795[5];
            if (!slog::exists_probe<3,2>(mp_has0index746, std::array<u64,3>{v_c78, v_c69, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index747, std::array<u64,3>{v_c23, v_c69, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex748, mbranchdelta754, std::array<u64,5>{v_c21, v_c19, v_c18, v_c23, 0}, [&](const std::array<u64,5>& m796) {
              u64 v_c77 = m796[4];
              slog::join_probe_old<3,3>(mp_has0index749, mp_has0delta755, std::array<u64,3>{v_c78, v_c69, v_c77}, [&](const std::array<u64,3>& m797) {
                slog::join_probe_old<3,2>(mp_has0index750, mp_has0delta756, std::array<u64,3>{v_c23, v_c69, 0}, [&](const std::array<u64,3>& m798) {
                  u64 v_c79 = m798[2];
                  slog::join_probe<2,1>(mp_has0_ansindex751, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m799) {
                    u64 v_c81 = m799[1];
                    u64 v_c82 = _prim_band(db, v_c69, v_c19);
                    if (v_c82 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c119 = _prim_gt(db, v_c82, v_c76);
                    if (v_c119 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c119) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c78, v_c81}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask757* _cont = new ReadTask757(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask757(db,b), false);
  // (crule (pre (let __tconst40sd335 constd4735e3a265e16eee03f5971)) (scan mp_msk __t0sIx339 k m) (body (let __t09AU334 (_0002a __tconst40sd335 m))) (head (emit-temp temp4Eqs1025 __t09AU334 __t0sIx339 k)) map.slog:22 #f)
  class ReadTask801 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4Eqs1025");
      outer_rel = db->getRelation("mp_msk");
  
    }
    ReadTask801(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c112 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c111 = _prim__0002a(db, v_c120, v_c19);
        if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c111, v_c112, v_c69});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask801* _cont = new ReadTask801(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask801(db,b), false);
  // (crule (pre) (scan toint_range __erre8EZm1001 __errf1ZpA1002 __errf5K831003) (body) (head (emit error (0) __erre8EZm1001)) <internal>:1 #f)
  class ReadTask802 : public slog::Task
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
      std::vector<u16> ord803({0});
      slog::Relation* readrel804 = db->getRelation("error");
      head_index[0] = readrel804->getIndex(ord803, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask802(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c122 = _t[1];
        u64 v_c123 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c121}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask802* _cont = new ReadTask802(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask802(db,b), false);
}

