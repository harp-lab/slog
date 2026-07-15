
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const07d7fbed0aba019c07f7eb8a;
extern u64 v_const11445e6556bc59ce1e80cdf7;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_constaa218622af4adb846b2d6244;
extern u64 v_constb177cd86b4c517da8099d6e4;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc742e02805b99df617265a41;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd9f3167b950244706dc6dbb2;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste711e3685c3e87fc5763620f;
extern u64 v_constfc04a7193b8b865723e61851;
extern u64 v_constfdb0a95399e17c48d6f65653;


void slog_rules_c859e7a5b23266fd0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan eval_args __t9m2L796 es rho t) (body (exists eval_args (3 2 0 1) 2 t rho) (exists $seq_at (1 0 2) 1 _00024sqo2y2x951) (exists eval (2 3 0 1) 2 rho t) (exists eval_args_ans (0 1) 1 __t9m2L796) (join $sup70016x43x0x0x0 (3 4 5 0 1 2) 3 es rho t _00024seq0 __t7ZV0794 e) (join eval_args (3 2 0 1) 4 t rho __t7ZV0794 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2y2x951 e _00024seq0) (join eval (1 2 3 0) 3 e rho t __t7vCW795) (join eval_ans (0 1) 1 __t7vCW795 __v0) (join eval_args_ans (0 1) 1 __t9m2L796 __v1) (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (letp chk9oVj2042 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk9oVj2042) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let chk1j3S2043 (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (eq es chk1j3S2043)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex0;  slog::Index** $seq_atindex1;  slog::Index** evalindex2;  slog::Index** eval_args_ansindex3;  slog::Index** $sup70016x43x0x0x0index4;  slog::Index** eval_argsindex5;  slog::Index** $seq_atindex6;  slog::Index** evalindex7;  slog::Index** eval_ansindex8;  slog::Index** eval_args_ansindex9;  slog::Index** $seq_atdelta10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord12({3, 2, 0, 1});
      slog::Relation* readrel13 = db->getRelation("eval_args");
      eval_argsindex0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0, 2});
      slog::Relation* readrel15 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 3, 0, 1});
      slog::Relation* readrel17 = db->getRelation("eval");
      evalindex2 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("eval_args_ans");
      eval_args_ansindex3 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel21 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index4 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({3, 2, 0, 1});
      slog::Relation* readrel23 = db->getRelation("eval_args");
      eval_argsindex5 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0, 2});
      slog::Relation* readrel25 = db->getRelation("$seq_at");
      $seq_atindex6 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0, 2});
      slog::Relation* readrel27 = db->getRelation("$seq_at");
      $seq_atdelta10 = readrel27->getIndex(ord26, true);
      std::vector<u16> ord28({1, 2, 3, 0});
      slog::Relation* readrel29 = db->getRelation("eval");
      evalindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("eval_ans");
      eval_ansindex8 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("eval_args_ans");
      eval_args_ansindex9 = readrel33->getIndex(ord32, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = _prim_lempty(db);
      if (v_c5 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        if (!slog::exists_probe<4,2>(eval_argsindex0, std::array<u64,4>{v_c9, v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex1, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex2, std::array<u64,4>{v_c8, v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex3, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<6,3>($sup70016x43x0x0x0index4, std::array<u64,6>{v_c7, v_c8, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m34) {
          u64 v_c10 = m34[3]; u64 v_c11 = m34[4]; u64 v_c12 = m34[5];
          slog::join_probe<4,4>(eval_argsindex5, std::array<u64,4>{v_c9, v_c8, v_c11, v_c10}, [&](const std::array<u64,4>& m35) {
            slog::join_probe_old<3,3>($seq_atindex6, $seq_atdelta10, std::array<u64,3>{v_c4, v_c12, v_c10}, [&](const std::array<u64,3>& m36) {
              slog::join_probe<4,3>(evalindex7, std::array<u64,4>{v_c12, v_c8, v_c9, 0}, [&](const std::array<u64,4>& m37) {
                u64 v_c13 = m37[3];
                slog::join_probe<2,1>(eval_ansindex8, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m38) {
                  u64 v_c14 = m38[1];
                  slog::join_probe<2,1>(eval_args_ansindex9, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m39) {
                    u64 v_c15 = m39[1];
                    bool ok40 = true;
                    u64 v_c16 = _prim_aslst(db, v_c10, &ok40);
                    if (!ok40) return;
                    u64 v_c17 = _prim_llen(db, v_c16);
                    if (v_c17 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c18 = _prim_ge(db, v_c17, v_c0);
                    if (v_c18 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (!v_c18) return;
                    bool ok42 = true;
                    u64 v_c19 = _prim_lref(db, v_c16, v_c1, &ok42);
                    if (!ok42) return;
                    if (v_c12 != v_c19) return;
                    u64 v_c20 = _prim__0002d(db, v_c17, v_c3);
                    if (v_c20 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c21 = _prim_lslice(db, v_c16, v_c2, v_c20);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (v_c7 != v_c21) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c5, v_c11, v_c14, v_c15});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval_args", _fires);
  
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
  // (crule (pre (let __tconst2EWQ349 const6b86b273ff34fce19d6b804e)) (scan $sup5638x51x0x0x0 __t50Md348 k l m p r) (body (exists mp_get (0 2 1) 2 __t50Md348 k) (exists mp_get (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5IXI347) (join-old mp_get (0 2 1) 3 (0 2 1) __t50Md348 k __t5IXI347) (join-old mp_get (1 2 0) 2 (1 2 0) l k __t7Zfl351) (join mp_get_ans (0 1) 1 __t7Zfl351 v) (let __t51z6350 (band k m)) (cmp lt __t51z6350 __tconst2EWQ349)) (head (emit mp_get_ans (0 1) __t50Md348 v)) map.slog:52 #f)
  class ReadTask52 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex43;  slog::Index** mp_getindex44;  slog::Index** mbranchindex45;  slog::Index** mp_getindex46;  slog::Index** mp_getindex47;  slog::Index** mp_get_ansindex48;  slog::Index** mbranchdelta49;  slog::Index** mp_getdelta50;  slog::Index** mp_getdelta51;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("mp_get_ans");
      head_index[0] = readrel54->getIndex(ord53, false);
      outer_rel = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord55({0, 2, 1});
      slog::Relation* readrel56 = db->getRelation("mp_get");
      mp_getindex43 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 0});
      slog::Relation* readrel58 = db->getRelation("mp_get");
      mp_getindex44 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 3, 4, 0});
      slog::Relation* readrel60 = db->getRelation("mbranch");
      mbranchindex45 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 3, 4, 0});
      slog::Relation* readrel62 = db->getRelation("mbranch");
      mbranchdelta49 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 2, 1});
      slog::Relation* readrel64 = db->getRelation("mp_get");
      mp_getindex46 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 2, 1});
      slog::Relation* readrel66 = db->getRelation("mp_get");
      mp_getdelta50 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("mp_get");
      mp_getindex47 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("mp_get");
      mp_getdelta51 = readrel70->getIndex(ord69, true);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("mp_get_ans");
      mp_get_ansindex48 = readrel72->getIndex(ord71, false);
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c28 = _t[5];
        if (!slog::exists_probe<3,2>(mp_getindex43, std::array<u64,3>{v_c23, v_c24, 0})) return;
        if (!slog::exists_probe<3,2>(mp_getindex44, std::array<u64,3>{v_c25, v_c24, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex45, mbranchdelta49, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0}, [&](const std::array<u64,5>& m73) {
          u64 v_c29 = m73[4];
          slog::join_probe_old<3,3>(mp_getindex46, mp_getdelta50, std::array<u64,3>{v_c23, v_c24, v_c29}, [&](const std::array<u64,3>& m74) {
            slog::join_probe_old<3,2>(mp_getindex47, mp_getdelta51, std::array<u64,3>{v_c25, v_c24, 0}, [&](const std::array<u64,3>& m75) {
              u64 v_c30 = m75[2];
              slog::join_probe<2,1>(mp_get_ansindex48, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m76) {
                u64 v_c31 = m76[1];
                u64 v_c32 = _prim_band(db, v_c24, v_c26);
                if (v_c32 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c33 = _prim_lt(db, v_c32, v_c22);
                if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c33) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c31}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:$sup5638x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask52* _cont = new ReadTask52(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), false);
  // (crule (pre) (scan delta __t9Mk1341 op vs) (body (exists delta_ans (0 1) 1 __t9Mk1341) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t24hv340) (join delta_ans (0 1) 1 __t9Mk1341 v) (join prim (1 0) 1 op __t1N6L339) (join eval_ans (1 0) 1 __t1N6L339 __t8KmI338) (join eval (0 1 2 3) 1 __t8KmI338 ef rho t) (exists $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (join eval_args (3 2 0 1) 3 t rho __t24hv340 es) (exists app (1 2 0) 2 ef es) (join $sup70016x75x0x0x0 (1 3 4 2 0) 4 ef rho t es __t8Dhb337) (join eval (2 3 0 1) 3 rho t __t8Dhb337 __t87KU336) (join app (0 1 2) 3 __t87KU336 ef es)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask93 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** delta_ansindex78;  slog::Index** primindex79;  slog::Index** eval_args_ansindex80;  slog::Index** delta_ansindex81;  slog::Index** primindex82;  slog::Index** eval_ansindex83;  slog::Index** evalindex84;  slog::Index** $sup70016x75x0x0x0index85;  slog::Index** evalindex86;  slog::Index** appindex87;  slog::Index** eval_argsindex88;  slog::Index** appindex89;  slog::Index** $sup70016x75x0x0x0index90;  slog::Index** evalindex91;  slog::Index** appindex92;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("eval_ans");
      head_index[0] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("delta_ans");
      delta_ansindex78 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("prim");
      primindex79 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("eval_args_ans");
      eval_args_ansindex80 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("delta_ans");
      delta_ansindex81 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("prim");
      primindex82 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("eval_ans");
      eval_ansindex83 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 1, 2, 3});
      slog::Relation* readrel109 = db->getRelation("eval");
      evalindex84 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 3, 4, 2, 0});
      slog::Relation* readrel111 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index85 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({2, 3, 0, 1});
      slog::Relation* readrel113 = db->getRelation("eval");
      evalindex86 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 2, 0});
      slog::Relation* readrel115 = db->getRelation("app");
      appindex87 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({3, 2, 0, 1});
      slog::Relation* readrel117 = db->getRelation("eval_args");
      eval_argsindex88 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("app");
      appindex89 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 3, 4, 2, 0});
      slog::Relation* readrel121 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index90 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({2, 3, 0, 1});
      slog::Relation* readrel123 = db->getRelation("eval");
      evalindex91 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({0, 1, 2});
      slog::Relation* readrel125 = db->getRelation("app");
      appindex92 = readrel125->getIndex(ord124, false);
  
    }
    ReadTask93(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[2];
        if (!slog::exists_probe<2,1>(delta_ansindex78, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(primindex79, std::array<u64,2>{v_c35, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex80, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m126) {
          u64 v_c37 = m126[1];
          slog::join_probe<2,1>(delta_ansindex81, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m127) {
            u64 v_c31 = m127[1];
            slog::join_probe<2,1>(primindex82, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m128) {
              u64 v_c38 = m128[1];
              slog::join_probe<2,1>(eval_ansindex83, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m129) {
                u64 v_c39 = m129[1];
                slog::join_probe<4,1>(evalindex84, std::array<u64,4>{v_c39, 0, 0, 0}, [&](const std::array<u64,4>& m130) {
                  u64 v_c40 = m130[1]; u64 v_c8 = m130[2]; u64 v_c9 = m130[3];
                  if (!slog::exists_probe<5,3>($sup70016x75x0x0x0index85, std::array<u64,5>{v_c40, v_c8, v_c9, 0, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex86, std::array<u64,4>{v_c8, v_c9, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex87, std::array<u64,3>{v_c40, 0, 0})) return;
                  slog::join_probe<4,3>(eval_argsindex88, std::array<u64,4>{v_c9, v_c8, v_c37, 0}, [&](const std::array<u64,4>& m131) {
                    u64 v_c7 = m131[3];
                    if (!slog::exists_probe<3,2>(appindex89, std::array<u64,3>{v_c40, v_c7, 0})) return;
                    slog::join_probe<5,4>($sup70016x75x0x0x0index90, std::array<u64,5>{v_c40, v_c8, v_c9, v_c7, 0}, [&](const std::array<u64,5>& m132) {
                      u64 v_c41 = m132[4];
                      slog::join_probe<4,3>(evalindex91, std::array<u64,4>{v_c8, v_c9, v_c41, 0}, [&](const std::array<u64,4>& m133) {
                        u64 v_c42 = m133[3];
                        slog::join_probe<3,3>(appindex92, std::array<u64,3>{v_c42, v_c40, v_c7}, [&](const std::array<u64,3>& m134) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask93* _cont = new ReadTask93(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask93(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan $sup5638x60x0x0x0 __t6Aa9325 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t6Aa9325 k) (exists mp_has0 (1 2 0) 2 l k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0WBy324) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t6Aa9325 k __t0WBy324) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t81Rn328) (exists mp_has0_ans (0 1) 1 __t81Rn328) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2ONI329) (join mp_msk_ans (0 1) 2 __t2ONI329 p) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index135;  slog::Index** mp_has0index136;  slog::Index** mp_mskindex137;  slog::Index** mp_msk_ansindex138;  slog::Index** mbranchindex139;  slog::Index** mp_has0index140;  slog::Index** mp_has0index141;  slog::Index** mp_has0_ansindex142;  slog::Index** mp_mskindex143;  slog::Index** mp_msk_ansindex144;  slog::Index** mp_has0_ansindex145;  slog::Index** mbranchdelta146;  slog::Index** mp_has0delta147;  slog::Index** mp_has0delta148;  slog::Index** mp_mskdelta149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel152->getIndex(ord151, false);
      outer_rel = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord153({0, 2, 1});
      slog::Relation* readrel154 = db->getRelation("mp_has0");
      mp_has0index135 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("mp_has0");
      mp_has0index136 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("mp_msk");
      mp_mskindex137 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex138 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 3, 4, 0});
      slog::Relation* readrel162 = db->getRelation("mbranch");
      mbranchindex139 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 3, 4, 0});
      slog::Relation* readrel164 = db->getRelation("mbranch");
      mbranchdelta146 = readrel164->getIndex(ord163, true);
      std::vector<u16> ord165({0, 2, 1});
      slog::Relation* readrel166 = db->getRelation("mp_has0");
      mp_has0index140 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 2, 1});
      slog::Relation* readrel168 = db->getRelation("mp_has0");
      mp_has0delta147 = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("mp_has0");
      mp_has0index141 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("mp_has0");
      mp_has0delta148 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex142 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("mp_msk");
      mp_mskindex143 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("mp_msk");
      mp_mskdelta149 = readrel178->getIndex(ord177, true);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex144 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex145 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c28 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index135, std::array<u64,3>{v_c44, v_c24, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index136, std::array<u64,3>{v_c25, v_c24, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex137, std::array<u64,3>{v_c24, v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex138, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex139, mbranchdelta146, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0}, [&](const std::array<u64,5>& m183) {
          u64 v_c45 = m183[4];
          slog::join_probe_old<3,3>(mp_has0index140, mp_has0delta147, std::array<u64,3>{v_c44, v_c24, v_c45}, [&](const std::array<u64,3>& m184) {
            slog::join_probe_old<3,2>(mp_has0index141, mp_has0delta148, std::array<u64,3>{v_c25, v_c24, 0}, [&](const std::array<u64,3>& m185) {
              u64 v_c46 = m185[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex142, std::array<u64,2>{v_c46, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex143, mp_mskdelta149, std::array<u64,3>{v_c24, v_c26, 0}, [&](const std::array<u64,3>& m186) {
                u64 v_c47 = m186[2];
                slog::join_probe<2,2>(mp_msk_ansindex144, std::array<u64,2>{v_c47, v_c27}, [&](const std::array<u64,2>& m187) {
                  slog::join_probe<2,1>(mp_has0_ansindex145, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m188) {
                    u64 v_c48 = m188[1];
                    u64 v_c49 = _prim_band(db, v_c24, v_c26);
                    if (v_c49 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c50 = _prim_lt(db, v_c49, v_c43);
                    if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c50) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c48}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:$sup5638x60x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre) (scan mp_join_ans __t6jFY835 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t6jFY835 k __t5lKq834 p __t6oBk833) (exists mp_put (1 2 3 0) 2 __t6oBk833 k) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 3 k p __t6oBk833) (exists mbranch (0 1 2 3 4) 2 __t6oBk833 p) (exists mp_msk (1 2 0) 1 k) (join-old mleaf (0 1 2) 2 (0 1 2) __t5lKq834 k v) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 4 k p __t6oBk833 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __t6oBk833 k v __t6Fc5832) (join-old $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 5 (1 7 0 6 4 2 3 5) k v __t6Fc5832 __t6oBk833 p l m r) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6oBk833) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join-old mp_msk_ans (0 1) 1 (0 1) __t2nZc836 __v0) (neq p __v0)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask209 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex190;  slog::Index** mp_putindex191;  slog::Index** $sup5638x44x0x0x0index192;  slog::Index** mbranchindex193;  slog::Index** mp_mskindex194;  slog::Index** mleafindex195;  slog::Index** $sup5638x44x0x0x0index196;  slog::Index** mp_putindex197;  slog::Index** $sup5638x44x0x0x0index198;  slog::Index** mbranchindex199;  slog::Index** mp_mskindex200;  slog::Index** mp_msk_ansindex201;  slog::Index** mp_joindelta202;  slog::Index** mleafdelta203;  slog::Index** mp_putdelta204;  slog::Index** $sup5638x44x0x0x0delta205;  slog::Index** mbranchdelta206;  slog::Index** mp_mskdelta207;  slog::Index** mp_msk_ansdelta208;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("mp_put_ans");
      head_index[0] = readrel211->getIndex(ord210, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord212({0, 1, 2, 3, 4});
      slog::Relation* readrel213 = db->getRelation("mp_join");
      mp_joinindex190 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 1, 2, 3, 4});
      slog::Relation* readrel215 = db->getRelation("mp_join");
      mp_joindelta202 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({1, 2, 3, 0});
      slog::Relation* readrel217 = db->getRelation("mp_put");
      mp_putindex191 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel219 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index192 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({0, 1, 2, 3, 4});
      slog::Relation* readrel221 = db->getRelation("mbranch");
      mbranchindex193 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("mp_msk");
      mp_mskindex194 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 1, 2});
      slog::Relation* readrel225 = db->getRelation("mleaf");
      mleafindex195 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({0, 1, 2});
      slog::Relation* readrel227 = db->getRelation("mleaf");
      mleafdelta203 = readrel227->getIndex(ord226, true);
      std::vector<u16> ord228({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel229 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index196 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 3, 0});
      slog::Relation* readrel231 = db->getRelation("mp_put");
      mp_putindex197 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 2, 3, 0});
      slog::Relation* readrel233 = db->getRelation("mp_put");
      mp_putdelta204 = readrel233->getIndex(ord232, true);
      std::vector<u16> ord234({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel235 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index198 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel237 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0delta205 = readrel237->getIndex(ord236, true);
      std::vector<u16> ord238({1, 2, 3, 4, 0});
      slog::Relation* readrel239 = db->getRelation("mbranch");
      mbranchindex199 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 3, 4, 0});
      slog::Relation* readrel241 = db->getRelation("mbranch");
      mbranchdelta206 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("mp_msk");
      mp_mskindex200 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("mp_msk");
      mp_mskdelta207 = readrel245->getIndex(ord244, true);
      std::vector<u16> ord246({0, 1});
      slog::Relation* readrel247 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex201 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta208 = readrel249->getIndex(ord248, true);
  
    }
    ReadTask209(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex190, mp_joindelta202, std::array<u64,5>{v_c51, 0, 0, 0, 0}, [&](const std::array<u64,5>& m250) {
          u64 v_c24 = m250[1]; u64 v_c53 = m250[2]; u64 v_c27 = m250[3]; u64 v_c54 = m250[4];
          if (!slog::exists_probe<4,2>(mp_putindex191, std::array<u64,4>{v_c54, v_c24, 0, 0})) return;
          if (!slog::exists_probe<8,3>($sup5638x44x0x0x0index192, std::array<u64,8>{v_c24, v_c27, v_c54, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex193, std::array<u64,5>{v_c54, v_c27, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex194, std::array<u64,3>{v_c24, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex195, mleafdelta203, std::array<u64,3>{v_c53, v_c24, 0}, [&](const std::array<u64,3>& m251) {
            u64 v_c31 = m251[2];
            if (!slog::exists_probe<8,4>($sup5638x44x0x0x0index196, std::array<u64,8>{v_c24, v_c27, v_c54, v_c31, 0, 0, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex197, mp_putdelta204, std::array<u64,4>{v_c54, v_c24, v_c31, 0}, [&](const std::array<u64,4>& m252) {
              u64 v_c55 = m252[3];
              slog::join_probe_old<8,5>($sup5638x44x0x0x0index198, $sup5638x44x0x0x0delta205, std::array<u64,8>{v_c24, v_c31, v_c55, v_c54, v_c27, 0, 0, 0}, [&](const std::array<u64,8>& m253) {
                u64 v_c25 = m253[5]; u64 v_c26 = m253[6]; u64 v_c28 = m253[7];
                slog::join_probe_old<5,5>(mbranchindex199, mbranchdelta206, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, v_c54}, [&](const std::array<u64,5>& m254) {
                  slog::join_probe_old<3,2>(mp_mskindex200, mp_mskdelta207, std::array<u64,3>{v_c24, v_c26, 0}, [&](const std::array<u64,3>& m255) {
                    u64 v_c56 = m255[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex201, mp_msk_ansdelta208, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m256) {
                      u64 v_c14 = m256[1];
                      if (v_c27 == v_c14) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c52}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask209* _cont = new ReadTask209(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask209(db,b), false);
  // (crule (pre (let __trid8oFI1194 constfc04a7193b8b865723e61851) (let __trel1xz01195 const4a59dbb9cb3129dfcc75170b) (let __tcol1v571196 const5feceb66ffc86f38d952786c) (let __trel3w3E1197 const4a59dbb9cb3129dfcc75170b) (let __tcol3yRD1198 const6b86b273ff34fce19d6b804e) (let __trel1jo41199 const4a59dbb9cb3129dfcc75170b) (let __tcol1yus1200 constd4735e3a265e16eee03f5971)) (scan $sup70016x75x0x0x0 __d0 ef es rho t) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid8oFI1194 __trel1xz01195 __tcol1v571196 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8oFI1194 __trel3w3E1197 __tcol3yRD1198 (1 2 3 4 0)) (tycheck t (accept seq) __trid8oFI1194 __trel1jo41199 __tcol1yus1200 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __4BNv1193 ef rho t)) interp.slog:76 #f)
  class ReadTask270 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid268;  u32 sid257;  u32 sid258;  u32 sid259;  u32 sid260;  u32 sid261;  u32 sid262;  u32 sid267;  u32 sid269;  u32 sid263;  u32 sid264;  u32 sid265;  u32 sid266;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x75x0x0x0");
      sid268 = db->getRelation("_enum")->getStructId();
      sid257 = db->getRelation("app")->getStructId();
      sid258 = db->getRelation("boolean")->getStructId();
      sid259 = db->getRelation("if")->getStructId();
      sid260 = db->getRelation("lambda")->getStructId();
      sid261 = db->getRelation("let")->getStructId();
      sid262 = db->getRelation("letrec")->getStructId();
      sid267 = db->getRelation("mbranch")->getStructId();
      sid269 = db->getRelation("mleaf")->getStructId();
      sid263 = db->getRelation("num")->getStructId();
      sid264 = db->getRelation("primref")->getStructId();
      sid265 = db->getRelation("ref")->getStructId();
      sid266 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask270(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_constfc04a7193b8b865723e61851;
      u64 v_c58 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c62 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c63 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c64 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        ++_fires;
        if (!((is_struct(v_c40) && (decode_struct_id(v_c40) == sid257 || decode_struct_id(v_c40) == sid258 || decode_struct_id(v_c40) == sid259 || decode_struct_id(v_c40) == sid260 || decode_struct_id(v_c40) == sid261 || decode_struct_id(v_c40) == sid262 || decode_struct_id(v_c40) == sid263 || decode_struct_id(v_c40) == sid264 || decode_struct_id(v_c40) == sid265 || decode_struct_id(v_c40) == sid266))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c57, v_c58, v_c59, v_c40}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid267 || decode_struct_id(v_c8) == sid268 || decode_struct_id(v_c8) == sid269))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c60, v_c61, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c57, v_c62, v_c63, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c40, v_c8, v_c9}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:$sup70016x75x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask270* _cont = new ReadTask270(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask270(db,b), false);
  // (crule (pre (let __tconst5HUr775 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t0pir774 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t0pir774 __t4G4F773) (join $sup5638x25x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t0Mwp776 (band p0 __v0)) (cmp lt __t0Mwp776 __tconst5HUr775) (let chk7KeX1833 (bxor p0 p1)) (eq __t4G4F773 chk7KeX1833)) (head (emit $sup5638x25x0x0x1 (1 2 0 3 4 5 6) __t0pir774 __v0 __d0 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex271;  slog::Index** $sup5638x25x0x0x0index272;  slog::Index** mp_hsbdelta273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord275({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel276 = db->getRelation("$sup5638x25x0x0x1");
      head_index[0] = readrel276->getIndex(ord275, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("mp_hsb");
      mp_hsbindex271 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("mp_hsb");
      mp_hsbdelta273 = readrel280->getIndex(ord279, true);
      std::vector<u16> ord281({1, 0, 2, 3, 4});
      slog::Relation* readrel282 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index272 = readrel282->getIndex(ord281, false);
  
    }
    ReadTask274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex271, mp_hsbdelta273, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m283) {
          u64 v_c67 = m283[1];
          slog::join_all<5>($sup5638x25x0x0x0index272, [&](const std::array<u64,5>& m284) {
            u64 v_c68 = m284[0]; u64 v_c64 = m284[1]; u64 v_c69 = m284[2]; u64 v_c70 = m284[3]; u64 v_c71 = m284[4];
            u64 v_c72 = _prim_band(db, v_c68, v_c14);
            if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            u64 v_c73 = _prim_lt(db, v_c72, v_c65);
            if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (!v_c73) return;
            u64 v_c74 = _prim_bxor(db, v_c68, v_c69);
            if (v_c74 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
            if (v_c67 != v_c74) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c66, v_c14, v_c64, v_c68, v_c69, v_c70, v_c71}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask274* _cont = new ReadTask274(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask274(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mbranch __t2NO6142 q n u v) (body (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 4 u n q v) (exists mp_union (2 0 1) 1 __t2NO6142) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 u) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t0kfV144 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t2NO6142 __t0kfV144) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t0kfV144 l m p r __t7PVf147) (exists mp_msk (1 2 0) 3 p n __t7PVf147) (exists mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_union (0 1 2) 3 (0 1 2) __t0kfV144 __t5mfE148 __t2NO6142) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x1index286;  slog::Index** mp_unionindex287;  slog::Index** mp_mskindex288;  slog::Index** mp_msk_ansindex289;  slog::Index** mp_unionindex290;  slog::Index** $sup5638x104x0x0x0index291;  slog::Index** mbranchindex292;  slog::Index** mp_unionindex293;  slog::Index** mp_mskindex294;  slog::Index** $sup5638x104x0x0x1index295;  slog::Index** mp_mskindex296;  slog::Index** mp_msk_ansindex297;  slog::Index** mbranchindex298;  slog::Index** mp_unionindex299;  slog::Index** mp_mskindex300;  slog::Index** mp_msk_ansindex301;  slog::Index** mp_unionindex302;  slog::Index** mp_union_ansindex303;  slog::Index** mbranchdelta304;  slog::Index** mp_uniondelta305;  slog::Index** mp_mskdelta306;  slog::Index** mp_uniondelta307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord309({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel310 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index286 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({2, 0, 1});
      slog::Relation* readrel312 = db->getRelation("mp_union");
      mp_unionindex287 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({2, 0, 1});
      slog::Relation* readrel314 = db->getRelation("mp_msk");
      mp_mskindex288 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex289 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({2, 0, 1});
      slog::Relation* readrel318 = db->getRelation("mp_union");
      mp_unionindex290 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel320 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index291 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 2, 3, 4, 0});
      slog::Relation* readrel322 = db->getRelation("mbranch");
      mbranchindex292 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({2, 0, 1});
      slog::Relation* readrel324 = db->getRelation("mp_union");
      mp_unionindex293 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("mp_msk");
      mp_mskindex294 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel328 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index295 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("mp_msk");
      mp_mskindex296 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({0, 1});
      slog::Relation* readrel332 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex297 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 3, 4, 0});
      slog::Relation* readrel334 = db->getRelation("mbranch");
      mbranchindex298 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 2, 3, 4, 0});
      slog::Relation* readrel336 = db->getRelation("mbranch");
      mbranchdelta304 = readrel336->getIndex(ord335, true);
      std::vector<u16> ord337({0, 1, 2});
      slog::Relation* readrel338 = db->getRelation("mp_union");
      mp_unionindex299 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1, 2});
      slog::Relation* readrel340 = db->getRelation("mp_union");
      mp_uniondelta305 = readrel340->getIndex(ord339, true);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("mp_msk");
      mp_mskindex300 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("mp_msk");
      mp_mskdelta306 = readrel344->getIndex(ord343, true);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex301 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 2, 0});
      slog::Relation* readrel348 = db->getRelation("mp_union");
      mp_unionindex302 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("mp_union");
      mp_uniondelta307 = readrel350->getIndex(ord349, true);
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("mp_union_ans");
      mp_union_ansindex303 = readrel352->getIndex(ord351, false);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        u64 v_c31 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x104x0x0x1index286, std::array<u64,10>{v_c79, v_c78, v_c77, v_c31, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex287, std::array<u64,3>{v_c76, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex288, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex289, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex290, std::array<u64,3>{v_c79, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x104x0x0x0index291, std::array<u64,9>{v_c77, v_c78, v_c79, v_c31, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m353) {
          u64 v_c80 = m353[4]; u64 v_c25 = m353[5]; u64 v_c26 = m353[6]; u64 v_c27 = m353[7]; u64 v_c28 = m353[8];
          u64 v_c81 = _prim_lt(db, v_c26, v_c78);
          if (v_c81 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c81) return;
          if (!slog::exists_probe<5,4>(mbranchindex292, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex293, std::array<u64,3>{v_c76, v_c80, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex294, std::array<u64,3>{v_c27, v_c78, 0})) return;
          slog::join_probe<10,9>($sup5638x104x0x0x1index295, std::array<u64,10>{v_c79, v_c78, v_c77, v_c31, v_c80, v_c25, v_c26, v_c27, v_c28, 0}, [&](const std::array<u64,10>& m355) {
            u64 v_c82 = m355[9];
            if (!slog::exists_probe<3,3>(mp_mskindex296, std::array<u64,3>{v_c27, v_c78, v_c82})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex297, std::array<u64,2>{v_c82, v_c77})) return;
            slog::join_probe_old<5,4>(mbranchindex298, mbranchdelta304, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0}, [&](const std::array<u64,5>& m356) {
              u64 v_c83 = m356[4];
              slog::join_probe_old<3,3>(mp_unionindex299, mp_uniondelta305, std::array<u64,3>{v_c80, v_c83, v_c76}, [&](const std::array<u64,3>& m357) {
                slog::join_probe_old<3,3>(mp_mskindex300, mp_mskdelta306, std::array<u64,3>{v_c27, v_c78, v_c82}, [&](const std::array<u64,3>& m358) {
                  slog::join_probe<2,2>(mp_msk_ansindex301, std::array<u64,2>{v_c82, v_c77}, [&](const std::array<u64,2>& m359) {
                    slog::join_probe_old<3,2>(mp_unionindex302, mp_uniondelta307, std::array<u64,3>{v_c83, v_c79, 0}, [&](const std::array<u64,3>& m360) {
                      u64 v_c84 = m360[2];
                      slog::join_probe<2,1>(mp_union_ansindex303, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m361) {
                        u64 v_c14 = m361[1];
                        u64 v_c85 = _prim_band(db, v_c27, v_c78);
                        if (v_c85 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c86 = _prim_lt(db, v_c85, v_c75);
                        if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c86) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c80, v_c14, v_c78, v_c77, v_c31});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c77, v_c78, v_c14, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_bld __t2Csk801 p m l __v0) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join mbranch (1 2 3 4 0) 3 p m l r __t29Nf797) (exists mp_del (1 2 0) 1 __t29Nf797) (exists mp_del (1 2 0) 1 r) (join $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 p l m r __t2paO798 k) (join mp_del (0 2 1) 3 __t2paO798 k __t29Nf797) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join mp_del_ans (0 1) 2 __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index363;  slog::Index** mp_mskindex364;  slog::Index** mp_msk_ansindex365;  slog::Index** mp_del_ansindex366;  slog::Index** mp_bld_ansindex367;  slog::Index** mbranchindex368;  slog::Index** mp_delindex369;  slog::Index** mp_delindex370;  slog::Index** $sup5638x84x0x0x0index371;  slog::Index** mp_delindex372;  slog::Index** mp_delindex373;  slog::Index** mp_mskindex374;  slog::Index** mp_msk_ansindex375;  slog::Index** mp_delindex376;  slog::Index** mp_del_ansindex377;  slog::Index** mp_bld_ansindex378;  slog::Index** mp_mskdelta379;  slog::Index** mp_deldelta380;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord382({0, 1});
      slog::Relation* readrel383 = db->getRelation("mp_del_ans");
      head_index[0] = readrel383->getIndex(ord382, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord384({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel385 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index363 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({2, 0, 1});
      slog::Relation* readrel387 = db->getRelation("mp_msk");
      mp_mskindex364 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex365 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 0});
      slog::Relation* readrel391 = db->getRelation("mp_del_ans");
      mp_del_ansindex366 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex367 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 3, 4, 0});
      slog::Relation* readrel395 = db->getRelation("mbranch");
      mbranchindex368 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("mp_del");
      mp_delindex369 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("mp_del");
      mp_delindex370 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel401 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index371 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({0, 2, 1});
      slog::Relation* readrel403 = db->getRelation("mp_del");
      mp_delindex372 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("mp_del");
      mp_delindex373 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("mp_msk");
      mp_mskindex374 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0});
      slog::Relation* readrel409 = db->getRelation("mp_msk");
      mp_mskdelta379 = readrel409->getIndex(ord408, true);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex375 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("mp_del");
      mp_delindex376 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("mp_del");
      mp_deldelta380 = readrel415->getIndex(ord414, true);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("mp_del_ans");
      mp_del_ansindex377 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({0, 1});
      slog::Relation* readrel419 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex378 = readrel419->getIndex(ord418, false);
  
    }
    ReadTask381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c88 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c14 = _t[4];
        if (!slog::exists_probe<6,3>($sup5638x84x0x0x0index363, std::array<u64,6>{v_c27, v_c25, v_c26, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex364, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex365, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(mp_del_ansindex366, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(mp_bld_ansindex367, std::array<u64,2>{v_c88, 0})) return;
        slog::join_probe<5,3>(mbranchindex368, std::array<u64,5>{v_c27, v_c26, v_c25, 0, 0}, [&](const std::array<u64,5>& m420) {
          u64 v_c28 = m420[3]; u64 v_c89 = m420[4];
          if (!slog::exists_probe<3,1>(mp_delindex369, std::array<u64,3>{v_c89, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex370, std::array<u64,3>{v_c28, 0, 0})) return;
          slog::join_probe<6,4>($sup5638x84x0x0x0index371, std::array<u64,6>{v_c27, v_c25, v_c26, v_c28, 0, 0}, [&](const std::array<u64,6>& m421) {
            u64 v_c90 = m421[4]; u64 v_c24 = m421[5];
            slog::join_probe<3,3>(mp_delindex372, std::array<u64,3>{v_c90, v_c24, v_c89}, [&](const std::array<u64,3>& m422) {
              if (!slog::exists_probe<3,2>(mp_delindex373, std::array<u64,3>{v_c28, v_c24, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex374, mp_mskdelta379, std::array<u64,3>{v_c24, v_c26, 0}, [&](const std::array<u64,3>& m423) {
                u64 v_c91 = m423[2];
                slog::join_probe<2,2>(mp_msk_ansindex375, std::array<u64,2>{v_c91, v_c27}, [&](const std::array<u64,2>& m424) {
                  slog::join_probe_old<3,2>(mp_delindex376, mp_deldelta380, std::array<u64,3>{v_c28, v_c24, 0}, [&](const std::array<u64,3>& m425) {
                    u64 v_c92 = m425[2];
                    slog::join_probe<2,2>(mp_del_ansindex377, std::array<u64,2>{v_c92, v_c14}, [&](const std::array<u64,2>& m426) {
                      slog::join_probe<2,1>(mp_bld_ansindex378, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m427) {
                        u64 v_c52 = m427[1];
                        u64 v_c93 = _prim_band(db, v_c24, v_c26);
                        if (v_c93 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c94 = _prim_gt(db, v_c93, v_c87);
                        if (v_c94 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c94) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c90, v_c52}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_bld", _fires);
  
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
  // (crule (pre) (scan eval __t94oK812 __t7PJK811 rho t) (body (join letrec (0 1 2 3) 1 __t7PJK811 x er eb)) (head (emit $sup70016x95x0x0x0 (1 4 2 0 3 5) eb t er __t94oK812 rho x)) interp.slog:96 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord431({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel432 = db->getRelation("$sup70016x95x0x0x0");
      head_index[0] = readrel432->getIndex(ord431, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord433({0, 1, 2, 3});
      slog::Relation* readrel434 = db->getRelation("letrec");
      letrecindex429 = readrel434->getIndex(ord433, false);
  
    }
    ReadTask430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        slog::join_probe<4,1>(letrecindex429, std::array<u64,4>{v_c96, 0, 0, 0}, [&](const std::array<u64,4>& m435) {
          u64 v_c97 = m435[1]; u64 v_c98 = m435[2]; u64 v_c99 = m435[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c99, v_c9, v_c98, v_c95, v_c8, v_c97}, std::array<u16,6>{1, 4, 2, 0, 3, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask430* _cont = new ReadTask430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask430(db,b), false);
  // (crule (pre) (scan div_by_zero __erre8p9l1746 __errf7vvx1747 __errf1DYW1748) (body) (head (emit error (0) __erre8p9l1746)) <internal>:1 #f)
  class ReadTask436 : public slog::Task
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
      std::vector<u16> ord437({0});
      slog::Relation* readrel438 = db->getRelation("error");
      head_index[0] = readrel438->getIndex(ord437, false);
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c100 = _t[0];
        u64 v_c101 = _t[1];
        u64 v_c102 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c100}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let __tconst14HM709 const60e3114d9b4b6577eea8cbc0) (let __tconst9fQa703 const844546be553b9dcbf71ae163) (let __tconst09sA701 const0453462f31b2bcf68e33a91f)) (scan temp92Pq1813 __t8Hit708) (body (exists sym (1 0) 1 __tconst9fQa703) (exists primref (1 0) 1 __tconst14HM709) (exists app (2 0 1) 1 __t8Hit708) (join sym (1 0) 1 __tconst09sA701 __t1F7O702) (join sym (1 0) 1 __tconst9fQa703 __t3RPz704) (join primref (1 0) 1 __tconst14HM709 __t8M3S710) (join app (1 2 0) 2 __t8M3S710 __t8Hit708 __t1VB8711)) (head (emit-temp temp4ydz1814 __t1VB8711) (mkstruct if (1 3 2 0) __t7BKw712 __t1VB8711 __t1F7O702 __t3RPz704)) kcfa.slog:52 #f)
  class ReadTask446 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex439;  slog::Index** primrefindex440;  slog::Index** appindex441;  slog::Index** symindex442;  slog::Index** symindex443;  slog::Index** primrefindex444;  slog::Index** appindex445;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4ydz1814");
      head_rel[1] = db->getRelation("if");
      outer_rel = db->getRelation("temp92Pq1813");
      std::vector<u16> ord447({1, 0});
      slog::Relation* readrel448 = db->getRelation("sym");
      symindex439 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 0});
      slog::Relation* readrel450 = db->getRelation("primref");
      primrefindex440 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({2, 0, 1});
      slog::Relation* readrel452 = db->getRelation("app");
      appindex441 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({1, 0});
      slog::Relation* readrel454 = db->getRelation("sym");
      symindex442 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 0});
      slog::Relation* readrel456 = db->getRelation("sym");
      symindex443 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({1, 0});
      slog::Relation* readrel458 = db->getRelation("primref");
      primrefindex444 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 2, 0});
      slog::Relation* readrel460 = db->getRelation("app");
      appindex445 = readrel460->getIndex(ord459, false);
  
    }
    ReadTask446(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c104 = v_const844546be553b9dcbf71ae163;
      u64 v_c105 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        if (!slog::exists_probe<2,1>(symindex439, std::array<u64,2>{v_c104, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex440, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<3,1>(appindex441, std::array<u64,3>{v_c106, 0, 0})) return;
        slog::join_probe<2,1>(symindex442, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m461) {
          u64 v_c107 = m461[1];
          slog::join_probe<2,1>(symindex443, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m462) {
            u64 v_c108 = m462[1];
            slog::join_probe<2,1>(primrefindex444, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m463) {
              u64 v_c109 = m463[1];
              slog::join_probe<3,2>(appindex445, std::array<u64,3>{v_c109, v_c106, 0}, [&](const std::array<u64,3>& m464) {
                u64 v_c110 = m464[2];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c110});
                slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c110, v_c107, v_c108}, std::array<u16,4>{1, 3, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:52", "delta:temp92Pq1813", _fires);
  
      if (!_done)
      {
        ReadTask446* _cont = new ReadTask446(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask446(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t0MS8397 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t0MS8397 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_del (2 0 1) 1 k) (join-old $sup5638x81x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t5Y7y396 l p r) (neq p __v0) (exists mp_del (0 2 1) 2 __t5Y7y396 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8pu9395) (join-old mp_del (0 2 1) 3 (0 2 1) __t5Y7y396 k __t8pu9395)) (head (emit mp_del_ans (0 1) __t5Y7y396 __t8pu9395)) map.slog:82 #f)
  class ReadTask476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex465;  slog::Index** mbranchindex466;  slog::Index** mp_delindex467;  slog::Index** $sup5638x81x0x0x0index468;  slog::Index** mp_delindex469;  slog::Index** mbranchindex470;  slog::Index** mp_delindex471;  slog::Index** mp_mskdelta472;  slog::Index** $sup5638x81x0x0x0delta473;  slog::Index** mbranchdelta474;  slog::Index** mp_deldelta475;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("mp_del_ans");
      head_index[0] = readrel478->getIndex(ord477, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord479({0, 1, 2});
      slog::Relation* readrel480 = db->getRelation("mp_msk");
      mp_mskindex465 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 1, 2});
      slog::Relation* readrel482 = db->getRelation("mp_msk");
      mp_mskdelta472 = readrel482->getIndex(ord481, true);
      std::vector<u16> ord483({2, 0, 1, 3, 4});
      slog::Relation* readrel484 = db->getRelation("mbranch");
      mbranchindex466 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({2, 0, 1});
      slog::Relation* readrel486 = db->getRelation("mp_del");
      mp_delindex467 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel488 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index468 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel490 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0delta473 = readrel490->getIndex(ord489, true);
      std::vector<u16> ord491({0, 2, 1});
      slog::Relation* readrel492 = db->getRelation("mp_del");
      mp_delindex469 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 3, 4, 0});
      slog::Relation* readrel494 = db->getRelation("mbranch");
      mbranchindex470 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 3, 4, 0});
      slog::Relation* readrel496 = db->getRelation("mbranch");
      mbranchdelta474 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 2, 1});
      slog::Relation* readrel498 = db->getRelation("mp_del");
      mp_delindex471 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 2, 1});
      slog::Relation* readrel500 = db->getRelation("mp_del");
      mp_deldelta475 = readrel500->getIndex(ord499, true);
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c111 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex465, mp_mskdelta472, std::array<u64,3>{v_c111, 0, 0}, [&](const std::array<u64,3>& m501) {
          u64 v_c24 = m501[1]; u64 v_c26 = m501[2];
          if (!slog::exists_probe<5,1>(mbranchindex466, std::array<u64,5>{v_c26, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex467, std::array<u64,3>{v_c24, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x81x0x0x0index468, $sup5638x81x0x0x0delta473, std::array<u64,6>{v_c24, v_c26, 0, 0, 0, 0}, [&](const std::array<u64,6>& m502) {
            u64 v_c112 = m502[2]; u64 v_c25 = m502[3]; u64 v_c27 = m502[4]; u64 v_c28 = m502[5];
            if (v_c27 == v_c14) return;
            if (!slog::exists_probe<3,2>(mp_delindex469, std::array<u64,3>{v_c112, v_c24, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex470, mbranchdelta474, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0}, [&](const std::array<u64,5>& m503) {
              u64 v_c113 = m503[4];
              slog::join_probe_old<3,3>(mp_delindex471, mp_deldelta475, std::array<u64,3>{v_c112, v_c24, v_c113}, [&](const std::array<u64,3>& m504) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c112, v_c113}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask476* _cont = new ReadTask476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask476(db,b), false);
  // (crule (pre) (scan temp9Aeo1872 __t9DAM375 __t9OPt374) (body) (head (emit mp_hsb_ans (0 1) __t9DAM375 __t9OPt374)) map.slog:19 #f)
  class ReadTask505 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("mp_hsb_ans");
      head_index[0] = readrel507->getIndex(ord506, false);
      outer_rel = db->getRelation("temp9Aeo1872");
  
    }
    ReadTask505(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c114, v_c115}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:temp9Aeo1872", _fires);
  
      if (!_done)
      {
        ReadTask505* _cont = new ReadTask505(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask505(db,b), false);
  // (crule (pre (let __trid3LOQ1254 constb177cd86b4c517da8099d6e4) (let __trel6Mro1255 const4a59dbb9cb3129dfcc75170b) (let __tcol1UAK1256 const5feceb66ffc86f38d952786c) (let __trel3zI81257 const4a59dbb9cb3129dfcc75170b) (let __tcol3LJP1258 const6b86b273ff34fce19d6b804e) (let __trel0NSO1259 const4a59dbb9cb3129dfcc75170b) (let __tcol76GW1260 constd4735e3a265e16eee03f5971)) (scan $sup70016x92x0x0x1 __d0 __d1 __d3 __v0 eb er rho t vr x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid3LOQ1254 __trel6Mro1255 __tcol1UAK1256 (1 2 3 4 0)) (tycheck __v0 (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid3LOQ1254 __trel3zI81257 __tcol3LJP1258 (1 2 3 4 0)) (tycheck t (accept seq) __trid3LOQ1254 __trel0NSO1259 __tcol76GW1260 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __23W01253 eb __v0 t)) interp.slog:93 #f)
  class ReadTask521 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid519;  u32 sid508;  u32 sid509;  u32 sid510;  u32 sid511;  u32 sid512;  u32 sid513;  u32 sid518;  u32 sid520;  u32 sid514;  u32 sid515;  u32 sid516;  u32 sid517;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x92x0x0x1");
      sid519 = db->getRelation("_enum")->getStructId();
      sid508 = db->getRelation("app")->getStructId();
      sid509 = db->getRelation("boolean")->getStructId();
      sid510 = db->getRelation("if")->getStructId();
      sid511 = db->getRelation("lambda")->getStructId();
      sid512 = db->getRelation("let")->getStructId();
      sid513 = db->getRelation("letrec")->getStructId();
      sid518 = db->getRelation("mbranch")->getStructId();
      sid520 = db->getRelation("mleaf")->getStructId();
      sid514 = db->getRelation("num")->getStructId();
      sid515 = db->getRelation("primref")->getStructId();
      sid516 = db->getRelation("ref")->getStructId();
      sid517 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask521(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_constb177cd86b4c517da8099d6e4;
      u64 v_c117 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
      u64 v_c119 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c64 = _t[0];
        u64 v_c123 = _t[1];
        u64 v_c124 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c99 = _t[4];
        u64 v_c98 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c9 = _t[7];
        u64 v_c125 = _t[8];
        u64 v_c97 = _t[9];
        ++_fires;
        if (!((is_struct(v_c99) && (decode_struct_id(v_c99) == sid508 || decode_struct_id(v_c99) == sid509 || decode_struct_id(v_c99) == sid510 || decode_struct_id(v_c99) == sid511 || decode_struct_id(v_c99) == sid512 || decode_struct_id(v_c99) == sid513 || decode_struct_id(v_c99) == sid514 || decode_struct_id(v_c99) == sid515 || decode_struct_id(v_c99) == sid516 || decode_struct_id(v_c99) == sid517))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c116, v_c117, v_c118, v_c99}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid518 || decode_struct_id(v_c14) == sid519 || decode_struct_id(v_c14) == sid520))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c116, v_c119, v_c120, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c116, v_c121, v_c122, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c99, v_c14, v_c9}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask521* _cont = new ReadTask521(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask521(db,b), false);
  // (crule (pre) (scan $sup5638x95x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t6N42442) (join-old mp_msk_ans (0 1) 2 (0 1) __t6N42442 p)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t6N42442 m n p q r u v)) map.slog:96 #f)
  class ReadTask527 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex522;  slog::Index** mp_mskindex523;  slog::Index** mp_msk_ansindex524;  slog::Index** mp_mskdelta525;  slog::Index** mp_msk_ansdelta526;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord528({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel529 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel529->getIndex(ord528, false);
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord530({1, 0});
      slog::Relation* readrel531 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex522 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("mp_msk");
      mp_mskindex523 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 2, 0});
      slog::Relation* readrel535 = db->getRelation("mp_msk");
      mp_mskdelta525 = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex524 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 1});
      slog::Relation* readrel539 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta526 = readrel539->getIndex(ord538, true);
  
    }
    ReadTask527(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c77 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c79 = _t[7];
        u64 v_c31 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex522, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex523, mp_mskdelta525, std::array<u64,3>{v_c77, v_c26, 0}, [&](const std::array<u64,3>& m540) {
          u64 v_c126 = m540[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex524, mp_msk_ansdelta526, std::array<u64,2>{v_c126, v_c27}, [&](const std::array<u64,2>& m541) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c64, v_c25, v_c126, v_c26, v_c78, v_c27, v_c77, v_c28, v_c79, v_c31}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask527* _cont = new ReadTask527(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask527(db,b), false);
  // (crule (pre) (scan mbranch __t1a8C695 q n u v) (body (exists mp_join (3 4 1 0 2) 2 q __t1a8C695) (exists mp_union (2 0 1) 1 __t1a8C695) (exists mp_msk (1 2 0) 1 q) (join $sup5638x101x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t1a8C695 u v __t5awj693 l m p r __t1ouF694) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 p m l r __t1ouF694) (exists mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t1ouF694 q __t1a8C695 __t8BsD696) (join mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (exists mp_join_ans (0 1) 1 __t8BsD696) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask557 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex542;  slog::Index** mp_unionindex543;  slog::Index** mp_mskindex544;  slog::Index** $sup5638x101x0x0x0index545;  slog::Index** mbranchindex546;  slog::Index** mp_unionindex547;  slog::Index** mp_mskindex548;  slog::Index** mp_joinindex549;  slog::Index** mp_unionindex550;  slog::Index** mp_join_ansindex551;  slog::Index** mp_mskindex552;  slog::Index** mp_msk_ansindex553;  slog::Index** mp_join_ansindex554;  slog::Index** mp_joindelta555;  slog::Index** mp_mskdelta556;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord558({0, 1});
      slog::Relation* readrel559 = db->getRelation("mp_union_ans");
      head_index[0] = readrel559->getIndex(ord558, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord560({3, 4, 1, 0, 2});
      slog::Relation* readrel561 = db->getRelation("mp_join");
      mp_joinindex542 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({2, 0, 1});
      slog::Relation* readrel563 = db->getRelation("mp_union");
      mp_unionindex543 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 0});
      slog::Relation* readrel565 = db->getRelation("mp_msk");
      mp_mskindex544 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel567 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index545 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 2, 3, 4, 0});
      slog::Relation* readrel569 = db->getRelation("mbranch");
      mbranchindex546 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({0, 1, 2});
      slog::Relation* readrel571 = db->getRelation("mp_union");
      mp_unionindex547 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("mp_msk");
      mp_mskindex548 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 3, 4, 0});
      slog::Relation* readrel575 = db->getRelation("mp_join");
      mp_joinindex549 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 3, 4, 0});
      slog::Relation* readrel577 = db->getRelation("mp_join");
      mp_joindelta555 = readrel577->getIndex(ord576, true);
      std::vector<u16> ord578({0, 1, 2});
      slog::Relation* readrel579 = db->getRelation("mp_union");
      mp_unionindex550 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("mp_join_ans");
      mp_join_ansindex551 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("mp_msk");
      mp_mskindex552 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("mp_msk");
      mp_mskdelta556 = readrel585->getIndex(ord584, true);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex553 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({0, 1});
      slog::Relation* readrel589 = db->getRelation("mp_join_ans");
      mp_join_ansindex554 = readrel589->getIndex(ord588, false);
  
    }
    ReadTask557(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c127 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        u64 v_c31 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex542, std::array<u64,5>{v_c77, v_c127, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex543, std::array<u64,3>{v_c127, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex544, std::array<u64,3>{v_c77, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x101x0x0x0index545, std::array<u64,11>{v_c78, v_c77, v_c127, v_c79, v_c31, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m590) {
          u64 v_c128 = m590[5]; u64 v_c25 = m590[6]; u64 v_c26 = m590[7]; u64 v_c27 = m590[8]; u64 v_c28 = m590[9]; u64 v_c129 = m590[10];
          u64 v_c130 = _prim_lt(db, v_c78, v_c26);
          if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c130) return;
          slog::join_probe<5,5>(mbranchindex546, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, v_c129}, [&](const std::array<u64,5>& m592) {
            if (!slog::exists_probe<3,3>(mp_unionindex547, std::array<u64,3>{v_c128, v_c129, v_c127})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex548, std::array<u64,3>{v_c77, v_c26, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex549, mp_joindelta555, std::array<u64,5>{v_c27, v_c129, v_c77, v_c127, 0}, [&](const std::array<u64,5>& m593) {
              u64 v_c131 = m593[4];
              slog::join_probe<3,3>(mp_unionindex550, std::array<u64,3>{v_c128, v_c129, v_c127}, [&](const std::array<u64,3>& m594) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex551, std::array<u64,2>{v_c131, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex552, mp_mskdelta556, std::array<u64,3>{v_c77, v_c26, 0}, [&](const std::array<u64,3>& m595) {
                  u64 v_c132 = m595[2];
                  slog::join_probe<2,1>(mp_msk_ansindex553, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m596) {
                    u64 v_c14 = m596[1];
                    if (v_c27 == v_c14) return;
                    slog::join_probe<2,1>(mp_join_ansindex554, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m597) {
                      u64 v_c52 = m597[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c128, v_c52}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask557* _cont = new ReadTask557(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask557(db,b), false);
  // (crule (pre (let __trid22rX1279 const11445e6556bc59ce1e80cdf7) (let __trel6D1G1280 constdd7bbf31ce5f578b9805e840) (let __tcol48Qs1281 const5feceb66ffc86f38d952786c) (let __trel3kHv1282 constdd7bbf31ce5f578b9805e840) (let __tcol9u5b1283 const6b86b273ff34fce19d6b804e)) (scan $sup5638x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid22rX1279 __trel6D1G1280 __tcol48Qs1281 (1 2 3 4 0)) (tycheck n (accept int) __trid22rX1279 __trel3kHv1282 __tcol9u5b1283 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __0LJE1278 p n)) map.slog:111 #f)
  class ReadTask598 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c133 = v_const11445e6556bc59ce1e80cdf7;
      u64 v_c134 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
      u64 v_c136 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c137 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c64 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c77 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c138 = _t[7];
        u64 v_c9 = _t[8];
        u64 v_c79 = _t[9];
        u64 v_c31 = _t[10];
        ++_fires;
        if (!(is_int(v_c27)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c133, v_c134, v_c135, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c78)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c133, v_c136, v_c137, v_c78}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c27, v_c78}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:$sup5638x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask598* _cont = new ReadTask598(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), false);
  // (crule (pre) (scan letrec __t06G7423 x er eb) (body (join eval (1 2 3 0) 1 __t06G7423 rho t __1KGF1410)) (head (mkstruct mp_put (1 2 3 0) __9PdX1411 rho x t)) interp.slog:98 #f)
  class ReadTask600 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex599;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord601({1, 2, 3, 0});
      slog::Relation* readrel602 = db->getRelation("eval");
      evalindex599 = readrel602->getIndex(ord601, false);
  
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
        u64 v_c139 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c98 = _t[2];
        u64 v_c99 = _t[3];
        slog::join_probe<4,1>(evalindex599, std::array<u64,4>{v_c139, 0, 0, 0}, [&](const std::array<u64,4>& m603) {
          u64 v_c8 = m603[1]; u64 v_c9 = m603[2]; u64 v_c140 = m603[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c8, v_c97, v_c9}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:letrec", _fires);
  
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
  // (crule (pre) (scan extend_env_ans __t5fzh540 __v0) (body (join-old eval (2 3 0 1) 1 (2 3 0 1) __v0 t2 __t7TaT537 eb) (exists lambda (2 0 1) 1 eb) (exists $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 2 eb t2) (exists tick_ans (1 0) 1 t2) (exists eval_ans (0 1) 1 __t7TaT537) (join-old extend_env (3 0 1 2) 2 (3 0 1 2) t2 __t5fzh540 rhoc xs) (exists closure (2 0 1) 1 rhoc) (exists $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 4 eb t2 rhoc xs) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (exists eval_ans (1 0) 1 __t9dfl535) (join-old $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 4 (4 10 8 12 0 1 2 3 5 6 7 9 11) eb t2 rhoc xs __t2z6s532 __t5qy8533 __t2srV536 __t0CD9539 ef es rho t vs) (join-old $sup70016x51x0x0x0 (4 0 3 1 2) 5 (4 0 3 1 2) t __t2z6s532 rho ef es) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask642 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex604;  slog::Index** lambdaindex605;  slog::Index** $sup70016x51x0x0x1index606;  slog::Index** tick_ansindex607;  slog::Index** eval_ansindex608;  slog::Index** extend_envindex609;  slog::Index** closureindex610;  slog::Index** $sup70016x51x0x0x1index611;  slog::Index** lambdaindex612;  slog::Index** closureindex613;  slog::Index** eval_ansindex614;  slog::Index** $sup70016x51x0x0x1index615;  slog::Index** $sup70016x51x0x0x0index616;  slog::Index** evalindex617;  slog::Index** eval_argsindex618;  slog::Index** appindex619;  slog::Index** tickindex620;  slog::Index** eval_ansindex621;  slog::Index** eval_args_ansindex622;  slog::Index** tick_ansindex623;  slog::Index** evalindex624;  slog::Index** appindex625;  slog::Index** tickindex626;  slog::Index** eval_ansindex627;  slog::Index** eval_args_ansindex628;  slog::Index** tick_ansindex629;  slog::Index** eval_ansindex630;  slog::Index** evaldelta631;  slog::Index** extend_envdelta632;  slog::Index** lambdadelta633;  slog::Index** closuredelta634;  slog::Index** $sup70016x51x0x0x1delta635;  slog::Index** $sup70016x51x0x0x0delta636;  slog::Index** evaldelta637;  slog::Index** eval_argsdelta638;  slog::Index** evaldelta639;  slog::Index** appdelta640;  slog::Index** tickdelta641;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord643({0, 1});
      slog::Relation* readrel644 = db->getRelation("eval_ans");
      head_index[0] = readrel644->getIndex(ord643, false);
      outer_rel = db->getRelation("extend_env_ans");
      std::vector<u16> ord645({2, 3, 0, 1});
      slog::Relation* readrel646 = db->getRelation("eval");
      evalindex604 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({2, 3, 0, 1});
      slog::Relation* readrel648 = db->getRelation("eval");
      evaldelta631 = readrel648->getIndex(ord647, true);
      std::vector<u16> ord649({2, 0, 1});
      slog::Relation* readrel650 = db->getRelation("lambda");
      lambdaindex605 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel652 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index606 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 0});
      slog::Relation* readrel654 = db->getRelation("tick_ans");
      tick_ansindex607 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("eval_ans");
      eval_ansindex608 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({3, 0, 1, 2});
      slog::Relation* readrel658 = db->getRelation("extend_env");
      extend_envindex609 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({3, 0, 1, 2});
      slog::Relation* readrel660 = db->getRelation("extend_env");
      extend_envdelta632 = readrel660->getIndex(ord659, true);
      std::vector<u16> ord661({2, 0, 1});
      slog::Relation* readrel662 = db->getRelation("closure");
      closureindex610 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel664 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index611 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("lambda");
      lambdaindex612 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 0});
      slog::Relation* readrel668 = db->getRelation("lambda");
      lambdadelta633 = readrel668->getIndex(ord667, true);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("closure");
      closureindex613 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 2, 0});
      slog::Relation* readrel672 = db->getRelation("closure");
      closuredelta634 = readrel672->getIndex(ord671, true);
      std::vector<u16> ord673({1, 0});
      slog::Relation* readrel674 = db->getRelation("eval_ans");
      eval_ansindex614 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel676 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index615 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel678 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta635 = readrel678->getIndex(ord677, true);
      std::vector<u16> ord679({4, 0, 3, 1, 2});
      slog::Relation* readrel680 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index616 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({4, 0, 3, 1, 2});
      slog::Relation* readrel682 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0delta636 = readrel682->getIndex(ord681, true);
      std::vector<u16> ord683({2, 3, 0, 1});
      slog::Relation* readrel684 = db->getRelation("eval");
      evalindex617 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({2, 3, 0, 1});
      slog::Relation* readrel686 = db->getRelation("eval");
      evaldelta637 = readrel686->getIndex(ord685, true);
      std::vector<u16> ord687({3, 2, 0, 1});
      slog::Relation* readrel688 = db->getRelation("eval_args");
      eval_argsindex618 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({3, 2, 0, 1});
      slog::Relation* readrel690 = db->getRelation("eval_args");
      eval_argsdelta638 = readrel690->getIndex(ord689, true);
      std::vector<u16> ord691({1, 2, 0});
      slog::Relation* readrel692 = db->getRelation("app");
      appindex619 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 2, 1});
      slog::Relation* readrel694 = db->getRelation("tick");
      tickindex620 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("eval_ans");
      eval_ansindex621 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("eval_args_ans");
      eval_args_ansindex622 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("tick_ans");
      tick_ansindex623 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({2, 3, 0, 1});
      slog::Relation* readrel702 = db->getRelation("eval");
      evalindex624 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({2, 3, 0, 1});
      slog::Relation* readrel704 = db->getRelation("eval");
      evaldelta639 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({0, 1, 2});
      slog::Relation* readrel706 = db->getRelation("app");
      appindex625 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1, 2});
      slog::Relation* readrel708 = db->getRelation("app");
      appdelta640 = readrel708->getIndex(ord707, true);
      std::vector<u16> ord709({0, 2, 1});
      slog::Relation* readrel710 = db->getRelation("tick");
      tickindex626 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 2, 1});
      slog::Relation* readrel712 = db->getRelation("tick");
      tickdelta641 = readrel712->getIndex(ord711, true);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("eval_ans");
      eval_ansindex627 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("eval_args_ans");
      eval_args_ansindex628 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({0, 1});
      slog::Relation* readrel718 = db->getRelation("tick_ans");
      tick_ansindex629 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("eval_ans");
      eval_ansindex630 = readrel720->getIndex(ord719, false);
  
    }
    ReadTask642(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c141 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<4,1>(evalindex604, evaldelta631, std::array<u64,4>{v_c14, 0, 0, 0}, [&](const std::array<u64,4>& m721) {
          u64 v_c142 = m721[1]; u64 v_c143 = m721[2]; u64 v_c99 = m721[3];
          if (!slog::exists_probe<3,1>(lambdaindex605, std::array<u64,3>{v_c99, 0, 0})) return;
          if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index606, std::array<u64,13>{v_c99, v_c142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(tick_ansindex607, std::array<u64,2>{v_c142, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex608, std::array<u64,2>{v_c143, 0})) return;
          slog::join_probe_old<4,2>(extend_envindex609, extend_envdelta632, std::array<u64,4>{v_c142, v_c141, 0, 0}, [&](const std::array<u64,4>& m722) {
            u64 v_c144 = m722[2]; u64 v_c145 = m722[3];
            if (!slog::exists_probe<3,1>(closureindex610, std::array<u64,3>{v_c144, 0, 0})) return;
            if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index611, std::array<u64,13>{v_c99, v_c142, v_c144, v_c145, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<3,2>(lambdaindex612, lambdadelta633, std::array<u64,3>{v_c145, v_c99, 0}, [&](const std::array<u64,3>& m723) {
              u64 v_c146 = m723[2];
              slog::join_probe_old<3,2>(closureindex613, closuredelta634, std::array<u64,3>{v_c146, v_c144, 0}, [&](const std::array<u64,3>& m724) {
                u64 v_c147 = m724[2];
                if (!slog::exists_probe<2,1>(eval_ansindex614, std::array<u64,2>{v_c147, 0})) return;
                slog::join_probe_old<13,4>($sup70016x51x0x0x1index615, $sup70016x51x0x0x1delta635, std::array<u64,13>{v_c99, v_c142, v_c144, v_c145, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m725) {
                  u64 v_c148 = m725[4]; u64 v_c149 = m725[5]; u64 v_c150 = m725[6]; u64 v_c151 = m725[7]; u64 v_c40 = m725[8]; u64 v_c7 = m725[9]; u64 v_c8 = m725[10]; u64 v_c9 = m725[11]; u64 v_c36 = m725[12];
                  slog::join_probe_old<5,5>($sup70016x51x0x0x0index616, $sup70016x51x0x0x0delta636, std::array<u64,5>{v_c9, v_c148, v_c8, v_c40, v_c7}, [&](const std::array<u64,5>& m726) {
                    slog::join_probe_old<4,4>(evalindex617, evaldelta637, std::array<u64,4>{v_c8, v_c9, v_c149, v_c40}, [&](const std::array<u64,4>& m727) {
                      slog::join_probe_old<4,4>(eval_argsindex618, eval_argsdelta638, std::array<u64,4>{v_c9, v_c8, v_c150, v_c7}, [&](const std::array<u64,4>& m728) {
                        if (!slog::exists_probe<3,2>(appindex619, std::array<u64,3>{v_c40, v_c7, 0})) return;
                        if (!slog::exists_probe<3,2>(tickindex620, std::array<u64,3>{v_c151, v_c9, 0})) return;
                        if (!slog::exists_probe<2,2>(eval_ansindex621, std::array<u64,2>{v_c149, v_c147})) return;
                        if (!slog::exists_probe<2,2>(eval_args_ansindex622, std::array<u64,2>{v_c150, v_c36})) return;
                        if (!slog::exists_probe<2,2>(tick_ansindex623, std::array<u64,2>{v_c151, v_c142})) return;
                        slog::join_probe_old<4,3>(evalindex624, evaldelta639, std::array<u64,4>{v_c8, v_c9, v_c148, 0}, [&](const std::array<u64,4>& m729) {
                          u64 v_c152 = m729[3];
                          slog::join_probe_old<3,3>(appindex625, appdelta640, std::array<u64,3>{v_c152, v_c40, v_c7}, [&](const std::array<u64,3>& m730) {
                            slog::join_probe_old<3,3>(tickindex626, tickdelta641, std::array<u64,3>{v_c151, v_c9, v_c152}, [&](const std::array<u64,3>& m731) {
                              slog::join_probe<2,2>(eval_ansindex627, std::array<u64,2>{v_c149, v_c147}, [&](const std::array<u64,2>& m732) {
                                slog::join_probe<2,2>(eval_args_ansindex628, std::array<u64,2>{v_c150, v_c36}, [&](const std::array<u64,2>& m733) {
                                  slog::join_probe<2,2>(tick_ansindex629, std::array<u64,2>{v_c151, v_c142}, [&](const std::array<u64,2>& m734) {
                                    slog::join_probe<2,1>(eval_ansindex630, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m735) {
                                      u64 v_c31 = m735[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:extend_env_ans", _fires);
  
      if (!_done)
      {
        ReadTask642* _cont = new ReadTask642(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask642(db,b), false);
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (scan boolval __t5IbK109 b) (body (exists $seq_at (1 0 2) 2 _00024sqo8pFe907 __t5IbK109) (exists $seq_atr (1 0 2) 2 _00024sqo3hRp908 __t5IbK109) (exists $seq_atr (1 0 2) 2 _00024sqo4hee909 __t5IbK109) (exists delta (1 2 0) 1 __tconst3u5R106) (exists _enum (1 0) 1 __tconst35Xg1071) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7aO7906 __t5IbK109 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8pFe907 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3hRp908 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4hee909 __t5IbK109 _00024seq2) (join delta (1 2 0) 2 __tconst3u5R106 _00024seq2 __t8l3B107) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (letp _00024sql6c1M901 (aslst _00024seq2)) (let chk2A4P1958 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk2A4P1958) (letp chk1Asp1959 (lref _00024sql6c1M901 _00024sqc9U0q904)) (eq __t5IbK109 chk1Asp1959) (letp chk0nZS1960 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk0nZS1960)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask751 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex736;  slog::Index** $seq_atrindex737;  slog::Index** $seq_atrindex738;  slog::Index** deltaindex739;  slog::Index** _enumindex740;  slog::Index** $seq_atindex741;  slog::Index** $seq_atindex742;  slog::Index** $seq_atrindex743;  slog::Index** $seq_atrindex744;  slog::Index** deltaindex745;  slog::Index** _enumindex746;  slog::Index** $seq_atdelta747;  slog::Index** $seq_atdelta748;  slog::Index** $seq_atrdelta749;  slog::Index** $seq_atrdelta750;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord752({1, 0, 2});
      slog::Relation* readrel753 = db->getRelation("$seq_at");
      $seq_atindex736 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 0, 2});
      slog::Relation* readrel755 = db->getRelation("$seq_atr");
      $seq_atrindex737 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 0, 2});
      slog::Relation* readrel757 = db->getRelation("$seq_atr");
      $seq_atrindex738 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("delta");
      deltaindex739 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0});
      slog::Relation* readrel761 = db->getRelation("_enum");
      _enumindex740 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 0, 2});
      slog::Relation* readrel763 = db->getRelation("$seq_at");
      $seq_atindex741 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 0, 2});
      slog::Relation* readrel765 = db->getRelation("$seq_at");
      $seq_atdelta747 = readrel765->getIndex(ord764, true);
      std::vector<u16> ord766({1, 0, 2});
      slog::Relation* readrel767 = db->getRelation("$seq_at");
      $seq_atindex742 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 0, 2});
      slog::Relation* readrel769 = db->getRelation("$seq_at");
      $seq_atdelta748 = readrel769->getIndex(ord768, true);
      std::vector<u16> ord770({1, 0, 2});
      slog::Relation* readrel771 = db->getRelation("$seq_atr");
      $seq_atrindex743 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 0, 2});
      slog::Relation* readrel773 = db->getRelation("$seq_atr");
      $seq_atrdelta749 = readrel773->getIndex(ord772, true);
      std::vector<u16> ord774({1, 0, 2});
      slog::Relation* readrel775 = db->getRelation("$seq_atr");
      $seq_atrindex744 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 0, 2});
      slog::Relation* readrel777 = db->getRelation("$seq_atr");
      $seq_atrdelta750 = readrel777->getIndex(ord776, true);
      std::vector<u16> ord778({1, 2, 0});
      slog::Relation* readrel779 = db->getRelation("delta");
      deltaindex745 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 0});
      slog::Relation* readrel781 = db->getRelation("_enum");
      _enumindex746 = readrel781->getIndex(ord780, false);
  
    }
    ReadTask751(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c153 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c154 = v_const06abaa100ecef791ce028c56;
      u64 v_c155 = v_constd4735e3a265e16eee03f5971;
      u64 v_c156 = v_const5feceb66ffc86f38d952786c;
      u64 v_c157 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c158 = v_const5feceb66ffc86f38d952786c;
      u64 v_c159 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c160 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c161 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c162 = _t[0];
        u64 v_c163 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex736, std::array<u64,3>{v_c159, v_c162, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex737, std::array<u64,3>{v_c160, v_c162, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex738, std::array<u64,3>{v_c161, v_c162, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex739, std::array<u64,3>{v_c154, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex740, std::array<u64,2>{v_c153, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex741, $seq_atdelta747, std::array<u64,3>{v_c158, v_c162, 0}, [&](const std::array<u64,3>& m782) {
          u64 v_c164 = m782[2];
          slog::join_probe_old<3,3>($seq_atindex742, $seq_atdelta748, std::array<u64,3>{v_c159, v_c162, v_c164}, [&](const std::array<u64,3>& m783) {
            slog::join_probe_old<3,3>($seq_atrindex743, $seq_atrdelta749, std::array<u64,3>{v_c160, v_c162, v_c164}, [&](const std::array<u64,3>& m784) {
              slog::join_probe_old<3,3>($seq_atrindex744, $seq_atrdelta750, std::array<u64,3>{v_c161, v_c162, v_c164}, [&](const std::array<u64,3>& m785) {
                slog::join_probe<3,2>(deltaindex745, std::array<u64,3>{v_c154, v_c164, 0}, [&](const std::array<u64,3>& m786) {
                  u64 v_c165 = m786[2];
                  slog::join_probe<2,1>(_enumindex746, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m787) {
                    u64 v_c166 = m787[1];
                    bool ok788 = true;
                    u64 v_c167 = _prim_aslst(db, v_c164, &ok788);
                    if (!ok788) return;
                    u64 v_c168 = _prim_llen(db, v_c167);
                    if (v_c168 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c155 != v_c168) return;
                    bool ok789 = true;
                    u64 v_c169 = _prim_lref(db, v_c167, v_c156, &ok789);
                    if (!ok789) return;
                    if (v_c162 != v_c169) return;
                    bool ok790 = true;
                    u64 v_c170 = _prim_lref(db, v_c167, v_c157, &ok790);
                    if (!ok790) return;
                    if (v_c162 != v_c170) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c165});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c166}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask751* _cont = new ReadTask751(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask751(db,b), false);
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t42Fa18 __v0) (body (exists extend_env (1 2 3 0) 1 __v0) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo31L8847 x _00024seq0) (exists $sup70016x47x0x0x0 (0 4 5 1 2 3) 2 _00024seq0 x) (exists extend_env (2 3 0 1) 1 _00024seq0) (join-old mp_put (0 2 1 3) 2 (0 2 1 3) __t42Fa18 x rho t) (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let xs (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (exists extend_env (1 2 3 0) 3 rho _00024seq0 t) (exists extend_env (1 2 3 0) 3 __v0 xs t) (join-old $sup70016x47x0x0x0 (2 3 4 5 0 1) 5 (2 3 4 5 0 1) rho t x xs _00024seq0 __t2ugT17) (join-old extend_env (0 2 3 1) 4 (0 2 3 1) __t2ugT17 _00024seq0 t rho) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) __v0 xs t __t8zl419) (join-old extend_env_ans (0 1) 1 (0 1) __t8zl419 __v1) (letp chk3qWP1823 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk3qWP1823)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask808 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex791;  slog::Index** $seq_atindex792;  slog::Index** $sup70016x47x0x0x0index793;  slog::Index** extend_envindex794;  slog::Index** mp_putindex795;  slog::Index** extend_envindex796;  slog::Index** extend_envindex797;  slog::Index** $sup70016x47x0x0x0index798;  slog::Index** extend_envindex799;  slog::Index** extend_envindex800;  slog::Index** extend_env_ansindex801;  slog::Index** $seq_atdelta802;  slog::Index** mp_putdelta803;  slog::Index** $sup70016x47x0x0x0delta804;  slog::Index** extend_envdelta805;  slog::Index** extend_envdelta806;  slog::Index** extend_env_ansdelta807;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord809({0, 1});
      slog::Relation* readrel810 = db->getRelation("extend_env_ans");
      head_index[0] = readrel810->getIndex(ord809, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord811({1, 2, 3, 0});
      slog::Relation* readrel812 = db->getRelation("extend_env");
      extend_envindex791 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0, 2});
      slog::Relation* readrel814 = db->getRelation("$seq_at");
      $seq_atindex792 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 0, 2});
      slog::Relation* readrel816 = db->getRelation("$seq_at");
      $seq_atdelta802 = readrel816->getIndex(ord815, true);
      std::vector<u16> ord817({0, 4, 5, 1, 2, 3});
      slog::Relation* readrel818 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index793 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({2, 3, 0, 1});
      slog::Relation* readrel820 = db->getRelation("extend_env");
      extend_envindex794 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 2, 1, 3});
      slog::Relation* readrel822 = db->getRelation("mp_put");
      mp_putindex795 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({0, 2, 1, 3});
      slog::Relation* readrel824 = db->getRelation("mp_put");
      mp_putdelta803 = readrel824->getIndex(ord823, true);
      std::vector<u16> ord825({1, 2, 3, 0});
      slog::Relation* readrel826 = db->getRelation("extend_env");
      extend_envindex796 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 2, 3, 0});
      slog::Relation* readrel828 = db->getRelation("extend_env");
      extend_envindex797 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel830 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index798 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel832 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0delta804 = readrel832->getIndex(ord831, true);
      std::vector<u16> ord833({0, 2, 3, 1});
      slog::Relation* readrel834 = db->getRelation("extend_env");
      extend_envindex799 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({0, 2, 3, 1});
      slog::Relation* readrel836 = db->getRelation("extend_env");
      extend_envdelta805 = readrel836->getIndex(ord835, true);
      std::vector<u16> ord837({1, 2, 3, 0});
      slog::Relation* readrel838 = db->getRelation("extend_env");
      extend_envindex800 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 3, 0});
      slog::Relation* readrel840 = db->getRelation("extend_env");
      extend_envdelta806 = readrel840->getIndex(ord839, true);
      std::vector<u16> ord841({0, 1});
      slog::Relation* readrel842 = db->getRelation("extend_env_ans");
      extend_env_ansindex801 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({0, 1});
      slog::Relation* readrel844 = db->getRelation("extend_env_ans");
      extend_env_ansdelta807 = readrel844->getIndex(ord843, true);
  
    }
    ReadTask808(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c171 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c172 = v_const5feceb66ffc86f38d952786c;
      u64 v_c173 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c174 = v_const5feceb66ffc86f38d952786c;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c176 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<4,1>(extend_envindex791, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        slog::join_probe_old<3,1>($seq_atindex792, $seq_atdelta802, std::array<u64,3>{v_c175, 0, 0}, [&](const std::array<u64,3>& m845) {
          u64 v_c97 = m845[1]; u64 v_c10 = m845[2];
          if (!slog::exists_probe<6,2>($sup70016x47x0x0x0index793, std::array<u64,6>{v_c10, v_c97, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(extend_envindex794, std::array<u64,4>{v_c10, 0, 0, 0})) return;
          slog::join_probe_old<4,2>(mp_putindex795, mp_putdelta803, std::array<u64,4>{v_c176, v_c97, 0, 0}, [&](const std::array<u64,4>& m846) {
            u64 v_c8 = m846[2]; u64 v_c9 = m846[3];
            bool ok847 = true;
            u64 v_c177 = _prim_aslst(db, v_c10, &ok847);
            if (!ok847) return;
            u64 v_c178 = _prim_llen(db, v_c177);
            if (v_c178 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c179 = _prim_ge(db, v_c178, v_c171);
            if (v_c179 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (!v_c179) return;
            u64 v_c180 = _prim__0002d(db, v_c178, v_c174);
            if (v_c180 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c145 = _prim_lslice(db, v_c177, v_c173, v_c180);
            if (v_c145 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (!slog::exists_probe<4,3>(extend_envindex796, std::array<u64,4>{v_c8, v_c10, v_c9, 0})) return;
            if (!slog::exists_probe<4,3>(extend_envindex797, std::array<u64,4>{v_c14, v_c145, v_c9, 0})) return;
            slog::join_probe_old<6,5>($sup70016x47x0x0x0index798, $sup70016x47x0x0x0delta804, std::array<u64,6>{v_c8, v_c9, v_c97, v_c145, v_c10, 0}, [&](const std::array<u64,6>& m849) {
              u64 v_c181 = m849[5];
              slog::join_probe_old<4,4>(extend_envindex799, extend_envdelta805, std::array<u64,4>{v_c181, v_c10, v_c9, v_c8}, [&](const std::array<u64,4>& m850) {
                slog::join_probe_old<4,3>(extend_envindex800, extend_envdelta806, std::array<u64,4>{v_c14, v_c145, v_c9, 0}, [&](const std::array<u64,4>& m851) {
                  u64 v_c182 = m851[3];
                  slog::join_probe_old<2,1>(extend_env_ansindex801, extend_env_ansdelta807, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m852) {
                    u64 v_c15 = m852[1];
                    bool ok853 = true;
                    u64 v_c183 = _prim_lref(db, v_c177, v_c172, &ok853);
                    if (!ok853) return;
                    if (v_c97 != v_c183) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c181, v_c15}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:mp_put_ans", _fires);
  
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
  // (crule (pre) (scan mbranch __t9QK9100 q n u v) (body (join mp_union (2 0 1) 1 __t9QK9100 __t32Fx98 __t8vmP99) (join mbranch (0 1 2 3 4) 1 __t8vmP99 p m l r) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t32Fx98 l m q r __t8vmP99 __t9QK9100 u v)) map.slog:111 #f)
  class ReadTask856 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex854;  slog::Index** mbranchindex855;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord857({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel858 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel858->getIndex(ord857, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord859({2, 0, 1});
      slog::Relation* readrel860 = db->getRelation("mp_union");
      mp_unionindex854 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({0, 1, 2, 3, 4});
      slog::Relation* readrel862 = db->getRelation("mbranch");
      mbranchindex855 = readrel862->getIndex(ord861, false);
  
    }
    ReadTask856(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c184 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        u64 v_c31 = _t[4];
        slog::join_probe<3,1>(mp_unionindex854, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m863) {
          u64 v_c185 = m863[1]; u64 v_c186 = m863[2];
          slog::join_probe<5,1>(mbranchindex855, std::array<u64,5>{v_c186, 0, 0, 0, 0}, [&](const std::array<u64,5>& m864) {
            u64 v_c27 = m864[1]; u64 v_c26 = m864[2]; u64 v_c25 = m864[3]; u64 v_c28 = m864[4];
            u64 v_c187 = _prim_lt(db, v_c26, v_c78);
            if (v_c187 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c187) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c78, v_c27, v_c185, v_c25, v_c26, v_c77, v_c28, v_c186, v_c184, v_c79, v_c31}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask856* _cont = new ReadTask856(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask856(db,b), false);
  // (crule (pre) (scan ref __t4vms664 x) (body (exists $sup70016x33x0x0x0 (3 1 0 2) 1 x) (exists eval (1 2 3 0) 1 __t4vms664) (join-old lookup (1 2 0) 1 (1 2 0) x rho __t03bu666) (exists eval (1 2 3 0) 2 __t4vms664 rho) (exists lookup_ans (0 1) 1 __t03bu666) (join $sup70016x33x0x0x0 (3 1 0 2) 2 x rho __t5crG665 t) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5crG665 __t4vms664) (join lookup_ans (0 1) 1 __t03bu666 __v0)) (head (emit eval_ans (0 1) __t5crG665 __v0)) interp.slog:34 #f)
  class ReadTask876 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x33x0x0x0index866;  slog::Index** evalindex867;  slog::Index** lookupindex868;  slog::Index** evalindex869;  slog::Index** lookup_ansindex870;  slog::Index** $sup70016x33x0x0x0index871;  slog::Index** evalindex872;  slog::Index** lookup_ansindex873;  slog::Index** lookupdelta874;  slog::Index** evaldelta875;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord877({0, 1});
      slog::Relation* readrel878 = db->getRelation("eval_ans");
      head_index[0] = readrel878->getIndex(ord877, false);
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord879({3, 1, 0, 2});
      slog::Relation* readrel880 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0index866 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 3, 0});
      slog::Relation* readrel882 = db->getRelation("eval");
      evalindex867 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("lookup");
      lookupindex868 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 0});
      slog::Relation* readrel886 = db->getRelation("lookup");
      lookupdelta874 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({1, 2, 3, 0});
      slog::Relation* readrel888 = db->getRelation("eval");
      evalindex869 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({0, 1});
      slog::Relation* readrel890 = db->getRelation("lookup_ans");
      lookup_ansindex870 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({3, 1, 0, 2});
      slog::Relation* readrel892 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0index871 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({2, 3, 0, 1});
      slog::Relation* readrel894 = db->getRelation("eval");
      evalindex872 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({2, 3, 0, 1});
      slog::Relation* readrel896 = db->getRelation("eval");
      evaldelta875 = readrel896->getIndex(ord895, true);
      std::vector<u16> ord897({0, 1});
      slog::Relation* readrel898 = db->getRelation("lookup_ans");
      lookup_ansindex873 = readrel898->getIndex(ord897, false);
  
    }
    ReadTask876(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c188 = _t[0];
        u64 v_c97 = _t[1];
        if (!slog::exists_probe<4,1>($sup70016x33x0x0x0index866, std::array<u64,4>{v_c97, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex867, std::array<u64,4>{v_c188, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(lookupindex868, lookupdelta874, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m899) {
          u64 v_c8 = m899[1]; u64 v_c189 = m899[2];
          if (!slog::exists_probe<4,2>(evalindex869, std::array<u64,4>{v_c188, v_c8, 0, 0})) return;
          if (!slog::exists_probe<2,1>(lookup_ansindex870, std::array<u64,2>{v_c189, 0})) return;
          slog::join_probe<4,2>($sup70016x33x0x0x0index871, std::array<u64,4>{v_c97, v_c8, 0, 0}, [&](const std::array<u64,4>& m900) {
            u64 v_c190 = m900[2]; u64 v_c9 = m900[3];
            slog::join_probe_old<4,4>(evalindex872, evaldelta875, std::array<u64,4>{v_c8, v_c9, v_c190, v_c188}, [&](const std::array<u64,4>& m901) {
              slog::join_probe<2,1>(lookup_ansindex873, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m902) {
                u64 v_c14 = m902[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c190, v_c14}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask876* _cont = new ReadTask876(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask876(db,b), false);
  // (crule (pre) (scan eval __1OTt1444 __t6NLj559 rho t) (body (join-old app (0 1 2) 1 (0 1 2) __t6NLj559 ef es)) (head (mkstruct eval (1 2 3 0) __7bjK1445 ef rho t)) interp.slog:59 #f)
  class ReadTask905 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex903;  slog::Index** appdelta904;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("app");
      appindex903 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({0, 1, 2});
      slog::Relation* readrel909 = db->getRelation("app");
      appdelta904 = readrel909->getIndex(ord908, true);
  
    }
    ReadTask905(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c191 = _t[0];
        u64 v_c192 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        slog::join_probe_old<3,1>(appindex903, appdelta904, std::array<u64,3>{v_c192, 0, 0}, [&](const std::array<u64,3>& m910) {
          u64 v_c40 = m910[1]; u64 v_c7 = m910[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c40, v_c8, v_c9}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask905* _cont = new ReadTask905(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask905(db,b), false);
  // (crule (pre) (scan app __t3yPA806 ef es) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t3yPA806 rho t __t5ODU807)) (head (emit $sup70016x75x0x0x0 (1 2 0 3 4) ef es __t5ODU807 rho t)) interp.slog:76 #f)
  class ReadTask913 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex911;  slog::Index** evaldelta912;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord914({1, 2, 0, 3, 4});
      slog::Relation* readrel915 = db->getRelation("$sup70016x75x0x0x0");
      head_index[0] = readrel915->getIndex(ord914, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord916({1, 2, 3, 0});
      slog::Relation* readrel917 = db->getRelation("eval");
      evalindex911 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 3, 0});
      slog::Relation* readrel919 = db->getRelation("eval");
      evaldelta912 = readrel919->getIndex(ord918, true);
  
    }
    ReadTask913(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c193 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe_old<4,1>(evalindex911, evaldelta912, std::array<u64,4>{v_c193, 0, 0, 0}, [&](const std::array<u64,4>& m920) {
          u64 v_c8 = m920[1]; u64 v_c9 = m920[2]; u64 v_c194 = m920[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c40, v_c7, v_c194, v_c8, v_c9}, std::array<u16,5>{1, 2, 0, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask913* _cont = new ReadTask913(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask913(db,b), false);
  // (crule (pre (let __tconst53B7217 const6b86b273ff34fce19d6b804e) (let __tconst86II214 constd4735e3a265e16eee03f5971)) (scan mp_hsb __t450F216 x) (body (cmp lt __tconst53B7217 x) (let __t3e5V215 (_0002f x __tconst86II214))) (head (emit-temp temp3nE61896 __t3e5V215)) map.slog:19 #f)
  class ReadTask921 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3nE61896");
      outer_rel = db->getRelation("mp_hsb");
  
    }
    ReadTask921(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c195 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c196 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c197 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c198 = _prim_lt(db, v_c195, v_c97);
        if (v_c198 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        if (!v_c198) return;
        u64 v_c199 = _prim__0002f(db, v_c97, v_c196);
        if (v_c199 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c199});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb", _fires);
  
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
  // (crule (pre) (scan mbranch __t8vmP99 p m l r) (body (join mp_union (1 2 0) 1 __t8vmP99 __t9QK9100 __t32Fx98) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t9QK9100 q n u v) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t32Fx98 l m q r __t8vmP99 __t9QK9100 u v)) map.slog:111 #f)
  class ReadTask926 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex923;  slog::Index** mbranchindex924;  slog::Index** mbranchdelta925;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord927({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel928 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel928->getIndex(ord927, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord929({1, 2, 0});
      slog::Relation* readrel930 = db->getRelation("mp_union");
      mp_unionindex923 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({0, 1, 2, 3, 4});
      slog::Relation* readrel932 = db->getRelation("mbranch");
      mbranchindex924 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({0, 1, 2, 3, 4});
      slog::Relation* readrel934 = db->getRelation("mbranch");
      mbranchdelta925 = readrel934->getIndex(ord933, true);
  
    }
    ReadTask926(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c186 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c28 = _t[4];
        slog::join_probe<3,1>(mp_unionindex923, std::array<u64,3>{v_c186, 0, 0}, [&](const std::array<u64,3>& m935) {
          u64 v_c184 = m935[1]; u64 v_c185 = m935[2];
          slog::join_probe_old<5,1>(mbranchindex924, mbranchdelta925, std::array<u64,5>{v_c184, 0, 0, 0, 0}, [&](const std::array<u64,5>& m936) {
            u64 v_c77 = m936[1]; u64 v_c78 = m936[2]; u64 v_c79 = m936[3]; u64 v_c31 = m936[4];
            u64 v_c200 = _prim_lt(db, v_c26, v_c78);
            if (v_c200 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c200) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c78, v_c27, v_c185, v_c25, v_c26, v_c77, v_c28, v_c186, v_c184, v_c79, v_c31}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask926* _cont = new ReadTask926(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask926(db,b), false);
  // (crule (pre) (scan $sup70016x75x0x0x0 __t8Dhb337 ef es rho t) (body (exists app (1 2 0) 2 ef es) (exists eval (1 2 3 0) 3 ef rho t) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t8Dhb337 __t87KU336) (join-old app (0 1 2) 3 (0 1 2) __t87KU336 ef es) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t8KmI338) (exists eval_ans (0 1) 1 __t8KmI338) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t24hv340) (exists eval_args_ans (0 1) 1 __t24hv340) (join eval_ans (0 1) 1 __t8KmI338 __t1N6L339) (join eval_args_ans (0 1) 1 __t24hv340 vs) (exists delta (2 0 1) 1 vs) (join-old prim (0 1) 1 (0 1) __t1N6L339 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t9Mk1341) (join delta_ans (0 1) 1 __t9Mk1341 v)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask959 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex938;  slog::Index** evalindex939;  slog::Index** eval_argsindex940;  slog::Index** evalindex941;  slog::Index** appindex942;  slog::Index** evalindex943;  slog::Index** eval_ansindex944;  slog::Index** eval_argsindex945;  slog::Index** eval_args_ansindex946;  slog::Index** eval_ansindex947;  slog::Index** eval_args_ansindex948;  slog::Index** deltaindex949;  slog::Index** primindex950;  slog::Index** deltaindex951;  slog::Index** delta_ansindex952;  slog::Index** evaldelta953;  slog::Index** appdelta954;  slog::Index** evaldelta955;  slog::Index** eval_argsdelta956;  slog::Index** primdelta957;  slog::Index** deltadelta958;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord960({0, 1});
      slog::Relation* readrel961 = db->getRelation("eval_ans");
      head_index[0] = readrel961->getIndex(ord960, false);
      outer_rel = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord962({1, 2, 0});
      slog::Relation* readrel963 = db->getRelation("app");
      appindex938 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({1, 2, 3, 0});
      slog::Relation* readrel965 = db->getRelation("eval");
      evalindex939 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 3, 2, 0});
      slog::Relation* readrel967 = db->getRelation("eval_args");
      eval_argsindex940 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({2, 3, 0, 1});
      slog::Relation* readrel969 = db->getRelation("eval");
      evalindex941 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({2, 3, 0, 1});
      slog::Relation* readrel971 = db->getRelation("eval");
      evaldelta953 = readrel971->getIndex(ord970, true);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("app");
      appindex942 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({0, 1, 2});
      slog::Relation* readrel975 = db->getRelation("app");
      appdelta954 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({1, 2, 3, 0});
      slog::Relation* readrel977 = db->getRelation("eval");
      evalindex943 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({1, 2, 3, 0});
      slog::Relation* readrel979 = db->getRelation("eval");
      evaldelta955 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({0, 1});
      slog::Relation* readrel981 = db->getRelation("eval_ans");
      eval_ansindex944 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 3, 2, 0});
      slog::Relation* readrel983 = db->getRelation("eval_args");
      eval_argsindex945 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({1, 3, 2, 0});
      slog::Relation* readrel985 = db->getRelation("eval_args");
      eval_argsdelta956 = readrel985->getIndex(ord984, true);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("eval_args_ans");
      eval_args_ansindex946 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("eval_ans");
      eval_ansindex947 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({0, 1});
      slog::Relation* readrel991 = db->getRelation("eval_args_ans");
      eval_args_ansindex948 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({2, 0, 1});
      slog::Relation* readrel993 = db->getRelation("delta");
      deltaindex949 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({0, 1});
      slog::Relation* readrel995 = db->getRelation("prim");
      primindex950 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({0, 1});
      slog::Relation* readrel997 = db->getRelation("prim");
      primdelta957 = readrel997->getIndex(ord996, true);
      std::vector<u16> ord998({1, 2, 0});
      slog::Relation* readrel999 = db->getRelation("delta");
      deltaindex951 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 2, 0});
      slog::Relation* readrel1001 = db->getRelation("delta");
      deltadelta958 = readrel1001->getIndex(ord1000, true);
      std::vector<u16> ord1002({0, 1});
      slog::Relation* readrel1003 = db->getRelation("delta_ans");
      delta_ansindex952 = readrel1003->getIndex(ord1002, false);
  
    }
    ReadTask959(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        if (!slog::exists_probe<3,2>(appindex938, std::array<u64,3>{v_c40, v_c7, 0})) return;
        if (!slog::exists_probe<4,3>(evalindex939, std::array<u64,4>{v_c40, v_c8, v_c9, 0})) return;
        if (!slog::exists_probe<4,3>(eval_argsindex940, std::array<u64,4>{v_c7, v_c9, v_c8, 0})) return;
        slog::join_probe_old<4,3>(evalindex941, evaldelta953, std::array<u64,4>{v_c8, v_c9, v_c41, 0}, [&](const std::array<u64,4>& m1004) {
          u64 v_c42 = m1004[3];
          slog::join_probe_old<3,3>(appindex942, appdelta954, std::array<u64,3>{v_c42, v_c40, v_c7}, [&](const std::array<u64,3>& m1005) {
            slog::join_probe_old<4,3>(evalindex943, evaldelta955, std::array<u64,4>{v_c40, v_c8, v_c9, 0}, [&](const std::array<u64,4>& m1006) {
              u64 v_c39 = m1006[3];
              if (!slog::exists_probe<2,1>(eval_ansindex944, std::array<u64,2>{v_c39, 0})) return;
              slog::join_probe_old<4,3>(eval_argsindex945, eval_argsdelta956, std::array<u64,4>{v_c7, v_c9, v_c8, 0}, [&](const std::array<u64,4>& m1007) {
                u64 v_c37 = m1007[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex946, std::array<u64,2>{v_c37, 0})) return;
                slog::join_probe<2,1>(eval_ansindex947, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m1008) {
                  u64 v_c38 = m1008[1];
                  slog::join_probe<2,1>(eval_args_ansindex948, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m1009) {
                    u64 v_c36 = m1009[1];
                    if (!slog::exists_probe<3,1>(deltaindex949, std::array<u64,3>{v_c36, 0, 0})) return;
                    slog::join_probe_old<2,1>(primindex950, primdelta957, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m1010) {
                      u64 v_c35 = m1010[1];
                      slog::join_probe_old<3,2>(deltaindex951, deltadelta958, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m1011) {
                        u64 v_c34 = m1011[2];
                        slog::join_probe<2,1>(delta_ansindex952, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m1012) {
                          u64 v_c31 = m1012[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c31}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:$sup70016x75x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask959* _cont = new ReadTask959(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask959(db,b), false);
  // (crule (pre (let __tconst6pJx1346 constb9e118781cea1f9fa01462e0) (let __tconst62iD1347 const0122baa3ac55f1b433944eb1) (let __tconst3W5V576 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0LoQ973 const6b86b273ff34fce19d6b804e) (let _00024sqc1LSK974 const5feceb66ffc86f38d952786c) (let _00024sqo9raf975 const5feceb66ffc86f38d952786c) (let _00024sqo4FnC976 const5feceb66ffc86f38d952786c)) (scan boolval __t9AVR579 __t18UG578) (body (join _enum (0 1) 2 __t18UG578 __tconst6pJx1346) (exists $seq_atr (1 0 2) 2 _00024sqo4FnC976 __t9AVR579) (exists delta (1 2 0) 1 __tconst3W5V576) (exists _enum (1 0) 1 __tconst62iD1347) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo9raf975 __t9AVR579 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4FnC976 __t9AVR579 _00024seq1) (join delta (1 2 0) 2 __tconst3W5V576 _00024seq1 __t9o8A577) (join _enum (1 0) 1 __tconst62iD1347 __t2cB8574) (letp _00024sql99sk971 (aslst _00024seq1)) (let chk1nIf2065 (llen _00024sql99sk971)) (eq _00024sqc0LoQ973 chk1nIf2065) (letp chk0T6y2066 (lref _00024sql99sk971 _00024sqc1LSK974)) (eq __t9AVR579 chk0T6y2066)) (head (emit-temp temp7pkd2063 __t9o8A577) (mkstruct boolval (1 0) __t7CgS575 __t2cB8574)) interp.slog:118 #f)
  class ReadTask1023 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1013;  slog::Index** $seq_atrindex1014;  slog::Index** deltaindex1015;  slog::Index** _enumindex1016;  slog::Index** $seq_atindex1017;  slog::Index** $seq_atrindex1018;  slog::Index** deltaindex1019;  slog::Index** _enumindex1020;  slog::Index** $seq_atdelta1021;  slog::Index** $seq_atrdelta1022;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7pkd2063");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord1024({0, 1});
      slog::Relation* readrel1025 = db->getRelation("_enum");
      _enumindex1013 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 0, 2});
      slog::Relation* readrel1027 = db->getRelation("$seq_atr");
      $seq_atrindex1014 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 2, 0});
      slog::Relation* readrel1029 = db->getRelation("delta");
      deltaindex1015 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 0});
      slog::Relation* readrel1031 = db->getRelation("_enum");
      _enumindex1016 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 0, 2});
      slog::Relation* readrel1033 = db->getRelation("$seq_at");
      $seq_atindex1017 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({1, 0, 2});
      slog::Relation* readrel1035 = db->getRelation("$seq_at");
      $seq_atdelta1021 = readrel1035->getIndex(ord1034, true);
      std::vector<u16> ord1036({1, 0, 2});
      slog::Relation* readrel1037 = db->getRelation("$seq_atr");
      $seq_atrindex1018 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({1, 0, 2});
      slog::Relation* readrel1039 = db->getRelation("$seq_atr");
      $seq_atrdelta1022 = readrel1039->getIndex(ord1038, true);
      std::vector<u16> ord1040({1, 2, 0});
      slog::Relation* readrel1041 = db->getRelation("delta");
      deltaindex1019 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 0});
      slog::Relation* readrel1043 = db->getRelation("_enum");
      _enumindex1020 = readrel1043->getIndex(ord1042, false);
  
    }
    ReadTask1023(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c201 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c202 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c203 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c204 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c205 = v_const5feceb66ffc86f38d952786c;
      u64 v_c206 = v_const5feceb66ffc86f38d952786c;
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c208 = _t[0];
        u64 v_c209 = _t[1];
        slog::join_probe<2,2>(_enumindex1013, std::array<u64,2>{v_c209, v_c201}, [&](const std::array<u64,2>& m1044) {
          if (!slog::exists_probe<3,2>($seq_atrindex1014, std::array<u64,3>{v_c207, v_c208, 0})) return;
          if (!slog::exists_probe<3,1>(deltaindex1015, std::array<u64,3>{v_c203, 0, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex1016, std::array<u64,2>{v_c202, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex1017, $seq_atdelta1021, std::array<u64,3>{v_c206, v_c208, 0}, [&](const std::array<u64,3>& m1045) {
            u64 v_c210 = m1045[2];
            slog::join_probe_old<3,3>($seq_atrindex1018, $seq_atrdelta1022, std::array<u64,3>{v_c207, v_c208, v_c210}, [&](const std::array<u64,3>& m1046) {
              slog::join_probe<3,2>(deltaindex1019, std::array<u64,3>{v_c203, v_c210, 0}, [&](const std::array<u64,3>& m1047) {
                u64 v_c211 = m1047[2];
                slog::join_probe<2,1>(_enumindex1020, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m1048) {
                  u64 v_c212 = m1048[1];
                  bool ok1049 = true;
                  u64 v_c213 = _prim_aslst(db, v_c210, &ok1049);
                  if (!ok1049) return;
                  u64 v_c214 = _prim_llen(db, v_c213);
                  if (v_c214 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                  if (v_c204 != v_c214) return;
                  bool ok1050 = true;
                  u64 v_c215 = _prim_lref(db, v_c213, v_c205, &ok1050);
                  if (!ok1050) return;
                  if (v_c208 != v_c215) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c211});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c212}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask1023* _cont = new ReadTask1023(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1023(db,b), false);
  // (crule (pre (let __tconst6uLy1418 constcd2a69ce5ca278db1d6da969) (let _00024sqc5ZED979 constd4735e3a265e16eee03f5971) (let _00024sqc8Ktf980 const5feceb66ffc86f38d952786c) (let _00024sqc1r6Y981 const6b86b273ff34fce19d6b804e) (let _00024sqo4ml8982 const5feceb66ffc86f38d952786c) (let _00024sqo9GuQ983 const6b86b273ff34fce19d6b804e) (let _00024sqo9DrV984 const6b86b273ff34fce19d6b804e) (let _00024sqo0wvc985 const5feceb66ffc86f38d952786c) (let __trid2ZoU1419 constfdb0a95399e17c48d6f65653) (let __trel2kf41420 constdede4476644eb06b5a48b866) (let __tcol0QrU1421 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo0wvc985 __t0ebd433 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4ml8982 __t0ebd433 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo9GuQ983 __t0ebd433 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo9DrV984 __t0ebd433 _00024seq2) (join _enum (0 1) 2 __t0ebd433 __tconst6uLy1418) (join delta (2 0 1) 1 _00024seq2 __t9b4a431 op) (join arithmetic_op (0) 1 op) (letp _00024sql4NVe977 (aslst _00024seq2)) (let chk4nAd1868 (llen _00024sql4NVe977)) (eq _00024sqc5ZED979 chk4nAd1868) (letp chk6zHW1869 (lref _00024sql4NVe977 _00024sqc8Ktf980)) (eq __t0ebd433 chk6zHW1869) (letp chk1y6z1870 (lref _00024sql4NVe977 _00024sqc1r6Y981)) (eq __t0ebd433 chk1y6z1870)) (head (tycheck __t0ebd433 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2ZoU1419 __trel2kf41420 __tcol0QrU1421 (1 2 3 4 0)) (emit delta_ans (0 1) __t9b4a431 __t0ebd433)) interp.slog:116 #f)
  class ReadTask1062 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1051;  slog::Index** $seq_atindex1052;  slog::Index** $seq_atrindex1053;  slog::Index** _enumindex1054;  slog::Index** deltaindex1055;  slog::Index** arithmetic_opindex1056;
    u32 sid1059;  u32 sid1057;  u32 sid1058;  u32 sid1060;  u32 sid1061;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1063({0, 1});
      slog::Relation* readrel1064 = db->getRelation("delta_ans");
      head_index[1] = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({1, 0, 2});
      slog::Relation* readrel1066 = db->getRelation("$seq_atr");
      driver_index = readrel1066->getIndex(ord1065, true);
      std::vector<u16> ord1067({1, 0, 2});
      slog::Relation* readrel1068 = db->getRelation("$seq_at");
      $seq_atindex1051 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 0, 2});
      slog::Relation* readrel1070 = db->getRelation("$seq_at");
      $seq_atindex1052 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({1, 0, 2});
      slog::Relation* readrel1072 = db->getRelation("$seq_atr");
      $seq_atrindex1053 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({0, 1});
      slog::Relation* readrel1074 = db->getRelation("_enum");
      _enumindex1054 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({2, 0, 1});
      slog::Relation* readrel1076 = db->getRelation("delta");
      deltaindex1055 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({0});
      slog::Relation* readrel1078 = db->getRelation("arithmetic_op");
      arithmetic_opindex1056 = readrel1078->getIndex(ord1077, false);
      sid1059 = db->getRelation("_enum")->getStructId();
      sid1057 = db->getRelation("boolval")->getStructId();
      sid1058 = db->getRelation("closure")->getStructId();
      sid1060 = db->getRelation("prim")->getStructId();
      sid1061 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1062(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c216 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c217 = v_constd4735e3a265e16eee03f5971;
      u64 v_c218 = v_const5feceb66ffc86f38d952786c;
      u64 v_c219 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c220 = v_const5feceb66ffc86f38d952786c;
      u64 v_c221 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c222 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c223 = v_const5feceb66ffc86f38d952786c;
      u64 v_c224 = v_constfdb0a95399e17c48d6f65653;
      u64 v_c225 = v_constdede4476644eb06b5a48b866;
      u64 v_c226 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c223, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1079) {
        u64 v_c227 = m1079[1];
        u64 v_c164 = m1079[2];
        if (buckethash(v_c227) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1051, std::array<u64,3>{v_c220, v_c227, v_c164}, [&](const std::array<u64,3>& m1080) {
          slog::join_probe<3,3>($seq_atindex1052, std::array<u64,3>{v_c221, v_c227, v_c164}, [&](const std::array<u64,3>& m1081) {
            slog::join_probe<3,3>($seq_atrindex1053, std::array<u64,3>{v_c222, v_c227, v_c164}, [&](const std::array<u64,3>& m1082) {
              slog::join_probe<2,2>(_enumindex1054, std::array<u64,2>{v_c227, v_c216}, [&](const std::array<u64,2>& m1083) {
                slog::join_probe<3,1>(deltaindex1055, std::array<u64,3>{v_c164, 0, 0}, [&](const std::array<u64,3>& m1084) {
                  u64 v_c228 = m1084[1]; u64 v_c35 = m1084[2];
                  slog::join_probe<1,1>(arithmetic_opindex1056, std::array<u64,1>{v_c35}, [&](const std::array<u64,1>& m1085) {
                    bool ok1086 = true;
                    u64 v_c229 = _prim_aslst(db, v_c164, &ok1086);
                    if (!ok1086) return;
                    u64 v_c230 = _prim_llen(db, v_c229);
                    if (v_c230 == slog_error) { slog::emit_pending_error(db, "interp.slog:116"); return; }
                    if (v_c217 != v_c230) return;
                    bool ok1087 = true;
                    u64 v_c231 = _prim_lref(db, v_c229, v_c218, &ok1087);
                    if (!ok1087) return;
                    if (v_c227 != v_c231) return;
                    bool ok1088 = true;
                    u64 v_c232 = _prim_lref(db, v_c229, v_c219, &ok1088);
                    if (!ok1088) return;
                    if (v_c227 != v_c232) return;
                    ++_fires;
                    if (!((is_struct(v_c227) && (decode_struct_id(v_c227) == sid1057 || decode_struct_id(v_c227) == sid1058 || decode_struct_id(v_c227) == sid1059 || decode_struct_id(v_c227) == sid1060 || decode_struct_id(v_c227) == sid1061))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c224, v_c225, v_c226, v_c227}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c228, v_c227}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:116", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1062* _cont = new ReadTask1062(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1062(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t2ONI329 k m) (body (exists $sup5638x60x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t2ONI329 p) (exists mbranch (1 2 3 4 0) 2 p m) (join $sup5638x60x0x0x0 (1 3 4 0 2 5) 3 k m p __t6Aa9325 l r) (exists mp_has0 (0 2 1) 2 __t6Aa9325 k) (exists mp_has0 (1 2 0) 2 l k) (join mbranch (1 2 3 4 0) 4 p m l r __t0WBy324) (join mp_has0 (0 2 1) 3 __t6Aa9325 k __t0WBy324) (join mp_has0 (1 2 0) 2 l k __t81Rn328) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask1101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index1089;  slog::Index** mbranchindex1090;  slog::Index** mp_has0index1091;  slog::Index** mp_msk_ansindex1092;  slog::Index** mbranchindex1093;  slog::Index** $sup5638x60x0x0x0index1094;  slog::Index** mp_has0index1095;  slog::Index** mp_has0index1096;  slog::Index** mbranchindex1097;  slog::Index** mp_has0index1098;  slog::Index** mp_has0index1099;  slog::Index** mp_has0_ansindex1100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1102({0, 1});
      slog::Relation* readrel1103 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1103->getIndex(ord1102, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1104({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1105 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index1089 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({2, 0, 1, 3, 4});
      slog::Relation* readrel1107 = db->getRelation("mbranch");
      mbranchindex1090 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({2, 0, 1});
      slog::Relation* readrel1109 = db->getRelation("mp_has0");
      mp_has0index1091 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({0, 1});
      slog::Relation* readrel1111 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1092 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 2, 3, 4, 0});
      slog::Relation* readrel1113 = db->getRelation("mbranch");
      mbranchindex1093 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1115 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index1094 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({0, 2, 1});
      slog::Relation* readrel1117 = db->getRelation("mp_has0");
      mp_has0index1095 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 2, 0});
      slog::Relation* readrel1119 = db->getRelation("mp_has0");
      mp_has0index1096 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 2, 3, 4, 0});
      slog::Relation* readrel1121 = db->getRelation("mbranch");
      mbranchindex1097 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({0, 2, 1});
      slog::Relation* readrel1123 = db->getRelation("mp_has0");
      mp_has0index1098 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 2, 0});
      slog::Relation* readrel1125 = db->getRelation("mp_has0");
      mp_has0index1099 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({0, 1});
      slog::Relation* readrel1127 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1100 = readrel1127->getIndex(ord1126, false);
  
    }
    ReadTask1101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c26 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x60x0x0x0index1089, std::array<u64,6>{v_c24, v_c26, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1090, std::array<u64,5>{v_c26, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index1091, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1092, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m1128) {
          u64 v_c27 = m1128[1];
          if (!slog::exists_probe<5,2>(mbranchindex1093, std::array<u64,5>{v_c27, v_c26, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x60x0x0x0index1094, std::array<u64,6>{v_c24, v_c26, v_c27, 0, 0, 0}, [&](const std::array<u64,6>& m1129) {
            u64 v_c44 = m1129[3]; u64 v_c25 = m1129[4]; u64 v_c28 = m1129[5];
            if (!slog::exists_probe<3,2>(mp_has0index1095, std::array<u64,3>{v_c44, v_c24, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index1096, std::array<u64,3>{v_c25, v_c24, 0})) return;
            slog::join_probe<5,4>(mbranchindex1097, std::array<u64,5>{v_c27, v_c26, v_c25, v_c28, 0}, [&](const std::array<u64,5>& m1130) {
              u64 v_c45 = m1130[4];
              slog::join_probe<3,3>(mp_has0index1098, std::array<u64,3>{v_c44, v_c24, v_c45}, [&](const std::array<u64,3>& m1131) {
                slog::join_probe<3,2>(mp_has0index1099, std::array<u64,3>{v_c25, v_c24, 0}, [&](const std::array<u64,3>& m1132) {
                  u64 v_c46 = m1132[2];
                  slog::join_probe<2,1>(mp_has0_ansindex1100, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m1133) {
                    u64 v_c48 = m1133[1];
                    u64 v_c49 = _prim_band(db, v_c24, v_c26);
                    if (v_c49 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c233 = _prim_lt(db, v_c49, v_c43);
                    if (v_c233 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c233) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c48}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1101* _cont = new ReadTask1101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1101(db,b), false);
  // (crule (pre (let __trid7eCK1088 const07d7fbed0aba019c07f7eb8a) (let __trel2iiF1089 const20347926ddb307a8e2bdb71b) (let __tcol0Wnu1090 const4e07408562bedb8b60ce05c1)) (scan mp_msk __t9pQc287 k m) (body (exists $sup5638x82x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t9pQc287 p) (join $sup5638x82x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t6EHL288) (join mp_del_ans (0 1) 1 __t6EHL288 __v0)) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7eCK1088 __trel2iiF1089 __tcol0Wnu1090 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __4RjO1087 p m __v0 r)) map.slog:83 #f)
  class ReadTask1145 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index1135;  slog::Index** mp_delindex1136;  slog::Index** mp_msk_ansindex1137;  slog::Index** $sup5638x82x0x0x0index1138;  slog::Index** mp_delindex1139;  slog::Index** mp_del_ansindex1140;  slog::Index** mp_deldelta1141;
    u32 sid1143;  u32 sid1142;  u32 sid1144;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1146({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1147 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1135 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({2, 0, 1});
      slog::Relation* readrel1149 = db->getRelation("mp_del");
      mp_delindex1136 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({0, 1});
      slog::Relation* readrel1151 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1137 = readrel1151->getIndex(ord1150, false);
      std::vector<u16> ord1152({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1153 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1138 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({1, 2, 0});
      slog::Relation* readrel1155 = db->getRelation("mp_del");
      mp_delindex1139 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({1, 2, 0});
      slog::Relation* readrel1157 = db->getRelation("mp_del");
      mp_deldelta1141 = readrel1157->getIndex(ord1156, true);
      std::vector<u16> ord1158({0, 1});
      slog::Relation* readrel1159 = db->getRelation("mp_del_ans");
      mp_del_ansindex1140 = readrel1159->getIndex(ord1158, false);
      sid1143 = db->getRelation("_enum")->getStructId();
      sid1142 = db->getRelation("mbranch")->getStructId();
      sid1144 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1145(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c234 = v_const07d7fbed0aba019c07f7eb8a;
      u64 v_c235 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c236 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c237 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c26 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index1135, std::array<u64,6>{v_c24, v_c26, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex1136, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1137, std::array<u64,2>{v_c237, 0}, [&](const std::array<u64,2>& m1160) {
          u64 v_c27 = m1160[1];
          slog::join_probe<6,3>($sup5638x82x0x0x0index1138, std::array<u64,6>{v_c24, v_c26, v_c27, 0, 0, 0}, [&](const std::array<u64,6>& m1161) {
            u64 v_c64 = m1161[3]; u64 v_c25 = m1161[4]; u64 v_c28 = m1161[5];
            slog::join_probe_old<3,2>(mp_delindex1139, mp_deldelta1141, std::array<u64,3>{v_c25, v_c24, 0}, [&](const std::array<u64,3>& m1162) {
              u64 v_c238 = m1162[2];
              slog::join_probe<2,1>(mp_del_ansindex1140, std::array<u64,2>{v_c238, 0}, [&](const std::array<u64,2>& m1163) {
                u64 v_c14 = m1163[1];
                ++_fires;
                if (!((is_struct(v_c28) && (decode_struct_id(v_c28) == sid1142 || decode_struct_id(v_c28) == sid1143 || decode_struct_id(v_c28) == sid1144))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c234, v_c235, v_c236, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c26, v_c14, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1145* _cont = new ReadTask1145(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1145(db,b), false);
  // (crule (pre (let __trid4Cw71231 constaa218622af4adb846b2d6244) (let __trel6Rfo1232 const4a59dbb9cb3129dfcc75170b) (let __tcol2HWo1233 const5feceb66ffc86f38d952786c) (let __trel8FF11234 const4a59dbb9cb3129dfcc75170b) (let __tcol2yNn1235 const6b86b273ff34fce19d6b804e) (let __trel5WVi1236 const4a59dbb9cb3129dfcc75170b) (let __tcol0jym1237 constd4735e3a265e16eee03f5971)) (scan $sup70016x87x0x0x0 __d0 e1 e2 e3 rho t) (body) (head (tycheck e1 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid4Cw71231 __trel6Rfo1232 __tcol2HWo1233 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4Cw71231 __trel8FF11234 __tcol2yNn1235 (1 2 3 4 0)) (tycheck t (accept seq) __trid4Cw71231 __trel5WVi1236 __tcol0jym1237 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __2OgY1230 e1 rho t)) interp.slog:88 #f)
  class ReadTask1177 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1175;  u32 sid1164;  u32 sid1165;  u32 sid1166;  u32 sid1167;  u32 sid1168;  u32 sid1169;  u32 sid1174;  u32 sid1176;  u32 sid1170;  u32 sid1171;  u32 sid1172;  u32 sid1173;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x87x0x0x0");
      sid1175 = db->getRelation("_enum")->getStructId();
      sid1164 = db->getRelation("app")->getStructId();
      sid1165 = db->getRelation("boolean")->getStructId();
      sid1166 = db->getRelation("if")->getStructId();
      sid1167 = db->getRelation("lambda")->getStructId();
      sid1168 = db->getRelation("let")->getStructId();
      sid1169 = db->getRelation("letrec")->getStructId();
      sid1174 = db->getRelation("mbranch")->getStructId();
      sid1176 = db->getRelation("mleaf")->getStructId();
      sid1170 = db->getRelation("num")->getStructId();
      sid1171 = db->getRelation("primref")->getStructId();
      sid1172 = db->getRelation("ref")->getStructId();
      sid1173 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1177(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c239 = v_constaa218622af4adb846b2d6244;
      u64 v_c240 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c241 = v_const5feceb66ffc86f38d952786c;
      u64 v_c242 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c243 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c244 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c245 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c64 = _t[0];
        u64 v_c246 = _t[1];
        u64 v_c247 = _t[2];
        u64 v_c248 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c9 = _t[5];
        ++_fires;
        if (!((is_struct(v_c246) && (decode_struct_id(v_c246) == sid1164 || decode_struct_id(v_c246) == sid1165 || decode_struct_id(v_c246) == sid1166 || decode_struct_id(v_c246) == sid1167 || decode_struct_id(v_c246) == sid1168 || decode_struct_id(v_c246) == sid1169 || decode_struct_id(v_c246) == sid1170 || decode_struct_id(v_c246) == sid1171 || decode_struct_id(v_c246) == sid1172 || decode_struct_id(v_c246) == sid1173))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c239, v_c240, v_c241, v_c246}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid1174 || decode_struct_id(v_c8) == sid1175 || decode_struct_id(v_c8) == sid1176))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c239, v_c242, v_c243, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c239, v_c244, v_c245, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c246, v_c8, v_c9}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:$sup70016x87x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1177* _cont = new ReadTask1177(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1177(db,b), false);
  // (crule (pre (let __trid8qtc1109 constc742e02805b99df617265a41) (let __trel1ESJ1110 const7f254967624b26d820569bd6) (let __tcol1Eip1111 const5feceb66ffc86f38d952786c) (let __trel3kWp1112 const72bac24066bb34077c1f6e71) (let __tcol0ClE1113 const5feceb66ffc86f38d952786c) (let __trel7YG31114 const72bac24066bb34077c1f6e71) (let __tcol4mfT1115 const6b86b273ff34fce19d6b804e) (let __trel118x1116 const72bac24066bb34077c1f6e71) (let __tcol8dNC1117 constd4735e3a265e16eee03f5971) (let __trel1ig71118 const72bac24066bb34077c1f6e71) (let __tcol2jT21119 const4e07408562bedb8b60ce05c1)) (scan $sup5638x95x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8qtc1109 __trel1ESJ1110 __tcol1Eip1111 (1 2 3 4 0)) (tycheck q (accept int) __trid8qtc1109 __trel3kWp1112 __tcol0ClE1113 (1 2 3 4 0)) (tycheck n (accept int) __trid8qtc1109 __trel7YG31114 __tcol4mfT1115 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8qtc1109 __trel118x1116 __tcol8dNC1117 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8qtc1109 __trel1ig71118 __tcol2jT21119 (1 2 3 4 0)) (emit-temp temp05ov2047 l n q u v) (mkstruct mbranch (1 2 3 4 0) __t5MWB602 q n u v)) map.slog:96 #f)
  class ReadTask1181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1179;  u32 sid1178;  u32 sid1180;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp05ov2047");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x1");
      sid1179 = db->getRelation("_enum")->getStructId();
      sid1178 = db->getRelation("mbranch")->getStructId();
      sid1180 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c249 = v_constc742e02805b99df617265a41;
      u64 v_c250 = v_const7f254967624b26d820569bd6;
      u64 v_c251 = v_const5feceb66ffc86f38d952786c;
      u64 v_c252 = v_const72bac24066bb34077c1f6e71;
      u64 v_c253 = v_const5feceb66ffc86f38d952786c;
      u64 v_c254 = v_const72bac24066bb34077c1f6e71;
      u64 v_c255 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c256 = v_const72bac24066bb34077c1f6e71;
      u64 v_c257 = v_constd4735e3a265e16eee03f5971;
      u64 v_c258 = v_const72bac24066bb34077c1f6e71;
      u64 v_c259 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c64 = _t[0];
        u64 v_c123 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c78 = _t[4];
        u64 v_c27 = _t[5];
        u64 v_c77 = _t[6];
        u64 v_c28 = _t[7];
        u64 v_c79 = _t[8];
        u64 v_c31 = _t[9];
        ++_fires;
        if (!((is_struct(v_c25) && (decode_struct_id(v_c25) == sid1178 || decode_struct_id(v_c25) == sid1179 || decode_struct_id(v_c25) == sid1180))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c249, v_c250, v_c251, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c77)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c249, v_c252, v_c253, v_c77}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c78)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c249, v_c254, v_c255, v_c78}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c79) && (decode_struct_id(v_c79) == sid1178 || decode_struct_id(v_c79) == sid1179 || decode_struct_id(v_c79) == sid1180))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c249, v_c256, v_c257, v_c79}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c31) && (decode_struct_id(v_c31) == sid1178 || decode_struct_id(v_c31) == sid1179 || decode_struct_id(v_c31) == sid1180))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c249, v_c258, v_c259, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c25, v_c78, v_c77, v_c79, v_c31});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c77, v_c78, v_c79, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1181* _cont = new ReadTask1181(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1181(db,b), false);
  // (crule (pre (let __tconst49eD1184 constcd2a69ce5ca278db1d6da969) (let __tconst7GbT659 const06abaa100ecef791ce028c56) (let _00024sqc0jJd1013 constd4735e3a265e16eee03f5971) (let _00024sqc54us1014 const5feceb66ffc86f38d952786c) (let _00024sqc6uOX1015 const6b86b273ff34fce19d6b804e) (let _00024sqo8ZRa1016 const5feceb66ffc86f38d952786c) (let _00024sqo9lkw1017 const6b86b273ff34fce19d6b804e) (let _00024sqo8so11018 const6b86b273ff34fce19d6b804e) (let _00024sqo0qa11019 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo0qa11019 __t013P662 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8ZRa1016 __t013P662 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo9lkw1017 __t013P662 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo8so11018 __t013P662 _00024seq2) (join _enum (0 1) 2 __t013P662 __tconst49eD1184) (join delta (1 2 0) 2 __tconst7GbT659 _00024seq2 __t6erK660) (join any_bool (0) 0 b) (letp _00024sql99Ol1011 (aslst _00024seq2)) (let chk2Rvf1790 (llen _00024sql99Ol1011)) (eq _00024sqc0jJd1013 chk2Rvf1790) (letp chk2xff1791 (lref _00024sql99Ol1011 _00024sqc54us1014)) (eq __t013P662 chk2xff1791) (letp chk2PiQ1792 (lref _00024sql99Ol1011 _00024sqc6uOX1015)) (eq __t013P662 chk2PiQ1792)) (head (emit-temp temp3q8l1778 __t6erK660 b) (mkstruct boolval (1 0) __t5eIx658 b)) interp.slog:125 #f)
  class ReadTask1188 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1182;  slog::Index** $seq_atindex1183;  slog::Index** $seq_atrindex1184;  slog::Index** _enumindex1185;  slog::Index** deltaindex1186;  slog::Index** any_boolindex1187;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3q8l1778");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1189({1, 0, 2});
      slog::Relation* readrel1190 = db->getRelation("$seq_atr");
      driver_index = readrel1190->getIndex(ord1189, true);
      std::vector<u16> ord1191({1, 0, 2});
      slog::Relation* readrel1192 = db->getRelation("$seq_at");
      $seq_atindex1182 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({1, 0, 2});
      slog::Relation* readrel1194 = db->getRelation("$seq_at");
      $seq_atindex1183 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 0, 2});
      slog::Relation* readrel1196 = db->getRelation("$seq_atr");
      $seq_atrindex1184 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({0, 1});
      slog::Relation* readrel1198 = db->getRelation("_enum");
      _enumindex1185 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 2, 0});
      slog::Relation* readrel1200 = db->getRelation("delta");
      deltaindex1186 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({0});
      slog::Relation* readrel1202 = db->getRelation("any_bool");
      any_boolindex1187 = readrel1202->getIndex(ord1201, false);
  
    }
    ReadTask1188(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c261 = v_const06abaa100ecef791ce028c56;
      u64 v_c262 = v_constd4735e3a265e16eee03f5971;
      u64 v_c263 = v_const5feceb66ffc86f38d952786c;
      u64 v_c264 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c265 = v_const5feceb66ffc86f38d952786c;
      u64 v_c266 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c267 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c268 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c268, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1203) {
        u64 v_c269 = m1203[1];
        u64 v_c164 = m1203[2];
        if (buckethash(v_c269) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1182, std::array<u64,3>{v_c265, v_c269, v_c164}, [&](const std::array<u64,3>& m1204) {
          slog::join_probe<3,3>($seq_atindex1183, std::array<u64,3>{v_c266, v_c269, v_c164}, [&](const std::array<u64,3>& m1205) {
            slog::join_probe<3,3>($seq_atrindex1184, std::array<u64,3>{v_c267, v_c269, v_c164}, [&](const std::array<u64,3>& m1206) {
              slog::join_probe<2,2>(_enumindex1185, std::array<u64,2>{v_c269, v_c260}, [&](const std::array<u64,2>& m1207) {
                slog::join_probe<3,2>(deltaindex1186, std::array<u64,3>{v_c261, v_c164, 0}, [&](const std::array<u64,3>& m1208) {
                  u64 v_c270 = m1208[2];
                  slog::join_all<1>(any_boolindex1187, [&](const std::array<u64,1>& m1209) {
                    u64 v_c163 = m1209[0];
                    bool ok1210 = true;
                    u64 v_c271 = _prim_aslst(db, v_c164, &ok1210);
                    if (!ok1210) return;
                    u64 v_c272 = _prim_llen(db, v_c271);
                    if (v_c272 == slog_error) { slog::emit_pending_error(db, "interp.slog:125"); return; }
                    if (v_c262 != v_c272) return;
                    bool ok1211 = true;
                    u64 v_c273 = _prim_lref(db, v_c271, v_c263, &ok1211);
                    if (!ok1211) return;
                    if (v_c269 != v_c273) return;
                    bool ok1212 = true;
                    u64 v_c274 = _prim_lref(db, v_c271, v_c264, &ok1212);
                    if (!ok1212) return;
                    if (v_c269 != v_c274) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c270, v_c163});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c163}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1188* _cont = new ReadTask1188(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1188(db,b), false);
  // (crule (pre) (scan temp3fv92049 __t5BnU274 __t96hl275) (body) (head (emit lst_take_ans (0 1) __t96hl275 __t5BnU274)) list.slog:29 #f)
  class ReadTask1213 : public slog::Task
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
      std::vector<u16> ord1214({0, 1});
      slog::Relation* readrel1215 = db->getRelation("lst_take_ans");
      head_index[0] = readrel1215->getIndex(ord1214, false);
      outer_rel = db->getRelation("temp3fv92049");
  
    }
    ReadTask1213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c275 = _t[0];
        u64 v_c276 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c276, v_c275}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:temp3fv92049", _fires);
  
      if (!_done)
      {
        ReadTask1213* _cont = new ReadTask1213(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1213(db,b), false);
  // (crule (pre (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c)) (scan temp7F9y1954 __t1aBM195 __t9JFW211) (body (join let (1 2 3 0) 3 __tconst2PAJ212 __t9JFW211 __t1aBM195 __t0C5k213)) (head (emit program (0) __t0C5k213)) kcfa.slog:59 #f)
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
      outer_rel = db->getRelation("temp7F9y1954");
      std::vector<u16> ord1220({1, 2, 3, 0});
      slog::Relation* readrel1221 = db->getRelation("let");
      letindex1216 = readrel1221->getIndex(ord1220, false);
  
    }
    ReadTask1217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c277 = v_const624b60c58c9d8bfb6ff1886c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c278 = _t[0];
        u64 v_c279 = _t[1];
        slog::join_probe<4,3>(letindex1216, std::array<u64,4>{v_c277, v_c279, v_c278, 0}, [&](const std::array<u64,4>& m1222) {
          u64 v_c280 = m1222[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c280}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp7F9y1954", _fires);
  
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
  // (crule (pre (let __trid4QnP1476 conste711e3685c3e87fc5763620f) (let __trel8MWP1477 const4a59dbb9cb3129dfcc75170b) (let __tcol3iWZ1478 const5feceb66ffc86f38d952786c) (let __trel7Wft1479 const4a59dbb9cb3129dfcc75170b) (let __tcol0rtE1480 const6b86b273ff34fce19d6b804e) (let __trel105C1481 const4a59dbb9cb3129dfcc75170b) (let __tcol9NZL1482 constd4735e3a265e16eee03f5971)) (scan $sup70016x95x0x0x1 __d0 __d3 eb er rho rho2 t x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid4QnP1476 __trel8MWP1477 __tcol3iWZ1478 (1 2 3 4 0)) (tycheck rho2 (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4QnP1476 __trel7Wft1479 __tcol0rtE1480 (1 2 3 4 0)) (tycheck t (accept seq) __trid4QnP1476 __trel105C1481 __tcol9NZL1482 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __2IYp1475 er rho2 t)) interp.slog:96 #f)
  class ReadTask1236 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1234;  u32 sid1223;  u32 sid1224;  u32 sid1225;  u32 sid1226;  u32 sid1227;  u32 sid1228;  u32 sid1233;  u32 sid1235;  u32 sid1229;  u32 sid1230;  u32 sid1231;  u32 sid1232;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x95x0x0x1");
      sid1234 = db->getRelation("_enum")->getStructId();
      sid1223 = db->getRelation("app")->getStructId();
      sid1224 = db->getRelation("boolean")->getStructId();
      sid1225 = db->getRelation("if")->getStructId();
      sid1226 = db->getRelation("lambda")->getStructId();
      sid1227 = db->getRelation("let")->getStructId();
      sid1228 = db->getRelation("letrec")->getStructId();
      sid1233 = db->getRelation("mbranch")->getStructId();
      sid1235 = db->getRelation("mleaf")->getStructId();
      sid1229 = db->getRelation("num")->getStructId();
      sid1230 = db->getRelation("primref")->getStructId();
      sid1231 = db->getRelation("ref")->getStructId();
      sid1232 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1236(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c281 = v_conste711e3685c3e87fc5763620f;
      u64 v_c282 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c283 = v_const5feceb66ffc86f38d952786c;
      u64 v_c284 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c285 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c286 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c287 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c64 = _t[0];
        u64 v_c124 = _t[1];
        u64 v_c99 = _t[2];
        u64 v_c98 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c288 = _t[5];
        u64 v_c9 = _t[6];
        u64 v_c97 = _t[7];
        ++_fires;
        if (!((is_struct(v_c98) && (decode_struct_id(v_c98) == sid1223 || decode_struct_id(v_c98) == sid1224 || decode_struct_id(v_c98) == sid1225 || decode_struct_id(v_c98) == sid1226 || decode_struct_id(v_c98) == sid1227 || decode_struct_id(v_c98) == sid1228 || decode_struct_id(v_c98) == sid1229 || decode_struct_id(v_c98) == sid1230 || decode_struct_id(v_c98) == sid1231 || decode_struct_id(v_c98) == sid1232))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c281, v_c282, v_c283, v_c98}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c288) && (decode_struct_id(v_c288) == sid1233 || decode_struct_id(v_c288) == sid1234 || decode_struct_id(v_c288) == sid1235))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c281, v_c284, v_c285, v_c288}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c9)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c281, v_c286, v_c287, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c98, v_c288, v_c9}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1236* _cont = new ReadTask1236(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1236(db,b), false);
  // (crule (pre (let __trid4Ioc1285 constd9f3167b950244706dc6dbb2) (let __trel74vT1286 const7f254967624b26d820569bd6) (let __tcol5QiB1287 const6b86b273ff34fce19d6b804e) (let __trel9cBj1288 const72bac24066bb34077c1f6e71) (let __tcol4LeD1289 const5feceb66ffc86f38d952786c) (let __trel8DyF1290 const72bac24066bb34077c1f6e71) (let __tcol4Zb01291 const6b86b273ff34fce19d6b804e) (let __trel4Tfg1292 const72bac24066bb34077c1f6e71) (let __tcol8nzq1293 constd4735e3a265e16eee03f5971) (let __trel1lTy1294 const72bac24066bb34077c1f6e71) (let __tcol1VMQ1295 const4e07408562bedb8b60ce05c1)) (scan $sup5638x107x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4Ioc1285 __trel74vT1286 __tcol5QiB1287 (1 2 3 4 0)) (tycheck p (accept int) __trid4Ioc1285 __trel9cBj1288 __tcol4LeD1289 (1 2 3 4 0)) (tycheck m (accept int) __trid4Ioc1285 __trel8DyF1290 __tcol4Zb01291 (1 2 3 4 0)) (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4Ioc1285 __trel4Tfg1292 __tcol8nzq1293 (1 2 3 4 0)) (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4Ioc1285 __trel1lTy1294 __tcol1VMQ1295 (1 2 3 4 0)) (emit-temp temp53kK1916 l m p r v) (mkstruct mbranch (1 2 3 4 0) __t4yht230 p m l r)) map.slog:108 #f)
  class ReadTask1240 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1238;  u32 sid1237;  u32 sid1239;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp53kK1916");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x1");
      sid1238 = db->getRelation("_enum")->getStructId();
      sid1237 = db->getRelation("mbranch")->getStructId();
      sid1239 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_constd9f3167b950244706dc6dbb2;
      u64 v_c290 = v_const7f254967624b26d820569bd6;
      u64 v_c291 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c292 = v_const72bac24066bb34077c1f6e71;
      u64 v_c293 = v_const5feceb66ffc86f38d952786c;
      u64 v_c294 = v_const72bac24066bb34077c1f6e71;
      u64 v_c295 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c296 = v_const72bac24066bb34077c1f6e71;
      u64 v_c297 = v_constd4735e3a265e16eee03f5971;
      u64 v_c298 = v_const72bac24066bb34077c1f6e71;
      u64 v_c299 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c64 = _t[0];
        u64 v_c123 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c78 = _t[4];
        u64 v_c27 = _t[5];
        u64 v_c77 = _t[6];
        u64 v_c28 = _t[7];
        u64 v_c79 = _t[8];
        u64 v_c31 = _t[9];
        ++_fires;
        if (!((is_struct(v_c31) && (decode_struct_id(v_c31) == sid1237 || decode_struct_id(v_c31) == sid1238 || decode_struct_id(v_c31) == sid1239))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c289, v_c290, v_c291, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c27)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c289, v_c292, v_c293, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c26)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c289, v_c294, v_c295, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c25) && (decode_struct_id(v_c25) == sid1237 || decode_struct_id(v_c25) == sid1238 || decode_struct_id(v_c25) == sid1239))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c289, v_c296, v_c297, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c28) && (decode_struct_id(v_c28) == sid1237 || decode_struct_id(v_c28) == sid1238 || decode_struct_id(v_c28) == sid1239))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c289, v_c298, v_c299, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c25, v_c26, v_c27, v_c28, v_c31});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c27, v_c26, v_c25, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1240* _cont = new ReadTask1240(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1240(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t8x7Q785 __v0) (body (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 2 __t8x7Q785 __v0) (exists $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 2 __t8x7Q785 __v0) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v3) (exists $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 3 __t8x7Q785 __v0 __v3) (join mp_hsb_ans (0 1) 1 __t8x7Q785 __v1) (exists mp_msk (2 0 1) 1 __v1) (join $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t8x7Q785 __v0 __v3 __v1 __t7O3e781 dup6QI21998 dup4FCe1999 p0 p1 t0 t1) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join mp_msk_ans (0 1) 1 __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask1258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1241;  slog::Index** $sup5638x29x0x0x2index1242;  slog::Index** $sup5638x29x0x0x1index1243;  slog::Index** mp_hsb_ansindex1244;  slog::Index** $sup5638x29x0x0x2index1245;  slog::Index** mp_hsb_ansindex1246;  slog::Index** mp_mskindex1247;  slog::Index** $sup5638x29x0x0x2index1248;  slog::Index** $sup5638x29x0x0x1index1249;  slog::Index** $sup5638x29x0x0x0index1250;  slog::Index** mp_joinindex1251;  slog::Index** mp_mskindex1252;  slog::Index** mp_msk_ansindex1253;  slog::Index** mp_hsbindex1254;  slog::Index** mp_joindelta1255;  slog::Index** mp_mskdelta1256;  slog::Index** mp_hsbdelta1257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1259({0, 1});
      slog::Relation* readrel1260 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1241 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1262 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1242 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1264 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1243 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({0, 1});
      slog::Relation* readrel1266 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1244 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1268 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1245 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1246 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({2, 0, 1});
      slog::Relation* readrel1272 = db->getRelation("mp_msk");
      mp_mskindex1247 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1274 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index1248 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1276 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index1249 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 0, 2, 3, 4});
      slog::Relation* readrel1278 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1250 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({1, 2, 3, 4, 0});
      slog::Relation* readrel1280 = db->getRelation("mp_join");
      mp_joinindex1251 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 2, 3, 4, 0});
      slog::Relation* readrel1282 = db->getRelation("mp_join");
      mp_joindelta1255 = readrel1282->getIndex(ord1281, true);
      std::vector<u16> ord1283({1, 2, 0});
      slog::Relation* readrel1284 = db->getRelation("mp_msk");
      mp_mskindex1252 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({1, 2, 0});
      slog::Relation* readrel1286 = db->getRelation("mp_msk");
      mp_mskdelta1256 = readrel1286->getIndex(ord1285, true);
      std::vector<u16> ord1287({0, 1});
      slog::Relation* readrel1288 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1253 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({0, 1});
      slog::Relation* readrel1290 = db->getRelation("mp_hsb");
      mp_hsbindex1254 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({0, 1});
      slog::Relation* readrel1292 = db->getRelation("mp_hsb");
      mp_hsbdelta1257 = readrel1292->getIndex(ord1291, true);
  
    }
    ReadTask1258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c300 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c301 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1241, std::array<u64,2>{v_c301, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x29x0x0x2index1242, std::array<u64,11>{v_c301, v_c14, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,2>($sup5638x29x0x0x1index1243, std::array<u64,7>{v_c301, v_c14, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex1244, std::array<u64,2>{v_c301, 0}, [&](const std::array<u64,2>& m1293) {
          u64 v_c302 = m1293[1];
          if (!slog::exists_probe<11,3>($sup5638x29x0x0x2index1245, std::array<u64,11>{v_c301, v_c14, v_c302, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex1246, std::array<u64,2>{v_c301, 0}, [&](const std::array<u64,2>& m1294) {
            u64 v_c15 = m1294[1];
            if (!slog::exists_probe<3,1>(mp_mskindex1247, std::array<u64,3>{v_c15, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x29x0x0x2index1248, std::array<u64,11>{v_c301, v_c14, v_c302, v_c15, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1295) {
              u64 v_c303 = m1295[4]; u64 v_c304 = m1295[5]; u64 v_c305 = m1295[6]; u64 v_c68 = m1295[7]; u64 v_c69 = m1295[8]; u64 v_c70 = m1295[9]; u64 v_c71 = m1295[10];
              if (v_c301 != v_c305) return;
              if (v_c301 != v_c304) return;
              slog::join_probe<7,7>($sup5638x29x0x0x1index1249, std::array<u64,7>{v_c303, v_c68, v_c69, v_c70, v_c71, v_c301, v_c14}, [&](const std::array<u64,7>& m1296) {
                slog::join_probe<5,5>($sup5638x29x0x0x0index1250, std::array<u64,5>{v_c68, v_c303, v_c69, v_c70, v_c71}, [&](const std::array<u64,5>& m1297) {
                  slog::join_probe_old<5,5>(mp_joinindex1251, mp_joindelta1255, std::array<u64,5>{v_c68, v_c70, v_c69, v_c71, v_c303}, [&](const std::array<u64,5>& m1298) {
                    slog::join_probe_old<3,2>(mp_mskindex1252, mp_mskdelta1256, std::array<u64,3>{v_c68, v_c15, 0}, [&](const std::array<u64,3>& m1299) {
                      u64 v_c306 = m1299[2];
                      slog::join_probe<2,1>(mp_msk_ansindex1253, std::array<u64,2>{v_c306, 0}, [&](const std::array<u64,2>& m1300) {
                        u64 v_c307 = m1300[1];
                        u64 v_c308 = _prim_bxor(db, v_c68, v_c69);
                        if (v_c308 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1254, mp_hsbdelta1257, std::array<u64,2>{v_c301, v_c308}, [&](const std::array<u64,2>& m1301) {
                          u64 v_c309 = _prim_band(db, v_c68, v_c14);
                          if (v_c309 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c310 = _prim_gt(db, v_c309, v_c300);
                          if (v_c310 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c310) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c303, v_c307, v_c302, v_c70, v_c71});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c307, v_c302, v_c71, v_c70}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1258* _cont = new ReadTask1258(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1258(db,b), false);
  // (crule (pre (let __tconst4OFx251 const6b86b273ff34fce19d6b804e)) (scan mbranch __t18bm249 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t18bm249 k __t18R6250) (let __t0Aej252 (band k m)) (cmp lt __t0Aej252 __tconst4OFx251)) (head (emit $sup5638x82x0x0x0 (4 3 5 2 0 1) p m r l __t18R6250 k)) map.slog:83 #f)
  class ReadTask1305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex1303;  slog::Index** mp_deldelta1304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord1306({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1307 = db->getRelation("$sup5638x82x0x0x0");
      head_index[0] = readrel1307->getIndex(ord1306, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1308({1, 2, 0});
      slog::Relation* readrel1309 = db->getRelation("mp_del");
      mp_delindex1303 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({1, 2, 0});
      slog::Relation* readrel1311 = db->getRelation("mp_del");
      mp_deldelta1304 = readrel1311->getIndex(ord1310, true);
  
    }
    ReadTask1305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c311 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c312 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c28 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex1303, mp_deldelta1304, std::array<u64,3>{v_c312, 0, 0}, [&](const std::array<u64,3>& m1312) {
          u64 v_c24 = m1312[1]; u64 v_c313 = m1312[2];
          u64 v_c314 = _prim_band(db, v_c24, v_c26);
          if (v_c314 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          u64 v_c315 = _prim_lt(db, v_c314, v_c311);
          if (v_c315 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          if (!v_c315) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c27, v_c26, v_c28, v_c25, v_c313, v_c24}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1305* _cont = new ReadTask1305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1305(db,b), false);
  // (crule (pre) (scan mleaf __t1w01301 j v) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t1w01301 k __t7wT8302) (neq j k)) (head (emit mp_del_ans (0 1) __t7wT8302 __t1w01301)) map.slog:81 #f)
  class ReadTask1316 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex1314;  slog::Index** mp_deldelta1315;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1317({0, 1});
      slog::Relation* readrel1318 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1318->getIndex(ord1317, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord1319({1, 2, 0});
      slog::Relation* readrel1320 = db->getRelation("mp_del");
      mp_delindex1314 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("mp_del");
      mp_deldelta1315 = readrel1322->getIndex(ord1321, true);
  
    }
    ReadTask1316(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c316 = _t[0];
        u64 v_c317 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe_old<3,1>(mp_delindex1314, mp_deldelta1315, std::array<u64,3>{v_c316, 0, 0}, [&](const std::array<u64,3>& m1323) {
          u64 v_c24 = m1323[1]; u64 v_c318 = m1323[2];
          if (v_c317 == v_c24) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c318, v_c316}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:81", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask1316* _cont = new ReadTask1316(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1316(db,b), false);
}

