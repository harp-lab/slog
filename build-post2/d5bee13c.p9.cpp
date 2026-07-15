
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const0bbd2fbd1dc4200473343503;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_consta9707d158296ad63d61ac4f7;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c2780fa2b8ac15958(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan eval __t2z6s532 __t5a7h538 rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists $sup70016x51x0x0x1 (0 7 9 3 10 1 2 4 5 6 8 11 12) 3 __t2z6s532 rho t) (exists eval_args (3 2 0 1) 2 t rho) (exists tick (1 2 0) 2 __t5a7h538 t) (join $sup70016x51x0x0x0 (4 0 3 1 2) 3 t __t2z6s532 rho ef es) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (exists $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 5 ef es __t2z6s532 rho t) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t5qy8533) (exists eval_ans (0 1) 1 __t5qy8533) (join $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 6 ef es __t2z6s532 rho t __t5qy8533 __t2srV536 __t0CD9539 eb rhoc t2 vs xs) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval (3 1 0 2) 2 t2 eb) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask36 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** $sup70016x51x0x0x1index1;  slog::Index** eval_argsindex2;  slog::Index** tickindex3;  slog::Index** $sup70016x51x0x0x0index4;  slog::Index** appindex5;  slog::Index** $sup70016x51x0x0x1index6;  slog::Index** eval_argsindex7;  slog::Index** evalindex8;  slog::Index** eval_ansindex9;  slog::Index** $sup70016x51x0x0x1index10;  slog::Index** eval_argsindex11;  slog::Index** tickindex12;  slog::Index** eval_args_ansindex13;  slog::Index** tick_ansindex14;  slog::Index** lambdaindex15;  slog::Index** closureindex16;  slog::Index** evalindex17;  slog::Index** extend_envindex18;  slog::Index** eval_args_ansindex19;  slog::Index** tick_ansindex20;  slog::Index** extend_env_ansindex21;  slog::Index** lambdaindex22;  slog::Index** closureindex23;  slog::Index** eval_ansindex24;  slog::Index** evalindex25;  slog::Index** extend_env_ansindex26;  slog::Index** eval_ansindex27;  slog::Index** appdelta28;  slog::Index** evaldelta29;  slog::Index** eval_argsdelta30;  slog::Index** tickdelta31;  slog::Index** extend_envdelta32;  slog::Index** lambdadelta33;  slog::Index** closuredelta34;  slog::Index** evaldelta35;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("eval_ans");
      head_index[0] = readrel38->getIndex(ord37, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord39({2, 3, 0, 1});
      slog::Relation* readrel40 = db->getRelation("eval");
      evalindex0 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 7, 9, 3, 10, 1, 2, 4, 5, 6, 8, 11, 12});
      slog::Relation* readrel42 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({3, 2, 0, 1});
      slog::Relation* readrel44 = db->getRelation("eval_args");
      eval_argsindex2 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 0});
      slog::Relation* readrel46 = db->getRelation("tick");
      tickindex3 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({4, 0, 3, 1, 2});
      slog::Relation* readrel48 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index4 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1, 2});
      slog::Relation* readrel50 = db->getRelation("app");
      appindex5 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("app");
      appdelta28 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel54 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index6 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 3, 2, 0});
      slog::Relation* readrel56 = db->getRelation("eval_args");
      eval_argsindex7 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 3, 0});
      slog::Relation* readrel58 = db->getRelation("eval");
      evalindex8 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 3, 0});
      slog::Relation* readrel60 = db->getRelation("eval");
      evaldelta29 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("eval_ans");
      eval_ansindex9 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel64 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index10 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({3, 2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("eval_args");
      eval_argsindex11 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({3, 2, 0, 1});
      slog::Relation* readrel68 = db->getRelation("eval_args");
      eval_argsdelta30 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({0, 2, 1});
      slog::Relation* readrel70 = db->getRelation("tick");
      tickindex12 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 2, 1});
      slog::Relation* readrel72 = db->getRelation("tick");
      tickdelta31 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("eval_args_ans");
      eval_args_ansindex13 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("tick_ans");
      tick_ansindex14 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("lambda");
      lambdaindex15 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({2, 0, 1});
      slog::Relation* readrel80 = db->getRelation("closure");
      closureindex16 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({3, 1, 0, 2});
      slog::Relation* readrel82 = db->getRelation("eval");
      evalindex17 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 3, 0});
      slog::Relation* readrel84 = db->getRelation("extend_env");
      extend_envindex18 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 2, 3, 0});
      slog::Relation* readrel86 = db->getRelation("extend_env");
      extend_envdelta32 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("eval_args_ans");
      eval_args_ansindex19 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("tick_ans");
      tick_ansindex20 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("extend_env_ans");
      extend_env_ansindex21 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 2, 0});
      slog::Relation* readrel94 = db->getRelation("lambda");
      lambdaindex22 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 2, 0});
      slog::Relation* readrel96 = db->getRelation("lambda");
      lambdadelta33 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({1, 2, 0});
      slog::Relation* readrel98 = db->getRelation("closure");
      closureindex23 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("closure");
      closuredelta34 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("eval_ans");
      eval_ansindex24 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({3, 1, 0, 2});
      slog::Relation* readrel104 = db->getRelation("eval");
      evalindex25 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({3, 1, 0, 2});
      slog::Relation* readrel106 = db->getRelation("eval");
      evaldelta35 = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("extend_env_ans");
      extend_env_ansindex26 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("eval_ans");
      eval_ansindex27 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask36(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex0, std::array<u64,4>{v_c2, v_c3, 0, 0})) return;
        if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index1, std::array<u64,13>{v_c0, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex2, std::array<u64,4>{v_c3, v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,2>(tickindex3, std::array<u64,3>{v_c1, v_c3, 0})) return;
        slog::join_probe<5,3>($sup70016x51x0x0x0index4, std::array<u64,5>{v_c3, v_c0, v_c2, 0, 0}, [&](const std::array<u64,5>& m111) {
          u64 v_c4 = m111[3]; u64 v_c5 = m111[4];
          slog::join_probe_old<3,3>(appindex5, appdelta28, std::array<u64,3>{v_c1, v_c4, v_c5}, [&](const std::array<u64,3>& m112) {
            if (!slog::exists_probe<13,5>($sup70016x51x0x0x1index6, std::array<u64,13>{v_c4, v_c5, v_c0, v_c2, v_c3, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<4,3>(eval_argsindex7, std::array<u64,4>{v_c5, v_c3, v_c2, 0})) return;
            slog::join_probe_old<4,3>(evalindex8, evaldelta29, std::array<u64,4>{v_c4, v_c2, v_c3, 0}, [&](const std::array<u64,4>& m113) {
              u64 v_c6 = m113[3];
              if (!slog::exists_probe<2,1>(eval_ansindex9, std::array<u64,2>{v_c6, 0})) return;
              slog::join_probe<13,6>($sup70016x51x0x0x1index10, std::array<u64,13>{v_c4, v_c5, v_c0, v_c2, v_c3, v_c6, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m114) {
                u64 v_c7 = m114[6]; u64 v_c8 = m114[7]; u64 v_c9 = m114[8]; u64 v_c10 = m114[9]; u64 v_c11 = m114[10]; u64 v_c12 = m114[11]; u64 v_c13 = m114[12];
                slog::join_probe_old<4,4>(eval_argsindex11, eval_argsdelta30, std::array<u64,4>{v_c3, v_c2, v_c7, v_c5}, [&](const std::array<u64,4>& m115) {
                  slog::join_probe_old<3,3>(tickindex12, tickdelta31, std::array<u64,3>{v_c8, v_c3, v_c1}, [&](const std::array<u64,3>& m116) {
                    if (!slog::exists_probe<2,2>(eval_args_ansindex13, std::array<u64,2>{v_c7, v_c12})) return;
                    if (!slog::exists_probe<2,2>(tick_ansindex14, std::array<u64,2>{v_c8, v_c11})) return;
                    if (!slog::exists_probe<3,2>(lambdaindex15, std::array<u64,3>{v_c13, v_c9, 0})) return;
                    if (!slog::exists_probe<3,1>(closureindex16, std::array<u64,3>{v_c10, 0, 0})) return;
                    if (!slog::exists_probe<4,2>(evalindex17, std::array<u64,4>{v_c11, v_c9, 0, 0})) return;
                    slog::join_probe_old<4,3>(extend_envindex18, extend_envdelta32, std::array<u64,4>{v_c10, v_c13, v_c11, 0}, [&](const std::array<u64,4>& m117) {
                      u64 v_c14 = m117[3];
                      slog::join_probe<2,2>(eval_args_ansindex19, std::array<u64,2>{v_c7, v_c12}, [&](const std::array<u64,2>& m118) {
                        slog::join_probe<2,2>(tick_ansindex20, std::array<u64,2>{v_c8, v_c11}, [&](const std::array<u64,2>& m119) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex21, std::array<u64,2>{v_c14, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex22, lambdadelta33, std::array<u64,3>{v_c13, v_c9, 0}, [&](const std::array<u64,3>& m120) {
                            u64 v_c15 = m120[2];
                            slog::join_probe_old<3,2>(closureindex23, closuredelta34, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m121) {
                              u64 v_c16 = m121[2];
                              slog::join_probe<2,2>(eval_ansindex24, std::array<u64,2>{v_c6, v_c16}, [&](const std::array<u64,2>& m122) {
                                slog::join_probe_old<4,2>(evalindex25, evaldelta35, std::array<u64,4>{v_c11, v_c9, 0, 0}, [&](const std::array<u64,4>& m123) {
                                  u64 v_c17 = m123[2]; u64 v_c18 = m123[3];
                                  slog::join_probe<2,2>(extend_env_ansindex26, std::array<u64,2>{v_c14, v_c18}, [&](const std::array<u64,2>& m124) {
                                    slog::join_probe<2,1>(eval_ansindex27, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m125) {
                                      u64 v_c19 = m125[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask36* _cont = new ReadTask36(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask36(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mp_union __t0kfV144 __t5mfE148 __t2NO6142) (body (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 1 __t0kfV144) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 1 __t0kfV144) (join-old mp_union (1 2 0) 1 (1 2 0) __t5mfE148 u __t221b149) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t0kfV144 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t0kfV144 u) (exists mp_union_ans (0 1) 1 __t221b149) (join mbranch (3 0 1 2 4) 2 u __t2NO6142 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t0kfV144) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0kfV144 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t5mfE148) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t0kfV144 l m p r __t7PVf147) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask147 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index126;  slog::Index** $sup5638x104x0x0x1index127;  slog::Index** mp_unionindex128;  slog::Index** $sup5638x104x0x0x0index129;  slog::Index** $sup5638x104x0x0x1index130;  slog::Index** mp_union_ansindex131;  slog::Index** mbranchindex132;  slog::Index** $sup5638x104x0x0x1index133;  slog::Index** mp_mskindex134;  slog::Index** mp_msk_ansindex135;  slog::Index** $sup5638x104x0x0x0index136;  slog::Index** mbranchindex137;  slog::Index** mp_mskindex138;  slog::Index** $sup5638x104x0x0x1index139;  slog::Index** mbranchindex140;  slog::Index** mp_mskindex141;  slog::Index** mp_msk_ansindex142;  slog::Index** mp_union_ansindex143;  slog::Index** mp_uniondelta144;  slog::Index** mbranchdelta145;  slog::Index** mp_mskdelta146;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord148({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel149 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index126 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel151 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index127 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 2, 0});
      slog::Relation* readrel153 = db->getRelation("mp_union");
      mp_unionindex128 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 0});
      slog::Relation* readrel155 = db->getRelation("mp_union");
      mp_uniondelta144 = readrel155->getIndex(ord154, true);
      std::vector<u16> ord156({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel157 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index129 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel159 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index130 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("mp_union_ans");
      mp_union_ansindex131 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({3, 0, 1, 2, 4});
      slog::Relation* readrel163 = db->getRelation("mbranch");
      mbranchindex132 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel165 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index133 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({2, 0, 1});
      slog::Relation* readrel167 = db->getRelation("mp_msk");
      mp_mskindex134 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 0});
      slog::Relation* readrel169 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex135 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel171 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index136 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 3, 4, 0});
      slog::Relation* readrel173 = db->getRelation("mbranch");
      mbranchindex137 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 0});
      slog::Relation* readrel175 = db->getRelation("mp_msk");
      mp_mskindex138 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel177 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index139 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 3, 4, 0});
      slog::Relation* readrel179 = db->getRelation("mbranch");
      mbranchindex140 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 3, 4, 0});
      slog::Relation* readrel181 = db->getRelation("mbranch");
      mbranchdelta145 = readrel181->getIndex(ord180, true);
      std::vector<u16> ord182({1, 2, 0});
      slog::Relation* readrel183 = db->getRelation("mp_msk");
      mp_mskindex141 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("mp_msk");
      mp_mskdelta146 = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex142 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("mp_union_ans");
      mp_union_ansindex143 = readrel189->getIndex(ord188, false);
  
    }
    ReadTask147(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index126, std::array<u64,9>{v_c21, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index127, std::array<u64,10>{v_c21, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex128, mp_uniondelta144, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m190) {
          u64 v_c24 = m190[1]; u64 v_c25 = m190[2];
          if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index129, std::array<u64,9>{v_c21, v_c24, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index130, std::array<u64,10>{v_c21, v_c24, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex131, std::array<u64,2>{v_c25, 0})) return;
          slog::join_probe<5,2>(mbranchindex132, std::array<u64,5>{v_c24, v_c23, 0, 0, 0}, [&](const std::array<u64,5>& m191) {
            u64 v_c26 = m191[2]; u64 v_c27 = m191[3]; u64 v_c19 = m191[4];
            if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index133, std::array<u64,10>{v_c24, v_c27, v_c26, v_c19, v_c21, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex134, std::array<u64,3>{v_c27, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex135, std::array<u64,2>{v_c26, 0})) return;
            slog::join_probe<9,5>($sup5638x104x0x0x0index136, std::array<u64,9>{v_c26, v_c27, v_c24, v_c19, v_c21, 0, 0, 0, 0}, [&](const std::array<u64,9>& m192) {
              u64 v_c28 = m192[5]; u64 v_c29 = m192[6]; u64 v_c30 = m192[7]; u64 v_c31 = m192[8];
              u64 v_c32 = _prim_lt(db, v_c29, v_c27);
              if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
              if (!v_c32) return;
              if (!slog::exists_probe<5,5>(mbranchindex137, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, v_c22})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex138, std::array<u64,3>{v_c30, v_c27, 0})) return;
              slog::join_probe<10,9>($sup5638x104x0x0x1index139, std::array<u64,10>{v_c24, v_c27, v_c26, v_c19, v_c21, v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,10>& m194) {
                u64 v_c33 = m194[9];
                slog::join_probe_old<5,5>(mbranchindex140, mbranchdelta145, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, v_c22}, [&](const std::array<u64,5>& m195) {
                  slog::join_probe_old<3,3>(mp_mskindex141, mp_mskdelta146, std::array<u64,3>{v_c30, v_c27, v_c33}, [&](const std::array<u64,3>& m196) {
                    slog::join_probe<2,2>(mp_msk_ansindex142, std::array<u64,2>{v_c33, v_c26}, [&](const std::array<u64,2>& m197) {
                      slog::join_probe<2,1>(mp_union_ansindex143, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m198) {
                        u64 v_c18 = m198[1];
                        u64 v_c34 = _prim_band(db, v_c30, v_c27);
                        if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c35 = _prim_lt(db, v_c34, v_c20);
                        if (v_c35 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c35) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c21, v_c18, v_c27, v_c26, v_c19});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c26, v_c27, v_c18, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask147* _cont = new ReadTask147(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask147(db,b), false);
  // (crule (pre) (scan $sup5638x104x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 q) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t7tLj279) (join-old mp_msk_ans (0 1) 2 (0 1) __t7tLj279 q)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t7tLj279 l m n p q r v)) map.slog:105 #f)
  class ReadTask205 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex200;  slog::Index** mp_mskindex201;  slog::Index** mp_msk_ansindex202;  slog::Index** mp_mskdelta203;  slog::Index** mp_msk_ansdelta204;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord206({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel207 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel207->getIndex(ord206, false);
      outer_rel = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex200 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 0});
      slog::Relation* readrel211 = db->getRelation("mp_msk");
      mp_mskindex201 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("mp_msk");
      mp_mskdelta203 = readrel213->getIndex(ord212, true);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex202 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta204 = readrel217->getIndex(ord216, true);
  
    }
    ReadTask205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c26 = _t[5];
        u64 v_c31 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c19 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex200, std::array<u64,2>{v_c26, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex201, mp_mskdelta203, std::array<u64,3>{v_c30, v_c27, 0}, [&](const std::array<u64,3>& m218) {
          u64 v_c37 = m218[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex202, mp_msk_ansdelta204, std::array<u64,2>{v_c37, v_c26}, [&](const std::array<u64,2>& m219) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c36, v_c24, v_c37, v_c28, v_c29, v_c27, v_c30, v_c26, v_c31, v_c19}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5XjX1045 __t7ye2598 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo05pe1044 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0BYf1046 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9pUp1047 __t7ye2598 _00024seq2) (exists _enum (1 0) 1 __tconst8WcI1085) (join delta (1 2 0) 2 __tconst9cNI595 _00024seq2 __t0WVv596) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join symval (0 1) 1 __t7ye2598 s) (letp _00024sql2mO51039 (aslst _00024seq2)) (let chk9flA2021 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk9flA2021) (letp chk2W5k2022 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (eq __t7ye2598 chk2W5k2022) (letp chk7h6D2023 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk7h6D2023)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask229 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex220;  slog::Index** $seq_atrindex221;  slog::Index** $seq_atrindex222;  slog::Index** _enumindex223;  slog::Index** deltaindex224;  slog::Index** _enumindex225;  slog::Index** symvalindex226;  slog::Index** $seq_atrdelta227;  slog::Index** $seq_atrdelta228;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord230({1, 0, 2});
      slog::Relation* readrel231 = db->getRelation("$seq_at");
      driver_index = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({1, 0, 2});
      slog::Relation* readrel233 = db->getRelation("$seq_at");
      $seq_atindex220 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0, 2});
      slog::Relation* readrel235 = db->getRelation("$seq_atr");
      $seq_atrindex221 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0, 2});
      slog::Relation* readrel237 = db->getRelation("$seq_atr");
      $seq_atrdelta227 = readrel237->getIndex(ord236, true);
      std::vector<u16> ord238({1, 0, 2});
      slog::Relation* readrel239 = db->getRelation("$seq_atr");
      $seq_atrindex222 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 0, 2});
      slog::Relation* readrel241 = db->getRelation("$seq_atr");
      $seq_atrdelta228 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("_enum");
      _enumindex223 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("delta");
      deltaindex224 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 0});
      slog::Relation* readrel247 = db->getRelation("_enum");
      _enumindex225 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("symval");
      symvalindex226 = readrel249->getIndex(ord248, false);
  
    }
    ReadTask229(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c39 = v_const06abaa100ecef791ce028c56;
      u64 v_c40 = v_constd4735e3a265e16eee03f5971;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c44, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m250) {
        u64 v_c47 = m250[1];
        u64 v_c48 = m250[2];
        if (buckethash(v_c47) != bucket) return;
        slog::join_probe<3,3>($seq_atindex220, std::array<u64,3>{v_c43, v_c47, v_c48}, [&](const std::array<u64,3>& m251) {
          slog::join_probe_old<3,3>($seq_atrindex221, $seq_atrdelta227, std::array<u64,3>{v_c45, v_c47, v_c48}, [&](const std::array<u64,3>& m252) {
            slog::join_probe_old<3,3>($seq_atrindex222, $seq_atrdelta228, std::array<u64,3>{v_c46, v_c47, v_c48}, [&](const std::array<u64,3>& m253) {
              if (!slog::exists_probe<2,1>(_enumindex223, std::array<u64,2>{v_c38, 0})) return;
              slog::join_probe<3,2>(deltaindex224, std::array<u64,3>{v_c39, v_c48, 0}, [&](const std::array<u64,3>& m254) {
                u64 v_c49 = m254[2];
                slog::join_probe<2,1>(_enumindex225, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m255) {
                  u64 v_c50 = m255[1];
                  slog::join_probe<2,1>(symvalindex226, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m256) {
                    u64 v_c51 = m256[1];
                    bool ok257 = true;
                    u64 v_c52 = _prim_aslst(db, v_c48, &ok257);
                    if (!ok257) return;
                    u64 v_c53 = _prim_llen(db, v_c52);
                    if (v_c53 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c40 != v_c53) return;
                    bool ok258 = true;
                    u64 v_c54 = _prim_lref(db, v_c52, v_c41, &ok258);
                    if (!ok258) return;
                    if (v_c47 != v_c54) return;
                    bool ok259 = true;
                    u64 v_c55 = _prim_lref(db, v_c52, v_c42, &ok259);
                    if (!ok259) return;
                    if (v_c47 != v_c55) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c49});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c50}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask229* _cont = new ReadTask229(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask229(db,b), false);
  // (crule (pre (let __trid6DUz1244 const8c6798fa821ed573f6b89759) (let __trel85wC1245 const4a59dbb9cb3129dfcc75170b) (let __tcol5KOf1246 const5feceb66ffc86f38d952786c)) (scan $sup70016x51x0x0x1 __d0 __d1 __d2 __d4 eb ef es rho rhoc t t2 vs xs) (body (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t753P32) (join-old extend_env_ans (0 1) 1 (0 1) __t753P32 __v0)) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid6DUz1244 __trel85wC1245 __tcol5KOf1246 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __3Qtr1243 eb __v0 t2)) interp.slog:52 #f)
  class ReadTask274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex260;  slog::Index** extend_env_ansindex261;  slog::Index** extend_envdelta262;  slog::Index** extend_env_ansdelta263;
    u32 sid264;  u32 sid265;  u32 sid266;  u32 sid267;  u32 sid268;  u32 sid269;  u32 sid270;  u32 sid271;  u32 sid272;  u32 sid273;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord275({1, 2, 3, 0});
      slog::Relation* readrel276 = db->getRelation("extend_env");
      extend_envindex260 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 3, 0});
      slog::Relation* readrel278 = db->getRelation("extend_env");
      extend_envdelta262 = readrel278->getIndex(ord277, true);
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("extend_env_ans");
      extend_env_ansindex261 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({0, 1});
      slog::Relation* readrel282 = db->getRelation("extend_env_ans");
      extend_env_ansdelta263 = readrel282->getIndex(ord281, true);
      sid264 = db->getRelation("app")->getStructId();
      sid265 = db->getRelation("boolean")->getStructId();
      sid266 = db->getRelation("if")->getStructId();
      sid267 = db->getRelation("lambda")->getStructId();
      sid268 = db->getRelation("let")->getStructId();
      sid269 = db->getRelation("letrec")->getStructId();
      sid270 = db->getRelation("num")->getStructId();
      sid271 = db->getRelation("primref")->getStructId();
      sid272 = db->getRelation("ref")->getStructId();
      sid273 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const8c6798fa821ed573f6b89759;
      u64 v_c57 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c59 = _t[1];
        u64 v_c60 = _t[2];
        u64 v_c61 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c4 = _t[5];
        u64 v_c5 = _t[6];
        u64 v_c2 = _t[7];
        u64 v_c10 = _t[8];
        u64 v_c3 = _t[9];
        u64 v_c11 = _t[10];
        u64 v_c12 = _t[11];
        u64 v_c13 = _t[12];
        slog::join_probe_old<4,3>(extend_envindex260, extend_envdelta262, std::array<u64,4>{v_c10, v_c13, v_c11, 0}, [&](const std::array<u64,4>& m283) {
          u64 v_c62 = m283[3];
          slog::join_probe_old<2,1>(extend_env_ansindex261, extend_env_ansdelta263, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m284) {
            u64 v_c18 = m284[1];
            ++_fires;
            if (!((is_struct(v_c9) && (decode_struct_id(v_c9) == sid264 || decode_struct_id(v_c9) == sid265 || decode_struct_id(v_c9) == sid266 || decode_struct_id(v_c9) == sid267 || decode_struct_id(v_c9) == sid268 || decode_struct_id(v_c9) == sid269 || decode_struct_id(v_c9) == sid270 || decode_struct_id(v_c9) == sid271 || decode_struct_id(v_c9) == sid272 || decode_struct_id(v_c9) == sid273))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c56, v_c57, v_c58, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c9, v_c18, v_c11}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x1", _fires);
  
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
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join mp_hsb_ans (0 1) 0 __t15yE714 __v3) (join mp_hsb_ans (0 1) 1 __t15yE714 __v1) (let __t4JMu715 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t15yE714 __t4JMu715)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t15yE714 __t15yE714 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask289 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex285;  slog::Index** mp_hsb_ansindex286;  slog::Index** mp_hsbindex287;  slog::Index** mp_hsbdelta288;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord290({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel291 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel291->getIndex(ord290, false);
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord292({0, 1});
      slog::Relation* readrel293 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex285 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({0, 1});
      slog::Relation* readrel295 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex286 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("mp_hsb");
      mp_hsbindex287 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("mp_hsb");
      mp_hsbdelta288 = readrel299->getIndex(ord298, true);
  
    }
    ReadTask289(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c59 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c63 = _t[3];
        u64 v_c64 = _t[4];
        u64 v_c65 = _t[5];
        u64 v_c66 = _t[6];
        slog::join_all<2>(mp_hsb_ansindex285, [&](const std::array<u64,2>& m300) {
          u64 v_c67 = m300[0]; u64 v_c68 = m300[1];
          slog::join_probe<2,1>(mp_hsb_ansindex286, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m301) {
            u64 v_c69 = m301[1];
            u64 v_c70 = _prim_bxor(db, v_c63, v_c64);
            if (v_c70 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            slog::join_probe_old<2,2>(mp_hsbindex287, mp_hsbdelta288, std::array<u64,2>{v_c67, v_c70}, [&](const std::array<u64,2>& m302) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c59, v_c18, v_c68, v_c69, v_c36, v_c67, v_c67, v_c63, v_c64, v_c65, v_c66}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask289* _cont = new ReadTask289(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask289(db,b), false);
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan extend_env __t2ugT17 rho _00024seq0 t) (body (letp _00024sql00Zd837 (aslst _00024seq0)) (letp x (lref _00024sql00Zd837 _00024sqc4H0B840)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let xs (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (join $sup70016x47x0x0x0 (2 3 4 5 0 1) 6 rho t x xs _00024seq0 __t2ugT17) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo31L8847 x _00024seq0) (exists extend_env (2 3 0 1) 2 xs t) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t42Fa18) (exists mp_put_ans (0 1) 1 __t42Fa18) (join-old extend_env (2 3 0 1) 2 (2 3 0 1) xs t __t8zl419 __v0) (join mp_put_ans (0 1) 2 __t42Fa18 __v0) (join extend_env_ans (0 1) 1 __t8zl419 __v1)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x47x0x0x0index303;  slog::Index** $seq_atindex304;  slog::Index** extend_envindex305;  slog::Index** mp_putindex306;  slog::Index** mp_put_ansindex307;  slog::Index** extend_envindex308;  slog::Index** mp_put_ansindex309;  slog::Index** extend_env_ansindex310;  slog::Index** $seq_atdelta311;  slog::Index** mp_putdelta312;  slog::Index** extend_envdelta313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord315({0, 1});
      slog::Relation* readrel316 = db->getRelation("extend_env_ans");
      head_index[0] = readrel316->getIndex(ord315, false);
      outer_rel = db->getRelation("extend_env");
      std::vector<u16> ord317({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel318 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index303 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0, 2});
      slog::Relation* readrel320 = db->getRelation("$seq_at");
      $seq_atindex304 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 0, 2});
      slog::Relation* readrel322 = db->getRelation("$seq_at");
      $seq_atdelta311 = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({2, 3, 0, 1});
      slog::Relation* readrel324 = db->getRelation("extend_env");
      extend_envindex305 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 3, 0});
      slog::Relation* readrel326 = db->getRelation("mp_put");
      mp_putindex306 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 3, 0});
      slog::Relation* readrel328 = db->getRelation("mp_put");
      mp_putdelta312 = readrel328->getIndex(ord327, true);
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("mp_put_ans");
      mp_put_ansindex307 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({2, 3, 0, 1});
      slog::Relation* readrel332 = db->getRelation("extend_env");
      extend_envindex308 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({2, 3, 0, 1});
      slog::Relation* readrel334 = db->getRelation("extend_env");
      extend_envdelta313 = readrel334->getIndex(ord333, true);
      std::vector<u16> ord335({0, 1});
      slog::Relation* readrel336 = db->getRelation("mp_put_ans");
      mp_put_ansindex309 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({0, 1});
      slog::Relation* readrel338 = db->getRelation("extend_env_ans");
      extend_env_ansindex310 = readrel338->getIndex(ord337, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
      u64 v_c73 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c74 = v_const5feceb66ffc86f38d952786c;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c77 = _t[2];
        u64 v_c3 = _t[3];
        bool ok339 = true;
        u64 v_c78 = _prim_aslst(db, v_c77, &ok339);
        if (!ok339) return;
        bool ok340 = true;
        u64 v_c79 = _prim_lref(db, v_c78, v_c72, &ok340);
        if (!ok340) return;
        u64 v_c80 = _prim_llen(db, v_c78);
        if (v_c80 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c81 = _prim_ge(db, v_c80, v_c71);
        if (v_c81 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        if (!v_c81) return;
        u64 v_c82 = _prim__0002d(db, v_c80, v_c74);
        if (v_c82 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c13 = _prim_lslice(db, v_c78, v_c73, v_c82);
        if (v_c13 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        slog::join_probe<6,6>($sup70016x47x0x0x0index303, std::array<u64,6>{v_c2, v_c3, v_c79, v_c13, v_c77, v_c76}, [&](const std::array<u64,6>& m342) {
          slog::join_probe_old<3,3>($seq_atindex304, $seq_atdelta311, std::array<u64,3>{v_c75, v_c79, v_c77}, [&](const std::array<u64,3>& m343) {
            if (!slog::exists_probe<4,2>(extend_envindex305, std::array<u64,4>{v_c13, v_c3, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex306, mp_putdelta312, std::array<u64,4>{v_c2, v_c79, v_c3, 0}, [&](const std::array<u64,4>& m344) {
              u64 v_c83 = m344[3];
              if (!slog::exists_probe<2,1>(mp_put_ansindex307, std::array<u64,2>{v_c83, 0})) return;
              slog::join_probe_old<4,2>(extend_envindex308, extend_envdelta313, std::array<u64,4>{v_c13, v_c3, 0, 0}, [&](const std::array<u64,4>& m345) {
                u64 v_c84 = m345[2]; u64 v_c18 = m345[3];
                slog::join_probe<2,2>(mp_put_ansindex309, std::array<u64,2>{v_c83, v_c18}, [&](const std::array<u64,2>& m346) {
                  slog::join_probe<2,1>(extend_env_ansindex310, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m347) {
                    u64 v_c69 = m347[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c76, v_c69}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c) (let __tconst0SLc45 const06abaa100ecef791ce028c56)) (scan temp2vYa1984 __t32mX89 __t66zQ63 __t8XJL92 __t8ZUv44 __t8z2o72 __t9CBr54 __t9rwO81) (body (exists primref (1 0) 1 __tconst0SLc45) (exists app (2 0 1) 1 __t8ZUv44) (join lambda (1 2 0) 2 __t8XJL92 __t32mX89 __t39ek93) (join primref (1 0) 1 __tconst0SLc45 __t0d6446) (join app (1 2 0) 2 __t0d6446 __t8ZUv44 __t3YaY47)) (head (emit-temp temp0Ab21985 __t39ek93 __t3YaY47 __t66zQ63 __t8z2o72 __t9CBr54 __t9rwO81) (mkstruct let (1 2 3 0) __t6Peh56 __tconst2JmK55 __t9CBr54 __t3YaY47)) kcfa.slog:16 #f)
  class ReadTask353 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primrefindex348;  slog::Index** appindex349;  slog::Index** lambdaindex350;  slog::Index** primrefindex351;  slog::Index** appindex352;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Ab21985");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp2vYa1984");
      std::vector<u16> ord354({1, 0});
      slog::Relation* readrel355 = db->getRelation("primref");
      primrefindex348 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({2, 0, 1});
      slog::Relation* readrel357 = db->getRelation("app");
      appindex349 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("lambda");
      lambdaindex350 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 0});
      slog::Relation* readrel361 = db->getRelation("primref");
      primrefindex351 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 2, 0});
      slog::Relation* readrel363 = db->getRelation("app");
      appindex352 = readrel363->getIndex(ord362, false);
  
    }
    ReadTask353(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c85 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c86 = v_constef2d127de37b942baad06145;
      u64 v_c87 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c88 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
      u64 v_c90 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c91 = _t[0];
        u64 v_c92 = _t[1];
        u64 v_c93 = _t[2];
        u64 v_c94 = _t[3];
        u64 v_c95 = _t[4];
        u64 v_c96 = _t[5];
        u64 v_c97 = _t[6];
        if (!slog::exists_probe<2,1>(primrefindex348, std::array<u64,2>{v_c90, 0})) return;
        if (!slog::exists_probe<3,1>(appindex349, std::array<u64,3>{v_c94, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex350, std::array<u64,3>{v_c93, v_c91, 0}, [&](const std::array<u64,3>& m364) {
          u64 v_c98 = m364[2];
          slog::join_probe<2,1>(primrefindex351, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m365) {
            u64 v_c99 = m365[1];
            slog::join_probe<3,2>(appindex352, std::array<u64,3>{v_c99, v_c94, 0}, [&](const std::array<u64,3>& m366) {
              u64 v_c100 = m366[2];
              ++_fires;
              slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c98, v_c100, v_c92, v_c95, v_c96, v_c97});
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c85, v_c96, v_c100}, std::array<u16,4>{1, 2, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp2vYa1984", _fires);
  
      if (!_done)
      {
        ReadTask353* _cont = new ReadTask353(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask353(db,b), false);
  // (crule (pre) (scan eval_args_ans __t192L615 vs) (body (join-old eval_args (0 1 2 3) 1 (0 1 2 3) __t192L615 es rho t) (exists app (2 0 1) 1 es) (exists eval (2 3 0 1) 2 rho t) (exists tick (2 0 1) 1 t) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (2 0 1) 2 (2 0 1) es __t3MQm616 ef) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t7lOb612) (exists eval_ans (0 1) 1 __t7lOb612) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join-old tick_ans (0 1) 1 (0 1) __t2n7W617 t2) (join-old closure (0 1 2) 1 (0 1 2) __t6tRF614 __t20Nd613 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask389 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex367;  slog::Index** appindex368;  slog::Index** evalindex369;  slog::Index** tickindex370;  slog::Index** evalindex371;  slog::Index** tickindex372;  slog::Index** appindex373;  slog::Index** evalindex374;  slog::Index** eval_ansindex375;  slog::Index** tickindex376;  slog::Index** tick_ansindex377;  slog::Index** eval_ansindex378;  slog::Index** tick_ansindex379;  slog::Index** closureindex380;  slog::Index** lambdaindex381;  slog::Index** eval_argsdelta382;  slog::Index** appdelta383;  slog::Index** evaldelta384;  slog::Index** tickdelta385;  slog::Index** tick_ansdelta386;  slog::Index** closuredelta387;  slog::Index** lambdadelta388;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord390({0, 1, 2, 3});
      slog::Relation* readrel391 = db->getRelation("bind_store");
      head_index[0] = readrel391->getIndex(ord390, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("call_event");
      head_index[1] = readrel393->getIndex(ord392, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord394({0, 1, 2, 3});
      slog::Relation* readrel395 = db->getRelation("eval_args");
      eval_argsindex367 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2, 3});
      slog::Relation* readrel397 = db->getRelation("eval_args");
      eval_argsdelta382 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({2, 0, 1});
      slog::Relation* readrel399 = db->getRelation("app");
      appindex368 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({2, 3, 0, 1});
      slog::Relation* readrel401 = db->getRelation("eval");
      evalindex369 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({2, 0, 1});
      slog::Relation* readrel403 = db->getRelation("tick");
      tickindex370 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({2, 3, 0, 1});
      slog::Relation* readrel405 = db->getRelation("eval");
      evalindex371 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("tick");
      tickindex372 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({2, 0, 1});
      slog::Relation* readrel409 = db->getRelation("app");
      appindex373 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({2, 0, 1});
      slog::Relation* readrel411 = db->getRelation("app");
      appdelta383 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({1, 2, 3, 0});
      slog::Relation* readrel413 = db->getRelation("eval");
      evalindex374 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 3, 0});
      slog::Relation* readrel415 = db->getRelation("eval");
      evaldelta384 = readrel415->getIndex(ord414, true);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("eval_ans");
      eval_ansindex375 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("tick");
      tickindex376 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("tick");
      tickdelta385 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("tick_ans");
      tick_ansindex377 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("eval_ans");
      eval_ansindex378 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("tick_ans");
      tick_ansindex379 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("tick_ans");
      tick_ansdelta386 = readrel429->getIndex(ord428, true);
      std::vector<u16> ord430({0, 1, 2});
      slog::Relation* readrel431 = db->getRelation("closure");
      closureindex380 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 1, 2});
      slog::Relation* readrel433 = db->getRelation("closure");
      closuredelta387 = readrel433->getIndex(ord432, true);
      std::vector<u16> ord434({0, 1, 2});
      slog::Relation* readrel435 = db->getRelation("lambda");
      lambdaindex381 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1, 2});
      slog::Relation* readrel437 = db->getRelation("lambda");
      lambdadelta388 = readrel437->getIndex(ord436, true);
  
    }
    ReadTask389(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe_old<4,1>(eval_argsindex367, eval_argsdelta382, std::array<u64,4>{v_c101, 0, 0, 0}, [&](const std::array<u64,4>& m438) {
          u64 v_c5 = m438[1]; u64 v_c2 = m438[2]; u64 v_c3 = m438[3];
          if (!slog::exists_probe<3,1>(appindex368, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex369, std::array<u64,4>{v_c2, v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex370, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>(evalindex371, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m439) {
            u64 v_c102 = m439[2]; u64 v_c103 = m439[3];
            if (!slog::exists_probe<3,2>(tickindex372, std::array<u64,3>{v_c103, v_c3, 0})) return;
            slog::join_probe_old<3,2>(appindex373, appdelta383, std::array<u64,3>{v_c5, v_c103, 0}, [&](const std::array<u64,3>& m440) {
              u64 v_c4 = m440[2];
              slog::join_probe_old<4,3>(evalindex374, evaldelta384, std::array<u64,4>{v_c4, v_c2, v_c3, 0}, [&](const std::array<u64,4>& m441) {
                u64 v_c104 = m441[3];
                if (!slog::exists_probe<2,1>(eval_ansindex375, std::array<u64,2>{v_c104, 0})) return;
                slog::join_probe_old<3,2>(tickindex376, tickdelta385, std::array<u64,3>{v_c103, v_c3, 0}, [&](const std::array<u64,3>& m442) {
                  u64 v_c105 = m442[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex377, std::array<u64,2>{v_c105, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex378, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m443) {
                    u64 v_c106 = m443[1];
                    slog::join_probe_old<2,1>(tick_ansindex379, tick_ansdelta386, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m444) {
                      u64 v_c11 = m444[1];
                      slog::join_probe_old<3,1>(closureindex380, closuredelta387, std::array<u64,3>{v_c106, 0, 0}, [&](const std::array<u64,3>& m445) {
                        u64 v_c107 = m445[1]; u64 v_c10 = m445[2];
                        slog::join_probe_old<3,1>(lambdaindex381, lambdadelta388, std::array<u64,3>{v_c107, 0, 0}, [&](const std::array<u64,3>& m446) {
                          u64 v_c13 = m446[1]; u64 v_c9 = m446[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c13, v_c12, v_c11, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c11, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask389* _cont = new ReadTask389(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask389(db,b), false);
  // (crule (pre) (scan tick_ans __t0CD9539 t2) (body (exists $sup70016x51x0x0x1 (3 10 4 0 1 2 5 6 7 8 9 11 12) 2 __t0CD9539 t2) (exists extend_env (3 0 1 2) 1 t2) (exists eval (3 1 0 2) 1 t2) (join-old tick (0 2 1) 1 (0 2 1) __t0CD9539 t __t5a7h538) (exists $sup70016x51x0x0x0 (4 0 3 1 2) 1 t) (exists $sup70016x51x0x0x1 (3 9 10 0 1 2 4 5 6 7 8 11 12) 3 __t0CD9539 t t2) (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (join-old eval (3 1 0 2) 2 (3 1 0 2) t __t5a7h538 __t2z6s532 rho) (exists $sup70016x51x0x0x1 (0 7 9 3 10 1 2 4 5 6 8 11 12) 5 __t2z6s532 rho t __t0CD9539 t2) (exists eval (2 3 0 1) 2 rho t) (exists eval_args (3 2 0 1) 2 t rho) (join-old $sup70016x51x0x0x0 (4 0 3 1 2) 3 (4 0 3 1 2) t __t2z6s532 rho ef es) (exists eval (1 2 3 0) 3 ef rho t) (exists eval_args (1 3 2 0) 3 es t rho) (exists app (0 1 2) 3 __t5a7h538 ef es) (join-old $sup70016x51x0x0x1 (0 3 5 6 7 9 10 1 2 4 8 11 12) 7 (0 3 5 6 7 9 10 1 2 4 8 11 12) __t2z6s532 __t0CD9539 ef es rho t t2 __t5qy8533 __t2srV536 eb rhoc vs xs) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join-old extend_env_ans (0 1) 2 (0 1) __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask493 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index447;  slog::Index** extend_envindex448;  slog::Index** evalindex449;  slog::Index** tickindex450;  slog::Index** $sup70016x51x0x0x0index451;  slog::Index** $sup70016x51x0x0x1index452;  slog::Index** evalindex453;  slog::Index** eval_argsindex454;  slog::Index** evalindex455;  slog::Index** $sup70016x51x0x0x1index456;  slog::Index** evalindex457;  slog::Index** eval_argsindex458;  slog::Index** $sup70016x51x0x0x0index459;  slog::Index** evalindex460;  slog::Index** eval_argsindex461;  slog::Index** appindex462;  slog::Index** $sup70016x51x0x0x1index463;  slog::Index** evalindex464;  slog::Index** eval_argsindex465;  slog::Index** appindex466;  slog::Index** eval_args_ansindex467;  slog::Index** lambdaindex468;  slog::Index** closureindex469;  slog::Index** eval_ansindex470;  slog::Index** evalindex471;  slog::Index** extend_envindex472;  slog::Index** eval_args_ansindex473;  slog::Index** extend_env_ansindex474;  slog::Index** lambdaindex475;  slog::Index** closureindex476;  slog::Index** eval_ansindex477;  slog::Index** evalindex478;  slog::Index** extend_env_ansindex479;  slog::Index** eval_ansindex480;  slog::Index** tickdelta481;  slog::Index** evaldelta482;  slog::Index** $sup70016x51x0x0x0delta483;  slog::Index** $sup70016x51x0x0x1delta484;  slog::Index** evaldelta485;  slog::Index** eval_argsdelta486;  slog::Index** appdelta487;  slog::Index** extend_envdelta488;  slog::Index** lambdadelta489;  slog::Index** closuredelta490;  slog::Index** evaldelta491;  slog::Index** extend_env_ansdelta492;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("eval_ans");
      head_index[0] = readrel495->getIndex(ord494, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord496({3, 10, 4, 0, 1, 2, 5, 6, 7, 8, 9, 11, 12});
      slog::Relation* readrel497 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index447 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({3, 0, 1, 2});
      slog::Relation* readrel499 = db->getRelation("extend_env");
      extend_envindex448 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({3, 1, 0, 2});
      slog::Relation* readrel501 = db->getRelation("eval");
      evalindex449 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 2, 1});
      slog::Relation* readrel503 = db->getRelation("tick");
      tickindex450 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 2, 1});
      slog::Relation* readrel505 = db->getRelation("tick");
      tickdelta481 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({4, 0, 3, 1, 2});
      slog::Relation* readrel507 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index451 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({3, 9, 10, 0, 1, 2, 4, 5, 6, 7, 8, 11, 12});
      slog::Relation* readrel509 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index452 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({3, 1, 0, 2});
      slog::Relation* readrel511 = db->getRelation("eval");
      evalindex453 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({3, 2, 0, 1});
      slog::Relation* readrel513 = db->getRelation("eval_args");
      eval_argsindex454 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({3, 1, 0, 2});
      slog::Relation* readrel515 = db->getRelation("eval");
      evalindex455 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({3, 1, 0, 2});
      slog::Relation* readrel517 = db->getRelation("eval");
      evaldelta482 = readrel517->getIndex(ord516, true);
      std::vector<u16> ord518({0, 7, 9, 3, 10, 1, 2, 4, 5, 6, 8, 11, 12});
      slog::Relation* readrel519 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index456 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({2, 3, 0, 1});
      slog::Relation* readrel521 = db->getRelation("eval");
      evalindex457 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({3, 2, 0, 1});
      slog::Relation* readrel523 = db->getRelation("eval_args");
      eval_argsindex458 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({4, 0, 3, 1, 2});
      slog::Relation* readrel525 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index459 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({4, 0, 3, 1, 2});
      slog::Relation* readrel527 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0delta483 = readrel527->getIndex(ord526, true);
      std::vector<u16> ord528({1, 2, 3, 0});
      slog::Relation* readrel529 = db->getRelation("eval");
      evalindex460 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 3, 2, 0});
      slog::Relation* readrel531 = db->getRelation("eval_args");
      eval_argsindex461 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({0, 1, 2});
      slog::Relation* readrel533 = db->getRelation("app");
      appindex462 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({0, 3, 5, 6, 7, 9, 10, 1, 2, 4, 8, 11, 12});
      slog::Relation* readrel535 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index463 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 3, 5, 6, 7, 9, 10, 1, 2, 4, 8, 11, 12});
      slog::Relation* readrel537 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta484 = readrel537->getIndex(ord536, true);
      std::vector<u16> ord538({2, 3, 0, 1});
      slog::Relation* readrel539 = db->getRelation("eval");
      evalindex464 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({2, 3, 0, 1});
      slog::Relation* readrel541 = db->getRelation("eval");
      evaldelta485 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({3, 2, 0, 1});
      slog::Relation* readrel543 = db->getRelation("eval_args");
      eval_argsindex465 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({3, 2, 0, 1});
      slog::Relation* readrel545 = db->getRelation("eval_args");
      eval_argsdelta486 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({0, 1, 2});
      slog::Relation* readrel547 = db->getRelation("app");
      appindex466 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({0, 1, 2});
      slog::Relation* readrel549 = db->getRelation("app");
      appdelta487 = readrel549->getIndex(ord548, true);
      std::vector<u16> ord550({0, 1});
      slog::Relation* readrel551 = db->getRelation("eval_args_ans");
      eval_args_ansindex467 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 0});
      slog::Relation* readrel553 = db->getRelation("lambda");
      lambdaindex468 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({2, 0, 1});
      slog::Relation* readrel555 = db->getRelation("closure");
      closureindex469 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({0, 1});
      slog::Relation* readrel557 = db->getRelation("eval_ans");
      eval_ansindex470 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({3, 1, 0, 2});
      slog::Relation* readrel559 = db->getRelation("eval");
      evalindex471 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 3, 0});
      slog::Relation* readrel561 = db->getRelation("extend_env");
      extend_envindex472 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 3, 0});
      slog::Relation* readrel563 = db->getRelation("extend_env");
      extend_envdelta488 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({0, 1});
      slog::Relation* readrel565 = db->getRelation("eval_args_ans");
      eval_args_ansindex473 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1});
      slog::Relation* readrel567 = db->getRelation("extend_env_ans");
      extend_env_ansindex474 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 2, 0});
      slog::Relation* readrel569 = db->getRelation("lambda");
      lambdaindex475 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("lambda");
      lambdadelta489 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("closure");
      closureindex476 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("closure");
      closuredelta490 = readrel575->getIndex(ord574, true);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("eval_ans");
      eval_ansindex477 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({3, 1, 0, 2});
      slog::Relation* readrel579 = db->getRelation("eval");
      evalindex478 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({3, 1, 0, 2});
      slog::Relation* readrel581 = db->getRelation("eval");
      evaldelta491 = readrel581->getIndex(ord580, true);
      std::vector<u16> ord582({0, 1});
      slog::Relation* readrel583 = db->getRelation("extend_env_ans");
      extend_env_ansindex479 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("extend_env_ans");
      extend_env_ansdelta492 = readrel585->getIndex(ord584, true);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("eval_ans");
      eval_ansindex480 = readrel587->getIndex(ord586, false);
  
    }
    ReadTask493(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[0];
        u64 v_c11 = _t[1];
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index447, std::array<u64,13>{v_c8, v_c11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(extend_envindex448, std::array<u64,4>{v_c11, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex449, std::array<u64,4>{v_c11, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(tickindex450, tickdelta481, std::array<u64,3>{v_c8, 0, 0}, [&](const std::array<u64,3>& m588) {
          u64 v_c3 = m588[1]; u64 v_c1 = m588[2];
          if (!slog::exists_probe<5,1>($sup70016x51x0x0x0index451, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index452, std::array<u64,13>{v_c8, v_c3, v_c11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex453, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(eval_argsindex454, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          slog::join_probe_old<4,2>(evalindex455, evaldelta482, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m589) {
            u64 v_c0 = m589[2]; u64 v_c2 = m589[3];
            if (!slog::exists_probe<13,5>($sup70016x51x0x0x1index456, std::array<u64,13>{v_c0, v_c2, v_c3, v_c8, v_c11, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<4,2>(evalindex457, std::array<u64,4>{v_c2, v_c3, 0, 0})) return;
            if (!slog::exists_probe<4,2>(eval_argsindex458, std::array<u64,4>{v_c3, v_c2, 0, 0})) return;
            slog::join_probe_old<5,3>($sup70016x51x0x0x0index459, $sup70016x51x0x0x0delta483, std::array<u64,5>{v_c3, v_c0, v_c2, 0, 0}, [&](const std::array<u64,5>& m590) {
              u64 v_c4 = m590[3]; u64 v_c5 = m590[4];
              if (!slog::exists_probe<4,3>(evalindex460, std::array<u64,4>{v_c4, v_c2, v_c3, 0})) return;
              if (!slog::exists_probe<4,3>(eval_argsindex461, std::array<u64,4>{v_c5, v_c3, v_c2, 0})) return;
              if (!slog::exists_probe<3,3>(appindex462, std::array<u64,3>{v_c1, v_c4, v_c5})) return;
              slog::join_probe_old<13,7>($sup70016x51x0x0x1index463, $sup70016x51x0x0x1delta484, std::array<u64,13>{v_c0, v_c8, v_c4, v_c5, v_c2, v_c3, v_c11, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m591) {
                u64 v_c6 = m591[7]; u64 v_c7 = m591[8]; u64 v_c9 = m591[9]; u64 v_c10 = m591[10]; u64 v_c12 = m591[11]; u64 v_c13 = m591[12];
                slog::join_probe_old<4,4>(evalindex464, evaldelta485, std::array<u64,4>{v_c2, v_c3, v_c6, v_c4}, [&](const std::array<u64,4>& m592) {
                  slog::join_probe_old<4,4>(eval_argsindex465, eval_argsdelta486, std::array<u64,4>{v_c3, v_c2, v_c7, v_c5}, [&](const std::array<u64,4>& m593) {
                    slog::join_probe_old<3,3>(appindex466, appdelta487, std::array<u64,3>{v_c1, v_c4, v_c5}, [&](const std::array<u64,3>& m594) {
                      if (!slog::exists_probe<2,2>(eval_args_ansindex467, std::array<u64,2>{v_c7, v_c12})) return;
                      if (!slog::exists_probe<3,2>(lambdaindex468, std::array<u64,3>{v_c13, v_c9, 0})) return;
                      if (!slog::exists_probe<3,1>(closureindex469, std::array<u64,3>{v_c10, 0, 0})) return;
                      if (!slog::exists_probe<2,1>(eval_ansindex470, std::array<u64,2>{v_c6, 0})) return;
                      if (!slog::exists_probe<4,2>(evalindex471, std::array<u64,4>{v_c11, v_c9, 0, 0})) return;
                      slog::join_probe_old<4,3>(extend_envindex472, extend_envdelta488, std::array<u64,4>{v_c10, v_c13, v_c11, 0}, [&](const std::array<u64,4>& m595) {
                        u64 v_c14 = m595[3];
                        slog::join_probe<2,2>(eval_args_ansindex473, std::array<u64,2>{v_c7, v_c12}, [&](const std::array<u64,2>& m596) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex474, std::array<u64,2>{v_c14, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex475, lambdadelta489, std::array<u64,3>{v_c13, v_c9, 0}, [&](const std::array<u64,3>& m597) {
                            u64 v_c15 = m597[2];
                            slog::join_probe_old<3,2>(closureindex476, closuredelta490, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m598) {
                              u64 v_c16 = m598[2];
                              slog::join_probe<2,2>(eval_ansindex477, std::array<u64,2>{v_c6, v_c16}, [&](const std::array<u64,2>& m599) {
                                slog::join_probe_old<4,2>(evalindex478, evaldelta491, std::array<u64,4>{v_c11, v_c9, 0, 0}, [&](const std::array<u64,4>& m600) {
                                  u64 v_c17 = m600[2]; u64 v_c18 = m600[3];
                                  slog::join_probe_old<2,2>(extend_env_ansindex479, extend_env_ansdelta492, std::array<u64,2>{v_c14, v_c18}, [&](const std::array<u64,2>& m601) {
                                    slog::join_probe<2,1>(eval_ansindex480, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m602) {
                                      u64 v_c19 = m602[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask493* _cont = new ReadTask493(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask493(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t7b5L282 (bxor p0 p1))) (head (emit-temp temp60fT1907 __t7b5L282)) map.slog:30 #f)
  class ReadTask603 : public slog::Task
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
      head_rel[0] = db->getRelation("temp60fT1907");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
  
    }
    ReadTask603(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c59 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c63 = _t[3];
        u64 v_c64 = _t[4];
        u64 v_c65 = _t[5];
        u64 v_c66 = _t[6];
        u64 v_c108 = _prim_bxor(db, v_c63, v_c64);
        if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c108});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask603* _cont = new ReadTask603(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask603(db,b), false);
  // (crule (pre) (scan eval_ans __t4Rxn650 __v2) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t4Rxn650 __v1 rho t) (exists $sup70016x87x0x0x0 (4 5 0 1 2 3) 2 rho t) (exists eval (2 3 0 1) 2 rho t) (exists select_branch_ans (1 0) 1 __v1) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t7kdB647 __t71xd646) (join-old $sup70016x87x0x0x0 (4 5 0 1 2 3) 3 (4 5 0 1 2 3) rho t __t7kdB647 e1 e2 e3) (join-old if (1 3 2 0) 4 (1 3 2 0) e1 e3 e2 __t71xd646) (exists select_branch (2 3 1 0) 2 e2 e3) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t2MYH648) (exists eval_ans (0 1) 1 __t2MYH648) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (join select_branch_ans (0 1) 2 __t1Vli649 __v1)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask623 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex604;  slog::Index** $sup70016x87x0x0x0index605;  slog::Index** evalindex606;  slog::Index** select_branch_ansindex607;  slog::Index** evalindex608;  slog::Index** $sup70016x87x0x0x0index609;  slog::Index** ifindex610;  slog::Index** select_branchindex611;  slog::Index** evalindex612;  slog::Index** eval_ansindex613;  slog::Index** select_branchindex614;  slog::Index** eval_ansindex615;  slog::Index** select_branch_ansindex616;  slog::Index** evaldelta617;  slog::Index** evaldelta618;  slog::Index** $sup70016x87x0x0x0delta619;  slog::Index** ifdelta620;  slog::Index** evaldelta621;  slog::Index** select_branchdelta622;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord624({0, 1});
      slog::Relation* readrel625 = db->getRelation("eval_ans");
      head_index[0] = readrel625->getIndex(ord624, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord626({0, 1, 2, 3});
      slog::Relation* readrel627 = db->getRelation("eval");
      evalindex604 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 1, 2, 3});
      slog::Relation* readrel629 = db->getRelation("eval");
      evaldelta617 = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel631 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index605 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({2, 3, 0, 1});
      slog::Relation* readrel633 = db->getRelation("eval");
      evalindex606 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 0});
      slog::Relation* readrel635 = db->getRelation("select_branch_ans");
      select_branch_ansindex607 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({2, 3, 0, 1});
      slog::Relation* readrel637 = db->getRelation("eval");
      evalindex608 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({2, 3, 0, 1});
      slog::Relation* readrel639 = db->getRelation("eval");
      evaldelta618 = readrel639->getIndex(ord638, true);
      std::vector<u16> ord640({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel641 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index609 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel643 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0delta619 = readrel643->getIndex(ord642, true);
      std::vector<u16> ord644({1, 3, 2, 0});
      slog::Relation* readrel645 = db->getRelation("if");
      ifindex610 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 3, 2, 0});
      slog::Relation* readrel647 = db->getRelation("if");
      ifdelta620 = readrel647->getIndex(ord646, true);
      std::vector<u16> ord648({2, 3, 1, 0});
      slog::Relation* readrel649 = db->getRelation("select_branch");
      select_branchindex611 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 2, 3, 0});
      slog::Relation* readrel651 = db->getRelation("eval");
      evalindex612 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 3, 0});
      slog::Relation* readrel653 = db->getRelation("eval");
      evaldelta621 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("eval_ans");
      eval_ansindex613 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({2, 3, 1, 0});
      slog::Relation* readrel657 = db->getRelation("select_branch");
      select_branchindex614 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({2, 3, 1, 0});
      slog::Relation* readrel659 = db->getRelation("select_branch");
      select_branchdelta622 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("eval_ans");
      eval_ansindex615 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("select_branch_ans");
      select_branch_ansindex616 = readrel663->getIndex(ord662, false);
  
    }
    ReadTask623(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c109 = _t[0];
        u64 v_c110 = _t[1];
        slog::join_probe_old<4,1>(evalindex604, evaldelta617, std::array<u64,4>{v_c109, 0, 0, 0}, [&](const std::array<u64,4>& m664) {
          u64 v_c69 = m664[1]; u64 v_c2 = m664[2]; u64 v_c3 = m664[3];
          if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index605, std::array<u64,6>{v_c2, v_c3, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex606, std::array<u64,4>{v_c2, v_c3, 0, 0})) return;
          if (!slog::exists_probe<2,1>(select_branch_ansindex607, std::array<u64,2>{v_c69, 0})) return;
          slog::join_probe_old<4,2>(evalindex608, evaldelta618, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m665) {
            u64 v_c111 = m665[2]; u64 v_c112 = m665[3];
            slog::join_probe_old<6,3>($sup70016x87x0x0x0index609, $sup70016x87x0x0x0delta619, std::array<u64,6>{v_c2, v_c3, v_c111, 0, 0, 0}, [&](const std::array<u64,6>& m666) {
              u64 v_c113 = m666[3]; u64 v_c114 = m666[4]; u64 v_c115 = m666[5];
              slog::join_probe_old<4,4>(ifindex610, ifdelta620, std::array<u64,4>{v_c113, v_c115, v_c114, v_c112}, [&](const std::array<u64,4>& m667) {
                if (!slog::exists_probe<4,2>(select_branchindex611, std::array<u64,4>{v_c114, v_c115, 0, 0})) return;
                slog::join_probe_old<4,3>(evalindex612, evaldelta621, std::array<u64,4>{v_c113, v_c2, v_c3, 0}, [&](const std::array<u64,4>& m668) {
                  u64 v_c116 = m668[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex613, std::array<u64,2>{v_c116, 0})) return;
                  slog::join_probe_old<4,2>(select_branchindex614, select_branchdelta622, std::array<u64,4>{v_c114, v_c115, 0, 0}, [&](const std::array<u64,4>& m669) {
                    u64 v_c18 = m669[2]; u64 v_c117 = m669[3];
                    slog::join_probe<2,2>(eval_ansindex615, std::array<u64,2>{v_c116, v_c18}, [&](const std::array<u64,2>& m670) {
                      slog::join_probe<2,2>(select_branch_ansindex616, std::array<u64,2>{v_c117, v_c69}, [&](const std::array<u64,2>& m671) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c111, v_c110}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask623* _cont = new ReadTask623(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask623(db,b), false);
  // (crule (pre) (scan eval __t7lOb612 ef rho t) (body (exists app (1 2 0) 1 ef) (exists eval_args (3 2 0 1) 2 t rho) (exists tick (2 0 1) 1 t) (exists eval_ans (0 1) 1 __t7lOb612) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2) (join-old closure (0 1 2) 1 (0 1 2) __t6tRF614 __t20Nd613 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask693 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex672;  slog::Index** eval_argsindex673;  slog::Index** tickindex674;  slog::Index** eval_ansindex675;  slog::Index** evalindex676;  slog::Index** tickindex677;  slog::Index** appindex678;  slog::Index** eval_argsindex679;  slog::Index** eval_args_ansindex680;  slog::Index** tickindex681;  slog::Index** tick_ansindex682;  slog::Index** eval_ansindex683;  slog::Index** eval_args_ansindex684;  slog::Index** tick_ansindex685;  slog::Index** closureindex686;  slog::Index** lambdaindex687;  slog::Index** appdelta688;  slog::Index** eval_argsdelta689;  slog::Index** tickdelta690;  slog::Index** closuredelta691;  slog::Index** lambdadelta692;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord694({0, 1, 2, 3});
      slog::Relation* readrel695 = db->getRelation("bind_store");
      head_index[0] = readrel695->getIndex(ord694, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("call_event");
      head_index[1] = readrel697->getIndex(ord696, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("app");
      appindex672 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({3, 2, 0, 1});
      slog::Relation* readrel701 = db->getRelation("eval_args");
      eval_argsindex673 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({2, 0, 1});
      slog::Relation* readrel703 = db->getRelation("tick");
      tickindex674 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 1});
      slog::Relation* readrel705 = db->getRelation("eval_ans");
      eval_ansindex675 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 3, 0, 1});
      slog::Relation* readrel707 = db->getRelation("eval");
      evalindex676 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 2, 0});
      slog::Relation* readrel709 = db->getRelation("tick");
      tickindex677 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1, 2});
      slog::Relation* readrel711 = db->getRelation("app");
      appindex678 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({0, 1, 2});
      slog::Relation* readrel713 = db->getRelation("app");
      appdelta688 = readrel713->getIndex(ord712, true);
      std::vector<u16> ord714({1, 3, 2, 0});
      slog::Relation* readrel715 = db->getRelation("eval_args");
      eval_argsindex679 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 3, 2, 0});
      slog::Relation* readrel717 = db->getRelation("eval_args");
      eval_argsdelta689 = readrel717->getIndex(ord716, true);
      std::vector<u16> ord718({0, 1});
      slog::Relation* readrel719 = db->getRelation("eval_args_ans");
      eval_args_ansindex680 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 2, 0});
      slog::Relation* readrel721 = db->getRelation("tick");
      tickindex681 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("tick");
      tickdelta690 = readrel723->getIndex(ord722, true);
      std::vector<u16> ord724({0, 1});
      slog::Relation* readrel725 = db->getRelation("tick_ans");
      tick_ansindex682 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("eval_ans");
      eval_ansindex683 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("eval_args_ans");
      eval_args_ansindex684 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({0, 1});
      slog::Relation* readrel731 = db->getRelation("tick_ans");
      tick_ansindex685 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 1, 2});
      slog::Relation* readrel733 = db->getRelation("closure");
      closureindex686 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({0, 1, 2});
      slog::Relation* readrel735 = db->getRelation("closure");
      closuredelta691 = readrel735->getIndex(ord734, true);
      std::vector<u16> ord736({0, 1, 2});
      slog::Relation* readrel737 = db->getRelation("lambda");
      lambdaindex687 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 1, 2});
      slog::Relation* readrel739 = db->getRelation("lambda");
      lambdadelta692 = readrel739->getIndex(ord738, true);
  
    }
    ReadTask693(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c104 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<3,1>(appindex672, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex673, std::array<u64,4>{v_c3, v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex674, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex675, std::array<u64,2>{v_c104, 0})) return;
        slog::join_probe<4,2>(evalindex676, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m740) {
          u64 v_c102 = m740[2]; u64 v_c103 = m740[3];
          if (!slog::exists_probe<3,2>(tickindex677, std::array<u64,3>{v_c103, v_c3, 0})) return;
          slog::join_probe_old<3,2>(appindex678, appdelta688, std::array<u64,3>{v_c103, v_c4, 0}, [&](const std::array<u64,3>& m741) {
            u64 v_c5 = m741[2];
            slog::join_probe_old<4,3>(eval_argsindex679, eval_argsdelta689, std::array<u64,4>{v_c5, v_c3, v_c2, 0}, [&](const std::array<u64,4>& m742) {
              u64 v_c101 = m742[3];
              if (!slog::exists_probe<2,1>(eval_args_ansindex680, std::array<u64,2>{v_c101, 0})) return;
              slog::join_probe_old<3,2>(tickindex681, tickdelta690, std::array<u64,3>{v_c103, v_c3, 0}, [&](const std::array<u64,3>& m743) {
                u64 v_c105 = m743[2];
                if (!slog::exists_probe<2,1>(tick_ansindex682, std::array<u64,2>{v_c105, 0})) return;
                slog::join_probe<2,1>(eval_ansindex683, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m744) {
                  u64 v_c106 = m744[1];
                  slog::join_probe<2,1>(eval_args_ansindex684, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m745) {
                    u64 v_c12 = m745[1];
                    slog::join_probe<2,1>(tick_ansindex685, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m746) {
                      u64 v_c11 = m746[1];
                      slog::join_probe_old<3,1>(closureindex686, closuredelta691, std::array<u64,3>{v_c106, 0, 0}, [&](const std::array<u64,3>& m747) {
                        u64 v_c107 = m747[1]; u64 v_c10 = m747[2];
                        slog::join_probe_old<3,1>(lambdaindex687, lambdadelta692, std::array<u64,3>{v_c107, 0, 0}, [&](const std::array<u64,3>& m748) {
                          u64 v_c13 = m748[1]; u64 v_c9 = m748[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c13, v_c12, v_c11, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c11, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask693* _cont = new ReadTask693(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask693(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x1 __t8K90240 __t0CZp243 k l m p r v) (body (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t8K90240 k v) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_msk (1 2 0) 3 k m __t0CZp243) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3kyC239) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t8K90240 k __t3kyC239 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0CZp243) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask764 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index749;  slog::Index** mp_putindex750;  slog::Index** mp_mskindex751;  slog::Index** mp_putindex752;  slog::Index** mp_msk_ansindex753;  slog::Index** mbranchindex754;  slog::Index** mp_putindex755;  slog::Index** mp_mskindex756;  slog::Index** mp_putindex757;  slog::Index** mp_msk_ansindex758;  slog::Index** mp_put_ansindex759;  slog::Index** mbranchdelta760;  slog::Index** mp_putdelta761;  slog::Index** mp_mskdelta762;  slog::Index** mp_putdelta763;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord765({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel766 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index749 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({3, 0, 2, 1});
      slog::Relation* readrel768 = db->getRelation("mp_put");
      mp_putindex750 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("mp_msk");
      mp_mskindex751 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 2, 3, 0});
      slog::Relation* readrel772 = db->getRelation("mp_put");
      mp_putindex752 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({0, 1});
      slog::Relation* readrel774 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex753 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 3, 4, 0});
      slog::Relation* readrel776 = db->getRelation("mbranch");
      mbranchindex754 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 3, 4, 0});
      slog::Relation* readrel778 = db->getRelation("mbranch");
      mbranchdelta760 = readrel778->getIndex(ord777, true);
      std::vector<u16> ord779({0, 2, 1, 3});
      slog::Relation* readrel780 = db->getRelation("mp_put");
      mp_putindex755 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 2, 1, 3});
      slog::Relation* readrel782 = db->getRelation("mp_put");
      mp_putdelta761 = readrel782->getIndex(ord781, true);
      std::vector<u16> ord783({1, 2, 0});
      slog::Relation* readrel784 = db->getRelation("mp_msk");
      mp_mskindex756 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 2, 0});
      slog::Relation* readrel786 = db->getRelation("mp_msk");
      mp_mskdelta762 = readrel786->getIndex(ord785, true);
      std::vector<u16> ord787({1, 2, 3, 0});
      slog::Relation* readrel788 = db->getRelation("mp_put");
      mp_putindex757 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 3, 0});
      slog::Relation* readrel790 = db->getRelation("mp_put");
      mp_putdelta763 = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({0, 1});
      slog::Relation* readrel792 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex758 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("mp_put_ans");
      mp_put_ansindex759 = readrel794->getIndex(ord793, false);
  
    }
    ReadTask764(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c29 = _t[4];
        u64 v_c30 = _t[5];
        u64 v_c31 = _t[6];
        u64 v_c19 = _t[7];
        slog::join_probe<7,7>($sup5638x40x0x0x0index749, std::array<u64,7>{v_c30, v_c28, v_c29, v_c31, v_c119, v_c121, v_c19}, [&](const std::array<u64,7>& m795) {
          if (!slog::exists_probe<4,3>(mp_putindex750, std::array<u64,4>{v_c19, v_c119, v_c121, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex751, std::array<u64,3>{v_c121, v_c29, v_c120})) return;
          if (!slog::exists_probe<4,3>(mp_putindex752, std::array<u64,4>{v_c28, v_c121, v_c19, 0})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex753, std::array<u64,2>{v_c120, v_c30})) return;
          slog::join_probe_old<5,4>(mbranchindex754, mbranchdelta760, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, 0}, [&](const std::array<u64,5>& m796) {
            u64 v_c122 = m796[4];
            slog::join_probe_old<4,4>(mp_putindex755, mp_putdelta761, std::array<u64,4>{v_c119, v_c121, v_c122, v_c19}, [&](const std::array<u64,4>& m797) {
              slog::join_probe_old<3,3>(mp_mskindex756, mp_mskdelta762, std::array<u64,3>{v_c121, v_c29, v_c120}, [&](const std::array<u64,3>& m798) {
                slog::join_probe_old<4,3>(mp_putindex757, mp_putdelta763, std::array<u64,4>{v_c28, v_c121, v_c19, 0}, [&](const std::array<u64,4>& m799) {
                  u64 v_c123 = m799[3];
                  slog::join_probe<2,2>(mp_msk_ansindex758, std::array<u64,2>{v_c120, v_c30}, [&](const std::array<u64,2>& m800) {
                    slog::join_probe<2,1>(mp_put_ansindex759, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m801) {
                      u64 v_c18 = m801[1];
                      u64 v_c124 = _prim_band(db, v_c121, v_c29);
                      if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c125 = _prim_lt(db, v_c124, v_c118);
                      if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c125) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c119, v_c18, v_c29, v_c30, v_c31});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c29, v_c18, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask764* _cont = new ReadTask764(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask764(db,b), false);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst1XI2167 const3fdba35f04dc8c462986c992) (let __tconst5TvD157 const06abaa100ecef791ce028c56)) (scan temp7BWu1993 __t3ORQ166 __t7NO4156 __t9GVo175 __t9kRL183) (body (exists app (2 0 1) 1 __t7NO4156) (join primref (1 0) 1 __tconst5TvD157 __t2ZGf158) (join app (1 2 0) 2 __t2ZGf158 __t7NO4156 __t9KE7159)) (head (emit-temp temp14ub1994 __t3ORQ166 __t9GVo175 __t9KE7159 __t9kRL183) (mkstruct let (1 2 3 0) __t2pQQ168 __tconst1XI2167 __t3ORQ166 __t9KE7159)) kcfa.slog:29 #f)
  class ReadTask806 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex803;  slog::Index** primrefindex804;  slog::Index** appindex805;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp14ub1994");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp7BWu1993");
      std::vector<u16> ord807({2, 0, 1});
      slog::Relation* readrel808 = db->getRelation("app");
      appindex803 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 0});
      slog::Relation* readrel810 = db->getRelation("primref");
      primrefindex804 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 0});
      slog::Relation* readrel812 = db->getRelation("app");
      appindex805 = readrel812->getIndex(ord811, false);
  
    }
    ReadTask806(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const4a44dc15364204a80fe80e90;
      u64 v_c127 = v_const6b51d431df5d7f141cbececc;
      u64 v_c128 = v_const3fdba35f04dc8c462986c992;
      u64 v_c129 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c130 = _t[0];
        u64 v_c131 = _t[1];
        u64 v_c132 = _t[2];
        u64 v_c133 = _t[3];
        if (!slog::exists_probe<3,1>(appindex803, std::array<u64,3>{v_c131, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex804, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m813) {
          u64 v_c134 = m813[1];
          slog::join_probe<3,2>(appindex805, std::array<u64,3>{v_c134, v_c131, 0}, [&](const std::array<u64,3>& m814) {
            u64 v_c135 = m814[2];
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c130, v_c132, v_c135, v_c133});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c128, v_c130, v_c135}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp7BWu1993", _fires);
  
      if (!_done)
      {
        ReadTask806* _cont = new ReadTask806(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask806(db,b), false);
  // (crule (pre) (scan boolean __t91oc139 b) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t91oc139 rho t __t1ySt140)) (head (emit-temp temp1se51948 __t1ySt140 b) (mkstruct boolval (1 0) __t6Y41138 b)) interp.slog:31 #f)
  class ReadTask817 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex815;  slog::Index** evaldelta816;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1se51948");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolean");
      std::vector<u16> ord818({1, 2, 3, 0});
      slog::Relation* readrel819 = db->getRelation("eval");
      evalindex815 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 3, 0});
      slog::Relation* readrel821 = db->getRelation("eval");
      evaldelta816 = readrel821->getIndex(ord820, true);
  
    }
    ReadTask817(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c136 = _t[0];
        u64 v_c137 = _t[1];
        slog::join_probe_old<4,1>(evalindex815, evaldelta816, std::array<u64,4>{v_c136, 0, 0, 0}, [&](const std::array<u64,4>& m822) {
          u64 v_c2 = m822[1]; u64 v_c3 = m822[2]; u64 v_c138 = m822[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c138, v_c137});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:31", "delta:boolean", _fires);
  
      if (!_done)
      {
        ReadTask817* _cont = new ReadTask817(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask817(db,b), false);
  // (crule (pre (let __tconst5HUr775 const6b86b273ff34fce19d6b804e)) (scan mp_hsb __t0pir774 __t4G4F773) (body (join mp_hsb_ans (0 1) 1 __t0pir774 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t0Mwp776 (band p0 __v0)) (cmp lt __t0Mwp776 __tconst5HUr775) (let chk26Y41834 (bxor p0 p1)) (eq __t4G4F773 chk26Y41834)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t0pir774 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask825 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex823;  slog::Index** $sup5638x25x0x0x0index824;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord826({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel827 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel827->getIndex(ord826, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex823 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 0, 2, 3, 4});
      slog::Relation* readrel831 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index824 = readrel831->getIndex(ord830, false);
  
    }
    ReadTask825(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c140 = _t[0];
        u64 v_c141 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex823, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m832) {
          u64 v_c18 = m832[1];
          slog::join_all<5>($sup5638x25x0x0x0index824, [&](const std::array<u64,5>& m833) {
            u64 v_c63 = m833[0]; u64 v_c36 = m833[1]; u64 v_c64 = m833[2]; u64 v_c65 = m833[3]; u64 v_c66 = m833[4];
            u64 v_c142 = _prim_band(db, v_c63, v_c18);
            if (v_c142 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c143 = _prim_lt(db, v_c142, v_c139);
            if (v_c143 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c143) return;
            u64 v_c144 = _prim_bxor(db, v_c63, v_c64);
            if (v_c144 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (v_c141 != v_c144) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c140, v_c18, v_c36, v_c63, v_c64, v_c65, v_c66}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask825* _cont = new ReadTask825(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask825(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x0 __t7O3e781 p0 p1 t0 t1) (body (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (exists $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t7O3e781 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 5 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists mp_hsb_ans (0 1) 2 __t8x7Q785 __v0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0 dup6QI21998 dup4FCe1999 __v1 __v3) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join-old mp_msk_ans (0 1) 1 (0 1) __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask855 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex835;  slog::Index** $sup5638x29x0x0x2index836;  slog::Index** mp_mskindex837;  slog::Index** $sup5638x29x0x0x1index838;  slog::Index** mp_hsb_ansindex839;  slog::Index** mp_hsb_ansindex840;  slog::Index** $sup5638x29x0x0x2index841;  slog::Index** mp_hsb_ansindex842;  slog::Index** mp_hsb_ansindex843;  slog::Index** mp_hsb_ansindex844;  slog::Index** mp_mskindex845;  slog::Index** mp_msk_ansindex846;  slog::Index** mp_hsbindex847;  slog::Index** mp_joindelta848;  slog::Index** mp_hsb_ansdelta849;  slog::Index** mp_hsb_ansdelta850;  slog::Index** mp_hsb_ansdelta851;  slog::Index** mp_mskdelta852;  slog::Index** mp_msk_ansdelta853;  slog::Index** mp_hsbdelta854;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord856({1, 2, 3, 4, 0});
      slog::Relation* readrel857 = db->getRelation("mp_join");
      mp_joinindex835 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 2, 3, 4, 0});
      slog::Relation* readrel859 = db->getRelation("mp_join");
      mp_joindelta848 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel861 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index836 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("mp_msk");
      mp_mskindex837 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel865 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index838 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1});
      slog::Relation* readrel867 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex839 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1});
      slog::Relation* readrel869 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex840 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel871 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index841 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({0, 1});
      slog::Relation* readrel873 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex842 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1});
      slog::Relation* readrel875 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta849 = readrel875->getIndex(ord874, true);
      std::vector<u16> ord876({0, 1});
      slog::Relation* readrel877 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex843 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({0, 1});
      slog::Relation* readrel879 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta850 = readrel879->getIndex(ord878, true);
      std::vector<u16> ord880({0, 1});
      slog::Relation* readrel881 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex844 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({0, 1});
      slog::Relation* readrel883 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta851 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("mp_msk");
      mp_mskindex845 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 2, 0});
      slog::Relation* readrel887 = db->getRelation("mp_msk");
      mp_mskdelta852 = readrel887->getIndex(ord886, true);
      std::vector<u16> ord888({0, 1});
      slog::Relation* readrel889 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex846 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({0, 1});
      slog::Relation* readrel891 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta853 = readrel891->getIndex(ord890, true);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("mp_hsb");
      mp_hsbindex847 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("mp_hsb");
      mp_hsbdelta854 = readrel895->getIndex(ord894, true);
  
    }
    ReadTask855(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c145 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c146 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c66 = _t[4];
        slog::join_probe_old<5,5>(mp_joinindex835, mp_joindelta848, std::array<u64,5>{v_c63, v_c65, v_c64, v_c66, v_c146}, [&](const std::array<u64,5>& m896) {
          if (!slog::exists_probe<11,5>($sup5638x29x0x0x2index836, std::array<u64,11>{v_c146, v_c63, v_c64, v_c65, v_c66, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex837, std::array<u64,3>{v_c63, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x29x0x0x1index838, std::array<u64,7>{v_c146, v_c63, v_c64, v_c65, v_c66, 0, 0}, [&](const std::array<u64,7>& m897) {
            u64 v_c147 = m897[5]; u64 v_c18 = m897[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex839, std::array<u64,2>{v_c147, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex840, std::array<u64,2>{v_c147, v_c18})) return;
            slog::join_probe<11,7>($sup5638x29x0x0x2index841, std::array<u64,11>{v_c146, v_c63, v_c64, v_c65, v_c66, v_c147, v_c18, 0, 0, 0, 0}, [&](const std::array<u64,11>& m898) {
              u64 v_c148 = m898[7]; u64 v_c149 = m898[8]; u64 v_c69 = m898[9]; u64 v_c68 = m898[10];
              if (v_c147 != v_c149) return;
              if (v_c147 != v_c148) return;
              slog::join_probe_old<2,2>(mp_hsb_ansindex842, mp_hsb_ansdelta849, std::array<u64,2>{v_c147, v_c68}, [&](const std::array<u64,2>& m899) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex843, mp_hsb_ansdelta850, std::array<u64,2>{v_c147, v_c69}, [&](const std::array<u64,2>& m900) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex844, mp_hsb_ansdelta851, std::array<u64,2>{v_c147, v_c18}, [&](const std::array<u64,2>& m901) {
                    slog::join_probe_old<3,2>(mp_mskindex845, mp_mskdelta852, std::array<u64,3>{v_c63, v_c69, 0}, [&](const std::array<u64,3>& m902) {
                      u64 v_c150 = m902[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex846, mp_msk_ansdelta853, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m903) {
                        u64 v_c110 = m903[1];
                        u64 v_c151 = _prim_bxor(db, v_c63, v_c64);
                        if (v_c151 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex847, mp_hsbdelta854, std::array<u64,2>{v_c147, v_c151}, [&](const std::array<u64,2>& m904) {
                          u64 v_c152 = _prim_band(db, v_c63, v_c18);
                          if (v_c152 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c153 = _prim_gt(db, v_c152, v_c145);
                          if (v_c153 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c153) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c146, v_c110, v_c68, v_c65, v_c66});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c68, v_c66, v_c65}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask855* _cont = new ReadTask855(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask855(db,b), false);
  // (crule (pre) (scan eval_args_ans __t24hv340 vs) (body (join-old delta (2 0 1) 1 (2 0 1) vs __t9Mk1341 op) (exists prim (1 0) 1 op) (join-old delta_ans (0 1) 1 (0 1) __t9Mk1341 v) (join-old prim (1 0) 1 (1 0) op __t1N6L339) (join eval_ans (1 0) 1 __t1N6L339 __t8KmI338) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t8KmI338 ef rho t) (exists $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (join-old eval_args (3 2 0 1) 3 (3 2 0 1) t rho __t24hv340 es) (exists app (1 2 0) 2 ef es) (join-old $sup70016x75x0x0x0 (1 3 4 2 0) 4 (1 3 4 2 0) ef rho t es __t8Dhb337) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t8Dhb337 __t87KU336) (join-old app (0 1 2) 3 (0 1 2) __t87KU336 ef es)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask928 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex906;  slog::Index** primindex907;  slog::Index** delta_ansindex908;  slog::Index** primindex909;  slog::Index** eval_ansindex910;  slog::Index** evalindex911;  slog::Index** $sup70016x75x0x0x0index912;  slog::Index** evalindex913;  slog::Index** appindex914;  slog::Index** eval_argsindex915;  slog::Index** appindex916;  slog::Index** $sup70016x75x0x0x0index917;  slog::Index** evalindex918;  slog::Index** appindex919;  slog::Index** deltadelta920;  slog::Index** delta_ansdelta921;  slog::Index** primdelta922;  slog::Index** evaldelta923;  slog::Index** eval_argsdelta924;  slog::Index** $sup70016x75x0x0x0delta925;  slog::Index** evaldelta926;  slog::Index** appdelta927;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord929({0, 1});
      slog::Relation* readrel930 = db->getRelation("eval_ans");
      head_index[0] = readrel930->getIndex(ord929, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord931({2, 0, 1});
      slog::Relation* readrel932 = db->getRelation("delta");
      deltaindex906 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({2, 0, 1});
      slog::Relation* readrel934 = db->getRelation("delta");
      deltadelta920 = readrel934->getIndex(ord933, true);
      std::vector<u16> ord935({1, 0});
      slog::Relation* readrel936 = db->getRelation("prim");
      primindex907 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({0, 1});
      slog::Relation* readrel938 = db->getRelation("delta_ans");
      delta_ansindex908 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({0, 1});
      slog::Relation* readrel940 = db->getRelation("delta_ans");
      delta_ansdelta921 = readrel940->getIndex(ord939, true);
      std::vector<u16> ord941({1, 0});
      slog::Relation* readrel942 = db->getRelation("prim");
      primindex909 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0});
      slog::Relation* readrel944 = db->getRelation("prim");
      primdelta922 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({1, 0});
      slog::Relation* readrel946 = db->getRelation("eval_ans");
      eval_ansindex910 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({0, 1, 2, 3});
      slog::Relation* readrel948 = db->getRelation("eval");
      evalindex911 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({0, 1, 2, 3});
      slog::Relation* readrel950 = db->getRelation("eval");
      evaldelta923 = readrel950->getIndex(ord949, true);
      std::vector<u16> ord951({1, 3, 4, 2, 0});
      slog::Relation* readrel952 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index912 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({2, 3, 0, 1});
      slog::Relation* readrel954 = db->getRelation("eval");
      evalindex913 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("app");
      appindex914 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({3, 2, 0, 1});
      slog::Relation* readrel958 = db->getRelation("eval_args");
      eval_argsindex915 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({3, 2, 0, 1});
      slog::Relation* readrel960 = db->getRelation("eval_args");
      eval_argsdelta924 = readrel960->getIndex(ord959, true);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("app");
      appindex916 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 3, 4, 2, 0});
      slog::Relation* readrel964 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index917 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 3, 4, 2, 0});
      slog::Relation* readrel966 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0delta925 = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({2, 3, 0, 1});
      slog::Relation* readrel968 = db->getRelation("eval");
      evalindex918 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({2, 3, 0, 1});
      slog::Relation* readrel970 = db->getRelation("eval");
      evaldelta926 = readrel970->getIndex(ord969, true);
      std::vector<u16> ord971({0, 1, 2});
      slog::Relation* readrel972 = db->getRelation("app");
      appindex919 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({0, 1, 2});
      slog::Relation* readrel974 = db->getRelation("app");
      appdelta927 = readrel974->getIndex(ord973, true);
  
    }
    ReadTask928(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        slog::join_probe_old<3,1>(deltaindex906, deltadelta920, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m975) {
          u64 v_c155 = m975[1]; u64 v_c156 = m975[2];
          if (!slog::exists_probe<2,1>(primindex907, std::array<u64,2>{v_c156, 0})) return;
          slog::join_probe_old<2,1>(delta_ansindex908, delta_ansdelta921, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m976) {
            u64 v_c19 = m976[1];
            slog::join_probe_old<2,1>(primindex909, primdelta922, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m977) {
              u64 v_c157 = m977[1];
              slog::join_probe<2,1>(eval_ansindex910, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m978) {
                u64 v_c158 = m978[1];
                slog::join_probe_old<4,1>(evalindex911, evaldelta923, std::array<u64,4>{v_c158, 0, 0, 0}, [&](const std::array<u64,4>& m979) {
                  u64 v_c4 = m979[1]; u64 v_c2 = m979[2]; u64 v_c3 = m979[3];
                  if (!slog::exists_probe<5,3>($sup70016x75x0x0x0index912, std::array<u64,5>{v_c4, v_c2, v_c3, 0, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex913, std::array<u64,4>{v_c2, v_c3, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex914, std::array<u64,3>{v_c4, 0, 0})) return;
                  slog::join_probe_old<4,3>(eval_argsindex915, eval_argsdelta924, std::array<u64,4>{v_c3, v_c2, v_c154, 0}, [&](const std::array<u64,4>& m980) {
                    u64 v_c5 = m980[3];
                    if (!slog::exists_probe<3,2>(appindex916, std::array<u64,3>{v_c4, v_c5, 0})) return;
                    slog::join_probe_old<5,4>($sup70016x75x0x0x0index917, $sup70016x75x0x0x0delta925, std::array<u64,5>{v_c4, v_c2, v_c3, v_c5, 0}, [&](const std::array<u64,5>& m981) {
                      u64 v_c159 = m981[4];
                      slog::join_probe_old<4,3>(evalindex918, evaldelta926, std::array<u64,4>{v_c2, v_c3, v_c159, 0}, [&](const std::array<u64,4>& m982) {
                        u64 v_c160 = m982[3];
                        slog::join_probe_old<3,3>(appindex919, appdelta927, std::array<u64,3>{v_c160, v_c4, v_c5}, [&](const std::array<u64,3>& m983) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c159, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask928* _cont = new ReadTask928(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask928(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_join __t8CpS128 p0 t0 p1 t1) (body (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (exists $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t8CpS128 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 5 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists mp_hsb_ans (0 1) 2 __t0Ayb132 __v0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0 dup4t6F1978 dup2J5X1979 __v1 __v3) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join mp_hsb_ans (0 1) 2 __t0Ayb132 __v3) (join mp_hsb_ans (0 1) 2 __t0Ayb132 __v1) (join mp_hsb_ans (0 1) 2 __t0Ayb132 __v0) (join mp_msk (1 2 0) 2 p0 __v1 __t40jf135) (join mp_msk_ans (0 1) 1 __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join mp_hsb (0 1) 2 __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask997 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x0index984;  slog::Index** $sup5638x25x0x0x2index985;  slog::Index** mp_mskindex986;  slog::Index** $sup5638x25x0x0x1index987;  slog::Index** mp_hsb_ansindex988;  slog::Index** mp_hsb_ansindex989;  slog::Index** $sup5638x25x0x0x2index990;  slog::Index** mp_hsb_ansindex991;  slog::Index** mp_hsb_ansindex992;  slog::Index** mp_hsb_ansindex993;  slog::Index** mp_mskindex994;  slog::Index** mp_msk_ansindex995;  slog::Index** mp_hsbindex996;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord998({1, 0, 2, 3, 4});
      slog::Relation* readrel999 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index984 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1001 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index985 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({1, 2, 0});
      slog::Relation* readrel1003 = db->getRelation("mp_msk");
      mp_mskindex986 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1005 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index987 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({0, 1});
      slog::Relation* readrel1007 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex988 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({0, 1});
      slog::Relation* readrel1009 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex989 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1011 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index990 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({0, 1});
      slog::Relation* readrel1013 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex991 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({0, 1});
      slog::Relation* readrel1015 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex992 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({0, 1});
      slog::Relation* readrel1017 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex993 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 0});
      slog::Relation* readrel1019 = db->getRelation("mp_msk");
      mp_mskindex994 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({0, 1});
      slog::Relation* readrel1021 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex995 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({0, 1});
      slog::Relation* readrel1023 = db->getRelation("mp_hsb");
      mp_hsbindex996 = readrel1023->getIndex(ord1022, false);
  
    }
    ReadTask997(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c161 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c162 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c65 = _t[2];
        u64 v_c64 = _t[3];
        u64 v_c66 = _t[4];
        slog::join_probe<5,5>($sup5638x25x0x0x0index984, std::array<u64,5>{v_c63, v_c162, v_c64, v_c65, v_c66}, [&](const std::array<u64,5>& m1024) {
          if (!slog::exists_probe<11,5>($sup5638x25x0x0x2index985, std::array<u64,11>{v_c162, v_c63, v_c64, v_c65, v_c66, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex986, std::array<u64,3>{v_c63, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x25x0x0x1index987, std::array<u64,7>{v_c162, v_c63, v_c64, v_c65, v_c66, 0, 0}, [&](const std::array<u64,7>& m1025) {
            u64 v_c163 = m1025[5]; u64 v_c18 = m1025[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex988, std::array<u64,2>{v_c163, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex989, std::array<u64,2>{v_c163, v_c18})) return;
            slog::join_probe<11,7>($sup5638x25x0x0x2index990, std::array<u64,11>{v_c162, v_c63, v_c64, v_c65, v_c66, v_c163, v_c18, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1026) {
              u64 v_c164 = m1026[7]; u64 v_c165 = m1026[8]; u64 v_c69 = m1026[9]; u64 v_c68 = m1026[10];
              if (v_c163 != v_c165) return;
              if (v_c163 != v_c164) return;
              slog::join_probe<2,2>(mp_hsb_ansindex991, std::array<u64,2>{v_c163, v_c68}, [&](const std::array<u64,2>& m1027) {
                slog::join_probe<2,2>(mp_hsb_ansindex992, std::array<u64,2>{v_c163, v_c69}, [&](const std::array<u64,2>& m1028) {
                  slog::join_probe<2,2>(mp_hsb_ansindex993, std::array<u64,2>{v_c163, v_c18}, [&](const std::array<u64,2>& m1029) {
                    slog::join_probe<3,2>(mp_mskindex994, std::array<u64,3>{v_c63, v_c69, 0}, [&](const std::array<u64,3>& m1030) {
                      u64 v_c166 = m1030[2];
                      slog::join_probe<2,1>(mp_msk_ansindex995, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1031) {
                        u64 v_c110 = m1031[1];
                        u64 v_c167 = _prim_bxor(db, v_c63, v_c64);
                        if (v_c167 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe<2,2>(mp_hsbindex996, std::array<u64,2>{v_c163, v_c167}, [&](const std::array<u64,2>& m1032) {
                          u64 v_c168 = _prim_band(db, v_c63, v_c18);
                          if (v_c168 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c169 = _prim_lt(db, v_c168, v_c161);
                          if (v_c169 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c169) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c162, v_c110, v_c68, v_c65, v_c66});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c68, v_c65, v_c66}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask997* _cont = new ReadTask997(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask997(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e)) (scan temp8qsY2009 __t0Vtj505 __t0cTh509 __t2zNy470 __t9htJ493) (body (exists num (1 0) 1 __tconst0Ob1494) (join if (1 3 2 0) 2 __t0Vtj505 __t9htJ493 __t1oVV472 __t6hPZ506) (join num (0 1) 2 __t1oVV472 __tconst0Ob1494)) (head (emit-temp temp32cQ2010 __t0cTh509 __t2zNy470 __t6hPZ506) (mkstruct lambda (1 2 0) __t6gSw510 __t0cTh509 __t6hPZ506)) kcfa.slog:40 #f)
  class ReadTask1037 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1034;  slog::Index** ifindex1035;  slog::Index** numindex1036;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp32cQ2010");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp8qsY2009");
      std::vector<u16> ord1038({1, 0});
      slog::Relation* readrel1039 = db->getRelation("num");
      numindex1034 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({1, 3, 2, 0});
      slog::Relation* readrel1041 = db->getRelation("if");
      ifindex1035 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({0, 1});
      slog::Relation* readrel1043 = db->getRelation("num");
      numindex1036 = readrel1043->getIndex(ord1042, false);
  
    }
    ReadTask1037(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c171 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c172 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c174 = _t[2];
        u64 v_c175 = _t[3];
        if (!slog::exists_probe<2,1>(numindex1034, std::array<u64,2>{v_c171, 0})) return;
        slog::join_probe<4,2>(ifindex1035, std::array<u64,4>{v_c172, v_c175, 0, 0}, [&](const std::array<u64,4>& m1044) {
          u64 v_c176 = m1044[2]; u64 v_c177 = m1044[3];
          slog::join_probe<2,2>(numindex1036, std::array<u64,2>{v_c176, v_c171}, [&](const std::array<u64,2>& m1045) {
            ++_fires;
            slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c173, v_c174, v_c177});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c173, v_c177}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp8qsY2009", _fires);
  
      if (!_done)
      {
        ReadTask1037* _cont = new ReadTask1037(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1037(db,b), false);
  // (crule (pre) (scan temp0Rhp1793 __t0r8J513 __t30pJ514) (body) (head (emit eval_args_ans (0 1) __t30pJ514 __t0r8J513)) interp.slog:43 #f)
  class ReadTask1046 : public slog::Task
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
      std::vector<u16> ord1047({0, 1});
      slog::Relation* readrel1048 = db->getRelation("eval_args_ans");
      head_index[0] = readrel1048->getIndex(ord1047, false);
      outer_rel = db->getRelation("temp0Rhp1793");
  
    }
    ReadTask1046(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c178 = _t[0];
        u64 v_c179 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c179, v_c178}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:43", "delta:temp0Rhp1793", _fires);
  
      if (!_done)
      {
        ReadTask1046* _cont = new ReadTask1046(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1046(db,b), false);
  // (crule (pre (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp3H1p1987 __t39ek93 __t8z2o72 __t953c65 __t9rwO81) (body (join let (1 2 3 0) 3 __tconst6c7T73 __t8z2o72 __t953c65 __t5f4h74)) (head (emit-temp temp7mbl1988 __t39ek93 __t5f4h74 __t9rwO81) (mkstruct let (1 2 3 0) __t62tP83 __tconst56qw82 __t9rwO81 __t5f4h74)) kcfa.slog:16 #f)
  class ReadTask1050 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1049;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7mbl1988");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp3H1p1987");
      std::vector<u16> ord1051({1, 2, 3, 0});
      slog::Relation* readrel1052 = db->getRelation("let");
      letindex1049 = readrel1052->getIndex(ord1051, false);
  
    }
    ReadTask1050(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c88 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c98 = _t[0];
        u64 v_c95 = _t[1];
        u64 v_c180 = _t[2];
        u64 v_c97 = _t[3];
        slog::join_probe<4,3>(letindex1049, std::array<u64,4>{v_c87, v_c95, v_c180, 0}, [&](const std::array<u64,4>& m1053) {
          u64 v_c181 = m1053[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c98, v_c181, v_c97});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c88, v_c97, v_c181}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp3H1p1987", _fires);
  
      if (!_done)
      {
        ReadTask1050* _cont = new ReadTask1050(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1050(db,b), false);
  // (crule (pre) (scan eval __t7AlQ821 __t90hH820 rho t) (body (join primref (0 1) 1 __t90hH820 op) (join primitive (0) 1 op)) (head (emit-temp temp9R9Y1810 __t7AlQ821 op) (mkstruct prim (1 0) __t1HR7819 op)) interp.slog:35 #f)
  class ReadTask1056 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primrefindex1054;  slog::Index** primitiveindex1055;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9R9Y1810");
      head_rel[1] = db->getRelation("prim");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1057({0, 1});
      slog::Relation* readrel1058 = db->getRelation("primref");
      primrefindex1054 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({0});
      slog::Relation* readrel1060 = db->getRelation("primitive");
      primitiveindex1055 = readrel1060->getIndex(ord1059, false);
  
    }
    ReadTask1056(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c182 = _t[0];
        u64 v_c183 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        slog::join_probe<2,1>(primrefindex1054, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m1061) {
          u64 v_c156 = m1061[1];
          slog::join_probe<1,1>(primitiveindex1055, std::array<u64,1>{v_c156}, [&](const std::array<u64,1>& m1062) {
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c182, v_c156});
            slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c156}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:35", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1056* _cont = new ReadTask1056(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1056(db,b), false);
  // (crule (pre (let __trid4qD31544 consta9707d158296ad63d61ac4f7) (let __trel07sS1545 const0bbd2fbd1dc4200473343503) (let __tcol16oz1546 const5feceb66ffc86f38d952786c)) (scan lambda __t4vLM557 xs eb) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t4vLM557 rho t __t1OhY558)) (head (tycheck __t4vLM557 (accept (struct lambda)) __trid4qD31544 __trel07sS1545 __tcol16oz1546 (1 2 3 4 0)) (emit-temp temp7xOk1832 __t1OhY558 __t4vLM557 rho) (mkstruct closure (1 2 0) __t7c6K556 __t4vLM557 rho)) interp.slog:33 #f)
  class ReadTask1066 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1063;  slog::Index** evaldelta1064;
    u32 sid1065;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp7xOk1832");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1067({1, 2, 3, 0});
      slog::Relation* readrel1068 = db->getRelation("eval");
      evalindex1063 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 2, 3, 0});
      slog::Relation* readrel1070 = db->getRelation("eval");
      evaldelta1064 = readrel1070->getIndex(ord1069, true);
      sid1065 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask1066(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c184 = v_consta9707d158296ad63d61ac4f7;
      u64 v_c185 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c186 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c187 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c9 = _t[2];
        slog::join_probe_old<4,1>(evalindex1063, evaldelta1064, std::array<u64,4>{v_c187, 0, 0, 0}, [&](const std::array<u64,4>& m1071) {
          u64 v_c2 = m1071[1]; u64 v_c3 = m1071[2]; u64 v_c188 = m1071[3];
          ++_fires;
          if (!((is_struct(v_c187) && (decode_struct_id(v_c187) == sid1065))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c184, v_c185, v_c186, v_c187}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c188, v_c187, v_c2});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c187, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1066* _cont = new ReadTask1066(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1066(db,b), false);
  // (crule (pre (let __trid7eCK1088 const07d7fbed0aba019c07f7eb8a) (let __trel2iiF1089 const20347926ddb307a8e2bdb71b) (let __tcol0Wnu1090 const4e07408562bedb8b60ce05c1)) (scan mp_msk_ans __t9pQc287 p) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t9pQc287 k m) (exists mp_del (2 0 1) 1 k) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t6EHL288) (join-old mp_del_ans (0 1) 1 (0 1) __t6EHL288 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7eCK1088 __trel2iiF1089 __tcol0Wnu1090 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __4RjO1087 p m __v0 r)) map.slog:83 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index1072;  slog::Index** mp_mskindex1073;  slog::Index** mp_delindex1074;  slog::Index** $sup5638x82x0x0x0index1075;  slog::Index** mp_delindex1076;  slog::Index** mp_del_ansindex1077;  slog::Index** mp_mskdelta1078;  slog::Index** mp_deldelta1079;  slog::Index** mp_del_ansdelta1080;
    u32 sid1082;  u32 sid1081;  u32 sid1083;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1085({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1086 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1072 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({0, 1, 2});
      slog::Relation* readrel1088 = db->getRelation("mp_msk");
      mp_mskindex1073 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({0, 1, 2});
      slog::Relation* readrel1090 = db->getRelation("mp_msk");
      mp_mskdelta1078 = readrel1090->getIndex(ord1089, true);
      std::vector<u16> ord1091({2, 0, 1});
      slog::Relation* readrel1092 = db->getRelation("mp_del");
      mp_delindex1074 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1094 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1075 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("mp_del");
      mp_delindex1076 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({1, 2, 0});
      slog::Relation* readrel1098 = db->getRelation("mp_del");
      mp_deldelta1079 = readrel1098->getIndex(ord1097, true);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("mp_del_ans");
      mp_del_ansindex1077 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("mp_del_ans");
      mp_del_ansdelta1080 = readrel1102->getIndex(ord1101, true);
      sid1082 = db->getRelation("_enum")->getStructId();
      sid1081 = db->getRelation("mbranch")->getStructId();
      sid1083 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c189 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c190 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c191 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c192 = _t[0];
        u64 v_c30 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x82x0x0x0index1072, std::array<u64,6>{v_c30, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1073, mp_mskdelta1078, std::array<u64,3>{v_c192, 0, 0}, [&](const std::array<u64,3>& m1103) {
          u64 v_c121 = m1103[1]; u64 v_c29 = m1103[2];
          if (!slog::exists_probe<3,1>(mp_delindex1074, std::array<u64,3>{v_c121, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x82x0x0x0index1075, std::array<u64,6>{v_c121, v_c29, v_c30, 0, 0, 0}, [&](const std::array<u64,6>& m1104) {
            u64 v_c36 = m1104[3]; u64 v_c28 = m1104[4]; u64 v_c31 = m1104[5];
            slog::join_probe_old<3,2>(mp_delindex1076, mp_deldelta1079, std::array<u64,3>{v_c28, v_c121, 0}, [&](const std::array<u64,3>& m1105) {
              u64 v_c193 = m1105[2];
              slog::join_probe_old<2,1>(mp_del_ansindex1077, mp_del_ansdelta1080, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m1106) {
                u64 v_c18 = m1106[1];
                ++_fires;
                if (!((is_struct(v_c31) && (decode_struct_id(v_c31) == sid1081 || decode_struct_id(v_c31) == sid1082 || decode_struct_id(v_c31) == sid1083))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c189, v_c190, v_c191, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c29, v_c18, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mbranch __t5gI3231 p m l r) (body (exists mp_has0 (1 2 0) 1 __t5gI3231) (exists mp_has0 (1 2 0) 1 r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x62x0x0x0 (4 2 3 5 0 1) 4 p l m r __t7cml232 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t7cml232 k __t5gI3231) (exists mp_msk (1 2 0) 2 k m) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t2sXu235) (exists mp_has0_ans (0 1) 1 __t2sXu235) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9BfR236) (join mp_msk_ans (0 1) 2 __t9BfR236 p) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask1122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1107;  slog::Index** mp_has0index1108;  slog::Index** mp_mskindex1109;  slog::Index** mp_msk_ansindex1110;  slog::Index** $sup5638x62x0x0x0index1111;  slog::Index** mp_has0index1112;  slog::Index** mp_mskindex1113;  slog::Index** mp_has0index1114;  slog::Index** mp_has0_ansindex1115;  slog::Index** mp_mskindex1116;  slog::Index** mp_msk_ansindex1117;  slog::Index** mp_has0_ansindex1118;  slog::Index** mp_has0delta1119;  slog::Index** mp_has0delta1120;  slog::Index** mp_mskdelta1121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1123({0, 1});
      slog::Relation* readrel1124 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1124->getIndex(ord1123, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("mp_has0");
      mp_has0index1107 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("mp_has0");
      mp_has0index1108 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({2, 0, 1});
      slog::Relation* readrel1130 = db->getRelation("mp_msk");
      mp_mskindex1109 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 0});
      slog::Relation* readrel1132 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1110 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1134 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1111 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({0, 2, 1});
      slog::Relation* readrel1136 = db->getRelation("mp_has0");
      mp_has0index1112 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({0, 2, 1});
      slog::Relation* readrel1138 = db->getRelation("mp_has0");
      mp_has0delta1119 = readrel1138->getIndex(ord1137, true);
      std::vector<u16> ord1139({1, 2, 0});
      slog::Relation* readrel1140 = db->getRelation("mp_msk");
      mp_mskindex1113 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 2, 0});
      slog::Relation* readrel1142 = db->getRelation("mp_has0");
      mp_has0index1114 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 2, 0});
      slog::Relation* readrel1144 = db->getRelation("mp_has0");
      mp_has0delta1120 = readrel1144->getIndex(ord1143, true);
      std::vector<u16> ord1145({0, 1});
      slog::Relation* readrel1146 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1115 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({1, 2, 0});
      slog::Relation* readrel1148 = db->getRelation("mp_msk");
      mp_mskindex1116 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({1, 2, 0});
      slog::Relation* readrel1150 = db->getRelation("mp_msk");
      mp_mskdelta1121 = readrel1150->getIndex(ord1149, true);
      std::vector<u16> ord1151({0, 1});
      slog::Relation* readrel1152 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1117 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({0, 1});
      slog::Relation* readrel1154 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1118 = readrel1154->getIndex(ord1153, false);
  
    }
    ReadTask1122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c195 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c31 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index1107, std::array<u64,3>{v_c195, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index1108, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1109, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1110, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<6,4>($sup5638x62x0x0x0index1111, std::array<u64,6>{v_c30, v_c28, v_c29, v_c31, 0, 0}, [&](const std::array<u64,6>& m1155) {
          u64 v_c196 = m1155[4]; u64 v_c121 = m1155[5];
          slog::join_probe_old<3,3>(mp_has0index1112, mp_has0delta1119, std::array<u64,3>{v_c196, v_c121, v_c195}, [&](const std::array<u64,3>& m1156) {
            if (!slog::exists_probe<3,2>(mp_mskindex1113, std::array<u64,3>{v_c121, v_c29, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index1114, mp_has0delta1120, std::array<u64,3>{v_c31, v_c121, 0}, [&](const std::array<u64,3>& m1157) {
              u64 v_c197 = m1157[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex1115, std::array<u64,2>{v_c197, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1116, mp_mskdelta1121, std::array<u64,3>{v_c121, v_c29, 0}, [&](const std::array<u64,3>& m1158) {
                u64 v_c198 = m1158[2];
                slog::join_probe<2,2>(mp_msk_ansindex1117, std::array<u64,2>{v_c198, v_c30}, [&](const std::array<u64,2>& m1159) {
                  slog::join_probe<2,1>(mp_has0_ansindex1118, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m1160) {
                    u64 v_c199 = m1160[1];
                    u64 v_c200 = _prim_band(db, v_c121, v_c29);
                    if (v_c200 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c201 = _prim_gt(db, v_c200, v_c194);
                    if (v_c201 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c201) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c196, v_c199}, std::array<u16,2>{0, 1});
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
        ReadTask1122* _cont = new ReadTask1122(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1122(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mp_union __t6Lp3227 r __t5FeR226) (body (exists mp_union (2 0 1) 1 __t5FeR226) (exists mbranch (4 0 1 2 3) 1 r) (exists $sup5638x98x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (join mp_union (2 0 1) 1 __t5FeR226 __t14N0222 __t006N221) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t14N0222 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t14N0222 r) (join mbranch (4 0 1 2 3) 2 r __t006N221 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t14N0222) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t14N0222 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t5FeR226) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t14N0222 n q u v __t4NVE225) (join mbranch (1 2 3 4 0) 5 q n u v __t5FeR226) (join mp_msk (1 2 0) 3 q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask1181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1162;  slog::Index** mbranchindex1163;  slog::Index** $sup5638x98x0x0x0index1164;  slog::Index** $sup5638x98x0x0x1index1165;  slog::Index** mp_union_ansindex1166;  slog::Index** mp_unionindex1167;  slog::Index** $sup5638x98x0x0x0index1168;  slog::Index** $sup5638x98x0x0x1index1169;  slog::Index** mbranchindex1170;  slog::Index** $sup5638x98x0x0x1index1171;  slog::Index** mp_mskindex1172;  slog::Index** mp_msk_ansindex1173;  slog::Index** $sup5638x98x0x0x0index1174;  slog::Index** mbranchindex1175;  slog::Index** mp_mskindex1176;  slog::Index** $sup5638x98x0x0x1index1177;  slog::Index** mbranchindex1178;  slog::Index** mp_mskindex1179;  slog::Index** mp_msk_ansindex1180;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1182({2, 0, 1});
      slog::Relation* readrel1183 = db->getRelation("mp_union");
      mp_unionindex1162 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({4, 0, 1, 2, 3});
      slog::Relation* readrel1185 = db->getRelation("mbranch");
      mbranchindex1163 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1187 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1164 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1189 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1165 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({0, 1});
      slog::Relation* readrel1191 = db->getRelation("mp_union_ans");
      mp_union_ansindex1166 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({2, 0, 1});
      slog::Relation* readrel1193 = db->getRelation("mp_union");
      mp_unionindex1167 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1195 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1168 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel1197 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1169 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({4, 0, 1, 2, 3});
      slog::Relation* readrel1199 = db->getRelation("mbranch");
      mbranchindex1170 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1201 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1171 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({2, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("mp_msk");
      mp_mskindex1172 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 0});
      slog::Relation* readrel1205 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1173 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1207 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1174 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 2, 3, 4, 0});
      slog::Relation* readrel1209 = db->getRelation("mbranch");
      mbranchindex1175 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("mp_msk");
      mp_mskindex1176 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1213 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1177 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 2, 3, 4, 0});
      slog::Relation* readrel1215 = db->getRelation("mbranch");
      mbranchindex1178 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 2, 0});
      slog::Relation* readrel1217 = db->getRelation("mp_msk");
      mp_mskindex1179 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({0, 1});
      slog::Relation* readrel1219 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1180 = readrel1219->getIndex(ord1218, false);
  
    }
    ReadTask1181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c202 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c203 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c204 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex1162, std::array<u64,3>{v_c204, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1163, std::array<u64,5>{v_c31, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index1164, std::array<u64,9>{v_c31, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index1165, std::array<u64,10>{v_c31, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex1166, std::array<u64,2>{v_c203, 0}, [&](const std::array<u64,2>& m1220) {
          u64 v_c18 = m1220[1];
          slog::join_probe<3,1>(mp_unionindex1167, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m1221) {
            u64 v_c205 = m1221[1]; u64 v_c206 = m1221[2];
            if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index1168, std::array<u64,9>{v_c205, v_c31, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index1169, std::array<u64,10>{v_c205, v_c31, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex1170, std::array<u64,5>{v_c31, v_c206, 0, 0, 0}, [&](const std::array<u64,5>& m1222) {
              u64 v_c30 = m1222[2]; u64 v_c29 = m1222[3]; u64 v_c28 = m1222[4];
              if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index1171, std::array<u64,10>{v_c31, v_c28, v_c29, v_c30, v_c205, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex1172, std::array<u64,3>{v_c29, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex1173, std::array<u64,2>{v_c30, 0})) return;
              slog::join_probe<9,5>($sup5638x98x0x0x0index1174, std::array<u64,9>{v_c30, v_c28, v_c29, v_c31, v_c205, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1223) {
                u64 v_c27 = m1223[5]; u64 v_c26 = m1223[6]; u64 v_c24 = m1223[7]; u64 v_c19 = m1223[8];
                u64 v_c207 = _prim_lt(db, v_c27, v_c29);
                if (v_c207 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                if (!v_c207) return;
                if (!slog::exists_probe<5,5>(mbranchindex1175, std::array<u64,5>{v_c26, v_c27, v_c24, v_c19, v_c204})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex1176, std::array<u64,3>{v_c26, v_c29, 0})) return;
                slog::join_probe<10,9>($sup5638x98x0x0x1index1177, std::array<u64,10>{v_c31, v_c28, v_c29, v_c30, v_c205, v_c27, v_c26, v_c24, v_c19, 0}, [&](const std::array<u64,10>& m1225) {
                  u64 v_c208 = m1225[9];
                  slog::join_probe<5,5>(mbranchindex1178, std::array<u64,5>{v_c26, v_c27, v_c24, v_c19, v_c204}, [&](const std::array<u64,5>& m1226) {
                    slog::join_probe<3,3>(mp_mskindex1179, std::array<u64,3>{v_c26, v_c29, v_c208}, [&](const std::array<u64,3>& m1227) {
                      slog::join_probe<2,2>(mp_msk_ansindex1180, std::array<u64,2>{v_c208, v_c30}, [&](const std::array<u64,2>& m1228) {
                        u64 v_c209 = _prim_band(db, v_c26, v_c29);
                        if (v_c209 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c210 = _prim_gt(db, v_c209, v_c202);
                        if (v_c210 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c210) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c205, v_c18, v_c28, v_c29, v_c30});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c29, v_c28, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1181* _cont = new ReadTask1181(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1181(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_hsb __t8x7Q785 __t1znr789) (body (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t8x7Q785) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 1 __t8x7Q785) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v3) (exists $sup5638x29x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t8x7Q785 __v3) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v1) (exists $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t8x7Q785 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t8x7Q785 __v0) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t8x7Q785 __v0 __v3 __v1 __t7O3e781 dup6QI21998 dup4FCe1999 p0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join mp_msk (1 2 0) 2 p0 __v1 __t4ZDq788) (join mp_msk_ans (0 1) 1 __t4ZDq788 __v2) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782) (let chk3Zwq2000 (bxor p0 p1)) (eq __t1znr789 chk3Zwq2000)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask1247 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1230;  slog::Index** $sup5638x29x0x0x2index1231;  slog::Index** $sup5638x29x0x0x1index1232;  slog::Index** mp_hsb_ansindex1233;  slog::Index** $sup5638x29x0x0x2index1234;  slog::Index** mp_hsb_ansindex1235;  slog::Index** $sup5638x29x0x0x2index1236;  slog::Index** mp_mskindex1237;  slog::Index** mp_hsb_ansindex1238;  slog::Index** $sup5638x29x0x0x1index1239;  slog::Index** $sup5638x29x0x0x2index1240;  slog::Index** $sup5638x29x0x0x1index1241;  slog::Index** $sup5638x29x0x0x0index1242;  slog::Index** mp_joinindex1243;  slog::Index** mp_mskindex1244;  slog::Index** mp_msk_ansindex1245;  slog::Index** mp_joindelta1246;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord1248({0, 1});
      slog::Relation* readrel1249 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1230 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1251 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1231 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1253 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1232 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({0, 1});
      slog::Relation* readrel1255 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1233 = readrel1255->getIndex(ord1254, false);
      std::vector<u16> ord1256({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel1257 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1234 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({0, 1});
      slog::Relation* readrel1259 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1235 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1261 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1236 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({2, 0, 1});
      slog::Relation* readrel1263 = db->getRelation("mp_msk");
      mp_mskindex1237 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({0, 1});
      slog::Relation* readrel1265 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1238 = readrel1265->getIndex(ord1264, false);
      std::vector<u16> ord1266({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1267 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1239 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1269 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1240 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1271 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1241 = readrel1271->getIndex(ord1270, false);
      std::vector<u16> ord1272({1, 0, 2, 3, 4});
      slog::Relation* readrel1273 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1242 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({1, 2, 3, 4, 0});
      slog::Relation* readrel1275 = db->getRelation("mp_join");
      mp_joinindex1243 = readrel1275->getIndex(ord1274, false);
      std::vector<u16> ord1276({1, 2, 3, 4, 0});
      slog::Relation* readrel1277 = db->getRelation("mp_join");
      mp_joindelta1246 = readrel1277->getIndex(ord1276, true);
      std::vector<u16> ord1278({1, 2, 0});
      slog::Relation* readrel1279 = db->getRelation("mp_msk");
      mp_mskindex1244 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({0, 1});
      slog::Relation* readrel1281 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1245 = readrel1281->getIndex(ord1280, false);
  
    }
    ReadTask1247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c145 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c147 = _t[0];
        u64 v_c151 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1230, std::array<u64,2>{v_c147, 0})) return;
        if (!slog::exists_probe<11,1>($sup5638x29x0x0x2index1231, std::array<u64,11>{v_c147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index1232, std::array<u64,7>{v_c147, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex1233, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1282) {
          u64 v_c68 = m1282[1];
          if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index1234, std::array<u64,11>{v_c147, v_c68, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex1235, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1283) {
            u64 v_c69 = m1283[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index1236, std::array<u64,11>{v_c147, v_c69, v_c68, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex1237, std::array<u64,3>{v_c69, 0, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex1238, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1284) {
              u64 v_c18 = m1284[1];
              if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index1239, std::array<u64,7>{v_c147, v_c18, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup5638x29x0x0x2index1240, std::array<u64,11>{v_c147, v_c18, v_c68, v_c69, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1285) {
                u64 v_c146 = m1285[4]; u64 v_c148 = m1285[5]; u64 v_c149 = m1285[6]; u64 v_c63 = m1285[7]; u64 v_c64 = m1285[8]; u64 v_c65 = m1285[9]; u64 v_c66 = m1285[10];
                if (v_c147 != v_c149) return;
                if (v_c147 != v_c148) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index1241, std::array<u64,7>{v_c146, v_c63, v_c64, v_c65, v_c66, v_c147, v_c18}, [&](const std::array<u64,7>& m1286) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index1242, std::array<u64,5>{v_c63, v_c146, v_c64, v_c65, v_c66}, [&](const std::array<u64,5>& m1287) {
                    slog::join_probe_old<5,5>(mp_joinindex1243, mp_joindelta1246, std::array<u64,5>{v_c63, v_c65, v_c64, v_c66, v_c146}, [&](const std::array<u64,5>& m1288) {
                      slog::join_probe<3,2>(mp_mskindex1244, std::array<u64,3>{v_c63, v_c69, 0}, [&](const std::array<u64,3>& m1289) {
                        u64 v_c150 = m1289[2];
                        slog::join_probe<2,1>(mp_msk_ansindex1245, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m1290) {
                          u64 v_c110 = m1290[1];
                          u64 v_c152 = _prim_band(db, v_c63, v_c18);
                          if (v_c152 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c211 = _prim_gt(db, v_c152, v_c145);
                          if (v_c211 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c211) return;
                          u64 v_c212 = _prim_bxor(db, v_c63, v_c64);
                          if (v_c212 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (v_c151 != v_c212) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c146, v_c110, v_c68, v_c65, v_c66});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c68, v_c66, v_c65}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1247* _cont = new ReadTask1247(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1247(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t7PVf147 q) (body (exists $sup5638x104x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t7PVf147 q) (exists $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists mbranch (1 2 3 4 0) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t7PVf147 p n) (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists mbranch (1 2 3 4 0) 2 q n) (exists mbranch (1 2 3 4 0) 1 p) (join-old $sup5638x104x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t7PVf147 n p q __t0kfV144 l m r u v) (cmp lt m n) (join-old $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t0kfV144 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 1 u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2NO6142) (exists mp_union (2 0 1) 2 __t2NO6142 __t0kfV144) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_union (0 1 2) 3 (0 1 2) __t0kfV144 __t5mfE148 __t2NO6142) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join-old mp_union_ans (0 1) 1 (0 1) __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask1317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index1292;  slog::Index** $sup5638x104x0x0x0index1293;  slog::Index** mbranchindex1294;  slog::Index** mp_mskindex1295;  slog::Index** $sup5638x104x0x0x0index1296;  slog::Index** mbranchindex1297;  slog::Index** mbranchindex1298;  slog::Index** $sup5638x104x0x0x1index1299;  slog::Index** $sup5638x104x0x0x0index1300;  slog::Index** mbranchindex1301;  slog::Index** mp_unionindex1302;  slog::Index** mbranchindex1303;  slog::Index** mp_unionindex1304;  slog::Index** mbranchindex1305;  slog::Index** mp_unionindex1306;  slog::Index** mp_unionindex1307;  slog::Index** mp_union_ansindex1308;  slog::Index** mp_mskdelta1309;  slog::Index** $sup5638x104x0x0x1delta1310;  slog::Index** $sup5638x104x0x0x0delta1311;  slog::Index** mbranchdelta1312;  slog::Index** mbranchdelta1313;  slog::Index** mp_uniondelta1314;  slog::Index** mp_uniondelta1315;  slog::Index** mp_union_ansdelta1316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1318({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel1319 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index1292 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1321 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index1293 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({1, 2, 3, 4, 0});
      slog::Relation* readrel1323 = db->getRelation("mbranch");
      mbranchindex1294 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({0, 1, 2});
      slog::Relation* readrel1325 = db->getRelation("mp_msk");
      mp_mskindex1295 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({0, 1, 2});
      slog::Relation* readrel1327 = db->getRelation("mp_msk");
      mp_mskdelta1309 = readrel1327->getIndex(ord1326, true);
      std::vector<u16> ord1328({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel1329 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index1296 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 2, 3, 4, 0});
      slog::Relation* readrel1331 = db->getRelation("mbranch");
      mbranchindex1297 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({1, 2, 3, 4, 0});
      slog::Relation* readrel1333 = db->getRelation("mbranch");
      mbranchindex1298 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel1335 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index1299 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel1337 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta1310 = readrel1337->getIndex(ord1336, true);
      std::vector<u16> ord1338({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1339 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index1300 = readrel1339->getIndex(ord1338, false);
      std::vector<u16> ord1340({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1341 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0delta1311 = readrel1341->getIndex(ord1340, true);
      std::vector<u16> ord1342({1, 2, 3, 4, 0});
      slog::Relation* readrel1343 = db->getRelation("mbranch");
      mbranchindex1301 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({2, 0, 1});
      slog::Relation* readrel1345 = db->getRelation("mp_union");
      mp_unionindex1302 = readrel1345->getIndex(ord1344, false);
      std::vector<u16> ord1346({1, 2, 3, 4, 0});
      slog::Relation* readrel1347 = db->getRelation("mbranch");
      mbranchindex1303 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 3, 4, 0});
      slog::Relation* readrel1349 = db->getRelation("mbranch");
      mbranchdelta1312 = readrel1349->getIndex(ord1348, true);
      std::vector<u16> ord1350({2, 0, 1});
      slog::Relation* readrel1351 = db->getRelation("mp_union");
      mp_unionindex1304 = readrel1351->getIndex(ord1350, false);
      std::vector<u16> ord1352({1, 2, 3, 4, 0});
      slog::Relation* readrel1353 = db->getRelation("mbranch");
      mbranchindex1305 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 2, 3, 4, 0});
      slog::Relation* readrel1355 = db->getRelation("mbranch");
      mbranchdelta1313 = readrel1355->getIndex(ord1354, true);
      std::vector<u16> ord1356({0, 1, 2});
      slog::Relation* readrel1357 = db->getRelation("mp_union");
      mp_unionindex1306 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({0, 1, 2});
      slog::Relation* readrel1359 = db->getRelation("mp_union");
      mp_uniondelta1314 = readrel1359->getIndex(ord1358, true);
      std::vector<u16> ord1360({1, 2, 0});
      slog::Relation* readrel1361 = db->getRelation("mp_union");
      mp_unionindex1307 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({1, 2, 0});
      slog::Relation* readrel1363 = db->getRelation("mp_union");
      mp_uniondelta1315 = readrel1363->getIndex(ord1362, true);
      std::vector<u16> ord1364({0, 1});
      slog::Relation* readrel1365 = db->getRelation("mp_union_ans");
      mp_union_ansindex1308 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({0, 1});
      slog::Relation* readrel1367 = db->getRelation("mp_union_ans");
      mp_union_ansdelta1316 = readrel1367->getIndex(ord1366, true);
  
    }
    ReadTask1317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[0];
        u64 v_c26 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index1292, std::array<u64,10>{v_c33, v_c26, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index1293, std::array<u64,9>{v_c26, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1294, std::array<u64,5>{v_c26, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1295, mp_mskdelta1309, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m1368) {
          u64 v_c30 = m1368[1]; u64 v_c27 = m1368[2];
          if (!slog::exists_probe<9,3>($sup5638x104x0x0x0index1296, std::array<u64,9>{v_c27, v_c30, v_c26, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex1297, std::array<u64,5>{v_c26, v_c27, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1298, std::array<u64,5>{v_c30, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x104x0x0x1index1299, $sup5638x104x0x0x1delta1310, std::array<u64,10>{v_c33, v_c27, v_c30, v_c26, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1369) {
            u64 v_c21 = m1369[4]; u64 v_c28 = m1369[5]; u64 v_c29 = m1369[6]; u64 v_c31 = m1369[7]; u64 v_c24 = m1369[8]; u64 v_c19 = m1369[9];
            u64 v_c213 = _prim_lt(db, v_c29, v_c27);
            if (v_c213 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c213) return;
            slog::join_probe_old<9,9>($sup5638x104x0x0x0index1300, $sup5638x104x0x0x0delta1311, std::array<u64,9>{v_c26, v_c27, v_c24, v_c19, v_c21, v_c28, v_c29, v_c30, v_c31}, [&](const std::array<u64,9>& m1371) {
              if (!slog::exists_probe<5,4>(mbranchindex1301, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex1302, std::array<u64,3>{v_c24, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex1303, mbranchdelta1312, std::array<u64,5>{v_c26, v_c27, v_c24, v_c19, 0}, [&](const std::array<u64,5>& m1372) {
                u64 v_c23 = m1372[4];
                if (!slog::exists_probe<3,2>(mp_unionindex1304, std::array<u64,3>{v_c23, v_c21, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex1305, mbranchdelta1313, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, 0}, [&](const std::array<u64,5>& m1373) {
                  u64 v_c22 = m1373[4];
                  slog::join_probe_old<3,3>(mp_unionindex1306, mp_uniondelta1314, std::array<u64,3>{v_c21, v_c22, v_c23}, [&](const std::array<u64,3>& m1374) {
                    slog::join_probe_old<3,2>(mp_unionindex1307, mp_uniondelta1315, std::array<u64,3>{v_c22, v_c24, 0}, [&](const std::array<u64,3>& m1375) {
                      u64 v_c25 = m1375[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex1308, mp_union_ansdelta1316, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1376) {
                        u64 v_c18 = m1376[1];
                        u64 v_c34 = _prim_band(db, v_c30, v_c27);
                        if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c214 = _prim_lt(db, v_c34, v_c20);
                        if (v_c214 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c214) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c21, v_c18, v_c27, v_c26, v_c19});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c26, v_c27, v_c18, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1317* _cont = new ReadTask1317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1317(db,b), false);
  // (crule (pre) (scan $sup5638x110x0x0x0 __t5Qtl389 l m n p q r __t6AX6390 __t46nL391 u v) (body (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6AX6390) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t46nL391) (exists mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t6AX6390 q __t46nL391 __t6UVn392) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_join_ans (0 1) 1 __t6UVn392) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1393 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1378;  slog::Index** mbranchindex1379;  slog::Index** mp_unionindex1380;  slog::Index** mp_mskindex1381;  slog::Index** mp_joinindex1382;  slog::Index** mp_unionindex1383;  slog::Index** mp_join_ansindex1384;  slog::Index** mp_mskindex1385;  slog::Index** mp_msk_ansindex1386;  slog::Index** mp_join_ansindex1387;  slog::Index** mbranchdelta1388;  slog::Index** mbranchdelta1389;  slog::Index** mp_joindelta1390;  slog::Index** mp_uniondelta1391;  slog::Index** mp_mskdelta1392;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1394({0, 1});
      slog::Relation* readrel1395 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1395->getIndex(ord1394, false);
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord1396({1, 2, 3, 4, 0});
      slog::Relation* readrel1397 = db->getRelation("mbranch");
      mbranchindex1378 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({1, 2, 3, 4, 0});
      slog::Relation* readrel1399 = db->getRelation("mbranch");
      mbranchdelta1388 = readrel1399->getIndex(ord1398, true);
      std::vector<u16> ord1400({1, 2, 3, 4, 0});
      slog::Relation* readrel1401 = db->getRelation("mbranch");
      mbranchindex1379 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({1, 2, 3, 4, 0});
      slog::Relation* readrel1403 = db->getRelation("mbranch");
      mbranchdelta1389 = readrel1403->getIndex(ord1402, true);
      std::vector<u16> ord1404({0, 1, 2});
      slog::Relation* readrel1405 = db->getRelation("mp_union");
      mp_unionindex1380 = readrel1405->getIndex(ord1404, false);
      std::vector<u16> ord1406({1, 2, 0});
      slog::Relation* readrel1407 = db->getRelation("mp_msk");
      mp_mskindex1381 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({1, 2, 3, 4, 0});
      slog::Relation* readrel1409 = db->getRelation("mp_join");
      mp_joinindex1382 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({1, 2, 3, 4, 0});
      slog::Relation* readrel1411 = db->getRelation("mp_join");
      mp_joindelta1390 = readrel1411->getIndex(ord1410, true);
      std::vector<u16> ord1412({0, 1, 2});
      slog::Relation* readrel1413 = db->getRelation("mp_union");
      mp_unionindex1383 = readrel1413->getIndex(ord1412, false);
      std::vector<u16> ord1414({0, 1, 2});
      slog::Relation* readrel1415 = db->getRelation("mp_union");
      mp_uniondelta1391 = readrel1415->getIndex(ord1414, true);
      std::vector<u16> ord1416({0, 1});
      slog::Relation* readrel1417 = db->getRelation("mp_join_ans");
      mp_join_ansindex1384 = readrel1417->getIndex(ord1416, false);
      std::vector<u16> ord1418({1, 2, 0});
      slog::Relation* readrel1419 = db->getRelation("mp_msk");
      mp_mskindex1385 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({1, 2, 0});
      slog::Relation* readrel1421 = db->getRelation("mp_msk");
      mp_mskdelta1392 = readrel1421->getIndex(ord1420, true);
      std::vector<u16> ord1422({0, 1});
      slog::Relation* readrel1423 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1386 = readrel1423->getIndex(ord1422, false);
      std::vector<u16> ord1424({0, 1});
      slog::Relation* readrel1425 = db->getRelation("mp_join_ans");
      mp_join_ansindex1387 = readrel1425->getIndex(ord1424, false);
  
    }
    ReadTask1393(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c215 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c26 = _t[5];
        u64 v_c31 = _t[6];
        u64 v_c216 = _t[7];
        u64 v_c217 = _t[8];
        u64 v_c24 = _t[9];
        u64 v_c19 = _t[10];
        u64 v_c218 = _prim_lt(db, v_c29, v_c27);
        if (v_c218 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
        if (!v_c218) return;
        slog::join_probe_old<5,5>(mbranchindex1378, mbranchdelta1388, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, v_c216}, [&](const std::array<u64,5>& m1427) {
          slog::join_probe_old<5,5>(mbranchindex1379, mbranchdelta1389, std::array<u64,5>{v_c26, v_c27, v_c24, v_c19, v_c217}, [&](const std::array<u64,5>& m1428) {
            if (!slog::exists_probe<3,3>(mp_unionindex1380, std::array<u64,3>{v_c215, v_c216, v_c217})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1381, std::array<u64,3>{v_c30, v_c27, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex1382, mp_joindelta1390, std::array<u64,5>{v_c30, v_c216, v_c26, v_c217, 0}, [&](const std::array<u64,5>& m1429) {
              u64 v_c219 = m1429[4];
              slog::join_probe_old<3,3>(mp_unionindex1383, mp_uniondelta1391, std::array<u64,3>{v_c215, v_c216, v_c217}, [&](const std::array<u64,3>& m1430) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex1384, std::array<u64,2>{v_c219, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex1385, mp_mskdelta1392, std::array<u64,3>{v_c30, v_c27, 0}, [&](const std::array<u64,3>& m1431) {
                  u64 v_c220 = m1431[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1386, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1432) {
                    u64 v_c18 = m1432[1];
                    if (v_c26 == v_c18) return;
                    slog::join_probe<2,1>(mp_join_ansindex1387, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m1433) {
                      u64 v_c221 = m1433[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c215, v_c221}, std::array<u16,2>{0, 1});
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
        ReadTask1393* _cont = new ReadTask1393(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1393(db,b), false);
  // (crule (pre) (scan mbranch __t3dlR26 q m u v) (body (exists mbranch (2 0 1 3 4) 1 m) (exists mp_union (2 0 1) 1 __t3dlR26) (join-old mp_join (3 4 1 0 2) 2 (3 4 1 0 2) q __t3dlR26 p __t77mZ27 __t7Hza25) (neq p q) (exists mp_union (1 2 0) 2 __t7Hza25 __t3dlR26) (exists mp_join_ans (0 1) 1 __t77mZ27) (join mbranch (0 1 2 3 4) 3 __t7Hza25 p m l r) (join mp_union (1 2 0) 2 __t7Hza25 __t3dlR26 __t2vfE24) (join mp_join_ans (0 1) 1 __t77mZ27 res)) (head (emit mp_union_ans (0 1) __t2vfE24 res)) map.slog:114 #f)
  class ReadTask1443 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1434;  slog::Index** mp_unionindex1435;  slog::Index** mp_joinindex1436;  slog::Index** mp_unionindex1437;  slog::Index** mp_join_ansindex1438;  slog::Index** mbranchindex1439;  slog::Index** mp_unionindex1440;  slog::Index** mp_join_ansindex1441;  slog::Index** mp_joindelta1442;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1444({0, 1});
      slog::Relation* readrel1445 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1445->getIndex(ord1444, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1446({2, 0, 1, 3, 4});
      slog::Relation* readrel1447 = db->getRelation("mbranch");
      mbranchindex1434 = readrel1447->getIndex(ord1446, false);
      std::vector<u16> ord1448({2, 0, 1});
      slog::Relation* readrel1449 = db->getRelation("mp_union");
      mp_unionindex1435 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({3, 4, 1, 0, 2});
      slog::Relation* readrel1451 = db->getRelation("mp_join");
      mp_joinindex1436 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({3, 4, 1, 0, 2});
      slog::Relation* readrel1453 = db->getRelation("mp_join");
      mp_joindelta1442 = readrel1453->getIndex(ord1452, true);
      std::vector<u16> ord1454({1, 2, 0});
      slog::Relation* readrel1455 = db->getRelation("mp_union");
      mp_unionindex1437 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({0, 1});
      slog::Relation* readrel1457 = db->getRelation("mp_join_ans");
      mp_join_ansindex1438 = readrel1457->getIndex(ord1456, false);
      std::vector<u16> ord1458({0, 1, 2, 3, 4});
      slog::Relation* readrel1459 = db->getRelation("mbranch");
      mbranchindex1439 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 2, 0});
      slog::Relation* readrel1461 = db->getRelation("mp_union");
      mp_unionindex1440 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({0, 1});
      slog::Relation* readrel1463 = db->getRelation("mp_join_ans");
      mp_join_ansindex1441 = readrel1463->getIndex(ord1462, false);
  
    }
    ReadTask1443(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c222 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex1434, std::array<u64,5>{v_c29, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1435, std::array<u64,3>{v_c222, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex1436, mp_joindelta1442, std::array<u64,5>{v_c26, v_c222, 0, 0, 0}, [&](const std::array<u64,5>& m1464) {
          u64 v_c30 = m1464[2]; u64 v_c223 = m1464[3]; u64 v_c224 = m1464[4];
          if (v_c30 == v_c26) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1437, std::array<u64,3>{v_c224, v_c222, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex1438, std::array<u64,2>{v_c223, 0})) return;
          slog::join_probe<5,3>(mbranchindex1439, std::array<u64,5>{v_c224, v_c30, v_c29, 0, 0}, [&](const std::array<u64,5>& m1465) {
            u64 v_c28 = m1465[3]; u64 v_c31 = m1465[4];
            slog::join_probe<3,2>(mp_unionindex1440, std::array<u64,3>{v_c224, v_c222, 0}, [&](const std::array<u64,3>& m1466) {
              u64 v_c225 = m1466[2];
              slog::join_probe<2,1>(mp_join_ansindex1441, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1467) {
                u64 v_c221 = m1467[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c225, v_c221}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1443* _cont = new ReadTask1443(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1443(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp4eez1903 __t1WhI754 __t2X4e744 __t5Neo735 __t5xOK723 __t8k6P758) (body (exists app (2 0 1) 1 __t5Neo735) (join ref (1 0) 1 __tconst6I9K760 __t9NO9722) (join app (1 2 0) 2 __t9NO9722 __t5Neo735 __t7vYe738)) (head (emit-temp temp8oJc1904 __t1WhI754 __t2X4e744 __t5xOK723 __t7vYe738 __t8k6P758) (mkstruct if (1 3 2 0) __t8UvH755 __t1WhI754 __t7vYe738 __t2X4e744)) kcfa.slog:70 #f)
  class ReadTask1471 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1468;  slog::Index** refindex1469;  slog::Index** appindex1470;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8oJc1904");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp4eez1903");
      std::vector<u16> ord1472({2, 0, 1});
      slog::Relation* readrel1473 = db->getRelation("app");
      appindex1468 = readrel1473->getIndex(ord1472, false);
      std::vector<u16> ord1474({1, 0});
      slog::Relation* readrel1475 = db->getRelation("ref");
      refindex1469 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({1, 2, 0});
      slog::Relation* readrel1477 = db->getRelation("app");
      appindex1470 = readrel1477->getIndex(ord1476, false);
  
    }
    ReadTask1471(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c226 = v_constd59eced1ded07f84c145592f;
  
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
        u64 v_c228 = _t[1];
        u64 v_c229 = _t[2];
        u64 v_c230 = _t[3];
        u64 v_c231 = _t[4];
        if (!slog::exists_probe<3,1>(appindex1468, std::array<u64,3>{v_c229, 0, 0})) return;
        slog::join_probe<2,1>(refindex1469, std::array<u64,2>{v_c226, 0}, [&](const std::array<u64,2>& m1478) {
          u64 v_c232 = m1478[1];
          slog::join_probe<3,2>(appindex1470, std::array<u64,3>{v_c232, v_c229, 0}, [&](const std::array<u64,3>& m1479) {
            u64 v_c233 = m1479[2];
            ++_fires;
            slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c227, v_c228, v_c230, v_c233, v_c231});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c227, v_c233, v_c228}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp4eez1903", _fires);
  
      if (!_done)
      {
        ReadTask1471* _cont = new ReadTask1471(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1471(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t4ZDq788 __v2) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t4ZDq788 p0 __v1) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x29x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join-old mp_hsb_ans (1 0) 1 (1 0) __v1 __t8x7Q785) (exists $sup5638x29x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t8x7Q785) (exists $sup5638x29x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t8x7Q785) (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v3) (join $sup5638x29x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t8x7Q785 __v1 __v3 p0 __t7O3e781 dup6QI21998 dup4FCe1999 __v0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v0) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask1501 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex1480;  slog::Index** $sup5638x29x0x0x2index1481;  slog::Index** $sup5638x29x0x0x1index1482;  slog::Index** $sup5638x29x0x0x0index1483;  slog::Index** mp_joinindex1484;  slog::Index** mp_hsb_ansindex1485;  slog::Index** $sup5638x29x0x0x2index1486;  slog::Index** $sup5638x29x0x0x1index1487;  slog::Index** mp_hsb_ansindex1488;  slog::Index** mp_hsb_ansindex1489;  slog::Index** $sup5638x29x0x0x2index1490;  slog::Index** $sup5638x29x0x0x1index1491;  slog::Index** $sup5638x29x0x0x0index1492;  slog::Index** mp_joinindex1493;  slog::Index** mp_hsb_ansindex1494;  slog::Index** mp_hsbindex1495;  slog::Index** mp_mskdelta1496;  slog::Index** mp_hsb_ansdelta1497;  slog::Index** mp_joindelta1498;  slog::Index** mp_hsb_ansdelta1499;  slog::Index** mp_hsbdelta1500;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1502({0, 1, 2});
      slog::Relation* readrel1503 = db->getRelation("mp_msk");
      mp_mskindex1480 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({0, 1, 2});
      slog::Relation* readrel1505 = db->getRelation("mp_msk");
      mp_mskdelta1496 = readrel1505->getIndex(ord1504, true);
      std::vector<u16> ord1506({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel1507 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1481 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel1509 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1482 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({1, 0, 2, 3, 4});
      slog::Relation* readrel1511 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1483 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 2, 3, 4, 0});
      slog::Relation* readrel1513 = db->getRelation("mp_join");
      mp_joinindex1484 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({1, 0});
      slog::Relation* readrel1515 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1485 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 0});
      slog::Relation* readrel1517 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1497 = readrel1517->getIndex(ord1516, true);
      std::vector<u16> ord1518({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel1519 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1486 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel1521 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1487 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({0, 1});
      slog::Relation* readrel1523 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1488 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({0, 1});
      slog::Relation* readrel1525 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1489 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1527 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1490 = readrel1527->getIndex(ord1526, false);
      std::vector<u16> ord1528({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1529 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1491 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({1, 0, 2, 3, 4});
      slog::Relation* readrel1531 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1492 = readrel1531->getIndex(ord1530, false);
      std::vector<u16> ord1532({1, 2, 3, 4, 0});
      slog::Relation* readrel1533 = db->getRelation("mp_join");
      mp_joinindex1493 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 2, 3, 4, 0});
      slog::Relation* readrel1535 = db->getRelation("mp_join");
      mp_joindelta1498 = readrel1535->getIndex(ord1534, true);
      std::vector<u16> ord1536({0, 1});
      slog::Relation* readrel1537 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1494 = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({0, 1});
      slog::Relation* readrel1539 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1499 = readrel1539->getIndex(ord1538, true);
      std::vector<u16> ord1540({0, 1});
      slog::Relation* readrel1541 = db->getRelation("mp_hsb");
      mp_hsbindex1495 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({0, 1});
      slog::Relation* readrel1543 = db->getRelation("mp_hsb");
      mp_hsbdelta1500 = readrel1543->getIndex(ord1542, true);
  
    }
    ReadTask1501(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c145 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c150 = _t[0];
        u64 v_c110 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex1480, mp_mskdelta1496, std::array<u64,3>{v_c150, 0, 0}, [&](const std::array<u64,3>& m1544) {
          u64 v_c63 = m1544[1]; u64 v_c69 = m1544[2];
          if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index1481, std::array<u64,11>{v_c69, v_c63, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup5638x29x0x0x1index1482, std::array<u64,7>{v_c63, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup5638x29x0x0x0index1483, std::array<u64,5>{v_c63, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex1484, std::array<u64,5>{v_c63, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex1485, mp_hsb_ansdelta1497, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m1545) {
            u64 v_c147 = m1545[1];
            if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index1486, std::array<u64,11>{v_c69, v_c63, v_c147, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index1487, std::array<u64,7>{v_c63, v_c147, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex1488, std::array<u64,2>{v_c147, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex1489, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1546) {
              u64 v_c68 = m1546[1];
              slog::join_probe<11,4>($sup5638x29x0x0x2index1490, std::array<u64,11>{v_c147, v_c69, v_c68, v_c63, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1547) {
                u64 v_c146 = m1547[4]; u64 v_c148 = m1547[5]; u64 v_c149 = m1547[6]; u64 v_c18 = m1547[7]; u64 v_c64 = m1547[8]; u64 v_c65 = m1547[9]; u64 v_c66 = m1547[10];
                if (v_c147 != v_c149) return;
                if (v_c147 != v_c148) return;
                slog::join_probe<7,7>($sup5638x29x0x0x1index1491, std::array<u64,7>{v_c146, v_c63, v_c64, v_c65, v_c66, v_c147, v_c18}, [&](const std::array<u64,7>& m1548) {
                  slog::join_probe<5,5>($sup5638x29x0x0x0index1492, std::array<u64,5>{v_c63, v_c146, v_c64, v_c65, v_c66}, [&](const std::array<u64,5>& m1549) {
                    slog::join_probe_old<5,5>(mp_joinindex1493, mp_joindelta1498, std::array<u64,5>{v_c63, v_c65, v_c64, v_c66, v_c146}, [&](const std::array<u64,5>& m1550) {
                      slog::join_probe_old<2,2>(mp_hsb_ansindex1494, mp_hsb_ansdelta1499, std::array<u64,2>{v_c147, v_c18}, [&](const std::array<u64,2>& m1551) {
                        u64 v_c151 = _prim_bxor(db, v_c63, v_c64);
                        if (v_c151 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1495, mp_hsbdelta1500, std::array<u64,2>{v_c147, v_c151}, [&](const std::array<u64,2>& m1552) {
                          u64 v_c152 = _prim_band(db, v_c63, v_c18);
                          if (v_c152 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c234 = _prim_gt(db, v_c152, v_c145);
                          if (v_c234 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c234) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c146, v_c110, v_c68, v_c65, v_c66});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c68, v_c66, v_c65}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre) (scan $sup5638x81x0x0x0 __t5Y7y396 k l m p r) (body (exists mp_del (0 2 1) 2 __t5Y7y396 k) (exists mp_msk (1 2 0) 2 k m) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8pu9395) (join-old mp_del (0 2 1) 3 (0 2 1) __t5Y7y396 k __t8pu9395) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t0MS8397) (join mp_msk_ans (0 1) 1 __t0MS8397 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t5Y7y396 __t8pu9395)) map.slog:82 #f)
  class ReadTask1563 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex1554;  slog::Index** mp_mskindex1555;  slog::Index** mbranchindex1556;  slog::Index** mp_delindex1557;  slog::Index** mp_mskindex1558;  slog::Index** mp_msk_ansindex1559;  slog::Index** mbranchdelta1560;  slog::Index** mp_deldelta1561;  slog::Index** mp_mskdelta1562;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1564({0, 1});
      slog::Relation* readrel1565 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1565->getIndex(ord1564, false);
      outer_rel = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord1566({0, 2, 1});
      slog::Relation* readrel1567 = db->getRelation("mp_del");
      mp_delindex1554 = readrel1567->getIndex(ord1566, false);
      std::vector<u16> ord1568({1, 2, 0});
      slog::Relation* readrel1569 = db->getRelation("mp_msk");
      mp_mskindex1555 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({1, 2, 3, 4, 0});
      slog::Relation* readrel1571 = db->getRelation("mbranch");
      mbranchindex1556 = readrel1571->getIndex(ord1570, false);
      std::vector<u16> ord1572({1, 2, 3, 4, 0});
      slog::Relation* readrel1573 = db->getRelation("mbranch");
      mbranchdelta1560 = readrel1573->getIndex(ord1572, true);
      std::vector<u16> ord1574({0, 2, 1});
      slog::Relation* readrel1575 = db->getRelation("mp_del");
      mp_delindex1557 = readrel1575->getIndex(ord1574, false);
      std::vector<u16> ord1576({0, 2, 1});
      slog::Relation* readrel1577 = db->getRelation("mp_del");
      mp_deldelta1561 = readrel1577->getIndex(ord1576, true);
      std::vector<u16> ord1578({1, 2, 0});
      slog::Relation* readrel1579 = db->getRelation("mp_msk");
      mp_mskindex1558 = readrel1579->getIndex(ord1578, false);
      std::vector<u16> ord1580({1, 2, 0});
      slog::Relation* readrel1581 = db->getRelation("mp_msk");
      mp_mskdelta1562 = readrel1581->getIndex(ord1580, true);
      std::vector<u16> ord1582({0, 1});
      slog::Relation* readrel1583 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1559 = readrel1583->getIndex(ord1582, false);
  
    }
    ReadTask1563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c31 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex1554, std::array<u64,3>{v_c235, v_c121, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex1555, std::array<u64,3>{v_c121, v_c29, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex1556, mbranchdelta1560, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, 0}, [&](const std::array<u64,5>& m1584) {
          u64 v_c236 = m1584[4];
          slog::join_probe_old<3,3>(mp_delindex1557, mp_deldelta1561, std::array<u64,3>{v_c235, v_c121, v_c236}, [&](const std::array<u64,3>& m1585) {
            slog::join_probe_old<3,2>(mp_mskindex1558, mp_mskdelta1562, std::array<u64,3>{v_c121, v_c29, 0}, [&](const std::array<u64,3>& m1586) {
              u64 v_c237 = m1586[2];
              slog::join_probe<2,1>(mp_msk_ansindex1559, std::array<u64,2>{v_c237, 0}, [&](const std::array<u64,2>& m1587) {
                u64 v_c18 = m1587[1];
                if (v_c30 == v_c18) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c235, v_c236}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:$sup5638x81x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1563* _cont = new ReadTask1563(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1563(db,b), false);
  // (crule (pre) (scan mp_hsb_ans __t16An260 __v3) (body (join-old mp_hsb_ans (0 1) 1 (0 1) __t16An260 __v1) (join-old mp_hsb (0 1) 1 (0 1) __t16An260 __t7Dpg261) (join-old $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk2CMp1835 (bxor p0 p1)) (eq __t7Dpg261 chk2CMp1835)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t16An260 __t16An260 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask1594 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1588;  slog::Index** mp_hsbindex1589;  slog::Index** $sup5638x29x0x0x1index1590;  slog::Index** mp_hsb_ansdelta1591;  slog::Index** mp_hsbdelta1592;  slog::Index** $sup5638x29x0x0x1delta1593;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord1595({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1596 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel1596->getIndex(ord1595, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1597({0, 1});
      slog::Relation* readrel1598 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1588 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({0, 1});
      slog::Relation* readrel1600 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1591 = readrel1600->getIndex(ord1599, true);
      std::vector<u16> ord1601({0, 1});
      slog::Relation* readrel1602 = db->getRelation("mp_hsb");
      mp_hsbindex1589 = readrel1602->getIndex(ord1601, false);
      std::vector<u16> ord1603({0, 1});
      slog::Relation* readrel1604 = db->getRelation("mp_hsb");
      mp_hsbdelta1592 = readrel1604->getIndex(ord1603, true);
      std::vector<u16> ord1605({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1606 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1590 = readrel1606->getIndex(ord1605, false);
      std::vector<u16> ord1607({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1608 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1delta1593 = readrel1608->getIndex(ord1607, true);
  
    }
    ReadTask1594(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c238 = _t[0];
        u64 v_c68 = _t[1];
        slog::join_probe_old<2,1>(mp_hsb_ansindex1588, mp_hsb_ansdelta1591, std::array<u64,2>{v_c238, 0}, [&](const std::array<u64,2>& m1609) {
          u64 v_c69 = m1609[1];
          slog::join_probe_old<2,1>(mp_hsbindex1589, mp_hsbdelta1592, std::array<u64,2>{v_c238, 0}, [&](const std::array<u64,2>& m1610) {
            u64 v_c239 = m1610[1];
            slog::join_all_old<7>($sup5638x29x0x0x1index1590, $sup5638x29x0x0x1delta1593, [&](const std::array<u64,7>& m1611) {
              u64 v_c59 = m1611[0]; u64 v_c18 = m1611[1]; u64 v_c36 = m1611[2]; u64 v_c63 = m1611[3]; u64 v_c64 = m1611[4]; u64 v_c65 = m1611[5]; u64 v_c66 = m1611[6];
              u64 v_c240 = _prim_bxor(db, v_c63, v_c64);
              if (v_c240 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c239 != v_c240) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c59, v_c18, v_c68, v_c69, v_c36, v_c238, v_c238, v_c63, v_c64, v_c65, v_c66}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1594* _cont = new ReadTask1594(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1594(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e)) (scan temp9q5M2005 __t0Vtj505 __t0cTh509 __t0f2O482 __t2zNy470 __t3yjA501) (body (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469)) (head (emit-temp temp2A5g2006 __t0Vtj505 __t0cTh509 __t0f2O482 __t2zNy470 __t3yjA501) (mkstruct app (1 2 0) __t2wOF485 __t1y5d469 __t0f2O482)) kcfa.slog:40 #f)
  class ReadTask1617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1612;  slog::Index** refindex1613;  slog::Index** primrefindex1614;  slog::Index** numindex1615;  slog::Index** refindex1616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2A5g2006");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp9q5M2005");
      std::vector<u16> ord1618({1, 0});
      slog::Relation* readrel1619 = db->getRelation("num");
      numindex1612 = readrel1619->getIndex(ord1618, false);
      std::vector<u16> ord1620({1, 0});
      slog::Relation* readrel1621 = db->getRelation("ref");
      refindex1613 = readrel1621->getIndex(ord1620, false);
      std::vector<u16> ord1622({1, 0});
      slog::Relation* readrel1623 = db->getRelation("primref");
      primrefindex1614 = readrel1623->getIndex(ord1622, false);
      std::vector<u16> ord1624({1, 0});
      slog::Relation* readrel1625 = db->getRelation("num");
      numindex1615 = readrel1625->getIndex(ord1624, false);
      std::vector<u16> ord1626({1, 0});
      slog::Relation* readrel1627 = db->getRelation("ref");
      refindex1616 = readrel1627->getIndex(ord1626, false);
  
    }
    ReadTask1617(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c241 = v_consted725292f5f32d61535958c1;
      u64 v_c171 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c172 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c242 = _t[2];
        u64 v_c174 = _t[3];
        u64 v_c243 = _t[4];
        if (!slog::exists_probe<2,1>(numindex1612, std::array<u64,2>{v_c171, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1613, std::array<u64,2>{v_c170, 0})) return;
        slog::join_probe<2,1>(primrefindex1614, std::array<u64,2>{v_c241, 0}, [&](const std::array<u64,2>& m1628) {
          u64 v_c244 = m1628[1];
          slog::join_probe<2,1>(numindex1615, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m1629) {
            u64 v_c176 = m1629[1];
            slog::join_probe<2,1>(refindex1616, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m1630) {
              u64 v_c245 = m1630[1];
              ++_fires;
              slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c172, v_c173, v_c242, v_c174, v_c243});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c245, v_c242}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp9q5M2005", _fires);
  
      if (!_done)
      {
        ReadTask1617* _cont = new ReadTask1617(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1617(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mp_union_ans __t6NDF685 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t6NDF685 __t0Aux684 v) (exists mbranch (4 0 1 2 3) 1 v) (exists $sup5638x107x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join-old mp_union (1 2 0) 1 (1 2 0) __t0Aux684 __t105R678 __t5Sgr680) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t5Sgr680 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t5Sgr680 v) (join-old mbranch (4 0 1 2 3) 2 (4 0 1 2 3) v __t105R678 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t5Sgr680) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join-old $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t5Sgr680 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t0Aux684) (exists mp_msk (1 2 0) 2 p n) (join-old $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t5Sgr680 l m p r __t78qG683) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask1656 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1631;  slog::Index** mbranchindex1632;  slog::Index** $sup5638x107x0x0x0index1633;  slog::Index** $sup5638x107x0x0x1index1634;  slog::Index** mp_unionindex1635;  slog::Index** $sup5638x107x0x0x0index1636;  slog::Index** $sup5638x107x0x0x1index1637;  slog::Index** mbranchindex1638;  slog::Index** $sup5638x107x0x0x1index1639;  slog::Index** mp_mskindex1640;  slog::Index** mp_msk_ansindex1641;  slog::Index** $sup5638x107x0x0x0index1642;  slog::Index** mbranchindex1643;  slog::Index** mp_mskindex1644;  slog::Index** $sup5638x107x0x0x1index1645;  slog::Index** mbranchindex1646;  slog::Index** mp_mskindex1647;  slog::Index** mp_msk_ansindex1648;  slog::Index** mp_uniondelta1649;  slog::Index** mp_uniondelta1650;  slog::Index** mbranchdelta1651;  slog::Index** $sup5638x107x0x0x0delta1652;  slog::Index** $sup5638x107x0x0x1delta1653;  slog::Index** mbranchdelta1654;  slog::Index** mp_mskdelta1655;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord1657({0, 1, 2});
      slog::Relation* readrel1658 = db->getRelation("mp_union");
      mp_unionindex1631 = readrel1658->getIndex(ord1657, false);
      std::vector<u16> ord1659({0, 1, 2});
      slog::Relation* readrel1660 = db->getRelation("mp_union");
      mp_uniondelta1649 = readrel1660->getIndex(ord1659, true);
      std::vector<u16> ord1661({4, 0, 1, 2, 3});
      slog::Relation* readrel1662 = db->getRelation("mbranch");
      mbranchindex1632 = readrel1662->getIndex(ord1661, false);
      std::vector<u16> ord1663({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1664 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index1633 = readrel1664->getIndex(ord1663, false);
      std::vector<u16> ord1665({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1666 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1634 = readrel1666->getIndex(ord1665, false);
      std::vector<u16> ord1667({1, 2, 0});
      slog::Relation* readrel1668 = db->getRelation("mp_union");
      mp_unionindex1635 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 2, 0});
      slog::Relation* readrel1670 = db->getRelation("mp_union");
      mp_uniondelta1650 = readrel1670->getIndex(ord1669, true);
      std::vector<u16> ord1671({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1672 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index1636 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1674 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1637 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({4, 0, 1, 2, 3});
      slog::Relation* readrel1676 = db->getRelation("mbranch");
      mbranchindex1638 = readrel1676->getIndex(ord1675, false);
      std::vector<u16> ord1677({4, 0, 1, 2, 3});
      slog::Relation* readrel1678 = db->getRelation("mbranch");
      mbranchdelta1651 = readrel1678->getIndex(ord1677, true);
      std::vector<u16> ord1679({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1680 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1639 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({2, 0, 1});
      slog::Relation* readrel1682 = db->getRelation("mp_msk");
      mp_mskindex1640 = readrel1682->getIndex(ord1681, false);
      std::vector<u16> ord1683({1, 0});
      slog::Relation* readrel1684 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1641 = readrel1684->getIndex(ord1683, false);
      std::vector<u16> ord1685({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1686 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index1642 = readrel1686->getIndex(ord1685, false);
      std::vector<u16> ord1687({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1688 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0delta1652 = readrel1688->getIndex(ord1687, true);
      std::vector<u16> ord1689({1, 2, 3, 4, 0});
      slog::Relation* readrel1690 = db->getRelation("mbranch");
      mbranchindex1643 = readrel1690->getIndex(ord1689, false);
      std::vector<u16> ord1691({1, 2, 0});
      slog::Relation* readrel1692 = db->getRelation("mp_msk");
      mp_mskindex1644 = readrel1692->getIndex(ord1691, false);
      std::vector<u16> ord1693({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1694 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1645 = readrel1694->getIndex(ord1693, false);
      std::vector<u16> ord1695({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1696 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1delta1653 = readrel1696->getIndex(ord1695, true);
      std::vector<u16> ord1697({1, 2, 3, 4, 0});
      slog::Relation* readrel1698 = db->getRelation("mbranch");
      mbranchindex1646 = readrel1698->getIndex(ord1697, false);
      std::vector<u16> ord1699({1, 2, 3, 4, 0});
      slog::Relation* readrel1700 = db->getRelation("mbranch");
      mbranchdelta1654 = readrel1700->getIndex(ord1699, true);
      std::vector<u16> ord1701({1, 2, 0});
      slog::Relation* readrel1702 = db->getRelation("mp_msk");
      mp_mskindex1647 = readrel1702->getIndex(ord1701, false);
      std::vector<u16> ord1703({1, 2, 0});
      slog::Relation* readrel1704 = db->getRelation("mp_msk");
      mp_mskdelta1655 = readrel1704->getIndex(ord1703, true);
      std::vector<u16> ord1705({0, 1});
      slog::Relation* readrel1706 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1648 = readrel1706->getIndex(ord1705, false);
  
    }
    ReadTask1656(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c246 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c247 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex1631, mp_uniondelta1649, std::array<u64,3>{v_c247, 0, 0}, [&](const std::array<u64,3>& m1707) {
          u64 v_c248 = m1707[1]; u64 v_c19 = m1707[2];
          if (!slog::exists_probe<5,1>(mbranchindex1632, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index1633, std::array<u64,9>{v_c19, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index1634, std::array<u64,10>{v_c19, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex1635, mp_uniondelta1650, std::array<u64,3>{v_c248, 0, 0}, [&](const std::array<u64,3>& m1708) {
            u64 v_c249 = m1708[1]; u64 v_c250 = m1708[2];
            if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index1636, std::array<u64,9>{v_c250, v_c19, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index1637, std::array<u64,10>{v_c250, v_c19, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex1638, mbranchdelta1651, std::array<u64,5>{v_c19, v_c249, 0, 0, 0}, [&](const std::array<u64,5>& m1709) {
              u64 v_c26 = m1709[2]; u64 v_c27 = m1709[3]; u64 v_c24 = m1709[4];
              if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index1639, std::array<u64,10>{v_c19, v_c27, v_c26, v_c24, v_c250, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex1640, std::array<u64,3>{v_c27, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex1641, std::array<u64,2>{v_c26, 0})) return;
              slog::join_probe_old<9,5>($sup5638x107x0x0x0index1642, $sup5638x107x0x0x0delta1652, std::array<u64,9>{v_c26, v_c27, v_c24, v_c19, v_c250, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1710) {
                u64 v_c28 = m1710[5]; u64 v_c29 = m1710[6]; u64 v_c30 = m1710[7]; u64 v_c31 = m1710[8];
                u64 v_c251 = _prim_lt(db, v_c29, v_c27);
                if (v_c251 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                if (!v_c251) return;
                if (!slog::exists_probe<5,5>(mbranchindex1643, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, v_c248})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex1644, std::array<u64,3>{v_c30, v_c27, 0})) return;
                slog::join_probe_old<10,9>($sup5638x107x0x0x1index1645, $sup5638x107x0x0x1delta1653, std::array<u64,10>{v_c19, v_c27, v_c26, v_c24, v_c250, v_c28, v_c29, v_c30, v_c31, 0}, [&](const std::array<u64,10>& m1712) {
                  u64 v_c252 = m1712[9];
                  slog::join_probe_old<5,5>(mbranchindex1646, mbranchdelta1654, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, v_c248}, [&](const std::array<u64,5>& m1713) {
                    slog::join_probe_old<3,3>(mp_mskindex1647, mp_mskdelta1655, std::array<u64,3>{v_c30, v_c27, v_c252}, [&](const std::array<u64,3>& m1714) {
                      slog::join_probe<2,2>(mp_msk_ansindex1648, std::array<u64,2>{v_c252, v_c26}, [&](const std::array<u64,2>& m1715) {
                        u64 v_c253 = _prim_band(db, v_c30, v_c27);
                        if (v_c253 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c254 = _prim_gt(db, v_c253, v_c246);
                        if (v_c254 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c254) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c250, v_c18, v_c27, v_c26, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c26, v_c27, v_c24, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1656* _cont = new ReadTask1656(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1656(db,b), false);
  // (crule (pre) (scan lookup __t03bu666 x rho) (body (exists eval (2 3 0 1) 1 rho) (exists ref (1 0) 1 x) (exists lookup_ans (0 1) 1 __t03bu666) (join $sup70016x33x0x0x0 (3 1 0 2) 2 x rho __t5crG665 t) (join eval (2 3 0 1) 3 rho t __t5crG665 __t4vms664) (join ref (0 1) 2 __t4vms664 x) (join lookup_ans (0 1) 1 __t03bu666 __v0)) (head (emit eval_ans (0 1) __t5crG665 __v0)) interp.slog:34 #f)
  class ReadTask1724 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1717;  slog::Index** refindex1718;  slog::Index** lookup_ansindex1719;  slog::Index** $sup70016x33x0x0x0index1720;  slog::Index** evalindex1721;  slog::Index** refindex1722;  slog::Index** lookup_ansindex1723;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1725({0, 1});
      slog::Relation* readrel1726 = db->getRelation("eval_ans");
      head_index[0] = readrel1726->getIndex(ord1725, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord1727({2, 3, 0, 1});
      slog::Relation* readrel1728 = db->getRelation("eval");
      evalindex1717 = readrel1728->getIndex(ord1727, false);
      std::vector<u16> ord1729({1, 0});
      slog::Relation* readrel1730 = db->getRelation("ref");
      refindex1718 = readrel1730->getIndex(ord1729, false);
      std::vector<u16> ord1731({0, 1});
      slog::Relation* readrel1732 = db->getRelation("lookup_ans");
      lookup_ansindex1719 = readrel1732->getIndex(ord1731, false);
      std::vector<u16> ord1733({3, 1, 0, 2});
      slog::Relation* readrel1734 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0index1720 = readrel1734->getIndex(ord1733, false);
      std::vector<u16> ord1735({2, 3, 0, 1});
      slog::Relation* readrel1736 = db->getRelation("eval");
      evalindex1721 = readrel1736->getIndex(ord1735, false);
      std::vector<u16> ord1737({0, 1});
      slog::Relation* readrel1738 = db->getRelation("ref");
      refindex1722 = readrel1738->getIndex(ord1737, false);
      std::vector<u16> ord1739({0, 1});
      slog::Relation* readrel1740 = db->getRelation("lookup_ans");
      lookup_ansindex1723 = readrel1740->getIndex(ord1739, false);
  
    }
    ReadTask1724(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c255 = _t[0];
        u64 v_c79 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex1717, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1718, std::array<u64,2>{v_c79, 0})) return;
        if (!slog::exists_probe<2,1>(lookup_ansindex1719, std::array<u64,2>{v_c255, 0})) return;
        slog::join_probe<4,2>($sup70016x33x0x0x0index1720, std::array<u64,4>{v_c79, v_c2, 0, 0}, [&](const std::array<u64,4>& m1741) {
          u64 v_c256 = m1741[2]; u64 v_c3 = m1741[3];
          slog::join_probe<4,3>(evalindex1721, std::array<u64,4>{v_c2, v_c3, v_c256, 0}, [&](const std::array<u64,4>& m1742) {
            u64 v_c257 = m1742[3];
            slog::join_probe<2,2>(refindex1722, std::array<u64,2>{v_c257, v_c79}, [&](const std::array<u64,2>& m1743) {
              slog::join_probe<2,1>(lookup_ansindex1723, std::array<u64,2>{v_c255, 0}, [&](const std::array<u64,2>& m1744) {
                u64 v_c18 = m1744[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c256, v_c18}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask1724* _cont = new ReadTask1724(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1724(db,b), false);
  // (crule (pre (let __trid1cWW1167 const07d7fbed0aba019c07f7eb8a) (let __trel2sJQ1168 constdd7bbf31ce5f578b9805e840) (let __tcol5iom1169 const5feceb66ffc86f38d952786c) (let __trel1wkf1170 constdd7bbf31ce5f578b9805e840) (let __tcol2BaV1171 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid1cWW1167 __trel2sJQ1168 __tcol5iom1169 (1 2 3 4 0)) (tycheck m (accept int) __trid1cWW1167 __trel1wkf1170 __tcol2BaV1171 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __9t831166 k m)) map.slog:83 #f)
  class ReadTask1745 : public slog::Task
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
    ReadTask1745(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c258 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c259 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c260 = v_const5feceb66ffc86f38d952786c;
      u64 v_c261 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c262 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c36 = _t[0];
        u64 v_c121 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c31 = _t[5];
        ++_fires;
        if (!(is_int(v_c121)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c258, v_c259, v_c260, v_c121}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c29)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c258, v_c261, v_c262, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c121, v_c29}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1745* _cont = new ReadTask1745(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1745(db,b), false);
  // (crule (pre) (scan temp9R9Y1810 __t7AlQ821 op) (body (join prim (1 0) 1 op __t1HR7819)) (head (emit eval_ans (0 1) __t7AlQ821 __t1HR7819)) interp.slog:35 #f)
  class ReadTask1747 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex1746;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1748({0, 1});
      slog::Relation* readrel1749 = db->getRelation("eval_ans");
      head_index[0] = readrel1749->getIndex(ord1748, false);
      outer_rel = db->getRelation("temp9R9Y1810");
      std::vector<u16> ord1750({1, 0});
      slog::Relation* readrel1751 = db->getRelation("prim");
      primindex1746 = readrel1751->getIndex(ord1750, false);
  
    }
    ReadTask1747(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c182 = _t[0];
        u64 v_c156 = _t[1];
        slog::join_probe<2,1>(primindex1746, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m1752) {
          u64 v_c263 = m1752[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c182, v_c263}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:35", "delta:temp9R9Y1810", _fires);
  
      if (!_done)
      {
        ReadTask1747* _cont = new ReadTask1747(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1747(db,b), false);
  // (crule (pre) (scan temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1) (body (let __t02pg792 (lpush __t6qtm791 __v0))) (head (emit-temp temp3Hfu2034 __t02pg792 __t7ZV0794 __v1)) interp.slog:44 #f)
  class ReadTask1753 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3Hfu2034");
      outer_rel = db->getRelation("temp2swd2033");
  
    }
    ReadTask1753(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c264 = _t[0];
        u64 v_c265 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c69 = _t[3];
        u64 v_c266 = _prim_lpush(db, v_c264, v_c18);
        if (v_c266 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c266, v_c265, v_c69});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:temp2swd2033", _fires);
  
      if (!_done)
      {
        ReadTask1753* _cont = new ReadTask1753(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1753(db,b), false);
  // (crule (pre) (scan temp0HD91944 __t56KF124 k t) (body (let __t5ttu125 (lcat __t56KF124 t))) (head (emit-temp temp89ti1945 __t5ttu125 k)) context.slog:11 #f)
  class ReadTask1754 : public slog::Task
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
      head_rel[0] = db->getRelation("temp89ti1945");
      outer_rel = db->getRelation("temp0HD91944");
  
    }
    ReadTask1754(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c268 = _prim_lcat(db, v_c267, v_c3);
        if (v_c268 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c268, v_c121});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:temp0HD91944", _fires);
  
      if (!_done)
      {
        ReadTask1754* _cont = new ReadTask1754(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1754(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp6yZq1906 __t5xOK723 __t9E0P759) (body (join letrec (1 2 3 0) 3 __tconst6I9K760 __t9E0P759 __t5xOK723 __t79Wk761)) (head (emit program (0) __t79Wk761)) kcfa.slog:70 #f)
  class ReadTask1756 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1755;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1757({0});
      slog::Relation* readrel1758 = db->getRelation("program");
      head_index[0] = readrel1758->getIndex(ord1757, false);
      outer_rel = db->getRelation("temp6yZq1906");
      std::vector<u16> ord1759({1, 2, 3, 0});
      slog::Relation* readrel1760 = db->getRelation("letrec");
      letrecindex1755 = readrel1760->getIndex(ord1759, false);
  
    }
    ReadTask1756(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c226 = v_constd59eced1ded07f84c145592f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c230 = _t[0];
        u64 v_c269 = _t[1];
        slog::join_probe<4,3>(letrecindex1755, std::array<u64,4>{v_c226, v_c269, v_c230, 0}, [&](const std::array<u64,4>& m1761) {
          u64 v_c270 = m1761[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c270}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp6yZq1906", _fires);
  
      if (!_done)
      {
        ReadTask1756* _cont = new ReadTask1756(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1756(db,b), false);
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t9BfR236 p) (body (exists $sup5638x62x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t9BfR236 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x62x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t7cml232 l r) (exists mp_has0 (0 2 1) 2 __t7cml232 k) (exists mp_has0 (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5gI3231) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t7cml232 k __t5gI3231) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t2sXu235) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask1779 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index1762;  slog::Index** mbranchindex1763;  slog::Index** mp_mskindex1764;  slog::Index** mbranchindex1765;  slog::Index** mp_has0index1766;  slog::Index** $sup5638x62x0x0x0index1767;  slog::Index** mp_has0index1768;  slog::Index** mp_has0index1769;  slog::Index** mbranchindex1770;  slog::Index** mp_has0index1771;  slog::Index** mp_has0index1772;  slog::Index** mp_has0_ansindex1773;  slog::Index** mp_mskdelta1774;  slog::Index** $sup5638x62x0x0x0delta1775;  slog::Index** mbranchdelta1776;  slog::Index** mp_has0delta1777;  slog::Index** mp_has0delta1778;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1780({0, 1});
      slog::Relation* readrel1781 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1781->getIndex(ord1780, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1782({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1783 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1762 = readrel1783->getIndex(ord1782, false);
      std::vector<u16> ord1784({1, 2, 3, 4, 0});
      slog::Relation* readrel1785 = db->getRelation("mbranch");
      mbranchindex1763 = readrel1785->getIndex(ord1784, false);
      std::vector<u16> ord1786({0, 1, 2});
      slog::Relation* readrel1787 = db->getRelation("mp_msk");
      mp_mskindex1764 = readrel1787->getIndex(ord1786, false);
      std::vector<u16> ord1788({0, 1, 2});
      slog::Relation* readrel1789 = db->getRelation("mp_msk");
      mp_mskdelta1774 = readrel1789->getIndex(ord1788, true);
      std::vector<u16> ord1790({1, 2, 3, 4, 0});
      slog::Relation* readrel1791 = db->getRelation("mbranch");
      mbranchindex1765 = readrel1791->getIndex(ord1790, false);
      std::vector<u16> ord1792({2, 0, 1});
      slog::Relation* readrel1793 = db->getRelation("mp_has0");
      mp_has0index1766 = readrel1793->getIndex(ord1792, false);
      std::vector<u16> ord1794({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1795 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index1767 = readrel1795->getIndex(ord1794, false);
      std::vector<u16> ord1796({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1797 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0delta1775 = readrel1797->getIndex(ord1796, true);
      std::vector<u16> ord1798({0, 2, 1});
      slog::Relation* readrel1799 = db->getRelation("mp_has0");
      mp_has0index1768 = readrel1799->getIndex(ord1798, false);
      std::vector<u16> ord1800({1, 2, 0});
      slog::Relation* readrel1801 = db->getRelation("mp_has0");
      mp_has0index1769 = readrel1801->getIndex(ord1800, false);
      std::vector<u16> ord1802({1, 2, 3, 4, 0});
      slog::Relation* readrel1803 = db->getRelation("mbranch");
      mbranchindex1770 = readrel1803->getIndex(ord1802, false);
      std::vector<u16> ord1804({1, 2, 3, 4, 0});
      slog::Relation* readrel1805 = db->getRelation("mbranch");
      mbranchdelta1776 = readrel1805->getIndex(ord1804, true);
      std::vector<u16> ord1806({0, 2, 1});
      slog::Relation* readrel1807 = db->getRelation("mp_has0");
      mp_has0index1771 = readrel1807->getIndex(ord1806, false);
      std::vector<u16> ord1808({0, 2, 1});
      slog::Relation* readrel1809 = db->getRelation("mp_has0");
      mp_has0delta1777 = readrel1809->getIndex(ord1808, true);
      std::vector<u16> ord1810({1, 2, 0});
      slog::Relation* readrel1811 = db->getRelation("mp_has0");
      mp_has0index1772 = readrel1811->getIndex(ord1810, false);
      std::vector<u16> ord1812({1, 2, 0});
      slog::Relation* readrel1813 = db->getRelation("mp_has0");
      mp_has0delta1778 = readrel1813->getIndex(ord1812, true);
      std::vector<u16> ord1814({0, 1});
      slog::Relation* readrel1815 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1773 = readrel1815->getIndex(ord1814, false);
  
    }
    ReadTask1779(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c198 = _t[0];
        u64 v_c30 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x62x0x0x0index1762, std::array<u64,6>{v_c30, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1763, std::array<u64,5>{v_c30, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1764, mp_mskdelta1774, std::array<u64,3>{v_c198, 0, 0}, [&](const std::array<u64,3>& m1816) {
          u64 v_c121 = m1816[1]; u64 v_c29 = m1816[2];
          if (!slog::exists_probe<5,2>(mbranchindex1765, std::array<u64,5>{v_c30, v_c29, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index1766, std::array<u64,3>{v_c121, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x62x0x0x0index1767, $sup5638x62x0x0x0delta1775, std::array<u64,6>{v_c121, v_c29, v_c30, 0, 0, 0}, [&](const std::array<u64,6>& m1817) {
            u64 v_c196 = m1817[3]; u64 v_c28 = m1817[4]; u64 v_c31 = m1817[5];
            if (!slog::exists_probe<3,2>(mp_has0index1768, std::array<u64,3>{v_c196, v_c121, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index1769, std::array<u64,3>{v_c31, v_c121, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1770, mbranchdelta1776, std::array<u64,5>{v_c30, v_c29, v_c28, v_c31, 0}, [&](const std::array<u64,5>& m1818) {
              u64 v_c195 = m1818[4];
              slog::join_probe_old<3,3>(mp_has0index1771, mp_has0delta1777, std::array<u64,3>{v_c196, v_c121, v_c195}, [&](const std::array<u64,3>& m1819) {
                slog::join_probe_old<3,2>(mp_has0index1772, mp_has0delta1778, std::array<u64,3>{v_c31, v_c121, 0}, [&](const std::array<u64,3>& m1820) {
                  u64 v_c197 = m1820[2];
                  slog::join_probe<2,1>(mp_has0_ansindex1773, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m1821) {
                    u64 v_c199 = m1821[1];
                    u64 v_c200 = _prim_band(db, v_c121, v_c29);
                    if (v_c200 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c271 = _prim_gt(db, v_c200, v_c194);
                    if (v_c271 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c271) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c196, v_c199}, std::array<u16,2>{0, 1});
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
        ReadTask1779* _cont = new ReadTask1779(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1779(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x0 __d0 p0 p1 t0 t1) (body (let __t9B8M434 (bxor p0 p1))) (head (emit-temp temp1h2m2046 __t9B8M434)) map.slog:30 #f)
  class ReadTask1823 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1h2m2046");
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
  
    }
    ReadTask1823(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c66 = _t[4];
        u64 v_c272 = _prim_bxor(db, v_c63, v_c64);
        if (v_c272 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c272});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1823* _cont = new ReadTask1823(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1823(db,b), false);
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst9cNI595 _00024seq2 __t0WVv596) (body (letp _00024sql2mO51039 (aslst _00024seq2)) (letp __t7ye2598 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo05pe1044 __t7ye2598 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5XjX1045 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0BYf1046 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9pUp1047 __t7ye2598 _00024seq2) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join-old symval (0 1) 1 (0 1) __t7ye2598 s) (let chk5TKA2013 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk5TKA2013) (letp chk1bJV2014 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk1bJV2014)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask1835 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1824;  slog::Index** $seq_atindex1825;  slog::Index** $seq_atrindex1826;  slog::Index** $seq_atrindex1827;  slog::Index** _enumindex1828;  slog::Index** symvalindex1829;  slog::Index** $seq_atdelta1830;  slog::Index** $seq_atdelta1831;  slog::Index** $seq_atrdelta1832;  slog::Index** $seq_atrdelta1833;  slog::Index** symvaldelta1834;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1836({1, 2, 0});
      slog::Relation* readrel1837 = db->getRelation("delta");
      driver_index = readrel1837->getIndex(ord1836, true);
      std::vector<u16> ord1838({1, 0, 2});
      slog::Relation* readrel1839 = db->getRelation("$seq_at");
      $seq_atindex1824 = readrel1839->getIndex(ord1838, false);
      std::vector<u16> ord1840({1, 0, 2});
      slog::Relation* readrel1841 = db->getRelation("$seq_at");
      $seq_atdelta1830 = readrel1841->getIndex(ord1840, true);
      std::vector<u16> ord1842({1, 0, 2});
      slog::Relation* readrel1843 = db->getRelation("$seq_at");
      $seq_atindex1825 = readrel1843->getIndex(ord1842, false);
      std::vector<u16> ord1844({1, 0, 2});
      slog::Relation* readrel1845 = db->getRelation("$seq_at");
      $seq_atdelta1831 = readrel1845->getIndex(ord1844, true);
      std::vector<u16> ord1846({1, 0, 2});
      slog::Relation* readrel1847 = db->getRelation("$seq_atr");
      $seq_atrindex1826 = readrel1847->getIndex(ord1846, false);
      std::vector<u16> ord1848({1, 0, 2});
      slog::Relation* readrel1849 = db->getRelation("$seq_atr");
      $seq_atrdelta1832 = readrel1849->getIndex(ord1848, true);
      std::vector<u16> ord1850({1, 0, 2});
      slog::Relation* readrel1851 = db->getRelation("$seq_atr");
      $seq_atrindex1827 = readrel1851->getIndex(ord1850, false);
      std::vector<u16> ord1852({1, 0, 2});
      slog::Relation* readrel1853 = db->getRelation("$seq_atr");
      $seq_atrdelta1833 = readrel1853->getIndex(ord1852, true);
      std::vector<u16> ord1854({1, 0});
      slog::Relation* readrel1855 = db->getRelation("_enum");
      _enumindex1828 = readrel1855->getIndex(ord1854, false);
      std::vector<u16> ord1856({0, 1});
      slog::Relation* readrel1857 = db->getRelation("symval");
      symvalindex1829 = readrel1857->getIndex(ord1856, false);
      std::vector<u16> ord1858({0, 1});
      slog::Relation* readrel1859 = db->getRelation("symval");
      symvaldelta1834 = readrel1859->getIndex(ord1858, true);
  
    }
    ReadTask1835(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c39 = v_const06abaa100ecef791ce028c56;
      u64 v_c40 = v_constd4735e3a265e16eee03f5971;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c39, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1860) {
        u64 v_c48 = m1860[1];
        u64 v_c49 = m1860[2];
        if (buckethash(v_c48) != bucket) return;
        bool ok1861 = true;
        u64 v_c52 = _prim_aslst(db, v_c48, &ok1861);
        if (!ok1861) return;
        bool ok1862 = true;
        u64 v_c47 = _prim_lref(db, v_c52, v_c41, &ok1862);
        if (!ok1862) return;
        slog::join_probe_old<3,3>($seq_atindex1824, $seq_atdelta1830, std::array<u64,3>{v_c43, v_c47, v_c48}, [&](const std::array<u64,3>& m1863) {
          slog::join_probe_old<3,3>($seq_atindex1825, $seq_atdelta1831, std::array<u64,3>{v_c44, v_c47, v_c48}, [&](const std::array<u64,3>& m1864) {
            slog::join_probe_old<3,3>($seq_atrindex1826, $seq_atrdelta1832, std::array<u64,3>{v_c45, v_c47, v_c48}, [&](const std::array<u64,3>& m1865) {
              slog::join_probe_old<3,3>($seq_atrindex1827, $seq_atrdelta1833, std::array<u64,3>{v_c46, v_c47, v_c48}, [&](const std::array<u64,3>& m1866) {
                slog::join_probe<2,1>(_enumindex1828, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m1867) {
                  u64 v_c50 = m1867[1];
                  slog::join_probe_old<2,1>(symvalindex1829, symvaldelta1834, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m1868) {
                    u64 v_c51 = m1868[1];
                    u64 v_c273 = _prim_llen(db, v_c52);
                    if (v_c273 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c40 != v_c273) return;
                    bool ok1869 = true;
                    u64 v_c274 = _prim_lref(db, v_c52, v_c42, &ok1869);
                    if (!ok1869) return;
                    if (v_c47 != v_c274) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c49});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c50}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1835* _cont = new ReadTask1835(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1835(db,b), false);
  // (crule (pre) (scan toint_range __erre1L7H1760 __errf45G71761 __errf0eu11762) (body) (head (emit error (0) __erre1L7H1760)) <internal>:1 #f)
  class ReadTask1870 : public slog::Task
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
      std::vector<u16> ord1871({0});
      slog::Relation* readrel1872 = db->getRelation("error");
      head_index[0] = readrel1872->getIndex(ord1871, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask1870(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c275 = _t[0];
        u64 v_c276 = _t[1];
        u64 v_c277 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c275}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask1870* _cont = new ReadTask1870(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1870(db,b), false);
}

