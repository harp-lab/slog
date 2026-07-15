
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const00b70a53bc33238570e12d7a;
extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const0bbd2fbd1dc4200473343503;
extern u64 v_const0fc34686741291b4dd06511b;
extern u64 v_const20c400557af0eddc0be4d9e0;
extern u64 v_const2a09f8e08b8d8243373579d9;
extern u64 v_const2d53b3c21fa5cc786ac46d72;
extern u64 v_const37664d5895f78758ec8e94e4;
extern u64 v_const39c6f8839ca547fa7b7a32c4;
extern u64 v_const46a3ae93aa7a8b988080d6c9;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const71dc04e9084b526ffd253a28;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_consta05447c5b6502c5938db0f77;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste403ffb5ff0078a3e3c6bcc7;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c66ec8594335941e9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3bSs155 _00024seq2 __t2lyA156) (body (letp _00024sql2qfO508 (aslst _00024seq2)) (letp __t59ft158 (lref _00024sql2qfO508 _00024sqc65nX511)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3TKl513 __t59ft158 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2IHZ514 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Kdp515 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0AcC516 __t59ft158 _00024seq2) (join-old closure (0 1 2) 1 (0 1 2) __t59ft158 lm cb) (join any_bool (0) 0 b) (let chk8bx91129 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk8bx91129) (letp chk6vUA1130 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk6vUA1130)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atindex1;  slog::Index** $seq_atrindex2;  slog::Index** $seq_atrindex3;  slog::Index** closureindex4;  slog::Index** any_boolindex5;  slog::Index** $seq_atdelta6;  slog::Index** $seq_atdelta7;  slog::Index** $seq_atrdelta8;  slog::Index** $seq_atrdelta9;  slog::Index** closuredelta10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord12({1, 2, 0});
      slog::Relation* readrel13 = db->getRelation("delta");
      driver_index = readrel13->getIndex(ord12, true);
      std::vector<u16> ord14({1, 0, 2});
      slog::Relation* readrel15 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0, 2});
      slog::Relation* readrel17 = db->getRelation("$seq_at");
      $seq_atdelta6 = readrel17->getIndex(ord16, true);
      std::vector<u16> ord18({1, 0, 2});
      slog::Relation* readrel19 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0, 2});
      slog::Relation* readrel21 = db->getRelation("$seq_at");
      $seq_atdelta7 = readrel21->getIndex(ord20, true);
      std::vector<u16> ord22({1, 0, 2});
      slog::Relation* readrel23 = db->getRelation("$seq_atr");
      $seq_atrindex2 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0, 2});
      slog::Relation* readrel25 = db->getRelation("$seq_atr");
      $seq_atrdelta8 = readrel25->getIndex(ord24, true);
      std::vector<u16> ord26({1, 0, 2});
      slog::Relation* readrel27 = db->getRelation("$seq_atr");
      $seq_atrindex3 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0, 2});
      slog::Relation* readrel29 = db->getRelation("$seq_atr");
      $seq_atrdelta9 = readrel29->getIndex(ord28, true);
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("closure");
      closureindex4 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("closure");
      closuredelta10 = readrel33->getIndex(ord32, true);
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("any_bool");
      any_boolindex5 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const06abaa100ecef791ce028c56;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m36) {
        u64 v_c8 = m36[1];
        u64 v_c9 = m36[2];
        if (buckethash(v_c8) != bucket) return;
        bool ok37 = true;
        u64 v_c10 = _prim_aslst(db, v_c8, &ok37);
        if (!ok37) return;
        bool ok38 = true;
        u64 v_c11 = _prim_lref(db, v_c10, v_c2, &ok38);
        if (!ok38) return;
        slog::join_probe_old<3,3>($seq_atindex0, $seq_atdelta6, std::array<u64,3>{v_c4, v_c11, v_c8}, [&](const std::array<u64,3>& m39) {
          slog::join_probe_old<3,3>($seq_atindex1, $seq_atdelta7, std::array<u64,3>{v_c5, v_c11, v_c8}, [&](const std::array<u64,3>& m40) {
            slog::join_probe_old<3,3>($seq_atrindex2, $seq_atrdelta8, std::array<u64,3>{v_c6, v_c11, v_c8}, [&](const std::array<u64,3>& m41) {
              slog::join_probe_old<3,3>($seq_atrindex3, $seq_atrdelta9, std::array<u64,3>{v_c7, v_c11, v_c8}, [&](const std::array<u64,3>& m42) {
                slog::join_probe_old<3,1>(closureindex4, closuredelta10, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m43) {
                  u64 v_c12 = m43[1]; u64 v_c13 = m43[2];
                  slog::join_all<1>(any_boolindex5, [&](const std::array<u64,1>& m44) {
                    u64 v_c14 = m44[0];
                    u64 v_c15 = _prim_llen(db, v_c10);
                    if (v_c15 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c1 != v_c15) return;
                    bool ok45 = true;
                    u64 v_c16 = _prim_lref(db, v_c10, v_c3, &ok45);
                    if (!ok45) return;
                    if (v_c11 != v_c16) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c9, v_c14});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
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
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), false);
  // (crule (pre) (scan eval_ans __t9j6S443 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t9j6S443 c eb) (exists let (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (join-old $sup56712x91x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c eb __t1bnm441 er x) (exists eval (0 2 1) 2 __t1bnm441 c) (exists eval (1 2 0) 2 er c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t0DPj440) (join-old eval (0 2 1) 3 (0 2 1) __t1bnm441 c __t0DPj440) (join-old eval (1 2 0) 2 (1 2 0) er c __t0jgp442) (join eval_ans (0 1) 1 __t0jgp442 vr)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask61 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex46;  slog::Index** letindex47;  slog::Index** evalindex48;  slog::Index** $sup56712x91x0x0x0index49;  slog::Index** evalindex50;  slog::Index** evalindex51;  slog::Index** letindex52;  slog::Index** evalindex53;  slog::Index** evalindex54;  slog::Index** eval_ansindex55;  slog::Index** evaldelta56;  slog::Index** $sup56712x91x0x0x0delta57;  slog::Index** letdelta58;  slog::Index** evaldelta59;  slog::Index** evaldelta60;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("eval_ans");
      head_index[0] = readrel63->getIndex(ord62, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord64({0, 2, 1});
      slog::Relation* readrel65 = db->getRelation("eval");
      evalindex46 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 2, 1});
      slog::Relation* readrel67 = db->getRelation("eval");
      evaldelta56 = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({3, 0, 1, 2});
      slog::Relation* readrel69 = db->getRelation("let");
      letindex47 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({2, 0, 1});
      slog::Relation* readrel71 = db->getRelation("eval");
      evalindex48 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 2, 0, 3, 4});
      slog::Relation* readrel73 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index49 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 2, 0, 3, 4});
      slog::Relation* readrel75 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0delta57 = readrel75->getIndex(ord74, true);
      std::vector<u16> ord76({0, 2, 1});
      slog::Relation* readrel77 = db->getRelation("eval");
      evalindex50 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("eval");
      evalindex51 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({2, 1, 3, 0});
      slog::Relation* readrel81 = db->getRelation("let");
      letindex52 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 1, 3, 0});
      slog::Relation* readrel83 = db->getRelation("let");
      letdelta58 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({0, 2, 1});
      slog::Relation* readrel85 = db->getRelation("eval");
      evalindex53 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 2, 1});
      slog::Relation* readrel87 = db->getRelation("eval");
      evaldelta59 = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("eval");
      evalindex54 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("eval");
      evaldelta60 = readrel91->getIndex(ord90, true);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("eval_ans");
      eval_ansindex55 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        slog::join_probe_old<3,1>(evalindex46, evaldelta56, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m94) {
          u64 v_c19 = m94[1]; u64 v_c20 = m94[2];
          if (!slog::exists_probe<4,1>(letindex47, std::array<u64,4>{v_c20, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex48, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x91x0x0x0index49, $sup56712x91x0x0x0delta57, std::array<u64,5>{v_c19, v_c20, 0, 0, 0}, [&](const std::array<u64,5>& m95) {
            u64 v_c21 = m95[2]; u64 v_c22 = m95[3]; u64 v_c23 = m95[4];
            if (!slog::exists_probe<3,2>(evalindex50, std::array<u64,3>{v_c21, v_c19, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex51, std::array<u64,3>{v_c22, v_c19, 0})) return;
            slog::join_probe_old<4,3>(letindex52, letdelta58, std::array<u64,4>{v_c22, v_c23, v_c20, 0}, [&](const std::array<u64,4>& m96) {
              u64 v_c24 = m96[3];
              slog::join_probe_old<3,3>(evalindex53, evaldelta59, std::array<u64,3>{v_c21, v_c19, v_c24}, [&](const std::array<u64,3>& m97) {
                slog::join_probe_old<3,2>(evalindex54, evaldelta60, std::array<u64,3>{v_c22, v_c19, 0}, [&](const std::array<u64,3>& m98) {
                  u64 v_c25 = m98[2];
                  slog::join_probe<2,1>(eval_ansindex55, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m99) {
                    u64 v_c26 = m99[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c18}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask61* _cont = new ReadTask61(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask61(db,b), false);
  // (crule (pre) (scan eval_ans __t0jgp442 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t0jgp442 c er) (exists let (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (join-old $sup56712x91x0x0x0 (1 3 0 2 4) 2 (1 3 0 2 4) c er __t1bnm441 eb x) (exists eval (0 2 1) 2 __t1bnm441 c) (exists eval (1 2 0) 2 eb c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t0DPj440) (join-old eval (0 2 1) 3 (0 2 1) __t1bnm441 c __t0DPj440) (join-old eval (1 2 0) 2 (1 2 0) eb c __t9j6S443) (join-old eval_ans (0 1) 1 (0 1) __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex100;  slog::Index** letindex101;  slog::Index** evalindex102;  slog::Index** $sup56712x91x0x0x0index103;  slog::Index** evalindex104;  slog::Index** evalindex105;  slog::Index** letindex106;  slog::Index** evalindex107;  slog::Index** evalindex108;  slog::Index** eval_ansindex109;  slog::Index** evaldelta110;  slog::Index** $sup56712x91x0x0x0delta111;  slog::Index** letdelta112;  slog::Index** evaldelta113;  slog::Index** evaldelta114;  slog::Index** eval_ansdelta115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("eval_ans");
      head_index[0] = readrel118->getIndex(ord117, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord119({0, 2, 1});
      slog::Relation* readrel120 = db->getRelation("eval");
      evalindex100 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({0, 2, 1});
      slog::Relation* readrel122 = db->getRelation("eval");
      evaldelta110 = readrel122->getIndex(ord121, true);
      std::vector<u16> ord123({2, 1, 3, 0});
      slog::Relation* readrel124 = db->getRelation("let");
      letindex101 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({2, 0, 1});
      slog::Relation* readrel126 = db->getRelation("eval");
      evalindex102 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 3, 0, 2, 4});
      slog::Relation* readrel128 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index103 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({1, 3, 0, 2, 4});
      slog::Relation* readrel130 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0delta111 = readrel130->getIndex(ord129, true);
      std::vector<u16> ord131({0, 2, 1});
      slog::Relation* readrel132 = db->getRelation("eval");
      evalindex104 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 0});
      slog::Relation* readrel134 = db->getRelation("eval");
      evalindex105 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({2, 1, 3, 0});
      slog::Relation* readrel136 = db->getRelation("let");
      letindex106 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({2, 1, 3, 0});
      slog::Relation* readrel138 = db->getRelation("let");
      letdelta112 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({0, 2, 1});
      slog::Relation* readrel140 = db->getRelation("eval");
      evalindex107 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({0, 2, 1});
      slog::Relation* readrel142 = db->getRelation("eval");
      evaldelta113 = readrel142->getIndex(ord141, true);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("eval");
      evalindex108 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({1, 2, 0});
      slog::Relation* readrel146 = db->getRelation("eval");
      evaldelta114 = readrel146->getIndex(ord145, true);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("eval_ans");
      eval_ansindex109 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("eval_ans");
      eval_ansdelta115 = readrel150->getIndex(ord149, true);
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[1];
        slog::join_probe_old<3,1>(evalindex100, evaldelta110, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m151) {
          u64 v_c19 = m151[1]; u64 v_c22 = m151[2];
          if (!slog::exists_probe<4,1>(letindex101, std::array<u64,4>{v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex102, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x91x0x0x0index103, $sup56712x91x0x0x0delta111, std::array<u64,5>{v_c19, v_c22, 0, 0, 0}, [&](const std::array<u64,5>& m152) {
            u64 v_c21 = m152[2]; u64 v_c20 = m152[3]; u64 v_c23 = m152[4];
            if (!slog::exists_probe<3,2>(evalindex104, std::array<u64,3>{v_c21, v_c19, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex105, std::array<u64,3>{v_c20, v_c19, 0})) return;
            slog::join_probe_old<4,3>(letindex106, letdelta112, std::array<u64,4>{v_c22, v_c23, v_c20, 0}, [&](const std::array<u64,4>& m153) {
              u64 v_c24 = m153[3];
              slog::join_probe_old<3,3>(evalindex107, evaldelta113, std::array<u64,3>{v_c21, v_c19, v_c24}, [&](const std::array<u64,3>& m154) {
                slog::join_probe_old<3,2>(evalindex108, evaldelta114, std::array<u64,3>{v_c20, v_c19, 0}, [&](const std::array<u64,3>& m155) {
                  u64 v_c17 = m155[2];
                  slog::join_probe_old<2,1>(eval_ansindex109, eval_ansdelta115, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m156) {
                    u64 v_c18 = m156[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c18}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask116* _cont = new ReadTask116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask116(db,b), false);
  // (crule (pre) (scan letrec __t3tSN159 y er eb) (body (join freevar (1 0) 1 er x) (neq x y)) (head (emit freevar (0 1) x __t3tSN159)) freevars.slog:24 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex157;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("freevar");
      head_index[0] = readrel160->getIndex(ord159, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("freevar");
      freevarindex157 = readrel162->getIndex(ord161, false);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c20 = _t[3];
        slog::join_probe<2,1>(freevarindex157, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m163) {
          u64 v_c23 = m163[1];
          if (v_c23 == v_c28) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c27}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask158* _cont = new ReadTask158(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask158(db,b), false);
  // (crule (pre (let _00024sqc5Umw578 const6b86b273ff34fce19d6b804e) (let _00024sqc3t7M579 const5feceb66ffc86f38d952786c) (let _00024sqc8s9N580 const6b86b273ff34fce19d6b804e) (let _00024sqc7UCT581 const5feceb66ffc86f38d952786c) (let _00024sqo6m8k586 const5feceb66ffc86f38d952786c) (let __t4EG4161 (lempty))) (scan argument_list _00024seq0) (body (letp _00024sql6PLL576 (aslst _00024seq0)) (letp e (lref _00024sql6PLL576 _00024sqc3t7M579)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6m8k586 e _00024seq0) (join freevar (1 0) 1 e x) (let _00024sqn6WLF577 (llen _00024sql6PLL576)) (cmp ge _00024sqn6WLF577 _00024sqc5Umw578) (let _00024sqp95yh582 (_0002d _00024sqn6WLF577 _00024sqc7UCT581)) (let es (lslice _00024sql6PLL576 _00024sqc8s9N580 _00024sqp95yh582))) (head (emit-temp temp4nra1103 __t4EG4161 e es x)) freevars.slog:35 #f)
  class ReadTask167 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex164;  slog::Index** freevarindex165;  slog::Index** $seq_atdelta166;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4nra1103");
      outer_rel = db->getRelation("argument_list");
      std::vector<u16> ord168({1, 0, 2});
      slog::Relation* readrel169 = db->getRelation("$seq_at");
      $seq_atindex164 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 0, 2});
      slog::Relation* readrel171 = db->getRelation("$seq_at");
      $seq_atdelta166 = readrel171->getIndex(ord170, true);
      std::vector<u16> ord172({1, 0});
      slog::Relation* readrel173 = db->getRelation("freevar");
      freevarindex165 = readrel173->getIndex(ord172, false);
  
    }
    ReadTask167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c32 = v_const5feceb66ffc86f38d952786c;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = _prim_lempty(db);
      if (v_c34 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        bool ok174 = true;
        u64 v_c36 = _prim_aslst(db, v_c35, &ok174);
        if (!ok174) return;
        bool ok175 = true;
        u64 v_c37 = _prim_lref(db, v_c36, v_c30, &ok175);
        if (!ok175) return;
        slog::join_probe_old<3,3>($seq_atindex164, $seq_atdelta166, std::array<u64,3>{v_c33, v_c37, v_c35}, [&](const std::array<u64,3>& m176) {
          slog::join_probe<2,1>(freevarindex165, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m177) {
            u64 v_c23 = m177[1];
            u64 v_c38 = _prim_llen(db, v_c36);
            if (v_c38 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c39 = _prim_ge(db, v_c38, v_c29);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c39) return;
            u64 v_c40 = _prim__0002d(db, v_c38, v_c32);
            if (v_c40 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c41 = _prim_lslice(db, v_c36, v_c31, v_c40);
            if (v_c41 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c37, v_c41, v_c23});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:argument_list", _fires);
  
      if (!_done)
      {
        ReadTask167* _cont = new ReadTask167(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask167(db,b), false);
  // (crule (pre) (scan delta __t8RjX507 op vs) (body (exists delta_ans (0 1) 1 __t8RjX507) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t60iG506) (join delta_ans (0 1) 1 __t8RjX507 v) (join prim (1 0) 1 op __t4zl0505) (join eval_ans (1 0) 1 __t4zl0505 __t3A6m504) (join eval (0 2 1) 1 __t3A6m504 c ef) (exists $sup56712x74x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval_args (0 2 1) 2 __t60iG506 c es) (exists app (1 2 0) 2 ef es) (join $sup56712x74x0x0x0 (1 2 3 0) 3 c ef es __t8a3x503) (exists eval (0 2 1) 2 __t8a3x503 c) (join app (1 2 0) 2 ef es __t8eby502) (join eval (0 2 1) 3 __t8a3x503 c __t8eby502)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** delta_ansindex179;  slog::Index** primindex180;  slog::Index** eval_args_ansindex181;  slog::Index** delta_ansindex182;  slog::Index** primindex183;  slog::Index** eval_ansindex184;  slog::Index** evalindex185;  slog::Index** $sup56712x74x0x0x0index186;  slog::Index** appindex187;  slog::Index** evalindex188;  slog::Index** eval_argsindex189;  slog::Index** appindex190;  slog::Index** $sup56712x74x0x0x0index191;  slog::Index** evalindex192;  slog::Index** appindex193;  slog::Index** evalindex194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("eval_ans");
      head_index[0] = readrel197->getIndex(ord196, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord198({0, 1});
      slog::Relation* readrel199 = db->getRelation("delta_ans");
      delta_ansindex179 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("prim");
      primindex180 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("eval_args_ans");
      eval_args_ansindex181 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("delta_ans");
      delta_ansindex182 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("prim");
      primindex183 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("eval_ans");
      eval_ansindex184 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({0, 2, 1});
      slog::Relation* readrel211 = db->getRelation("eval");
      evalindex185 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 3, 0});
      slog::Relation* readrel213 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index186 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 0});
      slog::Relation* readrel215 = db->getRelation("app");
      appindex187 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({2, 0, 1});
      slog::Relation* readrel217 = db->getRelation("eval");
      evalindex188 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 2, 1});
      slog::Relation* readrel219 = db->getRelation("eval_args");
      eval_argsindex189 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("app");
      appindex190 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 3, 0});
      slog::Relation* readrel223 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index191 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 2, 1});
      slog::Relation* readrel225 = db->getRelation("eval");
      evalindex192 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("app");
      appindex193 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({0, 2, 1});
      slog::Relation* readrel229 = db->getRelation("eval");
      evalindex194 = readrel229->getIndex(ord228, false);
  
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        if (!slog::exists_probe<2,1>(delta_ansindex179, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<2,1>(primindex180, std::array<u64,2>{v_c43, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex181, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m230) {
          u64 v_c45 = m230[1];
          slog::join_probe<2,1>(delta_ansindex182, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m231) {
            u64 v_c18 = m231[1];
            slog::join_probe<2,1>(primindex183, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m232) {
              u64 v_c46 = m232[1];
              slog::join_probe<2,1>(eval_ansindex184, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m233) {
                u64 v_c47 = m233[1];
                slog::join_probe<3,1>(evalindex185, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m234) {
                  u64 v_c19 = m234[1]; u64 v_c48 = m234[2];
                  if (!slog::exists_probe<4,2>($sup56712x74x0x0x0index186, std::array<u64,4>{v_c19, v_c48, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex187, std::array<u64,3>{v_c48, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex188, std::array<u64,3>{v_c19, 0, 0})) return;
                  slog::join_probe<3,2>(eval_argsindex189, std::array<u64,3>{v_c45, v_c19, 0}, [&](const std::array<u64,3>& m235) {
                    u64 v_c41 = m235[2];
                    if (!slog::exists_probe<3,2>(appindex190, std::array<u64,3>{v_c48, v_c41, 0})) return;
                    slog::join_probe<4,3>($sup56712x74x0x0x0index191, std::array<u64,4>{v_c19, v_c48, v_c41, 0}, [&](const std::array<u64,4>& m236) {
                      u64 v_c49 = m236[3];
                      if (!slog::exists_probe<3,2>(evalindex192, std::array<u64,3>{v_c49, v_c19, 0})) return;
                      slog::join_probe<3,2>(appindex193, std::array<u64,3>{v_c48, v_c41, 0}, [&](const std::array<u64,3>& m237) {
                        u64 v_c50 = m237[2];
                        slog::join_probe<3,3>(evalindex194, std::array<u64,3>{v_c49, v_c19, v_c50}, [&](const std::array<u64,3>& m238) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c18}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:delta", _fires);
  
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
  // (crule (pre) (scan letrec __t3qWc160 y er eb) (body (join freevar (1 0) 1 eb x) (neq x y)) (head (emit freevar (0 1) x __t3qWc160)) freevars.slog:24 #f)
  class ReadTask240 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex239;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("freevar");
      head_index[0] = readrel242->getIndex(ord241, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord243({1, 0});
      slog::Relation* readrel244 = db->getRelation("freevar");
      freevarindex239 = readrel244->getIndex(ord243, false);
  
    }
    ReadTask240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c20 = _t[3];
        slog::join_probe<2,1>(freevarindex239, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m245) {
          u64 v_c23 = m245[1];
          if (v_c23 == v_c28) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c51}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask240* _cont = new ReadTask240(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask240(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3VNs307 _00024seq2 __t5HIm308) (body (letp _00024sql2wmw517 (aslst _00024seq2)) (letp __t5ERV310 (lref _00024sql2wmw517 _00024sqc5bE7520)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7nH0522 __t5ERV310 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8HCy523 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Uwu524 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9OPL525 __t5ERV310 _00024seq2) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join-old symval (0 1) 1 (0 1) __t5ERV310 s) (let chk0bjP1147 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk0bjP1147) (letp chk2whU1148 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk2whU1148)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex246;  slog::Index** $seq_atindex247;  slog::Index** $seq_atrindex248;  slog::Index** $seq_atrindex249;  slog::Index** _enumindex250;  slog::Index** symvalindex251;  slog::Index** $seq_atdelta252;  slog::Index** $seq_atdelta253;  slog::Index** $seq_atrdelta254;  slog::Index** $seq_atrdelta255;  slog::Index** symvaldelta256;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord258({1, 2, 0});
      slog::Relation* readrel259 = db->getRelation("delta");
      driver_index = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 0, 2});
      slog::Relation* readrel261 = db->getRelation("$seq_at");
      $seq_atindex246 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 0, 2});
      slog::Relation* readrel263 = db->getRelation("$seq_at");
      $seq_atdelta252 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({1, 0, 2});
      slog::Relation* readrel265 = db->getRelation("$seq_at");
      $seq_atindex247 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 0, 2});
      slog::Relation* readrel267 = db->getRelation("$seq_at");
      $seq_atdelta253 = readrel267->getIndex(ord266, true);
      std::vector<u16> ord268({1, 0, 2});
      slog::Relation* readrel269 = db->getRelation("$seq_atr");
      $seq_atrindex248 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0, 2});
      slog::Relation* readrel271 = db->getRelation("$seq_atr");
      $seq_atrdelta254 = readrel271->getIndex(ord270, true);
      std::vector<u16> ord272({1, 0, 2});
      slog::Relation* readrel273 = db->getRelation("$seq_atr");
      $seq_atrindex249 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 0, 2});
      slog::Relation* readrel275 = db->getRelation("$seq_atr");
      $seq_atrdelta255 = readrel275->getIndex(ord274, true);
      std::vector<u16> ord276({1, 0});
      slog::Relation* readrel277 = db->getRelation("_enum");
      _enumindex250 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("symval");
      symvalindex251 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({0, 1});
      slog::Relation* readrel281 = db->getRelation("symval");
      symvaldelta256 = readrel281->getIndex(ord280, true);
  
    }
    ReadTask257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c53 = v_const06abaa100ecef791ce028c56;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c53, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m282) {
        u64 v_c8 = m282[1];
        u64 v_c61 = m282[2];
        if (buckethash(v_c8) != bucket) return;
        bool ok283 = true;
        u64 v_c62 = _prim_aslst(db, v_c8, &ok283);
        if (!ok283) return;
        bool ok284 = true;
        u64 v_c63 = _prim_lref(db, v_c62, v_c55, &ok284);
        if (!ok284) return;
        slog::join_probe_old<3,3>($seq_atindex246, $seq_atdelta252, std::array<u64,3>{v_c57, v_c63, v_c8}, [&](const std::array<u64,3>& m285) {
          slog::join_probe_old<3,3>($seq_atindex247, $seq_atdelta253, std::array<u64,3>{v_c58, v_c63, v_c8}, [&](const std::array<u64,3>& m286) {
            slog::join_probe_old<3,3>($seq_atrindex248, $seq_atrdelta254, std::array<u64,3>{v_c59, v_c63, v_c8}, [&](const std::array<u64,3>& m287) {
              slog::join_probe_old<3,3>($seq_atrindex249, $seq_atrdelta255, std::array<u64,3>{v_c60, v_c63, v_c8}, [&](const std::array<u64,3>& m288) {
                slog::join_probe<2,1>(_enumindex250, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m289) {
                  u64 v_c64 = m289[1];
                  slog::join_probe_old<2,1>(symvalindex251, symvaldelta256, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m290) {
                    u64 v_c65 = m290[1];
                    u64 v_c66 = _prim_llen(db, v_c62);
                    if (v_c66 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c54 != v_c66) return;
                    bool ok291 = true;
                    u64 v_c67 = _prim_lref(db, v_c62, v_c56, &ok291);
                    if (!ok291) return;
                    if (v_c63 != v_c67) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c61});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c64}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask257* _cont = new ReadTask257(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask257(db,b), false);
  // (crule (pre) (scan sym __t4jyq321 s) (body (join-old eval (1 2 0) 1 (1 2 0) __t4jyq321 c __t1acj322)) (head (emit-temp temp7Ldx1076 __t1acj322 s) (mkstruct symval (1 0) __t4PSF320 s)) interp.slog:28 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex292;  slog::Index** evaldelta293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Ldx1076");
      head_rel[1] = db->getRelation("symval");
      outer_rel = db->getRelation("sym");
      std::vector<u16> ord295({1, 2, 0});
      slog::Relation* readrel296 = db->getRelation("eval");
      evalindex292 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("eval");
      evaldelta293 = readrel298->getIndex(ord297, true);
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[0];
        u64 v_c65 = _t[1];
        slog::join_probe_old<3,1>(evalindex292, evaldelta293, std::array<u64,3>{v_c68, 0, 0}, [&](const std::array<u64,3>& m299) {
          u64 v_c19 = m299[1]; u64 v_c69 = m299[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c65});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c65}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:28", "delta:sym", _fires);
  
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
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7)) (scan temp9CrE1013 __t18GV497 __t6n7e489 __t8zw1478) (body (join let (2 1 3 0) 3 __t6n7e489 __tconst7G6n490 __t8zw1478 __t6FoF491)) (head (emit-temp temp105Q1014 __t18GV497 __t6FoF491) (mkstruct let (2 1 3 0) __t9OTU499 __t18GV497 __tconst8pH5498 __t6FoF491)) schemecfa.slog:51 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp105Q1014");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp9CrE1013");
      std::vector<u16> ord302({2, 1, 3, 0});
      slog::Relation* readrel303 = db->getRelation("let");
      letindex300 = readrel303->getIndex(ord302, false);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c71 = v_conste403ffb5ff0078a3e3c6bcc7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c74 = _t[2];
        slog::join_probe<4,3>(letindex300, std::array<u64,4>{v_c73, v_c71, v_c74, 0}, [&](const std::array<u64,4>& m304) {
          u64 v_c75 = m304[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c72, v_c75});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c72, v_c70, v_c75}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp9CrE1013", _fires);
  
      if (!_done)
      {
        ReadTask301* _cont = new ReadTask301(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask301(db,b), false);
  // (crule (pre) (scan temp2sam1177 __t1MuT124 c m) (body (let __t0raq125 (lcat __t1MuT124 c))) (head (emit-temp temp5zYE1178 __t0raq125 m)) context.slog:10 #f)
  class ReadTask305 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5zYE1178");
      outer_rel = db->getRelation("temp2sam1177");
  
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
        u64 v_c76 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c77 = _t[2];
        u64 v_c78 = _prim_lcat(db, v_c76, v_c19);
        if (v_c78 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c78, v_c77});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp2sam1177", _fires);
  
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
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0) (let __tconst3fuu217 const06abaa100ecef791ce028c56) (let _00024sqc1fPN569 constd4735e3a265e16eee03f5971) (let _00024sqc78q5570 const5feceb66ffc86f38d952786c) (let _00024sqc5TDx571 const6b86b273ff34fce19d6b804e) (let _00024sqo1Czp572 const5feceb66ffc86f38d952786c) (let _00024sqo2Uyj573 const6b86b273ff34fce19d6b804e) (let _00024sqo2qsW574 const6b86b273ff34fce19d6b804e) (let _00024sqo2mjM575 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2mjM575 v2 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo2Uyj573 v2 _00024seq0) (letp _00024sql8W3E567 (aslst _00024seq0)) (letp v1 (lref _00024sql8W3E567 _00024sqc78q5570)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo1Czp572 v1 _00024seq0) (join $seq_atr (1 0 2) 3 _00024sqo2qsW574 v1 _00024seq0) (exists _enum (1 0) 1 __tconst03NO760) (join delta (1 2 0) 2 __tconst3fuu217 _00024seq0 __t12h7218) (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (let chk3HJt1099 (llen _00024sql8W3E567)) (eq _00024sqc1fPN569 chk3HJt1099) (letp chk9fW41100 (lref _00024sql8W3E567 _00024sqc5TDx571)) (eq v2 chk9fW41100)) (head (emit-temp temp4VE71091 __t12h7218) (mkstruct boolval (1 0) __t5boA216 __t6tMS215)) interp.slog:120 #f)
  class ReadTask312 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex306;  slog::Index** $seq_atindex307;  slog::Index** $seq_atrindex308;  slog::Index** _enumindex309;  slog::Index** deltaindex310;  slog::Index** _enumindex311;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4VE71091");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord313({1, 0, 2});
      slog::Relation* readrel314 = db->getRelation("$seq_atr");
      driver_index = readrel314->getIndex(ord313, true);
      std::vector<u16> ord315({1, 0, 2});
      slog::Relation* readrel316 = db->getRelation("$seq_at");
      $seq_atindex306 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0, 2});
      slog::Relation* readrel318 = db->getRelation("$seq_at");
      $seq_atindex307 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0, 2});
      slog::Relation* readrel320 = db->getRelation("$seq_atr");
      $seq_atrindex308 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 0});
      slog::Relation* readrel322 = db->getRelation("_enum");
      _enumindex309 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 2, 0});
      slog::Relation* readrel324 = db->getRelation("delta");
      deltaindex310 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 0});
      slog::Relation* readrel326 = db->getRelation("_enum");
      _enumindex311 = readrel326->getIndex(ord325, false);
  
    }
    ReadTask312(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c80 = v_const06abaa100ecef791ce028c56;
      u64 v_c81 = v_constd4735e3a265e16eee03f5971;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_const5feceb66ffc86f38d952786c;
      u64 v_c85 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c86 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c87, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m327) {
        u64 v_c88 = m327[1];
        u64 v_c35 = m327[2];
        if (buckethash(v_c88) != bucket) return;
        slog::join_probe<3,3>($seq_atindex306, std::array<u64,3>{v_c85, v_c88, v_c35}, [&](const std::array<u64,3>& m328) {
          bool ok329 = true;
          u64 v_c89 = _prim_aslst(db, v_c35, &ok329);
          if (!ok329) return;
          bool ok330 = true;
          u64 v_c90 = _prim_lref(db, v_c89, v_c82, &ok330);
          if (!ok330) return;
          if (v_c90 == v_c88) return;
          slog::join_probe<3,3>($seq_atindex307, std::array<u64,3>{v_c84, v_c90, v_c35}, [&](const std::array<u64,3>& m331) {
            slog::join_probe<3,3>($seq_atrindex308, std::array<u64,3>{v_c86, v_c90, v_c35}, [&](const std::array<u64,3>& m332) {
              if (!slog::exists_probe<2,1>(_enumindex309, std::array<u64,2>{v_c79, 0})) return;
              slog::join_probe<3,2>(deltaindex310, std::array<u64,3>{v_c80, v_c35, 0}, [&](const std::array<u64,3>& m333) {
                u64 v_c91 = m333[2];
                slog::join_probe<2,1>(_enumindex311, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m334) {
                  u64 v_c92 = m334[1];
                  u64 v_c93 = _prim_llen(db, v_c89);
                  if (v_c93 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c81 != v_c93) return;
                  bool ok335 = true;
                  u64 v_c94 = _prim_lref(db, v_c89, v_c83, &ok335);
                  if (!ok335) return;
                  if (v_c88 != v_c94) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c91});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c92}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask312* _cont = new ReadTask312(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask312(db,b), false);
  // (crule (pre) (scan temp0LsC994 __t6kpB195 b) (body (join boolval (1 0) 1 b __t7v8e193)) (head (emit eval_ans (0 1) __t6kpB195 __t7v8e193)) interp.slog:27 #f)
  class ReadTask337 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex336;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("eval_ans");
      head_index[0] = readrel339->getIndex(ord338, false);
      outer_rel = db->getRelation("temp0LsC994");
      std::vector<u16> ord340({1, 0});
      slog::Relation* readrel341 = db->getRelation("boolval");
      boolvalindex336 = readrel341->getIndex(ord340, false);
  
    }
    ReadTask337(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(boolvalindex336, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m342) {
          u64 v_c96 = m342[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c95, v_c96}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:27", "delta:temp0LsC994", _fires);
  
      if (!_done)
      {
        ReadTask337* _cont = new ReadTask337(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask337(db,b), false);
  // (crule (pre) (scan prim __t9gUy312 op) (body (join eval_ans (1 0) 1 __t9gUy312 __t55UJ311) (join eval (0 2 1) 1 __t55UJ311 c ef) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2HTD313) (join eval_args_ans (0 1) 1 __t2HTD313 vs)) (head (mkstruct delta (1 2 0) __8qO4739 op vs)) interp.slog:75 #f)
  class ReadTask350 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex343;  slog::Index** evalindex344;  slog::Index** eval_argsindex345;  slog::Index** $sup56712x74x0x0x0index346;  slog::Index** eval_argsindex347;  slog::Index** eval_args_ansindex348;  slog::Index** eval_argsdelta349;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("eval_ans");
      eval_ansindex343 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 2, 1});
      slog::Relation* readrel354 = db->getRelation("eval");
      evalindex344 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({2, 0, 1});
      slog::Relation* readrel356 = db->getRelation("eval_args");
      eval_argsindex345 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 3, 0});
      slog::Relation* readrel358 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index346 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 2, 0});
      slog::Relation* readrel360 = db->getRelation("eval_args");
      eval_argsindex347 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("eval_args");
      eval_argsdelta349 = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("eval_args_ans");
      eval_args_ansindex348 = readrel364->getIndex(ord363, false);
  
    }
    ReadTask350(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[1];
        slog::join_probe<2,1>(eval_ansindex343, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m365) {
          u64 v_c98 = m365[1];
          slog::join_probe<3,1>(evalindex344, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m366) {
            u64 v_c19 = m366[1]; u64 v_c48 = m366[2];
            if (!slog::exists_probe<3,1>(eval_argsindex345, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index346, std::array<u64,4>{v_c19, v_c48, 0, 0}, [&](const std::array<u64,4>& m367) {
              u64 v_c41 = m367[2]; u64 v_c99 = m367[3];
              slog::join_probe_old<3,2>(eval_argsindex347, eval_argsdelta349, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m368) {
                u64 v_c100 = m368[2];
                slog::join_probe<2,1>(eval_args_ansindex348, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m369) {
                  u64 v_c44 = m369[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c43, v_c44}, std::array<u16,3>{1, 2, 0});
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
        ReadTask350* _cont = new ReadTask350(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask350(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e)) (scan temp3f2d1112 __t2xne366 __t3xwX335 __t4CVz374 __t72Zs370 __t9cbk347) (body (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334)) (head (emit-temp temp1KBC1113 __t2xne366 __t3xwX335 __t4CVz374 __t72Zs370 __t9cbk347) (mkstruct app (1 2 0) __t3As1350 __t7cCj334 __t9cbk347)) schemecfa.slog:12 #f)
  class ReadTask375 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex370;  slog::Index** refindex371;  slog::Index** refindex372;  slog::Index** numindex373;  slog::Index** refindex374;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1KBC1113");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp3f2d1112");
      std::vector<u16> ord376({1, 0});
      slog::Relation* readrel377 = db->getRelation("num");
      numindex370 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 0});
      slog::Relation* readrel379 = db->getRelation("ref");
      refindex371 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("ref");
      refindex372 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 0});
      slog::Relation* readrel383 = db->getRelation("num");
      numindex373 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("ref");
      refindex374 = readrel385->getIndex(ord384, false);
  
    }
    ReadTask375(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_consta81ad7556291f9defc5163ec;
      u64 v_c102 = v_consted725292f5f32d61535958c1;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c105 = _t[1];
        u64 v_c106 = _t[2];
        u64 v_c107 = _t[3];
        u64 v_c108 = _t[4];
        if (!slog::exists_probe<2,1>(numindex370, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex371, std::array<u64,2>{v_c101, 0})) return;
        slog::join_probe<2,1>(refindex372, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m386) {
          u64 v_c109 = m386[1];
          slog::join_probe<2,1>(numindex373, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m387) {
            u64 v_c110 = m387[1];
            slog::join_probe<2,1>(refindex374, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m388) {
              u64 v_c111 = m388[1];
              ++_fires;
              slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c104, v_c105, v_c106, v_c107, v_c108});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c111, v_c108}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp3f2d1112", _fires);
  
      if (!_done)
      {
        ReadTask375* _cont = new ReadTask375(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask375(db,b), false);
  // (crule (pre) (scan eval __t9Q4F432 e1 c) (body (exists eval_ans (0 1) 1 __t9Q4F432) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t1sbj433 __v0) (join eval_ans (0 1) 2 __t9Q4F432 __v0) (join select_branch_ans (0 1) 1 __t1sbj433 __v1)) (head (mkstruct eval (1 2 0) __9Gjy723 __v1 c)) interp.slog:87 #f)
  class ReadTask395 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex389;  slog::Index** $sup56712x86x0x0x0index390;  slog::Index** select_branchindex391;  slog::Index** eval_ansindex392;  slog::Index** select_branch_ansindex393;  slog::Index** select_branchdelta394;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("eval_ans");
      eval_ansindex389 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 2, 0, 3, 4});
      slog::Relation* readrel399 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index390 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({2, 3, 0, 1});
      slog::Relation* readrel401 = db->getRelation("select_branch");
      select_branchindex391 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({2, 3, 0, 1});
      slog::Relation* readrel403 = db->getRelation("select_branch");
      select_branchdelta394 = readrel403->getIndex(ord402, true);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("eval_ans");
      eval_ansindex392 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("select_branch_ans");
      select_branch_ansindex393 = readrel407->getIndex(ord406, false);
  
    }
    ReadTask395(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex389, std::array<u64,2>{v_c112, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index390, std::array<u64,5>{v_c19, v_c113, 0, 0, 0}, [&](const std::array<u64,5>& m408) {
          u64 v_c99 = m408[2]; u64 v_c114 = m408[3]; u64 v_c115 = m408[4];
          slog::join_probe_old<4,2>(select_branchindex391, select_branchdelta394, std::array<u64,4>{v_c114, v_c115, 0, 0}, [&](const std::array<u64,4>& m409) {
            u64 v_c116 = m409[2]; u64 v_c117 = m409[3];
            slog::join_probe<2,2>(eval_ansindex392, std::array<u64,2>{v_c112, v_c117}, [&](const std::array<u64,2>& m410) {
              slog::join_probe<2,1>(select_branch_ansindex393, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m411) {
                u64 v_c118 = m411[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c118, v_c19}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
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
  // (crule (pre (let __t6Vjn123 (lempty))) (scan tick __t9p6E126 site c) (body (join mlimit (0) 0 m)) (head (emit-temp temp8zAf1176 __t6Vjn123 c m site)) context.slog:10 #f)
  class ReadTask413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex412;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8zAf1176");
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord414({0});
      slog::Relation* readrel415 = db->getRelation("mlimit");
      mlimitindex412 = readrel415->getIndex(ord414, false);
  
    }
    ReadTask413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = _prim_lempty(db);
      if (v_c119 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c120 = _t[0];
        u64 v_c121 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_all<1>(mlimitindex412, [&](const std::array<u64,1>& m416) {
          u64 v_c77 = m416[0];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c119, v_c19, v_c77, v_c121});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask413* _cont = new ReadTask413(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask413(db,b), false);
  // (crule (pre (let __tconst04ab676 constcd2a69ce5ca278db1d6da969) (let _00024sqc0NDP645 constd4735e3a265e16eee03f5971) (let _00024sqc7bIa646 const5feceb66ffc86f38d952786c) (let _00024sqc1Uf7647 const6b86b273ff34fce19d6b804e) (let _00024sqo7IWL648 const5feceb66ffc86f38d952786c) (let _00024sqo5kNQ649 const6b86b273ff34fce19d6b804e) (let _00024sqo9k7p650 const6b86b273ff34fce19d6b804e) (let _00024sqo7Xo2651 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo7IWL648 __t2qlr318 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5kNQ649 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9k7p650 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7Xo2651 __t2qlr318 _00024seq2) (join _enum (0 1) 2 __t2qlr318 __tconst04ab676) (join delta (2 0 1) 1 _00024seq2 __t6QsA316 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql2g05643 (aslst _00024seq2)) (let chk6XWQ1018 (llen _00024sql2g05643)) (eq _00024sqc0NDP645 chk6XWQ1018) (letp chk7p8m1019 (lref _00024sql2g05643 _00024sqc7bIa646)) (eq __t2qlr318 chk7p8m1019) (letp chk3rim1020 (lref _00024sql2g05643 _00024sqc1Uf7647)) (eq __t2qlr318 chk3rim1020)) (head (emit-temp temp53FS1015 __t6QsA316 b) (mkstruct boolval (1 0) __t3y4C315 b)) interp.slog:112 #f)
  class ReadTask427 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex417;  slog::Index** $seq_atrindex418;  slog::Index** $seq_atrindex419;  slog::Index** _enumindex420;  slog::Index** deltaindex421;  slog::Index** comparison_opindex422;  slog::Index** any_boolindex423;  slog::Index** $seq_atdelta424;  slog::Index** $seq_atrdelta425;  slog::Index** $seq_atrdelta426;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp53FS1015");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord428({1, 0, 2});
      slog::Relation* readrel429 = db->getRelation("$seq_at");
      driver_index = readrel429->getIndex(ord428, true);
      std::vector<u16> ord430({1, 0, 2});
      slog::Relation* readrel431 = db->getRelation("$seq_at");
      $seq_atindex417 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 0, 2});
      slog::Relation* readrel433 = db->getRelation("$seq_at");
      $seq_atdelta424 = readrel433->getIndex(ord432, true);
      std::vector<u16> ord434({1, 0, 2});
      slog::Relation* readrel435 = db->getRelation("$seq_atr");
      $seq_atrindex418 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 0, 2});
      slog::Relation* readrel437 = db->getRelation("$seq_atr");
      $seq_atrdelta425 = readrel437->getIndex(ord436, true);
      std::vector<u16> ord438({1, 0, 2});
      slog::Relation* readrel439 = db->getRelation("$seq_atr");
      $seq_atrindex419 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 0, 2});
      slog::Relation* readrel441 = db->getRelation("$seq_atr");
      $seq_atrdelta426 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({0, 1});
      slog::Relation* readrel443 = db->getRelation("_enum");
      _enumindex420 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({2, 0, 1});
      slog::Relation* readrel445 = db->getRelation("delta");
      deltaindex421 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({0});
      slog::Relation* readrel447 = db->getRelation("comparison_op");
      comparison_opindex422 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0});
      slog::Relation* readrel449 = db->getRelation("any_bool");
      any_boolindex423 = readrel449->getIndex(ord448, false);
  
    }
    ReadTask427(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c126, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m450) {
        u64 v_c130 = m450[1];
        u64 v_c8 = m450[2];
        if (buckethash(v_c130) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex417, $seq_atdelta424, std::array<u64,3>{v_c127, v_c130, v_c8}, [&](const std::array<u64,3>& m451) {
          slog::join_probe_old<3,3>($seq_atrindex418, $seq_atrdelta425, std::array<u64,3>{v_c128, v_c130, v_c8}, [&](const std::array<u64,3>& m452) {
            slog::join_probe_old<3,3>($seq_atrindex419, $seq_atrdelta426, std::array<u64,3>{v_c129, v_c130, v_c8}, [&](const std::array<u64,3>& m453) {
              slog::join_probe<2,2>(_enumindex420, std::array<u64,2>{v_c130, v_c122}, [&](const std::array<u64,2>& m454) {
                slog::join_probe<3,1>(deltaindex421, std::array<u64,3>{v_c8, 0, 0}, [&](const std::array<u64,3>& m455) {
                  u64 v_c131 = m455[1]; u64 v_c43 = m455[2];
                  slog::join_probe<1,1>(comparison_opindex422, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m456) {
                    slog::join_all<1>(any_boolindex423, [&](const std::array<u64,1>& m457) {
                      u64 v_c14 = m457[0];
                      bool ok458 = true;
                      u64 v_c132 = _prim_aslst(db, v_c8, &ok458);
                      if (!ok458) return;
                      u64 v_c133 = _prim_llen(db, v_c132);
                      if (v_c133 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c123 != v_c133) return;
                      bool ok459 = true;
                      u64 v_c134 = _prim_lref(db, v_c132, v_c124, &ok459);
                      if (!ok459) return;
                      if (v_c130 != v_c134) return;
                      bool ok460 = true;
                      u64 v_c135 = _prim_lref(db, v_c132, v_c125, &ok460);
                      if (!ok460) return;
                      if (v_c130 != v_c135) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c131, v_c14});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask427* _cont = new ReadTask427(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask427(db,b), false);
  // (crule (pre) (scan if __t4dlE324 e1 e2 e3) (body (join freevar (1 0) 1 e2 x)) (head (emit freevar (0 1) x __t4dlE324)) freevars.slog:17 #f)
  class ReadTask462 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex461;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord463({0, 1});
      slog::Relation* readrel464 = db->getRelation("freevar");
      head_index[0] = readrel464->getIndex(ord463, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord465({1, 0});
      slog::Relation* readrel466 = db->getRelation("freevar");
      freevarindex461 = readrel466->getIndex(ord465, false);
  
    }
    ReadTask462(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c136 = _t[0];
        u64 v_c113 = _t[1];
        u64 v_c114 = _t[2];
        u64 v_c115 = _t[3];
        slog::join_probe<2,1>(freevarindex461, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m467) {
          u64 v_c23 = m467[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c136}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask462* _cont = new ReadTask462(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask462(db,b), false);
  // (crule (pre) (scan eval __t3m2r182 er c) (body (exists eval (2 0 1) 1 c) (exists letrec (2 1 3 0) 1 er) (join eval_ans (0 1) 1 __t3m2r182 vr) (join eval (2 0 1) 1 c __1E5R778 __t7zZ2181) (join letrec (0 2 1 3) 2 __t7zZ2181 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask473 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex468;  slog::Index** letrecindex469;  slog::Index** eval_ansindex470;  slog::Index** evalindex471;  slog::Index** letrecindex472;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord474({0, 1, 2});
      slog::Relation* readrel475 = db->getRelation("binding");
      head_index[0] = readrel475->getIndex(ord474, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord476({0, 1, 2});
      slog::Relation* readrel477 = db->getRelation("binding_event");
      head_index[1] = readrel477->getIndex(ord476, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord478({2, 0, 1});
      slog::Relation* readrel479 = db->getRelation("eval");
      evalindex468 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({2, 1, 3, 0});
      slog::Relation* readrel481 = db->getRelation("letrec");
      letrecindex469 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({0, 1});
      slog::Relation* readrel483 = db->getRelation("eval_ans");
      eval_ansindex470 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({2, 0, 1});
      slog::Relation* readrel485 = db->getRelation("eval");
      evalindex471 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 2, 1, 3});
      slog::Relation* readrel487 = db->getRelation("letrec");
      letrecindex472 = readrel487->getIndex(ord486, false);
  
    }
    ReadTask473(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex468, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex469, std::array<u64,4>{v_c22, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex470, std::array<u64,2>{v_c137, 0}, [&](const std::array<u64,2>& m488) {
          u64 v_c26 = m488[1];
          slog::join_probe<3,1>(evalindex471, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m489) {
            u64 v_c138 = m489[1]; u64 v_c139 = m489[2];
            slog::join_probe<4,2>(letrecindex472, std::array<u64,4>{v_c139, v_c22, 0, 0}, [&](const std::array<u64,4>& m490) {
              u64 v_c23 = m490[2]; u64 v_c20 = m490[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c23, v_c19, v_c26}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c23, v_c19, v_c19}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask473* _cont = new ReadTask473(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask473(db,b), false);
  // (crule (pre) (scan closure __t4ng7301 __t4mHn300 cb) (body (join eval_ans (1 0) 1 __t4ng7301 __t9B5D299) (join eval (0 2 1) 1 __t9B5D299 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join tick_ans (0 1) 1 __t5Pln304 l) (join lambda (0 1 2) 1 __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask509 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex491;  slog::Index** evalindex492;  slog::Index** appindex493;  slog::Index** eval_argsindex494;  slog::Index** tickindex495;  slog::Index** evalindex496;  slog::Index** tickindex497;  slog::Index** appindex498;  slog::Index** eval_argsindex499;  slog::Index** eval_args_ansindex500;  slog::Index** tickindex501;  slog::Index** tick_ansindex502;  slog::Index** eval_args_ansindex503;  slog::Index** tick_ansindex504;  slog::Index** lambdaindex505;  slog::Index** appdelta506;  slog::Index** eval_argsdelta507;  slog::Index** tickdelta508;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord510({0, 1, 2, 3});
      slog::Relation* readrel511 = db->getRelation("bind_params");
      head_index[0] = readrel511->getIndex(ord510, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("call_event");
      head_index[1] = readrel513->getIndex(ord512, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord514({1, 0});
      slog::Relation* readrel515 = db->getRelation("eval_ans");
      eval_ansindex491 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({0, 2, 1});
      slog::Relation* readrel517 = db->getRelation("eval");
      evalindex492 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 0});
      slog::Relation* readrel519 = db->getRelation("app");
      appindex493 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({2, 0, 1});
      slog::Relation* readrel521 = db->getRelation("eval_args");
      eval_argsindex494 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({2, 0, 1});
      slog::Relation* readrel523 = db->getRelation("tick");
      tickindex495 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({2, 0, 1});
      slog::Relation* readrel525 = db->getRelation("eval");
      evalindex496 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 2, 0});
      slog::Relation* readrel527 = db->getRelation("tick");
      tickindex497 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("app");
      appindex498 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 1, 2});
      slog::Relation* readrel531 = db->getRelation("app");
      appdelta506 = readrel531->getIndex(ord530, true);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("eval_args");
      eval_argsindex499 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("eval_args");
      eval_argsdelta507 = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("eval_args_ans");
      eval_args_ansindex500 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 2, 0});
      slog::Relation* readrel539 = db->getRelation("tick");
      tickindex501 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("tick");
      tickdelta508 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("tick_ans");
      tick_ansindex502 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("eval_args_ans");
      eval_args_ansindex503 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({0, 1});
      slog::Relation* readrel547 = db->getRelation("tick_ans");
      tick_ansindex504 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({0, 1, 2});
      slog::Relation* readrel549 = db->getRelation("lambda");
      lambdaindex505 = readrel549->getIndex(ord548, false);
  
    }
    ReadTask509(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c140 = _t[0];
        u64 v_c141 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe<2,1>(eval_ansindex491, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m550) {
          u64 v_c142 = m550[1];
          slog::join_probe<3,1>(evalindex492, std::array<u64,3>{v_c142, 0, 0}, [&](const std::array<u64,3>& m551) {
            u64 v_c19 = m551[1]; u64 v_c48 = m551[2];
            if (!slog::exists_probe<3,1>(appindex493, std::array<u64,3>{v_c48, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex494, std::array<u64,3>{v_c19, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex495, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe<3,1>(evalindex496, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m552) {
              u64 v_c143 = m552[1]; u64 v_c144 = m552[2];
              if (!slog::exists_probe<3,2>(tickindex497, std::array<u64,3>{v_c144, v_c19, 0})) return;
              slog::join_probe_old<3,2>(appindex498, appdelta506, std::array<u64,3>{v_c144, v_c48, 0}, [&](const std::array<u64,3>& m553) {
                u64 v_c41 = m553[2];
                slog::join_probe_old<3,2>(eval_argsindex499, eval_argsdelta507, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m554) {
                  u64 v_c145 = m554[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex500, std::array<u64,2>{v_c145, 0})) return;
                  slog::join_probe_old<3,2>(tickindex501, tickdelta508, std::array<u64,3>{v_c144, v_c19, 0}, [&](const std::array<u64,3>& m555) {
                    u64 v_c146 = m555[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex502, std::array<u64,2>{v_c146, 0})) return;
                    slog::join_probe<2,1>(eval_args_ansindex503, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m556) {
                      u64 v_c44 = m556[1];
                      slog::join_probe<2,1>(tick_ansindex504, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m557) {
                        u64 v_c147 = m557[1];
                        slog::join_probe<3,1>(lambdaindex505, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m558) {
                          u64 v_c148 = m558[1]; u64 v_c20 = m558[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c148, v_c44, v_c147, v_c19}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c147, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask509* _cont = new ReadTask509(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask509(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst35kI244 _00024seq2 __t7NfZ245) (body (letp _00024sql4qXJ661 (aslst _00024seq2)) (letp __t1b46247 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8MNY666 __t1b46247 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0NcP667 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0X3t668 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo6VJl669 __t1b46247 _00024seq2) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join-old boolval (0 1) 1 (0 1) __t1b46247 b) (let chk7kTX963 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk7kTX963) (letp chk39Hm964 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk39Hm964)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask570 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex559;  slog::Index** $seq_atindex560;  slog::Index** $seq_atrindex561;  slog::Index** $seq_atrindex562;  slog::Index** _enumindex563;  slog::Index** boolvalindex564;  slog::Index** $seq_atdelta565;  slog::Index** $seq_atdelta566;  slog::Index** $seq_atrdelta567;  slog::Index** $seq_atrdelta568;  slog::Index** boolvaldelta569;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("delta");
      driver_index = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({1, 0, 2});
      slog::Relation* readrel574 = db->getRelation("$seq_at");
      $seq_atindex559 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 0, 2});
      slog::Relation* readrel576 = db->getRelation("$seq_at");
      $seq_atdelta565 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({1, 0, 2});
      slog::Relation* readrel578 = db->getRelation("$seq_at");
      $seq_atindex560 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0, 2});
      slog::Relation* readrel580 = db->getRelation("$seq_at");
      $seq_atdelta566 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({1, 0, 2});
      slog::Relation* readrel582 = db->getRelation("$seq_atr");
      $seq_atrindex561 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 0, 2});
      slog::Relation* readrel584 = db->getRelation("$seq_atr");
      $seq_atrdelta567 = readrel584->getIndex(ord583, true);
      std::vector<u16> ord585({1, 0, 2});
      slog::Relation* readrel586 = db->getRelation("$seq_atr");
      $seq_atrindex562 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 0, 2});
      slog::Relation* readrel588 = db->getRelation("$seq_atr");
      $seq_atrdelta568 = readrel588->getIndex(ord587, true);
      std::vector<u16> ord589({1, 0});
      slog::Relation* readrel590 = db->getRelation("_enum");
      _enumindex563 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("boolval");
      boolvalindex564 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("boolval");
      boolvaldelta569 = readrel594->getIndex(ord593, true);
  
    }
    ReadTask570(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c150 = v_const06abaa100ecef791ce028c56;
      u64 v_c151 = v_constd4735e3a265e16eee03f5971;
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
      u64 v_c153 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c154 = v_const5feceb66ffc86f38d952786c;
      u64 v_c155 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c156 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c157 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c150, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m595) {
        u64 v_c8 = m595[1];
        u64 v_c158 = m595[2];
        if (buckethash(v_c8) != bucket) return;
        bool ok596 = true;
        u64 v_c159 = _prim_aslst(db, v_c8, &ok596);
        if (!ok596) return;
        bool ok597 = true;
        u64 v_c160 = _prim_lref(db, v_c159, v_c152, &ok597);
        if (!ok597) return;
        slog::join_probe_old<3,3>($seq_atindex559, $seq_atdelta565, std::array<u64,3>{v_c154, v_c160, v_c8}, [&](const std::array<u64,3>& m598) {
          slog::join_probe_old<3,3>($seq_atindex560, $seq_atdelta566, std::array<u64,3>{v_c155, v_c160, v_c8}, [&](const std::array<u64,3>& m599) {
            slog::join_probe_old<3,3>($seq_atrindex561, $seq_atrdelta567, std::array<u64,3>{v_c156, v_c160, v_c8}, [&](const std::array<u64,3>& m600) {
              slog::join_probe_old<3,3>($seq_atrindex562, $seq_atrdelta568, std::array<u64,3>{v_c157, v_c160, v_c8}, [&](const std::array<u64,3>& m601) {
                slog::join_probe<2,1>(_enumindex563, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m602) {
                  u64 v_c161 = m602[1];
                  slog::join_probe_old<2,1>(boolvalindex564, boolvaldelta569, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m603) {
                    u64 v_c14 = m603[1];
                    u64 v_c162 = _prim_llen(db, v_c159);
                    if (v_c162 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c151 != v_c162) return;
                    bool ok604 = true;
                    u64 v_c163 = _prim_lref(db, v_c159, v_c153, &ok604);
                    if (!ok604) return;
                    if (v_c160 != v_c163) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c158});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c161}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask570* _cont = new ReadTask570(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask570(db,b), false);
  // (crule (pre (let __tconst04ab676 constcd2a69ce5ca278db1d6da969) (let _00024sqc0NDP645 constd4735e3a265e16eee03f5971) (let _00024sqc7bIa646 const5feceb66ffc86f38d952786c) (let _00024sqc1Uf7647 const6b86b273ff34fce19d6b804e) (let _00024sqo7IWL648 const5feceb66ffc86f38d952786c) (let _00024sqo5kNQ649 const6b86b273ff34fce19d6b804e) (let _00024sqo9k7p650 const6b86b273ff34fce19d6b804e) (let _00024sqo7Xo2651 const5feceb66ffc86f38d952786c)) (scan delta __t6QsA316 op _00024seq2) (body (letp _00024sql2g05643 (aslst _00024seq2)) (letp __t2qlr318 (lref _00024sql2g05643 _00024sqc7bIa646)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7IWL648 __t2qlr318 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5kNQ649 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9k7p650 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7Xo2651 __t2qlr318 _00024seq2) (join _enum (0 1) 2 __t2qlr318 __tconst04ab676) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (let chk5pjp1016 (llen _00024sql2g05643)) (eq _00024sqc0NDP645 chk5pjp1016) (letp chk5MRI1017 (lref _00024sql2g05643 _00024sqc1Uf7647)) (eq __t2qlr318 chk5MRI1017)) (head (emit-temp temp53FS1015 __t6QsA316 b) (mkstruct boolval (1 0) __t3y4C315 b)) interp.slog:112 #f)
  class ReadTask616 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex605;  slog::Index** $seq_atindex606;  slog::Index** $seq_atrindex607;  slog::Index** $seq_atrindex608;  slog::Index** _enumindex609;  slog::Index** comparison_opindex610;  slog::Index** any_boolindex611;  slog::Index** $seq_atdelta612;  slog::Index** $seq_atdelta613;  slog::Index** $seq_atrdelta614;  slog::Index** $seq_atrdelta615;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp53FS1015");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord617({1, 0, 2});
      slog::Relation* readrel618 = db->getRelation("$seq_at");
      $seq_atindex605 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0, 2});
      slog::Relation* readrel620 = db->getRelation("$seq_at");
      $seq_atdelta612 = readrel620->getIndex(ord619, true);
      std::vector<u16> ord621({1, 0, 2});
      slog::Relation* readrel622 = db->getRelation("$seq_at");
      $seq_atindex606 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 0, 2});
      slog::Relation* readrel624 = db->getRelation("$seq_at");
      $seq_atdelta613 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({1, 0, 2});
      slog::Relation* readrel626 = db->getRelation("$seq_atr");
      $seq_atrindex607 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 0, 2});
      slog::Relation* readrel628 = db->getRelation("$seq_atr");
      $seq_atrdelta614 = readrel628->getIndex(ord627, true);
      std::vector<u16> ord629({1, 0, 2});
      slog::Relation* readrel630 = db->getRelation("$seq_atr");
      $seq_atrindex608 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 0, 2});
      slog::Relation* readrel632 = db->getRelation("$seq_atr");
      $seq_atrdelta615 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({0, 1});
      slog::Relation* readrel634 = db->getRelation("_enum");
      _enumindex609 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0});
      slog::Relation* readrel636 = db->getRelation("comparison_op");
      comparison_opindex610 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({0});
      slog::Relation* readrel638 = db->getRelation("any_bool");
      any_boolindex611 = readrel638->getIndex(ord637, false);
  
    }
    ReadTask616(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c131 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c8 = _t[2];
        bool ok639 = true;
        u64 v_c132 = _prim_aslst(db, v_c8, &ok639);
        if (!ok639) return;
        bool ok640 = true;
        u64 v_c130 = _prim_lref(db, v_c132, v_c124, &ok640);
        if (!ok640) return;
        slog::join_probe_old<3,3>($seq_atindex605, $seq_atdelta612, std::array<u64,3>{v_c126, v_c130, v_c8}, [&](const std::array<u64,3>& m641) {
          slog::join_probe_old<3,3>($seq_atindex606, $seq_atdelta613, std::array<u64,3>{v_c127, v_c130, v_c8}, [&](const std::array<u64,3>& m642) {
            slog::join_probe_old<3,3>($seq_atrindex607, $seq_atrdelta614, std::array<u64,3>{v_c128, v_c130, v_c8}, [&](const std::array<u64,3>& m643) {
              slog::join_probe_old<3,3>($seq_atrindex608, $seq_atrdelta615, std::array<u64,3>{v_c129, v_c130, v_c8}, [&](const std::array<u64,3>& m644) {
                slog::join_probe<2,2>(_enumindex609, std::array<u64,2>{v_c130, v_c122}, [&](const std::array<u64,2>& m645) {
                  slog::join_probe<1,1>(comparison_opindex610, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m646) {
                    slog::join_all<1>(any_boolindex611, [&](const std::array<u64,1>& m647) {
                      u64 v_c14 = m647[0];
                      u64 v_c164 = _prim_llen(db, v_c132);
                      if (v_c164 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c123 != v_c164) return;
                      bool ok648 = true;
                      u64 v_c165 = _prim_lref(db, v_c132, v_c125, &ok648);
                      if (!ok648) return;
                      if (v_c130 != v_c165) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c131, v_c14});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
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
  // (crule (pre) (scan eval __t1acj322 __t4jyq321 c) (body (join sym (0 1) 1 __t4jyq321 s)) (head (emit-temp temp7Ldx1076 __t1acj322 s) (mkstruct symval (1 0) __t4PSF320 s)) interp.slog:28 #f)
  class ReadTask650 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex649;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Ldx1076");
      head_rel[1] = db->getRelation("symval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord651({0, 1});
      slog::Relation* readrel652 = db->getRelation("sym");
      symindex649 = readrel652->getIndex(ord651, false);
  
    }
    ReadTask650(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,1>(symindex649, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m653) {
          u64 v_c65 = m653[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c65});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c65}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:28", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask650* _cont = new ReadTask650(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask650(db,b), false);
  // (crule (pre) (scan app __t7NtH303 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t7NtH303) (join eval (1 2 0) 1 __t7NtH303 c __7p9q702) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t7NtH303 c) (join eval (1 2 0) 2 ef c __t9B5D299) (exists eval_ans (0 1) 1 __t9B5D299) (join eval_args (1 2 0) 2 es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join eval_args_ans (0 1) 1 __t6sYC302 vs) (join tick_ans (0 1) 1 __t5Pln304 l) (join closure (0 1 2) 1 __t4ng7301 __t4mHn300 cb) (join lambda (0 1 2) 1 __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask672 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex654;  slog::Index** eval_argsindex655;  slog::Index** tickindex656;  slog::Index** evalindex657;  slog::Index** eval_argsindex658;  slog::Index** tickindex659;  slog::Index** evalindex660;  slog::Index** eval_ansindex661;  slog::Index** eval_argsindex662;  slog::Index** eval_args_ansindex663;  slog::Index** tickindex664;  slog::Index** tick_ansindex665;  slog::Index** eval_ansindex666;  slog::Index** eval_args_ansindex667;  slog::Index** tick_ansindex668;  slog::Index** closureindex669;  slog::Index** lambdaindex670;  slog::Index** tickdelta671;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord673({0, 1, 2, 3});
      slog::Relation* readrel674 = db->getRelation("bind_params");
      head_index[0] = readrel674->getIndex(ord673, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord675({0, 1});
      slog::Relation* readrel676 = db->getRelation("call_event");
      head_index[1] = readrel676->getIndex(ord675, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord677({1, 2, 0});
      slog::Relation* readrel678 = db->getRelation("eval");
      evalindex654 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 2, 0});
      slog::Relation* readrel680 = db->getRelation("eval_args");
      eval_argsindex655 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 2, 0});
      slog::Relation* readrel682 = db->getRelation("tick");
      tickindex656 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({1, 2, 0});
      slog::Relation* readrel684 = db->getRelation("eval");
      evalindex657 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({1, 2, 0});
      slog::Relation* readrel686 = db->getRelation("eval_args");
      eval_argsindex658 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("tick");
      tickindex659 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("eval");
      evalindex660 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({0, 1});
      slog::Relation* readrel692 = db->getRelation("eval_ans");
      eval_ansindex661 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("eval_args");
      eval_argsindex662 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("eval_args_ans");
      eval_args_ansindex663 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 2, 0});
      slog::Relation* readrel698 = db->getRelation("tick");
      tickindex664 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("tick");
      tickdelta671 = readrel700->getIndex(ord699, true);
      std::vector<u16> ord701({0, 1});
      slog::Relation* readrel702 = db->getRelation("tick_ans");
      tick_ansindex665 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({0, 1});
      slog::Relation* readrel704 = db->getRelation("eval_ans");
      eval_ansindex666 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("eval_args_ans");
      eval_args_ansindex667 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("tick_ans");
      tick_ansindex668 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({0, 1, 2});
      slog::Relation* readrel710 = db->getRelation("closure");
      closureindex669 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 1, 2});
      slog::Relation* readrel712 = db->getRelation("lambda");
      lambdaindex670 = readrel712->getIndex(ord711, false);
  
    }
    ReadTask672(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c144 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c41 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex654, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex655, std::array<u64,3>{v_c41, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex656, std::array<u64,3>{v_c144, 0, 0})) return;
        slog::join_probe<3,1>(evalindex657, std::array<u64,3>{v_c144, 0, 0}, [&](const std::array<u64,3>& m713) {
          u64 v_c19 = m713[1]; u64 v_c143 = m713[2];
          if (!slog::exists_probe<3,2>(eval_argsindex658, std::array<u64,3>{v_c41, v_c19, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex659, std::array<u64,3>{v_c144, v_c19, 0})) return;
          slog::join_probe<3,2>(evalindex660, std::array<u64,3>{v_c48, v_c19, 0}, [&](const std::array<u64,3>& m714) {
            u64 v_c142 = m714[2];
            if (!slog::exists_probe<2,1>(eval_ansindex661, std::array<u64,2>{v_c142, 0})) return;
            slog::join_probe<3,2>(eval_argsindex662, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m715) {
              u64 v_c145 = m715[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex663, std::array<u64,2>{v_c145, 0})) return;
              slog::join_probe_old<3,2>(tickindex664, tickdelta671, std::array<u64,3>{v_c144, v_c19, 0}, [&](const std::array<u64,3>& m716) {
                u64 v_c146 = m716[2];
                if (!slog::exists_probe<2,1>(tick_ansindex665, std::array<u64,2>{v_c146, 0})) return;
                slog::join_probe<2,1>(eval_ansindex666, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m717) {
                  u64 v_c140 = m717[1];
                  slog::join_probe<2,1>(eval_args_ansindex667, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m718) {
                    u64 v_c44 = m718[1];
                    slog::join_probe<2,1>(tick_ansindex668, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m719) {
                      u64 v_c147 = m719[1];
                      slog::join_probe<3,1>(closureindex669, std::array<u64,3>{v_c140, 0, 0}, [&](const std::array<u64,3>& m720) {
                        u64 v_c141 = m720[1]; u64 v_c13 = m720[2];
                        slog::join_probe<3,1>(lambdaindex670, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m721) {
                          u64 v_c148 = m721[1]; u64 v_c20 = m721[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c148, v_c44, v_c147, v_c19}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c147, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask672* _cont = new ReadTask672(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask672(db,b), false);
  // (crule (pre (let __tconst0ib5704 constcd2a69ce5ca278db1d6da969)) (scan eval __t3VNp10 __t93te9 c) (body (join _enum (1 0) 1 __tconst0ib5704 __t5HyQ8) (join num (0 1) 1 __t93te9 n)) (head (emit eval_ans (0 1) __t3VNp10 __t5HyQ8)) interp.slog:26 #f)
  class ReadTask724 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex722;  slog::Index** numindex723;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord725({0, 1});
      slog::Relation* readrel726 = db->getRelation("eval_ans");
      head_index[0] = readrel726->getIndex(ord725, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord727({1, 0});
      slog::Relation* readrel728 = db->getRelation("_enum");
      _enumindex722 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({0, 1});
      slog::Relation* readrel730 = db->getRelation("num");
      numindex723 = readrel730->getIndex(ord729, false);
  
    }
    ReadTask724(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c166 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c167 = _t[0];
        u64 v_c168 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,1>(_enumindex722, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m731) {
          u64 v_c169 = m731[1];
          slog::join_probe<2,1>(numindex723, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m732) {
            u64 v_c170 = m732[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c167, v_c169}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask724* _cont = new ReadTask724(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask724(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst88d3359 const6b86b273ff34fce19d6b804e)) (scan temp6QrZ1116 __t3xwX335 __t4CVz374 __t5Ha7358 __t72Zs370) (body (exists num (1 0) 1 __tconst88d3359) (join if (1 3 2 0) 2 __t72Zs370 __t5Ha7358 __t29aP337 __t6p3G371) (join num (0 1) 2 __t29aP337 __tconst88d3359)) (head (emit-temp temp88Gk1117 __t3xwX335 __t4CVz374 __t6p3G371) (mkstruct lambda (1 2 0) __t8yYt375 __t4CVz374 __t6p3G371)) schemecfa.slog:12 #f)
  class ReadTask736 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex733;  slog::Index** ifindex734;  slog::Index** numindex735;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp88Gk1117");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp6QrZ1116");
      std::vector<u16> ord737({1, 0});
      slog::Relation* readrel738 = db->getRelation("num");
      numindex733 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 3, 2, 0});
      slog::Relation* readrel740 = db->getRelation("if");
      ifindex734 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({0, 1});
      slog::Relation* readrel742 = db->getRelation("num");
      numindex735 = readrel742->getIndex(ord741, false);
  
    }
    ReadTask736(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_consta81ad7556291f9defc5163ec;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c105 = _t[0];
        u64 v_c106 = _t[1];
        u64 v_c171 = _t[2];
        u64 v_c107 = _t[3];
        if (!slog::exists_probe<2,1>(numindex733, std::array<u64,2>{v_c103, 0})) return;
        slog::join_probe<4,2>(ifindex734, std::array<u64,4>{v_c107, v_c171, 0, 0}, [&](const std::array<u64,4>& m743) {
          u64 v_c110 = m743[2]; u64 v_c172 = m743[3];
          slog::join_probe<2,2>(numindex735, std::array<u64,2>{v_c110, v_c103}, [&](const std::array<u64,2>& m744) {
            ++_fires;
            slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c105, v_c106, v_c172});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c106, v_c172}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp6QrZ1116", _fires);
  
      if (!_done)
      {
        ReadTask736* _cont = new ReadTask736(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask736(db,b), false);
  // (crule (pre) (scan eval __5LXb801 __t0Aad241 c) (body (join-old app (0 1 2) 1 (0 1 2) __t0Aad241 ef es)) (head (mkstruct eval_args (1 2 0) __66Zv802 es c)) interp.slog:48 #f)
  class ReadTask747 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex745;  slog::Index** appdelta746;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord748({0, 1, 2});
      slog::Relation* readrel749 = db->getRelation("app");
      appindex745 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({0, 1, 2});
      slog::Relation* readrel751 = db->getRelation("app");
      appdelta746 = readrel751->getIndex(ord750, true);
  
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
        u64 v_c173 = _t[0];
        u64 v_c174 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe_old<3,1>(appindex745, appdelta746, std::array<u64,3>{v_c174, 0, 0}, [&](const std::array<u64,3>& m752) {
          u64 v_c48 = m752[1]; u64 v_c41 = m752[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c41, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst3nEA343 const0933fb667296882d8c45abca) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e) (let __tconst2t4L361 const5feceb66ffc86f38d952786c) (let __tconst8nL2368 const90fb9068eda6f2d68bb61c33)) (scan temp7tzo1109 __t0Kjq332 __t2xne366 __t4CVz374 __t6UsA373) (body (exists num (1 0) 1 __tconst2t4L361) (exists ref (1 0) 1 __tconst0pCN356) (exists ref (1 0) 1 __tconst3nEA343) (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (join ref (1 0) 1 __tconst8nL2368 __t5g5j369) (join num (1 0) 1 __tconst2t4L361 __t9AJk362) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join ref (1 0) 1 __tconst3nEA343 __t85N1344) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334) (let __t0UW1342 (lpush __t2xne366 __t29aP337)) (let __t65kJ367 (lpush __t2xne366 __t9AJk362))) (head (emit-temp temp7hN01110 __t0Kjq332 __t0UW1342 __t2xne366 __t4CVz374 __t65kJ367 __t6UsA373) (mkstruct app (1 2 0) __t3xwX335 __t7cCj334 __t0Kjq332)) schemecfa.slog:12 #f)
  class ReadTask764 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex753;  slog::Index** refindex754;  slog::Index** refindex755;  slog::Index** numindex756;  slog::Index** refindex757;  slog::Index** refindex758;  slog::Index** numindex759;  slog::Index** refindex760;  slog::Index** refindex761;  slog::Index** numindex762;  slog::Index** refindex763;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7hN01110");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp7tzo1109");
      std::vector<u16> ord765({1, 0});
      slog::Relation* readrel766 = db->getRelation("num");
      numindex753 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 0});
      slog::Relation* readrel768 = db->getRelation("ref");
      refindex754 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0});
      slog::Relation* readrel770 = db->getRelation("ref");
      refindex755 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 0});
      slog::Relation* readrel772 = db->getRelation("num");
      numindex756 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 0});
      slog::Relation* readrel774 = db->getRelation("ref");
      refindex757 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 0});
      slog::Relation* readrel776 = db->getRelation("ref");
      refindex758 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 0});
      slog::Relation* readrel778 = db->getRelation("num");
      numindex759 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 0});
      slog::Relation* readrel780 = db->getRelation("ref");
      refindex760 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 0});
      slog::Relation* readrel782 = db->getRelation("ref");
      refindex761 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 0});
      slog::Relation* readrel784 = db->getRelation("num");
      numindex762 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 0});
      slog::Relation* readrel786 = db->getRelation("ref");
      refindex763 = readrel786->getIndex(ord785, false);
  
    }
    ReadTask764(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_consta81ad7556291f9defc5163ec;
      u64 v_c175 = v_const0933fb667296882d8c45abca;
      u64 v_c102 = v_consted725292f5f32d61535958c1;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_const90fb9068eda6f2d68bb61c33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c178 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c106 = _t[2];
        u64 v_c179 = _t[3];
        if (!slog::exists_probe<2,1>(numindex753, std::array<u64,2>{v_c176, 0})) return;
        if (!slog::exists_probe<2,1>(refindex754, std::array<u64,2>{v_c102, 0})) return;
        if (!slog::exists_probe<2,1>(refindex755, std::array<u64,2>{v_c175, 0})) return;
        if (!slog::exists_probe<2,1>(numindex756, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex757, std::array<u64,2>{v_c101, 0})) return;
        slog::join_probe<2,1>(refindex758, std::array<u64,2>{v_c177, 0}, [&](const std::array<u64,2>& m787) {
          u64 v_c180 = m787[1];
          slog::join_probe<2,1>(numindex759, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m788) {
            u64 v_c181 = m788[1];
            slog::join_probe<2,1>(refindex760, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m789) {
              u64 v_c109 = m789[1];
              slog::join_probe<2,1>(refindex761, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m790) {
                u64 v_c182 = m790[1];
                slog::join_probe<2,1>(numindex762, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m791) {
                  u64 v_c110 = m791[1];
                  slog::join_probe<2,1>(refindex763, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m792) {
                    u64 v_c111 = m792[1];
                    u64 v_c183 = _prim_lpush(db, v_c104, v_c110);
                    if (v_c183 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                    u64 v_c184 = _prim_lpush(db, v_c104, v_c181);
                    if (v_c184 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c178, v_c183, v_c104, v_c106, v_c184, v_c179});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c111, v_c178}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp7tzo1109", _fires);
  
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
  // (crule (pre (let __tconst0jqw13 const6b86b273ff34fce19d6b804e) (let __trid8KnT728 const71dc04e9084b526ffd253a28) (let __trel0zIA729 const00b70a53bc33238570e12d7a) (let __tcol1EuT730 const5feceb66ffc86f38d952786c)) (scan freevar x eb) (body (exists lst_absent (2 0 1) 1 x) (exists lambda (2 0 1) 1 eb) (join-old lst_absent_ans (1 0) 1 (1 0) __tconst0jqw13 __t4tDv12) (join-old lst_absent (0 2 1) 2 (0 2 1) __t4tDv12 x xs) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t2Cl511)) (head (tycheck x (accept str) __trid8KnT728 __trel0zIA729 __tcol1EuT730 (1 2 3 4 0)) (emit freevar (0 1) x __t2Cl511)) freevars.slog:28 #f)
  class ReadTask801 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absentindex793;  slog::Index** lambdaindex794;  slog::Index** lst_absent_ansindex795;  slog::Index** lst_absentindex796;  slog::Index** lambdaindex797;  slog::Index** lst_absent_ansdelta798;  slog::Index** lst_absentdelta799;  slog::Index** lambdadelta800;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord802({0, 1});
      slog::Relation* readrel803 = db->getRelation("freevar");
      head_index[1] = readrel803->getIndex(ord802, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord804({2, 0, 1});
      slog::Relation* readrel805 = db->getRelation("lst_absent");
      lst_absentindex793 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({2, 0, 1});
      slog::Relation* readrel807 = db->getRelation("lambda");
      lambdaindex794 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 0});
      slog::Relation* readrel809 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex795 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 0});
      slog::Relation* readrel811 = db->getRelation("lst_absent_ans");
      lst_absent_ansdelta798 = readrel811->getIndex(ord810, true);
      std::vector<u16> ord812({0, 2, 1});
      slog::Relation* readrel813 = db->getRelation("lst_absent");
      lst_absentindex796 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 2, 1});
      slog::Relation* readrel815 = db->getRelation("lst_absent");
      lst_absentdelta799 = readrel815->getIndex(ord814, true);
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("lambda");
      lambdaindex797 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("lambda");
      lambdadelta800 = readrel819->getIndex(ord818, true);
  
    }
    ReadTask801(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_const71dc04e9084b526ffd253a28;
      u64 v_c187 = v_const00b70a53bc33238570e12d7a;
      u64 v_c188 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c20 = _t[1];
        if (!slog::exists_probe<3,1>(lst_absentindex793, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex794, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe_old<2,1>(lst_absent_ansindex795, lst_absent_ansdelta798, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m820) {
          u64 v_c189 = m820[1];
          slog::join_probe_old<3,2>(lst_absentindex796, lst_absentdelta799, std::array<u64,3>{v_c189, v_c23, 0}, [&](const std::array<u64,3>& m821) {
            u64 v_c148 = m821[2];
            slog::join_probe_old<3,2>(lambdaindex797, lambdadelta800, std::array<u64,3>{v_c148, v_c20, 0}, [&](const std::array<u64,3>& m822) {
              u64 v_c190 = m822[2];
              ++_fires;
              if (!(is_str(v_c23)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c186, v_c187, v_c188, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c190}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask801* _cont = new ReadTask801(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask801(db,b), false);
  // (crule (pre (let __trid7JOP768 const2a09f8e08b8d8243373579d9) (let __trel5M7g769 const0bbd2fbd1dc4200473343503) (let __tcol25Yj770 const5feceb66ffc86f38d952786c)) (scan eval __t4BlY180 __t3YjV179 c) (body (join lambda (0 1 2) 1 __t3YjV179 xs eb)) (head (tycheck __t3YjV179 (accept (struct lambda)) __trid7JOP768 __trel5M7g769 __tcol25Yj770 (1 2 3 4 0)) (emit-temp temp2RWj1119 __t3YjV179 __t4BlY180 c) (mkstruct closure (1 2 0) __t7vnx178 __t3YjV179 c)) interp.slog:29 #f)
  class ReadTask825 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex823;
    u32 sid824;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp2RWj1119");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord826({0, 1, 2});
      slog::Relation* readrel827 = db->getRelation("lambda");
      lambdaindex823 = readrel827->getIndex(ord826, false);
      sid824 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask825(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c191 = v_const2a09f8e08b8d8243373579d9;
      u64 v_c192 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c193 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c194 = _t[0];
        u64 v_c195 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<3,1>(lambdaindex823, std::array<u64,3>{v_c195, 0, 0}, [&](const std::array<u64,3>& m828) {
          u64 v_c148 = m828[1]; u64 v_c20 = m828[2];
          ++_fires;
          if (!((is_struct(v_c195) && (decode_struct_id(v_c195) == sid824))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c191, v_c192, v_c193, v_c195}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c195, v_c194, v_c19});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c195, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval_args_ans __t6sYC302 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t6sYC302 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (2 0 1) 2 (2 0 1) es __t7NtH303 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t9B5D299) (exists eval_ans (0 1) 1 __t9B5D299) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join eval_ans (0 1) 1 __t9B5D299 __t4ng7301) (join-old tick_ans (0 1) 1 (0 1) __t5Pln304 l) (join-old closure (0 1 2) 1 (0 1 2) __t4ng7301 __t4mHn300 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask851 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex829;  slog::Index** appindex830;  slog::Index** evalindex831;  slog::Index** tickindex832;  slog::Index** evalindex833;  slog::Index** tickindex834;  slog::Index** appindex835;  slog::Index** evalindex836;  slog::Index** eval_ansindex837;  slog::Index** tickindex838;  slog::Index** tick_ansindex839;  slog::Index** eval_ansindex840;  slog::Index** tick_ansindex841;  slog::Index** closureindex842;  slog::Index** lambdaindex843;  slog::Index** eval_argsdelta844;  slog::Index** appdelta845;  slog::Index** evaldelta846;  slog::Index** tickdelta847;  slog::Index** tick_ansdelta848;  slog::Index** closuredelta849;  slog::Index** lambdadelta850;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord852({0, 1, 2, 3});
      slog::Relation* readrel853 = db->getRelation("bind_params");
      head_index[0] = readrel853->getIndex(ord852, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord854({0, 1});
      slog::Relation* readrel855 = db->getRelation("call_event");
      head_index[1] = readrel855->getIndex(ord854, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord856({0, 2, 1});
      slog::Relation* readrel857 = db->getRelation("eval_args");
      eval_argsindex829 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 2, 1});
      slog::Relation* readrel859 = db->getRelation("eval_args");
      eval_argsdelta844 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({2, 0, 1});
      slog::Relation* readrel861 = db->getRelation("app");
      appindex830 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({2, 0, 1});
      slog::Relation* readrel863 = db->getRelation("eval");
      evalindex831 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({2, 0, 1});
      slog::Relation* readrel865 = db->getRelation("tick");
      tickindex832 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({2, 0, 1});
      slog::Relation* readrel867 = db->getRelation("eval");
      evalindex833 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({1, 2, 0});
      slog::Relation* readrel869 = db->getRelation("tick");
      tickindex834 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({2, 0, 1});
      slog::Relation* readrel871 = db->getRelation("app");
      appindex835 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({2, 0, 1});
      slog::Relation* readrel873 = db->getRelation("app");
      appdelta845 = readrel873->getIndex(ord872, true);
      std::vector<u16> ord874({1, 2, 0});
      slog::Relation* readrel875 = db->getRelation("eval");
      evalindex836 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 2, 0});
      slog::Relation* readrel877 = db->getRelation("eval");
      evaldelta846 = readrel877->getIndex(ord876, true);
      std::vector<u16> ord878({0, 1});
      slog::Relation* readrel879 = db->getRelation("eval_ans");
      eval_ansindex837 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({1, 2, 0});
      slog::Relation* readrel881 = db->getRelation("tick");
      tickindex838 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 0});
      slog::Relation* readrel883 = db->getRelation("tick");
      tickdelta847 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({0, 1});
      slog::Relation* readrel885 = db->getRelation("tick_ans");
      tick_ansindex839 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({0, 1});
      slog::Relation* readrel887 = db->getRelation("eval_ans");
      eval_ansindex840 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({0, 1});
      slog::Relation* readrel889 = db->getRelation("tick_ans");
      tick_ansindex841 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({0, 1});
      slog::Relation* readrel891 = db->getRelation("tick_ans");
      tick_ansdelta848 = readrel891->getIndex(ord890, true);
      std::vector<u16> ord892({0, 1, 2});
      slog::Relation* readrel893 = db->getRelation("closure");
      closureindex842 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({0, 1, 2});
      slog::Relation* readrel895 = db->getRelation("closure");
      closuredelta849 = readrel895->getIndex(ord894, true);
      std::vector<u16> ord896({0, 1, 2});
      slog::Relation* readrel897 = db->getRelation("lambda");
      lambdaindex843 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({0, 1, 2});
      slog::Relation* readrel899 = db->getRelation("lambda");
      lambdadelta850 = readrel899->getIndex(ord898, true);
  
    }
    ReadTask851(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c145 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex829, eval_argsdelta844, std::array<u64,3>{v_c145, 0, 0}, [&](const std::array<u64,3>& m900) {
          u64 v_c19 = m900[1]; u64 v_c41 = m900[2];
          if (!slog::exists_probe<3,1>(appindex830, std::array<u64,3>{v_c41, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex831, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex832, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<3,1>(evalindex833, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m901) {
            u64 v_c143 = m901[1]; u64 v_c144 = m901[2];
            if (!slog::exists_probe<3,2>(tickindex834, std::array<u64,3>{v_c144, v_c19, 0})) return;
            slog::join_probe_old<3,2>(appindex835, appdelta845, std::array<u64,3>{v_c41, v_c144, 0}, [&](const std::array<u64,3>& m902) {
              u64 v_c48 = m902[2];
              slog::join_probe_old<3,2>(evalindex836, evaldelta846, std::array<u64,3>{v_c48, v_c19, 0}, [&](const std::array<u64,3>& m903) {
                u64 v_c142 = m903[2];
                if (!slog::exists_probe<2,1>(eval_ansindex837, std::array<u64,2>{v_c142, 0})) return;
                slog::join_probe_old<3,2>(tickindex838, tickdelta847, std::array<u64,3>{v_c144, v_c19, 0}, [&](const std::array<u64,3>& m904) {
                  u64 v_c146 = m904[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex839, std::array<u64,2>{v_c146, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex840, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m905) {
                    u64 v_c140 = m905[1];
                    slog::join_probe_old<2,1>(tick_ansindex841, tick_ansdelta848, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m906) {
                      u64 v_c147 = m906[1];
                      slog::join_probe_old<3,1>(closureindex842, closuredelta849, std::array<u64,3>{v_c140, 0, 0}, [&](const std::array<u64,3>& m907) {
                        u64 v_c141 = m907[1]; u64 v_c13 = m907[2];
                        slog::join_probe_old<3,1>(lambdaindex843, lambdadelta850, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m908) {
                          u64 v_c148 = m908[1]; u64 v_c20 = m908[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c148, v_c44, v_c147, v_c19}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c147, v_c19}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval_args_ans", _fires);
  
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
  // (crule (pre (let __tconst4Btx248 const4e07408562bedb8b60ce05c1) (let __tconst1yQ3255 const6b86b273ff34fce19d6b804e) (let __tconst5n8U262 const0933fb667296882d8c45abca) (let __tconst0jEK272 const37664d5895f78758ec8e94e4) (let __tconst6yT0276 const5feceb66ffc86f38d952786c) (let __tconst3Rob283 const90fb9068eda6f2d68bb61c33) (let __tconst2l7U287 consta05447c5b6502c5938db0f77) (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9) (let __t6t5b288 (lempty))) (once) (body) (head (emit-temp temp6Rvt1049 __t6t5b288) (mkstruct num (1 0) __t4N0a249 __tconst4Btx248) (mkstruct ref (1 0) __t8oYB253 __tconst4G37291) (mkstruct num (1 0) __t5z2C256 __tconst1yQ3255) (mkstruct ref (1 0) __t0OCP258 __tconst2l7U287) (mkstruct ref (1 0) __t4C1l263 __tconst5n8U262) (mkstruct ref (1 0) __t42iX271 __tconst0jEK272) (mkstruct num (1 0) __t0Xcv277 __tconst6yT0276) (mkstruct ref (1 0) __t88QE284 __tconst3Rob283)) schemecfa.slog:70 #f)
  class ReadTask909 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[9];
    slog::Index** head_index[9];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6Rvt1049");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("num");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("num");
      head_rel[8] = db->getRelation("ref");
  
    }
    ReadTask909(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c197 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c198 = v_const0933fb667296882d8c45abca;
      u64 v_c199 = v_const37664d5895f78758ec8e94e4;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
      u64 v_c201 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c202 = v_consta05447c5b6502c5938db0f77;
      u64 v_c203 = v_const889c19fd926bc4ca61c0b4d9;
      u64 v_c204 = _prim_lempty(db);
      if (v_c204 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[9];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c204});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c196}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c203}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c197}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c202}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c198}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c199}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c200}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c201}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask909(db,b), true);
  // (crule (pre) (scan freevar x e1) (body (join-old if (1 3 2 0) 1 (1 3 2 0) e1 e3 e2 __t1rOw325)) (head (emit freevar (0 1) x __t1rOw325)) freevars.slog:17 #f)
  class ReadTask912 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex910;  slog::Index** ifdelta911;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord913({0, 1});
      slog::Relation* readrel914 = db->getRelation("freevar");
      head_index[0] = readrel914->getIndex(ord913, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord915({1, 3, 2, 0});
      slog::Relation* readrel916 = db->getRelation("if");
      ifindex910 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 3, 2, 0});
      slog::Relation* readrel918 = db->getRelation("if");
      ifdelta911 = readrel918->getIndex(ord917, true);
  
    }
    ReadTask912(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c113 = _t[1];
        slog::join_probe_old<4,1>(ifindex910, ifdelta911, std::array<u64,4>{v_c113, 0, 0, 0}, [&](const std::array<u64,4>& m919) {
          u64 v_c115 = m919[1]; u64 v_c114 = m919[2]; u64 v_c205 = m919[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c205}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
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
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5)) (scan temp2ZI81174 __t0QD8426 __t2wub408) (body (join let (2 1 3 0) 3 __t0QD8426 __tconst1UOH427 __t2wub408 __t3BHe428)) (head (emit program (0) __t3BHe428)) schemecfa.slog:26 #f)
  class ReadTask921 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex920;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord922({0});
      slog::Relation* readrel923 = db->getRelation("program");
      head_index[0] = readrel923->getIndex(ord922, false);
      outer_rel = db->getRelation("temp2ZI81174");
      std::vector<u16> ord924({2, 1, 3, 0});
      slog::Relation* readrel925 = db->getRelation("let");
      letindex920 = readrel925->getIndex(ord924, false);
  
    }
    ReadTask921(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const0457bba0679825d285ef7fa5;
  
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
        slog::join_probe<4,3>(letindex920, std::array<u64,4>{v_c207, v_c206, v_c208, 0}, [&](const std::array<u64,4>& m926) {
          u64 v_c209 = m926[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c209}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp2ZI81174", _fires);
  
      if (!_done)
      {
        ReadTask921* _cont = new ReadTask921(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask921(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e)) (scan temp1KBC1113 __t2xne366 __t3xwX335 __t4CVz374 __t72Zs370 __t9cbk347) (body (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (exists app (2 0 1) 1 __t9cbk347) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334) (join app (1 2 0) 2 __t7cCj334 __t9cbk347 __t3As1350) (let __t7Mqx355 (lpush __t2xne366 __t3As1350))) (head (emit-temp temp3NtF1114 __t3xwX335 __t4CVz374 __t72Zs370 __t7Mqx355)) schemecfa.slog:12 #f)
  class ReadTask934 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex927;  slog::Index** refindex928;  slog::Index** appindex929;  slog::Index** refindex930;  slog::Index** numindex931;  slog::Index** refindex932;  slog::Index** appindex933;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3NtF1114");
      outer_rel = db->getRelation("temp1KBC1113");
      std::vector<u16> ord935({1, 0});
      slog::Relation* readrel936 = db->getRelation("num");
      numindex927 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 0});
      slog::Relation* readrel938 = db->getRelation("ref");
      refindex928 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({2, 0, 1});
      slog::Relation* readrel940 = db->getRelation("app");
      appindex929 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({1, 0});
      slog::Relation* readrel942 = db->getRelation("ref");
      refindex930 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0});
      slog::Relation* readrel944 = db->getRelation("num");
      numindex931 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 0});
      slog::Relation* readrel946 = db->getRelation("ref");
      refindex932 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("app");
      appindex933 = readrel948->getIndex(ord947, false);
  
    }
    ReadTask934(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_consta81ad7556291f9defc5163ec;
      u64 v_c102 = v_consted725292f5f32d61535958c1;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c107 = _t[3];
        u64 v_c108 = _t[4];
        if (!slog::exists_probe<2,1>(numindex927, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex928, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(appindex929, std::array<u64,3>{v_c108, 0, 0})) return;
        slog::join_probe<2,1>(refindex930, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m949) {
          u64 v_c109 = m949[1];
          slog::join_probe<2,1>(numindex931, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m950) {
            u64 v_c110 = m950[1];
            slog::join_probe<2,1>(refindex932, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m951) {
              u64 v_c111 = m951[1];
              slog::join_probe<3,2>(appindex933, std::array<u64,3>{v_c111, v_c108, 0}, [&](const std::array<u64,3>& m952) {
                u64 v_c210 = m952[2];
                u64 v_c211 = _prim_lpush(db, v_c104, v_c210);
                if (v_c211 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                ++_fires;
                slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c105, v_c106, v_c107, v_c211});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp1KBC1113", _fires);
  
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
  // (crule (pre) (scan select_branch __t8m22105 __v0 e2 e3) (body (exists $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3) (exists eval_ans (1 0) 1 __v0) (exists select_branch_ans (0 1) 1 __t8m22105) (join if (2 3 0 1) 2 e2 e3 __t2D2o102 e1) (exists eval (1 2 0) 1 __t2D2o102) (exists eval (1 2 0) 1 e1) (join $sup56712x86x0x0x0 (3 4 2 0 1) 3 e2 e3 e1 __t9HBz103 c) (join eval (0 2 1) 3 __t9HBz103 c __t2D2o102) (exists eval (2 0 1) 1 c) (join eval (1 2 0) 2 e1 c __t0Z2s104) (join eval_ans (0 1) 2 __t0Z2s104 __v0) (join select_branch_ans (0 1) 1 __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join eval_ans (0 1) 1 __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask968 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x86x0x0x0index953;  slog::Index** eval_ansindex954;  slog::Index** select_branch_ansindex955;  slog::Index** ifindex956;  slog::Index** evalindex957;  slog::Index** evalindex958;  slog::Index** $sup56712x86x0x0x0index959;  slog::Index** evalindex960;  slog::Index** evalindex961;  slog::Index** evalindex962;  slog::Index** eval_ansindex963;  slog::Index** select_branch_ansindex964;  slog::Index** evalindex965;  slog::Index** eval_ansindex966;  slog::Index** evaldelta967;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("eval_ans");
      head_index[0] = readrel970->getIndex(ord969, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord971({3, 4, 2, 0, 1});
      slog::Relation* readrel972 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index953 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({1, 0});
      slog::Relation* readrel974 = db->getRelation("eval_ans");
      eval_ansindex954 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 1});
      slog::Relation* readrel976 = db->getRelation("select_branch_ans");
      select_branch_ansindex955 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({2, 3, 0, 1});
      slog::Relation* readrel978 = db->getRelation("if");
      ifindex956 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({1, 2, 0});
      slog::Relation* readrel980 = db->getRelation("eval");
      evalindex957 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 2, 0});
      slog::Relation* readrel982 = db->getRelation("eval");
      evalindex958 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({3, 4, 2, 0, 1});
      slog::Relation* readrel984 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index959 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({0, 2, 1});
      slog::Relation* readrel986 = db->getRelation("eval");
      evalindex960 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({2, 0, 1});
      slog::Relation* readrel988 = db->getRelation("eval");
      evalindex961 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 2, 0});
      slog::Relation* readrel990 = db->getRelation("eval");
      evalindex962 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({0, 1});
      slog::Relation* readrel992 = db->getRelation("eval_ans");
      eval_ansindex963 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({0, 1});
      slog::Relation* readrel994 = db->getRelation("select_branch_ans");
      select_branch_ansindex964 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 0});
      slog::Relation* readrel996 = db->getRelation("eval");
      evalindex965 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 2, 0});
      slog::Relation* readrel998 = db->getRelation("eval");
      evaldelta967 = readrel998->getIndex(ord997, true);
      std::vector<u16> ord999({0, 1});
      slog::Relation* readrel1000 = db->getRelation("eval_ans");
      eval_ansindex966 = readrel1000->getIndex(ord999, false);
  
    }
    ReadTask968(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c212 = _t[0];
        u64 v_c117 = _t[1];
        u64 v_c114 = _t[2];
        u64 v_c115 = _t[3];
        if (!slog::exists_probe<5,2>($sup56712x86x0x0x0index953, std::array<u64,5>{v_c114, v_c115, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex954, std::array<u64,2>{v_c117, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex955, std::array<u64,2>{v_c212, 0})) return;
        slog::join_probe<4,2>(ifindex956, std::array<u64,4>{v_c114, v_c115, 0, 0}, [&](const std::array<u64,4>& m1001) {
          u64 v_c213 = m1001[2]; u64 v_c113 = m1001[3];
          if (!slog::exists_probe<3,1>(evalindex957, std::array<u64,3>{v_c213, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex958, std::array<u64,3>{v_c113, 0, 0})) return;
          slog::join_probe<5,3>($sup56712x86x0x0x0index959, std::array<u64,5>{v_c114, v_c115, v_c113, 0, 0}, [&](const std::array<u64,5>& m1002) {
            u64 v_c214 = m1002[3]; u64 v_c19 = m1002[4];
            slog::join_probe<3,3>(evalindex960, std::array<u64,3>{v_c214, v_c19, v_c213}, [&](const std::array<u64,3>& m1003) {
              if (!slog::exists_probe<3,1>(evalindex961, std::array<u64,3>{v_c19, 0, 0})) return;
              slog::join_probe<3,2>(evalindex962, std::array<u64,3>{v_c113, v_c19, 0}, [&](const std::array<u64,3>& m1004) {
                u64 v_c215 = m1004[2];
                slog::join_probe<2,2>(eval_ansindex963, std::array<u64,2>{v_c215, v_c117}, [&](const std::array<u64,2>& m1005) {
                  slog::join_probe<2,1>(select_branch_ansindex964, std::array<u64,2>{v_c212, 0}, [&](const std::array<u64,2>& m1006) {
                    u64 v_c118 = m1006[1];
                    slog::join_probe_old<3,2>(evalindex965, evaldelta967, std::array<u64,3>{v_c118, v_c19, 0}, [&](const std::array<u64,3>& m1007) {
                      u64 v_c216 = m1007[2];
                      slog::join_probe<2,1>(eval_ansindex966, std::array<u64,2>{v_c216, 0}, [&](const std::array<u64,2>& m1008) {
                        u64 v_c217 = m1008[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c217}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask968* _cont = new ReadTask968(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask968(db,b), false);
  // (crule (pre (let __tconst0jqw13 const6b86b273ff34fce19d6b804e) (let __trid8KnT728 const71dc04e9084b526ffd253a28) (let __trel0zIA729 const00b70a53bc33238570e12d7a) (let __tcol1EuT730 const5feceb66ffc86f38d952786c)) (probe lst_absent_ans (1 0) 1 __tconst0jqw13 __t4tDv12) (body (join-old lst_absent (0 2 1) 1 (0 2 1) __t4tDv12 x xs) (exists lambda (1 2 0) 1 xs) (join freevar (0 1) 1 x eb) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t2Cl511)) (head (tycheck x (accept str) __trid8KnT728 __trel0zIA729 __tcol1EuT730 (1 2 3 4 0)) (emit freevar (0 1) x __t2Cl511)) freevars.slog:28 #f)
  class ReadTask1015 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lst_absentindex1009;  slog::Index** lambdaindex1010;  slog::Index** freevarindex1011;  slog::Index** lambdaindex1012;  slog::Index** lst_absentdelta1013;  slog::Index** lambdadelta1014;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord1016({0, 1});
      slog::Relation* readrel1017 = db->getRelation("freevar");
      head_index[1] = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0});
      slog::Relation* readrel1019 = db->getRelation("lst_absent_ans");
      driver_index = readrel1019->getIndex(ord1018, true);
      std::vector<u16> ord1020({0, 2, 1});
      slog::Relation* readrel1021 = db->getRelation("lst_absent");
      lst_absentindex1009 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({0, 2, 1});
      slog::Relation* readrel1023 = db->getRelation("lst_absent");
      lst_absentdelta1013 = readrel1023->getIndex(ord1022, true);
      std::vector<u16> ord1024({1, 2, 0});
      slog::Relation* readrel1025 = db->getRelation("lambda");
      lambdaindex1010 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({0, 1});
      slog::Relation* readrel1027 = db->getRelation("freevar");
      freevarindex1011 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 2, 0});
      slog::Relation* readrel1029 = db->getRelation("lambda");
      lambdaindex1012 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 0});
      slog::Relation* readrel1031 = db->getRelation("lambda");
      lambdadelta1014 = readrel1031->getIndex(ord1030, true);
  
    }
    ReadTask1015(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_const71dc04e9084b526ffd253a28;
      u64 v_c187 = v_const00b70a53bc33238570e12d7a;
      u64 v_c188 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c185, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1032) {
        u64 v_c189 = m1032[1];
        if (buckethash(v_c189) != bucket) return;
        slog::join_probe_old<3,1>(lst_absentindex1009, lst_absentdelta1013, std::array<u64,3>{v_c189, 0, 0}, [&](const std::array<u64,3>& m1033) {
          u64 v_c23 = m1033[1]; u64 v_c148 = m1033[2];
          if (!slog::exists_probe<3,1>(lambdaindex1010, std::array<u64,3>{v_c148, 0, 0})) return;
          slog::join_probe<2,1>(freevarindex1011, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1034) {
            u64 v_c20 = m1034[1];
            slog::join_probe_old<3,2>(lambdaindex1012, lambdadelta1014, std::array<u64,3>{v_c148, v_c20, 0}, [&](const std::array<u64,3>& m1035) {
              u64 v_c190 = m1035[2];
              ++_fires;
              if (!(is_str(v_c23)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c186, v_c187, v_c188, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c190}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lst_absent_ans", _fires);
  
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
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp4xKX1171 __t0QMt425 __t1kdF420 __t6GQ8404) (body (exists num (1 0) 1 __tconst9Oxy387) (exists ref (1 0) 1 __tconst1UOH427) (join lambda (1 2 0) 2 __t0QMt425 __t1kdF420 __t0QD8426) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (let __t5V4O405 (lpush __t6GQ8404 __t7jad388))) (head (emit-temp temp9V7J1172 __t0QD8426 __t5V4O405)) schemecfa.slog:26 #f)
  class ReadTask1041 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1036;  slog::Index** refindex1037;  slog::Index** lambdaindex1038;  slog::Index** numindex1039;  slog::Index** refindex1040;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9V7J1172");
      outer_rel = db->getRelation("temp4xKX1171");
      std::vector<u16> ord1042({1, 0});
      slog::Relation* readrel1043 = db->getRelation("num");
      numindex1036 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 0});
      slog::Relation* readrel1045 = db->getRelation("ref");
      refindex1037 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 2, 0});
      slog::Relation* readrel1047 = db->getRelation("lambda");
      lambdaindex1038 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({1, 0});
      slog::Relation* readrel1049 = db->getRelation("num");
      numindex1039 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 0});
      slog::Relation* readrel1051 = db->getRelation("ref");
      refindex1040 = readrel1051->getIndex(ord1050, false);
  
    }
    ReadTask1041(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const0457bba0679825d285ef7fa5;
      u64 v_c218 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c219 = _t[0];
        u64 v_c220 = _t[1];
        u64 v_c221 = _t[2];
        if (!slog::exists_probe<2,1>(numindex1036, std::array<u64,2>{v_c218, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1037, std::array<u64,2>{v_c206, 0})) return;
        slog::join_probe<3,2>(lambdaindex1038, std::array<u64,3>{v_c219, v_c220, 0}, [&](const std::array<u64,3>& m1052) {
          u64 v_c207 = m1052[2];
          slog::join_probe<2,1>(numindex1039, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1053) {
            u64 v_c222 = m1053[1];
            slog::join_probe<2,1>(refindex1040, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1054) {
              u64 v_c223 = m1054[1];
              u64 v_c224 = _prim_lpush(db, v_c221, v_c222);
              if (v_c224 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
              ++_fires;
              slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c207, v_c224});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp4xKX1171", _fires);
  
      if (!_done)
      {
        ReadTask1041* _cont = new ReadTask1041(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1041(db,b), false);
  // (crule (pre (let __tconst6e41223 const6b86b273ff34fce19d6b804e)) (scan lst_absent __t9PgS221 l y) (body (let __t1sHt222 (lmem l y)) (cmp lt __t1sHt222 __tconst6e41223)) (head (emit lst_absent_ans (1 0) __tconst6e41223 __t9PgS221)) list.slog:33 #f)
  class ReadTask1055 : public slog::Task
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
      head_rel[0] = db->getRelation("lst_absent_ans");
      std::vector<u16> ord1056({1, 0});
      slog::Relation* readrel1057 = db->getRelation("lst_absent_ans");
      head_index[0] = readrel1057->getIndex(ord1056, false);
      outer_rel = db->getRelation("lst_absent");
  
    }
    ReadTask1055(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c225 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c226 = _t[0];
        u64 v_c147 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c227 = _prim_lmem(db, v_c147, v_c28);
        if (v_c227 == slog_error) { slog::emit_pending_error(db, "list.slog:33"); return; }
        u64 v_c228 = _prim_lt(db, v_c227, v_c225);
        if (v_c228 == slog_error) { slog::emit_pending_error(db, "list.slog:33"); return; }
        if (!v_c228) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c225, v_c226}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:33", "delta:lst_absent", _fires);
  
      if (!_done)
      {
        ReadTask1055* _cont = new ReadTask1055(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1055(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan eval __t25lG448 e c) (body (exists $sup56712x37x0x0x0 (2 3 0 1 4) 2 c e) (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t25lG448) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7FTM622 e _00024seq0) (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let es (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (exists eval_args (1 2 0) 2 _00024seq0 c) (exists eval_args (1 2 0) 2 es c) (join $sup56712x37x0x0x0 (0 3 4 2 1) 4 _00024seq0 e es c __t2W25447) (join eval_args (0 2 1) 3 __t2W25447 c _00024seq0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6oBa449) (exists eval_args_ans (0 1) 1 __t6oBa449) (join eval_ans (0 1) 1 __t25lG448 __v0) (join eval_args_ans (0 1) 1 __t6oBa449 __v1) (letp chk0DXH988 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk0DXH988)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask1073 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x37x0x0x0index1059;  slog::Index** eval_argsindex1060;  slog::Index** eval_ansindex1061;  slog::Index** $seq_atindex1062;  slog::Index** eval_argsindex1063;  slog::Index** eval_argsindex1064;  slog::Index** $sup56712x37x0x0x0index1065;  slog::Index** eval_argsindex1066;  slog::Index** eval_argsindex1067;  slog::Index** eval_args_ansindex1068;  slog::Index** eval_ansindex1069;  slog::Index** eval_args_ansindex1070;  slog::Index** $seq_atdelta1071;  slog::Index** eval_argsdelta1072;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1074({2, 3, 0, 1, 4});
      slog::Relation* readrel1075 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index1059 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({2, 0, 1});
      slog::Relation* readrel1077 = db->getRelation("eval_args");
      eval_argsindex1060 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({0, 1});
      slog::Relation* readrel1079 = db->getRelation("eval_ans");
      eval_ansindex1061 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 0, 2});
      slog::Relation* readrel1081 = db->getRelation("$seq_at");
      $seq_atindex1062 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 0, 2});
      slog::Relation* readrel1083 = db->getRelation("$seq_at");
      $seq_atdelta1071 = readrel1083->getIndex(ord1082, true);
      std::vector<u16> ord1084({1, 2, 0});
      slog::Relation* readrel1085 = db->getRelation("eval_args");
      eval_argsindex1063 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 2, 0});
      slog::Relation* readrel1087 = db->getRelation("eval_args");
      eval_argsindex1064 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({0, 3, 4, 2, 1});
      slog::Relation* readrel1089 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index1065 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({0, 2, 1});
      slog::Relation* readrel1091 = db->getRelation("eval_args");
      eval_argsindex1066 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 2, 0});
      slog::Relation* readrel1093 = db->getRelation("eval_args");
      eval_argsindex1067 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({1, 2, 0});
      slog::Relation* readrel1095 = db->getRelation("eval_args");
      eval_argsdelta1072 = readrel1095->getIndex(ord1094, true);
      std::vector<u16> ord1096({0, 1});
      slog::Relation* readrel1097 = db->getRelation("eval_args_ans");
      eval_args_ansindex1068 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({0, 1});
      slog::Relation* readrel1099 = db->getRelation("eval_ans");
      eval_ansindex1069 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({0, 1});
      slog::Relation* readrel1101 = db->getRelation("eval_args_ans");
      eval_args_ansindex1070 = readrel1101->getIndex(ord1100, false);
  
    }
    ReadTask1073(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c229 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c230 = v_const5feceb66ffc86f38d952786c;
      u64 v_c231 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c232 = v_const5feceb66ffc86f38d952786c;
      u64 v_c233 = v_const5feceb66ffc86f38d952786c;
      u64 v_c234 = _prim_lempty(db);
      if (v_c234 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c235 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<5,2>($sup56712x37x0x0x0index1059, std::array<u64,5>{v_c19, v_c37, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1060, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1061, std::array<u64,2>{v_c235, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1062, $seq_atdelta1071, std::array<u64,3>{v_c233, v_c37, 0}, [&](const std::array<u64,3>& m1102) {
          u64 v_c35 = m1102[2];
          bool ok1103 = true;
          u64 v_c236 = _prim_aslst(db, v_c35, &ok1103);
          if (!ok1103) return;
          u64 v_c237 = _prim_llen(db, v_c236);
          if (v_c237 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          u64 v_c238 = _prim_ge(db, v_c237, v_c229);
          if (v_c238 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          if (!v_c238) return;
          u64 v_c239 = _prim__0002d(db, v_c237, v_c232);
          if (v_c239 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          u64 v_c41 = _prim_lslice(db, v_c236, v_c231, v_c239);
          if (v_c41 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          if (!slog::exists_probe<3,2>(eval_argsindex1063, std::array<u64,3>{v_c35, v_c19, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex1064, std::array<u64,3>{v_c41, v_c19, 0})) return;
          slog::join_probe<5,4>($sup56712x37x0x0x0index1065, std::array<u64,5>{v_c35, v_c37, v_c41, v_c19, 0}, [&](const std::array<u64,5>& m1105) {
            u64 v_c240 = m1105[4];
            slog::join_probe<3,3>(eval_argsindex1066, std::array<u64,3>{v_c240, v_c19, v_c35}, [&](const std::array<u64,3>& m1106) {
              slog::join_probe_old<3,2>(eval_argsindex1067, eval_argsdelta1072, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m1107) {
                u64 v_c241 = m1107[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1068, std::array<u64,2>{v_c241, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1069, std::array<u64,2>{v_c235, 0}, [&](const std::array<u64,2>& m1108) {
                  u64 v_c117 = m1108[1];
                  slog::join_probe<2,1>(eval_args_ansindex1070, std::array<u64,2>{v_c241, 0}, [&](const std::array<u64,2>& m1109) {
                    u64 v_c118 = m1109[1];
                    bool ok1110 = true;
                    u64 v_c242 = _prim_lref(db, v_c236, v_c230, &ok1110);
                    if (!ok1110) return;
                    if (v_c37 != v_c242) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c240, v_c234, v_c117, v_c118});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1073* _cont = new ReadTask1073(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1073(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (join freevar (0 1) 1 y __t3Eay213) (join-old lambda (0 1 2) 1 (0 1 2) __t3Eay213 xs eb) (join eval (0 2 1) 0 __1G4R719 c __t1Dbd212) (join-old app (0 1 2) 1 (0 1 2) __t1Dbd212 ef es)) (head (mkstruct tick (1 2 0) __2Xr3720 __t1Dbd212 c)) interp.slog:56 #f)
  class ReadTask1117 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1111;  slog::Index** lambdaindex1112;  slog::Index** evalindex1113;  slog::Index** appindex1114;  slog::Index** lambdadelta1115;  slog::Index** appdelta1116;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord1118({0, 1});
      slog::Relation* readrel1119 = db->getRelation("freevar");
      freevarindex1111 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({0, 1, 2});
      slog::Relation* readrel1121 = db->getRelation("lambda");
      lambdaindex1112 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({0, 1, 2});
      slog::Relation* readrel1123 = db->getRelation("lambda");
      lambdadelta1115 = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({0, 2, 1});
      slog::Relation* readrel1125 = db->getRelation("eval");
      evalindex1113 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({0, 1, 2});
      slog::Relation* readrel1127 = db->getRelation("app");
      appindex1114 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({0, 1, 2});
      slog::Relation* readrel1129 = db->getRelation("app");
      appdelta1116 = readrel1129->getIndex(ord1128, true);
  
    }
    ReadTask1117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[1];
        u64 v_c243 = _t[2];
        slog::join_probe<2,1>(freevarindex1111, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1130) {
          u64 v_c244 = m1130[1];
          slog::join_probe_old<3,1>(lambdaindex1112, lambdadelta1115, std::array<u64,3>{v_c244, 0, 0}, [&](const std::array<u64,3>& m1131) {
            u64 v_c148 = m1131[1]; u64 v_c20 = m1131[2];
            slog::join_all<3>(evalindex1113, [&](const std::array<u64,3>& m1132) {
              u64 v_c245 = m1132[0]; u64 v_c19 = m1132[1]; u64 v_c246 = m1132[2];
              slog::join_probe_old<3,1>(appindex1114, appdelta1116, std::array<u64,3>{v_c246, 0, 0}, [&](const std::array<u64,3>& m1133) {
                u64 v_c48 = m1133[1]; u64 v_c41 = m1133[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c246, v_c19}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask1117* _cont = new ReadTask1117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1117(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4) (let __tconst0VKF494 const20c400557af0eddc0be4d9e0) (let __tconst3zss458 const06abaa100ecef791ce028c56)) (scan temp4Sey1009 __t54rR457 __t55Yy488 __t6BG8482 __t6DJ9464 __t7u8Q496 __t8QoE473) (body (exists ref (1 0) 1 __tconst7G6n490) (exists app (2 0 1) 1 __t6DJ9464) (exists app (2 0 1) 1 __t8QoE473) (exists ref (1 0) 1 __tconst8pH5498) (exists app (2 0 1) 1 __t6BG8482) (exists ref (1 0) 1 __tconst0VKF494) (exists lambda (1 2 0) 1 __t7u8Q496) (join ref (1 0) 1 __tconst3zss458 __t0Jxw459) (join ref (1 0) 1 __tconst7G6n490 __t58rC466) (exists app (1 2 0) 2 __t58rC466 __t8QoE473) (join app (1 2 0) 2 __t58rC466 __t6DJ9464 __t7FRU467) (join app (1 2 0) 2 __t58rC466 __t8QoE473 __t0c92476) (join ref (1 0) 1 __tconst8pH5498 __t6Nc8484) (join app (1 2 0) 2 __t6Nc8484 __t6BG8482 __t6p4Y485) (join ref (1 0) 1 __tconst0VKF494 __t6o9z493) (join lambda (1 2 0) 2 __t7u8Q496 __t6o9z493 __t18GV497)) (head (emit-temp temp06cC1010 __t0c92476 __t18GV497 __t54rR457 __t55Yy488 __t6p4Y485 __t7FRU467) (mkstruct lambda (1 2 0) __t6n7e489 __t55Yy488 __t6p4Y485) (mkstruct app (1 2 0) __t8jPa460 __t0Jxw459 __t54rR457)) schemecfa.slog:51 #f)
  class ReadTask1150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1134;  slog::Index** appindex1135;  slog::Index** appindex1136;  slog::Index** refindex1137;  slog::Index** appindex1138;  slog::Index** refindex1139;  slog::Index** lambdaindex1140;  slog::Index** refindex1141;  slog::Index** refindex1142;  slog::Index** appindex1143;  slog::Index** appindex1144;  slog::Index** appindex1145;  slog::Index** refindex1146;  slog::Index** appindex1147;  slog::Index** refindex1148;  slog::Index** lambdaindex1149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp06cC1010");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp4Sey1009");
      std::vector<u16> ord1151({1, 0});
      slog::Relation* readrel1152 = db->getRelation("ref");
      refindex1134 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({2, 0, 1});
      slog::Relation* readrel1154 = db->getRelation("app");
      appindex1135 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({2, 0, 1});
      slog::Relation* readrel1156 = db->getRelation("app");
      appindex1136 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 0});
      slog::Relation* readrel1158 = db->getRelation("ref");
      refindex1137 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({2, 0, 1});
      slog::Relation* readrel1160 = db->getRelation("app");
      appindex1138 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({1, 0});
      slog::Relation* readrel1162 = db->getRelation("ref");
      refindex1139 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({1, 2, 0});
      slog::Relation* readrel1164 = db->getRelation("lambda");
      lambdaindex1140 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({1, 0});
      slog::Relation* readrel1166 = db->getRelation("ref");
      refindex1141 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({1, 0});
      slog::Relation* readrel1168 = db->getRelation("ref");
      refindex1142 = readrel1168->getIndex(ord1167, false);
      std::vector<u16> ord1169({1, 2, 0});
      slog::Relation* readrel1170 = db->getRelation("app");
      appindex1143 = readrel1170->getIndex(ord1169, false);
      std::vector<u16> ord1171({1, 2, 0});
      slog::Relation* readrel1172 = db->getRelation("app");
      appindex1144 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({1, 2, 0});
      slog::Relation* readrel1174 = db->getRelation("app");
      appindex1145 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({1, 0});
      slog::Relation* readrel1176 = db->getRelation("ref");
      refindex1146 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({1, 2, 0});
      slog::Relation* readrel1178 = db->getRelation("app");
      appindex1147 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({1, 0});
      slog::Relation* readrel1180 = db->getRelation("ref");
      refindex1148 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("lambda");
      lambdaindex1149 = readrel1182->getIndex(ord1181, false);
  
    }
    ReadTask1150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c71 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c247 = v_const0fc34686741291b4dd06511b;
      u64 v_c248 = v_const39c6f8839ca547fa7b7a32c4;
      u64 v_c249 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c250 = v_const06abaa100ecef791ce028c56;
  
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
        u64 v_c251 = _t[0];
        u64 v_c252 = _t[1];
        u64 v_c253 = _t[2];
        u64 v_c254 = _t[3];
        u64 v_c255 = _t[4];
        u64 v_c256 = _t[5];
        if (!slog::exists_probe<2,1>(refindex1134, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1135, std::array<u64,3>{v_c254, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1136, std::array<u64,3>{v_c256, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1137, std::array<u64,2>{v_c70, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1138, std::array<u64,3>{v_c253, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1139, std::array<u64,2>{v_c249, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1140, std::array<u64,3>{v_c255, 0, 0})) return;
        slog::join_probe<2,1>(refindex1141, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1183) {
          u64 v_c257 = m1183[1];
          slog::join_probe<2,1>(refindex1142, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m1184) {
            u64 v_c258 = m1184[1];
            if (!slog::exists_probe<3,2>(appindex1143, std::array<u64,3>{v_c258, v_c256, 0})) return;
            slog::join_probe<3,2>(appindex1144, std::array<u64,3>{v_c258, v_c254, 0}, [&](const std::array<u64,3>& m1185) {
              u64 v_c259 = m1185[2];
              slog::join_probe<3,2>(appindex1145, std::array<u64,3>{v_c258, v_c256, 0}, [&](const std::array<u64,3>& m1186) {
                u64 v_c260 = m1186[2];
                slog::join_probe<2,1>(refindex1146, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m1187) {
                  u64 v_c261 = m1187[1];
                  slog::join_probe<3,2>(appindex1147, std::array<u64,3>{v_c261, v_c253, 0}, [&](const std::array<u64,3>& m1188) {
                    u64 v_c262 = m1188[2];
                    slog::join_probe<2,1>(refindex1148, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m1189) {
                      u64 v_c263 = m1189[1];
                      slog::join_probe<3,2>(lambdaindex1149, std::array<u64,3>{v_c255, v_c263, 0}, [&](const std::array<u64,3>& m1190) {
                        u64 v_c72 = m1190[2];
                        ++_fires;
                        slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c260, v_c72, v_c251, v_c252, v_c262, v_c259});
                        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c252, v_c262}, std::array<u16,3>{1, 2, 0});
                        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c257, v_c251}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp4Sey1009", _fires);
  
      if (!_done)
      {
        ReadTask1150* _cont = new ReadTask1150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1150(db,b), false);
  // (crule (pre) (scan eval_ans __t6lGP106 __v2) (body (join-old eval (0 2 1) 1 (0 2 1) __t6lGP106 c __v1) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join select_branch_ans (1 0) 1 __v1 __t8m22105) (join-old eval (2 0 1) 1 (2 0 1) c __t9HBz103 __t2D2o102) (join-old $sup56712x86x0x0x0 (1 0 2 3 4) 2 (1 0 2 3 4) c __t9HBz103 e1 e2 e3) (join-old if (1 3 2 0) 4 (1 3 2 0) e1 e3 e2 __t2D2o102) (exists eval (1 2 0) 2 e1 c) (join-old select_branch (2 3 0 1) 3 (2 3 0 1) e2 e3 __t8m22105 __v0) (exists eval_ans (1 0) 1 __v0) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t0Z2s104) (join eval_ans (0 1) 2 __t0Z2s104 __v0)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask1209 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1191;  slog::Index** evalindex1192;  slog::Index** $sup56712x86x0x0x0index1193;  slog::Index** select_branch_ansindex1194;  slog::Index** evalindex1195;  slog::Index** $sup56712x86x0x0x0index1196;  slog::Index** ifindex1197;  slog::Index** evalindex1198;  slog::Index** select_branchindex1199;  slog::Index** eval_ansindex1200;  slog::Index** evalindex1201;  slog::Index** eval_ansindex1202;  slog::Index** evaldelta1203;  slog::Index** evaldelta1204;  slog::Index** $sup56712x86x0x0x0delta1205;  slog::Index** ifdelta1206;  slog::Index** select_branchdelta1207;  slog::Index** evaldelta1208;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1210({0, 1});
      slog::Relation* readrel1211 = db->getRelation("eval_ans");
      head_index[0] = readrel1211->getIndex(ord1210, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1212({0, 2, 1});
      slog::Relation* readrel1213 = db->getRelation("eval");
      evalindex1191 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({0, 2, 1});
      slog::Relation* readrel1215 = db->getRelation("eval");
      evaldelta1203 = readrel1215->getIndex(ord1214, true);
      std::vector<u16> ord1216({2, 0, 1});
      slog::Relation* readrel1217 = db->getRelation("eval");
      evalindex1192 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 0, 2, 3, 4});
      slog::Relation* readrel1219 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1193 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 0});
      slog::Relation* readrel1221 = db->getRelation("select_branch_ans");
      select_branch_ansindex1194 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({2, 0, 1});
      slog::Relation* readrel1223 = db->getRelation("eval");
      evalindex1195 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({2, 0, 1});
      slog::Relation* readrel1225 = db->getRelation("eval");
      evaldelta1204 = readrel1225->getIndex(ord1224, true);
      std::vector<u16> ord1226({1, 0, 2, 3, 4});
      slog::Relation* readrel1227 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1196 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 0, 2, 3, 4});
      slog::Relation* readrel1229 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta1205 = readrel1229->getIndex(ord1228, true);
      std::vector<u16> ord1230({1, 3, 2, 0});
      slog::Relation* readrel1231 = db->getRelation("if");
      ifindex1197 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 3, 2, 0});
      slog::Relation* readrel1233 = db->getRelation("if");
      ifdelta1206 = readrel1233->getIndex(ord1232, true);
      std::vector<u16> ord1234({1, 2, 0});
      slog::Relation* readrel1235 = db->getRelation("eval");
      evalindex1198 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({2, 3, 0, 1});
      slog::Relation* readrel1237 = db->getRelation("select_branch");
      select_branchindex1199 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({2, 3, 0, 1});
      slog::Relation* readrel1239 = db->getRelation("select_branch");
      select_branchdelta1207 = readrel1239->getIndex(ord1238, true);
      std::vector<u16> ord1240({1, 0});
      slog::Relation* readrel1241 = db->getRelation("eval_ans");
      eval_ansindex1200 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({1, 2, 0});
      slog::Relation* readrel1243 = db->getRelation("eval");
      evalindex1201 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 2, 0});
      slog::Relation* readrel1245 = db->getRelation("eval");
      evaldelta1208 = readrel1245->getIndex(ord1244, true);
      std::vector<u16> ord1246({0, 1});
      slog::Relation* readrel1247 = db->getRelation("eval_ans");
      eval_ansindex1202 = readrel1247->getIndex(ord1246, false);
  
    }
    ReadTask1209(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c217 = _t[1];
        slog::join_probe_old<3,1>(evalindex1191, evaldelta1203, std::array<u64,3>{v_c216, 0, 0}, [&](const std::array<u64,3>& m1248) {
          u64 v_c19 = m1248[1]; u64 v_c118 = m1248[2];
          if (!slog::exists_probe<3,1>(evalindex1192, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index1193, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(select_branch_ansindex1194, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m1249) {
            u64 v_c212 = m1249[1];
            slog::join_probe_old<3,1>(evalindex1195, evaldelta1204, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m1250) {
              u64 v_c214 = m1250[1]; u64 v_c213 = m1250[2];
              slog::join_probe_old<5,2>($sup56712x86x0x0x0index1196, $sup56712x86x0x0x0delta1205, std::array<u64,5>{v_c19, v_c214, 0, 0, 0}, [&](const std::array<u64,5>& m1251) {
                u64 v_c113 = m1251[2]; u64 v_c114 = m1251[3]; u64 v_c115 = m1251[4];
                slog::join_probe_old<4,4>(ifindex1197, ifdelta1206, std::array<u64,4>{v_c113, v_c115, v_c114, v_c213}, [&](const std::array<u64,4>& m1252) {
                  if (!slog::exists_probe<3,2>(evalindex1198, std::array<u64,3>{v_c113, v_c19, 0})) return;
                  slog::join_probe_old<4,3>(select_branchindex1199, select_branchdelta1207, std::array<u64,4>{v_c114, v_c115, v_c212, 0}, [&](const std::array<u64,4>& m1253) {
                    u64 v_c117 = m1253[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex1200, std::array<u64,2>{v_c117, 0})) return;
                    slog::join_probe_old<3,2>(evalindex1201, evaldelta1208, std::array<u64,3>{v_c113, v_c19, 0}, [&](const std::array<u64,3>& m1254) {
                      u64 v_c215 = m1254[2];
                      slog::join_probe<2,2>(eval_ansindex1202, std::array<u64,2>{v_c215, v_c117}, [&](const std::array<u64,2>& m1255) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c217}, std::array<u16,2>{0, 1});
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
        ReadTask1209* _cont = new ReadTask1209(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1209(db,b), false);
  // (crule (pre) (scan eval __t9lTe203 __t8x6E209 c) (body (exists $sup56712x41x0x0x0 (1 0 2 3) 2 c __t9lTe203) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join $sup56712x41x0x0x0 (1 0 2 3) 2 c __t9lTe203 ef es) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t6XAE206 __t6hhS205 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask1283 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x41x0x0x0index1256;  slog::Index** evalindex1257;  slog::Index** eval_argsindex1258;  slog::Index** tickindex1259;  slog::Index** tick_ansindex1260;  slog::Index** $sup56712x41x0x0x0index1261;  slog::Index** appindex1262;  slog::Index** eval_argsindex1263;  slog::Index** evalindex1264;  slog::Index** eval_ansindex1265;  slog::Index** eval_argsindex1266;  slog::Index** eval_args_ansindex1267;  slog::Index** eval_ansindex1268;  slog::Index** eval_args_ansindex1269;  slog::Index** tick_ansindex1270;  slog::Index** evalindex1271;  slog::Index** closureindex1272;  slog::Index** lambdaindex1273;  slog::Index** evalindex1274;  slog::Index** eval_ansindex1275;  slog::Index** tickdelta1276;  slog::Index** appdelta1277;  slog::Index** evaldelta1278;  slog::Index** eval_argsdelta1279;  slog::Index** closuredelta1280;  slog::Index** lambdadelta1281;  slog::Index** evaldelta1282;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1284({0, 1});
      slog::Relation* readrel1285 = db->getRelation("eval_ans");
      head_index[0] = readrel1285->getIndex(ord1284, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1286({1, 0, 2, 3});
      slog::Relation* readrel1287 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1256 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({2, 0, 1});
      slog::Relation* readrel1289 = db->getRelation("eval");
      evalindex1257 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({2, 0, 1});
      slog::Relation* readrel1291 = db->getRelation("eval_args");
      eval_argsindex1258 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({1, 2, 0});
      slog::Relation* readrel1293 = db->getRelation("tick");
      tickindex1259 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({1, 2, 0});
      slog::Relation* readrel1295 = db->getRelation("tick");
      tickdelta1276 = readrel1295->getIndex(ord1294, true);
      std::vector<u16> ord1296({0, 1});
      slog::Relation* readrel1297 = db->getRelation("tick_ans");
      tick_ansindex1260 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 0, 2, 3});
      slog::Relation* readrel1299 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1261 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({0, 1, 2});
      slog::Relation* readrel1301 = db->getRelation("app");
      appindex1262 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({0, 1, 2});
      slog::Relation* readrel1303 = db->getRelation("app");
      appdelta1277 = readrel1303->getIndex(ord1302, true);
      std::vector<u16> ord1304({1, 2, 0});
      slog::Relation* readrel1305 = db->getRelation("eval_args");
      eval_argsindex1263 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({1, 2, 0});
      slog::Relation* readrel1307 = db->getRelation("eval");
      evalindex1264 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({1, 2, 0});
      slog::Relation* readrel1309 = db->getRelation("eval");
      evaldelta1278 = readrel1309->getIndex(ord1308, true);
      std::vector<u16> ord1310({0, 1});
      slog::Relation* readrel1311 = db->getRelation("eval_ans");
      eval_ansindex1265 = readrel1311->getIndex(ord1310, false);
      std::vector<u16> ord1312({1, 2, 0});
      slog::Relation* readrel1313 = db->getRelation("eval_args");
      eval_argsindex1266 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 2, 0});
      slog::Relation* readrel1315 = db->getRelation("eval_args");
      eval_argsdelta1279 = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("eval_args_ans");
      eval_args_ansindex1267 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("eval_ans");
      eval_ansindex1268 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({0, 1});
      slog::Relation* readrel1321 = db->getRelation("eval_args_ans");
      eval_args_ansindex1269 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({0, 1});
      slog::Relation* readrel1323 = db->getRelation("tick_ans");
      tick_ansindex1270 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({2, 0, 1});
      slog::Relation* readrel1325 = db->getRelation("eval");
      evalindex1271 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({0, 1, 2});
      slog::Relation* readrel1327 = db->getRelation("closure");
      closureindex1272 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({0, 1, 2});
      slog::Relation* readrel1329 = db->getRelation("closure");
      closuredelta1280 = readrel1329->getIndex(ord1328, true);
      std::vector<u16> ord1330({0, 1, 2});
      slog::Relation* readrel1331 = db->getRelation("lambda");
      lambdaindex1273 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({0, 1, 2});
      slog::Relation* readrel1333 = db->getRelation("lambda");
      lambdadelta1281 = readrel1333->getIndex(ord1332, true);
      std::vector<u16> ord1334({1, 2, 0});
      slog::Relation* readrel1335 = db->getRelation("eval");
      evalindex1274 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({1, 2, 0});
      slog::Relation* readrel1337 = db->getRelation("eval");
      evaldelta1282 = readrel1337->getIndex(ord1336, true);
      std::vector<u16> ord1338({0, 1});
      slog::Relation* readrel1339 = db->getRelation("eval_ans");
      eval_ansindex1275 = readrel1339->getIndex(ord1338, false);
  
    }
    ReadTask1283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index1256, std::array<u64,4>{v_c19, v_c264, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1257, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1258, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex1259, tickdelta1276, std::array<u64,3>{v_c265, v_c19, 0}, [&](const std::array<u64,3>& m1340) {
          u64 v_c266 = m1340[2];
          if (!slog::exists_probe<2,1>(tick_ansindex1260, std::array<u64,2>{v_c266, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index1261, std::array<u64,4>{v_c19, v_c264, 0, 0}, [&](const std::array<u64,4>& m1341) {
            u64 v_c48 = m1341[2]; u64 v_c41 = m1341[3];
            slog::join_probe_old<3,3>(appindex1262, appdelta1277, std::array<u64,3>{v_c265, v_c48, v_c41}, [&](const std::array<u64,3>& m1342) {
              if (!slog::exists_probe<3,2>(eval_argsindex1263, std::array<u64,3>{v_c41, v_c19, 0})) return;
              slog::join_probe_old<3,2>(evalindex1264, evaldelta1278, std::array<u64,3>{v_c48, v_c19, 0}, [&](const std::array<u64,3>& m1343) {
                u64 v_c267 = m1343[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1265, std::array<u64,2>{v_c267, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex1266, eval_argsdelta1279, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m1344) {
                  u64 v_c268 = m1344[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1267, std::array<u64,2>{v_c268, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1268, std::array<u64,2>{v_c267, 0}, [&](const std::array<u64,2>& m1345) {
                    u64 v_c269 = m1345[1];
                    slog::join_probe<2,1>(eval_args_ansindex1269, std::array<u64,2>{v_c268, 0}, [&](const std::array<u64,2>& m1346) {
                      u64 v_c44 = m1346[1];
                      slog::join_probe<2,1>(tick_ansindex1270, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1347) {
                        u64 v_c117 = m1347[1];
                        if (!slog::exists_probe<3,1>(evalindex1271, std::array<u64,3>{v_c117, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex1272, closuredelta1280, std::array<u64,3>{v_c269, 0, 0}, [&](const std::array<u64,3>& m1348) {
                          u64 v_c270 = m1348[1]; u64 v_c13 = m1348[2];
                          slog::join_probe_old<3,1>(lambdaindex1273, lambdadelta1281, std::array<u64,3>{v_c270, 0, 0}, [&](const std::array<u64,3>& m1349) {
                            u64 v_c148 = m1349[1]; u64 v_c20 = m1349[2];
                            slog::join_probe_old<3,2>(evalindex1274, evaldelta1282, std::array<u64,3>{v_c20, v_c117, 0}, [&](const std::array<u64,3>& m1350) {
                              u64 v_c271 = m1350[2];
                              slog::join_probe<2,1>(eval_ansindex1275, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1351) {
                                u64 v_c18 = m1351[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c264, v_c18}, std::array<u16,2>{0, 1});
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
        ReadTask1283* _cont = new ReadTask1283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1283(db,b), false);
  // (crule (pre) (scan tick_ans __t3z31201 __v0) (body (join-old tick (0 2 1) 1 (0 2 1) __t3z31201 c __t0nYt200) (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval_args (2 0 1) 1 c) (join-old eval (2 0 1) 1 (2 0 1) c __t44Jo196 ef) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists eval_ans (0 1) 1 __t44Jo196) (join-old app (0 1 2) 2 (0 1 2) __t0nYt200 ef es) (exists eval_args (1 2 0) 2 es c) (join $sup56712x41x0x0x0 (1 2 3 0) 3 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join-old closure (0 1 2) 1 (0 1 2) __t4ROj198 __t2BTJ197 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask1373 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex1352;  slog::Index** $sup56712x41x0x0x0index1353;  slog::Index** eval_argsindex1354;  slog::Index** evalindex1355;  slog::Index** $sup56712x41x0x0x0index1356;  slog::Index** eval_ansindex1357;  slog::Index** appindex1358;  slog::Index** eval_argsindex1359;  slog::Index** $sup56712x41x0x0x0index1360;  slog::Index** eval_argsindex1361;  slog::Index** eval_args_ansindex1362;  slog::Index** eval_ansindex1363;  slog::Index** eval_args_ansindex1364;  slog::Index** closureindex1365;  slog::Index** lambdaindex1366;  slog::Index** tickdelta1367;  slog::Index** evaldelta1368;  slog::Index** appdelta1369;  slog::Index** eval_argsdelta1370;  slog::Index** closuredelta1371;  slog::Index** lambdadelta1372;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord1374({0, 2, 1});
      slog::Relation* readrel1375 = db->getRelation("tick");
      tickindex1352 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({0, 2, 1});
      slog::Relation* readrel1377 = db->getRelation("tick");
      tickdelta1367 = readrel1377->getIndex(ord1376, true);
      std::vector<u16> ord1378({1, 0, 2, 3});
      slog::Relation* readrel1379 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1353 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({2, 0, 1});
      slog::Relation* readrel1381 = db->getRelation("eval_args");
      eval_argsindex1354 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({2, 0, 1});
      slog::Relation* readrel1383 = db->getRelation("eval");
      evalindex1355 = readrel1383->getIndex(ord1382, false);
      std::vector<u16> ord1384({2, 0, 1});
      slog::Relation* readrel1385 = db->getRelation("eval");
      evaldelta1368 = readrel1385->getIndex(ord1384, true);
      std::vector<u16> ord1386({1, 2, 3, 0});
      slog::Relation* readrel1387 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1356 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({0, 1});
      slog::Relation* readrel1389 = db->getRelation("eval_ans");
      eval_ansindex1357 = readrel1389->getIndex(ord1388, false);
      std::vector<u16> ord1390({0, 1, 2});
      slog::Relation* readrel1391 = db->getRelation("app");
      appindex1358 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({0, 1, 2});
      slog::Relation* readrel1393 = db->getRelation("app");
      appdelta1369 = readrel1393->getIndex(ord1392, true);
      std::vector<u16> ord1394({1, 2, 0});
      slog::Relation* readrel1395 = db->getRelation("eval_args");
      eval_argsindex1359 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({1, 2, 3, 0});
      slog::Relation* readrel1397 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1360 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({1, 2, 0});
      slog::Relation* readrel1399 = db->getRelation("eval_args");
      eval_argsindex1361 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({1, 2, 0});
      slog::Relation* readrel1401 = db->getRelation("eval_args");
      eval_argsdelta1370 = readrel1401->getIndex(ord1400, true);
      std::vector<u16> ord1402({0, 1});
      slog::Relation* readrel1403 = db->getRelation("eval_args_ans");
      eval_args_ansindex1362 = readrel1403->getIndex(ord1402, false);
      std::vector<u16> ord1404({0, 1});
      slog::Relation* readrel1405 = db->getRelation("eval_ans");
      eval_ansindex1363 = readrel1405->getIndex(ord1404, false);
      std::vector<u16> ord1406({0, 1});
      slog::Relation* readrel1407 = db->getRelation("eval_args_ans");
      eval_args_ansindex1364 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({0, 1, 2});
      slog::Relation* readrel1409 = db->getRelation("closure");
      closureindex1365 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({0, 1, 2});
      slog::Relation* readrel1411 = db->getRelation("closure");
      closuredelta1371 = readrel1411->getIndex(ord1410, true);
      std::vector<u16> ord1412({0, 1, 2});
      slog::Relation* readrel1413 = db->getRelation("lambda");
      lambdaindex1366 = readrel1413->getIndex(ord1412, false);
      std::vector<u16> ord1414({0, 1, 2});
      slog::Relation* readrel1415 = db->getRelation("lambda");
      lambdadelta1372 = readrel1415->getIndex(ord1414, true);
  
    }
    ReadTask1373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c272 = _t[0];
        u64 v_c117 = _t[1];
        slog::join_probe_old<3,1>(tickindex1352, tickdelta1367, std::array<u64,3>{v_c272, 0, 0}, [&](const std::array<u64,3>& m1416) {
          u64 v_c19 = m1416[1]; u64 v_c273 = m1416[2];
          if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index1353, std::array<u64,4>{v_c19, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex1354, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<3,1>(evalindex1355, evaldelta1368, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m1417) {
            u64 v_c274 = m1417[1]; u64 v_c48 = m1417[2];
            if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index1356, std::array<u64,4>{v_c19, v_c48, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex1357, std::array<u64,2>{v_c274, 0})) return;
            slog::join_probe_old<3,2>(appindex1358, appdelta1369, std::array<u64,3>{v_c273, v_c48, 0}, [&](const std::array<u64,3>& m1418) {
              u64 v_c41 = m1418[2];
              if (!slog::exists_probe<3,2>(eval_argsindex1359, std::array<u64,3>{v_c41, v_c19, 0})) return;
              slog::join_probe<4,3>($sup56712x41x0x0x0index1360, std::array<u64,4>{v_c19, v_c48, v_c41, 0}, [&](const std::array<u64,4>& m1419) {
                u64 v_c99 = m1419[3];
                slog::join_probe_old<3,2>(eval_argsindex1361, eval_argsdelta1370, std::array<u64,3>{v_c41, v_c19, 0}, [&](const std::array<u64,3>& m1420) {
                  u64 v_c275 = m1420[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1362, std::array<u64,2>{v_c275, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1363, std::array<u64,2>{v_c274, 0}, [&](const std::array<u64,2>& m1421) {
                    u64 v_c276 = m1421[1];
                    slog::join_probe<2,1>(eval_args_ansindex1364, std::array<u64,2>{v_c275, 0}, [&](const std::array<u64,2>& m1422) {
                      u64 v_c44 = m1422[1];
                      slog::join_probe_old<3,1>(closureindex1365, closuredelta1371, std::array<u64,3>{v_c276, 0, 0}, [&](const std::array<u64,3>& m1423) {
                        u64 v_c277 = m1423[1]; u64 v_c13 = m1423[2];
                        slog::join_probe_old<3,1>(lambdaindex1366, lambdadelta1372, std::array<u64,3>{v_c277, 0, 0}, [&](const std::array<u64,3>& m1424) {
                          u64 v_c148 = m1424[1]; u64 v_c20 = m1424[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c20, v_c117}, std::array<u16,3>{1, 2, 0});
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
        ReadTask1373* _cont = new ReadTask1373(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1373(db,b), false);
  // (crule (pre (let __tconst3F1g329 conste7f6c011776e8db7cd330b54) (let __tconst3nEA343 const0933fb667296882d8c45abca) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e) (let __tconst2t4L361 const5feceb66ffc86f38d952786c) (let __tconst8nL2368 const90fb9068eda6f2d68bb61c33) (let __tconst2LxS372 const46a3ae93aa7a8b988080d6c9) (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __t6UsA373 (lempty))) (once) (body) (head (emit-temp temp1EpF1108 __t6UsA373) (mkstruct num (1 0) __t3dLQ330 __tconst3F1g329) (mkstruct ref (1 0) __t7cCj334 __tconst3Nin376) (mkstruct num (1 0) __t29aP337 __tconst88d3359) (mkstruct ref (1 0) __t62US339 __tconst2LxS372) (mkstruct ref (1 0) __t85N1344 __tconst3nEA343) (mkstruct ref (1 0) __t56Hj357 __tconst0pCN356) (mkstruct num (1 0) __t9AJk362 __tconst2t4L361) (mkstruct ref (1 0) __t5g5j369 __tconst8nL2368)) schemecfa.slog:12 #f)
  class ReadTask1425 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[9];
    slog::Index** head_index[9];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1EpF1108");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("num");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("num");
      head_rel[8] = db->getRelation("ref");
  
    }
    ReadTask1425(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c278 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c175 = v_const0933fb667296882d8c45abca;
      u64 v_c102 = v_consted725292f5f32d61535958c1;
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c279 = v_const46a3ae93aa7a8b988080d6c9;
      u64 v_c101 = v_consta81ad7556291f9defc5163ec;
      u64 v_c179 = _prim_lempty(db);
      if (v_c179 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[9];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c179});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c278}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c101}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c103}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c279}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c175}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c102}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c176}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c177}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1425(db,b), true);
  // (crule (pre) (scan $sup56712x91x0x0x0 __t1bnm441 c eb er x) (body (exists eval (0 2 1) 2 __t1bnm441 c) (exists eval (1 2 0) 2 er c) (exists eval (1 2 0) 2 eb c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t0DPj440) (join-old eval (0 2 1) 3 (0 2 1) __t1bnm441 c __t0DPj440) (join-old eval (1 2 0) 2 (1 2 0) er c __t0jgp442) (exists eval_ans (0 1) 1 __t0jgp442) (join-old eval (1 2 0) 2 (1 2 0) eb c __t9j6S443) (exists eval_ans (0 1) 1 __t9j6S443) (join eval_ans (0 1) 1 __t0jgp442 vr) (join eval_ans (0 1) 1 __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask1441 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1426;  slog::Index** evalindex1427;  slog::Index** evalindex1428;  slog::Index** letindex1429;  slog::Index** evalindex1430;  slog::Index** evalindex1431;  slog::Index** eval_ansindex1432;  slog::Index** evalindex1433;  slog::Index** eval_ansindex1434;  slog::Index** eval_ansindex1435;  slog::Index** eval_ansindex1436;  slog::Index** letdelta1437;  slog::Index** evaldelta1438;  slog::Index** evaldelta1439;  slog::Index** evaldelta1440;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1442({0, 1});
      slog::Relation* readrel1443 = db->getRelation("eval_ans");
      head_index[0] = readrel1443->getIndex(ord1442, false);
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord1444({0, 2, 1});
      slog::Relation* readrel1445 = db->getRelation("eval");
      evalindex1426 = readrel1445->getIndex(ord1444, false);
      std::vector<u16> ord1446({1, 2, 0});
      slog::Relation* readrel1447 = db->getRelation("eval");
      evalindex1427 = readrel1447->getIndex(ord1446, false);
      std::vector<u16> ord1448({1, 2, 0});
      slog::Relation* readrel1449 = db->getRelation("eval");
      evalindex1428 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({2, 1, 3, 0});
      slog::Relation* readrel1451 = db->getRelation("let");
      letindex1429 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({2, 1, 3, 0});
      slog::Relation* readrel1453 = db->getRelation("let");
      letdelta1437 = readrel1453->getIndex(ord1452, true);
      std::vector<u16> ord1454({0, 2, 1});
      slog::Relation* readrel1455 = db->getRelation("eval");
      evalindex1430 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({0, 2, 1});
      slog::Relation* readrel1457 = db->getRelation("eval");
      evaldelta1438 = readrel1457->getIndex(ord1456, true);
      std::vector<u16> ord1458({1, 2, 0});
      slog::Relation* readrel1459 = db->getRelation("eval");
      evalindex1431 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 2, 0});
      slog::Relation* readrel1461 = db->getRelation("eval");
      evaldelta1439 = readrel1461->getIndex(ord1460, true);
      std::vector<u16> ord1462({0, 1});
      slog::Relation* readrel1463 = db->getRelation("eval_ans");
      eval_ansindex1432 = readrel1463->getIndex(ord1462, false);
      std::vector<u16> ord1464({1, 2, 0});
      slog::Relation* readrel1465 = db->getRelation("eval");
      evalindex1433 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({1, 2, 0});
      slog::Relation* readrel1467 = db->getRelation("eval");
      evaldelta1440 = readrel1467->getIndex(ord1466, true);
      std::vector<u16> ord1468({0, 1});
      slog::Relation* readrel1469 = db->getRelation("eval_ans");
      eval_ansindex1434 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({0, 1});
      slog::Relation* readrel1471 = db->getRelation("eval_ans");
      eval_ansindex1435 = readrel1471->getIndex(ord1470, false);
      std::vector<u16> ord1472({0, 1});
      slog::Relation* readrel1473 = db->getRelation("eval_ans");
      eval_ansindex1436 = readrel1473->getIndex(ord1472, false);
  
    }
    ReadTask1441(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c23 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex1426, std::array<u64,3>{v_c21, v_c19, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1427, std::array<u64,3>{v_c22, v_c19, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1428, std::array<u64,3>{v_c20, v_c19, 0})) return;
        slog::join_probe_old<4,3>(letindex1429, letdelta1437, std::array<u64,4>{v_c22, v_c23, v_c20, 0}, [&](const std::array<u64,4>& m1474) {
          u64 v_c24 = m1474[3];
          slog::join_probe_old<3,3>(evalindex1430, evaldelta1438, std::array<u64,3>{v_c21, v_c19, v_c24}, [&](const std::array<u64,3>& m1475) {
            slog::join_probe_old<3,2>(evalindex1431, evaldelta1439, std::array<u64,3>{v_c22, v_c19, 0}, [&](const std::array<u64,3>& m1476) {
              u64 v_c25 = m1476[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1432, std::array<u64,2>{v_c25, 0})) return;
              slog::join_probe_old<3,2>(evalindex1433, evaldelta1440, std::array<u64,3>{v_c20, v_c19, 0}, [&](const std::array<u64,3>& m1477) {
                u64 v_c17 = m1477[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1434, std::array<u64,2>{v_c17, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1435, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1478) {
                  u64 v_c26 = m1478[1];
                  slog::join_probe<2,1>(eval_ansindex1436, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m1479) {
                    u64 v_c18 = m1479[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c18}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:$sup56712x91x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (scan prim __t76ef190 op) (body (exists $seq_at (1 0 2) 2 _00024sqo3d3H593 __t76ef190) (exists $seq_atr (1 0 2) 2 _00024sqo5WJE594 __t76ef190) (exists $seq_atr (1 0 2) 2 _00024sqo4b4d595 __t76ef190) (exists delta (1 2 0) 1 __tconst16Oe187) (exists _enum (1 0) 1 __tconst5USv771) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo2ych592 __t76ef190 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3d3H593 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5WJE594 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4b4d595 __t76ef190 _00024seq2) (join delta (1 2 0) 2 __tconst16Oe187 _00024seq2 __t4OrE188) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (letp _00024sql3Mb9587 (aslst _00024seq2)) (let chk8Ayz1061 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk8Ayz1061) (letp chk8gr11062 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (eq __t76ef190 chk8gr11062) (letp chk4Tzw1063 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk4Tzw1063)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask1495 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1480;  slog::Index** $seq_atrindex1481;  slog::Index** $seq_atrindex1482;  slog::Index** deltaindex1483;  slog::Index** _enumindex1484;  slog::Index** $seq_atindex1485;  slog::Index** $seq_atindex1486;  slog::Index** $seq_atrindex1487;  slog::Index** $seq_atrindex1488;  slog::Index** deltaindex1489;  slog::Index** _enumindex1490;  slog::Index** $seq_atdelta1491;  slog::Index** $seq_atdelta1492;  slog::Index** $seq_atrdelta1493;  slog::Index** $seq_atrdelta1494;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord1496({1, 0, 2});
      slog::Relation* readrel1497 = db->getRelation("$seq_at");
      $seq_atindex1480 = readrel1497->getIndex(ord1496, false);
      std::vector<u16> ord1498({1, 0, 2});
      slog::Relation* readrel1499 = db->getRelation("$seq_atr");
      $seq_atrindex1481 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({1, 0, 2});
      slog::Relation* readrel1501 = db->getRelation("$seq_atr");
      $seq_atrindex1482 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({1, 2, 0});
      slog::Relation* readrel1503 = db->getRelation("delta");
      deltaindex1483 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 0});
      slog::Relation* readrel1505 = db->getRelation("_enum");
      _enumindex1484 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 0, 2});
      slog::Relation* readrel1507 = db->getRelation("$seq_at");
      $seq_atindex1485 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({1, 0, 2});
      slog::Relation* readrel1509 = db->getRelation("$seq_at");
      $seq_atdelta1491 = readrel1509->getIndex(ord1508, true);
      std::vector<u16> ord1510({1, 0, 2});
      slog::Relation* readrel1511 = db->getRelation("$seq_at");
      $seq_atindex1486 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 0, 2});
      slog::Relation* readrel1513 = db->getRelation("$seq_at");
      $seq_atdelta1492 = readrel1513->getIndex(ord1512, true);
      std::vector<u16> ord1514({1, 0, 2});
      slog::Relation* readrel1515 = db->getRelation("$seq_atr");
      $seq_atrindex1487 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 0, 2});
      slog::Relation* readrel1517 = db->getRelation("$seq_atr");
      $seq_atrdelta1493 = readrel1517->getIndex(ord1516, true);
      std::vector<u16> ord1518({1, 0, 2});
      slog::Relation* readrel1519 = db->getRelation("$seq_atr");
      $seq_atrindex1488 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 0, 2});
      slog::Relation* readrel1521 = db->getRelation("$seq_atr");
      $seq_atrdelta1494 = readrel1521->getIndex(ord1520, true);
      std::vector<u16> ord1522({1, 2, 0});
      slog::Relation* readrel1523 = db->getRelation("delta");
      deltaindex1489 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({1, 0});
      slog::Relation* readrel1525 = db->getRelation("_enum");
      _enumindex1490 = readrel1525->getIndex(ord1524, false);
  
    }
    ReadTask1495(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c280 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c281 = v_const06abaa100ecef791ce028c56;
      u64 v_c282 = v_constd4735e3a265e16eee03f5971;
      u64 v_c283 = v_const5feceb66ffc86f38d952786c;
      u64 v_c284 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c285 = v_const5feceb66ffc86f38d952786c;
      u64 v_c286 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c287 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c288 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c289 = _t[0];
        u64 v_c43 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex1480, std::array<u64,3>{v_c286, v_c289, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1481, std::array<u64,3>{v_c287, v_c289, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1482, std::array<u64,3>{v_c288, v_c289, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex1483, std::array<u64,3>{v_c281, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex1484, std::array<u64,2>{v_c280, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1485, $seq_atdelta1491, std::array<u64,3>{v_c285, v_c289, 0}, [&](const std::array<u64,3>& m1526) {
          u64 v_c8 = m1526[2];
          slog::join_probe_old<3,3>($seq_atindex1486, $seq_atdelta1492, std::array<u64,3>{v_c286, v_c289, v_c8}, [&](const std::array<u64,3>& m1527) {
            slog::join_probe_old<3,3>($seq_atrindex1487, $seq_atrdelta1493, std::array<u64,3>{v_c287, v_c289, v_c8}, [&](const std::array<u64,3>& m1528) {
              slog::join_probe_old<3,3>($seq_atrindex1488, $seq_atrdelta1494, std::array<u64,3>{v_c288, v_c289, v_c8}, [&](const std::array<u64,3>& m1529) {
                slog::join_probe<3,2>(deltaindex1489, std::array<u64,3>{v_c281, v_c8, 0}, [&](const std::array<u64,3>& m1530) {
                  u64 v_c290 = m1530[2];
                  slog::join_probe<2,1>(_enumindex1490, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1531) {
                    u64 v_c291 = m1531[1];
                    bool ok1532 = true;
                    u64 v_c292 = _prim_aslst(db, v_c8, &ok1532);
                    if (!ok1532) return;
                    u64 v_c293 = _prim_llen(db, v_c292);
                    if (v_c293 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c282 != v_c293) return;
                    bool ok1533 = true;
                    u64 v_c294 = _prim_lref(db, v_c292, v_c283, &ok1533);
                    if (!ok1533) return;
                    if (v_c289 != v_c294) return;
                    bool ok1534 = true;
                    u64 v_c295 = _prim_lref(db, v_c292, v_c284, &ok1534);
                    if (!ok1534) return;
                    if (v_c289 != v_c295) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c290});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c291}, std::array<u16,2>{1, 0});
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
        ReadTask1495* _cont = new ReadTask1495(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1495(db,b), false);
  // (crule (pre (let __tconst9G7o724 constb9e118781cea1f9fa01462e0) (let __tconst165m173 const60e3114d9b4b6577eea8cbc0) (let __tconst1U6w167 const844546be553b9dcbf71ae163) (let __tconst469K165 const0453462f31b2bcf68e33a91f) (let __t1trx171 (lempty))) (probe _enum (1 0) 1 __tconst9G7o724 __t551W169) (body) (head (emit-temp temp8AMS1030 __t1trx171) (mkstruct ref (1 0) __t3tIp174 __tconst165m173) (mkstruct boolean (1 0) __t1HQ2170 __t551W169) (mkstruct sym (1 0) __t2m3K168 __tconst1U6w167) (mkstruct sym (1 0) __t5k1R166 __tconst469K165)) schemecfa.slog:61 #f)
  class ReadTask1535 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8AMS1030");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("boolean");
      head_rel[3] = db->getRelation("sym");
      head_rel[4] = db->getRelation("sym");
      std::vector<u16> ord1536({1, 0});
      slog::Relation* readrel1537 = db->getRelation("_enum");
      driver_index = readrel1537->getIndex(ord1536, true);
  
    }
    ReadTask1535(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c296 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c297 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c298 = v_const844546be553b9dcbf71ae163;
      u64 v_c299 = v_const0453462f31b2bcf68e33a91f;
      u64 v_c300 = _prim_lempty(db);
      if (v_c300 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:61"); return true; }
  
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
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c296, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1538) {
        u64 v_c301 = m1538[1];
        if (buckethash(v_c301) != bucket) return;
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c300});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c297}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c301}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c298}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c299}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("schemecfa.slog:61", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask1535* _cont = new ReadTask1535(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1535(db,b), true);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp5oZM1054 __t0O3R266 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289) (body (exists app (2 0 1) 1 __t0O3R266) (join ref (1 0) 1 __tconst4G37291 __t8oYB253) (join app (1 2 0) 2 __t8oYB253 __t0O3R266 __t8IFs269)) (head (emit-temp temp2OQF1055 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289 __t8IFs269) (mkstruct if (1 3 2 0) __t7WBr286 __t5TOH285 __t8IFs269 __t0vlN275)) schemecfa.slog:70 #f)
  class ReadTask1542 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1539;  slog::Index** refindex1540;  slog::Index** appindex1541;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2OQF1055");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp5oZM1054");
      std::vector<u16> ord1543({2, 0, 1});
      slog::Relation* readrel1544 = db->getRelation("app");
      appindex1539 = readrel1544->getIndex(ord1543, false);
      std::vector<u16> ord1545({1, 0});
      slog::Relation* readrel1546 = db->getRelation("ref");
      refindex1540 = readrel1546->getIndex(ord1545, false);
      std::vector<u16> ord1547({1, 2, 0});
      slog::Relation* readrel1548 = db->getRelation("app");
      appindex1541 = readrel1548->getIndex(ord1547, false);
  
    }
    ReadTask1542(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c203 = v_const889c19fd926bc4ca61c0b4d9;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c302 = _t[0];
        u64 v_c303 = _t[1];
        u64 v_c304 = _t[2];
        u64 v_c305 = _t[3];
        u64 v_c306 = _t[4];
        if (!slog::exists_probe<3,1>(appindex1539, std::array<u64,3>{v_c302, 0, 0})) return;
        slog::join_probe<2,1>(refindex1540, std::array<u64,2>{v_c203, 0}, [&](const std::array<u64,2>& m1549) {
          u64 v_c307 = m1549[1];
          slog::join_probe<3,2>(appindex1541, std::array<u64,3>{v_c307, v_c302, 0}, [&](const std::array<u64,3>& m1550) {
            u64 v_c308 = m1550[2];
            ++_fires;
            slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c303, v_c304, v_c305, v_c306, v_c308});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c305, v_c308, v_c303}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp5oZM1054", _fires);
  
      if (!_done)
      {
        ReadTask1542* _cont = new ReadTask1542(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1542(db,b), false);
  // (crule (pre) (scan temp3KOr1128 __t2lyA156 b) (body (join boolval (1 0) 1 b __t5Aug154)) (head (emit delta_ans (0 1) __t2lyA156 __t5Aug154)) interp.slog:122 #f)
  class ReadTask1552 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex1551;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1553({0, 1});
      slog::Relation* readrel1554 = db->getRelation("delta_ans");
      head_index[0] = readrel1554->getIndex(ord1553, false);
      outer_rel = db->getRelation("temp3KOr1128");
      std::vector<u16> ord1555({1, 0});
      slog::Relation* readrel1556 = db->getRelation("boolval");
      boolvalindex1551 = readrel1556->getIndex(ord1555, false);
  
    }
    ReadTask1552(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe<2,1>(boolvalindex1551, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m1557) {
          u64 v_c309 = m1557[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c9, v_c309}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:temp3KOr1128", _fires);
  
      if (!_done)
      {
        ReadTask1552* _cont = new ReadTask1552(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1552(db,b), false);
  // (crule (pre) (scan toint_range __erre2zjC937 __errf197F938 __errf01Fo939) (body) (head (emit error (0) __erre2zjC937)) <internal>:1 #f)
  class ReadTask1558 : public slog::Task
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
      std::vector<u16> ord1559({0});
      slog::Relation* readrel1560 = db->getRelation("error");
      head_index[0] = readrel1560->getIndex(ord1559, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask1558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c310 = _t[0];
        u64 v_c311 = _t[1];
        u64 v_c312 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c310}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask1558* _cont = new ReadTask1558(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1558(db,b), false);
}

