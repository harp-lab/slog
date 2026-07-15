
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const0fc34686741291b4dd06511b;
extern u64 v_const20c400557af0eddc0be4d9e0;
extern u64 v_const2d53b3c21fa5cc786ac46d72;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const39c6f8839ca547fa7b7a32c4;
extern u64 v_const49e9fcfb5617aad332d56d58;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const5963fd3eff55776ca49412c5;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const609d51837c7fc306b0cbb04a;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7265b875feb0d1730ead43d3;
extern u64 v_const781eda039ec10c193395ca07;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb85d38dc71a8027700bebd3c;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste403ffb5ff0078a3e3c6bcc7;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_constea10b8ee9cd346b11a382114;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_cba1fca668d89f794(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan eval __t32yp296 eb c) (body (exists letrec (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t32yp296) (join $sup56712x93x0x0x0 (1 2 0 3 4) 2 c eb __t5OlD294 er x) (exists eval (0 2 1) 2 __t5OlD294 c) (exists eval (1 2 0) 2 er c) (join letrec (2 1 3 0) 3 er x eb __t0H7q293) (join eval (0 2 1) 3 __t5OlD294 c __t0H7q293) (join eval (1 2 0) 2 er c __t9p2a295) (join eval_ans (0 1) 1 __t9p2a295 vr) (join eval_ans (0 1) 1 __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex0;  slog::Index** evalindex1;  slog::Index** eval_ansindex2;  slog::Index** $sup56712x93x0x0x0index3;  slog::Index** evalindex4;  slog::Index** evalindex5;  slog::Index** letrecindex6;  slog::Index** evalindex7;  slog::Index** evalindex8;  slog::Index** eval_ansindex9;  slog::Index** eval_ansindex10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("eval_ans");
      head_index[0] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord14({3, 0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("letrec");
      letrecindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 0, 1});
      slog::Relation* readrel17 = db->getRelation("eval");
      evalindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("eval_ans");
      eval_ansindex2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 2, 0, 3, 4});
      slog::Relation* readrel21 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({0, 2, 1});
      slog::Relation* readrel23 = db->getRelation("eval");
      evalindex4 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 0});
      slog::Relation* readrel25 = db->getRelation("eval");
      evalindex5 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({2, 1, 3, 0});
      slog::Relation* readrel27 = db->getRelation("letrec");
      letrecindex6 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 2, 1});
      slog::Relation* readrel29 = db->getRelation("eval");
      evalindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("eval");
      evalindex8 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("eval_ans");
      eval_ansindex9 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("eval_ans");
      eval_ansindex10 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<4,1>(letrecindex0, std::array<u64,4>{v_c1, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex2, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index3, std::array<u64,5>{v_c2, v_c1, 0, 0, 0}, [&](const std::array<u64,5>& m36) {
          u64 v_c3 = m36[2]; u64 v_c4 = m36[3]; u64 v_c5 = m36[4];
          if (!slog::exists_probe<3,2>(evalindex4, std::array<u64,3>{v_c3, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex5, std::array<u64,3>{v_c4, v_c2, 0})) return;
          slog::join_probe<4,3>(letrecindex6, std::array<u64,4>{v_c4, v_c5, v_c1, 0}, [&](const std::array<u64,4>& m37) {
            u64 v_c6 = m37[3];
            slog::join_probe<3,3>(evalindex7, std::array<u64,3>{v_c3, v_c2, v_c6}, [&](const std::array<u64,3>& m38) {
              slog::join_probe<3,2>(evalindex8, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m39) {
                u64 v_c7 = m39[2];
                slog::join_probe<2,1>(eval_ansindex9, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m40) {
                  u64 v_c8 = m40[1];
                  slog::join_probe<2,1>(eval_ansindex10, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m41) {
                    u64 v_c9 = m41[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c9}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), false);
  // (crule (pre) (scan eval_ans __t44Jo196 __t4ROj198) (body (join-old eval (0 2 1) 1 (0 2 1) __t44Jo196 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join-old eval_args_ans (0 1) 1 (0 1) __t3i0k199 vs) (join-old tick_ans (0 1) 1 (0 1) __t3z31201 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4ROj198 __t2BTJ197 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex42;  slog::Index** eval_argsindex43;  slog::Index** appindex44;  slog::Index** tickindex45;  slog::Index** $sup56712x41x0x0x0index46;  slog::Index** appindex47;  slog::Index** eval_argsindex48;  slog::Index** eval_args_ansindex49;  slog::Index** appindex50;  slog::Index** tickindex51;  slog::Index** tick_ansindex52;  slog::Index** eval_args_ansindex53;  slog::Index** tick_ansindex54;  slog::Index** closureindex55;  slog::Index** lambdaindex56;  slog::Index** evaldelta57;  slog::Index** eval_argsdelta58;  slog::Index** appdelta59;  slog::Index** tickdelta60;  slog::Index** eval_args_ansdelta61;  slog::Index** tick_ansdelta62;  slog::Index** closuredelta63;  slog::Index** lambdadelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord66({0, 2, 1});
      slog::Relation* readrel67 = db->getRelation("eval");
      evalindex42 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({0, 2, 1});
      slog::Relation* readrel69 = db->getRelation("eval");
      evaldelta57 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({2, 0, 1});
      slog::Relation* readrel71 = db->getRelation("eval_args");
      eval_argsindex43 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 2, 0});
      slog::Relation* readrel73 = db->getRelation("app");
      appindex44 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({2, 0, 1});
      slog::Relation* readrel75 = db->getRelation("tick");
      tickindex45 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 3, 0});
      slog::Relation* readrel77 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index46 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("app");
      appindex47 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("eval_args");
      eval_argsindex48 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("eval_args");
      eval_argsdelta58 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("eval_args_ans");
      eval_args_ansindex49 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("app");
      appindex50 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("app");
      appdelta59 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("tick");
      tickindex51 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("tick");
      tickdelta60 = readrel93->getIndex(ord92, true);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("tick_ans");
      tick_ansindex52 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("eval_args_ans");
      eval_args_ansindex53 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("eval_args_ans");
      eval_args_ansdelta61 = readrel99->getIndex(ord98, true);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("tick_ans");
      tick_ansindex54 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("tick_ans");
      tick_ansdelta62 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("closure");
      closureindex55 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1, 2});
      slog::Relation* readrel107 = db->getRelation("closure");
      closuredelta63 = readrel107->getIndex(ord106, true);
      std::vector<u16> ord108({0, 1, 2});
      slog::Relation* readrel109 = db->getRelation("lambda");
      lambdaindex56 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({0, 1, 2});
      slog::Relation* readrel111 = db->getRelation("lambda");
      lambdadelta64 = readrel111->getIndex(ord110, true);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(evalindex42, evaldelta57, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m112) {
          u64 v_c2 = m112[1]; u64 v_c12 = m112[2];
          if (!slog::exists_probe<3,1>(eval_argsindex43, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex44, std::array<u64,3>{v_c12, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex45, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index46, std::array<u64,4>{v_c2, v_c12, 0, 0}, [&](const std::array<u64,4>& m113) {
            u64 v_c13 = m113[2]; u64 v_c14 = m113[3];
            if (!slog::exists_probe<3,2>(appindex47, std::array<u64,3>{v_c12, v_c13, 0})) return;
            slog::join_probe_old<3,2>(eval_argsindex48, eval_argsdelta58, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m114) {
              u64 v_c15 = m114[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex49, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe_old<3,2>(appindex50, appdelta59, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m115) {
                u64 v_c16 = m115[2];
                slog::join_probe_old<3,2>(tickindex51, tickdelta60, std::array<u64,3>{v_c16, v_c2, 0}, [&](const std::array<u64,3>& m116) {
                  u64 v_c17 = m116[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex52, std::array<u64,2>{v_c17, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex53, eval_args_ansdelta61, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m117) {
                    u64 v_c18 = m117[1];
                    slog::join_probe_old<2,1>(tick_ansindex54, tick_ansdelta62, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m118) {
                      u64 v_c19 = m118[1];
                      slog::join_probe_old<3,1>(closureindex55, closuredelta63, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m119) {
                        u64 v_c20 = m119[1]; u64 v_c21 = m119[2];
                        slog::join_probe_old<3,1>(lambdaindex56, lambdadelta64, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m120) {
                          u64 v_c22 = m120[1]; u64 v_c1 = m120[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c19}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre (let __tconst165m173 const60e3114d9b4b6577eea8cbc0) (let __tconst1U6w167 const844546be553b9dcbf71ae163) (let __tconst469K165 const0453462f31b2bcf68e33a91f)) (scan temp7N6P1032 __t6CCt172) (body (exists sym (1 0) 1 __tconst1U6w167) (exists ref (1 0) 1 __tconst165m173) (exists app (2 0 1) 1 __t6CCt172) (join sym (1 0) 1 __tconst469K165 __t5k1R166) (join sym (1 0) 1 __tconst1U6w167 __t2m3K168) (join ref (1 0) 1 __tconst165m173 __t3tIp174) (join app (1 2 0) 2 __t3tIp174 __t6CCt172 __t86mw175)) (head (emit-temp temp9DO81033 __t86mw175) (mkstruct if (1 3 2 0) __t55Mc176 __t86mw175 __t5k1R166 __t2m3K168)) schemecfa.slog:61 #f)
  class ReadTask128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex121;  slog::Index** refindex122;  slog::Index** appindex123;  slog::Index** symindex124;  slog::Index** symindex125;  slog::Index** refindex126;  slog::Index** appindex127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9DO81033");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp7N6P1032");
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("sym");
      symindex121 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 0});
      slog::Relation* readrel132 = db->getRelation("ref");
      refindex122 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({2, 0, 1});
      slog::Relation* readrel134 = db->getRelation("app");
      appindex123 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 0});
      slog::Relation* readrel136 = db->getRelation("sym");
      symindex124 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("sym");
      symindex125 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("ref");
      refindex126 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("app");
      appindex127 = readrel142->getIndex(ord141, false);
  
    }
    ReadTask128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c24 = v_const844546be553b9dcbf71ae163;
      u64 v_c25 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        if (!slog::exists_probe<2,1>(symindex121, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(refindex122, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<3,1>(appindex123, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<2,1>(symindex124, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m143) {
          u64 v_c27 = m143[1];
          slog::join_probe<2,1>(symindex125, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m144) {
            u64 v_c28 = m144[1];
            slog::join_probe<2,1>(refindex126, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m145) {
              u64 v_c29 = m145[1];
              slog::join_probe<3,2>(appindex127, std::array<u64,3>{v_c29, v_c26, 0}, [&](const std::array<u64,3>& m146) {
                u64 v_c30 = m146[2];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c30});
                slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c30, v_c27, v_c28}, std::array<u16,4>{1, 3, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:61", "delta:temp7N6P1032", _fires);
  
      if (!_done)
      {
        ReadTask128* _cont = new ReadTask128(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask128(db,b), false);
  // (crule (pre) (scan eval_args __t3i0k199 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t3i0k199) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __d0 ef) (exists app (1 2 0) 2 ef es) (join eval (1 2 0) 2 ef c __t44Jo196) (exists eval_ans (0 1) 1 __t44Jo196) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join tick_ans (0 1) 1 __t3z31201 __v0) (join closure (0 1 2) 1 __t4ROj198 __t2BTJ197 cb) (join lambda (0 1 2) 1 __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask165 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex147;  slog::Index** appindex148;  slog::Index** tickindex149;  slog::Index** eval_args_ansindex150;  slog::Index** $sup56712x41x0x0x0index151;  slog::Index** appindex152;  slog::Index** evalindex153;  slog::Index** eval_ansindex154;  slog::Index** appindex155;  slog::Index** tickindex156;  slog::Index** tick_ansindex157;  slog::Index** eval_ansindex158;  slog::Index** eval_args_ansindex159;  slog::Index** tick_ansindex160;  slog::Index** closureindex161;  slog::Index** lambdaindex162;  slog::Index** appdelta163;  slog::Index** tickdelta164;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord166({2, 0, 1});
      slog::Relation* readrel167 = db->getRelation("eval");
      evalindex147 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({2, 0, 1});
      slog::Relation* readrel169 = db->getRelation("app");
      appindex148 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({2, 0, 1});
      slog::Relation* readrel171 = db->getRelation("tick");
      tickindex149 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 1});
      slog::Relation* readrel173 = db->getRelation("eval_args_ans");
      eval_args_ansindex150 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 3, 0, 2});
      slog::Relation* readrel175 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index151 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 2, 0});
      slog::Relation* readrel177 = db->getRelation("app");
      appindex152 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 0});
      slog::Relation* readrel179 = db->getRelation("eval");
      evalindex153 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("eval_ans");
      eval_ansindex154 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 2, 0});
      slog::Relation* readrel183 = db->getRelation("app");
      appindex155 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("app");
      appdelta163 = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("tick");
      tickindex156 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 2, 0});
      slog::Relation* readrel189 = db->getRelation("tick");
      tickdelta164 = readrel189->getIndex(ord188, true);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("tick_ans");
      tick_ansindex157 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("eval_ans");
      eval_ansindex158 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1});
      slog::Relation* readrel195 = db->getRelation("eval_args_ans");
      eval_args_ansindex159 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("tick_ans");
      tick_ansindex160 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({0, 1, 2});
      slog::Relation* readrel199 = db->getRelation("closure");
      closureindex161 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1, 2});
      slog::Relation* readrel201 = db->getRelation("lambda");
      lambdaindex162 = readrel201->getIndex(ord200, false);
  
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
        u64 v_c15 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex147, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex148, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex149, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex150, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index151, std::array<u64,4>{v_c2, v_c13, 0, 0}, [&](const std::array<u64,4>& m202) {
          u64 v_c14 = m202[2]; u64 v_c12 = m202[3];
          if (!slog::exists_probe<3,2>(appindex152, std::array<u64,3>{v_c12, v_c13, 0})) return;
          slog::join_probe<3,2>(evalindex153, std::array<u64,3>{v_c12, v_c2, 0}, [&](const std::array<u64,3>& m203) {
            u64 v_c10 = m203[2];
            if (!slog::exists_probe<2,1>(eval_ansindex154, std::array<u64,2>{v_c10, 0})) return;
            slog::join_probe_old<3,2>(appindex155, appdelta163, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m204) {
              u64 v_c16 = m204[2];
              slog::join_probe_old<3,2>(tickindex156, tickdelta164, std::array<u64,3>{v_c16, v_c2, 0}, [&](const std::array<u64,3>& m205) {
                u64 v_c17 = m205[2];
                if (!slog::exists_probe<2,1>(tick_ansindex157, std::array<u64,2>{v_c17, 0})) return;
                slog::join_probe<2,1>(eval_ansindex158, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m206) {
                  u64 v_c11 = m206[1];
                  slog::join_probe<2,1>(eval_args_ansindex159, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m207) {
                    u64 v_c18 = m207[1];
                    slog::join_probe<2,1>(tick_ansindex160, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m208) {
                      u64 v_c19 = m208[1];
                      slog::join_probe<3,1>(closureindex161, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m209) {
                        u64 v_c20 = m209[1]; u64 v_c21 = m209[2];
                        slog::join_probe<3,1>(lambdaindex162, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m210) {
                          u64 v_c22 = m210[1]; u64 v_c1 = m210[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c19}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_args", _fires);
  
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
  // (crule (pre) (scan app __t1aJ4143 ef es) (body (join freevar (1 0) 1 ef x)) (head (emit freevar (0 1) x __t1aJ4143)) freevars.slog:13 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex211;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("freevar");
      head_index[0] = readrel214->getIndex(ord213, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("freevar");
      freevarindex211 = readrel216->getIndex(ord215, false);
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe<2,1>(freevarindex211, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m217) {
          u64 v_c5 = m217[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c31}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre) (scan eval __t5MCM24 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join tick_ans (0 1) 1 __t0DSy30 l) (join-old closure (0 1 2) 1 (0 1 2) __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask242 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex218;  slog::Index** appindex219;  slog::Index** eval_argsindex220;  slog::Index** tickindex221;  slog::Index** eval_ansindex222;  slog::Index** evalindex223;  slog::Index** tickindex224;  slog::Index** appindex225;  slog::Index** eval_argsindex226;  slog::Index** eval_args_ansindex227;  slog::Index** tickindex228;  slog::Index** tick_ansindex229;  slog::Index** eval_args_ansindex230;  slog::Index** tick_ansindex231;  slog::Index** closureindex232;  slog::Index** bindingindex233;  slog::Index** freevarindex234;  slog::Index** bindingindex235;  slog::Index** lambdaindex236;  slog::Index** appdelta237;  slog::Index** eval_argsdelta238;  slog::Index** tickdelta239;  slog::Index** closuredelta240;  slog::Index** lambdadelta241;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord243({0, 1, 2});
      slog::Relation* readrel244 = db->getRelation("binding");
      head_index[0] = readrel244->getIndex(ord243, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord245({0, 1, 2});
      slog::Relation* readrel246 = db->getRelation("binding_event");
      head_index[1] = readrel246->getIndex(ord245, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord247({2, 0, 1});
      slog::Relation* readrel248 = db->getRelation("eval");
      evalindex218 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("app");
      appindex219 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({2, 0, 1});
      slog::Relation* readrel252 = db->getRelation("eval_args");
      eval_argsindex220 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({2, 0, 1});
      slog::Relation* readrel254 = db->getRelation("tick");
      tickindex221 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({0, 1});
      slog::Relation* readrel256 = db->getRelation("eval_ans");
      eval_ansindex222 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({2, 0, 1});
      slog::Relation* readrel258 = db->getRelation("eval");
      evalindex223 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("tick");
      tickindex224 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({0, 1, 2});
      slog::Relation* readrel262 = db->getRelation("app");
      appindex225 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({0, 1, 2});
      slog::Relation* readrel264 = db->getRelation("app");
      appdelta237 = readrel264->getIndex(ord263, true);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("eval_args");
      eval_argsindex226 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("eval_args");
      eval_argsdelta238 = readrel268->getIndex(ord267, true);
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("eval_args_ans");
      eval_args_ansindex227 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 2, 0});
      slog::Relation* readrel272 = db->getRelation("tick");
      tickindex228 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 2, 0});
      slog::Relation* readrel274 = db->getRelation("tick");
      tickdelta239 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("tick_ans");
      tick_ansindex229 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("eval_args_ans");
      eval_args_ansindex230 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("tick_ans");
      tick_ansindex231 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({0, 1, 2});
      slog::Relation* readrel282 = db->getRelation("closure");
      closureindex232 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({0, 1, 2});
      slog::Relation* readrel284 = db->getRelation("closure");
      closuredelta240 = readrel284->getIndex(ord283, true);
      std::vector<u16> ord285({1, 0, 2});
      slog::Relation* readrel286 = db->getRelation("binding");
      bindingindex233 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("freevar");
      freevarindex234 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2});
      slog::Relation* readrel290 = db->getRelation("binding");
      bindingindex235 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1, 2});
      slog::Relation* readrel292 = db->getRelation("lambda");
      lambdaindex236 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1, 2});
      slog::Relation* readrel294 = db->getRelation("lambda");
      lambdadelta241 = readrel294->getIndex(ord293, true);
  
    }
    ReadTask242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex218, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex219, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex220, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex221, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex222, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m295) {
          u64 v_c33 = m295[1];
          slog::join_probe<3,1>(evalindex223, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m296) {
            u64 v_c34 = m296[1]; u64 v_c35 = m296[2];
            if (!slog::exists_probe<3,2>(tickindex224, std::array<u64,3>{v_c35, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex225, appdelta237, std::array<u64,3>{v_c35, v_c12, 0}, [&](const std::array<u64,3>& m297) {
              u64 v_c13 = m297[2];
              slog::join_probe_old<3,2>(eval_argsindex226, eval_argsdelta238, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m298) {
                u64 v_c36 = m298[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex227, std::array<u64,2>{v_c36, 0})) return;
                slog::join_probe_old<3,2>(tickindex228, tickdelta239, std::array<u64,3>{v_c35, v_c2, 0}, [&](const std::array<u64,3>& m299) {
                  u64 v_c37 = m299[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex229, std::array<u64,2>{v_c37, 0})) return;
                  slog::join_probe<2,1>(eval_args_ansindex230, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m300) {
                    u64 v_c18 = m300[1];
                    slog::join_probe<2,1>(tick_ansindex231, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m301) {
                      u64 v_c38 = m301[1];
                      slog::join_probe_old<3,1>(closureindex232, closuredelta240, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m302) {
                        u64 v_c39 = m302[1]; u64 v_c21 = m302[2];
                        if (!slog::exists_probe<3,1>(bindingindex233, std::array<u64,3>{v_c21, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex234, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m303) {
                          u64 v_c40 = m303[1];
                          slog::join_probe<3,2>(bindingindex235, std::array<u64,3>{v_c40, v_c21, 0}, [&](const std::array<u64,3>& m304) {
                            u64 v_c41 = m304[2];
                            slog::join_probe_old<3,1>(lambdaindex236, lambdadelta241, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m305) {
                              u64 v_c22 = m305[1]; u64 v_c1 = m305[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c40, v_c38, v_c41}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c40, v_c38, v_c2}, std::array<u16,3>{0, 1, 2});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask242* _cont = new ReadTask242(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask242(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (exists closure (2 0 1) 1 cb) (join freevar (0 1) 1 y __t0xip28) (join-old closure (1 2 0) 2 (1 2 0) __t0xip28 cb __t3Pto26) (join eval_ans (1 0) 1 __t3Pto26 __t5MCM24) (join-old eval (0 2 1) 1 (0 2 1) __t5MCM24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0DSy30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask331 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex306;  slog::Index** freevarindex307;  slog::Index** closureindex308;  slog::Index** eval_ansindex309;  slog::Index** evalindex310;  slog::Index** appindex311;  slog::Index** eval_argsindex312;  slog::Index** tickindex313;  slog::Index** evalindex314;  slog::Index** tickindex315;  slog::Index** appindex316;  slog::Index** eval_argsindex317;  slog::Index** eval_args_ansindex318;  slog::Index** tickindex319;  slog::Index** tick_ansindex320;  slog::Index** eval_args_ansindex321;  slog::Index** tick_ansindex322;  slog::Index** lambdaindex323;  slog::Index** closuredelta324;  slog::Index** evaldelta325;  slog::Index** appdelta326;  slog::Index** eval_argsdelta327;  slog::Index** tickdelta328;  slog::Index** tick_ansdelta329;  slog::Index** lambdadelta330;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord332({0, 1, 2});
      slog::Relation* readrel333 = db->getRelation("binding");
      head_index[0] = readrel333->getIndex(ord332, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord334({0, 1, 2});
      slog::Relation* readrel335 = db->getRelation("binding_event");
      head_index[1] = readrel335->getIndex(ord334, false);
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord336({2, 0, 1});
      slog::Relation* readrel337 = db->getRelation("closure");
      closureindex306 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("freevar");
      freevarindex307 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 2, 0});
      slog::Relation* readrel341 = db->getRelation("closure");
      closureindex308 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 0});
      slog::Relation* readrel343 = db->getRelation("closure");
      closuredelta324 = readrel343->getIndex(ord342, true);
      std::vector<u16> ord344({1, 0});
      slog::Relation* readrel345 = db->getRelation("eval_ans");
      eval_ansindex309 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 2, 1});
      slog::Relation* readrel347 = db->getRelation("eval");
      evalindex310 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 2, 1});
      slog::Relation* readrel349 = db->getRelation("eval");
      evaldelta325 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("app");
      appindex311 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({2, 0, 1});
      slog::Relation* readrel353 = db->getRelation("eval_args");
      eval_argsindex312 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({2, 0, 1});
      slog::Relation* readrel355 = db->getRelation("tick");
      tickindex313 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({2, 0, 1});
      slog::Relation* readrel357 = db->getRelation("eval");
      evalindex314 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("tick");
      tickindex315 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1, 2});
      slog::Relation* readrel361 = db->getRelation("app");
      appindex316 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({0, 1, 2});
      slog::Relation* readrel363 = db->getRelation("app");
      appdelta326 = readrel363->getIndex(ord362, true);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("eval_args");
      eval_argsindex317 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 2, 0});
      slog::Relation* readrel367 = db->getRelation("eval_args");
      eval_argsdelta327 = readrel367->getIndex(ord366, true);
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("eval_args_ans");
      eval_args_ansindex318 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 2, 0});
      slog::Relation* readrel371 = db->getRelation("tick");
      tickindex319 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 0});
      slog::Relation* readrel373 = db->getRelation("tick");
      tickdelta328 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({0, 1});
      slog::Relation* readrel375 = db->getRelation("tick_ans");
      tick_ansindex320 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("eval_args_ans");
      eval_args_ansindex321 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("tick_ans");
      tick_ansindex322 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("tick_ans");
      tick_ansdelta329 = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({0, 1, 2});
      slog::Relation* readrel383 = db->getRelation("lambda");
      lambdaindex323 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1, 2});
      slog::Relation* readrel385 = db->getRelation("lambda");
      lambdadelta330 = readrel385->getIndex(ord384, true);
  
    }
    ReadTask331(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c41 = _t[2];
        if (!slog::exists_probe<3,1>(closureindex306, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex307, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m386) {
          u64 v_c39 = m386[1];
          slog::join_probe_old<3,2>(closureindex308, closuredelta324, std::array<u64,3>{v_c39, v_c21, 0}, [&](const std::array<u64,3>& m387) {
            u64 v_c33 = m387[2];
            slog::join_probe<2,1>(eval_ansindex309, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m388) {
              u64 v_c32 = m388[1];
              slog::join_probe_old<3,1>(evalindex310, evaldelta325, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m389) {
                u64 v_c2 = m389[1]; u64 v_c12 = m389[2];
                if (!slog::exists_probe<3,1>(appindex311, std::array<u64,3>{v_c12, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex312, std::array<u64,3>{v_c2, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex313, std::array<u64,3>{v_c2, 0, 0})) return;
                slog::join_probe<3,1>(evalindex314, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m390) {
                  u64 v_c34 = m390[1]; u64 v_c35 = m390[2];
                  if (!slog::exists_probe<3,2>(tickindex315, std::array<u64,3>{v_c35, v_c2, 0})) return;
                  slog::join_probe_old<3,2>(appindex316, appdelta326, std::array<u64,3>{v_c35, v_c12, 0}, [&](const std::array<u64,3>& m391) {
                    u64 v_c13 = m391[2];
                    slog::join_probe_old<3,2>(eval_argsindex317, eval_argsdelta327, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m392) {
                      u64 v_c36 = m392[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex318, std::array<u64,2>{v_c36, 0})) return;
                      slog::join_probe_old<3,2>(tickindex319, tickdelta328, std::array<u64,3>{v_c35, v_c2, 0}, [&](const std::array<u64,3>& m393) {
                        u64 v_c37 = m393[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex320, std::array<u64,2>{v_c37, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex321, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m394) {
                          u64 v_c18 = m394[1];
                          slog::join_probe_old<2,1>(tick_ansindex322, tick_ansdelta329, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m395) {
                            u64 v_c38 = m395[1];
                            slog::join_probe_old<3,1>(lambdaindex323, lambdadelta330, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m396) {
                              u64 v_c22 = m396[1]; u64 v_c1 = m396[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c40, v_c38, v_c41}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c40, v_c38, v_c2}, std::array<u16,3>{0, 1, 2});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask331* _cont = new ReadTask331(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask331(db,b), false);
  // (crule (pre) (scan eval __t55UJ311 ef c) (body (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t55UJ311) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2HTD313) (exists eval_args_ans (0 1) 1 __t2HTD313) (join eval_ans (0 1) 1 __t55UJ311 __t9gUy312) (join eval_args_ans (0 1) 1 __t2HTD313 vs) (join-old prim (0 1) 1 (0 1) __t9gUy312 op)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
  class ReadTask407 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex397;  slog::Index** eval_ansindex398;  slog::Index** $sup56712x74x0x0x0index399;  slog::Index** eval_argsindex400;  slog::Index** eval_args_ansindex401;  slog::Index** eval_ansindex402;  slog::Index** eval_args_ansindex403;  slog::Index** primindex404;  slog::Index** eval_argsdelta405;  slog::Index** primdelta406;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord408({2, 0, 1});
      slog::Relation* readrel409 = db->getRelation("eval_args");
      eval_argsindex397 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("eval_ans");
      eval_ansindex398 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 3, 0});
      slog::Relation* readrel413 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index399 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("eval_args");
      eval_argsindex400 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 2, 0});
      slog::Relation* readrel417 = db->getRelation("eval_args");
      eval_argsdelta405 = readrel417->getIndex(ord416, true);
      std::vector<u16> ord418({0, 1});
      slog::Relation* readrel419 = db->getRelation("eval_args_ans");
      eval_args_ansindex401 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 1});
      slog::Relation* readrel421 = db->getRelation("eval_ans");
      eval_ansindex402 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("eval_args_ans");
      eval_args_ansindex403 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("prim");
      primindex404 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("prim");
      primdelta406 = readrel427->getIndex(ord426, true);
  
    }
    ReadTask407(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex397, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex398, std::array<u64,2>{v_c42, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index399, std::array<u64,4>{v_c2, v_c12, 0, 0}, [&](const std::array<u64,4>& m428) {
          u64 v_c13 = m428[2]; u64 v_c14 = m428[3];
          slog::join_probe_old<3,2>(eval_argsindex400, eval_argsdelta405, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m429) {
            u64 v_c43 = m429[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex401, std::array<u64,2>{v_c43, 0})) return;
            slog::join_probe<2,1>(eval_ansindex402, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m430) {
              u64 v_c44 = m430[1];
              slog::join_probe<2,1>(eval_args_ansindex403, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m431) {
                u64 v_c18 = m431[1];
                slog::join_probe_old<2,1>(primindex404, primdelta406, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m432) {
                  u64 v_c45 = m432[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c45, v_c18}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask407* _cont = new ReadTask407(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask407(db,b), false);
  // (crule (pre (let __trid2nQ3792 const781eda039ec10c193395ca07) (let __trel5oEP793 const4a59dbb9cb3129dfcc75170b) (let __tcol087F794 const5feceb66ffc86f38d952786c) (let __trel9QXn795 const4a59dbb9cb3129dfcc75170b) (let __tcol9WyH796 const6b86b273ff34fce19d6b804e)) (scan $sup56712x93x0x0x0 __d0 c eb er x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid2nQ3792 __trel5oEP793 __tcol087F794 (1 2 3 4 0)) (tycheck c (accept seq) __trid2nQ3792 __trel9QXn795 __tcol9WyH796 (1 2 3 4 0)) (mkstruct eval (1 2 0) __9w6m791 er c)) interp.slog:94 #f)
  class ReadTask442 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid433;  u32 sid434;  u32 sid435;  u32 sid436;  u32 sid437;  u32 sid438;  u32 sid439;  u32 sid440;  u32 sid441;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      sid433 = db->getRelation("app")->getStructId();
      sid434 = db->getRelation("boolean")->getStructId();
      sid435 = db->getRelation("if")->getStructId();
      sid436 = db->getRelation("lambda")->getStructId();
      sid437 = db->getRelation("let")->getStructId();
      sid438 = db->getRelation("letrec")->getStructId();
      sid439 = db->getRelation("num")->getStructId();
      sid440 = db->getRelation("ref")->getStructId();
      sid441 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask442(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c46 = v_const781eda039ec10c193395ca07;
      u64 v_c47 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
      u64 v_c49 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c14 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c5 = _t[4];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid433 || decode_struct_id(v_c4) == sid434 || decode_struct_id(v_c4) == sid435 || decode_struct_id(v_c4) == sid436 || decode_struct_id(v_c4) == sid437 || decode_struct_id(v_c4) == sid438 || decode_struct_id(v_c4) == sid439 || decode_struct_id(v_c4) == sid440 || decode_struct_id(v_c4) == sid441))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c46, v_c47, v_c48, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c46, v_c49, v_c50, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:$sup56712x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask442* _cont = new ReadTask442(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask442(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst0VKF494 const20c400557af0eddc0be4d9e0) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst6Qri486 const7265b875feb0d1730ead43d3) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst6Aow470 const49e9fcfb5617aad332d56d58) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4) (let __tconst49VM461 constb85d38dc71a8027700bebd3c) (let __tconst3zss458 const06abaa100ecef791ce028c56) (let __t7qtp495 (lempty))) (once) (body) (head (emit-temp temp34Hd1007 __t7qtp495) (mkstruct ref (1 0) __t6o9z493 __tconst0VKF494) (mkstruct ref (1 0) __t6Nc8484 __tconst8pH5498) (mkstruct ref (1 0) __t7D13480 __tconst6Qri486) (mkstruct sym (1 0) __t3yjc471 __tconst6Aow470) (mkstruct ref (1 0) __t58rC466 __tconst7G6n490) (mkstruct sym (1 0) __t7EYF462 __tconst49VM461) (mkstruct ref (1 0) __t0Jxw459 __tconst3zss458) (mkstruct ref (1 0) __t2pSO454 __tconst49ZO477) (mkstruct ref (1 0) __t7Te9452 __tconst2M9b468)) schemecfa.slog:51 #f)
  class ReadTask443 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[10];
    slog::Index** head_index[10];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp34Hd1007");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("sym");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("sym");
      head_rel[7] = db->getRelation("ref");
      head_rel[8] = db->getRelation("ref");
      head_rel[9] = db->getRelation("ref");
  
    }
    ReadTask443(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c52 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c53 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c54 = v_const7265b875feb0d1730ead43d3;
      u64 v_c55 = v_const0fc34686741291b4dd06511b;
      u64 v_c56 = v_const49e9fcfb5617aad332d56d58;
      u64 v_c57 = v_const39c6f8839ca547fa7b7a32c4;
      u64 v_c58 = v_constb85d38dc71a8027700bebd3c;
      u64 v_c59 = v_const06abaa100ecef791ce028c56;
      u64 v_c60 = _prim_lempty(db);
      if (v_c60 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[10];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
      newbatch[9] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c60});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c52}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c54}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c56}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c53}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c58}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c59}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c55}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[9], newbatch[9], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
        head_rel[9]->sendBatch(newbatch[9]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask443(db,b), true);
  // (crule (pre) (scan eval __36hc798 __t36c5191 c) (body (join-old app (0 1 2) 1 (0 1 2) __t36c5191 ef es) (join freevar (0 1) 0 y __t75gL192) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t75gL192 xs eb)) (head (mkstruct eval_args (1 2 0) __9QEA799 es c)) interp.slog:56 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex444;  slog::Index** freevarindex445;  slog::Index** bindingindex446;  slog::Index** lambdaindex447;  slog::Index** appdelta448;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord450({0, 1, 2});
      slog::Relation* readrel451 = db->getRelation("app");
      appindex444 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({0, 1, 2});
      slog::Relation* readrel453 = db->getRelation("app");
      appdelta448 = readrel453->getIndex(ord452, true);
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("freevar");
      freevarindex445 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 1, 2});
      slog::Relation* readrel457 = db->getRelation("binding");
      bindingindex446 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1, 2});
      slog::Relation* readrel459 = db->getRelation("lambda");
      lambdaindex447 = readrel459->getIndex(ord458, false);
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c61 = _t[0];
        u64 v_c62 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex444, appdelta448, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m460) {
          u64 v_c12 = m460[1]; u64 v_c13 = m460[2];
          slog::join_all<2>(freevarindex445, [&](const std::array<u64,2>& m461) {
            u64 v_c40 = m461[0]; u64 v_c63 = m461[1];
            slog::join_probe<3,1>(bindingindex446, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m462) {
              u64 v_c21 = m462[1]; u64 v_c41 = m462[2];
              slog::join_probe<3,1>(lambdaindex447, std::array<u64,3>{v_c63, 0, 0}, [&](const std::array<u64,3>& m463) {
                u64 v_c22 = m463[1]; u64 v_c1 = m463[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
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
  // (crule (pre) (scan tick_ans __t3KuN210 __v0) (body (join-old eval (2 0 1) 1 (2 0 1) __v0 __t3K5j208 eb) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t3K5j208 v) (join-old lambda (2 0 1) 1 (2 0 1) eb __t6hhS205 xs) (join-old closure (1 2 0) 1 (1 2 0) __t6hhS205 cb __t6XAE206) (join eval_ans (1 0) 1 __t6XAE206 __t1DkM204) (join-old eval (0 2 1) 1 (0 2 1) __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t3KuN210 c __t8x6E209) (exists app (0 1 2) 2 __t8x6E209 ef) (join-old eval (1 2 0) 2 (1 2 0) __t8x6E209 c __t9lTe203) (join-old $sup56712x41x0x0x0 (1 0 2 3) 3 (1 0 2 3) c __t9lTe203 ef es) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (join eval_args_ans (0 1) 1 __t58jO207 vs)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex464;  slog::Index** lambdaindex465;  slog::Index** eval_ansindex466;  slog::Index** lambdaindex467;  slog::Index** closureindex468;  slog::Index** eval_ansindex469;  slog::Index** evalindex470;  slog::Index** evalindex471;  slog::Index** $sup56712x41x0x0x0index472;  slog::Index** appindex473;  slog::Index** eval_argsindex474;  slog::Index** tickindex475;  slog::Index** appindex476;  slog::Index** evalindex477;  slog::Index** $sup56712x41x0x0x0index478;  slog::Index** appindex479;  slog::Index** eval_argsindex480;  slog::Index** eval_args_ansindex481;  slog::Index** evaldelta482;  slog::Index** lambdadelta483;  slog::Index** closuredelta484;  slog::Index** evaldelta485;  slog::Index** tickdelta486;  slog::Index** evaldelta487;  slog::Index** $sup56712x41x0x0x0delta488;  slog::Index** appdelta489;  slog::Index** eval_argsdelta490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("eval_ans");
      head_index[0] = readrel493->getIndex(ord492, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord494({2, 0, 1});
      slog::Relation* readrel495 = db->getRelation("eval");
      evalindex464 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({2, 0, 1});
      slog::Relation* readrel497 = db->getRelation("eval");
      evaldelta482 = readrel497->getIndex(ord496, true);
      std::vector<u16> ord498({2, 0, 1});
      slog::Relation* readrel499 = db->getRelation("lambda");
      lambdaindex465 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 1});
      slog::Relation* readrel501 = db->getRelation("eval_ans");
      eval_ansindex466 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({2, 0, 1});
      slog::Relation* readrel503 = db->getRelation("lambda");
      lambdaindex467 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({2, 0, 1});
      slog::Relation* readrel505 = db->getRelation("lambda");
      lambdadelta483 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("closure");
      closureindex468 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("closure");
      closuredelta484 = readrel509->getIndex(ord508, true);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("eval_ans");
      eval_ansindex469 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 2, 1});
      slog::Relation* readrel513 = db->getRelation("eval");
      evalindex470 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 2, 1});
      slog::Relation* readrel515 = db->getRelation("eval");
      evaldelta485 = readrel515->getIndex(ord514, true);
      std::vector<u16> ord516({2, 0, 1});
      slog::Relation* readrel517 = db->getRelation("eval");
      evalindex471 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 3, 0});
      slog::Relation* readrel519 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index472 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 2, 0});
      slog::Relation* readrel521 = db->getRelation("app");
      appindex473 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({2, 0, 1});
      slog::Relation* readrel523 = db->getRelation("eval_args");
      eval_argsindex474 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({0, 2, 1});
      slog::Relation* readrel525 = db->getRelation("tick");
      tickindex475 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 2, 1});
      slog::Relation* readrel527 = db->getRelation("tick");
      tickdelta486 = readrel527->getIndex(ord526, true);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("app");
      appindex476 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("eval");
      evalindex477 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("eval");
      evaldelta487 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({1, 0, 2, 3});
      slog::Relation* readrel535 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index478 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 0, 2, 3});
      slog::Relation* readrel537 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta488 = readrel537->getIndex(ord536, true);
      std::vector<u16> ord538({0, 1, 2});
      slog::Relation* readrel539 = db->getRelation("app");
      appindex479 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({0, 1, 2});
      slog::Relation* readrel541 = db->getRelation("app");
      appdelta489 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({1, 2, 0});
      slog::Relation* readrel543 = db->getRelation("eval_args");
      eval_argsindex480 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 2, 0});
      slog::Relation* readrel545 = db->getRelation("eval_args");
      eval_argsdelta490 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({0, 1});
      slog::Relation* readrel547 = db->getRelation("eval_args_ans");
      eval_args_ansindex481 = readrel547->getIndex(ord546, false);
  
    }
    ReadTask491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[1];
        slog::join_probe_old<3,1>(evalindex464, evaldelta482, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m548) {
          u64 v_c65 = m548[1]; u64 v_c1 = m548[2];
          if (!slog::exists_probe<3,1>(lambdaindex465, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe<2,1>(eval_ansindex466, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m549) {
            u64 v_c9 = m549[1];
            slog::join_probe_old<3,1>(lambdaindex467, lambdadelta483, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m550) {
              u64 v_c66 = m550[1]; u64 v_c22 = m550[2];
              slog::join_probe_old<3,1>(closureindex468, closuredelta484, std::array<u64,3>{v_c66, 0, 0}, [&](const std::array<u64,3>& m551) {
                u64 v_c21 = m551[1]; u64 v_c67 = m551[2];
                slog::join_probe<2,1>(eval_ansindex469, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m552) {
                  u64 v_c68 = m552[1];
                  slog::join_probe_old<3,1>(evalindex470, evaldelta485, std::array<u64,3>{v_c68, 0, 0}, [&](const std::array<u64,3>& m553) {
                    u64 v_c2 = m553[1]; u64 v_c12 = m553[2];
                    if (!slog::exists_probe<3,1>(evalindex471, std::array<u64,3>{v_c2, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index472, std::array<u64,4>{v_c2, v_c12, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex473, std::array<u64,3>{v_c12, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex474, std::array<u64,3>{v_c2, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex475, tickdelta486, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m554) {
                      u64 v_c69 = m554[2];
                      if (!slog::exists_probe<3,2>(appindex476, std::array<u64,3>{v_c69, v_c12, 0})) return;
                      slog::join_probe_old<3,2>(evalindex477, evaldelta487, std::array<u64,3>{v_c69, v_c2, 0}, [&](const std::array<u64,3>& m555) {
                        u64 v_c70 = m555[2];
                        slog::join_probe_old<4,3>($sup56712x41x0x0x0index478, $sup56712x41x0x0x0delta488, std::array<u64,4>{v_c2, v_c70, v_c12, 0}, [&](const std::array<u64,4>& m556) {
                          u64 v_c13 = m556[3];
                          slog::join_probe_old<3,3>(appindex479, appdelta489, std::array<u64,3>{v_c69, v_c12, v_c13}, [&](const std::array<u64,3>& m557) {
                            slog::join_probe_old<3,2>(eval_argsindex480, eval_argsdelta490, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m558) {
                              u64 v_c71 = m558[2];
                              slog::join_probe<2,1>(eval_args_ansindex481, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m559) {
                                u64 v_c18 = m559[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c9}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask491* _cont = new ReadTask491(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask491(db,b), false);
  // (crule (pre (let _00024sqc2oXB553 const6b86b273ff34fce19d6b804e) (let _00024sqc3Uyr554 const5feceb66ffc86f38d952786c) (let _00024sqc24j5555 const6b86b273ff34fce19d6b804e) (let _00024sqc6qhn556 const5feceb66ffc86f38d952786c) (let __t4EG4161 (lempty))) (scan freevar_in_args x es) (body (join-old argument_list (0) 0 (0) _00024seq0) (letp _00024sql1b7l551 (aslst _00024seq0)) (let _00024sqn9FNh552 (llen _00024sql1b7l551)) (cmp ge _00024sqn9FNh552 _00024sqc2oXB553) (letp e (lref _00024sql1b7l551 _00024sqc3Uyr554)) (let _00024sqp9dtl557 (_0002d _00024sqn9FNh552 _00024sqc6qhn556)) (let chk3yIA1006 (lslice _00024sql1b7l551 _00024sqc24j5555 _00024sqp9dtl557)) (eq es chk3yIA1006)) (head (emit-temp temp2Fk51003 __t4EG4161 e es x)) freevars.slog:35 #f)
  class ReadTask562 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** argument_listindex560;  slog::Index** argument_listdelta561;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Fk51003");
      outer_rel = db->getRelation("freevar_in_args");
      std::vector<u16> ord563({0});
      slog::Relation* readrel564 = db->getRelation("argument_list");
      argument_listindex560 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({0});
      slog::Relation* readrel566 = db->getRelation("argument_list");
      argument_listdelta561 = readrel566->getIndex(ord565, true);
  
    }
    ReadTask562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
      u64 v_c76 = _prim_lempty(db);
      if (v_c76 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_all_old<1>(argument_listindex560, argument_listdelta561, [&](const std::array<u64,1>& m567) {
          u64 v_c77 = m567[0];
          bool ok568 = true;
          u64 v_c78 = _prim_aslst(db, v_c77, &ok568);
          if (!ok568) return;
          u64 v_c79 = _prim_llen(db, v_c78);
          if (v_c79 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          u64 v_c80 = _prim_ge(db, v_c79, v_c72);
          if (v_c80 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          if (!v_c80) return;
          bool ok570 = true;
          u64 v_c81 = _prim_lref(db, v_c78, v_c73, &ok570);
          if (!ok570) return;
          u64 v_c82 = _prim__0002d(db, v_c79, v_c75);
          if (v_c82 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          u64 v_c83 = _prim_lslice(db, v_c78, v_c74, v_c82);
          if (v_c83 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          if (v_c13 != v_c83) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c81, v_c13, v_c5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:freevar_in_args", _fires);
  
      if (!_done)
      {
        ReadTask562* _cont = new ReadTask562(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask562(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (scan boolval __t1b46247 b) (body (exists $seq_at (1 0 2) 2 _00024sqo0NcP667 __t1b46247) (exists $seq_atr (1 0 2) 2 _00024sqo0X3t668 __t1b46247) (exists $seq_atr (1 0 2) 2 _00024sqo6VJl669 __t1b46247) (exists delta (1 2 0) 1 __tconst35kI244) (exists _enum (1 0) 1 __tconst7knU761) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo8MNY666 __t1b46247 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0NcP667 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0X3t668 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo6VJl669 __t1b46247 _00024seq2) (join delta (1 2 0) 2 __tconst35kI244 _00024seq2 __t7NfZ245) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (letp _00024sql4qXJ661 (aslst _00024seq2)) (let chk5KGq965 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk5KGq965) (letp chk3rN0966 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (eq __t1b46247 chk3rN0966) (letp chk3ItQ967 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk3ItQ967)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex571;  slog::Index** $seq_atrindex572;  slog::Index** $seq_atrindex573;  slog::Index** deltaindex574;  slog::Index** _enumindex575;  slog::Index** $seq_atindex576;  slog::Index** $seq_atindex577;  slog::Index** $seq_atrindex578;  slog::Index** $seq_atrindex579;  slog::Index** deltaindex580;  slog::Index** _enumindex581;  slog::Index** $seq_atdelta582;  slog::Index** $seq_atdelta583;  slog::Index** $seq_atrdelta584;  slog::Index** $seq_atrdelta585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord587({1, 0, 2});
      slog::Relation* readrel588 = db->getRelation("$seq_at");
      $seq_atindex571 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 0, 2});
      slog::Relation* readrel590 = db->getRelation("$seq_atr");
      $seq_atrindex572 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 0, 2});
      slog::Relation* readrel592 = db->getRelation("$seq_atr");
      $seq_atrindex573 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 2, 0});
      slog::Relation* readrel594 = db->getRelation("delta");
      deltaindex574 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 0});
      slog::Relation* readrel596 = db->getRelation("_enum");
      _enumindex575 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 0, 2});
      slog::Relation* readrel598 = db->getRelation("$seq_at");
      $seq_atindex576 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 0, 2});
      slog::Relation* readrel600 = db->getRelation("$seq_at");
      $seq_atdelta582 = readrel600->getIndex(ord599, true);
      std::vector<u16> ord601({1, 0, 2});
      slog::Relation* readrel602 = db->getRelation("$seq_at");
      $seq_atindex577 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 0, 2});
      slog::Relation* readrel604 = db->getRelation("$seq_at");
      $seq_atdelta583 = readrel604->getIndex(ord603, true);
      std::vector<u16> ord605({1, 0, 2});
      slog::Relation* readrel606 = db->getRelation("$seq_atr");
      $seq_atrindex578 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 0, 2});
      slog::Relation* readrel608 = db->getRelation("$seq_atr");
      $seq_atrdelta584 = readrel608->getIndex(ord607, true);
      std::vector<u16> ord609({1, 0, 2});
      slog::Relation* readrel610 = db->getRelation("$seq_atr");
      $seq_atrindex579 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({1, 0, 2});
      slog::Relation* readrel612 = db->getRelation("$seq_atr");
      $seq_atrdelta585 = readrel612->getIndex(ord611, true);
      std::vector<u16> ord613({1, 2, 0});
      slog::Relation* readrel614 = db->getRelation("delta");
      deltaindex580 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 0});
      slog::Relation* readrel616 = db->getRelation("_enum");
      _enumindex581 = readrel616->getIndex(ord615, false);
  
    }
    ReadTask586(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c85 = v_const06abaa100ecef791ce028c56;
      u64 v_c86 = v_constd4735e3a265e16eee03f5971;
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c94 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex571, std::array<u64,3>{v_c90, v_c93, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex572, std::array<u64,3>{v_c91, v_c93, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex573, std::array<u64,3>{v_c92, v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex574, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex575, std::array<u64,2>{v_c84, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex576, $seq_atdelta582, std::array<u64,3>{v_c89, v_c93, 0}, [&](const std::array<u64,3>& m617) {
          u64 v_c95 = m617[2];
          slog::join_probe_old<3,3>($seq_atindex577, $seq_atdelta583, std::array<u64,3>{v_c90, v_c93, v_c95}, [&](const std::array<u64,3>& m618) {
            slog::join_probe_old<3,3>($seq_atrindex578, $seq_atrdelta584, std::array<u64,3>{v_c91, v_c93, v_c95}, [&](const std::array<u64,3>& m619) {
              slog::join_probe_old<3,3>($seq_atrindex579, $seq_atrdelta585, std::array<u64,3>{v_c92, v_c93, v_c95}, [&](const std::array<u64,3>& m620) {
                slog::join_probe<3,2>(deltaindex580, std::array<u64,3>{v_c85, v_c95, 0}, [&](const std::array<u64,3>& m621) {
                  u64 v_c96 = m621[2];
                  slog::join_probe<2,1>(_enumindex581, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m622) {
                    u64 v_c97 = m622[1];
                    bool ok623 = true;
                    u64 v_c98 = _prim_aslst(db, v_c95, &ok623);
                    if (!ok623) return;
                    u64 v_c99 = _prim_llen(db, v_c98);
                    if (v_c99 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c86 != v_c99) return;
                    bool ok624 = true;
                    u64 v_c100 = _prim_lref(db, v_c98, v_c87, &ok624);
                    if (!ok624) return;
                    if (v_c93 != v_c100) return;
                    bool ok625 = true;
                    u64 v_c101 = _prim_lref(db, v_c98, v_c88, &ok625);
                    if (!ok625) return;
                    if (v_c93 != v_c101) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c96});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c97}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:boolval", _fires);
  
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
  // (crule (pre) (scan let __t17FH236 x er eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t17FH236 c __t1YLG237)) (head (emit $sup56712x91x0x0x0 (0 1 2 3 4) __t1YLG237 c eb er x)) interp.slog:92 #f)
  class ReadTask628 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex626;  slog::Index** evaldelta627;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord629({0, 1, 2, 3, 4});
      slog::Relation* readrel630 = db->getRelation("$sup56712x91x0x0x0");
      head_index[0] = readrel630->getIndex(ord629, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord631({1, 2, 0});
      slog::Relation* readrel632 = db->getRelation("eval");
      evalindex626 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({1, 2, 0});
      slog::Relation* readrel634 = db->getRelation("eval");
      evaldelta627 = readrel634->getIndex(ord633, true);
  
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
        u64 v_c102 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c1 = _t[3];
        slog::join_probe_old<3,1>(evalindex626, evaldelta627, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m635) {
          u64 v_c2 = m635[1]; u64 v_c103 = m635[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c103, v_c2, v_c1, v_c4, v_c5}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:let", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre2eJm923 __errf0IfE924 __errf0NOE925) (body) (head (emit error (0) __erre2eJm923)) <internal>:1 #f)
  class ReadTask636 : public slog::Task
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
      std::vector<u16> ord637({0});
      slog::Relation* readrel638 = db->getRelation("error");
      head_index[0] = readrel638->getIndex(ord637, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask636(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c104 = _t[0];
        u64 v_c105 = _t[1];
        u64 v_c106 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c104}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask636* _cont = new ReadTask636(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask636(db,b), false);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9) (let __tconst5n8U262 const0933fb667296882d8c45abca) (let __tconst3Rob283 const90fb9068eda6f2d68bb61c33)) (scan temp3sak1052 __t0vlN275 __t5GYK254 __t6cev261 __t6dUB289 __t6t5b288 __t9Oif282) (body (exists app (2 0 1) 1 __t9Oif282) (exists ref (1 0) 1 __tconst5n8U262) (exists app (2 0 1) 1 __t6cev261) (exists ref (1 0) 1 __tconst4G37291) (join ref (1 0) 1 __tconst3Rob283 __t88QE284) (join app (1 2 0) 2 __t88QE284 __t9Oif282 __t5TOH285) (join ref (1 0) 1 __tconst5n8U262 __t4C1l263) (join app (1 2 0) 2 __t4C1l263 __t6cev261 __t4piH264) (join ref (1 0) 1 __tconst4G37291 __t8oYB253) (let __t0O3R266 (lpush __t6t5b288 __t4piH264))) (head (emit-temp temp8yir1053 __t0O3R266 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289)) schemecfa.slog:70 #f)
  class ReadTask648 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex639;  slog::Index** refindex640;  slog::Index** appindex641;  slog::Index** refindex642;  slog::Index** refindex643;  slog::Index** appindex644;  slog::Index** refindex645;  slog::Index** appindex646;  slog::Index** refindex647;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8yir1053");
      outer_rel = db->getRelation("temp3sak1052");
      std::vector<u16> ord649({2, 0, 1});
      slog::Relation* readrel650 = db->getRelation("app");
      appindex639 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 0});
      slog::Relation* readrel652 = db->getRelation("ref");
      refindex640 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({2, 0, 1});
      slog::Relation* readrel654 = db->getRelation("app");
      appindex641 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({1, 0});
      slog::Relation* readrel656 = db->getRelation("ref");
      refindex642 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({1, 0});
      slog::Relation* readrel658 = db->getRelation("ref");
      refindex643 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 0});
      slog::Relation* readrel660 = db->getRelation("app");
      appindex644 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 0});
      slog::Relation* readrel662 = db->getRelation("ref");
      refindex645 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 2, 0});
      slog::Relation* readrel664 = db->getRelation("app");
      appindex646 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 0});
      slog::Relation* readrel666 = db->getRelation("ref");
      refindex647 = readrel666->getIndex(ord665, false);
  
    }
    ReadTask648(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const889c19fd926bc4ca61c0b4d9;
      u64 v_c108 = v_const0933fb667296882d8c45abca;
      u64 v_c109 = v_const90fb9068eda6f2d68bb61c33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        u64 v_c111 = _t[1];
        u64 v_c112 = _t[2];
        u64 v_c113 = _t[3];
        u64 v_c114 = _t[4];
        u64 v_c115 = _t[5];
        if (!slog::exists_probe<3,1>(appindex639, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex640, std::array<u64,2>{v_c108, 0})) return;
        if (!slog::exists_probe<3,1>(appindex641, std::array<u64,3>{v_c112, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex642, std::array<u64,2>{v_c107, 0})) return;
        slog::join_probe<2,1>(refindex643, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m667) {
          u64 v_c116 = m667[1];
          slog::join_probe<3,2>(appindex644, std::array<u64,3>{v_c116, v_c115, 0}, [&](const std::array<u64,3>& m668) {
            u64 v_c117 = m668[2];
            slog::join_probe<2,1>(refindex645, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m669) {
              u64 v_c118 = m669[1];
              slog::join_probe<3,2>(appindex646, std::array<u64,3>{v_c118, v_c112, 0}, [&](const std::array<u64,3>& m670) {
                u64 v_c119 = m670[2];
                slog::join_probe<2,1>(refindex647, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m671) {
                  u64 v_c120 = m671[1];
                  u64 v_c121 = _prim_lpush(db, v_c114, v_c119);
                  if (v_c121 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c110, v_c111, v_c117, v_c113});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp3sak1052", _fires);
  
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
  // (crule (pre) (scan if __t2D2o102 e1 e2 e3) (body (exists eval (1 2 0) 1 __t2D2o102) (exists eval (1 2 0) 1 e1) (exists select_branch (2 3 0 1) 2 e2 e3) (join $sup56712x86x0x0x0 (3 4 2 0 1) 3 e2 e3 e1 __t9HBz103 c) (join-old eval (0 2 1) 3 (0 2 1) __t9HBz103 c __t2D2o102) (exists eval (2 0 1) 1 c) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t0Z2s104) (exists eval_ans (0 1) 1 __t0Z2s104) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t8m22105 __v0) (join eval_ans (0 1) 2 __t0Z2s104 __v0) (join select_branch_ans (0 1) 1 __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join eval_ans (0 1) 1 __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask689 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex672;  slog::Index** evalindex673;  slog::Index** select_branchindex674;  slog::Index** $sup56712x86x0x0x0index675;  slog::Index** evalindex676;  slog::Index** evalindex677;  slog::Index** evalindex678;  slog::Index** eval_ansindex679;  slog::Index** select_branchindex680;  slog::Index** eval_ansindex681;  slog::Index** select_branch_ansindex682;  slog::Index** evalindex683;  slog::Index** eval_ansindex684;  slog::Index** evaldelta685;  slog::Index** evaldelta686;  slog::Index** select_branchdelta687;  slog::Index** evaldelta688;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord690({0, 1});
      slog::Relation* readrel691 = db->getRelation("eval_ans");
      head_index[0] = readrel691->getIndex(ord690, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("eval");
      evalindex672 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("eval");
      evalindex673 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({2, 3, 0, 1});
      slog::Relation* readrel697 = db->getRelation("select_branch");
      select_branchindex674 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({3, 4, 2, 0, 1});
      slog::Relation* readrel699 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index675 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 2, 1});
      slog::Relation* readrel701 = db->getRelation("eval");
      evalindex676 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 2, 1});
      slog::Relation* readrel703 = db->getRelation("eval");
      evaldelta685 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({2, 0, 1});
      slog::Relation* readrel705 = db->getRelation("eval");
      evalindex677 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 0});
      slog::Relation* readrel707 = db->getRelation("eval");
      evalindex678 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 2, 0});
      slog::Relation* readrel709 = db->getRelation("eval");
      evaldelta686 = readrel709->getIndex(ord708, true);
      std::vector<u16> ord710({0, 1});
      slog::Relation* readrel711 = db->getRelation("eval_ans");
      eval_ansindex679 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({2, 3, 0, 1});
      slog::Relation* readrel713 = db->getRelation("select_branch");
      select_branchindex680 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({2, 3, 0, 1});
      slog::Relation* readrel715 = db->getRelation("select_branch");
      select_branchdelta687 = readrel715->getIndex(ord714, true);
      std::vector<u16> ord716({0, 1});
      slog::Relation* readrel717 = db->getRelation("eval_ans");
      eval_ansindex681 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({0, 1});
      slog::Relation* readrel719 = db->getRelation("select_branch_ans");
      select_branch_ansindex682 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 2, 0});
      slog::Relation* readrel721 = db->getRelation("eval");
      evalindex683 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("eval");
      evaldelta688 = readrel723->getIndex(ord722, true);
      std::vector<u16> ord724({0, 1});
      slog::Relation* readrel725 = db->getRelation("eval_ans");
      eval_ansindex684 = readrel725->getIndex(ord724, false);
  
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
        u64 v_c122 = _t[0];
        u64 v_c123 = _t[1];
        u64 v_c124 = _t[2];
        u64 v_c125 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex672, std::array<u64,3>{v_c122, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex673, std::array<u64,3>{v_c123, 0, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex674, std::array<u64,4>{v_c124, v_c125, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x86x0x0x0index675, std::array<u64,5>{v_c124, v_c125, v_c123, 0, 0}, [&](const std::array<u64,5>& m726) {
          u64 v_c126 = m726[3]; u64 v_c2 = m726[4];
          slog::join_probe_old<3,3>(evalindex676, evaldelta685, std::array<u64,3>{v_c126, v_c2, v_c122}, [&](const std::array<u64,3>& m727) {
            if (!slog::exists_probe<3,1>(evalindex677, std::array<u64,3>{v_c2, 0, 0})) return;
            slog::join_probe_old<3,2>(evalindex678, evaldelta686, std::array<u64,3>{v_c123, v_c2, 0}, [&](const std::array<u64,3>& m728) {
              u64 v_c127 = m728[2];
              if (!slog::exists_probe<2,1>(eval_ansindex679, std::array<u64,2>{v_c127, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex680, select_branchdelta687, std::array<u64,4>{v_c124, v_c125, 0, 0}, [&](const std::array<u64,4>& m729) {
                u64 v_c128 = m729[2]; u64 v_c19 = m729[3];
                slog::join_probe<2,2>(eval_ansindex681, std::array<u64,2>{v_c127, v_c19}, [&](const std::array<u64,2>& m730) {
                  slog::join_probe<2,1>(select_branch_ansindex682, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m731) {
                    u64 v_c129 = m731[1];
                    slog::join_probe_old<3,2>(evalindex683, evaldelta688, std::array<u64,3>{v_c129, v_c2, 0}, [&](const std::array<u64,3>& m732) {
                      u64 v_c130 = m732[2];
                      slog::join_probe<2,1>(eval_ansindex684, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m733) {
                        u64 v_c131 = m733[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c126, v_c131}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:if", _fires);
  
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
  // (crule (pre) (scan $sup56712x74x0x0x0 __d0 c ef es) (body (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t55UJ311) (exists eval_ans (0 1) 1 __t55UJ311) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2HTD313) (exists eval_args_ans (0 1) 1 __t2HTD313) (join-old eval_ans (0 1) 1 (0 1) __t55UJ311 __t9gUy312) (join-old eval_args_ans (0 1) 1 (0 1) __t2HTD313 vs) (join-old prim (0 1) 1 (0 1) __t9gUy312 op)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
  class ReadTask747 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex734;  slog::Index** evalindex735;  slog::Index** eval_ansindex736;  slog::Index** eval_argsindex737;  slog::Index** eval_args_ansindex738;  slog::Index** eval_ansindex739;  slog::Index** eval_args_ansindex740;  slog::Index** primindex741;  slog::Index** evaldelta742;  slog::Index** eval_argsdelta743;  slog::Index** eval_ansdelta744;  slog::Index** eval_args_ansdelta745;  slog::Index** primdelta746;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord748({1, 2, 0});
      slog::Relation* readrel749 = db->getRelation("eval_args");
      eval_argsindex734 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("eval");
      evalindex735 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 0});
      slog::Relation* readrel753 = db->getRelation("eval");
      evaldelta742 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({0, 1});
      slog::Relation* readrel755 = db->getRelation("eval_ans");
      eval_ansindex736 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 2, 0});
      slog::Relation* readrel757 = db->getRelation("eval_args");
      eval_argsindex737 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("eval_args");
      eval_argsdelta743 = readrel759->getIndex(ord758, true);
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("eval_args_ans");
      eval_args_ansindex738 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("eval_ans");
      eval_ansindex739 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1});
      slog::Relation* readrel765 = db->getRelation("eval_ans");
      eval_ansdelta744 = readrel765->getIndex(ord764, true);
      std::vector<u16> ord766({0, 1});
      slog::Relation* readrel767 = db->getRelation("eval_args_ans");
      eval_args_ansindex740 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({0, 1});
      slog::Relation* readrel769 = db->getRelation("eval_args_ans");
      eval_args_ansdelta745 = readrel769->getIndex(ord768, true);
      std::vector<u16> ord770({0, 1});
      slog::Relation* readrel771 = db->getRelation("prim");
      primindex741 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 1});
      slog::Relation* readrel773 = db->getRelation("prim");
      primdelta746 = readrel773->getIndex(ord772, true);
  
    }
    ReadTask747(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        if (!slog::exists_probe<3,2>(eval_argsindex734, std::array<u64,3>{v_c13, v_c2, 0})) return;
        slog::join_probe_old<3,2>(evalindex735, evaldelta742, std::array<u64,3>{v_c12, v_c2, 0}, [&](const std::array<u64,3>& m774) {
          u64 v_c42 = m774[2];
          if (!slog::exists_probe<2,1>(eval_ansindex736, std::array<u64,2>{v_c42, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex737, eval_argsdelta743, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m775) {
            u64 v_c43 = m775[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex738, std::array<u64,2>{v_c43, 0})) return;
            slog::join_probe_old<2,1>(eval_ansindex739, eval_ansdelta744, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m776) {
              u64 v_c44 = m776[1];
              slog::join_probe_old<2,1>(eval_args_ansindex740, eval_args_ansdelta745, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m777) {
                u64 v_c18 = m777[1];
                slog::join_probe_old<2,1>(primindex741, primdelta746, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m778) {
                  u64 v_c45 = m778[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c45, v_c18}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
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
  // (crule (pre) (scan freevar x e2) (body (join-old if (2 3 0 1) 1 (2 3 0 1) e2 e3 __t4dlE324 e1)) (head (emit freevar (0 1) x __t4dlE324)) freevars.slog:17 #f)
  class ReadTask781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex779;  slog::Index** ifdelta780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord782({0, 1});
      slog::Relation* readrel783 = db->getRelation("freevar");
      head_index[0] = readrel783->getIndex(ord782, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord784({2, 3, 0, 1});
      slog::Relation* readrel785 = db->getRelation("if");
      ifindex779 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({2, 3, 0, 1});
      slog::Relation* readrel787 = db->getRelation("if");
      ifdelta780 = readrel787->getIndex(ord786, true);
  
    }
    ReadTask781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c124 = _t[1];
        slog::join_probe_old<4,1>(ifindex779, ifdelta780, std::array<u64,4>{v_c124, 0, 0, 0}, [&](const std::array<u64,4>& m788) {
          u64 v_c125 = m788[1]; u64 v_c132 = m788[2]; u64 v_c123 = m788[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c132}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask781* _cont = new ReadTask781(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask781(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3NP861 const609d51837c7fc306b0cbb04a)) (scan temp1U5N958 __t0AJB72 __t0UL087 __t5uOh47 __t8AJw94 __t8p2B57) (body (exists ref (1 0) 1 __tconst6GmF96) (exists app (2 0 1) 1 __t8p2B57) (exists app (2 0 1) 1 __t0AJB72) (join lambda (1 2 0) 2 __t8AJw94 __t0UL087 __t9Uwo95) (join ref (1 0) 1 __tconst6GmF96 __t8XG759) (exists app (1 2 0) 2 __t8XG759 __t0AJB72) (join app (1 2 0) 2 __t8XG759 __t8p2B57 __t1pzN60) (join app (1 2 0) 2 __t8XG759 __t0AJB72 __t9J9k75)) (head (emit-temp temp9y4i959 __t1pzN60 __t5uOh47 __t9J9k75 __t9Uwo95) (mkstruct let (2 1 3 0) __t351k62 __t1pzN60 __tconst3NP861 __t5uOh47)) schemecfa.slog:39 #f)
  class ReadTask797 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex789;  slog::Index** appindex790;  slog::Index** appindex791;  slog::Index** lambdaindex792;  slog::Index** refindex793;  slog::Index** appindex794;  slog::Index** appindex795;  slog::Index** appindex796;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9y4i959");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp1U5N958");
      std::vector<u16> ord798({1, 0});
      slog::Relation* readrel799 = db->getRelation("ref");
      refindex789 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({2, 0, 1});
      slog::Relation* readrel801 = db->getRelation("app");
      appindex790 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({2, 0, 1});
      slog::Relation* readrel803 = db->getRelation("app");
      appindex791 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("lambda");
      lambdaindex792 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 0});
      slog::Relation* readrel807 = db->getRelation("ref");
      refindex793 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("app");
      appindex794 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 0});
      slog::Relation* readrel811 = db->getRelation("app");
      appindex795 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({1, 2, 0});
      slog::Relation* readrel813 = db->getRelation("app");
      appindex796 = readrel813->getIndex(ord812, false);
  
    }
    ReadTask797(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c133 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c134 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c135 = v_const609d51837c7fc306b0cbb04a;
  
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
        u64 v_c138 = _t[2];
        u64 v_c139 = _t[3];
        u64 v_c140 = _t[4];
        if (!slog::exists_probe<2,1>(refindex789, std::array<u64,2>{v_c133, 0})) return;
        if (!slog::exists_probe<3,1>(appindex790, std::array<u64,3>{v_c140, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex791, std::array<u64,3>{v_c136, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex792, std::array<u64,3>{v_c139, v_c137, 0}, [&](const std::array<u64,3>& m814) {
          u64 v_c141 = m814[2];
          slog::join_probe<2,1>(refindex793, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m815) {
            u64 v_c142 = m815[1];
            if (!slog::exists_probe<3,2>(appindex794, std::array<u64,3>{v_c142, v_c136, 0})) return;
            slog::join_probe<3,2>(appindex795, std::array<u64,3>{v_c142, v_c140, 0}, [&](const std::array<u64,3>& m816) {
              u64 v_c143 = m816[2];
              slog::join_probe<3,2>(appindex796, std::array<u64,3>{v_c142, v_c136, 0}, [&](const std::array<u64,3>& m817) {
                u64 v_c144 = m817[2];
                ++_fires;
                slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c143, v_c138, v_c144, v_c141});
                slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c143, v_c135, v_c138}, std::array<u16,4>{2, 1, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp1U5N958", _fires);
  
      if (!_done)
      {
        ReadTask797* _cont = new ReadTask797(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask797(db,b), false);
  // (crule (pre) (scan temp7Ldx1076 __t1acj322 s) (body (join symval (1 0) 1 s __t4PSF320)) (head (emit eval_ans (0 1) __t1acj322 __t4PSF320)) interp.slog:28 #f)
  class ReadTask819 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symvalindex818;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("eval_ans");
      head_index[0] = readrel821->getIndex(ord820, false);
      outer_rel = db->getRelation("temp7Ldx1076");
      std::vector<u16> ord822({1, 0});
      slog::Relation* readrel823 = db->getRelation("symval");
      symvalindex818 = readrel823->getIndex(ord822, false);
  
    }
    ReadTask819(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c145 = _t[0];
        u64 v_c146 = _t[1];
        slog::join_probe<2,1>(symvalindex818, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m824) {
          u64 v_c147 = m824[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c145, v_c147}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:28", "delta:temp7Ldx1076", _fires);
  
      if (!_done)
      {
        ReadTask819* _cont = new ReadTask819(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask819(db,b), false);
  // (crule (pre) (scan app __t1Lm9110 ef es) (body (join-old eval (1 2 0) 1 (1 2 0) __t1Lm9110 c __t2QyE111)) (head (emit $sup56712x74x0x0x0 (0 1 2 3) __t2QyE111 c ef es)) interp.slog:75 #f)
  class ReadTask827 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex825;  slog::Index** evaldelta826;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord828({0, 1, 2, 3});
      slog::Relation* readrel829 = db->getRelation("$sup56712x74x0x0x0");
      head_index[0] = readrel829->getIndex(ord828, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord830({1, 2, 0});
      slog::Relation* readrel831 = db->getRelation("eval");
      evalindex825 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 0});
      slog::Relation* readrel833 = db->getRelation("eval");
      evaldelta826 = readrel833->getIndex(ord832, true);
  
    }
    ReadTask827(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe_old<3,1>(evalindex825, evaldelta826, std::array<u64,3>{v_c148, 0, 0}, [&](const std::array<u64,3>& m834) {
          u64 v_c2 = m834[1]; u64 v_c149 = m834[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c149, v_c2, v_c12, v_c13}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask827* _cont = new ReadTask827(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask827(db,b), false);
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp0zsa1170 __t0QMt425 __t0cS8401 __t8Onp417 __t8pxg398 __t9Q7F423) (body (exists num (1 0) 1 __tconst9Oxy387) (exists ref (1 0) 1 __tconst1UOH427) (exists ref (1 0) 1 __tconst4i3L422) (exists app (2 0 1) 1 __t8Onp417) (join lambda (1 2 0) 2 __t0cS8401 __t8pxg398 __t6kgH402) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join ref (1 0) 1 __tconst4i3L422 __t4MSc414) (join app (1 2 0) 2 __t4MSc414 __t8Onp417 __t1kdF420) (let __t6GQ8404 (lpush __t9Q7F423 __t6kgH402))) (head (emit-temp temp4xKX1171 __t0QMt425 __t1kdF420 __t6GQ8404) (mkstruct lambda (1 2 0) __t0QD8426 __t0QMt425 __t1kdF420)) schemecfa.slog:26 #f)
  class ReadTask844 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex835;  slog::Index** refindex836;  slog::Index** refindex837;  slog::Index** appindex838;  slog::Index** lambdaindex839;  slog::Index** numindex840;  slog::Index** refindex841;  slog::Index** refindex842;  slog::Index** appindex843;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4xKX1171");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp0zsa1170");
      std::vector<u16> ord845({1, 0});
      slog::Relation* readrel846 = db->getRelation("num");
      numindex835 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({1, 0});
      slog::Relation* readrel848 = db->getRelation("ref");
      refindex836 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 0});
      slog::Relation* readrel850 = db->getRelation("ref");
      refindex837 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({2, 0, 1});
      slog::Relation* readrel852 = db->getRelation("app");
      appindex838 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 2, 0});
      slog::Relation* readrel854 = db->getRelation("lambda");
      lambdaindex839 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 0});
      slog::Relation* readrel856 = db->getRelation("num");
      numindex840 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 0});
      slog::Relation* readrel858 = db->getRelation("ref");
      refindex841 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 0});
      slog::Relation* readrel860 = db->getRelation("ref");
      refindex842 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("app");
      appindex843 = readrel862->getIndex(ord861, false);
  
    }
    ReadTask844(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c150 = v_const0457bba0679825d285ef7fa5;
      u64 v_c151 = v_const30f8b180d63559f2512b744f;
      u64 v_c152 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c154 = _t[1];
        u64 v_c155 = _t[2];
        u64 v_c156 = _t[3];
        u64 v_c157 = _t[4];
        if (!slog::exists_probe<2,1>(numindex835, std::array<u64,2>{v_c152, 0})) return;
        if (!slog::exists_probe<2,1>(refindex836, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(refindex837, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<3,1>(appindex838, std::array<u64,3>{v_c155, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex839, std::array<u64,3>{v_c154, v_c156, 0}, [&](const std::array<u64,3>& m863) {
          u64 v_c158 = m863[2];
          slog::join_probe<2,1>(numindex840, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m864) {
            u64 v_c159 = m864[1];
            slog::join_probe<2,1>(refindex841, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m865) {
              u64 v_c160 = m865[1];
              slog::join_probe<2,1>(refindex842, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m866) {
                u64 v_c161 = m866[1];
                slog::join_probe<3,2>(appindex843, std::array<u64,3>{v_c161, v_c155, 0}, [&](const std::array<u64,3>& m867) {
                  u64 v_c162 = m867[2];
                  u64 v_c163 = _prim_lpush(db, v_c157, v_c158);
                  if (v_c163 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                  ++_fires;
                  slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c153, v_c162, v_c163});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c153, v_c162}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp0zsa1170", _fires);
  
      if (!_done)
      {
        ReadTask844* _cont = new ReadTask844(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask844(db,b), false);
  // (crule (pre) (scan temp1lMF953 __t7XMo37 x) (body (join prim (1 0) 1 x __t7sUm36)) (head (emit lookup_ans (0 1) __t7XMo37 __t7sUm36)) interp.slog:33 #f)
  class ReadTask869 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex868;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord870({0, 1});
      slog::Relation* readrel871 = db->getRelation("lookup_ans");
      head_index[0] = readrel871->getIndex(ord870, false);
      outer_rel = db->getRelation("temp1lMF953");
      std::vector<u16> ord872({1, 0});
      slog::Relation* readrel873 = db->getRelation("prim");
      primindex868 = readrel873->getIndex(ord872, false);
  
    }
    ReadTask869(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c164 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,1>(primindex868, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m874) {
          u64 v_c165 = m874[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c164, v_c165}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:temp1lMF953", _fires);
  
      if (!_done)
      {
        ReadTask869* _cont = new ReadTask869(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask869(db,b), false);
  // (crule (pre (let __tconst1U6w167 const844546be553b9dcbf71ae163) (let __tconst469K165 const0453462f31b2bcf68e33a91f)) (scan temp9DO81033 __t86mw175) (body (exists if (1 3 2 0) 1 __t86mw175) (exists sym (1 0) 1 __tconst1U6w167) (join sym (1 0) 1 __tconst469K165 __t5k1R166) (join if (1 3 2 0) 2 __t86mw175 __t5k1R166 __t2m3K168 __t55Mc176) (join sym (0 1) 2 __t2m3K168 __tconst1U6w167)) (head (emit program (0) __t55Mc176)) schemecfa.slog:61 #f)
  class ReadTask880 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex875;  slog::Index** symindex876;  slog::Index** symindex877;  slog::Index** ifindex878;  slog::Index** symindex879;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord881({0});
      slog::Relation* readrel882 = db->getRelation("program");
      head_index[0] = readrel882->getIndex(ord881, false);
      outer_rel = db->getRelation("temp9DO81033");
      std::vector<u16> ord883({1, 3, 2, 0});
      slog::Relation* readrel884 = db->getRelation("if");
      ifindex875 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 0});
      slog::Relation* readrel886 = db->getRelation("sym");
      symindex876 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 0});
      slog::Relation* readrel888 = db->getRelation("sym");
      symindex877 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 3, 2, 0});
      slog::Relation* readrel890 = db->getRelation("if");
      ifindex878 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("sym");
      symindex879 = readrel892->getIndex(ord891, false);
  
    }
    ReadTask880(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const844546be553b9dcbf71ae163;
      u64 v_c25 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        if (!slog::exists_probe<4,1>(ifindex875, std::array<u64,4>{v_c30, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(symindex876, std::array<u64,2>{v_c24, 0})) return;
        slog::join_probe<2,1>(symindex877, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m893) {
          u64 v_c27 = m893[1];
          slog::join_probe<4,2>(ifindex878, std::array<u64,4>{v_c30, v_c27, 0, 0}, [&](const std::array<u64,4>& m894) {
            u64 v_c28 = m894[2]; u64 v_c166 = m894[3];
            slog::join_probe<2,2>(symindex879, std::array<u64,2>{v_c28, v_c24}, [&](const std::array<u64,2>& m895) {
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c166}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:61", "delta:temp9DO81033", _fires);
  
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
  // (crule (pre) (scan eval __t6lGP106 __v1 c) (body (exists eval_ans (0 1) 1 __t6lGP106) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join select_branch_ans (1 0) 1 __v1 __t8m22105) (join eval_ans (0 1) 1 __t6lGP106 __v2) (join eval (2 0 1) 1 c __t9HBz103 __t2D2o102) (join $sup56712x86x0x0x0 (1 0 2 3 4) 2 c __t9HBz103 e1 e2 e3) (join if (1 3 2 0) 4 e1 e3 e2 __t2D2o102) (exists eval (1 2 0) 2 e1 c) (join select_branch (2 3 0 1) 3 e2 e3 __t8m22105 __v0) (exists eval_ans (1 0) 1 __v0) (join eval (1 2 0) 2 e1 c __t0Z2s104) (join eval_ans (0 1) 2 __t0Z2s104 __v0)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask909 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex896;  slog::Index** evalindex897;  slog::Index** $sup56712x86x0x0x0index898;  slog::Index** select_branch_ansindex899;  slog::Index** eval_ansindex900;  slog::Index** evalindex901;  slog::Index** $sup56712x86x0x0x0index902;  slog::Index** ifindex903;  slog::Index** evalindex904;  slog::Index** select_branchindex905;  slog::Index** eval_ansindex906;  slog::Index** evalindex907;  slog::Index** eval_ansindex908;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord910({0, 1});
      slog::Relation* readrel911 = db->getRelation("eval_ans");
      head_index[0] = readrel911->getIndex(ord910, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord912({0, 1});
      slog::Relation* readrel913 = db->getRelation("eval_ans");
      eval_ansindex896 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({2, 0, 1});
      slog::Relation* readrel915 = db->getRelation("eval");
      evalindex897 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({1, 0, 2, 3, 4});
      slog::Relation* readrel917 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index898 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 0});
      slog::Relation* readrel919 = db->getRelation("select_branch_ans");
      select_branch_ansindex899 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({0, 1});
      slog::Relation* readrel921 = db->getRelation("eval_ans");
      eval_ansindex900 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({2, 0, 1});
      slog::Relation* readrel923 = db->getRelation("eval");
      evalindex901 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 0, 2, 3, 4});
      slog::Relation* readrel925 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index902 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 3, 2, 0});
      slog::Relation* readrel927 = db->getRelation("if");
      ifindex903 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("eval");
      evalindex904 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({2, 3, 0, 1});
      slog::Relation* readrel931 = db->getRelation("select_branch");
      select_branchindex905 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0});
      slog::Relation* readrel933 = db->getRelation("eval_ans");
      eval_ansindex906 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("eval");
      evalindex907 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({0, 1});
      slog::Relation* readrel937 = db->getRelation("eval_ans");
      eval_ansindex908 = readrel937->getIndex(ord936, false);
  
    }
    ReadTask909(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c129 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex896, std::array<u64,2>{v_c130, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex897, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index898, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(select_branch_ansindex899, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m938) {
          u64 v_c128 = m938[1];
          slog::join_probe<2,1>(eval_ansindex900, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m939) {
            u64 v_c131 = m939[1];
            slog::join_probe<3,1>(evalindex901, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m940) {
              u64 v_c126 = m940[1]; u64 v_c122 = m940[2];
              slog::join_probe<5,2>($sup56712x86x0x0x0index902, std::array<u64,5>{v_c2, v_c126, 0, 0, 0}, [&](const std::array<u64,5>& m941) {
                u64 v_c123 = m941[2]; u64 v_c124 = m941[3]; u64 v_c125 = m941[4];
                slog::join_probe<4,4>(ifindex903, std::array<u64,4>{v_c123, v_c125, v_c124, v_c122}, [&](const std::array<u64,4>& m942) {
                  if (!slog::exists_probe<3,2>(evalindex904, std::array<u64,3>{v_c123, v_c2, 0})) return;
                  slog::join_probe<4,3>(select_branchindex905, std::array<u64,4>{v_c124, v_c125, v_c128, 0}, [&](const std::array<u64,4>& m943) {
                    u64 v_c19 = m943[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex906, std::array<u64,2>{v_c19, 0})) return;
                    slog::join_probe<3,2>(evalindex907, std::array<u64,3>{v_c123, v_c2, 0}, [&](const std::array<u64,3>& m944) {
                      u64 v_c127 = m944[2];
                      slog::join_probe<2,2>(eval_ansindex908, std::array<u64,2>{v_c127, v_c19}, [&](const std::array<u64,2>& m945) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c126, v_c131}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst7oTo733 constb9e118781cea1f9fa01462e0) (let __tconst23AG380 const60e3114d9b4b6577eea8cbc0) (let _00024sqc7zL5538 const6b86b273ff34fce19d6b804e) (let _00024sqc0b5k539 const5feceb66ffc86f38d952786c) (let _00024sqo0tFP540 const5feceb66ffc86f38d952786c) (let _00024sqo2KLy541 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo0tFP540 v _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2KLy541 v _00024seq0) (exists _enum (1 0) 1 __tconst7oTo733) (join delta (1 2 0) 2 __tconst23AG380 _00024seq0 __t7rOF381) (join _enum (1 0) 1 __tconst7oTo733 __t1FRr378) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql6Yee536 (aslst _00024seq0)) (let chk6PMD999 (llen _00024sql6Yee536)) (eq _00024sqc7zL5538 chk6PMD999) (letp chk9oRy1000 (lref _00024sql6Yee536 _00024sqc0b5k539)) (eq v chk9oRy1000)) (head (emit-temp temp0LTu995 __t7rOF381) (mkstruct boolval (1 0) __t7RmO379 __t1FRr378)) interp.slog:114 #f)
  class ReadTask952 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex946;  slog::Index** _enumindex947;  slog::Index** deltaindex948;  slog::Index** _enumindex949;  slog::Index** scheme_falseindex950;  slog::Index** $seq_atrdelta951;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LTu995");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord953({1, 0, 2});
      slog::Relation* readrel954 = db->getRelation("$seq_at");
      driver_index = readrel954->getIndex(ord953, true);
      std::vector<u16> ord955({1, 0, 2});
      slog::Relation* readrel956 = db->getRelation("$seq_atr");
      $seq_atrindex946 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 0, 2});
      slog::Relation* readrel958 = db->getRelation("$seq_atr");
      $seq_atrdelta951 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("_enum");
      _enumindex947 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("delta");
      deltaindex948 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 0});
      slog::Relation* readrel964 = db->getRelation("_enum");
      _enumindex949 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({0});
      slog::Relation* readrel966 = db->getRelation("scheme_false");
      scheme_falseindex950 = readrel966->getIndex(ord965, false);
  
    }
    ReadTask952(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c167 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c168 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c169 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c170 = v_const5feceb66ffc86f38d952786c;
      u64 v_c171 = v_const5feceb66ffc86f38d952786c;
      u64 v_c172 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c171, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m967) {
        u64 v_c9 = m967[1];
        u64 v_c77 = m967[2];
        if (buckethash(v_c9) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex946, $seq_atrdelta951, std::array<u64,3>{v_c172, v_c9, v_c77}, [&](const std::array<u64,3>& m968) {
          if (!slog::exists_probe<2,1>(_enumindex947, std::array<u64,2>{v_c167, 0})) return;
          slog::join_probe<3,2>(deltaindex948, std::array<u64,3>{v_c168, v_c77, 0}, [&](const std::array<u64,3>& m969) {
            u64 v_c173 = m969[2];
            slog::join_probe<2,1>(_enumindex949, std::array<u64,2>{v_c167, 0}, [&](const std::array<u64,2>& m970) {
              u64 v_c174 = m970[1];
              slog::join_all<1>(scheme_falseindex950, [&](const std::array<u64,1>& m971) {
                u64 v_c175 = m971[0];
                if (v_c9 == v_c175) return;
                bool ok972 = true;
                u64 v_c176 = _prim_aslst(db, v_c77, &ok972);
                if (!ok972) return;
                u64 v_c177 = _prim_llen(db, v_c176);
                if (v_c177 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c169 != v_c177) return;
                bool ok973 = true;
                u64 v_c178 = _prim_lref(db, v_c176, v_c170, &ok973);
                if (!ok973) return;
                if (v_c9 != v_c178) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c173});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c174}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask952* _cont = new ReadTask952(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask952(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo5WJE594 __t76ef190 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo2ych592 __t76ef190 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3d3H593 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4b4d595 __t76ef190 _00024seq2) (exists _enum (1 0) 1 __tconst5USv771) (join delta (1 2 0) 2 __tconst16Oe187 _00024seq2 __t4OrE188) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join prim (0 1) 1 __t76ef190 op) (letp _00024sql3Mb9587 (aslst _00024seq2)) (let chk5ZOT1070 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk5ZOT1070) (letp chk7Mj61071 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (eq __t76ef190 chk7Mj61071) (letp chk7HrB1072 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk7HrB1072)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask982 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex974;  slog::Index** $seq_atindex975;  slog::Index** $seq_atrindex976;  slog::Index** _enumindex977;  slog::Index** deltaindex978;  slog::Index** _enumindex979;  slog::Index** primindex980;  slog::Index** $seq_atrdelta981;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord983({1, 0, 2});
      slog::Relation* readrel984 = db->getRelation("$seq_atr");
      driver_index = readrel984->getIndex(ord983, true);
      std::vector<u16> ord985({1, 0, 2});
      slog::Relation* readrel986 = db->getRelation("$seq_at");
      $seq_atindex974 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({1, 0, 2});
      slog::Relation* readrel988 = db->getRelation("$seq_at");
      $seq_atindex975 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 0, 2});
      slog::Relation* readrel990 = db->getRelation("$seq_atr");
      $seq_atrindex976 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 0, 2});
      slog::Relation* readrel992 = db->getRelation("$seq_atr");
      $seq_atrdelta981 = readrel992->getIndex(ord991, true);
      std::vector<u16> ord993({1, 0});
      slog::Relation* readrel994 = db->getRelation("_enum");
      _enumindex977 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 0});
      slog::Relation* readrel996 = db->getRelation("delta");
      deltaindex978 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0});
      slog::Relation* readrel998 = db->getRelation("_enum");
      _enumindex979 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({0, 1});
      slog::Relation* readrel1000 = db->getRelation("prim");
      primindex980 = readrel1000->getIndex(ord999, false);
  
    }
    ReadTask982(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c179 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c180 = v_const06abaa100ecef791ce028c56;
      u64 v_c181 = v_constd4735e3a265e16eee03f5971;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
      u64 v_c183 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c184 = v_const5feceb66ffc86f38d952786c;
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c187 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c186, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1001) {
        u64 v_c188 = m1001[1];
        u64 v_c95 = m1001[2];
        if (buckethash(v_c188) != bucket) return;
        slog::join_probe<3,3>($seq_atindex974, std::array<u64,3>{v_c184, v_c188, v_c95}, [&](const std::array<u64,3>& m1002) {
          slog::join_probe<3,3>($seq_atindex975, std::array<u64,3>{v_c185, v_c188, v_c95}, [&](const std::array<u64,3>& m1003) {
            slog::join_probe_old<3,3>($seq_atrindex976, $seq_atrdelta981, std::array<u64,3>{v_c187, v_c188, v_c95}, [&](const std::array<u64,3>& m1004) {
              if (!slog::exists_probe<2,1>(_enumindex977, std::array<u64,2>{v_c179, 0})) return;
              slog::join_probe<3,2>(deltaindex978, std::array<u64,3>{v_c180, v_c95, 0}, [&](const std::array<u64,3>& m1005) {
                u64 v_c189 = m1005[2];
                slog::join_probe<2,1>(_enumindex979, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m1006) {
                  u64 v_c190 = m1006[1];
                  slog::join_probe<2,1>(primindex980, std::array<u64,2>{v_c188, 0}, [&](const std::array<u64,2>& m1007) {
                    u64 v_c45 = m1007[1];
                    bool ok1008 = true;
                    u64 v_c191 = _prim_aslst(db, v_c95, &ok1008);
                    if (!ok1008) return;
                    u64 v_c192 = _prim_llen(db, v_c191);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c181 != v_c192) return;
                    bool ok1009 = true;
                    u64 v_c193 = _prim_lref(db, v_c191, v_c182, &ok1009);
                    if (!ok1009) return;
                    if (v_c188 != v_c193) return;
                    bool ok1010 = true;
                    u64 v_c194 = _prim_lref(db, v_c191, v_c183, &ok1010);
                    if (!ok1010) return;
                    if (v_c188 != v_c194) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c189});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c190}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask982* _cont = new ReadTask982(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask982(db,b), false);
  // (crule (pre) (scan tick __t0DSy30 __t8j7u29 c) (body (exists tick_ans (0 1) 1 __t0DSy30) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t8j7u29 c __4cUN684) (join tick_ans (0 1) 1 __t0DSy30 l) (join eval (2 0 1) 1 c __t5MCM24 ef) (exists eval_ans (0 1) 1 __t5MCM24) (join app (0 1 2) 2 __t8j7u29 ef es) (join eval_args (1 2 0) 2 es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join closure (0 1 2) 1 __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join lambda (0 1 2) 1 __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1028 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex1011;  slog::Index** evalindex1012;  slog::Index** eval_argsindex1013;  slog::Index** evalindex1014;  slog::Index** tick_ansindex1015;  slog::Index** evalindex1016;  slog::Index** eval_ansindex1017;  slog::Index** appindex1018;  slog::Index** eval_argsindex1019;  slog::Index** eval_args_ansindex1020;  slog::Index** eval_ansindex1021;  slog::Index** eval_args_ansindex1022;  slog::Index** closureindex1023;  slog::Index** bindingindex1024;  slog::Index** freevarindex1025;  slog::Index** bindingindex1026;  slog::Index** lambdaindex1027;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1029({0, 1, 2});
      slog::Relation* readrel1030 = db->getRelation("binding");
      head_index[0] = readrel1030->getIndex(ord1029, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1031({0, 1, 2});
      slog::Relation* readrel1032 = db->getRelation("binding_event");
      head_index[1] = readrel1032->getIndex(ord1031, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1033({0, 1});
      slog::Relation* readrel1034 = db->getRelation("tick_ans");
      tick_ansindex1011 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({2, 0, 1});
      slog::Relation* readrel1036 = db->getRelation("eval");
      evalindex1012 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({2, 0, 1});
      slog::Relation* readrel1038 = db->getRelation("eval_args");
      eval_argsindex1013 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({1, 2, 0});
      slog::Relation* readrel1040 = db->getRelation("eval");
      evalindex1014 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({0, 1});
      slog::Relation* readrel1042 = db->getRelation("tick_ans");
      tick_ansindex1015 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({2, 0, 1});
      slog::Relation* readrel1044 = db->getRelation("eval");
      evalindex1016 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("eval_ans");
      eval_ansindex1017 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({0, 1, 2});
      slog::Relation* readrel1048 = db->getRelation("app");
      appindex1018 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 2, 0});
      slog::Relation* readrel1050 = db->getRelation("eval_args");
      eval_argsindex1019 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({0, 1});
      slog::Relation* readrel1052 = db->getRelation("eval_args_ans");
      eval_args_ansindex1020 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({0, 1});
      slog::Relation* readrel1054 = db->getRelation("eval_ans");
      eval_ansindex1021 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({0, 1});
      slog::Relation* readrel1056 = db->getRelation("eval_args_ans");
      eval_args_ansindex1022 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({0, 1, 2});
      slog::Relation* readrel1058 = db->getRelation("closure");
      closureindex1023 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 0, 2});
      slog::Relation* readrel1060 = db->getRelation("binding");
      bindingindex1024 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 0});
      slog::Relation* readrel1062 = db->getRelation("freevar");
      freevarindex1025 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({0, 1, 2});
      slog::Relation* readrel1064 = db->getRelation("binding");
      bindingindex1026 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({0, 1, 2});
      slog::Relation* readrel1066 = db->getRelation("lambda");
      lambdaindex1027 = readrel1066->getIndex(ord1065, false);
  
    }
    ReadTask1028(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex1011, std::array<u64,2>{v_c37, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1012, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1013, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<3,2>(evalindex1014, std::array<u64,3>{v_c35, v_c2, 0}, [&](const std::array<u64,3>& m1067) {
          u64 v_c34 = m1067[2];
          slog::join_probe<2,1>(tick_ansindex1015, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m1068) {
            u64 v_c38 = m1068[1];
            slog::join_probe<3,1>(evalindex1016, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1069) {
              u64 v_c32 = m1069[1]; u64 v_c12 = m1069[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1017, std::array<u64,2>{v_c32, 0})) return;
              slog::join_probe<3,2>(appindex1018, std::array<u64,3>{v_c35, v_c12, 0}, [&](const std::array<u64,3>& m1070) {
                u64 v_c13 = m1070[2];
                slog::join_probe<3,2>(eval_argsindex1019, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m1071) {
                  u64 v_c36 = m1071[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1020, std::array<u64,2>{v_c36, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1021, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m1072) {
                    u64 v_c33 = m1072[1];
                    slog::join_probe<2,1>(eval_args_ansindex1022, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1073) {
                      u64 v_c18 = m1073[1];
                      slog::join_probe<3,1>(closureindex1023, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m1074) {
                        u64 v_c39 = m1074[1]; u64 v_c21 = m1074[2];
                        if (!slog::exists_probe<3,1>(bindingindex1024, std::array<u64,3>{v_c21, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex1025, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m1075) {
                          u64 v_c40 = m1075[1];
                          slog::join_probe<3,2>(bindingindex1026, std::array<u64,3>{v_c40, v_c21, 0}, [&](const std::array<u64,3>& m1076) {
                            u64 v_c41 = m1076[2];
                            slog::join_probe<3,1>(lambdaindex1027, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m1077) {
                              u64 v_c22 = m1077[1]; u64 v_c1 = m1077[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c40, v_c38, v_c41}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c40, v_c38, v_c2}, std::array<u16,3>{0, 1, 2});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask1028* _cont = new ReadTask1028(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1028(db,b), false);
  // (crule (pre) (scan ref __t8mXW119 x) (body) (head (emit freevar (0 1) x __t8mXW119)) freevars.slog:11 #f)
  class ReadTask1078 : public slog::Task
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
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1079({0, 1});
      slog::Relation* readrel1080 = db->getRelation("freevar");
      head_index[0] = readrel1080->getIndex(ord1079, false);
      outer_rel = db->getRelation("ref");
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c195 = _t[0];
        u64 v_c5 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c195}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:11", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1078* _cont = new ReadTask1078(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1078(db,b), false);
  // (crule (pre) (scan tick_ans __t5Pln304 l) (body (join-old tick (0 2 1) 1 (0 2 1) __t5Pln304 c __t7NtH303) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t7NtH303 c __7p9q702) (join-old eval (2 0 1) 1 (2 0 1) c __t9B5D299 ef) (exists eval_ans (0 1) 1 __t9B5D299) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join-old closure (0 1 2) 1 (0 1 2) __t4ng7301 __t4mHn300 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex1081;  slog::Index** evalindex1082;  slog::Index** eval_argsindex1083;  slog::Index** evalindex1084;  slog::Index** evalindex1085;  slog::Index** eval_ansindex1086;  slog::Index** appindex1087;  slog::Index** eval_argsindex1088;  slog::Index** eval_args_ansindex1089;  slog::Index** eval_ansindex1090;  slog::Index** eval_args_ansindex1091;  slog::Index** closureindex1092;  slog::Index** lambdaindex1093;  slog::Index** tickdelta1094;  slog::Index** evaldelta1095;  slog::Index** appdelta1096;  slog::Index** eval_argsdelta1097;  slog::Index** closuredelta1098;  slog::Index** lambdadelta1099;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1101({0, 1, 2, 3});
      slog::Relation* readrel1102 = db->getRelation("bind_params");
      head_index[0] = readrel1102->getIndex(ord1101, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1103({0, 1});
      slog::Relation* readrel1104 = db->getRelation("call_event");
      head_index[1] = readrel1104->getIndex(ord1103, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord1105({0, 2, 1});
      slog::Relation* readrel1106 = db->getRelation("tick");
      tickindex1081 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({0, 2, 1});
      slog::Relation* readrel1108 = db->getRelation("tick");
      tickdelta1094 = readrel1108->getIndex(ord1107, true);
      std::vector<u16> ord1109({2, 0, 1});
      slog::Relation* readrel1110 = db->getRelation("eval");
      evalindex1082 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 0, 1});
      slog::Relation* readrel1112 = db->getRelation("eval_args");
      eval_argsindex1083 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 2, 0});
      slog::Relation* readrel1114 = db->getRelation("eval");
      evalindex1084 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({2, 0, 1});
      slog::Relation* readrel1116 = db->getRelation("eval");
      evalindex1085 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({2, 0, 1});
      slog::Relation* readrel1118 = db->getRelation("eval");
      evaldelta1095 = readrel1118->getIndex(ord1117, true);
      std::vector<u16> ord1119({0, 1});
      slog::Relation* readrel1120 = db->getRelation("eval_ans");
      eval_ansindex1086 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({0, 1, 2});
      slog::Relation* readrel1122 = db->getRelation("app");
      appindex1087 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({0, 1, 2});
      slog::Relation* readrel1124 = db->getRelation("app");
      appdelta1096 = readrel1124->getIndex(ord1123, true);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("eval_args");
      eval_argsindex1088 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("eval_args");
      eval_argsdelta1097 = readrel1128->getIndex(ord1127, true);
      std::vector<u16> ord1129({0, 1});
      slog::Relation* readrel1130 = db->getRelation("eval_args_ans");
      eval_args_ansindex1089 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 1});
      slog::Relation* readrel1132 = db->getRelation("eval_ans");
      eval_ansindex1090 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({0, 1});
      slog::Relation* readrel1134 = db->getRelation("eval_args_ans");
      eval_args_ansindex1091 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({0, 1, 2});
      slog::Relation* readrel1136 = db->getRelation("closure");
      closureindex1092 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({0, 1, 2});
      slog::Relation* readrel1138 = db->getRelation("closure");
      closuredelta1098 = readrel1138->getIndex(ord1137, true);
      std::vector<u16> ord1139({0, 1, 2});
      slog::Relation* readrel1140 = db->getRelation("lambda");
      lambdaindex1093 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({0, 1, 2});
      slog::Relation* readrel1142 = db->getRelation("lambda");
      lambdadelta1099 = readrel1142->getIndex(ord1141, true);
  
    }
    ReadTask1100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[0];
        u64 v_c38 = _t[1];
        slog::join_probe_old<3,1>(tickindex1081, tickdelta1094, std::array<u64,3>{v_c196, 0, 0}, [&](const std::array<u64,3>& m1143) {
          u64 v_c2 = m1143[1]; u64 v_c197 = m1143[2];
          if (!slog::exists_probe<3,1>(evalindex1082, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex1083, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<3,2>(evalindex1084, std::array<u64,3>{v_c197, v_c2, 0}, [&](const std::array<u64,3>& m1144) {
            u64 v_c198 = m1144[2];
            slog::join_probe_old<3,1>(evalindex1085, evaldelta1095, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1145) {
              u64 v_c199 = m1145[1]; u64 v_c12 = m1145[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1086, std::array<u64,2>{v_c199, 0})) return;
              slog::join_probe_old<3,2>(appindex1087, appdelta1096, std::array<u64,3>{v_c197, v_c12, 0}, [&](const std::array<u64,3>& m1146) {
                u64 v_c13 = m1146[2];
                slog::join_probe_old<3,2>(eval_argsindex1088, eval_argsdelta1097, std::array<u64,3>{v_c13, v_c2, 0}, [&](const std::array<u64,3>& m1147) {
                  u64 v_c200 = m1147[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1089, std::array<u64,2>{v_c200, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1090, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1148) {
                    u64 v_c201 = m1148[1];
                    slog::join_probe<2,1>(eval_args_ansindex1091, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m1149) {
                      u64 v_c18 = m1149[1];
                      slog::join_probe_old<3,1>(closureindex1092, closuredelta1098, std::array<u64,3>{v_c201, 0, 0}, [&](const std::array<u64,3>& m1150) {
                        u64 v_c202 = m1150[1]; u64 v_c21 = m1150[2];
                        slog::join_probe_old<3,1>(lambdaindex1093, lambdadelta1099, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m1151) {
                          u64 v_c22 = m1151[1]; u64 v_c1 = m1151[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c22, v_c18, v_c38, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c38, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask1100* _cont = new ReadTask1100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1100(db,b), false);
  // (crule (pre) (scan letrec __t7zZ2181 x er eb) (body (exists eval (1 2 0) 1 er) (join eval (1 2 0) 1 __t7zZ2181 c __1E5R778) (join-old eval (1 2 0) 2 (1 2 0) er c __t3m2r182) (join eval_ans (0 1) 1 __t3m2r182 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask1157 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1152;  slog::Index** evalindex1153;  slog::Index** evalindex1154;  slog::Index** eval_ansindex1155;  slog::Index** evaldelta1156;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1158({0, 1, 2});
      slog::Relation* readrel1159 = db->getRelation("binding");
      head_index[0] = readrel1159->getIndex(ord1158, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1160({0, 1, 2});
      slog::Relation* readrel1161 = db->getRelation("binding_event");
      head_index[1] = readrel1161->getIndex(ord1160, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord1162({1, 2, 0});
      slog::Relation* readrel1163 = db->getRelation("eval");
      evalindex1152 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({1, 2, 0});
      slog::Relation* readrel1165 = db->getRelation("eval");
      evalindex1153 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({1, 2, 0});
      slog::Relation* readrel1167 = db->getRelation("eval");
      evalindex1154 = readrel1167->getIndex(ord1166, false);
      std::vector<u16> ord1168({1, 2, 0});
      slog::Relation* readrel1169 = db->getRelation("eval");
      evaldelta1156 = readrel1169->getIndex(ord1168, true);
      std::vector<u16> ord1170({0, 1});
      slog::Relation* readrel1171 = db->getRelation("eval_ans");
      eval_ansindex1155 = readrel1171->getIndex(ord1170, false);
  
    }
    ReadTask1157(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c203 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c1 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex1152, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,1>(evalindex1153, std::array<u64,3>{v_c203, 0, 0}, [&](const std::array<u64,3>& m1172) {
          u64 v_c2 = m1172[1]; u64 v_c204 = m1172[2];
          slog::join_probe_old<3,2>(evalindex1154, evaldelta1156, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m1173) {
            u64 v_c205 = m1173[2];
            slog::join_probe<2,1>(eval_ansindex1155, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1174) {
              u64 v_c8 = m1174[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c2, v_c8}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask1157* _cont = new ReadTask1157(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1157(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1Uwu524 __t5ERV310 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7nH0522 __t5ERV310 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8HCy523 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9OPL525 __t5ERV310 _00024seq2) (exists _enum (1 0) 1 __tconst65GN810) (join delta (1 2 0) 2 __tconst3VNs307 _00024seq2 __t5HIm308) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join symval (0 1) 1 __t5ERV310 s) (letp _00024sql2wmw517 (aslst _00024seq2)) (let chk7wsr1158 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk7wsr1158) (letp chk4oy21159 (lref _00024sql2wmw517 _00024sqc5bE7520)) (eq __t5ERV310 chk4oy21159) (letp chk7E5x1160 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk7E5x1160)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask1183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1175;  slog::Index** $seq_atindex1176;  slog::Index** $seq_atrindex1177;  slog::Index** _enumindex1178;  slog::Index** deltaindex1179;  slog::Index** _enumindex1180;  slog::Index** symvalindex1181;  slog::Index** $seq_atrdelta1182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1184({1, 0, 2});
      slog::Relation* readrel1185 = db->getRelation("$seq_atr");
      driver_index = readrel1185->getIndex(ord1184, true);
      std::vector<u16> ord1186({1, 0, 2});
      slog::Relation* readrel1187 = db->getRelation("$seq_at");
      $seq_atindex1175 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 0, 2});
      slog::Relation* readrel1189 = db->getRelation("$seq_at");
      $seq_atindex1176 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 0, 2});
      slog::Relation* readrel1191 = db->getRelation("$seq_atr");
      $seq_atrindex1177 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 0, 2});
      slog::Relation* readrel1193 = db->getRelation("$seq_atr");
      $seq_atrdelta1182 = readrel1193->getIndex(ord1192, true);
      std::vector<u16> ord1194({1, 0});
      slog::Relation* readrel1195 = db->getRelation("_enum");
      _enumindex1178 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 2, 0});
      slog::Relation* readrel1197 = db->getRelation("delta");
      deltaindex1179 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({1, 0});
      slog::Relation* readrel1199 = db->getRelation("_enum");
      _enumindex1180 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({0, 1});
      slog::Relation* readrel1201 = db->getRelation("symval");
      symvalindex1181 = readrel1201->getIndex(ord1200, false);
  
    }
    ReadTask1183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c207 = v_const06abaa100ecef791ce028c56;
      u64 v_c208 = v_constd4735e3a265e16eee03f5971;
      u64 v_c209 = v_const5feceb66ffc86f38d952786c;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const5feceb66ffc86f38d952786c;
      u64 v_c212 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c213, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1202) {
        u64 v_c215 = m1202[1];
        u64 v_c95 = m1202[2];
        if (buckethash(v_c215) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1175, std::array<u64,3>{v_c211, v_c215, v_c95}, [&](const std::array<u64,3>& m1203) {
          slog::join_probe<3,3>($seq_atindex1176, std::array<u64,3>{v_c212, v_c215, v_c95}, [&](const std::array<u64,3>& m1204) {
            slog::join_probe_old<3,3>($seq_atrindex1177, $seq_atrdelta1182, std::array<u64,3>{v_c214, v_c215, v_c95}, [&](const std::array<u64,3>& m1205) {
              if (!slog::exists_probe<2,1>(_enumindex1178, std::array<u64,2>{v_c206, 0})) return;
              slog::join_probe<3,2>(deltaindex1179, std::array<u64,3>{v_c207, v_c95, 0}, [&](const std::array<u64,3>& m1206) {
                u64 v_c216 = m1206[2];
                slog::join_probe<2,1>(_enumindex1180, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1207) {
                  u64 v_c217 = m1207[1];
                  slog::join_probe<2,1>(symvalindex1181, std::array<u64,2>{v_c215, 0}, [&](const std::array<u64,2>& m1208) {
                    u64 v_c146 = m1208[1];
                    bool ok1209 = true;
                    u64 v_c218 = _prim_aslst(db, v_c95, &ok1209);
                    if (!ok1209) return;
                    u64 v_c219 = _prim_llen(db, v_c218);
                    if (v_c219 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c208 != v_c219) return;
                    bool ok1210 = true;
                    u64 v_c220 = _prim_lref(db, v_c218, v_c209, &ok1210);
                    if (!ok1210) return;
                    if (v_c215 != v_c220) return;
                    bool ok1211 = true;
                    u64 v_c221 = _prim_lref(db, v_c218, v_c210, &ok1211);
                    if (!ok1211) return;
                    if (v_c215 != v_c221) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c216});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c217}, std::array<u16,2>{1, 0});
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
        ReadTask1183* _cont = new ReadTask1183(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1183(db,b), false);
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0)) (scan temp4VE71091 __t12h7218) (body (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (join boolval (1 0) 1 __t6tMS215 __t5boA216)) (head (emit delta_ans (0 1) __t12h7218 __t5boA216)) interp.slog:120 #f)
  class ReadTask1214 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1212;  slog::Index** boolvalindex1213;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1215({0, 1});
      slog::Relation* readrel1216 = db->getRelation("delta_ans");
      head_index[0] = readrel1216->getIndex(ord1215, false);
      outer_rel = db->getRelation("temp4VE71091");
      std::vector<u16> ord1217({1, 0});
      slog::Relation* readrel1218 = db->getRelation("_enum");
      _enumindex1212 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 0});
      slog::Relation* readrel1220 = db->getRelation("boolval");
      boolvalindex1213 = readrel1220->getIndex(ord1219, false);
  
    }
    ReadTask1214(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c222 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c223 = _t[0];
        slog::join_probe<2,1>(_enumindex1212, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m1221) {
          u64 v_c224 = m1221[1];
          slog::join_probe<2,1>(boolvalindex1213, std::array<u64,2>{v_c224, 0}, [&](const std::array<u64,2>& m1222) {
            u64 v_c225 = m1222[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c223, v_c225}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:temp4VE71091", _fires);
  
      if (!_done)
      {
        ReadTask1214* _cont = new ReadTask1214(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1214(db,b), false);
  // (crule (pre) (scan let __t0UAj147 y er eb) (body (join freevar (1 0) 1 eb x) (neq x y)) (head (emit freevar (0 1) x __t0UAj147)) freevars.slog:22 #f)
  class ReadTask1224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1225({0, 1});
      slog::Relation* readrel1226 = db->getRelation("freevar");
      head_index[0] = readrel1226->getIndex(ord1225, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord1227({1, 0});
      slog::Relation* readrel1228 = db->getRelation("freevar");
      freevarindex1223 = readrel1228->getIndex(ord1227, false);
  
    }
    ReadTask1224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c226 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c1 = _t[3];
        slog::join_probe<2,1>(freevarindex1223, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1229) {
          u64 v_c5 = m1229[1];
          if (v_c5 == v_c40) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c226}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:22", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask1224* _cont = new ReadTask1224(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1224(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55)) (scan temp0SQX961 __t00Fz77 __t9Uwo95) (body (join let (2 1 3 0) 3 __t9Uwo95 __tconst6GmF96 __t00Fz77 __t515p97)) (head (emit program (0) __t515p97)) schemecfa.slog:39 #f)
  class ReadTask1231 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1230;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1232({0});
      slog::Relation* readrel1233 = db->getRelation("program");
      head_index[0] = readrel1233->getIndex(ord1232, false);
      outer_rel = db->getRelation("temp0SQX961");
      std::vector<u16> ord1234({2, 1, 3, 0});
      slog::Relation* readrel1235 = db->getRelation("let");
      letindex1230 = readrel1235->getIndex(ord1234, false);
  
    }
    ReadTask1231(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c133 = v_const5d1d34d1b1718cd7c9f1ee55;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c227 = _t[0];
        u64 v_c141 = _t[1];
        slog::join_probe<4,3>(letindex1230, std::array<u64,4>{v_c141, v_c133, v_c227, 0}, [&](const std::array<u64,4>& m1236) {
          u64 v_c228 = m1236[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c228}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp0SQX961", _fires);
  
      if (!_done)
      {
        ReadTask1231* _cont = new ReadTask1231(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1231(db,b), false);
  // (crule (pre (let __trid5DSK697 constea10b8ee9cd346b11a382114) (let __trel5Ibl698 const4a59dbb9cb3129dfcc75170b) (let __tcol64lM699 const5feceb66ffc86f38d952786c) (let __trel2k3T700 const4a59dbb9cb3129dfcc75170b) (let __tcol7zaI701 const6b86b273ff34fce19d6b804e)) (scan $sup56712x37x0x0x0 _00024seq0 __d0 c e es) (body) (head (tycheck e (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid5DSK697 __trel5Ibl698 __tcol64lM699 (1 2 3 4 0)) (tycheck c (accept seq) __trid5DSK697 __trel2k3T700 __tcol7zaI701 (1 2 3 4 0)) (mkstruct eval (1 2 0) __4wp2696 e c)) interp.slog:38 #f)
  class ReadTask1246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1237;  u32 sid1238;  u32 sid1239;  u32 sid1240;  u32 sid1241;  u32 sid1242;  u32 sid1243;  u32 sid1244;  u32 sid1245;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x37x0x0x0");
      sid1237 = db->getRelation("app")->getStructId();
      sid1238 = db->getRelation("boolean")->getStructId();
      sid1239 = db->getRelation("if")->getStructId();
      sid1240 = db->getRelation("lambda")->getStructId();
      sid1241 = db->getRelation("let")->getStructId();
      sid1242 = db->getRelation("letrec")->getStructId();
      sid1243 = db->getRelation("num")->getStructId();
      sid1244 = db->getRelation("ref")->getStructId();
      sid1245 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c229 = v_constea10b8ee9cd346b11a382114;
      u64 v_c230 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c231 = v_const5feceb66ffc86f38d952786c;
      u64 v_c232 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c233 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c77 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c81 = _t[3];
        u64 v_c13 = _t[4];
        ++_fires;
        if (!((is_struct(v_c81) && (decode_struct_id(v_c81) == sid1237 || decode_struct_id(v_c81) == sid1238 || decode_struct_id(v_c81) == sid1239 || decode_struct_id(v_c81) == sid1240 || decode_struct_id(v_c81) == sid1241 || decode_struct_id(v_c81) == sid1242 || decode_struct_id(v_c81) == sid1243 || decode_struct_id(v_c81) == sid1244 || decode_struct_id(v_c81) == sid1245))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c229, v_c230, v_c231, v_c81}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c229, v_c232, v_c233, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c81, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$sup56712x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1246* _cont = new ReadTask1246(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1246(db,b), false);
  // (crule (pre (let __trid3qe8708 const5963fd3eff55776ca49412c5) (let __trel6Tq0709 conste90c92f3e6c3b47a7bc93e42) (let __tcol76Zo710 const5feceb66ffc86f38d952786c) (let __trel4UTY711 conste90c92f3e6c3b47a7bc93e42) (let __tcol2l2M712 const6b86b273ff34fce19d6b804e)) (scan $sup56712x74x0x0x0 __d0 c ef es) (body) (head (tycheck es (accept seq) __trid3qe8708 __trel6Tq0709 __tcol76Zo710 (1 2 3 4 0)) (tycheck c (accept seq) __trid3qe8708 __trel4UTY711 __tcol2l2M712 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __97en707 es c)) interp.slog:75 #f)
  class ReadTask1247 : public slog::Task
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
      head_rel[2] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
  
    }
    ReadTask1247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c234 = v_const5963fd3eff55776ca49412c5;
      u64 v_c235 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c236 = v_const5feceb66ffc86f38d952786c;
      u64 v_c237 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c238 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c14 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        ++_fires;
        if (!(is_seq(v_c13)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c234, v_c235, v_c236, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c234, v_c237, v_c238, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c13, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
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
  // (crule (pre (let __trid3JvS805 constea10b8ee9cd346b11a382114) (let __trel6cgw806 conste90c92f3e6c3b47a7bc93e42) (let __tcol2taN807 const5feceb66ffc86f38d952786c) (let __trel3Bs7808 conste90c92f3e6c3b47a7bc93e42) (let __tcol75ih809 const6b86b273ff34fce19d6b804e)) (scan $sup56712x37x0x0x0 _00024seq0 __d0 c e es) (body) (head (tycheck es (accept seq) __trid3JvS805 __trel6cgw806 __tcol2taN807 (1 2 3 4 0)) (tycheck c (accept seq) __trid3JvS805 __trel3Bs7808 __tcol75ih809 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __4WmY804 es c)) interp.slog:38 #f)
  class ReadTask1248 : public slog::Task
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
      head_rel[2] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup56712x37x0x0x0");
  
    }
    ReadTask1248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c239 = v_constea10b8ee9cd346b11a382114;
      u64 v_c240 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c241 = v_const5feceb66ffc86f38d952786c;
      u64 v_c242 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c243 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c77 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c81 = _t[3];
        u64 v_c13 = _t[4];
        ++_fires;
        if (!(is_seq(v_c13)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c239, v_c240, v_c241, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c239, v_c242, v_c243, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c13, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$sup56712x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1248* _cont = new ReadTask1248(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1248(db,b), false);
  // (crule (pre) (scan app __t7Nk2385 ef es) (body (join eval (1 2 0) 1 __t7Nk2385 c __23px789)) (head (mkstruct tick (1 2 0) __16lD790 __t7Nk2385 c)) interp.slog:48 #f)
  class ReadTask1250 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1249;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("eval");
      evalindex1249 = readrel1252->getIndex(ord1251, false);
  
    }
    ReadTask1250(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c244 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe<3,1>(evalindex1249, std::array<u64,3>{v_c244, 0, 0}, [&](const std::array<u64,3>& m1253) {
          u64 v_c2 = m1253[1]; u64 v_c245 = m1253[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c244, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1250* _cont = new ReadTask1250(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1250(db,b), false);
  // (crule (pre) (scan eval __1G4R719 __t1Dbd212 c) (body (join-old app (0 1 2) 1 (0 1 2) __t1Dbd212 ef es) (join-old freevar (0 1) 0 (0 1) y __t3Eay213) (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3Eay213 xs eb)) (head (mkstruct tick (1 2 0) __2Xr3720 __t1Dbd212 c)) interp.slog:56 #f)
  class ReadTask1262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1254;  slog::Index** freevarindex1255;  slog::Index** bindingindex1256;  slog::Index** lambdaindex1257;  slog::Index** appdelta1258;  slog::Index** freevardelta1259;  slog::Index** bindingdelta1260;  slog::Index** lambdadelta1261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1263({0, 1, 2});
      slog::Relation* readrel1264 = db->getRelation("app");
      appindex1254 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({0, 1, 2});
      slog::Relation* readrel1266 = db->getRelation("app");
      appdelta1258 = readrel1266->getIndex(ord1265, true);
      std::vector<u16> ord1267({0, 1});
      slog::Relation* readrel1268 = db->getRelation("freevar");
      freevarindex1255 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("freevar");
      freevardelta1259 = readrel1270->getIndex(ord1269, true);
      std::vector<u16> ord1271({0, 1, 2});
      slog::Relation* readrel1272 = db->getRelation("binding");
      bindingindex1256 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({0, 1, 2});
      slog::Relation* readrel1274 = db->getRelation("binding");
      bindingdelta1260 = readrel1274->getIndex(ord1273, true);
      std::vector<u16> ord1275({0, 1, 2});
      slog::Relation* readrel1276 = db->getRelation("lambda");
      lambdaindex1257 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({0, 1, 2});
      slog::Relation* readrel1278 = db->getRelation("lambda");
      lambdadelta1261 = readrel1278->getIndex(ord1277, true);
  
    }
    ReadTask1262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c246 = _t[0];
        u64 v_c247 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex1254, appdelta1258, std::array<u64,3>{v_c247, 0, 0}, [&](const std::array<u64,3>& m1279) {
          u64 v_c12 = m1279[1]; u64 v_c13 = m1279[2];
          slog::join_all_old<2>(freevarindex1255, freevardelta1259, [&](const std::array<u64,2>& m1280) {
            u64 v_c40 = m1280[0]; u64 v_c248 = m1280[1];
            slog::join_probe_old<3,1>(bindingindex1256, bindingdelta1260, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m1281) {
              u64 v_c21 = m1281[1]; u64 v_c41 = m1281[2];
              slog::join_probe_old<3,1>(lambdaindex1257, lambdadelta1261, std::array<u64,3>{v_c248, 0, 0}, [&](const std::array<u64,3>& m1282) {
                u64 v_c22 = m1282[1]; u64 v_c1 = m1282[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c247, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1262* _cont = new ReadTask1262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1262(db,b), false);
}

