
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const00b70a53bc33238570e12d7a;
extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const609d51837c7fc306b0cbb04a;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const71dc04e9084b526ffd253a28;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_const913be61629bf526ec23a58e7;
extern u64 v_const99565d312ddf7c579dcfd67c;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste6c67f7247161354cd7e1d34;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c779455f62c59ec92(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan select_branch __t1sbj433 __v0 e2 e3) (body (exists eval_ans (1 0) 1 __v0) (exists select_branch_ans (0 1) 1 __t1sbj433) (join $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3 e1 __d0 c) (join eval (1 2 0) 2 e1 c __t9Q4F432) (join eval_ans (0 1) 2 __t9Q4F432 __v0) (join select_branch_ans (0 1) 1 __t1sbj433 __v1)) (head (mkstruct eval (1 2 0) __9Gjy723 __v1 c)) interp.slog:87 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex0;  slog::Index** select_branch_ansindex1;  slog::Index** $sup56712x86x0x0x0index2;  slog::Index** evalindex3;  slog::Index** eval_ansindex4;  slog::Index** select_branch_ansindex5;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("eval_ans");
      eval_ansindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("select_branch_ans");
      select_branch_ansindex1 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({3, 4, 2, 0, 1});
      slog::Relation* readrel12 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index2 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 2, 0});
      slog::Relation* readrel14 = db->getRelation("eval");
      evalindex3 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("eval_ans");
      eval_ansindex4 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("select_branch_ans");
      select_branch_ansindex5 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(eval_ansindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex1, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index2, std::array<u64,5>{v_c2, v_c3, 0, 0, 0}, [&](const std::array<u64,5>& m19) {
          u64 v_c4 = m19[2]; u64 v_c5 = m19[3]; u64 v_c6 = m19[4];
          slog::join_probe<3,2>(evalindex3, std::array<u64,3>{v_c4, v_c6, 0}, [&](const std::array<u64,3>& m20) {
            u64 v_c7 = m20[2];
            slog::join_probe<2,2>(eval_ansindex4, std::array<u64,2>{v_c7, v_c1}, [&](const std::array<u64,2>& m21) {
              slog::join_probe<2,1>(select_branch_ansindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m22) {
                u64 v_c8 = m22[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c8, v_c6}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre (let __trid1UyS671 const342a69eb5a93251c8b7e179a) (let __trel0aVG672 const4a59dbb9cb3129dfcc75170b) (let __tcol03WR673 const5feceb66ffc86f38d952786c) (let __trel3YLv674 const4a59dbb9cb3129dfcc75170b) (let __tcol5wu1675 const6b86b273ff34fce19d6b804e)) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body) (head (tycheck e1 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid1UyS671 __trel0aVG672 __tcol03WR673 (1 2 3 4 0)) (tycheck c (accept seq) __trid1UyS671 __trel3YLv674 __tcol5wu1675 (1 2 3 4 0)) (mkstruct eval (1 2 0) __4M1u670 e1 c)) interp.slog:87 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid23;  u32 sid24;  u32 sid25;  u32 sid26;  u32 sid27;  u32 sid28;  u32 sid29;  u32 sid30;  u32 sid31;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      sid23 = db->getRelation("app")->getStructId();
      sid24 = db->getRelation("boolean")->getStructId();
      sid25 = db->getRelation("if")->getStructId();
      sid26 = db->getRelation("lambda")->getStructId();
      sid27 = db->getRelation("let")->getStructId();
      sid28 = db->getRelation("letrec")->getStructId();
      sid29 = db->getRelation("num")->getStructId();
      sid30 = db->getRelation("ref")->getStructId();
      sid31 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c10 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c3 = _t[4];
        ++_fires;
        if (!((is_struct(v_c4) && (decode_struct_id(v_c4) == sid23 || decode_struct_id(v_c4) == sid24 || decode_struct_id(v_c4) == sid25 || decode_struct_id(v_c4) == sid26 || decode_struct_id(v_c4) == sid27 || decode_struct_id(v_c4) == sid28 || decode_struct_id(v_c4) == sid29 || decode_struct_id(v_c4) == sid30 || decode_struct_id(v_c4) == sid31))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c9, v_c10, v_c11, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c9, v_c12, v_c13, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
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
  // (crule (pre) (scan lookup __t7XMo37 x c) (body (join primitive (0) 1 x)) (head (emit-temp temp1lMF953 __t7XMo37 x) (mkstruct prim (1 0) __t7sUm36 x)) interp.slog:33 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primitiveindex33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1lMF953");
      head_rel[1] = db->getRelation("prim");
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord35({0});
      slog::Relation* readrel36 = db->getRelation("primitive");
      primitiveindex33 = readrel36->getIndex(ord35, false);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<1,1>(primitiveindex33, std::array<u64,1>{v_c15}, [&](const std::array<u64,1>& m37) {
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c15});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask34* _cont = new ReadTask34(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask34(db,b), false);
  // (crule (pre) (scan closure __t4ROj198 __t2BTJ197 cb) (body (join eval_ans (1 0) 1 __t4ROj198 __t44Jo196) (join eval (0 2 1) 1 __t44Jo196 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join tick_ans (0 1) 1 __t3z31201 __v0) (join lambda (0 1 2) 1 __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
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
        u64 v_c16 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c18 = _t[2];
        slog::join_probe<2,1>(eval_ansindex38, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m93) {
          u64 v_c19 = m93[1];
          slog::join_probe<3,1>(evalindex39, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m94) {
            u64 v_c6 = m94[1]; u64 v_c20 = m94[2];
            if (!slog::exists_probe<3,1>(eval_argsindex40, std::array<u64,3>{v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex41, std::array<u64,3>{v_c20, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex42, std::array<u64,3>{v_c6, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x41x0x0x0index43, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m95) {
              u64 v_c21 = m95[2]; u64 v_c5 = m95[3];
              if (!slog::exists_probe<3,2>(appindex44, std::array<u64,3>{v_c20, v_c21, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex45, eval_argsdelta53, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m96) {
                u64 v_c22 = m96[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex46, std::array<u64,2>{v_c22, 0})) return;
                slog::join_probe_old<3,2>(appindex47, appdelta54, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m97) {
                  u64 v_c23 = m97[2];
                  slog::join_probe_old<3,2>(tickindex48, tickdelta55, std::array<u64,3>{v_c23, v_c6, 0}, [&](const std::array<u64,3>& m98) {
                    u64 v_c24 = m98[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex49, std::array<u64,2>{v_c24, 0})) return;
                    slog::join_probe<2,1>(eval_args_ansindex50, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m99) {
                      u64 v_c25 = m99[1];
                      slog::join_probe<2,1>(tick_ansindex51, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m100) {
                        u64 v_c1 = m100[1];
                        slog::join_probe<3,1>(lambdaindex52, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m101) {
                          u64 v_c26 = m101[1]; u64 v_c27 = m101[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c1}, std::array<u16,3>{1, 2, 0});
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
  // (crule (pre) (scan eval_ans __t55UJ311 __t9gUy312) (body (join-old prim (0 1) 1 (0 1) __t9gUy312 op) (join-old eval (0 2 1) 1 (0 2 1) __t55UJ311 c ef) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2HTD313) (join-old eval_args_ans (0 1) 1 (0 1) __t2HTD313 vs)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
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
        u64 v_c28 = _t[0];
        u64 v_c29 = _t[1];
        slog::join_probe_old<2,1>(primindex102, primdelta108, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m133) {
          u64 v_c30 = m133[1];
          slog::join_probe_old<3,1>(evalindex103, evaldelta109, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m134) {
            u64 v_c6 = m134[1]; u64 v_c20 = m134[2];
            if (!slog::exists_probe<3,1>(eval_argsindex104, std::array<u64,3>{v_c6, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index105, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m135) {
              u64 v_c21 = m135[2]; u64 v_c5 = m135[3];
              slog::join_probe_old<3,2>(eval_argsindex106, eval_argsdelta110, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m136) {
                u64 v_c31 = m136[2];
                slog::join_probe_old<2,1>(eval_args_ansindex107, eval_args_ansdelta111, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m137) {
                  u64 v_c25 = m137[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c30, v_c25}, std::array<u16,3>{1, 2, 0});
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
  // (crule (pre (let __tconst0jqw13 const6b86b273ff34fce19d6b804e) (let __trid8KnT728 const71dc04e9084b526ffd253a28) (let __trel0zIA729 const00b70a53bc33238570e12d7a) (let __tcol1EuT730 const5feceb66ffc86f38d952786c)) (scan lambda __t2Cl511 xs eb) (body (exists lst_absent (1 2 0) 1 xs) (exists lst_absent_ans (1 0) 1 __tconst0jqw13) (join freevar (1 0) 1 eb x) (join-old lst_absent (1 2 0) 2 (1 2 0) xs x __t4tDv12) (join lst_absent_ans (1 0) 2 __tconst0jqw13 __t4tDv12)) (head (tycheck x (accept str) __trid8KnT728 __trel0zIA729 __tcol1EuT730 (1 2 3 4 0)) (emit freevar (0 1) x __t2Cl511)) freevars.slog:28 #f)
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
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const71dc04e9084b526ffd253a28;
      u64 v_c34 = v_const00b70a53bc33238570e12d7a;
      u64 v_c35 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c26 = _t[1];
        u64 v_c27 = _t[2];
        if (!slog::exists_probe<3,1>(lst_absentindex138, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<2,1>(lst_absent_ansindex139, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<2,1>(freevarindex140, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m159) {
          u64 v_c15 = m159[1];
          slog::join_probe_old<3,2>(lst_absentindex141, lst_absentdelta143, std::array<u64,3>{v_c26, v_c15, 0}, [&](const std::array<u64,3>& m160) {
            u64 v_c37 = m160[2];
            slog::join_probe<2,2>(lst_absent_ansindex142, std::array<u64,2>{v_c32, v_c37}, [&](const std::array<u64,2>& m161) {
              ++_fires;
              if (!(is_str(v_c15)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c33, v_c34, v_c35, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c15, v_c36}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan app __t0Aad241 ef es) (body (join eval (1 2 0) 1 __t0Aad241 c __5LXb801)) (head (mkstruct eval_args (1 2 0) __66Zv802 es c)) interp.slog:48 #f)
  class ReadTask163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord164({1, 2, 0});
      slog::Relation* readrel165 = db->getRelation("eval");
      evalindex162 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c21 = _t[2];
        slog::join_probe<3,1>(evalindex162, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m166) {
          u64 v_c6 = m166[1]; u64 v_c39 = m166[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask163* _cont = new ReadTask163(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask163(db,b), false);
  // (crule (pre) (scan eval __23px789 __t7Nk2385 c) (body (join-old app (0 1 2) 1 (0 1 2) __t7Nk2385 ef es)) (head (mkstruct tick (1 2 0) __16lD790 __t7Nk2385 c)) interp.slog:48 #f)
  class ReadTask169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex167;  slog::Index** appdelta168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord170({0, 1, 2});
      slog::Relation* readrel171 = db->getRelation("app");
      appindex167 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 1, 2});
      slog::Relation* readrel173 = db->getRelation("app");
      appdelta168 = readrel173->getIndex(ord172, true);
  
    }
    ReadTask169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe_old<3,1>(appindex167, appdelta168, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m174) {
          u64 v_c20 = m174[1]; u64 v_c21 = m174[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c41, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask169* _cont = new ReadTask169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask169(db,b), false);
  // (crule (pre) (scan eval __t3K5j208 eb __v0) (body (exists tick_ans (1 0) 1 __v0) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t3K5j208 v) (join tick_ans (1 0) 1 __v0 __t3KuN210) (join lambda (2 0 1) 1 eb __t6hhS205 xs) (join closure (1 2 0) 1 __t6hhS205 cb __t6XAE206) (join eval_ans (1 0) 1 __t6XAE206 __t1DkM204) (join eval (0 2 1) 1 __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t3KuN210 c __t8x6E209) (exists app (0 1 2) 2 __t8x6E209 ef) (join eval (1 2 0) 2 __t8x6E209 c __t9lTe203) (join $sup56712x41x0x0x0 (1 0 2 3) 3 c __t9lTe203 ef es) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (join eval_args (1 2 0) 2 es c __t58jO207) (join eval_args_ans (0 1) 1 __t58jO207 vs)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex175;  slog::Index** lambdaindex176;  slog::Index** eval_ansindex177;  slog::Index** tick_ansindex178;  slog::Index** lambdaindex179;  slog::Index** closureindex180;  slog::Index** eval_ansindex181;  slog::Index** evalindex182;  slog::Index** evalindex183;  slog::Index** $sup56712x41x0x0x0index184;  slog::Index** appindex185;  slog::Index** eval_argsindex186;  slog::Index** tickindex187;  slog::Index** appindex188;  slog::Index** evalindex189;  slog::Index** $sup56712x41x0x0x0index190;  slog::Index** appindex191;  slog::Index** eval_argsindex192;  slog::Index** eval_args_ansindex193;  slog::Index** tickdelta194;  slog::Index** appdelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("eval_ans");
      head_index[0] = readrel198->getIndex(ord197, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord199({1, 0});
      slog::Relation* readrel200 = db->getRelation("tick_ans");
      tick_ansindex175 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({2, 0, 1});
      slog::Relation* readrel202 = db->getRelation("lambda");
      lambdaindex176 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("eval_ans");
      eval_ansindex177 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 0});
      slog::Relation* readrel206 = db->getRelation("tick_ans");
      tick_ansindex178 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({2, 0, 1});
      slog::Relation* readrel208 = db->getRelation("lambda");
      lambdaindex179 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("closure");
      closureindex180 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("eval_ans");
      eval_ansindex181 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({0, 2, 1});
      slog::Relation* readrel214 = db->getRelation("eval");
      evalindex182 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({2, 0, 1});
      slog::Relation* readrel216 = db->getRelation("eval");
      evalindex183 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 3, 0});
      slog::Relation* readrel218 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index184 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("app");
      appindex185 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({2, 0, 1});
      slog::Relation* readrel222 = db->getRelation("eval_args");
      eval_argsindex186 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({0, 2, 1});
      slog::Relation* readrel224 = db->getRelation("tick");
      tickindex187 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 2, 1});
      slog::Relation* readrel226 = db->getRelation("tick");
      tickdelta194 = readrel226->getIndex(ord225, true);
      std::vector<u16> ord227({0, 1, 2});
      slog::Relation* readrel228 = db->getRelation("app");
      appindex188 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("eval");
      evalindex189 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0, 2, 3});
      slog::Relation* readrel232 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index190 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1, 2});
      slog::Relation* readrel234 = db->getRelation("app");
      appindex191 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("app");
      appdelta195 = readrel236->getIndex(ord235, true);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("eval_args");
      eval_argsindex192 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 1});
      slog::Relation* readrel240 = db->getRelation("eval_args_ans");
      eval_args_ansindex193 = readrel240->getIndex(ord239, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<2,1>(tick_ansindex175, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex176, std::array<u64,3>{v_c27, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex177, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m241) {
          u64 v_c43 = m241[1];
          slog::join_probe<2,1>(tick_ansindex178, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m242) {
            u64 v_c44 = m242[1];
            slog::join_probe<3,1>(lambdaindex179, std::array<u64,3>{v_c27, 0, 0}, [&](const std::array<u64,3>& m243) {
              u64 v_c45 = m243[1]; u64 v_c26 = m243[2];
              slog::join_probe<3,1>(closureindex180, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m244) {
                u64 v_c18 = m244[1]; u64 v_c46 = m244[2];
                slog::join_probe<2,1>(eval_ansindex181, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m245) {
                  u64 v_c47 = m245[1];
                  slog::join_probe<3,1>(evalindex182, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m246) {
                    u64 v_c6 = m246[1]; u64 v_c20 = m246[2];
                    if (!slog::exists_probe<3,1>(evalindex183, std::array<u64,3>{v_c6, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index184, std::array<u64,4>{v_c6, v_c20, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex185, std::array<u64,3>{v_c20, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex186, std::array<u64,3>{v_c6, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex187, tickdelta194, std::array<u64,3>{v_c44, v_c6, 0}, [&](const std::array<u64,3>& m247) {
                      u64 v_c48 = m247[2];
                      if (!slog::exists_probe<3,2>(appindex188, std::array<u64,3>{v_c48, v_c20, 0})) return;
                      slog::join_probe<3,2>(evalindex189, std::array<u64,3>{v_c48, v_c6, 0}, [&](const std::array<u64,3>& m248) {
                        u64 v_c49 = m248[2];
                        slog::join_probe<4,3>($sup56712x41x0x0x0index190, std::array<u64,4>{v_c6, v_c49, v_c20, 0}, [&](const std::array<u64,4>& m249) {
                          u64 v_c21 = m249[3];
                          slog::join_probe_old<3,3>(appindex191, appdelta195, std::array<u64,3>{v_c48, v_c20, v_c21}, [&](const std::array<u64,3>& m250) {
                            slog::join_probe<3,2>(eval_argsindex192, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m251) {
                              u64 v_c50 = m251[2];
                              slog::join_probe<2,1>(eval_args_ansindex193, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m252) {
                                u64 v_c25 = m252[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask196* _cont = new ReadTask196(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask196(db,b), false);
  // (crule (pre) (scan eval_ans __t1DkM204 __t6XAE206) (body (join-old eval (0 2 1) 1 (0 2 1) __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join-old $sup56712x41x0x0x0 (1 2 3 0) 2 (1 2 3 0) c ef es __t9lTe203) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (0 2 1) 2 (0 2 1) __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join-old eval_args_ans (0 1) 1 (0 1) __t58jO207 vs) (join-old tick_ans (0 1) 1 (0 1) __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t6XAE206 __t6hhS205 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join-old eval_ans (0 1) 1 (0 1) __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex253;  slog::Index** evalindex254;  slog::Index** appindex255;  slog::Index** eval_argsindex256;  slog::Index** tickindex257;  slog::Index** $sup56712x41x0x0x0index258;  slog::Index** appindex259;  slog::Index** eval_argsindex260;  slog::Index** evalindex261;  slog::Index** appindex262;  slog::Index** tickindex263;  slog::Index** eval_argsindex264;  slog::Index** eval_args_ansindex265;  slog::Index** tickindex266;  slog::Index** tick_ansindex267;  slog::Index** eval_args_ansindex268;  slog::Index** tick_ansindex269;  slog::Index** evalindex270;  slog::Index** closureindex271;  slog::Index** lambdaindex272;  slog::Index** evalindex273;  slog::Index** eval_ansindex274;  slog::Index** evaldelta275;  slog::Index** $sup56712x41x0x0x0delta276;  slog::Index** evaldelta277;  slog::Index** appdelta278;  slog::Index** eval_argsdelta279;  slog::Index** tickdelta280;  slog::Index** eval_args_ansdelta281;  slog::Index** tick_ansdelta282;  slog::Index** closuredelta283;  slog::Index** lambdadelta284;  slog::Index** evaldelta285;  slog::Index** eval_ansdelta286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("eval_ans");
      head_index[0] = readrel289->getIndex(ord288, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord290({0, 2, 1});
      slog::Relation* readrel291 = db->getRelation("eval");
      evalindex253 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({0, 2, 1});
      slog::Relation* readrel293 = db->getRelation("eval");
      evaldelta275 = readrel293->getIndex(ord292, true);
      std::vector<u16> ord294({2, 0, 1});
      slog::Relation* readrel295 = db->getRelation("eval");
      evalindex254 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("app");
      appindex255 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({2, 0, 1});
      slog::Relation* readrel299 = db->getRelation("eval_args");
      eval_argsindex256 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({2, 0, 1});
      slog::Relation* readrel301 = db->getRelation("tick");
      tickindex257 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 3, 0});
      slog::Relation* readrel303 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index258 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 3, 0});
      slog::Relation* readrel305 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta276 = readrel305->getIndex(ord304, true);
      std::vector<u16> ord306({1, 2, 0});
      slog::Relation* readrel307 = db->getRelation("app");
      appindex259 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("eval_args");
      eval_argsindex260 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({0, 2, 1});
      slog::Relation* readrel311 = db->getRelation("eval");
      evalindex261 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 2, 1});
      slog::Relation* readrel313 = db->getRelation("eval");
      evaldelta277 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({0, 1, 2});
      slog::Relation* readrel315 = db->getRelation("app");
      appindex262 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1, 2});
      slog::Relation* readrel317 = db->getRelation("app");
      appdelta278 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("tick");
      tickindex263 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 0});
      slog::Relation* readrel321 = db->getRelation("eval_args");
      eval_argsindex264 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("eval_args");
      eval_argsdelta279 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("eval_args_ans");
      eval_args_ansindex265 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 0});
      slog::Relation* readrel327 = db->getRelation("tick");
      tickindex266 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("tick");
      tickdelta280 = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({0, 1});
      slog::Relation* readrel331 = db->getRelation("tick_ans");
      tick_ansindex267 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({0, 1});
      slog::Relation* readrel333 = db->getRelation("eval_args_ans");
      eval_args_ansindex268 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("eval_args_ans");
      eval_args_ansdelta281 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("tick_ans");
      tick_ansindex269 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("tick_ans");
      tick_ansdelta282 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({2, 0, 1});
      slog::Relation* readrel341 = db->getRelation("eval");
      evalindex270 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1, 2});
      slog::Relation* readrel343 = db->getRelation("closure");
      closureindex271 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0, 1, 2});
      slog::Relation* readrel345 = db->getRelation("closure");
      closuredelta283 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1, 2});
      slog::Relation* readrel347 = db->getRelation("lambda");
      lambdaindex272 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1, 2});
      slog::Relation* readrel349 = db->getRelation("lambda");
      lambdadelta284 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("eval");
      evalindex273 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 2, 0});
      slog::Relation* readrel353 = db->getRelation("eval");
      evaldelta285 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1});
      slog::Relation* readrel355 = db->getRelation("eval_ans");
      eval_ansindex274 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("eval_ans");
      eval_ansdelta286 = readrel357->getIndex(ord356, true);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c46 = _t[1];
        slog::join_probe_old<3,1>(evalindex253, evaldelta275, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m358) {
          u64 v_c6 = m358[1]; u64 v_c20 = m358[2];
          if (!slog::exists_probe<3,1>(evalindex254, std::array<u64,3>{v_c6, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex255, std::array<u64,3>{v_c20, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex256, std::array<u64,3>{v_c6, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex257, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x41x0x0x0index258, $sup56712x41x0x0x0delta276, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m359) {
            u64 v_c21 = m359[2]; u64 v_c49 = m359[3];
            if (!slog::exists_probe<3,2>(appindex259, std::array<u64,3>{v_c20, v_c21, 0})) return;
            if (!slog::exists_probe<3,2>(eval_argsindex260, std::array<u64,3>{v_c21, v_c6, 0})) return;
            slog::join_probe_old<3,2>(evalindex261, evaldelta277, std::array<u64,3>{v_c49, v_c6, 0}, [&](const std::array<u64,3>& m360) {
              u64 v_c48 = m360[2];
              slog::join_probe_old<3,3>(appindex262, appdelta278, std::array<u64,3>{v_c48, v_c20, v_c21}, [&](const std::array<u64,3>& m361) {
                if (!slog::exists_probe<3,2>(tickindex263, std::array<u64,3>{v_c48, v_c6, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex264, eval_argsdelta279, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m362) {
                  u64 v_c50 = m362[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex265, std::array<u64,2>{v_c50, 0})) return;
                  slog::join_probe_old<3,2>(tickindex266, tickdelta280, std::array<u64,3>{v_c48, v_c6, 0}, [&](const std::array<u64,3>& m363) {
                    u64 v_c44 = m363[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex267, std::array<u64,2>{v_c44, 0})) return;
                    slog::join_probe_old<2,1>(eval_args_ansindex268, eval_args_ansdelta281, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m364) {
                      u64 v_c25 = m364[1];
                      slog::join_probe_old<2,1>(tick_ansindex269, tick_ansdelta282, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m365) {
                        u64 v_c1 = m365[1];
                        if (!slog::exists_probe<3,1>(evalindex270, std::array<u64,3>{v_c1, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex271, closuredelta283, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m366) {
                          u64 v_c45 = m366[1]; u64 v_c18 = m366[2];
                          slog::join_probe_old<3,1>(lambdaindex272, lambdadelta284, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m367) {
                            u64 v_c26 = m367[1]; u64 v_c27 = m367[2];
                            slog::join_probe_old<3,2>(evalindex273, evaldelta285, std::array<u64,3>{v_c27, v_c1, 0}, [&](const std::array<u64,3>& m368) {
                              u64 v_c42 = m368[2];
                              slog::join_probe_old<2,1>(eval_ansindex274, eval_ansdelta286, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m369) {
                                u64 v_c43 = m369[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3NP861 const609d51837c7fc306b0cbb04a)) (scan temp9y4i959 __t1pzN60 __t5uOh47 __t9J9k75 __t9Uwo95) (body (join let (2 1 3 0) 3 __t1pzN60 __tconst3NP861 __t5uOh47 __t351k62)) (head (emit-temp temp51he960 __t351k62 __t9J9k75 __t9Uwo95) (mkstruct let (2 1 3 0) __t00Fz77 __t9J9k75 __tconst4uoq76 __t351k62)) schemecfa.slog:39 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp51he960");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp9y4i959");
      std::vector<u16> ord372({2, 1, 3, 0});
      slog::Relation* readrel373 = db->getRelation("let");
      letindex370 = readrel373->getIndex(ord372, false);
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c52 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c53 = v_const609d51837c7fc306b0cbb04a;
  
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
        u64 v_c56 = _t[2];
        u64 v_c57 = _t[3];
        slog::join_probe<4,3>(letindex370, std::array<u64,4>{v_c54, v_c53, v_c55, 0}, [&](const std::array<u64,4>& m374) {
          u64 v_c58 = m374[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c58, v_c56, v_c57});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c56, v_c52, v_c58}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp9y4i959", _fires);
  
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
  // (crule (pre) (scan eval __t9j6S443 eb c) (body (exists let (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t9j6S443) (join $sup56712x91x0x0x0 (1 2 0 3 4) 2 c eb __t1bnm441 er x) (exists eval (0 2 1) 2 __t1bnm441 c) (exists eval (1 2 0) 2 er c) (join let (2 1 3 0) 3 er x eb __t0DPj440) (join eval (0 2 1) 3 __t1bnm441 c __t0DPj440) (join eval (1 2 0) 2 er c __t0jgp442) (join eval_ans (0 1) 1 __t0jgp442 vr) (join eval_ans (0 1) 1 __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask386 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex375;  slog::Index** evalindex376;  slog::Index** eval_ansindex377;  slog::Index** $sup56712x91x0x0x0index378;  slog::Index** evalindex379;  slog::Index** evalindex380;  slog::Index** letindex381;  slog::Index** evalindex382;  slog::Index** evalindex383;  slog::Index** eval_ansindex384;  slog::Index** eval_ansindex385;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("eval_ans");
      head_index[0] = readrel388->getIndex(ord387, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord389({3, 0, 1, 2});
      slog::Relation* readrel390 = db->getRelation("let");
      letindex375 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({2, 0, 1});
      slog::Relation* readrel392 = db->getRelation("eval");
      evalindex376 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("eval_ans");
      eval_ansindex377 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0, 3, 4});
      slog::Relation* readrel396 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index378 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 2, 1});
      slog::Relation* readrel398 = db->getRelation("eval");
      evalindex379 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("eval");
      evalindex380 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({2, 1, 3, 0});
      slog::Relation* readrel402 = db->getRelation("let");
      letindex381 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 2, 1});
      slog::Relation* readrel404 = db->getRelation("eval");
      evalindex382 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("eval");
      evalindex383 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({0, 1});
      slog::Relation* readrel408 = db->getRelation("eval_ans");
      eval_ansindex384 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("eval_ans");
      eval_ansindex385 = readrel410->getIndex(ord409, false);
  
    }
    ReadTask386(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<4,1>(letindex375, std::array<u64,4>{v_c27, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex376, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex377, std::array<u64,2>{v_c59, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index378, std::array<u64,5>{v_c6, v_c27, 0, 0, 0}, [&](const std::array<u64,5>& m411) {
          u64 v_c60 = m411[2]; u64 v_c61 = m411[3]; u64 v_c15 = m411[4];
          if (!slog::exists_probe<3,2>(evalindex379, std::array<u64,3>{v_c60, v_c6, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex380, std::array<u64,3>{v_c61, v_c6, 0})) return;
          slog::join_probe<4,3>(letindex381, std::array<u64,4>{v_c61, v_c15, v_c27, 0}, [&](const std::array<u64,4>& m412) {
            u64 v_c62 = m412[3];
            slog::join_probe<3,3>(evalindex382, std::array<u64,3>{v_c60, v_c6, v_c62}, [&](const std::array<u64,3>& m413) {
              slog::join_probe<3,2>(evalindex383, std::array<u64,3>{v_c61, v_c6, 0}, [&](const std::array<u64,3>& m414) {
                u64 v_c63 = m414[2];
                slog::join_probe<2,1>(eval_ansindex384, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m415) {
                  u64 v_c64 = m415[1];
                  slog::join_probe<2,1>(eval_ansindex385, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m416) {
                    u64 v_c43 = m416[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c60, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask386* _cont = new ReadTask386(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask386(db,b), false);
  // (crule (pre (let __tconst0jqw13 const6b86b273ff34fce19d6b804e) (let __trid8KnT728 const71dc04e9084b526ffd253a28) (let __trel0zIA729 const00b70a53bc33238570e12d7a) (let __tcol1EuT730 const5feceb66ffc86f38d952786c)) (scan lst_absent __t4tDv12 xs x) (body (join lst_absent_ans (1 0) 2 __tconst0jqw13 __t4tDv12) (exists lambda (1 2 0) 1 xs) (join freevar (0 1) 1 x eb) (join lambda (1 2 0) 2 xs eb __t2Cl511)) (head (tycheck x (accept str) __trid8KnT728 __trel0zIA729 __tcol1EuT730 (1 2 3 4 0)) (emit freevar (0 1) x __t2Cl511)) freevars.slog:28 #f)
  class ReadTask421 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absent_ansindex417;  slog::Index** lambdaindex418;  slog::Index** freevarindex419;  slog::Index** lambdaindex420;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("freevar");
      head_index[1] = readrel423->getIndex(ord422, false);
      outer_rel = db->getRelation("lst_absent");
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex417 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 0});
      slog::Relation* readrel427 = db->getRelation("lambda");
      lambdaindex418 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("freevar");
      freevarindex419 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 2, 0});
      slog::Relation* readrel431 = db->getRelation("lambda");
      lambdaindex420 = readrel431->getIndex(ord430, false);
  
    }
    ReadTask421(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const71dc04e9084b526ffd253a28;
      u64 v_c34 = v_const00b70a53bc33238570e12d7a;
      u64 v_c35 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c26 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe<2,2>(lst_absent_ansindex417, std::array<u64,2>{v_c32, v_c37}, [&](const std::array<u64,2>& m432) {
          if (!slog::exists_probe<3,1>(lambdaindex418, std::array<u64,3>{v_c26, 0, 0})) return;
          slog::join_probe<2,1>(freevarindex419, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m433) {
            u64 v_c27 = m433[1];
            slog::join_probe<3,2>(lambdaindex420, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m434) {
              u64 v_c36 = m434[2];
              ++_fires;
              if (!(is_str(v_c15)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c33, v_c34, v_c35, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c15, v_c36}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lst_absent", _fires);
  
      if (!_done)
      {
        ReadTask421* _cont = new ReadTask421(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask421(db,b), false);
  // (crule (pre) (scan let __t7Gbt142 x er eb) (body (join eval (1 2 0) 1 __t7Gbt142 c __6hwf725)) (head (mkstruct eval (1 2 0) __1Vwr726 er c)) interp.slog:93 #f)
  class ReadTask436 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex435;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("let");
      std::vector<u16> ord437({1, 2, 0});
      slog::Relation* readrel438 = db->getRelation("eval");
      evalindex435 = readrel438->getIndex(ord437, false);
  
    }
    ReadTask436(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c61 = _t[2];
        u64 v_c27 = _t[3];
        slog::join_probe<3,1>(evalindex435, std::array<u64,3>{v_c65, 0, 0}, [&](const std::array<u64,3>& m439) {
          u64 v_c6 = m439[1]; u64 v_c66 = m439[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c61, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask436* _cont = new ReadTask436(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask436(db,b), false);
  // (crule (pre) (scan closure __t6XAE206 __t6hhS205 cb) (body (join eval_ans (1 0) 1 __t6XAE206 __t1DkM204) (join eval (0 2 1) 1 __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t9lTe203) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join lambda (0 1 2) 1 __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex440;  slog::Index** evalindex441;  slog::Index** evalindex442;  slog::Index** appindex443;  slog::Index** eval_argsindex444;  slog::Index** tickindex445;  slog::Index** $sup56712x41x0x0x0index446;  slog::Index** appindex447;  slog::Index** eval_argsindex448;  slog::Index** evalindex449;  slog::Index** appindex450;  slog::Index** tickindex451;  slog::Index** eval_argsindex452;  slog::Index** eval_args_ansindex453;  slog::Index** tickindex454;  slog::Index** tick_ansindex455;  slog::Index** eval_args_ansindex456;  slog::Index** tick_ansindex457;  slog::Index** evalindex458;  slog::Index** lambdaindex459;  slog::Index** evalindex460;  slog::Index** eval_ansindex461;  slog::Index** appdelta462;  slog::Index** eval_argsdelta463;  slog::Index** tickdelta464;  slog::Index** evaldelta465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("eval_ans");
      head_index[0] = readrel468->getIndex(ord467, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord469({1, 0});
      slog::Relation* readrel470 = db->getRelation("eval_ans");
      eval_ansindex440 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 2, 1});
      slog::Relation* readrel472 = db->getRelation("eval");
      evalindex441 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({2, 0, 1});
      slog::Relation* readrel474 = db->getRelation("eval");
      evalindex442 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("app");
      appindex443 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({2, 0, 1});
      slog::Relation* readrel478 = db->getRelation("eval_args");
      eval_argsindex444 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({2, 0, 1});
      slog::Relation* readrel480 = db->getRelation("tick");
      tickindex445 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 2, 3, 0});
      slog::Relation* readrel482 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index446 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("app");
      appindex447 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 0});
      slog::Relation* readrel486 = db->getRelation("eval_args");
      eval_argsindex448 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({0, 2, 1});
      slog::Relation* readrel488 = db->getRelation("eval");
      evalindex449 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({0, 1, 2});
      slog::Relation* readrel490 = db->getRelation("app");
      appindex450 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 1, 2});
      slog::Relation* readrel492 = db->getRelation("app");
      appdelta462 = readrel492->getIndex(ord491, true);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("tick");
      tickindex451 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("eval_args");
      eval_argsindex452 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("eval_args");
      eval_argsdelta463 = readrel498->getIndex(ord497, true);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("eval_args_ans");
      eval_args_ansindex453 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("tick");
      tickindex454 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("tick");
      tickdelta464 = readrel504->getIndex(ord503, true);
      std::vector<u16> ord505({0, 1});
      slog::Relation* readrel506 = db->getRelation("tick_ans");
      tick_ansindex455 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("eval_args_ans");
      eval_args_ansindex456 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("tick_ans");
      tick_ansindex457 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({2, 0, 1});
      slog::Relation* readrel512 = db->getRelation("eval");
      evalindex458 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1, 2});
      slog::Relation* readrel514 = db->getRelation("lambda");
      lambdaindex459 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 2, 0});
      slog::Relation* readrel516 = db->getRelation("eval");
      evalindex460 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 2, 0});
      slog::Relation* readrel518 = db->getRelation("eval");
      evaldelta465 = readrel518->getIndex(ord517, true);
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("eval_ans");
      eval_ansindex461 = readrel520->getIndex(ord519, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c18 = _t[2];
        slog::join_probe<2,1>(eval_ansindex440, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m521) {
          u64 v_c47 = m521[1];
          slog::join_probe<3,1>(evalindex441, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m522) {
            u64 v_c6 = m522[1]; u64 v_c20 = m522[2];
            if (!slog::exists_probe<3,1>(evalindex442, std::array<u64,3>{v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex443, std::array<u64,3>{v_c20, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex444, std::array<u64,3>{v_c6, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex445, std::array<u64,3>{v_c6, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x41x0x0x0index446, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m523) {
              u64 v_c21 = m523[2]; u64 v_c49 = m523[3];
              if (!slog::exists_probe<3,2>(appindex447, std::array<u64,3>{v_c20, v_c21, 0})) return;
              if (!slog::exists_probe<3,2>(eval_argsindex448, std::array<u64,3>{v_c21, v_c6, 0})) return;
              slog::join_probe<3,2>(evalindex449, std::array<u64,3>{v_c49, v_c6, 0}, [&](const std::array<u64,3>& m524) {
                u64 v_c48 = m524[2];
                slog::join_probe_old<3,3>(appindex450, appdelta462, std::array<u64,3>{v_c48, v_c20, v_c21}, [&](const std::array<u64,3>& m525) {
                  if (!slog::exists_probe<3,2>(tickindex451, std::array<u64,3>{v_c48, v_c6, 0})) return;
                  slog::join_probe_old<3,2>(eval_argsindex452, eval_argsdelta463, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m526) {
                    u64 v_c50 = m526[2];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex453, std::array<u64,2>{v_c50, 0})) return;
                    slog::join_probe_old<3,2>(tickindex454, tickdelta464, std::array<u64,3>{v_c48, v_c6, 0}, [&](const std::array<u64,3>& m527) {
                      u64 v_c44 = m527[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex455, std::array<u64,2>{v_c44, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex456, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m528) {
                        u64 v_c25 = m528[1];
                        slog::join_probe<2,1>(tick_ansindex457, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m529) {
                          u64 v_c1 = m529[1];
                          if (!slog::exists_probe<3,1>(evalindex458, std::array<u64,3>{v_c1, 0, 0})) return;
                          slog::join_probe<3,1>(lambdaindex459, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m530) {
                            u64 v_c26 = m530[1]; u64 v_c27 = m530[2];
                            slog::join_probe_old<3,2>(evalindex460, evaldelta465, std::array<u64,3>{v_c27, v_c1, 0}, [&](const std::array<u64,3>& m531) {
                              u64 v_c42 = m531[2];
                              slog::join_probe<2,1>(eval_ansindex461, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m532) {
                                u64 v_c43 = m532[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask466* _cont = new ReadTask466(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask466(db,b), false);
  // (crule (pre) (scan temp4IsT993 __t2Wlm108 __t97gC109) (body) (head (emit lst_take_ans (0 1) __t97gC109 __t2Wlm108)) list.slog:29 #f)
  class ReadTask533 : public slog::Task
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
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("lst_take_ans");
      head_index[0] = readrel535->getIndex(ord534, false);
      outer_rel = db->getRelation("temp4IsT993");
  
    }
    ReadTask533(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c68 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c68, v_c67}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:temp4IsT993", _fires);
  
      if (!_done)
      {
        ReadTask533* _cont = new ReadTask533(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask533(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst12zL90 conste6c67f7247161354cd7e1d34) (let __tconst7Sjr89 constac8d8342bbb2362d13f0a559) (let __tconst4c9Y88 constc100f95c1913f9c72fc1f4ef) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3hti67 const7297d2085ea0adffc396d546) (let __tconst864965 const4a44dc15364204a80fe80e90) (let __tconst2skc63 constf5ca38f748a1d6eaf726b8a4) (let __tconst3NP861 const609d51837c7fc306b0cbb04a) (let __tconst6C1f52 const53a56174f3826669a422fc54) (let __tconst4wKk50 const6b86b273ff34fce19d6b804e) (let __tconst7EjY48 constd4735e3a265e16eee03f5971) (let __tconst65HW45 const06abaa100ecef791ce028c56)) (scan temp1yL5954 __t8u9k91) (body (exists ref (1 0) 1 __tconst4uoq76) (exists ref (1 0) 1 __tconst65HW45) (exists num (1 0) 1 __tconst7EjY48) (exists num (1 0) 1 __tconst4wKk50) (exists ref (1 0) 1 __tconst6C1f52) (exists ref (1 0) 1 __tconst6GmF96) (exists num (1 0) 1 __tconst2skc63) (exists num (1 0) 1 __tconst864965) (exists ref (1 0) 1 __tconst3hti67) (exists ref (1 0) 1 __tconst4c9Y88) (exists ref (1 0) 1 __tconst7Sjr89) (exists ref (1 0) 1 __tconst12zL90) (join ref (1 0) 1 __tconst3NP861 __t1gk939) (join ref (1 0) 1 __tconst4uoq76 __t0zwc41) (join ref (1 0) 1 __tconst65HW45 __t2luW46) (join num (1 0) 1 __tconst7EjY48 __t61C349) (join num (1 0) 1 __tconst4wKk50 __t3xjv51) (join ref (1 0) 1 __tconst6C1f52 __t1C8J53) (join ref (1 0) 1 __tconst6GmF96 __t8XG759) (join num (1 0) 1 __tconst2skc63 __t23M464) (join num (1 0) 1 __tconst864965 __t4oij66) (join ref (1 0) 1 __tconst3hti67 __t87Tf68) (join ref (1 0) 1 __tconst4c9Y88 __t3e8l79) (join ref (1 0) 1 __tconst7Sjr89 __t2GL381) (join ref (1 0) 1 __tconst12zL90 __t4l0k86) (let __t6K0I92 (lpush __t8u9k91 __tconst12zL90)) (let __t1uIM83 (lpush __t8u9k91 __t2GL381)) (let __t5hQI70 (lpush __t8u9k91 __t87Tf68)) (let __t0g3l55 (lpush __t8u9k91 __t1C8J53)) (let __t3MC543 (lpush __t8u9k91 __t0zwc41))) (head (emit-temp temp5rra955 __t0g3l55 __t1uIM83 __t3MC543 __t5hQI70 __t6K0I92)) schemecfa.slog:39 #f)
  class ReadTask561 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex536;  slog::Index** refindex537;  slog::Index** numindex538;  slog::Index** numindex539;  slog::Index** refindex540;  slog::Index** refindex541;  slog::Index** numindex542;  slog::Index** numindex543;  slog::Index** refindex544;  slog::Index** refindex545;  slog::Index** refindex546;  slog::Index** refindex547;  slog::Index** refindex548;  slog::Index** refindex549;  slog::Index** refindex550;  slog::Index** numindex551;  slog::Index** numindex552;  slog::Index** refindex553;  slog::Index** refindex554;  slog::Index** numindex555;  slog::Index** numindex556;  slog::Index** refindex557;  slog::Index** refindex558;  slog::Index** refindex559;  slog::Index** refindex560;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5rra955");
      outer_rel = db->getRelation("temp1yL5954");
      std::vector<u16> ord562({1, 0});
      slog::Relation* readrel563 = db->getRelation("ref");
      refindex536 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 0});
      slog::Relation* readrel565 = db->getRelation("ref");
      refindex537 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0});
      slog::Relation* readrel567 = db->getRelation("num");
      numindex538 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0});
      slog::Relation* readrel569 = db->getRelation("num");
      numindex539 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("ref");
      refindex540 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("ref");
      refindex541 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("num");
      numindex542 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("num");
      numindex543 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 0});
      slog::Relation* readrel579 = db->getRelation("ref");
      refindex544 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 0});
      slog::Relation* readrel581 = db->getRelation("ref");
      refindex545 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 0});
      slog::Relation* readrel583 = db->getRelation("ref");
      refindex546 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 0});
      slog::Relation* readrel585 = db->getRelation("ref");
      refindex547 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({1, 0});
      slog::Relation* readrel587 = db->getRelation("ref");
      refindex548 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 0});
      slog::Relation* readrel589 = db->getRelation("ref");
      refindex549 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 0});
      slog::Relation* readrel591 = db->getRelation("ref");
      refindex550 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 0});
      slog::Relation* readrel593 = db->getRelation("num");
      numindex551 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("num");
      numindex552 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 0});
      slog::Relation* readrel597 = db->getRelation("ref");
      refindex553 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 0});
      slog::Relation* readrel599 = db->getRelation("ref");
      refindex554 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 0});
      slog::Relation* readrel601 = db->getRelation("num");
      numindex555 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 0});
      slog::Relation* readrel603 = db->getRelation("num");
      numindex556 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 0});
      slog::Relation* readrel605 = db->getRelation("ref");
      refindex557 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("ref");
      refindex558 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 0});
      slog::Relation* readrel609 = db->getRelation("ref");
      refindex559 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 0});
      slog::Relation* readrel611 = db->getRelation("ref");
      refindex560 = readrel611->getIndex(ord610, false);
  
    }
    ReadTask561(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c69 = v_conste6c67f7247161354cd7e1d34;
      u64 v_c70 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c71 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c52 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c72 = v_const7297d2085ea0adffc396d546;
      u64 v_c73 = v_const4a44dc15364204a80fe80e90;
      u64 v_c74 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_const609d51837c7fc306b0cbb04a;
      u64 v_c75 = v_const53a56174f3826669a422fc54;
      u64 v_c76 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c79 = _t[0];
        if (!slog::exists_probe<2,1>(refindex536, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<2,1>(refindex537, std::array<u64,2>{v_c78, 0})) return;
        if (!slog::exists_probe<2,1>(numindex538, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<2,1>(numindex539, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<2,1>(refindex540, std::array<u64,2>{v_c75, 0})) return;
        if (!slog::exists_probe<2,1>(refindex541, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<2,1>(numindex542, std::array<u64,2>{v_c74, 0})) return;
        if (!slog::exists_probe<2,1>(numindex543, std::array<u64,2>{v_c73, 0})) return;
        if (!slog::exists_probe<2,1>(refindex544, std::array<u64,2>{v_c72, 0})) return;
        if (!slog::exists_probe<2,1>(refindex545, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<2,1>(refindex546, std::array<u64,2>{v_c70, 0})) return;
        if (!slog::exists_probe<2,1>(refindex547, std::array<u64,2>{v_c69, 0})) return;
        slog::join_probe<2,1>(refindex548, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m612) {
          u64 v_c80 = m612[1];
          slog::join_probe<2,1>(refindex549, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m613) {
            u64 v_c81 = m613[1];
            slog::join_probe<2,1>(refindex550, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m614) {
              u64 v_c82 = m614[1];
              slog::join_probe<2,1>(numindex551, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m615) {
                u64 v_c83 = m615[1];
                slog::join_probe<2,1>(numindex552, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m616) {
                  u64 v_c84 = m616[1];
                  slog::join_probe<2,1>(refindex553, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m617) {
                    u64 v_c85 = m617[1];
                    slog::join_probe<2,1>(refindex554, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m618) {
                      u64 v_c86 = m618[1];
                      slog::join_probe<2,1>(numindex555, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m619) {
                        u64 v_c87 = m619[1];
                        slog::join_probe<2,1>(numindex556, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m620) {
                          u64 v_c88 = m620[1];
                          slog::join_probe<2,1>(refindex557, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m621) {
                            u64 v_c89 = m621[1];
                            slog::join_probe<2,1>(refindex558, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m622) {
                              u64 v_c90 = m622[1];
                              slog::join_probe<2,1>(refindex559, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m623) {
                                u64 v_c91 = m623[1];
                                slog::join_probe<2,1>(refindex560, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m624) {
                                  u64 v_c92 = m624[1];
                                  u64 v_c93 = _prim_lpush(db, v_c79, v_c69);
                                  if (v_c93 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                                  u64 v_c94 = _prim_lpush(db, v_c79, v_c91);
                                  if (v_c94 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                                  u64 v_c95 = _prim_lpush(db, v_c79, v_c89);
                                  if (v_c95 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                                  u64 v_c96 = _prim_lpush(db, v_c79, v_c85);
                                  if (v_c96 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                                  u64 v_c97 = _prim_lpush(db, v_c79, v_c81);
                                  if (v_c97 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                                  ++_fires;
                                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c96, v_c94, v_c97, v_c95, v_c93});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp1yL5954", _fires);
  
      if (!_done)
      {
        ReadTask561* _cont = new ReadTask561(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask561(db,b), false);
  // (crule (pre) (scan eval __t1YLG237 __t17FH236 c) (body (join let (0 2 1 3) 1 __t17FH236 er x eb)) (head (emit $sup56712x91x0x0x0 (0 1 2 3 4) __t1YLG237 c eb er x)) interp.slog:92 #f)
  class ReadTask626 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex625;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord627({0, 1, 2, 3, 4});
      slog::Relation* readrel628 = db->getRelation("$sup56712x91x0x0x0");
      head_index[0] = readrel628->getIndex(ord627, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord629({0, 2, 1, 3});
      slog::Relation* readrel630 = db->getRelation("let");
      letindex625 = readrel630->getIndex(ord629, false);
  
    }
    ReadTask626(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c98 = _t[0];
        u64 v_c99 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<4,1>(letindex625, std::array<u64,4>{v_c99, 0, 0, 0}, [&](const std::array<u64,4>& m631) {
          u64 v_c61 = m631[1]; u64 v_c15 = m631[2]; u64 v_c27 = m631[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c98, v_c6, v_c27, v_c61, v_c15}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask626* _cont = new ReadTask626(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask626(db,b), false);
  // (crule (pre) (scan lambda __t2BTJ197 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t2BTJ197 cb __t4ROj198) (join eval_ans (1 0) 1 __t4ROj198 __t44Jo196) (join eval (0 2 1) 1 __t44Jo196 c ef) (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join tick_ans (0 1) 1 __t3z31201 __v0)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask651 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex632;  slog::Index** eval_ansindex633;  slog::Index** evalindex634;  slog::Index** eval_argsindex635;  slog::Index** appindex636;  slog::Index** tickindex637;  slog::Index** $sup56712x41x0x0x0index638;  slog::Index** appindex639;  slog::Index** eval_argsindex640;  slog::Index** eval_args_ansindex641;  slog::Index** appindex642;  slog::Index** tickindex643;  slog::Index** tick_ansindex644;  slog::Index** eval_args_ansindex645;  slog::Index** tick_ansindex646;  slog::Index** closuredelta647;  slog::Index** eval_argsdelta648;  slog::Index** appdelta649;  slog::Index** tickdelta650;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("closure");
      closureindex632 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("closure");
      closuredelta647 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 0});
      slog::Relation* readrel657 = db->getRelation("eval_ans");
      eval_ansindex633 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 2, 1});
      slog::Relation* readrel659 = db->getRelation("eval");
      evalindex634 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({2, 0, 1});
      slog::Relation* readrel661 = db->getRelation("eval_args");
      eval_argsindex635 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("app");
      appindex636 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({2, 0, 1});
      slog::Relation* readrel665 = db->getRelation("tick");
      tickindex637 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 3, 0});
      slog::Relation* readrel667 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index638 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("app");
      appindex639 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 2, 0});
      slog::Relation* readrel671 = db->getRelation("eval_args");
      eval_argsindex640 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("eval_args");
      eval_argsdelta648 = readrel673->getIndex(ord672, true);
      std::vector<u16> ord674({0, 1});
      slog::Relation* readrel675 = db->getRelation("eval_args_ans");
      eval_args_ansindex641 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 0});
      slog::Relation* readrel677 = db->getRelation("app");
      appindex642 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("app");
      appdelta649 = readrel679->getIndex(ord678, true);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("tick");
      tickindex643 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("tick");
      tickdelta650 = readrel683->getIndex(ord682, true);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("tick_ans");
      tick_ansindex644 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_args_ans");
      eval_args_ansindex645 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("tick_ans");
      tick_ansindex646 = readrel689->getIndex(ord688, false);
  
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
        u64 v_c17 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c27 = _t[2];
        slog::join_probe_old<3,1>(closureindex632, closuredelta647, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m690) {
          u64 v_c18 = m690[1]; u64 v_c16 = m690[2];
          slog::join_probe<2,1>(eval_ansindex633, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m691) {
            u64 v_c19 = m691[1];
            slog::join_probe<3,1>(evalindex634, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m692) {
              u64 v_c6 = m692[1]; u64 v_c20 = m692[2];
              if (!slog::exists_probe<3,1>(eval_argsindex635, std::array<u64,3>{v_c6, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex636, std::array<u64,3>{v_c20, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex637, std::array<u64,3>{v_c6, 0, 0})) return;
              slog::join_probe<4,2>($sup56712x41x0x0x0index638, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m693) {
                u64 v_c21 = m693[2]; u64 v_c5 = m693[3];
                if (!slog::exists_probe<3,2>(appindex639, std::array<u64,3>{v_c20, v_c21, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex640, eval_argsdelta648, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m694) {
                  u64 v_c22 = m694[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex641, std::array<u64,2>{v_c22, 0})) return;
                  slog::join_probe_old<3,2>(appindex642, appdelta649, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m695) {
                    u64 v_c23 = m695[2];
                    slog::join_probe_old<3,2>(tickindex643, tickdelta650, std::array<u64,3>{v_c23, v_c6, 0}, [&](const std::array<u64,3>& m696) {
                      u64 v_c24 = m696[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex644, std::array<u64,2>{v_c24, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex645, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m697) {
                        u64 v_c25 = m697[1];
                        slog::join_probe<2,1>(tick_ansindex646, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m698) {
                          u64 v_c1 = m698[1];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c1}, std::array<u16,3>{1, 2, 0});
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
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp8yir1053 __t0O3R266 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289) (body (join ref (1 0) 1 __tconst4G37291 __t8oYB253)) (head (emit-temp temp5oZM1054 __t0O3R266 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289) (mkstruct app (1 2 0) __t8IFs269 __t8oYB253 __t0O3R266)) schemecfa.slog:70 #f)
  class ReadTask700 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex699;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5oZM1054");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp8yir1053");
      std::vector<u16> ord701({1, 0});
      slog::Relation* readrel702 = db->getRelation("ref");
      refindex699 = readrel702->getIndex(ord701, false);
  
    }
    ReadTask700(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const889c19fd926bc4ca61c0b4d9;
  
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
        u64 v_c102 = _t[1];
        u64 v_c103 = _t[2];
        u64 v_c104 = _t[3];
        u64 v_c105 = _t[4];
        slog::join_probe<2,1>(refindex699, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m703) {
          u64 v_c106 = m703[1];
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c101, v_c102, v_c103, v_c104, v_c105});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c106, v_c101}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp8yir1053", _fires);
  
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
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo0AcC516 __t59ft158 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo3TKl513 __t59ft158 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo2IHZ514 __t59ft158 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo1Kdp515 __t59ft158 _00024seq2) (join delta (1 2 0) 2 __tconst3bSs155 _00024seq2 __t2lyA156) (join closure (0 1 2) 1 __t59ft158 lm cb) (join any_bool (0) 0 b) (letp _00024sql2qfO508 (aslst _00024seq2)) (let chk4b3P1143 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk4b3P1143) (letp chk6smD1144 (lref _00024sql2qfO508 _00024sqc65nX511)) (eq __t59ft158 chk6smD1144) (letp chk4mTL1145 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk4mTL1145)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask710 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex704;  slog::Index** $seq_atindex705;  slog::Index** $seq_atrindex706;  slog::Index** deltaindex707;  slog::Index** closureindex708;  slog::Index** any_boolindex709;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord711({1, 0, 2});
      slog::Relation* readrel712 = db->getRelation("$seq_atr");
      driver_index = readrel712->getIndex(ord711, true);
      std::vector<u16> ord713({1, 0, 2});
      slog::Relation* readrel714 = db->getRelation("$seq_at");
      $seq_atindex704 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 0, 2});
      slog::Relation* readrel716 = db->getRelation("$seq_at");
      $seq_atindex705 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 0, 2});
      slog::Relation* readrel718 = db->getRelation("$seq_atr");
      $seq_atrindex706 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 0});
      slog::Relation* readrel720 = db->getRelation("delta");
      deltaindex707 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({0, 1, 2});
      slog::Relation* readrel722 = db->getRelation("closure");
      closureindex708 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({0});
      slog::Relation* readrel724 = db->getRelation("any_bool");
      any_boolindex709 = readrel724->getIndex(ord723, false);
  
    }
    ReadTask710(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const06abaa100ecef791ce028c56;
      u64 v_c108 = v_constd4735e3a265e16eee03f5971;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c114, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m725) {
        u64 v_c115 = m725[1];
        u64 v_c116 = m725[2];
        if (buckethash(v_c115) != bucket) return;
        slog::join_probe<3,3>($seq_atindex704, std::array<u64,3>{v_c111, v_c115, v_c116}, [&](const std::array<u64,3>& m726) {
          slog::join_probe<3,3>($seq_atindex705, std::array<u64,3>{v_c112, v_c115, v_c116}, [&](const std::array<u64,3>& m727) {
            slog::join_probe<3,3>($seq_atrindex706, std::array<u64,3>{v_c113, v_c115, v_c116}, [&](const std::array<u64,3>& m728) {
              slog::join_probe<3,2>(deltaindex707, std::array<u64,3>{v_c107, v_c116, 0}, [&](const std::array<u64,3>& m729) {
                u64 v_c117 = m729[2];
                slog::join_probe<3,1>(closureindex708, std::array<u64,3>{v_c115, 0, 0}, [&](const std::array<u64,3>& m730) {
                  u64 v_c118 = m730[1]; u64 v_c18 = m730[2];
                  slog::join_all<1>(any_boolindex709, [&](const std::array<u64,1>& m731) {
                    u64 v_c119 = m731[0];
                    bool ok732 = true;
                    u64 v_c120 = _prim_aslst(db, v_c116, &ok732);
                    if (!ok732) return;
                    u64 v_c121 = _prim_llen(db, v_c120);
                    if (v_c121 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c108 != v_c121) return;
                    bool ok733 = true;
                    u64 v_c122 = _prim_lref(db, v_c120, v_c109, &ok733);
                    if (!ok733) return;
                    if (v_c115 != v_c122) return;
                    bool ok734 = true;
                    u64 v_c123 = _prim_lref(db, v_c120, v_c110, &ok734);
                    if (!ok734) return;
                    if (v_c115 != v_c123) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c117, v_c119});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c119}, std::array<u16,2>{1, 0});
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
        ReadTask710* _cont = new ReadTask710(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask710(db,b), false);
  // (crule (pre) (scan eval __t8a3x503 __t8eby502 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (0 1 2 3) 2 __t8a3x503 c ef es) (join app (0 1 2) 3 __t8eby502 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3A6m504) (exists eval_ans (0 1) 1 __t3A6m504) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (exists eval_args_ans (0 1) 1 __t60iG506) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join eval_args_ans (0 1) 1 __t60iG506 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask754 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex735;  slog::Index** eval_argsindex736;  slog::Index** $sup56712x74x0x0x0index737;  slog::Index** appindex738;  slog::Index** eval_argsindex739;  slog::Index** evalindex740;  slog::Index** eval_ansindex741;  slog::Index** eval_argsindex742;  slog::Index** eval_args_ansindex743;  slog::Index** eval_ansindex744;  slog::Index** eval_args_ansindex745;  slog::Index** deltaindex746;  slog::Index** primindex747;  slog::Index** deltaindex748;  slog::Index** delta_ansindex749;  slog::Index** evaldelta750;  slog::Index** eval_argsdelta751;  slog::Index** primdelta752;  slog::Index** deltadelta753;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord755({0, 1});
      slog::Relation* readrel756 = db->getRelation("eval_ans");
      head_index[0] = readrel756->getIndex(ord755, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord757({2, 0, 1});
      slog::Relation* readrel758 = db->getRelation("eval");
      evalindex735 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({2, 0, 1});
      slog::Relation* readrel760 = db->getRelation("eval_args");
      eval_argsindex736 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({0, 1, 2, 3});
      slog::Relation* readrel762 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index737 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({0, 1, 2});
      slog::Relation* readrel764 = db->getRelation("app");
      appindex738 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 2, 0});
      slog::Relation* readrel766 = db->getRelation("eval_args");
      eval_argsindex739 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 2, 0});
      slog::Relation* readrel768 = db->getRelation("eval");
      evalindex740 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("eval");
      evaldelta750 = readrel770->getIndex(ord769, true);
      std::vector<u16> ord771({0, 1});
      slog::Relation* readrel772 = db->getRelation("eval_ans");
      eval_ansindex741 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("eval_args");
      eval_argsindex742 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 0});
      slog::Relation* readrel776 = db->getRelation("eval_args");
      eval_argsdelta751 = readrel776->getIndex(ord775, true);
      std::vector<u16> ord777({0, 1});
      slog::Relation* readrel778 = db->getRelation("eval_args_ans");
      eval_args_ansindex743 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({0, 1});
      slog::Relation* readrel780 = db->getRelation("eval_ans");
      eval_ansindex744 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 1});
      slog::Relation* readrel782 = db->getRelation("eval_args_ans");
      eval_args_ansindex745 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({2, 0, 1});
      slog::Relation* readrel784 = db->getRelation("delta");
      deltaindex746 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("prim");
      primindex747 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({0, 1});
      slog::Relation* readrel788 = db->getRelation("prim");
      primdelta752 = readrel788->getIndex(ord787, true);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("delta");
      deltaindex748 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("delta");
      deltadelta753 = readrel792->getIndex(ord791, true);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("delta_ans");
      delta_ansindex749 = readrel794->getIndex(ord793, false);
  
    }
    ReadTask754(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex735, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex736, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index737, std::array<u64,4>{v_c124, v_c6, 0, 0}, [&](const std::array<u64,4>& m795) {
          u64 v_c20 = m795[2]; u64 v_c21 = m795[3];
          slog::join_probe<3,3>(appindex738, std::array<u64,3>{v_c125, v_c20, v_c21}, [&](const std::array<u64,3>& m796) {
            if (!slog::exists_probe<3,2>(eval_argsindex739, std::array<u64,3>{v_c21, v_c6, 0})) return;
            slog::join_probe_old<3,2>(evalindex740, evaldelta750, std::array<u64,3>{v_c20, v_c6, 0}, [&](const std::array<u64,3>& m797) {
              u64 v_c126 = m797[2];
              if (!slog::exists_probe<2,1>(eval_ansindex741, std::array<u64,2>{v_c126, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex742, eval_argsdelta751, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m798) {
                u64 v_c127 = m798[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex743, std::array<u64,2>{v_c127, 0})) return;
                slog::join_probe<2,1>(eval_ansindex744, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m799) {
                  u64 v_c128 = m799[1];
                  slog::join_probe<2,1>(eval_args_ansindex745, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m800) {
                    u64 v_c25 = m800[1];
                    if (!slog::exists_probe<3,1>(deltaindex746, std::array<u64,3>{v_c25, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex747, primdelta752, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m801) {
                      u64 v_c30 = m801[1];
                      slog::join_probe_old<3,2>(deltaindex748, deltadelta753, std::array<u64,3>{v_c30, v_c25, 0}, [&](const std::array<u64,3>& m802) {
                        u64 v_c129 = m802[2];
                        slog::join_probe<2,1>(delta_ansindex749, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m803) {
                          u64 v_c43 = m803[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c124, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask754* _cont = new ReadTask754(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask754(db,b), false);
  // (crule (pre) (scan eval __t60Dg116 __t0hKJ115 c) (body (join letrec (0 2 1 3) 1 __t0hKJ115 er x eb)) (head (emit $sup56712x93x0x0x0 (0 1 2 3 4) __t60Dg116 c eb er x)) interp.slog:94 #f)
  class ReadTask805 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex804;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord806({0, 1, 2, 3, 4});
      slog::Relation* readrel807 = db->getRelation("$sup56712x93x0x0x0");
      head_index[0] = readrel807->getIndex(ord806, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord808({0, 2, 1, 3});
      slog::Relation* readrel809 = db->getRelation("letrec");
      letrecindex804 = readrel809->getIndex(ord808, false);
  
    }
    ReadTask805(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c131 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<4,1>(letrecindex804, std::array<u64,4>{v_c131, 0, 0, 0}, [&](const std::array<u64,4>& m810) {
          u64 v_c61 = m810[1]; u64 v_c15 = m810[2]; u64 v_c27 = m810[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c130, v_c6, v_c27, v_c61, v_c15}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
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
  // (crule (pre (let _00024sqc7mfe625 const6b86b273ff34fce19d6b804e) (let _00024sqc6vjh626 const5feceb66ffc86f38d952786c) (let _00024sqc8B9m627 const6b86b273ff34fce19d6b804e) (let _00024sqc6Ku4628 const5feceb66ffc86f38d952786c) (let _00024sqc6PTs635 const6b86b273ff34fce19d6b804e) (let _00024sqc8L1M636 const5feceb66ffc86f38d952786c) (let _00024sqc4SMj637 const6b86b273ff34fce19d6b804e) (let _00024sqc91NV638 const5feceb66ffc86f38d952786c) (let __trid1gZn752 const99565d312ddf7c579dcfd67c) (let __trel2YOC753 const65c80aac3433a01ef8a7f298) (let __tcol0ZMO754 const5feceb66ffc86f38d952786c) (let __trel1CM7755 const913be61629bf526ec23a58e7) (let __tcol4ETR756 const5feceb66ffc86f38d952786c) (let __trel6dqT757 const913be61629bf526ec23a58e7) (let __tcol9kwv758 constd4735e3a265e16eee03f5971)) (scan bind_params _00024seq0 _00024seq1 l c) (body (letp _00024sql894W623 (aslst _00024seq1)) (let _00024sqn60MZ624 (llen _00024sql894W623)) (cmp ge _00024sqn60MZ624 _00024sqc7mfe625) (letp _00024sql9gxL633 (aslst _00024seq0)) (let _00024sqn6pSh634 (llen _00024sql9gxL633)) (cmp ge _00024sqn6pSh634 _00024sqc6PTs635) (letp v (lref _00024sql894W623 _00024sqc6vjh626)) (let _00024sqp78Rl629 (_0002d _00024sqn60MZ624 _00024sqc6Ku4628)) (let vs (lslice _00024sql894W623 _00024sqc8B9m627 _00024sqp78Rl629)) (letp x (lref _00024sql9gxL633 _00024sqc8L1M636)) (let _00024sqp3c0u639 (_0002d _00024sqn6pSh634 _00024sqc91NV638)) (let xs (lslice _00024sql9gxL633 _00024sqc4SMj637 _00024sqp3c0u639))) (head (tycheck x (accept str) __trid1gZn752 __trel2YOC753 __tcol0ZMO754 (1 2 3 4 0)) (tycheck x (accept str) __trid1gZn752 __trel1CM7755 __tcol4ETR756 (1 2 3 4 0)) (tycheck v (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid1gZn752 __trel6dqT757 __tcol9kwv758 (1 2 3 4 0)) (emit bind_params (0 1 2 3) xs vs l c) (emit binding_event (0 1 2) x l c) (emit binding (0 1 2) x l v)) interp.slog:67 #f)
  class ReadTask816 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid813;  u32 sid811;  u32 sid812;  u32 sid814;  u32 sid815;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("bind_params");
      std::vector<u16> ord817({0, 1, 2, 3});
      slog::Relation* readrel818 = db->getRelation("bind_params");
      head_index[3] = readrel818->getIndex(ord817, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord819({0, 1, 2});
      slog::Relation* readrel820 = db->getRelation("binding_event");
      head_index[4] = readrel820->getIndex(ord819, false);
      head_rel[5] = db->getRelation("binding");
      std::vector<u16> ord821({0, 1, 2});
      slog::Relation* readrel822 = db->getRelation("binding");
      head_index[5] = readrel822->getIndex(ord821, false);
      outer_rel = db->getRelation("bind_params");
      sid813 = db->getRelation("_enum")->getStructId();
      sid811 = db->getRelation("boolval")->getStructId();
      sid812 = db->getRelation("closure")->getStructId();
      sid814 = db->getRelation("prim")->getStructId();
      sid815 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask816(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c133 = v_const5feceb66ffc86f38d952786c;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const99565d312ddf7c579dcfd67c;
      u64 v_c141 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c142 = v_const5feceb66ffc86f38d952786c;
      u64 v_c143 = v_const913be61629bf526ec23a58e7;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_const913be61629bf526ec23a58e7;
      u64 v_c146 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c147 = _t[0];
        u64 v_c148 = _t[1];
        u64 v_c149 = _t[2];
        u64 v_c6 = _t[3];
        bool ok823 = true;
        u64 v_c150 = _prim_aslst(db, v_c148, &ok823);
        if (!ok823) return;
        u64 v_c151 = _prim_llen(db, v_c150);
        if (v_c151 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c152 = _prim_ge(db, v_c151, v_c132);
        if (v_c152 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        if (!v_c152) return;
        bool ok825 = true;
        u64 v_c153 = _prim_aslst(db, v_c147, &ok825);
        if (!ok825) return;
        u64 v_c154 = _prim_llen(db, v_c153);
        if (v_c154 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c155 = _prim_ge(db, v_c154, v_c136);
        if (v_c155 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        if (!v_c155) return;
        bool ok827 = true;
        u64 v_c43 = _prim_lref(db, v_c150, v_c133, &ok827);
        if (!ok827) return;
        u64 v_c156 = _prim__0002d(db, v_c151, v_c135);
        if (v_c156 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c25 = _prim_lslice(db, v_c150, v_c134, v_c156);
        if (v_c25 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        bool ok828 = true;
        u64 v_c15 = _prim_lref(db, v_c153, v_c137, &ok828);
        if (!ok828) return;
        u64 v_c157 = _prim__0002d(db, v_c154, v_c139);
        if (v_c157 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        u64 v_c26 = _prim_lslice(db, v_c153, v_c138, v_c157);
        if (v_c26 == slog_error) { slog::emit_pending_error(db, "interp.slog:67"); return; }
        ++_fires;
        if (!(is_str(v_c15)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c140, v_c141, v_c142, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c15)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c140, v_c143, v_c144, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c43) && (decode_struct_id(v_c43) == sid811 || decode_struct_id(v_c43) == sid812 || decode_struct_id(v_c43) == sid813 || decode_struct_id(v_c43) == sid814 || decode_struct_id(v_c43) == sid815))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c140, v_c145, v_c146, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit<4>(head_rel[3], head_index[3], newbatch[3], std::array<u64,4>{v_c26, v_c25, v_c149, v_c6}, std::array<u16,4>{0, 1, 2, 3});
        slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c15, v_c149, v_c6}, std::array<u16,3>{0, 1, 2});
        slog::emit<3>(head_rel[5], head_index[5], newbatch[5], std::array<u64,3>{v_c15, v_c149, v_c43}, std::array<u16,3>{0, 1, 2});
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
        ReadTask816* _cont = new ReadTask816(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask816(db,b), false);
  // (crule (pre (let __tconst7oTo733 constb9e118781cea1f9fa01462e0) (let __tconst23AG380 const60e3114d9b4b6577eea8cbc0) (let _00024sqc7zL5538 const6b86b273ff34fce19d6b804e) (let _00024sqc0b5k539 const5feceb66ffc86f38d952786c) (let _00024sqo0tFP540 const5feceb66ffc86f38d952786c) (let _00024sqo2KLy541 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2KLy541 v _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo0tFP540 v _00024seq0) (exists _enum (1 0) 1 __tconst7oTo733) (join delta (1 2 0) 2 __tconst23AG380 _00024seq0 __t7rOF381) (join _enum (1 0) 1 __tconst7oTo733 __t1FRr378) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql6Yee536 (aslst _00024seq0)) (let chk2KX81001 (llen _00024sql6Yee536)) (eq _00024sqc7zL5538 chk2KX81001) (letp chk1rQy1002 (lref _00024sql6Yee536 _00024sqc0b5k539)) (eq v chk1rQy1002)) (head (emit-temp temp0LTu995 __t7rOF381) (mkstruct boolval (1 0) __t7RmO379 __t1FRr378)) interp.slog:114 #f)
  class ReadTask834 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex829;  slog::Index** _enumindex830;  slog::Index** deltaindex831;  slog::Index** _enumindex832;  slog::Index** scheme_falseindex833;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LTu995");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord835({1, 0, 2});
      slog::Relation* readrel836 = db->getRelation("$seq_atr");
      driver_index = readrel836->getIndex(ord835, true);
      std::vector<u16> ord837({1, 0, 2});
      slog::Relation* readrel838 = db->getRelation("$seq_at");
      $seq_atindex829 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 0});
      slog::Relation* readrel840 = db->getRelation("_enum");
      _enumindex830 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 2, 0});
      slog::Relation* readrel842 = db->getRelation("delta");
      deltaindex831 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 0});
      slog::Relation* readrel844 = db->getRelation("_enum");
      _enumindex832 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({0});
      slog::Relation* readrel846 = db->getRelation("scheme_false");
      scheme_falseindex833 = readrel846->getIndex(ord845, false);
  
    }
    ReadTask834(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c158 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c159 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c160 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c161 = v_const5feceb66ffc86f38d952786c;
      u64 v_c162 = v_const5feceb66ffc86f38d952786c;
      u64 v_c163 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c163, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m847) {
        u64 v_c43 = m847[1];
        u64 v_c147 = m847[2];
        if (buckethash(v_c43) != bucket) return;
        slog::join_probe<3,3>($seq_atindex829, std::array<u64,3>{v_c162, v_c43, v_c147}, [&](const std::array<u64,3>& m848) {
          if (!slog::exists_probe<2,1>(_enumindex830, std::array<u64,2>{v_c158, 0})) return;
          slog::join_probe<3,2>(deltaindex831, std::array<u64,3>{v_c159, v_c147, 0}, [&](const std::array<u64,3>& m849) {
            u64 v_c164 = m849[2];
            slog::join_probe<2,1>(_enumindex832, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m850) {
              u64 v_c165 = m850[1];
              slog::join_all<1>(scheme_falseindex833, [&](const std::array<u64,1>& m851) {
                u64 v_c166 = m851[0];
                if (v_c43 == v_c166) return;
                bool ok852 = true;
                u64 v_c167 = _prim_aslst(db, v_c147, &ok852);
                if (!ok852) return;
                u64 v_c168 = _prim_llen(db, v_c167);
                if (v_c168 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c160 != v_c168) return;
                bool ok853 = true;
                u64 v_c169 = _prim_lref(db, v_c167, v_c161, &ok853);
                if (!ok853) return;
                if (v_c43 != v_c169) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c164});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c165}, std::array<u16,2>{1, 0});
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
        ReadTask834* _cont = new ReadTask834(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask834(db,b), false);
  // (crule (pre (let __tconst9sKD800 constb9e118781cea1f9fa01462e0)) (seeded) (body (join _enum (1 0) 1 __tconst9sKD800 __t4akT382) (join boolval (1 0) 1 __t4akT382 __t7ocu383)) (head (emit scheme_false (0) __t7ocu383)) interp.slog:81 #f)
  class ReadTask856 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex854;  slog::Index** boolvalindex855;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord857({0});
      slog::Relation* readrel858 = db->getRelation("scheme_false");
      head_index[0] = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 0});
      slog::Relation* readrel860 = db->getRelation("_enum");
      _enumindex854 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 0});
      slog::Relation* readrel862 = db->getRelation("boolval");
      boolvalindex855 = readrel862->getIndex(ord861, false);
  
    }
    ReadTask856(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex854, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m863) {
        u64 v_c171 = m863[1];
        slog::join_probe<2,1>(boolvalindex855, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m864) {
          u64 v_c172 = m864[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c172}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask856(db,b));
  // (crule (pre) (scan temp9b5k981 __t0SDA445 __t2W25447 __v1) (body (let __t6A6H446 (lcat __t0SDA445 __v1))) (head (emit-temp temp3czf982 __t2W25447 __t6A6H446)) interp.slog:38 #f)
  class ReadTask865 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3czf982");
      outer_rel = db->getRelation("temp9b5k981");
  
    }
    ReadTask865(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[2];
        u64 v_c175 = _prim_lcat(db, v_c173, v_c8);
        if (v_c175 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c174, v_c175});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp9b5k981", _fires);
  
      if (!_done)
      {
        ReadTask865* _cont = new ReadTask865(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask865(db,b), false);
  // (crule (pre) (scan temp5zYE1178 __t0raq125 m) (body) (head (mkstruct lst_take (1 2 0) __1Jfw803 __t0raq125 m)) context.slog:10 #f)
  class ReadTask866 : public slog::Task
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
      outer_rel = db->getRelation("temp5zYE1178");
  
    }
    ReadTask866(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c176 = _t[0];
        u64 v_c177 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c176, v_c177}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp5zYE1178", _fires);
  
      if (!_done)
      {
        ReadTask866* _cont = new ReadTask866(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask866(db,b), false);
  // (crule (pre) (scan $sup56712x93x0x0x0 __t5OlD294 c eb er x) (body (exists eval (0 2 1) 2 __t5OlD294 c) (exists eval (1 2 0) 2 er c) (exists eval (1 2 0) 2 eb c) (join-old letrec (2 1 3 0) 3 (2 1 3 0) er x eb __t0H7q293) (join-old eval (0 2 1) 3 (0 2 1) __t5OlD294 c __t0H7q293) (join-old eval (1 2 0) 2 (1 2 0) er c __t9p2a295) (exists eval_ans (0 1) 1 __t9p2a295) (join-old eval (1 2 0) 2 (1 2 0) eb c __t32yp296) (exists eval_ans (0 1) 1 __t32yp296) (join eval_ans (0 1) 1 __t9p2a295 vr) (join eval_ans (0 1) 1 __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask882 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex867;  slog::Index** evalindex868;  slog::Index** evalindex869;  slog::Index** letrecindex870;  slog::Index** evalindex871;  slog::Index** evalindex872;  slog::Index** eval_ansindex873;  slog::Index** evalindex874;  slog::Index** eval_ansindex875;  slog::Index** eval_ansindex876;  slog::Index** eval_ansindex877;  slog::Index** letrecdelta878;  slog::Index** evaldelta879;  slog::Index** evaldelta880;  slog::Index** evaldelta881;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord883({0, 1});
      slog::Relation* readrel884 = db->getRelation("eval_ans");
      head_index[0] = readrel884->getIndex(ord883, false);
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord885({0, 2, 1});
      slog::Relation* readrel886 = db->getRelation("eval");
      evalindex867 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("eval");
      evalindex868 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("eval");
      evalindex869 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({2, 1, 3, 0});
      slog::Relation* readrel892 = db->getRelation("letrec");
      letrecindex870 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({2, 1, 3, 0});
      slog::Relation* readrel894 = db->getRelation("letrec");
      letrecdelta878 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({0, 2, 1});
      slog::Relation* readrel896 = db->getRelation("eval");
      evalindex871 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 2, 1});
      slog::Relation* readrel898 = db->getRelation("eval");
      evaldelta879 = readrel898->getIndex(ord897, true);
      std::vector<u16> ord899({1, 2, 0});
      slog::Relation* readrel900 = db->getRelation("eval");
      evalindex872 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 2, 0});
      slog::Relation* readrel902 = db->getRelation("eval");
      evaldelta880 = readrel902->getIndex(ord901, true);
      std::vector<u16> ord903({0, 1});
      slog::Relation* readrel904 = db->getRelation("eval_ans");
      eval_ansindex873 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 2, 0});
      slog::Relation* readrel906 = db->getRelation("eval");
      evalindex874 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({1, 2, 0});
      slog::Relation* readrel908 = db->getRelation("eval");
      evaldelta881 = readrel908->getIndex(ord907, true);
      std::vector<u16> ord909({0, 1});
      slog::Relation* readrel910 = db->getRelation("eval_ans");
      eval_ansindex875 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({0, 1});
      slog::Relation* readrel912 = db->getRelation("eval_ans");
      eval_ansindex876 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({0, 1});
      slog::Relation* readrel914 = db->getRelation("eval_ans");
      eval_ansindex877 = readrel914->getIndex(ord913, false);
  
    }
    ReadTask882(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c61 = _t[3];
        u64 v_c15 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex867, std::array<u64,3>{v_c178, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex868, std::array<u64,3>{v_c61, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex869, std::array<u64,3>{v_c27, v_c6, 0})) return;
        slog::join_probe_old<4,3>(letrecindex870, letrecdelta878, std::array<u64,4>{v_c61, v_c15, v_c27, 0}, [&](const std::array<u64,4>& m915) {
          u64 v_c179 = m915[3];
          slog::join_probe_old<3,3>(evalindex871, evaldelta879, std::array<u64,3>{v_c178, v_c6, v_c179}, [&](const std::array<u64,3>& m916) {
            slog::join_probe_old<3,2>(evalindex872, evaldelta880, std::array<u64,3>{v_c61, v_c6, 0}, [&](const std::array<u64,3>& m917) {
              u64 v_c180 = m917[2];
              if (!slog::exists_probe<2,1>(eval_ansindex873, std::array<u64,2>{v_c180, 0})) return;
              slog::join_probe_old<3,2>(evalindex874, evaldelta881, std::array<u64,3>{v_c27, v_c6, 0}, [&](const std::array<u64,3>& m918) {
                u64 v_c181 = m918[2];
                if (!slog::exists_probe<2,1>(eval_ansindex875, std::array<u64,2>{v_c181, 0})) return;
                slog::join_probe<2,1>(eval_ansindex876, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m919) {
                  u64 v_c64 = m919[1];
                  slog::join_probe<2,1>(eval_ansindex877, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m920) {
                    u64 v_c43 = m920[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c178, v_c43}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:$sup56712x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask882* _cont = new ReadTask882(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask882(db,b), false);
  // (crule (pre) (scan ref __t8y8931 x) (body (exists lookup (1 2 0) 1 x) (join-old eval (1 2 0) 1 (1 2 0) __t8y8931 c __t0HZY32) (join-old lookup (1 2 0) 2 (1 2 0) x c __t5YK333) (join lookup_ans (0 1) 1 __t5YK333 __v0)) (head (emit eval_ans (0 1) __t0HZY32 __v0)) interp.slog:30 #f)
  class ReadTask927 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex921;  slog::Index** evalindex922;  slog::Index** lookupindex923;  slog::Index** lookup_ansindex924;  slog::Index** evaldelta925;  slog::Index** lookupdelta926;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord928({0, 1});
      slog::Relation* readrel929 = db->getRelation("eval_ans");
      head_index[0] = readrel929->getIndex(ord928, false);
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("lookup");
      lookupindex921 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 2, 0});
      slog::Relation* readrel933 = db->getRelation("eval");
      evalindex922 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("eval");
      evaldelta925 = readrel935->getIndex(ord934, true);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("lookup");
      lookupindex923 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 0});
      slog::Relation* readrel939 = db->getRelation("lookup");
      lookupdelta926 = readrel939->getIndex(ord938, true);
      std::vector<u16> ord940({0, 1});
      slog::Relation* readrel941 = db->getRelation("lookup_ans");
      lookup_ansindex924 = readrel941->getIndex(ord940, false);
  
    }
    ReadTask927(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        if (!slog::exists_probe<3,1>(lookupindex921, std::array<u64,3>{v_c15, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex922, evaldelta925, std::array<u64,3>{v_c182, 0, 0}, [&](const std::array<u64,3>& m942) {
          u64 v_c6 = m942[1]; u64 v_c183 = m942[2];
          slog::join_probe_old<3,2>(lookupindex923, lookupdelta926, std::array<u64,3>{v_c15, v_c6, 0}, [&](const std::array<u64,3>& m943) {
            u64 v_c184 = m943[2];
            slog::join_probe<2,1>(lookup_ansindex924, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m944) {
              u64 v_c1 = m944[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c183, v_c1}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask927* _cont = new ReadTask927(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask927(db,b), false);
  // (crule (pre (let _00024sqc1ruq598 const6b86b273ff34fce19d6b804e) (let _00024sqc9Kmt599 const5feceb66ffc86f38d952786c) (let _00024sqc4E49600 const6b86b273ff34fce19d6b804e) (let _00024sqc7Uhq601 const5feceb66ffc86f38d952786c)) (scan eval_args __t7UNn145 _00024seq0 c) (body (letp _00024sql8tia596 (aslst _00024seq0)) (let _00024sqn2B6k597 (llen _00024sql8tia596)) (cmp ge _00024sqn2B6k597 _00024sqc1ruq598) (letp e (lref _00024sql8tia596 _00024sqc9Kmt599)) (let _00024sqp6Kbi602 (_0002d _00024sqn2B6k597 _00024sqc7Uhq601)) (let es (lslice _00024sql8tia596 _00024sqc4E49600 _00024sqp6Kbi602))) (head (emit $sup56712x37x0x0x0 (2 3 0 1 4) c e _00024seq0 __t7UNn145 es)) interp.slog:38 #f)
  class ReadTask945 : public slog::Task
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
      std::vector<u16> ord946({2, 3, 0, 1, 4});
      slog::Relation* readrel947 = db->getRelation("$sup56712x37x0x0x0");
      head_index[0] = readrel947->getIndex(ord946, false);
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask945(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_const5feceb66ffc86f38d952786c;
      u64 v_c187 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c188 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c189 = _t[0];
        u64 v_c147 = _t[1];
        u64 v_c6 = _t[2];
        bool ok948 = true;
        u64 v_c190 = _prim_aslst(db, v_c147, &ok948);
        if (!ok948) return;
        u64 v_c191 = _prim_llen(db, v_c190);
        if (v_c191 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c192 = _prim_ge(db, v_c191, v_c185);
        if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c192) return;
        bool ok950 = true;
        u64 v_c193 = _prim_lref(db, v_c190, v_c186, &ok950);
        if (!ok950) return;
        u64 v_c194 = _prim__0002d(db, v_c191, v_c188);
        if (v_c194 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c21 = _prim_lslice(db, v_c190, v_c187, v_c194);
        if (v_c21 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c6, v_c193, v_c147, v_c189, v_c21}, std::array<u16,5>{2, 3, 0, 1, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask945* _cont = new ReadTask945(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask945(db,b), false);
  // (crule (pre) (scan delta_ans __t8RjX507 v) (body (join-old delta (0 1 2) 1 (0 1 2) __t8RjX507 op vs) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t60iG506) (join-old prim (1 0) 1 (1 0) op __t4zl0505) (join eval_ans (1 0) 1 __t4zl0505 __t3A6m504) (join-old eval (0 2 1) 1 (0 2 1) __t3A6m504 c ef) (exists $sup56712x74x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join-old eval_args (0 2 1) 2 (0 2 1) __t60iG506 c es) (exists app (1 2 0) 2 ef es) (join-old $sup56712x74x0x0x0 (1 2 3 0) 3 (1 2 3 0) c ef es __t8a3x503) (exists eval (0 2 1) 2 __t8a3x503 c) (join-old app (1 2 0) 2 (1 2 0) ef es __t8eby502) (join-old eval (0 2 1) 3 (0 2 1) __t8a3x503 c __t8eby502)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask973 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex951;  slog::Index** primindex952;  slog::Index** eval_args_ansindex953;  slog::Index** primindex954;  slog::Index** eval_ansindex955;  slog::Index** evalindex956;  slog::Index** $sup56712x74x0x0x0index957;  slog::Index** appindex958;  slog::Index** evalindex959;  slog::Index** eval_argsindex960;  slog::Index** appindex961;  slog::Index** $sup56712x74x0x0x0index962;  slog::Index** evalindex963;  slog::Index** appindex964;  slog::Index** evalindex965;  slog::Index** deltadelta966;  slog::Index** primdelta967;  slog::Index** evaldelta968;  slog::Index** eval_argsdelta969;  slog::Index** $sup56712x74x0x0x0delta970;  slog::Index** appdelta971;  slog::Index** evaldelta972;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord974({0, 1});
      slog::Relation* readrel975 = db->getRelation("eval_ans");
      head_index[0] = readrel975->getIndex(ord974, false);
      outer_rel = db->getRelation("delta_ans");
      std::vector<u16> ord976({0, 1, 2});
      slog::Relation* readrel977 = db->getRelation("delta");
      deltaindex951 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({0, 1, 2});
      slog::Relation* readrel979 = db->getRelation("delta");
      deltadelta966 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({1, 0});
      slog::Relation* readrel981 = db->getRelation("prim");
      primindex952 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 0});
      slog::Relation* readrel983 = db->getRelation("eval_args_ans");
      eval_args_ansindex953 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({1, 0});
      slog::Relation* readrel985 = db->getRelation("prim");
      primindex954 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({1, 0});
      slog::Relation* readrel987 = db->getRelation("prim");
      primdelta967 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({1, 0});
      slog::Relation* readrel989 = db->getRelation("eval_ans");
      eval_ansindex955 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 2, 1});
      slog::Relation* readrel991 = db->getRelation("eval");
      evalindex956 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({0, 2, 1});
      slog::Relation* readrel993 = db->getRelation("eval");
      evaldelta968 = readrel993->getIndex(ord992, true);
      std::vector<u16> ord994({1, 2, 3, 0});
      slog::Relation* readrel995 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index957 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({1, 2, 0});
      slog::Relation* readrel997 = db->getRelation("app");
      appindex958 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({2, 0, 1});
      slog::Relation* readrel999 = db->getRelation("eval");
      evalindex959 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({0, 2, 1});
      slog::Relation* readrel1001 = db->getRelation("eval_args");
      eval_argsindex960 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({0, 2, 1});
      slog::Relation* readrel1003 = db->getRelation("eval_args");
      eval_argsdelta969 = readrel1003->getIndex(ord1002, true);
      std::vector<u16> ord1004({1, 2, 0});
      slog::Relation* readrel1005 = db->getRelation("app");
      appindex961 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({1, 2, 3, 0});
      slog::Relation* readrel1007 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index962 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({1, 2, 3, 0});
      slog::Relation* readrel1009 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta970 = readrel1009->getIndex(ord1008, true);
      std::vector<u16> ord1010({0, 2, 1});
      slog::Relation* readrel1011 = db->getRelation("eval");
      evalindex963 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 2, 0});
      slog::Relation* readrel1013 = db->getRelation("app");
      appindex964 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("app");
      appdelta971 = readrel1015->getIndex(ord1014, true);
      std::vector<u16> ord1016({0, 2, 1});
      slog::Relation* readrel1017 = db->getRelation("eval");
      evalindex965 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({0, 2, 1});
      slog::Relation* readrel1019 = db->getRelation("eval");
      evaldelta972 = readrel1019->getIndex(ord1018, true);
  
    }
    ReadTask973(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[1];
        slog::join_probe_old<3,1>(deltaindex951, deltadelta966, std::array<u64,3>{v_c129, 0, 0}, [&](const std::array<u64,3>& m1020) {
          u64 v_c30 = m1020[1]; u64 v_c25 = m1020[2];
          if (!slog::exists_probe<2,1>(primindex952, std::array<u64,2>{v_c30, 0})) return;
          slog::join_probe<2,1>(eval_args_ansindex953, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1021) {
            u64 v_c127 = m1021[1];
            slog::join_probe_old<2,1>(primindex954, primdelta967, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1022) {
              u64 v_c128 = m1022[1];
              slog::join_probe<2,1>(eval_ansindex955, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m1023) {
                u64 v_c126 = m1023[1];
                slog::join_probe_old<3,1>(evalindex956, evaldelta968, std::array<u64,3>{v_c126, 0, 0}, [&](const std::array<u64,3>& m1024) {
                  u64 v_c6 = m1024[1]; u64 v_c20 = m1024[2];
                  if (!slog::exists_probe<4,2>($sup56712x74x0x0x0index957, std::array<u64,4>{v_c6, v_c20, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex958, std::array<u64,3>{v_c20, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex959, std::array<u64,3>{v_c6, 0, 0})) return;
                  slog::join_probe_old<3,2>(eval_argsindex960, eval_argsdelta969, std::array<u64,3>{v_c127, v_c6, 0}, [&](const std::array<u64,3>& m1025) {
                    u64 v_c21 = m1025[2];
                    if (!slog::exists_probe<3,2>(appindex961, std::array<u64,3>{v_c20, v_c21, 0})) return;
                    slog::join_probe_old<4,3>($sup56712x74x0x0x0index962, $sup56712x74x0x0x0delta970, std::array<u64,4>{v_c6, v_c20, v_c21, 0}, [&](const std::array<u64,4>& m1026) {
                      u64 v_c124 = m1026[3];
                      if (!slog::exists_probe<3,2>(evalindex963, std::array<u64,3>{v_c124, v_c6, 0})) return;
                      slog::join_probe_old<3,2>(appindex964, appdelta971, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m1027) {
                        u64 v_c125 = m1027[2];
                        slog::join_probe_old<3,3>(evalindex965, evaldelta972, std::array<u64,3>{v_c124, v_c6, v_c125}, [&](const std::array<u64,3>& m1028) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c124, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask973* _cont = new ReadTask973(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask973(db,b), false);
  // (crule (pre) (scan freevar y __t3Eay213) (body (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3Eay213 xs eb) (join eval (0 2 1) 0 __1G4R719 c __t1Dbd212) (join-old app (0 1 2) 1 (0 1 2) __t1Dbd212 ef es)) (head (mkstruct tick (1 2 0) __2Xr3720 __t1Dbd212 c)) interp.slog:56 #f)
  class ReadTask1036 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex1029;  slog::Index** lambdaindex1030;  slog::Index** evalindex1031;  slog::Index** appindex1032;  slog::Index** bindingdelta1033;  slog::Index** lambdadelta1034;  slog::Index** appdelta1035;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1037({0, 1, 2});
      slog::Relation* readrel1038 = db->getRelation("binding");
      bindingindex1029 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1, 2});
      slog::Relation* readrel1040 = db->getRelation("binding");
      bindingdelta1033 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({0, 1, 2});
      slog::Relation* readrel1042 = db->getRelation("lambda");
      lambdaindex1030 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1, 2});
      slog::Relation* readrel1044 = db->getRelation("lambda");
      lambdadelta1034 = readrel1044->getIndex(ord1043, true);
      std::vector<u16> ord1045({0, 2, 1});
      slog::Relation* readrel1046 = db->getRelation("eval");
      evalindex1031 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({0, 1, 2});
      slog::Relation* readrel1048 = db->getRelation("app");
      appindex1032 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({0, 1, 2});
      slog::Relation* readrel1050 = db->getRelation("app");
      appdelta1035 = readrel1050->getIndex(ord1049, true);
  
    }
    ReadTask1036(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(bindingindex1029, bindingdelta1033, std::array<u64,3>{v_c195, 0, 0}, [&](const std::array<u64,3>& m1051) {
          u64 v_c18 = m1051[1]; u64 v_c197 = m1051[2];
          slog::join_probe_old<3,1>(lambdaindex1030, lambdadelta1034, std::array<u64,3>{v_c196, 0, 0}, [&](const std::array<u64,3>& m1052) {
            u64 v_c26 = m1052[1]; u64 v_c27 = m1052[2];
            slog::join_all<3>(evalindex1031, [&](const std::array<u64,3>& m1053) {
              u64 v_c198 = m1053[0]; u64 v_c6 = m1053[1]; u64 v_c199 = m1053[2];
              slog::join_probe_old<3,1>(appindex1032, appdelta1035, std::array<u64,3>{v_c199, 0, 0}, [&](const std::array<u64,3>& m1054) {
                u64 v_c20 = m1054[1]; u64 v_c21 = m1054[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c199, v_c6}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1036* _cont = new ReadTask1036(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1036(db,b), false);
  // (crule (pre) (scan eval_ans __t9p2a295 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t9p2a295 c er) (exists letrec (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (join-old $sup56712x93x0x0x0 (1 3 0 2 4) 2 (1 3 0 2 4) c er __t5OlD294 eb x) (exists eval (0 2 1) 2 __t5OlD294 c) (exists eval (1 2 0) 2 eb c) (join-old letrec (2 1 3 0) 3 (2 1 3 0) er x eb __t0H7q293) (join-old eval (0 2 1) 3 (0 2 1) __t5OlD294 c __t0H7q293) (join-old eval (1 2 0) 2 (1 2 0) eb c __t32yp296) (join-old eval_ans (0 1) 1 (0 1) __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask1071 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1055;  slog::Index** letrecindex1056;  slog::Index** evalindex1057;  slog::Index** $sup56712x93x0x0x0index1058;  slog::Index** evalindex1059;  slog::Index** evalindex1060;  slog::Index** letrecindex1061;  slog::Index** evalindex1062;  slog::Index** evalindex1063;  slog::Index** eval_ansindex1064;  slog::Index** evaldelta1065;  slog::Index** $sup56712x93x0x0x0delta1066;  slog::Index** letrecdelta1067;  slog::Index** evaldelta1068;  slog::Index** evaldelta1069;  slog::Index** eval_ansdelta1070;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1072({0, 1});
      slog::Relation* readrel1073 = db->getRelation("eval_ans");
      head_index[0] = readrel1073->getIndex(ord1072, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1074({0, 2, 1});
      slog::Relation* readrel1075 = db->getRelation("eval");
      evalindex1055 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({0, 2, 1});
      slog::Relation* readrel1077 = db->getRelation("eval");
      evaldelta1065 = readrel1077->getIndex(ord1076, true);
      std::vector<u16> ord1078({2, 1, 3, 0});
      slog::Relation* readrel1079 = db->getRelation("letrec");
      letrecindex1056 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({2, 0, 1});
      slog::Relation* readrel1081 = db->getRelation("eval");
      evalindex1057 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 3, 0, 2, 4});
      slog::Relation* readrel1083 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index1058 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 3, 0, 2, 4});
      slog::Relation* readrel1085 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0delta1066 = readrel1085->getIndex(ord1084, true);
      std::vector<u16> ord1086({0, 2, 1});
      slog::Relation* readrel1087 = db->getRelation("eval");
      evalindex1059 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({1, 2, 0});
      slog::Relation* readrel1089 = db->getRelation("eval");
      evalindex1060 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({2, 1, 3, 0});
      slog::Relation* readrel1091 = db->getRelation("letrec");
      letrecindex1061 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({2, 1, 3, 0});
      slog::Relation* readrel1093 = db->getRelation("letrec");
      letrecdelta1067 = readrel1093->getIndex(ord1092, true);
      std::vector<u16> ord1094({0, 2, 1});
      slog::Relation* readrel1095 = db->getRelation("eval");
      evalindex1062 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({0, 2, 1});
      slog::Relation* readrel1097 = db->getRelation("eval");
      evaldelta1068 = readrel1097->getIndex(ord1096, true);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("eval");
      evalindex1063 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 0});
      slog::Relation* readrel1101 = db->getRelation("eval");
      evaldelta1069 = readrel1101->getIndex(ord1100, true);
      std::vector<u16> ord1102({0, 1});
      slog::Relation* readrel1103 = db->getRelation("eval_ans");
      eval_ansindex1064 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1});
      slog::Relation* readrel1105 = db->getRelation("eval_ans");
      eval_ansdelta1070 = readrel1105->getIndex(ord1104, true);
  
    }
    ReadTask1071(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[0];
        u64 v_c64 = _t[1];
        slog::join_probe_old<3,1>(evalindex1055, evaldelta1065, std::array<u64,3>{v_c180, 0, 0}, [&](const std::array<u64,3>& m1106) {
          u64 v_c6 = m1106[1]; u64 v_c61 = m1106[2];
          if (!slog::exists_probe<4,1>(letrecindex1056, std::array<u64,4>{v_c61, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1057, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x93x0x0x0index1058, $sup56712x93x0x0x0delta1066, std::array<u64,5>{v_c6, v_c61, 0, 0, 0}, [&](const std::array<u64,5>& m1107) {
            u64 v_c178 = m1107[2]; u64 v_c27 = m1107[3]; u64 v_c15 = m1107[4];
            if (!slog::exists_probe<3,2>(evalindex1059, std::array<u64,3>{v_c178, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex1060, std::array<u64,3>{v_c27, v_c6, 0})) return;
            slog::join_probe_old<4,3>(letrecindex1061, letrecdelta1067, std::array<u64,4>{v_c61, v_c15, v_c27, 0}, [&](const std::array<u64,4>& m1108) {
              u64 v_c179 = m1108[3];
              slog::join_probe_old<3,3>(evalindex1062, evaldelta1068, std::array<u64,3>{v_c178, v_c6, v_c179}, [&](const std::array<u64,3>& m1109) {
                slog::join_probe_old<3,2>(evalindex1063, evaldelta1069, std::array<u64,3>{v_c27, v_c6, 0}, [&](const std::array<u64,3>& m1110) {
                  u64 v_c181 = m1110[2];
                  slog::join_probe_old<2,1>(eval_ansindex1064, eval_ansdelta1070, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m1111) {
                    u64 v_c43 = m1111[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c178, v_c43}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1071* _cont = new ReadTask1071(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1071(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre7jFS950 __errf6YaC951 __errf7Or0952) (body) (head (emit error (0) __erre7jFS950)) <internal>:1 #f)
  class ReadTask1112 : public slog::Task
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
      std::vector<u16> ord1113({0});
      slog::Relation* readrel1114 = db->getRelation("error");
      head_index[0] = readrel1114->getIndex(ord1113, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask1112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c200 = _t[0];
        u64 v_c201 = _t[1];
        u64 v_c202 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c200}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask1112* _cont = new ReadTask1112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1112(db,b), false);
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (scan closure __t59ft158 lm cb) (body (exists $seq_at (1 0 2) 2 _00024sqo2IHZ514 __t59ft158) (exists $seq_atr (1 0 2) 2 _00024sqo1Kdp515 __t59ft158) (exists $seq_atr (1 0 2) 2 _00024sqo0AcC516 __t59ft158) (exists delta (1 2 0) 1 __tconst3bSs155) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo3TKl513 __t59ft158 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2IHZ514 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Kdp515 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0AcC516 __t59ft158 _00024seq2) (join delta (1 2 0) 2 __tconst3bSs155 _00024seq2 __t2lyA156) (join any_bool (0) 0 b) (letp _00024sql2qfO508 (aslst _00024seq2)) (let chk97bS1131 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk97bS1131) (letp chk3dtz1132 (lref _00024sql2qfO508 _00024sqc65nX511)) (eq __t59ft158 chk3dtz1132) (letp chk49oj1133 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk49oj1133)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask1129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1115;  slog::Index** $seq_atrindex1116;  slog::Index** $seq_atrindex1117;  slog::Index** deltaindex1118;  slog::Index** $seq_atindex1119;  slog::Index** $seq_atindex1120;  slog::Index** $seq_atrindex1121;  slog::Index** $seq_atrindex1122;  slog::Index** deltaindex1123;  slog::Index** any_boolindex1124;  slog::Index** $seq_atdelta1125;  slog::Index** $seq_atdelta1126;  slog::Index** $seq_atrdelta1127;  slog::Index** $seq_atrdelta1128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord1130({1, 0, 2});
      slog::Relation* readrel1131 = db->getRelation("$seq_at");
      $seq_atindex1115 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 0, 2});
      slog::Relation* readrel1133 = db->getRelation("$seq_atr");
      $seq_atrindex1116 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 0, 2});
      slog::Relation* readrel1135 = db->getRelation("$seq_atr");
      $seq_atrindex1117 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 2, 0});
      slog::Relation* readrel1137 = db->getRelation("delta");
      deltaindex1118 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({1, 0, 2});
      slog::Relation* readrel1139 = db->getRelation("$seq_at");
      $seq_atindex1119 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 0, 2});
      slog::Relation* readrel1141 = db->getRelation("$seq_at");
      $seq_atdelta1125 = readrel1141->getIndex(ord1140, true);
      std::vector<u16> ord1142({1, 0, 2});
      slog::Relation* readrel1143 = db->getRelation("$seq_at");
      $seq_atindex1120 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 0, 2});
      slog::Relation* readrel1145 = db->getRelation("$seq_at");
      $seq_atdelta1126 = readrel1145->getIndex(ord1144, true);
      std::vector<u16> ord1146({1, 0, 2});
      slog::Relation* readrel1147 = db->getRelation("$seq_atr");
      $seq_atrindex1121 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({1, 0, 2});
      slog::Relation* readrel1149 = db->getRelation("$seq_atr");
      $seq_atrdelta1127 = readrel1149->getIndex(ord1148, true);
      std::vector<u16> ord1150({1, 0, 2});
      slog::Relation* readrel1151 = db->getRelation("$seq_atr");
      $seq_atrindex1122 = readrel1151->getIndex(ord1150, false);
      std::vector<u16> ord1152({1, 0, 2});
      slog::Relation* readrel1153 = db->getRelation("$seq_atr");
      $seq_atrdelta1128 = readrel1153->getIndex(ord1152, true);
      std::vector<u16> ord1154({1, 2, 0});
      slog::Relation* readrel1155 = db->getRelation("delta");
      deltaindex1123 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({0});
      slog::Relation* readrel1157 = db->getRelation("any_bool");
      any_boolindex1124 = readrel1157->getIndex(ord1156, false);
  
    }
    ReadTask1129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const06abaa100ecef791ce028c56;
      u64 v_c108 = v_constd4735e3a265e16eee03f5971;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c115 = _t[0];
        u64 v_c118 = _t[1];
        u64 v_c18 = _t[2];
        if (!slog::exists_probe<3,2>($seq_atindex1115, std::array<u64,3>{v_c112, v_c115, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1116, std::array<u64,3>{v_c113, v_c115, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1117, std::array<u64,3>{v_c114, v_c115, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex1118, std::array<u64,3>{v_c107, 0, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1119, $seq_atdelta1125, std::array<u64,3>{v_c111, v_c115, 0}, [&](const std::array<u64,3>& m1158) {
          u64 v_c116 = m1158[2];
          slog::join_probe_old<3,3>($seq_atindex1120, $seq_atdelta1126, std::array<u64,3>{v_c112, v_c115, v_c116}, [&](const std::array<u64,3>& m1159) {
            slog::join_probe_old<3,3>($seq_atrindex1121, $seq_atrdelta1127, std::array<u64,3>{v_c113, v_c115, v_c116}, [&](const std::array<u64,3>& m1160) {
              slog::join_probe_old<3,3>($seq_atrindex1122, $seq_atrdelta1128, std::array<u64,3>{v_c114, v_c115, v_c116}, [&](const std::array<u64,3>& m1161) {
                slog::join_probe<3,2>(deltaindex1123, std::array<u64,3>{v_c107, v_c116, 0}, [&](const std::array<u64,3>& m1162) {
                  u64 v_c117 = m1162[2];
                  slog::join_all<1>(any_boolindex1124, [&](const std::array<u64,1>& m1163) {
                    u64 v_c119 = m1163[0];
                    bool ok1164 = true;
                    u64 v_c120 = _prim_aslst(db, v_c116, &ok1164);
                    if (!ok1164) return;
                    u64 v_c203 = _prim_llen(db, v_c120);
                    if (v_c203 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c108 != v_c203) return;
                    bool ok1165 = true;
                    u64 v_c204 = _prim_lref(db, v_c120, v_c109, &ok1165);
                    if (!ok1165) return;
                    if (v_c115 != v_c204) return;
                    bool ok1166 = true;
                    u64 v_c205 = _prim_lref(db, v_c120, v_c110, &ok1166);
                    if (!ok1166) return;
                    if (v_c115 != v_c205) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c117, v_c119});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c119}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask1129* _cont = new ReadTask1129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1129(db,b), false);
  // (crule (pre (let __t1Myh135 (lempty))) (scan program e) (body) (head (emit-temp temp87fU992 __t1Myh135 e)) interp.slog:129 #f)
  class ReadTask1167 : public slog::Task
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
      head_rel[0] = db->getRelation("temp87fU992");
      outer_rel = db->getRelation("program");
  
    }
    ReadTask1167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = _prim_lempty(db);
      if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:129"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c193 = _t[0];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c206, v_c193});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:129", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask1167* _cont = new ReadTask1167(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1167(db,b), false);
  // (crule (pre (let _00024sqc2oXB553 const6b86b273ff34fce19d6b804e) (let _00024sqc3Uyr554 const5feceb66ffc86f38d952786c) (let _00024sqc24j5555 const6b86b273ff34fce19d6b804e) (let _00024sqc6qhn556 const5feceb66ffc86f38d952786c) (let __t4EG4161 (lempty))) (scan argument_list _00024seq0) (body (letp _00024sql1b7l551 (aslst _00024seq0)) (let _00024sqn9FNh552 (llen _00024sql1b7l551)) (cmp ge _00024sqn9FNh552 _00024sqc2oXB553) (let _00024sqp9dtl557 (_0002d _00024sqn9FNh552 _00024sqc6qhn556)) (let es (lslice _00024sql1b7l551 _00024sqc24j5555 _00024sqp9dtl557)) (join freevar_in_args (1 0) 1 es x) (letp e (lref _00024sql1b7l551 _00024sqc3Uyr554))) (head (emit-temp temp2Fk51003 __t4EG4161 e es x)) freevars.slog:35 #f)
  class ReadTask1169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevar_in_argsindex1168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Fk51003");
      outer_rel = db->getRelation("argument_list");
      std::vector<u16> ord1170({1, 0});
      slog::Relation* readrel1171 = db->getRelation("freevar_in_args");
      freevar_in_argsindex1168 = readrel1171->getIndex(ord1170, false);
  
    }
    ReadTask1169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c210 = v_const5feceb66ffc86f38d952786c;
      u64 v_c211 = _prim_lempty(db);
      if (v_c211 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c147 = _t[0];
        bool ok1172 = true;
        u64 v_c212 = _prim_aslst(db, v_c147, &ok1172);
        if (!ok1172) return;
        u64 v_c213 = _prim_llen(db, v_c212);
        if (v_c213 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        u64 v_c214 = _prim_ge(db, v_c213, v_c207);
        if (v_c214 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        if (!v_c214) return;
        u64 v_c215 = _prim__0002d(db, v_c213, v_c210);
        if (v_c215 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        u64 v_c21 = _prim_lslice(db, v_c212, v_c209, v_c215);
        if (v_c21 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        slog::join_probe<2,1>(freevar_in_argsindex1168, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1174) {
          u64 v_c15 = m1174[1];
          bool ok1175 = true;
          u64 v_c193 = _prim_lref(db, v_c212, v_c208, &ok1175);
          if (!ok1175) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c211, v_c193, v_c21, v_c15});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:argument_list", _fires);
  
      if (!_done)
      {
        ReadTask1169* _cont = new ReadTask1169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1169(db,b), false);
  // (crule (pre) (scan lambda __t4mHn300 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t4mHn300 cb __t4ng7301) (join eval_ans (1 0) 1 __t4ng7301 __t9B5D299) (join eval (0 2 1) 1 __t9B5D299 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join tick_ans (0 1) 1 __t5Pln304 l)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1176;  slog::Index** eval_ansindex1177;  slog::Index** evalindex1178;  slog::Index** appindex1179;  slog::Index** eval_argsindex1180;  slog::Index** tickindex1181;  slog::Index** evalindex1182;  slog::Index** tickindex1183;  slog::Index** appindex1184;  slog::Index** eval_argsindex1185;  slog::Index** eval_args_ansindex1186;  slog::Index** tickindex1187;  slog::Index** tick_ansindex1188;  slog::Index** eval_args_ansindex1189;  slog::Index** tick_ansindex1190;  slog::Index** closuredelta1191;  slog::Index** appdelta1192;  slog::Index** eval_argsdelta1193;  slog::Index** tickdelta1194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1196({0, 1, 2, 3});
      slog::Relation* readrel1197 = db->getRelation("bind_params");
      head_index[0] = readrel1197->getIndex(ord1196, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1198({0, 1});
      slog::Relation* readrel1199 = db->getRelation("call_event");
      head_index[1] = readrel1199->getIndex(ord1198, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("closure");
      closureindex1176 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 2, 0});
      slog::Relation* readrel1203 = db->getRelation("closure");
      closuredelta1191 = readrel1203->getIndex(ord1202, true);
      std::vector<u16> ord1204({1, 0});
      slog::Relation* readrel1205 = db->getRelation("eval_ans");
      eval_ansindex1177 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({0, 2, 1});
      slog::Relation* readrel1207 = db->getRelation("eval");
      evalindex1178 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 2, 0});
      slog::Relation* readrel1209 = db->getRelation("app");
      appindex1179 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({2, 0, 1});
      slog::Relation* readrel1211 = db->getRelation("eval_args");
      eval_argsindex1180 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({2, 0, 1});
      slog::Relation* readrel1213 = db->getRelation("tick");
      tickindex1181 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({2, 0, 1});
      slog::Relation* readrel1215 = db->getRelation("eval");
      evalindex1182 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 2, 0});
      slog::Relation* readrel1217 = db->getRelation("tick");
      tickindex1183 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({0, 1, 2});
      slog::Relation* readrel1219 = db->getRelation("app");
      appindex1184 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({0, 1, 2});
      slog::Relation* readrel1221 = db->getRelation("app");
      appdelta1192 = readrel1221->getIndex(ord1220, true);
      std::vector<u16> ord1222({1, 2, 0});
      slog::Relation* readrel1223 = db->getRelation("eval_args");
      eval_argsindex1185 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 2, 0});
      slog::Relation* readrel1225 = db->getRelation("eval_args");
      eval_argsdelta1193 = readrel1225->getIndex(ord1224, true);
      std::vector<u16> ord1226({0, 1});
      slog::Relation* readrel1227 = db->getRelation("eval_args_ans");
      eval_args_ansindex1186 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 2, 0});
      slog::Relation* readrel1229 = db->getRelation("tick");
      tickindex1187 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({1, 2, 0});
      slog::Relation* readrel1231 = db->getRelation("tick");
      tickdelta1194 = readrel1231->getIndex(ord1230, true);
      std::vector<u16> ord1232({0, 1});
      slog::Relation* readrel1233 = db->getRelation("tick_ans");
      tick_ansindex1188 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({0, 1});
      slog::Relation* readrel1235 = db->getRelation("eval_args_ans");
      eval_args_ansindex1189 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({0, 1});
      slog::Relation* readrel1237 = db->getRelation("tick_ans");
      tick_ansindex1190 = readrel1237->getIndex(ord1236, false);
  
    }
    ReadTask1195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c216 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c27 = _t[2];
        slog::join_probe_old<3,1>(closureindex1176, closuredelta1191, std::array<u64,3>{v_c216, 0, 0}, [&](const std::array<u64,3>& m1238) {
          u64 v_c18 = m1238[1]; u64 v_c217 = m1238[2];
          slog::join_probe<2,1>(eval_ansindex1177, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1239) {
            u64 v_c218 = m1239[1];
            slog::join_probe<3,1>(evalindex1178, std::array<u64,3>{v_c218, 0, 0}, [&](const std::array<u64,3>& m1240) {
              u64 v_c6 = m1240[1]; u64 v_c20 = m1240[2];
              if (!slog::exists_probe<3,1>(appindex1179, std::array<u64,3>{v_c20, 0, 0})) return;
              if (!slog::exists_probe<3,1>(eval_argsindex1180, std::array<u64,3>{v_c6, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex1181, std::array<u64,3>{v_c6, 0, 0})) return;
              slog::join_probe<3,1>(evalindex1182, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m1241) {
                u64 v_c219 = m1241[1]; u64 v_c220 = m1241[2];
                if (!slog::exists_probe<3,2>(tickindex1183, std::array<u64,3>{v_c220, v_c6, 0})) return;
                slog::join_probe_old<3,2>(appindex1184, appdelta1192, std::array<u64,3>{v_c220, v_c20, 0}, [&](const std::array<u64,3>& m1242) {
                  u64 v_c21 = m1242[2];
                  slog::join_probe_old<3,2>(eval_argsindex1185, eval_argsdelta1193, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m1243) {
                    u64 v_c221 = m1243[2];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex1186, std::array<u64,2>{v_c221, 0})) return;
                    slog::join_probe_old<3,2>(tickindex1187, tickdelta1194, std::array<u64,3>{v_c220, v_c6, 0}, [&](const std::array<u64,3>& m1244) {
                      u64 v_c222 = m1244[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex1188, std::array<u64,2>{v_c222, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex1189, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m1245) {
                        u64 v_c25 = m1245[1];
                        slog::join_probe<2,1>(tick_ansindex1190, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m1246) {
                          u64 v_c149 = m1246[1];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c26, v_c25, v_c149, v_c6}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c149, v_c6}, std::array<u16,2>{0, 1});
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
        ReadTask1195* _cont = new ReadTask1195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1195(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst16Oe187 _00024seq2 __t4OrE188) (body (letp _00024sql3Mb9587 (aslst _00024seq2)) (letp __t76ef190 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2ych592 __t76ef190 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3d3H593 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5WJE594 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4b4d595 __t76ef190 _00024seq2) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join-old prim (0 1) 1 (0 1) __t76ef190 op) (let chk3Cca1059 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk3Cca1059) (letp chk7U5T1060 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk7U5T1060)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask1258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1247;  slog::Index** $seq_atindex1248;  slog::Index** $seq_atrindex1249;  slog::Index** $seq_atrindex1250;  slog::Index** _enumindex1251;  slog::Index** primindex1252;  slog::Index** $seq_atdelta1253;  slog::Index** $seq_atdelta1254;  slog::Index** $seq_atrdelta1255;  slog::Index** $seq_atrdelta1256;  slog::Index** primdelta1257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1259({1, 2, 0});
      slog::Relation* readrel1260 = db->getRelation("delta");
      driver_index = readrel1260->getIndex(ord1259, true);
      std::vector<u16> ord1261({1, 0, 2});
      slog::Relation* readrel1262 = db->getRelation("$seq_at");
      $seq_atindex1247 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 0, 2});
      slog::Relation* readrel1264 = db->getRelation("$seq_at");
      $seq_atdelta1253 = readrel1264->getIndex(ord1263, true);
      std::vector<u16> ord1265({1, 0, 2});
      slog::Relation* readrel1266 = db->getRelation("$seq_at");
      $seq_atindex1248 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 0, 2});
      slog::Relation* readrel1268 = db->getRelation("$seq_at");
      $seq_atdelta1254 = readrel1268->getIndex(ord1267, true);
      std::vector<u16> ord1269({1, 0, 2});
      slog::Relation* readrel1270 = db->getRelation("$seq_atr");
      $seq_atrindex1249 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({1, 0, 2});
      slog::Relation* readrel1272 = db->getRelation("$seq_atr");
      $seq_atrdelta1255 = readrel1272->getIndex(ord1271, true);
      std::vector<u16> ord1273({1, 0, 2});
      slog::Relation* readrel1274 = db->getRelation("$seq_atr");
      $seq_atrindex1250 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({1, 0, 2});
      slog::Relation* readrel1276 = db->getRelation("$seq_atr");
      $seq_atrdelta1256 = readrel1276->getIndex(ord1275, true);
      std::vector<u16> ord1277({1, 0});
      slog::Relation* readrel1278 = db->getRelation("_enum");
      _enumindex1251 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({0, 1});
      slog::Relation* readrel1280 = db->getRelation("prim");
      primindex1252 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({0, 1});
      slog::Relation* readrel1282 = db->getRelation("prim");
      primdelta1257 = readrel1282->getIndex(ord1281, true);
  
    }
    ReadTask1258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c223 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c224 = v_const06abaa100ecef791ce028c56;
      u64 v_c225 = v_constd4735e3a265e16eee03f5971;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
      u64 v_c227 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c228 = v_const5feceb66ffc86f38d952786c;
      u64 v_c229 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c230 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c231 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c224, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1283) {
        u64 v_c116 = m1283[1];
        u64 v_c232 = m1283[2];
        if (buckethash(v_c116) != bucket) return;
        bool ok1284 = true;
        u64 v_c233 = _prim_aslst(db, v_c116, &ok1284);
        if (!ok1284) return;
        bool ok1285 = true;
        u64 v_c234 = _prim_lref(db, v_c233, v_c226, &ok1285);
        if (!ok1285) return;
        slog::join_probe_old<3,3>($seq_atindex1247, $seq_atdelta1253, std::array<u64,3>{v_c228, v_c234, v_c116}, [&](const std::array<u64,3>& m1286) {
          slog::join_probe_old<3,3>($seq_atindex1248, $seq_atdelta1254, std::array<u64,3>{v_c229, v_c234, v_c116}, [&](const std::array<u64,3>& m1287) {
            slog::join_probe_old<3,3>($seq_atrindex1249, $seq_atrdelta1255, std::array<u64,3>{v_c230, v_c234, v_c116}, [&](const std::array<u64,3>& m1288) {
              slog::join_probe_old<3,3>($seq_atrindex1250, $seq_atrdelta1256, std::array<u64,3>{v_c231, v_c234, v_c116}, [&](const std::array<u64,3>& m1289) {
                slog::join_probe<2,1>(_enumindex1251, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1290) {
                  u64 v_c235 = m1290[1];
                  slog::join_probe_old<2,1>(primindex1252, primdelta1257, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1291) {
                    u64 v_c30 = m1291[1];
                    u64 v_c236 = _prim_llen(db, v_c233);
                    if (v_c236 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c225 != v_c236) return;
                    bool ok1292 = true;
                    u64 v_c237 = _prim_lref(db, v_c233, v_c227, &ok1292);
                    if (!ok1292) return;
                    if (v_c234 != v_c237) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c232});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c235}, std::array<u16,2>{1, 0});
                  });
                });
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
        ReadTask1258* _cont = new ReadTask1258(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1258(db,b), false);
  // (crule (pre) (scan $sup56712x74x0x0x0 __t8a3x503 c ef es) (body (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval (1 2 0) 2 ef c) (exists eval_args (1 2 0) 2 es c) (join-old app (1 2 0) 2 (1 2 0) ef es __t8eby502) (join-old eval (0 2 1) 3 (0 2 1) __t8a3x503 c __t8eby502) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3A6m504) (exists eval_ans (0 1) 1 __t3A6m504) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (exists eval_args_ans (0 1) 1 __t60iG506) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join eval_args_ans (0 1) 1 __t60iG506 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask1314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1293;  slog::Index** evalindex1294;  slog::Index** eval_argsindex1295;  slog::Index** appindex1296;  slog::Index** evalindex1297;  slog::Index** evalindex1298;  slog::Index** eval_ansindex1299;  slog::Index** eval_argsindex1300;  slog::Index** eval_args_ansindex1301;  slog::Index** eval_ansindex1302;  slog::Index** eval_args_ansindex1303;  slog::Index** deltaindex1304;  slog::Index** primindex1305;  slog::Index** deltaindex1306;  slog::Index** delta_ansindex1307;  slog::Index** appdelta1308;  slog::Index** evaldelta1309;  slog::Index** evaldelta1310;  slog::Index** eval_argsdelta1311;  slog::Index** primdelta1312;  slog::Index** deltadelta1313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1315({0, 1});
      slog::Relation* readrel1316 = db->getRelation("eval_ans");
      head_index[0] = readrel1316->getIndex(ord1315, false);
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord1317({0, 2, 1});
      slog::Relation* readrel1318 = db->getRelation("eval");
      evalindex1293 = readrel1318->getIndex(ord1317, false);
      std::vector<u16> ord1319({1, 2, 0});
      slog::Relation* readrel1320 = db->getRelation("eval");
      evalindex1294 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("eval_args");
      eval_argsindex1295 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({1, 2, 0});
      slog::Relation* readrel1324 = db->getRelation("app");
      appindex1296 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({1, 2, 0});
      slog::Relation* readrel1326 = db->getRelation("app");
      appdelta1308 = readrel1326->getIndex(ord1325, true);
      std::vector<u16> ord1327({0, 2, 1});
      slog::Relation* readrel1328 = db->getRelation("eval");
      evalindex1297 = readrel1328->getIndex(ord1327, false);
      std::vector<u16> ord1329({0, 2, 1});
      slog::Relation* readrel1330 = db->getRelation("eval");
      evaldelta1309 = readrel1330->getIndex(ord1329, true);
      std::vector<u16> ord1331({1, 2, 0});
      slog::Relation* readrel1332 = db->getRelation("eval");
      evalindex1298 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({1, 2, 0});
      slog::Relation* readrel1334 = db->getRelation("eval");
      evaldelta1310 = readrel1334->getIndex(ord1333, true);
      std::vector<u16> ord1335({0, 1});
      slog::Relation* readrel1336 = db->getRelation("eval_ans");
      eval_ansindex1299 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({1, 2, 0});
      slog::Relation* readrel1338 = db->getRelation("eval_args");
      eval_argsindex1300 = readrel1338->getIndex(ord1337, false);
      std::vector<u16> ord1339({1, 2, 0});
      slog::Relation* readrel1340 = db->getRelation("eval_args");
      eval_argsdelta1311 = readrel1340->getIndex(ord1339, true);
      std::vector<u16> ord1341({0, 1});
      slog::Relation* readrel1342 = db->getRelation("eval_args_ans");
      eval_args_ansindex1301 = readrel1342->getIndex(ord1341, false);
      std::vector<u16> ord1343({0, 1});
      slog::Relation* readrel1344 = db->getRelation("eval_ans");
      eval_ansindex1302 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({0, 1});
      slog::Relation* readrel1346 = db->getRelation("eval_args_ans");
      eval_args_ansindex1303 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({2, 0, 1});
      slog::Relation* readrel1348 = db->getRelation("delta");
      deltaindex1304 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({0, 1});
      slog::Relation* readrel1350 = db->getRelation("prim");
      primindex1305 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({0, 1});
      slog::Relation* readrel1352 = db->getRelation("prim");
      primdelta1312 = readrel1352->getIndex(ord1351, true);
      std::vector<u16> ord1353({1, 2, 0});
      slog::Relation* readrel1354 = db->getRelation("delta");
      deltaindex1306 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("delta");
      deltadelta1313 = readrel1356->getIndex(ord1355, true);
      std::vector<u16> ord1357({0, 1});
      slog::Relation* readrel1358 = db->getRelation("delta_ans");
      delta_ansindex1307 = readrel1358->getIndex(ord1357, false);
  
    }
    ReadTask1314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c21 = _t[3];
        if (!slog::exists_probe<3,2>(evalindex1293, std::array<u64,3>{v_c124, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1294, std::array<u64,3>{v_c20, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(eval_argsindex1295, std::array<u64,3>{v_c21, v_c6, 0})) return;
        slog::join_probe_old<3,2>(appindex1296, appdelta1308, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m1359) {
          u64 v_c125 = m1359[2];
          slog::join_probe_old<3,3>(evalindex1297, evaldelta1309, std::array<u64,3>{v_c124, v_c6, v_c125}, [&](const std::array<u64,3>& m1360) {
            slog::join_probe_old<3,2>(evalindex1298, evaldelta1310, std::array<u64,3>{v_c20, v_c6, 0}, [&](const std::array<u64,3>& m1361) {
              u64 v_c126 = m1361[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1299, std::array<u64,2>{v_c126, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex1300, eval_argsdelta1311, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m1362) {
                u64 v_c127 = m1362[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1301, std::array<u64,2>{v_c127, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1302, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m1363) {
                  u64 v_c128 = m1363[1];
                  slog::join_probe<2,1>(eval_args_ansindex1303, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m1364) {
                    u64 v_c25 = m1364[1];
                    if (!slog::exists_probe<3,1>(deltaindex1304, std::array<u64,3>{v_c25, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex1305, primdelta1312, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m1365) {
                      u64 v_c30 = m1365[1];
                      slog::join_probe_old<3,2>(deltaindex1306, deltadelta1313, std::array<u64,3>{v_c30, v_c25, 0}, [&](const std::array<u64,3>& m1366) {
                        u64 v_c129 = m1366[2];
                        slog::join_probe<2,1>(delta_ansindex1307, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m1367) {
                          u64 v_c43 = m1367[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c124, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask1314* _cont = new ReadTask1314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1314(db,b), false);
  // (crule (pre (let __tconst7oTo733 constb9e118781cea1f9fa01462e0) (let __tconst23AG380 const60e3114d9b4b6577eea8cbc0) (let _00024sqc7zL5538 const6b86b273ff34fce19d6b804e) (let _00024sqc0b5k539 const5feceb66ffc86f38d952786c) (let _00024sqo0tFP540 const5feceb66ffc86f38d952786c) (let _00024sqo2KLy541 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst23AG380 _00024seq0 __t7rOF381) (body (letp _00024sql6Yee536 (aslst _00024seq0)) (letp v (lref _00024sql6Yee536 _00024sqc0b5k539)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0tFP540 v _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2KLy541 v _00024seq0) (join _enum (1 0) 1 __tconst7oTo733 __t1FRr378) (join scheme_false (0) 0 fv) (neq v fv) (let chk01y9998 (llen _00024sql6Yee536)) (eq _00024sqc7zL5538 chk01y9998)) (head (emit-temp temp0LTu995 __t7rOF381) (mkstruct boolval (1 0) __t7RmO379 __t1FRr378)) interp.slog:114 #f)
  class ReadTask1374 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1368;  slog::Index** $seq_atrindex1369;  slog::Index** _enumindex1370;  slog::Index** scheme_falseindex1371;  slog::Index** $seq_atdelta1372;  slog::Index** $seq_atrdelta1373;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LTu995");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1375({1, 2, 0});
      slog::Relation* readrel1376 = db->getRelation("delta");
      driver_index = readrel1376->getIndex(ord1375, true);
      std::vector<u16> ord1377({1, 0, 2});
      slog::Relation* readrel1378 = db->getRelation("$seq_at");
      $seq_atindex1368 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 0, 2});
      slog::Relation* readrel1380 = db->getRelation("$seq_at");
      $seq_atdelta1372 = readrel1380->getIndex(ord1379, true);
      std::vector<u16> ord1381({1, 0, 2});
      slog::Relation* readrel1382 = db->getRelation("$seq_atr");
      $seq_atrindex1369 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 0, 2});
      slog::Relation* readrel1384 = db->getRelation("$seq_atr");
      $seq_atrdelta1373 = readrel1384->getIndex(ord1383, true);
      std::vector<u16> ord1385({1, 0});
      slog::Relation* readrel1386 = db->getRelation("_enum");
      _enumindex1370 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0});
      slog::Relation* readrel1388 = db->getRelation("scheme_false");
      scheme_falseindex1371 = readrel1388->getIndex(ord1387, false);
  
    }
    ReadTask1374(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c158 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c159 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c160 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c161 = v_const5feceb66ffc86f38d952786c;
      u64 v_c162 = v_const5feceb66ffc86f38d952786c;
      u64 v_c163 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c159, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1389) {
        u64 v_c147 = m1389[1];
        u64 v_c164 = m1389[2];
        if (buckethash(v_c147) != bucket) return;
        bool ok1390 = true;
        u64 v_c167 = _prim_aslst(db, v_c147, &ok1390);
        if (!ok1390) return;
        bool ok1391 = true;
        u64 v_c43 = _prim_lref(db, v_c167, v_c161, &ok1391);
        if (!ok1391) return;
        slog::join_probe_old<3,3>($seq_atindex1368, $seq_atdelta1372, std::array<u64,3>{v_c162, v_c43, v_c147}, [&](const std::array<u64,3>& m1392) {
          slog::join_probe_old<3,3>($seq_atrindex1369, $seq_atrdelta1373, std::array<u64,3>{v_c163, v_c43, v_c147}, [&](const std::array<u64,3>& m1393) {
            slog::join_probe<2,1>(_enumindex1370, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1394) {
              u64 v_c165 = m1394[1];
              slog::join_all<1>(scheme_falseindex1371, [&](const std::array<u64,1>& m1395) {
                u64 v_c166 = m1395[0];
                if (v_c43 == v_c166) return;
                u64 v_c238 = _prim_llen(db, v_c167);
                if (v_c238 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c160 != v_c238) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c164});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c165}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1374* _cont = new ReadTask1374(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1374(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo3d3H593 __t76ef190 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo2ych592 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5WJE594 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4b4d595 __t76ef190 _00024seq2) (exists _enum (1 0) 1 __tconst5USv771) (join delta (1 2 0) 2 __tconst16Oe187 _00024seq2 __t4OrE188) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join prim (0 1) 1 __t76ef190 op) (letp _00024sql3Mb9587 (aslst _00024seq2)) (let chk0qNM1067 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk0qNM1067) (letp chk5d401068 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (eq __t76ef190 chk5d401068) (letp chk96Ar1069 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk96Ar1069)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask1405 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1396;  slog::Index** $seq_atrindex1397;  slog::Index** $seq_atrindex1398;  slog::Index** _enumindex1399;  slog::Index** deltaindex1400;  slog::Index** _enumindex1401;  slog::Index** primindex1402;  slog::Index** $seq_atrdelta1403;  slog::Index** $seq_atrdelta1404;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1406({1, 0, 2});
      slog::Relation* readrel1407 = db->getRelation("$seq_at");
      driver_index = readrel1407->getIndex(ord1406, true);
      std::vector<u16> ord1408({1, 0, 2});
      slog::Relation* readrel1409 = db->getRelation("$seq_at");
      $seq_atindex1396 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({1, 0, 2});
      slog::Relation* readrel1411 = db->getRelation("$seq_atr");
      $seq_atrindex1397 = readrel1411->getIndex(ord1410, false);
      std::vector<u16> ord1412({1, 0, 2});
      slog::Relation* readrel1413 = db->getRelation("$seq_atr");
      $seq_atrdelta1403 = readrel1413->getIndex(ord1412, true);
      std::vector<u16> ord1414({1, 0, 2});
      slog::Relation* readrel1415 = db->getRelation("$seq_atr");
      $seq_atrindex1398 = readrel1415->getIndex(ord1414, false);
      std::vector<u16> ord1416({1, 0, 2});
      slog::Relation* readrel1417 = db->getRelation("$seq_atr");
      $seq_atrdelta1404 = readrel1417->getIndex(ord1416, true);
      std::vector<u16> ord1418({1, 0});
      slog::Relation* readrel1419 = db->getRelation("_enum");
      _enumindex1399 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({1, 2, 0});
      slog::Relation* readrel1421 = db->getRelation("delta");
      deltaindex1400 = readrel1421->getIndex(ord1420, false);
      std::vector<u16> ord1422({1, 0});
      slog::Relation* readrel1423 = db->getRelation("_enum");
      _enumindex1401 = readrel1423->getIndex(ord1422, false);
      std::vector<u16> ord1424({0, 1});
      slog::Relation* readrel1425 = db->getRelation("prim");
      primindex1402 = readrel1425->getIndex(ord1424, false);
  
    }
    ReadTask1405(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c223 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c224 = v_const06abaa100ecef791ce028c56;
      u64 v_c225 = v_constd4735e3a265e16eee03f5971;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
      u64 v_c227 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c228 = v_const5feceb66ffc86f38d952786c;
      u64 v_c229 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c230 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c231 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c229, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1426) {
        u64 v_c234 = m1426[1];
        u64 v_c116 = m1426[2];
        if (buckethash(v_c234) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1396, std::array<u64,3>{v_c228, v_c234, v_c116}, [&](const std::array<u64,3>& m1427) {
          slog::join_probe_old<3,3>($seq_atrindex1397, $seq_atrdelta1403, std::array<u64,3>{v_c230, v_c234, v_c116}, [&](const std::array<u64,3>& m1428) {
            slog::join_probe_old<3,3>($seq_atrindex1398, $seq_atrdelta1404, std::array<u64,3>{v_c231, v_c234, v_c116}, [&](const std::array<u64,3>& m1429) {
              if (!slog::exists_probe<2,1>(_enumindex1399, std::array<u64,2>{v_c223, 0})) return;
              slog::join_probe<3,2>(deltaindex1400, std::array<u64,3>{v_c224, v_c116, 0}, [&](const std::array<u64,3>& m1430) {
                u64 v_c232 = m1430[2];
                slog::join_probe<2,1>(_enumindex1401, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1431) {
                  u64 v_c235 = m1431[1];
                  slog::join_probe<2,1>(primindex1402, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1432) {
                    u64 v_c30 = m1432[1];
                    bool ok1433 = true;
                    u64 v_c233 = _prim_aslst(db, v_c116, &ok1433);
                    if (!ok1433) return;
                    u64 v_c239 = _prim_llen(db, v_c233);
                    if (v_c239 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c225 != v_c239) return;
                    bool ok1434 = true;
                    u64 v_c240 = _prim_lref(db, v_c233, v_c226, &ok1434);
                    if (!ok1434) return;
                    if (v_c234 != v_c240) return;
                    bool ok1435 = true;
                    u64 v_c241 = _prim_lref(db, v_c233, v_c227, &ok1435);
                    if (!ok1435) return;
                    if (v_c234 != v_c241) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c232});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c235}, std::array<u16,2>{1, 0});
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
        ReadTask1405* _cont = new ReadTask1405(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1405(db,b), false);
  // (crule (pre (let __tconst22Ls722 const0122baa3ac55f1b433944eb1)) (scan temp41lW1120 __t1y17151) (body (join _enum (1 0) 1 __tconst22Ls722 __t5r57148) (join boolval (1 0) 1 __t5r57148 __t2W4B149)) (head (emit delta_ans (0 1) __t1y17151 __t2W4B149)) interp.slog:113 #f)
  class ReadTask1438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1436;  slog::Index** boolvalindex1437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1439({0, 1});
      slog::Relation* readrel1440 = db->getRelation("delta_ans");
      head_index[0] = readrel1440->getIndex(ord1439, false);
      outer_rel = db->getRelation("temp41lW1120");
      std::vector<u16> ord1441({1, 0});
      slog::Relation* readrel1442 = db->getRelation("_enum");
      _enumindex1436 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 0});
      slog::Relation* readrel1444 = db->getRelation("boolval");
      boolvalindex1437 = readrel1444->getIndex(ord1443, false);
  
    }
    ReadTask1438(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c243 = _t[0];
        slog::join_probe<2,1>(_enumindex1436, std::array<u64,2>{v_c242, 0}, [&](const std::array<u64,2>& m1445) {
          u64 v_c244 = m1445[1];
          slog::join_probe<2,1>(boolvalindex1437, std::array<u64,2>{v_c244, 0}, [&](const std::array<u64,2>& m1446) {
            u64 v_c245 = m1446[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c243, v_c245}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:temp41lW1120", _fires);
  
      if (!_done)
      {
        ReadTask1438* _cont = new ReadTask1438(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1438(db,b), false);
  // (crule (pre) (scan lookup __t3AMl16 x c) (body (join binding (0 1 2) 2 x c v)) (head (emit lookup_ans (0 1) __t3AMl16 v)) interp.slog:32 #f)
  class ReadTask1448 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex1447;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord1449({0, 1});
      slog::Relation* readrel1450 = db->getRelation("lookup_ans");
      head_index[0] = readrel1450->getIndex(ord1449, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord1451({0, 1, 2});
      slog::Relation* readrel1452 = db->getRelation("binding");
      bindingindex1447 = readrel1452->getIndex(ord1451, false);
  
    }
    ReadTask1448(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<3,2>(bindingindex1447, std::array<u64,3>{v_c15, v_c6, 0}, [&](const std::array<u64,3>& m1453) {
          u64 v_c43 = m1453[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c246, v_c43}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask1448* _cont = new ReadTask1448(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1448(db,b), false);
  // (crule (pre) (scan eval __t1DkM204 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t1DkM204) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t9lTe203) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t6XAE206 __t6hhS205 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask1483 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1454;  slog::Index** appindex1455;  slog::Index** eval_argsindex1456;  slog::Index** tickindex1457;  slog::Index** eval_ansindex1458;  slog::Index** $sup56712x41x0x0x0index1459;  slog::Index** appindex1460;  slog::Index** eval_argsindex1461;  slog::Index** evalindex1462;  slog::Index** appindex1463;  slog::Index** tickindex1464;  slog::Index** eval_argsindex1465;  slog::Index** eval_args_ansindex1466;  slog::Index** tickindex1467;  slog::Index** tick_ansindex1468;  slog::Index** eval_ansindex1469;  slog::Index** eval_args_ansindex1470;  slog::Index** tick_ansindex1471;  slog::Index** evalindex1472;  slog::Index** closureindex1473;  slog::Index** lambdaindex1474;  slog::Index** evalindex1475;  slog::Index** eval_ansindex1476;  slog::Index** appdelta1477;  slog::Index** eval_argsdelta1478;  slog::Index** tickdelta1479;  slog::Index** closuredelta1480;  slog::Index** lambdadelta1481;  slog::Index** evaldelta1482;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1484({0, 1});
      slog::Relation* readrel1485 = db->getRelation("eval_ans");
      head_index[0] = readrel1485->getIndex(ord1484, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1486({2, 0, 1});
      slog::Relation* readrel1487 = db->getRelation("eval");
      evalindex1454 = readrel1487->getIndex(ord1486, false);
      std::vector<u16> ord1488({1, 2, 0});
      slog::Relation* readrel1489 = db->getRelation("app");
      appindex1455 = readrel1489->getIndex(ord1488, false);
      std::vector<u16> ord1490({2, 0, 1});
      slog::Relation* readrel1491 = db->getRelation("eval_args");
      eval_argsindex1456 = readrel1491->getIndex(ord1490, false);
      std::vector<u16> ord1492({2, 0, 1});
      slog::Relation* readrel1493 = db->getRelation("tick");
      tickindex1457 = readrel1493->getIndex(ord1492, false);
      std::vector<u16> ord1494({0, 1});
      slog::Relation* readrel1495 = db->getRelation("eval_ans");
      eval_ansindex1458 = readrel1495->getIndex(ord1494, false);
      std::vector<u16> ord1496({1, 2, 3, 0});
      slog::Relation* readrel1497 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1459 = readrel1497->getIndex(ord1496, false);
      std::vector<u16> ord1498({1, 2, 0});
      slog::Relation* readrel1499 = db->getRelation("app");
      appindex1460 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({1, 2, 0});
      slog::Relation* readrel1501 = db->getRelation("eval_args");
      eval_argsindex1461 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({0, 2, 1});
      slog::Relation* readrel1503 = db->getRelation("eval");
      evalindex1462 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({0, 1, 2});
      slog::Relation* readrel1505 = db->getRelation("app");
      appindex1463 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({0, 1, 2});
      slog::Relation* readrel1507 = db->getRelation("app");
      appdelta1477 = readrel1507->getIndex(ord1506, true);
      std::vector<u16> ord1508({1, 2, 0});
      slog::Relation* readrel1509 = db->getRelation("tick");
      tickindex1464 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({1, 2, 0});
      slog::Relation* readrel1511 = db->getRelation("eval_args");
      eval_argsindex1465 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 2, 0});
      slog::Relation* readrel1513 = db->getRelation("eval_args");
      eval_argsdelta1478 = readrel1513->getIndex(ord1512, true);
      std::vector<u16> ord1514({0, 1});
      slog::Relation* readrel1515 = db->getRelation("eval_args_ans");
      eval_args_ansindex1466 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 2, 0});
      slog::Relation* readrel1517 = db->getRelation("tick");
      tickindex1467 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 2, 0});
      slog::Relation* readrel1519 = db->getRelation("tick");
      tickdelta1479 = readrel1519->getIndex(ord1518, true);
      std::vector<u16> ord1520({0, 1});
      slog::Relation* readrel1521 = db->getRelation("tick_ans");
      tick_ansindex1468 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({0, 1});
      slog::Relation* readrel1523 = db->getRelation("eval_ans");
      eval_ansindex1469 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({0, 1});
      slog::Relation* readrel1525 = db->getRelation("eval_args_ans");
      eval_args_ansindex1470 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({0, 1});
      slog::Relation* readrel1527 = db->getRelation("tick_ans");
      tick_ansindex1471 = readrel1527->getIndex(ord1526, false);
      std::vector<u16> ord1528({2, 0, 1});
      slog::Relation* readrel1529 = db->getRelation("eval");
      evalindex1472 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({0, 1, 2});
      slog::Relation* readrel1531 = db->getRelation("closure");
      closureindex1473 = readrel1531->getIndex(ord1530, false);
      std::vector<u16> ord1532({0, 1, 2});
      slog::Relation* readrel1533 = db->getRelation("closure");
      closuredelta1480 = readrel1533->getIndex(ord1532, true);
      std::vector<u16> ord1534({0, 1, 2});
      slog::Relation* readrel1535 = db->getRelation("lambda");
      lambdaindex1474 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({0, 1, 2});
      slog::Relation* readrel1537 = db->getRelation("lambda");
      lambdadelta1481 = readrel1537->getIndex(ord1536, true);
      std::vector<u16> ord1538({1, 2, 0});
      slog::Relation* readrel1539 = db->getRelation("eval");
      evalindex1475 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({1, 2, 0});
      slog::Relation* readrel1541 = db->getRelation("eval");
      evaldelta1482 = readrel1541->getIndex(ord1540, true);
      std::vector<u16> ord1542({0, 1});
      slog::Relation* readrel1543 = db->getRelation("eval_ans");
      eval_ansindex1476 = readrel1543->getIndex(ord1542, false);
  
    }
    ReadTask1483(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1454, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1455, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1456, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1457, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1458, std::array<u64,2>{v_c47, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1459, std::array<u64,4>{v_c6, v_c20, 0, 0}, [&](const std::array<u64,4>& m1544) {
          u64 v_c21 = m1544[2]; u64 v_c49 = m1544[3];
          if (!slog::exists_probe<3,2>(appindex1460, std::array<u64,3>{v_c20, v_c21, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex1461, std::array<u64,3>{v_c21, v_c6, 0})) return;
          slog::join_probe<3,2>(evalindex1462, std::array<u64,3>{v_c49, v_c6, 0}, [&](const std::array<u64,3>& m1545) {
            u64 v_c48 = m1545[2];
            slog::join_probe_old<3,3>(appindex1463, appdelta1477, std::array<u64,3>{v_c48, v_c20, v_c21}, [&](const std::array<u64,3>& m1546) {
              if (!slog::exists_probe<3,2>(tickindex1464, std::array<u64,3>{v_c48, v_c6, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex1465, eval_argsdelta1478, std::array<u64,3>{v_c21, v_c6, 0}, [&](const std::array<u64,3>& m1547) {
                u64 v_c50 = m1547[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1466, std::array<u64,2>{v_c50, 0})) return;
                slog::join_probe_old<3,2>(tickindex1467, tickdelta1479, std::array<u64,3>{v_c48, v_c6, 0}, [&](const std::array<u64,3>& m1548) {
                  u64 v_c44 = m1548[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1468, std::array<u64,2>{v_c44, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1469, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m1549) {
                    u64 v_c46 = m1549[1];
                    slog::join_probe<2,1>(eval_args_ansindex1470, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m1550) {
                      u64 v_c25 = m1550[1];
                      slog::join_probe<2,1>(tick_ansindex1471, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m1551) {
                        u64 v_c1 = m1551[1];
                        if (!slog::exists_probe<3,1>(evalindex1472, std::array<u64,3>{v_c1, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex1473, closuredelta1480, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m1552) {
                          u64 v_c45 = m1552[1]; u64 v_c18 = m1552[2];
                          slog::join_probe_old<3,1>(lambdaindex1474, lambdadelta1481, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m1553) {
                            u64 v_c26 = m1553[1]; u64 v_c27 = m1553[2];
                            slog::join_probe_old<3,2>(evalindex1475, evaldelta1482, std::array<u64,3>{v_c27, v_c1, 0}, [&](const std::array<u64,3>& m1554) {
                              u64 v_c42 = m1554[2];
                              slog::join_probe<2,1>(eval_ansindex1476, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m1555) {
                                u64 v_c43 = m1555[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask1483* _cont = new ReadTask1483(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1483(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e)) (scan temp3pOy1115 __t3xwX335 __t4CVz374 __t72Zs370 __t7Mqx355) (body (exists app (2 0 1) 1 __t7Mqx355) (exists num (1 0) 1 __tconst88d3359) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join app (1 2 0) 2 __t56Hj357 __t7Mqx355 __t5Ha7358) (join num (1 0) 1 __tconst88d3359 __t29aP337)) (head (emit-temp temp6QrZ1116 __t3xwX335 __t4CVz374 __t5Ha7358 __t72Zs370) (mkstruct if (1 3 2 0) __t6p3G371 __t72Zs370 __t5Ha7358 __t29aP337)) schemecfa.slog:12 #f)
  class ReadTask1561 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1556;  slog::Index** numindex1557;  slog::Index** refindex1558;  slog::Index** appindex1559;  slog::Index** numindex1560;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6QrZ1116");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp3pOy1115");
      std::vector<u16> ord1562({2, 0, 1});
      slog::Relation* readrel1563 = db->getRelation("app");
      appindex1556 = readrel1563->getIndex(ord1562, false);
      std::vector<u16> ord1564({1, 0});
      slog::Relation* readrel1565 = db->getRelation("num");
      numindex1557 = readrel1565->getIndex(ord1564, false);
      std::vector<u16> ord1566({1, 0});
      slog::Relation* readrel1567 = db->getRelation("ref");
      refindex1558 = readrel1567->getIndex(ord1566, false);
      std::vector<u16> ord1568({1, 2, 0});
      slog::Relation* readrel1569 = db->getRelation("app");
      appindex1559 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({1, 0});
      slog::Relation* readrel1571 = db->getRelation("num");
      numindex1560 = readrel1571->getIndex(ord1570, false);
  
    }
    ReadTask1561(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c247 = v_consta81ad7556291f9defc5163ec;
      u64 v_c248 = v_consted725292f5f32d61535958c1;
      u64 v_c249 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c250 = _t[0];
        u64 v_c251 = _t[1];
        u64 v_c252 = _t[2];
        u64 v_c253 = _t[3];
        if (!slog::exists_probe<3,1>(appindex1556, std::array<u64,3>{v_c253, 0, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1557, std::array<u64,2>{v_c249, 0})) return;
        slog::join_probe<2,1>(refindex1558, std::array<u64,2>{v_c248, 0}, [&](const std::array<u64,2>& m1572) {
          u64 v_c254 = m1572[1];
          slog::join_probe<3,2>(appindex1559, std::array<u64,3>{v_c254, v_c253, 0}, [&](const std::array<u64,3>& m1573) {
            u64 v_c255 = m1573[2];
            slog::join_probe<2,1>(numindex1560, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m1574) {
              u64 v_c256 = m1574[1];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c250, v_c251, v_c255, v_c252});
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c252, v_c255, v_c256}, std::array<u16,4>{1, 3, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp3pOy1115", _fires);
  
      if (!_done)
      {
        ReadTask1561* _cont = new ReadTask1561(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1561(db,b), false);
  // (crule (pre) (scan eval __t9p2a295 er c) (body (exists letrec (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t9p2a295) (join $sup56712x93x0x0x0 (1 3 0 2 4) 2 c er __t5OlD294 eb x) (exists eval (0 2 1) 2 __t5OlD294 c) (exists eval (1 2 0) 2 eb c) (join letrec (2 1 3 0) 3 er x eb __t0H7q293) (join eval (0 2 1) 3 __t5OlD294 c __t0H7q293) (join-old eval (1 2 0) 2 (1 2 0) eb c __t32yp296) (exists eval_ans (0 1) 1 __t32yp296) (join eval_ans (0 1) 1 __t9p2a295 vr) (join eval_ans (0 1) 1 __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask1588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1575;  slog::Index** evalindex1576;  slog::Index** eval_ansindex1577;  slog::Index** $sup56712x93x0x0x0index1578;  slog::Index** evalindex1579;  slog::Index** evalindex1580;  slog::Index** letrecindex1581;  slog::Index** evalindex1582;  slog::Index** evalindex1583;  slog::Index** eval_ansindex1584;  slog::Index** eval_ansindex1585;  slog::Index** eval_ansindex1586;  slog::Index** evaldelta1587;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1589({0, 1});
      slog::Relation* readrel1590 = db->getRelation("eval_ans");
      head_index[0] = readrel1590->getIndex(ord1589, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1591({2, 1, 3, 0});
      slog::Relation* readrel1592 = db->getRelation("letrec");
      letrecindex1575 = readrel1592->getIndex(ord1591, false);
      std::vector<u16> ord1593({2, 0, 1});
      slog::Relation* readrel1594 = db->getRelation("eval");
      evalindex1576 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({0, 1});
      slog::Relation* readrel1596 = db->getRelation("eval_ans");
      eval_ansindex1577 = readrel1596->getIndex(ord1595, false);
      std::vector<u16> ord1597({1, 3, 0, 2, 4});
      slog::Relation* readrel1598 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index1578 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({0, 2, 1});
      slog::Relation* readrel1600 = db->getRelation("eval");
      evalindex1579 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({1, 2, 0});
      slog::Relation* readrel1602 = db->getRelation("eval");
      evalindex1580 = readrel1602->getIndex(ord1601, false);
      std::vector<u16> ord1603({2, 1, 3, 0});
      slog::Relation* readrel1604 = db->getRelation("letrec");
      letrecindex1581 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({0, 2, 1});
      slog::Relation* readrel1606 = db->getRelation("eval");
      evalindex1582 = readrel1606->getIndex(ord1605, false);
      std::vector<u16> ord1607({1, 2, 0});
      slog::Relation* readrel1608 = db->getRelation("eval");
      evalindex1583 = readrel1608->getIndex(ord1607, false);
      std::vector<u16> ord1609({1, 2, 0});
      slog::Relation* readrel1610 = db->getRelation("eval");
      evaldelta1587 = readrel1610->getIndex(ord1609, true);
      std::vector<u16> ord1611({0, 1});
      slog::Relation* readrel1612 = db->getRelation("eval_ans");
      eval_ansindex1584 = readrel1612->getIndex(ord1611, false);
      std::vector<u16> ord1613({0, 1});
      slog::Relation* readrel1614 = db->getRelation("eval_ans");
      eval_ansindex1585 = readrel1614->getIndex(ord1613, false);
      std::vector<u16> ord1615({0, 1});
      slog::Relation* readrel1616 = db->getRelation("eval_ans");
      eval_ansindex1586 = readrel1616->getIndex(ord1615, false);
  
    }
    ReadTask1588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<4,1>(letrecindex1575, std::array<u64,4>{v_c61, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1576, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1577, std::array<u64,2>{v_c180, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index1578, std::array<u64,5>{v_c6, v_c61, 0, 0, 0}, [&](const std::array<u64,5>& m1617) {
          u64 v_c178 = m1617[2]; u64 v_c27 = m1617[3]; u64 v_c15 = m1617[4];
          if (!slog::exists_probe<3,2>(evalindex1579, std::array<u64,3>{v_c178, v_c6, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex1580, std::array<u64,3>{v_c27, v_c6, 0})) return;
          slog::join_probe<4,3>(letrecindex1581, std::array<u64,4>{v_c61, v_c15, v_c27, 0}, [&](const std::array<u64,4>& m1618) {
            u64 v_c179 = m1618[3];
            slog::join_probe<3,3>(evalindex1582, std::array<u64,3>{v_c178, v_c6, v_c179}, [&](const std::array<u64,3>& m1619) {
              slog::join_probe_old<3,2>(evalindex1583, evaldelta1587, std::array<u64,3>{v_c27, v_c6, 0}, [&](const std::array<u64,3>& m1620) {
                u64 v_c181 = m1620[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1584, std::array<u64,2>{v_c181, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1585, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m1621) {
                  u64 v_c64 = m1621[1];
                  slog::join_probe<2,1>(eval_ansindex1586, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m1622) {
                    u64 v_c43 = m1622[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c178, v_c43}, std::array<u16,2>{0, 1});
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
        ReadTask1588* _cont = new ReadTask1588(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1588(db,b), false);
  // (crule (pre (let __tconst4VQK721 constb9e118781cea1f9fa01462e0) (let __tconst22Ls722 const0122baa3ac55f1b433944eb1) (let __tconst5lFL150 const60e3114d9b4b6577eea8cbc0) (let _00024sqc6U6L608 const6b86b273ff34fce19d6b804e) (let _00024sqc4sFX609 const5feceb66ffc86f38d952786c) (let _00024sqo2S6J610 const5feceb66ffc86f38d952786c) (let _00024sqo0Kwi611 const5feceb66ffc86f38d952786c)) (scan boolval __t9y9U153 __t0cMr152) (body (join _enum (0 1) 2 __t0cMr152 __tconst4VQK721) (exists $seq_atr (1 0 2) 2 _00024sqo0Kwi611 __t9y9U153) (exists delta (1 2 0) 1 __tconst5lFL150) (exists _enum (1 0) 1 __tconst22Ls722) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo2S6J610 __t9y9U153 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0Kwi611 __t9y9U153 _00024seq1) (join delta (1 2 0) 2 __tconst5lFL150 _00024seq1 __t1y17151) (join _enum (1 0) 1 __tconst22Ls722 __t5r57148) (letp _00024sql06hQ606 (aslst _00024seq1)) (let chk59yh1122 (llen _00024sql06hQ606)) (eq _00024sqc6U6L608 chk59yh1122) (letp chk8kyv1123 (lref _00024sql06hQ606 _00024sqc4sFX609)) (eq __t9y9U153 chk8kyv1123)) (head (emit-temp temp41lW1120 __t1y17151) (mkstruct boolval (1 0) __t2W4B149 __t5r57148)) interp.slog:113 #f)
  class ReadTask1633 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1623;  slog::Index** $seq_atrindex1624;  slog::Index** deltaindex1625;  slog::Index** _enumindex1626;  slog::Index** $seq_atindex1627;  slog::Index** $seq_atrindex1628;  slog::Index** deltaindex1629;  slog::Index** _enumindex1630;  slog::Index** $seq_atdelta1631;  slog::Index** $seq_atrdelta1632;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp41lW1120");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord1634({0, 1});
      slog::Relation* readrel1635 = db->getRelation("_enum");
      _enumindex1623 = readrel1635->getIndex(ord1634, false);
      std::vector<u16> ord1636({1, 0, 2});
      slog::Relation* readrel1637 = db->getRelation("$seq_atr");
      $seq_atrindex1624 = readrel1637->getIndex(ord1636, false);
      std::vector<u16> ord1638({1, 2, 0});
      slog::Relation* readrel1639 = db->getRelation("delta");
      deltaindex1625 = readrel1639->getIndex(ord1638, false);
      std::vector<u16> ord1640({1, 0});
      slog::Relation* readrel1641 = db->getRelation("_enum");
      _enumindex1626 = readrel1641->getIndex(ord1640, false);
      std::vector<u16> ord1642({1, 0, 2});
      slog::Relation* readrel1643 = db->getRelation("$seq_at");
      $seq_atindex1627 = readrel1643->getIndex(ord1642, false);
      std::vector<u16> ord1644({1, 0, 2});
      slog::Relation* readrel1645 = db->getRelation("$seq_at");
      $seq_atdelta1631 = readrel1645->getIndex(ord1644, true);
      std::vector<u16> ord1646({1, 0, 2});
      slog::Relation* readrel1647 = db->getRelation("$seq_atr");
      $seq_atrindex1628 = readrel1647->getIndex(ord1646, false);
      std::vector<u16> ord1648({1, 0, 2});
      slog::Relation* readrel1649 = db->getRelation("$seq_atr");
      $seq_atrdelta1632 = readrel1649->getIndex(ord1648, true);
      std::vector<u16> ord1650({1, 2, 0});
      slog::Relation* readrel1651 = db->getRelation("delta");
      deltaindex1629 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 0});
      slog::Relation* readrel1653 = db->getRelation("_enum");
      _enumindex1630 = readrel1653->getIndex(ord1652, false);
  
    }
    ReadTask1633(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c257 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c242 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c258 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c259 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c260 = v_const5feceb66ffc86f38d952786c;
      u64 v_c261 = v_const5feceb66ffc86f38d952786c;
      u64 v_c262 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c263 = _t[0];
        u64 v_c264 = _t[1];
        slog::join_probe<2,2>(_enumindex1623, std::array<u64,2>{v_c264, v_c257}, [&](const std::array<u64,2>& m1654) {
          if (!slog::exists_probe<3,2>($seq_atrindex1624, std::array<u64,3>{v_c262, v_c263, 0})) return;
          if (!slog::exists_probe<3,1>(deltaindex1625, std::array<u64,3>{v_c258, 0, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex1626, std::array<u64,2>{v_c242, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex1627, $seq_atdelta1631, std::array<u64,3>{v_c261, v_c263, 0}, [&](const std::array<u64,3>& m1655) {
            u64 v_c148 = m1655[2];
            slog::join_probe_old<3,3>($seq_atrindex1628, $seq_atrdelta1632, std::array<u64,3>{v_c262, v_c263, v_c148}, [&](const std::array<u64,3>& m1656) {
              slog::join_probe<3,2>(deltaindex1629, std::array<u64,3>{v_c258, v_c148, 0}, [&](const std::array<u64,3>& m1657) {
                u64 v_c243 = m1657[2];
                slog::join_probe<2,1>(_enumindex1630, std::array<u64,2>{v_c242, 0}, [&](const std::array<u64,2>& m1658) {
                  u64 v_c244 = m1658[1];
                  bool ok1659 = true;
                  u64 v_c265 = _prim_aslst(db, v_c148, &ok1659);
                  if (!ok1659) return;
                  u64 v_c266 = _prim_llen(db, v_c265);
                  if (v_c266 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c259 != v_c266) return;
                  bool ok1660 = true;
                  u64 v_c267 = _prim_lref(db, v_c265, v_c260, &ok1660);
                  if (!ok1660) return;
                  if (v_c263 != v_c267) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c243});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c244}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask1633* _cont = new ReadTask1633(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1633(db,b), false);
  // (crule (pre (let __t2ytA435 (lempty))) (scan lst_take_ans __t1Al3438 __v0) (body (join-old lst_take (0 1 2) 1 (0 1 2) __t1Al3438 __t2jGw437 m) (join mlimit (0) 1 m) (join-old tick (0 2 1) 0 (0 2 1) __t6dFG434 c site) (let __t33cB436 (lpush __t2ytA435 site)) (let chk4rud1164 (lcat __t33cB436 c)) (eq __t2jGw437 chk4rud1164)) (head (emit tick_ans (0 1) __t6dFG434 __v0)) context.slog:10 #f)
  class ReadTask1666 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_takeindex1661;  slog::Index** mlimitindex1662;  slog::Index** tickindex1663;  slog::Index** lst_takedelta1664;  slog::Index** tickdelta1665;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord1667({0, 1});
      slog::Relation* readrel1668 = db->getRelation("tick_ans");
      head_index[0] = readrel1668->getIndex(ord1667, false);
      outer_rel = db->getRelation("lst_take_ans");
      std::vector<u16> ord1669({0, 1, 2});
      slog::Relation* readrel1670 = db->getRelation("lst_take");
      lst_takeindex1661 = readrel1670->getIndex(ord1669, false);
      std::vector<u16> ord1671({0, 1, 2});
      slog::Relation* readrel1672 = db->getRelation("lst_take");
      lst_takedelta1664 = readrel1672->getIndex(ord1671, true);
      std::vector<u16> ord1673({0});
      slog::Relation* readrel1674 = db->getRelation("mlimit");
      mlimitindex1662 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({0, 2, 1});
      slog::Relation* readrel1676 = db->getRelation("tick");
      tickindex1663 = readrel1676->getIndex(ord1675, false);
      std::vector<u16> ord1677({0, 2, 1});
      slog::Relation* readrel1678 = db->getRelation("tick");
      tickdelta1665 = readrel1678->getIndex(ord1677, true);
  
    }
    ReadTask1666(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c268 = _prim_lempty(db);
      if (v_c268 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c269 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<3,1>(lst_takeindex1661, lst_takedelta1664, std::array<u64,3>{v_c269, 0, 0}, [&](const std::array<u64,3>& m1679) {
          u64 v_c270 = m1679[1]; u64 v_c177 = m1679[2];
          slog::join_probe<1,1>(mlimitindex1662, std::array<u64,1>{v_c177}, [&](const std::array<u64,1>& m1680) {
            slog::join_all_old<3>(tickindex1663, tickdelta1665, [&](const std::array<u64,3>& m1681) {
              u64 v_c271 = m1681[0]; u64 v_c6 = m1681[1]; u64 v_c272 = m1681[2];
              u64 v_c273 = _prim_lpush(db, v_c268, v_c272);
              if (v_c273 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              u64 v_c274 = _prim_lcat(db, v_c273, v_c6);
              if (v_c274 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              if (v_c270 != v_c274) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c271, v_c1}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:lst_take_ans", _fires);
  
      if (!_done)
      {
        ReadTask1666* _cont = new ReadTask1666(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1666(db,b), false);
  // (crule (pre) (scan freevar y __t75gL192) (body (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t75gL192 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __36hc798 c __t36c5191) (join-old app (0 1 2) 1 (0 1 2) __t36c5191 ef es)) (head (mkstruct eval_args (1 2 0) __9QEA799 es c)) interp.slog:56 #f)
  class ReadTask1689 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex1682;  slog::Index** lambdaindex1683;  slog::Index** evalindex1684;  slog::Index** appindex1685;  slog::Index** lambdadelta1686;  slog::Index** evaldelta1687;  slog::Index** appdelta1688;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1690({0, 1, 2});
      slog::Relation* readrel1691 = db->getRelation("binding");
      bindingindex1682 = readrel1691->getIndex(ord1690, false);
      std::vector<u16> ord1692({0, 1, 2});
      slog::Relation* readrel1693 = db->getRelation("lambda");
      lambdaindex1683 = readrel1693->getIndex(ord1692, false);
      std::vector<u16> ord1694({0, 1, 2});
      slog::Relation* readrel1695 = db->getRelation("lambda");
      lambdadelta1686 = readrel1695->getIndex(ord1694, true);
      std::vector<u16> ord1696({0, 2, 1});
      slog::Relation* readrel1697 = db->getRelation("eval");
      evalindex1684 = readrel1697->getIndex(ord1696, false);
      std::vector<u16> ord1698({0, 2, 1});
      slog::Relation* readrel1699 = db->getRelation("eval");
      evaldelta1687 = readrel1699->getIndex(ord1698, true);
      std::vector<u16> ord1700({0, 1, 2});
      slog::Relation* readrel1701 = db->getRelation("app");
      appindex1685 = readrel1701->getIndex(ord1700, false);
      std::vector<u16> ord1702({0, 1, 2});
      slog::Relation* readrel1703 = db->getRelation("app");
      appdelta1688 = readrel1703->getIndex(ord1702, true);
  
    }
    ReadTask1689(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c275 = _t[1];
        slog::join_probe<3,1>(bindingindex1682, std::array<u64,3>{v_c195, 0, 0}, [&](const std::array<u64,3>& m1704) {
          u64 v_c18 = m1704[1]; u64 v_c197 = m1704[2];
          slog::join_probe_old<3,1>(lambdaindex1683, lambdadelta1686, std::array<u64,3>{v_c275, 0, 0}, [&](const std::array<u64,3>& m1705) {
            u64 v_c26 = m1705[1]; u64 v_c27 = m1705[2];
            slog::join_all_old<3>(evalindex1684, evaldelta1687, [&](const std::array<u64,3>& m1706) {
              u64 v_c276 = m1706[0]; u64 v_c6 = m1706[1]; u64 v_c277 = m1706[2];
              slog::join_probe_old<3,1>(appindex1685, appdelta1688, std::array<u64,3>{v_c277, 0, 0}, [&](const std::array<u64,3>& m1707) {
                u64 v_c20 = m1707[1]; u64 v_c21 = m1707[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c6}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1689* _cont = new ReadTask1689(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1689(db,b), false);
  // (crule (pre) (scan freevar x eb) (body (join-old letrec (3 0 1 2) 1 (3 0 1 2) eb __t3qWc160 y er) (neq x y)) (head (emit freevar (0 1) x __t3qWc160)) freevars.slog:24 #f)
  class ReadTask1710 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1708;  slog::Index** letrecdelta1709;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1711({0, 1});
      slog::Relation* readrel1712 = db->getRelation("freevar");
      head_index[0] = readrel1712->getIndex(ord1711, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1713({3, 0, 1, 2});
      slog::Relation* readrel1714 = db->getRelation("letrec");
      letrecindex1708 = readrel1714->getIndex(ord1713, false);
      std::vector<u16> ord1715({3, 0, 1, 2});
      slog::Relation* readrel1716 = db->getRelation("letrec");
      letrecdelta1709 = readrel1716->getIndex(ord1715, true);
  
    }
    ReadTask1710(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        slog::join_probe_old<4,1>(letrecindex1708, letrecdelta1709, std::array<u64,4>{v_c27, 0, 0, 0}, [&](const std::array<u64,4>& m1717) {
          u64 v_c278 = m1717[1]; u64 v_c195 = m1717[2]; u64 v_c61 = m1717[3];
          if (v_c15 == v_c195) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c278}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1710* _cont = new ReadTask1710(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1710(db,b), false);
}

