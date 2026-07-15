
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4e5ef144c51cd25230c144c3;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const829935b42173b360da35f679;
extern u64 v_const879923da020d1533f4d8e921;
extern u64 v_const8c8656c5d114d7f8b2a412d2;
extern u64 v_const8ca5d81566f88badd698137a;
extern u64 v_constac3fe12f2763ff95bc66dbed;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdcc297bb3300d9549a9d611a;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_consteefaed435882b14b69e99d78;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_ce65829c6446beac6(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan lookup __t0d3433 x c) (body (exists ref (1 0) 1 x) (exists eval (2 0 1) 1 c) (join lookup_ans (0 1) 1 __t0d3433 __v0) (join ref (1 0) 1 x __t8l5731) (join eval (1 2 0) 2 __t8l5731 c __t8n0332)) (head (emit eval_ans (0 1) __t8n0332 __v0)) interp.slog:30 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex0;  slog::Index** evalindex1;  slog::Index** lookup_ansindex2;  slog::Index** refindex3;  slog::Index** evalindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("eval_ans");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("ref");
      refindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({2, 0, 1});
      slog::Relation* readrel11 = db->getRelation("eval");
      evalindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("lookup_ans");
      lookup_ansindex2 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("ref");
      refindex3 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("eval");
      evalindex4 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(refindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(lookup_ansindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c3 = m18[1];
          slog::join_probe<2,1>(refindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c4 = m19[1];
            slog::join_probe<3,2>(evalindex4, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m20) {
              u64 v_c5 = m20[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c3}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre (let __tconst63FS700 constb9e118781cea1f9fa01462e0)) (scan select_branch __t7eum214 __t9W2N213 e2 e3) (body (join _enum (1 0) 1 __tconst63FS700 __t2bEf212) (join boolval (0 1) 2 __t9W2N213 __t2bEf212)) (head (emit select_branch_ans (0 1) __t7eum214 e3)) interp.slog:84 #f)
  class ReadTask23 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex21;  slog::Index** boolvalindex22;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("select_branch_ans");
      head_index[0] = readrel25->getIndex(ord24, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("_enum");
      _enumindex21 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("boolval");
      boolvalindex22 = readrel29->getIndex(ord28, false);
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        slog::join_probe<2,1>(_enumindex21, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m30) {
          u64 v_c11 = m30[1];
          slog::join_probe<2,2>(boolvalindex22, std::array<u64,2>{v_c8, v_c11}, [&](const std::array<u64,2>& m31) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c10}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:84", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), false);
  // (crule (pre (let __tconst4znW669 constcd2a69ce5ca278db1d6da969) (let _00024sqc3H5i520 constd4735e3a265e16eee03f5971) (let _00024sqc4tob521 const5feceb66ffc86f38d952786c) (let _00024sqc5Dhg522 const6b86b273ff34fce19d6b804e) (let _00024sqo4wSo523 const5feceb66ffc86f38d952786c) (let _00024sqo3X5o524 const6b86b273ff34fce19d6b804e) (let _00024sqo10Lc525 const6b86b273ff34fce19d6b804e) (let _00024sqo1tMi526 const5feceb66ffc86f38d952786c) (let __trid6dum670 consteefaed435882b14b69e99d78) (let __trel5mCG671 constdede4476644eb06b5a48b866) (let __tcol9ZQn672 const6b86b273ff34fce19d6b804e)) (scan delta __t2MSw39 op _00024seq2) (body (letp _00024sql8wbR518 (aslst _00024seq2)) (letp __t5cN641 (lref _00024sql8wbR518 _00024sqc4tob521)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4wSo523 __t5cN641 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3X5o524 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo10Lc525 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1tMi526 __t5cN641 _00024seq2) (join _enum (0 1) 2 __t5cN641 __tconst4znW669) (join arithmetic_op (0) 1 op) (let chk7ROm898 (llen _00024sql8wbR518)) (eq _00024sqc3H5i520 chk7ROm898) (letp chk0qi9899 (lref _00024sql8wbR518 _00024sqc5Dhg522)) (eq __t5cN641 chk0qi9899)) (head (tycheck __t5cN641 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid6dum670 __trel5mCG671 __tcol9ZQn672 (1 2 3 4 0)) (emit delta_ans (0 1) __t2MSw39 __t5cN641)) interp.slog:111 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex32;  slog::Index** $seq_atindex33;  slog::Index** $seq_atrindex34;  slog::Index** $seq_atrindex35;  slog::Index** _enumindex36;  slog::Index** arithmetic_opindex37;  slog::Index** $seq_atdelta38;  slog::Index** $seq_atdelta39;  slog::Index** $seq_atrdelta40;  slog::Index** $seq_atrdelta41;
    u32 sid44;  u32 sid42;  u32 sid43;  u32 sid45;  u32 sid46;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("delta_ans");
      head_index[1] = readrel49->getIndex(ord48, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord50({1, 0, 2});
      slog::Relation* readrel51 = db->getRelation("$seq_at");
      $seq_atindex32 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 0, 2});
      slog::Relation* readrel53 = db->getRelation("$seq_at");
      $seq_atdelta38 = readrel53->getIndex(ord52, true);
      std::vector<u16> ord54({1, 0, 2});
      slog::Relation* readrel55 = db->getRelation("$seq_at");
      $seq_atindex33 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 0, 2});
      slog::Relation* readrel57 = db->getRelation("$seq_at");
      $seq_atdelta39 = readrel57->getIndex(ord56, true);
      std::vector<u16> ord58({1, 0, 2});
      slog::Relation* readrel59 = db->getRelation("$seq_atr");
      $seq_atrindex34 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0, 2});
      slog::Relation* readrel61 = db->getRelation("$seq_atr");
      $seq_atrdelta40 = readrel61->getIndex(ord60, true);
      std::vector<u16> ord62({1, 0, 2});
      slog::Relation* readrel63 = db->getRelation("$seq_atr");
      $seq_atrindex35 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 0, 2});
      slog::Relation* readrel65 = db->getRelation("$seq_atr");
      $seq_atrdelta41 = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("_enum");
      _enumindex36 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({0});
      slog::Relation* readrel69 = db->getRelation("arithmetic_op");
      arithmetic_opindex37 = readrel69->getIndex(ord68, false);
      sid44 = db->getRelation("_enum")->getStructId();
      sid42 = db->getRelation("boolval")->getStructId();
      sid43 = db->getRelation("closure")->getStructId();
      sid45 = db->getRelation("prim")->getStructId();
      sid46 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c13 = v_constd4735e3a265e16eee03f5971;
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c16 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_consteefaed435882b14b69e99d78;
      u64 v_c21 = v_constdede4476644eb06b5a48b866;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        bool ok70 = true;
        u64 v_c26 = _prim_aslst(db, v_c25, &ok70);
        if (!ok70) return;
        bool ok71 = true;
        u64 v_c27 = _prim_lref(db, v_c26, v_c14, &ok71);
        if (!ok71) return;
        slog::join_probe_old<3,3>($seq_atindex32, $seq_atdelta38, std::array<u64,3>{v_c16, v_c27, v_c25}, [&](const std::array<u64,3>& m72) {
          slog::join_probe_old<3,3>($seq_atindex33, $seq_atdelta39, std::array<u64,3>{v_c17, v_c27, v_c25}, [&](const std::array<u64,3>& m73) {
            slog::join_probe_old<3,3>($seq_atrindex34, $seq_atrdelta40, std::array<u64,3>{v_c18, v_c27, v_c25}, [&](const std::array<u64,3>& m74) {
              slog::join_probe_old<3,3>($seq_atrindex35, $seq_atrdelta41, std::array<u64,3>{v_c19, v_c27, v_c25}, [&](const std::array<u64,3>& m75) {
                slog::join_probe<2,2>(_enumindex36, std::array<u64,2>{v_c27, v_c12}, [&](const std::array<u64,2>& m76) {
                  slog::join_probe<1,1>(arithmetic_opindex37, std::array<u64,1>{v_c24}, [&](const std::array<u64,1>& m77) {
                    u64 v_c28 = _prim_llen(db, v_c26);
                    if (v_c28 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c13 != v_c28) return;
                    bool ok78 = true;
                    u64 v_c29 = _prim_lref(db, v_c26, v_c15, &ok78);
                    if (!ok78) return;
                    if (v_c27 != v_c29) return;
                    ++_fires;
                    if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid42 || decode_struct_id(v_c27) == sid43 || decode_struct_id(v_c27) == sid44 || decode_struct_id(v_c27) == sid45 || decode_struct_id(v_c27) == sid46))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c20, v_c21, v_c22, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst16Fs254 const879923da020d1533f4d8e921)) (scan temp8QhX964 __t36Tx287 __t3DyN290 __t3RWJ237 __t4Zol274 __t5YMF258 __t8kBG271 __t9Hvd221) (body (exists lambda (1 2 0) 2 __t3DyN290 __t36Tx287) (exists ref (1 0) 1 __tconst2XD5276) (exists ref (1 0) 1 __tconst7wlx292) (exists ref (1 0) 1 __tconst4aTz260) (exists ref (1 0) 1 __tconst6YSZ252) (exists ref (1 0) 1 __tconst39ZW253) (exists ref (1 0) 1 __tconst16Fs254) (exists lambda (1 2 0) 1 __t5YMF258) (join lambda (1 2 0) 2 __t4Zol274 __t8kBG271 __t7Cof275) (join lambda (1 2 0) 2 __t3DyN290 __t36Tx287 __t4sa5291) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst7wlx292 __t1iN7225) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join ref (1 0) 1 __tconst6YSZ252 __t7SX3246) (exists if (3 0 1 2) 1 __t7SX3246) (join ref (1 0) 1 __tconst39ZW253 __t1waL248) (join if (2 3 1 0) 2 __t1waL248 __t7SX3246 __t54jO250 __t4Qs4251) (join ref (0 1) 2 __t54jO250 __tconst16Fs254) (join lambda (1 2 0) 2 __t5YMF258 __t4Qs4251 __t34RH259) (let __t03VS238 (lpush __t3RWJ237 __t1iN7225))) (head (emit-temp temp17TG965 __t03VS238 __t34RH259 __t4sa5291 __t7Cof275 __t9Hvd221)) analysis-demo.slog:21 #f)
  class ReadTask98 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex79;  slog::Index** refindex80;  slog::Index** refindex81;  slog::Index** refindex82;  slog::Index** refindex83;  slog::Index** refindex84;  slog::Index** refindex85;  slog::Index** lambdaindex86;  slog::Index** lambdaindex87;  slog::Index** lambdaindex88;  slog::Index** refindex89;  slog::Index** refindex90;  slog::Index** refindex91;  slog::Index** refindex92;  slog::Index** ifindex93;  slog::Index** refindex94;  slog::Index** ifindex95;  slog::Index** refindex96;  slog::Index** lambdaindex97;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp17TG965");
      outer_rel = db->getRelation("temp8QhX964");
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("lambda");
      lambdaindex79 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("ref");
      refindex80 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0});
      slog::Relation* readrel104 = db->getRelation("ref");
      refindex81 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("ref");
      refindex82 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("ref");
      refindex83 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("ref");
      refindex84 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("ref");
      refindex85 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("lambda");
      lambdaindex86 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("lambda");
      lambdaindex87 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 0});
      slog::Relation* readrel118 = db->getRelation("lambda");
      lambdaindex88 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 0});
      slog::Relation* readrel120 = db->getRelation("ref");
      refindex89 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 0});
      slog::Relation* readrel122 = db->getRelation("ref");
      refindex90 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 0});
      slog::Relation* readrel124 = db->getRelation("ref");
      refindex91 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 0});
      slog::Relation* readrel126 = db->getRelation("ref");
      refindex92 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({3, 0, 1, 2});
      slog::Relation* readrel128 = db->getRelation("if");
      ifindex93 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("ref");
      refindex94 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({2, 3, 1, 0});
      slog::Relation* readrel132 = db->getRelation("if");
      ifindex95 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("ref");
      refindex96 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 0});
      slog::Relation* readrel136 = db->getRelation("lambda");
      lambdaindex97 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask98(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c31 = v_constf77801bebb40767a1b303d97;
      u64 v_c32 = v_const829935b42173b360da35f679;
      u64 v_c33 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c34 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c35 = v_const8ca5d81566f88badd698137a;
      u64 v_c36 = v_const879923da020d1533f4d8e921;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _t[3];
        u64 v_c41 = _t[4];
        u64 v_c42 = _t[5];
        u64 v_c43 = _t[6];
        if (!slog::exists_probe<3,2>(lambdaindex79, std::array<u64,3>{v_c38, v_c37, 0})) return;
        if (!slog::exists_probe<2,1>(refindex80, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(refindex81, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(refindex82, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(refindex83, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex84, std::array<u64,2>{v_c35, 0})) return;
        if (!slog::exists_probe<2,1>(refindex85, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex86, std::array<u64,3>{v_c41, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex87, std::array<u64,3>{v_c40, v_c42, 0}, [&](const std::array<u64,3>& m137) {
          u64 v_c44 = m137[2];
          slog::join_probe<3,2>(lambdaindex88, std::array<u64,3>{v_c38, v_c37, 0}, [&](const std::array<u64,3>& m138) {
            u64 v_c45 = m138[2];
            slog::join_probe<2,1>(refindex89, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m139) {
              u64 v_c46 = m139[1];
              slog::join_probe<2,1>(refindex90, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m140) {
                u64 v_c47 = m140[1];
                slog::join_probe<2,1>(refindex91, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m141) {
                  u64 v_c48 = m141[1];
                  slog::join_probe<2,1>(refindex92, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m142) {
                    u64 v_c49 = m142[1];
                    if (!slog::exists_probe<4,1>(ifindex93, std::array<u64,4>{v_c49, 0, 0, 0})) return;
                    slog::join_probe<2,1>(refindex94, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m143) {
                      u64 v_c50 = m143[1];
                      slog::join_probe<4,2>(ifindex95, std::array<u64,4>{v_c50, v_c49, 0, 0}, [&](const std::array<u64,4>& m144) {
                        u64 v_c51 = m144[2]; u64 v_c52 = m144[3];
                        slog::join_probe<2,2>(refindex96, std::array<u64,2>{v_c51, v_c36}, [&](const std::array<u64,2>& m145) {
                          slog::join_probe<3,2>(lambdaindex97, std::array<u64,3>{v_c41, v_c52, 0}, [&](const std::array<u64,3>& m146) {
                            u64 v_c53 = m146[2];
                            u64 v_c54 = _prim_lpush(db, v_c39, v_c47);
                            if (v_c54 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                            ++_fires;
                            slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c54, v_c53, v_c45, v_c44, v_c43});
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
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp8QhX964", _fires);
  
      if (!_done)
      {
        ReadTask98* _cont = new ReadTask98(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask98(db,b), false);
  // (crule (pre (let __trid6nWa620 const119eb3a23d030ee0dfe9f807) (let __trel6i8U621 constac3fe12f2763ff95bc66dbed) (let __tcol2wIl622 const6b86b273ff34fce19d6b804e) (let __trel5eQQ623 const4e5ef144c51cd25230c144c3) (let __tcol8hcx624 const5feceb66ffc86f38d952786c) (let __trel1tbi625 const4e5ef144c51cd25230c144c3) (let __tcol8IVc626 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck c (accept seq) __trid6nWa620 __trel6i8U621 __tcol2wIl622 (1 2 3 4 0)) (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid6nWa620 __trel5eQQ623 __tcol8hcx624 (1 2 3 4 0)) (tycheck es (accept seq) __trid6nWa620 __trel1tbi625 __tcol8IVc626 (1 2 3 4 0)) (emit-temp temp1iok1031 c ef es) (mkstruct app (1 2 0) __t9umL4 ef es)) interp.slog:42 #f)
  class ReadTask156 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid147;  u32 sid148;  u32 sid149;  u32 sid150;  u32 sid151;  u32 sid152;  u32 sid153;  u32 sid154;  u32 sid155;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("temp1iok1031");
      head_rel[4] = db->getRelation("app");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      sid147 = db->getRelation("app")->getStructId();
      sid148 = db->getRelation("boolean")->getStructId();
      sid149 = db->getRelation("if")->getStructId();
      sid150 = db->getRelation("lambda")->getStructId();
      sid151 = db->getRelation("let")->getStructId();
      sid152 = db->getRelation("letrec")->getStructId();
      sid153 = db->getRelation("num")->getStructId();
      sid154 = db->getRelation("ref")->getStructId();
      sid155 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask156(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c56 = v_constac3fe12f2763ff95bc66dbed;
      u64 v_c57 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c58 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c62 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c63 = _t[2];
        u64 v_c64 = _t[3];
        ++_fires;
        if (!(is_seq(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c55, v_c56, v_c57, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c63) && (decode_struct_id(v_c63) == sid147 || decode_struct_id(v_c63) == sid148 || decode_struct_id(v_c63) == sid149 || decode_struct_id(v_c63) == sid150 || decode_struct_id(v_c63) == sid151 || decode_struct_id(v_c63) == sid152 || decode_struct_id(v_c63) == sid153 || decode_struct_id(v_c63) == sid154 || decode_struct_id(v_c63) == sid155))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c58, v_c59, v_c63}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c64)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c55, v_c60, v_c61, v_c64}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<3>(head_rel[3], newbatch[3], std::array<u64,3>{v_c2, v_c63, v_c64});
        slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c63, v_c64}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask156* _cont = new ReadTask156(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask156(db,b), false);
  // (crule (pre (let __tconst2fdM633 constcd2a69ce5ca278db1d6da969) (let _00024sqc7LFn532 constd4735e3a265e16eee03f5971) (let _00024sqc3SHd533 const5feceb66ffc86f38d952786c) (let _00024sqc4CLM534 const6b86b273ff34fce19d6b804e) (let _00024sqo90j9535 const5feceb66ffc86f38d952786c) (let _00024sqo88rK536 const6b86b273ff34fce19d6b804e) (let _00024sqo1A9y537 const6b86b273ff34fce19d6b804e) (let _00024sqo2hWF538 const5feceb66ffc86f38d952786c)) (scan delta __t1IV0337 op _00024seq2) (body (letp _00024sql96G9530 (aslst _00024seq2)) (letp __t26Zq339 (lref _00024sql96G9530 _00024sqc3SHd533)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo90j9535 __t26Zq339 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo88rK536 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1A9y537 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2hWF538 __t26Zq339 _00024seq2) (join _enum (0 1) 2 __t26Zq339 __tconst2fdM633) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (let chk6zc9946 (llen _00024sql96G9530)) (eq _00024sqc7LFn532 chk6zc9946) (letp chk7KrQ947 (lref _00024sql96G9530 _00024sqc4CLM534)) (eq __t26Zq339 chk7KrQ947)) (head (emit-temp temp5ZiW945 __t1IV0337 b) (mkstruct boolval (1 0) __t4qAo336 b)) interp.slog:112 #f)
  class ReadTask168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex157;  slog::Index** $seq_atindex158;  slog::Index** $seq_atrindex159;  slog::Index** $seq_atrindex160;  slog::Index** _enumindex161;  slog::Index** comparison_opindex162;  slog::Index** any_boolindex163;  slog::Index** $seq_atdelta164;  slog::Index** $seq_atdelta165;  slog::Index** $seq_atrdelta166;  slog::Index** $seq_atrdelta167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5ZiW945");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord169({1, 0, 2});
      slog::Relation* readrel170 = db->getRelation("$seq_at");
      $seq_atindex157 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0, 2});
      slog::Relation* readrel172 = db->getRelation("$seq_at");
      $seq_atdelta164 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({1, 0, 2});
      slog::Relation* readrel174 = db->getRelation("$seq_at");
      $seq_atindex158 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0, 2});
      slog::Relation* readrel176 = db->getRelation("$seq_at");
      $seq_atdelta165 = readrel176->getIndex(ord175, true);
      std::vector<u16> ord177({1, 0, 2});
      slog::Relation* readrel178 = db->getRelation("$seq_atr");
      $seq_atrindex159 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0, 2});
      slog::Relation* readrel180 = db->getRelation("$seq_atr");
      $seq_atrdelta166 = readrel180->getIndex(ord179, true);
      std::vector<u16> ord181({1, 0, 2});
      slog::Relation* readrel182 = db->getRelation("$seq_atr");
      $seq_atrindex160 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 0, 2});
      slog::Relation* readrel184 = db->getRelation("$seq_atr");
      $seq_atrdelta167 = readrel184->getIndex(ord183, true);
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("_enum");
      _enumindex161 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0});
      slog::Relation* readrel188 = db->getRelation("comparison_op");
      comparison_opindex162 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({0});
      slog::Relation* readrel190 = db->getRelation("any_bool");
      any_boolindex163 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c66 = v_constd4735e3a265e16eee03f5971;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
      u64 v_c68 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        bool ok191 = true;
        u64 v_c74 = _prim_aslst(db, v_c25, &ok191);
        if (!ok191) return;
        bool ok192 = true;
        u64 v_c75 = _prim_lref(db, v_c74, v_c67, &ok192);
        if (!ok192) return;
        slog::join_probe_old<3,3>($seq_atindex157, $seq_atdelta164, std::array<u64,3>{v_c69, v_c75, v_c25}, [&](const std::array<u64,3>& m193) {
          slog::join_probe_old<3,3>($seq_atindex158, $seq_atdelta165, std::array<u64,3>{v_c70, v_c75, v_c25}, [&](const std::array<u64,3>& m194) {
            slog::join_probe_old<3,3>($seq_atrindex159, $seq_atrdelta166, std::array<u64,3>{v_c71, v_c75, v_c25}, [&](const std::array<u64,3>& m195) {
              slog::join_probe_old<3,3>($seq_atrindex160, $seq_atrdelta167, std::array<u64,3>{v_c72, v_c75, v_c25}, [&](const std::array<u64,3>& m196) {
                slog::join_probe<2,2>(_enumindex161, std::array<u64,2>{v_c75, v_c65}, [&](const std::array<u64,2>& m197) {
                  slog::join_probe<1,1>(comparison_opindex162, std::array<u64,1>{v_c24}, [&](const std::array<u64,1>& m198) {
                    slog::join_all<1>(any_boolindex163, [&](const std::array<u64,1>& m199) {
                      u64 v_c76 = m199[0];
                      u64 v_c77 = _prim_llen(db, v_c74);
                      if (v_c77 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c66 != v_c77) return;
                      bool ok200 = true;
                      u64 v_c78 = _prim_lref(db, v_c74, v_c68, &ok200);
                      if (!ok200) return;
                      if (v_c75 != v_c78) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c73, v_c76});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c76}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask168* _cont = new ReadTask168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask168(db,b), false);
  // (crule (pre (let _00024sqc3H84394 const6b86b273ff34fce19d6b804e) (let _00024sqc8FJ0395 const5feceb66ffc86f38d952786c) (let _00024sqc8fGD396 const6b86b273ff34fce19d6b804e) (let _00024sqc1CIf397 const5feceb66ffc86f38d952786c)) (scan argument_list _00024seq0) (body (letp _00024sql11Zx392 (aslst _00024seq0)) (let _00024sqn3UO5393 (llen _00024sql11Zx392)) (cmp ge _00024sqn3UO5393 _00024sqc3H84394) (letp e (lref _00024sql11Zx392 _00024sqc8FJ0395)) (let _00024sqp32do398 (_0002d _00024sqn3UO5393 _00024sqc1CIf397)) (let es (lslice _00024sql11Zx392 _00024sqc8fGD396 _00024sqp32do398))) (head (emit argument_list (0) es)) freevars.slog:34 #f)
  class ReadTask201 : public slog::Task
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
      head_rel[0] = db->getRelation("argument_list");
      std::vector<u16> ord202({0});
      slog::Relation* readrel203 = db->getRelation("argument_list");
      head_index[0] = readrel203->getIndex(ord202, false);
      outer_rel = db->getRelation("argument_list");
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const5feceb66ffc86f38d952786c;
      u64 v_c81 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        bool ok204 = true;
        u64 v_c84 = _prim_aslst(db, v_c83, &ok204);
        if (!ok204) return;
        u64 v_c85 = _prim_llen(db, v_c84);
        if (v_c85 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        u64 v_c86 = _prim_ge(db, v_c85, v_c79);
        if (v_c86 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        if (!v_c86) return;
        bool ok206 = true;
        u64 v_c87 = _prim_lref(db, v_c84, v_c80, &ok206);
        if (!ok206) return;
        u64 v_c88 = _prim__0002d(db, v_c85, v_c82);
        if (v_c88 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        u64 v_c64 = _prim_lslice(db, v_c84, v_c81, v_c88);
        if (v_c64 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:34", "delta:argument_list", _fires);
  
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
  // (crule (pre (let _00024sqc67YX483 const6b86b273ff34fce19d6b804e) (let _00024sqc6yXy484 const5feceb66ffc86f38d952786c) (let _00024sqc5zPS485 const6b86b273ff34fce19d6b804e) (let _00024sqc5ri6486 const5feceb66ffc86f38d952786c) (let _00024sqo8WWm491 const5feceb66ffc86f38d952786c) (let __t8LOa148 (lempty))) (scan argument_list _00024seq0) (body (letp _00024sql8fmo481 (aslst _00024seq0)) (letp e (lref _00024sql8fmo481 _00024sqc6yXy484)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8WWm491 e _00024seq0) (join freevar (1 0) 1 e x) (let _00024sqn5D5C482 (llen _00024sql8fmo481)) (cmp ge _00024sqn5D5C482 _00024sqc67YX483) (let _00024sqp6Eh2487 (_0002d _00024sqn5D5C482 _00024sqc5ri6486)) (let es (lslice _00024sql8fmo481 _00024sqc5zPS485 _00024sqp6Eh2487))) (head (emit-temp temp86Ay863 __t8LOa148 e es x)) freevars.slog:35 #f)
  class ReadTask210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex207;  slog::Index** freevarindex208;  slog::Index** $seq_atdelta209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp86Ay863");
      outer_rel = db->getRelation("argument_list");
      std::vector<u16> ord211({1, 0, 2});
      slog::Relation* readrel212 = db->getRelation("$seq_at");
      $seq_atindex207 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 0, 2});
      slog::Relation* readrel214 = db->getRelation("$seq_at");
      $seq_atdelta209 = readrel214->getIndex(ord213, true);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("freevar");
      freevarindex208 = readrel216->getIndex(ord215, false);
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = _prim_lempty(db);
      if (v_c94 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        bool ok217 = true;
        u64 v_c95 = _prim_aslst(db, v_c83, &ok217);
        if (!ok217) return;
        bool ok218 = true;
        u64 v_c87 = _prim_lref(db, v_c95, v_c90, &ok218);
        if (!ok218) return;
        slog::join_probe_old<3,3>($seq_atindex207, $seq_atdelta209, std::array<u64,3>{v_c93, v_c87, v_c83}, [&](const std::array<u64,3>& m219) {
          slog::join_probe<2,1>(freevarindex208, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m220) {
            u64 v_c1 = m220[1];
            u64 v_c96 = _prim_llen(db, v_c95);
            if (v_c96 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c97 = _prim_ge(db, v_c96, v_c89);
            if (v_c97 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c97) return;
            u64 v_c98 = _prim__0002d(db, v_c96, v_c92);
            if (v_c98 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c64 = _prim_lslice(db, v_c95, v_c91, v_c98);
            if (v_c64 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c94, v_c87, v_c64, v_c1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:argument_list", _fires);
  
      if (!_done)
      {
        ReadTask210* _cont = new ReadTask210(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask210(db,b), false);
  // (crule (pre) (scan lambda __t3miO28 xs eb) (body (exists closure (1 2 0) 1 __t3miO28) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 1 y cb vy) (join closure (1 2 0) 2 __t3miO28 cb __t6CK626) (join eval_ans (1 0) 1 __t6CK626 __t84Ji24) (join eval (0 2 1) 1 __t84Ji24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join eval_args (1 2 0) 2 es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join tick_ans (0 1) 1 __t0NvE30 l)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask242 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex222;  slog::Index** freevarindex223;  slog::Index** bindingindex224;  slog::Index** closureindex225;  slog::Index** eval_ansindex226;  slog::Index** evalindex227;  slog::Index** appindex228;  slog::Index** eval_argsindex229;  slog::Index** tickindex230;  slog::Index** evalindex231;  slog::Index** tickindex232;  slog::Index** appindex233;  slog::Index** eval_argsindex234;  slog::Index** eval_args_ansindex235;  slog::Index** tickindex236;  slog::Index** tick_ansindex237;  slog::Index** eval_args_ansindex238;  slog::Index** tick_ansindex239;  slog::Index** appdelta240;  slog::Index** tickdelta241;
  
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
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord247({1, 2, 0});
      slog::Relation* readrel248 = db->getRelation("closure");
      closureindex222 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 0});
      slog::Relation* readrel250 = db->getRelation("freevar");
      freevarindex223 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1, 2});
      slog::Relation* readrel252 = db->getRelation("binding");
      bindingindex224 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 2, 0});
      slog::Relation* readrel254 = db->getRelation("closure");
      closureindex225 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 0});
      slog::Relation* readrel256 = db->getRelation("eval_ans");
      eval_ansindex226 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({0, 2, 1});
      slog::Relation* readrel258 = db->getRelation("eval");
      evalindex227 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("app");
      appindex228 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({2, 0, 1});
      slog::Relation* readrel262 = db->getRelation("eval_args");
      eval_argsindex229 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({2, 0, 1});
      slog::Relation* readrel264 = db->getRelation("tick");
      tickindex230 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({2, 0, 1});
      slog::Relation* readrel266 = db->getRelation("eval");
      evalindex231 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("tick");
      tickindex232 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1, 2});
      slog::Relation* readrel270 = db->getRelation("app");
      appindex233 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({0, 1, 2});
      slog::Relation* readrel272 = db->getRelation("app");
      appdelta240 = readrel272->getIndex(ord271, true);
      std::vector<u16> ord273({1, 2, 0});
      slog::Relation* readrel274 = db->getRelation("eval_args");
      eval_argsindex234 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("eval_args_ans");
      eval_args_ansindex235 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 0});
      slog::Relation* readrel278 = db->getRelation("tick");
      tickindex236 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 2, 0});
      slog::Relation* readrel280 = db->getRelation("tick");
      tickdelta241 = readrel280->getIndex(ord279, true);
      std::vector<u16> ord281({0, 1});
      slog::Relation* readrel282 = db->getRelation("tick_ans");
      tick_ansindex237 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("eval_args_ans");
      eval_args_ansindex238 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("tick_ans");
      tick_ansindex239 = readrel286->getIndex(ord285, false);
  
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
        u64 v_c99 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c101 = _t[2];
        if (!slog::exists_probe<3,1>(closureindex222, std::array<u64,3>{v_c99, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex223, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m287) {
          u64 v_c102 = m287[1];
          slog::join_probe<3,1>(bindingindex224, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m288) {
            u64 v_c103 = m288[1]; u64 v_c104 = m288[2];
            slog::join_probe<3,2>(closureindex225, std::array<u64,3>{v_c99, v_c103, 0}, [&](const std::array<u64,3>& m289) {
              u64 v_c105 = m289[2];
              slog::join_probe<2,1>(eval_ansindex226, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m290) {
                u64 v_c106 = m290[1];
                slog::join_probe<3,1>(evalindex227, std::array<u64,3>{v_c106, 0, 0}, [&](const std::array<u64,3>& m291) {
                  u64 v_c2 = m291[1]; u64 v_c63 = m291[2];
                  if (!slog::exists_probe<3,1>(appindex228, std::array<u64,3>{v_c63, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(eval_argsindex229, std::array<u64,3>{v_c2, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(tickindex230, std::array<u64,3>{v_c2, 0, 0})) return;
                  slog::join_probe<3,1>(evalindex231, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m292) {
                    u64 v_c107 = m292[1]; u64 v_c108 = m292[2];
                    if (!slog::exists_probe<3,2>(tickindex232, std::array<u64,3>{v_c108, v_c2, 0})) return;
                    slog::join_probe_old<3,2>(appindex233, appdelta240, std::array<u64,3>{v_c108, v_c63, 0}, [&](const std::array<u64,3>& m293) {
                      u64 v_c64 = m293[2];
                      slog::join_probe<3,2>(eval_argsindex234, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m294) {
                        u64 v_c109 = m294[2];
                        if (!slog::exists_probe<2,1>(eval_args_ansindex235, std::array<u64,2>{v_c109, 0})) return;
                        slog::join_probe_old<3,2>(tickindex236, tickdelta241, std::array<u64,3>{v_c108, v_c2, 0}, [&](const std::array<u64,3>& m295) {
                          u64 v_c110 = m295[2];
                          if (!slog::exists_probe<2,1>(tick_ansindex237, std::array<u64,2>{v_c110, 0})) return;
                          slog::join_probe<2,1>(eval_args_ansindex238, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m296) {
                            u64 v_c111 = m296[1];
                            slog::join_probe<2,1>(tick_ansindex239, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m297) {
                              u64 v_c112 = m297[1];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c102, v_c112, v_c104}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c102, v_c112, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
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
  // (crule (pre) (scan temp8YJO864 __t60vU149 es x) (body (let __t43VN150 (lcat __t60vU149 es))) (head (emit-temp temp7ASG865 __t43VN150 x)) freevars.slog:35 #f)
  class ReadTask298 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7ASG865");
      outer_rel = db->getRelation("temp8YJO864");
  
    }
    ReadTask298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c113 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c114 = _prim_lcat(db, v_c113, v_c64);
        if (v_c114 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c114, v_c1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp8YJO864", _fires);
  
      if (!_done)
      {
        ReadTask298* _cont = new ReadTask298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask298(db,b), false);
  // (crule (pre) (scan eval_ans __t550i320 __t2qAJ322) (body (join-old eval (0 2 1) 1 (0 2 1) __t550i320 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join-old eval_args_ans (0 1) 1 (0 1) __t8cVn323 vs) (join-old tick_ans (0 1) 1 (0 1) __t3nAR325 l) (join-old closure (0 1 2) 1 (0 1 2) __t2qAJ322 __t7ycN321 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask322 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex299;  slog::Index** appindex300;  slog::Index** eval_argsindex301;  slog::Index** tickindex302;  slog::Index** evalindex303;  slog::Index** tickindex304;  slog::Index** appindex305;  slog::Index** eval_argsindex306;  slog::Index** eval_args_ansindex307;  slog::Index** tickindex308;  slog::Index** tick_ansindex309;  slog::Index** eval_args_ansindex310;  slog::Index** tick_ansindex311;  slog::Index** closureindex312;  slog::Index** lambdaindex313;  slog::Index** evaldelta314;  slog::Index** appdelta315;  slog::Index** eval_argsdelta316;  slog::Index** tickdelta317;  slog::Index** eval_args_ansdelta318;  slog::Index** tick_ansdelta319;  slog::Index** closuredelta320;  slog::Index** lambdadelta321;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord323({0, 1, 2, 3});
      slog::Relation* readrel324 = db->getRelation("bind_params");
      head_index[0] = readrel324->getIndex(ord323, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord325({0, 1});
      slog::Relation* readrel326 = db->getRelation("call_event");
      head_index[1] = readrel326->getIndex(ord325, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord327({0, 2, 1});
      slog::Relation* readrel328 = db->getRelation("eval");
      evalindex299 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 2, 1});
      slog::Relation* readrel330 = db->getRelation("eval");
      evaldelta314 = readrel330->getIndex(ord329, true);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("app");
      appindex300 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({2, 0, 1});
      slog::Relation* readrel334 = db->getRelation("eval_args");
      eval_argsindex301 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({2, 0, 1});
      slog::Relation* readrel336 = db->getRelation("tick");
      tickindex302 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({2, 0, 1});
      slog::Relation* readrel338 = db->getRelation("eval");
      evalindex303 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 2, 0});
      slog::Relation* readrel340 = db->getRelation("tick");
      tickindex304 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({0, 1, 2});
      slog::Relation* readrel342 = db->getRelation("app");
      appindex305 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1, 2});
      slog::Relation* readrel344 = db->getRelation("app");
      appdelta315 = readrel344->getIndex(ord343, true);
      std::vector<u16> ord345({1, 2, 0});
      slog::Relation* readrel346 = db->getRelation("eval_args");
      eval_argsindex306 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 2, 0});
      slog::Relation* readrel348 = db->getRelation("eval_args");
      eval_argsdelta316 = readrel348->getIndex(ord347, true);
      std::vector<u16> ord349({0, 1});
      slog::Relation* readrel350 = db->getRelation("eval_args_ans");
      eval_args_ansindex307 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("tick");
      tickindex308 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("tick");
      tickdelta317 = readrel354->getIndex(ord353, true);
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("tick_ans");
      tick_ansindex309 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("eval_args_ans");
      eval_args_ansindex310 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({0, 1});
      slog::Relation* readrel360 = db->getRelation("eval_args_ans");
      eval_args_ansdelta318 = readrel360->getIndex(ord359, true);
      std::vector<u16> ord361({0, 1});
      slog::Relation* readrel362 = db->getRelation("tick_ans");
      tick_ansindex311 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("tick_ans");
      tick_ansdelta319 = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({0, 1, 2});
      slog::Relation* readrel366 = db->getRelation("closure");
      closureindex312 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 1, 2});
      slog::Relation* readrel368 = db->getRelation("closure");
      closuredelta320 = readrel368->getIndex(ord367, true);
      std::vector<u16> ord369({0, 1, 2});
      slog::Relation* readrel370 = db->getRelation("lambda");
      lambdaindex313 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1, 2});
      slog::Relation* readrel372 = db->getRelation("lambda");
      lambdadelta321 = readrel372->getIndex(ord371, true);
  
    }
    ReadTask322(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[0];
        u64 v_c116 = _t[1];
        slog::join_probe_old<3,1>(evalindex299, evaldelta314, std::array<u64,3>{v_c115, 0, 0}, [&](const std::array<u64,3>& m373) {
          u64 v_c2 = m373[1]; u64 v_c63 = m373[2];
          if (!slog::exists_probe<3,1>(appindex300, std::array<u64,3>{v_c63, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex301, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex302, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<3,1>(evalindex303, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m374) {
            u64 v_c117 = m374[1]; u64 v_c118 = m374[2];
            if (!slog::exists_probe<3,2>(tickindex304, std::array<u64,3>{v_c118, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex305, appdelta315, std::array<u64,3>{v_c118, v_c63, 0}, [&](const std::array<u64,3>& m375) {
              u64 v_c64 = m375[2];
              slog::join_probe_old<3,2>(eval_argsindex306, eval_argsdelta316, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m376) {
                u64 v_c119 = m376[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex307, std::array<u64,2>{v_c119, 0})) return;
                slog::join_probe_old<3,2>(tickindex308, tickdelta317, std::array<u64,3>{v_c118, v_c2, 0}, [&](const std::array<u64,3>& m377) {
                  u64 v_c120 = m377[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex309, std::array<u64,2>{v_c120, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex310, eval_args_ansdelta318, std::array<u64,2>{v_c119, 0}, [&](const std::array<u64,2>& m378) {
                    u64 v_c111 = m378[1];
                    slog::join_probe_old<2,1>(tick_ansindex311, tick_ansdelta319, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m379) {
                      u64 v_c112 = m379[1];
                      slog::join_probe_old<3,1>(closureindex312, closuredelta320, std::array<u64,3>{v_c116, 0, 0}, [&](const std::array<u64,3>& m380) {
                        u64 v_c121 = m380[1]; u64 v_c103 = m380[2];
                        slog::join_probe_old<3,1>(lambdaindex313, lambdadelta321, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m381) {
                          u64 v_c100 = m381[1]; u64 v_c101 = m381[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c100, v_c111, v_c112, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c112, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask322* _cont = new ReadTask322(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask322(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst1ae2105 constba2df4903a2c14e86dc3bcca) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst8Fnl80 const7297d2085ea0adffc396d546) (let __tconst8n1H73 const6b86b273ff34fce19d6b804e) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp2J14999 __t1hw196 __t5Wmv107 __t6Al3108 __t9Kbk85 __t9ZBY78) (body (exists num (1 0) 1 __tconst8n1H73) (exists ref (1 0) 1 __tconst8Fnl80) (exists ref (1 0) 1 __tconst2uSL111) (exists ref (1 0) 1 __tconst0xiC106) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join num (1 0) 1 __tconst8n1H73 __t7RPv74) (join ref (1 0) 1 __tconst8Fnl80 __t0mBu81) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join ref (1 0) 1 __tconst0xiC106 __t2Kfn98) (let __t8dvA109 (lpush __t6Al3108 __tconst1ae2105)) (let __t528g79 (lpush __t9ZBY78 __t7RPv74))) (head (emit-temp temp2du61000 __t1hw196 __t528g79 __t5Wmv107 __t8dvA109 __t9Kbk85) (mkstruct app (1 2 0) __t6UC699 __t2Kfn98 __t1hw196)) analysis-demo.slog:11 #f)
  class ReadTask391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex382;  slog::Index** refindex383;  slog::Index** refindex384;  slog::Index** refindex385;  slog::Index** numindex386;  slog::Index** numindex387;  slog::Index** refindex388;  slog::Index** refindex389;  slog::Index** refindex390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2du61000");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp2J14999");
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("num");
      numindex382 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("ref");
      refindex383 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("ref");
      refindex384 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 0});
      slog::Relation* readrel399 = db->getRelation("ref");
      refindex385 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 0});
      slog::Relation* readrel401 = db->getRelation("num");
      numindex386 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0});
      slog::Relation* readrel403 = db->getRelation("num");
      numindex387 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 0});
      slog::Relation* readrel405 = db->getRelation("ref");
      refindex388 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 0});
      slog::Relation* readrel407 = db->getRelation("ref");
      refindex389 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("ref");
      refindex390 = readrel409->getIndex(ord408, false);
  
    }
    ReadTask391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const0457bba0679825d285ef7fa5;
      u64 v_c123 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c124 = v_const30f8b180d63559f2512b744f;
      u64 v_c125 = v_const7297d2085ea0adffc396d546;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c128 = _t[0];
        u64 v_c129 = _t[1];
        u64 v_c130 = _t[2];
        u64 v_c131 = _t[3];
        u64 v_c132 = _t[4];
        if (!slog::exists_probe<2,1>(numindex382, std::array<u64,2>{v_c126, 0})) return;
        if (!slog::exists_probe<2,1>(refindex383, std::array<u64,2>{v_c125, 0})) return;
        if (!slog::exists_probe<2,1>(refindex384, std::array<u64,2>{v_c122, 0})) return;
        if (!slog::exists_probe<2,1>(refindex385, std::array<u64,2>{v_c124, 0})) return;
        slog::join_probe<2,1>(numindex386, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m410) {
          u64 v_c133 = m410[1];
          slog::join_probe<2,1>(numindex387, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m411) {
            u64 v_c134 = m411[1];
            slog::join_probe<2,1>(refindex388, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m412) {
              u64 v_c135 = m412[1];
              slog::join_probe<2,1>(refindex389, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m413) {
                u64 v_c136 = m413[1];
                slog::join_probe<2,1>(refindex390, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m414) {
                  u64 v_c137 = m414[1];
                  u64 v_c138 = _prim_lpush(db, v_c130, v_c123);
                  if (v_c138 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                  u64 v_c139 = _prim_lpush(db, v_c132, v_c134);
                  if (v_c139 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c128, v_c139, v_c129, v_c138, v_c131});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c137, v_c128}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp2J14999", _fires);
  
      if (!_done)
      {
        ReadTask391* _cont = new ReadTask391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask391(db,b), false);
  // (crule (pre) (scan app __t8csz347 ef es) (body (join eval (1 2 0) 1 __t8csz347 c __4zPb614)) (head (mkstruct eval (1 2 0) __0JTh615 ef c)) analysis.slog:11 #f)
  class ReadTask416 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex415;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("eval");
      evalindex415 = readrel418->getIndex(ord417, false);
  
    }
    ReadTask416(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c140 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        slog::join_probe<3,1>(evalindex415, std::array<u64,3>{v_c140, 0, 0}, [&](const std::array<u64,3>& m419) {
          u64 v_c2 = m419[1]; u64 v_c141 = m419[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:11", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask416* _cont = new ReadTask416(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask416(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre65Aa836 __errf6XU2837 __errf7wJq838 __errf0Hbr839 __errf1lH6840) (body) (head (emit error (0) __erre65Aa836)) <internal>:1 #f)
  class ReadTask420 : public slog::Task
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
      std::vector<u16> ord421({0});
      slog::Relation* readrel422 = db->getRelation("error");
      head_index[0] = readrel422->getIndex(ord421, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask420(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c143 = _t[1];
        u64 v_c144 = _t[2];
        u64 v_c145 = _t[3];
        u64 v_c146 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c142}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask420* _cont = new ReadTask420(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask420(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan eval_args __t1ye1379 _00024seq0 c) (body (letp _00024sql0xMp424 (aslst _00024seq0)) (letp e (lref _00024sql0xMp424 _00024sqc0a7Y427)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let es (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (join $sup56712x37x0x0x0 (0 3 4 2 1) 5 _00024seq0 e es c __t1ye1379) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7QcU434 e _00024seq0) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) e c __t33Oa380) (exists eval_ans (0 1) 1 __t33Oa380) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5lLk381) (exists eval_args_ans (0 1) 1 __t5lLk381) (join eval_ans (0 1) 1 __t33Oa380 __v0) (join eval_args_ans (0 1) 1 __t5lLk381 __v1)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask435 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x37x0x0x0index423;  slog::Index** $seq_atindex424;  slog::Index** eval_argsindex425;  slog::Index** evalindex426;  slog::Index** eval_ansindex427;  slog::Index** eval_argsindex428;  slog::Index** eval_args_ansindex429;  slog::Index** eval_ansindex430;  slog::Index** eval_args_ansindex431;  slog::Index** $seq_atdelta432;  slog::Index** evaldelta433;  slog::Index** eval_argsdelta434;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord436({0, 3, 4, 2, 1});
      slog::Relation* readrel437 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index423 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 0, 2});
      slog::Relation* readrel439 = db->getRelation("$seq_at");
      $seq_atindex424 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 0, 2});
      slog::Relation* readrel441 = db->getRelation("$seq_at");
      $seq_atdelta432 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({1, 2, 0});
      slog::Relation* readrel443 = db->getRelation("eval_args");
      eval_argsindex425 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 2, 0});
      slog::Relation* readrel445 = db->getRelation("eval");
      evalindex426 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 2, 0});
      slog::Relation* readrel447 = db->getRelation("eval");
      evaldelta433 = readrel447->getIndex(ord446, true);
      std::vector<u16> ord448({0, 1});
      slog::Relation* readrel449 = db->getRelation("eval_ans");
      eval_ansindex427 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 2, 0});
      slog::Relation* readrel451 = db->getRelation("eval_args");
      eval_argsindex428 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("eval_args");
      eval_argsdelta434 = readrel453->getIndex(ord452, true);
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("eval_args_ans");
      eval_args_ansindex429 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 1});
      slog::Relation* readrel457 = db->getRelation("eval_ans");
      eval_ansindex430 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("eval_args_ans");
      eval_args_ansindex431 = readrel459->getIndex(ord458, false);
  
    }
    ReadTask435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c150 = v_const5feceb66ffc86f38d952786c;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
      u64 v_c152 = _prim_lempty(db);
      if (v_c152 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c2 = _t[2];
        bool ok460 = true;
        u64 v_c154 = _prim_aslst(db, v_c83, &ok460);
        if (!ok460) return;
        bool ok461 = true;
        u64 v_c87 = _prim_lref(db, v_c154, v_c148, &ok461);
        if (!ok461) return;
        u64 v_c155 = _prim_llen(db, v_c154);
        if (v_c155 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c156 = _prim_ge(db, v_c155, v_c147);
        if (v_c156 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c156) return;
        u64 v_c157 = _prim__0002d(db, v_c155, v_c150);
        if (v_c157 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c64 = _prim_lslice(db, v_c154, v_c149, v_c157);
        if (v_c64 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        slog::join_probe<5,5>($sup56712x37x0x0x0index423, std::array<u64,5>{v_c83, v_c87, v_c64, v_c2, v_c153}, [&](const std::array<u64,5>& m463) {
          slog::join_probe_old<3,3>($seq_atindex424, $seq_atdelta432, std::array<u64,3>{v_c151, v_c87, v_c83}, [&](const std::array<u64,3>& m464) {
            if (!slog::exists_probe<3,2>(eval_argsindex425, std::array<u64,3>{v_c64, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex426, evaldelta433, std::array<u64,3>{v_c87, v_c2, 0}, [&](const std::array<u64,3>& m465) {
              u64 v_c158 = m465[2];
              if (!slog::exists_probe<2,1>(eval_ansindex427, std::array<u64,2>{v_c158, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex428, eval_argsdelta434, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m466) {
                u64 v_c159 = m466[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex429, std::array<u64,2>{v_c159, 0})) return;
                slog::join_probe<2,1>(eval_ansindex430, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m467) {
                  u64 v_c3 = m467[1];
                  slog::join_probe<2,1>(eval_args_ansindex431, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m468) {
                    u64 v_c160 = m468[1];
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c153, v_c152, v_c3, v_c160});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask435* _cont = new ReadTask435(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask435(db,b), false);
  // (crule (pre) (scan let __t9408360 x er eb) (body (exists eval (1 2 0) 1 er) (join eval (1 2 0) 1 __t9408360 c __9hFj634) (join-old eval (1 2 0) 2 (1 2 0) er c __t1yWg361) (join eval_ans (0 1) 1 __t1yWg361 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask474 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex469;  slog::Index** evalindex470;  slog::Index** evalindex471;  slog::Index** eval_ansindex472;  slog::Index** evaldelta473;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord475({0, 1, 2});
      slog::Relation* readrel476 = db->getRelation("binding");
      head_index[0] = readrel476->getIndex(ord475, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord477({0, 1, 2});
      slog::Relation* readrel478 = db->getRelation("binding_event");
      head_index[1] = readrel478->getIndex(ord477, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord479({1, 2, 0});
      slog::Relation* readrel480 = db->getRelation("eval");
      evalindex469 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 2, 0});
      slog::Relation* readrel482 = db->getRelation("eval");
      evalindex470 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("eval");
      evalindex471 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 0});
      slog::Relation* readrel486 = db->getRelation("eval");
      evaldelta473 = readrel486->getIndex(ord485, true);
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("eval_ans");
      eval_ansindex472 = readrel488->getIndex(ord487, false);
  
    }
    ReadTask474(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c161 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c162 = _t[2];
        u64 v_c101 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex469, std::array<u64,3>{v_c162, 0, 0})) return;
        slog::join_probe<3,1>(evalindex470, std::array<u64,3>{v_c161, 0, 0}, [&](const std::array<u64,3>& m489) {
          u64 v_c2 = m489[1]; u64 v_c163 = m489[2];
          slog::join_probe_old<3,2>(evalindex471, evaldelta473, std::array<u64,3>{v_c162, v_c2, 0}, [&](const std::array<u64,3>& m490) {
            u64 v_c164 = m490[2];
            slog::join_probe<2,1>(eval_ansindex472, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m491) {
              u64 v_c165 = m491[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c165}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask474* _cont = new ReadTask474(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask474(db,b), false);
  // (crule (pre) (scan eval __2TQp678 __t3lnK155 c) (body (join-old eval (2 0 1) 1 (2 0 1) c __t3XtU156 er) (exists eval_ans (0 1) 1 __t3XtU156) (join letrec (0 2 1 3) 2 __t3lnK155 er x eb) (join-old eval_ans (0 1) 1 (0 1) __t3XtU156 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask498 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex492;  slog::Index** eval_ansindex493;  slog::Index** letrecindex494;  slog::Index** eval_ansindex495;  slog::Index** evaldelta496;  slog::Index** eval_ansdelta497;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord499({0, 1, 2});
      slog::Relation* readrel500 = db->getRelation("binding");
      head_index[0] = readrel500->getIndex(ord499, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord501({0, 1, 2});
      slog::Relation* readrel502 = db->getRelation("binding_event");
      head_index[1] = readrel502->getIndex(ord501, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord503({2, 0, 1});
      slog::Relation* readrel504 = db->getRelation("eval");
      evalindex492 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({2, 0, 1});
      slog::Relation* readrel506 = db->getRelation("eval");
      evaldelta496 = readrel506->getIndex(ord505, true);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("eval_ans");
      eval_ansindex493 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({0, 2, 1, 3});
      slog::Relation* readrel510 = db->getRelation("letrec");
      letrecindex494 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({0, 1});
      slog::Relation* readrel512 = db->getRelation("eval_ans");
      eval_ansindex495 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("eval_ans");
      eval_ansdelta497 = readrel514->getIndex(ord513, true);
  
    }
    ReadTask498(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c166 = _t[0];
        u64 v_c167 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(evalindex492, evaldelta496, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m515) {
          u64 v_c168 = m515[1]; u64 v_c162 = m515[2];
          if (!slog::exists_probe<2,1>(eval_ansindex493, std::array<u64,2>{v_c168, 0})) return;
          slog::join_probe<4,2>(letrecindex494, std::array<u64,4>{v_c167, v_c162, 0, 0}, [&](const std::array<u64,4>& m516) {
            u64 v_c1 = m516[2]; u64 v_c101 = m516[3];
            slog::join_probe_old<2,1>(eval_ansindex495, eval_ansdelta497, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m517) {
              u64 v_c165 = m517[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c165}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask498* _cont = new ReadTask498(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask498(db,b), false);
  // (crule (pre) (scan temp6vCQ1007 __t1A8l169 b) (body (join boolval (1 0) 1 b __t0boW167)) (head (emit eval_ans (0 1) __t1A8l169 __t0boW167)) interp.slog:27 #f)
  class ReadTask519 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex518;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord520({0, 1});
      slog::Relation* readrel521 = db->getRelation("eval_ans");
      head_index[0] = readrel521->getIndex(ord520, false);
      outer_rel = db->getRelation("temp6vCQ1007");
      std::vector<u16> ord522({1, 0});
      slog::Relation* readrel523 = db->getRelation("boolval");
      boolvalindex518 = readrel523->getIndex(ord522, false);
  
    }
    ReadTask519(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c169 = _t[0];
        u64 v_c76 = _t[1];
        slog::join_probe<2,1>(boolvalindex518, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m524) {
          u64 v_c170 = m524[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c169, v_c170}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:27", "delta:temp6vCQ1007", _fires);
  
      if (!_done)
      {
        ReadTask519* _cont = new ReadTask519(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask519(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo1C1f450 __t4Puk145 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aST449 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Q0D451 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7GLE452 __t4Puk145 _00024seq2) (join delta (1 2 0) 2 __tconst9XQ5142 _00024seq2 __t9sdv143) (join closure (0 1 2) 1 __t4Puk145 lm cb) (join any_bool (0) 0 b) (letp _00024sql8vYG444 (aslst _00024seq2)) (let chk7IwU921 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk7IwU921) (letp chk0W77922 (lref _00024sql8vYG444 _00024sqc5yoB447)) (eq __t4Puk145 chk0W77922) (letp chk6Fqx923 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk6Fqx923)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask533 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex525;  slog::Index** $seq_atrindex526;  slog::Index** $seq_atrindex527;  slog::Index** deltaindex528;  slog::Index** closureindex529;  slog::Index** any_boolindex530;  slog::Index** $seq_atrdelta531;  slog::Index** $seq_atrdelta532;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord534({1, 0, 2});
      slog::Relation* readrel535 = db->getRelation("$seq_at");
      driver_index = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({1, 0, 2});
      slog::Relation* readrel537 = db->getRelation("$seq_at");
      $seq_atindex525 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 0, 2});
      slog::Relation* readrel539 = db->getRelation("$seq_atr");
      $seq_atrindex526 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 0, 2});
      slog::Relation* readrel541 = db->getRelation("$seq_atr");
      $seq_atrdelta531 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({1, 0, 2});
      slog::Relation* readrel543 = db->getRelation("$seq_atr");
      $seq_atrindex527 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0, 2});
      slog::Relation* readrel545 = db->getRelation("$seq_atr");
      $seq_atrdelta532 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({1, 2, 0});
      slog::Relation* readrel547 = db->getRelation("delta");
      deltaindex528 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({0, 1, 2});
      slog::Relation* readrel549 = db->getRelation("closure");
      closureindex529 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({0});
      slog::Relation* readrel551 = db->getRelation("any_bool");
      any_boolindex530 = readrel551->getIndex(ord550, false);
  
    }
    ReadTask533(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c171 = v_const06abaa100ecef791ce028c56;
      u64 v_c172 = v_constd4735e3a265e16eee03f5971;
      u64 v_c173 = v_const5feceb66ffc86f38d952786c;
      u64 v_c174 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
      u64 v_c176 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c176, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m552) {
        u64 v_c179 = m552[1];
        u64 v_c25 = m552[2];
        if (buckethash(v_c179) != bucket) return;
        slog::join_probe<3,3>($seq_atindex525, std::array<u64,3>{v_c175, v_c179, v_c25}, [&](const std::array<u64,3>& m553) {
          slog::join_probe_old<3,3>($seq_atrindex526, $seq_atrdelta531, std::array<u64,3>{v_c177, v_c179, v_c25}, [&](const std::array<u64,3>& m554) {
            slog::join_probe_old<3,3>($seq_atrindex527, $seq_atrdelta532, std::array<u64,3>{v_c178, v_c179, v_c25}, [&](const std::array<u64,3>& m555) {
              slog::join_probe<3,2>(deltaindex528, std::array<u64,3>{v_c171, v_c25, 0}, [&](const std::array<u64,3>& m556) {
                u64 v_c180 = m556[2];
                slog::join_probe<3,1>(closureindex529, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m557) {
                  u64 v_c181 = m557[1]; u64 v_c103 = m557[2];
                  slog::join_all<1>(any_boolindex530, [&](const std::array<u64,1>& m558) {
                    u64 v_c76 = m558[0];
                    bool ok559 = true;
                    u64 v_c182 = _prim_aslst(db, v_c25, &ok559);
                    if (!ok559) return;
                    u64 v_c183 = _prim_llen(db, v_c182);
                    if (v_c183 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c172 != v_c183) return;
                    bool ok560 = true;
                    u64 v_c184 = _prim_lref(db, v_c182, v_c173, &ok560);
                    if (!ok560) return;
                    if (v_c179 != v_c184) return;
                    bool ok561 = true;
                    u64 v_c185 = _prim_lref(db, v_c182, v_c174, &ok561);
                    if (!ok561) return;
                    if (v_c179 != v_c185) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c180, v_c76});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c76}, std::array<u16,2>{1, 0});
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
        ReadTask533* _cont = new ReadTask533(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask533(db,b), false);
  // (crule (pre) (scan eval __t17mt343 __t2weF342 c) (body (join sym (0 1) 1 __t2weF342 s)) (head (emit-temp temp5zyE1032 __t17mt343 s) (mkstruct symval (1 0) __t2VgD341 s)) interp.slog:28 #f)
  class ReadTask563 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex562;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5zyE1032");
      head_rel[1] = db->getRelation("symval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord564({0, 1});
      slog::Relation* readrel565 = db->getRelation("sym");
      symindex562 = readrel565->getIndex(ord564, false);
  
    }
    ReadTask563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c186 = _t[0];
        u64 v_c187 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(symindex562, std::array<u64,2>{v_c187, 0}, [&](const std::array<u64,2>& m566) {
          u64 v_c188 = m566[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c186, v_c188});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c188}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:28", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask563* _cont = new ReadTask563(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask563(db,b), false);
  // (crule (pre) (scan eval_ans __t9ATC44 __v0) (body (exists select_branch (1 2 3 0) 1 __v0) (join-old eval (0 2 1) 1 (0 2 1) __t9ATC44 c e1) (exists if (1 0 2 3) 1 e1) (exists eval (2 0 1) 1 c) (join-old $sup56712x86x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c e1 __t7yOw43 e2 e3) (exists eval (0 2 1) 2 __t7yOw43 c) (exists select_branch (1 2 3 0) 3 __v0 e2 e3) (join-old if (2 3 1 0) 3 (2 3 1 0) e2 e3 e1 __t3ePt42) (join-old eval (0 2 1) 3 (0 2 1) __t7yOw43 c __t3ePt42) (join-old select_branch (1 2 3 0) 3 (1 2 3 0) __v0 e2 e3 __t5q6W45) (join-old select_branch_ans (0 1) 1 (0 1) __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join-old eval_ans (0 1) 1 (0 1) __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex567;  slog::Index** evalindex568;  slog::Index** ifindex569;  slog::Index** evalindex570;  slog::Index** $sup56712x86x0x0x0index571;  slog::Index** evalindex572;  slog::Index** select_branchindex573;  slog::Index** ifindex574;  slog::Index** evalindex575;  slog::Index** select_branchindex576;  slog::Index** select_branch_ansindex577;  slog::Index** evalindex578;  slog::Index** eval_ansindex579;  slog::Index** evaldelta580;  slog::Index** $sup56712x86x0x0x0delta581;  slog::Index** ifdelta582;  slog::Index** evaldelta583;  slog::Index** select_branchdelta584;  slog::Index** select_branch_ansdelta585;  slog::Index** evaldelta586;  slog::Index** eval_ansdelta587;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("eval_ans");
      head_index[0] = readrel590->getIndex(ord589, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord591({1, 2, 3, 0});
      slog::Relation* readrel592 = db->getRelation("select_branch");
      select_branchindex567 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 2, 1});
      slog::Relation* readrel594 = db->getRelation("eval");
      evalindex568 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({0, 2, 1});
      slog::Relation* readrel596 = db->getRelation("eval");
      evaldelta580 = readrel596->getIndex(ord595, true);
      std::vector<u16> ord597({1, 0, 2, 3});
      slog::Relation* readrel598 = db->getRelation("if");
      ifindex569 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({2, 0, 1});
      slog::Relation* readrel600 = db->getRelation("eval");
      evalindex570 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 0, 3, 4});
      slog::Relation* readrel602 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index571 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0, 3, 4});
      slog::Relation* readrel604 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta581 = readrel604->getIndex(ord603, true);
      std::vector<u16> ord605({0, 2, 1});
      slog::Relation* readrel606 = db->getRelation("eval");
      evalindex572 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 2, 3, 0});
      slog::Relation* readrel608 = db->getRelation("select_branch");
      select_branchindex573 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({2, 3, 1, 0});
      slog::Relation* readrel610 = db->getRelation("if");
      ifindex574 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({2, 3, 1, 0});
      slog::Relation* readrel612 = db->getRelation("if");
      ifdelta582 = readrel612->getIndex(ord611, true);
      std::vector<u16> ord613({0, 2, 1});
      slog::Relation* readrel614 = db->getRelation("eval");
      evalindex575 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({0, 2, 1});
      slog::Relation* readrel616 = db->getRelation("eval");
      evaldelta583 = readrel616->getIndex(ord615, true);
      std::vector<u16> ord617({1, 2, 3, 0});
      slog::Relation* readrel618 = db->getRelation("select_branch");
      select_branchindex576 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 2, 3, 0});
      slog::Relation* readrel620 = db->getRelation("select_branch");
      select_branchdelta584 = readrel620->getIndex(ord619, true);
      std::vector<u16> ord621({0, 1});
      slog::Relation* readrel622 = db->getRelation("select_branch_ans");
      select_branch_ansindex577 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({0, 1});
      slog::Relation* readrel624 = db->getRelation("select_branch_ans");
      select_branch_ansdelta585 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("eval");
      evalindex578 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("eval");
      evaldelta586 = readrel628->getIndex(ord627, true);
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("eval_ans");
      eval_ansindex579 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({0, 1});
      slog::Relation* readrel632 = db->getRelation("eval_ans");
      eval_ansdelta587 = readrel632->getIndex(ord631, true);
  
    }
    ReadTask588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c189 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex567, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex568, evaldelta580, std::array<u64,3>{v_c189, 0, 0}, [&](const std::array<u64,3>& m633) {
          u64 v_c2 = m633[1]; u64 v_c190 = m633[2];
          if (!slog::exists_probe<4,1>(ifindex569, std::array<u64,4>{v_c190, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex570, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x86x0x0x0index571, $sup56712x86x0x0x0delta581, std::array<u64,5>{v_c2, v_c190, 0, 0, 0}, [&](const std::array<u64,5>& m634) {
            u64 v_c191 = m634[2]; u64 v_c9 = m634[3]; u64 v_c10 = m634[4];
            if (!slog::exists_probe<3,2>(evalindex572, std::array<u64,3>{v_c191, v_c2, 0})) return;
            if (!slog::exists_probe<4,3>(select_branchindex573, std::array<u64,4>{v_c3, v_c9, v_c10, 0})) return;
            slog::join_probe_old<4,3>(ifindex574, ifdelta582, std::array<u64,4>{v_c9, v_c10, v_c190, 0}, [&](const std::array<u64,4>& m635) {
              u64 v_c192 = m635[3];
              slog::join_probe_old<3,3>(evalindex575, evaldelta583, std::array<u64,3>{v_c191, v_c2, v_c192}, [&](const std::array<u64,3>& m636) {
                slog::join_probe_old<4,3>(select_branchindex576, select_branchdelta584, std::array<u64,4>{v_c3, v_c9, v_c10, 0}, [&](const std::array<u64,4>& m637) {
                  u64 v_c193 = m637[3];
                  slog::join_probe_old<2,1>(select_branch_ansindex577, select_branch_ansdelta585, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m638) {
                    u64 v_c160 = m638[1];
                    slog::join_probe_old<3,2>(evalindex578, evaldelta586, std::array<u64,3>{v_c160, v_c2, 0}, [&](const std::array<u64,3>& m639) {
                      u64 v_c194 = m639[2];
                      slog::join_probe_old<2,1>(eval_ansindex579, eval_ansdelta587, std::array<u64,2>{v_c194, 0}, [&](const std::array<u64,2>& m640) {
                        u64 v_c195 = m640[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c191, v_c195}, std::array<u16,2>{0, 1});
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
        ReadTask588* _cont = new ReadTask588(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask588(db,b), false);
  // (crule (pre) (scan eval_args __t3tQh27 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (2 0 1) 2 (2 0 1) es __t3Fr129 ef) (join eval (1 2 0) 2 ef c __t84Ji24) (exists eval_ans (0 1) 1 __t84Ji24) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join tick_ans (0 1) 1 __t0NvE30 l) (join closure (0 1 2) 1 __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask662 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex641;  slog::Index** appindex642;  slog::Index** tickindex643;  slog::Index** eval_args_ansindex644;  slog::Index** evalindex645;  slog::Index** tickindex646;  slog::Index** appindex647;  slog::Index** evalindex648;  slog::Index** eval_ansindex649;  slog::Index** tickindex650;  slog::Index** tick_ansindex651;  slog::Index** eval_ansindex652;  slog::Index** tick_ansindex653;  slog::Index** closureindex654;  slog::Index** bindingindex655;  slog::Index** freevarindex656;  slog::Index** bindingindex657;  slog::Index** lambdaindex658;  slog::Index** appdelta659;  slog::Index** tickdelta660;  slog::Index** lambdadelta661;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord663({0, 1, 2});
      slog::Relation* readrel664 = db->getRelation("binding");
      head_index[0] = readrel664->getIndex(ord663, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord665({0, 1, 2});
      slog::Relation* readrel666 = db->getRelation("binding_event");
      head_index[1] = readrel666->getIndex(ord665, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord667({2, 0, 1});
      slog::Relation* readrel668 = db->getRelation("eval");
      evalindex641 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({2, 0, 1});
      slog::Relation* readrel670 = db->getRelation("app");
      appindex642 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({2, 0, 1});
      slog::Relation* readrel672 = db->getRelation("tick");
      tickindex643 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 1});
      slog::Relation* readrel674 = db->getRelation("eval_args_ans");
      eval_args_ansindex644 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({2, 0, 1});
      slog::Relation* readrel676 = db->getRelation("eval");
      evalindex645 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 0});
      slog::Relation* readrel678 = db->getRelation("tick");
      tickindex646 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({2, 0, 1});
      slog::Relation* readrel680 = db->getRelation("app");
      appindex647 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({2, 0, 1});
      slog::Relation* readrel682 = db->getRelation("app");
      appdelta659 = readrel682->getIndex(ord681, true);
      std::vector<u16> ord683({1, 2, 0});
      slog::Relation* readrel684 = db->getRelation("eval");
      evalindex648 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({0, 1});
      slog::Relation* readrel686 = db->getRelation("eval_ans");
      eval_ansindex649 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("tick");
      tickindex650 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("tick");
      tickdelta660 = readrel690->getIndex(ord689, true);
      std::vector<u16> ord691({0, 1});
      slog::Relation* readrel692 = db->getRelation("tick_ans");
      tick_ansindex651 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1});
      slog::Relation* readrel694 = db->getRelation("eval_ans");
      eval_ansindex652 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("tick_ans");
      tick_ansindex653 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1, 2});
      slog::Relation* readrel698 = db->getRelation("closure");
      closureindex654 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 0, 2});
      slog::Relation* readrel700 = db->getRelation("binding");
      bindingindex655 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 0});
      slog::Relation* readrel702 = db->getRelation("freevar");
      freevarindex656 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({0, 1, 2});
      slog::Relation* readrel704 = db->getRelation("binding");
      bindingindex657 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1, 2});
      slog::Relation* readrel706 = db->getRelation("lambda");
      lambdaindex658 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1, 2});
      slog::Relation* readrel708 = db->getRelation("lambda");
      lambdadelta661 = readrel708->getIndex(ord707, true);
  
    }
    ReadTask662(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c109 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex641, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex642, std::array<u64,3>{v_c64, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex643, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex644, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m709) {
          u64 v_c111 = m709[1];
          slog::join_probe<3,1>(evalindex645, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m710) {
            u64 v_c107 = m710[1]; u64 v_c108 = m710[2];
            if (!slog::exists_probe<3,2>(tickindex646, std::array<u64,3>{v_c108, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex647, appdelta659, std::array<u64,3>{v_c64, v_c108, 0}, [&](const std::array<u64,3>& m711) {
              u64 v_c63 = m711[2];
              slog::join_probe<3,2>(evalindex648, std::array<u64,3>{v_c63, v_c2, 0}, [&](const std::array<u64,3>& m712) {
                u64 v_c106 = m712[2];
                if (!slog::exists_probe<2,1>(eval_ansindex649, std::array<u64,2>{v_c106, 0})) return;
                slog::join_probe_old<3,2>(tickindex650, tickdelta660, std::array<u64,3>{v_c108, v_c2, 0}, [&](const std::array<u64,3>& m713) {
                  u64 v_c110 = m713[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex651, std::array<u64,2>{v_c110, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex652, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m714) {
                    u64 v_c105 = m714[1];
                    slog::join_probe<2,1>(tick_ansindex653, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m715) {
                      u64 v_c112 = m715[1];
                      slog::join_probe<3,1>(closureindex654, std::array<u64,3>{v_c105, 0, 0}, [&](const std::array<u64,3>& m716) {
                        u64 v_c99 = m716[1]; u64 v_c103 = m716[2];
                        if (!slog::exists_probe<3,1>(bindingindex655, std::array<u64,3>{v_c103, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex656, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m717) {
                          u64 v_c102 = m717[1];
                          slog::join_probe<3,2>(bindingindex657, std::array<u64,3>{v_c102, v_c103, 0}, [&](const std::array<u64,3>& m718) {
                            u64 v_c104 = m718[2];
                            slog::join_probe_old<3,1>(lambdaindex658, lambdadelta661, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m719) {
                              u64 v_c100 = m719[1]; u64 v_c101 = m719[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c102, v_c112, v_c104}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c102, v_c112, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask662* _cont = new ReadTask662(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask662(db,b), false);
  // (crule (pre) (scan tick __t8kWT184 __t7cos183 c) (body (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (exists tick_ans (0 1) 1 __t8kWT184) (join eval (1 2 0) 2 __t7cos183 c __t6uzd177) (join $sup56712x41x0x0x0 (1 0 2 3) 2 c __t6uzd177 ef es) (join app (0 1 2) 3 __t7cos183 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (1 2 0) 2 ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join eval_args (1 2 0) 2 es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t4yWQ180 __t7rcY179 cb) (join lambda (0 1 2) 1 __t7rcY179 xs eb) (join eval (1 2 0) 2 eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask740 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x41x0x0x0index720;  slog::Index** evalindex721;  slog::Index** eval_argsindex722;  slog::Index** tick_ansindex723;  slog::Index** evalindex724;  slog::Index** $sup56712x41x0x0x0index725;  slog::Index** appindex726;  slog::Index** eval_argsindex727;  slog::Index** evalindex728;  slog::Index** eval_ansindex729;  slog::Index** eval_argsindex730;  slog::Index** eval_args_ansindex731;  slog::Index** eval_ansindex732;  slog::Index** eval_args_ansindex733;  slog::Index** tick_ansindex734;  slog::Index** evalindex735;  slog::Index** closureindex736;  slog::Index** lambdaindex737;  slog::Index** evalindex738;  slog::Index** eval_ansindex739;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord741({0, 1});
      slog::Relation* readrel742 = db->getRelation("eval_ans");
      head_index[0] = readrel742->getIndex(ord741, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord743({1, 0, 2, 3});
      slog::Relation* readrel744 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index720 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({2, 0, 1});
      slog::Relation* readrel746 = db->getRelation("eval");
      evalindex721 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({2, 0, 1});
      slog::Relation* readrel748 = db->getRelation("eval_args");
      eval_argsindex722 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({0, 1});
      slog::Relation* readrel750 = db->getRelation("tick_ans");
      tick_ansindex723 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 2, 0});
      slog::Relation* readrel752 = db->getRelation("eval");
      evalindex724 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({1, 0, 2, 3});
      slog::Relation* readrel754 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index725 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({0, 1, 2});
      slog::Relation* readrel756 = db->getRelation("app");
      appindex726 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 2, 0});
      slog::Relation* readrel758 = db->getRelation("eval_args");
      eval_argsindex727 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 2, 0});
      slog::Relation* readrel760 = db->getRelation("eval");
      evalindex728 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({0, 1});
      slog::Relation* readrel762 = db->getRelation("eval_ans");
      eval_ansindex729 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("eval_args");
      eval_argsindex730 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("eval_args_ans");
      eval_args_ansindex731 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({0, 1});
      slog::Relation* readrel768 = db->getRelation("eval_ans");
      eval_ansindex732 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({0, 1});
      slog::Relation* readrel770 = db->getRelation("eval_args_ans");
      eval_args_ansindex733 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({0, 1});
      slog::Relation* readrel772 = db->getRelation("tick_ans");
      tick_ansindex734 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({2, 0, 1});
      slog::Relation* readrel774 = db->getRelation("eval");
      evalindex735 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({0, 1, 2});
      slog::Relation* readrel776 = db->getRelation("closure");
      closureindex736 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({0, 1, 2});
      slog::Relation* readrel778 = db->getRelation("lambda");
      lambdaindex737 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 2, 0});
      slog::Relation* readrel780 = db->getRelation("eval");
      evalindex738 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 1});
      slog::Relation* readrel782 = db->getRelation("eval_ans");
      eval_ansindex739 = readrel782->getIndex(ord781, false);
  
    }
    ReadTask740(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[0];
        u64 v_c197 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index720, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex721, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex722, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(tick_ansindex723, std::array<u64,2>{v_c196, 0})) return;
        slog::join_probe<3,2>(evalindex724, std::array<u64,3>{v_c197, v_c2, 0}, [&](const std::array<u64,3>& m783) {
          u64 v_c198 = m783[2];
          slog::join_probe<4,2>($sup56712x41x0x0x0index725, std::array<u64,4>{v_c2, v_c198, 0, 0}, [&](const std::array<u64,4>& m784) {
            u64 v_c63 = m784[2]; u64 v_c64 = m784[3];
            slog::join_probe<3,3>(appindex726, std::array<u64,3>{v_c197, v_c63, v_c64}, [&](const std::array<u64,3>& m785) {
              if (!slog::exists_probe<3,2>(eval_argsindex727, std::array<u64,3>{v_c64, v_c2, 0})) return;
              slog::join_probe<3,2>(evalindex728, std::array<u64,3>{v_c63, v_c2, 0}, [&](const std::array<u64,3>& m786) {
                u64 v_c199 = m786[2];
                if (!slog::exists_probe<2,1>(eval_ansindex729, std::array<u64,2>{v_c199, 0})) return;
                slog::join_probe<3,2>(eval_argsindex730, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m787) {
                  u64 v_c200 = m787[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex731, std::array<u64,2>{v_c200, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex732, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m788) {
                    u64 v_c201 = m788[1];
                    slog::join_probe<2,1>(eval_args_ansindex733, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m789) {
                      u64 v_c111 = m789[1];
                      slog::join_probe<2,1>(tick_ansindex734, std::array<u64,2>{v_c196, 0}, [&](const std::array<u64,2>& m790) {
                        u64 v_c3 = m790[1];
                        if (!slog::exists_probe<3,1>(evalindex735, std::array<u64,3>{v_c3, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex736, std::array<u64,3>{v_c201, 0, 0}, [&](const std::array<u64,3>& m791) {
                          u64 v_c202 = m791[1]; u64 v_c103 = m791[2];
                          slog::join_probe<3,1>(lambdaindex737, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m792) {
                            u64 v_c100 = m792[1]; u64 v_c101 = m792[2];
                            slog::join_probe<3,2>(evalindex738, std::array<u64,3>{v_c101, v_c3, 0}, [&](const std::array<u64,3>& m793) {
                              u64 v_c203 = m793[2];
                              slog::join_probe<2,1>(eval_ansindex739, std::array<u64,2>{v_c203, 0}, [&](const std::array<u64,2>& m794) {
                                u64 v_c204 = m794[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c204}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask740* _cont = new ReadTask740(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask740(db,b), false);
  // (crule (pre) (scan lookup_ans __t0d3433 __v0) (body (join-old lookup (0 1 2) 1 (0 1 2) __t0d3433 x c) (exists eval (2 0 1) 1 c) (join-old ref (1 0) 1 (1 0) x __t8l5731) (join-old eval (1 2 0) 2 (1 2 0) __t8l5731 c __t8n0332)) (head (emit eval_ans (0 1) __t8n0332 __v0)) interp.slog:30 #f)
  class ReadTask802 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex795;  slog::Index** evalindex796;  slog::Index** refindex797;  slog::Index** evalindex798;  slog::Index** lookupdelta799;  slog::Index** refdelta800;  slog::Index** evaldelta801;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord803({0, 1});
      slog::Relation* readrel804 = db->getRelation("eval_ans");
      head_index[0] = readrel804->getIndex(ord803, false);
      outer_rel = db->getRelation("lookup_ans");
      std::vector<u16> ord805({0, 1, 2});
      slog::Relation* readrel806 = db->getRelation("lookup");
      lookupindex795 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 1, 2});
      slog::Relation* readrel808 = db->getRelation("lookup");
      lookupdelta799 = readrel808->getIndex(ord807, true);
      std::vector<u16> ord809({2, 0, 1});
      slog::Relation* readrel810 = db->getRelation("eval");
      evalindex796 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 0});
      slog::Relation* readrel812 = db->getRelation("ref");
      refindex797 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0});
      slog::Relation* readrel814 = db->getRelation("ref");
      refdelta800 = readrel814->getIndex(ord813, true);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("eval");
      evalindex798 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("eval");
      evaldelta801 = readrel818->getIndex(ord817, true);
  
    }
    ReadTask802(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        slog::join_probe_old<3,1>(lookupindex795, lookupdelta799, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m819) {
          u64 v_c1 = m819[1]; u64 v_c2 = m819[2];
          if (!slog::exists_probe<3,1>(evalindex796, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>(refindex797, refdelta800, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m820) {
            u64 v_c4 = m820[1];
            slog::join_probe_old<3,2>(evalindex798, evaldelta801, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m821) {
              u64 v_c5 = m821[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c3}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:lookup_ans", _fires);
  
      if (!_done)
      {
        ReadTask802* _cont = new ReadTask802(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask802(db,b), false);
  // (crule (pre) (scan app __t33MT383 ef es) (body) (head (emit argument_list (0) es)) freevars.slog:33 #f)
  class ReadTask822 : public slog::Task
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
      head_rel[0] = db->getRelation("argument_list");
      std::vector<u16> ord823({0});
      slog::Relation* readrel824 = db->getRelation("argument_list");
      head_index[0] = readrel824->getIndex(ord823, false);
      outer_rel = db->getRelation("app");
  
    }
    ReadTask822(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c205 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:33", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask822* _cont = new ReadTask822(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask822(db,b), false);
  // (crule (pre) (scan freevar_in_args x es) (body (join-old app (2 0 1) 1 (2 0 1) es __t9RxE131 ef)) (head (emit freevar (0 1) x __t9RxE131)) freevars.slog:13 #f)
  class ReadTask827 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex825;  slog::Index** appdelta826;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("freevar");
      head_index[0] = readrel829->getIndex(ord828, false);
      outer_rel = db->getRelation("freevar_in_args");
      std::vector<u16> ord830({2, 0, 1});
      slog::Relation* readrel831 = db->getRelation("app");
      appindex825 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({2, 0, 1});
      slog::Relation* readrel833 = db->getRelation("app");
      appdelta826 = readrel833->getIndex(ord832, true);
  
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
        u64 v_c1 = _t[0];
        u64 v_c64 = _t[1];
        slog::join_probe_old<3,1>(appindex825, appdelta826, std::array<u64,3>{v_c64, 0, 0}, [&](const std::array<u64,3>& m834) {
          u64 v_c206 = m834[1]; u64 v_c63 = m834[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c206}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar_in_args", _fires);
  
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
  // (crule (pre) (scan eval __t59EL158 __t4e5j157 c) (body (join app (0 1 2) 1 __t4e5j157 ef es)) (head (emit $sup56712x41x0x0x0 (1 0 2 3) c __t59EL158 ef es)) interp.slog:42 #f)
  class ReadTask836 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex835;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord837({1, 0, 2, 3});
      slog::Relation* readrel838 = db->getRelation("$sup56712x41x0x0x0");
      head_index[0] = readrel838->getIndex(ord837, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord839({0, 1, 2});
      slog::Relation* readrel840 = db->getRelation("app");
      appindex835 = readrel840->getIndex(ord839, false);
  
    }
    ReadTask836(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(appindex835, std::array<u64,3>{v_c208, 0, 0}, [&](const std::array<u64,3>& m841) {
          u64 v_c63 = m841[1]; u64 v_c64 = m841[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c207, v_c63, v_c64}, std::array<u16,4>{1, 0, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask836* _cont = new ReadTask836(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask836(db,b), false);
  // (crule (pre (let __trid3Ey3582 const342a69eb5a93251c8b7e179a) (let __trel65ch583 constf6cdc3db4b71e0cdeda6912e) (let __tcol4Ars584 const6b86b273ff34fce19d6b804e) (let __trel1pCT585 constf6cdc3db4b71e0cdeda6912e) (let __tcol8ZHX586 constd4735e3a265e16eee03f5971)) (scan eval __t9qzE362 e1 c) (body (exists eval_ans (0 1) 1 __t9qzE362) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join eval_ans (0 1) 1 __t9qzE362 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel65ch583 __tcol4Ars584 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel1pCT585 __tcol8ZHX586 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __9nb7581 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask854 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex842;  slog::Index** $sup56712x86x0x0x0index843;  slog::Index** eval_ansindex844;
    u32 sid845;  u32 sid846;  u32 sid847;  u32 sid848;  u32 sid849;  u32 sid850;  u32 sid851;  u32 sid852;  u32 sid853;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord855({0, 1});
      slog::Relation* readrel856 = db->getRelation("eval_ans");
      eval_ansindex842 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 0, 3, 4});
      slog::Relation* readrel858 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index843 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({0, 1});
      slog::Relation* readrel860 = db->getRelation("eval_ans");
      eval_ansindex844 = readrel860->getIndex(ord859, false);
      sid845 = db->getRelation("app")->getStructId();
      sid846 = db->getRelation("boolean")->getStructId();
      sid847 = db->getRelation("if")->getStructId();
      sid848 = db->getRelation("lambda")->getStructId();
      sid849 = db->getRelation("let")->getStructId();
      sid850 = db->getRelation("letrec")->getStructId();
      sid851 = db->getRelation("num")->getStructId();
      sid852 = db->getRelation("ref")->getStructId();
      sid853 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask854(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c210 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c211 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c212 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c213 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c214 = _t[0];
        u64 v_c190 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex842, std::array<u64,2>{v_c214, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index843, std::array<u64,5>{v_c2, v_c190, 0, 0, 0}, [&](const std::array<u64,5>& m861) {
          u64 v_c62 = m861[2]; u64 v_c9 = m861[3]; u64 v_c10 = m861[4];
          slog::join_probe<2,1>(eval_ansindex844, std::array<u64,2>{v_c214, 0}, [&](const std::array<u64,2>& m862) {
            u64 v_c3 = m862[1];
            ++_fires;
            if (!((is_struct(v_c9) && (decode_struct_id(v_c9) == sid845 || decode_struct_id(v_c9) == sid846 || decode_struct_id(v_c9) == sid847 || decode_struct_id(v_c9) == sid848 || decode_struct_id(v_c9) == sid849 || decode_struct_id(v_c9) == sid850 || decode_struct_id(v_c9) == sid851 || decode_struct_id(v_c9) == sid852 || decode_struct_id(v_c9) == sid853))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c209, v_c210, v_c211, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid845 || decode_struct_id(v_c10) == sid846 || decode_struct_id(v_c10) == sid847 || decode_struct_id(v_c10) == sid848 || decode_struct_id(v_c10) == sid849 || decode_struct_id(v_c10) == sid850 || decode_struct_id(v_c10) == sid851 || decode_struct_id(v_c10) == sid852 || decode_struct_id(v_c10) == sid853))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c209, v_c212, v_c213, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c3, v_c9, v_c10}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask854* _cont = new ReadTask854(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask854(db,b), false);
  // (crule (pre) (scan eval __5oJJ605 __t9RJc318 c) (body (join-old app (0 1 2) 1 (0 1 2) __t9RJc318 ef es)) (head (mkstruct eval (1 2 0) __8Fdd606 ef c)) interp.slog:48 #f)
  class ReadTask865 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex863;  slog::Index** appdelta864;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord866({0, 1, 2});
      slog::Relation* readrel867 = db->getRelation("app");
      appindex863 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1, 2});
      slog::Relation* readrel869 = db->getRelation("app");
      appdelta864 = readrel869->getIndex(ord868, true);
  
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
        u64 v_c215 = _t[0];
        u64 v_c216 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex863, appdelta864, std::array<u64,3>{v_c216, 0, 0}, [&](const std::array<u64,3>& m870) {
          u64 v_c63 = m870[1]; u64 v_c64 = m870[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
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
  // (crule (pre) (scan ref __t1ou9207 x) (body (join-old eval (1 2 0) 1 (1 2 0) __t1ou9207 c __t4RAT208)) (head (mkstruct lookup (1 2 0) __54Gi608 x c)) interp.slog:30 #f)
  class ReadTask873 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex871;  slog::Index** evaldelta872;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord874({1, 2, 0});
      slog::Relation* readrel875 = db->getRelation("eval");
      evalindex871 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 2, 0});
      slog::Relation* readrel877 = db->getRelation("eval");
      evaldelta872 = readrel877->getIndex(ord876, true);
  
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
        u64 v_c217 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<3,1>(evalindex871, evaldelta872, std::array<u64,3>{v_c217, 0, 0}, [&](const std::array<u64,3>& m878) {
          u64 v_c2 = m878[1]; u64 v_c218 = m878[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:ref", _fires);
  
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
  // (crule (pre) (scan app __t6KUR174 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t6KUR174) (join $sup56712x41x0x0x0 (2 3 0 1) 2 ef es __d0 c) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t6KUR174 c) (join eval (1 2 0) 2 ef c __t66Yt170) (exists eval_ans (0 1) 1 __t66Yt170) (join eval_args (1 2 0) 2 es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join tick_ans (0 1) 1 __t9uJP175 __v0) (join closure (0 1 2) 1 __t8UWw172 __t3anZ171 cb) (join lambda (0 1 2) 1 __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask897 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex879;  slog::Index** eval_argsindex880;  slog::Index** tickindex881;  slog::Index** $sup56712x41x0x0x0index882;  slog::Index** eval_argsindex883;  slog::Index** tickindex884;  slog::Index** evalindex885;  slog::Index** eval_ansindex886;  slog::Index** eval_argsindex887;  slog::Index** eval_args_ansindex888;  slog::Index** tickindex889;  slog::Index** tick_ansindex890;  slog::Index** eval_ansindex891;  slog::Index** eval_args_ansindex892;  slog::Index** tick_ansindex893;  slog::Index** closureindex894;  slog::Index** lambdaindex895;  slog::Index** tickdelta896;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord898({1, 2, 0});
      slog::Relation* readrel899 = db->getRelation("eval");
      evalindex879 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 2, 0});
      slog::Relation* readrel901 = db->getRelation("eval_args");
      eval_argsindex880 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("tick");
      tickindex881 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({2, 3, 0, 1});
      slog::Relation* readrel905 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index882 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({1, 2, 0});
      slog::Relation* readrel907 = db->getRelation("eval_args");
      eval_argsindex883 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 2, 0});
      slog::Relation* readrel909 = db->getRelation("tick");
      tickindex884 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 0});
      slog::Relation* readrel911 = db->getRelation("eval");
      evalindex885 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({0, 1});
      slog::Relation* readrel913 = db->getRelation("eval_ans");
      eval_ansindex886 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 0});
      slog::Relation* readrel915 = db->getRelation("eval_args");
      eval_argsindex887 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({0, 1});
      slog::Relation* readrel917 = db->getRelation("eval_args_ans");
      eval_args_ansindex888 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("tick");
      tickindex889 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 2, 0});
      slog::Relation* readrel921 = db->getRelation("tick");
      tickdelta896 = readrel921->getIndex(ord920, true);
      std::vector<u16> ord922({0, 1});
      slog::Relation* readrel923 = db->getRelation("tick_ans");
      tick_ansindex890 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({0, 1});
      slog::Relation* readrel925 = db->getRelation("eval_ans");
      eval_ansindex891 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({0, 1});
      slog::Relation* readrel927 = db->getRelation("eval_args_ans");
      eval_args_ansindex892 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({0, 1});
      slog::Relation* readrel929 = db->getRelation("tick_ans");
      tick_ansindex893 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({0, 1, 2});
      slog::Relation* readrel931 = db->getRelation("closure");
      closureindex894 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({0, 1, 2});
      slog::Relation* readrel933 = db->getRelation("lambda");
      lambdaindex895 = readrel933->getIndex(ord932, false);
  
    }
    ReadTask897(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c219 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex879, std::array<u64,3>{v_c63, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex880, std::array<u64,3>{v_c64, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex881, std::array<u64,3>{v_c219, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index882, std::array<u64,4>{v_c63, v_c64, 0, 0}, [&](const std::array<u64,4>& m934) {
          u64 v_c62 = m934[2]; u64 v_c2 = m934[3];
          if (!slog::exists_probe<3,2>(eval_argsindex883, std::array<u64,3>{v_c64, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex884, std::array<u64,3>{v_c219, v_c2, 0})) return;
          slog::join_probe<3,2>(evalindex885, std::array<u64,3>{v_c63, v_c2, 0}, [&](const std::array<u64,3>& m935) {
            u64 v_c220 = m935[2];
            if (!slog::exists_probe<2,1>(eval_ansindex886, std::array<u64,2>{v_c220, 0})) return;
            slog::join_probe<3,2>(eval_argsindex887, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m936) {
              u64 v_c221 = m936[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex888, std::array<u64,2>{v_c221, 0})) return;
              slog::join_probe_old<3,2>(tickindex889, tickdelta896, std::array<u64,3>{v_c219, v_c2, 0}, [&](const std::array<u64,3>& m937) {
                u64 v_c222 = m937[2];
                if (!slog::exists_probe<2,1>(tick_ansindex890, std::array<u64,2>{v_c222, 0})) return;
                slog::join_probe<2,1>(eval_ansindex891, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m938) {
                  u64 v_c223 = m938[1];
                  slog::join_probe<2,1>(eval_args_ansindex892, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m939) {
                    u64 v_c111 = m939[1];
                    slog::join_probe<2,1>(tick_ansindex893, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m940) {
                      u64 v_c3 = m940[1];
                      slog::join_probe<3,1>(closureindex894, std::array<u64,3>{v_c223, 0, 0}, [&](const std::array<u64,3>& m941) {
                        u64 v_c224 = m941[1]; u64 v_c103 = m941[2];
                        slog::join_probe<3,1>(lambdaindex895, std::array<u64,3>{v_c224, 0, 0}, [&](const std::array<u64,3>& m942) {
                          u64 v_c100 = m942[1]; u64 v_c101 = m942[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c101, v_c3}, std::array<u16,3>{1, 2, 0});
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
        ReadTask897* _cont = new ReadTask897(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask897(db,b), false);
  // (crule (pre) (scan eval_ans __t56Is182 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t56Is182 __v0 eb) (exists lambda (2 0 1) 1 eb) (join-old tick_ans (1 0) 1 (1 0) __v0 __t8kWT184) (join-old lambda (2 0 1) 1 (2 0 1) eb __t7rcY179 xs) (join-old closure (1 2 0) 1 (1 2 0) __t7rcY179 cb __t4yWQ180) (join eval_ans (1 0) 1 __t4yWQ180 __t6e44178) (join-old eval (0 2 1) 1 (0 2 1) __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t8kWT184 c __t7cos183) (exists app (0 1 2) 2 __t7cos183 ef) (join-old eval (1 2 0) 2 (1 2 0) __t7cos183 c __t6uzd177) (join-old $sup56712x41x0x0x0 (1 0 2 3) 3 (1 0 2 3) c __t6uzd177 ef es) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (join eval_args_ans (0 1) 1 __t6UxD181 vs)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask971 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex943;  slog::Index** lambdaindex944;  slog::Index** tick_ansindex945;  slog::Index** lambdaindex946;  slog::Index** closureindex947;  slog::Index** eval_ansindex948;  slog::Index** evalindex949;  slog::Index** evalindex950;  slog::Index** $sup56712x41x0x0x0index951;  slog::Index** appindex952;  slog::Index** eval_argsindex953;  slog::Index** tickindex954;  slog::Index** appindex955;  slog::Index** evalindex956;  slog::Index** $sup56712x41x0x0x0index957;  slog::Index** appindex958;  slog::Index** eval_argsindex959;  slog::Index** eval_args_ansindex960;  slog::Index** evaldelta961;  slog::Index** tick_ansdelta962;  slog::Index** lambdadelta963;  slog::Index** closuredelta964;  slog::Index** evaldelta965;  slog::Index** tickdelta966;  slog::Index** evaldelta967;  slog::Index** $sup56712x41x0x0x0delta968;  slog::Index** appdelta969;  slog::Index** eval_argsdelta970;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord972({0, 1});
      slog::Relation* readrel973 = db->getRelation("eval_ans");
      head_index[0] = readrel973->getIndex(ord972, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord974({0, 2, 1});
      slog::Relation* readrel975 = db->getRelation("eval");
      evalindex943 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({0, 2, 1});
      slog::Relation* readrel977 = db->getRelation("eval");
      evaldelta961 = readrel977->getIndex(ord976, true);
      std::vector<u16> ord978({2, 0, 1});
      slog::Relation* readrel979 = db->getRelation("lambda");
      lambdaindex944 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({1, 0});
      slog::Relation* readrel981 = db->getRelation("tick_ans");
      tick_ansindex945 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 0});
      slog::Relation* readrel983 = db->getRelation("tick_ans");
      tick_ansdelta962 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({2, 0, 1});
      slog::Relation* readrel985 = db->getRelation("lambda");
      lambdaindex946 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({2, 0, 1});
      slog::Relation* readrel987 = db->getRelation("lambda");
      lambdadelta963 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({1, 2, 0});
      slog::Relation* readrel989 = db->getRelation("closure");
      closureindex947 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({1, 2, 0});
      slog::Relation* readrel991 = db->getRelation("closure");
      closuredelta964 = readrel991->getIndex(ord990, true);
      std::vector<u16> ord992({1, 0});
      slog::Relation* readrel993 = db->getRelation("eval_ans");
      eval_ansindex948 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({0, 2, 1});
      slog::Relation* readrel995 = db->getRelation("eval");
      evalindex949 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({0, 2, 1});
      slog::Relation* readrel997 = db->getRelation("eval");
      evaldelta965 = readrel997->getIndex(ord996, true);
      std::vector<u16> ord998({2, 0, 1});
      slog::Relation* readrel999 = db->getRelation("eval");
      evalindex950 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 2, 3, 0});
      slog::Relation* readrel1001 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index951 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({1, 2, 0});
      slog::Relation* readrel1003 = db->getRelation("app");
      appindex952 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({2, 0, 1});
      slog::Relation* readrel1005 = db->getRelation("eval_args");
      eval_argsindex953 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({0, 2, 1});
      slog::Relation* readrel1007 = db->getRelation("tick");
      tickindex954 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({0, 2, 1});
      slog::Relation* readrel1009 = db->getRelation("tick");
      tickdelta966 = readrel1009->getIndex(ord1008, true);
      std::vector<u16> ord1010({0, 1, 2});
      slog::Relation* readrel1011 = db->getRelation("app");
      appindex955 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 2, 0});
      slog::Relation* readrel1013 = db->getRelation("eval");
      evalindex956 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("eval");
      evaldelta967 = readrel1015->getIndex(ord1014, true);
      std::vector<u16> ord1016({1, 0, 2, 3});
      slog::Relation* readrel1017 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index957 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0, 2, 3});
      slog::Relation* readrel1019 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta968 = readrel1019->getIndex(ord1018, true);
      std::vector<u16> ord1020({0, 1, 2});
      slog::Relation* readrel1021 = db->getRelation("app");
      appindex958 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({0, 1, 2});
      slog::Relation* readrel1023 = db->getRelation("app");
      appdelta969 = readrel1023->getIndex(ord1022, true);
      std::vector<u16> ord1024({1, 2, 0});
      slog::Relation* readrel1025 = db->getRelation("eval_args");
      eval_argsindex959 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 0});
      slog::Relation* readrel1027 = db->getRelation("eval_args");
      eval_argsdelta970 = readrel1027->getIndex(ord1026, true);
      std::vector<u16> ord1028({0, 1});
      slog::Relation* readrel1029 = db->getRelation("eval_args_ans");
      eval_args_ansindex960 = readrel1029->getIndex(ord1028, false);
  
    }
    ReadTask971(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c203 = _t[0];
        u64 v_c204 = _t[1];
        slog::join_probe_old<3,1>(evalindex943, evaldelta961, std::array<u64,3>{v_c203, 0, 0}, [&](const std::array<u64,3>& m1030) {
          u64 v_c3 = m1030[1]; u64 v_c101 = m1030[2];
          if (!slog::exists_probe<3,1>(lambdaindex944, std::array<u64,3>{v_c101, 0, 0})) return;
          slog::join_probe_old<2,1>(tick_ansindex945, tick_ansdelta962, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1031) {
            u64 v_c196 = m1031[1];
            slog::join_probe_old<3,1>(lambdaindex946, lambdadelta963, std::array<u64,3>{v_c101, 0, 0}, [&](const std::array<u64,3>& m1032) {
              u64 v_c202 = m1032[1]; u64 v_c100 = m1032[2];
              slog::join_probe_old<3,1>(closureindex947, closuredelta964, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m1033) {
                u64 v_c103 = m1033[1]; u64 v_c201 = m1033[2];
                slog::join_probe<2,1>(eval_ansindex948, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1034) {
                  u64 v_c199 = m1034[1];
                  slog::join_probe_old<3,1>(evalindex949, evaldelta965, std::array<u64,3>{v_c199, 0, 0}, [&](const std::array<u64,3>& m1035) {
                    u64 v_c2 = m1035[1]; u64 v_c63 = m1035[2];
                    if (!slog::exists_probe<3,1>(evalindex950, std::array<u64,3>{v_c2, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index951, std::array<u64,4>{v_c2, v_c63, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex952, std::array<u64,3>{v_c63, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex953, std::array<u64,3>{v_c2, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex954, tickdelta966, std::array<u64,3>{v_c196, v_c2, 0}, [&](const std::array<u64,3>& m1036) {
                      u64 v_c197 = m1036[2];
                      if (!slog::exists_probe<3,2>(appindex955, std::array<u64,3>{v_c197, v_c63, 0})) return;
                      slog::join_probe_old<3,2>(evalindex956, evaldelta967, std::array<u64,3>{v_c197, v_c2, 0}, [&](const std::array<u64,3>& m1037) {
                        u64 v_c198 = m1037[2];
                        slog::join_probe_old<4,3>($sup56712x41x0x0x0index957, $sup56712x41x0x0x0delta968, std::array<u64,4>{v_c2, v_c198, v_c63, 0}, [&](const std::array<u64,4>& m1038) {
                          u64 v_c64 = m1038[3];
                          slog::join_probe_old<3,3>(appindex958, appdelta969, std::array<u64,3>{v_c197, v_c63, v_c64}, [&](const std::array<u64,3>& m1039) {
                            slog::join_probe_old<3,2>(eval_argsindex959, eval_argsdelta970, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m1040) {
                              u64 v_c200 = m1040[2];
                              slog::join_probe<2,1>(eval_args_ansindex960, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m1041) {
                                u64 v_c111 = m1041[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c204}, std::array<u16,2>{0, 1});
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
        ReadTask971* _cont = new ReadTask971(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask971(db,b), false);
  // (crule (pre) (scan app __t4e5j157 ef es) (body (join-old eval (1 2 0) 1 (1 2 0) __t4e5j157 c __t59EL158)) (head (emit $sup56712x41x0x0x0 (1 0 2 3) c __t59EL158 ef es)) interp.slog:42 #f)
  class ReadTask1044 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1042;  slog::Index** evaldelta1043;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord1045({1, 0, 2, 3});
      slog::Relation* readrel1046 = db->getRelation("$sup56712x41x0x0x0");
      head_index[0] = readrel1046->getIndex(ord1045, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1047({1, 2, 0});
      slog::Relation* readrel1048 = db->getRelation("eval");
      evalindex1042 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 2, 0});
      slog::Relation* readrel1050 = db->getRelation("eval");
      evaldelta1043 = readrel1050->getIndex(ord1049, true);
  
    }
    ReadTask1044(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c208 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        slog::join_probe_old<3,1>(evalindex1042, evaldelta1043, std::array<u64,3>{v_c208, 0, 0}, [&](const std::array<u64,3>& m1051) {
          u64 v_c2 = m1051[1]; u64 v_c207 = m1051[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c207, v_c63, v_c64}, std::array<u16,4>{1, 0, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1044* _cont = new ReadTask1044(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1044(db,b), false);
  // (crule (pre) (scan eval __64BN675 __t3Fr129 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (join-old tick_ans (0 1) 1 (0 1) __t0NvE30 l) (join-old eval (2 0 1) 1 (2 0 1) c __t84Ji24 ef) (exists eval_ans (0 1) 1 __t84Ji24) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old eval_ans (0 1) 1 (0 1) __t84Ji24 __t6CK626) (join-old eval_args_ans (0 1) 1 (0 1) __t3tQh27 vs) (join-old closure (0 1 2) 1 (0 1 2) __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t3miO28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1079 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1052;  slog::Index** eval_argsindex1053;  slog::Index** tickindex1054;  slog::Index** tick_ansindex1055;  slog::Index** evalindex1056;  slog::Index** eval_ansindex1057;  slog::Index** appindex1058;  slog::Index** eval_argsindex1059;  slog::Index** eval_args_ansindex1060;  slog::Index** eval_ansindex1061;  slog::Index** eval_args_ansindex1062;  slog::Index** closureindex1063;  slog::Index** bindingindex1064;  slog::Index** freevarindex1065;  slog::Index** bindingindex1066;  slog::Index** lambdaindex1067;  slog::Index** tickdelta1068;  slog::Index** tick_ansdelta1069;  slog::Index** evaldelta1070;  slog::Index** appdelta1071;  slog::Index** eval_argsdelta1072;  slog::Index** eval_ansdelta1073;  slog::Index** eval_args_ansdelta1074;  slog::Index** closuredelta1075;  slog::Index** freevardelta1076;  slog::Index** bindingdelta1077;  slog::Index** lambdadelta1078;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1080({0, 1, 2});
      slog::Relation* readrel1081 = db->getRelation("binding");
      head_index[0] = readrel1081->getIndex(ord1080, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1082({0, 1, 2});
      slog::Relation* readrel1083 = db->getRelation("binding_event");
      head_index[1] = readrel1083->getIndex(ord1082, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1084({2, 0, 1});
      slog::Relation* readrel1085 = db->getRelation("eval");
      evalindex1052 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({2, 0, 1});
      slog::Relation* readrel1087 = db->getRelation("eval_args");
      eval_argsindex1053 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({1, 2, 0});
      slog::Relation* readrel1089 = db->getRelation("tick");
      tickindex1054 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 2, 0});
      slog::Relation* readrel1091 = db->getRelation("tick");
      tickdelta1068 = readrel1091->getIndex(ord1090, true);
      std::vector<u16> ord1092({0, 1});
      slog::Relation* readrel1093 = db->getRelation("tick_ans");
      tick_ansindex1055 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 1});
      slog::Relation* readrel1095 = db->getRelation("tick_ans");
      tick_ansdelta1069 = readrel1095->getIndex(ord1094, true);
      std::vector<u16> ord1096({2, 0, 1});
      slog::Relation* readrel1097 = db->getRelation("eval");
      evalindex1056 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({2, 0, 1});
      slog::Relation* readrel1099 = db->getRelation("eval");
      evaldelta1070 = readrel1099->getIndex(ord1098, true);
      std::vector<u16> ord1100({0, 1});
      slog::Relation* readrel1101 = db->getRelation("eval_ans");
      eval_ansindex1057 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({0, 1, 2});
      slog::Relation* readrel1103 = db->getRelation("app");
      appindex1058 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1, 2});
      slog::Relation* readrel1105 = db->getRelation("app");
      appdelta1071 = readrel1105->getIndex(ord1104, true);
      std::vector<u16> ord1106({1, 2, 0});
      slog::Relation* readrel1107 = db->getRelation("eval_args");
      eval_argsindex1059 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 2, 0});
      slog::Relation* readrel1109 = db->getRelation("eval_args");
      eval_argsdelta1072 = readrel1109->getIndex(ord1108, true);
      std::vector<u16> ord1110({0, 1});
      slog::Relation* readrel1111 = db->getRelation("eval_args_ans");
      eval_args_ansindex1060 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({0, 1});
      slog::Relation* readrel1113 = db->getRelation("eval_ans");
      eval_ansindex1061 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({0, 1});
      slog::Relation* readrel1115 = db->getRelation("eval_ans");
      eval_ansdelta1073 = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({0, 1});
      slog::Relation* readrel1117 = db->getRelation("eval_args_ans");
      eval_args_ansindex1062 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({0, 1});
      slog::Relation* readrel1119 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1074 = readrel1119->getIndex(ord1118, true);
      std::vector<u16> ord1120({0, 1, 2});
      slog::Relation* readrel1121 = db->getRelation("closure");
      closureindex1063 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({0, 1, 2});
      slog::Relation* readrel1123 = db->getRelation("closure");
      closuredelta1075 = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({1, 0, 2});
      slog::Relation* readrel1125 = db->getRelation("binding");
      bindingindex1064 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 0});
      slog::Relation* readrel1127 = db->getRelation("freevar");
      freevarindex1065 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 0});
      slog::Relation* readrel1129 = db->getRelation("freevar");
      freevardelta1076 = readrel1129->getIndex(ord1128, true);
      std::vector<u16> ord1130({0, 1, 2});
      slog::Relation* readrel1131 = db->getRelation("binding");
      bindingindex1066 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({0, 1, 2});
      slog::Relation* readrel1133 = db->getRelation("binding");
      bindingdelta1077 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({0, 1, 2});
      slog::Relation* readrel1135 = db->getRelation("lambda");
      lambdaindex1067 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1, 2});
      slog::Relation* readrel1137 = db->getRelation("lambda");
      lambdadelta1078 = readrel1137->getIndex(ord1136, true);
  
    }
    ReadTask1079(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c107 = _t[0];
        u64 v_c108 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1052, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1053, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex1054, tickdelta1068, std::array<u64,3>{v_c108, v_c2, 0}, [&](const std::array<u64,3>& m1138) {
          u64 v_c110 = m1138[2];
          slog::join_probe_old<2,1>(tick_ansindex1055, tick_ansdelta1069, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m1139) {
            u64 v_c112 = m1139[1];
            slog::join_probe_old<3,1>(evalindex1056, evaldelta1070, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1140) {
              u64 v_c106 = m1140[1]; u64 v_c63 = m1140[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1057, std::array<u64,2>{v_c106, 0})) return;
              slog::join_probe_old<3,2>(appindex1058, appdelta1071, std::array<u64,3>{v_c108, v_c63, 0}, [&](const std::array<u64,3>& m1141) {
                u64 v_c64 = m1141[2];
                slog::join_probe_old<3,2>(eval_argsindex1059, eval_argsdelta1072, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m1142) {
                  u64 v_c109 = m1142[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1060, std::array<u64,2>{v_c109, 0})) return;
                  slog::join_probe_old<2,1>(eval_ansindex1061, eval_ansdelta1073, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m1143) {
                    u64 v_c105 = m1143[1];
                    slog::join_probe_old<2,1>(eval_args_ansindex1062, eval_args_ansdelta1074, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m1144) {
                      u64 v_c111 = m1144[1];
                      slog::join_probe_old<3,1>(closureindex1063, closuredelta1075, std::array<u64,3>{v_c105, 0, 0}, [&](const std::array<u64,3>& m1145) {
                        u64 v_c99 = m1145[1]; u64 v_c103 = m1145[2];
                        if (!slog::exists_probe<3,1>(bindingindex1064, std::array<u64,3>{v_c103, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex1065, freevardelta1076, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1146) {
                          u64 v_c102 = m1146[1];
                          slog::join_probe_old<3,2>(bindingindex1066, bindingdelta1077, std::array<u64,3>{v_c102, v_c103, 0}, [&](const std::array<u64,3>& m1147) {
                            u64 v_c104 = m1147[2];
                            slog::join_probe_old<3,1>(lambdaindex1067, lambdadelta1078, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m1148) {
                              u64 v_c100 = m1148[1]; u64 v_c101 = m1148[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c102, v_c112, v_c104}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c102, v_c112, v_c2}, std::array<u16,3>{0, 1, 2});
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
        ReadTask1079* _cont = new ReadTask1079(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1079(db,b), false);
  // (crule (pre) (scan freevar y __t3miO28) (body (exists closure (1 2 0) 1 __t3miO28) (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old closure (1 2 0) 2 (1 2 0) __t3miO28 cb __t6CK626) (join eval_ans (1 0) 1 __t6CK626 __t84Ji24) (join-old eval (0 2 1) 1 (0 2 1) __t84Ji24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0NvE30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1149;  slog::Index** bindingindex1150;  slog::Index** closureindex1151;  slog::Index** eval_ansindex1152;  slog::Index** evalindex1153;  slog::Index** appindex1154;  slog::Index** eval_argsindex1155;  slog::Index** tickindex1156;  slog::Index** evalindex1157;  slog::Index** tickindex1158;  slog::Index** appindex1159;  slog::Index** eval_argsindex1160;  slog::Index** eval_args_ansindex1161;  slog::Index** tickindex1162;  slog::Index** tick_ansindex1163;  slog::Index** eval_args_ansindex1164;  slog::Index** tick_ansindex1165;  slog::Index** lambdaindex1166;  slog::Index** bindingdelta1167;  slog::Index** closuredelta1168;  slog::Index** evaldelta1169;  slog::Index** appdelta1170;  slog::Index** eval_argsdelta1171;  slog::Index** tickdelta1172;  slog::Index** tick_ansdelta1173;  slog::Index** lambdadelta1174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1176({0, 1, 2});
      slog::Relation* readrel1177 = db->getRelation("binding");
      head_index[0] = readrel1177->getIndex(ord1176, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1178({0, 1, 2});
      slog::Relation* readrel1179 = db->getRelation("binding_event");
      head_index[1] = readrel1179->getIndex(ord1178, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1180({1, 2, 0});
      slog::Relation* readrel1181 = db->getRelation("closure");
      closureindex1149 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({0, 1, 2});
      slog::Relation* readrel1183 = db->getRelation("binding");
      bindingindex1150 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({0, 1, 2});
      slog::Relation* readrel1185 = db->getRelation("binding");
      bindingdelta1167 = readrel1185->getIndex(ord1184, true);
      std::vector<u16> ord1186({1, 2, 0});
      slog::Relation* readrel1187 = db->getRelation("closure");
      closureindex1151 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 2, 0});
      slog::Relation* readrel1189 = db->getRelation("closure");
      closuredelta1168 = readrel1189->getIndex(ord1188, true);
      std::vector<u16> ord1190({1, 0});
      slog::Relation* readrel1191 = db->getRelation("eval_ans");
      eval_ansindex1152 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({0, 2, 1});
      slog::Relation* readrel1193 = db->getRelation("eval");
      evalindex1153 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({0, 2, 1});
      slog::Relation* readrel1195 = db->getRelation("eval");
      evaldelta1169 = readrel1195->getIndex(ord1194, true);
      std::vector<u16> ord1196({1, 2, 0});
      slog::Relation* readrel1197 = db->getRelation("app");
      appindex1154 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({2, 0, 1});
      slog::Relation* readrel1199 = db->getRelation("eval_args");
      eval_argsindex1155 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({2, 0, 1});
      slog::Relation* readrel1201 = db->getRelation("tick");
      tickindex1156 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({2, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("eval");
      evalindex1157 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 2, 0});
      slog::Relation* readrel1205 = db->getRelation("tick");
      tickindex1158 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({0, 1, 2});
      slog::Relation* readrel1207 = db->getRelation("app");
      appindex1159 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({0, 1, 2});
      slog::Relation* readrel1209 = db->getRelation("app");
      appdelta1170 = readrel1209->getIndex(ord1208, true);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("eval_args");
      eval_argsindex1160 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0});
      slog::Relation* readrel1213 = db->getRelation("eval_args");
      eval_argsdelta1171 = readrel1213->getIndex(ord1212, true);
      std::vector<u16> ord1214({0, 1});
      slog::Relation* readrel1215 = db->getRelation("eval_args_ans");
      eval_args_ansindex1161 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 2, 0});
      slog::Relation* readrel1217 = db->getRelation("tick");
      tickindex1162 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 2, 0});
      slog::Relation* readrel1219 = db->getRelation("tick");
      tickdelta1172 = readrel1219->getIndex(ord1218, true);
      std::vector<u16> ord1220({0, 1});
      slog::Relation* readrel1221 = db->getRelation("tick_ans");
      tick_ansindex1163 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({0, 1});
      slog::Relation* readrel1223 = db->getRelation("eval_args_ans");
      eval_args_ansindex1164 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({0, 1});
      slog::Relation* readrel1225 = db->getRelation("tick_ans");
      tick_ansindex1165 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({0, 1});
      slog::Relation* readrel1227 = db->getRelation("tick_ans");
      tick_ansdelta1173 = readrel1227->getIndex(ord1226, true);
      std::vector<u16> ord1228({0, 1, 2});
      slog::Relation* readrel1229 = db->getRelation("lambda");
      lambdaindex1166 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 1, 2});
      slog::Relation* readrel1231 = db->getRelation("lambda");
      lambdadelta1174 = readrel1231->getIndex(ord1230, true);
  
    }
    ReadTask1175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[0];
        u64 v_c99 = _t[1];
        if (!slog::exists_probe<3,1>(closureindex1149, std::array<u64,3>{v_c99, 0, 0})) return;
        slog::join_probe_old<3,1>(bindingindex1150, bindingdelta1167, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m1232) {
          u64 v_c103 = m1232[1]; u64 v_c104 = m1232[2];
          slog::join_probe_old<3,2>(closureindex1151, closuredelta1168, std::array<u64,3>{v_c99, v_c103, 0}, [&](const std::array<u64,3>& m1233) {
            u64 v_c105 = m1233[2];
            slog::join_probe<2,1>(eval_ansindex1152, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m1234) {
              u64 v_c106 = m1234[1];
              slog::join_probe_old<3,1>(evalindex1153, evaldelta1169, std::array<u64,3>{v_c106, 0, 0}, [&](const std::array<u64,3>& m1235) {
                u64 v_c2 = m1235[1]; u64 v_c63 = m1235[2];
                if (!slog::exists_probe<3,1>(appindex1154, std::array<u64,3>{v_c63, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex1155, std::array<u64,3>{v_c2, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex1156, std::array<u64,3>{v_c2, 0, 0})) return;
                slog::join_probe<3,1>(evalindex1157, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1236) {
                  u64 v_c107 = m1236[1]; u64 v_c108 = m1236[2];
                  if (!slog::exists_probe<3,2>(tickindex1158, std::array<u64,3>{v_c108, v_c2, 0})) return;
                  slog::join_probe_old<3,2>(appindex1159, appdelta1170, std::array<u64,3>{v_c108, v_c63, 0}, [&](const std::array<u64,3>& m1237) {
                    u64 v_c64 = m1237[2];
                    slog::join_probe_old<3,2>(eval_argsindex1160, eval_argsdelta1171, std::array<u64,3>{v_c64, v_c2, 0}, [&](const std::array<u64,3>& m1238) {
                      u64 v_c109 = m1238[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex1161, std::array<u64,2>{v_c109, 0})) return;
                      slog::join_probe_old<3,2>(tickindex1162, tickdelta1172, std::array<u64,3>{v_c108, v_c2, 0}, [&](const std::array<u64,3>& m1239) {
                        u64 v_c110 = m1239[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex1163, std::array<u64,2>{v_c110, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex1164, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m1240) {
                          u64 v_c111 = m1240[1];
                          slog::join_probe_old<2,1>(tick_ansindex1165, tick_ansdelta1173, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m1241) {
                            u64 v_c112 = m1241[1];
                            slog::join_probe_old<3,1>(lambdaindex1166, lambdadelta1174, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m1242) {
                              u64 v_c100 = m1242[1]; u64 v_c101 = m1242[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c102, v_c112, v_c104}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c102, v_c112, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1175* _cont = new ReadTask1175(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1175(db,b), false);
  // (crule (pre) (scan eval __t7j91374 er c) (body (exists let (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t7j91374) (join $sup56712x91x0x0x0 (1 3 0 2 4) 2 c er __t9U3N373 eb x) (exists eval (0 2 1) 2 __t9U3N373 c) (exists eval (1 2 0) 2 eb c) (join let (2 1 3 0) 3 er x eb __t78XS372) (join eval (0 2 1) 3 __t9U3N373 c __t78XS372) (join-old eval (1 2 0) 2 (1 2 0) eb c __t3KJV375) (exists eval_ans (0 1) 1 __t3KJV375) (join eval_ans (0 1) 1 __t7j91374 vr) (join eval_ans (0 1) 1 __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask1256 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1243;  slog::Index** evalindex1244;  slog::Index** eval_ansindex1245;  slog::Index** $sup56712x91x0x0x0index1246;  slog::Index** evalindex1247;  slog::Index** evalindex1248;  slog::Index** letindex1249;  slog::Index** evalindex1250;  slog::Index** evalindex1251;  slog::Index** eval_ansindex1252;  slog::Index** eval_ansindex1253;  slog::Index** eval_ansindex1254;  slog::Index** evaldelta1255;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1257({0, 1});
      slog::Relation* readrel1258 = db->getRelation("eval_ans");
      head_index[0] = readrel1258->getIndex(ord1257, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1259({2, 1, 3, 0});
      slog::Relation* readrel1260 = db->getRelation("let");
      letindex1243 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({2, 0, 1});
      slog::Relation* readrel1262 = db->getRelation("eval");
      evalindex1244 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({0, 1});
      slog::Relation* readrel1264 = db->getRelation("eval_ans");
      eval_ansindex1245 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 3, 0, 2, 4});
      slog::Relation* readrel1266 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index1246 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({0, 2, 1});
      slog::Relation* readrel1268 = db->getRelation("eval");
      evalindex1247 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({1, 2, 0});
      slog::Relation* readrel1270 = db->getRelation("eval");
      evalindex1248 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({2, 1, 3, 0});
      slog::Relation* readrel1272 = db->getRelation("let");
      letindex1249 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({0, 2, 1});
      slog::Relation* readrel1274 = db->getRelation("eval");
      evalindex1250 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({1, 2, 0});
      slog::Relation* readrel1276 = db->getRelation("eval");
      evalindex1251 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 2, 0});
      slog::Relation* readrel1278 = db->getRelation("eval");
      evaldelta1255 = readrel1278->getIndex(ord1277, true);
      std::vector<u16> ord1279({0, 1});
      slog::Relation* readrel1280 = db->getRelation("eval_ans");
      eval_ansindex1252 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({0, 1});
      slog::Relation* readrel1282 = db->getRelation("eval_ans");
      eval_ansindex1253 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({0, 1});
      slog::Relation* readrel1284 = db->getRelation("eval_ans");
      eval_ansindex1254 = readrel1284->getIndex(ord1283, false);
  
    }
    ReadTask1256(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c225 = _t[0];
        u64 v_c162 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>(letindex1243, std::array<u64,4>{v_c162, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1244, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1245, std::array<u64,2>{v_c225, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index1246, std::array<u64,5>{v_c2, v_c162, 0, 0, 0}, [&](const std::array<u64,5>& m1285) {
          u64 v_c226 = m1285[2]; u64 v_c101 = m1285[3]; u64 v_c1 = m1285[4];
          if (!slog::exists_probe<3,2>(evalindex1247, std::array<u64,3>{v_c226, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex1248, std::array<u64,3>{v_c101, v_c2, 0})) return;
          slog::join_probe<4,3>(letindex1249, std::array<u64,4>{v_c162, v_c1, v_c101, 0}, [&](const std::array<u64,4>& m1286) {
            u64 v_c227 = m1286[3];
            slog::join_probe<3,3>(evalindex1250, std::array<u64,3>{v_c226, v_c2, v_c227}, [&](const std::array<u64,3>& m1287) {
              slog::join_probe_old<3,2>(evalindex1251, evaldelta1255, std::array<u64,3>{v_c101, v_c2, 0}, [&](const std::array<u64,3>& m1288) {
                u64 v_c228 = m1288[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1252, std::array<u64,2>{v_c228, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1253, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m1289) {
                  u64 v_c165 = m1289[1];
                  slog::join_probe<2,1>(eval_ansindex1254, std::array<u64,2>{v_c228, 0}, [&](const std::array<u64,2>& m1290) {
                    u64 v_c204 = m1290[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c226, v_c204}, std::array<u16,2>{0, 1});
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
        ReadTask1256* _cont = new ReadTask1256(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1256(db,b), false);
  // (crule (pre (let __tconst62Eu697 constb9e118781cea1f9fa01462e0)) (probe _enum (1 0) 1 __tconst62Eu697 __t7z6n355) (body) (head (mkstruct boolval (1 0) __t9OVd356 __t7z6n355)) interp.slog:81 #f)
  class ReadTask1291 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("boolval");
      std::vector<u16> ord1292({1, 0});
      slog::Relation* readrel1293 = db->getRelation("_enum");
      driver_index = readrel1293->getIndex(ord1292, true);
  
    }
    ReadTask1291(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c229 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c229, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1294) {
        u64 v_c230 = m1294[1];
        if (buckethash(v_c230) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c230}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask1291* _cont = new ReadTask1291(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1291(db,b), true);
  // (crule (pre) (scan eval __t9U3N373 __t78XS372 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x91x0x0x0 (0 1 2 3 4) 2 __t9U3N373 c eb er x) (join let (2 1 3 0) 4 er x eb __t78XS372) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t7j91374) (exists eval_ans (0 1) 1 __t7j91374) (join-old eval (1 2 0) 2 (1 2 0) eb c __t3KJV375) (exists eval_ans (0 1) 1 __t3KJV375) (join eval_ans (0 1) 1 __t7j91374 vr) (join eval_ans (0 1) 1 __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask1307 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1295;  slog::Index** $sup56712x91x0x0x0index1296;  slog::Index** letindex1297;  slog::Index** evalindex1298;  slog::Index** evalindex1299;  slog::Index** eval_ansindex1300;  slog::Index** evalindex1301;  slog::Index** eval_ansindex1302;  slog::Index** eval_ansindex1303;  slog::Index** eval_ansindex1304;  slog::Index** evaldelta1305;  slog::Index** evaldelta1306;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1308({0, 1});
      slog::Relation* readrel1309 = db->getRelation("eval_ans");
      head_index[0] = readrel1309->getIndex(ord1308, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1310({2, 0, 1});
      slog::Relation* readrel1311 = db->getRelation("eval");
      evalindex1295 = readrel1311->getIndex(ord1310, false);
      std::vector<u16> ord1312({0, 1, 2, 3, 4});
      slog::Relation* readrel1313 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index1296 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({2, 1, 3, 0});
      slog::Relation* readrel1315 = db->getRelation("let");
      letindex1297 = readrel1315->getIndex(ord1314, false);
      std::vector<u16> ord1316({1, 2, 0});
      slog::Relation* readrel1317 = db->getRelation("eval");
      evalindex1298 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({1, 2, 0});
      slog::Relation* readrel1319 = db->getRelation("eval");
      evalindex1299 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 2, 0});
      slog::Relation* readrel1321 = db->getRelation("eval");
      evaldelta1305 = readrel1321->getIndex(ord1320, true);
      std::vector<u16> ord1322({0, 1});
      slog::Relation* readrel1323 = db->getRelation("eval_ans");
      eval_ansindex1300 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 2, 0});
      slog::Relation* readrel1325 = db->getRelation("eval");
      evalindex1301 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({1, 2, 0});
      slog::Relation* readrel1327 = db->getRelation("eval");
      evaldelta1306 = readrel1327->getIndex(ord1326, true);
      std::vector<u16> ord1328({0, 1});
      slog::Relation* readrel1329 = db->getRelation("eval_ans");
      eval_ansindex1302 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({0, 1});
      slog::Relation* readrel1331 = db->getRelation("eval_ans");
      eval_ansindex1303 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({0, 1});
      slog::Relation* readrel1333 = db->getRelation("eval_ans");
      eval_ansindex1304 = readrel1333->getIndex(ord1332, false);
  
    }
    ReadTask1307(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c227 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1295, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index1296, std::array<u64,5>{v_c226, v_c2, 0, 0, 0}, [&](const std::array<u64,5>& m1334) {
          u64 v_c101 = m1334[2]; u64 v_c162 = m1334[3]; u64 v_c1 = m1334[4];
          slog::join_probe<4,4>(letindex1297, std::array<u64,4>{v_c162, v_c1, v_c101, v_c227}, [&](const std::array<u64,4>& m1335) {
            if (!slog::exists_probe<3,2>(evalindex1298, std::array<u64,3>{v_c101, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex1299, evaldelta1305, std::array<u64,3>{v_c162, v_c2, 0}, [&](const std::array<u64,3>& m1336) {
              u64 v_c225 = m1336[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1300, std::array<u64,2>{v_c225, 0})) return;
              slog::join_probe_old<3,2>(evalindex1301, evaldelta1306, std::array<u64,3>{v_c101, v_c2, 0}, [&](const std::array<u64,3>& m1337) {
                u64 v_c228 = m1337[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1302, std::array<u64,2>{v_c228, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1303, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m1338) {
                  u64 v_c165 = m1338[1];
                  slog::join_probe<2,1>(eval_ansindex1304, std::array<u64,2>{v_c228, 0}, [&](const std::array<u64,2>& m1339) {
                    u64 v_c204 = m1339[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c226, v_c204}, std::array<u16,2>{0, 1});
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
        ReadTask1307* _cont = new ReadTask1307(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1307(db,b), false);
  // (crule (pre) (scan nan_result __erre90cM824 __errf8rst825 __errf4gif826 __errf3Wo6827) (body) (head (emit error (0) __erre90cM824)) <internal>:1 #f)
  class ReadTask1340 : public slog::Task
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
      std::vector<u16> ord1341({0});
      slog::Relation* readrel1342 = db->getRelation("error");
      head_index[0] = readrel1342->getIndex(ord1341, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask1340(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c231 = _t[0];
        u64 v_c232 = _t[1];
        u64 v_c233 = _t[2];
        u64 v_c234 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c231}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask1340* _cont = new ReadTask1340(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1340(db,b), false);
  // (crule (pre (let __tconst7saS665 constb9e118781cea1f9fa01462e0) (let __tconst4R6j353 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9CpF541 const6b86b273ff34fce19d6b804e) (let _00024sqc8vSl542 const5feceb66ffc86f38d952786c) (let _00024sqo1EFx543 const5feceb66ffc86f38d952786c) (let _00024sqo1k6Q544 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst4R6j353 _00024seq0 __t1geM354) (body (letp _00024sql7fhi539 (aslst _00024seq0)) (letp v (lref _00024sql7fhi539 _00024sqc8vSl542)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1EFx543 v _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1k6Q544 v _00024seq0) (join _enum (1 0) 1 __tconst7saS665 __t73g6351) (join scheme_false (0) 0 fv) (neq v fv) (let chk36Vw1036 (llen _00024sql7fhi539)) (eq _00024sqc9CpF541 chk36Vw1036)) (head (emit-temp temp9mFJ1033 __t1geM354) (mkstruct boolval (1 0) __t1MPL352 __t73g6351)) interp.slog:114 #f)
  class ReadTask1349 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1343;  slog::Index** $seq_atrindex1344;  slog::Index** _enumindex1345;  slog::Index** scheme_falseindex1346;  slog::Index** $seq_atdelta1347;  slog::Index** $seq_atrdelta1348;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mFJ1033");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1350({1, 2, 0});
      slog::Relation* readrel1351 = db->getRelation("delta");
      driver_index = readrel1351->getIndex(ord1350, true);
      std::vector<u16> ord1352({1, 0, 2});
      slog::Relation* readrel1353 = db->getRelation("$seq_at");
      $seq_atindex1343 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 0, 2});
      slog::Relation* readrel1355 = db->getRelation("$seq_at");
      $seq_atdelta1347 = readrel1355->getIndex(ord1354, true);
      std::vector<u16> ord1356({1, 0, 2});
      slog::Relation* readrel1357 = db->getRelation("$seq_atr");
      $seq_atrindex1344 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({1, 0, 2});
      slog::Relation* readrel1359 = db->getRelation("$seq_atr");
      $seq_atrdelta1348 = readrel1359->getIndex(ord1358, true);
      std::vector<u16> ord1360({1, 0});
      slog::Relation* readrel1361 = db->getRelation("_enum");
      _enumindex1345 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({0});
      slog::Relation* readrel1363 = db->getRelation("scheme_false");
      scheme_falseindex1346 = readrel1363->getIndex(ord1362, false);
  
    }
    ReadTask1349(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c235 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c236 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c237 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c238 = v_const5feceb66ffc86f38d952786c;
      u64 v_c239 = v_const5feceb66ffc86f38d952786c;
      u64 v_c240 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c236, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1364) {
        u64 v_c83 = m1364[1];
        u64 v_c241 = m1364[2];
        if (buckethash(v_c83) != bucket) return;
        bool ok1365 = true;
        u64 v_c242 = _prim_aslst(db, v_c83, &ok1365);
        if (!ok1365) return;
        bool ok1366 = true;
        u64 v_c204 = _prim_lref(db, v_c242, v_c238, &ok1366);
        if (!ok1366) return;
        slog::join_probe_old<3,3>($seq_atindex1343, $seq_atdelta1347, std::array<u64,3>{v_c239, v_c204, v_c83}, [&](const std::array<u64,3>& m1367) {
          slog::join_probe_old<3,3>($seq_atrindex1344, $seq_atrdelta1348, std::array<u64,3>{v_c240, v_c204, v_c83}, [&](const std::array<u64,3>& m1368) {
            slog::join_probe<2,1>(_enumindex1345, std::array<u64,2>{v_c235, 0}, [&](const std::array<u64,2>& m1369) {
              u64 v_c243 = m1369[1];
              slog::join_all<1>(scheme_falseindex1346, [&](const std::array<u64,1>& m1370) {
                u64 v_c244 = m1370[0];
                if (v_c204 == v_c244) return;
                u64 v_c245 = _prim_llen(db, v_c242);
                if (v_c245 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c237 != v_c245) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c241});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c243}, std::array<u16,2>{1, 0});
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
        ReadTask1349* _cont = new ReadTask1349(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1349(db,b), false);
  // (crule (pre (let __tconst4znW669 constcd2a69ce5ca278db1d6da969) (let _00024sqc3H5i520 constd4735e3a265e16eee03f5971) (let _00024sqc4tob521 const5feceb66ffc86f38d952786c) (let _00024sqc5Dhg522 const6b86b273ff34fce19d6b804e) (let _00024sqo4wSo523 const5feceb66ffc86f38d952786c) (let _00024sqo3X5o524 const6b86b273ff34fce19d6b804e) (let _00024sqo10Lc525 const6b86b273ff34fce19d6b804e) (let _00024sqo1tMi526 const5feceb66ffc86f38d952786c) (let __trid6dum670 consteefaed435882b14b69e99d78) (let __trel5mCG671 constdede4476644eb06b5a48b866) (let __tcol9ZQn672 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo10Lc525 __t5cN641 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4wSo523 __t5cN641 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3X5o524 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1tMi526 __t5cN641 _00024seq2) (join _enum (0 1) 2 __t5cN641 __tconst4znW669) (join delta (2 0 1) 1 _00024seq2 __t2MSw39 op) (join arithmetic_op (0) 1 op) (letp _00024sql8wbR518 (aslst _00024seq2)) (let chk269N906 (llen _00024sql8wbR518)) (eq _00024sqc3H5i520 chk269N906) (letp chk48WN907 (lref _00024sql8wbR518 _00024sqc4tob521)) (eq __t5cN641 chk48WN907) (letp chk8e7l908 (lref _00024sql8wbR518 _00024sqc5Dhg522)) (eq __t5cN641 chk8e7l908)) (head (tycheck __t5cN641 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid6dum670 __trel5mCG671 __tcol9ZQn672 (1 2 3 4 0)) (emit delta_ans (0 1) __t2MSw39 __t5cN641)) interp.slog:111 #f)
  class ReadTask1383 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1371;  slog::Index** $seq_atindex1372;  slog::Index** $seq_atrindex1373;  slog::Index** _enumindex1374;  slog::Index** deltaindex1375;  slog::Index** arithmetic_opindex1376;  slog::Index** $seq_atrdelta1377;
    u32 sid1380;  u32 sid1378;  u32 sid1379;  u32 sid1381;  u32 sid1382;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1384({0, 1});
      slog::Relation* readrel1385 = db->getRelation("delta_ans");
      head_index[1] = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({1, 0, 2});
      slog::Relation* readrel1387 = db->getRelation("$seq_atr");
      driver_index = readrel1387->getIndex(ord1386, true);
      std::vector<u16> ord1388({1, 0, 2});
      slog::Relation* readrel1389 = db->getRelation("$seq_at");
      $seq_atindex1371 = readrel1389->getIndex(ord1388, false);
      std::vector<u16> ord1390({1, 0, 2});
      slog::Relation* readrel1391 = db->getRelation("$seq_at");
      $seq_atindex1372 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({1, 0, 2});
      slog::Relation* readrel1393 = db->getRelation("$seq_atr");
      $seq_atrindex1373 = readrel1393->getIndex(ord1392, false);
      std::vector<u16> ord1394({1, 0, 2});
      slog::Relation* readrel1395 = db->getRelation("$seq_atr");
      $seq_atrdelta1377 = readrel1395->getIndex(ord1394, true);
      std::vector<u16> ord1396({0, 1});
      slog::Relation* readrel1397 = db->getRelation("_enum");
      _enumindex1374 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({2, 0, 1});
      slog::Relation* readrel1399 = db->getRelation("delta");
      deltaindex1375 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({0});
      slog::Relation* readrel1401 = db->getRelation("arithmetic_op");
      arithmetic_opindex1376 = readrel1401->getIndex(ord1400, false);
      sid1380 = db->getRelation("_enum")->getStructId();
      sid1378 = db->getRelation("boolval")->getStructId();
      sid1379 = db->getRelation("closure")->getStructId();
      sid1381 = db->getRelation("prim")->getStructId();
      sid1382 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1383(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c13 = v_constd4735e3a265e16eee03f5971;
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c16 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_consteefaed435882b14b69e99d78;
      u64 v_c21 = v_constdede4476644eb06b5a48b866;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c18, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1402) {
        u64 v_c27 = m1402[1];
        u64 v_c25 = m1402[2];
        if (buckethash(v_c27) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1371, std::array<u64,3>{v_c16, v_c27, v_c25}, [&](const std::array<u64,3>& m1403) {
          slog::join_probe<3,3>($seq_atindex1372, std::array<u64,3>{v_c17, v_c27, v_c25}, [&](const std::array<u64,3>& m1404) {
            slog::join_probe_old<3,3>($seq_atrindex1373, $seq_atrdelta1377, std::array<u64,3>{v_c19, v_c27, v_c25}, [&](const std::array<u64,3>& m1405) {
              slog::join_probe<2,2>(_enumindex1374, std::array<u64,2>{v_c27, v_c12}, [&](const std::array<u64,2>& m1406) {
                slog::join_probe<3,1>(deltaindex1375, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m1407) {
                  u64 v_c23 = m1407[1]; u64 v_c24 = m1407[2];
                  slog::join_probe<1,1>(arithmetic_opindex1376, std::array<u64,1>{v_c24}, [&](const std::array<u64,1>& m1408) {
                    bool ok1409 = true;
                    u64 v_c26 = _prim_aslst(db, v_c25, &ok1409);
                    if (!ok1409) return;
                    u64 v_c246 = _prim_llen(db, v_c26);
                    if (v_c246 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c13 != v_c246) return;
                    bool ok1410 = true;
                    u64 v_c247 = _prim_lref(db, v_c26, v_c14, &ok1410);
                    if (!ok1410) return;
                    if (v_c27 != v_c247) return;
                    bool ok1411 = true;
                    u64 v_c248 = _prim_lref(db, v_c26, v_c15, &ok1411);
                    if (!ok1411) return;
                    if (v_c27 != v_c248) return;
                    ++_fires;
                    if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid1378 || decode_struct_id(v_c27) == sid1379 || decode_struct_id(v_c27) == sid1380 || decode_struct_id(v_c27) == sid1381 || decode_struct_id(v_c27) == sid1382))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c20, v_c21, v_c22, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1383* _cont = new ReadTask1383(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1383(db,b), false);
  // (crule (pre) (scan temp8OpH912 __t9sdv143 b) (body (join boolval (1 0) 1 b __t9Ain141)) (head (emit delta_ans (0 1) __t9sdv143 __t9Ain141)) interp.slog:122 #f)
  class ReadTask1413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex1412;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1414({0, 1});
      slog::Relation* readrel1415 = db->getRelation("delta_ans");
      head_index[0] = readrel1415->getIndex(ord1414, false);
      outer_rel = db->getRelation("temp8OpH912");
      std::vector<u16> ord1416({1, 0});
      slog::Relation* readrel1417 = db->getRelation("boolval");
      boolvalindex1412 = readrel1417->getIndex(ord1416, false);
  
    }
    ReadTask1413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[1];
        slog::join_probe<2,1>(boolvalindex1412, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m1418) {
          u64 v_c249 = m1418[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c180, v_c249}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:temp8OpH912", _fires);
  
      if (!_done)
      {
        ReadTask1413* _cont = new ReadTask1413(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1413(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo7aST449 __t4Puk145 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1C1f450 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Q0D451 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7GLE452 __t4Puk145 _00024seq2) (join delta (1 2 0) 2 __tconst9XQ5142 _00024seq2 __t9sdv143) (join closure (0 1 2) 1 __t4Puk145 lm cb) (join any_bool (0) 0 b) (letp _00024sql8vYG444 (aslst _00024seq2)) (let chk5L4Y918 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk5L4Y918) (letp chk897P919 (lref _00024sql8vYG444 _00024sqc5yoB447)) (eq __t4Puk145 chk897P919) (letp chk4kmG920 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk4kmG920)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask1428 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1419;  slog::Index** $seq_atrindex1420;  slog::Index** $seq_atrindex1421;  slog::Index** deltaindex1422;  slog::Index** closureindex1423;  slog::Index** any_boolindex1424;  slog::Index** $seq_atdelta1425;  slog::Index** $seq_atrdelta1426;  slog::Index** $seq_atrdelta1427;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1429({1, 0, 2});
      slog::Relation* readrel1430 = db->getRelation("$seq_at");
      driver_index = readrel1430->getIndex(ord1429, true);
      std::vector<u16> ord1431({1, 0, 2});
      slog::Relation* readrel1432 = db->getRelation("$seq_at");
      $seq_atindex1419 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({1, 0, 2});
      slog::Relation* readrel1434 = db->getRelation("$seq_at");
      $seq_atdelta1425 = readrel1434->getIndex(ord1433, true);
      std::vector<u16> ord1435({1, 0, 2});
      slog::Relation* readrel1436 = db->getRelation("$seq_atr");
      $seq_atrindex1420 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 0, 2});
      slog::Relation* readrel1438 = db->getRelation("$seq_atr");
      $seq_atrdelta1426 = readrel1438->getIndex(ord1437, true);
      std::vector<u16> ord1439({1, 0, 2});
      slog::Relation* readrel1440 = db->getRelation("$seq_atr");
      $seq_atrindex1421 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 0, 2});
      slog::Relation* readrel1442 = db->getRelation("$seq_atr");
      $seq_atrdelta1427 = readrel1442->getIndex(ord1441, true);
      std::vector<u16> ord1443({1, 2, 0});
      slog::Relation* readrel1444 = db->getRelation("delta");
      deltaindex1422 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({0, 1, 2});
      slog::Relation* readrel1446 = db->getRelation("closure");
      closureindex1423 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({0});
      slog::Relation* readrel1448 = db->getRelation("any_bool");
      any_boolindex1424 = readrel1448->getIndex(ord1447, false);
  
    }
    ReadTask1428(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c171 = v_const06abaa100ecef791ce028c56;
      u64 v_c172 = v_constd4735e3a265e16eee03f5971;
      u64 v_c173 = v_const5feceb66ffc86f38d952786c;
      u64 v_c174 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
      u64 v_c176 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c177 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c175, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1449) {
        u64 v_c179 = m1449[1];
        u64 v_c25 = m1449[2];
        if (buckethash(v_c179) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1419, $seq_atdelta1425, std::array<u64,3>{v_c176, v_c179, v_c25}, [&](const std::array<u64,3>& m1450) {
          slog::join_probe_old<3,3>($seq_atrindex1420, $seq_atrdelta1426, std::array<u64,3>{v_c177, v_c179, v_c25}, [&](const std::array<u64,3>& m1451) {
            slog::join_probe_old<3,3>($seq_atrindex1421, $seq_atrdelta1427, std::array<u64,3>{v_c178, v_c179, v_c25}, [&](const std::array<u64,3>& m1452) {
              slog::join_probe<3,2>(deltaindex1422, std::array<u64,3>{v_c171, v_c25, 0}, [&](const std::array<u64,3>& m1453) {
                u64 v_c180 = m1453[2];
                slog::join_probe<3,1>(closureindex1423, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m1454) {
                  u64 v_c181 = m1454[1]; u64 v_c103 = m1454[2];
                  slog::join_all<1>(any_boolindex1424, [&](const std::array<u64,1>& m1455) {
                    u64 v_c76 = m1455[0];
                    bool ok1456 = true;
                    u64 v_c182 = _prim_aslst(db, v_c25, &ok1456);
                    if (!ok1456) return;
                    u64 v_c250 = _prim_llen(db, v_c182);
                    if (v_c250 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c172 != v_c250) return;
                    bool ok1457 = true;
                    u64 v_c251 = _prim_lref(db, v_c182, v_c173, &ok1457);
                    if (!ok1457) return;
                    if (v_c179 != v_c251) return;
                    bool ok1458 = true;
                    u64 v_c252 = _prim_lref(db, v_c182, v_c174, &ok1458);
                    if (!ok1458) return;
                    if (v_c179 != v_c252) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c180, v_c76});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c76}, std::array<u16,2>{1, 0});
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
        ReadTask1428* _cont = new ReadTask1428(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1428(db,b), false);
  // (crule (pre) (scan app __t9RJc318 ef es) (body (join eval (1 2 0) 1 __t9RJc318 c __5oJJ605)) (head (mkstruct eval (1 2 0) __8Fdd606 ef c)) interp.slog:48 #f)
  class ReadTask1460 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1459;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1461({1, 2, 0});
      slog::Relation* readrel1462 = db->getRelation("eval");
      evalindex1459 = readrel1462->getIndex(ord1461, false);
  
    }
    ReadTask1460(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c216 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        slog::join_probe<3,1>(evalindex1459, std::array<u64,3>{v_c216, 0, 0}, [&](const std::array<u64,3>& m1463) {
          u64 v_c2 = m1463[1]; u64 v_c215 = m1463[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1460* _cont = new ReadTask1460(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1460(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp2CFC1002 __t5Wmv107 __t7KRi101 __t8dvA109 __t8wZP82 __t9Kbk85) (body (exists num (1 0) 1 __tconst2U2F71) (exists ref (1 0) 1 __tconst2uSL111) (exists ref (1 0) 1 __tconst0xiC106) (exists app (2 0 1) 1 __t7KRi101) (join lambda (1 2 0) 2 __t9Kbk85 __t8wZP82 __t2Jp186) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join ref (1 0) 1 __tconst0xiC106 __t2Kfn98) (join app (1 2 0) 2 __t2Kfn98 __t7KRi101 __t223e104) (let __t4GbJ88 (lpush __t5Wmv107 __t2Jp186))) (head (emit-temp temp3h2w1003 __t223e104 __t4GbJ88 __t8dvA109) (mkstruct lambda (1 2 0) __t0Gv1110 __t8dvA109 __t223e104)) analysis-demo.slog:11 #f)
  class ReadTask1473 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1464;  slog::Index** refindex1465;  slog::Index** refindex1466;  slog::Index** appindex1467;  slog::Index** lambdaindex1468;  slog::Index** numindex1469;  slog::Index** refindex1470;  slog::Index** refindex1471;  slog::Index** appindex1472;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3h2w1003");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp2CFC1002");
      std::vector<u16> ord1474({1, 0});
      slog::Relation* readrel1475 = db->getRelation("num");
      numindex1464 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({1, 0});
      slog::Relation* readrel1477 = db->getRelation("ref");
      refindex1465 = readrel1477->getIndex(ord1476, false);
      std::vector<u16> ord1478({1, 0});
      slog::Relation* readrel1479 = db->getRelation("ref");
      refindex1466 = readrel1479->getIndex(ord1478, false);
      std::vector<u16> ord1480({2, 0, 1});
      slog::Relation* readrel1481 = db->getRelation("app");
      appindex1467 = readrel1481->getIndex(ord1480, false);
      std::vector<u16> ord1482({1, 2, 0});
      slog::Relation* readrel1483 = db->getRelation("lambda");
      lambdaindex1468 = readrel1483->getIndex(ord1482, false);
      std::vector<u16> ord1484({1, 0});
      slog::Relation* readrel1485 = db->getRelation("num");
      numindex1469 = readrel1485->getIndex(ord1484, false);
      std::vector<u16> ord1486({1, 0});
      slog::Relation* readrel1487 = db->getRelation("ref");
      refindex1470 = readrel1487->getIndex(ord1486, false);
      std::vector<u16> ord1488({1, 0});
      slog::Relation* readrel1489 = db->getRelation("ref");
      refindex1471 = readrel1489->getIndex(ord1488, false);
      std::vector<u16> ord1490({1, 2, 0});
      slog::Relation* readrel1491 = db->getRelation("app");
      appindex1472 = readrel1491->getIndex(ord1490, false);
  
    }
    ReadTask1473(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_const0457bba0679825d285ef7fa5;
      u64 v_c124 = v_const30f8b180d63559f2512b744f;
      u64 v_c127 = v_constef2d127de37b942baad06145;
  
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
        u64 v_c253 = _t[1];
        u64 v_c138 = _t[2];
        u64 v_c254 = _t[3];
        u64 v_c131 = _t[4];
        if (!slog::exists_probe<2,1>(numindex1464, std::array<u64,2>{v_c127, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1465, std::array<u64,2>{v_c122, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1466, std::array<u64,2>{v_c124, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1467, std::array<u64,3>{v_c253, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1468, std::array<u64,3>{v_c131, v_c254, 0}, [&](const std::array<u64,3>& m1492) {
          u64 v_c255 = m1492[2];
          slog::join_probe<2,1>(numindex1469, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m1493) {
            u64 v_c133 = m1493[1];
            slog::join_probe<2,1>(refindex1470, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m1494) {
              u64 v_c136 = m1494[1];
              slog::join_probe<2,1>(refindex1471, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m1495) {
                u64 v_c137 = m1495[1];
                slog::join_probe<3,2>(appindex1472, std::array<u64,3>{v_c137, v_c253, 0}, [&](const std::array<u64,3>& m1496) {
                  u64 v_c256 = m1496[2];
                  u64 v_c257 = _prim_lpush(db, v_c129, v_c255);
                  if (v_c257 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                  ++_fires;
                  slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c256, v_c257, v_c138});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c138, v_c256}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp2CFC1002", _fires);
  
      if (!_done)
      {
        ReadTask1473* _cont = new ReadTask1473(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1473(db,b), false);
}

