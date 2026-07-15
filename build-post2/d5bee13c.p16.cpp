
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6f4b6612125fb3a0daecd279;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const798640599597df7a8daa32b1;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_const955cca1ceba45052d85984d3;
extern u64 v_consta2d3b5b64cd0c50598de1133;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc99bf3037b4c2fce0fbaab85;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c7ac02556e2ed0658(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (body (join mbranch (1 2 3 4 0) 4 __v2 __v3 t0 t1 __t3nlL127)) (head (emit mp_join_ans (0 1) __t8CpS128 __t3nlL127)) map.slog:26 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("mp_join_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("temp0yve1977");
      std::vector<u16> ord4({1, 2, 3, 4, 0});
      slog::Relation* readrel5 = db->getRelation("mbranch");
      mbranchindex0 = readrel5->getIndex(ord4, false);
  
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
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        slog::join_probe<5,4>(mbranchindex0, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m6) {
          u64 v_c5 = m6[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c5}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp0yve1977", _fires);
  
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
  // (crule (pre (let __tconst2Fuh376 const6b86b273ff34fce19d6b804e) (let __tconst0hsx377 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t1Fw3379 __t0AZp378) (body (join mp_hsb_ans (0 1) 1 __t1Fw3379 __v0) (join mp_hsb (0 1) 0 __t9DAM375 x) (cmp lt __tconst2Fuh376 x) (let chk9ktK1874 (_0002f x __tconst0hsx377)) (eq __t0AZp378 chk9ktK1874) (let __t9OPt374 (_0002a __tconst0hsx377 __v0))) (head (emit-temp temp9Aeo1872 __t9DAM375 __t9OPt374)) map.slog:19 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex7;  slog::Index** mp_hsbindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Aeo1872");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex7 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("mp_hsb");
      mp_hsbindex8 = readrel13->getIndex(ord12, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
  
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
        slog::join_probe<2,1>(mp_hsb_ansindex7, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m14) {
          u64 v_c10 = m14[1];
          slog::join_all<2>(mp_hsbindex8, [&](const std::array<u64,2>& m15) {
            u64 v_c11 = m15[0]; u64 v_c12 = m15[1];
            u64 v_c13 = _prim_lt(db, v_c6, v_c12);
            if (v_c13 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (!v_c13) return;
            u64 v_c14 = _prim__0002f(db, v_c12, v_c7);
            if (v_c14 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (v_c9 != v_c14) return;
            u64 v_c15 = _prim__0002a(db, v_c7, v_c10);
            if (v_c15 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c15});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre (let __trid0dHl1521 consta2d3b5b64cd0c50598de1133) (let __trel5O8s1522 const3a655602588fe6d8c59d4a5a) (let __tcol17sg1523 const5feceb66ffc86f38d952786c) (let __trel2uL91524 const3a655602588fe6d8c59d4a5a) (let __tcol2rCz1525 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid0dHl1521 __trel5O8s1522 __tcol17sg1523 (1 2 3 4 0)) (tycheck k (accept int) __trid0dHl1521 __trel2uL91524 __tcol2rCz1525 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __4JHd1520 l k)) map.slog:61 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid18;  u32 sid17;  u32 sid19;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
      sid18 = db->getRelation("_enum")->getStructId();
      sid17 = db->getRelation("mbranch")->getStructId();
      sid19 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c16 = v_consta2d3b5b64cd0c50598de1133;
      u64 v_c17 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
      u64 v_c19 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c26 = _t[5];
        ++_fires;
        if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid17 || decode_struct_id(v_c23) == sid18 || decode_struct_id(v_c23) == sid19))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c16, v_c17, v_c18, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c19, v_c20, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c23, v_c22}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
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
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo2y2x951 e _00024seq0) (body (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let es (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (exists eval_args (1 3 2 0) 1 _00024seq0) (exists eval (1 2 3 0) 1 e) (exists eval_args (1 3 2 0) 1 es) (join $sup70016x43x0x0x0 (0 2 3 4 5 1) 3 _00024seq0 e es rho t __t7ZV0794) (join eval_args (3 2 0 1) 4 t rho __t7ZV0794 _00024seq0) (exists eval_args (1 3 2 0) 3 es t rho) (join eval (1 2 3 0) 3 e rho t __t7vCW795) (exists eval_ans (0 1) 1 __t7vCW795) (join eval_args (1 3 2 0) 3 es t rho __t9m2L796) (exists eval_args_ans (0 1) 1 __t9m2L796) (join eval_ans (0 1) 1 __t7vCW795 __v0) (join eval_args_ans (0 1) 1 __t9m2L796 __v1) (letp chk0nfT2044 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk0nfT2044)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** eval_argsindex21;  slog::Index** evalindex22;  slog::Index** eval_argsindex23;  slog::Index** $sup70016x43x0x0x0index24;  slog::Index** eval_argsindex25;  slog::Index** eval_argsindex26;  slog::Index** evalindex27;  slog::Index** eval_ansindex28;  slog::Index** eval_argsindex29;  slog::Index** eval_args_ansindex30;  slog::Index** eval_ansindex31;  slog::Index** eval_args_ansindex32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      std::vector<u16> ord34({1, 0, 2});
      slog::Relation* readrel35 = db->getRelation("$seq_at");
      driver_index = readrel35->getIndex(ord34, true);
      std::vector<u16> ord36({1, 3, 2, 0});
      slog::Relation* readrel37 = db->getRelation("eval_args");
      eval_argsindex21 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 3, 0});
      slog::Relation* readrel39 = db->getRelation("eval");
      evalindex22 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 3, 2, 0});
      slog::Relation* readrel41 = db->getRelation("eval_args");
      eval_argsindex23 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel43 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index24 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({3, 2, 0, 1});
      slog::Relation* readrel45 = db->getRelation("eval_args");
      eval_argsindex25 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 3, 2, 0});
      slog::Relation* readrel47 = db->getRelation("eval_args");
      eval_argsindex26 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 3, 0});
      slog::Relation* readrel49 = db->getRelation("eval");
      evalindex27 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("eval_ans");
      eval_ansindex28 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 3, 2, 0});
      slog::Relation* readrel53 = db->getRelation("eval_args");
      eval_argsindex29 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("eval_args_ans");
      eval_args_ansindex30 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("eval_ans");
      eval_ansindex31 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("eval_args_ans");
      eval_args_ansindex32 = readrel59->getIndex(ord58, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = _prim_lempty(db);
      if (v_c32 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c31, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m60) {
        u64 v_c33 = m60[1];
        u64 v_c34 = m60[2];
        if (buckethash(v_c33) != bucket) return;
        bool ok61 = true;
        u64 v_c35 = _prim_aslst(db, v_c34, &ok61);
        if (!ok61) return;
        u64 v_c36 = _prim_llen(db, v_c35);
        if (v_c36 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c37 = _prim_ge(db, v_c36, v_c27);
        if (v_c37 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        if (!v_c37) return;
        u64 v_c38 = _prim__0002d(db, v_c36, v_c30);
        if (v_c38 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c39 = _prim_lslice(db, v_c35, v_c29, v_c38);
        if (v_c39 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        if (!slog::exists_probe<4,1>(eval_argsindex21, std::array<u64,4>{v_c34, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex22, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex23, std::array<u64,4>{v_c39, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x43x0x0x0index24, std::array<u64,6>{v_c34, v_c33, v_c39, 0, 0, 0}, [&](const std::array<u64,6>& m63) {
          u64 v_c40 = m63[3]; u64 v_c41 = m63[4]; u64 v_c42 = m63[5];
          slog::join_probe<4,4>(eval_argsindex25, std::array<u64,4>{v_c41, v_c40, v_c42, v_c34}, [&](const std::array<u64,4>& m64) {
            if (!slog::exists_probe<4,3>(eval_argsindex26, std::array<u64,4>{v_c39, v_c41, v_c40, 0})) return;
            slog::join_probe<4,3>(evalindex27, std::array<u64,4>{v_c33, v_c40, v_c41, 0}, [&](const std::array<u64,4>& m65) {
              u64 v_c43 = m65[3];
              if (!slog::exists_probe<2,1>(eval_ansindex28, std::array<u64,2>{v_c43, 0})) return;
              slog::join_probe<4,3>(eval_argsindex29, std::array<u64,4>{v_c39, v_c41, v_c40, 0}, [&](const std::array<u64,4>& m66) {
                u64 v_c44 = m66[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex30, std::array<u64,2>{v_c44, 0})) return;
                slog::join_probe<2,1>(eval_ansindex31, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m67) {
                  u64 v_c10 = m67[1];
                  slog::join_probe<2,1>(eval_args_ansindex32, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m68) {
                    u64 v_c45 = m68[1];
                    bool ok69 = true;
                    u64 v_c46 = _prim_lref(db, v_c35, v_c28, &ok69);
                    if (!ok69) return;
                    if (v_c33 != v_c46) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c32, v_c42, v_c10, v_c45});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4)) (scan temp9iKU2011 __t2zNy470 __t6gSw510) (body (join letrec (1 2 3 0) 3 __tconst2mJz511 __t6gSw510 __t2zNy470 __t9LO7512)) (head (emit program (0) __t9LO7512)) kcfa.slog:40 #f)
  class ReadTask71 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex70;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord72({0});
      slog::Relation* readrel73 = db->getRelation("program");
      head_index[0] = readrel73->getIndex(ord72, false);
      outer_rel = db->getRelation("temp9iKU2011");
      std::vector<u16> ord74({1, 2, 3, 0});
      slog::Relation* readrel75 = db->getRelation("letrec");
      letrecindex70 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask71(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        slog::join_probe<4,3>(letrecindex70, std::array<u64,4>{v_c47, v_c49, v_c48, 0}, [&](const std::array<u64,4>& m76) {
          u64 v_c50 = m76[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp9iKU2011", _fires);
  
      if (!_done)
      {
        ReadTask71* _cont = new ReadTask71(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask71(db,b), false);
  // (crule (pre) (scan $sup5638x107x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 q) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t99il580) (join-old mp_msk_ans (0 1) 2 (0 1) __t99il580 q)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t99il580 l m n p q r u)) map.slog:108 #f)
  class ReadTask82 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex77;  slog::Index** mp_mskindex78;  slog::Index** mp_msk_ansindex79;  slog::Index** mp_mskdelta80;  slog::Index** mp_msk_ansdelta81;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord83({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel84 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel84->getIndex(ord83, false);
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord85({1, 0});
      slog::Relation* readrel86 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex77 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("mp_msk");
      mp_mskindex78 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 2, 0});
      slog::Relation* readrel90 = db->getRelation("mp_msk");
      mp_mskdelta80 = readrel90->getIndex(ord89, true);
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex79 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({0, 1});
      slog::Relation* readrel94 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta81 = readrel94->getIndex(ord93, true);
  
    }
    ReadTask82(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c52 = _t[5];
        u64 v_c26 = _t[6];
        u64 v_c53 = _t[7];
        u64 v_c54 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex77, std::array<u64,2>{v_c52, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex78, mp_mskdelta80, std::array<u64,3>{v_c25, v_c51, 0}, [&](const std::array<u64,3>& m95) {
          u64 v_c55 = m95[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex79, mp_msk_ansdelta81, std::array<u64,2>{v_c55, v_c52}, [&](const std::array<u64,2>& m96) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c21, v_c54, v_c55, v_c23, v_c24, v_c51, v_c25, v_c52, v_c26, v_c53}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask82* _cont = new ReadTask82(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask82(db,b), false);
  // (crule (pre) (scan lookup __t95yV362 x rho) (body (exists store (0 1 2) 1 x) (join-old mp_get (1 2 0) 2 (1 2 0) rho x __t0Izo363) (join mp_get_ans (0 1) 1 __t0Izo363 tx) (join store (0 1 2) 2 x tx v)) (head (emit lookup_ans (0 1) __t95yV362 v)) interp.slog:39 #f)
  class ReadTask102 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex97;  slog::Index** mp_getindex98;  slog::Index** mp_get_ansindex99;  slog::Index** storeindex100;  slog::Index** mp_getdelta101;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("lookup_ans");
      head_index[0] = readrel104->getIndex(ord103, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord105({0, 1, 2});
      slog::Relation* readrel106 = db->getRelation("store");
      storeindex97 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("mp_get");
      mp_getindex98 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("mp_get");
      mp_getdelta101 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("mp_get_ans");
      mp_get_ansindex99 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 1, 2});
      slog::Relation* readrel114 = db->getRelation("store");
      storeindex100 = readrel114->getIndex(ord113, false);
  
    }
    ReadTask102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c40 = _t[2];
        if (!slog::exists_probe<3,1>(storeindex97, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe_old<3,2>(mp_getindex98, mp_getdelta101, std::array<u64,3>{v_c40, v_c12, 0}, [&](const std::array<u64,3>& m115) {
          u64 v_c57 = m115[2];
          slog::join_probe<2,1>(mp_get_ansindex99, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m116) {
            u64 v_c58 = m116[1];
            slog::join_probe<3,2>(storeindex100, std::array<u64,3>{v_c12, v_c58, 0}, [&](const std::array<u64,3>& m117) {
              u64 v_c54 = m117[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c54}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask102* _cont = new ReadTask102(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask102(db,b), false);
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan $sup70016x47x0x0x0 _00024seq0 __t2ugT17 rho t x xs) (body (join-old extend_env (0 2 3 1) 4 (0 2 3 1) __t2ugT17 _00024seq0 t rho) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo31L8847 x _00024seq0) (exists extend_env (2 3 0 1) 2 xs t) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t42Fa18) (exists mp_put_ans (0 1) 1 __t42Fa18) (join-old extend_env (2 3 0 1) 2 (2 3 0 1) xs t __t8zl419 __v0) (join mp_put_ans (0 1) 2 __t42Fa18 __v0) (join extend_env_ans (0 1) 1 __t8zl419 __v1) (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (letp chk2oaV1825 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk2oaV1825) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let chk8CZb1826 (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (eq xs chk8CZb1826)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask130 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex118;  slog::Index** $seq_atindex119;  slog::Index** extend_envindex120;  slog::Index** mp_putindex121;  slog::Index** mp_put_ansindex122;  slog::Index** extend_envindex123;  slog::Index** mp_put_ansindex124;  slog::Index** extend_env_ansindex125;  slog::Index** extend_envdelta126;  slog::Index** $seq_atdelta127;  slog::Index** mp_putdelta128;  slog::Index** extend_envdelta129;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("extend_env_ans");
      head_index[0] = readrel132->getIndex(ord131, false);
      outer_rel = db->getRelation("$sup70016x47x0x0x0");
      std::vector<u16> ord133({0, 2, 3, 1});
      slog::Relation* readrel134 = db->getRelation("extend_env");
      extend_envindex118 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({0, 2, 3, 1});
      slog::Relation* readrel136 = db->getRelation("extend_env");
      extend_envdelta126 = readrel136->getIndex(ord135, true);
      std::vector<u16> ord137({1, 0, 2});
      slog::Relation* readrel138 = db->getRelation("$seq_at");
      $seq_atindex119 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0, 2});
      slog::Relation* readrel140 = db->getRelation("$seq_at");
      $seq_atdelta127 = readrel140->getIndex(ord139, true);
      std::vector<u16> ord141({2, 3, 0, 1});
      slog::Relation* readrel142 = db->getRelation("extend_env");
      extend_envindex120 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 3, 0});
      slog::Relation* readrel144 = db->getRelation("mp_put");
      mp_putindex121 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({1, 2, 3, 0});
      slog::Relation* readrel146 = db->getRelation("mp_put");
      mp_putdelta128 = readrel146->getIndex(ord145, true);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("mp_put_ans");
      mp_put_ansindex122 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({2, 3, 0, 1});
      slog::Relation* readrel150 = db->getRelation("extend_env");
      extend_envindex123 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 3, 0, 1});
      slog::Relation* readrel152 = db->getRelation("extend_env");
      extend_envdelta129 = readrel152->getIndex(ord151, true);
      std::vector<u16> ord153({0, 1});
      slog::Relation* readrel154 = db->getRelation("mp_put_ans");
      mp_put_ansindex124 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("extend_env_ans");
      extend_env_ansindex125 = readrel156->getIndex(ord155, false);
  
    }
    ReadTask130(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c40 = _t[2];
        u64 v_c41 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c65 = _t[5];
        slog::join_probe_old<4,4>(extend_envindex118, extend_envdelta126, std::array<u64,4>{v_c64, v_c34, v_c41, v_c40}, [&](const std::array<u64,4>& m157) {
          slog::join_probe_old<3,3>($seq_atindex119, $seq_atdelta127, std::array<u64,3>{v_c63, v_c12, v_c34}, [&](const std::array<u64,3>& m158) {
            if (!slog::exists_probe<4,2>(extend_envindex120, std::array<u64,4>{v_c65, v_c41, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex121, mp_putdelta128, std::array<u64,4>{v_c40, v_c12, v_c41, 0}, [&](const std::array<u64,4>& m159) {
              u64 v_c66 = m159[3];
              if (!slog::exists_probe<2,1>(mp_put_ansindex122, std::array<u64,2>{v_c66, 0})) return;
              slog::join_probe_old<4,2>(extend_envindex123, extend_envdelta129, std::array<u64,4>{v_c65, v_c41, 0, 0}, [&](const std::array<u64,4>& m160) {
                u64 v_c67 = m160[2]; u64 v_c10 = m160[3];
                slog::join_probe<2,2>(mp_put_ansindex124, std::array<u64,2>{v_c66, v_c10}, [&](const std::array<u64,2>& m161) {
                  slog::join_probe<2,1>(extend_env_ansindex125, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m162) {
                    u64 v_c45 = m162[1];
                    bool ok163 = true;
                    u64 v_c68 = _prim_aslst(db, v_c34, &ok163);
                    if (!ok163) return;
                    u64 v_c69 = _prim_llen(db, v_c68);
                    if (v_c69 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c70 = _prim_ge(db, v_c69, v_c59);
                    if (v_c70 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (!v_c70) return;
                    bool ok165 = true;
                    u64 v_c71 = _prim_lref(db, v_c68, v_c60, &ok165);
                    if (!ok165) return;
                    if (v_c12 != v_c71) return;
                    u64 v_c72 = _prim__0002d(db, v_c69, v_c62);
                    if (v_c72 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c73 = _prim_lslice(db, v_c68, v_c61, v_c72);
                    if (v_c73 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (v_c65 != v_c73) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c45}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:$sup70016x47x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask130* _cont = new ReadTask130(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask130(db,b), false);
  // (crule (pre) (scan eval __t8Dhb337 __t87KU336 rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists eval_args (3 2 0 1) 2 t rho) (join $sup70016x75x0x0x0 (0 3 4 1 2) 3 __t8Dhb337 rho t ef es) (join app (0 1 2) 3 __t87KU336 ef es) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t8KmI338) (exists eval_ans (0 1) 1 __t8KmI338) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t24hv340) (exists eval_args_ans (0 1) 1 __t24hv340) (join eval_ans (0 1) 1 __t8KmI338 __t1N6L339) (join eval_args_ans (0 1) 1 __t24hv340 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t1N6L339 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t9Mk1341) (join delta_ans (0 1) 1 __t9Mk1341 v)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex166;  slog::Index** eval_argsindex167;  slog::Index** $sup70016x75x0x0x0index168;  slog::Index** appindex169;  slog::Index** eval_argsindex170;  slog::Index** evalindex171;  slog::Index** eval_ansindex172;  slog::Index** eval_argsindex173;  slog::Index** eval_args_ansindex174;  slog::Index** eval_ansindex175;  slog::Index** eval_args_ansindex176;  slog::Index** deltaindex177;  slog::Index** primindex178;  slog::Index** deltaindex179;  slog::Index** delta_ansindex180;  slog::Index** evaldelta181;  slog::Index** eval_argsdelta182;  slog::Index** primdelta183;  slog::Index** deltadelta184;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("eval_ans");
      head_index[0] = readrel187->getIndex(ord186, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord188({2, 3, 0, 1});
      slog::Relation* readrel189 = db->getRelation("eval");
      evalindex166 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({3, 2, 0, 1});
      slog::Relation* readrel191 = db->getRelation("eval_args");
      eval_argsindex167 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 3, 4, 1, 2});
      slog::Relation* readrel193 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index168 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1, 2});
      slog::Relation* readrel195 = db->getRelation("app");
      appindex169 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 3, 2, 0});
      slog::Relation* readrel197 = db->getRelation("eval_args");
      eval_argsindex170 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 2, 3, 0});
      slog::Relation* readrel199 = db->getRelation("eval");
      evalindex171 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 3, 0});
      slog::Relation* readrel201 = db->getRelation("eval");
      evaldelta181 = readrel201->getIndex(ord200, true);
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("eval_ans");
      eval_ansindex172 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 3, 2, 0});
      slog::Relation* readrel205 = db->getRelation("eval_args");
      eval_argsindex173 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 3, 2, 0});
      slog::Relation* readrel207 = db->getRelation("eval_args");
      eval_argsdelta182 = readrel207->getIndex(ord206, true);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("eval_args_ans");
      eval_args_ansindex174 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("eval_ans");
      eval_ansindex175 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1});
      slog::Relation* readrel213 = db->getRelation("eval_args_ans");
      eval_args_ansindex176 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({2, 0, 1});
      slog::Relation* readrel215 = db->getRelation("delta");
      deltaindex177 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("prim");
      primindex178 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("prim");
      primdelta183 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("delta");
      deltaindex179 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("delta");
      deltadelta184 = readrel223->getIndex(ord222, true);
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("delta_ans");
      delta_ansindex180 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask185(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[2];
        u64 v_c41 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex166, std::array<u64,4>{v_c40, v_c41, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex167, std::array<u64,4>{v_c41, v_c40, 0, 0})) return;
        slog::join_probe<5,3>($sup70016x75x0x0x0index168, std::array<u64,5>{v_c74, v_c40, v_c41, 0, 0}, [&](const std::array<u64,5>& m226) {
          u64 v_c76 = m226[3]; u64 v_c39 = m226[4];
          slog::join_probe<3,3>(appindex169, std::array<u64,3>{v_c75, v_c76, v_c39}, [&](const std::array<u64,3>& m227) {
            if (!slog::exists_probe<4,3>(eval_argsindex170, std::array<u64,4>{v_c39, v_c41, v_c40, 0})) return;
            slog::join_probe_old<4,3>(evalindex171, evaldelta181, std::array<u64,4>{v_c76, v_c40, v_c41, 0}, [&](const std::array<u64,4>& m228) {
              u64 v_c77 = m228[3];
              if (!slog::exists_probe<2,1>(eval_ansindex172, std::array<u64,2>{v_c77, 0})) return;
              slog::join_probe_old<4,3>(eval_argsindex173, eval_argsdelta182, std::array<u64,4>{v_c39, v_c41, v_c40, 0}, [&](const std::array<u64,4>& m229) {
                u64 v_c78 = m229[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex174, std::array<u64,2>{v_c78, 0})) return;
                slog::join_probe<2,1>(eval_ansindex175, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m230) {
                  u64 v_c79 = m230[1];
                  slog::join_probe<2,1>(eval_args_ansindex176, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m231) {
                    u64 v_c80 = m231[1];
                    if (!slog::exists_probe<3,1>(deltaindex177, std::array<u64,3>{v_c80, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex178, primdelta183, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m232) {
                      u64 v_c81 = m232[1];
                      slog::join_probe_old<3,2>(deltaindex179, deltadelta184, std::array<u64,3>{v_c81, v_c80, 0}, [&](const std::array<u64,3>& m233) {
                        u64 v_c82 = m233[2];
                        slog::join_probe<2,1>(delta_ansindex180, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m234) {
                          u64 v_c54 = m234[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c74, v_c54}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask185* _cont = new ReadTask185(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask185(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1lCq870 __t4CTM7 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5fwv868 __t4CTM7 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo41sW869 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4Tlp871 __t4CTM7 _00024seq2) (exists _enum (1 0) 1 __tconst6yBc1412) (join delta (1 2 0) 2 __tconst2fTo4 _00024seq2 __t9sv95) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join prim (0 1) 1 __t4CTM7 op) (letp _00024sql5qXm863 (aslst _00024seq2)) (let chk334p1931 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk334p1931) (letp chk4kaT1932 (lref _00024sql5qXm863 _00024sqc32Jr866)) (eq __t4CTM7 chk4kaT1932) (letp chk9ZfM1933 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk9ZfM1933)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask243 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex235;  slog::Index** $seq_atindex236;  slog::Index** $seq_atrindex237;  slog::Index** _enumindex238;  slog::Index** deltaindex239;  slog::Index** _enumindex240;  slog::Index** primindex241;  slog::Index** $seq_atrdelta242;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord244({1, 0, 2});
      slog::Relation* readrel245 = db->getRelation("$seq_atr");
      driver_index = readrel245->getIndex(ord244, true);
      std::vector<u16> ord246({1, 0, 2});
      slog::Relation* readrel247 = db->getRelation("$seq_at");
      $seq_atindex235 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 0, 2});
      slog::Relation* readrel249 = db->getRelation("$seq_at");
      $seq_atindex236 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0, 2});
      slog::Relation* readrel251 = db->getRelation("$seq_atr");
      $seq_atrindex237 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 0, 2});
      slog::Relation* readrel253 = db->getRelation("$seq_atr");
      $seq_atrdelta242 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("_enum");
      _enumindex238 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("delta");
      deltaindex239 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 0});
      slog::Relation* readrel259 = db->getRelation("_enum");
      _enumindex240 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("prim");
      primindex241 = readrel261->getIndex(ord260, false);
  
    }
    ReadTask243(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c84 = v_const06abaa100ecef791ce028c56;
      u64 v_c85 = v_constd4735e3a265e16eee03f5971;
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c90, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m262) {
        u64 v_c92 = m262[1];
        u64 v_c93 = m262[2];
        if (buckethash(v_c92) != bucket) return;
        slog::join_probe<3,3>($seq_atindex235, std::array<u64,3>{v_c88, v_c92, v_c93}, [&](const std::array<u64,3>& m263) {
          slog::join_probe<3,3>($seq_atindex236, std::array<u64,3>{v_c89, v_c92, v_c93}, [&](const std::array<u64,3>& m264) {
            slog::join_probe_old<3,3>($seq_atrindex237, $seq_atrdelta242, std::array<u64,3>{v_c91, v_c92, v_c93}, [&](const std::array<u64,3>& m265) {
              if (!slog::exists_probe<2,1>(_enumindex238, std::array<u64,2>{v_c83, 0})) return;
              slog::join_probe<3,2>(deltaindex239, std::array<u64,3>{v_c84, v_c93, 0}, [&](const std::array<u64,3>& m266) {
                u64 v_c94 = m266[2];
                slog::join_probe<2,1>(_enumindex240, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m267) {
                  u64 v_c95 = m267[1];
                  slog::join_probe<2,1>(primindex241, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m268) {
                    u64 v_c81 = m268[1];
                    bool ok269 = true;
                    u64 v_c96 = _prim_aslst(db, v_c93, &ok269);
                    if (!ok269) return;
                    u64 v_c97 = _prim_llen(db, v_c96);
                    if (v_c97 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c85 != v_c97) return;
                    bool ok270 = true;
                    u64 v_c98 = _prim_lref(db, v_c96, v_c86, &ok270);
                    if (!ok270) return;
                    if (v_c92 != v_c98) return;
                    bool ok271 = true;
                    u64 v_c99 = _prim_lref(db, v_c96, v_c87, &ok271);
                    if (!ok271) return;
                    if (v_c92 != v_c99) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c94});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c95}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask243* _cont = new ReadTask243(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask243(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t27ag118 p) (body (exists $sup5638x95x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t27ag118 p) (exists $sup5638x95x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t27ag118 q m) (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mbranch (1 2 3 4 0) 1 q) (join-old $sup5638x95x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t27ag118 m q p __t2hbE115 l n r u v) (cmp lt n m) (join-old $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 (1 2 4 6 0 3 5 7 8) l m p r __t2hbE115 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (1 2 0) 1 l) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5EdF114) (exists mp_union (0 1 2) 2 __t2hbE115 __t5EdF114) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_union (0 1 2) 3 (0 1 2) __t2hbE115 __t5EdF114 __t8CES119) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join-old mp_union_ans (0 1) 1 (0 1) __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask297 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index272;  slog::Index** $sup5638x95x0x0x0index273;  slog::Index** mbranchindex274;  slog::Index** mp_mskindex275;  slog::Index** $sup5638x95x0x0x0index276;  slog::Index** mbranchindex277;  slog::Index** mbranchindex278;  slog::Index** $sup5638x95x0x0x1index279;  slog::Index** $sup5638x95x0x0x0index280;  slog::Index** mbranchindex281;  slog::Index** mp_unionindex282;  slog::Index** mbranchindex283;  slog::Index** mp_unionindex284;  slog::Index** mbranchindex285;  slog::Index** mp_unionindex286;  slog::Index** mp_unionindex287;  slog::Index** mp_union_ansindex288;  slog::Index** mp_mskdelta289;  slog::Index** $sup5638x95x0x0x1delta290;  slog::Index** $sup5638x95x0x0x0delta291;  slog::Index** mbranchdelta292;  slog::Index** mbranchdelta293;  slog::Index** mp_uniondelta294;  slog::Index** mp_uniondelta295;  slog::Index** mp_union_ansdelta296;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord298({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel299 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index272 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel301 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index273 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 3, 4, 0});
      slog::Relation* readrel303 = db->getRelation("mbranch");
      mbranchindex274 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1, 2});
      slog::Relation* readrel305 = db->getRelation("mp_msk");
      mp_mskindex275 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1, 2});
      slog::Relation* readrel307 = db->getRelation("mp_msk");
      mp_mskdelta289 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel309 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index276 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 3, 4, 0});
      slog::Relation* readrel311 = db->getRelation("mbranch");
      mbranchindex277 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("mbranch");
      mbranchindex278 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel315 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index279 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel317 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta290 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel319 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index280 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel321 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0delta291 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({1, 2, 3, 4, 0});
      slog::Relation* readrel323 = db->getRelation("mbranch");
      mbranchindex281 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("mp_union");
      mp_unionindex282 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 3, 4, 0});
      slog::Relation* readrel327 = db->getRelation("mbranch");
      mbranchindex283 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 3, 4, 0});
      slog::Relation* readrel329 = db->getRelation("mbranch");
      mbranchdelta292 = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({0, 1, 2});
      slog::Relation* readrel331 = db->getRelation("mp_union");
      mp_unionindex284 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 3, 4, 0});
      slog::Relation* readrel333 = db->getRelation("mbranch");
      mbranchindex285 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 3, 4, 0});
      slog::Relation* readrel335 = db->getRelation("mbranch");
      mbranchdelta293 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1, 2});
      slog::Relation* readrel337 = db->getRelation("mp_union");
      mp_unionindex286 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1, 2});
      slog::Relation* readrel339 = db->getRelation("mp_union");
      mp_uniondelta294 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({1, 2, 0});
      slog::Relation* readrel341 = db->getRelation("mp_union");
      mp_unionindex287 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 0});
      slog::Relation* readrel343 = db->getRelation("mp_union");
      mp_uniondelta295 = readrel343->getIndex(ord342, true);
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("mp_union_ans");
      mp_union_ansindex288 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1});
      slog::Relation* readrel347 = db->getRelation("mp_union_ans");
      mp_union_ansdelta296 = readrel347->getIndex(ord346, true);
  
    }
    ReadTask297(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c25 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index272, std::array<u64,10>{v_c101, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index273, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex274, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex275, mp_mskdelta289, std::array<u64,3>{v_c101, 0, 0}, [&](const std::array<u64,3>& m348) {
          u64 v_c52 = m348[1]; u64 v_c24 = m348[2];
          if (!slog::exists_probe<9,3>($sup5638x95x0x0x0index276, std::array<u64,9>{v_c24, v_c52, v_c25, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex277, std::array<u64,5>{v_c25, v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex278, std::array<u64,5>{v_c52, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x95x0x0x1index279, $sup5638x95x0x0x1delta290, std::array<u64,10>{v_c101, v_c24, v_c52, v_c25, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m349) {
            u64 v_c102 = m349[4]; u64 v_c23 = m349[5]; u64 v_c51 = m349[6]; u64 v_c26 = m349[7]; u64 v_c53 = m349[8]; u64 v_c54 = m349[9];
            u64 v_c103 = _prim_lt(db, v_c51, v_c24);
            if (v_c103 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c103) return;
            slog::join_probe_old<9,9>($sup5638x95x0x0x0index280, $sup5638x95x0x0x0delta291, std::array<u64,9>{v_c23, v_c24, v_c25, v_c26, v_c102, v_c51, v_c52, v_c53, v_c54}, [&](const std::array<u64,9>& m351) {
              if (!slog::exists_probe<5,4>(mbranchindex281, std::array<u64,5>{v_c52, v_c51, v_c53, v_c54, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex282, std::array<u64,3>{v_c23, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex283, mbranchdelta292, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0}, [&](const std::array<u64,5>& m352) {
                u64 v_c104 = m352[4];
                if (!slog::exists_probe<3,2>(mp_unionindex284, std::array<u64,3>{v_c102, v_c104, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex285, mbranchdelta293, std::array<u64,5>{v_c52, v_c51, v_c53, v_c54, 0}, [&](const std::array<u64,5>& m353) {
                  u64 v_c105 = m353[4];
                  slog::join_probe_old<3,3>(mp_unionindex286, mp_uniondelta294, std::array<u64,3>{v_c102, v_c104, v_c105}, [&](const std::array<u64,3>& m354) {
                    slog::join_probe_old<3,2>(mp_unionindex287, mp_uniondelta295, std::array<u64,3>{v_c23, v_c105, 0}, [&](const std::array<u64,3>& m355) {
                      u64 v_c106 = m355[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex288, mp_union_ansdelta296, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m356) {
                        u64 v_c10 = m356[1];
                        u64 v_c107 = _prim_band(db, v_c52, v_c24);
                        if (v_c107 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c108 = _prim_lt(db, v_c107, v_c100);
                        if (v_c108 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c108) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c10, v_c24, v_c25, v_c26});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask297* _cont = new ReadTask297(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask297(db,b), false);
  // (crule (pre) (scan mp_union __t4atM456 r v) (body (exists $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 r v) (exists mbranch (4 0 1 2 3) 1 v) (exists mbranch (4 0 1 2 3) 1 r) (join mp_union_ans (0 1) 1 __t4atM456 __v1) (join $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 r v __t70BJ454 l m p u) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (join mbranch (1 2 3 4 0) 4 p m u v __t1p4P452) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (join mbranch (1 2 3 4 0) 4 p m l r __t4xjy453) (join mp_union (0 1 2) 3 __t70BJ454 __t4xjy453 __t1p4P452) (join mp_union (1 2 0) 2 l u __t1OdF455) (join mp_union_ans (0 1) 1 __t1OdF455 __v0)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask371 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index358;  slog::Index** mbranchindex359;  slog::Index** mbranchindex360;  slog::Index** mp_union_ansindex361;  slog::Index** $sup5638x93x0x0x0index362;  slog::Index** mbranchindex363;  slog::Index** mp_unionindex364;  slog::Index** mbranchindex365;  slog::Index** mp_unionindex366;  slog::Index** mbranchindex367;  slog::Index** mp_unionindex368;  slog::Index** mp_unionindex369;  slog::Index** mp_union_ansindex370;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord372({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel373 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index358 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({4, 0, 1, 2, 3});
      slog::Relation* readrel375 = db->getRelation("mbranch");
      mbranchindex359 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({4, 0, 1, 2, 3});
      slog::Relation* readrel377 = db->getRelation("mbranch");
      mbranchindex360 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("mp_union_ans");
      mp_union_ansindex361 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel381 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index362 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 3, 4, 0});
      slog::Relation* readrel383 = db->getRelation("mbranch");
      mbranchindex363 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("mp_union");
      mp_unionindex364 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 3, 4, 0});
      slog::Relation* readrel387 = db->getRelation("mbranch");
      mbranchindex365 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 0, 1});
      slog::Relation* readrel389 = db->getRelation("mp_union");
      mp_unionindex366 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 3, 4, 0});
      slog::Relation* readrel391 = db->getRelation("mbranch");
      mbranchindex367 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 1, 2});
      slog::Relation* readrel393 = db->getRelation("mp_union");
      mp_unionindex368 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("mp_union");
      mp_unionindex369 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("mp_union_ans");
      mp_union_ansindex370 = readrel397->getIndex(ord396, false);
  
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
        u64 v_c109 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c54 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x93x0x0x0index358, std::array<u64,7>{v_c26, v_c54, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex359, std::array<u64,5>{v_c54, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex360, std::array<u64,5>{v_c26, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex361, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m398) {
          u64 v_c45 = m398[1];
          slog::join_probe<7,2>($sup5638x93x0x0x0index362, std::array<u64,7>{v_c26, v_c54, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m399) {
            u64 v_c110 = m399[2]; u64 v_c23 = m399[3]; u64 v_c24 = m399[4]; u64 v_c25 = m399[5]; u64 v_c53 = m399[6];
            if (!slog::exists_probe<5,4>(mbranchindex363, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex364, std::array<u64,3>{v_c23, v_c53, 0})) return;
            slog::join_probe<5,4>(mbranchindex365, std::array<u64,5>{v_c25, v_c24, v_c53, v_c54, 0}, [&](const std::array<u64,5>& m400) {
              u64 v_c111 = m400[4];
              if (!slog::exists_probe<3,2>(mp_unionindex366, std::array<u64,3>{v_c111, v_c110, 0})) return;
              slog::join_probe<5,4>(mbranchindex367, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0}, [&](const std::array<u64,5>& m401) {
                u64 v_c112 = m401[4];
                slog::join_probe<3,3>(mp_unionindex368, std::array<u64,3>{v_c110, v_c112, v_c111}, [&](const std::array<u64,3>& m402) {
                  slog::join_probe<3,2>(mp_unionindex369, std::array<u64,3>{v_c23, v_c53, 0}, [&](const std::array<u64,3>& m403) {
                    u64 v_c113 = m403[2];
                    slog::join_probe<2,1>(mp_union_ansindex370, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m404) {
                      u64 v_c10 = m404[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c110, v_c10, v_c45, v_c24, v_c25});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c45}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
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
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (scan mp_put __t7U64528 t k v) (body (exists mp_put_soft (1 2 3 0) 3 t k v) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst25r1527) (exists mp_put_ans (0 1) 1 __t7U64528) (join $sup5638x68x0x0x0 (1 2 3 0) 3 k t v __t94M4525) (join mp_put_soft (1 2 3 0) 4 t k v __t94M4525) (join mp_has0 (1 2 0) 2 t k __t5miQ526) (join mp_has0_ans (0 1) 2 __t5miQ526 __tconst25r1527) (join mp_put_ans (0 1) 1 __t7U64528 r)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask414 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex405;  slog::Index** mp_has0index406;  slog::Index** mp_has0_ansindex407;  slog::Index** mp_put_ansindex408;  slog::Index** $sup5638x68x0x0x0index409;  slog::Index** mp_put_softindex410;  slog::Index** mp_has0index411;  slog::Index** mp_has0_ansindex412;  slog::Index** mp_put_ansindex413;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel416->getIndex(ord415, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord417({1, 2, 3, 0});
      slog::Relation* readrel418 = db->getRelation("mp_put_soft");
      mp_put_softindex405 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("mp_has0");
      mp_has0index406 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 0});
      slog::Relation* readrel422 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex407 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({0, 1});
      slog::Relation* readrel424 = db->getRelation("mp_put_ans");
      mp_put_ansindex408 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 2, 3, 0});
      slog::Relation* readrel426 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index409 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 3, 0});
      slog::Relation* readrel428 = db->getRelation("mp_put_soft");
      mp_put_softindex410 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("mp_has0");
      mp_has0index411 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex412 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({0, 1});
      slog::Relation* readrel434 = db->getRelation("mp_put_ans");
      mp_put_ansindex413 = readrel434->getIndex(ord433, false);
  
    }
    ReadTask414(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c115 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c54 = _t[3];
        if (!slog::exists_probe<4,3>(mp_put_softindex405, std::array<u64,4>{v_c41, v_c22, v_c54, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index406, std::array<u64,3>{v_c41, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(mp_has0_ansindex407, std::array<u64,2>{v_c114, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex408, std::array<u64,2>{v_c115, 0})) return;
        slog::join_probe<4,3>($sup5638x68x0x0x0index409, std::array<u64,4>{v_c22, v_c41, v_c54, 0}, [&](const std::array<u64,4>& m435) {
          u64 v_c116 = m435[3];
          slog::join_probe<4,4>(mp_put_softindex410, std::array<u64,4>{v_c41, v_c22, v_c54, v_c116}, [&](const std::array<u64,4>& m436) {
            slog::join_probe<3,2>(mp_has0index411, std::array<u64,3>{v_c41, v_c22, 0}, [&](const std::array<u64,3>& m437) {
              u64 v_c117 = m437[2];
              slog::join_probe<2,2>(mp_has0_ansindex412, std::array<u64,2>{v_c117, v_c114}, [&](const std::array<u64,2>& m438) {
                slog::join_probe<2,1>(mp_put_ansindex413, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m439) {
                  u64 v_c26 = m439[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c116, v_c26}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask414* _cont = new ReadTask414(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask414(db,b), false);
  // (crule (pre (let __trid7PZm1399 constc99bf3037b4c2fce0fbaab85) (let __trel12aq1400 constdd7bbf31ce5f578b9805e840) (let __tcol88Dw1401 const5feceb66ffc86f38d952786c) (let __trel6opB1402 constdd7bbf31ce5f578b9805e840) (let __tcol38Y81403 const6b86b273ff34fce19d6b804e)) (scan $sup5638x98x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid7PZm1399 __trel12aq1400 __tcol88Dw1401 (1 2 3 4 0)) (tycheck m (accept int) __trid7PZm1399 __trel6opB1402 __tcol38Y81403 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4wa21398 q m)) map.slog:99 #f)
  class ReadTask440 : public slog::Task
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
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
  
    }
    ReadTask440(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constc99bf3037b4c2fce0fbaab85;
      u64 v_c119 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c120 = v_const5feceb66ffc86f38d952786c;
      u64 v_c121 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c21 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c52 = _t[5];
        u64 v_c26 = _t[6];
        u64 v_c53 = _t[7];
        u64 v_c54 = _t[8];
        ++_fires;
        if (!(is_int(v_c52)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c118, v_c119, v_c120, v_c52}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c24)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c118, v_c121, v_c122, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c52, v_c24}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask440* _cont = new ReadTask440(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask440(db,b), false);
  // (crule (pre) (scan app __t4H6p267 ef es) (body (exists eval (1 2 3 0) 1 ef) (exists eval_args (1 3 2 0) 1 es) (exists tick (1 2 0) 1 __t4H6p267) (join $sup70016x51x0x0x0 (1 2 4 0 3) 2 ef es t __d0 rho) (exists eval_args (1 3 2 0) 3 es t rho) (exists tick (1 2 0) 2 __t4H6p267 t) (join eval (1 2 3 0) 3 ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join eval_args (1 3 2 0) 3 es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join tick_ans (0 1) 1 __t8A6X268 t2) (join closure (0 1 2) 1 __t5Yru265 __t3Nsh264 rhoc) (join lambda (0 1 2) 1 __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex441;  slog::Index** eval_argsindex442;  slog::Index** tickindex443;  slog::Index** $sup70016x51x0x0x0index444;  slog::Index** eval_argsindex445;  slog::Index** tickindex446;  slog::Index** evalindex447;  slog::Index** eval_ansindex448;  slog::Index** eval_argsindex449;  slog::Index** eval_args_ansindex450;  slog::Index** tickindex451;  slog::Index** tick_ansindex452;  slog::Index** eval_ansindex453;  slog::Index** eval_args_ansindex454;  slog::Index** tick_ansindex455;  slog::Index** closureindex456;  slog::Index** lambdaindex457;  slog::Index** tickdelta458;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord460({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel461 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel461->getIndex(ord460, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord462({1, 2, 3, 0});
      slog::Relation* readrel463 = db->getRelation("eval");
      evalindex441 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 3, 2, 0});
      slog::Relation* readrel465 = db->getRelation("eval_args");
      eval_argsindex442 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("tick");
      tickindex443 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 4, 0, 3});
      slog::Relation* readrel469 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index444 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 3, 2, 0});
      slog::Relation* readrel471 = db->getRelation("eval_args");
      eval_argsindex445 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 2, 0});
      slog::Relation* readrel473 = db->getRelation("tick");
      tickindex446 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 3, 0});
      slog::Relation* readrel475 = db->getRelation("eval");
      evalindex447 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("eval_ans");
      eval_ansindex448 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 3, 2, 0});
      slog::Relation* readrel479 = db->getRelation("eval_args");
      eval_argsindex449 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("eval_args_ans");
      eval_args_ansindex450 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("tick");
      tickindex451 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 0});
      slog::Relation* readrel485 = db->getRelation("tick");
      tickdelta458 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("tick_ans");
      tick_ansindex452 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1});
      slog::Relation* readrel489 = db->getRelation("eval_ans");
      eval_ansindex453 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("eval_args_ans");
      eval_args_ansindex454 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("tick_ans");
      tick_ansindex455 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("closure");
      closureindex456 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1, 2});
      slog::Relation* readrel497 = db->getRelation("lambda");
      lambdaindex457 = readrel497->getIndex(ord496, false);
  
    }
    ReadTask459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[1];
        u64 v_c39 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex441, std::array<u64,4>{v_c76, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex442, std::array<u64,4>{v_c39, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex443, std::array<u64,3>{v_c123, 0, 0})) return;
        slog::join_probe<5,2>($sup70016x51x0x0x0index444, std::array<u64,5>{v_c76, v_c39, 0, 0, 0}, [&](const std::array<u64,5>& m498) {
          u64 v_c41 = m498[2]; u64 v_c21 = m498[3]; u64 v_c40 = m498[4];
          if (!slog::exists_probe<4,3>(eval_argsindex445, std::array<u64,4>{v_c39, v_c41, v_c40, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex446, std::array<u64,3>{v_c123, v_c41, 0})) return;
          slog::join_probe<4,3>(evalindex447, std::array<u64,4>{v_c76, v_c40, v_c41, 0}, [&](const std::array<u64,4>& m499) {
            u64 v_c124 = m499[3];
            if (!slog::exists_probe<2,1>(eval_ansindex448, std::array<u64,2>{v_c124, 0})) return;
            slog::join_probe<4,3>(eval_argsindex449, std::array<u64,4>{v_c39, v_c41, v_c40, 0}, [&](const std::array<u64,4>& m500) {
              u64 v_c125 = m500[3];
              if (!slog::exists_probe<2,1>(eval_args_ansindex450, std::array<u64,2>{v_c125, 0})) return;
              slog::join_probe_old<3,2>(tickindex451, tickdelta458, std::array<u64,3>{v_c123, v_c41, 0}, [&](const std::array<u64,3>& m501) {
                u64 v_c126 = m501[2];
                if (!slog::exists_probe<2,1>(tick_ansindex452, std::array<u64,2>{v_c126, 0})) return;
                slog::join_probe<2,1>(eval_ansindex453, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m502) {
                  u64 v_c127 = m502[1];
                  slog::join_probe<2,1>(eval_args_ansindex454, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m503) {
                    u64 v_c80 = m503[1];
                    slog::join_probe<2,1>(tick_ansindex455, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m504) {
                      u64 v_c128 = m504[1];
                      slog::join_probe<3,1>(closureindex456, std::array<u64,3>{v_c127, 0, 0}, [&](const std::array<u64,3>& m505) {
                        u64 v_c129 = m505[1]; u64 v_c130 = m505[2];
                        slog::join_probe<3,1>(lambdaindex457, std::array<u64,3>{v_c129, 0, 0}, [&](const std::array<u64,3>& m506) {
                          u64 v_c65 = m506[1]; u64 v_c131 = m506[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c124, v_c130, v_c21, v_c125, v_c126, v_c131, v_c76, v_c39, v_c40, v_c41, v_c128, v_c80, v_c65}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask459* _cont = new ReadTask459(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask459(db,b), false);
  // (crule (pre (let __trid7eCK1088 const07d7fbed0aba019c07f7eb8a) (let __trel2iiF1089 const20347926ddb307a8e2bdb71b) (let __tcol0Wnu1090 const4e07408562bedb8b60ce05c1)) (scan $sup5638x82x0x0x0 __d0 k l m p r) (body (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9pQc287) (join-old mp_msk_ans (0 1) 2 (0 1) __t9pQc287 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t6EHL288) (join-old mp_del_ans (0 1) 1 (0 1) __t6EHL288 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7eCK1088 __trel2iiF1089 __tcol0Wnu1090 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __4RjO1087 p m __v0 r)) map.slog:83 #f)
  class ReadTask520 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex507;  slog::Index** mp_delindex508;  slog::Index** mp_mskindex509;  slog::Index** mp_msk_ansindex510;  slog::Index** mp_delindex511;  slog::Index** mp_del_ansindex512;  slog::Index** mp_mskdelta513;  slog::Index** mp_msk_ansdelta514;  slog::Index** mp_deldelta515;  slog::Index** mp_del_ansdelta516;
    u32 sid518;  u32 sid517;  u32 sid519;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex507 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 2, 0});
      slog::Relation* readrel524 = db->getRelation("mp_del");
      mp_delindex508 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 0});
      slog::Relation* readrel526 = db->getRelation("mp_msk");
      mp_mskindex509 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 0});
      slog::Relation* readrel528 = db->getRelation("mp_msk");
      mp_mskdelta513 = readrel528->getIndex(ord527, true);
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex510 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1});
      slog::Relation* readrel532 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta514 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({1, 2, 0});
      slog::Relation* readrel534 = db->getRelation("mp_del");
      mp_delindex511 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 0});
      slog::Relation* readrel536 = db->getRelation("mp_del");
      mp_deldelta515 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({0, 1});
      slog::Relation* readrel538 = db->getRelation("mp_del_ans");
      mp_del_ansindex512 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({0, 1});
      slog::Relation* readrel540 = db->getRelation("mp_del_ans");
      mp_del_ansdelta516 = readrel540->getIndex(ord539, true);
      sid518 = db->getRelation("_enum")->getStructId();
      sid517 = db->getRelation("mbranch")->getStructId();
      sid519 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask520(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c133 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c134 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        u64 v_c26 = _t[5];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex507, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex508, std::array<u64,3>{v_c23, v_c22, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex509, mp_mskdelta513, std::array<u64,3>{v_c22, v_c24, 0}, [&](const std::array<u64,3>& m541) {
          u64 v_c135 = m541[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex510, mp_msk_ansdelta514, std::array<u64,2>{v_c135, v_c25}, [&](const std::array<u64,2>& m542) {
            slog::join_probe_old<3,2>(mp_delindex511, mp_deldelta515, std::array<u64,3>{v_c23, v_c22, 0}, [&](const std::array<u64,3>& m543) {
              u64 v_c136 = m543[2];
              slog::join_probe_old<2,1>(mp_del_ansindex512, mp_del_ansdelta516, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m544) {
                u64 v_c10 = m544[1];
                ++_fires;
                if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid517 || decode_struct_id(v_c26) == sid518 || decode_struct_id(v_c26) == sid519))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c132, v_c133, v_c134, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask520* _cont = new ReadTask520(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask520(db,b), false);
  // (crule (pre (let __tconst2Fuh376 const6b86b273ff34fce19d6b804e) (let __tconst0hsx377 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t9DAM375 x) (body (cmp lt __tconst2Fuh376 x) (join mp_hsb_ans (0 1) 0 __t1Fw3379 __v0) (let __t0AZp378 (_0002f x __tconst0hsx377)) (join-old mp_hsb (0 1) 2 (0 1) __t1Fw3379 __t0AZp378) (let __t9OPt374 (_0002a __tconst0hsx377 __v0))) (head (emit-temp temp9Aeo1872 __t9DAM375 __t9OPt374)) map.slog:19 #f)
  class ReadTask548 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex545;  slog::Index** mp_hsbindex546;  slog::Index** mp_hsbdelta547;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Aeo1872");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord549({0, 1});
      slog::Relation* readrel550 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex545 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("mp_hsb");
      mp_hsbindex546 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({0, 1});
      slog::Relation* readrel554 = db->getRelation("mp_hsb");
      mp_hsbdelta547 = readrel554->getIndex(ord553, true);
  
    }
    ReadTask548(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c137 = _prim_lt(db, v_c6, v_c12);
        if (v_c137 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        if (!v_c137) return;
        slog::join_all<2>(mp_hsb_ansindex545, [&](const std::array<u64,2>& m556) {
          u64 v_c8 = m556[0]; u64 v_c10 = m556[1];
          u64 v_c9 = _prim__0002f(db, v_c12, v_c7);
          if (v_c9 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex546, mp_hsbdelta547, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m557) {
            u64 v_c15 = _prim__0002a(db, v_c7, v_c10);
            if (v_c15 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c15});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask548* _cont = new ReadTask548(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask548(db,b), false);
  // (crule (pre (let __tconst7VkA464 constef2d127de37b942baad06145) (let __tconst3zaK478 const0933fb667296882d8c45abca) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e) (let __tconst8C9X496 const5feceb66ffc86f38d952786c) (let __tconst91JR503 const90fb9068eda6f2d68bb61c33) (let __tconst8eEZ507 const6f4b6612125fb3a0daecd279) (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __t4qrC508 (lempty))) (once) (body) (head (emit-temp temp4TYC2001 __t4qrC508) (mkstruct num (1 0) __t67Xh465 __tconst7VkA464) (mkstruct ref (1 0) __t1y5d469 __tconst2mJz511) (mkstruct num (1 0) __t1oVV472 __tconst0Ob1494) (mkstruct ref (1 0) __t6w00474 __tconst8eEZ507) (mkstruct primref (1 0) __t2abh479 __tconst3zaK478) (mkstruct primref (1 0) __t3x0f492 __tconst6GsZ491) (mkstruct num (1 0) __t8p4J497 __tconst8C9X496) (mkstruct primref (1 0) __t8Gth504 __tconst91JR503)) kcfa.slog:40 #f)
  class ReadTask558 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[9];
    slog::Index** head_index[9];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4TYC2001");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("num");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("primref");
      head_rel[6] = db->getRelation("primref");
      head_rel[7] = db->getRelation("num");
      head_rel[8] = db->getRelation("primref");
  
    }
    ReadTask558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c138 = v_constef2d127de37b942baad06145;
      u64 v_c139 = v_const0933fb667296882d8c45abca;
      u64 v_c140 = v_consted725292f5f32d61535958c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const5feceb66ffc86f38d952786c;
      u64 v_c143 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c144 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c47 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c145 = _prim_lempty(db);
      if (v_c145 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return true; }
  
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
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c145});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c138}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c47}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c141}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c144}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c139}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c140}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c142}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c143}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask558(db,b), true);
  // (crule (pre) (scan temp9u0L1939 __t6ckH643 __t8cgD644) (body) (head (emit mp_msk_ans (0 1) __t8cgD644 __t6ckH643)) map.slog:22 #f)
  class ReadTask559 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_msk_ans");
      std::vector<u16> ord560({0, 1});
      slog::Relation* readrel561 = db->getRelation("mp_msk_ans");
      head_index[0] = readrel561->getIndex(ord560, false);
      outer_rel = db->getRelation("temp9u0L1939");
  
    }
    ReadTask559(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c147 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c147, v_c146}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp9u0L1939", _fires);
  
      if (!_done)
      {
        ReadTask559* _cont = new ReadTask559(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask559(db,b), false);
  // (crule (pre (let _00024sqc4Fzm988 constd4735e3a265e16eee03f5971) (let _00024sqc6SKj989 const5feceb66ffc86f38d952786c) (let _00024sqc8JKk990 const6b86b273ff34fce19d6b804e) (let _00024sqc2Wqs993 const6b86b273ff34fce19d6b804e) (let _00024sqc3gqm994 const5feceb66ffc86f38d952786c) (let _00024sqc5u0R995 const6b86b273ff34fce19d6b804e) (let _00024sqc2qd4996 const5feceb66ffc86f38d952786c) (let _00024sqo0rW61001 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t5IsX765 __v1) (body (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo0rW61001 _00024seq0 _00024seq1) (exists $sup5638x127x0x0x0 (0 1 2 3 4 5) 2 _00024seq0 _00024seq1) (join mp_fromlist (1 0) 1 _00024seq1 __t1Wom763) (letp _00024sql7g5s986 (aslst _00024seq0)) (letp k (lref _00024sql7g5s986 _00024sqc6SKj989)) (letp v (lref _00024sql7g5s986 _00024sqc8JKk990)) (letp _00024sql4o7j991 (aslst _00024seq1)) (let _00024sqn095f992 (llen _00024sql4o7j991)) (cmp ge _00024sqn095f992 _00024sqc2Wqs993) (let _00024sqp3avN997 (_0002d _00024sqn095f992 _00024sqc2qd4996)) (let xs (lslice _00024sql4o7j991 _00024sqc5u0R995 _00024sqp3avN997)) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 6 k v xs _00024seq0 _00024seq1 __t1Wom763) (exists mp_fromlist (1 0) 1 xs) (join-old mp_put (3 0 2 1) 3 (3 0 2 1) v __t5IsX765 k __v0) (join mp_fromlist_ans (1 0) 1 __v0 __t3r8n764) (join mp_fromlist (0 1) 2 __t3r8n764 xs) (let chk7H2A1882 (llen _00024sql7g5s986)) (eq _00024sqc4Fzm988 chk7H2A1882) (letp chk1QqQ1883 (lref _00024sql4o7j991 _00024sqc3gqm994)) (eq _00024seq0 chk1QqQ1883)) (head (emit mp_fromlist_ans (1 0) __v1 __t1Wom763)) map.slog:128 #f)
  class ReadTask572 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex562;  slog::Index** $sup5638x127x0x0x0index563;  slog::Index** mp_fromlistindex564;  slog::Index** $sup5638x127x0x0x0index565;  slog::Index** mp_fromlistindex566;  slog::Index** mp_putindex567;  slog::Index** mp_fromlist_ansindex568;  slog::Index** mp_fromlistindex569;  slog::Index** $seq_atdelta570;  slog::Index** mp_putdelta571;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord573({1, 0});
      slog::Relation* readrel574 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel574->getIndex(ord573, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord575({1, 0, 2});
      slog::Relation* readrel576 = db->getRelation("$seq_at");
      $seq_atindex562 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 0, 2});
      slog::Relation* readrel578 = db->getRelation("$seq_at");
      $seq_atdelta570 = readrel578->getIndex(ord577, true);
      std::vector<u16> ord579({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel580 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index563 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 0});
      slog::Relation* readrel582 = db->getRelation("mp_fromlist");
      mp_fromlistindex564 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel584 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index565 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 0});
      slog::Relation* readrel586 = db->getRelation("mp_fromlist");
      mp_fromlistindex566 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({3, 0, 2, 1});
      slog::Relation* readrel588 = db->getRelation("mp_put");
      mp_putindex567 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({3, 0, 2, 1});
      slog::Relation* readrel590 = db->getRelation("mp_put");
      mp_putdelta571 = readrel590->getIndex(ord589, true);
      std::vector<u16> ord591({1, 0});
      slog::Relation* readrel592 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex568 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("mp_fromlist");
      mp_fromlistindex569 = readrel594->getIndex(ord593, false);
  
    }
    ReadTask572(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_constd4735e3a265e16eee03f5971;
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
      u64 v_c153 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c154 = v_const5feceb66ffc86f38d952786c;
      u64 v_c155 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c156 = _t[0];
        u64 v_c45 = _t[1];
        slog::join_probe_old<3,1>($seq_atindex562, $seq_atdelta570, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m595) {
          u64 v_c34 = m595[1]; u64 v_c157 = m595[2];
          if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index563, std::array<u64,6>{v_c34, v_c157, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_fromlistindex564, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m596) {
            u64 v_c158 = m596[1];
            bool ok597 = true;
            u64 v_c159 = _prim_aslst(db, v_c34, &ok597);
            if (!ok597) return;
            bool ok598 = true;
            u64 v_c22 = _prim_lref(db, v_c159, v_c149, &ok598);
            if (!ok598) return;
            bool ok599 = true;
            u64 v_c54 = _prim_lref(db, v_c159, v_c150, &ok599);
            if (!ok599) return;
            bool ok600 = true;
            u64 v_c160 = _prim_aslst(db, v_c157, &ok600);
            if (!ok600) return;
            u64 v_c161 = _prim_llen(db, v_c160);
            if (v_c161 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c162 = _prim_ge(db, v_c161, v_c151);
            if (v_c162 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (!v_c162) return;
            u64 v_c163 = _prim__0002d(db, v_c161, v_c154);
            if (v_c163 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c65 = _prim_lslice(db, v_c160, v_c153, v_c163);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            slog::join_probe<6,6>($sup5638x127x0x0x0index565, std::array<u64,6>{v_c22, v_c54, v_c65, v_c34, v_c157, v_c158}, [&](const std::array<u64,6>& m602) {
              if (!slog::exists_probe<2,1>(mp_fromlistindex566, std::array<u64,2>{v_c65, 0})) return;
              slog::join_probe_old<4,3>(mp_putindex567, mp_putdelta571, std::array<u64,4>{v_c54, v_c156, v_c22, 0}, [&](const std::array<u64,4>& m603) {
                u64 v_c10 = m603[3];
                slog::join_probe<2,1>(mp_fromlist_ansindex568, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m604) {
                  u64 v_c164 = m604[1];
                  slog::join_probe<2,2>(mp_fromlistindex569, std::array<u64,2>{v_c164, v_c65}, [&](const std::array<u64,2>& m605) {
                    u64 v_c165 = _prim_llen(db, v_c159);
                    if (v_c165 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c148 != v_c165) return;
                    bool ok606 = true;
                    u64 v_c166 = _prim_lref(db, v_c160, v_c152, &ok606);
                    if (!ok606) return;
                    if (v_c34 != v_c166) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c158}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask572* _cont = new ReadTask572(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask572(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5fwv868 __t4CTM7 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo41sW869 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1lCq870 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4Tlp871 __t4CTM7 _00024seq2) (exists _enum (1 0) 1 __tconst6yBc1412) (join delta (1 2 0) 2 __tconst2fTo4 _00024seq2 __t9sv95) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join prim (0 1) 1 __t4CTM7 op) (letp _00024sql5qXm863 (aslst _00024seq2)) (let chk5zV61925 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk5zV61925) (letp chk79iY1926 (lref _00024sql5qXm863 _00024sqc32Jr866)) (eq __t4CTM7 chk79iY1926) (letp chk1S8j1927 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk1S8j1927)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex607;  slog::Index** $seq_atrindex608;  slog::Index** $seq_atrindex609;  slog::Index** _enumindex610;  slog::Index** deltaindex611;  slog::Index** _enumindex612;  slog::Index** primindex613;  slog::Index** $seq_atdelta614;  slog::Index** $seq_atrdelta615;  slog::Index** $seq_atrdelta616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord618({1, 0, 2});
      slog::Relation* readrel619 = db->getRelation("$seq_at");
      driver_index = readrel619->getIndex(ord618, true);
      std::vector<u16> ord620({1, 0, 2});
      slog::Relation* readrel621 = db->getRelation("$seq_at");
      $seq_atindex607 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0, 2});
      slog::Relation* readrel623 = db->getRelation("$seq_at");
      $seq_atdelta614 = readrel623->getIndex(ord622, true);
      std::vector<u16> ord624({1, 0, 2});
      slog::Relation* readrel625 = db->getRelation("$seq_atr");
      $seq_atrindex608 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 0, 2});
      slog::Relation* readrel627 = db->getRelation("$seq_atr");
      $seq_atrdelta615 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({1, 0, 2});
      slog::Relation* readrel629 = db->getRelation("$seq_atr");
      $seq_atrindex609 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 0, 2});
      slog::Relation* readrel631 = db->getRelation("$seq_atr");
      $seq_atrdelta616 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({1, 0});
      slog::Relation* readrel633 = db->getRelation("_enum");
      _enumindex610 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 0});
      slog::Relation* readrel635 = db->getRelation("delta");
      deltaindex611 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 0});
      slog::Relation* readrel637 = db->getRelation("_enum");
      _enumindex612 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({0, 1});
      slog::Relation* readrel639 = db->getRelation("prim");
      primindex613 = readrel639->getIndex(ord638, false);
  
    }
    ReadTask617(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c84 = v_const06abaa100ecef791ce028c56;
      u64 v_c85 = v_constd4735e3a265e16eee03f5971;
      u64 v_c86 = v_const5feceb66ffc86f38d952786c;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c88, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m640) {
        u64 v_c92 = m640[1];
        u64 v_c93 = m640[2];
        if (buckethash(v_c92) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex607, $seq_atdelta614, std::array<u64,3>{v_c89, v_c92, v_c93}, [&](const std::array<u64,3>& m641) {
          slog::join_probe_old<3,3>($seq_atrindex608, $seq_atrdelta615, std::array<u64,3>{v_c90, v_c92, v_c93}, [&](const std::array<u64,3>& m642) {
            slog::join_probe_old<3,3>($seq_atrindex609, $seq_atrdelta616, std::array<u64,3>{v_c91, v_c92, v_c93}, [&](const std::array<u64,3>& m643) {
              if (!slog::exists_probe<2,1>(_enumindex610, std::array<u64,2>{v_c83, 0})) return;
              slog::join_probe<3,2>(deltaindex611, std::array<u64,3>{v_c84, v_c93, 0}, [&](const std::array<u64,3>& m644) {
                u64 v_c94 = m644[2];
                slog::join_probe<2,1>(_enumindex612, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m645) {
                  u64 v_c95 = m645[1];
                  slog::join_probe<2,1>(primindex613, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m646) {
                    u64 v_c81 = m646[1];
                    bool ok647 = true;
                    u64 v_c96 = _prim_aslst(db, v_c93, &ok647);
                    if (!ok647) return;
                    u64 v_c167 = _prim_llen(db, v_c96);
                    if (v_c167 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c85 != v_c167) return;
                    bool ok648 = true;
                    u64 v_c168 = _prim_lref(db, v_c96, v_c86, &ok648);
                    if (!ok648) return;
                    if (v_c92 != v_c168) return;
                    bool ok649 = true;
                    u64 v_c169 = _prim_lref(db, v_c96, v_c87, &ok649);
                    if (!ok649) return;
                    if (v_c92 != v_c169) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c94});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c95}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask617* _cont = new ReadTask617(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask617(db,b), false);
  // (crule (pre (let __tconst6pJx1346 constb9e118781cea1f9fa01462e0) (let __tconst62iD1347 const0122baa3ac55f1b433944eb1) (let __tconst3W5V576 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0LoQ973 const6b86b273ff34fce19d6b804e) (let _00024sqc1LSK974 const5feceb66ffc86f38d952786c) (let _00024sqo9raf975 const5feceb66ffc86f38d952786c) (let _00024sqo4FnC976 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3W5V576 _00024seq1 __t9o8A577) (body (letp _00024sql99sk971 (aslst _00024seq1)) (letp __t9AVR579 (lref _00024sql99sk971 _00024sqc1LSK974)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9raf975 __t9AVR579 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4FnC976 __t9AVR579 _00024seq1) (exists _enum (1 0) 1 __tconst62iD1347) (join _enum (1 0) 1 __tconst6pJx1346 __t18UG578) (join-old boolval (0 1) 2 (0 1) __t9AVR579 __t18UG578) (join _enum (1 0) 1 __tconst62iD1347 __t2cB8574) (let chk3bDF2064 (llen _00024sql99sk971)) (eq _00024sqc0LoQ973 chk3bDF2064)) (head (emit-temp temp7pkd2063 __t9o8A577) (mkstruct boolval (1 0) __t7CgS575 __t2cB8574)) interp.slog:118 #f)
  class ReadTask659 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex650;  slog::Index** $seq_atrindex651;  slog::Index** _enumindex652;  slog::Index** _enumindex653;  slog::Index** boolvalindex654;  slog::Index** _enumindex655;  slog::Index** $seq_atdelta656;  slog::Index** $seq_atrdelta657;  slog::Index** boolvaldelta658;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7pkd2063");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("delta");
      driver_index = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({1, 0, 2});
      slog::Relation* readrel663 = db->getRelation("$seq_at");
      $seq_atindex650 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0, 2});
      slog::Relation* readrel665 = db->getRelation("$seq_at");
      $seq_atdelta656 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({1, 0, 2});
      slog::Relation* readrel667 = db->getRelation("$seq_atr");
      $seq_atrindex651 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 0, 2});
      slog::Relation* readrel669 = db->getRelation("$seq_atr");
      $seq_atrdelta657 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({1, 0});
      slog::Relation* readrel671 = db->getRelation("_enum");
      _enumindex652 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 0});
      slog::Relation* readrel673 = db->getRelation("_enum");
      _enumindex653 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1});
      slog::Relation* readrel675 = db->getRelation("boolval");
      boolvalindex654 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({0, 1});
      slog::Relation* readrel677 = db->getRelation("boolval");
      boolvaldelta658 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({1, 0});
      slog::Relation* readrel679 = db->getRelation("_enum");
      _enumindex655 = readrel679->getIndex(ord678, false);
  
    }
    ReadTask659(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c171 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c172 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c173 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c174 = v_const5feceb66ffc86f38d952786c;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c172, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m680) {
        u64 v_c157 = m680[1];
        u64 v_c177 = m680[2];
        if (buckethash(v_c157) != bucket) return;
        bool ok681 = true;
        u64 v_c178 = _prim_aslst(db, v_c157, &ok681);
        if (!ok681) return;
        bool ok682 = true;
        u64 v_c179 = _prim_lref(db, v_c178, v_c174, &ok682);
        if (!ok682) return;
        slog::join_probe_old<3,3>($seq_atindex650, $seq_atdelta656, std::array<u64,3>{v_c175, v_c179, v_c157}, [&](const std::array<u64,3>& m683) {
          slog::join_probe_old<3,3>($seq_atrindex651, $seq_atrdelta657, std::array<u64,3>{v_c176, v_c179, v_c157}, [&](const std::array<u64,3>& m684) {
            if (!slog::exists_probe<2,1>(_enumindex652, std::array<u64,2>{v_c171, 0})) return;
            slog::join_probe<2,1>(_enumindex653, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m685) {
              u64 v_c180 = m685[1];
              slog::join_probe_old<2,2>(boolvalindex654, boolvaldelta658, std::array<u64,2>{v_c179, v_c180}, [&](const std::array<u64,2>& m686) {
                slog::join_probe<2,1>(_enumindex655, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m687) {
                  u64 v_c181 = m687[1];
                  u64 v_c182 = _prim_llen(db, v_c178);
                  if (v_c182 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                  if (v_c173 != v_c182) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c177});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c181}, std::array<u16,2>{1, 0});
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
        ReadTask659* _cont = new ReadTask659(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask659(db,b), false);
  // (crule (pre (let _00024sqc4Fzm988 constd4735e3a265e16eee03f5971) (let _00024sqc6SKj989 const5feceb66ffc86f38d952786c) (let _00024sqc8JKk990 const6b86b273ff34fce19d6b804e) (let _00024sqc2Wqs993 const6b86b273ff34fce19d6b804e) (let _00024sqc3gqm994 const5feceb66ffc86f38d952786c) (let _00024sqc5u0R995 const6b86b273ff34fce19d6b804e) (let _00024sqc2qd4996 const5feceb66ffc86f38d952786c) (let _00024sqo0rW61001 const5feceb66ffc86f38d952786c)) (scan mp_put __t5IsX765 __v0 k v) (body (exists mp_put_ans (0 1) 1 __t5IsX765) (exists $sup5638x127x0x0x0 (3 4 5 0 1 2) 2 k v) (exists $seq_at (1 0 2) 1 _00024sqo0rW61001) (join mp_fromlist_ans (1 0) 1 __v0 __t3r8n764) (join mp_put_ans (0 1) 1 __t5IsX765 __v1) (join mp_fromlist (0 1) 1 __t3r8n764 xs) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 3 k v xs _00024seq0 _00024seq1 __t1Wom763) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0rW61001 _00024seq0 _00024seq1) (join mp_fromlist (0 1) 2 __t1Wom763 _00024seq1) (letp _00024sql4o7j991 (aslst _00024seq1)) (let _00024sqn095f992 (llen _00024sql4o7j991)) (cmp ge _00024sqn095f992 _00024sqc2Wqs993) (letp _00024sql7g5s986 (aslst _00024seq0)) (let chk4cwM1884 (llen _00024sql7g5s986)) (eq _00024sqc4Fzm988 chk4cwM1884) (letp chk36kG1885 (lref _00024sql7g5s986 _00024sqc6SKj989)) (eq k chk36kG1885) (letp chk8GoU1886 (lref _00024sql7g5s986 _00024sqc8JKk990)) (eq v chk8GoU1886) (letp chk2HTM1887 (lref _00024sql4o7j991 _00024sqc3gqm994)) (eq _00024seq0 chk2HTM1887) (let _00024sqp3avN997 (_0002d _00024sqn095f992 _00024sqc2qd4996)) (let chk9eLN1888 (lslice _00024sql4o7j991 _00024sqc5u0R995 _00024sqp3avN997)) (eq xs chk9eLN1888)) (head (emit mp_fromlist_ans (1 0) __v1 __t1Wom763)) map.slog:128 #f)
  class ReadTask698 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex688;  slog::Index** $sup5638x127x0x0x0index689;  slog::Index** $seq_atindex690;  slog::Index** mp_fromlist_ansindex691;  slog::Index** mp_put_ansindex692;  slog::Index** mp_fromlistindex693;  slog::Index** $sup5638x127x0x0x0index694;  slog::Index** $seq_atindex695;  slog::Index** mp_fromlistindex696;  slog::Index** $seq_atdelta697;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord699({1, 0});
      slog::Relation* readrel700 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel700->getIndex(ord699, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord701({0, 1});
      slog::Relation* readrel702 = db->getRelation("mp_put_ans");
      mp_put_ansindex688 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel704 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index689 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({1, 0, 2});
      slog::Relation* readrel706 = db->getRelation("$seq_at");
      $seq_atindex690 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 0});
      slog::Relation* readrel708 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex691 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({0, 1});
      slog::Relation* readrel710 = db->getRelation("mp_put_ans");
      mp_put_ansindex692 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("mp_fromlist");
      mp_fromlistindex693 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel714 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index694 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 0, 2});
      slog::Relation* readrel716 = db->getRelation("$seq_at");
      $seq_atindex695 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 0, 2});
      slog::Relation* readrel718 = db->getRelation("$seq_at");
      $seq_atdelta697 = readrel718->getIndex(ord717, true);
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("mp_fromlist");
      mp_fromlistindex696 = readrel720->getIndex(ord719, false);
  
    }
    ReadTask698(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_constd4735e3a265e16eee03f5971;
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
      u64 v_c153 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c154 = v_const5feceb66ffc86f38d952786c;
      u64 v_c155 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c156 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c54 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex688, std::array<u64,2>{v_c156, 0})) return;
        if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index689, std::array<u64,6>{v_c22, v_c54, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex690, std::array<u64,3>{v_c155, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlist_ansindex691, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m721) {
          u64 v_c164 = m721[1];
          slog::join_probe<2,1>(mp_put_ansindex692, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m722) {
            u64 v_c45 = m722[1];
            slog::join_probe<2,1>(mp_fromlistindex693, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m723) {
              u64 v_c65 = m723[1];
              slog::join_probe<6,3>($sup5638x127x0x0x0index694, std::array<u64,6>{v_c22, v_c54, v_c65, 0, 0, 0}, [&](const std::array<u64,6>& m724) {
                u64 v_c34 = m724[3]; u64 v_c157 = m724[4]; u64 v_c158 = m724[5];
                slog::join_probe_old<3,3>($seq_atindex695, $seq_atdelta697, std::array<u64,3>{v_c155, v_c34, v_c157}, [&](const std::array<u64,3>& m725) {
                  slog::join_probe<2,2>(mp_fromlistindex696, std::array<u64,2>{v_c158, v_c157}, [&](const std::array<u64,2>& m726) {
                    bool ok727 = true;
                    u64 v_c160 = _prim_aslst(db, v_c157, &ok727);
                    if (!ok727) return;
                    u64 v_c161 = _prim_llen(db, v_c160);
                    if (v_c161 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c183 = _prim_ge(db, v_c161, v_c151);
                    if (v_c183 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (!v_c183) return;
                    bool ok729 = true;
                    u64 v_c159 = _prim_aslst(db, v_c34, &ok729);
                    if (!ok729) return;
                    u64 v_c184 = _prim_llen(db, v_c159);
                    if (v_c184 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c148 != v_c184) return;
                    bool ok730 = true;
                    u64 v_c185 = _prim_lref(db, v_c159, v_c149, &ok730);
                    if (!ok730) return;
                    if (v_c22 != v_c185) return;
                    bool ok731 = true;
                    u64 v_c186 = _prim_lref(db, v_c159, v_c150, &ok731);
                    if (!ok731) return;
                    if (v_c54 != v_c186) return;
                    bool ok732 = true;
                    u64 v_c187 = _prim_lref(db, v_c160, v_c152, &ok732);
                    if (!ok732) return;
                    if (v_c34 != v_c187) return;
                    u64 v_c163 = _prim__0002d(db, v_c161, v_c154);
                    if (v_c163 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c188 = _prim_lslice(db, v_c160, v_c153, v_c163);
                    if (v_c188 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c65 != v_c188) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c158}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask698* _cont = new ReadTask698(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask698(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mbranch __t5EdF114 p m l r) (body (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 4 l m p r) (exists mp_union (1 2 0) 1 __t5EdF114) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 l) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t2hbE115 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t2hbE115 __t5EdF114) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t2hbE115 n q u v __t27ag118) (exists mp_msk (1 2 0) 3 q m __t27ag118) (exists mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_union (0 1 2) 3 (0 1 2) __t2hbE115 __t5EdF114 __t8CES119) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask755 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index733;  slog::Index** mp_unionindex734;  slog::Index** mp_mskindex735;  slog::Index** mp_msk_ansindex736;  slog::Index** mp_unionindex737;  slog::Index** $sup5638x95x0x0x0index738;  slog::Index** mbranchindex739;  slog::Index** mp_unionindex740;  slog::Index** mp_mskindex741;  slog::Index** $sup5638x95x0x0x1index742;  slog::Index** mp_mskindex743;  slog::Index** mp_msk_ansindex744;  slog::Index** mbranchindex745;  slog::Index** mp_unionindex746;  slog::Index** mp_mskindex747;  slog::Index** mp_msk_ansindex748;  slog::Index** mp_unionindex749;  slog::Index** mp_union_ansindex750;  slog::Index** mbranchdelta751;  slog::Index** mp_uniondelta752;  slog::Index** mp_mskdelta753;  slog::Index** mp_uniondelta754;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord756({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel757 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index733 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("mp_union");
      mp_unionindex734 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({2, 0, 1});
      slog::Relation* readrel761 = db->getRelation("mp_msk");
      mp_mskindex735 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0});
      slog::Relation* readrel763 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex736 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 0});
      slog::Relation* readrel765 = db->getRelation("mp_union");
      mp_unionindex737 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel767 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index738 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 2, 3, 4, 0});
      slog::Relation* readrel769 = db->getRelation("mbranch");
      mbranchindex739 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1, 2});
      slog::Relation* readrel771 = db->getRelation("mp_union");
      mp_unionindex740 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 2, 0});
      slog::Relation* readrel773 = db->getRelation("mp_msk");
      mp_mskindex741 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel775 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index742 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("mp_msk");
      mp_mskindex743 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex744 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 3, 4, 0});
      slog::Relation* readrel781 = db->getRelation("mbranch");
      mbranchindex745 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 3, 4, 0});
      slog::Relation* readrel783 = db->getRelation("mbranch");
      mbranchdelta751 = readrel783->getIndex(ord782, true);
      std::vector<u16> ord784({0, 1, 2});
      slog::Relation* readrel785 = db->getRelation("mp_union");
      mp_unionindex746 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({0, 1, 2});
      slog::Relation* readrel787 = db->getRelation("mp_union");
      mp_uniondelta752 = readrel787->getIndex(ord786, true);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("mp_msk");
      mp_mskindex747 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("mp_msk");
      mp_mskdelta753 = readrel791->getIndex(ord790, true);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex748 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 0});
      slog::Relation* readrel795 = db->getRelation("mp_union");
      mp_unionindex749 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("mp_union");
      mp_uniondelta754 = readrel797->getIndex(ord796, true);
      std::vector<u16> ord798({0, 1});
      slog::Relation* readrel799 = db->getRelation("mp_union_ans");
      mp_union_ansindex750 = readrel799->getIndex(ord798, false);
  
    }
    ReadTask755(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c25 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c26 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x95x0x0x1index733, std::array<u64,10>{v_c23, v_c24, v_c25, v_c26, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex734, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex735, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex736, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex737, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x95x0x0x0index738, std::array<u64,9>{v_c23, v_c24, v_c25, v_c26, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m800) {
          u64 v_c102 = m800[4]; u64 v_c51 = m800[5]; u64 v_c52 = m800[6]; u64 v_c53 = m800[7]; u64 v_c54 = m800[8];
          u64 v_c189 = _prim_lt(db, v_c51, v_c24);
          if (v_c189 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c189) return;
          if (!slog::exists_probe<5,4>(mbranchindex739, std::array<u64,5>{v_c52, v_c51, v_c53, v_c54, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex740, std::array<u64,3>{v_c102, v_c104, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex741, std::array<u64,3>{v_c52, v_c24, 0})) return;
          slog::join_probe<10,9>($sup5638x95x0x0x1index742, std::array<u64,10>{v_c23, v_c24, v_c25, v_c26, v_c102, v_c51, v_c52, v_c53, v_c54, 0}, [&](const std::array<u64,10>& m802) {
            u64 v_c101 = m802[9];
            if (!slog::exists_probe<3,3>(mp_mskindex743, std::array<u64,3>{v_c52, v_c24, v_c101})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex744, std::array<u64,2>{v_c101, v_c25})) return;
            slog::join_probe_old<5,4>(mbranchindex745, mbranchdelta751, std::array<u64,5>{v_c52, v_c51, v_c53, v_c54, 0}, [&](const std::array<u64,5>& m803) {
              u64 v_c105 = m803[4];
              slog::join_probe_old<3,3>(mp_unionindex746, mp_uniondelta752, std::array<u64,3>{v_c102, v_c104, v_c105}, [&](const std::array<u64,3>& m804) {
                slog::join_probe_old<3,3>(mp_mskindex747, mp_mskdelta753, std::array<u64,3>{v_c52, v_c24, v_c101}, [&](const std::array<u64,3>& m805) {
                  slog::join_probe<2,2>(mp_msk_ansindex748, std::array<u64,2>{v_c101, v_c25}, [&](const std::array<u64,2>& m806) {
                    slog::join_probe_old<3,2>(mp_unionindex749, mp_uniondelta754, std::array<u64,3>{v_c23, v_c105, 0}, [&](const std::array<u64,3>& m807) {
                      u64 v_c106 = m807[2];
                      slog::join_probe<2,1>(mp_union_ansindex750, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m808) {
                        u64 v_c10 = m808[1];
                        u64 v_c107 = _prim_band(db, v_c52, v_c24);
                        if (v_c107 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c190 = _prim_lt(db, v_c107, v_c100);
                        if (v_c190 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c190) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c10, v_c24, v_c25, v_c26});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask755* _cont = new ReadTask755(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask755(db,b), false);
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (scan $sup5638x68x0x0x0 __t94M4525 k t v) (body (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t94M4525) (exists mp_has0 (1 2 0) 2 t k) (exists mp_has0_ans (1 0) 1 __tconst25r1527) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t7U64528) (exists mp_put_ans (0 1) 1 __t7U64528) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t5miQ526) (join mp_has0_ans (0 1) 2 __t5miQ526 __tconst25r1527) (join mp_put_ans (0 1) 1 __t7U64528 r)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask821 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex810;  slog::Index** mp_has0index811;  slog::Index** mp_has0_ansindex812;  slog::Index** mp_putindex813;  slog::Index** mp_put_ansindex814;  slog::Index** mp_has0index815;  slog::Index** mp_has0_ansindex816;  slog::Index** mp_put_ansindex817;  slog::Index** mp_put_softdelta818;  slog::Index** mp_putdelta819;  slog::Index** mp_has0delta820;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel823->getIndex(ord822, false);
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord824({1, 2, 3, 0});
      slog::Relation* readrel825 = db->getRelation("mp_put_soft");
      mp_put_softindex810 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 2, 3, 0});
      slog::Relation* readrel827 = db->getRelation("mp_put_soft");
      mp_put_softdelta818 = readrel827->getIndex(ord826, true);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("mp_has0");
      mp_has0index811 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 0});
      slog::Relation* readrel831 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex812 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 3, 0});
      slog::Relation* readrel833 = db->getRelation("mp_put");
      mp_putindex813 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 3, 0});
      slog::Relation* readrel835 = db->getRelation("mp_put");
      mp_putdelta819 = readrel835->getIndex(ord834, true);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("mp_put_ans");
      mp_put_ansindex814 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("mp_has0");
      mp_has0index815 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 0});
      slog::Relation* readrel841 = db->getRelation("mp_has0");
      mp_has0delta820 = readrel841->getIndex(ord840, true);
      std::vector<u16> ord842({0, 1});
      slog::Relation* readrel843 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex816 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1});
      slog::Relation* readrel845 = db->getRelation("mp_put_ans");
      mp_put_ansindex817 = readrel845->getIndex(ord844, false);
  
    }
    ReadTask821(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c116 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c41 = _t[2];
        u64 v_c54 = _t[3];
        slog::join_probe_old<4,4>(mp_put_softindex810, mp_put_softdelta818, std::array<u64,4>{v_c41, v_c22, v_c54, v_c116}, [&](const std::array<u64,4>& m846) {
          if (!slog::exists_probe<3,2>(mp_has0index811, std::array<u64,3>{v_c41, v_c22, 0})) return;
          if (!slog::exists_probe<2,1>(mp_has0_ansindex812, std::array<u64,2>{v_c114, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex813, mp_putdelta819, std::array<u64,4>{v_c41, v_c22, v_c54, 0}, [&](const std::array<u64,4>& m847) {
            u64 v_c115 = m847[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex814, std::array<u64,2>{v_c115, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index815, mp_has0delta820, std::array<u64,3>{v_c41, v_c22, 0}, [&](const std::array<u64,3>& m848) {
              u64 v_c117 = m848[2];
              slog::join_probe<2,2>(mp_has0_ansindex816, std::array<u64,2>{v_c117, v_c114}, [&](const std::array<u64,2>& m849) {
                slog::join_probe<2,1>(mp_put_ansindex817, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m850) {
                  u64 v_c26 = m850[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c116, v_c26}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask821* _cont = new ReadTask821(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask821(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mp_union __t221b149 __t5mfE148 u) (body (exists mp_union (1 2 0) 1 __t5mfE148) (exists mbranch (3 0 1 2 4) 1 u) (exists $sup5638x104x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join mp_union_ans (0 1) 1 __t221b149 __v0) (join mp_union (1 2 0) 1 __t5mfE148 __t2NO6142 __t0kfV144) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t0kfV144 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t0kfV144 u) (join mbranch (3 0 1 2 4) 2 u __t2NO6142 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t0kfV144) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0kfV144 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t5mfE148) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t0kfV144 l m p r __t7PVf147) (join mbranch (1 2 3 4 0) 5 p m l r __t5mfE148) (join mp_msk (1 2 0) 3 p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask870 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex851;  slog::Index** mbranchindex852;  slog::Index** $sup5638x104x0x0x0index853;  slog::Index** $sup5638x104x0x0x1index854;  slog::Index** mp_union_ansindex855;  slog::Index** mp_unionindex856;  slog::Index** $sup5638x104x0x0x0index857;  slog::Index** $sup5638x104x0x0x1index858;  slog::Index** mbranchindex859;  slog::Index** $sup5638x104x0x0x1index860;  slog::Index** mp_mskindex861;  slog::Index** mp_msk_ansindex862;  slog::Index** $sup5638x104x0x0x0index863;  slog::Index** mbranchindex864;  slog::Index** mp_mskindex865;  slog::Index** $sup5638x104x0x0x1index866;  slog::Index** mbranchindex867;  slog::Index** mp_mskindex868;  slog::Index** mp_msk_ansindex869;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("mp_union");
      mp_unionindex851 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({3, 0, 1, 2, 4});
      slog::Relation* readrel874 = db->getRelation("mbranch");
      mbranchindex852 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel876 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index853 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel878 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index854 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 1});
      slog::Relation* readrel880 = db->getRelation("mp_union_ans");
      mp_union_ansindex855 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 0});
      slog::Relation* readrel882 = db->getRelation("mp_union");
      mp_unionindex856 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel884 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index857 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel886 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index858 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({3, 0, 1, 2, 4});
      slog::Relation* readrel888 = db->getRelation("mbranch");
      mbranchindex859 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel890 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index860 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({2, 0, 1});
      slog::Relation* readrel892 = db->getRelation("mp_msk");
      mp_mskindex861 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 0});
      slog::Relation* readrel894 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex862 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel896 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index863 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({1, 2, 3, 4, 0});
      slog::Relation* readrel898 = db->getRelation("mbranch");
      mbranchindex864 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 2, 0});
      slog::Relation* readrel900 = db->getRelation("mp_msk");
      mp_mskindex865 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel902 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index866 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 3, 4, 0});
      slog::Relation* readrel904 = db->getRelation("mbranch");
      mbranchindex867 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 2, 0});
      slog::Relation* readrel906 = db->getRelation("mp_msk");
      mp_mskindex868 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex869 = readrel908->getIndex(ord907, false);
  
    }
    ReadTask870(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c191 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c192 = _t[0];
        u64 v_c193 = _t[1];
        u64 v_c53 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex851, std::array<u64,3>{v_c193, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex852, std::array<u64,5>{v_c53, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index853, std::array<u64,9>{v_c53, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index854, std::array<u64,10>{v_c53, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex855, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m909) {
          u64 v_c10 = m909[1];
          slog::join_probe<3,1>(mp_unionindex856, std::array<u64,3>{v_c193, 0, 0}, [&](const std::array<u64,3>& m910) {
            u64 v_c194 = m910[1]; u64 v_c195 = m910[2];
            if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index857, std::array<u64,9>{v_c195, v_c53, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index858, std::array<u64,10>{v_c195, v_c53, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex859, std::array<u64,5>{v_c53, v_c194, 0, 0, 0}, [&](const std::array<u64,5>& m911) {
              u64 v_c52 = m911[2]; u64 v_c51 = m911[3]; u64 v_c54 = m911[4];
              if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index860, std::array<u64,10>{v_c53, v_c51, v_c52, v_c54, v_c195, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex861, std::array<u64,3>{v_c51, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex862, std::array<u64,2>{v_c52, 0})) return;
              slog::join_probe<9,5>($sup5638x104x0x0x0index863, std::array<u64,9>{v_c52, v_c51, v_c53, v_c54, v_c195, 0, 0, 0, 0}, [&](const std::array<u64,9>& m912) {
                u64 v_c23 = m912[5]; u64 v_c24 = m912[6]; u64 v_c25 = m912[7]; u64 v_c26 = m912[8];
                u64 v_c196 = _prim_lt(db, v_c24, v_c51);
                if (v_c196 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                if (!v_c196) return;
                if (!slog::exists_probe<5,5>(mbranchindex864, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, v_c193})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex865, std::array<u64,3>{v_c25, v_c51, 0})) return;
                slog::join_probe<10,9>($sup5638x104x0x0x1index866, std::array<u64,10>{v_c53, v_c51, v_c52, v_c54, v_c195, v_c23, v_c24, v_c25, v_c26, 0}, [&](const std::array<u64,10>& m914) {
                  u64 v_c197 = m914[9];
                  slog::join_probe<5,5>(mbranchindex867, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, v_c193}, [&](const std::array<u64,5>& m915) {
                    slog::join_probe<3,3>(mp_mskindex868, std::array<u64,3>{v_c25, v_c51, v_c197}, [&](const std::array<u64,3>& m916) {
                      slog::join_probe<2,2>(mp_msk_ansindex869, std::array<u64,2>{v_c197, v_c52}, [&](const std::array<u64,2>& m917) {
                        u64 v_c198 = _prim_band(db, v_c25, v_c51);
                        if (v_c198 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c199 = _prim_lt(db, v_c198, v_c191);
                        if (v_c199 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c199) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c195, v_c10, v_c51, v_c52, v_c54});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c52, v_c51, v_c10, v_c54}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask870* _cont = new ReadTask870(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask870(db,b), false);
  // (crule (pre (let __tconst1Kzi11 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t7h7513 __t6lgH12 k) (body (join mleaf (0 1 2) 2 __t6lgH12 k v)) (head (emit mp_has0_ans (0 1) __t7h7513 __tconst1Kzi11)) map.slog:58 #f)
  class ReadTask920 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex919;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel922->getIndex(ord921, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord923({0, 1, 2});
      slog::Relation* readrel924 = db->getRelation("mleaf");
      mleafindex919 = readrel924->getIndex(ord923, false);
  
    }
    ReadTask920(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c200 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c201 = _t[0];
        u64 v_c202 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe<3,2>(mleafindex919, std::array<u64,3>{v_c202, v_c22, 0}, [&](const std::array<u64,3>& m925) {
          u64 v_c54 = m925[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c201, v_c200}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:58", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask920* _cont = new ReadTask920(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask920(db,b), false);
  // (crule (pre (let __tconst1Kzi11 const6b86b273ff34fce19d6b804e)) (scan mleaf __t6lgH12 k v) (body (join-old mp_has0 (1 2 0) 2 (1 2 0) __t6lgH12 k __t7h7513)) (head (emit mp_has0_ans (0 1) __t7h7513 __tconst1Kzi11)) map.slog:58 #f)
  class ReadTask928 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index926;  slog::Index** mp_has0delta927;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord929({0, 1});
      slog::Relation* readrel930 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel930->getIndex(ord929, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord931({1, 2, 0});
      slog::Relation* readrel932 = db->getRelation("mp_has0");
      mp_has0index926 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 2, 0});
      slog::Relation* readrel934 = db->getRelation("mp_has0");
      mp_has0delta927 = readrel934->getIndex(ord933, true);
  
    }
    ReadTask928(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c200 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c202 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c54 = _t[2];
        slog::join_probe_old<3,2>(mp_has0index926, mp_has0delta927, std::array<u64,3>{v_c202, v_c22, 0}, [&](const std::array<u64,3>& m935) {
          u64 v_c201 = m935[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c201, v_c200}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:58", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask928* _cont = new ReadTask928(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask928(db,b), false);
  // (crule (pre (let _00024sqc5BuE1031 const6b86b273ff34fce19d6b804e) (let _00024sqc5mgg1032 const5feceb66ffc86f38d952786c) (let _00024sqc3TQh1033 const6b86b273ff34fce19d6b804e) (let _00024sqc0pgC1034 const5feceb66ffc86f38d952786c)) (scan extend_env __t5Tm2606 rho _00024seq0 t) (body (letp _00024sql4VoC1029 (aslst _00024seq0)) (let _00024sqn9IzY1030 (llen _00024sql4VoC1029)) (cmp ge _00024sqn9IzY1030 _00024sqc5BuE1031) (letp x (lref _00024sql4VoC1029 _00024sqc5mgg1032)) (let _00024sqp46PN1035 (_0002d _00024sqn9IzY1030 _00024sqc0pgC1034)) (let xs (lslice _00024sql4VoC1029 _00024sqc3TQh1033 _00024sqp46PN1035))) (head (emit $sup70016x47x0x0x0 (0 4 5 1 2 3) _00024seq0 x xs __t5Tm2606 rho t)) interp.slog:48 #f)
  class ReadTask936 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup70016x47x0x0x0");
      std::vector<u16> ord937({0, 4, 5, 1, 2, 3});
      slog::Relation* readrel938 = db->getRelation("$sup70016x47x0x0x0");
      head_index[0] = readrel938->getIndex(ord937, false);
      outer_rel = db->getRelation("extend_env");
  
    }
    ReadTask936(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c203 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c204 = v_const5feceb66ffc86f38d952786c;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c207 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c41 = _t[3];
        bool ok939 = true;
        u64 v_c208 = _prim_aslst(db, v_c34, &ok939);
        if (!ok939) return;
        u64 v_c209 = _prim_llen(db, v_c208);
        if (v_c209 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c210 = _prim_ge(db, v_c209, v_c203);
        if (v_c210 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        if (!v_c210) return;
        bool ok941 = true;
        u64 v_c12 = _prim_lref(db, v_c208, v_c204, &ok941);
        if (!ok941) return;
        u64 v_c211 = _prim__0002d(db, v_c209, v_c206);
        if (v_c211 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c65 = _prim_lslice(db, v_c208, v_c205, v_c211);
        if (v_c65 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        ++_fires;
        slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c34, v_c12, v_c65, v_c207, v_c40, v_c41}, std::array<u16,6>{0, 4, 5, 1, 2, 3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask936* _cont = new ReadTask936(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask936(db,b), false);
  // (crule (pre (let __tconst6pJx1346 constb9e118781cea1f9fa01462e0) (let __tconst62iD1347 const0122baa3ac55f1b433944eb1) (let __tconst3W5V576 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0LoQ973 const6b86b273ff34fce19d6b804e) (let _00024sqc1LSK974 const5feceb66ffc86f38d952786c) (let _00024sqo9raf975 const5feceb66ffc86f38d952786c) (let _00024sqo4FnC976 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo9raf975 __t9AVR579 _00024seq1) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4FnC976 __t9AVR579 _00024seq1) (exists _enum (1 0) 1 __tconst6pJx1346) (exists _enum (1 0) 1 __tconst62iD1347) (join delta (1 2 0) 2 __tconst3W5V576 _00024seq1 __t9o8A577) (join _enum (1 0) 1 __tconst6pJx1346 __t18UG578) (join boolval (0 1) 2 __t9AVR579 __t18UG578) (join _enum (1 0) 1 __tconst62iD1347 __t2cB8574) (letp _00024sql99sk971 (aslst _00024seq1)) (let chk2D9q2067 (llen _00024sql99sk971)) (eq _00024sqc0LoQ973 chk2D9q2067) (letp chk06Fd2068 (lref _00024sql99sk971 _00024sqc1LSK974)) (eq __t9AVR579 chk06Fd2068)) (head (emit-temp temp7pkd2063 __t9o8A577) (mkstruct boolval (1 0) __t7CgS575 __t2cB8574)) interp.slog:118 #f)
  class ReadTask950 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex942;  slog::Index** _enumindex943;  slog::Index** _enumindex944;  slog::Index** deltaindex945;  slog::Index** _enumindex946;  slog::Index** boolvalindex947;  slog::Index** _enumindex948;  slog::Index** $seq_atrdelta949;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7pkd2063");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord951({1, 0, 2});
      slog::Relation* readrel952 = db->getRelation("$seq_at");
      driver_index = readrel952->getIndex(ord951, true);
      std::vector<u16> ord953({1, 0, 2});
      slog::Relation* readrel954 = db->getRelation("$seq_atr");
      $seq_atrindex942 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 0, 2});
      slog::Relation* readrel956 = db->getRelation("$seq_atr");
      $seq_atrdelta949 = readrel956->getIndex(ord955, true);
      std::vector<u16> ord957({1, 0});
      slog::Relation* readrel958 = db->getRelation("_enum");
      _enumindex943 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("_enum");
      _enumindex944 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("delta");
      deltaindex945 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 0});
      slog::Relation* readrel964 = db->getRelation("_enum");
      _enumindex946 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("boolval");
      boolvalindex947 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 0});
      slog::Relation* readrel968 = db->getRelation("_enum");
      _enumindex948 = readrel968->getIndex(ord967, false);
  
    }
    ReadTask950(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c171 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c172 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c173 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c174 = v_const5feceb66ffc86f38d952786c;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c175, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m969) {
        u64 v_c179 = m969[1];
        u64 v_c157 = m969[2];
        if (buckethash(v_c179) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex942, $seq_atrdelta949, std::array<u64,3>{v_c176, v_c179, v_c157}, [&](const std::array<u64,3>& m970) {
          if (!slog::exists_probe<2,1>(_enumindex943, std::array<u64,2>{v_c170, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex944, std::array<u64,2>{v_c171, 0})) return;
          slog::join_probe<3,2>(deltaindex945, std::array<u64,3>{v_c172, v_c157, 0}, [&](const std::array<u64,3>& m971) {
            u64 v_c177 = m971[2];
            slog::join_probe<2,1>(_enumindex946, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m972) {
              u64 v_c180 = m972[1];
              slog::join_probe<2,2>(boolvalindex947, std::array<u64,2>{v_c179, v_c180}, [&](const std::array<u64,2>& m973) {
                slog::join_probe<2,1>(_enumindex948, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m974) {
                  u64 v_c181 = m974[1];
                  bool ok975 = true;
                  u64 v_c178 = _prim_aslst(db, v_c157, &ok975);
                  if (!ok975) return;
                  u64 v_c212 = _prim_llen(db, v_c178);
                  if (v_c212 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                  if (v_c173 != v_c212) return;
                  bool ok976 = true;
                  u64 v_c213 = _prim_lref(db, v_c178, v_c174, &ok976);
                  if (!ok976) return;
                  if (v_c179 != v_c213) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c177});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c181}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask950* _cont = new ReadTask950(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask950(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mbranch __t3kyC239 p m l r) (body (exists $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 4 l m p r) (exists mp_put (1 2 3 0) 1 __t3kyC239) (exists mp_msk (2 0 1) 1 m) (exists mp_put (1 2 3 0) 1 l) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 4 p l m r __t8K90240 k v) (exists mp_put (0 2 1 3) 4 __t8K90240 k __t3kyC239 v) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t8K90240 k v __t0CZp243) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t8K90240 k __t3kyC239 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0CZp243) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask996 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index977;  slog::Index** mp_putindex978;  slog::Index** mp_mskindex979;  slog::Index** mp_putindex980;  slog::Index** mp_msk_ansindex981;  slog::Index** $sup5638x40x0x0x0index982;  slog::Index** mp_putindex983;  slog::Index** mp_mskindex984;  slog::Index** mp_putindex985;  slog::Index** $sup5638x40x0x0x1index986;  slog::Index** mp_putindex987;  slog::Index** mp_mskindex988;  slog::Index** mp_msk_ansindex989;  slog::Index** mp_putindex990;  slog::Index** mp_msk_ansindex991;  slog::Index** mp_put_ansindex992;  slog::Index** mp_putdelta993;  slog::Index** mp_mskdelta994;  slog::Index** mp_putdelta995;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord997({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel998 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index977 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 2, 3, 0});
      slog::Relation* readrel1000 = db->getRelation("mp_put");
      mp_putindex978 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({2, 0, 1});
      slog::Relation* readrel1002 = db->getRelation("mp_msk");
      mp_mskindex979 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 2, 3, 0});
      slog::Relation* readrel1004 = db->getRelation("mp_put");
      mp_putindex980 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 0});
      slog::Relation* readrel1006 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex981 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1008 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index982 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({0, 2, 1, 3});
      slog::Relation* readrel1010 = db->getRelation("mp_put");
      mp_putindex983 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 0});
      slog::Relation* readrel1012 = db->getRelation("mp_msk");
      mp_mskindex984 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 2, 3, 0});
      slog::Relation* readrel1014 = db->getRelation("mp_put");
      mp_putindex985 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1016 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index986 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({0, 2, 1, 3});
      slog::Relation* readrel1018 = db->getRelation("mp_put");
      mp_putindex987 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({0, 2, 1, 3});
      slog::Relation* readrel1020 = db->getRelation("mp_put");
      mp_putdelta993 = readrel1020->getIndex(ord1019, true);
      std::vector<u16> ord1021({1, 2, 0});
      slog::Relation* readrel1022 = db->getRelation("mp_msk");
      mp_mskindex988 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 0});
      slog::Relation* readrel1024 = db->getRelation("mp_msk");
      mp_mskdelta994 = readrel1024->getIndex(ord1023, true);
      std::vector<u16> ord1025({0, 1});
      slog::Relation* readrel1026 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex989 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 3, 0});
      slog::Relation* readrel1028 = db->getRelation("mp_put");
      mp_putindex990 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 3, 0});
      slog::Relation* readrel1030 = db->getRelation("mp_put");
      mp_putdelta995 = readrel1030->getIndex(ord1029, true);
      std::vector<u16> ord1031({0, 1});
      slog::Relation* readrel1032 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex991 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({0, 1});
      slog::Relation* readrel1034 = db->getRelation("mp_put_ans");
      mp_put_ansindex992 = readrel1034->getIndex(ord1033, false);
  
    }
    ReadTask996(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c214 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c215 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c26 = _t[4];
        if (!slog::exists_probe<8,4>($sup5638x40x0x0x1index977, std::array<u64,8>{v_c23, v_c24, v_c25, v_c26, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex978, std::array<u64,4>{v_c215, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex979, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex980, std::array<u64,4>{v_c23, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex981, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe<7,4>($sup5638x40x0x0x0index982, std::array<u64,7>{v_c25, v_c23, v_c24, v_c26, 0, 0, 0}, [&](const std::array<u64,7>& m1035) {
          u64 v_c216 = m1035[4]; u64 v_c22 = m1035[5]; u64 v_c54 = m1035[6];
          if (!slog::exists_probe<4,4>(mp_putindex983, std::array<u64,4>{v_c216, v_c22, v_c215, v_c54})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex984, std::array<u64,3>{v_c22, v_c24, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex985, std::array<u64,4>{v_c23, v_c22, v_c54, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index986, std::array<u64,8>{v_c23, v_c24, v_c25, v_c26, v_c216, v_c22, v_c54, 0}, [&](const std::array<u64,8>& m1036) {
            u64 v_c217 = m1036[7];
            slog::join_probe_old<4,4>(mp_putindex987, mp_putdelta993, std::array<u64,4>{v_c216, v_c22, v_c215, v_c54}, [&](const std::array<u64,4>& m1037) {
              slog::join_probe_old<3,3>(mp_mskindex988, mp_mskdelta994, std::array<u64,3>{v_c22, v_c24, v_c217}, [&](const std::array<u64,3>& m1038) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex989, std::array<u64,2>{v_c217, v_c25})) return;
                slog::join_probe_old<4,3>(mp_putindex990, mp_putdelta995, std::array<u64,4>{v_c23, v_c22, v_c54, 0}, [&](const std::array<u64,4>& m1039) {
                  u64 v_c218 = m1039[3];
                  slog::join_probe<2,2>(mp_msk_ansindex991, std::array<u64,2>{v_c217, v_c25}, [&](const std::array<u64,2>& m1040) {
                    slog::join_probe<2,1>(mp_put_ansindex992, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1041) {
                      u64 v_c10 = m1041[1];
                      u64 v_c219 = _prim_band(db, v_c22, v_c24);
                      if (v_c219 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c220 = _prim_lt(db, v_c219, v_c214);
                      if (v_c220 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c220) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c216, v_c10, v_c24, v_c25, v_c26});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask996* _cont = new ReadTask996(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask996(db,b), false);
  // (crule (pre (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c) (let __tconst1O2C203 const7297d2085ea0adffc396d546)) (scan temp7x931952 __t8R2f202 __t8cZd192 __t9Ps2210) (body (exists app (2 0 1) 1 __t8R2f202) (exists ref (1 0) 1 __tconst2PAJ212) (exists app (2 0 1) 1 __t8cZd192) (join primref (1 0) 1 __tconst1O2C203 __t0nMB204) (join app (1 2 0) 2 __t0nMB204 __t8R2f202 __t7nIl205) (join ref (1 0) 1 __tconst2PAJ212 __t4x55194) (join app (1 2 0) 2 __t4x55194 __t8cZd192 __t1aBM195)) (head (emit-temp temp7ssb1953 __t1aBM195 __t7nIl205 __t9Ps2210) (mkstruct lambda (1 2 0) __t9JFW211 __t9Ps2210 __t7nIl205)) kcfa.slog:59 #f)
  class ReadTask1050 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1043;  slog::Index** refindex1044;  slog::Index** appindex1045;  slog::Index** primrefindex1046;  slog::Index** appindex1047;  slog::Index** refindex1048;  slog::Index** appindex1049;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7ssb1953");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp7x931952");
      std::vector<u16> ord1051({2, 0, 1});
      slog::Relation* readrel1052 = db->getRelation("app");
      appindex1043 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 0});
      slog::Relation* readrel1054 = db->getRelation("ref");
      refindex1044 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({2, 0, 1});
      slog::Relation* readrel1056 = db->getRelation("app");
      appindex1045 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({1, 0});
      slog::Relation* readrel1058 = db->getRelation("primref");
      primrefindex1046 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 2, 0});
      slog::Relation* readrel1060 = db->getRelation("app");
      appindex1047 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 0});
      slog::Relation* readrel1062 = db->getRelation("ref");
      refindex1048 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 2, 0});
      slog::Relation* readrel1064 = db->getRelation("app");
      appindex1049 = readrel1064->getIndex(ord1063, false);
  
    }
    ReadTask1050(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c221 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c222 = v_const7297d2085ea0adffc396d546;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c223 = _t[0];
        u64 v_c224 = _t[1];
        u64 v_c225 = _t[2];
        if (!slog::exists_probe<3,1>(appindex1043, std::array<u64,3>{v_c223, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1044, std::array<u64,2>{v_c221, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1045, std::array<u64,3>{v_c224, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex1046, std::array<u64,2>{v_c222, 0}, [&](const std::array<u64,2>& m1065) {
          u64 v_c226 = m1065[1];
          slog::join_probe<3,2>(appindex1047, std::array<u64,3>{v_c226, v_c223, 0}, [&](const std::array<u64,3>& m1066) {
            u64 v_c227 = m1066[2];
            slog::join_probe<2,1>(refindex1048, std::array<u64,2>{v_c221, 0}, [&](const std::array<u64,2>& m1067) {
              u64 v_c228 = m1067[1];
              slog::join_probe<3,2>(appindex1049, std::array<u64,3>{v_c228, v_c224, 0}, [&](const std::array<u64,3>& m1068) {
                u64 v_c229 = m1068[2];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c229, v_c227, v_c225});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c225, v_c227}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp7x931952", _fires);
  
      if (!_done)
      {
        ReadTask1050* _cont = new ReadTask1050(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1050(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t8vNz312 p) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_bld (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t8vNz312 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_del (2 0 1) 1 k) (exists mp_bld (1 2 3 4 0) 2 p m) (join-old $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t0iNt308 l r) (exists mp_del (0 2 1) 2 __t0iNt308 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_del (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t62gM307) (join-old mp_del (0 2 1) 3 (0 2 1) __t0iNt308 k __t62gM307) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t8pI6311 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join-old mp_del_ans (0 1) 2 (0 1) __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask1095 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index1069;  slog::Index** mbranchindex1070;  slog::Index** mp_bldindex1071;  slog::Index** mp_mskindex1072;  slog::Index** mbranchindex1073;  slog::Index** mp_delindex1074;  slog::Index** mp_bldindex1075;  slog::Index** $sup5638x82x0x0x0index1076;  slog::Index** mp_delindex1077;  slog::Index** mp_bldindex1078;  slog::Index** mp_delindex1079;  slog::Index** mbranchindex1080;  slog::Index** mp_delindex1081;  slog::Index** mp_bldindex1082;  slog::Index** mp_del_ansindex1083;  slog::Index** mp_bld_ansindex1084;  slog::Index** mp_delindex1085;  slog::Index** mp_del_ansindex1086;  slog::Index** mp_bld_ansindex1087;  slog::Index** mp_mskdelta1088;  slog::Index** $sup5638x82x0x0x0delta1089;  slog::Index** mbranchdelta1090;  slog::Index** mp_deldelta1091;  slog::Index** mp_blddelta1092;  slog::Index** mp_deldelta1093;  slog::Index** mp_del_ansdelta1094;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1096({0, 1});
      slog::Relation* readrel1097 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1097->getIndex(ord1096, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1098({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1099 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1069 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 3, 4, 0});
      slog::Relation* readrel1101 = db->getRelation("mbranch");
      mbranchindex1070 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 2, 3, 4, 0});
      slog::Relation* readrel1103 = db->getRelation("mp_bld");
      mp_bldindex1071 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1, 2});
      slog::Relation* readrel1105 = db->getRelation("mp_msk");
      mp_mskindex1072 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({0, 1, 2});
      slog::Relation* readrel1107 = db->getRelation("mp_msk");
      mp_mskdelta1088 = readrel1107->getIndex(ord1106, true);
      std::vector<u16> ord1108({1, 2, 3, 4, 0});
      slog::Relation* readrel1109 = db->getRelation("mbranch");
      mbranchindex1073 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({2, 0, 1});
      slog::Relation* readrel1111 = db->getRelation("mp_del");
      mp_delindex1074 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 2, 3, 4, 0});
      slog::Relation* readrel1113 = db->getRelation("mp_bld");
      mp_bldindex1075 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1115 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1076 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1117 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta1089 = readrel1117->getIndex(ord1116, true);
      std::vector<u16> ord1118({0, 2, 1});
      slog::Relation* readrel1119 = db->getRelation("mp_del");
      mp_delindex1077 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({2, 1, 4, 0, 3});
      slog::Relation* readrel1121 = db->getRelation("mp_bld");
      mp_bldindex1078 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 2, 0});
      slog::Relation* readrel1123 = db->getRelation("mp_del");
      mp_delindex1079 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 2, 3, 4, 0});
      slog::Relation* readrel1125 = db->getRelation("mbranch");
      mbranchindex1080 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 3, 4, 0});
      slog::Relation* readrel1127 = db->getRelation("mbranch");
      mbranchdelta1090 = readrel1127->getIndex(ord1126, true);
      std::vector<u16> ord1128({0, 2, 1});
      slog::Relation* readrel1129 = db->getRelation("mp_del");
      mp_delindex1081 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({0, 2, 1});
      slog::Relation* readrel1131 = db->getRelation("mp_del");
      mp_deldelta1091 = readrel1131->getIndex(ord1130, true);
      std::vector<u16> ord1132({2, 1, 4, 0, 3});
      slog::Relation* readrel1133 = db->getRelation("mp_bld");
      mp_bldindex1082 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({2, 1, 4, 0, 3});
      slog::Relation* readrel1135 = db->getRelation("mp_bld");
      mp_blddelta1092 = readrel1135->getIndex(ord1134, true);
      std::vector<u16> ord1136({1, 0});
      slog::Relation* readrel1137 = db->getRelation("mp_del_ans");
      mp_del_ansindex1083 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1084 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("mp_del");
      mp_delindex1085 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 2, 0});
      slog::Relation* readrel1143 = db->getRelation("mp_del");
      mp_deldelta1093 = readrel1143->getIndex(ord1142, true);
      std::vector<u16> ord1144({0, 1});
      slog::Relation* readrel1145 = db->getRelation("mp_del_ans");
      mp_del_ansindex1086 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({0, 1});
      slog::Relation* readrel1147 = db->getRelation("mp_del_ans");
      mp_del_ansdelta1094 = readrel1147->getIndex(ord1146, true);
      std::vector<u16> ord1148({0, 1});
      slog::Relation* readrel1149 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1087 = readrel1149->getIndex(ord1148, false);
  
    }
    ReadTask1095(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c230 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c231 = _t[0];
        u64 v_c25 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x82x0x0x0index1069, std::array<u64,6>{v_c25, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1070, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_bldindex1071, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1072, mp_mskdelta1088, std::array<u64,3>{v_c231, 0, 0}, [&](const std::array<u64,3>& m1150) {
          u64 v_c22 = m1150[1]; u64 v_c24 = m1150[2];
          if (!slog::exists_probe<5,2>(mbranchindex1073, std::array<u64,5>{v_c25, v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex1074, std::array<u64,3>{v_c22, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mp_bldindex1075, std::array<u64,5>{v_c25, v_c24, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x82x0x0x0index1076, $sup5638x82x0x0x0delta1089, std::array<u64,6>{v_c22, v_c24, v_c25, 0, 0, 0}, [&](const std::array<u64,6>& m1151) {
            u64 v_c232 = m1151[3]; u64 v_c23 = m1151[4]; u64 v_c26 = m1151[5];
            if (!slog::exists_probe<3,2>(mp_delindex1077, std::array<u64,3>{v_c232, v_c22, 0})) return;
            if (!slog::exists_probe<5,3>(mp_bldindex1078, std::array<u64,5>{v_c24, v_c25, v_c26, 0, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex1079, std::array<u64,3>{v_c23, v_c22, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1080, mbranchdelta1090, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0}, [&](const std::array<u64,5>& m1152) {
              u64 v_c233 = m1152[4];
              slog::join_probe_old<3,3>(mp_delindex1081, mp_deldelta1091, std::array<u64,3>{v_c232, v_c22, v_c233}, [&](const std::array<u64,3>& m1153) {
                slog::join_probe_old<5,3>(mp_bldindex1082, mp_blddelta1092, std::array<u64,5>{v_c24, v_c25, v_c26, 0, 0}, [&](const std::array<u64,5>& m1154) {
                  u64 v_c234 = m1154[3]; u64 v_c10 = m1154[4];
                  if (!slog::exists_probe<2,1>(mp_del_ansindex1083, std::array<u64,2>{v_c10, 0})) return;
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex1084, std::array<u64,2>{v_c234, 0})) return;
                  slog::join_probe_old<3,2>(mp_delindex1085, mp_deldelta1093, std::array<u64,3>{v_c23, v_c22, 0}, [&](const std::array<u64,3>& m1155) {
                    u64 v_c235 = m1155[2];
                    slog::join_probe_old<2,2>(mp_del_ansindex1086, mp_del_ansdelta1094, std::array<u64,2>{v_c235, v_c10}, [&](const std::array<u64,2>& m1156) {
                      slog::join_probe<2,1>(mp_bld_ansindex1087, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1157) {
                        u64 v_c236 = m1157[1];
                        u64 v_c237 = _prim_band(db, v_c22, v_c24);
                        if (v_c237 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c238 = _prim_lt(db, v_c237, v_c230);
                        if (v_c238 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c238) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c232, v_c236}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1095* _cont = new ReadTask1095(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1095(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0) (let __tconst3nKQ305 const06abaa100ecef791ce028c56) (let _00024sqc19MG1022 constd4735e3a265e16eee03f5971) (let _00024sqc5y4j1023 const5feceb66ffc86f38d952786c) (let _00024sqc09of1024 const6b86b273ff34fce19d6b804e) (let _00024sqo41XW1025 const5feceb66ffc86f38d952786c) (let _00024sqo2TL91026 const6b86b273ff34fce19d6b804e) (let _00024sqo4lhI1027 const6b86b273ff34fce19d6b804e) (let _00024sqo7qxI1028 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo41XW1025 v1 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4lhI1027 v1 _00024seq0) (letp _00024sql8r1X1020 (aslst _00024seq0)) (letp v2 (lref _00024sql8r1X1020 _00024sqc09of1024)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2TL91026 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qxI1028 v2 _00024seq0) (exists _enum (1 0) 1 __tconst85Gw1131) (join delta (1 2 0) 2 __tconst3nKQ305 _00024seq0 __t44yZ306) (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (let chk5QVN2054 (llen _00024sql8r1X1020)) (eq _00024sqc19MG1022 chk5QVN2054) (letp chk2QlR2055 (lref _00024sql8r1X1020 _00024sqc5y4j1023)) (eq v1 chk2QlR2055)) (head (emit-temp temp2zCq2052 __t44yZ306) (mkstruct boolval (1 0) __t6gLd304 __t4QRG303)) interp.slog:124 #f)
  class ReadTask1168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex1159;  slog::Index** $seq_atindex1160;  slog::Index** $seq_atrindex1161;  slog::Index** _enumindex1162;  slog::Index** deltaindex1163;  slog::Index** _enumindex1164;  slog::Index** $seq_atrdelta1165;  slog::Index** $seq_atdelta1166;  slog::Index** $seq_atrdelta1167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zCq2052");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1169({1, 0, 2});
      slog::Relation* readrel1170 = db->getRelation("$seq_at");
      driver_index = readrel1170->getIndex(ord1169, true);
      std::vector<u16> ord1171({1, 0, 2});
      slog::Relation* readrel1172 = db->getRelation("$seq_atr");
      $seq_atrindex1159 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({1, 0, 2});
      slog::Relation* readrel1174 = db->getRelation("$seq_atr");
      $seq_atrdelta1165 = readrel1174->getIndex(ord1173, true);
      std::vector<u16> ord1175({1, 0, 2});
      slog::Relation* readrel1176 = db->getRelation("$seq_at");
      $seq_atindex1160 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({1, 0, 2});
      slog::Relation* readrel1178 = db->getRelation("$seq_at");
      $seq_atdelta1166 = readrel1178->getIndex(ord1177, true);
      std::vector<u16> ord1179({1, 0, 2});
      slog::Relation* readrel1180 = db->getRelation("$seq_atr");
      $seq_atrindex1161 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 0, 2});
      slog::Relation* readrel1182 = db->getRelation("$seq_atr");
      $seq_atrdelta1167 = readrel1182->getIndex(ord1181, true);
      std::vector<u16> ord1183({1, 0});
      slog::Relation* readrel1184 = db->getRelation("_enum");
      _enumindex1162 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 2, 0});
      slog::Relation* readrel1186 = db->getRelation("delta");
      deltaindex1163 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({1, 0});
      slog::Relation* readrel1188 = db->getRelation("_enum");
      _enumindex1164 = readrel1188->getIndex(ord1187, false);
  
    }
    ReadTask1168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c239 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c240 = v_const06abaa100ecef791ce028c56;
      u64 v_c241 = v_constd4735e3a265e16eee03f5971;
      u64 v_c242 = v_const5feceb66ffc86f38d952786c;
      u64 v_c243 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
      u64 v_c245 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c247 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c244, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1189) {
        u64 v_c248 = m1189[1];
        u64 v_c34 = m1189[2];
        if (buckethash(v_c248) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex1159, $seq_atrdelta1165, std::array<u64,3>{v_c246, v_c248, v_c34}, [&](const std::array<u64,3>& m1190) {
          bool ok1191 = true;
          u64 v_c249 = _prim_aslst(db, v_c34, &ok1191);
          if (!ok1191) return;
          bool ok1192 = true;
          u64 v_c250 = _prim_lref(db, v_c249, v_c243, &ok1192);
          if (!ok1192) return;
          if (v_c248 == v_c250) return;
          slog::join_probe_old<3,3>($seq_atindex1160, $seq_atdelta1166, std::array<u64,3>{v_c245, v_c250, v_c34}, [&](const std::array<u64,3>& m1193) {
            slog::join_probe_old<3,3>($seq_atrindex1161, $seq_atrdelta1167, std::array<u64,3>{v_c247, v_c250, v_c34}, [&](const std::array<u64,3>& m1194) {
              if (!slog::exists_probe<2,1>(_enumindex1162, std::array<u64,2>{v_c239, 0})) return;
              slog::join_probe<3,2>(deltaindex1163, std::array<u64,3>{v_c240, v_c34, 0}, [&](const std::array<u64,3>& m1195) {
                u64 v_c251 = m1195[2];
                slog::join_probe<2,1>(_enumindex1164, std::array<u64,2>{v_c239, 0}, [&](const std::array<u64,2>& m1196) {
                  u64 v_c252 = m1196[1];
                  u64 v_c253 = _prim_llen(db, v_c249);
                  if (v_c253 == slog_error) { slog::emit_pending_error(db, "interp.slog:124"); return; }
                  if (v_c241 != v_c253) return;
                  bool ok1197 = true;
                  u64 v_c254 = _prim_lref(db, v_c249, v_c242, &ok1197);
                  if (!ok1197) return;
                  if (v_c248 != v_c254) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c251});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c252}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1168* _cont = new ReadTask1168(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1168(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mbranch __t8CES119 q n u v) (body (exists $sup5638x95x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists mp_union (2 0 1) 1 __t8CES119) (exists mp_msk (1 2 0) 1 q) (join $sup5638x95x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t2hbE115 l m p r) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t8CES119 __t2hbE115) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 2 l __t8CES119) (join $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t2hbE115 n q u v __t27ag118) (exists mp_msk (1 2 0) 3 q m __t27ag118) (exists mp_msk_ans (0 1) 2 __t27ag118 p) (join mbranch (1 2 3 4 0) 4 p m l r __t5EdF114) (join mp_union (0 1 2) 3 __t2hbE115 __t5EdF114 __t8CES119) (join mp_msk (1 2 0) 3 q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask1217 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x1index1198;  slog::Index** mp_unionindex1199;  slog::Index** mp_mskindex1200;  slog::Index** $sup5638x95x0x0x0index1201;  slog::Index** mbranchindex1202;  slog::Index** mp_unionindex1203;  slog::Index** mp_mskindex1204;  slog::Index** mp_msk_ansindex1205;  slog::Index** mp_unionindex1206;  slog::Index** $sup5638x95x0x0x1index1207;  slog::Index** mp_mskindex1208;  slog::Index** mp_msk_ansindex1209;  slog::Index** mbranchindex1210;  slog::Index** mp_unionindex1211;  slog::Index** mp_mskindex1212;  slog::Index** mp_msk_ansindex1213;  slog::Index** mp_unionindex1214;  slog::Index** mp_union_ansindex1215;  slog::Index** mp_uniondelta1216;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1218({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel1219 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1198 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({2, 0, 1});
      slog::Relation* readrel1221 = db->getRelation("mp_union");
      mp_unionindex1199 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 0});
      slog::Relation* readrel1223 = db->getRelation("mp_msk");
      mp_mskindex1200 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1225 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index1201 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 2, 3, 4, 0});
      slog::Relation* readrel1227 = db->getRelation("mbranch");
      mbranchindex1202 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({2, 0, 1});
      slog::Relation* readrel1229 = db->getRelation("mp_union");
      mp_unionindex1203 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({1, 2, 0});
      slog::Relation* readrel1231 = db->getRelation("mp_msk");
      mp_mskindex1204 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 0});
      slog::Relation* readrel1233 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1205 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({1, 2, 0});
      slog::Relation* readrel1235 = db->getRelation("mp_union");
      mp_unionindex1206 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1237 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index1207 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({1, 2, 0});
      slog::Relation* readrel1239 = db->getRelation("mp_msk");
      mp_mskindex1208 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({0, 1});
      slog::Relation* readrel1241 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1209 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({1, 2, 3, 4, 0});
      slog::Relation* readrel1243 = db->getRelation("mbranch");
      mbranchindex1210 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({0, 1, 2});
      slog::Relation* readrel1245 = db->getRelation("mp_union");
      mp_unionindex1211 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({1, 2, 0});
      slog::Relation* readrel1247 = db->getRelation("mp_msk");
      mp_mskindex1212 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({0, 1});
      slog::Relation* readrel1249 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1213 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 2, 0});
      slog::Relation* readrel1251 = db->getRelation("mp_union");
      mp_unionindex1214 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({1, 2, 0});
      slog::Relation* readrel1253 = db->getRelation("mp_union");
      mp_uniondelta1216 = readrel1253->getIndex(ord1252, true);
      std::vector<u16> ord1254({0, 1});
      slog::Relation* readrel1255 = db->getRelation("mp_union_ans");
      mp_union_ansindex1215 = readrel1255->getIndex(ord1254, false);
  
    }
    ReadTask1217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c52 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c54 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x95x0x0x1index1198, std::array<u64,10>{v_c51, v_c52, v_c53, v_c54, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1199, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1200, std::array<u64,3>{v_c52, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x95x0x0x0index1201, std::array<u64,9>{v_c51, v_c52, v_c53, v_c54, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1256) {
          u64 v_c102 = m1256[4]; u64 v_c23 = m1256[5]; u64 v_c24 = m1256[6]; u64 v_c25 = m1256[7]; u64 v_c26 = m1256[8];
          u64 v_c255 = _prim_lt(db, v_c51, v_c24);
          if (v_c255 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c255) return;
          if (!slog::exists_probe<5,4>(mbranchindex1202, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1203, std::array<u64,3>{v_c105, v_c102, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex1204, std::array<u64,3>{v_c52, v_c24, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex1205, std::array<u64,2>{v_c25, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1206, std::array<u64,3>{v_c23, v_c105, 0})) return;
          slog::join_probe<10,9>($sup5638x95x0x0x1index1207, std::array<u64,10>{v_c23, v_c24, v_c25, v_c26, v_c102, v_c51, v_c52, v_c53, v_c54, 0}, [&](const std::array<u64,10>& m1258) {
            u64 v_c101 = m1258[9];
            if (!slog::exists_probe<3,3>(mp_mskindex1208, std::array<u64,3>{v_c52, v_c24, v_c101})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex1209, std::array<u64,2>{v_c101, v_c25})) return;
            slog::join_probe<5,4>(mbranchindex1210, std::array<u64,5>{v_c25, v_c24, v_c23, v_c26, 0}, [&](const std::array<u64,5>& m1259) {
              u64 v_c104 = m1259[4];
              slog::join_probe<3,3>(mp_unionindex1211, std::array<u64,3>{v_c102, v_c104, v_c105}, [&](const std::array<u64,3>& m1260) {
                slog::join_probe<3,3>(mp_mskindex1212, std::array<u64,3>{v_c52, v_c24, v_c101}, [&](const std::array<u64,3>& m1261) {
                  slog::join_probe<2,2>(mp_msk_ansindex1213, std::array<u64,2>{v_c101, v_c25}, [&](const std::array<u64,2>& m1262) {
                    slog::join_probe_old<3,2>(mp_unionindex1214, mp_uniondelta1216, std::array<u64,3>{v_c23, v_c105, 0}, [&](const std::array<u64,3>& m1263) {
                      u64 v_c106 = m1263[2];
                      slog::join_probe<2,1>(mp_union_ansindex1215, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m1264) {
                        u64 v_c10 = m1264[1];
                        u64 v_c107 = _prim_band(db, v_c52, v_c24);
                        if (v_c107 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c256 = _prim_lt(db, v_c107, v_c100);
                        if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c256) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c10, v_c24, v_c25, v_c26});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c25, v_c24, v_c10, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst0SLc45 const06abaa100ecef791ce028c56) (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst9TOB66 const955cca1ceba45052d85984d3) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst2wMu75 const798640599597df7a8daa32b1) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst4buE86 constd4735e3a265e16eee03f5971) (let __tconst2aC790 const6b86b273ff34fce19d6b804e) (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp5W9V1981 __t9eMP91) (body (exists sym (1 0) 1 __tconst2wMu75) (exists ref (1 0) 1 __tconst5MNq94) (exists sym (1 0) 1 __tconst9TOB66) (exists ref (1 0) 1 __tconst56qw82) (exists ref (1 0) 1 __tconst6c7T73) (exists num (1 0) 1 __tconst5MNq94) (exists primref (1 0) 1 __tconst0SLc45) (exists ref (1 0) 1 __tconst7dEi64) (exists ref (1 0) 1 __tconst2JmK55) (join ref (1 0) 1 __tconst2aC790 __t6rYz85) (join sym (1 0) 1 __tconst2wMu75 __t5BQT76) (join ref (1 0) 1 __tconst5MNq94 __t0g1Q71) (join sym (1 0) 1 __tconst9TOB66 __t8BGj67) (join ref (1 0) 1 __tconst56qw82 __t7Sy862) (join ref (1 0) 1 __tconst6c7T73 __t5Ugf53) (join num (1 0) 1 __tconst5MNq94 __t7V3849) (join primref (1 0) 1 __tconst0SLc45 __t0d6446) (join ref (1 0) 1 __tconst7dEi64 __t5HCy41) (join ref (1 0) 1 __tconst2JmK55 __t4U6j39) (let __t8Wlt43 (lpush __t9eMP91 __t5HCy41)) (let __t5wMp60 (lpush __t9eMP91 __t7V3849)) (let __t1uVZ69 (lpush __t9eMP91 __t8BGj67)) (let __t1Qwq78 (lpush __t9eMP91 __t5BQT76)) (let __t7j3b88 (lpush __t9eMP91 __tconst4buE86)) (let __t8XJL92 (lpush __t9eMP91 __tconst2aC790))) (head (emit-temp temp5u3V1982 __t1Qwq78 __t1uVZ69 __t5wMp60 __t7j3b88 __t8Wlt43 __t8XJL92)) kcfa.slog:16 #f)
  class ReadTask1285 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex1266;  slog::Index** refindex1267;  slog::Index** symindex1268;  slog::Index** refindex1269;  slog::Index** refindex1270;  slog::Index** numindex1271;  slog::Index** primrefindex1272;  slog::Index** refindex1273;  slog::Index** refindex1274;  slog::Index** refindex1275;  slog::Index** symindex1276;  slog::Index** refindex1277;  slog::Index** symindex1278;  slog::Index** refindex1279;  slog::Index** refindex1280;  slog::Index** numindex1281;  slog::Index** primrefindex1282;  slog::Index** refindex1283;  slog::Index** refindex1284;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5u3V1982");
      outer_rel = db->getRelation("temp5W9V1981");
      std::vector<u16> ord1286({1, 0});
      slog::Relation* readrel1287 = db->getRelation("sym");
      symindex1266 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({1, 0});
      slog::Relation* readrel1289 = db->getRelation("ref");
      refindex1267 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 0});
      slog::Relation* readrel1291 = db->getRelation("sym");
      symindex1268 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({1, 0});
      slog::Relation* readrel1293 = db->getRelation("ref");
      refindex1269 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({1, 0});
      slog::Relation* readrel1295 = db->getRelation("ref");
      refindex1270 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({1, 0});
      slog::Relation* readrel1297 = db->getRelation("num");
      numindex1271 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 0});
      slog::Relation* readrel1299 = db->getRelation("primref");
      primrefindex1272 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({1, 0});
      slog::Relation* readrel1301 = db->getRelation("ref");
      refindex1273 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({1, 0});
      slog::Relation* readrel1303 = db->getRelation("ref");
      refindex1274 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({1, 0});
      slog::Relation* readrel1305 = db->getRelation("ref");
      refindex1275 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({1, 0});
      slog::Relation* readrel1307 = db->getRelation("sym");
      symindex1276 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({1, 0});
      slog::Relation* readrel1309 = db->getRelation("ref");
      refindex1277 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({1, 0});
      slog::Relation* readrel1311 = db->getRelation("sym");
      symindex1278 = readrel1311->getIndex(ord1310, false);
      std::vector<u16> ord1312({1, 0});
      slog::Relation* readrel1313 = db->getRelation("ref");
      refindex1279 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 0});
      slog::Relation* readrel1315 = db->getRelation("ref");
      refindex1280 = readrel1315->getIndex(ord1314, false);
      std::vector<u16> ord1316({1, 0});
      slog::Relation* readrel1317 = db->getRelation("num");
      numindex1281 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({1, 0});
      slog::Relation* readrel1319 = db->getRelation("primref");
      primrefindex1282 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 0});
      slog::Relation* readrel1321 = db->getRelation("ref");
      refindex1283 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({1, 0});
      slog::Relation* readrel1323 = db->getRelation("ref");
      refindex1284 = readrel1323->getIndex(ord1322, false);
  
    }
    ReadTask1285(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c257 = v_const06abaa100ecef791ce028c56;
      u64 v_c258 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c259 = v_constef2d127de37b942baad06145;
      u64 v_c260 = v_const955cca1ceba45052d85984d3;
      u64 v_c261 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c262 = v_const798640599597df7a8daa32b1;
      u64 v_c263 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c264 = v_constd4735e3a265e16eee03f5971;
      u64 v_c265 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c266 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c267 = _t[0];
        if (!slog::exists_probe<2,1>(symindex1266, std::array<u64,2>{v_c262, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1267, std::array<u64,2>{v_c266, 0})) return;
        if (!slog::exists_probe<2,1>(symindex1268, std::array<u64,2>{v_c260, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1269, std::array<u64,2>{v_c263, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1270, std::array<u64,2>{v_c261, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1271, std::array<u64,2>{v_c266, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1272, std::array<u64,2>{v_c257, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1273, std::array<u64,2>{v_c259, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1274, std::array<u64,2>{v_c258, 0})) return;
        slog::join_probe<2,1>(refindex1275, std::array<u64,2>{v_c265, 0}, [&](const std::array<u64,2>& m1324) {
          u64 v_c268 = m1324[1];
          slog::join_probe<2,1>(symindex1276, std::array<u64,2>{v_c262, 0}, [&](const std::array<u64,2>& m1325) {
            u64 v_c269 = m1325[1];
            slog::join_probe<2,1>(refindex1277, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1326) {
              u64 v_c270 = m1326[1];
              slog::join_probe<2,1>(symindex1278, std::array<u64,2>{v_c260, 0}, [&](const std::array<u64,2>& m1327) {
                u64 v_c271 = m1327[1];
                slog::join_probe<2,1>(refindex1279, std::array<u64,2>{v_c263, 0}, [&](const std::array<u64,2>& m1328) {
                  u64 v_c272 = m1328[1];
                  slog::join_probe<2,1>(refindex1280, std::array<u64,2>{v_c261, 0}, [&](const std::array<u64,2>& m1329) {
                    u64 v_c273 = m1329[1];
                    slog::join_probe<2,1>(numindex1281, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1330) {
                      u64 v_c274 = m1330[1];
                      slog::join_probe<2,1>(primrefindex1282, std::array<u64,2>{v_c257, 0}, [&](const std::array<u64,2>& m1331) {
                        u64 v_c275 = m1331[1];
                        slog::join_probe<2,1>(refindex1283, std::array<u64,2>{v_c259, 0}, [&](const std::array<u64,2>& m1332) {
                          u64 v_c276 = m1332[1];
                          slog::join_probe<2,1>(refindex1284, std::array<u64,2>{v_c258, 0}, [&](const std::array<u64,2>& m1333) {
                            u64 v_c277 = m1333[1];
                            u64 v_c278 = _prim_lpush(db, v_c267, v_c276);
                            if (v_c278 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            u64 v_c279 = _prim_lpush(db, v_c267, v_c274);
                            if (v_c279 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            u64 v_c280 = _prim_lpush(db, v_c267, v_c271);
                            if (v_c280 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            u64 v_c281 = _prim_lpush(db, v_c267, v_c269);
                            if (v_c281 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            u64 v_c282 = _prim_lpush(db, v_c267, v_c264);
                            if (v_c282 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            u64 v_c283 = _prim_lpush(db, v_c267, v_c265);
                            if (v_c283 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return; }
                            ++_fires;
                            slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c281, v_c280, v_c279, v_c282, v_c278, v_c283});
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
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp5W9V1981", _fires);
  
      if (!_done)
      {
        ReadTask1285* _cont = new ReadTask1285(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1285(db,b), false);
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan $sup70016x43x0x0x0 _00024seq0 __t7ZV0794 e es rho t) (body (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t7ZV0794 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2y2x951 e _00024seq0) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) e rho t __t7vCW795) (exists eval_ans (0 1) 1 __t7vCW795) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t9m2L796) (exists eval_args_ans (0 1) 1 __t9m2L796) (join eval_ans (0 1) 1 __t7vCW795 __v0) (join eval_args_ans (0 1) 1 __t9m2L796 __v1) (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (letp chk9FuM2038 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk9FuM2038) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let chk52Sh2039 (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (eq es chk52Sh2039)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask1347 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1334;  slog::Index** $seq_atindex1335;  slog::Index** eval_argsindex1336;  slog::Index** evalindex1337;  slog::Index** eval_ansindex1338;  slog::Index** eval_argsindex1339;  slog::Index** eval_args_ansindex1340;  slog::Index** eval_ansindex1341;  slog::Index** eval_args_ansindex1342;  slog::Index** eval_argsdelta1343;  slog::Index** $seq_atdelta1344;  slog::Index** evaldelta1345;  slog::Index** eval_argsdelta1346;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("$sup70016x43x0x0x0");
      std::vector<u16> ord1348({3, 2, 0, 1});
      slog::Relation* readrel1349 = db->getRelation("eval_args");
      eval_argsindex1334 = readrel1349->getIndex(ord1348, false);
      std::vector<u16> ord1350({3, 2, 0, 1});
      slog::Relation* readrel1351 = db->getRelation("eval_args");
      eval_argsdelta1343 = readrel1351->getIndex(ord1350, true);
      std::vector<u16> ord1352({1, 0, 2});
      slog::Relation* readrel1353 = db->getRelation("$seq_at");
      $seq_atindex1335 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 0, 2});
      slog::Relation* readrel1355 = db->getRelation("$seq_at");
      $seq_atdelta1344 = readrel1355->getIndex(ord1354, true);
      std::vector<u16> ord1356({1, 3, 2, 0});
      slog::Relation* readrel1357 = db->getRelation("eval_args");
      eval_argsindex1336 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({1, 2, 3, 0});
      slog::Relation* readrel1359 = db->getRelation("eval");
      evalindex1337 = readrel1359->getIndex(ord1358, false);
      std::vector<u16> ord1360({1, 2, 3, 0});
      slog::Relation* readrel1361 = db->getRelation("eval");
      evaldelta1345 = readrel1361->getIndex(ord1360, true);
      std::vector<u16> ord1362({0, 1});
      slog::Relation* readrel1363 = db->getRelation("eval_ans");
      eval_ansindex1338 = readrel1363->getIndex(ord1362, false);
      std::vector<u16> ord1364({1, 3, 2, 0});
      slog::Relation* readrel1365 = db->getRelation("eval_args");
      eval_argsindex1339 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({1, 3, 2, 0});
      slog::Relation* readrel1367 = db->getRelation("eval_args");
      eval_argsdelta1346 = readrel1367->getIndex(ord1366, true);
      std::vector<u16> ord1368({0, 1});
      slog::Relation* readrel1369 = db->getRelation("eval_args_ans");
      eval_args_ansindex1340 = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({0, 1});
      slog::Relation* readrel1371 = db->getRelation("eval_ans");
      eval_ansindex1341 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({0, 1});
      slog::Relation* readrel1373 = db->getRelation("eval_args_ans");
      eval_args_ansindex1342 = readrel1373->getIndex(ord1372, false);
  
    }
    ReadTask1347(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = _prim_lempty(db);
      if (v_c32 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c39 = _t[3];
        u64 v_c40 = _t[4];
        u64 v_c41 = _t[5];
        slog::join_probe_old<4,4>(eval_argsindex1334, eval_argsdelta1343, std::array<u64,4>{v_c41, v_c40, v_c42, v_c34}, [&](const std::array<u64,4>& m1374) {
          slog::join_probe_old<3,3>($seq_atindex1335, $seq_atdelta1344, std::array<u64,3>{v_c31, v_c33, v_c34}, [&](const std::array<u64,3>& m1375) {
            if (!slog::exists_probe<4,3>(eval_argsindex1336, std::array<u64,4>{v_c39, v_c41, v_c40, 0})) return;
            slog::join_probe_old<4,3>(evalindex1337, evaldelta1345, std::array<u64,4>{v_c33, v_c40, v_c41, 0}, [&](const std::array<u64,4>& m1376) {
              u64 v_c43 = m1376[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1338, std::array<u64,2>{v_c43, 0})) return;
              slog::join_probe_old<4,3>(eval_argsindex1339, eval_argsdelta1346, std::array<u64,4>{v_c39, v_c41, v_c40, 0}, [&](const std::array<u64,4>& m1377) {
                u64 v_c44 = m1377[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1340, std::array<u64,2>{v_c44, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1341, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m1378) {
                  u64 v_c10 = m1378[1];
                  slog::join_probe<2,1>(eval_args_ansindex1342, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m1379) {
                    u64 v_c45 = m1379[1];
                    bool ok1380 = true;
                    u64 v_c35 = _prim_aslst(db, v_c34, &ok1380);
                    if (!ok1380) return;
                    u64 v_c36 = _prim_llen(db, v_c35);
                    if (v_c36 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c284 = _prim_ge(db, v_c36, v_c27);
                    if (v_c284 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (!v_c284) return;
                    bool ok1382 = true;
                    u64 v_c285 = _prim_lref(db, v_c35, v_c28, &ok1382);
                    if (!ok1382) return;
                    if (v_c33 != v_c285) return;
                    u64 v_c38 = _prim__0002d(db, v_c36, v_c30);
                    if (v_c38 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c286 = _prim_lslice(db, v_c35, v_c29, v_c38);
                    if (v_c286 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (v_c39 != v_c286) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c32, v_c42, v_c10, v_c45});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:$sup70016x43x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1347* _cont = new ReadTask1347(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1347(db,b), false);
}

