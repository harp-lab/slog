
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
extern u64 v_consta221beeaebe583607e193be7;
extern u64 v_consta68730bc42ed463b202c634e;
extern u64 v_consta9a6d512c3f845483b03fd37;
extern u64 v_constab76c7d069d6f33dc950fb33;
extern u64 v_constb3bd32486de3ee02878db405;
extern u64 v_constb5c7d53c1c5cb8517644318d;
extern u64 v_constbb1534a1c906f3ee1939a91e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste433800a79f2d3be41014577;
extern u64 v_consteb8bf0d80db323992f6b634a;
extern u64 v_consted0583037dc2e002b6af2ca9;
extern u64 v_constef39e22752c73795a9d935a5;
extern u64 v_constfc5bdca6f3fa7cfdc4f78dd7;


void slog_rules_c0691dac12232a1eb(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8)) (once) (body) (head (mkstruct iv (1 0) __t8QUK101 __tconst503n100) (mkstruct ic (1 0) __t3YLv99 __tconst2WqR98)) demo.slog:19 #f)
  class ReadTask0 : public slog::Task
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
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c2 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const45aa4f80f636b15f8d75cce8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:19", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b)) (probe ic (1 0) 1 __tconst6NWz71 __t5vc872) (body (join iv (1 0) 1 __tconst58dx73 __t3Imx74)) (head (mkstruct llt (2 1 0) __t8MBI75 __t5vc872 __t3Imx74)) demo.slog:16 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord3({1, 0});
      slog::Relation* readrel4 = db->getRelation("ic");
      driver_index = readrel4->getIndex(ord3, true);
      std::vector<u16> ord5({1, 0});
      slog::Relation* readrel6 = db->getRelation("iv");
      ivindex1 = readrel6->getIndex(ord5, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c6 = v_constef39e22752c73795a9d935a5;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
      u64 v_c8 = v_const75f539c022ff58cca2ea854c;
      u64 v_c9 = v_const521847e7e2e4552b87a9916b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c7, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m7) {
        u64 v_c10 = m7[1];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<2,1>(ivindex1, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m8) {
          u64 v_c11 = m8[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre (let __tconst85EC156 conste433800a79f2d3be41014577) (let __tconst69x890 const580dc10e980f4c3a7a1f2359)) (probe _enum (1 0) 1 __tconst85EC156 __t9EdQ89) (body) (head (emit stmt (1 0) __t9EdQ89 __tconst69x890)) demo.slog:25 #f)
  class ReadTask9 : public slog::Task
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
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("stmt");
      head_index[0] = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("_enum");
      driver_index = readrel13->getIndex(ord12, true);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_conste433800a79f2d3be41014577;
      u64 v_c13 = v_const580dc10e980f4c3a7a1f2359;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c12, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m14) {
        u64 v_c14 = m14[1];
        if (buckethash(v_c14) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c13}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:25", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), true);
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c)) (seeded) (body (join check (1 3 2 0) 2 __tconst6lL530 __tconst4s9G24 __t0Ksc29 __t4Ts131) (exists iv (1 0) 1 __tconst1PP127) (join ic (1 0) 1 __tconst2n0O25 __t3kVu26) (join lne (0 2 1) 2 __t0Ksc29 __t3kVu26 __t8tDh28) (join iv (0 1) 2 __t8tDh28 __tconst1PP127)) (head (emit stmt (1 0) __t4Ts131 __tconst9B3032)) demo.slog:24 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** checkindex15;  slog::Index** ivindex16;  slog::Index** icindex17;  slog::Index** lneindex18;  slog::Index** ivindex19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("stmt");
      head_index[0] = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 3, 2, 0});
      slog::Relation* readrel24 = db->getRelation("check");
      checkindex15 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("iv");
      ivindex16 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 0});
      slog::Relation* readrel28 = db->getRelation("ic");
      icindex17 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 2, 1});
      slog::Relation* readrel30 = db->getRelation("lne");
      lneindex18 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("iv");
      ivindex19 = readrel32->getIndex(ord31, false);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const1c39633808c54038b6212e46;
      u64 v_c16 = v_consta68730bc42ed463b202c634e;
      u64 v_c17 = v_const580dc10e980f4c3a7a1f2359;
      u64 v_c18 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(checkindex15, std::array<u64,4>{v_c16, v_c17, 0, 0}, [&](const std::array<u64,4>& m33) {
        u64 v_c20 = m33[2]; u64 v_c21 = m33[3];
        if (!slog::exists_probe<2,1>(ivindex16, std::array<u64,2>{v_c18, 0})) return;
        slog::join_probe<2,1>(icindex17, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m34) {
          u64 v_c22 = m34[1];
          slog::join_probe<3,2>(lneindex18, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m35) {
            u64 v_c23 = m35[2];
            slog::join_probe<2,2>(ivindex19, std::array<u64,2>{v_c23, v_c18}, [&](const std::array<u64,2>& m36) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c15}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask20(db,b));
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst3onN110 const40480dc150931aa1b1d04926) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5)) (seeded) (body (join asgn (1 3 2 0) 2 __tconst3kSp116 __tconst3onN110 __t8CTm115 __t4NUM117) (exists ic (1 0) 1 __tconst9rCc113) (join iv (1 0) 1 __tconst5wBX111 __t24pM112) (join lsub (0 2 1) 2 __t8CTm115 __t24pM112 __t6I2Z114) (join ic (0 1) 2 __t6I2Z114 __tconst9rCc113)) (head (emit stmt (1 0) __t4NUM117 __tconst6z4r118)) demo.slog:17 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** asgnindex37;  slog::Index** icindex38;  slog::Index** ivindex39;  slog::Index** lsubindex40;  slog::Index** icindex41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("stmt");
      head_index[0] = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 3, 2, 0});
      slog::Relation* readrel46 = db->getRelation("asgn");
      asgnindex37 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("ic");
      icindex38 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("iv");
      ivindex39 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 2, 1});
      slog::Relation* readrel52 = db->getRelation("lsub");
      lsubindex40 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("ic");
      icindex41 = readrel54->getIndex(ord53, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(asgnindex37, std::array<u64,4>{v_c25, v_c26, 0, 0}, [&](const std::array<u64,4>& m55) {
        u64 v_c29 = m55[2]; u64 v_c30 = m55[3];
        if (!slog::exists_probe<2,1>(icindex38, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe<2,1>(ivindex39, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m56) {
          u64 v_c31 = m56[1];
          slog::join_probe<3,2>(lsubindex40, std::array<u64,3>{v_c29, v_c31, 0}, [&](const std::array<u64,3>& m57) {
            u64 v_c32 = m57[2];
            slog::join_probe<2,2>(icindex41, std::array<u64,2>{v_c32, v_c27}, [&](const std::array<u64,2>& m58) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c24}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask42(db,b));
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c)) (probe check (1 3 0 2) 2 __tconst6lL530 __tconst4s9G24 __t4Ts131 __t0Ksc29) (body (exists iv (1 0) 1 __tconst1PP127) (join ic (1 0) 1 __tconst2n0O25 __t3kVu26) (join lne (0 2 1) 2 __t0Ksc29 __t3kVu26 __t8tDh28) (join iv (0 1) 2 __t8tDh28 __tconst1PP127)) (head (emit stmt (1 0) __t4Ts131 __tconst9B3032)) demo.slog:24 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex59;  slog::Index** icindex60;  slog::Index** lneindex61;  slog::Index** ivindex62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord64({1, 0});
      slog::Relation* readrel65 = db->getRelation("stmt");
      head_index[0] = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 3, 0, 2});
      slog::Relation* readrel67 = db->getRelation("check");
      driver_index = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("iv");
      ivindex59 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ic");
      icindex60 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 2, 1});
      slog::Relation* readrel73 = db->getRelation("lne");
      lneindex61 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0, 1});
      slog::Relation* readrel75 = db->getRelation("iv");
      ivindex62 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const1c39633808c54038b6212e46;
      u64 v_c16 = v_consta68730bc42ed463b202c634e;
      u64 v_c17 = v_const580dc10e980f4c3a7a1f2359;
      u64 v_c18 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c16, v_c17, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m76) {
        u64 v_c21 = m76[2];
        u64 v_c20 = m76[3];
        if (buckethash(v_c21) != bucket) return;
        if (!slog::exists_probe<2,1>(ivindex59, std::array<u64,2>{v_c18, 0})) return;
        slog::join_probe<2,1>(icindex60, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m77) {
          u64 v_c22 = m77[1];
          slog::join_probe<3,2>(lneindex61, std::array<u64,3>{v_c20, v_c22, 0}, [&](const std::array<u64,3>& m78) {
            u64 v_c23 = m78[2];
            slog::join_probe<2,2>(ivindex62, std::array<u64,2>{v_c23, v_c18}, [&](const std::array<u64,2>& m79) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c15}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "delta:check", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre) (scan temp3XuN172 E X __t5v3R126) (body (join leq (1 2 0) 2 __t5v3R126 E __t9w3f127)) (head (emit eqf (0 1 2) X E __t9w3f127)) verify.slog:50 #f)
  class ReadTask81 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** leqindex80;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eqf");
      std::vector<u16> ord82({0, 1, 2});
      slog::Relation* readrel83 = db->getRelation("eqf");
      head_index[0] = readrel83->getIndex(ord82, false);
      outer_rel = db->getRelation("temp3XuN172");
      std::vector<u16> ord84({1, 2, 0});
      slog::Relation* readrel85 = db->getRelation("leq");
      leqindex80 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask81(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        slog::join_probe<3,2>(leqindex80, std::array<u64,3>{v_c35, v_c33, 0}, [&](const std::array<u64,3>& m86) {
          u64 v_c36 = m86[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c34, v_c33, v_c36}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("verify.slog:50", "delta:temp3XuN172", _fires);
  
      if (!_done)
      {
        ReadTask81* _cont = new ReadTask81(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask81(db,b), false);
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971)) (scan lgt __t2PDL65 __t1cQ264 __t0WtQ62) (body (join ic (0 1) 2 __t0WtQ62 __tconst7YJt61) (join ic (0 1) 2 __t1cQ264 __tconst35f163)) (head (mkstruct check (1 3 2 0) __t024m67 __tconst4u1v66 __tconst5K2Z60 __t2PDL65)) demo.slog:30 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex87;  slog::Index** icindex88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      outer_rel = db->getRelation("lgt");
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("ic");
      icindex87 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("ic");
      icindex88 = readrel93->getIndex(ord92, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
  
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
        slog::join_probe<2,2>(icindex87, std::array<u64,2>{v_c44, v_c41}, [&](const std::array<u64,2>& m94) {
          slog::join_probe<2,2>(icindex88, std::array<u64,2>{v_c43, v_c40}, [&](const std::array<u64,2>& m95) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c38, v_c39, v_c42}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "delta:lgt", _fires);
  
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
  // (crule (pre) (scan asgn __t4sDs128 X E N) (body (join stmt (1 0) 1 __t4sDs128 L)) (head (emit-temp temp2RZM171 E X) (mkstruct iv (1 0) __t5v3R126 X)) verify.slog:50 #f)
  class ReadTask97 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stmtindex96;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2RZM171");
      head_rel[1] = db->getRelation("iv");
      outer_rel = db->getRelation("asgn");
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("stmt");
      stmtindex96 = readrel99->getIndex(ord98, false);
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c46 = _t[3];
        slog::join_probe<2,1>(stmtindex96, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m100) {
          u64 v_c47 = m100[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c33, v_c34});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c34}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("verify.slog:50", "delta:asgn", _fires);
  
      if (!_done)
      {
        ReadTask97* _cont = new ReadTask97(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask97(db,b), false);
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c)) (scan lne __t0Ksc29 __t8tDh28 __t3kVu26) (body (join ic (0 1) 2 __t3kVu26 __tconst2n0O25) (join iv (0 1) 2 __t8tDh28 __tconst1PP127)) (head (mkstruct check (1 3 2 0) __t4Ts131 __tconst6lL530 __tconst4s9G24 __t0Ksc29)) demo.slog:24 #f)
  class ReadTask103 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex101;  slog::Index** ivindex102;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      outer_rel = db->getRelation("lne");
      std::vector<u16> ord104({0, 1});
      slog::Relation* readrel105 = db->getRelation("ic");
      icindex101 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1});
      slog::Relation* readrel107 = db->getRelation("iv");
      ivindex102 = readrel107->getIndex(ord106, false);
  
    }
    ReadTask103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const1c39633808c54038b6212e46;
      u64 v_c16 = v_consta68730bc42ed463b202c634e;
      u64 v_c17 = v_const580dc10e980f4c3a7a1f2359;
      u64 v_c18 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe<2,2>(icindex101, std::array<u64,2>{v_c22, v_c19}, [&](const std::array<u64,2>& m108) {
          slog::join_probe<2,2>(ivindex102, std::array<u64,2>{v_c23, v_c18}, [&](const std::array<u64,2>& m109) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c16, v_c17, v_c20}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "delta:lne", _fires);
  
      if (!_done)
      {
        ReadTask103* _cont = new ReadTask103(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask103(db,b), false);
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst3onN110 const40480dc150931aa1b1d04926) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5)) (probe asgn (1 3 0 2) 2 __tconst3kSp116 __tconst3onN110 __t4NUM117 __t8CTm115) (body (exists ic (1 0) 1 __tconst9rCc113) (join iv (1 0) 1 __tconst5wBX111 __t24pM112) (join lsub (0 2 1) 2 __t8CTm115 __t24pM112 __t6I2Z114) (join ic (0 1) 2 __t6I2Z114 __tconst9rCc113)) (head (emit stmt (1 0) __t4NUM117 __tconst6z4r118)) demo.slog:17 #f)
  class ReadTask114 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** icindex110;  slog::Index** ivindex111;  slog::Index** lsubindex112;  slog::Index** icindex113;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord115({1, 0});
      slog::Relation* readrel116 = db->getRelation("stmt");
      head_index[0] = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 3, 0, 2});
      slog::Relation* readrel118 = db->getRelation("asgn");
      driver_index = readrel118->getIndex(ord117, true);
      std::vector<u16> ord119({1, 0});
      slog::Relation* readrel120 = db->getRelation("ic");
      icindex110 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 0});
      slog::Relation* readrel122 = db->getRelation("iv");
      ivindex111 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({0, 2, 1});
      slog::Relation* readrel124 = db->getRelation("lsub");
      lsubindex112 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("ic");
      icindex113 = readrel126->getIndex(ord125, false);
  
    }
    ReadTask114(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c25, v_c26, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m127) {
        u64 v_c30 = m127[2];
        u64 v_c29 = m127[3];
        if (buckethash(v_c30) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex110, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe<2,1>(ivindex111, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m128) {
          u64 v_c31 = m128[1];
          slog::join_probe<3,2>(lsubindex112, std::array<u64,3>{v_c29, v_c31, 0}, [&](const std::array<u64,3>& m129) {
            u64 v_c32 = m129[2];
            slog::join_probe<2,2>(icindex113, std::array<u64,2>{v_c32, v_c27}, [&](const std::array<u64,2>& m130) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c24}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "delta:asgn", _fires);
  
      if (!_done)
      {
        ReadTask114* _cont = new ReadTask114(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask114(db,b), false);
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971)) (probe check (1 3 0 2) 2 __tconst4u1v66 __tconst5K2Z60 __t024m67 __t2PDL65) (body (exists ic (1 0) 1 __tconst35f163) (join ic (1 0) 1 __tconst7YJt61 __t0WtQ62) (join lgt (0 2 1) 2 __t2PDL65 __t0WtQ62 __t1cQ264) (join ic (0 1) 2 __t1cQ264 __tconst35f163)) (head (emit stmt (1 0) __t024m67 __tconst2nzu68)) demo.slog:30 #f)
  class ReadTask135 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** icindex131;  slog::Index** icindex132;  slog::Index** lgtindex133;  slog::Index** icindex134;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("stmt");
      head_index[0] = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 3, 0, 2});
      slog::Relation* readrel139 = db->getRelation("check");
      driver_index = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("ic");
      icindex131 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("ic");
      icindex132 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 2, 1});
      slog::Relation* readrel145 = db->getRelation("lgt");
      lgtindex133 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("ic");
      icindex134 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c38, v_c39, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m148) {
        u64 v_c48 = m148[2];
        u64 v_c42 = m148[3];
        if (buckethash(v_c48) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex131, std::array<u64,2>{v_c40, 0})) return;
        slog::join_probe<2,1>(icindex132, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m149) {
          u64 v_c44 = m149[1];
          slog::join_probe<3,2>(lgtindex133, std::array<u64,3>{v_c42, v_c44, 0}, [&](const std::array<u64,3>& m150) {
            u64 v_c43 = m150[2];
            slog::join_probe<2,2>(icindex134, std::array<u64,2>{v_c43, v_c40}, [&](const std::array<u64,2>& m151) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c37}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "delta:check", _fires);
  
      if (!_done)
      {
        ReadTask135* _cont = new ReadTask135(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask135(db,b), false);
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c)) (seeded) (body (join ic (1 0) 1 __tconst6NWz71 __t5vc872) (exists llt (2 1 0) 1 __t5vc872) (join iv (1 0) 1 __tconst58dx73 __t3Imx74) (join llt (2 1 0) 2 __t5vc872 __t3Imx74 __t8MBI75)) (head (mkstruct branch (2 3 1 0) __t4vxt76 __tconst4csV70 __tconst8HQA69 __t8MBI75)) demo.slog:16 #f)
  class ReadTask156 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex152;  slog::Index** lltindex153;  slog::Index** ivindex154;  slog::Index** lltindex155;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("branch");
      std::vector<u16> ord157({2, 3, 1, 0});
      slog::Relation* readrel158 = db->getRelation("branch");
      head_index[0] = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("ic");
      icindex152 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({2, 1, 0});
      slog::Relation* readrel162 = db->getRelation("llt");
      lltindex153 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 0});
      slog::Relation* readrel164 = db->getRelation("iv");
      ivindex154 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({2, 1, 0});
      slog::Relation* readrel166 = db->getRelation("llt");
      lltindex155 = readrel166->getIndex(ord165, false);
  
    }
    ReadTask156(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c8 = v_const75f539c022ff58cca2ea854c;
      u64 v_c9 = v_const521847e7e2e4552b87a9916b;
      u64 v_c6 = v_constef39e22752c73795a9d935a5;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex152, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m167) {
        u64 v_c10 = m167[1];
        if (!slog::exists_probe<3,1>(lltindex153, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<2,1>(ivindex154, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m168) {
          u64 v_c11 = m168[1];
          slog::join_probe<3,2>(lltindex155, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m169) {
            u64 v_c49 = m169[2];
            ++_fires;
            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c8, v_c9, v_c49}, std::array<u16,4>{2, 3, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask156(db,b));
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5) (let __tconst3onN110 const40480dc150931aa1b1d04926)) (seeded) (body (join iv (1 0) 1 __tconst5wBX111 __t24pM112) (join ic (1 0) 1 __tconst9rCc113 __t6I2Z114)) (head (mkstruct lsub (2 1 0) __t8CTm115 __t24pM112 __t6I2Z114)) demo.slog:17 #f)
  class ReadTask172 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** ivindex170;  slog::Index** icindex171;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lsub");
      std::vector<u16> ord173({2, 1, 0});
      slog::Relation* readrel174 = db->getRelation("lsub");
      head_index[0] = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("iv");
      ivindex170 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 0});
      slog::Relation* readrel178 = db->getRelation("ic");
      icindex171 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask172(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(ivindex170, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m179) {
        u64 v_c31 = m179[1];
        slog::join_probe<2,1>(icindex171, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m180) {
          u64 v_c32 = m180[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c32}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask172(db,b));
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a)) (once) (body) (head (mkstruct ic (1 0) __t1cQ264 __tconst35f163) (mkstruct ic (1 0) __t0WtQ62 __tconst7YJt61)) demo.slog:30 #f)
  class ReadTask181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c41}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:30", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask181(db,b), true);
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a)) (seeded) (body (join ic (1 0) 1 __tconst7YJt61 __t0WtQ62) (join ic (1 0) 1 __tconst35f163 __t1cQ264)) (head (mkstruct lgt (2 1 0) __t2PDL65 __t0WtQ62 __t1cQ264)) demo.slog:30 #f)
  class ReadTask184 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex182;  slog::Index** icindex183;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lgt");
      std::vector<u16> ord185({2, 1, 0});
      slog::Relation* readrel186 = db->getRelation("lgt");
      head_index[0] = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("ic");
      icindex182 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ic");
      icindex183 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask184(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex182, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m191) {
        u64 v_c44 = m191[1];
        slog::join_probe<2,1>(icindex183, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m192) {
          u64 v_c43 = m192[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c43}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask184(db,b));
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971)) (seeded) (body (join ic (1 0) 1 __tconst7YJt61 __t0WtQ62) (exists lgt (2 1 0) 1 __t0WtQ62) (join ic (1 0) 1 __tconst35f163 __t1cQ264) (join lgt (2 1 0) 2 __t0WtQ62 __t1cQ264 __t2PDL65)) (head (mkstruct check (1 3 2 0) __t024m67 __tconst4u1v66 __tconst5K2Z60 __t2PDL65)) demo.slog:30 #f)
  class ReadTask197 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex193;  slog::Index** lgtindex194;  slog::Index** icindex195;  slog::Index** lgtindex196;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      std::vector<u16> ord198({1, 3, 2, 0});
      slog::Relation* readrel199 = db->getRelation("check");
      head_index[0] = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("ic");
      icindex193 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({2, 1, 0});
      slog::Relation* readrel203 = db->getRelation("lgt");
      lgtindex194 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("ic");
      icindex195 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({2, 1, 0});
      slog::Relation* readrel207 = db->getRelation("lgt");
      lgtindex196 = readrel207->getIndex(ord206, false);
  
    }
    ReadTask197(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex193, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m208) {
        u64 v_c44 = m208[1];
        if (!slog::exists_probe<3,1>(lgtindex194, std::array<u64,3>{v_c44, 0, 0})) return;
        slog::join_probe<2,1>(icindex195, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m209) {
          u64 v_c43 = m209[1];
          slog::join_probe<3,2>(lgtindex196, std::array<u64,3>{v_c44, v_c43, 0}, [&](const std::array<u64,3>& m210) {
            u64 v_c42 = m210[2];
            ++_fires;
            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c38, v_c39, v_c42}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask197(db,b));
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c)) (seeded) (body (join ic (1 0) 1 __tconst2WqR98 __t3YLv99) (exists lge (2 1 0) 1 __t3YLv99) (join iv (1 0) 1 __tconst503n100 __t8QUK101) (join lge (2 1 0) 2 __t3YLv99 __t8QUK101 __t3ZLW102)) (head (mkstruct check (1 3 2 0) __t7oct104 __tconst18Er103 __tconst0NaN97 __t3ZLW102)) demo.slog:19 #f)
  class ReadTask215 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex211;  slog::Index** lgeindex212;  slog::Index** ivindex213;  slog::Index** lgeindex214;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      std::vector<u16> ord216({1, 3, 2, 0});
      slog::Relation* readrel217 = db->getRelation("check");
      head_index[0] = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 0});
      slog::Relation* readrel219 = db->getRelation("ic");
      icindex211 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({2, 1, 0});
      slog::Relation* readrel221 = db->getRelation("lge");
      lgeindex212 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("iv");
      ivindex213 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({2, 1, 0});
      slog::Relation* readrel225 = db->getRelation("lge");
      lgeindex214 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask215(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c4 = v_const45aa4f80f636b15f8d75cce8;
      u64 v_c2 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex211, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m226) {
        u64 v_c50 = m226[1];
        if (!slog::exists_probe<3,1>(lgeindex212, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<2,1>(ivindex213, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m227) {
          u64 v_c51 = m227[1];
          slog::join_probe<3,2>(lgeindex214, std::array<u64,3>{v_c50, v_c51, 0}, [&](const std::array<u64,3>& m228) {
            u64 v_c52 = m228[2];
            ++_fires;
            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c4, v_c52}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask215(db,b));
  // (crule (pre (let __tconst4cJL133 conste433800a79f2d3be41014577) (let __tconst6gHm80 const45aa4f80f636b15f8d75cce8)) (probe _enum (1 0) 1 __tconst4cJL133 __t9ARu79) (body) (head (emit stmt (1 0) __t9ARu79 __tconst6gHm80)) demo.slog:20 #f)
  class ReadTask229 : public slog::Task
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
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("stmt");
      head_index[0] = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("_enum");
      driver_index = readrel233->getIndex(ord232, true);
  
    }
    ReadTask229(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_conste433800a79f2d3be41014577;
      u64 v_c54 = v_const45aa4f80f636b15f8d75cce8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c53, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m234) {
        u64 v_c55 = m234[1];
        if (buckethash(v_c55) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c54}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:20", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask229* _cont = new ReadTask229(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask229(db,b), true);
  // (crule (pre (let __tconst2nzu68 constb5c7d53c1c5cb8517644318d) (let __tconst4u1v66 constb3bd32486de3ee02878db405) (let __tconst5K2Z60 const14e32b34cd055e89c9cc695a) (let __tconst35f163 const6b86b273ff34fce19d6b804e) (let __tconst7YJt61 constd4735e3a265e16eee03f5971)) (seeded) (body (join check (1 3 2 0) 2 __tconst4u1v66 __tconst5K2Z60 __t2PDL65 __t024m67) (exists ic (1 0) 1 __tconst35f163) (join ic (1 0) 1 __tconst7YJt61 __t0WtQ62) (join lgt (0 2 1) 2 __t2PDL65 __t0WtQ62 __t1cQ264) (join ic (0 1) 2 __t1cQ264 __tconst35f163)) (head (emit stmt (1 0) __t024m67 __tconst2nzu68)) demo.slog:30 #f)
  class ReadTask240 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** checkindex235;  slog::Index** icindex236;  slog::Index** icindex237;  slog::Index** lgtindex238;  slog::Index** icindex239;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord241({1, 0});
      slog::Relation* readrel242 = db->getRelation("stmt");
      head_index[0] = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 3, 2, 0});
      slog::Relation* readrel244 = db->getRelation("check");
      checkindex235 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("ic");
      icindex236 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("ic");
      icindex237 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({0, 2, 1});
      slog::Relation* readrel250 = db->getRelation("lgt");
      lgtindex238 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("ic");
      icindex239 = readrel252->getIndex(ord251, false);
  
    }
    ReadTask240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c38 = v_constb3bd32486de3ee02878db405;
      u64 v_c39 = v_const14e32b34cd055e89c9cc695a;
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(checkindex235, std::array<u64,4>{v_c38, v_c39, 0, 0}, [&](const std::array<u64,4>& m253) {
        u64 v_c42 = m253[2]; u64 v_c48 = m253[3];
        if (!slog::exists_probe<2,1>(icindex236, std::array<u64,2>{v_c40, 0})) return;
        slog::join_probe<2,1>(icindex237, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m254) {
          u64 v_c44 = m254[1];
          slog::join_probe<3,2>(lgtindex238, std::array<u64,3>{v_c42, v_c44, 0}, [&](const std::array<u64,3>& m255) {
            u64 v_c43 = m255[2];
            slog::join_probe<2,2>(icindex239, std::array<u64,2>{v_c43, v_c40}, [&](const std::array<u64,2>& m256) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c37}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:30", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask240(db,b));
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1)) (seeded) (body (join check (1 3 2 0) 2 __tconst7EoZ21 __tconst69di12 __t2oqq20 __t9e5t22) (exists ic (1 0) 1 __tconst4wtI17) (join ic (1 0) 1 __tconst5qV413 __t12js14) (join lle (0 2 1) 2 __t2oqq20 __t12js14 __t52Ib19) (join ic (1 0) 1 __tconst4wtI17 __t57K216) (join lmul (0 1 2) 2 __t52Ib19 __t57K216 dup2MRL170) (eq __t57K216 dup2MRL170)) (head (emit stmt (1 0) __t9e5t22 __tconst3hGT23)) demo.slog:29 #f)
  class ReadTask263 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** checkindex257;  slog::Index** icindex258;  slog::Index** icindex259;  slog::Index** lleindex260;  slog::Index** icindex261;  slog::Index** lmulindex262;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord264({1, 0});
      slog::Relation* readrel265 = db->getRelation("stmt");
      head_index[0] = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 3, 2, 0});
      slog::Relation* readrel267 = db->getRelation("check");
      checkindex257 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("ic");
      icindex258 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("ic");
      icindex259 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 2, 1});
      slog::Relation* readrel273 = db->getRelation("lle");
      lleindex260 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 0});
      slog::Relation* readrel275 = db->getRelation("ic");
      icindex261 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1, 2});
      slog::Relation* readrel277 = db->getRelation("lmul");
      lmulindex262 = readrel277->getIndex(ord276, false);
  
    }
    ReadTask263(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c57 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c58 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c59 = v_const4a44dc15364204a80fe80e90;
      u64 v_c60 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(checkindex257, std::array<u64,4>{v_c57, v_c58, 0, 0}, [&](const std::array<u64,4>& m278) {
        u64 v_c61 = m278[2]; u64 v_c62 = m278[3];
        if (!slog::exists_probe<2,1>(icindex258, std::array<u64,2>{v_c60, 0})) return;
        slog::join_probe<2,1>(icindex259, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m279) {
          u64 v_c63 = m279[1];
          slog::join_probe<3,2>(lleindex260, std::array<u64,3>{v_c61, v_c63, 0}, [&](const std::array<u64,3>& m280) {
            u64 v_c64 = m280[2];
            slog::join_probe<2,1>(icindex261, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m281) {
              u64 v_c65 = m281[1];
              slog::join_probe<3,2>(lmulindex262, std::array<u64,3>{v_c64, v_c65, 0}, [&](const std::array<u64,3>& m282) {
                u64 v_c66 = m282[2];
                if (v_c65 != v_c66) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c56}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask263(db,b));
  // (crule (pre (let __tconst7jvJ77 consta9a6d512c3f845483b03fd37) (let __tconst4csV70 const75f539c022ff58cca2ea854c) (let __tconst8HQA69 const521847e7e2e4552b87a9916b) (let __tconst58dx73 constef39e22752c73795a9d935a5) (let __tconst6NWz71 const5feceb66ffc86f38d952786c)) (seeded) (body (join branch (2 3 1 0) 2 __tconst4csV70 __tconst8HQA69 __t8MBI75 __t4vxt76) (exists iv (1 0) 1 __tconst58dx73) (join ic (1 0) 1 __tconst6NWz71 __t5vc872) (join llt (0 2 1) 2 __t8MBI75 __t5vc872 __t3Imx74) (join iv (0 1) 2 __t3Imx74 __tconst58dx73)) (head (emit stmt (1 0) __t4vxt76 __tconst7jvJ77)) demo.slog:16 #f)
  class ReadTask288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** branchindex283;  slog::Index** ivindex284;  slog::Index** icindex285;  slog::Index** lltindex286;  slog::Index** ivindex287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord289({1, 0});
      slog::Relation* readrel290 = db->getRelation("stmt");
      head_index[0] = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({2, 3, 1, 0});
      slog::Relation* readrel292 = db->getRelation("branch");
      branchindex283 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 0});
      slog::Relation* readrel294 = db->getRelation("iv");
      ivindex284 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 0});
      slog::Relation* readrel296 = db->getRelation("ic");
      icindex285 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 2, 1});
      slog::Relation* readrel298 = db->getRelation("llt");
      lltindex286 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 1});
      slog::Relation* readrel300 = db->getRelation("iv");
      ivindex287 = readrel300->getIndex(ord299, false);
  
    }
    ReadTask288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_consta9a6d512c3f845483b03fd37;
      u64 v_c8 = v_const75f539c022ff58cca2ea854c;
      u64 v_c9 = v_const521847e7e2e4552b87a9916b;
      u64 v_c6 = v_constef39e22752c73795a9d935a5;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<4,2>(branchindex283, std::array<u64,4>{v_c8, v_c9, 0, 0}, [&](const std::array<u64,4>& m301) {
        u64 v_c49 = m301[2]; u64 v_c67 = m301[3];
        if (!slog::exists_probe<2,1>(ivindex284, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<2,1>(icindex285, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m302) {
          u64 v_c10 = m302[1];
          slog::join_probe<3,2>(lltindex286, std::array<u64,3>{v_c49, v_c10, 0}, [&](const std::array<u64,3>& m303) {
            u64 v_c11 = m303[2];
            slog::join_probe<2,2>(ivindex287, std::array<u64,2>{v_c11, v_c6}, [&](const std::array<u64,2>& m304) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c5}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask288(db,b));
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst5qV413 __t12js14) (exists lle (2 1 0) 1 __t12js14) (join ic (1 0) 1 __tconst4wtI17 __t57K216) (join lmul (1 2 0) 1 __t57K216 dup4d7v168 __t52Ib19) (eq __t57K216 dup4d7v168) (join lle (2 1 0) 2 __t12js14 __t52Ib19 __t2oqq20)) (head (mkstruct check (1 3 2 0) __t9e5t22 __tconst7EoZ21 __tconst69di12 __t2oqq20)) demo.slog:29 #f)
  class ReadTask310 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex305;  slog::Index** lleindex306;  slog::Index** icindex307;  slog::Index** lmulindex308;  slog::Index** lleindex309;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("check");
      std::vector<u16> ord311({1, 3, 2, 0});
      slog::Relation* readrel312 = db->getRelation("check");
      head_index[0] = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 0});
      slog::Relation* readrel314 = db->getRelation("ic");
      icindex305 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({2, 1, 0});
      slog::Relation* readrel316 = db->getRelation("lle");
      lleindex306 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0});
      slog::Relation* readrel318 = db->getRelation("ic");
      icindex307 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 2, 0});
      slog::Relation* readrel320 = db->getRelation("lmul");
      lmulindex308 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({2, 1, 0});
      slog::Relation* readrel322 = db->getRelation("lle");
      lleindex309 = readrel322->getIndex(ord321, false);
  
    }
    ReadTask310(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c57 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c58 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c59 = v_const4a44dc15364204a80fe80e90;
      u64 v_c60 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex305, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m323) {
        u64 v_c63 = m323[1];
        if (!slog::exists_probe<3,1>(lleindex306, std::array<u64,3>{v_c63, 0, 0})) return;
        slog::join_probe<2,1>(icindex307, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m324) {
          u64 v_c65 = m324[1];
          slog::join_probe<3,1>(lmulindex308, std::array<u64,3>{v_c65, 0, 0}, [&](const std::array<u64,3>& m325) {
            u64 v_c68 = m325[1]; u64 v_c64 = m325[2];
            if (v_c65 != v_c68) return;
            slog::join_probe<3,2>(lleindex309, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m326) {
              u64 v_c61 = m326[2];
              ++_fires;
              slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c57, v_c58, v_c61}, std::array<u16,4>{1, 3, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask310(db,b));
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5) (let __tconst3onN110 const40480dc150931aa1b1d04926)) (once) (body) (head (mkstruct ic (1 0) __t6I2Z114 __tconst9rCc113) (mkstruct iv (1 0) __t24pM112 __tconst5wBX111)) demo.slog:17 #f)
  class ReadTask327 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("iv");
  
    }
    ReadTask327(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c28}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:17", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask327(db,b), true);
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst69di12 constb5c7d53c1c5cb8517644318d) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1) (let __tconst5qV413 const4a44dc15364204a80fe80e90)) (seeded) (body (join ic (1 0) 1 __tconst5qV413 __t12js14) (join ic (1 0) 1 __tconst4wtI17 __t57K216) (join lmul (1 2 0) 1 __t57K216 dup4wkx166 __t52Ib19) (eq __t57K216 dup4wkx166)) (head (mkstruct lle (2 1 0) __t2oqq20 __t12js14 __t52Ib19)) demo.slog:29 #f)
  class ReadTask331 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex328;  slog::Index** icindex329;  slog::Index** lmulindex330;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lle");
      std::vector<u16> ord332({2, 1, 0});
      slog::Relation* readrel333 = db->getRelation("lle");
      head_index[0] = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0});
      slog::Relation* readrel335 = db->getRelation("ic");
      icindex328 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("ic");
      icindex329 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 0});
      slog::Relation* readrel339 = db->getRelation("lmul");
      lmulindex330 = readrel339->getIndex(ord338, false);
  
    }
    ReadTask331(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c57 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c58 = v_constb5c7d53c1c5cb8517644318d;
      u64 v_c60 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex328, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m340) {
        u64 v_c63 = m340[1];
        slog::join_probe<2,1>(icindex329, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m341) {
          u64 v_c65 = m341[1];
          slog::join_probe<3,1>(lmulindex330, std::array<u64,3>{v_c65, 0, 0}, [&](const std::array<u64,3>& m342) {
            u64 v_c69 = m342[1]; u64 v_c64 = m342[2];
            if (v_c65 != v_c69) return;
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c64}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:29", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask331(db,b));
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359)) (probe ic (1 0) 1 __tconst2n0O25 __t3kVu26) (body (join iv (1 0) 1 __tconst1PP127 __t8tDh28)) (head (mkstruct lne (2 1 0) __t0Ksc29 __t3kVu26 __t8tDh28)) demo.slog:24 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lne");
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("ic");
      driver_index = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("iv");
      ivindex343 = readrel348->getIndex(ord347, false);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const1c39633808c54038b6212e46;
      u64 v_c16 = v_consta68730bc42ed463b202c634e;
      u64 v_c18 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const580dc10e980f4c3a7a1f2359;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c19, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m349) {
        u64 v_c22 = m349[1];
        if (buckethash(v_c22) != bucket) return;
        slog::join_probe<2,1>(ivindex343, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m350) {
          u64 v_c23 = m350[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c22, v_c23}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:24", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask344* _cont = new ReadTask344(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask344(db,b), false);
  // (crule (pre (let __tconst5Fpi146 consta221beeaebe583607e193be7) (let __tconst0iQT147 constab76c7d069d6f33dc950fb33) (let __tconst32HK148 consteb8bf0d80db323992f6b634a) (let __tconst1dFD7 constd4735e3a265e16eee03f5971) (let __tconst7T2M5 const6b86b273ff34fce19d6b804e) (let __tconst8y7U3 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst5Fpi146 __t2nAE6) (body (exists _enum (1 0) 1 __tconst32HK148) (join _enum (1 0) 1 __tconst0iQT147 __t0L2R4) (join _enum (1 0) 1 __tconst32HK148 __t3UIh2)) (head (emit smt_vcode (0 1) __tconst1dFD7 __t2nAE6) (emit smt_vcode (0 1) __tconst7T2M5 __t0L2R4) (emit smt_vcode (0 1) __tconst8y7U3 __t3UIh2)) smt.slog:68 #f)
  class ReadTask354 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex351;  slog::Index** _enumindex352;  slog::Index** _enumindex353;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_vcode");
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("smt_vcode");
      head_index[0] = readrel356->getIndex(ord355, false);
      head_rel[1] = db->getRelation("smt_vcode");
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("smt_vcode");
      head_index[1] = readrel358->getIndex(ord357, false);
      head_rel[2] = db->getRelation("smt_vcode");
      std::vector<u16> ord359({0, 1});
      slog::Relation* readrel360 = db->getRelation("smt_vcode");
      head_index[2] = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 0});
      slog::Relation* readrel362 = db->getRelation("_enum");
      driver_index = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("_enum");
      _enumindex351 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 0});
      slog::Relation* readrel366 = db->getRelation("_enum");
      _enumindex352 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 0});
      slog::Relation* readrel368 = db->getRelation("_enum");
      _enumindex353 = readrel368->getIndex(ord367, false);
  
    }
    ReadTask354(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_consta221beeaebe583607e193be7;
      u64 v_c71 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c72 = v_consteb8bf0d80db323992f6b634a;
      u64 v_c73 = v_constd4735e3a265e16eee03f5971;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c70, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m369) {
        u64 v_c76 = m369[1];
        if (buckethash(v_c76) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex351, std::array<u64,2>{v_c72, 0})) return;
        slog::join_probe<2,1>(_enumindex352, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m370) {
          u64 v_c77 = m370[1];
          slog::join_probe<2,1>(_enumindex353, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m371) {
            u64 v_c78 = m371[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c76}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c74, v_c77}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c75, v_c78}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt.slog:68", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask354* _cont = new ReadTask354(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask354(db,b), true);
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst3onN110 const40480dc150931aa1b1d04926) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5)) (seeded) (body (join iv (1 0) 1 __tconst5wBX111 __t24pM112) (exists lsub (2 1 0) 1 __t24pM112) (join ic (1 0) 1 __tconst9rCc113 __t6I2Z114) (join lsub (2 1 0) 2 __t24pM112 __t6I2Z114 __t8CTm115)) (head (mkstruct asgn (1 3 2 0) __t4NUM117 __tconst3kSp116 __tconst3onN110 __t8CTm115)) demo.slog:17 #f)
  class ReadTask376 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** ivindex372;  slog::Index** lsubindex373;  slog::Index** icindex374;  slog::Index** lsubindex375;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("asgn");
      std::vector<u16> ord377({1, 3, 2, 0});
      slog::Relation* readrel378 = db->getRelation("asgn");
      head_index[0] = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 0});
      slog::Relation* readrel380 = db->getRelation("iv");
      ivindex372 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({2, 1, 0});
      slog::Relation* readrel382 = db->getRelation("lsub");
      lsubindex373 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 0});
      slog::Relation* readrel384 = db->getRelation("ic");
      icindex374 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({2, 1, 0});
      slog::Relation* readrel386 = db->getRelation("lsub");
      lsubindex375 = readrel386->getIndex(ord385, false);
  
    }
    ReadTask376(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(ivindex372, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m387) {
        u64 v_c31 = m387[1];
        if (!slog::exists_probe<3,1>(lsubindex373, std::array<u64,3>{v_c31, 0, 0})) return;
        slog::join_probe<2,1>(icindex374, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m388) {
          u64 v_c32 = m388[1];
          slog::join_probe<3,2>(lsubindex375, std::array<u64,3>{v_c31, v_c32, 0}, [&](const std::array<u64,3>& m389) {
            u64 v_c29 = m389[2];
            ++_fires;
            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c25, v_c26, v_c29}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask376(db,b));
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8)) (probe ic (1 0) 1 __tconst2WqR98 __t3YLv99) (body (join iv (1 0) 1 __tconst503n100 __t8QUK101)) (head (mkstruct lge (2 1 0) __t3ZLW102 __t3YLv99 __t8QUK101)) demo.slog:19 #f)
  class ReadTask391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lge");
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("ic");
      driver_index = readrel393->getIndex(ord392, true);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("iv");
      ivindex390 = readrel395->getIndex(ord394, false);
  
    }
    ReadTask391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c2 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const45aa4f80f636b15f8d75cce8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c3, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m396) {
        u64 v_c50 = m396[1];
        if (buckethash(v_c50) != bucket) return;
        slog::join_probe<2,1>(ivindex390, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m397) {
          u64 v_c51 = m397[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c50, v_c51}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask391* _cont = new ReadTask391(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask391(db,b), false);
  // (crule (pre (let __tconst6bGa145 conste433800a79f2d3be41014577) (let __tconst4Ad192 const14e32b34cd055e89c9cc695a)) (probe _enum (1 0) 1 __tconst6bGa145 __t6Caa91) (body) (head (emit stmt (1 0) __t6Caa91 __tconst4Ad192)) demo.slog:31 #f)
  class ReadTask398 : public slog::Task
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
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord399({1, 0});
      slog::Relation* readrel400 = db->getRelation("stmt");
      head_index[0] = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 0});
      slog::Relation* readrel402 = db->getRelation("_enum");
      driver_index = readrel402->getIndex(ord401, true);
  
    }
    ReadTask398(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_conste433800a79f2d3be41014577;
      u64 v_c80 = v_const14e32b34cd055e89c9cc695a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c79, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m403) {
        u64 v_c81 = m403[1];
        if (buckethash(v_c81) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c80}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:31", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask398* _cont = new ReadTask398(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask398(db,b), true);
  // (crule (pre (let __tconst6z4r118 const75f539c022ff58cca2ea854c) (let __tconst3kSp116 const09c9e756387a87c9bbdc4c0e) (let __tconst3onN110 const40480dc150931aa1b1d04926) (let __tconst9rCc113 const5feceb66ffc86f38d952786c) (let __tconst5wBX111 constef39e22752c73795a9d935a5)) (scan lsub __t8CTm115 __t6I2Z114 __t24pM112) (body (join iv (0 1) 2 __t24pM112 __tconst5wBX111) (join ic (0 1) 2 __t6I2Z114 __tconst9rCc113)) (head (mkstruct asgn (1 3 2 0) __t4NUM117 __tconst3kSp116 __tconst3onN110 __t8CTm115)) demo.slog:17 #f)
  class ReadTask406 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ivindex404;  slog::Index** icindex405;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("asgn");
      outer_rel = db->getRelation("lsub");
      std::vector<u16> ord407({0, 1});
      slog::Relation* readrel408 = db->getRelation("iv");
      ivindex404 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("ic");
      icindex405 = readrel410->getIndex(ord409, false);
  
    }
    ReadTask406(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const75f539c022ff58cca2ea854c;
      u64 v_c25 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c26 = v_const40480dc150931aa1b1d04926;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c29 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe<2,2>(ivindex404, std::array<u64,2>{v_c31, v_c28}, [&](const std::array<u64,2>& m411) {
          slog::join_probe<2,2>(icindex405, std::array<u64,2>{v_c32, v_c27}, [&](const std::array<u64,2>& m412) {
            ++_fires;
            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c25, v_c26, v_c29}, std::array<u16,4>{1, 3, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:17", "delta:lsub", _fires);
  
      if (!_done)
      {
        ReadTask406* _cont = new ReadTask406(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask406(db,b), false);
  // (crule (pre (let __tconst3hGT23 consted0583037dc2e002b6af2ca9) (let __tconst7EoZ21 constbb1534a1c906f3ee1939a91e) (let __tconst4wtI17 const4e07408562bedb8b60ce05c1) (let __tconst5qV413 const4a44dc15364204a80fe80e90) (let __tconst69di12 constb5c7d53c1c5cb8517644318d)) (once) (body) (head (mkstruct ic (1 0) __t57K216 __tconst4wtI17) (mkstruct ic (1 0) __t12js14 __tconst5qV413)) demo.slog:29 #f)
  class ReadTask413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_consted0583037dc2e002b6af2ca9;
      u64 v_c57 = v_constbb1534a1c906f3ee1939a91e;
      u64 v_c60 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_constb5c7d53c1c5cb8517644318d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c59}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:29", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask413(db,b), true);
  // (crule (pre (let __tconst48RK105 const40480dc150931aa1b1d04926) (let __tconst18Er103 const1277a2cd065b41d0baf310a1) (let __tconst0NaN97 const45aa4f80f636b15f8d75cce8) (let __tconst503n100 const09c9e756387a87c9bbdc4c0e) (let __tconst2WqR98 const5feceb66ffc86f38d952786c)) (probe check (1 3 0 2) 2 __tconst18Er103 __tconst0NaN97 __t7oct104 __t3ZLW102) (body (exists iv (1 0) 1 __tconst503n100) (join ic (1 0) 1 __tconst2WqR98 __t3YLv99) (join lge (0 2 1) 2 __t3ZLW102 __t3YLv99 __t8QUK101) (join iv (0 1) 2 __t8QUK101 __tconst503n100)) (head (emit stmt (1 0) __t7oct104 __tconst48RK105)) demo.slog:19 #f)
  class ReadTask418 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex414;  slog::Index** icindex415;  slog::Index** lgeindex416;  slog::Index** ivindex417;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord419({1, 0});
      slog::Relation* readrel420 = db->getRelation("stmt");
      head_index[0] = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 3, 0, 2});
      slog::Relation* readrel422 = db->getRelation("check");
      driver_index = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({1, 0});
      slog::Relation* readrel424 = db->getRelation("iv");
      ivindex414 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 0});
      slog::Relation* readrel426 = db->getRelation("ic");
      icindex415 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({0, 2, 1});
      slog::Relation* readrel428 = db->getRelation("lge");
      lgeindex416 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1});
      slog::Relation* readrel430 = db->getRelation("iv");
      ivindex417 = readrel430->getIndex(ord429, false);
  
    }
    ReadTask418(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const40480dc150931aa1b1d04926;
      u64 v_c1 = v_const1277a2cd065b41d0baf310a1;
      u64 v_c4 = v_const45aa4f80f636b15f8d75cce8;
      u64 v_c2 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c1, v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m431) {
        u64 v_c82 = m431[2];
        u64 v_c52 = m431[3];
        if (buckethash(v_c82) != bucket) return;
        if (!slog::exists_probe<2,1>(ivindex414, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(icindex415, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m432) {
          u64 v_c50 = m432[1];
          slog::join_probe<3,2>(lgeindex416, std::array<u64,3>{v_c52, v_c50, 0}, [&](const std::array<u64,3>& m433) {
            u64 v_c51 = m433[2];
            slog::join_probe<2,2>(ivindex417, std::array<u64,2>{v_c51, v_c2}, [&](const std::array<u64,2>& m434) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c0}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:19", "delta:check", _fires);
  
      if (!_done)
      {
        ReadTask418* _cont = new ReadTask418(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask418(db,b), false);
  // (crule (pre (let __tconst6xZt45 const521847e7e2e4552b87a9916b) (let __tconst1rC043 const09c9e756387a87c9bbdc4c0e) (let __tconst391g40 const40480dc150931aa1b1d04926) (let __tconst4bVo41 constef39e22752c73795a9d935a5)) (probe asgn (1 3 0 2) 2 __tconst1rC043 __tconst391g40 __t0yDQ44 __t1fAr42) (body (join iv (0 1) 2 __t1fAr42 __tconst4bVo41)) (head (emit stmt (1 0) __t0yDQ44 __tconst6xZt45)) demo.slog:18 #f)
  class ReadTask436 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex435;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("stmt");
      std::vector<u16> ord437({1, 0});
      slog::Relation* readrel438 = db->getRelation("stmt");
      head_index[0] = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 3, 0, 2});
      slog::Relation* readrel440 = db->getRelation("asgn");
      driver_index = readrel440->getIndex(ord439, true);
      std::vector<u16> ord441({0, 1});
      slog::Relation* readrel442 = db->getRelation("iv");
      ivindex435 = readrel442->getIndex(ord441, false);
  
    }
    ReadTask436(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const521847e7e2e4552b87a9916b;
      u64 v_c84 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c85 = v_const40480dc150931aa1b1d04926;
      u64 v_c86 = v_constef39e22752c73795a9d935a5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,2>(driver_index, std::array<u64,4>{v_c84, v_c85, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m443) {
        u64 v_c87 = m443[2];
        u64 v_c88 = m443[3];
        if (buckethash(v_c87) != bucket) return;
        slog::join_probe<2,2>(ivindex435, std::array<u64,2>{v_c88, v_c86}, [&](const std::array<u64,2>& m444) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c83}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:18", "delta:asgn", _fires);
  
      if (!_done)
      {
        ReadTask436* _cont = new ReadTask436(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask436(db,b), false);
  // (crule (pre (let __tconst6xZt45 const521847e7e2e4552b87a9916b) (let __tconst1rC043 const09c9e756387a87c9bbdc4c0e) (let __tconst4bVo41 constef39e22752c73795a9d935a5) (let __tconst391g40 const40480dc150931aa1b1d04926)) (once) (body) (head (mkstruct iv (1 0) __t1fAr42 __tconst4bVo41)) demo.slog:18 #f)
  class ReadTask445 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("iv");
  
    }
    ReadTask445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_const521847e7e2e4552b87a9916b;
      u64 v_c84 = v_const09c9e756387a87c9bbdc4c0e;
      u64 v_c86 = v_constef39e22752c73795a9d935a5;
      u64 v_c85 = v_const40480dc150931aa1b1d04926;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c86}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("demo.slog:18", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask445(db,b), true);
  // (crule (pre (let __tconst9B3032 const1c39633808c54038b6212e46) (let __tconst6lL530 consta68730bc42ed463b202c634e) (let __tconst1PP127 constfc5bdca6f3fa7cfdc4f78dd7) (let __tconst2n0O25 const5feceb66ffc86f38d952786c) (let __tconst4s9G24 const580dc10e980f4c3a7a1f2359)) (once) (body) (head (mkstruct iv (1 0) __t8tDh28 __tconst1PP127) (mkstruct ic (1 0) __t3kVu26 __tconst2n0O25)) demo.slog:24 #f)
  class ReadTask446 : public slog::Task
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
    ReadTask446(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const1c39633808c54038b6212e46;
      u64 v_c16 = v_consta68730bc42ed463b202c634e;
      u64 v_c18 = v_constfc5bdca6f3fa7cfdc4f78dd7;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const580dc10e980f4c3a7a1f2359;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("demo.slog:24", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask446(db,b), true);
}

