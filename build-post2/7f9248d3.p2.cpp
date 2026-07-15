
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const2bc983a5942276eb00a75e21;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const5963fd3eff55776ca49412c5;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const609d51837c7fc306b0cbb04a;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste6c67f7247161354cd7e1d34;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;


void slog_rules_ca08d4117d20484b2(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp46yO1034 __t4bAF20 b) (body (join boolval (1 0) 1 b __t6st618)) (head (emit delta_ans (0 1) __t4bAF20 __t6st618)) interp.slog:121 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("delta_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("temp46yO1034");
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("boolval");
      boolvalindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(boolvalindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m6) {
          u64 v_c2 = m6[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c2}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:temp46yO1034", _fires);
  
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
  // (crule (pre) (scan eval __t44Jo196 ef c) (body (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t44Jo196) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join tick_ans (0 1) 1 __t3z31201 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4ROj198 __t2BTJ197 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex7;  slog::Index** appindex8;  slog::Index** tickindex9;  slog::Index** eval_ansindex10;  slog::Index** $sup56712x41x0x0x0index11;  slog::Index** appindex12;  slog::Index** eval_argsindex13;  slog::Index** eval_args_ansindex14;  slog::Index** appindex15;  slog::Index** tickindex16;  slog::Index** tick_ansindex17;  slog::Index** eval_ansindex18;  slog::Index** eval_args_ansindex19;  slog::Index** tick_ansindex20;  slog::Index** closureindex21;  slog::Index** lambdaindex22;  slog::Index** eval_argsdelta23;  slog::Index** appdelta24;  slog::Index** tickdelta25;  slog::Index** closuredelta26;  slog::Index** lambdadelta27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord29({2, 0, 1});
      slog::Relation* readrel30 = db->getRelation("eval_args");
      eval_argsindex7 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("app");
      appindex8 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({2, 0, 1});
      slog::Relation* readrel34 = db->getRelation("tick");
      tickindex9 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("eval_ans");
      eval_ansindex10 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 3, 0});
      slog::Relation* readrel38 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index11 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("app");
      appindex12 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("eval_args");
      eval_argsindex13 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("eval_args");
      eval_argsdelta23 = readrel44->getIndex(ord43, true);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("eval_args_ans");
      eval_args_ansindex14 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("app");
      appindex15 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("app");
      appdelta24 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("tick");
      tickindex16 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("tick");
      tickdelta25 = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("tick_ans");
      tick_ansindex17 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("eval_ans");
      eval_ansindex18 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("eval_args_ans");
      eval_args_ansindex19 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("tick_ans");
      tick_ansindex20 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1, 2});
      slog::Relation* readrel64 = db->getRelation("closure");
      closureindex21 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1, 2});
      slog::Relation* readrel66 = db->getRelation("closure");
      closuredelta26 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({0, 1, 2});
      slog::Relation* readrel68 = db->getRelation("lambda");
      lambdaindex22 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0, 1, 2});
      slog::Relation* readrel70 = db->getRelation("lambda");
      lambdadelta27 = readrel70->getIndex(ord69, true);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex7, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex8, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex9, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex10, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index11, std::array<u64,4>{v_c5, v_c4, 0, 0}, [&](const std::array<u64,4>& m71) {
          u64 v_c6 = m71[2]; u64 v_c7 = m71[3];
          if (!slog::exists_probe<3,2>(appindex12, std::array<u64,3>{v_c4, v_c6, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex13, eval_argsdelta23, std::array<u64,3>{v_c6, v_c5, 0}, [&](const std::array<u64,3>& m72) {
            u64 v_c8 = m72[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex14, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe_old<3,2>(appindex15, appdelta24, std::array<u64,3>{v_c4, v_c6, 0}, [&](const std::array<u64,3>& m73) {
              u64 v_c9 = m73[2];
              slog::join_probe_old<3,2>(tickindex16, tickdelta25, std::array<u64,3>{v_c9, v_c5, 0}, [&](const std::array<u64,3>& m74) {
                u64 v_c10 = m74[2];
                if (!slog::exists_probe<2,1>(tick_ansindex17, std::array<u64,2>{v_c10, 0})) return;
                slog::join_probe<2,1>(eval_ansindex18, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m75) {
                  u64 v_c11 = m75[1];
                  slog::join_probe<2,1>(eval_args_ansindex19, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m76) {
                    u64 v_c12 = m76[1];
                    slog::join_probe<2,1>(tick_ansindex20, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m77) {
                      u64 v_c13 = m77[1];
                      slog::join_probe_old<3,1>(closureindex21, closuredelta26, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m78) {
                        u64 v_c14 = m78[1]; u64 v_c15 = m78[2];
                        slog::join_probe_old<3,1>(lambdaindex22, lambdadelta27, std::array<u64,3>{v_c14, 0, 0}, [&](const std::array<u64,3>& m79) {
                          u64 v_c16 = m79[1]; u64 v_c17 = m79[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c13}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre) (scan eval __t9B5D299 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join tick_ans (0 1) 1 __t5Pln304 l) (join-old closure (0 1 2) 1 (0 1 2) __t4ng7301 __t4mHn300 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex80;  slog::Index** appindex81;  slog::Index** eval_argsindex82;  slog::Index** tickindex83;  slog::Index** eval_ansindex84;  slog::Index** evalindex85;  slog::Index** tickindex86;  slog::Index** appindex87;  slog::Index** eval_argsindex88;  slog::Index** eval_args_ansindex89;  slog::Index** tickindex90;  slog::Index** tick_ansindex91;  slog::Index** eval_args_ansindex92;  slog::Index** tick_ansindex93;  slog::Index** closureindex94;  slog::Index** lambdaindex95;  slog::Index** appdelta96;  slog::Index** eval_argsdelta97;  slog::Index** tickdelta98;  slog::Index** closuredelta99;  slog::Index** lambdadelta100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord102({0, 1, 2, 3});
      slog::Relation* readrel103 = db->getRelation("bind_params");
      head_index[0] = readrel103->getIndex(ord102, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord104({0, 1});
      slog::Relation* readrel105 = db->getRelation("call_event");
      head_index[1] = readrel105->getIndex(ord104, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord106({2, 0, 1});
      slog::Relation* readrel107 = db->getRelation("eval");
      evalindex80 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("app");
      appindex81 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({2, 0, 1});
      slog::Relation* readrel111 = db->getRelation("eval_args");
      eval_argsindex82 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({2, 0, 1});
      slog::Relation* readrel113 = db->getRelation("tick");
      tickindex83 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("eval_ans");
      eval_ansindex84 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({2, 0, 1});
      slog::Relation* readrel117 = db->getRelation("eval");
      evalindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("tick");
      tickindex86 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({0, 1, 2});
      slog::Relation* readrel121 = db->getRelation("app");
      appindex87 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1, 2});
      slog::Relation* readrel123 = db->getRelation("app");
      appdelta96 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("eval_args");
      eval_argsindex88 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("eval_args");
      eval_argsdelta97 = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("eval_args_ans");
      eval_args_ansindex89 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("tick");
      tickindex90 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("tick");
      tickdelta98 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({0, 1});
      slog::Relation* readrel135 = db->getRelation("tick_ans");
      tick_ansindex91 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1});
      slog::Relation* readrel137 = db->getRelation("eval_args_ans");
      eval_args_ansindex92 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("tick_ans");
      tick_ansindex93 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1, 2});
      slog::Relation* readrel141 = db->getRelation("closure");
      closureindex94 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1, 2});
      slog::Relation* readrel143 = db->getRelation("closure");
      closuredelta99 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({0, 1, 2});
      slog::Relation* readrel145 = db->getRelation("lambda");
      lambdaindex95 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1, 2});
      slog::Relation* readrel147 = db->getRelation("lambda");
      lambdadelta100 = readrel147->getIndex(ord146, true);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex80, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex81, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex82, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex83, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex84, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m148) {
          u64 v_c19 = m148[1];
          slog::join_probe<3,1>(evalindex85, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m149) {
            u64 v_c20 = m149[1]; u64 v_c21 = m149[2];
            if (!slog::exists_probe<3,2>(tickindex86, std::array<u64,3>{v_c21, v_c5, 0})) return;
            slog::join_probe_old<3,2>(appindex87, appdelta96, std::array<u64,3>{v_c21, v_c4, 0}, [&](const std::array<u64,3>& m150) {
              u64 v_c6 = m150[2];
              slog::join_probe_old<3,2>(eval_argsindex88, eval_argsdelta97, std::array<u64,3>{v_c6, v_c5, 0}, [&](const std::array<u64,3>& m151) {
                u64 v_c22 = m151[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex89, std::array<u64,2>{v_c22, 0})) return;
                slog::join_probe_old<3,2>(tickindex90, tickdelta98, std::array<u64,3>{v_c21, v_c5, 0}, [&](const std::array<u64,3>& m152) {
                  u64 v_c23 = m152[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex91, std::array<u64,2>{v_c23, 0})) return;
                  slog::join_probe<2,1>(eval_args_ansindex92, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m153) {
                    u64 v_c12 = m153[1];
                    slog::join_probe<2,1>(tick_ansindex93, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m154) {
                      u64 v_c24 = m154[1];
                      slog::join_probe_old<3,1>(closureindex94, closuredelta99, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m155) {
                        u64 v_c25 = m155[1]; u64 v_c15 = m155[2];
                        slog::join_probe_old<3,1>(lambdaindex95, lambdadelta100, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m156) {
                          u64 v_c16 = m156[1]; u64 v_c17 = m156[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c16, v_c12, v_c24, v_c5}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c24, v_c5}, std::array<u16,2>{0, 1});
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
        ReadTask101* _cont = new ReadTask101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask101(db,b), false);
  // (crule (pre) (scan eval __t0Z2s104 e1 c) (body (exists if (1 3 2 0) 1 e1) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t0Z2s104) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __t9HBz103 e2 e3) (exists eval (0 2 1) 2 __t9HBz103 c) (exists select_branch (2 3 0 1) 2 e2 e3) (join if (1 3 2 0) 3 e1 e3 e2 __t2D2o102) (join eval (0 2 1) 3 __t9HBz103 c __t2D2o102) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t8m22105 __v0) (join eval_ans (0 1) 2 __t0Z2s104 __v0) (join select_branch_ans (0 1) 1 __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join eval_ans (0 1) 1 __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask172 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex157;  slog::Index** evalindex158;  slog::Index** eval_ansindex159;  slog::Index** $sup56712x86x0x0x0index160;  slog::Index** evalindex161;  slog::Index** select_branchindex162;  slog::Index** ifindex163;  slog::Index** evalindex164;  slog::Index** select_branchindex165;  slog::Index** eval_ansindex166;  slog::Index** select_branch_ansindex167;  slog::Index** evalindex168;  slog::Index** eval_ansindex169;  slog::Index** select_branchdelta170;  slog::Index** evaldelta171;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("eval_ans");
      head_index[0] = readrel174->getIndex(ord173, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord175({1, 3, 2, 0});
      slog::Relation* readrel176 = db->getRelation("if");
      ifindex157 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({2, 0, 1});
      slog::Relation* readrel178 = db->getRelation("eval");
      evalindex158 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("eval_ans");
      eval_ansindex159 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0, 3, 4});
      slog::Relation* readrel182 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index160 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 2, 1});
      slog::Relation* readrel184 = db->getRelation("eval");
      evalindex161 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({2, 3, 0, 1});
      slog::Relation* readrel186 = db->getRelation("select_branch");
      select_branchindex162 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 3, 2, 0});
      slog::Relation* readrel188 = db->getRelation("if");
      ifindex163 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({0, 2, 1});
      slog::Relation* readrel190 = db->getRelation("eval");
      evalindex164 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({2, 3, 0, 1});
      slog::Relation* readrel192 = db->getRelation("select_branch");
      select_branchindex165 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({2, 3, 0, 1});
      slog::Relation* readrel194 = db->getRelation("select_branch");
      select_branchdelta170 = readrel194->getIndex(ord193, true);
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("eval_ans");
      eval_ansindex166 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("select_branch_ans");
      select_branch_ansindex167 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("eval");
      evalindex168 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("eval");
      evaldelta171 = readrel202->getIndex(ord201, true);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("eval_ans");
      eval_ansindex169 = readrel204->getIndex(ord203, false);
  
    }
    ReadTask172(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<4,1>(ifindex157, std::array<u64,4>{v_c27, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex158, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex159, std::array<u64,2>{v_c26, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index160, std::array<u64,5>{v_c5, v_c27, 0, 0, 0}, [&](const std::array<u64,5>& m205) {
          u64 v_c28 = m205[2]; u64 v_c29 = m205[3]; u64 v_c30 = m205[4];
          if (!slog::exists_probe<3,2>(evalindex161, std::array<u64,3>{v_c28, v_c5, 0})) return;
          if (!slog::exists_probe<4,2>(select_branchindex162, std::array<u64,4>{v_c29, v_c30, 0, 0})) return;
          slog::join_probe<4,3>(ifindex163, std::array<u64,4>{v_c27, v_c30, v_c29, 0}, [&](const std::array<u64,4>& m206) {
            u64 v_c31 = m206[3];
            slog::join_probe<3,3>(evalindex164, std::array<u64,3>{v_c28, v_c5, v_c31}, [&](const std::array<u64,3>& m207) {
              slog::join_probe_old<4,2>(select_branchindex165, select_branchdelta170, std::array<u64,4>{v_c29, v_c30, 0, 0}, [&](const std::array<u64,4>& m208) {
                u64 v_c32 = m208[2]; u64 v_c13 = m208[3];
                slog::join_probe<2,2>(eval_ansindex166, std::array<u64,2>{v_c26, v_c13}, [&](const std::array<u64,2>& m209) {
                  slog::join_probe<2,1>(select_branch_ansindex167, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m210) {
                    u64 v_c33 = m210[1];
                    slog::join_probe_old<3,2>(evalindex168, evaldelta171, std::array<u64,3>{v_c33, v_c5, 0}, [&](const std::array<u64,3>& m211) {
                      u64 v_c34 = m211[2];
                      slog::join_probe<2,1>(eval_ansindex169, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m212) {
                        u64 v_c35 = m212[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c35}, std::array<u16,2>{0, 1});
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
        ReadTask172* _cont = new ReadTask172(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask172(db,b), false);
  // (crule (pre) (scan eval_ans __t9SPH430 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t9SPH430 c er) (exists let (2 1 3 0) 1 er) (join eval (2 0 1) 1 c __4M4I787 __t66ko429) (join-old let (0 2 1 3) 2 (0 2 1 3) __t66ko429 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex213;  slog::Index** letindex214;  slog::Index** evalindex215;  slog::Index** letindex216;  slog::Index** evaldelta217;  slog::Index** letdelta218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord220({0, 1, 2});
      slog::Relation* readrel221 = db->getRelation("binding");
      head_index[0] = readrel221->getIndex(ord220, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord222({0, 1, 2});
      slog::Relation* readrel223 = db->getRelation("binding_event");
      head_index[1] = readrel223->getIndex(ord222, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord224({0, 2, 1});
      slog::Relation* readrel225 = db->getRelation("eval");
      evalindex213 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({0, 2, 1});
      slog::Relation* readrel227 = db->getRelation("eval");
      evaldelta217 = readrel227->getIndex(ord226, true);
      std::vector<u16> ord228({2, 1, 3, 0});
      slog::Relation* readrel229 = db->getRelation("let");
      letindex214 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({2, 0, 1});
      slog::Relation* readrel231 = db->getRelation("eval");
      evalindex215 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 2, 1, 3});
      slog::Relation* readrel233 = db->getRelation("let");
      letindex216 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 2, 1, 3});
      slog::Relation* readrel235 = db->getRelation("let");
      letdelta218 = readrel235->getIndex(ord234, true);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[1];
        slog::join_probe_old<3,1>(evalindex213, evaldelta217, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m236) {
          u64 v_c5 = m236[1]; u64 v_c38 = m236[2];
          if (!slog::exists_probe<4,1>(letindex214, std::array<u64,4>{v_c38, 0, 0, 0})) return;
          slog::join_probe<3,1>(evalindex215, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m237) {
            u64 v_c39 = m237[1]; u64 v_c40 = m237[2];
            slog::join_probe_old<4,2>(letindex216, letdelta218, std::array<u64,4>{v_c40, v_c38, 0, 0}, [&](const std::array<u64,4>& m238) {
              u64 v_c41 = m238[2]; u64 v_c17 = m238[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c41, v_c5, v_c37}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c41, v_c5, v_c5}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask219* _cont = new ReadTask219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), false);
  // (crule (pre (let __tconst4VQK721 constb9e118781cea1f9fa01462e0) (let __tconst22Ls722 const0122baa3ac55f1b433944eb1) (let __tconst5lFL150 const60e3114d9b4b6577eea8cbc0) (let _00024sqc6U6L608 const6b86b273ff34fce19d6b804e) (let _00024sqc4sFX609 const5feceb66ffc86f38d952786c) (let _00024sqo2S6J610 const5feceb66ffc86f38d952786c) (let _00024sqo0Kwi611 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst5lFL150 _00024seq1 __t1y17151) (body (letp _00024sql06hQ606 (aslst _00024seq1)) (letp __t9y9U153 (lref _00024sql06hQ606 _00024sqc4sFX609)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2S6J610 __t9y9U153 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0Kwi611 __t9y9U153 _00024seq1) (exists _enum (1 0) 1 __tconst22Ls722) (join _enum (1 0) 1 __tconst4VQK721 __t0cMr152) (join-old boolval (0 1) 2 (0 1) __t9y9U153 __t0cMr152) (join _enum (1 0) 1 __tconst22Ls722 __t5r57148) (let chk4BZF1121 (llen _00024sql06hQ606)) (eq _00024sqc6U6L608 chk4BZF1121)) (head (emit-temp temp41lW1120 __t1y17151) (mkstruct boolval (1 0) __t2W4B149 __t5r57148)) interp.slog:113 #f)
  class ReadTask248 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex239;  slog::Index** $seq_atrindex240;  slog::Index** _enumindex241;  slog::Index** _enumindex242;  slog::Index** boolvalindex243;  slog::Index** _enumindex244;  slog::Index** $seq_atdelta245;  slog::Index** $seq_atrdelta246;  slog::Index** boolvaldelta247;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp41lW1120");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("delta");
      driver_index = readrel250->getIndex(ord249, true);
      std::vector<u16> ord251({1, 0, 2});
      slog::Relation* readrel252 = db->getRelation("$seq_at");
      $seq_atindex239 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0, 2});
      slog::Relation* readrel254 = db->getRelation("$seq_at");
      $seq_atdelta245 = readrel254->getIndex(ord253, true);
      std::vector<u16> ord255({1, 0, 2});
      slog::Relation* readrel256 = db->getRelation("$seq_atr");
      $seq_atrindex240 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0, 2});
      slog::Relation* readrel258 = db->getRelation("$seq_atr");
      $seq_atrdelta246 = readrel258->getIndex(ord257, true);
      std::vector<u16> ord259({1, 0});
      slog::Relation* readrel260 = db->getRelation("_enum");
      _enumindex241 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("_enum");
      _enumindex242 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("boolval");
      boolvalindex243 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({0, 1});
      slog::Relation* readrel266 = db->getRelation("boolval");
      boolvaldelta247 = readrel266->getIndex(ord265, true);
      std::vector<u16> ord267({1, 0});
      slog::Relation* readrel268 = db->getRelation("_enum");
      _enumindex244 = readrel268->getIndex(ord267, false);
  
    }
    ReadTask248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c43 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c44 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c44, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m269) {
        u64 v_c49 = m269[1];
        u64 v_c50 = m269[2];
        if (buckethash(v_c49) != bucket) return;
        bool ok270 = true;
        u64 v_c51 = _prim_aslst(db, v_c49, &ok270);
        if (!ok270) return;
        bool ok271 = true;
        u64 v_c52 = _prim_lref(db, v_c51, v_c46, &ok271);
        if (!ok271) return;
        slog::join_probe_old<3,3>($seq_atindex239, $seq_atdelta245, std::array<u64,3>{v_c47, v_c52, v_c49}, [&](const std::array<u64,3>& m272) {
          slog::join_probe_old<3,3>($seq_atrindex240, $seq_atrdelta246, std::array<u64,3>{v_c48, v_c52, v_c49}, [&](const std::array<u64,3>& m273) {
            if (!slog::exists_probe<2,1>(_enumindex241, std::array<u64,2>{v_c43, 0})) return;
            slog::join_probe<2,1>(_enumindex242, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m274) {
              u64 v_c53 = m274[1];
              slog::join_probe_old<2,2>(boolvalindex243, boolvaldelta247, std::array<u64,2>{v_c52, v_c53}, [&](const std::array<u64,2>& m275) {
                slog::join_probe<2,1>(_enumindex244, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m276) {
                  u64 v_c54 = m276[1];
                  u64 v_c55 = _prim_llen(db, v_c51);
                  if (v_c55 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c45 != v_c55) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c50});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c54}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask248* _cont = new ReadTask248(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask248(db,b), false);
  // (crule (pre) (scan eval __9PBX705 __t9oOP118 c) (body (join-old letrec (0 2 1 3) 1 (0 2 1 3) __t9oOP118 er x eb)) (head (mkstruct eval (1 2 0) __8dqD706 er c)) interp.slog:95 #f)
  class ReadTask279 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex277;  slog::Index** letrecdelta278;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord280({0, 2, 1, 3});
      slog::Relation* readrel281 = db->getRelation("letrec");
      letrecindex277 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 2, 1, 3});
      slog::Relation* readrel283 = db->getRelation("letrec");
      letrecdelta278 = readrel283->getIndex(ord282, true);
  
    }
    ReadTask279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe_old<4,1>(letrecindex277, letrecdelta278, std::array<u64,4>{v_c57, 0, 0, 0}, [&](const std::array<u64,4>& m284) {
          u64 v_c38 = m284[1]; u64 v_c41 = m284[2]; u64 v_c17 = m284[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c38, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask279* _cont = new ReadTask279(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask279(db,b), false);
  // (crule (pre (let __trid57q7747 const5963fd3eff55776ca49412c5) (let __trel1vDS748 const4a59dbb9cb3129dfcc75170b) (let __tcol0ZvL749 const5feceb66ffc86f38d952786c) (let __trel36D3750 const4a59dbb9cb3129dfcc75170b) (let __tcol1SZq751 const6b86b273ff34fce19d6b804e)) (scan $sup56712x74x0x0x0 __d0 c ef es) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid57q7747 __trel1vDS748 __tcol0ZvL749 (1 2 3 4 0)) (tycheck c (accept seq) __trid57q7747 __trel36D3750 __tcol1SZq751 (1 2 3 4 0)) (mkstruct eval (1 2 0) __0nWf746 ef c)) interp.slog:75 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid285;  u32 sid286;  u32 sid287;  u32 sid288;  u32 sid289;  u32 sid290;  u32 sid291;  u32 sid292;  u32 sid293;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      sid285 = db->getRelation("app")->getStructId();
      sid286 = db->getRelation("boolean")->getStructId();
      sid287 = db->getRelation("if")->getStructId();
      sid288 = db->getRelation("lambda")->getStructId();
      sid289 = db->getRelation("let")->getStructId();
      sid290 = db->getRelation("letrec")->getStructId();
      sid291 = db->getRelation("num")->getStructId();
      sid292 = db->getRelation("ref")->getStructId();
      sid293 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_const5963fd3eff55776ca49412c5;
      u64 v_c59 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
      u64 v_c61 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c6 = _t[3];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid285 || decode_struct_id(v_c4) == sid286 || decode_struct_id(v_c4) == sid287 || decode_struct_id(v_c4) == sid288 || decode_struct_id(v_c4) == sid289 || decode_struct_id(v_c4) == sid290 || decode_struct_id(v_c4) == sid291 || decode_struct_id(v_c4) == sid292 || decode_struct_id(v_c4) == sid293))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c58, v_c59, v_c60, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c5)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c58, v_c61, v_c62, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c5}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre6j8v926 __errf4l1n927 __errf0c2O928) (body) (head (emit error (0) __erre6j8v926)) <internal>:1 #f)
  class ReadTask295 : public slog::Task
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
      std::vector<u16> ord296({0});
      slog::Relation* readrel297 = db->getRelation("error");
      head_index[0] = readrel297->getIndex(ord296, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask295(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask295* _cont = new ReadTask295(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask295(db,b), false);
  // (crule (pre) (scan eval_args __t2HTD313 es c) (body (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t2HTD313) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __d0 ef) (join eval (1 2 0) 2 ef c __t55UJ311) (join eval_ans (0 1) 1 __t55UJ311 __t9gUy312) (join eval_args_ans (0 1) 1 __t2HTD313 vs) (join prim (0 1) 1 __t9gUy312 op)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
  class ReadTask305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex298;  slog::Index** eval_args_ansindex299;  slog::Index** $sup56712x74x0x0x0index300;  slog::Index** evalindex301;  slog::Index** eval_ansindex302;  slog::Index** eval_args_ansindex303;  slog::Index** primindex304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord306({2, 0, 1});
      slog::Relation* readrel307 = db->getRelation("eval");
      evalindex298 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({0, 1});
      slog::Relation* readrel309 = db->getRelation("eval_args_ans");
      eval_args_ansindex299 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 3, 0, 2});
      slog::Relation* readrel311 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index300 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("eval");
      evalindex301 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("eval_ans");
      eval_ansindex302 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("eval_args_ans");
      eval_args_ansindex303 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1});
      slog::Relation* readrel319 = db->getRelation("prim");
      primindex304 = readrel319->getIndex(ord318, false);
  
    }
    ReadTask305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex298, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex299, std::array<u64,2>{v_c66, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index300, std::array<u64,4>{v_c5, v_c6, 0, 0}, [&](const std::array<u64,4>& m320) {
          u64 v_c7 = m320[2]; u64 v_c4 = m320[3];
          slog::join_probe<3,2>(evalindex301, std::array<u64,3>{v_c4, v_c5, 0}, [&](const std::array<u64,3>& m321) {
            u64 v_c67 = m321[2];
            slog::join_probe<2,1>(eval_ansindex302, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m322) {
              u64 v_c68 = m322[1];
              slog::join_probe<2,1>(eval_args_ansindex303, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m323) {
                u64 v_c12 = m323[1];
                slog::join_probe<2,1>(primindex304, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m324) {
                  u64 v_c69 = m324[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c12}, std::array<u16,3>{1, 2, 0});
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
        ReadTask305* _cont = new ReadTask305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask305(db,b), false);
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0) (let __tconst3fuu217 const06abaa100ecef791ce028c56) (let _00024sqc1fPN569 constd4735e3a265e16eee03f5971) (let _00024sqc78q5570 const5feceb66ffc86f38d952786c) (let _00024sqc5TDx571 const6b86b273ff34fce19d6b804e) (let _00024sqo1Czp572 const5feceb66ffc86f38d952786c) (let _00024sqo2Uyj573 const6b86b273ff34fce19d6b804e) (let _00024sqo2qsW574 const6b86b273ff34fce19d6b804e) (let _00024sqo2mjM575 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo1Czp572 v1 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2qsW574 v1 _00024seq0) (letp _00024sql8W3E567 (aslst _00024seq0)) (letp v2 (lref _00024sql8W3E567 _00024sqc5TDx571)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2Uyj573 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2mjM575 v2 _00024seq0) (exists _enum (1 0) 1 __tconst03NO760) (join delta (1 2 0) 2 __tconst3fuu217 _00024seq0 __t12h7218) (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (let chk10At1093 (llen _00024sql8W3E567)) (eq _00024sqc1fPN569 chk10At1093) (letp chk7Kcp1094 (lref _00024sql8W3E567 _00024sqc78q5570)) (eq v1 chk7Kcp1094)) (head (emit-temp temp4VE71091 __t12h7218) (mkstruct boolval (1 0) __t5boA216 __t6tMS215)) interp.slog:120 #f)
  class ReadTask334 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex325;  slog::Index** $seq_atindex326;  slog::Index** $seq_atrindex327;  slog::Index** _enumindex328;  slog::Index** deltaindex329;  slog::Index** _enumindex330;  slog::Index** $seq_atrdelta331;  slog::Index** $seq_atdelta332;  slog::Index** $seq_atrdelta333;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4VE71091");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord335({1, 0, 2});
      slog::Relation* readrel336 = db->getRelation("$seq_at");
      driver_index = readrel336->getIndex(ord335, true);
      std::vector<u16> ord337({1, 0, 2});
      slog::Relation* readrel338 = db->getRelation("$seq_atr");
      $seq_atrindex325 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0, 2});
      slog::Relation* readrel340 = db->getRelation("$seq_atr");
      $seq_atrdelta331 = readrel340->getIndex(ord339, true);
      std::vector<u16> ord341({1, 0, 2});
      slog::Relation* readrel342 = db->getRelation("$seq_at");
      $seq_atindex326 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 0, 2});
      slog::Relation* readrel344 = db->getRelation("$seq_at");
      $seq_atdelta332 = readrel344->getIndex(ord343, true);
      std::vector<u16> ord345({1, 0, 2});
      slog::Relation* readrel346 = db->getRelation("$seq_atr");
      $seq_atrindex327 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 0, 2});
      slog::Relation* readrel348 = db->getRelation("$seq_atr");
      $seq_atrdelta333 = readrel348->getIndex(ord347, true);
      std::vector<u16> ord349({1, 0});
      slog::Relation* readrel350 = db->getRelation("_enum");
      _enumindex328 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("delta");
      deltaindex329 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 0});
      slog::Relation* readrel354 = db->getRelation("_enum");
      _enumindex330 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask334(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c71 = v_const06abaa100ecef791ce028c56;
      u64 v_c72 = v_constd4735e3a265e16eee03f5971;
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
      u64 v_c76 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c75, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m355) {
        u64 v_c79 = m355[1];
        u64 v_c80 = m355[2];
        if (buckethash(v_c79) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex325, $seq_atrdelta331, std::array<u64,3>{v_c77, v_c79, v_c80}, [&](const std::array<u64,3>& m356) {
          bool ok357 = true;
          u64 v_c81 = _prim_aslst(db, v_c80, &ok357);
          if (!ok357) return;
          bool ok358 = true;
          u64 v_c82 = _prim_lref(db, v_c81, v_c74, &ok358);
          if (!ok358) return;
          if (v_c79 == v_c82) return;
          slog::join_probe_old<3,3>($seq_atindex326, $seq_atdelta332, std::array<u64,3>{v_c76, v_c82, v_c80}, [&](const std::array<u64,3>& m359) {
            slog::join_probe_old<3,3>($seq_atrindex327, $seq_atrdelta333, std::array<u64,3>{v_c78, v_c82, v_c80}, [&](const std::array<u64,3>& m360) {
              if (!slog::exists_probe<2,1>(_enumindex328, std::array<u64,2>{v_c70, 0})) return;
              slog::join_probe<3,2>(deltaindex329, std::array<u64,3>{v_c71, v_c80, 0}, [&](const std::array<u64,3>& m361) {
                u64 v_c83 = m361[2];
                slog::join_probe<2,1>(_enumindex330, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m362) {
                  u64 v_c84 = m362[1];
                  u64 v_c85 = _prim_llen(db, v_c81);
                  if (v_c85 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c72 != v_c85) return;
                  bool ok363 = true;
                  u64 v_c86 = _prim_lref(db, v_c81, v_c73, &ok363);
                  if (!ok363) return;
                  if (v_c79 != v_c86) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c83});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c84}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask334* _cont = new ReadTask334(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask334(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4b4d595 __t76ef190 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo2ych592 __t76ef190 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3d3H593 __t76ef190 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo5WJE594 __t76ef190 _00024seq2) (exists _enum (1 0) 1 __tconst5USv771) (join delta (1 2 0) 2 __tconst16Oe187 _00024seq2 __t4OrE188) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join prim (0 1) 1 __t76ef190 op) (letp _00024sql3Mb9587 (aslst _00024seq2)) (let chk1Ch21073 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk1Ch21073) (letp chk1VKN1074 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (eq __t76ef190 chk1VKN1074) (letp chk5JSm1075 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk5JSm1075)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex364;  slog::Index** $seq_atindex365;  slog::Index** $seq_atrindex366;  slog::Index** _enumindex367;  slog::Index** deltaindex368;  slog::Index** _enumindex369;  slog::Index** primindex370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord372({1, 0, 2});
      slog::Relation* readrel373 = db->getRelation("$seq_atr");
      driver_index = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({1, 0, 2});
      slog::Relation* readrel375 = db->getRelation("$seq_at");
      $seq_atindex364 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0, 2});
      slog::Relation* readrel377 = db->getRelation("$seq_at");
      $seq_atindex365 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 0, 2});
      slog::Relation* readrel379 = db->getRelation("$seq_atr");
      $seq_atrindex366 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("_enum");
      _enumindex367 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("delta");
      deltaindex368 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("_enum");
      _enumindex369 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("prim");
      primindex370 = readrel387->getIndex(ord386, false);
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c88 = v_const06abaa100ecef791ce028c56;
      u64 v_c89 = v_constd4735e3a265e16eee03f5971;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c95, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m388) {
        u64 v_c96 = m388[1];
        u64 v_c97 = m388[2];
        if (buckethash(v_c96) != bucket) return;
        slog::join_probe<3,3>($seq_atindex364, std::array<u64,3>{v_c92, v_c96, v_c97}, [&](const std::array<u64,3>& m389) {
          slog::join_probe<3,3>($seq_atindex365, std::array<u64,3>{v_c93, v_c96, v_c97}, [&](const std::array<u64,3>& m390) {
            slog::join_probe<3,3>($seq_atrindex366, std::array<u64,3>{v_c94, v_c96, v_c97}, [&](const std::array<u64,3>& m391) {
              if (!slog::exists_probe<2,1>(_enumindex367, std::array<u64,2>{v_c87, 0})) return;
              slog::join_probe<3,2>(deltaindex368, std::array<u64,3>{v_c88, v_c97, 0}, [&](const std::array<u64,3>& m392) {
                u64 v_c98 = m392[2];
                slog::join_probe<2,1>(_enumindex369, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m393) {
                  u64 v_c99 = m393[1];
                  slog::join_probe<2,1>(primindex370, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m394) {
                    u64 v_c69 = m394[1];
                    bool ok395 = true;
                    u64 v_c100 = _prim_aslst(db, v_c97, &ok395);
                    if (!ok395) return;
                    u64 v_c101 = _prim_llen(db, v_c100);
                    if (v_c101 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c89 != v_c101) return;
                    bool ok396 = true;
                    u64 v_c102 = _prim_lref(db, v_c100, v_c90, &ok396);
                    if (!ok396) return;
                    if (v_c96 != v_c102) return;
                    bool ok397 = true;
                    u64 v_c103 = _prim_lref(db, v_c100, v_c91, &ok397);
                    if (!ok397) return;
                    if (v_c96 != v_c103) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c98});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c99}, std::array<u16,2>{1, 0});
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
        ReadTask371* _cont = new ReadTask371(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask371(db,b), false);
  // (crule (pre (let __tconst6ZoU727 constb9e118781cea1f9fa01462e0)) (scan boolval __t0HMR234 __t2nGP233) (body (join _enum (0 1) 2 __t2nGP233 __tconst6ZoU727) (join-old select_branch (1 2 3 0) 1 (1 2 3 0) __t0HMR234 e2 e3 __t1G3m235)) (head (emit select_branch_ans (0 1) __t1G3m235 e3)) interp.slog:84 #f)
  class ReadTask401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex398;  slog::Index** select_branchindex399;  slog::Index** select_branchdelta400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("select_branch_ans");
      head_index[0] = readrel403->getIndex(ord402, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("_enum");
      _enumindex398 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 3, 0});
      slog::Relation* readrel407 = db->getRelation("select_branch");
      select_branchindex399 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 3, 0});
      slog::Relation* readrel409 = db->getRelation("select_branch");
      select_branchdelta400 = readrel409->getIndex(ord408, true);
  
    }
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c105 = _t[0];
        u64 v_c106 = _t[1];
        slog::join_probe<2,2>(_enumindex398, std::array<u64,2>{v_c106, v_c104}, [&](const std::array<u64,2>& m410) {
          slog::join_probe_old<4,1>(select_branchindex399, select_branchdelta400, std::array<u64,4>{v_c105, 0, 0, 0}, [&](const std::array<u64,4>& m411) {
            u64 v_c29 = m411[1]; u64 v_c30 = m411[2]; u64 v_c107 = m411[3];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c107, v_c30}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:84", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask401* _cont = new ReadTask401(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), false);
  // (crule (pre) (scan temp87fU992 __t1Myh135 e) (body) (head (mkstruct eval (1 2 0) __6ZJk703 e __t1Myh135)) interp.slog:129 #f)
  class ReadTask412 : public slog::Task
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
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("temp87fU992");
  
    }
    ReadTask412(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c108 = _t[0];
        u64 v_c109 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c109, v_c108}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:129", "delta:temp87fU992", _fires);
  
      if (!_done)
      {
        ReadTask412* _cont = new ReadTask412(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask412(db,b), false);
  // (crule (pre) (scan eval __t5OlD294 __t0H7q293 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x93x0x0x0 (0 1 2 3 4) 2 __t5OlD294 c eb er x) (join letrec (2 1 3 0) 4 er x eb __t0H7q293) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t9p2a295) (exists eval_ans (0 1) 1 __t9p2a295) (join-old eval (1 2 0) 2 (1 2 0) eb c __t32yp296) (exists eval_ans (0 1) 1 __t32yp296) (join eval_ans (0 1) 1 __t9p2a295 vr) (join eval_ans (0 1) 1 __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask425 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex413;  slog::Index** $sup56712x93x0x0x0index414;  slog::Index** letrecindex415;  slog::Index** evalindex416;  slog::Index** evalindex417;  slog::Index** eval_ansindex418;  slog::Index** evalindex419;  slog::Index** eval_ansindex420;  slog::Index** eval_ansindex421;  slog::Index** eval_ansindex422;  slog::Index** evaldelta423;  slog::Index** evaldelta424;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("eval_ans");
      head_index[0] = readrel427->getIndex(ord426, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord428({2, 0, 1});
      slog::Relation* readrel429 = db->getRelation("eval");
      evalindex413 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1, 2, 3, 4});
      slog::Relation* readrel431 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index414 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({2, 1, 3, 0});
      slog::Relation* readrel433 = db->getRelation("letrec");
      letrecindex415 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("eval");
      evalindex416 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("eval");
      evalindex417 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("eval");
      evaldelta423 = readrel439->getIndex(ord438, true);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("eval_ans");
      eval_ansindex418 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({1, 2, 0});
      slog::Relation* readrel443 = db->getRelation("eval");
      evalindex419 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 2, 0});
      slog::Relation* readrel445 = db->getRelation("eval");
      evaldelta424 = readrel445->getIndex(ord444, true);
      std::vector<u16> ord446({0, 1});
      slog::Relation* readrel447 = db->getRelation("eval_ans");
      eval_ansindex420 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0, 1});
      slog::Relation* readrel449 = db->getRelation("eval_ans");
      eval_ansindex421 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({0, 1});
      slog::Relation* readrel451 = db->getRelation("eval_ans");
      eval_ansindex422 = readrel451->getIndex(ord450, false);
  
    }
    ReadTask425(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c110 = _t[0];
        u64 v_c111 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex413, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index414, std::array<u64,5>{v_c110, v_c5, 0, 0, 0}, [&](const std::array<u64,5>& m452) {
          u64 v_c17 = m452[2]; u64 v_c38 = m452[3]; u64 v_c41 = m452[4];
          slog::join_probe<4,4>(letrecindex415, std::array<u64,4>{v_c38, v_c41, v_c17, v_c111}, [&](const std::array<u64,4>& m453) {
            if (!slog::exists_probe<3,2>(evalindex416, std::array<u64,3>{v_c17, v_c5, 0})) return;
            slog::join_probe_old<3,2>(evalindex417, evaldelta423, std::array<u64,3>{v_c38, v_c5, 0}, [&](const std::array<u64,3>& m454) {
              u64 v_c112 = m454[2];
              if (!slog::exists_probe<2,1>(eval_ansindex418, std::array<u64,2>{v_c112, 0})) return;
              slog::join_probe_old<3,2>(evalindex419, evaldelta424, std::array<u64,3>{v_c17, v_c5, 0}, [&](const std::array<u64,3>& m455) {
                u64 v_c113 = m455[2];
                if (!slog::exists_probe<2,1>(eval_ansindex420, std::array<u64,2>{v_c113, 0})) return;
                slog::join_probe<2,1>(eval_ansindex421, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m456) {
                  u64 v_c37 = m456[1];
                  slog::join_probe<2,1>(eval_ansindex422, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m457) {
                    u64 v_c114 = m457[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c110, v_c114}, std::array<u16,2>{0, 1});
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
        ReadTask425* _cont = new ReadTask425(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask425(db,b), false);
  // (crule (pre (let __trid28Qd741 const342a69eb5a93251c8b7e179a) (let __trel7X6u742 constf6cdc3db4b71e0cdeda6912e) (let __tcol4g8x743 const6b86b273ff34fce19d6b804e) (let __trel7qwO744 constf6cdc3db4b71e0cdeda6912e) (let __tcol8jiL745 constd4735e3a265e16eee03f5971)) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body (join-old eval (1 2 0) 2 (1 2 0) e1 c __t8BCY386) (join-old eval_ans (0 1) 1 (0 1) __t8BCY386 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7X6u742 __tcol4g8x743 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7qwO744 __tcol8jiL745 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __7pWz740 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask471 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex458;  slog::Index** eval_ansindex459;  slog::Index** evaldelta460;  slog::Index** eval_ansdelta461;
    u32 sid462;  u32 sid463;  u32 sid464;  u32 sid465;  u32 sid466;  u32 sid467;  u32 sid468;  u32 sid469;  u32 sid470;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord472({1, 2, 0});
      slog::Relation* readrel473 = db->getRelation("eval");
      evalindex458 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("eval");
      evaldelta460 = readrel475->getIndex(ord474, true);
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("eval_ans");
      eval_ansindex459 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({0, 1});
      slog::Relation* readrel479 = db->getRelation("eval_ans");
      eval_ansdelta461 = readrel479->getIndex(ord478, true);
      sid462 = db->getRelation("app")->getStructId();
      sid463 = db->getRelation("boolean")->getStructId();
      sid464 = db->getRelation("if")->getStructId();
      sid465 = db->getRelation("lambda")->getStructId();
      sid466 = db->getRelation("let")->getStructId();
      sid467 = db->getRelation("letrec")->getStructId();
      sid468 = db->getRelation("num")->getStructId();
      sid469 = db->getRelation("ref")->getStructId();
      sid470 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask471(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c116 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c119 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c7 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe_old<3,2>(evalindex458, evaldelta460, std::array<u64,3>{v_c27, v_c5, 0}, [&](const std::array<u64,3>& m480) {
          u64 v_c120 = m480[2];
          slog::join_probe_old<2,1>(eval_ansindex459, eval_ansdelta461, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m481) {
            u64 v_c13 = m481[1];
            ++_fires;
            if (!((is_struct(v_c29) && (decode_struct_id(v_c29) == sid462 || decode_struct_id(v_c29) == sid463 || decode_struct_id(v_c29) == sid464 || decode_struct_id(v_c29) == sid465 || decode_struct_id(v_c29) == sid466 || decode_struct_id(v_c29) == sid467 || decode_struct_id(v_c29) == sid468 || decode_struct_id(v_c29) == sid469 || decode_struct_id(v_c29) == sid470))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c115, v_c116, v_c117, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c30) && (decode_struct_id(v_c30) == sid462 || decode_struct_id(v_c30) == sid463 || decode_struct_id(v_c30) == sid464 || decode_struct_id(v_c30) == sid465 || decode_struct_id(v_c30) == sid466 || decode_struct_id(v_c30) == sid467 || decode_struct_id(v_c30) == sid468 || decode_struct_id(v_c30) == sid469 || decode_struct_id(v_c30) == sid470))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c115, v_c118, v_c119, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c13, v_c29, v_c30}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask471* _cont = new ReadTask471(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask471(db,b), false);
  // (crule (pre) (scan app __t1Dbd212 ef es) (body (join eval (1 2 0) 1 __t1Dbd212 c __1G4R719) (join freevar (0 1) 0 y __t3Eay213) (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3Eay213 xs eb)) (head (mkstruct tick (1 2 0) __2Xr3720 __t1Dbd212 c)) interp.slog:56 #f)
  class ReadTask487 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex482;  slog::Index** freevarindex483;  slog::Index** bindingindex484;  slog::Index** lambdaindex485;  slog::Index** lambdadelta486;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("eval");
      evalindex482 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("freevar");
      freevarindex483 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({0, 1, 2});
      slog::Relation* readrel493 = db->getRelation("binding");
      bindingindex484 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("lambda");
      lambdaindex485 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1, 2});
      slog::Relation* readrel497 = db->getRelation("lambda");
      lambdadelta486 = readrel497->getIndex(ord496, true);
  
    }
    ReadTask487(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<3,1>(evalindex482, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m498) {
          u64 v_c5 = m498[1]; u64 v_c122 = m498[2];
          slog::join_all<2>(freevarindex483, [&](const std::array<u64,2>& m499) {
            u64 v_c123 = m499[0]; u64 v_c124 = m499[1];
            slog::join_probe<3,1>(bindingindex484, std::array<u64,3>{v_c123, 0, 0}, [&](const std::array<u64,3>& m500) {
              u64 v_c15 = m500[1]; u64 v_c125 = m500[2];
              slog::join_probe_old<3,1>(lambdaindex485, lambdadelta486, std::array<u64,3>{v_c124, 0, 0}, [&](const std::array<u64,3>& m501) {
                u64 v_c16 = m501[1]; u64 v_c17 = m501[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c121, v_c5}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask487* _cont = new ReadTask487(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask487(db,b), false);
  // (crule (pre) (scan lambda __t6hhS205 xs eb) (body (exists eval (1 2 0) 1 eb) (join-old closure (1 2 0) 1 (1 2 0) __t6hhS205 cb __t6XAE206) (join eval_ans (1 0) 1 __t6XAE206 __t1DkM204) (join eval (0 2 1) 1 __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t9lTe203) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask529 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex502;  slog::Index** closureindex503;  slog::Index** eval_ansindex504;  slog::Index** evalindex505;  slog::Index** evalindex506;  slog::Index** appindex507;  slog::Index** eval_argsindex508;  slog::Index** tickindex509;  slog::Index** $sup56712x41x0x0x0index510;  slog::Index** appindex511;  slog::Index** eval_argsindex512;  slog::Index** evalindex513;  slog::Index** appindex514;  slog::Index** tickindex515;  slog::Index** eval_argsindex516;  slog::Index** eval_args_ansindex517;  slog::Index** tickindex518;  slog::Index** tick_ansindex519;  slog::Index** eval_args_ansindex520;  slog::Index** tick_ansindex521;  slog::Index** evalindex522;  slog::Index** eval_ansindex523;  slog::Index** closuredelta524;  slog::Index** appdelta525;  slog::Index** eval_argsdelta526;  slog::Index** tickdelta527;  slog::Index** evaldelta528;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord530({0, 1});
      slog::Relation* readrel531 = db->getRelation("eval_ans");
      head_index[0] = readrel531->getIndex(ord530, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("eval");
      evalindex502 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("closure");
      closureindex503 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 2, 0});
      slog::Relation* readrel537 = db->getRelation("closure");
      closuredelta524 = readrel537->getIndex(ord536, true);
      std::vector<u16> ord538({1, 0});
      slog::Relation* readrel539 = db->getRelation("eval_ans");
      eval_ansindex504 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({0, 2, 1});
      slog::Relation* readrel541 = db->getRelation("eval");
      evalindex505 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({2, 0, 1});
      slog::Relation* readrel543 = db->getRelation("eval");
      evalindex506 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 2, 0});
      slog::Relation* readrel545 = db->getRelation("app");
      appindex507 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({2, 0, 1});
      slog::Relation* readrel547 = db->getRelation("eval_args");
      eval_argsindex508 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({2, 0, 1});
      slog::Relation* readrel549 = db->getRelation("tick");
      tickindex509 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 2, 3, 0});
      slog::Relation* readrel551 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index510 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 0});
      slog::Relation* readrel553 = db->getRelation("app");
      appindex511 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 0});
      slog::Relation* readrel555 = db->getRelation("eval_args");
      eval_argsindex512 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({0, 2, 1});
      slog::Relation* readrel557 = db->getRelation("eval");
      evalindex513 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({0, 1, 2});
      slog::Relation* readrel559 = db->getRelation("app");
      appindex514 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({0, 1, 2});
      slog::Relation* readrel561 = db->getRelation("app");
      appdelta525 = readrel561->getIndex(ord560, true);
      std::vector<u16> ord562({1, 2, 0});
      slog::Relation* readrel563 = db->getRelation("tick");
      tickindex515 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 0});
      slog::Relation* readrel565 = db->getRelation("eval_args");
      eval_argsindex516 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 2, 0});
      slog::Relation* readrel567 = db->getRelation("eval_args");
      eval_argsdelta526 = readrel567->getIndex(ord566, true);
      std::vector<u16> ord568({0, 1});
      slog::Relation* readrel569 = db->getRelation("eval_args_ans");
      eval_args_ansindex517 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("tick");
      tickindex518 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("tick");
      tickdelta527 = readrel573->getIndex(ord572, true);
      std::vector<u16> ord574({0, 1});
      slog::Relation* readrel575 = db->getRelation("tick_ans");
      tick_ansindex519 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("eval_args_ans");
      eval_args_ansindex520 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0, 1});
      slog::Relation* readrel579 = db->getRelation("tick_ans");
      tick_ansindex521 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("eval");
      evalindex522 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("eval");
      evaldelta528 = readrel583->getIndex(ord582, true);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("eval_ans");
      eval_ansindex523 = readrel585->getIndex(ord584, false);
  
    }
    ReadTask529(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex502, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe_old<3,1>(closureindex503, closuredelta524, std::array<u64,3>{v_c126, 0, 0}, [&](const std::array<u64,3>& m586) {
          u64 v_c15 = m586[1]; u64 v_c127 = m586[2];
          slog::join_probe<2,1>(eval_ansindex504, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m587) {
            u64 v_c128 = m587[1];
            slog::join_probe<3,1>(evalindex505, std::array<u64,3>{v_c128, 0, 0}, [&](const std::array<u64,3>& m588) {
              u64 v_c5 = m588[1]; u64 v_c4 = m588[2];
              if (!slog::exists_probe<3,1>(evalindex506, std::array<u64,3>{v_c5, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex507, std::array<u64,3>{v_c4, 0, 0})) return;
              if (!slog::exists_probe<3,1>(eval_argsindex508, std::array<u64,3>{v_c5, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex509, std::array<u64,3>{v_c5, 0, 0})) return;
              slog::join_probe<4,2>($sup56712x41x0x0x0index510, std::array<u64,4>{v_c5, v_c4, 0, 0}, [&](const std::array<u64,4>& m589) {
                u64 v_c6 = m589[2]; u64 v_c129 = m589[3];
                if (!slog::exists_probe<3,2>(appindex511, std::array<u64,3>{v_c4, v_c6, 0})) return;
                if (!slog::exists_probe<3,2>(eval_argsindex512, std::array<u64,3>{v_c6, v_c5, 0})) return;
                slog::join_probe<3,2>(evalindex513, std::array<u64,3>{v_c129, v_c5, 0}, [&](const std::array<u64,3>& m590) {
                  u64 v_c130 = m590[2];
                  slog::join_probe_old<3,3>(appindex514, appdelta525, std::array<u64,3>{v_c130, v_c4, v_c6}, [&](const std::array<u64,3>& m591) {
                    if (!slog::exists_probe<3,2>(tickindex515, std::array<u64,3>{v_c130, v_c5, 0})) return;
                    slog::join_probe_old<3,2>(eval_argsindex516, eval_argsdelta526, std::array<u64,3>{v_c6, v_c5, 0}, [&](const std::array<u64,3>& m592) {
                      u64 v_c131 = m592[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex517, std::array<u64,2>{v_c131, 0})) return;
                      slog::join_probe_old<3,2>(tickindex518, tickdelta527, std::array<u64,3>{v_c130, v_c5, 0}, [&](const std::array<u64,3>& m593) {
                        u64 v_c132 = m593[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex519, std::array<u64,2>{v_c132, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex520, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m594) {
                          u64 v_c12 = m594[1];
                          slog::join_probe<2,1>(tick_ansindex521, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m595) {
                            u64 v_c13 = m595[1];
                            slog::join_probe_old<3,2>(evalindex522, evaldelta528, std::array<u64,3>{v_c17, v_c13, 0}, [&](const std::array<u64,3>& m596) {
                              u64 v_c133 = m596[2];
                              slog::join_probe<2,1>(eval_ansindex523, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m597) {
                                u64 v_c114 = m597[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c114}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:lambda", _fires);
  
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
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst93LG421 constba2df4903a2c14e86dc3bcca) (let __tconst6zXr399 const2bc983a5942276eb00a75e21) (let __tconst0XfR396 const7297d2085ea0adffc396d546) (let __tconst466s389 const6b86b273ff34fce19d6b804e) (let __tconst9Oxy387 constef2d127de37b942baad06145) (let __t9Q7F423 (lempty))) (once) (body) (head (emit-temp temp9wda1166 __t9Q7F423) (mkstruct ref (1 0) __t4MSc414 __tconst4i3L422) (mkstruct ref (1 0) __t5p3B410 __tconst93LG421) (mkstruct ref (1 0) __t4O08407 __tconst1UOH427) (mkstruct ref (1 0) __t1k9L397 __tconst0XfR396) (mkstruct ref (1 0) __t4jBg392 __tconst6zXr399) (mkstruct num (1 0) __t7CfZ390 __tconst466s389) (mkstruct num (1 0) __t7jad388 __tconst9Oxy387)) schemecfa.slog:26 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9wda1166");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("num");
      head_rel[7] = db->getRelation("num");
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const0457bba0679825d285ef7fa5;
      u64 v_c135 = v_const30f8b180d63559f2512b744f;
      u64 v_c136 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c137 = v_const2bc983a5942276eb00a75e21;
      u64 v_c138 = v_const7297d2085ea0adffc396d546;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_constef2d127de37b942baad06145;
      u64 v_c141 = _prim_lempty(db);
      if (v_c141 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[8];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c141});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c135}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c136}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c134}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c138}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c139}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c140}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), true);
  // (crule (pre) (scan if __t1rOw325 e1 e2 e3) (body (join freevar (1 0) 1 e1 x)) (head (emit freevar (0 1) x __t1rOw325)) freevars.slog:17 #f)
  class ReadTask600 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex599;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("freevar");
      head_index[0] = readrel602->getIndex(ord601, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord603({1, 0});
      slog::Relation* readrel604 = db->getRelation("freevar");
      freevarindex599 = readrel604->getIndex(ord603, false);
  
    }
    ReadTask600(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        slog::join_probe<2,1>(freevarindex599, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m605) {
          u64 v_c41 = m605[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c142}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask600* _cont = new ReadTask600(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask600(db,b), false);
  // (crule (pre) (scan binding x c v) (body (join-old lookup (1 2 0) 2 (1 2 0) x c __t3AMl16)) (head (emit lookup_ans (0 1) __t3AMl16 v)) interp.slog:32 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex606;  slog::Index** lookupdelta607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("lookup_ans");
      head_index[0] = readrel610->getIndex(ord609, false);
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord611({1, 2, 0});
      slog::Relation* readrel612 = db->getRelation("lookup");
      lookupindex606 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 2, 0});
      slog::Relation* readrel614 = db->getRelation("lookup");
      lookupdelta607 = readrel614->getIndex(ord613, true);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c114 = _t[2];
        slog::join_probe_old<3,2>(lookupindex606, lookupdelta607, std::array<u64,3>{v_c41, v_c5, 0}, [&](const std::array<u64,3>& m615) {
          u64 v_c143 = m615[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c143, v_c114}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre1Ep5918 __errf0rFA919 __errf9LBV920 __errf1vnY921 __errf40sL922) (body) (head (emit error (0) __erre1Ep5918)) <internal>:1 #f)
  class ReadTask616 : public slog::Task
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
      std::vector<u16> ord617({0});
      slog::Relation* readrel618 = db->getRelation("error");
      head_index[0] = readrel618->getIndex(ord617, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask616(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c144 = _t[0];
        u64 v_c145 = _t[1];
        u64 v_c146 = _t[2];
        u64 v_c147 = _t[3];
        u64 v_c148 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c144}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask616* _cont = new ReadTask616(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask616(db,b), false);
  // (crule (pre) (scan letrec __t9oOP118 x er eb) (body (join eval (1 2 0) 1 __t9oOP118 c __9PBX705)) (head (mkstruct eval (1 2 0) __8dqD706 er c)) interp.slog:95 #f)
  class ReadTask620 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex619;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("eval");
      evalindex619 = readrel622->getIndex(ord621, false);
  
    }
    ReadTask620(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c17 = _t[3];
        slog::join_probe<3,1>(evalindex619, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m623) {
          u64 v_c5 = m623[1]; u64 v_c56 = m623[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c38, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask620* _cont = new ReadTask620(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask620(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst7Sjr89 constac8d8342bbb2362d13f0a559) (let __tconst4c9Y88 constc100f95c1913f9c72fc1f4ef) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3NP861 const609d51837c7fc306b0cbb04a) (let __tconst12zL90 conste6c67f7247161354cd7e1d34) (let __tconst864965 const4a44dc15364204a80fe80e90) (let __tconst2skc63 constf5ca38f748a1d6eaf726b8a4) (let __tconst4wKk50 const6b86b273ff34fce19d6b804e) (let __tconst7EjY48 constd4735e3a265e16eee03f5971) (let __tconst65HW45 const06abaa100ecef791ce028c56)) (scan temp5rra955 __t0g3l55 __t1uIM83 __t3MC543 __t5hQI70 __t6K0I92) (body (exists ref (1 0) 1 __tconst65HW45) (exists num (1 0) 1 __tconst7EjY48) (exists num (1 0) 1 __tconst4wKk50) (exists ref (1 0) 1 __tconst6GmF96) (exists num (1 0) 1 __tconst2skc63) (exists num (1 0) 1 __tconst864965) (exists ref (1 0) 1 __tconst4c9Y88) (exists ref (1 0) 1 __tconst12zL90) (join ref (1 0) 1 __tconst3NP861 __t1gk939) (join ref (1 0) 1 __tconst65HW45 __t2luW46) (join num (1 0) 1 __tconst7EjY48 __t61C349) (join num (1 0) 1 __tconst4wKk50 __t3xjv51) (join ref (1 0) 1 __tconst6GmF96 __t8XG759) (join num (1 0) 1 __tconst2skc63 __t23M464) (join num (1 0) 1 __tconst864965 __t4oij66) (join ref (1 0) 1 __tconst4c9Y88 __t3e8l79) (join ref (1 0) 1 __tconst12zL90 __t4l0k86) (let __t1KLO93 (lpush __t6K0I92 __tconst7Sjr89)) (let __t45Au84 (lpush __t1uIM83 __t3e8l79)) (let __t4TnP71 (lpush __t5hQI70 __t4oij66)) (let __t2Fmv56 (lpush __t0g3l55 __t3xjv51)) (let __t0XVv44 (lpush __t3MC543 __t1gk939))) (head (emit-temp temp5yYR956 __t0XVv44 __t1KLO93 __t2Fmv56 __t45Au84 __t4TnP71)) schemecfa.slog:39 #f)
  class ReadTask641 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex624;  slog::Index** numindex625;  slog::Index** numindex626;  slog::Index** refindex627;  slog::Index** numindex628;  slog::Index** numindex629;  slog::Index** refindex630;  slog::Index** refindex631;  slog::Index** refindex632;  slog::Index** refindex633;  slog::Index** numindex634;  slog::Index** numindex635;  slog::Index** refindex636;  slog::Index** numindex637;  slog::Index** numindex638;  slog::Index** refindex639;  slog::Index** refindex640;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5yYR956");
      outer_rel = db->getRelation("temp5rra955");
      std::vector<u16> ord642({1, 0});
      slog::Relation* readrel643 = db->getRelation("ref");
      refindex624 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 0});
      slog::Relation* readrel645 = db->getRelation("num");
      numindex625 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0});
      slog::Relation* readrel647 = db->getRelation("num");
      numindex626 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 0});
      slog::Relation* readrel649 = db->getRelation("ref");
      refindex627 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 0});
      slog::Relation* readrel651 = db->getRelation("num");
      numindex628 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 0});
      slog::Relation* readrel653 = db->getRelation("num");
      numindex629 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 0});
      slog::Relation* readrel655 = db->getRelation("ref");
      refindex630 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 0});
      slog::Relation* readrel657 = db->getRelation("ref");
      refindex631 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 0});
      slog::Relation* readrel659 = db->getRelation("ref");
      refindex632 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 0});
      slog::Relation* readrel661 = db->getRelation("ref");
      refindex633 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 0});
      slog::Relation* readrel663 = db->getRelation("num");
      numindex634 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0});
      slog::Relation* readrel665 = db->getRelation("num");
      numindex635 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 0});
      slog::Relation* readrel667 = db->getRelation("ref");
      refindex636 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 0});
      slog::Relation* readrel669 = db->getRelation("num");
      numindex637 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 0});
      slog::Relation* readrel671 = db->getRelation("num");
      numindex638 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 0});
      slog::Relation* readrel673 = db->getRelation("ref");
      refindex639 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 0});
      slog::Relation* readrel675 = db->getRelation("ref");
      refindex640 = readrel675->getIndex(ord674, false);
  
    }
    ReadTask641(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c150 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c151 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c152 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c153 = v_const609d51837c7fc306b0cbb04a;
      u64 v_c154 = v_conste6c67f7247161354cd7e1d34;
      u64 v_c155 = v_const4a44dc15364204a80fe80e90;
      u64 v_c156 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c157 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c158 = v_constd4735e3a265e16eee03f5971;
      u64 v_c159 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c160 = _t[0];
        u64 v_c161 = _t[1];
        u64 v_c162 = _t[2];
        u64 v_c163 = _t[3];
        u64 v_c164 = _t[4];
        if (!slog::exists_probe<2,1>(refindex624, std::array<u64,2>{v_c159, 0})) return;
        if (!slog::exists_probe<2,1>(numindex625, std::array<u64,2>{v_c158, 0})) return;
        if (!slog::exists_probe<2,1>(numindex626, std::array<u64,2>{v_c157, 0})) return;
        if (!slog::exists_probe<2,1>(refindex627, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<2,1>(numindex628, std::array<u64,2>{v_c156, 0})) return;
        if (!slog::exists_probe<2,1>(numindex629, std::array<u64,2>{v_c155, 0})) return;
        if (!slog::exists_probe<2,1>(refindex630, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(refindex631, std::array<u64,2>{v_c154, 0})) return;
        slog::join_probe<2,1>(refindex632, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m676) {
          u64 v_c165 = m676[1];
          slog::join_probe<2,1>(refindex633, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m677) {
            u64 v_c166 = m677[1];
            slog::join_probe<2,1>(numindex634, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m678) {
              u64 v_c167 = m678[1];
              slog::join_probe<2,1>(numindex635, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m679) {
                u64 v_c168 = m679[1];
                slog::join_probe<2,1>(refindex636, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m680) {
                  u64 v_c169 = m680[1];
                  slog::join_probe<2,1>(numindex637, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m681) {
                    u64 v_c170 = m681[1];
                    slog::join_probe<2,1>(numindex638, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m682) {
                      u64 v_c171 = m682[1];
                      slog::join_probe<2,1>(refindex639, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m683) {
                        u64 v_c172 = m683[1];
                        slog::join_probe<2,1>(refindex640, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m684) {
                          u64 v_c173 = m684[1];
                          u64 v_c174 = _prim_lpush(db, v_c164, v_c150);
                          if (v_c174 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                          u64 v_c175 = _prim_lpush(db, v_c161, v_c172);
                          if (v_c175 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                          u64 v_c176 = _prim_lpush(db, v_c163, v_c171);
                          if (v_c176 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                          u64 v_c177 = _prim_lpush(db, v_c160, v_c168);
                          if (v_c177 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                          u64 v_c178 = _prim_lpush(db, v_c162, v_c165);
                          if (v_c178 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c178, v_c174, v_c177, v_c175, v_c176});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp5rra955", _fires);
  
      if (!_done)
      {
        ReadTask641* _cont = new ReadTask641(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask641(db,b), false);
  // (crule (pre) (scan select_branch_ans __t8m22105 __v1) (body (join-old eval (1 2 0) 1 (1 2 0) __v1 c __t6lGP106) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join-old eval_ans (0 1) 1 (0 1) __t6lGP106 __v2) (join-old eval (2 0 1) 1 (2 0 1) c __t9HBz103 __t2D2o102) (join-old $sup56712x86x0x0x0 (1 0 2 3 4) 2 (1 0 2 3 4) c __t9HBz103 e1 e2 e3) (join-old if (1 3 2 0) 4 (1 3 2 0) e1 e3 e2 __t2D2o102) (exists eval (1 2 0) 2 e1 c) (join-old select_branch (2 3 0 1) 3 (2 3 0 1) e2 e3 __t8m22105 __v0) (exists eval_ans (1 0) 1 __v0) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t0Z2s104) (join eval_ans (0 1) 2 __t0Z2s104 __v0)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask704 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex685;  slog::Index** evalindex686;  slog::Index** $sup56712x86x0x0x0index687;  slog::Index** eval_ansindex688;  slog::Index** evalindex689;  slog::Index** $sup56712x86x0x0x0index690;  slog::Index** ifindex691;  slog::Index** evalindex692;  slog::Index** select_branchindex693;  slog::Index** eval_ansindex694;  slog::Index** evalindex695;  slog::Index** eval_ansindex696;  slog::Index** evaldelta697;  slog::Index** eval_ansdelta698;  slog::Index** evaldelta699;  slog::Index** $sup56712x86x0x0x0delta700;  slog::Index** ifdelta701;  slog::Index** select_branchdelta702;  slog::Index** evaldelta703;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("eval_ans");
      head_index[0] = readrel706->getIndex(ord705, false);
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("eval");
      evalindex685 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("eval");
      evaldelta697 = readrel710->getIndex(ord709, true);
      std::vector<u16> ord711({2, 0, 1});
      slog::Relation* readrel712 = db->getRelation("eval");
      evalindex686 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 0, 2, 3, 4});
      slog::Relation* readrel714 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index687 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("eval_ans");
      eval_ansindex688 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({0, 1});
      slog::Relation* readrel718 = db->getRelation("eval_ans");
      eval_ansdelta698 = readrel718->getIndex(ord717, true);
      std::vector<u16> ord719({2, 0, 1});
      slog::Relation* readrel720 = db->getRelation("eval");
      evalindex689 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({2, 0, 1});
      slog::Relation* readrel722 = db->getRelation("eval");
      evaldelta699 = readrel722->getIndex(ord721, true);
      std::vector<u16> ord723({1, 0, 2, 3, 4});
      slog::Relation* readrel724 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index690 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0, 2, 3, 4});
      slog::Relation* readrel726 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta700 = readrel726->getIndex(ord725, true);
      std::vector<u16> ord727({1, 3, 2, 0});
      slog::Relation* readrel728 = db->getRelation("if");
      ifindex691 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 3, 2, 0});
      slog::Relation* readrel730 = db->getRelation("if");
      ifdelta701 = readrel730->getIndex(ord729, true);
      std::vector<u16> ord731({1, 2, 0});
      slog::Relation* readrel732 = db->getRelation("eval");
      evalindex692 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({2, 3, 0, 1});
      slog::Relation* readrel734 = db->getRelation("select_branch");
      select_branchindex693 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({2, 3, 0, 1});
      slog::Relation* readrel736 = db->getRelation("select_branch");
      select_branchdelta702 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({1, 0});
      slog::Relation* readrel738 = db->getRelation("eval_ans");
      eval_ansindex694 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 2, 0});
      slog::Relation* readrel740 = db->getRelation("eval");
      evalindex695 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 2, 0});
      slog::Relation* readrel742 = db->getRelation("eval");
      evaldelta703 = readrel742->getIndex(ord741, true);
      std::vector<u16> ord743({0, 1});
      slog::Relation* readrel744 = db->getRelation("eval_ans");
      eval_ansindex696 = readrel744->getIndex(ord743, false);
  
    }
    ReadTask704(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[1];
        slog::join_probe_old<3,1>(evalindex685, evaldelta697, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m745) {
          u64 v_c5 = m745[1]; u64 v_c34 = m745[2];
          if (!slog::exists_probe<3,1>(evalindex686, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index687, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(eval_ansindex688, eval_ansdelta698, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m746) {
            u64 v_c35 = m746[1];
            slog::join_probe_old<3,1>(evalindex689, evaldelta699, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m747) {
              u64 v_c28 = m747[1]; u64 v_c31 = m747[2];
              slog::join_probe_old<5,2>($sup56712x86x0x0x0index690, $sup56712x86x0x0x0delta700, std::array<u64,5>{v_c5, v_c28, 0, 0, 0}, [&](const std::array<u64,5>& m748) {
                u64 v_c27 = m748[2]; u64 v_c29 = m748[3]; u64 v_c30 = m748[4];
                slog::join_probe_old<4,4>(ifindex691, ifdelta701, std::array<u64,4>{v_c27, v_c30, v_c29, v_c31}, [&](const std::array<u64,4>& m749) {
                  if (!slog::exists_probe<3,2>(evalindex692, std::array<u64,3>{v_c27, v_c5, 0})) return;
                  slog::join_probe_old<4,3>(select_branchindex693, select_branchdelta702, std::array<u64,4>{v_c29, v_c30, v_c32, 0}, [&](const std::array<u64,4>& m750) {
                    u64 v_c13 = m750[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex694, std::array<u64,2>{v_c13, 0})) return;
                    slog::join_probe_old<3,2>(evalindex695, evaldelta703, std::array<u64,3>{v_c27, v_c5, 0}, [&](const std::array<u64,3>& m751) {
                      u64 v_c26 = m751[2];
                      slog::join_probe<2,2>(eval_ansindex696, std::array<u64,2>{v_c26, v_c13}, [&](const std::array<u64,2>& m752) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c35}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask704* _cont = new ReadTask704(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask704(db,b), false);
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst0XfR396 const7297d2085ea0adffc396d546) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp0K4e1169 __t0QMt425 __t0cS8401 __t8Onp417 __t9Q7F423 __t9Wjx395) (body (exists ref (1 0) 1 __tconst0XfR396) (exists app (2 0 1) 1 __t9Wjx395) (exists ref (1 0) 1 __tconst1UOH427) (exists ref (1 0) 1 __tconst4i3L422) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join ref (1 0) 1 __tconst0XfR396 __t1k9L397) (join app (1 2 0) 2 __t1k9L397 __t9Wjx395 __t8pxg398) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join ref (1 0) 1 __tconst4i3L422 __t4MSc414)) (head (emit-temp temp0zsa1170 __t0QMt425 __t0cS8401 __t8Onp417 __t8pxg398 __t9Q7F423) (mkstruct app (1 2 0) __t1kdF420 __t4MSc414 __t8Onp417) (mkstruct lambda (1 2 0) __t6kgH402 __t0cS8401 __t8pxg398)) schemecfa.slog:26 #f)
  class ReadTask762 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex753;  slog::Index** appindex754;  slog::Index** refindex755;  slog::Index** refindex756;  slog::Index** numindex757;  slog::Index** refindex758;  slog::Index** appindex759;  slog::Index** refindex760;  slog::Index** refindex761;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0zsa1170");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp0K4e1169");
      std::vector<u16> ord763({1, 0});
      slog::Relation* readrel764 = db->getRelation("ref");
      refindex753 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({2, 0, 1});
      slog::Relation* readrel766 = db->getRelation("app");
      appindex754 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 0});
      slog::Relation* readrel768 = db->getRelation("ref");
      refindex755 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0});
      slog::Relation* readrel770 = db->getRelation("ref");
      refindex756 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 0});
      slog::Relation* readrel772 = db->getRelation("num");
      numindex757 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 0});
      slog::Relation* readrel774 = db->getRelation("ref");
      refindex758 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 0});
      slog::Relation* readrel776 = db->getRelation("app");
      appindex759 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 0});
      slog::Relation* readrel778 = db->getRelation("ref");
      refindex760 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 0});
      slog::Relation* readrel780 = db->getRelation("ref");
      refindex761 = readrel780->getIndex(ord779, false);
  
    }
    ReadTask762(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const0457bba0679825d285ef7fa5;
      u64 v_c135 = v_const30f8b180d63559f2512b744f;
      u64 v_c138 = v_const7297d2085ea0adffc396d546;
      u64 v_c140 = v_constef2d127de37b942baad06145;
  
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
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        u64 v_c181 = _t[2];
        u64 v_c141 = _t[3];
        u64 v_c182 = _t[4];
        if (!slog::exists_probe<2,1>(refindex753, std::array<u64,2>{v_c138, 0})) return;
        if (!slog::exists_probe<3,1>(appindex754, std::array<u64,3>{v_c182, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex755, std::array<u64,2>{v_c134, 0})) return;
        if (!slog::exists_probe<2,1>(refindex756, std::array<u64,2>{v_c135, 0})) return;
        slog::join_probe<2,1>(numindex757, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m781) {
          u64 v_c183 = m781[1];
          slog::join_probe<2,1>(refindex758, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m782) {
            u64 v_c184 = m782[1];
            slog::join_probe<3,2>(appindex759, std::array<u64,3>{v_c184, v_c182, 0}, [&](const std::array<u64,3>& m783) {
              u64 v_c185 = m783[2];
              slog::join_probe<2,1>(refindex760, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m784) {
                u64 v_c186 = m784[1];
                slog::join_probe<2,1>(refindex761, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m785) {
                  u64 v_c187 = m785[1];
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c179, v_c180, v_c181, v_c185, v_c141});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c187, v_c181}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c180, v_c185}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp0K4e1169", _fires);
  
      if (!_done)
      {
        ReadTask762* _cont = new ReadTask762(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask762(db,b), false);
  // (crule (pre) (scan lambda __t3Eay213 xs eb) (body (join freevar (1 0) 1 __t3Eay213 y) (join binding (0 1 2) 1 y cb vy) (join eval (0 2 1) 0 __1G4R719 c __t1Dbd212) (join app (0 1 2) 1 __t1Dbd212 ef es)) (head (mkstruct tick (1 2 0) __2Xr3720 __t1Dbd212 c)) interp.slog:56 #f)
  class ReadTask790 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex786;  slog::Index** bindingindex787;  slog::Index** evalindex788;  slog::Index** appindex789;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord791({1, 0});
      slog::Relation* readrel792 = db->getRelation("freevar");
      freevarindex786 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1, 2});
      slog::Relation* readrel794 = db->getRelation("binding");
      bindingindex787 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 2, 1});
      slog::Relation* readrel796 = db->getRelation("eval");
      evalindex788 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1, 2});
      slog::Relation* readrel798 = db->getRelation("app");
      appindex789 = readrel798->getIndex(ord797, false);
  
    }
    ReadTask790(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c124 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<2,1>(freevarindex786, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m799) {
          u64 v_c123 = m799[1];
          slog::join_probe<3,1>(bindingindex787, std::array<u64,3>{v_c123, 0, 0}, [&](const std::array<u64,3>& m800) {
            u64 v_c15 = m800[1]; u64 v_c125 = m800[2];
            slog::join_all<3>(evalindex788, [&](const std::array<u64,3>& m801) {
              u64 v_c122 = m801[0]; u64 v_c5 = m801[1]; u64 v_c121 = m801[2];
              slog::join_probe<3,1>(appindex789, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m802) {
                u64 v_c4 = m802[1]; u64 v_c6 = m802[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c121, v_c5}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask790* _cont = new ReadTask790(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask790(db,b), false);
  // (crule (pre (let __tconst165m173 const60e3114d9b4b6577eea8cbc0) (let __tconst1U6w167 const844546be553b9dcbf71ae163) (let __tconst469K165 const0453462f31b2bcf68e33a91f)) (scan temp0nxI1031 __t6CCt172) (body (exists sym (1 0) 1 __tconst1U6w167) (exists ref (1 0) 1 __tconst165m173) (join sym (1 0) 1 __tconst469K165 __t5k1R166) (join sym (1 0) 1 __tconst1U6w167 __t2m3K168) (join ref (1 0) 1 __tconst165m173 __t3tIp174)) (head (emit-temp temp7N6P1032 __t6CCt172) (mkstruct app (1 2 0) __t86mw175 __t3tIp174 __t6CCt172)) schemecfa.slog:61 #f)
  class ReadTask808 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex803;  slog::Index** refindex804;  slog::Index** symindex805;  slog::Index** symindex806;  slog::Index** refindex807;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7N6P1032");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp0nxI1031");
      std::vector<u16> ord809({1, 0});
      slog::Relation* readrel810 = db->getRelation("sym");
      symindex803 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 0});
      slog::Relation* readrel812 = db->getRelation("ref");
      refindex804 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0});
      slog::Relation* readrel814 = db->getRelation("sym");
      symindex805 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 0});
      slog::Relation* readrel816 = db->getRelation("sym");
      symindex806 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 0});
      slog::Relation* readrel818 = db->getRelation("ref");
      refindex807 = readrel818->getIndex(ord817, false);
  
    }
    ReadTask808(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c188 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c189 = v_const844546be553b9dcbf71ae163;
      u64 v_c190 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c191 = _t[0];
        if (!slog::exists_probe<2,1>(symindex803, std::array<u64,2>{v_c189, 0})) return;
        if (!slog::exists_probe<2,1>(refindex804, std::array<u64,2>{v_c188, 0})) return;
        slog::join_probe<2,1>(symindex805, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m819) {
          u64 v_c192 = m819[1];
          slog::join_probe<2,1>(symindex806, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m820) {
            u64 v_c193 = m820[1];
            slog::join_probe<2,1>(refindex807, std::array<u64,2>{v_c188, 0}, [&](const std::array<u64,2>& m821) {
              u64 v_c194 = m821[1];
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c191});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c194, v_c191}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:61", "delta:temp0nxI1031", _fires);
  
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
  // (crule (pre) (scan eval __6hwf725 __t7Gbt142 c) (body (join-old let (0 2 1 3) 1 (0 2 1 3) __t7Gbt142 er x eb)) (head (mkstruct eval (1 2 0) __1Vwr726 er c)) interp.slog:93 #f)
  class ReadTask824 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex822;  slog::Index** letdelta823;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord825({0, 2, 1, 3});
      slog::Relation* readrel826 = db->getRelation("let");
      letindex822 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({0, 2, 1, 3});
      slog::Relation* readrel828 = db->getRelation("let");
      letdelta823 = readrel828->getIndex(ord827, true);
  
    }
    ReadTask824(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe_old<4,1>(letindex822, letdelta823, std::array<u64,4>{v_c196, 0, 0, 0}, [&](const std::array<u64,4>& m829) {
          u64 v_c38 = m829[1]; u64 v_c41 = m829[2]; u64 v_c17 = m829[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c38, v_c5}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask824* _cont = new ReadTask824(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask824(db,b), false);
  // (crule (pre) (scan eval_ans __t0Z2s104 __v0) (body (exists select_branch (1 2 3 0) 1 __v0) (join-old eval (0 2 1) 1 (0 2 1) __t0Z2s104 c e1) (exists if (1 3 2 0) 1 e1) (exists eval (2 0 1) 1 c) (join-old $sup56712x86x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c e1 __t9HBz103 e2 e3) (exists eval (0 2 1) 2 __t9HBz103 c) (exists select_branch (1 2 3 0) 3 __v0 e2 e3) (join-old if (1 3 2 0) 3 (1 3 2 0) e1 e3 e2 __t2D2o102) (join-old eval (0 2 1) 3 (0 2 1) __t9HBz103 c __t2D2o102) (join-old select_branch (1 2 3 0) 3 (1 2 3 0) __v0 e2 e3 __t8m22105) (join-old select_branch_ans (0 1) 1 (0 1) __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join-old eval_ans (0 1) 1 (0 1) __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask851 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex830;  slog::Index** evalindex831;  slog::Index** ifindex832;  slog::Index** evalindex833;  slog::Index** $sup56712x86x0x0x0index834;  slog::Index** evalindex835;  slog::Index** select_branchindex836;  slog::Index** ifindex837;  slog::Index** evalindex838;  slog::Index** select_branchindex839;  slog::Index** select_branch_ansindex840;  slog::Index** evalindex841;  slog::Index** eval_ansindex842;  slog::Index** evaldelta843;  slog::Index** $sup56712x86x0x0x0delta844;  slog::Index** ifdelta845;  slog::Index** evaldelta846;  slog::Index** select_branchdelta847;  slog::Index** select_branch_ansdelta848;  slog::Index** evaldelta849;  slog::Index** eval_ansdelta850;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord852({0, 1});
      slog::Relation* readrel853 = db->getRelation("eval_ans");
      head_index[0] = readrel853->getIndex(ord852, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord854({1, 2, 3, 0});
      slog::Relation* readrel855 = db->getRelation("select_branch");
      select_branchindex830 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({0, 2, 1});
      slog::Relation* readrel857 = db->getRelation("eval");
      evalindex831 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 2, 1});
      slog::Relation* readrel859 = db->getRelation("eval");
      evaldelta843 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({1, 3, 2, 0});
      slog::Relation* readrel861 = db->getRelation("if");
      ifindex832 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({2, 0, 1});
      slog::Relation* readrel863 = db->getRelation("eval");
      evalindex833 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 2, 0, 3, 4});
      slog::Relation* readrel865 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index834 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({1, 2, 0, 3, 4});
      slog::Relation* readrel867 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta844 = readrel867->getIndex(ord866, true);
      std::vector<u16> ord868({0, 2, 1});
      slog::Relation* readrel869 = db->getRelation("eval");
      evalindex835 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({1, 2, 3, 0});
      slog::Relation* readrel871 = db->getRelation("select_branch");
      select_branchindex836 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({1, 3, 2, 0});
      slog::Relation* readrel873 = db->getRelation("if");
      ifindex837 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({1, 3, 2, 0});
      slog::Relation* readrel875 = db->getRelation("if");
      ifdelta845 = readrel875->getIndex(ord874, true);
      std::vector<u16> ord876({0, 2, 1});
      slog::Relation* readrel877 = db->getRelation("eval");
      evalindex838 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({0, 2, 1});
      slog::Relation* readrel879 = db->getRelation("eval");
      evaldelta846 = readrel879->getIndex(ord878, true);
      std::vector<u16> ord880({1, 2, 3, 0});
      slog::Relation* readrel881 = db->getRelation("select_branch");
      select_branchindex839 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 3, 0});
      slog::Relation* readrel883 = db->getRelation("select_branch");
      select_branchdelta847 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({0, 1});
      slog::Relation* readrel885 = db->getRelation("select_branch_ans");
      select_branch_ansindex840 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({0, 1});
      slog::Relation* readrel887 = db->getRelation("select_branch_ans");
      select_branch_ansdelta848 = readrel887->getIndex(ord886, true);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("eval");
      evalindex841 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 0});
      slog::Relation* readrel891 = db->getRelation("eval");
      evaldelta849 = readrel891->getIndex(ord890, true);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("eval_ans");
      eval_ansindex842 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("eval_ans");
      eval_ansdelta850 = readrel895->getIndex(ord894, true);
  
    }
    ReadTask851(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex830, std::array<u64,4>{v_c13, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex831, evaldelta843, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m896) {
          u64 v_c5 = m896[1]; u64 v_c27 = m896[2];
          if (!slog::exists_probe<4,1>(ifindex832, std::array<u64,4>{v_c27, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex833, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x86x0x0x0index834, $sup56712x86x0x0x0delta844, std::array<u64,5>{v_c5, v_c27, 0, 0, 0}, [&](const std::array<u64,5>& m897) {
            u64 v_c28 = m897[2]; u64 v_c29 = m897[3]; u64 v_c30 = m897[4];
            if (!slog::exists_probe<3,2>(evalindex835, std::array<u64,3>{v_c28, v_c5, 0})) return;
            if (!slog::exists_probe<4,3>(select_branchindex836, std::array<u64,4>{v_c13, v_c29, v_c30, 0})) return;
            slog::join_probe_old<4,3>(ifindex837, ifdelta845, std::array<u64,4>{v_c27, v_c30, v_c29, 0}, [&](const std::array<u64,4>& m898) {
              u64 v_c31 = m898[3];
              slog::join_probe_old<3,3>(evalindex838, evaldelta846, std::array<u64,3>{v_c28, v_c5, v_c31}, [&](const std::array<u64,3>& m899) {
                slog::join_probe_old<4,3>(select_branchindex839, select_branchdelta847, std::array<u64,4>{v_c13, v_c29, v_c30, 0}, [&](const std::array<u64,4>& m900) {
                  u64 v_c32 = m900[3];
                  slog::join_probe_old<2,1>(select_branch_ansindex840, select_branch_ansdelta848, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m901) {
                    u64 v_c33 = m901[1];
                    slog::join_probe_old<3,2>(evalindex841, evaldelta849, std::array<u64,3>{v_c33, v_c5, 0}, [&](const std::array<u64,3>& m902) {
                      u64 v_c34 = m902[2];
                      slog::join_probe_old<2,1>(eval_ansindex842, eval_ansdelta850, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m903) {
                        u64 v_c35 = m903[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c35}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask851* _cont = new ReadTask851(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask851(db,b), false);
  // (crule (pre (let __tconst7oTo733 constb9e118781cea1f9fa01462e0) (let __tconst23AG380 const60e3114d9b4b6577eea8cbc0) (let _00024sqc7zL5538 const6b86b273ff34fce19d6b804e) (let _00024sqc0b5k539 const5feceb66ffc86f38d952786c) (let _00024sqo0tFP540 const5feceb66ffc86f38d952786c) (let _00024sqo2KLy541 const5feceb66ffc86f38d952786c)) (scan scheme_false fv) (body (exists $seq_at (1 0 2) 1 _00024sqo0tFP540) (exists $seq_atr (1 0 2) 1 _00024sqo2KLy541) (exists delta (1 2 0) 1 __tconst23AG380) (join _enum (1 0) 1 __tconst7oTo733 __t1FRr378) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo0tFP540 v _00024seq0) (neq v fv) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2KLy541 v _00024seq0) (join-old delta (1 2 0) 2 (1 2 0) __tconst23AG380 _00024seq0 __t7rOF381) (letp _00024sql6Yee536 (aslst _00024seq0)) (let chk2wjz996 (llen _00024sql6Yee536)) (eq _00024sqc7zL5538 chk2wjz996) (letp chk4Oxq997 (lref _00024sql6Yee536 _00024sqc0b5k539)) (eq v chk4Oxq997)) (head (emit-temp temp0LTu995 __t7rOF381) (mkstruct boolval (1 0) __t7RmO379 __t1FRr378)) interp.slog:114 #f)
  class ReadTask914 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex904;  slog::Index** $seq_atrindex905;  slog::Index** deltaindex906;  slog::Index** _enumindex907;  slog::Index** $seq_atindex908;  slog::Index** $seq_atrindex909;  slog::Index** deltaindex910;  slog::Index** $seq_atdelta911;  slog::Index** $seq_atrdelta912;  slog::Index** deltadelta913;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LTu995");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord915({1, 0, 2});
      slog::Relation* readrel916 = db->getRelation("$seq_at");
      $seq_atindex904 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 0, 2});
      slog::Relation* readrel918 = db->getRelation("$seq_atr");
      $seq_atrindex905 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 2, 0});
      slog::Relation* readrel920 = db->getRelation("delta");
      deltaindex906 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 0});
      slog::Relation* readrel922 = db->getRelation("_enum");
      _enumindex907 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 0, 2});
      slog::Relation* readrel924 = db->getRelation("$seq_at");
      $seq_atindex908 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({1, 0, 2});
      slog::Relation* readrel926 = db->getRelation("$seq_at");
      $seq_atdelta911 = readrel926->getIndex(ord925, true);
      std::vector<u16> ord927({1, 0, 2});
      slog::Relation* readrel928 = db->getRelation("$seq_atr");
      $seq_atrindex909 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 0, 2});
      slog::Relation* readrel930 = db->getRelation("$seq_atr");
      $seq_atrdelta912 = readrel930->getIndex(ord929, true);
      std::vector<u16> ord931({1, 2, 0});
      slog::Relation* readrel932 = db->getRelation("delta");
      deltaindex910 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 2, 0});
      slog::Relation* readrel934 = db->getRelation("delta");
      deltadelta913 = readrel934->getIndex(ord933, true);
  
    }
    ReadTask914(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c197 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c198 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
      u64 v_c201 = v_const5feceb66ffc86f38d952786c;
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
        if (!slog::exists_probe<3,1>($seq_atindex904, std::array<u64,3>{v_c201, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atrindex905, std::array<u64,3>{v_c202, 0, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex906, std::array<u64,3>{v_c198, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex907, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m935) {
          u64 v_c204 = m935[1];
          slog::join_probe_old<3,1>($seq_atindex908, $seq_atdelta911, std::array<u64,3>{v_c201, 0, 0}, [&](const std::array<u64,3>& m936) {
            u64 v_c114 = m936[1]; u64 v_c80 = m936[2];
            if (v_c114 == v_c203) return;
            slog::join_probe_old<3,3>($seq_atrindex909, $seq_atrdelta912, std::array<u64,3>{v_c202, v_c114, v_c80}, [&](const std::array<u64,3>& m937) {
              slog::join_probe_old<3,2>(deltaindex910, deltadelta913, std::array<u64,3>{v_c198, v_c80, 0}, [&](const std::array<u64,3>& m938) {
                u64 v_c205 = m938[2];
                bool ok939 = true;
                u64 v_c206 = _prim_aslst(db, v_c80, &ok939);
                if (!ok939) return;
                u64 v_c207 = _prim_llen(db, v_c206);
                if (v_c207 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c199 != v_c207) return;
                bool ok940 = true;
                u64 v_c208 = _prim_lref(db, v_c206, v_c200, &ok940);
                if (!ok940) return;
                if (v_c114 != v_c208) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c205});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c204}, std::array<u16,2>{1, 0});
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
  // (crule (pre (let __tconst7god107 const5feceb66ffc86f38d952786c)) (scan lst_take __t97gC109 l n) (body (let __t2Wlm108 (lslice l __tconst7god107 n))) (head (emit-temp temp4IsT993 __t2Wlm108 __t97gC109)) list.slog:29 #f)
  class ReadTask941 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4IsT993");
      outer_rel = db->getRelation("lst_take");
  
    }
    ReadTask941(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c210 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c211 = _t[2];
        u64 v_c212 = _prim_lslice(db, v_c24, v_c209, v_c211);
        if (v_c212 == slog_error) { slog::emit_pending_error(db, "list.slog:29"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c212, v_c210});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask941* _cont = new ReadTask941(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask941(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec)) (scan temp88Gk1117 __t3xwX335 __t4CVz374 __t6p3G371) (body (join lambda (1 2 0) 2 __t4CVz374 __t6p3G371 __t8yYt375)) (head (emit-temp temp3xK81118 __t3xwX335 __t8yYt375) (mkstruct letrec (2 1 3 0) __t4gqR377 __t8yYt375 __tconst3Nin376 __t3xwX335)) schemecfa.slog:12 #f)
  class ReadTask943 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex942;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xK81118");
      head_rel[1] = db->getRelation("letrec");
      outer_rel = db->getRelation("temp88Gk1117");
      std::vector<u16> ord944({1, 2, 0});
      slog::Relation* readrel945 = db->getRelation("lambda");
      lambdaindex942 = readrel945->getIndex(ord944, false);
  
    }
    ReadTask943(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_consta81ad7556291f9defc5163ec;
  
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
        u64 v_c215 = _t[1];
        u64 v_c216 = _t[2];
        slog::join_probe<3,2>(lambdaindex942, std::array<u64,3>{v_c215, v_c216, 0}, [&](const std::array<u64,3>& m946) {
          u64 v_c217 = m946[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c214, v_c217});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c217, v_c213, v_c214}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp88Gk1117", _fires);
  
      if (!_done)
      {
        ReadTask943* _cont = new ReadTask943(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask943(db,b), false);
}

