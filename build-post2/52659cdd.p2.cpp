
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0dfced6e06d4ae6199e0f896;
extern u64 v_const439d97756c1f6d8e3f1b29c9;
extern u64 v_const5c7fc02224fc3e7f3cf5fdfc;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6d8bc911abd31f57d1b91158;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_conste7e898c68006c22d00270874;
extern u64 v_constf415be8f37f48a64565a412d;


void slog_rules_c39d6ed8e25e73f9e(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan nullable __t95K4125 r) (body (exists cat (1 2 0) 1 r) (exists $sup14449x71x0x0x0 (2 3 0 1) 1 r) (exists $sup14449x71x0x0x1 (1 4 0 2 3 5) 2 __t95K4125 r) (join nullable_ans (0 1) 1 __t95K4125 n) (cmp lt __tconst0Lyv124 n) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 3 __t95K4125 n r) (join deriv_ans (0 1) 0 __t17NK126 __v0) (join cat (1 2 0) 1 r s __t4VgL122) (exists $sup14449x71x0x0x0 (2 3 0 1) 2 r s) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 4 __t95K4125 n r s) (exists deriv (1 2 0) 1 __t4VgL122) (join-old deriv (0 1 2) 2 (0 1 2) __t17NK126 s c) (exists deriv (1 2 0) 2 __t4VgL122 c) (join3 __t2zzw123 (full $sup14449x71x0x0x0 (1 3 2 0) 3 () c s r __t2zzw123) (full $sup14449x71x0x0x1 (1 2 3 5 4 0) 5 () __t95K4125 c n s r __t2zzw123)) (join deriv (0 1 2) 3 __t2zzw123 __t4VgL122 c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex0;  slog::Index** $sup14449x71x0x0x0index1;  slog::Index** $sup14449x71x0x0x1index2;  slog::Index** nullable_ansindex3;  slog::Index** $sup14449x71x0x0x1index4;  slog::Index** deriv_ansindex5;  slog::Index** catindex6;  slog::Index** $sup14449x71x0x0x0index7;  slog::Index** $sup14449x71x0x0x1index8;  slog::Index** derivindex9;  slog::Index** derivindex10;  slog::Index** derivindex11;  slog::Index** derivindex12;  slog::Index** $sup14449x71x0x0x0index13;  slog::Index** $sup14449x71x0x0x1index14;  slog::Index** derivdelta15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("deriv_ans");
      head_index[0] = readrel18->getIndex(ord17, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("cat");
      catindex0 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({2, 3, 0, 1});
      slog::Relation* readrel22 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index1 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel24 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index2 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("nullable_ans");
      nullable_ansindex3 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel28 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index4 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("deriv_ans");
      deriv_ansindex5 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("cat");
      catindex6 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({2, 3, 0, 1});
      slog::Relation* readrel34 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index7 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel36 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index8 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("deriv");
      derivindex9 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1, 2});
      slog::Relation* readrel40 = db->getRelation("deriv");
      derivindex10 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1, 2});
      slog::Relation* readrel42 = db->getRelation("deriv");
      derivdelta15 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("deriv");
      derivindex11 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1, 2});
      slog::Relation* readrel46 = db->getRelation("deriv");
      derivindex12 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 3, 2, 0});
      slog::Relation* readrel48 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index13 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel50 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index14 = readrel50->getIndex(ord49, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<3,1>(catindex0, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup14449x71x0x0x0index1, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index2, std::array<u64,6>{v_c1, v_c2, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m51) {
          u64 v_c3 = m51[1];
          u64 v_c4 = _prim_lt(db, v_c0, v_c3);
          if (v_c4 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c4) return;
          if (!slog::exists_probe<6,3>($sup14449x71x0x0x1index4, std::array<u64,6>{v_c1, v_c3, v_c2, 0, 0, 0})) return;
          slog::join_all<2>(deriv_ansindex5, [&](const std::array<u64,2>& m53) {
            u64 v_c5 = m53[0]; u64 v_c6 = m53[1];
            slog::join_probe<3,1>(catindex6, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m54) {
              u64 v_c7 = m54[1]; u64 v_c8 = m54[2];
              if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index7, std::array<u64,4>{v_c2, v_c7, 0, 0})) return;
              if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index8, std::array<u64,6>{v_c1, v_c3, v_c2, v_c7, 0, 0})) return;
              if (!slog::exists_probe<3,1>(derivindex9, std::array<u64,3>{v_c8, 0, 0})) return;
              slog::join_probe_old<3,2>(derivindex10, derivdelta15, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m55) {
                u64 v_c9 = m55[2];
                if (!slog::exists_probe<3,2>(derivindex11, std::array<u64,3>{v_c8, v_c9, 0})) return;
                slog::join3<4,3,slog::Join3View::full,6,5,slog::Join3View::full>($sup14449x71x0x0x0index13, $sup14449x71x0x0x0index13, std::array<u64,4>{v_c9, v_c7, v_c2, 0}, $sup14449x71x0x0x1index14, $sup14449x71x0x0x1index14, std::array<u64,6>{v_c1, v_c9, v_c3, v_c7, v_c2, 0}, [&](u64 cycle56) {
                u64 v_c10 = cycle56;
                  slog::join_probe<3,3>(derivindex12, std::array<u64,3>{v_c10, v_c8, v_c9}, [&](const std::array<u64,3>& m57) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c6}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), false);
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan deriv_ans __t17NK126 __v0) (body (join nullable_ans (0 1) 0 __t95K4125 n) (cmp lt __tconst0Lyv124 n) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 2 __t95K4125 n) (join-old cat (0 1 2) 0 (0 1 2) __t4VgL122 r s) (join-old nullable (0 1) 2 (0 1) __t95K4125 r) (exists $sup14449x71x0x0x0 (2 3 0 1) 2 r s) (exists $sup14449x71x0x0x1 (1 3 4 5 0 2) 4 __t95K4125 n r s) (exists deriv (1 2 0) 1 __t4VgL122) (join-old deriv (0 1 2) 2 (0 1 2) __t17NK126 s c) (exists deriv (1 2 0) 2 __t4VgL122 c) (join3 __t2zzw123 (old $sup14449x71x0x0x0 (1 3 2 0) 3 (1 3 2 0) c s r __t2zzw123) (old $sup14449x71x0x0x1 (1 2 3 5 4 0) 5 (1 2 3 5 4 0) __t95K4125 c n s r __t2zzw123)) (join-old deriv (0 1 2) 3 (0 1 2) __t2zzw123 __t4VgL122 c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullable_ansindex58;  slog::Index** $sup14449x71x0x0x1index59;  slog::Index** catindex60;  slog::Index** nullableindex61;  slog::Index** $sup14449x71x0x0x0index62;  slog::Index** $sup14449x71x0x0x1index63;  slog::Index** derivindex64;  slog::Index** derivindex65;  slog::Index** derivindex66;  slog::Index** derivindex67;  slog::Index** $sup14449x71x0x0x0index68;  slog::Index** $sup14449x71x0x0x1index69;  slog::Index** catdelta70;  slog::Index** nullabledelta71;  slog::Index** derivdelta72;  slog::Index** derivdelta73;  slog::Index** $sup14449x71x0x0x0delta74;  slog::Index** $sup14449x71x0x0x1delta75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("deriv_ans");
      head_index[0] = readrel78->getIndex(ord77, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("nullable_ans");
      nullable_ansindex58 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel82 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index59 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1, 2});
      slog::Relation* readrel84 = db->getRelation("cat");
      catindex60 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2});
      slog::Relation* readrel86 = db->getRelation("cat");
      catdelta70 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("nullable");
      nullableindex61 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("nullable");
      nullabledelta71 = readrel90->getIndex(ord89, true);
      std::vector<u16> ord91({2, 3, 0, 1});
      slog::Relation* readrel92 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index62 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 3, 4, 5, 0, 2});
      slog::Relation* readrel94 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index63 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 2, 0});
      slog::Relation* readrel96 = db->getRelation("deriv");
      derivindex64 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("deriv");
      derivindex65 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 1, 2});
      slog::Relation* readrel100 = db->getRelation("deriv");
      derivdelta72 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({1, 2, 0});
      slog::Relation* readrel102 = db->getRelation("deriv");
      derivindex66 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({0, 1, 2});
      slog::Relation* readrel104 = db->getRelation("deriv");
      derivindex67 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1, 2});
      slog::Relation* readrel106 = db->getRelation("deriv");
      derivdelta73 = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({1, 3, 2, 0});
      slog::Relation* readrel108 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index68 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 3, 2, 0});
      slog::Relation* readrel110 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0delta74 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel112 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index69 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 3, 5, 4, 0});
      slog::Relation* readrel114 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1delta75 = readrel114->getIndex(ord113, true);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_all<2>(nullable_ansindex58, [&](const std::array<u64,2>& m115) {
          u64 v_c1 = m115[0]; u64 v_c3 = m115[1];
          u64 v_c11 = _prim_lt(db, v_c0, v_c3);
          if (v_c11 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c11) return;
          if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index59, std::array<u64,6>{v_c1, v_c3, 0, 0, 0, 0})) return;
          slog::join_all_old<3>(catindex60, catdelta70, [&](const std::array<u64,3>& m117) {
            u64 v_c8 = m117[0]; u64 v_c2 = m117[1]; u64 v_c7 = m117[2];
            slog::join_probe_old<2,2>(nullableindex61, nullabledelta71, std::array<u64,2>{v_c1, v_c2}, [&](const std::array<u64,2>& m118) {
              if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index62, std::array<u64,4>{v_c2, v_c7, 0, 0})) return;
              if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index63, std::array<u64,6>{v_c1, v_c3, v_c2, v_c7, 0, 0})) return;
              if (!slog::exists_probe<3,1>(derivindex64, std::array<u64,3>{v_c8, 0, 0})) return;
              slog::join_probe_old<3,2>(derivindex65, derivdelta72, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m119) {
                u64 v_c9 = m119[2];
                if (!slog::exists_probe<3,2>(derivindex66, std::array<u64,3>{v_c8, v_c9, 0})) return;
                slog::join3<4,3,slog::Join3View::old,6,5,slog::Join3View::old>($sup14449x71x0x0x0index68, $sup14449x71x0x0x0delta74, std::array<u64,4>{v_c9, v_c7, v_c2, 0}, $sup14449x71x0x0x1index69, $sup14449x71x0x0x1delta75, std::array<u64,6>{v_c1, v_c9, v_c3, v_c7, v_c2, 0}, [&](u64 cycle120) {
                u64 v_c10 = cycle120;
                  slog::join_probe_old<3,3>(derivindex67, derivdelta73, std::array<u64,3>{v_c10, v_c8, v_c9}, [&](const std::array<u64,3>& m121) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c6}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:deriv_ans", _fires);
  
      if (!_done)
      {
        ReadTask76* _cont = new ReadTask76(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask76(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst7i6460 __t7SBZ53) (exists alt (2 0 1) 1 __t7SBZ53) (exists cat (1 2 0) 1 __t7SBZ53) (join chr (1 0) 1 __tconst77RG62 __t8Axk58) (join alt (1 2 0) 2 __t8Axk58 __t7SBZ53 __t8pHj64) (join cat (1 2 0) 1 __t7SBZ53 dup02oI318 __t9z7256) (eq __t7SBZ53 dup02oI318)) (head (mkstruct star (1 0) __t5cfw65 __t8pHj64) (mkstruct cat (1 2 0) __t2gMK59 __t8Axk58 __t9z7256)) antimirov.slog:126 #f)
  class ReadTask128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** chrindex122;  slog::Index** altindex123;  slog::Index** catindex124;  slog::Index** chrindex125;  slog::Index** altindex126;  slog::Index** catindex127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("star");
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("star");
      head_index[0] = readrel130->getIndex(ord129, false);
      head_rel[1] = db->getRelation("cat");
      std::vector<u16> ord131({1, 2, 0});
      slog::Relation* readrel132 = db->getRelation("cat");
      head_index[1] = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("chr");
      chrindex122 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({2, 0, 1});
      slog::Relation* readrel136 = db->getRelation("alt");
      altindex123 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 0});
      slog::Relation* readrel138 = db->getRelation("cat");
      catindex124 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("chr");
      chrindex125 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("alt");
      altindex126 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("cat");
      catindex127 = readrel144->getIndex(ord143, false);
  
    }
    ReadTask128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c13 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c14 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex122, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m145) {
        u64 v_c15 = m145[1];
        if (!slog::exists_probe<3,1>(altindex123, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<3,1>(catindex124, std::array<u64,3>{v_c15, 0, 0})) return;
        slog::join_probe<2,1>(chrindex125, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m146) {
          u64 v_c16 = m146[1];
          slog::join_probe<3,2>(altindex126, std::array<u64,3>{v_c16, v_c15, 0}, [&](const std::array<u64,3>& m147) {
            u64 v_c17 = m147[2];
            slog::join_probe<3,1>(catindex127, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m148) {
              u64 v_c18 = m148[1]; u64 v_c19 = m148[2];
              if (v_c15 != v_c18) return;
              ++_fires;
              slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c16, v_c19}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask128(db,b));
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst77RG62 __t8Axk58) (exists alt (1 2 0) 1 __t8Axk58) (exists cat (1 2 0) 1 __t8Axk58) (join chr (1 0) 1 __tconst7i6460 __t7SBZ53) (exists cat (1 2 0) 1 __t7SBZ53) (join alt (1 2 0) 2 __t8Axk58 __t7SBZ53 __t8pHj64) (join star (1 0) 1 __t8pHj64 __t5cfw65) (join cat (1 2 0) 1 __t7SBZ53 dup4uFW320 __t9z7256) (eq __t7SBZ53 dup4uFW320) (join cat (1 2 0) 2 __t8Axk58 __t9z7256 __t2gMK59)) (head (mkstruct cat (1 2 0) __t3C3W66 __t5cfw65 __t2gMK59)) antimirov.slog:126 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex149;  slog::Index** altindex150;  slog::Index** catindex151;  slog::Index** chrindex152;  slog::Index** catindex153;  slog::Index** altindex154;  slog::Index** starindex155;  slog::Index** catindex156;  slog::Index** catindex157;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("cat");
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("cat");
      head_index[0] = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("chr");
      chrindex149 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("alt");
      altindex150 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("cat");
      catindex151 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("chr");
      chrindex152 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("cat");
      catindex153 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("alt");
      altindex154 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("star");
      starindex155 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("cat");
      catindex156 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("cat");
      catindex157 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c13 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c14 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex149, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m179) {
        u64 v_c16 = m179[1];
        if (!slog::exists_probe<3,1>(altindex150, std::array<u64,3>{v_c16, 0, 0})) return;
        if (!slog::exists_probe<3,1>(catindex151, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe<2,1>(chrindex152, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m180) {
          u64 v_c15 = m180[1];
          if (!slog::exists_probe<3,1>(catindex153, std::array<u64,3>{v_c15, 0, 0})) return;
          slog::join_probe<3,2>(altindex154, std::array<u64,3>{v_c16, v_c15, 0}, [&](const std::array<u64,3>& m181) {
            u64 v_c17 = m181[2];
            slog::join_probe<2,1>(starindex155, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m182) {
              u64 v_c20 = m182[1];
              slog::join_probe<3,1>(catindex156, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m183) {
                u64 v_c21 = m183[1]; u64 v_c19 = m183[2];
                if (v_c15 != v_c21) return;
                slog::join_probe<3,2>(catindex157, std::array<u64,3>{v_c16, v_c19, 0}, [&](const std::array<u64,3>& m184) {
                  u64 v_c22 = m184[2];
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c22}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask158(db,b));
  // (crule (pre) (scan deriv_ans __t70si3 __v0) (body (exists mkcat (1 2 0) 1 __v0) (join-old deriv (0 1 2) 1 (0 1 2) __t70si3 r c) (exists deriv (2 0 1) 1 c) (join-old star (1 0) 1 (1 0) r __t3xJI4) (exists mkcat (1 2 0) 2 __v0 __t3xJI4) (join-old deriv (1 2 0) 2 (1 2 0) __t3xJI4 c __t9dkM2) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 __t3xJI4 __t3A2z5) (join-old mkcat_ans (0 1) 1 (0 1) __t3A2z5 __v1)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask198 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex185;  slog::Index** derivindex186;  slog::Index** derivindex187;  slog::Index** starindex188;  slog::Index** mkcatindex189;  slog::Index** derivindex190;  slog::Index** mkcatindex191;  slog::Index** mkcat_ansindex192;  slog::Index** derivdelta193;  slog::Index** stardelta194;  slog::Index** derivdelta195;  slog::Index** mkcatdelta196;  slog::Index** mkcat_ansdelta197;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("deriv_ans");
      head_index[0] = readrel200->getIndex(ord199, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("mkcat");
      mkcatindex185 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1, 2});
      slog::Relation* readrel204 = db->getRelation("deriv");
      derivindex186 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1, 2});
      slog::Relation* readrel206 = db->getRelation("deriv");
      derivdelta193 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({2, 0, 1});
      slog::Relation* readrel208 = db->getRelation("deriv");
      derivindex187 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 0});
      slog::Relation* readrel210 = db->getRelation("star");
      starindex188 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("star");
      stardelta194 = readrel212->getIndex(ord211, true);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("mkcat");
      mkcatindex189 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("deriv");
      derivindex190 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("deriv");
      derivdelta195 = readrel218->getIndex(ord217, true);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("mkcat");
      mkcatindex191 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("mkcat");
      mkcatdelta196 = readrel222->getIndex(ord221, true);
      std::vector<u16> ord223({0, 1});
      slog::Relation* readrel224 = db->getRelation("mkcat_ans");
      mkcat_ansindex192 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1});
      slog::Relation* readrel226 = db->getRelation("mkcat_ans");
      mkcat_ansdelta197 = readrel226->getIndex(ord225, true);
  
    }
    ReadTask198(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>(mkcatindex185, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe_old<3,1>(derivindex186, derivdelta193, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m227) {
          u64 v_c2 = m227[1]; u64 v_c9 = m227[2];
          if (!slog::exists_probe<3,1>(derivindex187, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe_old<2,1>(starindex188, stardelta194, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m228) {
            u64 v_c24 = m228[1];
            if (!slog::exists_probe<3,2>(mkcatindex189, std::array<u64,3>{v_c6, v_c24, 0})) return;
            slog::join_probe_old<3,2>(derivindex190, derivdelta195, std::array<u64,3>{v_c24, v_c9, 0}, [&](const std::array<u64,3>& m229) {
              u64 v_c25 = m229[2];
              slog::join_probe_old<3,2>(mkcatindex191, mkcatdelta196, std::array<u64,3>{v_c6, v_c24, 0}, [&](const std::array<u64,3>& m230) {
                u64 v_c26 = m230[2];
                slog::join_probe_old<2,1>(mkcat_ansindex192, mkcat_ansdelta197, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m231) {
                  u64 v_c27 = m231[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c25, v_c27}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv_ans", _fires);
  
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
  // (crule (pre) (scan mkcat __t3A2z5 __v0 __t3xJI4) (body (exists mkcat_ans (0 1) 1 __t3A2z5) (exists deriv (1 2 0) 1 __t3xJI4) (join deriv_ans (1 0) 1 __v0 __t70si3) (join mkcat_ans (0 1) 1 __t3A2z5 __v1) (join star (0 1) 1 __t3xJI4 r) (join deriv (0 1 2) 2 __t70si3 r c) (join deriv (1 2 0) 2 __t3xJI4 c __t9dkM2)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcat_ansindex232;  slog::Index** derivindex233;  slog::Index** deriv_ansindex234;  slog::Index** mkcat_ansindex235;  slog::Index** starindex236;  slog::Index** derivindex237;  slog::Index** derivindex238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("deriv_ans");
      head_index[0] = readrel241->getIndex(ord240, false);
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("mkcat_ans");
      mkcat_ansindex232 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("deriv");
      derivindex233 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 0});
      slog::Relation* readrel247 = db->getRelation("deriv_ans");
      deriv_ansindex234 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("mkcat_ans");
      mkcat_ansindex235 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("star");
      starindex236 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1, 2});
      slog::Relation* readrel253 = db->getRelation("deriv");
      derivindex237 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("deriv");
      derivindex238 = readrel255->getIndex(ord254, false);
  
    }
    ReadTask239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c24 = _t[2];
        if (!slog::exists_probe<2,1>(mkcat_ansindex232, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex233, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe<2,1>(deriv_ansindex234, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m256) {
          u64 v_c23 = m256[1];
          slog::join_probe<2,1>(mkcat_ansindex235, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m257) {
            u64 v_c27 = m257[1];
            slog::join_probe<2,1>(starindex236, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m258) {
              u64 v_c2 = m258[1];
              slog::join_probe<3,2>(derivindex237, std::array<u64,3>{v_c23, v_c2, 0}, [&](const std::array<u64,3>& m259) {
                u64 v_c9 = m259[2];
                slog::join_probe<3,2>(derivindex238, std::array<u64,3>{v_c24, v_c9, 0}, [&](const std::array<u64,3>& m260) {
                  u64 v_c25 = m260[2];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c25, v_c27}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:mkcat", _fires);
  
      if (!_done)
      {
        ReadTask239* _cont = new ReadTask239(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask239(db,b), false);
  // (crule (pre) (scan deriv __t2byM14 r c) (body (exists alt (1 2 0) 1 r) (exists deriv (2 0 1) 1 c) (exists deriv_ans (0 1) 1 __t2byM14) (join $sup14449x68x0x0x0 (1 2 0 3) 2 c r __t2Yus13 s) (exists deriv (2 0 1) 2 c __t2Yus13) (join alt (1 2 0) 2 r s __t1uAM12) (join deriv (0 1 2) 3 __t2Yus13 __t1uAM12 c) (join deriv_ans (0 1) 1 __t2byM14 __v0)) (head (emit deriv_ans (0 1) __t2Yus13 __v0)) antimirov.slog:69 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex261;  slog::Index** derivindex262;  slog::Index** deriv_ansindex263;  slog::Index** $sup14449x68x0x0x0index264;  slog::Index** derivindex265;  slog::Index** altindex266;  slog::Index** derivindex267;  slog::Index** deriv_ansindex268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("deriv_ans");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("alt");
      altindex261 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({2, 0, 1});
      slog::Relation* readrel275 = db->getRelation("deriv");
      derivindex262 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1});
      slog::Relation* readrel277 = db->getRelation("deriv_ans");
      deriv_ansindex263 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 2, 0, 3});
      slog::Relation* readrel279 = db->getRelation("$sup14449x68x0x0x0");
      $sup14449x68x0x0x0index264 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({2, 0, 1});
      slog::Relation* readrel281 = db->getRelation("deriv");
      derivindex265 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 2, 0});
      slog::Relation* readrel283 = db->getRelation("alt");
      altindex266 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("deriv");
      derivindex267 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({0, 1});
      slog::Relation* readrel287 = db->getRelation("deriv_ans");
      deriv_ansindex268 = readrel287->getIndex(ord286, false);
  
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
        u64 v_c28 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<3,1>(altindex261, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex262, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(deriv_ansindex263, std::array<u64,2>{v_c28, 0})) return;
        slog::join_probe<4,2>($sup14449x68x0x0x0index264, std::array<u64,4>{v_c9, v_c2, 0, 0}, [&](const std::array<u64,4>& m288) {
          u64 v_c29 = m288[2]; u64 v_c7 = m288[3];
          if (!slog::exists_probe<3,2>(derivindex265, std::array<u64,3>{v_c9, v_c29, 0})) return;
          slog::join_probe<3,2>(altindex266, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m289) {
            u64 v_c30 = m289[2];
            slog::join_probe<3,3>(derivindex267, std::array<u64,3>{v_c29, v_c30, v_c9}, [&](const std::array<u64,3>& m290) {
              slog::join_probe<2,1>(deriv_ansindex268, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m291) {
                u64 v_c6 = m291[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c6}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan nullable __t4S29112 __t8cCt111) (body (join $sup14449x46x0x0x0 (0 1 2) 1 __t4S29112 r s) (join alt (0 1 2) 3 __t8cCt111 r s) (exists nullable (1 0) 1 s) (join-old nullable (1 0) 1 (1 0) r __t6Byf113) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (join-old nullable (1 0) 1 (1 0) s __t0lgX114) (join nullable_ans (0 1) 1 __t0lgX114 __v1) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x46x0x0x0index292;  slog::Index** altindex293;  slog::Index** nullableindex294;  slog::Index** nullableindex295;  slog::Index** nullable_ansindex296;  slog::Index** nullableindex297;  slog::Index** nullable_ansindex298;  slog::Index** nullabledelta299;  slog::Index** nullabledelta300;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord302({0, 1, 2});
      slog::Relation* readrel303 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index292 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1, 2});
      slog::Relation* readrel305 = db->getRelation("alt");
      altindex293 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 0});
      slog::Relation* readrel307 = db->getRelation("nullable");
      nullableindex294 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 0});
      slog::Relation* readrel309 = db->getRelation("nullable");
      nullableindex295 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("nullable");
      nullabledelta299 = readrel311->getIndex(ord310, true);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("nullable_ans");
      nullable_ansindex296 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 0});
      slog::Relation* readrel315 = db->getRelation("nullable");
      nullableindex297 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("nullable");
      nullabledelta300 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({0, 1});
      slog::Relation* readrel319 = db->getRelation("nullable_ans");
      nullable_ansindex298 = readrel319->getIndex(ord318, false);
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe<3,1>($sup14449x46x0x0x0index292, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m320) {
          u64 v_c2 = m320[1]; u64 v_c7 = m320[2];
          slog::join_probe<3,3>(altindex293, std::array<u64,3>{v_c32, v_c2, v_c7}, [&](const std::array<u64,3>& m321) {
            if (!slog::exists_probe<2,1>(nullableindex294, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe_old<2,1>(nullableindex295, nullabledelta299, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m322) {
              u64 v_c33 = m322[1];
              slog::join_probe<2,1>(nullable_ansindex296, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m323) {
                u64 v_c6 = m323[1];
                slog::join_probe_old<2,1>(nullableindex297, nullabledelta300, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m324) {
                  u64 v_c34 = m324[1];
                  slog::join_probe<2,1>(nullable_ansindex298, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m325) {
                    u64 v_c27 = m325[1];
                    u64 v_c35 = _prim_max(db, v_c6, v_c27);
                    if (v_c35 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c35, v_c31});
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
  // (crule (pre (let __tconst0Lyv124 const5feceb66ffc86f38d952786c)) (scan deriv __t2zzw123 __t4VgL122 c) (body (exists $sup14449x71x0x0x0 (0 1 2 3) 2 __t2zzw123 c) (exists $sup14449x71x0x0x1 (0 2 1 3 4 5) 2 __t2zzw123 c) (exists deriv (2 0 1) 1 c) (join nullable_ans (0 1) 0 __t95K4125 n) (cmp lt __tconst0Lyv124 n) (exists $sup14449x71x0x0x1 (0 2 1 3 4 5) 4 __t2zzw123 c __t95K4125 n) (join deriv_ans (0 1) 0 __t17NK126 __v0) (exists deriv (2 0 1) 2 c __t17NK126) (join-old nullable (0 1) 1 (0 1) __t95K4125 r) (exists cat (0 1 2) 2 __t4VgL122 r) (join3 s (full $sup14449x71x0x0x0 (0 1 2 3) 3 () __t2zzw123 c r s) (full $sup14449x71x0x0x1 (0 2 1 3 4 5) 5 () __t2zzw123 c __t95K4125 n r s)) (join cat (0 1 2) 3 __t4VgL122 r s) (join-old deriv (0 1 2) 3 (0 1 2) __t17NK126 s c)) (head (emit deriv_ans (0 1) __t2zzw123 __v0)) antimirov.slog:72 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x71x0x0x0index326;  slog::Index** $sup14449x71x0x0x1index327;  slog::Index** derivindex328;  slog::Index** nullable_ansindex329;  slog::Index** $sup14449x71x0x0x1index330;  slog::Index** deriv_ansindex331;  slog::Index** derivindex332;  slog::Index** nullableindex333;  slog::Index** catindex334;  slog::Index** catindex335;  slog::Index** derivindex336;  slog::Index** $sup14449x71x0x0x0index337;  slog::Index** $sup14449x71x0x0x1index338;  slog::Index** nullabledelta339;  slog::Index** derivdelta340;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("deriv_ans");
      head_index[0] = readrel343->getIndex(ord342, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord344({0, 1, 2, 3});
      slog::Relation* readrel345 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index326 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel347 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index327 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({2, 0, 1});
      slog::Relation* readrel349 = db->getRelation("deriv");
      derivindex328 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({0, 1});
      slog::Relation* readrel351 = db->getRelation("nullable_ans");
      nullable_ansindex329 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel353 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index330 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({0, 1});
      slog::Relation* readrel355 = db->getRelation("deriv_ans");
      deriv_ansindex331 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({2, 0, 1});
      slog::Relation* readrel357 = db->getRelation("deriv");
      derivindex332 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({0, 1});
      slog::Relation* readrel359 = db->getRelation("nullable");
      nullableindex333 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("nullable");
      nullabledelta339 = readrel361->getIndex(ord360, true);
      std::vector<u16> ord362({0, 1, 2});
      slog::Relation* readrel363 = db->getRelation("cat");
      catindex334 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1, 2});
      slog::Relation* readrel365 = db->getRelation("cat");
      catindex335 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1, 2});
      slog::Relation* readrel367 = db->getRelation("deriv");
      derivindex336 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({0, 1, 2});
      slog::Relation* readrel369 = db->getRelation("deriv");
      derivdelta340 = readrel369->getIndex(ord368, true);
      std::vector<u16> ord370({0, 1, 2, 3});
      slog::Relation* readrel371 = db->getRelation("$sup14449x71x0x0x0");
      $sup14449x71x0x0x0index337 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel373 = db->getRelation("$sup14449x71x0x0x1");
      $sup14449x71x0x0x1index338 = readrel373->getIndex(ord372, false);
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<4,2>($sup14449x71x0x0x0index326, std::array<u64,4>{v_c10, v_c9, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup14449x71x0x0x1index327, std::array<u64,6>{v_c10, v_c9, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex328, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_all<2>(nullable_ansindex329, [&](const std::array<u64,2>& m374) {
          u64 v_c1 = m374[0]; u64 v_c3 = m374[1];
          u64 v_c36 = _prim_lt(db, v_c0, v_c3);
          if (v_c36 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
          if (!v_c36) return;
          if (!slog::exists_probe<6,4>($sup14449x71x0x0x1index330, std::array<u64,6>{v_c10, v_c9, v_c1, v_c3, 0, 0})) return;
          slog::join_all<2>(deriv_ansindex331, [&](const std::array<u64,2>& m376) {
            u64 v_c5 = m376[0]; u64 v_c6 = m376[1];
            if (!slog::exists_probe<3,2>(derivindex332, std::array<u64,3>{v_c9, v_c5, 0})) return;
            slog::join_probe_old<2,1>(nullableindex333, nullabledelta339, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m377) {
              u64 v_c2 = m377[1];
              if (!slog::exists_probe<3,2>(catindex334, std::array<u64,3>{v_c8, v_c2, 0})) return;
              slog::join3<4,3,slog::Join3View::full,6,5,slog::Join3View::full>($sup14449x71x0x0x0index337, $sup14449x71x0x0x0index337, std::array<u64,4>{v_c10, v_c9, v_c2, 0}, $sup14449x71x0x0x1index338, $sup14449x71x0x0x1index338, std::array<u64,6>{v_c10, v_c9, v_c1, v_c3, v_c2, 0}, [&](u64 cycle378) {
              u64 v_c7 = cycle378;
                slog::join_probe<3,3>(catindex335, std::array<u64,3>{v_c8, v_c2, v_c7}, [&](const std::array<u64,3>& m379) {
                  slog::join_probe_old<3,3>(derivindex336, derivdelta340, std::array<u64,3>{v_c5, v_c7, v_c9}, [&](const std::array<u64,3>& m380) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c6}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan deriv __t2TCG31 r c) (body (exists star (1 0) 1 r) (exists deriv (2 0 1) 1 c) (join deriv_ans (0 1) 1 __t2TCG31 __v0) (join star (1 0) 1 r __t1wYz29) (join deriv (1 2 0) 2 __t1wYz29 c __t8rjP30)) (head (mkstruct mkcat (1 2 0) __7GaM229 __v0 __t1wYz29)) antimirov.slog:73 #f)
  class ReadTask386 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex381;  slog::Index** derivindex382;  slog::Index** deriv_ansindex383;  slog::Index** starindex384;  slog::Index** derivindex385;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat");
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord387({1, 0});
      slog::Relation* readrel388 = db->getRelation("star");
      starindex381 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({2, 0, 1});
      slog::Relation* readrel390 = db->getRelation("deriv");
      derivindex382 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("deriv_ans");
      deriv_ansindex383 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 0});
      slog::Relation* readrel394 = db->getRelation("star");
      starindex384 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("deriv");
      derivindex385 = readrel396->getIndex(ord395, false);
  
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
        u64 v_c37 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<2,1>(starindex381, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex382, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<2,1>(deriv_ansindex383, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m397) {
          u64 v_c6 = m397[1];
          slog::join_probe<2,1>(starindex384, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m398) {
            u64 v_c38 = m398[1];
            slog::join_probe<3,2>(derivindex385, std::array<u64,3>{v_c38, v_c9, 0}, [&](const std::array<u64,3>& m399) {
              u64 v_c39 = m399[2];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c38}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv", _fires);
  
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
  // (crule (pre (let __trid5orn191 const5c7fc02224fc3e7f3cf5fdfc) (let __trel7Ahr192 const0dfced6e06d4ae6199e0f896) (let __tcol1qbX193 const5feceb66ffc86f38d952786c) (let __trel05dT194 const0dfced6e06d4ae6199e0f896) (let __tcol2FRi195 const6b86b273ff34fce19d6b804e)) (scan $sup14449x69x0x0x0 __d0 c r s) (body) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid5orn191 __trel7Ahr192 __tcol1qbX193 (1 2 3 4 0)) (tycheck c (accept str) __trid5orn191 __trel05dT194 __tcol2FRi195 (1 2 3 4 0)) (mkstruct deriv (1 2 0) __0Dwv190 s c)) antimirov.slog:70 #f)
  class ReadTask405 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid403;  u32 sid400;  u32 sid401;  u32 sid402;  u32 sid404;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("deriv");
      outer_rel = db->getRelation("$sup14449x69x0x0x0");
      sid403 = db->getRelation("_enum")->getStructId();
      sid400 = db->getRelation("alt")->getStructId();
      sid401 = db->getRelation("cat")->getStructId();
      sid402 = db->getRelation("chr")->getStructId();
      sid404 = db->getRelation("star")->getStructId();
  
    }
    ReadTask405(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const5c7fc02224fc3e7f3cf5fdfc;
      u64 v_c41 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c42 = v_const5feceb66ffc86f38d952786c;
      u64 v_c43 = v_const0dfced6e06d4ae6199e0f896;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c45 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c7 = _t[3];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid400 || decode_struct_id(v_c7) == sid401 || decode_struct_id(v_c7) == sid402 || decode_struct_id(v_c7) == sid403 || decode_struct_id(v_c7) == sid404))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c40, v_c41, v_c42, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c9)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c40, v_c43, v_c44, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c7, v_c9}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:$sup14449x69x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask405* _cont = new ReadTask405(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask405(db,b), false);
  // (crule (pre) (scan nullable_ans __t6Byf113 __v0) (body (join-old nullable (0 1) 1 (0 1) __t6Byf113 r) (exists alt (1 2 0) 1 r) (join-old $sup14449x46x0x0x0 (1 2 0) 1 (1 2 0) r s __t4S29112) (exists nullable (1 0) 1 s) (join-old alt (1 2 0) 2 (1 2 0) r s __t8cCt111) (join-old nullable (0 1) 2 (0 1) __t4S29112 __t8cCt111) (join-old nullable (1 0) 1 (1 0) s __t0lgX114) (join-old nullable_ans (0 1) 1 (0 1) __t0lgX114 __v1) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask420 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex406;  slog::Index** altindex407;  slog::Index** $sup14449x46x0x0x0index408;  slog::Index** nullableindex409;  slog::Index** altindex410;  slog::Index** nullableindex411;  slog::Index** nullableindex412;  slog::Index** nullable_ansindex413;  slog::Index** nullabledelta414;  slog::Index** $sup14449x46x0x0x0delta415;  slog::Index** altdelta416;  slog::Index** nullabledelta417;  slog::Index** nullabledelta418;  slog::Index** nullable_ansdelta419;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("nullable");
      nullableindex406 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({0, 1});
      slog::Relation* readrel424 = db->getRelation("nullable");
      nullabledelta414 = readrel424->getIndex(ord423, true);
      std::vector<u16> ord425({1, 2, 0});
      slog::Relation* readrel426 = db->getRelation("alt");
      altindex407 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 0});
      slog::Relation* readrel428 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index408 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0delta415 = readrel430->getIndex(ord429, true);
      std::vector<u16> ord431({1, 0});
      slog::Relation* readrel432 = db->getRelation("nullable");
      nullableindex409 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 0});
      slog::Relation* readrel434 = db->getRelation("alt");
      altindex410 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 0});
      slog::Relation* readrel436 = db->getRelation("alt");
      altdelta416 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("nullable");
      nullableindex411 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("nullable");
      nullabledelta417 = readrel440->getIndex(ord439, true);
      std::vector<u16> ord441({1, 0});
      slog::Relation* readrel442 = db->getRelation("nullable");
      nullableindex412 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 0});
      slog::Relation* readrel444 = db->getRelation("nullable");
      nullabledelta418 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("nullable_ans");
      nullable_ansindex413 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({0, 1});
      slog::Relation* readrel448 = db->getRelation("nullable_ans");
      nullable_ansdelta419 = readrel448->getIndex(ord447, true);
  
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
        u64 v_c33 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_probe_old<2,1>(nullableindex406, nullabledelta414, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m449) {
          u64 v_c2 = m449[1];
          if (!slog::exists_probe<3,1>(altindex407, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<3,1>($sup14449x46x0x0x0index408, $sup14449x46x0x0x0delta415, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m450) {
            u64 v_c7 = m450[1]; u64 v_c31 = m450[2];
            if (!slog::exists_probe<2,1>(nullableindex409, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe_old<3,2>(altindex410, altdelta416, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m451) {
              u64 v_c32 = m451[2];
              slog::join_probe_old<2,2>(nullableindex411, nullabledelta417, std::array<u64,2>{v_c31, v_c32}, [&](const std::array<u64,2>& m452) {
                slog::join_probe_old<2,1>(nullableindex412, nullabledelta418, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m453) {
                  u64 v_c34 = m453[1];
                  slog::join_probe_old<2,1>(nullable_ansindex413, nullable_ansdelta419, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m454) {
                    u64 v_c27 = m454[1];
                    u64 v_c35 = _prim_max(db, v_c6, v_c27);
                    if (v_c35 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c35, v_c31});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:nullable_ans", _fires);
  
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
  // (crule (pre) (scan state r) (body (join-old deriv (1 2 0) 1 (1 2 0) r c __t43JV128) (join-old alpha (0) 1 (0) c) (join-old deriv_ans (0 1) 1 (0 1) __t43JV128 r2)) (head (emit nfa (0 1 2) r c r2) (emit state (0) r2)) antimirov.slog:115 #f)
  class ReadTask461 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex455;  slog::Index** alphaindex456;  slog::Index** deriv_ansindex457;  slog::Index** derivdelta458;  slog::Index** alphadelta459;  slog::Index** deriv_ansdelta460;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nfa");
      std::vector<u16> ord462({0, 1, 2});
      slog::Relation* readrel463 = db->getRelation("nfa");
      head_index[0] = readrel463->getIndex(ord462, false);
      head_rel[1] = db->getRelation("state");
      std::vector<u16> ord464({0});
      slog::Relation* readrel465 = db->getRelation("state");
      head_index[1] = readrel465->getIndex(ord464, false);
      outer_rel = db->getRelation("state");
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("deriv");
      derivindex455 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("deriv");
      derivdelta458 = readrel469->getIndex(ord468, true);
      std::vector<u16> ord470({0});
      slog::Relation* readrel471 = db->getRelation("alpha");
      alphaindex456 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0});
      slog::Relation* readrel473 = db->getRelation("alpha");
      alphadelta459 = readrel473->getIndex(ord472, true);
      std::vector<u16> ord474({0, 1});
      slog::Relation* readrel475 = db->getRelation("deriv_ans");
      deriv_ansindex457 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("deriv_ans");
      deriv_ansdelta460 = readrel477->getIndex(ord476, true);
  
    }
    ReadTask461(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        slog::join_probe_old<3,1>(derivindex455, derivdelta458, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m478) {
          u64 v_c9 = m478[1]; u64 v_c46 = m478[2];
          slog::join_probe_old<1,1>(alphaindex456, alphadelta459, std::array<u64,1>{v_c9}, [&](const std::array<u64,1>& m479) {
            slog::join_probe_old<2,1>(deriv_ansindex457, deriv_ansdelta460, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m480) {
              u64 v_c47 = m480[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c2, v_c9, v_c47}, std::array<u16,3>{0, 1, 2});
              slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:state", _fires);
  
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
  // (crule (pre (let __trid5ZcZ204 conste7e898c68006c22d00270874) (let __trel8qkJ205 constf415be8f37f48a64565a412d) (let __tcol9wok206 const6b86b273ff34fce19d6b804e)) (scan $sup14449x70x0x0x0 __d0 c r s) (body (join-old deriv (1 2 0) 2 (1 2 0) r c __t9BNj9) (join-old deriv_ans (0 1) 1 (0 1) __t9BNj9 __v0)) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid5ZcZ204 __trel8qkJ205 __tcol9wok206 (1 2 3 4 0)) (mkstruct mkcat (1 2 0) __6Dj3203 __v0 s)) antimirov.slog:71 #f)
  class ReadTask490 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex481;  slog::Index** deriv_ansindex482;  slog::Index** derivdelta483;  slog::Index** deriv_ansdelta484;
    u32 sid488;  u32 sid485;  u32 sid486;  u32 sid487;  u32 sid489;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mkcat");
      outer_rel = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord491({1, 2, 0});
      slog::Relation* readrel492 = db->getRelation("deriv");
      derivindex481 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("deriv");
      derivdelta483 = readrel494->getIndex(ord493, true);
      std::vector<u16> ord495({0, 1});
      slog::Relation* readrel496 = db->getRelation("deriv_ans");
      deriv_ansindex482 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("deriv_ans");
      deriv_ansdelta484 = readrel498->getIndex(ord497, true);
      sid488 = db->getRelation("_enum")->getStructId();
      sid485 = db->getRelation("alt")->getStructId();
      sid486 = db->getRelation("cat")->getStructId();
      sid487 = db->getRelation("chr")->getStructId();
      sid489 = db->getRelation("star")->getStructId();
  
    }
    ReadTask490(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_conste7e898c68006c22d00270874;
      u64 v_c49 = v_constf415be8f37f48a64565a412d;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe_old<3,2>(derivindex481, derivdelta483, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m499) {
          u64 v_c51 = m499[2];
          slog::join_probe_old<2,1>(deriv_ansindex482, deriv_ansdelta484, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m500) {
            u64 v_c6 = m500[1];
            ++_fires;
            if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid485 || decode_struct_id(v_c7) == sid486 || decode_struct_id(v_c7) == sid487 || decode_struct_id(v_c7) == sid488 || decode_struct_id(v_c7) == sid489))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c48, v_c49, v_c50, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:$sup14449x70x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask490* _cont = new ReadTask490(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask490(db,b), false);
  // (crule (pre (let __tconst7GyM108 const5feceb66ffc86f38d952786c)) (scan $sup14449x71x0x0x0 __d0 c r s) (body (join-old nullable (1 0) 1 (1 0) r __t3KPn107) (join-old nullable_ans (0 1) 1 (0 1) __t3KPn107 n) (cmp lt __tconst7GyM108 n)) (head (emit $sup14449x71x0x0x1 (0 2 1 3 4 5) __d0 c __t3KPn107 n r s)) antimirov.slog:72 #f)
  class ReadTask505 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex501;  slog::Index** nullable_ansindex502;  slog::Index** nullabledelta503;  slog::Index** nullable_ansdelta504;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord506({0, 2, 1, 3, 4, 5});
      slog::Relation* readrel507 = db->getRelation("$sup14449x71x0x0x1");
      head_index[0] = readrel507->getIndex(ord506, false);
      outer_rel = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord508({1, 0});
      slog::Relation* readrel509 = db->getRelation("nullable");
      nullableindex501 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("nullable");
      nullabledelta503 = readrel511->getIndex(ord510, true);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("nullable_ans");
      nullable_ansindex502 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1});
      slog::Relation* readrel515 = db->getRelation("nullable_ans");
      nullable_ansdelta504 = readrel515->getIndex(ord514, true);
  
    }
    ReadTask505(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe_old<2,1>(nullableindex501, nullabledelta503, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m516) {
          u64 v_c53 = m516[1];
          slog::join_probe_old<2,1>(nullable_ansindex502, nullable_ansdelta504, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m517) {
            u64 v_c3 = m517[1];
            u64 v_c54 = _prim_lt(db, v_c52, v_c3);
            if (v_c54 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:72"); return; }
            if (!v_c54) return;
            ++_fires;
            slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c45, v_c9, v_c53, v_c3, v_c2, v_c7}, std::array<u16,6>{0, 2, 1, 3, 4, 5});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:$sup14449x71x0x0x0", _fires);
  
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
  // (crule (pre) (scan mkcat __t3Hfq20 __v0 s) (body (exists mkcat_ans (0 1) 1 __t3Hfq20) (exists cat (2 0 1) 1 s) (exists $sup14449x70x0x0x0 (3 2 0 1) 1 s) (join deriv_ans (1 0) 1 __v0 __t3USy19) (join mkcat_ans (0 1) 1 __t3Hfq20 __v1) (join cat (2 0 1) 1 s __t9RZg17 r) (exists $sup14449x70x0x0x0 (3 2 0 1) 2 s r) (exists deriv (1 2 0) 1 __t9RZg17) (join deriv (0 1 2) 2 __t3USy19 r c) (exists deriv (1 2 0) 2 __t9RZg17 c) (join $sup14449x70x0x0x0 (1 2 3 0) 3 c r s __t1fTl18) (join deriv (0 1 2) 3 __t1fTl18 __t9RZg17 c)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask531 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcat_ansindex519;  slog::Index** catindex520;  slog::Index** $sup14449x70x0x0x0index521;  slog::Index** deriv_ansindex522;  slog::Index** mkcat_ansindex523;  slog::Index** catindex524;  slog::Index** $sup14449x70x0x0x0index525;  slog::Index** derivindex526;  slog::Index** derivindex527;  slog::Index** derivindex528;  slog::Index** $sup14449x70x0x0x0index529;  slog::Index** derivindex530;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord532({0, 1});
      slog::Relation* readrel533 = db->getRelation("deriv_ans");
      head_index[0] = readrel533->getIndex(ord532, false);
      outer_rel = db->getRelation("mkcat");
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("mkcat_ans");
      mkcat_ansindex519 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({2, 0, 1});
      slog::Relation* readrel537 = db->getRelation("cat");
      catindex520 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({3, 2, 0, 1});
      slog::Relation* readrel539 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index521 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 0});
      slog::Relation* readrel541 = db->getRelation("deriv_ans");
      deriv_ansindex522 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("mkcat_ans");
      mkcat_ansindex523 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({2, 0, 1});
      slog::Relation* readrel545 = db->getRelation("cat");
      catindex524 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({3, 2, 0, 1});
      slog::Relation* readrel547 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index525 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0});
      slog::Relation* readrel549 = db->getRelation("deriv");
      derivindex526 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({0, 1, 2});
      slog::Relation* readrel551 = db->getRelation("deriv");
      derivindex527 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 0});
      slog::Relation* readrel553 = db->getRelation("deriv");
      derivindex528 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 3, 0});
      slog::Relation* readrel555 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index529 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({0, 1, 2});
      slog::Relation* readrel557 = db->getRelation("deriv");
      derivindex530 = readrel557->getIndex(ord556, false);
  
    }
    ReadTask531(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(mkcat_ansindex519, std::array<u64,2>{v_c55, 0})) return;
        if (!slog::exists_probe<3,1>(catindex520, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup14449x70x0x0x0index521, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        slog::join_probe<2,1>(deriv_ansindex522, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m558) {
          u64 v_c56 = m558[1];
          slog::join_probe<2,1>(mkcat_ansindex523, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m559) {
            u64 v_c27 = m559[1];
            slog::join_probe<3,1>(catindex524, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m560) {
              u64 v_c57 = m560[1]; u64 v_c2 = m560[2];
              if (!slog::exists_probe<4,2>($sup14449x70x0x0x0index525, std::array<u64,4>{v_c7, v_c2, 0, 0})) return;
              if (!slog::exists_probe<3,1>(derivindex526, std::array<u64,3>{v_c57, 0, 0})) return;
              slog::join_probe<3,2>(derivindex527, std::array<u64,3>{v_c56, v_c2, 0}, [&](const std::array<u64,3>& m561) {
                u64 v_c9 = m561[2];
                if (!slog::exists_probe<3,2>(derivindex528, std::array<u64,3>{v_c57, v_c9, 0})) return;
                slog::join_probe<4,3>($sup14449x70x0x0x0index529, std::array<u64,4>{v_c9, v_c2, v_c7, 0}, [&](const std::array<u64,4>& m562) {
                  u64 v_c58 = m562[3];
                  slog::join_probe<3,3>(derivindex530, std::array<u64,3>{v_c58, v_c57, v_c9}, [&](const std::array<u64,3>& m563) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:mkcat", _fires);
  
      if (!_done)
      {
        ReadTask531* _cont = new ReadTask531(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask531(db,b), false);
  // (crule (pre) (scan $sup14449x45x0x0x0 __t7U0R87 r s) (body (exists nullable (1 0) 1 r) (exists nullable (1 0) 1 s) (join-old cat (1 2 0) 2 (1 2 0) r s __t3mF986) (join-old nullable (0 1) 2 (0 1) __t7U0R87 __t3mF986) (join-old nullable (1 0) 1 (1 0) r __t7OBQ88) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (join-old nullable (1 0) 1 (1 0) s __t5WkW89) (join nullable_ans (0 1) 1 __t5WkW89 __v1) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask576 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex564;  slog::Index** nullableindex565;  slog::Index** catindex566;  slog::Index** nullableindex567;  slog::Index** nullableindex568;  slog::Index** nullable_ansindex569;  slog::Index** nullableindex570;  slog::Index** nullable_ansindex571;  slog::Index** catdelta572;  slog::Index** nullabledelta573;  slog::Index** nullabledelta574;  slog::Index** nullabledelta575;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("$sup14449x45x0x0x0");
      std::vector<u16> ord577({1, 0});
      slog::Relation* readrel578 = db->getRelation("nullable");
      nullableindex564 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("nullable");
      nullableindex565 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("cat");
      catindex566 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("cat");
      catdelta572 = readrel584->getIndex(ord583, true);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("nullable");
      nullableindex567 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("nullable");
      nullabledelta573 = readrel588->getIndex(ord587, true);
      std::vector<u16> ord589({1, 0});
      slog::Relation* readrel590 = db->getRelation("nullable");
      nullableindex568 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 0});
      slog::Relation* readrel592 = db->getRelation("nullable");
      nullabledelta574 = readrel592->getIndex(ord591, true);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("nullable_ans");
      nullable_ansindex569 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 0});
      slog::Relation* readrel596 = db->getRelation("nullable");
      nullableindex570 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 0});
      slog::Relation* readrel598 = db->getRelation("nullable");
      nullabledelta575 = readrel598->getIndex(ord597, true);
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("nullable_ans");
      nullable_ansindex571 = readrel600->getIndex(ord599, false);
  
    }
    ReadTask576(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(nullableindex564, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex565, std::array<u64,2>{v_c7, 0})) return;
        slog::join_probe_old<3,2>(catindex566, catdelta572, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m601) {
          u64 v_c60 = m601[2];
          slog::join_probe_old<2,2>(nullableindex567, nullabledelta573, std::array<u64,2>{v_c59, v_c60}, [&](const std::array<u64,2>& m602) {
            slog::join_probe_old<2,1>(nullableindex568, nullabledelta574, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m603) {
              u64 v_c61 = m603[1];
              slog::join_probe<2,1>(nullable_ansindex569, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m604) {
                u64 v_c6 = m604[1];
                slog::join_probe_old<2,1>(nullableindex570, nullabledelta575, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m605) {
                  u64 v_c62 = m605[1];
                  slog::join_probe<2,1>(nullable_ansindex571, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m606) {
                    u64 v_c27 = m606[1];
                    u64 v_c63 = _prim__0002a(db, v_c6, v_c27);
                    if (v_c63 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c59});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:$sup14449x45x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask576* _cont = new ReadTask576(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask576(db,b), false);
  // (crule (pre) (scan temp5pCD310 __t08Xq94 __t7r4Z93 s) (body (join cat (1 2 0) 2 __t7r4Z93 s __t7HJf92)) (head (emit mkcat_ans (0 1) __t08Xq94 __t7HJf92)) antimirov.slog:60 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mkcat_ans");
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("mkcat_ans");
      head_index[0] = readrel610->getIndex(ord609, false);
      outer_rel = db->getRelation("temp5pCD310");
      std::vector<u16> ord611({1, 2, 0});
      slog::Relation* readrel612 = db->getRelation("cat");
      catindex607 = readrel612->getIndex(ord611, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[2];
        slog::join_probe<3,2>(catindex607, std::array<u64,3>{v_c65, v_c7, 0}, [&](const std::array<u64,3>& m613) {
          u64 v_c66 = m613[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c66}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:60", "delta:temp5pCD310", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre49Jk282 __errf0KqJ283 __errf7vmu284) (body) (head (emit error (0) __erre49Jk282)) <internal>:1 #f)
  class ReadTask614 : public slog::Task
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
      std::vector<u16> ord615({0});
      slog::Relation* readrel616 = db->getRelation("error");
      head_index[0] = readrel616->getIndex(ord615, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask614(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c67}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask614* _cont = new ReadTask614(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask614(db,b), false);
  // (crule (pre) (scan cat __t3dhA32 r s) (body (join-old deriv (1 2 0) 1 (1 2 0) __t3dhA32 c __t7laT33)) (head (emit $sup14449x71x0x0x0 (2 3 0 1) r s __t7laT33 c)) antimirov.slog:72 #f)
  class ReadTask619 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex617;  slog::Index** derivdelta618;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord620({2, 3, 0, 1});
      slog::Relation* readrel621 = db->getRelation("$sup14449x71x0x0x0");
      head_index[0] = readrel621->getIndex(ord620, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("deriv");
      derivindex617 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("deriv");
      derivdelta618 = readrel625->getIndex(ord624, true);
  
    }
    ReadTask619(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe_old<3,1>(derivindex617, derivdelta618, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m626) {
          u64 v_c9 = m626[1]; u64 v_c71 = m626[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c7, v_c71, v_c9}, std::array<u16,4>{2, 3, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask619* _cont = new ReadTask619(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask619(db,b), false);
  // (crule (pre) (scan query nm r) (body) (head (emit frag (0) r)) antimirov.slog:105 #f)
  class ReadTask627 : public slog::Task
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
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord628({0});
      slog::Relation* readrel629 = db->getRelation("frag");
      head_index[0] = readrel629->getIndex(ord628, false);
      outer_rel = db->getRelation("query");
  
    }
    ReadTask627(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c2 = _t[1];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:105", "delta:query", _fires);
  
      if (!_done)
      {
        ReadTask627* _cont = new ReadTask627(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask627(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (scan cat __t4yUC99 __t4w1Y98 __t6I9I96) (body (join chr (0 1) 2 __t6I9I96 __tconst8qEb95) (join chr (0 1) 2 __t4w1Y98 __tconst3Xg1100)) (head (mkstruct alt (1 2 0) __t5G2v102 __t4w1Y98 __t4yUC99)) antimirov.slog:130 #f)
  class ReadTask632 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex630;  slog::Index** chrindex631;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alt");
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord633({0, 1});
      slog::Relation* readrel634 = db->getRelation("chr");
      chrindex630 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("chr");
      chrindex631 = readrel636->getIndex(ord635, false);
  
    }
    ReadTask632(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c74 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c75 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        slog::join_probe<2,2>(chrindex630, std::array<u64,2>{v_c78, v_c75}, [&](const std::array<u64,2>& m637) {
          slog::join_probe<2,2>(chrindex631, std::array<u64,2>{v_c77, v_c74}, [&](const std::array<u64,2>& m638) {
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c77, v_c76}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask632* _cont = new ReadTask632(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask632(db,b), false);
  // (crule (pre) (scan alt __t0JJd26 a b) (body (join-old mkcat (1 2 0) 1 (1 2 0) __t0JJd26 s __t2GkP27)) (head (emit-temp temp4ebc327 __t0JJd26 __t2GkP27 s) (mkstruct cat (1 2 0) __t2o7L25 __t0JJd26 s)) antimirov.slog:59 #f)
  class ReadTask641 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex639;  slog::Index** mkcatdelta640;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4ebc327");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("mkcat");
      mkcatindex639 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("mkcat");
      mkcatdelta640 = readrel645->getIndex(ord644, true);
  
    }
    ReadTask641(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[0];
        u64 v_c80 = _t[1];
        u64 v_c81 = _t[2];
        slog::join_probe_old<3,1>(mkcatindex639, mkcatdelta640, std::array<u64,3>{v_c79, 0, 0}, [&](const std::array<u64,3>& m646) {
          u64 v_c7 = m646[1]; u64 v_c82 = m646[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c79, v_c82, v_c7});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c79, v_c7}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:59", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask641* _cont = new ReadTask641(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask641(db,b), false);
  // (crule (pre) (scan deriv __t2Yus13 __t1uAM12 c) (body (exists deriv (2 0 1) 1 c) (join $sup14449x68x0x0x0 (0 1 2 3) 2 __t2Yus13 c r s) (join alt (0 1 2) 3 __t1uAM12 r s) (join-old deriv (1 2 0) 2 (1 2 0) r c __t2byM14) (join deriv_ans (0 1) 1 __t2byM14 __v0)) (head (emit deriv_ans (0 1) __t2Yus13 __v0)) antimirov.slog:69 #f)
  class ReadTask653 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex647;  slog::Index** $sup14449x68x0x0x0index648;  slog::Index** altindex649;  slog::Index** derivindex650;  slog::Index** deriv_ansindex651;  slog::Index** derivdelta652;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("deriv_ans");
      head_index[0] = readrel655->getIndex(ord654, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord656({2, 0, 1});
      slog::Relation* readrel657 = db->getRelation("deriv");
      derivindex647 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 1, 2, 3});
      slog::Relation* readrel659 = db->getRelation("$sup14449x68x0x0x0");
      $sup14449x68x0x0x0index648 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 1, 2});
      slog::Relation* readrel661 = db->getRelation("alt");
      altindex649 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("deriv");
      derivindex650 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("deriv");
      derivdelta652 = readrel665->getIndex(ord664, true);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("deriv_ans");
      deriv_ansindex651 = readrel667->getIndex(ord666, false);
  
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<3,1>(derivindex647, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<4,2>($sup14449x68x0x0x0index648, std::array<u64,4>{v_c29, v_c9, 0, 0}, [&](const std::array<u64,4>& m668) {
          u64 v_c2 = m668[2]; u64 v_c7 = m668[3];
          slog::join_probe<3,3>(altindex649, std::array<u64,3>{v_c30, v_c2, v_c7}, [&](const std::array<u64,3>& m669) {
            slog::join_probe_old<3,2>(derivindex650, derivdelta652, std::array<u64,3>{v_c2, v_c9, 0}, [&](const std::array<u64,3>& m670) {
              u64 v_c28 = m670[2];
              slog::join_probe<2,1>(deriv_ansindex651, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m671) {
                u64 v_c6 = m671[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c6}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:69", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan deriv __t43JV128 r c) (body (join state (0) 1 r) (join alpha (0) 1 c) (join deriv_ans (0 1) 1 __t43JV128 r2)) (head (emit nfa (0 1 2) r c r2) (emit state (0) r2)) antimirov.slog:115 #f)
  class ReadTask675 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stateindex672;  slog::Index** alphaindex673;  slog::Index** deriv_ansindex674;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nfa");
      std::vector<u16> ord676({0, 1, 2});
      slog::Relation* readrel677 = db->getRelation("nfa");
      head_index[0] = readrel677->getIndex(ord676, false);
      head_rel[1] = db->getRelation("state");
      std::vector<u16> ord678({0});
      slog::Relation* readrel679 = db->getRelation("state");
      head_index[1] = readrel679->getIndex(ord678, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord680({0});
      slog::Relation* readrel681 = db->getRelation("state");
      stateindex672 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({0});
      slog::Relation* readrel683 = db->getRelation("alpha");
      alphaindex673 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("deriv_ans");
      deriv_ansindex674 = readrel685->getIndex(ord684, false);
  
    }
    ReadTask675(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c9 = _t[2];
        slog::join_probe<1,1>(stateindex672, std::array<u64,1>{v_c2}, [&](const std::array<u64,1>& m686) {
          slog::join_probe<1,1>(alphaindex673, std::array<u64,1>{v_c9}, [&](const std::array<u64,1>& m687) {
            slog::join_probe<2,1>(deriv_ansindex674, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m688) {
              u64 v_c47 = m688[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c2, v_c9, v_c47}, std::array<u16,3>{0, 1, 2});
              slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask675* _cont = new ReadTask675(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask675(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst77RG62 __t8Axk58) (exists alt (1 2 0) 1 __t8Axk58) (exists cat (1 2 0) 1 __t8Axk58) (join chr (1 0) 1 __tconst7i6460 __t7SBZ53) (exists cat (1 2 0) 1 __t7SBZ53) (join alt (1 2 0) 2 __t8Axk58 __t7SBZ53 __t8pHj64) (join star (1 0) 1 __t8pHj64 __t5cfw65) (exists cat (1 2 0) 1 __t5cfw65) (join cat (1 2 0) 1 __t7SBZ53 dup9ett322 __t9z7256) (eq __t7SBZ53 dup9ett322) (join cat (1 2 0) 2 __t8Axk58 __t9z7256 __t2gMK59) (join cat (1 2 0) 2 __t5cfw65 __t2gMK59 __t3C3W66)) (head (emit query (0 1) __tconst9dp567 __t3C3W66)) antimirov.slog:126 #f)
  class ReadTask700 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex689;  slog::Index** altindex690;  slog::Index** catindex691;  slog::Index** chrindex692;  slog::Index** catindex693;  slog::Index** altindex694;  slog::Index** starindex695;  slog::Index** catindex696;  slog::Index** catindex697;  slog::Index** catindex698;  slog::Index** catindex699;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("query");
      std::vector<u16> ord701({0, 1});
      slog::Relation* readrel702 = db->getRelation("query");
      head_index[0] = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 0});
      slog::Relation* readrel704 = db->getRelation("chr");
      chrindex689 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("alt");
      altindex690 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("cat");
      catindex691 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 0});
      slog::Relation* readrel710 = db->getRelation("chr");
      chrindex692 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 0});
      slog::Relation* readrel712 = db->getRelation("cat");
      catindex693 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 0});
      slog::Relation* readrel714 = db->getRelation("alt");
      altindex694 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 0});
      slog::Relation* readrel716 = db->getRelation("star");
      starindex695 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("cat");
      catindex696 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 0});
      slog::Relation* readrel720 = db->getRelation("cat");
      catindex697 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({1, 2, 0});
      slog::Relation* readrel722 = db->getRelation("cat");
      catindex698 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 2, 0});
      slog::Relation* readrel724 = db->getRelation("cat");
      catindex699 = readrel724->getIndex(ord723, false);
  
    }
    ReadTask700(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c13 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c14 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex689, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m725) {
        u64 v_c16 = m725[1];
        if (!slog::exists_probe<3,1>(altindex690, std::array<u64,3>{v_c16, 0, 0})) return;
        if (!slog::exists_probe<3,1>(catindex691, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe<2,1>(chrindex692, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m726) {
          u64 v_c15 = m726[1];
          if (!slog::exists_probe<3,1>(catindex693, std::array<u64,3>{v_c15, 0, 0})) return;
          slog::join_probe<3,2>(altindex694, std::array<u64,3>{v_c16, v_c15, 0}, [&](const std::array<u64,3>& m727) {
            u64 v_c17 = m727[2];
            slog::join_probe<2,1>(starindex695, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m728) {
              u64 v_c20 = m728[1];
              if (!slog::exists_probe<3,1>(catindex696, std::array<u64,3>{v_c20, 0, 0})) return;
              slog::join_probe<3,1>(catindex697, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m729) {
                u64 v_c83 = m729[1]; u64 v_c19 = m729[2];
                if (v_c15 != v_c83) return;
                slog::join_probe<3,2>(catindex698, std::array<u64,3>{v_c16, v_c19, 0}, [&](const std::array<u64,3>& m730) {
                  u64 v_c22 = m730[2];
                  slog::join_probe<3,2>(catindex699, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m731) {
                    u64 v_c84 = m731[2];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c84}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask700(db,b));
  // (crule (pre) (scan alt __t30Rf69 r s) (body (join-old nullable (1 0) 1 (1 0) __t30Rf69 __t750i70)) (head (emit $sup14449x46x0x0x0 (0 1 2) __t750i70 r s)) antimirov.slog:47 #f)
  class ReadTask734 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex732;  slog::Index** nullabledelta733;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x46x0x0x0");
      std::vector<u16> ord735({0, 1, 2});
      slog::Relation* readrel736 = db->getRelation("$sup14449x46x0x0x0");
      head_index[0] = readrel736->getIndex(ord735, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord737({1, 0});
      slog::Relation* readrel738 = db->getRelation("nullable");
      nullableindex732 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 0});
      slog::Relation* readrel740 = db->getRelation("nullable");
      nullabledelta733 = readrel740->getIndex(ord739, true);
  
    }
    ReadTask734(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c85 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe_old<2,1>(nullableindex732, nullabledelta733, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m741) {
          u64 v_c86 = m741[1];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c86, v_c2, v_c7}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask734* _cont = new ReadTask734(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask734(db,b), false);
  // (crule (pre) (scan deriv_ans __t3USy19 __v0) (body (exists mkcat (1 2 0) 1 __v0) (join-old deriv (0 1 2) 1 (0 1 2) __t3USy19 r c) (exists cat (1 2 0) 1 r) (exists deriv (2 0 1) 1 c) (join-old $sup14449x70x0x0x0 (1 2 3 0) 2 (1 2 3 0) c r s __t1fTl18) (exists deriv (2 0 1) 2 c __t1fTl18) (exists mkcat (1 2 0) 2 __v0 s) (join-old cat (1 2 0) 2 (1 2 0) r s __t9RZg17) (join-old deriv (0 1 2) 3 (0 1 2) __t1fTl18 __t9RZg17 c) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 s __t3Hfq20) (join-old mkcat_ans (0 1) 1 (0 1) __t3Hfq20 __v1)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask759 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex742;  slog::Index** derivindex743;  slog::Index** catindex744;  slog::Index** derivindex745;  slog::Index** $sup14449x70x0x0x0index746;  slog::Index** derivindex747;  slog::Index** mkcatindex748;  slog::Index** catindex749;  slog::Index** derivindex750;  slog::Index** mkcatindex751;  slog::Index** mkcat_ansindex752;  slog::Index** derivdelta753;  slog::Index** $sup14449x70x0x0x0delta754;  slog::Index** catdelta755;  slog::Index** derivdelta756;  slog::Index** mkcatdelta757;  slog::Index** mkcat_ansdelta758;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("deriv_ans");
      head_index[0] = readrel761->getIndex(ord760, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord762({1, 2, 0});
      slog::Relation* readrel763 = db->getRelation("mkcat");
      mkcatindex742 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("deriv");
      derivindex743 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("deriv");
      derivdelta753 = readrel767->getIndex(ord766, true);
      std::vector<u16> ord768({1, 2, 0});
      slog::Relation* readrel769 = db->getRelation("cat");
      catindex744 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("deriv");
      derivindex745 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 2, 3, 0});
      slog::Relation* readrel773 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index746 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 2, 3, 0});
      slog::Relation* readrel775 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0delta754 = readrel775->getIndex(ord774, true);
      std::vector<u16> ord776({2, 0, 1});
      slog::Relation* readrel777 = db->getRelation("deriv");
      derivindex747 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 0});
      slog::Relation* readrel779 = db->getRelation("mkcat");
      mkcatindex748 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 0});
      slog::Relation* readrel781 = db->getRelation("cat");
      catindex749 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 0});
      slog::Relation* readrel783 = db->getRelation("cat");
      catdelta755 = readrel783->getIndex(ord782, true);
      std::vector<u16> ord784({0, 1, 2});
      slog::Relation* readrel785 = db->getRelation("deriv");
      derivindex750 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({0, 1, 2});
      slog::Relation* readrel787 = db->getRelation("deriv");
      derivdelta756 = readrel787->getIndex(ord786, true);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("mkcat");
      mkcatindex751 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("mkcat");
      mkcatdelta757 = readrel791->getIndex(ord790, true);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("mkcat_ans");
      mkcat_ansindex752 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("mkcat_ans");
      mkcat_ansdelta758 = readrel795->getIndex(ord794, true);
  
    }
    ReadTask759(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>(mkcatindex742, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe_old<3,1>(derivindex743, derivdelta753, std::array<u64,3>{v_c56, 0, 0}, [&](const std::array<u64,3>& m796) {
          u64 v_c2 = m796[1]; u64 v_c9 = m796[2];
          if (!slog::exists_probe<3,1>(catindex744, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(derivindex745, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe_old<4,2>($sup14449x70x0x0x0index746, $sup14449x70x0x0x0delta754, std::array<u64,4>{v_c9, v_c2, 0, 0}, [&](const std::array<u64,4>& m797) {
            u64 v_c7 = m797[2]; u64 v_c58 = m797[3];
            if (!slog::exists_probe<3,2>(derivindex747, std::array<u64,3>{v_c9, v_c58, 0})) return;
            if (!slog::exists_probe<3,2>(mkcatindex748, std::array<u64,3>{v_c6, v_c7, 0})) return;
            slog::join_probe_old<3,2>(catindex749, catdelta755, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m798) {
              u64 v_c57 = m798[2];
              slog::join_probe_old<3,3>(derivindex750, derivdelta756, std::array<u64,3>{v_c58, v_c57, v_c9}, [&](const std::array<u64,3>& m799) {
                slog::join_probe_old<3,2>(mkcatindex751, mkcatdelta757, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m800) {
                  u64 v_c55 = m800[2];
                  slog::join_probe_old<2,1>(mkcat_ansindex752, mkcat_ansdelta758, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m801) {
                    u64 v_c27 = m801[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c58, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:deriv_ans", _fires);
  
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
  // (crule (pre (let __tconst70YG21 const5feceb66ffc86f38d952786c)) (scan chr __t39D622 c) (body (join-old nullable (1 0) 1 (1 0) __t39D622 __t71qa23)) (head (emit nullable_ans (0 1) __t71qa23 __tconst70YG21)) antimirov.slog:44 #f)
  class ReadTask804 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex802;  slog::Index** nullabledelta803;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord805({0, 1});
      slog::Relation* readrel806 = db->getRelation("nullable_ans");
      head_index[0] = readrel806->getIndex(ord805, false);
      outer_rel = db->getRelation("chr");
      std::vector<u16> ord807({1, 0});
      slog::Relation* readrel808 = db->getRelation("nullable");
      nullableindex802 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 0});
      slog::Relation* readrel810 = db->getRelation("nullable");
      nullabledelta803 = readrel810->getIndex(ord809, true);
  
    }
    ReadTask804(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        slog::join_probe_old<2,1>(nullableindex802, nullabledelta803, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m811) {
          u64 v_c89 = m811[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c89, v_c87}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:44", "delta:chr", _fires);
  
      if (!_done)
      {
        ReadTask804* _cont = new ReadTask804(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask804(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre8wEt274 __errf8l0G275 __errf1xZU276 __errf0LMd277 __errf0q43278) (body) (head (emit error (0) __erre8wEt274)) <internal>:1 #f)
  class ReadTask812 : public slog::Task
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
      std::vector<u16> ord813({0});
      slog::Relation* readrel814 = db->getRelation("error");
      head_index[0] = readrel814->getIndex(ord813, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask812(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        u64 v_c93 = _t[3];
        u64 v_c94 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c90}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask812* _cont = new ReadTask812(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask812(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (scan star __t4CfV103 __t5G2v102) (body (exists chr (1 0) 1 __tconst8qEb95) (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98) (exists cat (1 2 0) 1 __t4w1Y98) (join alt (0 1 2) 2 __t5G2v102 __t4w1Y98 __t4yUC99) (join cat (0 1 2) 2 __t4yUC99 __t4w1Y98 __t6I9I96) (join chr (0 1) 2 __t6I9I96 __tconst8qEb95)) (head (emit query (0 1) __tconst53SJ104 __t4CfV103)) antimirov.slog:130 #f)
  class ReadTask821 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex815;  slog::Index** chrindex816;  slog::Index** catindex817;  slog::Index** altindex818;  slog::Index** catindex819;  slog::Index** chrindex820;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("query");
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("query");
      head_index[0] = readrel823->getIndex(ord822, false);
      outer_rel = db->getRelation("star");
      std::vector<u16> ord824({1, 0});
      slog::Relation* readrel825 = db->getRelation("chr");
      chrindex815 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 0});
      slog::Relation* readrel827 = db->getRelation("chr");
      chrindex816 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("cat");
      catindex817 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 1, 2});
      slog::Relation* readrel831 = db->getRelation("alt");
      altindex818 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 1, 2});
      slog::Relation* readrel833 = db->getRelation("cat");
      catindex819 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("chr");
      chrindex820 = readrel835->getIndex(ord834, false);
  
    }
    ReadTask821(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c74 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c75 = v_constc100f95c1913f9c72fc1f4ef;
  
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
        if (!slog::exists_probe<2,1>(chrindex815, std::array<u64,2>{v_c75, 0})) return;
        slog::join_probe<2,1>(chrindex816, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m836) {
          u64 v_c77 = m836[1];
          if (!slog::exists_probe<3,1>(catindex817, std::array<u64,3>{v_c77, 0, 0})) return;
          slog::join_probe<3,2>(altindex818, std::array<u64,3>{v_c96, v_c77, 0}, [&](const std::array<u64,3>& m837) {
            u64 v_c76 = m837[2];
            slog::join_probe<3,2>(catindex819, std::array<u64,3>{v_c76, v_c77, 0}, [&](const std::array<u64,3>& m838) {
              u64 v_c78 = m838[2];
              slog::join_probe<2,2>(chrindex820, std::array<u64,2>{v_c78, v_c75}, [&](const std::array<u64,2>& m839) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c95}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "delta:star", _fires);
  
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
  // (crule (pre) (scan nullable __t4w6L133 __t8U6m132) (body (join cat (0 1 2) 1 __t8U6m132 r s)) (head (emit $sup14449x45x0x0x0 (0 1 2) __t4w6L133 r s)) antimirov.slog:46 #f)
  class ReadTask841 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex840;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup14449x45x0x0x0");
      std::vector<u16> ord842({0, 1, 2});
      slog::Relation* readrel843 = db->getRelation("$sup14449x45x0x0x0");
      head_index[0] = readrel843->getIndex(ord842, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("cat");
      catindex840 = readrel845->getIndex(ord844, false);
  
    }
    ReadTask841(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c98 = _t[1];
        slog::join_probe<3,1>(catindex840, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m846) {
          u64 v_c2 = m846[1]; u64 v_c7 = m846[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c97, v_c2, v_c7}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask841* _cont = new ReadTask841(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask841(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98) (exists cat (1 2 0) 1 __t4w1Y98) (exists alt (1 2 0) 1 __t4w1Y98) (join chr (1 0) 1 __tconst8qEb95 __t6I9I96) (join cat (1 2 0) 2 __t4w1Y98 __t6I9I96 __t4yUC99) (join alt (1 2 0) 2 __t4w1Y98 __t4yUC99 __t5G2v102) (join star (1 0) 1 __t5G2v102 __t4CfV103)) (head (emit query (0 1) __tconst53SJ104 __t4CfV103)) antimirov.slog:130 #f)
  class ReadTask854 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex847;  slog::Index** catindex848;  slog::Index** altindex849;  slog::Index** chrindex850;  slog::Index** catindex851;  slog::Index** altindex852;  slog::Index** starindex853;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("query");
      std::vector<u16> ord855({0, 1});
      slog::Relation* readrel856 = db->getRelation("query");
      head_index[0] = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 0});
      slog::Relation* readrel858 = db->getRelation("chr");
      chrindex847 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("cat");
      catindex848 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("alt");
      altindex849 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 0});
      slog::Relation* readrel864 = db->getRelation("chr");
      chrindex850 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("cat");
      catindex851 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 2, 0});
      slog::Relation* readrel868 = db->getRelation("alt");
      altindex852 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 0});
      slog::Relation* readrel870 = db->getRelation("star");
      starindex853 = readrel870->getIndex(ord869, false);
  
    }
    ReadTask854(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c74 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c75 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex847, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m871) {
        u64 v_c77 = m871[1];
        if (!slog::exists_probe<3,1>(catindex848, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<3,1>(altindex849, std::array<u64,3>{v_c77, 0, 0})) return;
        slog::join_probe<2,1>(chrindex850, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m872) {
          u64 v_c78 = m872[1];
          slog::join_probe<3,2>(catindex851, std::array<u64,3>{v_c77, v_c78, 0}, [&](const std::array<u64,3>& m873) {
            u64 v_c76 = m873[2];
            slog::join_probe<3,2>(altindex852, std::array<u64,3>{v_c77, v_c76, 0}, [&](const std::array<u64,3>& m874) {
              u64 v_c96 = m874[2];
              slog::join_probe<2,1>(starindex853, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m875) {
                u64 v_c95 = m875[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c95}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask854(db,b));
  // (crule (pre) (scan alt __t2vXQ10 r s) (body (join frag (0) 1 __t2vXQ10)) (head (emit frag (0) s) (emit frag (0) r)) antimirov.slog:107 #f)
  class ReadTask877 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fragindex876;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord878({0});
      slog::Relation* readrel879 = db->getRelation("frag");
      head_index[0] = readrel879->getIndex(ord878, false);
      head_rel[1] = db->getRelation("frag");
      std::vector<u16> ord880({0});
      slog::Relation* readrel881 = db->getRelation("frag");
      head_index[1] = readrel881->getIndex(ord880, false);
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord882({0});
      slog::Relation* readrel883 = db->getRelation("frag");
      fragindex876 = readrel883->getIndex(ord882, false);
  
    }
    ReadTask877(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<1,1>(fragindex876, std::array<u64,1>{v_c99}, [&](const std::array<u64,1>& m884) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:107", "delta:alt", _fires);
  
      if (!_done)
      {
        ReadTask877* _cont = new ReadTask877(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask877(db,b), false);
  // (crule (pre) (scan frag __t6EC3134) (body (join-old chr (0 1) 1 (0 1) __t6EC3134 c)) (head (emit alpha (0) c)) antimirov.slog:109 #f)
  class ReadTask887 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex885;  slog::Index** chrdelta886;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alpha");
      std::vector<u16> ord888({0});
      slog::Relation* readrel889 = db->getRelation("alpha");
      head_index[0] = readrel889->getIndex(ord888, false);
      outer_rel = db->getRelation("frag");
      std::vector<u16> ord890({0, 1});
      slog::Relation* readrel891 = db->getRelation("chr");
      chrindex885 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("chr");
      chrdelta886 = readrel893->getIndex(ord892, true);
  
    }
    ReadTask887(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(chrindex885, chrdelta886, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m894) {
          u64 v_c9 = m894[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:109", "delta:frag", _fires);
  
      if (!_done)
      {
        ReadTask887* _cont = new ReadTask887(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask887(db,b), false);
  // (crule (pre) (scan frag __t4ieC109) (body (join-old star (0 1) 1 (0 1) __t4ieC109 r)) (head (emit frag (0) r)) antimirov.slog:108 #f)
  class ReadTask897 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex895;  slog::Index** stardelta896;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord898({0});
      slog::Relation* readrel899 = db->getRelation("frag");
      head_index[0] = readrel899->getIndex(ord898, false);
      outer_rel = db->getRelation("frag");
      std::vector<u16> ord900({0, 1});
      slog::Relation* readrel901 = db->getRelation("star");
      starindex895 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({0, 1});
      slog::Relation* readrel903 = db->getRelation("star");
      stardelta896 = readrel903->getIndex(ord902, true);
  
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
        u64 v_c101 = _t[0];
        slog::join_probe_old<2,1>(starindex895, stardelta896, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m904) {
          u64 v_c2 = m904[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:108", "delta:frag", _fires);
  
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
  // (crule (pre) (scan alpha c) (body (join-old state (0) 0 (0) r)) (head (mkstruct deriv (1 2 0) __6P3l230 r c)) antimirov.slog:115 #f)
  class ReadTask907 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stateindex905;  slog::Index** statedelta906;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv");
      outer_rel = db->getRelation("alpha");
      std::vector<u16> ord908({0});
      slog::Relation* readrel909 = db->getRelation("state");
      stateindex905 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({0});
      slog::Relation* readrel911 = db->getRelation("state");
      statedelta906 = readrel911->getIndex(ord910, true);
  
    }
    ReadTask907(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_all_old<1>(stateindex905, statedelta906, [&](const std::array<u64,1>& m912) {
          u64 v_c2 = m912[0];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c9}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:115", "delta:alpha", _fires);
  
      if (!_done)
      {
        ReadTask907* _cont = new ReadTask907(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask907(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst7i6460 __t7SBZ53) (join chr (1 0) 1 __tconst77RG62 __t8Axk58)) (head (mkstruct alt (1 2 0) __t8pHj64 __t8Axk58 __t7SBZ53) (mkstruct cat (1 2 0) __t9z7256 __t7SBZ53 __t7SBZ53)) antimirov.slog:126 #f)
  class ReadTask915 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** chrindex913;  slog::Index** chrindex914;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("alt");
      std::vector<u16> ord916({1, 2, 0});
      slog::Relation* readrel917 = db->getRelation("alt");
      head_index[0] = readrel917->getIndex(ord916, false);
      head_rel[1] = db->getRelation("cat");
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("cat");
      head_index[1] = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 0});
      slog::Relation* readrel921 = db->getRelation("chr");
      chrindex913 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({1, 0});
      slog::Relation* readrel923 = db->getRelation("chr");
      chrindex914 = readrel923->getIndex(ord922, false);
  
    }
    ReadTask915(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c13 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c14 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex913, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m924) {
        u64 v_c15 = m924[1];
        slog::join_probe<2,1>(chrindex914, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m925) {
          u64 v_c16 = m925[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c15, v_c15}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask915(db,b));
  // (crule (pre) (scan nullable __t5WkW89 s) (body (exists $sup14449x45x0x0x0 (2 0 1) 1 s) (exists cat (2 0 1) 1 s) (join nullable_ans (0 1) 1 __t5WkW89 __v1) (join $sup14449x45x0x0x0 (2 0 1) 1 s __t7U0R87 r) (exists nullable (1 0) 1 r) (join cat (1 2 0) 2 r s __t3mF986) (join nullable (0 1) 2 __t7U0R87 __t3mF986) (join nullable (1 0) 1 r __t7OBQ88) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask935 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x45x0x0x0index926;  slog::Index** catindex927;  slog::Index** nullable_ansindex928;  slog::Index** $sup14449x45x0x0x0index929;  slog::Index** nullableindex930;  slog::Index** catindex931;  slog::Index** nullableindex932;  slog::Index** nullableindex933;  slog::Index** nullable_ansindex934;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord936({2, 0, 1});
      slog::Relation* readrel937 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index926 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({2, 0, 1});
      slog::Relation* readrel939 = db->getRelation("cat");
      catindex927 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({0, 1});
      slog::Relation* readrel941 = db->getRelation("nullable_ans");
      nullable_ansindex928 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({2, 0, 1});
      slog::Relation* readrel943 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index929 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 0});
      slog::Relation* readrel945 = db->getRelation("nullable");
      nullableindex930 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 2, 0});
      slog::Relation* readrel947 = db->getRelation("cat");
      catindex931 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("nullable");
      nullableindex932 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 0});
      slog::Relation* readrel951 = db->getRelation("nullable");
      nullableindex933 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({0, 1});
      slog::Relation* readrel953 = db->getRelation("nullable_ans");
      nullable_ansindex934 = readrel953->getIndex(ord952, false);
  
    }
    ReadTask935(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[1];
        if (!slog::exists_probe<3,1>($sup14449x45x0x0x0index926, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(catindex927, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex928, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m954) {
          u64 v_c27 = m954[1];
          slog::join_probe<3,1>($sup14449x45x0x0x0index929, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m955) {
            u64 v_c59 = m955[1]; u64 v_c2 = m955[2];
            if (!slog::exists_probe<2,1>(nullableindex930, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(catindex931, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m956) {
              u64 v_c60 = m956[2];
              slog::join_probe<2,2>(nullableindex932, std::array<u64,2>{v_c59, v_c60}, [&](const std::array<u64,2>& m957) {
                slog::join_probe<2,1>(nullableindex933, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m958) {
                  u64 v_c61 = m958[1];
                  slog::join_probe<2,1>(nullable_ansindex934, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m959) {
                    u64 v_c6 = m959[1];
                    u64 v_c63 = _prim__0002a(db, v_c6, v_c27);
                    if (v_c63 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c59});
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
        ReadTask935* _cont = new ReadTask935(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask935(db,b), false);
}

