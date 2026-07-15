
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const00b70a53bc33238570e12d7a;
extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const71dc04e9084b526ffd253a28;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const829935b42173b360da35f679;
extern u64 v_const879923da020d1533f4d8e921;
extern u64 v_const8c8656c5d114d7f8b2a412d2;
extern u64 v_const8ca5d81566f88badd698137a;
extern u64 v_const913be61629bf526ec23a58e7;
extern u64 v_const99565d312ddf7c579dcfd67c;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdcc297bb3300d9549a9d611a;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_cab8513954b29fbb4(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679)) (scan temp82x0969 __t34RH259 __t4sa5291 __t7Cof275 __t7jCf244) (body (join let (2 1 3 0) 3 __t34RH259 __tconst4aTz260 __t7jCf244 __t0Ieb261)) (head (emit-temp temp09au970 __t0Ieb261 __t4sa5291 __t7Cof275) (mkstruct let (2 1 3 0) __t0GXe277 __t7Cof275 __tconst2XD5276 __t0Ieb261)) analysis-demo.slog:21 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp09au970");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp82x0969");
      std::vector<u16> ord2({2, 1, 3, 0});
      slog::Relation* readrel3 = db->getRelation("let");
      letindex0 = readrel3->getIndex(ord2, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c1 = v_constf77801bebb40767a1b303d97;
      u64 v_c2 = v_const829935b42173b360da35f679;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c6 = _t[3];
        slog::join_probe<4,3>(letindex0, std::array<u64,4>{v_c3, v_c2, v_c6, 0}, [&](const std::array<u64,4>& m4) {
          u64 v_c7 = m4[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c7, v_c4, v_c5});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c5, v_c1, v_c7}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp82x0969", _fires);
  
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
  // (crule (pre) (scan select_branch __t7P7f365 __v0 e2 e3) (body (exists eval_ans (1 0) 1 __v0) (exists select_branch_ans (0 1) 1 __t7P7f365) (join $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3 e1 __d0 c) (join eval (1 2 0) 2 e1 c __t4vYZ364) (join eval_ans (0 1) 2 __t4vYZ364 __v0) (join select_branch_ans (0 1) 1 __t7P7f365 __v1)) (head (mkstruct eval (1 2 0) __4AHX627 __v1 c)) interp.slog:87 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex5;  slog::Index** select_branch_ansindex6;  slog::Index** $sup56712x86x0x0x0index7;  slog::Index** evalindex8;  slog::Index** eval_ansindex9;  slog::Index** select_branch_ansindex10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("eval_ans");
      eval_ansindex5 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({0, 1});
      slog::Relation* readrel15 = db->getRelation("select_branch_ans");
      select_branch_ansindex6 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({3, 4, 2, 0, 1});
      slog::Relation* readrel17 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index7 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 2, 0});
      slog::Relation* readrel19 = db->getRelation("eval");
      evalindex8 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("eval_ans");
      eval_ansindex9 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({0, 1});
      slog::Relation* readrel23 = db->getRelation("select_branch_ans");
      select_branch_ansindex10 = readrel23->getIndex(ord22, false);
  
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
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<2,1>(eval_ansindex5, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex6, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index7, std::array<u64,5>{v_c10, v_c11, 0, 0, 0}, [&](const std::array<u64,5>& m24) {
          u64 v_c12 = m24[2]; u64 v_c13 = m24[3]; u64 v_c14 = m24[4];
          slog::join_probe<3,2>(evalindex8, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m25) {
            u64 v_c15 = m25[2];
            slog::join_probe<2,2>(eval_ansindex9, std::array<u64,2>{v_c15, v_c9}, [&](const std::array<u64,2>& m26) {
              slog::join_probe<2,1>(select_branch_ansindex10, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m27) {
                u64 v_c16 = m27[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c16, v_c14}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch", _fires);
  
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
  // (crule (pre (let __trid5F87555 const342a69eb5a93251c8b7e179a) (let __trel3emh556 const4a59dbb9cb3129dfcc75170b) (let __tcol1tNK557 const5feceb66ffc86f38d952786c) (let __trel3KUa558 const4a59dbb9cb3129dfcc75170b) (let __tcol7jjn559 const6b86b273ff34fce19d6b804e)) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body) (head (tycheck e1 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid5F87555 __trel3emh556 __tcol1tNK557 (1 2 3 4 0)) (tycheck c (accept seq) __trid5F87555 __trel3KUa558 __tcol7jjn559 (1 2 3 4 0)) (mkstruct eval (1 2 0) __1ROB554 e1 c)) interp.slog:87 #f)
  class ReadTask37 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid28;  u32 sid29;  u32 sid30;  u32 sid31;  u32 sid32;  u32 sid33;  u32 sid34;  u32 sid35;  u32 sid36;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      sid28 = db->getRelation("app")->getStructId();
      sid29 = db->getRelation("boolean")->getStructId();
      sid30 = db->getRelation("if")->getStructId();
      sid31 = db->getRelation("lambda")->getStructId();
      sid32 = db->getRelation("let")->getStructId();
      sid33 = db->getRelation("letrec")->getStructId();
      sid34 = db->getRelation("num")->getStructId();
      sid35 = db->getRelation("ref")->getStructId();
      sid36 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c18 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        ++_fires;
        if (!((is_struct(v_c12) && (decode_struct_id(v_c12) == sid28 || decode_struct_id(v_c12) == sid29 || decode_struct_id(v_c12) == sid30 || decode_struct_id(v_c12) == sid31 || decode_struct_id(v_c12) == sid32 || decode_struct_id(v_c12) == sid33 || decode_struct_id(v_c12) == sid34 || decode_struct_id(v_c12) == sid35 || decode_struct_id(v_c12) == sid36))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c17, v_c18, v_c19, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c14)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c17, v_c20, v_c21, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c12, v_c14}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask37* _cont = new ReadTask37(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), false);
  // (crule (pre) (scan closure __t8UWw172 __t3anZ171 cb) (body (join eval_ans (1 0) 1 __t8UWw172 __t66Yt170) (join eval (0 2 1) 1 __t66Yt170 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join tick_ans (0 1) 1 __t9uJP175 __v0) (join lambda (0 1 2) 1 __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex38;  slog::Index** evalindex39;  slog::Index** eval_argsindex40;  slog::Index** appindex41;  slog::Index** tickindex42;  slog::Index** $sup56712x41x0x0x0index43;  slog::Index** appindex44;  slog::Index** eval_argsindex45;  slog::Index** eval_args_ansindex46;  slog::Index** appindex47;  slog::Index** tickindex48;  slog::Index** tick_ansindex49;  slog::Index** eval_args_ansindex50;  slog::Index** tick_ansindex51;  slog::Index** lambdaindex52;  slog::Index** eval_argsdelta53;  slog::Index** appdelta54;  slog::Index** tickdelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("eval_ans");
      eval_ansindex38 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 2, 1});
      slog::Relation* readrel60 = db->getRelation("eval");
      evalindex39 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({2, 0, 1});
      slog::Relation* readrel62 = db->getRelation("eval_args");
      eval_argsindex40 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("app");
      appindex41 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("tick");
      tickindex42 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 3, 0});
      slog::Relation* readrel68 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index43 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("app");
      appindex44 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("eval_args");
      eval_argsindex45 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("eval_args");
      eval_argsdelta53 = readrel74->getIndex(ord73, true);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("eval_args_ans");
      eval_args_ansindex46 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("app");
      appindex47 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("app");
      appdelta54 = readrel80->getIndex(ord79, true);
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("tick");
      tickindex48 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 0});
      slog::Relation* readrel84 = db->getRelation("tick");
      tickdelta55 = readrel84->getIndex(ord83, true);
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("tick_ans");
      tick_ansindex49 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("eval_args_ans");
      eval_args_ansindex50 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("tick_ans");
      tick_ansindex51 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({0, 1, 2});
      slog::Relation* readrel92 = db->getRelation("lambda");
      lambdaindex52 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[2];
        slog::join_probe<2,1>(eval_ansindex38, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m93) {
          u64 v_c25 = m93[1];
          slog::join_probe<3,1>(evalindex39, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m94) {
            u64 v_c14 = m94[1]; u64 v_c26 = m94[2];
            if (!slog::exists_probe<3,1>(eval_argsindex40, std::array<u64,3>{v_c14, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex41, std::array<u64,3>{v_c26, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex42, std::array<u64,3>{v_c14, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x41x0x0x0index43, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m95) {
              u64 v_c27 = m95[2]; u64 v_c13 = m95[3];
              if (!slog::exists_probe<3,2>(appindex44, std::array<u64,3>{v_c26, v_c27, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex45, eval_argsdelta53, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m96) {
                u64 v_c28 = m96[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex46, std::array<u64,2>{v_c28, 0})) return;
                slog::join_probe_old<3,2>(appindex47, appdelta54, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m97) {
                  u64 v_c29 = m97[2];
                  slog::join_probe_old<3,2>(tickindex48, tickdelta55, std::array<u64,3>{v_c29, v_c14, 0}, [&](const std::array<u64,3>& m98) {
                    u64 v_c30 = m98[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex49, std::array<u64,2>{v_c30, 0})) return;
                    slog::join_probe<2,1>(eval_args_ansindex50, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m99) {
                      u64 v_c31 = m99[1];
                      slog::join_probe<2,1>(tick_ansindex51, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m100) {
                        u64 v_c9 = m100[1];
                        slog::join_probe<3,1>(lambdaindex52, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m101) {
                          u64 v_c32 = m101[1]; u64 v_c33 = m101[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c33, v_c9}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre) (scan eval_ans __t3Egw332 __t68RF333) (body (join-old prim (0 1) 1 (0 1) __t68RF333 op) (join-old eval (0 2 1) 1 (0 2 1) __t3Egw332 c ef) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2Zls334) (join-old eval_args_ans (0 1) 1 (0 1) __t2Zls334 vs)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask112 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex102;  slog::Index** evalindex103;  slog::Index** eval_argsindex104;  slog::Index** $sup56712x74x0x0x0index105;  slog::Index** eval_argsindex106;  slog::Index** eval_args_ansindex107;  slog::Index** primdelta108;  slog::Index** evaldelta109;  slog::Index** eval_argsdelta110;  slog::Index** eval_args_ansdelta111;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("prim");
      primindex102 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("prim");
      primdelta108 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0, 2, 1});
      slog::Relation* readrel118 = db->getRelation("eval");
      evalindex103 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 2, 1});
      slog::Relation* readrel120 = db->getRelation("eval");
      evaldelta109 = readrel120->getIndex(ord119, true);
      std::vector<u16> ord121({2, 0, 1});
      slog::Relation* readrel122 = db->getRelation("eval_args");
      eval_argsindex104 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 3, 0});
      slog::Relation* readrel124 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index105 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 0});
      slog::Relation* readrel126 = db->getRelation("eval_args");
      eval_argsindex106 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 2, 0});
      slog::Relation* readrel128 = db->getRelation("eval_args");
      eval_argsdelta110 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("eval_args_ans");
      eval_args_ansindex107 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("eval_args_ans");
      eval_args_ansdelta111 = readrel132->getIndex(ord131, true);
  
    }
    ReadTask112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(primindex102, primdelta108, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m133) {
          u64 v_c36 = m133[1];
          slog::join_probe_old<3,1>(evalindex103, evaldelta109, std::array<u64,3>{v_c34, 0, 0}, [&](const std::array<u64,3>& m134) {
            u64 v_c14 = m134[1]; u64 v_c26 = m134[2];
            if (!slog::exists_probe<3,1>(eval_argsindex104, std::array<u64,3>{v_c14, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index105, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m135) {
              u64 v_c27 = m135[2]; u64 v_c13 = m135[3];
              slog::join_probe_old<3,2>(eval_argsindex106, eval_argsdelta110, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m136) {
                u64 v_c37 = m136[2];
                slog::join_probe_old<2,1>(eval_args_ansindex107, eval_args_ansdelta111, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m137) {
                  u64 v_c31 = m137[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c36, v_c31}, std::array<u16,3>{1, 2, 0});
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
        ReadTask112* _cont = new ReadTask112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask112(db,b), false);
  // (crule (pre (let __tconst3aMB13 const6b86b273ff34fce19d6b804e) (let __trid483D630 const71dc04e9084b526ffd253a28) (let __trel5eGB631 const00b70a53bc33238570e12d7a) (let __tcol5FTK632 const5feceb66ffc86f38d952786c)) (scan lambda __t89QP11 xs eb) (body (exists lst_absent (1 2 0) 1 xs) (exists lst_absent_ans (1 0) 1 __tconst3aMB13) (join freevar (1 0) 1 eb x) (join-old lst_absent (1 2 0) 2 (1 2 0) xs x __t2LT912) (join lst_absent_ans (1 0) 2 __tconst3aMB13 __t2LT912)) (head (tycheck x (accept str) __trid483D630 __trel5eGB631 __tcol5FTK632 (1 2 3 4 0)) (emit freevar (0 1) x __t89QP11)) freevars.slog:28 #f)
  class ReadTask144 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absentindex138;  slog::Index** lst_absent_ansindex139;  slog::Index** freevarindex140;  slog::Index** lst_absentindex141;  slog::Index** lst_absent_ansindex142;  slog::Index** lst_absentdelta143;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("freevar");
      head_index[1] = readrel146->getIndex(ord145, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("lst_absent");
      lst_absentindex138 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex139 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("freevar");
      freevarindex140 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 0});
      slog::Relation* readrel154 = db->getRelation("lst_absent");
      lst_absentindex141 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("lst_absent");
      lst_absentdelta143 = readrel156->getIndex(ord155, true);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex142 = readrel158->getIndex(ord157, false);
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c39 = v_const71dc04e9084b526ffd253a28;
      u64 v_c40 = v_const00b70a53bc33238570e12d7a;
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
        u64 v_c32 = _t[1];
        u64 v_c33 = _t[2];
        if (!slog::exists_probe<3,1>(lst_absentindex138, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<2,1>(lst_absent_ansindex139, std::array<u64,2>{v_c38, 0})) return;
        slog::join_probe<2,1>(freevarindex140, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m159) {
          u64 v_c43 = m159[1];
          slog::join_probe_old<3,2>(lst_absentindex141, lst_absentdelta143, std::array<u64,3>{v_c32, v_c43, 0}, [&](const std::array<u64,3>& m160) {
            u64 v_c44 = m160[2];
            slog::join_probe<2,2>(lst_absent_ansindex142, std::array<u64,2>{v_c38, v_c44}, [&](const std::array<u64,2>& m161) {
              ++_fires;
              if (!(is_str(v_c43)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c39, v_c40, v_c41, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c43, v_c42}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask144* _cont = new ReadTask144(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask144(db,b), false);
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0)) (scan temp5E9s870 __t0ECW197) (body (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (join boolval (1 0) 1 __t7sei194 __t2gQB195)) (head (emit delta_ans (0 1) __t0ECW197 __t2gQB195)) interp.slog:120 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex162;  slog::Index** boolvalindex163;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("delta_ans");
      head_index[0] = readrel166->getIndex(ord165, false);
      outer_rel = db->getRelation("temp5E9s870");
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("_enum");
      _enumindex162 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 0});
      slog::Relation* readrel170 = db->getRelation("boolval");
      boolvalindex163 = readrel170->getIndex(ord169, false);
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c46 = _t[0];
        slog::join_probe<2,1>(_enumindex162, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m171) {
          u64 v_c47 = m171[1];
          slog::join_probe<2,1>(boolvalindex163, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m172) {
            u64 v_c48 = m172[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c48}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:temp5E9s870", _fires);
  
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
  // (crule (pre) (scan app __t7pOP300 ef es) (body (join eval (1 2 0) 1 __t7pOP300 c __6RFP667)) (head (mkstruct eval_args (1 2 0) __80Wk668 es c)) interp.slog:48 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("eval");
      evalindex173 = readrel176->getIndex(ord175, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c27 = _t[2];
        slog::join_probe<3,1>(evalindex173, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m177) {
          u64 v_c14 = m177[1]; u64 v_c50 = m177[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c14}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre (let __tconst7saS665 constb9e118781cea1f9fa01462e0)) (scan temp9mFJ1033 __t1geM354) (body (join _enum (1 0) 1 __tconst7saS665 __t73g6351) (join boolval (1 0) 1 __t73g6351 __t1MPL352)) (head (emit delta_ans (0 1) __t1geM354 __t1MPL352)) interp.slog:114 #f)
  class ReadTask180 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex178;  slog::Index** boolvalindex179;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("delta_ans");
      head_index[0] = readrel182->getIndex(ord181, false);
      outer_rel = db->getRelation("temp9mFJ1033");
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("_enum");
      _enumindex178 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("boolval");
      boolvalindex179 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask180(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c52 = _t[0];
        slog::join_probe<2,1>(_enumindex178, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m187) {
          u64 v_c53 = m187[1];
          slog::join_probe<2,1>(boolvalindex179, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m188) {
            u64 v_c54 = m188[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c54}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:temp9mFJ1033", _fires);
  
      if (!_done)
      {
        ReadTask180* _cont = new ReadTask180(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask180(db,b), false);
  // (crule (pre) (scan eval __2M2m643 __t89GZ358 c) (body (join-old app (0 1 2) 1 (0 1 2) __t89GZ358 ef es)) (head (mkstruct tick (1 2 0) __5IkN644 __t89GZ358 c)) interp.slog:48 #f)
  class ReadTask191 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex189;  slog::Index** appdelta190;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord192({0, 1, 2});
      slog::Relation* readrel193 = db->getRelation("app");
      appindex189 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1, 2});
      slog::Relation* readrel195 = db->getRelation("app");
      appdelta190 = readrel195->getIndex(ord194, true);
  
    }
    ReadTask191(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe_old<3,1>(appindex189, appdelta190, std::array<u64,3>{v_c56, 0, 0}, [&](const std::array<u64,3>& m196) {
          u64 v_c26 = m196[1]; u64 v_c27 = m196[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c56, v_c14}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval __t56Is182 eb __v0) (body (exists tick_ans (1 0) 1 __v0) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t56Is182 v) (join tick_ans (1 0) 1 __v0 __t8kWT184) (join lambda (2 0 1) 1 eb __t7rcY179 xs) (join closure (1 2 0) 1 __t7rcY179 cb __t4yWQ180) (join eval_ans (1 0) 1 __t4yWQ180 __t6e44178) (join eval (0 2 1) 1 __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t8kWT184 c __t7cos183) (exists app (0 1 2) 2 __t7cos183 ef) (join eval (1 2 0) 2 __t7cos183 c __t6uzd177) (join $sup56712x41x0x0x0 (1 0 2 3) 3 c __t6uzd177 ef es) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (join eval_args (1 2 0) 2 es c __t6UxD181) (join eval_args_ans (0 1) 1 __t6UxD181 vs)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask218 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex197;  slog::Index** lambdaindex198;  slog::Index** eval_ansindex199;  slog::Index** tick_ansindex200;  slog::Index** lambdaindex201;  slog::Index** closureindex202;  slog::Index** eval_ansindex203;  slog::Index** evalindex204;  slog::Index** evalindex205;  slog::Index** $sup56712x41x0x0x0index206;  slog::Index** appindex207;  slog::Index** eval_argsindex208;  slog::Index** tickindex209;  slog::Index** appindex210;  slog::Index** evalindex211;  slog::Index** $sup56712x41x0x0x0index212;  slog::Index** appindex213;  slog::Index** eval_argsindex214;  slog::Index** eval_args_ansindex215;  slog::Index** tickdelta216;  slog::Index** appdelta217;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("eval_ans");
      head_index[0] = readrel220->getIndex(ord219, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord221({1, 0});
      slog::Relation* readrel222 = db->getRelation("tick_ans");
      tick_ansindex197 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({2, 0, 1});
      slog::Relation* readrel224 = db->getRelation("lambda");
      lambdaindex198 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1});
      slog::Relation* readrel226 = db->getRelation("eval_ans");
      eval_ansindex199 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("tick_ans");
      tick_ansindex200 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({2, 0, 1});
      slog::Relation* readrel230 = db->getRelation("lambda");
      lambdaindex201 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 0});
      slog::Relation* readrel232 = db->getRelation("closure");
      closureindex202 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("eval_ans");
      eval_ansindex203 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 2, 1});
      slog::Relation* readrel236 = db->getRelation("eval");
      evalindex204 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({2, 0, 1});
      slog::Relation* readrel238 = db->getRelation("eval");
      evalindex205 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 3, 0});
      slog::Relation* readrel240 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index206 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 2, 0});
      slog::Relation* readrel242 = db->getRelation("app");
      appindex207 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({2, 0, 1});
      slog::Relation* readrel244 = db->getRelation("eval_args");
      eval_argsindex208 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({0, 2, 1});
      slog::Relation* readrel246 = db->getRelation("tick");
      tickindex209 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 2, 1});
      slog::Relation* readrel248 = db->getRelation("tick");
      tickdelta216 = readrel248->getIndex(ord247, true);
      std::vector<u16> ord249({0, 1, 2});
      slog::Relation* readrel250 = db->getRelation("app");
      appindex210 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("eval");
      evalindex211 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0, 2, 3});
      slog::Relation* readrel254 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index212 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({0, 1, 2});
      slog::Relation* readrel256 = db->getRelation("app");
      appindex213 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({0, 1, 2});
      slog::Relation* readrel258 = db->getRelation("app");
      appdelta217 = readrel258->getIndex(ord257, true);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("eval_args");
      eval_argsindex214 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({0, 1});
      slog::Relation* readrel262 = db->getRelation("eval_args_ans");
      eval_args_ansindex215 = readrel262->getIndex(ord261, false);
  
    }
    ReadTask218(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex197, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex198, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex199, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m263) {
          u64 v_c58 = m263[1];
          slog::join_probe<2,1>(tick_ansindex200, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m264) {
            u64 v_c59 = m264[1];
            slog::join_probe<3,1>(lambdaindex201, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m265) {
              u64 v_c60 = m265[1]; u64 v_c32 = m265[2];
              slog::join_probe<3,1>(closureindex202, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m266) {
                u64 v_c24 = m266[1]; u64 v_c61 = m266[2];
                slog::join_probe<2,1>(eval_ansindex203, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m267) {
                  u64 v_c62 = m267[1];
                  slog::join_probe<3,1>(evalindex204, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m268) {
                    u64 v_c14 = m268[1]; u64 v_c26 = m268[2];
                    if (!slog::exists_probe<3,1>(evalindex205, std::array<u64,3>{v_c14, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index206, std::array<u64,4>{v_c14, v_c26, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex207, std::array<u64,3>{v_c26, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex208, std::array<u64,3>{v_c14, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex209, tickdelta216, std::array<u64,3>{v_c59, v_c14, 0}, [&](const std::array<u64,3>& m269) {
                      u64 v_c63 = m269[2];
                      if (!slog::exists_probe<3,2>(appindex210, std::array<u64,3>{v_c63, v_c26, 0})) return;
                      slog::join_probe<3,2>(evalindex211, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m270) {
                        u64 v_c64 = m270[2];
                        slog::join_probe<4,3>($sup56712x41x0x0x0index212, std::array<u64,4>{v_c14, v_c64, v_c26, 0}, [&](const std::array<u64,4>& m271) {
                          u64 v_c27 = m271[3];
                          slog::join_probe_old<3,3>(appindex213, appdelta217, std::array<u64,3>{v_c63, v_c26, v_c27}, [&](const std::array<u64,3>& m272) {
                            slog::join_probe<3,2>(eval_argsindex214, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m273) {
                              u64 v_c65 = m273[2];
                              slog::join_probe<2,1>(eval_args_ansindex215, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m274) {
                                u64 v_c31 = m274[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask218* _cont = new ReadTask218(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask218(db,b), false);
  // (crule (pre) (scan eval_ans __t6e44178 __t4yWQ180) (body (join-old eval (0 2 1) 1 (0 2 1) __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join-old $sup56712x41x0x0x0 (1 2 3 0) 2 (1 2 3 0) c ef es __t6uzd177) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (0 2 1) 2 (0 2 1) __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join-old eval_args_ans (0 1) 1 (0 1) __t6UxD181 vs) (join-old tick_ans (0 1) 1 (0 1) __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4yWQ180 __t7rcY179 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join-old eval_ans (0 1) 1 (0 1) __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex275;  slog::Index** evalindex276;  slog::Index** appindex277;  slog::Index** eval_argsindex278;  slog::Index** tickindex279;  slog::Index** $sup56712x41x0x0x0index280;  slog::Index** appindex281;  slog::Index** eval_argsindex282;  slog::Index** evalindex283;  slog::Index** appindex284;  slog::Index** tickindex285;  slog::Index** eval_argsindex286;  slog::Index** eval_args_ansindex287;  slog::Index** tickindex288;  slog::Index** tick_ansindex289;  slog::Index** eval_args_ansindex290;  slog::Index** tick_ansindex291;  slog::Index** evalindex292;  slog::Index** closureindex293;  slog::Index** lambdaindex294;  slog::Index** evalindex295;  slog::Index** eval_ansindex296;  slog::Index** evaldelta297;  slog::Index** $sup56712x41x0x0x0delta298;  slog::Index** evaldelta299;  slog::Index** appdelta300;  slog::Index** eval_argsdelta301;  slog::Index** tickdelta302;  slog::Index** eval_args_ansdelta303;  slog::Index** tick_ansdelta304;  slog::Index** closuredelta305;  slog::Index** lambdadelta306;  slog::Index** evaldelta307;  slog::Index** eval_ansdelta308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("eval_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord312({0, 2, 1});
      slog::Relation* readrel313 = db->getRelation("eval");
      evalindex275 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 2, 1});
      slog::Relation* readrel315 = db->getRelation("eval");
      evaldelta297 = readrel315->getIndex(ord314, true);
      std::vector<u16> ord316({2, 0, 1});
      slog::Relation* readrel317 = db->getRelation("eval");
      evalindex276 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("app");
      appindex277 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({2, 0, 1});
      slog::Relation* readrel321 = db->getRelation("eval_args");
      eval_argsindex278 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({2, 0, 1});
      slog::Relation* readrel323 = db->getRelation("tick");
      tickindex279 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 3, 0});
      slog::Relation* readrel325 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index280 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 3, 0});
      slog::Relation* readrel327 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta298 = readrel327->getIndex(ord326, true);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("app");
      appindex281 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("eval_args");
      eval_argsindex282 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({0, 2, 1});
      slog::Relation* readrel333 = db->getRelation("eval");
      evalindex283 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 2, 1});
      slog::Relation* readrel335 = db->getRelation("eval");
      evaldelta299 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1, 2});
      slog::Relation* readrel337 = db->getRelation("app");
      appindex284 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1, 2});
      slog::Relation* readrel339 = db->getRelation("app");
      appdelta300 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({1, 2, 0});
      slog::Relation* readrel341 = db->getRelation("tick");
      tickindex285 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 0});
      slog::Relation* readrel343 = db->getRelation("eval_args");
      eval_argsindex286 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 0});
      slog::Relation* readrel345 = db->getRelation("eval_args");
      eval_argsdelta301 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1});
      slog::Relation* readrel347 = db->getRelation("eval_args_ans");
      eval_args_ansindex287 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 2, 0});
      slog::Relation* readrel349 = db->getRelation("tick");
      tickindex288 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("tick");
      tickdelta302 = readrel351->getIndex(ord350, true);
      std::vector<u16> ord352({0, 1});
      slog::Relation* readrel353 = db->getRelation("tick_ans");
      tick_ansindex289 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({0, 1});
      slog::Relation* readrel355 = db->getRelation("eval_args_ans");
      eval_args_ansindex290 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("eval_args_ans");
      eval_args_ansdelta303 = readrel357->getIndex(ord356, true);
      std::vector<u16> ord358({0, 1});
      slog::Relation* readrel359 = db->getRelation("tick_ans");
      tick_ansindex291 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("tick_ans");
      tick_ansdelta304 = readrel361->getIndex(ord360, true);
      std::vector<u16> ord362({2, 0, 1});
      slog::Relation* readrel363 = db->getRelation("eval");
      evalindex292 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1, 2});
      slog::Relation* readrel365 = db->getRelation("closure");
      closureindex293 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1, 2});
      slog::Relation* readrel367 = db->getRelation("closure");
      closuredelta305 = readrel367->getIndex(ord366, true);
      std::vector<u16> ord368({0, 1, 2});
      slog::Relation* readrel369 = db->getRelation("lambda");
      lambdaindex294 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({0, 1, 2});
      slog::Relation* readrel371 = db->getRelation("lambda");
      lambdadelta306 = readrel371->getIndex(ord370, true);
      std::vector<u16> ord372({1, 2, 0});
      slog::Relation* readrel373 = db->getRelation("eval");
      evalindex295 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("eval");
      evaldelta307 = readrel375->getIndex(ord374, true);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("eval_ans");
      eval_ansindex296 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("eval_ans");
      eval_ansdelta308 = readrel379->getIndex(ord378, true);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c61 = _t[1];
        slog::join_probe_old<3,1>(evalindex275, evaldelta297, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m380) {
          u64 v_c14 = m380[1]; u64 v_c26 = m380[2];
          if (!slog::exists_probe<3,1>(evalindex276, std::array<u64,3>{v_c14, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex277, std::array<u64,3>{v_c26, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex278, std::array<u64,3>{v_c14, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex279, std::array<u64,3>{v_c14, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x41x0x0x0index280, $sup56712x41x0x0x0delta298, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m381) {
            u64 v_c27 = m381[2]; u64 v_c64 = m381[3];
            if (!slog::exists_probe<3,2>(appindex281, std::array<u64,3>{v_c26, v_c27, 0})) return;
            if (!slog::exists_probe<3,2>(eval_argsindex282, std::array<u64,3>{v_c27, v_c14, 0})) return;
            slog::join_probe_old<3,2>(evalindex283, evaldelta299, std::array<u64,3>{v_c64, v_c14, 0}, [&](const std::array<u64,3>& m382) {
              u64 v_c63 = m382[2];
              slog::join_probe_old<3,3>(appindex284, appdelta300, std::array<u64,3>{v_c63, v_c26, v_c27}, [&](const std::array<u64,3>& m383) {
                if (!slog::exists_probe<3,2>(tickindex285, std::array<u64,3>{v_c63, v_c14, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex286, eval_argsdelta301, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m384) {
                  u64 v_c65 = m384[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex287, std::array<u64,2>{v_c65, 0})) return;
                  slog::join_probe_old<3,2>(tickindex288, tickdelta302, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m385) {
                    u64 v_c59 = m385[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex289, std::array<u64,2>{v_c59, 0})) return;
                    slog::join_probe_old<2,1>(eval_args_ansindex290, eval_args_ansdelta303, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m386) {
                      u64 v_c31 = m386[1];
                      slog::join_probe_old<2,1>(tick_ansindex291, tick_ansdelta304, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m387) {
                        u64 v_c9 = m387[1];
                        if (!slog::exists_probe<3,1>(evalindex292, std::array<u64,3>{v_c9, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex293, closuredelta305, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m388) {
                          u64 v_c60 = m388[1]; u64 v_c24 = m388[2];
                          slog::join_probe_old<3,1>(lambdaindex294, lambdadelta306, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m389) {
                            u64 v_c32 = m389[1]; u64 v_c33 = m389[2];
                            slog::join_probe_old<3,2>(evalindex295, evaldelta307, std::array<u64,3>{v_c33, v_c9, 0}, [&](const std::array<u64,3>& m390) {
                              u64 v_c57 = m390[2];
                              slog::join_probe_old<2,1>(eval_ansindex296, eval_ansdelta308, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m391) {
                                u64 v_c58 = m391[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask309* _cont = new ReadTask309(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask309(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715)) (scan temp1Oz8967 __t34RH259 __t4sa5291 __t6mUC239 __t7Cof275 __t9Hvd221) (body (exists app (2 0 1) 1 __t6mUC239) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join app (1 2 0) 2 __t41cT241 __t6mUC239 __t1E72242)) (head (emit-temp temp6KbH968 __t1E72242 __t34RH259 __t4sa5291 __t7Cof275 __t9Hvd221) (mkstruct let (2 1 3 0) __t7jCf244 __t1E72242 __tconst7Bar243 __t9Hvd221)) analysis-demo.slog:21 #f)
  class ReadTask395 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex392;  slog::Index** refindex393;  slog::Index** appindex394;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6KbH968");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp1Oz8967");
      std::vector<u16> ord396({2, 0, 1});
      slog::Relation* readrel397 = db->getRelation("app");
      appindex392 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 0});
      slog::Relation* readrel399 = db->getRelation("ref");
      refindex393 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("app");
      appindex394 = readrel401->getIndex(ord400, false);
  
    }
    ReadTask395(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c1 = v_constf77801bebb40767a1b303d97;
      u64 v_c2 = v_const829935b42173b360da35f679;
      u64 v_c66 = v_const0388ead47e9d5ccfc5320715;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c67 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c68 = _t[4];
        if (!slog::exists_probe<3,1>(appindex392, std::array<u64,3>{v_c67, 0, 0})) return;
        slog::join_probe<2,1>(refindex393, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m402) {
          u64 v_c69 = m402[1];
          slog::join_probe<3,2>(appindex394, std::array<u64,3>{v_c69, v_c67, 0}, [&](const std::array<u64,3>& m403) {
            u64 v_c70 = m403[2];
            ++_fires;
            slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c70, v_c3, v_c4, v_c5, v_c68});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c70, v_c66, v_c68}, std::array<u16,4>{2, 1, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp1Oz8967", _fires);
  
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
  // (crule (pre) (scan eval __t3KJV375 eb c) (body (exists let (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t3KJV375) (join $sup56712x91x0x0x0 (1 2 0 3 4) 2 c eb __t9U3N373 er x) (exists eval (0 2 1) 2 __t9U3N373 c) (exists eval (1 2 0) 2 er c) (join let (2 1 3 0) 3 er x eb __t78XS372) (join eval (0 2 1) 3 __t9U3N373 c __t78XS372) (join eval (1 2 0) 2 er c __t7j91374) (join eval_ans (0 1) 1 __t7j91374 vr) (join eval_ans (0 1) 1 __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask415 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex404;  slog::Index** evalindex405;  slog::Index** eval_ansindex406;  slog::Index** $sup56712x91x0x0x0index407;  slog::Index** evalindex408;  slog::Index** evalindex409;  slog::Index** letindex410;  slog::Index** evalindex411;  slog::Index** evalindex412;  slog::Index** eval_ansindex413;  slog::Index** eval_ansindex414;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("eval_ans");
      head_index[0] = readrel417->getIndex(ord416, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord418({3, 0, 1, 2});
      slog::Relation* readrel419 = db->getRelation("let");
      letindex404 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({2, 0, 1});
      slog::Relation* readrel421 = db->getRelation("eval");
      evalindex405 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("eval_ans");
      eval_ansindex406 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 0, 3, 4});
      slog::Relation* readrel425 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index407 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({0, 2, 1});
      slog::Relation* readrel427 = db->getRelation("eval");
      evalindex408 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 2, 0});
      slog::Relation* readrel429 = db->getRelation("eval");
      evalindex409 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({2, 1, 3, 0});
      slog::Relation* readrel431 = db->getRelation("let");
      letindex410 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 2, 1});
      slog::Relation* readrel433 = db->getRelation("eval");
      evalindex411 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("eval");
      evalindex412 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1});
      slog::Relation* readrel437 = db->getRelation("eval_ans");
      eval_ansindex413 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 1});
      slog::Relation* readrel439 = db->getRelation("eval_ans");
      eval_ansindex414 = readrel439->getIndex(ord438, false);
  
    }
    ReadTask415(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<4,1>(letindex404, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex405, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex406, std::array<u64,2>{v_c71, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index407, std::array<u64,5>{v_c14, v_c33, 0, 0, 0}, [&](const std::array<u64,5>& m440) {
          u64 v_c72 = m440[2]; u64 v_c73 = m440[3]; u64 v_c43 = m440[4];
          if (!slog::exists_probe<3,2>(evalindex408, std::array<u64,3>{v_c72, v_c14, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex409, std::array<u64,3>{v_c73, v_c14, 0})) return;
          slog::join_probe<4,3>(letindex410, std::array<u64,4>{v_c73, v_c43, v_c33, 0}, [&](const std::array<u64,4>& m441) {
            u64 v_c74 = m441[3];
            slog::join_probe<3,3>(evalindex411, std::array<u64,3>{v_c72, v_c14, v_c74}, [&](const std::array<u64,3>& m442) {
              slog::join_probe<3,2>(evalindex412, std::array<u64,3>{v_c73, v_c14, 0}, [&](const std::array<u64,3>& m443) {
                u64 v_c75 = m443[2];
                slog::join_probe<2,1>(eval_ansindex413, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m444) {
                  u64 v_c76 = m444[1];
                  slog::join_probe<2,1>(eval_ansindex414, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m445) {
                    u64 v_c58 = m445[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c72, v_c58}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask415* _cont = new ReadTask415(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask415(db,b), false);
  // (crule (pre (let __tconst3aMB13 const6b86b273ff34fce19d6b804e) (let __trid483D630 const71dc04e9084b526ffd253a28) (let __trel5eGB631 const00b70a53bc33238570e12d7a) (let __tcol5FTK632 const5feceb66ffc86f38d952786c)) (scan lst_absent __t2LT912 xs x) (body (join lst_absent_ans (1 0) 2 __tconst3aMB13 __t2LT912) (exists lambda (1 2 0) 1 xs) (join freevar (0 1) 1 x eb) (join lambda (1 2 0) 2 xs eb __t89QP11)) (head (tycheck x (accept str) __trid483D630 __trel5eGB631 __tcol5FTK632 (1 2 3 4 0)) (emit freevar (0 1) x __t89QP11)) freevars.slog:28 #f)
  class ReadTask450 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absent_ansindex446;  slog::Index** lambdaindex447;  slog::Index** freevarindex448;  slog::Index** lambdaindex449;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord451({0, 1});
      slog::Relation* readrel452 = db->getRelation("freevar");
      head_index[1] = readrel452->getIndex(ord451, false);
      outer_rel = db->getRelation("lst_absent");
      std::vector<u16> ord453({1, 0});
      slog::Relation* readrel454 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex446 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 0});
      slog::Relation* readrel456 = db->getRelation("lambda");
      lambdaindex447 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({0, 1});
      slog::Relation* readrel458 = db->getRelation("freevar");
      freevarindex448 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 2, 0});
      slog::Relation* readrel460 = db->getRelation("lambda");
      lambdaindex449 = readrel460->getIndex(ord459, false);
  
    }
    ReadTask450(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c39 = v_const71dc04e9084b526ffd253a28;
      u64 v_c40 = v_const00b70a53bc33238570e12d7a;
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
        u64 v_c44 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c43 = _t[2];
        slog::join_probe<2,2>(lst_absent_ansindex446, std::array<u64,2>{v_c38, v_c44}, [&](const std::array<u64,2>& m461) {
          if (!slog::exists_probe<3,1>(lambdaindex447, std::array<u64,3>{v_c32, 0, 0})) return;
          slog::join_probe<2,1>(freevarindex448, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m462) {
            u64 v_c33 = m462[1];
            slog::join_probe<3,2>(lambdaindex449, std::array<u64,3>{v_c32, v_c33, 0}, [&](const std::array<u64,3>& m463) {
              u64 v_c42 = m463[2];
              ++_fires;
              if (!(is_str(v_c43)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c39, v_c40, v_c41, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c43, v_c42}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lst_absent", _fires);
  
      if (!_done)
      {
        ReadTask450* _cont = new ReadTask450(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask450(db,b), false);
  // (crule (pre) (scan let __t1kar129 x er eb) (body (join eval (1 2 0) 1 __t1kar129 c __4EnN698)) (head (mkstruct eval (1 2 0) __8Q4o699 er c)) interp.slog:93 #f)
  class ReadTask465 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex464;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("let");
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("eval");
      evalindex464 = readrel467->getIndex(ord466, false);
  
    }
    ReadTask465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c33 = _t[3];
        slog::join_probe<3,1>(evalindex464, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m468) {
          u64 v_c14 = m468[1]; u64 v_c78 = m468[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c73, v_c14}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask465* _cont = new ReadTask465(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask465(db,b), false);
  // (crule (pre) (scan closure __t4yWQ180 __t7rcY179 cb) (body (join eval_ans (1 0) 1 __t4yWQ180 __t6e44178) (join eval (0 2 1) 1 __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t6uzd177) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join lambda (0 1 2) 1 __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask495 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex469;  slog::Index** evalindex470;  slog::Index** evalindex471;  slog::Index** appindex472;  slog::Index** eval_argsindex473;  slog::Index** tickindex474;  slog::Index** $sup56712x41x0x0x0index475;  slog::Index** appindex476;  slog::Index** eval_argsindex477;  slog::Index** evalindex478;  slog::Index** appindex479;  slog::Index** tickindex480;  slog::Index** eval_argsindex481;  slog::Index** eval_args_ansindex482;  slog::Index** tickindex483;  slog::Index** tick_ansindex484;  slog::Index** eval_args_ansindex485;  slog::Index** tick_ansindex486;  slog::Index** evalindex487;  slog::Index** lambdaindex488;  slog::Index** evalindex489;  slog::Index** eval_ansindex490;  slog::Index** appdelta491;  slog::Index** eval_argsdelta492;  slog::Index** tickdelta493;  slog::Index** evaldelta494;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("eval_ans");
      head_index[0] = readrel497->getIndex(ord496, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord498({1, 0});
      slog::Relation* readrel499 = db->getRelation("eval_ans");
      eval_ansindex469 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 2, 1});
      slog::Relation* readrel501 = db->getRelation("eval");
      evalindex470 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({2, 0, 1});
      slog::Relation* readrel503 = db->getRelation("eval");
      evalindex471 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("app");
      appindex472 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({2, 0, 1});
      slog::Relation* readrel507 = db->getRelation("eval_args");
      eval_argsindex473 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({2, 0, 1});
      slog::Relation* readrel509 = db->getRelation("tick");
      tickindex474 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 2, 3, 0});
      slog::Relation* readrel511 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index475 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 2, 0});
      slog::Relation* readrel513 = db->getRelation("app");
      appindex476 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 2, 0});
      slog::Relation* readrel515 = db->getRelation("eval_args");
      eval_argsindex477 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({0, 2, 1});
      slog::Relation* readrel517 = db->getRelation("eval");
      evalindex478 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({0, 1, 2});
      slog::Relation* readrel519 = db->getRelation("app");
      appindex479 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({0, 1, 2});
      slog::Relation* readrel521 = db->getRelation("app");
      appdelta491 = readrel521->getIndex(ord520, true);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("tick");
      tickindex480 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 2, 0});
      slog::Relation* readrel525 = db->getRelation("eval_args");
      eval_argsindex481 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 2, 0});
      slog::Relation* readrel527 = db->getRelation("eval_args");
      eval_argsdelta492 = readrel527->getIndex(ord526, true);
      std::vector<u16> ord528({0, 1});
      slog::Relation* readrel529 = db->getRelation("eval_args_ans");
      eval_args_ansindex482 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("tick");
      tickindex483 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("tick");
      tickdelta493 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("tick_ans");
      tick_ansindex484 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("eval_args_ans");
      eval_args_ansindex485 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 1});
      slog::Relation* readrel539 = db->getRelation("tick_ans");
      tick_ansindex486 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({2, 0, 1});
      slog::Relation* readrel541 = db->getRelation("eval");
      evalindex487 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({0, 1, 2});
      slog::Relation* readrel543 = db->getRelation("lambda");
      lambdaindex488 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 2, 0});
      slog::Relation* readrel545 = db->getRelation("eval");
      evalindex489 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 0});
      slog::Relation* readrel547 = db->getRelation("eval");
      evaldelta494 = readrel547->getIndex(ord546, true);
      std::vector<u16> ord548({0, 1});
      slog::Relation* readrel549 = db->getRelation("eval_ans");
      eval_ansindex490 = readrel549->getIndex(ord548, false);
  
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
        u64 v_c61 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c24 = _t[2];
        slog::join_probe<2,1>(eval_ansindex469, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m550) {
          u64 v_c62 = m550[1];
          slog::join_probe<3,1>(evalindex470, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m551) {
            u64 v_c14 = m551[1]; u64 v_c26 = m551[2];
            if (!slog::exists_probe<3,1>(evalindex471, std::array<u64,3>{v_c14, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex472, std::array<u64,3>{v_c26, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex473, std::array<u64,3>{v_c14, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex474, std::array<u64,3>{v_c14, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x41x0x0x0index475, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m552) {
              u64 v_c27 = m552[2]; u64 v_c64 = m552[3];
              if (!slog::exists_probe<3,2>(appindex476, std::array<u64,3>{v_c26, v_c27, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex477, std::array<u64,3>{v_c27, v_c14, 0})) return;
              slog::join_probe<3,2>(evalindex478, std::array<u64,3>{v_c64, v_c14, 0}, [&](const std::array<u64,3>& m553) {
                u64 v_c63 = m553[2];
                slog::join_probe_old<3,3>(appindex479, appdelta491, std::array<u64,3>{v_c63, v_c26, v_c27}, [&](const std::array<u64,3>& m554) {
                  if (!slog::exists_probe<3,2>(tickindex480, std::array<u64,3>{v_c63, v_c14, 0})) return;
                  slog::join_probe_old<3,2>(eval_argsindex481, eval_argsdelta492, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m555) {
                    u64 v_c65 = m555[2];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex482, std::array<u64,2>{v_c65, 0})) return;
                    slog::join_probe_old<3,2>(tickindex483, tickdelta493, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m556) {
                      u64 v_c59 = m556[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex484, std::array<u64,2>{v_c59, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex485, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m557) {
                        u64 v_c31 = m557[1];
                        slog::join_probe<2,1>(tick_ansindex486, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m558) {
                          u64 v_c9 = m558[1];
                          if (!slog::exists_probe<3,1>(evalindex487, std::array<u64,3>{v_c9, 0, 0})) return;
                          slog::join_probe<3,1>(lambdaindex488, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m559) {
                            u64 v_c32 = m559[1]; u64 v_c33 = m559[2];
                            slog::join_probe_old<3,2>(evalindex489, evaldelta494, std::array<u64,3>{v_c33, v_c9, 0}, [&](const std::array<u64,3>& m560) {
                              u64 v_c57 = m560[2];
                              slog::join_probe<2,1>(eval_ansindex490, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m561) {
                                u64 v_c58 = m561[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:closure", _fires);
  
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
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst8Fnl80 const7297d2085ea0adffc396d546) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp8uWT1001 __t528g79 __t5Wmv107 __t7KRi101 __t8dvA109 __t9Kbk85) (body (exists ref (1 0) 1 __tconst8Fnl80) (exists app (2 0 1) 1 __t528g79) (exists ref (1 0) 1 __tconst2uSL111) (exists ref (1 0) 1 __tconst0xiC106) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join ref (1 0) 1 __tconst8Fnl80 __t0mBu81) (join app (1 2 0) 2 __t0mBu81 __t528g79 __t8wZP82) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join ref (1 0) 1 __tconst0xiC106 __t2Kfn98)) (head (emit-temp temp2CFC1002 __t5Wmv107 __t7KRi101 __t8dvA109 __t8wZP82 __t9Kbk85) (mkstruct app (1 2 0) __t223e104 __t2Kfn98 __t7KRi101) (mkstruct lambda (1 2 0) __t2Jp186 __t9Kbk85 __t8wZP82)) analysis-demo.slog:11 #f)
  class ReadTask571 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex562;  slog::Index** appindex563;  slog::Index** refindex564;  slog::Index** refindex565;  slog::Index** numindex566;  slog::Index** refindex567;  slog::Index** appindex568;  slog::Index** refindex569;  slog::Index** refindex570;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2CFC1002");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp8uWT1001");
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("ref");
      refindex562 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({2, 0, 1});
      slog::Relation* readrel575 = db->getRelation("app");
      appindex563 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("ref");
      refindex564 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 0});
      slog::Relation* readrel579 = db->getRelation("ref");
      refindex565 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 0});
      slog::Relation* readrel581 = db->getRelation("num");
      numindex566 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 0});
      slog::Relation* readrel583 = db->getRelation("ref");
      refindex567 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("app");
      appindex568 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({1, 0});
      slog::Relation* readrel587 = db->getRelation("ref");
      refindex569 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 0});
      slog::Relation* readrel589 = db->getRelation("ref");
      refindex570 = readrel589->getIndex(ord588, false);
  
    }
    ReadTask571(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_const0457bba0679825d285ef7fa5;
      u64 v_c80 = v_const30f8b180d63559f2512b744f;
      u64 v_c81 = v_const7297d2085ea0adffc396d546;
      u64 v_c82 = v_constef2d127de37b942baad06145;
  
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
        u64 v_c83 = _t[0];
        u64 v_c84 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c86 = _t[3];
        u64 v_c87 = _t[4];
        if (!slog::exists_probe<2,1>(refindex562, std::array<u64,2>{v_c81, 0})) return;
        if (!slog::exists_probe<3,1>(appindex563, std::array<u64,3>{v_c83, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex564, std::array<u64,2>{v_c79, 0})) return;
        if (!slog::exists_probe<2,1>(refindex565, std::array<u64,2>{v_c80, 0})) return;
        slog::join_probe<2,1>(numindex566, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m590) {
          u64 v_c88 = m590[1];
          slog::join_probe<2,1>(refindex567, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m591) {
            u64 v_c89 = m591[1];
            slog::join_probe<3,2>(appindex568, std::array<u64,3>{v_c89, v_c83, 0}, [&](const std::array<u64,3>& m592) {
              u64 v_c90 = m592[2];
              slog::join_probe<2,1>(refindex569, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m593) {
                u64 v_c91 = m593[1];
                slog::join_probe<2,1>(refindex570, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m594) {
                  u64 v_c92 = m594[1];
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c84, v_c85, v_c86, v_c90, v_c87});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c92, v_c85}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c87, v_c90}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp8uWT1001", _fires);
  
      if (!_done)
      {
        ReadTask571* _cont = new ReadTask571(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask571(db,b), false);
  // (crule (pre) (scan eval __t3j1R295 __t9Wlk294 c) (body (join let (0 2 1 3) 1 __t9Wlk294 er x eb)) (head (emit $sup56712x91x0x0x0 (0 1 2 3 4) __t3j1R295 c eb er x)) interp.slog:92 #f)
  class ReadTask596 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex595;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord597({0, 1, 2, 3, 4});
      slog::Relation* readrel598 = db->getRelation("$sup56712x91x0x0x0");
      head_index[0] = readrel598->getIndex(ord597, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord599({0, 2, 1, 3});
      slog::Relation* readrel600 = db->getRelation("let");
      letindex595 = readrel600->getIndex(ord599, false);
  
    }
    ReadTask596(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c93 = _t[0];
        u64 v_c94 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe<4,1>(letindex595, std::array<u64,4>{v_c94, 0, 0, 0}, [&](const std::array<u64,4>& m601) {
          u64 v_c73 = m601[1]; u64 v_c43 = m601[2]; u64 v_c33 = m601[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c93, v_c14, v_c33, v_c73, v_c43}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask596* _cont = new ReadTask596(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask596(db,b), false);
  // (crule (pre) (scan lambda __t3anZ171 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t3anZ171 cb __t8UWw172) (join eval_ans (1 0) 1 __t8UWw172 __t66Yt170) (join eval (0 2 1) 1 __t66Yt170 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join tick_ans (0 1) 1 __t9uJP175 __v0)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask621 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex602;  slog::Index** eval_ansindex603;  slog::Index** evalindex604;  slog::Index** eval_argsindex605;  slog::Index** appindex606;  slog::Index** tickindex607;  slog::Index** $sup56712x41x0x0x0index608;  slog::Index** appindex609;  slog::Index** eval_argsindex610;  slog::Index** eval_args_ansindex611;  slog::Index** appindex612;  slog::Index** tickindex613;  slog::Index** tick_ansindex614;  slog::Index** eval_args_ansindex615;  slog::Index** tick_ansindex616;  slog::Index** closuredelta617;  slog::Index** eval_argsdelta618;  slog::Index** appdelta619;  slog::Index** tickdelta620;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("closure");
      closureindex602 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("closure");
      closuredelta617 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({1, 0});
      slog::Relation* readrel627 = db->getRelation("eval_ans");
      eval_ansindex603 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 2, 1});
      slog::Relation* readrel629 = db->getRelation("eval");
      evalindex604 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({2, 0, 1});
      slog::Relation* readrel631 = db->getRelation("eval_args");
      eval_argsindex605 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("app");
      appindex606 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({2, 0, 1});
      slog::Relation* readrel635 = db->getRelation("tick");
      tickindex607 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 2, 3, 0});
      slog::Relation* readrel637 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index608 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 2, 0});
      slog::Relation* readrel639 = db->getRelation("app");
      appindex609 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("eval_args");
      eval_argsindex610 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("eval_args");
      eval_argsdelta618 = readrel643->getIndex(ord642, true);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("eval_args_ans");
      eval_args_ansindex611 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 2, 0});
      slog::Relation* readrel647 = db->getRelation("app");
      appindex612 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("app");
      appdelta619 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({1, 2, 0});
      slog::Relation* readrel651 = db->getRelation("tick");
      tickindex613 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("tick");
      tickdelta620 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("tick_ans");
      tick_ansindex614 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("eval_args_ans");
      eval_args_ansindex615 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("tick_ans");
      tick_ansindex616 = readrel659->getIndex(ord658, false);
  
    }
    ReadTask621(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c33 = _t[2];
        slog::join_probe_old<3,1>(closureindex602, closuredelta617, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m660) {
          u64 v_c24 = m660[1]; u64 v_c22 = m660[2];
          slog::join_probe<2,1>(eval_ansindex603, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m661) {
            u64 v_c25 = m661[1];
            slog::join_probe<3,1>(evalindex604, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m662) {
              u64 v_c14 = m662[1]; u64 v_c26 = m662[2];
              if (!slog::exists_probe<3,1>(eval_argsindex605, std::array<u64,3>{v_c14, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex606, std::array<u64,3>{v_c26, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex607, std::array<u64,3>{v_c14, 0, 0})) return;
              slog::join_probe<4,2>($sup56712x41x0x0x0index608, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m663) {
                u64 v_c27 = m663[2]; u64 v_c13 = m663[3];
                if (!slog::exists_probe<3,2>(appindex609, std::array<u64,3>{v_c26, v_c27, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex610, eval_argsdelta618, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m664) {
                  u64 v_c28 = m664[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex611, std::array<u64,2>{v_c28, 0})) return;
                  slog::join_probe_old<3,2>(appindex612, appdelta619, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m665) {
                    u64 v_c29 = m665[2];
                    slog::join_probe_old<3,2>(tickindex613, tickdelta620, std::array<u64,3>{v_c29, v_c14, 0}, [&](const std::array<u64,3>& m666) {
                      u64 v_c30 = m666[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex614, std::array<u64,2>{v_c30, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex615, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m667) {
                        u64 v_c31 = m667[1];
                        slog::join_probe<2,1>(tick_ansindex616, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m668) {
                          u64 v_c9 = m668[1];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c33, v_c9}, std::array<u16,3>{1, 2, 0});
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
        ReadTask621* _cont = new ReadTask621(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask621(db,b), false);
  // (crule (pre) (scan eval __t0zOO387 __t2JOw386 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (0 1 2 3) 2 __t0zOO387 c ef es) (join app (0 1 2) 3 __t2JOw386 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t9EYC388) (exists eval_ans (0 1) 1 __t9EYC388) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (exists eval_args_ans (0 1) 1 __t4aOO390) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask688 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex669;  slog::Index** eval_argsindex670;  slog::Index** $sup56712x74x0x0x0index671;  slog::Index** appindex672;  slog::Index** eval_argsindex673;  slog::Index** evalindex674;  slog::Index** eval_ansindex675;  slog::Index** eval_argsindex676;  slog::Index** eval_args_ansindex677;  slog::Index** eval_ansindex678;  slog::Index** eval_args_ansindex679;  slog::Index** deltaindex680;  slog::Index** primindex681;  slog::Index** deltaindex682;  slog::Index** delta_ansindex683;  slog::Index** evaldelta684;  slog::Index** eval_argsdelta685;  slog::Index** primdelta686;  slog::Index** deltadelta687;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord689({0, 1});
      slog::Relation* readrel690 = db->getRelation("eval_ans");
      head_index[0] = readrel690->getIndex(ord689, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord691({2, 0, 1});
      slog::Relation* readrel692 = db->getRelation("eval");
      evalindex669 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({2, 0, 1});
      slog::Relation* readrel694 = db->getRelation("eval_args");
      eval_argsindex670 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1, 2, 3});
      slog::Relation* readrel696 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index671 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1, 2});
      slog::Relation* readrel698 = db->getRelation("app");
      appindex672 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("eval_args");
      eval_argsindex673 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 0});
      slog::Relation* readrel702 = db->getRelation("eval");
      evalindex674 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 0});
      slog::Relation* readrel704 = db->getRelation("eval");
      evaldelta684 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("eval_ans");
      eval_ansindex675 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("eval_args");
      eval_argsindex676 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("eval_args");
      eval_argsdelta685 = readrel710->getIndex(ord709, true);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("eval_args_ans");
      eval_args_ansindex677 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("eval_ans");
      eval_ansindex678 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("eval_args_ans");
      eval_args_ansindex679 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({2, 0, 1});
      slog::Relation* readrel718 = db->getRelation("delta");
      deltaindex680 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("prim");
      primindex681 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({0, 1});
      slog::Relation* readrel722 = db->getRelation("prim");
      primdelta686 = readrel722->getIndex(ord721, true);
      std::vector<u16> ord723({1, 2, 0});
      slog::Relation* readrel724 = db->getRelation("delta");
      deltaindex682 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 2, 0});
      slog::Relation* readrel726 = db->getRelation("delta");
      deltadelta687 = readrel726->getIndex(ord725, true);
      std::vector<u16> ord727({0, 1});
      slog::Relation* readrel728 = db->getRelation("delta_ans");
      delta_ansindex683 = readrel728->getIndex(ord727, false);
  
    }
    ReadTask688(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[0];
        u64 v_c96 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex669, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex670, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index671, std::array<u64,4>{v_c95, v_c14, 0, 0}, [&](const std::array<u64,4>& m729) {
          u64 v_c26 = m729[2]; u64 v_c27 = m729[3];
          slog::join_probe<3,3>(appindex672, std::array<u64,3>{v_c96, v_c26, v_c27}, [&](const std::array<u64,3>& m730) {
            if (!slog::exists_probe<3,2>(eval_argsindex673, std::array<u64,3>{v_c27, v_c14, 0})) return;
            slog::join_probe_old<3,2>(evalindex674, evaldelta684, std::array<u64,3>{v_c26, v_c14, 0}, [&](const std::array<u64,3>& m731) {
              u64 v_c97 = m731[2];
              if (!slog::exists_probe<2,1>(eval_ansindex675, std::array<u64,2>{v_c97, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex676, eval_argsdelta685, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m732) {
                u64 v_c98 = m732[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex677, std::array<u64,2>{v_c98, 0})) return;
                slog::join_probe<2,1>(eval_ansindex678, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m733) {
                  u64 v_c99 = m733[1];
                  slog::join_probe<2,1>(eval_args_ansindex679, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m734) {
                    u64 v_c31 = m734[1];
                    if (!slog::exists_probe<3,1>(deltaindex680, std::array<u64,3>{v_c31, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex681, primdelta686, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m735) {
                      u64 v_c36 = m735[1];
                      slog::join_probe_old<3,2>(deltaindex682, deltadelta687, std::array<u64,3>{v_c36, v_c31, 0}, [&](const std::array<u64,3>& m736) {
                        u64 v_c100 = m736[2];
                        slog::join_probe<2,1>(delta_ansindex683, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m737) {
                          u64 v_c58 = m737[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c95, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask688* _cont = new ReadTask688(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask688(db,b), false);
  // (crule (pre) (scan eval __t0vH556 __t0mtA55 c) (body (join letrec (0 2 1 3) 1 __t0mtA55 er x eb)) (head (emit $sup56712x93x0x0x0 (0 1 2 3 4) __t0vH556 c eb er x)) interp.slog:94 #f)
  class ReadTask739 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex738;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord740({0, 1, 2, 3, 4});
      slog::Relation* readrel741 = db->getRelation("$sup56712x93x0x0x0");
      head_index[0] = readrel741->getIndex(ord740, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord742({0, 2, 1, 3});
      slog::Relation* readrel743 = db->getRelation("letrec");
      letrecindex738 = readrel743->getIndex(ord742, false);
  
    }
    ReadTask739(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<4,1>(letrecindex738, std::array<u64,4>{v_c102, 0, 0, 0}, [&](const std::array<u64,4>& m744) {
          u64 v_c73 = m744[1]; u64 v_c43 = m744[2]; u64 v_c33 = m744[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c101, v_c14, v_c33, v_c73, v_c43}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask739* _cont = new ReadTask739(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask739(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo5qV2470 __t5qKD331 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5RED468 __t5qKD331 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo66CB469 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4yFo471 __t5qKD331 _00024seq2) (exists _enum (1 0) 1 __tconst2WdB587) (join delta (1 2 0) 2 __tconst2sal328 _00024seq2 __t8DFh329) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join symval (0 1) 1 __t5qKD331 s) (letp _00024sql2Y3P463 (aslst _00024seq2)) (let chk7Xno892 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk7Xno892) (letp chk950t893 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (eq __t5qKD331 chk950t893) (letp chk2SiT894 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk2SiT894)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask753 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex745;  slog::Index** $seq_atindex746;  slog::Index** $seq_atrindex747;  slog::Index** _enumindex748;  slog::Index** deltaindex749;  slog::Index** _enumindex750;  slog::Index** symvalindex751;  slog::Index** $seq_atrdelta752;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord754({1, 0, 2});
      slog::Relation* readrel755 = db->getRelation("$seq_atr");
      driver_index = readrel755->getIndex(ord754, true);
      std::vector<u16> ord756({1, 0, 2});
      slog::Relation* readrel757 = db->getRelation("$seq_at");
      $seq_atindex745 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 0, 2});
      slog::Relation* readrel759 = db->getRelation("$seq_at");
      $seq_atindex746 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0, 2});
      slog::Relation* readrel761 = db->getRelation("$seq_atr");
      $seq_atrindex747 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0, 2});
      slog::Relation* readrel763 = db->getRelation("$seq_atr");
      $seq_atrdelta752 = readrel763->getIndex(ord762, true);
      std::vector<u16> ord764({1, 0});
      slog::Relation* readrel765 = db->getRelation("_enum");
      _enumindex748 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 0});
      slog::Relation* readrel767 = db->getRelation("delta");
      deltaindex749 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 0});
      slog::Relation* readrel769 = db->getRelation("_enum");
      _enumindex750 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1});
      slog::Relation* readrel771 = db->getRelation("symval");
      symvalindex751 = readrel771->getIndex(ord770, false);
  
    }
    ReadTask753(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c104 = v_const06abaa100ecef791ce028c56;
      u64 v_c105 = v_constd4735e3a265e16eee03f5971;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c108 = v_const5feceb66ffc86f38d952786c;
      u64 v_c109 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c110, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m772) {
        u64 v_c112 = m772[1];
        u64 v_c113 = m772[2];
        if (buckethash(v_c112) != bucket) return;
        slog::join_probe<3,3>($seq_atindex745, std::array<u64,3>{v_c108, v_c112, v_c113}, [&](const std::array<u64,3>& m773) {
          slog::join_probe<3,3>($seq_atindex746, std::array<u64,3>{v_c109, v_c112, v_c113}, [&](const std::array<u64,3>& m774) {
            slog::join_probe_old<3,3>($seq_atrindex747, $seq_atrdelta752, std::array<u64,3>{v_c111, v_c112, v_c113}, [&](const std::array<u64,3>& m775) {
              if (!slog::exists_probe<2,1>(_enumindex748, std::array<u64,2>{v_c103, 0})) return;
              slog::join_probe<3,2>(deltaindex749, std::array<u64,3>{v_c104, v_c113, 0}, [&](const std::array<u64,3>& m776) {
                u64 v_c114 = m776[2];
                slog::join_probe<2,1>(_enumindex750, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m777) {
                  u64 v_c115 = m777[1];
                  slog::join_probe<2,1>(symvalindex751, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m778) {
                    u64 v_c116 = m778[1];
                    bool ok779 = true;
                    u64 v_c117 = _prim_aslst(db, v_c113, &ok779);
                    if (!ok779) return;
                    u64 v_c118 = _prim_llen(db, v_c117);
                    if (v_c118 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c105 != v_c118) return;
                    bool ok780 = true;
                    u64 v_c119 = _prim_lref(db, v_c117, v_c106, &ok780);
                    if (!ok780) return;
                    if (v_c112 != v_c119) return;
                    bool ok781 = true;
                    u64 v_c120 = _prim_lref(db, v_c117, v_c107, &ok781);
                    if (!ok781) return;
                    if (v_c112 != v_c120) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c114});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c115}, std::array<u16,2>{1, 0});
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
        ReadTask753* _cont = new ReadTask753(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask753(db,b), false);
  // (crule (pre (let _00024sqc6XAv500 const6b86b273ff34fce19d6b804e) (let _00024sqc0vSU501 const5feceb66ffc86f38d952786c) (let _00024sqc8wQe502 const6b86b273ff34fce19d6b804e) (let _00024sqc1CqB503 const5feceb66ffc86f38d952786c) (let _00024sqc6aX2510 const6b86b273ff34fce19d6b804e) (let _00024sqc42tq511 const5feceb66ffc86f38d952786c) (let _00024sqc69Ok512 const6b86b273ff34fce19d6b804e) (let _00024sqc3PpH513 const5feceb66ffc86f38d952786c) (let __trid2mUd657 const99565d312ddf7c579dcfd67c) (let __trel91Vz658 const65c80aac3433a01ef8a7f298) (let __tcol2VoF659 const5feceb66ffc86f38d952786c) (let __trel6Nj3660 const913be61629bf526ec23a58e7) (let __tcol2Tx4661 const5feceb66ffc86f38d952786c) (let __trel2zEW662 const913be61629bf526ec23a58e7) (let __tcol6ILE663 constd4735e3a265e16eee03f5971)) (scan bind_params _00024seq0 _00024seq1 l c) (body (letp _00024sql4ZzE498 (aslst _00024seq1)) (let _00024sqn60yI499 (llen _00024sql4ZzE498)) (cmp ge _00024sqn60yI499 _00024sqc6XAv500) (letp _00024sql3SBC508 (aslst _00024seq0)) (let _00024sqn6fdX509 (llen _00024sql3SBC508)) (cmp ge _00024sqn6fdX509 _00024sqc6aX2510) (letp v (lref _00024sql4ZzE498 _00024sqc0vSU501)) (let _00024sqp7RXp504 (_0002d _00024sqn60yI499 _00024sqc1CqB503)) (let vs (lslice _00024sql4ZzE498 _00024sqc8wQe502 _00024sqp7RXp504)) (letp x (lref _00024sql3SBC508 _00024sqc42tq511)) (let _00024sqp1Xf9514 (_0002d _00024sqn6fdX509 _00024sqc3PpH513)) (let xs (lslice _00024sql3SBC508 _00024sqc69Ok512 _00024sqp1Xf9514))) (head (tycheck x (accept str) __trid2mUd657 __trel91Vz658 __tcol2VoF659 (1 2 3 4 0)) (tycheck x (accept str) __trid2mUd657 __trel6Nj3660 __tcol2Tx4661 (1 2 3 4 0)) (tycheck v (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2mUd657 __trel2zEW662 __tcol6ILE663 (1 2 3 4 0)) (emit bind_params (0 1 2 3) xs vs l c) (emit binding_event (0 1 2) x l c) (emit binding (0 1 2) x l v)) interp.slog:67 #f)
  class ReadTask787 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid784;  u32 sid782;  u32 sid783;  u32 sid785;  u32 sid786;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("bind_params");
      std::vector<u16> ord788({0, 1, 2, 3});
      slog::Relation* readrel789 = db->getRelation("bind_params");
      head_index[3] = readrel789->getIndex(ord788, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord790({0, 1, 2});
      slog::Relation* readrel791 = db->getRelation("binding_event");
      head_index[4] = readrel791->getIndex(ord790, false);
      head_rel[5] = db->getRelation("binding");
      std::vector<u16> ord792({0, 1, 2});
      slog::Relation* readrel793 = db->getRelation("binding");
      head_index[5] = readrel793->getIndex(ord792, false);
      outer_rel = db->getRelation("bind_params");
      sid784 = db->getRelation("_enum")->getStructId();
      sid782 = db->getRelation("boolval")->getStructId();
      sid783 = db->getRelation("closure")->getStructId();
      sid785 = db->getRelation("prim")->getStructId();
      sid786 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask787(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const5feceb66ffc86f38d952786c;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
      u64 v_c129 = v_const99565d312ddf7c579dcfd67c;
      u64 v_c130 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c131 = v_const5feceb66ffc86f38d952786c;
      u64 v_c132 = v_const913be61629bf526ec23a58e7;
      u64 v_c133 = v_const5feceb66ffc86f38d952786c;
      u64 v_c134 = v_const913be61629bf526ec23a58e7;
      u64 v_c135 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c136 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c138 = _t[2];
        u64 v_c14 = _t[3];
        bool ok794 = true;
        u64 v_c139 = _prim_aslst(db, v_c137, &ok794);
        if (!ok794) return;
        u64 v_c140 = _prim_llen(db, v_c139);
        if (v_c140 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c141 = _prim_ge(db, v_c140, v_c121);
        if (v_c141 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        if (!v_c141) return;
        bool ok796 = true;
        u64 v_c142 = _prim_aslst(db, v_c136, &ok796);
        if (!ok796) return;
        u64 v_c143 = _prim_llen(db, v_c142);
        if (v_c143 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c144 = _prim_ge(db, v_c143, v_c125);
        if (v_c144 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        if (!v_c144) return;
        bool ok798 = true;
        u64 v_c58 = _prim_lref(db, v_c139, v_c122, &ok798);
        if (!ok798) return;
        u64 v_c145 = _prim__0002d(db, v_c140, v_c124);
        if (v_c145 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c31 = _prim_lslice(db, v_c139, v_c123, v_c145);
        if (v_c31 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        bool ok799 = true;
        u64 v_c43 = _prim_lref(db, v_c142, v_c126, &ok799);
        if (!ok799) return;
        u64 v_c146 = _prim__0002d(db, v_c143, v_c128);
        if (v_c146 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c32 = _prim_lslice(db, v_c142, v_c127, v_c146);
        if (v_c32 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        ++_fires;
        if (!(is_str(v_c43)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c129, v_c130, v_c131, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c43)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c129, v_c132, v_c133, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c58) && (decode_struct_id(v_c58) == sid782 || decode_struct_id(v_c58) == sid783 || decode_struct_id(v_c58) == sid784 || decode_struct_id(v_c58) == sid785 || decode_struct_id(v_c58) == sid786))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c129, v_c134, v_c135, v_c58}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit<4>(head_rel[3], head_index[3], newbatch[3], std::array<u64,4>{v_c32, v_c31, v_c138, v_c14}, std::array<u16,4>{0, 1, 2, 3});
        slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c43, v_c138, v_c14}, std::array<u16,3>{0, 1, 2});
        slog::emit<3>(head_rel[5], head_index[5], newbatch[5], std::array<u64,3>{v_c43, v_c138, v_c58}, std::array<u16,3>{0, 1, 2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("interp.slog:67", "delta:bind_params", _fires);
  
      if (!_done)
      {
        ReadTask787* _cont = new ReadTask787(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask787(db,b), false);
  // (crule (pre (let __tconst62Eu697 constb9e118781cea1f9fa01462e0)) (seeded) (body (join _enum (1 0) 1 __tconst62Eu697 __t7z6n355) (join boolval (1 0) 1 __t7z6n355 __t9OVd356)) (head (emit scheme_false (0) __t9OVd356)) interp.slog:81 #f)
  class ReadTask802 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex800;  slog::Index** boolvalindex801;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord803({0});
      slog::Relation* readrel804 = db->getRelation("scheme_false");
      head_index[0] = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 0});
      slog::Relation* readrel806 = db->getRelation("_enum");
      _enumindex800 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 0});
      slog::Relation* readrel808 = db->getRelation("boolval");
      boolvalindex801 = readrel808->getIndex(ord807, false);
  
    }
    ReadTask802(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex800, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m809) {
        u64 v_c148 = m809[1];
        slog::join_probe<2,1>(boolvalindex801, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m810) {
          u64 v_c149 = m810[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c149}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask802(db,b));
  // (crule (pre) (scan ref __t8l5731 x) (body (exists lookup (1 2 0) 1 x) (join-old eval (1 2 0) 1 (1 2 0) __t8l5731 c __t8n0332) (join-old lookup (1 2 0) 2 (1 2 0) x c __t0d3433) (join lookup_ans (0 1) 1 __t0d3433 __v0)) (head (emit eval_ans (0 1) __t8n0332 __v0)) interp.slog:30 #f)
  class ReadTask817 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex811;  slog::Index** evalindex812;  slog::Index** lookupindex813;  slog::Index** lookup_ansindex814;  slog::Index** evaldelta815;  slog::Index** lookupdelta816;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord818({0, 1});
      slog::Relation* readrel819 = db->getRelation("eval_ans");
      head_index[0] = readrel819->getIndex(ord818, false);
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("lookup");
      lookupindex811 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("eval");
      evalindex812 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 2, 0});
      slog::Relation* readrel825 = db->getRelation("eval");
      evaldelta815 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("lookup");
      lookupindex813 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("lookup");
      lookupdelta816 = readrel829->getIndex(ord828, true);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("lookup_ans");
      lookup_ansindex814 = readrel831->getIndex(ord830, false);
  
    }
    ReadTask817(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c150 = _t[0];
        u64 v_c43 = _t[1];
        if (!slog::exists_probe<3,1>(lookupindex811, std::array<u64,3>{v_c43, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex812, evaldelta815, std::array<u64,3>{v_c150, 0, 0}, [&](const std::array<u64,3>& m832) {
          u64 v_c14 = m832[1]; u64 v_c151 = m832[2];
          slog::join_probe_old<3,2>(lookupindex813, lookupdelta816, std::array<u64,3>{v_c43, v_c14, 0}, [&](const std::array<u64,3>& m833) {
            u64 v_c152 = m833[2];
            slog::join_probe<2,1>(lookup_ansindex814, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m834) {
              u64 v_c9 = m834[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c151, v_c9}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:ref", _fires);
  
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
  // (crule (pre (let _00024sqc5lNj455 const6b86b273ff34fce19d6b804e) (let _00024sqc2roT456 const5feceb66ffc86f38d952786c) (let _00024sqc6IBH457 const6b86b273ff34fce19d6b804e) (let _00024sqc9QSx458 const5feceb66ffc86f38d952786c)) (scan eval_args __t4EsZ134 _00024seq0 c) (body (letp _00024sql5glG453 (aslst _00024seq0)) (let _00024sqn5AI6454 (llen _00024sql5glG453)) (cmp ge _00024sqn5AI6454 _00024sqc5lNj455) (letp e (lref _00024sql5glG453 _00024sqc2roT456)) (let _00024sqp7eTI459 (_0002d _00024sqn5AI6454 _00024sqc9QSx458)) (let es (lslice _00024sql5glG453 _00024sqc6IBH457 _00024sqp7eTI459))) (head (emit $sup56712x37x0x0x0 (2 3 0 1 4) c e _00024seq0 __t4EsZ134 es)) interp.slog:38 #f)
  class ReadTask835 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup56712x37x0x0x0");
      std::vector<u16> ord836({2, 3, 0, 1, 4});
      slog::Relation* readrel837 = db->getRelation("$sup56712x37x0x0x0");
      head_index[0] = readrel837->getIndex(ord836, false);
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask835(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c153 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c154 = v_const5feceb66ffc86f38d952786c;
      u64 v_c155 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c156 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c157 = _t[0];
        u64 v_c136 = _t[1];
        u64 v_c14 = _t[2];
        bool ok838 = true;
        u64 v_c158 = _prim_aslst(db, v_c136, &ok838);
        if (!ok838) return;
        u64 v_c159 = _prim_llen(db, v_c158);
        if (v_c159 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c160 = _prim_ge(db, v_c159, v_c153);
        if (v_c160 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c160) return;
        bool ok840 = true;
        u64 v_c161 = _prim_lref(db, v_c158, v_c154, &ok840);
        if (!ok840) return;
        u64 v_c162 = _prim__0002d(db, v_c159, v_c156);
        if (v_c162 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c27 = _prim_lslice(db, v_c158, v_c155, v_c162);
        if (v_c27 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c14, v_c161, v_c136, v_c157, v_c27}, std::array<u16,5>{2, 3, 0, 1, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask835* _cont = new ReadTask835(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask835(db,b), false);
  // (crule (pre) (scan delta_ans __t3FWR391 v) (body (join-old delta (0 1 2) 1 (0 1 2) __t3FWR391 op vs) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t4aOO390) (join-old prim (1 0) 1 (1 0) op __t22Li389) (join eval_ans (1 0) 1 __t22Li389 __t9EYC388) (join-old eval (0 2 1) 1 (0 2 1) __t9EYC388 c ef) (exists $sup56712x74x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join-old eval_args (0 2 1) 2 (0 2 1) __t4aOO390 c es) (exists app (1 2 0) 2 ef es) (join-old $sup56712x74x0x0x0 (1 2 3 0) 3 (1 2 3 0) c ef es __t0zOO387) (exists eval (0 2 1) 2 __t0zOO387 c) (join-old app (1 2 0) 2 (1 2 0) ef es __t2JOw386) (join-old eval (0 2 1) 3 (0 2 1) __t0zOO387 c __t2JOw386)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask863 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex841;  slog::Index** primindex842;  slog::Index** eval_args_ansindex843;  slog::Index** primindex844;  slog::Index** eval_ansindex845;  slog::Index** evalindex846;  slog::Index** $sup56712x74x0x0x0index847;  slog::Index** appindex848;  slog::Index** evalindex849;  slog::Index** eval_argsindex850;  slog::Index** appindex851;  slog::Index** $sup56712x74x0x0x0index852;  slog::Index** evalindex853;  slog::Index** appindex854;  slog::Index** evalindex855;  slog::Index** deltadelta856;  slog::Index** primdelta857;  slog::Index** evaldelta858;  slog::Index** eval_argsdelta859;  slog::Index** $sup56712x74x0x0x0delta860;  slog::Index** appdelta861;  slog::Index** evaldelta862;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord864({0, 1});
      slog::Relation* readrel865 = db->getRelation("eval_ans");
      head_index[0] = readrel865->getIndex(ord864, false);
      outer_rel = db->getRelation("delta_ans");
      std::vector<u16> ord866({0, 1, 2});
      slog::Relation* readrel867 = db->getRelation("delta");
      deltaindex841 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1, 2});
      slog::Relation* readrel869 = db->getRelation("delta");
      deltadelta856 = readrel869->getIndex(ord868, true);
      std::vector<u16> ord870({1, 0});
      slog::Relation* readrel871 = db->getRelation("prim");
      primindex842 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({1, 0});
      slog::Relation* readrel873 = db->getRelation("eval_args_ans");
      eval_args_ansindex843 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({1, 0});
      slog::Relation* readrel875 = db->getRelation("prim");
      primindex844 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 0});
      slog::Relation* readrel877 = db->getRelation("prim");
      primdelta857 = readrel877->getIndex(ord876, true);
      std::vector<u16> ord878({1, 0});
      slog::Relation* readrel879 = db->getRelation("eval_ans");
      eval_ansindex845 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({0, 2, 1});
      slog::Relation* readrel881 = db->getRelation("eval");
      evalindex846 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({0, 2, 1});
      slog::Relation* readrel883 = db->getRelation("eval");
      evaldelta858 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({1, 2, 3, 0});
      slog::Relation* readrel885 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index847 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 2, 0});
      slog::Relation* readrel887 = db->getRelation("app");
      appindex848 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({2, 0, 1});
      slog::Relation* readrel889 = db->getRelation("eval");
      evalindex849 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({0, 2, 1});
      slog::Relation* readrel891 = db->getRelation("eval_args");
      eval_argsindex850 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({0, 2, 1});
      slog::Relation* readrel893 = db->getRelation("eval_args");
      eval_argsdelta859 = readrel893->getIndex(ord892, true);
      std::vector<u16> ord894({1, 2, 0});
      slog::Relation* readrel895 = db->getRelation("app");
      appindex851 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({1, 2, 3, 0});
      slog::Relation* readrel897 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index852 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 2, 3, 0});
      slog::Relation* readrel899 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta860 = readrel899->getIndex(ord898, true);
      std::vector<u16> ord900({0, 2, 1});
      slog::Relation* readrel901 = db->getRelation("eval");
      evalindex853 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("app");
      appindex854 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({1, 2, 0});
      slog::Relation* readrel905 = db->getRelation("app");
      appdelta861 = readrel905->getIndex(ord904, true);
      std::vector<u16> ord906({0, 2, 1});
      slog::Relation* readrel907 = db->getRelation("eval");
      evalindex855 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({0, 2, 1});
      slog::Relation* readrel909 = db->getRelation("eval");
      evaldelta862 = readrel909->getIndex(ord908, true);
  
    }
    ReadTask863(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c100 = _t[0];
        u64 v_c58 = _t[1];
        slog::join_probe_old<3,1>(deltaindex841, deltadelta856, std::array<u64,3>{v_c100, 0, 0}, [&](const std::array<u64,3>& m910) {
          u64 v_c36 = m910[1]; u64 v_c31 = m910[2];
          if (!slog::exists_probe<2,1>(primindex842, std::array<u64,2>{v_c36, 0})) return;
          slog::join_probe<2,1>(eval_args_ansindex843, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m911) {
            u64 v_c98 = m911[1];
            slog::join_probe_old<2,1>(primindex844, primdelta857, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m912) {
              u64 v_c99 = m912[1];
              slog::join_probe<2,1>(eval_ansindex845, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m913) {
                u64 v_c97 = m913[1];
                slog::join_probe_old<3,1>(evalindex846, evaldelta858, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m914) {
                  u64 v_c14 = m914[1]; u64 v_c26 = m914[2];
                  if (!slog::exists_probe<4,2>($sup56712x74x0x0x0index847, std::array<u64,4>{v_c14, v_c26, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex848, std::array<u64,3>{v_c26, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex849, std::array<u64,3>{v_c14, 0, 0})) return;
                  slog::join_probe_old<3,2>(eval_argsindex850, eval_argsdelta859, std::array<u64,3>{v_c98, v_c14, 0}, [&](const std::array<u64,3>& m915) {
                    u64 v_c27 = m915[2];
                    if (!slog::exists_probe<3,2>(appindex851, std::array<u64,3>{v_c26, v_c27, 0})) return;
                    slog::join_probe_old<4,3>($sup56712x74x0x0x0index852, $sup56712x74x0x0x0delta860, std::array<u64,4>{v_c14, v_c26, v_c27, 0}, [&](const std::array<u64,4>& m916) {
                      u64 v_c95 = m916[3];
                      if (!slog::exists_probe<3,2>(evalindex853, std::array<u64,3>{v_c95, v_c14, 0})) return;
                      slog::join_probe_old<3,2>(appindex854, appdelta861, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m917) {
                        u64 v_c96 = m917[2];
                        slog::join_probe_old<3,3>(evalindex855, evaldelta862, std::array<u64,3>{v_c95, v_c14, v_c96}, [&](const std::array<u64,3>& m918) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c95, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:delta_ans", _fires);
  
      if (!_done)
      {
        ReadTask863* _cont = new ReadTask863(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask863(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo7QcU434 e _00024seq0) (body (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let es (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (exists eval_args (1 2 0) 1 _00024seq0) (exists eval (1 2 0) 1 e) (exists eval_args (1 2 0) 1 es) (join $sup56712x37x0x0x0 (0 3 4 2 1) 3 _00024seq0 e es c __t1ye1379) (join eval_args (0 2 1) 3 __t1ye1379 c _00024seq0) (exists eval_args (1 2 0) 2 es c) (join eval (1 2 0) 2 e c __t33Oa380) (exists eval_ans (0 1) 1 __t33Oa380) (join eval_args (1 2 0) 2 es c __t5lLk381) (exists eval_args_ans (0 1) 1 __t5lLk381) (join eval_ans (0 1) 1 __t33Oa380 __v0) (join eval_args_ans (0 1) 1 __t5lLk381 __v1) (letp chk86IS944 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk86IS944)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask931 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** eval_argsindex919;  slog::Index** evalindex920;  slog::Index** eval_argsindex921;  slog::Index** $sup56712x37x0x0x0index922;  slog::Index** eval_argsindex923;  slog::Index** eval_argsindex924;  slog::Index** evalindex925;  slog::Index** eval_ansindex926;  slog::Index** eval_argsindex927;  slog::Index** eval_args_ansindex928;  slog::Index** eval_ansindex929;  slog::Index** eval_args_ansindex930;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      std::vector<u16> ord932({1, 0, 2});
      slog::Relation* readrel933 = db->getRelation("$seq_at");
      driver_index = readrel933->getIndex(ord932, true);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("eval_args");
      eval_argsindex919 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("eval");
      evalindex920 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 0});
      slog::Relation* readrel939 = db->getRelation("eval_args");
      eval_argsindex921 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({0, 3, 4, 2, 1});
      slog::Relation* readrel941 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index922 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({0, 2, 1});
      slog::Relation* readrel943 = db->getRelation("eval_args");
      eval_argsindex923 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 2, 0});
      slog::Relation* readrel945 = db->getRelation("eval_args");
      eval_argsindex924 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 2, 0});
      slog::Relation* readrel947 = db->getRelation("eval");
      evalindex925 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("eval_ans");
      eval_ansindex926 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 2, 0});
      slog::Relation* readrel951 = db->getRelation("eval_args");
      eval_argsindex927 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({0, 1});
      slog::Relation* readrel953 = db->getRelation("eval_args_ans");
      eval_args_ansindex928 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("eval_ans");
      eval_ansindex929 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({0, 1});
      slog::Relation* readrel957 = db->getRelation("eval_args_ans");
      eval_args_ansindex930 = readrel957->getIndex(ord956, false);
  
    }
    ReadTask931(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
      u64 v_c165 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c166 = v_const5feceb66ffc86f38d952786c;
      u64 v_c167 = v_const5feceb66ffc86f38d952786c;
      u64 v_c168 = _prim_lempty(db);
      if (v_c168 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c167, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m958) {
        u64 v_c161 = m958[1];
        u64 v_c136 = m958[2];
        if (buckethash(v_c161) != bucket) return;
        bool ok959 = true;
        u64 v_c169 = _prim_aslst(db, v_c136, &ok959);
        if (!ok959) return;
        u64 v_c170 = _prim_llen(db, v_c169);
        if (v_c170 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c171 = _prim_ge(db, v_c170, v_c163);
        if (v_c171 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c171) return;
        u64 v_c172 = _prim__0002d(db, v_c170, v_c166);
        if (v_c172 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c27 = _prim_lslice(db, v_c169, v_c165, v_c172);
        if (v_c27 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!slog::exists_probe<3,1>(eval_argsindex919, std::array<u64,3>{v_c136, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex920, std::array<u64,3>{v_c161, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex921, std::array<u64,3>{v_c27, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x37x0x0x0index922, std::array<u64,5>{v_c136, v_c161, v_c27, 0, 0}, [&](const std::array<u64,5>& m961) {
          u64 v_c14 = m961[3]; u64 v_c173 = m961[4];
          slog::join_probe<3,3>(eval_argsindex923, std::array<u64,3>{v_c173, v_c14, v_c136}, [&](const std::array<u64,3>& m962) {
            if (!slog::exists_probe<3,2>(eval_argsindex924, std::array<u64,3>{v_c27, v_c14, 0})) return;
            slog::join_probe<3,2>(evalindex925, std::array<u64,3>{v_c161, v_c14, 0}, [&](const std::array<u64,3>& m963) {
              u64 v_c174 = m963[2];
              if (!slog::exists_probe<2,1>(eval_ansindex926, std::array<u64,2>{v_c174, 0})) return;
              slog::join_probe<3,2>(eval_argsindex927, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m964) {
                u64 v_c175 = m964[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex928, std::array<u64,2>{v_c175, 0})) return;
                slog::join_probe<2,1>(eval_ansindex929, std::array<u64,2>{v_c174, 0}, [&](const std::array<u64,2>& m965) {
                  u64 v_c9 = m965[1];
                  slog::join_probe<2,1>(eval_args_ansindex930, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m966) {
                    u64 v_c16 = m966[1];
                    bool ok967 = true;
                    u64 v_c176 = _prim_lref(db, v_c169, v_c164, &ok967);
                    if (!ok967) return;
                    if (v_c161 != v_c176) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c173, v_c168, v_c9, v_c16});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask931* _cont = new ReadTask931(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask931(db,b), false);
  // (crule (pre) (scan freevar y __t0Osl187) (body (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0Osl187 xs eb) (join eval (0 2 1) 0 __2wtW609 c __t5Orx186) (join-old app (0 1 2) 1 (0 1 2) __t5Orx186 ef es)) (head (mkstruct tick (1 2 0) __4U5c610 __t5Orx186 c)) interp.slog:56 #f)
  class ReadTask975 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex968;  slog::Index** lambdaindex969;  slog::Index** evalindex970;  slog::Index** appindex971;  slog::Index** bindingdelta972;  slog::Index** lambdadelta973;  slog::Index** appdelta974;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord976({0, 1, 2});
      slog::Relation* readrel977 = db->getRelation("binding");
      bindingindex968 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({0, 1, 2});
      slog::Relation* readrel979 = db->getRelation("binding");
      bindingdelta972 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({0, 1, 2});
      slog::Relation* readrel981 = db->getRelation("lambda");
      lambdaindex969 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({0, 1, 2});
      slog::Relation* readrel983 = db->getRelation("lambda");
      lambdadelta973 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({0, 2, 1});
      slog::Relation* readrel985 = db->getRelation("eval");
      evalindex970 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({0, 1, 2});
      slog::Relation* readrel987 = db->getRelation("app");
      appindex971 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1, 2});
      slog::Relation* readrel989 = db->getRelation("app");
      appdelta974 = readrel989->getIndex(ord988, true);
  
    }
    ReadTask975(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c177 = _t[0];
        u64 v_c178 = _t[1];
        slog::join_probe_old<3,1>(bindingindex968, bindingdelta972, std::array<u64,3>{v_c177, 0, 0}, [&](const std::array<u64,3>& m990) {
          u64 v_c24 = m990[1]; u64 v_c179 = m990[2];
          slog::join_probe_old<3,1>(lambdaindex969, lambdadelta973, std::array<u64,3>{v_c178, 0, 0}, [&](const std::array<u64,3>& m991) {
            u64 v_c32 = m991[1]; u64 v_c33 = m991[2];
            slog::join_all<3>(evalindex970, [&](const std::array<u64,3>& m992) {
              u64 v_c180 = m992[0]; u64 v_c14 = m992[1]; u64 v_c181 = m992[2];
              slog::join_probe_old<3,1>(appindex971, appdelta974, std::array<u64,3>{v_c181, 0, 0}, [&](const std::array<u64,3>& m993) {
                u64 v_c26 = m993[1]; u64 v_c27 = m993[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c181, v_c14}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask975* _cont = new ReadTask975(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask975(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre2IEv841 __errf1MvX842 __errf2wPj843) (body) (head (emit error (0) __erre2IEv841)) <internal>:1 #f)
  class ReadTask994 : public slog::Task
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
      std::vector<u16> ord995({0});
      slog::Relation* readrel996 = db->getRelation("error");
      head_index[0] = readrel996->getIndex(ord995, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask994(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c183 = _t[1];
        u64 v_c184 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c182}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask994* _cont = new ReadTask994(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask994(db,b), false);
  // (crule (pre (let _00024sqc67YX483 const6b86b273ff34fce19d6b804e) (let _00024sqc6yXy484 const5feceb66ffc86f38d952786c) (let _00024sqc5zPS485 const6b86b273ff34fce19d6b804e) (let _00024sqc5ri6486 const5feceb66ffc86f38d952786c) (let _00024sqo8WWm491 const5feceb66ffc86f38d952786c) (let __t8LOa148 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo8WWm491 e _00024seq0) (body (join argument_list (0) 1 _00024seq0) (join freevar (1 0) 1 e x) (letp _00024sql8fmo481 (aslst _00024seq0)) (let _00024sqn5D5C482 (llen _00024sql8fmo481)) (cmp ge _00024sqn5D5C482 _00024sqc67YX483) (letp chk0ndQ867 (lref _00024sql8fmo481 _00024sqc6yXy484)) (eq e chk0ndQ867) (let _00024sqp6Eh2487 (_0002d _00024sqn5D5C482 _00024sqc5ri6486)) (let es (lslice _00024sql8fmo481 _00024sqc5zPS485 _00024sqp6Eh2487))) (head (emit-temp temp86Ay863 __t8LOa148 e es x)) freevars.slog:35 #f)
  class ReadTask999 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** argument_listindex997;  slog::Index** freevarindex998;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp86Ay863");
      std::vector<u16> ord1000({1, 0, 2});
      slog::Relation* readrel1001 = db->getRelation("$seq_at");
      driver_index = readrel1001->getIndex(ord1000, true);
      std::vector<u16> ord1002({0});
      slog::Relation* readrel1003 = db->getRelation("argument_list");
      argument_listindex997 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({1, 0});
      slog::Relation* readrel1005 = db->getRelation("freevar");
      freevarindex998 = readrel1005->getIndex(ord1004, false);
  
    }
    ReadTask999(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_const5feceb66ffc86f38d952786c;
      u64 v_c187 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c188 = v_const5feceb66ffc86f38d952786c;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = _prim_lempty(db);
      if (v_c190 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c189, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1006) {
        u64 v_c161 = m1006[1];
        u64 v_c136 = m1006[2];
        if (buckethash(v_c161) != bucket) return;
        slog::join_probe<1,1>(argument_listindex997, std::array<u64,1>{v_c136}, [&](const std::array<u64,1>& m1007) {
          slog::join_probe<2,1>(freevarindex998, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m1008) {
            u64 v_c43 = m1008[1];
            bool ok1009 = true;
            u64 v_c191 = _prim_aslst(db, v_c136, &ok1009);
            if (!ok1009) return;
            u64 v_c192 = _prim_llen(db, v_c191);
            if (v_c192 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c193 = _prim_ge(db, v_c192, v_c185);
            if (v_c193 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c193) return;
            bool ok1011 = true;
            u64 v_c194 = _prim_lref(db, v_c191, v_c186, &ok1011);
            if (!ok1011) return;
            if (v_c161 != v_c194) return;
            u64 v_c195 = _prim__0002d(db, v_c192, v_c188);
            if (v_c195 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c27 = _prim_lslice(db, v_c191, v_c187, v_c195);
            if (v_c27 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c190, v_c161, v_c27, v_c43});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask999* _cont = new ReadTask999(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask999(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo7GLE452 __t4Puk145 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aST449 __t4Puk145 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo1C1f450 __t4Puk145 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo1Q0D451 __t4Puk145 _00024seq2) (join delta (1 2 0) 2 __tconst9XQ5142 _00024seq2 __t9sdv143) (join closure (0 1 2) 1 __t4Puk145 lm cb) (join any_bool (0) 0 b) (letp _00024sql8vYG444 (aslst _00024seq2)) (let chk7ZbM927 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk7ZbM927) (letp chk3eDh928 (lref _00024sql8vYG444 _00024sqc5yoB447)) (eq __t4Puk145 chk3eDh928) (letp chk3B3z929 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk3B3z929)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask1018 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1012;  slog::Index** $seq_atindex1013;  slog::Index** $seq_atrindex1014;  slog::Index** deltaindex1015;  slog::Index** closureindex1016;  slog::Index** any_boolindex1017;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1019({1, 0, 2});
      slog::Relation* readrel1020 = db->getRelation("$seq_atr");
      driver_index = readrel1020->getIndex(ord1019, true);
      std::vector<u16> ord1021({1, 0, 2});
      slog::Relation* readrel1022 = db->getRelation("$seq_at");
      $seq_atindex1012 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 0, 2});
      slog::Relation* readrel1024 = db->getRelation("$seq_at");
      $seq_atindex1013 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 0, 2});
      slog::Relation* readrel1026 = db->getRelation("$seq_atr");
      $seq_atrindex1014 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("delta");
      deltaindex1015 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({0, 1, 2});
      slog::Relation* readrel1030 = db->getRelation("closure");
      closureindex1016 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({0});
      slog::Relation* readrel1032 = db->getRelation("any_bool");
      any_boolindex1017 = readrel1032->getIndex(ord1031, false);
  
    }
    ReadTask1018(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_const06abaa100ecef791ce028c56;
      u64 v_c197 = v_constd4735e3a265e16eee03f5971;
      u64 v_c198 = v_const5feceb66ffc86f38d952786c;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
      u64 v_c201 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c202 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c203 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c203, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1033) {
        u64 v_c204 = m1033[1];
        u64 v_c113 = m1033[2];
        if (buckethash(v_c204) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1012, std::array<u64,3>{v_c200, v_c204, v_c113}, [&](const std::array<u64,3>& m1034) {
          slog::join_probe<3,3>($seq_atindex1013, std::array<u64,3>{v_c201, v_c204, v_c113}, [&](const std::array<u64,3>& m1035) {
            slog::join_probe<3,3>($seq_atrindex1014, std::array<u64,3>{v_c202, v_c204, v_c113}, [&](const std::array<u64,3>& m1036) {
              slog::join_probe<3,2>(deltaindex1015, std::array<u64,3>{v_c196, v_c113, 0}, [&](const std::array<u64,3>& m1037) {
                u64 v_c205 = m1037[2];
                slog::join_probe<3,1>(closureindex1016, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m1038) {
                  u64 v_c206 = m1038[1]; u64 v_c24 = m1038[2];
                  slog::join_all<1>(any_boolindex1017, [&](const std::array<u64,1>& m1039) {
                    u64 v_c207 = m1039[0];
                    bool ok1040 = true;
                    u64 v_c208 = _prim_aslst(db, v_c113, &ok1040);
                    if (!ok1040) return;
                    u64 v_c209 = _prim_llen(db, v_c208);
                    if (v_c209 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c197 != v_c209) return;
                    bool ok1041 = true;
                    u64 v_c210 = _prim_lref(db, v_c208, v_c198, &ok1041);
                    if (!ok1041) return;
                    if (v_c204 != v_c210) return;
                    bool ok1042 = true;
                    u64 v_c211 = _prim_lref(db, v_c208, v_c199, &ok1042);
                    if (!ok1042) return;
                    if (v_c204 != v_c211) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c205, v_c207});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c207}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1018* _cont = new ReadTask1018(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1018(db,b), false);
  // (crule (pre) (scan lambda __t7ycN321 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t7ycN321 cb __t2qAJ322) (join eval_ans (1 0) 1 __t2qAJ322 __t550i320) (join eval (0 2 1) 1 __t550i320 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join tick_ans (0 1) 1 __t3nAR325 l)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1062 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1043;  slog::Index** eval_ansindex1044;  slog::Index** evalindex1045;  slog::Index** appindex1046;  slog::Index** eval_argsindex1047;  slog::Index** tickindex1048;  slog::Index** evalindex1049;  slog::Index** tickindex1050;  slog::Index** appindex1051;  slog::Index** eval_argsindex1052;  slog::Index** eval_args_ansindex1053;  slog::Index** tickindex1054;  slog::Index** tick_ansindex1055;  slog::Index** eval_args_ansindex1056;  slog::Index** tick_ansindex1057;  slog::Index** closuredelta1058;  slog::Index** appdelta1059;  slog::Index** eval_argsdelta1060;  slog::Index** tickdelta1061;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1063({0, 1, 2, 3});
      slog::Relation* readrel1064 = db->getRelation("bind_params");
      head_index[0] = readrel1064->getIndex(ord1063, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1065({0, 1});
      slog::Relation* readrel1066 = db->getRelation("call_event");
      head_index[1] = readrel1066->getIndex(ord1065, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1067({1, 2, 0});
      slog::Relation* readrel1068 = db->getRelation("closure");
      closureindex1043 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 2, 0});
      slog::Relation* readrel1070 = db->getRelation("closure");
      closuredelta1058 = readrel1070->getIndex(ord1069, true);
      std::vector<u16> ord1071({1, 0});
      slog::Relation* readrel1072 = db->getRelation("eval_ans");
      eval_ansindex1044 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({0, 2, 1});
      slog::Relation* readrel1074 = db->getRelation("eval");
      evalindex1045 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({1, 2, 0});
      slog::Relation* readrel1076 = db->getRelation("app");
      appindex1046 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({2, 0, 1});
      slog::Relation* readrel1078 = db->getRelation("eval_args");
      eval_argsindex1047 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({2, 0, 1});
      slog::Relation* readrel1080 = db->getRelation("tick");
      tickindex1048 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({2, 0, 1});
      slog::Relation* readrel1082 = db->getRelation("eval");
      evalindex1049 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({1, 2, 0});
      slog::Relation* readrel1084 = db->getRelation("tick");
      tickindex1050 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({0, 1, 2});
      slog::Relation* readrel1086 = db->getRelation("app");
      appindex1051 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({0, 1, 2});
      slog::Relation* readrel1088 = db->getRelation("app");
      appdelta1059 = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({1, 2, 0});
      slog::Relation* readrel1090 = db->getRelation("eval_args");
      eval_argsindex1052 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 2, 0});
      slog::Relation* readrel1092 = db->getRelation("eval_args");
      eval_argsdelta1060 = readrel1092->getIndex(ord1091, true);
      std::vector<u16> ord1093({0, 1});
      slog::Relation* readrel1094 = db->getRelation("eval_args_ans");
      eval_args_ansindex1053 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("tick");
      tickindex1054 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({1, 2, 0});
      slog::Relation* readrel1098 = db->getRelation("tick");
      tickdelta1061 = readrel1098->getIndex(ord1097, true);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("tick_ans");
      tick_ansindex1055 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("eval_args_ans");
      eval_args_ansindex1056 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({0, 1});
      slog::Relation* readrel1104 = db->getRelation("tick_ans");
      tick_ansindex1057 = readrel1104->getIndex(ord1103, false);
  
    }
    ReadTask1062(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c212 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c33 = _t[2];
        slog::join_probe_old<3,1>(closureindex1043, closuredelta1058, std::array<u64,3>{v_c212, 0, 0}, [&](const std::array<u64,3>& m1105) {
          u64 v_c24 = m1105[1]; u64 v_c213 = m1105[2];
          slog::join_probe<2,1>(eval_ansindex1044, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m1106) {
            u64 v_c214 = m1106[1];
            slog::join_probe<3,1>(evalindex1045, std::array<u64,3>{v_c214, 0, 0}, [&](const std::array<u64,3>& m1107) {
              u64 v_c14 = m1107[1]; u64 v_c26 = m1107[2];
              if (!slog::exists_probe<3,1>(appindex1046, std::array<u64,3>{v_c26, 0, 0})) return;
              if (!slog::exists_probe<3,1>(eval_argsindex1047, std::array<u64,3>{v_c14, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex1048, std::array<u64,3>{v_c14, 0, 0})) return;
              slog::join_probe<3,1>(evalindex1049, std::array<u64,3>{v_c14, 0, 0}, [&](const std::array<u64,3>& m1108) {
                u64 v_c215 = m1108[1]; u64 v_c216 = m1108[2];
                if (!slog::exists_probe<3,2>(tickindex1050, std::array<u64,3>{v_c216, v_c14, 0})) return;
                slog::join_probe_old<3,2>(appindex1051, appdelta1059, std::array<u64,3>{v_c216, v_c26, 0}, [&](const std::array<u64,3>& m1109) {
                  u64 v_c27 = m1109[2];
                  slog::join_probe_old<3,2>(eval_argsindex1052, eval_argsdelta1060, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m1110) {
                    u64 v_c217 = m1110[2];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex1053, std::array<u64,2>{v_c217, 0})) return;
                    slog::join_probe_old<3,2>(tickindex1054, tickdelta1061, std::array<u64,3>{v_c216, v_c14, 0}, [&](const std::array<u64,3>& m1111) {
                      u64 v_c218 = m1111[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex1055, std::array<u64,2>{v_c218, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex1056, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1112) {
                        u64 v_c31 = m1112[1];
                        slog::join_probe<2,1>(tick_ansindex1057, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1113) {
                          u64 v_c138 = m1113[1];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c32, v_c31, v_c138, v_c14}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c138, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1062* _cont = new ReadTask1062(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1062(db,b), false);
  // (crule (pre) (scan $sup56712x74x0x0x0 __t0zOO387 c ef es) (body (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval (1 2 0) 2 ef c) (exists eval_args (1 2 0) 2 es c) (join-old app (1 2 0) 2 (1 2 0) ef es __t2JOw386) (join-old eval (0 2 1) 3 (0 2 1) __t0zOO387 c __t2JOw386) (join-old eval (1 2 0) 2 (1 2 0) ef c __t9EYC388) (exists eval_ans (0 1) 1 __t9EYC388) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (exists eval_args_ans (0 1) 1 __t4aOO390) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask1135 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1114;  slog::Index** evalindex1115;  slog::Index** eval_argsindex1116;  slog::Index** appindex1117;  slog::Index** evalindex1118;  slog::Index** evalindex1119;  slog::Index** eval_ansindex1120;  slog::Index** eval_argsindex1121;  slog::Index** eval_args_ansindex1122;  slog::Index** eval_ansindex1123;  slog::Index** eval_args_ansindex1124;  slog::Index** deltaindex1125;  slog::Index** primindex1126;  slog::Index** deltaindex1127;  slog::Index** delta_ansindex1128;  slog::Index** appdelta1129;  slog::Index** evaldelta1130;  slog::Index** evaldelta1131;  slog::Index** eval_argsdelta1132;  slog::Index** primdelta1133;  slog::Index** deltadelta1134;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1136({0, 1});
      slog::Relation* readrel1137 = db->getRelation("eval_ans");
      head_index[0] = readrel1137->getIndex(ord1136, false);
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord1138({0, 2, 1});
      slog::Relation* readrel1139 = db->getRelation("eval");
      evalindex1114 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("eval");
      evalindex1115 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 2, 0});
      slog::Relation* readrel1143 = db->getRelation("eval_args");
      eval_argsindex1116 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 2, 0});
      slog::Relation* readrel1145 = db->getRelation("app");
      appindex1117 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({1, 2, 0});
      slog::Relation* readrel1147 = db->getRelation("app");
      appdelta1129 = readrel1147->getIndex(ord1146, true);
      std::vector<u16> ord1148({0, 2, 1});
      slog::Relation* readrel1149 = db->getRelation("eval");
      evalindex1118 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({0, 2, 1});
      slog::Relation* readrel1151 = db->getRelation("eval");
      evaldelta1130 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({1, 2, 0});
      slog::Relation* readrel1153 = db->getRelation("eval");
      evalindex1119 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({1, 2, 0});
      slog::Relation* readrel1155 = db->getRelation("eval");
      evaldelta1131 = readrel1155->getIndex(ord1154, true);
      std::vector<u16> ord1156({0, 1});
      slog::Relation* readrel1157 = db->getRelation("eval_ans");
      eval_ansindex1120 = readrel1157->getIndex(ord1156, false);
      std::vector<u16> ord1158({1, 2, 0});
      slog::Relation* readrel1159 = db->getRelation("eval_args");
      eval_argsindex1121 = readrel1159->getIndex(ord1158, false);
      std::vector<u16> ord1160({1, 2, 0});
      slog::Relation* readrel1161 = db->getRelation("eval_args");
      eval_argsdelta1132 = readrel1161->getIndex(ord1160, true);
      std::vector<u16> ord1162({0, 1});
      slog::Relation* readrel1163 = db->getRelation("eval_args_ans");
      eval_args_ansindex1122 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({0, 1});
      slog::Relation* readrel1165 = db->getRelation("eval_ans");
      eval_ansindex1123 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({0, 1});
      slog::Relation* readrel1167 = db->getRelation("eval_args_ans");
      eval_args_ansindex1124 = readrel1167->getIndex(ord1166, false);
      std::vector<u16> ord1168({2, 0, 1});
      slog::Relation* readrel1169 = db->getRelation("delta");
      deltaindex1125 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({0, 1});
      slog::Relation* readrel1171 = db->getRelation("prim");
      primindex1126 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({0, 1});
      slog::Relation* readrel1173 = db->getRelation("prim");
      primdelta1133 = readrel1173->getIndex(ord1172, true);
      std::vector<u16> ord1174({1, 2, 0});
      slog::Relation* readrel1175 = db->getRelation("delta");
      deltaindex1127 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({1, 2, 0});
      slog::Relation* readrel1177 = db->getRelation("delta");
      deltadelta1134 = readrel1177->getIndex(ord1176, true);
      std::vector<u16> ord1178({0, 1});
      slog::Relation* readrel1179 = db->getRelation("delta_ans");
      delta_ansindex1128 = readrel1179->getIndex(ord1178, false);
  
    }
    ReadTask1135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        if (!slog::exists_probe<3,2>(evalindex1114, std::array<u64,3>{v_c95, v_c14, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1115, std::array<u64,3>{v_c26, v_c14, 0})) return;
        if (!slog::exists_probe<3,2>(eval_argsindex1116, std::array<u64,3>{v_c27, v_c14, 0})) return;
        slog::join_probe_old<3,2>(appindex1117, appdelta1129, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m1180) {
          u64 v_c96 = m1180[2];
          slog::join_probe_old<3,3>(evalindex1118, evaldelta1130, std::array<u64,3>{v_c95, v_c14, v_c96}, [&](const std::array<u64,3>& m1181) {
            slog::join_probe_old<3,2>(evalindex1119, evaldelta1131, std::array<u64,3>{v_c26, v_c14, 0}, [&](const std::array<u64,3>& m1182) {
              u64 v_c97 = m1182[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1120, std::array<u64,2>{v_c97, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex1121, eval_argsdelta1132, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m1183) {
                u64 v_c98 = m1183[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1122, std::array<u64,2>{v_c98, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1123, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1184) {
                  u64 v_c99 = m1184[1];
                  slog::join_probe<2,1>(eval_args_ansindex1124, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1185) {
                    u64 v_c31 = m1185[1];
                    if (!slog::exists_probe<3,1>(deltaindex1125, std::array<u64,3>{v_c31, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex1126, primdelta1133, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1186) {
                      u64 v_c36 = m1186[1];
                      slog::join_probe_old<3,2>(deltaindex1127, deltadelta1134, std::array<u64,3>{v_c36, v_c31, 0}, [&](const std::array<u64,3>& m1187) {
                        u64 v_c100 = m1187[2];
                        slog::join_probe<2,1>(delta_ansindex1128, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m1188) {
                          u64 v_c58 = m1188[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c95, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1135* _cont = new ReadTask1135(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1135(db,b), false);
  // (crule (pre (let __t3TU6119 (lempty))) (scan program e) (body) (head (emit-temp temp8Oyq932 __t3TU6119 e)) interp.slog:129 #f)
  class ReadTask1189 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8Oyq932");
      outer_rel = db->getRelation("program");
  
    }
    ReadTask1189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c219 = _prim_lempty(db);
      if (v_c219 == slog_error) { slog::emit_pending_error(db, "interp.slog:129"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c161 = _t[0];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c219, v_c161});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:129", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask1189* _cont = new ReadTask1189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1189(db,b), false);
  // (crule (pre) (scan lookup __t82W616 x c) (body (join binding (0 1 2) 2 x c v)) (head (emit lookup_ans (0 1) __t82W616 v)) interp.slog:32 #f)
  class ReadTask1191 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex1190;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord1192({0, 1});
      slog::Relation* readrel1193 = db->getRelation("lookup_ans");
      head_index[0] = readrel1193->getIndex(ord1192, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord1194({0, 1, 2});
      slog::Relation* readrel1195 = db->getRelation("binding");
      bindingindex1190 = readrel1195->getIndex(ord1194, false);
  
    }
    ReadTask1191(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c220 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe<3,2>(bindingindex1190, std::array<u64,3>{v_c43, v_c14, 0}, [&](const std::array<u64,3>& m1196) {
          u64 v_c58 = m1196[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c220, v_c58}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask1191* _cont = new ReadTask1191(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1191(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst2I8h285 const7297d2085ea0adffc396d546) (let __tconst48zw269 const0933fb667296882d8c45abca) (let __tconst7F8v233 const53a56174f3826669a422fc54) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst16Fs254 const879923da020d1533f4d8e921)) (scan temp1Z8g963 __t1sga232 __t3DyN290 __t41Z9268 __t4Zol274 __t5YMF258 __t5xQ3284 __t5yWE289 __t9Hvd221) (body (exists ref (1 0) 1 __tconst7wlx292) (exists ref (1 0) 1 __tconst7F8v233) (exists app (2 0 1) 1 __t1sga232) (exists ref (1 0) 1 __tconst4aTz260) (exists ref (1 0) 1 __tconst48zw269) (exists app (2 0 1) 1 __t41Z9268) (exists ref (1 0) 1 __tconst2I8h285) (exists app (2 0 1) 1 __t5xQ3284) (exists ref (1 0) 1 __tconst6YSZ252) (exists ref (1 0) 1 __tconst39ZW253) (exists ref (1 0) 1 __tconst16Fs254) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst7wlx292 __t1iN7225) (join ref (1 0) 1 __tconst7F8v233 __t3grR234) (join app (1 2 0) 2 __t3grR234 __t1sga232 __t2Un6235) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join ref (1 0) 1 __tconst48zw269 __t7uwu270) (join app (1 2 0) 2 __t7uwu270 __t41Z9268 __t8kBG271) (join ref (1 0) 1 __tconst2I8h285 __t5wDB286) (join app (1 2 0) 2 __t5wDB286 __t5xQ3284 __t36Tx287) (join ref (1 0) 1 __tconst6YSZ252 __t7SX3246) (exists if (3 0 1 2) 1 __t7SX3246) (join ref (1 0) 1 __tconst39ZW253 __t1waL248) (join if (2 3 1 0) 2 __t1waL248 __t7SX3246 __t54jO250 __t4Qs4251) (join ref (0 1) 2 __t54jO250 __tconst16Fs254) (let __t3RWJ237 (lpush __t5yWE289 __t2Un6235))) (head (emit-temp temp8QhX964 __t36Tx287 __t3DyN290 __t3RWJ237 __t4Zol274 __t5YMF258 __t8kBG271 __t9Hvd221) (mkstruct lambda (1 2 0) __t4sa5291 __t3DyN290 __t36Tx287) (mkstruct lambda (1 2 0) __t7Cof275 __t4Zol274 __t8kBG271) (mkstruct lambda (1 2 0) __t34RH259 __t5YMF258 __t4Qs4251)) analysis-demo.slog:21 #f)
  class ReadTask1222 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1197;  slog::Index** refindex1198;  slog::Index** appindex1199;  slog::Index** refindex1200;  slog::Index** refindex1201;  slog::Index** appindex1202;  slog::Index** refindex1203;  slog::Index** appindex1204;  slog::Index** refindex1205;  slog::Index** refindex1206;  slog::Index** refindex1207;  slog::Index** refindex1208;  slog::Index** refindex1209;  slog::Index** refindex1210;  slog::Index** appindex1211;  slog::Index** refindex1212;  slog::Index** refindex1213;  slog::Index** appindex1214;  slog::Index** refindex1215;  slog::Index** appindex1216;  slog::Index** refindex1217;  slog::Index** ifindex1218;  slog::Index** refindex1219;  slog::Index** ifindex1220;  slog::Index** refindex1221;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8QhX964");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      head_rel[3] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp1Z8g963");
      std::vector<u16> ord1223({1, 0});
      slog::Relation* readrel1224 = db->getRelation("ref");
      refindex1197 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({1, 0});
      slog::Relation* readrel1226 = db->getRelation("ref");
      refindex1198 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({2, 0, 1});
      slog::Relation* readrel1228 = db->getRelation("app");
      appindex1199 = readrel1228->getIndex(ord1227, false);
      std::vector<u16> ord1229({1, 0});
      slog::Relation* readrel1230 = db->getRelation("ref");
      refindex1200 = readrel1230->getIndex(ord1229, false);
      std::vector<u16> ord1231({1, 0});
      slog::Relation* readrel1232 = db->getRelation("ref");
      refindex1201 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({2, 0, 1});
      slog::Relation* readrel1234 = db->getRelation("app");
      appindex1202 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 0});
      slog::Relation* readrel1236 = db->getRelation("ref");
      refindex1203 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({2, 0, 1});
      slog::Relation* readrel1238 = db->getRelation("app");
      appindex1204 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 0});
      slog::Relation* readrel1240 = db->getRelation("ref");
      refindex1205 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({1, 0});
      slog::Relation* readrel1242 = db->getRelation("ref");
      refindex1206 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({1, 0});
      slog::Relation* readrel1244 = db->getRelation("ref");
      refindex1207 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({1, 0});
      slog::Relation* readrel1246 = db->getRelation("ref");
      refindex1208 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({1, 0});
      slog::Relation* readrel1248 = db->getRelation("ref");
      refindex1209 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 0});
      slog::Relation* readrel1250 = db->getRelation("ref");
      refindex1210 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("app");
      appindex1211 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 0});
      slog::Relation* readrel1254 = db->getRelation("ref");
      refindex1212 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 0});
      slog::Relation* readrel1256 = db->getRelation("ref");
      refindex1213 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({1, 2, 0});
      slog::Relation* readrel1258 = db->getRelation("app");
      appindex1214 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({1, 0});
      slog::Relation* readrel1260 = db->getRelation("ref");
      refindex1215 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 2, 0});
      slog::Relation* readrel1262 = db->getRelation("app");
      appindex1216 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 0});
      slog::Relation* readrel1264 = db->getRelation("ref");
      refindex1217 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({3, 0, 1, 2});
      slog::Relation* readrel1266 = db->getRelation("if");
      ifindex1218 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 0});
      slog::Relation* readrel1268 = db->getRelation("ref");
      refindex1219 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({2, 3, 1, 0});
      slog::Relation* readrel1270 = db->getRelation("if");
      ifindex1220 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({0, 1});
      slog::Relation* readrel1272 = db->getRelation("ref");
      refindex1221 = readrel1272->getIndex(ord1271, false);
  
    }
    ReadTask1222(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c1 = v_constf77801bebb40767a1b303d97;
      u64 v_c2 = v_const829935b42173b360da35f679;
      u64 v_c66 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c221 = v_const7297d2085ea0adffc396d546;
      u64 v_c222 = v_const0933fb667296882d8c45abca;
      u64 v_c223 = v_const53a56174f3826669a422fc54;
      u64 v_c224 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c225 = v_const8ca5d81566f88badd698137a;
      u64 v_c226 = v_const879923da020d1533f4d8e921;
  
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
        u64 v_c227 = _t[0];
        u64 v_c228 = _t[1];
        u64 v_c229 = _t[2];
        u64 v_c230 = _t[3];
        u64 v_c231 = _t[4];
        u64 v_c232 = _t[5];
        u64 v_c233 = _t[6];
        u64 v_c68 = _t[7];
        if (!slog::exists_probe<2,1>(refindex1197, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1198, std::array<u64,2>{v_c223, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1199, std::array<u64,3>{v_c227, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1200, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1201, std::array<u64,2>{v_c222, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1202, std::array<u64,3>{v_c229, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1203, std::array<u64,2>{v_c221, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1204, std::array<u64,3>{v_c232, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1205, std::array<u64,2>{v_c224, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1206, std::array<u64,2>{v_c225, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1207, std::array<u64,2>{v_c226, 0})) return;
        slog::join_probe<2,1>(refindex1208, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1273) {
          u64 v_c234 = m1273[1];
          slog::join_probe<2,1>(refindex1209, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1274) {
            u64 v_c235 = m1274[1];
            slog::join_probe<2,1>(refindex1210, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1275) {
              u64 v_c236 = m1275[1];
              slog::join_probe<3,2>(appindex1211, std::array<u64,3>{v_c236, v_c227, 0}, [&](const std::array<u64,3>& m1276) {
                u64 v_c237 = m1276[2];
                slog::join_probe<2,1>(refindex1212, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1277) {
                  u64 v_c69 = m1277[1];
                  slog::join_probe<2,1>(refindex1213, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m1278) {
                    u64 v_c238 = m1278[1];
                    slog::join_probe<3,2>(appindex1214, std::array<u64,3>{v_c238, v_c229, 0}, [&](const std::array<u64,3>& m1279) {
                      u64 v_c239 = m1279[2];
                      slog::join_probe<2,1>(refindex1215, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m1280) {
                        u64 v_c240 = m1280[1];
                        slog::join_probe<3,2>(appindex1216, std::array<u64,3>{v_c240, v_c232, 0}, [&](const std::array<u64,3>& m1281) {
                          u64 v_c241 = m1281[2];
                          slog::join_probe<2,1>(refindex1217, std::array<u64,2>{v_c224, 0}, [&](const std::array<u64,2>& m1282) {
                            u64 v_c242 = m1282[1];
                            if (!slog::exists_probe<4,1>(ifindex1218, std::array<u64,4>{v_c242, 0, 0, 0})) return;
                            slog::join_probe<2,1>(refindex1219, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m1283) {
                              u64 v_c243 = m1283[1];
                              slog::join_probe<4,2>(ifindex1220, std::array<u64,4>{v_c243, v_c242, 0, 0}, [&](const std::array<u64,4>& m1284) {
                                u64 v_c244 = m1284[2]; u64 v_c245 = m1284[3];
                                slog::join_probe<2,2>(refindex1221, std::array<u64,2>{v_c244, v_c226}, [&](const std::array<u64,2>& m1285) {
                                  u64 v_c246 = _prim_lpush(db, v_c233, v_c237);
                                  if (v_c246 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                  ++_fires;
                                  slog::emit_temp<7>(head_rel[0], newbatch[0], std::array<u64,7>{v_c241, v_c228, v_c246, v_c230, v_c231, v_c239, v_c68});
                                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c228, v_c241}, std::array<u16,3>{1, 2, 0});
                                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c230, v_c239}, std::array<u16,3>{1, 2, 0});
                                  slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c231, v_c245}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp1Z8g963", _fires);
  
      if (!_done)
      {
        ReadTask1222* _cont = new ReadTask1222(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1222(db,b), false);
  // (crule (pre) (scan eval __t6e44178 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t6e44178) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t6uzd177) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4yWQ180 __t7rcY179 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask1315 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1286;  slog::Index** appindex1287;  slog::Index** eval_argsindex1288;  slog::Index** tickindex1289;  slog::Index** eval_ansindex1290;  slog::Index** $sup56712x41x0x0x0index1291;  slog::Index** appindex1292;  slog::Index** eval_argsindex1293;  slog::Index** evalindex1294;  slog::Index** appindex1295;  slog::Index** tickindex1296;  slog::Index** eval_argsindex1297;  slog::Index** eval_args_ansindex1298;  slog::Index** tickindex1299;  slog::Index** tick_ansindex1300;  slog::Index** eval_ansindex1301;  slog::Index** eval_args_ansindex1302;  slog::Index** tick_ansindex1303;  slog::Index** evalindex1304;  slog::Index** closureindex1305;  slog::Index** lambdaindex1306;  slog::Index** evalindex1307;  slog::Index** eval_ansindex1308;  slog::Index** appdelta1309;  slog::Index** eval_argsdelta1310;  slog::Index** tickdelta1311;  slog::Index** closuredelta1312;  slog::Index** lambdadelta1313;  slog::Index** evaldelta1314;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("eval_ans");
      head_index[0] = readrel1317->getIndex(ord1316, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1318({2, 0, 1});
      slog::Relation* readrel1319 = db->getRelation("eval");
      evalindex1286 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 2, 0});
      slog::Relation* readrel1321 = db->getRelation("app");
      appindex1287 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({2, 0, 1});
      slog::Relation* readrel1323 = db->getRelation("eval_args");
      eval_argsindex1288 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({2, 0, 1});
      slog::Relation* readrel1325 = db->getRelation("tick");
      tickindex1289 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({0, 1});
      slog::Relation* readrel1327 = db->getRelation("eval_ans");
      eval_ansindex1290 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 2, 3, 0});
      slog::Relation* readrel1329 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1291 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 2, 0});
      slog::Relation* readrel1331 = db->getRelation("app");
      appindex1292 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({1, 2, 0});
      slog::Relation* readrel1333 = db->getRelation("eval_args");
      eval_argsindex1293 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({0, 2, 1});
      slog::Relation* readrel1335 = db->getRelation("eval");
      evalindex1294 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({0, 1, 2});
      slog::Relation* readrel1337 = db->getRelation("app");
      appindex1295 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({0, 1, 2});
      slog::Relation* readrel1339 = db->getRelation("app");
      appdelta1309 = readrel1339->getIndex(ord1338, true);
      std::vector<u16> ord1340({1, 2, 0});
      slog::Relation* readrel1341 = db->getRelation("tick");
      tickindex1296 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({1, 2, 0});
      slog::Relation* readrel1343 = db->getRelation("eval_args");
      eval_argsindex1297 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({1, 2, 0});
      slog::Relation* readrel1345 = db->getRelation("eval_args");
      eval_argsdelta1310 = readrel1345->getIndex(ord1344, true);
      std::vector<u16> ord1346({0, 1});
      slog::Relation* readrel1347 = db->getRelation("eval_args_ans");
      eval_args_ansindex1298 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 0});
      slog::Relation* readrel1349 = db->getRelation("tick");
      tickindex1299 = readrel1349->getIndex(ord1348, false);
      std::vector<u16> ord1350({1, 2, 0});
      slog::Relation* readrel1351 = db->getRelation("tick");
      tickdelta1311 = readrel1351->getIndex(ord1350, true);
      std::vector<u16> ord1352({0, 1});
      slog::Relation* readrel1353 = db->getRelation("tick_ans");
      tick_ansindex1300 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({0, 1});
      slog::Relation* readrel1355 = db->getRelation("eval_ans");
      eval_ansindex1301 = readrel1355->getIndex(ord1354, false);
      std::vector<u16> ord1356({0, 1});
      slog::Relation* readrel1357 = db->getRelation("eval_args_ans");
      eval_args_ansindex1302 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({0, 1});
      slog::Relation* readrel1359 = db->getRelation("tick_ans");
      tick_ansindex1303 = readrel1359->getIndex(ord1358, false);
      std::vector<u16> ord1360({2, 0, 1});
      slog::Relation* readrel1361 = db->getRelation("eval");
      evalindex1304 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({0, 1, 2});
      slog::Relation* readrel1363 = db->getRelation("closure");
      closureindex1305 = readrel1363->getIndex(ord1362, false);
      std::vector<u16> ord1364({0, 1, 2});
      slog::Relation* readrel1365 = db->getRelation("closure");
      closuredelta1312 = readrel1365->getIndex(ord1364, true);
      std::vector<u16> ord1366({0, 1, 2});
      slog::Relation* readrel1367 = db->getRelation("lambda");
      lambdaindex1306 = readrel1367->getIndex(ord1366, false);
      std::vector<u16> ord1368({0, 1, 2});
      slog::Relation* readrel1369 = db->getRelation("lambda");
      lambdadelta1313 = readrel1369->getIndex(ord1368, true);
      std::vector<u16> ord1370({1, 2, 0});
      slog::Relation* readrel1371 = db->getRelation("eval");
      evalindex1307 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({1, 2, 0});
      slog::Relation* readrel1373 = db->getRelation("eval");
      evaldelta1314 = readrel1373->getIndex(ord1372, true);
      std::vector<u16> ord1374({0, 1});
      slog::Relation* readrel1375 = db->getRelation("eval_ans");
      eval_ansindex1308 = readrel1375->getIndex(ord1374, false);
  
    }
    ReadTask1315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1286, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1287, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1288, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1289, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1290, std::array<u64,2>{v_c62, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1291, std::array<u64,4>{v_c14, v_c26, 0, 0}, [&](const std::array<u64,4>& m1376) {
          u64 v_c27 = m1376[2]; u64 v_c64 = m1376[3];
          if (!slog::exists_probe<3,2>(appindex1292, std::array<u64,3>{v_c26, v_c27, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex1293, std::array<u64,3>{v_c27, v_c14, 0})) return;
          slog::join_probe<3,2>(evalindex1294, std::array<u64,3>{v_c64, v_c14, 0}, [&](const std::array<u64,3>& m1377) {
            u64 v_c63 = m1377[2];
            slog::join_probe_old<3,3>(appindex1295, appdelta1309, std::array<u64,3>{v_c63, v_c26, v_c27}, [&](const std::array<u64,3>& m1378) {
              if (!slog::exists_probe<3,2>(tickindex1296, std::array<u64,3>{v_c63, v_c14, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex1297, eval_argsdelta1310, std::array<u64,3>{v_c27, v_c14, 0}, [&](const std::array<u64,3>& m1379) {
                u64 v_c65 = m1379[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1298, std::array<u64,2>{v_c65, 0})) return;
                slog::join_probe_old<3,2>(tickindex1299, tickdelta1311, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m1380) {
                  u64 v_c59 = m1380[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1300, std::array<u64,2>{v_c59, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1301, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m1381) {
                    u64 v_c61 = m1381[1];
                    slog::join_probe<2,1>(eval_args_ansindex1302, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m1382) {
                      u64 v_c31 = m1382[1];
                      slog::join_probe<2,1>(tick_ansindex1303, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m1383) {
                        u64 v_c9 = m1383[1];
                        if (!slog::exists_probe<3,1>(evalindex1304, std::array<u64,3>{v_c9, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex1305, closuredelta1312, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m1384) {
                          u64 v_c60 = m1384[1]; u64 v_c24 = m1384[2];
                          slog::join_probe_old<3,1>(lambdaindex1306, lambdadelta1313, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m1385) {
                            u64 v_c32 = m1385[1]; u64 v_c33 = m1385[2];
                            slog::join_probe_old<3,2>(evalindex1307, evaldelta1314, std::array<u64,3>{v_c33, v_c9, 0}, [&](const std::array<u64,3>& m1386) {
                              u64 v_c57 = m1386[2];
                              slog::join_probe<2,1>(eval_ansindex1308, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m1387) {
                                u64 v_c58 = m1387[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c58}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1315* _cont = new ReadTask1315(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1315(db,b), false);
  // (crule (pre) (scan eval __t8bEj309 er c) (body (exists letrec (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t8bEj309) (join $sup56712x93x0x0x0 (1 3 0 2 4) 2 c er __t3Qfa308 eb x) (exists eval (0 2 1) 2 __t3Qfa308 c) (exists eval (1 2 0) 2 eb c) (join letrec (2 1 3 0) 3 er x eb __t8pF7307) (join eval (0 2 1) 3 __t3Qfa308 c __t8pF7307) (join-old eval (1 2 0) 2 (1 2 0) eb c __t8NjM310) (exists eval_ans (0 1) 1 __t8NjM310) (join eval_ans (0 1) 1 __t8bEj309 vr) (join eval_ans (0 1) 1 __t8NjM310 v)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask1401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1388;  slog::Index** evalindex1389;  slog::Index** eval_ansindex1390;  slog::Index** $sup56712x93x0x0x0index1391;  slog::Index** evalindex1392;  slog::Index** evalindex1393;  slog::Index** letrecindex1394;  slog::Index** evalindex1395;  slog::Index** evalindex1396;  slog::Index** eval_ansindex1397;  slog::Index** eval_ansindex1398;  slog::Index** eval_ansindex1399;  slog::Index** evaldelta1400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1402({0, 1});
      slog::Relation* readrel1403 = db->getRelation("eval_ans");
      head_index[0] = readrel1403->getIndex(ord1402, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1404({2, 1, 3, 0});
      slog::Relation* readrel1405 = db->getRelation("letrec");
      letrecindex1388 = readrel1405->getIndex(ord1404, false);
      std::vector<u16> ord1406({2, 0, 1});
      slog::Relation* readrel1407 = db->getRelation("eval");
      evalindex1389 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({0, 1});
      slog::Relation* readrel1409 = db->getRelation("eval_ans");
      eval_ansindex1390 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({1, 3, 0, 2, 4});
      slog::Relation* readrel1411 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index1391 = readrel1411->getIndex(ord1410, false);
      std::vector<u16> ord1412({0, 2, 1});
      slog::Relation* readrel1413 = db->getRelation("eval");
      evalindex1392 = readrel1413->getIndex(ord1412, false);
      std::vector<u16> ord1414({1, 2, 0});
      slog::Relation* readrel1415 = db->getRelation("eval");
      evalindex1393 = readrel1415->getIndex(ord1414, false);
      std::vector<u16> ord1416({2, 1, 3, 0});
      slog::Relation* readrel1417 = db->getRelation("letrec");
      letrecindex1394 = readrel1417->getIndex(ord1416, false);
      std::vector<u16> ord1418({0, 2, 1});
      slog::Relation* readrel1419 = db->getRelation("eval");
      evalindex1395 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({1, 2, 0});
      slog::Relation* readrel1421 = db->getRelation("eval");
      evalindex1396 = readrel1421->getIndex(ord1420, false);
      std::vector<u16> ord1422({1, 2, 0});
      slog::Relation* readrel1423 = db->getRelation("eval");
      evaldelta1400 = readrel1423->getIndex(ord1422, true);
      std::vector<u16> ord1424({0, 1});
      slog::Relation* readrel1425 = db->getRelation("eval_ans");
      eval_ansindex1397 = readrel1425->getIndex(ord1424, false);
      std::vector<u16> ord1426({0, 1});
      slog::Relation* readrel1427 = db->getRelation("eval_ans");
      eval_ansindex1398 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({0, 1});
      slog::Relation* readrel1429 = db->getRelation("eval_ans");
      eval_ansindex1399 = readrel1429->getIndex(ord1428, false);
  
    }
    ReadTask1401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c247 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<4,1>(letrecindex1388, std::array<u64,4>{v_c73, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1389, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1390, std::array<u64,2>{v_c247, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index1391, std::array<u64,5>{v_c14, v_c73, 0, 0, 0}, [&](const std::array<u64,5>& m1430) {
          u64 v_c248 = m1430[2]; u64 v_c33 = m1430[3]; u64 v_c43 = m1430[4];
          if (!slog::exists_probe<3,2>(evalindex1392, std::array<u64,3>{v_c248, v_c14, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex1393, std::array<u64,3>{v_c33, v_c14, 0})) return;
          slog::join_probe<4,3>(letrecindex1394, std::array<u64,4>{v_c73, v_c43, v_c33, 0}, [&](const std::array<u64,4>& m1431) {
            u64 v_c249 = m1431[3];
            slog::join_probe<3,3>(evalindex1395, std::array<u64,3>{v_c248, v_c14, v_c249}, [&](const std::array<u64,3>& m1432) {
              slog::join_probe_old<3,2>(evalindex1396, evaldelta1400, std::array<u64,3>{v_c33, v_c14, 0}, [&](const std::array<u64,3>& m1433) {
                u64 v_c250 = m1433[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1397, std::array<u64,2>{v_c250, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1398, std::array<u64,2>{v_c247, 0}, [&](const std::array<u64,2>& m1434) {
                  u64 v_c76 = m1434[1];
                  slog::join_probe<2,1>(eval_ansindex1399, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1435) {
                    u64 v_c58 = m1435[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c248, v_c58}, std::array<u16,2>{0, 1});
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
        ReadTask1401* _cont = new ReadTask1401(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1401(db,b), false);
  // (crule (pre (let __t5FX9367 (lempty))) (scan lst_take_ans __t7KjH370 __v0) (body (join-old lst_take (0 1 2) 1 (0 1 2) __t7KjH370 __t82mC369 m) (join mlimit (0) 1 m) (join-old tick (0 2 1) 0 (0 2 1) __t18ya366 c site) (let __t70Q4368 (lpush __t5FX9367 site)) (let chk4QtR930 (lcat __t70Q4368 c)) (eq __t82mC369 chk4QtR930)) (head (emit tick_ans (0 1) __t18ya366 __v0)) context.slog:10 #f)
  class ReadTask1441 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_takeindex1436;  slog::Index** mlimitindex1437;  slog::Index** tickindex1438;  slog::Index** lst_takedelta1439;  slog::Index** tickdelta1440;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord1442({0, 1});
      slog::Relation* readrel1443 = db->getRelation("tick_ans");
      head_index[0] = readrel1443->getIndex(ord1442, false);
      outer_rel = db->getRelation("lst_take_ans");
      std::vector<u16> ord1444({0, 1, 2});
      slog::Relation* readrel1445 = db->getRelation("lst_take");
      lst_takeindex1436 = readrel1445->getIndex(ord1444, false);
      std::vector<u16> ord1446({0, 1, 2});
      slog::Relation* readrel1447 = db->getRelation("lst_take");
      lst_takedelta1439 = readrel1447->getIndex(ord1446, true);
      std::vector<u16> ord1448({0});
      slog::Relation* readrel1449 = db->getRelation("mlimit");
      mlimitindex1437 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({0, 2, 1});
      slog::Relation* readrel1451 = db->getRelation("tick");
      tickindex1438 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({0, 2, 1});
      slog::Relation* readrel1453 = db->getRelation("tick");
      tickdelta1440 = readrel1453->getIndex(ord1452, true);
  
    }
    ReadTask1441(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c251 = _prim_lempty(db);
      if (v_c251 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c252 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe_old<3,1>(lst_takeindex1436, lst_takedelta1439, std::array<u64,3>{v_c252, 0, 0}, [&](const std::array<u64,3>& m1454) {
          u64 v_c253 = m1454[1]; u64 v_c254 = m1454[2];
          slog::join_probe<1,1>(mlimitindex1437, std::array<u64,1>{v_c254}, [&](const std::array<u64,1>& m1455) {
            slog::join_all_old<3>(tickindex1438, tickdelta1440, [&](const std::array<u64,3>& m1456) {
              u64 v_c255 = m1456[0]; u64 v_c14 = m1456[1]; u64 v_c256 = m1456[2];
              u64 v_c257 = _prim_lpush(db, v_c251, v_c256);
              if (v_c257 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              u64 v_c258 = _prim_lcat(db, v_c257, v_c14);
              if (v_c258 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              if (v_c253 != v_c258) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c255, v_c9}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:lst_take_ans", _fires);
  
      if (!_done)
      {
        ReadTask1441* _cont = new ReadTask1441(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1441(db,b), false);
  // (crule (pre) (scan freevar y __t4lcS166) (body (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4lcS166 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __0ffn676 c __t45PK165) (join-old app (0 1 2) 1 (0 1 2) __t45PK165 ef es)) (head (mkstruct eval_args (1 2 0) __3T4u677 es c)) interp.slog:56 #f)
  class ReadTask1464 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex1457;  slog::Index** lambdaindex1458;  slog::Index** evalindex1459;  slog::Index** appindex1460;  slog::Index** lambdadelta1461;  slog::Index** evaldelta1462;  slog::Index** appdelta1463;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1465({0, 1, 2});
      slog::Relation* readrel1466 = db->getRelation("binding");
      bindingindex1457 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({0, 1, 2});
      slog::Relation* readrel1468 = db->getRelation("lambda");
      lambdaindex1458 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({0, 1, 2});
      slog::Relation* readrel1470 = db->getRelation("lambda");
      lambdadelta1461 = readrel1470->getIndex(ord1469, true);
      std::vector<u16> ord1471({0, 2, 1});
      slog::Relation* readrel1472 = db->getRelation("eval");
      evalindex1459 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({0, 2, 1});
      slog::Relation* readrel1474 = db->getRelation("eval");
      evaldelta1462 = readrel1474->getIndex(ord1473, true);
      std::vector<u16> ord1475({0, 1, 2});
      slog::Relation* readrel1476 = db->getRelation("app");
      appindex1460 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({0, 1, 2});
      slog::Relation* readrel1478 = db->getRelation("app");
      appdelta1463 = readrel1478->getIndex(ord1477, true);
  
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
        u64 v_c177 = _t[0];
        u64 v_c259 = _t[1];
        slog::join_probe<3,1>(bindingindex1457, std::array<u64,3>{v_c177, 0, 0}, [&](const std::array<u64,3>& m1479) {
          u64 v_c24 = m1479[1]; u64 v_c179 = m1479[2];
          slog::join_probe_old<3,1>(lambdaindex1458, lambdadelta1461, std::array<u64,3>{v_c259, 0, 0}, [&](const std::array<u64,3>& m1480) {
            u64 v_c32 = m1480[1]; u64 v_c33 = m1480[2];
            slog::join_all_old<3>(evalindex1459, evaldelta1462, [&](const std::array<u64,3>& m1481) {
              u64 v_c260 = m1481[0]; u64 v_c14 = m1481[1]; u64 v_c261 = m1481[2];
              slog::join_probe_old<3,1>(appindex1460, appdelta1463, std::array<u64,3>{v_c261, 0, 0}, [&](const std::array<u64,3>& m1482) {
                u64 v_c26 = m1482[1]; u64 v_c27 = m1482[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c14}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
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
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0) (let __tconst7ska196 const06abaa100ecef791ce028c56) (let _00024sqc2bs1547 constd4735e3a265e16eee03f5971) (let _00024sqc3b5Z548 const5feceb66ffc86f38d952786c) (let _00024sqc4cPv549 const6b86b273ff34fce19d6b804e) (let _00024sqo2orM550 const5feceb66ffc86f38d952786c) (let _00024sqo79dC551 const6b86b273ff34fce19d6b804e) (let _00024sqo7ukz552 const6b86b273ff34fce19d6b804e) (let _00024sqo5FdA553 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2orM550 v1 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7ukz552 v1 _00024seq0) (letp _00024sql4FKJ545 (aslst _00024seq0)) (letp v2 (lref _00024sql4FKJ545 _00024sqc4cPv549)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo79dC551 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5FdA553 v2 _00024seq0) (exists _enum (1 0) 1 __tconst5mQl666) (join delta (1 2 0) 2 __tconst7ska196 _00024seq0 __t0ECW197) (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (let chk10Y1872 (llen _00024sql4FKJ545)) (eq _00024sqc2bs1547 chk10Y1872) (letp chk5Ayq873 (lref _00024sql4FKJ545 _00024sqc3b5Z548)) (eq v1 chk5Ayq873)) (head (emit-temp temp5E9s870 __t0ECW197) (mkstruct boolval (1 0) __t2gQB195 __t7sei194)) interp.slog:120 #f)
  class ReadTask1492 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex1483;  slog::Index** $seq_atindex1484;  slog::Index** $seq_atrindex1485;  slog::Index** _enumindex1486;  slog::Index** deltaindex1487;  slog::Index** _enumindex1488;  slog::Index** $seq_atrdelta1489;  slog::Index** $seq_atdelta1490;  slog::Index** $seq_atrdelta1491;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5E9s870");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1493({1, 0, 2});
      slog::Relation* readrel1494 = db->getRelation("$seq_at");
      driver_index = readrel1494->getIndex(ord1493, true);
      std::vector<u16> ord1495({1, 0, 2});
      slog::Relation* readrel1496 = db->getRelation("$seq_atr");
      $seq_atrindex1483 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({1, 0, 2});
      slog::Relation* readrel1498 = db->getRelation("$seq_atr");
      $seq_atrdelta1489 = readrel1498->getIndex(ord1497, true);
      std::vector<u16> ord1499({1, 0, 2});
      slog::Relation* readrel1500 = db->getRelation("$seq_at");
      $seq_atindex1484 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({1, 0, 2});
      slog::Relation* readrel1502 = db->getRelation("$seq_at");
      $seq_atdelta1490 = readrel1502->getIndex(ord1501, true);
      std::vector<u16> ord1503({1, 0, 2});
      slog::Relation* readrel1504 = db->getRelation("$seq_atr");
      $seq_atrindex1485 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({1, 0, 2});
      slog::Relation* readrel1506 = db->getRelation("$seq_atr");
      $seq_atrdelta1491 = readrel1506->getIndex(ord1505, true);
      std::vector<u16> ord1507({1, 0});
      slog::Relation* readrel1508 = db->getRelation("_enum");
      _enumindex1486 = readrel1508->getIndex(ord1507, false);
      std::vector<u16> ord1509({1, 2, 0});
      slog::Relation* readrel1510 = db->getRelation("delta");
      deltaindex1487 = readrel1510->getIndex(ord1509, false);
      std::vector<u16> ord1511({1, 0});
      slog::Relation* readrel1512 = db->getRelation("_enum");
      _enumindex1488 = readrel1512->getIndex(ord1511, false);
  
    }
    ReadTask1492(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c262 = v_const06abaa100ecef791ce028c56;
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
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c266, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1513) {
        u64 v_c270 = m1513[1];
        u64 v_c136 = m1513[2];
        if (buckethash(v_c270) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex1483, $seq_atrdelta1489, std::array<u64,3>{v_c268, v_c270, v_c136}, [&](const std::array<u64,3>& m1514) {
          bool ok1515 = true;
          u64 v_c271 = _prim_aslst(db, v_c136, &ok1515);
          if (!ok1515) return;
          bool ok1516 = true;
          u64 v_c272 = _prim_lref(db, v_c271, v_c265, &ok1516);
          if (!ok1516) return;
          if (v_c270 == v_c272) return;
          slog::join_probe_old<3,3>($seq_atindex1484, $seq_atdelta1490, std::array<u64,3>{v_c267, v_c272, v_c136}, [&](const std::array<u64,3>& m1517) {
            slog::join_probe_old<3,3>($seq_atrindex1485, $seq_atrdelta1491, std::array<u64,3>{v_c269, v_c272, v_c136}, [&](const std::array<u64,3>& m1518) {
              if (!slog::exists_probe<2,1>(_enumindex1486, std::array<u64,2>{v_c45, 0})) return;
              slog::join_probe<3,2>(deltaindex1487, std::array<u64,3>{v_c262, v_c136, 0}, [&](const std::array<u64,3>& m1519) {
                u64 v_c46 = m1519[2];
                slog::join_probe<2,1>(_enumindex1488, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m1520) {
                  u64 v_c47 = m1520[1];
                  u64 v_c273 = _prim_llen(db, v_c271);
                  if (v_c273 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c263 != v_c273) return;
                  bool ok1521 = true;
                  u64 v_c274 = _prim_lref(db, v_c271, v_c264, &ok1521);
                  if (!ok1521) return;
                  if (v_c270 != v_c274) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c46});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c47}, std::array<u16,2>{1, 0});
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
        ReadTask1492* _cont = new ReadTask1492(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1492(db,b), false);
}

