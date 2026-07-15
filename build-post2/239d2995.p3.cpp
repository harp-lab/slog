
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const721c36ff691f951d83718d83;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constfee494ff4827aeb0635bb714;
extern u64 v_constff5a1ae012afa5d4c889c50a;


void slog_rules_cae5e53883d639a44(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9clk144 const6b86b273ff34fce19d6b804e)) (probe mp_hsb (1 0) 1 __tconst9clk144 __t4eDN145) (body) (head (emit mp_hsb_ans (0 1) __t4eDN145 __tconst9clk144)) map.slog:18 #f)
  class ReadTask0 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("mp_hsb_ans");
      head_index[0] = readrel2->getIndex(ord1, false);
      std::vector<u16> ord3({1, 0});
      slog::Relation* readrel4 = db->getRelation("mp_hsb");
      driver_index = readrel4->getIndex(ord3, true);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m5) {
        u64 v_c1 = m5[1];
        if (buckethash(v_c1) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c0}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:18", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre (let __trid2hJI853 constfee494ff4827aeb0635bb714) (let __trel0l7X854 const20347926ddb307a8e2bdb71b) (let __tcol3G8h855 constd4735e3a265e16eee03f5971)) (scan mp_del_ans __t4tTw258 __v0) (body (join-old mp_del (0 2 1) 1 (0 2 1) __t4tTw258 k r) (exists mp_msk (1 2 0) 1 k) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t1DER257) (join mp_msk_ans (0 1) 2 __t1DER257 p)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2hJI853 __trel0l7X854 __tcol3G8h855 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __5v59852 p m l __v0)) map.slog:85 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex6;  slog::Index** mp_mskindex7;  slog::Index** $sup5638x84x0x0x0index8;  slog::Index** mp_msk_ansindex9;  slog::Index** mp_mskindex10;  slog::Index** mp_msk_ansindex11;  slog::Index** mp_deldelta12;  slog::Index** mp_mskdelta13;
    u32 sid15;  u32 sid14;  u32 sid16;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord18({0, 2, 1});
      slog::Relation* readrel19 = db->getRelation("mp_del");
      mp_delindex6 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 2, 1});
      slog::Relation* readrel21 = db->getRelation("mp_del");
      mp_deldelta12 = readrel21->getIndex(ord20, true);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("mp_msk");
      mp_mskindex7 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel25 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index8 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex9 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 2, 0});
      slog::Relation* readrel29 = db->getRelation("mp_msk");
      mp_mskindex10 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("mp_msk");
      mp_mskdelta13 = readrel31->getIndex(ord30, true);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex11 = readrel33->getIndex(ord32, false);
      sid15 = db->getRelation("_enum")->getStructId();
      sid14 = db->getRelation("mbranch")->getStructId();
      sid16 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_constfee494ff4827aeb0635bb714;
      u64 v_c3 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
  
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
        slog::join_probe_old<3,1>(mp_delindex6, mp_deldelta12, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m34) {
          u64 v_c7 = m34[1]; u64 v_c8 = m34[2];
          if (!slog::exists_probe<3,1>(mp_mskindex7, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x84x0x0x0index8, std::array<u64,6>{v_c7, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m35) {
            u64 v_c9 = m35[2]; u64 v_c10 = m35[3]; u64 v_c11 = m35[4]; u64 v_c12 = m35[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex9, std::array<u64,2>{v_c12, 0})) return;
            slog::join_probe_old<3,2>(mp_mskindex10, mp_mskdelta13, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m36) {
              u64 v_c13 = m36[2];
              slog::join_probe<2,2>(mp_msk_ansindex11, std::array<u64,2>{v_c13, v_c12}, [&](const std::array<u64,2>& m37) {
                ++_fires;
                if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid14 || decode_struct_id(v_c10) == sid15 || decode_struct_id(v_c10) == sid16))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c2, v_c3, v_c4, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c12, v_c11, v_c10, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask17* _cont = new ReadTask17(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), false);
  // (crule (pre (let __tconst03sd851 constd01925b37634a1a9d24159d8) (let __tconst3k9477 constff5a1ae012afa5d4c889c50a) (let __tconst1tgO78 const7902699be42c8a8e46fbbb45) (let __tconst2cGK81 const624b60c58c9d8bfb6ff1886c) (let __tconst35sq82 const4e07408562bedb8b60ce05c1) (let __tconst4DUy84 const4a44dc15364204a80fe80e90) (let __tconst2ARJ85 const6b86b273ff34fce19d6b804e)) (probe mp_put (2 3 0 1) 2 __tconst2ARJ85 __tconst4DUy84 __t9RS986 __v1) (body (exists _enum (1 0) 1 __tconst03sd851) (exists mp_put (2 3 0 1) 2 __tconst35sq82 __tconst2cGK81) (exists mp_put_ans (1 0) 1 __v1) (exists mp_put_ans (0 1) 1 __t9RS986) (join mp_put (2 3 0 1) 2 __tconst1tgO78 __tconst3k9477 __t0yI380 __t0J6w79) (join _enum (0 1) 2 __t0J6w79 __tconst03sd851) (exists mp_put_ans (0 1) 1 __t0yI380) (join mp_put (2 3 0 1) 2 __tconst35sq82 __tconst2cGK81 __t1P9g83 __v0) (join mp_put_ans (0 1) 2 __t0yI380 __v0) (join mp_put_ans (0 1) 2 __t1P9g83 __v1) (join mp_put_ans (0 1) 1 __t9RS986 r)) (head (emit canon (0) r)) mp_basic.slog:14 #f)
  class ReadTask49 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex38;  slog::Index** mp_putindex39;  slog::Index** mp_put_ansindex40;  slog::Index** mp_put_ansindex41;  slog::Index** mp_putindex42;  slog::Index** _enumindex43;  slog::Index** mp_put_ansindex44;  slog::Index** mp_putindex45;  slog::Index** mp_put_ansindex46;  slog::Index** mp_put_ansindex47;  slog::Index** mp_put_ansindex48;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord50({0});
      slog::Relation* readrel51 = db->getRelation("canon");
      head_index[0] = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({2, 3, 0, 1});
      slog::Relation* readrel53 = db->getRelation("mp_put");
      driver_index = readrel53->getIndex(ord52, true);
      std::vector<u16> ord54({1, 0});
      slog::Relation* readrel55 = db->getRelation("_enum");
      _enumindex38 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({2, 3, 0, 1});
      slog::Relation* readrel57 = db->getRelation("mp_put");
      mp_putindex39 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("mp_put_ans");
      mp_put_ansindex40 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({0, 1});
      slog::Relation* readrel61 = db->getRelation("mp_put_ans");
      mp_put_ansindex41 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({2, 3, 0, 1});
      slog::Relation* readrel63 = db->getRelation("mp_put");
      mp_putindex42 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("_enum");
      _enumindex43 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("mp_put_ans");
      mp_put_ansindex44 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({2, 3, 0, 1});
      slog::Relation* readrel69 = db->getRelation("mp_put");
      mp_putindex45 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("mp_put_ans");
      mp_put_ansindex46 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("mp_put_ans");
      mp_put_ansindex47 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0, 1});
      slog::Relation* readrel75 = db->getRelation("mp_put_ans");
      mp_put_ansindex48 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask49(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constd01925b37634a1a9d24159d8;
      u64 v_c15 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c16 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c17 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c18 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c19 = v_const4a44dc15364204a80fe80e90;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c20, v_c19, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m76) {
        u64 v_c21 = m76[2];
        u64 v_c22 = m76[3];
        if (buckethash(v_c21) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex38, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex39, std::array<u64,4>{v_c18, v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex40, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex41, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<4,2>(mp_putindex42, std::array<u64,4>{v_c16, v_c15, 0, 0}, [&](const std::array<u64,4>& m77) {
          u64 v_c23 = m77[2]; u64 v_c24 = m77[3];
          slog::join_probe<2,2>(_enumindex43, std::array<u64,2>{v_c24, v_c14}, [&](const std::array<u64,2>& m78) {
            if (!slog::exists_probe<2,1>(mp_put_ansindex44, std::array<u64,2>{v_c23, 0})) return;
            slog::join_probe<4,2>(mp_putindex45, std::array<u64,4>{v_c18, v_c17, 0, 0}, [&](const std::array<u64,4>& m79) {
              u64 v_c25 = m79[2]; u64 v_c6 = m79[3];
              slog::join_probe<2,2>(mp_put_ansindex46, std::array<u64,2>{v_c23, v_c6}, [&](const std::array<u64,2>& m80) {
                slog::join_probe<2,2>(mp_put_ansindex47, std::array<u64,2>{v_c25, v_c22}, [&](const std::array<u64,2>& m81) {
                  slog::join_probe<2,1>(mp_put_ansindex48, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m82) {
                    u64 v_c8 = m82[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
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
        ReadTask49* _cont = new ReadTask49(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask49(db,b), false);
  // (crule (pre (let __trid8kcN573 const721c36ff691f951d83718d83) (let __trel2a8j574 constdd7bbf31ce5f578b9805e840) (let __tcol60mN575 const5feceb66ffc86f38d952786c) (let __trel960A576 constdd7bbf31ce5f578b9805e840) (let __tcol8Llp577 const6b86b273ff34fce19d6b804e)) (scan $sup5638x81x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid8kcN573 __trel2a8j574 __tcol60mN575 (1 2 3 4 0)) (tycheck m (accept int) __trid8kcN573 __trel960A576 __tcol8Llp577 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __3qov572 k m)) map.slog:82 #f)
  class ReadTask83 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x81x0x0x0");
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const721c36ff691f951d83718d83;
      u64 v_c27 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c8 = _t[5];
        ++_fires;
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c26, v_c27, v_c28, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c11)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c26, v_c29, v_c30, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c7, v_c11}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:$sup5638x81x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x1 __t4lFL393 __t1lh0397 __v0 p0 p1 t0 t1) (body (exists $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t4lFL393 p1 t0 t1) (exists mp_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t4lFL393) (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists mp_hsb_ans (0 1) 2 __t1lh0397 __v0) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0 dup0XDZ1075 dup8FhK1076 __v1 __v3) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join-old $sup5638x29x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t4lFL393 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join-old mp_msk_ans (0 1) 1 (0 1) __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x0index84;  slog::Index** mp_joinindex85;  slog::Index** mp_hsb_ansindex86;  slog::Index** mp_hsb_ansindex87;  slog::Index** mp_mskindex88;  slog::Index** $sup5638x29x0x0x2index89;  slog::Index** $sup5638x29x0x0x0index90;  slog::Index** mp_joinindex91;  slog::Index** mp_hsb_ansindex92;  slog::Index** mp_hsb_ansindex93;  slog::Index** mp_hsb_ansindex94;  slog::Index** mp_mskindex95;  slog::Index** mp_msk_ansindex96;  slog::Index** mp_hsbindex97;  slog::Index** $sup5638x29x0x0x0delta98;  slog::Index** mp_joindelta99;  slog::Index** mp_hsb_ansdelta100;  slog::Index** mp_hsb_ansdelta101;  slog::Index** mp_hsb_ansdelta102;  slog::Index** mp_mskdelta103;  slog::Index** mp_msk_ansdelta104;  slog::Index** mp_hsbdelta105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord107({1, 0, 2, 3, 4});
      slog::Relation* readrel108 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index84 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 3, 4, 0});
      slog::Relation* readrel110 = db->getRelation("mp_join");
      mp_joinindex85 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex86 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex87 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("mp_msk");
      mp_mskindex88 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel118 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index89 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 0, 2, 3, 4});
      slog::Relation* readrel120 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index90 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 0, 2, 3, 4});
      slog::Relation* readrel122 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0delta98 = readrel122->getIndex(ord121, true);
      std::vector<u16> ord123({1, 2, 3, 4, 0});
      slog::Relation* readrel124 = db->getRelation("mp_join");
      mp_joinindex91 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 3, 4, 0});
      slog::Relation* readrel126 = db->getRelation("mp_join");
      mp_joindelta99 = readrel126->getIndex(ord125, true);
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex92 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta100 = readrel130->getIndex(ord129, true);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex93 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta101 = readrel134->getIndex(ord133, true);
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex94 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta102 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("mp_msk");
      mp_mskindex95 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("mp_msk");
      mp_mskdelta103 = readrel142->getIndex(ord141, true);
      std::vector<u16> ord143({0, 1});
      slog::Relation* readrel144 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex96 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta104 = readrel146->getIndex(ord145, true);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("mp_hsb");
      mp_hsbindex97 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("mp_hsb");
      mp_hsbdelta105 = readrel150->getIndex(ord149, true);
  
    }
    ReadTask106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c35 = _t[4];
        u64 v_c36 = _t[5];
        u64 v_c37 = _t[6];
        if (!slog::exists_probe<5,5>($sup5638x29x0x0x0index84, std::array<u64,5>{v_c34, v_c32, v_c35, v_c36, v_c37})) return;
        if (!slog::exists_probe<5,5>(mp_joinindex85, std::array<u64,5>{v_c34, v_c36, v_c35, v_c37, v_c32})) return;
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex86, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,2>(mp_hsb_ansindex87, std::array<u64,2>{v_c33, v_c6})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex88, std::array<u64,3>{v_c34, 0, 0})) return;
        slog::join_probe<11,7>($sup5638x29x0x0x2index89, std::array<u64,11>{v_c32, v_c34, v_c35, v_c36, v_c37, v_c33, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,11>& m151) {
          u64 v_c38 = m151[7]; u64 v_c39 = m151[8]; u64 v_c22 = m151[9]; u64 v_c40 = m151[10];
          if (v_c33 != v_c39) return;
          if (v_c33 != v_c38) return;
          slog::join_probe_old<5,5>($sup5638x29x0x0x0index90, $sup5638x29x0x0x0delta98, std::array<u64,5>{v_c34, v_c32, v_c35, v_c36, v_c37}, [&](const std::array<u64,5>& m152) {
            slog::join_probe_old<5,5>(mp_joinindex91, mp_joindelta99, std::array<u64,5>{v_c34, v_c36, v_c35, v_c37, v_c32}, [&](const std::array<u64,5>& m153) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex92, mp_hsb_ansdelta100, std::array<u64,2>{v_c33, v_c40}, [&](const std::array<u64,2>& m154) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex93, mp_hsb_ansdelta101, std::array<u64,2>{v_c33, v_c22}, [&](const std::array<u64,2>& m155) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex94, mp_hsb_ansdelta102, std::array<u64,2>{v_c33, v_c6}, [&](const std::array<u64,2>& m156) {
                    slog::join_probe_old<3,2>(mp_mskindex95, mp_mskdelta103, std::array<u64,3>{v_c34, v_c22, 0}, [&](const std::array<u64,3>& m157) {
                      u64 v_c41 = m157[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex96, mp_msk_ansdelta104, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m158) {
                        u64 v_c42 = m158[1];
                        u64 v_c43 = _prim_bxor(db, v_c34, v_c35);
                        if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex97, mp_hsbdelta105, std::array<u64,2>{v_c33, v_c43}, [&](const std::array<u64,2>& m159) {
                          u64 v_c44 = _prim_band(db, v_c34, v_c6);
                          if (v_c44 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c45 = _prim_gt(db, v_c44, v_c31);
                          if (v_c45 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c45) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c32, v_c42, v_c40, v_c36, v_c37});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c42, v_c40, v_c37, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask106* _cont = new ReadTask106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask106(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t185P265 p) (body (exists $sup5638x95x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t185P265 q m) (join $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t185P265 m n p q r u v)) map.slog:96 #f)
  class ReadTask165 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index161;  slog::Index** mp_mskindex162;  slog::Index** $sup5638x95x0x0x0index163;  slog::Index** mp_mskdelta164;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord166({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel167 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel167->getIndex(ord166, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord168({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel169 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index161 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({0, 1, 2});
      slog::Relation* readrel171 = db->getRelation("mp_msk");
      mp_mskindex162 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 1, 2});
      slog::Relation* readrel173 = db->getRelation("mp_msk");
      mp_mskdelta164 = readrel173->getIndex(ord172, true);
      std::vector<u16> ord174({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel175 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index163 = readrel175->getIndex(ord174, false);
  
    }
    ReadTask165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index161, std::array<u64,9>{v_c12, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex162, mp_mskdelta164, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m176) {
          u64 v_c47 = m176[1]; u64 v_c11 = m176[2];
          slog::join_probe<9,3>($sup5638x95x0x0x0index163, std::array<u64,9>{v_c11, v_c47, v_c12, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m177) {
            u64 v_c9 = m177[3]; u64 v_c10 = m177[4]; u64 v_c48 = m177[5]; u64 v_c8 = m177[6]; u64 v_c49 = m177[7]; u64 v_c50 = m177[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c9, v_c10, v_c46, v_c11, v_c48, v_c12, v_c47, v_c8, v_c49, v_c50}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask165* _cont = new ReadTask165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask165(db,b), false);
  // (crule (pre (let __tconst7awV353 const5feceb66ffc86f38d952786c)) (scan $sup5638x107x0x0x1 __t05l7352 __t4mLe355 l m n p q r u v) (body (cmp lt m n) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t05l7352 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 3 p n __t4mLe355) (exists mp_msk_ans (0 1) 2 __t4mLe355 q) (exists mp_union (2 0 1) 1 v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3rQ8350) (exists mp_union (2 0 1) 2 __t3rQ8350 __t05l7352) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6yxH356) (join-old mp_union (0 1 2) 3 (0 1 2) __t05l7352 __t6yxH356 __t3rQ8350) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t4mLe355) (join mp_msk_ans (0 1) 2 __t4mLe355 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t6yxH356 v __t9WRQ357) (join mp_union_ans (0 1) 1 __t9WRQ357 __v0) (let __t80v6354 (band p n)) (cmp gt __t80v6354 __tconst7awV353)) (head (emit-temp temp9B581035 __t05l7352 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t3dsi349 q n u __v0)) map.slog:108 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index178;  slog::Index** mbranchindex179;  slog::Index** mp_mskindex180;  slog::Index** mp_msk_ansindex181;  slog::Index** mp_unionindex182;  slog::Index** mbranchindex183;  slog::Index** mp_unionindex184;  slog::Index** mbranchindex185;  slog::Index** mp_unionindex186;  slog::Index** mp_mskindex187;  slog::Index** mp_msk_ansindex188;  slog::Index** mp_unionindex189;  slog::Index** mp_union_ansindex190;  slog::Index** mbranchdelta191;  slog::Index** mbranchdelta192;  slog::Index** mp_uniondelta193;  slog::Index** mp_mskdelta194;  slog::Index** mp_uniondelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9B581035");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord197({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel198 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index178 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 3, 4, 0});
      slog::Relation* readrel200 = db->getRelation("mbranch");
      mbranchindex179 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("mp_msk");
      mp_mskindex180 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex181 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({2, 0, 1});
      slog::Relation* readrel206 = db->getRelation("mp_union");
      mp_unionindex182 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 3, 4, 0});
      slog::Relation* readrel208 = db->getRelation("mbranch");
      mbranchindex183 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 3, 4, 0});
      slog::Relation* readrel210 = db->getRelation("mbranch");
      mbranchdelta191 = readrel210->getIndex(ord209, true);
      std::vector<u16> ord211({2, 0, 1});
      slog::Relation* readrel212 = db->getRelation("mp_union");
      mp_unionindex184 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 3, 4, 0});
      slog::Relation* readrel214 = db->getRelation("mbranch");
      mbranchindex185 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 3, 4, 0});
      slog::Relation* readrel216 = db->getRelation("mbranch");
      mbranchdelta192 = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({0, 1, 2});
      slog::Relation* readrel218 = db->getRelation("mp_union");
      mp_unionindex186 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({0, 1, 2});
      slog::Relation* readrel220 = db->getRelation("mp_union");
      mp_uniondelta193 = readrel220->getIndex(ord219, true);
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("mp_msk");
      mp_mskindex187 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 0});
      slog::Relation* readrel224 = db->getRelation("mp_msk");
      mp_mskdelta194 = readrel224->getIndex(ord223, true);
      std::vector<u16> ord225({0, 1});
      slog::Relation* readrel226 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex188 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("mp_union");
      mp_unionindex189 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("mp_union");
      mp_uniondelta195 = readrel230->getIndex(ord229, true);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("mp_union_ans");
      mp_union_ansindex190 = readrel232->getIndex(ord231, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c53 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c48 = _t[4];
        u64 v_c12 = _t[5];
        u64 v_c47 = _t[6];
        u64 v_c8 = _t[7];
        u64 v_c49 = _t[8];
        u64 v_c50 = _t[9];
        u64 v_c54 = _prim_lt(db, v_c11, v_c48);
        if (v_c54 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
        if (!v_c54) return;
        slog::join_probe<9,9>($sup5638x107x0x0x0index178, std::array<u64,9>{v_c47, v_c48, v_c49, v_c50, v_c52, v_c10, v_c11, v_c12, v_c8}, [&](const std::array<u64,9>& m234) {
          if (!slog::exists_probe<5,4>(mbranchindex179, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex180, std::array<u64,3>{v_c12, v_c48, v_c53})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex181, std::array<u64,2>{v_c53, v_c47})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex182, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex183, mbranchdelta191, std::array<u64,5>{v_c47, v_c48, v_c49, v_c50, 0}, [&](const std::array<u64,5>& m235) {
            u64 v_c55 = m235[4];
            if (!slog::exists_probe<3,2>(mp_unionindex184, std::array<u64,3>{v_c55, v_c52, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex185, mbranchdelta192, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m236) {
              u64 v_c56 = m236[4];
              slog::join_probe_old<3,3>(mp_unionindex186, mp_uniondelta193, std::array<u64,3>{v_c52, v_c56, v_c55}, [&](const std::array<u64,3>& m237) {
                slog::join_probe_old<3,3>(mp_mskindex187, mp_mskdelta194, std::array<u64,3>{v_c12, v_c48, v_c53}, [&](const std::array<u64,3>& m238) {
                  slog::join_probe<2,2>(mp_msk_ansindex188, std::array<u64,2>{v_c53, v_c47}, [&](const std::array<u64,2>& m239) {
                    slog::join_probe_old<3,2>(mp_unionindex189, mp_uniondelta195, std::array<u64,3>{v_c56, v_c50, 0}, [&](const std::array<u64,3>& m240) {
                      u64 v_c57 = m240[2];
                      slog::join_probe<2,1>(mp_union_ansindex190, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m241) {
                        u64 v_c6 = m241[1];
                        u64 v_c58 = _prim_band(db, v_c12, v_c48);
                        if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c59 = _prim_gt(db, v_c58, v_c51);
                        if (v_c59 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c59) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c52, v_c6, v_c48, v_c47, v_c49});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c47, v_c48, v_c49, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_del_ans __t3il5409 __v0) (body (exists mp_bld (4 0 1 2 3) 1 __v0) (join-old mp_del (0 2 1) 1 (0 2 1) __t3il5409 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t01YW404 l m p) (exists mp_bld (1 2 3 4 0) 4 p m l __v0) (exists mp_del (0 2 1) 2 __t01YW404 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0VzH403) (exists mp_del (0 2 1) 3 __t01YW404 k __t0VzH403) (join-old mp_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m l __v0 __t8Ai5407) (join-old mp_del (0 2 1) 3 (0 2 1) __t01YW404 k __t0VzH403) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7ikb408) (join mp_msk_ans (0 1) 2 __t7ikb408 p) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex243;  slog::Index** mp_delindex244;  slog::Index** mbranchindex245;  slog::Index** mp_delindex246;  slog::Index** mp_mskindex247;  slog::Index** $sup5638x84x0x0x0index248;  slog::Index** mp_bldindex249;  slog::Index** mp_delindex250;  slog::Index** mp_mskindex251;  slog::Index** mp_msk_ansindex252;  slog::Index** mbranchindex253;  slog::Index** mp_delindex254;  slog::Index** mp_bldindex255;  slog::Index** mp_delindex256;  slog::Index** mp_bld_ansindex257;  slog::Index** mp_mskindex258;  slog::Index** mp_msk_ansindex259;  slog::Index** mp_bld_ansindex260;  slog::Index** mp_deldelta261;  slog::Index** $sup5638x84x0x0x0delta262;  slog::Index** mbranchdelta263;  slog::Index** mp_blddelta264;  slog::Index** mp_deldelta265;  slog::Index** mp_mskdelta266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("mp_del_ans");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord270({4, 0, 1, 2, 3});
      slog::Relation* readrel271 = db->getRelation("mp_bld");
      mp_bldindex243 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 2, 1});
      slog::Relation* readrel273 = db->getRelation("mp_del");
      mp_delindex244 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 2, 1});
      slog::Relation* readrel275 = db->getRelation("mp_del");
      mp_deldelta261 = readrel275->getIndex(ord274, true);
      std::vector<u16> ord276({4, 0, 1, 2, 3});
      slog::Relation* readrel277 = db->getRelation("mbranch");
      mbranchindex245 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({2, 0, 1});
      slog::Relation* readrel279 = db->getRelation("mp_del");
      mp_delindex246 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 2, 0});
      slog::Relation* readrel281 = db->getRelation("mp_msk");
      mp_mskindex247 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel283 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index248 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel285 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta262 = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({1, 2, 3, 4, 0});
      slog::Relation* readrel287 = db->getRelation("mp_bld");
      mp_bldindex249 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({0, 2, 1});
      slog::Relation* readrel289 = db->getRelation("mp_del");
      mp_delindex250 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 2, 0});
      slog::Relation* readrel291 = db->getRelation("mp_msk");
      mp_mskindex251 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 0});
      slog::Relation* readrel293 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex252 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 3, 4, 0});
      slog::Relation* readrel295 = db->getRelation("mbranch");
      mbranchindex253 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 3, 4, 0});
      slog::Relation* readrel297 = db->getRelation("mbranch");
      mbranchdelta263 = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({0, 2, 1});
      slog::Relation* readrel299 = db->getRelation("mp_del");
      mp_delindex254 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 3, 4, 0});
      slog::Relation* readrel301 = db->getRelation("mp_bld");
      mp_bldindex255 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 3, 4, 0});
      slog::Relation* readrel303 = db->getRelation("mp_bld");
      mp_blddelta264 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({0, 2, 1});
      slog::Relation* readrel305 = db->getRelation("mp_del");
      mp_delindex256 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 2, 1});
      slog::Relation* readrel307 = db->getRelation("mp_del");
      mp_deldelta265 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({0, 1});
      slog::Relation* readrel309 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex257 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("mp_msk");
      mp_mskindex258 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("mp_msk");
      mp_mskdelta266 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex259 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex260 = readrel317->getIndex(ord316, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<5,1>(mp_bldindex243, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_delindex244, mp_deldelta261, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m318) {
          u64 v_c7 = m318[1]; u64 v_c8 = m318[2];
          if (!slog::exists_probe<5,1>(mbranchindex245, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex246, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex247, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x84x0x0x0index248, $sup5638x84x0x0x0delta262, std::array<u64,6>{v_c7, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m319) {
            u64 v_c62 = m319[2]; u64 v_c10 = m319[3]; u64 v_c11 = m319[4]; u64 v_c12 = m319[5];
            if (!slog::exists_probe<5,4>(mp_bldindex249, std::array<u64,5>{v_c12, v_c11, v_c10, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex250, std::array<u64,3>{v_c62, v_c7, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex251, std::array<u64,3>{v_c7, v_c11, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex252, std::array<u64,2>{v_c12, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex253, mbranchdelta263, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m320) {
              u64 v_c63 = m320[4];
              if (!slog::exists_probe<3,3>(mp_delindex254, std::array<u64,3>{v_c62, v_c7, v_c63})) return;
              slog::join_probe_old<5,4>(mp_bldindex255, mp_blddelta264, std::array<u64,5>{v_c12, v_c11, v_c10, v_c6, 0}, [&](const std::array<u64,5>& m321) {
                u64 v_c64 = m321[4];
                slog::join_probe_old<3,3>(mp_delindex256, mp_deldelta265, std::array<u64,3>{v_c62, v_c7, v_c63}, [&](const std::array<u64,3>& m322) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex257, std::array<u64,2>{v_c64, 0})) return;
                  slog::join_probe_old<3,2>(mp_mskindex258, mp_mskdelta266, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m323) {
                    u64 v_c65 = m323[2];
                    slog::join_probe<2,2>(mp_msk_ansindex259, std::array<u64,2>{v_c65, v_c12}, [&](const std::array<u64,2>& m324) {
                      slog::join_probe<2,1>(mp_bld_ansindex260, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m325) {
                        u64 v_c66 = m325[1];
                        u64 v_c67 = _prim_band(db, v_c7, v_c11);
                        if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c68 = _prim_gt(db, v_c67, v_c60);
                        if (v_c68 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c68) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c66}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del_ans", _fires);
  
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
  // (crule (pre) (scan temp2xeX1033 __t0mSQ44 __v0 m p r) (body (join mbranch (1 2 3 4 0) 4 p m __v0 r __t4qMo41)) (head (emit mp_union_ans (0 1) __t0mSQ44 __t4qMo41)) map.slog:96 #f)
  class ReadTask328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("mp_union_ans");
      head_index[0] = readrel330->getIndex(ord329, false);
      outer_rel = db->getRelation("temp2xeX1033");
      std::vector<u16> ord331({1, 2, 3, 4, 0});
      slog::Relation* readrel332 = db->getRelation("mbranch");
      mbranchindex327 = readrel332->getIndex(ord331, false);
  
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
        u64 v_c69 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<5,4>(mbranchindex327, std::array<u64,5>{v_c12, v_c11, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m333) {
          u64 v_c70 = m333[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c69, v_c70}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:temp2xeX1033", _fires);
  
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
  // (crule (pre (let __tconst7bQr405 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t7ikb408 p) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_bld (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t7ikb408 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (1 2 3 4 0) 2 p m) (join-old $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t01YW404 l r) (exists mp_del (0 2 1) 2 __t01YW404 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_del (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0VzH403) (join-old mp_del (0 2 1) 3 (0 2 1) __t01YW404 k __t0VzH403) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8Ai5407) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8Ai5407) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t3il5409) (join-old mp_del_ans (0 1) 2 (0 1) __t3il5409 __v0) (join mp_bld_ans (0 1) 1 __t8Ai5407 res) (let __t8wDJ406 (band k m)) (cmp gt __t8wDJ406 __tconst7bQr405)) (head (emit mp_del_ans (0 1) __t01YW404 res)) map.slog:85 #f)
  class ReadTask360 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index334;  slog::Index** mbranchindex335;  slog::Index** mp_bldindex336;  slog::Index** mp_mskindex337;  slog::Index** mbranchindex338;  slog::Index** mp_delindex339;  slog::Index** mp_bldindex340;  slog::Index** $sup5638x84x0x0x0index341;  slog::Index** mp_delindex342;  slog::Index** mp_bldindex343;  slog::Index** mp_delindex344;  slog::Index** mbranchindex345;  slog::Index** mp_delindex346;  slog::Index** mp_bldindex347;  slog::Index** mp_del_ansindex348;  slog::Index** mp_bld_ansindex349;  slog::Index** mp_delindex350;  slog::Index** mp_del_ansindex351;  slog::Index** mp_bld_ansindex352;  slog::Index** mp_mskdelta353;  slog::Index** $sup5638x84x0x0x0delta354;  slog::Index** mbranchdelta355;  slog::Index** mp_deldelta356;  slog::Index** mp_blddelta357;  slog::Index** mp_deldelta358;  slog::Index** mp_del_ansdelta359;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord361({0, 1});
      slog::Relation* readrel362 = db->getRelation("mp_del_ans");
      head_index[0] = readrel362->getIndex(ord361, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord363({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel364 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index334 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 3, 4, 0});
      slog::Relation* readrel366 = db->getRelation("mbranch");
      mbranchindex335 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 3, 4, 0});
      slog::Relation* readrel368 = db->getRelation("mp_bld");
      mp_bldindex336 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({0, 1, 2});
      slog::Relation* readrel370 = db->getRelation("mp_msk");
      mp_mskindex337 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1, 2});
      slog::Relation* readrel372 = db->getRelation("mp_msk");
      mp_mskdelta353 = readrel372->getIndex(ord371, true);
      std::vector<u16> ord373({1, 2, 3, 4, 0});
      slog::Relation* readrel374 = db->getRelation("mbranch");
      mbranchindex338 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({2, 0, 1});
      slog::Relation* readrel376 = db->getRelation("mp_del");
      mp_delindex339 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 2, 3, 4, 0});
      slog::Relation* readrel378 = db->getRelation("mp_bld");
      mp_bldindex340 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel380 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index341 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel382 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta354 = readrel382->getIndex(ord381, true);
      std::vector<u16> ord383({0, 2, 1});
      slog::Relation* readrel384 = db->getRelation("mp_del");
      mp_delindex342 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 2, 3, 4, 0});
      slog::Relation* readrel386 = db->getRelation("mp_bld");
      mp_bldindex343 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("mp_del");
      mp_delindex344 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 3, 4, 0});
      slog::Relation* readrel390 = db->getRelation("mbranch");
      mbranchindex345 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 3, 4, 0});
      slog::Relation* readrel392 = db->getRelation("mbranch");
      mbranchdelta355 = readrel392->getIndex(ord391, true);
      std::vector<u16> ord393({0, 2, 1});
      slog::Relation* readrel394 = db->getRelation("mp_del");
      mp_delindex346 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0, 2, 1});
      slog::Relation* readrel396 = db->getRelation("mp_del");
      mp_deldelta356 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({1, 2, 3, 4, 0});
      slog::Relation* readrel398 = db->getRelation("mp_bld");
      mp_bldindex347 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 3, 4, 0});
      slog::Relation* readrel400 = db->getRelation("mp_bld");
      mp_blddelta357 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({1, 0});
      slog::Relation* readrel402 = db->getRelation("mp_del_ans");
      mp_del_ansindex348 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex349 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("mp_del");
      mp_delindex350 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 0});
      slog::Relation* readrel408 = db->getRelation("mp_del");
      mp_deldelta358 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("mp_del_ans");
      mp_del_ansindex351 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({0, 1});
      slog::Relation* readrel412 = db->getRelation("mp_del_ans");
      mp_del_ansdelta359 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex352 = readrel414->getIndex(ord413, false);
  
    }
    ReadTask360(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c65 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x84x0x0x0index334, std::array<u64,6>{v_c12, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex335, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex336, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex337, mp_mskdelta353, std::array<u64,3>{v_c65, 0, 0}, [&](const std::array<u64,3>& m415) {
          u64 v_c7 = m415[1]; u64 v_c11 = m415[2];
          if (!slog::exists_probe<5,2>(mbranchindex338, std::array<u64,5>{v_c12, v_c11, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex339, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex340, std::array<u64,5>{v_c12, v_c11, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x84x0x0x0index341, $sup5638x84x0x0x0delta354, std::array<u64,6>{v_c7, v_c11, v_c12, 0, 0, 0}, [&](const std::array<u64,6>& m416) {
            u64 v_c62 = m416[3]; u64 v_c10 = m416[4]; u64 v_c8 = m416[5];
            if (!slog::exists_probe<3,2>(mp_delindex342, std::array<u64,3>{v_c62, v_c7, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex343, std::array<u64,5>{v_c12, v_c11, v_c10, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex344, std::array<u64,3>{v_c8, v_c7, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex345, mbranchdelta355, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m417) {
              u64 v_c63 = m417[4];
              slog::join_probe_old<3,3>(mp_delindex346, mp_deldelta356, std::array<u64,3>{v_c62, v_c7, v_c63}, [&](const std::array<u64,3>& m418) {
                slog::join_probe_old<5,3>(mp_bldindex347, mp_blddelta357, std::array<u64,5>{v_c12, v_c11, v_c10, 0, 0}, [&](const std::array<u64,5>& m419) {
                  u64 v_c6 = m419[3]; u64 v_c64 = m419[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex348, std::array<u64,2>{v_c6, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex349, std::array<u64,2>{v_c64, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex350, mp_deldelta358, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m420) {
                    u64 v_c61 = m420[2];
                    slog::join_probe_old<2,2>(mp_del_ansindex351, mp_del_ansdelta359, std::array<u64,2>{v_c61, v_c6}, [&](const std::array<u64,2>& m421) {
                      slog::join_probe<2,1>(mp_bld_ansindex352, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m422) {
                        u64 v_c66 = m422[1];
                        u64 v_c67 = _prim_band(db, v_c7, v_c11);
                        if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c71 = _prim_gt(db, v_c67, v_c60);
                        if (v_c71 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c71) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c66}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask360* _cont = new ReadTask360(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask360(db,b), false);
  // (crule (pre (let __tconst5oqW96 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t9ory98 p) (body (exists $sup5638x98x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t9ory98 p) (exists $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t9ory98 q m) (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mbranch (1 2 3 4 0) 1 q) (join-old $sup5638x98x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t9ory98 m q p __t2uCs95 l n r u v) (cmp lt n m) (join-old $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 (4 1 2 6 0 3 5 7 8) p l m r __t2uCs95 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (1 2 0) 1 r) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2SOF94) (exists mp_union (0 1 2) 2 __t2uCs95 __t2SOF94) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t1Mtu99) (join-old mp_union (0 1 2) 3 (0 1 2) __t2uCs95 __t2SOF94 __t1Mtu99) (join-old mp_union (1 2 0) 2 (1 2 0) r __t1Mtu99 __t2wnB100) (join-old mp_union_ans (0 1) 1 (0 1) __t2wnB100 __v0) (let __t1uht97 (band q m)) (cmp gt __t1uht97 __tconst5oqW96)) (head (emit-temp temp1XD61034 __t2uCs95 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t0Nlr92 p m l __v0)) map.slog:99 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index424;  slog::Index** $sup5638x98x0x0x0index425;  slog::Index** mbranchindex426;  slog::Index** mp_mskindex427;  slog::Index** $sup5638x98x0x0x0index428;  slog::Index** mbranchindex429;  slog::Index** mbranchindex430;  slog::Index** $sup5638x98x0x0x1index431;  slog::Index** $sup5638x98x0x0x0index432;  slog::Index** mbranchindex433;  slog::Index** mp_unionindex434;  slog::Index** mbranchindex435;  slog::Index** mp_unionindex436;  slog::Index** mbranchindex437;  slog::Index** mp_unionindex438;  slog::Index** mp_unionindex439;  slog::Index** mp_union_ansindex440;  slog::Index** mp_mskdelta441;  slog::Index** $sup5638x98x0x0x1delta442;  slog::Index** $sup5638x98x0x0x0delta443;  slog::Index** mbranchdelta444;  slog::Index** mbranchdelta445;  slog::Index** mp_uniondelta446;  slog::Index** mp_uniondelta447;  slog::Index** mp_union_ansdelta448;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1XD61034");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord450({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel451 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index424 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel453 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index425 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 3, 4, 0});
      slog::Relation* readrel455 = db->getRelation("mbranch");
      mbranchindex426 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 1, 2});
      slog::Relation* readrel457 = db->getRelation("mp_msk");
      mp_mskindex427 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1, 2});
      slog::Relation* readrel459 = db->getRelation("mp_msk");
      mp_mskdelta441 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel461 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index428 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 3, 4, 0});
      slog::Relation* readrel463 = db->getRelation("mbranch");
      mbranchindex429 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 3, 4, 0});
      slog::Relation* readrel465 = db->getRelation("mbranch");
      mbranchindex430 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel467 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index431 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel469 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta442 = readrel469->getIndex(ord468, true);
      std::vector<u16> ord470({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel471 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index432 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel473 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0delta443 = readrel473->getIndex(ord472, true);
      std::vector<u16> ord474({1, 2, 3, 4, 0});
      slog::Relation* readrel475 = db->getRelation("mbranch");
      mbranchindex433 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("mp_union");
      mp_unionindex434 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 3, 4, 0});
      slog::Relation* readrel479 = db->getRelation("mbranch");
      mbranchindex435 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 3, 4, 0});
      slog::Relation* readrel481 = db->getRelation("mbranch");
      mbranchdelta444 = readrel481->getIndex(ord480, true);
      std::vector<u16> ord482({0, 1, 2});
      slog::Relation* readrel483 = db->getRelation("mp_union");
      mp_unionindex436 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 3, 4, 0});
      slog::Relation* readrel485 = db->getRelation("mbranch");
      mbranchindex437 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 2, 3, 4, 0});
      slog::Relation* readrel487 = db->getRelation("mbranch");
      mbranchdelta445 = readrel487->getIndex(ord486, true);
      std::vector<u16> ord488({0, 1, 2});
      slog::Relation* readrel489 = db->getRelation("mp_union");
      mp_unionindex438 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1, 2});
      slog::Relation* readrel491 = db->getRelation("mp_union");
      mp_uniondelta446 = readrel491->getIndex(ord490, true);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("mp_union");
      mp_unionindex439 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({1, 2, 0});
      slog::Relation* readrel495 = db->getRelation("mp_union");
      mp_uniondelta447 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("mp_union_ans");
      mp_union_ansindex440 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 1});
      slog::Relation* readrel499 = db->getRelation("mp_union_ans");
      mp_union_ansdelta448 = readrel499->getIndex(ord498, true);
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index424, std::array<u64,10>{v_c73, v_c12, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index425, std::array<u64,9>{v_c12, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex426, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex427, mp_mskdelta441, std::array<u64,3>{v_c73, 0, 0}, [&](const std::array<u64,3>& m500) {
          u64 v_c47 = m500[1]; u64 v_c11 = m500[2];
          if (!slog::exists_probe<9,3>($sup5638x98x0x0x0index428, std::array<u64,9>{v_c11, v_c47, v_c12, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex429, std::array<u64,5>{v_c12, v_c11, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex430, std::array<u64,5>{v_c47, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x98x0x0x1index431, $sup5638x98x0x0x1delta442, std::array<u64,10>{v_c73, v_c11, v_c47, v_c12, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m501) {
            u64 v_c74 = m501[4]; u64 v_c10 = m501[5]; u64 v_c48 = m501[6]; u64 v_c8 = m501[7]; u64 v_c49 = m501[8]; u64 v_c50 = m501[9];
            u64 v_c75 = _prim_lt(db, v_c48, v_c11);
            if (v_c75 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c75) return;
            slog::join_probe_old<9,9>($sup5638x98x0x0x0index432, $sup5638x98x0x0x0delta443, std::array<u64,9>{v_c12, v_c10, v_c11, v_c8, v_c74, v_c48, v_c47, v_c49, v_c50}, [&](const std::array<u64,9>& m503) {
              if (!slog::exists_probe<5,4>(mbranchindex433, std::array<u64,5>{v_c47, v_c48, v_c49, v_c50, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex434, std::array<u64,3>{v_c8, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex435, mbranchdelta444, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m504) {
                u64 v_c76 = m504[4];
                if (!slog::exists_probe<3,2>(mp_unionindex436, std::array<u64,3>{v_c74, v_c76, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex437, mbranchdelta445, std::array<u64,5>{v_c47, v_c48, v_c49, v_c50, 0}, [&](const std::array<u64,5>& m505) {
                  u64 v_c77 = m505[4];
                  slog::join_probe_old<3,3>(mp_unionindex438, mp_uniondelta446, std::array<u64,3>{v_c74, v_c76, v_c77}, [&](const std::array<u64,3>& m506) {
                    slog::join_probe_old<3,2>(mp_unionindex439, mp_uniondelta447, std::array<u64,3>{v_c8, v_c77, 0}, [&](const std::array<u64,3>& m507) {
                      u64 v_c78 = m507[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex440, mp_union_ansdelta448, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m508) {
                        u64 v_c6 = m508[1];
                        u64 v_c79 = _prim_band(db, v_c47, v_c11);
                        if (v_c79 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c80 = _prim_gt(db, v_c79, v_c72);
                        if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c80) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c74, v_c6, v_c10, v_c11, v_c12});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c12, v_c11, v_c10, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre) (scan mbranch __t7hGG305 p m l r) (body (join mp_put (1 2 0 3) 1 __t7hGG305 k __t3qfB304 v)) (head (emit $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) k m v __t3qfB304 l p r __t7hGG305)) map.slog:45 #f)
  class ReadTask511 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex510;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord512({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel513 = db->getRelation("$sup5638x44x0x0x0");
      head_index[0] = readrel513->getIndex(ord512, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord514({1, 2, 0, 3});
      slog::Relation* readrel515 = db->getRelation("mp_put");
      mp_putindex510 = readrel515->getIndex(ord514, false);
  
    }
    ReadTask511(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c81 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<4,1>(mp_putindex510, std::array<u64,4>{v_c81, 0, 0, 0}, [&](const std::array<u64,4>& m516) {
          u64 v_c7 = m516[1]; u64 v_c82 = m516[2]; u64 v_c50 = m516[3];
          ++_fires;
          slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c11, v_c50, v_c82, v_c10, v_c12, v_c8, v_c81}, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask511* _cont = new ReadTask511(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask511(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t7eaA149 p) (body (exists $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t7eaA149 k m) (join $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t7eaA149 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask521 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index517;  slog::Index** mp_mskindex518;  slog::Index** $sup5638x40x0x0x0index519;  slog::Index** mp_mskdelta520;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord522({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel523 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel523->getIndex(ord522, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord524({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel525 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index517 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 1, 2});
      slog::Relation* readrel527 = db->getRelation("mp_msk");
      mp_mskindex518 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("mp_msk");
      mp_mskdelta520 = readrel529->getIndex(ord528, true);
      std::vector<u16> ord530({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel531 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index519 = readrel531->getIndex(ord530, false);
  
    }
    ReadTask521(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<7,1>($sup5638x40x0x0x0index517, std::array<u64,7>{v_c12, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex518, mp_mskdelta520, std::array<u64,3>{v_c83, 0, 0}, [&](const std::array<u64,3>& m532) {
          u64 v_c7 = m532[1]; u64 v_c11 = m532[2];
          slog::join_probe<7,3>($sup5638x40x0x0x0index519, std::array<u64,7>{v_c7, v_c11, v_c12, 0, 0, 0, 0}, [&](const std::array<u64,7>& m533) {
            u64 v_c9 = m533[3]; u64 v_c10 = m533[4]; u64 v_c8 = m533[5]; u64 v_c50 = m533[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c83, v_c12, v_c9, v_c7, v_c10, v_c11, v_c8, v_c50}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask521* _cont = new ReadTask521(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask521(db,b), false);
  // (crule (pre) (scan mbranch __t9UVm194 q n u v) (body (join mp_union (2 0 1) 1 __t9UVm194 __t0SXa192 __t5w7I193) (join mbranch (0 1 2 3 4) 1 __t5w7I193 p m l r) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t0SXa192 l n p r __t5w7I193 __t9UVm194 u v)) map.slog:102 #f)
  class ReadTask536 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex534;  slog::Index** mbranchindex535;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord537({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel538 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel538->getIndex(ord537, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord539({2, 0, 1});
      slog::Relation* readrel540 = db->getRelation("mp_union");
      mp_unionindex534 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1, 2, 3, 4});
      slog::Relation* readrel542 = db->getRelation("mbranch");
      mbranchindex535 = readrel542->getIndex(ord541, false);
  
    }
    ReadTask536(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c48 = _t[2];
        u64 v_c49 = _t[3];
        u64 v_c50 = _t[4];
        slog::join_probe<3,1>(mp_unionindex534, std::array<u64,3>{v_c84, 0, 0}, [&](const std::array<u64,3>& m543) {
          u64 v_c85 = m543[1]; u64 v_c86 = m543[2];
          slog::join_probe<5,1>(mbranchindex535, std::array<u64,5>{v_c86, 0, 0, 0, 0}, [&](const std::array<u64,5>& m544) {
            u64 v_c12 = m544[1]; u64 v_c11 = m544[2]; u64 v_c10 = m544[3]; u64 v_c8 = m544[4];
            u64 v_c87 = _prim_lt(db, v_c48, v_c11);
            if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c87) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c11, v_c47, v_c85, v_c10, v_c48, v_c12, v_c8, v_c86, v_c84, v_c49, v_c50}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask536* _cont = new ReadTask536(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask536(db,b), false);
  // (crule (pre (let __tconst03XK425 const5feceb66ffc86f38d952786c)) (scan mp_hsb __t63mh424 __t5o85423) (body (join mp_hsb_ans (0 1) 1 __t63mh424 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t2zZo426 (band p0 __v0)) (cmp gt __t2zZo426 __tconst03XK425) (let chk7dDT1063 (bxor p0 p1)) (eq __t5o85423 chk7dDT1063)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t63mh424 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask548 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex546;  slog::Index** $sup5638x29x0x0x0index547;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord549({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel550 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel550->getIndex(ord549, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex546 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 0, 2, 3, 4});
      slog::Relation* readrel554 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index547 = readrel554->getIndex(ord553, false);
  
    }
    ReadTask548(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c89 = _t[0];
        u64 v_c90 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex546, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m555) {
          u64 v_c6 = m555[1];
          slog::join_all<5>($sup5638x29x0x0x0index547, [&](const std::array<u64,5>& m556) {
            u64 v_c34 = m556[0]; u64 v_c9 = m556[1]; u64 v_c35 = m556[2]; u64 v_c36 = m556[3]; u64 v_c37 = m556[4];
            u64 v_c91 = _prim_band(db, v_c34, v_c6);
            if (v_c91 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c92 = _prim_gt(db, v_c91, v_c88);
            if (v_c92 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c92) return;
            u64 v_c93 = _prim_bxor(db, v_c34, v_c35);
            if (v_c93 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (v_c90 != v_c93) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c89, v_c6, v_c9, v_c34, v_c35, v_c36, v_c37}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask548* _cont = new ReadTask548(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask548(db,b), false);
  // (crule (pre) (scan mbranch __t5rgl314 p m u v) (body (exists mp_union (2 0 1) 1 __t5rgl314) (join-old mbranch (1 2 3 4 0) 2 (1 2 3 4 0) p m l r __t9YDI315) (join-old mp_union (1 2 0) 2 (1 2 0) __t9YDI315 __t5rgl314 __t4nmW316)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t4nmW316 l m p r u v)) map.slog:94 #f)
  class ReadTask563 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex558;  slog::Index** mbranchindex559;  slog::Index** mp_unionindex560;  slog::Index** mbranchdelta561;  slog::Index** mp_uniondelta562;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord564({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel565 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel565->getIndex(ord564, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord566({2, 0, 1});
      slog::Relation* readrel567 = db->getRelation("mp_union");
      mp_unionindex558 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 2, 3, 4, 0});
      slog::Relation* readrel569 = db->getRelation("mbranch");
      mbranchindex559 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 3, 4, 0});
      slog::Relation* readrel571 = db->getRelation("mbranch");
      mbranchdelta561 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("mp_union");
      mp_unionindex560 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("mp_union");
      mp_uniondelta562 = readrel575->getIndex(ord574, true);
  
    }
    ReadTask563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c49 = _t[3];
        u64 v_c50 = _t[4];
        if (!slog::exists_probe<3,1>(mp_unionindex558, std::array<u64,3>{v_c94, 0, 0})) return;
        slog::join_probe_old<5,2>(mbranchindex559, mbranchdelta561, std::array<u64,5>{v_c12, v_c11, 0, 0, 0}, [&](const std::array<u64,5>& m576) {
          u64 v_c10 = m576[2]; u64 v_c8 = m576[3]; u64 v_c95 = m576[4];
          slog::join_probe_old<3,2>(mp_unionindex560, mp_uniondelta562, std::array<u64,3>{v_c95, v_c94, 0}, [&](const std::array<u64,3>& m577) {
            u64 v_c96 = m577[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c96, v_c10, v_c11, v_c12, v_c8, v_c49, v_c50}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask563* _cont = new ReadTask563(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask563(db,b), false);
  // (crule (pre) (scan mbranch __t5VI4222 p m l r) (body (exists mp_del (1 2 0) 1 __t5VI4222) (exists mp_msk (2 0 1) 1 m) (join $sup5638x81x0x0x0 (2 3 4 5 0 1) 4 l m p r __t9Sl6223 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t9Sl6223 k __t5VI4222) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t3J75224) (join mp_msk_ans (0 1) 1 __t3J75224 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t9Sl6223 __t5VI4222)) map.slog:82 #f)
  class ReadTask586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex578;  slog::Index** mp_mskindex579;  slog::Index** $sup5638x81x0x0x0index580;  slog::Index** mp_delindex581;  slog::Index** mp_mskindex582;  slog::Index** mp_msk_ansindex583;  slog::Index** mp_deldelta584;  slog::Index** mp_mskdelta585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("mp_del_ans");
      head_index[0] = readrel588->getIndex(ord587, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("mp_del");
      mp_delindex578 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({2, 0, 1});
      slog::Relation* readrel592 = db->getRelation("mp_msk");
      mp_mskindex579 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel594 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index580 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({0, 2, 1});
      slog::Relation* readrel596 = db->getRelation("mp_del");
      mp_delindex581 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({0, 2, 1});
      slog::Relation* readrel598 = db->getRelation("mp_del");
      mp_deldelta584 = readrel598->getIndex(ord597, true);
      std::vector<u16> ord599({1, 2, 0});
      slog::Relation* readrel600 = db->getRelation("mp_msk");
      mp_mskindex582 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 0});
      slog::Relation* readrel602 = db->getRelation("mp_msk");
      mp_mskdelta585 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex583 = readrel604->getIndex(ord603, false);
  
    }
    ReadTask586(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(mp_delindex578, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex579, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x81x0x0x0index580, std::array<u64,6>{v_c10, v_c11, v_c12, v_c8, 0, 0}, [&](const std::array<u64,6>& m605) {
          u64 v_c98 = m605[4]; u64 v_c7 = m605[5];
          slog::join_probe_old<3,3>(mp_delindex581, mp_deldelta584, std::array<u64,3>{v_c98, v_c7, v_c97}, [&](const std::array<u64,3>& m606) {
            slog::join_probe_old<3,2>(mp_mskindex582, mp_mskdelta585, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m607) {
              u64 v_c99 = m607[2];
              slog::join_probe<2,1>(mp_msk_ansindex583, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m608) {
                u64 v_c6 = m608[1];
                if (v_c12 == v_c6) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c98, v_c97}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask586* _cont = new ReadTask586(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask586(db,b), false);
  // (crule (pre (let __tconst22D2394 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x0 __t4lFL393 p0 p1 t0 t1) (body (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4lFL393) (exists $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t4lFL393 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 5 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0) (exists mp_hsb_ans (0 1) 1 __t1lh0397) (exists mp_hsb_ans (0 1) 2 __t1lh0397 __v0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4lFL393 p0 p1 t0 t1 __t1lh0397 __v0 dup0XDZ1075 dup8FhK1076 __v1 __v3) (eq __t1lh0397 dup8FhK1076) (eq __t1lh0397 dup0XDZ1075) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t1lh0397 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t8rat400) (join-old mp_msk_ans (0 1) 1 (0 1) __t8rat400 __v2) (let __t82fz401 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t1lh0397 __t82fz401) (let __t0wDX395 (band p0 __v0)) (cmp gt __t0wDX395 __tconst22D2394)) (head (emit-temp temp5z0Y1074 __t4lFL393 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t85Rb392 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask629 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex609;  slog::Index** $sup5638x29x0x0x2index610;  slog::Index** mp_mskindex611;  slog::Index** $sup5638x29x0x0x1index612;  slog::Index** mp_hsb_ansindex613;  slog::Index** mp_hsb_ansindex614;  slog::Index** $sup5638x29x0x0x2index615;  slog::Index** mp_hsb_ansindex616;  slog::Index** mp_hsb_ansindex617;  slog::Index** mp_hsb_ansindex618;  slog::Index** mp_mskindex619;  slog::Index** mp_msk_ansindex620;  slog::Index** mp_hsbindex621;  slog::Index** mp_joindelta622;  slog::Index** mp_hsb_ansdelta623;  slog::Index** mp_hsb_ansdelta624;  slog::Index** mp_hsb_ansdelta625;  slog::Index** mp_mskdelta626;  slog::Index** mp_msk_ansdelta627;  slog::Index** mp_hsbdelta628;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5z0Y1074");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord630({1, 2, 3, 4, 0});
      slog::Relation* readrel631 = db->getRelation("mp_join");
      mp_joinindex609 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 3, 4, 0});
      slog::Relation* readrel633 = db->getRelation("mp_join");
      mp_joindelta622 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel635 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index610 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 2, 0});
      slog::Relation* readrel637 = db->getRelation("mp_msk");
      mp_mskindex611 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel639 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index612 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({0, 1});
      slog::Relation* readrel641 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex613 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex614 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel645 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index615 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex616 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta623 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex617 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta624 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex618 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta625 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("mp_msk");
      mp_mskindex619 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("mp_msk");
      mp_mskdelta626 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex620 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta627 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("mp_hsb");
      mp_hsbindex621 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("mp_hsb");
      mp_hsbdelta628 = readrel669->getIndex(ord668, true);
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c37 = _t[4];
        slog::join_probe_old<5,5>(mp_joinindex609, mp_joindelta622, std::array<u64,5>{v_c34, v_c36, v_c35, v_c37, v_c32}, [&](const std::array<u64,5>& m670) {
          if (!slog::exists_probe<11,5>($sup5638x29x0x0x2index610, std::array<u64,11>{v_c32, v_c34, v_c35, v_c36, v_c37, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex611, std::array<u64,3>{v_c34, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x29x0x0x1index612, std::array<u64,7>{v_c32, v_c34, v_c35, v_c36, v_c37, 0, 0}, [&](const std::array<u64,7>& m671) {
            u64 v_c33 = m671[5]; u64 v_c6 = m671[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex613, std::array<u64,2>{v_c33, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex614, std::array<u64,2>{v_c33, v_c6})) return;
            slog::join_probe<11,7>($sup5638x29x0x0x2index615, std::array<u64,11>{v_c32, v_c34, v_c35, v_c36, v_c37, v_c33, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,11>& m672) {
              u64 v_c38 = m672[7]; u64 v_c39 = m672[8]; u64 v_c22 = m672[9]; u64 v_c40 = m672[10];
              if (v_c33 != v_c39) return;
              if (v_c33 != v_c38) return;
              slog::join_probe_old<2,2>(mp_hsb_ansindex616, mp_hsb_ansdelta623, std::array<u64,2>{v_c33, v_c40}, [&](const std::array<u64,2>& m673) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex617, mp_hsb_ansdelta624, std::array<u64,2>{v_c33, v_c22}, [&](const std::array<u64,2>& m674) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex618, mp_hsb_ansdelta625, std::array<u64,2>{v_c33, v_c6}, [&](const std::array<u64,2>& m675) {
                    slog::join_probe_old<3,2>(mp_mskindex619, mp_mskdelta626, std::array<u64,3>{v_c34, v_c22, 0}, [&](const std::array<u64,3>& m676) {
                      u64 v_c41 = m676[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex620, mp_msk_ansdelta627, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m677) {
                        u64 v_c42 = m677[1];
                        u64 v_c43 = _prim_bxor(db, v_c34, v_c35);
                        if (v_c43 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex621, mp_hsbdelta628, std::array<u64,2>{v_c33, v_c43}, [&](const std::array<u64,2>& m678) {
                          u64 v_c44 = _prim_band(db, v_c34, v_c6);
                          if (v_c44 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c100 = _prim_gt(db, v_c44, v_c31);
                          if (v_c100 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c100) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c32, v_c42, v_c40, v_c36, v_c37});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c42, v_c40, v_c37, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst1EMh391 const6b86b273ff34fce19d6b804e)) (scan $sup5638x67x0x0x0 __t51a7389 k t v) (body (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t51a7389) (exists mp_has0_ans (1 0) 1 __tconst1EMh391) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t3RjP390) (join mp_has0_ans (0 1) 2 __t3RjP390 __tconst1EMh391)) (head (emit mp_put_soft_ans (0 1) __t51a7389 t)) map.slog:68 #f)
  class ReadTask686 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex680;  slog::Index** mp_has0_ansindex681;  slog::Index** mp_has0index682;  slog::Index** mp_has0_ansindex683;  slog::Index** mp_put_softdelta684;  slog::Index** mp_has0delta685;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel688->getIndex(ord687, false);
      outer_rel = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord689({1, 2, 3, 0});
      slog::Relation* readrel690 = db->getRelation("mp_put_soft");
      mp_put_softindex680 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 3, 0});
      slog::Relation* readrel692 = db->getRelation("mp_put_soft");
      mp_put_softdelta684 = readrel692->getIndex(ord691, true);
      std::vector<u16> ord693({1, 0});
      slog::Relation* readrel694 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex681 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 0});
      slog::Relation* readrel696 = db->getRelation("mp_has0");
      mp_has0index682 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 2, 0});
      slog::Relation* readrel698 = db->getRelation("mp_has0");
      mp_has0delta685 = readrel698->getIndex(ord697, true);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex683 = readrel700->getIndex(ord699, false);
  
    }
    ReadTask686(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c102 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c103 = _t[2];
        u64 v_c50 = _t[3];
        slog::join_probe_old<4,4>(mp_put_softindex680, mp_put_softdelta684, std::array<u64,4>{v_c103, v_c7, v_c50, v_c102}, [&](const std::array<u64,4>& m701) {
          if (!slog::exists_probe<2,1>(mp_has0_ansindex681, std::array<u64,2>{v_c101, 0})) return;
          slog::join_probe_old<3,2>(mp_has0index682, mp_has0delta685, std::array<u64,3>{v_c103, v_c7, 0}, [&](const std::array<u64,3>& m702) {
            u64 v_c104 = m702[2];
            slog::join_probe<2,2>(mp_has0_ansindex683, std::array<u64,2>{v_c104, v_c101}, [&](const std::array<u64,2>& m703) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c102, v_c103}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:$sup5638x67x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask686* _cont = new ReadTask686(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask686(db,b), false);
  // (crule (pre (let __tconst0tqB177 const6b86b273ff34fce19d6b804e)) (scan mp_put __t4dVF176 __t9qsM175 k v) (body (join mbranch (0 1 2 3 4) 1 __t9qsM175 p m l r) (let __t82n0178 (band k m)) (cmp lt __t82n0178 __tconst0tqB177)) (head (emit $sup5638x40x0x0x0 (4 2 3 5 0 1 6) p l m r __t4dVF176 k v)) map.slog:41 #f)
  class ReadTask705 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex704;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord706({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel707 = db->getRelation("$sup5638x40x0x0x0");
      head_index[0] = readrel707->getIndex(ord706, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord708({0, 1, 2, 3, 4});
      slog::Relation* readrel709 = db->getRelation("mbranch");
      mbranchindex704 = readrel709->getIndex(ord708, false);
  
    }
    ReadTask705(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        u64 v_c107 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c50 = _t[3];
        slog::join_probe<5,1>(mbranchindex704, std::array<u64,5>{v_c107, 0, 0, 0, 0}, [&](const std::array<u64,5>& m710) {
          u64 v_c12 = m710[1]; u64 v_c11 = m710[2]; u64 v_c10 = m710[3]; u64 v_c8 = m710[4];
          u64 v_c108 = _prim_band(db, v_c7, v_c11);
          if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          u64 v_c109 = _prim_lt(db, v_c108, v_c105);
          if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          if (!v_c109) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c12, v_c10, v_c11, v_c8, v_c106, v_c7, v_c50}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask705* _cont = new ReadTask705(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask705(db,b), false);
  // (crule (pre (let __tconst291W171 const6b86b273ff34fce19d6b804e)) (scan mp_has0_ans __t8KSH173 a) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t8KSH173 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t5APc170 m p r) (exists mp_has0 (0 2 1) 2 __t5APc170 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4G6v169) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t5APc170 k __t4G6v169) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4QPc174) (join-old mp_msk_ans (0 1) 2 (0 1) __t4QPc174 p) (let __t1a5T172 (band k m)) (cmp lt __t1a5T172 __tconst291W171)) (head (emit mp_has0_ans (0 1) __t5APc170 a)) map.slog:61 #f)
  class ReadTask730 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index712;  slog::Index** mbranchindex713;  slog::Index** mp_has0index714;  slog::Index** mp_mskindex715;  slog::Index** $sup5638x60x0x0x0index716;  slog::Index** mp_has0index717;  slog::Index** mp_mskindex718;  slog::Index** mp_msk_ansindex719;  slog::Index** mbranchindex720;  slog::Index** mp_has0index721;  slog::Index** mp_mskindex722;  slog::Index** mp_msk_ansindex723;  slog::Index** mp_has0delta724;  slog::Index** $sup5638x60x0x0x0delta725;  slog::Index** mbranchdelta726;  slog::Index** mp_has0delta727;  slog::Index** mp_mskdelta728;  slog::Index** mp_msk_ansdelta729;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord731({0, 1});
      slog::Relation* readrel732 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel732->getIndex(ord731, false);
      outer_rel = db->getRelation("mp_has0_ans");
      std::vector<u16> ord733({0, 2, 1});
      slog::Relation* readrel734 = db->getRelation("mp_has0");
      mp_has0index712 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({0, 2, 1});
      slog::Relation* readrel736 = db->getRelation("mp_has0");
      mp_has0delta724 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({3, 0, 1, 2, 4});
      slog::Relation* readrel738 = db->getRelation("mbranch");
      mbranchindex713 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({2, 0, 1});
      slog::Relation* readrel740 = db->getRelation("mp_has0");
      mp_has0index714 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 2, 0});
      slog::Relation* readrel742 = db->getRelation("mp_msk");
      mp_mskindex715 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel744 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index716 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel746 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0delta725 = readrel746->getIndex(ord745, true);
      std::vector<u16> ord747({0, 2, 1});
      slog::Relation* readrel748 = db->getRelation("mp_has0");
      mp_has0index717 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 2, 0});
      slog::Relation* readrel750 = db->getRelation("mp_msk");
      mp_mskindex718 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 0});
      slog::Relation* readrel752 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex719 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({1, 2, 3, 4, 0});
      slog::Relation* readrel754 = db->getRelation("mbranch");
      mbranchindex720 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({1, 2, 3, 4, 0});
      slog::Relation* readrel756 = db->getRelation("mbranch");
      mbranchdelta726 = readrel756->getIndex(ord755, true);
      std::vector<u16> ord757({0, 2, 1});
      slog::Relation* readrel758 = db->getRelation("mp_has0");
      mp_has0index721 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({0, 2, 1});
      slog::Relation* readrel760 = db->getRelation("mp_has0");
      mp_has0delta727 = readrel760->getIndex(ord759, true);
      std::vector<u16> ord761({1, 2, 0});
      slog::Relation* readrel762 = db->getRelation("mp_msk");
      mp_mskindex722 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("mp_msk");
      mp_mskdelta728 = readrel764->getIndex(ord763, true);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex723 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({0, 1});
      slog::Relation* readrel768 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta729 = readrel768->getIndex(ord767, true);
  
    }
    ReadTask730(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
  
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
        slog::join_probe_old<3,1>(mp_has0index712, mp_has0delta724, std::array<u64,3>{v_c111, 0, 0}, [&](const std::array<u64,3>& m769) {
          u64 v_c7 = m769[1]; u64 v_c10 = m769[2];
          if (!slog::exists_probe<5,1>(mbranchindex713, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index714, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex715, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x60x0x0x0index716, $sup5638x60x0x0x0delta725, std::array<u64,6>{v_c7, v_c10, 0, 0, 0, 0}, [&](const std::array<u64,6>& m770) {
            u64 v_c113 = m770[2]; u64 v_c11 = m770[3]; u64 v_c12 = m770[4]; u64 v_c8 = m770[5];
            if (!slog::exists_probe<3,2>(mp_has0index717, std::array<u64,3>{v_c113, v_c7, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex718, std::array<u64,3>{v_c7, v_c11, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex719, std::array<u64,2>{v_c12, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex720, mbranchdelta726, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m771) {
              u64 v_c114 = m771[4];
              slog::join_probe_old<3,3>(mp_has0index721, mp_has0delta727, std::array<u64,3>{v_c113, v_c7, v_c114}, [&](const std::array<u64,3>& m772) {
                slog::join_probe_old<3,2>(mp_mskindex722, mp_mskdelta728, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m773) {
                  u64 v_c115 = m773[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex723, mp_msk_ansdelta729, std::array<u64,2>{v_c115, v_c12}, [&](const std::array<u64,2>& m774) {
                    u64 v_c116 = _prim_band(db, v_c7, v_c11);
                    if (v_c116 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c117 = _prim_lt(db, v_c116, v_c110);
                    if (v_c117 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c117) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c113, v_c112}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_has0_ans", _fires);
  
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
  // (crule (pre (let __tconst1GO9299 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t0IP7301 __t8ocD300 k) (body (exists mp_msk (1 2 0) 1 k) (join $sup5638x59x0x0x0 (0 1 2 3 4 5) 2 __t0IP7301 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t8ocD300) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t6Y68302) (join mp_msk_ans (0 1) 1 __t6Y68302 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t0IP7301 __tconst1GO9299)) map.slog:60 #f)
  class ReadTask782 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex776;  slog::Index** $sup5638x59x0x0x0index777;  slog::Index** mbranchindex778;  slog::Index** mp_mskindex779;  slog::Index** mp_msk_ansindex780;  slog::Index** mp_mskdelta781;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord783({0, 1});
      slog::Relation* readrel784 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel784->getIndex(ord783, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord785({1, 2, 0});
      slog::Relation* readrel786 = db->getRelation("mp_msk");
      mp_mskindex776 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel788 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index777 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 3, 4, 0});
      slog::Relation* readrel790 = db->getRelation("mbranch");
      mbranchindex778 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("mp_msk");
      mp_mskindex779 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("mp_msk");
      mp_mskdelta781 = readrel794->getIndex(ord793, true);
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex780 = readrel796->getIndex(ord795, false);
  
    }
    ReadTask782(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex776, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x59x0x0x0index777, std::array<u64,6>{v_c119, v_c7, 0, 0, 0, 0}, [&](const std::array<u64,6>& m797) {
          u64 v_c10 = m797[2]; u64 v_c11 = m797[3]; u64 v_c12 = m797[4]; u64 v_c8 = m797[5];
          slog::join_probe<5,5>(mbranchindex778, std::array<u64,5>{v_c12, v_c11, v_c10, v_c8, v_c120}, [&](const std::array<u64,5>& m798) {
            slog::join_probe_old<3,2>(mp_mskindex779, mp_mskdelta781, std::array<u64,3>{v_c7, v_c11, 0}, [&](const std::array<u64,3>& m799) {
              u64 v_c121 = m799[2];
              slog::join_probe<2,1>(mp_msk_ansindex780, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m800) {
                u64 v_c6 = m800[1];
                if (v_c12 == v_c6) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c119, v_c118}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask782* _cont = new ReadTask782(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask782(db,b), false);
}

