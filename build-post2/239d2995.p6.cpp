
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const8c1f1046219ddd216a023f79;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_consteca796f75a14387c3a7674e7;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_cf1315b147c9a2b4b(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid56ua736 constfee494ff4827aeb0635bb714) (let __trel321s737 constdd7bbf31ce5f578b9805e840) (let __tcol1YQq738 const5feceb66ffc86f38d952786c) (let __trel58rz739 constdd7bbf31ce5f578b9805e840) (let __tcol22Dx740 const6b86b273ff34fce19d6b804e)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid56ua736 __trel321s737 __tcol1YQq738 (1 2 3 4 0)) (tycheck m (accept int) __trid56ua736 __trel58rz739 __tcol22Dx740 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __1KPU735 k m)) map.slog:85 #f)
  class ReadTask0 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constfee494ff4827aeb0635bb714;
      u64 v_c1 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_constdd7bbf31ce5f578b9805e840;
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
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c8)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c8}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre (let __tconst4Vak285 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t8lnB287 p) (body (exists $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) 2 __t8lnB287 p) (exists $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t8lnB287 k m) (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_put (2 3 0 1) 1 k) (join-old $sup5638x42x0x0x1 (1 2 4 5 0 3 6 7) 4 (1 2 4 5 0 3 6 7) __t8lnB287 k m p __t0ekw284 l r v) (join-old $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 (4 2 3 5 0 1 6) p l m r __t0ekw284 k v) (exists mp_put (2 3 0 1) 3 k v __t0ekw284) (exists mp_put (1 2 3 0) 3 r k v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t07OG283) (join-old mp_put (1 2 0 3) 4 (1 2 0 3) __t07OG283 k __t0ekw284 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t7iEH288) (join-old mp_put_ans (0 1) 1 (0 1) __t7iEH288 __v0) (let __t44Bo286 (band k m)) (cmp gt __t44Bo286 __tconst4Vak285)) (head (emit-temp temp5A4p1059 __t0ekw284 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t4v0n282 p m l __v0)) map.slog:43 #f)
  class ReadTask23 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index1;  slog::Index** $sup5638x42x0x0x0index2;  slog::Index** mbranchindex3;  slog::Index** mp_mskindex4;  slog::Index** $sup5638x42x0x0x0index5;  slog::Index** mbranchindex6;  slog::Index** mp_putindex7;  slog::Index** $sup5638x42x0x0x1index8;  slog::Index** $sup5638x42x0x0x0index9;  slog::Index** mp_putindex10;  slog::Index** mp_putindex11;  slog::Index** mbranchindex12;  slog::Index** mp_putindex13;  slog::Index** mp_putindex14;  slog::Index** mp_put_ansindex15;  slog::Index** mp_mskdelta16;  slog::Index** $sup5638x42x0x0x1delta17;  slog::Index** $sup5638x42x0x0x0delta18;  slog::Index** mbranchdelta19;  slog::Index** mp_putdelta20;  slog::Index** mp_putdelta21;  slog::Index** mp_put_ansdelta22;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5A4p1059");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord24({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel25 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel27 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index2 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 2, 3, 4, 0});
      slog::Relation* readrel29 = db->getRelation("mbranch");
      mbranchindex3 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("mp_msk");
      mp_mskindex4 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("mp_msk");
      mp_mskdelta16 = readrel33->getIndex(ord32, true);
      std::vector<u16> ord34({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel35 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index5 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 3, 4, 0});
      slog::Relation* readrel37 = db->getRelation("mbranch");
      mbranchindex6 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({2, 3, 0, 1});
      slog::Relation* readrel39 = db->getRelation("mp_put");
      mp_putindex7 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel41 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index8 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel43 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta17 = readrel43->getIndex(ord42, true);
      std::vector<u16> ord44({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel45 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index9 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel47 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0delta18 = readrel47->getIndex(ord46, true);
      std::vector<u16> ord48({2, 3, 0, 1});
      slog::Relation* readrel49 = db->getRelation("mp_put");
      mp_putindex10 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 2, 3, 0});
      slog::Relation* readrel51 = db->getRelation("mp_put");
      mp_putindex11 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 3, 4, 0});
      slog::Relation* readrel53 = db->getRelation("mbranch");
      mbranchindex12 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 3, 4, 0});
      slog::Relation* readrel55 = db->getRelation("mbranch");
      mbranchdelta19 = readrel55->getIndex(ord54, true);
      std::vector<u16> ord56({1, 2, 0, 3});
      slog::Relation* readrel57 = db->getRelation("mp_put");
      mp_putindex13 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 0, 3});
      slog::Relation* readrel59 = db->getRelation("mp_put");
      mp_putdelta20 = readrel59->getIndex(ord58, true);
      std::vector<u16> ord60({1, 2, 3, 0});
      slog::Relation* readrel61 = db->getRelation("mp_put");
      mp_putindex14 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 3, 0});
      slog::Relation* readrel63 = db->getRelation("mp_put");
      mp_putdelta21 = readrel63->getIndex(ord62, true);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("mp_put_ans");
      mp_put_ansindex15 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("mp_put_ans");
      mp_put_ansdelta22 = readrel67->getIndex(ord66, true);
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<8,2>($sup5638x42x0x0x1index1, std::array<u64,8>{v_c12, v_c9, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x42x0x0x0index2, std::array<u64,7>{v_c9, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex3, std::array<u64,5>{v_c9, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex4, mp_mskdelta16, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m68) {
          u64 v_c6 = m68[1]; u64 v_c8 = m68[2];
          if (!slog::exists_probe<7,3>($sup5638x42x0x0x0index5, std::array<u64,7>{v_c6, v_c8, v_c9, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex6, std::array<u64,5>{v_c9, v_c8, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex7, std::array<u64,4>{v_c6, 0, 0, 0})) return;
          slog::join_probe_old<8,4>($sup5638x42x0x0x1index8, $sup5638x42x0x0x1delta17, std::array<u64,8>{v_c12, v_c6, v_c8, v_c9, 0, 0, 0, 0}, [&](const std::array<u64,8>& m69) {
            u64 v_c13 = m69[4]; u64 v_c7 = m69[5]; u64 v_c10 = m69[6]; u64 v_c14 = m69[7];
            slog::join_probe_old<7,7>($sup5638x42x0x0x0index9, $sup5638x42x0x0x0delta18, std::array<u64,7>{v_c9, v_c7, v_c8, v_c10, v_c13, v_c6, v_c14}, [&](const std::array<u64,7>& m70) {
              if (!slog::exists_probe<4,3>(mp_putindex10, std::array<u64,4>{v_c6, v_c14, v_c13, 0})) return;
              if (!slog::exists_probe<4,3>(mp_putindex11, std::array<u64,4>{v_c10, v_c6, v_c14, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex12, mbranchdelta19, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m71) {
                u64 v_c15 = m71[4];
                slog::join_probe_old<4,4>(mp_putindex13, mp_putdelta20, std::array<u64,4>{v_c15, v_c6, v_c13, v_c14}, [&](const std::array<u64,4>& m72) {
                  slog::join_probe_old<4,3>(mp_putindex14, mp_putdelta21, std::array<u64,4>{v_c10, v_c6, v_c14, 0}, [&](const std::array<u64,4>& m73) {
                    u64 v_c16 = m73[3];
                    slog::join_probe_old<2,1>(mp_put_ansindex15, mp_put_ansdelta22, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m74) {
                      u64 v_c17 = m74[1];
                      u64 v_c18 = _prim_band(db, v_c6, v_c8);
                      if (v_c18 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c19 = _prim_gt(db, v_c18, v_c11);
                      if (v_c19 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c19) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c13, v_c17, v_c7, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), false);
  // (crule (pre (let __tconst1aAW45 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t0xN947 q m) (body (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists mbranch (2 0 1 3 4) 1 m) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_msk_ans (0 1) 1 __t0xN947) (join $sup5638x95x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t0xN947 m q p __t0mSQ44 l n r u v) (cmp lt n m) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t0mSQ44 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk_ans (0 1) 2 __t0xN947 p) (exists mp_union (1 2 0) 1 l) (join mbranch (1 2 3 4 0) 4 p m l r __t39oH43) (exists mp_union (0 1 2) 2 __t0mSQ44 __t39oH43) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t499t48) (join mp_union (0 1 2) 3 __t0mSQ44 __t39oH43 __t499t48) (join mp_msk_ans (0 1) 2 __t0xN947 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t499t48 __t2OJC49) (join mp_union_ans (0 1) 1 __t2OJC49 __v0) (let __t8bok46 (band q m)) (cmp lt __t8bok46 __tconst1aAW45)) (head (emit-temp temp2xeX1033 __t0mSQ44 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t4qMo41 p m __v0 r)) map.slog:96 #f)
  class ReadTask94 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index76;  slog::Index** mbranchindex77;  slog::Index** mbranchindex78;  slog::Index** mp_msk_ansindex79;  slog::Index** $sup5638x95x0x0x1index80;  slog::Index** $sup5638x95x0x0x0index81;  slog::Index** mbranchindex82;  slog::Index** mp_msk_ansindex83;  slog::Index** mp_unionindex84;  slog::Index** mbranchindex85;  slog::Index** mp_unionindex86;  slog::Index** mbranchindex87;  slog::Index** mp_unionindex88;  slog::Index** mp_msk_ansindex89;  slog::Index** mp_unionindex90;  slog::Index** mp_union_ansindex91;  slog::Index** mbranchdelta92;  slog::Index** mp_uniondelta93;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2xeX1033");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord95({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel96 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index76 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({2, 0, 1, 3, 4});
      slog::Relation* readrel98 = db->getRelation("mbranch");
      mbranchindex77 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 3, 4, 0});
      slog::Relation* readrel100 = db->getRelation("mbranch");
      mbranchindex78 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex79 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel104 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index80 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel106 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index81 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 3, 4, 0});
      slog::Relation* readrel108 = db->getRelation("mbranch");
      mbranchindex82 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex83 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 2, 0});
      slog::Relation* readrel112 = db->getRelation("mp_union");
      mp_unionindex84 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 3, 4, 0});
      slog::Relation* readrel114 = db->getRelation("mbranch");
      mbranchindex85 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1, 2});
      slog::Relation* readrel116 = db->getRelation("mp_union");
      mp_unionindex86 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 3, 4, 0});
      slog::Relation* readrel118 = db->getRelation("mbranch");
      mbranchindex87 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 2, 3, 4, 0});
      slog::Relation* readrel120 = db->getRelation("mbranch");
      mbranchdelta92 = readrel120->getIndex(ord119, true);
      std::vector<u16> ord121({0, 1, 2});
      slog::Relation* readrel122 = db->getRelation("mp_union");
      mp_unionindex88 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex89 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 0});
      slog::Relation* readrel126 = db->getRelation("mp_union");
      mp_unionindex90 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 2, 0});
      slog::Relation* readrel128 = db->getRelation("mp_union");
      mp_uniondelta93 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("mp_union_ans");
      mp_union_ansindex91 = readrel130->getIndex(ord129, false);
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index76, std::array<u64,9>{v_c8, v_c22, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex77, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex78, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex79, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<10,3>($sup5638x95x0x0x1index80, std::array<u64,10>{v_c21, v_c8, v_c22, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m131) {
          u64 v_c9 = m131[3]; u64 v_c23 = m131[4]; u64 v_c7 = m131[5]; u64 v_c24 = m131[6]; u64 v_c10 = m131[7]; u64 v_c25 = m131[8]; u64 v_c14 = m131[9];
          u64 v_c26 = _prim_lt(db, v_c24, v_c8);
          if (v_c26 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c26) return;
          slog::join_probe<9,9>($sup5638x95x0x0x0index81, std::array<u64,9>{v_c7, v_c8, v_c9, v_c10, v_c23, v_c24, v_c22, v_c25, v_c14}, [&](const std::array<u64,9>& m133) {
            if (!slog::exists_probe<5,4>(mbranchindex82, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex83, std::array<u64,2>{v_c21, v_c9})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex84, std::array<u64,3>{v_c7, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex85, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m134) {
              u64 v_c27 = m134[4];
              if (!slog::exists_probe<3,2>(mp_unionindex86, std::array<u64,3>{v_c23, v_c27, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex87, mbranchdelta92, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, 0}, [&](const std::array<u64,5>& m135) {
                u64 v_c28 = m135[4];
                slog::join_probe<3,3>(mp_unionindex88, std::array<u64,3>{v_c23, v_c27, v_c28}, [&](const std::array<u64,3>& m136) {
                  slog::join_probe<2,2>(mp_msk_ansindex89, std::array<u64,2>{v_c21, v_c9}, [&](const std::array<u64,2>& m137) {
                    slog::join_probe_old<3,2>(mp_unionindex90, mp_uniondelta93, std::array<u64,3>{v_c7, v_c28, 0}, [&](const std::array<u64,3>& m138) {
                      u64 v_c29 = m138[2];
                      slog::join_probe<2,1>(mp_union_ansindex91, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m139) {
                        u64 v_c17 = m139[1];
                        u64 v_c30 = _prim_band(db, v_c22, v_c8);
                        if (v_c30 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c31 = _prim_lt(db, v_c30, v_c20);
                        if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c31) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c23, v_c17, v_c8, v_c9, v_c10});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c17, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), false);
  // (crule (pre (let __tconst9Mut582 constd01925b37634a1a9d24159d8)) (scan mp_bld __t9UyG147 p m l r) (body (join _enum (1 0) 1 __tconst9Mut582 __t4o12148) (neq l __t4o12148) (neq r __t4o12148)) (head (emit-temp temp5jzw1068 __t9UyG147 l m p r) (mkstruct mbranch (1 2 3 4 0) __t9Cts146 p m l r)) map.slog:75 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5jzw1068");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord143({1, 0});
      slog::Relation* readrel144 = db->getRelation("_enum");
      _enumindex141 = readrel144->getIndex(ord143, false);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        slog::join_probe<2,1>(_enumindex141, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m145) {
          u64 v_c34 = m145[1];
          if (v_c7 == v_c34) return;
          if (v_c10 == v_c34) return;
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c33, v_c7, v_c8, v_c9, v_c10});
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:75", "delta:mp_bld", _fires);
  
      if (!_done)
      {
        ReadTask142* _cont = new ReadTask142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask142(db,b), false);
  // (crule (pre (let __tconst1VYq155 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __t8KQn154 k l m p r) (body (exists mp_del (0 2 1) 2 __t8KQn154 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t85IU153) (join-old mp_del (0 2 1) 3 (0 2 1) __t8KQn154 k __t85IU153) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t0Lvo157 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t0Lvo157) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1jAB158) (join mp_msk_ans (0 1) 2 __t1jAB158 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t5pOj159) (join mp_del_ans (0 1) 2 __t5pOj159 __v0) (join mp_bld_ans (0 1) 1 __t0Lvo157 res) (let __t6N9r156 (band k m)) (cmp lt __t6N9r156 __tconst1VYq155)) (head (emit mp_del_ans (0 1) __t8KQn154 res)) map.slog:83 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex146;  slog::Index** mp_bldindex147;  slog::Index** mp_mskindex148;  slog::Index** mp_msk_ansindex149;  slog::Index** mp_delindex150;  slog::Index** mbranchindex151;  slog::Index** mp_delindex152;  slog::Index** mp_bldindex153;  slog::Index** mp_del_ansindex154;  slog::Index** mp_bld_ansindex155;  slog::Index** mp_mskindex156;  slog::Index** mp_msk_ansindex157;  slog::Index** mp_delindex158;  slog::Index** mp_del_ansindex159;  slog::Index** mp_bld_ansindex160;  slog::Index** mbranchdelta161;  slog::Index** mp_deldelta162;  slog::Index** mp_blddelta163;  slog::Index** mp_mskdelta164;  slog::Index** mp_deldelta165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("mp_del_ans");
      head_index[0] = readrel168->getIndex(ord167, false);
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord169({0, 2, 1});
      slog::Relation* readrel170 = db->getRelation("mp_del");
      mp_delindex146 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({2, 1, 4, 0, 3});
      slog::Relation* readrel172 = db->getRelation("mp_bld");
      mp_bldindex147 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("mp_msk");
      mp_mskindex148 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex149 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("mp_del");
      mp_delindex150 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 3, 4, 0});
      slog::Relation* readrel180 = db->getRelation("mbranch");
      mbranchindex151 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 3, 4, 0});
      slog::Relation* readrel182 = db->getRelation("mbranch");
      mbranchdelta161 = readrel182->getIndex(ord181, true);
      std::vector<u16> ord183({0, 2, 1});
      slog::Relation* readrel184 = db->getRelation("mp_del");
      mp_delindex152 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({0, 2, 1});
      slog::Relation* readrel186 = db->getRelation("mp_del");
      mp_deldelta162 = readrel186->getIndex(ord185, true);
      std::vector<u16> ord187({2, 1, 4, 0, 3});
      slog::Relation* readrel188 = db->getRelation("mp_bld");
      mp_bldindex153 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({2, 1, 4, 0, 3});
      slog::Relation* readrel190 = db->getRelation("mp_bld");
      mp_blddelta163 = readrel190->getIndex(ord189, true);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("mp_del_ans");
      mp_del_ansindex154 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex155 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("mp_msk");
      mp_mskindex156 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("mp_msk");
      mp_mskdelta164 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex157 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("mp_del");
      mp_delindex158 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 0});
      slog::Relation* readrel204 = db->getRelation("mp_del");
      mp_deldelta165 = readrel204->getIndex(ord203, true);
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("mp_del_ans");
      mp_del_ansindex159 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 1});
      slog::Relation* readrel208 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex160 = readrel208->getIndex(ord207, false);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex146, std::array<u64,3>{v_c36, v_c6, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex147, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex148, std::array<u64,3>{v_c6, v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex149, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex150, std::array<u64,3>{v_c7, v_c6, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex151, mbranchdelta161, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m209) {
          u64 v_c37 = m209[4];
          slog::join_probe_old<3,3>(mp_delindex152, mp_deldelta162, std::array<u64,3>{v_c36, v_c6, v_c37}, [&](const std::array<u64,3>& m210) {
            slog::join_probe_old<5,3>(mp_bldindex153, mp_blddelta163, std::array<u64,5>{v_c8, v_c9, v_c10, 0, 0}, [&](const std::array<u64,5>& m211) {
              u64 v_c38 = m211[3]; u64 v_c17 = m211[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex154, std::array<u64,2>{v_c17, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex155, std::array<u64,2>{v_c38, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex156, mp_mskdelta164, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m212) {
                u64 v_c39 = m212[2];
                slog::join_probe<2,2>(mp_msk_ansindex157, std::array<u64,2>{v_c39, v_c9}, [&](const std::array<u64,2>& m213) {
                  slog::join_probe_old<3,2>(mp_delindex158, mp_deldelta165, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m214) {
                    u64 v_c40 = m214[2];
                    slog::join_probe<2,2>(mp_del_ansindex159, std::array<u64,2>{v_c40, v_c17}, [&](const std::array<u64,2>& m215) {
                      slog::join_probe<2,1>(mp_bld_ansindex160, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m216) {
                        u64 v_c41 = m216[1];
                        u64 v_c42 = _prim_band(db, v_c6, v_c8);
                        if (v_c42 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c43 = _prim_lt(db, v_c42, v_c35);
                        if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c43) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c41}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
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
  // (crule (pre) (scan mp_msk __t4OmG128 p n) (body (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join mp_msk_ans (0 1) 1 __t4OmG128 q) (join $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t4OmG128 l m n p q r v)) map.slog:105 #f)
  class ReadTask221 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index218;  slog::Index** mp_msk_ansindex219;  slog::Index** $sup5638x104x0x0x0index220;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord222({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel223 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel223->getIndex(ord222, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord224({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel225 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index218 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex219 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel229 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index220 = readrel229->getIndex(ord228, false);
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c24 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index218, std::array<u64,9>{v_c24, v_c9, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex219, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m230) {
          u64 v_c22 = m230[1];
          slog::join_probe<9,3>($sup5638x104x0x0x0index220, std::array<u64,9>{v_c24, v_c9, v_c22, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m231) {
            u64 v_c5 = m231[3]; u64 v_c7 = m231[4]; u64 v_c8 = m231[5]; u64 v_c10 = m231[6]; u64 v_c25 = m231[7]; u64 v_c14 = m231[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c5, v_c25, v_c44, v_c7, v_c8, v_c24, v_c9, v_c22, v_c10, v_c14}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask221* _cont = new ReadTask221(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask221(db,b), false);
  // (crule (pre) (scan mp_msk __t7eaA149 k m) (body (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 2 k m) (join mp_msk_ans (0 1) 1 __t7eaA149 p) (join $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t7eaA149 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask235 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index232;  slog::Index** mp_msk_ansindex233;  slog::Index** $sup5638x40x0x0x0index234;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord236({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel237 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel237->getIndex(ord236, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord238({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel239 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index232 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex233 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel243 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index234 = readrel243->getIndex(ord242, false);
  
    }
    ReadTask235(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x40x0x0x0index232, std::array<u64,7>{v_c6, v_c8, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex233, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m244) {
          u64 v_c9 = m244[1];
          slog::join_probe<7,3>($sup5638x40x0x0x0index234, std::array<u64,7>{v_c6, v_c8, v_c9, 0, 0, 0, 0}, [&](const std::array<u64,7>& m245) {
            u64 v_c5 = m245[3]; u64 v_c7 = m245[4]; u64 v_c10 = m245[5]; u64 v_c14 = m245[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c45, v_c9, v_c5, v_c6, v_c7, v_c8, v_c10, v_c14}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst0HVn828 constd01925b37634a1a9d24159d8) (let __tconst9FbD307 const8c1f1046219ddd216a023f79) (let __tconst465U308 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst465U308 __tconst9FbD307 __t0rdB310 __t3qgX309) (body (join _enum (0 1) 2 __t3qgX309 __tconst0HVn828) (join mp_put_ans (0 1) 1 __t0rdB310 s) (join canon (0) 0 m)) (head (mkstruct mp_union (1 2 0) __4LkF829 s m)) mp_basic.slog:23 #f)
  class ReadTask249 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex246;  slog::Index** mp_put_ansindex247;  slog::Index** canonindex248;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      std::vector<u16> ord250({2, 3, 0, 1});
      slog::Relation* readrel251 = db->getRelation("mp_put");
      driver_index = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("_enum");
      _enumindex246 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("mp_put_ans");
      mp_put_ansindex247 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0});
      slog::Relation* readrel257 = db->getRelation("canon");
      canonindex248 = readrel257->getIndex(ord256, false);
  
    }
    ReadTask249(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c46 = v_constd01925b37634a1a9d24159d8;
      u64 v_c47 = v_const8c1f1046219ddd216a023f79;
      u64 v_c48 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c48, v_c47, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m258) {
        u64 v_c49 = m258[2];
        u64 v_c50 = m258[3];
        if (buckethash(v_c49) != bucket) return;
        slog::join_probe<2,2>(_enumindex246, std::array<u64,2>{v_c50, v_c46}, [&](const std::array<u64,2>& m259) {
          slog::join_probe<2,1>(mp_put_ansindex247, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m260) {
            u64 v_c51 = m260[1];
            slog::join_all<1>(canonindex248, [&](const std::array<u64,1>& m261) {
              u64 v_c8 = m261[0];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c8}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:23", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask249* _cont = new ReadTask249(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask249(db,b), false);
  // (crule (pre) (scan mbranch __t5rXw260 p m u v) (body (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_union (2 0 1) 1 __t5rXw260) (exists mp_union (2 0 1) 1 u) (exists mp_union (2 0 1) 1 v) (join $sup5638x93x0x0x0 (2 3 5 6 0 1 4) 4 m p u v __t9rnk262 l r) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2wpn261) (join-old mp_union (0 1 2) 3 (0 1 2) __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t2Oaj263) (exists mp_union_ans (0 1) 1 __t2Oaj263) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (exists mp_union_ans (0 1) 1 __t0Kdo264) (join mp_union_ans (0 1) 1 __t2Oaj263 __v0) (join mp_union_ans (0 1) 1 __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex262;  slog::Index** mp_unionindex263;  slog::Index** mp_unionindex264;  slog::Index** mp_unionindex265;  slog::Index** $sup5638x93x0x0x0index266;  slog::Index** mp_unionindex267;  slog::Index** mp_unionindex268;  slog::Index** mp_unionindex269;  slog::Index** mbranchindex270;  slog::Index** mp_unionindex271;  slog::Index** mp_unionindex272;  slog::Index** mp_union_ansindex273;  slog::Index** mp_unionindex274;  slog::Index** mp_union_ansindex275;  slog::Index** mp_union_ansindex276;  slog::Index** mp_union_ansindex277;  slog::Index** mbranchdelta278;  slog::Index** mp_uniondelta279;  slog::Index** mp_uniondelta280;  slog::Index** mp_uniondelta281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord283({1, 2, 3, 4, 0});
      slog::Relation* readrel284 = db->getRelation("mbranch");
      mbranchindex262 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({2, 0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_union");
      mp_unionindex263 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({2, 0, 1});
      slog::Relation* readrel288 = db->getRelation("mp_union");
      mp_unionindex264 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({2, 0, 1});
      slog::Relation* readrel290 = db->getRelation("mp_union");
      mp_unionindex265 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel292 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index266 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({2, 0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_union");
      mp_unionindex267 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 2, 0});
      slog::Relation* readrel296 = db->getRelation("mp_union");
      mp_unionindex268 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("mp_union");
      mp_unionindex269 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 3, 4, 0});
      slog::Relation* readrel300 = db->getRelation("mbranch");
      mbranchindex270 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 3, 4, 0});
      slog::Relation* readrel302 = db->getRelation("mbranch");
      mbranchdelta278 = readrel302->getIndex(ord301, true);
      std::vector<u16> ord303({0, 1, 2});
      slog::Relation* readrel304 = db->getRelation("mp_union");
      mp_unionindex271 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 1, 2});
      slog::Relation* readrel306 = db->getRelation("mp_union");
      mp_uniondelta279 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("mp_union");
      mp_unionindex272 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 2, 0});
      slog::Relation* readrel310 = db->getRelation("mp_union");
      mp_uniondelta280 = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("mp_union_ans");
      mp_union_ansindex273 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("mp_union");
      mp_unionindex274 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("mp_union");
      mp_uniondelta281 = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({0, 1});
      slog::Relation* readrel318 = db->getRelation("mp_union_ans");
      mp_union_ansindex275 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("mp_union_ans");
      mp_union_ansindex276 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("mp_union_ans");
      mp_union_ansindex277 = readrel322->getIndex(ord321, false);
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c14 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex262, std::array<u64,5>{v_c9, v_c8, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex263, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex264, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex265, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe<7,4>($sup5638x93x0x0x0index266, std::array<u64,7>{v_c8, v_c9, v_c25, v_c14, 0, 0, 0}, [&](const std::array<u64,7>& m323) {
          u64 v_c53 = m323[4]; u64 v_c7 = m323[5]; u64 v_c10 = m323[6];
          if (!slog::exists_probe<3,2>(mp_unionindex267, std::array<u64,3>{v_c52, v_c53, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex268, std::array<u64,3>{v_c7, v_c25, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex269, std::array<u64,3>{v_c10, v_c14, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex270, mbranchdelta278, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m324) {
            u64 v_c54 = m324[4];
            slog::join_probe_old<3,3>(mp_unionindex271, mp_uniondelta279, std::array<u64,3>{v_c53, v_c54, v_c52}, [&](const std::array<u64,3>& m325) {
              slog::join_probe_old<3,2>(mp_unionindex272, mp_uniondelta280, std::array<u64,3>{v_c7, v_c25, 0}, [&](const std::array<u64,3>& m326) {
                u64 v_c55 = m326[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex273, std::array<u64,2>{v_c55, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex274, mp_uniondelta281, std::array<u64,3>{v_c10, v_c14, 0}, [&](const std::array<u64,3>& m327) {
                  u64 v_c56 = m327[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex275, std::array<u64,2>{v_c56, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex276, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m328) {
                    u64 v_c17 = m328[1];
                    slog::join_probe<2,1>(mp_union_ansindex277, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m329) {
                      u64 v_c57 = m329[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c53, v_c17, v_c57, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c17, v_c57}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask282* _cont = new ReadTask282(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask282(db,b), false);
  // (crule (pre (let __trid2hJI853 constfee494ff4827aeb0635bb714) (let __trel0l7X854 const20347926ddb307a8e2bdb71b) (let __tcol3G8h855 constd4735e3a265e16eee03f5971)) (scan mp_msk __t1DER257 k m) (body (exists $sup5638x84x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t1DER257 p) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t4tTw258) (join mp_del_ans (0 1) 1 __t4tTw258 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2hJI853 __trel0l7X854 __tcol3G8h855 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __5v59852 p m l __v0)) map.slog:85 #f)
  class ReadTask340 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index330;  slog::Index** mp_delindex331;  slog::Index** mp_msk_ansindex332;  slog::Index** $sup5638x84x0x0x0index333;  slog::Index** mp_delindex334;  slog::Index** mp_del_ansindex335;  slog::Index** mp_deldelta336;
    u32 sid338;  u32 sid337;  u32 sid339;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord341({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel342 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index330 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({2, 0, 1});
      slog::Relation* readrel344 = db->getRelation("mp_del");
      mp_delindex331 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex332 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel348 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index333 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("mp_del");
      mp_delindex334 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("mp_del");
      mp_deldelta336 = readrel352->getIndex(ord351, true);
      std::vector<u16> ord353({0, 1});
      slog::Relation* readrel354 = db->getRelation("mp_del_ans");
      mp_del_ansindex335 = readrel354->getIndex(ord353, false);
      sid338 = db->getRelation("_enum")->getStructId();
      sid337 = db->getRelation("mbranch")->getStructId();
      sid339 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask340(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constfee494ff4827aeb0635bb714;
      u64 v_c59 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c60 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index330, std::array<u64,6>{v_c6, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex331, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex332, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m355) {
          u64 v_c9 = m355[1];
          slog::join_probe<6,3>($sup5638x84x0x0x0index333, std::array<u64,6>{v_c6, v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m356) {
            u64 v_c5 = m356[3]; u64 v_c7 = m356[4]; u64 v_c10 = m356[5];
            slog::join_probe_old<3,2>(mp_delindex334, mp_deldelta336, std::array<u64,3>{v_c10, v_c6, 0}, [&](const std::array<u64,3>& m357) {
              u64 v_c62 = m357[2];
              slog::join_probe<2,1>(mp_del_ansindex335, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m358) {
                u64 v_c17 = m358[1];
                ++_fires;
                if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid337 || decode_struct_id(v_c7) == sid338 || decode_struct_id(v_c7) == sid339))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c58, v_c59, v_c60, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c7, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask340* _cont = new ReadTask340(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask340(db,b), false);
  // (crule (pre) (scan mp_del __t9Sl6223 __t5VI4222 k) (body (exists mp_msk (1 2 0) 1 k) (join $sup5638x81x0x0x0 (0 1 2 3 4 5) 2 __t9Sl6223 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t5VI4222) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t3J75224) (join mp_msk_ans (0 1) 1 __t3J75224 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t9Sl6223 __t5VI4222)) map.slog:82 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex359;  slog::Index** $sup5638x81x0x0x0index360;  slog::Index** mbranchindex361;  slog::Index** mp_mskindex362;  slog::Index** mp_msk_ansindex363;  slog::Index** mp_mskdelta364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord366({0, 1});
      slog::Relation* readrel367 = db->getRelation("mp_del_ans");
      head_index[0] = readrel367->getIndex(ord366, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord368({1, 2, 0});
      slog::Relation* readrel369 = db->getRelation("mp_msk");
      mp_mskindex359 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel371 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index360 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 3, 4, 0});
      slog::Relation* readrel373 = db->getRelation("mbranch");
      mbranchindex361 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("mp_msk");
      mp_mskindex362 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("mp_msk");
      mp_mskdelta364 = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex363 = readrel379->getIndex(ord378, false);
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex359, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x81x0x0x0index360, std::array<u64,6>{v_c63, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m380) {
          u64 v_c7 = m380[2]; u64 v_c8 = m380[3]; u64 v_c9 = m380[4]; u64 v_c10 = m380[5];
          slog::join_probe<5,5>(mbranchindex361, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c64}, [&](const std::array<u64,5>& m381) {
            slog::join_probe_old<3,2>(mp_mskindex362, mp_mskdelta364, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m382) {
              u64 v_c65 = m382[2];
              slog::join_probe<2,1>(mp_msk_ansindex363, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m383) {
                u64 v_c17 = m383[1];
                if (v_c9 == v_c17) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c64}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask365* _cont = new ReadTask365(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask365(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_del __t01YW404 __t0VzH403 k) (body (exists mp_msk (1 2 0) 1 k) (exists mp_del (2 0 1) 1 k) (join $sup5638x84x0x0x0 (0 1 2 3 4 5) 2 __t01YW404 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t0VzH403) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8Ai5407) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join mp_del_ans (0 1) 2 __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask402 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex384;  slog::Index** mp_delindex385;  slog::Index** $sup5638x84x0x0x0index386;  slog::Index** mbranchindex387;  slog::Index** mp_mskindex388;  slog::Index** mp_msk_ansindex389;  slog::Index** mp_delindex390;  slog::Index** mp_bldindex391;  slog::Index** mp_del_ansindex392;  slog::Index** mp_bld_ansindex393;  slog::Index** mp_mskindex394;  slog::Index** mp_msk_ansindex395;  slog::Index** mp_delindex396;  slog::Index** mp_del_ansindex397;  slog::Index** mp_bld_ansindex398;  slog::Index** mp_blddelta399;  slog::Index** mp_mskdelta400;  slog::Index** mp_deldelta401;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("mp_del_ans");
      head_index[0] = readrel404->getIndex(ord403, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("mp_msk");
      mp_mskindex384 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({2, 0, 1});
      slog::Relation* readrel408 = db->getRelation("mp_del");
      mp_delindex385 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel410 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index386 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 3, 4, 0});
      slog::Relation* readrel412 = db->getRelation("mbranch");
      mbranchindex387 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("mp_msk");
      mp_mskindex388 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 0});
      slog::Relation* readrel416 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex389 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("mp_del");
      mp_delindex390 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 3, 4, 0});
      slog::Relation* readrel420 = db->getRelation("mp_bld");
      mp_bldindex391 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 2, 3, 4, 0});
      slog::Relation* readrel422 = db->getRelation("mp_bld");
      mp_blddelta399 = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({1, 0});
      slog::Relation* readrel424 = db->getRelation("mp_del_ans");
      mp_del_ansindex392 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1});
      slog::Relation* readrel426 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex393 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 0});
      slog::Relation* readrel428 = db->getRelation("mp_msk");
      mp_mskindex394 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("mp_msk");
      mp_mskdelta400 = readrel430->getIndex(ord429, true);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex395 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 0});
      slog::Relation* readrel434 = db->getRelation("mp_del");
      mp_delindex396 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 0});
      slog::Relation* readrel436 = db->getRelation("mp_del");
      mp_deldelta401 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("mp_del_ans");
      mp_del_ansindex397 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex398 = readrel440->getIndex(ord439, false);
  
    }
    ReadTask402(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex384, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex385, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x84x0x0x0index386, std::array<u64,6>{v_c67, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m441) {
          u64 v_c7 = m441[2]; u64 v_c8 = m441[3]; u64 v_c9 = m441[4]; u64 v_c10 = m441[5];
          slog::join_probe<5,5>(mbranchindex387, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c68}, [&](const std::array<u64,5>& m442) {
            if (!slog::exists_probe<3,2>(mp_mskindex388, std::array<u64,3>{v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex389, std::array<u64,2>{v_c9, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex390, std::array<u64,3>{v_c10, v_c6, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex391, mp_blddelta399, std::array<u64,5>{v_c9, v_c8, v_c7, 0, 0}, [&](const std::array<u64,5>& m443) {
              u64 v_c17 = m443[3]; u64 v_c69 = m443[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex392, std::array<u64,2>{v_c17, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex393, std::array<u64,2>{v_c69, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex394, mp_mskdelta400, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m444) {
                u64 v_c70 = m444[2];
                slog::join_probe<2,2>(mp_msk_ansindex395, std::array<u64,2>{v_c70, v_c9}, [&](const std::array<u64,2>& m445) {
                  slog::join_probe_old<3,2>(mp_delindex396, mp_deldelta401, std::array<u64,3>{v_c10, v_c6, 0}, [&](const std::array<u64,3>& m446) {
                    u64 v_c71 = m446[2];
                    slog::join_probe<2,2>(mp_del_ansindex397, std::array<u64,2>{v_c71, v_c17}, [&](const std::array<u64,2>& m447) {
                      slog::join_probe<2,1>(mp_bld_ansindex398, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m448) {
                        u64 v_c41 = m448[1];
                        u64 v_c72 = _prim_band(db, v_c6, v_c8);
                        if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c73 = _prim_gt(db, v_c72, v_c66);
                        if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c73) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c41}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask402* _cont = new ReadTask402(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask402(db,b), false);
  // (crule (pre) (scan mbranch __t0o62217 p m l r) (body (exists mp_join (1 2 3 4 0) 2 p __t0o62217) (exists mp_union (1 2 0) 1 __t0o62217) (exists mp_msk (1 2 0) 1 p) (join $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 5 l m p r __t0o62217 n __t5xrH216 q __t0BoC218 u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0BoC218) (exists mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t0o62217 q __t0BoC218 __t7HEI219) (join mp_union (0 1 2) 3 __t5xrH216 __t0o62217 __t0BoC218) (exists mp_join_ans (0 1) 1 __t7HEI219) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex450;  slog::Index** mp_unionindex451;  slog::Index** mp_mskindex452;  slog::Index** $sup5638x110x0x0x0index453;  slog::Index** mbranchindex454;  slog::Index** mp_unionindex455;  slog::Index** mp_mskindex456;  slog::Index** mp_joinindex457;  slog::Index** mp_unionindex458;  slog::Index** mp_join_ansindex459;  slog::Index** mp_mskindex460;  slog::Index** mp_msk_ansindex461;  slog::Index** mp_join_ansindex462;  slog::Index** mbranchdelta463;  slog::Index** mp_joindelta464;  slog::Index** mp_mskdelta465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("mp_union_ans");
      head_index[0] = readrel468->getIndex(ord467, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord469({1, 2, 3, 4, 0});
      slog::Relation* readrel470 = db->getRelation("mp_join");
      mp_joinindex450 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("mp_union");
      mp_unionindex451 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 2, 0});
      slog::Relation* readrel474 = db->getRelation("mp_msk");
      mp_mskindex452 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel476 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index453 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 3, 4, 0});
      slog::Relation* readrel478 = db->getRelation("mbranch");
      mbranchindex454 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 4, 0});
      slog::Relation* readrel480 = db->getRelation("mbranch");
      mbranchdelta463 = readrel480->getIndex(ord479, true);
      std::vector<u16> ord481({0, 1, 2});
      slog::Relation* readrel482 = db->getRelation("mp_union");
      mp_unionindex455 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("mp_msk");
      mp_mskindex456 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 3, 4, 0});
      slog::Relation* readrel486 = db->getRelation("mp_join");
      mp_joinindex457 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 2, 3, 4, 0});
      slog::Relation* readrel488 = db->getRelation("mp_join");
      mp_joindelta464 = readrel488->getIndex(ord487, true);
      std::vector<u16> ord489({0, 1, 2});
      slog::Relation* readrel490 = db->getRelation("mp_union");
      mp_unionindex458 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("mp_join_ans");
      mp_join_ansindex459 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("mp_msk");
      mp_mskindex460 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("mp_msk");
      mp_mskdelta465 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex461 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("mp_join_ans");
      mp_join_ansindex462 = readrel500->getIndex(ord499, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex450, std::array<u64,5>{v_c9, v_c74, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex451, std::array<u64,3>{v_c74, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex452, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x110x0x0x0index453, std::array<u64,11>{v_c7, v_c8, v_c9, v_c10, v_c74, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m501) {
          u64 v_c24 = m501[5]; u64 v_c75 = m501[6]; u64 v_c22 = m501[7]; u64 v_c76 = m501[8]; u64 v_c25 = m501[9]; u64 v_c14 = m501[10];
          u64 v_c77 = _prim_lt(db, v_c8, v_c24);
          if (v_c77 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c77) return;
          slog::join_probe_old<5,5>(mbranchindex454, mbranchdelta463, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, v_c76}, [&](const std::array<u64,5>& m503) {
            if (!slog::exists_probe<3,3>(mp_unionindex455, std::array<u64,3>{v_c75, v_c74, v_c76})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex456, std::array<u64,3>{v_c9, v_c24, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex457, mp_joindelta464, std::array<u64,5>{v_c9, v_c74, v_c22, v_c76, 0}, [&](const std::array<u64,5>& m504) {
              u64 v_c78 = m504[4];
              slog::join_probe<3,3>(mp_unionindex458, std::array<u64,3>{v_c75, v_c74, v_c76}, [&](const std::array<u64,3>& m505) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex459, std::array<u64,2>{v_c78, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex460, mp_mskdelta465, std::array<u64,3>{v_c9, v_c24, 0}, [&](const std::array<u64,3>& m506) {
                  u64 v_c79 = m506[2];
                  slog::join_probe<2,1>(mp_msk_ansindex461, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m507) {
                    u64 v_c17 = m507[1];
                    if (v_c22 == v_c17) return;
                    slog::join_probe<2,1>(mp_join_ansindex462, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m508) {
                      u64 v_c41 = m508[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c75, v_c41}, std::array<u16,2>{0, 1});
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
        ReadTask466* _cont = new ReadTask466(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask466(db,b), false);
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_del __t3il5409 r k) (body (exists $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t3il5409 __v0) (exists mp_bld (4 0 1 2 3) 1 __v0) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __t01YW404 l m p) (exists mp_bld (1 2 3 4 0) 4 p m l __v0) (exists mp_del (0 2 1) 2 __t01YW404 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t0VzH403) (exists mp_del (0 2 1) 3 __t01YW404 k __t0VzH403) (join mp_bld (1 2 3 4 0) 4 p m l __v0 __t8Ai5407) (join mp_del (0 2 1) 3 __t01YW404 k __t0VzH403) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join mp_msk (1 2 0) 2 k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask528 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index509;  slog::Index** mbranchindex510;  slog::Index** mp_delindex511;  slog::Index** mp_mskindex512;  slog::Index** mp_del_ansindex513;  slog::Index** mp_bldindex514;  slog::Index** $sup5638x84x0x0x0index515;  slog::Index** mp_bldindex516;  slog::Index** mp_delindex517;  slog::Index** mp_mskindex518;  slog::Index** mp_msk_ansindex519;  slog::Index** mbranchindex520;  slog::Index** mp_delindex521;  slog::Index** mp_bldindex522;  slog::Index** mp_delindex523;  slog::Index** mp_bld_ansindex524;  slog::Index** mp_mskindex525;  slog::Index** mp_msk_ansindex526;  slog::Index** mp_bld_ansindex527;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("mp_del_ans");
      head_index[0] = readrel530->getIndex(ord529, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord531({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel532 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index509 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({4, 0, 1, 2, 3});
      slog::Relation* readrel534 = db->getRelation("mbranch");
      mbranchindex510 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({2, 0, 1});
      slog::Relation* readrel536 = db->getRelation("mp_del");
      mp_delindex511 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("mp_msk");
      mp_mskindex512 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({0, 1});
      slog::Relation* readrel540 = db->getRelation("mp_del_ans");
      mp_del_ansindex513 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({4, 0, 1, 2, 3});
      slog::Relation* readrel542 = db->getRelation("mp_bld");
      mp_bldindex514 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel544 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index515 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 2, 3, 4, 0});
      slog::Relation* readrel546 = db->getRelation("mp_bld");
      mp_bldindex516 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({0, 2, 1});
      slog::Relation* readrel548 = db->getRelation("mp_del");
      mp_delindex517 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("mp_msk");
      mp_mskindex518 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 0});
      slog::Relation* readrel552 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex519 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 3, 4, 0});
      slog::Relation* readrel554 = db->getRelation("mbranch");
      mbranchindex520 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 2, 1});
      slog::Relation* readrel556 = db->getRelation("mp_del");
      mp_delindex521 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({1, 2, 3, 4, 0});
      slog::Relation* readrel558 = db->getRelation("mp_bld");
      mp_bldindex522 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 2, 1});
      slog::Relation* readrel560 = db->getRelation("mp_del");
      mp_delindex523 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex524 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 0});
      slog::Relation* readrel564 = db->getRelation("mp_msk");
      mp_mskindex525 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({0, 1});
      slog::Relation* readrel566 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex526 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1});
      slog::Relation* readrel568 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex527 = readrel568->getIndex(ord567, false);
  
    }
    ReadTask528(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c71 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index509, std::array<u64,6>{v_c6, v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex510, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex511, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex512, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex513, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m569) {
          u64 v_c17 = m569[1];
          if (!slog::exists_probe<5,1>(mp_bldindex514, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x84x0x0x0index515, std::array<u64,6>{v_c6, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,6>& m570) {
            u64 v_c67 = m570[2]; u64 v_c7 = m570[3]; u64 v_c8 = m570[4]; u64 v_c9 = m570[5];
            if (!slog::exists_probe<5,4>(mp_bldindex516, std::array<u64,5>{v_c9, v_c8, v_c7, v_c17, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex517, std::array<u64,3>{v_c67, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex518, std::array<u64,3>{v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex519, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<5,4>(mbranchindex520, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m571) {
              u64 v_c68 = m571[4];
              if (!slog::exists_probe<3,3>(mp_delindex521, std::array<u64,3>{v_c67, v_c6, v_c68})) return;
              slog::join_probe<5,4>(mp_bldindex522, std::array<u64,5>{v_c9, v_c8, v_c7, v_c17, 0}, [&](const std::array<u64,5>& m572) {
                u64 v_c69 = m572[4];
                slog::join_probe<3,3>(mp_delindex523, std::array<u64,3>{v_c67, v_c6, v_c68}, [&](const std::array<u64,3>& m573) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex524, std::array<u64,2>{v_c69, 0})) return;
                  slog::join_probe<3,2>(mp_mskindex525, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m574) {
                    u64 v_c70 = m574[2];
                    slog::join_probe<2,2>(mp_msk_ansindex526, std::array<u64,2>{v_c70, v_c9}, [&](const std::array<u64,2>& m575) {
                      slog::join_probe<2,1>(mp_bld_ansindex527, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m576) {
                        u64 v_c41 = m576[1];
                        u64 v_c72 = _prim_band(db, v_c6, v_c8);
                        if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c80 = _prim_gt(db, v_c72, v_c66);
                        if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c80) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c41}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
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
  // (crule (pre (let __tconst8Ngf105 const6b86b273ff34fce19d6b804e)) (scan mp_union __t109M109 __t6XhK108 u) (body (exists mp_union (1 2 0) 1 __t6XhK108) (exists mbranch (3 0 1 2 4) 1 u) (exists $sup5638x104x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join mp_union_ans (0 1) 1 __t109M109 __v0) (join mp_union (1 2 0) 1 __t6XhK108 __t9OKP102 __t38nk104) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t38nk104 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t38nk104 u) (join mbranch (3 0 1 2 4) 2 u __t9OKP102 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t38nk104) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t38nk104 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t6XhK108) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t38nk104 l m p r __t3jH2107) (join mbranch (1 2 3 4 0) 5 p m l r __t6XhK108) (join mp_msk (1 2 0) 3 p n __t3jH2107) (join mp_msk_ans (0 1) 2 __t3jH2107 q) (let __t2Wiz106 (band p n)) (cmp lt __t2Wiz106 __tconst8Ngf105)) (head (emit-temp temp6y6l1036 __t38nk104 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t3cki101 q n __v0 v)) map.slog:105 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex578;  slog::Index** mbranchindex579;  slog::Index** $sup5638x104x0x0x0index580;  slog::Index** $sup5638x104x0x0x1index581;  slog::Index** mp_union_ansindex582;  slog::Index** mp_unionindex583;  slog::Index** $sup5638x104x0x0x0index584;  slog::Index** $sup5638x104x0x0x1index585;  slog::Index** mbranchindex586;  slog::Index** $sup5638x104x0x0x1index587;  slog::Index** mp_mskindex588;  slog::Index** mp_msk_ansindex589;  slog::Index** $sup5638x104x0x0x0index590;  slog::Index** mbranchindex591;  slog::Index** mp_mskindex592;  slog::Index** $sup5638x104x0x0x1index593;  slog::Index** mbranchindex594;  slog::Index** mp_mskindex595;  slog::Index** mp_msk_ansindex596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6y6l1036");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord598({1, 2, 0});
      slog::Relation* readrel599 = db->getRelation("mp_union");
      mp_unionindex578 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({3, 0, 1, 2, 4});
      slog::Relation* readrel601 = db->getRelation("mbranch");
      mbranchindex579 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel603 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index580 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel605 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index581 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({0, 1});
      slog::Relation* readrel607 = db->getRelation("mp_union_ans");
      mp_union_ansindex582 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 2, 0});
      slog::Relation* readrel609 = db->getRelation("mp_union");
      mp_unionindex583 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel611 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index584 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel613 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index585 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({3, 0, 1, 2, 4});
      slog::Relation* readrel615 = db->getRelation("mbranch");
      mbranchindex586 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel617 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index587 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({2, 0, 1});
      slog::Relation* readrel619 = db->getRelation("mp_msk");
      mp_mskindex588 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 0});
      slog::Relation* readrel621 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex589 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel623 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index590 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 3, 4, 0});
      slog::Relation* readrel625 = db->getRelation("mbranch");
      mbranchindex591 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("mp_msk");
      mp_mskindex592 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel629 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index593 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 3, 4, 0});
      slog::Relation* readrel631 = db->getRelation("mbranch");
      mbranchindex594 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("mp_msk");
      mp_mskindex595 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex596 = readrel635->getIndex(ord634, false);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c81 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c82 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex578, std::array<u64,3>{v_c83, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex579, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index580, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index581, std::array<u64,10>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex582, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m636) {
          u64 v_c17 = m636[1];
          slog::join_probe<3,1>(mp_unionindex583, std::array<u64,3>{v_c83, 0, 0}, [&](const std::array<u64,3>& m637) {
            u64 v_c84 = m637[1]; u64 v_c85 = m637[2];
            if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index584, std::array<u64,9>{v_c85, v_c25, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index585, std::array<u64,10>{v_c85, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex586, std::array<u64,5>{v_c25, v_c84, 0, 0, 0}, [&](const std::array<u64,5>& m638) {
              u64 v_c22 = m638[2]; u64 v_c24 = m638[3]; u64 v_c14 = m638[4];
              if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index587, std::array<u64,10>{v_c25, v_c24, v_c22, v_c14, v_c85, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex588, std::array<u64,3>{v_c24, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex589, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe<9,5>($sup5638x104x0x0x0index590, std::array<u64,9>{v_c22, v_c24, v_c25, v_c14, v_c85, 0, 0, 0, 0}, [&](const std::array<u64,9>& m639) {
                u64 v_c7 = m639[5]; u64 v_c8 = m639[6]; u64 v_c9 = m639[7]; u64 v_c10 = m639[8];
                u64 v_c86 = _prim_lt(db, v_c8, v_c24);
                if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                if (!v_c86) return;
                if (!slog::exists_probe<5,5>(mbranchindex591, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c83})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex592, std::array<u64,3>{v_c9, v_c24, 0})) return;
                slog::join_probe<10,9>($sup5638x104x0x0x1index593, std::array<u64,10>{v_c25, v_c24, v_c22, v_c14, v_c85, v_c7, v_c8, v_c9, v_c10, 0}, [&](const std::array<u64,10>& m641) {
                  u64 v_c87 = m641[9];
                  slog::join_probe<5,5>(mbranchindex594, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c83}, [&](const std::array<u64,5>& m642) {
                    slog::join_probe<3,3>(mp_mskindex595, std::array<u64,3>{v_c9, v_c24, v_c87}, [&](const std::array<u64,3>& m643) {
                      slog::join_probe<2,2>(mp_msk_ansindex596, std::array<u64,2>{v_c87, v_c22}, [&](const std::array<u64,2>& m644) {
                        u64 v_c88 = _prim_band(db, v_c9, v_c24);
                        if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c89 = _prim_lt(db, v_c88, v_c81);
                        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c89) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c85, v_c17, v_c24, v_c22, v_c14});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c24, v_c17, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __trid79JJ868 consteca796f75a14387c3a7674e7) (let __trel4A6g869 constdd7bbf31ce5f578b9805e840) (let __tcol5CKr870 const5feceb66ffc86f38d952786c) (let __trel5zDZ871 constdd7bbf31ce5f578b9805e840) (let __tcol0Ulo872 const6b86b273ff34fce19d6b804e)) (scan $sup5638x29x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid79JJ868 __trel4A6g869 __tcol5CKr870 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid79JJ868 __trel5zDZ871 __tcol0Ulo872 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __08lO867 p0 __v1)) map.slog:30 #f)
  class ReadTask646 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x29x0x0x2");
  
    }
    ReadTask646(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_consteca796f75a14387c3a7674e7;
      u64 v_c91 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
      u64 v_c93 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c95 = _t[1];
        u64 v_c96 = _t[2];
        u64 v_c97 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c98 = _t[6];
        u64 v_c99 = _t[7];
        u64 v_c100 = _t[8];
        u64 v_c101 = _t[9];
        u64 v_c102 = _t[10];
        ++_fires;
        if (!(is_int(v_c99)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c90, v_c91, v_c92, v_c99}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c57)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c90, v_c93, v_c94, v_c57}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c99, v_c57}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask646* _cont = new ReadTask646(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask646(db,b), false);
  // (crule (pre (let __tconst9KOM52 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x2 __t6Puw51 __t2bXu55 dup3kne1056 dup92Cz1057 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t2bXu55 dup92Cz1057) (eq __t2bXu55 dup3kne1056) (join-old $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t6Puw51 p0 p1 t0 t1 __t2bXu55 __v0) (join-old $sup5638x25x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t6Puw51 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t6Puw51) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t2bXu55 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t6JeD58) (join-old mp_msk_ans (0 1) 1 (0 1) __t6JeD58 __v2) (let __t9Mxe59 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t2bXu55 __t9Mxe59) (let __t0P0N53 (band p0 __v0)) (cmp lt __t0P0N53 __tconst9KOM52)) (head (emit-temp temp7KpW1055 __t6Puw51 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t8sDR50 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask665 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x1index647;  slog::Index** $sup5638x25x0x0x0index648;  slog::Index** mp_joinindex649;  slog::Index** mp_hsb_ansindex650;  slog::Index** mp_hsb_ansindex651;  slog::Index** mp_hsb_ansindex652;  slog::Index** mp_mskindex653;  slog::Index** mp_msk_ansindex654;  slog::Index** mp_hsbindex655;  slog::Index** $sup5638x25x0x0x1delta656;  slog::Index** $sup5638x25x0x0x0delta657;  slog::Index** mp_joindelta658;  slog::Index** mp_hsb_ansdelta659;  slog::Index** mp_hsb_ansdelta660;  slog::Index** mp_hsb_ansdelta661;  slog::Index** mp_mskdelta662;  slog::Index** mp_msk_ansdelta663;  slog::Index** mp_hsbdelta664;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7KpW1055");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord666({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel667 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index647 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel669 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta656 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({1, 0, 2, 3, 4});
      slog::Relation* readrel671 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index648 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 0, 2, 3, 4});
      slog::Relation* readrel673 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0delta657 = readrel673->getIndex(ord672, true);
      std::vector<u16> ord674({1, 2, 3, 4, 0});
      slog::Relation* readrel675 = db->getRelation("mp_join");
      mp_joinindex649 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 3, 4, 0});
      slog::Relation* readrel677 = db->getRelation("mp_join");
      mp_joindelta658 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex650 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({0, 1});
      slog::Relation* readrel681 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta659 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex651 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta660 = readrel685->getIndex(ord684, true);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex652 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta661 = readrel689->getIndex(ord688, true);
      std::vector<u16> ord690({1, 2, 0});
      slog::Relation* readrel691 = db->getRelation("mp_msk");
      mp_mskindex653 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("mp_msk");
      mp_mskdelta662 = readrel693->getIndex(ord692, true);
      std::vector<u16> ord694({0, 1});
      slog::Relation* readrel695 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex654 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta663 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("mp_hsb");
      mp_hsbindex655 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1});
      slog::Relation* readrel701 = db->getRelation("mp_hsb");
      mp_hsbdelta664 = readrel701->getIndex(ord700, true);
  
    }
    ReadTask665(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c104 = _t[0];
        u64 v_c105 = _t[1];
        u64 v_c106 = _t[2];
        u64 v_c107 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c98 = _t[6];
        u64 v_c99 = _t[7];
        u64 v_c100 = _t[8];
        u64 v_c101 = _t[9];
        u64 v_c102 = _t[10];
        if (v_c105 != v_c107) return;
        if (v_c105 != v_c106) return;
        slog::join_probe_old<7,7>($sup5638x25x0x0x1index647, $sup5638x25x0x0x1delta656, std::array<u64,7>{v_c104, v_c99, v_c100, v_c101, v_c102, v_c105, v_c17}, [&](const std::array<u64,7>& m702) {
          slog::join_probe_old<5,5>($sup5638x25x0x0x0index648, $sup5638x25x0x0x0delta657, std::array<u64,5>{v_c99, v_c104, v_c100, v_c101, v_c102}, [&](const std::array<u64,5>& m703) {
            slog::join_probe_old<5,5>(mp_joinindex649, mp_joindelta658, std::array<u64,5>{v_c99, v_c101, v_c100, v_c102, v_c104}, [&](const std::array<u64,5>& m704) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex650, mp_hsb_ansdelta659, std::array<u64,2>{v_c105, v_c98}, [&](const std::array<u64,2>& m705) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex651, mp_hsb_ansdelta660, std::array<u64,2>{v_c105, v_c57}, [&](const std::array<u64,2>& m706) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex652, mp_hsb_ansdelta661, std::array<u64,2>{v_c105, v_c17}, [&](const std::array<u64,2>& m707) {
                    slog::join_probe_old<3,2>(mp_mskindex653, mp_mskdelta662, std::array<u64,3>{v_c99, v_c57, 0}, [&](const std::array<u64,3>& m708) {
                      u64 v_c108 = m708[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex654, mp_msk_ansdelta663, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m709) {
                        u64 v_c109 = m709[1];
                        u64 v_c110 = _prim_bxor(db, v_c99, v_c100);
                        if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex655, mp_hsbdelta664, std::array<u64,2>{v_c105, v_c110}, [&](const std::array<u64,2>& m710) {
                          u64 v_c111 = _prim_band(db, v_c99, v_c17);
                          if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c112 = _prim_lt(db, v_c111, v_c103);
                          if (v_c112 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c112) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c104, v_c109, v_c98, v_c101, v_c102});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c109, v_c98, v_c101, v_c102}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask665* _cont = new ReadTask665(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask665(db,b), false);
  // (crule (pre) (scan temp61Si1083 __t0wz7137) (body) (head (mkstruct mp_hsb (1 0) __00ax794 __t0wz7137)) map.slog:30 #f)
  class ReadTask712 : public slog::Task
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
      outer_rel = db->getRelation("temp61Si1083");
  
    }
    ReadTask712(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c113 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c113}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp61Si1083", _fires);
  
      if (!_done)
      {
        ReadTask712* _cont = new ReadTask712(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask712(db,b), false);
  // (crule (pre) (scan mp_union __t4ZhK374 __t8hMI375 __t5XzA376) (body (exists $sup5638x101x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t8hMI375 __t5XzA376 __t35Cd377 p q) (exists mbranch (0 1 2 3 4) 2 __t8hMI375 p) (exists mbranch (0 1 2 3 4) 2 __t5XzA376 q) (exists mp_msk (1 2 0) 1 q) (exists mp_join_ans (0 1) 1 __t35Cd377) (join $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t8hMI375 __t5XzA376 __t4ZhK374 l m n r u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t8hMI375) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5XzA376) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask729 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x101x0x0x0index713;  slog::Index** mp_joinindex714;  slog::Index** mbranchindex715;  slog::Index** mbranchindex716;  slog::Index** mp_mskindex717;  slog::Index** mp_join_ansindex718;  slog::Index** $sup5638x101x0x0x0index719;  slog::Index** mbranchindex720;  slog::Index** mbranchindex721;  slog::Index** mp_mskindex722;  slog::Index** mp_msk_ansindex723;  slog::Index** mp_join_ansindex724;  slog::Index** mp_joindelta725;  slog::Index** mbranchdelta726;  slog::Index** mbranchdelta727;  slog::Index** mp_mskdelta728;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord730({0, 1});
      slog::Relation* readrel731 = db->getRelation("mp_union_ans");
      head_index[0] = readrel731->getIndex(ord730, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord732({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel733 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index713 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({2, 4, 0, 1, 3});
      slog::Relation* readrel735 = db->getRelation("mp_join");
      mp_joinindex714 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({2, 4, 0, 1, 3});
      slog::Relation* readrel737 = db->getRelation("mp_join");
      mp_joindelta725 = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({0, 1, 2, 3, 4});
      slog::Relation* readrel739 = db->getRelation("mbranch");
      mbranchindex715 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({0, 1, 2, 3, 4});
      slog::Relation* readrel741 = db->getRelation("mbranch");
      mbranchindex716 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("mp_msk");
      mp_mskindex717 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("mp_join_ans");
      mp_join_ansindex718 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel747 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index719 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 2, 3, 4, 0});
      slog::Relation* readrel749 = db->getRelation("mbranch");
      mbranchindex720 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 3, 4, 0});
      slog::Relation* readrel751 = db->getRelation("mbranch");
      mbranchdelta726 = readrel751->getIndex(ord750, true);
      std::vector<u16> ord752({1, 2, 3, 4, 0});
      slog::Relation* readrel753 = db->getRelation("mbranch");
      mbranchindex721 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 3, 4, 0});
      slog::Relation* readrel755 = db->getRelation("mbranch");
      mbranchdelta727 = readrel755->getIndex(ord754, true);
      std::vector<u16> ord756({1, 2, 0});
      slog::Relation* readrel757 = db->getRelation("mp_msk");
      mp_mskindex722 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("mp_msk");
      mp_mskdelta728 = readrel759->getIndex(ord758, true);
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex723 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("mp_join_ans");
      mp_join_ansindex724 = readrel763->getIndex(ord762, false);
  
    }
    ReadTask729(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[1];
        u64 v_c116 = _t[2];
        if (!slog::exists_probe<11,3>($sup5638x101x0x0x0index713, std::array<u64,11>{v_c114, v_c115, v_c116, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex714, mp_joindelta725, std::array<u64,5>{v_c115, v_c116, 0, 0, 0}, [&](const std::array<u64,5>& m764) {
          u64 v_c117 = m764[2]; u64 v_c9 = m764[3]; u64 v_c22 = m764[4];
          if (!slog::exists_probe<5,2>(mbranchindex715, std::array<u64,5>{v_c115, v_c9, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex716, std::array<u64,5>{v_c116, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex717, std::array<u64,3>{v_c22, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex718, std::array<u64,2>{v_c117, 0})) return;
          slog::join_probe<11,5>($sup5638x101x0x0x0index719, std::array<u64,11>{v_c9, v_c22, v_c115, v_c116, v_c114, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m765) {
            u64 v_c7 = m765[5]; u64 v_c8 = m765[6]; u64 v_c24 = m765[7]; u64 v_c10 = m765[8]; u64 v_c25 = m765[9]; u64 v_c14 = m765[10];
            u64 v_c118 = _prim_lt(db, v_c24, v_c8);
            if (v_c118 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c118) return;
            slog::join_probe_old<5,5>(mbranchindex720, mbranchdelta726, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c115}, [&](const std::array<u64,5>& m767) {
              slog::join_probe_old<5,5>(mbranchindex721, mbranchdelta727, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, v_c116}, [&](const std::array<u64,5>& m768) {
                slog::join_probe_old<3,2>(mp_mskindex722, mp_mskdelta728, std::array<u64,3>{v_c22, v_c8, 0}, [&](const std::array<u64,3>& m769) {
                  u64 v_c119 = m769[2];
                  slog::join_probe<2,1>(mp_msk_ansindex723, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m770) {
                    u64 v_c17 = m770[1];
                    if (v_c9 == v_c17) return;
                    slog::join_probe<2,1>(mp_join_ansindex724, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m771) {
                      u64 v_c41 = m771[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c114, v_c41}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask729* _cont = new ReadTask729(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask729(db,b), false);
  // (crule (pre) (scan mp_union __t5xrH216 __t0o62217 __t0BoC218) (body (exists $sup5638x110x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t5xrH216 __t0o62217 __t0BoC218) (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t0o62217 __t0BoC218 __t7HEI219 p q) (exists mbranch (0 1 2 3 4) 2 __t0o62217 p) (exists mbranch (0 1 2 3 4) 2 __t0BoC218 q) (exists mp_msk (1 2 0) 1 p) (exists mp_join_ans (0 1) 1 __t7HEI219) (join $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t0o62217 __t0BoC218 __t5xrH216 l m n r u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0o62217) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t0BoC218) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t5IgR220) (join mp_msk_ans (0 1) 1 __t5IgR220 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t7HEI219 res)) (head (emit mp_union_ans (0 1) __t5xrH216 res)) map.slog:111 #f)
  class ReadTask788 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x110x0x0x0index772;  slog::Index** mp_joinindex773;  slog::Index** mbranchindex774;  slog::Index** mbranchindex775;  slog::Index** mp_mskindex776;  slog::Index** mp_join_ansindex777;  slog::Index** $sup5638x110x0x0x0index778;  slog::Index** mbranchindex779;  slog::Index** mbranchindex780;  slog::Index** mp_mskindex781;  slog::Index** mp_msk_ansindex782;  slog::Index** mp_join_ansindex783;  slog::Index** mp_joindelta784;  slog::Index** mbranchdelta785;  slog::Index** mbranchdelta786;  slog::Index** mp_mskdelta787;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord789({0, 1});
      slog::Relation* readrel790 = db->getRelation("mp_union_ans");
      head_index[0] = readrel790->getIndex(ord789, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord791({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel792 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index772 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({2, 4, 0, 1, 3});
      slog::Relation* readrel794 = db->getRelation("mp_join");
      mp_joinindex773 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({2, 4, 0, 1, 3});
      slog::Relation* readrel796 = db->getRelation("mp_join");
      mp_joindelta784 = readrel796->getIndex(ord795, true);
      std::vector<u16> ord797({0, 1, 2, 3, 4});
      slog::Relation* readrel798 = db->getRelation("mbranch");
      mbranchindex774 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({0, 1, 2, 3, 4});
      slog::Relation* readrel800 = db->getRelation("mbranch");
      mbranchindex775 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 2, 0});
      slog::Relation* readrel802 = db->getRelation("mp_msk");
      mp_mskindex776 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({0, 1});
      slog::Relation* readrel804 = db->getRelation("mp_join_ans");
      mp_join_ansindex777 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel806 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index778 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 2, 3, 4, 0});
      slog::Relation* readrel808 = db->getRelation("mbranch");
      mbranchindex779 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 2, 3, 4, 0});
      slog::Relation* readrel810 = db->getRelation("mbranch");
      mbranchdelta785 = readrel810->getIndex(ord809, true);
      std::vector<u16> ord811({1, 2, 3, 4, 0});
      slog::Relation* readrel812 = db->getRelation("mbranch");
      mbranchindex780 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 2, 3, 4, 0});
      slog::Relation* readrel814 = db->getRelation("mbranch");
      mbranchdelta786 = readrel814->getIndex(ord813, true);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("mp_msk");
      mp_mskindex781 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("mp_msk");
      mp_mskdelta787 = readrel818->getIndex(ord817, true);
      std::vector<u16> ord819({0, 1});
      slog::Relation* readrel820 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex782 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1});
      slog::Relation* readrel822 = db->getRelation("mp_join_ans");
      mp_join_ansindex783 = readrel822->getIndex(ord821, false);
  
    }
    ReadTask788(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c75 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c76 = _t[2];
        if (!slog::exists_probe<11,3>($sup5638x110x0x0x0index772, std::array<u64,11>{v_c75, v_c74, v_c76, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex773, mp_joindelta784, std::array<u64,5>{v_c74, v_c76, 0, 0, 0}, [&](const std::array<u64,5>& m823) {
          u64 v_c78 = m823[2]; u64 v_c9 = m823[3]; u64 v_c22 = m823[4];
          if (!slog::exists_probe<5,2>(mbranchindex774, std::array<u64,5>{v_c74, v_c9, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex775, std::array<u64,5>{v_c76, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex776, std::array<u64,3>{v_c9, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex777, std::array<u64,2>{v_c78, 0})) return;
          slog::join_probe<11,5>($sup5638x110x0x0x0index778, std::array<u64,11>{v_c9, v_c22, v_c74, v_c76, v_c75, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m824) {
            u64 v_c7 = m824[5]; u64 v_c8 = m824[6]; u64 v_c24 = m824[7]; u64 v_c10 = m824[8]; u64 v_c25 = m824[9]; u64 v_c14 = m824[10];
            u64 v_c120 = _prim_lt(db, v_c8, v_c24);
            if (v_c120 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c120) return;
            slog::join_probe_old<5,5>(mbranchindex779, mbranchdelta785, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c74}, [&](const std::array<u64,5>& m826) {
              slog::join_probe_old<5,5>(mbranchindex780, mbranchdelta786, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, v_c76}, [&](const std::array<u64,5>& m827) {
                slog::join_probe_old<3,2>(mp_mskindex781, mp_mskdelta787, std::array<u64,3>{v_c9, v_c24, 0}, [&](const std::array<u64,3>& m828) {
                  u64 v_c79 = m828[2];
                  slog::join_probe<2,1>(mp_msk_ansindex782, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m829) {
                    u64 v_c17 = m829[1];
                    if (v_c22 == v_c17) return;
                    slog::join_probe<2,1>(mp_join_ansindex783, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m830) {
                      u64 v_c41 = m830[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c75, v_c41}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask788* _cont = new ReadTask788(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask788(db,b), false);
  // (crule (pre) (scan mbranch __t0fD4327 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t0fD4327 k __t070u328)) (head (emit $sup5638x59x0x0x0 (0 1 2 3 4 5) __t070u328 k l m p r)) map.slog:60 #f)
  class ReadTask833 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index831;  slog::Index** mp_has0delta832;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord834({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel835 = db->getRelation("$sup5638x59x0x0x0");
      head_index[0] = readrel835->getIndex(ord834, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord836({1, 2, 0});
      slog::Relation* readrel837 = db->getRelation("mp_has0");
      mp_has0index831 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("mp_has0");
      mp_has0delta832 = readrel839->getIndex(ord838, true);
  
    }
    ReadTask833(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c10 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index831, mp_has0delta832, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m840) {
          u64 v_c6 = m840[1]; u64 v_c122 = m840[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c122, v_c6, v_c7, v_c8, v_c9, v_c10}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask833* _cont = new ReadTask833(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask833(db,b), false);
  // (crule (pre) (scan temp8fvz1067 __t6LFp12 k v) (body (join mleaf (1 2 0) 2 k v __t2ggE10)) (head (emit mp_put_ans (0 1) __t6LFp12 __t2ggE10)) map.slog:37 #f)
  class ReadTask842 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex841;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord843({0, 1});
      slog::Relation* readrel844 = db->getRelation("mp_put_ans");
      head_index[0] = readrel844->getIndex(ord843, false);
      outer_rel = db->getRelation("temp8fvz1067");
      std::vector<u16> ord845({1, 2, 0});
      slog::Relation* readrel846 = db->getRelation("mleaf");
      mleafindex841 = readrel846->getIndex(ord845, false);
  
    }
    ReadTask842(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe<3,2>(mleafindex841, std::array<u64,3>{v_c6, v_c14, 0}, [&](const std::array<u64,3>& m847) {
          u64 v_c124 = m847[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c123, v_c124}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:37", "delta:temp8fvz1067", _fires);
  
      if (!_done)
      {
        ReadTask842* _cont = new ReadTask842(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask842(db,b), false);
  // (crule (pre) (scan mp_join __t35Cd377 p __t8hMI375 q __t5XzA376) (body (exists mbranch (0 1 2 3 4) 2 __t8hMI375 p) (exists mbranch (0 1 2 3 4) 2 __t5XzA376 q) (exists mp_union (1 2 0) 2 __t8hMI375 __t5XzA376) (exists mp_msk (1 2 0) 1 q) (exists mp_join_ans (0 1) 1 __t35Cd377) (join $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t8hMI375 __t5XzA376 __t4ZhK374 l m n r u v) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 p m l r __t8hMI375) (join mbranch (1 2 3 4 0) 5 q n u v __t5XzA376) (join mp_union (0 1 2) 3 __t4ZhK374 __t8hMI375 __t5XzA376) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t0M9S378) (join mp_msk_ans (0 1) 1 __t0M9S378 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t35Cd377 res)) (head (emit mp_union_ans (0 1) __t4ZhK374 res)) map.slog:102 #f)
  class ReadTask861 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex848;  slog::Index** mbranchindex849;  slog::Index** mp_unionindex850;  slog::Index** mp_mskindex851;  slog::Index** mp_join_ansindex852;  slog::Index** $sup5638x101x0x0x0index853;  slog::Index** mbranchindex854;  slog::Index** mbranchindex855;  slog::Index** mp_unionindex856;  slog::Index** mp_mskindex857;  slog::Index** mp_msk_ansindex858;  slog::Index** mp_join_ansindex859;  slog::Index** mp_mskdelta860;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord862({0, 1});
      slog::Relation* readrel863 = db->getRelation("mp_union_ans");
      head_index[0] = readrel863->getIndex(ord862, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord864({0, 1, 2, 3, 4});
      slog::Relation* readrel865 = db->getRelation("mbranch");
      mbranchindex848 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1, 2, 3, 4});
      slog::Relation* readrel867 = db->getRelation("mbranch");
      mbranchindex849 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({1, 2, 0});
      slog::Relation* readrel869 = db->getRelation("mp_union");
      mp_unionindex850 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({1, 2, 0});
      slog::Relation* readrel871 = db->getRelation("mp_msk");
      mp_mskindex851 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({0, 1});
      slog::Relation* readrel873 = db->getRelation("mp_join_ans");
      mp_join_ansindex852 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel875 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index853 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 2, 3, 4, 0});
      slog::Relation* readrel877 = db->getRelation("mbranch");
      mbranchindex854 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({1, 2, 3, 4, 0});
      slog::Relation* readrel879 = db->getRelation("mbranch");
      mbranchindex855 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({0, 1, 2});
      slog::Relation* readrel881 = db->getRelation("mp_union");
      mp_unionindex856 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 0});
      slog::Relation* readrel883 = db->getRelation("mp_msk");
      mp_mskindex857 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("mp_msk");
      mp_mskdelta860 = readrel885->getIndex(ord884, true);
      std::vector<u16> ord886({0, 1});
      slog::Relation* readrel887 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex858 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({0, 1});
      slog::Relation* readrel889 = db->getRelation("mp_join_ans");
      mp_join_ansindex859 = readrel889->getIndex(ord888, false);
  
    }
    ReadTask861(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c117 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c115 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c116 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex848, std::array<u64,5>{v_c115, v_c9, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex849, std::array<u64,5>{v_c116, v_c22, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex850, std::array<u64,3>{v_c115, v_c116, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex851, std::array<u64,3>{v_c22, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex852, std::array<u64,2>{v_c117, 0})) return;
        slog::join_probe<11,4>($sup5638x101x0x0x0index853, std::array<u64,11>{v_c9, v_c22, v_c115, v_c116, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m890) {
          u64 v_c114 = m890[4]; u64 v_c7 = m890[5]; u64 v_c8 = m890[6]; u64 v_c24 = m890[7]; u64 v_c10 = m890[8]; u64 v_c25 = m890[9]; u64 v_c14 = m890[10];
          u64 v_c125 = _prim_lt(db, v_c24, v_c8);
          if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c125) return;
          slog::join_probe<5,5>(mbranchindex854, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, v_c115}, [&](const std::array<u64,5>& m892) {
            slog::join_probe<5,5>(mbranchindex855, std::array<u64,5>{v_c22, v_c24, v_c25, v_c14, v_c116}, [&](const std::array<u64,5>& m893) {
              slog::join_probe<3,3>(mp_unionindex856, std::array<u64,3>{v_c114, v_c115, v_c116}, [&](const std::array<u64,3>& m894) {
                slog::join_probe_old<3,2>(mp_mskindex857, mp_mskdelta860, std::array<u64,3>{v_c22, v_c8, 0}, [&](const std::array<u64,3>& m895) {
                  u64 v_c119 = m895[2];
                  slog::join_probe<2,1>(mp_msk_ansindex858, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m896) {
                    u64 v_c17 = m896[1];
                    if (v_c9 == v_c17) return;
                    slog::join_probe<2,1>(mp_join_ansindex859, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m897) {
                      u64 v_c41 = m897[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c114, v_c41}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask861* _cont = new ReadTask861(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask861(db,b), false);
  // (crule (pre (let __tconst0PwW227 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t22eB226 __t8dlF225 k) (body (join mbranch (0 1 2 3 4) 1 __t8dlF225 p m l r) (let __t6Vmq228 (band k m)) (cmp gt __t6Vmq228 __tconst0PwW227)) (head (emit $sup5638x62x0x0x0 (4 2 3 5 0 1) p l m r __t22eB226 k)) map.slog:63 #f)
  class ReadTask899 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex898;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord900({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel901 = db->getRelation("$sup5638x62x0x0x0");
      head_index[0] = readrel901->getIndex(ord900, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord902({0, 1, 2, 3, 4});
      slog::Relation* readrel903 = db->getRelation("mbranch");
      mbranchindex898 = readrel903->getIndex(ord902, false);
  
    }
    ReadTask899(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c6 = _t[2];
        slog::join_probe<5,1>(mbranchindex898, std::array<u64,5>{v_c128, 0, 0, 0, 0}, [&](const std::array<u64,5>& m904) {
          u64 v_c9 = m904[1]; u64 v_c8 = m904[2]; u64 v_c7 = m904[3]; u64 v_c10 = m904[4];
          u64 v_c129 = _prim_band(db, v_c6, v_c8);
          if (v_c129 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          u64 v_c130 = _prim_gt(db, v_c129, v_c126);
          if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          if (!v_c130) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c9, v_c7, v_c8, v_c10, v_c127, v_c6}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask899* _cont = new ReadTask899(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask899(db,b), false);
  // (crule (pre (let __tconst03XK425 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t63mh424 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t63mh424 __t5o85423) (join $sup5638x29x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t2zZo426 (band p0 __v0)) (cmp gt __t2zZo426 __tconst03XK425) (let chk27VD1062 (bxor p0 p1)) (eq __t5o85423 chk27VD1062)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t63mh424 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask909 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex906;  slog::Index** $sup5638x29x0x0x0index907;  slog::Index** mp_hsbdelta908;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord910({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel911 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel911->getIndex(ord910, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord912({0, 1});
      slog::Relation* readrel913 = db->getRelation("mp_hsb");
      mp_hsbindex906 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({0, 1});
      slog::Relation* readrel915 = db->getRelation("mp_hsb");
      mp_hsbdelta908 = readrel915->getIndex(ord914, true);
      std::vector<u16> ord916({1, 0, 2, 3, 4});
      slog::Relation* readrel917 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index907 = readrel917->getIndex(ord916, false);
  
    }
    ReadTask909(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c131 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c132 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex906, mp_hsbdelta908, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m918) {
          u64 v_c133 = m918[1];
          slog::join_all<5>($sup5638x29x0x0x0index907, [&](const std::array<u64,5>& m919) {
            u64 v_c99 = m919[0]; u64 v_c5 = m919[1]; u64 v_c100 = m919[2]; u64 v_c101 = m919[3]; u64 v_c102 = m919[4];
            u64 v_c134 = _prim_band(db, v_c99, v_c17);
            if (v_c134 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c135 = _prim_gt(db, v_c134, v_c131);
            if (v_c135 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c135) return;
            u64 v_c136 = _prim_bxor(db, v_c99, v_c100);
            if (v_c136 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (v_c133 != v_c136) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c132, v_c17, v_c5, v_c99, v_c100, v_c101, v_c102}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask909* _cont = new ReadTask909(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask909(db,b), false);
  // (crule (pre (let __tconst1GO9299 const5feceb66ffc86f38d952786c)) (scan $sup5638x59x0x0x0 __t0IP7301 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t0IP7301 k) (exists mp_msk (1 2 0) 2 k m) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8ocD300) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t0IP7301 k __t8ocD300) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6Y68302) (join mp_msk_ans (0 1) 1 __t6Y68302 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t0IP7301 __tconst1GO9299)) map.slog:60 #f)
  class ReadTask930 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index921;  slog::Index** mp_mskindex922;  slog::Index** mbranchindex923;  slog::Index** mp_has0index924;  slog::Index** mp_mskindex925;  slog::Index** mp_msk_ansindex926;  slog::Index** mbranchdelta927;  slog::Index** mp_has0delta928;  slog::Index** mp_mskdelta929;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord931({0, 1});
      slog::Relation* readrel932 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel932->getIndex(ord931, false);
      outer_rel = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord933({0, 2, 1});
      slog::Relation* readrel934 = db->getRelation("mp_has0");
      mp_has0index921 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 2, 0});
      slog::Relation* readrel936 = db->getRelation("mp_msk");
      mp_mskindex922 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 2, 3, 4, 0});
      slog::Relation* readrel938 = db->getRelation("mbranch");
      mbranchindex923 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 2, 3, 4, 0});
      slog::Relation* readrel940 = db->getRelation("mbranch");
      mbranchdelta927 = readrel940->getIndex(ord939, true);
      std::vector<u16> ord941({0, 2, 1});
      slog::Relation* readrel942 = db->getRelation("mp_has0");
      mp_has0index924 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({0, 2, 1});
      slog::Relation* readrel944 = db->getRelation("mp_has0");
      mp_has0delta928 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("mp_msk");
      mp_mskindex925 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("mp_msk");
      mp_mskdelta929 = readrel948->getIndex(ord947, true);
      std::vector<u16> ord949({0, 1});
      slog::Relation* readrel950 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex926 = readrel950->getIndex(ord949, false);
  
    }
    ReadTask930(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c138 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index921, std::array<u64,3>{v_c138, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex922, std::array<u64,3>{v_c6, v_c8, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex923, mbranchdelta927, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m951) {
          u64 v_c139 = m951[4];
          slog::join_probe_old<3,3>(mp_has0index924, mp_has0delta928, std::array<u64,3>{v_c138, v_c6, v_c139}, [&](const std::array<u64,3>& m952) {
            slog::join_probe_old<3,2>(mp_mskindex925, mp_mskdelta929, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m953) {
              u64 v_c140 = m953[2];
              slog::join_probe<2,1>(mp_msk_ansindex926, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m954) {
                u64 v_c17 = m954[1];
                if (v_c9 == v_c17) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c138, v_c137}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:$sup5638x59x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask930* _cont = new ReadTask930(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask930(db,b), false);
  // (crule (pre) (scan mp_union_ans __t2Oaj263 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t2Oaj263 l u) (exists mbranch (3 0 1 2 4) 1 u) (exists mbranch (3 0 1 2 4) 1 l) (join-old $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 (1 5 0 2 3 4 6) l u __t9rnk262 m p r v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t5rXw260) (exists mp_union (2 0 1) 2 __t5rXw260 __t9rnk262) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2wpn261) (join-old mp_union (0 1 2) 3 (0 1 2) __t9rnk262 __t2wpn261 __t5rXw260) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t0Kdo264) (join-old mp_union_ans (0 1) 1 (0 1) __t0Kdo264 __v1)) (head (emit-temp temp2ytq1023 __t9rnk262 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t2msK259 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask974 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex955;  slog::Index** mbranchindex956;  slog::Index** mbranchindex957;  slog::Index** $sup5638x93x0x0x0index958;  slog::Index** mbranchindex959;  slog::Index** mp_unionindex960;  slog::Index** mbranchindex961;  slog::Index** mp_unionindex962;  slog::Index** mbranchindex963;  slog::Index** mp_unionindex964;  slog::Index** mp_unionindex965;  slog::Index** mp_union_ansindex966;  slog::Index** mp_uniondelta967;  slog::Index** $sup5638x93x0x0x0delta968;  slog::Index** mbranchdelta969;  slog::Index** mbranchdelta970;  slog::Index** mp_uniondelta971;  slog::Index** mp_uniondelta972;  slog::Index** mp_union_ansdelta973;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ytq1023");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord975({0, 1, 2});
      slog::Relation* readrel976 = db->getRelation("mp_union");
      mp_unionindex955 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({0, 1, 2});
      slog::Relation* readrel978 = db->getRelation("mp_union");
      mp_uniondelta967 = readrel978->getIndex(ord977, true);
      std::vector<u16> ord979({3, 0, 1, 2, 4});
      slog::Relation* readrel980 = db->getRelation("mbranch");
      mbranchindex956 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({3, 0, 1, 2, 4});
      slog::Relation* readrel982 = db->getRelation("mbranch");
      mbranchindex957 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel984 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index958 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel986 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0delta968 = readrel986->getIndex(ord985, true);
      std::vector<u16> ord987({1, 2, 3, 4, 0});
      slog::Relation* readrel988 = db->getRelation("mbranch");
      mbranchindex959 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 2, 0});
      slog::Relation* readrel990 = db->getRelation("mp_union");
      mp_unionindex960 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 2, 3, 4, 0});
      slog::Relation* readrel992 = db->getRelation("mbranch");
      mbranchindex961 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 2, 3, 4, 0});
      slog::Relation* readrel994 = db->getRelation("mbranch");
      mbranchdelta969 = readrel994->getIndex(ord993, true);
      std::vector<u16> ord995({2, 0, 1});
      slog::Relation* readrel996 = db->getRelation("mp_union");
      mp_unionindex962 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 2, 3, 4, 0});
      slog::Relation* readrel998 = db->getRelation("mbranch");
      mbranchindex963 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 2, 3, 4, 0});
      slog::Relation* readrel1000 = db->getRelation("mbranch");
      mbranchdelta970 = readrel1000->getIndex(ord999, true);
      std::vector<u16> ord1001({0, 1, 2});
      slog::Relation* readrel1002 = db->getRelation("mp_union");
      mp_unionindex964 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({0, 1, 2});
      slog::Relation* readrel1004 = db->getRelation("mp_union");
      mp_uniondelta971 = readrel1004->getIndex(ord1003, true);
      std::vector<u16> ord1005({1, 2, 0});
      slog::Relation* readrel1006 = db->getRelation("mp_union");
      mp_unionindex965 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("mp_union");
      mp_uniondelta972 = readrel1008->getIndex(ord1007, true);
      std::vector<u16> ord1009({0, 1});
      slog::Relation* readrel1010 = db->getRelation("mp_union_ans");
      mp_union_ansindex966 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({0, 1});
      slog::Relation* readrel1012 = db->getRelation("mp_union_ans");
      mp_union_ansdelta973 = readrel1012->getIndex(ord1011, true);
  
    }
    ReadTask974(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex955, mp_uniondelta967, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m1013) {
          u64 v_c7 = m1013[1]; u64 v_c25 = m1013[2];
          if (!slog::exists_probe<5,1>(mbranchindex956, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex957, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup5638x93x0x0x0index958, $sup5638x93x0x0x0delta968, std::array<u64,7>{v_c7, v_c25, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1014) {
            u64 v_c53 = m1014[2]; u64 v_c8 = m1014[3]; u64 v_c9 = m1014[4]; u64 v_c10 = m1014[5]; u64 v_c14 = m1014[6];
            if (!slog::exists_probe<5,4>(mbranchindex959, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex960, std::array<u64,3>{v_c10, v_c14, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex961, mbranchdelta969, std::array<u64,5>{v_c9, v_c8, v_c25, v_c14, 0}, [&](const std::array<u64,5>& m1015) {
              u64 v_c52 = m1015[4];
              if (!slog::exists_probe<3,2>(mp_unionindex962, std::array<u64,3>{v_c52, v_c53, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex963, mbranchdelta970, std::array<u64,5>{v_c9, v_c8, v_c7, v_c10, 0}, [&](const std::array<u64,5>& m1016) {
                u64 v_c54 = m1016[4];
                slog::join_probe_old<3,3>(mp_unionindex964, mp_uniondelta971, std::array<u64,3>{v_c53, v_c54, v_c52}, [&](const std::array<u64,3>& m1017) {
                  slog::join_probe_old<3,2>(mp_unionindex965, mp_uniondelta972, std::array<u64,3>{v_c10, v_c14, 0}, [&](const std::array<u64,3>& m1018) {
                    u64 v_c56 = m1018[2];
                    slog::join_probe_old<2,1>(mp_union_ansindex966, mp_union_ansdelta973, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m1019) {
                      u64 v_c57 = m1019[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c53, v_c17, v_c57, v_c8, v_c9});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c8, v_c17, v_c57}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask974* _cont = new ReadTask974(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask974(db,b), false);
}

