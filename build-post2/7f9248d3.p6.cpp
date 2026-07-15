
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const25f568921d120de09a5f575d;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const609d51837c7fc306b0cbb04a;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const781eda039ec10c193395ca07;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste6c67f7247161354cd7e1d34;
extern u64 v_consteefaed435882b14b69e99d78;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_cc602175322616bae(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan app __t8Z3R127 ef es) (body (join eval (1 2 0) 1 __t8Z3R127 c __1mVf736) (join freevar (0 1) 0 y __t8ny9128) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t8ny9128 xs eb)) (head (mkstruct eval (1 2 0) __8uDI737 ef c)) interp.slog:56 #f)
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
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst12zL90 conste6c67f7247161354cd7e1d34) (let __tconst7Sjr89 constac8d8342bbb2362d13f0a559) (let __tconst4c9Y88 constc100f95c1913f9c72fc1f4ef) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3hti67 const7297d2085ea0adffc396d546) (let __tconst864965 const4a44dc15364204a80fe80e90) (let __tconst2skc63 constf5ca38f748a1d6eaf726b8a4) (let __tconst3NP861 const609d51837c7fc306b0cbb04a) (let __tconst6C1f52 const53a56174f3826669a422fc54) (let __tconst4wKk50 const6b86b273ff34fce19d6b804e) (let __tconst7EjY48 constd4735e3a265e16eee03f5971) (let __tconst65HW45 const06abaa100ecef791ce028c56) (let __t8u9k91 (lempty))) (once) (body) (head (emit-temp temp1yL5954 __t8u9k91) (mkstruct ref (1 0) __t4l0k86 __tconst12zL90) (mkstruct ref (1 0) __t2GL381 __tconst7Sjr89) (mkstruct ref (1 0) __t3e8l79 __tconst4c9Y88) (mkstruct ref (1 0) __t87Tf68 __tconst3hti67) (mkstruct num (1 0) __t4oij66 __tconst864965) (mkstruct num (1 0) __t23M464 __tconst2skc63) (mkstruct ref (1 0) __t8XG759 __tconst6GmF96) (mkstruct ref (1 0) __t1C8J53 __tconst6C1f52) (mkstruct num (1 0) __t3xjv51 __tconst4wKk50) (mkstruct num (1 0) __t61C349 __tconst7EjY48) (mkstruct ref (1 0) __t2luW46 __tconst65HW45) (mkstruct ref (1 0) __t0zwc41 __tconst4uoq76) (mkstruct ref (1 0) __t1gk939 __tconst3NP861)) schemecfa.slog:39 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[14];
    slog::Index** head_index[14];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yL5954");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("num");
      head_rel[6] = db->getRelation("num");
      head_rel[7] = db->getRelation("ref");
      head_rel[8] = db->getRelation("ref");
      head_rel[9] = db->getRelation("num");
      head_rel[10] = db->getRelation("num");
      head_rel[11] = db->getRelation("ref");
      head_rel[12] = db->getRelation("ref");
      head_rel[13] = db->getRelation("ref");
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c12 = v_conste6c67f7247161354cd7e1d34;
      u64 v_c13 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c14 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c15 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c16 = v_const7297d2085ea0adffc396d546;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
      u64 v_c18 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c19 = v_const609d51837c7fc306b0cbb04a;
      u64 v_c20 = v_const53a56174f3826669a422fc54;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c22 = v_constd4735e3a265e16eee03f5971;
      u64 v_c23 = v_const06abaa100ecef791ce028c56;
      u64 v_c24 = _prim_lempty(db);
      if (v_c24 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[14];
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
      newbatch[10] = new slog::InsertBatch();
      newbatch[11] = new slog::InsertBatch();
      newbatch[12] = new slog::InsertBatch();
      newbatch[13] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c13}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[9], newbatch[9], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[10], newbatch[10], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[11], newbatch[11], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[12], newbatch[12], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[13], newbatch[13], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
  
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
        head_rel[10]->sendBatch(newbatch[10]);
        head_rel[11]->sendBatch(newbatch[11]);
        head_rel[12]->sendBatch(newbatch[12]);
        head_rel[13]->sendBatch(newbatch[13]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), true);
  // (crule (pre) (scan tick __t5Pln304 __t7NtH303 c) (body (exists tick_ans (0 1) 1 __t5Pln304) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t7NtH303 c __7p9q702) (join tick_ans (0 1) 1 __t5Pln304 l) (join eval (2 0 1) 1 c __t9B5D299 ef) (exists eval_ans (0 1) 1 __t9B5D299) (join app (0 1 2) 2 __t7NtH303 ef es) (join eval_args (1 2 0) 2 es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join closure (0 1 2) 1 __t4ng7301 __t4mHn300 cb) (join lambda (0 1 2) 1 __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex18;  slog::Index** evalindex19;  slog::Index** eval_argsindex20;  slog::Index** evalindex21;  slog::Index** tick_ansindex22;  slog::Index** evalindex23;  slog::Index** eval_ansindex24;  slog::Index** appindex25;  slog::Index** eval_argsindex26;  slog::Index** eval_args_ansindex27;  slog::Index** eval_ansindex28;  slog::Index** eval_args_ansindex29;  slog::Index** closureindex30;  slog::Index** lambdaindex31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord33({0, 1, 2, 3});
      slog::Relation* readrel34 = db->getRelation("bind_params");
      head_index[0] = readrel34->getIndex(ord33, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("call_event");
      head_index[1] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("tick_ans");
      tick_ansindex18 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 0, 1});
      slog::Relation* readrel40 = db->getRelation("eval");
      evalindex19 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 0, 1});
      slog::Relation* readrel42 = db->getRelation("eval_args");
      eval_argsindex20 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("eval");
      evalindex21 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("tick_ans");
      tick_ansindex22 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({2, 0, 1});
      slog::Relation* readrel48 = db->getRelation("eval");
      evalindex23 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("eval_ans");
      eval_ansindex24 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("app");
      appindex25 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("eval_args");
      eval_argsindex26 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("eval_args_ans");
      eval_args_ansindex27 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("eval_ans");
      eval_ansindex28 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("eval_args_ans");
      eval_args_ansindex29 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1, 2});
      slog::Relation* readrel62 = db->getRelation("closure");
      closureindex30 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1, 2});
      slog::Relation* readrel64 = db->getRelation("lambda");
      lambdaindex31 = readrel64->getIndex(ord63, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex18, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex19, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex20, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<3,2>(evalindex21, std::array<u64,3>{v_c26, v_c3, 0}, [&](const std::array<u64,3>& m65) {
          u64 v_c27 = m65[2];
          slog::join_probe<2,1>(tick_ansindex22, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m66) {
            u64 v_c28 = m66[1];
            slog::join_probe<3,1>(evalindex23, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m67) {
              u64 v_c29 = m67[1]; u64 v_c1 = m67[2];
              if (!slog::exists_probe<2,1>(eval_ansindex24, std::array<u64,2>{v_c29, 0})) return;
              slog::join_probe<3,2>(appindex25, std::array<u64,3>{v_c26, v_c1, 0}, [&](const std::array<u64,3>& m68) {
                u64 v_c2 = m68[2];
                slog::join_probe<3,2>(eval_argsindex26, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m69) {
                  u64 v_c30 = m69[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex27, std::array<u64,2>{v_c30, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex28, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m70) {
                    u64 v_c31 = m70[1];
                    slog::join_probe<2,1>(eval_args_ansindex29, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m71) {
                      u64 v_c32 = m71[1];
                      slog::join_probe<3,1>(closureindex30, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m72) {
                        u64 v_c33 = m72[1]; u64 v_c7 = m72[2];
                        slog::join_probe<3,1>(lambdaindex31, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m73) {
                          u64 v_c9 = m73[1]; u64 v_c10 = m73[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c32, v_c28, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c28, v_c3}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan eval __t0HZY32 __t8y8931 c) (body (exists lookup (2 0 1) 1 c) (join ref (0 1) 1 __t8y8931 x) (join-old lookup (1 2 0) 2 (1 2 0) x c __t5YK333) (join lookup_ans (0 1) 1 __t5YK333 __v0)) (head (emit eval_ans (0 1) __t0HZY32 __v0)) interp.slog:30 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex74;  slog::Index** refindex75;  slog::Index** lookupindex76;  slog::Index** lookup_ansindex77;  slog::Index** lookupdelta78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("eval_ans");
      head_index[0] = readrel81->getIndex(ord80, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord82({2, 0, 1});
      slog::Relation* readrel83 = db->getRelation("lookup");
      lookupindex74 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("ref");
      refindex75 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("lookup");
      lookupindex76 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("lookup");
      lookupdelta78 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("lookup_ans");
      lookup_ansindex77 = readrel91->getIndex(ord90, false);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(lookupindex74, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(refindex75, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m92) {
          u64 v_c36 = m92[1];
          slog::join_probe_old<3,2>(lookupindex76, lookupdelta78, std::array<u64,3>{v_c36, v_c3, 0}, [&](const std::array<u64,3>& m93) {
            u64 v_c37 = m93[2];
            slog::join_probe<2,1>(lookup_ansindex77, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m94) {
              u64 v_c38 = m94[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c38}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre) (scan lambda __t8ny9128 xs eb) (body (join freevar (1 0) 1 __t8ny9128 y) (join binding (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __1mVf736 c __t8Z3R127) (join-old app (0 1 2) 1 (0 1 2) __t8Z3R127 ef es)) (head (mkstruct eval (1 2 0) __8uDI737 ef c)) interp.slog:56 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex95;  slog::Index** bindingindex96;  slog::Index** evalindex97;  slog::Index** appindex98;  slog::Index** evaldelta99;  slog::Index** appdelta100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("freevar");
      freevarindex95 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("binding");
      bindingindex96 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 2, 1});
      slog::Relation* readrel107 = db->getRelation("eval");
      evalindex97 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 2, 1});
      slog::Relation* readrel109 = db->getRelation("eval");
      evaldelta99 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({0, 1, 2});
      slog::Relation* readrel111 = db->getRelation("app");
      appindex98 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 1, 2});
      slog::Relation* readrel113 = db->getRelation("app");
      appdelta100 = readrel113->getIndex(ord112, true);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(freevarindex95, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m114) {
          u64 v_c5 = m114[1];
          slog::join_probe<3,1>(bindingindex96, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m115) {
            u64 v_c7 = m115[1]; u64 v_c8 = m115[2];
            slog::join_all_old<3>(evalindex97, evaldelta99, [&](const std::array<u64,3>& m116) {
              u64 v_c4 = m116[0]; u64 v_c3 = m116[1]; u64 v_c0 = m116[2];
              slog::join_probe_old<3,1>(appindex98, appdelta100, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m117) {
                u64 v_c1 = m117[1]; u64 v_c2 = m117[2];
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
  // (crule (pre (let __tconst165m173 const60e3114d9b4b6577eea8cbc0) (let __tconst1U6w167 const844546be553b9dcbf71ae163) (let __tconst469K165 const0453462f31b2bcf68e33a91f) (let __tconst9G7o724 constb9e118781cea1f9fa01462e0)) (scan temp8AMS1030 __t1trx171) (body (exists sym (1 0) 1 __tconst469K165) (exists sym (1 0) 1 __tconst1U6w167) (exists ref (1 0) 1 __tconst165m173) (join _enum (1 0) 1 __tconst9G7o724 __t551W169) (exists boolean (1 0) 1 __t551W169) (join sym (1 0) 1 __tconst469K165 __t5k1R166) (join sym (1 0) 1 __tconst1U6w167 __t2m3K168) (join boolean (1 0) 1 __t551W169 __t1HQ2170) (join ref (1 0) 1 __tconst165m173 __t3tIp174) (let __t6CCt172 (lpush __t1trx171 __t1HQ2170))) (head (emit-temp temp0nxI1031 __t6CCt172)) schemecfa.slog:61 #f)
  class ReadTask127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex118;  slog::Index** symindex119;  slog::Index** refindex120;  slog::Index** _enumindex121;  slog::Index** booleanindex122;  slog::Index** symindex123;  slog::Index** symindex124;  slog::Index** booleanindex125;  slog::Index** refindex126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0nxI1031");
      outer_rel = db->getRelation("temp8AMS1030");
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("sym");
      symindex118 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("sym");
      symindex119 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ref");
      refindex120 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("_enum");
      _enumindex121 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("boolean");
      booleanindex122 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("sym");
      symindex123 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("sym");
      symindex124 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("boolean");
      booleanindex125 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0});
      slog::Relation* readrel145 = db->getRelation("ref");
      refindex126 = readrel145->getIndex(ord144, false);
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c40 = v_const844546be553b9dcbf71ae163;
      u64 v_c41 = v_const0453462f31b2bcf68e33a91f;
      u64 v_c42 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c43 = _t[0];
        if (!slog::exists_probe<2,1>(symindex118, std::array<u64,2>{v_c41, 0})) return;
        if (!slog::exists_probe<2,1>(symindex119, std::array<u64,2>{v_c40, 0})) return;
        if (!slog::exists_probe<2,1>(refindex120, std::array<u64,2>{v_c39, 0})) return;
        slog::join_probe<2,1>(_enumindex121, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m146) {
          u64 v_c44 = m146[1];
          if (!slog::exists_probe<2,1>(booleanindex122, std::array<u64,2>{v_c44, 0})) return;
          slog::join_probe<2,1>(symindex123, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m147) {
            u64 v_c45 = m147[1];
            slog::join_probe<2,1>(symindex124, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m148) {
              u64 v_c46 = m148[1];
              slog::join_probe<2,1>(booleanindex125, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m149) {
                u64 v_c47 = m149[1];
                slog::join_probe<2,1>(refindex126, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m150) {
                  u64 v_c48 = m150[1];
                  u64 v_c49 = _prim_lpush(db, v_c43, v_c47);
                  if (v_c49 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:61"); return; }
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c49});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:61", "delta:temp8AMS1030", _fires);
  
      if (!_done)
      {
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec)) (scan temp3xK81118 __t3xwX335 __t8yYt375) (body (join letrec (2 1 3 0) 3 __t8yYt375 __tconst3Nin376 __t3xwX335 __t4gqR377)) (head (emit program (0) __t4gqR377)) schemecfa.slog:12 #f)
  class ReadTask152 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex151;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord153({0});
      slog::Relation* readrel154 = db->getRelation("program");
      head_index[0] = readrel154->getIndex(ord153, false);
      outer_rel = db->getRelation("temp3xK81118");
      std::vector<u16> ord155({2, 1, 3, 0});
      slog::Relation* readrel156 = db->getRelation("letrec");
      letrecindex151 = readrel156->getIndex(ord155, false);
  
    }
    ReadTask152(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_consta81ad7556291f9defc5163ec;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c51 = _t[0];
        u64 v_c52 = _t[1];
        slog::join_probe<4,3>(letrecindex151, std::array<u64,4>{v_c52, v_c50, v_c51, 0}, [&](const std::array<u64,4>& m157) {
          u64 v_c53 = m157[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp3xK81118", _fires);
  
      if (!_done)
      {
        ReadTask152* _cont = new ReadTask152(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask152(db,b), false);
  // (crule (pre) (scan eval_ans __t3m2r182 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t3m2r182 c er) (exists letrec (2 1 3 0) 1 er) (join eval (2 0 1) 1 c __1E5R778 __t7zZ2181) (join-old letrec (0 2 1 3) 2 (0 2 1 3) __t7zZ2181 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex158;  slog::Index** letrecindex159;  slog::Index** evalindex160;  slog::Index** letrecindex161;  slog::Index** evaldelta162;  slog::Index** letrecdelta163;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord165({0, 1, 2});
      slog::Relation* readrel166 = db->getRelation("binding");
      head_index[0] = readrel166->getIndex(ord165, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord167({0, 1, 2});
      slog::Relation* readrel168 = db->getRelation("binding_event");
      head_index[1] = readrel168->getIndex(ord167, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord169({0, 2, 1});
      slog::Relation* readrel170 = db->getRelation("eval");
      evalindex158 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 2, 1});
      slog::Relation* readrel172 = db->getRelation("eval");
      evaldelta162 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({2, 1, 3, 0});
      slog::Relation* readrel174 = db->getRelation("letrec");
      letrecindex159 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({2, 0, 1});
      slog::Relation* readrel176 = db->getRelation("eval");
      evalindex160 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 2, 1, 3});
      slog::Relation* readrel178 = db->getRelation("letrec");
      letrecindex161 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 2, 1, 3});
      slog::Relation* readrel180 = db->getRelation("letrec");
      letrecdelta163 = readrel180->getIndex(ord179, true);
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        slog::join_probe_old<3,1>(evalindex158, evaldelta162, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m181) {
          u64 v_c3 = m181[1]; u64 v_c56 = m181[2];
          if (!slog::exists_probe<4,1>(letrecindex159, std::array<u64,4>{v_c56, 0, 0, 0})) return;
          slog::join_probe<3,1>(evalindex160, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m182) {
            u64 v_c57 = m182[1]; u64 v_c58 = m182[2];
            slog::join_probe_old<4,2>(letrecindex161, letrecdelta163, std::array<u64,4>{v_c58, v_c56, 0, 0}, [&](const std::array<u64,4>& m183) {
              u64 v_c36 = m183[2]; u64 v_c10 = m183[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c36, v_c3, v_c55}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c36, v_c3, v_c3}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask164* _cont = new ReadTask164(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), false);
  // (crule (pre) (scan freevar x er) (body (join-old letrec (2 1 3 0) 1 (2 1 3 0) er y eb __t3tSN159) (neq x y)) (head (emit freevar (0 1) x __t3tSN159)) freevars.slog:24 #f)
  class ReadTask186 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex184;  slog::Index** letrecdelta185;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord187({0, 1});
      slog::Relation* readrel188 = db->getRelation("freevar");
      head_index[0] = readrel188->getIndex(ord187, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord189({2, 1, 3, 0});
      slog::Relation* readrel190 = db->getRelation("letrec");
      letrecindex184 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({2, 1, 3, 0});
      slog::Relation* readrel192 = db->getRelation("letrec");
      letrecdelta185 = readrel192->getIndex(ord191, true);
  
    }
    ReadTask186(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        slog::join_probe_old<4,1>(letrecindex184, letrecdelta185, std::array<u64,4>{v_c56, 0, 0, 0}, [&](const std::array<u64,4>& m193) {
          u64 v_c5 = m193[1]; u64 v_c10 = m193[2]; u64 v_c59 = m193[3];
          if (v_c36 == v_c5) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c59}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask186* _cont = new ReadTask186(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask186(db,b), false);
  // (crule (pre) (scan select_branch_ans __t1sbj433 __v1) (body (join-old select_branch (0 1 2 3) 1 (0 1 2 3) __t1sbj433 __v0 e2 e3) (exists eval_ans (1 0) 1 __v0) (join $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3 e1 __d0 c) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9Q4F432) (join eval_ans (0 1) 2 __t9Q4F432 __v0)) (head (mkstruct eval (1 2 0) __9Gjy723 __v1 c)) interp.slog:87 #f)
  class ReadTask201 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex194;  slog::Index** eval_ansindex195;  slog::Index** $sup56712x86x0x0x0index196;  slog::Index** evalindex197;  slog::Index** eval_ansindex198;  slog::Index** select_branchdelta199;  slog::Index** evaldelta200;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord202({0, 1, 2, 3});
      slog::Relation* readrel203 = db->getRelation("select_branch");
      select_branchindex194 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({0, 1, 2, 3});
      slog::Relation* readrel205 = db->getRelation("select_branch");
      select_branchdelta199 = readrel205->getIndex(ord204, true);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("eval_ans");
      eval_ansindex195 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({3, 4, 2, 0, 1});
      slog::Relation* readrel209 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index196 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 0});
      slog::Relation* readrel211 = db->getRelation("eval");
      evalindex197 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("eval");
      evaldelta200 = readrel213->getIndex(ord212, true);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("eval_ans");
      eval_ansindex198 = readrel215->getIndex(ord214, false);
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<4,1>(select_branchindex194, select_branchdelta199, std::array<u64,4>{v_c60, 0, 0, 0}, [&](const std::array<u64,4>& m216) {
          u64 v_c38 = m216[1]; u64 v_c62 = m216[2]; u64 v_c63 = m216[3];
          if (!slog::exists_probe<2,1>(eval_ansindex195, std::array<u64,2>{v_c38, 0})) return;
          slog::join_probe<5,2>($sup56712x86x0x0x0index196, std::array<u64,5>{v_c62, v_c63, 0, 0, 0}, [&](const std::array<u64,5>& m217) {
            u64 v_c64 = m217[2]; u64 v_c65 = m217[3]; u64 v_c3 = m217[4];
            slog::join_probe_old<3,2>(evalindex197, evaldelta200, std::array<u64,3>{v_c64, v_c3, 0}, [&](const std::array<u64,3>& m218) {
              u64 v_c66 = m218[2];
              slog::join_probe<2,2>(eval_ansindex198, std::array<u64,2>{v_c66, v_c38}, [&](const std::array<u64,2>& m219) {
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c61, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask201* _cont = new ReadTask201(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask201(db,b), false);
  // (crule (pre) (scan eval_ans __t9Q4F432 __v0) (body (exists select_branch (1 2 3 0) 1 __v0) (join-old eval (0 2 1) 1 (0 2 1) __t9Q4F432 c e1) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join-old select_branch (1 2 3 0) 3 (1 2 3 0) __v0 e2 e3 __t1sbj433) (join-old select_branch_ans (0 1) 1 (0 1) __t1sbj433 __v1)) (head (mkstruct eval (1 2 0) __9Gjy723 __v1 c)) interp.slog:87 #f)
  class ReadTask228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex220;  slog::Index** evalindex221;  slog::Index** $sup56712x86x0x0x0index222;  slog::Index** select_branchindex223;  slog::Index** select_branch_ansindex224;  slog::Index** evaldelta225;  slog::Index** select_branchdelta226;  slog::Index** select_branch_ansdelta227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord229({1, 2, 3, 0});
      slog::Relation* readrel230 = db->getRelation("select_branch");
      select_branchindex220 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 2, 1});
      slog::Relation* readrel232 = db->getRelation("eval");
      evalindex221 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 2, 1});
      slog::Relation* readrel234 = db->getRelation("eval");
      evaldelta225 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({1, 2, 0, 3, 4});
      slog::Relation* readrel236 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index222 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 3, 0});
      slog::Relation* readrel238 = db->getRelation("select_branch");
      select_branchindex223 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 3, 0});
      slog::Relation* readrel240 = db->getRelation("select_branch");
      select_branchdelta226 = readrel240->getIndex(ord239, true);
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("select_branch_ans");
      select_branch_ansindex224 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1});
      slog::Relation* readrel244 = db->getRelation("select_branch_ans");
      select_branch_ansdelta227 = readrel244->getIndex(ord243, true);
  
    }
    ReadTask228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex220, std::array<u64,4>{v_c38, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex221, evaldelta225, std::array<u64,3>{v_c66, 0, 0}, [&](const std::array<u64,3>& m245) {
          u64 v_c3 = m245[1]; u64 v_c64 = m245[2];
          slog::join_probe<5,2>($sup56712x86x0x0x0index222, std::array<u64,5>{v_c3, v_c64, 0, 0, 0}, [&](const std::array<u64,5>& m246) {
            u64 v_c65 = m246[2]; u64 v_c62 = m246[3]; u64 v_c63 = m246[4];
            slog::join_probe_old<4,3>(select_branchindex223, select_branchdelta226, std::array<u64,4>{v_c38, v_c62, v_c63, 0}, [&](const std::array<u64,4>& m247) {
              u64 v_c60 = m247[3];
              slog::join_probe_old<2,1>(select_branch_ansindex224, select_branch_ansdelta227, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m248) {
                u64 v_c61 = m248[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c61, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
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
  // (crule (pre) (scan eval __t9SPH430 er c) (body (exists eval (2 0 1) 1 c) (exists let (2 1 3 0) 1 er) (join eval_ans (0 1) 1 __t9SPH430 vr) (join eval (2 0 1) 1 c __4M4I787 __t66ko429) (join let (0 2 1 3) 2 __t66ko429 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex249;  slog::Index** letindex250;  slog::Index** eval_ansindex251;  slog::Index** evalindex252;  slog::Index** letindex253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord255({0, 1, 2});
      slog::Relation* readrel256 = db->getRelation("binding");
      head_index[0] = readrel256->getIndex(ord255, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord257({0, 1, 2});
      slog::Relation* readrel258 = db->getRelation("binding_event");
      head_index[1] = readrel258->getIndex(ord257, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord259({2, 0, 1});
      slog::Relation* readrel260 = db->getRelation("eval");
      evalindex249 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({2, 1, 3, 0});
      slog::Relation* readrel262 = db->getRelation("let");
      letindex250 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("eval_ans");
      eval_ansindex251 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({2, 0, 1});
      slog::Relation* readrel266 = db->getRelation("eval");
      evalindex252 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({0, 2, 1, 3});
      slog::Relation* readrel268 = db->getRelation("let");
      letindex253 = readrel268->getIndex(ord267, false);
  
    }
    ReadTask254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex249, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letindex250, std::array<u64,4>{v_c56, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex251, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m269) {
          u64 v_c55 = m269[1];
          slog::join_probe<3,1>(evalindex252, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m270) {
            u64 v_c68 = m270[1]; u64 v_c69 = m270[2];
            slog::join_probe<4,2>(letindex253, std::array<u64,4>{v_c69, v_c56, 0, 0}, [&](const std::array<u64,4>& m271) {
              u64 v_c36 = m271[2]; u64 v_c10 = m271[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c36, v_c3, v_c55}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c36, v_c3, v_c3}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask254* _cont = new ReadTask254(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask254(db,b), false);
  // (crule (pre) (scan eval_args __t60iG506 es c) (body (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t60iG506) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __t8a3x503 ef) (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval (1 2 0) 2 ef c) (join app (1 2 0) 2 ef es __t8eby502) (join eval (0 2 1) 3 __t8a3x503 c __t8eby502) (join eval (1 2 0) 2 ef c __t3A6m504) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join eval_args_ans (0 1) 1 __t60iG506 vs) (exists delta (2 0 1) 1 vs) (join prim (0 1) 1 __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex272;  slog::Index** evalindex273;  slog::Index** eval_args_ansindex274;  slog::Index** $sup56712x74x0x0x0index275;  slog::Index** evalindex276;  slog::Index** evalindex277;  slog::Index** appindex278;  slog::Index** evalindex279;  slog::Index** evalindex280;  slog::Index** eval_ansindex281;  slog::Index** eval_args_ansindex282;  slog::Index** deltaindex283;  slog::Index** primindex284;  slog::Index** deltaindex285;  slog::Index** delta_ansindex286;  slog::Index** deltadelta287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("eval_ans");
      head_index[0] = readrel290->getIndex(ord289, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord291({2, 0, 1});
      slog::Relation* readrel292 = db->getRelation("app");
      appindex272 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({2, 0, 1});
      slog::Relation* readrel294 = db->getRelation("eval");
      evalindex273 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0, 1});
      slog::Relation* readrel296 = db->getRelation("eval_args_ans");
      eval_args_ansindex274 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 3, 0, 2});
      slog::Relation* readrel298 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index275 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 2, 1});
      slog::Relation* readrel300 = db->getRelation("eval");
      evalindex276 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 0});
      slog::Relation* readrel302 = db->getRelation("eval");
      evalindex277 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("app");
      appindex278 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 2, 1});
      slog::Relation* readrel306 = db->getRelation("eval");
      evalindex279 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("eval");
      evalindex280 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("eval_ans");
      eval_ansindex281 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("eval_args_ans");
      eval_args_ansindex282 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({2, 0, 1});
      slog::Relation* readrel314 = db->getRelation("delta");
      deltaindex283 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({0, 1});
      slog::Relation* readrel316 = db->getRelation("prim");
      primindex284 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("delta");
      deltaindex285 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 2, 0});
      slog::Relation* readrel320 = db->getRelation("delta");
      deltadelta287 = readrel320->getIndex(ord319, true);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("delta_ans");
      delta_ansindex286 = readrel322->getIndex(ord321, false);
  
    }
    ReadTask288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(appindex272, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex273, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex274, std::array<u64,2>{v_c70, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index275, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m323) {
          u64 v_c71 = m323[2]; u64 v_c1 = m323[3];
          if (!slog::exists_probe<3,2>(evalindex276, std::array<u64,3>{v_c71, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex277, std::array<u64,3>{v_c1, v_c3, 0})) return;
          slog::join_probe<3,2>(appindex278, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m324) {
            u64 v_c72 = m324[2];
            slog::join_probe<3,3>(evalindex279, std::array<u64,3>{v_c71, v_c3, v_c72}, [&](const std::array<u64,3>& m325) {
              slog::join_probe<3,2>(evalindex280, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m326) {
                u64 v_c73 = m326[2];
                slog::join_probe<2,1>(eval_ansindex281, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m327) {
                  u64 v_c74 = m327[1];
                  slog::join_probe<2,1>(eval_args_ansindex282, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m328) {
                    u64 v_c32 = m328[1];
                    if (!slog::exists_probe<3,1>(deltaindex283, std::array<u64,3>{v_c32, 0, 0})) return;
                    slog::join_probe<2,1>(primindex284, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m329) {
                      u64 v_c75 = m329[1];
                      slog::join_probe_old<3,2>(deltaindex285, deltadelta287, std::array<u64,3>{v_c75, v_c32, 0}, [&](const std::array<u64,3>& m330) {
                        u64 v_c76 = m330[2];
                        slog::join_probe<2,1>(delta_ansindex286, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m331) {
                          u64 v_c77 = m331[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c77}, std::array<u16,2>{0, 1});
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
        ReadTask288* _cont = new ReadTask288(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask288(db,b), false);
  // (crule (pre (let __trid7ENB763 const119eb3a23d030ee0dfe9f807) (let __trel682S764 const4a59dbb9cb3129dfcc75170b) (let __tcol9bPN765 const5feceb66ffc86f38d952786c) (let __trel7EGz766 const4a59dbb9cb3129dfcc75170b) (let __tcol9cre767 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid7ENB763 __trel682S764 __tcol9bPN765 (1 2 3 4 0)) (tycheck c (accept seq) __trid7ENB763 __trel7EGz766 __tcol9cre767 (1 2 3 4 0)) (mkstruct eval (1 2 0) __34CN762 ef c)) interp.slog:42 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid332;  u32 sid333;  u32 sid334;  u32 sid335;  u32 sid336;  u32 sid337;  u32 sid338;  u32 sid339;  u32 sid340;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      sid332 = db->getRelation("app")->getStructId();
      sid333 = db->getRelation("boolean")->getStructId();
      sid334 = db->getRelation("if")->getStructId();
      sid335 = db->getRelation("lambda")->getStructId();
      sid336 = db->getRelation("let")->getStructId();
      sid337 = db->getRelation("letrec")->getStructId();
      sid338 = db->getRelation("num")->getStructId();
      sid339 = db->getRelation("ref")->getStructId();
      sid340 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c79 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c80 = v_const5feceb66ffc86f38d952786c;
      u64 v_c81 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c82 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c65 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid332 || decode_struct_id(v_c1) == sid333 || decode_struct_id(v_c1) == sid334 || decode_struct_id(v_c1) == sid335 || decode_struct_id(v_c1) == sid336 || decode_struct_id(v_c1) == sid337 || decode_struct_id(v_c1) == sid338 || decode_struct_id(v_c1) == sid339 || decode_struct_id(v_c1) == sid340))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c78, v_c79, v_c80, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c78, v_c81, v_c82, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask341* _cont = new ReadTask341(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask341(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1)) (scan temp0P9u1146 __t5HIm308) (body (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join boolval (1 0) 1 __t26fz305 __t7uE5306)) (head (emit delta_ans (0 1) __t5HIm308 __t7uE5306)) interp.slog:117 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex342;  slog::Index** boolvalindex343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("delta_ans");
      head_index[0] = readrel346->getIndex(ord345, false);
      outer_rel = db->getRelation("temp0P9u1146");
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("_enum");
      _enumindex342 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 0});
      slog::Relation* readrel350 = db->getRelation("boolval");
      boolvalindex343 = readrel350->getIndex(ord349, false);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        slog::join_probe<2,1>(_enumindex342, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m351) {
          u64 v_c85 = m351[1];
          slog::join_probe<2,1>(boolvalindex343, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m352) {
            u64 v_c86 = m352[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c86}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:temp0P9u1146", _fires);
  
      if (!_done)
      {
        ReadTask344* _cont = new ReadTask344(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask344(db,b), false);
  // (crule (pre) (scan app __t36c5191 ef es) (body (join eval (1 2 0) 1 __t36c5191 c __36hc798) (join freevar (0 1) 0 y __t75gL192) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t75gL192 xs eb)) (head (mkstruct eval_args (1 2 0) __9QEA799 es c)) interp.slog:56 #f)
  class ReadTask357 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex353;  slog::Index** freevarindex354;  slog::Index** bindingindex355;  slog::Index** lambdaindex356;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("eval");
      evalindex353 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("freevar");
      freevarindex354 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({0, 1, 2});
      slog::Relation* readrel363 = db->getRelation("binding");
      bindingindex355 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1, 2});
      slog::Relation* readrel365 = db->getRelation("lambda");
      lambdaindex356 = readrel365->getIndex(ord364, false);
  
    }
    ReadTask357(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(evalindex353, std::array<u64,3>{v_c87, 0, 0}, [&](const std::array<u64,3>& m366) {
          u64 v_c3 = m366[1]; u64 v_c88 = m366[2];
          slog::join_all<2>(freevarindex354, [&](const std::array<u64,2>& m367) {
            u64 v_c5 = m367[0]; u64 v_c89 = m367[1];
            slog::join_probe<3,1>(bindingindex355, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m368) {
              u64 v_c7 = m368[1]; u64 v_c8 = m368[2];
              slog::join_probe<3,1>(lambdaindex356, std::array<u64,3>{v_c89, 0, 0}, [&](const std::array<u64,3>& m369) {
                u64 v_c9 = m369[1]; u64 v_c10 = m369[2];
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
        ReadTask357* _cont = new ReadTask357(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask357(db,b), false);
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo3TKl513 __t59ft158 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2IHZ514 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Kdp515 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0AcC516 __t59ft158 _00024seq2) (join delta (1 2 0) 2 __tconst3bSs155 _00024seq2 __t2lyA156) (join closure (0 1 2) 1 __t59ft158 lm cb) (join any_bool (0) 0 b) (letp _00024sql2qfO508 (aslst _00024seq2)) (let chk0g8G1134 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk0g8G1134) (letp chk2yGe1135 (lref _00024sql2qfO508 _00024sqc65nX511)) (eq __t59ft158 chk2yGe1135) (letp chk4nBH1136 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk4nBH1136)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask379 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex370;  slog::Index** $seq_atrindex371;  slog::Index** $seq_atrindex372;  slog::Index** deltaindex373;  slog::Index** closureindex374;  slog::Index** any_boolindex375;  slog::Index** $seq_atdelta376;  slog::Index** $seq_atrdelta377;  slog::Index** $seq_atrdelta378;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord380({1, 0, 2});
      slog::Relation* readrel381 = db->getRelation("$seq_at");
      driver_index = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({1, 0, 2});
      slog::Relation* readrel383 = db->getRelation("$seq_at");
      $seq_atindex370 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0, 2});
      slog::Relation* readrel385 = db->getRelation("$seq_at");
      $seq_atdelta376 = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({1, 0, 2});
      slog::Relation* readrel387 = db->getRelation("$seq_atr");
      $seq_atrindex371 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0, 2});
      slog::Relation* readrel389 = db->getRelation("$seq_atr");
      $seq_atrdelta377 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({1, 0, 2});
      slog::Relation* readrel391 = db->getRelation("$seq_atr");
      $seq_atrindex372 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 0, 2});
      slog::Relation* readrel393 = db->getRelation("$seq_atr");
      $seq_atrdelta378 = readrel393->getIndex(ord392, true);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("delta");
      deltaindex373 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2});
      slog::Relation* readrel397 = db->getRelation("closure");
      closureindex374 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0});
      slog::Relation* readrel399 = db->getRelation("any_bool");
      any_boolindex375 = readrel399->getIndex(ord398, false);
  
    }
    ReadTask379(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c90 = v_const06abaa100ecef791ce028c56;
      u64 v_c91 = v_constd4735e3a265e16eee03f5971;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_const5feceb66ffc86f38d952786c;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c97 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c94, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m400) {
        u64 v_c98 = m400[1];
        u64 v_c99 = m400[2];
        if (buckethash(v_c98) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex370, $seq_atdelta376, std::array<u64,3>{v_c95, v_c98, v_c99}, [&](const std::array<u64,3>& m401) {
          slog::join_probe_old<3,3>($seq_atrindex371, $seq_atrdelta377, std::array<u64,3>{v_c96, v_c98, v_c99}, [&](const std::array<u64,3>& m402) {
            slog::join_probe_old<3,3>($seq_atrindex372, $seq_atrdelta378, std::array<u64,3>{v_c97, v_c98, v_c99}, [&](const std::array<u64,3>& m403) {
              slog::join_probe<3,2>(deltaindex373, std::array<u64,3>{v_c90, v_c99, 0}, [&](const std::array<u64,3>& m404) {
                u64 v_c100 = m404[2];
                slog::join_probe<3,1>(closureindex374, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m405) {
                  u64 v_c101 = m405[1]; u64 v_c7 = m405[2];
                  slog::join_all<1>(any_boolindex375, [&](const std::array<u64,1>& m406) {
                    u64 v_c102 = m406[0];
                    bool ok407 = true;
                    u64 v_c103 = _prim_aslst(db, v_c99, &ok407);
                    if (!ok407) return;
                    u64 v_c104 = _prim_llen(db, v_c103);
                    if (v_c104 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c91 != v_c104) return;
                    bool ok408 = true;
                    u64 v_c105 = _prim_lref(db, v_c103, v_c92, &ok408);
                    if (!ok408) return;
                    if (v_c98 != v_c105) return;
                    bool ok409 = true;
                    u64 v_c106 = _prim_lref(db, v_c103, v_c93, &ok409);
                    if (!ok409) return;
                    if (v_c98 != v_c106) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c100, v_c102});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c102}, std::array<u16,2>{1, 0});
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
        ReadTask379* _cont = new ReadTask379(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask379(db,b), false);
  // (crule (pre) (scan eval __7p9q702 __t7NtH303 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (join-old tick_ans (0 1) 1 (0 1) __t5Pln304 l) (join-old eval (2 0 1) 1 (2 0 1) c __t9B5D299 ef) (exists eval_ans (0 1) 1 __t9B5D299) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old eval_ans (0 1) 1 (0 1) __t9B5D299 __t4ng7301) (join-old eval_args_ans (0 1) 1 (0 1) __t6sYC302 vs) (join-old closure (0 1 2) 1 (0 1 2) __t4ng7301 __t4mHn300 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex410;  slog::Index** eval_argsindex411;  slog::Index** tickindex412;  slog::Index** tick_ansindex413;  slog::Index** evalindex414;  slog::Index** eval_ansindex415;  slog::Index** appindex416;  slog::Index** eval_argsindex417;  slog::Index** eval_args_ansindex418;  slog::Index** eval_ansindex419;  slog::Index** eval_args_ansindex420;  slog::Index** closureindex421;  slog::Index** lambdaindex422;  slog::Index** tickdelta423;  slog::Index** tick_ansdelta424;  slog::Index** evaldelta425;  slog::Index** appdelta426;  slog::Index** eval_argsdelta427;  slog::Index** eval_ansdelta428;  slog::Index** eval_args_ansdelta429;  slog::Index** closuredelta430;  slog::Index** lambdadelta431;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord433({0, 1, 2, 3});
      slog::Relation* readrel434 = db->getRelation("bind_params");
      head_index[0] = readrel434->getIndex(ord433, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord435({0, 1});
      slog::Relation* readrel436 = db->getRelation("call_event");
      head_index[1] = readrel436->getIndex(ord435, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord437({2, 0, 1});
      slog::Relation* readrel438 = db->getRelation("eval");
      evalindex410 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({2, 0, 1});
      slog::Relation* readrel440 = db->getRelation("eval_args");
      eval_argsindex411 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("tick");
      tickindex412 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("tick");
      tickdelta423 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("tick_ans");
      tick_ansindex413 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({0, 1});
      slog::Relation* readrel448 = db->getRelation("tick_ans");
      tick_ansdelta424 = readrel448->getIndex(ord447, true);
      std::vector<u16> ord449({2, 0, 1});
      slog::Relation* readrel450 = db->getRelation("eval");
      evalindex414 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({2, 0, 1});
      slog::Relation* readrel452 = db->getRelation("eval");
      evaldelta425 = readrel452->getIndex(ord451, true);
      std::vector<u16> ord453({0, 1});
      slog::Relation* readrel454 = db->getRelation("eval_ans");
      eval_ansindex415 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({0, 1, 2});
      slog::Relation* readrel456 = db->getRelation("app");
      appindex416 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({0, 1, 2});
      slog::Relation* readrel458 = db->getRelation("app");
      appdelta426 = readrel458->getIndex(ord457, true);
      std::vector<u16> ord459({1, 2, 0});
      slog::Relation* readrel460 = db->getRelation("eval_args");
      eval_argsindex417 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0});
      slog::Relation* readrel462 = db->getRelation("eval_args");
      eval_argsdelta427 = readrel462->getIndex(ord461, true);
      std::vector<u16> ord463({0, 1});
      slog::Relation* readrel464 = db->getRelation("eval_args_ans");
      eval_args_ansindex418 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({0, 1});
      slog::Relation* readrel466 = db->getRelation("eval_ans");
      eval_ansindex419 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("eval_ans");
      eval_ansdelta428 = readrel468->getIndex(ord467, true);
      std::vector<u16> ord469({0, 1});
      slog::Relation* readrel470 = db->getRelation("eval_args_ans");
      eval_args_ansindex420 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 1});
      slog::Relation* readrel472 = db->getRelation("eval_args_ans");
      eval_args_ansdelta429 = readrel472->getIndex(ord471, true);
      std::vector<u16> ord473({0, 1, 2});
      slog::Relation* readrel474 = db->getRelation("closure");
      closureindex421 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({0, 1, 2});
      slog::Relation* readrel476 = db->getRelation("closure");
      closuredelta430 = readrel476->getIndex(ord475, true);
      std::vector<u16> ord477({0, 1, 2});
      slog::Relation* readrel478 = db->getRelation("lambda");
      lambdaindex422 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({0, 1, 2});
      slog::Relation* readrel480 = db->getRelation("lambda");
      lambdadelta431 = readrel480->getIndex(ord479, true);
  
    }
    ReadTask432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex410, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex411, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex412, tickdelta423, std::array<u64,3>{v_c26, v_c3, 0}, [&](const std::array<u64,3>& m481) {
          u64 v_c25 = m481[2];
          slog::join_probe_old<2,1>(tick_ansindex413, tick_ansdelta424, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m482) {
            u64 v_c28 = m482[1];
            slog::join_probe_old<3,1>(evalindex414, evaldelta425, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m483) {
              u64 v_c29 = m483[1]; u64 v_c1 = m483[2];
              if (!slog::exists_probe<2,1>(eval_ansindex415, std::array<u64,2>{v_c29, 0})) return;
              slog::join_probe_old<3,2>(appindex416, appdelta426, std::array<u64,3>{v_c26, v_c1, 0}, [&](const std::array<u64,3>& m484) {
                u64 v_c2 = m484[2];
                slog::join_probe_old<3,2>(eval_argsindex417, eval_argsdelta427, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m485) {
                  u64 v_c30 = m485[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex418, std::array<u64,2>{v_c30, 0})) return;
                  slog::join_probe_old<2,1>(eval_ansindex419, eval_ansdelta428, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m486) {
                    u64 v_c31 = m486[1];
                    slog::join_probe_old<2,1>(eval_args_ansindex420, eval_args_ansdelta429, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m487) {
                      u64 v_c32 = m487[1];
                      slog::join_probe_old<3,1>(closureindex421, closuredelta430, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m488) {
                        u64 v_c33 = m488[1]; u64 v_c7 = m488[2];
                        slog::join_probe_old<3,1>(lambdaindex422, lambdadelta431, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m489) {
                          u64 v_c9 = m489[1]; u64 v_c10 = m489[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c32, v_c28, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c28, v_c3}, std::array<u16,2>{0, 1});
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
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp0MTF1056 __t5GYK254 __t6dUB289 __t7WBr286) (body (join lambda (1 2 0) 2 __t6dUB289 __t7WBr286 __t2Jtx290)) (head (emit-temp temp2Bvj1057 __t2Jtx290 __t5GYK254) (mkstruct letrec (2 1 3 0) __t8OWf292 __t2Jtx290 __tconst4G37291 __t5GYK254)) schemecfa.slog:70 #f)
  class ReadTask491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Bvj1057");
      head_rel[1] = db->getRelation("letrec");
      outer_rel = db->getRelation("temp0MTF1056");
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("lambda");
      lambdaindex490 = readrel493->getIndex(ord492, false);
  
    }
    ReadTask491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const889c19fd926bc4ca61c0b4d9;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c108 = _t[0];
        u64 v_c109 = _t[1];
        u64 v_c110 = _t[2];
        slog::join_probe<3,2>(lambdaindex490, std::array<u64,3>{v_c109, v_c110, 0}, [&](const std::array<u64,3>& m494) {
          u64 v_c111 = m494[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c111, v_c108});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c111, v_c107, v_c108}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp0MTF1056", _fires);
  
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
  // (crule (pre) (scan temp1wv51004 __t0whu162 es x) (body (let __t4ZSk163 (lcat __t0whu162 es))) (head (emit-temp temp8Yy11005 __t4ZSk163 x)) freevars.slog:35 #f)
  class ReadTask495 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8Yy11005");
      outer_rel = db->getRelation("temp1wv51004");
  
    }
    ReadTask495(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c113 = _prim_lcat(db, v_c112, v_c2);
        if (v_c113 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c113, v_c36});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp1wv51004", _fires);
  
      if (!_done)
      {
        ReadTask495* _cont = new ReadTask495(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask495(db,b), false);
  // (crule (pre (let __tconst04ab676 constcd2a69ce5ca278db1d6da969) (let _00024sqc0NDP645 constd4735e3a265e16eee03f5971) (let _00024sqc7bIa646 const5feceb66ffc86f38d952786c) (let _00024sqc1Uf7647 const6b86b273ff34fce19d6b804e) (let _00024sqo7IWL648 const5feceb66ffc86f38d952786c) (let _00024sqo5kNQ649 const6b86b273ff34fce19d6b804e) (let _00024sqo9k7p650 const6b86b273ff34fce19d6b804e) (let _00024sqo7Xo2651 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo7Xo2651 __t2qlr318 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7IWL648 __t2qlr318 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo5kNQ649 __t2qlr318 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo9k7p650 __t2qlr318 _00024seq2) (join _enum (0 1) 2 __t2qlr318 __tconst04ab676) (join delta (2 0 1) 1 _00024seq2 __t6QsA316 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql2g05643 (aslst _00024seq2)) (let chk50Q51027 (llen _00024sql2g05643)) (eq _00024sqc0NDP645 chk50Q51027) (letp chk9HUs1028 (lref _00024sql2g05643 _00024sqc7bIa646)) (eq __t2qlr318 chk9HUs1028) (letp chk8XzM1029 (lref _00024sql2g05643 _00024sqc1Uf7647)) (eq __t2qlr318 chk8XzM1029)) (head (emit-temp temp53FS1015 __t6QsA316 b) (mkstruct boolval (1 0) __t3y4C315 b)) interp.slog:112 #f)
  class ReadTask503 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex496;  slog::Index** $seq_atindex497;  slog::Index** $seq_atrindex498;  slog::Index** _enumindex499;  slog::Index** deltaindex500;  slog::Index** comparison_opindex501;  slog::Index** any_boolindex502;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp53FS1015");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord504({1, 0, 2});
      slog::Relation* readrel505 = db->getRelation("$seq_atr");
      driver_index = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({1, 0, 2});
      slog::Relation* readrel507 = db->getRelation("$seq_at");
      $seq_atindex496 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 0, 2});
      slog::Relation* readrel509 = db->getRelation("$seq_at");
      $seq_atindex497 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0, 2});
      slog::Relation* readrel511 = db->getRelation("$seq_atr");
      $seq_atrindex498 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("_enum");
      _enumindex499 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({2, 0, 1});
      slog::Relation* readrel515 = db->getRelation("delta");
      deltaindex500 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({0});
      slog::Relation* readrel517 = db->getRelation("comparison_op");
      comparison_opindex501 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({0});
      slog::Relation* readrel519 = db->getRelation("any_bool");
      any_boolindex502 = readrel519->getIndex(ord518, false);
  
    }
    ReadTask503(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c115 = v_constd4735e3a265e16eee03f5971;
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
      u64 v_c119 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c121, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m520) {
        u64 v_c122 = m520[1];
        u64 v_c99 = m520[2];
        if (buckethash(v_c122) != bucket) return;
        slog::join_probe<3,3>($seq_atindex496, std::array<u64,3>{v_c118, v_c122, v_c99}, [&](const std::array<u64,3>& m521) {
          slog::join_probe<3,3>($seq_atindex497, std::array<u64,3>{v_c119, v_c122, v_c99}, [&](const std::array<u64,3>& m522) {
            slog::join_probe<3,3>($seq_atrindex498, std::array<u64,3>{v_c120, v_c122, v_c99}, [&](const std::array<u64,3>& m523) {
              slog::join_probe<2,2>(_enumindex499, std::array<u64,2>{v_c122, v_c114}, [&](const std::array<u64,2>& m524) {
                slog::join_probe<3,1>(deltaindex500, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m525) {
                  u64 v_c123 = m525[1]; u64 v_c75 = m525[2];
                  slog::join_probe<1,1>(comparison_opindex501, std::array<u64,1>{v_c75}, [&](const std::array<u64,1>& m526) {
                    slog::join_all<1>(any_boolindex502, [&](const std::array<u64,1>& m527) {
                      u64 v_c102 = m527[0];
                      bool ok528 = true;
                      u64 v_c124 = _prim_aslst(db, v_c99, &ok528);
                      if (!ok528) return;
                      u64 v_c125 = _prim_llen(db, v_c124);
                      if (v_c125 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c115 != v_c125) return;
                      bool ok529 = true;
                      u64 v_c126 = _prim_lref(db, v_c124, v_c116, &ok529);
                      if (!ok529) return;
                      if (v_c122 != v_c126) return;
                      bool ok530 = true;
                      u64 v_c127 = _prim_lref(db, v_c124, v_c117, &ok530);
                      if (!ok530) return;
                      if (v_c122 != v_c127) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c123, v_c102});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c102}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask503* _cont = new ReadTask503(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask503(db,b), false);
  // (crule (pre) (scan $sup56712x86x0x0x0 __t9HBz103 c e1 e2 e3) (body (exists eval (0 2 1) 2 __t9HBz103 c) (exists eval (1 2 0) 2 e1 c) (exists select_branch (2 3 0 1) 2 e2 e3) (exists eval (2 0 1) 1 c) (join-old if (1 3 2 0) 3 (1 3 2 0) e1 e3 e2 __t2D2o102) (join-old eval (0 2 1) 3 (0 2 1) __t9HBz103 c __t2D2o102) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t0Z2s104) (exists eval_ans (0 1) 1 __t0Z2s104) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t8m22105 __v0) (join eval_ans (0 1) 2 __t0Z2s104 __v0) (join select_branch_ans (0 1) 1 __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join eval_ans (0 1) 1 __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask549 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex531;  slog::Index** evalindex532;  slog::Index** select_branchindex533;  slog::Index** evalindex534;  slog::Index** ifindex535;  slog::Index** evalindex536;  slog::Index** evalindex537;  slog::Index** eval_ansindex538;  slog::Index** select_branchindex539;  slog::Index** eval_ansindex540;  slog::Index** select_branch_ansindex541;  slog::Index** evalindex542;  slog::Index** eval_ansindex543;  slog::Index** ifdelta544;  slog::Index** evaldelta545;  slog::Index** evaldelta546;  slog::Index** select_branchdelta547;  slog::Index** evaldelta548;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord550({0, 1});
      slog::Relation* readrel551 = db->getRelation("eval_ans");
      head_index[0] = readrel551->getIndex(ord550, false);
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord552({0, 2, 1});
      slog::Relation* readrel553 = db->getRelation("eval");
      evalindex531 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 0});
      slog::Relation* readrel555 = db->getRelation("eval");
      evalindex532 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({2, 3, 0, 1});
      slog::Relation* readrel557 = db->getRelation("select_branch");
      select_branchindex533 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({2, 0, 1});
      slog::Relation* readrel559 = db->getRelation("eval");
      evalindex534 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 3, 2, 0});
      slog::Relation* readrel561 = db->getRelation("if");
      ifindex535 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 3, 2, 0});
      slog::Relation* readrel563 = db->getRelation("if");
      ifdelta544 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({0, 2, 1});
      slog::Relation* readrel565 = db->getRelation("eval");
      evalindex536 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 2, 1});
      slog::Relation* readrel567 = db->getRelation("eval");
      evaldelta545 = readrel567->getIndex(ord566, true);
      std::vector<u16> ord568({1, 2, 0});
      slog::Relation* readrel569 = db->getRelation("eval");
      evalindex537 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("eval");
      evaldelta546 = readrel571->getIndex(ord570, true);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("eval_ans");
      eval_ansindex538 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({2, 3, 0, 1});
      slog::Relation* readrel575 = db->getRelation("select_branch");
      select_branchindex539 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({2, 3, 0, 1});
      slog::Relation* readrel577 = db->getRelation("select_branch");
      select_branchdelta547 = readrel577->getIndex(ord576, true);
      std::vector<u16> ord578({0, 1});
      slog::Relation* readrel579 = db->getRelation("eval_ans");
      eval_ansindex540 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("select_branch_ans");
      select_branch_ansindex541 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("eval");
      evalindex542 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("eval");
      evaldelta548 = readrel585->getIndex(ord584, true);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("eval_ans");
      eval_ansindex543 = readrel587->getIndex(ord586, false);
  
    }
    ReadTask549(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c128 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c62 = _t[3];
        u64 v_c63 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex531, std::array<u64,3>{v_c128, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex532, std::array<u64,3>{v_c64, v_c3, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex533, std::array<u64,4>{v_c62, v_c63, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex534, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<4,3>(ifindex535, ifdelta544, std::array<u64,4>{v_c64, v_c63, v_c62, 0}, [&](const std::array<u64,4>& m588) {
          u64 v_c129 = m588[3];
          slog::join_probe_old<3,3>(evalindex536, evaldelta545, std::array<u64,3>{v_c128, v_c3, v_c129}, [&](const std::array<u64,3>& m589) {
            slog::join_probe_old<3,2>(evalindex537, evaldelta546, std::array<u64,3>{v_c64, v_c3, 0}, [&](const std::array<u64,3>& m590) {
              u64 v_c130 = m590[2];
              if (!slog::exists_probe<2,1>(eval_ansindex538, std::array<u64,2>{v_c130, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex539, select_branchdelta547, std::array<u64,4>{v_c62, v_c63, 0, 0}, [&](const std::array<u64,4>& m591) {
                u64 v_c131 = m591[2]; u64 v_c38 = m591[3];
                slog::join_probe<2,2>(eval_ansindex540, std::array<u64,2>{v_c130, v_c38}, [&](const std::array<u64,2>& m592) {
                  slog::join_probe<2,1>(select_branch_ansindex541, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m593) {
                    u64 v_c61 = m593[1];
                    slog::join_probe_old<3,2>(evalindex542, evaldelta548, std::array<u64,3>{v_c61, v_c3, 0}, [&](const std::array<u64,3>& m594) {
                      u64 v_c132 = m594[2];
                      slog::join_probe<2,1>(eval_ansindex543, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m595) {
                        u64 v_c133 = m595[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c128, v_c133}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask549* _cont = new ReadTask549(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask549(db,b), false);
  // (crule (pre) (scan app __t8eby502 ef es) (body (exists eval (1 2 0) 1 __t8eby502) (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (join $sup56712x74x0x0x0 (2 3 0 1) 2 ef es __t8a3x503 c) (join-old eval (0 2 1) 3 (0 2 1) __t8a3x503 c __t8eby502) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3A6m504) (exists eval_ans (0 1) 1 __t3A6m504) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (exists eval_args_ans (0 1) 1 __t60iG506) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join eval_args_ans (0 1) 1 __t60iG506 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex596;  slog::Index** evalindex597;  slog::Index** eval_argsindex598;  slog::Index** $sup56712x74x0x0x0index599;  slog::Index** evalindex600;  slog::Index** eval_argsindex601;  slog::Index** evalindex602;  slog::Index** eval_ansindex603;  slog::Index** eval_argsindex604;  slog::Index** eval_args_ansindex605;  slog::Index** eval_ansindex606;  slog::Index** eval_args_ansindex607;  slog::Index** deltaindex608;  slog::Index** primindex609;  slog::Index** deltaindex610;  slog::Index** delta_ansindex611;  slog::Index** evaldelta612;  slog::Index** evaldelta613;  slog::Index** eval_argsdelta614;  slog::Index** primdelta615;  slog::Index** deltadelta616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("eval_ans");
      head_index[0] = readrel619->getIndex(ord618, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("eval");
      evalindex596 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("eval");
      evalindex597 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("eval_args");
      eval_argsindex598 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({2, 3, 0, 1});
      slog::Relation* readrel627 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index599 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 2, 1});
      slog::Relation* readrel629 = db->getRelation("eval");
      evalindex600 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({0, 2, 1});
      slog::Relation* readrel631 = db->getRelation("eval");
      evaldelta612 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("eval_args");
      eval_argsindex601 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 0});
      slog::Relation* readrel635 = db->getRelation("eval");
      evalindex602 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 2, 0});
      slog::Relation* readrel637 = db->getRelation("eval");
      evaldelta613 = readrel637->getIndex(ord636, true);
      std::vector<u16> ord638({0, 1});
      slog::Relation* readrel639 = db->getRelation("eval_ans");
      eval_ansindex603 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("eval_args");
      eval_argsindex604 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("eval_args");
      eval_argsdelta614 = readrel643->getIndex(ord642, true);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("eval_args_ans");
      eval_args_ansindex605 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("eval_ans");
      eval_ansindex606 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("eval_args_ans");
      eval_args_ansindex607 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({2, 0, 1});
      slog::Relation* readrel651 = db->getRelation("delta");
      deltaindex608 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("prim");
      primindex609 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("prim");
      primdelta615 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("delta");
      deltaindex610 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("delta");
      deltadelta616 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("delta_ans");
      delta_ansindex611 = readrel661->getIndex(ord660, false);
  
    }
    ReadTask617(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,1>(evalindex596, std::array<u64,3>{v_c72, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex597, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex598, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index599, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m662) {
          u64 v_c71 = m662[2]; u64 v_c3 = m662[3];
          slog::join_probe_old<3,3>(evalindex600, evaldelta612, std::array<u64,3>{v_c71, v_c3, v_c72}, [&](const std::array<u64,3>& m663) {
            if (!slog::exists_probe<3,2>(eval_argsindex601, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<3,2>(evalindex602, evaldelta613, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m664) {
              u64 v_c73 = m664[2];
              if (!slog::exists_probe<2,1>(eval_ansindex603, std::array<u64,2>{v_c73, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex604, eval_argsdelta614, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m665) {
                u64 v_c70 = m665[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex605, std::array<u64,2>{v_c70, 0})) return;
                slog::join_probe<2,1>(eval_ansindex606, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m666) {
                  u64 v_c74 = m666[1];
                  slog::join_probe<2,1>(eval_args_ansindex607, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m667) {
                    u64 v_c32 = m667[1];
                    if (!slog::exists_probe<3,1>(deltaindex608, std::array<u64,3>{v_c32, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex609, primdelta615, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m668) {
                      u64 v_c75 = m668[1];
                      slog::join_probe_old<3,2>(deltaindex610, deltadelta616, std::array<u64,3>{v_c75, v_c32, 0}, [&](const std::array<u64,3>& m669) {
                        u64 v_c76 = m669[2];
                        slog::join_probe<2,1>(delta_ansindex611, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m670) {
                          u64 v_c77 = m670[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c77}, std::array<u16,2>{0, 1});
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
        ReadTask617* _cont = new ReadTask617(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask617(db,b), false);
  // (crule (pre) (scan eval_ans __t3A6m504 __t4zl0505) (body (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (exists delta (1 2 0) 1 op) (join-old eval (0 2 1) 1 (0 2 1) __t3A6m504 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old $sup56712x74x0x0x0 (1 2 3 0) 2 (1 2 3 0) c ef es __t8a3x503) (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval_args (1 2 0) 2 es c) (join-old app (1 2 0) 2 (1 2 0) ef es __t8eby502) (join-old eval (0 2 1) 3 (0 2 1) __t8a3x503 c __t8eby502) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (join-old eval_args_ans (0 1) 1 (0 1) __t60iG506 vs) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join-old delta_ans (0 1) 1 (0 1) __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask695 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex671;  slog::Index** deltaindex672;  slog::Index** evalindex673;  slog::Index** appindex674;  slog::Index** evalindex675;  slog::Index** eval_argsindex676;  slog::Index** $sup56712x74x0x0x0index677;  slog::Index** evalindex678;  slog::Index** eval_argsindex679;  slog::Index** appindex680;  slog::Index** evalindex681;  slog::Index** eval_argsindex682;  slog::Index** eval_args_ansindex683;  slog::Index** deltaindex684;  slog::Index** delta_ansindex685;  slog::Index** primdelta686;  slog::Index** evaldelta687;  slog::Index** $sup56712x74x0x0x0delta688;  slog::Index** appdelta689;  slog::Index** evaldelta690;  slog::Index** eval_argsdelta691;  slog::Index** eval_args_ansdelta692;  slog::Index** deltadelta693;  slog::Index** delta_ansdelta694;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("eval_ans");
      head_index[0] = readrel697->getIndex(ord696, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("prim");
      primindex671 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1});
      slog::Relation* readrel701 = db->getRelation("prim");
      primdelta686 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("delta");
      deltaindex672 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 2, 1});
      slog::Relation* readrel705 = db->getRelation("eval");
      evalindex673 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({0, 2, 1});
      slog::Relation* readrel707 = db->getRelation("eval");
      evaldelta687 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({1, 2, 0});
      slog::Relation* readrel709 = db->getRelation("app");
      appindex674 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({2, 0, 1});
      slog::Relation* readrel711 = db->getRelation("eval");
      evalindex675 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({2, 0, 1});
      slog::Relation* readrel713 = db->getRelation("eval_args");
      eval_argsindex676 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 2, 3, 0});
      slog::Relation* readrel715 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index677 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 3, 0});
      slog::Relation* readrel717 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta688 = readrel717->getIndex(ord716, true);
      std::vector<u16> ord718({0, 2, 1});
      slog::Relation* readrel719 = db->getRelation("eval");
      evalindex678 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 2, 0});
      slog::Relation* readrel721 = db->getRelation("eval_args");
      eval_argsindex679 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("app");
      appindex680 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 0});
      slog::Relation* readrel725 = db->getRelation("app");
      appdelta689 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 2, 1});
      slog::Relation* readrel727 = db->getRelation("eval");
      evalindex681 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 2, 1});
      slog::Relation* readrel729 = db->getRelation("eval");
      evaldelta690 = readrel729->getIndex(ord728, true);
      std::vector<u16> ord730({1, 2, 0});
      slog::Relation* readrel731 = db->getRelation("eval_args");
      eval_argsindex682 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 2, 0});
      slog::Relation* readrel733 = db->getRelation("eval_args");
      eval_argsdelta691 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({0, 1});
      slog::Relation* readrel735 = db->getRelation("eval_args_ans");
      eval_args_ansindex683 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({0, 1});
      slog::Relation* readrel737 = db->getRelation("eval_args_ans");
      eval_args_ansdelta692 = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({1, 2, 0});
      slog::Relation* readrel739 = db->getRelation("delta");
      deltaindex684 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("delta");
      deltadelta693 = readrel741->getIndex(ord740, true);
      std::vector<u16> ord742({0, 1});
      slog::Relation* readrel743 = db->getRelation("delta_ans");
      delta_ansindex685 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("delta_ans");
      delta_ansdelta694 = readrel745->getIndex(ord744, true);
  
    }
    ReadTask695(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        slog::join_probe_old<2,1>(primindex671, primdelta686, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m746) {
          u64 v_c75 = m746[1];
          if (!slog::exists_probe<3,1>(deltaindex672, std::array<u64,3>{v_c75, 0, 0})) return;
          slog::join_probe_old<3,1>(evalindex673, evaldelta687, std::array<u64,3>{v_c73, 0, 0}, [&](const std::array<u64,3>& m747) {
            u64 v_c3 = m747[1]; u64 v_c1 = m747[2];
            if (!slog::exists_probe<3,1>(appindex674, std::array<u64,3>{v_c1, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex675, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex676, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe_old<4,2>($sup56712x74x0x0x0index677, $sup56712x74x0x0x0delta688, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m748) {
              u64 v_c2 = m748[2]; u64 v_c71 = m748[3];
              if (!slog::exists_probe<3,2>(evalindex678, std::array<u64,3>{v_c71, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex679, std::array<u64,3>{v_c2, v_c3, 0})) return;
              slog::join_probe_old<3,2>(appindex680, appdelta689, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m749) {
                u64 v_c72 = m749[2];
                slog::join_probe_old<3,3>(evalindex681, evaldelta690, std::array<u64,3>{v_c71, v_c3, v_c72}, [&](const std::array<u64,3>& m750) {
                  slog::join_probe_old<3,2>(eval_argsindex682, eval_argsdelta691, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m751) {
                    u64 v_c70 = m751[2];
                    slog::join_probe_old<2,1>(eval_args_ansindex683, eval_args_ansdelta692, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m752) {
                      u64 v_c32 = m752[1];
                      slog::join_probe_old<3,2>(deltaindex684, deltadelta693, std::array<u64,3>{v_c75, v_c32, 0}, [&](const std::array<u64,3>& m753) {
                        u64 v_c76 = m753[2];
                        slog::join_probe_old<2,1>(delta_ansindex685, delta_ansdelta694, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m754) {
                          u64 v_c77 = m754[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c77}, std::array<u16,2>{0, 1});
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
        ReadTask695* _cont = new ReadTask695(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask695(db,b), false);
  // (crule (pre (let _00024sqc5Umw578 const6b86b273ff34fce19d6b804e) (let _00024sqc3t7M579 const5feceb66ffc86f38d952786c) (let _00024sqc8s9N580 const6b86b273ff34fce19d6b804e) (let _00024sqc7UCT581 const5feceb66ffc86f38d952786c) (let _00024sqo6m8k586 const5feceb66ffc86f38d952786c) (let __t4EG4161 (lempty))) (scan freevar x e) (body (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo6m8k586 e _00024seq0) (join-old argument_list (0) 1 (0) _00024seq0) (letp _00024sql6PLL576 (aslst _00024seq0)) (let _00024sqn6WLF577 (llen _00024sql6PLL576)) (cmp ge _00024sqn6WLF577 _00024sqc5Umw578) (letp chk4ELM1106 (lref _00024sql6PLL576 _00024sqc3t7M579)) (eq e chk4ELM1106) (let _00024sqp95yh582 (_0002d _00024sqn6WLF577 _00024sqc7UCT581)) (let es (lslice _00024sql6PLL576 _00024sqc8s9N580 _00024sqp95yh582))) (head (emit-temp temp4nra1103 __t4EG4161 e es x)) freevars.slog:35 #f)
  class ReadTask759 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex755;  slog::Index** argument_listindex756;  slog::Index** $seq_atdelta757;  slog::Index** argument_listdelta758;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4nra1103");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord760({1, 0, 2});
      slog::Relation* readrel761 = db->getRelation("$seq_at");
      $seq_atindex755 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0, 2});
      slog::Relation* readrel763 = db->getRelation("$seq_at");
      $seq_atdelta757 = readrel763->getIndex(ord762, true);
      std::vector<u16> ord764({0});
      slog::Relation* readrel765 = db->getRelation("argument_list");
      argument_listindex756 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0});
      slog::Relation* readrel767 = db->getRelation("argument_list");
      argument_listdelta758 = readrel767->getIndex(ord766, true);
  
    }
    ReadTask759(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const5feceb66ffc86f38d952786c;
      u64 v_c139 = _prim_lempty(db);
      if (v_c139 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c140 = _t[1];
        slog::join_probe_old<3,2>($seq_atindex755, $seq_atdelta757, std::array<u64,3>{v_c138, v_c140, 0}, [&](const std::array<u64,3>& m768) {
          u64 v_c141 = m768[2];
          slog::join_probe_old<1,1>(argument_listindex756, argument_listdelta758, std::array<u64,1>{v_c141}, [&](const std::array<u64,1>& m769) {
            bool ok770 = true;
            u64 v_c142 = _prim_aslst(db, v_c141, &ok770);
            if (!ok770) return;
            u64 v_c143 = _prim_llen(db, v_c142);
            if (v_c143 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c144 = _prim_ge(db, v_c143, v_c134);
            if (v_c144 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c144) return;
            bool ok772 = true;
            u64 v_c145 = _prim_lref(db, v_c142, v_c135, &ok772);
            if (!ok772) return;
            if (v_c140 != v_c145) return;
            u64 v_c146 = _prim__0002d(db, v_c143, v_c137);
            if (v_c146 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c2 = _prim_lslice(db, v_c142, v_c136, v_c146);
            if (v_c2 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c139, v_c140, v_c2, v_c36});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask759* _cont = new ReadTask759(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask759(db,b), false);
  // (crule (pre) (scan eval_args_ans __t5BFX27 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t5BFX27 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (2 0 1) 2 (2 0 1) es __t8j7u29 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t5MCM24) (exists eval_ans (0 1) 1 __t5MCM24) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join-old tick_ans (0 1) 1 (0 1) __t0DSy30 l) (join-old closure (0 1 2) 1 (0 1 2) __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t0xip28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask800 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex773;  slog::Index** appindex774;  slog::Index** evalindex775;  slog::Index** tickindex776;  slog::Index** evalindex777;  slog::Index** tickindex778;  slog::Index** appindex779;  slog::Index** evalindex780;  slog::Index** eval_ansindex781;  slog::Index** tickindex782;  slog::Index** tick_ansindex783;  slog::Index** eval_ansindex784;  slog::Index** tick_ansindex785;  slog::Index** closureindex786;  slog::Index** bindingindex787;  slog::Index** freevarindex788;  slog::Index** bindingindex789;  slog::Index** lambdaindex790;  slog::Index** eval_argsdelta791;  slog::Index** appdelta792;  slog::Index** evaldelta793;  slog::Index** tickdelta794;  slog::Index** tick_ansdelta795;  slog::Index** closuredelta796;  slog::Index** freevardelta797;  slog::Index** bindingdelta798;  slog::Index** lambdadelta799;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord801({0, 1, 2});
      slog::Relation* readrel802 = db->getRelation("binding");
      head_index[0] = readrel802->getIndex(ord801, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord803({0, 1, 2});
      slog::Relation* readrel804 = db->getRelation("binding_event");
      head_index[1] = readrel804->getIndex(ord803, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord805({0, 2, 1});
      slog::Relation* readrel806 = db->getRelation("eval_args");
      eval_argsindex773 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 2, 1});
      slog::Relation* readrel808 = db->getRelation("eval_args");
      eval_argsdelta791 = readrel808->getIndex(ord807, true);
      std::vector<u16> ord809({2, 0, 1});
      slog::Relation* readrel810 = db->getRelation("app");
      appindex774 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({2, 0, 1});
      slog::Relation* readrel812 = db->getRelation("eval");
      evalindex775 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({2, 0, 1});
      slog::Relation* readrel814 = db->getRelation("tick");
      tickindex776 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({2, 0, 1});
      slog::Relation* readrel816 = db->getRelation("eval");
      evalindex777 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("tick");
      tickindex778 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({2, 0, 1});
      slog::Relation* readrel820 = db->getRelation("app");
      appindex779 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({2, 0, 1});
      slog::Relation* readrel822 = db->getRelation("app");
      appdelta792 = readrel822->getIndex(ord821, true);
      std::vector<u16> ord823({1, 2, 0});
      slog::Relation* readrel824 = db->getRelation("eval");
      evalindex780 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("eval");
      evaldelta793 = readrel826->getIndex(ord825, true);
      std::vector<u16> ord827({0, 1});
      slog::Relation* readrel828 = db->getRelation("eval_ans");
      eval_ansindex781 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({1, 2, 0});
      slog::Relation* readrel830 = db->getRelation("tick");
      tickindex782 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({1, 2, 0});
      slog::Relation* readrel832 = db->getRelation("tick");
      tickdelta794 = readrel832->getIndex(ord831, true);
      std::vector<u16> ord833({0, 1});
      slog::Relation* readrel834 = db->getRelation("tick_ans");
      tick_ansindex783 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({0, 1});
      slog::Relation* readrel836 = db->getRelation("eval_ans");
      eval_ansindex784 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({0, 1});
      slog::Relation* readrel838 = db->getRelation("tick_ans");
      tick_ansindex785 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({0, 1});
      slog::Relation* readrel840 = db->getRelation("tick_ans");
      tick_ansdelta795 = readrel840->getIndex(ord839, true);
      std::vector<u16> ord841({0, 1, 2});
      slog::Relation* readrel842 = db->getRelation("closure");
      closureindex786 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({0, 1, 2});
      slog::Relation* readrel844 = db->getRelation("closure");
      closuredelta796 = readrel844->getIndex(ord843, true);
      std::vector<u16> ord845({1, 0, 2});
      slog::Relation* readrel846 = db->getRelation("binding");
      bindingindex787 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({1, 0});
      slog::Relation* readrel848 = db->getRelation("freevar");
      freevarindex788 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 0});
      slog::Relation* readrel850 = db->getRelation("freevar");
      freevardelta797 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({0, 1, 2});
      slog::Relation* readrel852 = db->getRelation("binding");
      bindingindex789 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({0, 1, 2});
      slog::Relation* readrel854 = db->getRelation("binding");
      bindingdelta798 = readrel854->getIndex(ord853, true);
      std::vector<u16> ord855({0, 1, 2});
      slog::Relation* readrel856 = db->getRelation("lambda");
      lambdaindex790 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({0, 1, 2});
      slog::Relation* readrel858 = db->getRelation("lambda");
      lambdadelta799 = readrel858->getIndex(ord857, true);
  
    }
    ReadTask800(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c147 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex773, eval_argsdelta791, std::array<u64,3>{v_c147, 0, 0}, [&](const std::array<u64,3>& m859) {
          u64 v_c3 = m859[1]; u64 v_c2 = m859[2];
          if (!slog::exists_probe<3,1>(appindex774, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex775, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex776, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<3,1>(evalindex777, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m860) {
            u64 v_c148 = m860[1]; u64 v_c149 = m860[2];
            if (!slog::exists_probe<3,2>(tickindex778, std::array<u64,3>{v_c149, v_c3, 0})) return;
            slog::join_probe_old<3,2>(appindex779, appdelta792, std::array<u64,3>{v_c2, v_c149, 0}, [&](const std::array<u64,3>& m861) {
              u64 v_c1 = m861[2];
              slog::join_probe_old<3,2>(evalindex780, evaldelta793, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m862) {
                u64 v_c150 = m862[2];
                if (!slog::exists_probe<2,1>(eval_ansindex781, std::array<u64,2>{v_c150, 0})) return;
                slog::join_probe_old<3,2>(tickindex782, tickdelta794, std::array<u64,3>{v_c149, v_c3, 0}, [&](const std::array<u64,3>& m863) {
                  u64 v_c151 = m863[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex783, std::array<u64,2>{v_c151, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex784, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m864) {
                    u64 v_c152 = m864[1];
                    slog::join_probe_old<2,1>(tick_ansindex785, tick_ansdelta795, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m865) {
                      u64 v_c28 = m865[1];
                      slog::join_probe_old<3,1>(closureindex786, closuredelta796, std::array<u64,3>{v_c152, 0, 0}, [&](const std::array<u64,3>& m866) {
                        u64 v_c153 = m866[1]; u64 v_c7 = m866[2];
                        if (!slog::exists_probe<3,1>(bindingindex787, std::array<u64,3>{v_c7, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex788, freevardelta797, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m867) {
                          u64 v_c5 = m867[1];
                          slog::join_probe_old<3,2>(bindingindex789, bindingdelta798, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m868) {
                            u64 v_c8 = m868[2];
                            slog::join_probe_old<3,1>(lambdaindex790, lambdadelta799, std::array<u64,3>{v_c153, 0, 0}, [&](const std::array<u64,3>& m869) {
                              u64 v_c9 = m869[1]; u64 v_c10 = m869[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c28, v_c8}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c28, v_c3}, std::array<u16,3>{0, 1, 2});
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
        ReadTask800* _cont = new ReadTask800(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask800(db,b), false);
  // (crule (pre) (scan eval_args_ans __t2HTD313 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t2HTD313 c es) (exists eval (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __d0 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t55UJ311) (join eval_ans (0 1) 1 __t55UJ311 __t9gUy312) (join-old prim (0 1) 1 (0 1) __t9gUy312 op)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
  class ReadTask879 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex870;  slog::Index** evalindex871;  slog::Index** $sup56712x74x0x0x0index872;  slog::Index** evalindex873;  slog::Index** eval_ansindex874;  slog::Index** primindex875;  slog::Index** eval_argsdelta876;  slog::Index** evaldelta877;  slog::Index** primdelta878;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord880({0, 2, 1});
      slog::Relation* readrel881 = db->getRelation("eval_args");
      eval_argsindex870 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({0, 2, 1});
      slog::Relation* readrel883 = db->getRelation("eval_args");
      eval_argsdelta876 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({2, 0, 1});
      slog::Relation* readrel885 = db->getRelation("eval");
      evalindex871 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 3, 0, 2});
      slog::Relation* readrel887 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index872 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("eval");
      evalindex873 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({1, 2, 0});
      slog::Relation* readrel891 = db->getRelation("eval");
      evaldelta877 = readrel891->getIndex(ord890, true);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("eval_ans");
      eval_ansindex874 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("prim");
      primindex875 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({0, 1});
      slog::Relation* readrel897 = db->getRelation("prim");
      primdelta878 = readrel897->getIndex(ord896, true);
  
    }
    ReadTask879(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex870, eval_argsdelta876, std::array<u64,3>{v_c154, 0, 0}, [&](const std::array<u64,3>& m898) {
          u64 v_c3 = m898[1]; u64 v_c2 = m898[2];
          if (!slog::exists_probe<3,1>(evalindex871, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x74x0x0x0index872, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m899) {
            u64 v_c65 = m899[2]; u64 v_c1 = m899[3];
            slog::join_probe_old<3,2>(evalindex873, evaldelta877, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m900) {
              u64 v_c155 = m900[2];
              slog::join_probe<2,1>(eval_ansindex874, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m901) {
                u64 v_c156 = m901[1];
                slog::join_probe_old<2,1>(primindex875, primdelta878, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m902) {
                  u64 v_c75 = m902[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c75, v_c32}, std::array<u16,3>{1, 2, 0});
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
        ReadTask879* _cont = new ReadTask879(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask879(db,b), false);
  // (crule (pre (let __trid3VF6773 const25f568921d120de09a5f575d) (let __trel3Pje774 const4a59dbb9cb3129dfcc75170b) (let __tcol4ZDP775 const5feceb66ffc86f38d952786c) (let __trel4q3y776 const4a59dbb9cb3129dfcc75170b) (let __tcol3Vnx777 const6b86b273ff34fce19d6b804e)) (scan $sup56712x91x0x0x0 __d0 c eb er x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3VF6773 __trel3Pje774 __tcol4ZDP775 (1 2 3 4 0)) (tycheck c (accept seq) __trid3VF6773 __trel4q3y776 __tcol3Vnx777 (1 2 3 4 0)) (mkstruct eval (1 2 0) __7jH5772 eb c)) interp.slog:92 #f)
  class ReadTask912 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid903;  u32 sid904;  u32 sid905;  u32 sid906;  u32 sid907;  u32 sid908;  u32 sid909;  u32 sid910;  u32 sid911;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      sid903 = db->getRelation("app")->getStructId();
      sid904 = db->getRelation("boolean")->getStructId();
      sid905 = db->getRelation("if")->getStructId();
      sid906 = db->getRelation("lambda")->getStructId();
      sid907 = db->getRelation("let")->getStructId();
      sid908 = db->getRelation("letrec")->getStructId();
      sid909 = db->getRelation("num")->getStructId();
      sid910 = db->getRelation("ref")->getStructId();
      sid911 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask912(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_const25f568921d120de09a5f575d;
      u64 v_c158 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c159 = v_const5feceb66ffc86f38d952786c;
      u64 v_c160 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c161 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c65 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c36 = _t[4];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid903 || decode_struct_id(v_c10) == sid904 || decode_struct_id(v_c10) == sid905 || decode_struct_id(v_c10) == sid906 || decode_struct_id(v_c10) == sid907 || decode_struct_id(v_c10) == sid908 || decode_struct_id(v_c10) == sid909 || decode_struct_id(v_c10) == sid910 || decode_struct_id(v_c10) == sid911))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c157, v_c158, v_c159, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c157, v_c160, v_c161, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask912* _cont = new ReadTask912(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask912(db,b), false);
  // (crule (pre) (scan eval_args_ans __t3i0k199 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t3i0k199 c es) (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __d0 ef) (exists app (1 2 0) 2 ef es) (join-old eval (1 2 0) 2 (1 2 0) ef c __t44Jo196) (exists eval_ans (0 1) 1 __t44Jo196) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join-old tick_ans (0 1) 1 (0 1) __t3z31201 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4ROj198 __t2BTJ197 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask935 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex913;  slog::Index** evalindex914;  slog::Index** appindex915;  slog::Index** tickindex916;  slog::Index** $sup56712x41x0x0x0index917;  slog::Index** appindex918;  slog::Index** evalindex919;  slog::Index** eval_ansindex920;  slog::Index** appindex921;  slog::Index** tickindex922;  slog::Index** tick_ansindex923;  slog::Index** eval_ansindex924;  slog::Index** tick_ansindex925;  slog::Index** closureindex926;  slog::Index** lambdaindex927;  slog::Index** eval_argsdelta928;  slog::Index** evaldelta929;  slog::Index** appdelta930;  slog::Index** tickdelta931;  slog::Index** tick_ansdelta932;  slog::Index** closuredelta933;  slog::Index** lambdadelta934;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord936({0, 2, 1});
      slog::Relation* readrel937 = db->getRelation("eval_args");
      eval_argsindex913 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({0, 2, 1});
      slog::Relation* readrel939 = db->getRelation("eval_args");
      eval_argsdelta928 = readrel939->getIndex(ord938, true);
      std::vector<u16> ord940({2, 0, 1});
      slog::Relation* readrel941 = db->getRelation("eval");
      evalindex914 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({2, 0, 1});
      slog::Relation* readrel943 = db->getRelation("app");
      appindex915 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({2, 0, 1});
      slog::Relation* readrel945 = db->getRelation("tick");
      tickindex916 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 3, 0, 2});
      slog::Relation* readrel947 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index917 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({1, 2, 0});
      slog::Relation* readrel949 = db->getRelation("app");
      appindex918 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 2, 0});
      slog::Relation* readrel951 = db->getRelation("eval");
      evalindex919 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("eval");
      evaldelta929 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("eval_ans");
      eval_ansindex920 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({1, 2, 0});
      slog::Relation* readrel957 = db->getRelation("app");
      appindex921 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("app");
      appdelta930 = readrel959->getIndex(ord958, true);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("tick");
      tickindex922 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 2, 0});
      slog::Relation* readrel963 = db->getRelation("tick");
      tickdelta931 = readrel963->getIndex(ord962, true);
      std::vector<u16> ord964({0, 1});
      slog::Relation* readrel965 = db->getRelation("tick_ans");
      tick_ansindex923 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({0, 1});
      slog::Relation* readrel967 = db->getRelation("eval_ans");
      eval_ansindex924 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({0, 1});
      slog::Relation* readrel969 = db->getRelation("tick_ans");
      tick_ansindex925 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({0, 1});
      slog::Relation* readrel971 = db->getRelation("tick_ans");
      tick_ansdelta932 = readrel971->getIndex(ord970, true);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("closure");
      closureindex926 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({0, 1, 2});
      slog::Relation* readrel975 = db->getRelation("closure");
      closuredelta933 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({0, 1, 2});
      slog::Relation* readrel977 = db->getRelation("lambda");
      lambdaindex927 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({0, 1, 2});
      slog::Relation* readrel979 = db->getRelation("lambda");
      lambdadelta934 = readrel979->getIndex(ord978, true);
  
    }
    ReadTask935(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c162 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex913, eval_argsdelta928, std::array<u64,3>{v_c162, 0, 0}, [&](const std::array<u64,3>& m980) {
          u64 v_c3 = m980[1]; u64 v_c2 = m980[2];
          if (!slog::exists_probe<3,1>(evalindex914, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex915, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex916, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index917, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m981) {
            u64 v_c65 = m981[2]; u64 v_c1 = m981[3];
            if (!slog::exists_probe<3,2>(appindex918, std::array<u64,3>{v_c1, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex919, evaldelta929, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m982) {
              u64 v_c163 = m982[2];
              if (!slog::exists_probe<2,1>(eval_ansindex920, std::array<u64,2>{v_c163, 0})) return;
              slog::join_probe_old<3,2>(appindex921, appdelta930, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m983) {
                u64 v_c164 = m983[2];
                slog::join_probe_old<3,2>(tickindex922, tickdelta931, std::array<u64,3>{v_c164, v_c3, 0}, [&](const std::array<u64,3>& m984) {
                  u64 v_c165 = m984[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex923, std::array<u64,2>{v_c165, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex924, std::array<u64,2>{v_c163, 0}, [&](const std::array<u64,2>& m985) {
                    u64 v_c166 = m985[1];
                    slog::join_probe_old<2,1>(tick_ansindex925, tick_ansdelta932, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m986) {
                      u64 v_c38 = m986[1];
                      slog::join_probe_old<3,1>(closureindex926, closuredelta933, std::array<u64,3>{v_c166, 0, 0}, [&](const std::array<u64,3>& m987) {
                        u64 v_c167 = m987[1]; u64 v_c7 = m987[2];
                        slog::join_probe_old<3,1>(lambdaindex927, lambdadelta934, std::array<u64,3>{v_c167, 0, 0}, [&](const std::array<u64,3>& m988) {
                          u64 v_c9 = m988[1]; u64 v_c10 = m988[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c38}, std::array<u16,3>{1, 2, 0});
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
        ReadTask935* _cont = new ReadTask935(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask935(db,b), false);
  // (crule (pre) (scan temp8Jp41175 c ef es) (body (join app (1 2 0) 2 ef es __t8D6k4)) (head (mkstruct tick (1 2 0) __4Wig779 __t8D6k4 c)) interp.slog:42 #f)
  class ReadTask990 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex989;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("temp8Jp41175");
      std::vector<u16> ord991({1, 2, 0});
      slog::Relation* readrel992 = db->getRelation("app");
      appindex989 = readrel992->getIndex(ord991, false);
  
    }
    ReadTask990(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,2>(appindex989, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m993) {
          u64 v_c168 = m993[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c168, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:temp8Jp41175", _fires);
  
      if (!_done)
      {
        ReadTask990* _cont = new ReadTask990(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask990(db,b), false);
  // (crule (pre) (scan prim __t4zl0505 op) (body (exists delta (1 2 0) 1 op) (join eval_ans (1 0) 1 __t4zl0505 __t3A6m504) (join eval (0 2 1) 1 __t3A6m504 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __t8a3x503) (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval_args (1 2 0) 2 es c) (join app (1 2 0) 2 ef es __t8eby502) (join eval (0 2 1) 3 __t8a3x503 c __t8eby502) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (join eval_args_ans (0 1) 1 __t60iG506 vs) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask1011 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex994;  slog::Index** eval_ansindex995;  slog::Index** evalindex996;  slog::Index** appindex997;  slog::Index** evalindex998;  slog::Index** eval_argsindex999;  slog::Index** $sup56712x74x0x0x0index1000;  slog::Index** evalindex1001;  slog::Index** eval_argsindex1002;  slog::Index** appindex1003;  slog::Index** evalindex1004;  slog::Index** eval_argsindex1005;  slog::Index** eval_args_ansindex1006;  slog::Index** deltaindex1007;  slog::Index** delta_ansindex1008;  slog::Index** eval_argsdelta1009;  slog::Index** deltadelta1010;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1012({0, 1});
      slog::Relation* readrel1013 = db->getRelation("eval_ans");
      head_index[0] = readrel1013->getIndex(ord1012, false);
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("delta");
      deltaindex994 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 0});
      slog::Relation* readrel1017 = db->getRelation("eval_ans");
      eval_ansindex995 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({0, 2, 1});
      slog::Relation* readrel1019 = db->getRelation("eval");
      evalindex996 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("app");
      appindex997 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({2, 0, 1});
      slog::Relation* readrel1023 = db->getRelation("eval");
      evalindex998 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({2, 0, 1});
      slog::Relation* readrel1025 = db->getRelation("eval_args");
      eval_argsindex999 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 3, 0});
      slog::Relation* readrel1027 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index1000 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({0, 2, 1});
      slog::Relation* readrel1029 = db->getRelation("eval");
      evalindex1001 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 0});
      slog::Relation* readrel1031 = db->getRelation("eval_args");
      eval_argsindex1002 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 2, 0});
      slog::Relation* readrel1033 = db->getRelation("app");
      appindex1003 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({0, 2, 1});
      slog::Relation* readrel1035 = db->getRelation("eval");
      evalindex1004 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({1, 2, 0});
      slog::Relation* readrel1037 = db->getRelation("eval_args");
      eval_argsindex1005 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({1, 2, 0});
      slog::Relation* readrel1039 = db->getRelation("eval_args");
      eval_argsdelta1009 = readrel1039->getIndex(ord1038, true);
      std::vector<u16> ord1040({0, 1});
      slog::Relation* readrel1041 = db->getRelation("eval_args_ans");
      eval_args_ansindex1006 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 2, 0});
      slog::Relation* readrel1043 = db->getRelation("delta");
      deltaindex1007 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 2, 0});
      slog::Relation* readrel1045 = db->getRelation("delta");
      deltadelta1010 = readrel1045->getIndex(ord1044, true);
      std::vector<u16> ord1046({0, 1});
      slog::Relation* readrel1047 = db->getRelation("delta_ans");
      delta_ansindex1008 = readrel1047->getIndex(ord1046, false);
  
    }
    ReadTask1011(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c75 = _t[1];
        if (!slog::exists_probe<3,1>(deltaindex994, std::array<u64,3>{v_c75, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex995, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m1048) {
          u64 v_c73 = m1048[1];
          slog::join_probe<3,1>(evalindex996, std::array<u64,3>{v_c73, 0, 0}, [&](const std::array<u64,3>& m1049) {
            u64 v_c3 = m1049[1]; u64 v_c1 = m1049[2];
            if (!slog::exists_probe<3,1>(appindex997, std::array<u64,3>{v_c1, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex998, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex999, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index1000, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m1050) {
              u64 v_c2 = m1050[2]; u64 v_c71 = m1050[3];
              if (!slog::exists_probe<3,2>(evalindex1001, std::array<u64,3>{v_c71, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex1002, std::array<u64,3>{v_c2, v_c3, 0})) return;
              slog::join_probe<3,2>(appindex1003, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m1051) {
                u64 v_c72 = m1051[2];
                slog::join_probe<3,3>(evalindex1004, std::array<u64,3>{v_c71, v_c3, v_c72}, [&](const std::array<u64,3>& m1052) {
                  slog::join_probe_old<3,2>(eval_argsindex1005, eval_argsdelta1009, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1053) {
                    u64 v_c70 = m1053[2];
                    slog::join_probe<2,1>(eval_args_ansindex1006, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m1054) {
                      u64 v_c32 = m1054[1];
                      slog::join_probe_old<3,2>(deltaindex1007, deltadelta1010, std::array<u64,3>{v_c75, v_c32, 0}, [&](const std::array<u64,3>& m1055) {
                        u64 v_c76 = m1055[2];
                        slog::join_probe<2,1>(delta_ansindex1008, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m1056) {
                          u64 v_c77 = m1056[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c77}, std::array<u16,2>{0, 1});
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
        ReadTask1011* _cont = new ReadTask1011(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1011(db,b), false);
  // (crule (pre) (scan temp53FS1015 __t6QsA316 b) (body (join boolval (1 0) 1 b __t3y4C315)) (head (emit delta_ans (0 1) __t6QsA316 __t3y4C315)) interp.slog:112 #f)
  class ReadTask1058 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex1057;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1059({0, 1});
      slog::Relation* readrel1060 = db->getRelation("delta_ans");
      head_index[0] = readrel1060->getIndex(ord1059, false);
      outer_rel = db->getRelation("temp53FS1015");
      std::vector<u16> ord1061({1, 0});
      slog::Relation* readrel1062 = db->getRelation("boolval");
      boolvalindex1057 = readrel1062->getIndex(ord1061, false);
  
    }
    ReadTask1058(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[1];
        slog::join_probe<2,1>(boolvalindex1057, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1063) {
          u64 v_c169 = m1063[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c123, v_c169}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:temp53FS1015", _fires);
  
      if (!_done)
      {
        ReadTask1058* _cont = new ReadTask1058(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1058(db,b), false);
  // (crule (pre (let __tconst69HS686 constcd2a69ce5ca278db1d6da969) (let _00024sqc0vxk654 constd4735e3a265e16eee03f5971) (let _00024sqc9Xix655 const5feceb66ffc86f38d952786c) (let _00024sqc63kA656 const6b86b273ff34fce19d6b804e) (let _00024sqo95lm657 const5feceb66ffc86f38d952786c) (let _00024sqo4EpM658 const6b86b273ff34fce19d6b804e) (let _00024sqo7bBz659 const6b86b273ff34fce19d6b804e) (let _00024sqo5IeL660 const5feceb66ffc86f38d952786c) (let __trid88QO687 consteefaed435882b14b69e99d78) (let __trel4WdJ688 constdede4476644eb06b5a48b866) (let __tcol9WTP689 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo95lm657 __t4TBU101 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4EpM658 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7bBz659 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5IeL660 __t4TBU101 _00024seq2) (join _enum (0 1) 2 __t4TBU101 __tconst69HS686) (join delta (2 0 1) 1 _00024seq2 __t3GFi99 op) (join arithmetic_op (0) 1 op) (letp _00024sql4o3F652 (aslst _00024seq2)) (let chk4hts1079 (llen _00024sql4o3F652)) (eq _00024sqc0vxk654 chk4hts1079) (letp chk5Qwh1080 (lref _00024sql4o3F652 _00024sqc9Xix655)) (eq __t4TBU101 chk5Qwh1080) (letp chk2wS31081 (lref _00024sql4o3F652 _00024sqc63kA656)) (eq __t4TBU101 chk2wS31081)) (head (tycheck __t4TBU101 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid88QO687 __trel4WdJ688 __tcol9WTP689 (1 2 3 4 0)) (emit delta_ans (0 1) __t3GFi99 __t4TBU101)) interp.slog:111 #f)
  class ReadTask1078 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1064;  slog::Index** $seq_atrindex1065;  slog::Index** $seq_atrindex1066;  slog::Index** _enumindex1067;  slog::Index** deltaindex1068;  slog::Index** arithmetic_opindex1069;  slog::Index** $seq_atdelta1070;  slog::Index** $seq_atrdelta1071;  slog::Index** $seq_atrdelta1072;
    u32 sid1075;  u32 sid1073;  u32 sid1074;  u32 sid1076;  u32 sid1077;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1079({0, 1});
      slog::Relation* readrel1080 = db->getRelation("delta_ans");
      head_index[1] = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({1, 0, 2});
      slog::Relation* readrel1082 = db->getRelation("$seq_at");
      driver_index = readrel1082->getIndex(ord1081, true);
      std::vector<u16> ord1083({1, 0, 2});
      slog::Relation* readrel1084 = db->getRelation("$seq_at");
      $seq_atindex1064 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({1, 0, 2});
      slog::Relation* readrel1086 = db->getRelation("$seq_at");
      $seq_atdelta1070 = readrel1086->getIndex(ord1085, true);
      std::vector<u16> ord1087({1, 0, 2});
      slog::Relation* readrel1088 = db->getRelation("$seq_atr");
      $seq_atrindex1065 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 0, 2});
      slog::Relation* readrel1090 = db->getRelation("$seq_atr");
      $seq_atrdelta1071 = readrel1090->getIndex(ord1089, true);
      std::vector<u16> ord1091({1, 0, 2});
      slog::Relation* readrel1092 = db->getRelation("$seq_atr");
      $seq_atrindex1066 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 0, 2});
      slog::Relation* readrel1094 = db->getRelation("$seq_atr");
      $seq_atrdelta1072 = readrel1094->getIndex(ord1093, true);
      std::vector<u16> ord1095({0, 1});
      slog::Relation* readrel1096 = db->getRelation("_enum");
      _enumindex1067 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({2, 0, 1});
      slog::Relation* readrel1098 = db->getRelation("delta");
      deltaindex1068 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0});
      slog::Relation* readrel1100 = db->getRelation("arithmetic_op");
      arithmetic_opindex1069 = readrel1100->getIndex(ord1099, false);
      sid1075 = db->getRelation("_enum")->getStructId();
      sid1073 = db->getRelation("boolval")->getStructId();
      sid1074 = db->getRelation("closure")->getStructId();
      sid1076 = db->getRelation("prim")->getStructId();
      sid1077 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c171 = v_constd4735e3a265e16eee03f5971;
      u64 v_c172 = v_const5feceb66ffc86f38d952786c;
      u64 v_c173 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c174 = v_const5feceb66ffc86f38d952786c;
      u64 v_c175 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c176 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c177 = v_const5feceb66ffc86f38d952786c;
      u64 v_c178 = v_consteefaed435882b14b69e99d78;
      u64 v_c179 = v_constdede4476644eb06b5a48b866;
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c174, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1101) {
        u64 v_c181 = m1101[1];
        u64 v_c99 = m1101[2];
        if (buckethash(v_c181) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1064, $seq_atdelta1070, std::array<u64,3>{v_c175, v_c181, v_c99}, [&](const std::array<u64,3>& m1102) {
          slog::join_probe_old<3,3>($seq_atrindex1065, $seq_atrdelta1071, std::array<u64,3>{v_c176, v_c181, v_c99}, [&](const std::array<u64,3>& m1103) {
            slog::join_probe_old<3,3>($seq_atrindex1066, $seq_atrdelta1072, std::array<u64,3>{v_c177, v_c181, v_c99}, [&](const std::array<u64,3>& m1104) {
              slog::join_probe<2,2>(_enumindex1067, std::array<u64,2>{v_c181, v_c170}, [&](const std::array<u64,2>& m1105) {
                slog::join_probe<3,1>(deltaindex1068, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m1106) {
                  u64 v_c182 = m1106[1]; u64 v_c75 = m1106[2];
                  slog::join_probe<1,1>(arithmetic_opindex1069, std::array<u64,1>{v_c75}, [&](const std::array<u64,1>& m1107) {
                    bool ok1108 = true;
                    u64 v_c183 = _prim_aslst(db, v_c99, &ok1108);
                    if (!ok1108) return;
                    u64 v_c184 = _prim_llen(db, v_c183);
                    if (v_c184 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c171 != v_c184) return;
                    bool ok1109 = true;
                    u64 v_c185 = _prim_lref(db, v_c183, v_c172, &ok1109);
                    if (!ok1109) return;
                    if (v_c181 != v_c185) return;
                    bool ok1110 = true;
                    u64 v_c186 = _prim_lref(db, v_c183, v_c173, &ok1110);
                    if (!ok1110) return;
                    if (v_c181 != v_c186) return;
                    ++_fires;
                    if (!((is_struct(v_c181) && (decode_struct_id(v_c181) == sid1073 || decode_struct_id(v_c181) == sid1074 || decode_struct_id(v_c181) == sid1075 || decode_struct_id(v_c181) == sid1076 || decode_struct_id(v_c181) == sid1077))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c178, v_c179, v_c180, v_c181}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c182, v_c181}, std::array<u16,2>{0, 1});
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
        ReadTask1078* _cont = new ReadTask1078(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1078(db,b), false);
  // (crule (pre) (scan eval __1mVf736 __t8Z3R127 c) (body (join-old app (0 1 2) 1 (0 1 2) __t8Z3R127 ef es) (join freevar (0 1) 0 y __t8ny9128) (join binding (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t8ny9128 xs eb)) (head (mkstruct eval (1 2 0) __8uDI737 ef c)) interp.slog:56 #f)
  class ReadTask1116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1111;  slog::Index** freevarindex1112;  slog::Index** bindingindex1113;  slog::Index** lambdaindex1114;  slog::Index** appdelta1115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1117({0, 1, 2});
      slog::Relation* readrel1118 = db->getRelation("app");
      appindex1111 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({0, 1, 2});
      slog::Relation* readrel1120 = db->getRelation("app");
      appdelta1115 = readrel1120->getIndex(ord1119, true);
      std::vector<u16> ord1121({0, 1});
      slog::Relation* readrel1122 = db->getRelation("freevar");
      freevarindex1112 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({0, 1, 2});
      slog::Relation* readrel1124 = db->getRelation("binding");
      bindingindex1113 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({0, 1, 2});
      slog::Relation* readrel1126 = db->getRelation("lambda");
      lambdaindex1114 = readrel1126->getIndex(ord1125, false);
  
    }
    ReadTask1116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(appindex1111, appdelta1115, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m1127) {
          u64 v_c1 = m1127[1]; u64 v_c2 = m1127[2];
          slog::join_all<2>(freevarindex1112, [&](const std::array<u64,2>& m1128) {
            u64 v_c5 = m1128[0]; u64 v_c6 = m1128[1];
            slog::join_probe<3,1>(bindingindex1113, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m1129) {
              u64 v_c7 = m1129[1]; u64 v_c8 = m1129[2];
              slog::join_probe<3,1>(lambdaindex1114, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m1130) {
                u64 v_c9 = m1130[1]; u64 v_c10 = m1130[2];
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
        ReadTask1116* _cont = new ReadTask1116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1116(db,b), false);
  // (crule (pre) (scan eval_args __t6sYC302 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (2 0 1) 2 (2 0 1) es __t7NtH303 ef) (join eval (1 2 0) 2 ef c __t9B5D299) (exists eval_ans (0 1) 1 __t9B5D299) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join tick_ans (0 1) 1 __t5Pln304 l) (join closure (0 1 2) 1 __t4ng7301 __t4mHn300 cb) (join lambda (0 1 2) 1 __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1131;  slog::Index** appindex1132;  slog::Index** tickindex1133;  slog::Index** eval_args_ansindex1134;  slog::Index** evalindex1135;  slog::Index** tickindex1136;  slog::Index** appindex1137;  slog::Index** evalindex1138;  slog::Index** eval_ansindex1139;  slog::Index** tickindex1140;  slog::Index** tick_ansindex1141;  slog::Index** eval_ansindex1142;  slog::Index** tick_ansindex1143;  slog::Index** closureindex1144;  slog::Index** lambdaindex1145;  slog::Index** appdelta1146;  slog::Index** tickdelta1147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1149({0, 1, 2, 3});
      slog::Relation* readrel1150 = db->getRelation("bind_params");
      head_index[0] = readrel1150->getIndex(ord1149, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1151({0, 1});
      slog::Relation* readrel1152 = db->getRelation("call_event");
      head_index[1] = readrel1152->getIndex(ord1151, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1153({2, 0, 1});
      slog::Relation* readrel1154 = db->getRelation("eval");
      evalindex1131 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({2, 0, 1});
      slog::Relation* readrel1156 = db->getRelation("app");
      appindex1132 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({2, 0, 1});
      slog::Relation* readrel1158 = db->getRelation("tick");
      tickindex1133 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({0, 1});
      slog::Relation* readrel1160 = db->getRelation("eval_args_ans");
      eval_args_ansindex1134 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({2, 0, 1});
      slog::Relation* readrel1162 = db->getRelation("eval");
      evalindex1135 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({1, 2, 0});
      slog::Relation* readrel1164 = db->getRelation("tick");
      tickindex1136 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({2, 0, 1});
      slog::Relation* readrel1166 = db->getRelation("app");
      appindex1137 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({2, 0, 1});
      slog::Relation* readrel1168 = db->getRelation("app");
      appdelta1146 = readrel1168->getIndex(ord1167, true);
      std::vector<u16> ord1169({1, 2, 0});
      slog::Relation* readrel1170 = db->getRelation("eval");
      evalindex1138 = readrel1170->getIndex(ord1169, false);
      std::vector<u16> ord1171({0, 1});
      slog::Relation* readrel1172 = db->getRelation("eval_ans");
      eval_ansindex1139 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({1, 2, 0});
      slog::Relation* readrel1174 = db->getRelation("tick");
      tickindex1140 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({1, 2, 0});
      slog::Relation* readrel1176 = db->getRelation("tick");
      tickdelta1147 = readrel1176->getIndex(ord1175, true);
      std::vector<u16> ord1177({0, 1});
      slog::Relation* readrel1178 = db->getRelation("tick_ans");
      tick_ansindex1141 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("eval_ans");
      eval_ansindex1142 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({0, 1});
      slog::Relation* readrel1182 = db->getRelation("tick_ans");
      tick_ansindex1143 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({0, 1, 2});
      slog::Relation* readrel1184 = db->getRelation("closure");
      closureindex1144 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({0, 1, 2});
      slog::Relation* readrel1186 = db->getRelation("lambda");
      lambdaindex1145 = readrel1186->getIndex(ord1185, false);
  
    }
    ReadTask1148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1131, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1132, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1133, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex1134, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1187) {
          u64 v_c32 = m1187[1];
          slog::join_probe<3,1>(evalindex1135, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m1188) {
            u64 v_c27 = m1188[1]; u64 v_c26 = m1188[2];
            if (!slog::exists_probe<3,2>(tickindex1136, std::array<u64,3>{v_c26, v_c3, 0})) return;
            slog::join_probe_old<3,2>(appindex1137, appdelta1146, std::array<u64,3>{v_c2, v_c26, 0}, [&](const std::array<u64,3>& m1189) {
              u64 v_c1 = m1189[2];
              slog::join_probe<3,2>(evalindex1138, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m1190) {
                u64 v_c29 = m1190[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1139, std::array<u64,2>{v_c29, 0})) return;
                slog::join_probe_old<3,2>(tickindex1140, tickdelta1147, std::array<u64,3>{v_c26, v_c3, 0}, [&](const std::array<u64,3>& m1191) {
                  u64 v_c25 = m1191[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1141, std::array<u64,2>{v_c25, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1142, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1192) {
                    u64 v_c31 = m1192[1];
                    slog::join_probe<2,1>(tick_ansindex1143, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1193) {
                      u64 v_c28 = m1193[1];
                      slog::join_probe<3,1>(closureindex1144, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m1194) {
                        u64 v_c33 = m1194[1]; u64 v_c7 = m1194[2];
                        slog::join_probe<3,1>(lambdaindex1145, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m1195) {
                          u64 v_c9 = m1195[1]; u64 v_c10 = m1195[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c9, v_c32, v_c28, v_c3}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c28, v_c3}, std::array<u16,2>{0, 1});
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
        ReadTask1148* _cont = new ReadTask1148(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1148(db,b), false);
  // (crule (pre (let __trid6yqO714 const781eda039ec10c193395ca07) (let __trel90ho715 const4a59dbb9cb3129dfcc75170b) (let __tcol1UVn716 const5feceb66ffc86f38d952786c) (let __trel6QRw717 const4a59dbb9cb3129dfcc75170b) (let __tcol9PtW718 const6b86b273ff34fce19d6b804e)) (scan $sup56712x93x0x0x0 __d0 c eb er x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid6yqO714 __trel90ho715 __tcol1UVn716 (1 2 3 4 0)) (tycheck c (accept seq) __trid6yqO714 __trel6QRw717 __tcol9PtW718 (1 2 3 4 0)) (mkstruct eval (1 2 0) __1H8O713 eb c)) interp.slog:94 #f)
  class ReadTask1205 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1196;  u32 sid1197;  u32 sid1198;  u32 sid1199;  u32 sid1200;  u32 sid1201;  u32 sid1202;  u32 sid1203;  u32 sid1204;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      sid1196 = db->getRelation("app")->getStructId();
      sid1197 = db->getRelation("boolean")->getStructId();
      sid1198 = db->getRelation("if")->getStructId();
      sid1199 = db->getRelation("lambda")->getStructId();
      sid1200 = db->getRelation("let")->getStructId();
      sid1201 = db->getRelation("letrec")->getStructId();
      sid1202 = db->getRelation("num")->getStructId();
      sid1203 = db->getRelation("ref")->getStructId();
      sid1204 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c187 = v_const781eda039ec10c193395ca07;
      u64 v_c188 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c191 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c65 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c36 = _t[4];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid1196 || decode_struct_id(v_c10) == sid1197 || decode_struct_id(v_c10) == sid1198 || decode_struct_id(v_c10) == sid1199 || decode_struct_id(v_c10) == sid1200 || decode_struct_id(v_c10) == sid1201 || decode_struct_id(v_c10) == sid1202 || decode_struct_id(v_c10) == sid1203 || decode_struct_id(v_c10) == sid1204))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c187, v_c188, v_c189, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c3)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c187, v_c190, v_c191, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1205* _cont = new ReadTask1205(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1205(db,b), false);
}

