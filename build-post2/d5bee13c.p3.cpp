
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const721c36ff691f951d83718d83;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste711e3685c3e87fc5763620f;
extern u64 v_constfdb0a95399e17c48d6f65653;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_c8b2f8e8a1edfca6a(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst43q5382 const5feceb66ffc86f38d952786c)) (scan mp_get __t1KiE384 r k) (body (exists $sup5638x52x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_get (2 0 1) 1 k) (join mp_get_ans (0 1) 1 __t1KiE384 v) (join $sup5638x52x0x0x0 (1 5 0 2 3 4) 2 k r __t9K8V381 l m p) (exists mp_get (0 2 1) 2 __t9K8V381 k) (join mbranch (1 2 3 4 0) 4 p m l r __t5bK8380) (join mp_get (0 2 1) 3 __t9K8V381 k __t5bK8380) (let __t0f7P383 (band k m)) (cmp gt __t0f7P383 __tconst43q5382)) (head (emit mp_get_ans (0 1) __t9K8V381 v)) map.slog:53 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x52x0x0x0index0;  slog::Index** mbranchindex1;  slog::Index** mp_getindex2;  slog::Index** mp_get_ansindex3;  slog::Index** $sup5638x52x0x0x0index4;  slog::Index** mp_getindex5;  slog::Index** mbranchindex6;  slog::Index** mp_getindex7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("mp_get_ans");
      head_index[0] = readrel10->getIndex(ord9, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord11({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel12 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index0 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({4, 0, 1, 2, 3});
      slog::Relation* readrel14 = db->getRelation("mbranch");
      mbranchindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({2, 0, 1});
      slog::Relation* readrel16 = db->getRelation("mp_get");
      mp_getindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("mp_get_ans");
      mp_get_ansindex3 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel20 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({0, 2, 1});
      slog::Relation* readrel22 = db->getRelation("mp_get");
      mp_getindex5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 2, 3, 4, 0});
      slog::Relation* readrel24 = db->getRelation("mbranch");
      mbranchindex6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 2, 1});
      slog::Relation* readrel26 = db->getRelation("mp_get");
      mp_getindex7 = readrel26->getIndex(ord25, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<6,2>($sup5638x52x0x0x0index0, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_getindex2, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(mp_get_ansindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m27) {
          u64 v_c4 = m27[1];
          slog::join_probe<6,2>($sup5638x52x0x0x0index4, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,6>& m28) {
            u64 v_c5 = m28[2]; u64 v_c6 = m28[3]; u64 v_c7 = m28[4]; u64 v_c8 = m28[5];
            if (!slog::exists_probe<3,2>(mp_getindex5, std::array<u64,3>{v_c5, v_c3, 0})) return;
            slog::join_probe<5,4>(mbranchindex6, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m29) {
              u64 v_c9 = m29[4];
              slog::join_probe<3,3>(mp_getindex7, std::array<u64,3>{v_c5, v_c3, v_c9}, [&](const std::array<u64,3>& m30) {
                u64 v_c10 = _prim_band(db, v_c3, v_c7);
                if (v_c10 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c11 = _prim_gt(db, v_c10, v_c0);
                if (v_c11 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c11) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c4}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan $sup5638x42x0x0x1 __t6Bbs459 __t5aM3462 k l m p r v) (body (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t6Bbs459 k v) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_msk (1 2 0) 3 k m __t5aM3462) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t9ixF458) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Bbs459 k __t9ixF458 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t5aM3462) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index32;  slog::Index** mp_putindex33;  slog::Index** mp_mskindex34;  slog::Index** mp_putindex35;  slog::Index** mp_msk_ansindex36;  slog::Index** mbranchindex37;  slog::Index** mp_putindex38;  slog::Index** mp_mskindex39;  slog::Index** mp_putindex40;  slog::Index** mp_msk_ansindex41;  slog::Index** mp_put_ansindex42;  slog::Index** mbranchdelta43;  slog::Index** mp_putdelta44;  slog::Index** mp_mskdelta45;  slog::Index** mp_putdelta46;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord48({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel49 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index32 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({3, 0, 2, 1});
      slog::Relation* readrel51 = db->getRelation("mp_put");
      mp_putindex33 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("mp_msk");
      mp_mskindex34 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 3, 0});
      slog::Relation* readrel55 = db->getRelation("mp_put");
      mp_putindex35 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex36 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 3, 4, 0});
      slog::Relation* readrel59 = db->getRelation("mbranch");
      mbranchindex37 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 3, 4, 0});
      slog::Relation* readrel61 = db->getRelation("mbranch");
      mbranchdelta43 = readrel61->getIndex(ord60, true);
      std::vector<u16> ord62({0, 2, 1, 3});
      slog::Relation* readrel63 = db->getRelation("mp_put");
      mp_putindex38 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 2, 1, 3});
      slog::Relation* readrel65 = db->getRelation("mp_put");
      mp_putdelta44 = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({1, 2, 0});
      slog::Relation* readrel67 = db->getRelation("mp_msk");
      mp_mskindex39 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("mp_msk");
      mp_mskdelta45 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({1, 2, 3, 0});
      slog::Relation* readrel71 = db->getRelation("mp_put");
      mp_putindex40 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 2, 3, 0});
      slog::Relation* readrel73 = db->getRelation("mp_put");
      mp_putdelta46 = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({0, 1});
      slog::Relation* readrel75 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex41 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("mp_put_ans");
      mp_put_ansindex42 = readrel77->getIndex(ord76, false);
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c2 = _t[6];
        u64 v_c4 = _t[7];
        slog::join_probe<7,7>($sup5638x42x0x0x0index32, std::array<u64,7>{v_c8, v_c6, v_c7, v_c2, v_c13, v_c3, v_c4}, [&](const std::array<u64,7>& m78) {
          if (!slog::exists_probe<4,3>(mp_putindex33, std::array<u64,4>{v_c4, v_c13, v_c3, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex34, std::array<u64,3>{v_c3, v_c7, v_c14})) return;
          if (!slog::exists_probe<4,3>(mp_putindex35, std::array<u64,4>{v_c2, v_c3, v_c4, 0})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex36, std::array<u64,2>{v_c14, v_c8})) return;
          slog::join_probe_old<5,4>(mbranchindex37, mbranchdelta43, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m79) {
            u64 v_c15 = m79[4];
            slog::join_probe_old<4,4>(mp_putindex38, mp_putdelta44, std::array<u64,4>{v_c13, v_c3, v_c15, v_c4}, [&](const std::array<u64,4>& m80) {
              slog::join_probe_old<3,3>(mp_mskindex39, mp_mskdelta45, std::array<u64,3>{v_c3, v_c7, v_c14}, [&](const std::array<u64,3>& m81) {
                slog::join_probe_old<4,3>(mp_putindex40, mp_putdelta46, std::array<u64,4>{v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,4>& m82) {
                  u64 v_c16 = m82[3];
                  slog::join_probe<2,2>(mp_msk_ansindex41, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m83) {
                    slog::join_probe<2,1>(mp_put_ansindex42, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m84) {
                      u64 v_c17 = m84[1];
                      u64 v_c18 = _prim_band(db, v_c3, v_c7);
                      if (v_c18 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c19 = _prim_gt(db, v_c18, v_c12);
                      if (v_c19 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c19) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c13, v_c17, v_c6, v_c7, v_c8});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c6, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), false);
  // (crule (pre (let __tconst83Kb290 const6b86b273ff34fce19d6b804e)) (probe mp_hsb (1 0) 1 __tconst83Kb290 __t4bOq291) (body) (head (emit mp_hsb_ans (0 1) __t4bOq291 __tconst83Kb290)) map.slog:18 #f)
  class ReadTask86 : public slog::Task
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
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("mp_hsb_ans");
      head_index[0] = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 0});
      slog::Relation* readrel90 = db->getRelation("mp_hsb");
      driver_index = readrel90->getIndex(ord89, true);
  
    }
    ReadTask86(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c20, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m91) {
        u64 v_c21 = m91[1];
        if (buckethash(v_c21) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c20}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:18", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask86* _cont = new ReadTask86(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask86(db,b), false);
  // (crule (pre) (scan eval_ans __t6HuT359 vr) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t6HuT359 er rho2 t) (exists $sup70016x95x0x0x1 (3 5 6 1 0 2 4 7) 3 er rho2 t) (exists $sup70016x95x0x0x0 (2 4 0 1 3 5) 2 er t) (exists mp_put (3 0 2 1) 1 t) (exists letrec (2 3 0 1) 1 er) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (1 0) 1 rho2) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho2 t __t63JF360 eb) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 3 eb t er) (exists letrec (2 3 0 1) 2 er eb) (exists eval_ans (0 1) 1 __t63JF360) (join-old $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 4 (2 5 6 3 0 1 4 7) eb rho2 t er __t7DhJ358 __t0Rig361 rho x) (join-old $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old letrec (1 2 3 0) 3 (1 2 3 0) x er eb __t0Sks357) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old mp_put_ans (0 1) 2 (0 1) __t0Rig361 rho2) (join-old eval_ans (0 1) 1 (0 1) __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask121 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex92;  slog::Index** $sup70016x95x0x0x1index93;  slog::Index** $sup70016x95x0x0x0index94;  slog::Index** mp_putindex95;  slog::Index** letrecindex96;  slog::Index** evalindex97;  slog::Index** mp_put_ansindex98;  slog::Index** evalindex99;  slog::Index** $sup70016x95x0x0x0index100;  slog::Index** letrecindex101;  slog::Index** eval_ansindex102;  slog::Index** $sup70016x95x0x0x1index103;  slog::Index** $sup70016x95x0x0x0index104;  slog::Index** mp_putindex105;  slog::Index** evalindex106;  slog::Index** mp_put_ansindex107;  slog::Index** letrecindex108;  slog::Index** evalindex109;  slog::Index** mp_put_ansindex110;  slog::Index** eval_ansindex111;  slog::Index** evaldelta112;  slog::Index** evaldelta113;  slog::Index** $sup70016x95x0x0x1delta114;  slog::Index** $sup70016x95x0x0x0delta115;  slog::Index** mp_putdelta116;  slog::Index** letrecdelta117;  slog::Index** evaldelta118;  slog::Index** mp_put_ansdelta119;  slog::Index** eval_ansdelta120;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("eval_ans");
      head_index[0] = readrel123->getIndex(ord122, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord124({0, 1, 2, 3});
      slog::Relation* readrel125 = db->getRelation("eval");
      evalindex92 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1, 2, 3});
      slog::Relation* readrel127 = db->getRelation("eval");
      evaldelta112 = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({3, 5, 6, 1, 0, 2, 4, 7});
      slog::Relation* readrel129 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index93 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({2, 4, 0, 1, 3, 5});
      slog::Relation* readrel131 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index94 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({3, 0, 2, 1});
      slog::Relation* readrel133 = db->getRelation("mp_put");
      mp_putindex95 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({2, 3, 0, 1});
      slog::Relation* readrel135 = db->getRelation("letrec");
      letrecindex96 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({3, 1, 0, 2});
      slog::Relation* readrel137 = db->getRelation("eval");
      evalindex97 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("mp_put_ans");
      mp_put_ansindex98 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({2, 3, 0, 1});
      slog::Relation* readrel141 = db->getRelation("eval");
      evalindex99 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({2, 3, 0, 1});
      slog::Relation* readrel143 = db->getRelation("eval");
      evaldelta113 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel145 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index100 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({2, 3, 0, 1});
      slog::Relation* readrel147 = db->getRelation("letrec");
      letrecindex101 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1});
      slog::Relation* readrel149 = db->getRelation("eval_ans");
      eval_ansindex102 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel151 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index103 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel153 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1delta114 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel155 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index104 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel157 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0delta115 = readrel157->getIndex(ord156, true);
      std::vector<u16> ord158({0, 2, 1, 3});
      slog::Relation* readrel159 = db->getRelation("mp_put");
      mp_putindex105 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 2, 1, 3});
      slog::Relation* readrel161 = db->getRelation("mp_put");
      mp_putdelta116 = readrel161->getIndex(ord160, true);
      std::vector<u16> ord162({2, 3, 0, 1});
      slog::Relation* readrel163 = db->getRelation("eval");
      evalindex106 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("mp_put_ans");
      mp_put_ansindex107 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 3, 0});
      slog::Relation* readrel167 = db->getRelation("letrec");
      letrecindex108 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 2, 3, 0});
      slog::Relation* readrel169 = db->getRelation("letrec");
      letrecdelta117 = readrel169->getIndex(ord168, true);
      std::vector<u16> ord170({2, 3, 0, 1});
      slog::Relation* readrel171 = db->getRelation("eval");
      evalindex109 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({2, 3, 0, 1});
      slog::Relation* readrel173 = db->getRelation("eval");
      evaldelta118 = readrel173->getIndex(ord172, true);
      std::vector<u16> ord174({0, 1});
      slog::Relation* readrel175 = db->getRelation("mp_put_ans");
      mp_put_ansindex110 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("mp_put_ans");
      mp_put_ansdelta119 = readrel177->getIndex(ord176, true);
      std::vector<u16> ord178({0, 1});
      slog::Relation* readrel179 = db->getRelation("eval_ans");
      eval_ansindex111 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("eval_ans");
      eval_ansdelta120 = readrel181->getIndex(ord180, true);
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        slog::join_probe_old<4,1>(evalindex92, evaldelta112, std::array<u64,4>{v_c22, 0, 0, 0}, [&](const std::array<u64,4>& m182) {
          u64 v_c24 = m182[1]; u64 v_c25 = m182[2]; u64 v_c26 = m182[3];
          if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index93, std::array<u64,8>{v_c24, v_c25, v_c26, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<6,2>($sup70016x95x0x0x0index94, std::array<u64,6>{v_c24, v_c26, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex95, std::array<u64,4>{v_c26, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letrecindex96, std::array<u64,4>{v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex97, std::array<u64,4>{v_c26, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_put_ansindex98, std::array<u64,2>{v_c25, 0})) return;
          slog::join_probe_old<4,2>(evalindex99, evaldelta113, std::array<u64,4>{v_c25, v_c26, 0, 0}, [&](const std::array<u64,4>& m183) {
            u64 v_c27 = m183[2]; u64 v_c28 = m183[3];
            if (!slog::exists_probe<6,3>($sup70016x95x0x0x0index100, std::array<u64,6>{v_c28, v_c26, v_c24, 0, 0, 0})) return;
            if (!slog::exists_probe<4,2>(letrecindex101, std::array<u64,4>{v_c24, v_c28, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex102, std::array<u64,2>{v_c27, 0})) return;
            slog::join_probe_old<8,4>($sup70016x95x0x0x1index103, $sup70016x95x0x0x1delta114, std::array<u64,8>{v_c28, v_c25, v_c26, v_c24, 0, 0, 0, 0}, [&](const std::array<u64,8>& m184) {
              u64 v_c29 = m184[4]; u64 v_c30 = m184[5]; u64 v_c31 = m184[6]; u64 v_c32 = m184[7];
              slog::join_probe_old<6,6>($sup70016x95x0x0x0index104, $sup70016x95x0x0x0delta115, std::array<u64,6>{v_c29, v_c31, v_c26, v_c28, v_c24, v_c32}, [&](const std::array<u64,6>& m185) {
                slog::join_probe_old<4,4>(mp_putindex105, mp_putdelta116, std::array<u64,4>{v_c30, v_c32, v_c31, v_c26}, [&](const std::array<u64,4>& m186) {
                  if (!slog::exists_probe<4,3>(evalindex106, std::array<u64,4>{v_c31, v_c26, v_c29, 0})) return;
                  if (!slog::exists_probe<2,2>(mp_put_ansindex107, std::array<u64,2>{v_c30, v_c25})) return;
                  slog::join_probe_old<4,3>(letrecindex108, letrecdelta117, std::array<u64,4>{v_c32, v_c24, v_c28, 0}, [&](const std::array<u64,4>& m187) {
                    u64 v_c33 = m187[3];
                    slog::join_probe_old<4,4>(evalindex109, evaldelta118, std::array<u64,4>{v_c31, v_c26, v_c29, v_c33}, [&](const std::array<u64,4>& m188) {
                      slog::join_probe_old<2,2>(mp_put_ansindex110, mp_put_ansdelta119, std::array<u64,2>{v_c30, v_c25}, [&](const std::array<u64,2>& m189) {
                        slog::join_probe_old<2,1>(eval_ansindex111, eval_ansdelta120, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m190) {
                          u64 v_c4 = m190[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c4}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre (let __trid8LqO1205 constfee494ff4827aeb0635bb714) (let __trel2H7m1206 const20347926ddb307a8e2bdb71b) (let __tcol2B611207 constd4735e3a265e16eee03f5971)) (scan mp_del_ans __t33MJ441 __v0) (body (join-old mp_del (0 2 1) 1 (0 2 1) __t33MJ441 k r) (exists mp_msk (1 2 0) 1 k) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t0gIW440) (join mp_msk_ans (0 1) 2 __t0gIW440 p)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8LqO1205 __trel2H7m1206 __tcol2B611207 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __0kM11204 p m l __v0)) map.slog:85 #f)
  class ReadTask202 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex191;  slog::Index** mp_mskindex192;  slog::Index** $sup5638x84x0x0x0index193;  slog::Index** mp_msk_ansindex194;  slog::Index** mp_mskindex195;  slog::Index** mp_msk_ansindex196;  slog::Index** mp_deldelta197;  slog::Index** mp_mskdelta198;
    u32 sid200;  u32 sid199;  u32 sid201;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord203({0, 2, 1});
      slog::Relation* readrel204 = db->getRelation("mp_del");
      mp_delindex191 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 2, 1});
      slog::Relation* readrel206 = db->getRelation("mp_del");
      mp_deldelta197 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("mp_msk");
      mp_mskindex192 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel210 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index193 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex194 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("mp_msk");
      mp_mskindex195 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("mp_msk");
      mp_mskdelta198 = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex196 = readrel218->getIndex(ord217, false);
      sid200 = db->getRelation("_enum")->getStructId();
      sid199 = db->getRelation("mbranch")->getStructId();
      sid201 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_constfee494ff4827aeb0635bb714;
      u64 v_c35 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c36 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe_old<3,1>(mp_delindex191, mp_deldelta197, std::array<u64,3>{v_c37, 0, 0}, [&](const std::array<u64,3>& m219) {
          u64 v_c3 = m219[1]; u64 v_c2 = m219[2];
          if (!slog::exists_probe<3,1>(mp_mskindex192, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x84x0x0x0index193, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,6>& m220) {
            u64 v_c38 = m220[2]; u64 v_c6 = m220[3]; u64 v_c7 = m220[4]; u64 v_c8 = m220[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex194, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe_old<3,2>(mp_mskindex195, mp_mskdelta198, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m221) {
              u64 v_c39 = m221[2];
              slog::join_probe<2,2>(mp_msk_ansindex196, std::array<u64,2>{v_c39, v_c8}, [&](const std::array<u64,2>& m222) {
                ++_fires;
                if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid199 || decode_struct_id(v_c6) == sid200 || decode_struct_id(v_c6) == sid201))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c35, v_c36, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c6, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask202* _cont = new ReadTask202(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask202(db,b), false);
  // (crule (pre (let __tconst43q5382 const5feceb66ffc86f38d952786c)) (scan mbranch __t5bK8380 p m l r) (body (exists mp_get (1 2 0) 1 __t5bK8380) (exists mp_get (1 2 0) 1 r) (join $sup5638x52x0x0x0 (2 3 4 5 0 1) 4 l m p r __t9K8V381 k) (join-old mp_get (0 2 1) 3 (0 2 1) __t9K8V381 k __t5bK8380) (join-old mp_get (1 2 0) 2 (1 2 0) r k __t1KiE384) (join mp_get_ans (0 1) 1 __t1KiE384 v) (let __t0f7P383 (band k m)) (cmp gt __t0f7P383 __tconst43q5382)) (head (emit mp_get_ans (0 1) __t9K8V381 v)) map.slog:53 #f)
  class ReadTask231 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex223;  slog::Index** mp_getindex224;  slog::Index** $sup5638x52x0x0x0index225;  slog::Index** mp_getindex226;  slog::Index** mp_getindex227;  slog::Index** mp_get_ansindex228;  slog::Index** mp_getdelta229;  slog::Index** mp_getdelta230;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("mp_get_ans");
      head_index[0] = readrel233->getIndex(ord232, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("mp_get");
      mp_getindex223 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("mp_get");
      mp_getindex224 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel239 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index225 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 2, 1});
      slog::Relation* readrel241 = db->getRelation("mp_get");
      mp_getindex226 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({0, 2, 1});
      slog::Relation* readrel243 = db->getRelation("mp_get");
      mp_getdelta229 = readrel243->getIndex(ord242, true);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("mp_get");
      mp_getindex227 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("mp_get");
      mp_getdelta230 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("mp_get_ans");
      mp_get_ansindex228 = readrel249->getIndex(ord248, false);
  
    }
    ReadTask231(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c2 = _t[4];
        if (!slog::exists_probe<3,1>(mp_getindex223, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_getindex224, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x52x0x0x0index225, std::array<u64,6>{v_c6, v_c7, v_c8, v_c2, 0, 0}, [&](const std::array<u64,6>& m250) {
          u64 v_c5 = m250[4]; u64 v_c3 = m250[5];
          slog::join_probe_old<3,3>(mp_getindex226, mp_getdelta229, std::array<u64,3>{v_c5, v_c3, v_c9}, [&](const std::array<u64,3>& m251) {
            slog::join_probe_old<3,2>(mp_getindex227, mp_getdelta230, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m252) {
              u64 v_c1 = m252[2];
              slog::join_probe<2,1>(mp_get_ansindex228, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m253) {
                u64 v_c4 = m253[1];
                u64 v_c10 = _prim_band(db, v_c3, v_c7);
                if (v_c10 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c40 = _prim_gt(db, v_c10, v_c0);
                if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c40) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c4}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask231* _cont = new ReadTask231(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask231(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t8x7Q785 __v3) (body (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists $sup5638x29x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t8x7Q785 __v3) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t8x7Q785) (join-old mp_hsb_ans (0 1) 1 (0 1) __t8x7Q785 __v1) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t8x7Q785 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join-old mp_hsb_ans (0 1) 1 (0 1) __t8x7Q785 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t8x7Q785 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t8x7Q785 __v0 __v3 __v1 __t7O3e781 dup6QI21998 dup4FCe1999 p0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join-old mp_msk_ans (0 1) 1 (0 1) __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask276 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex255;  slog::Index** $sup5638x29x0x0x2index256;  slog::Index** $sup5638x29x0x0x1index257;  slog::Index** mp_hsb_ansindex258;  slog::Index** $sup5638x29x0x0x2index259;  slog::Index** mp_mskindex260;  slog::Index** mp_hsb_ansindex261;  slog::Index** $sup5638x29x0x0x1index262;  slog::Index** $sup5638x29x0x0x2index263;  slog::Index** $sup5638x29x0x0x1index264;  slog::Index** $sup5638x29x0x0x0index265;  slog::Index** mp_joinindex266;  slog::Index** mp_mskindex267;  slog::Index** mp_msk_ansindex268;  slog::Index** mp_hsbindex269;  slog::Index** mp_hsb_ansdelta270;  slog::Index** mp_hsb_ansdelta271;  slog::Index** mp_joindelta272;  slog::Index** mp_mskdelta273;  slog::Index** mp_msk_ansdelta274;  slog::Index** mp_hsbdelta275;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex255 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel280 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index256 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel282 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index257 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex258 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta270 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel288 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index259 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({2, 0, 1});
      slog::Relation* readrel290 = db->getRelation("mp_msk");
      mp_mskindex260 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex261 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta271 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel296 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index262 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel298 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index263 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel300 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index264 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 0, 2, 3, 4});
      slog::Relation* readrel302 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index265 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 3, 4, 0});
      slog::Relation* readrel304 = db->getRelation("mp_join");
      mp_joinindex266 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 2, 3, 4, 0});
      slog::Relation* readrel306 = db->getRelation("mp_join");
      mp_joindelta272 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("mp_msk");
      mp_mskindex267 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 2, 0});
      slog::Relation* readrel310 = db->getRelation("mp_msk");
      mp_mskdelta273 = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex268 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta274 = readrel314->getIndex(ord313, true);
      std::vector<u16> ord315({0, 1});
      slog::Relation* readrel316 = db->getRelation("mp_hsb");
      mp_hsbindex269 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({0, 1});
      slog::Relation* readrel318 = db->getRelation("mp_hsb");
      mp_hsbdelta275 = readrel318->getIndex(ord317, true);
  
    }
    ReadTask276(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex255, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index256, std::array<u64,11>{v_c42, v_c43, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index257, std::array<u64,7>{v_c42, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(mp_hsb_ansindex258, mp_hsb_ansdelta270, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m319) {
          u64 v_c44 = m319[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index259, std::array<u64,11>{v_c42, v_c44, v_c43, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex260, std::array<u64,3>{v_c44, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex261, mp_hsb_ansdelta271, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m320) {
            u64 v_c17 = m320[1];
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index262, std::array<u64,7>{v_c42, v_c17, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index263, std::array<u64,11>{v_c42, v_c17, v_c43, v_c44, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m321) {
              u64 v_c45 = m321[4]; u64 v_c46 = m321[5]; u64 v_c47 = m321[6]; u64 v_c48 = m321[7]; u64 v_c49 = m321[8]; u64 v_c50 = m321[9]; u64 v_c51 = m321[10];
              if (v_c42 != v_c47) return;
              if (v_c42 != v_c46) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index264, std::array<u64,7>{v_c45, v_c48, v_c49, v_c50, v_c51, v_c42, v_c17}, [&](const std::array<u64,7>& m322) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index265, std::array<u64,5>{v_c48, v_c45, v_c49, v_c50, v_c51}, [&](const std::array<u64,5>& m323) {
                  slog::join_probe_old<5,5>(mp_joinindex266, mp_joindelta272, std::array<u64,5>{v_c48, v_c50, v_c49, v_c51, v_c45}, [&](const std::array<u64,5>& m324) {
                    slog::join_probe_old<3,2>(mp_mskindex267, mp_mskdelta273, std::array<u64,3>{v_c48, v_c44, 0}, [&](const std::array<u64,3>& m325) {
                      u64 v_c52 = m325[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex268, mp_msk_ansdelta274, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m326) {
                        u64 v_c53 = m326[1];
                        u64 v_c54 = _prim_bxor(db, v_c48, v_c49);
                        if (v_c54 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex269, mp_hsbdelta275, std::array<u64,2>{v_c42, v_c54}, [&](const std::array<u64,2>& m327) {
                          u64 v_c55 = _prim_band(db, v_c48, v_c17);
                          if (v_c55 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c56 = _prim_gt(db, v_c55, v_c41);
                          if (v_c56 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c56) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c45, v_c53, v_c43, v_c50, v_c51});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c53, v_c43, v_c51, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask276* _cont = new ReadTask276(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask276(db,b), false);
  // (crule (pre (let __trid94Ia1125 const721c36ff691f951d83718d83) (let __trel7NAa1126 constdd7bbf31ce5f578b9805e840) (let __tcol86vT1127 const5feceb66ffc86f38d952786c) (let __trel7mFy1128 constdd7bbf31ce5f578b9805e840) (let __tcol02kK1129 const6b86b273ff34fce19d6b804e)) (scan $sup5638x81x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid94Ia1125 __trel7NAa1126 __tcol86vT1127 (1 2 3 4 0)) (tycheck m (accept int) __trid94Ia1125 __trel7mFy1128 __tcol02kK1129 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __5GyT1124 k m)) map.slog:82 #f)
  class ReadTask329 : public slog::Task
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
    ReadTask329(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const721c36ff691f951d83718d83;
      u64 v_c58 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c38 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c2 = _t[5];
        ++_fires;
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c57, v_c58, v_c59, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c60, v_c61, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c3, v_c7}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:$sup5638x81x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask329* _cont = new ReadTask329(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask329(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t6N42442 p) (body (exists $sup5638x95x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t6N42442 q m) (join $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t6N42442 m n p q r u v)) map.slog:96 #f)
  class ReadTask334 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index330;  slog::Index** mp_mskindex331;  slog::Index** $sup5638x95x0x0x0index332;  slog::Index** mp_mskdelta333;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord335({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel336 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel336->getIndex(ord335, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord337({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel338 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index330 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1, 2});
      slog::Relation* readrel340 = db->getRelation("mp_msk");
      mp_mskindex331 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({0, 1, 2});
      slog::Relation* readrel342 = db->getRelation("mp_msk");
      mp_mskdelta333 = readrel342->getIndex(ord341, true);
      std::vector<u16> ord343({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel344 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index332 = readrel344->getIndex(ord343, false);
  
    }
    ReadTask334(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index330, std::array<u64,9>{v_c8, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex331, mp_mskdelta333, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m345) {
          u64 v_c63 = m345[1]; u64 v_c7 = m345[2];
          slog::join_probe<9,3>($sup5638x95x0x0x0index332, std::array<u64,9>{v_c7, v_c63, v_c8, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m346) {
            u64 v_c38 = m346[3]; u64 v_c6 = m346[4]; u64 v_c64 = m346[5]; u64 v_c2 = m346[6]; u64 v_c65 = m346[7]; u64 v_c4 = m346[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c38, v_c6, v_c62, v_c7, v_c64, v_c8, v_c63, v_c2, v_c65, v_c4}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask334* _cont = new ReadTask334(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask334(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_del_ans __t1FSo803 __v0) (body (exists mp_bld (4 0 1 2 3) 1 __v0) (join-old mp_del (0 2 1) 1 (0 2 1) __t1FSo803 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t2paO798 l m p) (exists mp_bld (1 2 3 4 0) 4 p m l __v0) (exists mp_del (0 2 1) 2 __t2paO798 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t29Nf797) (exists mp_del (0 2 1) 3 __t2paO798 k __t29Nf797) (join-old mp_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m l __v0 __t2Csk801) (join-old mp_del (0 2 1) 3 (0 2 1) __t2paO798 k __t29Nf797) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex347;  slog::Index** mp_delindex348;  slog::Index** mbranchindex349;  slog::Index** mp_delindex350;  slog::Index** mp_mskindex351;  slog::Index** $sup5638x84x0x0x0index352;  slog::Index** mp_bldindex353;  slog::Index** mp_delindex354;  slog::Index** mp_mskindex355;  slog::Index** mp_msk_ansindex356;  slog::Index** mbranchindex357;  slog::Index** mp_delindex358;  slog::Index** mp_bldindex359;  slog::Index** mp_delindex360;  slog::Index** mp_bld_ansindex361;  slog::Index** mp_mskindex362;  slog::Index** mp_msk_ansindex363;  slog::Index** mp_bld_ansindex364;  slog::Index** mp_deldelta365;  slog::Index** $sup5638x84x0x0x0delta366;  slog::Index** mbranchdelta367;  slog::Index** mp_blddelta368;  slog::Index** mp_deldelta369;  slog::Index** mp_mskdelta370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord372({0, 1});
      slog::Relation* readrel373 = db->getRelation("mp_del_ans");
      head_index[0] = readrel373->getIndex(ord372, false);
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord374({4, 0, 1, 2, 3});
      slog::Relation* readrel375 = db->getRelation("mp_bld");
      mp_bldindex347 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 2, 1});
      slog::Relation* readrel377 = db->getRelation("mp_del");
      mp_delindex348 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 2, 1});
      slog::Relation* readrel379 = db->getRelation("mp_del");
      mp_deldelta365 = readrel379->getIndex(ord378, true);
      std::vector<u16> ord380({4, 0, 1, 2, 3});
      slog::Relation* readrel381 = db->getRelation("mbranch");
      mbranchindex349 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({2, 0, 1});
      slog::Relation* readrel383 = db->getRelation("mp_del");
      mp_delindex350 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("mp_msk");
      mp_mskindex351 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel387 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index352 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel389 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta366 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({1, 2, 3, 4, 0});
      slog::Relation* readrel391 = db->getRelation("mp_bld");
      mp_bldindex353 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 2, 1});
      slog::Relation* readrel393 = db->getRelation("mp_del");
      mp_delindex354 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("mp_msk");
      mp_mskindex355 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex356 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 2, 3, 4, 0});
      slog::Relation* readrel399 = db->getRelation("mbranch");
      mbranchindex357 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 3, 4, 0});
      slog::Relation* readrel401 = db->getRelation("mbranch");
      mbranchdelta367 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 2, 1});
      slog::Relation* readrel403 = db->getRelation("mp_del");
      mp_delindex358 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 3, 4, 0});
      slog::Relation* readrel405 = db->getRelation("mp_bld");
      mp_bldindex359 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 3, 4, 0});
      slog::Relation* readrel407 = db->getRelation("mp_bld");
      mp_blddelta368 = readrel407->getIndex(ord406, true);
      std::vector<u16> ord408({0, 2, 1});
      slog::Relation* readrel409 = db->getRelation("mp_del");
      mp_delindex360 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 2, 1});
      slog::Relation* readrel411 = db->getRelation("mp_del");
      mp_deldelta369 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex361 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("mp_msk");
      mp_mskindex362 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 2, 0});
      slog::Relation* readrel417 = db->getRelation("mp_msk");
      mp_mskdelta370 = readrel417->getIndex(ord416, true);
      std::vector<u16> ord418({0, 1});
      slog::Relation* readrel419 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex363 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 1});
      slog::Relation* readrel421 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex364 = readrel421->getIndex(ord420, false);
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        if (!slog::exists_probe<5,1>(mp_bldindex347, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_delindex348, mp_deldelta365, std::array<u64,3>{v_c67, 0, 0}, [&](const std::array<u64,3>& m422) {
          u64 v_c3 = m422[1]; u64 v_c2 = m422[2];
          if (!slog::exists_probe<5,1>(mbranchindex349, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex350, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex351, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x84x0x0x0index352, $sup5638x84x0x0x0delta366, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,6>& m423) {
            u64 v_c68 = m423[2]; u64 v_c6 = m423[3]; u64 v_c7 = m423[4]; u64 v_c8 = m423[5];
            if (!slog::exists_probe<5,4>(mp_bldindex353, std::array<u64,5>{v_c8, v_c7, v_c6, v_c17, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex354, std::array<u64,3>{v_c68, v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex355, std::array<u64,3>{v_c3, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex356, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex357, mbranchdelta367, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m424) {
              u64 v_c69 = m424[4];
              if (!slog::exists_probe<3,3>(mp_delindex358, std::array<u64,3>{v_c68, v_c3, v_c69})) return;
              slog::join_probe_old<5,4>(mp_bldindex359, mp_blddelta368, std::array<u64,5>{v_c8, v_c7, v_c6, v_c17, 0}, [&](const std::array<u64,5>& m425) {
                u64 v_c70 = m425[4];
                slog::join_probe_old<3,3>(mp_delindex360, mp_deldelta369, std::array<u64,3>{v_c68, v_c3, v_c69}, [&](const std::array<u64,3>& m426) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex361, std::array<u64,2>{v_c70, 0})) return;
                  slog::join_probe_old<3,2>(mp_mskindex362, mp_mskdelta370, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m427) {
                    u64 v_c71 = m427[2];
                    slog::join_probe<2,2>(mp_msk_ansindex363, std::array<u64,2>{v_c71, v_c8}, [&](const std::array<u64,2>& m428) {
                      slog::join_probe<2,1>(mp_bld_ansindex364, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m429) {
                        u64 v_c72 = m429[1];
                        u64 v_c73 = _prim_band(db, v_c3, v_c7);
                        if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c74 = _prim_gt(db, v_c73, v_c66);
                        if (v_c74 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c74) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c68, v_c72}, std::array<u16,2>{0, 1});
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
        ReadTask371* _cont = new ReadTask371(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask371(db,b), false);
  // (crule (pre (let __tconst6VAa1189 constb9e118781cea1f9fa01462e0) (let __tconst14HM709 const60e3114d9b4b6577eea8cbc0) (let __tconst9fQa703 const844546be553b9dcbf71ae163) (let __tconst09sA701 const0453462f31b2bcf68e33a91f) (let __t7ua0707 (lempty))) (probe _enum (1 0) 1 __tconst6VAa1189 __t2zPu705) (body) (head (emit-temp temp3ow11811 __t7ua0707) (mkstruct primref (1 0) __t8M3S710 __tconst14HM709) (mkstruct boolean (1 0) __t5X6z706 __t2zPu705) (mkstruct sym (1 0) __t3RPz704 __tconst9fQa703) (mkstruct sym (1 0) __t1F7O702 __tconst09sA701)) kcfa.slog:52 #f)
  class ReadTask431 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3ow11811");
      head_rel[1] = db->getRelation("primref");
      head_rel[2] = db->getRelation("boolean");
      head_rel[3] = db->getRelation("sym");
      head_rel[4] = db->getRelation("sym");
      std::vector<u16> ord432({1, 0});
      slog::Relation* readrel433 = db->getRelation("_enum");
      driver_index = readrel433->getIndex(ord432, true);
  
    }
    ReadTask431(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c76 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c77 = v_const844546be553b9dcbf71ae163;
      u64 v_c78 = v_const0453462f31b2bcf68e33a91f;
      u64 v_c79 = _prim_lempty(db);
      if (v_c79 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:52"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c75, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m434) {
        u64 v_c80 = m434[1];
        if (buckethash(v_c80) != bucket) return;
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c79});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c76}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c80}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c77}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c78}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("kcfa.slog:52", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask431* _cont = new ReadTask431(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask431(db,b), true);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mbranch __t5mfE148 p m l r) (body (exists $sup5638x104x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists mp_union (1 2 0) 1 __t5mfE148) (exists mp_msk (1 2 0) 1 p) (join $sup5638x104x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t0kfV144 n q u v) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t0kfV144 __t5mfE148) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (1 2 0) 2 __t5mfE148 u) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t0kfV144 l m p r __t7PVf147) (exists mp_msk (1 2 0) 3 p n __t7PVf147) (exists mp_msk_ans (0 1) 2 __t7PVf147 q) (join mbranch (1 2 3 4 0) 4 q n u v __t2NO6142) (join mp_union (0 1 2) 3 __t0kfV144 __t5mfE148 __t2NO6142) (join mp_msk (1 2 0) 3 p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask454 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index435;  slog::Index** mp_unionindex436;  slog::Index** mp_mskindex437;  slog::Index** $sup5638x104x0x0x0index438;  slog::Index** mbranchindex439;  slog::Index** mp_unionindex440;  slog::Index** mp_mskindex441;  slog::Index** mp_msk_ansindex442;  slog::Index** mp_unionindex443;  slog::Index** $sup5638x104x0x0x1index444;  slog::Index** mp_mskindex445;  slog::Index** mp_msk_ansindex446;  slog::Index** mbranchindex447;  slog::Index** mp_unionindex448;  slog::Index** mp_mskindex449;  slog::Index** mp_msk_ansindex450;  slog::Index** mp_unionindex451;  slog::Index** mp_union_ansindex452;  slog::Index** mp_uniondelta453;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord455({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel456 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index435 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({1, 2, 0});
      slog::Relation* readrel458 = db->getRelation("mp_union");
      mp_unionindex436 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 2, 0});
      slog::Relation* readrel460 = db->getRelation("mp_msk");
      mp_mskindex437 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel462 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index438 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 3, 4, 0});
      slog::Relation* readrel464 = db->getRelation("mbranch");
      mbranchindex439 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({0, 1, 2});
      slog::Relation* readrel466 = db->getRelation("mp_union");
      mp_unionindex440 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("mp_msk");
      mp_mskindex441 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 0});
      slog::Relation* readrel470 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex442 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("mp_union");
      mp_unionindex443 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel474 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index444 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("mp_msk");
      mp_mskindex445 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex446 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 4, 0});
      slog::Relation* readrel480 = db->getRelation("mbranch");
      mbranchindex447 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 1, 2});
      slog::Relation* readrel482 = db->getRelation("mp_union");
      mp_unionindex448 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("mp_msk");
      mp_mskindex449 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex450 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 2, 0});
      slog::Relation* readrel488 = db->getRelation("mp_union");
      mp_unionindex451 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 2, 0});
      slog::Relation* readrel490 = db->getRelation("mp_union");
      mp_uniondelta453 = readrel490->getIndex(ord489, true);
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("mp_union_ans");
      mp_union_ansindex452 = readrel492->getIndex(ord491, false);
  
    }
    ReadTask454(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c2 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x104x0x0x1index435, std::array<u64,10>{v_c6, v_c7, v_c8, v_c2, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex436, std::array<u64,3>{v_c82, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex437, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x104x0x0x0index438, std::array<u64,9>{v_c6, v_c7, v_c8, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m493) {
          u64 v_c83 = m493[4]; u64 v_c64 = m493[5]; u64 v_c63 = m493[6]; u64 v_c65 = m493[7]; u64 v_c4 = m493[8];
          u64 v_c84 = _prim_lt(db, v_c7, v_c64);
          if (v_c84 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c84) return;
          if (!slog::exists_probe<5,4>(mbranchindex439, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex440, std::array<u64,3>{v_c83, v_c82, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex441, std::array<u64,3>{v_c8, v_c64, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex442, std::array<u64,2>{v_c63, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex443, std::array<u64,3>{v_c82, v_c65, 0})) return;
          slog::join_probe<10,9>($sup5638x104x0x0x1index444, std::array<u64,10>{v_c65, v_c64, v_c63, v_c4, v_c83, v_c6, v_c7, v_c8, v_c2, 0}, [&](const std::array<u64,10>& m495) {
            u64 v_c85 = m495[9];
            if (!slog::exists_probe<3,3>(mp_mskindex445, std::array<u64,3>{v_c8, v_c64, v_c85})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex446, std::array<u64,2>{v_c85, v_c63})) return;
            slog::join_probe<5,4>(mbranchindex447, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, 0}, [&](const std::array<u64,5>& m496) {
              u64 v_c86 = m496[4];
              slog::join_probe<3,3>(mp_unionindex448, std::array<u64,3>{v_c83, v_c82, v_c86}, [&](const std::array<u64,3>& m497) {
                slog::join_probe<3,3>(mp_mskindex449, std::array<u64,3>{v_c8, v_c64, v_c85}, [&](const std::array<u64,3>& m498) {
                  slog::join_probe<2,2>(mp_msk_ansindex450, std::array<u64,2>{v_c85, v_c63}, [&](const std::array<u64,2>& m499) {
                    slog::join_probe_old<3,2>(mp_unionindex451, mp_uniondelta453, std::array<u64,3>{v_c82, v_c65, 0}, [&](const std::array<u64,3>& m500) {
                      u64 v_c87 = m500[2];
                      slog::join_probe<2,1>(mp_union_ansindex452, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m501) {
                        u64 v_c17 = m501[1];
                        u64 v_c88 = _prim_band(db, v_c8, v_c64);
                        if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c89 = _prim_lt(db, v_c88, v_c81);
                        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c89) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c83, v_c17, v_c64, v_c63, v_c4});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c63, v_c64, v_c17, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask454* _cont = new ReadTask454(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask454(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t4hJg802 p) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_bld (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4hJg802 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (1 2 3 4 0) 2 p m) (join-old $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t2paO798 l r) (exists mp_del (0 2 1) 2 __t2paO798 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_del (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t29Nf797) (join-old mp_del (0 2 1) 3 (0 2 1) __t2paO798 k __t29Nf797) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t2Csk801) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join-old mp_del_ans (0 1) 2 (0 1) __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask529 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index503;  slog::Index** mbranchindex504;  slog::Index** mp_bldindex505;  slog::Index** mp_mskindex506;  slog::Index** mbranchindex507;  slog::Index** mp_delindex508;  slog::Index** mp_bldindex509;  slog::Index** $sup5638x84x0x0x0index510;  slog::Index** mp_delindex511;  slog::Index** mp_bldindex512;  slog::Index** mp_delindex513;  slog::Index** mbranchindex514;  slog::Index** mp_delindex515;  slog::Index** mp_bldindex516;  slog::Index** mp_del_ansindex517;  slog::Index** mp_bld_ansindex518;  slog::Index** mp_delindex519;  slog::Index** mp_del_ansindex520;  slog::Index** mp_bld_ansindex521;  slog::Index** mp_mskdelta522;  slog::Index** $sup5638x84x0x0x0delta523;  slog::Index** mbranchdelta524;  slog::Index** mp_deldelta525;  slog::Index** mp_blddelta526;  slog::Index** mp_deldelta527;  slog::Index** mp_del_ansdelta528;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord530({0, 1});
      slog::Relation* readrel531 = db->getRelation("mp_del_ans");
      head_index[0] = readrel531->getIndex(ord530, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord532({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel533 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index503 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 3, 4, 0});
      slog::Relation* readrel535 = db->getRelation("mbranch");
      mbranchindex504 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 2, 3, 4, 0});
      slog::Relation* readrel537 = db->getRelation("mp_bld");
      mp_bldindex505 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 1, 2});
      slog::Relation* readrel539 = db->getRelation("mp_msk");
      mp_mskindex506 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({0, 1, 2});
      slog::Relation* readrel541 = db->getRelation("mp_msk");
      mp_mskdelta522 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({1, 2, 3, 4, 0});
      slog::Relation* readrel543 = db->getRelation("mbranch");
      mbranchindex507 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({2, 0, 1});
      slog::Relation* readrel545 = db->getRelation("mp_del");
      mp_delindex508 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 3, 4, 0});
      slog::Relation* readrel547 = db->getRelation("mp_bld");
      mp_bldindex509 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel549 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index510 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel551 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta523 = readrel551->getIndex(ord550, true);
      std::vector<u16> ord552({0, 2, 1});
      slog::Relation* readrel553 = db->getRelation("mp_del");
      mp_delindex511 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 3, 4, 0});
      slog::Relation* readrel555 = db->getRelation("mp_bld");
      mp_bldindex512 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 0});
      slog::Relation* readrel557 = db->getRelation("mp_del");
      mp_delindex513 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 2, 3, 4, 0});
      slog::Relation* readrel559 = db->getRelation("mbranch");
      mbranchindex514 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 3, 4, 0});
      slog::Relation* readrel561 = db->getRelation("mbranch");
      mbranchdelta524 = readrel561->getIndex(ord560, true);
      std::vector<u16> ord562({0, 2, 1});
      slog::Relation* readrel563 = db->getRelation("mp_del");
      mp_delindex515 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({0, 2, 1});
      slog::Relation* readrel565 = db->getRelation("mp_del");
      mp_deldelta525 = readrel565->getIndex(ord564, true);
      std::vector<u16> ord566({1, 2, 3, 4, 0});
      slog::Relation* readrel567 = db->getRelation("mp_bld");
      mp_bldindex516 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 2, 3, 4, 0});
      slog::Relation* readrel569 = db->getRelation("mp_bld");
      mp_blddelta526 = readrel569->getIndex(ord568, true);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("mp_del_ans");
      mp_del_ansindex517 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex518 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("mp_del");
      mp_delindex519 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 0});
      slog::Relation* readrel577 = db->getRelation("mp_del");
      mp_deldelta527 = readrel577->getIndex(ord576, true);
      std::vector<u16> ord578({0, 1});
      slog::Relation* readrel579 = db->getRelation("mp_del_ans");
      mp_del_ansindex520 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("mp_del_ans");
      mp_del_ansdelta528 = readrel581->getIndex(ord580, true);
      std::vector<u16> ord582({0, 1});
      slog::Relation* readrel583 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex521 = readrel583->getIndex(ord582, false);
  
    }
    ReadTask529(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x84x0x0x0index503, std::array<u64,6>{v_c8, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex504, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex505, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex506, mp_mskdelta522, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m584) {
          u64 v_c3 = m584[1]; u64 v_c7 = m584[2];
          if (!slog::exists_probe<5,2>(mbranchindex507, std::array<u64,5>{v_c8, v_c7, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex508, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex509, std::array<u64,5>{v_c8, v_c7, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x84x0x0x0index510, $sup5638x84x0x0x0delta523, std::array<u64,6>{v_c3, v_c7, v_c8, 0, 0, 0}, [&](const std::array<u64,6>& m585) {
            u64 v_c68 = m585[3]; u64 v_c6 = m585[4]; u64 v_c2 = m585[5];
            if (!slog::exists_probe<3,2>(mp_delindex511, std::array<u64,3>{v_c68, v_c3, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex512, std::array<u64,5>{v_c8, v_c7, v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex513, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex514, mbranchdelta524, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m586) {
              u64 v_c69 = m586[4];
              slog::join_probe_old<3,3>(mp_delindex515, mp_deldelta525, std::array<u64,3>{v_c68, v_c3, v_c69}, [&](const std::array<u64,3>& m587) {
                slog::join_probe_old<5,3>(mp_bldindex516, mp_blddelta526, std::array<u64,5>{v_c8, v_c7, v_c6, 0, 0}, [&](const std::array<u64,5>& m588) {
                  u64 v_c17 = m588[3]; u64 v_c70 = m588[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex517, std::array<u64,2>{v_c17, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex518, std::array<u64,2>{v_c70, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex519, mp_deldelta527, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m589) {
                    u64 v_c67 = m589[2];
                    slog::join_probe_old<2,2>(mp_del_ansindex520, mp_del_ansdelta528, std::array<u64,2>{v_c67, v_c17}, [&](const std::array<u64,2>& m590) {
                      slog::join_probe<2,1>(mp_bld_ansindex521, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m591) {
                        u64 v_c72 = m591[1];
                        u64 v_c73 = _prim_band(db, v_c3, v_c7);
                        if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c90 = _prim_gt(db, v_c73, v_c66);
                        if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c90) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c68, v_c72}, std::array<u16,2>{0, 1});
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
        ReadTask529* _cont = new ReadTask529(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask529(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x1 __t2hbE115 __t27ag118 l m n p q r u v) (body (cmp lt n m) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t2hbE115 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 3 q m __t27ag118) (exists mp_msk_ans (0 1) 2 __t27ag118 p) (exists mp_union (1 2 0) 1 l) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5EdF114) (exists mp_union (0 1 2) 2 __t2hbE115 __t5EdF114) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_union (0 1 2) 3 (0 1 2) __t2hbE115 __t5EdF114 __t8CES119) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask611 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index593;  slog::Index** mbranchindex594;  slog::Index** mp_mskindex595;  slog::Index** mp_msk_ansindex596;  slog::Index** mp_unionindex597;  slog::Index** mbranchindex598;  slog::Index** mp_unionindex599;  slog::Index** mbranchindex600;  slog::Index** mp_unionindex601;  slog::Index** mp_mskindex602;  slog::Index** mp_msk_ansindex603;  slog::Index** mp_unionindex604;  slog::Index** mp_union_ansindex605;  slog::Index** mbranchdelta606;  slog::Index** mbranchdelta607;  slog::Index** mp_uniondelta608;  slog::Index** mp_mskdelta609;  slog::Index** mp_uniondelta610;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord612({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel613 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index593 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 2, 3, 4, 0});
      slog::Relation* readrel615 = db->getRelation("mbranch");
      mbranchindex594 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("mp_msk");
      mp_mskindex595 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex596 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("mp_union");
      mp_unionindex597 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 3, 4, 0});
      slog::Relation* readrel623 = db->getRelation("mbranch");
      mbranchindex598 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 3, 4, 0});
      slog::Relation* readrel625 = db->getRelation("mbranch");
      mbranchdelta606 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({0, 1, 2});
      slog::Relation* readrel627 = db->getRelation("mp_union");
      mp_unionindex599 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 3, 4, 0});
      slog::Relation* readrel629 = db->getRelation("mbranch");
      mbranchindex600 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 3, 4, 0});
      slog::Relation* readrel631 = db->getRelation("mbranch");
      mbranchdelta607 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({0, 1, 2});
      slog::Relation* readrel633 = db->getRelation("mp_union");
      mp_unionindex601 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1, 2});
      slog::Relation* readrel635 = db->getRelation("mp_union");
      mp_uniondelta608 = readrel635->getIndex(ord634, true);
      std::vector<u16> ord636({1, 2, 0});
      slog::Relation* readrel637 = db->getRelation("mp_msk");
      mp_mskindex602 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 2, 0});
      slog::Relation* readrel639 = db->getRelation("mp_msk");
      mp_mskdelta609 = readrel639->getIndex(ord638, true);
      std::vector<u16> ord640({0, 1});
      slog::Relation* readrel641 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex603 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("mp_union");
      mp_unionindex604 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("mp_union");
      mp_uniondelta610 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("mp_union_ans");
      mp_union_ansindex605 = readrel647->getIndex(ord646, false);
  
    }
    ReadTask611(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c93 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c64 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c63 = _t[6];
        u64 v_c2 = _t[7];
        u64 v_c65 = _t[8];
        u64 v_c4 = _t[9];
        u64 v_c94 = _prim_lt(db, v_c64, v_c7);
        if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
        if (!v_c94) return;
        slog::join_probe<9,9>($sup5638x95x0x0x0index593, std::array<u64,9>{v_c6, v_c7, v_c8, v_c2, v_c92, v_c64, v_c63, v_c65, v_c4}, [&](const std::array<u64,9>& m649) {
          if (!slog::exists_probe<5,4>(mbranchindex594, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex595, std::array<u64,3>{v_c63, v_c7, v_c93})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex596, std::array<u64,2>{v_c93, v_c8})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex597, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex598, mbranchdelta606, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m650) {
            u64 v_c95 = m650[4];
            if (!slog::exists_probe<3,2>(mp_unionindex599, std::array<u64,3>{v_c92, v_c95, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex600, mbranchdelta607, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, 0}, [&](const std::array<u64,5>& m651) {
              u64 v_c96 = m651[4];
              slog::join_probe_old<3,3>(mp_unionindex601, mp_uniondelta608, std::array<u64,3>{v_c92, v_c95, v_c96}, [&](const std::array<u64,3>& m652) {
                slog::join_probe_old<3,3>(mp_mskindex602, mp_mskdelta609, std::array<u64,3>{v_c63, v_c7, v_c93}, [&](const std::array<u64,3>& m653) {
                  slog::join_probe<2,2>(mp_msk_ansindex603, std::array<u64,2>{v_c93, v_c8}, [&](const std::array<u64,2>& m654) {
                    slog::join_probe_old<3,2>(mp_unionindex604, mp_uniondelta610, std::array<u64,3>{v_c6, v_c96, 0}, [&](const std::array<u64,3>& m655) {
                      u64 v_c97 = m655[2];
                      slog::join_probe<2,1>(mp_union_ansindex605, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m656) {
                        u64 v_c17 = m656[1];
                        u64 v_c98 = _prim_band(db, v_c63, v_c7);
                        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c99 = _prim_lt(db, v_c98, v_c91);
                        if (v_c99 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c99) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c92, v_c17, v_c7, v_c8, v_c2});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c17, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask611* _cont = new ReadTask611(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask611(db,b), false);
  // (crule (pre (let __trid8fKn1161 conste711e3685c3e87fc5763620f) (let __trel7YWj1162 const1064263932db82f2cf6d4ac2) (let __tcol5P7Y1163 const5feceb66ffc86f38d952786c) (let __trel7hOL1164 const1064263932db82f2cf6d4ac2) (let __tcol4E3i1165 const6b86b273ff34fce19d6b804e)) (scan $sup70016x95x0x0x0 __d0 eb er rho t x) (body) (head (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8fKn1161 __trel7YWj1162 __tcol5P7Y1163 (1 2 3 4 0)) (tycheck x (accept int) __trid8fKn1161 __trel7hOL1164 __tcol4E3i1165 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __6j2u1160 rho x t)) interp.slog:96 #f)
  class ReadTask661 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid659;  u32 sid658;  u32 sid660;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup70016x95x0x0x0");
      sid659 = db->getRelation("_enum")->getStructId();
      sid658 = db->getRelation("mbranch")->getStructId();
      sid660 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask661(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_conste711e3685c3e87fc5763620f;
      u64 v_c101 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c102 = v_const5feceb66ffc86f38d952786c;
      u64 v_c103 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c104 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c38 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c26 = _t[4];
        u64 v_c32 = _t[5];
        ++_fires;
        if (!((is_struct(v_c31) && (decode_struct_id(v_c31) == sid658 || decode_struct_id(v_c31) == sid659 || decode_struct_id(v_c31) == sid660))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c100, v_c101, v_c102, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c32)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c100, v_c103, v_c104, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c31, v_c32, v_c26}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask661* _cont = new ReadTask661(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask661(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x2 __t7O3e781 __t8x7Q785 dup6QI21998 dup4FCe1999 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join-old $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join-old $sup5638x29x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join-old mp_msk_ans (0 1) 1 (0 1) __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask680 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x1index662;  slog::Index** $sup5638x29x0x0x0index663;  slog::Index** mp_joinindex664;  slog::Index** mp_hsb_ansindex665;  slog::Index** mp_hsb_ansindex666;  slog::Index** mp_hsb_ansindex667;  slog::Index** mp_mskindex668;  slog::Index** mp_msk_ansindex669;  slog::Index** mp_hsbindex670;  slog::Index** $sup5638x29x0x0x1delta671;  slog::Index** $sup5638x29x0x0x0delta672;  slog::Index** mp_joindelta673;  slog::Index** mp_hsb_ansdelta674;  slog::Index** mp_hsb_ansdelta675;  slog::Index** mp_hsb_ansdelta676;  slog::Index** mp_mskdelta677;  slog::Index** mp_msk_ansdelta678;  slog::Index** mp_hsbdelta679;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord681({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel682 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index662 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel684 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta671 = readrel684->getIndex(ord683, true);
      std::vector<u16> ord685({1, 0, 2, 3, 4});
      slog::Relation* readrel686 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index663 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 0, 2, 3, 4});
      slog::Relation* readrel688 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0delta672 = readrel688->getIndex(ord687, true);
      std::vector<u16> ord689({1, 2, 3, 4, 0});
      slog::Relation* readrel690 = db->getRelation("mp_join");
      mp_joinindex664 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 3, 4, 0});
      slog::Relation* readrel692 = db->getRelation("mp_join");
      mp_joindelta673 = readrel692->getIndex(ord691, true);
      std::vector<u16> ord693({0, 1});
      slog::Relation* readrel694 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex665 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta674 = readrel696->getIndex(ord695, true);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex666 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta675 = readrel700->getIndex(ord699, true);
      std::vector<u16> ord701({0, 1});
      slog::Relation* readrel702 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex667 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({0, 1});
      slog::Relation* readrel704 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta676 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("mp_msk");
      mp_mskindex668 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("mp_msk");
      mp_mskdelta677 = readrel708->getIndex(ord707, true);
      std::vector<u16> ord709({0, 1});
      slog::Relation* readrel710 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex669 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta678 = readrel712->getIndex(ord711, true);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("mp_hsb");
      mp_hsbindex670 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("mp_hsb");
      mp_hsbdelta679 = readrel716->getIndex(ord715, true);
  
    }
    ReadTask680(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c42 = _t[1];
        u64 v_c46 = _t[2];
        u64 v_c47 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c44 = _t[5];
        u64 v_c43 = _t[6];
        u64 v_c48 = _t[7];
        u64 v_c49 = _t[8];
        u64 v_c50 = _t[9];
        u64 v_c51 = _t[10];
        if (v_c42 != v_c47) return;
        if (v_c42 != v_c46) return;
        slog::join_probe_old<7,7>($sup5638x29x0x0x1index662, $sup5638x29x0x0x1delta671, std::array<u64,7>{v_c45, v_c48, v_c49, v_c50, v_c51, v_c42, v_c17}, [&](const std::array<u64,7>& m717) {
          slog::join_probe_old<5,5>($sup5638x29x0x0x0index663, $sup5638x29x0x0x0delta672, std::array<u64,5>{v_c48, v_c45, v_c49, v_c50, v_c51}, [&](const std::array<u64,5>& m718) {
            slog::join_probe_old<5,5>(mp_joinindex664, mp_joindelta673, std::array<u64,5>{v_c48, v_c50, v_c49, v_c51, v_c45}, [&](const std::array<u64,5>& m719) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex665, mp_hsb_ansdelta674, std::array<u64,2>{v_c42, v_c43}, [&](const std::array<u64,2>& m720) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex666, mp_hsb_ansdelta675, std::array<u64,2>{v_c42, v_c44}, [&](const std::array<u64,2>& m721) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex667, mp_hsb_ansdelta676, std::array<u64,2>{v_c42, v_c17}, [&](const std::array<u64,2>& m722) {
                    slog::join_probe_old<3,2>(mp_mskindex668, mp_mskdelta677, std::array<u64,3>{v_c48, v_c44, 0}, [&](const std::array<u64,3>& m723) {
                      u64 v_c52 = m723[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex669, mp_msk_ansdelta678, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m724) {
                        u64 v_c53 = m724[1];
                        u64 v_c54 = _prim_bxor(db, v_c48, v_c49);
                        if (v_c54 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex670, mp_hsbdelta679, std::array<u64,2>{v_c42, v_c54}, [&](const std::array<u64,2>& m725) {
                          u64 v_c55 = _prim_band(db, v_c48, v_c17);
                          if (v_c55 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c105 = _prim_gt(db, v_c55, v_c41);
                          if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c105) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c45, v_c53, v_c43, v_c50, v_c51});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c53, v_c43, v_c51, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask680* _cont = new ReadTask680(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask680(db,b), false);
  // (crule (pre (let __tconst6uLy1418 constcd2a69ce5ca278db1d6da969) (let _00024sqc5ZED979 constd4735e3a265e16eee03f5971) (let _00024sqc8Ktf980 const5feceb66ffc86f38d952786c) (let _00024sqc1r6Y981 const6b86b273ff34fce19d6b804e) (let _00024sqo4ml8982 const5feceb66ffc86f38d952786c) (let _00024sqo9GuQ983 const6b86b273ff34fce19d6b804e) (let _00024sqo9DrV984 const6b86b273ff34fce19d6b804e) (let _00024sqo0wvc985 const5feceb66ffc86f38d952786c) (let __trid2ZoU1419 constfdb0a95399e17c48d6f65653) (let __trel2kf41420 constdede4476644eb06b5a48b866) (let __tcol0QrU1421 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo4ml8982 __t0ebd433 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9GuQ983 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9DrV984 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0wvc985 __t0ebd433 _00024seq2) (join _enum (0 1) 2 __t0ebd433 __tconst6uLy1418) (join delta (2 0 1) 1 _00024seq2 __t9b4a431 op) (join arithmetic_op (0) 1 op) (letp _00024sql4NVe977 (aslst _00024seq2)) (let chk9Tee1859 (llen _00024sql4NVe977)) (eq _00024sqc5ZED979 chk9Tee1859) (letp chk1DGs1860 (lref _00024sql4NVe977 _00024sqc8Ktf980)) (eq __t0ebd433 chk1DGs1860) (letp chk8vWx1861 (lref _00024sql4NVe977 _00024sqc1r6Y981)) (eq __t0ebd433 chk8vWx1861)) (head (tycheck __t0ebd433 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2ZoU1419 __trel2kf41420 __tcol0QrU1421 (1 2 3 4 0)) (emit delta_ans (0 1) __t9b4a431 __t0ebd433)) interp.slog:116 #f)
  class ReadTask741 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex727;  slog::Index** $seq_atrindex728;  slog::Index** $seq_atrindex729;  slog::Index** _enumindex730;  slog::Index** deltaindex731;  slog::Index** arithmetic_opindex732;  slog::Index** $seq_atdelta733;  slog::Index** $seq_atrdelta734;  slog::Index** $seq_atrdelta735;
    u32 sid738;  u32 sid736;  u32 sid737;  u32 sid739;  u32 sid740;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord742({0, 1});
      slog::Relation* readrel743 = db->getRelation("delta_ans");
      head_index[1] = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 0, 2});
      slog::Relation* readrel745 = db->getRelation("$seq_at");
      driver_index = readrel745->getIndex(ord744, true);
      std::vector<u16> ord746({1, 0, 2});
      slog::Relation* readrel747 = db->getRelation("$seq_at");
      $seq_atindex727 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 0, 2});
      slog::Relation* readrel749 = db->getRelation("$seq_at");
      $seq_atdelta733 = readrel749->getIndex(ord748, true);
      std::vector<u16> ord750({1, 0, 2});
      slog::Relation* readrel751 = db->getRelation("$seq_atr");
      $seq_atrindex728 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0, 2});
      slog::Relation* readrel753 = db->getRelation("$seq_atr");
      $seq_atrdelta734 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({1, 0, 2});
      slog::Relation* readrel755 = db->getRelation("$seq_atr");
      $seq_atrindex729 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 0, 2});
      slog::Relation* readrel757 = db->getRelation("$seq_atr");
      $seq_atrdelta735 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({0, 1});
      slog::Relation* readrel759 = db->getRelation("_enum");
      _enumindex730 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({2, 0, 1});
      slog::Relation* readrel761 = db->getRelation("delta");
      deltaindex731 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({0});
      slog::Relation* readrel763 = db->getRelation("arithmetic_op");
      arithmetic_opindex732 = readrel763->getIndex(ord762, false);
      sid738 = db->getRelation("_enum")->getStructId();
      sid736 = db->getRelation("boolval")->getStructId();
      sid737 = db->getRelation("closure")->getStructId();
      sid739 = db->getRelation("prim")->getStructId();
      sid740 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask741(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c106 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c107 = v_constd4735e3a265e16eee03f5971;
      u64 v_c108 = v_const5feceb66ffc86f38d952786c;
      u64 v_c109 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const5feceb66ffc86f38d952786c;
      u64 v_c114 = v_constfdb0a95399e17c48d6f65653;
      u64 v_c115 = v_constdede4476644eb06b5a48b866;
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c110, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m764) {
        u64 v_c117 = m764[1];
        u64 v_c118 = m764[2];
        if (buckethash(v_c117) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex727, $seq_atdelta733, std::array<u64,3>{v_c111, v_c117, v_c118}, [&](const std::array<u64,3>& m765) {
          slog::join_probe_old<3,3>($seq_atrindex728, $seq_atrdelta734, std::array<u64,3>{v_c112, v_c117, v_c118}, [&](const std::array<u64,3>& m766) {
            slog::join_probe_old<3,3>($seq_atrindex729, $seq_atrdelta735, std::array<u64,3>{v_c113, v_c117, v_c118}, [&](const std::array<u64,3>& m767) {
              slog::join_probe<2,2>(_enumindex730, std::array<u64,2>{v_c117, v_c106}, [&](const std::array<u64,2>& m768) {
                slog::join_probe<3,1>(deltaindex731, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m769) {
                  u64 v_c119 = m769[1]; u64 v_c120 = m769[2];
                  slog::join_probe<1,1>(arithmetic_opindex732, std::array<u64,1>{v_c120}, [&](const std::array<u64,1>& m770) {
                    bool ok771 = true;
                    u64 v_c121 = _prim_aslst(db, v_c118, &ok771);
                    if (!ok771) return;
                    u64 v_c122 = _prim_llen(db, v_c121);
                    if (v_c122 == slog_error) { slog::emit_pending_error(db, "interp.slog:116"); return; }
                    if (v_c107 != v_c122) return;
                    bool ok772 = true;
                    u64 v_c123 = _prim_lref(db, v_c121, v_c108, &ok772);
                    if (!ok772) return;
                    if (v_c117 != v_c123) return;
                    bool ok773 = true;
                    u64 v_c124 = _prim_lref(db, v_c121, v_c109, &ok773);
                    if (!ok773) return;
                    if (v_c117 != v_c124) return;
                    ++_fires;
                    if (!((is_struct(v_c117) && (decode_struct_id(v_c117) == sid736 || decode_struct_id(v_c117) == sid737 || decode_struct_id(v_c117) == sid738 || decode_struct_id(v_c117) == sid739 || decode_struct_id(v_c117) == sid740))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c114, v_c115, v_c116, v_c117}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c119, v_c117}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:116", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask741* _cont = new ReadTask741(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask741(db,b), false);
  // (crule (pre) (scan mbranch __t4xjy453 p m l r) (body (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_union (1 2 0) 1 __t4xjy453) (exists mp_union (1 2 0) 1 l) (exists mp_union (1 2 0) 1 r) (join $sup5638x93x0x0x0 (1 2 3 4 0 5 6) 4 l m p r __t70BJ454 u v) (exists mp_union (0 1 2) 2 __t70BJ454 __t4xjy453) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join mbranch (1 2 3 4 0) 4 p m u v __t1p4P452) (join-old mp_union (0 1 2) 3 (0 1 2) __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t1OdF455) (exists mp_union_ans (0 1) 1 __t1OdF455) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (exists mp_union_ans (0 1) 1 __t4atM456) (join mp_union_ans (0 1) 1 __t1OdF455 __v0) (join mp_union_ans (0 1) 1 __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask793 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex774;  slog::Index** mp_unionindex775;  slog::Index** mp_unionindex776;  slog::Index** mp_unionindex777;  slog::Index** $sup5638x93x0x0x0index778;  slog::Index** mp_unionindex779;  slog::Index** mp_unionindex780;  slog::Index** mp_unionindex781;  slog::Index** mbranchindex782;  slog::Index** mp_unionindex783;  slog::Index** mp_unionindex784;  slog::Index** mp_union_ansindex785;  slog::Index** mp_unionindex786;  slog::Index** mp_union_ansindex787;  slog::Index** mp_union_ansindex788;  slog::Index** mp_union_ansindex789;  slog::Index** mp_uniondelta790;  slog::Index** mp_uniondelta791;  slog::Index** mp_uniondelta792;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord794({1, 2, 3, 4, 0});
      slog::Relation* readrel795 = db->getRelation("mbranch");
      mbranchindex774 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("mp_union");
      mp_unionindex775 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("mp_union");
      mp_unionindex776 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("mp_union");
      mp_unionindex777 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 3, 4, 0, 5, 6});
      slog::Relation* readrel803 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index778 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({0, 1, 2});
      slog::Relation* readrel805 = db->getRelation("mp_union");
      mp_unionindex779 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("mp_union");
      mp_unionindex780 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("mp_union");
      mp_unionindex781 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 3, 4, 0});
      slog::Relation* readrel811 = db->getRelation("mbranch");
      mbranchindex782 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1, 2});
      slog::Relation* readrel813 = db->getRelation("mp_union");
      mp_unionindex783 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 1, 2});
      slog::Relation* readrel815 = db->getRelation("mp_union");
      mp_uniondelta790 = readrel815->getIndex(ord814, true);
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("mp_union");
      mp_unionindex784 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("mp_union");
      mp_uniondelta791 = readrel819->getIndex(ord818, true);
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("mp_union_ans");
      mp_union_ansindex785 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("mp_union");
      mp_unionindex786 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 2, 0});
      slog::Relation* readrel825 = db->getRelation("mp_union");
      mp_uniondelta792 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({0, 1});
      slog::Relation* readrel827 = db->getRelation("mp_union_ans");
      mp_union_ansindex787 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("mp_union_ans");
      mp_union_ansindex788 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("mp_union_ans");
      mp_union_ansindex789 = readrel831->getIndex(ord830, false);
  
    }
    ReadTask793(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c2 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex774, std::array<u64,5>{v_c8, v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex775, std::array<u64,3>{v_c125, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex776, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex777, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<7,4>($sup5638x93x0x0x0index778, std::array<u64,7>{v_c6, v_c7, v_c8, v_c2, 0, 0, 0}, [&](const std::array<u64,7>& m832) {
          u64 v_c126 = m832[4]; u64 v_c65 = m832[5]; u64 v_c4 = m832[6];
          if (!slog::exists_probe<3,2>(mp_unionindex779, std::array<u64,3>{v_c126, v_c125, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex780, std::array<u64,3>{v_c6, v_c65, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex781, std::array<u64,3>{v_c2, v_c4, 0})) return;
          slog::join_probe<5,4>(mbranchindex782, std::array<u64,5>{v_c8, v_c7, v_c65, v_c4, 0}, [&](const std::array<u64,5>& m833) {
            u64 v_c127 = m833[4];
            slog::join_probe_old<3,3>(mp_unionindex783, mp_uniondelta790, std::array<u64,3>{v_c126, v_c125, v_c127}, [&](const std::array<u64,3>& m834) {
              slog::join_probe_old<3,2>(mp_unionindex784, mp_uniondelta791, std::array<u64,3>{v_c6, v_c65, 0}, [&](const std::array<u64,3>& m835) {
                u64 v_c128 = m835[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex785, std::array<u64,2>{v_c128, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex786, mp_uniondelta792, std::array<u64,3>{v_c2, v_c4, 0}, [&](const std::array<u64,3>& m836) {
                  u64 v_c129 = m836[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex787, std::array<u64,2>{v_c129, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex788, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m837) {
                    u64 v_c17 = m837[1];
                    slog::join_probe<2,1>(mp_union_ansindex789, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m838) {
                      u64 v_c44 = m838[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c126, v_c17, v_c44, v_c7, v_c8});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c17, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre) (scan mp_msk_ans __t4Cp5299 p) (body (exists $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4Cp5299 k m) (join $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t4Cp5299 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask843 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index839;  slog::Index** mp_mskindex840;  slog::Index** $sup5638x40x0x0x0index841;  slog::Index** mp_mskdelta842;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord844({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel845 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel845->getIndex(ord844, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord846({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel847 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index839 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({0, 1, 2});
      slog::Relation* readrel849 = db->getRelation("mp_msk");
      mp_mskindex840 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({0, 1, 2});
      slog::Relation* readrel851 = db->getRelation("mp_msk");
      mp_mskdelta842 = readrel851->getIndex(ord850, true);
      std::vector<u16> ord852({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel853 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index841 = readrel853->getIndex(ord852, false);
  
    }
    ReadTask843(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c130 = _t[0];
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<7,1>($sup5638x40x0x0x0index839, std::array<u64,7>{v_c8, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex840, mp_mskdelta842, std::array<u64,3>{v_c130, 0, 0}, [&](const std::array<u64,3>& m854) {
          u64 v_c3 = m854[1]; u64 v_c7 = m854[2];
          slog::join_probe<7,3>($sup5638x40x0x0x0index841, std::array<u64,7>{v_c3, v_c7, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,7>& m855) {
            u64 v_c38 = m855[3]; u64 v_c6 = m855[4]; u64 v_c2 = m855[5]; u64 v_c4 = m855[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c130, v_c8, v_c38, v_c3, v_c6, v_c7, v_c2, v_c4}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask843* _cont = new ReadTask843(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask843(db,b), false);
  // (crule (pre) (scan temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (body (join mbranch (1 2 3 4 0) 4 p m __v0 __v1 __t8Q9x451)) (head (emit mp_union_ans (0 1) __t70BJ454 __t8Q9x451)) map.slog:94 #f)
  class ReadTask857 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex856;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord858({0, 1});
      slog::Relation* readrel859 = db->getRelation("mp_union_ans");
      head_index[0] = readrel859->getIndex(ord858, false);
      outer_rel = db->getRelation("temp9Yrn2045");
      std::vector<u16> ord860({1, 2, 3, 4, 0});
      slog::Relation* readrel861 = db->getRelation("mbranch");
      mbranchindex856 = readrel861->getIndex(ord860, false);
  
    }
    ReadTask857(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<5,4>(mbranchindex856, std::array<u64,5>{v_c8, v_c7, v_c17, v_c44, 0}, [&](const std::array<u64,5>& m862) {
          u64 v_c131 = m862[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c126, v_c131}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:temp9Yrn2045", _fires);
  
      if (!_done)
      {
        ReadTask857* _cont = new ReadTask857(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask857(db,b), false);
  // (crule (pre) (scan prim __t1N6L339 op) (body (exists delta (1 2 0) 1 op) (join eval_ans (1 0) 1 __t1N6L339 __t8KmI338) (join-old delta (1 2 0) 1 (1 2 0) op vs __t9Mk1341) (exists delta_ans (0 1) 1 __t9Mk1341) (join eval_args_ans (1 0) 1 vs __t24hv340) (join delta_ans (0 1) 1 __t9Mk1341 v) (join eval (0 1 2 3) 1 __t8KmI338 ef rho t) (exists $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (join-old eval_args (3 2 0 1) 3 (3 2 0 1) t rho __t24hv340 es) (exists app (1 2 0) 2 ef es) (join $sup70016x75x0x0x0 (1 3 4 2 0) 4 ef rho t es __t8Dhb337) (join eval (2 3 0 1) 3 rho t __t8Dhb337 __t87KU336) (join app (0 1 2) 3 __t87KU336 ef es)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask880 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex863;  slog::Index** eval_ansindex864;  slog::Index** deltaindex865;  slog::Index** delta_ansindex866;  slog::Index** eval_args_ansindex867;  slog::Index** delta_ansindex868;  slog::Index** evalindex869;  slog::Index** $sup70016x75x0x0x0index870;  slog::Index** evalindex871;  slog::Index** appindex872;  slog::Index** eval_argsindex873;  slog::Index** appindex874;  slog::Index** $sup70016x75x0x0x0index875;  slog::Index** evalindex876;  slog::Index** appindex877;  slog::Index** deltadelta878;  slog::Index** eval_argsdelta879;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord881({0, 1});
      slog::Relation* readrel882 = db->getRelation("eval_ans");
      head_index[0] = readrel882->getIndex(ord881, false);
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("delta");
      deltaindex863 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 0});
      slog::Relation* readrel886 = db->getRelation("eval_ans");
      eval_ansindex864 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("delta");
      deltaindex865 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("delta");
      deltadelta878 = readrel890->getIndex(ord889, true);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("delta_ans");
      delta_ansindex866 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 0});
      slog::Relation* readrel894 = db->getRelation("eval_args_ans");
      eval_args_ansindex867 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("delta_ans");
      delta_ansindex868 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1, 2, 3});
      slog::Relation* readrel898 = db->getRelation("eval");
      evalindex869 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 3, 4, 2, 0});
      slog::Relation* readrel900 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index870 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({2, 3, 0, 1});
      slog::Relation* readrel902 = db->getRelation("eval");
      evalindex871 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 0});
      slog::Relation* readrel904 = db->getRelation("app");
      appindex872 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({3, 2, 0, 1});
      slog::Relation* readrel906 = db->getRelation("eval_args");
      eval_argsindex873 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({3, 2, 0, 1});
      slog::Relation* readrel908 = db->getRelation("eval_args");
      eval_argsdelta879 = readrel908->getIndex(ord907, true);
      std::vector<u16> ord909({1, 2, 0});
      slog::Relation* readrel910 = db->getRelation("app");
      appindex874 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({1, 3, 4, 2, 0});
      slog::Relation* readrel912 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index875 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({2, 3, 0, 1});
      slog::Relation* readrel914 = db->getRelation("eval");
      evalindex876 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({0, 1, 2});
      slog::Relation* readrel916 = db->getRelation("app");
      appindex877 = readrel916->getIndex(ord915, false);
  
    }
    ReadTask880(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c120 = _t[1];
        if (!slog::exists_probe<3,1>(deltaindex863, std::array<u64,3>{v_c120, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex864, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m917) {
          u64 v_c133 = m917[1];
          slog::join_probe_old<3,1>(deltaindex865, deltadelta878, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m918) {
            u64 v_c134 = m918[1]; u64 v_c135 = m918[2];
            if (!slog::exists_probe<2,1>(delta_ansindex866, std::array<u64,2>{v_c135, 0})) return;
            slog::join_probe<2,1>(eval_args_ansindex867, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m919) {
              u64 v_c136 = m919[1];
              slog::join_probe<2,1>(delta_ansindex868, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m920) {
                u64 v_c4 = m920[1];
                slog::join_probe<4,1>(evalindex869, std::array<u64,4>{v_c133, 0, 0, 0}, [&](const std::array<u64,4>& m921) {
                  u64 v_c137 = m921[1]; u64 v_c31 = m921[2]; u64 v_c26 = m921[3];
                  if (!slog::exists_probe<5,3>($sup70016x75x0x0x0index870, std::array<u64,5>{v_c137, v_c31, v_c26, 0, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex871, std::array<u64,4>{v_c31, v_c26, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex872, std::array<u64,3>{v_c137, 0, 0})) return;
                  slog::join_probe_old<4,3>(eval_argsindex873, eval_argsdelta879, std::array<u64,4>{v_c26, v_c31, v_c136, 0}, [&](const std::array<u64,4>& m922) {
                    u64 v_c138 = m922[3];
                    if (!slog::exists_probe<3,2>(appindex874, std::array<u64,3>{v_c137, v_c138, 0})) return;
                    slog::join_probe<5,4>($sup70016x75x0x0x0index875, std::array<u64,5>{v_c137, v_c31, v_c26, v_c138, 0}, [&](const std::array<u64,5>& m923) {
                      u64 v_c139 = m923[4];
                      slog::join_probe<4,3>(evalindex876, std::array<u64,4>{v_c31, v_c26, v_c139, 0}, [&](const std::array<u64,4>& m924) {
                        u64 v_c140 = m924[3];
                        slog::join_probe<3,3>(appindex877, std::array<u64,3>{v_c140, v_c137, v_c138}, [&](const std::array<u64,3>& m925) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c4}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:prim", _fires);
  
      if (!_done)
      {
        ReadTask880* _cont = new ReadTask880(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask880(db,b), false);
  // (crule (pre) (scan $sup70016x92x0x0x0 __d0 eb er rho t x) (body (exists mp_put (1 2 3 0) 3 rho x t) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho t __t7uXV815) (exists eval_ans (0 1) 1 __t7uXV815) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t3Rle816) (exists mp_put_ans (0 1) 1 __t3Rle816) (join-old eval_ans (0 1) 1 (0 1) __t7uXV815 vr) (join-old mp_put_ans (0 1) 1 (0 1) __t3Rle816 __v0)) (head (emit $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) __t7uXV815 vr __d0 __t3Rle816 __v0 eb er rho t x)) interp.slog:93 #f)
  class ReadTask937 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex926;  slog::Index** evalindex927;  slog::Index** eval_ansindex928;  slog::Index** mp_putindex929;  slog::Index** mp_put_ansindex930;  slog::Index** eval_ansindex931;  slog::Index** mp_put_ansindex932;  slog::Index** evaldelta933;  slog::Index** mp_putdelta934;  slog::Index** eval_ansdelta935;  slog::Index** mp_put_ansdelta936;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord938({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel939 = db->getRelation("$sup70016x92x0x0x1");
      head_index[0] = readrel939->getIndex(ord938, false);
      outer_rel = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord940({1, 2, 3, 0});
      slog::Relation* readrel941 = db->getRelation("mp_put");
      mp_putindex926 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 2, 3, 0});
      slog::Relation* readrel943 = db->getRelation("eval");
      evalindex927 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 2, 3, 0});
      slog::Relation* readrel945 = db->getRelation("eval");
      evaldelta933 = readrel945->getIndex(ord944, true);
      std::vector<u16> ord946({0, 1});
      slog::Relation* readrel947 = db->getRelation("eval_ans");
      eval_ansindex928 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({1, 2, 3, 0});
      slog::Relation* readrel949 = db->getRelation("mp_put");
      mp_putindex929 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 2, 3, 0});
      slog::Relation* readrel951 = db->getRelation("mp_put");
      mp_putdelta934 = readrel951->getIndex(ord950, true);
      std::vector<u16> ord952({0, 1});
      slog::Relation* readrel953 = db->getRelation("mp_put_ans");
      mp_put_ansindex930 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("eval_ans");
      eval_ansindex931 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({0, 1});
      slog::Relation* readrel957 = db->getRelation("eval_ans");
      eval_ansdelta935 = readrel957->getIndex(ord956, true);
      std::vector<u16> ord958({0, 1});
      slog::Relation* readrel959 = db->getRelation("mp_put_ans");
      mp_put_ansindex932 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({0, 1});
      slog::Relation* readrel961 = db->getRelation("mp_put_ans");
      mp_put_ansdelta936 = readrel961->getIndex(ord960, true);
  
    }
    ReadTask937(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c26 = _t[4];
        u64 v_c32 = _t[5];
        if (!slog::exists_probe<4,3>(mp_putindex926, std::array<u64,4>{v_c31, v_c32, v_c26, 0})) return;
        slog::join_probe_old<4,3>(evalindex927, evaldelta933, std::array<u64,4>{v_c24, v_c31, v_c26, 0}, [&](const std::array<u64,4>& m962) {
          u64 v_c141 = m962[3];
          if (!slog::exists_probe<2,1>(eval_ansindex928, std::array<u64,2>{v_c141, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex929, mp_putdelta934, std::array<u64,4>{v_c31, v_c32, v_c26, 0}, [&](const std::array<u64,4>& m963) {
            u64 v_c142 = m963[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex930, std::array<u64,2>{v_c142, 0})) return;
            slog::join_probe_old<2,1>(eval_ansindex931, eval_ansdelta935, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m964) {
              u64 v_c23 = m964[1];
              slog::join_probe_old<2,1>(mp_put_ansindex932, mp_put_ansdelta936, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m965) {
                u64 v_c17 = m965[1];
                ++_fires;
                slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c141, v_c23, v_c38, v_c142, v_c17, v_c28, v_c24, v_c31, v_c26, v_c32}, std::array<u16,10>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask937* _cont = new ReadTask937(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask937(db,b), false);
  // (crule (pre) (scan $sup5638x44x0x0x0 __t6Fc5832 k l m p r __t6oBk833 v) (body (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6oBk833) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Fc5832 k __t6oBk833 v) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t6oBk833 k __t6jFY835 __t5lKq834) (join-old mleaf (0 1 2) 3 (0 1 2) __t5lKq834 k v) (exists mp_join_ans (0 1) 1 __t6jFY835) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask981 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex966;  slog::Index** mp_putindex967;  slog::Index** mleafindex968;  slog::Index** mp_mskindex969;  slog::Index** mp_joinindex970;  slog::Index** mleafindex971;  slog::Index** mp_join_ansindex972;  slog::Index** mp_mskindex973;  slog::Index** mp_msk_ansindex974;  slog::Index** mp_join_ansindex975;  slog::Index** mbranchdelta976;  slog::Index** mp_putdelta977;  slog::Index** mp_joindelta978;  slog::Index** mleafdelta979;  slog::Index** mp_mskdelta980;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord982({0, 1});
      slog::Relation* readrel983 = db->getRelation("mp_put_ans");
      head_index[0] = readrel983->getIndex(ord982, false);
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord984({1, 2, 3, 4, 0});
      slog::Relation* readrel985 = db->getRelation("mbranch");
      mbranchindex966 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({1, 2, 3, 4, 0});
      slog::Relation* readrel987 = db->getRelation("mbranch");
      mbranchdelta976 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({0, 2, 1, 3});
      slog::Relation* readrel989 = db->getRelation("mp_put");
      mp_putindex967 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 2, 1, 3});
      slog::Relation* readrel991 = db->getRelation("mp_put");
      mp_putdelta977 = readrel991->getIndex(ord990, true);
      std::vector<u16> ord992({1, 2, 0});
      slog::Relation* readrel993 = db->getRelation("mleaf");
      mleafindex968 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({1, 2, 0});
      slog::Relation* readrel995 = db->getRelation("mp_msk");
      mp_mskindex969 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({3, 4, 1, 0, 2});
      slog::Relation* readrel997 = db->getRelation("mp_join");
      mp_joinindex970 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({3, 4, 1, 0, 2});
      slog::Relation* readrel999 = db->getRelation("mp_join");
      mp_joindelta978 = readrel999->getIndex(ord998, true);
      std::vector<u16> ord1000({0, 1, 2});
      slog::Relation* readrel1001 = db->getRelation("mleaf");
      mleafindex971 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({0, 1, 2});
      slog::Relation* readrel1003 = db->getRelation("mleaf");
      mleafdelta979 = readrel1003->getIndex(ord1002, true);
      std::vector<u16> ord1004({0, 1});
      slog::Relation* readrel1005 = db->getRelation("mp_join_ans");
      mp_join_ansindex972 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({1, 2, 0});
      slog::Relation* readrel1007 = db->getRelation("mp_msk");
      mp_mskindex973 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({1, 2, 0});
      slog::Relation* readrel1009 = db->getRelation("mp_msk");
      mp_mskdelta980 = readrel1009->getIndex(ord1008, true);
      std::vector<u16> ord1010({0, 1});
      slog::Relation* readrel1011 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex974 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({0, 1});
      slog::Relation* readrel1013 = db->getRelation("mp_join_ans");
      mp_join_ansindex975 = readrel1013->getIndex(ord1012, false);
  
    }
    ReadTask981(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c143 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c144 = _t[6];
        u64 v_c4 = _t[7];
        slog::join_probe_old<5,5>(mbranchindex966, mbranchdelta976, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, v_c144}, [&](const std::array<u64,5>& m1014) {
          slog::join_probe_old<4,4>(mp_putindex967, mp_putdelta977, std::array<u64,4>{v_c143, v_c3, v_c144, v_c4}, [&](const std::array<u64,4>& m1015) {
            if (!slog::exists_probe<3,2>(mleafindex968, std::array<u64,3>{v_c3, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex969, std::array<u64,3>{v_c3, v_c7, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex970, mp_joindelta978, std::array<u64,5>{v_c8, v_c144, v_c3, 0, 0}, [&](const std::array<u64,5>& m1016) {
              u64 v_c145 = m1016[3]; u64 v_c146 = m1016[4];
              slog::join_probe_old<3,3>(mleafindex971, mleafdelta979, std::array<u64,3>{v_c146, v_c3, v_c4}, [&](const std::array<u64,3>& m1017) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex972, std::array<u64,2>{v_c145, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex973, mp_mskdelta980, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m1018) {
                  u64 v_c147 = m1018[2];
                  slog::join_probe<2,1>(mp_msk_ansindex974, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1019) {
                    u64 v_c17 = m1019[1];
                    if (v_c8 == v_c17) return;
                    slog::join_probe<2,1>(mp_join_ansindex975, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1020) {
                      u64 v_c72 = m1020[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c143, v_c72}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask981* _cont = new ReadTask981(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask981(db,b), false);
  // (crule (pre) (scan mbranch __t6hR1368 q n u v) (body (join mp_union (2 0 1) 1 __t6hR1368 __t2qeD366 __t9kHM367) (join mbranch (0 1 2 3 4) 1 __t9kHM367 p m l r) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t2qeD366 l n p r __t9kHM367 __t6hR1368 u v)) map.slog:102 #f)
  class ReadTask1023 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1021;  slog::Index** mbranchindex1022;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord1024({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel1025 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel1025->getIndex(ord1024, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1026({2, 0, 1});
      slog::Relation* readrel1027 = db->getRelation("mp_union");
      mp_unionindex1021 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({0, 1, 2, 3, 4});
      slog::Relation* readrel1029 = db->getRelation("mbranch");
      mbranchindex1022 = readrel1029->getIndex(ord1028, false);
  
    }
    ReadTask1023(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c4 = _t[4];
        slog::join_probe<3,1>(mp_unionindex1021, std::array<u64,3>{v_c148, 0, 0}, [&](const std::array<u64,3>& m1030) {
          u64 v_c149 = m1030[1]; u64 v_c150 = m1030[2];
          slog::join_probe<5,1>(mbranchindex1022, std::array<u64,5>{v_c150, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1031) {
            u64 v_c8 = m1031[1]; u64 v_c7 = m1031[2]; u64 v_c6 = m1031[3]; u64 v_c2 = m1031[4];
            u64 v_c151 = _prim_lt(db, v_c64, v_c7);
            if (v_c151 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c151) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c7, v_c63, v_c149, v_c6, v_c64, v_c8, v_c2, v_c150, v_c148, v_c65, v_c4}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1023* _cont = new ReadTask1023(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1023(db,b), false);
  // (crule (pre (let __tconst5SF3829 const5feceb66ffc86f38d952786c)) (scan mp_hsb __t6kiQ828 __t9t7u827) (body (join mp_hsb_ans (0 1) 1 __t6kiQ828 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t4k7L830 (band p0 __v0)) (cmp gt __t4k7L830 __tconst5SF3829) (let chk10vF2032 (bxor p0 p1)) (eq __t9t7u827 chk10vF2032)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t6kiQ828 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask1035 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1033;  slog::Index** $sup5638x29x0x0x0index1034;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord1036({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1037 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel1037->getIndex(ord1036, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord1038({0, 1});
      slog::Relation* readrel1039 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1033 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({1, 0, 2, 3, 4});
      slog::Relation* readrel1041 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1034 = readrel1041->getIndex(ord1040, false);
  
    }
    ReadTask1035(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c154 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex1033, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1042) {
          u64 v_c17 = m1042[1];
          slog::join_all<5>($sup5638x29x0x0x0index1034, [&](const std::array<u64,5>& m1043) {
            u64 v_c48 = m1043[0]; u64 v_c38 = m1043[1]; u64 v_c49 = m1043[2]; u64 v_c50 = m1043[3]; u64 v_c51 = m1043[4];
            u64 v_c155 = _prim_band(db, v_c48, v_c17);
            if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c156 = _prim_gt(db, v_c155, v_c152);
            if (v_c156 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c156) return;
            u64 v_c157 = _prim_bxor(db, v_c48, v_c49);
            if (v_c157 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (v_c154 != v_c157) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c153, v_c17, v_c38, v_c48, v_c49, v_c50, v_c51}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1035* _cont = new ReadTask1035(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1035(db,b), false);
  // (crule (pre) (scan $sup70016x51x0x0x0 __t2z6s532 ef es rho t) (body (exists app (1 2 0) 2 ef es) (exists eval (1 2 3 0) 3 ef rho t) (exists $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 5 ef es __t2z6s532 rho t) (exists eval_args (1 3 2 0) 3 es t rho) (exists tick (2 0 1) 1 t) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (exists tick (1 2 0) 2 __t5a7h538 t) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t5qy8533) (exists eval_ans (0 1) 1 __t5qy8533) (join-old $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 6 (5 6 0 7 9 1 2 3 4 8 10 11 12) ef es __t2z6s532 rho t __t5qy8533 __t2srV536 __t0CD9539 eb rhoc t2 vs xs) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval (3 1 0 2) 2 t2 eb) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1083 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1045;  slog::Index** evalindex1046;  slog::Index** $sup70016x51x0x0x1index1047;  slog::Index** eval_argsindex1048;  slog::Index** tickindex1049;  slog::Index** evalindex1050;  slog::Index** appindex1051;  slog::Index** tickindex1052;  slog::Index** evalindex1053;  slog::Index** eval_ansindex1054;  slog::Index** $sup70016x51x0x0x1index1055;  slog::Index** eval_argsindex1056;  slog::Index** tickindex1057;  slog::Index** eval_args_ansindex1058;  slog::Index** tick_ansindex1059;  slog::Index** lambdaindex1060;  slog::Index** closureindex1061;  slog::Index** evalindex1062;  slog::Index** extend_envindex1063;  slog::Index** eval_args_ansindex1064;  slog::Index** tick_ansindex1065;  slog::Index** extend_env_ansindex1066;  slog::Index** lambdaindex1067;  slog::Index** closureindex1068;  slog::Index** eval_ansindex1069;  slog::Index** evalindex1070;  slog::Index** extend_env_ansindex1071;  slog::Index** eval_ansindex1072;  slog::Index** evaldelta1073;  slog::Index** appdelta1074;  slog::Index** evaldelta1075;  slog::Index** $sup70016x51x0x0x1delta1076;  slog::Index** eval_argsdelta1077;  slog::Index** tickdelta1078;  slog::Index** extend_envdelta1079;  slog::Index** lambdadelta1080;  slog::Index** closuredelta1081;  slog::Index** evaldelta1082;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1084({0, 1});
      slog::Relation* readrel1085 = db->getRelation("eval_ans");
      head_index[0] = readrel1085->getIndex(ord1084, false);
      outer_rel = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord1086({1, 2, 0});
      slog::Relation* readrel1087 = db->getRelation("app");
      appindex1045 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({1, 2, 3, 0});
      slog::Relation* readrel1089 = db->getRelation("eval");
      evalindex1046 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel1091 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1047 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 3, 2, 0});
      slog::Relation* readrel1093 = db->getRelation("eval_args");
      eval_argsindex1048 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({2, 0, 1});
      slog::Relation* readrel1095 = db->getRelation("tick");
      tickindex1049 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({2, 3, 0, 1});
      slog::Relation* readrel1097 = db->getRelation("eval");
      evalindex1050 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({2, 3, 0, 1});
      slog::Relation* readrel1099 = db->getRelation("eval");
      evaldelta1073 = readrel1099->getIndex(ord1098, true);
      std::vector<u16> ord1100({0, 1, 2});
      slog::Relation* readrel1101 = db->getRelation("app");
      appindex1051 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({0, 1, 2});
      slog::Relation* readrel1103 = db->getRelation("app");
      appdelta1074 = readrel1103->getIndex(ord1102, true);
      std::vector<u16> ord1104({1, 2, 0});
      slog::Relation* readrel1105 = db->getRelation("tick");
      tickindex1052 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({1, 2, 3, 0});
      slog::Relation* readrel1107 = db->getRelation("eval");
      evalindex1053 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 2, 3, 0});
      slog::Relation* readrel1109 = db->getRelation("eval");
      evaldelta1075 = readrel1109->getIndex(ord1108, true);
      std::vector<u16> ord1110({0, 1});
      slog::Relation* readrel1111 = db->getRelation("eval_ans");
      eval_ansindex1054 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel1113 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1055 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel1115 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta1076 = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({3, 2, 0, 1});
      slog::Relation* readrel1117 = db->getRelation("eval_args");
      eval_argsindex1056 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({3, 2, 0, 1});
      slog::Relation* readrel1119 = db->getRelation("eval_args");
      eval_argsdelta1077 = readrel1119->getIndex(ord1118, true);
      std::vector<u16> ord1120({0, 2, 1});
      slog::Relation* readrel1121 = db->getRelation("tick");
      tickindex1057 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({0, 2, 1});
      slog::Relation* readrel1123 = db->getRelation("tick");
      tickdelta1078 = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({0, 1});
      slog::Relation* readrel1125 = db->getRelation("eval_args_ans");
      eval_args_ansindex1058 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({0, 1});
      slog::Relation* readrel1127 = db->getRelation("tick_ans");
      tick_ansindex1059 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 2, 0});
      slog::Relation* readrel1129 = db->getRelation("lambda");
      lambdaindex1060 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({2, 0, 1});
      slog::Relation* readrel1131 = db->getRelation("closure");
      closureindex1061 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({3, 1, 0, 2});
      slog::Relation* readrel1133 = db->getRelation("eval");
      evalindex1062 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 2, 3, 0});
      slog::Relation* readrel1135 = db->getRelation("extend_env");
      extend_envindex1063 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 2, 3, 0});
      slog::Relation* readrel1137 = db->getRelation("extend_env");
      extend_envdelta1079 = readrel1137->getIndex(ord1136, true);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("eval_args_ans");
      eval_args_ansindex1064 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({0, 1});
      slog::Relation* readrel1141 = db->getRelation("tick_ans");
      tick_ansindex1065 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({0, 1});
      slog::Relation* readrel1143 = db->getRelation("extend_env_ans");
      extend_env_ansindex1066 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 2, 0});
      slog::Relation* readrel1145 = db->getRelation("lambda");
      lambdaindex1067 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({1, 2, 0});
      slog::Relation* readrel1147 = db->getRelation("lambda");
      lambdadelta1080 = readrel1147->getIndex(ord1146, true);
      std::vector<u16> ord1148({1, 2, 0});
      slog::Relation* readrel1149 = db->getRelation("closure");
      closureindex1068 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({1, 2, 0});
      slog::Relation* readrel1151 = db->getRelation("closure");
      closuredelta1081 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({0, 1});
      slog::Relation* readrel1153 = db->getRelation("eval_ans");
      eval_ansindex1069 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({3, 1, 0, 2});
      slog::Relation* readrel1155 = db->getRelation("eval");
      evalindex1070 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({3, 1, 0, 2});
      slog::Relation* readrel1157 = db->getRelation("eval");
      evaldelta1082 = readrel1157->getIndex(ord1156, true);
      std::vector<u16> ord1158({0, 1});
      slog::Relation* readrel1159 = db->getRelation("extend_env_ans");
      extend_env_ansindex1071 = readrel1159->getIndex(ord1158, false);
      std::vector<u16> ord1160({0, 1});
      slog::Relation* readrel1161 = db->getRelation("eval_ans");
      eval_ansindex1072 = readrel1161->getIndex(ord1160, false);
  
    }
    ReadTask1083(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c158 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c138 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c26 = _t[4];
        if (!slog::exists_probe<3,2>(appindex1045, std::array<u64,3>{v_c137, v_c138, 0})) return;
        if (!slog::exists_probe<4,3>(evalindex1046, std::array<u64,4>{v_c137, v_c31, v_c26, 0})) return;
        if (!slog::exists_probe<13,5>($sup70016x51x0x0x1index1047, std::array<u64,13>{v_c137, v_c138, v_c158, v_c31, v_c26, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,3>(eval_argsindex1048, std::array<u64,4>{v_c138, v_c26, v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1049, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe_old<4,3>(evalindex1050, evaldelta1073, std::array<u64,4>{v_c31, v_c26, v_c158, 0}, [&](const std::array<u64,4>& m1162) {
          u64 v_c159 = m1162[3];
          slog::join_probe_old<3,3>(appindex1051, appdelta1074, std::array<u64,3>{v_c159, v_c137, v_c138}, [&](const std::array<u64,3>& m1163) {
            if (!slog::exists_probe<3,2>(tickindex1052, std::array<u64,3>{v_c159, v_c26, 0})) return;
            slog::join_probe_old<4,3>(evalindex1053, evaldelta1075, std::array<u64,4>{v_c137, v_c31, v_c26, 0}, [&](const std::array<u64,4>& m1164) {
              u64 v_c160 = m1164[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1054, std::array<u64,2>{v_c160, 0})) return;
              slog::join_probe_old<13,6>($sup70016x51x0x0x1index1055, $sup70016x51x0x0x1delta1076, std::array<u64,13>{v_c137, v_c138, v_c158, v_c31, v_c26, v_c160, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1165) {
                u64 v_c161 = m1165[6]; u64 v_c162 = m1165[7]; u64 v_c28 = m1165[8]; u64 v_c163 = m1165[9]; u64 v_c164 = m1165[10]; u64 v_c134 = m1165[11]; u64 v_c165 = m1165[12];
                slog::join_probe_old<4,4>(eval_argsindex1056, eval_argsdelta1077, std::array<u64,4>{v_c26, v_c31, v_c161, v_c138}, [&](const std::array<u64,4>& m1166) {
                  slog::join_probe_old<3,3>(tickindex1057, tickdelta1078, std::array<u64,3>{v_c162, v_c26, v_c159}, [&](const std::array<u64,3>& m1167) {
                    if (!slog::exists_probe<2,2>(eval_args_ansindex1058, std::array<u64,2>{v_c161, v_c134})) return;
                    if (!slog::exists_probe<2,2>(tick_ansindex1059, std::array<u64,2>{v_c162, v_c164})) return;
                    if (!slog::exists_probe<3,2>(lambdaindex1060, std::array<u64,3>{v_c165, v_c28, 0})) return;
                    if (!slog::exists_probe<3,1>(closureindex1061, std::array<u64,3>{v_c163, 0, 0})) return;
                    if (!slog::exists_probe<4,2>(evalindex1062, std::array<u64,4>{v_c164, v_c28, 0, 0})) return;
                    slog::join_probe_old<4,3>(extend_envindex1063, extend_envdelta1079, std::array<u64,4>{v_c163, v_c165, v_c164, 0}, [&](const std::array<u64,4>& m1168) {
                      u64 v_c166 = m1168[3];
                      slog::join_probe<2,2>(eval_args_ansindex1064, std::array<u64,2>{v_c161, v_c134}, [&](const std::array<u64,2>& m1169) {
                        slog::join_probe<2,2>(tick_ansindex1065, std::array<u64,2>{v_c162, v_c164}, [&](const std::array<u64,2>& m1170) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex1066, std::array<u64,2>{v_c166, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex1067, lambdadelta1080, std::array<u64,3>{v_c165, v_c28, 0}, [&](const std::array<u64,3>& m1171) {
                            u64 v_c167 = m1171[2];
                            slog::join_probe_old<3,2>(closureindex1068, closuredelta1081, std::array<u64,3>{v_c167, v_c163, 0}, [&](const std::array<u64,3>& m1172) {
                              u64 v_c168 = m1172[2];
                              slog::join_probe<2,2>(eval_ansindex1069, std::array<u64,2>{v_c160, v_c168}, [&](const std::array<u64,2>& m1173) {
                                slog::join_probe_old<4,2>(evalindex1070, evaldelta1082, std::array<u64,4>{v_c164, v_c28, 0, 0}, [&](const std::array<u64,4>& m1174) {
                                  u64 v_c169 = m1174[2]; u64 v_c17 = m1174[3];
                                  slog::join_probe<2,2>(extend_env_ansindex1071, std::array<u64,2>{v_c166, v_c17}, [&](const std::array<u64,2>& m1175) {
                                    slog::join_probe<2,1>(eval_ansindex1072, std::array<u64,2>{v_c169, 0}, [&](const std::array<u64,2>& m1176) {
                                      u64 v_c4 = m1176[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c158, v_c4}, std::array<u16,2>{0, 1});
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
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1083* _cont = new ReadTask1083(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1083(db,b), false);
  // (crule (pre) (scan mp_union __t5GHT421 __t4XKi420 t) (body (exists mp_put (1 2 3 0) 1 t) (join mleaf (0 1 2) 1 __t4XKi420 k v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t1yia422) (join mp_put_ans (0 1) 1 __t1yia422 r)) (head (emit mp_union_ans (0 1) __t5GHT421 r)) map.slog:92 #f)
  class ReadTask1182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1177;  slog::Index** mleafindex1178;  slog::Index** mp_putindex1179;  slog::Index** mp_put_ansindex1180;  slog::Index** mp_putdelta1181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1183({0, 1});
      slog::Relation* readrel1184 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1184->getIndex(ord1183, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1185({1, 2, 3, 0});
      slog::Relation* readrel1186 = db->getRelation("mp_put");
      mp_putindex1177 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({0, 1, 2});
      slog::Relation* readrel1188 = db->getRelation("mleaf");
      mleafindex1178 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 2, 3, 0});
      slog::Relation* readrel1190 = db->getRelation("mp_put");
      mp_putindex1179 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({1, 2, 3, 0});
      slog::Relation* readrel1192 = db->getRelation("mp_put");
      mp_putdelta1181 = readrel1192->getIndex(ord1191, true);
      std::vector<u16> ord1193({0, 1});
      slog::Relation* readrel1194 = db->getRelation("mp_put_ans");
      mp_put_ansindex1180 = readrel1194->getIndex(ord1193, false);
  
    }
    ReadTask1182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c170 = _t[0];
        u64 v_c171 = _t[1];
        u64 v_c26 = _t[2];
        if (!slog::exists_probe<4,1>(mp_putindex1177, std::array<u64,4>{v_c26, 0, 0, 0})) return;
        slog::join_probe<3,1>(mleafindex1178, std::array<u64,3>{v_c171, 0, 0}, [&](const std::array<u64,3>& m1195) {
          u64 v_c3 = m1195[1]; u64 v_c4 = m1195[2];
          slog::join_probe_old<4,3>(mp_putindex1179, mp_putdelta1181, std::array<u64,4>{v_c26, v_c3, v_c4, 0}, [&](const std::array<u64,4>& m1196) {
            u64 v_c172 = m1196[3];
            slog::join_probe<2,1>(mp_put_ansindex1180, std::array<u64,2>{v_c172, 0}, [&](const std::array<u64,2>& m1197) {
              u64 v_c2 = m1197[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c170, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1182* _cont = new ReadTask1182(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1182(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mp_union __t7k4o120 l __t8CES119) (body (exists mp_union (2 0 1) 1 __t8CES119) (exists mbranch (3 0 1 2 4) 1 l) (exists $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (join mp_union (2 0 1) 1 __t8CES119 __t2hbE115 __t5EdF114) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t2hbE115 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t2hbE115 l) (join mbranch (3 0 1 2 4) 2 l __t5EdF114 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t2hbE115) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t2hbE115 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t8CES119) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t2hbE115 n q u v __t27ag118) (join mbranch (1 2 3 4 0) 5 q n u v __t8CES119) (join mp_msk (1 2 0) 3 q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask1217 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1198;  slog::Index** mbranchindex1199;  slog::Index** $sup5638x95x0x0x0index1200;  slog::Index** $sup5638x95x0x0x1index1201;  slog::Index** mp_union_ansindex1202;  slog::Index** mp_unionindex1203;  slog::Index** $sup5638x95x0x0x0index1204;  slog::Index** $sup5638x95x0x0x1index1205;  slog::Index** mbranchindex1206;  slog::Index** $sup5638x95x0x0x1index1207;  slog::Index** mp_mskindex1208;  slog::Index** mp_msk_ansindex1209;  slog::Index** $sup5638x95x0x0x0index1210;  slog::Index** mbranchindex1211;  slog::Index** mp_mskindex1212;  slog::Index** $sup5638x95x0x0x1index1213;  slog::Index** mbranchindex1214;  slog::Index** mp_mskindex1215;  slog::Index** mp_msk_ansindex1216;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1218({2, 0, 1});
      slog::Relation* readrel1219 = db->getRelation("mp_union");
      mp_unionindex1198 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({3, 0, 1, 2, 4});
      slog::Relation* readrel1221 = db->getRelation("mbranch");
      mbranchindex1199 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1223 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1200 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1225 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1201 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({0, 1});
      slog::Relation* readrel1227 = db->getRelation("mp_union_ans");
      mp_union_ansindex1202 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({2, 0, 1});
      slog::Relation* readrel1229 = db->getRelation("mp_union");
      mp_unionindex1203 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1231 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1204 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel1233 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1205 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({3, 0, 1, 2, 4});
      slog::Relation* readrel1235 = db->getRelation("mbranch");
      mbranchindex1206 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1237 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1207 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({2, 0, 1});
      slog::Relation* readrel1239 = db->getRelation("mp_msk");
      mp_mskindex1208 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({1, 0});
      slog::Relation* readrel1241 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1209 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1243 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1210 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 2, 3, 4, 0});
      slog::Relation* readrel1245 = db->getRelation("mbranch");
      mbranchindex1211 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({1, 2, 0});
      slog::Relation* readrel1247 = db->getRelation("mp_msk");
      mp_mskindex1212 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1249 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1213 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 2, 3, 4, 0});
      slog::Relation* readrel1251 = db->getRelation("mbranch");
      mbranchindex1214 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({1, 2, 0});
      slog::Relation* readrel1253 = db->getRelation("mp_msk");
      mp_mskindex1215 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({0, 1});
      slog::Relation* readrel1255 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1216 = readrel1255->getIndex(ord1254, false);
  
    }
    ReadTask1217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c97 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c96 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex1198, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1199, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index1200, std::array<u64,9>{v_c6, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index1201, std::array<u64,10>{v_c6, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex1202, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1256) {
          u64 v_c17 = m1256[1];
          slog::join_probe<3,1>(mp_unionindex1203, std::array<u64,3>{v_c96, 0, 0}, [&](const std::array<u64,3>& m1257) {
            u64 v_c92 = m1257[1]; u64 v_c95 = m1257[2];
            if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index1204, std::array<u64,9>{v_c92, v_c6, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index1205, std::array<u64,10>{v_c92, v_c6, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex1206, std::array<u64,5>{v_c6, v_c95, 0, 0, 0}, [&](const std::array<u64,5>& m1258) {
              u64 v_c8 = m1258[2]; u64 v_c7 = m1258[3]; u64 v_c2 = m1258[4];
              if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index1207, std::array<u64,10>{v_c6, v_c7, v_c8, v_c2, v_c92, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex1208, std::array<u64,3>{v_c7, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex1209, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe<9,5>($sup5638x95x0x0x0index1210, std::array<u64,9>{v_c6, v_c7, v_c8, v_c2, v_c92, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1259) {
                u64 v_c64 = m1259[5]; u64 v_c63 = m1259[6]; u64 v_c65 = m1259[7]; u64 v_c4 = m1259[8];
                u64 v_c173 = _prim_lt(db, v_c64, v_c7);
                if (v_c173 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                if (!v_c173) return;
                if (!slog::exists_probe<5,5>(mbranchindex1211, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, v_c96})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex1212, std::array<u64,3>{v_c63, v_c7, 0})) return;
                slog::join_probe<10,9>($sup5638x95x0x0x1index1213, std::array<u64,10>{v_c6, v_c7, v_c8, v_c2, v_c92, v_c64, v_c63, v_c65, v_c4, 0}, [&](const std::array<u64,10>& m1261) {
                  u64 v_c93 = m1261[9];
                  slog::join_probe<5,5>(mbranchindex1214, std::array<u64,5>{v_c63, v_c64, v_c65, v_c4, v_c96}, [&](const std::array<u64,5>& m1262) {
                    slog::join_probe<3,3>(mp_mskindex1215, std::array<u64,3>{v_c63, v_c7, v_c93}, [&](const std::array<u64,3>& m1263) {
                      slog::join_probe<2,2>(mp_msk_ansindex1216, std::array<u64,2>{v_c93, v_c8}, [&](const std::array<u64,2>& m1264) {
                        u64 v_c98 = _prim_band(db, v_c63, v_c7);
                        if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c174 = _prim_lt(db, v_c98, v_c91);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c174) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c92, v_c17, v_c7, v_c8, v_c2});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c17, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1217* _cont = new ReadTask1217(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1217(db,b), false);
  // (crule (pre) (scan eval __t3h00297 __t6No4296 rho t) (body (join ref (0 1) 1 __t6No4296 x)) (head (emit $sup70016x33x0x0x0 (3 1 0 2) x rho __t3h00297 t)) interp.slog:34 #f)
  class ReadTask1267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x33x0x0x0");
      std::vector<u16> ord1268({3, 1, 0, 2});
      slog::Relation* readrel1269 = db->getRelation("$sup70016x33x0x0x0");
      head_index[0] = readrel1269->getIndex(ord1268, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1270({0, 1});
      slog::Relation* readrel1271 = db->getRelation("ref");
      refindex1266 = readrel1271->getIndex(ord1270, false);
  
    }
    ReadTask1267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c175 = _t[0];
        u64 v_c176 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c26 = _t[3];
        slog::join_probe<2,1>(refindex1266, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m1272) {
          u64 v_c32 = m1272[1];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c32, v_c31, v_c175, v_c26}, std::array<u16,4>{3, 1, 0, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1267* _cont = new ReadTask1267(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1267(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x0 __t8K90240 k l m p r v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t8K90240 k v __t0CZp243) (exists mp_msk (1 2 0) 3 k m __t0CZp243) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3kyC239) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t8K90240 k __t3kyC239 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0CZp243) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask1292 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1273;  slog::Index** mp_putindex1274;  slog::Index** mp_mskindex1275;  slog::Index** mp_putindex1276;  slog::Index** mp_msk_ansindex1277;  slog::Index** $sup5638x40x0x0x1index1278;  slog::Index** mp_mskindex1279;  slog::Index** mp_msk_ansindex1280;  slog::Index** mbranchindex1281;  slog::Index** mp_putindex1282;  slog::Index** mp_mskindex1283;  slog::Index** mp_putindex1284;  slog::Index** mp_msk_ansindex1285;  slog::Index** mp_put_ansindex1286;  slog::Index** $sup5638x40x0x0x1delta1287;  slog::Index** mbranchdelta1288;  slog::Index** mp_putdelta1289;  slog::Index** mp_mskdelta1290;  slog::Index** mp_putdelta1291;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord1293({1, 2, 3, 4, 0});
      slog::Relation* readrel1294 = db->getRelation("mbranch");
      mbranchindex1273 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({3, 0, 2, 1});
      slog::Relation* readrel1296 = db->getRelation("mp_put");
      mp_putindex1274 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({1, 2, 0});
      slog::Relation* readrel1298 = db->getRelation("mp_msk");
      mp_mskindex1275 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 2, 3, 0});
      slog::Relation* readrel1300 = db->getRelation("mp_put");
      mp_putindex1276 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({1, 0});
      slog::Relation* readrel1302 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1277 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1304 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index1278 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1306 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta1287 = readrel1306->getIndex(ord1305, true);
      std::vector<u16> ord1307({1, 2, 0});
      slog::Relation* readrel1308 = db->getRelation("mp_msk");
      mp_mskindex1279 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1280 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 2, 3, 4, 0});
      slog::Relation* readrel1312 = db->getRelation("mbranch");
      mbranchindex1281 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({1, 2, 3, 4, 0});
      slog::Relation* readrel1314 = db->getRelation("mbranch");
      mbranchdelta1288 = readrel1314->getIndex(ord1313, true);
      std::vector<u16> ord1315({0, 2, 1, 3});
      slog::Relation* readrel1316 = db->getRelation("mp_put");
      mp_putindex1282 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({0, 2, 1, 3});
      slog::Relation* readrel1318 = db->getRelation("mp_put");
      mp_putdelta1289 = readrel1318->getIndex(ord1317, true);
      std::vector<u16> ord1319({1, 2, 0});
      slog::Relation* readrel1320 = db->getRelation("mp_msk");
      mp_mskindex1283 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("mp_msk");
      mp_mskdelta1290 = readrel1322->getIndex(ord1321, true);
      std::vector<u16> ord1323({1, 2, 3, 0});
      slog::Relation* readrel1324 = db->getRelation("mp_put");
      mp_putindex1284 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({1, 2, 3, 0});
      slog::Relation* readrel1326 = db->getRelation("mp_put");
      mp_putdelta1291 = readrel1326->getIndex(ord1325, true);
      std::vector<u16> ord1327({0, 1});
      slog::Relation* readrel1328 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1285 = readrel1328->getIndex(ord1327, false);
      std::vector<u16> ord1329({0, 1});
      slog::Relation* readrel1330 = db->getRelation("mp_put_ans");
      mp_put_ansindex1286 = readrel1330->getIndex(ord1329, false);
  
    }
    ReadTask1292(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c178 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c4 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex1273, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex1274, std::array<u64,4>{v_c4, v_c178, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex1275, std::array<u64,3>{v_c3, v_c7, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex1276, std::array<u64,4>{v_c6, v_c3, v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1277, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe_old<8,7>($sup5638x40x0x0x1index1278, $sup5638x40x0x0x1delta1287, std::array<u64,8>{v_c6, v_c7, v_c8, v_c2, v_c178, v_c3, v_c4, 0}, [&](const std::array<u64,8>& m1331) {
          u64 v_c179 = m1331[7];
          if (!slog::exists_probe<3,3>(mp_mskindex1279, std::array<u64,3>{v_c3, v_c7, v_c179})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex1280, std::array<u64,2>{v_c179, v_c8})) return;
          slog::join_probe_old<5,4>(mbranchindex1281, mbranchdelta1288, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m1332) {
            u64 v_c180 = m1332[4];
            slog::join_probe_old<4,4>(mp_putindex1282, mp_putdelta1289, std::array<u64,4>{v_c178, v_c3, v_c180, v_c4}, [&](const std::array<u64,4>& m1333) {
              slog::join_probe_old<3,3>(mp_mskindex1283, mp_mskdelta1290, std::array<u64,3>{v_c3, v_c7, v_c179}, [&](const std::array<u64,3>& m1334) {
                slog::join_probe_old<4,3>(mp_putindex1284, mp_putdelta1291, std::array<u64,4>{v_c6, v_c3, v_c4, 0}, [&](const std::array<u64,4>& m1335) {
                  u64 v_c181 = m1335[3];
                  slog::join_probe<2,2>(mp_msk_ansindex1285, std::array<u64,2>{v_c179, v_c8}, [&](const std::array<u64,2>& m1336) {
                    slog::join_probe<2,1>(mp_put_ansindex1286, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m1337) {
                      u64 v_c17 = m1337[1];
                      u64 v_c182 = _prim_band(db, v_c3, v_c7);
                      if (v_c182 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c183 = _prim_lt(db, v_c182, v_c177);
                      if (v_c183 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c183) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c178, v_c17, v_c7, v_c8, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c8, v_c7, v_c17, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1292* _cont = new ReadTask1292(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1292(db,b), false);
  // (crule (pre) (scan mbranch __t7y6C599 p m u v) (body (exists mp_union (2 0 1) 1 __t7y6C599) (join-old mbranch (1 2 3 4 0) 2 (1 2 3 4 0) p m l r __t04LR600) (join-old mp_union (1 2 0) 2 (1 2 0) __t04LR600 __t7y6C599 __t2zhu601)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t2zhu601 l m p r u v)) map.slog:94 #f)
  class ReadTask1344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1339;  slog::Index** mbranchindex1340;  slog::Index** mp_unionindex1341;  slog::Index** mbranchdelta1342;  slog::Index** mp_uniondelta1343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord1345({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel1346 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel1346->getIndex(ord1345, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1347({2, 0, 1});
      slog::Relation* readrel1348 = db->getRelation("mp_union");
      mp_unionindex1339 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 2, 3, 4, 0});
      slog::Relation* readrel1350 = db->getRelation("mbranch");
      mbranchindex1340 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 2, 3, 4, 0});
      slog::Relation* readrel1352 = db->getRelation("mbranch");
      mbranchdelta1342 = readrel1352->getIndex(ord1351, true);
      std::vector<u16> ord1353({1, 2, 0});
      slog::Relation* readrel1354 = db->getRelation("mp_union");
      mp_unionindex1341 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("mp_union");
      mp_uniondelta1343 = readrel1356->getIndex(ord1355, true);
  
    }
    ReadTask1344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c184 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c4 = _t[4];
        if (!slog::exists_probe<3,1>(mp_unionindex1339, std::array<u64,3>{v_c184, 0, 0})) return;
        slog::join_probe_old<5,2>(mbranchindex1340, mbranchdelta1342, std::array<u64,5>{v_c8, v_c7, 0, 0, 0}, [&](const std::array<u64,5>& m1357) {
          u64 v_c6 = m1357[2]; u64 v_c2 = m1357[3]; u64 v_c185 = m1357[4];
          slog::join_probe_old<3,2>(mp_unionindex1341, mp_uniondelta1343, std::array<u64,3>{v_c185, v_c184, 0}, [&](const std::array<u64,3>& m1358) {
            u64 v_c186 = m1358[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c186, v_c6, v_c7, v_c8, v_c2, v_c65, v_c4}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1344* _cont = new ReadTask1344(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1344(db,b), false);
  // (crule (pre) (scan $sup70016x75x0x0x0 __d0 ef es rho t) (body (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t6oYx552) (exists eval_ans (0 1) 1 __t6oYx552) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t11mn554) (exists eval_args_ans (0 1) 1 __t11mn554) (join-old eval_ans (0 1) 1 (0 1) __t6oYx552 __t21iW553) (join-old eval_args_ans (0 1) 1 (0 1) __t11mn554 vs) (join-old prim (0 1) 1 (0 1) __t21iW553 op)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask1372 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1359;  slog::Index** evalindex1360;  slog::Index** eval_ansindex1361;  slog::Index** eval_argsindex1362;  slog::Index** eval_args_ansindex1363;  slog::Index** eval_ansindex1364;  slog::Index** eval_args_ansindex1365;  slog::Index** primindex1366;  slog::Index** evaldelta1367;  slog::Index** eval_argsdelta1368;  slog::Index** eval_ansdelta1369;  slog::Index** eval_args_ansdelta1370;  slog::Index** primdelta1371;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord1373({1, 3, 2, 0});
      slog::Relation* readrel1374 = db->getRelation("eval_args");
      eval_argsindex1359 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 3, 0});
      slog::Relation* readrel1376 = db->getRelation("eval");
      evalindex1360 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 3, 0});
      slog::Relation* readrel1378 = db->getRelation("eval");
      evaldelta1367 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({0, 1});
      slog::Relation* readrel1380 = db->getRelation("eval_ans");
      eval_ansindex1361 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 3, 2, 0});
      slog::Relation* readrel1382 = db->getRelation("eval_args");
      eval_argsindex1362 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 3, 2, 0});
      slog::Relation* readrel1384 = db->getRelation("eval_args");
      eval_argsdelta1368 = readrel1384->getIndex(ord1383, true);
      std::vector<u16> ord1385({0, 1});
      slog::Relation* readrel1386 = db->getRelation("eval_args_ans");
      eval_args_ansindex1363 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("eval_ans");
      eval_ansindex1364 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({0, 1});
      slog::Relation* readrel1390 = db->getRelation("eval_ans");
      eval_ansdelta1369 = readrel1390->getIndex(ord1389, true);
      std::vector<u16> ord1391({0, 1});
      slog::Relation* readrel1392 = db->getRelation("eval_args_ans");
      eval_args_ansindex1365 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({0, 1});
      slog::Relation* readrel1394 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1370 = readrel1394->getIndex(ord1393, true);
      std::vector<u16> ord1395({0, 1});
      slog::Relation* readrel1396 = db->getRelation("prim");
      primindex1366 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({0, 1});
      slog::Relation* readrel1398 = db->getRelation("prim");
      primdelta1371 = readrel1398->getIndex(ord1397, true);
  
    }
    ReadTask1372(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c138 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c26 = _t[4];
        if (!slog::exists_probe<4,3>(eval_argsindex1359, std::array<u64,4>{v_c138, v_c26, v_c31, 0})) return;
        slog::join_probe_old<4,3>(evalindex1360, evaldelta1367, std::array<u64,4>{v_c137, v_c31, v_c26, 0}, [&](const std::array<u64,4>& m1399) {
          u64 v_c187 = m1399[3];
          if (!slog::exists_probe<2,1>(eval_ansindex1361, std::array<u64,2>{v_c187, 0})) return;
          slog::join_probe_old<4,3>(eval_argsindex1362, eval_argsdelta1368, std::array<u64,4>{v_c138, v_c26, v_c31, 0}, [&](const std::array<u64,4>& m1400) {
            u64 v_c188 = m1400[3];
            if (!slog::exists_probe<2,1>(eval_args_ansindex1363, std::array<u64,2>{v_c188, 0})) return;
            slog::join_probe_old<2,1>(eval_ansindex1364, eval_ansdelta1369, std::array<u64,2>{v_c187, 0}, [&](const std::array<u64,2>& m1401) {
              u64 v_c189 = m1401[1];
              slog::join_probe_old<2,1>(eval_args_ansindex1365, eval_args_ansdelta1370, std::array<u64,2>{v_c188, 0}, [&](const std::array<u64,2>& m1402) {
                u64 v_c134 = m1402[1];
                slog::join_probe_old<2,1>(primindex1366, primdelta1371, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1403) {
                  u64 v_c120 = m1403[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c120, v_c134}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:$sup70016x75x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1372* _cont = new ReadTask1372(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1372(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst2fTo4 _00024seq2 __t9sv95) (body (letp _00024sql5qXm863 (aslst _00024seq2)) (letp __t4CTM7 (lref _00024sql5qXm863 _00024sqc32Jr866)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5fwv868 __t4CTM7 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo41sW869 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1lCq870 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4Tlp871 __t4CTM7 _00024seq2) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join-old prim (0 1) 1 (0 1) __t4CTM7 op) (let chk6ZKq1920 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk6ZKq1920) (letp chk3c721921 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk3c721921)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask1415 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1404;  slog::Index** $seq_atindex1405;  slog::Index** $seq_atrindex1406;  slog::Index** $seq_atrindex1407;  slog::Index** _enumindex1408;  slog::Index** primindex1409;  slog::Index** $seq_atdelta1410;  slog::Index** $seq_atdelta1411;  slog::Index** $seq_atrdelta1412;  slog::Index** $seq_atrdelta1413;  slog::Index** primdelta1414;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1416({1, 2, 0});
      slog::Relation* readrel1417 = db->getRelation("delta");
      driver_index = readrel1417->getIndex(ord1416, true);
      std::vector<u16> ord1418({1, 0, 2});
      slog::Relation* readrel1419 = db->getRelation("$seq_at");
      $seq_atindex1404 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({1, 0, 2});
      slog::Relation* readrel1421 = db->getRelation("$seq_at");
      $seq_atdelta1410 = readrel1421->getIndex(ord1420, true);
      std::vector<u16> ord1422({1, 0, 2});
      slog::Relation* readrel1423 = db->getRelation("$seq_at");
      $seq_atindex1405 = readrel1423->getIndex(ord1422, false);
      std::vector<u16> ord1424({1, 0, 2});
      slog::Relation* readrel1425 = db->getRelation("$seq_at");
      $seq_atdelta1411 = readrel1425->getIndex(ord1424, true);
      std::vector<u16> ord1426({1, 0, 2});
      slog::Relation* readrel1427 = db->getRelation("$seq_atr");
      $seq_atrindex1406 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({1, 0, 2});
      slog::Relation* readrel1429 = db->getRelation("$seq_atr");
      $seq_atrdelta1412 = readrel1429->getIndex(ord1428, true);
      std::vector<u16> ord1430({1, 0, 2});
      slog::Relation* readrel1431 = db->getRelation("$seq_atr");
      $seq_atrindex1407 = readrel1431->getIndex(ord1430, false);
      std::vector<u16> ord1432({1, 0, 2});
      slog::Relation* readrel1433 = db->getRelation("$seq_atr");
      $seq_atrdelta1413 = readrel1433->getIndex(ord1432, true);
      std::vector<u16> ord1434({1, 0});
      slog::Relation* readrel1435 = db->getRelation("_enum");
      _enumindex1408 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({0, 1});
      slog::Relation* readrel1437 = db->getRelation("prim");
      primindex1409 = readrel1437->getIndex(ord1436, false);
      std::vector<u16> ord1438({0, 1});
      slog::Relation* readrel1439 = db->getRelation("prim");
      primdelta1414 = readrel1439->getIndex(ord1438, true);
  
    }
    ReadTask1415(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c190 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c191 = v_const06abaa100ecef791ce028c56;
      u64 v_c192 = v_constd4735e3a265e16eee03f5971;
      u64 v_c193 = v_const5feceb66ffc86f38d952786c;
      u64 v_c194 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c195 = v_const5feceb66ffc86f38d952786c;
      u64 v_c196 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c197 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c198 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c191, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1440) {
        u64 v_c118 = m1440[1];
        u64 v_c199 = m1440[2];
        if (buckethash(v_c118) != bucket) return;
        bool ok1441 = true;
        u64 v_c200 = _prim_aslst(db, v_c118, &ok1441);
        if (!ok1441) return;
        bool ok1442 = true;
        u64 v_c201 = _prim_lref(db, v_c200, v_c193, &ok1442);
        if (!ok1442) return;
        slog::join_probe_old<3,3>($seq_atindex1404, $seq_atdelta1410, std::array<u64,3>{v_c195, v_c201, v_c118}, [&](const std::array<u64,3>& m1443) {
          slog::join_probe_old<3,3>($seq_atindex1405, $seq_atdelta1411, std::array<u64,3>{v_c196, v_c201, v_c118}, [&](const std::array<u64,3>& m1444) {
            slog::join_probe_old<3,3>($seq_atrindex1406, $seq_atrdelta1412, std::array<u64,3>{v_c197, v_c201, v_c118}, [&](const std::array<u64,3>& m1445) {
              slog::join_probe_old<3,3>($seq_atrindex1407, $seq_atrdelta1413, std::array<u64,3>{v_c198, v_c201, v_c118}, [&](const std::array<u64,3>& m1446) {
                slog::join_probe<2,1>(_enumindex1408, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1447) {
                  u64 v_c202 = m1447[1];
                  slog::join_probe_old<2,1>(primindex1409, primdelta1414, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1448) {
                    u64 v_c120 = m1448[1];
                    u64 v_c203 = _prim_llen(db, v_c200);
                    if (v_c203 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c192 != v_c203) return;
                    bool ok1449 = true;
                    u64 v_c204 = _prim_lref(db, v_c200, v_c194, &ok1449);
                    if (!ok1449) return;
                    if (v_c201 != v_c204) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c199});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c202}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1415* _cont = new ReadTask1415(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1415(db,b), false);
  // (crule (pre) (scan temp1sew1876 __t9Sw7529) (body) (head (mkstruct mp_hsb (1 0) __2BrK1190 __t9Sw7529)) map.slog:26 #f)
  class ReadTask1450 : public slog::Task
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
      outer_rel = db->getRelation("temp1sew1876");
  
    }
    ReadTask1450(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c205 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c205}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp1sew1876", _fires);
  
      if (!_done)
      {
        ReadTask1450* _cont = new ReadTask1450(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1450(db,b), false);
  // (crule (pre) (scan mbranch __t8pu9395 p m l r) (body (exists mp_del (1 2 0) 1 __t8pu9395) (exists mp_msk (2 0 1) 1 m) (join $sup5638x81x0x0x0 (2 3 4 5 0 1) 4 l m p r __t5Y7y396 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t5Y7y396 k __t8pu9395) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t0MS8397) (join mp_msk_ans (0 1) 1 __t0MS8397 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t5Y7y396 __t8pu9395)) map.slog:82 #f)
  class ReadTask1459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex1451;  slog::Index** mp_mskindex1452;  slog::Index** $sup5638x81x0x0x0index1453;  slog::Index** mp_delindex1454;  slog::Index** mp_mskindex1455;  slog::Index** mp_msk_ansindex1456;  slog::Index** mp_deldelta1457;  slog::Index** mp_mskdelta1458;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1460({0, 1});
      slog::Relation* readrel1461 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1461->getIndex(ord1460, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1462({1, 2, 0});
      slog::Relation* readrel1463 = db->getRelation("mp_del");
      mp_delindex1451 = readrel1463->getIndex(ord1462, false);
      std::vector<u16> ord1464({2, 0, 1});
      slog::Relation* readrel1465 = db->getRelation("mp_msk");
      mp_mskindex1452 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel1467 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index1453 = readrel1467->getIndex(ord1466, false);
      std::vector<u16> ord1468({0, 2, 1});
      slog::Relation* readrel1469 = db->getRelation("mp_del");
      mp_delindex1454 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({0, 2, 1});
      slog::Relation* readrel1471 = db->getRelation("mp_del");
      mp_deldelta1457 = readrel1471->getIndex(ord1470, true);
      std::vector<u16> ord1472({1, 2, 0});
      slog::Relation* readrel1473 = db->getRelation("mp_msk");
      mp_mskindex1455 = readrel1473->getIndex(ord1472, false);
      std::vector<u16> ord1474({1, 2, 0});
      slog::Relation* readrel1475 = db->getRelation("mp_msk");
      mp_mskdelta1458 = readrel1475->getIndex(ord1474, true);
      std::vector<u16> ord1476({0, 1});
      slog::Relation* readrel1477 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1456 = readrel1477->getIndex(ord1476, false);
  
    }
    ReadTask1459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c206 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c2 = _t[4];
        if (!slog::exists_probe<3,1>(mp_delindex1451, std::array<u64,3>{v_c206, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1452, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x81x0x0x0index1453, std::array<u64,6>{v_c6, v_c7, v_c8, v_c2, 0, 0}, [&](const std::array<u64,6>& m1478) {
          u64 v_c207 = m1478[4]; u64 v_c3 = m1478[5];
          slog::join_probe_old<3,3>(mp_delindex1454, mp_deldelta1457, std::array<u64,3>{v_c207, v_c3, v_c206}, [&](const std::array<u64,3>& m1479) {
            slog::join_probe_old<3,2>(mp_mskindex1455, mp_mskdelta1458, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m1480) {
              u64 v_c208 = m1480[2];
              slog::join_probe<2,1>(mp_msk_ansindex1456, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m1481) {
                u64 v_c17 = m1481[1];
                if (v_c8 == v_c17) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c207, v_c206}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1459* _cont = new ReadTask1459(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1459(db,b), false);
  // (crule (pre (let __tconst8HHZ1552 constb9e118781cea1f9fa01462e0)) (scan boolval __t48JJ272 __t7uDW271) (body (join _enum (0 1) 2 __t7uDW271 __tconst8HHZ1552)) (head (emit scheme_false (0) __t48JJ272)) interp.slog:82 #f)
  class ReadTask1483 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1482;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord1484({0});
      slog::Relation* readrel1485 = db->getRelation("scheme_false");
      head_index[0] = readrel1485->getIndex(ord1484, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord1486({0, 1});
      slog::Relation* readrel1487 = db->getRelation("_enum");
      _enumindex1482 = readrel1487->getIndex(ord1486, false);
  
    }
    ReadTask1483(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c210 = _t[0];
        u64 v_c211 = _t[1];
        slog::join_probe<2,2>(_enumindex1482, std::array<u64,2>{v_c211, v_c209}, [&](const std::array<u64,2>& m1488) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c210}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:82", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask1483* _cont = new ReadTask1483(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1483(db,b), false);
  // (crule (pre (let __tconst00GP779 const6b86b273ff34fce19d6b804e)) (scan $sup5638x67x0x0x0 __t8RYZ777 k t v) (body (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t8RYZ777) (exists mp_has0_ans (1 0) 1 __tconst00GP779) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t3FES778) (join mp_has0_ans (0 1) 2 __t3FES778 __tconst00GP779)) (head (emit mp_put_soft_ans (0 1) __t8RYZ777 t)) map.slog:68 #f)
  class ReadTask1495 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex1489;  slog::Index** mp_has0_ansindex1490;  slog::Index** mp_has0index1491;  slog::Index** mp_has0_ansindex1492;  slog::Index** mp_put_softdelta1493;  slog::Index** mp_has0delta1494;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord1496({0, 1});
      slog::Relation* readrel1497 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel1497->getIndex(ord1496, false);
      outer_rel = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord1498({1, 2, 3, 0});
      slog::Relation* readrel1499 = db->getRelation("mp_put_soft");
      mp_put_softindex1489 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({1, 2, 3, 0});
      slog::Relation* readrel1501 = db->getRelation("mp_put_soft");
      mp_put_softdelta1493 = readrel1501->getIndex(ord1500, true);
      std::vector<u16> ord1502({1, 0});
      slog::Relation* readrel1503 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1490 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("mp_has0");
      mp_has0index1491 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 2, 0});
      slog::Relation* readrel1507 = db->getRelation("mp_has0");
      mp_has0delta1494 = readrel1507->getIndex(ord1506, true);
      std::vector<u16> ord1508({0, 1});
      slog::Relation* readrel1509 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1492 = readrel1509->getIndex(ord1508, false);
  
    }
    ReadTask1495(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c212 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c213 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c4 = _t[3];
        slog::join_probe_old<4,4>(mp_put_softindex1489, mp_put_softdelta1493, std::array<u64,4>{v_c26, v_c3, v_c4, v_c213}, [&](const std::array<u64,4>& m1510) {
          if (!slog::exists_probe<2,1>(mp_has0_ansindex1490, std::array<u64,2>{v_c212, 0})) return;
          slog::join_probe_old<3,2>(mp_has0index1491, mp_has0delta1494, std::array<u64,3>{v_c26, v_c3, 0}, [&](const std::array<u64,3>& m1511) {
            u64 v_c214 = m1511[2];
            slog::join_probe<2,2>(mp_has0_ansindex1492, std::array<u64,2>{v_c214, v_c212}, [&](const std::array<u64,2>& m1512) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c213, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:$sup5638x67x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1495* _cont = new ReadTask1495(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1495(db,b), false);
  // (crule (pre (let __tconst9dzl332 const6b86b273ff34fce19d6b804e)) (scan mp_put __t24wX331 __t88jc330 k v) (body (join mbranch (0 1 2 3 4) 1 __t88jc330 p m l r) (let __t85Nm333 (band k m)) (cmp lt __t85Nm333 __tconst9dzl332)) (head (emit $sup5638x40x0x0x0 (4 2 3 5 0 1 6) p l m r __t24wX331 k v)) map.slog:41 #f)
  class ReadTask1514 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1513;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord1515({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1516 = db->getRelation("$sup5638x40x0x0x0");
      head_index[0] = readrel1516->getIndex(ord1515, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord1517({0, 1, 2, 3, 4});
      slog::Relation* readrel1518 = db->getRelation("mbranch");
      mbranchindex1513 = readrel1518->getIndex(ord1517, false);
  
    }
    ReadTask1514(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c215 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c216 = _t[0];
        u64 v_c217 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        slog::join_probe<5,1>(mbranchindex1513, std::array<u64,5>{v_c217, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1519) {
          u64 v_c8 = m1519[1]; u64 v_c7 = m1519[2]; u64 v_c6 = m1519[3]; u64 v_c2 = m1519[4];
          u64 v_c218 = _prim_band(db, v_c3, v_c7);
          if (v_c218 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          u64 v_c219 = _prim_lt(db, v_c218, v_c215);
          if (v_c219 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          if (!v_c219) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c8, v_c6, v_c7, v_c2, v_c216, v_c3, v_c4}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask1514* _cont = new ReadTask1514(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1514(db,b), false);
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (probe mp_has0_ans (1 0) 1 __tconst25r1527 __t5miQ526) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t5miQ526 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (exists mp_put (1 2 3 0) 2 t k) (join-old $sup5638x68x0x0x0 (1 2 3 0) 2 (1 2 3 0) k t v __t94M4525) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t94M4525) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t7U64528) (join-old mp_put_ans (0 1) 1 (0 1) __t7U64528 r)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask1533 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_has0index1521;  slog::Index** mp_put_softindex1522;  slog::Index** mp_putindex1523;  slog::Index** $sup5638x68x0x0x0index1524;  slog::Index** mp_put_softindex1525;  slog::Index** mp_putindex1526;  slog::Index** mp_put_ansindex1527;  slog::Index** mp_has0delta1528;  slog::Index** $sup5638x68x0x0x0delta1529;  slog::Index** mp_put_softdelta1530;  slog::Index** mp_putdelta1531;  slog::Index** mp_put_ansdelta1532;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord1534({0, 1});
      slog::Relation* readrel1535 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({1, 0});
      slog::Relation* readrel1537 = db->getRelation("mp_has0_ans");
      driver_index = readrel1537->getIndex(ord1536, true);
      std::vector<u16> ord1538({0, 2, 1});
      slog::Relation* readrel1539 = db->getRelation("mp_has0");
      mp_has0index1521 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({0, 2, 1});
      slog::Relation* readrel1541 = db->getRelation("mp_has0");
      mp_has0delta1528 = readrel1541->getIndex(ord1540, true);
      std::vector<u16> ord1542({1, 2, 3, 0});
      slog::Relation* readrel1543 = db->getRelation("mp_put_soft");
      mp_put_softindex1522 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({1, 2, 3, 0});
      slog::Relation* readrel1545 = db->getRelation("mp_put");
      mp_putindex1523 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({1, 2, 3, 0});
      slog::Relation* readrel1547 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index1524 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({1, 2, 3, 0});
      slog::Relation* readrel1549 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0delta1529 = readrel1549->getIndex(ord1548, true);
      std::vector<u16> ord1550({1, 2, 3, 0});
      slog::Relation* readrel1551 = db->getRelation("mp_put_soft");
      mp_put_softindex1525 = readrel1551->getIndex(ord1550, false);
      std::vector<u16> ord1552({1, 2, 3, 0});
      slog::Relation* readrel1553 = db->getRelation("mp_put_soft");
      mp_put_softdelta1530 = readrel1553->getIndex(ord1552, true);
      std::vector<u16> ord1554({1, 2, 3, 0});
      slog::Relation* readrel1555 = db->getRelation("mp_put");
      mp_putindex1526 = readrel1555->getIndex(ord1554, false);
      std::vector<u16> ord1556({1, 2, 3, 0});
      slog::Relation* readrel1557 = db->getRelation("mp_put");
      mp_putdelta1531 = readrel1557->getIndex(ord1556, true);
      std::vector<u16> ord1558({0, 1});
      slog::Relation* readrel1559 = db->getRelation("mp_put_ans");
      mp_put_ansindex1527 = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({0, 1});
      slog::Relation* readrel1561 = db->getRelation("mp_put_ans");
      mp_put_ansdelta1532 = readrel1561->getIndex(ord1560, true);
  
    }
    ReadTask1533(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c220 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c220, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1562) {
        u64 v_c221 = m1562[1];
        if (buckethash(v_c221) != bucket) return;
        slog::join_probe_old<3,1>(mp_has0index1521, mp_has0delta1528, std::array<u64,3>{v_c221, 0, 0}, [&](const std::array<u64,3>& m1563) {
          u64 v_c3 = m1563[1]; u64 v_c26 = m1563[2];
          if (!slog::exists_probe<4,2>(mp_put_softindex1522, std::array<u64,4>{v_c26, v_c3, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex1523, std::array<u64,4>{v_c26, v_c3, 0, 0})) return;
          slog::join_probe_old<4,2>($sup5638x68x0x0x0index1524, $sup5638x68x0x0x0delta1529, std::array<u64,4>{v_c3, v_c26, 0, 0}, [&](const std::array<u64,4>& m1564) {
            u64 v_c4 = m1564[2]; u64 v_c222 = m1564[3];
            slog::join_probe_old<4,4>(mp_put_softindex1525, mp_put_softdelta1530, std::array<u64,4>{v_c26, v_c3, v_c4, v_c222}, [&](const std::array<u64,4>& m1565) {
              slog::join_probe_old<4,3>(mp_putindex1526, mp_putdelta1531, std::array<u64,4>{v_c26, v_c3, v_c4, 0}, [&](const std::array<u64,4>& m1566) {
                u64 v_c223 = m1566[3];
                slog::join_probe_old<2,1>(mp_put_ansindex1527, mp_put_ansdelta1532, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1567) {
                  u64 v_c2 = m1567[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c222, v_c2}, std::array<u16,2>{0, 1});
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
        ReadTask1533* _cont = new ReadTask1533(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1533(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mp_has0_ans __t81Rn328 a) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t81Rn328 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t6Aa9325 m p r) (exists mp_has0 (0 2 1) 2 __t6Aa9325 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0WBy324) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t6Aa9325 k __t0WBy324) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2ONI329) (join-old mp_msk_ans (0 1) 2 (0 1) __t2ONI329 p) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask1586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1568;  slog::Index** mbranchindex1569;  slog::Index** mp_has0index1570;  slog::Index** mp_mskindex1571;  slog::Index** $sup5638x60x0x0x0index1572;  slog::Index** mp_has0index1573;  slog::Index** mp_mskindex1574;  slog::Index** mp_msk_ansindex1575;  slog::Index** mbranchindex1576;  slog::Index** mp_has0index1577;  slog::Index** mp_mskindex1578;  slog::Index** mp_msk_ansindex1579;  slog::Index** mp_has0delta1580;  slog::Index** $sup5638x60x0x0x0delta1581;  slog::Index** mbranchdelta1582;  slog::Index** mp_has0delta1583;  slog::Index** mp_mskdelta1584;  slog::Index** mp_msk_ansdelta1585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1587({0, 1});
      slog::Relation* readrel1588 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1588->getIndex(ord1587, false);
      outer_rel = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1589({0, 2, 1});
      slog::Relation* readrel1590 = db->getRelation("mp_has0");
      mp_has0index1568 = readrel1590->getIndex(ord1589, false);
      std::vector<u16> ord1591({0, 2, 1});
      slog::Relation* readrel1592 = db->getRelation("mp_has0");
      mp_has0delta1580 = readrel1592->getIndex(ord1591, true);
      std::vector<u16> ord1593({3, 0, 1, 2, 4});
      slog::Relation* readrel1594 = db->getRelation("mbranch");
      mbranchindex1569 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({2, 0, 1});
      slog::Relation* readrel1596 = db->getRelation("mp_has0");
      mp_has0index1570 = readrel1596->getIndex(ord1595, false);
      std::vector<u16> ord1597({1, 2, 0});
      slog::Relation* readrel1598 = db->getRelation("mp_msk");
      mp_mskindex1571 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1600 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index1572 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1602 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0delta1581 = readrel1602->getIndex(ord1601, true);
      std::vector<u16> ord1603({0, 2, 1});
      slog::Relation* readrel1604 = db->getRelation("mp_has0");
      mp_has0index1573 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({1, 2, 0});
      slog::Relation* readrel1606 = db->getRelation("mp_msk");
      mp_mskindex1574 = readrel1606->getIndex(ord1605, false);
      std::vector<u16> ord1607({1, 0});
      slog::Relation* readrel1608 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1575 = readrel1608->getIndex(ord1607, false);
      std::vector<u16> ord1609({1, 2, 3, 4, 0});
      slog::Relation* readrel1610 = db->getRelation("mbranch");
      mbranchindex1576 = readrel1610->getIndex(ord1609, false);
      std::vector<u16> ord1611({1, 2, 3, 4, 0});
      slog::Relation* readrel1612 = db->getRelation("mbranch");
      mbranchdelta1582 = readrel1612->getIndex(ord1611, true);
      std::vector<u16> ord1613({0, 2, 1});
      slog::Relation* readrel1614 = db->getRelation("mp_has0");
      mp_has0index1577 = readrel1614->getIndex(ord1613, false);
      std::vector<u16> ord1615({0, 2, 1});
      slog::Relation* readrel1616 = db->getRelation("mp_has0");
      mp_has0delta1583 = readrel1616->getIndex(ord1615, true);
      std::vector<u16> ord1617({1, 2, 0});
      slog::Relation* readrel1618 = db->getRelation("mp_msk");
      mp_mskindex1578 = readrel1618->getIndex(ord1617, false);
      std::vector<u16> ord1619({1, 2, 0});
      slog::Relation* readrel1620 = db->getRelation("mp_msk");
      mp_mskdelta1584 = readrel1620->getIndex(ord1619, true);
      std::vector<u16> ord1621({0, 1});
      slog::Relation* readrel1622 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1579 = readrel1622->getIndex(ord1621, false);
      std::vector<u16> ord1623({0, 1});
      slog::Relation* readrel1624 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1585 = readrel1624->getIndex(ord1623, true);
  
    }
    ReadTask1586(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c225 = _t[0];
        u64 v_c226 = _t[1];
        slog::join_probe_old<3,1>(mp_has0index1568, mp_has0delta1580, std::array<u64,3>{v_c225, 0, 0}, [&](const std::array<u64,3>& m1625) {
          u64 v_c3 = m1625[1]; u64 v_c6 = m1625[2];
          if (!slog::exists_probe<5,1>(mbranchindex1569, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index1570, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1571, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x60x0x0x0index1572, $sup5638x60x0x0x0delta1581, std::array<u64,6>{v_c3, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1626) {
            u64 v_c227 = m1626[2]; u64 v_c7 = m1626[3]; u64 v_c8 = m1626[4]; u64 v_c2 = m1626[5];
            if (!slog::exists_probe<3,2>(mp_has0index1573, std::array<u64,3>{v_c227, v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1574, std::array<u64,3>{v_c3, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1575, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1576, mbranchdelta1582, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, 0}, [&](const std::array<u64,5>& m1627) {
              u64 v_c228 = m1627[4];
              slog::join_probe_old<3,3>(mp_has0index1577, mp_has0delta1583, std::array<u64,3>{v_c227, v_c3, v_c228}, [&](const std::array<u64,3>& m1628) {
                slog::join_probe_old<3,2>(mp_mskindex1578, mp_mskdelta1584, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m1629) {
                  u64 v_c229 = m1629[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex1579, mp_msk_ansdelta1585, std::array<u64,2>{v_c229, v_c8}, [&](const std::array<u64,2>& m1630) {
                    u64 v_c230 = _prim_band(db, v_c3, v_c7);
                    if (v_c230 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c231 = _prim_lt(db, v_c230, v_c224);
                    if (v_c231 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c231) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c227, v_c226}, std::array<u16,2>{0, 1});
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
        ReadTask1586* _cont = new ReadTask1586(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1586(db,b), false);
  // (crule (pre (let __tconst8wBL581 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t8lWf583 __t0T68582 k) (body (exists mp_msk (1 2 0) 1 k) (join $sup5638x59x0x0x0 (0 1 2 3 4 5) 2 __t8lWf583 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t0T68582) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7zc5584) (join mp_msk_ans (0 1) 1 __t7zc5584 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t8lWf583 __tconst8wBL581)) map.slog:60 #f)
  class ReadTask1638 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex1632;  slog::Index** $sup5638x59x0x0x0index1633;  slog::Index** mbranchindex1634;  slog::Index** mp_mskindex1635;  slog::Index** mp_msk_ansindex1636;  slog::Index** mp_mskdelta1637;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1639({0, 1});
      slog::Relation* readrel1640 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1640->getIndex(ord1639, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord1641({1, 2, 0});
      slog::Relation* readrel1642 = db->getRelation("mp_msk");
      mp_mskindex1632 = readrel1642->getIndex(ord1641, false);
      std::vector<u16> ord1643({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1644 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index1633 = readrel1644->getIndex(ord1643, false);
      std::vector<u16> ord1645({1, 2, 3, 4, 0});
      slog::Relation* readrel1646 = db->getRelation("mbranch");
      mbranchindex1634 = readrel1646->getIndex(ord1645, false);
      std::vector<u16> ord1647({1, 2, 0});
      slog::Relation* readrel1648 = db->getRelation("mp_msk");
      mp_mskindex1635 = readrel1648->getIndex(ord1647, false);
      std::vector<u16> ord1649({1, 2, 0});
      slog::Relation* readrel1650 = db->getRelation("mp_msk");
      mp_mskdelta1637 = readrel1650->getIndex(ord1649, true);
      std::vector<u16> ord1651({0, 1});
      slog::Relation* readrel1652 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1636 = readrel1652->getIndex(ord1651, false);
  
    }
    ReadTask1638(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c232 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c233 = _t[0];
        u64 v_c234 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex1632, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x59x0x0x0index1633, std::array<u64,6>{v_c233, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1653) {
          u64 v_c6 = m1653[2]; u64 v_c7 = m1653[3]; u64 v_c8 = m1653[4]; u64 v_c2 = m1653[5];
          slog::join_probe<5,5>(mbranchindex1634, std::array<u64,5>{v_c8, v_c7, v_c6, v_c2, v_c234}, [&](const std::array<u64,5>& m1654) {
            slog::join_probe_old<3,2>(mp_mskindex1635, mp_mskdelta1637, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m1655) {
              u64 v_c235 = m1655[2];
              slog::join_probe<2,1>(mp_msk_ansindex1636, std::array<u64,2>{v_c235, 0}, [&](const std::array<u64,2>& m1656) {
                u64 v_c17 = m1656[1];
                if (v_c8 == v_c17) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c233, v_c232}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask1638* _cont = new ReadTask1638(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1638(db,b), false);
}

