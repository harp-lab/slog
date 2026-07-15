
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const12ae32cb1ec02d01eda3581b;
extern u64 v_const30749c2c8a5c40a4f0a780b6;
extern u64 v_const439d97756c1f6d8e3f1b29c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6d8bc911abd31f57d1b91158;
extern u64 v_constabce180ee56b2c323c19f642;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constd1596cb698715803872591d6;
extern u64 v_conste7e898c68006c22d00270874;
extern u64 v_constf415be8f37f48a64565a412d;


void slog_rules_c52d32657b777eee0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (probe chr (1 0) 1 __tconst8qEb95 __t6I9I96) (body (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98)) (head (mkstruct cat (1 2 0) __t4yUC99 __t4w1Y98 __t6I9I96)) antimirov.slog:130 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** chrindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("cat");
      std::vector<u16> ord2({1, 0});
      slog::Relation* readrel3 = db->getRelation("chr");
      driver_index = readrel3->getIndex(ord2, true);
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("chr");
      chrindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c1 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c2 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m6) {
        u64 v_c3 = m6[1];
        if (buckethash(v_c3) != bucket) return;
        slog::join_probe<2,1>(chrindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m7) {
          u64 v_c4 = m7[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "delta:chr", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre (let _00024sqc30eT141 const6b86b273ff34fce19d6b804e) (let _00024sqc8YZJ142 const5feceb66ffc86f38d952786c) (let _00024sqc24yE143 const6b86b273ff34fce19d6b804e) (let _00024sqc1P4u144 const5feceb66ffc86f38d952786c)) (scan deriv_ans __t1HCg50 __v0) (body (join-old deriv (0 1 2) 1 (0 1 2) __t1HCg50 r c) (join $sup14449x83x0x0x0 (2 4 0 1 3) 2 c r _00024seq0 __d0 cs) (letp _00024sql7KCR139 (aslst _00024seq0)) (let _00024sqn6JCE140 (llen _00024sql7KCR139)) (cmp ge _00024sqn6JCE140 _00024sqc30eT141) (letp chk0Wbd313 (lref _00024sql7KCR139 _00024sqc8YZJ142)) (eq c chk0Wbd313) (let _00024sqp2g3G145 (_0002d _00024sqn6JCE140 _00024sqc1P4u144)) (let chk1Grz314 (lslice _00024sql7KCR139 _00024sqc24yE143 _00024sqp2g3G145)) (eq cs chk1Grz314)) (head (mkstruct run (1 2 0) __6qdL202 __v0 cs)) antimirov.slog:84 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex8;  slog::Index** $sup14449x83x0x0x0index9;  slog::Index** derivdelta10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run");
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord12({0, 1, 2});
      slog::Relation* readrel13 = db->getRelation("deriv");
      derivindex8 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("deriv");
      derivdelta10 = readrel15->getIndex(ord14, true);
      std::vector<u16> ord16({2, 4, 0, 1, 3});
      slog::Relation* readrel17 = db->getRelation("$sup14449x83x0x0x0");
      $sup14449x83x0x0x0index9 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(derivindex8, derivdelta10, std::array<u64,3>{v_c9, 0, 0}, [&](const std::array<u64,3>& m18) {
          u64 v_c11 = m18[1]; u64 v_c12 = m18[2];
          slog::join_probe<5,2>($sup14449x83x0x0x0index9, std::array<u64,5>{v_c12, v_c11, 0, 0, 0}, [&](const std::array<u64,5>& m19) {
            u64 v_c13 = m19[2]; u64 v_c14 = m19[3]; u64 v_c15 = m19[4];
            bool ok20 = true;
            u64 v_c16 = _prim_aslst(db, v_c13, &ok20);
            if (!ok20) return;
            u64 v_c17 = _prim_llen(db, v_c16);
            if (v_c17 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c18 = _prim_ge(db, v_c17, v_c5);
            if (v_c18 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (!v_c18) return;
            bool ok22 = true;
            u64 v_c19 = _prim_lref(db, v_c16, v_c6, &ok22);
            if (!ok22) return;
            if (v_c12 != v_c19) return;
            u64 v_c20 = _prim__0002d(db, v_c17, v_c8);
            if (v_c20 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            u64 v_c21 = _prim_lslice(db, v_c16, v_c7, v_c20);
            if (v_c21 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
            if (v_c15 != v_c21) return;
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c15}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:deriv_ans", _fires);
  
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
  // (crule (pre) (scan $sup14449x68x0x0x0 __t2Yus13 c r s) (body (exists deriv (2 0 1) 2 c __t2Yus13) (exists deriv (1 2 0) 2 r c) (join-old alt (1 2 0) 2 (1 2 0) r s __t1uAM12) (join-old deriv (0 1 2) 3 (0 1 2) __t2Yus13 __t1uAM12 c) (join-old deriv (1 2 0) 2 (1 2 0) r c __t2byM14) (join deriv_ans (0 1) 1 __t2byM14 __v0)) (head (emit deriv_ans (0 1) __t2Yus13 __v0)) antimirov.slog:69 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex23;  slog::Index** derivindex24;  slog::Index** altindex25;  slog::Index** derivindex26;  slog::Index** derivindex27;  slog::Index** deriv_ansindex28;  slog::Index** altdelta29;  slog::Index** derivdelta30;  slog::Index** derivdelta31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("deriv_ans");
      head_index[0] = readrel34->getIndex(ord33, false);
      outer_rel = db->getRelation("$sup14449x68x0x0x0");
      std::vector<u16> ord35({2, 0, 1});
      slog::Relation* readrel36 = db->getRelation("deriv");
      derivindex23 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("deriv");
      derivindex24 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("alt");
      altindex25 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("alt");
      altdelta29 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("deriv");
      derivindex26 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1, 2});
      slog::Relation* readrel46 = db->getRelation("deriv");
      derivdelta30 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("deriv");
      derivindex27 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("deriv");
      derivdelta31 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("deriv_ans");
      deriv_ansindex28 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c23 = _t[3];
        if (!slog::exists_probe<3,2>(derivindex23, std::array<u64,3>{v_c12, v_c22, 0})) return;
        if (!slog::exists_probe<3,2>(derivindex24, std::array<u64,3>{v_c11, v_c12, 0})) return;
        slog::join_probe_old<3,2>(altindex25, altdelta29, std::array<u64,3>{v_c11, v_c23, 0}, [&](const std::array<u64,3>& m53) {
          u64 v_c24 = m53[2];
          slog::join_probe_old<3,3>(derivindex26, derivdelta30, std::array<u64,3>{v_c22, v_c24, v_c12}, [&](const std::array<u64,3>& m54) {
            slog::join_probe_old<3,2>(derivindex27, derivdelta31, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m55) {
              u64 v_c25 = m55[2];
              slog::join_probe<2,1>(deriv_ansindex28, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m56) {
                u64 v_c10 = m56[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c10}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:$sup14449x68x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan deriv __t17NK126 s c) (body (exists deriv_ans (0 1) 1 __t17NK126) (exists cat (2 0 1) 1 s) (exists $sup14449x71x0x0x0 (1 3 2 0) 2 c s) (exists $sup14449x71x0x0x1 (2 5 0 4 1 3) 2 c s) (exists deriv (2 0 1) 1 c) (join nullable_ans (0 1) 0 __t95K4125 n) (cmp lt __tconst0Lyv124 n) (exists $sup14449x71x0x0x1 (1 2 3 5 4 0) 4 __t95K4125 c n s) (join deriv_ans (0 1) 1 __t17NK126 __v0) (join cat (2 0 1) 1 s __t4VgL122 r) (exists deriv (1 2 0) 2 __t4VgL122 c) (exists nullable (0 1) 2 __t95K4125 r) (join3 __t2zzw123 (full $sup14449x71x0x0x0 (1 3 2 0) 3 () c s r __t2zzw123) (full $sup14449x71x0x0x1 (1 2 3 5 4 0) 5 () __t95K4125 c n s r __t2zzw123)) (join deriv (0 1 2) 3 __t2zzw123 __t4VgL122 c) (join nullable (0 1) 2 __t95K4125 r)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask72 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deriv_ansindex57;  slog::Index** catindex58;  slog::Index** $sup14449x71x0x0x0index59;  slog::Index** $sup14449x71x0x0x1index60;  slog::Index** derivindex61;  slog::Index** nullable_ansindex62;  slog::Index** $sup14449x71x0x0x1index63;  slog::Index** deriv_ansindex64;  slog::Index** catindex65;  slog::Index** derivindex66;  slog::Index** nullableindex67;  slog::Index** derivindex68;  slog::Index** nullableindex69;  slog::Index** $sup14449x71x0x0x0index70;  slog::Index** $sup14449x71x0x0x1index71;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("deriv_ans");
      head_index[0] = readrel74->getIndex(ord73, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("deriv_ans");
      deriv_ansindex57 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({2, 0, 1});
      slog::Relation* readrel78 = db->getRelation("cat");
      catindex58 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 3, 2, 0});
      slog::Relation* readrel80 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index59 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({2, 5, 0, 4, 1, 3});
      slog::Relation* readrel82 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index60 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({2, 0, 1});
      slog::Relation* readrel84 = db->getRelation("deriv");
      derivindex61 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("nullable_ans");
      nullable_ansindex62 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel88 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index63 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("deriv_ans");
      deriv_ansindex64 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({2, 0, 1});
      slog::Relation* readrel92 = db->getRelation("cat");
      catindex65 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 2, 0});
      slog::Relation* readrel94 = db->getRelation("deriv");
      derivindex66 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1});
      slog::Relation* readrel96 = db->getRelation("nullable");
      nullableindex67 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("deriv");
      derivindex68 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 1});
      slog::Relation* readrel100 = db->getRelation("nullable");
      nullableindex69 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 3, 2, 0});
      slog::Relation* readrel102 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index70 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel104 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index71 = readrel104->getIndex(ord103, false);
  
    }
    ReadTask72(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<2,1>(deriv_ansindex57, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<3,1>(catindex58, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index59, std::array<u64,4>{v_c12, v_c23, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index60, std::array<u64,6>{v_c12, v_c23, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex61, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_all<2>(nullable_ansindex62, [&](const std::array<u64,2>& m105) {
          u64 v_c28 = m105[0]; u64 v_c29 = m105[1];
          u64 v_c30 = _prim_lt(db, v_c26, v_c29);
          if (v_c30 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c30) return;
          if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index63, std::array<u64,6>{v_c28, v_c12, v_c29, v_c23, 0, 0})) return;
          slog::join_probe<2,1>(deriv_ansindex64, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m107) {
            u64 v_c10 = m107[1];
            slog::join_probe<3,1>(catindex65, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m108) {
              u64 v_c31 = m108[1]; u64 v_c11 = m108[2];
              if (!slog::exists_probe<3,2>(derivindex66, std::array<u64,3>{v_c31, v_c12, 0})) return;
              if (!slog::exists_probe<2,2>(nullableindex67, std::array<u64,2>{v_c28, v_c11})) return;
              slog::join3<4,3,slog::Join3View::full,6,5,slog::Join3View::full>($sup14449x71x0x0x0index70, $sup14449x71x0x0x0index70, std::array<u64,4>{v_c12, v_c23, v_c11, 0}, $sup14449x71x0x0x1index71, $sup14449x71x0x0x1index71, std::array<u64,6>{v_c28, v_c12, v_c29, v_c23, v_c11, 0}, [&](u64 cycle109) {
              u64 v_c32 = cycle109;
                slog::join_probe<3,3>(derivindex68, std::array<u64,3>{v_c32, v_c31, v_c12}, [&](const std::array<u64,3>& m110) {
                  slog::join_probe<2,2>(nullableindex69, std::array<u64,2>{v_c28, v_c11}, [&](const std::array<u64,2>& m111) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c10}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask72* _cont = new ReadTask72(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask72(db,b), false);
  // (crule (pre) (scan star __t1wYz29 r) (body (exists deriv (1 2 0) 1 r) (join-old deriv (1 2 0) 1 (1 2 0) __t1wYz29 c __t8rjP30) (join-old deriv (1 2 0) 2 (1 2 0) r c __t2TCG31) (join deriv_ans (0 1) 1 __t2TCG31 __v0)) (head (mkstruct mkcat (1 2 0) __7GaM229 __v0 __t1wYz29)) antimirov.slog:73 #f)
  class ReadTask118 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex112;  slog::Index** derivindex113;  slog::Index** derivindex114;  slog::Index** deriv_ansindex115;  slog::Index** derivdelta116;  slog::Index** derivdelta117;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat");
      outer_rel = db->getRelation("star");
      std::vector<u16> ord119({1, 2, 0});
      slog::Relation* readrel120 = db->getRelation("deriv");
      derivindex112 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("deriv");
      derivindex113 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("deriv");
      derivdelta116 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({1, 2, 0});
      slog::Relation* readrel126 = db->getRelation("deriv");
      derivindex114 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 2, 0});
      slog::Relation* readrel128 = db->getRelation("deriv");
      derivdelta117 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("deriv_ans");
      deriv_ansindex115 = readrel130->getIndex(ord129, false);
  
    }
    ReadTask118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[0];
        u64 v_c11 = _t[1];
        if (!slog::exists_probe<3,1>(derivindex112, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe_old<3,1>(derivindex113, derivdelta116, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m131) {
          u64 v_c12 = m131[1]; u64 v_c34 = m131[2];
          slog::join_probe_old<3,2>(derivindex114, derivdelta117, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m132) {
            u64 v_c35 = m132[2];
            slog::join_probe<2,1>(deriv_ansindex115, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m133) {
              u64 v_c10 = m133[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c33}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:star", _fires);
  
      if (!_done)
      {
        ReadTask118* _cont = new ReadTask118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask118(db,b), false);
  // (crule (pre) (scan alpha c) (body (join-old deriv (2 0 1) 1 (2 0 1) c __t43JV128 r) (join state (0) 1 r) (join-old deriv_ans (0 1) 1 (0 1) __t43JV128 r2)) (head (emit nfa (0 1 2) r c r2) (emit state (0) r2)) antimirov.slog:115 #f)
  class ReadTask139 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex134;  slog::Index** stateindex135;  slog::Index** deriv_ansindex136;  slog::Index** derivdelta137;  slog::Index** deriv_ansdelta138;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nfa");
      std::vector<u16> ord140({0, 1, 2});
      slog::Relation* readrel141 = db->getRelation("nfa");
      head_index[0] = readrel141->getIndex(ord140, false);
      head_rel[1] = db->getRelation("state");
      std::vector<u16> ord142({0});
      slog::Relation* readrel143 = db->getRelation("state");
      head_index[1] = readrel143->getIndex(ord142, false);
      outer_rel = db->getRelation("alpha");
      std::vector<u16> ord144({2, 0, 1});
      slog::Relation* readrel145 = db->getRelation("deriv");
      derivindex134 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({2, 0, 1});
      slog::Relation* readrel147 = db->getRelation("deriv");
      derivdelta137 = readrel147->getIndex(ord146, true);
      std::vector<u16> ord148({0});
      slog::Relation* readrel149 = db->getRelation("state");
      stateindex135 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("deriv_ans");
      deriv_ansindex136 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("deriv_ans");
      deriv_ansdelta138 = readrel153->getIndex(ord152, true);
  
    }
    ReadTask139(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        slog::join_probe_old<3,1>(derivindex134, derivdelta137, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m154) {
          u64 v_c36 = m154[1]; u64 v_c11 = m154[2];
          slog::join_probe<1,1>(stateindex135, std::array<u64,1>{v_c11}, [&](const std::array<u64,1>& m155) {
            slog::join_probe_old<2,1>(deriv_ansindex136, deriv_ansdelta138, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m156) {
              u64 v_c37 = m156[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c11, v_c12, v_c37}, std::array<u16,3>{0, 1, 2});
              slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:alpha", _fires);
  
      if (!_done)
      {
        ReadTask139* _cont = new ReadTask139(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask139(db,b), false);
  // (crule (pre (let __trid5ZcZ204 conste7e898c68006c22d00270874) (let __trel8qkJ205 constf415be8f37f48a64565a412d) (let __tcol9wok206 const6b86b273ff34fce19d6b804e)) (scan deriv_ans __t9BNj9 __v0) (body (join-old deriv (0 1 2) 1 (0 1 2) __t9BNj9 r c) (join $sup14449x70x0x0x0 (1 2 3 0) 2 c r s __d0)) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid5ZcZ204 __trel8qkJ205 __tcol9wok206 (1 2 3 4 0)) (mkstruct mkcat (1 2 0) __6Dj3203 __v0 s)) antimirov.slog:71 #f)
  class ReadTask165 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex157;  slog::Index** $sup14449x70x0x0x0index158;  slog::Index** derivdelta159;
    u32 sid163;  u32 sid160;  u32 sid161;  u32 sid162;  u32 sid164;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mkcat");
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord166({0, 1, 2});
      slog::Relation* readrel167 = db->getRelation("deriv");
      derivindex157 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1, 2});
      slog::Relation* readrel169 = db->getRelation("deriv");
      derivdelta159 = readrel169->getIndex(ord168, true);
      std::vector<u16> ord170({1, 2, 3, 0});
      slog::Relation* readrel171 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index158 = readrel171->getIndex(ord170, false);
      sid163 = db->getRelation("_enum")->getStructId();
      sid160 = db->getRelation("alt")->getStructId();
      sid161 = db->getRelation("cat")->getStructId();
      sid162 = db->getRelation("chr")->getStructId();
      sid164 = db->getRelation("star")->getStructId();
  
    }
    ReadTask165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_conste7e898c68006c22d00270874;
      u64 v_c39 = v_constf415be8f37f48a64565a412d;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(derivindex157, derivdelta159, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m172) {
          u64 v_c11 = m172[1]; u64 v_c12 = m172[2];
          slog::join_probe<4,2>($sup14449x70x0x0x0index158, std::array<u64,4>{v_c12, v_c11, 0, 0}, [&](const std::array<u64,4>& m173) {
            u64 v_c23 = m173[2]; u64 v_c14 = m173[3];
            ++_fires;
            if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid160 || decode_struct_id(v_c23) == sid161 || decode_struct_id(v_c23) == sid162 || decode_struct_id(v_c23) == sid163 || decode_struct_id(v_c23) == sid164))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c38, v_c39, v_c40, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c23}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:deriv_ans", _fires);
  
      if (!_done)
      {
        ReadTask165* _cont = new ReadTask165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask165(db,b), false);
  // (crule (pre (let __tconst3svo173 constabce180ee56b2c323c19f642)) (scan deriv __t34Qo117 __t3mKa116 c) (body (join chr (0 1) 2 __t3mKa116 c) (join _enum (1 0) 1 __tconst3svo173 __t9IyX115)) (head (emit deriv_ans (0 1) __t34Qo117 __t9IyX115)) antimirov.slog:68 #f)
  class ReadTask176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex174;  slog::Index** _enumindex175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("deriv_ans");
      head_index[0] = readrel178->getIndex(ord177, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("chr");
      chrindex174 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("_enum");
      _enumindex175 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_constabce180ee56b2c323c19f642;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c43 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<2,2>(chrindex174, std::array<u64,2>{v_c44, v_c12}, [&](const std::array<u64,2>& m183) {
          slog::join_probe<2,1>(_enumindex175, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m184) {
            u64 v_c45 = m184[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c45}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:68", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask176* _cont = new ReadTask176(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask176(db,b), false);
  // (crule (pre (let __tconst3svo173 constabce180ee56b2c323c19f642)) (scan chr __t3mKa116 c) (body (exists _enum (1 0) 1 __tconst3svo173) (join-old deriv (1 2 0) 2 (1 2 0) __t3mKa116 c __t34Qo117) (join _enum (1 0) 1 __tconst3svo173 __t9IyX115)) (head (emit deriv_ans (0 1) __t34Qo117 __t9IyX115)) antimirov.slog:68 #f)
  class ReadTask189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex185;  slog::Index** derivindex186;  slog::Index** _enumindex187;  slog::Index** derivdelta188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("deriv_ans");
      head_index[0] = readrel191->getIndex(ord190, false);
      outer_rel = db->getRelation("chr");
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("_enum");
      _enumindex185 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("deriv");
      derivindex186 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("deriv");
      derivdelta188 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({1, 0});
      slog::Relation* readrel199 = db->getRelation("_enum");
      _enumindex187 = readrel199->getIndex(ord198, false);
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_constabce180ee56b2c323c19f642;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex185, std::array<u64,2>{v_c42, 0})) return;
        slog::join_probe_old<3,2>(derivindex186, derivdelta188, std::array<u64,3>{v_c44, v_c12, 0}, [&](const std::array<u64,3>& m200) {
          u64 v_c43 = m200[2];
          slog::join_probe<2,1>(_enumindex187, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m201) {
            u64 v_c45 = m201[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c45}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:68", "delta:chr", _fires);
  
      if (!_done)
      {
        ReadTask189* _cont = new ReadTask189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask189(db,b), false);
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan nullable_ans __t95K4125 n) (body (cmp lt __tconst0Lyv124 n) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 2 __t95K4125 n) (join-old deriv_ans (0 1) 0 (0 1) __t17NK126 __v0) (join-old cat (0 1 2) 0 (0 1 2) __t4VgL122 r s) (join-old nullable (0 1) 2 (0 1) __t95K4125 r) (exists $sup14449x71x0x0x0 (2 3 0 1) 2 r s) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 4 __t95K4125 n r s) (exists deriv (1 2 0) 1 __t4VgL122) (join-old deriv (0 1 2) 2 (0 1 2) __t17NK126 s c) (exists deriv (1 2 0) 2 __t4VgL122 c) (join3 __t2zzw123 (old $sup14449x71x0x0x0 (1 3 2 0) 3 (1 3 2 0) c s r __t2zzw123) (old $sup14449x71x0x0x1 (1 2 3 5 4 0) 5 (1 2 3 5 4 0) __t95K4125 c n s r __t2zzw123)) (join-old deriv (0 1 2) 3 (0 1 2) __t2zzw123 __t4VgL122 c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask221 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x71x0x0x1index202;  slog::Index** deriv_ansindex203;  slog::Index** catindex204;  slog::Index** nullableindex205;  slog::Index** $sup14449x71x0x0x0index206;  slog::Index** $sup14449x71x0x0x1index207;  slog::Index** derivindex208;  slog::Index** derivindex209;  slog::Index** derivindex210;  slog::Index** derivindex211;  slog::Index** $sup14449x71x0x0x0index212;  slog::Index** $sup14449x71x0x0x1index213;  slog::Index** deriv_ansdelta214;  slog::Index** catdelta215;  slog::Index** nullabledelta216;  slog::Index** derivdelta217;  slog::Index** derivdelta218;  slog::Index** $sup14449x71x0x0x0delta219;  slog::Index** $sup14449x71x0x0x1delta220;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("deriv_ans");
      head_index[0] = readrel223->getIndex(ord222, false);
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord224({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel225 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index202 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("deriv_ans");
      deriv_ansindex203 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("deriv_ans");
      deriv_ansdelta214 = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({0, 1, 2});
      slog::Relation* readrel231 = db->getRelation("cat");
      catindex204 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1, 2});
      slog::Relation* readrel233 = db->getRelation("cat");
      catdelta215 = readrel233->getIndex(ord232, true);
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("nullable");
      nullableindex205 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({0, 1});
      slog::Relation* readrel237 = db->getRelation("nullable");
      nullabledelta216 = readrel237->getIndex(ord236, true);
      std::vector<u16> ord238({2, 3, 0, 1});
      slog::Relation* readrel239 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index206 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel241 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index207 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("deriv");
      derivindex208 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 1, 2});
      slog::Relation* readrel245 = db->getRelation("deriv");
      derivindex209 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({0, 1, 2});
      slog::Relation* readrel247 = db->getRelation("deriv");
      derivdelta217 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("deriv");
      derivindex210 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1, 2});
      slog::Relation* readrel251 = db->getRelation("deriv");
      derivindex211 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1, 2});
      slog::Relation* readrel253 = db->getRelation("deriv");
      derivdelta218 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 3, 2, 0});
      slog::Relation* readrel255 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index212 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 3, 2, 0});
      slog::Relation* readrel257 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0delta219 = readrel257->getIndex(ord256, true);
      std::vector<u16> ord258({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel259 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index213 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel261 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1delta220 = readrel261->getIndex(ord260, true);
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c46 = _prim_lt(db, v_c26, v_c29);
        if (v_c46 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
        if (!v_c46) return;
        if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index202, std::array<u64,6>{v_c28, v_c29, 0, 0, 0, 0})) return;
        slog::join_all_old<2>(deriv_ansindex203, deriv_ansdelta214, [&](const std::array<u64,2>& m263) {
          u64 v_c27 = m263[0]; u64 v_c10 = m263[1];
          slog::join_all_old<3>(catindex204, catdelta215, [&](const std::array<u64,3>& m264) {
            u64 v_c31 = m264[0]; u64 v_c11 = m264[1]; u64 v_c23 = m264[2];
            slog::join_probe_old<2,2>(nullableindex205, nullabledelta216, std::array<u64,2>{v_c28, v_c11}, [&](const std::array<u64,2>& m265) {
              if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index206, std::array<u64,4>{v_c11, v_c23, 0, 0})) return;
              if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index207, std::array<u64,6>{v_c28, v_c29, v_c11, v_c23, 0, 0})) return;
              if (!slog::exists_probe<3,1>(derivindex208, std::array<u64,3>{v_c31, 0, 0})) return;
              slog::join_probe_old<3,2>(derivindex209, derivdelta217, std::array<u64,3>{v_c27, v_c23, 0}, [&](const std::array<u64,3>& m266) {
                u64 v_c12 = m266[2];
                if (!slog::exists_probe<3,2>(derivindex210, std::array<u64,3>{v_c31, v_c12, 0})) return;
                slog::join3<4,3,slog::Join3View::old,6,5,slog::Join3View::old>($sup14449x71x0x0x0index212, $sup14449x71x0x0x0delta219, std::array<u64,4>{v_c12, v_c23, v_c11, 0}, $sup14449x71x0x0x1index213, $sup14449x71x0x0x1delta220, std::array<u64,6>{v_c28, v_c12, v_c29, v_c23, v_c11, 0}, [&](u64 cycle267) {
                u64 v_c32 = cycle267;
                  slog::join_probe_old<3,3>(derivindex211, derivdelta218, std::array<u64,3>{v_c32, v_c31, v_c12}, [&](const std::array<u64,3>& m268) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c10}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:nullable_ans", _fires);
  
      if (!_done)
      {
        ReadTask221* _cont = new ReadTask221(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask221(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre7zsQ301 __errf3H6n302 __errf3Inq303 __errf2W5a304 __errf8FiS305) (body) (head (emit error (0) __erre7zsQ301)) <internal>:1 #f)
  class ReadTask269 : public slog::Task
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
      std::vector<u16> ord270({0});
      slog::Relation* readrel271 = db->getRelation("error");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[1];
        u64 v_c49 = _t[2];
        u64 v_c50 = _t[3];
        u64 v_c51 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre (let __tconst7GyM108 const5feceb66ffc86f38d952786c)) (scan nullable_ans __t3KPn107 n) (body (cmp lt __tconst7GyM108 n) (join-old nullable (0 1) 1 (0 1) __t3KPn107 r) (join $sup14449x71x0x0x0 (2 3 0 1) 1 r s __d0 c)) (head (emit $sup14449x71x0x0x1 (0 2 1 3 4 5) __d0 c __t3KPn107 n r s)) antimirov.slog:72 #f)
  class ReadTask275 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex272;  slog::Index** $sup14449x71x0x0x0index273;  slog::Index** nullabledelta274;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord276({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel277 = db->getRelation("$sup14449x71x0x0x1");
      head_index[0] = readrel277->getIndex(ord276, false);
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("nullable");
      nullableindex272 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({0, 1});
      slog::Relation* readrel281 = db->getRelation("nullable");
      nullabledelta274 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({2, 3, 0, 1});
      slog::Relation* readrel283 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index273 = readrel283->getIndex(ord282, false);
  
    }
    ReadTask275(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c54 = _prim_lt(db, v_c52, v_c29);
        if (v_c54 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
        if (!v_c54) return;
        slog::join_probe_old<2,1>(nullableindex272, nullabledelta274, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m285) {
          u64 v_c11 = m285[1];
          slog::join_probe<4,1>($sup14449x71x0x0x0index273, std::array<u64,4>{v_c11, 0, 0, 0}, [&](const std::array<u64,4>& m286) {
            u64 v_c23 = m286[1]; u64 v_c14 = m286[2]; u64 v_c12 = m286[3];
            ++_fires;
            slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c14, v_c12, v_c53, v_c29, v_c11, v_c23}, std::array<u16,6>{0, 2, 1, 3, 4, 5});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:nullable_ans", _fires);
  
      if (!_done)
      {
        ReadTask275* _cont = new ReadTask275(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask275(db,b), false);
  // (crule (pre) (scan mkcat __t08Xq94 __t7r4Z93 s) (body (join star (0 1) 1 __t7r4Z93 a)) (head (emit-temp temp5pCD310 __t08Xq94 __t7r4Z93 s) (mkstruct cat (1 2 0) __t7HJf92 __t7r4Z93 s)) antimirov.slog:60 #f)
  class ReadTask288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5pCD310");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("star");
      starindex287 = readrel290->getIndex(ord289, false);
  
    }
    ReadTask288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<2,1>(starindex287, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m291) {
          u64 v_c57 = m291[1];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c55, v_c56, v_c23});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c56, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:60", "delta:mkcat", _fires);
  
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
  // (crule (pre) (scan nullable __t750i70 __t30Rf69) (body (join alt (0 1 2) 1 __t30Rf69 r s)) (head (emit $sup14449x46x0x0x0 (0 1 2) __t750i70 r s)) antimirov.slog:47 #f)
  class ReadTask293 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex292;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x46x0x0x0");
      std::vector<u16> ord294({0, 1, 2});
      slog::Relation* readrel295 = db->getRelation("$sup14449x46x0x0x0");
      head_index[0] = readrel295->getIndex(ord294, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord296({0, 1, 2});
      slog::Relation* readrel297 = db->getRelation("alt");
      altindex292 = readrel297->getIndex(ord296, false);
  
    }
    ReadTask293(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        slog::join_probe<3,1>(altindex292, std::array<u64,3>{v_c59, 0, 0}, [&](const std::array<u64,3>& m298) {
          u64 v_c11 = m298[1]; u64 v_c23 = m298[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c58, v_c11, v_c23}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask293* _cont = new ReadTask293(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask293(db,b), false);
  // (crule (pre) (scan chr __t8G6r74 c) (body (join-old mkcat (1 2 0) 1 (1 2 0) __t8G6r74 s __t4QnR75)) (head (emit-temp temp262S323 __t4QnR75 __t8G6r74 s) (mkstruct cat (1 2 0) __t0ZKc73 __t8G6r74 s)) antimirov.slog:57 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex299;  slog::Index** mkcatdelta300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp262S323");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("chr");
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("mkcat");
      mkcatindex299 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("mkcat");
      mkcatdelta300 = readrel305->getIndex(ord304, true);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe_old<3,1>(mkcatindex299, mkcatdelta300, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m306) {
          u64 v_c23 = m306[1]; u64 v_c61 = m306[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c61, v_c60, v_c23});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c60, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:57", "delta:chr", _fires);
  
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
  // (crule (pre) (scan cat __t5yew82 a b) (body (join-old mkcat (1 2 0) 1 (1 2 0) __t5yew82 s __t6haW83)) (head (emit-temp temp5DUf326 __t5yew82 __t6haW83 s) (mkstruct cat (1 2 0) __t5GnC81 __t5yew82 s)) antimirov.slog:58 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex307;  slog::Index** mkcatdelta308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5DUf326");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("mkcat");
      mkcatindex307 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("mkcat");
      mkcatdelta308 = readrel313->getIndex(ord312, true);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[1];
        u64 v_c63 = _t[2];
        slog::join_probe_old<3,1>(mkcatindex307, mkcatdelta308, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m314) {
          u64 v_c23 = m314[1]; u64 v_c64 = m314[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c62, v_c64, v_c23});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c62, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:58", "delta:cat", _fires);
  
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
  // (crule (pre) (scan alt __t5FmK34 r s) (body (join-old deriv (1 2 0) 1 (1 2 0) __t5FmK34 c __t2Ihd35)) (head (emit $sup14449x68x0x0x0 (0 1 2 3) __t2Ihd35 c r s)) antimirov.slog:69 #f)
  class ReadTask317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex315;  slog::Index** derivdelta316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x68x0x0x0");
      std::vector<u16> ord318({0, 1, 2, 3});
      slog::Relation* readrel319 = db->getRelation("$sup14449x68x0x0x0");
      head_index[0] = readrel319->getIndex(ord318, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord320({1, 2, 0});
      slog::Relation* readrel321 = db->getRelation("deriv");
      derivindex315 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("deriv");
      derivdelta316 = readrel323->getIndex(ord322, true);
  
    }
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe_old<3,1>(derivindex315, derivdelta316, std::array<u64,3>{v_c65, 0, 0}, [&](const std::array<u64,3>& m324) {
          u64 v_c12 = m324[1]; u64 v_c66 = m324[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c66, v_c12, v_c11, v_c23}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask317* _cont = new ReadTask317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask317(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (scan cat __t3C3W66 __t5cfw65 __t2gMK59) (body (exists chr (1 0) 1 __tconst77RG62) (exists chr (1 0) 1 __tconst7i6460) (join star (0 1) 1 __t5cfw65 __t8pHj64) (join chr (1 0) 1 __tconst77RG62 __t8Axk58) (exists alt (0 1 2) 2 __t8pHj64 __t8Axk58) (join cat (0 1 2) 2 __t2gMK59 __t8Axk58 __t9z7256) (join alt (0 1 2) 2 __t8pHj64 __t8Axk58 __t7SBZ53) (join chr (0 1) 2 __t7SBZ53 __tconst7i6460) (join cat (0 1 2) 2 __t9z7256 __t7SBZ53 dup8knB321) (eq __t7SBZ53 dup8knB321)) (head (emit query (0 1) __tconst9dp567 __t3C3W66)) antimirov.slog:126 #f)
  class ReadTask334 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex325;  slog::Index** chrindex326;  slog::Index** starindex327;  slog::Index** chrindex328;  slog::Index** altindex329;  slog::Index** catindex330;  slog::Index** altindex331;  slog::Index** chrindex332;  slog::Index** catindex333;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("query");
      std::vector<u16> ord335({0, 1});
      slog::Relation* readrel336 = db->getRelation("query");
      head_index[0] = readrel336->getIndex(ord335, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord337({1, 0});
      slog::Relation* readrel338 = db->getRelation("chr");
      chrindex325 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0});
      slog::Relation* readrel340 = db->getRelation("chr");
      chrindex326 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({0, 1});
      slog::Relation* readrel342 = db->getRelation("star");
      starindex327 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 0});
      slog::Relation* readrel344 = db->getRelation("chr");
      chrindex328 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1, 2});
      slog::Relation* readrel346 = db->getRelation("alt");
      altindex329 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1, 2});
      slog::Relation* readrel348 = db->getRelation("cat");
      catindex330 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("alt");
      altindex331 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("chr");
      chrindex332 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1, 2});
      slog::Relation* readrel354 = db->getRelation("cat");
      catindex333 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask334(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c68 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c69 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c70 = _t[0];
        u64 v_c71 = _t[1];
        u64 v_c72 = _t[2];
        if (!slog::exists_probe<2,1>(chrindex325, std::array<u64,2>{v_c68, 0})) return;
        if (!slog::exists_probe<2,1>(chrindex326, std::array<u64,2>{v_c69, 0})) return;
        slog::join_probe<2,1>(starindex327, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m355) {
          u64 v_c73 = m355[1];
          slog::join_probe<2,1>(chrindex328, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m356) {
            u64 v_c74 = m356[1];
            if (!slog::exists_probe<3,2>(altindex329, std::array<u64,3>{v_c73, v_c74, 0})) return;
            slog::join_probe<3,2>(catindex330, std::array<u64,3>{v_c72, v_c74, 0}, [&](const std::array<u64,3>& m357) {
              u64 v_c75 = m357[2];
              slog::join_probe<3,2>(altindex331, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m358) {
                u64 v_c76 = m358[2];
                slog::join_probe<2,2>(chrindex332, std::array<u64,2>{v_c76, v_c69}, [&](const std::array<u64,2>& m359) {
                  slog::join_probe<3,2>(catindex333, std::array<u64,3>{v_c75, v_c76, 0}, [&](const std::array<u64,3>& m360) {
                    u64 v_c77 = m360[2];
                    if (v_c76 != v_c77) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c70}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask334* _cont = new ReadTask334(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask334(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst8qEb95 __t6I9I96) (exists cat (2 0 1) 1 __t6I9I96) (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98) (join cat (1 2 0) 2 __t4w1Y98 __t6I9I96 __t4yUC99)) (head (mkstruct alt (1 2 0) __t5G2v102 __t4w1Y98 __t4yUC99)) antimirov.slog:130 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex361;  slog::Index** catindex362;  slog::Index** chrindex363;  slog::Index** catindex364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alt");
      std::vector<u16> ord366({1, 2, 0});
      slog::Relation* readrel367 = db->getRelation("alt");
      head_index[0] = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 0});
      slog::Relation* readrel369 = db->getRelation("chr");
      chrindex361 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({2, 0, 1});
      slog::Relation* readrel371 = db->getRelation("cat");
      catindex362 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("chr");
      chrindex363 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("cat");
      catindex364 = readrel375->getIndex(ord374, false);
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c1 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c2 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex361, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m376) {
        u64 v_c3 = m376[1];
        if (!slog::exists_probe<3,1>(catindex362, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(chrindex363, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m377) {
          u64 v_c4 = m377[1];
          slog::join_probe<3,2>(catindex364, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m378) {
            u64 v_c78 = m378[2];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c78}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask365(db,b));
  // (crule (pre) (scan int_overflow __erre8Ei0285 __errf5emP286 __errf0Cuj287 __errf1Eq1288) (body) (head (emit error (0) __erre8Ei0285)) <internal>:1 #f)
  class ReadTask379 : public slog::Task
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
      std::vector<u16> ord380({0});
      slog::Relation* readrel381 = db->getRelation("error");
      head_index[0] = readrel381->getIndex(ord380, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask379(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[0];
        u64 v_c80 = _t[1];
        u64 v_c81 = _t[2];
        u64 v_c82 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c79}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask379* _cont = new ReadTask379(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask379(db,b), false);
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan $sup14449x71x0x0x0 __t2zzw123 c r s) (body (exists cat (1 2 0) 2 r s) (exists deriv (2 0 1) 2 c __t2zzw123) (exists nullable (1 0) 1 r) (exists $sup14449x71x0x0x1 (2 5 0 4 1 3) 4 c s __t2zzw123 r) (exists deriv (1 2 0) 2 s c) (join deriv_ans (0 1) 0 __t17NK126 __v0) (exists deriv (0 1 2) 3 __t17NK126 s c) (join-old cat (1 2 0) 2 (1 2 0) r s __t4VgL122) (join-old deriv (0 1 2) 3 (0 1 2) __t2zzw123 __t4VgL122 c) (join-old nullable (1 0) 1 (1 0) r __t95K4125) (join3 n (full nullable_ans (0 1) 1 () __t95K4125 n) (old $sup14449x71x0x0x1 (2 5 0 4 1 3) 5 (2 5 0 4 1 3) c s __t2zzw123 r __t95K4125 n)) (join-old deriv (0 1 2) 3 (0 1 2) __t17NK126 s c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask400 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex382;  slog::Index** derivindex383;  slog::Index** nullableindex384;  slog::Index** $sup14449x71x0x0x1index385;  slog::Index** derivindex386;  slog::Index** deriv_ansindex387;  slog::Index** derivindex388;  slog::Index** catindex389;  slog::Index** derivindex390;  slog::Index** nullableindex391;  slog::Index** derivindex392;  slog::Index** nullable_ansindex393;  slog::Index** $sup14449x71x0x0x1index394;  slog::Index** catdelta395;  slog::Index** derivdelta396;  slog::Index** nullabledelta397;  slog::Index** derivdelta398;  slog::Index** $sup14449x71x0x0x1delta399;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("deriv_ans");
      head_index[0] = readrel402->getIndex(ord401, false);
      outer_rel = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("cat");
      catindex382 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({2, 0, 1});
      slog::Relation* readrel406 = db->getRelation("deriv");
      derivindex383 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 0});
      slog::Relation* readrel408 = db->getRelation("nullable");
      nullableindex384 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({2, 5, 0, 4, 1, 3});
      slog::Relation* readrel410 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index385 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("deriv");
      derivindex386 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("deriv_ans");
      deriv_ansindex387 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({0, 1, 2});
      slog::Relation* readrel416 = db->getRelation("deriv");
      derivindex388 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("cat");
      catindex389 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("cat");
      catdelta395 = readrel420->getIndex(ord419, true);
      std::vector<u16> ord421({0, 1, 2});
      slog::Relation* readrel422 = db->getRelation("deriv");
      derivindex390 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({0, 1, 2});
      slog::Relation* readrel424 = db->getRelation("deriv");
      derivdelta396 = readrel424->getIndex(ord423, true);
      std::vector<u16> ord425({1, 0});
      slog::Relation* readrel426 = db->getRelation("nullable");
      nullableindex391 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 0});
      slog::Relation* readrel428 = db->getRelation("nullable");
      nullabledelta397 = readrel428->getIndex(ord427, true);
      std::vector<u16> ord429({0, 1, 2});
      slog::Relation* readrel430 = db->getRelation("deriv");
      derivindex392 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1, 2});
      slog::Relation* readrel432 = db->getRelation("deriv");
      derivdelta398 = readrel432->getIndex(ord431, true);
      std::vector<u16> ord433({0, 1});
      slog::Relation* readrel434 = db->getRelation("nullable_ans");
      nullable_ansindex393 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({2, 5, 0, 4, 1, 3});
      slog::Relation* readrel436 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index394 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({2, 5, 0, 4, 1, 3});
      slog::Relation* readrel438 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1delta399 = readrel438->getIndex(ord437, true);
  
    }
    ReadTask400(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c23 = _t[3];
        if (!slog::exists_probe<3,2>(catindex382, std::array<u64,3>{v_c11, v_c23, 0})) return;
        if (!slog::exists_probe<3,2>(derivindex383, std::array<u64,3>{v_c12, v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex384, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index385, std::array<u64,6>{v_c12, v_c23, v_c32, v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,2>(derivindex386, std::array<u64,3>{v_c23, v_c12, 0})) return;
        slog::join_all<2>(deriv_ansindex387, [&](const std::array<u64,2>& m439) {
          u64 v_c27 = m439[0]; u64 v_c10 = m439[1];
          if (!slog::exists_probe<3,3>(derivindex388, std::array<u64,3>{v_c27, v_c23, v_c12})) return;
          slog::join_probe_old<3,2>(catindex389, catdelta395, std::array<u64,3>{v_c11, v_c23, 0}, [&](const std::array<u64,3>& m440) {
            u64 v_c31 = m440[2];
            slog::join_probe_old<3,3>(derivindex390, derivdelta396, std::array<u64,3>{v_c32, v_c31, v_c12}, [&](const std::array<u64,3>& m441) {
              slog::join_probe_old<2,1>(nullableindex391, nullabledelta397, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m442) {
                u64 v_c28 = m442[1];
                slog::join3<2,1,slog::Join3View::full,6,5,slog::Join3View::old>(nullable_ansindex393, nullable_ansindex393, std::array<u64,2>{v_c28, 0}, $sup14449x71x0x0x1index394, $sup14449x71x0x0x1delta399, std::array<u64,6>{v_c12, v_c23, v_c32, v_c11, v_c28, 0}, [&](u64 cycle443) {
                u64 v_c29 = cycle443;
                  slog::join_probe_old<3,3>(derivindex392, derivdelta398, std::array<u64,3>{v_c27, v_c23, v_c12}, [&](const std::array<u64,3>& m444) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c10}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:$sup14449x71x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask400* _cont = new ReadTask400(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask400(db,b), false);
  // (crule (pre (let __trid5ZcZ204 conste7e898c68006c22d00270874) (let __trel8qkJ205 constf415be8f37f48a64565a412d) (let __tcol9wok206 const6b86b273ff34fce19d6b804e)) (scan deriv __t9BNj9 r c) (body (exists deriv_ans (0 1) 1 __t9BNj9) (join $sup14449x70x0x0x0 (1 2 3 0) 2 c r s __d0) (join deriv_ans (0 1) 1 __t9BNj9 __v0)) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid5ZcZ204 __trel8qkJ205 __tcol9wok206 (1 2 3 4 0)) (mkstruct mkcat (1 2 0) __6Dj3203 __v0 s)) antimirov.slog:71 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deriv_ansindex445;  slog::Index** $sup14449x70x0x0x0index446;  slog::Index** deriv_ansindex447;
    u32 sid451;  u32 sid448;  u32 sid449;  u32 sid450;  u32 sid452;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mkcat");
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("deriv_ans");
      deriv_ansindex445 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 3, 0});
      slog::Relation* readrel457 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index446 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("deriv_ans");
      deriv_ansindex447 = readrel459->getIndex(ord458, false);
      sid451 = db->getRelation("_enum")->getStructId();
      sid448 = db->getRelation("alt")->getStructId();
      sid449 = db->getRelation("cat")->getStructId();
      sid450 = db->getRelation("chr")->getStructId();
      sid452 = db->getRelation("star")->getStructId();
  
    }
    ReadTask453(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_conste7e898c68006c22d00270874;
      u64 v_c39 = v_constf415be8f37f48a64565a412d;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<2,1>(deriv_ansindex445, std::array<u64,2>{v_c41, 0})) return;
        slog::join_probe<4,2>($sup14449x70x0x0x0index446, std::array<u64,4>{v_c12, v_c11, 0, 0}, [&](const std::array<u64,4>& m460) {
          u64 v_c23 = m460[2]; u64 v_c14 = m460[3];
          slog::join_probe<2,1>(deriv_ansindex447, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m461) {
            u64 v_c10 = m461[1];
            ++_fires;
            if (!((is_struct(v_c23) && (decode_struct_id(v_c23) == sid448 || decode_struct_id(v_c23) == sid449 || decode_struct_id(v_c23) == sid450 || decode_struct_id(v_c23) == sid451 || decode_struct_id(v_c23) == sid452))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c38, v_c39, v_c40, v_c23}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c23}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask453* _cont = new ReadTask453(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask453(db,b), false);
  // (crule (pre) (scan temp4sU7325 __t4QnL42 r) (body) (head (mkstruct run (1 2 0) __12Xm228 r __t4QnL42)) antimirov.slog:90 #f)
  class ReadTask462 : public slog::Task
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
      head_rel[0] = db->getRelation("run");
      outer_rel = db->getRelation("temp4sU7325");
  
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
        u64 v_c83 = _t[0];
        u64 v_c11 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c83}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:90", "delta:temp4sU7325", _fires);
  
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
  // (crule (pre (let __tconst4jXV41 const12ae32cb1ec02d01eda3581b)) (scan query nm r) (body (join subject (0) 0 s) (let __t4QnL42 (ssplit s __tconst4jXV41))) (head (emit-temp temp4sU7325 __t4QnL42 r)) antimirov.slog:90 #f)
  class ReadTask464 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** subjectindex463;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4sU7325");
      outer_rel = db->getRelation("query");
      std::vector<u16> ord465({0});
      slog::Relation* readrel466 = db->getRelation("subject");
      subjectindex463 = readrel466->getIndex(ord465, false);
  
    }
    ReadTask464(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const12ae32cb1ec02d01eda3581b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c85 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_all<1>(subjectindex463, [&](const std::array<u64,1>& m467) {
          u64 v_c23 = m467[0];
          u64 v_c83 = _prim_ssplit(db, v_c23, v_c84);
          if (v_c83 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:90"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c83, v_c11});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:90", "delta:query", _fires);
  
      if (!_done)
      {
        ReadTask464* _cont = new ReadTask464(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask464(db,b), false);
  // (crule (pre (let __tconst8HyN174 constabce180ee56b2c323c19f642)) (scan mkcat __t0uGT77 __t6Vnq76 s) (body (join _enum (0 1) 2 __t6Vnq76 __tconst8HyN174)) (head (emit mkcat_ans (0 1) __t0uGT77 s)) antimirov.slog:56 #f)
  class ReadTask469 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex468;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat_ans");
      std::vector<u16> ord470({0, 1});
      slog::Relation* readrel471 = db->getRelation("mkcat_ans");
      head_index[0] = readrel471->getIndex(ord470, false);
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord472({0, 1});
      slog::Relation* readrel473 = db->getRelation("_enum");
      _enumindex468 = readrel473->getIndex(ord472, false);
  
    }
    ReadTask469(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_constabce180ee56b2c323c19f642;
  
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
        u64 v_c23 = _t[2];
        slog::join_probe<2,2>(_enumindex468, std::array<u64,2>{v_c88, v_c86}, [&](const std::array<u64,2>& m474) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c23}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:56", "delta:mkcat", _fires);
  
      if (!_done)
      {
        ReadTask469* _cont = new ReadTask469(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask469(db,b), false);
  // (crule (pre) (scan deriv __t70si3 r c) (body (exists star (1 0) 1 r) (exists deriv (2 0 1) 1 c) (join deriv_ans (0 1) 1 __t70si3 __v0) (exists mkcat (1 2 0) 1 __v0) (join-old star (1 0) 1 (1 0) r __t3xJI4) (exists mkcat (1 2 0) 2 __v0 __t3xJI4) (join deriv (1 2 0) 2 __t3xJI4 c __t9dkM2) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 __t3xJI4 __t3A2z5) (join mkcat_ans (0 1) 1 __t3A2z5 __v1)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask486 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex475;  slog::Index** derivindex476;  slog::Index** deriv_ansindex477;  slog::Index** mkcatindex478;  slog::Index** starindex479;  slog::Index** mkcatindex480;  slog::Index** derivindex481;  slog::Index** mkcatindex482;  slog::Index** mkcat_ansindex483;  slog::Index** stardelta484;  slog::Index** mkcatdelta485;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("deriv_ans");
      head_index[0] = readrel488->getIndex(ord487, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord489({1, 0});
      slog::Relation* readrel490 = db->getRelation("star");
      starindex475 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({2, 0, 1});
      slog::Relation* readrel492 = db->getRelation("deriv");
      derivindex476 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({0, 1});
      slog::Relation* readrel494 = db->getRelation("deriv_ans");
      deriv_ansindex477 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("mkcat");
      mkcatindex478 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 0});
      slog::Relation* readrel498 = db->getRelation("star");
      starindex479 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 0});
      slog::Relation* readrel500 = db->getRelation("star");
      stardelta484 = readrel500->getIndex(ord499, true);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("mkcat");
      mkcatindex480 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("deriv");
      derivindex481 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 2, 0});
      slog::Relation* readrel506 = db->getRelation("mkcat");
      mkcatindex482 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 2, 0});
      slog::Relation* readrel508 = db->getRelation("mkcat");
      mkcatdelta485 = readrel508->getIndex(ord507, true);
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("mkcat_ans");
      mkcat_ansindex483 = readrel510->getIndex(ord509, false);
  
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
        u64 v_c89 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<2,1>(starindex475, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex476, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<2,1>(deriv_ansindex477, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m511) {
          u64 v_c10 = m511[1];
          if (!slog::exists_probe<3,1>(mkcatindex478, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe_old<2,1>(starindex479, stardelta484, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m512) {
            u64 v_c90 = m512[1];
            if (!slog::exists_probe<3,2>(mkcatindex480, std::array<u64,3>{v_c10, v_c90, 0})) return;
            slog::join_probe<3,2>(derivindex481, std::array<u64,3>{v_c90, v_c12, 0}, [&](const std::array<u64,3>& m513) {
              u64 v_c91 = m513[2];
              slog::join_probe_old<3,2>(mkcatindex482, mkcatdelta485, std::array<u64,3>{v_c10, v_c90, 0}, [&](const std::array<u64,3>& m514) {
                u64 v_c92 = m514[2];
                slog::join_probe<2,1>(mkcat_ansindex483, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m515) {
                  u64 v_c93 = m515[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c91, v_c93}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan deriv __t1fTl18 __t9RZg17 c) (body (exists deriv (2 0 1) 1 c) (join $sup14449x70x0x0x0 (0 1 2 3) 2 __t1fTl18 c r s) (join cat (0 1 2) 3 __t9RZg17 r s) (exists mkcat (2 0 1) 1 s) (join-old deriv (1 2 0) 2 (1 2 0) r c __t3USy19) (join deriv_ans (0 1) 1 __t3USy19 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 s __t3Hfq20) (join mkcat_ans (0 1) 1 __t3Hfq20 __v1)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask526 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex516;  slog::Index** $sup14449x70x0x0x0index517;  slog::Index** catindex518;  slog::Index** mkcatindex519;  slog::Index** derivindex520;  slog::Index** deriv_ansindex521;  slog::Index** mkcatindex522;  slog::Index** mkcat_ansindex523;  slog::Index** derivdelta524;  slog::Index** mkcatdelta525;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("deriv_ans");
      head_index[0] = readrel528->getIndex(ord527, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord529({2, 0, 1});
      slog::Relation* readrel530 = db->getRelation("deriv");
      derivindex516 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1, 2, 3});
      slog::Relation* readrel532 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index517 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({0, 1, 2});
      slog::Relation* readrel534 = db->getRelation("cat");
      catindex518 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({2, 0, 1});
      slog::Relation* readrel536 = db->getRelation("mkcat");
      mkcatindex519 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("deriv");
      derivindex520 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("deriv");
      derivdelta524 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("deriv_ans");
      deriv_ansindex521 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 2, 0});
      slog::Relation* readrel544 = db->getRelation("mkcat");
      mkcatindex522 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 2, 0});
      slog::Relation* readrel546 = db->getRelation("mkcat");
      mkcatdelta525 = readrel546->getIndex(ord545, true);
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("mkcat_ans");
      mkcat_ansindex523 = readrel548->getIndex(ord547, false);
  
    }
    ReadTask526(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c94 = _t[0];
        u64 v_c95 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex516, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x70x0x0x0index517, std::array<u64,4>{v_c94, v_c12, 0, 0}, [&](const std::array<u64,4>& m549) {
          u64 v_c11 = m549[2]; u64 v_c23 = m549[3];
          slog::join_probe<3,3>(catindex518, std::array<u64,3>{v_c95, v_c11, v_c23}, [&](const std::array<u64,3>& m550) {
            if (!slog::exists_probe<3,1>(mkcatindex519, std::array<u64,3>{v_c23, 0, 0})) return;
            slog::join_probe_old<3,2>(derivindex520, derivdelta524, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m551) {
              u64 v_c96 = m551[2];
              slog::join_probe<2,1>(deriv_ansindex521, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m552) {
                u64 v_c10 = m552[1];
                slog::join_probe_old<3,2>(mkcatindex522, mkcatdelta525, std::array<u64,3>{v_c10, v_c23, 0}, [&](const std::array<u64,3>& m553) {
                  u64 v_c97 = m553[2];
                  slog::join_probe<2,1>(mkcat_ansindex523, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m554) {
                    u64 v_c93 = m554[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c94, v_c93}, std::array<u16,2>{0, 1});
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
        ReadTask526* _cont = new ReadTask526(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask526(db,b), false);
  // (crule (pre) (scan mkcat __t6haW83 __t5yew82 s) (body (join cat (0 1 2) 1 __t5yew82 a b)) (head (emit-temp temp5DUf326 __t5yew82 __t6haW83 s) (mkstruct cat (1 2 0) __t5GnC81 __t5yew82 s)) antimirov.slog:58 #f)
  class ReadTask556 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex555;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5DUf326");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("cat");
      catindex555 = readrel558->getIndex(ord557, false);
  
    }
    ReadTask556(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[0];
        u64 v_c62 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<3,1>(catindex555, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m559) {
          u64 v_c57 = m559[1]; u64 v_c63 = m559[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c62, v_c64, v_c23});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c62, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:58", "delta:mkcat", _fires);
  
      if (!_done)
      {
        ReadTask556* _cont = new ReadTask556(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask556(db,b), false);
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan cat __t4VgL122 r s) (body (exists nullable (1 0) 1 r) (exists deriv (1 2 0) 1 s) (exists $sup14449x71x0x0x0 (2 3 0 1) 2 r s) (exists $sup14449x71x0x0x1 (4 5 0 1 2 3) 2 r s) (exists deriv (1 2 0) 1 __t4VgL122) (join nullable_ans (0 1) 0 __t95K4125 n) (cmp lt __tconst0Lyv124 n) (exists nullable (0 1) 2 __t95K4125 r) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 4 __t95K4125 n r s) (join deriv_ans (0 1) 0 __t17NK126 __v0) (join-old nullable (0 1) 2 (0 1) __t95K4125 r) (join-old deriv (0 1 2) 2 (0 1 2) __t17NK126 s c) (exists deriv (1 2 0) 2 __t4VgL122 c) (join3 __t2zzw123 (full $sup14449x71x0x0x0 (1 3 2 0) 3 () c s r __t2zzw123) (full $sup14449x71x0x0x1 (1 2 3 5 4 0) 5 () __t95K4125 c n s r __t2zzw123)) (join-old deriv (0 1 2) 3 (0 1 2) __t2zzw123 __t4VgL122 c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask578 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex560;  slog::Index** derivindex561;  slog::Index** $sup14449x71x0x0x0index562;  slog::Index** $sup14449x71x0x0x1index563;  slog::Index** derivindex564;  slog::Index** nullable_ansindex565;  slog::Index** nullableindex566;  slog::Index** $sup14449x71x0x0x1index567;  slog::Index** deriv_ansindex568;  slog::Index** nullableindex569;  slog::Index** derivindex570;  slog::Index** derivindex571;  slog::Index** derivindex572;  slog::Index** $sup14449x71x0x0x0index573;  slog::Index** $sup14449x71x0x0x1index574;  slog::Index** nullabledelta575;  slog::Index** derivdelta576;  slog::Index** derivdelta577;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("deriv_ans");
      head_index[0] = readrel580->getIndex(ord579, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord581({1, 0});
      slog::Relation* readrel582 = db->getRelation("nullable");
      nullableindex560 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("deriv");
      derivindex561 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({2, 3, 0, 1});
      slog::Relation* readrel586 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index562 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel588 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index563 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("deriv");
      derivindex564 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 1});
      slog::Relation* readrel592 = db->getRelation("nullable_ans");
      nullable_ansindex565 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("nullable");
      nullableindex566 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel596 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index567 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({0, 1});
      slog::Relation* readrel598 = db->getRelation("deriv_ans");
      deriv_ansindex568 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("nullable");
      nullableindex569 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("nullable");
      nullabledelta575 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({0, 1, 2});
      slog::Relation* readrel604 = db->getRelation("deriv");
      derivindex570 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1, 2});
      slog::Relation* readrel606 = db->getRelation("deriv");
      derivdelta576 = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({1, 2, 0});
      slog::Relation* readrel608 = db->getRelation("deriv");
      derivindex571 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1, 2});
      slog::Relation* readrel610 = db->getRelation("deriv");
      derivindex572 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1, 2});
      slog::Relation* readrel612 = db->getRelation("deriv");
      derivdelta577 = readrel612->getIndex(ord611, true);
      std::vector<u16> ord613({1, 3, 2, 0});
      slog::Relation* readrel614 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index573 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel616 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index574 = readrel616->getIndex(ord615, false);
  
    }
    ReadTask578(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c23 = _t[2];
        if (!slog::exists_probe<2,1>(nullableindex560, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex561, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index562, std::array<u64,4>{v_c11, v_c23, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index563, std::array<u64,6>{v_c11, v_c23, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex564, std::array<u64,3>{v_c31, 0, 0})) return;
        slog::join_all<2>(nullable_ansindex565, [&](const std::array<u64,2>& m617) {
          u64 v_c28 = m617[0]; u64 v_c29 = m617[1];
          u64 v_c98 = _prim_lt(db, v_c26, v_c29);
          if (v_c98 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c98) return;
          if (!slog::exists_probe<2,2>(nullableindex566, std::array<u64,2>{v_c28, v_c11})) return;
          if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index567, std::array<u64,6>{v_c28, v_c29, v_c11, v_c23, 0, 0})) return;
          slog::join_all<2>(deriv_ansindex568, [&](const std::array<u64,2>& m619) {
            u64 v_c27 = m619[0]; u64 v_c10 = m619[1];
            slog::join_probe_old<2,2>(nullableindex569, nullabledelta575, std::array<u64,2>{v_c28, v_c11}, [&](const std::array<u64,2>& m620) {
              slog::join_probe_old<3,2>(derivindex570, derivdelta576, std::array<u64,3>{v_c27, v_c23, 0}, [&](const std::array<u64,3>& m621) {
                u64 v_c12 = m621[2];
                if (!slog::exists_probe<3,2>(derivindex571, std::array<u64,3>{v_c31, v_c12, 0})) return;
                slog::join3<4,3,slog::Join3View::full,6,5,slog::Join3View::full>($sup14449x71x0x0x0index573, $sup14449x71x0x0x0index573, std::array<u64,4>{v_c12, v_c23, v_c11, 0}, $sup14449x71x0x0x1index574, $sup14449x71x0x0x1index574, std::array<u64,6>{v_c28, v_c12, v_c29, v_c23, v_c11, 0}, [&](u64 cycle622) {
                u64 v_c32 = cycle622;
                  slog::join_probe_old<3,3>(derivindex572, derivdelta577, std::array<u64,3>{v_c32, v_c31, v_c12}, [&](const std::array<u64,3>& m623) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c10}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask578* _cont = new ReadTask578(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask578(db,b), false);
  // (crule (pre) (scan star __t8RSy36 r) (body (join-old deriv (1 2 0) 1 (1 2 0) __t8RSy36 c __t7KNy37)) (head (mkstruct deriv (1 2 0) __1VwH175 r c)) antimirov.slog:73 #f)
  class ReadTask626 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex624;  slog::Index** derivdelta625;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv");
      outer_rel = db->getRelation("star");
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("deriv");
      derivindex624 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 2, 0});
      slog::Relation* readrel630 = db->getRelation("deriv");
      derivdelta625 = readrel630->getIndex(ord629, true);
  
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
        u64 v_c99 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<3,1>(derivindex624, derivdelta625, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m631) {
          u64 v_c12 = m631[1]; u64 v_c100 = m631[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:star", _fires);
  
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
  // (crule (pre) (scan mkcat __t2GkP27 __t0JJd26 s) (body (join alt (0 1 2) 1 __t0JJd26 a b)) (head (emit-temp temp4ebc327 __t0JJd26 __t2GkP27 s) (mkstruct cat (1 2 0) __t2o7L25 __t0JJd26 s)) antimirov.slog:59 #f)
  class ReadTask633 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex632;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4ebc327");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord634({0, 1, 2});
      slog::Relation* readrel635 = db->getRelation("alt");
      altindex632 = readrel635->getIndex(ord634, false);
  
    }
    ReadTask633(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<3,1>(altindex632, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m636) {
          u64 v_c57 = m636[1]; u64 v_c63 = m636[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c102, v_c101, v_c23});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c102, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:59", "delta:mkcat", _fires);
  
      if (!_done)
      {
        ReadTask633* _cont = new ReadTask633(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask633(db,b), false);
  // (crule (pre (let __trid0fzH177 const30749c2c8a5c40a4f0a780b6) (let __trel6okx178 constd1596cb698715803872591d6) (let __tcol57TD179 const5feceb66ffc86f38d952786c)) (scan $sup14449x45x0x0x0 __d0 r s) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid0fzH177 __trel6okx178 __tcol57TD179 (1 2 3 4 0)) (mkstruct nullable (1 0) __1ndE176 r)) antimirov.slog:46 #f)
  class ReadTask642 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid640;  u32 sid637;  u32 sid638;  u32 sid639;  u32 sid641;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("nullable");
      outer_rel = db->getRelation("$sup14449x45x0x0x0");
      sid640 = db->getRelation("_enum")->getStructId();
      sid637 = db->getRelation("alt")->getStructId();
      sid638 = db->getRelation("cat")->getStructId();
      sid639 = db->getRelation("chr")->getStructId();
      sid641 = db->getRelation("star")->getStructId();
  
    }
    ReadTask642(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const30749c2c8a5c40a4f0a780b6;
      u64 v_c104 = v_constd1596cb698715803872591d6;
      u64 v_c105 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c11 = _t[1];
        u64 v_c23 = _t[2];
        ++_fires;
        if (!((is_struct(v_c11) && (decode_struct_id(v_c11) == sid637 || decode_struct_id(v_c11) == sid638 || decode_struct_id(v_c11) == sid639 || decode_struct_id(v_c11) == sid640 || decode_struct_id(v_c11) == sid641))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c103, v_c104, v_c105, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:$sup14449x45x0x0x0", _fires);
  
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
  // (crule (pre) (scan cat __t8U6m132 r s) (body (join-old nullable (1 0) 1 (1 0) __t8U6m132 __t4w6L133)) (head (emit $sup14449x45x0x0x0 (0 1 2) __t4w6L133 r s)) antimirov.slog:46 #f)
  class ReadTask645 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex643;  slog::Index** nullabledelta644;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x45x0x0x0");
      std::vector<u16> ord646({0, 1, 2});
      slog::Relation* readrel647 = db->getRelation("$sup14449x45x0x0x0");
      head_index[0] = readrel647->getIndex(ord646, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord648({1, 0});
      slog::Relation* readrel649 = db->getRelation("nullable");
      nullableindex643 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 0});
      slog::Relation* readrel651 = db->getRelation("nullable");
      nullabledelta644 = readrel651->getIndex(ord650, true);
  
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
        u64 v_c106 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe_old<2,1>(nullableindex643, nullabledelta644, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m652) {
          u64 v_c107 = m652[1];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c107, v_c11, v_c23}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:cat", _fires);
  
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
  // (crule (pre) (scan nan_result __erre5u5e289 __errf8jOw290 __errf91FE291 __errf7y2d292) (body) (head (emit error (0) __erre5u5e289)) <internal>:1 #f)
  class ReadTask653 : public slog::Task
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
      std::vector<u16> ord654({0});
      slog::Relation* readrel655 = db->getRelation("error");
      head_index[0] = readrel655->getIndex(ord654, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask653(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c108 = _t[0];
        u64 v_c109 = _t[1];
        u64 v_c110 = _t[2];
        u64 v_c111 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c108}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask653* _cont = new ReadTask653(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask653(db,b), false);
}

