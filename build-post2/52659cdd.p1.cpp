
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const04bd2b8089aaccc742a3c6c8;
extern u64 v_const0dfced6e06d4ae6199e0f896;
extern u64 v_const2c070a9498052f6e608df512;
extern u64 v_const30749c2c8a5c40a4f0a780b6;
extern u64 v_const439d97756c1f6d8e3f1b29c9;
extern u64 v_const4ab8424ce3e463ada0064da8;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6d8bc911abd31f57d1b91158;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constd1596cb698715803872591d6;
extern u64 v_conste7e898c68006c22d00270874;
extern u64 v_constf0add80747aca33dead79eea;


void slog_rules_c000f683e5e76f6b0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan frag __t2vXQ10) (body (join-old alt (0 1 2) 1 (0 1 2) __t2vXQ10 r s)) (head (emit frag (0) s) (emit frag (0) r)) antimirov.slog:107 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex0;  slog::Index** altdelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("frag");
      head_index[0] = readrel4->getIndex(ord3, false);
      head_rel[1] = db->getRelation("frag");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("frag");
      head_index[1] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("frag");
      std::vector<u16> ord7({0, 1, 2});
      slog::Relation* readrel8 = db->getRelation("alt");
      altindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("alt");
      altdelta1 = readrel10->getIndex(ord9, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        slog::join_probe_old<3,1>(altindex0, altdelta1, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m11) {
          u64 v_c1 = m11[1]; u64 v_c2 = m11[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:107", "delta:frag", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre) (scan temp262S323 __t4QnR75 __t8G6r74 s) (body (join cat (1 2 0) 2 __t8G6r74 s __t0ZKc73)) (head (emit mkcat_ans (0 1) __t4QnR75 __t0ZKc73)) antimirov.slog:57 #f)
  class ReadTask13 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex12;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat_ans");
      std::vector<u16> ord14({0, 1});
      slog::Relation* readrel15 = db->getRelation("mkcat_ans");
      head_index[0] = readrel15->getIndex(ord14, false);
      outer_rel = db->getRelation("temp262S323");
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("cat");
      catindex12 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(catindex12, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m18) {
          u64 v_c5 = m18[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c5}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:57", "delta:temp262S323", _fires);
  
      if (!_done)
      {
        ReadTask13* _cont = new ReadTask13(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask13(db,b), false);
  // (crule (pre) (scan mkcat __t4QnR75 __t8G6r74 s) (body (join chr (0 1) 1 __t8G6r74 c)) (head (emit-temp temp262S323 __t4QnR75 __t8G6r74 s) (mkstruct cat (1 2 0) __t0ZKc73 __t8G6r74 s)) antimirov.slog:57 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp262S323");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("chr");
      chrindex19 = readrel22->getIndex(ord21, false);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(chrindex19, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m23) {
          u64 v_c6 = m23[1];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c3, v_c4, v_c2});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c4, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:57", "delta:mkcat", _fires);
  
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
  // (crule (pre (let _00024sqc30eT141 const6b86b273ff34fce19d6b804e) (let _00024sqc8YZJ142 const5feceb66ffc86f38d952786c) (let _00024sqc24yE143 const6b86b273ff34fce19d6b804e) (let _00024sqc1P4u144 const5feceb66ffc86f38d952786c)) (scan $sup14449x83x0x0x0 _00024seq0 __d0 c cs r) (body (join-old deriv (1 2 0) 2 (1 2 0) r c __t1HCg50) (join-old deriv_ans (0 1) 1 (0 1) __t1HCg50 __v0) (letp _00024sql7KCR139 (aslst _00024seq0)) (let _00024sqn6JCE140 (llen _00024sql7KCR139)) (cmp ge _00024sqn6JCE140 _00024sqc30eT141) (letp chk7Uo3311 (lref _00024sql7KCR139 _00024sqc8YZJ142)) (eq c chk7Uo3311) (let _00024sqp2g3G145 (_0002d _00024sqn6JCE140 _00024sqc1P4u144)) (let chk1r83312 (lslice _00024sql7KCR139 _00024sqc24yE143 _00024sqp2g3G145)) (eq cs chk1r83312)) (head (mkstruct run (1 2 0) __6qdL202 __v0 cs)) antimirov.slog:84 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex24;  slog::Index** deriv_ansindex25;  slog::Index** derivdelta26;  slog::Index** deriv_ansdelta27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run");
      outer_rel = db->getRelation("$sup14449x83x0x0x0");
      std::vector<u16> ord29({1, 2, 0});
      slog::Relation* readrel30 = db->getRelation("deriv");
      derivindex24 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("deriv");
      derivdelta26 = readrel32->getIndex(ord31, true);
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("deriv_ans");
      deriv_ansindex25 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("deriv_ans");
      deriv_ansdelta27 = readrel36->getIndex(ord35, true);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c6 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c1 = _t[4];
        slog::join_probe_old<3,2>(derivindex24, derivdelta26, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m37) {
          u64 v_c14 = m37[2];
          slog::join_probe_old<2,1>(deriv_ansindex25, deriv_ansdelta27, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m38) {
            u64 v_c15 = m38[1];
            bool ok39 = true;
            u64 v_c16 = _prim_aslst(db, v_c11, &ok39);
            if (!ok39) return;
            u64 v_c17 = _prim_llen(db, v_c16);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c18 = _prim_ge(db, v_c17, v_c7);
            if (v_c18 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (!v_c18) return;
            bool ok41 = true;
            u64 v_c19 = _prim_lref(db, v_c16, v_c8, &ok41);
            if (!ok41) return;
            if (v_c6 != v_c19) return;
            u64 v_c20 = _prim__0002d(db, v_c17, v_c10);
            if (v_c20 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c21 = _prim_lslice(db, v_c16, v_c9, v_c20);
            if (v_c21 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (v_c13 != v_c21) return;
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c13}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:$sup14449x83x0x0x0", _fires);
  
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
  // (crule (pre) (scan cat __t3mF986 r s) (body (exists nullable (1 0) 1 __t3mF986) (exists nullable (1 0) 1 r) (exists nullable (1 0) 1 s) (join $sup14449x45x0x0x0 (1 2 0) 2 r s __t7U0R87) (join-old nullable (0 1) 2 (0 1) __t7U0R87 __t3mF986) (join-old nullable (1 0) 1 (1 0) r __t7OBQ88) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (join-old nullable (1 0) 1 (1 0) s __t5WkW89) (join nullable_ans (0 1) 1 __t5WkW89 __v1) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex42;  slog::Index** nullableindex43;  slog::Index** nullableindex44;  slog::Index** $sup14449x45x0x0x0index45;  slog::Index** nullableindex46;  slog::Index** nullableindex47;  slog::Index** nullable_ansindex48;  slog::Index** nullableindex49;  slog::Index** nullable_ansindex50;  slog::Index** nullabledelta51;  slog::Index** nullabledelta52;  slog::Index** nullabledelta53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("nullable");
      nullableindex42 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("nullable");
      nullableindex43 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0});
      slog::Relation* readrel60 = db->getRelation("nullable");
      nullableindex44 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index45 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("nullable");
      nullableindex46 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("nullable");
      nullabledelta51 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({1, 0});
      slog::Relation* readrel68 = db->getRelation("nullable");
      nullableindex47 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("nullable");
      nullabledelta52 = readrel70->getIndex(ord69, true);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("nullable_ans");
      nullable_ansindex48 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("nullable");
      nullableindex49 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("nullable");
      nullabledelta53 = readrel76->getIndex(ord75, true);
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("nullable_ans");
      nullable_ansindex50 = readrel78->getIndex(ord77, false);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(nullableindex42, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex43, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex44, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<3,2>($sup14449x45x0x0x0index45, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m79) {
          u64 v_c23 = m79[2];
          slog::join_probe_old<2,2>(nullableindex46, nullabledelta51, std::array<u64,2>{v_c23, v_c22}, [&](const std::array<u64,2>& m80) {
            slog::join_probe_old<2,1>(nullableindex47, nullabledelta52, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m81) {
              u64 v_c24 = m81[1];
              slog::join_probe<2,1>(nullable_ansindex48, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m82) {
                u64 v_c15 = m82[1];
                slog::join_probe_old<2,1>(nullableindex49, nullabledelta53, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m83) {
                  u64 v_c25 = m83[1];
                  slog::join_probe<2,1>(nullable_ansindex50, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m84) {
                    u64 v_c26 = m84[1];
                    u64 v_c27 = _prim__0002a(db, v_c15, v_c26);
                    if (v_c27 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c23});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask54* _cont = new ReadTask54(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), false);
  // (crule (pre) (scan temp8Et3328 __t18aQ85 __t7U0R87) (body) (head (emit nullable_ans (0 1) __t7U0R87 __t18aQ85)) antimirov.slog:46 #f)
  class ReadTask85 : public slog::Task
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
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("nullable_ans");
      head_index[0] = readrel87->getIndex(ord86, false);
      outer_rel = db->getRelation("temp8Et3328");
  
    }
    ReadTask85(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c27}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:temp8Et3328", _fires);
  
      if (!_done)
      {
        ReadTask85* _cont = new ReadTask85(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask85(db,b), false);
  // (crule (pre) (scan deriv __t7laT33 __t3dhA32 c) (body (join cat (0 1 2) 1 __t3dhA32 r s)) (head (emit $sup14449x71x0x0x0 (2 3 0 1) r s __t7laT33 c)) antimirov.slog:72 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord90({2, 3, 0, 1});
      slog::Relation* readrel91 = db->getRelation("$sup14449x71x0x0x0");
      head_index[0] = readrel91->getIndex(ord90, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord92({0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("cat");
      catindex88 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[2];
        slog::join_probe<3,1>(catindex88, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m94) {
          u64 v_c1 = m94[1]; u64 v_c2 = m94[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c1, v_c2, v_c28, v_c6}, std::array<u16,4>{2, 3, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask89* _cont = new ReadTask89(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask89(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (probe chr (1 0) 1 __tconst7i6460 __t7SBZ53) (body (join chr (1 0) 1 __tconst77RG62 __t8Axk58)) (head (mkstruct alt (1 2 0) __t8pHj64 __t8Axk58 __t7SBZ53) (mkstruct cat (1 2 0) __t9z7256 __t7SBZ53 __t7SBZ53)) antimirov.slog:126 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** chrindex95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alt");
      head_rel[1] = db->getRelation("cat");
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("chr");
      driver_index = readrel98->getIndex(ord97, true);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("chr");
      chrindex95 = readrel100->getIndex(ord99, false);
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c31 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c32 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c32, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m101) {
        u64 v_c33 = m101[1];
        if (buckethash(v_c33) != bucket) return;
        slog::join_probe<2,1>(chrindex95, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m102) {
          u64 v_c34 = m102[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c34, v_c33}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c33, v_c33}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "delta:chr", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre) (scan alt __t8cCt111 r s) (body (exists nullable (1 0) 1 __t8cCt111) (exists nullable (1 0) 1 r) (exists nullable (1 0) 1 s) (join $sup14449x46x0x0x0 (1 2 0) 2 r s __t4S29112) (join-old nullable (0 1) 2 (0 1) __t4S29112 __t8cCt111) (join-old nullable (1 0) 1 (1 0) r __t6Byf113) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (join-old nullable (1 0) 1 (1 0) s __t0lgX114) (join nullable_ans (0 1) 1 __t0lgX114 __v1) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex103;  slog::Index** nullableindex104;  slog::Index** nullableindex105;  slog::Index** $sup14449x46x0x0x0index106;  slog::Index** nullableindex107;  slog::Index** nullableindex108;  slog::Index** nullable_ansindex109;  slog::Index** nullableindex110;  slog::Index** nullable_ansindex111;  slog::Index** nullabledelta112;  slog::Index** nullabledelta113;  slog::Index** nullabledelta114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("nullable");
      nullableindex103 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("nullable");
      nullableindex104 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("nullable");
      nullableindex105 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index106 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("nullable");
      nullableindex107 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1});
      slog::Relation* readrel127 = db->getRelation("nullable");
      nullabledelta112 = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("nullable");
      nullableindex108 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("nullable");
      nullabledelta113 = readrel131->getIndex(ord130, true);
      std::vector<u16> ord132({0, 1});
      slog::Relation* readrel133 = db->getRelation("nullable_ans");
      nullable_ansindex109 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("nullable");
      nullableindex110 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("nullable");
      nullabledelta114 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("nullable_ans");
      nullable_ansindex111 = readrel139->getIndex(ord138, false);
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(nullableindex103, std::array<u64,2>{v_c35, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex104, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex105, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<3,2>($sup14449x46x0x0x0index106, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m140) {
          u64 v_c36 = m140[2];
          slog::join_probe_old<2,2>(nullableindex107, nullabledelta112, std::array<u64,2>{v_c36, v_c35}, [&](const std::array<u64,2>& m141) {
            slog::join_probe_old<2,1>(nullableindex108, nullabledelta113, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m142) {
              u64 v_c37 = m142[1];
              slog::join_probe<2,1>(nullable_ansindex109, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m143) {
                u64 v_c15 = m143[1];
                slog::join_probe_old<2,1>(nullableindex110, nullabledelta114, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m144) {
                  u64 v_c38 = m144[1];
                  slog::join_probe<2,1>(nullable_ansindex111, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m145) {
                    u64 v_c26 = m145[1];
                    u64 v_c39 = _prim_max(db, v_c15, v_c26);
                    if (v_c39 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c39, v_c36});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:alt", _fires);
  
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
  // (crule (pre) (scan deriv __t3USy19 r c) (body (exists cat (1 2 0) 1 r) (exists deriv (2 0 1) 1 c) (exists deriv_ans (0 1) 1 __t3USy19) (join $sup14449x70x0x0x0 (1 2 3 0) 2 c r s __t1fTl18) (exists deriv (2 0 1) 2 c __t1fTl18) (exists mkcat (2 0 1) 1 s) (join cat (1 2 0) 2 r s __t9RZg17) (join deriv (0 1 2) 3 __t1fTl18 __t9RZg17 c) (join deriv_ans (0 1) 1 __t3USy19 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 s __t3Hfq20) (join mkcat_ans (0 1) 1 __t3Hfq20 __v1)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex146;  slog::Index** derivindex147;  slog::Index** deriv_ansindex148;  slog::Index** $sup14449x70x0x0x0index149;  slog::Index** derivindex150;  slog::Index** mkcatindex151;  slog::Index** catindex152;  slog::Index** derivindex153;  slog::Index** deriv_ansindex154;  slog::Index** mkcatindex155;  slog::Index** mkcat_ansindex156;  slog::Index** mkcatdelta157;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("deriv_ans");
      head_index[0] = readrel160->getIndex(ord159, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("cat");
      catindex146 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({2, 0, 1});
      slog::Relation* readrel164 = db->getRelation("deriv");
      derivindex147 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("deriv_ans");
      deriv_ansindex148 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 2, 3, 0});
      slog::Relation* readrel168 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index149 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({2, 0, 1});
      slog::Relation* readrel170 = db->getRelation("deriv");
      derivindex150 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({2, 0, 1});
      slog::Relation* readrel172 = db->getRelation("mkcat");
      mkcatindex151 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("cat");
      catindex152 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1, 2});
      slog::Relation* readrel176 = db->getRelation("deriv");
      derivindex153 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("deriv_ans");
      deriv_ansindex154 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 0});
      slog::Relation* readrel180 = db->getRelation("mkcat");
      mkcatindex155 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("mkcat");
      mkcatdelta157 = readrel182->getIndex(ord181, true);
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("mkcat_ans");
      mkcat_ansindex156 = readrel184->getIndex(ord183, false);
  
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
        u64 v_c40 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(catindex146, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex147, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(deriv_ansindex148, std::array<u64,2>{v_c40, 0})) return;
        slog::join_probe<4,2>($sup14449x70x0x0x0index149, std::array<u64,4>{v_c6, v_c1, 0, 0}, [&](const std::array<u64,4>& m185) {
          u64 v_c2 = m185[2]; u64 v_c41 = m185[3];
          if (!slog::exists_probe<3,2>(derivindex150, std::array<u64,3>{v_c6, v_c41, 0})) return;
          if (!slog::exists_probe<3,1>(mkcatindex151, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<3,2>(catindex152, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m186) {
            u64 v_c42 = m186[2];
            slog::join_probe<3,3>(derivindex153, std::array<u64,3>{v_c41, v_c42, v_c6}, [&](const std::array<u64,3>& m187) {
              slog::join_probe<2,1>(deriv_ansindex154, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m188) {
                u64 v_c15 = m188[1];
                slog::join_probe_old<3,2>(mkcatindex155, mkcatdelta157, std::array<u64,3>{v_c15, v_c2, 0}, [&](const std::array<u64,3>& m189) {
                  u64 v_c43 = m189[2];
                  slog::join_probe<2,1>(mkcat_ansindex156, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m190) {
                    u64 v_c26 = m190[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c26}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan alt __t2ubg118 r s) (body (exists deriv (1 2 0) 1 __t2ubg118) (exists deriv (1 2 0) 1 s) (join $sup14449x69x0x0x0 (2 3 0 1) 2 r s __t0tyF119 c) (join-old deriv (0 1 2) 3 (0 1 2) __t0tyF119 __t2ubg118 c) (join-old deriv (1 2 0) 2 (1 2 0) s c __t72SS120) (join deriv_ans (0 1) 1 __t72SS120 __v0)) (head (emit deriv_ans (0 1) __t0tyF119 __v0)) antimirov.slog:70 #f)
  class ReadTask199 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex191;  slog::Index** derivindex192;  slog::Index** $sup14449x69x0x0x0index193;  slog::Index** derivindex194;  slog::Index** derivindex195;  slog::Index** deriv_ansindex196;  slog::Index** derivdelta197;  slog::Index** derivdelta198;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("deriv_ans");
      head_index[0] = readrel201->getIndex(ord200, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord202({1, 2, 0});
      slog::Relation* readrel203 = db->getRelation("deriv");
      derivindex191 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 0});
      slog::Relation* readrel205 = db->getRelation("deriv");
      derivindex192 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({2, 3, 0, 1});
      slog::Relation* readrel207 = db->getRelation("$sup14449x69x0x0x0");
      $sup14449x69x0x0x0index193 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1, 2});
      slog::Relation* readrel209 = db->getRelation("deriv");
      derivindex194 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({0, 1, 2});
      slog::Relation* readrel211 = db->getRelation("deriv");
      derivdelta197 = readrel211->getIndex(ord210, true);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("deriv");
      derivindex195 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 0});
      slog::Relation* readrel215 = db->getRelation("deriv");
      derivdelta198 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("deriv_ans");
      deriv_ansindex196 = readrel217->getIndex(ord216, false);
  
    }
    ReadTask199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex191, std::array<u64,3>{v_c44, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex192, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x69x0x0x0index193, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m218) {
          u64 v_c45 = m218[2]; u64 v_c6 = m218[3];
          slog::join_probe_old<3,3>(derivindex194, derivdelta197, std::array<u64,3>{v_c45, v_c44, v_c6}, [&](const std::array<u64,3>& m219) {
            slog::join_probe_old<3,2>(derivindex195, derivdelta198, std::array<u64,3>{v_c2, v_c6, 0}, [&](const std::array<u64,3>& m220) {
              u64 v_c46 = m220[2];
              slog::join_probe<2,1>(deriv_ansindex196, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m221) {
                u64 v_c15 = m221[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c15}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask199* _cont = new ReadTask199(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask199(db,b), false);
  // (crule (pre) (scan alt __t6BEs7 r s) (body (join-old deriv (1 2 0) 1 (1 2 0) __t6BEs7 c __t6IFg8)) (head (emit $sup14449x69x0x0x0 (0 1 2 3) __t6IFg8 c r s)) antimirov.slog:70 #f)
  class ReadTask224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex222;  slog::Index** derivdelta223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x69x0x0x0");
      std::vector<u16> ord225({0, 1, 2, 3});
      slog::Relation* readrel226 = db->getRelation("$sup14449x69x0x0x0");
      head_index[0] = readrel226->getIndex(ord225, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("deriv");
      derivindex222 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("deriv");
      derivdelta223 = readrel230->getIndex(ord229, true);
  
    }
    ReadTask224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(derivindex222, derivdelta223, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m231) {
          u64 v_c6 = m231[1]; u64 v_c48 = m231[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c48, v_c6, v_c1, v_c2}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask224* _cont = new ReadTask224(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask224(db,b), false);
  // (crule (pre (let __trid9jcK232 conste7e898c68006c22d00270874) (let __trel7Aa0233 const0dfced6e06d4ae6199e0f896) (let __tcol4jVi234 const5feceb66ffc86f38d952786c) (let __trel2ze5235 const0dfced6e06d4ae6199e0f896) (let __tcol4jGG236 const6b86b273ff34fce19d6b804e)) (scan $sup14449x70x0x0x0 __d0 c r s) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid9jcK232 __trel7Aa0233 __tcol4jVi234 (1 2 3 4 0)) (tycheck c (accept str) __trid9jcK232 __trel2ze5235 __tcol4jGG236 (1 2 3 4 0)) (mkstruct deriv (1 2 0) __92gV231 r c)) antimirov.slog:71 #f)
  class ReadTask237 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid235;  u32 sid232;  u32 sid233;  u32 sid234;  u32 sid236;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("deriv");
      outer_rel = db->getRelation("$sup14449x70x0x0x0");
      sid235 = db->getRelation("_enum")->getStructId();
      sid232 = db->getRelation("alt")->getStructId();
      sid233 = db->getRelation("cat")->getStructId();
      sid234 = db->getRelation("chr")->getStructId();
      sid236 = db->getRelation("star")->getStructId();
  
    }
    ReadTask237(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_conste7e898c68006c22d00270874;
      u64 v_c50 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c51 = v_const5feceb66ffc86f38d952786c;
      u64 v_c52 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c12 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid232 || decode_struct_id(v_c1) == sid233 || decode_struct_id(v_c1) == sid234 || decode_struct_id(v_c1) == sid235 || decode_struct_id(v_c1) == sid236))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c49, v_c50, v_c51, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c49, v_c52, v_c53, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:$sup14449x70x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask237* _cont = new ReadTask237(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask237(db,b), false);
  // (crule (pre (let __trid3rIs214 const2c070a9498052f6e608df512) (let __trel8aLD215 constd1596cb698715803872591d6) (let __tcol7Nnx216 const5feceb66ffc86f38d952786c)) (scan $sup14449x46x0x0x0 __d0 r s) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid3rIs214 __trel8aLD215 __tcol7Nnx216 (1 2 3 4 0)) (mkstruct nullable (1 0) __16GI213 r)) antimirov.slog:47 #f)
  class ReadTask243 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid241;  u32 sid238;  u32 sid239;  u32 sid240;  u32 sid242;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("nullable");
      outer_rel = db->getRelation("$sup14449x46x0x0x0");
      sid241 = db->getRelation("_enum")->getStructId();
      sid238 = db->getRelation("alt")->getStructId();
      sid239 = db->getRelation("cat")->getStructId();
      sid240 = db->getRelation("chr")->getStructId();
      sid242 = db->getRelation("star")->getStructId();
  
    }
    ReadTask243(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const2c070a9498052f6e608df512;
      u64 v_c55 = v_constd1596cb698715803872591d6;
      u64 v_c56 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid238 || decode_struct_id(v_c1) == sid239 || decode_struct_id(v_c1) == sid240 || decode_struct_id(v_c1) == sid241 || decode_struct_id(v_c1) == sid242))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c54, v_c55, v_c56, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:$sup14449x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask243* _cont = new ReadTask243(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask243(db,b), false);
  // (crule (pre) (scan cat __t0Qif15 r s) (body (join-old deriv (1 2 0) 1 (1 2 0) __t0Qif15 c __t92wU16)) (head (emit $sup14449x70x0x0x0 (3 2 0 1) s r __t92wU16 c)) antimirov.slog:71 #f)
  class ReadTask246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex244;  slog::Index** derivdelta245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord247({3, 2, 0, 1});
      slog::Relation* readrel248 = db->getRelation("$sup14449x70x0x0x0");
      head_index[0] = readrel248->getIndex(ord247, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("deriv");
      derivindex244 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("deriv");
      derivdelta245 = readrel252->getIndex(ord251, true);
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(derivindex244, derivdelta245, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m253) {
          u64 v_c6 = m253[1]; u64 v_c58 = m253[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c1, v_c58, v_c6}, std::array<u16,4>{3, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask246* _cont = new ReadTask246(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask246(db,b), false);
  // (crule (pre) (scan div_by_zero __erre8iFA279 __errf8arf280 __errf2M8u281) (body) (head (emit error (0) __erre8iFA279)) <internal>:1 #f)
  class ReadTask254 : public slog::Task
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
      std::vector<u16> ord255({0});
      slog::Relation* readrel256 = db->getRelation("error");
      head_index[0] = readrel256->getIndex(ord255, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c59}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan deriv_ans __t43JV128 r2) (body (join-old deriv (0 1 2) 1 (0 1 2) __t43JV128 r c) (join state (0) 1 r) (join alpha (0) 1 c)) (head (emit nfa (0 1 2) r c r2) (emit state (0) r2)) antimirov.slog:115 #f)
  class ReadTask261 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex257;  slog::Index** stateindex258;  slog::Index** alphaindex259;  slog::Index** derivdelta260;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nfa");
      std::vector<u16> ord262({0, 1, 2});
      slog::Relation* readrel263 = db->getRelation("nfa");
      head_index[0] = readrel263->getIndex(ord262, false);
      head_rel[1] = db->getRelation("state");
      std::vector<u16> ord264({0});
      slog::Relation* readrel265 = db->getRelation("state");
      head_index[1] = readrel265->getIndex(ord264, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord266({0, 1, 2});
      slog::Relation* readrel267 = db->getRelation("deriv");
      derivindex257 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0, 1, 2});
      slog::Relation* readrel269 = db->getRelation("deriv");
      derivdelta260 = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({0});
      slog::Relation* readrel271 = db->getRelation("state");
      stateindex258 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0});
      slog::Relation* readrel273 = db->getRelation("alpha");
      alphaindex259 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask261(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c63 = _t[1];
        slog::join_probe_old<3,1>(derivindex257, derivdelta260, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m274) {
          u64 v_c1 = m274[1]; u64 v_c6 = m274[2];
          slog::join_probe<1,1>(stateindex258, std::array<u64,1>{v_c1}, [&](const std::array<u64,1>& m275) {
            slog::join_probe<1,1>(alphaindex259, std::array<u64,1>{v_c6}, [&](const std::array<u64,1>& m276) {
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c6, v_c63}, std::array<u16,3>{0, 1, 2});
              slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:deriv_ans", _fires);
  
      if (!_done)
      {
        ReadTask261* _cont = new ReadTask261(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask261(db,b), false);
  // (crule (pre) (scan deriv __t7KNy37 __t8RSy36 c) (body (join star (0 1) 1 __t8RSy36 r)) (head (mkstruct deriv (1 2 0) __1VwH175 r c)) antimirov.slog:73 #f)
  class ReadTask278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex277;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv");
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("star");
      starindex277 = readrel280->getIndex(ord279, false);
  
    }
    ReadTask278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<2,1>(starindex277, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m281) {
          u64 v_c1 = m281[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask278* _cont = new ReadTask278(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask278(db,b), false);
  // (crule (pre) (scan temp5DUf326 __t5yew82 __t6haW83 s) (body (join cat (1 2 0) 2 __t5yew82 s __t5GnC81)) (head (emit mkcat_ans (0 1) __t6haW83 __t5GnC81)) antimirov.slog:58 #f)
  class ReadTask283 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex282;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat_ans");
      std::vector<u16> ord284({0, 1});
      slog::Relation* readrel285 = db->getRelation("mkcat_ans");
      head_index[0] = readrel285->getIndex(ord284, false);
      outer_rel = db->getRelation("temp5DUf326");
      std::vector<u16> ord286({1, 2, 0});
      slog::Relation* readrel287 = db->getRelation("cat");
      catindex282 = readrel287->getIndex(ord286, false);
  
    }
    ReadTask283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(catindex282, std::array<u64,3>{v_c66, v_c2, 0}, [&](const std::array<u64,3>& m288) {
          u64 v_c68 = m288[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c68}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:58", "delta:temp5DUf326", _fires);
  
      if (!_done)
      {
        ReadTask283* _cont = new ReadTask283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask283(db,b), false);
  // (crule (pre) (scan deriv __t8rjP30 __t1wYz29 c) (body (exists deriv (2 0 1) 1 c) (join star (0 1) 1 __t1wYz29 r) (join-old deriv (1 2 0) 2 (1 2 0) r c __t2TCG31) (join deriv_ans (0 1) 1 __t2TCG31 __v0)) (head (mkstruct mkcat (1 2 0) __7GaM229 __v0 __t1wYz29)) antimirov.slog:73 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex289;  slog::Index** starindex290;  slog::Index** derivindex291;  slog::Index** deriv_ansindex292;  slog::Index** derivdelta293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat");
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord295({2, 0, 1});
      slog::Relation* readrel296 = db->getRelation("deriv");
      derivindex289 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 1});
      slog::Relation* readrel298 = db->getRelation("star");
      starindex290 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 0});
      slog::Relation* readrel300 = db->getRelation("deriv");
      derivindex291 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 0});
      slog::Relation* readrel302 = db->getRelation("deriv");
      derivdelta293 = readrel302->getIndex(ord301, true);
      std::vector<u16> ord303({0, 1});
      slog::Relation* readrel304 = db->getRelation("deriv_ans");
      deriv_ansindex292 = readrel304->getIndex(ord303, false);
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex289, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(starindex290, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m305) {
          u64 v_c1 = m305[1];
          slog::join_probe_old<3,2>(derivindex291, derivdelta293, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m306) {
            u64 v_c71 = m306[2];
            slog::join_probe<2,1>(deriv_ansindex292, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m307) {
              u64 v_c15 = m307[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c70}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan temp31LP324 __t1cXu110 __t4S29112) (body) (head (emit nullable_ans (0 1) __t4S29112 __t1cXu110)) antimirov.slog:47 #f)
  class ReadTask308 : public slog::Task
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
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("nullable_ans");
      head_index[0] = readrel310->getIndex(ord309, false);
      outer_rel = db->getRelation("temp31LP324");
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c36 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c36, v_c39}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:temp31LP324", _fires);
  
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
  // (crule (pre) (scan deriv_ans __t2TCG31 __v0) (body (join-old deriv (0 1 2) 1 (0 1 2) __t2TCG31 r c) (exists deriv (2 0 1) 1 c) (join-old star (1 0) 1 (1 0) r __t1wYz29) (join-old deriv (1 2 0) 2 (1 2 0) __t1wYz29 c __t8rjP30)) (head (mkstruct mkcat (1 2 0) __7GaM229 __v0 __t1wYz29)) antimirov.slog:73 #f)
  class ReadTask318 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex311;  slog::Index** derivindex312;  slog::Index** starindex313;  slog::Index** derivindex314;  slog::Index** derivdelta315;  slog::Index** stardelta316;  slog::Index** derivdelta317;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat");
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord319({0, 1, 2});
      slog::Relation* readrel320 = db->getRelation("deriv");
      derivindex311 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1, 2});
      slog::Relation* readrel322 = db->getRelation("deriv");
      derivdelta315 = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({2, 0, 1});
      slog::Relation* readrel324 = db->getRelation("deriv");
      derivindex312 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 0});
      slog::Relation* readrel326 = db->getRelation("star");
      starindex313 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 0});
      slog::Relation* readrel328 = db->getRelation("star");
      stardelta316 = readrel328->getIndex(ord327, true);
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("deriv");
      derivindex314 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("deriv");
      derivdelta317 = readrel332->getIndex(ord331, true);
  
    }
    ReadTask318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        slog::join_probe_old<3,1>(derivindex311, derivdelta315, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m333) {
          u64 v_c1 = m333[1]; u64 v_c6 = m333[2];
          if (!slog::exists_probe<3,1>(derivindex312, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<2,1>(starindex313, stardelta316, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m334) {
            u64 v_c70 = m334[1];
            slog::join_probe_old<3,2>(derivindex314, derivdelta317, std::array<u64,3>{v_c70, v_c6, 0}, [&](const std::array<u64,3>& m335) {
              u64 v_c69 = m335[2];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c70}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv_ans", _fires);
  
      if (!_done)
      {
        ReadTask318* _cont = new ReadTask318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask318(db,b), false);
  // (crule (pre) (scan deriv __t0tyF119 __t2ubg118 c) (body (exists deriv (2 0 1) 1 c) (join $sup14449x69x0x0x0 (0 1 2 3) 2 __t0tyF119 c r s) (join alt (0 1 2) 3 __t2ubg118 r s) (join-old deriv (1 2 0) 2 (1 2 0) s c __t72SS120) (join deriv_ans (0 1) 1 __t72SS120 __v0)) (head (emit deriv_ans (0 1) __t0tyF119 __v0)) antimirov.slog:70 #f)
  class ReadTask342 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex336;  slog::Index** $sup14449x69x0x0x0index337;  slog::Index** altindex338;  slog::Index** derivindex339;  slog::Index** deriv_ansindex340;  slog::Index** derivdelta341;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord343({0, 1});
      slog::Relation* readrel344 = db->getRelation("deriv_ans");
      head_index[0] = readrel344->getIndex(ord343, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord345({2, 0, 1});
      slog::Relation* readrel346 = db->getRelation("deriv");
      derivindex336 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1, 2, 3});
      slog::Relation* readrel348 = db->getRelation("$sup14449x69x0x0x0");
      $sup14449x69x0x0x0index337 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("alt");
      altindex338 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("deriv");
      derivindex339 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("deriv");
      derivdelta341 = readrel354->getIndex(ord353, true);
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("deriv_ans");
      deriv_ansindex340 = readrel356->getIndex(ord355, false);
  
    }
    ReadTask342(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex336, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x69x0x0x0index337, std::array<u64,4>{v_c45, v_c6, 0, 0}, [&](const std::array<u64,4>& m357) {
          u64 v_c1 = m357[2]; u64 v_c2 = m357[3];
          slog::join_probe<3,3>(altindex338, std::array<u64,3>{v_c44, v_c1, v_c2}, [&](const std::array<u64,3>& m358) {
            slog::join_probe_old<3,2>(derivindex339, derivdelta341, std::array<u64,3>{v_c2, v_c6, 0}, [&](const std::array<u64,3>& m359) {
              u64 v_c46 = m359[2];
              slog::join_probe<2,1>(deriv_ansindex340, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m360) {
                u64 v_c15 = m360[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c15}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask342* _cont = new ReadTask342(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask342(db,b), false);
  // (crule (pre (let __trid36Av197 const04bd2b8089aaccc742a3c6c8) (let __trel2qUg198 const0dfced6e06d4ae6199e0f896) (let __tcol37vC199 const5feceb66ffc86f38d952786c) (let __trel6skK200 const0dfced6e06d4ae6199e0f896) (let __tcol5Ewg201 const6b86b273ff34fce19d6b804e)) (scan $sup14449x68x0x0x0 __d0 c r s) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid36Av197 __trel2qUg198 __tcol37vC199 (1 2 3 4 0)) (tycheck c (accept str) __trid36Av197 __trel6skK200 __tcol5Ewg201 (1 2 3 4 0)) (mkstruct deriv (1 2 0) __0Kce196 r c)) antimirov.slog:69 #f)
  class ReadTask366 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid364;  u32 sid361;  u32 sid362;  u32 sid363;  u32 sid365;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("deriv");
      outer_rel = db->getRelation("$sup14449x68x0x0x0");
      sid364 = db->getRelation("_enum")->getStructId();
      sid361 = db->getRelation("alt")->getStructId();
      sid362 = db->getRelation("cat")->getStructId();
      sid363 = db->getRelation("chr")->getStructId();
      sid365 = db->getRelation("star")->getStructId();
  
    }
    ReadTask366(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const04bd2b8089aaccc742a3c6c8;
      u64 v_c73 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c74 = v_const5feceb66ffc86f38d952786c;
      u64 v_c75 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c76 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c12 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid361 || decode_struct_id(v_c1) == sid362 || decode_struct_id(v_c1) == sid363 || decode_struct_id(v_c1) == sid364 || decode_struct_id(v_c1) == sid365))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c72, v_c73, v_c74, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c72, v_c75, v_c76, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:$sup14449x68x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask366* _cont = new ReadTask366(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask366(db,b), false);
  // (crule (pre) (scan chr __t6EC3134 c) (body (join frag (0) 1 __t6EC3134)) (head (emit alpha (0) c)) antimirov.slog:109 #f)
  class ReadTask368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fragindex367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alpha");
      std::vector<u16> ord369({0});
      slog::Relation* readrel370 = db->getRelation("alpha");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("chr");
      std::vector<u16> ord371({0});
      slog::Relation* readrel372 = db->getRelation("frag");
      fragindex367 = readrel372->getIndex(ord371, false);
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe<1,1>(fragindex367, std::array<u64,1>{v_c77}, [&](const std::array<u64,1>& m373) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:109", "delta:chr", _fires);
  
      if (!_done)
      {
        ReadTask368* _cont = new ReadTask368(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask368(db,b), false);
  // (crule (pre) (scan cat __t9RZg17 r s) (body (exists deriv (1 2 0) 1 __t9RZg17) (exists deriv (1 2 0) 1 r) (exists mkcat (2 0 1) 1 s) (join $sup14449x70x0x0x0 (3 2 0 1) 2 s r __t1fTl18 c) (join-old deriv (0 1 2) 3 (0 1 2) __t1fTl18 __t9RZg17 c) (join-old deriv (1 2 0) 2 (1 2 0) r c __t3USy19) (join deriv_ans (0 1) 1 __t3USy19 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 s __t3Hfq20) (join mkcat_ans (0 1) 1 __t3Hfq20 __v1)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask386 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex374;  slog::Index** derivindex375;  slog::Index** mkcatindex376;  slog::Index** $sup14449x70x0x0x0index377;  slog::Index** derivindex378;  slog::Index** derivindex379;  slog::Index** deriv_ansindex380;  slog::Index** mkcatindex381;  slog::Index** mkcat_ansindex382;  slog::Index** derivdelta383;  slog::Index** derivdelta384;  slog::Index** mkcatdelta385;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("deriv_ans");
      head_index[0] = readrel388->getIndex(ord387, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("deriv");
      derivindex374 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("deriv");
      derivindex375 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({2, 0, 1});
      slog::Relation* readrel394 = db->getRelation("mkcat");
      mkcatindex376 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({3, 2, 0, 1});
      slog::Relation* readrel396 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index377 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("deriv");
      derivindex378 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1, 2});
      slog::Relation* readrel400 = db->getRelation("deriv");
      derivdelta383 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({1, 2, 0});
      slog::Relation* readrel402 = db->getRelation("deriv");
      derivindex379 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("deriv");
      derivdelta384 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({0, 1});
      slog::Relation* readrel406 = db->getRelation("deriv_ans");
      deriv_ansindex380 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 2, 0});
      slog::Relation* readrel408 = db->getRelation("mkcat");
      mkcatindex381 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 0});
      slog::Relation* readrel410 = db->getRelation("mkcat");
      mkcatdelta385 = readrel410->getIndex(ord409, true);
      std::vector<u16> ord411({0, 1});
      slog::Relation* readrel412 = db->getRelation("mkcat_ans");
      mkcat_ansindex382 = readrel412->getIndex(ord411, false);
  
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
        u64 v_c42 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex374, std::array<u64,3>{v_c42, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex375, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mkcatindex376, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x70x0x0x0index377, std::array<u64,4>{v_c2, v_c1, 0, 0}, [&](const std::array<u64,4>& m413) {
          u64 v_c41 = m413[2]; u64 v_c6 = m413[3];
          slog::join_probe_old<3,3>(derivindex378, derivdelta383, std::array<u64,3>{v_c41, v_c42, v_c6}, [&](const std::array<u64,3>& m414) {
            slog::join_probe_old<3,2>(derivindex379, derivdelta384, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m415) {
              u64 v_c40 = m415[2];
              slog::join_probe<2,1>(deriv_ansindex380, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m416) {
                u64 v_c15 = m416[1];
                slog::join_probe_old<3,2>(mkcatindex381, mkcatdelta385, std::array<u64,3>{v_c15, v_c2, 0}, [&](const std::array<u64,3>& m417) {
                  u64 v_c43 = m417[2];
                  slog::join_probe<2,1>(mkcat_ansindex382, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m418) {
                    u64 v_c26 = m418[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c26}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:cat", _fires);
  
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
  // (crule (pre) (scan deriv_ans __t2byM14 __v0) (body (join-old deriv (0 1 2) 1 (0 1 2) __t2byM14 r c) (exists alt (1 2 0) 1 r) (exists deriv (2 0 1) 1 c) (join-old $sup14449x68x0x0x0 (1 2 0 3) 2 (1 2 0 3) c r __t2Yus13 s) (exists deriv (2 0 1) 2 c __t2Yus13) (join-old alt (1 2 0) 2 (1 2 0) r s __t1uAM12) (join-old deriv (0 1 2) 3 (0 1 2) __t2Yus13 __t1uAM12 c)) (head (emit deriv_ans (0 1) __t2Yus13 __v0)) antimirov.slog:69 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex419;  slog::Index** altindex420;  slog::Index** derivindex421;  slog::Index** $sup14449x68x0x0x0index422;  slog::Index** derivindex423;  slog::Index** altindex424;  slog::Index** derivindex425;  slog::Index** derivdelta426;  slog::Index** $sup14449x68x0x0x0delta427;  slog::Index** altdelta428;  slog::Index** derivdelta429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("deriv_ans");
      head_index[0] = readrel432->getIndex(ord431, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord433({0, 1, 2});
      slog::Relation* readrel434 = db->getRelation("deriv");
      derivindex419 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({0, 1, 2});
      slog::Relation* readrel436 = db->getRelation("deriv");
      derivdelta426 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({1, 2, 0});
      slog::Relation* readrel438 = db->getRelation("alt");
      altindex420 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({2, 0, 1});
      slog::Relation* readrel440 = db->getRelation("deriv");
      derivindex421 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0, 3});
      slog::Relation* readrel442 = db->getRelation("$sup14449x68x0x0x0");
      $sup14449x68x0x0x0index422 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0, 3});
      slog::Relation* readrel444 = db->getRelation("$sup14449x68x0x0x0");
      $sup14449x68x0x0x0delta427 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({2, 0, 1});
      slog::Relation* readrel446 = db->getRelation("deriv");
      derivindex423 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("alt");
      altindex424 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 2, 0});
      slog::Relation* readrel450 = db->getRelation("alt");
      altdelta428 = readrel450->getIndex(ord449, true);
      std::vector<u16> ord451({0, 1, 2});
      slog::Relation* readrel452 = db->getRelation("deriv");
      derivindex425 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 1, 2});
      slog::Relation* readrel454 = db->getRelation("deriv");
      derivdelta429 = readrel454->getIndex(ord453, true);
  
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
        u64 v_c78 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe_old<3,1>(derivindex419, derivdelta426, std::array<u64,3>{v_c78, 0, 0}, [&](const std::array<u64,3>& m455) {
          u64 v_c1 = m455[1]; u64 v_c6 = m455[2];
          if (!slog::exists_probe<3,1>(altindex420, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(derivindex421, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<4,2>($sup14449x68x0x0x0index422, $sup14449x68x0x0x0delta427, std::array<u64,4>{v_c6, v_c1, 0, 0}, [&](const std::array<u64,4>& m456) {
            u64 v_c79 = m456[2]; u64 v_c2 = m456[3];
            if (!slog::exists_probe<3,2>(derivindex423, std::array<u64,3>{v_c6, v_c79, 0})) return;
            slog::join_probe_old<3,2>(altindex424, altdelta428, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m457) {
              u64 v_c80 = m457[2];
              slog::join_probe_old<3,3>(derivindex425, derivdelta429, std::array<u64,3>{v_c79, v_c80, v_c6}, [&](const std::array<u64,3>& m458) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c15}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:deriv_ans", _fires);
  
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
  // (crule (pre (let __tconst06uO43 const6b86b273ff34fce19d6b804e)) (scan star __t51g944 r) (body (join-old nullable (1 0) 1 (1 0) __t51g944 __t4mn745)) (head (emit nullable_ans (0 1) __t4mn745 __tconst06uO43)) antimirov.slog:45 #f)
  class ReadTask461 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex459;  slog::Index** nullabledelta460;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("nullable_ans");
      head_index[0] = readrel463->getIndex(ord462, false);
      outer_rel = db->getRelation("star");
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("nullable");
      nullableindex459 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("nullable");
      nullabledelta460 = readrel467->getIndex(ord466, true);
  
    }
    ReadTask461(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c81 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c82 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<2,1>(nullableindex459, nullabledelta460, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m468) {
          u64 v_c83 = m468[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c83, v_c81}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:45", "delta:star", _fires);
  
      if (!_done)
      {
        ReadTask461* _cont = new ReadTask461(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask461(db,b), false);
  // (crule (pre (let _00024sqc30eT141 const6b86b273ff34fce19d6b804e) (let _00024sqc8YZJ142 const5feceb66ffc86f38d952786c) (let _00024sqc24yE143 const6b86b273ff34fce19d6b804e) (let _00024sqc1P4u144 const5feceb66ffc86f38d952786c)) (scan deriv __t1HCg50 r c) (body (exists deriv_ans (0 1) 1 __t1HCg50) (join $sup14449x83x0x0x0 (2 4 0 1 3) 2 c r _00024seq0 __d0 cs) (join deriv_ans (0 1) 1 __t1HCg50 __v0) (letp _00024sql7KCR139 (aslst _00024seq0)) (let _00024sqn6JCE140 (llen _00024sql7KCR139)) (cmp ge _00024sqn6JCE140 _00024sqc30eT141) (letp chk5RhD315 (lref _00024sql7KCR139 _00024sqc8YZJ142)) (eq c chk5RhD315) (let _00024sqp2g3G145 (_0002d _00024sqn6JCE140 _00024sqc1P4u144)) (let chk5zdT316 (lslice _00024sql7KCR139 _00024sqc24yE143 _00024sqp2g3G145)) (eq cs chk5zdT316)) (head (mkstruct run (1 2 0) __6qdL202 __v0 cs)) antimirov.slog:84 #f)
  class ReadTask472 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deriv_ansindex469;  slog::Index** $sup14449x83x0x0x0index470;  slog::Index** deriv_ansindex471;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run");
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord473({0, 1});
      slog::Relation* readrel474 = db->getRelation("deriv_ans");
      deriv_ansindex469 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({2, 4, 0, 1, 3});
      slog::Relation* readrel476 = db->getRelation("$sup14449x83x0x0x0");
      $sup14449x83x0x0x0index470 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("deriv_ans");
      deriv_ansindex471 = readrel478->getIndex(ord477, false);
  
    }
    ReadTask472(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<2,1>(deriv_ansindex469, std::array<u64,2>{v_c14, 0})) return;
        slog::join_probe<5,2>($sup14449x83x0x0x0index470, std::array<u64,5>{v_c6, v_c1, 0, 0, 0}, [&](const std::array<u64,5>& m479) {
          u64 v_c11 = m479[2]; u64 v_c12 = m479[3]; u64 v_c13 = m479[4];
          slog::join_probe<2,1>(deriv_ansindex471, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m480) {
            u64 v_c15 = m480[1];
            bool ok481 = true;
            u64 v_c16 = _prim_aslst(db, v_c11, &ok481);
            if (!ok481) return;
            u64 v_c17 = _prim_llen(db, v_c16);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c84 = _prim_ge(db, v_c17, v_c7);
            if (v_c84 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (!v_c84) return;
            bool ok483 = true;
            u64 v_c85 = _prim_lref(db, v_c16, v_c8, &ok483);
            if (!ok483) return;
            if (v_c6 != v_c85) return;
            u64 v_c20 = _prim__0002d(db, v_c17, v_c10);
            if (v_c20 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c86 = _prim_lslice(db, v_c16, v_c9, v_c20);
            if (v_c86 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (v_c13 != v_c86) return;
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c13}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask472* _cont = new ReadTask472(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask472(db,b), false);
  // (crule (pre) (scan state r) (body) (head (mkstruct nullable (1 0) __97Ck208 r)) antimirov.slog:116 #f)
  class ReadTask484 : public slog::Task
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
      head_rel[0] = db->getRelation("nullable");
      outer_rel = db->getRelation("state");
  
    }
    ReadTask484(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:116", "delta:state", _fires);
  
      if (!_done)
      {
        ReadTask484* _cont = new ReadTask484(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask484(db,b), false);
  // (crule (pre) (scan deriv __t2Ihd35 __t5FmK34 c) (body (join alt (0 1 2) 1 __t5FmK34 r s)) (head (emit $sup14449x68x0x0x0 (0 1 2 3) __t2Ihd35 c r s)) antimirov.slog:69 #f)
  class ReadTask486 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex485;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x68x0x0x0");
      std::vector<u16> ord487({0, 1, 2, 3});
      slog::Relation* readrel488 = db->getRelation("$sup14449x68x0x0x0");
      head_index[0] = readrel488->getIndex(ord487, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord489({0, 1, 2});
      slog::Relation* readrel490 = db->getRelation("alt");
      altindex485 = readrel490->getIndex(ord489, false);
  
    }
    ReadTask486(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c88 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<3,1>(altindex485, std::array<u64,3>{v_c88, 0, 0}, [&](const std::array<u64,3>& m491) {
          u64 v_c1 = m491[1]; u64 v_c2 = m491[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c87, v_c6, v_c1, v_c2}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask486* _cont = new ReadTask486(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask486(db,b), false);
  // (crule (pre (let _00024sqc6M7W172 const5feceb66ffc86f38d952786c)) (scan run __t0JBg84 r _00024seq0) (body (letp _00024sql7Elb170 (aslst _00024seq0)) (let chk4J74309 (llen _00024sql7Elb170)) (eq _00024sqc6M7W172 chk4J74309)) (head (mkstruct nullable (1 0) __5qgS207 r)) antimirov.slog:83 #f)
  class ReadTask492 : public slog::Task
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
      head_rel[0] = db->getRelation("nullable");
      outer_rel = db->getRelation("run");
  
    }
    ReadTask492(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c11 = _t[2];
        bool ok493 = true;
        u64 v_c91 = _prim_aslst(db, v_c11, &ok493);
        if (!ok493) return;
        u64 v_c92 = _prim_llen(db, v_c91);
        if (v_c92 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:83"); return; }
        if (v_c89 != v_c92) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:83", "delta:run", _fires);
  
      if (!_done)
      {
        ReadTask492* _cont = new ReadTask492(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask492(db,b), false);
  // (crule (pre (let __tconst7GyM108 const5feceb66ffc86f38d952786c)) (scan nullable __t3KPn107 r) (body (exists $sup14449x71x0x0x0 (2 3 0 1) 1 r) (join nullable_ans (0 1) 1 __t3KPn107 n) (cmp lt __tconst7GyM108 n) (join $sup14449x71x0x0x0 (2 3 0 1) 1 r s __d0 c)) (head (emit $sup14449x71x0x0x1 (0 2 1 3 4 5) __d0 c __t3KPn107 n r s)) antimirov.slog:72 #f)
  class ReadTask497 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x71x0x0x0index494;  slog::Index** nullable_ansindex495;  slog::Index** $sup14449x71x0x0x0index496;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord498({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel499 = db->getRelation("$sup14449x71x0x0x1");
      head_index[0] = readrel499->getIndex(ord498, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord500({2, 3, 0, 1});
      slog::Relation* readrel501 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index494 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("nullable_ans");
      nullable_ansindex495 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({2, 3, 0, 1});
      slog::Relation* readrel505 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index496 = readrel505->getIndex(ord504, false);
  
    }
    ReadTask497(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c94 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<4,1>($sup14449x71x0x0x0index494, std::array<u64,4>{v_c1, 0, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex495, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m506) {
          u64 v_c95 = m506[1];
          u64 v_c96 = _prim_lt(db, v_c93, v_c95);
          if (v_c96 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c96) return;
          slog::join_probe<4,1>($sup14449x71x0x0x0index496, std::array<u64,4>{v_c1, 0, 0, 0}, [&](const std::array<u64,4>& m508) {
            u64 v_c2 = m508[1]; u64 v_c12 = m508[2]; u64 v_c6 = m508[3];
            ++_fires;
            slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c12, v_c6, v_c94, v_c95, v_c1, v_c2}, std::array<u16,6>{0, 2, 1, 3, 4, 5});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask497* _cont = new ReadTask497(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask497(db,b), false);
  // (crule (pre) (scan alt __t1uAM12 r s) (body (exists deriv (1 2 0) 1 __t1uAM12) (exists deriv (1 2 0) 1 r) (join $sup14449x68x0x0x0 (2 3 0 1) 2 r s __t2Yus13 c) (join-old deriv (0 1 2) 3 (0 1 2) __t2Yus13 __t1uAM12 c) (join-old deriv (1 2 0) 2 (1 2 0) r c __t2byM14) (join deriv_ans (0 1) 1 __t2byM14 __v0)) (head (emit deriv_ans (0 1) __t2Yus13 __v0)) antimirov.slog:69 #f)
  class ReadTask517 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex509;  slog::Index** derivindex510;  slog::Index** $sup14449x68x0x0x0index511;  slog::Index** derivindex512;  slog::Index** derivindex513;  slog::Index** deriv_ansindex514;  slog::Index** derivdelta515;  slog::Index** derivdelta516;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord518({0, 1});
      slog::Relation* readrel519 = db->getRelation("deriv_ans");
      head_index[0] = readrel519->getIndex(ord518, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord520({1, 2, 0});
      slog::Relation* readrel521 = db->getRelation("deriv");
      derivindex509 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("deriv");
      derivindex510 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({2, 3, 0, 1});
      slog::Relation* readrel525 = db->getRelation("$sup14449x68x0x0x0");
      $sup14449x68x0x0x0index511 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 1, 2});
      slog::Relation* readrel527 = db->getRelation("deriv");
      derivindex512 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("deriv");
      derivdelta515 = readrel529->getIndex(ord528, true);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("deriv");
      derivindex513 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("deriv");
      derivdelta516 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("deriv_ans");
      deriv_ansindex514 = readrel535->getIndex(ord534, false);
  
    }
    ReadTask517(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex509, std::array<u64,3>{v_c80, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex510, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x68x0x0x0index511, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m536) {
          u64 v_c79 = m536[2]; u64 v_c6 = m536[3];
          slog::join_probe_old<3,3>(derivindex512, derivdelta515, std::array<u64,3>{v_c79, v_c80, v_c6}, [&](const std::array<u64,3>& m537) {
            slog::join_probe_old<3,2>(derivindex513, derivdelta516, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m538) {
              u64 v_c78 = m538[2];
              slog::join_probe<2,1>(deriv_ansindex514, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m539) {
                u64 v_c15 = m539[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c15}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask517* _cont = new ReadTask517(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask517(db,b), false);
  // (crule (pre) (scan nullable __t6Byf113 r) (body (exists $sup14449x46x0x0x0 (1 2 0) 1 r) (exists alt (1 2 0) 1 r) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (join $sup14449x46x0x0x0 (1 2 0) 1 r s __t4S29112) (exists nullable (1 0) 1 s) (join alt (1 2 0) 2 r s __t8cCt111) (join nullable (0 1) 2 __t4S29112 __t8cCt111) (join-old nullable (1 0) 1 (1 0) s __t0lgX114) (join nullable_ans (0 1) 1 __t0lgX114 __v1) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x46x0x0x0index540;  slog::Index** altindex541;  slog::Index** nullable_ansindex542;  slog::Index** $sup14449x46x0x0x0index543;  slog::Index** nullableindex544;  slog::Index** altindex545;  slog::Index** nullableindex546;  slog::Index** nullableindex547;  slog::Index** nullable_ansindex548;  slog::Index** nullabledelta549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index540 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 0});
      slog::Relation* readrel554 = db->getRelation("alt");
      altindex541 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 1});
      slog::Relation* readrel556 = db->getRelation("nullable_ans");
      nullable_ansindex542 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({1, 2, 0});
      slog::Relation* readrel558 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index543 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 0});
      slog::Relation* readrel560 = db->getRelation("nullable");
      nullableindex544 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("alt");
      altindex545 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({0, 1});
      slog::Relation* readrel564 = db->getRelation("nullable");
      nullableindex546 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 0});
      slog::Relation* readrel566 = db->getRelation("nullable");
      nullableindex547 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 0});
      slog::Relation* readrel568 = db->getRelation("nullable");
      nullabledelta549 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({0, 1});
      slog::Relation* readrel570 = db->getRelation("nullable_ans");
      nullable_ansindex548 = readrel570->getIndex(ord569, false);
  
    }
    ReadTask550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<3,1>($sup14449x46x0x0x0index540, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(altindex541, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex542, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m571) {
          u64 v_c15 = m571[1];
          slog::join_probe<3,1>($sup14449x46x0x0x0index543, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m572) {
            u64 v_c2 = m572[1]; u64 v_c36 = m572[2];
            if (!slog::exists_probe<2,1>(nullableindex544, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(altindex545, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m573) {
              u64 v_c35 = m573[2];
              slog::join_probe<2,2>(nullableindex546, std::array<u64,2>{v_c36, v_c35}, [&](const std::array<u64,2>& m574) {
                slog::join_probe_old<2,1>(nullableindex547, nullabledelta549, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m575) {
                  u64 v_c38 = m575[1];
                  slog::join_probe<2,1>(nullable_ansindex548, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m576) {
                    u64 v_c26 = m576[1];
                    u64 v_c39 = _prim_max(db, v_c15, v_c26);
                    if (v_c39 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c39, v_c36});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask550* _cont = new ReadTask550(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask550(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (once) (body) (head (mkstruct chr (1 0) __t4w1Y98 __tconst3Xg1100) (mkstruct chr (1 0) __t6I9I96 __tconst8qEb95)) antimirov.slog:130 #f)
  class ReadTask577 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("chr");
      head_rel[1] = db->getRelation("chr");
  
    }
    ReadTask577(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c98 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c99 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c98}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c99}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask577(db,b), true);
  // (crule (pre) (scan temp4ebc327 __t0JJd26 __t2GkP27 s) (body (join cat (1 2 0) 2 __t0JJd26 s __t2o7L25)) (head (emit mkcat_ans (0 1) __t2GkP27 __t2o7L25)) antimirov.slog:59 #f)
  class ReadTask579 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex578;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat_ans");
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("mkcat_ans");
      head_index[0] = readrel581->getIndex(ord580, false);
      outer_rel = db->getRelation("temp4ebc327");
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("cat");
      catindex578 = readrel583->getIndex(ord582, false);
  
    }
    ReadTask579(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(catindex578, std::array<u64,3>{v_c100, v_c2, 0}, [&](const std::array<u64,3>& m584) {
          u64 v_c102 = m584[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c102}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:59", "delta:temp4ebc327", _fires);
  
      if (!_done)
      {
        ReadTask579* _cont = new ReadTask579(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask579(db,b), false);
  // (crule (pre) (scan $sup14449x70x0x0x0 __t1fTl18 c r s) (body (exists deriv (2 0 1) 2 c __t1fTl18) (exists deriv (1 2 0) 2 r c) (exists mkcat (2 0 1) 1 s) (join-old cat (1 2 0) 2 (1 2 0) r s __t9RZg17) (join-old deriv (0 1 2) 3 (0 1 2) __t1fTl18 __t9RZg17 c) (join-old deriv (1 2 0) 2 (1 2 0) r c __t3USy19) (join deriv_ans (0 1) 1 __t3USy19 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 s __t3Hfq20) (join mkcat_ans (0 1) 1 __t3Hfq20 __v1)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex585;  slog::Index** derivindex586;  slog::Index** mkcatindex587;  slog::Index** catindex588;  slog::Index** derivindex589;  slog::Index** derivindex590;  slog::Index** deriv_ansindex591;  slog::Index** mkcatindex592;  slog::Index** mkcat_ansindex593;  slog::Index** catdelta594;  slog::Index** derivdelta595;  slog::Index** derivdelta596;  slog::Index** mkcatdelta597;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("deriv_ans");
      head_index[0] = readrel600->getIndex(ord599, false);
      outer_rel = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord601({2, 0, 1});
      slog::Relation* readrel602 = db->getRelation("deriv");
      derivindex585 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("deriv");
      derivindex586 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({2, 0, 1});
      slog::Relation* readrel606 = db->getRelation("mkcat");
      mkcatindex587 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 2, 0});
      slog::Relation* readrel608 = db->getRelation("cat");
      catindex588 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 2, 0});
      slog::Relation* readrel610 = db->getRelation("cat");
      catdelta594 = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({0, 1, 2});
      slog::Relation* readrel612 = db->getRelation("deriv");
      derivindex589 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({0, 1, 2});
      slog::Relation* readrel614 = db->getRelation("deriv");
      derivdelta595 = readrel614->getIndex(ord613, true);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("deriv");
      derivindex590 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("deriv");
      derivdelta596 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("deriv_ans");
      deriv_ansindex591 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("mkcat");
      mkcatindex592 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 2, 0});
      slog::Relation* readrel624 = db->getRelation("mkcat");
      mkcatdelta597 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({0, 1});
      slog::Relation* readrel626 = db->getRelation("mkcat_ans");
      mkcat_ansindex593 = readrel626->getIndex(ord625, false);
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        if (!slog::exists_probe<3,2>(derivindex585, std::array<u64,3>{v_c6, v_c41, 0})) return;
        if (!slog::exists_probe<3,2>(derivindex586, std::array<u64,3>{v_c1, v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(mkcatindex587, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe_old<3,2>(catindex588, catdelta594, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m627) {
          u64 v_c42 = m627[2];
          slog::join_probe_old<3,3>(derivindex589, derivdelta595, std::array<u64,3>{v_c41, v_c42, v_c6}, [&](const std::array<u64,3>& m628) {
            slog::join_probe_old<3,2>(derivindex590, derivdelta596, std::array<u64,3>{v_c1, v_c6, 0}, [&](const std::array<u64,3>& m629) {
              u64 v_c40 = m629[2];
              slog::join_probe<2,1>(deriv_ansindex591, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m630) {
                u64 v_c15 = m630[1];
                slog::join_probe_old<3,2>(mkcatindex592, mkcatdelta597, std::array<u64,3>{v_c15, v_c2, 0}, [&](const std::array<u64,3>& m631) {
                  u64 v_c43 = m631[2];
                  slog::join_probe<2,1>(mkcat_ansindex593, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m632) {
                    u64 v_c26 = m632[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c26}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:$sup14449x70x0x0x0", _fires);
  
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
  // (crule (pre) (scan state r) (body (join alpha (0) 0 c)) (head (mkstruct deriv (1 2 0) __6P3l230 r c)) antimirov.slog:115 #f)
  class ReadTask634 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** alphaindex633;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv");
      outer_rel = db->getRelation("state");
      std::vector<u16> ord635({0});
      slog::Relation* readrel636 = db->getRelation("alpha");
      alphaindex633 = readrel636->getIndex(ord635, false);
  
    }
    ReadTask634(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_all<1>(alphaindex633, [&](const std::array<u64,1>& m637) {
          u64 v_c6 = m637[0];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:state", _fires);
  
      if (!_done)
      {
        ReadTask634* _cont = new ReadTask634(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask634(db,b), false);
  // (crule (pre) (scan nullable_ans __t7OBQ88 __v0) (body (join-old nullable (0 1) 1 (0 1) __t7OBQ88 r) (exists cat (1 2 0) 1 r) (join-old $sup14449x45x0x0x0 (1 2 0) 1 (1 2 0) r s __t7U0R87) (exists nullable (1 0) 1 s) (join-old cat (1 2 0) 2 (1 2 0) r s __t3mF986) (join-old nullable (0 1) 2 (0 1) __t7U0R87 __t3mF986) (join-old nullable (1 0) 1 (1 0) s __t5WkW89) (join-old nullable_ans (0 1) 1 (0 1) __t5WkW89 __v1) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask652 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex638;  slog::Index** catindex639;  slog::Index** $sup14449x45x0x0x0index640;  slog::Index** nullableindex641;  slog::Index** catindex642;  slog::Index** nullableindex643;  slog::Index** nullableindex644;  slog::Index** nullable_ansindex645;  slog::Index** nullabledelta646;  slog::Index** $sup14449x45x0x0x0delta647;  slog::Index** catdelta648;  slog::Index** nullabledelta649;  slog::Index** nullabledelta650;  slog::Index** nullable_ansdelta651;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord653({0, 1});
      slog::Relation* readrel654 = db->getRelation("nullable");
      nullableindex638 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("nullable");
      nullabledelta646 = readrel656->getIndex(ord655, true);
      std::vector<u16> ord657({1, 2, 0});
      slog::Relation* readrel658 = db->getRelation("cat");
      catindex639 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 0});
      slog::Relation* readrel660 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index640 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 2, 0});
      slog::Relation* readrel662 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0delta647 = readrel662->getIndex(ord661, true);
      std::vector<u16> ord663({1, 0});
      slog::Relation* readrel664 = db->getRelation("nullable");
      nullableindex641 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("cat");
      catindex642 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 0});
      slog::Relation* readrel668 = db->getRelation("cat");
      catdelta648 = readrel668->getIndex(ord667, true);
      std::vector<u16> ord669({0, 1});
      slog::Relation* readrel670 = db->getRelation("nullable");
      nullableindex643 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({0, 1});
      slog::Relation* readrel672 = db->getRelation("nullable");
      nullabledelta649 = readrel672->getIndex(ord671, true);
      std::vector<u16> ord673({1, 0});
      slog::Relation* readrel674 = db->getRelation("nullable");
      nullableindex644 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({1, 0});
      slog::Relation* readrel676 = db->getRelation("nullable");
      nullabledelta650 = readrel676->getIndex(ord675, true);
      std::vector<u16> ord677({0, 1});
      slog::Relation* readrel678 = db->getRelation("nullable_ans");
      nullable_ansindex645 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({0, 1});
      slog::Relation* readrel680 = db->getRelation("nullable_ans");
      nullable_ansdelta651 = readrel680->getIndex(ord679, true);
  
    }
    ReadTask652(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe_old<2,1>(nullableindex638, nullabledelta646, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m681) {
          u64 v_c1 = m681[1];
          if (!slog::exists_probe<3,1>(catindex639, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<3,1>($sup14449x45x0x0x0index640, $sup14449x45x0x0x0delta647, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m682) {
            u64 v_c2 = m682[1]; u64 v_c23 = m682[2];
            if (!slog::exists_probe<2,1>(nullableindex641, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<3,2>(catindex642, catdelta648, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m683) {
              u64 v_c22 = m683[2];
              slog::join_probe_old<2,2>(nullableindex643, nullabledelta649, std::array<u64,2>{v_c23, v_c22}, [&](const std::array<u64,2>& m684) {
                slog::join_probe_old<2,1>(nullableindex644, nullabledelta650, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m685) {
                  u64 v_c25 = m685[1];
                  slog::join_probe_old<2,1>(nullable_ansindex645, nullable_ansdelta651, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m686) {
                    u64 v_c26 = m686[1];
                    u64 v_c27 = _prim__0002a(db, v_c15, v_c26);
                    if (v_c27 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c23});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:nullable_ans", _fires);
  
      if (!_done)
      {
        ReadTask652* _cont = new ReadTask652(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask652(db,b), false);
  // (crule (pre) (scan deriv __t6IFg8 __t6BEs7 c) (body (join alt (0 1 2) 1 __t6BEs7 r s)) (head (emit $sup14449x69x0x0x0 (0 1 2 3) __t6IFg8 c r s)) antimirov.slog:70 #f)
  class ReadTask688 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex687;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x69x0x0x0");
      std::vector<u16> ord689({0, 1, 2, 3});
      slog::Relation* readrel690 = db->getRelation("$sup14449x69x0x0x0");
      head_index[0] = readrel690->getIndex(ord689, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord691({0, 1, 2});
      slog::Relation* readrel692 = db->getRelation("alt");
      altindex687 = readrel692->getIndex(ord691, false);
  
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
        u64 v_c48 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<3,1>(altindex687, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m693) {
          u64 v_c1 = m693[1]; u64 v_c2 = m693[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c48, v_c6, v_c1, v_c2}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:deriv", _fires);
  
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
  // (crule (pre (let __trid1Yip218 const4ab8424ce3e463ada0064da8) (let __trel133X219 const0dfced6e06d4ae6199e0f896) (let __tcol8VY5220 const5feceb66ffc86f38d952786c) (let __trel1Zaw221 const0dfced6e06d4ae6199e0f896) (let __tcol0Vg2222 const6b86b273ff34fce19d6b804e)) (scan $sup14449x83x0x0x0 _00024seq0 __d0 c cs r) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid1Yip218 __trel133X219 __tcol8VY5220 (1 2 3 4 0)) (tycheck c (accept str) __trid1Yip218 __trel1Zaw221 __tcol0Vg2222 (1 2 3 4 0)) (mkstruct deriv (1 2 0) __8LVH217 r c)) antimirov.slog:84 #f)
  class ReadTask699 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid697;  u32 sid694;  u32 sid695;  u32 sid696;  u32 sid698;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("deriv");
      outer_rel = db->getRelation("$sup14449x83x0x0x0");
      sid697 = db->getRelation("_enum")->getStructId();
      sid694 = db->getRelation("alt")->getStructId();
      sid695 = db->getRelation("cat")->getStructId();
      sid696 = db->getRelation("chr")->getStructId();
      sid698 = db->getRelation("star")->getStructId();
  
    }
    ReadTask699(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const4ab8424ce3e463ada0064da8;
      u64 v_c104 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c105 = v_const5feceb66ffc86f38d952786c;
      u64 v_c106 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c1 = _t[4];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid694 || decode_struct_id(v_c1) == sid695 || decode_struct_id(v_c1) == sid696 || decode_struct_id(v_c1) == sid697 || decode_struct_id(v_c1) == sid698))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c103, v_c104, v_c105, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c103, v_c106, v_c107, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:$sup14449x83x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask699* _cont = new ReadTask699(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask699(db,b), false);
  // (crule (pre (let _00024sqc9HcA162 const6b86b273ff34fce19d6b804e) (let _00024sqc1KHV163 const5feceb66ffc86f38d952786c) (let _00024sqc1g5Q164 const6b86b273ff34fce19d6b804e) (let _00024sqc548L165 const5feceb66ffc86f38d952786c)) (scan run __t2lYh51 r _00024seq0) (body (letp _00024sql3Qp9160 (aslst _00024seq0)) (let _00024sqn2dnn161 (llen _00024sql3Qp9160)) (cmp ge _00024sqn2dnn161 _00024sqc9HcA162) (letp c (lref _00024sql3Qp9160 _00024sqc1KHV163)) (let _00024sqp2HD9166 (_0002d _00024sqn2dnn161 _00024sqc548L165)) (let cs (lslice _00024sql3Qp9160 _00024sqc1g5Q164 _00024sqp2HD9166))) (head (emit $sup14449x83x0x0x0 (2 4 0 1 3) c r _00024seq0 __t2lYh51 cs)) antimirov.slog:84 #f)
  class ReadTask700 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup14449x83x0x0x0");
      std::vector<u16> ord701({2, 4, 0, 1, 3});
      slog::Relation* readrel702 = db->getRelation("$sup14449x83x0x0x0");
      head_index[0] = readrel702->getIndex(ord701, false);
      outer_rel = db->getRelation("run");
  
    }
    ReadTask700(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c112 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c11 = _t[2];
        bool ok703 = true;
        u64 v_c113 = _prim_aslst(db, v_c11, &ok703);
        if (!ok703) return;
        u64 v_c114 = _prim_llen(db, v_c113);
        if (v_c114 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        u64 v_c115 = _prim_ge(db, v_c114, v_c108);
        if (v_c115 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        if (!v_c115) return;
        bool ok705 = true;
        u64 v_c6 = _prim_lref(db, v_c113, v_c109, &ok705);
        if (!ok705) return;
        u64 v_c116 = _prim__0002d(db, v_c114, v_c111);
        if (v_c116 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        u64 v_c13 = _prim_lslice(db, v_c113, v_c110, v_c116);
        if (v_c13 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c6, v_c1, v_c11, v_c112, v_c13}, std::array<u16,5>{2, 4, 0, 1, 3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:run", _fires);
  
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
  // (crule (pre) (scan mkcat_ans __t3A2z5 __v1) (body (join-old mkcat (0 1 2) 1 (0 1 2) __t3A2z5 __v0 __t3xJI4) (exists deriv (1 2 0) 1 __t3xJI4) (join deriv_ans (1 0) 1 __v0 __t70si3) (join-old star (0 1) 1 (0 1) __t3xJI4 r) (join-old deriv (0 1 2) 2 (0 1 2) __t70si3 r c) (join-old deriv (1 2 0) 2 (1 2 0) __t3xJI4 c __t9dkM2)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask716 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex706;  slog::Index** derivindex707;  slog::Index** deriv_ansindex708;  slog::Index** starindex709;  slog::Index** derivindex710;  slog::Index** derivindex711;  slog::Index** mkcatdelta712;  slog::Index** stardelta713;  slog::Index** derivdelta714;  slog::Index** derivdelta715;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord717({0, 1});
      slog::Relation* readrel718 = db->getRelation("deriv_ans");
      head_index[0] = readrel718->getIndex(ord717, false);
      outer_rel = db->getRelation("mkcat_ans");
      std::vector<u16> ord719({0, 1, 2});
      slog::Relation* readrel720 = db->getRelation("mkcat");
      mkcatindex706 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({0, 1, 2});
      slog::Relation* readrel722 = db->getRelation("mkcat");
      mkcatdelta712 = readrel722->getIndex(ord721, true);
      std::vector<u16> ord723({1, 2, 0});
      slog::Relation* readrel724 = db->getRelation("deriv");
      derivindex707 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0});
      slog::Relation* readrel726 = db->getRelation("deriv_ans");
      deriv_ansindex708 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({0, 1});
      slog::Relation* readrel728 = db->getRelation("star");
      starindex709 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({0, 1});
      slog::Relation* readrel730 = db->getRelation("star");
      stardelta713 = readrel730->getIndex(ord729, true);
      std::vector<u16> ord731({0, 1, 2});
      slog::Relation* readrel732 = db->getRelation("deriv");
      derivindex710 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({0, 1, 2});
      slog::Relation* readrel734 = db->getRelation("deriv");
      derivdelta714 = readrel734->getIndex(ord733, true);
      std::vector<u16> ord735({1, 2, 0});
      slog::Relation* readrel736 = db->getRelation("deriv");
      derivindex711 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 2, 0});
      slog::Relation* readrel738 = db->getRelation("deriv");
      derivdelta715 = readrel738->getIndex(ord737, true);
  
    }
    ReadTask716(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c117 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe_old<3,1>(mkcatindex706, mkcatdelta712, std::array<u64,3>{v_c117, 0, 0}, [&](const std::array<u64,3>& m739) {
          u64 v_c15 = m739[1]; u64 v_c118 = m739[2];
          if (!slog::exists_probe<3,1>(derivindex707, std::array<u64,3>{v_c118, 0, 0})) return;
          slog::join_probe<2,1>(deriv_ansindex708, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m740) {
            u64 v_c119 = m740[1];
            slog::join_probe_old<2,1>(starindex709, stardelta713, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m741) {
              u64 v_c1 = m741[1];
              slog::join_probe_old<3,2>(derivindex710, derivdelta714, std::array<u64,3>{v_c119, v_c1, 0}, [&](const std::array<u64,3>& m742) {
                u64 v_c6 = m742[2];
                slog::join_probe_old<3,2>(derivindex711, derivdelta715, std::array<u64,3>{v_c118, v_c6, 0}, [&](const std::array<u64,3>& m743) {
                  u64 v_c120 = m743[2];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c120, v_c26}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:mkcat_ans", _fires);
  
      if (!_done)
      {
        ReadTask716* _cont = new ReadTask716(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask716(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst8qEb95 __t6I9I96) (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98)) (head (mkstruct cat (1 2 0) __t4yUC99 __t4w1Y98 __t6I9I96)) antimirov.slog:130 #f)
  class ReadTask746 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex744;  slog::Index** chrindex745;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("cat");
      std::vector<u16> ord747({1, 2, 0});
      slog::Relation* readrel748 = db->getRelation("cat");
      head_index[0] = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 0});
      slog::Relation* readrel750 = db->getRelation("chr");
      chrindex744 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 0});
      slog::Relation* readrel752 = db->getRelation("chr");
      chrindex745 = readrel752->getIndex(ord751, false);
  
    }
    ReadTask746(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c97 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c98 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c99 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex744, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m753) {
        u64 v_c121 = m753[1];
        slog::join_probe<2,1>(chrindex745, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m754) {
          u64 v_c122 = m754[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c122, v_c121}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask746(db,b));
  // (crule (pre (let __trid7ZnL187 const30749c2c8a5c40a4f0a780b6) (let __trel9fHp188 constd1596cb698715803872591d6) (let __tcol6chB189 const5feceb66ffc86f38d952786c)) (scan $sup14449x45x0x0x0 __d0 r s) (body) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid7ZnL187 __trel9fHp188 __tcol6chB189 (1 2 3 4 0)) (mkstruct nullable (1 0) __9nym186 s)) antimirov.slog:46 #f)
  class ReadTask760 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid758;  u32 sid755;  u32 sid756;  u32 sid757;  u32 sid759;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("nullable");
      outer_rel = db->getRelation("$sup14449x45x0x0x0");
      sid758 = db->getRelation("_enum")->getStructId();
      sid755 = db->getRelation("alt")->getStructId();
      sid756 = db->getRelation("cat")->getStructId();
      sid757 = db->getRelation("chr")->getStructId();
      sid759 = db->getRelation("star")->getStructId();
  
    }
    ReadTask760(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c123 = v_const30749c2c8a5c40a4f0a780b6;
      u64 v_c124 = v_constd1596cb698715803872591d6;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid755 || decode_struct_id(v_c2) == sid756 || decode_struct_id(v_c2) == sid757 || decode_struct_id(v_c2) == sid758 || decode_struct_id(v_c2) == sid759))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c123, v_c124, v_c125, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:$sup14449x45x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask760* _cont = new ReadTask760(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask760(db,b), false);
  // (crule (pre (let __tconst70YG21 const5feceb66ffc86f38d952786c)) (scan nullable __t71qa23 __t39D622) (body (join chr (0 1) 1 __t39D622 c)) (head (emit nullable_ans (0 1) __t71qa23 __tconst70YG21)) antimirov.slog:44 #f)
  class ReadTask762 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex761;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord763({0, 1});
      slog::Relation* readrel764 = db->getRelation("nullable_ans");
      head_index[0] = readrel764->getIndex(ord763, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("chr");
      chrindex761 = readrel766->getIndex(ord765, false);
  
    }
    ReadTask762(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c127 = _t[0];
        u64 v_c128 = _t[1];
        slog::join_probe<2,1>(chrindex761, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m767) {
          u64 v_c6 = m767[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c127, v_c126}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:44", "delta:nullable", _fires);
  
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
  // (crule (pre) (scan nullable __t7U0R87 __t3mF986) (body (join $sup14449x45x0x0x0 (0 1 2) 1 __t7U0R87 r s) (join cat (0 1 2) 3 __t3mF986 r s) (exists nullable (1 0) 1 s) (join-old nullable (1 0) 1 (1 0) r __t7OBQ88) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (join-old nullable (1 0) 1 (1 0) s __t5WkW89) (join nullable_ans (0 1) 1 __t5WkW89 __v1) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask777 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x45x0x0x0index768;  slog::Index** catindex769;  slog::Index** nullableindex770;  slog::Index** nullableindex771;  slog::Index** nullable_ansindex772;  slog::Index** nullableindex773;  slog::Index** nullable_ansindex774;  slog::Index** nullabledelta775;  slog::Index** nullabledelta776;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord778({0, 1, 2});
      slog::Relation* readrel779 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index768 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({0, 1, 2});
      slog::Relation* readrel781 = db->getRelation("cat");
      catindex769 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 0});
      slog::Relation* readrel783 = db->getRelation("nullable");
      nullableindex770 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 0});
      slog::Relation* readrel785 = db->getRelation("nullable");
      nullableindex771 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 0});
      slog::Relation* readrel787 = db->getRelation("nullable");
      nullabledelta775 = readrel787->getIndex(ord786, true);
      std::vector<u16> ord788({0, 1});
      slog::Relation* readrel789 = db->getRelation("nullable_ans");
      nullable_ansindex772 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 0});
      slog::Relation* readrel791 = db->getRelation("nullable");
      nullableindex773 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 0});
      slog::Relation* readrel793 = db->getRelation("nullable");
      nullabledelta776 = readrel793->getIndex(ord792, true);
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("nullable_ans");
      nullable_ansindex774 = readrel795->getIndex(ord794, false);
  
    }
    ReadTask777(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        slog::join_probe<3,1>($sup14449x45x0x0x0index768, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m796) {
          u64 v_c1 = m796[1]; u64 v_c2 = m796[2];
          slog::join_probe<3,3>(catindex769, std::array<u64,3>{v_c22, v_c1, v_c2}, [&](const std::array<u64,3>& m797) {
            if (!slog::exists_probe<2,1>(nullableindex770, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<2,1>(nullableindex771, nullabledelta775, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m798) {
              u64 v_c24 = m798[1];
              slog::join_probe<2,1>(nullable_ansindex772, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m799) {
                u64 v_c15 = m799[1];
                slog::join_probe_old<2,1>(nullableindex773, nullabledelta776, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m800) {
                  u64 v_c25 = m800[1];
                  slog::join_probe<2,1>(nullable_ansindex774, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m801) {
                    u64 v_c26 = m801[1];
                    u64 v_c27 = _prim__0002a(db, v_c15, v_c26);
                    if (v_c27 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c27, v_c23});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask777* _cont = new ReadTask777(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask777(db,b), false);
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan $sup14449x71x0x0x1 __t2zzw123 __t95K4125 c n r s) (body (cmp lt __tconst0Lyv124 n) (join $sup14449x71x0x0x0 (0 1 2 3) 4 __t2zzw123 c r s) (join nullable_ans (0 1) 2 __t95K4125 n) (join-old nullable (0 1) 2 (0 1) __t95K4125 r) (exists deriv (2 0 1) 2 c __t2zzw123) (exists deriv (1 2 0) 2 s c) (join-old cat (1 2 0) 2 (1 2 0) r s __t4VgL122) (join-old deriv (0 1 2) 3 (0 1 2) __t2zzw123 __t4VgL122 c) (join-old deriv (1 2 0) 2 (1 2 0) s c __t17NK126) (join deriv_ans (0 1) 1 __t17NK126 __v0)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask815 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x71x0x0x0index802;  slog::Index** nullable_ansindex803;  slog::Index** nullableindex804;  slog::Index** derivindex805;  slog::Index** derivindex806;  slog::Index** catindex807;  slog::Index** derivindex808;  slog::Index** derivindex809;  slog::Index** deriv_ansindex810;  slog::Index** nullabledelta811;  slog::Index** catdelta812;  slog::Index** derivdelta813;  slog::Index** derivdelta814;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord816({0, 1});
      slog::Relation* readrel817 = db->getRelation("deriv_ans");
      head_index[0] = readrel817->getIndex(ord816, false);
      outer_rel = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord818({0, 1, 2, 3});
      slog::Relation* readrel819 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index802 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("nullable_ans");
      nullable_ansindex803 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("nullable");
      nullableindex804 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("nullable");
      nullabledelta811 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({2, 0, 1});
      slog::Relation* readrel827 = db->getRelation("deriv");
      derivindex805 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("deriv");
      derivindex806 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 2, 0});
      slog::Relation* readrel831 = db->getRelation("cat");
      catindex807 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 0});
      slog::Relation* readrel833 = db->getRelation("cat");
      catdelta812 = readrel833->getIndex(ord832, true);
      std::vector<u16> ord834({0, 1, 2});
      slog::Relation* readrel835 = db->getRelation("deriv");
      derivindex808 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1, 2});
      slog::Relation* readrel837 = db->getRelation("deriv");
      derivdelta813 = readrel837->getIndex(ord836, true);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("deriv");
      derivindex809 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 0});
      slog::Relation* readrel841 = db->getRelation("deriv");
      derivdelta814 = readrel841->getIndex(ord840, true);
      std::vector<u16> ord842({0, 1});
      slog::Relation* readrel843 = db->getRelation("deriv_ans");
      deriv_ansindex810 = readrel843->getIndex(ord842, false);
  
    }
    ReadTask815(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c95 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c132 = _prim_lt(db, v_c129, v_c95);
        if (v_c132 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
        if (!v_c132) return;
        slog::join_probe<4,4>($sup14449x71x0x0x0index802, std::array<u64,4>{v_c130, v_c6, v_c1, v_c2}, [&](const std::array<u64,4>& m845) {
          slog::join_probe<2,2>(nullable_ansindex803, std::array<u64,2>{v_c131, v_c95}, [&](const std::array<u64,2>& m846) {
            slog::join_probe_old<2,2>(nullableindex804, nullabledelta811, std::array<u64,2>{v_c131, v_c1}, [&](const std::array<u64,2>& m847) {
              if (!slog::exists_probe<3,2>(derivindex805, std::array<u64,3>{v_c6, v_c130, 0})) return;
              if (!slog::exists_probe<3,2>(derivindex806, std::array<u64,3>{v_c2, v_c6, 0})) return;
              slog::join_probe_old<3,2>(catindex807, catdelta812, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m848) {
                u64 v_c133 = m848[2];
                slog::join_probe_old<3,3>(derivindex808, derivdelta813, std::array<u64,3>{v_c130, v_c133, v_c6}, [&](const std::array<u64,3>& m849) {
                  slog::join_probe_old<3,2>(derivindex809, derivdelta814, std::array<u64,3>{v_c2, v_c6, 0}, [&](const std::array<u64,3>& m850) {
                    u64 v_c134 = m850[2];
                    slog::join_probe<2,1>(deriv_ansindex810, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m851) {
                      u64 v_c15 = m851[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c130, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:$sup14449x71x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask815* _cont = new ReadTask815(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask815(db,b), false);
  // (crule (pre) (scan $sup14449x69x0x0x0 __t0tyF119 c r s) (body (exists deriv (2 0 1) 2 c __t0tyF119) (exists deriv (1 2 0) 2 s c) (join-old alt (1 2 0) 2 (1 2 0) r s __t2ubg118) (join-old deriv (0 1 2) 3 (0 1 2) __t0tyF119 __t2ubg118 c) (join-old deriv (1 2 0) 2 (1 2 0) s c __t72SS120) (join deriv_ans (0 1) 1 __t72SS120 __v0)) (head (emit deriv_ans (0 1) __t0tyF119 __v0)) antimirov.slog:70 #f)
  class ReadTask861 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex852;  slog::Index** derivindex853;  slog::Index** altindex854;  slog::Index** derivindex855;  slog::Index** derivindex856;  slog::Index** deriv_ansindex857;  slog::Index** altdelta858;  slog::Index** derivdelta859;  slog::Index** derivdelta860;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord862({0, 1});
      slog::Relation* readrel863 = db->getRelation("deriv_ans");
      head_index[0] = readrel863->getIndex(ord862, false);
      outer_rel = db->getRelation("$sup14449x69x0x0x0");
      std::vector<u16> ord864({2, 0, 1});
      slog::Relation* readrel865 = db->getRelation("deriv");
      derivindex852 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({1, 2, 0});
      slog::Relation* readrel867 = db->getRelation("deriv");
      derivindex853 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({1, 2, 0});
      slog::Relation* readrel869 = db->getRelation("alt");
      altindex854 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({1, 2, 0});
      slog::Relation* readrel871 = db->getRelation("alt");
      altdelta858 = readrel871->getIndex(ord870, true);
      std::vector<u16> ord872({0, 1, 2});
      slog::Relation* readrel873 = db->getRelation("deriv");
      derivindex855 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1, 2});
      slog::Relation* readrel875 = db->getRelation("deriv");
      derivdelta859 = readrel875->getIndex(ord874, true);
      std::vector<u16> ord876({1, 2, 0});
      slog::Relation* readrel877 = db->getRelation("deriv");
      derivindex856 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({1, 2, 0});
      slog::Relation* readrel879 = db->getRelation("deriv");
      derivdelta860 = readrel879->getIndex(ord878, true);
      std::vector<u16> ord880({0, 1});
      slog::Relation* readrel881 = db->getRelation("deriv_ans");
      deriv_ansindex857 = readrel881->getIndex(ord880, false);
  
    }
    ReadTask861(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c2 = _t[3];
        if (!slog::exists_probe<3,2>(derivindex852, std::array<u64,3>{v_c6, v_c45, 0})) return;
        if (!slog::exists_probe<3,2>(derivindex853, std::array<u64,3>{v_c2, v_c6, 0})) return;
        slog::join_probe_old<3,2>(altindex854, altdelta858, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m882) {
          u64 v_c44 = m882[2];
          slog::join_probe_old<3,3>(derivindex855, derivdelta859, std::array<u64,3>{v_c45, v_c44, v_c6}, [&](const std::array<u64,3>& m883) {
            slog::join_probe_old<3,2>(derivindex856, derivdelta860, std::array<u64,3>{v_c2, v_c6, 0}, [&](const std::array<u64,3>& m884) {
              u64 v_c46 = m884[2];
              slog::join_probe<2,1>(deriv_ansindex857, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m885) {
                u64 v_c15 = m885[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c15}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:$sup14449x69x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask861* _cont = new ReadTask861(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask861(db,b), false);
  // (crule (pre (let __trid8XBR181 constf0add80747aca33dead79eea) (let __trel4v2k182 const0dfced6e06d4ae6199e0f896) (let __tcol6eY0183 const5feceb66ffc86f38d952786c) (let __trel2kAM184 const0dfced6e06d4ae6199e0f896) (let __tcol6TDG185 const6b86b273ff34fce19d6b804e)) (scan $sup14449x71x0x0x1 __d0 __d1 c n r s) (body) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid8XBR181 __trel4v2k182 __tcol6eY0183 (1 2 3 4 0)) (tycheck c (accept str) __trid8XBR181 __trel2kAM184 __tcol6TDG185 (1 2 3 4 0)) (mkstruct deriv (1 2 0) __6C57180 s c)) antimirov.slog:72 #f)
  class ReadTask891 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid889;  u32 sid886;  u32 sid887;  u32 sid888;  u32 sid890;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("deriv");
      outer_rel = db->getRelation("$sup14449x71x0x0x1");
      sid889 = db->getRelation("_enum")->getStructId();
      sid886 = db->getRelation("alt")->getStructId();
      sid887 = db->getRelation("cat")->getStructId();
      sid888 = db->getRelation("chr")->getStructId();
      sid890 = db->getRelation("star")->getStructId();
  
    }
    ReadTask891(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_constf0add80747aca33dead79eea;
      u64 v_c136 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c12 = _t[0];
        u64 v_c140 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c95 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c2 = _t[5];
        ++_fires;
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid886 || decode_struct_id(v_c2) == sid887 || decode_struct_id(v_c2) == sid888 || decode_struct_id(v_c2) == sid889 || decode_struct_id(v_c2) == sid890))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c135, v_c136, v_c137, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c135, v_c138, v_c139, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c2, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:$sup14449x71x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask891* _cont = new ReadTask891(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask891(db,b), false);
  // (crule (pre) (scan deriv __t92wU16 __t0Qif15 c) (body (join cat (0 1 2) 1 __t0Qif15 r s)) (head (emit $sup14449x70x0x0x0 (3 2 0 1) s r __t92wU16 c)) antimirov.slog:71 #f)
  class ReadTask893 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex892;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord894({3, 2, 0, 1});
      slog::Relation* readrel895 = db->getRelation("$sup14449x70x0x0x0");
      head_index[0] = readrel895->getIndex(ord894, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord896({0, 1, 2});
      slog::Relation* readrel897 = db->getRelation("cat");
      catindex892 = readrel897->getIndex(ord896, false);
  
    }
    ReadTask893(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<3,1>(catindex892, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m898) {
          u64 v_c1 = m898[1]; u64 v_c2 = m898[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c1, v_c58, v_c6}, std::array<u16,4>{3, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask893* _cont = new ReadTask893(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask893(db,b), false);
  // (crule (pre) (scan toint_range __erre2sS0293 __errf3esr294 __errf9o67295) (body) (head (emit error (0) __erre2sS0293)) <internal>:1 #f)
  class ReadTask899 : public slog::Task
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
      std::vector<u16> ord900({0});
      slog::Relation* readrel901 = db->getRelation("error");
      head_index[0] = readrel901->getIndex(ord900, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask899(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c142 = _t[1];
        u64 v_c143 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c141}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask899* _cont = new ReadTask899(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask899(db,b), false);
}

