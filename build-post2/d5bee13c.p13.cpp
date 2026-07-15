
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3b05f339a47cf251e643e4dd;
extern u64 v_const3cd26ab9ce3085a816a74a29;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6c3d8aa344844f80a370de02;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_consta2d3b5b64cd0c50598de1133;
extern u64 v_constc8dd3fe14ad7db61de7362fc;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste29c9c180c6279b0b02abd6a;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c918199782b5f3a6a(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9d7X1302 constd01925b37634a1a9d24159d8)) (scan mp_bld __t1Oue281 p m l __t4IY1280) (body (join _enum (0 1) 2 __t4IY1280 __tconst9d7X1302)) (head (emit mp_bld_ans (0 1) __t1Oue281 l)) map.slog:74 #f)
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
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord4({0, 1});
      slog::Relation* readrel5 = db->getRelation("_enum");
      _enumindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constd01925b37634a1a9d24159d8;
  
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
        slog::join_probe<2,2>(_enumindex0, std::array<u64,2>{v_c5, v_c0}, [&](const std::array<u64,2>& m6) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c4}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:74", "delta:mp_bld", _fires);
  
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
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan mp_put __t42Fa18 rho x t) (body (exists extend_env (1 3 0 2) 2 rho t) (exists $seq_at (1 0 2) 2 _00024sqo31L8847 x) (exists extend_env (3 0 1 2) 1 t) (exists mp_put_ans (0 1) 1 __t42Fa18) (join $sup70016x47x0x0x0 (2 3 4 5 0 1) 3 rho t x xs _00024seq0 __t2ugT17) (join extend_env (0 2 3 1) 4 __t2ugT17 _00024seq0 t rho) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo31L8847 x _00024seq0) (join-old extend_env (2 3 0 1) 2 (2 3 0 1) xs t __t8zl419 __v0) (join mp_put_ans (0 1) 2 __t42Fa18 __v0) (join extend_env_ans (0 1) 1 __t8zl419 __v1) (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (letp chk8huE1827 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk8huE1827) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let chk6sM71828 (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (eq xs chk6sM71828)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask19 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex7;  slog::Index** $seq_atindex8;  slog::Index** extend_envindex9;  slog::Index** mp_put_ansindex10;  slog::Index** $sup70016x47x0x0x0index11;  slog::Index** extend_envindex12;  slog::Index** $seq_atindex13;  slog::Index** extend_envindex14;  slog::Index** mp_put_ansindex15;  slog::Index** extend_env_ansindex16;  slog::Index** $seq_atdelta17;  slog::Index** extend_envdelta18;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("extend_env_ans");
      head_index[0] = readrel21->getIndex(ord20, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord22({1, 3, 0, 2});
      slog::Relation* readrel23 = db->getRelation("extend_env");
      extend_envindex7 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0, 2});
      slog::Relation* readrel25 = db->getRelation("$seq_at");
      $seq_atindex8 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({3, 0, 1, 2});
      slog::Relation* readrel27 = db->getRelation("extend_env");
      extend_envindex9 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("mp_put_ans");
      mp_put_ansindex10 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel31 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index11 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 2, 3, 1});
      slog::Relation* readrel33 = db->getRelation("extend_env");
      extend_envindex12 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0, 2});
      slog::Relation* readrel35 = db->getRelation("$seq_at");
      $seq_atindex13 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0, 2});
      slog::Relation* readrel37 = db->getRelation("$seq_at");
      $seq_atdelta17 = readrel37->getIndex(ord36, true);
      std::vector<u16> ord38({2, 3, 0, 1});
      slog::Relation* readrel39 = db->getRelation("extend_env");
      extend_envindex14 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({2, 3, 0, 1});
      slog::Relation* readrel41 = db->getRelation("extend_env");
      extend_envdelta18 = readrel41->getIndex(ord40, true);
      std::vector<u16> ord42({0, 1});
      slog::Relation* readrel43 = db->getRelation("mp_put_ans");
      mp_put_ansindex15 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("extend_env_ans");
      extend_env_ansindex16 = readrel45->getIndex(ord44, false);
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        if (!slog::exists_probe<4,2>(extend_envindex7, std::array<u64,4>{v_c12, v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex8, std::array<u64,3>{v_c10, v_c13, 0})) return;
        if (!slog::exists_probe<4,1>(extend_envindex9, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex10, std::array<u64,2>{v_c11, 0})) return;
        slog::join_probe<6,3>($sup70016x47x0x0x0index11, std::array<u64,6>{v_c12, v_c14, v_c13, 0, 0, 0}, [&](const std::array<u64,6>& m46) {
          u64 v_c15 = m46[3]; u64 v_c16 = m46[4]; u64 v_c17 = m46[5];
          slog::join_probe<4,4>(extend_envindex12, std::array<u64,4>{v_c17, v_c16, v_c14, v_c12}, [&](const std::array<u64,4>& m47) {
            slog::join_probe_old<3,3>($seq_atindex13, $seq_atdelta17, std::array<u64,3>{v_c10, v_c13, v_c16}, [&](const std::array<u64,3>& m48) {
              slog::join_probe_old<4,2>(extend_envindex14, extend_envdelta18, std::array<u64,4>{v_c15, v_c14, 0, 0}, [&](const std::array<u64,4>& m49) {
                u64 v_c18 = m49[2]; u64 v_c19 = m49[3];
                slog::join_probe<2,2>(mp_put_ansindex15, std::array<u64,2>{v_c11, v_c19}, [&](const std::array<u64,2>& m50) {
                  slog::join_probe<2,1>(extend_env_ansindex16, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m51) {
                    u64 v_c20 = m51[1];
                    bool ok52 = true;
                    u64 v_c21 = _prim_aslst(db, v_c16, &ok52);
                    if (!ok52) return;
                    u64 v_c22 = _prim_llen(db, v_c21);
                    if (v_c22 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c23 = _prim_ge(db, v_c22, v_c6);
                    if (v_c23 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (!v_c23) return;
                    bool ok54 = true;
                    u64 v_c24 = _prim_lref(db, v_c21, v_c7, &ok54);
                    if (!ok54) return;
                    if (v_c13 != v_c24) return;
                    u64 v_c25 = _prim__0002d(db, v_c22, v_c9);
                    if (v_c25 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c26 = _prim_lslice(db, v_c21, v_c8, v_c25);
                    if (v_c26 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (v_c15 != v_c26) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c20}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask19* _cont = new ReadTask19(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask19(db,b), false);
  // (crule (pre) (scan eval_ans __t3BcP671 v) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t3BcP671 eb __v0 t) (exists $sup70016x92x0x0x1 (3 4 7 2 0 1 5 6 8 9) 3 __v0 eb t) (exists $sup70016x92x0x0x0 (1 4 0 2 3 5) 2 eb t) (exists eval (3 1 0 2) 1 t) (exists mp_put (3 0 2 1) 1 t) (exists let (3 0 1 2) 1 eb) (join-old mp_put_ans (1 0) 1 (1 0) __v0 __t0mp6672) (exists mp_put (3 0 2 1) 2 t __t0mp6672) (join-old $sup70016x92x0x0x1 (3 4 7 2 0 1 5 6 8 9) 4 (3 4 7 2 0 1 5 6 8 9) __v0 eb t __t0mp6672 __t5vg0669 __t7GLg670 er rho vr x) (join-old $sup70016x92x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t5vg0669 rho t eb er x) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval_ans (0 1) 2 __t7GLg670 vr) (join-old let (1 2 3 0) 3 (1 2 3 0) x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join eval_ans (0 1) 2 __t7GLg670 vr)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask80 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex55;  slog::Index** $sup70016x92x0x0x1index56;  slog::Index** $sup70016x92x0x0x0index57;  slog::Index** evalindex58;  slog::Index** mp_putindex59;  slog::Index** letindex60;  slog::Index** mp_put_ansindex61;  slog::Index** mp_putindex62;  slog::Index** $sup70016x92x0x0x1index63;  slog::Index** $sup70016x92x0x0x0index64;  slog::Index** evalindex65;  slog::Index** mp_putindex66;  slog::Index** evalindex67;  slog::Index** eval_ansindex68;  slog::Index** letindex69;  slog::Index** evalindex70;  slog::Index** eval_ansindex71;  slog::Index** evaldelta72;  slog::Index** mp_put_ansdelta73;  slog::Index** $sup70016x92x0x0x1delta74;  slog::Index** $sup70016x92x0x0x0delta75;  slog::Index** evaldelta76;  slog::Index** mp_putdelta77;  slog::Index** letdelta78;  slog::Index** evaldelta79;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("eval_ans");
      head_index[0] = readrel82->getIndex(ord81, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord83({0, 1, 2, 3});
      slog::Relation* readrel84 = db->getRelation("eval");
      evalindex55 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2, 3});
      slog::Relation* readrel86 = db->getRelation("eval");
      evaldelta72 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel88 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index56 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel90 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index57 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({3, 1, 0, 2});
      slog::Relation* readrel92 = db->getRelation("eval");
      evalindex58 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({3, 0, 2, 1});
      slog::Relation* readrel94 = db->getRelation("mp_put");
      mp_putindex59 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({3, 0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("let");
      letindex60 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("mp_put_ans");
      mp_put_ansindex61 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("mp_put_ans");
      mp_put_ansdelta73 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({3, 0, 2, 1});
      slog::Relation* readrel102 = db->getRelation("mp_put");
      mp_putindex62 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel104 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index63 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel106 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1delta74 = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel108 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index64 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel110 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0delta75 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({2, 3, 0, 1});
      slog::Relation* readrel112 = db->getRelation("eval");
      evalindex65 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({2, 3, 0, 1});
      slog::Relation* readrel114 = db->getRelation("eval");
      evaldelta76 = readrel114->getIndex(ord113, true);
      std::vector<u16> ord115({0, 2, 1, 3});
      slog::Relation* readrel116 = db->getRelation("mp_put");
      mp_putindex66 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({0, 2, 1, 3});
      slog::Relation* readrel118 = db->getRelation("mp_put");
      mp_putdelta77 = readrel118->getIndex(ord117, true);
      std::vector<u16> ord119({2, 3, 0, 1});
      slog::Relation* readrel120 = db->getRelation("eval");
      evalindex67 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({0, 1});
      slog::Relation* readrel122 = db->getRelation("eval_ans");
      eval_ansindex68 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 3, 0});
      slog::Relation* readrel124 = db->getRelation("let");
      letindex69 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 3, 0});
      slog::Relation* readrel126 = db->getRelation("let");
      letdelta78 = readrel126->getIndex(ord125, true);
      std::vector<u16> ord127({2, 3, 0, 1});
      slog::Relation* readrel128 = db->getRelation("eval");
      evalindex70 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({2, 3, 0, 1});
      slog::Relation* readrel130 = db->getRelation("eval");
      evaldelta79 = readrel130->getIndex(ord129, true);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("eval_ans");
      eval_ansindex71 = readrel132->getIndex(ord131, false);
  
    }
    ReadTask80(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        slog::join_probe_old<4,1>(evalindex55, evaldelta72, std::array<u64,4>{v_c27, 0, 0, 0}, [&](const std::array<u64,4>& m133) {
          u64 v_c29 = m133[1]; u64 v_c19 = m133[2]; u64 v_c14 = m133[3];
          if (!slog::exists_probe<10,3>($sup70016x92x0x0x1index56, std::array<u64,10>{v_c19, v_c29, v_c14, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<6,2>($sup70016x92x0x0x0index57, std::array<u64,6>{v_c29, v_c14, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex58, std::array<u64,4>{v_c14, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex59, std::array<u64,4>{v_c14, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letindex60, std::array<u64,4>{v_c29, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_put_ansindex61, mp_put_ansdelta73, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m134) {
            u64 v_c30 = m134[1];
            if (!slog::exists_probe<4,2>(mp_putindex62, std::array<u64,4>{v_c14, v_c30, 0, 0})) return;
            slog::join_probe_old<10,4>($sup70016x92x0x0x1index63, $sup70016x92x0x0x1delta74, std::array<u64,10>{v_c19, v_c29, v_c14, v_c30, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m135) {
              u64 v_c31 = m135[4]; u64 v_c32 = m135[5]; u64 v_c33 = m135[6]; u64 v_c12 = m135[7]; u64 v_c34 = m135[8]; u64 v_c13 = m135[9];
              slog::join_probe_old<6,6>($sup70016x92x0x0x0index64, $sup70016x92x0x0x0delta75, std::array<u64,6>{v_c31, v_c12, v_c14, v_c29, v_c33, v_c13}, [&](const std::array<u64,6>& m136) {
                slog::join_probe_old<4,4>(evalindex65, evaldelta76, std::array<u64,4>{v_c12, v_c14, v_c32, v_c33}, [&](const std::array<u64,4>& m137) {
                  slog::join_probe_old<4,4>(mp_putindex66, mp_putdelta77, std::array<u64,4>{v_c30, v_c13, v_c12, v_c14}, [&](const std::array<u64,4>& m138) {
                    if (!slog::exists_probe<4,3>(evalindex67, std::array<u64,4>{v_c12, v_c14, v_c31, 0})) return;
                    if (!slog::exists_probe<2,2>(eval_ansindex68, std::array<u64,2>{v_c32, v_c34})) return;
                    slog::join_probe_old<4,3>(letindex69, letdelta78, std::array<u64,4>{v_c13, v_c33, v_c29, 0}, [&](const std::array<u64,4>& m139) {
                      u64 v_c35 = m139[3];
                      slog::join_probe_old<4,4>(evalindex70, evaldelta79, std::array<u64,4>{v_c12, v_c14, v_c31, v_c35}, [&](const std::array<u64,4>& m140) {
                        slog::join_probe<2,2>(eval_ansindex71, std::array<u64,2>{v_c32, v_c34}, [&](const std::array<u64,2>& m141) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c28}, std::array<u16,2>{0, 1});
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
        ReadTask80* _cont = new ReadTask80(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask80(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo57Hb970 __t40a6549 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5uVM967 __t40a6549 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo11r2968 __t40a6549 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo89F1969 __t40a6549 _00024seq2) (join delta (1 2 0) 2 __tconst2Vg0546 _00024seq2 __t6qCW547) (join closure (0 1 2) 1 __t40a6549 lm rc) (join any_bool (0) 0 b) (letp _00024sql3t08962 (aslst _00024seq2)) (let chk11hL1853 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk11hL1853) (letp chk0OXz1854 (lref _00024sql3t08962 _00024sqc2Wzv965)) (eq __t40a6549 chk0OXz1854) (letp chk1wls1855 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk1wls1855)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex142;  slog::Index** $seq_atindex143;  slog::Index** $seq_atrindex144;  slog::Index** deltaindex145;  slog::Index** closureindex146;  slog::Index** any_boolindex147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord149({1, 0, 2});
      slog::Relation* readrel150 = db->getRelation("$seq_atr");
      driver_index = readrel150->getIndex(ord149, true);
      std::vector<u16> ord151({1, 0, 2});
      slog::Relation* readrel152 = db->getRelation("$seq_at");
      $seq_atindex142 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 0, 2});
      slog::Relation* readrel154 = db->getRelation("$seq_at");
      $seq_atindex143 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0, 2});
      slog::Relation* readrel156 = db->getRelation("$seq_atr");
      $seq_atrindex144 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("delta");
      deltaindex145 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({0, 1, 2});
      slog::Relation* readrel160 = db->getRelation("closure");
      closureindex146 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0});
      slog::Relation* readrel162 = db->getRelation("any_bool");
      any_boolindex147 = readrel162->getIndex(ord161, false);
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const06abaa100ecef791ce028c56;
      u64 v_c37 = v_constd4735e3a265e16eee03f5971;
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c40 = v_const5feceb66ffc86f38d952786c;
      u64 v_c41 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c42 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c43, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m163) {
        u64 v_c44 = m163[1];
        u64 v_c45 = m163[2];
        if (buckethash(v_c44) != bucket) return;
        slog::join_probe<3,3>($seq_atindex142, std::array<u64,3>{v_c40, v_c44, v_c45}, [&](const std::array<u64,3>& m164) {
          slog::join_probe<3,3>($seq_atindex143, std::array<u64,3>{v_c41, v_c44, v_c45}, [&](const std::array<u64,3>& m165) {
            slog::join_probe<3,3>($seq_atrindex144, std::array<u64,3>{v_c42, v_c44, v_c45}, [&](const std::array<u64,3>& m166) {
              slog::join_probe<3,2>(deltaindex145, std::array<u64,3>{v_c36, v_c45, 0}, [&](const std::array<u64,3>& m167) {
                u64 v_c46 = m167[2];
                slog::join_probe<3,1>(closureindex146, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m168) {
                  u64 v_c47 = m168[1]; u64 v_c48 = m168[2];
                  slog::join_all<1>(any_boolindex147, [&](const std::array<u64,1>& m169) {
                    u64 v_c49 = m169[0];
                    bool ok170 = true;
                    u64 v_c50 = _prim_aslst(db, v_c45, &ok170);
                    if (!ok170) return;
                    u64 v_c51 = _prim_llen(db, v_c50);
                    if (v_c51 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c37 != v_c51) return;
                    bool ok171 = true;
                    u64 v_c52 = _prim_lref(db, v_c50, v_c38, &ok171);
                    if (!ok171) return;
                    if (v_c44 != v_c52) return;
                    bool ok172 = true;
                    u64 v_c53 = _prim_lref(db, v_c50, v_c39, &ok172);
                    if (!ok172) return;
                    if (v_c44 != v_c53) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c46, v_c49});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c49}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask148* _cont = new ReadTask148(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask148(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mp_msk __t78qG683 p n) (body (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_msk_ans (0 1) 1 __t78qG683) (join $sup5638x107x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t78qG683 n p q __t5Sgr680 l m r u v) (cmp lt m n) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t5Sgr680 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk_ans (0 1) 2 __t78qG683 q) (exists mp_union (2 0 1) 1 v) (join mbranch (1 2 3 4 0) 4 q n u v __t105R678) (exists mp_union (2 0 1) 2 __t105R678 __t5Sgr680) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0Aux684) (join mp_union (0 1 2) 3 __t5Sgr680 __t0Aux684 __t105R678) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask191 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index173;  slog::Index** mbranchindex174;  slog::Index** mbranchindex175;  slog::Index** mp_msk_ansindex176;  slog::Index** $sup5638x107x0x0x1index177;  slog::Index** $sup5638x107x0x0x0index178;  slog::Index** mbranchindex179;  slog::Index** mp_msk_ansindex180;  slog::Index** mp_unionindex181;  slog::Index** mbranchindex182;  slog::Index** mp_unionindex183;  slog::Index** mbranchindex184;  slog::Index** mp_unionindex185;  slog::Index** mp_msk_ansindex186;  slog::Index** mp_unionindex187;  slog::Index** mp_union_ansindex188;  slog::Index** mbranchdelta189;  slog::Index** mp_uniondelta190;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord192({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel193 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index173 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({2, 0, 1, 3, 4});
      slog::Relation* readrel195 = db->getRelation("mbranch");
      mbranchindex174 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 3, 4, 0});
      slog::Relation* readrel197 = db->getRelation("mbranch");
      mbranchindex175 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({0, 1});
      slog::Relation* readrel199 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex176 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel201 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index177 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel203 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index178 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 3, 4, 0});
      slog::Relation* readrel205 = db->getRelation("mbranch");
      mbranchindex179 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({0, 1});
      slog::Relation* readrel207 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex180 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({2, 0, 1});
      slog::Relation* readrel209 = db->getRelation("mp_union");
      mp_unionindex181 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 3, 4, 0});
      slog::Relation* readrel211 = db->getRelation("mbranch");
      mbranchindex182 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({2, 0, 1});
      slog::Relation* readrel213 = db->getRelation("mp_union");
      mp_unionindex183 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 3, 4, 0});
      slog::Relation* readrel215 = db->getRelation("mbranch");
      mbranchindex184 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 2, 3, 4, 0});
      slog::Relation* readrel217 = db->getRelation("mbranch");
      mbranchdelta189 = readrel217->getIndex(ord216, true);
      std::vector<u16> ord218({0, 1, 2});
      slog::Relation* readrel219 = db->getRelation("mp_union");
      mp_unionindex185 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex186 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("mp_union");
      mp_unionindex187 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("mp_union");
      mp_uniondelta190 = readrel225->getIndex(ord224, true);
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("mp_union_ans");
      mp_union_ansindex188 = readrel227->getIndex(ord226, false);
  
    }
    ReadTask191(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c2 = _t[1];
        u64 v_c56 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index173, std::array<u64,9>{v_c56, v_c2, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex174, std::array<u64,5>{v_c56, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex175, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex176, std::array<u64,2>{v_c55, 0})) return;
        slog::join_probe<10,3>($sup5638x107x0x0x1index177, std::array<u64,10>{v_c55, v_c56, v_c2, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m228) {
          u64 v_c57 = m228[3]; u64 v_c58 = m228[4]; u64 v_c4 = m228[5]; u64 v_c3 = m228[6]; u64 v_c59 = m228[7]; u64 v_c60 = m228[8]; u64 v_c28 = m228[9];
          u64 v_c61 = _prim_lt(db, v_c3, v_c56);
          if (v_c61 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c61) return;
          slog::join_probe<9,9>($sup5638x107x0x0x0index178, std::array<u64,9>{v_c57, v_c56, v_c60, v_c28, v_c58, v_c4, v_c3, v_c2, v_c59}, [&](const std::array<u64,9>& m230) {
            if (!slog::exists_probe<5,4>(mbranchindex179, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex180, std::array<u64,2>{v_c55, v_c57})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex181, std::array<u64,3>{v_c28, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex182, std::array<u64,5>{v_c57, v_c56, v_c60, v_c28, 0}, [&](const std::array<u64,5>& m231) {
              u64 v_c62 = m231[4];
              if (!slog::exists_probe<3,2>(mp_unionindex183, std::array<u64,3>{v_c62, v_c58, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex184, mbranchdelta189, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m232) {
                u64 v_c63 = m232[4];
                slog::join_probe<3,3>(mp_unionindex185, std::array<u64,3>{v_c58, v_c63, v_c62}, [&](const std::array<u64,3>& m233) {
                  slog::join_probe<2,2>(mp_msk_ansindex186, std::array<u64,2>{v_c55, v_c57}, [&](const std::array<u64,2>& m234) {
                    slog::join_probe_old<3,2>(mp_unionindex187, mp_uniondelta190, std::array<u64,3>{v_c63, v_c28, 0}, [&](const std::array<u64,3>& m235) {
                      u64 v_c64 = m235[2];
                      slog::join_probe<2,1>(mp_union_ansindex188, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m236) {
                        u64 v_c19 = m236[1];
                        u64 v_c65 = _prim_band(db, v_c2, v_c56);
                        if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c66 = _prim_gt(db, v_c65, v_c54);
                        if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c66) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c58, v_c19, v_c56, v_c57, v_c60});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c56, v_c60, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask191* _cont = new ReadTask191(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask191(db,b), false);
  // (crule (pre (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp7mbl1988 __t39ek93 __t5f4h74 __t9rwO81) (body (join let (1 2 3 0) 3 __tconst56qw82 __t9rwO81 __t5f4h74 __t62tP83)) (head (emit-temp temp3mEP1989 __t39ek93 __t62tP83) (mkstruct let (1 2 3 0) __t1QAZ95 __tconst5MNq94 __t39ek93 __t62tP83)) kcfa.slog:16 #f)
  class ReadTask239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3mEP1989");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp7mbl1988");
      std::vector<u16> ord240({1, 2, 3, 0});
      slog::Relation* readrel241 = db->getRelation("let");
      letindex238 = readrel241->getIndex(ord240, false);
  
    }
    ReadTask239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c71 = _t[2];
        slog::join_probe<4,3>(letindex238, std::array<u64,4>{v_c67, v_c71, v_c70, 0}, [&](const std::array<u64,4>& m242) {
          u64 v_c72 = m242[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c72});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c68, v_c69, v_c72}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp7mbl1988", _fires);
  
      if (!_done)
      {
        ReadTask239* _cont = new ReadTask239(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask239(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e)) (scan temp1lqI2008 __t0Vtj505 __t0cTh509 __t2zNy470 __t9oQ4490) (body (exists app (2 0 1) 1 __t9oQ4490) (exists num (1 0) 1 __tconst0Ob1494) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join app (1 2 0) 2 __t3x0f492 __t9oQ4490 __t9htJ493) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472)) (head (emit-temp temp8qsY2009 __t0Vtj505 __t0cTh509 __t2zNy470 __t9htJ493) (mkstruct if (1 3 2 0) __t6hPZ506 __t0Vtj505 __t9htJ493 __t1oVV472)) kcfa.slog:40 #f)
  class ReadTask248 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex243;  slog::Index** numindex244;  slog::Index** primrefindex245;  slog::Index** appindex246;  slog::Index** numindex247;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8qsY2009");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp1lqI2008");
      std::vector<u16> ord249({2, 0, 1});
      slog::Relation* readrel250 = db->getRelation("app");
      appindex243 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 0});
      slog::Relation* readrel252 = db->getRelation("num");
      numindex244 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0});
      slog::Relation* readrel254 = db->getRelation("primref");
      primrefindex245 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("app");
      appindex246 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("num");
      numindex247 = readrel258->getIndex(ord257, false);
  
    }
    ReadTask248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c74 = v_consted725292f5f32d61535958c1;
      u64 v_c75 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        if (!slog::exists_probe<3,1>(appindex243, std::array<u64,3>{v_c79, 0, 0})) return;
        if (!slog::exists_probe<2,1>(numindex244, std::array<u64,2>{v_c75, 0})) return;
        slog::join_probe<2,1>(primrefindex245, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m259) {
          u64 v_c80 = m259[1];
          slog::join_probe<3,2>(appindex246, std::array<u64,3>{v_c80, v_c79, 0}, [&](const std::array<u64,3>& m260) {
            u64 v_c81 = m260[2];
            slog::join_probe<2,1>(numindex247, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m261) {
              u64 v_c82 = m261[1];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c77, v_c78, v_c81});
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c76, v_c81, v_c82}, std::array<u16,4>{1, 3, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp1lqI2008", _fires);
  
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
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90)) (scan temp7ay71996 __t9kRL183 __t9uEv177) (body (join let (1 2 3 0) 3 __tconst5vD0184 __t9kRL183 __t9uEv177 __t7w5s185)) (head (emit program (0) __t7w5s185)) kcfa.slog:29 #f)
  class ReadTask263 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex262;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord264({0});
      slog::Relation* readrel265 = db->getRelation("program");
      head_index[0] = readrel265->getIndex(ord264, false);
      outer_rel = db->getRelation("temp7ay71996");
      std::vector<u16> ord266({1, 2, 3, 0});
      slog::Relation* readrel267 = db->getRelation("let");
      letindex262 = readrel267->getIndex(ord266, false);
  
    }
    ReadTask263(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        u64 v_c85 = _t[1];
        slog::join_probe<4,3>(letindex262, std::array<u64,4>{v_c83, v_c84, v_c85, 0}, [&](const std::array<u64,4>& m268) {
          u64 v_c86 = m268[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c86}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp7ay71996", _fires);
  
      if (!_done)
      {
        ReadTask263* _cont = new ReadTask263(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask263(db,b), false);
  // (crule (pre (let __trid9n3x1549 const5d6ab4fefffae2e4c15033db) (let __trel5eWq1550 const4a59dbb9cb3129dfcc75170b) (let __tcol6eZ31551 constd4735e3a265e16eee03f5971)) (scan letrec __t7vAU766 x er eb) (body (exists mp_put (2 3 0 1) 1 x) (join eval (1 2 3 0) 1 __t7vAU766 rho t __9QsM1547) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t9Rkj767) (join mp_put_ans (0 1) 1 __t9Rkj767 rho2)) (head (tycheck t (accept seq) __trid9n3x1549 __trel5eWq1550 __tcol6eZ31551 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __6xaV1548 er rho2 t)) interp.slog:98 #f)
  class ReadTask274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex269;  slog::Index** evalindex270;  slog::Index** mp_putindex271;  slog::Index** mp_put_ansindex272;  slog::Index** mp_putdelta273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord275({2, 3, 0, 1});
      slog::Relation* readrel276 = db->getRelation("mp_put");
      mp_putindex269 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 3, 0});
      slog::Relation* readrel278 = db->getRelation("eval");
      evalindex270 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 2, 3, 0});
      slog::Relation* readrel280 = db->getRelation("mp_put");
      mp_putindex271 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 3, 0});
      slog::Relation* readrel282 = db->getRelation("mp_put");
      mp_putdelta273 = readrel282->getIndex(ord281, true);
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("mp_put_ans");
      mp_put_ansindex272 = readrel284->getIndex(ord283, false);
  
    }
    ReadTask274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c88 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c89 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c29 = _t[3];
        if (!slog::exists_probe<4,1>(mp_putindex269, std::array<u64,4>{v_c13, 0, 0, 0})) return;
        slog::join_probe<4,1>(evalindex270, std::array<u64,4>{v_c90, 0, 0, 0}, [&](const std::array<u64,4>& m285) {
          u64 v_c12 = m285[1]; u64 v_c14 = m285[2]; u64 v_c91 = m285[3];
          slog::join_probe_old<4,3>(mp_putindex271, mp_putdelta273, std::array<u64,4>{v_c12, v_c13, v_c14, 0}, [&](const std::array<u64,4>& m286) {
            u64 v_c92 = m286[3];
            slog::join_probe<2,1>(mp_put_ansindex272, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m287) {
              u64 v_c93 = m287[1];
              ++_fires;
              if (!(is_seq(v_c14)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c87, v_c88, v_c89, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c33, v_c93, v_c14}, std::array<u16,4>{1, 2, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask274* _cont = new ReadTask274(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask274(db,b), false);
  // (crule (pre (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c) (let __tconst1O2C203 const7297d2085ea0adffc396d546)) (scan temp5bNF1951 __t8R2f202 __t8cZd192 __t9Ps2210) (body (exists ref (1 0) 1 __tconst2PAJ212) (join primref (1 0) 1 __tconst1O2C203 __t0nMB204) (join ref (1 0) 1 __tconst2PAJ212 __t4x55194)) (head (emit-temp temp7x931952 __t8R2f202 __t8cZd192 __t9Ps2210) (mkstruct app (1 2 0) __t1aBM195 __t4x55194 __t8cZd192) (mkstruct app (1 2 0) __t7nIl205 __t0nMB204 __t8R2f202)) kcfa.slog:59 #f)
  class ReadTask291 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex288;  slog::Index** primrefindex289;  slog::Index** refindex290;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7x931952");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp5bNF1951");
      std::vector<u16> ord292({1, 0});
      slog::Relation* readrel293 = db->getRelation("ref");
      refindex288 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("primref");
      primrefindex289 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 0});
      slog::Relation* readrel297 = db->getRelation("ref");
      refindex290 = readrel297->getIndex(ord296, false);
  
    }
    ReadTask291(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c94 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c95 = v_const7297d2085ea0adffc396d546;
  
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
        u64 v_c96 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c98 = _t[2];
        if (!slog::exists_probe<2,1>(refindex288, std::array<u64,2>{v_c94, 0})) return;
        slog::join_probe<2,1>(primrefindex289, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m298) {
          u64 v_c99 = m298[1];
          slog::join_probe<2,1>(refindex290, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m299) {
            u64 v_c100 = m299[1];
            ++_fires;
            slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c96, v_c97, v_c98});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c100, v_c97}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c99, v_c96}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp5bNF1951", _fires);
  
      if (!_done)
      {
        ReadTask291* _cont = new ReadTask291(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask291(db,b), false);
  // (crule (pre) (scan tick __t8A6X268 __t4H6p267 t) (body (exists $sup70016x51x0x0x0 (4 0 3 1 2) 1 t) (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (join tick_ans (0 1) 1 __t8A6X268 t2) (join app (0 1 2) 1 __t4H6p267 ef es) (exists eval (3 1 0 2) 2 t ef) (exists eval_args (1 3 2 0) 2 es t) (join $sup70016x51x0x0x0 (1 2 4 0 3) 3 ef es t __d0 rho) (exists eval_args (1 3 2 0) 3 es t rho) (join eval (1 2 3 0) 3 ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join eval_args (1 3 2 0) 3 es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join closure (0 1 2) 1 __t5Yru265 __t3Nsh264 rhoc) (join lambda (0 1 2) 1 __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x0index300;  slog::Index** evalindex301;  slog::Index** eval_argsindex302;  slog::Index** tick_ansindex303;  slog::Index** appindex304;  slog::Index** evalindex305;  slog::Index** eval_argsindex306;  slog::Index** $sup70016x51x0x0x0index307;  slog::Index** eval_argsindex308;  slog::Index** evalindex309;  slog::Index** eval_ansindex310;  slog::Index** eval_argsindex311;  slog::Index** eval_args_ansindex312;  slog::Index** eval_ansindex313;  slog::Index** eval_args_ansindex314;  slog::Index** closureindex315;  slog::Index** lambdaindex316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord318({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel319 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel319->getIndex(ord318, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord320({4, 0, 3, 1, 2});
      slog::Relation* readrel321 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index300 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({3, 1, 0, 2});
      slog::Relation* readrel323 = db->getRelation("eval");
      evalindex301 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({3, 2, 0, 1});
      slog::Relation* readrel325 = db->getRelation("eval_args");
      eval_argsindex302 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("tick_ans");
      tick_ansindex303 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({0, 1, 2});
      slog::Relation* readrel329 = db->getRelation("app");
      appindex304 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({3, 1, 0, 2});
      slog::Relation* readrel331 = db->getRelation("eval");
      evalindex305 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 3, 2, 0});
      slog::Relation* readrel333 = db->getRelation("eval_args");
      eval_argsindex306 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 4, 0, 3});
      slog::Relation* readrel335 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index307 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 3, 2, 0});
      slog::Relation* readrel337 = db->getRelation("eval_args");
      eval_argsindex308 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 3, 0});
      slog::Relation* readrel339 = db->getRelation("eval");
      evalindex309 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("eval_ans");
      eval_ansindex310 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 3, 2, 0});
      slog::Relation* readrel343 = db->getRelation("eval_args");
      eval_argsindex311 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("eval_args_ans");
      eval_args_ansindex312 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1});
      slog::Relation* readrel347 = db->getRelation("eval_ans");
      eval_ansindex313 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1});
      slog::Relation* readrel349 = db->getRelation("eval_args_ans");
      eval_args_ansindex314 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({0, 1, 2});
      slog::Relation* readrel351 = db->getRelation("closure");
      closureindex315 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({0, 1, 2});
      slog::Relation* readrel353 = db->getRelation("lambda");
      lambdaindex316 = readrel353->getIndex(ord352, false);
  
    }
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<5,1>($sup70016x51x0x0x0index300, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex301, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex302, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        slog::join_probe<2,1>(tick_ansindex303, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m354) {
          u64 v_c103 = m354[1];
          slog::join_probe<3,1>(appindex304, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m355) {
            u64 v_c104 = m355[1]; u64 v_c105 = m355[2];
            if (!slog::exists_probe<4,2>(evalindex305, std::array<u64,4>{v_c14, v_c104, 0, 0})) return;
            if (!slog::exists_probe<4,2>(eval_argsindex306, std::array<u64,4>{v_c105, v_c14, 0, 0})) return;
            slog::join_probe<5,3>($sup70016x51x0x0x0index307, std::array<u64,5>{v_c104, v_c105, v_c14, 0, 0}, [&](const std::array<u64,5>& m356) {
              u64 v_c106 = m356[3]; u64 v_c12 = m356[4];
              if (!slog::exists_probe<4,3>(eval_argsindex308, std::array<u64,4>{v_c105, v_c14, v_c12, 0})) return;
              slog::join_probe<4,3>(evalindex309, std::array<u64,4>{v_c104, v_c12, v_c14, 0}, [&](const std::array<u64,4>& m357) {
                u64 v_c107 = m357[3];
                if (!slog::exists_probe<2,1>(eval_ansindex310, std::array<u64,2>{v_c107, 0})) return;
                slog::join_probe<4,3>(eval_argsindex311, std::array<u64,4>{v_c105, v_c14, v_c12, 0}, [&](const std::array<u64,4>& m358) {
                  u64 v_c108 = m358[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex312, std::array<u64,2>{v_c108, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex313, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m359) {
                    u64 v_c109 = m359[1];
                    slog::join_probe<2,1>(eval_args_ansindex314, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m360) {
                      u64 v_c110 = m360[1];
                      slog::join_probe<3,1>(closureindex315, std::array<u64,3>{v_c109, 0, 0}, [&](const std::array<u64,3>& m361) {
                        u64 v_c111 = m361[1]; u64 v_c112 = m361[2];
                        slog::join_probe<3,1>(lambdaindex316, std::array<u64,3>{v_c111, 0, 0}, [&](const std::array<u64,3>& m362) {
                          u64 v_c15 = m362[1]; u64 v_c29 = m362[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c107, v_c112, v_c106, v_c108, v_c101, v_c29, v_c104, v_c105, v_c12, v_c14, v_c103, v_c110, v_c15}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask317* _cont = new ReadTask317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask317(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan $sup5638x84x0x0x0 __t2paO798 k l m p r) (body (exists mp_del (0 2 1) 2 __t2paO798 k) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t29Nf797) (join-old mp_del (0 2 1) 3 (0 2 1) __t2paO798 k __t29Nf797) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t2Csk801) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join mp_del_ans (0 1) 2 __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask383 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex363;  slog::Index** mp_bldindex364;  slog::Index** mp_mskindex365;  slog::Index** mp_msk_ansindex366;  slog::Index** mp_delindex367;  slog::Index** mbranchindex368;  slog::Index** mp_delindex369;  slog::Index** mp_bldindex370;  slog::Index** mp_del_ansindex371;  slog::Index** mp_bld_ansindex372;  slog::Index** mp_mskindex373;  slog::Index** mp_msk_ansindex374;  slog::Index** mp_delindex375;  slog::Index** mp_del_ansindex376;  slog::Index** mp_bld_ansindex377;  slog::Index** mbranchdelta378;  slog::Index** mp_deldelta379;  slog::Index** mp_blddelta380;  slog::Index** mp_mskdelta381;  slog::Index** mp_deldelta382;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_del_ans");
      head_index[0] = readrel385->getIndex(ord384, false);
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord386({0, 2, 1});
      slog::Relation* readrel387 = db->getRelation("mp_del");
      mp_delindex363 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 3, 4, 0});
      slog::Relation* readrel389 = db->getRelation("mp_bld");
      mp_bldindex364 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("mp_msk");
      mp_mskindex365 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex366 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("mp_del");
      mp_delindex367 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 3, 4, 0});
      slog::Relation* readrel397 = db->getRelation("mbranch");
      mbranchindex368 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 2, 3, 4, 0});
      slog::Relation* readrel399 = db->getRelation("mbranch");
      mbranchdelta378 = readrel399->getIndex(ord398, true);
      std::vector<u16> ord400({0, 2, 1});
      slog::Relation* readrel401 = db->getRelation("mp_del");
      mp_delindex369 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({0, 2, 1});
      slog::Relation* readrel403 = db->getRelation("mp_del");
      mp_deldelta379 = readrel403->getIndex(ord402, true);
      std::vector<u16> ord404({1, 2, 3, 4, 0});
      slog::Relation* readrel405 = db->getRelation("mp_bld");
      mp_bldindex370 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 3, 4, 0});
      slog::Relation* readrel407 = db->getRelation("mp_bld");
      mp_blddelta380 = readrel407->getIndex(ord406, true);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("mp_del_ans");
      mp_del_ansindex371 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex372 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("mp_msk");
      mp_mskindex373 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("mp_msk");
      mp_mskdelta381 = readrel415->getIndex(ord414, true);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex374 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("mp_del");
      mp_delindex375 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("mp_del");
      mp_deldelta382 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("mp_del_ans");
      mp_del_ansindex376 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex377 = readrel425->getIndex(ord424, false);
  
    }
    ReadTask383(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c113 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c59 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex363, std::array<u64,3>{v_c114, v_c115, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex364, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex365, std::array<u64,3>{v_c115, v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex366, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex367, std::array<u64,3>{v_c59, v_c115, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex368, mbranchdelta378, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m426) {
          u64 v_c116 = m426[4];
          slog::join_probe_old<3,3>(mp_delindex369, mp_deldelta379, std::array<u64,3>{v_c114, v_c115, v_c116}, [&](const std::array<u64,3>& m427) {
            slog::join_probe_old<5,3>(mp_bldindex370, mp_blddelta380, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0}, [&](const std::array<u64,5>& m428) {
              u64 v_c19 = m428[3]; u64 v_c117 = m428[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex371, std::array<u64,2>{v_c19, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex372, std::array<u64,2>{v_c117, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex373, mp_mskdelta381, std::array<u64,3>{v_c115, v_c3, 0}, [&](const std::array<u64,3>& m429) {
                u64 v_c118 = m429[2];
                slog::join_probe<2,2>(mp_msk_ansindex374, std::array<u64,2>{v_c118, v_c2}, [&](const std::array<u64,2>& m430) {
                  slog::join_probe_old<3,2>(mp_delindex375, mp_deldelta382, std::array<u64,3>{v_c59, v_c115, 0}, [&](const std::array<u64,3>& m431) {
                    u64 v_c119 = m431[2];
                    slog::join_probe<2,2>(mp_del_ansindex376, std::array<u64,2>{v_c119, v_c19}, [&](const std::array<u64,2>& m432) {
                      slog::join_probe<2,1>(mp_bld_ansindex377, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m433) {
                        u64 v_c120 = m433[1];
                        u64 v_c121 = _prim_band(db, v_c115, v_c3);
                        if (v_c121 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c122 = _prim_gt(db, v_c121, v_c113);
                        if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c122) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c114, v_c120}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask383* _cont = new ReadTask383(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask383(db,b), false);
  // (crule (pre) (scan temp3Hfu2034 __t02pg792 __t7ZV0794 __v1) (body (let __t2xRf793 (lcat __t02pg792 __v1))) (head (emit-temp temp4pxV2035 __t2xRf793 __t7ZV0794)) interp.slog:44 #f)
  class ReadTask435 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4pxV2035");
      outer_rel = db->getRelation("temp3Hfu2034");
  
    }
    ReadTask435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c124 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c125 = _prim_lcat(db, v_c123, v_c20);
        if (v_c125 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c125, v_c124});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:temp3Hfu2034", _fires);
  
      if (!_done)
      {
        ReadTask435* _cont = new ReadTask435(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask435(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_bld_ans __t8pI6311 res) (body (join-old mp_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t8pI6311 p m __v0 r) (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (join-old mbranch (1 2 4 0 3) 3 (1 2 4 0 3) p m r __t62gM307 l) (exists mp_del (1 2 0) 1 __t62gM307) (exists mp_del (1 2 0) 1 l) (join-old $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 (4 3 5 2 0 1) p m r l __t0iNt308 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t0iNt308 k __t62gM307) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join-old mp_msk_ans (0 1) 2 (0 1) __t8vNz312 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join-old mp_del_ans (0 1) 2 (0 1) __t1hIi313 __v0) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex436;  slog::Index** $sup5638x82x0x0x0index437;  slog::Index** mp_mskindex438;  slog::Index** mp_msk_ansindex439;  slog::Index** mp_del_ansindex440;  slog::Index** mbranchindex441;  slog::Index** mp_delindex442;  slog::Index** mp_delindex443;  slog::Index** $sup5638x82x0x0x0index444;  slog::Index** mp_delindex445;  slog::Index** mp_delindex446;  slog::Index** mp_mskindex447;  slog::Index** mp_msk_ansindex448;  slog::Index** mp_delindex449;  slog::Index** mp_del_ansindex450;  slog::Index** mp_blddelta451;  slog::Index** mbranchdelta452;  slog::Index** $sup5638x82x0x0x0delta453;  slog::Index** mp_deldelta454;  slog::Index** mp_mskdelta455;  slog::Index** mp_msk_ansdelta456;  slog::Index** mp_deldelta457;  slog::Index** mp_del_ansdelta458;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("mp_del_ans");
      head_index[0] = readrel461->getIndex(ord460, false);
      outer_rel = db->getRelation("mp_bld_ans");
      std::vector<u16> ord462({0, 1, 2, 3, 4});
      slog::Relation* readrel463 = db->getRelation("mp_bld");
      mp_bldindex436 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 1, 2, 3, 4});
      slog::Relation* readrel465 = db->getRelation("mp_bld");
      mp_blddelta451 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel467 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index437 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({2, 0, 1});
      slog::Relation* readrel469 = db->getRelation("mp_msk");
      mp_mskindex438 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 0});
      slog::Relation* readrel471 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex439 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("mp_del_ans");
      mp_del_ansindex440 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 4, 0, 3});
      slog::Relation* readrel475 = db->getRelation("mbranch");
      mbranchindex441 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 4, 0, 3});
      slog::Relation* readrel477 = db->getRelation("mbranch");
      mbranchdelta452 = readrel477->getIndex(ord476, true);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("mp_del");
      mp_delindex442 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("mp_del");
      mp_delindex443 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel483 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index444 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel485 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta453 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({0, 2, 1});
      slog::Relation* readrel487 = db->getRelation("mp_del");
      mp_delindex445 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 2, 1});
      slog::Relation* readrel489 = db->getRelation("mp_del");
      mp_deldelta454 = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("mp_del");
      mp_delindex446 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("mp_msk");
      mp_mskindex447 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({1, 2, 0});
      slog::Relation* readrel495 = db->getRelation("mp_msk");
      mp_mskdelta455 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex448 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 1});
      slog::Relation* readrel499 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta456 = readrel499->getIndex(ord498, true);
      std::vector<u16> ord500({1, 2, 0});
      slog::Relation* readrel501 = db->getRelation("mp_del");
      mp_delindex449 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({1, 2, 0});
      slog::Relation* readrel503 = db->getRelation("mp_del");
      mp_deldelta457 = readrel503->getIndex(ord502, true);
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("mp_del_ans");
      mp_del_ansindex450 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("mp_del_ans");
      mp_del_ansdelta458 = readrel507->getIndex(ord506, true);
  
    }
    ReadTask459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c127 = _t[0];
        u64 v_c120 = _t[1];
        slog::join_probe_old<5,1>(mp_bldindex436, mp_blddelta451, std::array<u64,5>{v_c127, 0, 0, 0, 0}, [&](const std::array<u64,5>& m508) {
          u64 v_c2 = m508[1]; u64 v_c3 = m508[2]; u64 v_c19 = m508[3]; u64 v_c59 = m508[4];
          if (!slog::exists_probe<6,3>($sup5638x82x0x0x0index437, std::array<u64,6>{v_c2, v_c3, v_c59, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex438, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex439, std::array<u64,2>{v_c2, 0})) return;
          if (!slog::exists_probe<2,1>(mp_del_ansindex440, std::array<u64,2>{v_c19, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex441, mbranchdelta452, std::array<u64,5>{v_c2, v_c3, v_c59, 0, 0}, [&](const std::array<u64,5>& m509) {
            u64 v_c128 = m509[3]; u64 v_c4 = m509[4];
            if (!slog::exists_probe<3,1>(mp_delindex442, std::array<u64,3>{v_c128, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_delindex443, std::array<u64,3>{v_c4, 0, 0})) return;
            slog::join_probe_old<6,4>($sup5638x82x0x0x0index444, $sup5638x82x0x0x0delta453, std::array<u64,6>{v_c2, v_c3, v_c59, v_c4, 0, 0}, [&](const std::array<u64,6>& m510) {
              u64 v_c129 = m510[4]; u64 v_c115 = m510[5];
              slog::join_probe_old<3,3>(mp_delindex445, mp_deldelta454, std::array<u64,3>{v_c129, v_c115, v_c128}, [&](const std::array<u64,3>& m511) {
                if (!slog::exists_probe<3,2>(mp_delindex446, std::array<u64,3>{v_c4, v_c115, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex447, mp_mskdelta455, std::array<u64,3>{v_c115, v_c3, 0}, [&](const std::array<u64,3>& m512) {
                  u64 v_c130 = m512[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex448, mp_msk_ansdelta456, std::array<u64,2>{v_c130, v_c2}, [&](const std::array<u64,2>& m513) {
                    slog::join_probe_old<3,2>(mp_delindex449, mp_deldelta457, std::array<u64,3>{v_c4, v_c115, 0}, [&](const std::array<u64,3>& m514) {
                      u64 v_c131 = m514[2];
                      slog::join_probe_old<2,2>(mp_del_ansindex450, mp_del_ansdelta458, std::array<u64,2>{v_c131, v_c19}, [&](const std::array<u64,2>& m515) {
                        u64 v_c132 = _prim_band(db, v_c115, v_c3);
                        if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c133 = _prim_lt(db, v_c132, v_c126);
                        if (v_c133 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c133) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c120}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask459* _cont = new ReadTask459(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask459(db,b), false);
  // (crule (pre) (scan mbranch __t4G0B592 p m l r) (body (join mp_put (1 2 3 0) 1 __t4G0B592 k v __t1iR2591)) (head (emit $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) k m v __t1iR2591 l p r __t4G0B592)) map.slog:45 #f)
  class ReadTask518 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex517;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord519({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel520 = db->getRelation("$sup5638x44x0x0x0");
      head_index[0] = readrel520->getIndex(ord519, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord521({1, 2, 3, 0});
      slog::Relation* readrel522 = db->getRelation("mp_put");
      mp_putindex517 = readrel522->getIndex(ord521, false);
  
    }
    ReadTask518(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c59 = _t[4];
        slog::join_probe<4,1>(mp_putindex517, std::array<u64,4>{v_c134, 0, 0, 0}, [&](const std::array<u64,4>& m523) {
          u64 v_c115 = m523[1]; u64 v_c28 = m523[2]; u64 v_c135 = m523[3];
          ++_fires;
          slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c115, v_c3, v_c28, v_c135, v_c4, v_c2, v_c59, v_c134}, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask518* _cont = new ReadTask518(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask518(db,b), false);
  // (crule (pre (let __tconst2EWQ349 const6b86b273ff34fce19d6b804e)) (scan mp_get_ans __t7Zfl351 v) (body (join-old mp_get (0 2 1) 1 (0 2 1) __t7Zfl351 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_get (2 0 1) 1 k) (join-old $sup5638x51x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t50Md348 m p r) (exists mp_get (0 2 1) 2 __t50Md348 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5IXI347) (join-old mp_get (0 2 1) 3 (0 2 1) __t50Md348 k __t5IXI347) (let __t51z6350 (band k m)) (cmp lt __t51z6350 __tconst2EWQ349)) (head (emit mp_get_ans (0 1) __t50Md348 v)) map.slog:52 #f)
  class ReadTask535 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex524;  slog::Index** mbranchindex525;  slog::Index** mp_getindex526;  slog::Index** $sup5638x51x0x0x0index527;  slog::Index** mp_getindex528;  slog::Index** mbranchindex529;  slog::Index** mp_getindex530;  slog::Index** mp_getdelta531;  slog::Index** $sup5638x51x0x0x0delta532;  slog::Index** mbranchdelta533;  slog::Index** mp_getdelta534;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_get_ans");
      head_index[0] = readrel537->getIndex(ord536, false);
      outer_rel = db->getRelation("mp_get_ans");
      std::vector<u16> ord538({0, 2, 1});
      slog::Relation* readrel539 = db->getRelation("mp_get");
      mp_getindex524 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({0, 2, 1});
      slog::Relation* readrel541 = db->getRelation("mp_get");
      mp_getdelta531 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({3, 0, 1, 2, 4});
      slog::Relation* readrel543 = db->getRelation("mbranch");
      mbranchindex525 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({2, 0, 1});
      slog::Relation* readrel545 = db->getRelation("mp_get");
      mp_getindex526 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel547 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index527 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel549 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0delta532 = readrel549->getIndex(ord548, true);
      std::vector<u16> ord550({0, 2, 1});
      slog::Relation* readrel551 = db->getRelation("mp_get");
      mp_getindex528 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 3, 4, 0});
      slog::Relation* readrel553 = db->getRelation("mbranch");
      mbranchindex529 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 3, 4, 0});
      slog::Relation* readrel555 = db->getRelation("mbranch");
      mbranchdelta533 = readrel555->getIndex(ord554, true);
      std::vector<u16> ord556({0, 2, 1});
      slog::Relation* readrel557 = db->getRelation("mp_get");
      mp_getindex530 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({0, 2, 1});
      slog::Relation* readrel559 = db->getRelation("mp_get");
      mp_getdelta534 = readrel559->getIndex(ord558, true);
  
    }
    ReadTask535(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c137 = _t[0];
        u64 v_c28 = _t[1];
        slog::join_probe_old<3,1>(mp_getindex524, mp_getdelta531, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m560) {
          u64 v_c115 = m560[1]; u64 v_c4 = m560[2];
          if (!slog::exists_probe<5,1>(mbranchindex525, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_getindex526, std::array<u64,3>{v_c115, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x51x0x0x0index527, $sup5638x51x0x0x0delta532, std::array<u64,6>{v_c115, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,6>& m561) {
            u64 v_c138 = m561[2]; u64 v_c3 = m561[3]; u64 v_c2 = m561[4]; u64 v_c59 = m561[5];
            if (!slog::exists_probe<3,2>(mp_getindex528, std::array<u64,3>{v_c138, v_c115, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex529, mbranchdelta533, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m562) {
              u64 v_c139 = m562[4];
              slog::join_probe_old<3,3>(mp_getindex530, mp_getdelta534, std::array<u64,3>{v_c138, v_c115, v_c139}, [&](const std::array<u64,3>& m563) {
                u64 v_c140 = _prim_band(db, v_c115, v_c3);
                if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c141 = _prim_lt(db, v_c140, v_c136);
                if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c141) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c138, v_c28}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mp_get_ans", _fires);
  
      if (!_done)
      {
        ReadTask535* _cont = new ReadTask535(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask535(db,b), false);
  // (crule (pre (let __trid7eCK1088 const07d7fbed0aba019c07f7eb8a) (let __trel2iiF1089 const20347926ddb307a8e2bdb71b) (let __tcol0Wnu1090 const4e07408562bedb8b60ce05c1)) (scan mp_del_ans __t6EHL288 __v0) (body (join-old mp_del (0 2 1) 1 (0 2 1) __t6EHL288 k l) (exists mp_msk (1 2 0) 1 k) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9pQc287) (join mp_msk_ans (0 1) 2 __t9pQc287 p)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7eCK1088 __trel2iiF1089 __tcol0Wnu1090 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __4RjO1087 p m __v0 r)) map.slog:83 #f)
  class ReadTask576 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex565;  slog::Index** mp_mskindex566;  slog::Index** $sup5638x82x0x0x0index567;  slog::Index** mp_msk_ansindex568;  slog::Index** mp_mskindex569;  slog::Index** mp_msk_ansindex570;  slog::Index** mp_deldelta571;  slog::Index** mp_mskdelta572;
    u32 sid574;  u32 sid573;  u32 sid575;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord577({0, 2, 1});
      slog::Relation* readrel578 = db->getRelation("mp_del");
      mp_delindex565 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 2, 1});
      slog::Relation* readrel580 = db->getRelation("mp_del");
      mp_deldelta571 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("mp_msk");
      mp_mskindex566 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel584 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index567 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 0});
      slog::Relation* readrel586 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex568 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("mp_msk");
      mp_mskindex569 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("mp_msk");
      mp_mskdelta572 = readrel590->getIndex(ord589, true);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex570 = readrel592->getIndex(ord591, false);
      sid574 = db->getRelation("_enum")->getStructId();
      sid573 = db->getRelation("mbranch")->getStructId();
      sid575 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask576(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c143 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c144 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c145 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe_old<3,1>(mp_delindex565, mp_deldelta571, std::array<u64,3>{v_c145, 0, 0}, [&](const std::array<u64,3>& m593) {
          u64 v_c115 = m593[1]; u64 v_c4 = m593[2];
          if (!slog::exists_probe<3,1>(mp_mskindex566, std::array<u64,3>{v_c115, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x82x0x0x0index567, std::array<u64,6>{v_c115, v_c4, 0, 0, 0, 0}, [&](const std::array<u64,6>& m594) {
            u64 v_c106 = m594[2]; u64 v_c3 = m594[3]; u64 v_c2 = m594[4]; u64 v_c59 = m594[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex568, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_mskindex569, mp_mskdelta572, std::array<u64,3>{v_c115, v_c3, 0}, [&](const std::array<u64,3>& m595) {
              u64 v_c146 = m595[2];
              slog::join_probe<2,2>(mp_msk_ansindex570, std::array<u64,2>{v_c146, v_c2}, [&](const std::array<u64,2>& m596) {
                ++_fires;
                if (!((is_struct(v_c59) && (decode_struct_id(v_c59) == sid573 || decode_struct_id(v_c59) == sid574 || decode_struct_id(v_c59) == sid575))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c142, v_c143, v_c144, v_c59}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c3, v_c19, v_c59}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask576* _cont = new ReadTask576(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask576(db,b), false);
  // (crule (pre) (scan let __t5LFI813 x er eb) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t5LFI813 rho t __t5iY7814)) (head (emit $sup70016x92x0x0x0 (1 4 0 2 3 5) eb t __t5iY7814 er rho x)) interp.slog:93 #f)
  class ReadTask599 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex597;  slog::Index** evaldelta598;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord600({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel601 = db->getRelation("$sup70016x92x0x0x0");
      head_index[0] = readrel601->getIndex(ord600, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord602({1, 2, 3, 0});
      slog::Relation* readrel603 = db->getRelation("eval");
      evalindex597 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 2, 3, 0});
      slog::Relation* readrel605 = db->getRelation("eval");
      evaldelta598 = readrel605->getIndex(ord604, true);
  
    }
    ReadTask599(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c147 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c29 = _t[3];
        slog::join_probe_old<4,1>(evalindex597, evaldelta598, std::array<u64,4>{v_c147, 0, 0, 0}, [&](const std::array<u64,4>& m606) {
          u64 v_c12 = m606[1]; u64 v_c14 = m606[2]; u64 v_c148 = m606[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c29, v_c14, v_c148, v_c33, v_c12, v_c13}, std::array<u16,6>{1, 4, 0, 2, 3, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
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
  // (crule (pre (let __trid7OLY1502 const07d7fbed0aba019c07f7eb8a) (let __trel1jWi1503 const3cd26ab9ce3085a816a74a29) (let __tcol6GeY1504 const5feceb66ffc86f38d952786c) (let __trel5QVe1505 const3cd26ab9ce3085a816a74a29) (let __tcol8ch61506 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7OLY1502 __trel1jWi1503 __tcol6GeY1504 (1 2 3 4 0)) (tycheck k (accept int) __trid7OLY1502 __trel5QVe1505 __tcol8ch61506 (1 2 3 4 0)) (mkstruct mp_del (1 2 0) __7b4a1501 l k)) map.slog:83 #f)
  class ReadTask610 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid608;  u32 sid607;  u32 sid609;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_del");
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      sid608 = db->getRelation("_enum")->getStructId();
      sid607 = db->getRelation("mbranch")->getStructId();
      sid609 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask610(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c150 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
      u64 v_c152 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c153 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c106 = _t[0];
        u64 v_c115 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c59 = _t[5];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid607 || decode_struct_id(v_c4) == sid608 || decode_struct_id(v_c4) == sid609))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c149, v_c150, v_c151, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c115)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c149, v_c152, v_c153, v_c115}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c115}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask610* _cont = new ReadTask610(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask610(db,b), false);
  // (crule (pre) (scan mp_del __t7wT8302 __t1w01301 k) (body (join mleaf (0 1 2) 1 __t1w01301 j v) (neq j k)) (head (emit mp_del_ans (0 1) __t7wT8302 __t1w01301)) map.slog:81 #f)
  class ReadTask612 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex611;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord613({0, 1});
      slog::Relation* readrel614 = db->getRelation("mp_del_ans");
      head_index[0] = readrel614->getIndex(ord613, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord615({0, 1, 2});
      slog::Relation* readrel616 = db->getRelation("mleaf");
      mleafindex611 = readrel616->getIndex(ord615, false);
  
    }
    ReadTask612(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c154 = _t[0];
        u64 v_c155 = _t[1];
        u64 v_c115 = _t[2];
        slog::join_probe<3,1>(mleafindex611, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m617) {
          u64 v_c156 = m617[1]; u64 v_c28 = m617[2];
          if (v_c156 == v_c115) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c154, v_c155}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:81", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask612* _cont = new ReadTask612(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask612(db,b), false);
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8pFe907 __t5IbK109 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aO7906 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3hRp908 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4hee909 __t5IbK109 _00024seq2) (exists _enum (1 0) 1 __tconst35Xg1071) (join delta (1 2 0) 2 __tconst3u5R106 _00024seq2 __t8l3B107) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join boolval (0 1) 1 __t5IbK109 b) (letp _00024sql6c1M901 (aslst _00024seq2)) (let chk2YTb1964 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk2YTb1964) (letp chk0ln71965 (lref _00024sql6c1M901 _00024sqc9U0q904)) (eq __t5IbK109 chk0ln71965) (letp chk6jEz1966 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk6jEz1966)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask627 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex618;  slog::Index** $seq_atrindex619;  slog::Index** $seq_atrindex620;  slog::Index** _enumindex621;  slog::Index** deltaindex622;  slog::Index** _enumindex623;  slog::Index** boolvalindex624;  slog::Index** $seq_atrdelta625;  slog::Index** $seq_atrdelta626;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord628({1, 0, 2});
      slog::Relation* readrel629 = db->getRelation("$seq_at");
      driver_index = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({1, 0, 2});
      slog::Relation* readrel631 = db->getRelation("$seq_at");
      $seq_atindex618 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 0, 2});
      slog::Relation* readrel633 = db->getRelation("$seq_atr");
      $seq_atrindex619 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 0, 2});
      slog::Relation* readrel635 = db->getRelation("$seq_atr");
      $seq_atrdelta625 = readrel635->getIndex(ord634, true);
      std::vector<u16> ord636({1, 0, 2});
      slog::Relation* readrel637 = db->getRelation("$seq_atr");
      $seq_atrindex620 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0, 2});
      slog::Relation* readrel639 = db->getRelation("$seq_atr");
      $seq_atrdelta626 = readrel639->getIndex(ord638, true);
      std::vector<u16> ord640({1, 0});
      slog::Relation* readrel641 = db->getRelation("_enum");
      _enumindex621 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("delta");
      deltaindex622 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 0});
      slog::Relation* readrel645 = db->getRelation("_enum");
      _enumindex623 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("boolval");
      boolvalindex624 = readrel647->getIndex(ord646, false);
  
    }
    ReadTask627(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c158 = v_const06abaa100ecef791ce028c56;
      u64 v_c159 = v_constd4735e3a265e16eee03f5971;
      u64 v_c160 = v_const5feceb66ffc86f38d952786c;
      u64 v_c161 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c162 = v_const5feceb66ffc86f38d952786c;
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c165 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c163, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m648) {
        u64 v_c166 = m648[1];
        u64 v_c45 = m648[2];
        if (buckethash(v_c166) != bucket) return;
        slog::join_probe<3,3>($seq_atindex618, std::array<u64,3>{v_c162, v_c166, v_c45}, [&](const std::array<u64,3>& m649) {
          slog::join_probe_old<3,3>($seq_atrindex619, $seq_atrdelta625, std::array<u64,3>{v_c164, v_c166, v_c45}, [&](const std::array<u64,3>& m650) {
            slog::join_probe_old<3,3>($seq_atrindex620, $seq_atrdelta626, std::array<u64,3>{v_c165, v_c166, v_c45}, [&](const std::array<u64,3>& m651) {
              if (!slog::exists_probe<2,1>(_enumindex621, std::array<u64,2>{v_c157, 0})) return;
              slog::join_probe<3,2>(deltaindex622, std::array<u64,3>{v_c158, v_c45, 0}, [&](const std::array<u64,3>& m652) {
                u64 v_c167 = m652[2];
                slog::join_probe<2,1>(_enumindex623, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m653) {
                  u64 v_c168 = m653[1];
                  slog::join_probe<2,1>(boolvalindex624, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m654) {
                    u64 v_c49 = m654[1];
                    bool ok655 = true;
                    u64 v_c169 = _prim_aslst(db, v_c45, &ok655);
                    if (!ok655) return;
                    u64 v_c170 = _prim_llen(db, v_c169);
                    if (v_c170 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c159 != v_c170) return;
                    bool ok656 = true;
                    u64 v_c171 = _prim_lref(db, v_c169, v_c160, &ok656);
                    if (!ok656) return;
                    if (v_c166 != v_c171) return;
                    bool ok657 = true;
                    u64 v_c172 = _prim_lref(db, v_c169, v_c161, &ok657);
                    if (!ok657) return;
                    if (v_c166 != v_c172) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c167});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c168}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask627* _cont = new ReadTask627(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask627(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t15yE714 __v3) (body (join-old mp_hsb_ans (0 1) 1 (0 1) __t15yE714 __v1) (join-old mp_hsb (0 1) 1 (0 1) __t15yE714 __t4JMu715) (join-old $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk7tDj1940 (bxor p0 p1)) (eq __t4JMu715 chk7tDj1940)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t15yE714 __t15yE714 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask664 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex658;  slog::Index** mp_hsbindex659;  slog::Index** $sup5638x25x0x0x1index660;  slog::Index** mp_hsb_ansdelta661;  slog::Index** mp_hsbdelta662;  slog::Index** $sup5638x25x0x0x1delta663;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord665({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel666 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel666->getIndex(ord665, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord667({0, 1});
      slog::Relation* readrel668 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex658 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({0, 1});
      slog::Relation* readrel670 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta661 = readrel670->getIndex(ord669, true);
      std::vector<u16> ord671({0, 1});
      slog::Relation* readrel672 = db->getRelation("mp_hsb");
      mp_hsbindex659 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 1});
      slog::Relation* readrel674 = db->getRelation("mp_hsb");
      mp_hsbdelta662 = readrel674->getIndex(ord673, true);
      std::vector<u16> ord675({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel676 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index660 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel678 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta663 = readrel678->getIndex(ord677, true);
  
    }
    ReadTask664(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c173 = _t[0];
        u64 v_c174 = _t[1];
        slog::join_probe_old<2,1>(mp_hsb_ansindex658, mp_hsb_ansdelta661, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m679) {
          u64 v_c20 = m679[1];
          slog::join_probe_old<2,1>(mp_hsbindex659, mp_hsbdelta662, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m680) {
            u64 v_c175 = m680[1];
            slog::join_all_old<7>($sup5638x25x0x0x1index660, $sup5638x25x0x0x1delta663, [&](const std::array<u64,7>& m681) {
              u64 v_c176 = m681[0]; u64 v_c19 = m681[1]; u64 v_c106 = m681[2]; u64 v_c177 = m681[3]; u64 v_c178 = m681[4]; u64 v_c179 = m681[5]; u64 v_c180 = m681[6];
              u64 v_c181 = _prim_bxor(db, v_c177, v_c178);
              if (v_c181 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c175 != v_c181) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c176, v_c19, v_c174, v_c20, v_c106, v_c173, v_c173, v_c177, v_c178, v_c179, v_c180}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask664* _cont = new ReadTask664(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask664(db,b), false);
  // (crule (pre (let _00024sqc4eJq915 const6b86b273ff34fce19d6b804e) (let _00024sqc7353916 const5feceb66ffc86f38d952786c) (let _00024sqc4F46917 const6b86b273ff34fce19d6b804e) (let _00024sqc6X6r918 const5feceb66ffc86f38d952786c) (let __trid8NVw1490 const3b05f339a47cf251e643e4dd) (let __trel54xq1491 constc8dd3fe14ad7db61de7362fc) (let __tcol3esC1492 constd4735e3a265e16eee03f5971)) (scan mp_put_ans __t8uts322 __v0) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t8uts322 x rho t) (join $sup70016x47x0x0x0 (2 3 4 5 0 1) 3 rho t x xs _00024seq0 __d0) (letp _00024sql9Vv7913 (aslst _00024seq0)) (let _00024sqn4An9914 (llen _00024sql9Vv7913)) (cmp ge _00024sqn4An9914 _00024sqc4eJq915) (letp chk7RIW1912 (lref _00024sql9Vv7913 _00024sqc7353916)) (eq x chk7RIW1912) (let _00024sqp6qIB919 (_0002d _00024sqn4An9914 _00024sqc6X6r918)) (let chk0mPn1913 (lslice _00024sql9Vv7913 _00024sqc4F46917 _00024sqp6qIB919)) (eq xs chk0mPn1913)) (head (tycheck t (accept seq) __trid8NVw1490 __trel54xq1491 __tcol3esC1492 (1 2 3 4 0)) (mkstruct extend_env (1 2 3 0) __3tRX1489 __v0 xs t)) interp.slog:48 #f)
  class ReadTask685 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex682;  slog::Index** $sup70016x47x0x0x0index683;  slog::Index** mp_putdelta684;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("extend_env");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord686({0, 2, 1, 3});
      slog::Relation* readrel687 = db->getRelation("mp_put");
      mp_putindex682 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 2, 1, 3});
      slog::Relation* readrel689 = db->getRelation("mp_put");
      mp_putdelta684 = readrel689->getIndex(ord688, true);
      std::vector<u16> ord690({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel691 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index683 = readrel691->getIndex(ord690, false);
  
    }
    ReadTask685(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c182 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
      u64 v_c184 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c185 = v_const5feceb66ffc86f38d952786c;
      u64 v_c186 = v_const3b05f339a47cf251e643e4dd;
      u64 v_c187 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c189 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex682, mp_putdelta684, std::array<u64,4>{v_c189, 0, 0, 0}, [&](const std::array<u64,4>& m692) {
          u64 v_c13 = m692[1]; u64 v_c12 = m692[2]; u64 v_c14 = m692[3];
          slog::join_probe<6,3>($sup70016x47x0x0x0index683, std::array<u64,6>{v_c12, v_c14, v_c13, 0, 0, 0}, [&](const std::array<u64,6>& m693) {
            u64 v_c15 = m693[3]; u64 v_c16 = m693[4]; u64 v_c106 = m693[5];
            bool ok694 = true;
            u64 v_c190 = _prim_aslst(db, v_c16, &ok694);
            if (!ok694) return;
            u64 v_c191 = _prim_llen(db, v_c190);
            if (v_c191 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c192 = _prim_ge(db, v_c191, v_c182);
            if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (!v_c192) return;
            bool ok696 = true;
            u64 v_c193 = _prim_lref(db, v_c190, v_c183, &ok696);
            if (!ok696) return;
            if (v_c13 != v_c193) return;
            u64 v_c194 = _prim__0002d(db, v_c191, v_c185);
            if (v_c194 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c195 = _prim_lslice(db, v_c190, v_c184, v_c194);
            if (v_c195 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (v_c15 != v_c195) return;
            ++_fires;
            if (!(is_seq(v_c14)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c186, v_c187, v_c188, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c19, v_c15, v_c14}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:mp_put_ans", _fires);
  
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
  // (crule (pre) (scan app __t87KU336 ef es) (body (exists eval (1 2 3 0) 1 __t87KU336) (exists eval (1 2 3 0) 1 ef) (exists eval_args (1 3 2 0) 1 es) (join $sup70016x75x0x0x0 (1 2 0 3 4) 2 ef es __t8Dhb337 rho t) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t8Dhb337 __t87KU336) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t8KmI338) (exists eval_ans (0 1) 1 __t8KmI338) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t24hv340) (exists eval_args_ans (0 1) 1 __t24hv340) (join eval_ans (0 1) 1 __t8KmI338 __t1N6L339) (join eval_args_ans (0 1) 1 __t24hv340 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t1N6L339 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t9Mk1341) (join delta_ans (0 1) 1 __t9Mk1341 v)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask718 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex697;  slog::Index** evalindex698;  slog::Index** eval_argsindex699;  slog::Index** $sup70016x75x0x0x0index700;  slog::Index** evalindex701;  slog::Index** eval_argsindex702;  slog::Index** evalindex703;  slog::Index** eval_ansindex704;  slog::Index** eval_argsindex705;  slog::Index** eval_args_ansindex706;  slog::Index** eval_ansindex707;  slog::Index** eval_args_ansindex708;  slog::Index** deltaindex709;  slog::Index** primindex710;  slog::Index** deltaindex711;  slog::Index** delta_ansindex712;  slog::Index** evaldelta713;  slog::Index** evaldelta714;  slog::Index** eval_argsdelta715;  slog::Index** primdelta716;  slog::Index** deltadelta717;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("eval_ans");
      head_index[0] = readrel720->getIndex(ord719, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord721({1, 2, 3, 0});
      slog::Relation* readrel722 = db->getRelation("eval");
      evalindex697 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 2, 3, 0});
      slog::Relation* readrel724 = db->getRelation("eval");
      evalindex698 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 3, 2, 0});
      slog::Relation* readrel726 = db->getRelation("eval_args");
      eval_argsindex699 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 2, 0, 3, 4});
      slog::Relation* readrel728 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index700 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({2, 3, 0, 1});
      slog::Relation* readrel730 = db->getRelation("eval");
      evalindex701 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({2, 3, 0, 1});
      slog::Relation* readrel732 = db->getRelation("eval");
      evaldelta713 = readrel732->getIndex(ord731, true);
      std::vector<u16> ord733({1, 3, 2, 0});
      slog::Relation* readrel734 = db->getRelation("eval_args");
      eval_argsindex702 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 2, 3, 0});
      slog::Relation* readrel736 = db->getRelation("eval");
      evalindex703 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 2, 3, 0});
      slog::Relation* readrel738 = db->getRelation("eval");
      evaldelta714 = readrel738->getIndex(ord737, true);
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("eval_ans");
      eval_ansindex704 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 3, 2, 0});
      slog::Relation* readrel742 = db->getRelation("eval_args");
      eval_argsindex705 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 3, 2, 0});
      slog::Relation* readrel744 = db->getRelation("eval_args");
      eval_argsdelta715 = readrel744->getIndex(ord743, true);
      std::vector<u16> ord745({0, 1});
      slog::Relation* readrel746 = db->getRelation("eval_args_ans");
      eval_args_ansindex706 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({0, 1});
      slog::Relation* readrel748 = db->getRelation("eval_ans");
      eval_ansindex707 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({0, 1});
      slog::Relation* readrel750 = db->getRelation("eval_args_ans");
      eval_args_ansindex708 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({2, 0, 1});
      slog::Relation* readrel752 = db->getRelation("delta");
      deltaindex709 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({0, 1});
      slog::Relation* readrel754 = db->getRelation("prim");
      primindex710 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({0, 1});
      slog::Relation* readrel756 = db->getRelation("prim");
      primdelta716 = readrel756->getIndex(ord755, true);
      std::vector<u16> ord757({1, 2, 0});
      slog::Relation* readrel758 = db->getRelation("delta");
      deltaindex711 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 2, 0});
      slog::Relation* readrel760 = db->getRelation("delta");
      deltadelta717 = readrel760->getIndex(ord759, true);
      std::vector<u16> ord761({0, 1});
      slog::Relation* readrel762 = db->getRelation("delta_ans");
      delta_ansindex712 = readrel762->getIndex(ord761, false);
  
    }
    ReadTask718(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c105 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex697, std::array<u64,4>{v_c196, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex698, std::array<u64,4>{v_c104, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex699, std::array<u64,4>{v_c105, 0, 0, 0})) return;
        slog::join_probe<5,2>($sup70016x75x0x0x0index700, std::array<u64,5>{v_c104, v_c105, 0, 0, 0}, [&](const std::array<u64,5>& m763) {
          u64 v_c197 = m763[2]; u64 v_c12 = m763[3]; u64 v_c14 = m763[4];
          slog::join_probe_old<4,4>(evalindex701, evaldelta713, std::array<u64,4>{v_c12, v_c14, v_c197, v_c196}, [&](const std::array<u64,4>& m764) {
            if (!slog::exists_probe<4,3>(eval_argsindex702, std::array<u64,4>{v_c105, v_c14, v_c12, 0})) return;
            slog::join_probe_old<4,3>(evalindex703, evaldelta714, std::array<u64,4>{v_c104, v_c12, v_c14, 0}, [&](const std::array<u64,4>& m765) {
              u64 v_c198 = m765[3];
              if (!slog::exists_probe<2,1>(eval_ansindex704, std::array<u64,2>{v_c198, 0})) return;
              slog::join_probe_old<4,3>(eval_argsindex705, eval_argsdelta715, std::array<u64,4>{v_c105, v_c14, v_c12, 0}, [&](const std::array<u64,4>& m766) {
                u64 v_c199 = m766[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex706, std::array<u64,2>{v_c199, 0})) return;
                slog::join_probe<2,1>(eval_ansindex707, std::array<u64,2>{v_c198, 0}, [&](const std::array<u64,2>& m767) {
                  u64 v_c200 = m767[1];
                  slog::join_probe<2,1>(eval_args_ansindex708, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m768) {
                    u64 v_c110 = m768[1];
                    if (!slog::exists_probe<3,1>(deltaindex709, std::array<u64,3>{v_c110, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex710, primdelta716, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m769) {
                      u64 v_c201 = m769[1];
                      slog::join_probe_old<3,2>(deltaindex711, deltadelta717, std::array<u64,3>{v_c201, v_c110, 0}, [&](const std::array<u64,3>& m770) {
                        u64 v_c202 = m770[2];
                        slog::join_probe<2,1>(delta_ansindex712, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m771) {
                          u64 v_c28 = m771[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c197, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask718* _cont = new ReadTask718(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask718(db,b), false);
  // (crule (pre (let __tconst4KHb101 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t58FV103 __t9soq102 k) (body (join mleaf (0 1 2) 1 __t9soq102 j v) (neq j k)) (head (emit mp_has0_ans (0 1) __t58FV103 __tconst4KHb101)) map.slog:59 #f)
  class ReadTask773 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex772;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord774({0, 1});
      slog::Relation* readrel775 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel775->getIndex(ord774, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord776({0, 1, 2});
      slog::Relation* readrel777 = db->getRelation("mleaf");
      mleafindex772 = readrel777->getIndex(ord776, false);
  
    }
    ReadTask773(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c205 = _t[1];
        u64 v_c115 = _t[2];
        slog::join_probe<3,1>(mleafindex772, std::array<u64,3>{v_c205, 0, 0}, [&](const std::array<u64,3>& m778) {
          u64 v_c156 = m778[1]; u64 v_c28 = m778[2];
          if (v_c156 == v_c115) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c204, v_c203}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:59", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask773* _cont = new ReadTask773(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask773(db,b), false);
  // (crule (pre (let __trid6E3w1423 consta2d3b5b64cd0c50598de1133) (let __trel5ChB1424 constdd7bbf31ce5f578b9805e840) (let __tcol8AJ51425 const5feceb66ffc86f38d952786c) (let __trel09Kq1426 constdd7bbf31ce5f578b9805e840) (let __tcol0gh41427 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid6E3w1423 __trel5ChB1424 __tcol8AJ51425 (1 2 3 4 0)) (tycheck m (accept int) __trid6E3w1423 __trel09Kq1426 __tcol0gh41427 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __2HTL1422 k m)) map.slog:61 #f)
  class ReadTask779 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
  
    }
    ReadTask779(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_consta2d3b5b64cd0c50598de1133;
      u64 v_c207 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c106 = _t[0];
        u64 v_c115 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c59 = _t[5];
        ++_fires;
        if (!(is_int(v_c115)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c206, v_c207, v_c208, v_c115}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c206, v_c209, v_c210, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c115, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask779* _cont = new ReadTask779(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask779(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t78qG683 q) (body (exists $sup5638x107x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t78qG683 q) (exists $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists mbranch (1 2 3 4 0) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t78qG683 p n) (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists mbranch (1 2 3 4 0) 2 q n) (exists mbranch (1 2 3 4 0) 1 p) (join-old $sup5638x107x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t78qG683 n p q __t5Sgr680 l m r u v) (cmp lt m n) (join-old $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t5Sgr680 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 1 v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t105R678) (exists mp_union (2 0 1) 2 __t105R678 __t5Sgr680) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Sgr680 __t0Aux684 __t105R678) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join-old mp_union_ans (0 1) 1 (0 1) __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask805 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index780;  slog::Index** $sup5638x107x0x0x0index781;  slog::Index** mbranchindex782;  slog::Index** mp_mskindex783;  slog::Index** $sup5638x107x0x0x0index784;  slog::Index** mbranchindex785;  slog::Index** mbranchindex786;  slog::Index** $sup5638x107x0x0x1index787;  slog::Index** $sup5638x107x0x0x0index788;  slog::Index** mbranchindex789;  slog::Index** mp_unionindex790;  slog::Index** mbranchindex791;  slog::Index** mp_unionindex792;  slog::Index** mbranchindex793;  slog::Index** mp_unionindex794;  slog::Index** mp_unionindex795;  slog::Index** mp_union_ansindex796;  slog::Index** mp_mskdelta797;  slog::Index** $sup5638x107x0x0x1delta798;  slog::Index** $sup5638x107x0x0x0delta799;  slog::Index** mbranchdelta800;  slog::Index** mbranchdelta801;  slog::Index** mp_uniondelta802;  slog::Index** mp_uniondelta803;  slog::Index** mp_union_ansdelta804;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord806({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel807 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index780 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel809 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index781 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 3, 4, 0});
      slog::Relation* readrel811 = db->getRelation("mbranch");
      mbranchindex782 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1, 2});
      slog::Relation* readrel813 = db->getRelation("mp_msk");
      mp_mskindex783 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 1, 2});
      slog::Relation* readrel815 = db->getRelation("mp_msk");
      mp_mskdelta797 = readrel815->getIndex(ord814, true);
      std::vector<u16> ord816({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel817 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index784 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 3, 4, 0});
      slog::Relation* readrel819 = db->getRelation("mbranch");
      mbranchindex785 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 3, 4, 0});
      slog::Relation* readrel821 = db->getRelation("mbranch");
      mbranchindex786 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel823 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index787 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel825 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta798 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel827 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index788 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel829 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0delta799 = readrel829->getIndex(ord828, true);
      std::vector<u16> ord830({1, 2, 3, 4, 0});
      slog::Relation* readrel831 = db->getRelation("mbranch");
      mbranchindex789 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({2, 0, 1});
      slog::Relation* readrel833 = db->getRelation("mp_union");
      mp_unionindex790 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 3, 4, 0});
      slog::Relation* readrel835 = db->getRelation("mbranch");
      mbranchindex791 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({1, 2, 3, 4, 0});
      slog::Relation* readrel837 = db->getRelation("mbranch");
      mbranchdelta800 = readrel837->getIndex(ord836, true);
      std::vector<u16> ord838({2, 0, 1});
      slog::Relation* readrel839 = db->getRelation("mp_union");
      mp_unionindex792 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 3, 4, 0});
      slog::Relation* readrel841 = db->getRelation("mbranch");
      mbranchindex793 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 3, 4, 0});
      slog::Relation* readrel843 = db->getRelation("mbranch");
      mbranchdelta801 = readrel843->getIndex(ord842, true);
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("mp_union");
      mp_unionindex794 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({0, 1, 2});
      slog::Relation* readrel847 = db->getRelation("mp_union");
      mp_uniondelta802 = readrel847->getIndex(ord846, true);
      std::vector<u16> ord848({1, 2, 0});
      slog::Relation* readrel849 = db->getRelation("mp_union");
      mp_unionindex795 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 2, 0});
      slog::Relation* readrel851 = db->getRelation("mp_union");
      mp_uniondelta803 = readrel851->getIndex(ord850, true);
      std::vector<u16> ord852({0, 1});
      slog::Relation* readrel853 = db->getRelation("mp_union_ans");
      mp_union_ansindex796 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({0, 1});
      slog::Relation* readrel855 = db->getRelation("mp_union_ans");
      mp_union_ansdelta804 = readrel855->getIndex(ord854, true);
  
    }
    ReadTask805(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c57 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index780, std::array<u64,10>{v_c55, v_c57, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index781, std::array<u64,9>{v_c57, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex782, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex783, mp_mskdelta797, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m856) {
          u64 v_c2 = m856[1]; u64 v_c56 = m856[2];
          if (!slog::exists_probe<9,3>($sup5638x107x0x0x0index784, std::array<u64,9>{v_c56, v_c2, v_c57, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex785, std::array<u64,5>{v_c57, v_c56, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex786, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x107x0x0x1index787, $sup5638x107x0x0x1delta798, std::array<u64,10>{v_c55, v_c56, v_c2, v_c57, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m857) {
            u64 v_c58 = m857[4]; u64 v_c4 = m857[5]; u64 v_c3 = m857[6]; u64 v_c59 = m857[7]; u64 v_c60 = m857[8]; u64 v_c28 = m857[9];
            u64 v_c211 = _prim_lt(db, v_c3, v_c56);
            if (v_c211 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c211) return;
            slog::join_probe_old<9,9>($sup5638x107x0x0x0index788, $sup5638x107x0x0x0delta799, std::array<u64,9>{v_c57, v_c56, v_c60, v_c28, v_c58, v_c4, v_c3, v_c2, v_c59}, [&](const std::array<u64,9>& m859) {
              if (!slog::exists_probe<5,4>(mbranchindex789, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex790, std::array<u64,3>{v_c28, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex791, mbranchdelta800, std::array<u64,5>{v_c57, v_c56, v_c60, v_c28, 0}, [&](const std::array<u64,5>& m860) {
                u64 v_c62 = m860[4];
                if (!slog::exists_probe<3,2>(mp_unionindex792, std::array<u64,3>{v_c62, v_c58, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex793, mbranchdelta801, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m861) {
                  u64 v_c63 = m861[4];
                  slog::join_probe_old<3,3>(mp_unionindex794, mp_uniondelta802, std::array<u64,3>{v_c58, v_c63, v_c62}, [&](const std::array<u64,3>& m862) {
                    slog::join_probe_old<3,2>(mp_unionindex795, mp_uniondelta803, std::array<u64,3>{v_c63, v_c28, 0}, [&](const std::array<u64,3>& m863) {
                      u64 v_c64 = m863[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex796, mp_union_ansdelta804, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m864) {
                        u64 v_c19 = m864[1];
                        u64 v_c65 = _prim_band(db, v_c2, v_c56);
                        if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c212 = _prim_gt(db, v_c65, v_c54);
                        if (v_c212 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c212) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c58, v_c19, v_c56, v_c57, v_c60});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c56, v_c60, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask805* _cont = new ReadTask805(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask805(db,b), false);
  // (crule (pre) (scan mp_msk __t0MS8397 k m) (body (exists $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t0MS8397 __v0) (join $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 k m __t5Y7y396 l p r) (neq p __v0) (exists mp_del (0 2 1) 2 __t5Y7y396 k) (join mbranch (1 2 3 4 0) 4 p m l r __t8pu9395) (join mp_del (0 2 1) 3 __t5Y7y396 k __t8pu9395)) (head (emit mp_del_ans (0 1) __t5Y7y396 __t8pu9395)) map.slog:82 #f)
  class ReadTask874 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x81x0x0x0index866;  slog::Index** mbranchindex867;  slog::Index** mp_delindex868;  slog::Index** mp_msk_ansindex869;  slog::Index** $sup5638x81x0x0x0index870;  slog::Index** mp_delindex871;  slog::Index** mbranchindex872;  slog::Index** mp_delindex873;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("mp_del_ans");
      head_index[0] = readrel876->getIndex(ord875, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord877({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel878 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index866 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({2, 0, 1, 3, 4});
      slog::Relation* readrel880 = db->getRelation("mbranch");
      mbranchindex867 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({2, 0, 1});
      slog::Relation* readrel882 = db->getRelation("mp_del");
      mp_delindex868 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 1});
      slog::Relation* readrel884 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex869 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel886 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index870 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({0, 2, 1});
      slog::Relation* readrel888 = db->getRelation("mp_del");
      mp_delindex871 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 3, 4, 0});
      slog::Relation* readrel890 = db->getRelation("mbranch");
      mbranchindex872 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({0, 2, 1});
      slog::Relation* readrel892 = db->getRelation("mp_del");
      mp_delindex873 = readrel892->getIndex(ord891, false);
  
    }
    ReadTask874(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c213 = _t[0];
        u64 v_c115 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x81x0x0x0index866, std::array<u64,6>{v_c115, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex867, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex868, std::array<u64,3>{v_c115, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex869, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m893) {
          u64 v_c19 = m893[1];
          slog::join_probe<6,2>($sup5638x81x0x0x0index870, std::array<u64,6>{v_c115, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,6>& m894) {
            u64 v_c214 = m894[2]; u64 v_c4 = m894[3]; u64 v_c2 = m894[4]; u64 v_c59 = m894[5];
            if (v_c2 == v_c19) return;
            if (!slog::exists_probe<3,2>(mp_delindex871, std::array<u64,3>{v_c214, v_c115, 0})) return;
            slog::join_probe<5,4>(mbranchindex872, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m895) {
              u64 v_c215 = m895[4];
              slog::join_probe<3,3>(mp_delindex873, std::array<u64,3>{v_c214, v_c115, v_c215}, [&](const std::array<u64,3>& m896) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c215}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask874* _cont = new ReadTask874(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask874(db,b), false);
  // (crule (pre) (scan $sup70016x92x0x0x0 __t5vg0669 eb er rho t x) (body (exists eval (1 2 3 0) 3 er rho t) (exists mp_put (1 2 3 0) 3 rho x t) (exists let (1 2 3 0) 3 x er eb) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval (3 1 0 2) 2 t eb) (join-old $sup70016x92x0x0x1 (0 6 7 4 5 9 1 2 3 8) 6 (0 6 7 4 5 9 1 2 3 8) __t5vg0669 rho t eb er x __t7GLg670 __t0mp6672 __v0 vr) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (1 2 3 0) 3 eb __v0 t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join-old let (1 2 3 0) 3 (1 2 3 0) x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask920 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex897;  slog::Index** mp_putindex898;  slog::Index** letindex899;  slog::Index** evalindex900;  slog::Index** evalindex901;  slog::Index** $sup70016x92x0x0x1index902;  slog::Index** evalindex903;  slog::Index** mp_putindex904;  slog::Index** evalindex905;  slog::Index** eval_ansindex906;  slog::Index** mp_put_ansindex907;  slog::Index** letindex908;  slog::Index** evalindex909;  slog::Index** evalindex910;  slog::Index** eval_ansindex911;  slog::Index** mp_put_ansindex912;  slog::Index** eval_ansindex913;  slog::Index** $sup70016x92x0x0x1delta914;  slog::Index** evaldelta915;  slog::Index** mp_putdelta916;  slog::Index** letdelta917;  slog::Index** evaldelta918;  slog::Index** evaldelta919;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("eval_ans");
      head_index[0] = readrel922->getIndex(ord921, false);
      outer_rel = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord923({1, 2, 3, 0});
      slog::Relation* readrel924 = db->getRelation("eval");
      evalindex897 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({1, 2, 3, 0});
      slog::Relation* readrel926 = db->getRelation("mp_put");
      mp_putindex898 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({1, 2, 3, 0});
      slog::Relation* readrel928 = db->getRelation("let");
      letindex899 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({2, 3, 0, 1});
      slog::Relation* readrel930 = db->getRelation("eval");
      evalindex900 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({3, 1, 0, 2});
      slog::Relation* readrel932 = db->getRelation("eval");
      evalindex901 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel934 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index902 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel936 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1delta914 = readrel936->getIndex(ord935, true);
      std::vector<u16> ord937({2, 3, 0, 1});
      slog::Relation* readrel938 = db->getRelation("eval");
      evalindex903 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({2, 3, 0, 1});
      slog::Relation* readrel940 = db->getRelation("eval");
      evaldelta915 = readrel940->getIndex(ord939, true);
      std::vector<u16> ord941({0, 2, 1, 3});
      slog::Relation* readrel942 = db->getRelation("mp_put");
      mp_putindex904 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({0, 2, 1, 3});
      slog::Relation* readrel944 = db->getRelation("mp_put");
      mp_putdelta916 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({1, 2, 3, 0});
      slog::Relation* readrel946 = db->getRelation("eval");
      evalindex905 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({0, 1});
      slog::Relation* readrel948 = db->getRelation("eval_ans");
      eval_ansindex906 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({0, 1});
      slog::Relation* readrel950 = db->getRelation("mp_put_ans");
      mp_put_ansindex907 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 2, 3, 0});
      slog::Relation* readrel952 = db->getRelation("let");
      letindex908 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 2, 3, 0});
      slog::Relation* readrel954 = db->getRelation("let");
      letdelta917 = readrel954->getIndex(ord953, true);
      std::vector<u16> ord955({2, 3, 0, 1});
      slog::Relation* readrel956 = db->getRelation("eval");
      evalindex909 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({2, 3, 0, 1});
      slog::Relation* readrel958 = db->getRelation("eval");
      evaldelta918 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({1, 2, 3, 0});
      slog::Relation* readrel960 = db->getRelation("eval");
      evalindex910 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 3, 0});
      slog::Relation* readrel962 = db->getRelation("eval");
      evaldelta919 = readrel962->getIndex(ord961, true);
      std::vector<u16> ord963({0, 1});
      slog::Relation* readrel964 = db->getRelation("eval_ans");
      eval_ansindex911 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("mp_put_ans");
      mp_put_ansindex912 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("eval_ans");
      eval_ansindex913 = readrel968->getIndex(ord967, false);
  
    }
    ReadTask920(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c14 = _t[4];
        u64 v_c13 = _t[5];
        if (!slog::exists_probe<4,3>(evalindex897, std::array<u64,4>{v_c33, v_c12, v_c14, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex898, std::array<u64,4>{v_c12, v_c13, v_c14, 0})) return;
        if (!slog::exists_probe<4,3>(letindex899, std::array<u64,4>{v_c13, v_c33, v_c29, 0})) return;
        if (!slog::exists_probe<4,3>(evalindex900, std::array<u64,4>{v_c12, v_c14, v_c31, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex901, std::array<u64,4>{v_c14, v_c29, 0, 0})) return;
        slog::join_probe_old<10,6>($sup70016x92x0x0x1index902, $sup70016x92x0x0x1delta914, std::array<u64,10>{v_c31, v_c12, v_c14, v_c29, v_c33, v_c13, 0, 0, 0, 0}, [&](const std::array<u64,10>& m969) {
          u64 v_c32 = m969[6]; u64 v_c30 = m969[7]; u64 v_c19 = m969[8]; u64 v_c34 = m969[9];
          slog::join_probe_old<4,4>(evalindex903, evaldelta915, std::array<u64,4>{v_c12, v_c14, v_c32, v_c33}, [&](const std::array<u64,4>& m970) {
            slog::join_probe_old<4,4>(mp_putindex904, mp_putdelta916, std::array<u64,4>{v_c30, v_c13, v_c12, v_c14}, [&](const std::array<u64,4>& m971) {
              if (!slog::exists_probe<4,3>(evalindex905, std::array<u64,4>{v_c29, v_c19, v_c14, 0})) return;
              if (!slog::exists_probe<2,2>(eval_ansindex906, std::array<u64,2>{v_c32, v_c34})) return;
              if (!slog::exists_probe<2,2>(mp_put_ansindex907, std::array<u64,2>{v_c30, v_c19})) return;
              slog::join_probe_old<4,3>(letindex908, letdelta917, std::array<u64,4>{v_c13, v_c33, v_c29, 0}, [&](const std::array<u64,4>& m972) {
                u64 v_c35 = m972[3];
                slog::join_probe_old<4,4>(evalindex909, evaldelta918, std::array<u64,4>{v_c12, v_c14, v_c31, v_c35}, [&](const std::array<u64,4>& m973) {
                  slog::join_probe_old<4,3>(evalindex910, evaldelta919, std::array<u64,4>{v_c29, v_c19, v_c14, 0}, [&](const std::array<u64,4>& m974) {
                    u64 v_c27 = m974[3];
                    slog::join_probe<2,2>(eval_ansindex911, std::array<u64,2>{v_c32, v_c34}, [&](const std::array<u64,2>& m975) {
                      slog::join_probe<2,2>(mp_put_ansindex912, std::array<u64,2>{v_c30, v_c19}, [&](const std::array<u64,2>& m976) {
                        slog::join_probe<2,1>(eval_ansindex913, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m977) {
                          u64 v_c28 = m977[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask920* _cont = new ReadTask920(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask920(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t8vNz312 k m) (body (exists $sup5638x82x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (2 1 4 0 3) 1 m) (join mp_msk_ans (0 1) 1 __t8vNz312 p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_bld (1 2 3 4 0) 2 p m) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __t0iNt308 l r) (exists mp_del (0 2 1) 2 __t0iNt308 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_del (1 2 0) 2 l k) (join mbranch (1 2 3 4 0) 4 p m l r __t62gM307) (join mp_del (0 2 1) 3 __t0iNt308 k __t62gM307) (join mp_bld (2 1 4 0 3) 3 m p r __t8pI6311 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join mp_del_ans (0 1) 2 __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask998 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index978;  slog::Index** mbranchindex979;  slog::Index** mp_delindex980;  slog::Index** mp_bldindex981;  slog::Index** mp_msk_ansindex982;  slog::Index** mbranchindex983;  slog::Index** mp_bldindex984;  slog::Index** $sup5638x82x0x0x0index985;  slog::Index** mp_delindex986;  slog::Index** mp_bldindex987;  slog::Index** mp_delindex988;  slog::Index** mbranchindex989;  slog::Index** mp_delindex990;  slog::Index** mp_bldindex991;  slog::Index** mp_del_ansindex992;  slog::Index** mp_bld_ansindex993;  slog::Index** mp_delindex994;  slog::Index** mp_del_ansindex995;  slog::Index** mp_bld_ansindex996;  slog::Index** mp_deldelta997;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord999({0, 1});
      slog::Relation* readrel1000 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1000->getIndex(ord999, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1001({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1002 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index978 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({2, 0, 1, 3, 4});
      slog::Relation* readrel1004 = db->getRelation("mbranch");
      mbranchindex979 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({2, 0, 1});
      slog::Relation* readrel1006 = db->getRelation("mp_del");
      mp_delindex980 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({2, 1, 4, 0, 3});
      slog::Relation* readrel1008 = db->getRelation("mp_bld");
      mp_bldindex981 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({0, 1});
      slog::Relation* readrel1010 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex982 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 3, 4, 0});
      slog::Relation* readrel1012 = db->getRelation("mbranch");
      mbranchindex983 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 2, 3, 4, 0});
      slog::Relation* readrel1014 = db->getRelation("mp_bld");
      mp_bldindex984 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1016 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index985 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({0, 2, 1});
      slog::Relation* readrel1018 = db->getRelation("mp_del");
      mp_delindex986 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({2, 1, 4, 0, 3});
      slog::Relation* readrel1020 = db->getRelation("mp_bld");
      mp_bldindex987 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 0});
      slog::Relation* readrel1022 = db->getRelation("mp_del");
      mp_delindex988 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 3, 4, 0});
      slog::Relation* readrel1024 = db->getRelation("mbranch");
      mbranchindex989 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({0, 2, 1});
      slog::Relation* readrel1026 = db->getRelation("mp_del");
      mp_delindex990 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({2, 1, 4, 0, 3});
      slog::Relation* readrel1028 = db->getRelation("mp_bld");
      mp_bldindex991 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 0});
      slog::Relation* readrel1030 = db->getRelation("mp_del_ans");
      mp_del_ansindex992 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({0, 1});
      slog::Relation* readrel1032 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex993 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 2, 0});
      slog::Relation* readrel1034 = db->getRelation("mp_del");
      mp_delindex994 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 0});
      slog::Relation* readrel1036 = db->getRelation("mp_del");
      mp_deldelta997 = readrel1036->getIndex(ord1035, true);
      std::vector<u16> ord1037({0, 1});
      slog::Relation* readrel1038 = db->getRelation("mp_del_ans");
      mp_del_ansindex995 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1});
      slog::Relation* readrel1040 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex996 = readrel1040->getIndex(ord1039, false);
  
    }
    ReadTask998(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c130 = _t[0];
        u64 v_c115 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index978, std::array<u64,6>{v_c115, v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex979, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex980, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex981, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex982, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m1041) {
          u64 v_c2 = m1041[1];
          if (!slog::exists_probe<5,2>(mbranchindex983, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex984, std::array<u64,5>{v_c2, v_c3, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x82x0x0x0index985, std::array<u64,6>{v_c115, v_c3, v_c2, 0, 0, 0}, [&](const std::array<u64,6>& m1042) {
            u64 v_c129 = m1042[3]; u64 v_c4 = m1042[4]; u64 v_c59 = m1042[5];
            if (!slog::exists_probe<3,2>(mp_delindex986, std::array<u64,3>{v_c129, v_c115, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex987, std::array<u64,5>{v_c3, v_c2, v_c59, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex988, std::array<u64,3>{v_c4, v_c115, 0})) return;
            slog::join_probe<5,4>(mbranchindex989, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, 0}, [&](const std::array<u64,5>& m1043) {
              u64 v_c128 = m1043[4];
              slog::join_probe<3,3>(mp_delindex990, std::array<u64,3>{v_c129, v_c115, v_c128}, [&](const std::array<u64,3>& m1044) {
                slog::join_probe<5,3>(mp_bldindex991, std::array<u64,5>{v_c3, v_c2, v_c59, 0, 0}, [&](const std::array<u64,5>& m1045) {
                  u64 v_c127 = m1045[3]; u64 v_c19 = m1045[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex992, std::array<u64,2>{v_c19, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex993, std::array<u64,2>{v_c127, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex994, mp_deldelta997, std::array<u64,3>{v_c4, v_c115, 0}, [&](const std::array<u64,3>& m1046) {
                    u64 v_c131 = m1046[2];
                    slog::join_probe<2,2>(mp_del_ansindex995, std::array<u64,2>{v_c131, v_c19}, [&](const std::array<u64,2>& m1047) {
                      slog::join_probe<2,1>(mp_bld_ansindex996, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m1048) {
                        u64 v_c120 = m1048[1];
                        u64 v_c132 = _prim_band(db, v_c115, v_c3);
                        if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c216 = _prim_lt(db, v_c132, v_c126);
                        if (v_c216 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c216) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c120}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask998* _cont = new ReadTask998(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask998(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t6Aa9325 __t0WBy324 k) (body (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join $sup5638x60x0x0x0 (0 1 2 3 4 5) 2 __t6Aa9325 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t0WBy324) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t81Rn328) (exists mp_has0_ans (0 1) 1 __t81Rn328) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2ONI329) (join mp_msk_ans (0 1) 2 __t2ONI329 p) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask1063 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1050;  slog::Index** mp_mskindex1051;  slog::Index** $sup5638x60x0x0x0index1052;  slog::Index** mbranchindex1053;  slog::Index** mp_mskindex1054;  slog::Index** mp_msk_ansindex1055;  slog::Index** mp_has0index1056;  slog::Index** mp_has0_ansindex1057;  slog::Index** mp_mskindex1058;  slog::Index** mp_msk_ansindex1059;  slog::Index** mp_has0_ansindex1060;  slog::Index** mp_has0delta1061;  slog::Index** mp_mskdelta1062;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1064({0, 1});
      slog::Relation* readrel1065 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1065->getIndex(ord1064, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord1066({2, 0, 1});
      slog::Relation* readrel1067 = db->getRelation("mp_has0");
      mp_has0index1050 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({1, 2, 0});
      slog::Relation* readrel1069 = db->getRelation("mp_msk");
      mp_mskindex1051 = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1071 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index1052 = readrel1071->getIndex(ord1070, false);
      std::vector<u16> ord1072({1, 2, 3, 4, 0});
      slog::Relation* readrel1073 = db->getRelation("mbranch");
      mbranchindex1053 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 2, 0});
      slog::Relation* readrel1075 = db->getRelation("mp_msk");
      mp_mskindex1054 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({1, 0});
      slog::Relation* readrel1077 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1055 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 2, 0});
      slog::Relation* readrel1079 = db->getRelation("mp_has0");
      mp_has0index1056 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 2, 0});
      slog::Relation* readrel1081 = db->getRelation("mp_has0");
      mp_has0delta1061 = readrel1081->getIndex(ord1080, true);
      std::vector<u16> ord1082({0, 1});
      slog::Relation* readrel1083 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1057 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 0});
      slog::Relation* readrel1085 = db->getRelation("mp_msk");
      mp_mskindex1058 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 2, 0});
      slog::Relation* readrel1087 = db->getRelation("mp_msk");
      mp_mskdelta1062 = readrel1087->getIndex(ord1086, true);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1059 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({0, 1});
      slog::Relation* readrel1091 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1060 = readrel1091->getIndex(ord1090, false);
  
    }
    ReadTask1063(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c218 = _t[0];
        u64 v_c219 = _t[1];
        u64 v_c115 = _t[2];
        if (!slog::exists_probe<3,1>(mp_has0index1050, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1051, std::array<u64,3>{v_c115, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x60x0x0x0index1052, std::array<u64,6>{v_c218, v_c115, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1092) {
          u64 v_c4 = m1092[2]; u64 v_c3 = m1092[3]; u64 v_c2 = m1092[4]; u64 v_c59 = m1092[5];
          slog::join_probe<5,5>(mbranchindex1053, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, v_c219}, [&](const std::array<u64,5>& m1093) {
            if (!slog::exists_probe<3,2>(mp_mskindex1054, std::array<u64,3>{v_c115, v_c3, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1055, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index1056, mp_has0delta1061, std::array<u64,3>{v_c4, v_c115, 0}, [&](const std::array<u64,3>& m1094) {
              u64 v_c220 = m1094[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex1057, std::array<u64,2>{v_c220, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1058, mp_mskdelta1062, std::array<u64,3>{v_c115, v_c3, 0}, [&](const std::array<u64,3>& m1095) {
                u64 v_c221 = m1095[2];
                slog::join_probe<2,2>(mp_msk_ansindex1059, std::array<u64,2>{v_c221, v_c2}, [&](const std::array<u64,2>& m1096) {
                  slog::join_probe<2,1>(mp_has0_ansindex1060, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1097) {
                    u64 v_c222 = m1097[1];
                    u64 v_c223 = _prim_band(db, v_c115, v_c3);
                    if (v_c223 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c224 = _prim_lt(db, v_c223, v_c217);
                    if (v_c224 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c224) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c218, v_c222}, std::array<u16,2>{0, 1});
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
        ReadTask1063* _cont = new ReadTask1063(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1063(db,b), false);
  // (crule (pre) (scan let __t2w2P668 x er eb) (body (exists $sup70016x92x0x0x1 (4 5 9 0 1 2 3 6 7 8) 3 eb er x) (exists eval (1 2 3 0) 1 __t2w2P668) (exists eval (1 2 3 0) 1 er) (exists mp_put (2 3 0 1) 1 x) (exists eval (1 2 3 0) 1 eb) (join $sup70016x92x0x0x0 (1 2 5 0 3 4) 3 eb er x __t5vg0669 rho t) (exists eval (2 3 0 1) 4 rho t __t5vg0669 __t2w2P668) (exists eval (1 2 3 0) 3 er rho t) (exists mp_put (1 2 3 0) 3 rho x t) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x92x0x0x1 (0 6 7 4 5 9 1 2 3 8) 6 __t5vg0669 rho t eb er x __t7GLg670 __t0mp6672 __v0 vr) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask1123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index1099;  slog::Index** evalindex1100;  slog::Index** evalindex1101;  slog::Index** mp_putindex1102;  slog::Index** evalindex1103;  slog::Index** $sup70016x92x0x0x0index1104;  slog::Index** evalindex1105;  slog::Index** evalindex1106;  slog::Index** mp_putindex1107;  slog::Index** evalindex1108;  slog::Index** $sup70016x92x0x0x1index1109;  slog::Index** evalindex1110;  slog::Index** evalindex1111;  slog::Index** mp_putindex1112;  slog::Index** eval_ansindex1113;  slog::Index** mp_put_ansindex1114;  slog::Index** evalindex1115;  slog::Index** eval_ansindex1116;  slog::Index** mp_put_ansindex1117;  slog::Index** eval_ansindex1118;  slog::Index** evaldelta1119;  slog::Index** evaldelta1120;  slog::Index** mp_putdelta1121;  slog::Index** evaldelta1122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1124({0, 1});
      slog::Relation* readrel1125 = db->getRelation("eval_ans");
      head_index[0] = readrel1125->getIndex(ord1124, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord1126({4, 5, 9, 0, 1, 2, 3, 6, 7, 8});
      slog::Relation* readrel1127 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1099 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 2, 3, 0});
      slog::Relation* readrel1129 = db->getRelation("eval");
      evalindex1100 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 2, 3, 0});
      slog::Relation* readrel1131 = db->getRelation("eval");
      evalindex1101 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({2, 3, 0, 1});
      slog::Relation* readrel1133 = db->getRelation("mp_put");
      mp_putindex1102 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 2, 3, 0});
      slog::Relation* readrel1135 = db->getRelation("eval");
      evalindex1103 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 2, 5, 0, 3, 4});
      slog::Relation* readrel1137 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index1104 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({2, 3, 0, 1});
      slog::Relation* readrel1139 = db->getRelation("eval");
      evalindex1105 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 3, 0});
      slog::Relation* readrel1141 = db->getRelation("eval");
      evalindex1106 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 2, 3, 0});
      slog::Relation* readrel1143 = db->getRelation("mp_put");
      mp_putindex1107 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({3, 1, 0, 2});
      slog::Relation* readrel1145 = db->getRelation("eval");
      evalindex1108 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel1147 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1109 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({2, 3, 0, 1});
      slog::Relation* readrel1149 = db->getRelation("eval");
      evalindex1110 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({2, 3, 0, 1});
      slog::Relation* readrel1151 = db->getRelation("eval");
      evaldelta1119 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({2, 3, 0, 1});
      slog::Relation* readrel1153 = db->getRelation("eval");
      evalindex1111 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({2, 3, 0, 1});
      slog::Relation* readrel1155 = db->getRelation("eval");
      evaldelta1120 = readrel1155->getIndex(ord1154, true);
      std::vector<u16> ord1156({0, 2, 1, 3});
      slog::Relation* readrel1157 = db->getRelation("mp_put");
      mp_putindex1112 = readrel1157->getIndex(ord1156, false);
      std::vector<u16> ord1158({0, 2, 1, 3});
      slog::Relation* readrel1159 = db->getRelation("mp_put");
      mp_putdelta1121 = readrel1159->getIndex(ord1158, true);
      std::vector<u16> ord1160({0, 1});
      slog::Relation* readrel1161 = db->getRelation("eval_ans");
      eval_ansindex1113 = readrel1161->getIndex(ord1160, false);
      std::vector<u16> ord1162({0, 1});
      slog::Relation* readrel1163 = db->getRelation("mp_put_ans");
      mp_put_ansindex1114 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({1, 2, 3, 0});
      slog::Relation* readrel1165 = db->getRelation("eval");
      evalindex1115 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({1, 2, 3, 0});
      slog::Relation* readrel1167 = db->getRelation("eval");
      evaldelta1122 = readrel1167->getIndex(ord1166, true);
      std::vector<u16> ord1168({0, 1});
      slog::Relation* readrel1169 = db->getRelation("eval_ans");
      eval_ansindex1116 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({0, 1});
      slog::Relation* readrel1171 = db->getRelation("mp_put_ans");
      mp_put_ansindex1117 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({0, 1});
      slog::Relation* readrel1173 = db->getRelation("eval_ans");
      eval_ansindex1118 = readrel1173->getIndex(ord1172, false);
  
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
        u64 v_c35 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c29 = _t[3];
        if (!slog::exists_probe<10,3>($sup70016x92x0x0x1index1099, std::array<u64,10>{v_c29, v_c33, v_c13, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1100, std::array<u64,4>{v_c35, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1101, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1102, std::array<u64,4>{v_c13, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1103, std::array<u64,4>{v_c29, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index1104, std::array<u64,6>{v_c29, v_c33, v_c13, 0, 0, 0}, [&](const std::array<u64,6>& m1174) {
          u64 v_c31 = m1174[3]; u64 v_c12 = m1174[4]; u64 v_c14 = m1174[5];
          if (!slog::exists_probe<4,4>(evalindex1105, std::array<u64,4>{v_c12, v_c14, v_c31, v_c35})) return;
          if (!slog::exists_probe<4,3>(evalindex1106, std::array<u64,4>{v_c33, v_c12, v_c14, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex1107, std::array<u64,4>{v_c12, v_c13, v_c14, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1108, std::array<u64,4>{v_c14, v_c29, 0, 0})) return;
          slog::join_probe<10,6>($sup70016x92x0x0x1index1109, std::array<u64,10>{v_c31, v_c12, v_c14, v_c29, v_c33, v_c13, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1175) {
            u64 v_c32 = m1175[6]; u64 v_c30 = m1175[7]; u64 v_c19 = m1175[8]; u64 v_c34 = m1175[9];
            slog::join_probe_old<4,4>(evalindex1110, evaldelta1119, std::array<u64,4>{v_c12, v_c14, v_c31, v_c35}, [&](const std::array<u64,4>& m1176) {
              slog::join_probe_old<4,4>(evalindex1111, evaldelta1120, std::array<u64,4>{v_c12, v_c14, v_c32, v_c33}, [&](const std::array<u64,4>& m1177) {
                slog::join_probe_old<4,4>(mp_putindex1112, mp_putdelta1121, std::array<u64,4>{v_c30, v_c13, v_c12, v_c14}, [&](const std::array<u64,4>& m1178) {
                  if (!slog::exists_probe<2,2>(eval_ansindex1113, std::array<u64,2>{v_c32, v_c34})) return;
                  if (!slog::exists_probe<2,2>(mp_put_ansindex1114, std::array<u64,2>{v_c30, v_c19})) return;
                  slog::join_probe_old<4,3>(evalindex1115, evaldelta1122, std::array<u64,4>{v_c29, v_c19, v_c14, 0}, [&](const std::array<u64,4>& m1179) {
                    u64 v_c27 = m1179[3];
                    slog::join_probe<2,2>(eval_ansindex1116, std::array<u64,2>{v_c32, v_c34}, [&](const std::array<u64,2>& m1180) {
                      slog::join_probe<2,2>(mp_put_ansindex1117, std::array<u64,2>{v_c30, v_c19}, [&](const std::array<u64,2>& m1181) {
                        slog::join_probe<2,1>(eval_ansindex1118, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1182) {
                          u64 v_c28 = m1182[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
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
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t8x7Q785 __v1) (body (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t8x7Q785 __v1) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t8x7Q785) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v3) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t8x7Q785 __v1 __v3) (join-old mp_hsb_ans (0 1) 1 (0 1) __t8x7Q785 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t8x7Q785 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t8x7Q785 __v0 __v3 __v1 __t7O3e781 dup6QI21998 dup4FCe1999 p0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join mp_msk_ans (0 1) 1 __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask1202 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1183;  slog::Index** $sup5638x29x0x0x2index1184;  slog::Index** $sup5638x29x0x0x1index1185;  slog::Index** mp_mskindex1186;  slog::Index** mp_hsb_ansindex1187;  slog::Index** $sup5638x29x0x0x2index1188;  slog::Index** mp_hsb_ansindex1189;  slog::Index** $sup5638x29x0x0x1index1190;  slog::Index** $sup5638x29x0x0x2index1191;  slog::Index** $sup5638x29x0x0x1index1192;  slog::Index** $sup5638x29x0x0x0index1193;  slog::Index** mp_joinindex1194;  slog::Index** mp_mskindex1195;  slog::Index** mp_msk_ansindex1196;  slog::Index** mp_hsbindex1197;  slog::Index** mp_hsb_ansdelta1198;  slog::Index** mp_joindelta1199;  slog::Index** mp_mskdelta1200;  slog::Index** mp_hsbdelta1201;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1203({0, 1});
      slog::Relation* readrel1204 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1183 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1206 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1184 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1208 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1185 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({2, 0, 1});
      slog::Relation* readrel1210 = db->getRelation("mp_msk");
      mp_mskindex1186 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({0, 1});
      slog::Relation* readrel1212 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1187 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1214 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1188 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({0, 1});
      slog::Relation* readrel1216 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1189 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({0, 1});
      slog::Relation* readrel1218 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1198 = readrel1218->getIndex(ord1217, true);
      std::vector<u16> ord1219({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1220 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1190 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1222 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1191 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1224 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1192 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({1, 0, 2, 3, 4});
      slog::Relation* readrel1226 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1193 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({1, 2, 3, 4, 0});
      slog::Relation* readrel1228 = db->getRelation("mp_join");
      mp_joinindex1194 = readrel1228->getIndex(ord1227, false);
      std::vector<u16> ord1229({1, 2, 3, 4, 0});
      slog::Relation* readrel1230 = db->getRelation("mp_join");
      mp_joindelta1199 = readrel1230->getIndex(ord1229, true);
      std::vector<u16> ord1231({1, 2, 0});
      slog::Relation* readrel1232 = db->getRelation("mp_msk");
      mp_mskindex1195 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({1, 2, 0});
      slog::Relation* readrel1234 = db->getRelation("mp_msk");
      mp_mskdelta1200 = readrel1234->getIndex(ord1233, true);
      std::vector<u16> ord1235({0, 1});
      slog::Relation* readrel1236 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1196 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({0, 1});
      slog::Relation* readrel1238 = db->getRelation("mp_hsb");
      mp_hsbindex1197 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({0, 1});
      slog::Relation* readrel1240 = db->getRelation("mp_hsb");
      mp_hsbdelta1201 = readrel1240->getIndex(ord1239, true);
  
    }
    ReadTask1202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c225 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c226 = _t[0];
        u64 v_c20 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1183, std::array<u64,2>{v_c226, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index1184, std::array<u64,11>{v_c226, v_c20, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index1185, std::array<u64,7>{v_c226, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1186, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex1187, std::array<u64,2>{v_c226, 0}, [&](const std::array<u64,2>& m1241) {
          u64 v_c174 = m1241[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index1188, std::array<u64,11>{v_c226, v_c20, v_c174, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex1189, mp_hsb_ansdelta1198, std::array<u64,2>{v_c226, 0}, [&](const std::array<u64,2>& m1242) {
            u64 v_c19 = m1242[1];
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index1190, std::array<u64,7>{v_c226, v_c19, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index1191, std::array<u64,11>{v_c226, v_c19, v_c174, v_c20, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1243) {
              u64 v_c227 = m1243[4]; u64 v_c228 = m1243[5]; u64 v_c229 = m1243[6]; u64 v_c177 = m1243[7]; u64 v_c178 = m1243[8]; u64 v_c179 = m1243[9]; u64 v_c180 = m1243[10];
              if (v_c226 != v_c229) return;
              if (v_c226 != v_c228) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index1192, std::array<u64,7>{v_c227, v_c177, v_c178, v_c179, v_c180, v_c226, v_c19}, [&](const std::array<u64,7>& m1244) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index1193, std::array<u64,5>{v_c177, v_c227, v_c178, v_c179, v_c180}, [&](const std::array<u64,5>& m1245) {
                  slog::join_probe_old<5,5>(mp_joinindex1194, mp_joindelta1199, std::array<u64,5>{v_c177, v_c179, v_c178, v_c180, v_c227}, [&](const std::array<u64,5>& m1246) {
                    slog::join_probe_old<3,2>(mp_mskindex1195, mp_mskdelta1200, std::array<u64,3>{v_c177, v_c20, 0}, [&](const std::array<u64,3>& m1247) {
                      u64 v_c230 = m1247[2];
                      slog::join_probe<2,1>(mp_msk_ansindex1196, std::array<u64,2>{v_c230, 0}, [&](const std::array<u64,2>& m1248) {
                        u64 v_c231 = m1248[1];
                        u64 v_c232 = _prim_bxor(db, v_c177, v_c178);
                        if (v_c232 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1197, mp_hsbdelta1201, std::array<u64,2>{v_c226, v_c232}, [&](const std::array<u64,2>& m1249) {
                          u64 v_c233 = _prim_band(db, v_c177, v_c19);
                          if (v_c233 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c234 = _prim_gt(db, v_c233, v_c225);
                          if (v_c234 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c234) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c227, v_c231, v_c174, v_c179, v_c180});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c231, v_c174, v_c180, v_c179}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1202* _cont = new ReadTask1202(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1202(db,b), false);
  // (crule (pre) (scan mleaf __t5Ivz603 k v) (body (exists mp_union (2 0 1) 1 __t5Ivz603) (join-old mp_put_soft (2 3 0 1) 2 (2 3 0 1) k v __t5GLK605 s) (exists mp_put_soft_ans (0 1) 1 __t5GLK605) (join-old mp_union (1 2 0) 2 (1 2 0) s __t5Ivz603 __t7E2l604) (join mp_put_soft_ans (0 1) 1 __t5GLK605 r)) (head (emit mp_union_ans (0 1) __t7E2l604 r)) map.slog:93 #f)
  class ReadTask1258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1251;  slog::Index** mp_put_softindex1252;  slog::Index** mp_put_soft_ansindex1253;  slog::Index** mp_unionindex1254;  slog::Index** mp_put_soft_ansindex1255;  slog::Index** mp_put_softdelta1256;  slog::Index** mp_uniondelta1257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1259({0, 1});
      slog::Relation* readrel1260 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1260->getIndex(ord1259, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord1261({2, 0, 1});
      slog::Relation* readrel1262 = db->getRelation("mp_union");
      mp_unionindex1251 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({2, 3, 0, 1});
      slog::Relation* readrel1264 = db->getRelation("mp_put_soft");
      mp_put_softindex1252 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({2, 3, 0, 1});
      slog::Relation* readrel1266 = db->getRelation("mp_put_soft");
      mp_put_softdelta1256 = readrel1266->getIndex(ord1265, true);
      std::vector<u16> ord1267({0, 1});
      slog::Relation* readrel1268 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex1253 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({1, 2, 0});
      slog::Relation* readrel1270 = db->getRelation("mp_union");
      mp_unionindex1254 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({1, 2, 0});
      slog::Relation* readrel1272 = db->getRelation("mp_union");
      mp_uniondelta1257 = readrel1272->getIndex(ord1271, true);
      std::vector<u16> ord1273({0, 1});
      slog::Relation* readrel1274 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex1255 = readrel1274->getIndex(ord1273, false);
  
    }
    ReadTask1258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c235 = _t[0];
        u64 v_c115 = _t[1];
        u64 v_c28 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex1251, std::array<u64,3>{v_c235, 0, 0})) return;
        slog::join_probe_old<4,2>(mp_put_softindex1252, mp_put_softdelta1256, std::array<u64,4>{v_c115, v_c28, 0, 0}, [&](const std::array<u64,4>& m1275) {
          u64 v_c236 = m1275[2]; u64 v_c237 = m1275[3];
          if (!slog::exists_probe<2,1>(mp_put_soft_ansindex1253, std::array<u64,2>{v_c236, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex1254, mp_uniondelta1257, std::array<u64,3>{v_c237, v_c235, 0}, [&](const std::array<u64,3>& m1276) {
            u64 v_c238 = m1276[2];
            slog::join_probe<2,1>(mp_put_soft_ansindex1255, std::array<u64,2>{v_c236, 0}, [&](const std::array<u64,2>& m1277) {
              u64 v_c59 = m1277[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c238, v_c59}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask1258* _cont = new ReadTask1258(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1258(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x0 __t8CpS128 p0 p1 t0 t1) (body (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (exists $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t8CpS128 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 5 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists mp_hsb_ans (0 1) 2 __t0Ayb132 __v0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0 dup4t6F1978 dup2J5X1979 __v1 __v3) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join-old mp_msk_ans (0 1) 1 (0 1) __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask1298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex1278;  slog::Index** $sup5638x25x0x0x2index1279;  slog::Index** mp_mskindex1280;  slog::Index** $sup5638x25x0x0x1index1281;  slog::Index** mp_hsb_ansindex1282;  slog::Index** mp_hsb_ansindex1283;  slog::Index** $sup5638x25x0x0x2index1284;  slog::Index** mp_hsb_ansindex1285;  slog::Index** mp_hsb_ansindex1286;  slog::Index** mp_hsb_ansindex1287;  slog::Index** mp_mskindex1288;  slog::Index** mp_msk_ansindex1289;  slog::Index** mp_hsbindex1290;  slog::Index** mp_joindelta1291;  slog::Index** mp_hsb_ansdelta1292;  slog::Index** mp_hsb_ansdelta1293;  slog::Index** mp_hsb_ansdelta1294;  slog::Index** mp_mskdelta1295;  slog::Index** mp_msk_ansdelta1296;  slog::Index** mp_hsbdelta1297;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord1299({1, 2, 3, 4, 0});
      slog::Relation* readrel1300 = db->getRelation("mp_join");
      mp_joinindex1278 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({1, 2, 3, 4, 0});
      slog::Relation* readrel1302 = db->getRelation("mp_join");
      mp_joindelta1291 = readrel1302->getIndex(ord1301, true);
      std::vector<u16> ord1303({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1304 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1279 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({1, 2, 0});
      slog::Relation* readrel1306 = db->getRelation("mp_msk");
      mp_mskindex1280 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1308 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1281 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1282 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({0, 1});
      slog::Relation* readrel1312 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1283 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1314 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1284 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({0, 1});
      slog::Relation* readrel1316 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1285 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({0, 1});
      slog::Relation* readrel1318 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1292 = readrel1318->getIndex(ord1317, true);
      std::vector<u16> ord1319({0, 1});
      slog::Relation* readrel1320 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1286 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({0, 1});
      slog::Relation* readrel1322 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1293 = readrel1322->getIndex(ord1321, true);
      std::vector<u16> ord1323({0, 1});
      slog::Relation* readrel1324 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1287 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({0, 1});
      slog::Relation* readrel1326 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1294 = readrel1326->getIndex(ord1325, true);
      std::vector<u16> ord1327({1, 2, 0});
      slog::Relation* readrel1328 = db->getRelation("mp_msk");
      mp_mskindex1288 = readrel1328->getIndex(ord1327, false);
      std::vector<u16> ord1329({1, 2, 0});
      slog::Relation* readrel1330 = db->getRelation("mp_msk");
      mp_mskdelta1295 = readrel1330->getIndex(ord1329, true);
      std::vector<u16> ord1331({0, 1});
      slog::Relation* readrel1332 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1289 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({0, 1});
      slog::Relation* readrel1334 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1296 = readrel1334->getIndex(ord1333, true);
      std::vector<u16> ord1335({0, 1});
      slog::Relation* readrel1336 = db->getRelation("mp_hsb");
      mp_hsbindex1290 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({0, 1});
      slog::Relation* readrel1338 = db->getRelation("mp_hsb");
      mp_hsbdelta1297 = readrel1338->getIndex(ord1337, true);
  
    }
    ReadTask1298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c239 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c240 = _t[0];
        u64 v_c177 = _t[1];
        u64 v_c178 = _t[2];
        u64 v_c179 = _t[3];
        u64 v_c180 = _t[4];
        slog::join_probe_old<5,5>(mp_joinindex1278, mp_joindelta1291, std::array<u64,5>{v_c177, v_c179, v_c178, v_c180, v_c240}, [&](const std::array<u64,5>& m1339) {
          if (!slog::exists_probe<11,5>($sup5638x25x0x0x2index1279, std::array<u64,11>{v_c240, v_c177, v_c178, v_c179, v_c180, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1280, std::array<u64,3>{v_c177, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x25x0x0x1index1281, std::array<u64,7>{v_c240, v_c177, v_c178, v_c179, v_c180, 0, 0}, [&](const std::array<u64,7>& m1340) {
            u64 v_c241 = m1340[5]; u64 v_c19 = m1340[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex1282, std::array<u64,2>{v_c241, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex1283, std::array<u64,2>{v_c241, v_c19})) return;
            slog::join_probe<11,7>($sup5638x25x0x0x2index1284, std::array<u64,11>{v_c240, v_c177, v_c178, v_c179, v_c180, v_c241, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1341) {
              u64 v_c242 = m1341[7]; u64 v_c243 = m1341[8]; u64 v_c20 = m1341[9]; u64 v_c174 = m1341[10];
              if (v_c241 != v_c243) return;
              if (v_c241 != v_c242) return;
              slog::join_probe_old<2,2>(mp_hsb_ansindex1285, mp_hsb_ansdelta1292, std::array<u64,2>{v_c241, v_c174}, [&](const std::array<u64,2>& m1342) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex1286, mp_hsb_ansdelta1293, std::array<u64,2>{v_c241, v_c20}, [&](const std::array<u64,2>& m1343) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex1287, mp_hsb_ansdelta1294, std::array<u64,2>{v_c241, v_c19}, [&](const std::array<u64,2>& m1344) {
                    slog::join_probe_old<3,2>(mp_mskindex1288, mp_mskdelta1295, std::array<u64,3>{v_c177, v_c20, 0}, [&](const std::array<u64,3>& m1345) {
                      u64 v_c244 = m1345[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex1289, mp_msk_ansdelta1296, std::array<u64,2>{v_c244, 0}, [&](const std::array<u64,2>& m1346) {
                        u64 v_c231 = m1346[1];
                        u64 v_c245 = _prim_bxor(db, v_c177, v_c178);
                        if (v_c245 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1290, mp_hsbdelta1297, std::array<u64,2>{v_c241, v_c245}, [&](const std::array<u64,2>& m1347) {
                          u64 v_c246 = _prim_band(db, v_c177, v_c19);
                          if (v_c246 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c247 = _prim_lt(db, v_c246, v_c239);
                          if (v_c247 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c247) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c240, v_c231, v_c174, v_c179, v_c180});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c231, v_c174, v_c179, v_c180}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
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
  // (crule (pre) (scan select_branch __t1Vli649 __v0 e2 e3) (body (exists $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3) (exists eval_ans (1 0) 1 __v0) (exists select_branch_ans (0 1) 1 __t1Vli649) (join if (2 3 0 1) 2 e2 e3 __t71xd646 e1) (exists eval (1 2 3 0) 1 __t71xd646) (exists eval (1 2 3 0) 1 e1) (join $sup70016x87x0x0x0 (2 3 1 0 4 5) 3 e2 e3 e1 __t7kdB647 rho t) (join eval (2 3 0 1) 4 rho t __t7kdB647 __t71xd646) (exists eval (2 3 0 1) 2 rho t) (join eval (1 2 3 0) 3 e1 rho t __t2MYH648) (join eval_ans (0 1) 2 __t2MYH648 __v0) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask1364 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x87x0x0x0index1349;  slog::Index** eval_ansindex1350;  slog::Index** select_branch_ansindex1351;  slog::Index** ifindex1352;  slog::Index** evalindex1353;  slog::Index** evalindex1354;  slog::Index** $sup70016x87x0x0x0index1355;  slog::Index** evalindex1356;  slog::Index** evalindex1357;  slog::Index** evalindex1358;  slog::Index** eval_ansindex1359;  slog::Index** evalindex1360;  slog::Index** select_branch_ansindex1361;  slog::Index** eval_ansindex1362;  slog::Index** evaldelta1363;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1365({0, 1});
      slog::Relation* readrel1366 = db->getRelation("eval_ans");
      head_index[0] = readrel1366->getIndex(ord1365, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord1367({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1368 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1349 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 0});
      slog::Relation* readrel1370 = db->getRelation("eval_ans");
      eval_ansindex1350 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({0, 1});
      slog::Relation* readrel1372 = db->getRelation("select_branch_ans");
      select_branch_ansindex1351 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({2, 3, 0, 1});
      slog::Relation* readrel1374 = db->getRelation("if");
      ifindex1352 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 3, 0});
      slog::Relation* readrel1376 = db->getRelation("eval");
      evalindex1353 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 3, 0});
      slog::Relation* readrel1378 = db->getRelation("eval");
      evalindex1354 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1380 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1355 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({2, 3, 0, 1});
      slog::Relation* readrel1382 = db->getRelation("eval");
      evalindex1356 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({2, 3, 0, 1});
      slog::Relation* readrel1384 = db->getRelation("eval");
      evalindex1357 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 2, 3, 0});
      slog::Relation* readrel1386 = db->getRelation("eval");
      evalindex1358 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("eval_ans");
      eval_ansindex1359 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({2, 3, 0, 1});
      slog::Relation* readrel1390 = db->getRelation("eval");
      evalindex1360 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({2, 3, 0, 1});
      slog::Relation* readrel1392 = db->getRelation("eval");
      evaldelta1363 = readrel1392->getIndex(ord1391, true);
      std::vector<u16> ord1393({0, 1});
      slog::Relation* readrel1394 = db->getRelation("select_branch_ans");
      select_branch_ansindex1361 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({0, 1});
      slog::Relation* readrel1396 = db->getRelation("eval_ans");
      eval_ansindex1362 = readrel1396->getIndex(ord1395, false);
  
    }
    ReadTask1364(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c248 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c249 = _t[2];
        u64 v_c250 = _t[3];
        if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index1349, std::array<u64,6>{v_c249, v_c250, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1350, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex1351, std::array<u64,2>{v_c248, 0})) return;
        slog::join_probe<4,2>(ifindex1352, std::array<u64,4>{v_c249, v_c250, 0, 0}, [&](const std::array<u64,4>& m1397) {
          u64 v_c251 = m1397[2]; u64 v_c252 = m1397[3];
          if (!slog::exists_probe<4,1>(evalindex1353, std::array<u64,4>{v_c251, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex1354, std::array<u64,4>{v_c252, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup70016x87x0x0x0index1355, std::array<u64,6>{v_c249, v_c250, v_c252, 0, 0, 0}, [&](const std::array<u64,6>& m1398) {
            u64 v_c253 = m1398[3]; u64 v_c12 = m1398[4]; u64 v_c14 = m1398[5];
            slog::join_probe<4,4>(evalindex1356, std::array<u64,4>{v_c12, v_c14, v_c253, v_c251}, [&](const std::array<u64,4>& m1399) {
              if (!slog::exists_probe<4,2>(evalindex1357, std::array<u64,4>{v_c12, v_c14, 0, 0})) return;
              slog::join_probe<4,3>(evalindex1358, std::array<u64,4>{v_c252, v_c12, v_c14, 0}, [&](const std::array<u64,4>& m1400) {
                u64 v_c254 = m1400[3];
                slog::join_probe<2,2>(eval_ansindex1359, std::array<u64,2>{v_c254, v_c19}, [&](const std::array<u64,2>& m1401) {
                  slog::join_probe_old<4,2>(evalindex1360, evaldelta1363, std::array<u64,4>{v_c12, v_c14, 0, 0}, [&](const std::array<u64,4>& m1402) {
                    u64 v_c255 = m1402[2]; u64 v_c20 = m1402[3];
                    slog::join_probe<2,2>(select_branch_ansindex1361, std::array<u64,2>{v_c248, v_c20}, [&](const std::array<u64,2>& m1403) {
                      slog::join_probe<2,1>(eval_ansindex1362, std::array<u64,2>{v_c255, 0}, [&](const std::array<u64,2>& m1404) {
                        u64 v_c231 = m1404[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c253, v_c231}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask1364* _cont = new ReadTask1364(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1364(db,b), false);
  // (crule (pre (let __tconst9dzl332 const6b86b273ff34fce19d6b804e)) (scan mbranch __t88jc330 p m l r) (body (join-old mp_put (1 2 3 0) 1 (1 2 3 0) __t88jc330 k v __t24wX331) (let __t85Nm333 (band k m)) (cmp lt __t85Nm333 __tconst9dzl332)) (head (emit $sup5638x40x0x0x0 (4 2 3 5 0 1 6) p l m r __t24wX331 k v)) map.slog:41 #f)
  class ReadTask1407 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1405;  slog::Index** mp_putdelta1406;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord1408({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1409 = db->getRelation("$sup5638x40x0x0x0");
      head_index[0] = readrel1409->getIndex(ord1408, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1410({1, 2, 3, 0});
      slog::Relation* readrel1411 = db->getRelation("mp_put");
      mp_putindex1405 = readrel1411->getIndex(ord1410, false);
      std::vector<u16> ord1412({1, 2, 3, 0});
      slog::Relation* readrel1413 = db->getRelation("mp_put");
      mp_putdelta1406 = readrel1413->getIndex(ord1412, true);
  
    }
    ReadTask1407(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c256 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c257 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c59 = _t[4];
        slog::join_probe_old<4,1>(mp_putindex1405, mp_putdelta1406, std::array<u64,4>{v_c257, 0, 0, 0}, [&](const std::array<u64,4>& m1414) {
          u64 v_c115 = m1414[1]; u64 v_c28 = m1414[2]; u64 v_c258 = m1414[3];
          u64 v_c259 = _prim_band(db, v_c115, v_c3);
          if (v_c259 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          u64 v_c260 = _prim_lt(db, v_c259, v_c256);
          if (v_c260 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
          if (!v_c260) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c2, v_c4, v_c3, v_c59, v_c258, v_c115, v_c28}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1407* _cont = new ReadTask1407(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1407(db,b), false);
  // (crule (pre) (scan mbranch __t8IRS449 q m u v) (body (exists mbranch (2 0 1 3 4) 1 m) (join mp_union (2 0 1) 1 __t8IRS449 __t7CA0447 __t8p1x448) (join mbranch (2 0 1 3 4) 2 m __t8p1x448 p l r) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __86XP1466 p __t8p1x448 q __t8IRS449)) map.slog:114 #f)
  class ReadTask1419 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1416;  slog::Index** mp_unionindex1417;  slog::Index** mbranchindex1418;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1420({2, 0, 1, 3, 4});
      slog::Relation* readrel1421 = db->getRelation("mbranch");
      mbranchindex1416 = readrel1421->getIndex(ord1420, false);
      std::vector<u16> ord1422({2, 0, 1});
      slog::Relation* readrel1423 = db->getRelation("mp_union");
      mp_unionindex1417 = readrel1423->getIndex(ord1422, false);
      std::vector<u16> ord1424({2, 0, 1, 3, 4});
      slog::Relation* readrel1425 = db->getRelation("mbranch");
      mbranchindex1418 = readrel1425->getIndex(ord1424, false);
  
    }
    ReadTask1419(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c261 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c28 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex1416, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(mp_unionindex1417, std::array<u64,3>{v_c261, 0, 0}, [&](const std::array<u64,3>& m1426) {
          u64 v_c262 = m1426[1]; u64 v_c263 = m1426[2];
          slog::join_probe<5,2>(mbranchindex1418, std::array<u64,5>{v_c3, v_c263, 0, 0, 0}, [&](const std::array<u64,5>& m1427) {
            u64 v_c2 = m1427[2]; u64 v_c4 = m1427[3]; u64 v_c59 = m1427[4];
            if (v_c2 == v_c57) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c2, v_c263, v_c57, v_c261}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1419* _cont = new ReadTask1419(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1419(db,b), false);
  // (crule (pre (let __trid6Txt1367 const6c3d8aa344844f80a370de02) (let __trel7v9K1368 consta24220c5193376967f1fa95e) (let __tcol55TM1369 const5feceb66ffc86f38d952786c) (let __trel9X2e1370 consta24220c5193376967f1fa95e) (let __tcol5gjV1371 const6b86b273ff34fce19d6b804e) (let __trel1SDj1372 consta24220c5193376967f1fa95e) (let __tcol0VSZ1373 constd4735e3a265e16eee03f5971) (let __trel9KF11374 consta24220c5193376967f1fa95e) (let __tcol3INk1375 const4e07408562bedb8b60ce05c1)) (scan $sup5638x101x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid6Txt1367 __trel7v9K1368 __tcol55TM1369 (1 2 3 4 0)) (tycheck s (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6Txt1367 __trel9X2e1370 __tcol5gjV1371 (1 2 3 4 0)) (tycheck q (accept int) __trid6Txt1367 __trel1SDj1372 __tcol0VSZ1373 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6Txt1367 __trel9KF11374 __tcol3INk1375 (1 2 3 4 0)) (mkstruct mp_join (1 2 3 4 0) __2e3P1366 p s q t)) map.slog:102 #f)
  class ReadTask1431 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1429;  u32 sid1428;  u32 sid1430;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("mp_join");
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
      sid1429 = db->getRelation("_enum")->getStructId();
      sid1428 = db->getRelation("mbranch")->getStructId();
      sid1430 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1431(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c264 = v_const6c3d8aa344844f80a370de02;
      u64 v_c265 = v_consta24220c5193376967f1fa95e;
      u64 v_c266 = v_const5feceb66ffc86f38d952786c;
      u64 v_c267 = v_consta24220c5193376967f1fa95e;
      u64 v_c268 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c269 = v_consta24220c5193376967f1fa95e;
      u64 v_c270 = v_constd4735e3a265e16eee03f5971;
      u64 v_c271 = v_consta24220c5193376967f1fa95e;
      u64 v_c272 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c106 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c59 = _t[6];
        u64 v_c237 = _t[7];
        u64 v_c14 = _t[8];
        u64 v_c60 = _t[9];
        u64 v_c28 = _t[10];
        ++_fires;
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c264, v_c265, v_c266, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c237) && (decode_struct_id(v_c237) == sid1428 || decode_struct_id(v_c237) == sid1429 || decode_struct_id(v_c237) == sid1430))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c264, v_c267, v_c268, v_c237}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c57)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c264, v_c269, v_c270, v_c57}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid1428 || decode_struct_id(v_c14) == sid1429 || decode_struct_id(v_c14) == sid1430))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c264, v_c271, v_c272, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c2, v_c237, v_c57, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1431* _cont = new ReadTask1431(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1431(db,b), false);
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t7cml232 __t5gI3231 k) (body (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join $sup5638x62x0x0x0 (0 1 2 3 4 5) 2 __t7cml232 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t5gI3231) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t2sXu235) (exists mp_has0_ans (0 1) 1 __t2sXu235) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9BfR236) (join mp_msk_ans (0 1) 2 __t9BfR236 p) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask1445 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1432;  slog::Index** mp_mskindex1433;  slog::Index** $sup5638x62x0x0x0index1434;  slog::Index** mbranchindex1435;  slog::Index** mp_mskindex1436;  slog::Index** mp_msk_ansindex1437;  slog::Index** mp_has0index1438;  slog::Index** mp_has0_ansindex1439;  slog::Index** mp_mskindex1440;  slog::Index** mp_msk_ansindex1441;  slog::Index** mp_has0_ansindex1442;  slog::Index** mp_has0delta1443;  slog::Index** mp_mskdelta1444;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1446({0, 1});
      slog::Relation* readrel1447 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1447->getIndex(ord1446, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord1448({2, 0, 1});
      slog::Relation* readrel1449 = db->getRelation("mp_has0");
      mp_has0index1432 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({1, 2, 0});
      slog::Relation* readrel1451 = db->getRelation("mp_msk");
      mp_mskindex1433 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1453 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1434 = readrel1453->getIndex(ord1452, false);
      std::vector<u16> ord1454({1, 2, 3, 4, 0});
      slog::Relation* readrel1455 = db->getRelation("mbranch");
      mbranchindex1435 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({1, 2, 0});
      slog::Relation* readrel1457 = db->getRelation("mp_msk");
      mp_mskindex1436 = readrel1457->getIndex(ord1456, false);
      std::vector<u16> ord1458({1, 0});
      slog::Relation* readrel1459 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1437 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 2, 0});
      slog::Relation* readrel1461 = db->getRelation("mp_has0");
      mp_has0index1438 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({1, 2, 0});
      slog::Relation* readrel1463 = db->getRelation("mp_has0");
      mp_has0delta1443 = readrel1463->getIndex(ord1462, true);
      std::vector<u16> ord1464({0, 1});
      slog::Relation* readrel1465 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1439 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({1, 2, 0});
      slog::Relation* readrel1467 = db->getRelation("mp_msk");
      mp_mskindex1440 = readrel1467->getIndex(ord1466, false);
      std::vector<u16> ord1468({1, 2, 0});
      slog::Relation* readrel1469 = db->getRelation("mp_msk");
      mp_mskdelta1444 = readrel1469->getIndex(ord1468, true);
      std::vector<u16> ord1470({0, 1});
      slog::Relation* readrel1471 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1441 = readrel1471->getIndex(ord1470, false);
      std::vector<u16> ord1472({0, 1});
      slog::Relation* readrel1473 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1442 = readrel1473->getIndex(ord1472, false);
  
    }
    ReadTask1445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c273 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c274 = _t[0];
        u64 v_c275 = _t[1];
        u64 v_c115 = _t[2];
        if (!slog::exists_probe<3,1>(mp_has0index1432, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1433, std::array<u64,3>{v_c115, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x62x0x0x0index1434, std::array<u64,6>{v_c274, v_c115, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1474) {
          u64 v_c4 = m1474[2]; u64 v_c3 = m1474[3]; u64 v_c2 = m1474[4]; u64 v_c59 = m1474[5];
          slog::join_probe<5,5>(mbranchindex1435, std::array<u64,5>{v_c2, v_c3, v_c4, v_c59, v_c275}, [&](const std::array<u64,5>& m1475) {
            if (!slog::exists_probe<3,2>(mp_mskindex1436, std::array<u64,3>{v_c115, v_c3, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1437, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index1438, mp_has0delta1443, std::array<u64,3>{v_c59, v_c115, 0}, [&](const std::array<u64,3>& m1476) {
              u64 v_c276 = m1476[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex1439, std::array<u64,2>{v_c276, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1440, mp_mskdelta1444, std::array<u64,3>{v_c115, v_c3, 0}, [&](const std::array<u64,3>& m1477) {
                u64 v_c277 = m1477[2];
                slog::join_probe<2,2>(mp_msk_ansindex1441, std::array<u64,2>{v_c277, v_c2}, [&](const std::array<u64,2>& m1478) {
                  slog::join_probe<2,1>(mp_has0_ansindex1442, std::array<u64,2>{v_c276, 0}, [&](const std::array<u64,2>& m1479) {
                    u64 v_c222 = m1479[1];
                    u64 v_c278 = _prim_band(db, v_c115, v_c3);
                    if (v_c278 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c279 = _prim_gt(db, v_c278, v_c273);
                    if (v_c279 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c279) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c274, v_c222}, std::array<u16,2>{0, 1});
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
        ReadTask1445* _cont = new ReadTask1445(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1445(db,b), false);
  // (crule (pre (let __tconst0bgi206 conste29c9c180c6279b0b02abd6a) (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c) (let __tconst5cJe186 const4b227777d4dd1fc61c6f884f) (let __tconst1O2C203 const7297d2085ea0adffc396d546)) (scan temp2Udj1950 __t03ww191 __t5bmL201 __t5rXn209) (body (exists ref (1 0) 1 __tconst0bgi206) (exists ref (1 0) 1 __tconst2PAJ212) (exists num (1 0) 1 __tconst5cJe186) (join primref (1 0) 1 __tconst1O2C203 __t0nMB204) (join ref (1 0) 1 __tconst0bgi206 __t7M5t197) (join ref (1 0) 1 __tconst2PAJ212 __t4x55194) (join num (1 0) 1 __tconst5cJe186 __t5VhZ187) (let __t8cZd192 (lpush __t03ww191 __t5VhZ187)) (let __t8R2f202 (lpush __t5bmL201 __t7M5t197)) (let __t9Ps2210 (lpush __t5rXn209 __tconst0bgi206))) (head (emit-temp temp5bNF1951 __t8R2f202 __t8cZd192 __t9Ps2210)) kcfa.slog:59 #f)
  class ReadTask1488 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1481;  slog::Index** refindex1482;  slog::Index** numindex1483;  slog::Index** primrefindex1484;  slog::Index** refindex1485;  slog::Index** refindex1486;  slog::Index** numindex1487;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5bNF1951");
      outer_rel = db->getRelation("temp2Udj1950");
      std::vector<u16> ord1489({1, 0});
      slog::Relation* readrel1490 = db->getRelation("ref");
      refindex1481 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({1, 0});
      slog::Relation* readrel1492 = db->getRelation("ref");
      refindex1482 = readrel1492->getIndex(ord1491, false);
      std::vector<u16> ord1493({1, 0});
      slog::Relation* readrel1494 = db->getRelation("num");
      numindex1483 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({1, 0});
      slog::Relation* readrel1496 = db->getRelation("primref");
      primrefindex1484 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({1, 0});
      slog::Relation* readrel1498 = db->getRelation("ref");
      refindex1485 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 0});
      slog::Relation* readrel1500 = db->getRelation("ref");
      refindex1486 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({1, 0});
      slog::Relation* readrel1502 = db->getRelation("num");
      numindex1487 = readrel1502->getIndex(ord1501, false);
  
    }
    ReadTask1488(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c280 = v_conste29c9c180c6279b0b02abd6a;
      u64 v_c94 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c281 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c95 = v_const7297d2085ea0adffc396d546;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c282 = _t[0];
        u64 v_c283 = _t[1];
        u64 v_c284 = _t[2];
        if (!slog::exists_probe<2,1>(refindex1481, std::array<u64,2>{v_c280, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1482, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1483, std::array<u64,2>{v_c281, 0})) return;
        slog::join_probe<2,1>(primrefindex1484, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m1503) {
          u64 v_c99 = m1503[1];
          slog::join_probe<2,1>(refindex1485, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1504) {
            u64 v_c285 = m1504[1];
            slog::join_probe<2,1>(refindex1486, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1505) {
              u64 v_c100 = m1505[1];
              slog::join_probe<2,1>(numindex1487, std::array<u64,2>{v_c281, 0}, [&](const std::array<u64,2>& m1506) {
                u64 v_c286 = m1506[1];
                u64 v_c97 = _prim_lpush(db, v_c282, v_c286);
                if (v_c97 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                u64 v_c96 = _prim_lpush(db, v_c283, v_c285);
                if (v_c96 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                u64 v_c98 = _prim_lpush(db, v_c284, v_c280);
                if (v_c98 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c96, v_c97, v_c98});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp2Udj1950", _fires);
  
      if (!_done)
      {
        ReadTask1488* _cont = new ReadTask1488(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1488(db,b), false);
  // (crule (pre (let __tconst4CIq418 const5feceb66ffc86f38d952786c)) (scan mbranch __t2QpY416 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t2QpY416 __t9vor415 __t6aCH417) (join mbranch (0 1 2 3 4) 1 __t9vor415 q n u v) (cmp lt m n) (let __t1cei419 (band p n)) (cmp gt __t1cei419 __tconst4CIq418)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t6aCH417 v l m n p q r u)) map.slog:108 #f)
  class ReadTask1510 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1507;  slog::Index** mbranchindex1508;  slog::Index** mp_uniondelta1509;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord1511({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1512 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel1512->getIndex(ord1511, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1513({1, 2, 0});
      slog::Relation* readrel1514 = db->getRelation("mp_union");
      mp_unionindex1507 = readrel1514->getIndex(ord1513, false);
      std::vector<u16> ord1515({1, 2, 0});
      slog::Relation* readrel1516 = db->getRelation("mp_union");
      mp_uniondelta1509 = readrel1516->getIndex(ord1515, true);
      std::vector<u16> ord1517({0, 1, 2, 3, 4});
      slog::Relation* readrel1518 = db->getRelation("mbranch");
      mbranchindex1508 = readrel1518->getIndex(ord1517, false);
  
    }
    ReadTask1510(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c287 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c288 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c59 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex1507, mp_uniondelta1509, std::array<u64,3>{v_c288, 0, 0}, [&](const std::array<u64,3>& m1519) {
          u64 v_c289 = m1519[1]; u64 v_c290 = m1519[2];
          slog::join_probe<5,1>(mbranchindex1508, std::array<u64,5>{v_c289, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1520) {
            u64 v_c57 = m1520[1]; u64 v_c56 = m1520[2]; u64 v_c60 = m1520[3]; u64 v_c28 = m1520[4];
            u64 v_c291 = _prim_lt(db, v_c3, v_c56);
            if (v_c291 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c291) return;
            u64 v_c292 = _prim_band(db, v_c2, v_c56);
            if (v_c292 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c293 = _prim_gt(db, v_c292, v_c287);
            if (v_c293 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c293) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c290, v_c28, v_c4, v_c3, v_c56, v_c2, v_c57, v_c59, v_c60}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1510* _cont = new ReadTask1510(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1510(db,b), false);
  // (crule (pre (let __tconst3VAm410 const5feceb66ffc86f38d952786c)) (scan mp_union __t6JnF409 __t7895408 __t7ecR407) (body (join mbranch (0 1 2 3 4) 1 __t7ecR407 q n u v) (join mbranch (0 1 2 3 4) 1 __t7895408 p m l r) (cmp lt n m) (let __t8deh411 (band q m)) (cmp gt __t8deh411 __tconst3VAm410)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t6JnF409 r l m n p q u v)) map.slog:99 #f)
  class ReadTask1525 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1523;  slog::Index** mbranchindex1524;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord1526({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1527 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel1527->getIndex(ord1526, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1528({0, 1, 2, 3, 4});
      slog::Relation* readrel1529 = db->getRelation("mbranch");
      mbranchindex1523 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({0, 1, 2, 3, 4});
      slog::Relation* readrel1531 = db->getRelation("mbranch");
      mbranchindex1524 = readrel1531->getIndex(ord1530, false);
  
    }
    ReadTask1525(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c294 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c295 = _t[0];
        u64 v_c296 = _t[1];
        u64 v_c297 = _t[2];
        slog::join_probe<5,1>(mbranchindex1523, std::array<u64,5>{v_c297, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1532) {
          u64 v_c57 = m1532[1]; u64 v_c56 = m1532[2]; u64 v_c60 = m1532[3]; u64 v_c28 = m1532[4];
          slog::join_probe<5,1>(mbranchindex1524, std::array<u64,5>{v_c296, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1533) {
            u64 v_c2 = m1533[1]; u64 v_c3 = m1533[2]; u64 v_c4 = m1533[3]; u64 v_c59 = m1533[4];
            u64 v_c298 = _prim_lt(db, v_c56, v_c3);
            if (v_c298 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c298) return;
            u64 v_c299 = _prim_band(db, v_c57, v_c3);
            if (v_c299 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c300 = _prim_gt(db, v_c299, v_c294);
            if (v_c300 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c300) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c295, v_c59, v_c4, v_c3, v_c56, v_c2, v_c57, v_c60, v_c28}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1525* _cont = new ReadTask1525(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1525(db,b), false);
  // (crule (pre) (scan eval __t6IYB551 __t0z7d550 rho t) (body (join if (0 1 2 3) 1 __t0z7d550 e1 e2 e3)) (head (emit $sup70016x87x0x0x0 (2 3 1 0 4 5) e2 e3 e1 __t6IYB551 rho t)) interp.slog:88 #f)
  class ReadTask1537 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex1536;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord1538({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1539 = db->getRelation("$sup70016x87x0x0x0");
      head_index[0] = readrel1539->getIndex(ord1538, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1540({0, 1, 2, 3});
      slog::Relation* readrel1541 = db->getRelation("if");
      ifindex1536 = readrel1541->getIndex(ord1540, false);
  
    }
    ReadTask1537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c301 = _t[0];
        u64 v_c302 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c14 = _t[3];
        slog::join_probe<4,1>(ifindex1536, std::array<u64,4>{v_c302, 0, 0, 0}, [&](const std::array<u64,4>& m1542) {
          u64 v_c252 = m1542[1]; u64 v_c249 = m1542[2]; u64 v_c250 = m1542[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c249, v_c250, v_c252, v_c301, v_c12, v_c14}, std::array<u16,6>{2, 3, 1, 0, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1537* _cont = new ReadTask1537(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1537(db,b), false);
}

