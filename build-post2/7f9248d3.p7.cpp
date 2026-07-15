
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0bbd2fbd1dc4200473343503;
extern u64 v_const0fc34686741291b4dd06511b;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const20c400557af0eddc0be4d9e0;
extern u64 v_const25f568921d120de09a5f575d;
extern u64 v_const2a09f8e08b8d8243373579d9;
extern u64 v_const2bc983a5942276eb00a75e21;
extern u64 v_const2d53b3c21fa5cc786ac46d72;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const39c6f8839ca547fa7b7a32c4;
extern u64 v_const49e9fcfb5617aad332d56d58;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4e5ef144c51cd25230c144c3;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7265b875feb0d1730ead43d3;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_constac3fe12f2763ff95bc66dbed;
extern u64 v_constb85d38dc71a8027700bebd3c;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste403ffb5ff0078a3e3c6bcc7;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;


void slog_rules_c732ca43a07335425(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp2mUr1105 __t4ZSk163 x) (body) (head (emit freevar_in_args (1 0) __t4ZSk163 x)) freevars.slog:35 #f)
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
      head_rel[0] = db->getRelation("freevar_in_args");
      std::vector<u16> ord1({1, 0});
      slog::Relation* readrel2 = db->getRelation("freevar_in_args");
      head_index[0] = readrel2->getIndex(ord1, false);
      outer_rel = db->getRelation("temp2mUr1105");
  
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
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp2mUr1105", _fires);
  
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
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan eval_ans __t25lG448 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo7FTM622) (join-old eval (0 2 1) 1 (0 2 1) __t25lG448 c e) (exists $sup56712x37x0x0x0 (2 3 0 1 4) 2 c e) (exists eval_args (2 0 1) 1 c) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7FTM622 e _00024seq0) (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let es (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (exists eval_args (1 2 0) 2 _00024seq0 c) (exists eval_args (1 2 0) 2 es c) (join-old $sup56712x37x0x0x0 (0 3 4 2 1) 4 (0 3 4 2 1) _00024seq0 e es c __t2W25447) (join-old eval_args (0 2 1) 3 (0 2 1) __t2W25447 c _00024seq0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6oBa449) (join-old eval_args_ans (0 1) 1 (0 1) __t6oBa449 __v1) (letp chk4I5N983 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk4I5N983)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex3;  slog::Index** evalindex4;  slog::Index** $sup56712x37x0x0x0index5;  slog::Index** eval_argsindex6;  slog::Index** $seq_atindex7;  slog::Index** eval_argsindex8;  slog::Index** eval_argsindex9;  slog::Index** $sup56712x37x0x0x0index10;  slog::Index** eval_argsindex11;  slog::Index** eval_argsindex12;  slog::Index** eval_args_ansindex13;  slog::Index** evaldelta14;  slog::Index** $seq_atdelta15;  slog::Index** $sup56712x37x0x0x0delta16;  slog::Index** eval_argsdelta17;  slog::Index** eval_argsdelta18;  slog::Index** eval_args_ansdelta19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord21({1, 0, 2});
      slog::Relation* readrel22 = db->getRelation("$seq_at");
      $seq_atindex3 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({0, 2, 1});
      slog::Relation* readrel24 = db->getRelation("eval");
      evalindex4 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 2, 1});
      slog::Relation* readrel26 = db->getRelation("eval");
      evaldelta14 = readrel26->getIndex(ord25, true);
      std::vector<u16> ord27({2, 3, 0, 1, 4});
      slog::Relation* readrel28 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index5 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 0, 1});
      slog::Relation* readrel30 = db->getRelation("eval_args");
      eval_argsindex6 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0, 2});
      slog::Relation* readrel32 = db->getRelation("$seq_at");
      $seq_atindex7 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0, 2});
      slog::Relation* readrel34 = db->getRelation("$seq_at");
      $seq_atdelta15 = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({1, 2, 0});
      slog::Relation* readrel36 = db->getRelation("eval_args");
      eval_argsindex8 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("eval_args");
      eval_argsindex9 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 3, 4, 2, 1});
      slog::Relation* readrel40 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index10 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 3, 4, 2, 1});
      slog::Relation* readrel42 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0delta16 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({0, 2, 1});
      slog::Relation* readrel44 = db->getRelation("eval_args");
      eval_argsindex11 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 2, 1});
      slog::Relation* readrel46 = db->getRelation("eval_args");
      eval_argsdelta17 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("eval_args");
      eval_argsindex12 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("eval_args");
      eval_argsdelta18 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("eval_args_ans");
      eval_args_ansindex13 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("eval_args_ans");
      eval_args_ansdelta19 = readrel54->getIndex(ord53, true);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = _prim_lempty(db);
      if (v_c7 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
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
        if (!slog::exists_probe<3,1>($seq_atindex3, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex4, evaldelta14, std::array<u64,3>{v_c8, 0, 0}, [&](const std::array<u64,3>& m55) {
          u64 v_c10 = m55[1]; u64 v_c11 = m55[2];
          if (!slog::exists_probe<5,2>($sup56712x37x0x0x0index5, std::array<u64,5>{v_c10, v_c11, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex6, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex7, $seq_atdelta15, std::array<u64,3>{v_c6, v_c11, 0}, [&](const std::array<u64,3>& m56) {
            u64 v_c12 = m56[2];
            bool ok57 = true;
            u64 v_c13 = _prim_aslst(db, v_c12, &ok57);
            if (!ok57) return;
            u64 v_c14 = _prim_llen(db, v_c13);
            if (v_c14 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            u64 v_c15 = _prim_ge(db, v_c14, v_c2);
            if (v_c15 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            if (!v_c15) return;
            u64 v_c16 = _prim__0002d(db, v_c14, v_c5);
            if (v_c16 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            u64 v_c17 = _prim_lslice(db, v_c13, v_c4, v_c16);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            if (!slog::exists_probe<3,2>(eval_argsindex8, std::array<u64,3>{v_c12, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(eval_argsindex9, std::array<u64,3>{v_c17, v_c10, 0})) return;
            slog::join_probe_old<5,4>($sup56712x37x0x0x0index10, $sup56712x37x0x0x0delta16, std::array<u64,5>{v_c12, v_c11, v_c17, v_c10, 0}, [&](const std::array<u64,5>& m59) {
              u64 v_c18 = m59[4];
              slog::join_probe_old<3,3>(eval_argsindex11, eval_argsdelta17, std::array<u64,3>{v_c18, v_c10, v_c12}, [&](const std::array<u64,3>& m60) {
                slog::join_probe_old<3,2>(eval_argsindex12, eval_argsdelta18, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m61) {
                  u64 v_c19 = m61[2];
                  slog::join_probe_old<2,1>(eval_args_ansindex13, eval_args_ansdelta19, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m62) {
                    u64 v_c20 = m62[1];
                    bool ok63 = true;
                    u64 v_c21 = _prim_lref(db, v_c13, v_c3, &ok63);
                    if (!ok63) return;
                    if (v_c11 != v_c21) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c18, v_c7, v_c9, v_c20});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo9OPL525 __t5ERV310 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7nH0522 __t5ERV310 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8HCy523 __t5ERV310 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo1Uwu524 __t5ERV310 _00024seq2) (exists _enum (1 0) 1 __tconst65GN810) (join delta (1 2 0) 2 __tconst3VNs307 _00024seq2 __t5HIm308) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join symval (0 1) 1 __t5ERV310 s) (letp _00024sql2wmw517 (aslst _00024seq2)) (let chk8G5Y1161 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk8G5Y1161) (letp chk34931162 (lref _00024sql2wmw517 _00024sqc5bE7520)) (eq __t5ERV310 chk34931162) (letp chk9QD11163 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk9QD11163)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask71 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex64;  slog::Index** $seq_atindex65;  slog::Index** $seq_atrindex66;  slog::Index** _enumindex67;  slog::Index** deltaindex68;  slog::Index** _enumindex69;  slog::Index** symvalindex70;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord72({1, 0, 2});
      slog::Relation* readrel73 = db->getRelation("$seq_atr");
      driver_index = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({1, 0, 2});
      slog::Relation* readrel75 = db->getRelation("$seq_at");
      $seq_atindex64 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 0, 2});
      slog::Relation* readrel77 = db->getRelation("$seq_at");
      $seq_atindex65 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 0, 2});
      slog::Relation* readrel79 = db->getRelation("$seq_atr");
      $seq_atrindex66 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("_enum");
      _enumindex67 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("delta");
      deltaindex68 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("_enum");
      _enumindex69 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("symval");
      symvalindex70 = readrel87->getIndex(ord86, false);
  
    }
    ReadTask71(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c23 = v_const06abaa100ecef791ce028c56;
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c30, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m88) {
        u64 v_c31 = m88[1];
        u64 v_c32 = m88[2];
        if (buckethash(v_c31) != bucket) return;
        slog::join_probe<3,3>($seq_atindex64, std::array<u64,3>{v_c27, v_c31, v_c32}, [&](const std::array<u64,3>& m89) {
          slog::join_probe<3,3>($seq_atindex65, std::array<u64,3>{v_c28, v_c31, v_c32}, [&](const std::array<u64,3>& m90) {
            slog::join_probe<3,3>($seq_atrindex66, std::array<u64,3>{v_c29, v_c31, v_c32}, [&](const std::array<u64,3>& m91) {
              if (!slog::exists_probe<2,1>(_enumindex67, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe<3,2>(deltaindex68, std::array<u64,3>{v_c23, v_c32, 0}, [&](const std::array<u64,3>& m92) {
                u64 v_c33 = m92[2];
                slog::join_probe<2,1>(_enumindex69, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m93) {
                  u64 v_c34 = m93[1];
                  slog::join_probe<2,1>(symvalindex70, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m94) {
                    u64 v_c35 = m94[1];
                    bool ok95 = true;
                    u64 v_c36 = _prim_aslst(db, v_c32, &ok95);
                    if (!ok95) return;
                    u64 v_c37 = _prim_llen(db, v_c36);
                    if (v_c37 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c24 != v_c37) return;
                    bool ok96 = true;
                    u64 v_c38 = _prim_lref(db, v_c36, v_c25, &ok96);
                    if (!ok96) return;
                    if (v_c31 != v_c38) return;
                    bool ok97 = true;
                    u64 v_c39 = _prim_lref(db, v_c36, v_c26, &ok97);
                    if (!ok97) return;
                    if (v_c31 != v_c39) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c34}, std::array<u16,2>{1, 0});
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
        ReadTask71* _cont = new ReadTask71(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask71(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst0VKF494 const20c400557af0eddc0be4d9e0) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst6Qri486 const7265b875feb0d1730ead43d3) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst6Aow470 const49e9fcfb5617aad332d56d58) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4) (let __tconst49VM461 constb85d38dc71a8027700bebd3c) (let __tconst3zss458 const06abaa100ecef791ce028c56)) (scan temp34Hd1007 __t7qtp495) (body (exists ref (1 0) 1 __tconst49ZO477) (exists ref (1 0) 1 __tconst3zss458) (exists sym (1 0) 1 __tconst49VM461) (exists ref (1 0) 1 __tconst7G6n490) (exists sym (1 0) 1 __tconst6Aow470) (exists ref (1 0) 1 __tconst6Qri486) (exists ref (1 0) 1 __tconst8pH5498) (exists ref (1 0) 1 __tconst0VKF494) (join ref (1 0) 1 __tconst2M9b468 __t7Te9452) (join ref (1 0) 1 __tconst49ZO477 __t2pSO454) (join ref (1 0) 1 __tconst3zss458 __t0Jxw459) (join sym (1 0) 1 __tconst49VM461 __t7EYF462) (join ref (1 0) 1 __tconst7G6n490 __t58rC466) (join sym (1 0) 1 __tconst6Aow470 __t3yjc471) (join ref (1 0) 1 __tconst6Qri486 __t7D13480) (join ref (1 0) 1 __tconst8pH5498 __t6Nc8484) (join ref (1 0) 1 __tconst0VKF494 __t6o9z493) (let __t7u8Q496 (lpush __t7qtp495 __tconst0VKF494)) (let __t55Yy488 (lpush __t7qtp495 __tconst6Qri486)) (let __t6BG8482 (lpush __t7qtp495 __t7D13480)) (let __t8QoE473 (lpush __t7qtp495 __t3yjc471)) (let __t6DJ9464 (lpush __t7qtp495 __t7EYF462)) (let __t0FwI456 (lpush __t7qtp495 __t2pSO454))) (head (emit-temp temp4IN11008 __t0FwI456 __t55Yy488 __t6BG8482 __t6DJ9464 __t7u8Q496 __t8QoE473)) schemecfa.slog:51 #f)
  class ReadTask115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex98;  slog::Index** refindex99;  slog::Index** symindex100;  slog::Index** refindex101;  slog::Index** symindex102;  slog::Index** refindex103;  slog::Index** refindex104;  slog::Index** refindex105;  slog::Index** refindex106;  slog::Index** refindex107;  slog::Index** refindex108;  slog::Index** symindex109;  slog::Index** refindex110;  slog::Index** symindex111;  slog::Index** refindex112;  slog::Index** refindex113;  slog::Index** refindex114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4IN11008");
      outer_rel = db->getRelation("temp34Hd1007");
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("ref");
      refindex98 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("ref");
      refindex99 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("sym");
      symindex100 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 0});
      slog::Relation* readrel123 = db->getRelation("ref");
      refindex101 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("sym");
      symindex102 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("ref");
      refindex103 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("ref");
      refindex104 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex105 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ref");
      refindex106 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ref");
      refindex107 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("ref");
      refindex108 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("sym");
      symindex109 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("ref");
      refindex110 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("sym");
      symindex111 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0});
      slog::Relation* readrel145 = db->getRelation("ref");
      refindex112 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 0});
      slog::Relation* readrel147 = db->getRelation("ref");
      refindex113 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 0});
      slog::Relation* readrel149 = db->getRelation("ref");
      refindex114 = readrel149->getIndex(ord148, false);
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c41 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c42 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c43 = v_const7265b875feb0d1730ead43d3;
      u64 v_c44 = v_const0fc34686741291b4dd06511b;
      u64 v_c45 = v_const49e9fcfb5617aad332d56d58;
      u64 v_c46 = v_const39c6f8839ca547fa7b7a32c4;
      u64 v_c47 = v_constb85d38dc71a8027700bebd3c;
      u64 v_c48 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c49 = _t[0];
        if (!slog::exists_probe<2,1>(refindex98, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<2,1>(refindex99, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<2,1>(symindex100, std::array<u64,2>{v_c47, 0})) return;
        if (!slog::exists_probe<2,1>(refindex101, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<2,1>(symindex102, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(refindex103, std::array<u64,2>{v_c43, 0})) return;
        if (!slog::exists_probe<2,1>(refindex104, std::array<u64,2>{v_c40, 0})) return;
        if (!slog::exists_probe<2,1>(refindex105, std::array<u64,2>{v_c41, 0})) return;
        slog::join_probe<2,1>(refindex106, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m150) {
          u64 v_c50 = m150[1];
          slog::join_probe<2,1>(refindex107, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m151) {
            u64 v_c51 = m151[1];
            slog::join_probe<2,1>(refindex108, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m152) {
              u64 v_c52 = m152[1];
              slog::join_probe<2,1>(symindex109, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m153) {
                u64 v_c53 = m153[1];
                slog::join_probe<2,1>(refindex110, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m154) {
                  u64 v_c54 = m154[1];
                  slog::join_probe<2,1>(symindex111, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m155) {
                    u64 v_c55 = m155[1];
                    slog::join_probe<2,1>(refindex112, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m156) {
                      u64 v_c56 = m156[1];
                      slog::join_probe<2,1>(refindex113, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m157) {
                        u64 v_c57 = m157[1];
                        slog::join_probe<2,1>(refindex114, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m158) {
                          u64 v_c58 = m158[1];
                          u64 v_c59 = _prim_lpush(db, v_c49, v_c41);
                          if (v_c59 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          u64 v_c60 = _prim_lpush(db, v_c49, v_c43);
                          if (v_c60 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          u64 v_c61 = _prim_lpush(db, v_c49, v_c56);
                          if (v_c61 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          u64 v_c62 = _prim_lpush(db, v_c49, v_c55);
                          if (v_c62 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          u64 v_c63 = _prim_lpush(db, v_c49, v_c53);
                          if (v_c63 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          u64 v_c64 = _prim_lpush(db, v_c49, v_c51);
                          if (v_c64 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                          ++_fires;
                          slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c64, v_c60, v_c61, v_c63, v_c59, v_c62});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp34Hd1007", _fires);
  
      if (!_done)
      {
        ReadTask115* _cont = new ReadTask115(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask115(db,b), false);
  // (crule (pre (let __t2ytA435 (lempty))) (scan tick __t6dFG434 site c) (body (join mlimit (0) 0 m) (let __t33cB436 (lpush __t2ytA435 site)) (let __t2jGw437 (lcat __t33cB436 c)) (join-old lst_take (1 2 0) 2 (1 2 0) __t2jGw437 m __t1Al3438) (join lst_take_ans (0 1) 1 __t1Al3438 __v0)) (head (emit tick_ans (0 1) __t6dFG434 __v0)) context.slog:10 #f)
  class ReadTask163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex159;  slog::Index** lst_takeindex160;  slog::Index** lst_take_ansindex161;  slog::Index** lst_takedelta162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("tick_ans");
      head_index[0] = readrel165->getIndex(ord164, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord166({0});
      slog::Relation* readrel167 = db->getRelation("mlimit");
      mlimitindex159 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 2, 0});
      slog::Relation* readrel169 = db->getRelation("lst_take");
      lst_takeindex160 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 2, 0});
      slog::Relation* readrel171 = db->getRelation("lst_take");
      lst_takedelta162 = readrel171->getIndex(ord170, true);
      std::vector<u16> ord172({0, 1});
      slog::Relation* readrel173 = db->getRelation("lst_take_ans");
      lst_take_ansindex161 = readrel173->getIndex(ord172, false);
  
    }
    ReadTask163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = _prim_lempty(db);
      if (v_c65 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_all<1>(mlimitindex159, [&](const std::array<u64,1>& m174) {
          u64 v_c68 = m174[0];
          u64 v_c69 = _prim_lpush(db, v_c65, v_c67);
          if (v_c69 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
          u64 v_c70 = _prim_lcat(db, v_c69, v_c10);
          if (v_c70 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
          slog::join_probe_old<3,2>(lst_takeindex160, lst_takedelta162, std::array<u64,3>{v_c70, v_c68, 0}, [&](const std::array<u64,3>& m175) {
            u64 v_c71 = m175[2];
            slog::join_probe<2,1>(lst_take_ansindex161, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m176) {
              u64 v_c9 = m176[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c66, v_c9}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:tick", _fires);
  
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
  // (crule (pre) (scan app __t8j7u29 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t8j7u29) (join eval (1 2 0) 1 __t8j7u29 c __4cUN684) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t8j7u29 c) (join eval (1 2 0) 2 ef c __t5MCM24) (exists eval_ans (0 1) 1 __t5MCM24) (join eval_args (1 2 0) 2 es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join tick_ans (0 1) 1 __t0DSy30 l) (join closure (0 1 2) 1 __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join lambda (0 1 2) 1 __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask198 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex177;  slog::Index** eval_argsindex178;  slog::Index** tickindex179;  slog::Index** evalindex180;  slog::Index** eval_argsindex181;  slog::Index** tickindex182;  slog::Index** evalindex183;  slog::Index** eval_ansindex184;  slog::Index** eval_argsindex185;  slog::Index** eval_args_ansindex186;  slog::Index** tickindex187;  slog::Index** tick_ansindex188;  slog::Index** eval_ansindex189;  slog::Index** eval_args_ansindex190;  slog::Index** tick_ansindex191;  slog::Index** closureindex192;  slog::Index** bindingindex193;  slog::Index** freevarindex194;  slog::Index** bindingindex195;  slog::Index** lambdaindex196;  slog::Index** tickdelta197;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord199({0, 1, 2});
      slog::Relation* readrel200 = db->getRelation("binding");
      head_index[0] = readrel200->getIndex(ord199, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord201({0, 1, 2});
      slog::Relation* readrel202 = db->getRelation("binding_event");
      head_index[1] = readrel202->getIndex(ord201, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord203({1, 2, 0});
      slog::Relation* readrel204 = db->getRelation("eval");
      evalindex177 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 0});
      slog::Relation* readrel206 = db->getRelation("eval_args");
      eval_argsindex178 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("tick");
      tickindex179 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("eval");
      evalindex180 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 0});
      slog::Relation* readrel212 = db->getRelation("eval_args");
      eval_argsindex181 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("tick");
      tickindex182 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("eval");
      evalindex183 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("eval_ans");
      eval_ansindex184 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("eval_args");
      eval_argsindex185 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("eval_args_ans");
      eval_args_ansindex186 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 0});
      slog::Relation* readrel224 = db->getRelation("tick");
      tickindex187 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("tick");
      tickdelta197 = readrel226->getIndex(ord225, true);
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("tick_ans");
      tick_ansindex188 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("eval_ans");
      eval_ansindex189 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("eval_args_ans");
      eval_args_ansindex190 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("tick_ans");
      tick_ansindex191 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("closure");
      closureindex192 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 0, 2});
      slog::Relation* readrel238 = db->getRelation("binding");
      bindingindex193 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("freevar");
      freevarindex194 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({0, 1, 2});
      slog::Relation* readrel242 = db->getRelation("binding");
      bindingindex195 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1, 2});
      slog::Relation* readrel244 = db->getRelation("lambda");
      lambdaindex196 = readrel244->getIndex(ord243, false);
  
    }
    ReadTask198(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex177, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex178, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex179, std::array<u64,3>{v_c72, 0, 0})) return;
        slog::join_probe<3,1>(evalindex180, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m245) {
          u64 v_c10 = m245[1]; u64 v_c74 = m245[2];
          if (!slog::exists_probe<3,2>(eval_argsindex181, std::array<u64,3>{v_c17, v_c10, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex182, std::array<u64,3>{v_c72, v_c10, 0})) return;
          slog::join_probe<3,2>(evalindex183, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m246) {
            u64 v_c75 = m246[2];
            if (!slog::exists_probe<2,1>(eval_ansindex184, std::array<u64,2>{v_c75, 0})) return;
            slog::join_probe<3,2>(eval_argsindex185, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m247) {
              u64 v_c76 = m247[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex186, std::array<u64,2>{v_c76, 0})) return;
              slog::join_probe_old<3,2>(tickindex187, tickdelta197, std::array<u64,3>{v_c72, v_c10, 0}, [&](const std::array<u64,3>& m248) {
                u64 v_c77 = m248[2];
                if (!slog::exists_probe<2,1>(tick_ansindex188, std::array<u64,2>{v_c77, 0})) return;
                slog::join_probe<2,1>(eval_ansindex189, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m249) {
                  u64 v_c78 = m249[1];
                  slog::join_probe<2,1>(eval_args_ansindex190, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m250) {
                    u64 v_c79 = m250[1];
                    slog::join_probe<2,1>(tick_ansindex191, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m251) {
                      u64 v_c80 = m251[1];
                      slog::join_probe<3,1>(closureindex192, std::array<u64,3>{v_c78, 0, 0}, [&](const std::array<u64,3>& m252) {
                        u64 v_c81 = m252[1]; u64 v_c82 = m252[2];
                        if (!slog::exists_probe<3,1>(bindingindex193, std::array<u64,3>{v_c82, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex194, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m253) {
                          u64 v_c83 = m253[1];
                          slog::join_probe<3,2>(bindingindex195, std::array<u64,3>{v_c83, v_c82, 0}, [&](const std::array<u64,3>& m254) {
                            u64 v_c84 = m254[2];
                            slog::join_probe<3,1>(lambdaindex196, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m255) {
                              u64 v_c85 = m255[1]; u64 v_c86 = m255[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c83, v_c80, v_c84}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c83, v_c80, v_c10}, std::array<u16,3>{0, 1, 2});
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
        ReadTask198* _cont = new ReadTask198(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask198(db,b), false);
  // (crule (pre) (scan eval __t3A6m504 ef c) (body (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t3A6m504) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __t8a3x503) (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval_args (1 2 0) 2 es c) (join app (1 2 0) 2 ef es __t8eby502) (join eval (0 2 1) 3 __t8a3x503 c __t8eby502) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t60iG506) (exists eval_args_ans (0 1) 1 __t60iG506) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join eval_args_ans (0 1) 1 __t60iG506 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join delta_ans (0 1) 1 __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask276 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex256;  slog::Index** evalindex257;  slog::Index** eval_argsindex258;  slog::Index** eval_ansindex259;  slog::Index** $sup56712x74x0x0x0index260;  slog::Index** evalindex261;  slog::Index** eval_argsindex262;  slog::Index** appindex263;  slog::Index** evalindex264;  slog::Index** eval_argsindex265;  slog::Index** eval_args_ansindex266;  slog::Index** eval_ansindex267;  slog::Index** eval_args_ansindex268;  slog::Index** deltaindex269;  slog::Index** primindex270;  slog::Index** deltaindex271;  slog::Index** delta_ansindex272;  slog::Index** eval_argsdelta273;  slog::Index** primdelta274;  slog::Index** deltadelta275;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("eval_ans");
      head_index[0] = readrel278->getIndex(ord277, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord279({1, 2, 0});
      slog::Relation* readrel280 = db->getRelation("app");
      appindex256 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({2, 0, 1});
      slog::Relation* readrel282 = db->getRelation("eval");
      evalindex257 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({2, 0, 1});
      slog::Relation* readrel284 = db->getRelation("eval_args");
      eval_argsindex258 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("eval_ans");
      eval_ansindex259 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 3, 0});
      slog::Relation* readrel288 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index260 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 2, 1});
      slog::Relation* readrel290 = db->getRelation("eval");
      evalindex261 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("eval_args");
      eval_argsindex262 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("app");
      appindex263 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0, 2, 1});
      slog::Relation* readrel296 = db->getRelation("eval");
      evalindex264 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("eval_args");
      eval_argsindex265 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 0});
      slog::Relation* readrel300 = db->getRelation("eval_args");
      eval_argsdelta273 = readrel300->getIndex(ord299, true);
      std::vector<u16> ord301({0, 1});
      slog::Relation* readrel302 = db->getRelation("eval_args_ans");
      eval_args_ansindex266 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({0, 1});
      slog::Relation* readrel304 = db->getRelation("eval_ans");
      eval_ansindex267 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 1});
      slog::Relation* readrel306 = db->getRelation("eval_args_ans");
      eval_args_ansindex268 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({2, 0, 1});
      slog::Relation* readrel308 = db->getRelation("delta");
      deltaindex269 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("prim");
      primindex270 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("prim");
      primdelta274 = readrel312->getIndex(ord311, true);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("delta");
      deltaindex271 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("delta");
      deltadelta275 = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({0, 1});
      slog::Relation* readrel318 = db->getRelation("delta_ans");
      delta_ansindex272 = readrel318->getIndex(ord317, false);
  
    }
    ReadTask276(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<3,1>(appindex256, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex257, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex258, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex259, std::array<u64,2>{v_c87, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index260, std::array<u64,4>{v_c10, v_c73, 0, 0}, [&](const std::array<u64,4>& m319) {
          u64 v_c17 = m319[2]; u64 v_c88 = m319[3];
          if (!slog::exists_probe<3,2>(evalindex261, std::array<u64,3>{v_c88, v_c10, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex262, std::array<u64,3>{v_c17, v_c10, 0})) return;
          slog::join_probe<3,2>(appindex263, std::array<u64,3>{v_c73, v_c17, 0}, [&](const std::array<u64,3>& m320) {
            u64 v_c89 = m320[2];
            slog::join_probe<3,3>(evalindex264, std::array<u64,3>{v_c88, v_c10, v_c89}, [&](const std::array<u64,3>& m321) {
              slog::join_probe_old<3,2>(eval_argsindex265, eval_argsdelta273, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m322) {
                u64 v_c90 = m322[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex266, std::array<u64,2>{v_c90, 0})) return;
                slog::join_probe<2,1>(eval_ansindex267, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m323) {
                  u64 v_c91 = m323[1];
                  slog::join_probe<2,1>(eval_args_ansindex268, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m324) {
                    u64 v_c79 = m324[1];
                    if (!slog::exists_probe<3,1>(deltaindex269, std::array<u64,3>{v_c79, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex270, primdelta274, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m325) {
                      u64 v_c92 = m325[1];
                      slog::join_probe_old<3,2>(deltaindex271, deltadelta275, std::array<u64,3>{v_c92, v_c79, 0}, [&](const std::array<u64,3>& m326) {
                        u64 v_c93 = m326[2];
                        slog::join_probe<2,1>(delta_ansindex272, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m327) {
                          u64 v_c94 = m327[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c88, v_c94}, std::array<u16,2>{0, 1});
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
        ReadTask276* _cont = new ReadTask276(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask276(db,b), false);
  // (crule (pre) (scan lambda __t3i6R439 xs eb) (body (join freevar (1 0) 1 eb x)) (head (mkstruct lst_absent (1 2 0) __8tPx738 xs x)) freevars.slog:28 #f)
  class ReadTask329 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex328;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lst_absent");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord330({1, 0});
      slog::Relation* readrel331 = db->getRelation("freevar");
      freevarindex328 = readrel331->getIndex(ord330, false);
  
    }
    ReadTask329(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c85 = _t[1];
        u64 v_c86 = _t[2];
        slog::join_probe<2,1>(freevarindex328, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m332) {
          u64 v_c1 = m332[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c85, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask329* _cont = new ReadTask329(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask329(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t75gL192) (join-old lambda (0 1 2) 1 (0 1 2) __t75gL192 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __36hc798 c __t36c5191) (join-old app (0 1 2) 1 (0 1 2) __t36c5191 ef es)) (head (mkstruct eval_args (1 2 0) __9QEA799 es c)) interp.slog:56 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex333;  slog::Index** lambdaindex334;  slog::Index** evalindex335;  slog::Index** appindex336;  slog::Index** freevardelta337;  slog::Index** lambdadelta338;  slog::Index** evaldelta339;  slog::Index** appdelta340;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("freevar");
      freevarindex333 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("freevar");
      freevardelta337 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1, 2});
      slog::Relation* readrel347 = db->getRelation("lambda");
      lambdaindex334 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1, 2});
      slog::Relation* readrel349 = db->getRelation("lambda");
      lambdadelta338 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({0, 2, 1});
      slog::Relation* readrel351 = db->getRelation("eval");
      evalindex335 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({0, 2, 1});
      slog::Relation* readrel353 = db->getRelation("eval");
      evaldelta339 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({0, 1, 2});
      slog::Relation* readrel355 = db->getRelation("app");
      appindex336 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1, 2});
      slog::Relation* readrel357 = db->getRelation("app");
      appdelta340 = readrel357->getIndex(ord356, true);
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[0];
        u64 v_c82 = _t[1];
        u64 v_c84 = _t[2];
        slog::join_probe_old<2,1>(freevarindex333, freevardelta337, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m358) {
          u64 v_c96 = m358[1];
          slog::join_probe_old<3,1>(lambdaindex334, lambdadelta338, std::array<u64,3>{v_c96, 0, 0}, [&](const std::array<u64,3>& m359) {
            u64 v_c85 = m359[1]; u64 v_c86 = m359[2];
            slog::join_all_old<3>(evalindex335, evaldelta339, [&](const std::array<u64,3>& m360) {
              u64 v_c97 = m360[0]; u64 v_c10 = m360[1]; u64 v_c98 = m360[2];
              slog::join_probe_old<3,1>(appindex336, appdelta340, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m361) {
                u64 v_c73 = m361[1]; u64 v_c17 = m361[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c10}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
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
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst0XfR396 const7297d2085ea0adffc396d546) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp8Sua1168 __t06tf412 __t0QMt425 __t0cS8401 __t9Q7F423 __t9Wjx395) (body (exists ref (1 0) 1 __tconst0XfR396) (exists ref (1 0) 1 __tconst1UOH427) (exists ref (1 0) 1 __tconst4i3L422) (exists app (2 0 1) 1 __t06tf412) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join ref (1 0) 1 __tconst0XfR396 __t1k9L397) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join ref (1 0) 1 __tconst4i3L422 __t4MSc414) (join app (1 2 0) 2 __t4MSc414 __t06tf412 __t8Bms415) (let __t8Onp417 (lpush __t9Q7F423 __t8Bms415))) (head (emit-temp temp0K4e1169 __t0QMt425 __t0cS8401 __t8Onp417 __t9Q7F423 __t9Wjx395) (mkstruct app (1 2 0) __t8pxg398 __t1k9L397 __t9Wjx395)) schemecfa.slog:26 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex362;  slog::Index** refindex363;  slog::Index** refindex364;  slog::Index** appindex365;  slog::Index** numindex366;  slog::Index** refindex367;  slog::Index** refindex368;  slog::Index** refindex369;  slog::Index** appindex370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0K4e1169");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp8Sua1168");
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("ref");
      refindex362 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("ref");
      refindex363 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0});
      slog::Relation* readrel377 = db->getRelation("ref");
      refindex364 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({2, 0, 1});
      slog::Relation* readrel379 = db->getRelation("app");
      appindex365 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("num");
      numindex366 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 0});
      slog::Relation* readrel383 = db->getRelation("ref");
      refindex367 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("ref");
      refindex368 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 0});
      slog::Relation* readrel387 = db->getRelation("ref");
      refindex369 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 0});
      slog::Relation* readrel389 = db->getRelation("app");
      appindex370 = readrel389->getIndex(ord388, false);
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const0457bba0679825d285ef7fa5;
      u64 v_c100 = v_const30f8b180d63559f2512b744f;
      u64 v_c101 = v_const7297d2085ea0adffc396d546;
      u64 v_c102 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c103 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c105 = _t[2];
        u64 v_c106 = _t[3];
        u64 v_c107 = _t[4];
        if (!slog::exists_probe<2,1>(refindex362, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<2,1>(refindex363, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex364, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<3,1>(appindex365, std::array<u64,3>{v_c103, 0, 0})) return;
        slog::join_probe<2,1>(numindex366, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m390) {
          u64 v_c108 = m390[1];
          slog::join_probe<2,1>(refindex367, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m391) {
            u64 v_c109 = m391[1];
            slog::join_probe<2,1>(refindex368, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m392) {
              u64 v_c110 = m392[1];
              slog::join_probe<2,1>(refindex369, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m393) {
                u64 v_c111 = m393[1];
                slog::join_probe<3,2>(appindex370, std::array<u64,3>{v_c111, v_c103, 0}, [&](const std::array<u64,3>& m394) {
                  u64 v_c112 = m394[2];
                  u64 v_c113 = _prim_lpush(db, v_c106, v_c112);
                  if (v_c113 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c104, v_c105, v_c113, v_c106, v_c107});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c109, v_c107}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp8Sua1168", _fires);
  
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
  // (crule (pre) (scan $sup56712x41x0x0x0 __d0 c ef es) (body (exists eval_args (1 2 0) 2 es c) (exists app (1 2 0) 2 ef es) (exists tick (2 0 1) 1 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t44Jo196) (exists eval_ans (0 1) 1 __t44Jo196) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old app (1 2 0) 2 (1 2 0) ef es __t0nYt200) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join-old eval_ans (0 1) 1 (0 1) __t44Jo196 __t4ROj198) (join-old eval_args_ans (0 1) 1 (0 1) __t3i0k199 vs) (join-old tick_ans (0 1) 1 (0 1) __t3z31201 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4ROj198 __t2BTJ197 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask419 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex395;  slog::Index** appindex396;  slog::Index** tickindex397;  slog::Index** evalindex398;  slog::Index** eval_ansindex399;  slog::Index** eval_argsindex400;  slog::Index** eval_args_ansindex401;  slog::Index** appindex402;  slog::Index** tickindex403;  slog::Index** tick_ansindex404;  slog::Index** eval_ansindex405;  slog::Index** eval_args_ansindex406;  slog::Index** tick_ansindex407;  slog::Index** closureindex408;  slog::Index** lambdaindex409;  slog::Index** evaldelta410;  slog::Index** eval_argsdelta411;  slog::Index** appdelta412;  slog::Index** tickdelta413;  slog::Index** eval_ansdelta414;  slog::Index** eval_args_ansdelta415;  slog::Index** tick_ansdelta416;  slog::Index** closuredelta417;  slog::Index** lambdadelta418;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("eval_args");
      eval_argsindex395 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 0});
      slog::Relation* readrel423 = db->getRelation("app");
      appindex396 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({2, 0, 1});
      slog::Relation* readrel425 = db->getRelation("tick");
      tickindex397 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 0});
      slog::Relation* readrel427 = db->getRelation("eval");
      evalindex398 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 2, 0});
      slog::Relation* readrel429 = db->getRelation("eval");
      evaldelta410 = readrel429->getIndex(ord428, true);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("eval_ans");
      eval_ansindex399 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("eval_args");
      eval_argsindex400 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("eval_args");
      eval_argsdelta411 = readrel435->getIndex(ord434, true);
      std::vector<u16> ord436({0, 1});
      slog::Relation* readrel437 = db->getRelation("eval_args_ans");
      eval_args_ansindex401 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("app");
      appindex402 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("app");
      appdelta412 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({1, 2, 0});
      slog::Relation* readrel443 = db->getRelation("tick");
      tickindex403 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 2, 0});
      slog::Relation* readrel445 = db->getRelation("tick");
      tickdelta413 = readrel445->getIndex(ord444, true);
      std::vector<u16> ord446({0, 1});
      slog::Relation* readrel447 = db->getRelation("tick_ans");
      tick_ansindex404 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0, 1});
      slog::Relation* readrel449 = db->getRelation("eval_ans");
      eval_ansindex405 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({0, 1});
      slog::Relation* readrel451 = db->getRelation("eval_ans");
      eval_ansdelta414 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1});
      slog::Relation* readrel453 = db->getRelation("eval_args_ans");
      eval_args_ansindex406 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("eval_args_ans");
      eval_args_ansdelta415 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({0, 1});
      slog::Relation* readrel457 = db->getRelation("tick_ans");
      tick_ansindex407 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("tick_ans");
      tick_ansdelta416 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({0, 1, 2});
      slog::Relation* readrel461 = db->getRelation("closure");
      closureindex408 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({0, 1, 2});
      slog::Relation* readrel463 = db->getRelation("closure");
      closuredelta417 = readrel463->getIndex(ord462, true);
      std::vector<u16> ord464({0, 1, 2});
      slog::Relation* readrel465 = db->getRelation("lambda");
      lambdaindex409 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1, 2});
      slog::Relation* readrel467 = db->getRelation("lambda");
      lambdadelta418 = readrel467->getIndex(ord466, true);
  
    }
    ReadTask419(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c114 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c17 = _t[3];
        if (!slog::exists_probe<3,2>(eval_argsindex395, std::array<u64,3>{v_c17, v_c10, 0})) return;
        if (!slog::exists_probe<3,2>(appindex396, std::array<u64,3>{v_c73, v_c17, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex397, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex398, evaldelta410, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m468) {
          u64 v_c115 = m468[2];
          if (!slog::exists_probe<2,1>(eval_ansindex399, std::array<u64,2>{v_c115, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex400, eval_argsdelta411, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m469) {
            u64 v_c116 = m469[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex401, std::array<u64,2>{v_c116, 0})) return;
            slog::join_probe_old<3,2>(appindex402, appdelta412, std::array<u64,3>{v_c73, v_c17, 0}, [&](const std::array<u64,3>& m470) {
              u64 v_c117 = m470[2];
              slog::join_probe_old<3,2>(tickindex403, tickdelta413, std::array<u64,3>{v_c117, v_c10, 0}, [&](const std::array<u64,3>& m471) {
                u64 v_c118 = m471[2];
                if (!slog::exists_probe<2,1>(tick_ansindex404, std::array<u64,2>{v_c118, 0})) return;
                slog::join_probe_old<2,1>(eval_ansindex405, eval_ansdelta414, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m472) {
                  u64 v_c119 = m472[1];
                  slog::join_probe_old<2,1>(eval_args_ansindex406, eval_args_ansdelta415, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m473) {
                    u64 v_c79 = m473[1];
                    slog::join_probe_old<2,1>(tick_ansindex407, tick_ansdelta416, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m474) {
                      u64 v_c9 = m474[1];
                      slog::join_probe_old<3,1>(closureindex408, closuredelta417, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m475) {
                        u64 v_c120 = m475[1]; u64 v_c82 = m475[2];
                        slog::join_probe_old<3,1>(lambdaindex409, lambdadelta418, std::array<u64,3>{v_c120, 0, 0}, [&](const std::array<u64,3>& m476) {
                          u64 v_c85 = m476[1]; u64 v_c86 = m476[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c86, v_c9}, std::array<u16,3>{1, 2, 0});
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
        ReadTask419* _cont = new ReadTask419(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask419(db,b), false);
  // (crule (pre (let __tconst9IXP677 constcd2a69ce5ca278db1d6da969) (let __tconst51tI19 const06abaa100ecef791ce028c56) (let _00024sqc4T4Y544 constd4735e3a265e16eee03f5971) (let _00024sqc7lRr545 const5feceb66ffc86f38d952786c) (let _00024sqc1s5u546 const6b86b273ff34fce19d6b804e) (let _00024sqo831x547 const5feceb66ffc86f38d952786c) (let _00024sqo8QLE548 const6b86b273ff34fce19d6b804e) (let _00024sqo7qSx549 const6b86b273ff34fce19d6b804e) (let _00024sqo2F2K550 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo7qSx549 __t1v1r22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo831x547 __t1v1r22 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8QLE548 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2F2K550 __t1v1r22 _00024seq2) (join _enum (0 1) 2 __t1v1r22 __tconst9IXP677) (join delta (1 2 0) 2 __tconst51tI19 _00024seq2 __t4bAF20) (join any_bool (0) 0 b) (letp _00024sql3fFG542 (aslst _00024seq2)) (let chk91j51043 (llen _00024sql3fFG542)) (eq _00024sqc4T4Y544 chk91j51043) (letp chk0Nkg1044 (lref _00024sql3fFG542 _00024sqc7lRr545)) (eq __t1v1r22 chk0Nkg1044) (letp chk40ph1045 (lref _00024sql3fFG542 _00024sqc1s5u546)) (eq __t1v1r22 chk40ph1045)) (head (emit-temp temp46yO1034 __t4bAF20 b) (mkstruct boolval (1 0) __t6st618 b)) interp.slog:121 #f)
  class ReadTask484 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex477;  slog::Index** $seq_atindex478;  slog::Index** $seq_atrindex479;  slog::Index** _enumindex480;  slog::Index** deltaindex481;  slog::Index** any_boolindex482;  slog::Index** $seq_atrdelta483;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp46yO1034");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord485({1, 0, 2});
      slog::Relation* readrel486 = db->getRelation("$seq_atr");
      driver_index = readrel486->getIndex(ord485, true);
      std::vector<u16> ord487({1, 0, 2});
      slog::Relation* readrel488 = db->getRelation("$seq_at");
      $seq_atindex477 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 0, 2});
      slog::Relation* readrel490 = db->getRelation("$seq_at");
      $seq_atindex478 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 0, 2});
      slog::Relation* readrel492 = db->getRelation("$seq_atr");
      $seq_atrindex479 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 0, 2});
      slog::Relation* readrel494 = db->getRelation("$seq_atr");
      $seq_atrdelta483 = readrel494->getIndex(ord493, true);
      std::vector<u16> ord495({0, 1});
      slog::Relation* readrel496 = db->getRelation("_enum");
      _enumindex480 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("delta");
      deltaindex481 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0});
      slog::Relation* readrel500 = db->getRelation("any_bool");
      any_boolindex482 = readrel500->getIndex(ord499, false);
  
    }
    ReadTask484(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c122 = v_const06abaa100ecef791ce028c56;
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
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c128, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m501) {
        u64 v_c130 = m501[1];
        u64 v_c32 = m501[2];
        if (buckethash(v_c130) != bucket) return;
        slog::join_probe<3,3>($seq_atindex477, std::array<u64,3>{v_c126, v_c130, v_c32}, [&](const std::array<u64,3>& m502) {
          slog::join_probe<3,3>($seq_atindex478, std::array<u64,3>{v_c127, v_c130, v_c32}, [&](const std::array<u64,3>& m503) {
            slog::join_probe_old<3,3>($seq_atrindex479, $seq_atrdelta483, std::array<u64,3>{v_c129, v_c130, v_c32}, [&](const std::array<u64,3>& m504) {
              slog::join_probe<2,2>(_enumindex480, std::array<u64,2>{v_c130, v_c121}, [&](const std::array<u64,2>& m505) {
                slog::join_probe<3,2>(deltaindex481, std::array<u64,3>{v_c122, v_c32, 0}, [&](const std::array<u64,3>& m506) {
                  u64 v_c131 = m506[2];
                  slog::join_all<1>(any_boolindex482, [&](const std::array<u64,1>& m507) {
                    u64 v_c132 = m507[0];
                    bool ok508 = true;
                    u64 v_c133 = _prim_aslst(db, v_c32, &ok508);
                    if (!ok508) return;
                    u64 v_c134 = _prim_llen(db, v_c133);
                    if (v_c134 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c123 != v_c134) return;
                    bool ok509 = true;
                    u64 v_c135 = _prim_lref(db, v_c133, v_c124, &ok509);
                    if (!ok509) return;
                    if (v_c130 != v_c135) return;
                    bool ok510 = true;
                    u64 v_c136 = _prim_lref(db, v_c133, v_c125, &ok510);
                    if (!ok510) return;
                    if (v_c130 != v_c136) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c131, v_c132});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
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
        ReadTask484* _cont = new ReadTask484(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask484(db,b), false);
  // (crule (pre (let __tconst9IXP677 constcd2a69ce5ca278db1d6da969) (let __tconst51tI19 const06abaa100ecef791ce028c56) (let _00024sqc4T4Y544 constd4735e3a265e16eee03f5971) (let _00024sqc7lRr545 const5feceb66ffc86f38d952786c) (let _00024sqc1s5u546 const6b86b273ff34fce19d6b804e) (let _00024sqo831x547 const5feceb66ffc86f38d952786c) (let _00024sqo8QLE548 const6b86b273ff34fce19d6b804e) (let _00024sqo7qSx549 const6b86b273ff34fce19d6b804e) (let _00024sqo2F2K550 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo831x547 __t1v1r22 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8QLE548 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qSx549 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2F2K550 __t1v1r22 _00024seq2) (join _enum (0 1) 2 __t1v1r22 __tconst9IXP677) (join delta (1 2 0) 2 __tconst51tI19 _00024seq2 __t4bAF20) (join any_bool (0) 0 b) (letp _00024sql3fFG542 (aslst _00024seq2)) (let chk4ezc1037 (llen _00024sql3fFG542)) (eq _00024sqc4T4Y544 chk4ezc1037) (letp chk5Xsx1038 (lref _00024sql3fFG542 _00024sqc7lRr545)) (eq __t1v1r22 chk5Xsx1038) (letp chk4MoV1039 (lref _00024sql3fFG542 _00024sqc1s5u546)) (eq __t1v1r22 chk4MoV1039)) (head (emit-temp temp46yO1034 __t4bAF20 b) (mkstruct boolval (1 0) __t6st618 b)) interp.slog:121 #f)
  class ReadTask520 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex511;  slog::Index** $seq_atrindex512;  slog::Index** $seq_atrindex513;  slog::Index** _enumindex514;  slog::Index** deltaindex515;  slog::Index** any_boolindex516;  slog::Index** $seq_atdelta517;  slog::Index** $seq_atrdelta518;  slog::Index** $seq_atrdelta519;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp46yO1034");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord521({1, 0, 2});
      slog::Relation* readrel522 = db->getRelation("$seq_at");
      driver_index = readrel522->getIndex(ord521, true);
      std::vector<u16> ord523({1, 0, 2});
      slog::Relation* readrel524 = db->getRelation("$seq_at");
      $seq_atindex511 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 0, 2});
      slog::Relation* readrel526 = db->getRelation("$seq_at");
      $seq_atdelta517 = readrel526->getIndex(ord525, true);
      std::vector<u16> ord527({1, 0, 2});
      slog::Relation* readrel528 = db->getRelation("$seq_atr");
      $seq_atrindex512 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 0, 2});
      slog::Relation* readrel530 = db->getRelation("$seq_atr");
      $seq_atrdelta518 = readrel530->getIndex(ord529, true);
      std::vector<u16> ord531({1, 0, 2});
      slog::Relation* readrel532 = db->getRelation("$seq_atr");
      $seq_atrindex513 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 0, 2});
      slog::Relation* readrel534 = db->getRelation("$seq_atr");
      $seq_atrdelta519 = readrel534->getIndex(ord533, true);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("_enum");
      _enumindex514 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("delta");
      deltaindex515 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({0});
      slog::Relation* readrel540 = db->getRelation("any_bool");
      any_boolindex516 = readrel540->getIndex(ord539, false);
  
    }
    ReadTask520(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c122 = v_const06abaa100ecef791ce028c56;
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
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c126, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m541) {
        u64 v_c130 = m541[1];
        u64 v_c32 = m541[2];
        if (buckethash(v_c130) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex511, $seq_atdelta517, std::array<u64,3>{v_c127, v_c130, v_c32}, [&](const std::array<u64,3>& m542) {
          slog::join_probe_old<3,3>($seq_atrindex512, $seq_atrdelta518, std::array<u64,3>{v_c128, v_c130, v_c32}, [&](const std::array<u64,3>& m543) {
            slog::join_probe_old<3,3>($seq_atrindex513, $seq_atrdelta519, std::array<u64,3>{v_c129, v_c130, v_c32}, [&](const std::array<u64,3>& m544) {
              slog::join_probe<2,2>(_enumindex514, std::array<u64,2>{v_c130, v_c121}, [&](const std::array<u64,2>& m545) {
                slog::join_probe<3,2>(deltaindex515, std::array<u64,3>{v_c122, v_c32, 0}, [&](const std::array<u64,3>& m546) {
                  u64 v_c131 = m546[2];
                  slog::join_all<1>(any_boolindex516, [&](const std::array<u64,1>& m547) {
                    u64 v_c132 = m547[0];
                    bool ok548 = true;
                    u64 v_c133 = _prim_aslst(db, v_c32, &ok548);
                    if (!ok548) return;
                    u64 v_c137 = _prim_llen(db, v_c133);
                    if (v_c137 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c123 != v_c137) return;
                    bool ok549 = true;
                    u64 v_c138 = _prim_lref(db, v_c133, v_c124, &ok549);
                    if (!ok549) return;
                    if (v_c130 != v_c138) return;
                    bool ok550 = true;
                    u64 v_c139 = _prim_lref(db, v_c133, v_c125, &ok550);
                    if (!ok550) return;
                    if (v_c130 != v_c139) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c131, v_c132});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
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
        ReadTask520* _cont = new ReadTask520(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask520(db,b), false);
  // (crule (pre (let __tconst9sKD800 constb9e118781cea1f9fa01462e0)) (scan boolval __t7ocu383 __t4akT382) (body (join _enum (0 1) 2 __t4akT382 __tconst9sKD800)) (head (emit scheme_false (0) __t7ocu383)) interp.slog:81 #f)
  class ReadTask552 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex551;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord553({0});
      slog::Relation* readrel554 = db->getRelation("scheme_false");
      head_index[0] = readrel554->getIndex(ord553, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord555({0, 1});
      slog::Relation* readrel556 = db->getRelation("_enum");
      _enumindex551 = readrel556->getIndex(ord555, false);
  
    }
    ReadTask552(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c140 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c141 = _t[0];
        u64 v_c142 = _t[1];
        slog::join_probe<2,2>(_enumindex551, std::array<u64,2>{v_c142, v_c140}, [&](const std::array<u64,2>& m557) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c141}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask552* _cont = new ReadTask552(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask552(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo7FTM622 e _00024seq0) (body (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let es (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (exists eval_args (1 2 0) 1 _00024seq0) (exists eval (1 2 0) 1 e) (exists eval_args (1 2 0) 1 es) (join $sup56712x37x0x0x0 (0 3 4 2 1) 3 _00024seq0 e es c __t2W25447) (join eval_args (0 2 1) 3 __t2W25447 c _00024seq0) (exists eval_args (1 2 0) 2 es c) (join eval (1 2 0) 2 e c __t25lG448) (exists eval_ans (0 1) 1 __t25lG448) (join eval_args (1 2 0) 2 es c __t6oBa449) (exists eval_args_ans (0 1) 1 __t6oBa449) (join eval_ans (0 1) 1 __t25lG448 __v0) (join eval_args_ans (0 1) 1 __t6oBa449 __v1) (letp chk8lMw991 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk8lMw991)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask570 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** eval_argsindex558;  slog::Index** evalindex559;  slog::Index** eval_argsindex560;  slog::Index** $sup56712x37x0x0x0index561;  slog::Index** eval_argsindex562;  slog::Index** eval_argsindex563;  slog::Index** evalindex564;  slog::Index** eval_ansindex565;  slog::Index** eval_argsindex566;  slog::Index** eval_args_ansindex567;  slog::Index** eval_ansindex568;  slog::Index** eval_args_ansindex569;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      std::vector<u16> ord571({1, 0, 2});
      slog::Relation* readrel572 = db->getRelation("$seq_at");
      driver_index = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("eval_args");
      eval_argsindex558 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("eval");
      evalindex559 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("eval_args");
      eval_argsindex560 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 3, 4, 2, 1});
      slog::Relation* readrel580 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index561 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({0, 2, 1});
      slog::Relation* readrel582 = db->getRelation("eval_args");
      eval_argsindex562 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("eval_args");
      eval_argsindex563 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 2, 0});
      slog::Relation* readrel586 = db->getRelation("eval");
      evalindex564 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("eval_ans");
      eval_ansindex565 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("eval_args");
      eval_argsindex566 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("eval_args_ans");
      eval_args_ansindex567 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("eval_ans");
      eval_ansindex568 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({0, 1});
      slog::Relation* readrel596 = db->getRelation("eval_args_ans");
      eval_args_ansindex569 = readrel596->getIndex(ord595, false);
  
    }
    ReadTask570(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = _prim_lempty(db);
      if (v_c7 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c6, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m597) {
        u64 v_c11 = m597[1];
        u64 v_c12 = m597[2];
        if (buckethash(v_c11) != bucket) return;
        bool ok598 = true;
        u64 v_c13 = _prim_aslst(db, v_c12, &ok598);
        if (!ok598) return;
        u64 v_c14 = _prim_llen(db, v_c13);
        if (v_c14 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c143 = _prim_ge(db, v_c14, v_c2);
        if (v_c143 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c143) return;
        u64 v_c16 = _prim__0002d(db, v_c14, v_c5);
        if (v_c16 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c17 = _prim_lslice(db, v_c13, v_c4, v_c16);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!slog::exists_probe<3,1>(eval_argsindex558, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex559, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex560, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x37x0x0x0index561, std::array<u64,5>{v_c12, v_c11, v_c17, 0, 0}, [&](const std::array<u64,5>& m600) {
          u64 v_c10 = m600[3]; u64 v_c18 = m600[4];
          slog::join_probe<3,3>(eval_argsindex562, std::array<u64,3>{v_c18, v_c10, v_c12}, [&](const std::array<u64,3>& m601) {
            if (!slog::exists_probe<3,2>(eval_argsindex563, std::array<u64,3>{v_c17, v_c10, 0})) return;
            slog::join_probe<3,2>(evalindex564, std::array<u64,3>{v_c11, v_c10, 0}, [&](const std::array<u64,3>& m602) {
              u64 v_c8 = m602[2];
              if (!slog::exists_probe<2,1>(eval_ansindex565, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe<3,2>(eval_argsindex566, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m603) {
                u64 v_c19 = m603[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex567, std::array<u64,2>{v_c19, 0})) return;
                slog::join_probe<2,1>(eval_ansindex568, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m604) {
                  u64 v_c9 = m604[1];
                  slog::join_probe<2,1>(eval_args_ansindex569, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m605) {
                    u64 v_c20 = m605[1];
                    bool ok606 = true;
                    u64 v_c144 = _prim_lref(db, v_c13, v_c3, &ok606);
                    if (!ok606) return;
                    if (v_c11 != v_c144) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c18, v_c7, v_c9, v_c20});
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
  // (crule (pre) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body (exists select_branch (2 3 0 1) 2 e2 e3) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9Q4F432) (exists eval_ans (0 1) 1 __t9Q4F432) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t1sbj433 __v0) (join-old eval_ans (0 1) 2 (0 1) __t9Q4F432 __v0) (join-old select_branch_ans (0 1) 1 (0 1) __t1sbj433 __v1)) (head (mkstruct eval (1 2 0) __9Gjy723 __v1 c)) interp.slog:87 #f)
  class ReadTask617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex607;  slog::Index** evalindex608;  slog::Index** eval_ansindex609;  slog::Index** select_branchindex610;  slog::Index** eval_ansindex611;  slog::Index** select_branch_ansindex612;  slog::Index** evaldelta613;  slog::Index** select_branchdelta614;  slog::Index** eval_ansdelta615;  slog::Index** select_branch_ansdelta616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord618({2, 3, 0, 1});
      slog::Relation* readrel619 = db->getRelation("select_branch");
      select_branchindex607 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("eval");
      evalindex608 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("eval");
      evaldelta613 = readrel623->getIndex(ord622, true);
      std::vector<u16> ord624({0, 1});
      slog::Relation* readrel625 = db->getRelation("eval_ans");
      eval_ansindex609 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({2, 3, 0, 1});
      slog::Relation* readrel627 = db->getRelation("select_branch");
      select_branchindex610 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({2, 3, 0, 1});
      slog::Relation* readrel629 = db->getRelation("select_branch");
      select_branchdelta614 = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({0, 1});
      slog::Relation* readrel631 = db->getRelation("eval_ans");
      eval_ansindex611 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({0, 1});
      slog::Relation* readrel633 = db->getRelation("eval_ans");
      eval_ansdelta615 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("select_branch_ans");
      select_branch_ansindex612 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({0, 1});
      slog::Relation* readrel637 = db->getRelation("select_branch_ans");
      select_branch_ansdelta616 = readrel637->getIndex(ord636, true);
  
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
        u64 v_c114 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c145 = _t[2];
        u64 v_c146 = _t[3];
        u64 v_c147 = _t[4];
        if (!slog::exists_probe<4,2>(select_branchindex607, std::array<u64,4>{v_c146, v_c147, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex608, evaldelta613, std::array<u64,3>{v_c145, v_c10, 0}, [&](const std::array<u64,3>& m638) {
          u64 v_c148 = m638[2];
          if (!slog::exists_probe<2,1>(eval_ansindex609, std::array<u64,2>{v_c148, 0})) return;
          slog::join_probe_old<4,2>(select_branchindex610, select_branchdelta614, std::array<u64,4>{v_c146, v_c147, 0, 0}, [&](const std::array<u64,4>& m639) {
            u64 v_c149 = m639[2]; u64 v_c9 = m639[3];
            slog::join_probe_old<2,2>(eval_ansindex611, eval_ansdelta615, std::array<u64,2>{v_c148, v_c9}, [&](const std::array<u64,2>& m640) {
              slog::join_probe_old<2,1>(select_branch_ansindex612, select_branch_ansdelta616, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m641) {
                u64 v_c20 = m641[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c20, v_c10}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
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
  // (crule (pre) (scan let __t0DPj440 x er eb) (body (exists eval (1 2 0) 1 __t0DPj440) (exists eval (1 2 0) 1 er) (exists eval (1 2 0) 1 eb) (join $sup56712x91x0x0x0 (2 3 4 0 1) 3 eb er x __t1bnm441 c) (join-old eval (0 2 1) 3 (0 2 1) __t1bnm441 c __t0DPj440) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t0jgp442) (exists eval_ans (0 1) 1 __t0jgp442) (join-old eval (1 2 0) 2 (1 2 0) eb c __t9j6S443) (exists eval_ans (0 1) 1 __t9j6S443) (join eval_ans (0 1) 1 __t0jgp442 vr) (join eval_ans (0 1) 1 __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask657 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex642;  slog::Index** evalindex643;  slog::Index** evalindex644;  slog::Index** $sup56712x91x0x0x0index645;  slog::Index** evalindex646;  slog::Index** evalindex647;  slog::Index** evalindex648;  slog::Index** eval_ansindex649;  slog::Index** evalindex650;  slog::Index** eval_ansindex651;  slog::Index** eval_ansindex652;  slog::Index** eval_ansindex653;  slog::Index** evaldelta654;  slog::Index** evaldelta655;  slog::Index** evaldelta656;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("eval_ans");
      head_index[0] = readrel659->getIndex(ord658, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("eval");
      evalindex642 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("eval");
      evalindex643 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("eval");
      evalindex644 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({2, 3, 4, 0, 1});
      slog::Relation* readrel667 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index645 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 2, 1});
      slog::Relation* readrel669 = db->getRelation("eval");
      evalindex646 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({0, 2, 1});
      slog::Relation* readrel671 = db->getRelation("eval");
      evaldelta654 = readrel671->getIndex(ord670, true);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("eval");
      evalindex647 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 0});
      slog::Relation* readrel675 = db->getRelation("eval");
      evalindex648 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 0});
      slog::Relation* readrel677 = db->getRelation("eval");
      evaldelta655 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("eval_ans");
      eval_ansindex649 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("eval");
      evalindex650 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("eval");
      evaldelta656 = readrel683->getIndex(ord682, true);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("eval_ans");
      eval_ansindex651 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_ans");
      eval_ansindex652 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("eval_ans");
      eval_ansindex653 = readrel689->getIndex(ord688, false);
  
    }
    ReadTask657(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c151 = _t[2];
        u64 v_c86 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex642, std::array<u64,3>{v_c150, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex643, std::array<u64,3>{v_c151, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex644, std::array<u64,3>{v_c86, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x91x0x0x0index645, std::array<u64,5>{v_c86, v_c151, v_c1, 0, 0}, [&](const std::array<u64,5>& m690) {
          u64 v_c152 = m690[3]; u64 v_c10 = m690[4];
          slog::join_probe_old<3,3>(evalindex646, evaldelta654, std::array<u64,3>{v_c152, v_c10, v_c150}, [&](const std::array<u64,3>& m691) {
            if (!slog::exists_probe<3,2>(evalindex647, std::array<u64,3>{v_c86, v_c10, 0})) return;
            slog::join_probe_old<3,2>(evalindex648, evaldelta655, std::array<u64,3>{v_c151, v_c10, 0}, [&](const std::array<u64,3>& m692) {
              u64 v_c153 = m692[2];
              if (!slog::exists_probe<2,1>(eval_ansindex649, std::array<u64,2>{v_c153, 0})) return;
              slog::join_probe_old<3,2>(evalindex650, evaldelta656, std::array<u64,3>{v_c86, v_c10, 0}, [&](const std::array<u64,3>& m693) {
                u64 v_c154 = m693[2];
                if (!slog::exists_probe<2,1>(eval_ansindex651, std::array<u64,2>{v_c154, 0})) return;
                slog::join_probe<2,1>(eval_ansindex652, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m694) {
                  u64 v_c155 = m694[1];
                  slog::join_probe<2,1>(eval_ansindex653, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m695) {
                    u64 v_c94 = m695[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c152, v_c94}, std::array<u16,2>{0, 1});
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
        ReadTask657* _cont = new ReadTask657(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask657(db,b), false);
  // (crule (pre) (scan let __t6gxv132 y er eb) (body (join freevar (1 0) 1 er x)) (head (emit freevar (0 1) x __t6gxv132)) freevars.slog:21 #f)
  class ReadTask697 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex696;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("freevar");
      head_index[0] = readrel699->getIndex(ord698, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("freevar");
      freevarindex696 = readrel701->getIndex(ord700, false);
  
    }
    ReadTask697(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c156 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c151 = _t[2];
        u64 v_c86 = _t[3];
        slog::join_probe<2,1>(freevarindex696, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m702) {
          u64 v_c1 = m702[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c156}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:21", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask697* _cont = new ReadTask697(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask697(db,b), false);
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst93LG421 constba2df4903a2c14e86dc3bcca) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst0XfR396 const7297d2085ea0adffc396d546) (let __tconst466s389 const6b86b273ff34fce19d6b804e) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp7rsY1167 __t06tf412 __t0cS8401 __t36Dl424 __t8uoE394 __t9Q7F423) (body (exists num (1 0) 1 __tconst466s389) (exists ref (1 0) 1 __tconst0XfR396) (exists ref (1 0) 1 __tconst1UOH427) (exists ref (1 0) 1 __tconst4i3L422) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join num (1 0) 1 __tconst466s389 __t7CfZ390) (join ref (1 0) 1 __tconst0XfR396 __t1k9L397) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join ref (1 0) 1 __tconst4i3L422 __t4MSc414) (let __t0QMt425 (lpush __t36Dl424 __tconst93LG421)) (let __t9Wjx395 (lpush __t8uoE394 __t7CfZ390))) (head (emit-temp temp8Sua1168 __t06tf412 __t0QMt425 __t0cS8401 __t9Q7F423 __t9Wjx395) (mkstruct app (1 2 0) __t8Bms415 __t4MSc414 __t06tf412)) schemecfa.slog:26 #f)
  class ReadTask712 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex703;  slog::Index** refindex704;  slog::Index** refindex705;  slog::Index** refindex706;  slog::Index** numindex707;  slog::Index** numindex708;  slog::Index** refindex709;  slog::Index** refindex710;  slog::Index** refindex711;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Sua1168");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp7rsY1167");
      std::vector<u16> ord713({1, 0});
      slog::Relation* readrel714 = db->getRelation("num");
      numindex703 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 0});
      slog::Relation* readrel716 = db->getRelation("ref");
      refindex704 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 0});
      slog::Relation* readrel718 = db->getRelation("ref");
      refindex705 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 0});
      slog::Relation* readrel720 = db->getRelation("ref");
      refindex706 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({1, 0});
      slog::Relation* readrel722 = db->getRelation("num");
      numindex707 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 0});
      slog::Relation* readrel724 = db->getRelation("num");
      numindex708 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0});
      slog::Relation* readrel726 = db->getRelation("ref");
      refindex709 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 0});
      slog::Relation* readrel728 = db->getRelation("ref");
      refindex710 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("ref");
      refindex711 = readrel730->getIndex(ord729, false);
  
    }
    ReadTask712(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const0457bba0679825d285ef7fa5;
      u64 v_c157 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c100 = v_const30f8b180d63559f2512b744f;
      u64 v_c101 = v_const7297d2085ea0adffc396d546;
      u64 v_c158 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c102 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c103 = _t[0];
        u64 v_c105 = _t[1];
        u64 v_c159 = _t[2];
        u64 v_c160 = _t[3];
        u64 v_c106 = _t[4];
        if (!slog::exists_probe<2,1>(numindex703, std::array<u64,2>{v_c158, 0})) return;
        if (!slog::exists_probe<2,1>(refindex704, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<2,1>(refindex705, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex706, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<2,1>(numindex707, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m731) {
          u64 v_c108 = m731[1];
          slog::join_probe<2,1>(numindex708, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m732) {
            u64 v_c161 = m732[1];
            slog::join_probe<2,1>(refindex709, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m733) {
              u64 v_c109 = m733[1];
              slog::join_probe<2,1>(refindex710, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m734) {
                u64 v_c110 = m734[1];
                slog::join_probe<2,1>(refindex711, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m735) {
                  u64 v_c111 = m735[1];
                  u64 v_c104 = _prim_lpush(db, v_c159, v_c157);
                  if (v_c104 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                  u64 v_c107 = _prim_lpush(db, v_c160, v_c161);
                  if (v_c107 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c103, v_c104, v_c105, v_c106, v_c107});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c111, v_c103}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp7rsY1167", _fires);
  
      if (!_done)
      {
        ReadTask712* _cont = new ReadTask712(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask712(db,b), false);
  // (crule (pre (let __tconst7oTo733 constb9e118781cea1f9fa01462e0)) (scan temp0LTu995 __t7rOF381) (body (join _enum (1 0) 1 __tconst7oTo733 __t1FRr378) (join boolval (1 0) 1 __t1FRr378 __t7RmO379)) (head (emit delta_ans (0 1) __t7rOF381 __t7RmO379)) interp.slog:114 #f)
  class ReadTask738 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex736;  slog::Index** boolvalindex737;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("delta_ans");
      head_index[0] = readrel740->getIndex(ord739, false);
      outer_rel = db->getRelation("temp0LTu995");
      std::vector<u16> ord741({1, 0});
      slog::Relation* readrel742 = db->getRelation("_enum");
      _enumindex736 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 0});
      slog::Relation* readrel744 = db->getRelation("boolval");
      boolvalindex737 = readrel744->getIndex(ord743, false);
  
    }
    ReadTask738(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c162 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c163 = _t[0];
        slog::join_probe<2,1>(_enumindex736, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m745) {
          u64 v_c164 = m745[1];
          slog::join_probe<2,1>(boolvalindex737, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m746) {
            u64 v_c165 = m746[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c163, v_c165}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:temp0LTu995", _fires);
  
      if (!_done)
      {
        ReadTask738* _cont = new ReadTask738(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask738(db,b), false);
  // (crule (pre (let __trid44iP679 const25f568921d120de09a5f575d) (let __trel3OQ9680 const4a59dbb9cb3129dfcc75170b) (let __tcol1pAq681 const5feceb66ffc86f38d952786c) (let __trel9Vve682 const4a59dbb9cb3129dfcc75170b) (let __tcol76Ta683 const6b86b273ff34fce19d6b804e)) (scan $sup56712x91x0x0x0 __d0 c eb er x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid44iP679 __trel3OQ9680 __tcol1pAq681 (1 2 3 4 0)) (tycheck c (accept seq) __trid44iP679 __trel9Vve682 __tcol76Ta683 (1 2 3 4 0)) (mkstruct eval (1 2 0) __2Rv6678 er c)) interp.slog:92 #f)
  class ReadTask756 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid747;  u32 sid748;  u32 sid749;  u32 sid750;  u32 sid751;  u32 sid752;  u32 sid753;  u32 sid754;  u32 sid755;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      sid747 = db->getRelation("app")->getStructId();
      sid748 = db->getRelation("boolean")->getStructId();
      sid749 = db->getRelation("if")->getStructId();
      sid750 = db->getRelation("lambda")->getStructId();
      sid751 = db->getRelation("let")->getStructId();
      sid752 = db->getRelation("letrec")->getStructId();
      sid753 = db->getRelation("num")->getStructId();
      sid754 = db->getRelation("ref")->getStructId();
      sid755 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask756(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c166 = v_const25f568921d120de09a5f575d;
      u64 v_c167 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c168 = v_const5feceb66ffc86f38d952786c;
      u64 v_c169 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c114 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c86 = _t[2];
        u64 v_c151 = _t[3];
        u64 v_c1 = _t[4];
        ++_fires;
        if (!((is_struct(v_c151) && (decode_struct_id(v_c151) == sid747 || decode_struct_id(v_c151) == sid748 || decode_struct_id(v_c151) == sid749 || decode_struct_id(v_c151) == sid750 || decode_struct_id(v_c151) == sid751 || decode_struct_id(v_c151) == sid752 || decode_struct_id(v_c151) == sid753 || decode_struct_id(v_c151) == sid754 || decode_struct_id(v_c151) == sid755))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c166, v_c167, v_c168, v_c151}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c10)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c166, v_c169, v_c170, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c151, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:$sup56712x91x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask756* _cont = new ReadTask756(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask756(db,b), false);
  // (crule (pre) (scan temp4nra1103 __t4EG4161 e es x) (body (let __t0whu162 (lpush __t4EG4161 e))) (head (emit-temp temp69gU1104 __t0whu162 es x)) freevars.slog:35 #f)
  class ReadTask757 : public slog::Task
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
      head_rel[0] = db->getRelation("temp69gU1104");
      outer_rel = db->getRelation("temp4nra1103");
  
    }
    ReadTask757(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c171 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c1 = _t[3];
        u64 v_c172 = _prim_lpush(db, v_c171, v_c11);
        if (v_c172 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c172, v_c17, v_c1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp4nra1103", _fires);
  
      if (!_done)
      {
        ReadTask757* _cont = new ReadTask757(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask757(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72)) (scan temp105Q1014 __t18GV497 __t6FoF491) (body (join let (2 1 3 0) 3 __t18GV497 __tconst8pH5498 __t6FoF491 __t9OTU499)) (head (emit program (0) __t9OTU499)) schemecfa.slog:51 #f)
  class ReadTask759 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex758;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord760({0});
      slog::Relation* readrel761 = db->getRelation("program");
      head_index[0] = readrel761->getIndex(ord760, false);
      outer_rel = db->getRelation("temp105Q1014");
      std::vector<u16> ord762({2, 1, 3, 0});
      slog::Relation* readrel763 = db->getRelation("let");
      letindex758 = readrel763->getIndex(ord762, false);
  
    }
    ReadTask759(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const2d53b3c21fa5cc786ac46d72;
  
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
        slog::join_probe<4,3>(letindex758, std::array<u64,4>{v_c173, v_c40, v_c174, 0}, [&](const std::array<u64,4>& m764) {
          u64 v_c175 = m764[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c175}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp105Q1014", _fires);
  
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
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5)) (scan temp0Cgl1173 __t0QD8426 __t5V4O405) (body (exists app (2 0 1) 1 __t5V4O405) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join app (1 2 0) 2 __t4O08407 __t5V4O405 __t2wub408)) (head (emit-temp temp2ZI81174 __t0QD8426 __t2wub408) (mkstruct let (2 1 3 0) __t3BHe428 __t0QD8426 __tconst1UOH427 __t2wub408)) schemecfa.slog:26 #f)
  class ReadTask768 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex765;  slog::Index** refindex766;  slog::Index** appindex767;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2ZI81174");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp0Cgl1173");
      std::vector<u16> ord769({2, 0, 1});
      slog::Relation* readrel770 = db->getRelation("app");
      appindex765 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 0});
      slog::Relation* readrel772 = db->getRelation("ref");
      refindex766 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("app");
      appindex767 = readrel774->getIndex(ord773, false);
  
    }
    ReadTask768(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const0457bba0679825d285ef7fa5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c176 = _t[0];
        u64 v_c177 = _t[1];
        if (!slog::exists_probe<3,1>(appindex765, std::array<u64,3>{v_c177, 0, 0})) return;
        slog::join_probe<2,1>(refindex766, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m775) {
          u64 v_c110 = m775[1];
          slog::join_probe<3,2>(appindex767, std::array<u64,3>{v_c110, v_c177, 0}, [&](const std::array<u64,3>& m776) {
            u64 v_c178 = m776[2];
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c176, v_c178});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c176, v_c99, v_c178}, std::array<u16,4>{2, 1, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp0Cgl1173", _fires);
  
      if (!_done)
      {
        ReadTask768* _cont = new ReadTask768(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask768(db,b), false);
  // (crule (pre) (scan freevar y __t8ny9128) (body (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t8ny9128 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __1mVf736 c __t8Z3R127) (join-old app (0 1 2) 1 (0 1 2) __t8Z3R127 ef es)) (head (mkstruct eval (1 2 0) __8uDI737 ef c)) interp.slog:56 #f)
  class ReadTask784 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindingindex777;  slog::Index** lambdaindex778;  slog::Index** evalindex779;  slog::Index** appindex780;  slog::Index** lambdadelta781;  slog::Index** evaldelta782;  slog::Index** appdelta783;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord785({0, 1, 2});
      slog::Relation* readrel786 = db->getRelation("binding");
      bindingindex777 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({0, 1, 2});
      slog::Relation* readrel788 = db->getRelation("lambda");
      lambdaindex778 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({0, 1, 2});
      slog::Relation* readrel790 = db->getRelation("lambda");
      lambdadelta781 = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({0, 2, 1});
      slog::Relation* readrel792 = db->getRelation("eval");
      evalindex779 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 2, 1});
      slog::Relation* readrel794 = db->getRelation("eval");
      evaldelta782 = readrel794->getIndex(ord793, true);
      std::vector<u16> ord795({0, 1, 2});
      slog::Relation* readrel796 = db->getRelation("app");
      appindex780 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1, 2});
      slog::Relation* readrel798 = db->getRelation("app");
      appdelta783 = readrel798->getIndex(ord797, true);
  
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
        u64 v_c83 = _t[0];
        u64 v_c179 = _t[1];
        slog::join_probe<3,1>(bindingindex777, std::array<u64,3>{v_c83, 0, 0}, [&](const std::array<u64,3>& m799) {
          u64 v_c82 = m799[1]; u64 v_c84 = m799[2];
          slog::join_probe_old<3,1>(lambdaindex778, lambdadelta781, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m800) {
            u64 v_c85 = m800[1]; u64 v_c86 = m800[2];
            slog::join_all_old<3>(evalindex779, evaldelta782, [&](const std::array<u64,3>& m801) {
              u64 v_c180 = m801[0]; u64 v_c10 = m801[1]; u64 v_c181 = m801[2];
              slog::join_probe_old<3,1>(appindex780, appdelta783, std::array<u64,3>{v_c181, 0, 0}, [&](const std::array<u64,3>& m802) {
                u64 v_c73 = m802[1]; u64 v_c17 = m802[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c73, v_c10}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
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
  // (crule (pre) (scan $sup56712x41x0x0x0 __t9lTe203 c ef es) (body (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (exists eval_args (1 2 0) 2 es c) (exists tick (2 0 1) 1 c) (join-old eval (0 2 1) 2 (0 2 1) __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t6XAE206 __t6hhS205 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask832 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex803;  slog::Index** evalindex804;  slog::Index** eval_argsindex805;  slog::Index** tickindex806;  slog::Index** evalindex807;  slog::Index** appindex808;  slog::Index** tickindex809;  slog::Index** evalindex810;  slog::Index** eval_ansindex811;  slog::Index** eval_argsindex812;  slog::Index** eval_args_ansindex813;  slog::Index** tickindex814;  slog::Index** tick_ansindex815;  slog::Index** eval_ansindex816;  slog::Index** eval_args_ansindex817;  slog::Index** tick_ansindex818;  slog::Index** evalindex819;  slog::Index** closureindex820;  slog::Index** lambdaindex821;  slog::Index** evalindex822;  slog::Index** eval_ansindex823;  slog::Index** evaldelta824;  slog::Index** appdelta825;  slog::Index** evaldelta826;  slog::Index** eval_argsdelta827;  slog::Index** tickdelta828;  slog::Index** closuredelta829;  slog::Index** lambdadelta830;  slog::Index** evaldelta831;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord833({0, 1});
      slog::Relation* readrel834 = db->getRelation("eval_ans");
      head_index[0] = readrel834->getIndex(ord833, false);
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord835({1, 2, 0});
      slog::Relation* readrel836 = db->getRelation("app");
      appindex803 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({1, 2, 0});
      slog::Relation* readrel838 = db->getRelation("eval");
      evalindex804 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 0});
      slog::Relation* readrel840 = db->getRelation("eval_args");
      eval_argsindex805 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({2, 0, 1});
      slog::Relation* readrel842 = db->getRelation("tick");
      tickindex806 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({0, 2, 1});
      slog::Relation* readrel844 = db->getRelation("eval");
      evalindex807 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({0, 2, 1});
      slog::Relation* readrel846 = db->getRelation("eval");
      evaldelta824 = readrel846->getIndex(ord845, true);
      std::vector<u16> ord847({0, 1, 2});
      slog::Relation* readrel848 = db->getRelation("app");
      appindex808 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({0, 1, 2});
      slog::Relation* readrel850 = db->getRelation("app");
      appdelta825 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({1, 2, 0});
      slog::Relation* readrel852 = db->getRelation("tick");
      tickindex809 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 2, 0});
      slog::Relation* readrel854 = db->getRelation("eval");
      evalindex810 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 0});
      slog::Relation* readrel856 = db->getRelation("eval");
      evaldelta826 = readrel856->getIndex(ord855, true);
      std::vector<u16> ord857({0, 1});
      slog::Relation* readrel858 = db->getRelation("eval_ans");
      eval_ansindex811 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("eval_args");
      eval_argsindex812 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("eval_args");
      eval_argsdelta827 = readrel862->getIndex(ord861, true);
      std::vector<u16> ord863({0, 1});
      slog::Relation* readrel864 = db->getRelation("eval_args_ans");
      eval_args_ansindex813 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("tick");
      tickindex814 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 2, 0});
      slog::Relation* readrel868 = db->getRelation("tick");
      tickdelta828 = readrel868->getIndex(ord867, true);
      std::vector<u16> ord869({0, 1});
      slog::Relation* readrel870 = db->getRelation("tick_ans");
      tick_ansindex815 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({0, 1});
      slog::Relation* readrel872 = db->getRelation("eval_ans");
      eval_ansindex816 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({0, 1});
      slog::Relation* readrel874 = db->getRelation("eval_args_ans");
      eval_args_ansindex817 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("tick_ans");
      tick_ansindex818 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({2, 0, 1});
      slog::Relation* readrel878 = db->getRelation("eval");
      evalindex819 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 1, 2});
      slog::Relation* readrel880 = db->getRelation("closure");
      closureindex820 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({0, 1, 2});
      slog::Relation* readrel882 = db->getRelation("closure");
      closuredelta829 = readrel882->getIndex(ord881, true);
      std::vector<u16> ord883({0, 1, 2});
      slog::Relation* readrel884 = db->getRelation("lambda");
      lambdaindex821 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({0, 1, 2});
      slog::Relation* readrel886 = db->getRelation("lambda");
      lambdadelta830 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("eval");
      evalindex822 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("eval");
      evaldelta831 = readrel890->getIndex(ord889, true);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("eval_ans");
      eval_ansindex823 = readrel892->getIndex(ord891, false);
  
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
        u64 v_c182 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c17 = _t[3];
        if (!slog::exists_probe<3,2>(appindex803, std::array<u64,3>{v_c73, v_c17, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex804, std::array<u64,3>{v_c73, v_c10, 0})) return;
        if (!slog::exists_probe<3,2>(eval_argsindex805, std::array<u64,3>{v_c17, v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex806, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe_old<3,2>(evalindex807, evaldelta824, std::array<u64,3>{v_c182, v_c10, 0}, [&](const std::array<u64,3>& m893) {
          u64 v_c183 = m893[2];
          slog::join_probe_old<3,3>(appindex808, appdelta825, std::array<u64,3>{v_c183, v_c73, v_c17}, [&](const std::array<u64,3>& m894) {
            if (!slog::exists_probe<3,2>(tickindex809, std::array<u64,3>{v_c183, v_c10, 0})) return;
            slog::join_probe_old<3,2>(evalindex810, evaldelta826, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m895) {
              u64 v_c184 = m895[2];
              if (!slog::exists_probe<2,1>(eval_ansindex811, std::array<u64,2>{v_c184, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex812, eval_argsdelta827, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m896) {
                u64 v_c185 = m896[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex813, std::array<u64,2>{v_c185, 0})) return;
                slog::join_probe_old<3,2>(tickindex814, tickdelta828, std::array<u64,3>{v_c183, v_c10, 0}, [&](const std::array<u64,3>& m897) {
                  u64 v_c186 = m897[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex815, std::array<u64,2>{v_c186, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex816, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m898) {
                    u64 v_c187 = m898[1];
                    slog::join_probe<2,1>(eval_args_ansindex817, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m899) {
                      u64 v_c79 = m899[1];
                      slog::join_probe<2,1>(tick_ansindex818, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m900) {
                        u64 v_c9 = m900[1];
                        if (!slog::exists_probe<3,1>(evalindex819, std::array<u64,3>{v_c9, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex820, closuredelta829, std::array<u64,3>{v_c187, 0, 0}, [&](const std::array<u64,3>& m901) {
                          u64 v_c188 = m901[1]; u64 v_c82 = m901[2];
                          slog::join_probe_old<3,1>(lambdaindex821, lambdadelta830, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m902) {
                            u64 v_c85 = m902[1]; u64 v_c86 = m902[2];
                            slog::join_probe_old<3,2>(evalindex822, evaldelta831, std::array<u64,3>{v_c86, v_c9, 0}, [&](const std::array<u64,3>& m903) {
                              u64 v_c189 = m903[2];
                              slog::join_probe<2,1>(eval_ansindex823, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m904) {
                                u64 v_c94 = m904[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c182, v_c94}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan eval_args_ans __t58jO207 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t58jO207 c es) (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join-old $sup56712x41x0x0x0 (1 3 0 2) 2 (1 3 0 2) c es __t9lTe203 ef) (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (join-old eval (0 2 1) 2 (0 2 1) __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join-old tick_ans (0 1) 1 (0 1) __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t6XAE206 __t6hhS205 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join-old eval_ans (0 1) 1 (0 1) __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask937 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex905;  slog::Index** evalindex906;  slog::Index** appindex907;  slog::Index** tickindex908;  slog::Index** $sup56712x41x0x0x0index909;  slog::Index** appindex910;  slog::Index** evalindex911;  slog::Index** evalindex912;  slog::Index** appindex913;  slog::Index** tickindex914;  slog::Index** evalindex915;  slog::Index** eval_ansindex916;  slog::Index** tickindex917;  slog::Index** tick_ansindex918;  slog::Index** eval_ansindex919;  slog::Index** tick_ansindex920;  slog::Index** evalindex921;  slog::Index** closureindex922;  slog::Index** lambdaindex923;  slog::Index** evalindex924;  slog::Index** eval_ansindex925;  slog::Index** eval_argsdelta926;  slog::Index** $sup56712x41x0x0x0delta927;  slog::Index** evaldelta928;  slog::Index** appdelta929;  slog::Index** evaldelta930;  slog::Index** tickdelta931;  slog::Index** tick_ansdelta932;  slog::Index** closuredelta933;  slog::Index** lambdadelta934;  slog::Index** evaldelta935;  slog::Index** eval_ansdelta936;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord938({0, 1});
      slog::Relation* readrel939 = db->getRelation("eval_ans");
      head_index[0] = readrel939->getIndex(ord938, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord940({0, 2, 1});
      slog::Relation* readrel941 = db->getRelation("eval_args");
      eval_argsindex905 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({0, 2, 1});
      slog::Relation* readrel943 = db->getRelation("eval_args");
      eval_argsdelta926 = readrel943->getIndex(ord942, true);
      std::vector<u16> ord944({2, 0, 1});
      slog::Relation* readrel945 = db->getRelation("eval");
      evalindex906 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({2, 0, 1});
      slog::Relation* readrel947 = db->getRelation("app");
      appindex907 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({2, 0, 1});
      slog::Relation* readrel949 = db->getRelation("tick");
      tickindex908 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 3, 0, 2});
      slog::Relation* readrel951 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index909 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 3, 0, 2});
      slog::Relation* readrel953 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta927 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({1, 2, 0});
      slog::Relation* readrel955 = db->getRelation("app");
      appindex910 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({1, 2, 0});
      slog::Relation* readrel957 = db->getRelation("eval");
      evalindex911 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({0, 2, 1});
      slog::Relation* readrel959 = db->getRelation("eval");
      evalindex912 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({0, 2, 1});
      slog::Relation* readrel961 = db->getRelation("eval");
      evaldelta928 = readrel961->getIndex(ord960, true);
      std::vector<u16> ord962({0, 1, 2});
      slog::Relation* readrel963 = db->getRelation("app");
      appindex913 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({0, 1, 2});
      slog::Relation* readrel965 = db->getRelation("app");
      appdelta929 = readrel965->getIndex(ord964, true);
      std::vector<u16> ord966({1, 2, 0});
      slog::Relation* readrel967 = db->getRelation("tick");
      tickindex914 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 2, 0});
      slog::Relation* readrel969 = db->getRelation("eval");
      evalindex915 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 2, 0});
      slog::Relation* readrel971 = db->getRelation("eval");
      evaldelta930 = readrel971->getIndex(ord970, true);
      std::vector<u16> ord972({0, 1});
      slog::Relation* readrel973 = db->getRelation("eval_ans");
      eval_ansindex916 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("tick");
      tickindex917 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 0});
      slog::Relation* readrel977 = db->getRelation("tick");
      tickdelta931 = readrel977->getIndex(ord976, true);
      std::vector<u16> ord978({0, 1});
      slog::Relation* readrel979 = db->getRelation("tick_ans");
      tick_ansindex918 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({0, 1});
      slog::Relation* readrel981 = db->getRelation("eval_ans");
      eval_ansindex919 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({0, 1});
      slog::Relation* readrel983 = db->getRelation("tick_ans");
      tick_ansindex920 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({0, 1});
      slog::Relation* readrel985 = db->getRelation("tick_ans");
      tick_ansdelta932 = readrel985->getIndex(ord984, true);
      std::vector<u16> ord986({2, 0, 1});
      slog::Relation* readrel987 = db->getRelation("eval");
      evalindex921 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1, 2});
      slog::Relation* readrel989 = db->getRelation("closure");
      closureindex922 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 1, 2});
      slog::Relation* readrel991 = db->getRelation("closure");
      closuredelta933 = readrel991->getIndex(ord990, true);
      std::vector<u16> ord992({0, 1, 2});
      slog::Relation* readrel993 = db->getRelation("lambda");
      lambdaindex923 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({0, 1, 2});
      slog::Relation* readrel995 = db->getRelation("lambda");
      lambdadelta934 = readrel995->getIndex(ord994, true);
      std::vector<u16> ord996({1, 2, 0});
      slog::Relation* readrel997 = db->getRelation("eval");
      evalindex924 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 2, 0});
      slog::Relation* readrel999 = db->getRelation("eval");
      evaldelta935 = readrel999->getIndex(ord998, true);
      std::vector<u16> ord1000({0, 1});
      slog::Relation* readrel1001 = db->getRelation("eval_ans");
      eval_ansindex925 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({0, 1});
      slog::Relation* readrel1003 = db->getRelation("eval_ans");
      eval_ansdelta936 = readrel1003->getIndex(ord1002, true);
  
    }
    ReadTask937(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c185 = _t[0];
        u64 v_c79 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex905, eval_argsdelta926, std::array<u64,3>{v_c185, 0, 0}, [&](const std::array<u64,3>& m1004) {
          u64 v_c10 = m1004[1]; u64 v_c17 = m1004[2];
          if (!slog::exists_probe<3,1>(evalindex906, std::array<u64,3>{v_c10, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex907, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex908, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x41x0x0x0index909, $sup56712x41x0x0x0delta927, std::array<u64,4>{v_c10, v_c17, 0, 0}, [&](const std::array<u64,4>& m1005) {
            u64 v_c182 = m1005[2]; u64 v_c73 = m1005[3];
            if (!slog::exists_probe<3,2>(appindex910, std::array<u64,3>{v_c73, v_c17, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex911, std::array<u64,3>{v_c73, v_c10, 0})) return;
            slog::join_probe_old<3,2>(evalindex912, evaldelta928, std::array<u64,3>{v_c182, v_c10, 0}, [&](const std::array<u64,3>& m1006) {
              u64 v_c183 = m1006[2];
              slog::join_probe_old<3,3>(appindex913, appdelta929, std::array<u64,3>{v_c183, v_c73, v_c17}, [&](const std::array<u64,3>& m1007) {
                if (!slog::exists_probe<3,2>(tickindex914, std::array<u64,3>{v_c183, v_c10, 0})) return;
                slog::join_probe_old<3,2>(evalindex915, evaldelta930, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m1008) {
                  u64 v_c184 = m1008[2];
                  if (!slog::exists_probe<2,1>(eval_ansindex916, std::array<u64,2>{v_c184, 0})) return;
                  slog::join_probe_old<3,2>(tickindex917, tickdelta931, std::array<u64,3>{v_c183, v_c10, 0}, [&](const std::array<u64,3>& m1009) {
                    u64 v_c186 = m1009[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex918, std::array<u64,2>{v_c186, 0})) return;
                    slog::join_probe<2,1>(eval_ansindex919, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m1010) {
                      u64 v_c187 = m1010[1];
                      slog::join_probe_old<2,1>(tick_ansindex920, tick_ansdelta932, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m1011) {
                        u64 v_c9 = m1011[1];
                        if (!slog::exists_probe<3,1>(evalindex921, std::array<u64,3>{v_c9, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex922, closuredelta933, std::array<u64,3>{v_c187, 0, 0}, [&](const std::array<u64,3>& m1012) {
                          u64 v_c188 = m1012[1]; u64 v_c82 = m1012[2];
                          slog::join_probe_old<3,1>(lambdaindex923, lambdadelta934, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m1013) {
                            u64 v_c85 = m1013[1]; u64 v_c86 = m1013[2];
                            slog::join_probe_old<3,2>(evalindex924, evaldelta935, std::array<u64,3>{v_c86, v_c9, 0}, [&](const std::array<u64,3>& m1014) {
                              u64 v_c189 = m1014[2];
                              slog::join_probe_old<2,1>(eval_ansindex925, eval_ansdelta936, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1015) {
                                u64 v_c94 = m1015[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c182, v_c94}, std::array<u16,2>{0, 1});
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
        ReadTask937* _cont = new ReadTask937(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask937(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4) (let __tconst3zss458 const06abaa100ecef791ce028c56)) (scan temp06cC1010 __t0c92476 __t18GV497 __t54rR457 __t55Yy488 __t6p4Y485 __t7FRU467) (body (exists ref (1 0) 1 __tconst3zss458) (exists app (2 0 1) 1 __t54rR457) (join lambda (1 2 0) 2 __t55Yy488 __t6p4Y485 __t6n7e489) (join ref (1 0) 1 __tconst3zss458 __t0Jxw459) (join app (1 2 0) 2 __t0Jxw459 __t54rR457 __t8jPa460)) (head (emit-temp temp7FfK1011 __t0c92476 __t18GV497 __t6n7e489 __t7FRU467 __t8jPa460) (mkstruct let (2 1 3 0) __t84ma469 __t7FRU467 __tconst2M9b468 __t8jPa460)) schemecfa.slog:51 #f)
  class ReadTask1021 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1016;  slog::Index** appindex1017;  slog::Index** lambdaindex1018;  slog::Index** refindex1019;  slog::Index** appindex1020;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7FfK1011");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp06cC1010");
      std::vector<u16> ord1022({1, 0});
      slog::Relation* readrel1023 = db->getRelation("ref");
      refindex1016 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({2, 0, 1});
      slog::Relation* readrel1025 = db->getRelation("app");
      appindex1017 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 0});
      slog::Relation* readrel1027 = db->getRelation("lambda");
      lambdaindex1018 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 0});
      slog::Relation* readrel1029 = db->getRelation("ref");
      refindex1019 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 0});
      slog::Relation* readrel1031 = db->getRelation("app");
      appindex1020 = readrel1031->getIndex(ord1030, false);
  
    }
    ReadTask1021(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c42 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c44 = v_const0fc34686741291b4dd06511b;
      u64 v_c46 = v_const39c6f8839ca547fa7b7a32c4;
      u64 v_c48 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c190 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c191 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c192 = _t[4];
        u64 v_c193 = _t[5];
        if (!slog::exists_probe<2,1>(refindex1016, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1017, std::array<u64,3>{v_c191, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1018, std::array<u64,3>{v_c60, v_c192, 0}, [&](const std::array<u64,3>& m1032) {
          u64 v_c194 = m1032[2];
          slog::join_probe<2,1>(refindex1019, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m1033) {
            u64 v_c52 = m1033[1];
            slog::join_probe<3,2>(appindex1020, std::array<u64,3>{v_c52, v_c191, 0}, [&](const std::array<u64,3>& m1034) {
              u64 v_c195 = m1034[2];
              ++_fires;
              slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c190, v_c173, v_c194, v_c193, v_c195});
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c193, v_c46, v_c195}, std::array<u16,4>{2, 1, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp06cC1010", _fires);
  
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
  // (crule (pre) (scan temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1) (body (let __t0SDA445 (lpush __t9KsM444 __v0))) (head (emit-temp temp9b5k981 __t0SDA445 __t2W25447 __v1)) interp.slog:38 #f)
  class ReadTask1035 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9b5k981");
      outer_rel = db->getRelation("temp2fEO980");
  
    }
    ReadTask1035(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c20 = _t[3];
        u64 v_c196 = _prim_lpush(db, v_c7, v_c9);
        if (v_c196 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c196, v_c18, v_c20});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp2fEO980", _fires);
  
      if (!_done)
      {
        ReadTask1035* _cont = new ReadTask1035(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1035(db,b), false);
  // (crule (pre) (scan scheme_false fv) (body (join-old select_branch (0 1 2 3) 0 (0 1 2 3) __t97Cg3 tv e2 e3) (neq tv fv)) (head (emit select_branch_ans (0 1) __t97Cg3 e2)) interp.slog:85 #f)
  class ReadTask1038 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex1036;  slog::Index** select_branchdelta1037;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord1039({0, 1});
      slog::Relation* readrel1040 = db->getRelation("select_branch_ans");
      head_index[0] = readrel1040->getIndex(ord1039, false);
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord1041({0, 1, 2, 3});
      slog::Relation* readrel1042 = db->getRelation("select_branch");
      select_branchindex1036 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1, 2, 3});
      slog::Relation* readrel1044 = db->getRelation("select_branch");
      select_branchdelta1037 = readrel1044->getIndex(ord1043, true);
  
    }
    ReadTask1038(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c197 = _t[0];
        slog::join_all_old<4>(select_branchindex1036, select_branchdelta1037, [&](const std::array<u64,4>& m1045) {
          u64 v_c198 = m1045[0]; u64 v_c199 = m1045[1]; u64 v_c146 = m1045[2]; u64 v_c147 = m1045[3];
          if (v_c199 == v_c197) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c146}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:scheme_false", _fires);
  
      if (!_done)
      {
        ReadTask1038* _cont = new ReadTask1038(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1038(db,b), false);
  // (crule (pre) (scan eval __t6kpB195 __t6acM194 c) (body (join boolean (0 1) 1 __t6acM194 b)) (head (emit-temp temp0LsC994 __t6kpB195 b) (mkstruct boolval (1 0) __t7v8e193 b)) interp.slog:27 #f)
  class ReadTask1047 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** booleanindex1046;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LsC994");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1048({0, 1});
      slog::Relation* readrel1049 = db->getRelation("boolean");
      booleanindex1046 = readrel1049->getIndex(ord1048, false);
  
    }
    ReadTask1047(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c200 = _t[0];
        u64 v_c201 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<2,1>(booleanindex1046, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1050) {
          u64 v_c132 = m1050[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c200, v_c132});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:27", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1047* _cont = new ReadTask1047(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1047(db,b), false);
  // (crule (pre) (scan if __t1Sxu34 e1 e2 e3) (body (join-old eval (1 2 0) 1 (1 2 0) __t1Sxu34 c __t82ak35)) (head (emit $sup56712x86x0x0x0 (1 0 2 3 4) c __t82ak35 e1 e2 e3)) interp.slog:87 #f)
  class ReadTask1053 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1051;  slog::Index** evaldelta1052;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord1054({1, 0, 2, 3, 4});
      slog::Relation* readrel1055 = db->getRelation("$sup56712x86x0x0x0");
      head_index[0] = readrel1055->getIndex(ord1054, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord1056({1, 2, 0});
      slog::Relation* readrel1057 = db->getRelation("eval");
      evalindex1051 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 2, 0});
      slog::Relation* readrel1059 = db->getRelation("eval");
      evaldelta1052 = readrel1059->getIndex(ord1058, true);
  
    }
    ReadTask1053(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c202 = _t[0];
        u64 v_c145 = _t[1];
        u64 v_c146 = _t[2];
        u64 v_c147 = _t[3];
        slog::join_probe_old<3,1>(evalindex1051, evaldelta1052, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m1060) {
          u64 v_c10 = m1060[1]; u64 v_c203 = m1060[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c10, v_c203, v_c145, v_c146, v_c147}, std::array<u16,5>{1, 0, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask1053* _cont = new ReadTask1053(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1053(db,b), false);
  // (crule (pre) (scan closure __t3Pto26 __t0xip28 cb) (body (exists freevar (1 0) 1 __t0xip28) (exists binding (1 0 2) 1 cb) (join eval_ans (1 0) 1 __t3Pto26 __t5MCM24) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join eval (0 2 1) 1 __t5MCM24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join tick_ans (0 1) 1 __t0DSy30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1061;  slog::Index** bindingindex1062;  slog::Index** eval_ansindex1063;  slog::Index** freevarindex1064;  slog::Index** bindingindex1065;  slog::Index** evalindex1066;  slog::Index** appindex1067;  slog::Index** eval_argsindex1068;  slog::Index** tickindex1069;  slog::Index** evalindex1070;  slog::Index** tickindex1071;  slog::Index** appindex1072;  slog::Index** eval_argsindex1073;  slog::Index** eval_args_ansindex1074;  slog::Index** tickindex1075;  slog::Index** tick_ansindex1076;  slog::Index** eval_args_ansindex1077;  slog::Index** tick_ansindex1078;  slog::Index** lambdaindex1079;  slog::Index** appdelta1080;  slog::Index** eval_argsdelta1081;  slog::Index** tickdelta1082;  slog::Index** lambdadelta1083;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1085({0, 1, 2});
      slog::Relation* readrel1086 = db->getRelation("binding");
      head_index[0] = readrel1086->getIndex(ord1085, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1087({0, 1, 2});
      slog::Relation* readrel1088 = db->getRelation("binding_event");
      head_index[1] = readrel1088->getIndex(ord1087, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord1089({1, 0});
      slog::Relation* readrel1090 = db->getRelation("freevar");
      freevarindex1061 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 0, 2});
      slog::Relation* readrel1092 = db->getRelation("binding");
      bindingindex1062 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 0});
      slog::Relation* readrel1094 = db->getRelation("eval_ans");
      eval_ansindex1063 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 0});
      slog::Relation* readrel1096 = db->getRelation("freevar");
      freevarindex1064 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({0, 1, 2});
      slog::Relation* readrel1098 = db->getRelation("binding");
      bindingindex1065 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 2, 1});
      slog::Relation* readrel1100 = db->getRelation("eval");
      evalindex1066 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({1, 2, 0});
      slog::Relation* readrel1102 = db->getRelation("app");
      appindex1067 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({2, 0, 1});
      slog::Relation* readrel1104 = db->getRelation("eval_args");
      eval_argsindex1068 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({2, 0, 1});
      slog::Relation* readrel1106 = db->getRelation("tick");
      tickindex1069 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({2, 0, 1});
      slog::Relation* readrel1108 = db->getRelation("eval");
      evalindex1070 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 2, 0});
      slog::Relation* readrel1110 = db->getRelation("tick");
      tickindex1071 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({0, 1, 2});
      slog::Relation* readrel1112 = db->getRelation("app");
      appindex1072 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({0, 1, 2});
      slog::Relation* readrel1114 = db->getRelation("app");
      appdelta1080 = readrel1114->getIndex(ord1113, true);
      std::vector<u16> ord1115({1, 2, 0});
      slog::Relation* readrel1116 = db->getRelation("eval_args");
      eval_argsindex1073 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 2, 0});
      slog::Relation* readrel1118 = db->getRelation("eval_args");
      eval_argsdelta1081 = readrel1118->getIndex(ord1117, true);
      std::vector<u16> ord1119({0, 1});
      slog::Relation* readrel1120 = db->getRelation("eval_args_ans");
      eval_args_ansindex1074 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 2, 0});
      slog::Relation* readrel1122 = db->getRelation("tick");
      tickindex1075 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 2, 0});
      slog::Relation* readrel1124 = db->getRelation("tick");
      tickdelta1082 = readrel1124->getIndex(ord1123, true);
      std::vector<u16> ord1125({0, 1});
      slog::Relation* readrel1126 = db->getRelation("tick_ans");
      tick_ansindex1076 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({0, 1});
      slog::Relation* readrel1128 = db->getRelation("eval_args_ans");
      eval_args_ansindex1077 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({0, 1});
      slog::Relation* readrel1130 = db->getRelation("tick_ans");
      tick_ansindex1078 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 1, 2});
      slog::Relation* readrel1132 = db->getRelation("lambda");
      lambdaindex1079 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({0, 1, 2});
      slog::Relation* readrel1134 = db->getRelation("lambda");
      lambdadelta1083 = readrel1134->getIndex(ord1133, true);
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c78 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c82 = _t[2];
        if (!slog::exists_probe<2,1>(freevarindex1061, std::array<u64,2>{v_c81, 0})) return;
        if (!slog::exists_probe<3,1>(bindingindex1062, std::array<u64,3>{v_c82, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex1063, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m1135) {
          u64 v_c75 = m1135[1];
          slog::join_probe<2,1>(freevarindex1064, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1136) {
            u64 v_c83 = m1136[1];
            slog::join_probe<3,2>(bindingindex1065, std::array<u64,3>{v_c83, v_c82, 0}, [&](const std::array<u64,3>& m1137) {
              u64 v_c84 = m1137[2];
              slog::join_probe<3,1>(evalindex1066, std::array<u64,3>{v_c75, 0, 0}, [&](const std::array<u64,3>& m1138) {
                u64 v_c10 = m1138[1]; u64 v_c73 = m1138[2];
                if (!slog::exists_probe<3,1>(appindex1067, std::array<u64,3>{v_c73, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex1068, std::array<u64,3>{v_c10, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex1069, std::array<u64,3>{v_c10, 0, 0})) return;
                slog::join_probe<3,1>(evalindex1070, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m1139) {
                  u64 v_c74 = m1139[1]; u64 v_c72 = m1139[2];
                  if (!slog::exists_probe<3,2>(tickindex1071, std::array<u64,3>{v_c72, v_c10, 0})) return;
                  slog::join_probe_old<3,2>(appindex1072, appdelta1080, std::array<u64,3>{v_c72, v_c73, 0}, [&](const std::array<u64,3>& m1140) {
                    u64 v_c17 = m1140[2];
                    slog::join_probe_old<3,2>(eval_argsindex1073, eval_argsdelta1081, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m1141) {
                      u64 v_c76 = m1141[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex1074, std::array<u64,2>{v_c76, 0})) return;
                      slog::join_probe_old<3,2>(tickindex1075, tickdelta1082, std::array<u64,3>{v_c72, v_c10, 0}, [&](const std::array<u64,3>& m1142) {
                        u64 v_c77 = m1142[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex1076, std::array<u64,2>{v_c77, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex1077, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m1143) {
                          u64 v_c79 = m1143[1];
                          slog::join_probe<2,1>(tick_ansindex1078, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m1144) {
                            u64 v_c80 = m1144[1];
                            slog::join_probe_old<3,1>(lambdaindex1079, lambdadelta1083, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m1145) {
                              u64 v_c85 = m1145[1]; u64 v_c86 = m1145[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c83, v_c80, v_c84}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c83, v_c80, v_c10}, std::array<u16,3>{0, 1, 2});
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
        ReadTask1084* _cont = new ReadTask1084(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1084(db,b), false);
  // (crule (pre) (scan eval __4M4I787 __t66ko429 c) (body (join-old eval (2 0 1) 1 (2 0 1) c __t9SPH430 er) (exists eval_ans (0 1) 1 __t9SPH430) (join-old let (0 2 1 3) 2 (0 2 1 3) __t66ko429 er x eb) (join-old eval_ans (0 1) 1 (0 1) __t9SPH430 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask1153 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1146;  slog::Index** eval_ansindex1147;  slog::Index** letindex1148;  slog::Index** eval_ansindex1149;  slog::Index** evaldelta1150;  slog::Index** letdelta1151;  slog::Index** eval_ansdelta1152;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1154({0, 1, 2});
      slog::Relation* readrel1155 = db->getRelation("binding");
      head_index[0] = readrel1155->getIndex(ord1154, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1156({0, 1, 2});
      slog::Relation* readrel1157 = db->getRelation("binding_event");
      head_index[1] = readrel1157->getIndex(ord1156, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1158({2, 0, 1});
      slog::Relation* readrel1159 = db->getRelation("eval");
      evalindex1146 = readrel1159->getIndex(ord1158, false);
      std::vector<u16> ord1160({2, 0, 1});
      slog::Relation* readrel1161 = db->getRelation("eval");
      evaldelta1150 = readrel1161->getIndex(ord1160, true);
      std::vector<u16> ord1162({0, 1});
      slog::Relation* readrel1163 = db->getRelation("eval_ans");
      eval_ansindex1147 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({0, 2, 1, 3});
      slog::Relation* readrel1165 = db->getRelation("let");
      letindex1148 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({0, 2, 1, 3});
      slog::Relation* readrel1167 = db->getRelation("let");
      letdelta1151 = readrel1167->getIndex(ord1166, true);
      std::vector<u16> ord1168({0, 1});
      slog::Relation* readrel1169 = db->getRelation("eval_ans");
      eval_ansindex1149 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({0, 1});
      slog::Relation* readrel1171 = db->getRelation("eval_ans");
      eval_ansdelta1152 = readrel1171->getIndex(ord1170, true);
  
    }
    ReadTask1153(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c204 = _t[0];
        u64 v_c205 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe_old<3,1>(evalindex1146, evaldelta1150, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m1172) {
          u64 v_c206 = m1172[1]; u64 v_c151 = m1172[2];
          if (!slog::exists_probe<2,1>(eval_ansindex1147, std::array<u64,2>{v_c206, 0})) return;
          slog::join_probe_old<4,2>(letindex1148, letdelta1151, std::array<u64,4>{v_c205, v_c151, 0, 0}, [&](const std::array<u64,4>& m1173) {
            u64 v_c1 = m1173[2]; u64 v_c86 = m1173[3];
            slog::join_probe_old<2,1>(eval_ansindex1149, eval_ansdelta1152, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1174) {
              u64 v_c155 = m1174[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c10, v_c155}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c10, v_c10}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1153* _cont = new ReadTask1153(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1153(db,b), false);
  // (crule (pre (let __trid28Qd741 const342a69eb5a93251c8b7e179a) (let __trel7X6u742 constf6cdc3db4b71e0cdeda6912e) (let __tcol4g8x743 const6b86b273ff34fce19d6b804e) (let __trel7qwO744 constf6cdc3db4b71e0cdeda6912e) (let __tcol8jiL745 constd4735e3a265e16eee03f5971)) (scan eval_ans __t8BCY386 __v0) (body (join-old eval (0 2 1) 1 (0 2 1) __t8BCY386 c e1) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7X6u742 __tcol4g8x743 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7qwO744 __tcol8jiL745 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __7pWz740 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask1187 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1175;  slog::Index** $sup56712x86x0x0x0index1176;  slog::Index** evaldelta1177;
    u32 sid1178;  u32 sid1179;  u32 sid1180;  u32 sid1181;  u32 sid1182;  u32 sid1183;  u32 sid1184;  u32 sid1185;  u32 sid1186;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1188({0, 2, 1});
      slog::Relation* readrel1189 = db->getRelation("eval");
      evalindex1175 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({0, 2, 1});
      slog::Relation* readrel1191 = db->getRelation("eval");
      evaldelta1177 = readrel1191->getIndex(ord1190, true);
      std::vector<u16> ord1192({1, 2, 0, 3, 4});
      slog::Relation* readrel1193 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1176 = readrel1193->getIndex(ord1192, false);
      sid1178 = db->getRelation("app")->getStructId();
      sid1179 = db->getRelation("boolean")->getStructId();
      sid1180 = db->getRelation("if")->getStructId();
      sid1181 = db->getRelation("lambda")->getStructId();
      sid1182 = db->getRelation("let")->getStructId();
      sid1183 = db->getRelation("letrec")->getStructId();
      sid1184 = db->getRelation("num")->getStructId();
      sid1185 = db->getRelation("ref")->getStructId();
      sid1186 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c207 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c208 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c209 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c210 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c211 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c212 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe_old<3,1>(evalindex1175, evaldelta1177, std::array<u64,3>{v_c212, 0, 0}, [&](const std::array<u64,3>& m1194) {
          u64 v_c10 = m1194[1]; u64 v_c145 = m1194[2];
          slog::join_probe<5,2>($sup56712x86x0x0x0index1176, std::array<u64,5>{v_c10, v_c145, 0, 0, 0}, [&](const std::array<u64,5>& m1195) {
            u64 v_c114 = m1195[2]; u64 v_c146 = m1195[3]; u64 v_c147 = m1195[4];
            ++_fires;
            if (!((is_struct(v_c146) && (decode_struct_id(v_c146) == sid1178 || decode_struct_id(v_c146) == sid1179 || decode_struct_id(v_c146) == sid1180 || decode_struct_id(v_c146) == sid1181 || decode_struct_id(v_c146) == sid1182 || decode_struct_id(v_c146) == sid1183 || decode_struct_id(v_c146) == sid1184 || decode_struct_id(v_c146) == sid1185 || decode_struct_id(v_c146) == sid1186))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c207, v_c208, v_c209, v_c146}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c147) && (decode_struct_id(v_c147) == sid1178 || decode_struct_id(v_c147) == sid1179 || decode_struct_id(v_c147) == sid1180 || decode_struct_id(v_c147) == sid1181 || decode_struct_id(v_c147) == sid1182 || decode_struct_id(v_c147) == sid1183 || decode_struct_id(v_c147) == sid1184 || decode_struct_id(v_c147) == sid1185 || decode_struct_id(v_c147) == sid1186))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c207, v_c210, v_c211, v_c147}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c9, v_c146, v_c147}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1187* _cont = new ReadTask1187(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1187(db,b), false);
  // (crule (pre (let __tconst0ib5704 constcd2a69ce5ca278db1d6da969)) (scan num __t93te9 n) (body (exists eval (1 2 0) 1 __t93te9) (join _enum (1 0) 1 __tconst0ib5704 __t5HyQ8) (join-old eval (1 2 0) 1 (1 2 0) __t93te9 c __t3VNp10)) (head (emit eval_ans (0 1) __t3VNp10 __t5HyQ8)) interp.slog:26 #f)
  class ReadTask1200 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1196;  slog::Index** _enumindex1197;  slog::Index** evalindex1198;  slog::Index** evaldelta1199;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1201({0, 1});
      slog::Relation* readrel1202 = db->getRelation("eval_ans");
      head_index[0] = readrel1202->getIndex(ord1201, false);
      outer_rel = db->getRelation("num");
      std::vector<u16> ord1203({1, 2, 0});
      slog::Relation* readrel1204 = db->getRelation("eval");
      evalindex1196 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 0});
      slog::Relation* readrel1206 = db->getRelation("_enum");
      _enumindex1197 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 2, 0});
      slog::Relation* readrel1208 = db->getRelation("eval");
      evalindex1198 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 2, 0});
      slog::Relation* readrel1210 = db->getRelation("eval");
      evaldelta1199 = readrel1210->getIndex(ord1209, true);
  
    }
    ReadTask1200(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c214 = _t[0];
        u64 v_c215 = _t[1];
        if (!slog::exists_probe<3,1>(evalindex1196, std::array<u64,3>{v_c214, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex1197, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m1211) {
          u64 v_c216 = m1211[1];
          slog::join_probe_old<3,1>(evalindex1198, evaldelta1199, std::array<u64,3>{v_c214, 0, 0}, [&](const std::array<u64,3>& m1212) {
            u64 v_c10 = m1212[1]; u64 v_c217 = m1212[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c217, v_c216}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:26", "delta:num", _fires);
  
      if (!_done)
      {
        ReadTask1200* _cont = new ReadTask1200(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1200(db,b), false);
  // (crule (pre) (scan if __t2nUQ323 e1 e2 e3) (body (join freevar (1 0) 1 e3 x)) (head (emit freevar (0 1) x __t2nUQ323)) freevars.slog:17 #f)
  class ReadTask1214 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1213;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1215({0, 1});
      slog::Relation* readrel1216 = db->getRelation("freevar");
      head_index[0] = readrel1216->getIndex(ord1215, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord1217({1, 0});
      slog::Relation* readrel1218 = db->getRelation("freevar");
      freevarindex1213 = readrel1218->getIndex(ord1217, false);
  
    }
    ReadTask1214(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c145 = _t[1];
        u64 v_c146 = _t[2];
        u64 v_c147 = _t[3];
        slog::join_probe<2,1>(freevarindex1213, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1219) {
          u64 v_c1 = m1219[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c218}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
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
  // (crule (pre (let __tconst4VQK721 constb9e118781cea1f9fa01462e0) (let __tconst22Ls722 const0122baa3ac55f1b433944eb1) (let __tconst5lFL150 const60e3114d9b4b6577eea8cbc0) (let _00024sqc6U6L608 const6b86b273ff34fce19d6b804e) (let _00024sqc4sFX609 const5feceb66ffc86f38d952786c) (let _00024sqo2S6J610 const5feceb66ffc86f38d952786c) (let _00024sqo0Kwi611 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2S6J610 __t9y9U153 _00024seq1) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0Kwi611 __t9y9U153 _00024seq1) (exists _enum (1 0) 1 __tconst4VQK721) (exists _enum (1 0) 1 __tconst22Ls722) (join delta (1 2 0) 2 __tconst5lFL150 _00024seq1 __t1y17151) (join _enum (1 0) 1 __tconst4VQK721 __t0cMr152) (join boolval (0 1) 2 __t9y9U153 __t0cMr152) (join _enum (1 0) 1 __tconst22Ls722 __t5r57148) (letp _00024sql06hQ606 (aslst _00024seq1)) (let chk2SQY1124 (llen _00024sql06hQ606)) (eq _00024sqc6U6L608 chk2SQY1124) (letp chk2SLd1125 (lref _00024sql06hQ606 _00024sqc4sFX609)) (eq __t9y9U153 chk2SLd1125)) (head (emit-temp temp41lW1120 __t1y17151) (mkstruct boolval (1 0) __t2W4B149 __t5r57148)) interp.slog:113 #f)
  class ReadTask1228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex1220;  slog::Index** _enumindex1221;  slog::Index** _enumindex1222;  slog::Index** deltaindex1223;  slog::Index** _enumindex1224;  slog::Index** boolvalindex1225;  slog::Index** _enumindex1226;  slog::Index** $seq_atrdelta1227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp41lW1120");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1229({1, 0, 2});
      slog::Relation* readrel1230 = db->getRelation("$seq_at");
      driver_index = readrel1230->getIndex(ord1229, true);
      std::vector<u16> ord1231({1, 0, 2});
      slog::Relation* readrel1232 = db->getRelation("$seq_atr");
      $seq_atrindex1220 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({1, 0, 2});
      slog::Relation* readrel1234 = db->getRelation("$seq_atr");
      $seq_atrdelta1227 = readrel1234->getIndex(ord1233, true);
      std::vector<u16> ord1235({1, 0});
      slog::Relation* readrel1236 = db->getRelation("_enum");
      _enumindex1221 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({1, 0});
      slog::Relation* readrel1238 = db->getRelation("_enum");
      _enumindex1222 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 2, 0});
      slog::Relation* readrel1240 = db->getRelation("delta");
      deltaindex1223 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({1, 0});
      slog::Relation* readrel1242 = db->getRelation("_enum");
      _enumindex1224 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({0, 1});
      slog::Relation* readrel1244 = db->getRelation("boolval");
      boolvalindex1225 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({1, 0});
      slog::Relation* readrel1246 = db->getRelation("_enum");
      _enumindex1226 = readrel1246->getIndex(ord1245, false);
  
    }
    ReadTask1228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c219 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c220 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c221 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c222 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c223 = v_const5feceb66ffc86f38d952786c;
      u64 v_c224 = v_const5feceb66ffc86f38d952786c;
      u64 v_c225 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c224, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1247) {
        u64 v_c226 = m1247[1];
        u64 v_c227 = m1247[2];
        if (buckethash(v_c226) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex1220, $seq_atrdelta1227, std::array<u64,3>{v_c225, v_c226, v_c227}, [&](const std::array<u64,3>& m1248) {
          if (!slog::exists_probe<2,1>(_enumindex1221, std::array<u64,2>{v_c219, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex1222, std::array<u64,2>{v_c220, 0})) return;
          slog::join_probe<3,2>(deltaindex1223, std::array<u64,3>{v_c221, v_c227, 0}, [&](const std::array<u64,3>& m1249) {
            u64 v_c228 = m1249[2];
            slog::join_probe<2,1>(_enumindex1224, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m1250) {
              u64 v_c229 = m1250[1];
              slog::join_probe<2,2>(boolvalindex1225, std::array<u64,2>{v_c226, v_c229}, [&](const std::array<u64,2>& m1251) {
                slog::join_probe<2,1>(_enumindex1226, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1252) {
                  u64 v_c230 = m1252[1];
                  bool ok1253 = true;
                  u64 v_c231 = _prim_aslst(db, v_c227, &ok1253);
                  if (!ok1253) return;
                  u64 v_c232 = _prim_llen(db, v_c231);
                  if (v_c232 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c222 != v_c232) return;
                  bool ok1254 = true;
                  u64 v_c233 = _prim_lref(db, v_c231, v_c223, &ok1254);
                  if (!ok1254) return;
                  if (v_c226 != v_c233) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c228});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c230}, std::array<u16,2>{1, 0});
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
        ReadTask1228* _cont = new ReadTask1228(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1228(db,b), false);
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0) (let __tconst3fuu217 const06abaa100ecef791ce028c56) (let _00024sqc1fPN569 constd4735e3a265e16eee03f5971) (let _00024sqc78q5570 const5feceb66ffc86f38d952786c) (let _00024sqc5TDx571 const6b86b273ff34fce19d6b804e) (let _00024sqo1Czp572 const5feceb66ffc86f38d952786c) (let _00024sqo2Uyj573 const6b86b273ff34fce19d6b804e) (let _00024sqo2qsW574 const6b86b273ff34fce19d6b804e) (let _00024sqo2mjM575 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3fuu217 _00024seq0 __t12h7218) (body (letp _00024sql8W3E567 (aslst _00024seq0)) (letp v1 (lref _00024sql8W3E567 _00024sqc78q5570)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1Czp572 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2qsW574 v1 _00024seq0) (letp v2 (lref _00024sql8W3E567 _00024sqc5TDx571)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2Uyj573 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2mjM575 v2 _00024seq0) (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (let chk5fOm1092 (llen _00024sql8W3E567)) (eq _00024sqc1fPN569 chk5fOm1092)) (head (emit-temp temp4VE71091 __t12h7218) (mkstruct boolval (1 0) __t5boA216 __t6tMS215)) interp.slog:120 #f)
  class ReadTask1264 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1255;  slog::Index** $seq_atrindex1256;  slog::Index** $seq_atindex1257;  slog::Index** $seq_atrindex1258;  slog::Index** _enumindex1259;  slog::Index** $seq_atdelta1260;  slog::Index** $seq_atrdelta1261;  slog::Index** $seq_atdelta1262;  slog::Index** $seq_atrdelta1263;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4VE71091");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1265({1, 2, 0});
      slog::Relation* readrel1266 = db->getRelation("delta");
      driver_index = readrel1266->getIndex(ord1265, true);
      std::vector<u16> ord1267({1, 0, 2});
      slog::Relation* readrel1268 = db->getRelation("$seq_at");
      $seq_atindex1255 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({1, 0, 2});
      slog::Relation* readrel1270 = db->getRelation("$seq_at");
      $seq_atdelta1260 = readrel1270->getIndex(ord1269, true);
      std::vector<u16> ord1271({1, 0, 2});
      slog::Relation* readrel1272 = db->getRelation("$seq_atr");
      $seq_atrindex1256 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({1, 0, 2});
      slog::Relation* readrel1274 = db->getRelation("$seq_atr");
      $seq_atrdelta1261 = readrel1274->getIndex(ord1273, true);
      std::vector<u16> ord1275({1, 0, 2});
      slog::Relation* readrel1276 = db->getRelation("$seq_at");
      $seq_atindex1257 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 0, 2});
      slog::Relation* readrel1278 = db->getRelation("$seq_at");
      $seq_atdelta1262 = readrel1278->getIndex(ord1277, true);
      std::vector<u16> ord1279({1, 0, 2});
      slog::Relation* readrel1280 = db->getRelation("$seq_atr");
      $seq_atrindex1258 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 0, 2});
      slog::Relation* readrel1282 = db->getRelation("$seq_atr");
      $seq_atrdelta1263 = readrel1282->getIndex(ord1281, true);
      std::vector<u16> ord1283({1, 0});
      slog::Relation* readrel1284 = db->getRelation("_enum");
      _enumindex1259 = readrel1284->getIndex(ord1283, false);
  
    }
    ReadTask1264(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c234 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c235 = v_const06abaa100ecef791ce028c56;
      u64 v_c236 = v_constd4735e3a265e16eee03f5971;
      u64 v_c237 = v_const5feceb66ffc86f38d952786c;
      u64 v_c238 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c239 = v_const5feceb66ffc86f38d952786c;
      u64 v_c240 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c241 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c242 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c235, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1285) {
        u64 v_c12 = m1285[1];
        u64 v_c243 = m1285[2];
        if (buckethash(v_c12) != bucket) return;
        bool ok1286 = true;
        u64 v_c244 = _prim_aslst(db, v_c12, &ok1286);
        if (!ok1286) return;
        bool ok1287 = true;
        u64 v_c245 = _prim_lref(db, v_c244, v_c237, &ok1287);
        if (!ok1287) return;
        slog::join_probe_old<3,3>($seq_atindex1255, $seq_atdelta1260, std::array<u64,3>{v_c239, v_c245, v_c12}, [&](const std::array<u64,3>& m1288) {
          slog::join_probe_old<3,3>($seq_atrindex1256, $seq_atrdelta1261, std::array<u64,3>{v_c241, v_c245, v_c12}, [&](const std::array<u64,3>& m1289) {
            bool ok1290 = true;
            u64 v_c246 = _prim_lref(db, v_c244, v_c238, &ok1290);
            if (!ok1290) return;
            if (v_c245 == v_c246) return;
            slog::join_probe_old<3,3>($seq_atindex1257, $seq_atdelta1262, std::array<u64,3>{v_c240, v_c246, v_c12}, [&](const std::array<u64,3>& m1291) {
              slog::join_probe_old<3,3>($seq_atrindex1258, $seq_atrdelta1263, std::array<u64,3>{v_c242, v_c246, v_c12}, [&](const std::array<u64,3>& m1292) {
                slog::join_probe<2,1>(_enumindex1259, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1293) {
                  u64 v_c247 = m1293[1];
                  u64 v_c248 = _prim_llen(db, v_c244);
                  if (v_c248 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c236 != v_c248) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c243});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c247}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1264* _cont = new ReadTask1264(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1264(db,b), false);
  // (crule (pre) (scan freevar x er) (body (join-old let (2 1 3 0) 1 (2 1 3 0) er y eb __t6gxv132)) (head (emit freevar (0 1) x __t6gxv132)) freevars.slog:21 #f)
  class ReadTask1296 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1294;  slog::Index** letdelta1295;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1297({0, 1});
      slog::Relation* readrel1298 = db->getRelation("freevar");
      head_index[0] = readrel1298->getIndex(ord1297, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1299({2, 1, 3, 0});
      slog::Relation* readrel1300 = db->getRelation("let");
      letindex1294 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({2, 1, 3, 0});
      slog::Relation* readrel1302 = db->getRelation("let");
      letdelta1295 = readrel1302->getIndex(ord1301, true);
  
    }
    ReadTask1296(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c151 = _t[1];
        slog::join_probe_old<4,1>(letindex1294, letdelta1295, std::array<u64,4>{v_c151, 0, 0, 0}, [&](const std::array<u64,4>& m1303) {
          u64 v_c83 = m1303[1]; u64 v_c86 = m1303[2]; u64 v_c156 = m1303[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c156}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:21", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1296* _cont = new ReadTask1296(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1296(db,b), false);
  // (crule (pre) (scan freevar x eb) (body (join-old let (3 0 1 2) 1 (3 0 1 2) eb __t0UAj147 y er) (neq x y)) (head (emit freevar (0 1) x __t0UAj147)) freevars.slog:22 #f)
  class ReadTask1306 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1304;  slog::Index** letdelta1305;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1307({0, 1});
      slog::Relation* readrel1308 = db->getRelation("freevar");
      head_index[0] = readrel1308->getIndex(ord1307, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1309({3, 0, 1, 2});
      slog::Relation* readrel1310 = db->getRelation("let");
      letindex1304 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({3, 0, 1, 2});
      slog::Relation* readrel1312 = db->getRelation("let");
      letdelta1305 = readrel1312->getIndex(ord1311, true);
  
    }
    ReadTask1306(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c86 = _t[1];
        slog::join_probe_old<4,1>(letindex1304, letdelta1305, std::array<u64,4>{v_c86, 0, 0, 0}, [&](const std::array<u64,4>& m1313) {
          u64 v_c249 = m1313[1]; u64 v_c83 = m1313[2]; u64 v_c151 = m1313[3];
          if (v_c1 == v_c83) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c249}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:22", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1306* _cont = new ReadTask1306(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1306(db,b), false);
  // (crule (pre) (scan eval_args_ans __t60iG506 vs) (body (exists delta (2 0 1) 1 vs) (join-old eval_args (0 2 1) 1 (0 2 1) __t60iG506 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (join-old $sup56712x74x0x0x0 (1 3 0 2) 2 (1 3 0 2) c es __t8a3x503 ef) (exists eval (0 2 1) 2 __t8a3x503 c) (exists eval (1 2 0) 2 ef c) (join-old app (1 2 0) 2 (1 2 0) ef es __t8eby502) (join-old eval (0 2 1) 3 (0 2 1) __t8a3x503 c __t8eby502) (join-old eval (1 2 0) 2 (1 2 0) ef c __t3A6m504) (join eval_ans (0 1) 1 __t3A6m504 __t4zl0505) (join-old prim (0 1) 1 (0 1) __t4zl0505 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t8RjX507) (join-old delta_ans (0 1) 1 (0 1) __t8RjX507 v)) (head (emit eval_ans (0 1) __t8a3x503 v)) interp.slog:75 #f)
  class ReadTask1336 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex1314;  slog::Index** eval_argsindex1315;  slog::Index** appindex1316;  slog::Index** evalindex1317;  slog::Index** $sup56712x74x0x0x0index1318;  slog::Index** evalindex1319;  slog::Index** evalindex1320;  slog::Index** appindex1321;  slog::Index** evalindex1322;  slog::Index** evalindex1323;  slog::Index** eval_ansindex1324;  slog::Index** primindex1325;  slog::Index** deltaindex1326;  slog::Index** delta_ansindex1327;  slog::Index** eval_argsdelta1328;  slog::Index** $sup56712x74x0x0x0delta1329;  slog::Index** appdelta1330;  slog::Index** evaldelta1331;  slog::Index** evaldelta1332;  slog::Index** primdelta1333;  slog::Index** deltadelta1334;  slog::Index** delta_ansdelta1335;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1337({0, 1});
      slog::Relation* readrel1338 = db->getRelation("eval_ans");
      head_index[0] = readrel1338->getIndex(ord1337, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord1339({2, 0, 1});
      slog::Relation* readrel1340 = db->getRelation("delta");
      deltaindex1314 = readrel1340->getIndex(ord1339, false);
      std::vector<u16> ord1341({0, 2, 1});
      slog::Relation* readrel1342 = db->getRelation("eval_args");
      eval_argsindex1315 = readrel1342->getIndex(ord1341, false);
      std::vector<u16> ord1343({0, 2, 1});
      slog::Relation* readrel1344 = db->getRelation("eval_args");
      eval_argsdelta1328 = readrel1344->getIndex(ord1343, true);
      std::vector<u16> ord1345({2, 0, 1});
      slog::Relation* readrel1346 = db->getRelation("app");
      appindex1316 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({2, 0, 1});
      slog::Relation* readrel1348 = db->getRelation("eval");
      evalindex1317 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 3, 0, 2});
      slog::Relation* readrel1350 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index1318 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 3, 0, 2});
      slog::Relation* readrel1352 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0delta1329 = readrel1352->getIndex(ord1351, true);
      std::vector<u16> ord1353({0, 2, 1});
      slog::Relation* readrel1354 = db->getRelation("eval");
      evalindex1319 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("eval");
      evalindex1320 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 2, 0});
      slog::Relation* readrel1358 = db->getRelation("app");
      appindex1321 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({1, 2, 0});
      slog::Relation* readrel1360 = db->getRelation("app");
      appdelta1330 = readrel1360->getIndex(ord1359, true);
      std::vector<u16> ord1361({0, 2, 1});
      slog::Relation* readrel1362 = db->getRelation("eval");
      evalindex1322 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({0, 2, 1});
      slog::Relation* readrel1364 = db->getRelation("eval");
      evaldelta1331 = readrel1364->getIndex(ord1363, true);
      std::vector<u16> ord1365({1, 2, 0});
      slog::Relation* readrel1366 = db->getRelation("eval");
      evalindex1323 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({1, 2, 0});
      slog::Relation* readrel1368 = db->getRelation("eval");
      evaldelta1332 = readrel1368->getIndex(ord1367, true);
      std::vector<u16> ord1369({0, 1});
      slog::Relation* readrel1370 = db->getRelation("eval_ans");
      eval_ansindex1324 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({0, 1});
      slog::Relation* readrel1372 = db->getRelation("prim");
      primindex1325 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({0, 1});
      slog::Relation* readrel1374 = db->getRelation("prim");
      primdelta1333 = readrel1374->getIndex(ord1373, true);
      std::vector<u16> ord1375({1, 2, 0});
      slog::Relation* readrel1376 = db->getRelation("delta");
      deltaindex1326 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 0});
      slog::Relation* readrel1378 = db->getRelation("delta");
      deltadelta1334 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({0, 1});
      slog::Relation* readrel1380 = db->getRelation("delta_ans");
      delta_ansindex1327 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({0, 1});
      slog::Relation* readrel1382 = db->getRelation("delta_ans");
      delta_ansdelta1335 = readrel1382->getIndex(ord1381, true);
  
    }
    ReadTask1336(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c90 = _t[0];
        u64 v_c79 = _t[1];
        if (!slog::exists_probe<3,1>(deltaindex1314, std::array<u64,3>{v_c79, 0, 0})) return;
        slog::join_probe_old<3,1>(eval_argsindex1315, eval_argsdelta1328, std::array<u64,3>{v_c90, 0, 0}, [&](const std::array<u64,3>& m1383) {
          u64 v_c10 = m1383[1]; u64 v_c17 = m1383[2];
          if (!slog::exists_probe<3,1>(appindex1316, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1317, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe_old<4,2>($sup56712x74x0x0x0index1318, $sup56712x74x0x0x0delta1329, std::array<u64,4>{v_c10, v_c17, 0, 0}, [&](const std::array<u64,4>& m1384) {
            u64 v_c88 = m1384[2]; u64 v_c73 = m1384[3];
            if (!slog::exists_probe<3,2>(evalindex1319, std::array<u64,3>{v_c88, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex1320, std::array<u64,3>{v_c73, v_c10, 0})) return;
            slog::join_probe_old<3,2>(appindex1321, appdelta1330, std::array<u64,3>{v_c73, v_c17, 0}, [&](const std::array<u64,3>& m1385) {
              u64 v_c89 = m1385[2];
              slog::join_probe_old<3,3>(evalindex1322, evaldelta1331, std::array<u64,3>{v_c88, v_c10, v_c89}, [&](const std::array<u64,3>& m1386) {
                slog::join_probe_old<3,2>(evalindex1323, evaldelta1332, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m1387) {
                  u64 v_c87 = m1387[2];
                  slog::join_probe<2,1>(eval_ansindex1324, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m1388) {
                    u64 v_c91 = m1388[1];
                    slog::join_probe_old<2,1>(primindex1325, primdelta1333, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m1389) {
                      u64 v_c92 = m1389[1];
                      slog::join_probe_old<3,2>(deltaindex1326, deltadelta1334, std::array<u64,3>{v_c92, v_c79, 0}, [&](const std::array<u64,3>& m1390) {
                        u64 v_c93 = m1390[2];
                        slog::join_probe_old<2,1>(delta_ansindex1327, delta_ansdelta1335, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1391) {
                          u64 v_c94 = m1391[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c88, v_c94}, std::array<u16,2>{0, 1});
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
        ReadTask1336* _cont = new ReadTask1336(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1336(db,b), false);
  // (crule (pre) (scan type_mismatch __erre6jvg940 __errf2A8t941 __errf9dzO942 __errf8YGD943 __errf9T1P944) (body) (head (emit error (0) __erre6jvg940)) <internal>:1 #f)
  class ReadTask1392 : public slog::Task
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
      std::vector<u16> ord1393({0});
      slog::Relation* readrel1394 = db->getRelation("error");
      head_index[0] = readrel1394->getIndex(ord1393, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask1392(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c250 = _t[0];
        u64 v_c251 = _t[1];
        u64 v_c252 = _t[2];
        u64 v_c253 = _t[3];
        u64 v_c254 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c250}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask1392* _cont = new ReadTask1392(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1392(db,b), false);
  // (crule (pre (let _00024sqc5Umw578 const6b86b273ff34fce19d6b804e) (let _00024sqc3t7M579 const5feceb66ffc86f38d952786c) (let _00024sqc8s9N580 const6b86b273ff34fce19d6b804e) (let _00024sqc7UCT581 const5feceb66ffc86f38d952786c) (let _00024sqo6m8k586 const5feceb66ffc86f38d952786c) (let __t4EG4161 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo6m8k586 e _00024seq0) (body (join argument_list (0) 1 _00024seq0) (join freevar (1 0) 1 e x) (letp _00024sql6PLL576 (aslst _00024seq0)) (let _00024sqn6WLF577 (llen _00024sql6PLL576)) (cmp ge _00024sqn6WLF577 _00024sqc5Umw578) (letp chk89UM1107 (lref _00024sql6PLL576 _00024sqc3t7M579)) (eq e chk89UM1107) (let _00024sqp95yh582 (_0002d _00024sqn6WLF577 _00024sqc7UCT581)) (let es (lslice _00024sql6PLL576 _00024sqc8s9N580 _00024sqp95yh582))) (head (emit-temp temp4nra1103 __t4EG4161 e es x)) freevars.slog:35 #f)
  class ReadTask1397 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** argument_listindex1395;  slog::Index** freevarindex1396;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4nra1103");
      std::vector<u16> ord1398({1, 0, 2});
      slog::Relation* readrel1399 = db->getRelation("$seq_at");
      driver_index = readrel1399->getIndex(ord1398, true);
      std::vector<u16> ord1400({0});
      slog::Relation* readrel1401 = db->getRelation("argument_list");
      argument_listindex1395 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({1, 0});
      slog::Relation* readrel1403 = db->getRelation("freevar");
      freevarindex1396 = readrel1403->getIndex(ord1402, false);
  
    }
    ReadTask1397(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c255 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c256 = v_const5feceb66ffc86f38d952786c;
      u64 v_c257 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c258 = v_const5feceb66ffc86f38d952786c;
      u64 v_c259 = v_const5feceb66ffc86f38d952786c;
      u64 v_c171 = _prim_lempty(db);
      if (v_c171 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c259, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1404) {
        u64 v_c11 = m1404[1];
        u64 v_c12 = m1404[2];
        if (buckethash(v_c11) != bucket) return;
        slog::join_probe<1,1>(argument_listindex1395, std::array<u64,1>{v_c12}, [&](const std::array<u64,1>& m1405) {
          slog::join_probe<2,1>(freevarindex1396, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1406) {
            u64 v_c1 = m1406[1];
            bool ok1407 = true;
            u64 v_c260 = _prim_aslst(db, v_c12, &ok1407);
            if (!ok1407) return;
            u64 v_c261 = _prim_llen(db, v_c260);
            if (v_c261 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c262 = _prim_ge(db, v_c261, v_c255);
            if (v_c262 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c262) return;
            bool ok1409 = true;
            u64 v_c263 = _prim_lref(db, v_c260, v_c256, &ok1409);
            if (!ok1409) return;
            if (v_c11 != v_c263) return;
            u64 v_c264 = _prim__0002d(db, v_c261, v_c258);
            if (v_c264 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c17 = _prim_lslice(db, v_c260, v_c257, v_c264);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c171, v_c11, v_c17, v_c1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1397* _cont = new ReadTask1397(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1397(db,b), false);
  // (crule (pre) (scan temp69gU1104 __t0whu162 es x) (body (let __t4ZSk163 (lcat __t0whu162 es))) (head (emit-temp temp2mUr1105 __t4ZSk163 x)) freevars.slog:35 #f)
  class ReadTask1410 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2mUr1105");
      outer_rel = db->getRelation("temp69gU1104");
  
    }
    ReadTask1410(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c172 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c0 = _prim_lcat(db, v_c172, v_c17);
        if (v_c0 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp69gU1104", _fires);
  
      if (!_done)
      {
        ReadTask1410* _cont = new ReadTask1410(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1410(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4)) (scan temp7FfK1011 __t0c92476 __t18GV497 __t6n7e489 __t7FRU467 __t8jPa460) (body (join let (2 1 3 0) 3 __t7FRU467 __tconst2M9b468 __t8jPa460 __t84ma469)) (head (emit-temp temp4t2N1012 __t0c92476 __t18GV497 __t6n7e489 __t84ma469) (mkstruct let (2 1 3 0) __t8zw1478 __t0c92476 __tconst49ZO477 __t84ma469)) schemecfa.slog:51 #f)
  class ReadTask1412 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1411;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4t2N1012");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp7FfK1011");
      std::vector<u16> ord1413({2, 1, 3, 0});
      slog::Relation* readrel1414 = db->getRelation("let");
      letindex1411 = readrel1414->getIndex(ord1413, false);
  
    }
    ReadTask1412(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c42 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c44 = v_const0fc34686741291b4dd06511b;
      u64 v_c46 = v_const39c6f8839ca547fa7b7a32c4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c190 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c194 = _t[2];
        u64 v_c193 = _t[3];
        u64 v_c195 = _t[4];
        slog::join_probe<4,3>(letindex1411, std::array<u64,4>{v_c193, v_c46, v_c195, 0}, [&](const std::array<u64,4>& m1415) {
          u64 v_c265 = m1415[3];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c190, v_c173, v_c194, v_c265});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c190, v_c44, v_c265}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp7FfK1011", _fires);
  
      if (!_done)
      {
        ReadTask1412* _cont = new ReadTask1412(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1412(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1)) (scan temp56SH1058 __t4OrE188) (body (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join boolval (1 0) 1 __t6FbR185 __t6RYP186)) (head (emit delta_ans (0 1) __t4OrE188 __t6RYP186)) interp.slog:119 #f)
  class ReadTask1418 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1416;  slog::Index** boolvalindex1417;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1419({0, 1});
      slog::Relation* readrel1420 = db->getRelation("delta_ans");
      head_index[0] = readrel1420->getIndex(ord1419, false);
      outer_rel = db->getRelation("temp56SH1058");
      std::vector<u16> ord1421({1, 0});
      slog::Relation* readrel1422 = db->getRelation("_enum");
      _enumindex1416 = readrel1422->getIndex(ord1421, false);
      std::vector<u16> ord1423({1, 0});
      slog::Relation* readrel1424 = db->getRelation("boolval");
      boolvalindex1417 = readrel1424->getIndex(ord1423, false);
  
    }
    ReadTask1418(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c266 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c267 = _t[0];
        slog::join_probe<2,1>(_enumindex1416, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1425) {
          u64 v_c268 = m1425[1];
          slog::join_probe<2,1>(boolvalindex1417, std::array<u64,2>{v_c268, 0}, [&](const std::array<u64,2>& m1426) {
            u64 v_c269 = m1426[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c267, v_c269}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:temp56SH1058", _fires);
  
      if (!_done)
      {
        ReadTask1418* _cont = new ReadTask1418(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1418(db,b), false);
  // (crule (pre (let __trid7JOP768 const2a09f8e08b8d8243373579d9) (let __trel5M7g769 const0bbd2fbd1dc4200473343503) (let __tcol25Yj770 const5feceb66ffc86f38d952786c)) (scan lambda __t3YjV179 xs eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t3YjV179 c __t4BlY180)) (head (tycheck __t3YjV179 (accept (struct lambda)) __trid7JOP768 __trel5M7g769 __tcol25Yj770 (1 2 3 4 0)) (emit-temp temp2RWj1119 __t3YjV179 __t4BlY180 c) (mkstruct closure (1 2 0) __t7vnx178 __t3YjV179 c)) interp.slog:29 #f)
  class ReadTask1430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1427;  slog::Index** evaldelta1428;
    u32 sid1429;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp2RWj1119");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1431({1, 2, 0});
      slog::Relation* readrel1432 = db->getRelation("eval");
      evalindex1427 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({1, 2, 0});
      slog::Relation* readrel1434 = db->getRelation("eval");
      evaldelta1428 = readrel1434->getIndex(ord1433, true);
      sid1429 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask1430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c270 = v_const2a09f8e08b8d8243373579d9;
      u64 v_c271 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c272 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c273 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c86 = _t[2];
        slog::join_probe_old<3,1>(evalindex1427, evaldelta1428, std::array<u64,3>{v_c273, 0, 0}, [&](const std::array<u64,3>& m1435) {
          u64 v_c10 = m1435[1]; u64 v_c274 = m1435[2];
          ++_fires;
          if (!((is_struct(v_c273) && (decode_struct_id(v_c273) == sid1429))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c270, v_c271, v_c272, v_c273}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c273, v_c274, v_c10});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c273, v_c10}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1430* _cont = new ReadTask1430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1430(db,b), false);
  // (crule (pre) (scan eval __t82ak35 __t1Sxu34 c) (body (join if (0 1 2 3) 1 __t1Sxu34 e1 e2 e3)) (head (emit $sup56712x86x0x0x0 (1 0 2 3 4) c __t82ak35 e1 e2 e3)) interp.slog:87 #f)
  class ReadTask1437 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex1436;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord1438({1, 0, 2, 3, 4});
      slog::Relation* readrel1439 = db->getRelation("$sup56712x86x0x0x0");
      head_index[0] = readrel1439->getIndex(ord1438, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1440({0, 1, 2, 3});
      slog::Relation* readrel1441 = db->getRelation("if");
      ifindex1436 = readrel1441->getIndex(ord1440, false);
  
    }
    ReadTask1437(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c202 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<4,1>(ifindex1436, std::array<u64,4>{v_c202, 0, 0, 0}, [&](const std::array<u64,4>& m1442) {
          u64 v_c145 = m1442[1]; u64 v_c146 = m1442[2]; u64 v_c147 = m1442[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c10, v_c203, v_c145, v_c146, v_c147}, std::array<u16,5>{1, 0, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1437* _cont = new ReadTask1437(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1437(db,b), false);
  // (crule (pre (let __trid9D7l780 const119eb3a23d030ee0dfe9f807) (let __trel4rjp781 constac3fe12f2763ff95bc66dbed) (let __tcol26vj782 const6b86b273ff34fce19d6b804e) (let __trel2GXh783 const4e5ef144c51cd25230c144c3) (let __tcol7AU5784 const5feceb66ffc86f38d952786c) (let __trel5NAA785 const4e5ef144c51cd25230c144c3) (let __tcol5or2786 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck c (accept seq) __trid9D7l780 __trel4rjp781 __tcol26vj782 (1 2 3 4 0)) (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid9D7l780 __trel2GXh783 __tcol7AU5784 (1 2 3 4 0)) (tycheck es (accept seq) __trid9D7l780 __trel5NAA785 __tcol5or2786 (1 2 3 4 0)) (emit-temp temp8Jp41175 c ef es) (mkstruct app (1 2 0) __t8D6k4 ef es)) interp.slog:42 #f)
  class ReadTask1452 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1443;  u32 sid1444;  u32 sid1445;  u32 sid1446;  u32 sid1447;  u32 sid1448;  u32 sid1449;  u32 sid1450;  u32 sid1451;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("temp8Jp41175");
      head_rel[4] = db->getRelation("app");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
      sid1443 = db->getRelation("app")->getStructId();
      sid1444 = db->getRelation("boolean")->getStructId();
      sid1445 = db->getRelation("if")->getStructId();
      sid1446 = db->getRelation("lambda")->getStructId();
      sid1447 = db->getRelation("let")->getStructId();
      sid1448 = db->getRelation("letrec")->getStructId();
      sid1449 = db->getRelation("num")->getStructId();
      sid1450 = db->getRelation("ref")->getStructId();
      sid1451 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1452(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c275 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c276 = v_constac3fe12f2763ff95bc66dbed;
      u64 v_c277 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c278 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c279 = v_const5feceb66ffc86f38d952786c;
      u64 v_c280 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c281 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c114 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c17 = _t[3];
        ++_fires;
        if (!(is_seq(v_c10)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c275, v_c276, v_c277, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c73) && (decode_struct_id(v_c73) == sid1443 || decode_struct_id(v_c73) == sid1444 || decode_struct_id(v_c73) == sid1445 || decode_struct_id(v_c73) == sid1446 || decode_struct_id(v_c73) == sid1447 || decode_struct_id(v_c73) == sid1448 || decode_struct_id(v_c73) == sid1449 || decode_struct_id(v_c73) == sid1450 || decode_struct_id(v_c73) == sid1451))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c275, v_c278, v_c279, v_c73}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c17)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c275, v_c280, v_c281, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<3>(head_rel[3], newbatch[3], std::array<u64,3>{v_c10, v_c73, v_c17});
        slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c73, v_c17}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1452* _cont = new ReadTask1452(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1452(db,b), false);
  // (crule (pre) (scan app __t8x6E209 ef es) (body (exists eval (1 2 0) 1 __t8x6E209) (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t8x6E209) (join $sup56712x41x0x0x0 (2 3 0 1) 2 ef es __t9lTe203 c) (join eval (0 2 1) 3 __t9lTe203 c __t8x6E209) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t8x6E209 c) (join eval (1 2 0) 2 ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join eval_args (1 2 0) 2 es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t6XAE206 __t6hhS205 cb) (join lambda (0 1 2) 1 __t6hhS205 xs eb) (join eval (1 2 0) 2 eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask1476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1453;  slog::Index** evalindex1454;  slog::Index** eval_argsindex1455;  slog::Index** tickindex1456;  slog::Index** $sup56712x41x0x0x0index1457;  slog::Index** evalindex1458;  slog::Index** eval_argsindex1459;  slog::Index** tickindex1460;  slog::Index** evalindex1461;  slog::Index** eval_ansindex1462;  slog::Index** eval_argsindex1463;  slog::Index** eval_args_ansindex1464;  slog::Index** tickindex1465;  slog::Index** tick_ansindex1466;  slog::Index** eval_ansindex1467;  slog::Index** eval_args_ansindex1468;  slog::Index** tick_ansindex1469;  slog::Index** evalindex1470;  slog::Index** closureindex1471;  slog::Index** lambdaindex1472;  slog::Index** evalindex1473;  slog::Index** eval_ansindex1474;  slog::Index** tickdelta1475;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1477({0, 1});
      slog::Relation* readrel1478 = db->getRelation("eval_ans");
      head_index[0] = readrel1478->getIndex(ord1477, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1479({1, 2, 0});
      slog::Relation* readrel1480 = db->getRelation("eval");
      evalindex1453 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({1, 2, 0});
      slog::Relation* readrel1482 = db->getRelation("eval");
      evalindex1454 = readrel1482->getIndex(ord1481, false);
      std::vector<u16> ord1483({1, 2, 0});
      slog::Relation* readrel1484 = db->getRelation("eval_args");
      eval_argsindex1455 = readrel1484->getIndex(ord1483, false);
      std::vector<u16> ord1485({1, 2, 0});
      slog::Relation* readrel1486 = db->getRelation("tick");
      tickindex1456 = readrel1486->getIndex(ord1485, false);
      std::vector<u16> ord1487({2, 3, 0, 1});
      slog::Relation* readrel1488 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1457 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({0, 2, 1});
      slog::Relation* readrel1490 = db->getRelation("eval");
      evalindex1458 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({1, 2, 0});
      slog::Relation* readrel1492 = db->getRelation("eval_args");
      eval_argsindex1459 = readrel1492->getIndex(ord1491, false);
      std::vector<u16> ord1493({1, 2, 0});
      slog::Relation* readrel1494 = db->getRelation("tick");
      tickindex1460 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({1, 2, 0});
      slog::Relation* readrel1496 = db->getRelation("eval");
      evalindex1461 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({0, 1});
      slog::Relation* readrel1498 = db->getRelation("eval_ans");
      eval_ansindex1462 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 2, 0});
      slog::Relation* readrel1500 = db->getRelation("eval_args");
      eval_argsindex1463 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({0, 1});
      slog::Relation* readrel1502 = db->getRelation("eval_args_ans");
      eval_args_ansindex1464 = readrel1502->getIndex(ord1501, false);
      std::vector<u16> ord1503({1, 2, 0});
      slog::Relation* readrel1504 = db->getRelation("tick");
      tickindex1465 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({1, 2, 0});
      slog::Relation* readrel1506 = db->getRelation("tick");
      tickdelta1475 = readrel1506->getIndex(ord1505, true);
      std::vector<u16> ord1507({0, 1});
      slog::Relation* readrel1508 = db->getRelation("tick_ans");
      tick_ansindex1466 = readrel1508->getIndex(ord1507, false);
      std::vector<u16> ord1509({0, 1});
      slog::Relation* readrel1510 = db->getRelation("eval_ans");
      eval_ansindex1467 = readrel1510->getIndex(ord1509, false);
      std::vector<u16> ord1511({0, 1});
      slog::Relation* readrel1512 = db->getRelation("eval_args_ans");
      eval_args_ansindex1468 = readrel1512->getIndex(ord1511, false);
      std::vector<u16> ord1513({0, 1});
      slog::Relation* readrel1514 = db->getRelation("tick_ans");
      tick_ansindex1469 = readrel1514->getIndex(ord1513, false);
      std::vector<u16> ord1515({2, 0, 1});
      slog::Relation* readrel1516 = db->getRelation("eval");
      evalindex1470 = readrel1516->getIndex(ord1515, false);
      std::vector<u16> ord1517({0, 1, 2});
      slog::Relation* readrel1518 = db->getRelation("closure");
      closureindex1471 = readrel1518->getIndex(ord1517, false);
      std::vector<u16> ord1519({0, 1, 2});
      slog::Relation* readrel1520 = db->getRelation("lambda");
      lambdaindex1472 = readrel1520->getIndex(ord1519, false);
      std::vector<u16> ord1521({1, 2, 0});
      slog::Relation* readrel1522 = db->getRelation("eval");
      evalindex1473 = readrel1522->getIndex(ord1521, false);
      std::vector<u16> ord1523({0, 1});
      slog::Relation* readrel1524 = db->getRelation("eval_ans");
      eval_ansindex1474 = readrel1524->getIndex(ord1523, false);
  
    }
    ReadTask1476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c183 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1453, std::array<u64,3>{v_c183, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1454, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1455, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1456, std::array<u64,3>{v_c183, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1457, std::array<u64,4>{v_c73, v_c17, 0, 0}, [&](const std::array<u64,4>& m1525) {
          u64 v_c182 = m1525[2]; u64 v_c10 = m1525[3];
          slog::join_probe<3,3>(evalindex1458, std::array<u64,3>{v_c182, v_c10, v_c183}, [&](const std::array<u64,3>& m1526) {
            if (!slog::exists_probe<3,2>(eval_argsindex1459, std::array<u64,3>{v_c17, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(tickindex1460, std::array<u64,3>{v_c183, v_c10, 0})) return;
            slog::join_probe<3,2>(evalindex1461, std::array<u64,3>{v_c73, v_c10, 0}, [&](const std::array<u64,3>& m1527) {
              u64 v_c184 = m1527[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1462, std::array<u64,2>{v_c184, 0})) return;
              slog::join_probe<3,2>(eval_argsindex1463, std::array<u64,3>{v_c17, v_c10, 0}, [&](const std::array<u64,3>& m1528) {
                u64 v_c185 = m1528[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1464, std::array<u64,2>{v_c185, 0})) return;
                slog::join_probe_old<3,2>(tickindex1465, tickdelta1475, std::array<u64,3>{v_c183, v_c10, 0}, [&](const std::array<u64,3>& m1529) {
                  u64 v_c186 = m1529[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1466, std::array<u64,2>{v_c186, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1467, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m1530) {
                    u64 v_c187 = m1530[1];
                    slog::join_probe<2,1>(eval_args_ansindex1468, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m1531) {
                      u64 v_c79 = m1531[1];
                      slog::join_probe<2,1>(tick_ansindex1469, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m1532) {
                        u64 v_c9 = m1532[1];
                        if (!slog::exists_probe<3,1>(evalindex1470, std::array<u64,3>{v_c9, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex1471, std::array<u64,3>{v_c187, 0, 0}, [&](const std::array<u64,3>& m1533) {
                          u64 v_c188 = m1533[1]; u64 v_c82 = m1533[2];
                          slog::join_probe<3,1>(lambdaindex1472, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m1534) {
                            u64 v_c85 = m1534[1]; u64 v_c86 = m1534[2];
                            slog::join_probe<3,2>(evalindex1473, std::array<u64,3>{v_c86, v_c9, 0}, [&](const std::array<u64,3>& m1535) {
                              u64 v_c189 = m1535[2];
                              slog::join_probe<2,1>(eval_ansindex1474, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m1536) {
                                u64 v_c94 = m1536[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c182, v_c94}, std::array<u16,2>{0, 1});
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
        ReadTask1476* _cont = new ReadTask1476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1476(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst49ZO477 const0fc34686741291b4dd06511b)) (scan temp4t2N1012 __t0c92476 __t18GV497 __t6n7e489 __t84ma469) (body (join let (2 1 3 0) 3 __t0c92476 __tconst49ZO477 __t84ma469 __t8zw1478)) (head (emit-temp temp9CrE1013 __t18GV497 __t6n7e489 __t8zw1478) (mkstruct let (2 1 3 0) __t6FoF491 __t6n7e489 __tconst7G6n490 __t8zw1478)) schemecfa.slog:51 #f)
  class ReadTask1538 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1537;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9CrE1013");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp4t2N1012");
      std::vector<u16> ord1539({2, 1, 3, 0});
      slog::Relation* readrel1540 = db->getRelation("let");
      letindex1537 = readrel1540->getIndex(ord1539, false);
  
    }
    ReadTask1538(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c42 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c44 = v_const0fc34686741291b4dd06511b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c190 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c194 = _t[2];
        u64 v_c265 = _t[3];
        slog::join_probe<4,3>(letindex1537, std::array<u64,4>{v_c190, v_c44, v_c265, 0}, [&](const std::array<u64,4>& m1541) {
          u64 v_c282 = m1541[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c173, v_c194, v_c282});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c194, v_c42, v_c282}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp4t2N1012", _fires);
  
      if (!_done)
      {
        ReadTask1538* _cont = new ReadTask1538(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1538(db,b), false);
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5) (let __tconst4i3L422 const30f8b180d63559f2512b744f) (let __tconst93LG421 constba2df4903a2c14e86dc3bcca) (let __tconst6zXr399 const2bc983a5942276eb00a75e21) (let __tconst0XfR396 const7297d2085ea0adffc396d546) (let __tconst466s389 const6b86b273ff34fce19d6b804e) (let __tconst9Oxy387 constef2d127de37b942baad06145)) (scan temp9wda1166 __t9Q7F423) (body (exists num (1 0) 1 __tconst466s389) (exists ref (1 0) 1 __tconst6zXr399) (exists ref (1 0) 1 __tconst0XfR396) (exists ref (1 0) 1 __tconst1UOH427) (exists ref (1 0) 1 __tconst93LG421) (exists ref (1 0) 1 __tconst4i3L422) (join num (1 0) 1 __tconst9Oxy387 __t7jad388) (join num (1 0) 1 __tconst466s389 __t7CfZ390) (join ref (1 0) 1 __tconst6zXr399 __t4jBg392) (join ref (1 0) 1 __tconst0XfR396 __t1k9L397) (join ref (1 0) 1 __tconst1UOH427 __t4O08407) (join ref (1 0) 1 __tconst93LG421 __t5p3B410) (join ref (1 0) 1 __tconst4i3L422 __t4MSc414) (let __t36Dl424 (lpush __t9Q7F423 __tconst4i3L422)) (let __t06tf412 (lpush __t9Q7F423 __t5p3B410)) (let __t0cS8401 (lpush __t9Q7F423 __tconst6zXr399)) (let __t8uoE394 (lpush __t9Q7F423 __t4jBg392))) (head (emit-temp temp7rsY1167 __t06tf412 __t0cS8401 __t36Dl424 __t8uoE394 __t9Q7F423)) schemecfa.slog:26 #f)
  class ReadTask1555 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1542;  slog::Index** refindex1543;  slog::Index** refindex1544;  slog::Index** refindex1545;  slog::Index** refindex1546;  slog::Index** refindex1547;  slog::Index** numindex1548;  slog::Index** numindex1549;  slog::Index** refindex1550;  slog::Index** refindex1551;  slog::Index** refindex1552;  slog::Index** refindex1553;  slog::Index** refindex1554;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7rsY1167");
      outer_rel = db->getRelation("temp9wda1166");
      std::vector<u16> ord1556({1, 0});
      slog::Relation* readrel1557 = db->getRelation("num");
      numindex1542 = readrel1557->getIndex(ord1556, false);
      std::vector<u16> ord1558({1, 0});
      slog::Relation* readrel1559 = db->getRelation("ref");
      refindex1543 = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({1, 0});
      slog::Relation* readrel1561 = db->getRelation("ref");
      refindex1544 = readrel1561->getIndex(ord1560, false);
      std::vector<u16> ord1562({1, 0});
      slog::Relation* readrel1563 = db->getRelation("ref");
      refindex1545 = readrel1563->getIndex(ord1562, false);
      std::vector<u16> ord1564({1, 0});
      slog::Relation* readrel1565 = db->getRelation("ref");
      refindex1546 = readrel1565->getIndex(ord1564, false);
      std::vector<u16> ord1566({1, 0});
      slog::Relation* readrel1567 = db->getRelation("ref");
      refindex1547 = readrel1567->getIndex(ord1566, false);
      std::vector<u16> ord1568({1, 0});
      slog::Relation* readrel1569 = db->getRelation("num");
      numindex1548 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({1, 0});
      slog::Relation* readrel1571 = db->getRelation("num");
      numindex1549 = readrel1571->getIndex(ord1570, false);
      std::vector<u16> ord1572({1, 0});
      slog::Relation* readrel1573 = db->getRelation("ref");
      refindex1550 = readrel1573->getIndex(ord1572, false);
      std::vector<u16> ord1574({1, 0});
      slog::Relation* readrel1575 = db->getRelation("ref");
      refindex1551 = readrel1575->getIndex(ord1574, false);
      std::vector<u16> ord1576({1, 0});
      slog::Relation* readrel1577 = db->getRelation("ref");
      refindex1552 = readrel1577->getIndex(ord1576, false);
      std::vector<u16> ord1578({1, 0});
      slog::Relation* readrel1579 = db->getRelation("ref");
      refindex1553 = readrel1579->getIndex(ord1578, false);
      std::vector<u16> ord1580({1, 0});
      slog::Relation* readrel1581 = db->getRelation("ref");
      refindex1554 = readrel1581->getIndex(ord1580, false);
  
    }
    ReadTask1555(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const0457bba0679825d285ef7fa5;
      u64 v_c100 = v_const30f8b180d63559f2512b744f;
      u64 v_c157 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c283 = v_const2bc983a5942276eb00a75e21;
      u64 v_c101 = v_const7297d2085ea0adffc396d546;
      u64 v_c158 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c102 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        if (!slog::exists_probe<2,1>(numindex1542, std::array<u64,2>{v_c158, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1543, std::array<u64,2>{v_c283, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1544, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1545, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1546, std::array<u64,2>{v_c157, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1547, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<2,1>(numindex1548, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1582) {
          u64 v_c108 = m1582[1];
          slog::join_probe<2,1>(numindex1549, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1583) {
            u64 v_c161 = m1583[1];
            slog::join_probe<2,1>(refindex1550, std::array<u64,2>{v_c283, 0}, [&](const std::array<u64,2>& m1584) {
              u64 v_c284 = m1584[1];
              slog::join_probe<2,1>(refindex1551, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1585) {
                u64 v_c109 = m1585[1];
                slog::join_probe<2,1>(refindex1552, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1586) {
                  u64 v_c110 = m1586[1];
                  slog::join_probe<2,1>(refindex1553, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m1587) {
                    u64 v_c285 = m1587[1];
                    slog::join_probe<2,1>(refindex1554, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m1588) {
                      u64 v_c111 = m1588[1];
                      u64 v_c159 = _prim_lpush(db, v_c106, v_c100);
                      if (v_c159 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                      u64 v_c103 = _prim_lpush(db, v_c106, v_c285);
                      if (v_c103 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                      u64 v_c105 = _prim_lpush(db, v_c106, v_c283);
                      if (v_c105 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                      u64 v_c160 = _prim_lpush(db, v_c106, v_c284);
                      if (v_c160 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:26"); return; }
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c103, v_c105, v_c159, v_c160, v_c106});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp9wda1166", _fires);
  
      if (!_done)
      {
        ReadTask1555* _cont = new ReadTask1555(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1555(db,b), false);
}

