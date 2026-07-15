
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const1fb680aa1ed965bc09f024ab;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5963fd3eff55776ca49412c5;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const781eda039ec10c193395ca07;
extern u64 v_const7902699be42c8a8e46fbbb45;
extern u64 v_const829935b42173b360da35f679;
extern u64 v_const879923da020d1533f4d8e921;
extern u64 v_const8c8656c5d114d7f8b2a412d2;
extern u64 v_const8ca5d81566f88badd698137a;
extern u64 v_const90edba1c9d0bb14ec514a96c;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdcc297bb3300d9549a9d611a;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_constea10b8ee9cd346b11a382114;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_c44d995e97763415a(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp5J1A935 __t1ye1379 __t6vuA378) (body) (head (emit eval_args_ans (0 1) __t1ye1379 __t6vuA378)) interp.slog:38 #f)
  class ReadTask0 : public slog::Task
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
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("eval_args_ans");
      head_index[0] = readrel2->getIndex(ord1, false);
      outer_rel = db->getRelation("temp5J1A935");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c1}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp5J1A935", _fires);
  
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
  // (crule (pre) (scan eval __t8NjM310 eb c) (body (exists letrec (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t8NjM310) (join $sup56712x93x0x0x0 (1 2 0 3 4) 2 c eb __t3Qfa308 er x) (exists eval (0 2 1) 2 __t3Qfa308 c) (exists eval (1 2 0) 2 er c) (join letrec (2 1 3 0) 3 er x eb __t8pF7307) (join eval (0 2 1) 3 __t3Qfa308 c __t8pF7307) (join eval (1 2 0) 2 er c __t8bEj309) (join eval_ans (0 1) 1 __t8bEj309 vr) (join eval_ans (0 1) 1 __t8NjM310 v)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex3;  slog::Index** evalindex4;  slog::Index** eval_ansindex5;  slog::Index** $sup56712x93x0x0x0index6;  slog::Index** evalindex7;  slog::Index** evalindex8;  slog::Index** letrecindex9;  slog::Index** evalindex10;  slog::Index** evalindex11;  slog::Index** eval_ansindex12;  slog::Index** eval_ansindex13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("eval_ans");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord17({3, 0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("letrec");
      letrecindex3 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({2, 0, 1});
      slog::Relation* readrel20 = db->getRelation("eval");
      evalindex4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("eval_ans");
      eval_ansindex5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 2, 0, 3, 4});
      slog::Relation* readrel24 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 2, 1});
      slog::Relation* readrel26 = db->getRelation("eval");
      evalindex7 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("eval");
      evalindex8 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 1, 3, 0});
      slog::Relation* readrel30 = db->getRelation("letrec");
      letrecindex9 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 2, 1});
      slog::Relation* readrel32 = db->getRelation("eval");
      evalindex10 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("eval");
      evalindex11 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("eval_ans");
      eval_ansindex12 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("eval_ans");
      eval_ansindex13 = readrel38->getIndex(ord37, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<4,1>(letrecindex3, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex4, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex5, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index6, std::array<u64,5>{v_c4, v_c3, 0, 0, 0}, [&](const std::array<u64,5>& m39) {
          u64 v_c5 = m39[2]; u64 v_c6 = m39[3]; u64 v_c7 = m39[4];
          if (!slog::exists_probe<3,2>(evalindex7, std::array<u64,3>{v_c5, v_c4, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex8, std::array<u64,3>{v_c6, v_c4, 0})) return;
          slog::join_probe<4,3>(letrecindex9, std::array<u64,4>{v_c6, v_c7, v_c3, 0}, [&](const std::array<u64,4>& m40) {
            u64 v_c8 = m40[3];
            slog::join_probe<3,3>(evalindex10, std::array<u64,3>{v_c5, v_c4, v_c8}, [&](const std::array<u64,3>& m41) {
              slog::join_probe<3,2>(evalindex11, std::array<u64,3>{v_c6, v_c4, 0}, [&](const std::array<u64,3>& m42) {
                u64 v_c9 = m42[2];
                slog::join_probe<2,1>(eval_ansindex12, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m43) {
                  u64 v_c10 = m43[1];
                  slog::join_probe<2,1>(eval_ansindex13, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m44) {
                    u64 v_c11 = m44[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c11}, std::array<u16,2>{0, 1});
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
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre) (scan eval_ans __t66Yt170 __t8UWw172) (body (join-old eval (0 2 1) 1 (0 2 1) __t66Yt170 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join-old eval_args_ans (0 1) 1 (0 1) __t3FCg173 vs) (join-old tick_ans (0 1) 1 (0 1) __t9uJP175 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t8UWw172 __t3anZ171 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask68 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex45;  slog::Index** eval_argsindex46;  slog::Index** appindex47;  slog::Index** tickindex48;  slog::Index** $sup56712x41x0x0x0index49;  slog::Index** appindex50;  slog::Index** eval_argsindex51;  slog::Index** eval_args_ansindex52;  slog::Index** appindex53;  slog::Index** tickindex54;  slog::Index** tick_ansindex55;  slog::Index** eval_args_ansindex56;  slog::Index** tick_ansindex57;  slog::Index** closureindex58;  slog::Index** lambdaindex59;  slog::Index** evaldelta60;  slog::Index** eval_argsdelta61;  slog::Index** appdelta62;  slog::Index** tickdelta63;  slog::Index** eval_args_ansdelta64;  slog::Index** tick_ansdelta65;  slog::Index** closuredelta66;  slog::Index** lambdadelta67;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord69({0, 2, 1});
      slog::Relation* readrel70 = db->getRelation("eval");
      evalindex45 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 2, 1});
      slog::Relation* readrel72 = db->getRelation("eval");
      evaldelta60 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({2, 0, 1});
      slog::Relation* readrel74 = db->getRelation("eval_args");
      eval_argsindex46 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("app");
      appindex47 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({2, 0, 1});
      slog::Relation* readrel78 = db->getRelation("tick");
      tickindex48 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 3, 0});
      slog::Relation* readrel80 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index49 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("app");
      appindex50 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 0});
      slog::Relation* readrel84 = db->getRelation("eval_args");
      eval_argsindex51 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 2, 0});
      slog::Relation* readrel86 = db->getRelation("eval_args");
      eval_argsdelta61 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("eval_args_ans");
      eval_args_ansindex52 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 2, 0});
      slog::Relation* readrel90 = db->getRelation("app");
      appindex53 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 2, 0});
      slog::Relation* readrel92 = db->getRelation("app");
      appdelta62 = readrel92->getIndex(ord91, true);
      std::vector<u16> ord93({1, 2, 0});
      slog::Relation* readrel94 = db->getRelation("tick");
      tickindex54 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 2, 0});
      slog::Relation* readrel96 = db->getRelation("tick");
      tickdelta63 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("tick_ans");
      tick_ansindex55 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 1});
      slog::Relation* readrel100 = db->getRelation("eval_args_ans");
      eval_args_ansindex56 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("eval_args_ans");
      eval_args_ansdelta64 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("tick_ans");
      tick_ansindex57 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("tick_ans");
      tick_ansdelta65 = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({0, 1, 2});
      slog::Relation* readrel108 = db->getRelation("closure");
      closureindex58 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1, 2});
      slog::Relation* readrel110 = db->getRelation("closure");
      closuredelta66 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({0, 1, 2});
      slog::Relation* readrel112 = db->getRelation("lambda");
      lambdaindex59 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 1, 2});
      slog::Relation* readrel114 = db->getRelation("lambda");
      lambdadelta67 = readrel114->getIndex(ord113, true);
  
    }
    ReadTask68(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe_old<3,1>(evalindex45, evaldelta60, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m115) {
          u64 v_c4 = m115[1]; u64 v_c14 = m115[2];
          if (!slog::exists_probe<3,1>(eval_argsindex46, std::array<u64,3>{v_c4, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex47, std::array<u64,3>{v_c14, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex48, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index49, std::array<u64,4>{v_c4, v_c14, 0, 0}, [&](const std::array<u64,4>& m116) {
            u64 v_c15 = m116[2]; u64 v_c16 = m116[3];
            if (!slog::exists_probe<3,2>(appindex50, std::array<u64,3>{v_c14, v_c15, 0})) return;
            slog::join_probe_old<3,2>(eval_argsindex51, eval_argsdelta61, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m117) {
              u64 v_c17 = m117[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex52, std::array<u64,2>{v_c17, 0})) return;
              slog::join_probe_old<3,2>(appindex53, appdelta62, std::array<u64,3>{v_c14, v_c15, 0}, [&](const std::array<u64,3>& m118) {
                u64 v_c18 = m118[2];
                slog::join_probe_old<3,2>(tickindex54, tickdelta63, std::array<u64,3>{v_c18, v_c4, 0}, [&](const std::array<u64,3>& m119) {
                  u64 v_c19 = m119[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex55, std::array<u64,2>{v_c19, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex56, eval_args_ansdelta64, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m120) {
                    u64 v_c20 = m120[1];
                    slog::join_probe_old<2,1>(tick_ansindex57, tick_ansdelta65, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m121) {
                      u64 v_c21 = m121[1];
                      slog::join_probe_old<3,1>(closureindex58, closuredelta66, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m122) {
                        u64 v_c22 = m122[1]; u64 v_c23 = m122[2];
                        slog::join_probe_old<3,1>(lambdaindex59, lambdadelta67, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m123) {
                          u64 v_c24 = m123[1]; u64 v_c3 = m123[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c21}, std::array<u16,3>{1, 2, 0});
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
        ReadTask68* _cont = new ReadTask68(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask68(db,b), false);
  // (crule (pre) (scan eval_args __t3FCg173 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t3FCg173) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __d0 ef) (exists app (1 2 0) 2 ef es) (join eval (1 2 0) 2 ef c __t66Yt170) (exists eval_ans (0 1) 1 __t66Yt170) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join tick_ans (0 1) 1 __t9uJP175 __v0) (join closure (0 1 2) 1 __t8UWw172 __t3anZ171 cb) (join lambda (0 1 2) 1 __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex124;  slog::Index** appindex125;  slog::Index** tickindex126;  slog::Index** eval_args_ansindex127;  slog::Index** $sup56712x41x0x0x0index128;  slog::Index** appindex129;  slog::Index** evalindex130;  slog::Index** eval_ansindex131;  slog::Index** appindex132;  slog::Index** tickindex133;  slog::Index** tick_ansindex134;  slog::Index** eval_ansindex135;  slog::Index** eval_args_ansindex136;  slog::Index** tick_ansindex137;  slog::Index** closureindex138;  slog::Index** lambdaindex139;  slog::Index** appdelta140;  slog::Index** tickdelta141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord143({2, 0, 1});
      slog::Relation* readrel144 = db->getRelation("eval");
      evalindex124 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({2, 0, 1});
      slog::Relation* readrel146 = db->getRelation("app");
      appindex125 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({2, 0, 1});
      slog::Relation* readrel148 = db->getRelation("tick");
      tickindex126 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("eval_args_ans");
      eval_args_ansindex127 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 3, 0, 2});
      slog::Relation* readrel152 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index128 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 0});
      slog::Relation* readrel154 = db->getRelation("app");
      appindex129 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("eval");
      evalindex130 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("eval_ans");
      eval_ansindex131 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("app");
      appindex132 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("app");
      appdelta140 = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("tick");
      tickindex133 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("tick");
      tickdelta141 = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("tick_ans");
      tick_ansindex134 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("eval_ans");
      eval_ansindex135 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("eval_args_ans");
      eval_args_ansindex136 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("tick_ans");
      tick_ansindex137 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1, 2});
      slog::Relation* readrel176 = db->getRelation("closure");
      closureindex138 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1, 2});
      slog::Relation* readrel178 = db->getRelation("lambda");
      lambdaindex139 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex124, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex125, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex126, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex127, std::array<u64,2>{v_c17, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index128, std::array<u64,4>{v_c4, v_c15, 0, 0}, [&](const std::array<u64,4>& m179) {
          u64 v_c16 = m179[2]; u64 v_c14 = m179[3];
          if (!slog::exists_probe<3,2>(appindex129, std::array<u64,3>{v_c14, v_c15, 0})) return;
          slog::join_probe<3,2>(evalindex130, std::array<u64,3>{v_c14, v_c4, 0}, [&](const std::array<u64,3>& m180) {
            u64 v_c12 = m180[2];
            if (!slog::exists_probe<2,1>(eval_ansindex131, std::array<u64,2>{v_c12, 0})) return;
            slog::join_probe_old<3,2>(appindex132, appdelta140, std::array<u64,3>{v_c14, v_c15, 0}, [&](const std::array<u64,3>& m181) {
              u64 v_c18 = m181[2];
              slog::join_probe_old<3,2>(tickindex133, tickdelta141, std::array<u64,3>{v_c18, v_c4, 0}, [&](const std::array<u64,3>& m182) {
                u64 v_c19 = m182[2];
                if (!slog::exists_probe<2,1>(tick_ansindex134, std::array<u64,2>{v_c19, 0})) return;
                slog::join_probe<2,1>(eval_ansindex135, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m183) {
                  u64 v_c13 = m183[1];
                  slog::join_probe<2,1>(eval_args_ansindex136, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m184) {
                    u64 v_c20 = m184[1];
                    slog::join_probe<2,1>(tick_ansindex137, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m185) {
                      u64 v_c21 = m185[1];
                      slog::join_probe<3,1>(closureindex138, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m186) {
                        u64 v_c22 = m186[1]; u64 v_c23 = m186[2];
                        slog::join_probe<3,1>(lambdaindex139, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m187) {
                          u64 v_c24 = m187[1]; u64 v_c3 = m187[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c21}, std::array<u16,3>{1, 2, 0});
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
  // (crule (pre) (scan app __t1DIg130 ef es) (body (join freevar (1 0) 1 ef x)) (head (emit freevar (0 1) x __t1DIg130)) freevars.slog:13 #f)
  class ReadTask189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("freevar");
      head_index[0] = readrel191->getIndex(ord190, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("freevar");
      freevarindex188 = readrel193->getIndex(ord192, false);
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe<2,1>(freevarindex188, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m194) {
          u64 v_c7 = m194[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c25}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask189* _cont = new ReadTask189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask189(db,b), false);
  // (crule (pre) (scan temp9TwZ1009 __t8LOa148 e es x) (body (let __t60vU149 (lpush __t8LOa148 e))) (head (emit-temp temp7olY1010 __t60vU149 es x)) freevars.slog:35 #f)
  class ReadTask195 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7olY1010");
      outer_rel = db->getRelation("temp9TwZ1009");
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c28 = _prim_lpush(db, v_c26, v_c27);
        if (v_c28 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c28, v_c15, v_c7});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp9TwZ1009", _fires);
  
      if (!_done)
      {
        ReadTask195* _cont = new ReadTask195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask195(db,b), false);
  // (crule (pre) (scan app __t0Yvq193 ef es) (body (join eval (1 2 0) 1 __t0Yvq193 c __8Eqi628)) (head (mkstruct eval (1 2 0) __8GR8629 ef c)) analysis.slog:36 #f)
  class ReadTask197 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex196;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord198({1, 2, 0});
      slog::Relation* readrel199 = db->getRelation("eval");
      evalindex196 = readrel199->getIndex(ord198, false);
  
    }
    ReadTask197(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe<3,1>(evalindex196, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m200) {
          u64 v_c4 = m200[1]; u64 v_c30 = m200[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c4}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:36", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask197* _cont = new ReadTask197(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask197(db,b), false);
  // (crule (pre) (scan eval __t84Ji24 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join tick_ans (0 1) 1 __t0NvE30 l) (join-old closure (0 1 2) 1 (0 1 2) __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask225 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex201;  slog::Index** appindex202;  slog::Index** eval_argsindex203;  slog::Index** tickindex204;  slog::Index** eval_ansindex205;  slog::Index** evalindex206;  slog::Index** tickindex207;  slog::Index** appindex208;  slog::Index** eval_argsindex209;  slog::Index** eval_args_ansindex210;  slog::Index** tickindex211;  slog::Index** tick_ansindex212;  slog::Index** eval_args_ansindex213;  slog::Index** tick_ansindex214;  slog::Index** closureindex215;  slog::Index** bindingindex216;  slog::Index** freevarindex217;  slog::Index** bindingindex218;  slog::Index** lambdaindex219;  slog::Index** appdelta220;  slog::Index** eval_argsdelta221;  slog::Index** tickdelta222;  slog::Index** closuredelta223;  slog::Index** lambdadelta224;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord226({0, 1, 2});
      slog::Relation* readrel227 = db->getRelation("binding");
      head_index[0] = readrel227->getIndex(ord226, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord228({0, 1, 2});
      slog::Relation* readrel229 = db->getRelation("binding_event");
      head_index[1] = readrel229->getIndex(ord228, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord230({2, 0, 1});
      slog::Relation* readrel231 = db->getRelation("eval");
      evalindex201 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 2, 0});
      slog::Relation* readrel233 = db->getRelation("app");
      appindex202 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({2, 0, 1});
      slog::Relation* readrel235 = db->getRelation("eval_args");
      eval_argsindex203 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({2, 0, 1});
      slog::Relation* readrel237 = db->getRelation("tick");
      tickindex204 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("eval_ans");
      eval_ansindex205 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({2, 0, 1});
      slog::Relation* readrel241 = db->getRelation("eval");
      evalindex206 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("tick");
      tickindex207 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 1, 2});
      slog::Relation* readrel245 = db->getRelation("app");
      appindex208 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({0, 1, 2});
      slog::Relation* readrel247 = db->getRelation("app");
      appdelta220 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("eval_args");
      eval_argsindex209 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 2, 0});
      slog::Relation* readrel251 = db->getRelation("eval_args");
      eval_argsdelta221 = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("eval_args_ans");
      eval_args_ansindex210 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("tick");
      tickindex211 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("tick");
      tickdelta222 = readrel257->getIndex(ord256, true);
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("tick_ans");
      tick_ansindex212 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("eval_args_ans");
      eval_args_ansindex213 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("tick_ans");
      tick_ansindex214 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({0, 1, 2});
      slog::Relation* readrel265 = db->getRelation("closure");
      closureindex215 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({0, 1, 2});
      slog::Relation* readrel267 = db->getRelation("closure");
      closuredelta223 = readrel267->getIndex(ord266, true);
      std::vector<u16> ord268({1, 0, 2});
      slog::Relation* readrel269 = db->getRelation("binding");
      bindingindex216 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("freevar");
      freevarindex217 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 1, 2});
      slog::Relation* readrel273 = db->getRelation("binding");
      bindingindex218 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0, 1, 2});
      slog::Relation* readrel275 = db->getRelation("lambda");
      lambdaindex219 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1, 2});
      slog::Relation* readrel277 = db->getRelation("lambda");
      lambdadelta224 = readrel277->getIndex(ord276, true);
  
    }
    ReadTask225(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex201, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex202, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex203, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex204, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex205, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m278) {
          u64 v_c32 = m278[1];
          slog::join_probe<3,1>(evalindex206, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m279) {
            u64 v_c33 = m279[1]; u64 v_c34 = m279[2];
            if (!slog::exists_probe<3,2>(tickindex207, std::array<u64,3>{v_c34, v_c4, 0})) return;
            slog::join_probe_old<3,2>(appindex208, appdelta220, std::array<u64,3>{v_c34, v_c14, 0}, [&](const std::array<u64,3>& m280) {
              u64 v_c15 = m280[2];
              slog::join_probe_old<3,2>(eval_argsindex209, eval_argsdelta221, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m281) {
                u64 v_c35 = m281[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex210, std::array<u64,2>{v_c35, 0})) return;
                slog::join_probe_old<3,2>(tickindex211, tickdelta222, std::array<u64,3>{v_c34, v_c4, 0}, [&](const std::array<u64,3>& m282) {
                  u64 v_c36 = m282[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex212, std::array<u64,2>{v_c36, 0})) return;
                  slog::join_probe<2,1>(eval_args_ansindex213, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m283) {
                    u64 v_c20 = m283[1];
                    slog::join_probe<2,1>(tick_ansindex214, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m284) {
                      u64 v_c37 = m284[1];
                      slog::join_probe_old<3,1>(closureindex215, closuredelta223, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m285) {
                        u64 v_c38 = m285[1]; u64 v_c23 = m285[2];
                        if (!slog::exists_probe<3,1>(bindingindex216, std::array<u64,3>{v_c23, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex217, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m286) {
                          u64 v_c39 = m286[1];
                          slog::join_probe<3,2>(bindingindex218, std::array<u64,3>{v_c39, v_c23, 0}, [&](const std::array<u64,3>& m287) {
                            u64 v_c40 = m287[2];
                            slog::join_probe_old<3,1>(lambdaindex219, lambdadelta224, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m288) {
                              u64 v_c24 = m288[1]; u64 v_c3 = m288[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c39, v_c37, v_c40}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c39, v_c37, v_c4}, std::array<u16,3>{0, 1, 2});
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
        ReadTask225* _cont = new ReadTask225(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask225(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (exists closure (2 0 1) 1 cb) (join freevar (0 1) 1 y __t3miO28) (join-old closure (1 2 0) 2 (1 2 0) __t3miO28 cb __t6CK626) (join eval_ans (1 0) 1 __t6CK626 __t84Ji24) (join-old eval (0 2 1) 1 (0 2 1) __t84Ji24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0NvE30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex289;  slog::Index** freevarindex290;  slog::Index** closureindex291;  slog::Index** eval_ansindex292;  slog::Index** evalindex293;  slog::Index** appindex294;  slog::Index** eval_argsindex295;  slog::Index** tickindex296;  slog::Index** evalindex297;  slog::Index** tickindex298;  slog::Index** appindex299;  slog::Index** eval_argsindex300;  slog::Index** eval_args_ansindex301;  slog::Index** tickindex302;  slog::Index** tick_ansindex303;  slog::Index** eval_args_ansindex304;  slog::Index** tick_ansindex305;  slog::Index** lambdaindex306;  slog::Index** closuredelta307;  slog::Index** evaldelta308;  slog::Index** appdelta309;  slog::Index** eval_argsdelta310;  slog::Index** tickdelta311;  slog::Index** tick_ansdelta312;  slog::Index** lambdadelta313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord315({0, 1, 2});
      slog::Relation* readrel316 = db->getRelation("binding");
      head_index[0] = readrel316->getIndex(ord315, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord317({0, 1, 2});
      slog::Relation* readrel318 = db->getRelation("binding_event");
      head_index[1] = readrel318->getIndex(ord317, false);
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord319({2, 0, 1});
      slog::Relation* readrel320 = db->getRelation("closure");
      closureindex289 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("freevar");
      freevarindex290 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 2, 0});
      slog::Relation* readrel324 = db->getRelation("closure");
      closureindex291 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("closure");
      closuredelta307 = readrel326->getIndex(ord325, true);
      std::vector<u16> ord327({1, 0});
      slog::Relation* readrel328 = db->getRelation("eval_ans");
      eval_ansindex292 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 2, 1});
      slog::Relation* readrel330 = db->getRelation("eval");
      evalindex293 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 2, 1});
      slog::Relation* readrel332 = db->getRelation("eval");
      evaldelta308 = readrel332->getIndex(ord331, true);
      std::vector<u16> ord333({1, 2, 0});
      slog::Relation* readrel334 = db->getRelation("app");
      appindex294 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({2, 0, 1});
      slog::Relation* readrel336 = db->getRelation("eval_args");
      eval_argsindex295 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({2, 0, 1});
      slog::Relation* readrel338 = db->getRelation("tick");
      tickindex296 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({2, 0, 1});
      slog::Relation* readrel340 = db->getRelation("eval");
      evalindex297 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("tick");
      tickindex298 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1, 2});
      slog::Relation* readrel344 = db->getRelation("app");
      appindex299 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1, 2});
      slog::Relation* readrel346 = db->getRelation("app");
      appdelta309 = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({1, 2, 0});
      slog::Relation* readrel348 = db->getRelation("eval_args");
      eval_argsindex300 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("eval_args");
      eval_argsdelta310 = readrel350->getIndex(ord349, true);
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("eval_args_ans");
      eval_args_ansindex301 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("tick");
      tickindex302 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 0});
      slog::Relation* readrel356 = db->getRelation("tick");
      tickdelta311 = readrel356->getIndex(ord355, true);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("tick_ans");
      tick_ansindex303 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({0, 1});
      slog::Relation* readrel360 = db->getRelation("eval_args_ans");
      eval_args_ansindex304 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({0, 1});
      slog::Relation* readrel362 = db->getRelation("tick_ans");
      tick_ansindex305 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("tick_ans");
      tick_ansdelta312 = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({0, 1, 2});
      slog::Relation* readrel366 = db->getRelation("lambda");
      lambdaindex306 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 1, 2});
      slog::Relation* readrel368 = db->getRelation("lambda");
      lambdadelta313 = readrel368->getIndex(ord367, true);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c40 = _t[2];
        if (!slog::exists_probe<3,1>(closureindex289, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex290, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m369) {
          u64 v_c38 = m369[1];
          slog::join_probe_old<3,2>(closureindex291, closuredelta307, std::array<u64,3>{v_c38, v_c23, 0}, [&](const std::array<u64,3>& m370) {
            u64 v_c32 = m370[2];
            slog::join_probe<2,1>(eval_ansindex292, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m371) {
              u64 v_c31 = m371[1];
              slog::join_probe_old<3,1>(evalindex293, evaldelta308, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m372) {
                u64 v_c4 = m372[1]; u64 v_c14 = m372[2];
                if (!slog::exists_probe<3,1>(appindex294, std::array<u64,3>{v_c14, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex295, std::array<u64,3>{v_c4, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex296, std::array<u64,3>{v_c4, 0, 0})) return;
                slog::join_probe<3,1>(evalindex297, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m373) {
                  u64 v_c33 = m373[1]; u64 v_c34 = m373[2];
                  if (!slog::exists_probe<3,2>(tickindex298, std::array<u64,3>{v_c34, v_c4, 0})) return;
                  slog::join_probe_old<3,2>(appindex299, appdelta309, std::array<u64,3>{v_c34, v_c14, 0}, [&](const std::array<u64,3>& m374) {
                    u64 v_c15 = m374[2];
                    slog::join_probe_old<3,2>(eval_argsindex300, eval_argsdelta310, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m375) {
                      u64 v_c35 = m375[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex301, std::array<u64,2>{v_c35, 0})) return;
                      slog::join_probe_old<3,2>(tickindex302, tickdelta311, std::array<u64,3>{v_c34, v_c4, 0}, [&](const std::array<u64,3>& m376) {
                        u64 v_c36 = m376[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex303, std::array<u64,2>{v_c36, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex304, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m377) {
                          u64 v_c20 = m377[1];
                          slog::join_probe_old<2,1>(tick_ansindex305, tick_ansdelta312, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m378) {
                            u64 v_c37 = m378[1];
                            slog::join_probe_old<3,1>(lambdaindex306, lambdadelta313, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m379) {
                              u64 v_c24 = m379[1]; u64 v_c3 = m379[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c39, v_c37, v_c40}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c39, v_c37, v_c4}, std::array<u16,3>{0, 1, 2});
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
  // (crule (pre) (scan temp2ZKS1041 __t0Xgw154 __t9t79153 c) (body (join closure (1 2 0) 2 __t9t79153 c __t8gPR152)) (head (emit eval_ans (0 1) __t0Xgw154 __t8gPR152)) interp.slog:29 #f)
  class ReadTask381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex380;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord382({0, 1});
      slog::Relation* readrel383 = db->getRelation("eval_ans");
      head_index[0] = readrel383->getIndex(ord382, false);
      outer_rel = db->getRelation("temp2ZKS1041");
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("closure");
      closureindex380 = readrel385->getIndex(ord384, false);
  
    }
    ReadTask381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[2];
        slog::join_probe<3,2>(closureindex380, std::array<u64,3>{v_c42, v_c4, 0}, [&](const std::array<u64,3>& m386) {
          u64 v_c43 = m386[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c43}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:temp2ZKS1041", _fires);
  
      if (!_done)
      {
        ReadTask381* _cont = new ReadTask381(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask381(db,b), false);
  // (crule (pre) (scan eval __t3Egw332 ef c) (body (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t3Egw332) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2Zls334) (exists eval_args_ans (0 1) 1 __t2Zls334) (join eval_ans (0 1) 1 __t3Egw332 __t68RF333) (join eval_args_ans (0 1) 1 __t2Zls334 vs) (join-old prim (0 1) 1 (0 1) __t68RF333 op)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask397 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex387;  slog::Index** eval_ansindex388;  slog::Index** $sup56712x74x0x0x0index389;  slog::Index** eval_argsindex390;  slog::Index** eval_args_ansindex391;  slog::Index** eval_ansindex392;  slog::Index** eval_args_ansindex393;  slog::Index** primindex394;  slog::Index** eval_argsdelta395;  slog::Index** primdelta396;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord398({2, 0, 1});
      slog::Relation* readrel399 = db->getRelation("eval_args");
      eval_argsindex387 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("eval_ans");
      eval_ansindex388 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 2, 3, 0});
      slog::Relation* readrel403 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index389 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("eval_args");
      eval_argsindex390 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("eval_args");
      eval_argsdelta395 = readrel407->getIndex(ord406, true);
      std::vector<u16> ord408({0, 1});
      slog::Relation* readrel409 = db->getRelation("eval_args_ans");
      eval_args_ansindex391 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("eval_ans");
      eval_ansindex392 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("eval_args_ans");
      eval_args_ansindex393 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("prim");
      primindex394 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("prim");
      primdelta396 = readrel417->getIndex(ord416, true);
  
    }
    ReadTask397(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex387, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex388, std::array<u64,2>{v_c44, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index389, std::array<u64,4>{v_c4, v_c14, 0, 0}, [&](const std::array<u64,4>& m418) {
          u64 v_c15 = m418[2]; u64 v_c16 = m418[3];
          slog::join_probe_old<3,2>(eval_argsindex390, eval_argsdelta395, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m419) {
            u64 v_c45 = m419[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex391, std::array<u64,2>{v_c45, 0})) return;
            slog::join_probe<2,1>(eval_ansindex392, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m420) {
              u64 v_c46 = m420[1];
              slog::join_probe<2,1>(eval_args_ansindex393, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m421) {
                u64 v_c20 = m421[1];
                slog::join_probe_old<2,1>(primindex394, primdelta396, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m422) {
                  u64 v_c47 = m422[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c47, v_c20}, std::array<u16,3>{1, 2, 0});
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
        ReadTask397* _cont = new ReadTask397(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask397(db,b), false);
  // (crule (pre (let __trid5V8A682 const781eda039ec10c193395ca07) (let __trel1Gni683 const4a59dbb9cb3129dfcc75170b) (let __tcol0U8X684 const5feceb66ffc86f38d952786c) (let __trel01vr685 const4a59dbb9cb3129dfcc75170b) (let __tcol42Ey686 const6b86b273ff34fce19d6b804e)) (scan $sup56712x93x0x0x0 __d0 c eb er x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid5V8A682 __trel1Gni683 __tcol0U8X684 (1 2 3 4 0)) (tycheck c (accept seq) __trid5V8A682 __trel01vr685 __tcol42Ey686 (1 2 3 4 0)) (mkstruct eval (1 2 0) __90S6681 er c)) interp.slog:94 #f)
  class ReadTask432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid423;  u32 sid424;  u32 sid425;  u32 sid426;  u32 sid427;  u32 sid428;  u32 sid429;  u32 sid430;  u32 sid431;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      sid423 = db->getRelation("app")->getStructId();
      sid424 = db->getRelation("boolean")->getStructId();
      sid425 = db->getRelation("if")->getStructId();
      sid426 = db->getRelation("lambda")->getStructId();
      sid427 = db->getRelation("let")->getStructId();
      sid428 = db->getRelation("letrec")->getStructId();
      sid429 = db->getRelation("num")->getStructId();
      sid430 = db->getRelation("ref")->getStructId();
      sid431 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const781eda039ec10c193395ca07;
      u64 v_c49 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid423 || decode_struct_id(v_c6) == sid424 || decode_struct_id(v_c6) == sid425 || decode_struct_id(v_c6) == sid426 || decode_struct_id(v_c6) == sid427 || decode_struct_id(v_c6) == sid428 || decode_struct_id(v_c6) == sid429 || decode_struct_id(v_c6) == sid430 || decode_struct_id(v_c6) == sid431))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c48, v_c49, v_c50, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c48, v_c51, v_c52, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:$sup56712x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask432* _cont = new ReadTask432(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask432(db,b), false);
  // (crule (pre) (scan eval __0ffn676 __t45PK165 c) (body (join-old app (0 1 2) 1 (0 1 2) __t45PK165 ef es) (join freevar (0 1) 0 y __t4lcS166) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t4lcS166 xs eb)) (head (mkstruct eval_args (1 2 0) __3T4u677 es c)) interp.slog:56 #f)
  class ReadTask438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex433;  slog::Index** freevarindex434;  slog::Index** bindingindex435;  slog::Index** lambdaindex436;  slog::Index** appdelta437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord439({0, 1, 2});
      slog::Relation* readrel440 = db->getRelation("app");
      appindex433 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({0, 1, 2});
      slog::Relation* readrel442 = db->getRelation("app");
      appdelta437 = readrel442->getIndex(ord441, true);
      std::vector<u16> ord443({0, 1});
      slog::Relation* readrel444 = db->getRelation("freevar");
      freevarindex434 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({0, 1, 2});
      slog::Relation* readrel446 = db->getRelation("binding");
      bindingindex435 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({0, 1, 2});
      slog::Relation* readrel448 = db->getRelation("lambda");
      lambdaindex436 = readrel448->getIndex(ord447, false);
  
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe_old<3,1>(appindex433, appdelta437, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m449) {
          u64 v_c14 = m449[1]; u64 v_c15 = m449[2];
          slog::join_all<2>(freevarindex434, [&](const std::array<u64,2>& m450) {
            u64 v_c39 = m450[0]; u64 v_c55 = m450[1];
            slog::join_probe<3,1>(bindingindex435, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m451) {
              u64 v_c23 = m451[1]; u64 v_c40 = m451[2];
              slog::join_probe<3,1>(lambdaindex436, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m452) {
                u64 v_c24 = m452[1]; u64 v_c3 = m452[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c4}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo8B0L443 __t9eYl306 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo16uv440 __t9eYl306 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3GRa441 __t9eYl306 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo2Vbm442 __t9eYl306 _00024seq2) (exists _enum (1 0) 1 __tconst0flI607) (join delta (1 2 0) 2 __tconst2Cp4303 _00024seq2 __t2i9A304) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join boolval (0 1) 1 __t9eYl306 b) (letp _00024sql7hRC435 (aslst _00024seq2)) (let chk27Bw1028 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk27Bw1028) (letp chk79dt1029 (lref _00024sql7hRC435 _00024sqc91nv438)) (eq __t9eYl306 chk79dt1029) (letp chk6zYy1030 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk6zYy1030)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask460 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex453;  slog::Index** $seq_atindex454;  slog::Index** $seq_atrindex455;  slog::Index** _enumindex456;  slog::Index** deltaindex457;  slog::Index** _enumindex458;  slog::Index** boolvalindex459;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord461({1, 0, 2});
      slog::Relation* readrel462 = db->getRelation("$seq_atr");
      driver_index = readrel462->getIndex(ord461, true);
      std::vector<u16> ord463({1, 0, 2});
      slog::Relation* readrel464 = db->getRelation("$seq_at");
      $seq_atindex453 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 0, 2});
      slog::Relation* readrel466 = db->getRelation("$seq_at");
      $seq_atindex454 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 0, 2});
      slog::Relation* readrel468 = db->getRelation("$seq_atr");
      $seq_atrindex455 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 0});
      slog::Relation* readrel470 = db->getRelation("_enum");
      _enumindex456 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("delta");
      deltaindex457 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 0});
      slog::Relation* readrel474 = db->getRelation("_enum");
      _enumindex458 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("boolval");
      boolvalindex459 = readrel476->getIndex(ord475, false);
  
    }
    ReadTask460(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c57 = v_const06abaa100ecef791ce028c56;
      u64 v_c58 = v_constd4735e3a265e16eee03f5971;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const5feceb66ffc86f38d952786c;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c64, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m477) {
        u64 v_c65 = m477[1];
        u64 v_c66 = m477[2];
        if (buckethash(v_c65) != bucket) return;
        slog::join_probe<3,3>($seq_atindex453, std::array<u64,3>{v_c61, v_c65, v_c66}, [&](const std::array<u64,3>& m478) {
          slog::join_probe<3,3>($seq_atindex454, std::array<u64,3>{v_c62, v_c65, v_c66}, [&](const std::array<u64,3>& m479) {
            slog::join_probe<3,3>($seq_atrindex455, std::array<u64,3>{v_c63, v_c65, v_c66}, [&](const std::array<u64,3>& m480) {
              if (!slog::exists_probe<2,1>(_enumindex456, std::array<u64,2>{v_c56, 0})) return;
              slog::join_probe<3,2>(deltaindex457, std::array<u64,3>{v_c57, v_c66, 0}, [&](const std::array<u64,3>& m481) {
                u64 v_c67 = m481[2];
                slog::join_probe<2,1>(_enumindex458, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m482) {
                  u64 v_c68 = m482[1];
                  slog::join_probe<2,1>(boolvalindex459, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m483) {
                    u64 v_c69 = m483[1];
                    bool ok484 = true;
                    u64 v_c70 = _prim_aslst(db, v_c66, &ok484);
                    if (!ok484) return;
                    u64 v_c71 = _prim_llen(db, v_c70);
                    if (v_c71 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c58 != v_c71) return;
                    bool ok485 = true;
                    u64 v_c72 = _prim_lref(db, v_c70, v_c59, &ok485);
                    if (!ok485) return;
                    if (v_c65 != v_c72) return;
                    bool ok486 = true;
                    u64 v_c73 = _prim_lref(db, v_c70, v_c60, &ok486);
                    if (!ok486) return;
                    if (v_c65 != v_c73) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c67});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c68}, std::array<u16,2>{1, 0});
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
        ReadTask460* _cont = new ReadTask460(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask460(db,b), false);
  // (crule (pre) (scan tick_ans __t8kWT184 __v0) (body (join-old eval (2 0 1) 1 (2 0 1) __v0 __t56Is182 eb) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t56Is182 v) (join-old lambda (2 0 1) 1 (2 0 1) eb __t7rcY179 xs) (join-old closure (1 2 0) 1 (1 2 0) __t7rcY179 cb __t4yWQ180) (join eval_ans (1 0) 1 __t4yWQ180 __t6e44178) (join-old eval (0 2 1) 1 (0 2 1) __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t8kWT184 c __t7cos183) (exists app (0 1 2) 2 __t7cos183 ef) (join-old eval (1 2 0) 2 (1 2 0) __t7cos183 c __t6uzd177) (join-old $sup56712x41x0x0x0 (1 0 2 3) 3 (1 0 2 3) c __t6uzd177 ef es) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (join eval_args_ans (0 1) 1 __t6UxD181 vs)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask514 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex487;  slog::Index** lambdaindex488;  slog::Index** eval_ansindex489;  slog::Index** lambdaindex490;  slog::Index** closureindex491;  slog::Index** eval_ansindex492;  slog::Index** evalindex493;  slog::Index** evalindex494;  slog::Index** $sup56712x41x0x0x0index495;  slog::Index** appindex496;  slog::Index** eval_argsindex497;  slog::Index** tickindex498;  slog::Index** appindex499;  slog::Index** evalindex500;  slog::Index** $sup56712x41x0x0x0index501;  slog::Index** appindex502;  slog::Index** eval_argsindex503;  slog::Index** eval_args_ansindex504;  slog::Index** evaldelta505;  slog::Index** lambdadelta506;  slog::Index** closuredelta507;  slog::Index** evaldelta508;  slog::Index** tickdelta509;  slog::Index** evaldelta510;  slog::Index** $sup56712x41x0x0x0delta511;  slog::Index** appdelta512;  slog::Index** eval_argsdelta513;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("eval_ans");
      head_index[0] = readrel516->getIndex(ord515, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord517({2, 0, 1});
      slog::Relation* readrel518 = db->getRelation("eval");
      evalindex487 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({2, 0, 1});
      slog::Relation* readrel520 = db->getRelation("eval");
      evaldelta505 = readrel520->getIndex(ord519, true);
      std::vector<u16> ord521({2, 0, 1});
      slog::Relation* readrel522 = db->getRelation("lambda");
      lambdaindex488 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1});
      slog::Relation* readrel524 = db->getRelation("eval_ans");
      eval_ansindex489 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({2, 0, 1});
      slog::Relation* readrel526 = db->getRelation("lambda");
      lambdaindex490 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({2, 0, 1});
      slog::Relation* readrel528 = db->getRelation("lambda");
      lambdadelta506 = readrel528->getIndex(ord527, true);
      std::vector<u16> ord529({1, 2, 0});
      slog::Relation* readrel530 = db->getRelation("closure");
      closureindex491 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 0});
      slog::Relation* readrel532 = db->getRelation("closure");
      closuredelta507 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({1, 0});
      slog::Relation* readrel534 = db->getRelation("eval_ans");
      eval_ansindex492 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 2, 1});
      slog::Relation* readrel536 = db->getRelation("eval");
      evalindex493 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({0, 2, 1});
      slog::Relation* readrel538 = db->getRelation("eval");
      evaldelta508 = readrel538->getIndex(ord537, true);
      std::vector<u16> ord539({2, 0, 1});
      slog::Relation* readrel540 = db->getRelation("eval");
      evalindex494 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 3, 0});
      slog::Relation* readrel542 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index495 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 2, 0});
      slog::Relation* readrel544 = db->getRelation("app");
      appindex496 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({2, 0, 1});
      slog::Relation* readrel546 = db->getRelation("eval_args");
      eval_argsindex497 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({0, 2, 1});
      slog::Relation* readrel548 = db->getRelation("tick");
      tickindex498 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 2, 1});
      slog::Relation* readrel550 = db->getRelation("tick");
      tickdelta509 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({0, 1, 2});
      slog::Relation* readrel552 = db->getRelation("app");
      appindex499 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 0});
      slog::Relation* readrel554 = db->getRelation("eval");
      evalindex500 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 2, 0});
      slog::Relation* readrel556 = db->getRelation("eval");
      evaldelta510 = readrel556->getIndex(ord555, true);
      std::vector<u16> ord557({1, 0, 2, 3});
      slog::Relation* readrel558 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index501 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 0, 2, 3});
      slog::Relation* readrel560 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta511 = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({0, 1, 2});
      slog::Relation* readrel562 = db->getRelation("app");
      appindex502 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({0, 1, 2});
      slog::Relation* readrel564 = db->getRelation("app");
      appdelta512 = readrel564->getIndex(ord563, true);
      std::vector<u16> ord565({1, 2, 0});
      slog::Relation* readrel566 = db->getRelation("eval_args");
      eval_argsindex503 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 0});
      slog::Relation* readrel568 = db->getRelation("eval_args");
      eval_argsdelta513 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({0, 1});
      slog::Relation* readrel570 = db->getRelation("eval_args_ans");
      eval_args_ansindex504 = readrel570->getIndex(ord569, false);
  
    }
    ReadTask514(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(evalindex487, evaldelta505, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m571) {
          u64 v_c75 = m571[1]; u64 v_c3 = m571[2];
          if (!slog::exists_probe<3,1>(lambdaindex488, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<2,1>(eval_ansindex489, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m572) {
            u64 v_c11 = m572[1];
            slog::join_probe_old<3,1>(lambdaindex490, lambdadelta506, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m573) {
              u64 v_c76 = m573[1]; u64 v_c24 = m573[2];
              slog::join_probe_old<3,1>(closureindex491, closuredelta507, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m574) {
                u64 v_c23 = m574[1]; u64 v_c77 = m574[2];
                slog::join_probe<2,1>(eval_ansindex492, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m575) {
                  u64 v_c78 = m575[1];
                  slog::join_probe_old<3,1>(evalindex493, evaldelta508, std::array<u64,3>{v_c78, 0, 0}, [&](const std::array<u64,3>& m576) {
                    u64 v_c4 = m576[1]; u64 v_c14 = m576[2];
                    if (!slog::exists_probe<3,1>(evalindex494, std::array<u64,3>{v_c4, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index495, std::array<u64,4>{v_c4, v_c14, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex496, std::array<u64,3>{v_c14, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex497, std::array<u64,3>{v_c4, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex498, tickdelta509, std::array<u64,3>{v_c74, v_c4, 0}, [&](const std::array<u64,3>& m577) {
                      u64 v_c79 = m577[2];
                      if (!slog::exists_probe<3,2>(appindex499, std::array<u64,3>{v_c79, v_c14, 0})) return;
                      slog::join_probe_old<3,2>(evalindex500, evaldelta510, std::array<u64,3>{v_c79, v_c4, 0}, [&](const std::array<u64,3>& m578) {
                        u64 v_c80 = m578[2];
                        slog::join_probe_old<4,3>($sup56712x41x0x0x0index501, $sup56712x41x0x0x0delta511, std::array<u64,4>{v_c4, v_c80, v_c14, 0}, [&](const std::array<u64,4>& m579) {
                          u64 v_c15 = m579[3];
                          slog::join_probe_old<3,3>(appindex502, appdelta512, std::array<u64,3>{v_c79, v_c14, v_c15}, [&](const std::array<u64,3>& m580) {
                            slog::join_probe_old<3,2>(eval_argsindex503, eval_argsdelta513, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m581) {
                              u64 v_c81 = m581[2];
                              slog::join_probe<2,1>(eval_args_ansindex504, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m582) {
                                u64 v_c20 = m582[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c80, v_c11}, std::array<u16,2>{0, 1});
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
        ReadTask514* _cont = new ReadTask514(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask514(db,b), false);
  // (crule (pre) (scan temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1) (body (let __t1E6c377 (lpush __t31sY376 __v0))) (head (emit-temp temp7a2g934 __t1E6c377 __t1ye1379 __v1)) interp.slog:38 #f)
  class ReadTask583 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7a2g934");
      outer_rel = db->getRelation("temp0JGK933");
  
    }
    ReadTask583(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[1];
        u64 v_c21 = _t[2];
        u64 v_c83 = _t[3];
        u64 v_c84 = _prim_lpush(db, v_c82, v_c21);
        if (v_c84 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c84, v_c0, v_c83});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp0JGK933", _fires);
  
      if (!_done)
      {
        ReadTask583* _cont = new ReadTask583(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask583(db,b), false);
  // (crule (pre) (scan let __t9Wlk294 x er eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t9Wlk294 c __t3j1R295)) (head (emit $sup56712x91x0x0x0 (0 1 2 3 4) __t3j1R295 c eb er x)) interp.slog:92 #f)
  class ReadTask586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex584;  slog::Index** evaldelta585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord587({0, 1, 2, 3, 4});
      slog::Relation* readrel588 = db->getRelation("$sup56712x91x0x0x0");
      head_index[0] = readrel588->getIndex(ord587, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("eval");
      evalindex584 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 0});
      slog::Relation* readrel592 = db->getRelation("eval");
      evaldelta585 = readrel592->getIndex(ord591, true);
  
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
        u64 v_c85 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        slog::join_probe_old<3,1>(evalindex584, evaldelta585, std::array<u64,3>{v_c85, 0, 0}, [&](const std::array<u64,3>& m593) {
          u64 v_c4 = m593[1]; u64 v_c86 = m593[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c86, v_c4, v_c3, v_c6, v_c7}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:let", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre52pK814 __errf6CZ5815 __errf1XyR816) (body) (head (emit error (0) __erre52pK814)) <internal>:1 #f)
  class ReadTask594 : public slog::Task
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
      std::vector<u16> ord595({0});
      slog::Relation* readrel596 = db->getRelation("error");
      head_index[0] = readrel596->getIndex(ord595, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask594(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c89 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c87}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask594* _cont = new ReadTask594(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask594(db,b), false);
  // (crule (pre (let __tconst7saS665 constb9e118781cea1f9fa01462e0) (let __tconst4R6j353 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9CpF541 const6b86b273ff34fce19d6b804e) (let _00024sqc8vSl542 const5feceb66ffc86f38d952786c) (let _00024sqo1EFx543 const5feceb66ffc86f38d952786c) (let _00024sqo1k6Q544 const5feceb66ffc86f38d952786c)) (scan scheme_false fv) (body (exists $seq_at (1 0 2) 1 _00024sqo1EFx543) (exists $seq_atr (1 0 2) 1 _00024sqo1k6Q544) (exists delta (1 2 0) 1 __tconst4R6j353) (join _enum (1 0) 1 __tconst7saS665 __t73g6351) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo1EFx543 v _00024seq0) (neq v fv) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1k6Q544 v _00024seq0) (join-old delta (1 2 0) 2 (1 2 0) __tconst4R6j353 _00024seq0 __t1geM354) (letp _00024sql7fhi539 (aslst _00024seq0)) (let chk2LnC1034 (llen _00024sql7fhi539)) (eq _00024sqc9CpF541 chk2LnC1034) (letp chk36Sx1035 (lref _00024sql7fhi539 _00024sqc8vSl542)) (eq v chk36Sx1035)) (head (emit-temp temp9mFJ1033 __t1geM354) (mkstruct boolval (1 0) __t1MPL352 __t73g6351)) interp.slog:114 #f)
  class ReadTask607 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex597;  slog::Index** $seq_atrindex598;  slog::Index** deltaindex599;  slog::Index** _enumindex600;  slog::Index** $seq_atindex601;  slog::Index** $seq_atrindex602;  slog::Index** deltaindex603;  slog::Index** $seq_atdelta604;  slog::Index** $seq_atrdelta605;  slog::Index** deltadelta606;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mFJ1033");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord608({1, 0, 2});
      slog::Relation* readrel609 = db->getRelation("$seq_at");
      $seq_atindex597 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 0, 2});
      slog::Relation* readrel611 = db->getRelation("$seq_atr");
      $seq_atrindex598 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 2, 0});
      slog::Relation* readrel613 = db->getRelation("delta");
      deltaindex599 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 0});
      slog::Relation* readrel615 = db->getRelation("_enum");
      _enumindex600 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 0, 2});
      slog::Relation* readrel617 = db->getRelation("$seq_at");
      $seq_atindex601 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 0, 2});
      slog::Relation* readrel619 = db->getRelation("$seq_at");
      $seq_atdelta604 = readrel619->getIndex(ord618, true);
      std::vector<u16> ord620({1, 0, 2});
      slog::Relation* readrel621 = db->getRelation("$seq_atr");
      $seq_atrindex602 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0, 2});
      slog::Relation* readrel623 = db->getRelation("$seq_atr");
      $seq_atrdelta605 = readrel623->getIndex(ord622, true);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("delta");
      deltaindex603 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("delta");
      deltadelta606 = readrel627->getIndex(ord626, true);
  
    }
    ReadTask607(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c91 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_const5feceb66ffc86f38d952786c;
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
        if (!slog::exists_probe<3,1>($seq_atindex597, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atrindex598, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex599, std::array<u64,3>{v_c91, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex600, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m628) {
          u64 v_c97 = m628[1];
          slog::join_probe_old<3,1>($seq_atindex601, $seq_atdelta604, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m629) {
            u64 v_c11 = m629[1]; u64 v_c98 = m629[2];
            if (v_c11 == v_c96) return;
            slog::join_probe_old<3,3>($seq_atrindex602, $seq_atrdelta605, std::array<u64,3>{v_c95, v_c11, v_c98}, [&](const std::array<u64,3>& m630) {
              slog::join_probe_old<3,2>(deltaindex603, deltadelta606, std::array<u64,3>{v_c91, v_c98, 0}, [&](const std::array<u64,3>& m631) {
                u64 v_c99 = m631[2];
                bool ok632 = true;
                u64 v_c100 = _prim_aslst(db, v_c98, &ok632);
                if (!ok632) return;
                u64 v_c101 = _prim_llen(db, v_c100);
                if (v_c101 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c92 != v_c101) return;
                bool ok633 = true;
                u64 v_c102 = _prim_lref(db, v_c100, v_c93, &ok633);
                if (!ok633) return;
                if (v_c11 != v_c102) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c99});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c97}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:scheme_false", _fires);
  
      if (!_done)
      {
        ReadTask607* _cont = new ReadTask607(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask607(db,b), false);
  // (crule (pre) (scan if __t3ePt42 e1 e2 e3) (body (exists eval (1 2 0) 1 __t3ePt42) (exists eval (1 2 0) 1 e1) (exists select_branch (2 3 0 1) 2 e2 e3) (join $sup56712x86x0x0x0 (3 4 2 0 1) 3 e2 e3 e1 __t7yOw43 c) (join-old eval (0 2 1) 3 (0 2 1) __t7yOw43 c __t3ePt42) (exists eval (2 0 1) 1 c) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9ATC44) (exists eval_ans (0 1) 1 __t9ATC44) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t5q6W45 __v0) (join eval_ans (0 1) 2 __t9ATC44 __v0) (join select_branch_ans (0 1) 1 __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join eval_ans (0 1) 1 __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask651 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex634;  slog::Index** evalindex635;  slog::Index** select_branchindex636;  slog::Index** $sup56712x86x0x0x0index637;  slog::Index** evalindex638;  slog::Index** evalindex639;  slog::Index** evalindex640;  slog::Index** eval_ansindex641;  slog::Index** select_branchindex642;  slog::Index** eval_ansindex643;  slog::Index** select_branch_ansindex644;  slog::Index** evalindex645;  slog::Index** eval_ansindex646;  slog::Index** evaldelta647;  slog::Index** evaldelta648;  slog::Index** select_branchdelta649;  slog::Index** evaldelta650;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("eval_ans");
      head_index[0] = readrel653->getIndex(ord652, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("eval");
      evalindex634 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("eval");
      evalindex635 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({2, 3, 0, 1});
      slog::Relation* readrel659 = db->getRelation("select_branch");
      select_branchindex636 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({3, 4, 2, 0, 1});
      slog::Relation* readrel661 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index637 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 2, 1});
      slog::Relation* readrel663 = db->getRelation("eval");
      evalindex638 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({0, 2, 1});
      slog::Relation* readrel665 = db->getRelation("eval");
      evaldelta647 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({2, 0, 1});
      slog::Relation* readrel667 = db->getRelation("eval");
      evalindex639 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("eval");
      evalindex640 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 2, 0});
      slog::Relation* readrel671 = db->getRelation("eval");
      evaldelta648 = readrel671->getIndex(ord670, true);
      std::vector<u16> ord672({0, 1});
      slog::Relation* readrel673 = db->getRelation("eval_ans");
      eval_ansindex641 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({2, 3, 0, 1});
      slog::Relation* readrel675 = db->getRelation("select_branch");
      select_branchindex642 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({2, 3, 0, 1});
      slog::Relation* readrel677 = db->getRelation("select_branch");
      select_branchdelta649 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("eval_ans");
      eval_ansindex643 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({0, 1});
      slog::Relation* readrel681 = db->getRelation("select_branch_ans");
      select_branch_ansindex644 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("eval");
      evalindex645 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 0});
      slog::Relation* readrel685 = db->getRelation("eval");
      evaldelta650 = readrel685->getIndex(ord684, true);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_ans");
      eval_ansindex646 = readrel687->getIndex(ord686, false);
  
    }
    ReadTask651(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c103 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c105 = _t[2];
        u64 v_c106 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex634, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex635, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex636, std::array<u64,4>{v_c105, v_c106, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x86x0x0x0index637, std::array<u64,5>{v_c105, v_c106, v_c104, 0, 0}, [&](const std::array<u64,5>& m688) {
          u64 v_c107 = m688[3]; u64 v_c4 = m688[4];
          slog::join_probe_old<3,3>(evalindex638, evaldelta647, std::array<u64,3>{v_c107, v_c4, v_c103}, [&](const std::array<u64,3>& m689) {
            if (!slog::exists_probe<3,1>(evalindex639, std::array<u64,3>{v_c4, 0, 0})) return;
            slog::join_probe_old<3,2>(evalindex640, evaldelta648, std::array<u64,3>{v_c104, v_c4, 0}, [&](const std::array<u64,3>& m690) {
              u64 v_c108 = m690[2];
              if (!slog::exists_probe<2,1>(eval_ansindex641, std::array<u64,2>{v_c108, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex642, select_branchdelta649, std::array<u64,4>{v_c105, v_c106, 0, 0}, [&](const std::array<u64,4>& m691) {
                u64 v_c109 = m691[2]; u64 v_c21 = m691[3];
                slog::join_probe<2,2>(eval_ansindex643, std::array<u64,2>{v_c108, v_c21}, [&](const std::array<u64,2>& m692) {
                  slog::join_probe<2,1>(select_branch_ansindex644, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m693) {
                    u64 v_c83 = m693[1];
                    slog::join_probe_old<3,2>(evalindex645, evaldelta650, std::array<u64,3>{v_c83, v_c4, 0}, [&](const std::array<u64,3>& m694) {
                      u64 v_c110 = m694[2];
                      slog::join_probe<2,1>(eval_ansindex646, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m695) {
                        u64 v_c111 = m695[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c107, v_c111}, std::array<u16,2>{0, 1});
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
        ReadTask651* _cont = new ReadTask651(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask651(db,b), false);
  // (crule (pre) (scan temp9zJ31008 __t0SHl48 __t8UGh49) (body) (head (emit lst_take_ans (0 1) __t8UGh49 __t0SHl48)) list.slog:29 #f)
  class ReadTask696 : public slog::Task
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
      head_rel[0] = db->getRelation("lst_take_ans");
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("lst_take_ans");
      head_index[0] = readrel698->getIndex(ord697, false);
      outer_rel = db->getRelation("temp9zJ31008");
  
    }
    ReadTask696(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c112 = _t[0];
        u64 v_c113 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c113, v_c112}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:temp9zJ31008", _fires);
  
      if (!_done)
      {
        ReadTask696* _cont = new ReadTask696(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask696(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst59e9288 const1fb680aa1ed965bc09f024ab) (let __tconst2I8h285 const7297d2085ea0adffc396d546) (let __tconst4QwH278 const6b86b273ff34fce19d6b804e) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst8lfC272 const90edba1c9d0bb14ec514a96c) (let __tconst48zw269 const0933fb667296882d8c45abca) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst16Fs254 const879923da020d1533f4d8e921) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst7F8v233 const53a56174f3826669a422fc54) (let __tconst85km226 constd4735e3a265e16eee03f5971) (let __tconst9HGv215 const7902699be42c8a8e46fbbb45)) (scan temp5WmB960 __t5yWE289) (body (exists ref (1 0) 1 __tconst7Bar243) (exists ref (1 0) 1 __tconst2XD5276) (exists ref (1 0) 1 __tconst7wlx292) (exists num (1 0) 1 __tconst85km226) (exists num (1 0) 1 __tconst4QwH278) (exists ref (1 0) 1 __tconst7F8v233) (exists ref (1 0) 1 __tconst4aTz260) (exists ref (1 0) 1 __tconst6YSZ252) (exists ref (1 0) 1 __tconst39ZW253) (exists ref (1 0) 1 __tconst16Fs254) (exists ref (1 0) 1 __tconst8lfC272) (exists ref (1 0) 1 __tconst48zw269) (exists ref (1 0) 1 __tconst59e9288) (exists ref (1 0) 1 __tconst2I8h285) (join num (1 0) 1 __tconst9HGv215 __t3mP4216) (join ref (1 0) 1 __tconst7Bar243 __t8Ely220) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst7wlx292 __t1iN7225) (join num (1 0) 1 __tconst85km226 __t7w2Z227) (join num (1 0) 1 __tconst4QwH278 __t3YP0229) (join ref (1 0) 1 __tconst7F8v233 __t3grR234) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join ref (1 0) 1 __tconst6YSZ252 __t7SX3246) (join ref (1 0) 1 __tconst39ZW253 __t1waL248) (join ref (1 0) 1 __tconst16Fs254 __t54jO250) (join ref (1 0) 1 __tconst8lfC272 __t9LjS265) (join ref (1 0) 1 __tconst48zw269 __t7uwu270) (join ref (1 0) 1 __tconst59e9288 __t66Mu281) (join ref (1 0) 1 __tconst2I8h285 __t5wDB286) (let __t3DyN290 (lpush __t5yWE289 __tconst59e9288)) (let __t6vXM283 (lpush __t5yWE289 __t66Mu281)) (let __t4Zol274 (lpush __t5yWE289 __tconst8lfC272)) (let __t6N9H267 (lpush __t5yWE289 __t9LjS265)) (let __t7YhR256 (lpush __t5yWE289 __tconst16Fs254)) (let __t7rKO231 (lpush __t5yWE289 __t3YP0229)) (let __t9tnf218 (lpush __t5yWE289 __t3mP4216))) (head (emit-temp temp9PWx961 __t3DyN290 __t4Zol274 __t5yWE289 __t6N9H267 __t6vXM283 __t7YhR256 __t7rKO231 __t9tnf218) (mkstruct if (2 3 1 0) __t4Qs4251 __t1waL248 __t7SX3246 __t54jO250)) analysis-demo.slog:21 #f)
  class ReadTask728 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex699;  slog::Index** refindex700;  slog::Index** refindex701;  slog::Index** numindex702;  slog::Index** numindex703;  slog::Index** refindex704;  slog::Index** refindex705;  slog::Index** refindex706;  slog::Index** refindex707;  slog::Index** refindex708;  slog::Index** refindex709;  slog::Index** refindex710;  slog::Index** refindex711;  slog::Index** refindex712;  slog::Index** numindex713;  slog::Index** refindex714;  slog::Index** refindex715;  slog::Index** refindex716;  slog::Index** numindex717;  slog::Index** numindex718;  slog::Index** refindex719;  slog::Index** refindex720;  slog::Index** refindex721;  slog::Index** refindex722;  slog::Index** refindex723;  slog::Index** refindex724;  slog::Index** refindex725;  slog::Index** refindex726;  slog::Index** refindex727;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9PWx961");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp5WmB960");
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("ref");
      refindex699 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({1, 0});
      slog::Relation* readrel732 = db->getRelation("ref");
      refindex700 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 0});
      slog::Relation* readrel734 = db->getRelation("ref");
      refindex701 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 0});
      slog::Relation* readrel736 = db->getRelation("num");
      numindex702 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 0});
      slog::Relation* readrel738 = db->getRelation("num");
      numindex703 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 0});
      slog::Relation* readrel740 = db->getRelation("ref");
      refindex704 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 0});
      slog::Relation* readrel742 = db->getRelation("ref");
      refindex705 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 0});
      slog::Relation* readrel744 = db->getRelation("ref");
      refindex706 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({1, 0});
      slog::Relation* readrel746 = db->getRelation("ref");
      refindex707 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({1, 0});
      slog::Relation* readrel748 = db->getRelation("ref");
      refindex708 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 0});
      slog::Relation* readrel750 = db->getRelation("ref");
      refindex709 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 0});
      slog::Relation* readrel752 = db->getRelation("ref");
      refindex710 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({1, 0});
      slog::Relation* readrel754 = db->getRelation("ref");
      refindex711 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({1, 0});
      slog::Relation* readrel756 = db->getRelation("ref");
      refindex712 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 0});
      slog::Relation* readrel758 = db->getRelation("num");
      numindex713 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 0});
      slog::Relation* readrel760 = db->getRelation("ref");
      refindex714 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 0});
      slog::Relation* readrel762 = db->getRelation("ref");
      refindex715 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 0});
      slog::Relation* readrel764 = db->getRelation("ref");
      refindex716 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 0});
      slog::Relation* readrel766 = db->getRelation("num");
      numindex717 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 0});
      slog::Relation* readrel768 = db->getRelation("num");
      numindex718 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0});
      slog::Relation* readrel770 = db->getRelation("ref");
      refindex719 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 0});
      slog::Relation* readrel772 = db->getRelation("ref");
      refindex720 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 0});
      slog::Relation* readrel774 = db->getRelation("ref");
      refindex721 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 0});
      slog::Relation* readrel776 = db->getRelation("ref");
      refindex722 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 0});
      slog::Relation* readrel778 = db->getRelation("ref");
      refindex723 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 0});
      slog::Relation* readrel780 = db->getRelation("ref");
      refindex724 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 0});
      slog::Relation* readrel782 = db->getRelation("ref");
      refindex725 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 0});
      slog::Relation* readrel784 = db->getRelation("ref");
      refindex726 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 0});
      slog::Relation* readrel786 = db->getRelation("ref");
      refindex727 = readrel786->getIndex(ord785, false);
  
    }
    ReadTask728(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c115 = v_const1fb680aa1ed965bc09f024ab;
      u64 v_c116 = v_const7297d2085ea0adffc396d546;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constf77801bebb40767a1b303d97;
      u64 v_c119 = v_const90edba1c9d0bb14ec514a96c;
      u64 v_c120 = v_const0933fb667296882d8c45abca;
      u64 v_c121 = v_const829935b42173b360da35f679;
      u64 v_c122 = v_const879923da020d1533f4d8e921;
      u64 v_c123 = v_const8ca5d81566f88badd698137a;
      u64 v_c124 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c125 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c126 = v_const53a56174f3826669a422fc54;
      u64 v_c127 = v_constd4735e3a265e16eee03f5971;
      u64 v_c128 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c129 = _t[0];
        if (!slog::exists_probe<2,1>(refindex699, std::array<u64,2>{v_c125, 0})) return;
        if (!slog::exists_probe<2,1>(refindex700, std::array<u64,2>{v_c118, 0})) return;
        if (!slog::exists_probe<2,1>(refindex701, std::array<u64,2>{v_c114, 0})) return;
        if (!slog::exists_probe<2,1>(numindex702, std::array<u64,2>{v_c127, 0})) return;
        if (!slog::exists_probe<2,1>(numindex703, std::array<u64,2>{v_c117, 0})) return;
        if (!slog::exists_probe<2,1>(refindex704, std::array<u64,2>{v_c126, 0})) return;
        if (!slog::exists_probe<2,1>(refindex705, std::array<u64,2>{v_c121, 0})) return;
        if (!slog::exists_probe<2,1>(refindex706, std::array<u64,2>{v_c124, 0})) return;
        if (!slog::exists_probe<2,1>(refindex707, std::array<u64,2>{v_c123, 0})) return;
        if (!slog::exists_probe<2,1>(refindex708, std::array<u64,2>{v_c122, 0})) return;
        if (!slog::exists_probe<2,1>(refindex709, std::array<u64,2>{v_c119, 0})) return;
        if (!slog::exists_probe<2,1>(refindex710, std::array<u64,2>{v_c120, 0})) return;
        if (!slog::exists_probe<2,1>(refindex711, std::array<u64,2>{v_c115, 0})) return;
        if (!slog::exists_probe<2,1>(refindex712, std::array<u64,2>{v_c116, 0})) return;
        slog::join_probe<2,1>(numindex713, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m787) {
          u64 v_c130 = m787[1];
          slog::join_probe<2,1>(refindex714, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m788) {
            u64 v_c131 = m788[1];
            slog::join_probe<2,1>(refindex715, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m789) {
              u64 v_c132 = m789[1];
              slog::join_probe<2,1>(refindex716, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m790) {
                u64 v_c133 = m790[1];
                slog::join_probe<2,1>(numindex717, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m791) {
                  u64 v_c134 = m791[1];
                  slog::join_probe<2,1>(numindex718, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m792) {
                    u64 v_c135 = m792[1];
                    slog::join_probe<2,1>(refindex719, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m793) {
                      u64 v_c136 = m793[1];
                      slog::join_probe<2,1>(refindex720, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m794) {
                        u64 v_c137 = m794[1];
                        slog::join_probe<2,1>(refindex721, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m795) {
                          u64 v_c138 = m795[1];
                          slog::join_probe<2,1>(refindex722, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m796) {
                            u64 v_c139 = m796[1];
                            slog::join_probe<2,1>(refindex723, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m797) {
                              u64 v_c140 = m797[1];
                              slog::join_probe<2,1>(refindex724, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m798) {
                                u64 v_c141 = m798[1];
                                slog::join_probe<2,1>(refindex725, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m799) {
                                  u64 v_c142 = m799[1];
                                  slog::join_probe<2,1>(refindex726, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m800) {
                                    u64 v_c143 = m800[1];
                                    slog::join_probe<2,1>(refindex727, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m801) {
                                      u64 v_c144 = m801[1];
                                      u64 v_c145 = _prim_lpush(db, v_c129, v_c115);
                                      if (v_c145 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c146 = _prim_lpush(db, v_c129, v_c143);
                                      if (v_c146 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c147 = _prim_lpush(db, v_c129, v_c119);
                                      if (v_c147 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c148 = _prim_lpush(db, v_c129, v_c141);
                                      if (v_c148 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c149 = _prim_lpush(db, v_c129, v_c122);
                                      if (v_c149 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c150 = _prim_lpush(db, v_c129, v_c135);
                                      if (v_c150 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      u64 v_c151 = _prim_lpush(db, v_c129, v_c130);
                                      if (v_c151 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                      ++_fires;
                                      slog::emit_temp<8>(head_rel[0], newbatch[0], std::array<u64,8>{v_c145, v_c147, v_c129, v_c148, v_c146, v_c149, v_c150, v_c151});
                                      slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c139, v_c138, v_c140}, std::array<u16,4>{2, 3, 1, 0});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp5WmB960", _fires);
  
      if (!_done)
      {
        ReadTask728* _cont = new ReadTask728(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask728(db,b), false);
  // (crule (pre) (scan $sup56712x74x0x0x0 __d0 c ef es) (body (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3Egw332) (exists eval_ans (0 1) 1 __t3Egw332) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2Zls334) (exists eval_args_ans (0 1) 1 __t2Zls334) (join-old eval_ans (0 1) 1 (0 1) __t3Egw332 __t68RF333) (join-old eval_args_ans (0 1) 1 (0 1) __t2Zls334 vs) (join-old prim (0 1) 1 (0 1) __t68RF333 op)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask815 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex802;  slog::Index** evalindex803;  slog::Index** eval_ansindex804;  slog::Index** eval_argsindex805;  slog::Index** eval_args_ansindex806;  slog::Index** eval_ansindex807;  slog::Index** eval_args_ansindex808;  slog::Index** primindex809;  slog::Index** evaldelta810;  slog::Index** eval_argsdelta811;  slog::Index** eval_ansdelta812;  slog::Index** eval_args_ansdelta813;  slog::Index** primdelta814;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("eval_args");
      eval_argsindex802 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("eval");
      evalindex803 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("eval");
      evaldelta810 = readrel821->getIndex(ord820, true);
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("eval_ans");
      eval_ansindex804 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 2, 0});
      slog::Relation* readrel825 = db->getRelation("eval_args");
      eval_argsindex805 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("eval_args");
      eval_argsdelta811 = readrel827->getIndex(ord826, true);
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("eval_args_ans");
      eval_args_ansindex806 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("eval_ans");
      eval_ansindex807 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 1});
      slog::Relation* readrel833 = db->getRelation("eval_ans");
      eval_ansdelta812 = readrel833->getIndex(ord832, true);
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("eval_args_ans");
      eval_args_ansindex808 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("eval_args_ans");
      eval_args_ansdelta813 = readrel837->getIndex(ord836, true);
      std::vector<u16> ord838({0, 1});
      slog::Relation* readrel839 = db->getRelation("prim");
      primindex809 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({0, 1});
      slog::Relation* readrel841 = db->getRelation("prim");
      primdelta814 = readrel841->getIndex(ord840, true);
  
    }
    ReadTask815(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        if (!slog::exists_probe<3,2>(eval_argsindex802, std::array<u64,3>{v_c15, v_c4, 0})) return;
        slog::join_probe_old<3,2>(evalindex803, evaldelta810, std::array<u64,3>{v_c14, v_c4, 0}, [&](const std::array<u64,3>& m842) {
          u64 v_c44 = m842[2];
          if (!slog::exists_probe<2,1>(eval_ansindex804, std::array<u64,2>{v_c44, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex805, eval_argsdelta811, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m843) {
            u64 v_c45 = m843[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex806, std::array<u64,2>{v_c45, 0})) return;
            slog::join_probe_old<2,1>(eval_ansindex807, eval_ansdelta812, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m844) {
              u64 v_c46 = m844[1];
              slog::join_probe_old<2,1>(eval_args_ansindex808, eval_args_ansdelta813, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m845) {
                u64 v_c20 = m845[1];
                slog::join_probe_old<2,1>(primindex809, primdelta814, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m846) {
                  u64 v_c47 = m846[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c47, v_c20}, std::array<u16,3>{1, 2, 0});
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
        ReadTask815* _cont = new ReadTask815(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask815(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5)) (scan temp9U5g1005 __t0Gv1110 __t0nIl89) (body (exists app (2 0 1) 1 __t0nIl89) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join app (1 2 0) 2 __t0iVM91 __t0nIl89 __t7VwH92)) (head (emit-temp temp0SQu1006 __t0Gv1110 __t7VwH92) (mkstruct let (2 1 3 0) __t7Zm1112 __t0Gv1110 __tconst2uSL111 __t7VwH92)) analysis-demo.slog:11 #f)
  class ReadTask850 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex847;  slog::Index** refindex848;  slog::Index** appindex849;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0SQu1006");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp9U5g1005");
      std::vector<u16> ord851({2, 0, 1});
      slog::Relation* readrel852 = db->getRelation("app");
      appindex847 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 0});
      slog::Relation* readrel854 = db->getRelation("ref");
      refindex848 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 0});
      slog::Relation* readrel856 = db->getRelation("app");
      appindex849 = readrel856->getIndex(ord855, false);
  
    }
    ReadTask850(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const0457bba0679825d285ef7fa5;
  
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
        if (!slog::exists_probe<3,1>(appindex847, std::array<u64,3>{v_c154, 0, 0})) return;
        slog::join_probe<2,1>(refindex848, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m857) {
          u64 v_c155 = m857[1];
          slog::join_probe<3,2>(appindex849, std::array<u64,3>{v_c155, v_c154, 0}, [&](const std::array<u64,3>& m858) {
            u64 v_c156 = m858[2];
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c153, v_c156});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c153, v_c152, v_c156}, std::array<u16,4>{2, 1, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp9U5g1005", _fires);
  
      if (!_done)
      {
        ReadTask850* _cont = new ReadTask850(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask850(db,b), false);
  // (crule (pre (let __tconst7saS665 constb9e118781cea1f9fa01462e0) (let __tconst4R6j353 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9CpF541 const6b86b273ff34fce19d6b804e) (let _00024sqc8vSl542 const5feceb66ffc86f38d952786c) (let _00024sqo1EFx543 const5feceb66ffc86f38d952786c) (let _00024sqo1k6Q544 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1k6Q544 v _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo1EFx543 v _00024seq0) (exists _enum (1 0) 1 __tconst7saS665) (join delta (1 2 0) 2 __tconst4R6j353 _00024seq0 __t1geM354) (join _enum (1 0) 1 __tconst7saS665 __t73g6351) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql7fhi539 (aslst _00024seq0)) (let chk8obA1039 (llen _00024sql7fhi539)) (eq _00024sqc9CpF541 chk8obA1039) (letp chk8feL1040 (lref _00024sql7fhi539 _00024sqc8vSl542)) (eq v chk8feL1040)) (head (emit-temp temp9mFJ1033 __t1geM354) (mkstruct boolval (1 0) __t1MPL352 __t73g6351)) interp.slog:114 #f)
  class ReadTask864 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex859;  slog::Index** _enumindex860;  slog::Index** deltaindex861;  slog::Index** _enumindex862;  slog::Index** scheme_falseindex863;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mFJ1033");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord865({1, 0, 2});
      slog::Relation* readrel866 = db->getRelation("$seq_atr");
      driver_index = readrel866->getIndex(ord865, true);
      std::vector<u16> ord867({1, 0, 2});
      slog::Relation* readrel868 = db->getRelation("$seq_at");
      $seq_atindex859 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 0});
      slog::Relation* readrel870 = db->getRelation("_enum");
      _enumindex860 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("delta");
      deltaindex861 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 0});
      slog::Relation* readrel874 = db->getRelation("_enum");
      _enumindex862 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({0});
      slog::Relation* readrel876 = db->getRelation("scheme_false");
      scheme_falseindex863 = readrel876->getIndex(ord875, false);
  
    }
    ReadTask864(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c91 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_const5feceb66ffc86f38d952786c;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c95, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m877) {
        u64 v_c11 = m877[1];
        u64 v_c98 = m877[2];
        if (buckethash(v_c11) != bucket) return;
        slog::join_probe<3,3>($seq_atindex859, std::array<u64,3>{v_c94, v_c11, v_c98}, [&](const std::array<u64,3>& m878) {
          if (!slog::exists_probe<2,1>(_enumindex860, std::array<u64,2>{v_c90, 0})) return;
          slog::join_probe<3,2>(deltaindex861, std::array<u64,3>{v_c91, v_c98, 0}, [&](const std::array<u64,3>& m879) {
            u64 v_c99 = m879[2];
            slog::join_probe<2,1>(_enumindex862, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m880) {
              u64 v_c97 = m880[1];
              slog::join_all<1>(scheme_falseindex863, [&](const std::array<u64,1>& m881) {
                u64 v_c96 = m881[0];
                if (v_c11 == v_c96) return;
                bool ok882 = true;
                u64 v_c100 = _prim_aslst(db, v_c98, &ok882);
                if (!ok882) return;
                u64 v_c157 = _prim_llen(db, v_c100);
                if (v_c157 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c92 != v_c157) return;
                bool ok883 = true;
                u64 v_c158 = _prim_lref(db, v_c100, v_c93, &ok883);
                if (!ok883) return;
                if (v_c11 != v_c158) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c99});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c97}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask864* _cont = new ReadTask864(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask864(db,b), false);
  // (crule (pre) (scan app __t9rGt50 ef es) (body (join-old eval (1 2 0) 1 (1 2 0) __t9rGt50 c __t7KQr51)) (head (emit $sup56712x74x0x0x0 (0 1 2 3) __t7KQr51 c ef es)) interp.slog:75 #f)
  class ReadTask886 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex884;  slog::Index** evaldelta885;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord887({0, 1, 2, 3});
      slog::Relation* readrel888 = db->getRelation("$sup56712x74x0x0x0");
      head_index[0] = readrel888->getIndex(ord887, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("eval");
      evalindex884 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("eval");
      evaldelta885 = readrel892->getIndex(ord891, true);
  
    }
    ReadTask886(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c159 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe_old<3,1>(evalindex884, evaldelta885, std::array<u64,3>{v_c159, 0, 0}, [&](const std::array<u64,3>& m893) {
          u64 v_c4 = m893[1]; u64 v_c160 = m893[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c160, v_c4, v_c14, v_c15}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask886* _cont = new ReadTask886(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask886(db,b), false);
  // (crule (pre) (scan eval __3Vvk616 __t3J8m58 c) (body (join letrec (0 2 1 3) 1 __t3J8m58 er x eb)) (head (mkstruct eval (1 2 0) __8gIm617 er c)) interp.slog:95 #f)
  class ReadTask895 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex894;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord896({0, 2, 1, 3});
      slog::Relation* readrel897 = db->getRelation("letrec");
      letrecindex894 = readrel897->getIndex(ord896, false);
  
    }
    ReadTask895(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c161 = _t[0];
        u64 v_c162 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<4,1>(letrecindex894, std::array<u64,4>{v_c162, 0, 0, 0}, [&](const std::array<u64,4>& m898) {
          u64 v_c6 = m898[1]; u64 v_c7 = m898[2]; u64 v_c3 = m898[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c4}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask895* _cont = new ReadTask895(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask895(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5RED468 __t5qKD331 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo66CB469 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5qV2470 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4yFo471 __t5qKD331 _00024seq2) (exists _enum (1 0) 1 __tconst2WdB587) (join delta (1 2 0) 2 __tconst2sal328 _00024seq2 __t8DFh329) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join symval (0 1) 1 __t5qKD331 s) (letp _00024sql2Y3P463 (aslst _00024seq2)) (let chk8jBc886 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk8jBc886) (letp chk4hbs887 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (eq __t5qKD331 chk4hbs887) (letp chk44UP888 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk44UP888)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask909 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex899;  slog::Index** $seq_atrindex900;  slog::Index** $seq_atrindex901;  slog::Index** _enumindex902;  slog::Index** deltaindex903;  slog::Index** _enumindex904;  slog::Index** symvalindex905;  slog::Index** $seq_atdelta906;  slog::Index** $seq_atrdelta907;  slog::Index** $seq_atrdelta908;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord910({1, 0, 2});
      slog::Relation* readrel911 = db->getRelation("$seq_at");
      driver_index = readrel911->getIndex(ord910, true);
      std::vector<u16> ord912({1, 0, 2});
      slog::Relation* readrel913 = db->getRelation("$seq_at");
      $seq_atindex899 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 0, 2});
      slog::Relation* readrel915 = db->getRelation("$seq_at");
      $seq_atdelta906 = readrel915->getIndex(ord914, true);
      std::vector<u16> ord916({1, 0, 2});
      slog::Relation* readrel917 = db->getRelation("$seq_atr");
      $seq_atrindex900 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 0, 2});
      slog::Relation* readrel919 = db->getRelation("$seq_atr");
      $seq_atrdelta907 = readrel919->getIndex(ord918, true);
      std::vector<u16> ord920({1, 0, 2});
      slog::Relation* readrel921 = db->getRelation("$seq_atr");
      $seq_atrindex901 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({1, 0, 2});
      slog::Relation* readrel923 = db->getRelation("$seq_atr");
      $seq_atrdelta908 = readrel923->getIndex(ord922, true);
      std::vector<u16> ord924({1, 0});
      slog::Relation* readrel925 = db->getRelation("_enum");
      _enumindex902 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 2, 0});
      slog::Relation* readrel927 = db->getRelation("delta");
      deltaindex903 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 0});
      slog::Relation* readrel929 = db->getRelation("_enum");
      _enumindex904 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({0, 1});
      slog::Relation* readrel931 = db->getRelation("symval");
      symvalindex905 = readrel931->getIndex(ord930, false);
  
    }
    ReadTask909(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c164 = v_const06abaa100ecef791ce028c56;
      u64 v_c165 = v_constd4735e3a265e16eee03f5971;
      u64 v_c166 = v_const5feceb66ffc86f38d952786c;
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c168 = v_const5feceb66ffc86f38d952786c;
      u64 v_c169 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c171 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c168, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m932) {
        u64 v_c172 = m932[1];
        u64 v_c66 = m932[2];
        if (buckethash(v_c172) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex899, $seq_atdelta906, std::array<u64,3>{v_c169, v_c172, v_c66}, [&](const std::array<u64,3>& m933) {
          slog::join_probe_old<3,3>($seq_atrindex900, $seq_atrdelta907, std::array<u64,3>{v_c170, v_c172, v_c66}, [&](const std::array<u64,3>& m934) {
            slog::join_probe_old<3,3>($seq_atrindex901, $seq_atrdelta908, std::array<u64,3>{v_c171, v_c172, v_c66}, [&](const std::array<u64,3>& m935) {
              if (!slog::exists_probe<2,1>(_enumindex902, std::array<u64,2>{v_c163, 0})) return;
              slog::join_probe<3,2>(deltaindex903, std::array<u64,3>{v_c164, v_c66, 0}, [&](const std::array<u64,3>& m936) {
                u64 v_c173 = m936[2];
                slog::join_probe<2,1>(_enumindex904, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m937) {
                  u64 v_c174 = m937[1];
                  slog::join_probe<2,1>(symvalindex905, std::array<u64,2>{v_c172, 0}, [&](const std::array<u64,2>& m938) {
                    u64 v_c175 = m938[1];
                    bool ok939 = true;
                    u64 v_c176 = _prim_aslst(db, v_c66, &ok939);
                    if (!ok939) return;
                    u64 v_c177 = _prim_llen(db, v_c176);
                    if (v_c177 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c165 != v_c177) return;
                    bool ok940 = true;
                    u64 v_c178 = _prim_lref(db, v_c176, v_c166, &ok940);
                    if (!ok940) return;
                    if (v_c172 != v_c178) return;
                    bool ok941 = true;
                    u64 v_c179 = _prim_lref(db, v_c176, v_c167, &ok941);
                    if (!ok941) return;
                    if (v_c172 != v_c179) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c173});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c174}, std::array<u16,2>{1, 0});
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
        ReadTask909* _cont = new ReadTask909(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask909(db,b), false);
  // (crule (pre (let _00024sqc7OdC529 const5feceb66ffc86f38d952786c) (let __t8vFN64 (lempty))) (scan eval_args __t2WEx65 _00024seq0 c) (body (letp _00024sql7huw527 (aslst _00024seq0)) (let chk5o0E869 (llen _00024sql7huw527)) (eq _00024sqc7OdC529 chk5o0E869)) (head (emit-temp temp4QUn868 __t2WEx65 __t8vFN64)) interp.slog:37 #f)
  class ReadTask942 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4QUn868");
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask942(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c180 = v_const5feceb66ffc86f38d952786c;
      u64 v_c181 = _prim_lempty(db);
      if (v_c181 == slog_error) { slog::emit_pending_error(db, "interp.slog:37"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c182 = _t[0];
        u64 v_c98 = _t[1];
        u64 v_c4 = _t[2];
        bool ok943 = true;
        u64 v_c183 = _prim_aslst(db, v_c98, &ok943);
        if (!ok943) return;
        u64 v_c184 = _prim_llen(db, v_c183);
        if (v_c184 == slog_error) { slog::emit_pending_error(db, "interp.slog:37"); return; }
        if (v_c180 != v_c184) return;
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c182, v_c181});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:37", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask942* _cont = new ReadTask942(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask942(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1)) (scan temp24NP880 __t8DFh329) (body (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join boolval (1 0) 1 __t44Xg326 __t5zQU327)) (head (emit delta_ans (0 1) __t8DFh329 __t5zQU327)) interp.slog:117 #f)
  class ReadTask946 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex944;  slog::Index** boolvalindex945;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord947({0, 1});
      slog::Relation* readrel948 = db->getRelation("delta_ans");
      head_index[0] = readrel948->getIndex(ord947, false);
      outer_rel = db->getRelation("temp24NP880");
      std::vector<u16> ord949({1, 0});
      slog::Relation* readrel950 = db->getRelation("_enum");
      _enumindex944 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 0});
      slog::Relation* readrel952 = db->getRelation("boolval");
      boolvalindex945 = readrel952->getIndex(ord951, false);
  
    }
    ReadTask946(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c173 = _t[0];
        slog::join_probe<2,1>(_enumindex944, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m953) {
          u64 v_c174 = m953[1];
          slog::join_probe<2,1>(boolvalindex945, std::array<u64,2>{v_c174, 0}, [&](const std::array<u64,2>& m954) {
            u64 v_c185 = m954[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c173, v_c185}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:temp24NP880", _fires);
  
      if (!_done)
      {
        ReadTask946* _cont = new ReadTask946(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask946(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan eval_args_ans __t5lLk381 __v1) (body (exists $seq_at (1 0 2) 1 _00024sqo7QcU434) (join-old eval_args (0 2 1) 1 (0 2 1) __t5lLk381 c es) (exists eval_args (2 0 1) 1 c) (exists eval (2 0 1) 1 c) (join-old $sup56712x37x0x0x0 (2 4 0 1 3) 2 (2 4 0 1 3) c es _00024seq0 __t1ye1379 e) (join-old eval_args (0 2 1) 3 (0 2 1) __t1ye1379 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7QcU434 e _00024seq0) (join-old eval (1 2 0) 2 (1 2 0) e c __t33Oa380) (join eval_ans (0 1) 1 __t33Oa380 __v0) (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (letp chk21Zy937 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk21Zy937) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let chk9ddz938 (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (eq es chk9ddz938)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask969 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex955;  slog::Index** eval_argsindex956;  slog::Index** eval_argsindex957;  slog::Index** evalindex958;  slog::Index** $sup56712x37x0x0x0index959;  slog::Index** eval_argsindex960;  slog::Index** $seq_atindex961;  slog::Index** evalindex962;  slog::Index** eval_ansindex963;  slog::Index** eval_argsdelta964;  slog::Index** $sup56712x37x0x0x0delta965;  slog::Index** eval_argsdelta966;  slog::Index** $seq_atdelta967;  slog::Index** evaldelta968;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord970({1, 0, 2});
      slog::Relation* readrel971 = db->getRelation("$seq_at");
      $seq_atindex955 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 2, 1});
      slog::Relation* readrel973 = db->getRelation("eval_args");
      eval_argsindex956 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({0, 2, 1});
      slog::Relation* readrel975 = db->getRelation("eval_args");
      eval_argsdelta964 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({2, 0, 1});
      slog::Relation* readrel977 = db->getRelation("eval_args");
      eval_argsindex957 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({2, 0, 1});
      slog::Relation* readrel979 = db->getRelation("eval");
      evalindex958 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({2, 4, 0, 1, 3});
      slog::Relation* readrel981 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index959 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({2, 4, 0, 1, 3});
      slog::Relation* readrel983 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0delta965 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({0, 2, 1});
      slog::Relation* readrel985 = db->getRelation("eval_args");
      eval_argsindex960 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({0, 2, 1});
      slog::Relation* readrel987 = db->getRelation("eval_args");
      eval_argsdelta966 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({1, 0, 2});
      slog::Relation* readrel989 = db->getRelation("$seq_at");
      $seq_atindex961 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({1, 0, 2});
      slog::Relation* readrel991 = db->getRelation("$seq_at");
      $seq_atdelta967 = readrel991->getIndex(ord990, true);
      std::vector<u16> ord992({1, 2, 0});
      slog::Relation* readrel993 = db->getRelation("eval");
      evalindex962 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({1, 2, 0});
      slog::Relation* readrel995 = db->getRelation("eval");
      evaldelta968 = readrel995->getIndex(ord994, true);
      std::vector<u16> ord996({0, 1});
      slog::Relation* readrel997 = db->getRelation("eval_ans");
      eval_ansindex963 = readrel997->getIndex(ord996, false);
  
    }
    ReadTask969(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c186 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c187 = v_const5feceb66ffc86f38d952786c;
      u64 v_c188 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = _prim_lempty(db);
      if (v_c82 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c191 = _t[0];
        u64 v_c83 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex955, std::array<u64,3>{v_c190, 0, 0})) return;
        slog::join_probe_old<3,1>(eval_argsindex956, eval_argsdelta964, std::array<u64,3>{v_c191, 0, 0}, [&](const std::array<u64,3>& m998) {
          u64 v_c4 = m998[1]; u64 v_c15 = m998[2];
          if (!slog::exists_probe<3,1>(eval_argsindex957, std::array<u64,3>{v_c4, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex958, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x37x0x0x0index959, $sup56712x37x0x0x0delta965, std::array<u64,5>{v_c4, v_c15, 0, 0, 0}, [&](const std::array<u64,5>& m999) {
            u64 v_c98 = m999[2]; u64 v_c0 = m999[3]; u64 v_c27 = m999[4];
            slog::join_probe_old<3,3>(eval_argsindex960, eval_argsdelta966, std::array<u64,3>{v_c0, v_c4, v_c98}, [&](const std::array<u64,3>& m1000) {
              slog::join_probe_old<3,3>($seq_atindex961, $seq_atdelta967, std::array<u64,3>{v_c190, v_c27, v_c98}, [&](const std::array<u64,3>& m1001) {
                slog::join_probe_old<3,2>(evalindex962, evaldelta968, std::array<u64,3>{v_c27, v_c4, 0}, [&](const std::array<u64,3>& m1002) {
                  u64 v_c192 = m1002[2];
                  slog::join_probe<2,1>(eval_ansindex963, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m1003) {
                    u64 v_c21 = m1003[1];
                    bool ok1004 = true;
                    u64 v_c193 = _prim_aslst(db, v_c98, &ok1004);
                    if (!ok1004) return;
                    u64 v_c194 = _prim_llen(db, v_c193);
                    if (v_c194 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c195 = _prim_ge(db, v_c194, v_c186);
                    if (v_c195 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c195) return;
                    bool ok1006 = true;
                    u64 v_c196 = _prim_lref(db, v_c193, v_c187, &ok1006);
                    if (!ok1006) return;
                    if (v_c27 != v_c196) return;
                    u64 v_c197 = _prim__0002d(db, v_c194, v_c189);
                    if (v_c197 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c198 = _prim_lslice(db, v_c193, v_c188, v_c197);
                    if (v_c198 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c15 != v_c198) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c82, v_c21, v_c83});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask969* _cont = new ReadTask969(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask969(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo8e4d479 __t5NWC164 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5t7q477 __t5NWC164 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo2Tf4478 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo87UW480 __t5NWC164 _00024seq2) (exists _enum (1 0) 1 __tconst0GOL695) (join delta (1 2 0) 2 __tconst6e36161 _00024seq2 __t2Zbc162) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join prim (0 1) 1 __t5NWC164 op) (letp _00024sql8XpT472 (aslst _00024seq2)) (let chk75Ec984 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk75Ec984) (letp chk9648985 (lref _00024sql8XpT472 _00024sqc8EM3475)) (eq __t5NWC164 chk9648985) (letp chk2oh4986 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk2oh4986)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask1015 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1007;  slog::Index** $seq_atindex1008;  slog::Index** $seq_atrindex1009;  slog::Index** _enumindex1010;  slog::Index** deltaindex1011;  slog::Index** _enumindex1012;  slog::Index** primindex1013;  slog::Index** $seq_atrdelta1014;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1016({1, 0, 2});
      slog::Relation* readrel1017 = db->getRelation("$seq_atr");
      driver_index = readrel1017->getIndex(ord1016, true);
      std::vector<u16> ord1018({1, 0, 2});
      slog::Relation* readrel1019 = db->getRelation("$seq_at");
      $seq_atindex1007 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 0, 2});
      slog::Relation* readrel1021 = db->getRelation("$seq_at");
      $seq_atindex1008 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 0, 2});
      slog::Relation* readrel1023 = db->getRelation("$seq_atr");
      $seq_atrindex1009 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 0, 2});
      slog::Relation* readrel1025 = db->getRelation("$seq_atr");
      $seq_atrdelta1014 = readrel1025->getIndex(ord1024, true);
      std::vector<u16> ord1026({1, 0});
      slog::Relation* readrel1027 = db->getRelation("_enum");
      _enumindex1010 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 2, 0});
      slog::Relation* readrel1029 = db->getRelation("delta");
      deltaindex1011 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 0});
      slog::Relation* readrel1031 = db->getRelation("_enum");
      _enumindex1012 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({0, 1});
      slog::Relation* readrel1033 = db->getRelation("prim");
      primindex1013 = readrel1033->getIndex(ord1032, false);
  
    }
    ReadTask1015(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c199 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c200 = v_const06abaa100ecef791ce028c56;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const5feceb66ffc86f38d952786c;
      u64 v_c203 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c204 = v_const5feceb66ffc86f38d952786c;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c206, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1034) {
        u64 v_c208 = m1034[1];
        u64 v_c66 = m1034[2];
        if (buckethash(v_c208) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1007, std::array<u64,3>{v_c204, v_c208, v_c66}, [&](const std::array<u64,3>& m1035) {
          slog::join_probe<3,3>($seq_atindex1008, std::array<u64,3>{v_c205, v_c208, v_c66}, [&](const std::array<u64,3>& m1036) {
            slog::join_probe_old<3,3>($seq_atrindex1009, $seq_atrdelta1014, std::array<u64,3>{v_c207, v_c208, v_c66}, [&](const std::array<u64,3>& m1037) {
              if (!slog::exists_probe<2,1>(_enumindex1010, std::array<u64,2>{v_c199, 0})) return;
              slog::join_probe<3,2>(deltaindex1011, std::array<u64,3>{v_c200, v_c66, 0}, [&](const std::array<u64,3>& m1038) {
                u64 v_c209 = m1038[2];
                slog::join_probe<2,1>(_enumindex1012, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1039) {
                  u64 v_c210 = m1039[1];
                  slog::join_probe<2,1>(primindex1013, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m1040) {
                    u64 v_c47 = m1040[1];
                    bool ok1041 = true;
                    u64 v_c211 = _prim_aslst(db, v_c66, &ok1041);
                    if (!ok1041) return;
                    u64 v_c212 = _prim_llen(db, v_c211);
                    if (v_c212 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c201 != v_c212) return;
                    bool ok1042 = true;
                    u64 v_c213 = _prim_lref(db, v_c211, v_c202, &ok1042);
                    if (!ok1042) return;
                    if (v_c208 != v_c213) return;
                    bool ok1043 = true;
                    u64 v_c214 = _prim_lref(db, v_c211, v_c203, &ok1043);
                    if (!ok1043) return;
                    if (v_c208 != v_c214) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c209});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c210}, std::array<u16,2>{1, 0});
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
        ReadTask1015* _cont = new ReadTask1015(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1015(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5t7q477 __t5NWC164 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2Tf4478 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8e4d479 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo87UW480 __t5NWC164 _00024seq2) (exists _enum (1 0) 1 __tconst0GOL695) (join delta (1 2 0) 2 __tconst6e36161 _00024seq2 __t2Zbc162) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join prim (0 1) 1 __t5NWC164 op) (letp _00024sql8XpT472 (aslst _00024seq2)) (let chk6bIZ978 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk6bIZ978) (letp chk5mPa979 (lref _00024sql8XpT472 _00024sqc8EM3475)) (eq __t5NWC164 chk5mPa979) (letp chk7lSj980 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk7lSj980)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask1054 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1044;  slog::Index** $seq_atrindex1045;  slog::Index** $seq_atrindex1046;  slog::Index** _enumindex1047;  slog::Index** deltaindex1048;  slog::Index** _enumindex1049;  slog::Index** primindex1050;  slog::Index** $seq_atdelta1051;  slog::Index** $seq_atrdelta1052;  slog::Index** $seq_atrdelta1053;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1055({1, 0, 2});
      slog::Relation* readrel1056 = db->getRelation("$seq_at");
      driver_index = readrel1056->getIndex(ord1055, true);
      std::vector<u16> ord1057({1, 0, 2});
      slog::Relation* readrel1058 = db->getRelation("$seq_at");
      $seq_atindex1044 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 0, 2});
      slog::Relation* readrel1060 = db->getRelation("$seq_at");
      $seq_atdelta1051 = readrel1060->getIndex(ord1059, true);
      std::vector<u16> ord1061({1, 0, 2});
      slog::Relation* readrel1062 = db->getRelation("$seq_atr");
      $seq_atrindex1045 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 0, 2});
      slog::Relation* readrel1064 = db->getRelation("$seq_atr");
      $seq_atrdelta1052 = readrel1064->getIndex(ord1063, true);
      std::vector<u16> ord1065({1, 0, 2});
      slog::Relation* readrel1066 = db->getRelation("$seq_atr");
      $seq_atrindex1046 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({1, 0, 2});
      slog::Relation* readrel1068 = db->getRelation("$seq_atr");
      $seq_atrdelta1053 = readrel1068->getIndex(ord1067, true);
      std::vector<u16> ord1069({1, 0});
      slog::Relation* readrel1070 = db->getRelation("_enum");
      _enumindex1047 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({1, 2, 0});
      slog::Relation* readrel1072 = db->getRelation("delta");
      deltaindex1048 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 0});
      slog::Relation* readrel1074 = db->getRelation("_enum");
      _enumindex1049 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({0, 1});
      slog::Relation* readrel1076 = db->getRelation("prim");
      primindex1050 = readrel1076->getIndex(ord1075, false);
  
    }
    ReadTask1054(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c199 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c200 = v_const06abaa100ecef791ce028c56;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const5feceb66ffc86f38d952786c;
      u64 v_c203 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c204 = v_const5feceb66ffc86f38d952786c;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c204, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1077) {
        u64 v_c208 = m1077[1];
        u64 v_c66 = m1077[2];
        if (buckethash(v_c208) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1044, $seq_atdelta1051, std::array<u64,3>{v_c205, v_c208, v_c66}, [&](const std::array<u64,3>& m1078) {
          slog::join_probe_old<3,3>($seq_atrindex1045, $seq_atrdelta1052, std::array<u64,3>{v_c206, v_c208, v_c66}, [&](const std::array<u64,3>& m1079) {
            slog::join_probe_old<3,3>($seq_atrindex1046, $seq_atrdelta1053, std::array<u64,3>{v_c207, v_c208, v_c66}, [&](const std::array<u64,3>& m1080) {
              if (!slog::exists_probe<2,1>(_enumindex1047, std::array<u64,2>{v_c199, 0})) return;
              slog::join_probe<3,2>(deltaindex1048, std::array<u64,3>{v_c200, v_c66, 0}, [&](const std::array<u64,3>& m1081) {
                u64 v_c209 = m1081[2];
                slog::join_probe<2,1>(_enumindex1049, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1082) {
                  u64 v_c210 = m1082[1];
                  slog::join_probe<2,1>(primindex1050, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m1083) {
                    u64 v_c47 = m1083[1];
                    bool ok1084 = true;
                    u64 v_c211 = _prim_aslst(db, v_c66, &ok1084);
                    if (!ok1084) return;
                    u64 v_c215 = _prim_llen(db, v_c211);
                    if (v_c215 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c201 != v_c215) return;
                    bool ok1085 = true;
                    u64 v_c216 = _prim_lref(db, v_c211, v_c202, &ok1085);
                    if (!ok1085) return;
                    if (v_c208 != v_c216) return;
                    bool ok1086 = true;
                    u64 v_c217 = _prim_lref(db, v_c211, v_c203, &ok1086);
                    if (!ok1086) return;
                    if (v_c208 != v_c217) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c209});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c210}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1054* _cont = new ReadTask1054(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1054(db,b), false);
  // (crule (pre) (scan tick __t0NvE30 __t3Fr129 c) (body (exists tick_ans (0 1) 1 __t0NvE30) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t3Fr129 c __64BN675) (join tick_ans (0 1) 1 __t0NvE30 l) (join eval (2 0 1) 1 c __t84Ji24 ef) (exists eval_ans (0 1) 1 __t84Ji24) (join app (0 1 2) 2 __t3Fr129 ef es) (join eval_args (1 2 0) 2 es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join closure (0 1 2) 1 __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join lambda (0 1 2) 1 __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex1087;  slog::Index** evalindex1088;  slog::Index** eval_argsindex1089;  slog::Index** evalindex1090;  slog::Index** tick_ansindex1091;  slog::Index** evalindex1092;  slog::Index** eval_ansindex1093;  slog::Index** appindex1094;  slog::Index** eval_argsindex1095;  slog::Index** eval_args_ansindex1096;  slog::Index** eval_ansindex1097;  slog::Index** eval_args_ansindex1098;  slog::Index** closureindex1099;  slog::Index** bindingindex1100;  slog::Index** freevarindex1101;  slog::Index** bindingindex1102;  slog::Index** lambdaindex1103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1105({0, 1, 2});
      slog::Relation* readrel1106 = db->getRelation("binding");
      head_index[0] = readrel1106->getIndex(ord1105, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1107({0, 1, 2});
      slog::Relation* readrel1108 = db->getRelation("binding_event");
      head_index[1] = readrel1108->getIndex(ord1107, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1109({0, 1});
      slog::Relation* readrel1110 = db->getRelation("tick_ans");
      tick_ansindex1087 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 0, 1});
      slog::Relation* readrel1112 = db->getRelation("eval");
      evalindex1088 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({2, 0, 1});
      slog::Relation* readrel1114 = db->getRelation("eval_args");
      eval_argsindex1089 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({1, 2, 0});
      slog::Relation* readrel1116 = db->getRelation("eval");
      evalindex1090 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({0, 1});
      slog::Relation* readrel1118 = db->getRelation("tick_ans");
      tick_ansindex1091 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({2, 0, 1});
      slog::Relation* readrel1120 = db->getRelation("eval");
      evalindex1092 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({0, 1});
      slog::Relation* readrel1122 = db->getRelation("eval_ans");
      eval_ansindex1093 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({0, 1, 2});
      slog::Relation* readrel1124 = db->getRelation("app");
      appindex1094 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("eval_args");
      eval_argsindex1095 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({0, 1});
      slog::Relation* readrel1128 = db->getRelation("eval_args_ans");
      eval_args_ansindex1096 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({0, 1});
      slog::Relation* readrel1130 = db->getRelation("eval_ans");
      eval_ansindex1097 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 1});
      slog::Relation* readrel1132 = db->getRelation("eval_args_ans");
      eval_args_ansindex1098 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({0, 1, 2});
      slog::Relation* readrel1134 = db->getRelation("closure");
      closureindex1099 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 0, 2});
      slog::Relation* readrel1136 = db->getRelation("binding");
      bindingindex1100 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 0});
      slog::Relation* readrel1138 = db->getRelation("freevar");
      freevarindex1101 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({0, 1, 2});
      slog::Relation* readrel1140 = db->getRelation("binding");
      bindingindex1102 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({0, 1, 2});
      slog::Relation* readrel1142 = db->getRelation("lambda");
      lambdaindex1103 = readrel1142->getIndex(ord1141, false);
  
    }
    ReadTask1104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex1087, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1088, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1089, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,2>(evalindex1090, std::array<u64,3>{v_c34, v_c4, 0}, [&](const std::array<u64,3>& m1143) {
          u64 v_c33 = m1143[2];
          slog::join_probe<2,1>(tick_ansindex1091, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1144) {
            u64 v_c37 = m1144[1];
            slog::join_probe<3,1>(evalindex1092, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m1145) {
              u64 v_c31 = m1145[1]; u64 v_c14 = m1145[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1093, std::array<u64,2>{v_c31, 0})) return;
              slog::join_probe<3,2>(appindex1094, std::array<u64,3>{v_c34, v_c14, 0}, [&](const std::array<u64,3>& m1146) {
                u64 v_c15 = m1146[2];
                slog::join_probe<3,2>(eval_argsindex1095, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m1147) {
                  u64 v_c35 = m1147[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1096, std::array<u64,2>{v_c35, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1097, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1148) {
                    u64 v_c32 = m1148[1];
                    slog::join_probe<2,1>(eval_args_ansindex1098, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m1149) {
                      u64 v_c20 = m1149[1];
                      slog::join_probe<3,1>(closureindex1099, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m1150) {
                        u64 v_c38 = m1150[1]; u64 v_c23 = m1150[2];
                        if (!slog::exists_probe<3,1>(bindingindex1100, std::array<u64,3>{v_c23, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex1101, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m1151) {
                          u64 v_c39 = m1151[1];
                          slog::join_probe<3,2>(bindingindex1102, std::array<u64,3>{v_c39, v_c23, 0}, [&](const std::array<u64,3>& m1152) {
                            u64 v_c40 = m1152[2];
                            slog::join_probe<3,1>(lambdaindex1103, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m1153) {
                              u64 v_c24 = m1153[1]; u64 v_c3 = m1153[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c39, v_c37, v_c40}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c39, v_c37, v_c4}, std::array<u16,3>{0, 1, 2});
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
        ReadTask1104* _cont = new ReadTask1104(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1104(db,b), false);
  // (crule (pre) (scan ref __t1fAc59 x) (body) (head (emit freevar (0 1) x __t1fAc59)) freevars.slog:11 #f)
  class ReadTask1154 : public slog::Task
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
      std::vector<u16> ord1155({0, 1});
      slog::Relation* readrel1156 = db->getRelation("freevar");
      head_index[0] = readrel1156->getIndex(ord1155, false);
      outer_rel = db->getRelation("ref");
  
    }
    ReadTask1154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c218 = _t[0];
        u64 v_c7 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c218}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:11", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1154* _cont = new ReadTask1154(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1154(db,b), false);
  // (crule (pre) (scan tick_ans __t3nAR325 l) (body (join-old tick (0 2 1) 1 (0 2 1) __t3nAR325 c __t9nj7324) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t9nj7324 c __5izx673) (join-old eval (2 0 1) 1 (2 0 1) c __t550i320 ef) (exists eval_ans (0 1) 1 __t550i320) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join-old closure (0 1 2) 1 (0 1 2) __t2qAJ322 __t7ycN321 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex1157;  slog::Index** evalindex1158;  slog::Index** eval_argsindex1159;  slog::Index** evalindex1160;  slog::Index** evalindex1161;  slog::Index** eval_ansindex1162;  slog::Index** appindex1163;  slog::Index** eval_argsindex1164;  slog::Index** eval_args_ansindex1165;  slog::Index** eval_ansindex1166;  slog::Index** eval_args_ansindex1167;  slog::Index** closureindex1168;  slog::Index** lambdaindex1169;  slog::Index** tickdelta1170;  slog::Index** evaldelta1171;  slog::Index** appdelta1172;  slog::Index** eval_argsdelta1173;  slog::Index** closuredelta1174;  slog::Index** lambdadelta1175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1177({0, 1, 2, 3});
      slog::Relation* readrel1178 = db->getRelation("bind_params");
      head_index[0] = readrel1178->getIndex(ord1177, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("call_event");
      head_index[1] = readrel1180->getIndex(ord1179, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord1181({0, 2, 1});
      slog::Relation* readrel1182 = db->getRelation("tick");
      tickindex1157 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({0, 2, 1});
      slog::Relation* readrel1184 = db->getRelation("tick");
      tickdelta1170 = readrel1184->getIndex(ord1183, true);
      std::vector<u16> ord1185({2, 0, 1});
      slog::Relation* readrel1186 = db->getRelation("eval");
      evalindex1158 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({2, 0, 1});
      slog::Relation* readrel1188 = db->getRelation("eval_args");
      eval_argsindex1159 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 2, 0});
      slog::Relation* readrel1190 = db->getRelation("eval");
      evalindex1160 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({2, 0, 1});
      slog::Relation* readrel1192 = db->getRelation("eval");
      evalindex1161 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({2, 0, 1});
      slog::Relation* readrel1194 = db->getRelation("eval");
      evaldelta1171 = readrel1194->getIndex(ord1193, true);
      std::vector<u16> ord1195({0, 1});
      slog::Relation* readrel1196 = db->getRelation("eval_ans");
      eval_ansindex1162 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({0, 1, 2});
      slog::Relation* readrel1198 = db->getRelation("app");
      appindex1163 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({0, 1, 2});
      slog::Relation* readrel1200 = db->getRelation("app");
      appdelta1172 = readrel1200->getIndex(ord1199, true);
      std::vector<u16> ord1201({1, 2, 0});
      slog::Relation* readrel1202 = db->getRelation("eval_args");
      eval_argsindex1164 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({1, 2, 0});
      slog::Relation* readrel1204 = db->getRelation("eval_args");
      eval_argsdelta1173 = readrel1204->getIndex(ord1203, true);
      std::vector<u16> ord1205({0, 1});
      slog::Relation* readrel1206 = db->getRelation("eval_args_ans");
      eval_args_ansindex1165 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({0, 1});
      slog::Relation* readrel1208 = db->getRelation("eval_ans");
      eval_ansindex1166 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({0, 1});
      slog::Relation* readrel1210 = db->getRelation("eval_args_ans");
      eval_args_ansindex1167 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({0, 1, 2});
      slog::Relation* readrel1212 = db->getRelation("closure");
      closureindex1168 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({0, 1, 2});
      slog::Relation* readrel1214 = db->getRelation("closure");
      closuredelta1174 = readrel1214->getIndex(ord1213, true);
      std::vector<u16> ord1215({0, 1, 2});
      slog::Relation* readrel1216 = db->getRelation("lambda");
      lambdaindex1169 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({0, 1, 2});
      slog::Relation* readrel1218 = db->getRelation("lambda");
      lambdadelta1175 = readrel1218->getIndex(ord1217, true);
  
    }
    ReadTask1176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c219 = _t[0];
        u64 v_c37 = _t[1];
        slog::join_probe_old<3,1>(tickindex1157, tickdelta1170, std::array<u64,3>{v_c219, 0, 0}, [&](const std::array<u64,3>& m1219) {
          u64 v_c4 = m1219[1]; u64 v_c220 = m1219[2];
          if (!slog::exists_probe<3,1>(evalindex1158, std::array<u64,3>{v_c4, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex1159, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe<3,2>(evalindex1160, std::array<u64,3>{v_c220, v_c4, 0}, [&](const std::array<u64,3>& m1220) {
            u64 v_c221 = m1220[2];
            slog::join_probe_old<3,1>(evalindex1161, evaldelta1171, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m1221) {
              u64 v_c222 = m1221[1]; u64 v_c14 = m1221[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1162, std::array<u64,2>{v_c222, 0})) return;
              slog::join_probe_old<3,2>(appindex1163, appdelta1172, std::array<u64,3>{v_c220, v_c14, 0}, [&](const std::array<u64,3>& m1222) {
                u64 v_c15 = m1222[2];
                slog::join_probe_old<3,2>(eval_argsindex1164, eval_argsdelta1173, std::array<u64,3>{v_c15, v_c4, 0}, [&](const std::array<u64,3>& m1223) {
                  u64 v_c223 = m1223[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1165, std::array<u64,2>{v_c223, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1166, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m1224) {
                    u64 v_c224 = m1224[1];
                    slog::join_probe<2,1>(eval_args_ansindex1167, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1225) {
                      u64 v_c20 = m1225[1];
                      slog::join_probe_old<3,1>(closureindex1168, closuredelta1174, std::array<u64,3>{v_c224, 0, 0}, [&](const std::array<u64,3>& m1226) {
                        u64 v_c225 = m1226[1]; u64 v_c23 = m1226[2];
                        slog::join_probe_old<3,1>(lambdaindex1169, lambdadelta1175, std::array<u64,3>{v_c225, 0, 0}, [&](const std::array<u64,3>& m1227) {
                          u64 v_c24 = m1227[1]; u64 v_c3 = m1227[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c24, v_c20, v_c37, v_c4}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c37, v_c4}, std::array<u16,2>{0, 1});
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
        ReadTask1176* _cont = new ReadTask1176(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1176(db,b), false);
  // (crule (pre) (scan let __t6Jt9132 y er eb) (body (join freevar (1 0) 1 eb x) (neq x y)) (head (emit freevar (0 1) x __t6Jt9132)) freevars.slog:22 #f)
  class ReadTask1229 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1228;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1230({0, 1});
      slog::Relation* readrel1231 = db->getRelation("freevar");
      head_index[0] = readrel1231->getIndex(ord1230, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord1232({1, 0});
      slog::Relation* readrel1233 = db->getRelation("freevar");
      freevarindex1228 = readrel1233->getIndex(ord1232, false);
  
    }
    ReadTask1229(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c3 = _t[3];
        slog::join_probe<2,1>(freevarindex1228, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1234) {
          u64 v_c7 = m1234[1];
          if (v_c7 == v_c39) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c226}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:22", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask1229* _cont = new ReadTask1229(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1229(db,b), false);
  // (crule (pre (let __tconst36mF602 constcd2a69ce5ca278db1d6da969) (let __tconst4MYs19 const06abaa100ecef791ce028c56) (let _00024sqc0R1w414 constd4735e3a265e16eee03f5971) (let _00024sqc2r3q415 const5feceb66ffc86f38d952786c) (let _00024sqc1pwY416 const6b86b273ff34fce19d6b804e) (let _00024sqo5Wc9417 const5feceb66ffc86f38d952786c) (let _00024sqo4N7A418 const6b86b273ff34fce19d6b804e) (let _00024sqo8u9a419 const6b86b273ff34fce19d6b804e) (let _00024sqo9jvY420 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo8u9a419 __t2nOL22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Wc9417 __t2nOL22 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo4N7A418 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9jvY420 __t2nOL22 _00024seq2) (join _enum (0 1) 2 __t2nOL22 __tconst36mF602) (join delta (1 2 0) 2 __tconst4MYs19 _00024seq2 __t9afR20) (join any_bool (0) 0 b) (letp _00024sql9osm412 (aslst _00024seq2)) (let chk0W8i853 (llen _00024sql9osm412)) (eq _00024sqc0R1w414 chk0W8i853) (letp chk8rlz854 (lref _00024sql9osm412 _00024sqc2r3q415)) (eq __t2nOL22 chk8rlz854) (letp chk3TlE855 (lref _00024sql9osm412 _00024sqc1pwY416)) (eq __t2nOL22 chk3TlE855)) (head (emit-temp temp4fHg844 __t9afR20 b) (mkstruct boolval (1 0) __t975c18 b)) interp.slog:121 #f)
  class ReadTask1242 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1235;  slog::Index** $seq_atindex1236;  slog::Index** $seq_atrindex1237;  slog::Index** _enumindex1238;  slog::Index** deltaindex1239;  slog::Index** any_boolindex1240;  slog::Index** $seq_atrdelta1241;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4fHg844");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1243({1, 0, 2});
      slog::Relation* readrel1244 = db->getRelation("$seq_atr");
      driver_index = readrel1244->getIndex(ord1243, true);
      std::vector<u16> ord1245({1, 0, 2});
      slog::Relation* readrel1246 = db->getRelation("$seq_at");
      $seq_atindex1235 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({1, 0, 2});
      slog::Relation* readrel1248 = db->getRelation("$seq_at");
      $seq_atindex1236 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 0, 2});
      slog::Relation* readrel1250 = db->getRelation("$seq_atr");
      $seq_atrindex1237 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 0, 2});
      slog::Relation* readrel1252 = db->getRelation("$seq_atr");
      $seq_atrdelta1241 = readrel1252->getIndex(ord1251, true);
      std::vector<u16> ord1253({0, 1});
      slog::Relation* readrel1254 = db->getRelation("_enum");
      _enumindex1238 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("delta");
      deltaindex1239 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({0});
      slog::Relation* readrel1258 = db->getRelation("any_bool");
      any_boolindex1240 = readrel1258->getIndex(ord1257, false);
  
    }
    ReadTask1242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c227 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c228 = v_const06abaa100ecef791ce028c56;
      u64 v_c229 = v_constd4735e3a265e16eee03f5971;
      u64 v_c230 = v_const5feceb66ffc86f38d952786c;
      u64 v_c231 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c232 = v_const5feceb66ffc86f38d952786c;
      u64 v_c233 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c234 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c235 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c234, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1259) {
        u64 v_c236 = m1259[1];
        u64 v_c66 = m1259[2];
        if (buckethash(v_c236) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1235, std::array<u64,3>{v_c232, v_c236, v_c66}, [&](const std::array<u64,3>& m1260) {
          slog::join_probe<3,3>($seq_atindex1236, std::array<u64,3>{v_c233, v_c236, v_c66}, [&](const std::array<u64,3>& m1261) {
            slog::join_probe_old<3,3>($seq_atrindex1237, $seq_atrdelta1241, std::array<u64,3>{v_c235, v_c236, v_c66}, [&](const std::array<u64,3>& m1262) {
              slog::join_probe<2,2>(_enumindex1238, std::array<u64,2>{v_c236, v_c227}, [&](const std::array<u64,2>& m1263) {
                slog::join_probe<3,2>(deltaindex1239, std::array<u64,3>{v_c228, v_c66, 0}, [&](const std::array<u64,3>& m1264) {
                  u64 v_c237 = m1264[2];
                  slog::join_all<1>(any_boolindex1240, [&](const std::array<u64,1>& m1265) {
                    u64 v_c69 = m1265[0];
                    bool ok1266 = true;
                    u64 v_c238 = _prim_aslst(db, v_c66, &ok1266);
                    if (!ok1266) return;
                    u64 v_c239 = _prim_llen(db, v_c238);
                    if (v_c239 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c229 != v_c239) return;
                    bool ok1267 = true;
                    u64 v_c240 = _prim_lref(db, v_c238, v_c230, &ok1267);
                    if (!ok1267) return;
                    if (v_c236 != v_c240) return;
                    bool ok1268 = true;
                    u64 v_c241 = _prim_lref(db, v_c238, v_c231, &ok1268);
                    if (!ok1268) return;
                    if (v_c236 != v_c241) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c237, v_c69});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c69}, std::array<u16,2>{1, 0});
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
        ReadTask1242* _cont = new ReadTask1242(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1242(db,b), false);
  // (crule (pre (let __trid7PeB576 constea10b8ee9cd346b11a382114) (let __trel3f5b577 const4a59dbb9cb3129dfcc75170b) (let __tcol4qZI578 const5feceb66ffc86f38d952786c) (let __trel1NqC579 const4a59dbb9cb3129dfcc75170b) (let __tcol6aw3580 const6b86b273ff34fce19d6b804e)) (scan $sup56712x37x0x0x0 _00024seq0 __d0 c e es) (body) (head (tycheck e (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid7PeB576 __trel3f5b577 __tcol4qZI578 (1 2 3 4 0)) (tycheck c (accept seq) __trid7PeB576 __trel1NqC579 __tcol6aw3580 (1 2 3 4 0)) (mkstruct eval (1 2 0) __4bPz575 e c)) interp.slog:38 #f)
  class ReadTask1278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1269;  u32 sid1270;  u32 sid1271;  u32 sid1272;  u32 sid1273;  u32 sid1274;  u32 sid1275;  u32 sid1276;  u32 sid1277;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x37x0x0x0");
      sid1269 = db->getRelation("app")->getStructId();
      sid1270 = db->getRelation("boolean")->getStructId();
      sid1271 = db->getRelation("if")->getStructId();
      sid1272 = db->getRelation("lambda")->getStructId();
      sid1273 = db->getRelation("let")->getStructId();
      sid1274 = db->getRelation("letrec")->getStructId();
      sid1275 = db->getRelation("num")->getStructId();
      sid1276 = db->getRelation("ref")->getStructId();
      sid1277 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_constea10b8ee9cd346b11a382114;
      u64 v_c243 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
      u64 v_c245 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c98 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c15 = _t[4];
        ++_fires;
        if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid1269 || decode_struct_id(v_c27) == sid1270 || decode_struct_id(v_c27) == sid1271 || decode_struct_id(v_c27) == sid1272 || decode_struct_id(v_c27) == sid1273 || decode_struct_id(v_c27) == sid1274 || decode_struct_id(v_c27) == sid1275 || decode_struct_id(v_c27) == sid1276 || decode_struct_id(v_c27) == sid1277))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c242, v_c243, v_c244, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c242, v_c245, v_c246, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c27, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$sup56712x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1278* _cont = new ReadTask1278(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1278(db,b), false);
  // (crule (pre (let __trid5o8l590 const5963fd3eff55776ca49412c5) (let __trel2EVD591 conste90c92f3e6c3b47a7bc93e42) (let __tcol07vh592 const5feceb66ffc86f38d952786c) (let __trel6eeN593 conste90c92f3e6c3b47a7bc93e42) (let __tcol1EhY594 const6b86b273ff34fce19d6b804e)) (scan $sup56712x74x0x0x0 __d0 c ef es) (body) (head (tycheck es (accept seq) __trid5o8l590 __trel2EVD591 __tcol07vh592 (1 2 3 4 0)) (tycheck c (accept seq) __trid5o8l590 __trel6eeN593 __tcol1EhY594 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __4tF4589 es c)) interp.slog:75 #f)
  class ReadTask1279 : public slog::Task
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
    ReadTask1279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c247 = v_const5963fd3eff55776ca49412c5;
      u64 v_c248 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c249 = v_const5feceb66ffc86f38d952786c;
      u64 v_c250 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c251 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c16 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        ++_fires;
        if (!(is_seq(v_c15)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c247, v_c248, v_c249, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c247, v_c250, v_c251, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c15, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1279* _cont = new ReadTask1279(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1279(db,b), false);
  // (crule (pre (let __trid1NvW690 constea10b8ee9cd346b11a382114) (let __trel1vpR691 conste90c92f3e6c3b47a7bc93e42) (let __tcol93No692 const5feceb66ffc86f38d952786c) (let __trel8xiT693 conste90c92f3e6c3b47a7bc93e42) (let __tcol4VSG694 const6b86b273ff34fce19d6b804e)) (scan $sup56712x37x0x0x0 _00024seq0 __d0 c e es) (body) (head (tycheck es (accept seq) __trid1NvW690 __trel1vpR691 __tcol93No692 (1 2 3 4 0)) (tycheck c (accept seq) __trid1NvW690 __trel8xiT693 __tcol4VSG694 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __5be8689 es c)) interp.slog:38 #f)
  class ReadTask1280 : public slog::Task
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
    ReadTask1280(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c252 = v_constea10b8ee9cd346b11a382114;
      u64 v_c253 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c254 = v_const5feceb66ffc86f38d952786c;
      u64 v_c255 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c256 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c98 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c15 = _t[4];
        ++_fires;
        if (!(is_seq(v_c15)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c252, v_c253, v_c254, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c252, v_c255, v_c256, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c15, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$sup56712x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1280* _cont = new ReadTask1280(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1280(db,b), false);
  // (crule (pre) (scan app __t89GZ358 ef es) (body (join eval (1 2 0) 1 __t89GZ358 c __2M2m643)) (head (mkstruct tick (1 2 0) __5IkN644 __t89GZ358 c)) interp.slog:48 #f)
  class ReadTask1282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1283({1, 2, 0});
      slog::Relation* readrel1284 = db->getRelation("eval");
      evalindex1281 = readrel1284->getIndex(ord1283, false);
  
    }
    ReadTask1282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c257 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe<3,1>(evalindex1281, std::array<u64,3>{v_c257, 0, 0}, [&](const std::array<u64,3>& m1285) {
          u64 v_c4 = m1285[1]; u64 v_c258 = m1285[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c257, v_c4}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1282* _cont = new ReadTask1282(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1282(db,b), false);
  // (crule (pre) (scan eval __2wtW609 __t5Orx186 c) (body (join-old app (0 1 2) 1 (0 1 2) __t5Orx186 ef es) (join-old freevar (0 1) 0 (0 1) y __t0Osl187) (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0Osl187 xs eb)) (head (mkstruct tick (1 2 0) __4U5c610 __t5Orx186 c)) interp.slog:56 #f)
  class ReadTask1294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1286;  slog::Index** freevarindex1287;  slog::Index** bindingindex1288;  slog::Index** lambdaindex1289;  slog::Index** appdelta1290;  slog::Index** freevardelta1291;  slog::Index** bindingdelta1292;  slog::Index** lambdadelta1293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1295({0, 1, 2});
      slog::Relation* readrel1296 = db->getRelation("app");
      appindex1286 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({0, 1, 2});
      slog::Relation* readrel1298 = db->getRelation("app");
      appdelta1290 = readrel1298->getIndex(ord1297, true);
      std::vector<u16> ord1299({0, 1});
      slog::Relation* readrel1300 = db->getRelation("freevar");
      freevarindex1287 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({0, 1});
      slog::Relation* readrel1302 = db->getRelation("freevar");
      freevardelta1291 = readrel1302->getIndex(ord1301, true);
      std::vector<u16> ord1303({0, 1, 2});
      slog::Relation* readrel1304 = db->getRelation("binding");
      bindingindex1288 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({0, 1, 2});
      slog::Relation* readrel1306 = db->getRelation("binding");
      bindingdelta1292 = readrel1306->getIndex(ord1305, true);
      std::vector<u16> ord1307({0, 1, 2});
      slog::Relation* readrel1308 = db->getRelation("lambda");
      lambdaindex1289 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1, 2});
      slog::Relation* readrel1310 = db->getRelation("lambda");
      lambdadelta1293 = readrel1310->getIndex(ord1309, true);
  
    }
    ReadTask1294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c259 = _t[0];
        u64 v_c260 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe_old<3,1>(appindex1286, appdelta1290, std::array<u64,3>{v_c260, 0, 0}, [&](const std::array<u64,3>& m1311) {
          u64 v_c14 = m1311[1]; u64 v_c15 = m1311[2];
          slog::join_all_old<2>(freevarindex1287, freevardelta1291, [&](const std::array<u64,2>& m1312) {
            u64 v_c39 = m1312[0]; u64 v_c261 = m1312[1];
            slog::join_probe_old<3,1>(bindingindex1288, bindingdelta1292, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m1313) {
              u64 v_c23 = m1313[1]; u64 v_c40 = m1313[2];
              slog::join_probe_old<3,1>(lambdaindex1289, lambdadelta1293, std::array<u64,3>{v_c261, 0, 0}, [&](const std::array<u64,3>& m1314) {
                u64 v_c24 = m1314[1]; u64 v_c3 = m1314[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c260, v_c4}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1294* _cont = new ReadTask1294(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1294(db,b), false);
}

