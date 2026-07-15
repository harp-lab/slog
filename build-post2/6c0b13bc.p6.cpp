
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const25f568921d120de09a5f575d;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const781eda039ec10c193395ca07;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_consteefaed435882b14b69e99d78;


void slog_rules_c7f120c5fa7201522(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan app __t4vf0113 ef es) (body (join eval (1 2 0) 1 __t4vf0113 c __88TM561) (join freevar (0 1) 0 y __t8awf114) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t8awf114 xs eb)) (head (mkstruct eval (1 2 0) __7s92562 ef c)) interp.slog:56 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** freevarindex1;  slog::Index** bindingindex2;  slog::Index** lambdaindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("eval");
      evalindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({0, 1});
      slog::Relation* readrel8 = db->getRelation("freevar");
      freevarindex1 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("binding");
      bindingindex2 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1, 2});
      slog::Relation* readrel12 = db->getRelation("lambda");
      lambdaindex3 = readrel12->getIndex(ord11, false);
  
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
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(evalindex0, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m13) {
          u64 v_c3 = m13[1]; u64 v_c4 = m13[2];
          slog::join_all<2>(freevarindex1, [&](const std::array<u64,2>& m14) {
            u64 v_c5 = m14[0]; u64 v_c6 = m14[1];
            slog::join_probe<3,1>(bindingindex2, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m15) {
              u64 v_c7 = m15[1]; u64 v_c8 = m15[2];
              slog::join_probe<3,1>(lambdaindex3, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m16) {
                u64 v_c9 = m16[1]; u64 v_c10 = m16[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:app", _fires);
  
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
  // (crule (pre) (scan tick __t3nAR325 __t9nj7324 c) (body (exists tick_ans (0 1) 1 __t3nAR325) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t9nj7324 c __5izx673) (join tick_ans (0 1) 1 __t3nAR325 l) (join eval (2 0 1) 1 c __t550i320 ef) (exists eval_ans (0 1) 1 __t550i320) (join app (0 1 2) 2 __t9nj7324 ef es) (join eval_args (1 2 0) 2 es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join closure (0 1 2) 1 __t2qAJ322 __t7ycN321 cb) (join lambda (0 1 2) 1 __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex17;  slog::Index** evalindex18;  slog::Index** eval_argsindex19;  slog::Index** evalindex20;  slog::Index** tick_ansindex21;  slog::Index** evalindex22;  slog::Index** eval_ansindex23;  slog::Index** appindex24;  slog::Index** eval_argsindex25;  slog::Index** eval_args_ansindex26;  slog::Index** eval_ansindex27;  slog::Index** eval_args_ansindex28;  slog::Index** closureindex29;  slog::Index** lambdaindex30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord32({0, 1, 2, 3});
      slog::Relation* readrel33 = db->getRelation("bind_params");
      head_index[0] = readrel33->getIndex(ord32, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("call_event");
      head_index[1] = readrel35->getIndex(ord34, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("tick_ans");
      tick_ansindex17 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({2, 0, 1});
      slog::Relation* readrel39 = db->getRelation("eval");
      evalindex18 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({2, 0, 1});
      slog::Relation* readrel41 = db->getRelation("eval_args");
      eval_argsindex19 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("eval");
      evalindex20 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("tick_ans");
      tick_ansindex21 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({2, 0, 1});
      slog::Relation* readrel47 = db->getRelation("eval");
      evalindex22 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("eval_ans");
      eval_ansindex23 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 1, 2});
      slog::Relation* readrel51 = db->getRelation("app");
      appindex24 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("eval_args");
      eval_argsindex25 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("eval_args_ans");
      eval_args_ansindex26 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("eval_ans");
      eval_ansindex27 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("eval_args_ans");
      eval_args_ansindex28 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({0, 1, 2});
      slog::Relation* readrel61 = db->getRelation("closure");
      closureindex29 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1, 2});
      slog::Relation* readrel63 = db->getRelation("lambda");
      lambdaindex30 = readrel63->getIndex(ord62, false);
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex17, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex18, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex19, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<3,2>(evalindex20, std::array<u64,3>{v_c12, v_c3, 0}, [&](const std::array<u64,3>& m64) {
          u64 v_c13 = m64[2];
          slog::join_probe<2,1>(tick_ansindex21, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m65) {
            u64 v_c14 = m65[1];
            slog::join_probe<3,1>(evalindex22, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m66) {
              u64 v_c15 = m66[1]; u64 v_c1 = m66[2];
              if (!slog::exists_probe<2,1>(eval_ansindex23, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe<3,2>(appindex24, std::array<u64,3>{v_c12, v_c1, 0}, [&](const std::array<u64,3>& m67) {
                u64 v_c2 = m67[2];
                slog::join_probe<3,2>(eval_argsindex25, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m68) {
                  u64 v_c16 = m68[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex26, std::array<u64,2>{v_c16, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex27, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m69) {
                    u64 v_c17 = m69[1];
                    slog::join_probe<2,1>(eval_args_ansindex28, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m70) {
                      u64 v_c18 = m70[1];
                      slog::join_probe<3,1>(closureindex29, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m71) {
                        u64 v_c19 = m71[1]; u64 v_c7 = m71[2];
                        slog::join_probe<3,1>(lambdaindex30, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m72) {
                          u64 v_c9 = m72[1]; u64 v_c10 = m72[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c18, v_c14, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c14, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), false);
  // (crule (pre) (scan eval __t8n0332 __t8l5731 c) (body (exists lookup (2 0 1) 1 c) (join ref (0 1) 1 __t8l5731 x) (join-old lookup (1 2 0) 2 (1 2 0) x c __t0d3433) (join lookup_ans (0 1) 1 __t0d3433 __v0)) (head (emit eval_ans (0 1) __t8n0332 __v0)) interp.slog:30 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex73;  slog::Index** refindex74;  slog::Index** lookupindex75;  slog::Index** lookup_ansindex76;  slog::Index** lookupdelta77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("eval_ans");
      head_index[0] = readrel80->getIndex(ord79, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord81({2, 0, 1});
      slog::Relation* readrel82 = db->getRelation("lookup");
      lookupindex73 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("ref");
      refindex74 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 2, 0});
      slog::Relation* readrel86 = db->getRelation("lookup");
      lookupindex75 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("lookup");
      lookupdelta77 = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("lookup_ans");
      lookup_ansindex76 = readrel90->getIndex(ord89, false);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(lookupindex73, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(refindex74, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m91) {
          u64 v_c22 = m91[1];
          slog::join_probe_old<3,2>(lookupindex75, lookupdelta77, std::array<u64,3>{v_c22, v_c3, 0}, [&](const std::array<u64,3>& m92) {
            u64 v_c23 = m92[2];
            slog::join_probe<2,1>(lookup_ansindex76, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m93) {
              u64 v_c24 = m93[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c24}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre) (scan lambda __t8awf114 xs eb) (body (join freevar (1 0) 1 __t8awf114 y) (join binding (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __88TM561 c __t4vf0113) (join-old app (0 1 2) 1 (0 1 2) __t4vf0113 ef es)) (head (mkstruct eval (1 2 0) __7s92562 ef c)) interp.slog:56 #f)
  class ReadTask100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex94;  slog::Index** bindingindex95;  slog::Index** evalindex96;  slog::Index** appindex97;  slog::Index** evaldelta98;  slog::Index** appdelta99;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("freevar");
      freevarindex94 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({0, 1, 2});
      slog::Relation* readrel104 = db->getRelation("binding");
      bindingindex95 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 2, 1});
      slog::Relation* readrel106 = db->getRelation("eval");
      evalindex96 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 2, 1});
      slog::Relation* readrel108 = db->getRelation("eval");
      evaldelta98 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({0, 1, 2});
      slog::Relation* readrel110 = db->getRelation("app");
      appindex97 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1, 2});
      slog::Relation* readrel112 = db->getRelation("app");
      appdelta99 = readrel112->getIndex(ord111, true);
  
    }
    ReadTask100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<2,1>(freevarindex94, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m113) {
          u64 v_c5 = m113[1];
          slog::join_probe<3,1>(bindingindex95, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m114) {
            u64 v_c7 = m114[1]; u64 v_c8 = m114[2];
            slog::join_all_old<3>(evalindex96, evaldelta98, [&](const std::array<u64,3>& m115) {
              u64 v_c4 = m115[0]; u64 v_c3 = m115[1]; u64 v_c0 = m115[2];
              slog::join_probe_old<3,1>(appindex97, appdelta99, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m116) {
                u64 v_c1 = m116[1]; u64 v_c2 = m116[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask100* _cont = new ReadTask100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask100(db,b), false);
  // (crule (pre (let __tconst36mF602 constcd2a69ce5ca278db1d6da969) (let __tconst4MYs19 const06abaa100ecef791ce028c56) (let _00024sqc0R1w414 constd4735e3a265e16eee03f5971) (let _00024sqc2r3q415 const5feceb66ffc86f38d952786c) (let _00024sqc1pwY416 const6b86b273ff34fce19d6b804e) (let _00024sqo5Wc9417 const5feceb66ffc86f38d952786c) (let _00024sqo4N7A418 const6b86b273ff34fce19d6b804e) (let _00024sqo8u9a419 const6b86b273ff34fce19d6b804e) (let _00024sqo9jvY420 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst4MYs19 _00024seq2 __t9afR20) (body (letp _00024sql9osm412 (aslst _00024seq2)) (letp __t2nOL22 (lref _00024sql9osm412 _00024sqc2r3q415)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5Wc9417 __t2nOL22 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4N7A418 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8u9a419 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9jvY420 __t2nOL22 _00024seq2) (join _enum (0 1) 2 __t2nOL22 __tconst36mF602) (join any_bool (0) 0 b) (let chk1Zli845 (llen _00024sql9osm412)) (eq _00024sqc0R1w414 chk1Zli845) (letp chk7CFR846 (lref _00024sql9osm412 _00024sqc1pwY416)) (eq __t2nOL22 chk7CFR846)) (head (emit-temp temp4fHg844 __t9afR20 b) (mkstruct boolval (1 0) __t975c18 b)) interp.slog:121 #f)
  class ReadTask127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex117;  slog::Index** $seq_atindex118;  slog::Index** $seq_atrindex119;  slog::Index** $seq_atrindex120;  slog::Index** _enumindex121;  slog::Index** any_boolindex122;  slog::Index** $seq_atdelta123;  slog::Index** $seq_atdelta124;  slog::Index** $seq_atrdelta125;  slog::Index** $seq_atrdelta126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4fHg844");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("delta");
      driver_index = readrel129->getIndex(ord128, true);
      std::vector<u16> ord130({1, 0, 2});
      slog::Relation* readrel131 = db->getRelation("$seq_at");
      $seq_atindex117 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0, 2});
      slog::Relation* readrel133 = db->getRelation("$seq_at");
      $seq_atdelta123 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({1, 0, 2});
      slog::Relation* readrel135 = db->getRelation("$seq_at");
      $seq_atindex118 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0, 2});
      slog::Relation* readrel137 = db->getRelation("$seq_at");
      $seq_atdelta124 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({1, 0, 2});
      slog::Relation* readrel139 = db->getRelation("$seq_atr");
      $seq_atrindex119 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0, 2});
      slog::Relation* readrel141 = db->getRelation("$seq_atr");
      $seq_atrdelta125 = readrel141->getIndex(ord140, true);
      std::vector<u16> ord142({1, 0, 2});
      slog::Relation* readrel143 = db->getRelation("$seq_atr");
      $seq_atrindex120 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0, 2});
      slog::Relation* readrel145 = db->getRelation("$seq_atr");
      $seq_atrdelta126 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("_enum");
      _enumindex121 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0});
      slog::Relation* readrel149 = db->getRelation("any_bool");
      any_boolindex122 = readrel149->getIndex(ord148, false);
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c26 = v_const06abaa100ecef791ce028c56;
      u64 v_c27 = v_constd4735e3a265e16eee03f5971;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c26, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m150) {
        u64 v_c34 = m150[1];
        u64 v_c35 = m150[2];
        if (buckethash(v_c34) != bucket) return;
        bool ok151 = true;
        u64 v_c36 = _prim_aslst(db, v_c34, &ok151);
        if (!ok151) return;
        bool ok152 = true;
        u64 v_c37 = _prim_lref(db, v_c36, v_c28, &ok152);
        if (!ok152) return;
        slog::join_probe_old<3,3>($seq_atindex117, $seq_atdelta123, std::array<u64,3>{v_c30, v_c37, v_c34}, [&](const std::array<u64,3>& m153) {
          slog::join_probe_old<3,3>($seq_atindex118, $seq_atdelta124, std::array<u64,3>{v_c31, v_c37, v_c34}, [&](const std::array<u64,3>& m154) {
            slog::join_probe_old<3,3>($seq_atrindex119, $seq_atrdelta125, std::array<u64,3>{v_c32, v_c37, v_c34}, [&](const std::array<u64,3>& m155) {
              slog::join_probe_old<3,3>($seq_atrindex120, $seq_atrdelta126, std::array<u64,3>{v_c33, v_c37, v_c34}, [&](const std::array<u64,3>& m156) {
                slog::join_probe<2,2>(_enumindex121, std::array<u64,2>{v_c37, v_c25}, [&](const std::array<u64,2>& m157) {
                  slog::join_all<1>(any_boolindex122, [&](const std::array<u64,1>& m158) {
                    u64 v_c38 = m158[0];
                    u64 v_c39 = _prim_llen(db, v_c36);
                    if (v_c39 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c27 != v_c39) return;
                    bool ok159 = true;
                    u64 v_c40 = _prim_lref(db, v_c36, v_c29, &ok159);
                    if (!ok159) return;
                    if (v_c37 != v_c40) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c35, v_c38});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
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
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre) (scan temp2tOv861 __t6eLD68 m) (body) (head (mkstruct lst_take (1 2 0) __9zLS560 __t6eLD68 m)) context.slog:10 #f)
  class ReadTask160 : public slog::Task
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
      head_rel[0] = db->getRelation("lst_take");
      outer_rel = db->getRelation("temp2tOv861");
  
    }
    ReadTask160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c41, v_c42}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp2tOv861", _fires);
  
      if (!_done)
      {
        ReadTask160* _cont = new ReadTask160(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask160(db,b), false);
  // (crule (pre) (scan temp5ZiW945 __t1IV0337 b) (body (join boolval (1 0) 1 b __t4qAo336)) (head (emit delta_ans (0 1) __t1IV0337 __t4qAo336)) interp.slog:112 #f)
  class ReadTask162 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex161;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("delta_ans");
      head_index[0] = readrel164->getIndex(ord163, false);
      outer_rel = db->getRelation("temp5ZiW945");
      std::vector<u16> ord165({1, 0});
      slog::Relation* readrel166 = db->getRelation("boolval");
      boolvalindex161 = readrel166->getIndex(ord165, false);
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c38 = _t[1];
        slog::join_probe<2,1>(boolvalindex161, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m167) {
          u64 v_c44 = m167[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c44}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:temp5ZiW945", _fires);
  
      if (!_done)
      {
        ReadTask162* _cont = new ReadTask162(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), false);
  // (crule (pre) (scan select_branch_ans __t7P7f365 __v1) (body (join-old select_branch (0 1 2 3) 1 (0 1 2 3) __t7P7f365 __v0 e2 e3) (exists eval_ans (1 0) 1 __v0) (join $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3 e1 __d0 c) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t4vYZ364) (join eval_ans (0 1) 2 __t4vYZ364 __v0)) (head (mkstruct eval (1 2 0) __4AHX627 __v1 c)) interp.slog:87 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex168;  slog::Index** eval_ansindex169;  slog::Index** $sup56712x86x0x0x0index170;  slog::Index** evalindex171;  slog::Index** eval_ansindex172;  slog::Index** select_branchdelta173;  slog::Index** evaldelta174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord176({0, 1, 2, 3});
      slog::Relation* readrel177 = db->getRelation("select_branch");
      select_branchindex168 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({0, 1, 2, 3});
      slog::Relation* readrel179 = db->getRelation("select_branch");
      select_branchdelta173 = readrel179->getIndex(ord178, true);
      std::vector<u16> ord180({1, 0});
      slog::Relation* readrel181 = db->getRelation("eval_ans");
      eval_ansindex169 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({3, 4, 2, 0, 1});
      slog::Relation* readrel183 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index170 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("eval");
      evalindex171 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("eval");
      evaldelta174 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("eval_ans");
      eval_ansindex172 = readrel189->getIndex(ord188, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[1];
        slog::join_probe_old<4,1>(select_branchindex168, select_branchdelta173, std::array<u64,4>{v_c45, 0, 0, 0}, [&](const std::array<u64,4>& m190) {
          u64 v_c24 = m190[1]; u64 v_c47 = m190[2]; u64 v_c48 = m190[3];
          if (!slog::exists_probe<2,1>(eval_ansindex169, std::array<u64,2>{v_c24, 0})) return;
          slog::join_probe<5,2>($sup56712x86x0x0x0index170, std::array<u64,5>{v_c47, v_c48, 0, 0, 0}, [&](const std::array<u64,5>& m191) {
            u64 v_c49 = m191[2]; u64 v_c50 = m191[3]; u64 v_c3 = m191[4];
            slog::join_probe_old<3,2>(evalindex171, evaldelta174, std::array<u64,3>{v_c49, v_c3, 0}, [&](const std::array<u64,3>& m192) {
              u64 v_c51 = m192[2];
              slog::join_probe<2,2>(eval_ansindex172, std::array<u64,2>{v_c51, v_c24}, [&](const std::array<u64,2>& m193) {
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c46, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask175* _cont = new ReadTask175(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask175(db,b), false);
  // (crule (pre) (scan eval_ans __t4vYZ364 __v0) (body (exists select_branch (1 2 3 0) 1 __v0) (join-old eval (0 2 1) 1 (0 2 1) __t4vYZ364 c e1) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join-old select_branch (1 2 3 0) 3 (1 2 3 0) __v0 e2 e3 __t7P7f365) (join-old select_branch_ans (0 1) 1 (0 1) __t7P7f365 __v1)) (head (mkstruct eval (1 2 0) __4AHX627 __v1 c)) interp.slog:87 #f)
  class ReadTask202 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex194;  slog::Index** evalindex195;  slog::Index** $sup56712x86x0x0x0index196;  slog::Index** select_branchindex197;  slog::Index** select_branch_ansindex198;  slog::Index** evaldelta199;  slog::Index** select_branchdelta200;  slog::Index** select_branch_ansdelta201;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord203({1, 2, 3, 0});
      slog::Relation* readrel204 = db->getRelation("select_branch");
      select_branchindex194 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 2, 1});
      slog::Relation* readrel206 = db->getRelation("eval");
      evalindex195 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 2, 1});
      slog::Relation* readrel208 = db->getRelation("eval");
      evaldelta199 = readrel208->getIndex(ord207, true);
      std::vector<u16> ord209({1, 2, 0, 3, 4});
      slog::Relation* readrel210 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index196 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 3, 0});
      slog::Relation* readrel212 = db->getRelation("select_branch");
      select_branchindex197 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 3, 0});
      slog::Relation* readrel214 = db->getRelation("select_branch");
      select_branchdelta200 = readrel214->getIndex(ord213, true);
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("select_branch_ans");
      select_branch_ansindex198 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("select_branch_ans");
      select_branch_ansdelta201 = readrel218->getIndex(ord217, true);
  
    }
    ReadTask202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[0];
        u64 v_c24 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex194, std::array<u64,4>{v_c24, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex195, evaldelta199, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m219) {
          u64 v_c3 = m219[1]; u64 v_c49 = m219[2];
          slog::join_probe<5,2>($sup56712x86x0x0x0index196, std::array<u64,5>{v_c3, v_c49, 0, 0, 0}, [&](const std::array<u64,5>& m220) {
            u64 v_c50 = m220[2]; u64 v_c47 = m220[3]; u64 v_c48 = m220[4];
            slog::join_probe_old<4,3>(select_branchindex197, select_branchdelta200, std::array<u64,4>{v_c24, v_c47, v_c48, 0}, [&](const std::array<u64,4>& m221) {
              u64 v_c45 = m221[3];
              slog::join_probe_old<2,1>(select_branch_ansindex198, select_branch_ansdelta201, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m222) {
                u64 v_c46 = m222[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c46, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
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
  // (crule (pre) (scan eval __t1yWg361 er c) (body (exists eval (2 0 1) 1 c) (exists let (2 1 3 0) 1 er) (join eval_ans (0 1) 1 __t1yWg361 vr) (join eval (2 0 1) 1 c __9hFj634 __t9408360) (join let (0 2 1 3) 2 __t9408360 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex223;  slog::Index** letindex224;  slog::Index** eval_ansindex225;  slog::Index** evalindex226;  slog::Index** letindex227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord229({0, 1, 2});
      slog::Relation* readrel230 = db->getRelation("binding");
      head_index[0] = readrel230->getIndex(ord229, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord231({0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("binding_event");
      head_index[1] = readrel232->getIndex(ord231, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord233({2, 0, 1});
      slog::Relation* readrel234 = db->getRelation("eval");
      evalindex223 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({2, 1, 3, 0});
      slog::Relation* readrel236 = db->getRelation("let");
      letindex224 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("eval_ans");
      eval_ansindex225 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({2, 0, 1});
      slog::Relation* readrel240 = db->getRelation("eval");
      evalindex226 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({0, 2, 1, 3});
      slog::Relation* readrel242 = db->getRelation("let");
      letindex227 = readrel242->getIndex(ord241, false);
  
    }
    ReadTask228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex223, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letindex224, std::array<u64,4>{v_c53, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex225, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m243) {
          u64 v_c54 = m243[1];
          slog::join_probe<3,1>(evalindex226, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m244) {
            u64 v_c55 = m244[1]; u64 v_c56 = m244[2];
            slog::join_probe<4,2>(letindex227, std::array<u64,4>{v_c56, v_c53, 0, 0}, [&](const std::array<u64,4>& m245) {
              u64 v_c22 = m245[2]; u64 v_c10 = m245[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c22, v_c3, v_c54}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c22, v_c3, v_c3}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask228* _cont = new ReadTask228(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask228(db,b), false);
  // (crule (pre) (scan eval_args __t4aOO390 es c) (body (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t4aOO390) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __t0zOO387 ef) (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval (1 2 0) 2 ef c) (join app (1 2 0) 2 ef es __t2JOw386) (join eval (0 2 1) 3 __t0zOO387 c __t2JOw386) (join eval (1 2 0) 2 ef c __t9EYC388) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (exists delta (2 0 1) 1 vs) (join prim (0 1) 1 __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex246;  slog::Index** evalindex247;  slog::Index** eval_args_ansindex248;  slog::Index** $sup56712x74x0x0x0index249;  slog::Index** evalindex250;  slog::Index** evalindex251;  slog::Index** appindex252;  slog::Index** evalindex253;  slog::Index** evalindex254;  slog::Index** eval_ansindex255;  slog::Index** eval_args_ansindex256;  slog::Index** deltaindex257;  slog::Index** primindex258;  slog::Index** deltaindex259;  slog::Index** delta_ansindex260;  slog::Index** deltadelta261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("eval_ans");
      head_index[0] = readrel264->getIndex(ord263, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord265({2, 0, 1});
      slog::Relation* readrel266 = db->getRelation("app");
      appindex246 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({2, 0, 1});
      slog::Relation* readrel268 = db->getRelation("eval");
      evalindex247 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("eval_args_ans");
      eval_args_ansindex248 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 3, 0, 2});
      slog::Relation* readrel272 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index249 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 2, 1});
      slog::Relation* readrel274 = db->getRelation("eval");
      evalindex250 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({1, 2, 0});
      slog::Relation* readrel276 = db->getRelation("eval");
      evalindex251 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 0});
      slog::Relation* readrel278 = db->getRelation("app");
      appindex252 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({0, 2, 1});
      slog::Relation* readrel280 = db->getRelation("eval");
      evalindex253 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("eval");
      evalindex254 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("eval_ans");
      eval_ansindex255 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("eval_args_ans");
      eval_args_ansindex256 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({2, 0, 1});
      slog::Relation* readrel288 = db->getRelation("delta");
      deltaindex257 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("prim");
      primindex258 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("delta");
      deltaindex259 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("delta");
      deltadelta261 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({0, 1});
      slog::Relation* readrel296 = db->getRelation("delta_ans");
      delta_ansindex260 = readrel296->getIndex(ord295, false);
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(appindex246, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex247, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex248, std::array<u64,2>{v_c57, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index249, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m297) {
          u64 v_c58 = m297[2]; u64 v_c1 = m297[3];
          if (!slog::exists_probe<3,2>(evalindex250, std::array<u64,3>{v_c58, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex251, std::array<u64,3>{v_c1, v_c3, 0})) return;
          slog::join_probe<3,2>(appindex252, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m298) {
            u64 v_c59 = m298[2];
            slog::join_probe<3,3>(evalindex253, std::array<u64,3>{v_c58, v_c3, v_c59}, [&](const std::array<u64,3>& m299) {
              slog::join_probe<3,2>(evalindex254, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m300) {
                u64 v_c60 = m300[2];
                slog::join_probe<2,1>(eval_ansindex255, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m301) {
                  u64 v_c61 = m301[1];
                  slog::join_probe<2,1>(eval_args_ansindex256, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m302) {
                    u64 v_c18 = m302[1];
                    if (!slog::exists_probe<3,1>(deltaindex257, std::array<u64,3>{v_c18, 0, 0})) return;
                    slog::join_probe<2,1>(primindex258, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m303) {
                      u64 v_c62 = m303[1];
                      slog::join_probe_old<3,2>(deltaindex259, deltadelta261, std::array<u64,3>{v_c62, v_c18, 0}, [&](const std::array<u64,3>& m304) {
                        u64 v_c63 = m304[2];
                        slog::join_probe<2,1>(delta_ansindex260, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m305) {
                          u64 v_c64 = m305[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c64}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre) (scan eval __4zPb614 __t8csz347 c) (body (join-old app (0 1 2) 1 (0 1 2) __t8csz347 ef es)) (head (mkstruct eval (1 2 0) __0JTh615 ef c)) analysis.slog:11 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex306;  slog::Index** appdelta307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord309({0, 1, 2});
      slog::Relation* readrel310 = db->getRelation("app");
      appindex306 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({0, 1, 2});
      slog::Relation* readrel312 = db->getRelation("app");
      appdelta307 = readrel312->getIndex(ord311, true);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[0];
        u64 v_c66 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe_old<3,1>(appindex306, appdelta307, std::array<u64,3>{v_c66, 0, 0}, [&](const std::array<u64,3>& m313) {
          u64 v_c1 = m313[1]; u64 v_c2 = m313[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:11", "delta:eval", _fires);
  
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
  // (crule (pre (let __trid4BXR652 const119eb3a23d030ee0dfe9f807) (let __trel0eDk653 const4a59dbb9cb3129dfcc75170b) (let __tcol0Seo654 const5feceb66ffc86f38d952786c) (let __trel3dMM655 const4a59dbb9cb3129dfcc75170b) (let __tcol45C5656 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid4BXR652 __trel0eDk653 __tcol0Seo654 (1 2 3 4 0)) (tycheck c (accept seq) __trid4BXR652 __trel3dMM655 __tcol45C5656 (1 2 3 4 0)) (mkstruct eval (1 2 0) __766O651 ef c)) interp.slog:42 #f)
  class ReadTask323 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid314;  u32 sid315;  u32 sid316;  u32 sid317;  u32 sid318;  u32 sid319;  u32 sid320;  u32 sid321;  u32 sid322;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      sid314 = db->getRelation("app")->getStructId();
      sid315 = db->getRelation("boolean")->getStructId();
      sid316 = db->getRelation("if")->getStructId();
      sid317 = db->getRelation("lambda")->getStructId();
      sid318 = db->getRelation("let")->getStructId();
      sid319 = db->getRelation("letrec")->getStructId();
      sid320 = db->getRelation("num")->getStructId();
      sid321 = db->getRelation("ref")->getStructId();
      sid322 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask323(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c68 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c50 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid314 || decode_struct_id(v_c1) == sid315 || decode_struct_id(v_c1) == sid316 || decode_struct_id(v_c1) == sid317 || decode_struct_id(v_c1) == sid318 || decode_struct_id(v_c1) == sid319 || decode_struct_id(v_c1) == sid320 || decode_struct_id(v_c1) == sid321 || decode_struct_id(v_c1) == sid322))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c67, v_c68, v_c69, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c67, v_c70, v_c71, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask323* _cont = new ReadTask323(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask323(db,b), false);
  // (crule (pre) (scan app __t45PK165 ef es) (body (join eval (1 2 0) 1 __t45PK165 c __0ffn676) (join freevar (0 1) 0 y __t4lcS166) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t4lcS166 xs eb)) (head (mkstruct eval_args (1 2 0) __3T4u677 es c)) interp.slog:56 #f)
  class ReadTask328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex324;  slog::Index** freevarindex325;  slog::Index** bindingindex326;  slog::Index** lambdaindex327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("eval");
      evalindex324 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 1});
      slog::Relation* readrel332 = db->getRelation("freevar");
      freevarindex325 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({0, 1, 2});
      slog::Relation* readrel334 = db->getRelation("binding");
      bindingindex326 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({0, 1, 2});
      slog::Relation* readrel336 = db->getRelation("lambda");
      lambdaindex327 = readrel336->getIndex(ord335, false);
  
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
        u64 v_c72 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(evalindex324, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m337) {
          u64 v_c3 = m337[1]; u64 v_c73 = m337[2];
          slog::join_all<2>(freevarindex325, [&](const std::array<u64,2>& m338) {
            u64 v_c5 = m338[0]; u64 v_c74 = m338[1];
            slog::join_probe<3,1>(bindingindex326, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m339) {
              u64 v_c7 = m339[1]; u64 v_c8 = m339[2];
              slog::join_probe<3,1>(lambdaindex327, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m340) {
                u64 v_c9 = m340[1]; u64 v_c10 = m340[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:app", _fires);
  
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
  // (crule (pre) (scan eval __8Eqi628 __t0Yvq193 c) (body (join-old app (0 1 2) 1 (0 1 2) __t0Yvq193 ef es)) (head (mkstruct eval (1 2 0) __8GR8629 ef c)) analysis.slog:36 #f)
  class ReadTask343 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex341;  slog::Index** appdelta342;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord344({0, 1, 2});
      slog::Relation* readrel345 = db->getRelation("app");
      appindex341 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1, 2});
      slog::Relation* readrel347 = db->getRelation("app");
      appdelta342 = readrel347->getIndex(ord346, true);
  
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
        u64 v_c75 = _t[0];
        u64 v_c76 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe_old<3,1>(appindex341, appdelta342, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m348) {
          u64 v_c1 = m348[1]; u64 v_c2 = m348[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:36", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval __5izx673 __t9nj7324 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (join-old tick_ans (0 1) 1 (0 1) __t3nAR325 l) (join-old eval (2 0 1) 1 (2 0 1) c __t550i320 ef) (exists eval_ans (0 1) 1 __t550i320) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old eval_ans (0 1) 1 (0 1) __t550i320 __t2qAJ322) (join-old eval_args_ans (0 1) 1 (0 1) __t8cVn323 vs) (join-old closure (0 1 2) 1 (0 1 2) __t2qAJ322 __t7ycN321 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex349;  slog::Index** eval_argsindex350;  slog::Index** tickindex351;  slog::Index** tick_ansindex352;  slog::Index** evalindex353;  slog::Index** eval_ansindex354;  slog::Index** appindex355;  slog::Index** eval_argsindex356;  slog::Index** eval_args_ansindex357;  slog::Index** eval_ansindex358;  slog::Index** eval_args_ansindex359;  slog::Index** closureindex360;  slog::Index** lambdaindex361;  slog::Index** tickdelta362;  slog::Index** tick_ansdelta363;  slog::Index** evaldelta364;  slog::Index** appdelta365;  slog::Index** eval_argsdelta366;  slog::Index** eval_ansdelta367;  slog::Index** eval_args_ansdelta368;  slog::Index** closuredelta369;  slog::Index** lambdadelta370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord372({0, 1, 2, 3});
      slog::Relation* readrel373 = db->getRelation("bind_params");
      head_index[0] = readrel373->getIndex(ord372, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord374({0, 1});
      slog::Relation* readrel375 = db->getRelation("call_event");
      head_index[1] = readrel375->getIndex(ord374, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord376({2, 0, 1});
      slog::Relation* readrel377 = db->getRelation("eval");
      evalindex349 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({2, 0, 1});
      slog::Relation* readrel379 = db->getRelation("eval_args");
      eval_argsindex350 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("tick");
      tickindex351 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("tick");
      tickdelta362 = readrel383->getIndex(ord382, true);
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("tick_ans");
      tick_ansindex352 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("tick_ans");
      tick_ansdelta363 = readrel387->getIndex(ord386, true);
      std::vector<u16> ord388({2, 0, 1});
      slog::Relation* readrel389 = db->getRelation("eval");
      evalindex353 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({2, 0, 1});
      slog::Relation* readrel391 = db->getRelation("eval");
      evaldelta364 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("eval_ans");
      eval_ansindex354 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1, 2});
      slog::Relation* readrel395 = db->getRelation("app");
      appindex355 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2});
      slog::Relation* readrel397 = db->getRelation("app");
      appdelta365 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("eval_args");
      eval_argsindex356 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("eval_args");
      eval_argsdelta366 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("eval_args_ans");
      eval_args_ansindex357 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("eval_ans");
      eval_ansindex358 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("eval_ans");
      eval_ansdelta367 = readrel407->getIndex(ord406, true);
      std::vector<u16> ord408({0, 1});
      slog::Relation* readrel409 = db->getRelation("eval_args_ans");
      eval_args_ansindex359 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("eval_args_ans");
      eval_args_ansdelta368 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({0, 1, 2});
      slog::Relation* readrel413 = db->getRelation("closure");
      closureindex360 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({0, 1, 2});
      slog::Relation* readrel415 = db->getRelation("closure");
      closuredelta369 = readrel415->getIndex(ord414, true);
      std::vector<u16> ord416({0, 1, 2});
      slog::Relation* readrel417 = db->getRelation("lambda");
      lambdaindex361 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({0, 1, 2});
      slog::Relation* readrel419 = db->getRelation("lambda");
      lambdadelta370 = readrel419->getIndex(ord418, true);
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex349, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex350, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex351, tickdelta362, std::array<u64,3>{v_c12, v_c3, 0}, [&](const std::array<u64,3>& m420) {
          u64 v_c11 = m420[2];
          slog::join_probe_old<2,1>(tick_ansindex352, tick_ansdelta363, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m421) {
            u64 v_c14 = m421[1];
            slog::join_probe_old<3,1>(evalindex353, evaldelta364, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m422) {
              u64 v_c15 = m422[1]; u64 v_c1 = m422[2];
              if (!slog::exists_probe<2,1>(eval_ansindex354, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe_old<3,2>(appindex355, appdelta365, std::array<u64,3>{v_c12, v_c1, 0}, [&](const std::array<u64,3>& m423) {
                u64 v_c2 = m423[2];
                slog::join_probe_old<3,2>(eval_argsindex356, eval_argsdelta366, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m424) {
                  u64 v_c16 = m424[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex357, std::array<u64,2>{v_c16, 0})) return;
                  slog::join_probe_old<2,1>(eval_ansindex358, eval_ansdelta367, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m425) {
                    u64 v_c17 = m425[1];
                    slog::join_probe_old<2,1>(eval_args_ansindex359, eval_args_ansdelta368, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m426) {
                      u64 v_c18 = m426[1];
                      slog::join_probe_old<3,1>(closureindex360, closuredelta369, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m427) {
                        u64 v_c19 = m427[1]; u64 v_c7 = m427[2];
                        slog::join_probe_old<3,1>(lambdaindex361, lambdadelta370, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m428) {
                          u64 v_c9 = m428[1]; u64 v_c10 = m428[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c18, v_c14, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c14, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
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
  // (crule (pre) (scan temp5zyE1032 __t17mt343 s) (body (join symval (1 0) 1 s __t2VgD341)) (head (emit eval_ans (0 1) __t17mt343 __t2VgD341)) interp.slog:28 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symvalindex429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("eval_ans");
      head_index[0] = readrel432->getIndex(ord431, false);
      outer_rel = db->getRelation("temp5zyE1032");
      std::vector<u16> ord433({1, 0});
      slog::Relation* readrel434 = db->getRelation("symval");
      symvalindex429 = readrel434->getIndex(ord433, false);
  
    }
    ReadTask430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(symvalindex429, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m435) {
          u64 v_c79 = m435[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c77, v_c79}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:28", "delta:temp5zyE1032", _fires);
  
      if (!_done)
      {
        ReadTask430* _cont = new ReadTask430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask430(db,b), false);
  // (crule (pre) (scan freevar x e2) (body (join-old if (2 3 1 0) 1 (2 3 1 0) e2 e3 e1 __t2Vv2345)) (head (emit freevar (0 1) x __t2Vv2345)) freevars.slog:17 #f)
  class ReadTask438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex436;  slog::Index** ifdelta437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("freevar");
      head_index[0] = readrel440->getIndex(ord439, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord441({2, 3, 1, 0});
      slog::Relation* readrel442 = db->getRelation("if");
      ifindex436 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({2, 3, 1, 0});
      slog::Relation* readrel444 = db->getRelation("if");
      ifdelta437 = readrel444->getIndex(ord443, true);
  
    }
    ReadTask438(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[1];
        slog::join_probe_old<4,1>(ifindex436, ifdelta437, std::array<u64,4>{v_c47, 0, 0, 0}, [&](const std::array<u64,4>& m445) {
          u64 v_c48 = m445[1]; u64 v_c49 = m445[2]; u64 v_c80 = m445[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c80}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask438* _cont = new ReadTask438(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask438(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4yFo471 __t5qKD331 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5RED468 __t5qKD331 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo66CB469 __t5qKD331 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo5qV2470 __t5qKD331 _00024seq2) (exists _enum (1 0) 1 __tconst2WdB587) (join delta (1 2 0) 2 __tconst2sal328 _00024seq2 __t8DFh329) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join symval (0 1) 1 __t5qKD331 s) (letp _00024sql2Y3P463 (aslst _00024seq2)) (let chk3fDs895 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk3fDs895) (letp chk8cFW896 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (eq __t5qKD331 chk8cFW896) (letp chk7PL6897 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk7PL6897)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex446;  slog::Index** $seq_atindex447;  slog::Index** $seq_atrindex448;  slog::Index** _enumindex449;  slog::Index** deltaindex450;  slog::Index** _enumindex451;  slog::Index** symvalindex452;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord454({1, 0, 2});
      slog::Relation* readrel455 = db->getRelation("$seq_atr");
      driver_index = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({1, 0, 2});
      slog::Relation* readrel457 = db->getRelation("$seq_at");
      $seq_atindex446 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0, 2});
      slog::Relation* readrel459 = db->getRelation("$seq_at");
      $seq_atindex447 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 0, 2});
      slog::Relation* readrel461 = db->getRelation("$seq_atr");
      $seq_atrindex448 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("_enum");
      _enumindex449 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("delta");
      deltaindex450 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("_enum");
      _enumindex451 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({0, 1});
      slog::Relation* readrel469 = db->getRelation("symval");
      symvalindex452 = readrel469->getIndex(ord468, false);
  
    }
    ReadTask453(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c81 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c82 = v_const06abaa100ecef791ce028c56;
      u64 v_c83 = v_constd4735e3a265e16eee03f5971;
      u64 v_c84 = v_const5feceb66ffc86f38d952786c;
      u64 v_c85 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c89, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m470) {
        u64 v_c90 = m470[1];
        u64 v_c34 = m470[2];
        if (buckethash(v_c90) != bucket) return;
        slog::join_probe<3,3>($seq_atindex446, std::array<u64,3>{v_c86, v_c90, v_c34}, [&](const std::array<u64,3>& m471) {
          slog::join_probe<3,3>($seq_atindex447, std::array<u64,3>{v_c87, v_c90, v_c34}, [&](const std::array<u64,3>& m472) {
            slog::join_probe<3,3>($seq_atrindex448, std::array<u64,3>{v_c88, v_c90, v_c34}, [&](const std::array<u64,3>& m473) {
              if (!slog::exists_probe<2,1>(_enumindex449, std::array<u64,2>{v_c81, 0})) return;
              slog::join_probe<3,2>(deltaindex450, std::array<u64,3>{v_c82, v_c34, 0}, [&](const std::array<u64,3>& m474) {
                u64 v_c91 = m474[2];
                slog::join_probe<2,1>(_enumindex451, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m475) {
                  u64 v_c92 = m475[1];
                  slog::join_probe<2,1>(symvalindex452, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m476) {
                    u64 v_c78 = m476[1];
                    bool ok477 = true;
                    u64 v_c93 = _prim_aslst(db, v_c34, &ok477);
                    if (!ok477) return;
                    u64 v_c94 = _prim_llen(db, v_c93);
                    if (v_c94 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c83 != v_c94) return;
                    bool ok478 = true;
                    u64 v_c95 = _prim_lref(db, v_c93, v_c84, &ok478);
                    if (!ok478) return;
                    if (v_c90 != v_c95) return;
                    bool ok479 = true;
                    u64 v_c96 = _prim_lref(db, v_c93, v_c85, &ok479);
                    if (!ok479) return;
                    if (v_c90 != v_c96) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c91});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c92}, std::array<u16,2>{1, 0});
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
        ReadTask453* _cont = new ReadTask453(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask453(db,b), false);
  // (crule (pre) (scan app __t2JOw386 ef es) (body (exists eval (1 2 0) 1 __t2JOw386) (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (join $sup56712x74x0x0x0 (2 3 0 1) 2 ef es __t0zOO387 c) (join-old eval (0 2 1) 3 (0 2 1) __t0zOO387 c __t2JOw386) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t9EYC388) (exists eval_ans (0 1) 1 __t9EYC388) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (exists eval_args_ans (0 1) 1 __t4aOO390) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask501 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex480;  slog::Index** evalindex481;  slog::Index** eval_argsindex482;  slog::Index** $sup56712x74x0x0x0index483;  slog::Index** evalindex484;  slog::Index** eval_argsindex485;  slog::Index** evalindex486;  slog::Index** eval_ansindex487;  slog::Index** eval_argsindex488;  slog::Index** eval_args_ansindex489;  slog::Index** eval_ansindex490;  slog::Index** eval_args_ansindex491;  slog::Index** deltaindex492;  slog::Index** primindex493;  slog::Index** deltaindex494;  slog::Index** delta_ansindex495;  slog::Index** evaldelta496;  slog::Index** evaldelta497;  slog::Index** eval_argsdelta498;  slog::Index** primdelta499;  slog::Index** deltadelta500;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("eval_ans");
      head_index[0] = readrel503->getIndex(ord502, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("eval");
      evalindex480 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("eval");
      evalindex481 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("eval_args");
      eval_argsindex482 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({2, 3, 0, 1});
      slog::Relation* readrel511 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index483 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 2, 1});
      slog::Relation* readrel513 = db->getRelation("eval");
      evalindex484 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 2, 1});
      slog::Relation* readrel515 = db->getRelation("eval");
      evaldelta496 = readrel515->getIndex(ord514, true);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("eval_args");
      eval_argsindex485 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 0});
      slog::Relation* readrel519 = db->getRelation("eval");
      evalindex486 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 2, 0});
      slog::Relation* readrel521 = db->getRelation("eval");
      evaldelta497 = readrel521->getIndex(ord520, true);
      std::vector<u16> ord522({0, 1});
      slog::Relation* readrel523 = db->getRelation("eval_ans");
      eval_ansindex487 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 2, 0});
      slog::Relation* readrel525 = db->getRelation("eval_args");
      eval_argsindex488 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 2, 0});
      slog::Relation* readrel527 = db->getRelation("eval_args");
      eval_argsdelta498 = readrel527->getIndex(ord526, true);
      std::vector<u16> ord528({0, 1});
      slog::Relation* readrel529 = db->getRelation("eval_args_ans");
      eval_args_ansindex489 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 1});
      slog::Relation* readrel531 = db->getRelation("eval_ans");
      eval_ansindex490 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({0, 1});
      slog::Relation* readrel533 = db->getRelation("eval_args_ans");
      eval_args_ansindex491 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({2, 0, 1});
      slog::Relation* readrel535 = db->getRelation("delta");
      deltaindex492 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("prim");
      primindex493 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 1});
      slog::Relation* readrel539 = db->getRelation("prim");
      primdelta499 = readrel539->getIndex(ord538, true);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("delta");
      deltaindex494 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 2, 0});
      slog::Relation* readrel543 = db->getRelation("delta");
      deltadelta500 = readrel543->getIndex(ord542, true);
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("delta_ans");
      delta_ansindex495 = readrel545->getIndex(ord544, false);
  
    }
    ReadTask501(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex480, std::array<u64,3>{v_c59, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex481, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex482, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index483, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m546) {
          u64 v_c58 = m546[2]; u64 v_c3 = m546[3];
          slog::join_probe_old<3,3>(evalindex484, evaldelta496, std::array<u64,3>{v_c58, v_c3, v_c59}, [&](const std::array<u64,3>& m547) {
            if (!slog::exists_probe<3,2>(eval_argsindex485, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<3,2>(evalindex486, evaldelta497, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m548) {
              u64 v_c60 = m548[2];
              if (!slog::exists_probe<2,1>(eval_ansindex487, std::array<u64,2>{v_c60, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex488, eval_argsdelta498, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m549) {
                u64 v_c57 = m549[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex489, std::array<u64,2>{v_c57, 0})) return;
                slog::join_probe<2,1>(eval_ansindex490, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m550) {
                  u64 v_c61 = m550[1];
                  slog::join_probe<2,1>(eval_args_ansindex491, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m551) {
                    u64 v_c18 = m551[1];
                    if (!slog::exists_probe<3,1>(deltaindex492, std::array<u64,3>{v_c18, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex493, primdelta499, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m552) {
                      u64 v_c62 = m552[1];
                      slog::join_probe_old<3,2>(deltaindex494, deltadelta500, std::array<u64,3>{v_c62, v_c18, 0}, [&](const std::array<u64,3>& m553) {
                        u64 v_c63 = m553[2];
                        slog::join_probe<2,1>(delta_ansindex495, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m554) {
                          u64 v_c64 = m554[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c64}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask501* _cont = new ReadTask501(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask501(db,b), false);
  // (crule (pre) (scan temp2lwj860 __t895k67 c m) (body (let __t6eLD68 (lcat __t895k67 c))) (head (emit-temp temp2tOv861 __t6eLD68 m)) context.slog:10 #f)
  class ReadTask555 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2tOv861");
      outer_rel = db->getRelation("temp2lwj860");
  
    }
    ReadTask555(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c42 = _t[2];
        u64 v_c41 = _prim_lcat(db, v_c97, v_c3);
        if (v_c41 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c41, v_c42});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp2lwj860", _fires);
  
      if (!_done)
      {
        ReadTask555* _cont = new ReadTask555(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask555(db,b), false);
  // (crule (pre) (scan eval_ans __t9EYC388 __t22Li389) (body (join-old prim (0 1) 1 (0 1) __t22Li389 op) (exists delta (1 2 0) 1 op) (join-old eval (0 2 1) 1 (0 2 1) __t9EYC388 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old $sup56712x74x0x0x0 (1 2 3 0) 2 (1 2 3 0) c ef es __t0zOO387) (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval_args (1 2 0) 2 es c) (join-old app (1 2 0) 2 (1 2 0) ef es __t2JOw386) (join-old eval (0 2 1) 3 (0 2 1) __t0zOO387 c __t2JOw386) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (join-old eval_args_ans (0 1) 1 (0 1) __t4aOO390 vs) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join-old delta_ans (0 1) 1 (0 1) __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask580 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex556;  slog::Index** deltaindex557;  slog::Index** evalindex558;  slog::Index** appindex559;  slog::Index** evalindex560;  slog::Index** eval_argsindex561;  slog::Index** $sup56712x74x0x0x0index562;  slog::Index** evalindex563;  slog::Index** eval_argsindex564;  slog::Index** appindex565;  slog::Index** evalindex566;  slog::Index** eval_argsindex567;  slog::Index** eval_args_ansindex568;  slog::Index** deltaindex569;  slog::Index** delta_ansindex570;  slog::Index** primdelta571;  slog::Index** evaldelta572;  slog::Index** $sup56712x74x0x0x0delta573;  slog::Index** appdelta574;  slog::Index** evaldelta575;  slog::Index** eval_argsdelta576;  slog::Index** eval_args_ansdelta577;  slog::Index** deltadelta578;  slog::Index** delta_ansdelta579;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord581({0, 1});
      slog::Relation* readrel582 = db->getRelation("eval_ans");
      head_index[0] = readrel582->getIndex(ord581, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("prim");
      primindex556 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("prim");
      primdelta571 = readrel586->getIndex(ord585, true);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("delta");
      deltaindex557 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({0, 2, 1});
      slog::Relation* readrel590 = db->getRelation("eval");
      evalindex558 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 2, 1});
      slog::Relation* readrel592 = db->getRelation("eval");
      evaldelta572 = readrel592->getIndex(ord591, true);
      std::vector<u16> ord593({1, 2, 0});
      slog::Relation* readrel594 = db->getRelation("app");
      appindex559 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({2, 0, 1});
      slog::Relation* readrel596 = db->getRelation("eval");
      evalindex560 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({2, 0, 1});
      slog::Relation* readrel598 = db->getRelation("eval_args");
      eval_argsindex561 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 3, 0});
      slog::Relation* readrel600 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index562 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 3, 0});
      slog::Relation* readrel602 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta573 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({0, 2, 1});
      slog::Relation* readrel604 = db->getRelation("eval");
      evalindex563 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({1, 2, 0});
      slog::Relation* readrel606 = db->getRelation("eval_args");
      eval_argsindex564 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 2, 0});
      slog::Relation* readrel608 = db->getRelation("app");
      appindex565 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 2, 0});
      slog::Relation* readrel610 = db->getRelation("app");
      appdelta574 = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({0, 2, 1});
      slog::Relation* readrel612 = db->getRelation("eval");
      evalindex566 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({0, 2, 1});
      slog::Relation* readrel614 = db->getRelation("eval");
      evaldelta575 = readrel614->getIndex(ord613, true);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("eval_args");
      eval_argsindex567 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("eval_args");
      eval_argsdelta576 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("eval_args_ans");
      eval_args_ansindex568 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({0, 1});
      slog::Relation* readrel622 = db->getRelation("eval_args_ans");
      eval_args_ansdelta577 = readrel622->getIndex(ord621, true);
      std::vector<u16> ord623({1, 2, 0});
      slog::Relation* readrel624 = db->getRelation("delta");
      deltaindex569 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("delta");
      deltadelta578 = readrel626->getIndex(ord625, true);
      std::vector<u16> ord627({0, 1});
      slog::Relation* readrel628 = db->getRelation("delta_ans");
      delta_ansindex570 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("delta_ans");
      delta_ansdelta579 = readrel630->getIndex(ord629, true);
  
    }
    ReadTask580(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        slog::join_probe_old<2,1>(primindex556, primdelta571, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m631) {
          u64 v_c62 = m631[1];
          if (!slog::exists_probe<3,1>(deltaindex557, std::array<u64,3>{v_c62, 0, 0})) return;
          slog::join_probe_old<3,1>(evalindex558, evaldelta572, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m632) {
            u64 v_c3 = m632[1]; u64 v_c1 = m632[2];
            if (!slog::exists_probe<3,1>(appindex559, std::array<u64,3>{v_c1, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex560, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex561, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe_old<4,2>($sup56712x74x0x0x0index562, $sup56712x74x0x0x0delta573, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m633) {
              u64 v_c2 = m633[2]; u64 v_c58 = m633[3];
              if (!slog::exists_probe<3,2>(evalindex563, std::array<u64,3>{v_c58, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex564, std::array<u64,3>{v_c2, v_c3, 0})) return;
              slog::join_probe_old<3,2>(appindex565, appdelta574, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m634) {
                u64 v_c59 = m634[2];
                slog::join_probe_old<3,3>(evalindex566, evaldelta575, std::array<u64,3>{v_c58, v_c3, v_c59}, [&](const std::array<u64,3>& m635) {
                  slog::join_probe_old<3,2>(eval_argsindex567, eval_argsdelta576, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m636) {
                    u64 v_c57 = m636[2];
                    slog::join_probe_old<2,1>(eval_args_ansindex568, eval_args_ansdelta577, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m637) {
                      u64 v_c18 = m637[1];
                      slog::join_probe_old<3,2>(deltaindex569, deltadelta578, std::array<u64,3>{v_c62, v_c18, 0}, [&](const std::array<u64,3>& m638) {
                        u64 v_c63 = m638[2];
                        slog::join_probe_old<2,1>(delta_ansindex570, delta_ansdelta579, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m639) {
                          u64 v_c64 = m639[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c64}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask580* _cont = new ReadTask580(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask580(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst9XQ5142 _00024seq2 __t9sdv143) (body (letp _00024sql8vYG444 (aslst _00024seq2)) (letp __t4Puk145 (lref _00024sql8vYG444 _00024sqc5yoB447)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7aST449 __t4Puk145 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1C1f450 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Q0D451 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7GLE452 __t4Puk145 _00024seq2) (join-old closure (0 1 2) 1 (0 1 2) __t4Puk145 lm cb) (join any_bool (0) 0 b) (let chk5Jyg913 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk5Jyg913) (letp chk8laD914 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk8laD914)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask651 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex640;  slog::Index** $seq_atindex641;  slog::Index** $seq_atrindex642;  slog::Index** $seq_atrindex643;  slog::Index** closureindex644;  slog::Index** any_boolindex645;  slog::Index** $seq_atdelta646;  slog::Index** $seq_atdelta647;  slog::Index** $seq_atrdelta648;  slog::Index** $seq_atrdelta649;  slog::Index** closuredelta650;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("delta");
      driver_index = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({1, 0, 2});
      slog::Relation* readrel655 = db->getRelation("$seq_at");
      $seq_atindex640 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 0, 2});
      slog::Relation* readrel657 = db->getRelation("$seq_at");
      $seq_atdelta646 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({1, 0, 2});
      slog::Relation* readrel659 = db->getRelation("$seq_at");
      $seq_atindex641 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 0, 2});
      slog::Relation* readrel661 = db->getRelation("$seq_at");
      $seq_atdelta647 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({1, 0, 2});
      slog::Relation* readrel663 = db->getRelation("$seq_atr");
      $seq_atrindex642 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0, 2});
      slog::Relation* readrel665 = db->getRelation("$seq_atr");
      $seq_atrdelta648 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({1, 0, 2});
      slog::Relation* readrel667 = db->getRelation("$seq_atr");
      $seq_atrindex643 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 0, 2});
      slog::Relation* readrel669 = db->getRelation("$seq_atr");
      $seq_atrdelta649 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({0, 1, 2});
      slog::Relation* readrel671 = db->getRelation("closure");
      closureindex644 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1, 2});
      slog::Relation* readrel673 = db->getRelation("closure");
      closuredelta650 = readrel673->getIndex(ord672, true);
      std::vector<u16> ord674({0});
      slog::Relation* readrel675 = db->getRelation("any_bool");
      any_boolindex645 = readrel675->getIndex(ord674, false);
  
    }
    ReadTask651(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const06abaa100ecef791ce028c56;
      u64 v_c99 = v_constd4735e3a265e16eee03f5971;
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
      u64 v_c101 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c102 = v_const5feceb66ffc86f38d952786c;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c104 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c105 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c98, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m676) {
        u64 v_c34 = m676[1];
        u64 v_c106 = m676[2];
        if (buckethash(v_c34) != bucket) return;
        bool ok677 = true;
        u64 v_c107 = _prim_aslst(db, v_c34, &ok677);
        if (!ok677) return;
        bool ok678 = true;
        u64 v_c108 = _prim_lref(db, v_c107, v_c100, &ok678);
        if (!ok678) return;
        slog::join_probe_old<3,3>($seq_atindex640, $seq_atdelta646, std::array<u64,3>{v_c102, v_c108, v_c34}, [&](const std::array<u64,3>& m679) {
          slog::join_probe_old<3,3>($seq_atindex641, $seq_atdelta647, std::array<u64,3>{v_c103, v_c108, v_c34}, [&](const std::array<u64,3>& m680) {
            slog::join_probe_old<3,3>($seq_atrindex642, $seq_atrdelta648, std::array<u64,3>{v_c104, v_c108, v_c34}, [&](const std::array<u64,3>& m681) {
              slog::join_probe_old<3,3>($seq_atrindex643, $seq_atrdelta649, std::array<u64,3>{v_c105, v_c108, v_c34}, [&](const std::array<u64,3>& m682) {
                slog::join_probe_old<3,1>(closureindex644, closuredelta650, std::array<u64,3>{v_c108, 0, 0}, [&](const std::array<u64,3>& m683) {
                  u64 v_c109 = m683[1]; u64 v_c7 = m683[2];
                  slog::join_all<1>(any_boolindex645, [&](const std::array<u64,1>& m684) {
                    u64 v_c38 = m684[0];
                    u64 v_c110 = _prim_llen(db, v_c107);
                    if (v_c110 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c99 != v_c110) return;
                    bool ok685 = true;
                    u64 v_c111 = _prim_lref(db, v_c107, v_c101, &ok685);
                    if (!ok685) return;
                    if (v_c108 != v_c111) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c106, v_c38});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask651* _cont = new ReadTask651(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask651(db,b), false);
  // (crule (pre) (scan eval_args_ans __t3tQh27 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t3tQh27 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (2 0 1) 2 (2 0 1) es __t3Fr129 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t84Ji24) (exists eval_ans (0 1) 1 __t84Ji24) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join-old tick_ans (0 1) 1 (0 1) __t0NvE30 l) (join-old closure (0 1 2) 1 (0 1 2) __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t3miO28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask713 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex686;  slog::Index** appindex687;  slog::Index** evalindex688;  slog::Index** tickindex689;  slog::Index** evalindex690;  slog::Index** tickindex691;  slog::Index** appindex692;  slog::Index** evalindex693;  slog::Index** eval_ansindex694;  slog::Index** tickindex695;  slog::Index** tick_ansindex696;  slog::Index** eval_ansindex697;  slog::Index** tick_ansindex698;  slog::Index** closureindex699;  slog::Index** bindingindex700;  slog::Index** freevarindex701;  slog::Index** bindingindex702;  slog::Index** lambdaindex703;  slog::Index** eval_argsdelta704;  slog::Index** appdelta705;  slog::Index** evaldelta706;  slog::Index** tickdelta707;  slog::Index** tick_ansdelta708;  slog::Index** closuredelta709;  slog::Index** freevardelta710;  slog::Index** bindingdelta711;  slog::Index** lambdadelta712;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord714({0, 1, 2});
      slog::Relation* readrel715 = db->getRelation("binding");
      head_index[0] = readrel715->getIndex(ord714, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord716({0, 1, 2});
      slog::Relation* readrel717 = db->getRelation("binding_event");
      head_index[1] = readrel717->getIndex(ord716, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord718({0, 2, 1});
      slog::Relation* readrel719 = db->getRelation("eval_args");
      eval_argsindex686 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({0, 2, 1});
      slog::Relation* readrel721 = db->getRelation("eval_args");
      eval_argsdelta704 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({2, 0, 1});
      slog::Relation* readrel723 = db->getRelation("app");
      appindex687 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({2, 0, 1});
      slog::Relation* readrel725 = db->getRelation("eval");
      evalindex688 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({2, 0, 1});
      slog::Relation* readrel727 = db->getRelation("tick");
      tickindex689 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({2, 0, 1});
      slog::Relation* readrel729 = db->getRelation("eval");
      evalindex690 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 0});
      slog::Relation* readrel731 = db->getRelation("tick");
      tickindex691 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({2, 0, 1});
      slog::Relation* readrel733 = db->getRelation("app");
      appindex692 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({2, 0, 1});
      slog::Relation* readrel735 = db->getRelation("app");
      appdelta705 = readrel735->getIndex(ord734, true);
      std::vector<u16> ord736({1, 2, 0});
      slog::Relation* readrel737 = db->getRelation("eval");
      evalindex693 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 2, 0});
      slog::Relation* readrel739 = db->getRelation("eval");
      evaldelta706 = readrel739->getIndex(ord738, true);
      std::vector<u16> ord740({0, 1});
      slog::Relation* readrel741 = db->getRelation("eval_ans");
      eval_ansindex694 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("tick");
      tickindex695 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 2, 0});
      slog::Relation* readrel745 = db->getRelation("tick");
      tickdelta707 = readrel745->getIndex(ord744, true);
      std::vector<u16> ord746({0, 1});
      slog::Relation* readrel747 = db->getRelation("tick_ans");
      tick_ansindex696 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({0, 1});
      slog::Relation* readrel749 = db->getRelation("eval_ans");
      eval_ansindex697 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({0, 1});
      slog::Relation* readrel751 = db->getRelation("tick_ans");
      tick_ansindex698 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({0, 1});
      slog::Relation* readrel753 = db->getRelation("tick_ans");
      tick_ansdelta708 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({0, 1, 2});
      slog::Relation* readrel755 = db->getRelation("closure");
      closureindex699 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("closure");
      closuredelta709 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({1, 0, 2});
      slog::Relation* readrel759 = db->getRelation("binding");
      bindingindex700 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0});
      slog::Relation* readrel761 = db->getRelation("freevar");
      freevarindex701 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0});
      slog::Relation* readrel763 = db->getRelation("freevar");
      freevardelta710 = readrel763->getIndex(ord762, true);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("binding");
      bindingindex702 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("binding");
      bindingdelta711 = readrel767->getIndex(ord766, true);
      std::vector<u16> ord768({0, 1, 2});
      slog::Relation* readrel769 = db->getRelation("lambda");
      lambdaindex703 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1, 2});
      slog::Relation* readrel771 = db->getRelation("lambda");
      lambdadelta712 = readrel771->getIndex(ord770, true);
  
    }
    ReadTask713(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c112 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex686, eval_argsdelta704, std::array<u64,3>{v_c112, 0, 0}, [&](const std::array<u64,3>& m772) {
          u64 v_c3 = m772[1]; u64 v_c2 = m772[2];
          if (!slog::exists_probe<3,1>(appindex687, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex688, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex689, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<3,1>(evalindex690, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m773) {
            u64 v_c113 = m773[1]; u64 v_c114 = m773[2];
            if (!slog::exists_probe<3,2>(tickindex691, std::array<u64,3>{v_c114, v_c3, 0})) return;
            slog::join_probe_old<3,2>(appindex692, appdelta705, std::array<u64,3>{v_c2, v_c114, 0}, [&](const std::array<u64,3>& m774) {
              u64 v_c1 = m774[2];
              slog::join_probe_old<3,2>(evalindex693, evaldelta706, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m775) {
                u64 v_c115 = m775[2];
                if (!slog::exists_probe<2,1>(eval_ansindex694, std::array<u64,2>{v_c115, 0})) return;
                slog::join_probe_old<3,2>(tickindex695, tickdelta707, std::array<u64,3>{v_c114, v_c3, 0}, [&](const std::array<u64,3>& m776) {
                  u64 v_c116 = m776[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex696, std::array<u64,2>{v_c116, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex697, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m777) {
                    u64 v_c117 = m777[1];
                    slog::join_probe_old<2,1>(tick_ansindex698, tick_ansdelta708, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m778) {
                      u64 v_c14 = m778[1];
                      slog::join_probe_old<3,1>(closureindex699, closuredelta709, std::array<u64,3>{v_c117, 0, 0}, [&](const std::array<u64,3>& m779) {
                        u64 v_c118 = m779[1]; u64 v_c7 = m779[2];
                        if (!slog::exists_probe<3,1>(bindingindex700, std::array<u64,3>{v_c7, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex701, freevardelta710, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m780) {
                          u64 v_c5 = m780[1];
                          slog::join_probe_old<3,2>(bindingindex702, bindingdelta711, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m781) {
                            u64 v_c8 = m781[2];
                            slog::join_probe_old<3,1>(lambdaindex703, lambdadelta712, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m782) {
                              u64 v_c9 = m782[1]; u64 v_c10 = m782[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c14, v_c8}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c14, v_c3}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask713* _cont = new ReadTask713(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask713(db,b), false);
  // (crule (pre) (scan app __t3qv3128 ef es) (body (join eval (1 2 0) 1 __t3qv3128 c __3Nvs603)) (head (mkstruct tick (1 2 0) __4klm604 __t3qv3128 c)) analysis.slog:11 #f)
  class ReadTask784 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex783;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord785({1, 2, 0});
      slog::Relation* readrel786 = db->getRelation("eval");
      evalindex783 = readrel786->getIndex(ord785, false);
  
    }
    ReadTask784(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c119 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(evalindex783, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m787) {
          u64 v_c3 = m787[1]; u64 v_c120 = m787[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c119, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:11", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask784* _cont = new ReadTask784(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask784(db,b), false);
  // (crule (pre) (scan eval_args_ans __t2Zls334 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t2Zls334 c es) (exists eval (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __d0 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3Egw332) (join eval_ans (0 1) 1 __t3Egw332 __t68RF333) (join-old prim (0 1) 1 (0 1) __t68RF333 op)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask797 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex788;  slog::Index** evalindex789;  slog::Index** $sup56712x74x0x0x0index790;  slog::Index** evalindex791;  slog::Index** eval_ansindex792;  slog::Index** primindex793;  slog::Index** eval_argsdelta794;  slog::Index** evaldelta795;  slog::Index** primdelta796;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord798({0, 2, 1});
      slog::Relation* readrel799 = db->getRelation("eval_args");
      eval_argsindex788 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({0, 2, 1});
      slog::Relation* readrel801 = db->getRelation("eval_args");
      eval_argsdelta794 = readrel801->getIndex(ord800, true);
      std::vector<u16> ord802({2, 0, 1});
      slog::Relation* readrel803 = db->getRelation("eval");
      evalindex789 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 3, 0, 2});
      slog::Relation* readrel805 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index790 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("eval");
      evalindex791 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("eval");
      evaldelta795 = readrel809->getIndex(ord808, true);
      std::vector<u16> ord810({0, 1});
      slog::Relation* readrel811 = db->getRelation("eval_ans");
      eval_ansindex792 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("prim");
      primindex793 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 1});
      slog::Relation* readrel815 = db->getRelation("prim");
      primdelta796 = readrel815->getIndex(ord814, true);
  
    }
    ReadTask797(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex788, eval_argsdelta794, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m816) {
          u64 v_c3 = m816[1]; u64 v_c2 = m816[2];
          if (!slog::exists_probe<3,1>(evalindex789, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x74x0x0x0index790, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m817) {
            u64 v_c50 = m817[2]; u64 v_c1 = m817[3];
            slog::join_probe_old<3,2>(evalindex791, evaldelta795, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m818) {
              u64 v_c122 = m818[2];
              slog::join_probe<2,1>(eval_ansindex792, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m819) {
                u64 v_c123 = m819[1];
                slog::join_probe_old<2,1>(primindex793, primdelta796, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m820) {
                  u64 v_c62 = m820[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c62, v_c18}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval_args_ans", _fires);
  
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
  // (crule (pre (let __trid0PM0646 const25f568921d120de09a5f575d) (let __trel9qwD647 const4a59dbb9cb3129dfcc75170b) (let __tcol6P6H648 const5feceb66ffc86f38d952786c) (let __trel9gdD649 const4a59dbb9cb3129dfcc75170b) (let __tcol1rF0650 const6b86b273ff34fce19d6b804e)) (scan $sup56712x91x0x0x0 __d0 c eb er x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid0PM0646 __trel9qwD647 __tcol6P6H648 (1 2 3 4 0)) (tycheck c (accept seq) __trid0PM0646 __trel9gdD649 __tcol1rF0650 (1 2 3 4 0)) (mkstruct eval (1 2 0) __519r645 eb c)) interp.slog:92 #f)
  class ReadTask830 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid821;  u32 sid822;  u32 sid823;  u32 sid824;  u32 sid825;  u32 sid826;  u32 sid827;  u32 sid828;  u32 sid829;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      sid821 = db->getRelation("app")->getStructId();
      sid822 = db->getRelation("boolean")->getStructId();
      sid823 = db->getRelation("if")->getStructId();
      sid824 = db->getRelation("lambda")->getStructId();
      sid825 = db->getRelation("let")->getStructId();
      sid826 = db->getRelation("letrec")->getStructId();
      sid827 = db->getRelation("num")->getStructId();
      sid828 = db->getRelation("ref")->getStructId();
      sid829 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask830(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_const25f568921d120de09a5f575d;
      u64 v_c125 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c50 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c22 = _t[4];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid821 || decode_struct_id(v_c10) == sid822 || decode_struct_id(v_c10) == sid823 || decode_struct_id(v_c10) == sid824 || decode_struct_id(v_c10) == sid825 || decode_struct_id(v_c10) == sid826 || decode_struct_id(v_c10) == sid827 || decode_struct_id(v_c10) == sid828 || decode_struct_id(v_c10) == sid829))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c124, v_c125, v_c126, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c124, v_c127, v_c128, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c10, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:$sup56712x91x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask830* _cont = new ReadTask830(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask830(db,b), false);
  // (crule (pre) (scan temp6hC5862 __t7u4837 x) (body (join prim (1 0) 1 x __t7M6E36)) (head (emit lookup_ans (0 1) __t7u4837 __t7M6E36)) interp.slog:33 #f)
  class ReadTask832 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex831;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord833({0, 1});
      slog::Relation* readrel834 = db->getRelation("lookup_ans");
      head_index[0] = readrel834->getIndex(ord833, false);
      outer_rel = db->getRelation("temp6hC5862");
      std::vector<u16> ord835({1, 0});
      slog::Relation* readrel836 = db->getRelation("prim");
      primindex831 = readrel836->getIndex(ord835, false);
  
    }
    ReadTask832(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c129 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe<2,1>(primindex831, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m837) {
          u64 v_c130 = m837[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c130}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:temp6hC5862", _fires);
  
      if (!_done)
      {
        ReadTask832* _cont = new ReadTask832(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask832(db,b), false);
  // (crule (pre) (scan eval_args_ans __t3FCg173 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t3FCg173 c es) (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __d0 ef) (exists app (1 2 0) 2 ef es) (join-old eval (1 2 0) 2 (1 2 0) ef c __t66Yt170) (exists eval_ans (0 1) 1 __t66Yt170) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join-old tick_ans (0 1) 1 (0 1) __t9uJP175 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t8UWw172 __t3anZ171 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask860 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex838;  slog::Index** evalindex839;  slog::Index** appindex840;  slog::Index** tickindex841;  slog::Index** $sup56712x41x0x0x0index842;  slog::Index** appindex843;  slog::Index** evalindex844;  slog::Index** eval_ansindex845;  slog::Index** appindex846;  slog::Index** tickindex847;  slog::Index** tick_ansindex848;  slog::Index** eval_ansindex849;  slog::Index** tick_ansindex850;  slog::Index** closureindex851;  slog::Index** lambdaindex852;  slog::Index** eval_argsdelta853;  slog::Index** evaldelta854;  slog::Index** appdelta855;  slog::Index** tickdelta856;  slog::Index** tick_ansdelta857;  slog::Index** closuredelta858;  slog::Index** lambdadelta859;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord861({0, 2, 1});
      slog::Relation* readrel862 = db->getRelation("eval_args");
      eval_argsindex838 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({0, 2, 1});
      slog::Relation* readrel864 = db->getRelation("eval_args");
      eval_argsdelta853 = readrel864->getIndex(ord863, true);
      std::vector<u16> ord865({2, 0, 1});
      slog::Relation* readrel866 = db->getRelation("eval");
      evalindex839 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({2, 0, 1});
      slog::Relation* readrel868 = db->getRelation("app");
      appindex840 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({2, 0, 1});
      slog::Relation* readrel870 = db->getRelation("tick");
      tickindex841 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 3, 0, 2});
      slog::Relation* readrel872 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index842 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("app");
      appindex843 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("eval");
      evalindex844 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("eval");
      evaldelta854 = readrel878->getIndex(ord877, true);
      std::vector<u16> ord879({0, 1});
      slog::Relation* readrel880 = db->getRelation("eval_ans");
      eval_ansindex845 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 0});
      slog::Relation* readrel882 = db->getRelation("app");
      appindex846 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("app");
      appdelta855 = readrel884->getIndex(ord883, true);
      std::vector<u16> ord885({1, 2, 0});
      slog::Relation* readrel886 = db->getRelation("tick");
      tickindex847 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("tick");
      tickdelta856 = readrel888->getIndex(ord887, true);
      std::vector<u16> ord889({0, 1});
      slog::Relation* readrel890 = db->getRelation("tick_ans");
      tick_ansindex848 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("eval_ans");
      eval_ansindex849 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({0, 1});
      slog::Relation* readrel894 = db->getRelation("tick_ans");
      tick_ansindex850 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({0, 1});
      slog::Relation* readrel896 = db->getRelation("tick_ans");
      tick_ansdelta857 = readrel896->getIndex(ord895, true);
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("closure");
      closureindex851 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({0, 1, 2});
      slog::Relation* readrel900 = db->getRelation("closure");
      closuredelta858 = readrel900->getIndex(ord899, true);
      std::vector<u16> ord901({0, 1, 2});
      slog::Relation* readrel902 = db->getRelation("lambda");
      lambdaindex852 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({0, 1, 2});
      slog::Relation* readrel904 = db->getRelation("lambda");
      lambdadelta859 = readrel904->getIndex(ord903, true);
  
    }
    ReadTask860(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c131 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex838, eval_argsdelta853, std::array<u64,3>{v_c131, 0, 0}, [&](const std::array<u64,3>& m905) {
          u64 v_c3 = m905[1]; u64 v_c2 = m905[2];
          if (!slog::exists_probe<3,1>(evalindex839, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex840, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex841, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index842, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m906) {
            u64 v_c50 = m906[2]; u64 v_c1 = m906[3];
            if (!slog::exists_probe<3,2>(appindex843, std::array<u64,3>{v_c1, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex844, evaldelta854, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m907) {
              u64 v_c132 = m907[2];
              if (!slog::exists_probe<2,1>(eval_ansindex845, std::array<u64,2>{v_c132, 0})) return;
              slog::join_probe_old<3,2>(appindex846, appdelta855, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m908) {
                u64 v_c133 = m908[2];
                slog::join_probe_old<3,2>(tickindex847, tickdelta856, std::array<u64,3>{v_c133, v_c3, 0}, [&](const std::array<u64,3>& m909) {
                  u64 v_c134 = m909[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex848, std::array<u64,2>{v_c134, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex849, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m910) {
                    u64 v_c135 = m910[1];
                    slog::join_probe_old<2,1>(tick_ansindex850, tick_ansdelta857, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m911) {
                      u64 v_c24 = m911[1];
                      slog::join_probe_old<3,1>(closureindex851, closuredelta858, std::array<u64,3>{v_c135, 0, 0}, [&](const std::array<u64,3>& m912) {
                        u64 v_c136 = m912[1]; u64 v_c7 = m912[2];
                        slog::join_probe_old<3,1>(lambdaindex852, lambdadelta859, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m913) {
                          u64 v_c9 = m913[1]; u64 v_c10 = m913[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c24}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask860* _cont = new ReadTask860(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask860(db,b), false);
  // (crule (pre) (scan temp6lH41011 __t43VN150 x) (body) (head (emit freevar_in_args (1 0) __t43VN150 x)) freevars.slog:35 #f)
  class ReadTask914 : public slog::Task
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
      head_rel[0] = db->getRelation("freevar_in_args");
      std::vector<u16> ord915({1, 0});
      slog::Relation* readrel916 = db->getRelation("freevar_in_args");
      head_index[0] = readrel916->getIndex(ord915, false);
      outer_rel = db->getRelation("temp6lH41011");
  
    }
    ReadTask914(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[0];
        u64 v_c22 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c137, v_c22}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp6lH41011", _fires);
  
      if (!_done)
      {
        ReadTask914* _cont = new ReadTask914(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask914(db,b), false);
  // (crule (pre) (scan prim __t22Li389 op) (body (exists delta (1 2 0) 1 op) (join eval_ans (1 0) 1 __t22Li389 __t9EYC388) (join eval (0 2 1) 1 __t9EYC388 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __t0zOO387) (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval_args (1 2 0) 2 es c) (join app (1 2 0) 2 ef es __t2JOw386) (join eval (0 2 1) 3 __t0zOO387 c __t2JOw386) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask934 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex917;  slog::Index** eval_ansindex918;  slog::Index** evalindex919;  slog::Index** appindex920;  slog::Index** evalindex921;  slog::Index** eval_argsindex922;  slog::Index** $sup56712x74x0x0x0index923;  slog::Index** evalindex924;  slog::Index** eval_argsindex925;  slog::Index** appindex926;  slog::Index** evalindex927;  slog::Index** eval_argsindex928;  slog::Index** eval_args_ansindex929;  slog::Index** deltaindex930;  slog::Index** delta_ansindex931;  slog::Index** eval_argsdelta932;  slog::Index** deltadelta933;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord935({0, 1});
      slog::Relation* readrel936 = db->getRelation("eval_ans");
      head_index[0] = readrel936->getIndex(ord935, false);
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord937({1, 2, 0});
      slog::Relation* readrel938 = db->getRelation("delta");
      deltaindex917 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 0});
      slog::Relation* readrel940 = db->getRelation("eval_ans");
      eval_ansindex918 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({0, 2, 1});
      slog::Relation* readrel942 = db->getRelation("eval");
      evalindex919 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 0});
      slog::Relation* readrel944 = db->getRelation("app");
      appindex920 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({2, 0, 1});
      slog::Relation* readrel946 = db->getRelation("eval");
      evalindex921 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({2, 0, 1});
      slog::Relation* readrel948 = db->getRelation("eval_args");
      eval_argsindex922 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 3, 0});
      slog::Relation* readrel950 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index923 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({0, 2, 1});
      slog::Relation* readrel952 = db->getRelation("eval");
      evalindex924 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 2, 0});
      slog::Relation* readrel954 = db->getRelation("eval_args");
      eval_argsindex925 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("app");
      appindex926 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({0, 2, 1});
      slog::Relation* readrel958 = db->getRelation("eval");
      evalindex927 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("eval_args");
      eval_argsindex928 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("eval_args");
      eval_argsdelta932 = readrel962->getIndex(ord961, true);
      std::vector<u16> ord963({0, 1});
      slog::Relation* readrel964 = db->getRelation("eval_args_ans");
      eval_args_ansindex929 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 2, 0});
      slog::Relation* readrel966 = db->getRelation("delta");
      deltaindex930 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 2, 0});
      slog::Relation* readrel968 = db->getRelation("delta");
      deltadelta933 = readrel968->getIndex(ord967, true);
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("delta_ans");
      delta_ansindex931 = readrel970->getIndex(ord969, false);
  
    }
    ReadTask934(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,1>(deltaindex917, std::array<u64,3>{v_c62, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex918, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m971) {
          u64 v_c60 = m971[1];
          slog::join_probe<3,1>(evalindex919, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m972) {
            u64 v_c3 = m972[1]; u64 v_c1 = m972[2];
            if (!slog::exists_probe<3,1>(appindex920, std::array<u64,3>{v_c1, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex921, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex922, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index923, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m973) {
              u64 v_c2 = m973[2]; u64 v_c58 = m973[3];
              if (!slog::exists_probe<3,2>(evalindex924, std::array<u64,3>{v_c58, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex925, std::array<u64,3>{v_c2, v_c3, 0})) return;
              slog::join_probe<3,2>(appindex926, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m974) {
                u64 v_c59 = m974[2];
                slog::join_probe<3,3>(evalindex927, std::array<u64,3>{v_c58, v_c3, v_c59}, [&](const std::array<u64,3>& m975) {
                  slog::join_probe_old<3,2>(eval_argsindex928, eval_argsdelta932, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m976) {
                    u64 v_c57 = m976[2];
                    slog::join_probe<2,1>(eval_args_ansindex929, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m977) {
                      u64 v_c18 = m977[1];
                      slog::join_probe_old<3,2>(deltaindex930, deltadelta933, std::array<u64,3>{v_c62, v_c18, 0}, [&](const std::array<u64,3>& m978) {
                        u64 v_c63 = m978[2];
                        slog::join_probe<2,1>(delta_ansindex931, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m979) {
                          u64 v_c64 = m979[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c64}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:prim", _fires);
  
      if (!_done)
      {
        ReadTask934* _cont = new ReadTask934(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask934(db,b), false);
  // (crule (pre) (scan temp4QUn868 __t2WEx65 __t8vFN64) (body) (head (emit eval_args_ans (0 1) __t2WEx65 __t8vFN64)) interp.slog:37 #f)
  class ReadTask980 : public slog::Task
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
      std::vector<u16> ord981({0, 1});
      slog::Relation* readrel982 = db->getRelation("eval_args_ans");
      head_index[0] = readrel982->getIndex(ord981, false);
      outer_rel = db->getRelation("temp4QUn868");
  
    }
    ReadTask980(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c138 = _t[0];
        u64 v_c139 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c138, v_c139}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:37", "delta:temp4QUn868", _fires);
  
      if (!_done)
      {
        ReadTask980* _cont = new ReadTask980(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask980(db,b), false);
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2Vbm442 __t9eYl306 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo16uv440 __t9eYl306 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3GRa441 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8B0L443 __t9eYl306 _00024seq2) (exists _enum (1 0) 1 __tconst0flI607) (join delta (1 2 0) 2 __tconst2Cp4303 _00024seq2 __t2i9A304) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join boolval (0 1) 1 __t9eYl306 b) (letp _00024sql7hRC435 (aslst _00024seq2)) (let chk0Rwo1025 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk0Rwo1025) (letp chk1zDE1026 (lref _00024sql7hRC435 _00024sqc91nv438)) (eq __t9eYl306 chk1zDE1026) (letp chk6N3P1027 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk6N3P1027)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask991 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex983;  slog::Index** $seq_atindex984;  slog::Index** $seq_atrindex985;  slog::Index** _enumindex986;  slog::Index** deltaindex987;  slog::Index** _enumindex988;  slog::Index** boolvalindex989;  slog::Index** $seq_atrdelta990;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord992({1, 0, 2});
      slog::Relation* readrel993 = db->getRelation("$seq_atr");
      driver_index = readrel993->getIndex(ord992, true);
      std::vector<u16> ord994({1, 0, 2});
      slog::Relation* readrel995 = db->getRelation("$seq_at");
      $seq_atindex983 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({1, 0, 2});
      slog::Relation* readrel997 = db->getRelation("$seq_at");
      $seq_atindex984 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 0, 2});
      slog::Relation* readrel999 = db->getRelation("$seq_atr");
      $seq_atrindex985 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 0, 2});
      slog::Relation* readrel1001 = db->getRelation("$seq_atr");
      $seq_atrdelta990 = readrel1001->getIndex(ord1000, true);
      std::vector<u16> ord1002({1, 0});
      slog::Relation* readrel1003 = db->getRelation("_enum");
      _enumindex986 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({1, 2, 0});
      slog::Relation* readrel1005 = db->getRelation("delta");
      deltaindex987 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({1, 0});
      slog::Relation* readrel1007 = db->getRelation("_enum");
      _enumindex988 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({0, 1});
      slog::Relation* readrel1009 = db->getRelation("boolval");
      boolvalindex989 = readrel1009->getIndex(ord1008, false);
  
    }
    ReadTask991(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c141 = v_const06abaa100ecef791ce028c56;
      u64 v_c142 = v_constd4735e3a265e16eee03f5971;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
      u64 v_c144 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c145 = v_const5feceb66ffc86f38d952786c;
      u64 v_c146 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c147, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1010) {
        u64 v_c149 = m1010[1];
        u64 v_c34 = m1010[2];
        if (buckethash(v_c149) != bucket) return;
        slog::join_probe<3,3>($seq_atindex983, std::array<u64,3>{v_c145, v_c149, v_c34}, [&](const std::array<u64,3>& m1011) {
          slog::join_probe<3,3>($seq_atindex984, std::array<u64,3>{v_c146, v_c149, v_c34}, [&](const std::array<u64,3>& m1012) {
            slog::join_probe_old<3,3>($seq_atrindex985, $seq_atrdelta990, std::array<u64,3>{v_c148, v_c149, v_c34}, [&](const std::array<u64,3>& m1013) {
              if (!slog::exists_probe<2,1>(_enumindex986, std::array<u64,2>{v_c140, 0})) return;
              slog::join_probe<3,2>(deltaindex987, std::array<u64,3>{v_c141, v_c34, 0}, [&](const std::array<u64,3>& m1014) {
                u64 v_c150 = m1014[2];
                slog::join_probe<2,1>(_enumindex988, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m1015) {
                  u64 v_c151 = m1015[1];
                  slog::join_probe<2,1>(boolvalindex989, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1016) {
                    u64 v_c38 = m1016[1];
                    bool ok1017 = true;
                    u64 v_c152 = _prim_aslst(db, v_c34, &ok1017);
                    if (!ok1017) return;
                    u64 v_c153 = _prim_llen(db, v_c152);
                    if (v_c153 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c142 != v_c153) return;
                    bool ok1018 = true;
                    u64 v_c154 = _prim_lref(db, v_c152, v_c143, &ok1018);
                    if (!ok1018) return;
                    if (v_c149 != v_c154) return;
                    bool ok1019 = true;
                    u64 v_c155 = _prim_lref(db, v_c152, v_c144, &ok1019);
                    if (!ok1019) return;
                    if (v_c149 != v_c155) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c150});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c151}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask991* _cont = new ReadTask991(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask991(db,b), false);
  // (crule (pre) (scan temp1iok1031 c ef es) (body (join app (1 2 0) 2 ef es __t9umL4)) (head (mkstruct tick (1 2 0) __92oJ619 __t9umL4 c)) interp.slog:42 #f)
  class ReadTask1021 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1020;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("temp1iok1031");
      std::vector<u16> ord1022({1, 2, 0});
      slog::Relation* readrel1023 = db->getRelation("app");
      appindex1020 = readrel1023->getIndex(ord1022, false);
  
    }
    ReadTask1021(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(appindex1020, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m1024) {
          u64 v_c156 = m1024[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c156, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:temp1iok1031", _fires);
  
      if (!_done)
      {
        ReadTask1021* _cont = new ReadTask1021(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1021(db,b), false);
  // (crule (pre (let __tconst4znW669 constcd2a69ce5ca278db1d6da969) (let _00024sqc3H5i520 constd4735e3a265e16eee03f5971) (let _00024sqc4tob521 const5feceb66ffc86f38d952786c) (let _00024sqc5Dhg522 const6b86b273ff34fce19d6b804e) (let _00024sqo4wSo523 const5feceb66ffc86f38d952786c) (let _00024sqo3X5o524 const6b86b273ff34fce19d6b804e) (let _00024sqo10Lc525 const6b86b273ff34fce19d6b804e) (let _00024sqo1tMi526 const5feceb66ffc86f38d952786c) (let __trid6dum670 consteefaed435882b14b69e99d78) (let __trel5mCG671 constdede4476644eb06b5a48b866) (let __tcol9ZQn672 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo4wSo523 __t5cN641 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3X5o524 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo10Lc525 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1tMi526 __t5cN641 _00024seq2) (join _enum (0 1) 2 __t5cN641 __tconst4znW669) (join delta (2 0 1) 1 _00024seq2 __t2MSw39 op) (join arithmetic_op (0) 1 op) (letp _00024sql8wbR518 (aslst _00024seq2)) (let chk9g0G900 (llen _00024sql8wbR518)) (eq _00024sqc3H5i520 chk9g0G900) (letp chk2x2k901 (lref _00024sql8wbR518 _00024sqc4tob521)) (eq __t5cN641 chk2x2k901) (letp chk749m902 (lref _00024sql8wbR518 _00024sqc5Dhg522)) (eq __t5cN641 chk749m902)) (head (tycheck __t5cN641 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid6dum670 __trel5mCG671 __tcol9ZQn672 (1 2 3 4 0)) (emit delta_ans (0 1) __t2MSw39 __t5cN641)) interp.slog:111 #f)
  class ReadTask1039 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1025;  slog::Index** $seq_atrindex1026;  slog::Index** $seq_atrindex1027;  slog::Index** _enumindex1028;  slog::Index** deltaindex1029;  slog::Index** arithmetic_opindex1030;  slog::Index** $seq_atdelta1031;  slog::Index** $seq_atrdelta1032;  slog::Index** $seq_atrdelta1033;
    u32 sid1036;  u32 sid1034;  u32 sid1035;  u32 sid1037;  u32 sid1038;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1040({0, 1});
      slog::Relation* readrel1041 = db->getRelation("delta_ans");
      head_index[1] = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 0, 2});
      slog::Relation* readrel1043 = db->getRelation("$seq_at");
      driver_index = readrel1043->getIndex(ord1042, true);
      std::vector<u16> ord1044({1, 0, 2});
      slog::Relation* readrel1045 = db->getRelation("$seq_at");
      $seq_atindex1025 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 0, 2});
      slog::Relation* readrel1047 = db->getRelation("$seq_at");
      $seq_atdelta1031 = readrel1047->getIndex(ord1046, true);
      std::vector<u16> ord1048({1, 0, 2});
      slog::Relation* readrel1049 = db->getRelation("$seq_atr");
      $seq_atrindex1026 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 0, 2});
      slog::Relation* readrel1051 = db->getRelation("$seq_atr");
      $seq_atrdelta1032 = readrel1051->getIndex(ord1050, true);
      std::vector<u16> ord1052({1, 0, 2});
      slog::Relation* readrel1053 = db->getRelation("$seq_atr");
      $seq_atrindex1027 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 0, 2});
      slog::Relation* readrel1055 = db->getRelation("$seq_atr");
      $seq_atrdelta1033 = readrel1055->getIndex(ord1054, true);
      std::vector<u16> ord1056({0, 1});
      slog::Relation* readrel1057 = db->getRelation("_enum");
      _enumindex1028 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({2, 0, 1});
      slog::Relation* readrel1059 = db->getRelation("delta");
      deltaindex1029 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({0});
      slog::Relation* readrel1061 = db->getRelation("arithmetic_op");
      arithmetic_opindex1030 = readrel1061->getIndex(ord1060, false);
      sid1036 = db->getRelation("_enum")->getStructId();
      sid1034 = db->getRelation("boolval")->getStructId();
      sid1035 = db->getRelation("closure")->getStructId();
      sid1037 = db->getRelation("prim")->getStructId();
      sid1038 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1039(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c158 = v_constd4735e3a265e16eee03f5971;
      u64 v_c159 = v_const5feceb66ffc86f38d952786c;
      u64 v_c160 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c161 = v_const5feceb66ffc86f38d952786c;
      u64 v_c162 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
      u64 v_c165 = v_consteefaed435882b14b69e99d78;
      u64 v_c166 = v_constdede4476644eb06b5a48b866;
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c161, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1062) {
        u64 v_c168 = m1062[1];
        u64 v_c34 = m1062[2];
        if (buckethash(v_c168) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1025, $seq_atdelta1031, std::array<u64,3>{v_c162, v_c168, v_c34}, [&](const std::array<u64,3>& m1063) {
          slog::join_probe_old<3,3>($seq_atrindex1026, $seq_atrdelta1032, std::array<u64,3>{v_c163, v_c168, v_c34}, [&](const std::array<u64,3>& m1064) {
            slog::join_probe_old<3,3>($seq_atrindex1027, $seq_atrdelta1033, std::array<u64,3>{v_c164, v_c168, v_c34}, [&](const std::array<u64,3>& m1065) {
              slog::join_probe<2,2>(_enumindex1028, std::array<u64,2>{v_c168, v_c157}, [&](const std::array<u64,2>& m1066) {
                slog::join_probe<3,1>(deltaindex1029, std::array<u64,3>{v_c34, 0, 0}, [&](const std::array<u64,3>& m1067) {
                  u64 v_c169 = m1067[1]; u64 v_c62 = m1067[2];
                  slog::join_probe<1,1>(arithmetic_opindex1030, std::array<u64,1>{v_c62}, [&](const std::array<u64,1>& m1068) {
                    bool ok1069 = true;
                    u64 v_c170 = _prim_aslst(db, v_c34, &ok1069);
                    if (!ok1069) return;
                    u64 v_c171 = _prim_llen(db, v_c170);
                    if (v_c171 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c158 != v_c171) return;
                    bool ok1070 = true;
                    u64 v_c172 = _prim_lref(db, v_c170, v_c159, &ok1070);
                    if (!ok1070) return;
                    if (v_c168 != v_c172) return;
                    bool ok1071 = true;
                    u64 v_c173 = _prim_lref(db, v_c170, v_c160, &ok1071);
                    if (!ok1071) return;
                    if (v_c168 != v_c173) return;
                    ++_fires;
                    if (!((is_struct(v_c168) && (decode_struct_id(v_c168) == sid1034 || decode_struct_id(v_c168) == sid1035 || decode_struct_id(v_c168) == sid1036 || decode_struct_id(v_c168) == sid1037 || decode_struct_id(v_c168) == sid1038))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c165, v_c166, v_c167, v_c168}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c169, v_c168}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1039* _cont = new ReadTask1039(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1039(db,b), false);
  // (crule (pre) (scan eval __88TM561 __t4vf0113 c) (body (join-old app (0 1 2) 1 (0 1 2) __t4vf0113 ef es) (join freevar (0 1) 0 y __t8awf114) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t8awf114 xs eb)) (head (mkstruct eval (1 2 0) __7s92562 ef c)) interp.slog:56 #f)
  class ReadTask1077 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1072;  slog::Index** freevarindex1073;  slog::Index** bindingindex1074;  slog::Index** lambdaindex1075;  slog::Index** appdelta1076;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1078({0, 1, 2});
      slog::Relation* readrel1079 = db->getRelation("app");
      appindex1072 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({0, 1, 2});
      slog::Relation* readrel1081 = db->getRelation("app");
      appdelta1076 = readrel1081->getIndex(ord1080, true);
      std::vector<u16> ord1082({0, 1});
      slog::Relation* readrel1083 = db->getRelation("freevar");
      freevarindex1073 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({0, 1, 2});
      slog::Relation* readrel1085 = db->getRelation("binding");
      bindingindex1074 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({0, 1, 2});
      slog::Relation* readrel1087 = db->getRelation("lambda");
      lambdaindex1075 = readrel1087->getIndex(ord1086, false);
  
    }
    ReadTask1077(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe_old<3,1>(appindex1072, appdelta1076, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m1088) {
          u64 v_c1 = m1088[1]; u64 v_c2 = m1088[2];
          slog::join_all<2>(freevarindex1073, [&](const std::array<u64,2>& m1089) {
            u64 v_c5 = m1089[0]; u64 v_c6 = m1089[1];
            slog::join_probe<3,1>(bindingindex1074, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m1090) {
              u64 v_c7 = m1090[1]; u64 v_c8 = m1090[2];
              slog::join_probe<3,1>(lambdaindex1075, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m1091) {
                u64 v_c9 = m1091[1]; u64 v_c10 = m1091[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1077* _cont = new ReadTask1077(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1077(db,b), false);
  // (crule (pre) (scan eval_args __t8cVn323 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (2 0 1) 2 (2 0 1) es __t9nj7324 ef) (join eval (1 2 0) 2 ef c __t550i320) (exists eval_ans (0 1) 1 __t550i320) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join tick_ans (0 1) 1 __t3nAR325 l) (join closure (0 1 2) 1 __t2qAJ322 __t7ycN321 cb) (join lambda (0 1 2) 1 __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1092;  slog::Index** appindex1093;  slog::Index** tickindex1094;  slog::Index** eval_args_ansindex1095;  slog::Index** evalindex1096;  slog::Index** tickindex1097;  slog::Index** appindex1098;  slog::Index** evalindex1099;  slog::Index** eval_ansindex1100;  slog::Index** tickindex1101;  slog::Index** tick_ansindex1102;  slog::Index** eval_ansindex1103;  slog::Index** tick_ansindex1104;  slog::Index** closureindex1105;  slog::Index** lambdaindex1106;  slog::Index** appdelta1107;  slog::Index** tickdelta1108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1110({0, 1, 2, 3});
      slog::Relation* readrel1111 = db->getRelation("bind_params");
      head_index[0] = readrel1111->getIndex(ord1110, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1112({0, 1});
      slog::Relation* readrel1113 = db->getRelation("call_event");
      head_index[1] = readrel1113->getIndex(ord1112, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1114({2, 0, 1});
      slog::Relation* readrel1115 = db->getRelation("eval");
      evalindex1092 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({2, 0, 1});
      slog::Relation* readrel1117 = db->getRelation("app");
      appindex1093 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({2, 0, 1});
      slog::Relation* readrel1119 = db->getRelation("tick");
      tickindex1094 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({0, 1});
      slog::Relation* readrel1121 = db->getRelation("eval_args_ans");
      eval_args_ansindex1095 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({2, 0, 1});
      slog::Relation* readrel1123 = db->getRelation("eval");
      evalindex1096 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 2, 0});
      slog::Relation* readrel1125 = db->getRelation("tick");
      tickindex1097 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({2, 0, 1});
      slog::Relation* readrel1127 = db->getRelation("app");
      appindex1098 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({2, 0, 1});
      slog::Relation* readrel1129 = db->getRelation("app");
      appdelta1107 = readrel1129->getIndex(ord1128, true);
      std::vector<u16> ord1130({1, 2, 0});
      slog::Relation* readrel1131 = db->getRelation("eval");
      evalindex1099 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({0, 1});
      slog::Relation* readrel1133 = db->getRelation("eval_ans");
      eval_ansindex1100 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 2, 0});
      slog::Relation* readrel1135 = db->getRelation("tick");
      tickindex1101 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 2, 0});
      slog::Relation* readrel1137 = db->getRelation("tick");
      tickdelta1108 = readrel1137->getIndex(ord1136, true);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("tick_ans");
      tick_ansindex1102 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({0, 1});
      slog::Relation* readrel1141 = db->getRelation("eval_ans");
      eval_ansindex1103 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({0, 1});
      slog::Relation* readrel1143 = db->getRelation("tick_ans");
      tick_ansindex1104 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({0, 1, 2});
      slog::Relation* readrel1145 = db->getRelation("closure");
      closureindex1105 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({0, 1, 2});
      slog::Relation* readrel1147 = db->getRelation("lambda");
      lambdaindex1106 = readrel1147->getIndex(ord1146, false);
  
    }
    ReadTask1109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1092, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1093, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1094, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex1095, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m1148) {
          u64 v_c18 = m1148[1];
          slog::join_probe<3,1>(evalindex1096, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m1149) {
            u64 v_c13 = m1149[1]; u64 v_c12 = m1149[2];
            if (!slog::exists_probe<3,2>(tickindex1097, std::array<u64,3>{v_c12, v_c3, 0})) return;
            slog::join_probe_old<3,2>(appindex1098, appdelta1107, std::array<u64,3>{v_c2, v_c12, 0}, [&](const std::array<u64,3>& m1150) {
              u64 v_c1 = m1150[2];
              slog::join_probe<3,2>(evalindex1099, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m1151) {
                u64 v_c15 = m1151[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1100, std::array<u64,2>{v_c15, 0})) return;
                slog::join_probe_old<3,2>(tickindex1101, tickdelta1108, std::array<u64,3>{v_c12, v_c3, 0}, [&](const std::array<u64,3>& m1152) {
                  u64 v_c11 = m1152[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1102, std::array<u64,2>{v_c11, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1103, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m1153) {
                    u64 v_c17 = m1153[1];
                    slog::join_probe<2,1>(tick_ansindex1104, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1154) {
                      u64 v_c14 = m1154[1];
                      slog::join_probe<3,1>(closureindex1105, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m1155) {
                        u64 v_c19 = m1155[1]; u64 v_c7 = m1155[2];
                        slog::join_probe<3,1>(lambdaindex1106, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m1156) {
                          u64 v_c9 = m1156[1]; u64 v_c10 = m1156[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c18, v_c14, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c14, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1109* _cont = new ReadTask1109(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1109(db,b), false);
  // (crule (pre (let __trid2Stn596 const781eda039ec10c193395ca07) (let __trel1BzK597 const4a59dbb9cb3129dfcc75170b) (let __tcol0uv3598 const5feceb66ffc86f38d952786c) (let __trel5Ul4599 const4a59dbb9cb3129dfcc75170b) (let __tcol4EE3600 const6b86b273ff34fce19d6b804e)) (scan $sup56712x93x0x0x0 __d0 c eb er x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid2Stn596 __trel1BzK597 __tcol0uv3598 (1 2 3 4 0)) (tycheck c (accept seq) __trid2Stn596 __trel5Ul4599 __tcol4EE3600 (1 2 3 4 0)) (mkstruct eval (1 2 0) __79LP595 eb c)) interp.slog:94 #f)
  class ReadTask1166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1157;  u32 sid1158;  u32 sid1159;  u32 sid1160;  u32 sid1161;  u32 sid1162;  u32 sid1163;  u32 sid1164;  u32 sid1165;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      sid1157 = db->getRelation("app")->getStructId();
      sid1158 = db->getRelation("boolean")->getStructId();
      sid1159 = db->getRelation("if")->getStructId();
      sid1160 = db->getRelation("lambda")->getStructId();
      sid1161 = db->getRelation("let")->getStructId();
      sid1162 = db->getRelation("letrec")->getStructId();
      sid1163 = db->getRelation("num")->getStructId();
      sid1164 = db->getRelation("ref")->getStructId();
      sid1165 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_const781eda039ec10c193395ca07;
      u64 v_c175 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c50 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c22 = _t[4];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid1157 || decode_struct_id(v_c10) == sid1158 || decode_struct_id(v_c10) == sid1159 || decode_struct_id(v_c10) == sid1160 || decode_struct_id(v_c10) == sid1161 || decode_struct_id(v_c10) == sid1162 || decode_struct_id(v_c10) == sid1163 || decode_struct_id(v_c10) == sid1164 || decode_struct_id(v_c10) == sid1165))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c174, v_c175, v_c176, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c174, v_c177, v_c178, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c10, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:$sup56712x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1166* _cont = new ReadTask1166(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1166(db,b), false);
}

