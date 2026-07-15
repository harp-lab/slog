
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const09c9e756387a87c9bbdc4c0e;
extern u64 v_const1277a2cd065b41d0baf310a1;
extern u64 v_const14e32b34cd055e89c9cc695a;
extern u64 v_const1c39633808c54038b6212e46;
extern u64 v_const40480dc150931aa1b1d04926;
extern u64 v_const45aa4f80f636b15f8d75cce8;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const521847e7e2e4552b87a9916b;
extern u64 v_const580dc10e980f4c3a7a1f2359;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const75f539c022ff58cca2ea854c;
extern u64 v_consta68730bc42ed463b202c634e;
extern u64 v_consta9a6d512c3f845483b03fd37;
extern u64 v_constb3bd32486de3ee02878db405;
extern u64 v_constb5c7d53c1c5cb8517644318d;
extern u64 v_constbb1534a1c906f3ee1939a91e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_consted0583037dc2e002b6af2ca9;
extern u64 v_constef39e22752c73795a9d935a5;
extern u64 v_constfc5bdca6f3fa7cfdc4f78dd7;


void slog_rules_c93cecb0f05bb5361(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c)) (seeded) (body (join check (1 3 2 0) 2 __tconst18Er103 __tconst0NaN97 __t3ZLW102 __t7oct104) (exists iv (1 0) 1 __tconst503n100) (join ic (1 0) 1 __tconst2WqR98 __t3YLv99) (join lge (0 2 1) 2 __t3ZLW102 __t3YLv99 __t8QUK101) (join iv (0 1) 2 __t8QUK101 __tconst503n100)) (head (emit stmt (1 0) __t7oct104 __tconst48RK105)) demo.slog:19 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** checkindex0;  slog::Index** ivindex1;  slog::Index** icindex2;  slog::Index** lgeindex3;  slog::Index** ivindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("stmt");
      head_index[0] = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 3, 2, 0});
      slog::Relation* readrel9 = db->getRelation("check");
      checkindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("iv");
      ivindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("ic");
      icindex2 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({0, 2, 1});
      slog::Relation* readrel15 = db->getRelation("lge");
      lgeindex3 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("iv");
      ivindex4 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c2 = v_const45aa4f80f636b15f8d75cce8;
      u64 v_c3 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(checkindex0, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m18) {
        u64 v_c5 = m18[2]; u64 v_c6 = m18[3];
        if (!slog::exists_probe<2,1>(ivindex1, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(icindex2, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m19) {
          u64 v_c7 = m19[1];
          slog::join_probe<3,2>(lgeindex3, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m20) {
            u64 v_c8 = m20[2];
            slog::join_probe<2,2>(ivindex4, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m21) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c0}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask5(db,b));
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b)) (seeded) (body (join ic (1 0) 1 __tconst6NWz71 __t5vc872) (join iv (1 0) 1 __tconst58dx73 __t3Imx74)) (head (mkstruct llt (2 1 0) __t8MBI75 __t5vc872 __t3Imx74)) demo.slog:16 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex22;  slog::Index** ivindex23;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord25({2, 1, 0});
      slog::Relation* readrel26 = db->getRelation("llt");
      head_index[0] = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 0});
      slog::Relation* readrel28 = db->getRelation("ic");
      icindex22 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("iv");
      ivindex23 = readrel30->getIndex(ord29, false);
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c10 = v_constef39e22752c73795a9d935a5;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_const75f539c022ff58cca2ea854c;
      u64 v_c13 = v_const521847e7e2e4552b87a9916b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex22, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m31) {
        u64 v_c14 = m31[1];
        slog::join_probe<2,1>(ivindex23, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m32) {
          u64 v_c15 = m32[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c15}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask24(db,b));
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8)) (seeded) (body (join ic (1 0) 1 __tconst2WqR98 __t3YLv99) (join iv (1 0) 1 __tconst503n100 __t8QUK101)) (head (mkstruct lge (2 1 0) __t3ZLW102 __t3YLv99 __t8QUK101)) demo.slog:19 #f)
  class ReadTask35 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex33;  slog::Index** ivindex34;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lge");
      std::vector<u16> ord36({2, 1, 0});
      slog::Relation* readrel37 = db->getRelation("lge");
      head_index[0] = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("ic");
      icindex33 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("iv");
      ivindex34 = readrel41->getIndex(ord40, false);
  
    }
    ReadTask35(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c3 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const45aa4f80f636b15f8d75cce8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex33, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m42) {
        u64 v_c7 = m42[1];
        slog::join_probe<2,1>(ivindex34, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m43) {
          u64 v_c8 = m43[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c8}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask35(db,b));
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c)) (scan llt __t8MBI75 __t3Imx74 __t5vc872) (body (join ic (0 1) 2 __t5vc872 __tconst6NWz71) (join iv (0 1) 2 __t3Imx74 __tconst58dx73)) (head (mkstruct branch (2 3 1 0) __t4vxt76 __tconst4csV70 __tconst8HQA69 __t8MBI75)) demo.slog:16 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex44;  slog::Index** ivindex45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("branch");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("ic");
      icindex44 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("iv");
      ivindex45 = readrel50->getIndex(ord49, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c12 = v_const75f539c022ff58cca2ea854c;
      u64 v_c13 = v_const521847e7e2e4552b87a9916b;
      u64 v_c10 = v_constef39e22752c73795a9d935a5;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe<2,2>(icindex44, std::array<u64,2>{v_c14, v_c11}, [&](const std::array<u64,2>& m51) {
          slog::join_probe<2,2>(ivindex45, std::array<u64,2>{v_c15, v_c10}, [&](const std::array<u64,2>& m52) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c13, v_c16}, std::array<u16,4>{2, 3, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask46* _cont = new ReadTask46(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask46(db,b), false);
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1)) (scan lle __t2oqq20 __t52Ib19 __t12js14) (body (join ic (0 1) 2 __t12js14 __tconst5qV413) (join ic (1 0) 1 __tconst4wtI17 __t57K216) (join lmul (0 1 2) 2 __t52Ib19 __t57K216 dup4Wcs167) (eq __t57K216 dup4Wcs167)) (head (mkstruct check (1 3 2 0) __t9e5t22 __tconst7EoZ21 __tconst69di12 __t2oqq20)) demo.slog:29 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex53;  slog::Index** icindex54;  slog::Index** lmulindex55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      outer_rel = db->getRelation("lle");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("ic");
      icindex53 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0});
      slog::Relation* readrel60 = db->getRelation("ic");
      icindex54 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1, 2});
      slog::Relation* readrel62 = db->getRelation("lmul");
      lmulindex55 = readrel62->getIndex(ord61, false);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c18 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c19 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c20 = v_const4a44dc15364204a80fe80e90;
      u64 v_c21 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        slog::join_probe<2,2>(icindex53, std::array<u64,2>{v_c24, v_c20}, [&](const std::array<u64,2>& m63) {
          slog::join_probe<2,1>(icindex54, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m64) {
            u64 v_c25 = m64[1];
            slog::join_probe<3,2>(lmulindex55, std::array<u64,3>{v_c23, v_c25, 0}, [&](const std::array<u64,3>& m65) {
              u64 v_c26 = m65[2];
              if (v_c25 != v_c26) return;
              ++_fires;
              slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c18, v_c19, v_c22}, std::array<u16,4>{1, 3, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "delta:lle", _fires);
  
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
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a)) (probe ic (1 0) 1 __tconst7YJt61 __t0WtQ62) (body (join ic (1 0) 1 __tconst35f163 __t1cQ264)) (head (mkstruct lgt (2 1 0) __t2PDL65 __t0WtQ62 __t1cQ264)) demo.slog:30 #f)
  class ReadTask67 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex66;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lgt");
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("ic");
      driver_index = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ic");
      icindex66 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c28 = v_constb3bd32486de3ee02878db405;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c31 = v_const14e32b34cd055e89c9cc695a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m72) {
        u64 v_c32 = m72[1];
        if (buckethash(v_c32) != bucket) return;
        slog::join_probe<2,1>(icindex66, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m73) {
          u64 v_c33 = m73[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c32, v_c33}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask67* _cont = new ReadTask67(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask67(db,b), false);
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1)) (probe check (1 3 0 2) 2 __tconst7EoZ21 __tconst69di12 __t9e5t22 __t2oqq20) (body (exists ic (1 0) 1 __tconst4wtI17) (join ic (1 0) 1 __tconst5qV413 __t12js14) (join lle (0 2 1) 2 __t2oqq20 __t12js14 __t52Ib19) (join ic (1 0) 1 __tconst4wtI17 __t57K216) (join lmul (0 1 2) 2 __t52Ib19 __t57K216 dup2J4O169) (eq __t57K216 dup2J4O169)) (head (emit stmt (1 0) __t9e5t22 __tconst3hGT23)) demo.slog:29 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** icindex74;  slog::Index** icindex75;  slog::Index** lleindex76;  slog::Index** icindex77;  slog::Index** lmulindex78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("stmt");
      head_index[0] = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 3, 0, 2});
      slog::Relation* readrel83 = db->getRelation("check");
      driver_index = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("ic");
      icindex74 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 0});
      slog::Relation* readrel87 = db->getRelation("ic");
      icindex75 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({0, 2, 1});
      slog::Relation* readrel89 = db->getRelation("lle");
      lleindex76 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ic");
      icindex77 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("lmul");
      lmulindex78 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c18 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c19 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c20 = v_const4a44dc15364204a80fe80e90;
      u64 v_c21 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c18, v_c19, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m94) {
        u64 v_c34 = m94[2];
        u64 v_c22 = m94[3];
        if (buckethash(v_c34) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex74, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<2,1>(icindex75, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m95) {
          u64 v_c24 = m95[1];
          slog::join_probe<3,2>(lleindex76, std::array<u64,3>{v_c22, v_c24, 0}, [&](const std::array<u64,3>& m96) {
            u64 v_c23 = m96[2];
            slog::join_probe<2,1>(icindex77, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m97) {
              u64 v_c25 = m97[1];
              slog::join_probe<3,2>(lmulindex78, std::array<u64,3>{v_c23, v_c25, 0}, [&](const std::array<u64,3>& m98) {
                u64 v_c35 = m98[2];
                if (v_c25 != v_c35) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c17}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "delta:check", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c)) (seeded) (body (join ic (1 0) 1 __tconst2n0O25 __t3kVu26) (exists lne (2 1 0) 1 __t3kVu26) (join iv (1 0) 1 __tconst1PP127 __t8tDh28) (join lne (2 1 0) 2 __t3kVu26 __t8tDh28 __t0Ksc29)) (head (mkstruct check (1 3 2 0) __t4Ts131 __tconst6lL530 __tconst4s9G24 __t0Ksc29)) demo.slog:24 #f)
  class ReadTask103 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex99;  slog::Index** lneindex100;  slog::Index** ivindex101;  slog::Index** lneindex102;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      std::vector<u16> ord104({1, 3, 2, 0});
      slog::Relation* readrel105 = db->getRelation("check");
      head_index[0] = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("ic");
      icindex99 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({2, 1, 0});
      slog::Relation* readrel109 = db->getRelation("lne");
      lneindex100 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("iv");
      ivindex101 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({2, 1, 0});
      slog::Relation* readrel113 = db->getRelation("lne");
      lneindex102 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const1c39633808c54038b6212e46;
      u64 v_c37 = v_consta68730bc42ed463b202c634e;
      u64 v_c38 = v_const580dc10e980f4c3a7a1f2359;
      u64 v_c39 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c40 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex99, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m114) {
        u64 v_c41 = m114[1];
        if (!slog::exists_probe<3,1>(lneindex100, std::array<u64,3>{v_c41, 0, 0})) return;
        slog::join_probe<2,1>(ivindex101, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m115) {
          u64 v_c42 = m115[1];
          slog::join_probe<3,2>(lneindex102, std::array<u64,3>{v_c41, v_c42, 0}, [&](const std::array<u64,3>& m116) {
            u64 v_c43 = m116[2];
            ++_fires;
            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c37, v_c38, v_c43}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask103(db,b));
  // (crule (pre (let __tconst6xZt45 const521847e7e2e4552b87a9916b) (let __tconst1rC043 const09c9e756387a87c9bbdc4c0e) (let __tconst391g40 const40480dc150931aa1b1d04926) (let __tconst4bVo41 constef39e22752c73795a9d935a5)) (seeded) (body (join asgn (1 3 2 0) 2 __tconst1rC043 __tconst391g40 __t1fAr42 __t0yDQ44) (join iv (0 1) 2 __t1fAr42 __tconst4bVo41)) (head (emit stmt (1 0) __t0yDQ44 __tconst6xZt45)) demo.slog:18 #f)
  class ReadTask119 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** asgnindex117;  slog::Index** ivindex118;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("stmt");
      head_index[0] = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 3, 2, 0});
      slog::Relation* readrel123 = db->getRelation("asgn");
      asgnindex117 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("iv");
      ivindex118 = readrel125->getIndex(ord124, false);
  
    }
    ReadTask119(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const521847e7e2e4552b87a9916b;
      u64 v_c45 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c46 = v_const40480dc150931aa1b1d04926;
      u64 v_c47 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(asgnindex117, std::array<u64,4>{v_c45, v_c46, 0, 0}, [&](const std::array<u64,4>& m126) {
        u64 v_c48 = m126[2]; u64 v_c49 = m126[3];
        slog::join_probe<2,2>(ivindex118, std::array<u64,2>{v_c48, v_c47}, [&](const std::array<u64,2>& m127) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c44}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask119(db,b));
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst69di12 constb5c7d53c1c5cb8517644318d)) (seeded) (body (join ic (1 0) 1 __tconst5qV413 __t12js14) (join ic (1 0) 1 __tconst4wtI17 __t57K216)) (head (mkstruct lmul (1 2 0) __t52Ib19 __t57K216 __t57K216)) demo.slog:29 #f)
  class ReadTask130 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex128;  slog::Index** icindex129;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lmul");
      std::vector<u16> ord131({1, 2, 0});
      slog::Relation* readrel132 = db->getRelation("lmul");
      head_index[0] = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("ic");
      icindex128 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 0});
      slog::Relation* readrel136 = db->getRelation("ic");
      icindex129 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask130(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c18 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c21 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4a44dc15364204a80fe80e90;
      u64 v_c19 = v_constb5c7d53c1c5cb8517644318d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex128, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m137) {
        u64 v_c24 = m137[1];
        slog::join_probe<2,1>(icindex129, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m138) {
          u64 v_c25 = m138[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c25, v_c25}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask130(db,b));
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c)) (scan lge __t3ZLW102 __t8QUK101 __t3YLv99) (body (join ic (0 1) 2 __t3YLv99 __tconst2WqR98) (join iv (0 1) 2 __t8QUK101 __tconst503n100)) (head (mkstruct check (1 3 2 0) __t7oct104 __tconst18Er103 __tconst0NaN97 __t3ZLW102)) demo.slog:19 #f)
  class ReadTask141 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex139;  slog::Index** ivindex140;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      outer_rel = db->getRelation("lge");
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("ic");
      icindex139 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("iv");
      ivindex140 = readrel145->getIndex(ord144, false);
  
    }
    ReadTask141(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c2 = v_const45aa4f80f636b15f8d75cce8;
      u64 v_c3 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<2,2>(icindex139, std::array<u64,2>{v_c7, v_c4}, [&](const std::array<u64,2>& m146) {
          slog::join_probe<2,2>(ivindex140, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m147) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c5}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "delta:lge", _fires);
  
      if (!_done)
      {
        ReadTask141* _cont = new ReadTask141(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask141(db,b), false);
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5) (let __tconst3onN110 const40480dc150931aa1b1d04926)) (probe iv (1 0) 1 __tconst5wBX111 __t24pM112) (body (join ic (1 0) 1 __tconst9rCc113 __t6I2Z114)) (head (mkstruct lsub (2 1 0) __t8CTm115 __t24pM112 __t6I2Z114)) demo.slog:17 #f)
  class ReadTask149 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex148;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lsub");
      std::vector<u16> ord150({1, 0});
      slog::Relation* readrel151 = db->getRelation("iv");
      driver_index = readrel151->getIndex(ord150, true);
      std::vector<u16> ord152({1, 0});
      slog::Relation* readrel153 = db->getRelation("ic");
      icindex148 = readrel153->getIndex(ord152, false);
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_const75f539c022ff58cca2ea854c;
      u64 v_c51 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c53 = v_constef39e22752c73795a9d935a5;
      u64 v_c54 = v_const40480dc150931aa1b1d04926;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c53, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m154) {
        u64 v_c55 = m154[1];
        if (buckethash(v_c55) != bucket) return;
        slog::join_probe<2,1>(icindex148, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m155) {
          u64 v_c56 = m155[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c55, v_c56}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "delta:iv", _fires);
  
      if (!_done)
      {
        ReadTask149* _cont = new ReadTask149(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask149(db,b), false);
  // (crule (pre) (scan stmt L __t4sDs128) (body (join-old asgn (0 1 2 3) 1 (0 1 2 3) __t4sDs128 X E N)) (head (emit-temp temp2RZM171 E X) (mkstruct iv (1 0) __t5v3R126 X)) verify.slog:50 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** asgnindex156;  slog::Index** asgndelta157;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2RZM171");
      head_rel[1] = db->getRelation("iv");
      outer_rel = db->getRelation("stmt");
      std::vector<u16> ord159({0, 1, 2, 3});
      slog::Relation* readrel160 = db->getRelation("asgn");
      asgnindex156 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0, 1, 2, 3});
      slog::Relation* readrel162 = db->getRelation("asgn");
      asgndelta157 = readrel162->getIndex(ord161, true);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        slog::join_probe_old<4,1>(asgnindex156, asgndelta157, std::array<u64,4>{v_c58, 0, 0, 0}, [&](const std::array<u64,4>& m163) {
          u64 v_c59 = m163[1]; u64 v_c60 = m163[2]; u64 v_c61 = m163[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c60, v_c59});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c59}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("verify.slog:50", "delta:stmt", _fires);
  
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
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b)) (once) (body) (head (mkstruct iv (1 0) __t3Imx74 __tconst58dx73) (mkstruct ic (1 0) __t5vc872 __tconst6NWz71)) demo.slog:16 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("iv");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c10 = v_constef39e22752c73795a9d935a5;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_const75f539c022ff58cca2ea854c;
      u64 v_c13 = v_const521847e7e2e4552b87a9916b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c10}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:16", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), true);
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359)) (seeded) (body (join ic (1 0) 1 __tconst2n0O25 __t3kVu26) (join iv (1 0) 1 __tconst1PP127 __t8tDh28)) (head (mkstruct lne (2 1 0) __t0Ksc29 __t3kVu26 __t8tDh28)) demo.slog:24 #f)
  class ReadTask167 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex165;  slog::Index** ivindex166;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lne");
      std::vector<u16> ord168({2, 1, 0});
      slog::Relation* readrel169 = db->getRelation("lne");
      head_index[0] = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 0});
      slog::Relation* readrel171 = db->getRelation("ic");
      icindex165 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 0});
      slog::Relation* readrel173 = db->getRelation("iv");
      ivindex166 = readrel173->getIndex(ord172, false);
  
    }
    ReadTask167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const1c39633808c54038b6212e46;
      u64 v_c37 = v_consta68730bc42ed463b202c634e;
      u64 v_c39 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c40 = v_const5feceb66ffc86f38d952786c;
      u64 v_c38 = v_const580dc10e980f4c3a7a1f2359;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex165, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m174) {
        u64 v_c41 = m174[1];
        slog::join_probe<2,1>(ivindex166, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m175) {
          u64 v_c42 = m175[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c42}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask167(db,b));
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1) (let __tconst5qV413 const4a44dc15364204a80fe80e90)) (scan lmul __t52Ib19 __t57K216 dup7Ol5165) (body (eq __t57K216 dup7Ol5165) (join ic (0 1) 2 __t57K216 __tconst4wtI17) (join ic (1 0) 1 __tconst5qV413 __t12js14)) (head (mkstruct lle (2 1 0) __t2oqq20 __t12js14 __t52Ib19)) demo.slog:29 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex176;  slog::Index** icindex177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lle");
      outer_rel = db->getRelation("lmul");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("ic");
      icindex176 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("ic");
      icindex177 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c18 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c19 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c21 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c62 = _t[2];
        if (v_c25 != v_c62) return;
        slog::join_probe<2,2>(icindex176, std::array<u64,2>{v_c25, v_c21}, [&](const std::array<u64,2>& m183) {
          slog::join_probe<2,1>(icindex177, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m184) {
            u64 v_c24 = m184[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c23}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "delta:lmul", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), false);
  // (crule (pre) (scan temp2RZM171 E X) (body (join iv (1 0) 1 X __t5v3R126)) (head (emit-temp temp3XuN172 E X __t5v3R126) (mkstruct leq (1 2 0) __t9w3f127 __t5v3R126 E)) verify.slog:50 #f)
  class ReadTask186 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ivindex185;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3XuN172");
      head_rel[1] = db->getRelation("leq");
      outer_rel = db->getRelation("temp2RZM171");
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("iv");
      ivindex185 = readrel188->getIndex(ord187, false);
  
    }
    ReadTask186(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        slog::join_probe<2,1>(ivindex185, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m189) {
          u64 v_c63 = m189[1];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c60, v_c59, v_c63});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c63, v_c60}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("verify.slog:50", "delta:temp2RZM171", _fires);
  
      if (!_done)
      {
        ReadTask186* _cont = new ReadTask186(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask186(db,b), false);
  // (crule (pre (let __tconst6xZt45 const521847e7e2e4552b87a9916b) (let __tconst1rC043 const09c9e756387a87c9bbdc4c0e) (let __tconst4bVo41 constef39e22752c73795a9d935a5) (let __tconst391g40 const40480dc150931aa1b1d04926)) (probe iv (1 0) 1 __tconst4bVo41 __t1fAr42) (body) (head (mkstruct asgn (1 3 2 0) __t0yDQ44 __tconst1rC043 __tconst391g40 __t1fAr42)) demo.slog:18 #f)
  class ReadTask190 : public slog::Task
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
      head_rel[0] = db->getRelation("asgn");
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("iv");
      driver_index = readrel192->getIndex(ord191, true);
  
    }
    ReadTask190(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const521847e7e2e4552b87a9916b;
      u64 v_c45 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c47 = v_constef39e22752c73795a9d935a5;
      u64 v_c46 = v_const40480dc150931aa1b1d04926;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c47, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m193) {
        u64 v_c48 = m193[1];
        if (buckethash(v_c48) != bucket) return;
        ++_fires;
        slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c45, v_c46, v_c48}, std::array<u16,4>{1, 3, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:18", "delta:iv", _fires);
  
      if (!_done)
      {
        ReadTask190* _cont = new ReadTask190(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask190(db,b), false);
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c)) (probe branch (2 3 0 1) 2 __tconst4csV70 __tconst8HQA69 __t4vxt76 __t8MBI75) (body (exists iv (1 0) 1 __tconst58dx73) (join ic (1 0) 1 __tconst6NWz71 __t5vc872) (join llt (0 2 1) 2 __t8MBI75 __t5vc872 __t3Imx74) (join iv (0 1) 2 __t3Imx74 __tconst58dx73)) (head (emit stmt (1 0) __t4vxt76 __tconst7jvJ77)) demo.slog:16 #f)
  class ReadTask198 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex194;  slog::Index** icindex195;  slog::Index** lltindex196;  slog::Index** ivindex197;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord199({1, 0});
      slog::Relation* readrel200 = db->getRelation("stmt");
      head_index[0] = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({2, 3, 0, 1});
      slog::Relation* readrel202 = db->getRelation("branch");
      driver_index = readrel202->getIndex(ord201, true);
      std::vector<u16> ord203({1, 0});
      slog::Relation* readrel204 = db->getRelation("iv");
      ivindex194 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 0});
      slog::Relation* readrel206 = db->getRelation("ic");
      icindex195 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 2, 1});
      slog::Relation* readrel208 = db->getRelation("llt");
      lltindex196 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("iv");
      ivindex197 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask198(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c12 = v_const75f539c022ff58cca2ea854c;
      u64 v_c13 = v_const521847e7e2e4552b87a9916b;
      u64 v_c10 = v_constef39e22752c73795a9d935a5;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c12, v_c13, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m211) {
        u64 v_c64 = m211[2];
        u64 v_c16 = m211[3];
        if (buckethash(v_c64) != bucket) return;
        if (!slog::exists_probe<2,1>(ivindex194, std::array<u64,2>{v_c10, 0})) return;
        slog::join_probe<2,1>(icindex195, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m212) {
          u64 v_c14 = m212[1];
          slog::join_probe<3,2>(lltindex196, std::array<u64,3>{v_c16, v_c14, 0}, [&](const std::array<u64,3>& m213) {
            u64 v_c15 = m213[2];
            slog::join_probe<2,2>(ivindex197, std::array<u64,2>{v_c15, v_c10}, [&](const std::array<u64,2>& m214) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c64, v_c9}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "delta:branch", _fires);
  
      if (!_done)
      {
        ReadTask198* _cont = new ReadTask198(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask198(db,b), false);
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst69di12 constb5c7d53c1c5cb8517644318d)) (probe ic (1 0) 1 __tconst5qV413 __t12js14) (body (join ic (1 0) 1 __tconst4wtI17 __t57K216)) (head (mkstruct lmul (1 2 0) __t52Ib19 __t57K216 __t57K216)) demo.slog:29 #f)
  class ReadTask216 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex215;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lmul");
      std::vector<u16> ord217({1, 0});
      slog::Relation* readrel218 = db->getRelation("ic");
      driver_index = readrel218->getIndex(ord217, true);
      std::vector<u16> ord219({1, 0});
      slog::Relation* readrel220 = db->getRelation("ic");
      icindex215 = readrel220->getIndex(ord219, false);
  
    }
    ReadTask216(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c18 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c21 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4a44dc15364204a80fe80e90;
      u64 v_c19 = v_constb5c7d53c1c5cb8517644318d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c20, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m221) {
        u64 v_c24 = m221[1];
        if (buckethash(v_c24) != bucket) return;
        slog::join_probe<2,1>(icindex215, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m222) {
          u64 v_c25 = m222[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c25}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask216* _cont = new ReadTask216(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask216(db,b), false);
}

