
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const1fb680aa1ed965bc09f024ab;
extern u64 v_const25f568921d120de09a5f575d;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
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
extern u64 v_constf6cdc3db4b71e0cdeda6912e;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_c37fb0286fb46e883(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan $sup56712x93x0x0x0 __t3Qfa308 c eb er x) (body (exists eval (0 2 1) 2 __t3Qfa308 c) (exists eval (1 2 0) 2 er c) (exists eval (1 2 0) 2 eb c) (join letrec (2 1 3 0) 3 er x eb __t8pF7307) (join-old eval (0 2 1) 3 (0 2 1) __t3Qfa308 c __t8pF7307) (join-old eval (1 2 0) 2 (1 2 0) er c __t8bEj309) (exists eval_ans (0 1) 1 __t8bEj309) (join-old eval (1 2 0) 2 (1 2 0) eb c __t8NjM310) (exists eval_ans (0 1) 1 __t8NjM310) (join eval_ans (0 1) 1 __t8bEj309 vr) (join eval_ans (0 1) 1 __t8NjM310 v)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** evalindex1;  slog::Index** evalindex2;  slog::Index** letrecindex3;  slog::Index** evalindex4;  slog::Index** evalindex5;  slog::Index** eval_ansindex6;  slog::Index** evalindex7;  slog::Index** eval_ansindex8;  slog::Index** eval_ansindex9;  slog::Index** eval_ansindex10;  slog::Index** evaldelta11;  slog::Index** evaldelta12;  slog::Index** evaldelta13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("eval_ans");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord17({0, 2, 1});
      slog::Relation* readrel18 = db->getRelation("eval");
      evalindex0 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("eval");
      evalindex1 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("eval");
      evalindex2 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 1, 3, 0});
      slog::Relation* readrel24 = db->getRelation("letrec");
      letrecindex3 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 2, 1});
      slog::Relation* readrel26 = db->getRelation("eval");
      evalindex4 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({0, 2, 1});
      slog::Relation* readrel28 = db->getRelation("eval");
      evaldelta11 = readrel28->getIndex(ord27, true);
      std::vector<u16> ord29({1, 2, 0});
      slog::Relation* readrel30 = db->getRelation("eval");
      evalindex5 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("eval");
      evaldelta12 = readrel32->getIndex(ord31, true);
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("eval_ans");
      eval_ansindex6 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 0});
      slog::Relation* readrel36 = db->getRelation("eval");
      evalindex7 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("eval");
      evaldelta13 = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("eval_ans");
      eval_ansindex8 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("eval_ans");
      eval_ansindex9 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("eval_ans");
      eval_ansindex10 = readrel44->getIndex(ord43, false);
  
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex0, std::array<u64,3>{v_c0, v_c1, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1, std::array<u64,3>{v_c3, v_c1, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex2, std::array<u64,3>{v_c2, v_c1, 0})) return;
        slog::join_probe<4,3>(letrecindex3, std::array<u64,4>{v_c3, v_c4, v_c2, 0}, [&](const std::array<u64,4>& m45) {
          u64 v_c5 = m45[3];
          slog::join_probe_old<3,3>(evalindex4, evaldelta11, std::array<u64,3>{v_c0, v_c1, v_c5}, [&](const std::array<u64,3>& m46) {
            slog::join_probe_old<3,2>(evalindex5, evaldelta12, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m47) {
              u64 v_c6 = m47[2];
              if (!slog::exists_probe<2,1>(eval_ansindex6, std::array<u64,2>{v_c6, 0})) return;
              slog::join_probe_old<3,2>(evalindex7, evaldelta13, std::array<u64,3>{v_c2, v_c1, 0}, [&](const std::array<u64,3>& m48) {
                u64 v_c7 = m48[2];
                if (!slog::exists_probe<2,1>(eval_ansindex8, std::array<u64,2>{v_c7, 0})) return;
                slog::join_probe<2,1>(eval_ansindex9, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m49) {
                  u64 v_c8 = m49[1];
                  slog::join_probe<2,1>(eval_ansindex10, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m50) {
                    u64 v_c9 = m50[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c9}, std::array<u16,2>{0, 1});
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
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst59e9288 const1fb680aa1ed965bc09f024ab) (let __tconst2I8h285 const7297d2085ea0adffc396d546) (let __tconst4QwH278 const6b86b273ff34fce19d6b804e) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst8lfC272 const90edba1c9d0bb14ec514a96c) (let __tconst48zw269 const0933fb667296882d8c45abca) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst16Fs254 const879923da020d1533f4d8e921) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst7F8v233 const53a56174f3826669a422fc54) (let __tconst85km226 constd4735e3a265e16eee03f5971) (let __tconst9HGv215 const7902699be42c8a8e46fbbb45) (let __t5yWE289 (lempty))) (once) (body) (head (emit-temp temp5WmB960 __t5yWE289) (mkstruct ref (1 0) __t5wDB286 __tconst2I8h285) (mkstruct ref (1 0) __t66Mu281 __tconst59e9288) (mkstruct ref (1 0) __t7uwu270 __tconst48zw269) (mkstruct ref (1 0) __t9LjS265 __tconst8lfC272) (mkstruct ref (1 0) __t54jO250 __tconst16Fs254) (mkstruct ref (1 0) __t1waL248 __tconst39ZW253) (mkstruct ref (1 0) __t7SX3246 __tconst6YSZ252) (mkstruct ref (1 0) __t41cT241 __tconst4aTz260) (mkstruct ref (1 0) __t3grR234 __tconst7F8v233) (mkstruct num (1 0) __t3YP0229 __tconst4QwH278) (mkstruct num (1 0) __t7w2Z227 __tconst85km226) (mkstruct ref (1 0) __t1iN7225 __tconst7wlx292) (mkstruct ref (1 0) __t55Yd223 __tconst2XD5276) (mkstruct ref (1 0) __t8Ely220 __tconst7Bar243) (mkstruct num (1 0) __t3mP4216 __tconst9HGv215)) analysis-demo.slog:21 #f)
  class ReadTask51 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[16];
    slog::Index** head_index[16];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5WmB960");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("ref");
      head_rel[8] = db->getRelation("ref");
      head_rel[9] = db->getRelation("ref");
      head_rel[10] = db->getRelation("num");
      head_rel[11] = db->getRelation("num");
      head_rel[12] = db->getRelation("ref");
      head_rel[13] = db->getRelation("ref");
      head_rel[14] = db->getRelation("ref");
      head_rel[15] = db->getRelation("num");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c11 = v_const1fb680aa1ed965bc09f024ab;
      u64 v_c12 = v_const7297d2085ea0adffc396d546;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constf77801bebb40767a1b303d97;
      u64 v_c15 = v_const90edba1c9d0bb14ec514a96c;
      u64 v_c16 = v_const0933fb667296882d8c45abca;
      u64 v_c17 = v_const829935b42173b360da35f679;
      u64 v_c18 = v_const879923da020d1533f4d8e921;
      u64 v_c19 = v_const8ca5d81566f88badd698137a;
      u64 v_c20 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c21 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c22 = v_const53a56174f3826669a422fc54;
      u64 v_c23 = v_constd4735e3a265e16eee03f5971;
      u64 v_c24 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c25 = _prim_lempty(db);
      if (v_c25 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[16];
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
      newbatch[14] = new slog::InsertBatch();
      newbatch[15] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c25});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[9], newbatch[9], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[10], newbatch[10], std::array<u64,1>{v_c13}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[11], newbatch[11], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[12], newbatch[12], std::array<u64,1>{v_c10}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[13], newbatch[13], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[14], newbatch[14], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[15], newbatch[15], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
  
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
        head_rel[14]->sendBatch(newbatch[14]);
        head_rel[15]->sendBatch(newbatch[15]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), true);
  // (crule (pre (let __t5FX9367 (lempty))) (scan tick __t18ya366 site c) (body (join mlimit (0) 0 m) (let __t70Q4368 (lpush __t5FX9367 site)) (let __t82mC369 (lcat __t70Q4368 c)) (join-old lst_take (1 2 0) 2 (1 2 0) __t82mC369 m __t7KjH370) (join lst_take_ans (0 1) 1 __t7KjH370 __v0)) (head (emit tick_ans (0 1) __t18ya366 __v0)) context.slog:10 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex52;  slog::Index** lst_takeindex53;  slog::Index** lst_take_ansindex54;  slog::Index** lst_takedelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("tick_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord59({0});
      slog::Relation* readrel60 = db->getRelation("mlimit");
      mlimitindex52 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("lst_take");
      lst_takeindex53 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("lst_take");
      lst_takedelta55 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("lst_take_ans");
      lst_take_ansindex54 = readrel66->getIndex(ord65, false);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = _prim_lempty(db);
      if (v_c26 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
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
        u64 v_c1 = _t[2];
        slog::join_all<1>(mlimitindex52, [&](const std::array<u64,1>& m67) {
          u64 v_c29 = m67[0];
          u64 v_c30 = _prim_lpush(db, v_c26, v_c28);
          if (v_c30 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
          u64 v_c31 = _prim_lcat(db, v_c30, v_c1);
          if (v_c31 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
          slog::join_probe_old<3,2>(lst_takeindex53, lst_takedelta55, std::array<u64,3>{v_c31, v_c29, 0}, [&](const std::array<u64,3>& m68) {
            u64 v_c32 = m68[2];
            slog::join_probe<2,1>(lst_take_ansindex54, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m69) {
              u64 v_c33 = m69[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c27, v_c33}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:tick", _fires);
  
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
  // (crule (pre) (scan app __t3Fr129 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t3Fr129) (join eval (1 2 0) 1 __t3Fr129 c __64BN675) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t3Fr129 c) (join eval (1 2 0) 2 ef c __t84Ji24) (exists eval_ans (0 1) 1 __t84Ji24) (join eval_args (1 2 0) 2 es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join tick_ans (0 1) 1 __t0NvE30 l) (join closure (0 1 2) 1 __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join lambda (0 1 2) 1 __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask91 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex70;  slog::Index** eval_argsindex71;  slog::Index** tickindex72;  slog::Index** evalindex73;  slog::Index** eval_argsindex74;  slog::Index** tickindex75;  slog::Index** evalindex76;  slog::Index** eval_ansindex77;  slog::Index** eval_argsindex78;  slog::Index** eval_args_ansindex79;  slog::Index** tickindex80;  slog::Index** tick_ansindex81;  slog::Index** eval_ansindex82;  slog::Index** eval_args_ansindex83;  slog::Index** tick_ansindex84;  slog::Index** closureindex85;  slog::Index** bindingindex86;  slog::Index** freevarindex87;  slog::Index** bindingindex88;  slog::Index** lambdaindex89;  slog::Index** tickdelta90;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord92({0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("binding");
      head_index[0] = readrel93->getIndex(ord92, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("binding_event");
      head_index[1] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("eval");
      evalindex70 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 2, 0});
      slog::Relation* readrel99 = db->getRelation("eval_args");
      eval_argsindex71 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("tick");
      tickindex72 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 2, 0});
      slog::Relation* readrel103 = db->getRelation("eval");
      evalindex73 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("eval_args");
      eval_argsindex74 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 0});
      slog::Relation* readrel107 = db->getRelation("tick");
      tickindex75 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("eval");
      evalindex76 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({0, 1});
      slog::Relation* readrel111 = db->getRelation("eval_ans");
      eval_ansindex77 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("eval_args");
      eval_argsindex78 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("eval_args_ans");
      eval_args_ansindex79 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("tick");
      tickindex80 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("tick");
      tickdelta90 = readrel119->getIndex(ord118, true);
      std::vector<u16> ord120({0, 1});
      slog::Relation* readrel121 = db->getRelation("tick_ans");
      tick_ansindex81 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("eval_ans");
      eval_ansindex82 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("eval_args_ans");
      eval_args_ansindex83 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1});
      slog::Relation* readrel127 = db->getRelation("tick_ans");
      tick_ansindex84 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 1, 2});
      slog::Relation* readrel129 = db->getRelation("closure");
      closureindex85 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0, 2});
      slog::Relation* readrel131 = db->getRelation("binding");
      bindingindex86 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("freevar");
      freevarindex87 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1, 2});
      slog::Relation* readrel135 = db->getRelation("binding");
      bindingindex88 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1, 2});
      slog::Relation* readrel137 = db->getRelation("lambda");
      lambdaindex89 = readrel137->getIndex(ord136, false);
  
    }
    ReadTask91(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex70, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex71, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex72, std::array<u64,3>{v_c34, 0, 0})) return;
        slog::join_probe<3,1>(evalindex73, std::array<u64,3>{v_c34, 0, 0}, [&](const std::array<u64,3>& m138) {
          u64 v_c1 = m138[1]; u64 v_c37 = m138[2];
          if (!slog::exists_probe<3,2>(eval_argsindex74, std::array<u64,3>{v_c36, v_c1, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex75, std::array<u64,3>{v_c34, v_c1, 0})) return;
          slog::join_probe<3,2>(evalindex76, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m139) {
            u64 v_c38 = m139[2];
            if (!slog::exists_probe<2,1>(eval_ansindex77, std::array<u64,2>{v_c38, 0})) return;
            slog::join_probe<3,2>(eval_argsindex78, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m140) {
              u64 v_c39 = m140[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex79, std::array<u64,2>{v_c39, 0})) return;
              slog::join_probe_old<3,2>(tickindex80, tickdelta90, std::array<u64,3>{v_c34, v_c1, 0}, [&](const std::array<u64,3>& m141) {
                u64 v_c40 = m141[2];
                if (!slog::exists_probe<2,1>(tick_ansindex81, std::array<u64,2>{v_c40, 0})) return;
                slog::join_probe<2,1>(eval_ansindex82, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m142) {
                  u64 v_c41 = m142[1];
                  slog::join_probe<2,1>(eval_args_ansindex83, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m143) {
                    u64 v_c42 = m143[1];
                    slog::join_probe<2,1>(tick_ansindex84, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m144) {
                      u64 v_c43 = m144[1];
                      slog::join_probe<3,1>(closureindex85, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m145) {
                        u64 v_c44 = m145[1]; u64 v_c45 = m145[2];
                        if (!slog::exists_probe<3,1>(bindingindex86, std::array<u64,3>{v_c45, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex87, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m146) {
                          u64 v_c46 = m146[1];
                          slog::join_probe<3,2>(bindingindex88, std::array<u64,3>{v_c46, v_c45, 0}, [&](const std::array<u64,3>& m147) {
                            u64 v_c47 = m147[2];
                            slog::join_probe<3,1>(lambdaindex89, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m148) {
                              u64 v_c48 = m148[1]; u64 v_c2 = m148[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c46, v_c43, v_c47}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c46, v_c43, v_c1}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask91* _cont = new ReadTask91(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask91(db,b), false);
  // (crule (pre) (scan eval_ans __t8NjM310 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t8NjM310 c eb) (exists letrec (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (join-old $sup56712x93x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c eb __t3Qfa308 er x) (exists eval (0 2 1) 2 __t3Qfa308 c) (exists eval (1 2 0) 2 er c) (join letrec (2 1 3 0) 3 er x eb __t8pF7307) (join-old eval (0 2 1) 3 (0 2 1) __t3Qfa308 c __t8pF7307) (join-old eval (1 2 0) 2 (1 2 0) er c __t8bEj309) (join eval_ans (0 1) 1 __t8bEj309 vr)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex149;  slog::Index** letrecindex150;  slog::Index** evalindex151;  slog::Index** $sup56712x93x0x0x0index152;  slog::Index** evalindex153;  slog::Index** evalindex154;  slog::Index** letrecindex155;  slog::Index** evalindex156;  slog::Index** evalindex157;  slog::Index** eval_ansindex158;  slog::Index** evaldelta159;  slog::Index** $sup56712x93x0x0x0delta160;  slog::Index** evaldelta161;  slog::Index** evaldelta162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("eval_ans");
      head_index[0] = readrel165->getIndex(ord164, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord166({0, 2, 1});
      slog::Relation* readrel167 = db->getRelation("eval");
      evalindex149 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 2, 1});
      slog::Relation* readrel169 = db->getRelation("eval");
      evaldelta159 = readrel169->getIndex(ord168, true);
      std::vector<u16> ord170({3, 0, 1, 2});
      slog::Relation* readrel171 = db->getRelation("letrec");
      letrecindex150 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({2, 0, 1});
      slog::Relation* readrel173 = db->getRelation("eval");
      evalindex151 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 0, 3, 4});
      slog::Relation* readrel175 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index152 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 2, 0, 3, 4});
      slog::Relation* readrel177 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0delta160 = readrel177->getIndex(ord176, true);
      std::vector<u16> ord178({0, 2, 1});
      slog::Relation* readrel179 = db->getRelation("eval");
      evalindex153 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 0});
      slog::Relation* readrel181 = db->getRelation("eval");
      evalindex154 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({2, 1, 3, 0});
      slog::Relation* readrel183 = db->getRelation("letrec");
      letrecindex155 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 2, 1});
      slog::Relation* readrel185 = db->getRelation("eval");
      evalindex156 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 2, 1});
      slog::Relation* readrel187 = db->getRelation("eval");
      evaldelta161 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({1, 2, 0});
      slog::Relation* readrel189 = db->getRelation("eval");
      evalindex157 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("eval");
      evaldelta162 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("eval_ans");
      eval_ansindex158 = readrel193->getIndex(ord192, false);
  
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
        u64 v_c7 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe_old<3,1>(evalindex149, evaldelta159, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m194) {
          u64 v_c1 = m194[1]; u64 v_c2 = m194[2];
          if (!slog::exists_probe<4,1>(letrecindex150, std::array<u64,4>{v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex151, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x93x0x0x0index152, $sup56712x93x0x0x0delta160, std::array<u64,5>{v_c1, v_c2, 0, 0, 0}, [&](const std::array<u64,5>& m195) {
            u64 v_c0 = m195[2]; u64 v_c3 = m195[3]; u64 v_c4 = m195[4];
            if (!slog::exists_probe<3,2>(evalindex153, std::array<u64,3>{v_c0, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex154, std::array<u64,3>{v_c3, v_c1, 0})) return;
            slog::join_probe<4,3>(letrecindex155, std::array<u64,4>{v_c3, v_c4, v_c2, 0}, [&](const std::array<u64,4>& m196) {
              u64 v_c5 = m196[3];
              slog::join_probe_old<3,3>(evalindex156, evaldelta161, std::array<u64,3>{v_c0, v_c1, v_c5}, [&](const std::array<u64,3>& m197) {
                slog::join_probe_old<3,2>(evalindex157, evaldelta162, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m198) {
                  u64 v_c6 = m198[2];
                  slog::join_probe<2,1>(eval_ansindex158, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m199) {
                    u64 v_c8 = m199[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c9}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan eval __t9EYC388 ef c) (body (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t9EYC388) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __t0zOO387) (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval_args (1 2 0) 2 es c) (join app (1 2 0) 2 ef es __t2JOw386) (join eval (0 2 1) 3 __t0zOO387 c __t2JOw386) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t4aOO390) (exists eval_args_ans (0 1) 1 __t4aOO390) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join eval_args_ans (0 1) 1 __t4aOO390 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join delta_ans (0 1) 1 __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask220 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex200;  slog::Index** evalindex201;  slog::Index** eval_argsindex202;  slog::Index** eval_ansindex203;  slog::Index** $sup56712x74x0x0x0index204;  slog::Index** evalindex205;  slog::Index** eval_argsindex206;  slog::Index** appindex207;  slog::Index** evalindex208;  slog::Index** eval_argsindex209;  slog::Index** eval_args_ansindex210;  slog::Index** eval_ansindex211;  slog::Index** eval_args_ansindex212;  slog::Index** deltaindex213;  slog::Index** primindex214;  slog::Index** deltaindex215;  slog::Index** delta_ansindex216;  slog::Index** eval_argsdelta217;  slog::Index** primdelta218;  slog::Index** deltadelta219;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("eval_ans");
      head_index[0] = readrel222->getIndex(ord221, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord223({1, 2, 0});
      slog::Relation* readrel224 = db->getRelation("app");
      appindex200 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({2, 0, 1});
      slog::Relation* readrel226 = db->getRelation("eval");
      evalindex201 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({2, 0, 1});
      slog::Relation* readrel228 = db->getRelation("eval_args");
      eval_argsindex202 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("eval_ans");
      eval_ansindex203 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 3, 0});
      slog::Relation* readrel232 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index204 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 2, 1});
      slog::Relation* readrel234 = db->getRelation("eval");
      evalindex205 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 2, 0});
      slog::Relation* readrel236 = db->getRelation("eval_args");
      eval_argsindex206 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("app");
      appindex207 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 2, 1});
      slog::Relation* readrel240 = db->getRelation("eval");
      evalindex208 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 2, 0});
      slog::Relation* readrel242 = db->getRelation("eval_args");
      eval_argsindex209 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("eval_args");
      eval_argsdelta217 = readrel244->getIndex(ord243, true);
      std::vector<u16> ord245({0, 1});
      slog::Relation* readrel246 = db->getRelation("eval_args_ans");
      eval_args_ansindex210 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("eval_ans");
      eval_ansindex211 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({0, 1});
      slog::Relation* readrel250 = db->getRelation("eval_args_ans");
      eval_args_ansindex212 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({2, 0, 1});
      slog::Relation* readrel252 = db->getRelation("delta");
      deltaindex213 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("prim");
      primindex214 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({0, 1});
      slog::Relation* readrel256 = db->getRelation("prim");
      primdelta218 = readrel256->getIndex(ord255, true);
      std::vector<u16> ord257({1, 2, 0});
      slog::Relation* readrel258 = db->getRelation("delta");
      deltaindex215 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("delta");
      deltadelta219 = readrel260->getIndex(ord259, true);
      std::vector<u16> ord261({0, 1});
      slog::Relation* readrel262 = db->getRelation("delta_ans");
      delta_ansindex216 = readrel262->getIndex(ord261, false);
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<3,1>(appindex200, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex201, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex202, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex203, std::array<u64,2>{v_c49, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index204, std::array<u64,4>{v_c1, v_c35, 0, 0}, [&](const std::array<u64,4>& m263) {
          u64 v_c36 = m263[2]; u64 v_c50 = m263[3];
          if (!slog::exists_probe<3,2>(evalindex205, std::array<u64,3>{v_c50, v_c1, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex206, std::array<u64,3>{v_c36, v_c1, 0})) return;
          slog::join_probe<3,2>(appindex207, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m264) {
            u64 v_c51 = m264[2];
            slog::join_probe<3,3>(evalindex208, std::array<u64,3>{v_c50, v_c1, v_c51}, [&](const std::array<u64,3>& m265) {
              slog::join_probe_old<3,2>(eval_argsindex209, eval_argsdelta217, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m266) {
                u64 v_c52 = m266[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex210, std::array<u64,2>{v_c52, 0})) return;
                slog::join_probe<2,1>(eval_ansindex211, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m267) {
                  u64 v_c53 = m267[1];
                  slog::join_probe<2,1>(eval_args_ansindex212, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m268) {
                    u64 v_c42 = m268[1];
                    if (!slog::exists_probe<3,1>(deltaindex213, std::array<u64,3>{v_c42, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex214, primdelta218, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m269) {
                      u64 v_c54 = m269[1];
                      slog::join_probe_old<3,2>(deltaindex215, deltadelta219, std::array<u64,3>{v_c54, v_c42, 0}, [&](const std::array<u64,3>& m270) {
                        u64 v_c55 = m270[2];
                        slog::join_probe<2,1>(delta_ansindex216, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m271) {
                          u64 v_c9 = m271[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c9}, std::array<u16,2>{0, 1});
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
        ReadTask220* _cont = new ReadTask220(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask220(db,b), false);
  // (crule (pre) (scan lambda __t0FCM371 xs eb) (body (join freevar (1 0) 1 eb x)) (head (mkstruct lst_absent (1 2 0) __2Kgy664 xs x)) freevars.slog:28 #f)
  class ReadTask273 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex272;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lst_absent");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord274({1, 0});
      slog::Relation* readrel275 = db->getRelation("freevar");
      freevarindex272 = readrel275->getIndex(ord274, false);
  
    }
    ReadTask273(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(freevarindex272, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m276) {
          u64 v_c4 = m276[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c48, v_c4}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask273* _cont = new ReadTask273(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask273(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t4lcS166) (join-old lambda (0 1 2) 1 (0 1 2) __t4lcS166 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __0ffn676 c __t45PK165) (join-old app (0 1 2) 1 (0 1 2) __t45PK165 ef es)) (head (mkstruct eval_args (1 2 0) __3T4u677 es c)) interp.slog:56 #f)
  class ReadTask285 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex277;  slog::Index** lambdaindex278;  slog::Index** evalindex279;  slog::Index** appindex280;  slog::Index** freevardelta281;  slog::Index** lambdadelta282;  slog::Index** evaldelta283;  slog::Index** appdelta284;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord286({0, 1});
      slog::Relation* readrel287 = db->getRelation("freevar");
      freevarindex277 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("freevar");
      freevardelta281 = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({0, 1, 2});
      slog::Relation* readrel291 = db->getRelation("lambda");
      lambdaindex278 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({0, 1, 2});
      slog::Relation* readrel293 = db->getRelation("lambda");
      lambdadelta282 = readrel293->getIndex(ord292, true);
      std::vector<u16> ord294({0, 2, 1});
      slog::Relation* readrel295 = db->getRelation("eval");
      evalindex279 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({0, 2, 1});
      slog::Relation* readrel297 = db->getRelation("eval");
      evaldelta283 = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({0, 1, 2});
      slog::Relation* readrel299 = db->getRelation("app");
      appindex280 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1, 2});
      slog::Relation* readrel301 = db->getRelation("app");
      appdelta284 = readrel301->getIndex(ord300, true);
  
    }
    ReadTask285(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[2];
        slog::join_probe_old<2,1>(freevarindex277, freevardelta281, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m302) {
          u64 v_c57 = m302[1];
          slog::join_probe_old<3,1>(lambdaindex278, lambdadelta282, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m303) {
            u64 v_c48 = m303[1]; u64 v_c2 = m303[2];
            slog::join_all_old<3>(evalindex279, evaldelta283, [&](const std::array<u64,3>& m304) {
              u64 v_c58 = m304[0]; u64 v_c1 = m304[1]; u64 v_c59 = m304[2];
              slog::join_probe_old<3,1>(appindex280, appdelta284, std::array<u64,3>{v_c59, 0, 0}, [&](const std::array<u64,3>& m305) {
                u64 v_c35 = m305[1]; u64 v_c36 = m305[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c36, v_c1}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask285* _cont = new ReadTask285(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask285(db,b), false);
  // (crule (pre (let __tconst6UQc687 constb9e118781cea1f9fa01462e0) (let __tconst2Qtx688 const0122baa3ac55f1b433944eb1) (let __tconst6Cg6137 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9tfN494 const6b86b273ff34fce19d6b804e) (let _00024sqc0jHU495 const5feceb66ffc86f38d952786c) (let _00024sqo7x4Q496 const5feceb66ffc86f38d952786c) (let _00024sqo5KfU497 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo7x4Q496 __t687V140 _00024seq1) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5KfU497 __t687V140 _00024seq1) (exists _enum (1 0) 1 __tconst6UQc687) (exists _enum (1 0) 1 __tconst2Qtx688) (join delta (1 2 0) 2 __tconst6Cg6137 _00024seq1 __t2pLy138) (join _enum (1 0) 1 __tconst6UQc687 __t4aV2139) (join boolval (0 1) 2 __t687V140 __t4aV2139) (join _enum (1 0) 1 __tconst2Qtx688 __t67wA135) (letp _00024sql9r92492 (aslst _00024seq1)) (let chk0ENw994 (llen _00024sql9r92492)) (eq _00024sqc9tfN494 chk0ENw994) (letp chk3DQy995 (lref _00024sql9r92492 _00024sqc0jHU495)) (eq __t687V140 chk3DQy995)) (head (emit-temp temp0a5K990 __t2pLy138) (mkstruct boolval (1 0) __t5iPS136 __t67wA135)) interp.slog:113 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex306;  slog::Index** _enumindex307;  slog::Index** _enumindex308;  slog::Index** deltaindex309;  slog::Index** _enumindex310;  slog::Index** boolvalindex311;  slog::Index** _enumindex312;  slog::Index** $seq_atrdelta313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0a5K990");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord315({1, 0, 2});
      slog::Relation* readrel316 = db->getRelation("$seq_at");
      driver_index = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({1, 0, 2});
      slog::Relation* readrel318 = db->getRelation("$seq_atr");
      $seq_atrindex306 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0, 2});
      slog::Relation* readrel320 = db->getRelation("$seq_atr");
      $seq_atrdelta313 = readrel320->getIndex(ord319, true);
      std::vector<u16> ord321({1, 0});
      slog::Relation* readrel322 = db->getRelation("_enum");
      _enumindex307 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 0});
      slog::Relation* readrel324 = db->getRelation("_enum");
      _enumindex308 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("delta");
      deltaindex309 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 0});
      slog::Relation* readrel328 = db->getRelation("_enum");
      _enumindex310 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("boolval");
      boolvalindex311 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 0});
      slog::Relation* readrel332 = db->getRelation("_enum");
      _enumindex312 = readrel332->getIndex(ord331, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c61 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c62 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c65, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m333) {
        u64 v_c67 = m333[1];
        u64 v_c68 = m333[2];
        if (buckethash(v_c67) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex306, $seq_atrdelta313, std::array<u64,3>{v_c66, v_c67, v_c68}, [&](const std::array<u64,3>& m334) {
          if (!slog::exists_probe<2,1>(_enumindex307, std::array<u64,2>{v_c60, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex308, std::array<u64,2>{v_c61, 0})) return;
          slog::join_probe<3,2>(deltaindex309, std::array<u64,3>{v_c62, v_c68, 0}, [&](const std::array<u64,3>& m335) {
            u64 v_c69 = m335[2];
            slog::join_probe<2,1>(_enumindex310, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m336) {
              u64 v_c70 = m336[1];
              slog::join_probe<2,2>(boolvalindex311, std::array<u64,2>{v_c67, v_c70}, [&](const std::array<u64,2>& m337) {
                slog::join_probe<2,1>(_enumindex312, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m338) {
                  u64 v_c71 = m338[1];
                  bool ok339 = true;
                  u64 v_c72 = _prim_aslst(db, v_c68, &ok339);
                  if (!ok339) return;
                  u64 v_c73 = _prim_llen(db, v_c72);
                  if (v_c73 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c63 != v_c73) return;
                  bool ok340 = true;
                  u64 v_c74 = _prim_lref(db, v_c72, v_c64, &ok340);
                  if (!ok340) return;
                  if (v_c67 != v_c74) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c69});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre) (scan $sup56712x41x0x0x0 __d0 c ef es) (body (exists eval_args (1 2 0) 2 es c) (exists app (1 2 0) 2 ef es) (exists tick (2 0 1) 1 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t66Yt170) (exists eval_ans (0 1) 1 __t66Yt170) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join-old eval_ans (0 1) 1 (0 1) __t66Yt170 __t8UWw172) (join-old eval_args_ans (0 1) 1 (0 1) __t3FCg173 vs) (join-old tick_ans (0 1) 1 (0 1) __t9uJP175 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t8UWw172 __t3anZ171 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex341;  slog::Index** appindex342;  slog::Index** tickindex343;  slog::Index** evalindex344;  slog::Index** eval_ansindex345;  slog::Index** eval_argsindex346;  slog::Index** eval_args_ansindex347;  slog::Index** appindex348;  slog::Index** tickindex349;  slog::Index** tick_ansindex350;  slog::Index** eval_ansindex351;  slog::Index** eval_args_ansindex352;  slog::Index** tick_ansindex353;  slog::Index** closureindex354;  slog::Index** lambdaindex355;  slog::Index** evaldelta356;  slog::Index** eval_argsdelta357;  slog::Index** appdelta358;  slog::Index** tickdelta359;  slog::Index** eval_ansdelta360;  slog::Index** eval_args_ansdelta361;  slog::Index** tick_ansdelta362;  slog::Index** closuredelta363;  slog::Index** lambdadelta364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord366({1, 2, 0});
      slog::Relation* readrel367 = db->getRelation("eval_args");
      eval_argsindex341 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 2, 0});
      slog::Relation* readrel369 = db->getRelation("app");
      appindex342 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({2, 0, 1});
      slog::Relation* readrel371 = db->getRelation("tick");
      tickindex343 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 0});
      slog::Relation* readrel373 = db->getRelation("eval");
      evalindex344 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("eval");
      evaldelta356 = readrel375->getIndex(ord374, true);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("eval_ans");
      eval_ansindex345 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("eval_args");
      eval_argsindex346 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("eval_args");
      eval_argsdelta357 = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({0, 1});
      slog::Relation* readrel383 = db->getRelation("eval_args_ans");
      eval_args_ansindex347 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("app");
      appindex348 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 0});
      slog::Relation* readrel387 = db->getRelation("app");
      appdelta358 = readrel387->getIndex(ord386, true);
      std::vector<u16> ord388({1, 2, 0});
      slog::Relation* readrel389 = db->getRelation("tick");
      tickindex349 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("tick");
      tickdelta359 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("tick_ans");
      tick_ansindex350 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1});
      slog::Relation* readrel395 = db->getRelation("eval_ans");
      eval_ansindex351 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("eval_ans");
      eval_ansdelta360 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({0, 1});
      slog::Relation* readrel399 = db->getRelation("eval_args_ans");
      eval_args_ansindex352 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("eval_args_ans");
      eval_args_ansdelta361 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("tick_ans");
      tick_ansindex353 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("tick_ans");
      tick_ansdelta362 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({0, 1, 2});
      slog::Relation* readrel407 = db->getRelation("closure");
      closureindex354 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({0, 1, 2});
      slog::Relation* readrel409 = db->getRelation("closure");
      closuredelta363 = readrel409->getIndex(ord408, true);
      std::vector<u16> ord410({0, 1, 2});
      slog::Relation* readrel411 = db->getRelation("lambda");
      lambdaindex355 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({0, 1, 2});
      slog::Relation* readrel413 = db->getRelation("lambda");
      lambdadelta364 = readrel413->getIndex(ord412, true);
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<3,2>(eval_argsindex341, std::array<u64,3>{v_c36, v_c1, 0})) return;
        if (!slog::exists_probe<3,2>(appindex342, std::array<u64,3>{v_c35, v_c36, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex343, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex344, evaldelta356, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m414) {
          u64 v_c76 = m414[2];
          if (!slog::exists_probe<2,1>(eval_ansindex345, std::array<u64,2>{v_c76, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex346, eval_argsdelta357, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m415) {
            u64 v_c77 = m415[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex347, std::array<u64,2>{v_c77, 0})) return;
            slog::join_probe_old<3,2>(appindex348, appdelta358, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m416) {
              u64 v_c78 = m416[2];
              slog::join_probe_old<3,2>(tickindex349, tickdelta359, std::array<u64,3>{v_c78, v_c1, 0}, [&](const std::array<u64,3>& m417) {
                u64 v_c79 = m417[2];
                if (!slog::exists_probe<2,1>(tick_ansindex350, std::array<u64,2>{v_c79, 0})) return;
                slog::join_probe_old<2,1>(eval_ansindex351, eval_ansdelta360, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m418) {
                  u64 v_c80 = m418[1];
                  slog::join_probe_old<2,1>(eval_args_ansindex352, eval_args_ansdelta361, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m419) {
                    u64 v_c42 = m419[1];
                    slog::join_probe_old<2,1>(tick_ansindex353, tick_ansdelta362, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m420) {
                      u64 v_c33 = m420[1];
                      slog::join_probe_old<3,1>(closureindex354, closuredelta363, std::array<u64,3>{v_c80, 0, 0}, [&](const std::array<u64,3>& m421) {
                        u64 v_c81 = m421[1]; u64 v_c45 = m421[2];
                        slog::join_probe_old<3,1>(lambdaindex355, lambdadelta364, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m422) {
                          u64 v_c48 = m422[1]; u64 v_c2 = m422[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c33}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask365* _cont = new ReadTask365(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask365(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715)) (scan temp6KbH968 __t1E72242 __t34RH259 __t4sa5291 __t7Cof275 __t9Hvd221) (body (join let (2 1 3 0) 3 __t1E72242 __tconst7Bar243 __t9Hvd221 __t7jCf244)) (head (emit-temp temp82x0969 __t34RH259 __t4sa5291 __t7Cof275 __t7jCf244) (mkstruct let (2 1 3 0) __t0Ieb261 __t34RH259 __tconst4aTz260 __t7jCf244)) analysis-demo.slog:21 #f)
  class ReadTask424 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex423;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp82x0969");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp6KbH968");
      std::vector<u16> ord425({2, 1, 3, 0});
      slog::Relation* readrel426 = db->getRelation("let");
      letindex423 = readrel426->getIndex(ord425, false);
  
    }
    ReadTask424(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c14 = v_constf77801bebb40767a1b303d97;
      u64 v_c17 = v_const829935b42173b360da35f679;
      u64 v_c21 = v_const0388ead47e9d5ccfc5320715;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c82 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c84 = _t[2];
        u64 v_c85 = _t[3];
        u64 v_c86 = _t[4];
        slog::join_probe<4,3>(letindex423, std::array<u64,4>{v_c82, v_c21, v_c86, 0}, [&](const std::array<u64,4>& m427) {
          u64 v_c87 = m427[3];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c83, v_c84, v_c85, v_c87});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c83, v_c17, v_c87}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp6KbH968", _fires);
  
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
  // (crule (pre (let __tconst62Eu697 constb9e118781cea1f9fa01462e0)) (scan boolval __t9OVd356 __t7z6n355) (body (join _enum (0 1) 2 __t7z6n355 __tconst62Eu697)) (head (emit scheme_false (0) __t9OVd356)) interp.slog:81 #f)
  class ReadTask429 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex428;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord430({0});
      slog::Relation* readrel431 = db->getRelation("scheme_false");
      head_index[0] = readrel431->getIndex(ord430, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord432({0, 1});
      slog::Relation* readrel433 = db->getRelation("_enum");
      _enumindex428 = readrel433->getIndex(ord432, false);
  
    }
    ReadTask429(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c89 = _t[0];
        u64 v_c90 = _t[1];
        slog::join_probe<2,2>(_enumindex428, std::array<u64,2>{v_c90, v_c88}, [&](const std::array<u64,2>& m434) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c89}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask429* _cont = new ReadTask429(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask429(db,b), false);
  // (crule (pre) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body (exists select_branch (2 3 0 1) 2 e2 e3) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t4vYZ364) (exists eval_ans (0 1) 1 __t4vYZ364) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t7P7f365 __v0) (join-old eval_ans (0 1) 2 (0 1) __t4vYZ364 __v0) (join-old select_branch_ans (0 1) 1 (0 1) __t7P7f365 __v1)) (head (mkstruct eval (1 2 0) __4AHX627 __v1 c)) interp.slog:87 #f)
  class ReadTask445 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex435;  slog::Index** evalindex436;  slog::Index** eval_ansindex437;  slog::Index** select_branchindex438;  slog::Index** eval_ansindex439;  slog::Index** select_branch_ansindex440;  slog::Index** evaldelta441;  slog::Index** select_branchdelta442;  slog::Index** eval_ansdelta443;  slog::Index** select_branch_ansdelta444;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord446({2, 3, 0, 1});
      slog::Relation* readrel447 = db->getRelation("select_branch");
      select_branchindex435 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({1, 2, 0});
      slog::Relation* readrel449 = db->getRelation("eval");
      evalindex436 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 2, 0});
      slog::Relation* readrel451 = db->getRelation("eval");
      evaldelta441 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1});
      slog::Relation* readrel453 = db->getRelation("eval_ans");
      eval_ansindex437 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({2, 3, 0, 1});
      slog::Relation* readrel455 = db->getRelation("select_branch");
      select_branchindex438 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({2, 3, 0, 1});
      slog::Relation* readrel457 = db->getRelation("select_branch");
      select_branchdelta442 = readrel457->getIndex(ord456, true);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("eval_ans");
      eval_ansindex439 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("eval_ans");
      eval_ansdelta443 = readrel461->getIndex(ord460, true);
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("select_branch_ans");
      select_branch_ansindex440 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("select_branch_ans");
      select_branch_ansdelta444 = readrel465->getIndex(ord464, true);
  
    }
    ReadTask445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c91 = _t[2];
        u64 v_c92 = _t[3];
        u64 v_c93 = _t[4];
        if (!slog::exists_probe<4,2>(select_branchindex435, std::array<u64,4>{v_c92, v_c93, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex436, evaldelta441, std::array<u64,3>{v_c91, v_c1, 0}, [&](const std::array<u64,3>& m466) {
          u64 v_c94 = m466[2];
          if (!slog::exists_probe<2,1>(eval_ansindex437, std::array<u64,2>{v_c94, 0})) return;
          slog::join_probe_old<4,2>(select_branchindex438, select_branchdelta442, std::array<u64,4>{v_c92, v_c93, 0, 0}, [&](const std::array<u64,4>& m467) {
            u64 v_c95 = m467[2]; u64 v_c33 = m467[3];
            slog::join_probe_old<2,2>(eval_ansindex439, eval_ansdelta443, std::array<u64,2>{v_c94, v_c33}, [&](const std::array<u64,2>& m468) {
              slog::join_probe_old<2,1>(select_branch_ansindex440, select_branch_ansdelta444, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m469) {
                u64 v_c96 = m469[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c96, v_c1}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask445* _cont = new ReadTask445(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask445(db,b), false);
  // (crule (pre) (scan let __t78XS372 x er eb) (body (exists eval (1 2 0) 1 __t78XS372) (exists eval (1 2 0) 1 er) (exists eval (1 2 0) 1 eb) (join $sup56712x91x0x0x0 (2 3 4 0 1) 3 eb er x __t9U3N373 c) (join-old eval (0 2 1) 3 (0 2 1) __t9U3N373 c __t78XS372) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t7j91374) (exists eval_ans (0 1) 1 __t7j91374) (join-old eval (1 2 0) 2 (1 2 0) eb c __t3KJV375) (exists eval_ans (0 1) 1 __t3KJV375) (join eval_ans (0 1) 1 __t7j91374 vr) (join eval_ans (0 1) 1 __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask485 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex470;  slog::Index** evalindex471;  slog::Index** evalindex472;  slog::Index** $sup56712x91x0x0x0index473;  slog::Index** evalindex474;  slog::Index** evalindex475;  slog::Index** evalindex476;  slog::Index** eval_ansindex477;  slog::Index** evalindex478;  slog::Index** eval_ansindex479;  slog::Index** eval_ansindex480;  slog::Index** eval_ansindex481;  slog::Index** evaldelta482;  slog::Index** evaldelta483;  slog::Index** evaldelta484;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("eval_ans");
      head_index[0] = readrel487->getIndex(ord486, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("eval");
      evalindex470 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("eval");
      evalindex471 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("eval");
      evalindex472 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({2, 3, 4, 0, 1});
      slog::Relation* readrel495 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index473 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 2, 1});
      slog::Relation* readrel497 = db->getRelation("eval");
      evalindex474 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 2, 1});
      slog::Relation* readrel499 = db->getRelation("eval");
      evaldelta482 = readrel499->getIndex(ord498, true);
      std::vector<u16> ord500({1, 2, 0});
      slog::Relation* readrel501 = db->getRelation("eval");
      evalindex475 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({1, 2, 0});
      slog::Relation* readrel503 = db->getRelation("eval");
      evalindex476 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("eval");
      evaldelta483 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("eval_ans");
      eval_ansindex477 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("eval");
      evalindex478 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 2, 0});
      slog::Relation* readrel511 = db->getRelation("eval");
      evaldelta484 = readrel511->getIndex(ord510, true);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("eval_ans");
      eval_ansindex479 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1});
      slog::Relation* readrel515 = db->getRelation("eval_ans");
      eval_ansindex480 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({0, 1});
      slog::Relation* readrel517 = db->getRelation("eval_ans");
      eval_ansindex481 = readrel517->getIndex(ord516, false);
  
    }
    ReadTask485(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex470, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex471, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex472, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x91x0x0x0index473, std::array<u64,5>{v_c2, v_c3, v_c4, 0, 0}, [&](const std::array<u64,5>& m518) {
          u64 v_c98 = m518[3]; u64 v_c1 = m518[4];
          slog::join_probe_old<3,3>(evalindex474, evaldelta482, std::array<u64,3>{v_c98, v_c1, v_c97}, [&](const std::array<u64,3>& m519) {
            if (!slog::exists_probe<3,2>(evalindex475, std::array<u64,3>{v_c2, v_c1, 0})) return;
            slog::join_probe_old<3,2>(evalindex476, evaldelta483, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m520) {
              u64 v_c99 = m520[2];
              if (!slog::exists_probe<2,1>(eval_ansindex477, std::array<u64,2>{v_c99, 0})) return;
              slog::join_probe_old<3,2>(evalindex478, evaldelta484, std::array<u64,3>{v_c2, v_c1, 0}, [&](const std::array<u64,3>& m521) {
                u64 v_c100 = m521[2];
                if (!slog::exists_probe<2,1>(eval_ansindex479, std::array<u64,2>{v_c100, 0})) return;
                slog::join_probe<2,1>(eval_ansindex480, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m522) {
                  u64 v_c8 = m522[1];
                  slog::join_probe<2,1>(eval_ansindex481, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m523) {
                    u64 v_c9 = m523[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c98, v_c9}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask485* _cont = new ReadTask485(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask485(db,b), false);
  // (crule (pre) (scan let __t0pzR116 y er eb) (body (join freevar (1 0) 1 er x)) (head (emit freevar (0 1) x __t0pzR116)) freevars.slog:21 #f)
  class ReadTask525 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex524;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord526({0, 1});
      slog::Relation* readrel527 = db->getRelation("freevar");
      head_index[0] = readrel527->getIndex(ord526, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord528({1, 0});
      slog::Relation* readrel529 = db->getRelation("freevar");
      freevarindex524 = readrel529->getIndex(ord528, false);
  
    }
    ReadTask525(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c2 = _t[3];
        slog::join_probe<2,1>(freevarindex524, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m530) {
          u64 v_c4 = m530[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c101}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:21", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask525* _cont = new ReadTask525(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask525(db,b), false);
  // (crule (pre (let __tconst36mF602 constcd2a69ce5ca278db1d6da969) (let __tconst4MYs19 const06abaa100ecef791ce028c56) (let _00024sqc0R1w414 constd4735e3a265e16eee03f5971) (let _00024sqc2r3q415 const5feceb66ffc86f38d952786c) (let _00024sqc1pwY416 const6b86b273ff34fce19d6b804e) (let _00024sqo5Wc9417 const5feceb66ffc86f38d952786c) (let _00024sqo4N7A418 const6b86b273ff34fce19d6b804e) (let _00024sqo8u9a419 const6b86b273ff34fce19d6b804e) (let _00024sqo9jvY420 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo4N7A418 __t2nOL22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Wc9417 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8u9a419 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9jvY420 __t2nOL22 _00024seq2) (join _enum (0 1) 2 __t2nOL22 __tconst36mF602) (join delta (1 2 0) 2 __tconst4MYs19 _00024seq2 __t9afR20) (join any_bool (0) 0 b) (letp _00024sql9osm412 (aslst _00024seq2)) (let chk1LOG850 (llen _00024sql9osm412)) (eq _00024sqc0R1w414 chk1LOG850) (letp chk4CCG851 (lref _00024sql9osm412 _00024sqc2r3q415)) (eq __t2nOL22 chk4CCG851) (letp chk9Rwm852 (lref _00024sql9osm412 _00024sqc1pwY416)) (eq __t2nOL22 chk9Rwm852)) (head (emit-temp temp4fHg844 __t9afR20 b) (mkstruct boolval (1 0) __t975c18 b)) interp.slog:121 #f)
  class ReadTask539 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex531;  slog::Index** $seq_atrindex532;  slog::Index** $seq_atrindex533;  slog::Index** _enumindex534;  slog::Index** deltaindex535;  slog::Index** any_boolindex536;  slog::Index** $seq_atrdelta537;  slog::Index** $seq_atrdelta538;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4fHg844");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord540({1, 0, 2});
      slog::Relation* readrel541 = db->getRelation("$seq_at");
      driver_index = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({1, 0, 2});
      slog::Relation* readrel543 = db->getRelation("$seq_at");
      $seq_atindex531 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0, 2});
      slog::Relation* readrel545 = db->getRelation("$seq_atr");
      $seq_atrindex532 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 0, 2});
      slog::Relation* readrel547 = db->getRelation("$seq_atr");
      $seq_atrdelta537 = readrel547->getIndex(ord546, true);
      std::vector<u16> ord548({1, 0, 2});
      slog::Relation* readrel549 = db->getRelation("$seq_atr");
      $seq_atrindex533 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 0, 2});
      slog::Relation* readrel551 = db->getRelation("$seq_atr");
      $seq_atrdelta538 = readrel551->getIndex(ord550, true);
      std::vector<u16> ord552({0, 1});
      slog::Relation* readrel553 = db->getRelation("_enum");
      _enumindex534 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 0});
      slog::Relation* readrel555 = db->getRelation("delta");
      deltaindex535 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({0});
      slog::Relation* readrel557 = db->getRelation("any_bool");
      any_boolindex536 = readrel557->getIndex(ord556, false);
  
    }
    ReadTask539(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c103 = v_const06abaa100ecef791ce028c56;
      u64 v_c104 = v_constd4735e3a265e16eee03f5971;
      u64 v_c105 = v_const5feceb66ffc86f38d952786c;
      u64 v_c106 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c108, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m558) {
        u64 v_c111 = m558[1];
        u64 v_c112 = m558[2];
        if (buckethash(v_c111) != bucket) return;
        slog::join_probe<3,3>($seq_atindex531, std::array<u64,3>{v_c107, v_c111, v_c112}, [&](const std::array<u64,3>& m559) {
          slog::join_probe_old<3,3>($seq_atrindex532, $seq_atrdelta537, std::array<u64,3>{v_c109, v_c111, v_c112}, [&](const std::array<u64,3>& m560) {
            slog::join_probe_old<3,3>($seq_atrindex533, $seq_atrdelta538, std::array<u64,3>{v_c110, v_c111, v_c112}, [&](const std::array<u64,3>& m561) {
              slog::join_probe<2,2>(_enumindex534, std::array<u64,2>{v_c111, v_c102}, [&](const std::array<u64,2>& m562) {
                slog::join_probe<3,2>(deltaindex535, std::array<u64,3>{v_c103, v_c112, 0}, [&](const std::array<u64,3>& m563) {
                  u64 v_c113 = m563[2];
                  slog::join_all<1>(any_boolindex536, [&](const std::array<u64,1>& m564) {
                    u64 v_c114 = m564[0];
                    bool ok565 = true;
                    u64 v_c115 = _prim_aslst(db, v_c112, &ok565);
                    if (!ok565) return;
                    u64 v_c116 = _prim_llen(db, v_c115);
                    if (v_c116 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c104 != v_c116) return;
                    bool ok566 = true;
                    u64 v_c117 = _prim_lref(db, v_c115, v_c105, &ok566);
                    if (!ok566) return;
                    if (v_c111 != v_c117) return;
                    bool ok567 = true;
                    u64 v_c118 = _prim_lref(db, v_c115, v_c106, &ok567);
                    if (!ok567) return;
                    if (v_c111 != v_c118) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c113, v_c114});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c114}, std::array<u16,2>{1, 0});
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
        ReadTask539* _cont = new ReadTask539(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask539(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715)) (scan temp17TG965 __t03VS238 __t34RH259 __t4sa5291 __t7Cof275 __t9Hvd221) (body (exists ref (1 0) 1 __tconst4aTz260) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (let __t6mUC239 (lpush __t03VS238 __t55Yd223))) (head (emit-temp temp0Rdi966 __t34RH259 __t4sa5291 __t6mUC239 __t7Cof275 __t9Hvd221)) analysis-demo.slog:21 #f)
  class ReadTask571 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex568;  slog::Index** refindex569;  slog::Index** refindex570;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Rdi966");
      outer_rel = db->getRelation("temp17TG965");
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("ref");
      refindex568 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("ref");
      refindex569 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("ref");
      refindex570 = readrel577->getIndex(ord576, false);
  
    }
    ReadTask571(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c14 = v_constf77801bebb40767a1b303d97;
      u64 v_c17 = v_const829935b42173b360da35f679;
      u64 v_c21 = v_const0388ead47e9d5ccfc5320715;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c84 = _t[2];
        u64 v_c85 = _t[3];
        u64 v_c86 = _t[4];
        if (!slog::exists_probe<2,1>(refindex568, std::array<u64,2>{v_c17, 0})) return;
        slog::join_probe<2,1>(refindex569, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m578) {
          u64 v_c120 = m578[1];
          slog::join_probe<2,1>(refindex570, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m579) {
            u64 v_c121 = m579[1];
            u64 v_c122 = _prim_lpush(db, v_c119, v_c120);
            if (v_c122 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
            ++_fires;
            slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c83, v_c84, v_c122, v_c85, v_c86});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp17TG965", _fires);
  
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
  // (crule (pre (let __trid0R3a564 const25f568921d120de09a5f575d) (let __trel4Aiv565 const4a59dbb9cb3129dfcc75170b) (let __tcol2jee566 const5feceb66ffc86f38d952786c) (let __trel1QfK567 const4a59dbb9cb3129dfcc75170b) (let __tcol55V4568 const6b86b273ff34fce19d6b804e)) (scan $sup56712x91x0x0x0 __d0 c eb er x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid0R3a564 __trel4Aiv565 __tcol2jee566 (1 2 3 4 0)) (tycheck c (accept seq) __trid0R3a564 __trel1QfK567 __tcol55V4568 (1 2 3 4 0)) (mkstruct eval (1 2 0) __9W5B563 er c)) interp.slog:92 #f)
  class ReadTask589 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid580;  u32 sid581;  u32 sid582;  u32 sid583;  u32 sid584;  u32 sid585;  u32 sid586;  u32 sid587;  u32 sid588;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      sid580 = db->getRelation("app")->getStructId();
      sid581 = db->getRelation("boolean")->getStructId();
      sid582 = db->getRelation("if")->getStructId();
      sid583 = db->getRelation("lambda")->getStructId();
      sid584 = db->getRelation("let")->getStructId();
      sid585 = db->getRelation("letrec")->getStructId();
      sid586 = db->getRelation("num")->getStructId();
      sid587 = db->getRelation("ref")->getStructId();
      sid588 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask589(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c123 = v_const25f568921d120de09a5f575d;
      u64 v_c124 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c75 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid580 || decode_struct_id(v_c3) == sid581 || decode_struct_id(v_c3) == sid582 || decode_struct_id(v_c3) == sid583 || decode_struct_id(v_c3) == sid584 || decode_struct_id(v_c3) == sid585 || decode_struct_id(v_c3) == sid586 || decode_struct_id(v_c3) == sid587 || decode_struct_id(v_c3) == sid588))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c123, v_c124, v_c125, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c1)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c123, v_c126, v_c127, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c3, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:$sup56712x91x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask589* _cont = new ReadTask589(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask589(db,b), false);
  // (crule (pre) (scan freevar y __t8awf114) (body (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t8awf114 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __88TM561 c __t4vf0113) (join-old app (0 1 2) 1 (0 1 2) __t4vf0113 ef es)) (head (mkstruct eval (1 2 0) __7s92562 ef c)) interp.slog:56 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex590;  slog::Index** lambdaindex591;  slog::Index** evalindex592;  slog::Index** appindex593;  slog::Index** lambdadelta594;  slog::Index** evaldelta595;  slog::Index** appdelta596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord598({0, 1, 2});
      slog::Relation* readrel599 = db->getRelation("binding");
      bindingindex590 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({0, 1, 2});
      slog::Relation* readrel601 = db->getRelation("lambda");
      lambdaindex591 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({0, 1, 2});
      slog::Relation* readrel603 = db->getRelation("lambda");
      lambdadelta594 = readrel603->getIndex(ord602, true);
      std::vector<u16> ord604({0, 2, 1});
      slog::Relation* readrel605 = db->getRelation("eval");
      evalindex592 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({0, 2, 1});
      slog::Relation* readrel607 = db->getRelation("eval");
      evaldelta595 = readrel607->getIndex(ord606, true);
      std::vector<u16> ord608({0, 1, 2});
      slog::Relation* readrel609 = db->getRelation("app");
      appindex593 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({0, 1, 2});
      slog::Relation* readrel611 = db->getRelation("app");
      appdelta596 = readrel611->getIndex(ord610, true);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c128 = _t[1];
        slog::join_probe<3,1>(bindingindex590, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m612) {
          u64 v_c45 = m612[1]; u64 v_c47 = m612[2];
          slog::join_probe_old<3,1>(lambdaindex591, lambdadelta594, std::array<u64,3>{v_c128, 0, 0}, [&](const std::array<u64,3>& m613) {
            u64 v_c48 = m613[1]; u64 v_c2 = m613[2];
            slog::join_all_old<3>(evalindex592, evaldelta595, [&](const std::array<u64,3>& m614) {
              u64 v_c129 = m614[0]; u64 v_c1 = m614[1]; u64 v_c130 = m614[2];
              slog::join_probe_old<3,1>(appindex593, appdelta596, std::array<u64,3>{v_c130, 0, 0}, [&](const std::array<u64,3>& m615) {
                u64 v_c35 = m615[1]; u64 v_c36 = m615[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c35, v_c1}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask597* _cont = new ReadTask597(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask597(db,b), false);
  // (crule (pre) (scan $sup56712x41x0x0x0 __t6uzd177 c ef es) (body (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (exists eval_args (1 2 0) 2 es c) (exists tick (2 0 1) 1 c) (join-old eval (0 2 1) 2 (0 2 1) __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4yWQ180 __t7rcY179 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask645 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex616;  slog::Index** evalindex617;  slog::Index** eval_argsindex618;  slog::Index** tickindex619;  slog::Index** evalindex620;  slog::Index** appindex621;  slog::Index** tickindex622;  slog::Index** evalindex623;  slog::Index** eval_ansindex624;  slog::Index** eval_argsindex625;  slog::Index** eval_args_ansindex626;  slog::Index** tickindex627;  slog::Index** tick_ansindex628;  slog::Index** eval_ansindex629;  slog::Index** eval_args_ansindex630;  slog::Index** tick_ansindex631;  slog::Index** evalindex632;  slog::Index** closureindex633;  slog::Index** lambdaindex634;  slog::Index** evalindex635;  slog::Index** eval_ansindex636;  slog::Index** evaldelta637;  slog::Index** appdelta638;  slog::Index** evaldelta639;  slog::Index** eval_argsdelta640;  slog::Index** tickdelta641;  slog::Index** closuredelta642;  slog::Index** lambdadelta643;  slog::Index** evaldelta644;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("eval_ans");
      head_index[0] = readrel647->getIndex(ord646, false);
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("app");
      appindex616 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 2, 0});
      slog::Relation* readrel651 = db->getRelation("eval");
      evalindex617 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("eval_args");
      eval_argsindex618 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({2, 0, 1});
      slog::Relation* readrel655 = db->getRelation("tick");
      tickindex619 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({0, 2, 1});
      slog::Relation* readrel657 = db->getRelation("eval");
      evalindex620 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 2, 1});
      slog::Relation* readrel659 = db->getRelation("eval");
      evaldelta637 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({0, 1, 2});
      slog::Relation* readrel661 = db->getRelation("app");
      appindex621 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1, 2});
      slog::Relation* readrel663 = db->getRelation("app");
      appdelta638 = readrel663->getIndex(ord662, true);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("tick");
      tickindex622 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("eval");
      evalindex623 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("eval");
      evaldelta639 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({0, 1});
      slog::Relation* readrel671 = db->getRelation("eval_ans");
      eval_ansindex624 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("eval_args");
      eval_argsindex625 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 0});
      slog::Relation* readrel675 = db->getRelation("eval_args");
      eval_argsdelta640 = readrel675->getIndex(ord674, true);
      std::vector<u16> ord676({0, 1});
      slog::Relation* readrel677 = db->getRelation("eval_args_ans");
      eval_args_ansindex626 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("tick");
      tickindex627 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("tick");
      tickdelta641 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("tick_ans");
      tick_ansindex628 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("eval_ans");
      eval_ansindex629 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_args_ans");
      eval_args_ansindex630 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("tick_ans");
      tick_ansindex631 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 0, 1});
      slog::Relation* readrel691 = db->getRelation("eval");
      evalindex632 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({0, 1, 2});
      slog::Relation* readrel693 = db->getRelation("closure");
      closureindex633 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1, 2});
      slog::Relation* readrel695 = db->getRelation("closure");
      closuredelta642 = readrel695->getIndex(ord694, true);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("lambda");
      lambdaindex634 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({0, 1, 2});
      slog::Relation* readrel699 = db->getRelation("lambda");
      lambdadelta643 = readrel699->getIndex(ord698, true);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("eval");
      evalindex635 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("eval");
      evaldelta644 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({0, 1});
      slog::Relation* readrel705 = db->getRelation("eval_ans");
      eval_ansindex636 = readrel705->getIndex(ord704, false);
  
    }
    ReadTask645(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        if (!slog::exists_probe<3,2>(appindex616, std::array<u64,3>{v_c35, v_c36, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex617, std::array<u64,3>{v_c35, v_c1, 0})) return;
        if (!slog::exists_probe<3,2>(eval_argsindex618, std::array<u64,3>{v_c36, v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex619, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex620, evaldelta637, std::array<u64,3>{v_c131, v_c1, 0}, [&](const std::array<u64,3>& m706) {
          u64 v_c132 = m706[2];
          slog::join_probe_old<3,3>(appindex621, appdelta638, std::array<u64,3>{v_c132, v_c35, v_c36}, [&](const std::array<u64,3>& m707) {
            if (!slog::exists_probe<3,2>(tickindex622, std::array<u64,3>{v_c132, v_c1, 0})) return;
            slog::join_probe_old<3,2>(evalindex623, evaldelta639, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m708) {
              u64 v_c133 = m708[2];
              if (!slog::exists_probe<2,1>(eval_ansindex624, std::array<u64,2>{v_c133, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex625, eval_argsdelta640, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m709) {
                u64 v_c134 = m709[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex626, std::array<u64,2>{v_c134, 0})) return;
                slog::join_probe_old<3,2>(tickindex627, tickdelta641, std::array<u64,3>{v_c132, v_c1, 0}, [&](const std::array<u64,3>& m710) {
                  u64 v_c135 = m710[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex628, std::array<u64,2>{v_c135, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex629, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m711) {
                    u64 v_c136 = m711[1];
                    slog::join_probe<2,1>(eval_args_ansindex630, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m712) {
                      u64 v_c42 = m712[1];
                      slog::join_probe<2,1>(tick_ansindex631, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m713) {
                        u64 v_c33 = m713[1];
                        if (!slog::exists_probe<3,1>(evalindex632, std::array<u64,3>{v_c33, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex633, closuredelta642, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m714) {
                          u64 v_c137 = m714[1]; u64 v_c45 = m714[2];
                          slog::join_probe_old<3,1>(lambdaindex634, lambdadelta643, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m715) {
                            u64 v_c48 = m715[1]; u64 v_c2 = m715[2];
                            slog::join_probe_old<3,2>(evalindex635, evaldelta644, std::array<u64,3>{v_c2, v_c33, 0}, [&](const std::array<u64,3>& m716) {
                              u64 v_c138 = m716[2];
                              slog::join_probe<2,1>(eval_ansindex636, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m717) {
                                u64 v_c9 = m717[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c9}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask645* _cont = new ReadTask645(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask645(db,b), false);
  // (crule (pre) (scan eval_args_ans __t6UxD181 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t6UxD181 c es) (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join-old $sup56712x41x0x0x0 (1 3 0 2) 2 (1 3 0 2) c es __t6uzd177 ef) (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (join-old eval (0 2 1) 2 (0 2 1) __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join-old tick_ans (0 1) 1 (0 1) __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4yWQ180 __t7rcY179 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join-old eval_ans (0 1) 1 (0 1) __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask750 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex718;  slog::Index** evalindex719;  slog::Index** appindex720;  slog::Index** tickindex721;  slog::Index** $sup56712x41x0x0x0index722;  slog::Index** appindex723;  slog::Index** evalindex724;  slog::Index** evalindex725;  slog::Index** appindex726;  slog::Index** tickindex727;  slog::Index** evalindex728;  slog::Index** eval_ansindex729;  slog::Index** tickindex730;  slog::Index** tick_ansindex731;  slog::Index** eval_ansindex732;  slog::Index** tick_ansindex733;  slog::Index** evalindex734;  slog::Index** closureindex735;  slog::Index** lambdaindex736;  slog::Index** evalindex737;  slog::Index** eval_ansindex738;  slog::Index** eval_argsdelta739;  slog::Index** $sup56712x41x0x0x0delta740;  slog::Index** evaldelta741;  slog::Index** appdelta742;  slog::Index** evaldelta743;  slog::Index** tickdelta744;  slog::Index** tick_ansdelta745;  slog::Index** closuredelta746;  slog::Index** lambdadelta747;  slog::Index** evaldelta748;  slog::Index** eval_ansdelta749;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord751({0, 1});
      slog::Relation* readrel752 = db->getRelation("eval_ans");
      head_index[0] = readrel752->getIndex(ord751, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord753({0, 2, 1});
      slog::Relation* readrel754 = db->getRelation("eval_args");
      eval_argsindex718 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({0, 2, 1});
      slog::Relation* readrel756 = db->getRelation("eval_args");
      eval_argsdelta739 = readrel756->getIndex(ord755, true);
      std::vector<u16> ord757({2, 0, 1});
      slog::Relation* readrel758 = db->getRelation("eval");
      evalindex719 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({2, 0, 1});
      slog::Relation* readrel760 = db->getRelation("app");
      appindex720 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({2, 0, 1});
      slog::Relation* readrel762 = db->getRelation("tick");
      tickindex721 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 3, 0, 2});
      slog::Relation* readrel764 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index722 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 3, 0, 2});
      slog::Relation* readrel766 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta740 = readrel766->getIndex(ord765, true);
      std::vector<u16> ord767({1, 2, 0});
      slog::Relation* readrel768 = db->getRelation("app");
      appindex723 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("eval");
      evalindex724 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({0, 2, 1});
      slog::Relation* readrel772 = db->getRelation("eval");
      evalindex725 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({0, 2, 1});
      slog::Relation* readrel774 = db->getRelation("eval");
      evaldelta741 = readrel774->getIndex(ord773, true);
      std::vector<u16> ord775({0, 1, 2});
      slog::Relation* readrel776 = db->getRelation("app");
      appindex726 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({0, 1, 2});
      slog::Relation* readrel778 = db->getRelation("app");
      appdelta742 = readrel778->getIndex(ord777, true);
      std::vector<u16> ord779({1, 2, 0});
      slog::Relation* readrel780 = db->getRelation("tick");
      tickindex727 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("eval");
      evalindex728 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 2, 0});
      slog::Relation* readrel784 = db->getRelation("eval");
      evaldelta743 = readrel784->getIndex(ord783, true);
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("eval_ans");
      eval_ansindex729 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 2, 0});
      slog::Relation* readrel788 = db->getRelation("tick");
      tickindex730 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("tick");
      tickdelta744 = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({0, 1});
      slog::Relation* readrel792 = db->getRelation("tick_ans");
      tick_ansindex731 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("eval_ans");
      eval_ansindex732 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("tick_ans");
      tick_ansindex733 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1});
      slog::Relation* readrel798 = db->getRelation("tick_ans");
      tick_ansdelta745 = readrel798->getIndex(ord797, true);
      std::vector<u16> ord799({2, 0, 1});
      slog::Relation* readrel800 = db->getRelation("eval");
      evalindex734 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 1, 2});
      slog::Relation* readrel802 = db->getRelation("closure");
      closureindex735 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({0, 1, 2});
      slog::Relation* readrel804 = db->getRelation("closure");
      closuredelta746 = readrel804->getIndex(ord803, true);
      std::vector<u16> ord805({0, 1, 2});
      slog::Relation* readrel806 = db->getRelation("lambda");
      lambdaindex736 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 1, 2});
      slog::Relation* readrel808 = db->getRelation("lambda");
      lambdadelta747 = readrel808->getIndex(ord807, true);
      std::vector<u16> ord809({1, 2, 0});
      slog::Relation* readrel810 = db->getRelation("eval");
      evalindex737 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 0});
      slog::Relation* readrel812 = db->getRelation("eval");
      evaldelta748 = readrel812->getIndex(ord811, true);
      std::vector<u16> ord813({0, 1});
      slog::Relation* readrel814 = db->getRelation("eval_ans");
      eval_ansindex738 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({0, 1});
      slog::Relation* readrel816 = db->getRelation("eval_ans");
      eval_ansdelta749 = readrel816->getIndex(ord815, true);
  
    }
    ReadTask750(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex718, eval_argsdelta739, std::array<u64,3>{v_c134, 0, 0}, [&](const std::array<u64,3>& m817) {
          u64 v_c1 = m817[1]; u64 v_c36 = m817[2];
          if (!slog::exists_probe<3,1>(evalindex719, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex720, std::array<u64,3>{v_c36, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex721, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x41x0x0x0index722, $sup56712x41x0x0x0delta740, std::array<u64,4>{v_c1, v_c36, 0, 0}, [&](const std::array<u64,4>& m818) {
            u64 v_c131 = m818[2]; u64 v_c35 = m818[3];
            if (!slog::exists_probe<3,2>(appindex723, std::array<u64,3>{v_c35, v_c36, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex724, std::array<u64,3>{v_c35, v_c1, 0})) return;
            slog::join_probe_old<3,2>(evalindex725, evaldelta741, std::array<u64,3>{v_c131, v_c1, 0}, [&](const std::array<u64,3>& m819) {
              u64 v_c132 = m819[2];
              slog::join_probe_old<3,3>(appindex726, appdelta742, std::array<u64,3>{v_c132, v_c35, v_c36}, [&](const std::array<u64,3>& m820) {
                if (!slog::exists_probe<3,2>(tickindex727, std::array<u64,3>{v_c132, v_c1, 0})) return;
                slog::join_probe_old<3,2>(evalindex728, evaldelta743, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m821) {
                  u64 v_c133 = m821[2];
                  if (!slog::exists_probe<2,1>(eval_ansindex729, std::array<u64,2>{v_c133, 0})) return;
                  slog::join_probe_old<3,2>(tickindex730, tickdelta744, std::array<u64,3>{v_c132, v_c1, 0}, [&](const std::array<u64,3>& m822) {
                    u64 v_c135 = m822[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex731, std::array<u64,2>{v_c135, 0})) return;
                    slog::join_probe<2,1>(eval_ansindex732, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m823) {
                      u64 v_c136 = m823[1];
                      slog::join_probe_old<2,1>(tick_ansindex733, tick_ansdelta745, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m824) {
                        u64 v_c33 = m824[1];
                        if (!slog::exists_probe<3,1>(evalindex734, std::array<u64,3>{v_c33, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex735, closuredelta746, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m825) {
                          u64 v_c137 = m825[1]; u64 v_c45 = m825[2];
                          slog::join_probe_old<3,1>(lambdaindex736, lambdadelta747, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m826) {
                            u64 v_c48 = m826[1]; u64 v_c2 = m826[2];
                            slog::join_probe_old<3,2>(evalindex737, evaldelta748, std::array<u64,3>{v_c2, v_c33, 0}, [&](const std::array<u64,3>& m827) {
                              u64 v_c138 = m827[2];
                              slog::join_probe_old<2,1>(eval_ansindex738, eval_ansdelta749, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m828) {
                                u64 v_c9 = m828[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c9}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_args_ans", _fires);
  
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
  // (crule (pre) (scan scheme_false fv) (body (join-old select_branch (0 1 2 3) 0 (0 1 2 3) __t13sL3 tv e2 e3) (neq tv fv)) (head (emit select_branch_ans (0 1) __t13sL3 e2)) interp.slog:85 #f)
  class ReadTask831 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex829;  slog::Index** select_branchdelta830;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord832({0, 1});
      slog::Relation* readrel833 = db->getRelation("select_branch_ans");
      head_index[0] = readrel833->getIndex(ord832, false);
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord834({0, 1, 2, 3});
      slog::Relation* readrel835 = db->getRelation("select_branch");
      select_branchindex829 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1, 2, 3});
      slog::Relation* readrel837 = db->getRelation("select_branch");
      select_branchdelta830 = readrel837->getIndex(ord836, true);
  
    }
    ReadTask831(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c139 = _t[0];
        slog::join_all_old<4>(select_branchindex829, select_branchdelta830, [&](const std::array<u64,4>& m838) {
          u64 v_c140 = m838[0]; u64 v_c141 = m838[1]; u64 v_c92 = m838[2]; u64 v_c93 = m838[3];
          if (v_c141 == v_c139) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c140, v_c92}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:scheme_false", _fires);
  
      if (!_done)
      {
        ReadTask831* _cont = new ReadTask831(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask831(db,b), false);
  // (crule (pre (let __tconst6UQc687 constb9e118781cea1f9fa01462e0) (let __tconst2Qtx688 const0122baa3ac55f1b433944eb1) (let __tconst6Cg6137 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9tfN494 const6b86b273ff34fce19d6b804e) (let _00024sqc0jHU495 const5feceb66ffc86f38d952786c) (let _00024sqo7x4Q496 const5feceb66ffc86f38d952786c) (let _00024sqo5KfU497 const5feceb66ffc86f38d952786c)) (scan boolval __t687V140 __t4aV2139) (body (join _enum (0 1) 2 __t4aV2139 __tconst6UQc687) (exists $seq_atr (1 0 2) 2 _00024sqo5KfU497 __t687V140) (exists delta (1 2 0) 1 __tconst6Cg6137) (exists _enum (1 0) 1 __tconst2Qtx688) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7x4Q496 __t687V140 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5KfU497 __t687V140 _00024seq1) (join delta (1 2 0) 2 __tconst6Cg6137 _00024seq1 __t2pLy138) (join _enum (1 0) 1 __tconst2Qtx688 __t67wA135) (letp _00024sql9r92492 (aslst _00024seq1)) (let chk4KVf992 (llen _00024sql9r92492)) (eq _00024sqc9tfN494 chk4KVf992) (letp chk3YSg993 (lref _00024sql9r92492 _00024sqc0jHU495)) (eq __t687V140 chk3YSg993)) (head (emit-temp temp0a5K990 __t2pLy138) (mkstruct boolval (1 0) __t5iPS136 __t67wA135)) interp.slog:113 #f)
  class ReadTask849 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex839;  slog::Index** $seq_atrindex840;  slog::Index** deltaindex841;  slog::Index** _enumindex842;  slog::Index** $seq_atindex843;  slog::Index** $seq_atrindex844;  slog::Index** deltaindex845;  slog::Index** _enumindex846;  slog::Index** $seq_atdelta847;  slog::Index** $seq_atrdelta848;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0a5K990");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord850({0, 1});
      slog::Relation* readrel851 = db->getRelation("_enum");
      _enumindex839 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 0, 2});
      slog::Relation* readrel853 = db->getRelation("$seq_atr");
      $seq_atrindex840 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 0});
      slog::Relation* readrel855 = db->getRelation("delta");
      deltaindex841 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 0});
      slog::Relation* readrel857 = db->getRelation("_enum");
      _enumindex842 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 0, 2});
      slog::Relation* readrel859 = db->getRelation("$seq_at");
      $seq_atindex843 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 0, 2});
      slog::Relation* readrel861 = db->getRelation("$seq_at");
      $seq_atdelta847 = readrel861->getIndex(ord860, true);
      std::vector<u16> ord862({1, 0, 2});
      slog::Relation* readrel863 = db->getRelation("$seq_atr");
      $seq_atrindex844 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 0, 2});
      slog::Relation* readrel865 = db->getRelation("$seq_atr");
      $seq_atrdelta848 = readrel865->getIndex(ord864, true);
      std::vector<u16> ord866({1, 2, 0});
      slog::Relation* readrel867 = db->getRelation("delta");
      deltaindex845 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({1, 0});
      slog::Relation* readrel869 = db->getRelation("_enum");
      _enumindex846 = readrel869->getIndex(ord868, false);
  
    }
    ReadTask849(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c61 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c62 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c70 = _t[1];
        slog::join_probe<2,2>(_enumindex839, std::array<u64,2>{v_c70, v_c60}, [&](const std::array<u64,2>& m870) {
          if (!slog::exists_probe<3,2>($seq_atrindex840, std::array<u64,3>{v_c66, v_c67, 0})) return;
          if (!slog::exists_probe<3,1>(deltaindex841, std::array<u64,3>{v_c62, 0, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex842, std::array<u64,2>{v_c61, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex843, $seq_atdelta847, std::array<u64,3>{v_c65, v_c67, 0}, [&](const std::array<u64,3>& m871) {
            u64 v_c68 = m871[2];
            slog::join_probe_old<3,3>($seq_atrindex844, $seq_atrdelta848, std::array<u64,3>{v_c66, v_c67, v_c68}, [&](const std::array<u64,3>& m872) {
              slog::join_probe<3,2>(deltaindex845, std::array<u64,3>{v_c62, v_c68, 0}, [&](const std::array<u64,3>& m873) {
                u64 v_c69 = m873[2];
                slog::join_probe<2,1>(_enumindex846, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m874) {
                  u64 v_c71 = m874[1];
                  bool ok875 = true;
                  u64 v_c72 = _prim_aslst(db, v_c68, &ok875);
                  if (!ok875) return;
                  u64 v_c142 = _prim_llen(db, v_c72);
                  if (v_c142 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c63 != v_c142) return;
                  bool ok876 = true;
                  u64 v_c143 = _prim_lref(db, v_c72, v_c64, &ok876);
                  if (!ok876) return;
                  if (v_c67 != v_c143) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c69});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
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
        ReadTask849* _cont = new ReadTask849(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask849(db,b), false);
  // (crule (pre) (scan if __t2hNa34 e1 e2 e3) (body (join-old eval (1 2 0) 1 (1 2 0) __t2hNa34 c __t6Md835)) (head (emit $sup56712x86x0x0x0 (1 0 2 3 4) c __t6Md835 e1 e2 e3)) interp.slog:87 #f)
  class ReadTask879 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex877;  slog::Index** evaldelta878;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord880({1, 0, 2, 3, 4});
      slog::Relation* readrel881 = db->getRelation("$sup56712x86x0x0x0");
      head_index[0] = readrel881->getIndex(ord880, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord882({1, 2, 0});
      slog::Relation* readrel883 = db->getRelation("eval");
      evalindex877 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("eval");
      evaldelta878 = readrel885->getIndex(ord884, true);
  
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
        u64 v_c144 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        u64 v_c93 = _t[3];
        slog::join_probe_old<3,1>(evalindex877, evaldelta878, std::array<u64,3>{v_c144, 0, 0}, [&](const std::array<u64,3>& m886) {
          u64 v_c1 = m886[1]; u64 v_c145 = m886[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c1, v_c145, v_c91, v_c92, v_c93}, std::array<u16,5>{1, 0, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:if", _fires);
  
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
  // (crule (pre) (scan closure __t6CK626 __t3miO28 cb) (body (exists freevar (1 0) 1 __t3miO28) (exists binding (1 0 2) 1 cb) (join eval_ans (1 0) 1 __t6CK626 __t84Ji24) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join eval (0 2 1) 1 __t84Ji24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join tick_ans (0 1) 1 __t0NvE30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask910 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex887;  slog::Index** bindingindex888;  slog::Index** eval_ansindex889;  slog::Index** freevarindex890;  slog::Index** bindingindex891;  slog::Index** evalindex892;  slog::Index** appindex893;  slog::Index** eval_argsindex894;  slog::Index** tickindex895;  slog::Index** evalindex896;  slog::Index** tickindex897;  slog::Index** appindex898;  slog::Index** eval_argsindex899;  slog::Index** eval_args_ansindex900;  slog::Index** tickindex901;  slog::Index** tick_ansindex902;  slog::Index** eval_args_ansindex903;  slog::Index** tick_ansindex904;  slog::Index** lambdaindex905;  slog::Index** appdelta906;  slog::Index** eval_argsdelta907;  slog::Index** tickdelta908;  slog::Index** lambdadelta909;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord911({0, 1, 2});
      slog::Relation* readrel912 = db->getRelation("binding");
      head_index[0] = readrel912->getIndex(ord911, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord913({0, 1, 2});
      slog::Relation* readrel914 = db->getRelation("binding_event");
      head_index[1] = readrel914->getIndex(ord913, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord915({1, 0});
      slog::Relation* readrel916 = db->getRelation("freevar");
      freevarindex887 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 0, 2});
      slog::Relation* readrel918 = db->getRelation("binding");
      bindingindex888 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 0});
      slog::Relation* readrel920 = db->getRelation("eval_ans");
      eval_ansindex889 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 0});
      slog::Relation* readrel922 = db->getRelation("freevar");
      freevarindex890 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({0, 1, 2});
      slog::Relation* readrel924 = db->getRelation("binding");
      bindingindex891 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 2, 1});
      slog::Relation* readrel926 = db->getRelation("eval");
      evalindex892 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({1, 2, 0});
      slog::Relation* readrel928 = db->getRelation("app");
      appindex893 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({2, 0, 1});
      slog::Relation* readrel930 = db->getRelation("eval_args");
      eval_argsindex894 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({2, 0, 1});
      slog::Relation* readrel932 = db->getRelation("tick");
      tickindex895 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({2, 0, 1});
      slog::Relation* readrel934 = db->getRelation("eval");
      evalindex896 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 2, 0});
      slog::Relation* readrel936 = db->getRelation("tick");
      tickindex897 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({0, 1, 2});
      slog::Relation* readrel938 = db->getRelation("app");
      appindex898 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({0, 1, 2});
      slog::Relation* readrel940 = db->getRelation("app");
      appdelta906 = readrel940->getIndex(ord939, true);
      std::vector<u16> ord941({1, 2, 0});
      slog::Relation* readrel942 = db->getRelation("eval_args");
      eval_argsindex899 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 0});
      slog::Relation* readrel944 = db->getRelation("eval_args");
      eval_argsdelta907 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({0, 1});
      slog::Relation* readrel946 = db->getRelation("eval_args_ans");
      eval_args_ansindex900 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("tick");
      tickindex901 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 0});
      slog::Relation* readrel950 = db->getRelation("tick");
      tickdelta908 = readrel950->getIndex(ord949, true);
      std::vector<u16> ord951({0, 1});
      slog::Relation* readrel952 = db->getRelation("tick_ans");
      tick_ansindex902 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({0, 1});
      slog::Relation* readrel954 = db->getRelation("eval_args_ans");
      eval_args_ansindex903 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({0, 1});
      slog::Relation* readrel956 = db->getRelation("tick_ans");
      tick_ansindex904 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({0, 1, 2});
      slog::Relation* readrel958 = db->getRelation("lambda");
      lambdaindex905 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({0, 1, 2});
      slog::Relation* readrel960 = db->getRelation("lambda");
      lambdadelta909 = readrel960->getIndex(ord959, true);
  
    }
    ReadTask910(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<2,1>(freevarindex887, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<3,1>(bindingindex888, std::array<u64,3>{v_c45, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex889, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m961) {
          u64 v_c38 = m961[1];
          slog::join_probe<2,1>(freevarindex890, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m962) {
            u64 v_c46 = m962[1];
            slog::join_probe<3,2>(bindingindex891, std::array<u64,3>{v_c46, v_c45, 0}, [&](const std::array<u64,3>& m963) {
              u64 v_c47 = m963[2];
              slog::join_probe<3,1>(evalindex892, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m964) {
                u64 v_c1 = m964[1]; u64 v_c35 = m964[2];
                if (!slog::exists_probe<3,1>(appindex893, std::array<u64,3>{v_c35, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex894, std::array<u64,3>{v_c1, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex895, std::array<u64,3>{v_c1, 0, 0})) return;
                slog::join_probe<3,1>(evalindex896, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m965) {
                  u64 v_c37 = m965[1]; u64 v_c34 = m965[2];
                  if (!slog::exists_probe<3,2>(tickindex897, std::array<u64,3>{v_c34, v_c1, 0})) return;
                  slog::join_probe_old<3,2>(appindex898, appdelta906, std::array<u64,3>{v_c34, v_c35, 0}, [&](const std::array<u64,3>& m966) {
                    u64 v_c36 = m966[2];
                    slog::join_probe_old<3,2>(eval_argsindex899, eval_argsdelta907, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m967) {
                      u64 v_c39 = m967[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex900, std::array<u64,2>{v_c39, 0})) return;
                      slog::join_probe_old<3,2>(tickindex901, tickdelta908, std::array<u64,3>{v_c34, v_c1, 0}, [&](const std::array<u64,3>& m968) {
                        u64 v_c40 = m968[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex902, std::array<u64,2>{v_c40, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex903, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m969) {
                          u64 v_c42 = m969[1];
                          slog::join_probe<2,1>(tick_ansindex904, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m970) {
                            u64 v_c43 = m970[1];
                            slog::join_probe_old<3,1>(lambdaindex905, lambdadelta909, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m971) {
                              u64 v_c48 = m971[1]; u64 v_c2 = m971[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c46, v_c43, v_c47}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c46, v_c43, v_c1}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask910* _cont = new ReadTask910(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask910(db,b), false);
  // (crule (pre) (scan eval __9hFj634 __t9408360 c) (body (join-old eval (2 0 1) 1 (2 0 1) c __t1yWg361 er) (exists eval_ans (0 1) 1 __t1yWg361) (join-old let (0 2 1 3) 2 (0 2 1 3) __t9408360 er x eb) (join-old eval_ans (0 1) 1 (0 1) __t1yWg361 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask979 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex972;  slog::Index** eval_ansindex973;  slog::Index** letindex974;  slog::Index** eval_ansindex975;  slog::Index** evaldelta976;  slog::Index** letdelta977;  slog::Index** eval_ansdelta978;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord980({0, 1, 2});
      slog::Relation* readrel981 = db->getRelation("binding");
      head_index[0] = readrel981->getIndex(ord980, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord982({0, 1, 2});
      slog::Relation* readrel983 = db->getRelation("binding_event");
      head_index[1] = readrel983->getIndex(ord982, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord984({2, 0, 1});
      slog::Relation* readrel985 = db->getRelation("eval");
      evalindex972 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({2, 0, 1});
      slog::Relation* readrel987 = db->getRelation("eval");
      evaldelta976 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("eval_ans");
      eval_ansindex973 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 2, 1, 3});
      slog::Relation* readrel991 = db->getRelation("let");
      letindex974 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({0, 2, 1, 3});
      slog::Relation* readrel993 = db->getRelation("let");
      letdelta977 = readrel993->getIndex(ord992, true);
      std::vector<u16> ord994({0, 1});
      slog::Relation* readrel995 = db->getRelation("eval_ans");
      eval_ansindex975 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({0, 1});
      slog::Relation* readrel997 = db->getRelation("eval_ans");
      eval_ansdelta978 = readrel997->getIndex(ord996, true);
  
    }
    ReadTask979(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c147 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe_old<3,1>(evalindex972, evaldelta976, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m998) {
          u64 v_c148 = m998[1]; u64 v_c3 = m998[2];
          if (!slog::exists_probe<2,1>(eval_ansindex973, std::array<u64,2>{v_c148, 0})) return;
          slog::join_probe_old<4,2>(letindex974, letdelta977, std::array<u64,4>{v_c147, v_c3, 0, 0}, [&](const std::array<u64,4>& m999) {
            u64 v_c4 = m999[2]; u64 v_c2 = m999[3];
            slog::join_probe_old<2,1>(eval_ansindex975, eval_ansdelta978, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m1000) {
              u64 v_c8 = m1000[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c4, v_c1, v_c8}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c4, v_c1, v_c1}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask979* _cont = new ReadTask979(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask979(db,b), false);
  // (crule (pre (let __trid3Ey3582 const342a69eb5a93251c8b7e179a) (let __trel65ch583 constf6cdc3db4b71e0cdeda6912e) (let __tcol4Ars584 const6b86b273ff34fce19d6b804e) (let __trel1pCT585 constf6cdc3db4b71e0cdeda6912e) (let __tcol8ZHX586 constd4735e3a265e16eee03f5971)) (scan eval_ans __t9qzE362 __v0) (body (join-old eval (0 2 1) 1 (0 2 1) __t9qzE362 c e1) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel65ch583 __tcol4Ars584 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel1pCT585 __tcol8ZHX586 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __9nb7581 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask1013 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1001;  slog::Index** $sup56712x86x0x0x0index1002;  slog::Index** evaldelta1003;
    u32 sid1004;  u32 sid1005;  u32 sid1006;  u32 sid1007;  u32 sid1008;  u32 sid1009;  u32 sid1010;  u32 sid1011;  u32 sid1012;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1014({0, 2, 1});
      slog::Relation* readrel1015 = db->getRelation("eval");
      evalindex1001 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({0, 2, 1});
      slog::Relation* readrel1017 = db->getRelation("eval");
      evaldelta1003 = readrel1017->getIndex(ord1016, true);
      std::vector<u16> ord1018({1, 2, 0, 3, 4});
      slog::Relation* readrel1019 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1002 = readrel1019->getIndex(ord1018, false);
      sid1004 = db->getRelation("app")->getStructId();
      sid1005 = db->getRelation("boolean")->getStructId();
      sid1006 = db->getRelation("if")->getStructId();
      sid1007 = db->getRelation("lambda")->getStructId();
      sid1008 = db->getRelation("let")->getStructId();
      sid1009 = db->getRelation("letrec")->getStructId();
      sid1010 = db->getRelation("num")->getStructId();
      sid1011 = db->getRelation("ref")->getStructId();
      sid1012 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1013(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c150 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c152 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c153 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c154 = _t[0];
        u64 v_c33 = _t[1];
        slog::join_probe_old<3,1>(evalindex1001, evaldelta1003, std::array<u64,3>{v_c154, 0, 0}, [&](const std::array<u64,3>& m1020) {
          u64 v_c1 = m1020[1]; u64 v_c91 = m1020[2];
          slog::join_probe<5,2>($sup56712x86x0x0x0index1002, std::array<u64,5>{v_c1, v_c91, 0, 0, 0}, [&](const std::array<u64,5>& m1021) {
            u64 v_c75 = m1021[2]; u64 v_c92 = m1021[3]; u64 v_c93 = m1021[4];
            ++_fires;
            if (!((is_struct(v_c92) && (decode_struct_id(v_c92) == sid1004 || decode_struct_id(v_c92) == sid1005 || decode_struct_id(v_c92) == sid1006 || decode_struct_id(v_c92) == sid1007 || decode_struct_id(v_c92) == sid1008 || decode_struct_id(v_c92) == sid1009 || decode_struct_id(v_c92) == sid1010 || decode_struct_id(v_c92) == sid1011 || decode_struct_id(v_c92) == sid1012))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c149, v_c150, v_c151, v_c92}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c93) && (decode_struct_id(v_c93) == sid1004 || decode_struct_id(v_c93) == sid1005 || decode_struct_id(v_c93) == sid1006 || decode_struct_id(v_c93) == sid1007 || decode_struct_id(v_c93) == sid1008 || decode_struct_id(v_c93) == sid1009 || decode_struct_id(v_c93) == sid1010 || decode_struct_id(v_c93) == sid1011 || decode_struct_id(v_c93) == sid1012))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c149, v_c152, v_c153, v_c93}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c33, v_c92, v_c93}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1013* _cont = new ReadTask1013(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1013(db,b), false);
  // (crule (pre (let __tconst5QMk601 constcd2a69ce5ca278db1d6da969)) (scan num __t5ViU9 n) (body (exists eval (1 2 0) 1 __t5ViU9) (join _enum (1 0) 1 __tconst5QMk601 __t0FqU8) (join-old eval (1 2 0) 1 (1 2 0) __t5ViU9 c __t0S0V10)) (head (emit eval_ans (0 1) __t0S0V10 __t0FqU8)) interp.slog:26 #f)
  class ReadTask1026 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1022;  slog::Index** _enumindex1023;  slog::Index** evalindex1024;  slog::Index** evaldelta1025;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1027({0, 1});
      slog::Relation* readrel1028 = db->getRelation("eval_ans");
      head_index[0] = readrel1028->getIndex(ord1027, false);
      outer_rel = db->getRelation("num");
      std::vector<u16> ord1029({1, 2, 0});
      slog::Relation* readrel1030 = db->getRelation("eval");
      evalindex1022 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 0});
      slog::Relation* readrel1032 = db->getRelation("_enum");
      _enumindex1023 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 2, 0});
      slog::Relation* readrel1034 = db->getRelation("eval");
      evalindex1024 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 0});
      slog::Relation* readrel1036 = db->getRelation("eval");
      evaldelta1025 = readrel1036->getIndex(ord1035, true);
  
    }
    ReadTask1026(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c155 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c156 = _t[0];
        u64 v_c157 = _t[1];
        if (!slog::exists_probe<3,1>(evalindex1022, std::array<u64,3>{v_c156, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex1023, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m1037) {
          u64 v_c158 = m1037[1];
          slog::join_probe_old<3,1>(evalindex1024, evaldelta1025, std::array<u64,3>{v_c156, 0, 0}, [&](const std::array<u64,3>& m1038) {
            u64 v_c1 = m1038[1]; u64 v_c159 = m1038[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c159, v_c158}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:26", "delta:num", _fires);
  
      if (!_done)
      {
        ReadTask1026* _cont = new ReadTask1026(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1026(db,b), false);
  // (crule (pre) (scan if __t5qA5344 e1 e2 e3) (body (join freevar (1 0) 1 e3 x)) (head (emit freevar (0 1) x __t5qA5344)) freevars.slog:17 #f)
  class ReadTask1040 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1039;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1041({0, 1});
      slog::Relation* readrel1042 = db->getRelation("freevar");
      head_index[0] = readrel1042->getIndex(ord1041, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord1043({1, 0});
      slog::Relation* readrel1044 = db->getRelation("freevar");
      freevarindex1039 = readrel1044->getIndex(ord1043, false);
  
    }
    ReadTask1040(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c160 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        u64 v_c93 = _t[3];
        slog::join_probe<2,1>(freevarindex1039, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1045) {
          u64 v_c4 = m1045[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c160}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask1040* _cont = new ReadTask1040(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1040(db,b), false);
  // (crule (pre) (scan freevar x er) (body (join-old let (2 1 3 0) 1 (2 1 3 0) er y eb __t0pzR116)) (head (emit freevar (0 1) x __t0pzR116)) freevars.slog:21 #f)
  class ReadTask1048 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1046;  slog::Index** letdelta1047;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1049({0, 1});
      slog::Relation* readrel1050 = db->getRelation("freevar");
      head_index[0] = readrel1050->getIndex(ord1049, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1051({2, 1, 3, 0});
      slog::Relation* readrel1052 = db->getRelation("let");
      letindex1046 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({2, 1, 3, 0});
      slog::Relation* readrel1054 = db->getRelation("let");
      letdelta1047 = readrel1054->getIndex(ord1053, true);
  
    }
    ReadTask1048(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        slog::join_probe_old<4,1>(letindex1046, letdelta1047, std::array<u64,4>{v_c3, 0, 0, 0}, [&](const std::array<u64,4>& m1055) {
          u64 v_c46 = m1055[1]; u64 v_c2 = m1055[2]; u64 v_c101 = m1055[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c101}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:21", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1048* _cont = new ReadTask1048(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1048(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (scan prim __t5NWC164 op) (body (exists $seq_at (1 0 2) 2 _00024sqo2Tf4478 __t5NWC164) (exists $seq_atr (1 0 2) 2 _00024sqo8e4d479 __t5NWC164) (exists $seq_atr (1 0 2) 2 _00024sqo87UW480 __t5NWC164) (exists delta (1 2 0) 1 __tconst6e36161) (exists _enum (1 0) 1 __tconst0GOL695) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo5t7q477 __t5NWC164 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2Tf4478 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8e4d479 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo87UW480 __t5NWC164 _00024seq2) (join delta (1 2 0) 2 __tconst6e36161 _00024seq2 __t2Zbc162) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (letp _00024sql8XpT472 (aslst _00024seq2)) (let chk2WUP975 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk2WUP975) (letp chk1m2e976 (lref _00024sql8XpT472 _00024sqc8EM3475)) (eq __t5NWC164 chk1m2e976) (letp chk1XAv977 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk1XAv977)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask1071 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1056;  slog::Index** $seq_atrindex1057;  slog::Index** $seq_atrindex1058;  slog::Index** deltaindex1059;  slog::Index** _enumindex1060;  slog::Index** $seq_atindex1061;  slog::Index** $seq_atindex1062;  slog::Index** $seq_atrindex1063;  slog::Index** $seq_atrindex1064;  slog::Index** deltaindex1065;  slog::Index** _enumindex1066;  slog::Index** $seq_atdelta1067;  slog::Index** $seq_atdelta1068;  slog::Index** $seq_atrdelta1069;  slog::Index** $seq_atrdelta1070;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord1072({1, 0, 2});
      slog::Relation* readrel1073 = db->getRelation("$seq_at");
      $seq_atindex1056 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 0, 2});
      slog::Relation* readrel1075 = db->getRelation("$seq_atr");
      $seq_atrindex1057 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({1, 0, 2});
      slog::Relation* readrel1077 = db->getRelation("$seq_atr");
      $seq_atrindex1058 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 2, 0});
      slog::Relation* readrel1079 = db->getRelation("delta");
      deltaindex1059 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 0});
      slog::Relation* readrel1081 = db->getRelation("_enum");
      _enumindex1060 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 0, 2});
      slog::Relation* readrel1083 = db->getRelation("$seq_at");
      $seq_atindex1061 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 0, 2});
      slog::Relation* readrel1085 = db->getRelation("$seq_at");
      $seq_atdelta1067 = readrel1085->getIndex(ord1084, true);
      std::vector<u16> ord1086({1, 0, 2});
      slog::Relation* readrel1087 = db->getRelation("$seq_at");
      $seq_atindex1062 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({1, 0, 2});
      slog::Relation* readrel1089 = db->getRelation("$seq_at");
      $seq_atdelta1068 = readrel1089->getIndex(ord1088, true);
      std::vector<u16> ord1090({1, 0, 2});
      slog::Relation* readrel1091 = db->getRelation("$seq_atr");
      $seq_atrindex1063 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 0, 2});
      slog::Relation* readrel1093 = db->getRelation("$seq_atr");
      $seq_atrdelta1069 = readrel1093->getIndex(ord1092, true);
      std::vector<u16> ord1094({1, 0, 2});
      slog::Relation* readrel1095 = db->getRelation("$seq_atr");
      $seq_atrindex1064 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({1, 0, 2});
      slog::Relation* readrel1097 = db->getRelation("$seq_atr");
      $seq_atrdelta1070 = readrel1097->getIndex(ord1096, true);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("delta");
      deltaindex1065 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 0});
      slog::Relation* readrel1101 = db->getRelation("_enum");
      _enumindex1066 = readrel1101->getIndex(ord1100, false);
  
    }
    ReadTask1071(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c161 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c162 = v_const06abaa100ecef791ce028c56;
      u64 v_c163 = v_constd4735e3a265e16eee03f5971;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
      u64 v_c165 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c166 = v_const5feceb66ffc86f38d952786c;
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c168 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c169 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c170 = _t[0];
        u64 v_c54 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex1056, std::array<u64,3>{v_c167, v_c170, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1057, std::array<u64,3>{v_c168, v_c170, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1058, std::array<u64,3>{v_c169, v_c170, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex1059, std::array<u64,3>{v_c162, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex1060, std::array<u64,2>{v_c161, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1061, $seq_atdelta1067, std::array<u64,3>{v_c166, v_c170, 0}, [&](const std::array<u64,3>& m1102) {
          u64 v_c112 = m1102[2];
          slog::join_probe_old<3,3>($seq_atindex1062, $seq_atdelta1068, std::array<u64,3>{v_c167, v_c170, v_c112}, [&](const std::array<u64,3>& m1103) {
            slog::join_probe_old<3,3>($seq_atrindex1063, $seq_atrdelta1069, std::array<u64,3>{v_c168, v_c170, v_c112}, [&](const std::array<u64,3>& m1104) {
              slog::join_probe_old<3,3>($seq_atrindex1064, $seq_atrdelta1070, std::array<u64,3>{v_c169, v_c170, v_c112}, [&](const std::array<u64,3>& m1105) {
                slog::join_probe<3,2>(deltaindex1065, std::array<u64,3>{v_c162, v_c112, 0}, [&](const std::array<u64,3>& m1106) {
                  u64 v_c171 = m1106[2];
                  slog::join_probe<2,1>(_enumindex1066, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m1107) {
                    u64 v_c172 = m1107[1];
                    bool ok1108 = true;
                    u64 v_c173 = _prim_aslst(db, v_c112, &ok1108);
                    if (!ok1108) return;
                    u64 v_c174 = _prim_llen(db, v_c173);
                    if (v_c174 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c163 != v_c174) return;
                    bool ok1109 = true;
                    u64 v_c175 = _prim_lref(db, v_c173, v_c164, &ok1109);
                    if (!ok1109) return;
                    if (v_c170 != v_c175) return;
                    bool ok1110 = true;
                    u64 v_c176 = _prim_lref(db, v_c173, v_c165, &ok1110);
                    if (!ok1110) return;
                    if (v_c170 != v_c176) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c171});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c172}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:prim", _fires);
  
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
  // (crule (pre) (scan freevar x eb) (body (join-old let (3 0 1 2) 1 (3 0 1 2) eb __t6Jt9132 y er) (neq x y)) (head (emit freevar (0 1) x __t6Jt9132)) freevars.slog:22 #f)
  class ReadTask1113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1111;  slog::Index** letdelta1112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1114({0, 1});
      slog::Relation* readrel1115 = db->getRelation("freevar");
      head_index[0] = readrel1115->getIndex(ord1114, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1116({3, 0, 1, 2});
      slog::Relation* readrel1117 = db->getRelation("let");
      letindex1111 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({3, 0, 1, 2});
      slog::Relation* readrel1119 = db->getRelation("let");
      letdelta1112 = readrel1119->getIndex(ord1118, true);
  
    }
    ReadTask1113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        slog::join_probe_old<4,1>(letindex1111, letdelta1112, std::array<u64,4>{v_c2, 0, 0, 0}, [&](const std::array<u64,4>& m1120) {
          u64 v_c177 = m1120[1]; u64 v_c46 = m1120[2]; u64 v_c3 = m1120[3];
          if (v_c4 == v_c46) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c177}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:22", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1113* _cont = new ReadTask1113(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1113(db,b), false);
  // (crule (pre) (scan eval_args_ans __t4aOO390 vs) (body (exists delta (2 0 1) 1 vs) (join-old eval_args (0 2 1) 1 (0 2 1) __t4aOO390 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (join-old $sup56712x74x0x0x0 (1 3 0 2) 2 (1 3 0 2) c es __t0zOO387 ef) (exists eval (0 2 1) 2 __t0zOO387 c) (exists eval (1 2 0) 2 ef c) (join-old app (1 2 0) 2 (1 2 0) ef es __t2JOw386) (join-old eval (0 2 1) 3 (0 2 1) __t0zOO387 c __t2JOw386) (join-old eval (1 2 0) 2 (1 2 0) ef c __t9EYC388) (join eval_ans (0 1) 1 __t9EYC388 __t22Li389) (join-old prim (0 1) 1 (0 1) __t22Li389 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t3FWR391) (join-old delta_ans (0 1) 1 (0 1) __t3FWR391 v)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask1143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex1121;  slog::Index** eval_argsindex1122;  slog::Index** appindex1123;  slog::Index** evalindex1124;  slog::Index** $sup56712x74x0x0x0index1125;  slog::Index** evalindex1126;  slog::Index** evalindex1127;  slog::Index** appindex1128;  slog::Index** evalindex1129;  slog::Index** evalindex1130;  slog::Index** eval_ansindex1131;  slog::Index** primindex1132;  slog::Index** deltaindex1133;  slog::Index** delta_ansindex1134;  slog::Index** eval_argsdelta1135;  slog::Index** $sup56712x74x0x0x0delta1136;  slog::Index** appdelta1137;  slog::Index** evaldelta1138;  slog::Index** evaldelta1139;  slog::Index** primdelta1140;  slog::Index** deltadelta1141;  slog::Index** delta_ansdelta1142;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1144({0, 1});
      slog::Relation* readrel1145 = db->getRelation("eval_ans");
      head_index[0] = readrel1145->getIndex(ord1144, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord1146({2, 0, 1});
      slog::Relation* readrel1147 = db->getRelation("delta");
      deltaindex1121 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({0, 2, 1});
      slog::Relation* readrel1149 = db->getRelation("eval_args");
      eval_argsindex1122 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({0, 2, 1});
      slog::Relation* readrel1151 = db->getRelation("eval_args");
      eval_argsdelta1135 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({2, 0, 1});
      slog::Relation* readrel1153 = db->getRelation("app");
      appindex1123 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({2, 0, 1});
      slog::Relation* readrel1155 = db->getRelation("eval");
      evalindex1124 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({1, 3, 0, 2});
      slog::Relation* readrel1157 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index1125 = readrel1157->getIndex(ord1156, false);
      std::vector<u16> ord1158({1, 3, 0, 2});
      slog::Relation* readrel1159 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta1136 = readrel1159->getIndex(ord1158, true);
      std::vector<u16> ord1160({0, 2, 1});
      slog::Relation* readrel1161 = db->getRelation("eval");
      evalindex1126 = readrel1161->getIndex(ord1160, false);
      std::vector<u16> ord1162({1, 2, 0});
      slog::Relation* readrel1163 = db->getRelation("eval");
      evalindex1127 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({1, 2, 0});
      slog::Relation* readrel1165 = db->getRelation("app");
      appindex1128 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({1, 2, 0});
      slog::Relation* readrel1167 = db->getRelation("app");
      appdelta1137 = readrel1167->getIndex(ord1166, true);
      std::vector<u16> ord1168({0, 2, 1});
      slog::Relation* readrel1169 = db->getRelation("eval");
      evalindex1129 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({0, 2, 1});
      slog::Relation* readrel1171 = db->getRelation("eval");
      evaldelta1138 = readrel1171->getIndex(ord1170, true);
      std::vector<u16> ord1172({1, 2, 0});
      slog::Relation* readrel1173 = db->getRelation("eval");
      evalindex1130 = readrel1173->getIndex(ord1172, false);
      std::vector<u16> ord1174({1, 2, 0});
      slog::Relation* readrel1175 = db->getRelation("eval");
      evaldelta1139 = readrel1175->getIndex(ord1174, true);
      std::vector<u16> ord1176({0, 1});
      slog::Relation* readrel1177 = db->getRelation("eval_ans");
      eval_ansindex1131 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({0, 1});
      slog::Relation* readrel1179 = db->getRelation("prim");
      primindex1132 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({0, 1});
      slog::Relation* readrel1181 = db->getRelation("prim");
      primdelta1140 = readrel1181->getIndex(ord1180, true);
      std::vector<u16> ord1182({1, 2, 0});
      slog::Relation* readrel1183 = db->getRelation("delta");
      deltaindex1133 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({1, 2, 0});
      slog::Relation* readrel1185 = db->getRelation("delta");
      deltadelta1141 = readrel1185->getIndex(ord1184, true);
      std::vector<u16> ord1186({0, 1});
      slog::Relation* readrel1187 = db->getRelation("delta_ans");
      delta_ansindex1134 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({0, 1});
      slog::Relation* readrel1189 = db->getRelation("delta_ans");
      delta_ansdelta1142 = readrel1189->getIndex(ord1188, true);
  
    }
    ReadTask1143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c42 = _t[1];
        if (!slog::exists_probe<3,1>(deltaindex1121, std::array<u64,3>{v_c42, 0, 0})) return;
        slog::join_probe_old<3,1>(eval_argsindex1122, eval_argsdelta1135, std::array<u64,3>{v_c52, 0, 0}, [&](const std::array<u64,3>& m1190) {
          u64 v_c1 = m1190[1]; u64 v_c36 = m1190[2];
          if (!slog::exists_probe<3,1>(appindex1123, std::array<u64,3>{v_c36, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1124, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x74x0x0x0index1125, $sup56712x74x0x0x0delta1136, std::array<u64,4>{v_c1, v_c36, 0, 0}, [&](const std::array<u64,4>& m1191) {
            u64 v_c50 = m1191[2]; u64 v_c35 = m1191[3];
            if (!slog::exists_probe<3,2>(evalindex1126, std::array<u64,3>{v_c50, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex1127, std::array<u64,3>{v_c35, v_c1, 0})) return;
            slog::join_probe_old<3,2>(appindex1128, appdelta1137, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m1192) {
              u64 v_c51 = m1192[2];
              slog::join_probe_old<3,3>(evalindex1129, evaldelta1138, std::array<u64,3>{v_c50, v_c1, v_c51}, [&](const std::array<u64,3>& m1193) {
                slog::join_probe_old<3,2>(evalindex1130, evaldelta1139, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m1194) {
                  u64 v_c49 = m1194[2];
                  slog::join_probe<2,1>(eval_ansindex1131, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m1195) {
                    u64 v_c53 = m1195[1];
                    slog::join_probe_old<2,1>(primindex1132, primdelta1140, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m1196) {
                      u64 v_c54 = m1196[1];
                      slog::join_probe_old<3,2>(deltaindex1133, deltadelta1141, std::array<u64,3>{v_c54, v_c42, 0}, [&](const std::array<u64,3>& m1197) {
                        u64 v_c55 = m1197[2];
                        slog::join_probe_old<2,1>(delta_ansindex1134, delta_ansdelta1142, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m1198) {
                          u64 v_c9 = m1198[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c9}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask1143* _cont = new ReadTask1143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1143(db,b), false);
  // (crule (pre) (scan type_mismatch __erre2ngW831 __errf5n9w832 __errf22RU833 __errf0hZM834 __errf0Jab835) (body) (head (emit error (0) __erre2ngW831)) <internal>:1 #f)
  class ReadTask1199 : public slog::Task
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
      std::vector<u16> ord1200({0});
      slog::Relation* readrel1201 = db->getRelation("error");
      head_index[0] = readrel1201->getIndex(ord1200, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask1199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[2];
        u64 v_c181 = _t[3];
        u64 v_c182 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c178}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask1199* _cont = new ReadTask1199(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1199(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a)) (scan temp1uko971 __t0GXe277 __t4sa5291) (body (join let (2 1 3 0) 3 __t4sa5291 __tconst7wlx292 __t0GXe277 __t9Jnj293)) (head (emit program (0) __t9Jnj293)) analysis-demo.slog:21 #f)
  class ReadTask1203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1204({0});
      slog::Relation* readrel1205 = db->getRelation("program");
      head_index[0] = readrel1205->getIndex(ord1204, false);
      outer_rel = db->getRelation("temp1uko971");
      std::vector<u16> ord1206({2, 1, 3, 0});
      slog::Relation* readrel1207 = db->getRelation("let");
      letindex1202 = readrel1207->getIndex(ord1206, false);
  
    }
    ReadTask1203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constdcc297bb3300d9549a9d611a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c183 = _t[0];
        u64 v_c84 = _t[1];
        slog::join_probe<4,3>(letindex1202, std::array<u64,4>{v_c84, v_c10, v_c183, 0}, [&](const std::array<u64,4>& m1208) {
          u64 v_c184 = m1208[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c184}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp1uko971", _fires);
  
      if (!_done)
      {
        ReadTask1203* _cont = new ReadTask1203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1203(db,b), false);
  // (crule (pre) (scan eval __t6Md835 __t2hNa34 c) (body (join if (0 1 2 3) 1 __t2hNa34 e1 e2 e3)) (head (emit $sup56712x86x0x0x0 (1 0 2 3 4) c __t6Md835 e1 e2 e3)) interp.slog:87 #f)
  class ReadTask1210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex1209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord1211({1, 0, 2, 3, 4});
      slog::Relation* readrel1212 = db->getRelation("$sup56712x86x0x0x0");
      head_index[0] = readrel1212->getIndex(ord1211, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1213({0, 1, 2, 3});
      slog::Relation* readrel1214 = db->getRelation("if");
      ifindex1209 = readrel1214->getIndex(ord1213, false);
  
    }
    ReadTask1210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c144 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<4,1>(ifindex1209, std::array<u64,4>{v_c144, 0, 0, 0}, [&](const std::array<u64,4>& m1215) {
          u64 v_c91 = m1215[1]; u64 v_c92 = m1215[2]; u64 v_c93 = m1215[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c1, v_c145, v_c91, v_c92, v_c93}, std::array<u16,5>{1, 0, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1210* _cont = new ReadTask1210(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1210(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5)) (scan temp0SQu1006 __t0Gv1110 __t7VwH92) (body (join let (2 1 3 0) 3 __t0Gv1110 __tconst2uSL111 __t7VwH92 __t7Zm1112)) (head (emit program (0) __t7Zm1112)) analysis-demo.slog:11 #f)
  class ReadTask1217 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1216;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1218({0});
      slog::Relation* readrel1219 = db->getRelation("program");
      head_index[0] = readrel1219->getIndex(ord1218, false);
      outer_rel = db->getRelation("temp0SQu1006");
      std::vector<u16> ord1220({2, 1, 3, 0});
      slog::Relation* readrel1221 = db->getRelation("let");
      letindex1216 = readrel1221->getIndex(ord1220, false);
  
    }
    ReadTask1217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const0457bba0679825d285ef7fa5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c186 = _t[0];
        u64 v_c187 = _t[1];
        slog::join_probe<4,3>(letindex1216, std::array<u64,4>{v_c186, v_c185, v_c187, 0}, [&](const std::array<u64,4>& m1222) {
          u64 v_c188 = m1222[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c188}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp0SQu1006", _fires);
  
      if (!_done)
      {
        ReadTask1217* _cont = new ReadTask1217(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1217(db,b), false);
  // (crule (pre) (scan app __t7cos183 ef es) (body (exists eval (1 2 0) 1 __t7cos183) (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t7cos183) (join $sup56712x41x0x0x0 (2 3 0 1) 2 ef es __t6uzd177 c) (join eval (0 2 1) 3 __t6uzd177 c __t7cos183) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t7cos183 c) (join eval (1 2 0) 2 ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join eval_args (1 2 0) 2 es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t4yWQ180 __t7rcY179 cb) (join lambda (0 1 2) 1 __t7rcY179 xs eb) (join eval (1 2 0) 2 eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask1246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1223;  slog::Index** evalindex1224;  slog::Index** eval_argsindex1225;  slog::Index** tickindex1226;  slog::Index** $sup56712x41x0x0x0index1227;  slog::Index** evalindex1228;  slog::Index** eval_argsindex1229;  slog::Index** tickindex1230;  slog::Index** evalindex1231;  slog::Index** eval_ansindex1232;  slog::Index** eval_argsindex1233;  slog::Index** eval_args_ansindex1234;  slog::Index** tickindex1235;  slog::Index** tick_ansindex1236;  slog::Index** eval_ansindex1237;  slog::Index** eval_args_ansindex1238;  slog::Index** tick_ansindex1239;  slog::Index** evalindex1240;  slog::Index** closureindex1241;  slog::Index** lambdaindex1242;  slog::Index** evalindex1243;  slog::Index** eval_ansindex1244;  slog::Index** tickdelta1245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1247({0, 1});
      slog::Relation* readrel1248 = db->getRelation("eval_ans");
      head_index[0] = readrel1248->getIndex(ord1247, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1249({1, 2, 0});
      slog::Relation* readrel1250 = db->getRelation("eval");
      evalindex1223 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("eval");
      evalindex1224 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 2, 0});
      slog::Relation* readrel1254 = db->getRelation("eval_args");
      eval_argsindex1225 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("tick");
      tickindex1226 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({2, 3, 0, 1});
      slog::Relation* readrel1258 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1227 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({0, 2, 1});
      slog::Relation* readrel1260 = db->getRelation("eval");
      evalindex1228 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 2, 0});
      slog::Relation* readrel1262 = db->getRelation("eval_args");
      eval_argsindex1229 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 2, 0});
      slog::Relation* readrel1264 = db->getRelation("tick");
      tickindex1230 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 2, 0});
      slog::Relation* readrel1266 = db->getRelation("eval");
      evalindex1231 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({0, 1});
      slog::Relation* readrel1268 = db->getRelation("eval_ans");
      eval_ansindex1232 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({1, 2, 0});
      slog::Relation* readrel1270 = db->getRelation("eval_args");
      eval_argsindex1233 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({0, 1});
      slog::Relation* readrel1272 = db->getRelation("eval_args_ans");
      eval_args_ansindex1234 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({1, 2, 0});
      slog::Relation* readrel1274 = db->getRelation("tick");
      tickindex1235 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({1, 2, 0});
      slog::Relation* readrel1276 = db->getRelation("tick");
      tickdelta1245 = readrel1276->getIndex(ord1275, true);
      std::vector<u16> ord1277({0, 1});
      slog::Relation* readrel1278 = db->getRelation("tick_ans");
      tick_ansindex1236 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({0, 1});
      slog::Relation* readrel1280 = db->getRelation("eval_ans");
      eval_ansindex1237 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({0, 1});
      slog::Relation* readrel1282 = db->getRelation("eval_args_ans");
      eval_args_ansindex1238 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({0, 1});
      slog::Relation* readrel1284 = db->getRelation("tick_ans");
      tick_ansindex1239 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({2, 0, 1});
      slog::Relation* readrel1286 = db->getRelation("eval");
      evalindex1240 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({0, 1, 2});
      slog::Relation* readrel1288 = db->getRelation("closure");
      closureindex1241 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({0, 1, 2});
      slog::Relation* readrel1290 = db->getRelation("lambda");
      lambdaindex1242 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({1, 2, 0});
      slog::Relation* readrel1292 = db->getRelation("eval");
      evalindex1243 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({0, 1});
      slog::Relation* readrel1294 = db->getRelation("eval_ans");
      eval_ansindex1244 = readrel1294->getIndex(ord1293, false);
  
    }
    ReadTask1246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c132 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1223, std::array<u64,3>{v_c132, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1224, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1225, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1226, std::array<u64,3>{v_c132, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1227, std::array<u64,4>{v_c35, v_c36, 0, 0}, [&](const std::array<u64,4>& m1295) {
          u64 v_c131 = m1295[2]; u64 v_c1 = m1295[3];
          slog::join_probe<3,3>(evalindex1228, std::array<u64,3>{v_c131, v_c1, v_c132}, [&](const std::array<u64,3>& m1296) {
            if (!slog::exists_probe<3,2>(eval_argsindex1229, std::array<u64,3>{v_c36, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(tickindex1230, std::array<u64,3>{v_c132, v_c1, 0})) return;
            slog::join_probe<3,2>(evalindex1231, std::array<u64,3>{v_c35, v_c1, 0}, [&](const std::array<u64,3>& m1297) {
              u64 v_c133 = m1297[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1232, std::array<u64,2>{v_c133, 0})) return;
              slog::join_probe<3,2>(eval_argsindex1233, std::array<u64,3>{v_c36, v_c1, 0}, [&](const std::array<u64,3>& m1298) {
                u64 v_c134 = m1298[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1234, std::array<u64,2>{v_c134, 0})) return;
                slog::join_probe_old<3,2>(tickindex1235, tickdelta1245, std::array<u64,3>{v_c132, v_c1, 0}, [&](const std::array<u64,3>& m1299) {
                  u64 v_c135 = m1299[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1236, std::array<u64,2>{v_c135, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1237, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m1300) {
                    u64 v_c136 = m1300[1];
                    slog::join_probe<2,1>(eval_args_ansindex1238, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m1301) {
                      u64 v_c42 = m1301[1];
                      slog::join_probe<2,1>(tick_ansindex1239, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m1302) {
                        u64 v_c33 = m1302[1];
                        if (!slog::exists_probe<3,1>(evalindex1240, std::array<u64,3>{v_c33, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex1241, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m1303) {
                          u64 v_c137 = m1303[1]; u64 v_c45 = m1303[2];
                          slog::join_probe<3,1>(lambdaindex1242, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m1304) {
                            u64 v_c48 = m1304[1]; u64 v_c2 = m1304[2];
                            slog::join_probe<3,2>(evalindex1243, std::array<u64,3>{v_c2, v_c33, 0}, [&](const std::array<u64,3>& m1305) {
                              u64 v_c138 = m1305[2];
                              slog::join_probe<2,1>(eval_ansindex1244, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m1306) {
                                u64 v_c9 = m1306[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c9}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo66CB469 __t5qKD331 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5RED468 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5qV2470 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4yFo471 __t5qKD331 _00024seq2) (exists _enum (1 0) 1 __tconst2WdB587) (join delta (1 2 0) 2 __tconst2sal328 _00024seq2 __t8DFh329) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join symval (0 1) 1 __t5qKD331 s) (letp _00024sql2Y3P463 (aslst _00024seq2)) (let chk0kku889 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk0kku889) (letp chk7RRQ890 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (eq __t5qKD331 chk7RRQ890) (letp chk44Ek891 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk44Ek891)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask1316 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1307;  slog::Index** $seq_atrindex1308;  slog::Index** $seq_atrindex1309;  slog::Index** _enumindex1310;  slog::Index** deltaindex1311;  slog::Index** _enumindex1312;  slog::Index** symvalindex1313;  slog::Index** $seq_atrdelta1314;  slog::Index** $seq_atrdelta1315;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1317({1, 0, 2});
      slog::Relation* readrel1318 = db->getRelation("$seq_at");
      driver_index = readrel1318->getIndex(ord1317, true);
      std::vector<u16> ord1319({1, 0, 2});
      slog::Relation* readrel1320 = db->getRelation("$seq_at");
      $seq_atindex1307 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 0, 2});
      slog::Relation* readrel1322 = db->getRelation("$seq_atr");
      $seq_atrindex1308 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({1, 0, 2});
      slog::Relation* readrel1324 = db->getRelation("$seq_atr");
      $seq_atrdelta1314 = readrel1324->getIndex(ord1323, true);
      std::vector<u16> ord1325({1, 0, 2});
      slog::Relation* readrel1326 = db->getRelation("$seq_atr");
      $seq_atrindex1309 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({1, 0, 2});
      slog::Relation* readrel1328 = db->getRelation("$seq_atr");
      $seq_atrdelta1315 = readrel1328->getIndex(ord1327, true);
      std::vector<u16> ord1329({1, 0});
      slog::Relation* readrel1330 = db->getRelation("_enum");
      _enumindex1310 = readrel1330->getIndex(ord1329, false);
      std::vector<u16> ord1331({1, 2, 0});
      slog::Relation* readrel1332 = db->getRelation("delta");
      deltaindex1311 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({1, 0});
      slog::Relation* readrel1334 = db->getRelation("_enum");
      _enumindex1312 = readrel1334->getIndex(ord1333, false);
      std::vector<u16> ord1335({0, 1});
      slog::Relation* readrel1336 = db->getRelation("symval");
      symvalindex1313 = readrel1336->getIndex(ord1335, false);
  
    }
    ReadTask1316(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c189 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c190 = v_const06abaa100ecef791ce028c56;
      u64 v_c191 = v_constd4735e3a265e16eee03f5971;
      u64 v_c192 = v_const5feceb66ffc86f38d952786c;
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
      u64 v_c195 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c196 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c195, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1337) {
        u64 v_c198 = m1337[1];
        u64 v_c112 = m1337[2];
        if (buckethash(v_c198) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1307, std::array<u64,3>{v_c194, v_c198, v_c112}, [&](const std::array<u64,3>& m1338) {
          slog::join_probe_old<3,3>($seq_atrindex1308, $seq_atrdelta1314, std::array<u64,3>{v_c196, v_c198, v_c112}, [&](const std::array<u64,3>& m1339) {
            slog::join_probe_old<3,3>($seq_atrindex1309, $seq_atrdelta1315, std::array<u64,3>{v_c197, v_c198, v_c112}, [&](const std::array<u64,3>& m1340) {
              if (!slog::exists_probe<2,1>(_enumindex1310, std::array<u64,2>{v_c189, 0})) return;
              slog::join_probe<3,2>(deltaindex1311, std::array<u64,3>{v_c190, v_c112, 0}, [&](const std::array<u64,3>& m1341) {
                u64 v_c199 = m1341[2];
                slog::join_probe<2,1>(_enumindex1312, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1342) {
                  u64 v_c200 = m1342[1];
                  slog::join_probe<2,1>(symvalindex1313, std::array<u64,2>{v_c198, 0}, [&](const std::array<u64,2>& m1343) {
                    u64 v_c201 = m1343[1];
                    bool ok1344 = true;
                    u64 v_c202 = _prim_aslst(db, v_c112, &ok1344);
                    if (!ok1344) return;
                    u64 v_c203 = _prim_llen(db, v_c202);
                    if (v_c203 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c191 != v_c203) return;
                    bool ok1345 = true;
                    u64 v_c204 = _prim_lref(db, v_c202, v_c192, &ok1345);
                    if (!ok1345) return;
                    if (v_c198 != v_c204) return;
                    bool ok1346 = true;
                    u64 v_c205 = _prim_lref(db, v_c202, v_c193, &ok1346);
                    if (!ok1346) return;
                    if (v_c198 != v_c205) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c199});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c200}, std::array<u16,2>{1, 0});
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
        ReadTask1316* _cont = new ReadTask1316(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1316(db,b), false);
}

