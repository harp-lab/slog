
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const3b05f339a47cf251e643e4dd;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const4fc82b26aecb47d2868c4efb;
extern u64 v_const5f7e60cb3d02e4170101c2bc;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const5fedc35d1451fa93f8022abf;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const73475cb40a568e8da8a045ce;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constbb851acf11177e0e526ed8e5;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_c886bd4db5f3c29d7(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan closure __t9dfl535 __t6iPm534 rhoc) (body (exists extend_env (1 2 3 0) 1 rhoc) (exists $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 1 rhoc) (join eval_ans (1 0) 1 __t9dfl535 __t5qy8533) (exists $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) 2 __t5qy8533 rhoc) (join lambda (0 1 2) 1 __t6iPm534 xs eb) (exists $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 4 eb xs rhoc __t5qy8533) (exists eval (1 2 3 0) 1 eb) (join-old extend_env (1 2 3 0) 2 (1 2 3 0) rhoc xs t2 __t5fzh540) (exists tick_ans (1 0) 1 t2) (exists eval (3 1 0 2) 2 t2 eb) (exists extend_env_ans (0 1) 1 __t5fzh540) (join $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 5 eb xs rhoc __t5qy8533 t2 __t2z6s532 __t2srV536 __t0CD9539 ef es rho t vs) (join $sup70016x51x0x0x0 (4 0 3 1 2) 5 t __t2z6s532 rho ef es) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex0;  slog::Index** $sup70016x51x0x0x1index1;  slog::Index** eval_ansindex2;  slog::Index** $sup70016x51x0x0x1index3;  slog::Index** lambdaindex4;  slog::Index** $sup70016x51x0x0x1index5;  slog::Index** evalindex6;  slog::Index** extend_envindex7;  slog::Index** tick_ansindex8;  slog::Index** evalindex9;  slog::Index** extend_env_ansindex10;  slog::Index** $sup70016x51x0x0x1index11;  slog::Index** $sup70016x51x0x0x0index12;  slog::Index** evalindex13;  slog::Index** eval_argsindex14;  slog::Index** appindex15;  slog::Index** tickindex16;  slog::Index** eval_args_ansindex17;  slog::Index** tick_ansindex18;  slog::Index** evalindex19;  slog::Index** appindex20;  slog::Index** tickindex21;  slog::Index** eval_args_ansindex22;  slog::Index** tick_ansindex23;  slog::Index** evalindex24;  slog::Index** extend_env_ansindex25;  slog::Index** eval_ansindex26;  slog::Index** extend_envdelta27;  slog::Index** eval_argsdelta28;  slog::Index** appdelta29;  slog::Index** tickdelta30;  slog::Index** evaldelta31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("eval_ans");
      head_index[0] = readrel34->getIndex(ord33, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord35({1, 2, 3, 0});
      slog::Relation* readrel36 = db->getRelation("extend_env");
      extend_envindex0 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel38 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("eval_ans");
      eval_ansindex2 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel42 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index3 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("lambda");
      lambdaindex4 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel46 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index5 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 3, 0});
      slog::Relation* readrel48 = db->getRelation("eval");
      evalindex6 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 3, 0});
      slog::Relation* readrel50 = db->getRelation("extend_env");
      extend_envindex7 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 3, 0});
      slog::Relation* readrel52 = db->getRelation("extend_env");
      extend_envdelta27 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("tick_ans");
      tick_ansindex8 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({3, 1, 0, 2});
      slog::Relation* readrel56 = db->getRelation("eval");
      evalindex9 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("extend_env_ans");
      extend_env_ansindex10 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel60 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index11 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({4, 0, 3, 1, 2});
      slog::Relation* readrel62 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index12 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({2, 3, 0, 1});
      slog::Relation* readrel64 = db->getRelation("eval");
      evalindex13 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({3, 2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("eval_args");
      eval_argsindex14 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({3, 2, 0, 1});
      slog::Relation* readrel68 = db->getRelation("eval_args");
      eval_argsdelta28 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("app");
      appindex15 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 2, 1});
      slog::Relation* readrel72 = db->getRelation("tick");
      tickindex16 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("eval_args_ans");
      eval_args_ansindex17 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("tick_ans");
      tick_ansindex18 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({2, 3, 0, 1});
      slog::Relation* readrel78 = db->getRelation("eval");
      evalindex19 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({0, 1, 2});
      slog::Relation* readrel80 = db->getRelation("app");
      appindex20 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1, 2});
      slog::Relation* readrel82 = db->getRelation("app");
      appdelta29 = readrel82->getIndex(ord81, true);
      std::vector<u16> ord83({0, 2, 1});
      slog::Relation* readrel84 = db->getRelation("tick");
      tickindex21 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1});
      slog::Relation* readrel86 = db->getRelation("tick");
      tickdelta30 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("eval_args_ans");
      eval_args_ansindex22 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("tick_ans");
      tick_ansindex23 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({3, 1, 0, 2});
      slog::Relation* readrel92 = db->getRelation("eval");
      evalindex24 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({3, 1, 0, 2});
      slog::Relation* readrel94 = db->getRelation("eval");
      evaldelta31 = readrel94->getIndex(ord93, true);
      std::vector<u16> ord95({0, 1});
      slog::Relation* readrel96 = db->getRelation("extend_env_ans");
      extend_env_ansindex25 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("eval_ans");
      eval_ansindex26 = readrel98->getIndex(ord97, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<4,1>(extend_envindex0, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<13,1>($sup70016x51x0x0x1index1, std::array<u64,13>{v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m99) {
          u64 v_c3 = m99[1];
          if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index3, std::array<u64,13>{v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(lambdaindex4, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m100) {
            u64 v_c4 = m100[1]; u64 v_c5 = m100[2];
            if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index5, std::array<u64,13>{v_c5, v_c4, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<4,1>(evalindex6, std::array<u64,4>{v_c5, 0, 0, 0})) return;
            slog::join_probe_old<4,2>(extend_envindex7, extend_envdelta27, std::array<u64,4>{v_c2, v_c4, 0, 0}, [&](const std::array<u64,4>& m101) {
              u64 v_c6 = m101[2]; u64 v_c7 = m101[3];
              if (!slog::exists_probe<2,1>(tick_ansindex8, std::array<u64,2>{v_c6, 0})) return;
              if (!slog::exists_probe<4,2>(evalindex9, std::array<u64,4>{v_c6, v_c5, 0, 0})) return;
              if (!slog::exists_probe<2,1>(extend_env_ansindex10, std::array<u64,2>{v_c7, 0})) return;
              slog::join_probe<13,5>($sup70016x51x0x0x1index11, std::array<u64,13>{v_c5, v_c4, v_c2, v_c3, v_c6, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m102) {
                u64 v_c8 = m102[5]; u64 v_c9 = m102[6]; u64 v_c10 = m102[7]; u64 v_c11 = m102[8]; u64 v_c12 = m102[9]; u64 v_c13 = m102[10]; u64 v_c14 = m102[11]; u64 v_c15 = m102[12];
                slog::join_probe<5,5>($sup70016x51x0x0x0index12, std::array<u64,5>{v_c14, v_c8, v_c13, v_c11, v_c12}, [&](const std::array<u64,5>& m103) {
                  slog::join_probe<4,4>(evalindex13, std::array<u64,4>{v_c13, v_c14, v_c3, v_c11}, [&](const std::array<u64,4>& m104) {
                    slog::join_probe_old<4,4>(eval_argsindex14, eval_argsdelta28, std::array<u64,4>{v_c14, v_c13, v_c9, v_c12}, [&](const std::array<u64,4>& m105) {
                      if (!slog::exists_probe<3,2>(appindex15, std::array<u64,3>{v_c11, v_c12, 0})) return;
                      if (!slog::exists_probe<3,2>(tickindex16, std::array<u64,3>{v_c10, v_c14, 0})) return;
                      if (!slog::exists_probe<2,2>(eval_args_ansindex17, std::array<u64,2>{v_c9, v_c15})) return;
                      if (!slog::exists_probe<2,2>(tick_ansindex18, std::array<u64,2>{v_c10, v_c6})) return;
                      slog::join_probe<4,3>(evalindex19, std::array<u64,4>{v_c13, v_c14, v_c8, 0}, [&](const std::array<u64,4>& m106) {
                        u64 v_c16 = m106[3];
                        slog::join_probe_old<3,3>(appindex20, appdelta29, std::array<u64,3>{v_c16, v_c11, v_c12}, [&](const std::array<u64,3>& m107) {
                          slog::join_probe_old<3,3>(tickindex21, tickdelta30, std::array<u64,3>{v_c10, v_c14, v_c16}, [&](const std::array<u64,3>& m108) {
                            slog::join_probe<2,2>(eval_args_ansindex22, std::array<u64,2>{v_c9, v_c15}, [&](const std::array<u64,2>& m109) {
                              slog::join_probe<2,2>(tick_ansindex23, std::array<u64,2>{v_c10, v_c6}, [&](const std::array<u64,2>& m110) {
                                slog::join_probe_old<4,2>(evalindex24, evaldelta31, std::array<u64,4>{v_c6, v_c5, 0, 0}, [&](const std::array<u64,4>& m111) {
                                  u64 v_c17 = m111[2]; u64 v_c18 = m111[3];
                                  slog::join_probe<2,2>(extend_env_ansindex25, std::array<u64,2>{v_c7, v_c18}, [&](const std::array<u64,2>& m112) {
                                    slog::join_probe<2,1>(eval_ansindex26, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m113) {
                                      u64 v_c19 = m113[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask32* _cont = new ReadTask32(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), false);
  // (crule (pre (let __tconst19gx36 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9QG833 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t9QG833 __t4pAf35 __t4rR634) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t4rR634 p m l r) (cmp lt n m) (let __t204137 (band q m)) (cmp lt __t204137 __tconst19gx36)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t4pAf35 l m n p q r u v)) map.slog:96 #f)
  class ReadTask118 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex114;  slog::Index** mbranchindex115;  slog::Index** mp_uniondelta116;  slog::Index** mbranchdelta117;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord119({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel120 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel120->getIndex(ord119, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord121({2, 0, 1});
      slog::Relation* readrel122 = db->getRelation("mp_union");
      mp_unionindex114 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({2, 0, 1});
      slog::Relation* readrel124 = db->getRelation("mp_union");
      mp_uniondelta116 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({0, 1, 2, 3, 4});
      slog::Relation* readrel126 = db->getRelation("mbranch");
      mbranchindex115 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1, 2, 3, 4});
      slog::Relation* readrel128 = db->getRelation("mbranch");
      mbranchdelta117 = readrel128->getIndex(ord127, true);
  
    }
    ReadTask118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex114, mp_uniondelta116, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m129) {
          u64 v_c25 = m129[1]; u64 v_c26 = m129[2];
          slog::join_probe_old<5,1>(mbranchindex115, mbranchdelta117, std::array<u64,5>{v_c26, 0, 0, 0, 0}, [&](const std::array<u64,5>& m130) {
            u64 v_c27 = m130[1]; u64 v_c28 = m130[2]; u64 v_c29 = m130[3]; u64 v_c30 = m130[4];
            u64 v_c31 = _prim_lt(db, v_c23, v_c28);
            if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c31) return;
            u64 v_c32 = _prim_band(db, v_c22, v_c28);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c33 = _prim_lt(db, v_c32, v_c20);
            if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c33) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c25, v_c29, v_c28, v_c23, v_c27, v_c22, v_c30, v_c24, v_c19}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask118* _cont = new ReadTask118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask118(db,b), false);
  // (crule (pre) (scan $sup70016x95x0x0x1 __t7DhJ358 __t0Rig361 eb er rho rho2 t x) (body (join $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists eval (1 2 3 0) 3 er rho2 t) (exists eval (1 2 3 0) 3 eb rho2 t) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old letrec (1 2 3 0) 3 (1 2 3 0) x er eb __t0Sks357) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho2 t __t6HuT359) (exists eval_ans (0 1) 1 __t6HuT359) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb rho2 t __t63JF360) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask153 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x0index133;  slog::Index** mp_putindex134;  slog::Index** evalindex135;  slog::Index** evalindex136;  slog::Index** evalindex137;  slog::Index** mp_put_ansindex138;  slog::Index** letrecindex139;  slog::Index** evalindex140;  slog::Index** evalindex141;  slog::Index** eval_ansindex142;  slog::Index** evalindex143;  slog::Index** mp_put_ansindex144;  slog::Index** eval_ansindex145;  slog::Index** eval_ansindex146;  slog::Index** eval_ansindex147;  slog::Index** mp_putdelta148;  slog::Index** letrecdelta149;  slog::Index** evaldelta150;  slog::Index** evaldelta151;  slog::Index** evaldelta152;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("eval_ans");
      head_index[0] = readrel155->getIndex(ord154, false);
      outer_rel = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord156({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel157 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index133 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 2, 1, 3});
      slog::Relation* readrel159 = db->getRelation("mp_put");
      mp_putindex134 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 2, 1, 3});
      slog::Relation* readrel161 = db->getRelation("mp_put");
      mp_putdelta148 = readrel161->getIndex(ord160, true);
      std::vector<u16> ord162({2, 3, 0, 1});
      slog::Relation* readrel163 = db->getRelation("eval");
      evalindex135 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 3, 0});
      slog::Relation* readrel165 = db->getRelation("eval");
      evalindex136 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 3, 0});
      slog::Relation* readrel167 = db->getRelation("eval");
      evalindex137 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1});
      slog::Relation* readrel169 = db->getRelation("mp_put_ans");
      mp_put_ansindex138 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 2, 3, 0});
      slog::Relation* readrel171 = db->getRelation("letrec");
      letrecindex139 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 3, 0});
      slog::Relation* readrel173 = db->getRelation("letrec");
      letrecdelta149 = readrel173->getIndex(ord172, true);
      std::vector<u16> ord174({2, 3, 0, 1});
      slog::Relation* readrel175 = db->getRelation("eval");
      evalindex140 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({2, 3, 0, 1});
      slog::Relation* readrel177 = db->getRelation("eval");
      evaldelta150 = readrel177->getIndex(ord176, true);
      std::vector<u16> ord178({1, 2, 3, 0});
      slog::Relation* readrel179 = db->getRelation("eval");
      evalindex141 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 3, 0});
      slog::Relation* readrel181 = db->getRelation("eval");
      evaldelta151 = readrel181->getIndex(ord180, true);
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("eval_ans");
      eval_ansindex142 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 3, 0});
      slog::Relation* readrel185 = db->getRelation("eval");
      evalindex143 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 3, 0});
      slog::Relation* readrel187 = db->getRelation("eval");
      evaldelta152 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("mp_put_ans");
      mp_put_ansindex144 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("eval_ans");
      eval_ansindex145 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("eval_ans");
      eval_ansindex146 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1});
      slog::Relation* readrel195 = db->getRelation("eval_ans");
      eval_ansindex147 = readrel195->getIndex(ord194, false);
  
    }
    ReadTask153(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c37 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c38 = _t[7];
        slog::join_probe<6,6>($sup70016x95x0x0x0index133, std::array<u64,6>{v_c34, v_c13, v_c14, v_c5, v_c36, v_c38}, [&](const std::array<u64,6>& m196) {
          slog::join_probe_old<4,4>(mp_putindex134, mp_putdelta148, std::array<u64,4>{v_c35, v_c38, v_c13, v_c14}, [&](const std::array<u64,4>& m197) {
            if (!slog::exists_probe<4,3>(evalindex135, std::array<u64,4>{v_c13, v_c14, v_c34, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex136, std::array<u64,4>{v_c36, v_c37, v_c14, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex137, std::array<u64,4>{v_c5, v_c37, v_c14, 0})) return;
            if (!slog::exists_probe<2,2>(mp_put_ansindex138, std::array<u64,2>{v_c35, v_c37})) return;
            slog::join_probe_old<4,3>(letrecindex139, letrecdelta149, std::array<u64,4>{v_c38, v_c36, v_c5, 0}, [&](const std::array<u64,4>& m198) {
              u64 v_c39 = m198[3];
              slog::join_probe_old<4,4>(evalindex140, evaldelta150, std::array<u64,4>{v_c13, v_c14, v_c34, v_c39}, [&](const std::array<u64,4>& m199) {
                slog::join_probe_old<4,3>(evalindex141, evaldelta151, std::array<u64,4>{v_c36, v_c37, v_c14, 0}, [&](const std::array<u64,4>& m200) {
                  u64 v_c40 = m200[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex142, std::array<u64,2>{v_c40, 0})) return;
                  slog::join_probe_old<4,3>(evalindex143, evaldelta152, std::array<u64,4>{v_c5, v_c37, v_c14, 0}, [&](const std::array<u64,4>& m201) {
                    u64 v_c41 = m201[3];
                    slog::join_probe<2,2>(mp_put_ansindex144, std::array<u64,2>{v_c35, v_c37}, [&](const std::array<u64,2>& m202) {
                      if (!slog::exists_probe<2,1>(eval_ansindex145, std::array<u64,2>{v_c41, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex146, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m203) {
                        u64 v_c42 = m203[1];
                        slog::join_probe<2,1>(eval_ansindex147, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m204) {
                          u64 v_c19 = m204[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask153* _cont = new ReadTask153(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask153(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mp_union_ans __t6Lp3227 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t6Lp3227 r __t5FeR226) (exists mbranch (4 0 1 2 3) 1 r) (exists $sup5638x98x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join-old mp_union (2 0 1) 1 (2 0 1) __t5FeR226 __t14N0222 __t006N221) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t14N0222 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t14N0222 r) (join-old mbranch (4 0 1 2 3) 2 (4 0 1 2 3) r __t006N221 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t14N0222) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 (4 1 2 6 0 3 5 7 8) p l m r __t14N0222 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t5FeR226) (exists mp_msk (1 2 0) 2 q m) (join-old $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t14N0222 n q u v __t4NVE225) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask230 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex205;  slog::Index** mbranchindex206;  slog::Index** $sup5638x98x0x0x0index207;  slog::Index** $sup5638x98x0x0x1index208;  slog::Index** mp_unionindex209;  slog::Index** $sup5638x98x0x0x0index210;  slog::Index** $sup5638x98x0x0x1index211;  slog::Index** mbranchindex212;  slog::Index** $sup5638x98x0x0x1index213;  slog::Index** mp_mskindex214;  slog::Index** mp_msk_ansindex215;  slog::Index** $sup5638x98x0x0x0index216;  slog::Index** mbranchindex217;  slog::Index** mp_mskindex218;  slog::Index** $sup5638x98x0x0x1index219;  slog::Index** mbranchindex220;  slog::Index** mp_mskindex221;  slog::Index** mp_msk_ansindex222;  slog::Index** mp_uniondelta223;  slog::Index** mp_uniondelta224;  slog::Index** mbranchdelta225;  slog::Index** $sup5638x98x0x0x0delta226;  slog::Index** $sup5638x98x0x0x1delta227;  slog::Index** mbranchdelta228;  slog::Index** mp_mskdelta229;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord231({0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("mp_union");
      mp_unionindex205 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1, 2});
      slog::Relation* readrel234 = db->getRelation("mp_union");
      mp_uniondelta223 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({4, 0, 1, 2, 3});
      slog::Relation* readrel236 = db->getRelation("mbranch");
      mbranchindex206 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel238 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index207 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel240 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index208 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({2, 0, 1});
      slog::Relation* readrel242 = db->getRelation("mp_union");
      mp_unionindex209 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({2, 0, 1});
      slog::Relation* readrel244 = db->getRelation("mp_union");
      mp_uniondelta224 = readrel244->getIndex(ord243, true);
      std::vector<u16> ord245({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel246 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index210 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel248 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index211 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({4, 0, 1, 2, 3});
      slog::Relation* readrel250 = db->getRelation("mbranch");
      mbranchindex212 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({4, 0, 1, 2, 3});
      slog::Relation* readrel252 = db->getRelation("mbranch");
      mbranchdelta225 = readrel252->getIndex(ord251, true);
      std::vector<u16> ord253({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel254 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index213 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 0, 1});
      slog::Relation* readrel256 = db->getRelation("mp_msk");
      mp_mskindex214 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex215 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel260 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index216 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel262 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0delta226 = readrel262->getIndex(ord261, true);
      std::vector<u16> ord263({1, 2, 3, 4, 0});
      slog::Relation* readrel264 = db->getRelation("mbranch");
      mbranchindex217 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("mp_msk");
      mp_mskindex218 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel268 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index219 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel270 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta227 = readrel270->getIndex(ord269, true);
      std::vector<u16> ord271({1, 2, 3, 4, 0});
      slog::Relation* readrel272 = db->getRelation("mbranch");
      mbranchindex220 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 2, 3, 4, 0});
      slog::Relation* readrel274 = db->getRelation("mbranch");
      mbranchdelta228 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({1, 2, 0});
      slog::Relation* readrel276 = db->getRelation("mp_msk");
      mp_mskindex221 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 0});
      slog::Relation* readrel278 = db->getRelation("mp_msk");
      mp_mskdelta229 = readrel278->getIndex(ord277, true);
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex222 = readrel280->getIndex(ord279, false);
  
    }
    ReadTask230(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe_old<3,1>(mp_unionindex205, mp_uniondelta223, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m281) {
          u64 v_c30 = m281[1]; u64 v_c45 = m281[2];
          if (!slog::exists_probe<5,1>(mbranchindex206, std::array<u64,5>{v_c30, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index207, std::array<u64,9>{v_c30, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index208, std::array<u64,10>{v_c30, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex209, mp_uniondelta224, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m282) {
            u64 v_c46 = m282[1]; u64 v_c47 = m282[2];
            if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index210, std::array<u64,9>{v_c46, v_c30, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index211, std::array<u64,10>{v_c46, v_c30, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex212, mbranchdelta225, std::array<u64,5>{v_c30, v_c47, 0, 0, 0}, [&](const std::array<u64,5>& m283) {
              u64 v_c27 = m283[2]; u64 v_c28 = m283[3]; u64 v_c29 = m283[4];
              if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index213, std::array<u64,10>{v_c30, v_c29, v_c28, v_c27, v_c46, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex214, std::array<u64,3>{v_c28, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex215, std::array<u64,2>{v_c27, 0})) return;
              slog::join_probe_old<9,5>($sup5638x98x0x0x0index216, $sup5638x98x0x0x0delta226, std::array<u64,9>{v_c27, v_c29, v_c28, v_c30, v_c46, 0, 0, 0, 0}, [&](const std::array<u64,9>& m284) {
                u64 v_c23 = m284[5]; u64 v_c22 = m284[6]; u64 v_c24 = m284[7]; u64 v_c19 = m284[8];
                u64 v_c48 = _prim_lt(db, v_c23, v_c28);
                if (v_c48 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                if (!v_c48) return;
                if (!slog::exists_probe<5,5>(mbranchindex217, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, v_c45})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex218, std::array<u64,3>{v_c22, v_c28, 0})) return;
                slog::join_probe_old<10,9>($sup5638x98x0x0x1index219, $sup5638x98x0x0x1delta227, std::array<u64,10>{v_c30, v_c29, v_c28, v_c27, v_c46, v_c23, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,10>& m286) {
                  u64 v_c49 = m286[9];
                  slog::join_probe_old<5,5>(mbranchindex220, mbranchdelta228, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, v_c45}, [&](const std::array<u64,5>& m287) {
                    slog::join_probe_old<3,3>(mp_mskindex221, mp_mskdelta229, std::array<u64,3>{v_c22, v_c28, v_c49}, [&](const std::array<u64,3>& m288) {
                      slog::join_probe<2,2>(mp_msk_ansindex222, std::array<u64,2>{v_c49, v_c27}, [&](const std::array<u64,2>& m289) {
                        u64 v_c50 = _prim_band(db, v_c22, v_c28);
                        if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c51 = _prim_gt(db, v_c50, v_c43);
                        if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c51) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c46, v_c18, v_c29, v_c28, v_c27});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c29, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask230* _cont = new ReadTask230(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask230(db,b), false);
  // (crule (pre (let __trid8Kgp1066 const5fedc35d1451fa93f8022abf) (let __trel3SCo1067 const3a655602588fe6d8c59d4a5a) (let __tcol9ySC1068 const5feceb66ffc86f38d952786c) (let __trel8PU21069 const3a655602588fe6d8c59d4a5a) (let __tcol8Q8V1070 const6b86b273ff34fce19d6b804e)) (scan $sup5638x67x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8Kgp1066 __trel3SCo1067 __tcol9ySC1068 (1 2 3 4 0)) (tycheck k (accept int) __trid8Kgp1066 __trel8PU21069 __tcol8Q8V1070 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __4rKq1065 t k)) map.slog:68 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid292;  u32 sid291;  u32 sid293;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x67x0x0x0");
      sid292 = db->getRelation("_enum")->getStructId();
      sid291 = db->getRelation("mbranch")->getStructId();
      sid293 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_const5fedc35d1451fa93f8022abf;
      u64 v_c53 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c54 = v_const5feceb66ffc86f38d952786c;
      u64 v_c55 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c19 = _t[3];
        ++_fires;
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid291 || decode_struct_id(v_c14) == sid292 || decode_struct_id(v_c14) == sid293))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c52, v_c53, v_c54, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c58)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c52, v_c55, v_c56, v_c58}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c14, v_c58}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:$sup5638x67x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask294* _cont = new ReadTask294(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask294(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mbranch __t105R678 q n u v) (body (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 4 v n q u) (exists mp_union (2 0 1) 1 __t105R678) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 v) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t5Sgr680 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t105R678 __t5Sgr680) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t5Sgr680 l m p r __t78qG683) (exists mp_msk (1 2 0) 3 p n __t78qG683) (exists mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Sgr680 __t0Aux684 __t105R678) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index295;  slog::Index** mp_unionindex296;  slog::Index** mp_mskindex297;  slog::Index** mp_msk_ansindex298;  slog::Index** mp_unionindex299;  slog::Index** $sup5638x107x0x0x0index300;  slog::Index** mbranchindex301;  slog::Index** mp_unionindex302;  slog::Index** mp_mskindex303;  slog::Index** $sup5638x107x0x0x1index304;  slog::Index** mp_mskindex305;  slog::Index** mp_msk_ansindex306;  slog::Index** mbranchindex307;  slog::Index** mp_unionindex308;  slog::Index** mp_mskindex309;  slog::Index** mp_msk_ansindex310;  slog::Index** mp_unionindex311;  slog::Index** mp_union_ansindex312;  slog::Index** mbranchdelta313;  slog::Index** mp_uniondelta314;  slog::Index** mp_mskdelta315;  slog::Index** mp_uniondelta316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord318({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel319 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index295 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({2, 0, 1});
      slog::Relation* readrel321 = db->getRelation("mp_union");
      mp_unionindex296 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({2, 0, 1});
      slog::Relation* readrel323 = db->getRelation("mp_msk");
      mp_mskindex297 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 0});
      slog::Relation* readrel325 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex298 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({2, 0, 1});
      slog::Relation* readrel327 = db->getRelation("mp_union");
      mp_unionindex299 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel329 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index300 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 3, 4, 0});
      slog::Relation* readrel331 = db->getRelation("mbranch");
      mbranchindex301 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({2, 0, 1});
      slog::Relation* readrel333 = db->getRelation("mp_union");
      mp_unionindex302 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 0});
      slog::Relation* readrel335 = db->getRelation("mp_msk");
      mp_mskindex303 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel337 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index304 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 0});
      slog::Relation* readrel339 = db->getRelation("mp_msk");
      mp_mskindex305 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex306 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 3, 4, 0});
      slog::Relation* readrel343 = db->getRelation("mbranch");
      mbranchindex307 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 3, 4, 0});
      slog::Relation* readrel345 = db->getRelation("mbranch");
      mbranchdelta313 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1, 2});
      slog::Relation* readrel347 = db->getRelation("mp_union");
      mp_unionindex308 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1, 2});
      slog::Relation* readrel349 = db->getRelation("mp_union");
      mp_uniondelta314 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("mp_msk");
      mp_mskindex309 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 0});
      slog::Relation* readrel353 = db->getRelation("mp_msk");
      mp_mskdelta315 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1});
      slog::Relation* readrel355 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex310 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({1, 2, 0});
      slog::Relation* readrel357 = db->getRelation("mp_union");
      mp_unionindex311 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("mp_union");
      mp_uniondelta316 = readrel359->getIndex(ord358, true);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("mp_union_ans");
      mp_union_ansindex312 = readrel361->getIndex(ord360, false);
  
    }
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c60 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x107x0x0x1index295, std::array<u64,10>{v_c19, v_c23, v_c22, v_c24, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex296, std::array<u64,3>{v_c60, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex297, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex298, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex299, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x107x0x0x0index300, std::array<u64,9>{v_c22, v_c23, v_c24, v_c19, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m362) {
          u64 v_c61 = m362[4]; u64 v_c29 = m362[5]; u64 v_c28 = m362[6]; u64 v_c27 = m362[7]; u64 v_c30 = m362[8];
          u64 v_c62 = _prim_lt(db, v_c28, v_c23);
          if (v_c62 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c62) return;
          if (!slog::exists_probe<5,4>(mbranchindex301, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex302, std::array<u64,3>{v_c60, v_c61, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex303, std::array<u64,3>{v_c27, v_c23, 0})) return;
          slog::join_probe<10,9>($sup5638x107x0x0x1index304, std::array<u64,10>{v_c19, v_c23, v_c22, v_c24, v_c61, v_c29, v_c28, v_c27, v_c30, 0}, [&](const std::array<u64,10>& m364) {
            u64 v_c63 = m364[9];
            if (!slog::exists_probe<3,3>(mp_mskindex305, std::array<u64,3>{v_c27, v_c23, v_c63})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex306, std::array<u64,2>{v_c63, v_c22})) return;
            slog::join_probe_old<5,4>(mbranchindex307, mbranchdelta313, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m365) {
              u64 v_c64 = m365[4];
              slog::join_probe_old<3,3>(mp_unionindex308, mp_uniondelta314, std::array<u64,3>{v_c61, v_c64, v_c60}, [&](const std::array<u64,3>& m366) {
                slog::join_probe_old<3,3>(mp_mskindex309, mp_mskdelta315, std::array<u64,3>{v_c27, v_c23, v_c63}, [&](const std::array<u64,3>& m367) {
                  slog::join_probe<2,2>(mp_msk_ansindex310, std::array<u64,2>{v_c63, v_c22}, [&](const std::array<u64,2>& m368) {
                    slog::join_probe_old<3,2>(mp_unionindex311, mp_uniondelta316, std::array<u64,3>{v_c64, v_c19, 0}, [&](const std::array<u64,3>& m369) {
                      u64 v_c65 = m369[2];
                      slog::join_probe<2,1>(mp_union_ansindex312, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m370) {
                        u64 v_c18 = m370[1];
                        u64 v_c66 = _prim_band(db, v_c27, v_c23);
                        if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c67 = _prim_gt(db, v_c66, v_c59);
                        if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c67) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c61, v_c18, v_c23, v_c22, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst3zaK478 const0933fb667296882d8c45abca) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e) (let __tconst91JR503 const90fb9068eda6f2d68bb61c33)) (scan temp7ZBA2004 __t0cTh509 __t18Fx502 __t2zNy470 __t3yjA501 __t4qrC508 __t7hSc477) (body (exists app (2 0 1) 1 __t18Fx502) (exists primref (1 0) 1 __tconst6GsZ491) (exists primref (1 0) 1 __tconst3zaK478) (exists app (2 0 1) 1 __t7hSc477) (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (join primref (1 0) 1 __tconst91JR503 __t8Gth504) (join app (1 2 0) 2 __t8Gth504 __t18Fx502 __t0Vtj505) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join primref (1 0) 1 __tconst3zaK478 __t2abh479) (join app (1 2 0) 2 __t2abh479 __t7hSc477 __t9p5V480) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469) (let __t0f2O482 (lpush __t4qrC508 __t9p5V480))) (head (emit-temp temp9q5M2005 __t0Vtj505 __t0cTh509 __t0f2O482 __t2zNy470 __t3yjA501)) kcfa.slog:40 #f)
  class ReadTask385 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex372;  slog::Index** primrefindex373;  slog::Index** primrefindex374;  slog::Index** appindex375;  slog::Index** numindex376;  slog::Index** refindex377;  slog::Index** primrefindex378;  slog::Index** appindex379;  slog::Index** primrefindex380;  slog::Index** primrefindex381;  slog::Index** appindex382;  slog::Index** numindex383;  slog::Index** refindex384;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9q5M2005");
      outer_rel = db->getRelation("temp7ZBA2004");
      std::vector<u16> ord386({2, 0, 1});
      slog::Relation* readrel387 = db->getRelation("app");
      appindex372 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("primref");
      primrefindex373 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 0});
      slog::Relation* readrel391 = db->getRelation("primref");
      primrefindex374 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({2, 0, 1});
      slog::Relation* readrel393 = db->getRelation("app");
      appindex375 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("num");
      numindex376 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("ref");
      refindex377 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 0});
      slog::Relation* readrel399 = db->getRelation("primref");
      primrefindex378 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("app");
      appindex379 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0});
      slog::Relation* readrel403 = db->getRelation("primref");
      primrefindex380 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 0});
      slog::Relation* readrel405 = db->getRelation("primref");
      primrefindex381 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("app");
      appindex382 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("num");
      numindex383 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("ref");
      refindex384 = readrel411->getIndex(ord410, false);
  
    }
    ReadTask385(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c69 = v_const0933fb667296882d8c45abca;
      u64 v_c70 = v_consted725292f5f32d61535958c1;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c75 = _t[2];
        u64 v_c76 = _t[3];
        u64 v_c77 = _t[4];
        u64 v_c78 = _t[5];
        if (!slog::exists_probe<3,1>(appindex372, std::array<u64,3>{v_c74, 0, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex373, std::array<u64,2>{v_c70, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex374, std::array<u64,2>{v_c69, 0})) return;
        if (!slog::exists_probe<3,1>(appindex375, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<2,1>(numindex376, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<2,1>(refindex377, std::array<u64,2>{v_c68, 0})) return;
        slog::join_probe<2,1>(primrefindex378, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m412) {
          u64 v_c79 = m412[1];
          slog::join_probe<3,2>(appindex379, std::array<u64,3>{v_c79, v_c74, 0}, [&](const std::array<u64,3>& m413) {
            u64 v_c80 = m413[2];
            slog::join_probe<2,1>(primrefindex380, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m414) {
              u64 v_c81 = m414[1];
              slog::join_probe<2,1>(primrefindex381, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m415) {
                u64 v_c82 = m415[1];
                slog::join_probe<3,2>(appindex382, std::array<u64,3>{v_c82, v_c78, 0}, [&](const std::array<u64,3>& m416) {
                  u64 v_c83 = m416[2];
                  slog::join_probe<2,1>(numindex383, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m417) {
                    u64 v_c84 = m417[1];
                    slog::join_probe<2,1>(refindex384, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m418) {
                      u64 v_c85 = m418[1];
                      u64 v_c86 = _prim_lpush(db, v_c77, v_c83);
                      if (v_c86 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c80, v_c73, v_c86, v_c75, v_c76});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp7ZBA2004", _fires);
  
      if (!_done)
      {
        ReadTask385* _cont = new ReadTask385(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask385(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t16An260 __v1) (body (join mp_hsb_ans (0 1) 1 __t16An260 __v3) (join-old mp_hsb (0 1) 1 (0 1) __t16An260 __t7Dpg261) (join-old $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk8NxN1836 (bxor p0 p1)) (eq __t7Dpg261 chk8NxN1836)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t16An260 __t16An260 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask424 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex419;  slog::Index** mp_hsbindex420;  slog::Index** $sup5638x29x0x0x1index421;  slog::Index** mp_hsbdelta422;  slog::Index** $sup5638x29x0x0x1delta423;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord425({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel426 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel426->getIndex(ord425, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex419 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1});
      slog::Relation* readrel430 = db->getRelation("mp_hsb");
      mp_hsbindex420 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("mp_hsb");
      mp_hsbdelta422 = readrel432->getIndex(ord431, true);
      std::vector<u16> ord433({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel434 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index421 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel436 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta423 = readrel436->getIndex(ord435, true);
  
    }
    ReadTask424(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c87 = _t[0];
        u64 v_c88 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex419, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m437) {
          u64 v_c89 = m437[1];
          slog::join_probe_old<2,1>(mp_hsbindex420, mp_hsbdelta422, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m438) {
            u64 v_c90 = m438[1];
            slog::join_all_old<7>($sup5638x29x0x0x1index421, $sup5638x29x0x0x1delta423, [&](const std::array<u64,7>& m439) {
              u64 v_c91 = m439[0]; u64 v_c18 = m439[1]; u64 v_c57 = m439[2]; u64 v_c92 = m439[3]; u64 v_c93 = m439[4]; u64 v_c94 = m439[5]; u64 v_c95 = m439[6];
              u64 v_c96 = _prim_bxor(db, v_c92, v_c93);
              if (v_c96 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c90 != v_c96) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c91, v_c18, v_c89, v_c88, v_c57, v_c87, v_c87, v_c92, v_c93, v_c94, v_c95}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask424* _cont = new ReadTask424(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask424(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f) (let __tconst7lpr731 const0933fb667296882d8c45abca) (let __tconst9wm7741 const73475cb40a568e8da8a045ce) (let __tconst1Nf0752 const90fb9068eda6f2d68bb61c33)) (scan temp6vSW1900 __t0esl751 __t3uI9730 __t75NQ757 __t81pk743 __t8k6P758 __t9E2t720) (body (exists ref (1 0) 1 __tconst9wm7741) (exists lambda (1 2 0) 1 __t81pk743) (exists primref (1 0) 1 __tconst7lpr731) (exists ref (1 0) 1 __tconst6I9K760) (exists app (2 0 1) 1 __t9E2t720) (join primref (1 0) 1 __tconst1Nf0752 __t6Asn753) (join ref (1 0) 1 __tconst9wm7741 __t6TM2740) (join lambda (1 2 0) 2 __t81pk743 __t6TM2740 __t2X4e744) (join primref (1 0) 1 __tconst7lpr731 __t1nv4732) (join ref (1 0) 1 __tconst6I9K760 __t9NO9722) (join app (1 2 0) 2 __t9NO9722 __t9E2t720 __t5xOK723)) (head (emit-temp temp6XDA1901 __t0esl751 __t2X4e744 __t3uI9730 __t5xOK723 __t75NQ757 __t8k6P758) (mkstruct app (1 2 0) __t55Nx733 __t1nv4732 __t3uI9730) (mkstruct app (1 2 0) __t1WhI754 __t6Asn753 __t0esl751)) kcfa.slog:70 #f)
  class ReadTask451 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex440;  slog::Index** lambdaindex441;  slog::Index** primrefindex442;  slog::Index** refindex443;  slog::Index** appindex444;  slog::Index** primrefindex445;  slog::Index** refindex446;  slog::Index** lambdaindex447;  slog::Index** primrefindex448;  slog::Index** refindex449;  slog::Index** appindex450;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6XDA1901");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp6vSW1900");
      std::vector<u16> ord452({1, 0});
      slog::Relation* readrel453 = db->getRelation("ref");
      refindex440 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("lambda");
      lambdaindex441 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 0});
      slog::Relation* readrel457 = db->getRelation("primref");
      primrefindex442 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("ref");
      refindex443 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({2, 0, 1});
      slog::Relation* readrel461 = db->getRelation("app");
      appindex444 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("primref");
      primrefindex445 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("ref");
      refindex446 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("lambda");
      lambdaindex447 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("primref");
      primrefindex448 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 0});
      slog::Relation* readrel471 = db->getRelation("ref");
      refindex449 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 2, 0});
      slog::Relation* readrel473 = db->getRelation("app");
      appindex450 = readrel473->getIndex(ord472, false);
  
    }
    ReadTask451(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_constd59eced1ded07f84c145592f;
      u64 v_c98 = v_const0933fb667296882d8c45abca;
      u64 v_c99 = v_const73475cb40a568e8da8a045ce;
      u64 v_c100 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c103 = _t[2];
        u64 v_c104 = _t[3];
        u64 v_c105 = _t[4];
        u64 v_c106 = _t[5];
        if (!slog::exists_probe<2,1>(refindex440, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex441, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex442, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<2,1>(refindex443, std::array<u64,2>{v_c97, 0})) return;
        if (!slog::exists_probe<3,1>(appindex444, std::array<u64,3>{v_c106, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex445, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m474) {
          u64 v_c107 = m474[1];
          slog::join_probe<2,1>(refindex446, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m475) {
            u64 v_c108 = m475[1];
            slog::join_probe<3,2>(lambdaindex447, std::array<u64,3>{v_c104, v_c108, 0}, [&](const std::array<u64,3>& m476) {
              u64 v_c109 = m476[2];
              slog::join_probe<2,1>(primrefindex448, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m477) {
                u64 v_c110 = m477[1];
                slog::join_probe<2,1>(refindex449, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m478) {
                  u64 v_c111 = m478[1];
                  slog::join_probe<3,2>(appindex450, std::array<u64,3>{v_c111, v_c106, 0}, [&](const std::array<u64,3>& m479) {
                    u64 v_c112 = m479[2];
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c101, v_c109, v_c102, v_c112, v_c103, v_c105});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c110, v_c102}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c107, v_c101}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp6vSW1900", _fires);
  
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
  // (crule (pre (let __tconst4JFo1084 constcd2a69ce5ca278db1d6da969) (let _00024sqc2XJk894 constd4735e3a265e16eee03f5971) (let _00024sqc3Vvh895 const5feceb66ffc86f38d952786c) (let _00024sqc1G23896 const6b86b273ff34fce19d6b804e) (let _00024sqo5Yvx897 const5feceb66ffc86f38d952786c) (let _00024sqo6jkp898 const6b86b273ff34fce19d6b804e) (let _00024sqo3xdn899 const6b86b273ff34fce19d6b804e) (let _00024sqo4MmQ900 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4MmQ900 __t6Yod544 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Yvx897 __t6Yod544 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo6jkp898 __t6Yod544 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo3xdn899 __t6Yod544 _00024seq2) (join _enum (0 1) 2 __t6Yod544 __tconst4JFo1084) (join delta (2 0 1) 1 _00024seq2 __t7695542 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql014l892 (aslst _00024seq2)) (let chk4IYj1807 (llen _00024sql014l892)) (eq _00024sqc2XJk894 chk4IYj1807) (letp chk7Kto1808 (lref _00024sql014l892 _00024sqc3Vvh895)) (eq __t6Yod544 chk7Kto1808) (letp chk7l0e1809 (lref _00024sql014l892 _00024sqc1G23896)) (eq __t6Yod544 chk7l0e1809)) (head (emit-temp temp4Zu91795 __t7695542 b) (mkstruct boolval (1 0) __t4iE5541 b)) interp.slog:117 #f)
  class ReadTask487 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex480;  slog::Index** $seq_atindex481;  slog::Index** $seq_atrindex482;  slog::Index** _enumindex483;  slog::Index** deltaindex484;  slog::Index** comparison_opindex485;  slog::Index** any_boolindex486;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Zu91795");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord488({1, 0, 2});
      slog::Relation* readrel489 = db->getRelation("$seq_atr");
      driver_index = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({1, 0, 2});
      slog::Relation* readrel491 = db->getRelation("$seq_at");
      $seq_atindex480 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 0, 2});
      slog::Relation* readrel493 = db->getRelation("$seq_at");
      $seq_atindex481 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({1, 0, 2});
      slog::Relation* readrel495 = db->getRelation("$seq_atr");
      $seq_atrindex482 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("_enum");
      _enumindex483 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({2, 0, 1});
      slog::Relation* readrel499 = db->getRelation("delta");
      deltaindex484 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0});
      slog::Relation* readrel501 = db->getRelation("comparison_op");
      comparison_opindex485 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0});
      slog::Relation* readrel503 = db->getRelation("any_bool");
      any_boolindex486 = readrel503->getIndex(ord502, false);
  
    }
    ReadTask487(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c113 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c114 = v_constd4735e3a265e16eee03f5971;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c117 = v_const5feceb66ffc86f38d952786c;
      u64 v_c118 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c119 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c120 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c120, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m504) {
        u64 v_c121 = m504[1];
        u64 v_c122 = m504[2];
        if (buckethash(v_c121) != bucket) return;
        slog::join_probe<3,3>($seq_atindex480, std::array<u64,3>{v_c117, v_c121, v_c122}, [&](const std::array<u64,3>& m505) {
          slog::join_probe<3,3>($seq_atindex481, std::array<u64,3>{v_c118, v_c121, v_c122}, [&](const std::array<u64,3>& m506) {
            slog::join_probe<3,3>($seq_atrindex482, std::array<u64,3>{v_c119, v_c121, v_c122}, [&](const std::array<u64,3>& m507) {
              slog::join_probe<2,2>(_enumindex483, std::array<u64,2>{v_c121, v_c113}, [&](const std::array<u64,2>& m508) {
                slog::join_probe<3,1>(deltaindex484, std::array<u64,3>{v_c122, 0, 0}, [&](const std::array<u64,3>& m509) {
                  u64 v_c123 = m509[1]; u64 v_c124 = m509[2];
                  slog::join_probe<1,1>(comparison_opindex485, std::array<u64,1>{v_c124}, [&](const std::array<u64,1>& m510) {
                    slog::join_all<1>(any_boolindex486, [&](const std::array<u64,1>& m511) {
                      u64 v_c125 = m511[0];
                      bool ok512 = true;
                      u64 v_c126 = _prim_aslst(db, v_c122, &ok512);
                      if (!ok512) return;
                      u64 v_c127 = _prim_llen(db, v_c126);
                      if (v_c127 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                      if (v_c114 != v_c127) return;
                      bool ok513 = true;
                      u64 v_c128 = _prim_lref(db, v_c126, v_c115, &ok513);
                      if (!ok513) return;
                      if (v_c121 != v_c128) return;
                      bool ok514 = true;
                      u64 v_c129 = _prim_lref(db, v_c126, v_c116, &ok514);
                      if (!ok514) return;
                      if (v_c121 != v_c129) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c123, v_c125});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c125}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask487* _cont = new ReadTask487(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask487(db,b), false);
  // (crule (pre (let __tconst0doI1201 constd01925b37634a1a9d24159d8) (let __tconst79E4354 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t0MX8356 __t7ZGs355 k) (body (join _enum (0 1) 2 __t7ZGs355 __tconst0doI1201)) (head (emit mp_has0_ans (0 1) __t0MX8356 __tconst79E4354)) map.slog:57 #f)
  class ReadTask516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel518->getIndex(ord517, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("_enum");
      _enumindex515 = readrel520->getIndex(ord519, false);
  
    }
    ReadTask516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c130 = v_constd01925b37634a1a9d24159d8;
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
        u64 v_c133 = _t[1];
        u64 v_c58 = _t[2];
        slog::join_probe<2,2>(_enumindex515, std::array<u64,2>{v_c133, v_c130}, [&](const std::array<u64,2>& m521) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c132, v_c131}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:57", "delta:mp_has0", _fires);
  
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
  // (crule (pre) (scan eval __t7uXV815 er rho t) (body (exists mp_put (1 3 0 2) 2 rho t) (exists eval_ans (0 1) 1 __t7uXV815) (join $sup70016x92x0x0x0 (2 3 4 0 1 5) 3 er rho t __d0 eb x) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t3Rle816) (exists mp_put_ans (0 1) 1 __t3Rle816) (join eval_ans (0 1) 1 __t7uXV815 vr) (join mp_put_ans (0 1) 1 __t3Rle816 __v0)) (head (emit $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) __t7uXV815 vr __d0 __t3Rle816 __v0 eb er rho t x)) interp.slog:93 #f)
  class ReadTask530 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex522;  slog::Index** eval_ansindex523;  slog::Index** $sup70016x92x0x0x0index524;  slog::Index** mp_putindex525;  slog::Index** mp_put_ansindex526;  slog::Index** eval_ansindex527;  slog::Index** mp_put_ansindex528;  slog::Index** mp_putdelta529;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord531({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel532 = db->getRelation("$sup70016x92x0x0x1");
      head_index[0] = readrel532->getIndex(ord531, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord533({1, 3, 0, 2});
      slog::Relation* readrel534 = db->getRelation("mp_put");
      mp_putindex522 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("eval_ans");
      eval_ansindex523 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({2, 3, 4, 0, 1, 5});
      slog::Relation* readrel538 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index524 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 3, 0});
      slog::Relation* readrel540 = db->getRelation("mp_put");
      mp_putindex525 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 3, 0});
      slog::Relation* readrel542 = db->getRelation("mp_put");
      mp_putdelta529 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({0, 1});
      slog::Relation* readrel544 = db->getRelation("mp_put_ans");
      mp_put_ansindex526 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("eval_ans");
      eval_ansindex527 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("mp_put_ans");
      mp_put_ansindex528 = readrel548->getIndex(ord547, false);
  
    }
    ReadTask530(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        if (!slog::exists_probe<4,2>(mp_putindex522, std::array<u64,4>{v_c13, v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex523, std::array<u64,2>{v_c134, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index524, std::array<u64,6>{v_c36, v_c13, v_c14, 0, 0, 0}, [&](const std::array<u64,6>& m549) {
          u64 v_c57 = m549[3]; u64 v_c5 = m549[4]; u64 v_c38 = m549[5];
          slog::join_probe_old<4,3>(mp_putindex525, mp_putdelta529, std::array<u64,4>{v_c13, v_c38, v_c14, 0}, [&](const std::array<u64,4>& m550) {
            u64 v_c135 = m550[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex526, std::array<u64,2>{v_c135, 0})) return;
            slog::join_probe<2,1>(eval_ansindex527, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m551) {
              u64 v_c42 = m551[1];
              slog::join_probe<2,1>(mp_put_ansindex528, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m552) {
                u64 v_c18 = m552[1];
                ++_fires;
                slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c134, v_c42, v_c57, v_c135, v_c18, v_c5, v_c36, v_c13, v_c14, v_c38}, std::array<u16,10>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
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
  // (crule (pre (let __trid9dmk1218 constbb851acf11177e0e526ed8e5) (let __trel6kxm1219 constdd7bbf31ce5f578b9805e840) (let __tcol5SON1220 const5feceb66ffc86f38d952786c) (let __trel7Miz1221 constdd7bbf31ce5f578b9805e840) (let __tcol91DH1222 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid9dmk1218 __trel6kxm1219 __tcol5SON1220 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid9dmk1218 __trel7Miz1221 __tcol91DH1222 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __0YjI1217 p0 __v1)) map.slog:26 #f)
  class ReadTask553 : public slog::Task
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
    ReadTask553(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_constbb851acf11177e0e526ed8e5;
      u64 v_c137 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c138 = v_const5feceb66ffc86f38d952786c;
      u64 v_c139 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c57 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c141 = _t[2];
        u64 v_c142 = _t[3];
        u64 v_c18 = _t[4];
        u64 v_c88 = _t[5];
        u64 v_c89 = _t[6];
        u64 v_c92 = _t[7];
        u64 v_c93 = _t[8];
        u64 v_c94 = _t[9];
        u64 v_c95 = _t[10];
        ++_fires;
        if (!(is_int(v_c92)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c136, v_c137, v_c138, v_c92}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c88)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c136, v_c139, v_c140, v_c88}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c92, v_c88}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask553* _cont = new ReadTask553(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask553(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo41sW869 __t4CTM7 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5fwv868 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1lCq870 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4Tlp871 __t4CTM7 _00024seq2) (exists _enum (1 0) 1 __tconst6yBc1412) (join delta (1 2 0) 2 __tconst2fTo4 _00024seq2 __t9sv95) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join prim (0 1) 1 __t4CTM7 op) (letp _00024sql5qXm863 (aslst _00024seq2)) (let chk1k671928 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk1k671928) (letp chk0UWo1929 (lref _00024sql5qXm863 _00024sqc32Jr866)) (eq __t4CTM7 chk0UWo1929) (letp chk6XsA1930 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk6XsA1930)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask563 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex554;  slog::Index** $seq_atrindex555;  slog::Index** $seq_atrindex556;  slog::Index** _enumindex557;  slog::Index** deltaindex558;  slog::Index** _enumindex559;  slog::Index** primindex560;  slog::Index** $seq_atrdelta561;  slog::Index** $seq_atrdelta562;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord564({1, 0, 2});
      slog::Relation* readrel565 = db->getRelation("$seq_at");
      driver_index = readrel565->getIndex(ord564, true);
      std::vector<u16> ord566({1, 0, 2});
      slog::Relation* readrel567 = db->getRelation("$seq_at");
      $seq_atindex554 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0, 2});
      slog::Relation* readrel569 = db->getRelation("$seq_atr");
      $seq_atrindex555 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0, 2});
      slog::Relation* readrel571 = db->getRelation("$seq_atr");
      $seq_atrdelta561 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({1, 0, 2});
      slog::Relation* readrel573 = db->getRelation("$seq_atr");
      $seq_atrindex556 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0, 2});
      slog::Relation* readrel575 = db->getRelation("$seq_atr");
      $seq_atrdelta562 = readrel575->getIndex(ord574, true);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("_enum");
      _enumindex557 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 2, 0});
      slog::Relation* readrel579 = db->getRelation("delta");
      deltaindex558 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 0});
      slog::Relation* readrel581 = db->getRelation("_enum");
      _enumindex559 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({0, 1});
      slog::Relation* readrel583 = db->getRelation("prim");
      primindex560 = readrel583->getIndex(ord582, false);
  
    }
    ReadTask563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c143 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c144 = v_const06abaa100ecef791ce028c56;
      u64 v_c145 = v_constd4735e3a265e16eee03f5971;
      u64 v_c146 = v_const5feceb66ffc86f38d952786c;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c149, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m584) {
        u64 v_c152 = m584[1];
        u64 v_c122 = m584[2];
        if (buckethash(v_c152) != bucket) return;
        slog::join_probe<3,3>($seq_atindex554, std::array<u64,3>{v_c148, v_c152, v_c122}, [&](const std::array<u64,3>& m585) {
          slog::join_probe_old<3,3>($seq_atrindex555, $seq_atrdelta561, std::array<u64,3>{v_c150, v_c152, v_c122}, [&](const std::array<u64,3>& m586) {
            slog::join_probe_old<3,3>($seq_atrindex556, $seq_atrdelta562, std::array<u64,3>{v_c151, v_c152, v_c122}, [&](const std::array<u64,3>& m587) {
              if (!slog::exists_probe<2,1>(_enumindex557, std::array<u64,2>{v_c143, 0})) return;
              slog::join_probe<3,2>(deltaindex558, std::array<u64,3>{v_c144, v_c122, 0}, [&](const std::array<u64,3>& m588) {
                u64 v_c153 = m588[2];
                slog::join_probe<2,1>(_enumindex559, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m589) {
                  u64 v_c154 = m589[1];
                  slog::join_probe<2,1>(primindex560, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m590) {
                    u64 v_c124 = m590[1];
                    bool ok591 = true;
                    u64 v_c155 = _prim_aslst(db, v_c122, &ok591);
                    if (!ok591) return;
                    u64 v_c156 = _prim_llen(db, v_c155);
                    if (v_c156 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c145 != v_c156) return;
                    bool ok592 = true;
                    u64 v_c157 = _prim_lref(db, v_c155, v_c146, &ok592);
                    if (!ok592) return;
                    if (v_c152 != v_c157) return;
                    bool ok593 = true;
                    u64 v_c158 = _prim_lref(db, v_c155, v_c147, &ok593);
                    if (!ok593) return;
                    if (v_c152 != v_c158) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c153});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c154}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask563* _cont = new ReadTask563(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask563(db,b), false);
  // (crule (pre (let __tconst0g0f1135 constd01925b37634a1a9d24159d8)) (scan mleaf __t8pgc425 k v) (body (exists _enum (1 0) 1 __tconst0g0f1135) (join-old mp_del (1 2 0) 2 (1 2 0) __t8pgc425 k __t69Uy426) (join _enum (1 0) 1 __tconst0g0f1135 __t3QLG424)) (head (emit mp_del_ans (0 1) __t69Uy426 __t3QLG424)) map.slog:80 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex594;  slog::Index** mp_delindex595;  slog::Index** _enumindex596;  slog::Index** mp_deldelta597;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("mp_del_ans");
      head_index[0] = readrel600->getIndex(ord599, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord601({1, 0});
      slog::Relation* readrel602 = db->getRelation("_enum");
      _enumindex594 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("mp_del");
      mp_delindex595 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({1, 2, 0});
      slog::Relation* readrel606 = db->getRelation("mp_del");
      mp_deldelta597 = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({1, 0});
      slog::Relation* readrel608 = db->getRelation("_enum");
      _enumindex596 = readrel608->getIndex(ord607, false);
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c159 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c160 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex594, std::array<u64,2>{v_c159, 0})) return;
        slog::join_probe_old<3,2>(mp_delindex595, mp_deldelta597, std::array<u64,3>{v_c160, v_c58, 0}, [&](const std::array<u64,3>& m609) {
          u64 v_c161 = m609[2];
          slog::join_probe<2,1>(_enumindex596, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m610) {
            u64 v_c162 = m610[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c161, v_c162}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:80", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask598* _cont = new ReadTask598(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x2 __t8CpS128 __t0Ayb132 dup4t6F1978 dup2J5X1979 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join-old $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join-old $sup5638x25x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join-old mp_msk_ans (0 1) 1 (0 1) __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask629 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x1index611;  slog::Index** $sup5638x25x0x0x0index612;  slog::Index** mp_joinindex613;  slog::Index** mp_hsb_ansindex614;  slog::Index** mp_hsb_ansindex615;  slog::Index** mp_hsb_ansindex616;  slog::Index** mp_mskindex617;  slog::Index** mp_msk_ansindex618;  slog::Index** mp_hsbindex619;  slog::Index** $sup5638x25x0x0x1delta620;  slog::Index** $sup5638x25x0x0x0delta621;  slog::Index** mp_joindelta622;  slog::Index** mp_hsb_ansdelta623;  slog::Index** mp_hsb_ansdelta624;  slog::Index** mp_hsb_ansdelta625;  slog::Index** mp_mskdelta626;  slog::Index** mp_msk_ansdelta627;  slog::Index** mp_hsbdelta628;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord630({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel631 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index611 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel633 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta620 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({1, 0, 2, 3, 4});
      slog::Relation* readrel635 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index612 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 0, 2, 3, 4});
      slog::Relation* readrel637 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0delta621 = readrel637->getIndex(ord636, true);
      std::vector<u16> ord638({1, 2, 3, 4, 0});
      slog::Relation* readrel639 = db->getRelation("mp_join");
      mp_joinindex613 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 3, 4, 0});
      slog::Relation* readrel641 = db->getRelation("mp_join");
      mp_joindelta622 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex614 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta623 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex615 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta624 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex616 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta625 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("mp_msk");
      mp_mskindex617 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("mp_msk");
      mp_mskdelta626 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex618 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta627 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("mp_hsb");
      mp_hsbindex619 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("mp_hsb");
      mp_hsbdelta628 = readrel665->getIndex(ord664, true);
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c164 = _t[0];
        u64 v_c165 = _t[1];
        u64 v_c166 = _t[2];
        u64 v_c167 = _t[3];
        u64 v_c18 = _t[4];
        u64 v_c88 = _t[5];
        u64 v_c89 = _t[6];
        u64 v_c92 = _t[7];
        u64 v_c93 = _t[8];
        u64 v_c94 = _t[9];
        u64 v_c95 = _t[10];
        if (v_c165 != v_c167) return;
        if (v_c165 != v_c166) return;
        slog::join_probe_old<7,7>($sup5638x25x0x0x1index611, $sup5638x25x0x0x1delta620, std::array<u64,7>{v_c164, v_c92, v_c93, v_c94, v_c95, v_c165, v_c18}, [&](const std::array<u64,7>& m666) {
          slog::join_probe_old<5,5>($sup5638x25x0x0x0index612, $sup5638x25x0x0x0delta621, std::array<u64,5>{v_c92, v_c164, v_c93, v_c94, v_c95}, [&](const std::array<u64,5>& m667) {
            slog::join_probe_old<5,5>(mp_joinindex613, mp_joindelta622, std::array<u64,5>{v_c92, v_c94, v_c93, v_c95, v_c164}, [&](const std::array<u64,5>& m668) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex614, mp_hsb_ansdelta623, std::array<u64,2>{v_c165, v_c89}, [&](const std::array<u64,2>& m669) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex615, mp_hsb_ansdelta624, std::array<u64,2>{v_c165, v_c88}, [&](const std::array<u64,2>& m670) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex616, mp_hsb_ansdelta625, std::array<u64,2>{v_c165, v_c18}, [&](const std::array<u64,2>& m671) {
                    slog::join_probe_old<3,2>(mp_mskindex617, mp_mskdelta626, std::array<u64,3>{v_c92, v_c88, 0}, [&](const std::array<u64,3>& m672) {
                      u64 v_c168 = m672[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex618, mp_msk_ansdelta627, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m673) {
                        u64 v_c169 = m673[1];
                        u64 v_c170 = _prim_bxor(db, v_c92, v_c93);
                        if (v_c170 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex619, mp_hsbdelta628, std::array<u64,2>{v_c165, v_c170}, [&](const std::array<u64,2>& m674) {
                          u64 v_c171 = _prim_band(db, v_c92, v_c18);
                          if (v_c171 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c172 = _prim_lt(db, v_c171, v_c163);
                          if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c172) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c164, v_c169, v_c89, v_c94, v_c95});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c169, v_c89, v_c94, v_c95}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre) (scan eval __t7kdB647 __t71xd646 rho t) (body (exists eval (2 3 0 1) 2 rho t) (join $sup70016x87x0x0x0 (4 5 0 1 2 3) 3 rho t __t7kdB647 e1 e2 e3) (join if (1 3 2 0) 4 e1 e3 e2 __t71xd646) (exists select_branch (2 3 1 0) 2 e2 e3) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t2MYH648) (exists eval_ans (0 1) 1 __t2MYH648) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (exists select_branch_ans (0 1) 1 __t1Vli649) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask691 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex676;  slog::Index** $sup70016x87x0x0x0index677;  slog::Index** ifindex678;  slog::Index** select_branchindex679;  slog::Index** evalindex680;  slog::Index** eval_ansindex681;  slog::Index** select_branchindex682;  slog::Index** eval_ansindex683;  slog::Index** select_branch_ansindex684;  slog::Index** evalindex685;  slog::Index** select_branch_ansindex686;  slog::Index** eval_ansindex687;  slog::Index** evaldelta688;  slog::Index** select_branchdelta689;  slog::Index** evaldelta690;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord692({0, 1});
      slog::Relation* readrel693 = db->getRelation("eval_ans");
      head_index[0] = readrel693->getIndex(ord692, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord694({2, 3, 0, 1});
      slog::Relation* readrel695 = db->getRelation("eval");
      evalindex676 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel697 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index677 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 3, 2, 0});
      slog::Relation* readrel699 = db->getRelation("if");
      ifindex678 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({2, 3, 1, 0});
      slog::Relation* readrel701 = db->getRelation("select_branch");
      select_branchindex679 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 3, 0});
      slog::Relation* readrel703 = db->getRelation("eval");
      evalindex680 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 3, 0});
      slog::Relation* readrel705 = db->getRelation("eval");
      evaldelta688 = readrel705->getIndex(ord704, true);
      std::vector<u16> ord706({0, 1});
      slog::Relation* readrel707 = db->getRelation("eval_ans");
      eval_ansindex681 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({2, 3, 1, 0});
      slog::Relation* readrel709 = db->getRelation("select_branch");
      select_branchindex682 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({2, 3, 1, 0});
      slog::Relation* readrel711 = db->getRelation("select_branch");
      select_branchdelta689 = readrel711->getIndex(ord710, true);
      std::vector<u16> ord712({0, 1});
      slog::Relation* readrel713 = db->getRelation("eval_ans");
      eval_ansindex683 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({0, 1});
      slog::Relation* readrel715 = db->getRelation("select_branch_ans");
      select_branch_ansindex684 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({2, 3, 0, 1});
      slog::Relation* readrel717 = db->getRelation("eval");
      evalindex685 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({2, 3, 0, 1});
      slog::Relation* readrel719 = db->getRelation("eval");
      evaldelta690 = readrel719->getIndex(ord718, true);
      std::vector<u16> ord720({0, 1});
      slog::Relation* readrel721 = db->getRelation("select_branch_ans");
      select_branch_ansindex686 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({0, 1});
      slog::Relation* readrel723 = db->getRelation("eval_ans");
      eval_ansindex687 = readrel723->getIndex(ord722, false);
  
    }
    ReadTask691(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex676, std::array<u64,4>{v_c13, v_c14, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x87x0x0x0index677, std::array<u64,6>{v_c13, v_c14, v_c173, 0, 0, 0}, [&](const std::array<u64,6>& m724) {
          u64 v_c175 = m724[3]; u64 v_c176 = m724[4]; u64 v_c177 = m724[5];
          slog::join_probe<4,4>(ifindex678, std::array<u64,4>{v_c175, v_c177, v_c176, v_c174}, [&](const std::array<u64,4>& m725) {
            if (!slog::exists_probe<4,2>(select_branchindex679, std::array<u64,4>{v_c176, v_c177, 0, 0})) return;
            slog::join_probe_old<4,3>(evalindex680, evaldelta688, std::array<u64,4>{v_c175, v_c13, v_c14, 0}, [&](const std::array<u64,4>& m726) {
              u64 v_c178 = m726[3];
              if (!slog::exists_probe<2,1>(eval_ansindex681, std::array<u64,2>{v_c178, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex682, select_branchdelta689, std::array<u64,4>{v_c176, v_c177, 0, 0}, [&](const std::array<u64,4>& m727) {
                u64 v_c18 = m727[2]; u64 v_c179 = m727[3];
                slog::join_probe<2,2>(eval_ansindex683, std::array<u64,2>{v_c178, v_c18}, [&](const std::array<u64,2>& m728) {
                  if (!slog::exists_probe<2,1>(select_branch_ansindex684, std::array<u64,2>{v_c179, 0})) return;
                  slog::join_probe_old<4,2>(evalindex685, evaldelta690, std::array<u64,4>{v_c13, v_c14, 0, 0}, [&](const std::array<u64,4>& m729) {
                    u64 v_c180 = m729[2]; u64 v_c88 = m729[3];
                    slog::join_probe<2,2>(select_branch_ansindex686, std::array<u64,2>{v_c179, v_c88}, [&](const std::array<u64,2>& m730) {
                      slog::join_probe<2,1>(eval_ansindex687, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m731) {
                        u64 v_c169 = m731[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c173, v_c169}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask691* _cont = new ReadTask691(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask691(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mp_put __t630X244 l k v) (body (exists $sup5638x40x0x0x1 (2 3 7 0 1 4 5 6) 3 k l v) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put_ans (0 1) 1 __t630X244) (join $sup5638x40x0x0x0 (1 2 6 0 3 4 5) 3 k l v __t8K90240 m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t8K90240 k v __t0CZp243) (exists mp_msk (1 2 0) 3 k m __t0CZp243) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join mbranch (1 2 3 4 0) 4 p m l r __t3kyC239) (join mp_put (0 2 1 3) 4 __t8K90240 k __t3kyC239 v) (join mp_msk (1 2 0) 3 k m __t0CZp243) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask750 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index732;  slog::Index** mbranchindex733;  slog::Index** mp_putindex734;  slog::Index** mp_mskindex735;  slog::Index** mp_put_ansindex736;  slog::Index** $sup5638x40x0x0x0index737;  slog::Index** mbranchindex738;  slog::Index** mp_putindex739;  slog::Index** mp_mskindex740;  slog::Index** mp_msk_ansindex741;  slog::Index** $sup5638x40x0x0x1index742;  slog::Index** mp_mskindex743;  slog::Index** mp_msk_ansindex744;  slog::Index** mbranchindex745;  slog::Index** mp_putindex746;  slog::Index** mp_mskindex747;  slog::Index** mp_msk_ansindex748;  slog::Index** mp_put_ansindex749;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord751({2, 3, 7, 0, 1, 4, 5, 6});
      slog::Relation* readrel752 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index732 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({3, 0, 1, 2, 4});
      slog::Relation* readrel754 = db->getRelation("mbranch");
      mbranchindex733 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({2, 3, 0, 1});
      slog::Relation* readrel756 = db->getRelation("mp_put");
      mp_putindex734 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 2, 0});
      slog::Relation* readrel758 = db->getRelation("mp_msk");
      mp_mskindex735 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({0, 1});
      slog::Relation* readrel760 = db->getRelation("mp_put_ans");
      mp_put_ansindex736 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel762 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index737 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 3, 4, 0});
      slog::Relation* readrel764 = db->getRelation("mbranch");
      mbranchindex738 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({3, 0, 2, 1});
      slog::Relation* readrel766 = db->getRelation("mp_put");
      mp_putindex739 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 2, 0});
      slog::Relation* readrel768 = db->getRelation("mp_msk");
      mp_mskindex740 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0});
      slog::Relation* readrel770 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex741 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel772 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index742 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("mp_msk");
      mp_mskindex743 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({0, 1});
      slog::Relation* readrel776 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex744 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 3, 4, 0});
      slog::Relation* readrel778 = db->getRelation("mbranch");
      mbranchindex745 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({0, 2, 1, 3});
      slog::Relation* readrel780 = db->getRelation("mp_put");
      mp_putindex746 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("mp_msk");
      mp_mskindex747 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({0, 1});
      slog::Relation* readrel784 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex748 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("mp_put_ans");
      mp_put_ansindex749 = readrel786->getIndex(ord785, false);
  
    }
    ReadTask750(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c182 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c58 = _t[2];
        u64 v_c19 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index732, std::array<u64,8>{v_c58, v_c29, v_c19, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex733, std::array<u64,5>{v_c29, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex734, std::array<u64,4>{v_c58, v_c19, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex735, std::array<u64,3>{v_c58, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex736, std::array<u64,2>{v_c182, 0})) return;
        slog::join_probe<7,3>($sup5638x40x0x0x0index737, std::array<u64,7>{v_c58, v_c29, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,7>& m787) {
          u64 v_c183 = m787[3]; u64 v_c28 = m787[4]; u64 v_c27 = m787[5]; u64 v_c30 = m787[6];
          if (!slog::exists_probe<5,4>(mbranchindex738, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex739, std::array<u64,4>{v_c19, v_c183, v_c58, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex740, std::array<u64,3>{v_c58, v_c28, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex741, std::array<u64,2>{v_c27, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index742, std::array<u64,8>{v_c29, v_c28, v_c27, v_c30, v_c183, v_c58, v_c19, 0}, [&](const std::array<u64,8>& m788) {
            u64 v_c184 = m788[7];
            if (!slog::exists_probe<3,3>(mp_mskindex743, std::array<u64,3>{v_c58, v_c28, v_c184})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex744, std::array<u64,2>{v_c184, v_c27})) return;
            slog::join_probe<5,4>(mbranchindex745, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m789) {
              u64 v_c185 = m789[4];
              slog::join_probe<4,4>(mp_putindex746, std::array<u64,4>{v_c183, v_c58, v_c185, v_c19}, [&](const std::array<u64,4>& m790) {
                slog::join_probe<3,3>(mp_mskindex747, std::array<u64,3>{v_c58, v_c28, v_c184}, [&](const std::array<u64,3>& m791) {
                  slog::join_probe<2,2>(mp_msk_ansindex748, std::array<u64,2>{v_c184, v_c27}, [&](const std::array<u64,2>& m792) {
                    slog::join_probe<2,1>(mp_put_ansindex749, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m793) {
                      u64 v_c18 = m793[1];
                      u64 v_c186 = _prim_band(db, v_c58, v_c28);
                      if (v_c186 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c187 = _prim_lt(db, v_c186, v_c181);
                      if (v_c187 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c187) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c183, v_c18, v_c28, v_c27, v_c30});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c18, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask750* _cont = new ReadTask750(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask750(db,b), false);
  // (crule (pre (let __trid8LqO1205 constfee494ff4827aeb0635bb714) (let __trel2H7m1206 const20347926ddb307a8e2bdb71b) (let __tcol2B611207 constd4735e3a265e16eee03f5971)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t0gIW440) (join-old mp_msk_ans (0 1) 2 (0 1) __t0gIW440 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t33MJ441) (join-old mp_del_ans (0 1) 1 (0 1) __t33MJ441 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8LqO1205 __trel2H7m1206 __tcol2B611207 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __0kM11204 p m l __v0)) map.slog:85 #f)
  class ReadTask808 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex795;  slog::Index** mp_delindex796;  slog::Index** mp_mskindex797;  slog::Index** mp_msk_ansindex798;  slog::Index** mp_delindex799;  slog::Index** mp_del_ansindex800;  slog::Index** mp_mskdelta801;  slog::Index** mp_msk_ansdelta802;  slog::Index** mp_deldelta803;  slog::Index** mp_del_ansdelta804;
    u32 sid806;  u32 sid805;  u32 sid807;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord809({1, 0});
      slog::Relation* readrel810 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex795 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 0});
      slog::Relation* readrel812 = db->getRelation("mp_del");
      mp_delindex796 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 2, 0});
      slog::Relation* readrel814 = db->getRelation("mp_msk");
      mp_mskindex797 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("mp_msk");
      mp_mskdelta801 = readrel816->getIndex(ord815, true);
      std::vector<u16> ord817({0, 1});
      slog::Relation* readrel818 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex798 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({0, 1});
      slog::Relation* readrel820 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta802 = readrel820->getIndex(ord819, true);
      std::vector<u16> ord821({1, 2, 0});
      slog::Relation* readrel822 = db->getRelation("mp_del");
      mp_delindex799 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({1, 2, 0});
      slog::Relation* readrel824 = db->getRelation("mp_del");
      mp_deldelta803 = readrel824->getIndex(ord823, true);
      std::vector<u16> ord825({0, 1});
      slog::Relation* readrel826 = db->getRelation("mp_del_ans");
      mp_del_ansindex800 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({0, 1});
      slog::Relation* readrel828 = db->getRelation("mp_del_ans");
      mp_del_ansdelta804 = readrel828->getIndex(ord827, true);
      sid806 = db->getRelation("_enum")->getStructId();
      sid805 = db->getRelation("mbranch")->getStructId();
      sid807 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask808(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c188 = v_constfee494ff4827aeb0635bb714;
      u64 v_c189 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c190 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c30 = _t[5];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex795, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex796, std::array<u64,3>{v_c30, v_c58, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex797, mp_mskdelta801, std::array<u64,3>{v_c58, v_c28, 0}, [&](const std::array<u64,3>& m829) {
          u64 v_c191 = m829[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex798, mp_msk_ansdelta802, std::array<u64,2>{v_c191, v_c27}, [&](const std::array<u64,2>& m830) {
            slog::join_probe_old<3,2>(mp_delindex799, mp_deldelta803, std::array<u64,3>{v_c30, v_c58, 0}, [&](const std::array<u64,3>& m831) {
              u64 v_c192 = m831[2];
              slog::join_probe_old<2,1>(mp_del_ansindex800, mp_del_ansdelta804, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m832) {
                u64 v_c18 = m832[1];
                ++_fires;
                if (!((is_struct(v_c29) && (decode_struct_id(v_c29) == sid805 || decode_struct_id(v_c29) == sid806 || decode_struct_id(v_c29) == sid807))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c188, v_c189, v_c190, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c29, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask808* _cont = new ReadTask808(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask808(db,b), false);
  // (crule (pre (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp9OrB1986 __t39ek93 __t66zQ63 __t6Peh56 __t8z2o72 __t9rwO81) (body (join let (1 2 3 0) 3 __tconst7dEi64 __t66zQ63 __t6Peh56 __t953c65)) (head (emit-temp temp3H1p1987 __t39ek93 __t8z2o72 __t953c65 __t9rwO81) (mkstruct let (1 2 3 0) __t5f4h74 __tconst6c7T73 __t8z2o72 __t953c65)) kcfa.slog:16 #f)
  class ReadTask834 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex833;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3H1p1987");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp9OrB1986");
      std::vector<u16> ord835({1, 2, 3, 0});
      slog::Relation* readrel836 = db->getRelation("let");
      letindex833 = readrel836->getIndex(ord835, false);
  
    }
    ReadTask834(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c193 = v_constef2d127de37b942baad06145;
      u64 v_c194 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c195 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c196 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c197 = _t[0];
        u64 v_c198 = _t[1];
        u64 v_c199 = _t[2];
        u64 v_c200 = _t[3];
        u64 v_c201 = _t[4];
        slog::join_probe<4,3>(letindex833, std::array<u64,4>{v_c193, v_c198, v_c199, 0}, [&](const std::array<u64,4>& m837) {
          u64 v_c202 = m837[3];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c197, v_c200, v_c202, v_c201});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c194, v_c200, v_c202}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp9OrB1986", _fires);
  
      if (!_done)
      {
        ReadTask834* _cont = new ReadTask834(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask834(db,b), false);
  // (crule (pre (let __tconst8wBL581 const5feceb66ffc86f38d952786c)) (scan mbranch __t0T68582 p m l r) (body (exists mp_has0 (1 2 0) 1 __t0T68582) (exists mp_msk (2 0 1) 1 m) (join $sup5638x59x0x0x0 (2 3 4 5 0 1) 4 l m p r __t8lWf583 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t8lWf583 k __t0T68582) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7zc5584) (join mp_msk_ans (0 1) 1 __t7zc5584 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t8lWf583 __tconst8wBL581)) map.slog:60 #f)
  class ReadTask846 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index838;  slog::Index** mp_mskindex839;  slog::Index** $sup5638x59x0x0x0index840;  slog::Index** mp_has0index841;  slog::Index** mp_mskindex842;  slog::Index** mp_msk_ansindex843;  slog::Index** mp_has0delta844;  slog::Index** mp_mskdelta845;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord847({0, 1});
      slog::Relation* readrel848 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel848->getIndex(ord847, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord849({1, 2, 0});
      slog::Relation* readrel850 = db->getRelation("mp_has0");
      mp_has0index838 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({2, 0, 1});
      slog::Relation* readrel852 = db->getRelation("mp_msk");
      mp_mskindex839 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel854 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index840 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({0, 2, 1});
      slog::Relation* readrel856 = db->getRelation("mp_has0");
      mp_has0index841 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({0, 2, 1});
      slog::Relation* readrel858 = db->getRelation("mp_has0");
      mp_has0delta844 = readrel858->getIndex(ord857, true);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("mp_msk");
      mp_mskindex842 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("mp_msk");
      mp_mskdelta845 = readrel862->getIndex(ord861, true);
      std::vector<u16> ord863({0, 1});
      slog::Relation* readrel864 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex843 = readrel864->getIndex(ord863, false);
  
    }
    ReadTask846(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index838, std::array<u64,3>{v_c204, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex839, std::array<u64,3>{v_c28, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x59x0x0x0index840, std::array<u64,6>{v_c29, v_c28, v_c27, v_c30, 0, 0}, [&](const std::array<u64,6>& m865) {
          u64 v_c205 = m865[4]; u64 v_c58 = m865[5];
          slog::join_probe_old<3,3>(mp_has0index841, mp_has0delta844, std::array<u64,3>{v_c205, v_c58, v_c204}, [&](const std::array<u64,3>& m866) {
            slog::join_probe_old<3,2>(mp_mskindex842, mp_mskdelta845, std::array<u64,3>{v_c58, v_c28, 0}, [&](const std::array<u64,3>& m867) {
              u64 v_c206 = m867[2];
              slog::join_probe<2,1>(mp_msk_ansindex843, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m868) {
                u64 v_c18 = m868[1];
                if (v_c27 == v_c18) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c205, v_c203}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask846* _cont = new ReadTask846(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask846(db,b), false);
  // (crule (pre) (scan mp_union __t2qeD366 __t9kHM367 __t6hR1368) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t9kHM367 p m l r) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6hR1368 q n u v) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t2qeD366 l n p r __t9kHM367 __t6hR1368 u v)) map.slog:102 #f)
  class ReadTask873 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex869;  slog::Index** mbranchindex870;  slog::Index** mbranchdelta871;  slog::Index** mbranchdelta872;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord874({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel875 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel875->getIndex(ord874, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord876({0, 1, 2, 3, 4});
      slog::Relation* readrel877 = db->getRelation("mbranch");
      mbranchindex869 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({0, 1, 2, 3, 4});
      slog::Relation* readrel879 = db->getRelation("mbranch");
      mbranchdelta871 = readrel879->getIndex(ord878, true);
      std::vector<u16> ord880({0, 1, 2, 3, 4});
      slog::Relation* readrel881 = db->getRelation("mbranch");
      mbranchindex870 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({0, 1, 2, 3, 4});
      slog::Relation* readrel883 = db->getRelation("mbranch");
      mbranchdelta872 = readrel883->getIndex(ord882, true);
  
    }
    ReadTask873(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c207 = _t[0];
        u64 v_c208 = _t[1];
        u64 v_c209 = _t[2];
        slog::join_probe_old<5,1>(mbranchindex869, mbranchdelta871, std::array<u64,5>{v_c208, 0, 0, 0, 0}, [&](const std::array<u64,5>& m884) {
          u64 v_c27 = m884[1]; u64 v_c28 = m884[2]; u64 v_c29 = m884[3]; u64 v_c30 = m884[4];
          slog::join_probe_old<5,1>(mbranchindex870, mbranchdelta872, std::array<u64,5>{v_c209, 0, 0, 0, 0}, [&](const std::array<u64,5>& m885) {
            u64 v_c22 = m885[1]; u64 v_c23 = m885[2]; u64 v_c24 = m885[3]; u64 v_c19 = m885[4];
            u64 v_c210 = _prim_lt(db, v_c23, v_c28);
            if (v_c210 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c210) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c28, v_c22, v_c207, v_c29, v_c23, v_c27, v_c30, v_c208, v_c209, v_c24, v_c19}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask873* _cont = new ReadTask873(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask873(db,b), false);
  // (crule (pre) (scan let __t3kGW443 x er eb) (body (exists eval (1 2 3 0) 1 er) (join eval (1 2 3 0) 1 __t3kGW443 rho t __4PdZ1446) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho t __t6VzV444) (join eval_ans (0 1) 1 __t6VzV444 vr)) (head (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:94 #f)
  class ReadTask892 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex887;  slog::Index** evalindex888;  slog::Index** evalindex889;  slog::Index** eval_ansindex890;  slog::Index** evaldelta891;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord893({0, 1, 2});
      slog::Relation* readrel894 = db->getRelation("store");
      head_index[0] = readrel894->getIndex(ord893, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord895({0, 1, 2});
      slog::Relation* readrel896 = db->getRelation("binding_event");
      head_index[1] = readrel896->getIndex(ord895, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord897({1, 2, 3, 0});
      slog::Relation* readrel898 = db->getRelation("eval");
      evalindex887 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 2, 3, 0});
      slog::Relation* readrel900 = db->getRelation("eval");
      evalindex888 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 2, 3, 0});
      slog::Relation* readrel902 = db->getRelation("eval");
      evalindex889 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 3, 0});
      slog::Relation* readrel904 = db->getRelation("eval");
      evaldelta891 = readrel904->getIndex(ord903, true);
      std::vector<u16> ord905({0, 1});
      slog::Relation* readrel906 = db->getRelation("eval_ans");
      eval_ansindex890 = readrel906->getIndex(ord905, false);
  
    }
    ReadTask892(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c211 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c5 = _t[3];
        if (!slog::exists_probe<4,1>(evalindex887, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        slog::join_probe<4,1>(evalindex888, std::array<u64,4>{v_c211, 0, 0, 0}, [&](const std::array<u64,4>& m907) {
          u64 v_c13 = m907[1]; u64 v_c14 = m907[2]; u64 v_c212 = m907[3];
          slog::join_probe_old<4,3>(evalindex889, evaldelta891, std::array<u64,4>{v_c36, v_c13, v_c14, 0}, [&](const std::array<u64,4>& m908) {
            u64 v_c213 = m908[3];
            slog::join_probe<2,1>(eval_ansindex890, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m909) {
              u64 v_c42 = m909[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c38, v_c14, v_c42}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c38, v_c14, v_c14}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask892* _cont = new ReadTask892(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask892(db,b), false);
  // (crule (pre) (scan mbranch __t1p4P452 p m u v) (body (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_union (2 0 1) 1 __t1p4P452) (exists mp_union (2 0 1) 1 u) (exists mp_union (2 0 1) 1 v) (join $sup5638x93x0x0x0 (2 3 5 6 0 1 4) 4 m p u v __t70BJ454 l r) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4xjy453) (join-old mp_union (0 1 2) 3 (0 1 2) __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t1OdF455) (exists mp_union_ans (0 1) 1 __t1OdF455) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (exists mp_union_ans (0 1) 1 __t4atM456) (join mp_union_ans (0 1) 1 __t1OdF455 __v0) (join mp_union_ans (0 1) 1 __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask930 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex910;  slog::Index** mp_unionindex911;  slog::Index** mp_unionindex912;  slog::Index** mp_unionindex913;  slog::Index** $sup5638x93x0x0x0index914;  slog::Index** mp_unionindex915;  slog::Index** mp_unionindex916;  slog::Index** mp_unionindex917;  slog::Index** mbranchindex918;  slog::Index** mp_unionindex919;  slog::Index** mp_unionindex920;  slog::Index** mp_union_ansindex921;  slog::Index** mp_unionindex922;  slog::Index** mp_union_ansindex923;  slog::Index** mp_union_ansindex924;  slog::Index** mp_union_ansindex925;  slog::Index** mbranchdelta926;  slog::Index** mp_uniondelta927;  slog::Index** mp_uniondelta928;  slog::Index** mp_uniondelta929;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord931({1, 2, 3, 4, 0});
      slog::Relation* readrel932 = db->getRelation("mbranch");
      mbranchindex910 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({2, 0, 1});
      slog::Relation* readrel934 = db->getRelation("mp_union");
      mp_unionindex911 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({2, 0, 1});
      slog::Relation* readrel936 = db->getRelation("mp_union");
      mp_unionindex912 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({2, 0, 1});
      slog::Relation* readrel938 = db->getRelation("mp_union");
      mp_unionindex913 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel940 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index914 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({2, 0, 1});
      slog::Relation* readrel942 = db->getRelation("mp_union");
      mp_unionindex915 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 0});
      slog::Relation* readrel944 = db->getRelation("mp_union");
      mp_unionindex916 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("mp_union");
      mp_unionindex917 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 3, 4, 0});
      slog::Relation* readrel948 = db->getRelation("mbranch");
      mbranchindex918 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 3, 4, 0});
      slog::Relation* readrel950 = db->getRelation("mbranch");
      mbranchdelta926 = readrel950->getIndex(ord949, true);
      std::vector<u16> ord951({0, 1, 2});
      slog::Relation* readrel952 = db->getRelation("mp_union");
      mp_unionindex919 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({0, 1, 2});
      slog::Relation* readrel954 = db->getRelation("mp_union");
      mp_uniondelta927 = readrel954->getIndex(ord953, true);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("mp_union");
      mp_unionindex920 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("mp_union");
      mp_uniondelta928 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({0, 1});
      slog::Relation* readrel960 = db->getRelation("mp_union_ans");
      mp_union_ansindex921 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("mp_union");
      mp_unionindex922 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 2, 0});
      slog::Relation* readrel964 = db->getRelation("mp_union");
      mp_uniondelta929 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("mp_union_ans");
      mp_union_ansindex923 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("mp_union_ans");
      mp_union_ansindex924 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("mp_union_ans");
      mp_union_ansindex925 = readrel970->getIndex(ord969, false);
  
    }
    ReadTask930(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c214 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex910, std::array<u64,5>{v_c27, v_c28, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex911, std::array<u64,3>{v_c214, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex912, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex913, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<7,4>($sup5638x93x0x0x0index914, std::array<u64,7>{v_c28, v_c27, v_c24, v_c19, 0, 0, 0}, [&](const std::array<u64,7>& m971) {
          u64 v_c215 = m971[4]; u64 v_c29 = m971[5]; u64 v_c30 = m971[6];
          if (!slog::exists_probe<3,2>(mp_unionindex915, std::array<u64,3>{v_c214, v_c215, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex916, std::array<u64,3>{v_c29, v_c24, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex917, std::array<u64,3>{v_c30, v_c19, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex918, mbranchdelta926, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m972) {
            u64 v_c216 = m972[4];
            slog::join_probe_old<3,3>(mp_unionindex919, mp_uniondelta927, std::array<u64,3>{v_c215, v_c216, v_c214}, [&](const std::array<u64,3>& m973) {
              slog::join_probe_old<3,2>(mp_unionindex920, mp_uniondelta928, std::array<u64,3>{v_c29, v_c24, 0}, [&](const std::array<u64,3>& m974) {
                u64 v_c217 = m974[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex921, std::array<u64,2>{v_c217, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex922, mp_uniondelta929, std::array<u64,3>{v_c30, v_c19, 0}, [&](const std::array<u64,3>& m975) {
                  u64 v_c218 = m975[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex923, std::array<u64,2>{v_c218, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex924, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m976) {
                    u64 v_c18 = m976[1];
                    slog::join_probe<2,1>(mp_union_ansindex925, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m977) {
                      u64 v_c88 = m977[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c215, v_c18, v_c88, v_c28, v_c27});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c18, v_c88}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __trid6dG11155 const3b05f339a47cf251e643e4dd) (let __trel4xVS1156 const1064263932db82f2cf6d4ac2) (let __tcol8JxE1157 const5feceb66ffc86f38d952786c) (let __trel7Sxc1158 const1064263932db82f2cf6d4ac2) (let __tcol2Avq1159 const6b86b273ff34fce19d6b804e)) (scan $sup70016x47x0x0x0 _00024seq0 __d0 rho t x xs) (body) (head (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6dG11155 __trel4xVS1156 __tcol8JxE1157 (1 2 3 4 0)) (tycheck x (accept int) __trid6dG11155 __trel7Sxc1158 __tcol2Avq1159 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __7bJ21154 rho x t)) interp.slog:48 #f)
  class ReadTask981 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid979;  u32 sid978;  u32 sid980;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup70016x47x0x0x0");
      sid979 = db->getRelation("_enum")->getStructId();
      sid978 = db->getRelation("mbranch")->getStructId();
      sid980 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask981(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c219 = v_const3b05f339a47cf251e643e4dd;
      u64 v_c220 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c221 = v_const5feceb66ffc86f38d952786c;
      u64 v_c222 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c223 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c224 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c38 = _t[4];
        u64 v_c4 = _t[5];
        ++_fires;
        if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid978 || decode_struct_id(v_c13) == sid979 || decode_struct_id(v_c13) == sid980))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c219, v_c220, v_c221, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c38)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c219, v_c222, v_c223, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c13, v_c38, v_c14}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:$sup70016x47x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t5aM3462 p) (body (exists $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) 2 __t5aM3462 p) (exists $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t5aM3462 k m) (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_put (2 3 0 1) 1 k) (join-old $sup5638x42x0x0x1 (1 2 4 5 0 3 6 7) 4 (1 2 4 5 0 3 6 7) __t5aM3462 k m p __t6Bbs459 l r v) (join-old $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 (4 2 3 5 0 1 6) p l m r __t6Bbs459 k v) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_put (1 2 3 0) 3 r k v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t9ixF458) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Bbs459 k __t9ixF458 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join-old mp_put_ans (0 1) 1 (0 1) __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask1004 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index982;  slog::Index** $sup5638x42x0x0x0index983;  slog::Index** mbranchindex984;  slog::Index** mp_mskindex985;  slog::Index** $sup5638x42x0x0x0index986;  slog::Index** mbranchindex987;  slog::Index** mp_putindex988;  slog::Index** $sup5638x42x0x0x1index989;  slog::Index** $sup5638x42x0x0x0index990;  slog::Index** mp_putindex991;  slog::Index** mp_putindex992;  slog::Index** mbranchindex993;  slog::Index** mp_putindex994;  slog::Index** mp_putindex995;  slog::Index** mp_put_ansindex996;  slog::Index** mp_mskdelta997;  slog::Index** $sup5638x42x0x0x1delta998;  slog::Index** $sup5638x42x0x0x0delta999;  slog::Index** mbranchdelta1000;  slog::Index** mp_putdelta1001;  slog::Index** mp_putdelta1002;  slog::Index** mp_put_ansdelta1003;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1005({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel1006 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index982 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1008 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index983 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 3, 4, 0});
      slog::Relation* readrel1010 = db->getRelation("mbranch");
      mbranchindex984 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({0, 1, 2});
      slog::Relation* readrel1012 = db->getRelation("mp_msk");
      mp_mskindex985 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({0, 1, 2});
      slog::Relation* readrel1014 = db->getRelation("mp_msk");
      mp_mskdelta997 = readrel1014->getIndex(ord1013, true);
      std::vector<u16> ord1015({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel1016 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index986 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 2, 3, 4, 0});
      slog::Relation* readrel1018 = db->getRelation("mbranch");
      mbranchindex987 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({2, 3, 0, 1});
      slog::Relation* readrel1020 = db->getRelation("mp_put");
      mp_putindex988 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel1022 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index989 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel1024 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta998 = readrel1024->getIndex(ord1023, true);
      std::vector<u16> ord1025({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1026 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index990 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1028 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0delta999 = readrel1028->getIndex(ord1027, true);
      std::vector<u16> ord1029({3, 0, 2, 1});
      slog::Relation* readrel1030 = db->getRelation("mp_put");
      mp_putindex991 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 3, 0});
      slog::Relation* readrel1032 = db->getRelation("mp_put");
      mp_putindex992 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 2, 3, 4, 0});
      slog::Relation* readrel1034 = db->getRelation("mbranch");
      mbranchindex993 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 3, 4, 0});
      slog::Relation* readrel1036 = db->getRelation("mbranch");
      mbranchdelta1000 = readrel1036->getIndex(ord1035, true);
      std::vector<u16> ord1037({0, 2, 1, 3});
      slog::Relation* readrel1038 = db->getRelation("mp_put");
      mp_putindex994 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 2, 1, 3});
      slog::Relation* readrel1040 = db->getRelation("mp_put");
      mp_putdelta1001 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({1, 2, 3, 0});
      slog::Relation* readrel1042 = db->getRelation("mp_put");
      mp_putindex995 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({1, 2, 3, 0});
      slog::Relation* readrel1044 = db->getRelation("mp_put");
      mp_putdelta1002 = readrel1044->getIndex(ord1043, true);
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("mp_put_ans");
      mp_put_ansindex996 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({0, 1});
      slog::Relation* readrel1048 = db->getRelation("mp_put_ans");
      mp_put_ansdelta1003 = readrel1048->getIndex(ord1047, true);
  
    }
    ReadTask1004(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        if (!slog::exists_probe<8,2>($sup5638x42x0x0x1index982, std::array<u64,8>{v_c226, v_c27, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x42x0x0x0index983, std::array<u64,7>{v_c27, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex984, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex985, mp_mskdelta997, std::array<u64,3>{v_c226, 0, 0}, [&](const std::array<u64,3>& m1049) {
          u64 v_c58 = m1049[1]; u64 v_c28 = m1049[2];
          if (!slog::exists_probe<7,3>($sup5638x42x0x0x0index986, std::array<u64,7>{v_c58, v_c28, v_c27, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex987, std::array<u64,5>{v_c27, v_c28, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex988, std::array<u64,4>{v_c58, 0, 0, 0})) return;
          slog::join_probe_old<8,4>($sup5638x42x0x0x1index989, $sup5638x42x0x0x1delta998, std::array<u64,8>{v_c226, v_c58, v_c28, v_c27, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1050) {
            u64 v_c227 = m1050[4]; u64 v_c29 = m1050[5]; u64 v_c30 = m1050[6]; u64 v_c19 = m1050[7];
            slog::join_probe_old<7,7>($sup5638x42x0x0x0index990, $sup5638x42x0x0x0delta999, std::array<u64,7>{v_c27, v_c29, v_c28, v_c30, v_c227, v_c58, v_c19}, [&](const std::array<u64,7>& m1051) {
              if (!slog::exists_probe<4,3>(mp_putindex991, std::array<u64,4>{v_c19, v_c227, v_c58, 0})) return;
              if (!slog::exists_probe<4,3>(mp_putindex992, std::array<u64,4>{v_c30, v_c58, v_c19, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex993, mbranchdelta1000, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m1052) {
                u64 v_c228 = m1052[4];
                slog::join_probe_old<4,4>(mp_putindex994, mp_putdelta1001, std::array<u64,4>{v_c227, v_c58, v_c228, v_c19}, [&](const std::array<u64,4>& m1053) {
                  slog::join_probe_old<4,3>(mp_putindex995, mp_putdelta1002, std::array<u64,4>{v_c30, v_c58, v_c19, 0}, [&](const std::array<u64,4>& m1054) {
                    u64 v_c229 = m1054[3];
                    slog::join_probe_old<2,1>(mp_put_ansindex996, mp_put_ansdelta1003, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1055) {
                      u64 v_c18 = m1055[1];
                      u64 v_c230 = _prim_band(db, v_c58, v_c28);
                      if (v_c230 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c231 = _prim_gt(db, v_c230, v_c225);
                      if (v_c231 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c231) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c227, v_c18, v_c29, v_c28, v_c27});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c29, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1004* _cont = new ReadTask1004(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1004(db,b), false);
  // (crule (pre) (scan $sup70016x95x0x0x0 __d0 eb er rho t x) (body (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t42s0769) (join-old mp_put_ans (0 1) 1 (0 1) __t42s0769 rho2)) (head (emit $sup70016x95x0x0x1 (1 5 0 2 3 4 6 7) __t42s0769 rho2 __d0 eb er rho t x)) interp.slog:96 #f)
  class ReadTask1061 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1057;  slog::Index** mp_put_ansindex1058;  slog::Index** mp_putdelta1059;  slog::Index** mp_put_ansdelta1060;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord1062({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel1063 = db->getRelation("$sup70016x95x0x0x1");
      head_index[0] = readrel1063->getIndex(ord1062, false);
      outer_rel = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord1064({1, 2, 3, 0});
      slog::Relation* readrel1065 = db->getRelation("mp_put");
      mp_putindex1057 = readrel1065->getIndex(ord1064, false);
      std::vector<u16> ord1066({1, 2, 3, 0});
      slog::Relation* readrel1067 = db->getRelation("mp_put");
      mp_putdelta1059 = readrel1067->getIndex(ord1066, true);
      std::vector<u16> ord1068({0, 1});
      slog::Relation* readrel1069 = db->getRelation("mp_put_ans");
      mp_put_ansindex1058 = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({0, 1});
      slog::Relation* readrel1071 = db->getRelation("mp_put_ans");
      mp_put_ansdelta1060 = readrel1071->getIndex(ord1070, true);
  
    }
    ReadTask1061(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c14 = _t[4];
        u64 v_c38 = _t[5];
        slog::join_probe_old<4,3>(mp_putindex1057, mp_putdelta1059, std::array<u64,4>{v_c13, v_c38, v_c14, 0}, [&](const std::array<u64,4>& m1072) {
          u64 v_c232 = m1072[3];
          slog::join_probe_old<2,1>(mp_put_ansindex1058, mp_put_ansdelta1060, std::array<u64,2>{v_c232, 0}, [&](const std::array<u64,2>& m1073) {
            u64 v_c37 = m1073[1];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c232, v_c37, v_c57, v_c5, v_c36, v_c13, v_c14, v_c38}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1061* _cont = new ReadTask1061(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1061(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp1ppH1902 __t1WhI754 __t2X4e744 __t5Neo735 __t5xOK723 __t8k6P758) (body (join ref (1 0) 1 __tconst6I9K760 __t9NO9722)) (head (emit-temp temp4eez1903 __t1WhI754 __t2X4e744 __t5Neo735 __t5xOK723 __t8k6P758) (mkstruct app (1 2 0) __t7vYe738 __t9NO9722 __t5Neo735)) kcfa.slog:70 #f)
  class ReadTask1075 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1074;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4eez1903");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp1ppH1902");
      std::vector<u16> ord1076({1, 0});
      slog::Relation* readrel1077 = db->getRelation("ref");
      refindex1074 = readrel1077->getIndex(ord1076, false);
  
    }
    ReadTask1075(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_constd59eced1ded07f84c145592f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c233 = _t[0];
        u64 v_c109 = _t[1];
        u64 v_c234 = _t[2];
        u64 v_c112 = _t[3];
        u64 v_c105 = _t[4];
        slog::join_probe<2,1>(refindex1074, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1078) {
          u64 v_c111 = m1078[1];
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c233, v_c109, v_c234, v_c112, v_c105});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c111, v_c234}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp1ppH1902", _fires);
  
      if (!_done)
      {
        ReadTask1075* _cont = new ReadTask1075(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1075(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t84wf697 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t84wf697 q m) (exists $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_join (3 4 1 0 2) 1 q) (join-old mbranch (2 0 1 3 4) 1 (2 0 1 3 4) m __t1ouF694 p l r) (neq p __v0) (exists mp_join (1 2 3 4 0) 3 p __t1ouF694 q) (exists mp_union (1 2 0) 1 __t1ouF694) (join-old $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 (1 2 4 6 7 5 0 3 8 9 10) l m p r __t1ouF694 q __t5awj693 n __t1a8C695 u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1a8C695) (exists mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t1ouF694 q __t1a8C695 __t8BsD696) (join-old mp_union (0 1 2) 3 (0 1 2) __t5awj693 __t1ouF694 __t1a8C695) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask1098 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex1079;  slog::Index** $sup5638x101x0x0x0index1080;  slog::Index** mbranchindex1081;  slog::Index** mp_joinindex1082;  slog::Index** mbranchindex1083;  slog::Index** mp_joinindex1084;  slog::Index** mp_unionindex1085;  slog::Index** $sup5638x101x0x0x0index1086;  slog::Index** mbranchindex1087;  slog::Index** mp_unionindex1088;  slog::Index** mp_joinindex1089;  slog::Index** mp_unionindex1090;  slog::Index** mp_join_ansindex1091;  slog::Index** mp_mskdelta1092;  slog::Index** mbranchdelta1093;  slog::Index** $sup5638x101x0x0x0delta1094;  slog::Index** mbranchdelta1095;  slog::Index** mp_joindelta1096;  slog::Index** mp_uniondelta1097;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1100->getIndex(ord1099, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1101({0, 1, 2});
      slog::Relation* readrel1102 = db->getRelation("mp_msk");
      mp_mskindex1079 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({0, 1, 2});
      slog::Relation* readrel1104 = db->getRelation("mp_msk");
      mp_mskdelta1092 = readrel1104->getIndex(ord1103, true);
      std::vector<u16> ord1105({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel1106 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1080 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 2, 3, 4, 0});
      slog::Relation* readrel1108 = db->getRelation("mbranch");
      mbranchindex1081 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({3, 4, 1, 0, 2});
      slog::Relation* readrel1110 = db->getRelation("mp_join");
      mp_joinindex1082 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 0, 1, 3, 4});
      slog::Relation* readrel1112 = db->getRelation("mbranch");
      mbranchindex1083 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({2, 0, 1, 3, 4});
      slog::Relation* readrel1114 = db->getRelation("mbranch");
      mbranchdelta1093 = readrel1114->getIndex(ord1113, true);
      std::vector<u16> ord1115({1, 2, 3, 4, 0});
      slog::Relation* readrel1116 = db->getRelation("mp_join");
      mp_joinindex1084 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 2, 0});
      slog::Relation* readrel1118 = db->getRelation("mp_union");
      mp_unionindex1085 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel1120 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1086 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel1122 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0delta1094 = readrel1122->getIndex(ord1121, true);
      std::vector<u16> ord1123({1, 2, 3, 4, 0});
      slog::Relation* readrel1124 = db->getRelation("mbranch");
      mbranchindex1087 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 3, 4, 0});
      slog::Relation* readrel1126 = db->getRelation("mbranch");
      mbranchdelta1095 = readrel1126->getIndex(ord1125, true);
      std::vector<u16> ord1127({0, 1, 2});
      slog::Relation* readrel1128 = db->getRelation("mp_union");
      mp_unionindex1088 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 3, 4, 0});
      slog::Relation* readrel1130 = db->getRelation("mp_join");
      mp_joinindex1089 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 2, 3, 4, 0});
      slog::Relation* readrel1132 = db->getRelation("mp_join");
      mp_joindelta1096 = readrel1132->getIndex(ord1131, true);
      std::vector<u16> ord1133({0, 1, 2});
      slog::Relation* readrel1134 = db->getRelation("mp_union");
      mp_unionindex1090 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({0, 1, 2});
      slog::Relation* readrel1136 = db->getRelation("mp_union");
      mp_uniondelta1097 = readrel1136->getIndex(ord1135, true);
      std::vector<u16> ord1137({0, 1});
      slog::Relation* readrel1138 = db->getRelation("mp_join_ans");
      mp_join_ansindex1091 = readrel1138->getIndex(ord1137, false);
  
    }
    ReadTask1098(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex1079, mp_mskdelta1092, std::array<u64,3>{v_c235, 0, 0}, [&](const std::array<u64,3>& m1139) {
          u64 v_c22 = m1139[1]; u64 v_c28 = m1139[2];
          if (!slog::exists_probe<11,2>($sup5638x101x0x0x0index1080, std::array<u64,11>{v_c28, v_c22, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1081, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex1082, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(mbranchindex1083, mbranchdelta1093, std::array<u64,5>{v_c28, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1140) {
            u64 v_c236 = m1140[1]; u64 v_c27 = m1140[2]; u64 v_c29 = m1140[3]; u64 v_c30 = m1140[4];
            if (v_c27 == v_c18) return;
            if (!slog::exists_probe<5,3>(mp_joinindex1084, std::array<u64,5>{v_c27, v_c236, v_c22, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex1085, std::array<u64,3>{v_c236, 0, 0})) return;
            slog::join_probe_old<11,6>($sup5638x101x0x0x0index1086, $sup5638x101x0x0x0delta1094, std::array<u64,11>{v_c29, v_c28, v_c27, v_c30, v_c236, v_c22, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1141) {
              u64 v_c237 = m1141[6]; u64 v_c23 = m1141[7]; u64 v_c238 = m1141[8]; u64 v_c24 = m1141[9]; u64 v_c19 = m1141[10];
              u64 v_c239 = _prim_lt(db, v_c23, v_c28);
              if (v_c239 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
              if (!v_c239) return;
              slog::join_probe_old<5,5>(mbranchindex1087, mbranchdelta1095, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, v_c238}, [&](const std::array<u64,5>& m1143) {
                if (!slog::exists_probe<3,3>(mp_unionindex1088, std::array<u64,3>{v_c237, v_c236, v_c238})) return;
                slog::join_probe_old<5,4>(mp_joinindex1089, mp_joindelta1096, std::array<u64,5>{v_c27, v_c236, v_c22, v_c238, 0}, [&](const std::array<u64,5>& m1144) {
                  u64 v_c240 = m1144[4];
                  slog::join_probe_old<3,3>(mp_unionindex1090, mp_uniondelta1097, std::array<u64,3>{v_c237, v_c236, v_c238}, [&](const std::array<u64,3>& m1145) {
                    slog::join_probe<2,1>(mp_join_ansindex1091, std::array<u64,2>{v_c240, 0}, [&](const std::array<u64,2>& m1146) {
                      u64 v_c241 = m1146[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c237, v_c241}, std::array<u16,2>{0, 1});
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
        ReadTask1098* _cont = new ReadTask1098(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1098(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mbranch __t62gM307 p m l r) (body (exists mp_del (1 2 0) 1 __t62gM307) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 1 l) (join $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 p m r l __t0iNt308 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t0iNt308 k __t62gM307) (exists mp_msk (1 2 0) 2 k m) (exists mp_del (1 2 0) 2 l k) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t8pI6311 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join mp_del_ans (0 1) 2 __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask1168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex1147;  slog::Index** mp_bldindex1148;  slog::Index** mp_mskindex1149;  slog::Index** mp_msk_ansindex1150;  slog::Index** mp_delindex1151;  slog::Index** $sup5638x82x0x0x0index1152;  slog::Index** mp_delindex1153;  slog::Index** mp_mskindex1154;  slog::Index** mp_delindex1155;  slog::Index** mp_bldindex1156;  slog::Index** mp_del_ansindex1157;  slog::Index** mp_bld_ansindex1158;  slog::Index** mp_mskindex1159;  slog::Index** mp_msk_ansindex1160;  slog::Index** mp_delindex1161;  slog::Index** mp_del_ansindex1162;  slog::Index** mp_bld_ansindex1163;  slog::Index** mp_deldelta1164;  slog::Index** mp_blddelta1165;  slog::Index** mp_mskdelta1166;  slog::Index** mp_deldelta1167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1169({0, 1});
      slog::Relation* readrel1170 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1170->getIndex(ord1169, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1171({1, 2, 0});
      slog::Relation* readrel1172 = db->getRelation("mp_del");
      mp_delindex1147 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({2, 1, 4, 0, 3});
      slog::Relation* readrel1174 = db->getRelation("mp_bld");
      mp_bldindex1148 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({2, 0, 1});
      slog::Relation* readrel1176 = db->getRelation("mp_msk");
      mp_mskindex1149 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({1, 0});
      slog::Relation* readrel1178 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1150 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({1, 2, 0});
      slog::Relation* readrel1180 = db->getRelation("mp_del");
      mp_delindex1151 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1182 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1152 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({0, 2, 1});
      slog::Relation* readrel1184 = db->getRelation("mp_del");
      mp_delindex1153 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({0, 2, 1});
      slog::Relation* readrel1186 = db->getRelation("mp_del");
      mp_deldelta1164 = readrel1186->getIndex(ord1185, true);
      std::vector<u16> ord1187({1, 2, 0});
      slog::Relation* readrel1188 = db->getRelation("mp_msk");
      mp_mskindex1154 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 2, 0});
      slog::Relation* readrel1190 = db->getRelation("mp_del");
      mp_delindex1155 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({2, 1, 4, 0, 3});
      slog::Relation* readrel1192 = db->getRelation("mp_bld");
      mp_bldindex1156 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({2, 1, 4, 0, 3});
      slog::Relation* readrel1194 = db->getRelation("mp_bld");
      mp_blddelta1165 = readrel1194->getIndex(ord1193, true);
      std::vector<u16> ord1195({1, 0});
      slog::Relation* readrel1196 = db->getRelation("mp_del_ans");
      mp_del_ansindex1157 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({0, 1});
      slog::Relation* readrel1198 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1158 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 2, 0});
      slog::Relation* readrel1200 = db->getRelation("mp_msk");
      mp_mskindex1159 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({1, 2, 0});
      slog::Relation* readrel1202 = db->getRelation("mp_msk");
      mp_mskdelta1166 = readrel1202->getIndex(ord1201, true);
      std::vector<u16> ord1203({0, 1});
      slog::Relation* readrel1204 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1160 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 2, 0});
      slog::Relation* readrel1206 = db->getRelation("mp_del");
      mp_delindex1161 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 2, 0});
      slog::Relation* readrel1208 = db->getRelation("mp_del");
      mp_deldelta1167 = readrel1208->getIndex(ord1207, true);
      std::vector<u16> ord1209({0, 1});
      slog::Relation* readrel1210 = db->getRelation("mp_del_ans");
      mp_del_ansindex1162 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({0, 1});
      slog::Relation* readrel1212 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1163 = readrel1212->getIndex(ord1211, false);
  
    }
    ReadTask1168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c243 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        if (!slog::exists_probe<3,1>(mp_delindex1147, std::array<u64,3>{v_c243, 0, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex1148, std::array<u64,5>{v_c28, v_c27, v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1149, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1150, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex1151, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x82x0x0x0index1152, std::array<u64,6>{v_c27, v_c28, v_c30, v_c29, 0, 0}, [&](const std::array<u64,6>& m1213) {
          u64 v_c244 = m1213[4]; u64 v_c58 = m1213[5];
          slog::join_probe_old<3,3>(mp_delindex1153, mp_deldelta1164, std::array<u64,3>{v_c244, v_c58, v_c243}, [&](const std::array<u64,3>& m1214) {
            if (!slog::exists_probe<3,2>(mp_mskindex1154, std::array<u64,3>{v_c58, v_c28, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex1155, std::array<u64,3>{v_c29, v_c58, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex1156, mp_blddelta1165, std::array<u64,5>{v_c28, v_c27, v_c30, 0, 0}, [&](const std::array<u64,5>& m1215) {
              u64 v_c245 = m1215[3]; u64 v_c18 = m1215[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex1157, std::array<u64,2>{v_c18, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex1158, std::array<u64,2>{v_c245, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1159, mp_mskdelta1166, std::array<u64,3>{v_c58, v_c28, 0}, [&](const std::array<u64,3>& m1216) {
                u64 v_c246 = m1216[2];
                slog::join_probe<2,2>(mp_msk_ansindex1160, std::array<u64,2>{v_c246, v_c27}, [&](const std::array<u64,2>& m1217) {
                  slog::join_probe_old<3,2>(mp_delindex1161, mp_deldelta1167, std::array<u64,3>{v_c29, v_c58, 0}, [&](const std::array<u64,3>& m1218) {
                    u64 v_c247 = m1218[2];
                    slog::join_probe<2,2>(mp_del_ansindex1162, std::array<u64,2>{v_c247, v_c18}, [&](const std::array<u64,2>& m1219) {
                      slog::join_probe<2,1>(mp_bld_ansindex1163, std::array<u64,2>{v_c245, 0}, [&](const std::array<u64,2>& m1220) {
                        u64 v_c241 = m1220[1];
                        u64 v_c248 = _prim_band(db, v_c58, v_c28);
                        if (v_c248 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c249 = _prim_lt(db, v_c248, v_c242);
                        if (v_c249 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c249) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c244, v_c241}, std::array<u16,2>{0, 1});
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
        ReadTask1168* _cont = new ReadTask1168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1168(db,b), false);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan $sup5638x42x0x0x0 __t6Bbs459 k l m p r v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t6Bbs459 k v __t5aM3462) (exists mp_msk (1 2 0) 3 k m __t5aM3462) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t9ixF458) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Bbs459 k __t9ixF458 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t5aM3462) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask1241 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1222;  slog::Index** mp_putindex1223;  slog::Index** mp_mskindex1224;  slog::Index** mp_putindex1225;  slog::Index** mp_msk_ansindex1226;  slog::Index** $sup5638x42x0x0x1index1227;  slog::Index** mp_mskindex1228;  slog::Index** mp_msk_ansindex1229;  slog::Index** mbranchindex1230;  slog::Index** mp_putindex1231;  slog::Index** mp_mskindex1232;  slog::Index** mp_putindex1233;  slog::Index** mp_msk_ansindex1234;  slog::Index** mp_put_ansindex1235;  slog::Index** $sup5638x42x0x0x1delta1236;  slog::Index** mbranchdelta1237;  slog::Index** mp_putdelta1238;  slog::Index** mp_mskdelta1239;  slog::Index** mp_putdelta1240;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord1242({1, 2, 3, 4, 0});
      slog::Relation* readrel1243 = db->getRelation("mbranch");
      mbranchindex1222 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({3, 0, 2, 1});
      slog::Relation* readrel1245 = db->getRelation("mp_put");
      mp_putindex1223 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({1, 2, 0});
      slog::Relation* readrel1247 = db->getRelation("mp_msk");
      mp_mskindex1224 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({1, 2, 3, 0});
      slog::Relation* readrel1249 = db->getRelation("mp_put");
      mp_putindex1225 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 0});
      slog::Relation* readrel1251 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1226 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1253 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1227 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1255 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta1236 = readrel1255->getIndex(ord1254, true);
      std::vector<u16> ord1256({1, 2, 0});
      slog::Relation* readrel1257 = db->getRelation("mp_msk");
      mp_mskindex1228 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({0, 1});
      slog::Relation* readrel1259 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1229 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({1, 2, 3, 4, 0});
      slog::Relation* readrel1261 = db->getRelation("mbranch");
      mbranchindex1230 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({1, 2, 3, 4, 0});
      slog::Relation* readrel1263 = db->getRelation("mbranch");
      mbranchdelta1237 = readrel1263->getIndex(ord1262, true);
      std::vector<u16> ord1264({0, 2, 1, 3});
      slog::Relation* readrel1265 = db->getRelation("mp_put");
      mp_putindex1231 = readrel1265->getIndex(ord1264, false);
      std::vector<u16> ord1266({0, 2, 1, 3});
      slog::Relation* readrel1267 = db->getRelation("mp_put");
      mp_putdelta1238 = readrel1267->getIndex(ord1266, true);
      std::vector<u16> ord1268({1, 2, 0});
      slog::Relation* readrel1269 = db->getRelation("mp_msk");
      mp_mskindex1232 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({1, 2, 0});
      slog::Relation* readrel1271 = db->getRelation("mp_msk");
      mp_mskdelta1239 = readrel1271->getIndex(ord1270, true);
      std::vector<u16> ord1272({1, 2, 3, 0});
      slog::Relation* readrel1273 = db->getRelation("mp_put");
      mp_putindex1233 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({1, 2, 3, 0});
      slog::Relation* readrel1275 = db->getRelation("mp_put");
      mp_putdelta1240 = readrel1275->getIndex(ord1274, true);
      std::vector<u16> ord1276({0, 1});
      slog::Relation* readrel1277 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1234 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({0, 1});
      slog::Relation* readrel1279 = db->getRelation("mp_put_ans");
      mp_put_ansindex1235 = readrel1279->getIndex(ord1278, false);
  
    }
    ReadTask1241(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c227 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c30 = _t[5];
        u64 v_c19 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex1222, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex1223, std::array<u64,4>{v_c19, v_c227, v_c58, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex1224, std::array<u64,3>{v_c58, v_c28, 0})) return;
        if (!slog::exists_probe<4,3>(mp_putindex1225, std::array<u64,4>{v_c30, v_c58, v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1226, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe_old<8,7>($sup5638x42x0x0x1index1227, $sup5638x42x0x0x1delta1236, std::array<u64,8>{v_c29, v_c28, v_c27, v_c30, v_c227, v_c58, v_c19, 0}, [&](const std::array<u64,8>& m1280) {
          u64 v_c226 = m1280[7];
          if (!slog::exists_probe<3,3>(mp_mskindex1228, std::array<u64,3>{v_c58, v_c28, v_c226})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex1229, std::array<u64,2>{v_c226, v_c27})) return;
          slog::join_probe_old<5,4>(mbranchindex1230, mbranchdelta1237, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m1281) {
            u64 v_c228 = m1281[4];
            slog::join_probe_old<4,4>(mp_putindex1231, mp_putdelta1238, std::array<u64,4>{v_c227, v_c58, v_c228, v_c19}, [&](const std::array<u64,4>& m1282) {
              slog::join_probe_old<3,3>(mp_mskindex1232, mp_mskdelta1239, std::array<u64,3>{v_c58, v_c28, v_c226}, [&](const std::array<u64,3>& m1283) {
                slog::join_probe_old<4,3>(mp_putindex1233, mp_putdelta1240, std::array<u64,4>{v_c30, v_c58, v_c19, 0}, [&](const std::array<u64,4>& m1284) {
                  u64 v_c229 = m1284[3];
                  slog::join_probe<2,2>(mp_msk_ansindex1234, std::array<u64,2>{v_c226, v_c27}, [&](const std::array<u64,2>& m1285) {
                    slog::join_probe<2,1>(mp_put_ansindex1235, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m1286) {
                      u64 v_c18 = m1286[1];
                      u64 v_c230 = _prim_band(db, v_c58, v_c28);
                      if (v_c230 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c250 = _prim_gt(db, v_c230, v_c225);
                      if (v_c250 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c250) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c227, v_c18, v_c29, v_c28, v_c27});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c29, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1241* _cont = new ReadTask1241(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1241(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t0Ayb132 __v0) (body (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t0Ayb132 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t0Ayb132 __v0) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v3) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t0Ayb132 __v0 __v3) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v1) (exists mp_msk (2 0 1) 1 __v1) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t0Ayb132 __v0 __v3 __v1 __t8CpS128 dup4t6F1978 dup2J5X1979 p0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join mp_msk_ans (0 1) 1 __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask1305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1288;  slog::Index** $sup5638x25x0x0x2index1289;  slog::Index** $sup5638x25x0x0x1index1290;  slog::Index** mp_hsb_ansindex1291;  slog::Index** $sup5638x25x0x0x2index1292;  slog::Index** mp_hsb_ansindex1293;  slog::Index** mp_mskindex1294;  slog::Index** $sup5638x25x0x0x2index1295;  slog::Index** $sup5638x25x0x0x1index1296;  slog::Index** $sup5638x25x0x0x0index1297;  slog::Index** mp_joinindex1298;  slog::Index** mp_mskindex1299;  slog::Index** mp_msk_ansindex1300;  slog::Index** mp_hsbindex1301;  slog::Index** mp_joindelta1302;  slog::Index** mp_mskdelta1303;  slog::Index** mp_hsbdelta1304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1306({0, 1});
      slog::Relation* readrel1307 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1288 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1309 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1289 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1311 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1290 = readrel1311->getIndex(ord1310, false);
      std::vector<u16> ord1312({0, 1});
      slog::Relation* readrel1313 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1291 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1315 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1292 = readrel1315->getIndex(ord1314, false);
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1293 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({2, 0, 1});
      slog::Relation* readrel1319 = db->getRelation("mp_msk");
      mp_mskindex1294 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1321 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1295 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1323 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1296 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 0, 2, 3, 4});
      slog::Relation* readrel1325 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index1297 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({1, 2, 3, 4, 0});
      slog::Relation* readrel1327 = db->getRelation("mp_join");
      mp_joinindex1298 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 2, 3, 4, 0});
      slog::Relation* readrel1329 = db->getRelation("mp_join");
      mp_joindelta1302 = readrel1329->getIndex(ord1328, true);
      std::vector<u16> ord1330({1, 2, 0});
      slog::Relation* readrel1331 = db->getRelation("mp_msk");
      mp_mskindex1299 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({1, 2, 0});
      slog::Relation* readrel1333 = db->getRelation("mp_msk");
      mp_mskdelta1303 = readrel1333->getIndex(ord1332, true);
      std::vector<u16> ord1334({0, 1});
      slog::Relation* readrel1335 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1300 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({0, 1});
      slog::Relation* readrel1337 = db->getRelation("mp_hsb");
      mp_hsbindex1301 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({0, 1});
      slog::Relation* readrel1339 = db->getRelation("mp_hsb");
      mp_hsbdelta1304 = readrel1339->getIndex(ord1338, true);
  
    }
    ReadTask1305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c165 = _t[0];
        u64 v_c18 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1288, std::array<u64,2>{v_c165, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index1289, std::array<u64,11>{v_c165, v_c18, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index1290, std::array<u64,7>{v_c165, v_c18, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex1291, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m1340) {
          u64 v_c89 = m1340[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index1292, std::array<u64,11>{v_c165, v_c18, v_c89, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex1293, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m1341) {
            u64 v_c88 = m1341[1];
            if (!slog::exists_probe<3,1>(mp_mskindex1294, std::array<u64,3>{v_c88, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index1295, std::array<u64,11>{v_c165, v_c18, v_c89, v_c88, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1342) {
              u64 v_c164 = m1342[4]; u64 v_c166 = m1342[5]; u64 v_c167 = m1342[6]; u64 v_c92 = m1342[7]; u64 v_c93 = m1342[8]; u64 v_c94 = m1342[9]; u64 v_c95 = m1342[10];
              if (v_c165 != v_c167) return;
              if (v_c165 != v_c166) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index1296, std::array<u64,7>{v_c164, v_c92, v_c93, v_c94, v_c95, v_c165, v_c18}, [&](const std::array<u64,7>& m1343) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index1297, std::array<u64,5>{v_c92, v_c164, v_c93, v_c94, v_c95}, [&](const std::array<u64,5>& m1344) {
                  slog::join_probe_old<5,5>(mp_joinindex1298, mp_joindelta1302, std::array<u64,5>{v_c92, v_c94, v_c93, v_c95, v_c164}, [&](const std::array<u64,5>& m1345) {
                    slog::join_probe_old<3,2>(mp_mskindex1299, mp_mskdelta1303, std::array<u64,3>{v_c92, v_c88, 0}, [&](const std::array<u64,3>& m1346) {
                      u64 v_c168 = m1346[2];
                      slog::join_probe<2,1>(mp_msk_ansindex1300, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m1347) {
                        u64 v_c169 = m1347[1];
                        u64 v_c170 = _prim_bxor(db, v_c92, v_c93);
                        if (v_c170 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1301, mp_hsbdelta1304, std::array<u64,2>{v_c165, v_c170}, [&](const std::array<u64,2>& m1348) {
                          u64 v_c171 = _prim_band(db, v_c92, v_c18);
                          if (v_c171 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c251 = _prim_lt(db, v_c171, v_c163);
                          if (v_c251 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c251) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c164, v_c169, v_c89, v_c94, v_c95});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c169, v_c89, v_c94, v_c95}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1305* _cont = new ReadTask1305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1305(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mp_union __t2hbE115 __t5EdF114 __t8CES119) (body (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 1 __t2hbE115) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 1 __t2hbE115) (join-old mp_union (2 0 1) 1 (2 0 1) __t8CES119 __t7k4o120 l) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t2hbE115 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t2hbE115 l) (exists mp_union_ans (0 1) 1 __t7k4o120) (join mbranch (3 0 1 2 4) 2 l __t5EdF114 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t2hbE115) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 l m p r __t2hbE115 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t8CES119) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t2hbE115 n q u v __t27ag118) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask1371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index1350;  slog::Index** $sup5638x95x0x0x1index1351;  slog::Index** mp_unionindex1352;  slog::Index** $sup5638x95x0x0x0index1353;  slog::Index** $sup5638x95x0x0x1index1354;  slog::Index** mp_union_ansindex1355;  slog::Index** mbranchindex1356;  slog::Index** $sup5638x95x0x0x1index1357;  slog::Index** mp_mskindex1358;  slog::Index** mp_msk_ansindex1359;  slog::Index** $sup5638x95x0x0x0index1360;  slog::Index** mbranchindex1361;  slog::Index** mp_mskindex1362;  slog::Index** $sup5638x95x0x0x1index1363;  slog::Index** mbranchindex1364;  slog::Index** mp_mskindex1365;  slog::Index** mp_msk_ansindex1366;  slog::Index** mp_union_ansindex1367;  slog::Index** mp_uniondelta1368;  slog::Index** mbranchdelta1369;  slog::Index** mp_mskdelta1370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1372({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1373 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1350 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel1375 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1351 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({2, 0, 1});
      slog::Relation* readrel1377 = db->getRelation("mp_union");
      mp_unionindex1352 = readrel1377->getIndex(ord1376, false);
      std::vector<u16> ord1378({2, 0, 1});
      slog::Relation* readrel1379 = db->getRelation("mp_union");
      mp_uniondelta1368 = readrel1379->getIndex(ord1378, true);
      std::vector<u16> ord1380({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1381 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1353 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel1383 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1354 = readrel1383->getIndex(ord1382, false);
      std::vector<u16> ord1384({0, 1});
      slog::Relation* readrel1385 = db->getRelation("mp_union_ans");
      mp_union_ansindex1355 = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({3, 0, 1, 2, 4});
      slog::Relation* readrel1387 = db->getRelation("mbranch");
      mbranchindex1356 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1389 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1357 = readrel1389->getIndex(ord1388, false);
      std::vector<u16> ord1390({2, 0, 1});
      slog::Relation* readrel1391 = db->getRelation("mp_msk");
      mp_mskindex1358 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({1, 0});
      slog::Relation* readrel1393 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1359 = readrel1393->getIndex(ord1392, false);
      std::vector<u16> ord1394({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1395 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1360 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({1, 2, 3, 4, 0});
      slog::Relation* readrel1397 = db->getRelation("mbranch");
      mbranchindex1361 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({1, 2, 0});
      slog::Relation* readrel1399 = db->getRelation("mp_msk");
      mp_mskindex1362 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1401 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1363 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({1, 2, 3, 4, 0});
      slog::Relation* readrel1403 = db->getRelation("mbranch");
      mbranchindex1364 = readrel1403->getIndex(ord1402, false);
      std::vector<u16> ord1404({1, 2, 3, 4, 0});
      slog::Relation* readrel1405 = db->getRelation("mbranch");
      mbranchdelta1369 = readrel1405->getIndex(ord1404, true);
      std::vector<u16> ord1406({1, 2, 0});
      slog::Relation* readrel1407 = db->getRelation("mp_msk");
      mp_mskindex1365 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({1, 2, 0});
      slog::Relation* readrel1409 = db->getRelation("mp_msk");
      mp_mskdelta1370 = readrel1409->getIndex(ord1408, true);
      std::vector<u16> ord1410({0, 1});
      slog::Relation* readrel1411 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1366 = readrel1411->getIndex(ord1410, false);
      std::vector<u16> ord1412({0, 1});
      slog::Relation* readrel1413 = db->getRelation("mp_union_ans");
      mp_union_ansindex1367 = readrel1413->getIndex(ord1412, false);
  
    }
    ReadTask1371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c252 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c253 = _t[0];
        u64 v_c254 = _t[1];
        u64 v_c255 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index1350, std::array<u64,9>{v_c253, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index1351, std::array<u64,10>{v_c253, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex1352, mp_uniondelta1368, std::array<u64,3>{v_c255, 0, 0}, [&](const std::array<u64,3>& m1414) {
          u64 v_c256 = m1414[1]; u64 v_c29 = m1414[2];
          if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index1353, std::array<u64,9>{v_c253, v_c29, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index1354, std::array<u64,10>{v_c253, v_c29, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex1355, std::array<u64,2>{v_c256, 0})) return;
          slog::join_probe<5,2>(mbranchindex1356, std::array<u64,5>{v_c29, v_c254, 0, 0, 0}, [&](const std::array<u64,5>& m1415) {
            u64 v_c27 = m1415[2]; u64 v_c28 = m1415[3]; u64 v_c30 = m1415[4];
            if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index1357, std::array<u64,10>{v_c29, v_c28, v_c27, v_c30, v_c253, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex1358, std::array<u64,3>{v_c28, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1359, std::array<u64,2>{v_c27, 0})) return;
            slog::join_probe<9,5>($sup5638x95x0x0x0index1360, std::array<u64,9>{v_c29, v_c28, v_c27, v_c30, v_c253, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1416) {
              u64 v_c23 = m1416[5]; u64 v_c22 = m1416[6]; u64 v_c24 = m1416[7]; u64 v_c19 = m1416[8];
              u64 v_c257 = _prim_lt(db, v_c23, v_c28);
              if (v_c257 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
              if (!v_c257) return;
              if (!slog::exists_probe<5,5>(mbranchindex1361, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, v_c255})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex1362, std::array<u64,3>{v_c22, v_c28, 0})) return;
              slog::join_probe<10,9>($sup5638x95x0x0x1index1363, std::array<u64,10>{v_c29, v_c28, v_c27, v_c30, v_c253, v_c23, v_c22, v_c24, v_c19, 0}, [&](const std::array<u64,10>& m1418) {
                u64 v_c258 = m1418[9];
                slog::join_probe_old<5,5>(mbranchindex1364, mbranchdelta1369, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, v_c255}, [&](const std::array<u64,5>& m1419) {
                  slog::join_probe_old<3,3>(mp_mskindex1365, mp_mskdelta1370, std::array<u64,3>{v_c22, v_c28, v_c258}, [&](const std::array<u64,3>& m1420) {
                    slog::join_probe<2,2>(mp_msk_ansindex1366, std::array<u64,2>{v_c258, v_c27}, [&](const std::array<u64,2>& m1421) {
                      slog::join_probe<2,1>(mp_union_ansindex1367, std::array<u64,2>{v_c256, 0}, [&](const std::array<u64,2>& m1422) {
                        u64 v_c18 = m1422[1];
                        u64 v_c259 = _prim_band(db, v_c22, v_c28);
                        if (v_c259 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c260 = _prim_lt(db, v_c259, v_c252);
                        if (v_c260 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c260) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c253, v_c18, v_c28, v_c27, v_c30});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c28, v_c18, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1371* _cont = new ReadTask1371(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1371(db,b), false);
  // (crule (pre (let __tconst2EWQ349 const6b86b273ff34fce19d6b804e)) (scan mbranch __t5IXI347 p m l r) (body (exists mp_get (1 2 0) 1 __t5IXI347) (exists mp_get (1 2 0) 1 l) (join $sup5638x51x0x0x0 (2 3 4 5 0 1) 4 l m p r __t50Md348 k) (join-old mp_get (0 2 1) 3 (0 2 1) __t50Md348 k __t5IXI347) (join-old mp_get (1 2 0) 2 (1 2 0) l k __t7Zfl351) (join mp_get_ans (0 1) 1 __t7Zfl351 v) (let __t51z6350 (band k m)) (cmp lt __t51z6350 __tconst2EWQ349)) (head (emit mp_get_ans (0 1) __t50Md348 v)) map.slog:52 #f)
  class ReadTask1432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex1424;  slog::Index** mp_getindex1425;  slog::Index** $sup5638x51x0x0x0index1426;  slog::Index** mp_getindex1427;  slog::Index** mp_getindex1428;  slog::Index** mp_get_ansindex1429;  slog::Index** mp_getdelta1430;  slog::Index** mp_getdelta1431;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord1433({0, 1});
      slog::Relation* readrel1434 = db->getRelation("mp_get_ans");
      head_index[0] = readrel1434->getIndex(ord1433, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1435({1, 2, 0});
      slog::Relation* readrel1436 = db->getRelation("mp_get");
      mp_getindex1424 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 2, 0});
      slog::Relation* readrel1438 = db->getRelation("mp_get");
      mp_getindex1425 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel1440 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index1426 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({0, 2, 1});
      slog::Relation* readrel1442 = db->getRelation("mp_get");
      mp_getindex1427 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({0, 2, 1});
      slog::Relation* readrel1444 = db->getRelation("mp_get");
      mp_getdelta1430 = readrel1444->getIndex(ord1443, true);
      std::vector<u16> ord1445({1, 2, 0});
      slog::Relation* readrel1446 = db->getRelation("mp_get");
      mp_getindex1428 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 2, 0});
      slog::Relation* readrel1448 = db->getRelation("mp_get");
      mp_getdelta1431 = readrel1448->getIndex(ord1447, true);
      std::vector<u16> ord1449({0, 1});
      slog::Relation* readrel1450 = db->getRelation("mp_get_ans");
      mp_get_ansindex1429 = readrel1450->getIndex(ord1449, false);
  
    }
    ReadTask1432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c261 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c262 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        if (!slog::exists_probe<3,1>(mp_getindex1424, std::array<u64,3>{v_c262, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_getindex1425, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x51x0x0x0index1426, std::array<u64,6>{v_c29, v_c28, v_c27, v_c30, 0, 0}, [&](const std::array<u64,6>& m1451) {
          u64 v_c263 = m1451[4]; u64 v_c58 = m1451[5];
          slog::join_probe_old<3,3>(mp_getindex1427, mp_getdelta1430, std::array<u64,3>{v_c263, v_c58, v_c262}, [&](const std::array<u64,3>& m1452) {
            slog::join_probe_old<3,2>(mp_getindex1428, mp_getdelta1431, std::array<u64,3>{v_c29, v_c58, 0}, [&](const std::array<u64,3>& m1453) {
              u64 v_c264 = m1453[2];
              slog::join_probe<2,1>(mp_get_ansindex1429, std::array<u64,2>{v_c264, 0}, [&](const std::array<u64,2>& m1454) {
                u64 v_c19 = m1454[1];
                u64 v_c265 = _prim_band(db, v_c58, v_c28);
                if (v_c265 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c266 = _prim_lt(db, v_c265, v_c261);
                if (v_c266 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c266) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c263, v_c19}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1432* _cont = new ReadTask1432(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1432(db,b), false);
  // (crule (pre) (scan mp_get __t8tXp229 __t4yTi228 k) (body (join mleaf (0 1 2) 2 __t4yTi228 k v)) (head (emit mp_get_ans (0 1) __t8tXp229 v)) map.slog:51 #f)
  class ReadTask1457 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex1456;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord1458({0, 1});
      slog::Relation* readrel1459 = db->getRelation("mp_get_ans");
      head_index[0] = readrel1459->getIndex(ord1458, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord1460({0, 1, 2});
      slog::Relation* readrel1461 = db->getRelation("mleaf");
      mleafindex1456 = readrel1461->getIndex(ord1460, false);
  
    }
    ReadTask1457(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c267 = _t[0];
        u64 v_c268 = _t[1];
        u64 v_c58 = _t[2];
        slog::join_probe<3,2>(mleafindex1456, std::array<u64,3>{v_c268, v_c58, 0}, [&](const std::array<u64,3>& m1462) {
          u64 v_c19 = m1462[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c267, v_c19}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:51", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask1457* _cont = new ReadTask1457(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1457(db,b), false);
  // (crule (pre) (scan let __t4Erg439 x er eb) (body (join eval (1 2 3 0) 1 __t4Erg439 rho t __8En81526)) (head (mkstruct eval (1 2 3 0) __1wQ81527 er rho t)) interp.slog:94 #f)
  class ReadTask1464 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1463;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("let");
      std::vector<u16> ord1465({1, 2, 3, 0});
      slog::Relation* readrel1466 = db->getRelation("eval");
      evalindex1463 = readrel1466->getIndex(ord1465, false);
  
    }
    ReadTask1464(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c269 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c5 = _t[3];
        slog::join_probe<4,1>(evalindex1463, std::array<u64,4>{v_c269, 0, 0, 0}, [&](const std::array<u64,4>& m1467) {
          u64 v_c13 = m1467[1]; u64 v_c14 = m1467[2]; u64 v_c270 = m1467[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c36, v_c13, v_c14}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask1464* _cont = new ReadTask1464(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1464(db,b), false);
  // (crule (pre) (scan eval __2hk41536 __t3cXN608 rho t) (body (join-old app (0 1 2) 1 (0 1 2) __t3cXN608 ef es)) (head (mkstruct eval_args (1 3 2 0) __2QMq1537 es t rho)) interp.slog:59 #f)
  class ReadTask1470 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1468;  slog::Index** appdelta1469;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1471({0, 1, 2});
      slog::Relation* readrel1472 = db->getRelation("app");
      appindex1468 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({0, 1, 2});
      slog::Relation* readrel1474 = db->getRelation("app");
      appdelta1469 = readrel1474->getIndex(ord1473, true);
  
    }
    ReadTask1470(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c271 = _t[0];
        u64 v_c272 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        slog::join_probe_old<3,1>(appindex1468, appdelta1469, std::array<u64,3>{v_c272, 0, 0}, [&](const std::array<u64,3>& m1475) {
          u64 v_c11 = m1475[1]; u64 v_c12 = m1475[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c14, v_c13}, std::array<u16,4>{1, 3, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1470* _cont = new ReadTask1470(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1470(db,b), false);
  // (crule (pre (let __trid2bIE1179 const5f7e60cb3d02e4170101c2bc) (let __trel102p1180 constdd7bbf31ce5f578b9805e840) (let __tcol13Ni1181 const5feceb66ffc86f38d952786c) (let __trel0Hro1182 constdd7bbf31ce5f578b9805e840) (let __tcol7vlP1183 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid2bIE1179 __trel102p1180 __tcol13Ni1181 (1 2 3 4 0)) (tycheck n (accept int) __trid2bIE1179 __trel0Hro1182 __tcol7vlP1183 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __7sQV1178 p n)) map.slog:105 #f)
  class ReadTask1476 : public slog::Task
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
    ReadTask1476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c273 = v_const5f7e60cb3d02e4170101c2bc;
      u64 v_c274 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c275 = v_const5feceb66ffc86f38d952786c;
      u64 v_c276 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c277 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c57 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c30 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c19 = _t[8];
        ++_fires;
        if (!(is_int(v_c27)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c273, v_c274, v_c275, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c23)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c273, v_c276, v_c277, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c27, v_c23}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1476* _cont = new ReadTask1476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1476(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan $sup5638x107x0x0x0 __t5Sgr680 l m n p q r u v) (body (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 v) (join-old $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t5Sgr680 l m p r __t78qG683) (exists mp_msk (1 2 0) 3 p n __t78qG683) (exists mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t105R678) (exists mp_union (2 0 1) 2 __t105R678 __t5Sgr680) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Sgr680 __t0Aux684 __t105R678) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask1499 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1477;  slog::Index** mbranchindex1478;  slog::Index** mp_mskindex1479;  slog::Index** mp_msk_ansindex1480;  slog::Index** mp_unionindex1481;  slog::Index** $sup5638x107x0x0x1index1482;  slog::Index** mp_mskindex1483;  slog::Index** mp_msk_ansindex1484;  slog::Index** mbranchindex1485;  slog::Index** mp_unionindex1486;  slog::Index** mbranchindex1487;  slog::Index** mp_unionindex1488;  slog::Index** mp_mskindex1489;  slog::Index** mp_msk_ansindex1490;  slog::Index** mp_unionindex1491;  slog::Index** mp_union_ansindex1492;  slog::Index** $sup5638x107x0x0x1delta1493;  slog::Index** mbranchdelta1494;  slog::Index** mbranchdelta1495;  slog::Index** mp_uniondelta1496;  slog::Index** mp_mskdelta1497;  slog::Index** mp_uniondelta1498;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord1500({1, 2, 3, 4, 0});
      slog::Relation* readrel1501 = db->getRelation("mbranch");
      mbranchindex1477 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({1, 2, 3, 4, 0});
      slog::Relation* readrel1503 = db->getRelation("mbranch");
      mbranchindex1478 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("mp_msk");
      mp_mskindex1479 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 0});
      slog::Relation* readrel1507 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1480 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({2, 0, 1});
      slog::Relation* readrel1509 = db->getRelation("mp_union");
      mp_unionindex1481 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1511 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1482 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1513 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta1493 = readrel1513->getIndex(ord1512, true);
      std::vector<u16> ord1514({1, 2, 0});
      slog::Relation* readrel1515 = db->getRelation("mp_msk");
      mp_mskindex1483 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({0, 1});
      slog::Relation* readrel1517 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1484 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 2, 3, 4, 0});
      slog::Relation* readrel1519 = db->getRelation("mbranch");
      mbranchindex1485 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 2, 3, 4, 0});
      slog::Relation* readrel1521 = db->getRelation("mbranch");
      mbranchdelta1494 = readrel1521->getIndex(ord1520, true);
      std::vector<u16> ord1522({2, 0, 1});
      slog::Relation* readrel1523 = db->getRelation("mp_union");
      mp_unionindex1486 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({1, 2, 3, 4, 0});
      slog::Relation* readrel1525 = db->getRelation("mbranch");
      mbranchindex1487 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({1, 2, 3, 4, 0});
      slog::Relation* readrel1527 = db->getRelation("mbranch");
      mbranchdelta1495 = readrel1527->getIndex(ord1526, true);
      std::vector<u16> ord1528({0, 1, 2});
      slog::Relation* readrel1529 = db->getRelation("mp_union");
      mp_unionindex1488 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({0, 1, 2});
      slog::Relation* readrel1531 = db->getRelation("mp_union");
      mp_uniondelta1496 = readrel1531->getIndex(ord1530, true);
      std::vector<u16> ord1532({1, 2, 0});
      slog::Relation* readrel1533 = db->getRelation("mp_msk");
      mp_mskindex1489 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 2, 0});
      slog::Relation* readrel1535 = db->getRelation("mp_msk");
      mp_mskdelta1497 = readrel1535->getIndex(ord1534, true);
      std::vector<u16> ord1536({0, 1});
      slog::Relation* readrel1537 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1490 = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({1, 2, 0});
      slog::Relation* readrel1539 = db->getRelation("mp_union");
      mp_unionindex1491 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({1, 2, 0});
      slog::Relation* readrel1541 = db->getRelation("mp_union");
      mp_uniondelta1498 = readrel1541->getIndex(ord1540, true);
      std::vector<u16> ord1542({0, 1});
      slog::Relation* readrel1543 = db->getRelation("mp_union_ans");
      mp_union_ansindex1492 = readrel1543->getIndex(ord1542, false);
  
    }
    ReadTask1499(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c29 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c30 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c19 = _t[8];
        u64 v_c278 = _prim_lt(db, v_c28, v_c23);
        if (v_c278 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
        if (!v_c278) return;
        if (!slog::exists_probe<5,4>(mbranchindex1477, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex1478, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex1479, std::array<u64,3>{v_c27, v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1480, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1481, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x107x0x0x1index1482, $sup5638x107x0x0x1delta1493, std::array<u64,10>{v_c19, v_c23, v_c22, v_c24, v_c61, v_c29, v_c28, v_c27, v_c30, 0}, [&](const std::array<u64,10>& m1545) {
          u64 v_c63 = m1545[9];
          if (!slog::exists_probe<3,3>(mp_mskindex1483, std::array<u64,3>{v_c27, v_c23, v_c63})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex1484, std::array<u64,2>{v_c63, v_c22})) return;
          slog::join_probe_old<5,4>(mbranchindex1485, mbranchdelta1494, std::array<u64,5>{v_c22, v_c23, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m1546) {
            u64 v_c60 = m1546[4];
            if (!slog::exists_probe<3,2>(mp_unionindex1486, std::array<u64,3>{v_c60, v_c61, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1487, mbranchdelta1495, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m1547) {
              u64 v_c64 = m1547[4];
              slog::join_probe_old<3,3>(mp_unionindex1488, mp_uniondelta1496, std::array<u64,3>{v_c61, v_c64, v_c60}, [&](const std::array<u64,3>& m1548) {
                slog::join_probe_old<3,3>(mp_mskindex1489, mp_mskdelta1497, std::array<u64,3>{v_c27, v_c23, v_c63}, [&](const std::array<u64,3>& m1549) {
                  slog::join_probe<2,2>(mp_msk_ansindex1490, std::array<u64,2>{v_c63, v_c22}, [&](const std::array<u64,2>& m1550) {
                    slog::join_probe_old<3,2>(mp_unionindex1491, mp_uniondelta1498, std::array<u64,3>{v_c64, v_c19, 0}, [&](const std::array<u64,3>& m1551) {
                      u64 v_c65 = m1551[2];
                      slog::join_probe<2,1>(mp_union_ansindex1492, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m1552) {
                        u64 v_c18 = m1552[1];
                        u64 v_c66 = _prim_band(db, v_c27, v_c23);
                        if (v_c66 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c279 = _prim_gt(db, v_c66, v_c59);
                        if (v_c279 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c279) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c61, v_c18, v_c23, v_c22, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1499* _cont = new ReadTask1499(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1499(db,b), false);
  // (crule (pre) (scan mleaf __t6x7f385 k v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t6x7f385 __t4rVj386 s)) (head (mkstruct mp_put_soft (1 2 3 0) __6BWr1132 s k v)) map.slog:93 #f)
  class ReadTask1556 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1554;  slog::Index** mp_uniondelta1555;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord1557({2, 0, 1});
      slog::Relation* readrel1558 = db->getRelation("mp_union");
      mp_unionindex1554 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({2, 0, 1});
      slog::Relation* readrel1560 = db->getRelation("mp_union");
      mp_uniondelta1555 = readrel1560->getIndex(ord1559, true);
  
    }
    ReadTask1556(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c280 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe_old<3,1>(mp_unionindex1554, mp_uniondelta1555, std::array<u64,3>{v_c280, 0, 0}, [&](const std::array<u64,3>& m1561) {
          u64 v_c281 = m1561[1]; u64 v_c282 = m1561[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c282, v_c58, v_c19}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask1556* _cont = new ReadTask1556(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1556(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t51z5346 p) (body (exists $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t51z5346 q m) (join $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t51z5346 l m n p q u v)) map.slog:99 #f)
  class ReadTask1566 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index1562;  slog::Index** mp_mskindex1563;  slog::Index** $sup5638x98x0x0x0index1564;  slog::Index** mp_mskdelta1565;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord1567({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel1568 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel1568->getIndex(ord1567, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1569({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1570 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1562 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({0, 1, 2});
      slog::Relation* readrel1572 = db->getRelation("mp_msk");
      mp_mskindex1563 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({0, 1, 2});
      slog::Relation* readrel1574 = db->getRelation("mp_msk");
      mp_mskdelta1565 = readrel1574->getIndex(ord1573, true);
      std::vector<u16> ord1575({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1576 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1564 = readrel1576->getIndex(ord1575, false);
  
    }
    ReadTask1566(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c283 = _t[0];
        u64 v_c27 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index1562, std::array<u64,9>{v_c27, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1563, mp_mskdelta1565, std::array<u64,3>{v_c283, 0, 0}, [&](const std::array<u64,3>& m1577) {
          u64 v_c22 = m1577[1]; u64 v_c28 = m1577[2];
          slog::join_probe<9,3>($sup5638x98x0x0x0index1564, std::array<u64,9>{v_c28, v_c22, v_c27, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1578) {
            u64 v_c57 = m1578[3]; u64 v_c29 = m1578[4]; u64 v_c23 = m1578[5]; u64 v_c30 = m1578[6]; u64 v_c24 = m1578[7]; u64 v_c19 = m1578[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c57, v_c30, v_c283, v_c29, v_c28, v_c23, v_c27, v_c22, v_c24, v_c19}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1566* _cont = new ReadTask1566(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1566(db,b), false);
  // (crule (pre) (scan eval_args __t2ycT266 es rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 t) (exists eval_args_ans (0 1) 1 __t2ycT266) (join $sup70016x51x0x0x0 (2 3 4 0 1) 3 es rho t __d0 ef) (exists app (1 2 0) 2 ef es) (join eval (1 2 3 0) 3 ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join tick_ans (0 1) 1 __t8A6X268 t2) (join closure (0 1 2) 1 __t5Yru265 __t3Nsh264 rhoc) (join lambda (0 1 2) 1 __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask1597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1579;  slog::Index** appindex1580;  slog::Index** tickindex1581;  slog::Index** eval_args_ansindex1582;  slog::Index** $sup70016x51x0x0x0index1583;  slog::Index** appindex1584;  slog::Index** evalindex1585;  slog::Index** eval_ansindex1586;  slog::Index** appindex1587;  slog::Index** tickindex1588;  slog::Index** tick_ansindex1589;  slog::Index** eval_ansindex1590;  slog::Index** eval_args_ansindex1591;  slog::Index** tick_ansindex1592;  slog::Index** closureindex1593;  slog::Index** lambdaindex1594;  slog::Index** appdelta1595;  slog::Index** tickdelta1596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord1598({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1599 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel1599->getIndex(ord1598, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1600({2, 3, 0, 1});
      slog::Relation* readrel1601 = db->getRelation("eval");
      evalindex1579 = readrel1601->getIndex(ord1600, false);
      std::vector<u16> ord1602({2, 0, 1});
      slog::Relation* readrel1603 = db->getRelation("app");
      appindex1580 = readrel1603->getIndex(ord1602, false);
      std::vector<u16> ord1604({2, 0, 1});
      slog::Relation* readrel1605 = db->getRelation("tick");
      tickindex1581 = readrel1605->getIndex(ord1604, false);
      std::vector<u16> ord1606({0, 1});
      slog::Relation* readrel1607 = db->getRelation("eval_args_ans");
      eval_args_ansindex1582 = readrel1607->getIndex(ord1606, false);
      std::vector<u16> ord1608({2, 3, 4, 0, 1});
      slog::Relation* readrel1609 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1583 = readrel1609->getIndex(ord1608, false);
      std::vector<u16> ord1610({1, 2, 0});
      slog::Relation* readrel1611 = db->getRelation("app");
      appindex1584 = readrel1611->getIndex(ord1610, false);
      std::vector<u16> ord1612({1, 2, 3, 0});
      slog::Relation* readrel1613 = db->getRelation("eval");
      evalindex1585 = readrel1613->getIndex(ord1612, false);
      std::vector<u16> ord1614({0, 1});
      slog::Relation* readrel1615 = db->getRelation("eval_ans");
      eval_ansindex1586 = readrel1615->getIndex(ord1614, false);
      std::vector<u16> ord1616({1, 2, 0});
      slog::Relation* readrel1617 = db->getRelation("app");
      appindex1587 = readrel1617->getIndex(ord1616, false);
      std::vector<u16> ord1618({1, 2, 0});
      slog::Relation* readrel1619 = db->getRelation("app");
      appdelta1595 = readrel1619->getIndex(ord1618, true);
      std::vector<u16> ord1620({1, 2, 0});
      slog::Relation* readrel1621 = db->getRelation("tick");
      tickindex1588 = readrel1621->getIndex(ord1620, false);
      std::vector<u16> ord1622({1, 2, 0});
      slog::Relation* readrel1623 = db->getRelation("tick");
      tickdelta1596 = readrel1623->getIndex(ord1622, true);
      std::vector<u16> ord1624({0, 1});
      slog::Relation* readrel1625 = db->getRelation("tick_ans");
      tick_ansindex1589 = readrel1625->getIndex(ord1624, false);
      std::vector<u16> ord1626({0, 1});
      slog::Relation* readrel1627 = db->getRelation("eval_ans");
      eval_ansindex1590 = readrel1627->getIndex(ord1626, false);
      std::vector<u16> ord1628({0, 1});
      slog::Relation* readrel1629 = db->getRelation("eval_args_ans");
      eval_args_ansindex1591 = readrel1629->getIndex(ord1628, false);
      std::vector<u16> ord1630({0, 1});
      slog::Relation* readrel1631 = db->getRelation("tick_ans");
      tick_ansindex1592 = readrel1631->getIndex(ord1630, false);
      std::vector<u16> ord1632({0, 1, 2});
      slog::Relation* readrel1633 = db->getRelation("closure");
      closureindex1593 = readrel1633->getIndex(ord1632, false);
      std::vector<u16> ord1634({0, 1, 2});
      slog::Relation* readrel1635 = db->getRelation("lambda");
      lambdaindex1594 = readrel1635->getIndex(ord1634, false);
  
    }
    ReadTask1597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c284 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex1579, std::array<u64,4>{v_c13, v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1580, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1581, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1582, std::array<u64,2>{v_c284, 0})) return;
        slog::join_probe<5,3>($sup70016x51x0x0x0index1583, std::array<u64,5>{v_c12, v_c13, v_c14, 0, 0}, [&](const std::array<u64,5>& m1636) {
          u64 v_c57 = m1636[3]; u64 v_c11 = m1636[4];
          if (!slog::exists_probe<3,2>(appindex1584, std::array<u64,3>{v_c11, v_c12, 0})) return;
          slog::join_probe<4,3>(evalindex1585, std::array<u64,4>{v_c11, v_c13, v_c14, 0}, [&](const std::array<u64,4>& m1637) {
            u64 v_c285 = m1637[3];
            if (!slog::exists_probe<2,1>(eval_ansindex1586, std::array<u64,2>{v_c285, 0})) return;
            slog::join_probe_old<3,2>(appindex1587, appdelta1595, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m1638) {
              u64 v_c286 = m1638[2];
              slog::join_probe_old<3,2>(tickindex1588, tickdelta1596, std::array<u64,3>{v_c286, v_c14, 0}, [&](const std::array<u64,3>& m1639) {
                u64 v_c287 = m1639[2];
                if (!slog::exists_probe<2,1>(tick_ansindex1589, std::array<u64,2>{v_c287, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1590, std::array<u64,2>{v_c285, 0}, [&](const std::array<u64,2>& m1640) {
                  u64 v_c288 = m1640[1];
                  slog::join_probe<2,1>(eval_args_ansindex1591, std::array<u64,2>{v_c284, 0}, [&](const std::array<u64,2>& m1641) {
                    u64 v_c15 = m1641[1];
                    slog::join_probe<2,1>(tick_ansindex1592, std::array<u64,2>{v_c287, 0}, [&](const std::array<u64,2>& m1642) {
                      u64 v_c6 = m1642[1];
                      slog::join_probe<3,1>(closureindex1593, std::array<u64,3>{v_c288, 0, 0}, [&](const std::array<u64,3>& m1643) {
                        u64 v_c289 = m1643[1]; u64 v_c2 = m1643[2];
                        slog::join_probe<3,1>(lambdaindex1594, std::array<u64,3>{v_c289, 0, 0}, [&](const std::array<u64,3>& m1644) {
                          u64 v_c4 = m1644[1]; u64 v_c5 = m1644[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c285, v_c2, v_c57, v_c284, v_c287, v_c5, v_c11, v_c12, v_c13, v_c14, v_c6, v_c15, v_c4}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1597* _cont = new ReadTask1597(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1597(db,b), false);
  // (crule (pre (let __t0SOq399 (lempty))) (scan tick __t7qQQ398 site t) (body (join klimit (0) 0 k) (let __t7jWC400 (lpush __t0SOq399 site)) (let __t3PGq401 (lcat __t7jWC400 t)) (join-old lst_take (1 2 0) 2 (1 2 0) __t3PGq401 k __t4nP5402) (join lst_take_ans (0 1) 1 __t4nP5402 __v0)) (head (emit tick_ans (0 1) __t7qQQ398 __v0)) context.slog:11 #f)
  class ReadTask1649 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** klimitindex1645;  slog::Index** lst_takeindex1646;  slog::Index** lst_take_ansindex1647;  slog::Index** lst_takedelta1648;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord1650({0, 1});
      slog::Relation* readrel1651 = db->getRelation("tick_ans");
      head_index[0] = readrel1651->getIndex(ord1650, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1652({0});
      slog::Relation* readrel1653 = db->getRelation("klimit");
      klimitindex1645 = readrel1653->getIndex(ord1652, false);
      std::vector<u16> ord1654({1, 2, 0});
      slog::Relation* readrel1655 = db->getRelation("lst_take");
      lst_takeindex1646 = readrel1655->getIndex(ord1654, false);
      std::vector<u16> ord1656({1, 2, 0});
      slog::Relation* readrel1657 = db->getRelation("lst_take");
      lst_takedelta1648 = readrel1657->getIndex(ord1656, true);
      std::vector<u16> ord1658({0, 1});
      slog::Relation* readrel1659 = db->getRelation("lst_take_ans");
      lst_take_ansindex1647 = readrel1659->getIndex(ord1658, false);
  
    }
    ReadTask1649(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c290 = _prim_lempty(db);
      if (v_c290 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c291 = _t[0];
        u64 v_c292 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_all<1>(klimitindex1645, [&](const std::array<u64,1>& m1660) {
          u64 v_c58 = m1660[0];
          u64 v_c293 = _prim_lpush(db, v_c290, v_c292);
          if (v_c293 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
          u64 v_c294 = _prim_lcat(db, v_c293, v_c14);
          if (v_c294 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
          slog::join_probe_old<3,2>(lst_takeindex1646, lst_takedelta1648, std::array<u64,3>{v_c294, v_c58, 0}, [&](const std::array<u64,3>& m1661) {
            u64 v_c295 = m1661[2];
            slog::join_probe<2,1>(lst_take_ansindex1647, std::array<u64,2>{v_c295, 0}, [&](const std::array<u64,2>& m1662) {
              u64 v_c18 = m1662[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c291, v_c18}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask1649* _cont = new ReadTask1649(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1649(db,b), false);
  // (crule (pre (let __tconst7YVO1086 constb9e118781cea1f9fa01462e0) (let __tconst0qOo437 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0uxV1007 const6b86b273ff34fce19d6b804e) (let _00024sqc0jY31008 const5feceb66ffc86f38d952786c) (let _00024sqo1OME1009 const5feceb66ffc86f38d952786c) (let _00024sqo3mx21010 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst0qOo437 _00024seq0 __t4KDF438) (body (letp _00024sql5Lne1005 (aslst _00024seq0)) (letp v (lref _00024sql5Lne1005 _00024sqc0jY31008)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1OME1009 v _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3mx21010 v _00024seq0) (join _enum (1 0) 1 __tconst7YVO1086 __t2dgW435) (join scheme_false (0) 0 fv) (neq v fv) (let chk4RnG1818 (llen _00024sql5Lne1005)) (eq _00024sqc0uxV1007 chk4RnG1818)) (head (emit-temp temp6YY41815 __t4KDF438) (mkstruct boolval (1 0) __t83Bj436 __t2dgW435)) interp.slog:119 #f)
  class ReadTask1669 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1663;  slog::Index** $seq_atrindex1664;  slog::Index** _enumindex1665;  slog::Index** scheme_falseindex1666;  slog::Index** $seq_atdelta1667;  slog::Index** $seq_atrdelta1668;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6YY41815");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1670({1, 2, 0});
      slog::Relation* readrel1671 = db->getRelation("delta");
      driver_index = readrel1671->getIndex(ord1670, true);
      std::vector<u16> ord1672({1, 0, 2});
      slog::Relation* readrel1673 = db->getRelation("$seq_at");
      $seq_atindex1663 = readrel1673->getIndex(ord1672, false);
      std::vector<u16> ord1674({1, 0, 2});
      slog::Relation* readrel1675 = db->getRelation("$seq_at");
      $seq_atdelta1667 = readrel1675->getIndex(ord1674, true);
      std::vector<u16> ord1676({1, 0, 2});
      slog::Relation* readrel1677 = db->getRelation("$seq_atr");
      $seq_atrindex1664 = readrel1677->getIndex(ord1676, false);
      std::vector<u16> ord1678({1, 0, 2});
      slog::Relation* readrel1679 = db->getRelation("$seq_atr");
      $seq_atrdelta1668 = readrel1679->getIndex(ord1678, true);
      std::vector<u16> ord1680({1, 0});
      slog::Relation* readrel1681 = db->getRelation("_enum");
      _enumindex1665 = readrel1681->getIndex(ord1680, false);
      std::vector<u16> ord1682({0});
      slog::Relation* readrel1683 = db->getRelation("scheme_false");
      scheme_falseindex1666 = readrel1683->getIndex(ord1682, false);
  
    }
    ReadTask1669(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c296 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c297 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c298 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c299 = v_const5feceb66ffc86f38d952786c;
      u64 v_c300 = v_const5feceb66ffc86f38d952786c;
      u64 v_c301 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c297, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1684) {
        u64 v_c224 = m1684[1];
        u64 v_c302 = m1684[2];
        if (buckethash(v_c224) != bucket) return;
        bool ok1685 = true;
        u64 v_c303 = _prim_aslst(db, v_c224, &ok1685);
        if (!ok1685) return;
        bool ok1686 = true;
        u64 v_c19 = _prim_lref(db, v_c303, v_c299, &ok1686);
        if (!ok1686) return;
        slog::join_probe_old<3,3>($seq_atindex1663, $seq_atdelta1667, std::array<u64,3>{v_c300, v_c19, v_c224}, [&](const std::array<u64,3>& m1687) {
          slog::join_probe_old<3,3>($seq_atrindex1664, $seq_atrdelta1668, std::array<u64,3>{v_c301, v_c19, v_c224}, [&](const std::array<u64,3>& m1688) {
            slog::join_probe<2,1>(_enumindex1665, std::array<u64,2>{v_c296, 0}, [&](const std::array<u64,2>& m1689) {
              u64 v_c304 = m1689[1];
              slog::join_all<1>(scheme_falseindex1666, [&](const std::array<u64,1>& m1690) {
                u64 v_c305 = m1690[0];
                if (v_c19 == v_c305) return;
                u64 v_c306 = _prim_llen(db, v_c303);
                if (v_c306 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                if (v_c298 != v_c306) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c302});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c304}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1669* _cont = new ReadTask1669(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1669(db,b), false);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst1XI2167 const3fdba35f04dc8c462986c992) (let __tconst2wxb180 const4fc82b26aecb47d2868c4efb) (let __tconst5TvD157 const06abaa100ecef791ce028c56)) (scan temp9mV91991 __t1jRc182 __t39Ee172 __t6qCj155 __t9exo163) (body (exists primref (1 0) 1 __tconst5TvD157) (exists ref (1 0) 1 __tconst5vD0184) (exists ref (1 0) 1 __tconst2wxb180) (join ref (1 0) 1 __tconst1XI2167 __t8RaS151) (join primref (1 0) 1 __tconst5TvD157 __t2ZGf158) (join ref (1 0) 1 __tconst5vD0184 __t1od9165) (join ref (1 0) 1 __tconst2wxb180 __t1BW9179) (let __t7NO4156 (lpush __t6qCj155 __t8RaS151))) (head (emit-temp temp7sUm1992 __t1jRc182 __t39Ee172 __t7NO4156 __t9exo163) (mkstruct lambda (1 2 0) __t9kRL183 __t1jRc182 __t1BW9179) (mkstruct app (1 2 0) __t9GVo175 __t1od9165 __t39Ee172) (mkstruct app (1 2 0) __t3ORQ166 __t1od9165 __t9exo163)) kcfa.slog:29 #f)
  class ReadTask1698 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primrefindex1691;  slog::Index** refindex1692;  slog::Index** refindex1693;  slog::Index** refindex1694;  slog::Index** primrefindex1695;  slog::Index** refindex1696;  slog::Index** refindex1697;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7sUm1992");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("app");
      outer_rel = db->getRelation("temp9mV91991");
      std::vector<u16> ord1699({1, 0});
      slog::Relation* readrel1700 = db->getRelation("primref");
      primrefindex1691 = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({1, 0});
      slog::Relation* readrel1702 = db->getRelation("ref");
      refindex1692 = readrel1702->getIndex(ord1701, false);
      std::vector<u16> ord1703({1, 0});
      slog::Relation* readrel1704 = db->getRelation("ref");
      refindex1693 = readrel1704->getIndex(ord1703, false);
      std::vector<u16> ord1705({1, 0});
      slog::Relation* readrel1706 = db->getRelation("ref");
      refindex1694 = readrel1706->getIndex(ord1705, false);
      std::vector<u16> ord1707({1, 0});
      slog::Relation* readrel1708 = db->getRelation("primref");
      primrefindex1695 = readrel1708->getIndex(ord1707, false);
      std::vector<u16> ord1709({1, 0});
      slog::Relation* readrel1710 = db->getRelation("ref");
      refindex1696 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({1, 0});
      slog::Relation* readrel1712 = db->getRelation("ref");
      refindex1697 = readrel1712->getIndex(ord1711, false);
  
    }
    ReadTask1698(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c307 = v_const4a44dc15364204a80fe80e90;
      u64 v_c308 = v_const6b51d431df5d7f141cbececc;
      u64 v_c309 = v_const3fdba35f04dc8c462986c992;
      u64 v_c310 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c311 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c312 = _t[0];
        u64 v_c313 = _t[1];
        u64 v_c314 = _t[2];
        u64 v_c315 = _t[3];
        if (!slog::exists_probe<2,1>(primrefindex1691, std::array<u64,2>{v_c311, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1692, std::array<u64,2>{v_c307, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1693, std::array<u64,2>{v_c310, 0})) return;
        slog::join_probe<2,1>(refindex1694, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m1713) {
          u64 v_c316 = m1713[1];
          slog::join_probe<2,1>(primrefindex1695, std::array<u64,2>{v_c311, 0}, [&](const std::array<u64,2>& m1714) {
            u64 v_c317 = m1714[1];
            slog::join_probe<2,1>(refindex1696, std::array<u64,2>{v_c307, 0}, [&](const std::array<u64,2>& m1715) {
              u64 v_c318 = m1715[1];
              slog::join_probe<2,1>(refindex1697, std::array<u64,2>{v_c310, 0}, [&](const std::array<u64,2>& m1716) {
                u64 v_c319 = m1716[1];
                u64 v_c320 = _prim_lpush(db, v_c314, v_c316);
                if (v_c320 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return; }
                ++_fires;
                slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c312, v_c313, v_c320, v_c315});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c312, v_c319}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c318, v_c313}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c318, v_c315}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp9mV91991", _fires);
  
      if (!_done)
      {
        ReadTask1698* _cont = new ReadTask1698(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1698(db,b), false);
  // (crule (pre (let __tconst4bk430 const5feceb66ffc86f38d952786c)) (scan mbranch __t9yY728 p m l r) (body (join-old mp_get (1 2 0) 1 (1 2 0) __t9yY728 k __t3H4x29) (let __t9Jlq31 (band k m)) (cmp gt __t9Jlq31 __tconst4bk430)) (head (emit $sup5638x52x0x0x0 (0 1 2 3 4 5) __t3H4x29 k l m p r)) map.slog:53 #f)
  class ReadTask1719 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex1717;  slog::Index** mp_getdelta1718;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord1720({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1721 = db->getRelation("$sup5638x52x0x0x0");
      head_index[0] = readrel1721->getIndex(ord1720, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1722({1, 2, 0});
      slog::Relation* readrel1723 = db->getRelation("mp_get");
      mp_getindex1717 = readrel1723->getIndex(ord1722, false);
      std::vector<u16> ord1724({1, 2, 0});
      slog::Relation* readrel1725 = db->getRelation("mp_get");
      mp_getdelta1718 = readrel1725->getIndex(ord1724, true);
  
    }
    ReadTask1719(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c321 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c322 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe_old<3,1>(mp_getindex1717, mp_getdelta1718, std::array<u64,3>{v_c322, 0, 0}, [&](const std::array<u64,3>& m1726) {
          u64 v_c58 = m1726[1]; u64 v_c323 = m1726[2];
          u64 v_c324 = _prim_band(db, v_c58, v_c28);
          if (v_c324 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
          u64 v_c325 = _prim_gt(db, v_c324, v_c321);
          if (v_c325 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
          if (!v_c325) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c323, v_c58, v_c29, v_c28, v_c27, v_c30}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1719* _cont = new ReadTask1719(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1719(db,b), false);
  // (crule (pre (let __tconst8wBL581 const5feceb66ffc86f38d952786c)) (scan mp_msk __t7zc5584 k m) (body (exists $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t7zc5584 __v0) (join $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 k m __t8lWf583 l p r) (neq p __v0) (exists mp_has0 (0 2 1) 2 __t8lWf583 k) (join mbranch (1 2 3 4 0) 4 p m l r __t0T68582) (join mp_has0 (0 2 1) 3 __t8lWf583 k __t0T68582)) (head (emit mp_has0_ans (0 1) __t8lWf583 __tconst8wBL581)) map.slog:60 #f)
  class ReadTask1736 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x59x0x0x0index1728;  slog::Index** mbranchindex1729;  slog::Index** mp_has0index1730;  slog::Index** mp_msk_ansindex1731;  slog::Index** $sup5638x59x0x0x0index1732;  slog::Index** mp_has0index1733;  slog::Index** mbranchindex1734;  slog::Index** mp_has0index1735;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1737({0, 1});
      slog::Relation* readrel1738 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1738->getIndex(ord1737, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1739({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel1740 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index1728 = readrel1740->getIndex(ord1739, false);
      std::vector<u16> ord1741({2, 0, 1, 3, 4});
      slog::Relation* readrel1742 = db->getRelation("mbranch");
      mbranchindex1729 = readrel1742->getIndex(ord1741, false);
      std::vector<u16> ord1743({2, 0, 1});
      slog::Relation* readrel1744 = db->getRelation("mp_has0");
      mp_has0index1730 = readrel1744->getIndex(ord1743, false);
      std::vector<u16> ord1745({0, 1});
      slog::Relation* readrel1746 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1731 = readrel1746->getIndex(ord1745, false);
      std::vector<u16> ord1747({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel1748 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index1732 = readrel1748->getIndex(ord1747, false);
      std::vector<u16> ord1749({0, 2, 1});
      slog::Relation* readrel1750 = db->getRelation("mp_has0");
      mp_has0index1733 = readrel1750->getIndex(ord1749, false);
      std::vector<u16> ord1751({1, 2, 3, 4, 0});
      slog::Relation* readrel1752 = db->getRelation("mbranch");
      mbranchindex1734 = readrel1752->getIndex(ord1751, false);
      std::vector<u16> ord1753({0, 2, 1});
      slog::Relation* readrel1754 = db->getRelation("mp_has0");
      mp_has0index1735 = readrel1754->getIndex(ord1753, false);
  
    }
    ReadTask1736(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c206 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c28 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x59x0x0x0index1728, std::array<u64,6>{v_c58, v_c28, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1729, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index1730, std::array<u64,3>{v_c58, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1731, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1755) {
          u64 v_c18 = m1755[1];
          slog::join_probe<6,2>($sup5638x59x0x0x0index1732, std::array<u64,6>{v_c58, v_c28, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1756) {
            u64 v_c205 = m1756[2]; u64 v_c29 = m1756[3]; u64 v_c27 = m1756[4]; u64 v_c30 = m1756[5];
            if (v_c27 == v_c18) return;
            if (!slog::exists_probe<3,2>(mp_has0index1733, std::array<u64,3>{v_c205, v_c58, 0})) return;
            slog::join_probe<5,4>(mbranchindex1734, std::array<u64,5>{v_c27, v_c28, v_c29, v_c30, 0}, [&](const std::array<u64,5>& m1757) {
              u64 v_c204 = m1757[4];
              slog::join_probe<3,3>(mp_has0index1735, std::array<u64,3>{v_c205, v_c58, v_c204}, [&](const std::array<u64,3>& m1758) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c205, v_c203}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1736* _cont = new ReadTask1736(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1736(db,b), false);
  // (crule (pre) (scan mp_put_ans __t0Rig361 rho2) (body (exists $sup70016x95x0x0x1 (1 5 0 2 3 4 6 7) 2 __t0Rig361 rho2) (exists eval (2 3 0 1) 1 rho2) (join-old eval (2 3 0 1) 1 (2 3 0 1) rho2 t __t6HuT359 er) (exists $sup70016x95x0x0x0 (2 4 0 1 3 5) 2 er t) (exists mp_put (3 0 2 1) 2 t __t0Rig361) (exists letrec (2 3 0 1) 1 er) (exists eval (3 1 0 2) 1 t) (exists eval (2 3 0 1) 2 rho2 t) (exists eval_ans (0 1) 1 __t6HuT359) (join-old $sup70016x95x0x0x1 (3 5 6 1 0 2 4 7) 4 (3 5 6 1 0 2 4 7) er rho2 t __t0Rig361 __t7DhJ358 eb rho x) (join-old $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists eval (1 2 3 0) 3 eb rho2 t) (join-old letrec (1 2 3 0) 3 (1 2 3 0) x er eb __t0Sks357) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb rho2 t __t63JF360) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask1786 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x1index1759;  slog::Index** evalindex1760;  slog::Index** evalindex1761;  slog::Index** $sup70016x95x0x0x0index1762;  slog::Index** mp_putindex1763;  slog::Index** letrecindex1764;  slog::Index** evalindex1765;  slog::Index** evalindex1766;  slog::Index** eval_ansindex1767;  slog::Index** $sup70016x95x0x0x1index1768;  slog::Index** $sup70016x95x0x0x0index1769;  slog::Index** mp_putindex1770;  slog::Index** evalindex1771;  slog::Index** evalindex1772;  slog::Index** letrecindex1773;  slog::Index** evalindex1774;  slog::Index** evalindex1775;  slog::Index** eval_ansindex1776;  slog::Index** eval_ansindex1777;  slog::Index** eval_ansindex1778;  slog::Index** evaldelta1779;  slog::Index** $sup70016x95x0x0x1delta1780;  slog::Index** $sup70016x95x0x0x0delta1781;  slog::Index** mp_putdelta1782;  slog::Index** letrecdelta1783;  slog::Index** evaldelta1784;  slog::Index** evaldelta1785;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1787({0, 1});
      slog::Relation* readrel1788 = db->getRelation("eval_ans");
      head_index[0] = readrel1788->getIndex(ord1787, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord1789({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel1790 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index1759 = readrel1790->getIndex(ord1789, false);
      std::vector<u16> ord1791({2, 3, 0, 1});
      slog::Relation* readrel1792 = db->getRelation("eval");
      evalindex1760 = readrel1792->getIndex(ord1791, false);
      std::vector<u16> ord1793({2, 3, 0, 1});
      slog::Relation* readrel1794 = db->getRelation("eval");
      evalindex1761 = readrel1794->getIndex(ord1793, false);
      std::vector<u16> ord1795({2, 3, 0, 1});
      slog::Relation* readrel1796 = db->getRelation("eval");
      evaldelta1779 = readrel1796->getIndex(ord1795, true);
      std::vector<u16> ord1797({2, 4, 0, 1, 3, 5});
      slog::Relation* readrel1798 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index1762 = readrel1798->getIndex(ord1797, false);
      std::vector<u16> ord1799({3, 0, 2, 1});
      slog::Relation* readrel1800 = db->getRelation("mp_put");
      mp_putindex1763 = readrel1800->getIndex(ord1799, false);
      std::vector<u16> ord1801({2, 3, 0, 1});
      slog::Relation* readrel1802 = db->getRelation("letrec");
      letrecindex1764 = readrel1802->getIndex(ord1801, false);
      std::vector<u16> ord1803({3, 1, 0, 2});
      slog::Relation* readrel1804 = db->getRelation("eval");
      evalindex1765 = readrel1804->getIndex(ord1803, false);
      std::vector<u16> ord1805({2, 3, 0, 1});
      slog::Relation* readrel1806 = db->getRelation("eval");
      evalindex1766 = readrel1806->getIndex(ord1805, false);
      std::vector<u16> ord1807({0, 1});
      slog::Relation* readrel1808 = db->getRelation("eval_ans");
      eval_ansindex1767 = readrel1808->getIndex(ord1807, false);
      std::vector<u16> ord1809({3, 5, 6, 1, 0, 2, 4, 7});
      slog::Relation* readrel1810 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index1768 = readrel1810->getIndex(ord1809, false);
      std::vector<u16> ord1811({3, 5, 6, 1, 0, 2, 4, 7});
      slog::Relation* readrel1812 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1delta1780 = readrel1812->getIndex(ord1811, true);
      std::vector<u16> ord1813({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel1814 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index1769 = readrel1814->getIndex(ord1813, false);
      std::vector<u16> ord1815({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel1816 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0delta1781 = readrel1816->getIndex(ord1815, true);
      std::vector<u16> ord1817({0, 2, 1, 3});
      slog::Relation* readrel1818 = db->getRelation("mp_put");
      mp_putindex1770 = readrel1818->getIndex(ord1817, false);
      std::vector<u16> ord1819({0, 2, 1, 3});
      slog::Relation* readrel1820 = db->getRelation("mp_put");
      mp_putdelta1782 = readrel1820->getIndex(ord1819, true);
      std::vector<u16> ord1821({2, 3, 0, 1});
      slog::Relation* readrel1822 = db->getRelation("eval");
      evalindex1771 = readrel1822->getIndex(ord1821, false);
      std::vector<u16> ord1823({1, 2, 3, 0});
      slog::Relation* readrel1824 = db->getRelation("eval");
      evalindex1772 = readrel1824->getIndex(ord1823, false);
      std::vector<u16> ord1825({1, 2, 3, 0});
      slog::Relation* readrel1826 = db->getRelation("letrec");
      letrecindex1773 = readrel1826->getIndex(ord1825, false);
      std::vector<u16> ord1827({1, 2, 3, 0});
      slog::Relation* readrel1828 = db->getRelation("letrec");
      letrecdelta1783 = readrel1828->getIndex(ord1827, true);
      std::vector<u16> ord1829({2, 3, 0, 1});
      slog::Relation* readrel1830 = db->getRelation("eval");
      evalindex1774 = readrel1830->getIndex(ord1829, false);
      std::vector<u16> ord1831({2, 3, 0, 1});
      slog::Relation* readrel1832 = db->getRelation("eval");
      evaldelta1784 = readrel1832->getIndex(ord1831, true);
      std::vector<u16> ord1833({1, 2, 3, 0});
      slog::Relation* readrel1834 = db->getRelation("eval");
      evalindex1775 = readrel1834->getIndex(ord1833, false);
      std::vector<u16> ord1835({1, 2, 3, 0});
      slog::Relation* readrel1836 = db->getRelation("eval");
      evaldelta1785 = readrel1836->getIndex(ord1835, true);
      std::vector<u16> ord1837({0, 1});
      slog::Relation* readrel1838 = db->getRelation("eval_ans");
      eval_ansindex1776 = readrel1838->getIndex(ord1837, false);
      std::vector<u16> ord1839({0, 1});
      slog::Relation* readrel1840 = db->getRelation("eval_ans");
      eval_ansindex1777 = readrel1840->getIndex(ord1839, false);
      std::vector<u16> ord1841({0, 1});
      slog::Relation* readrel1842 = db->getRelation("eval_ans");
      eval_ansindex1778 = readrel1842->getIndex(ord1841, false);
  
    }
    ReadTask1786(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[1];
        if (!slog::exists_probe<8,2>($sup70016x95x0x0x1index1759, std::array<u64,8>{v_c35, v_c37, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1760, std::array<u64,4>{v_c37, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(evalindex1761, evaldelta1779, std::array<u64,4>{v_c37, 0, 0, 0}, [&](const std::array<u64,4>& m1843) {
          u64 v_c14 = m1843[1]; u64 v_c40 = m1843[2]; u64 v_c36 = m1843[3];
          if (!slog::exists_probe<6,2>($sup70016x95x0x0x0index1762, std::array<u64,6>{v_c36, v_c14, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex1763, std::array<u64,4>{v_c14, v_c35, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letrecindex1764, std::array<u64,4>{v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex1765, std::array<u64,4>{v_c14, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1766, std::array<u64,4>{v_c37, v_c14, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex1767, std::array<u64,2>{v_c40, 0})) return;
          slog::join_probe_old<8,4>($sup70016x95x0x0x1index1768, $sup70016x95x0x0x1delta1780, std::array<u64,8>{v_c36, v_c37, v_c14, v_c35, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1844) {
            u64 v_c34 = m1844[4]; u64 v_c5 = m1844[5]; u64 v_c13 = m1844[6]; u64 v_c38 = m1844[7];
            slog::join_probe_old<6,6>($sup70016x95x0x0x0index1769, $sup70016x95x0x0x0delta1781, std::array<u64,6>{v_c34, v_c13, v_c14, v_c5, v_c36, v_c38}, [&](const std::array<u64,6>& m1845) {
              slog::join_probe_old<4,4>(mp_putindex1770, mp_putdelta1782, std::array<u64,4>{v_c35, v_c38, v_c13, v_c14}, [&](const std::array<u64,4>& m1846) {
                if (!slog::exists_probe<4,3>(evalindex1771, std::array<u64,4>{v_c13, v_c14, v_c34, 0})) return;
                if (!slog::exists_probe<4,3>(evalindex1772, std::array<u64,4>{v_c5, v_c37, v_c14, 0})) return;
                slog::join_probe_old<4,3>(letrecindex1773, letrecdelta1783, std::array<u64,4>{v_c38, v_c36, v_c5, 0}, [&](const std::array<u64,4>& m1847) {
                  u64 v_c39 = m1847[3];
                  slog::join_probe_old<4,4>(evalindex1774, evaldelta1784, std::array<u64,4>{v_c13, v_c14, v_c34, v_c39}, [&](const std::array<u64,4>& m1848) {
                    slog::join_probe_old<4,3>(evalindex1775, evaldelta1785, std::array<u64,4>{v_c5, v_c37, v_c14, 0}, [&](const std::array<u64,4>& m1849) {
                      u64 v_c41 = m1849[3];
                      if (!slog::exists_probe<2,1>(eval_ansindex1776, std::array<u64,2>{v_c41, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex1777, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m1850) {
                        u64 v_c42 = m1850[1];
                        slog::join_probe<2,1>(eval_ansindex1778, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m1851) {
                          u64 v_c19 = m1851[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask1786* _cont = new ReadTask1786(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1786(db,b), false);
}

