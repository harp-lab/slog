
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3b05f339a47cf251e643e4dd;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const52b5e20f559958f34e533431;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const73475cb40a568e8da8a045ce;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_constaa218622af4adb846b2d6244;
extern u64 v_constc8dd3fe14ad7db61de7362fc;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;


void slog_rules_cb00fdd549d29ce0e(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan store x tx v) (body (exists mp_get (2 0 1) 1 x) (exists lookup (1 2 0) 1 x) (join mp_get_ans (1 0) 1 tx __t0Izo363) (join-old mp_get (0 2 1) 2 (0 2 1) __t0Izo363 x rho) (join-old lookup (1 2 0) 2 (1 2 0) x rho __t95yV362)) (head (emit lookup_ans (0 1) __t95yV362 v)) interp.slog:39 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex0;  slog::Index** lookupindex1;  slog::Index** mp_get_ansindex2;  slog::Index** mp_getindex3;  slog::Index** lookupindex4;  slog::Index** mp_getdelta5;  slog::Index** lookupdelta6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("lookup_ans");
      head_index[0] = readrel9->getIndex(ord8, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord10({2, 0, 1});
      slog::Relation* readrel11 = db->getRelation("mp_get");
      mp_getindex0 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 2, 0});
      slog::Relation* readrel13 = db->getRelation("lookup");
      lookupindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("mp_get_ans");
      mp_get_ansindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 2, 1});
      slog::Relation* readrel17 = db->getRelation("mp_get");
      mp_getindex3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 2, 1});
      slog::Relation* readrel19 = db->getRelation("mp_get");
      mp_getdelta5 = readrel19->getIndex(ord18, true);
      std::vector<u16> ord20({1, 2, 0});
      slog::Relation* readrel21 = db->getRelation("lookup");
      lookupindex4 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("lookup");
      lookupdelta6 = readrel23->getIndex(ord22, true);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(mp_getindex0, std::array<u64,3>{v_c0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lookupindex1, std::array<u64,3>{v_c0, 0, 0})) return;
        slog::join_probe<2,1>(mp_get_ansindex2, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m24) {
          u64 v_c3 = m24[1];
          slog::join_probe_old<3,2>(mp_getindex3, mp_getdelta5, std::array<u64,3>{v_c3, v_c0, 0}, [&](const std::array<u64,3>& m25) {
            u64 v_c4 = m25[2];
            slog::join_probe_old<3,2>(lookupindex4, lookupdelta6, std::array<u64,3>{v_c0, v_c4, 0}, [&](const std::array<u64,3>& m26) {
              u64 v_c5 = m26[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:store", _fires);
  
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
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e)) (scan temp65cH2007 __t0Vtj505 __t0cTh509 __t2zNy470 __t9oQ4490) (body (exists num (1 0) 1 __tconst0Ob1494) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472)) (head (emit-temp temp1lqI2008 __t0Vtj505 __t0cTh509 __t2zNy470 __t9oQ4490) (mkstruct app (1 2 0) __t9htJ493 __t3x0f492 __t9oQ4490)) kcfa.slog:40 #f)
  class ReadTask30 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex27;  slog::Index** primrefindex28;  slog::Index** numindex29;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1lqI2008");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp65cH2007");
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("num");
      numindex27 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("primref");
      primrefindex28 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("num");
      numindex29 = readrel36->getIndex(ord35, false);
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_consted725292f5f32d61535958c1;
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        if (!slog::exists_probe<2,1>(numindex27, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<2,1>(primrefindex28, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m37) {
          u64 v_c13 = m37[1];
          slog::join_probe<2,1>(numindex29, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m38) {
            u64 v_c14 = m38[1];
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c9, v_c10, v_c11, v_c12});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c12}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp65cH2007", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst2Vg0546 _00024seq2 __t6qCW547) (body (letp _00024sql3t08962 (aslst _00024seq2)) (letp __t40a6549 (lref _00024sql3t08962 _00024sqc2Wzv965)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5uVM967 __t40a6549 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo11r2968 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo89F1969 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo57Hb970 __t40a6549 _00024seq2) (join-old closure (0 1 2) 1 (0 1 2) __t40a6549 lm rc) (join any_bool (0) 0 b) (let chk2ZoO1839 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk2ZoO1839) (letp chk5Nza1840 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk5Nza1840)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask50 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex39;  slog::Index** $seq_atindex40;  slog::Index** $seq_atrindex41;  slog::Index** $seq_atrindex42;  slog::Index** closureindex43;  slog::Index** any_boolindex44;  slog::Index** $seq_atdelta45;  slog::Index** $seq_atdelta46;  slog::Index** $seq_atrdelta47;  slog::Index** $seq_atrdelta48;  slog::Index** closuredelta49;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("delta");
      driver_index = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 0, 2});
      slog::Relation* readrel54 = db->getRelation("$seq_at");
      $seq_atindex39 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0, 2});
      slog::Relation* readrel56 = db->getRelation("$seq_at");
      $seq_atdelta45 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({1, 0, 2});
      slog::Relation* readrel58 = db->getRelation("$seq_at");
      $seq_atindex40 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0, 2});
      slog::Relation* readrel60 = db->getRelation("$seq_at");
      $seq_atdelta46 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({1, 0, 2});
      slog::Relation* readrel62 = db->getRelation("$seq_atr");
      $seq_atrindex41 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 0, 2});
      slog::Relation* readrel64 = db->getRelation("$seq_atr");
      $seq_atrdelta47 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({1, 0, 2});
      slog::Relation* readrel66 = db->getRelation("$seq_atr");
      $seq_atrindex42 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 0, 2});
      slog::Relation* readrel68 = db->getRelation("$seq_atr");
      $seq_atrdelta48 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({0, 1, 2});
      slog::Relation* readrel70 = db->getRelation("closure");
      closureindex43 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 1, 2});
      slog::Relation* readrel72 = db->getRelation("closure");
      closuredelta49 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({0});
      slog::Relation* readrel74 = db->getRelation("any_bool");
      any_boolindex44 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const06abaa100ecef791ce028c56;
      u64 v_c16 = v_constd4735e3a265e16eee03f5971;
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c15, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m75) {
        u64 v_c23 = m75[1];
        u64 v_c24 = m75[2];
        if (buckethash(v_c23) != bucket) return;
        bool ok76 = true;
        u64 v_c25 = _prim_aslst(db, v_c23, &ok76);
        if (!ok76) return;
        bool ok77 = true;
        u64 v_c26 = _prim_lref(db, v_c25, v_c17, &ok77);
        if (!ok77) return;
        slog::join_probe_old<3,3>($seq_atindex39, $seq_atdelta45, std::array<u64,3>{v_c19, v_c26, v_c23}, [&](const std::array<u64,3>& m78) {
          slog::join_probe_old<3,3>($seq_atindex40, $seq_atdelta46, std::array<u64,3>{v_c20, v_c26, v_c23}, [&](const std::array<u64,3>& m79) {
            slog::join_probe_old<3,3>($seq_atrindex41, $seq_atrdelta47, std::array<u64,3>{v_c21, v_c26, v_c23}, [&](const std::array<u64,3>& m80) {
              slog::join_probe_old<3,3>($seq_atrindex42, $seq_atrdelta48, std::array<u64,3>{v_c22, v_c26, v_c23}, [&](const std::array<u64,3>& m81) {
                slog::join_probe_old<3,1>(closureindex43, closuredelta49, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m82) {
                  u64 v_c27 = m82[1]; u64 v_c28 = m82[2];
                  slog::join_all<1>(any_boolindex44, [&](const std::array<u64,1>& m83) {
                    u64 v_c29 = m83[0];
                    u64 v_c30 = _prim_llen(db, v_c25);
                    if (v_c30 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c16 != v_c30) return;
                    bool ok84 = true;
                    u64 v_c31 = _prim_lref(db, v_c25, v_c18, &ok84);
                    if (!ok84) return;
                    if (v_c26 != v_c31) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c29});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), false);
  // (crule (pre) (scan letrec __t0Sks357 x er eb) (body (exists $sup70016x95x0x0x1 (2 3 7 0 1 4 5 6) 3 eb er x) (exists eval (1 2 3 0) 1 __t0Sks357) (exists mp_put (2 3 0 1) 1 x) (exists eval (1 2 3 0) 1 er) (exists eval (1 2 3 0) 1 eb) (join $sup70016x95x0x0x0 (1 2 5 0 3 4) 3 eb er x __t7DhJ358 rho t) (exists eval (2 3 0 1) 4 rho t __t7DhJ358 __t0Sks357) (exists mp_put (1 2 3 0) 3 rho x t) (exists eval (3 1 0 2) 2 t er) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x95x0x0x1 (0 4 6 2 3 7 1 5) 6 __t7DhJ358 rho t eb er x __t0Rig361 rho2) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (1 2 3 0) 3 eb rho2 t) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho2 t __t6HuT359) (exists eval_ans (0 1) 1 __t6HuT359) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb rho2 t __t63JF360) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x1index85;  slog::Index** evalindex86;  slog::Index** mp_putindex87;  slog::Index** evalindex88;  slog::Index** evalindex89;  slog::Index** $sup70016x95x0x0x0index90;  slog::Index** evalindex91;  slog::Index** mp_putindex92;  slog::Index** evalindex93;  slog::Index** evalindex94;  slog::Index** $sup70016x95x0x0x1index95;  slog::Index** evalindex96;  slog::Index** mp_putindex97;  slog::Index** evalindex98;  slog::Index** mp_put_ansindex99;  slog::Index** evalindex100;  slog::Index** eval_ansindex101;  slog::Index** evalindex102;  slog::Index** mp_put_ansindex103;  slog::Index** eval_ansindex104;  slog::Index** eval_ansindex105;  slog::Index** eval_ansindex106;  slog::Index** evaldelta107;  slog::Index** mp_putdelta108;  slog::Index** evaldelta109;  slog::Index** evaldelta110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord112({0, 1});
      slog::Relation* readrel113 = db->getRelation("eval_ans");
      head_index[0] = readrel113->getIndex(ord112, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord114({2, 3, 7, 0, 1, 4, 5, 6});
      slog::Relation* readrel115 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index85 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 3, 0});
      slog::Relation* readrel117 = db->getRelation("eval");
      evalindex86 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({2, 3, 0, 1});
      slog::Relation* readrel119 = db->getRelation("mp_put");
      mp_putindex87 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 3, 0});
      slog::Relation* readrel121 = db->getRelation("eval");
      evalindex88 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 3, 0});
      slog::Relation* readrel123 = db->getRelation("eval");
      evalindex89 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 5, 0, 3, 4});
      slog::Relation* readrel125 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index90 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({2, 3, 0, 1});
      slog::Relation* readrel127 = db->getRelation("eval");
      evalindex91 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 3, 0});
      slog::Relation* readrel129 = db->getRelation("mp_put");
      mp_putindex92 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({3, 1, 0, 2});
      slog::Relation* readrel131 = db->getRelation("eval");
      evalindex93 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({3, 1, 0, 2});
      slog::Relation* readrel133 = db->getRelation("eval");
      evalindex94 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 4, 6, 2, 3, 7, 1, 5});
      slog::Relation* readrel135 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index95 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({2, 3, 0, 1});
      slog::Relation* readrel137 = db->getRelation("eval");
      evalindex96 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({2, 3, 0, 1});
      slog::Relation* readrel139 = db->getRelation("eval");
      evaldelta107 = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({0, 2, 1, 3});
      slog::Relation* readrel141 = db->getRelation("mp_put");
      mp_putindex97 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 2, 1, 3});
      slog::Relation* readrel143 = db->getRelation("mp_put");
      mp_putdelta108 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({1, 2, 3, 0});
      slog::Relation* readrel145 = db->getRelation("eval");
      evalindex98 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("mp_put_ans");
      mp_put_ansindex99 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 3, 0});
      slog::Relation* readrel149 = db->getRelation("eval");
      evalindex100 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 3, 0});
      slog::Relation* readrel151 = db->getRelation("eval");
      evaldelta109 = readrel151->getIndex(ord150, true);
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("eval_ans");
      eval_ansindex101 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 3, 0});
      slog::Relation* readrel155 = db->getRelation("eval");
      evalindex102 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 2, 3, 0});
      slog::Relation* readrel157 = db->getRelation("eval");
      evaldelta110 = readrel157->getIndex(ord156, true);
      std::vector<u16> ord158({0, 1});
      slog::Relation* readrel159 = db->getRelation("mp_put_ans");
      mp_put_ansindex103 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("eval_ans");
      eval_ansindex104 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({0, 1});
      slog::Relation* readrel163 = db->getRelation("eval_ans");
      eval_ansindex105 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("eval_ans");
      eval_ansindex106 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c0 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c34 = _t[3];
        if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index85, std::array<u64,8>{v_c34, v_c33, v_c0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex86, std::array<u64,4>{v_c32, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex87, std::array<u64,4>{v_c0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex88, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex89, std::array<u64,4>{v_c34, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x95x0x0x0index90, std::array<u64,6>{v_c34, v_c33, v_c0, 0, 0, 0}, [&](const std::array<u64,6>& m166) {
          u64 v_c35 = m166[3]; u64 v_c4 = m166[4]; u64 v_c36 = m166[5];
          if (!slog::exists_probe<4,4>(evalindex91, std::array<u64,4>{v_c4, v_c36, v_c35, v_c32})) return;
          if (!slog::exists_probe<4,3>(mp_putindex92, std::array<u64,4>{v_c4, v_c0, v_c36, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex93, std::array<u64,4>{v_c36, v_c33, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex94, std::array<u64,4>{v_c36, v_c34, 0, 0})) return;
          slog::join_probe<8,6>($sup70016x95x0x0x1index95, std::array<u64,8>{v_c35, v_c4, v_c36, v_c34, v_c33, v_c0, 0, 0}, [&](const std::array<u64,8>& m167) {
            u64 v_c37 = m167[6]; u64 v_c38 = m167[7];
            slog::join_probe_old<4,4>(evalindex96, evaldelta107, std::array<u64,4>{v_c4, v_c36, v_c35, v_c32}, [&](const std::array<u64,4>& m168) {
              slog::join_probe_old<4,4>(mp_putindex97, mp_putdelta108, std::array<u64,4>{v_c37, v_c0, v_c4, v_c36}, [&](const std::array<u64,4>& m169) {
                if (!slog::exists_probe<4,3>(evalindex98, std::array<u64,4>{v_c34, v_c38, v_c36, 0})) return;
                if (!slog::exists_probe<2,2>(mp_put_ansindex99, std::array<u64,2>{v_c37, v_c38})) return;
                slog::join_probe_old<4,3>(evalindex100, evaldelta109, std::array<u64,4>{v_c33, v_c38, v_c36, 0}, [&](const std::array<u64,4>& m170) {
                  u64 v_c39 = m170[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex101, std::array<u64,2>{v_c39, 0})) return;
                  slog::join_probe_old<4,3>(evalindex102, evaldelta110, std::array<u64,4>{v_c34, v_c38, v_c36, 0}, [&](const std::array<u64,4>& m171) {
                    u64 v_c40 = m171[3];
                    slog::join_probe<2,2>(mp_put_ansindex103, std::array<u64,2>{v_c37, v_c38}, [&](const std::array<u64,2>& m172) {
                      if (!slog::exists_probe<2,1>(eval_ansindex104, std::array<u64,2>{v_c40, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex105, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m173) {
                        u64 v_c41 = m173[1];
                        slog::join_probe<2,1>(eval_ansindex106, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m174) {
                          u64 v_c2 = m174[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:letrec", _fires);
  
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
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan $sup5638x98x0x0x1 __t14N0222 __t4NVE225 l m n p q r u v) (body (cmp lt n m) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t14N0222 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 3 q m __t4NVE225) (exists mp_msk_ans (0 1) 2 __t4NVE225 p) (exists mp_union (1 2 0) 1 r) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t006N221) (exists mp_union (0 1 2) 2 __t14N0222 __t006N221) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_union (0 1 2) 3 (0 1 2) __t14N0222 __t006N221 __t5FeR226) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask193 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index175;  slog::Index** mbranchindex176;  slog::Index** mp_mskindex177;  slog::Index** mp_msk_ansindex178;  slog::Index** mp_unionindex179;  slog::Index** mbranchindex180;  slog::Index** mp_unionindex181;  slog::Index** mbranchindex182;  slog::Index** mp_unionindex183;  slog::Index** mp_mskindex184;  slog::Index** mp_msk_ansindex185;  slog::Index** mp_unionindex186;  slog::Index** mp_union_ansindex187;  slog::Index** mbranchdelta188;  slog::Index** mbranchdelta189;  slog::Index** mp_uniondelta190;  slog::Index** mp_mskdelta191;  slog::Index** mp_uniondelta192;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord194({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel195 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index175 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 3, 4, 0});
      slog::Relation* readrel197 = db->getRelation("mbranch");
      mbranchindex176 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 2, 0});
      slog::Relation* readrel199 = db->getRelation("mp_msk");
      mp_mskindex177 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex178 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 2, 0});
      slog::Relation* readrel203 = db->getRelation("mp_union");
      mp_unionindex179 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 3, 4, 0});
      slog::Relation* readrel205 = db->getRelation("mbranch");
      mbranchindex180 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 2, 3, 4, 0});
      slog::Relation* readrel207 = db->getRelation("mbranch");
      mbranchdelta188 = readrel207->getIndex(ord206, true);
      std::vector<u16> ord208({0, 1, 2});
      slog::Relation* readrel209 = db->getRelation("mp_union");
      mp_unionindex181 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 3, 4, 0});
      slog::Relation* readrel211 = db->getRelation("mbranch");
      mbranchindex182 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 3, 4, 0});
      slog::Relation* readrel213 = db->getRelation("mbranch");
      mbranchdelta189 = readrel213->getIndex(ord212, true);
      std::vector<u16> ord214({0, 1, 2});
      slog::Relation* readrel215 = db->getRelation("mp_union");
      mp_unionindex183 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1, 2});
      slog::Relation* readrel217 = db->getRelation("mp_union");
      mp_uniondelta190 = readrel217->getIndex(ord216, true);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("mp_msk");
      mp_mskindex184 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("mp_msk");
      mp_mskdelta191 = readrel221->getIndex(ord220, true);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex185 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("mp_union");
      mp_unionindex186 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("mp_union");
      mp_uniondelta192 = readrel227->getIndex(ord226, true);
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("mp_union_ans");
      mp_union_ansindex187 = readrel229->getIndex(ord228, false);
  
    }
    ReadTask193(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c43 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        u64 v_c46 = _t[3];
        u64 v_c47 = _t[4];
        u64 v_c48 = _t[5];
        u64 v_c49 = _t[6];
        u64 v_c50 = _t[7];
        u64 v_c51 = _t[8];
        u64 v_c2 = _t[9];
        u64 v_c52 = _prim_lt(db, v_c47, v_c46);
        if (v_c52 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
        if (!v_c52) return;
        slog::join_probe<9,9>($sup5638x98x0x0x0index175, std::array<u64,9>{v_c48, v_c45, v_c46, v_c50, v_c43, v_c47, v_c49, v_c51, v_c2}, [&](const std::array<u64,9>& m231) {
          if (!slog::exists_probe<5,4>(mbranchindex176, std::array<u64,5>{v_c49, v_c47, v_c51, v_c2, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex177, std::array<u64,3>{v_c49, v_c46, v_c44})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex178, std::array<u64,2>{v_c44, v_c48})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex179, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex180, mbranchdelta188, std::array<u64,5>{v_c48, v_c46, v_c45, v_c50, 0}, [&](const std::array<u64,5>& m232) {
            u64 v_c53 = m232[4];
            if (!slog::exists_probe<3,2>(mp_unionindex181, std::array<u64,3>{v_c43, v_c53, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex182, mbranchdelta189, std::array<u64,5>{v_c49, v_c47, v_c51, v_c2, 0}, [&](const std::array<u64,5>& m233) {
              u64 v_c54 = m233[4];
              slog::join_probe_old<3,3>(mp_unionindex183, mp_uniondelta190, std::array<u64,3>{v_c43, v_c53, v_c54}, [&](const std::array<u64,3>& m234) {
                slog::join_probe_old<3,3>(mp_mskindex184, mp_mskdelta191, std::array<u64,3>{v_c49, v_c46, v_c44}, [&](const std::array<u64,3>& m235) {
                  slog::join_probe<2,2>(mp_msk_ansindex185, std::array<u64,2>{v_c44, v_c48}, [&](const std::array<u64,2>& m236) {
                    slog::join_probe_old<3,2>(mp_unionindex186, mp_uniondelta192, std::array<u64,3>{v_c50, v_c54, 0}, [&](const std::array<u64,3>& m237) {
                      u64 v_c55 = m237[2];
                      slog::join_probe<2,1>(mp_union_ansindex187, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m238) {
                        u64 v_c56 = m238[1];
                        u64 v_c57 = _prim_band(db, v_c49, v_c46);
                        if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c58 = _prim_gt(db, v_c57, v_c42);
                        if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c58) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c43, v_c56, v_c45, v_c46, v_c48});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c46, v_c45, v_c56}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask193* _cont = new ReadTask193(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask193(db,b), false);
  // (crule (pre) (scan eval __t5crG665 __t4vms664 rho t) (body (exists lookup (2 0 1) 1 rho) (join $sup70016x33x0x0x0 (0 1 2 3) 3 __t5crG665 rho t x) (join ref (0 1) 2 __t4vms664 x) (join-old lookup (1 2 0) 2 (1 2 0) x rho __t03bu666) (join lookup_ans (0 1) 1 __t03bu666 __v0)) (head (emit eval_ans (0 1) __t5crG665 __v0)) interp.slog:34 #f)
  class ReadTask246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex240;  slog::Index** $sup70016x33x0x0x0index241;  slog::Index** refindex242;  slog::Index** lookupindex243;  slog::Index** lookup_ansindex244;  slog::Index** lookupdelta245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("eval_ans");
      head_index[0] = readrel248->getIndex(ord247, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord249({2, 0, 1});
      slog::Relation* readrel250 = db->getRelation("lookup");
      lookupindex240 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1, 2, 3});
      slog::Relation* readrel252 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0index241 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("ref");
      refindex242 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("lookup");
      lookupindex243 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 2, 0});
      slog::Relation* readrel258 = db->getRelation("lookup");
      lookupdelta245 = readrel258->getIndex(ord257, true);
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("lookup_ans");
      lookup_ansindex244 = readrel260->getIndex(ord259, false);
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<3,1>(lookupindex240, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<4,3>($sup70016x33x0x0x0index241, std::array<u64,4>{v_c59, v_c4, v_c36, 0}, [&](const std::array<u64,4>& m261) {
          u64 v_c0 = m261[3];
          slog::join_probe<2,2>(refindex242, std::array<u64,2>{v_c60, v_c0}, [&](const std::array<u64,2>& m262) {
            slog::join_probe_old<3,2>(lookupindex243, lookupdelta245, std::array<u64,3>{v_c0, v_c4, 0}, [&](const std::array<u64,3>& m263) {
              u64 v_c61 = m263[2];
              slog::join_probe<2,1>(lookup_ansindex244, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m264) {
                u64 v_c56 = m264[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c56}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask246* _cont = new ReadTask246(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask246(db,b), false);
  // (crule (pre (let __tconst62iD1347 const0122baa3ac55f1b433944eb1)) (scan temp7pkd2063 __t9o8A577) (body (join _enum (1 0) 1 __tconst62iD1347 __t2cB8574) (join boolval (1 0) 1 __t2cB8574 __t7CgS575)) (head (emit delta_ans (0 1) __t9o8A577 __t7CgS575)) interp.slog:118 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex265;  slog::Index** boolvalindex266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("delta_ans");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("temp7pkd2063");
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("_enum");
      _enumindex265 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 0});
      slog::Relation* readrel273 = db->getRelation("boolval");
      boolvalindex266 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        slog::join_probe<2,1>(_enumindex265, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m274) {
          u64 v_c64 = m274[1];
          slog::join_probe<2,1>(boolvalindex266, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m275) {
            u64 v_c65 = m275[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c65}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:temp7pkd2063", _fires);
  
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
  // (crule (pre (let _00024sqc4eJq915 const6b86b273ff34fce19d6b804e) (let _00024sqc7353916 const5feceb66ffc86f38d952786c) (let _00024sqc4F46917 const6b86b273ff34fce19d6b804e) (let _00024sqc6X6r918 const5feceb66ffc86f38d952786c) (let __trid8NVw1490 const3b05f339a47cf251e643e4dd) (let __trel54xq1491 constc8dd3fe14ad7db61de7362fc) (let __tcol3esC1492 constd4735e3a265e16eee03f5971)) (scan $sup70016x47x0x0x0 _00024seq0 __d0 rho t x xs) (body (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t8uts322) (join-old mp_put_ans (0 1) 1 (0 1) __t8uts322 __v0) (letp _00024sql9Vv7913 (aslst _00024seq0)) (let _00024sqn4An9914 (llen _00024sql9Vv7913)) (cmp ge _00024sqn4An9914 _00024sqc4eJq915) (letp chk9Un51910 (lref _00024sql9Vv7913 _00024sqc7353916)) (eq x chk9Un51910) (let _00024sqp6qIB919 (_0002d _00024sqn4An9914 _00024sqc6X6r918)) (let chk11Ny1911 (lslice _00024sql9Vv7913 _00024sqc4F46917 _00024sqp6qIB919)) (eq xs chk11Ny1911)) (head (tycheck t (accept seq) __trid8NVw1490 __trel54xq1491 __tcol3esC1492 (1 2 3 4 0)) (mkstruct extend_env (1 2 3 0) __3tRX1489 __v0 xs t)) interp.slog:48 #f)
  class ReadTask280 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex276;  slog::Index** mp_put_ansindex277;  slog::Index** mp_putdelta278;  slog::Index** mp_put_ansdelta279;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("extend_env");
      outer_rel = db->getRelation("$sup70016x47x0x0x0");
      std::vector<u16> ord281({1, 2, 3, 0});
      slog::Relation* readrel282 = db->getRelation("mp_put");
      mp_putindex276 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 3, 0});
      slog::Relation* readrel284 = db->getRelation("mp_put");
      mp_putdelta278 = readrel284->getIndex(ord283, true);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_put_ans");
      mp_put_ansindex277 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("mp_put_ans");
      mp_put_ansdelta279 = readrel288->getIndex(ord287, true);
  
    }
    ReadTask280(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
      u64 v_c68 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_const3b05f339a47cf251e643e4dd;
      u64 v_c71 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c72 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c74 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c0 = _t[4];
        u64 v_c75 = _t[5];
        slog::join_probe_old<4,3>(mp_putindex276, mp_putdelta278, std::array<u64,4>{v_c4, v_c0, v_c36, 0}, [&](const std::array<u64,4>& m289) {
          u64 v_c76 = m289[3];
          slog::join_probe_old<2,1>(mp_put_ansindex277, mp_put_ansdelta279, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m290) {
            u64 v_c56 = m290[1];
            bool ok291 = true;
            u64 v_c77 = _prim_aslst(db, v_c73, &ok291);
            if (!ok291) return;
            u64 v_c78 = _prim_llen(db, v_c77);
            if (v_c78 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c79 = _prim_ge(db, v_c78, v_c66);
            if (v_c79 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (!v_c79) return;
            bool ok293 = true;
            u64 v_c80 = _prim_lref(db, v_c77, v_c67, &ok293);
            if (!ok293) return;
            if (v_c0 != v_c80) return;
            u64 v_c81 = _prim__0002d(db, v_c78, v_c69);
            if (v_c81 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c82 = _prim_lslice(db, v_c77, v_c68, v_c81);
            if (v_c82 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (v_c75 != v_c82) return;
            ++_fires;
            if (!(is_seq(v_c36)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c70, v_c71, v_c72, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c56, v_c75, v_c36}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:$sup70016x47x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask280* _cont = new ReadTask280(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask280(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t81Rn328 l k) (body (exists $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (join $sup5638x60x0x0x0 (1 2 0 3 4 5) 2 k l __t6Aa9325 m p r) (exists mp_has0 (0 2 1) 2 __t6Aa9325 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t0WBy324) (join mp_has0 (0 2 1) 3 __t6Aa9325 k __t0WBy324) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2ONI329) (join mp_msk_ans (0 1) 2 __t2ONI329 p) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index294;  slog::Index** mbranchindex295;  slog::Index** mp_has0index296;  slog::Index** mp_mskindex297;  slog::Index** mp_has0_ansindex298;  slog::Index** $sup5638x60x0x0x0index299;  slog::Index** mp_has0index300;  slog::Index** mp_mskindex301;  slog::Index** mp_msk_ansindex302;  slog::Index** mbranchindex303;  slog::Index** mp_has0index304;  slog::Index** mp_mskindex305;  slog::Index** mp_msk_ansindex306;  slog::Index** mp_mskdelta307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel310->getIndex(ord309, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord311({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel312 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index294 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({3, 0, 1, 2, 4});
      slog::Relation* readrel314 = db->getRelation("mbranch");
      mbranchindex295 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({2, 0, 1});
      slog::Relation* readrel316 = db->getRelation("mp_has0");
      mp_has0index296 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("mp_msk");
      mp_mskindex297 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex298 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel322 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index299 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({0, 2, 1});
      slog::Relation* readrel324 = db->getRelation("mp_has0");
      mp_has0index300 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("mp_msk");
      mp_mskindex301 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 0});
      slog::Relation* readrel328 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex302 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 3, 4, 0});
      slog::Relation* readrel330 = db->getRelation("mbranch");
      mbranchindex303 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 2, 1});
      slog::Relation* readrel332 = db->getRelation("mp_has0");
      mp_has0index304 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 0});
      slog::Relation* readrel334 = db->getRelation("mp_msk");
      mp_mskindex305 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 2, 0});
      slog::Relation* readrel336 = db->getRelation("mp_msk");
      mp_mskdelta307 = readrel336->getIndex(ord335, true);
      std::vector<u16> ord337({0, 1});
      slog::Relation* readrel338 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex306 = readrel338->getIndex(ord337, false);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c85 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x60x0x0x0index294, std::array<u64,6>{v_c85, v_c45, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex295, std::array<u64,5>{v_c45, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index296, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex297, std::array<u64,3>{v_c85, 0, 0})) return;
        slog::join_probe<2,1>(mp_has0_ansindex298, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m339) {
          u64 v_c86 = m339[1];
          slog::join_probe<6,2>($sup5638x60x0x0x0index299, std::array<u64,6>{v_c85, v_c45, 0, 0, 0, 0}, [&](const std::array<u64,6>& m340) {
            u64 v_c87 = m340[2]; u64 v_c46 = m340[3]; u64 v_c48 = m340[4]; u64 v_c50 = m340[5];
            if (!slog::exists_probe<3,2>(mp_has0index300, std::array<u64,3>{v_c87, v_c85, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex301, std::array<u64,3>{v_c85, v_c46, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex302, std::array<u64,2>{v_c48, 0})) return;
            slog::join_probe<5,4>(mbranchindex303, std::array<u64,5>{v_c48, v_c46, v_c45, v_c50, 0}, [&](const std::array<u64,5>& m341) {
              u64 v_c88 = m341[4];
              slog::join_probe<3,3>(mp_has0index304, std::array<u64,3>{v_c87, v_c85, v_c88}, [&](const std::array<u64,3>& m342) {
                slog::join_probe_old<3,2>(mp_mskindex305, mp_mskdelta307, std::array<u64,3>{v_c85, v_c46, 0}, [&](const std::array<u64,3>& m343) {
                  u64 v_c89 = m343[2];
                  slog::join_probe<2,2>(mp_msk_ansindex306, std::array<u64,2>{v_c89, v_c48}, [&](const std::array<u64,2>& m344) {
                    u64 v_c90 = _prim_band(db, v_c85, v_c46);
                    if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c91 = _prim_lt(db, v_c90, v_c83);
                    if (v_c91 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c91) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c86}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre5oey1749 __errf4liB1750 __errf96jX1751) (body) (head (emit error (0) __erre5oey1749)) <internal>:1 #f)
  class ReadTask346 : public slog::Task
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
      std::vector<u16> ord347({0});
      slog::Relation* readrel348 = db->getRelation("error");
      head_index[0] = readrel348->getIndex(ord347, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask346(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c92 = _t[0];
        u64 v_c93 = _t[1];
        u64 v_c94 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c92}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask346* _cont = new ReadTask346(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask346(db,b), false);
  // (crule (pre) (scan mp_get_ans __t0Izo363 tx) (body (join-old store (1 0 2) 1 (1 0 2) tx x v) (exists lookup (1 2 0) 1 x) (join-old mp_get (0 2 1) 2 (0 2 1) __t0Izo363 x rho) (join-old lookup (1 2 0) 2 (1 2 0) x rho __t95yV362)) (head (emit lookup_ans (0 1) __t95yV362 v)) interp.slog:39 #f)
  class ReadTask356 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex349;  slog::Index** lookupindex350;  slog::Index** mp_getindex351;  slog::Index** lookupindex352;  slog::Index** storedelta353;  slog::Index** mp_getdelta354;  slog::Index** lookupdelta355;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("lookup_ans");
      head_index[0] = readrel358->getIndex(ord357, false);
      outer_rel = db->getRelation("mp_get_ans");
      std::vector<u16> ord359({1, 0, 2});
      slog::Relation* readrel360 = db->getRelation("store");
      storeindex349 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 0, 2});
      slog::Relation* readrel362 = db->getRelation("store");
      storedelta353 = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("lookup");
      lookupindex350 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 2, 1});
      slog::Relation* readrel366 = db->getRelation("mp_get");
      mp_getindex351 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 2, 1});
      slog::Relation* readrel368 = db->getRelation("mp_get");
      mp_getdelta354 = readrel368->getIndex(ord367, true);
      std::vector<u16> ord369({1, 2, 0});
      slog::Relation* readrel370 = db->getRelation("lookup");
      lookupindex352 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 2, 0});
      slog::Relation* readrel372 = db->getRelation("lookup");
      lookupdelta355 = readrel372->getIndex(ord371, true);
  
    }
    ReadTask356(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(storeindex349, storedelta353, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m373) {
          u64 v_c0 = m373[1]; u64 v_c2 = m373[2];
          if (!slog::exists_probe<3,1>(lookupindex350, std::array<u64,3>{v_c0, 0, 0})) return;
          slog::join_probe_old<3,2>(mp_getindex351, mp_getdelta354, std::array<u64,3>{v_c3, v_c0, 0}, [&](const std::array<u64,3>& m374) {
            u64 v_c4 = m374[2];
            slog::join_probe_old<3,2>(lookupindex352, lookupdelta355, std::array<u64,3>{v_c0, v_c4, 0}, [&](const std::array<u64,3>& m375) {
              u64 v_c5 = m375[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:mp_get_ans", _fires);
  
      if (!_done)
      {
        ReadTask356* _cont = new ReadTask356(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask356(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_msk __t4ZDq788 p0 __v1) (body (exists mp_hsb_ans (1 0) 1 __v1) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x29x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join mp_msk_ans (0 1) 1 __t4ZDq788 __v2) (join mp_hsb_ans (1 0) 1 __v1 __t8x7Q785) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t8x7Q785) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t8x7Q785) (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v3) (join $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t8x7Q785 __v1 __v3 p0 __t7O3e781 dup6QI21998 dup4FCe1999 __v0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join mp_hsb_ans (0 1) 2 __t8x7Q785 __v0) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask395 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex376;  slog::Index** $sup5638x29x0x0x2index377;  slog::Index** $sup5638x29x0x0x1index378;  slog::Index** $sup5638x29x0x0x0index379;  slog::Index** mp_joinindex380;  slog::Index** mp_msk_ansindex381;  slog::Index** mp_hsb_ansindex382;  slog::Index** $sup5638x29x0x0x2index383;  slog::Index** $sup5638x29x0x0x1index384;  slog::Index** mp_hsb_ansindex385;  slog::Index** mp_hsb_ansindex386;  slog::Index** $sup5638x29x0x0x2index387;  slog::Index** $sup5638x29x0x0x1index388;  slog::Index** $sup5638x29x0x0x0index389;  slog::Index** mp_joinindex390;  slog::Index** mp_hsb_ansindex391;  slog::Index** mp_hsbindex392;  slog::Index** mp_joindelta393;  slog::Index** mp_hsbdelta394;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex376 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel399 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index377 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel401 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index378 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0, 2, 3, 4});
      slog::Relation* readrel403 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index379 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 3, 4, 0});
      slog::Relation* readrel405 = db->getRelation("mp_join");
      mp_joinindex380 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex381 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex382 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel411 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index383 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel413 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index384 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex385 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex386 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel419 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index387 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel421 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index388 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 0, 2, 3, 4});
      slog::Relation* readrel423 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index389 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 3, 4, 0});
      slog::Relation* readrel425 = db->getRelation("mp_join");
      mp_joinindex390 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 3, 4, 0});
      slog::Relation* readrel427 = db->getRelation("mp_join");
      mp_joindelta393 = readrel427->getIndex(ord426, true);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex391 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("mp_hsb");
      mp_hsbindex392 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 1});
      slog::Relation* readrel433 = db->getRelation("mp_hsb");
      mp_hsbdelta394 = readrel433->getIndex(ord432, true);
  
    }
    ReadTask395(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c98 = _t[2];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex376, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index377, std::array<u64,11>{v_c98, v_c97, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index378, std::array<u64,7>{v_c97, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup5638x29x0x0x0index379, std::array<u64,5>{v_c97, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex380, std::array<u64,5>{v_c97, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex381, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m434) {
          u64 v_c99 = m434[1];
          slog::join_probe<2,1>(mp_hsb_ansindex382, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m435) {
            u64 v_c100 = m435[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index383, std::array<u64,11>{v_c98, v_c97, v_c100, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index384, std::array<u64,7>{v_c97, v_c100, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex385, std::array<u64,2>{v_c100, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex386, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m436) {
              u64 v_c101 = m436[1];
              slog::join_probe<11,4>($sup5638x29x0x0x2index387, std::array<u64,11>{v_c100, v_c98, v_c101, v_c97, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m437) {
                u64 v_c102 = m437[4]; u64 v_c103 = m437[5]; u64 v_c104 = m437[6]; u64 v_c56 = m437[7]; u64 v_c105 = m437[8]; u64 v_c106 = m437[9]; u64 v_c107 = m437[10];
                if (v_c100 != v_c104) return;
                if (v_c100 != v_c103) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index388, std::array<u64,7>{v_c102, v_c97, v_c105, v_c106, v_c107, v_c100, v_c56}, [&](const std::array<u64,7>& m438) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index389, std::array<u64,5>{v_c97, v_c102, v_c105, v_c106, v_c107}, [&](const std::array<u64,5>& m439) {
                    slog::join_probe_old<5,5>(mp_joinindex390, mp_joindelta393, std::array<u64,5>{v_c97, v_c106, v_c105, v_c107, v_c102}, [&](const std::array<u64,5>& m440) {
                      slog::join_probe<2,2>(mp_hsb_ansindex391, std::array<u64,2>{v_c100, v_c56}, [&](const std::array<u64,2>& m441) {
                        u64 v_c108 = _prim_bxor(db, v_c97, v_c105);
                        if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex392, mp_hsbdelta394, std::array<u64,2>{v_c100, v_c108}, [&](const std::array<u64,2>& m442) {
                          u64 v_c109 = _prim_band(db, v_c97, v_c56);
                          if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c110 = _prim_gt(db, v_c109, v_c95);
                          if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c110) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c99, v_c101, v_c106, v_c107});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c99, v_c101, v_c107, v_c106}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask395* _cont = new ReadTask395(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask395(db,b), false);
  // (crule (pre) (scan mp_put_ans __t3Rle816 __v0) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t3Rle816 x rho t) (exists eval (2 3 0 1) 2 rho t) (join $sup70016x92x0x0x0 (3 4 5 0 1 2) 3 rho t x __d0 eb er) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho t __t7uXV815) (join eval_ans (0 1) 1 __t7uXV815 vr)) (head (emit $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) __t7uXV815 vr __d0 __t3Rle816 __v0 eb er rho t x)) interp.slog:93 #f)
  class ReadTask451 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex444;  slog::Index** evalindex445;  slog::Index** $sup70016x92x0x0x0index446;  slog::Index** evalindex447;  slog::Index** eval_ansindex448;  slog::Index** mp_putdelta449;  slog::Index** evaldelta450;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord452({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel453 = db->getRelation("$sup70016x92x0x0x1");
      head_index[0] = readrel453->getIndex(ord452, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord454({0, 2, 1, 3});
      slog::Relation* readrel455 = db->getRelation("mp_put");
      mp_putindex444 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 2, 1, 3});
      slog::Relation* readrel457 = db->getRelation("mp_put");
      mp_putdelta449 = readrel457->getIndex(ord456, true);
      std::vector<u16> ord458({2, 3, 0, 1});
      slog::Relation* readrel459 = db->getRelation("eval");
      evalindex445 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel461 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index446 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 3, 0});
      slog::Relation* readrel463 = db->getRelation("eval");
      evalindex447 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 3, 0});
      slog::Relation* readrel465 = db->getRelation("eval");
      evaldelta450 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("eval_ans");
      eval_ansindex448 = readrel467->getIndex(ord466, false);
  
    }
    ReadTask451(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex444, mp_putdelta449, std::array<u64,4>{v_c111, 0, 0, 0}, [&](const std::array<u64,4>& m468) {
          u64 v_c0 = m468[1]; u64 v_c4 = m468[2]; u64 v_c36 = m468[3];
          if (!slog::exists_probe<4,2>(evalindex445, std::array<u64,4>{v_c4, v_c36, 0, 0})) return;
          slog::join_probe<6,3>($sup70016x92x0x0x0index446, std::array<u64,6>{v_c4, v_c36, v_c0, 0, 0, 0}, [&](const std::array<u64,6>& m469) {
            u64 v_c74 = m469[3]; u64 v_c34 = m469[4]; u64 v_c33 = m469[5];
            slog::join_probe_old<4,3>(evalindex447, evaldelta450, std::array<u64,4>{v_c33, v_c4, v_c36, 0}, [&](const std::array<u64,4>& m470) {
              u64 v_c112 = m470[3];
              slog::join_probe<2,1>(eval_ansindex448, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m471) {
                u64 v_c41 = m471[1];
                ++_fires;
                slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c112, v_c41, v_c74, v_c111, v_c56, v_c34, v_c33, v_c4, v_c36, v_c0}, std::array<u16,10>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask451* _cont = new ReadTask451(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask451(db,b), false);
  // (crule (pre) (scan store x tx v) (body (join-old lookup (1 2 0) 1 (1 2 0) x rho __t58t3572)) (head (mkstruct mp_get (1 2 0) __37aV1208 rho x)) interp.slog:39 #f)
  class ReadTask474 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex472;  slog::Index** lookupdelta473;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get");
      outer_rel = db->getRelation("store");
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("lookup");
      lookupindex472 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0});
      slog::Relation* readrel478 = db->getRelation("lookup");
      lookupdelta473 = readrel478->getIndex(ord477, true);
  
    }
    ReadTask474(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(lookupindex472, lookupdelta473, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m479) {
          u64 v_c4 = m479[1]; u64 v_c113 = m479[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c0}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask474* _cont = new ReadTask474(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask474(db,b), false);
  // (crule (pre (let __tconst3VAm410 const5feceb66ffc86f38d952786c)) (scan mbranch __t7895408 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t7895408 __t7ecR407 __t6JnF409) (join mbranch (0 1 2 3 4) 1 __t7ecR407 q n u v) (cmp lt n m) (let __t8deh411 (band q m)) (cmp gt __t8deh411 __tconst3VAm410)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t6JnF409 r l m n p q u v)) map.slog:99 #f)
  class ReadTask483 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex480;  slog::Index** mbranchindex481;  slog::Index** mp_uniondelta482;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord484({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel485 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel485->getIndex(ord484, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord486({1, 2, 0});
      slog::Relation* readrel487 = db->getRelation("mp_union");
      mp_unionindex480 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("mp_union");
      mp_uniondelta482 = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({0, 1, 2, 3, 4});
      slog::Relation* readrel491 = db->getRelation("mbranch");
      mbranchindex481 = readrel491->getIndex(ord490, false);
  
    }
    ReadTask483(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c115 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c46 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c50 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex480, mp_uniondelta482, std::array<u64,3>{v_c115, 0, 0}, [&](const std::array<u64,3>& m492) {
          u64 v_c116 = m492[1]; u64 v_c117 = m492[2];
          slog::join_probe<5,1>(mbranchindex481, std::array<u64,5>{v_c116, 0, 0, 0, 0}, [&](const std::array<u64,5>& m493) {
            u64 v_c49 = m493[1]; u64 v_c47 = m493[2]; u64 v_c51 = m493[3]; u64 v_c2 = m493[4];
            u64 v_c118 = _prim_lt(db, v_c47, v_c46);
            if (v_c118 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c118) return;
            u64 v_c119 = _prim_band(db, v_c49, v_c46);
            if (v_c119 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c120 = _prim_gt(db, v_c119, v_c114);
            if (v_c120 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c120) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c117, v_c50, v_c45, v_c46, v_c47, v_c48, v_c49, v_c51, v_c2}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask483* _cont = new ReadTask483(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask483(db,b), false);
  // (crule (pre) (scan eval_ans __t7GLg670 vr) (body (exists $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) 2 __t7GLg670 vr) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t7GLg670 er rho t) (exists $sup70016x92x0x0x0 (2 3 4 0 1 5) 3 er rho t) (exists mp_put (1 3 0 2) 2 rho t) (exists let (2 0 1 3) 1 er) (exists eval (2 3 0 1) 2 rho t) (exists eval (3 1 0 2) 1 t) (join-old $sup70016x92x0x0x1 (1 5 6 7 8 0 2 3 4 9) 5 (1 5 6 7 8 0 2 3 4 9) __t7GLg670 er rho t vr __t5vg0669 __t0mp6672 __v0 eb x) (join-old $sup70016x92x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t5vg0669 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval (1 2 3 0) 3 eb __v0 t) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join-old let (1 2 3 0) 3 (1 2 3 0) x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join-old mp_put_ans (0 1) 2 (0 1) __t0mp6672 __v0) (join-old eval_ans (0 1) 1 (0 1) __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask523 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index496;  slog::Index** evalindex497;  slog::Index** $sup70016x92x0x0x0index498;  slog::Index** mp_putindex499;  slog::Index** letindex500;  slog::Index** evalindex501;  slog::Index** evalindex502;  slog::Index** $sup70016x92x0x0x1index503;  slog::Index** $sup70016x92x0x0x0index504;  slog::Index** mp_putindex505;  slog::Index** evalindex506;  slog::Index** evalindex507;  slog::Index** mp_put_ansindex508;  slog::Index** letindex509;  slog::Index** evalindex510;  slog::Index** evalindex511;  slog::Index** mp_put_ansindex512;  slog::Index** eval_ansindex513;  slog::Index** evaldelta514;  slog::Index** $sup70016x92x0x0x1delta515;  slog::Index** $sup70016x92x0x0x0delta516;  slog::Index** mp_putdelta517;  slog::Index** letdelta518;  slog::Index** evaldelta519;  slog::Index** evaldelta520;  slog::Index** mp_put_ansdelta521;  slog::Index** eval_ansdelta522;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord524({0, 1});
      slog::Relation* readrel525 = db->getRelation("eval_ans");
      head_index[0] = readrel525->getIndex(ord524, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord526({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel527 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index496 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2, 3});
      slog::Relation* readrel529 = db->getRelation("eval");
      evalindex497 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 1, 2, 3});
      slog::Relation* readrel531 = db->getRelation("eval");
      evaldelta514 = readrel531->getIndex(ord530, true);
      std::vector<u16> ord532({2, 3, 4, 0, 1, 5});
      slog::Relation* readrel533 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index498 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 3, 0, 2});
      slog::Relation* readrel535 = db->getRelation("mp_put");
      mp_putindex499 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({2, 0, 1, 3});
      slog::Relation* readrel537 = db->getRelation("let");
      letindex500 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({2, 3, 0, 1});
      slog::Relation* readrel539 = db->getRelation("eval");
      evalindex501 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({3, 1, 0, 2});
      slog::Relation* readrel541 = db->getRelation("eval");
      evalindex502 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 5, 6, 7, 8, 0, 2, 3, 4, 9});
      slog::Relation* readrel543 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index503 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 5, 6, 7, 8, 0, 2, 3, 4, 9});
      slog::Relation* readrel545 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1delta515 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel547 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index504 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel549 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0delta516 = readrel549->getIndex(ord548, true);
      std::vector<u16> ord550({0, 2, 1, 3});
      slog::Relation* readrel551 = db->getRelation("mp_put");
      mp_putindex505 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({0, 2, 1, 3});
      slog::Relation* readrel553 = db->getRelation("mp_put");
      mp_putdelta517 = readrel553->getIndex(ord552, true);
      std::vector<u16> ord554({2, 3, 0, 1});
      slog::Relation* readrel555 = db->getRelation("eval");
      evalindex506 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 3, 0});
      slog::Relation* readrel557 = db->getRelation("eval");
      evalindex507 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({0, 1});
      slog::Relation* readrel559 = db->getRelation("mp_put_ans");
      mp_put_ansindex508 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 3, 0});
      slog::Relation* readrel561 = db->getRelation("let");
      letindex509 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 3, 0});
      slog::Relation* readrel563 = db->getRelation("let");
      letdelta518 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({2, 3, 0, 1});
      slog::Relation* readrel565 = db->getRelation("eval");
      evalindex510 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({2, 3, 0, 1});
      slog::Relation* readrel567 = db->getRelation("eval");
      evaldelta519 = readrel567->getIndex(ord566, true);
      std::vector<u16> ord568({1, 2, 3, 0});
      slog::Relation* readrel569 = db->getRelation("eval");
      evalindex511 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 3, 0});
      slog::Relation* readrel571 = db->getRelation("eval");
      evaldelta520 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("mp_put_ans");
      mp_put_ansindex512 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({0, 1});
      slog::Relation* readrel575 = db->getRelation("mp_put_ans");
      mp_put_ansdelta521 = readrel575->getIndex(ord574, true);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("eval_ans");
      eval_ansindex513 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0, 1});
      slog::Relation* readrel579 = db->getRelation("eval_ans");
      eval_ansdelta522 = readrel579->getIndex(ord578, true);
  
    }
    ReadTask523(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[1];
        if (!slog::exists_probe<10,2>($sup70016x92x0x0x1index496, std::array<u64,10>{v_c121, v_c41, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(evalindex497, evaldelta514, std::array<u64,4>{v_c121, 0, 0, 0}, [&](const std::array<u64,4>& m580) {
          u64 v_c33 = m580[1]; u64 v_c4 = m580[2]; u64 v_c36 = m580[3];
          if (!slog::exists_probe<6,3>($sup70016x92x0x0x0index498, std::array<u64,6>{v_c33, v_c4, v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex499, std::array<u64,4>{v_c4, v_c36, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letindex500, std::array<u64,4>{v_c33, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex501, std::array<u64,4>{v_c4, v_c36, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex502, std::array<u64,4>{v_c36, 0, 0, 0})) return;
          slog::join_probe_old<10,5>($sup70016x92x0x0x1index503, $sup70016x92x0x0x1delta515, std::array<u64,10>{v_c121, v_c33, v_c4, v_c36, v_c41, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m581) {
            u64 v_c122 = m581[5]; u64 v_c123 = m581[6]; u64 v_c56 = m581[7]; u64 v_c34 = m581[8]; u64 v_c0 = m581[9];
            slog::join_probe_old<6,6>($sup70016x92x0x0x0index504, $sup70016x92x0x0x0delta516, std::array<u64,6>{v_c122, v_c4, v_c36, v_c34, v_c33, v_c0}, [&](const std::array<u64,6>& m582) {
              slog::join_probe_old<4,4>(mp_putindex505, mp_putdelta517, std::array<u64,4>{v_c123, v_c0, v_c4, v_c36}, [&](const std::array<u64,4>& m583) {
                if (!slog::exists_probe<4,3>(evalindex506, std::array<u64,4>{v_c4, v_c36, v_c122, 0})) return;
                if (!slog::exists_probe<4,3>(evalindex507, std::array<u64,4>{v_c34, v_c56, v_c36, 0})) return;
                if (!slog::exists_probe<2,2>(mp_put_ansindex508, std::array<u64,2>{v_c123, v_c56})) return;
                slog::join_probe_old<4,3>(letindex509, letdelta518, std::array<u64,4>{v_c0, v_c33, v_c34, 0}, [&](const std::array<u64,4>& m584) {
                  u64 v_c124 = m584[3];
                  slog::join_probe_old<4,4>(evalindex510, evaldelta519, std::array<u64,4>{v_c4, v_c36, v_c122, v_c124}, [&](const std::array<u64,4>& m585) {
                    slog::join_probe_old<4,3>(evalindex511, evaldelta520, std::array<u64,4>{v_c34, v_c56, v_c36, 0}, [&](const std::array<u64,4>& m586) {
                      u64 v_c125 = m586[3];
                      slog::join_probe_old<2,2>(mp_put_ansindex512, mp_put_ansdelta521, std::array<u64,2>{v_c123, v_c56}, [&](const std::array<u64,2>& m587) {
                        slog::join_probe_old<2,1>(eval_ansindex513, eval_ansdelta522, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m588) {
                          u64 v_c2 = m588[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c122, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask523* _cont = new ReadTask523(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask523(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan eval_ans __t4Pyv623 vr) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t4Pyv623 er rho2 t) (exists mp_put (3 0 2 1) 1 t) (exists eval (3 1 0 2) 1 t) (exists letrec (2 3 0 1) 1 er) (join-old mp_put_ans (1 0) 1 (1 0) rho2 __t5ODE624) (join-old mp_put (3 0 2 1) 2 (3 0 2 1) t __t5ODE624 x rho) (exists letrec (1 2 3 0) 2 x er) (join eval (2 3 0 1) 2 rho t __7yeU1057 __t4cK3622) (join-old letrec (0 1 2 3) 3 (0 1 2 3) __t4cK3622 x er eb)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask602 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex589;  slog::Index** mp_putindex590;  slog::Index** evalindex591;  slog::Index** letrecindex592;  slog::Index** mp_put_ansindex593;  slog::Index** mp_putindex594;  slog::Index** letrecindex595;  slog::Index** evalindex596;  slog::Index** letrecindex597;  slog::Index** evaldelta598;  slog::Index** mp_put_ansdelta599;  slog::Index** mp_putdelta600;  slog::Index** letrecdelta601;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord603({0, 1, 2});
      slog::Relation* readrel604 = db->getRelation("store");
      head_index[3] = readrel604->getIndex(ord603, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord605({0, 1, 2});
      slog::Relation* readrel606 = db->getRelation("binding_event");
      head_index[4] = readrel606->getIndex(ord605, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord607({0, 1, 2, 3});
      slog::Relation* readrel608 = db->getRelation("eval");
      evalindex589 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1, 2, 3});
      slog::Relation* readrel610 = db->getRelation("eval");
      evaldelta598 = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({3, 0, 2, 1});
      slog::Relation* readrel612 = db->getRelation("mp_put");
      mp_putindex590 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({3, 1, 0, 2});
      slog::Relation* readrel614 = db->getRelation("eval");
      evalindex591 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({2, 3, 0, 1});
      slog::Relation* readrel616 = db->getRelation("letrec");
      letrecindex592 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 0});
      slog::Relation* readrel618 = db->getRelation("mp_put_ans");
      mp_put_ansindex593 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0});
      slog::Relation* readrel620 = db->getRelation("mp_put_ans");
      mp_put_ansdelta599 = readrel620->getIndex(ord619, true);
      std::vector<u16> ord621({3, 0, 2, 1});
      slog::Relation* readrel622 = db->getRelation("mp_put");
      mp_putindex594 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({3, 0, 2, 1});
      slog::Relation* readrel624 = db->getRelation("mp_put");
      mp_putdelta600 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({1, 2, 3, 0});
      slog::Relation* readrel626 = db->getRelation("letrec");
      letrecindex595 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({2, 3, 0, 1});
      slog::Relation* readrel628 = db->getRelation("eval");
      evalindex596 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({0, 1, 2, 3});
      slog::Relation* readrel630 = db->getRelation("letrec");
      letrecindex597 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({0, 1, 2, 3});
      slog::Relation* readrel632 = db->getRelation("letrec");
      letrecdelta601 = readrel632->getIndex(ord631, true);
  
    }
    ReadTask602(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c127 = v_const52b5e20f559958f34e533431;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c130 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c131 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c132 = v_constd4735e3a265e16eee03f5971;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c133 = _t[0];
        u64 v_c41 = _t[1];
        slog::join_probe_old<4,1>(evalindex589, evaldelta598, std::array<u64,4>{v_c133, 0, 0, 0}, [&](const std::array<u64,4>& m633) {
          u64 v_c33 = m633[1]; u64 v_c38 = m633[2]; u64 v_c36 = m633[3];
          if (!slog::exists_probe<4,1>(mp_putindex590, std::array<u64,4>{v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex591, std::array<u64,4>{v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letrecindex592, std::array<u64,4>{v_c33, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_put_ansindex593, mp_put_ansdelta599, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m634) {
            u64 v_c134 = m634[1];
            slog::join_probe_old<4,2>(mp_putindex594, mp_putdelta600, std::array<u64,4>{v_c36, v_c134, 0, 0}, [&](const std::array<u64,4>& m635) {
              u64 v_c0 = m635[2]; u64 v_c4 = m635[3];
              if (!slog::exists_probe<4,2>(letrecindex595, std::array<u64,4>{v_c0, v_c33, 0, 0})) return;
              slog::join_probe<4,2>(evalindex596, std::array<u64,4>{v_c4, v_c36, 0, 0}, [&](const std::array<u64,4>& m636) {
                u64 v_c135 = m636[2]; u64 v_c136 = m636[3];
                slog::join_probe_old<4,3>(letrecindex597, letrecdelta601, std::array<u64,4>{v_c136, v_c0, v_c33, 0}, [&](const std::array<u64,4>& m637) {
                  u64 v_c34 = m637[3];
                  ++_fires;
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c126, v_c127, v_c128, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c126, v_c129, v_c130, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c126, v_c131, v_c132, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c0, v_c36, v_c41}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c0, v_c36, v_c36}, std::array<u16,3>{0, 1, 2});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask602* _cont = new ReadTask602(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask602(db,b), false);
  // (crule (pre) (scan $sup70016x87x0x0x0 __d0 e1 e2 e3 rho t) (body (exists select_branch (2 3 1 0) 2 e2 e3) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t5mTH630) (exists eval_ans (0 1) 1 __t5mTH630) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t4JBz631) (join-old eval_ans (0 1) 2 (0 1) __t5mTH630 __v0) (join-old select_branch_ans (0 1) 1 (0 1) __t4JBz631 __v1)) (head (mkstruct eval (1 2 3 0) __226z1519 __v1 rho t)) interp.slog:88 #f)
  class ReadTask648 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex638;  slog::Index** evalindex639;  slog::Index** eval_ansindex640;  slog::Index** select_branchindex641;  slog::Index** eval_ansindex642;  slog::Index** select_branch_ansindex643;  slog::Index** evaldelta644;  slog::Index** select_branchdelta645;  slog::Index** eval_ansdelta646;  slog::Index** select_branch_ansdelta647;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord649({2, 3, 1, 0});
      slog::Relation* readrel650 = db->getRelation("select_branch");
      select_branchindex638 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 2, 3, 0});
      slog::Relation* readrel652 = db->getRelation("eval");
      evalindex639 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 3, 0});
      slog::Relation* readrel654 = db->getRelation("eval");
      evaldelta644 = readrel654->getIndex(ord653, true);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("eval_ans");
      eval_ansindex640 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({2, 3, 1, 0});
      slog::Relation* readrel658 = db->getRelation("select_branch");
      select_branchindex641 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({2, 3, 1, 0});
      slog::Relation* readrel660 = db->getRelation("select_branch");
      select_branchdelta645 = readrel660->getIndex(ord659, true);
      std::vector<u16> ord661({0, 1});
      slog::Relation* readrel662 = db->getRelation("eval_ans");
      eval_ansindex642 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({0, 1});
      slog::Relation* readrel664 = db->getRelation("eval_ans");
      eval_ansdelta646 = readrel664->getIndex(ord663, true);
      std::vector<u16> ord665({0, 1});
      slog::Relation* readrel666 = db->getRelation("select_branch_ans");
      select_branch_ansindex643 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({0, 1});
      slog::Relation* readrel668 = db->getRelation("select_branch_ans");
      select_branch_ansdelta647 = readrel668->getIndex(ord667, true);
  
    }
    ReadTask648(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[1];
        u64 v_c138 = _t[2];
        u64 v_c139 = _t[3];
        u64 v_c4 = _t[4];
        u64 v_c36 = _t[5];
        if (!slog::exists_probe<4,2>(select_branchindex638, std::array<u64,4>{v_c138, v_c139, 0, 0})) return;
        slog::join_probe_old<4,3>(evalindex639, evaldelta644, std::array<u64,4>{v_c137, v_c4, v_c36, 0}, [&](const std::array<u64,4>& m669) {
          u64 v_c140 = m669[3];
          if (!slog::exists_probe<2,1>(eval_ansindex640, std::array<u64,2>{v_c140, 0})) return;
          slog::join_probe_old<4,2>(select_branchindex641, select_branchdelta645, std::array<u64,4>{v_c138, v_c139, 0, 0}, [&](const std::array<u64,4>& m670) {
            u64 v_c56 = m670[2]; u64 v_c141 = m670[3];
            slog::join_probe_old<2,2>(eval_ansindex642, eval_ansdelta646, std::array<u64,2>{v_c140, v_c56}, [&](const std::array<u64,2>& m671) {
              slog::join_probe_old<2,1>(select_branch_ansindex643, select_branch_ansdelta647, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m672) {
                u64 v_c98 = m672[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c98, v_c4, v_c36}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:$sup70016x87x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask648* _cont = new ReadTask648(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask648(db,b), false);
  // (crule (pre) (scan mp_put_soft_ans __t5GLK605 r) (body (join-old mp_put_soft (0 1 2 3) 1 (0 1 2 3) __t5GLK605 s k v) (exists mp_union (1 2 0) 1 s) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t5Ivz603) (join-old mp_union (1 2 0) 2 (1 2 0) s __t5Ivz603 __t7E2l604)) (head (emit mp_union_ans (0 1) __t7E2l604 r)) map.slog:93 #f)
  class ReadTask680 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex673;  slog::Index** mp_unionindex674;  slog::Index** mleafindex675;  slog::Index** mp_unionindex676;  slog::Index** mp_put_softdelta677;  slog::Index** mleafdelta678;  slog::Index** mp_uniondelta679;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord681({0, 1});
      slog::Relation* readrel682 = db->getRelation("mp_union_ans");
      head_index[0] = readrel682->getIndex(ord681, false);
      outer_rel = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord683({0, 1, 2, 3});
      slog::Relation* readrel684 = db->getRelation("mp_put_soft");
      mp_put_softindex673 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({0, 1, 2, 3});
      slog::Relation* readrel686 = db->getRelation("mp_put_soft");
      mp_put_softdelta677 = readrel686->getIndex(ord685, true);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("mp_union");
      mp_unionindex674 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("mleaf");
      mleafindex675 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 0});
      slog::Relation* readrel692 = db->getRelation("mleaf");
      mleafdelta678 = readrel692->getIndex(ord691, true);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("mp_union");
      mp_unionindex676 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 0});
      slog::Relation* readrel696 = db->getRelation("mp_union");
      mp_uniondelta679 = readrel696->getIndex(ord695, true);
  
    }
    ReadTask680(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c142 = _t[0];
        u64 v_c50 = _t[1];
        slog::join_probe_old<4,1>(mp_put_softindex673, mp_put_softdelta677, std::array<u64,4>{v_c142, 0, 0, 0}, [&](const std::array<u64,4>& m697) {
          u64 v_c143 = m697[1]; u64 v_c85 = m697[2]; u64 v_c2 = m697[3];
          if (!slog::exists_probe<3,1>(mp_unionindex674, std::array<u64,3>{v_c143, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex675, mleafdelta678, std::array<u64,3>{v_c85, v_c2, 0}, [&](const std::array<u64,3>& m698) {
            u64 v_c144 = m698[2];
            slog::join_probe_old<3,2>(mp_unionindex676, mp_uniondelta679, std::array<u64,3>{v_c143, v_c144, 0}, [&](const std::array<u64,3>& m699) {
              u64 v_c145 = m699[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c145, v_c50}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_put_soft_ans", _fires);
  
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
  // (crule (pre) (scan temp4pxV2035 __t2xRf793 __t7ZV0794) (body) (head (emit eval_args_ans (0 1) __t7ZV0794 __t2xRf793)) interp.slog:44 #f)
  class ReadTask700 : public slog::Task
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
      head_rel[0] = db->getRelation("eval_args_ans");
      std::vector<u16> ord701({0, 1});
      slog::Relation* readrel702 = db->getRelation("eval_args_ans");
      head_index[0] = readrel702->getIndex(ord701, false);
      outer_rel = db->getRelation("temp4pxV2035");
  
    }
    ReadTask700(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c147 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c147, v_c146}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:temp4pxV2035", _fires);
  
      if (!_done)
      {
        ReadTask700* _cont = new ReadTask700(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask700(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mbranch __t006N221 p m l r) (body (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 4 r l m p) (exists mp_union (1 2 0) 1 __t006N221) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 r) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 4 p l m r __t14N0222 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t14N0222 __t006N221) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t14N0222 n q u v __t4NVE225) (exists mp_msk (1 2 0) 3 q m __t4NVE225) (exists mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_union (0 1 2) 3 (0 1 2) __t14N0222 __t006N221 __t5FeR226) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask725 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index703;  slog::Index** mp_unionindex704;  slog::Index** mp_mskindex705;  slog::Index** mp_msk_ansindex706;  slog::Index** mp_unionindex707;  slog::Index** $sup5638x98x0x0x0index708;  slog::Index** mbranchindex709;  slog::Index** mp_unionindex710;  slog::Index** mp_mskindex711;  slog::Index** $sup5638x98x0x0x1index712;  slog::Index** mp_mskindex713;  slog::Index** mp_msk_ansindex714;  slog::Index** mbranchindex715;  slog::Index** mp_unionindex716;  slog::Index** mp_mskindex717;  slog::Index** mp_msk_ansindex718;  slog::Index** mp_unionindex719;  slog::Index** mp_union_ansindex720;  slog::Index** mbranchdelta721;  slog::Index** mp_uniondelta722;  slog::Index** mp_mskdelta723;  slog::Index** mp_uniondelta724;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord726({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel727 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index703 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({1, 2, 0});
      slog::Relation* readrel729 = db->getRelation("mp_union");
      mp_unionindex704 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({2, 0, 1});
      slog::Relation* readrel731 = db->getRelation("mp_msk");
      mp_mskindex705 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 0});
      slog::Relation* readrel733 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex706 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 2, 0});
      slog::Relation* readrel735 = db->getRelation("mp_union");
      mp_unionindex707 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel737 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index708 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 2, 3, 4, 0});
      slog::Relation* readrel739 = db->getRelation("mbranch");
      mbranchindex709 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({0, 1, 2});
      slog::Relation* readrel741 = db->getRelation("mp_union");
      mp_unionindex710 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("mp_msk");
      mp_mskindex711 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel745 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index712 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 0});
      slog::Relation* readrel747 = db->getRelation("mp_msk");
      mp_mskindex713 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({0, 1});
      slog::Relation* readrel749 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex714 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 3, 4, 0});
      slog::Relation* readrel751 = db->getRelation("mbranch");
      mbranchindex715 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 3, 4, 0});
      slog::Relation* readrel753 = db->getRelation("mbranch");
      mbranchdelta721 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({0, 1, 2});
      slog::Relation* readrel755 = db->getRelation("mp_union");
      mp_unionindex716 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("mp_union");
      mp_uniondelta722 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("mp_msk");
      mp_mskindex717 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 2, 0});
      slog::Relation* readrel761 = db->getRelation("mp_msk");
      mp_mskdelta723 = readrel761->getIndex(ord760, true);
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex718 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 0});
      slog::Relation* readrel765 = db->getRelation("mp_union");
      mp_unionindex719 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 0});
      slog::Relation* readrel767 = db->getRelation("mp_union");
      mp_uniondelta724 = readrel767->getIndex(ord766, true);
      std::vector<u16> ord768({0, 1});
      slog::Relation* readrel769 = db->getRelation("mp_union_ans");
      mp_union_ansindex720 = readrel769->getIndex(ord768, false);
  
    }
    ReadTask725(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c46 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c50 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x98x0x0x1index703, std::array<u64,10>{v_c50, v_c45, v_c46, v_c48, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex704, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex705, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex706, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex707, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x98x0x0x0index708, std::array<u64,9>{v_c48, v_c45, v_c46, v_c50, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m770) {
          u64 v_c43 = m770[4]; u64 v_c47 = m770[5]; u64 v_c49 = m770[6]; u64 v_c51 = m770[7]; u64 v_c2 = m770[8];
          u64 v_c148 = _prim_lt(db, v_c47, v_c46);
          if (v_c148 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c148) return;
          if (!slog::exists_probe<5,4>(mbranchindex709, std::array<u64,5>{v_c49, v_c47, v_c51, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex710, std::array<u64,3>{v_c43, v_c53, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex711, std::array<u64,3>{v_c49, v_c46, 0})) return;
          slog::join_probe<10,9>($sup5638x98x0x0x1index712, std::array<u64,10>{v_c50, v_c45, v_c46, v_c48, v_c43, v_c47, v_c49, v_c51, v_c2, 0}, [&](const std::array<u64,10>& m772) {
            u64 v_c44 = m772[9];
            if (!slog::exists_probe<3,3>(mp_mskindex713, std::array<u64,3>{v_c49, v_c46, v_c44})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex714, std::array<u64,2>{v_c44, v_c48})) return;
            slog::join_probe_old<5,4>(mbranchindex715, mbranchdelta721, std::array<u64,5>{v_c49, v_c47, v_c51, v_c2, 0}, [&](const std::array<u64,5>& m773) {
              u64 v_c54 = m773[4];
              slog::join_probe_old<3,3>(mp_unionindex716, mp_uniondelta722, std::array<u64,3>{v_c43, v_c53, v_c54}, [&](const std::array<u64,3>& m774) {
                slog::join_probe_old<3,3>(mp_mskindex717, mp_mskdelta723, std::array<u64,3>{v_c49, v_c46, v_c44}, [&](const std::array<u64,3>& m775) {
                  slog::join_probe<2,2>(mp_msk_ansindex718, std::array<u64,2>{v_c44, v_c48}, [&](const std::array<u64,2>& m776) {
                    slog::join_probe_old<3,2>(mp_unionindex719, mp_uniondelta724, std::array<u64,3>{v_c50, v_c54, 0}, [&](const std::array<u64,3>& m777) {
                      u64 v_c55 = m777[2];
                      slog::join_probe<2,1>(mp_union_ansindex720, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m778) {
                        u64 v_c56 = m778[1];
                        u64 v_c57 = _prim_band(db, v_c49, v_c46);
                        if (v_c57 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c149 = _prim_gt(db, v_c57, v_c42);
                        if (v_c149 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c149) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c43, v_c56, v_c45, v_c46, v_c48});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c46, v_c45, v_c56}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask725* _cont = new ReadTask725(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask725(db,b), false);
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo0BYf1046 __t7ye2598 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo05pe1044 __t7ye2598 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo5XjX1045 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9pUp1047 __t7ye2598 _00024seq2) (exists _enum (1 0) 1 __tconst8WcI1085) (join delta (1 2 0) 2 __tconst9cNI595 _00024seq2 __t0WVv596) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join symval (0 1) 1 __t7ye2598 s) (letp _00024sql2mO51039 (aslst _00024seq2)) (let chk4EqQ2024 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk4EqQ2024) (letp chk4TA62025 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (eq __t7ye2598 chk4TA62025) (letp chk06992026 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk06992026)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask788 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex780;  slog::Index** $seq_atindex781;  slog::Index** $seq_atrindex782;  slog::Index** _enumindex783;  slog::Index** deltaindex784;  slog::Index** _enumindex785;  slog::Index** symvalindex786;  slog::Index** $seq_atrdelta787;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord789({1, 0, 2});
      slog::Relation* readrel790 = db->getRelation("$seq_atr");
      driver_index = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({1, 0, 2});
      slog::Relation* readrel792 = db->getRelation("$seq_at");
      $seq_atindex780 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 0, 2});
      slog::Relation* readrel794 = db->getRelation("$seq_at");
      $seq_atindex781 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 0, 2});
      slog::Relation* readrel796 = db->getRelation("$seq_atr");
      $seq_atrindex782 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 0, 2});
      slog::Relation* readrel798 = db->getRelation("$seq_atr");
      $seq_atrdelta787 = readrel798->getIndex(ord797, true);
      std::vector<u16> ord799({1, 0});
      slog::Relation* readrel800 = db->getRelation("_enum");
      _enumindex783 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 2, 0});
      slog::Relation* readrel802 = db->getRelation("delta");
      deltaindex784 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 0});
      slog::Relation* readrel804 = db->getRelation("_enum");
      _enumindex785 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({0, 1});
      slog::Relation* readrel806 = db->getRelation("symval");
      symvalindex786 = readrel806->getIndex(ord805, false);
  
    }
    ReadTask788(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c150 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c151 = v_const06abaa100ecef791ce028c56;
      u64 v_c152 = v_constd4735e3a265e16eee03f5971;
      u64 v_c153 = v_const5feceb66ffc86f38d952786c;
      u64 v_c154 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c155 = v_const5feceb66ffc86f38d952786c;
      u64 v_c156 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c157 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c158 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c157, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m807) {
        u64 v_c159 = m807[1];
        u64 v_c23 = m807[2];
        if (buckethash(v_c159) != bucket) return;
        slog::join_probe<3,3>($seq_atindex780, std::array<u64,3>{v_c155, v_c159, v_c23}, [&](const std::array<u64,3>& m808) {
          slog::join_probe<3,3>($seq_atindex781, std::array<u64,3>{v_c156, v_c159, v_c23}, [&](const std::array<u64,3>& m809) {
            slog::join_probe_old<3,3>($seq_atrindex782, $seq_atrdelta787, std::array<u64,3>{v_c158, v_c159, v_c23}, [&](const std::array<u64,3>& m810) {
              if (!slog::exists_probe<2,1>(_enumindex783, std::array<u64,2>{v_c150, 0})) return;
              slog::join_probe<3,2>(deltaindex784, std::array<u64,3>{v_c151, v_c23, 0}, [&](const std::array<u64,3>& m811) {
                u64 v_c160 = m811[2];
                slog::join_probe<2,1>(_enumindex785, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m812) {
                  u64 v_c161 = m812[1];
                  slog::join_probe<2,1>(symvalindex786, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m813) {
                    u64 v_c143 = m813[1];
                    bool ok814 = true;
                    u64 v_c162 = _prim_aslst(db, v_c23, &ok814);
                    if (!ok814) return;
                    u64 v_c163 = _prim_llen(db, v_c162);
                    if (v_c163 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c152 != v_c163) return;
                    bool ok815 = true;
                    u64 v_c164 = _prim_lref(db, v_c162, v_c153, &ok815);
                    if (!ok815) return;
                    if (v_c159 != v_c164) return;
                    bool ok816 = true;
                    u64 v_c165 = _prim_lref(db, v_c162, v_c154, &ok816);
                    if (!ok816) return;
                    if (v_c159 != v_c165) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c160});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c161}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask788* _cont = new ReadTask788(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask788(db,b), false);
  // (crule (pre (let __tconst1W1K1304 constd01925b37634a1a9d24159d8)) (scan mp_bld __t4uJJ293 p m l r) (body (join _enum (1 0) 1 __tconst1W1K1304 __t4ABx294) (neq l __t4ABx294) (neq r __t4ABx294)) (head (emit-temp temp77vn1973 __t4uJJ293 l m p r) (mkstruct mbranch (1 2 3 4 0) __t2dgA292 p m l r)) map.slog:75 #f)
  class ReadTask818 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex817;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp77vn1973");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord819({1, 0});
      slog::Relation* readrel820 = db->getRelation("_enum");
      _enumindex817 = readrel820->getIndex(ord819, false);
  
    }
    ReadTask818(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c166 = v_constd01925b37634a1a9d24159d8;
  
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
        u64 v_c48 = _t[1];
        u64 v_c46 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c50 = _t[4];
        slog::join_probe<2,1>(_enumindex817, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m821) {
          u64 v_c168 = m821[1];
          if (v_c45 == v_c168) return;
          if (v_c50 == v_c168) return;
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c167, v_c45, v_c46, v_c48, v_c50});
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c46, v_c45, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:75", "delta:mp_bld", _fires);
  
      if (!_done)
      {
        ReadTask818* _cont = new ReadTask818(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask818(db,b), false);
  // (crule (pre (let __tconst81hP570 const5feceb66ffc86f38d952786c)) (scan mp_put __t05Ld569 __t01On568 k v) (body (join mbranch (0 1 2 3 4) 1 __t01On568 p m l r) (let __t62ag571 (band k m)) (cmp gt __t62ag571 __tconst81hP570)) (head (emit $sup5638x42x0x0x0 (4 2 3 5 0 1 6) p l m r __t05Ld569 k v)) map.slog:43 #f)
  class ReadTask823 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex822;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord824({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel825 = db->getRelation("$sup5638x42x0x0x0");
      head_index[0] = readrel825->getIndex(ord824, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord826({0, 1, 2, 3, 4});
      slog::Relation* readrel827 = db->getRelation("mbranch");
      mbranchindex822 = readrel827->getIndex(ord826, false);
  
    }
    ReadTask823(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c169 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c85 = _t[2];
        u64 v_c2 = _t[3];
        slog::join_probe<5,1>(mbranchindex822, std::array<u64,5>{v_c171, 0, 0, 0, 0}, [&](const std::array<u64,5>& m828) {
          u64 v_c48 = m828[1]; u64 v_c46 = m828[2]; u64 v_c45 = m828[3]; u64 v_c50 = m828[4];
          u64 v_c172 = _prim_band(db, v_c85, v_c46);
          if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          u64 v_c173 = _prim_gt(db, v_c172, v_c169);
          if (v_c173 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          if (!v_c173) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c48, v_c45, v_c46, v_c50, v_c170, v_c85, v_c2}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask823* _cont = new ReadTask823(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask823(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f) (let __tconst0hQe724 const6b86b273ff34fce19d6b804e) (let __tconst7lpr731 const0933fb667296882d8c45abca) (let __tconst9wm7741 const73475cb40a568e8da8a045ce) (let __tconst4vHk745 const5feceb66ffc86f38d952786c) (let __tconst1Nf0752 const90fb9068eda6f2d68bb61c33)) (scan temp775z1899 __t75NQ757 __t81pk743 __t8k6P758 __t8oLu750 __t9E2t720) (body (exists num (1 0) 1 __tconst4vHk745) (exists ref (1 0) 1 __tconst9wm7741) (exists primref (1 0) 1 __tconst7lpr731) (exists num (1 0) 1 __tconst0hQe724) (exists ref (1 0) 1 __tconst6I9K760) (join primref (1 0) 1 __tconst1Nf0752 __t6Asn753) (join num (1 0) 1 __tconst4vHk745 __t8vxv746) (join ref (1 0) 1 __tconst9wm7741 __t6TM2740) (join primref (1 0) 1 __tconst7lpr731 __t1nv4732) (join num (1 0) 1 __tconst0hQe724 __t8m96725) (join ref (1 0) 1 __tconst6I9K760 __t9NO9722) (let __t3uI9730 (lpush __t8oLu750 __t8m96725)) (let __t0esl751 (lpush __t8oLu750 __t8vxv746))) (head (emit-temp temp6vSW1900 __t0esl751 __t3uI9730 __t75NQ757 __t81pk743 __t8k6P758 __t9E2t720) (mkstruct app (1 2 0) __t5xOK723 __t9NO9722 __t9E2t720) (mkstruct lambda (1 2 0) __t2X4e744 __t81pk743 __t6TM2740)) kcfa.slog:70 #f)
  class ReadTask841 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex830;  slog::Index** refindex831;  slog::Index** primrefindex832;  slog::Index** numindex833;  slog::Index** refindex834;  slog::Index** primrefindex835;  slog::Index** numindex836;  slog::Index** refindex837;  slog::Index** primrefindex838;  slog::Index** numindex839;  slog::Index** refindex840;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6vSW1900");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp775z1899");
      std::vector<u16> ord842({1, 0});
      slog::Relation* readrel843 = db->getRelation("num");
      numindex830 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({1, 0});
      slog::Relation* readrel845 = db->getRelation("ref");
      refindex831 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 0});
      slog::Relation* readrel847 = db->getRelation("primref");
      primrefindex832 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 0});
      slog::Relation* readrel849 = db->getRelation("num");
      numindex833 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 0});
      slog::Relation* readrel851 = db->getRelation("ref");
      refindex834 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 0});
      slog::Relation* readrel853 = db->getRelation("primref");
      primrefindex835 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 0});
      slog::Relation* readrel855 = db->getRelation("num");
      numindex836 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 0});
      slog::Relation* readrel857 = db->getRelation("ref");
      refindex837 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 0});
      slog::Relation* readrel859 = db->getRelation("primref");
      primrefindex838 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 0});
      slog::Relation* readrel861 = db->getRelation("num");
      numindex839 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 0});
      slog::Relation* readrel863 = db->getRelation("ref");
      refindex840 = readrel863->getIndex(ord862, false);
  
    }
    ReadTask841(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_constd59eced1ded07f84c145592f;
      u64 v_c175 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c176 = v_const0933fb667296882d8c45abca;
      u64 v_c177 = v_const73475cb40a568e8da8a045ce;
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
      u64 v_c179 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c180 = _t[0];
        u64 v_c181 = _t[1];
        u64 v_c182 = _t[2];
        u64 v_c183 = _t[3];
        u64 v_c184 = _t[4];
        if (!slog::exists_probe<2,1>(numindex830, std::array<u64,2>{v_c178, 0})) return;
        if (!slog::exists_probe<2,1>(refindex831, std::array<u64,2>{v_c177, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex832, std::array<u64,2>{v_c176, 0})) return;
        if (!slog::exists_probe<2,1>(numindex833, std::array<u64,2>{v_c175, 0})) return;
        if (!slog::exists_probe<2,1>(refindex834, std::array<u64,2>{v_c174, 0})) return;
        slog::join_probe<2,1>(primrefindex835, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m864) {
          u64 v_c185 = m864[1];
          slog::join_probe<2,1>(numindex836, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m865) {
            u64 v_c186 = m865[1];
            slog::join_probe<2,1>(refindex837, std::array<u64,2>{v_c177, 0}, [&](const std::array<u64,2>& m866) {
              u64 v_c187 = m866[1];
              slog::join_probe<2,1>(primrefindex838, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m867) {
                u64 v_c188 = m867[1];
                slog::join_probe<2,1>(numindex839, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m868) {
                  u64 v_c189 = m868[1];
                  slog::join_probe<2,1>(refindex840, std::array<u64,2>{v_c174, 0}, [&](const std::array<u64,2>& m869) {
                    u64 v_c190 = m869[1];
                    u64 v_c191 = _prim_lpush(db, v_c183, v_c189);
                    if (v_c191 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                    u64 v_c192 = _prim_lpush(db, v_c183, v_c186);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c192, v_c191, v_c180, v_c181, v_c182, v_c184});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c190, v_c184}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c181, v_c187}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp775z1899", _fires);
  
      if (!_done)
      {
        ReadTask841* _cont = new ReadTask841(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask841(db,b), false);
  // (crule (pre) (scan mp_put __t0Rig361 rho x t) (body (exists $sup70016x95x0x0x0 (3 4 5 0 1 2) 3 rho t x) (exists letrec (1 2 3 0) 1 x) (exists eval (2 3 0 1) 2 rho t) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (0 1) 1 __t0Rig361) (join $sup70016x95x0x0x1 (1 4 6 7 0 2 3 5) 4 __t0Rig361 rho t x __t7DhJ358 eb er rho2) (join $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 __t7DhJ358 rho t eb er x) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists eval (1 2 3 0) 3 er rho2 t) (exists eval (1 2 3 0) 3 eb rho2 t) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join letrec (1 2 3 0) 3 x er eb __t0Sks357) (join eval (2 3 0 1) 4 rho t __t7DhJ358 __t0Sks357) (join eval (1 2 3 0) 3 er rho2 t __t6HuT359) (exists eval_ans (0 1) 1 __t6HuT359) (join eval (1 2 3 0) 3 eb rho2 t __t63JF360) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask890 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x0index870;  slog::Index** letrecindex871;  slog::Index** evalindex872;  slog::Index** evalindex873;  slog::Index** mp_put_ansindex874;  slog::Index** $sup70016x95x0x0x1index875;  slog::Index** $sup70016x95x0x0x0index876;  slog::Index** evalindex877;  slog::Index** evalindex878;  slog::Index** evalindex879;  slog::Index** mp_put_ansindex880;  slog::Index** letrecindex881;  slog::Index** evalindex882;  slog::Index** evalindex883;  slog::Index** eval_ansindex884;  slog::Index** evalindex885;  slog::Index** mp_put_ansindex886;  slog::Index** eval_ansindex887;  slog::Index** eval_ansindex888;  slog::Index** eval_ansindex889;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("eval_ans");
      head_index[0] = readrel892->getIndex(ord891, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord893({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel894 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index870 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({1, 2, 3, 0});
      slog::Relation* readrel896 = db->getRelation("letrec");
      letrecindex871 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({2, 3, 0, 1});
      slog::Relation* readrel898 = db->getRelation("eval");
      evalindex872 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({3, 1, 0, 2});
      slog::Relation* readrel900 = db->getRelation("eval");
      evalindex873 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({0, 1});
      slog::Relation* readrel902 = db->getRelation("mp_put_ans");
      mp_put_ansindex874 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel904 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index875 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel906 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index876 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({2, 3, 0, 1});
      slog::Relation* readrel908 = db->getRelation("eval");
      evalindex877 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({1, 2, 3, 0});
      slog::Relation* readrel910 = db->getRelation("eval");
      evalindex878 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({1, 2, 3, 0});
      slog::Relation* readrel912 = db->getRelation("eval");
      evalindex879 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({0, 1});
      slog::Relation* readrel914 = db->getRelation("mp_put_ans");
      mp_put_ansindex880 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 2, 3, 0});
      slog::Relation* readrel916 = db->getRelation("letrec");
      letrecindex881 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({2, 3, 0, 1});
      slog::Relation* readrel918 = db->getRelation("eval");
      evalindex882 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 2, 3, 0});
      slog::Relation* readrel920 = db->getRelation("eval");
      evalindex883 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("eval_ans");
      eval_ansindex884 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 2, 3, 0});
      slog::Relation* readrel924 = db->getRelation("eval");
      evalindex885 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 1});
      slog::Relation* readrel926 = db->getRelation("mp_put_ans");
      mp_put_ansindex886 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({0, 1});
      slog::Relation* readrel928 = db->getRelation("eval_ans");
      eval_ansindex887 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({0, 1});
      slog::Relation* readrel930 = db->getRelation("eval_ans");
      eval_ansindex888 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({0, 1});
      slog::Relation* readrel932 = db->getRelation("eval_ans");
      eval_ansindex889 = readrel932->getIndex(ord931, false);
  
    }
    ReadTask890(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c0 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<6,3>($sup70016x95x0x0x0index870, std::array<u64,6>{v_c4, v_c36, v_c0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex871, std::array<u64,4>{v_c0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex872, std::array<u64,4>{v_c4, v_c36, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex873, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex874, std::array<u64,2>{v_c37, 0})) return;
        slog::join_probe<8,4>($sup70016x95x0x0x1index875, std::array<u64,8>{v_c37, v_c4, v_c36, v_c0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m933) {
          u64 v_c35 = m933[4]; u64 v_c34 = m933[5]; u64 v_c33 = m933[6]; u64 v_c38 = m933[7];
          slog::join_probe<6,6>($sup70016x95x0x0x0index876, std::array<u64,6>{v_c35, v_c4, v_c36, v_c34, v_c33, v_c0}, [&](const std::array<u64,6>& m934) {
            if (!slog::exists_probe<4,3>(evalindex877, std::array<u64,4>{v_c4, v_c36, v_c35, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex878, std::array<u64,4>{v_c33, v_c38, v_c36, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex879, std::array<u64,4>{v_c34, v_c38, v_c36, 0})) return;
            if (!slog::exists_probe<2,2>(mp_put_ansindex880, std::array<u64,2>{v_c37, v_c38})) return;
            slog::join_probe<4,3>(letrecindex881, std::array<u64,4>{v_c0, v_c33, v_c34, 0}, [&](const std::array<u64,4>& m935) {
              u64 v_c32 = m935[3];
              slog::join_probe<4,4>(evalindex882, std::array<u64,4>{v_c4, v_c36, v_c35, v_c32}, [&](const std::array<u64,4>& m936) {
                slog::join_probe<4,3>(evalindex883, std::array<u64,4>{v_c33, v_c38, v_c36, 0}, [&](const std::array<u64,4>& m937) {
                  u64 v_c39 = m937[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex884, std::array<u64,2>{v_c39, 0})) return;
                  slog::join_probe<4,3>(evalindex885, std::array<u64,4>{v_c34, v_c38, v_c36, 0}, [&](const std::array<u64,4>& m938) {
                    u64 v_c40 = m938[3];
                    slog::join_probe<2,2>(mp_put_ansindex886, std::array<u64,2>{v_c37, v_c38}, [&](const std::array<u64,2>& m939) {
                      if (!slog::exists_probe<2,1>(eval_ansindex887, std::array<u64,2>{v_c40, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex888, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m940) {
                        u64 v_c41 = m940[1];
                        slog::join_probe<2,1>(eval_ansindex889, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m941) {
                          u64 v_c2 = m941[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask890* _cont = new ReadTask890(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask890(db,b), false);
  // (crule (pre (let __tconst43q5382 const5feceb66ffc86f38d952786c)) (scan mp_get_ans __t1KiE384 v) (body (join-old mp_get (0 2 1) 1 (0 2 1) __t1KiE384 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_get (2 0 1) 1 k) (join-old $sup5638x52x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t9K8V381 l m p) (exists mp_get (0 2 1) 2 __t9K8V381 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5bK8380) (join-old mp_get (0 2 1) 3 (0 2 1) __t9K8V381 k __t5bK8380) (let __t0f7P383 (band k m)) (cmp gt __t0f7P383 __tconst43q5382)) (head (emit mp_get_ans (0 1) __t9K8V381 v)) map.slog:53 #f)
  class ReadTask953 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex942;  slog::Index** mbranchindex943;  slog::Index** mp_getindex944;  slog::Index** $sup5638x52x0x0x0index945;  slog::Index** mp_getindex946;  slog::Index** mbranchindex947;  slog::Index** mp_getindex948;  slog::Index** mp_getdelta949;  slog::Index** $sup5638x52x0x0x0delta950;  slog::Index** mbranchdelta951;  slog::Index** mp_getdelta952;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("mp_get_ans");
      head_index[0] = readrel955->getIndex(ord954, false);
      outer_rel = db->getRelation("mp_get_ans");
      std::vector<u16> ord956({0, 2, 1});
      slog::Relation* readrel957 = db->getRelation("mp_get");
      mp_getindex942 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({0, 2, 1});
      slog::Relation* readrel959 = db->getRelation("mp_get");
      mp_getdelta949 = readrel959->getIndex(ord958, true);
      std::vector<u16> ord960({4, 0, 1, 2, 3});
      slog::Relation* readrel961 = db->getRelation("mbranch");
      mbranchindex943 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({2, 0, 1});
      slog::Relation* readrel963 = db->getRelation("mp_get");
      mp_getindex944 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel965 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index945 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel967 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0delta950 = readrel967->getIndex(ord966, true);
      std::vector<u16> ord968({0, 2, 1});
      slog::Relation* readrel969 = db->getRelation("mp_get");
      mp_getindex946 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 2, 3, 4, 0});
      slog::Relation* readrel971 = db->getRelation("mbranch");
      mbranchindex947 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({1, 2, 3, 4, 0});
      slog::Relation* readrel973 = db->getRelation("mbranch");
      mbranchdelta951 = readrel973->getIndex(ord972, true);
      std::vector<u16> ord974({0, 2, 1});
      slog::Relation* readrel975 = db->getRelation("mp_get");
      mp_getindex948 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({0, 2, 1});
      slog::Relation* readrel977 = db->getRelation("mp_get");
      mp_getdelta952 = readrel977->getIndex(ord976, true);
  
    }
    ReadTask953(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c193 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c194 = _t[0];
        u64 v_c2 = _t[1];
        slog::join_probe_old<3,1>(mp_getindex942, mp_getdelta949, std::array<u64,3>{v_c194, 0, 0}, [&](const std::array<u64,3>& m978) {
          u64 v_c85 = m978[1]; u64 v_c50 = m978[2];
          if (!slog::exists_probe<5,1>(mbranchindex943, std::array<u64,5>{v_c50, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_getindex944, std::array<u64,3>{v_c85, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x52x0x0x0index945, $sup5638x52x0x0x0delta950, std::array<u64,6>{v_c85, v_c50, 0, 0, 0, 0}, [&](const std::array<u64,6>& m979) {
            u64 v_c195 = m979[2]; u64 v_c45 = m979[3]; u64 v_c46 = m979[4]; u64 v_c48 = m979[5];
            if (!slog::exists_probe<3,2>(mp_getindex946, std::array<u64,3>{v_c195, v_c85, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex947, mbranchdelta951, std::array<u64,5>{v_c48, v_c46, v_c45, v_c50, 0}, [&](const std::array<u64,5>& m980) {
              u64 v_c196 = m980[4];
              slog::join_probe_old<3,3>(mp_getindex948, mp_getdelta952, std::array<u64,3>{v_c195, v_c85, v_c196}, [&](const std::array<u64,3>& m981) {
                u64 v_c197 = _prim_band(db, v_c85, v_c46);
                if (v_c197 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c198 = _prim_gt(db, v_c197, v_c193);
                if (v_c198 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c198) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c195, v_c2}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mp_get_ans", _fires);
  
      if (!_done)
      {
        ReadTask953* _cont = new ReadTask953(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask953(db,b), false);
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (scan mp_put_soft __t94M4525 t k v) (body (join $sup5638x68x0x0x0 (1 2 3 0) 4 k t v __t94M4525) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst25r1527) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t7U64528) (exists mp_put_ans (0 1) 1 __t7U64528) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t5miQ526) (join mp_has0_ans (0 1) 2 __t5miQ526 __tconst25r1527) (join mp_put_ans (0 1) 1 __t7U64528 r)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask993 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x68x0x0x0index983;  slog::Index** mp_has0index984;  slog::Index** mp_has0_ansindex985;  slog::Index** mp_putindex986;  slog::Index** mp_put_ansindex987;  slog::Index** mp_has0index988;  slog::Index** mp_has0_ansindex989;  slog::Index** mp_put_ansindex990;  slog::Index** mp_putdelta991;  slog::Index** mp_has0delta992;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord994({0, 1});
      slog::Relation* readrel995 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel995->getIndex(ord994, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord996({1, 2, 3, 0});
      slog::Relation* readrel997 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index983 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 2, 0});
      slog::Relation* readrel999 = db->getRelation("mp_has0");
      mp_has0index984 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 0});
      slog::Relation* readrel1001 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex985 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({1, 2, 3, 0});
      slog::Relation* readrel1003 = db->getRelation("mp_put");
      mp_putindex986 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({1, 2, 3, 0});
      slog::Relation* readrel1005 = db->getRelation("mp_put");
      mp_putdelta991 = readrel1005->getIndex(ord1004, true);
      std::vector<u16> ord1006({0, 1});
      slog::Relation* readrel1007 = db->getRelation("mp_put_ans");
      mp_put_ansindex987 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({1, 2, 0});
      slog::Relation* readrel1009 = db->getRelation("mp_has0");
      mp_has0index988 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({1, 2, 0});
      slog::Relation* readrel1011 = db->getRelation("mp_has0");
      mp_has0delta992 = readrel1011->getIndex(ord1010, true);
      std::vector<u16> ord1012({0, 1});
      slog::Relation* readrel1013 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex989 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({0, 1});
      slog::Relation* readrel1015 = db->getRelation("mp_put_ans");
      mp_put_ansindex990 = readrel1015->getIndex(ord1014, false);
  
    }
    ReadTask993(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c199 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c200 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c2 = _t[3];
        slog::join_probe<4,4>($sup5638x68x0x0x0index983, std::array<u64,4>{v_c85, v_c36, v_c2, v_c200}, [&](const std::array<u64,4>& m1016) {
          if (!slog::exists_probe<3,2>(mp_has0index984, std::array<u64,3>{v_c36, v_c85, 0})) return;
          if (!slog::exists_probe<2,1>(mp_has0_ansindex985, std::array<u64,2>{v_c199, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex986, mp_putdelta991, std::array<u64,4>{v_c36, v_c85, v_c2, 0}, [&](const std::array<u64,4>& m1017) {
            u64 v_c201 = m1017[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex987, std::array<u64,2>{v_c201, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index988, mp_has0delta992, std::array<u64,3>{v_c36, v_c85, 0}, [&](const std::array<u64,3>& m1018) {
              u64 v_c202 = m1018[2];
              slog::join_probe<2,2>(mp_has0_ansindex989, std::array<u64,2>{v_c202, v_c199}, [&](const std::array<u64,2>& m1019) {
                slog::join_probe<2,1>(mp_put_ansindex990, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1020) {
                  u64 v_c50 = m1020[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c200, v_c50}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask993* _cont = new ReadTask993(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask993(db,b), false);
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mp_msk __t9BfR236 k m) (body (exists $sup5638x62x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t9BfR236 p) (exists mbranch (1 2 3 4 0) 2 p m) (join $sup5638x62x0x0x0 (1 3 4 0 2 5) 3 k m p __t7cml232 l r) (exists mp_has0 (0 2 1) 2 __t7cml232 k) (exists mp_has0 (1 2 0) 2 r k) (join mbranch (1 2 3 4 0) 4 p m l r __t5gI3231) (join mp_has0 (0 2 1) 3 __t7cml232 k __t5gI3231) (join mp_has0 (1 2 0) 2 r k __t2sXu235) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask1033 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index1021;  slog::Index** mbranchindex1022;  slog::Index** mp_has0index1023;  slog::Index** mp_msk_ansindex1024;  slog::Index** mbranchindex1025;  slog::Index** $sup5638x62x0x0x0index1026;  slog::Index** mp_has0index1027;  slog::Index** mp_has0index1028;  slog::Index** mbranchindex1029;  slog::Index** mp_has0index1030;  slog::Index** mp_has0index1031;  slog::Index** mp_has0_ansindex1032;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1034({0, 1});
      slog::Relation* readrel1035 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1035->getIndex(ord1034, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1036({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1037 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1021 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({2, 0, 1, 3, 4});
      slog::Relation* readrel1039 = db->getRelation("mbranch");
      mbranchindex1022 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({2, 0, 1});
      slog::Relation* readrel1041 = db->getRelation("mp_has0");
      mp_has0index1023 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({0, 1});
      slog::Relation* readrel1043 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1024 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 2, 3, 4, 0});
      slog::Relation* readrel1045 = db->getRelation("mbranch");
      mbranchindex1025 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1047 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1026 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({0, 2, 1});
      slog::Relation* readrel1049 = db->getRelation("mp_has0");
      mp_has0index1027 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 2, 0});
      slog::Relation* readrel1051 = db->getRelation("mp_has0");
      mp_has0index1028 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({1, 2, 3, 4, 0});
      slog::Relation* readrel1053 = db->getRelation("mbranch");
      mbranchindex1029 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({0, 2, 1});
      slog::Relation* readrel1055 = db->getRelation("mp_has0");
      mp_has0index1030 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 2, 0});
      slog::Relation* readrel1057 = db->getRelation("mp_has0");
      mp_has0index1031 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({0, 1});
      slog::Relation* readrel1059 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1032 = readrel1059->getIndex(ord1058, false);
  
    }
    ReadTask1033(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c203 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c204 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c46 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x62x0x0x0index1021, std::array<u64,6>{v_c85, v_c46, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1022, std::array<u64,5>{v_c46, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index1023, std::array<u64,3>{v_c85, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1024, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m1060) {
          u64 v_c48 = m1060[1];
          if (!slog::exists_probe<5,2>(mbranchindex1025, std::array<u64,5>{v_c48, v_c46, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x62x0x0x0index1026, std::array<u64,6>{v_c85, v_c46, v_c48, 0, 0, 0}, [&](const std::array<u64,6>& m1061) {
            u64 v_c205 = m1061[3]; u64 v_c45 = m1061[4]; u64 v_c50 = m1061[5];
            if (!slog::exists_probe<3,2>(mp_has0index1027, std::array<u64,3>{v_c205, v_c85, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index1028, std::array<u64,3>{v_c50, v_c85, 0})) return;
            slog::join_probe<5,4>(mbranchindex1029, std::array<u64,5>{v_c48, v_c46, v_c45, v_c50, 0}, [&](const std::array<u64,5>& m1062) {
              u64 v_c206 = m1062[4];
              slog::join_probe<3,3>(mp_has0index1030, std::array<u64,3>{v_c205, v_c85, v_c206}, [&](const std::array<u64,3>& m1063) {
                slog::join_probe<3,2>(mp_has0index1031, std::array<u64,3>{v_c50, v_c85, 0}, [&](const std::array<u64,3>& m1064) {
                  u64 v_c207 = m1064[2];
                  slog::join_probe<2,1>(mp_has0_ansindex1032, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m1065) {
                    u64 v_c86 = m1065[1];
                    u64 v_c208 = _prim_band(db, v_c85, v_c46);
                    if (v_c208 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c209 = _prim_gt(db, v_c208, v_c203);
                    if (v_c209 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c209) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c205, v_c86}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1033* _cont = new ReadTask1033(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1033(db,b), false);
  // (crule (pre) (scan eval __t1ySt140 __t91oc139 rho t) (body (join boolean (0 1) 1 __t91oc139 b)) (head (emit-temp temp1se51948 __t1ySt140 b) (mkstruct boolval (1 0) __t6Y41138 b)) interp.slog:31 #f)
  class ReadTask1068 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** booleanindex1067;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1se51948");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1069({0, 1});
      slog::Relation* readrel1070 = db->getRelation("boolean");
      booleanindex1067 = readrel1070->getIndex(ord1069, false);
  
    }
    ReadTask1068(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c210 = _t[0];
        u64 v_c211 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c36 = _t[3];
        slog::join_probe<2,1>(booleanindex1067, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m1071) {
          u64 v_c29 = m1071[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c210, v_c29});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:31", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1068* _cont = new ReadTask1068(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1068(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan mp_put_ans __t5ODE624 rho2) (body (join-old eval (2 3 0 1) 1 (2 3 0 1) rho2 t __t4Pyv623 er) (exists eval (3 1 0 2) 1 t) (exists letrec (2 3 0 1) 1 er) (exists eval_ans (0 1) 1 __t4Pyv623) (join-old mp_put (3 0 2 1) 2 (3 0 2 1) t __t5ODE624 x rho) (exists letrec (1 2 3 0) 2 x er) (join eval (2 3 0 1) 2 rho t __7yeU1057 __t4cK3622) (join-old letrec (0 1 2 3) 3 (0 1 2 3) __t4cK3622 x er eb) (join eval_ans (0 1) 1 __t4Pyv623 vr)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1072;  slog::Index** evalindex1073;  slog::Index** letrecindex1074;  slog::Index** eval_ansindex1075;  slog::Index** mp_putindex1076;  slog::Index** letrecindex1077;  slog::Index** evalindex1078;  slog::Index** letrecindex1079;  slog::Index** eval_ansindex1080;  slog::Index** evaldelta1081;  slog::Index** mp_putdelta1082;  slog::Index** letrecdelta1083;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord1085({0, 1, 2});
      slog::Relation* readrel1086 = db->getRelation("store");
      head_index[3] = readrel1086->getIndex(ord1085, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord1087({0, 1, 2});
      slog::Relation* readrel1088 = db->getRelation("binding_event");
      head_index[4] = readrel1088->getIndex(ord1087, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord1089({2, 3, 0, 1});
      slog::Relation* readrel1090 = db->getRelation("eval");
      evalindex1072 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({2, 3, 0, 1});
      slog::Relation* readrel1092 = db->getRelation("eval");
      evaldelta1081 = readrel1092->getIndex(ord1091, true);
      std::vector<u16> ord1093({3, 1, 0, 2});
      slog::Relation* readrel1094 = db->getRelation("eval");
      evalindex1073 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({2, 3, 0, 1});
      slog::Relation* readrel1096 = db->getRelation("letrec");
      letrecindex1074 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({0, 1});
      slog::Relation* readrel1098 = db->getRelation("eval_ans");
      eval_ansindex1075 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({3, 0, 2, 1});
      slog::Relation* readrel1100 = db->getRelation("mp_put");
      mp_putindex1076 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({3, 0, 2, 1});
      slog::Relation* readrel1102 = db->getRelation("mp_put");
      mp_putdelta1082 = readrel1102->getIndex(ord1101, true);
      std::vector<u16> ord1103({1, 2, 3, 0});
      slog::Relation* readrel1104 = db->getRelation("letrec");
      letrecindex1077 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({2, 3, 0, 1});
      slog::Relation* readrel1106 = db->getRelation("eval");
      evalindex1078 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({0, 1, 2, 3});
      slog::Relation* readrel1108 = db->getRelation("letrec");
      letrecindex1079 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({0, 1, 2, 3});
      slog::Relation* readrel1110 = db->getRelation("letrec");
      letrecdelta1083 = readrel1110->getIndex(ord1109, true);
      std::vector<u16> ord1111({0, 1});
      slog::Relation* readrel1112 = db->getRelation("eval_ans");
      eval_ansindex1080 = readrel1112->getIndex(ord1111, false);
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c127 = v_const52b5e20f559958f34e533431;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c130 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c131 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c132 = v_constd4735e3a265e16eee03f5971;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c134 = _t[0];
        u64 v_c38 = _t[1];
        slog::join_probe_old<4,1>(evalindex1072, evaldelta1081, std::array<u64,4>{v_c38, 0, 0, 0}, [&](const std::array<u64,4>& m1113) {
          u64 v_c36 = m1113[1]; u64 v_c133 = m1113[2]; u64 v_c33 = m1113[3];
          if (!slog::exists_probe<4,1>(evalindex1073, std::array<u64,4>{v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letrecindex1074, std::array<u64,4>{v_c33, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex1075, std::array<u64,2>{v_c133, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex1076, mp_putdelta1082, std::array<u64,4>{v_c36, v_c134, 0, 0}, [&](const std::array<u64,4>& m1114) {
            u64 v_c0 = m1114[2]; u64 v_c4 = m1114[3];
            if (!slog::exists_probe<4,2>(letrecindex1077, std::array<u64,4>{v_c0, v_c33, 0, 0})) return;
            slog::join_probe<4,2>(evalindex1078, std::array<u64,4>{v_c4, v_c36, 0, 0}, [&](const std::array<u64,4>& m1115) {
              u64 v_c135 = m1115[2]; u64 v_c136 = m1115[3];
              slog::join_probe_old<4,3>(letrecindex1079, letrecdelta1083, std::array<u64,4>{v_c136, v_c0, v_c33, 0}, [&](const std::array<u64,4>& m1116) {
                u64 v_c34 = m1116[3];
                slog::join_probe<2,1>(eval_ansindex1080, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m1117) {
                  u64 v_c41 = m1117[1];
                  ++_fires;
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c126, v_c127, v_c128, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c126, v_c129, v_c130, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c36)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c126, v_c131, v_c132, v_c36}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c0, v_c36, v_c41}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c0, v_c36, v_c36}, std::array<u16,3>{0, 1, 2});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask1084* _cont = new ReadTask1084(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1084(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre03ZE1741 __errf41Q01742 __errf1bP11743 __errf7qkX1744 __errf5DAo1745) (body) (head (emit error (0) __erre03ZE1741)) <internal>:1 #f)
  class ReadTask1118 : public slog::Task
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
      std::vector<u16> ord1119({0});
      slog::Relation* readrel1120 = db->getRelation("error");
      head_index[0] = readrel1120->getIndex(ord1119, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask1118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c212 = _t[0];
        u64 v_c213 = _t[1];
        u64 v_c214 = _t[2];
        u64 v_c215 = _t[3];
        u64 v_c216 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c212}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask1118* _cont = new ReadTask1118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1118(db,b), false);
  // (crule (pre) (scan mleaf __t6Cxo369 k v) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t6Cxo369 t __t8pY8370)) (head (mkstruct mp_put (1 2 3 0) __2kOd1560 t k v)) map.slog:92 #f)
  class ReadTask1123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1121;  slog::Index** mp_uniondelta1122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord1124({1, 2, 0});
      slog::Relation* readrel1125 = db->getRelation("mp_union");
      mp_unionindex1121 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 0});
      slog::Relation* readrel1127 = db->getRelation("mp_union");
      mp_uniondelta1122 = readrel1127->getIndex(ord1126, true);
  
    }
    ReadTask1123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c217 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(mp_unionindex1121, mp_uniondelta1122, std::array<u64,3>{v_c217, 0, 0}, [&](const std::array<u64,3>& m1128) {
          u64 v_c36 = m1128[1]; u64 v_c218 = m1128[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c36, v_c85, v_c2}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask1123* _cont = new ReadTask1123(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1123(db,b), false);
  // (crule (pre (let __tconst14HM709 const60e3114d9b4b6577eea8cbc0) (let __tconst9fQa703 const844546be553b9dcbf71ae163) (let __tconst09sA701 const0453462f31b2bcf68e33a91f)) (scan temp6rU11812 __t8Hit708) (body (exists sym (1 0) 1 __tconst9fQa703) (exists primref (1 0) 1 __tconst14HM709) (join sym (1 0) 1 __tconst09sA701 __t1F7O702) (join sym (1 0) 1 __tconst9fQa703 __t3RPz704) (join primref (1 0) 1 __tconst14HM709 __t8M3S710)) (head (emit-temp temp92Pq1813 __t8Hit708) (mkstruct app (1 2 0) __t1VB8711 __t8M3S710 __t8Hit708)) kcfa.slog:52 #f)
  class ReadTask1134 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex1129;  slog::Index** primrefindex1130;  slog::Index** symindex1131;  slog::Index** symindex1132;  slog::Index** primrefindex1133;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp92Pq1813");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp6rU11812");
      std::vector<u16> ord1135({1, 0});
      slog::Relation* readrel1136 = db->getRelation("sym");
      symindex1129 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 0});
      slog::Relation* readrel1138 = db->getRelation("primref");
      primrefindex1130 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 0});
      slog::Relation* readrel1140 = db->getRelation("sym");
      symindex1131 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 0});
      slog::Relation* readrel1142 = db->getRelation("sym");
      symindex1132 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 0});
      slog::Relation* readrel1144 = db->getRelation("primref");
      primrefindex1133 = readrel1144->getIndex(ord1143, false);
  
    }
    ReadTask1134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c219 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c220 = v_const844546be553b9dcbf71ae163;
      u64 v_c221 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c222 = _t[0];
        if (!slog::exists_probe<2,1>(symindex1129, std::array<u64,2>{v_c220, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1130, std::array<u64,2>{v_c219, 0})) return;
        slog::join_probe<2,1>(symindex1131, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m1145) {
          u64 v_c223 = m1145[1];
          slog::join_probe<2,1>(symindex1132, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1146) {
            u64 v_c224 = m1146[1];
            slog::join_probe<2,1>(primrefindex1133, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m1147) {
              u64 v_c225 = m1147[1];
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c222});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c225, v_c222}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:52", "delta:temp6rU11812", _fires);
  
      if (!_done)
      {
        ReadTask1134* _cont = new ReadTask1134(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1134(db,b), false);
  // (crule (pre (let __trid1aRe1173 constaa218622af4adb846b2d6244) (let __trel90Y91174 constf6cdc3db4b71e0cdeda6912e) (let __tcol2p1T1175 const6b86b273ff34fce19d6b804e) (let __trel6kaB1176 constf6cdc3db4b71e0cdeda6912e) (let __tcol9YXV1177 constd4735e3a265e16eee03f5971)) (scan eval __t77Vk298 e1 rho t) (body (exists eval_ans (0 1) 1 __t77Vk298) (join $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 e1 rho t __d0 e2 e3) (join eval_ans (0 1) 1 __t77Vk298 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel90Y91174 __tcol2p1T1175 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel6kaB1176 __tcol9YXV1177 (1 2 3 4 0)) (mkstruct select_branch (2 3 1 0) __7Jff1172 e2 e3 __v0)) interp.slog:88 #f)
  class ReadTask1161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex1148;  slog::Index** $sup70016x87x0x0x0index1149;  slog::Index** eval_ansindex1150;
    u32 sid1151;  u32 sid1152;  u32 sid1153;  u32 sid1154;  u32 sid1155;  u32 sid1156;  u32 sid1157;  u32 sid1158;  u32 sid1159;  u32 sid1160;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1162({0, 1});
      slog::Relation* readrel1163 = db->getRelation("eval_ans");
      eval_ansindex1148 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel1165 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1149 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({0, 1});
      slog::Relation* readrel1167 = db->getRelation("eval_ans");
      eval_ansindex1150 = readrel1167->getIndex(ord1166, false);
      sid1151 = db->getRelation("app")->getStructId();
      sid1152 = db->getRelation("boolean")->getStructId();
      sid1153 = db->getRelation("if")->getStructId();
      sid1154 = db->getRelation("lambda")->getStructId();
      sid1155 = db->getRelation("let")->getStructId();
      sid1156 = db->getRelation("letrec")->getStructId();
      sid1157 = db->getRelation("num")->getStructId();
      sid1158 = db->getRelation("primref")->getStructId();
      sid1159 = db->getRelation("ref")->getStructId();
      sid1160 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c226 = v_constaa218622af4adb846b2d6244;
      u64 v_c227 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c228 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c229 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c230 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c231 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<2,1>(eval_ansindex1148, std::array<u64,2>{v_c231, 0})) return;
        slog::join_probe<6,3>($sup70016x87x0x0x0index1149, std::array<u64,6>{v_c137, v_c4, v_c36, 0, 0, 0}, [&](const std::array<u64,6>& m1168) {
          u64 v_c74 = m1168[3]; u64 v_c138 = m1168[4]; u64 v_c139 = m1168[5];
          slog::join_probe<2,1>(eval_ansindex1150, std::array<u64,2>{v_c231, 0}, [&](const std::array<u64,2>& m1169) {
            u64 v_c56 = m1169[1];
            ++_fires;
            if (!((is_struct(v_c138) && (decode_struct_id(v_c138) == sid1151 || decode_struct_id(v_c138) == sid1152 || decode_struct_id(v_c138) == sid1153 || decode_struct_id(v_c138) == sid1154 || decode_struct_id(v_c138) == sid1155 || decode_struct_id(v_c138) == sid1156 || decode_struct_id(v_c138) == sid1157 || decode_struct_id(v_c138) == sid1158 || decode_struct_id(v_c138) == sid1159 || decode_struct_id(v_c138) == sid1160))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c226, v_c227, v_c228, v_c138}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c139) && (decode_struct_id(v_c139) == sid1151 || decode_struct_id(v_c139) == sid1152 || decode_struct_id(v_c139) == sid1153 || decode_struct_id(v_c139) == sid1154 || decode_struct_id(v_c139) == sid1155 || decode_struct_id(v_c139) == sid1156 || decode_struct_id(v_c139) == sid1157 || decode_struct_id(v_c139) == sid1158 || decode_struct_id(v_c139) == sid1159 || decode_struct_id(v_c139) == sid1160))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c226, v_c229, v_c230, v_c139}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c138, v_c139, v_c56}, std::array<u16,4>{2, 3, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1161* _cont = new ReadTask1161(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1161(db,b), false);
  // (crule (pre) (scan eval __t8KmI338 ef rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (exists eval_args (3 2 0 1) 2 t rho) (exists eval_ans (0 1) 1 __t8KmI338) (join $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t es __t8Dhb337) (exists app (1 2 0) 2 ef es) (exists eval_args (1 3 2 0) 3 es t rho) (join eval (2 3 0 1) 3 rho t __t8Dhb337 __t87KU336) (join app (0 1 2) 3 __t87KU336 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t24hv340) (exists eval_args_ans (0 1) 1 __t24hv340) (join eval_ans (0 1) 1 __t8KmI338 __t1N6L339) (join eval_args_ans (0 1) 1 __t24hv340 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t1N6L339 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t9Mk1341) (join delta_ans (0 1) 1 __t9Mk1341 v)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask1190 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1170;  slog::Index** appindex1171;  slog::Index** eval_argsindex1172;  slog::Index** eval_ansindex1173;  slog::Index** $sup70016x75x0x0x0index1174;  slog::Index** appindex1175;  slog::Index** eval_argsindex1176;  slog::Index** evalindex1177;  slog::Index** appindex1178;  slog::Index** eval_argsindex1179;  slog::Index** eval_args_ansindex1180;  slog::Index** eval_ansindex1181;  slog::Index** eval_args_ansindex1182;  slog::Index** deltaindex1183;  slog::Index** primindex1184;  slog::Index** deltaindex1185;  slog::Index** delta_ansindex1186;  slog::Index** eval_argsdelta1187;  slog::Index** primdelta1188;  slog::Index** deltadelta1189;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1191({0, 1});
      slog::Relation* readrel1192 = db->getRelation("eval_ans");
      head_index[0] = readrel1192->getIndex(ord1191, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1193({2, 3, 0, 1});
      slog::Relation* readrel1194 = db->getRelation("eval");
      evalindex1170 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 2, 0});
      slog::Relation* readrel1196 = db->getRelation("app");
      appindex1171 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({3, 2, 0, 1});
      slog::Relation* readrel1198 = db->getRelation("eval_args");
      eval_argsindex1172 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({0, 1});
      slog::Relation* readrel1200 = db->getRelation("eval_ans");
      eval_ansindex1173 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({1, 3, 4, 2, 0});
      slog::Relation* readrel1202 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index1174 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({1, 2, 0});
      slog::Relation* readrel1204 = db->getRelation("app");
      appindex1175 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 3, 2, 0});
      slog::Relation* readrel1206 = db->getRelation("eval_args");
      eval_argsindex1176 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({2, 3, 0, 1});
      slog::Relation* readrel1208 = db->getRelation("eval");
      evalindex1177 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({0, 1, 2});
      slog::Relation* readrel1210 = db->getRelation("app");
      appindex1178 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({1, 3, 2, 0});
      slog::Relation* readrel1212 = db->getRelation("eval_args");
      eval_argsindex1179 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 3, 2, 0});
      slog::Relation* readrel1214 = db->getRelation("eval_args");
      eval_argsdelta1187 = readrel1214->getIndex(ord1213, true);
      std::vector<u16> ord1215({0, 1});
      slog::Relation* readrel1216 = db->getRelation("eval_args_ans");
      eval_args_ansindex1180 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({0, 1});
      slog::Relation* readrel1218 = db->getRelation("eval_ans");
      eval_ansindex1181 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({0, 1});
      slog::Relation* readrel1220 = db->getRelation("eval_args_ans");
      eval_args_ansindex1182 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({2, 0, 1});
      slog::Relation* readrel1222 = db->getRelation("delta");
      deltaindex1183 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({0, 1});
      slog::Relation* readrel1224 = db->getRelation("prim");
      primindex1184 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({0, 1});
      slog::Relation* readrel1226 = db->getRelation("prim");
      primdelta1188 = readrel1226->getIndex(ord1225, true);
      std::vector<u16> ord1227({1, 2, 0});
      slog::Relation* readrel1228 = db->getRelation("delta");
      deltaindex1185 = readrel1228->getIndex(ord1227, false);
      std::vector<u16> ord1229({1, 2, 0});
      slog::Relation* readrel1230 = db->getRelation("delta");
      deltadelta1189 = readrel1230->getIndex(ord1229, true);
      std::vector<u16> ord1231({0, 1});
      slog::Relation* readrel1232 = db->getRelation("delta_ans");
      delta_ansindex1186 = readrel1232->getIndex(ord1231, false);
  
    }
    ReadTask1190(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c232 = _t[0];
        u64 v_c233 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex1170, std::array<u64,4>{v_c4, v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1171, std::array<u64,3>{v_c233, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex1172, std::array<u64,4>{v_c36, v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1173, std::array<u64,2>{v_c232, 0})) return;
        slog::join_probe<5,3>($sup70016x75x0x0x0index1174, std::array<u64,5>{v_c233, v_c4, v_c36, 0, 0}, [&](const std::array<u64,5>& m1233) {
          u64 v_c234 = m1233[3]; u64 v_c235 = m1233[4];
          if (!slog::exists_probe<3,2>(appindex1175, std::array<u64,3>{v_c233, v_c234, 0})) return;
          if (!slog::exists_probe<4,3>(eval_argsindex1176, std::array<u64,4>{v_c234, v_c36, v_c4, 0})) return;
          slog::join_probe<4,3>(evalindex1177, std::array<u64,4>{v_c4, v_c36, v_c235, 0}, [&](const std::array<u64,4>& m1234) {
            u64 v_c236 = m1234[3];
            slog::join_probe<3,3>(appindex1178, std::array<u64,3>{v_c236, v_c233, v_c234}, [&](const std::array<u64,3>& m1235) {
              slog::join_probe_old<4,3>(eval_argsindex1179, eval_argsdelta1187, std::array<u64,4>{v_c234, v_c36, v_c4, 0}, [&](const std::array<u64,4>& m1236) {
                u64 v_c237 = m1236[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1180, std::array<u64,2>{v_c237, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1181, std::array<u64,2>{v_c232, 0}, [&](const std::array<u64,2>& m1237) {
                  u64 v_c238 = m1237[1];
                  slog::join_probe<2,1>(eval_args_ansindex1182, std::array<u64,2>{v_c237, 0}, [&](const std::array<u64,2>& m1238) {
                    u64 v_c239 = m1238[1];
                    if (!slog::exists_probe<3,1>(deltaindex1183, std::array<u64,3>{v_c239, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex1184, primdelta1188, std::array<u64,2>{v_c238, 0}, [&](const std::array<u64,2>& m1239) {
                      u64 v_c240 = m1239[1];
                      slog::join_probe_old<3,2>(deltaindex1185, deltadelta1189, std::array<u64,3>{v_c240, v_c239, 0}, [&](const std::array<u64,3>& m1240) {
                        u64 v_c241 = m1240[2];
                        slog::join_probe<2,1>(delta_ansindex1186, std::array<u64,2>{v_c241, 0}, [&](const std::array<u64,2>& m1241) {
                          u64 v_c2 = m1241[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c235, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1190* _cont = new ReadTask1190(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1190(db,b), false);
  // (crule (pre (let __trid7eCK1088 const07d7fbed0aba019c07f7eb8a) (let __trel2iiF1089 const20347926ddb307a8e2bdb71b) (let __tcol0Wnu1090 const4e07408562bedb8b60ce05c1)) (scan mp_del __t6EHL288 l k) (body (exists $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t6EHL288 __v0) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists mp_msk_ans (1 0) 1 p) (join mp_msk (1 2 0) 2 k m __t9pQc287) (join mp_msk_ans (0 1) 2 __t9pQc287 p)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7eCK1088 __trel2iiF1089 __tcol0Wnu1090 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __4RjO1087 p m __v0 r)) map.slog:83 #f)
  class ReadTask1252 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index1242;  slog::Index** mp_mskindex1243;  slog::Index** mp_del_ansindex1244;  slog::Index** $sup5638x82x0x0x0index1245;  slog::Index** mp_msk_ansindex1246;  slog::Index** mp_mskindex1247;  slog::Index** mp_msk_ansindex1248;
    u32 sid1250;  u32 sid1249;  u32 sid1251;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord1253({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1254 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1242 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("mp_msk");
      mp_mskindex1243 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({0, 1});
      slog::Relation* readrel1258 = db->getRelation("mp_del_ans");
      mp_del_ansindex1244 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1260 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1245 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 0});
      slog::Relation* readrel1262 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1246 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 2, 0});
      slog::Relation* readrel1264 = db->getRelation("mp_msk");
      mp_mskindex1247 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({0, 1});
      slog::Relation* readrel1266 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1248 = readrel1266->getIndex(ord1265, false);
      sid1250 = db->getRelation("_enum")->getStructId();
      sid1249 = db->getRelation("mbranch")->getStructId();
      sid1251 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c243 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c244 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c245 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c85 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index1242, std::array<u64,6>{v_c85, v_c45, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1243, std::array<u64,3>{v_c85, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex1244, std::array<u64,2>{v_c245, 0}, [&](const std::array<u64,2>& m1267) {
          u64 v_c56 = m1267[1];
          slog::join_probe<6,2>($sup5638x82x0x0x0index1245, std::array<u64,6>{v_c85, v_c45, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1268) {
            u64 v_c74 = m1268[2]; u64 v_c46 = m1268[3]; u64 v_c48 = m1268[4]; u64 v_c50 = m1268[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1246, std::array<u64,2>{v_c48, 0})) return;
            slog::join_probe<3,2>(mp_mskindex1247, std::array<u64,3>{v_c85, v_c46, 0}, [&](const std::array<u64,3>& m1269) {
              u64 v_c246 = m1269[2];
              slog::join_probe<2,2>(mp_msk_ansindex1248, std::array<u64,2>{v_c246, v_c48}, [&](const std::array<u64,2>& m1270) {
                ++_fires;
                if (!((is_struct(v_c50) && (decode_struct_id(v_c50) == sid1249 || decode_struct_id(v_c50) == sid1250 || decode_struct_id(v_c50) == sid1251))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c242, v_c243, v_c244, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c46, v_c56, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask1252* _cont = new ReadTask1252(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1252(db,b), false);
  // (crule (pre) (scan temp1se51948 __t1ySt140 b) (body (join boolval (1 0) 1 b __t6Y41138)) (head (emit eval_ans (0 1) __t1ySt140 __t6Y41138)) interp.slog:31 #f)
  class ReadTask1272 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex1271;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1273({0, 1});
      slog::Relation* readrel1274 = db->getRelation("eval_ans");
      head_index[0] = readrel1274->getIndex(ord1273, false);
      outer_rel = db->getRelation("temp1se51948");
      std::vector<u16> ord1275({1, 0});
      slog::Relation* readrel1276 = db->getRelation("boolval");
      boolvalindex1271 = readrel1276->getIndex(ord1275, false);
  
    }
    ReadTask1272(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c210 = _t[0];
        u64 v_c29 = _t[1];
        slog::join_probe<2,1>(boolvalindex1271, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1277) {
          u64 v_c247 = m1277[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c210, v_c247}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:31", "delta:temp1se51948", _fires);
  
      if (!_done)
      {
        ReadTask1272* _cont = new ReadTask1272(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1272(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_msk __t4hJg802 k m) (body (exists $sup5638x84x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (2 1 4 0 3) 1 m) (join mp_msk_ans (0 1) 1 __t4hJg802 p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_bld (1 2 3 4 0) 2 p m) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __t2paO798 l r) (exists mp_del (0 2 1) 2 __t2paO798 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_del (1 2 0) 2 r k) (join mbranch (1 2 3 4 0) 4 p m l r __t29Nf797) (join mp_del (0 2 1) 3 __t2paO798 k __t29Nf797) (join mp_bld (1 2 3 4 0) 3 p m l __v0 __t2Csk801) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join mp_del_ans (0 1) 2 __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask1298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index1278;  slog::Index** mbranchindex1279;  slog::Index** mp_delindex1280;  slog::Index** mp_bldindex1281;  slog::Index** mp_msk_ansindex1282;  slog::Index** mbranchindex1283;  slog::Index** mp_bldindex1284;  slog::Index** $sup5638x84x0x0x0index1285;  slog::Index** mp_delindex1286;  slog::Index** mp_bldindex1287;  slog::Index** mp_delindex1288;  slog::Index** mbranchindex1289;  slog::Index** mp_delindex1290;  slog::Index** mp_bldindex1291;  slog::Index** mp_del_ansindex1292;  slog::Index** mp_bld_ansindex1293;  slog::Index** mp_delindex1294;  slog::Index** mp_del_ansindex1295;  slog::Index** mp_bld_ansindex1296;  slog::Index** mp_deldelta1297;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1299({0, 1});
      slog::Relation* readrel1300 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1300->getIndex(ord1299, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1301({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1302 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1278 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({2, 0, 1, 3, 4});
      slog::Relation* readrel1304 = db->getRelation("mbranch");
      mbranchindex1279 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({2, 0, 1});
      slog::Relation* readrel1306 = db->getRelation("mp_del");
      mp_delindex1280 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({2, 1, 4, 0, 3});
      slog::Relation* readrel1308 = db->getRelation("mp_bld");
      mp_bldindex1281 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1282 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 2, 3, 4, 0});
      slog::Relation* readrel1312 = db->getRelation("mbranch");
      mbranchindex1283 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({1, 2, 3, 4, 0});
      slog::Relation* readrel1314 = db->getRelation("mp_bld");
      mp_bldindex1284 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1316 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1285 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({0, 2, 1});
      slog::Relation* readrel1318 = db->getRelation("mp_del");
      mp_delindex1286 = readrel1318->getIndex(ord1317, false);
      std::vector<u16> ord1319({1, 2, 3, 4, 0});
      slog::Relation* readrel1320 = db->getRelation("mp_bld");
      mp_bldindex1287 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("mp_del");
      mp_delindex1288 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({1, 2, 3, 4, 0});
      slog::Relation* readrel1324 = db->getRelation("mbranch");
      mbranchindex1289 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({0, 2, 1});
      slog::Relation* readrel1326 = db->getRelation("mp_del");
      mp_delindex1290 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({1, 2, 3, 4, 0});
      slog::Relation* readrel1328 = db->getRelation("mp_bld");
      mp_bldindex1291 = readrel1328->getIndex(ord1327, false);
      std::vector<u16> ord1329({1, 0});
      slog::Relation* readrel1330 = db->getRelation("mp_del_ans");
      mp_del_ansindex1292 = readrel1330->getIndex(ord1329, false);
      std::vector<u16> ord1331({0, 1});
      slog::Relation* readrel1332 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1293 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({1, 2, 0});
      slog::Relation* readrel1334 = db->getRelation("mp_del");
      mp_delindex1294 = readrel1334->getIndex(ord1333, false);
      std::vector<u16> ord1335({1, 2, 0});
      slog::Relation* readrel1336 = db->getRelation("mp_del");
      mp_deldelta1297 = readrel1336->getIndex(ord1335, true);
      std::vector<u16> ord1337({0, 1});
      slog::Relation* readrel1338 = db->getRelation("mp_del_ans");
      mp_del_ansindex1295 = readrel1338->getIndex(ord1337, false);
      std::vector<u16> ord1339({0, 1});
      slog::Relation* readrel1340 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1296 = readrel1340->getIndex(ord1339, false);
  
    }
    ReadTask1298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c248 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c249 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c46 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index1278, std::array<u64,6>{v_c85, v_c46, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1279, std::array<u64,5>{v_c46, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex1280, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex1281, std::array<u64,5>{v_c46, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1282, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m1341) {
          u64 v_c48 = m1341[1];
          if (!slog::exists_probe<5,2>(mbranchindex1283, std::array<u64,5>{v_c48, v_c46, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex1284, std::array<u64,5>{v_c48, v_c46, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x84x0x0x0index1285, std::array<u64,6>{v_c85, v_c46, v_c48, 0, 0, 0}, [&](const std::array<u64,6>& m1342) {
            u64 v_c250 = m1342[3]; u64 v_c45 = m1342[4]; u64 v_c50 = m1342[5];
            if (!slog::exists_probe<3,2>(mp_delindex1286, std::array<u64,3>{v_c250, v_c85, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex1287, std::array<u64,5>{v_c48, v_c46, v_c45, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex1288, std::array<u64,3>{v_c50, v_c85, 0})) return;
            slog::join_probe<5,4>(mbranchindex1289, std::array<u64,5>{v_c48, v_c46, v_c45, v_c50, 0}, [&](const std::array<u64,5>& m1343) {
              u64 v_c251 = m1343[4];
              slog::join_probe<3,3>(mp_delindex1290, std::array<u64,3>{v_c250, v_c85, v_c251}, [&](const std::array<u64,3>& m1344) {
                slog::join_probe<5,3>(mp_bldindex1291, std::array<u64,5>{v_c48, v_c46, v_c45, 0, 0}, [&](const std::array<u64,5>& m1345) {
                  u64 v_c56 = m1345[3]; u64 v_c252 = m1345[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex1292, std::array<u64,2>{v_c56, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex1293, std::array<u64,2>{v_c252, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex1294, mp_deldelta1297, std::array<u64,3>{v_c50, v_c85, 0}, [&](const std::array<u64,3>& m1346) {
                    u64 v_c253 = m1346[2];
                    slog::join_probe<2,2>(mp_del_ansindex1295, std::array<u64,2>{v_c253, v_c56}, [&](const std::array<u64,2>& m1347) {
                      slog::join_probe<2,1>(mp_bld_ansindex1296, std::array<u64,2>{v_c252, 0}, [&](const std::array<u64,2>& m1348) {
                        u64 v_c254 = m1348[1];
                        u64 v_c255 = _prim_band(db, v_c85, v_c46);
                        if (v_c255 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c256 = _prim_gt(db, v_c255, v_c248);
                        if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c256) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c250, v_c254}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1298* _cont = new ReadTask1298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1298(db,b), false);
  // (crule (pre (let __tconst5HUr775 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x0 __d0 p0 p1 t0 t1) (body (join-old mp_hsb_ans (0 1) 0 (0 1) __t0pir774 __v0) (let __t4G4F773 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0pir774 __t4G4F773) (let __t0Mwp776 (band p0 __v0)) (cmp lt __t0Mwp776 __tconst5HUr775)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t0pir774 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask1354 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1350;  slog::Index** mp_hsbindex1351;  slog::Index** mp_hsb_ansdelta1352;  slog::Index** mp_hsbdelta1353;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord1355({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1356 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel1356->getIndex(ord1355, false);
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord1357({0, 1});
      slog::Relation* readrel1358 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1350 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({0, 1});
      slog::Relation* readrel1360 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1352 = readrel1360->getIndex(ord1359, true);
      std::vector<u16> ord1361({0, 1});
      slog::Relation* readrel1362 = db->getRelation("mp_hsb");
      mp_hsbindex1351 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({0, 1});
      slog::Relation* readrel1364 = db->getRelation("mp_hsb");
      mp_hsbdelta1353 = readrel1364->getIndex(ord1363, true);
  
    }
    ReadTask1354(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c257 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c105 = _t[2];
        u64 v_c106 = _t[3];
        u64 v_c107 = _t[4];
        slog::join_all_old<2>(mp_hsb_ansindex1350, mp_hsb_ansdelta1352, [&](const std::array<u64,2>& m1365) {
          u64 v_c258 = m1365[0]; u64 v_c56 = m1365[1];
          u64 v_c259 = _prim_bxor(db, v_c97, v_c105);
          if (v_c259 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex1351, mp_hsbdelta1353, std::array<u64,2>{v_c258, v_c259}, [&](const std::array<u64,2>& m1366) {
            u64 v_c260 = _prim_band(db, v_c97, v_c56);
            if (v_c260 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c261 = _prim_lt(db, v_c260, v_c257);
            if (v_c261 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c261) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c258, v_c56, v_c74, v_c97, v_c105, v_c106, v_c107}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1354* _cont = new ReadTask1354(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1354(db,b), false);
  // (crule (pre) (scan eval __t6HuT359 er rho2 t) (body (exists $sup70016x95x0x0x1 (3 5 6 1 0 2 4 7) 3 er rho2 t) (exists $sup70016x95x0x0x0 (2 4 0 1 3 5) 2 er t) (exists mp_put (3 0 2 1) 1 t) (exists letrec (2 3 0 1) 1 er) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (1 0) 1 rho2) (exists eval_ans (0 1) 1 __t6HuT359) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho2 t __t63JF360 eb) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 3 eb t er) (exists letrec (2 3 0 1) 2 er eb) (exists eval_ans (0 1) 1 __t63JF360) (join $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 4 eb rho2 t er __t7DhJ358 __t0Rig361 rho x) (join $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join letrec (1 2 3 0) 3 x er eb __t0Sks357) (join eval (2 3 0 1) 4 rho t __t7DhJ358 __t0Sks357) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask1391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x1index1368;  slog::Index** $sup70016x95x0x0x0index1369;  slog::Index** mp_putindex1370;  slog::Index** letrecindex1371;  slog::Index** evalindex1372;  slog::Index** mp_put_ansindex1373;  slog::Index** eval_ansindex1374;  slog::Index** evalindex1375;  slog::Index** $sup70016x95x0x0x0index1376;  slog::Index** letrecindex1377;  slog::Index** eval_ansindex1378;  slog::Index** $sup70016x95x0x0x1index1379;  slog::Index** $sup70016x95x0x0x0index1380;  slog::Index** mp_putindex1381;  slog::Index** evalindex1382;  slog::Index** mp_put_ansindex1383;  slog::Index** letrecindex1384;  slog::Index** evalindex1385;  slog::Index** mp_put_ansindex1386;  slog::Index** eval_ansindex1387;  slog::Index** eval_ansindex1388;  slog::Index** evaldelta1389;  slog::Index** mp_putdelta1390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1392({0, 1});
      slog::Relation* readrel1393 = db->getRelation("eval_ans");
      head_index[0] = readrel1393->getIndex(ord1392, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1394({3, 5, 6, 1, 0, 2, 4, 7});
      slog::Relation* readrel1395 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index1368 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({2, 4, 0, 1, 3, 5});
      slog::Relation* readrel1397 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index1369 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({3, 0, 2, 1});
      slog::Relation* readrel1399 = db->getRelation("mp_put");
      mp_putindex1370 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({2, 3, 0, 1});
      slog::Relation* readrel1401 = db->getRelation("letrec");
      letrecindex1371 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({3, 1, 0, 2});
      slog::Relation* readrel1403 = db->getRelation("eval");
      evalindex1372 = readrel1403->getIndex(ord1402, false);
      std::vector<u16> ord1404({1, 0});
      slog::Relation* readrel1405 = db->getRelation("mp_put_ans");
      mp_put_ansindex1373 = readrel1405->getIndex(ord1404, false);
      std::vector<u16> ord1406({0, 1});
      slog::Relation* readrel1407 = db->getRelation("eval_ans");
      eval_ansindex1374 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({2, 3, 0, 1});
      slog::Relation* readrel1409 = db->getRelation("eval");
      evalindex1375 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({2, 3, 0, 1});
      slog::Relation* readrel1411 = db->getRelation("eval");
      evaldelta1389 = readrel1411->getIndex(ord1410, true);
      std::vector<u16> ord1412({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel1413 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index1376 = readrel1413->getIndex(ord1412, false);
      std::vector<u16> ord1414({2, 3, 0, 1});
      slog::Relation* readrel1415 = db->getRelation("letrec");
      letrecindex1377 = readrel1415->getIndex(ord1414, false);
      std::vector<u16> ord1416({0, 1});
      slog::Relation* readrel1417 = db->getRelation("eval_ans");
      eval_ansindex1378 = readrel1417->getIndex(ord1416, false);
      std::vector<u16> ord1418({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel1419 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index1379 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel1421 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index1380 = readrel1421->getIndex(ord1420, false);
      std::vector<u16> ord1422({0, 2, 1, 3});
      slog::Relation* readrel1423 = db->getRelation("mp_put");
      mp_putindex1381 = readrel1423->getIndex(ord1422, false);
      std::vector<u16> ord1424({0, 2, 1, 3});
      slog::Relation* readrel1425 = db->getRelation("mp_put");
      mp_putdelta1390 = readrel1425->getIndex(ord1424, true);
      std::vector<u16> ord1426({2, 3, 0, 1});
      slog::Relation* readrel1427 = db->getRelation("eval");
      evalindex1382 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({0, 1});
      slog::Relation* readrel1429 = db->getRelation("mp_put_ans");
      mp_put_ansindex1383 = readrel1429->getIndex(ord1428, false);
      std::vector<u16> ord1430({1, 2, 3, 0});
      slog::Relation* readrel1431 = db->getRelation("letrec");
      letrecindex1384 = readrel1431->getIndex(ord1430, false);
      std::vector<u16> ord1432({2, 3, 0, 1});
      slog::Relation* readrel1433 = db->getRelation("eval");
      evalindex1385 = readrel1433->getIndex(ord1432, false);
      std::vector<u16> ord1434({0, 1});
      slog::Relation* readrel1435 = db->getRelation("mp_put_ans");
      mp_put_ansindex1386 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({0, 1});
      slog::Relation* readrel1437 = db->getRelation("eval_ans");
      eval_ansindex1387 = readrel1437->getIndex(ord1436, false);
      std::vector<u16> ord1438({0, 1});
      slog::Relation* readrel1439 = db->getRelation("eval_ans");
      eval_ansindex1388 = readrel1439->getIndex(ord1438, false);
  
    }
    ReadTask1391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index1368, std::array<u64,8>{v_c33, v_c38, v_c36, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup70016x95x0x0x0index1369, std::array<u64,6>{v_c33, v_c36, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1370, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex1371, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1372, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex1373, std::array<u64,2>{v_c38, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1374, std::array<u64,2>{v_c39, 0})) return;
        slog::join_probe_old<4,2>(evalindex1375, evaldelta1389, std::array<u64,4>{v_c38, v_c36, 0, 0}, [&](const std::array<u64,4>& m1440) {
          u64 v_c40 = m1440[2]; u64 v_c34 = m1440[3];
          if (!slog::exists_probe<6,3>($sup70016x95x0x0x0index1376, std::array<u64,6>{v_c34, v_c36, v_c33, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(letrecindex1377, std::array<u64,4>{v_c33, v_c34, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex1378, std::array<u64,2>{v_c40, 0})) return;
          slog::join_probe<8,4>($sup70016x95x0x0x1index1379, std::array<u64,8>{v_c34, v_c38, v_c36, v_c33, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1441) {
            u64 v_c35 = m1441[4]; u64 v_c37 = m1441[5]; u64 v_c4 = m1441[6]; u64 v_c0 = m1441[7];
            slog::join_probe<6,6>($sup70016x95x0x0x0index1380, std::array<u64,6>{v_c35, v_c4, v_c36, v_c34, v_c33, v_c0}, [&](const std::array<u64,6>& m1442) {
              slog::join_probe_old<4,4>(mp_putindex1381, mp_putdelta1390, std::array<u64,4>{v_c37, v_c0, v_c4, v_c36}, [&](const std::array<u64,4>& m1443) {
                if (!slog::exists_probe<4,3>(evalindex1382, std::array<u64,4>{v_c4, v_c36, v_c35, 0})) return;
                if (!slog::exists_probe<2,2>(mp_put_ansindex1383, std::array<u64,2>{v_c37, v_c38})) return;
                slog::join_probe<4,3>(letrecindex1384, std::array<u64,4>{v_c0, v_c33, v_c34, 0}, [&](const std::array<u64,4>& m1444) {
                  u64 v_c32 = m1444[3];
                  slog::join_probe<4,4>(evalindex1385, std::array<u64,4>{v_c4, v_c36, v_c35, v_c32}, [&](const std::array<u64,4>& m1445) {
                    slog::join_probe<2,2>(mp_put_ansindex1386, std::array<u64,2>{v_c37, v_c38}, [&](const std::array<u64,2>& m1446) {
                      slog::join_probe<2,1>(eval_ansindex1387, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m1447) {
                        u64 v_c41 = m1447[1];
                        slog::join_probe<2,1>(eval_ansindex1388, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m1448) {
                          u64 v_c2 = m1448[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1391* _cont = new ReadTask1391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1391(db,b), false);
  // (crule (pre (let __tconst4JFo1084 constcd2a69ce5ca278db1d6da969) (let _00024sqc2XJk894 constd4735e3a265e16eee03f5971) (let _00024sqc3Vvh895 const5feceb66ffc86f38d952786c) (let _00024sqc1G23896 const6b86b273ff34fce19d6b804e) (let _00024sqo5Yvx897 const5feceb66ffc86f38d952786c) (let _00024sqo6jkp898 const6b86b273ff34fce19d6b804e) (let _00024sqo3xdn899 const6b86b273ff34fce19d6b804e) (let _00024sqo4MmQ900 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo6jkp898 __t6Yod544 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Yvx897 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3xdn899 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4MmQ900 __t6Yod544 _00024seq2) (join _enum (0 1) 2 __t6Yod544 __tconst4JFo1084) (join delta (2 0 1) 1 _00024seq2 __t7695542 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql014l892 (aslst _00024seq2)) (let chk7Lwz1801 (llen _00024sql014l892)) (eq _00024sqc2XJk894 chk7Lwz1801) (letp chk1eVW1802 (lref _00024sql014l892 _00024sqc3Vvh895)) (eq __t6Yod544 chk1eVW1802) (letp chk8waj1803 (lref _00024sql014l892 _00024sqc1G23896)) (eq __t6Yod544 chk8waj1803)) (head (emit-temp temp4Zu91795 __t7695542 b) (mkstruct boolval (1 0) __t4iE5541 b)) interp.slog:117 #f)
  class ReadTask1458 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1449;  slog::Index** $seq_atrindex1450;  slog::Index** $seq_atrindex1451;  slog::Index** _enumindex1452;  slog::Index** deltaindex1453;  slog::Index** comparison_opindex1454;  slog::Index** any_boolindex1455;  slog::Index** $seq_atrdelta1456;  slog::Index** $seq_atrdelta1457;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Zu91795");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1459({1, 0, 2});
      slog::Relation* readrel1460 = db->getRelation("$seq_at");
      driver_index = readrel1460->getIndex(ord1459, true);
      std::vector<u16> ord1461({1, 0, 2});
      slog::Relation* readrel1462 = db->getRelation("$seq_at");
      $seq_atindex1449 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({1, 0, 2});
      slog::Relation* readrel1464 = db->getRelation("$seq_atr");
      $seq_atrindex1450 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 0, 2});
      slog::Relation* readrel1466 = db->getRelation("$seq_atr");
      $seq_atrdelta1456 = readrel1466->getIndex(ord1465, true);
      std::vector<u16> ord1467({1, 0, 2});
      slog::Relation* readrel1468 = db->getRelation("$seq_atr");
      $seq_atrindex1451 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 0, 2});
      slog::Relation* readrel1470 = db->getRelation("$seq_atr");
      $seq_atrdelta1457 = readrel1470->getIndex(ord1469, true);
      std::vector<u16> ord1471({0, 1});
      slog::Relation* readrel1472 = db->getRelation("_enum");
      _enumindex1452 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({2, 0, 1});
      slog::Relation* readrel1474 = db->getRelation("delta");
      deltaindex1453 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({0});
      slog::Relation* readrel1476 = db->getRelation("comparison_op");
      comparison_opindex1454 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({0});
      slog::Relation* readrel1478 = db->getRelation("any_bool");
      any_boolindex1455 = readrel1478->getIndex(ord1477, false);
  
    }
    ReadTask1458(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c262 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c263 = v_constd4735e3a265e16eee03f5971;
      u64 v_c264 = v_const5feceb66ffc86f38d952786c;
      u64 v_c265 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c266 = v_const5feceb66ffc86f38d952786c;
      u64 v_c267 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c268 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c269 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c267, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1479) {
        u64 v_c270 = m1479[1];
        u64 v_c23 = m1479[2];
        if (buckethash(v_c270) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1449, std::array<u64,3>{v_c266, v_c270, v_c23}, [&](const std::array<u64,3>& m1480) {
          slog::join_probe_old<3,3>($seq_atrindex1450, $seq_atrdelta1456, std::array<u64,3>{v_c268, v_c270, v_c23}, [&](const std::array<u64,3>& m1481) {
            slog::join_probe_old<3,3>($seq_atrindex1451, $seq_atrdelta1457, std::array<u64,3>{v_c269, v_c270, v_c23}, [&](const std::array<u64,3>& m1482) {
              slog::join_probe<2,2>(_enumindex1452, std::array<u64,2>{v_c270, v_c262}, [&](const std::array<u64,2>& m1483) {
                slog::join_probe<3,1>(deltaindex1453, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m1484) {
                  u64 v_c271 = m1484[1]; u64 v_c240 = m1484[2];
                  slog::join_probe<1,1>(comparison_opindex1454, std::array<u64,1>{v_c240}, [&](const std::array<u64,1>& m1485) {
                    slog::join_all<1>(any_boolindex1455, [&](const std::array<u64,1>& m1486) {
                      u64 v_c29 = m1486[0];
                      bool ok1487 = true;
                      u64 v_c272 = _prim_aslst(db, v_c23, &ok1487);
                      if (!ok1487) return;
                      u64 v_c273 = _prim_llen(db, v_c272);
                      if (v_c273 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                      if (v_c263 != v_c273) return;
                      bool ok1488 = true;
                      u64 v_c274 = _prim_lref(db, v_c272, v_c264, &ok1488);
                      if (!ok1488) return;
                      if (v_c270 != v_c274) return;
                      bool ok1489 = true;
                      u64 v_c275 = _prim_lref(db, v_c272, v_c265, &ok1489);
                      if (!ok1489) return;
                      if (v_c270 != v_c275) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c271, v_c29});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1458* _cont = new ReadTask1458(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1458(db,b), false);
  // (crule (pre (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c) (let __tconst0SLc45 const06abaa100ecef791ce028c56) (let __tconst2aC790 const6b86b273ff34fce19d6b804e)) (scan temp5u3V1982 __t1Qwq78 __t1uVZ69 __t5wMp60 __t7j3b88 __t8Wlt43 __t8XJL92) (body (exists ref (1 0) 1 __tconst5MNq94) (exists ref (1 0) 1 __tconst56qw82) (exists ref (1 0) 1 __tconst6c7T73) (exists primref (1 0) 1 __tconst0SLc45) (exists ref (1 0) 1 __tconst2JmK55) (join ref (1 0) 1 __tconst2aC790 __t6rYz85) (join ref (1 0) 1 __tconst5MNq94 __t0g1Q71) (join ref (1 0) 1 __tconst56qw82 __t7Sy862) (join ref (1 0) 1 __tconst6c7T73 __t5Ugf53) (join primref (1 0) 1 __tconst0SLc45 __t0d6446) (join ref (1 0) 1 __tconst2JmK55 __t4U6j39) (let __t8ZUv44 (lpush __t8Wlt43 __t4U6j39))) (head (emit-temp temp1cP31983 __t1Qwq78 __t1uVZ69 __t5wMp60 __t7j3b88 __t8XJL92 __t8ZUv44) (mkstruct app (1 2 0) __t9CBr54 __t5Ugf53 __t5wMp60) (mkstruct app (1 2 0) __t66zQ63 __t7Sy862 __t5wMp60) (mkstruct app (1 2 0) __t8z2o72 __t0g1Q71 __t1uVZ69) (mkstruct app (1 2 0) __t9rwO81 __t0g1Q71 __t1Qwq78) (mkstruct lambda (1 2 0) __t32mX89 __t7j3b88 __t6rYz85)) kcfa.slog:16 #f)
  class ReadTask1501 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1490;  slog::Index** refindex1491;  slog::Index** refindex1492;  slog::Index** primrefindex1493;  slog::Index** refindex1494;  slog::Index** refindex1495;  slog::Index** refindex1496;  slog::Index** refindex1497;  slog::Index** refindex1498;  slog::Index** primrefindex1499;  slog::Index** refindex1500;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1cP31983");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("app");
      head_rel[4] = db->getRelation("app");
      head_rel[5] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp5u3V1982");
      std::vector<u16> ord1502({1, 0});
      slog::Relation* readrel1503 = db->getRelation("ref");
      refindex1490 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 0});
      slog::Relation* readrel1505 = db->getRelation("ref");
      refindex1491 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 0});
      slog::Relation* readrel1507 = db->getRelation("ref");
      refindex1492 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({1, 0});
      slog::Relation* readrel1509 = db->getRelation("primref");
      primrefindex1493 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({1, 0});
      slog::Relation* readrel1511 = db->getRelation("ref");
      refindex1494 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 0});
      slog::Relation* readrel1513 = db->getRelation("ref");
      refindex1495 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({1, 0});
      slog::Relation* readrel1515 = db->getRelation("ref");
      refindex1496 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 0});
      slog::Relation* readrel1517 = db->getRelation("ref");
      refindex1497 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 0});
      slog::Relation* readrel1519 = db->getRelation("ref");
      refindex1498 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 0});
      slog::Relation* readrel1521 = db->getRelation("primref");
      primrefindex1499 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 0});
      slog::Relation* readrel1523 = db->getRelation("ref");
      refindex1500 = readrel1523->getIndex(ord1522, false);
  
    }
    ReadTask1501(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c276 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c277 = v_constef2d127de37b942baad06145;
      u64 v_c278 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c279 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c280 = v_const5feceb66ffc86f38d952786c;
      u64 v_c281 = v_const06abaa100ecef791ce028c56;
      u64 v_c282 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c283 = _t[0];
        u64 v_c284 = _t[1];
        u64 v_c285 = _t[2];
        u64 v_c286 = _t[3];
        u64 v_c287 = _t[4];
        u64 v_c288 = _t[5];
        if (!slog::exists_probe<2,1>(refindex1490, std::array<u64,2>{v_c280, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1491, std::array<u64,2>{v_c279, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1492, std::array<u64,2>{v_c278, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1493, std::array<u64,2>{v_c281, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1494, std::array<u64,2>{v_c276, 0})) return;
        slog::join_probe<2,1>(refindex1495, std::array<u64,2>{v_c282, 0}, [&](const std::array<u64,2>& m1524) {
          u64 v_c289 = m1524[1];
          slog::join_probe<2,1>(refindex1496, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1525) {
            u64 v_c290 = m1525[1];
            slog::join_probe<2,1>(refindex1497, std::array<u64,2>{v_c279, 0}, [&](const std::array<u64,2>& m1526) {
              u64 v_c291 = m1526[1];
              slog::join_probe<2,1>(refindex1498, std::array<u64,2>{v_c278, 0}, [&](const std::array<u64,2>& m1527) {
                u64 v_c292 = m1527[1];
                slog::join_probe<2,1>(primrefindex1499, std::array<u64,2>{v_c281, 0}, [&](const std::array<u64,2>& m1528) {
                  u64 v_c293 = m1528[1];
                  slog::join_probe<2,1>(refindex1500, std::array<u64,2>{v_c276, 0}, [&](const std::array<u64,2>& m1529) {
                    u64 v_c294 = m1529[1];
                    u64 v_c295 = _prim_lpush(db, v_c287, v_c294);
                    if (v_c295 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c283, v_c284, v_c285, v_c286, v_c288, v_c295});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c292, v_c285}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c291, v_c285}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c290, v_c284}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c290, v_c283}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[5], newbatch[5], std::array<u64,2>{v_c286, v_c289}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp5u3V1982", _fires);
  
      if (!_done)
      {
        ReadTask1501* _cont = new ReadTask1501(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1501(db,b), false);
}

