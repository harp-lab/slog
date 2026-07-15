
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1f503613ae12cc0c5121fd74;
extern u64 v_const2bc983a5942276eb00a75e21;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const74ed1f1471d4dd9b505236e5;
extern u64 v_const79093c59b0bf60c8403ebce3;
extern u64 v_constb40d060f542e4963e0fc1392;
extern u64 v_constba2df4903a2c14e86dc3bcca;


void slog_rules_c36b8001e8ddc41c3(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan lam __t8P1X2 x t1 e) (body (exists ck (2 0 1) 1 __t8P1X2) (exists ck (2 0 1) 1 e) (join-old ext (2 3 0 1) 2 (2 3 0 1) x t1 __t1FJ54 env) (exists ck (1 2 0) 2 __t1FJ54 e) (join-old ck (1 2 0) 2 (1 2 0) env __t8P1X2 __t99AN3) (join-old ck (1 2 0) 2 (1 2 0) __t1FJ54 e __t57LD5) (join ck_ans (0 1) 1 __t57LD5 __v0)) (head (emit-temp temp9j5e118 __t99AN3 __v0 t1) (mkstruct arrow (1 2 0) __t82gT1 t1 __v0)) dem_stlc.slog:16 #f)
  class ReadTask10 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex0;  slog::Index** ckindex1;  slog::Index** extindex2;  slog::Index** ckindex3;  slog::Index** ckindex4;  slog::Index** ckindex5;  slog::Index** ck_ansindex6;  slog::Index** extdelta7;  slog::Index** ckdelta8;  slog::Index** ckdelta9;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9j5e118");
      head_rel[1] = db->getRelation("arrow");
      outer_rel = db->getRelation("lam");
      std::vector<u16> ord11({2, 0, 1});
      slog::Relation* readrel12 = db->getRelation("ck");
      ckindex0 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({2, 0, 1});
      slog::Relation* readrel14 = db->getRelation("ck");
      ckindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({2, 3, 0, 1});
      slog::Relation* readrel16 = db->getRelation("ext");
      extindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({2, 3, 0, 1});
      slog::Relation* readrel18 = db->getRelation("ext");
      extdelta7 = readrel18->getIndex(ord17, true);
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("ck");
      ckindex3 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("ck");
      ckindex4 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 2, 0});
      slog::Relation* readrel24 = db->getRelation("ck");
      ckdelta8 = readrel24->getIndex(ord23, true);
      std::vector<u16> ord25({1, 2, 0});
      slog::Relation* readrel26 = db->getRelation("ck");
      ckindex5 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("ck");
      ckdelta9 = readrel28->getIndex(ord27, true);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("ck_ans");
      ck_ansindex6 = readrel30->getIndex(ord29, false);
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<3,1>(ckindex0, std::array<u64,3>{v_c0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex1, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<4,2>(extindex2, extdelta7, std::array<u64,4>{v_c1, v_c2, 0, 0}, [&](const std::array<u64,4>& m31) {
          u64 v_c4 = m31[2]; u64 v_c5 = m31[3];
          if (!slog::exists_probe<3,2>(ckindex3, std::array<u64,3>{v_c4, v_c3, 0})) return;
          slog::join_probe_old<3,2>(ckindex4, ckdelta8, std::array<u64,3>{v_c5, v_c0, 0}, [&](const std::array<u64,3>& m32) {
            u64 v_c6 = m32[2];
            slog::join_probe_old<3,2>(ckindex5, ckdelta9, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m33) {
              u64 v_c7 = m33[2];
              slog::join_probe<2,1>(ck_ansindex6, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m34) {
                u64 v_c8 = m34[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c6, v_c8, v_c2});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c8}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:lam", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan lookup __t9Fqg18 env x) (body (exists var (1 0) 1 x) (exists ck (1 2 0) 1 env) (join lookup_ans (0 1) 1 __t9Fqg18 __v0) (join var (1 0) 1 x __t6OR216) (join ck (1 2 0) 2 env __t6OR216 __t43Yp17)) (head (emit ck_ans (0 1) __t43Yp17 __v0)) dem_stlc.slog:15 #f)
  class ReadTask40 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** varindex35;  slog::Index** ckindex36;  slog::Index** lookup_ansindex37;  slog::Index** varindex38;  slog::Index** ckindex39;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("ck_ans");
      head_index[0] = readrel42->getIndex(ord41, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("var");
      varindex35 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 0});
      slog::Relation* readrel46 = db->getRelation("ck");
      ckindex36 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("lookup_ans");
      lookup_ansindex37 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("var");
      varindex38 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("ck");
      ckindex39 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<2,1>(varindex35, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex36, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<2,1>(lookup_ansindex37, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m53) {
          u64 v_c8 = m53[1];
          slog::join_probe<2,1>(varindex38, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m54) {
            u64 v_c10 = m54[1];
            slog::join_probe<3,2>(ckindex39, std::array<u64,3>{v_c5, v_c10, 0}, [&](const std::array<u64,3>& m55) {
              u64 v_c11 = m55[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c8}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre) (scan ck __t0iEo67 env __t7Y9q66) (body (join app (0 2 1) 1 __t7Y9q66 e2 e1)) (head (emit $sup76879x16x0x0x0 (0 3 1 2) __t0iEo67 env e1 e2)) dem_stlc.slog:17 #f)
  class ReadTask57 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex56;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup76879x16x0x0x0");
      std::vector<u16> ord58({0, 3, 1, 2});
      slog::Relation* readrel59 = db->getRelation("$sup76879x16x0x0x0");
      head_index[0] = readrel59->getIndex(ord58, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord60({0, 2, 1});
      slog::Relation* readrel61 = db->getRelation("app");
      appindex56 = readrel61->getIndex(ord60, false);
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe<3,1>(appindex56, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m62) {
          u64 v_c14 = m62[1]; u64 v_c15 = m62[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c12, v_c5, v_c15, v_c14}, std::array<u16,4>{0, 3, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask57* _cont = new ReadTask57(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask57(db,b), false);
  // (crule (pre) (scan $sup76879x10x0x0x0 __t4rN257 env x y) (body (neq x y) (exists ext (1 2 3 0) 2 env y) (exists lookup (1 2 0) 2 env x) (join-old lookup (0 2 1) 2 (0 2 1) __t4rN257 x __t538W56) (join-old ext (0 2 1 3) 3 (0 2 1 3) __t538W56 y env ____2zPL59) (join-old lookup (1 2 0) 2 (1 2 0) env x __t8ds158) (join lookup_ans (0 1) 1 __t8ds158 t)) (head (emit lookup_ans (0 1) __t4rN257 t)) dem_stlc.slog:11 #f)
  class ReadTask72 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extindex63;  slog::Index** lookupindex64;  slog::Index** lookupindex65;  slog::Index** extindex66;  slog::Index** lookupindex67;  slog::Index** lookup_ansindex68;  slog::Index** lookupdelta69;  slog::Index** extdelta70;  slog::Index** lookupdelta71;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("lookup_ans");
      head_index[0] = readrel74->getIndex(ord73, false);
      outer_rel = db->getRelation("$sup76879x10x0x0x0");
      std::vector<u16> ord75({1, 2, 3, 0});
      slog::Relation* readrel76 = db->getRelation("ext");
      extindex63 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("lookup");
      lookupindex64 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({0, 2, 1});
      slog::Relation* readrel80 = db->getRelation("lookup");
      lookupindex65 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 2, 1});
      slog::Relation* readrel82 = db->getRelation("lookup");
      lookupdelta69 = readrel82->getIndex(ord81, true);
      std::vector<u16> ord83({0, 2, 1, 3});
      slog::Relation* readrel84 = db->getRelation("ext");
      extindex66 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1, 3});
      slog::Relation* readrel86 = db->getRelation("ext");
      extdelta70 = readrel86->getIndex(ord85, true);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("lookup");
      lookupindex67 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 2, 0});
      slog::Relation* readrel90 = db->getRelation("lookup");
      lookupdelta71 = readrel90->getIndex(ord89, true);
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("lookup_ans");
      lookup_ansindex68 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask72(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c17 = _t[3];
        if (v_c1 == v_c17) return;
        if (!slog::exists_probe<4,2>(extindex63, std::array<u64,4>{v_c5, v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,2>(lookupindex64, std::array<u64,3>{v_c5, v_c1, 0})) return;
        slog::join_probe_old<3,2>(lookupindex65, lookupdelta69, std::array<u64,3>{v_c16, v_c1, 0}, [&](const std::array<u64,3>& m93) {
          u64 v_c18 = m93[2];
          slog::join_probe_old<4,3>(extindex66, extdelta70, std::array<u64,4>{v_c18, v_c17, v_c5, 0}, [&](const std::array<u64,4>& m94) {
            u64 v_c19 = m94[3];
            slog::join_probe_old<3,2>(lookupindex67, lookupdelta71, std::array<u64,3>{v_c5, v_c1, 0}, [&](const std::array<u64,3>& m95) {
              u64 v_c20 = m95[2];
              slog::join_probe<2,1>(lookup_ansindex68, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m96) {
                u64 v_c21 = m96[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c21}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:$sup76879x10x0x0x0", _fires);
  
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
  // (crule (pre) (scan lam __t0VTf12 x t1 e) (body (join-old ck (2 0 1) 1 (2 0 1) __t0VTf12 __t26fA13 env)) (head (emit-temp temp8Tl3109 e env t1 x) (mkstruct ext (1 2 3 0) __t0xCE11 env x t1)) dem_stlc.slog:16 #f)
  class ReadTask99 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex97;  slog::Index** ckdelta98;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Tl3109");
      head_rel[1] = db->getRelation("ext");
      outer_rel = db->getRelation("lam");
      std::vector<u16> ord100({2, 0, 1});
      slog::Relation* readrel101 = db->getRelation("ck");
      ckindex97 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({2, 0, 1});
      slog::Relation* readrel103 = db->getRelation("ck");
      ckdelta98 = readrel103->getIndex(ord102, true);
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        slog::join_probe_old<3,1>(ckindex97, ckdelta98, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m104) {
          u64 v_c23 = m104[1]; u64 v_c5 = m104[2];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c3, v_c5, v_c2, v_c1});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c5, v_c1, v_c2}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:lam", _fires);
  
      if (!_done)
      {
        ReadTask99* _cont = new ReadTask99(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask99(db,b), false);
  // (crule (pre (let __trid8u9P88 const79093c59b0bf60c8403ebce3) (let __trel14DY89 const74ed1f1471d4dd9b505236e5) (let __tcol2q4p90 const5feceb66ffc86f38d952786c) (let __trel9AqL91 const74ed1f1471d4dd9b505236e5) (let __tcol62rs92 const6b86b273ff34fce19d6b804e)) (scan $sup76879x16x0x0x0 __d0 e1 e2 env) (body) (head (tycheck env (accept (struct ext) (struct _enum)) __trid8u9P88 __trel14DY89 __tcol2q4p90 (1 2 3 4 0)) (tycheck e2 (accept (struct app) (struct lam) (struct num) (struct var)) __trid8u9P88 __trel9AqL91 __tcol62rs92 (1 2 3 4 0)) (mkstruct ck (1 2 0) __0LVD87 env e2)) dem_stlc.slog:17 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid106;  u32 sid107;  u32 sid105;  u32 sid108;  u32 sid109;  u32 sid110;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("ck");
      outer_rel = db->getRelation("$sup76879x16x0x0x0");
      sid106 = db->getRelation("_enum")->getStructId();
      sid107 = db->getRelation("app")->getStructId();
      sid105 = db->getRelation("ext")->getStructId();
      sid108 = db->getRelation("lam")->getStructId();
      sid109 = db->getRelation("num")->getStructId();
      sid110 = db->getRelation("var")->getStructId();
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const79093c59b0bf60c8403ebce3;
      u64 v_c25 = v_const74ed1f1471d4dd9b505236e5;
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const74ed1f1471d4dd9b505236e5;
      u64 v_c28 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c29 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c5 = _t[3];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid105 || decode_struct_id(v_c5) == sid106))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c24, v_c25, v_c26, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid107 || decode_struct_id(v_c14) == sid108 || decode_struct_id(v_c14) == sid109 || decode_struct_id(v_c14) == sid110))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c24, v_c27, v_c28, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c14}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:$sup76879x16x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre) (scan ck __t26fA13 env __t0VTf12) (body (join lam (0 1 2 3) 1 __t0VTf12 x t1 e)) (head (emit-temp temp8Tl3109 e env t1 x) (mkstruct ext (1 2 3 0) __t0xCE11 env x t1)) dem_stlc.slog:16 #f)
  class ReadTask113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lamindex112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Tl3109");
      head_rel[1] = db->getRelation("ext");
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord114({0, 1, 2, 3});
      slog::Relation* readrel115 = db->getRelation("lam");
      lamindex112 = readrel115->getIndex(ord114, false);
  
    }
    ReadTask113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe<4,1>(lamindex112, std::array<u64,4>{v_c22, 0, 0, 0}, [&](const std::array<u64,4>& m116) {
          u64 v_c1 = m116[1]; u64 v_c2 = m116[2]; u64 v_c3 = m116[3];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c3, v_c5, v_c2, v_c1});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c5, v_c1, v_c2}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask113* _cont = new ReadTask113(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask113(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst6P6s76 constb40d060f542e4963e0fc1392) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e)) (seeded) (body (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists var (1 0) 1 __tconst8dNm51) (exists lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50) (exists lam (1 2 3 0) 1 __tconst3JhQ48) (exists arrow (1 2 0) 1 __t3zgy50) (exists var (1 0) 1 __tconst3JhQ48) (exists lam (1 2 3 0) 1 __tconst9nbj32) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (join lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50 __t0OY020 __t16B123) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (exists app (2 0 1) 1 __t0OY020) (exists app (2 0 1) 1 __t16B123) (join lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50 __t5JUn49 __t5Erl52) (join lam (0 1 2 3) 2 __t5JUn49 __tconst3JhQ48 __t4oeC31 __t2MLp44) (exists app (0 2 1) 2 __t2MLp44 __t0OY020) (exists lam (1 2 3 0) 2 __tconst9nbj32 __t4oeC31) (join arrow (0 1 2) 2 __t4oeC31 __t3zgy50 dup0Zof117) (eq __t3zgy50 dup0Zof117) (join app (0 2 1) 2 __t2MLp44 __t0OY020 __t7Q1C43) (join var (0 1) 2 __t7Q1C43 __tconst3JhQ48) (join lam (1 2 3 0) 2 __tconst9nbj32 __t4oeC31 __t7G7R28 __t9fNk33) (join app (1 2 0) 2 __t9fNk33 __t16B123 __t2P4j34) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (join app (0 2 1) 2 __t7G7R28 __t95AJ25 __t6EL627) (join var (0 1) 2 __t6EL627 __tconst9nbj32)) (head (emit prog (0) __t5Erl52) (emit prog (0) __t2P4j34)) dem_stlc.slog:23 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** _enumindex117;  slog::Index** varindex118;  slog::Index** lamindex119;  slog::Index** lamindex120;  slog::Index** arrowindex121;  slog::Index** varindex122;  slog::Index** lamindex123;  slog::Index** numindex124;  slog::Index** varindex125;  slog::Index** lamindex126;  slog::Index** varindex127;  slog::Index** appindex128;  slog::Index** appindex129;  slog::Index** lamindex130;  slog::Index** lamindex131;  slog::Index** appindex132;  slog::Index** lamindex133;  slog::Index** arrowindex134;  slog::Index** appindex135;  slog::Index** varindex136;  slog::Index** lamindex137;  slog::Index** appindex138;  slog::Index** numindex139;  slog::Index** appindex140;  slog::Index** varindex141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord143({0});
      slog::Relation* readrel144 = db->getRelation("prog");
      head_index[0] = readrel144->getIndex(ord143, false);
      head_rel[1] = db->getRelation("prog");
      std::vector<u16> ord145({0});
      slog::Relation* readrel146 = db->getRelation("prog");
      head_index[1] = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 0});
      slog::Relation* readrel148 = db->getRelation("_enum");
      _enumindex117 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("var");
      varindex118 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 3, 0});
      slog::Relation* readrel152 = db->getRelation("lam");
      lamindex119 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 3, 0});
      slog::Relation* readrel154 = db->getRelation("lam");
      lamindex120 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("arrow");
      arrowindex121 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("var");
      varindex122 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 3, 0});
      slog::Relation* readrel160 = db->getRelation("lam");
      lamindex123 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("num");
      numindex124 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 0});
      slog::Relation* readrel164 = db->getRelation("var");
      varindex125 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 3, 0});
      slog::Relation* readrel166 = db->getRelation("lam");
      lamindex126 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("var");
      varindex127 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({2, 0, 1});
      slog::Relation* readrel170 = db->getRelation("app");
      appindex128 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({2, 0, 1});
      slog::Relation* readrel172 = db->getRelation("app");
      appindex129 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 3, 0});
      slog::Relation* readrel174 = db->getRelation("lam");
      lamindex130 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1, 2, 3});
      slog::Relation* readrel176 = db->getRelation("lam");
      lamindex131 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 2, 1});
      slog::Relation* readrel178 = db->getRelation("app");
      appindex132 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 3, 0});
      slog::Relation* readrel180 = db->getRelation("lam");
      lamindex133 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1, 2});
      slog::Relation* readrel182 = db->getRelation("arrow");
      arrowindex134 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 2, 1});
      slog::Relation* readrel184 = db->getRelation("app");
      appindex135 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("var");
      varindex136 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 3, 0});
      slog::Relation* readrel188 = db->getRelation("lam");
      lamindex137 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("app");
      appindex138 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("num");
      numindex139 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 2, 1});
      slog::Relation* readrel194 = db->getRelation("app");
      appindex140 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("var");
      varindex141 = readrel196->getIndex(ord195, false);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex117, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m197) {
        u64 v_c35 = m197[1];
        if (!slog::exists_probe<2,1>(varindex118, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<4,2>(lamindex119, std::array<u64,4>{v_c30, v_c35, 0, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex120, std::array<u64,4>{v_c31, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(arrowindex121, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(varindex122, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex123, std::array<u64,4>{v_c32, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(numindex124, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex125, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<4,2>(lamindex126, std::array<u64,4>{v_c30, v_c35, 0, 0}, [&](const std::array<u64,4>& m198) {
          u64 v_c36 = m198[2]; u64 v_c37 = m198[3];
          slog::join_probe<2,2>(varindex127, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m199) {
            if (!slog::exists_probe<3,1>(appindex128, std::array<u64,3>{v_c36, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex129, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<4,2>(lamindex130, std::array<u64,4>{v_c30, v_c35, 0, 0}, [&](const std::array<u64,4>& m200) {
              u64 v_c38 = m200[2]; u64 v_c39 = m200[3];
              slog::join_probe<4,2>(lamindex131, std::array<u64,4>{v_c38, v_c31, 0, 0}, [&](const std::array<u64,4>& m201) {
                u64 v_c40 = m201[2]; u64 v_c41 = m201[3];
                if (!slog::exists_probe<3,2>(appindex132, std::array<u64,3>{v_c41, v_c36, 0})) return;
                if (!slog::exists_probe<4,2>(lamindex133, std::array<u64,4>{v_c32, v_c40, 0, 0})) return;
                slog::join_probe<3,2>(arrowindex134, std::array<u64,3>{v_c40, v_c35, 0}, [&](const std::array<u64,3>& m202) {
                  u64 v_c42 = m202[2];
                  if (v_c35 != v_c42) return;
                  slog::join_probe<3,2>(appindex135, std::array<u64,3>{v_c41, v_c36, 0}, [&](const std::array<u64,3>& m203) {
                    u64 v_c43 = m203[2];
                    slog::join_probe<2,2>(varindex136, std::array<u64,2>{v_c43, v_c31}, [&](const std::array<u64,2>& m204) {
                      slog::join_probe<4,2>(lamindex137, std::array<u64,4>{v_c32, v_c40, 0, 0}, [&](const std::array<u64,4>& m205) {
                        u64 v_c44 = m205[2]; u64 v_c45 = m205[3];
                        slog::join_probe<3,2>(appindex138, std::array<u64,3>{v_c45, v_c37, 0}, [&](const std::array<u64,3>& m206) {
                          u64 v_c46 = m206[2];
                          slog::join_probe<2,1>(numindex139, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m207) {
                            u64 v_c47 = m207[1];
                            slog::join_probe<3,2>(appindex140, std::array<u64,3>{v_c44, v_c47, 0}, [&](const std::array<u64,3>& m208) {
                              u64 v_c48 = m208[2];
                              slog::join_probe<2,2>(varindex141, std::array<u64,2>{v_c48, v_c32}, [&](const std::array<u64,2>& m209) {
                                ++_fires;
                                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
                                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask142(db,b));
  // (crule (pre) (scan ext __t1moV61 env y ____7sx763) (body (join-old lookup (1 2 0) 1 (1 2 0) __t1moV61 x __t5u0262) (neq x y)) (head (emit $sup76879x10x0x0x0 (0 2 1 3) __t5u0262 x env y)) dem_stlc.slog:11 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex210;  slog::Index** lookupdelta211;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup76879x10x0x0x0");
      std::vector<u16> ord213({0, 2, 1, 3});
      slog::Relation* readrel214 = db->getRelation("$sup76879x10x0x0x0");
      head_index[0] = readrel214->getIndex(ord213, false);
      outer_rel = db->getRelation("ext");
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("lookup");
      lookupindex210 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("lookup");
      lookupdelta211 = readrel218->getIndex(ord217, true);
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c50 = _t[3];
        slog::join_probe_old<3,1>(lookupindex210, lookupdelta211, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m219) {
          u64 v_c1 = m219[1]; u64 v_c51 = m219[2];
          if (v_c1 == v_c17) return;
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c51, v_c1, v_c5, v_c17}, std::array<u16,4>{0, 2, 1, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:ext", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre) (scan temp9j5e118 __t99AN3 __v0 t1) (body (join arrow (1 2 0) 2 t1 __v0 __t82gT1)) (head (emit ck_ans (0 1) __t99AN3 __t82gT1)) dem_stlc.slog:16 #f)
  class ReadTask221 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** arrowindex220;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("ck_ans");
      head_index[0] = readrel223->getIndex(ord222, false);
      outer_rel = db->getRelation("temp9j5e118");
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("arrow");
      arrowindex220 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(arrowindex220, std::array<u64,3>{v_c2, v_c8, 0}, [&](const std::array<u64,3>& m226) {
          u64 v_c52 = m226[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c52}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:temp9j5e118", _fires);
  
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
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst1wvy37 const4e07408562bedb8b60ce05c1) (let __tconst1K9r35 const4b227777d4dd1fc61c6f884f) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e) (let __tconst6P6s76 constb40d060f542e4963e0fc1392)) (seeded) (body (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (exists num (1 0) 1 __tconst1K9r35) (exists num (1 0) 1 __tconst1wvy37) (exists var (1 0) 1 __tconst3JhQ48) (exists arrow (1 2 0) 1 __t3zgy50) (join var (1 0) 1 __tconst8dNm51 __t0OY020) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (join var (1 0) 1 __tconst9nbj32 __t6EL627) (join num (1 0) 1 __tconst1K9r35 __t35Fj36) (join num (1 0) 1 __tconst1wvy37 __t7sPi38) (join var (1 0) 1 __tconst3JhQ48 __t7Q1C43) (join arrow (1 2 0) 1 __t3zgy50 dup6etk111 __t4oeC31) (eq __t3zgy50 dup6etk111)) (head (mkstruct app (1 2 0) __t2MLp44 __t7Q1C43 __t0OY020) (mkstruct app (1 2 0) __t4b7B39 __t7sPi38 __t35Fj36) (mkstruct app (1 2 0) __t7G7R28 __t6EL627 __t95AJ25) (mkstruct lam (1 2 3 0) __t16B123 __tconst8dNm51 __t3zgy50 __t0OY020)) dem_stlc.slog:23 #f)
  class ReadTask241 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** _enumindex227;  slog::Index** numindex228;  slog::Index** varindex229;  slog::Index** numindex230;  slog::Index** numindex231;  slog::Index** varindex232;  slog::Index** arrowindex233;  slog::Index** varindex234;  slog::Index** numindex235;  slog::Index** varindex236;  slog::Index** numindex237;  slog::Index** numindex238;  slog::Index** varindex239;  slog::Index** arrowindex240;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("app");
      head_index[0] = readrel243->getIndex(ord242, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("app");
      head_index[1] = readrel245->getIndex(ord244, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("app");
      head_index[2] = readrel247->getIndex(ord246, false);
      head_rel[3] = db->getRelation("lam");
      std::vector<u16> ord248({1, 2, 3, 0});
      slog::Relation* readrel249 = db->getRelation("lam");
      head_index[3] = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("_enum");
      _enumindex227 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 0});
      slog::Relation* readrel253 = db->getRelation("num");
      numindex228 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("var");
      varindex229 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0});
      slog::Relation* readrel257 = db->getRelation("num");
      numindex230 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 0});
      slog::Relation* readrel259 = db->getRelation("num");
      numindex231 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 0});
      slog::Relation* readrel261 = db->getRelation("var");
      varindex232 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 2, 0});
      slog::Relation* readrel263 = db->getRelation("arrow");
      arrowindex233 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 0});
      slog::Relation* readrel265 = db->getRelation("var");
      varindex234 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 0});
      slog::Relation* readrel267 = db->getRelation("num");
      numindex235 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("var");
      varindex236 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("num");
      numindex237 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 0});
      slog::Relation* readrel273 = db->getRelation("num");
      numindex238 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 0});
      slog::Relation* readrel275 = db->getRelation("var");
      varindex239 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 0});
      slog::Relation* readrel277 = db->getRelation("arrow");
      arrowindex240 = readrel277->getIndex(ord276, false);
  
    }
    ReadTask241(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c53 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c54 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex227, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m278) {
        u64 v_c35 = m278[1];
        if (!slog::exists_probe<2,1>(numindex228, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex229, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(numindex230, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<2,1>(numindex231, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(varindex232, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(arrowindex233, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<2,1>(varindex234, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m279) {
          u64 v_c36 = m279[1];
          slog::join_probe<2,1>(numindex235, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m280) {
            u64 v_c47 = m280[1];
            slog::join_probe<2,1>(varindex236, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m281) {
              u64 v_c48 = m281[1];
              slog::join_probe<2,1>(numindex237, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m282) {
                u64 v_c55 = m282[1];
                slog::join_probe<2,1>(numindex238, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m283) {
                  u64 v_c56 = m283[1];
                  slog::join_probe<2,1>(varindex239, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m284) {
                    u64 v_c43 = m284[1];
                    slog::join_probe<3,1>(arrowindex240, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m285) {
                      u64 v_c57 = m285[1]; u64 v_c40 = m285[2];
                      if (v_c35 != v_c57) return;
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c36}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c56, v_c55}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c48, v_c47}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<4>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c30, v_c35, v_c36}, std::array<u16,4>{1, 2, 3, 0});
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
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask241(db,b));
  // (crule (pre) (scan ck __t8xpU69 env __t65ap68) (body (join var (0 1) 1 __t65ap68 x)) (head (mkstruct lookup (1 2 0) __2bB777 env x)) dem_stlc.slog:15 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** varindex286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("var");
      varindex286 = readrel289->getIndex(ord288, false);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c59 = _t[2];
        slog::join_probe<2,1>(varindex286, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m290) {
          u64 v_c1 = m290[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre) (scan ck_ans __t17cq8 __t9HVg9) (body (join-old ck (0 1 2) 1 (0 1 2) __t17cq8 env e1) (exists app (1 2 0) 1 e1) (exists ck (1 2 0) 1 env) (join-old $sup76879x16x0x0x0 (1 3 0 2) 2 (1 3 0 2) e1 env __t6Npw7 e2) (exists ck (0 1 2) 2 __t6Npw7 env) (exists ck (1 2 0) 2 env e2) (join-old app (1 2 0) 2 (1 2 0) e1 e2 __t3xua6) (join-old ck (0 1 2) 3 (0 1 2) __t6Npw7 env __t3xua6) (join-old ck (1 2 0) 2 (1 2 0) env e2 __t37kq10) (join-old ck_ans (0 1) 1 (0 1) __t37kq10 t1) (join-old arrow (0 1 2) 2 (0 1 2) __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex291;  slog::Index** appindex292;  slog::Index** ckindex293;  slog::Index** $sup76879x16x0x0x0index294;  slog::Index** ckindex295;  slog::Index** ckindex296;  slog::Index** appindex297;  slog::Index** ckindex298;  slog::Index** ckindex299;  slog::Index** ck_ansindex300;  slog::Index** arrowindex301;  slog::Index** ckdelta302;  slog::Index** $sup76879x16x0x0x0delta303;  slog::Index** appdelta304;  slog::Index** ckdelta305;  slog::Index** ckdelta306;  slog::Index** ck_ansdelta307;  slog::Index** arrowdelta308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("ck_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("ck_ans");
      std::vector<u16> ord312({0, 1, 2});
      slog::Relation* readrel313 = db->getRelation("ck");
      ckindex291 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1, 2});
      slog::Relation* readrel315 = db->getRelation("ck");
      ckdelta302 = readrel315->getIndex(ord314, true);
      std::vector<u16> ord316({1, 2, 0});
      slog::Relation* readrel317 = db->getRelation("app");
      appindex292 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("ck");
      ckindex293 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 3, 0, 2});
      slog::Relation* readrel321 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index294 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 3, 0, 2});
      slog::Relation* readrel323 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0delta303 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({0, 1, 2});
      slog::Relation* readrel325 = db->getRelation("ck");
      ckindex295 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 0});
      slog::Relation* readrel327 = db->getRelation("ck");
      ckindex296 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("app");
      appindex297 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("app");
      appdelta304 = readrel331->getIndex(ord330, true);
      std::vector<u16> ord332({0, 1, 2});
      slog::Relation* readrel333 = db->getRelation("ck");
      ckindex298 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1, 2});
      slog::Relation* readrel335 = db->getRelation("ck");
      ckdelta305 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({1, 2, 0});
      slog::Relation* readrel337 = db->getRelation("ck");
      ckindex299 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 0});
      slog::Relation* readrel339 = db->getRelation("ck");
      ckdelta306 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("ck_ans");
      ck_ansindex300 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("ck_ans");
      ck_ansdelta307 = readrel343->getIndex(ord342, true);
      std::vector<u16> ord344({0, 1, 2});
      slog::Relation* readrel345 = db->getRelation("arrow");
      arrowindex301 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1, 2});
      slog::Relation* readrel347 = db->getRelation("arrow");
      arrowdelta308 = readrel347->getIndex(ord346, true);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        slog::join_probe_old<3,1>(ckindex291, ckdelta302, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m348) {
          u64 v_c5 = m348[1]; u64 v_c15 = m348[2];
          if (!slog::exists_probe<3,1>(appindex292, std::array<u64,3>{v_c15, 0, 0})) return;
          if (!slog::exists_probe<3,1>(ckindex293, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe_old<4,2>($sup76879x16x0x0x0index294, $sup76879x16x0x0x0delta303, std::array<u64,4>{v_c15, v_c5, 0, 0}, [&](const std::array<u64,4>& m349) {
            u64 v_c62 = m349[2]; u64 v_c14 = m349[3];
            if (!slog::exists_probe<3,2>(ckindex295, std::array<u64,3>{v_c62, v_c5, 0})) return;
            if (!slog::exists_probe<3,2>(ckindex296, std::array<u64,3>{v_c5, v_c14, 0})) return;
            slog::join_probe_old<3,2>(appindex297, appdelta304, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m350) {
              u64 v_c63 = m350[2];
              slog::join_probe_old<3,3>(ckindex298, ckdelta305, std::array<u64,3>{v_c62, v_c5, v_c63}, [&](const std::array<u64,3>& m351) {
                slog::join_probe_old<3,2>(ckindex299, ckdelta306, std::array<u64,3>{v_c5, v_c14, 0}, [&](const std::array<u64,3>& m352) {
                  u64 v_c64 = m352[2];
                  slog::join_probe_old<2,1>(ck_ansindex300, ck_ansdelta307, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m353) {
                    u64 v_c2 = m353[1];
                    slog::join_probe_old<3,2>(arrowindex301, arrowdelta308, std::array<u64,3>{v_c61, v_c2, 0}, [&](const std::array<u64,3>& m354) {
                      u64 v_c65 = m354[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c65}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck_ans", _fires);
  
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
  // (crule (pre) (scan arrow __t9HVg9 t1 t2) (body (exists ck_ans (1 0) 1 t1) (join ck_ans (1 0) 1 __t9HVg9 __t17cq8) (join ck_ans (1 0) 1 t1 __t37kq10) (join ck (0 1 2) 1 __t17cq8 env e1) (exists $sup76879x16x0x0x0 (1 3 0 2) 2 e1 env) (exists app (1 2 0) 1 e1) (exists ck (1 2 0) 1 env) (join-old ck (0 1 2) 2 (0 1 2) __t37kq10 env e2) (exists app (1 2 0) 2 e1 e2) (join $sup76879x16x0x0x0 (1 2 3 0) 3 e1 e2 env __t6Npw7) (exists ck (0 1 2) 2 __t6Npw7 env) (join app (1 2 0) 2 e1 e2 __t3xua6) (join ck (0 1 2) 3 __t6Npw7 env __t3xua6)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask369 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ck_ansindex355;  slog::Index** ck_ansindex356;  slog::Index** ck_ansindex357;  slog::Index** ckindex358;  slog::Index** $sup76879x16x0x0x0index359;  slog::Index** appindex360;  slog::Index** ckindex361;  slog::Index** ckindex362;  slog::Index** appindex363;  slog::Index** $sup76879x16x0x0x0index364;  slog::Index** ckindex365;  slog::Index** appindex366;  slog::Index** ckindex367;  slog::Index** ckdelta368;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord370({0, 1});
      slog::Relation* readrel371 = db->getRelation("ck_ans");
      head_index[0] = readrel371->getIndex(ord370, false);
      outer_rel = db->getRelation("arrow");
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("ck_ans");
      ck_ansindex355 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("ck_ans");
      ck_ansindex356 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0});
      slog::Relation* readrel377 = db->getRelation("ck_ans");
      ck_ansindex357 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1, 2});
      slog::Relation* readrel379 = db->getRelation("ck");
      ckindex358 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 3, 0, 2});
      slog::Relation* readrel381 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index359 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("app");
      appindex360 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("ck");
      ckindex361 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({0, 1, 2});
      slog::Relation* readrel387 = db->getRelation("ck");
      ckindex362 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({0, 1, 2});
      slog::Relation* readrel389 = db->getRelation("ck");
      ckdelta368 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("app");
      appindex363 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 2, 3, 0});
      slog::Relation* readrel393 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index364 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1, 2});
      slog::Relation* readrel395 = db->getRelation("ck");
      ckindex365 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("app");
      appindex366 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0, 1, 2});
      slog::Relation* readrel399 = db->getRelation("ck");
      ckindex367 = readrel399->getIndex(ord398, false);
  
    }
    ReadTask369(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c61 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c65 = _t[2];
        if (!slog::exists_probe<2,1>(ck_ansindex355, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(ck_ansindex356, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m400) {
          u64 v_c60 = m400[1];
          slog::join_probe<2,1>(ck_ansindex357, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m401) {
            u64 v_c64 = m401[1];
            slog::join_probe<3,1>(ckindex358, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m402) {
              u64 v_c5 = m402[1]; u64 v_c15 = m402[2];
              if (!slog::exists_probe<4,2>($sup76879x16x0x0x0index359, std::array<u64,4>{v_c15, v_c5, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex360, std::array<u64,3>{v_c15, 0, 0})) return;
              if (!slog::exists_probe<3,1>(ckindex361, std::array<u64,3>{v_c5, 0, 0})) return;
              slog::join_probe_old<3,2>(ckindex362, ckdelta368, std::array<u64,3>{v_c64, v_c5, 0}, [&](const std::array<u64,3>& m403) {
                u64 v_c14 = m403[2];
                if (!slog::exists_probe<3,2>(appindex363, std::array<u64,3>{v_c15, v_c14, 0})) return;
                slog::join_probe<4,3>($sup76879x16x0x0x0index364, std::array<u64,4>{v_c15, v_c14, v_c5, 0}, [&](const std::array<u64,4>& m404) {
                  u64 v_c62 = m404[3];
                  if (!slog::exists_probe<3,2>(ckindex365, std::array<u64,3>{v_c62, v_c5, 0})) return;
                  slog::join_probe<3,2>(appindex366, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m405) {
                    u64 v_c63 = m405[2];
                    slog::join_probe<3,3>(ckindex367, std::array<u64,3>{v_c62, v_c5, v_c63}, [&](const std::array<u64,3>& m406) {
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c65}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:arrow", _fires);
  
      if (!_done)
      {
        ReadTask369* _cont = new ReadTask369(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask369(db,b), false);
  // (crule (pre) (scan ck __t57LD5 __t1FJ54 e) (body (exists lam (3 1 0 2) 1 e) (join ck_ans (0 1) 1 __t57LD5 __v0) (join lam (3 1 0 2) 1 e x __t8P1X2 t1) (exists ck (2 0 1) 1 __t8P1X2) (join ext (2 3 0 1) 3 x t1 __t1FJ54 env) (join ck (1 2 0) 2 env __t8P1X2 __t99AN3)) (head (emit-temp temp9j5e118 __t99AN3 __v0 t1) (mkstruct arrow (1 2 0) __t82gT1 t1 __v0)) dem_stlc.slog:16 #f)
  class ReadTask413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lamindex407;  slog::Index** ck_ansindex408;  slog::Index** lamindex409;  slog::Index** ckindex410;  slog::Index** extindex411;  slog::Index** ckindex412;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9j5e118");
      head_rel[1] = db->getRelation("arrow");
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord414({3, 1, 0, 2});
      slog::Relation* readrel415 = db->getRelation("lam");
      lamindex407 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("ck_ans");
      ck_ansindex408 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({3, 1, 0, 2});
      slog::Relation* readrel419 = db->getRelation("lam");
      lamindex409 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({2, 0, 1});
      slog::Relation* readrel421 = db->getRelation("ck");
      ckindex410 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({2, 3, 0, 1});
      slog::Relation* readrel423 = db->getRelation("ext");
      extindex411 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 0});
      slog::Relation* readrel425 = db->getRelation("ck");
      ckindex412 = readrel425->getIndex(ord424, false);
  
    }
    ReadTask413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<4,1>(lamindex407, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        slog::join_probe<2,1>(ck_ansindex408, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m426) {
          u64 v_c8 = m426[1];
          slog::join_probe<4,1>(lamindex409, std::array<u64,4>{v_c3, 0, 0, 0}, [&](const std::array<u64,4>& m427) {
            u64 v_c1 = m427[1]; u64 v_c0 = m427[2]; u64 v_c2 = m427[3];
            if (!slog::exists_probe<3,1>(ckindex410, std::array<u64,3>{v_c0, 0, 0})) return;
            slog::join_probe<4,3>(extindex411, std::array<u64,4>{v_c1, v_c2, v_c4, 0}, [&](const std::array<u64,4>& m428) {
              u64 v_c5 = m428[3];
              slog::join_probe<3,2>(ckindex412, std::array<u64,3>{v_c5, v_c0, 0}, [&](const std::array<u64,3>& m429) {
                u64 v_c6 = m429[2];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c6, v_c8, v_c2});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c8}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:ck", _fires);
  
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
  // (crule (pre) (scan lookup_ans __t8ds158 t) (body (join-old lookup (0 2 1) 1 (0 2 1) __t8ds158 x env) (exists lookup (2 0 1) 1 x) (exists ext (1 2 3 0) 1 env) (join-old $sup76879x10x0x0x0 (1 2 0 3) 2 (1 2 0 3) env x __t4rN257 y) (neq x y) (exists ext (1 2 3 0) 2 env y) (join-old lookup (0 2 1) 2 (0 2 1) __t4rN257 x __t538W56) (join-old ext (0 2 1 3) 3 (0 2 1 3) __t538W56 y env ____2zPL59)) (head (emit lookup_ans (0 1) __t4rN257 t)) dem_stlc.slog:11 #f)
  class ReadTask441 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex430;  slog::Index** lookupindex431;  slog::Index** extindex432;  slog::Index** $sup76879x10x0x0x0index433;  slog::Index** extindex434;  slog::Index** lookupindex435;  slog::Index** extindex436;  slog::Index** lookupdelta437;  slog::Index** $sup76879x10x0x0x0delta438;  slog::Index** lookupdelta439;  slog::Index** extdelta440;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord442({0, 1});
      slog::Relation* readrel443 = db->getRelation("lookup_ans");
      head_index[0] = readrel443->getIndex(ord442, false);
      outer_rel = db->getRelation("lookup_ans");
      std::vector<u16> ord444({0, 2, 1});
      slog::Relation* readrel445 = db->getRelation("lookup");
      lookupindex430 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({0, 2, 1});
      slog::Relation* readrel447 = db->getRelation("lookup");
      lookupdelta437 = readrel447->getIndex(ord446, true);
      std::vector<u16> ord448({2, 0, 1});
      slog::Relation* readrel449 = db->getRelation("lookup");
      lookupindex431 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 2, 3, 0});
      slog::Relation* readrel451 = db->getRelation("ext");
      extindex432 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0, 3});
      slog::Relation* readrel453 = db->getRelation("$sup76879x10x0x0x0");
      $sup76879x10x0x0x0index433 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0, 3});
      slog::Relation* readrel455 = db->getRelation("$sup76879x10x0x0x0");
      $sup76879x10x0x0x0delta438 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({1, 2, 3, 0});
      slog::Relation* readrel457 = db->getRelation("ext");
      extindex434 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 2, 1});
      slog::Relation* readrel459 = db->getRelation("lookup");
      lookupindex435 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 2, 1});
      slog::Relation* readrel461 = db->getRelation("lookup");
      lookupdelta439 = readrel461->getIndex(ord460, true);
      std::vector<u16> ord462({0, 2, 1, 3});
      slog::Relation* readrel463 = db->getRelation("ext");
      extindex436 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 2, 1, 3});
      slog::Relation* readrel465 = db->getRelation("ext");
      extdelta440 = readrel465->getIndex(ord464, true);
  
    }
    ReadTask441(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(lookupindex430, lookupdelta437, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m466) {
          u64 v_c1 = m466[1]; u64 v_c5 = m466[2];
          if (!slog::exists_probe<3,1>(lookupindex431, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<4,1>(extindex432, std::array<u64,4>{v_c5, 0, 0, 0})) return;
          slog::join_probe_old<4,2>($sup76879x10x0x0x0index433, $sup76879x10x0x0x0delta438, std::array<u64,4>{v_c5, v_c1, 0, 0}, [&](const std::array<u64,4>& m467) {
            u64 v_c16 = m467[2]; u64 v_c17 = m467[3];
            if (v_c1 == v_c17) return;
            if (!slog::exists_probe<4,2>(extindex434, std::array<u64,4>{v_c5, v_c17, 0, 0})) return;
            slog::join_probe_old<3,2>(lookupindex435, lookupdelta439, std::array<u64,3>{v_c16, v_c1, 0}, [&](const std::array<u64,3>& m468) {
              u64 v_c18 = m468[2];
              slog::join_probe_old<4,3>(extindex436, extdelta440, std::array<u64,4>{v_c18, v_c17, v_c5, 0}, [&](const std::array<u64,4>& m469) {
                u64 v_c19 = m469[3];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c21}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:lookup_ans", _fires);
  
      if (!_done)
      {
        ReadTask441* _cont = new ReadTask441(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask441(db,b), false);
  // (crule (pre) (scan ext __t9GTJ64 env x t) (body (join-old lookup (1 2 0) 2 (1 2 0) __t9GTJ64 x __t7RPo65)) (head (emit lookup_ans (0 1) __t7RPo65 t)) dem_stlc.slog:10 #f)
  class ReadTask472 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex470;  slog::Index** lookupdelta471;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord473({0, 1});
      slog::Relation* readrel474 = db->getRelation("lookup_ans");
      head_index[0] = readrel474->getIndex(ord473, false);
      outer_rel = db->getRelation("ext");
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("lookup");
      lookupindex470 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0});
      slog::Relation* readrel478 = db->getRelation("lookup");
      lookupdelta471 = readrel478->getIndex(ord477, true);
  
    }
    ReadTask472(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c21 = _t[3];
        slog::join_probe_old<3,2>(lookupindex470, lookupdelta471, std::array<u64,3>{v_c66, v_c1, 0}, [&](const std::array<u64,3>& m479) {
          u64 v_c67 = m479[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c21}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:10", "delta:ext", _fires);
  
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
  // (crule (pre (let __tconst9S2u94 const1f503613ae12cc0c5121fd74)) (scan prog e) (body (join _enum (1 0) 1 __tconst9S2u94 __t835e60)) (head (mkstruct ck (1 2 0) __7GKq93 __t835e60 e)) dem_stlc.slog:30 #f)
  class ReadTask481 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex480;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck");
      outer_rel = db->getRelation("prog");
      std::vector<u16> ord482({1, 0});
      slog::Relation* readrel483 = db->getRelation("_enum");
      _enumindex480 = readrel483->getIndex(ord482, false);
  
    }
    ReadTask481(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const1f503613ae12cc0c5121fd74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        slog::join_probe<2,1>(_enumindex480, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m484) {
          u64 v_c69 = m484[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:30", "delta:prog", _fires);
  
      if (!_done)
      {
        ReadTask481* _cont = new ReadTask481(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask481(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst1wvy37 const4e07408562bedb8b60ce05c1) (let __tconst1K9r35 const4b227777d4dd1fc61c6f884f) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e) (let __tconst6P6s76 constb40d060f542e4963e0fc1392)) (probe var (1 0) 1 __tconst8dNm51 __t0OY020) (body (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (exists num (1 0) 1 __tconst1K9r35) (exists num (1 0) 1 __tconst1wvy37) (exists var (1 0) 1 __tconst3JhQ48) (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists arrow (1 2 0) 1 __t3zgy50) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (join var (1 0) 1 __tconst9nbj32 __t6EL627) (join num (1 0) 1 __tconst1K9r35 __t35Fj36) (join num (1 0) 1 __tconst1wvy37 __t7sPi38) (join var (1 0) 1 __tconst3JhQ48 __t7Q1C43) (join arrow (1 2 0) 1 __t3zgy50 dup0fvT110 __t4oeC31) (eq __t3zgy50 dup0fvT110)) (head (mkstruct app (1 2 0) __t2MLp44 __t7Q1C43 __t0OY020) (mkstruct app (1 2 0) __t4b7B39 __t7sPi38 __t35Fj36) (mkstruct app (1 2 0) __t7G7R28 __t6EL627 __t95AJ25) (mkstruct lam (1 2 3 0) __t16B123 __tconst8dNm51 __t3zgy50 __t0OY020)) dem_stlc.slog:23 #f)
  class ReadTask498 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** numindex485;  slog::Index** varindex486;  slog::Index** numindex487;  slog::Index** numindex488;  slog::Index** varindex489;  slog::Index** _enumindex490;  slog::Index** arrowindex491;  slog::Index** numindex492;  slog::Index** varindex493;  slog::Index** numindex494;  slog::Index** numindex495;  slog::Index** varindex496;  slog::Index** arrowindex497;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("lam");
      std::vector<u16> ord499({1, 0});
      slog::Relation* readrel500 = db->getRelation("var");
      driver_index = readrel500->getIndex(ord499, true);
      std::vector<u16> ord501({1, 0});
      slog::Relation* readrel502 = db->getRelation("num");
      numindex485 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 0});
      slog::Relation* readrel504 = db->getRelation("var");
      varindex486 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("num");
      numindex487 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 0});
      slog::Relation* readrel508 = db->getRelation("num");
      numindex488 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 0});
      slog::Relation* readrel510 = db->getRelation("var");
      varindex489 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 0});
      slog::Relation* readrel512 = db->getRelation("_enum");
      _enumindex490 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 0});
      slog::Relation* readrel514 = db->getRelation("arrow");
      arrowindex491 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 0});
      slog::Relation* readrel516 = db->getRelation("num");
      numindex492 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 0});
      slog::Relation* readrel518 = db->getRelation("var");
      varindex493 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 0});
      slog::Relation* readrel520 = db->getRelation("num");
      numindex494 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("num");
      numindex495 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 0});
      slog::Relation* readrel524 = db->getRelation("var");
      varindex496 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 0});
      slog::Relation* readrel526 = db->getRelation("arrow");
      arrowindex497 = readrel526->getIndex(ord525, false);
  
    }
    ReadTask498(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c53 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c54 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m527) {
        u64 v_c36 = m527[1];
        if (buckethash(v_c36) != bucket) return;
        if (!slog::exists_probe<2,1>(numindex485, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex486, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(numindex487, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<2,1>(numindex488, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(varindex489, std::array<u64,2>{v_c31, 0})) return;
        slog::join_probe<2,1>(_enumindex490, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m528) {
          u64 v_c35 = m528[1];
          if (!slog::exists_probe<3,1>(arrowindex491, std::array<u64,3>{v_c35, 0, 0})) return;
          slog::join_probe<2,1>(numindex492, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m529) {
            u64 v_c47 = m529[1];
            slog::join_probe<2,1>(varindex493, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m530) {
              u64 v_c48 = m530[1];
              slog::join_probe<2,1>(numindex494, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m531) {
                u64 v_c55 = m531[1];
                slog::join_probe<2,1>(numindex495, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m532) {
                  u64 v_c56 = m532[1];
                  slog::join_probe<2,1>(varindex496, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m533) {
                    u64 v_c43 = m533[1];
                    slog::join_probe<3,1>(arrowindex497, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m534) {
                      u64 v_c70 = m534[1]; u64 v_c40 = m534[2];
                      if (v_c35 != v_c70) return;
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c43, v_c36}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c56, v_c55}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c48, v_c47}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c30, v_c35, v_c36}, std::array<u16,4>{1, 2, 3, 0});
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
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "delta:var", _fires);
  
      if (!_done)
      {
        ReadTask498* _cont = new ReadTask498(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask498(db,b), false);
  // (crule (pre (let __trid3XuU80 const79093c59b0bf60c8403ebce3) (let __trel112q81 const74ed1f1471d4dd9b505236e5) (let __tcol2Omn82 const5feceb66ffc86f38d952786c) (let __trel9cyV83 const74ed1f1471d4dd9b505236e5) (let __tcol2YQA84 const6b86b273ff34fce19d6b804e)) (scan $sup76879x16x0x0x0 __d0 e1 e2 env) (body) (head (tycheck env (accept (struct ext) (struct _enum)) __trid3XuU80 __trel112q81 __tcol2Omn82 (1 2 3 4 0)) (tycheck e1 (accept (struct app) (struct lam) (struct num) (struct var)) __trid3XuU80 __trel9cyV83 __tcol2YQA84 (1 2 3 4 0)) (mkstruct ck (1 2 0) __3jHJ79 env e1)) dem_stlc.slog:17 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid536;  u32 sid537;  u32 sid535;  u32 sid538;  u32 sid539;  u32 sid540;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("ck");
      outer_rel = db->getRelation("$sup76879x16x0x0x0");
      sid536 = db->getRelation("_enum")->getStructId();
      sid537 = db->getRelation("app")->getStructId();
      sid535 = db->getRelation("ext")->getStructId();
      sid538 = db->getRelation("lam")->getStructId();
      sid539 = db->getRelation("num")->getStructId();
      sid540 = db->getRelation("var")->getStructId();
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const79093c59b0bf60c8403ebce3;
      u64 v_c72 = v_const74ed1f1471d4dd9b505236e5;
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
      u64 v_c74 = v_const74ed1f1471d4dd9b505236e5;
      u64 v_c75 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c29 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c5 = _t[3];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid535 || decode_struct_id(v_c5) == sid536))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c71, v_c72, v_c73, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c15) && (decode_struct_id(v_c15) == sid537 || decode_struct_id(v_c15) == sid538 || decode_struct_id(v_c15) == sid539 || decode_struct_id(v_c15) == sid540))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c74, v_c75, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c15}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:$sup76879x16x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask541* _cont = new ReadTask541(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask541(db,b), false);
  // (crule (pre) (scan lookup __t4rN257 __t538W56 x) (body (exists lookup (2 0 1) 1 x) (join $sup76879x10x0x0x0 (0 2 1 3) 2 __t4rN257 x env y) (neq x y) (exists lookup (1 2 0) 2 env x) (join ext (0 2 1 3) 3 __t538W56 y env ____2zPL59) (join-old lookup (1 2 0) 2 (1 2 0) env x __t8ds158) (join lookup_ans (0 1) 1 __t8ds158 t)) (head (emit lookup_ans (0 1) __t4rN257 t)) dem_stlc.slog:11 #f)
  class ReadTask549 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex542;  slog::Index** $sup76879x10x0x0x0index543;  slog::Index** lookupindex544;  slog::Index** extindex545;  slog::Index** lookupindex546;  slog::Index** lookup_ansindex547;  slog::Index** lookupdelta548;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord550({0, 1});
      slog::Relation* readrel551 = db->getRelation("lookup_ans");
      head_index[0] = readrel551->getIndex(ord550, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord552({2, 0, 1});
      slog::Relation* readrel553 = db->getRelation("lookup");
      lookupindex542 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({0, 2, 1, 3});
      slog::Relation* readrel555 = db->getRelation("$sup76879x10x0x0x0");
      $sup76879x10x0x0x0index543 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 0});
      slog::Relation* readrel557 = db->getRelation("lookup");
      lookupindex544 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({0, 2, 1, 3});
      slog::Relation* readrel559 = db->getRelation("ext");
      extindex545 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 0});
      slog::Relation* readrel561 = db->getRelation("lookup");
      lookupindex546 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 0});
      slog::Relation* readrel563 = db->getRelation("lookup");
      lookupdelta548 = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({0, 1});
      slog::Relation* readrel565 = db->getRelation("lookup_ans");
      lookup_ansindex547 = readrel565->getIndex(ord564, false);
  
    }
    ReadTask549(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<3,1>(lookupindex542, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<4,2>($sup76879x10x0x0x0index543, std::array<u64,4>{v_c16, v_c1, 0, 0}, [&](const std::array<u64,4>& m566) {
          u64 v_c5 = m566[2]; u64 v_c17 = m566[3];
          if (v_c1 == v_c17) return;
          if (!slog::exists_probe<3,2>(lookupindex544, std::array<u64,3>{v_c5, v_c1, 0})) return;
          slog::join_probe<4,3>(extindex545, std::array<u64,4>{v_c18, v_c17, v_c5, 0}, [&](const std::array<u64,4>& m567) {
            u64 v_c19 = m567[3];
            slog::join_probe_old<3,2>(lookupindex546, lookupdelta548, std::array<u64,3>{v_c5, v_c1, 0}, [&](const std::array<u64,3>& m568) {
              u64 v_c20 = m568[2];
              slog::join_probe<2,1>(lookup_ansindex547, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m569) {
                u64 v_c21 = m569[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c21}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask549* _cont = new ReadTask549(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask549(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst6P6s76 constb40d060f542e4963e0fc1392) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e)) (probe lam (1 0 2 3) 1 __tconst9nbj32 __t9fNk33 __t4oeC31 __t7G7R28) (body (exists _enum (1 0) 1 __tconst6P6s76) (exists lam (1 2 3 0) 1 __tconst8dNm51) (exists var (1 0) 1 __tconst8dNm51) (exists var (1 0) 1 __tconst3JhQ48) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (join lam (1 2 3 0) 2 __tconst3JhQ48 __t4oeC31 __t2MLp44 __t5JUn49) (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50) (join arrow (0 1 2) 2 __t4oeC31 __t3zgy50 dup5MnR114) (eq __t3zgy50 dup5MnR114) (join lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50 __t0OY020 __t16B123) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (join app (0 2 1) 2 __t2MLp44 __t0OY020 __t7Q1C43) (join var (0 1) 2 __t7Q1C43 __tconst3JhQ48) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (join app (0 2 1) 2 __t7G7R28 __t95AJ25 __t6EL627) (join var (0 1) 2 __t6EL627 __tconst9nbj32)) (head (mkstruct lam (1 2 3 0) __t5Erl52 __tconst8dNm51 __t3zgy50 __t5JUn49) (mkstruct app (1 2 0) __t2P4j34 __t9fNk33 __t16B123)) dem_stlc.slog:23 #f)
  class ReadTask587 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex570;  slog::Index** lamindex571;  slog::Index** varindex572;  slog::Index** varindex573;  slog::Index** numindex574;  slog::Index** varindex575;  slog::Index** lamindex576;  slog::Index** _enumindex577;  slog::Index** lamindex578;  slog::Index** arrowindex579;  slog::Index** lamindex580;  slog::Index** varindex581;  slog::Index** appindex582;  slog::Index** varindex583;  slog::Index** numindex584;  slog::Index** appindex585;  slog::Index** varindex586;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lam");
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord588({1, 0, 2, 3});
      slog::Relation* readrel589 = db->getRelation("lam");
      driver_index = readrel589->getIndex(ord588, true);
      std::vector<u16> ord590({1, 0});
      slog::Relation* readrel591 = db->getRelation("_enum");
      _enumindex570 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 3, 0});
      slog::Relation* readrel593 = db->getRelation("lam");
      lamindex571 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("var");
      varindex572 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 0});
      slog::Relation* readrel597 = db->getRelation("var");
      varindex573 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 0});
      slog::Relation* readrel599 = db->getRelation("num");
      numindex574 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 0});
      slog::Relation* readrel601 = db->getRelation("var");
      varindex575 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 3, 0});
      slog::Relation* readrel603 = db->getRelation("lam");
      lamindex576 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 0});
      slog::Relation* readrel605 = db->getRelation("_enum");
      _enumindex577 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 2, 3, 0});
      slog::Relation* readrel607 = db->getRelation("lam");
      lamindex578 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({0, 1, 2});
      slog::Relation* readrel609 = db->getRelation("arrow");
      arrowindex579 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 3, 0});
      slog::Relation* readrel611 = db->getRelation("lam");
      lamindex580 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("var");
      varindex581 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 2, 1});
      slog::Relation* readrel615 = db->getRelation("app");
      appindex582 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({0, 1});
      slog::Relation* readrel617 = db->getRelation("var");
      varindex583 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 0});
      slog::Relation* readrel619 = db->getRelation("num");
      numindex584 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({0, 2, 1});
      slog::Relation* readrel621 = db->getRelation("app");
      appindex585 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("var");
      varindex586 = readrel623->getIndex(ord622, false);
  
    }
    ReadTask587(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,1>(driver_index, std::array<u64,4>{v_c32, 0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m624) {
        u64 v_c45 = m624[1];
        u64 v_c40 = m624[2];
        u64 v_c44 = m624[3];
        if (buckethash(v_c45) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex570, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex571, std::array<u64,4>{v_c30, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(varindex572, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(varindex573, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(numindex574, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex575, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<4,2>(lamindex576, std::array<u64,4>{v_c31, v_c40, 0, 0}, [&](const std::array<u64,4>& m625) {
          u64 v_c41 = m625[2]; u64 v_c38 = m625[3];
          slog::join_probe<2,1>(_enumindex577, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m626) {
            u64 v_c35 = m626[1];
            if (!slog::exists_probe<4,2>(lamindex578, std::array<u64,4>{v_c30, v_c35, 0, 0})) return;
            slog::join_probe<3,2>(arrowindex579, std::array<u64,3>{v_c40, v_c35, 0}, [&](const std::array<u64,3>& m627) {
              u64 v_c76 = m627[2];
              if (v_c35 != v_c76) return;
              slog::join_probe<4,2>(lamindex580, std::array<u64,4>{v_c30, v_c35, 0, 0}, [&](const std::array<u64,4>& m628) {
                u64 v_c36 = m628[2]; u64 v_c37 = m628[3];
                slog::join_probe<2,2>(varindex581, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m629) {
                  slog::join_probe<3,2>(appindex582, std::array<u64,3>{v_c41, v_c36, 0}, [&](const std::array<u64,3>& m630) {
                    u64 v_c43 = m630[2];
                    slog::join_probe<2,2>(varindex583, std::array<u64,2>{v_c43, v_c31}, [&](const std::array<u64,2>& m631) {
                      slog::join_probe<2,1>(numindex584, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m632) {
                        u64 v_c47 = m632[1];
                        slog::join_probe<3,2>(appindex585, std::array<u64,3>{v_c44, v_c47, 0}, [&](const std::array<u64,3>& m633) {
                          u64 v_c48 = m633[2];
                          slog::join_probe<2,2>(varindex586, std::array<u64,2>{v_c48, v_c32}, [&](const std::array<u64,2>& m634) {
                            ++_fires;
                            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c30, v_c35, v_c38}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c45, v_c37}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "delta:lam", _fires);
  
      if (!_done)
      {
        ReadTask587* _cont = new ReadTask587(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask587(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst1wvy37 const4e07408562bedb8b60ce05c1) (let __tconst1K9r35 const4b227777d4dd1fc61c6f884f) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e) (let __tconst6P6s76 constb40d060f542e4963e0fc1392)) (seeded) (body (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists var (1 0) 1 __tconst8dNm51) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (exists num (1 0) 1 __tconst1K9r35) (exists num (1 0) 1 __tconst1wvy37) (exists var (1 0) 1 __tconst3JhQ48) (exists arrow (1 2 0) 1 __t3zgy50) (join lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50 __t0OY020 __t16B123) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (exists app (2 0 1) 1 __t0OY020) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (exists app (2 0 1) 1 __t95AJ25) (join var (1 0) 1 __tconst9nbj32 __t6EL627) (join app (1 2 0) 2 __t6EL627 __t95AJ25 __t7G7R28) (join num (1 0) 1 __tconst1K9r35 __t35Fj36) (exists app (2 0 1) 1 __t35Fj36) (join num (1 0) 1 __tconst1wvy37 __t7sPi38) (join app (1 2 0) 2 __t7sPi38 __t35Fj36 __t4b7B39) (join var (1 0) 1 __tconst3JhQ48 __t7Q1C43) (join app (1 2 0) 2 __t7Q1C43 __t0OY020 __t2MLp44) (join arrow (1 2 0) 1 __t3zgy50 dup1wZH113 __t4oeC31) (eq __t3zgy50 dup1wZH113)) (head (emit prog (0) __t4b7B39) (mkstruct lam (1 2 3 0) __t5JUn49 __tconst3JhQ48 __t4oeC31 __t2MLp44) (mkstruct lam (1 2 3 0) __t9fNk33 __tconst9nbj32 __t4oeC31 __t7G7R28)) dem_stlc.slog:23 #f)
  class ReadTask657 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** _enumindex635;  slog::Index** varindex636;  slog::Index** numindex637;  slog::Index** varindex638;  slog::Index** numindex639;  slog::Index** numindex640;  slog::Index** varindex641;  slog::Index** arrowindex642;  slog::Index** lamindex643;  slog::Index** varindex644;  slog::Index** appindex645;  slog::Index** numindex646;  slog::Index** appindex647;  slog::Index** varindex648;  slog::Index** appindex649;  slog::Index** numindex650;  slog::Index** appindex651;  slog::Index** numindex652;  slog::Index** appindex653;  slog::Index** varindex654;  slog::Index** appindex655;  slog::Index** arrowindex656;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord658({0});
      slog::Relation* readrel659 = db->getRelation("prog");
      head_index[0] = readrel659->getIndex(ord658, false);
      head_rel[1] = db->getRelation("lam");
      std::vector<u16> ord660({1, 2, 3, 0});
      slog::Relation* readrel661 = db->getRelation("lam");
      head_index[1] = readrel661->getIndex(ord660, false);
      head_rel[2] = db->getRelation("lam");
      std::vector<u16> ord662({1, 2, 3, 0});
      slog::Relation* readrel663 = db->getRelation("lam");
      head_index[2] = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0});
      slog::Relation* readrel665 = db->getRelation("_enum");
      _enumindex635 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 0});
      slog::Relation* readrel667 = db->getRelation("var");
      varindex636 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 0});
      slog::Relation* readrel669 = db->getRelation("num");
      numindex637 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 0});
      slog::Relation* readrel671 = db->getRelation("var");
      varindex638 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 0});
      slog::Relation* readrel673 = db->getRelation("num");
      numindex639 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 0});
      slog::Relation* readrel675 = db->getRelation("num");
      numindex640 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 0});
      slog::Relation* readrel677 = db->getRelation("var");
      varindex641 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("arrow");
      arrowindex642 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 3, 0});
      slog::Relation* readrel681 = db->getRelation("lam");
      lamindex643 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("var");
      varindex644 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({2, 0, 1});
      slog::Relation* readrel685 = db->getRelation("app");
      appindex645 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 0});
      slog::Relation* readrel687 = db->getRelation("num");
      numindex646 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({2, 0, 1});
      slog::Relation* readrel689 = db->getRelation("app");
      appindex647 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 0});
      slog::Relation* readrel691 = db->getRelation("var");
      varindex648 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("app");
      appindex649 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 0});
      slog::Relation* readrel695 = db->getRelation("num");
      numindex650 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({2, 0, 1});
      slog::Relation* readrel697 = db->getRelation("app");
      appindex651 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 0});
      slog::Relation* readrel699 = db->getRelation("num");
      numindex652 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("app");
      appindex653 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 0});
      slog::Relation* readrel703 = db->getRelation("var");
      varindex654 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("app");
      appindex655 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 0});
      slog::Relation* readrel707 = db->getRelation("arrow");
      arrowindex656 = readrel707->getIndex(ord706, false);
  
    }
    ReadTask657(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c53 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c54 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex635, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m708) {
        u64 v_c35 = m708[1];
        if (!slog::exists_probe<2,1>(varindex636, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(numindex637, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex638, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(numindex639, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<2,1>(numindex640, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(varindex641, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(arrowindex642, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<4,2>(lamindex643, std::array<u64,4>{v_c30, v_c35, 0, 0}, [&](const std::array<u64,4>& m709) {
          u64 v_c36 = m709[2]; u64 v_c37 = m709[3];
          slog::join_probe<2,2>(varindex644, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m710) {
            if (!slog::exists_probe<3,1>(appindex645, std::array<u64,3>{v_c36, 0, 0})) return;
            slog::join_probe<2,1>(numindex646, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m711) {
              u64 v_c47 = m711[1];
              if (!slog::exists_probe<3,1>(appindex647, std::array<u64,3>{v_c47, 0, 0})) return;
              slog::join_probe<2,1>(varindex648, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m712) {
                u64 v_c48 = m712[1];
                slog::join_probe<3,2>(appindex649, std::array<u64,3>{v_c48, v_c47, 0}, [&](const std::array<u64,3>& m713) {
                  u64 v_c44 = m713[2];
                  slog::join_probe<2,1>(numindex650, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m714) {
                    u64 v_c55 = m714[1];
                    if (!slog::exists_probe<3,1>(appindex651, std::array<u64,3>{v_c55, 0, 0})) return;
                    slog::join_probe<2,1>(numindex652, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m715) {
                      u64 v_c56 = m715[1];
                      slog::join_probe<3,2>(appindex653, std::array<u64,3>{v_c56, v_c55, 0}, [&](const std::array<u64,3>& m716) {
                        u64 v_c77 = m716[2];
                        slog::join_probe<2,1>(varindex654, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m717) {
                          u64 v_c43 = m717[1];
                          slog::join_probe<3,2>(appindex655, std::array<u64,3>{v_c43, v_c36, 0}, [&](const std::array<u64,3>& m718) {
                            u64 v_c41 = m718[2];
                            slog::join_probe<3,1>(arrowindex656, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m719) {
                              u64 v_c78 = m719[1]; u64 v_c40 = m719[2];
                              if (v_c35 != v_c78) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c77}, std::array<u16,1>{0});
                              slog::emit_struct_checked<4>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c31, v_c40, v_c41}, std::array<u16,4>{1, 2, 3, 0});
                              slog::emit_struct_checked<4>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c32, v_c40, v_c44}, std::array<u16,4>{1, 2, 3, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask657(db,b));
  // (crule (pre) (scan temp8Tl3109 e env t1 x) (body (join ext (1 2 3 0) 3 env x t1 __t0xCE11)) (head (mkstruct ck (1 2 0) __3ANJ85 __t0xCE11 e)) dem_stlc.slog:16 #f)
  class ReadTask721 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extindex720;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck");
      outer_rel = db->getRelation("temp8Tl3109");
      std::vector<u16> ord722({1, 2, 3, 0});
      slog::Relation* readrel723 = db->getRelation("ext");
      extindex720 = readrel723->getIndex(ord722, false);
  
    }
    ReadTask721(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c1 = _t[3];
        slog::join_probe<4,3>(extindex720, std::array<u64,4>{v_c5, v_c1, v_c2, 0}, [&](const std::array<u64,4>& m724) {
          u64 v_c79 = m724[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c79, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:temp8Tl3109", _fires);
  
      if (!_done)
      {
        ReadTask721* _cont = new ReadTask721(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask721(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst6P6s76 constb40d060f542e4963e0fc1392) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e)) (scan app __t2P4j34 __t9fNk33 __t16B123) (body (exists _enum (1 0) 1 __tconst6P6s76) (exists var (1 0) 1 __tconst8dNm51) (exists lam (0 1 2 3) 2 __t9fNk33 __tconst9nbj32) (exists lam (1 2 3 0) 1 __tconst3JhQ48) (exists lam (1 2 3 0) 1 __tconst8dNm51) (exists var (1 0) 1 __tconst3JhQ48) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (join lam (0 1 2 3) 2 __t16B123 __tconst8dNm51 __t3zgy50 __t0OY020) (join _enum (0 1) 2 __t3zgy50 __tconst6P6s76) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (exists arrow (1 2 0) 1 __t3zgy50) (exists lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50) (exists app (2 0 1) 1 __t0OY020) (join lam (0 1 2 3) 2 __t9fNk33 __tconst9nbj32 __t4oeC31 __t7G7R28) (exists lam (1 2 3 0) 2 __tconst3JhQ48 __t4oeC31) (join arrow (0 1 2) 2 __t4oeC31 __t3zgy50 dup2a9S116) (eq __t3zgy50 dup2a9S116) (join lam (1 2 3 0) 2 __tconst3JhQ48 __t4oeC31 __t2MLp44 __t5JUn49) (exists app (0 2 1) 2 __t2MLp44 __t0OY020) (join lam (1 2 3 0) 3 __tconst8dNm51 __t3zgy50 __t5JUn49 __t5Erl52) (join app (0 2 1) 2 __t2MLp44 __t0OY020 __t7Q1C43) (join var (0 1) 2 __t7Q1C43 __tconst3JhQ48) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (join app (0 2 1) 2 __t7G7R28 __t95AJ25 __t6EL627) (join var (0 1) 2 __t6EL627 __tconst9nbj32)) (head (emit prog (0) __t5Erl52) (emit prog (0) __t2P4j34)) dem_stlc.slog:23 #f)
  class ReadTask750 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex725;  slog::Index** varindex726;  slog::Index** lamindex727;  slog::Index** lamindex728;  slog::Index** lamindex729;  slog::Index** varindex730;  slog::Index** numindex731;  slog::Index** varindex732;  slog::Index** lamindex733;  slog::Index** _enumindex734;  slog::Index** varindex735;  slog::Index** arrowindex736;  slog::Index** lamindex737;  slog::Index** appindex738;  slog::Index** lamindex739;  slog::Index** lamindex740;  slog::Index** arrowindex741;  slog::Index** lamindex742;  slog::Index** appindex743;  slog::Index** lamindex744;  slog::Index** appindex745;  slog::Index** varindex746;  slog::Index** numindex747;  slog::Index** appindex748;  slog::Index** varindex749;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord751({0});
      slog::Relation* readrel752 = db->getRelation("prog");
      head_index[0] = readrel752->getIndex(ord751, false);
      head_rel[1] = db->getRelation("prog");
      std::vector<u16> ord753({0});
      slog::Relation* readrel754 = db->getRelation("prog");
      head_index[1] = readrel754->getIndex(ord753, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord755({1, 0});
      slog::Relation* readrel756 = db->getRelation("_enum");
      _enumindex725 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 0});
      slog::Relation* readrel758 = db->getRelation("var");
      varindex726 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({0, 1, 2, 3});
      slog::Relation* readrel760 = db->getRelation("lam");
      lamindex727 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 2, 3, 0});
      slog::Relation* readrel762 = db->getRelation("lam");
      lamindex728 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 3, 0});
      slog::Relation* readrel764 = db->getRelation("lam");
      lamindex729 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 0});
      slog::Relation* readrel766 = db->getRelation("var");
      varindex730 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 0});
      slog::Relation* readrel768 = db->getRelation("num");
      numindex731 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0});
      slog::Relation* readrel770 = db->getRelation("var");
      varindex732 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({0, 1, 2, 3});
      slog::Relation* readrel772 = db->getRelation("lam");
      lamindex733 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({0, 1});
      slog::Relation* readrel774 = db->getRelation("_enum");
      _enumindex734 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({0, 1});
      slog::Relation* readrel776 = db->getRelation("var");
      varindex735 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 0});
      slog::Relation* readrel778 = db->getRelation("arrow");
      arrowindex736 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 2, 3, 0});
      slog::Relation* readrel780 = db->getRelation("lam");
      lamindex737 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({2, 0, 1});
      slog::Relation* readrel782 = db->getRelation("app");
      appindex738 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({0, 1, 2, 3});
      slog::Relation* readrel784 = db->getRelation("lam");
      lamindex739 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 2, 3, 0});
      slog::Relation* readrel786 = db->getRelation("lam");
      lamindex740 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({0, 1, 2});
      slog::Relation* readrel788 = db->getRelation("arrow");
      arrowindex741 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 3, 0});
      slog::Relation* readrel790 = db->getRelation("lam");
      lamindex742 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({0, 2, 1});
      slog::Relation* readrel792 = db->getRelation("app");
      appindex743 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 3, 0});
      slog::Relation* readrel794 = db->getRelation("lam");
      lamindex744 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 2, 1});
      slog::Relation* readrel796 = db->getRelation("app");
      appindex745 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1});
      slog::Relation* readrel798 = db->getRelation("var");
      varindex746 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 0});
      slog::Relation* readrel800 = db->getRelation("num");
      numindex747 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 2, 1});
      slog::Relation* readrel802 = db->getRelation("app");
      appindex748 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({0, 1});
      slog::Relation* readrel804 = db->getRelation("var");
      varindex749 = readrel804->getIndex(ord803, false);
  
    }
    ReadTask750(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c31 = v_const2bc983a5942276eb00a75e21;
      u64 v_c32 = v_const30f8b180d63559f2512b744f;
      u64 v_c33 = v_constb40d060f542e4963e0fc1392;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c45 = _t[1];
        u64 v_c37 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex725, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,1>(varindex726, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<4,2>(lamindex727, std::array<u64,4>{v_c45, v_c32, 0, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex728, std::array<u64,4>{v_c31, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex729, std::array<u64,4>{v_c30, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(varindex730, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(numindex731, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(varindex732, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<4,2>(lamindex733, std::array<u64,4>{v_c37, v_c30, 0, 0}, [&](const std::array<u64,4>& m805) {
          u64 v_c35 = m805[2]; u64 v_c36 = m805[3];
          slog::join_probe<2,2>(_enumindex734, std::array<u64,2>{v_c35, v_c33}, [&](const std::array<u64,2>& m806) {
            slog::join_probe<2,2>(varindex735, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m807) {
              if (!slog::exists_probe<3,1>(arrowindex736, std::array<u64,3>{v_c35, 0, 0})) return;
              if (!slog::exists_probe<4,2>(lamindex737, std::array<u64,4>{v_c30, v_c35, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex738, std::array<u64,3>{v_c36, 0, 0})) return;
              slog::join_probe<4,2>(lamindex739, std::array<u64,4>{v_c45, v_c32, 0, 0}, [&](const std::array<u64,4>& m808) {
                u64 v_c40 = m808[2]; u64 v_c44 = m808[3];
                if (!slog::exists_probe<4,2>(lamindex740, std::array<u64,4>{v_c31, v_c40, 0, 0})) return;
                slog::join_probe<3,2>(arrowindex741, std::array<u64,3>{v_c40, v_c35, 0}, [&](const std::array<u64,3>& m809) {
                  u64 v_c80 = m809[2];
                  if (v_c35 != v_c80) return;
                  slog::join_probe<4,2>(lamindex742, std::array<u64,4>{v_c31, v_c40, 0, 0}, [&](const std::array<u64,4>& m810) {
                    u64 v_c41 = m810[2]; u64 v_c38 = m810[3];
                    if (!slog::exists_probe<3,2>(appindex743, std::array<u64,3>{v_c41, v_c36, 0})) return;
                    slog::join_probe<4,3>(lamindex744, std::array<u64,4>{v_c30, v_c35, v_c38, 0}, [&](const std::array<u64,4>& m811) {
                      u64 v_c39 = m811[3];
                      slog::join_probe<3,2>(appindex745, std::array<u64,3>{v_c41, v_c36, 0}, [&](const std::array<u64,3>& m812) {
                        u64 v_c43 = m812[2];
                        slog::join_probe<2,2>(varindex746, std::array<u64,2>{v_c43, v_c31}, [&](const std::array<u64,2>& m813) {
                          slog::join_probe<2,1>(numindex747, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m814) {
                            u64 v_c47 = m814[1];
                            slog::join_probe<3,2>(appindex748, std::array<u64,3>{v_c44, v_c47, 0}, [&](const std::array<u64,3>& m815) {
                              u64 v_c48 = m815[2];
                              slog::join_probe<2,2>(varindex749, std::array<u64,2>{v_c48, v_c32}, [&](const std::array<u64,2>& m816) {
                                ++_fires;
                                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
                                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask750* _cont = new ReadTask750(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask750(db,b), false);
  // (crule (pre) (scan $sup76879x16x0x0x0 __t6Npw7 e1 e2 env) (body (exists ck (0 1 2) 2 __t6Npw7 env) (exists ck (1 2 0) 2 env e1) (exists ck (1 2 0) 2 env e2) (join-old app (1 2 0) 2 (1 2 0) e1 e2 __t3xua6) (join-old ck (0 1 2) 3 (0 1 2) __t6Npw7 env __t3xua6) (join-old ck (1 2 0) 2 (1 2 0) env e1 __t17cq8) (exists ck_ans (0 1) 1 __t17cq8) (join-old ck (1 2 0) 2 (1 2 0) env e2 __t37kq10) (exists ck_ans (0 1) 1 __t37kq10) (join ck_ans (0 1) 1 __t17cq8 __t9HVg9) (join ck_ans (0 1) 1 __t37kq10 t1) (join-old arrow (0 1 2) 2 (0 1 2) __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask834 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex817;  slog::Index** ckindex818;  slog::Index** ckindex819;  slog::Index** appindex820;  slog::Index** ckindex821;  slog::Index** ckindex822;  slog::Index** ck_ansindex823;  slog::Index** ckindex824;  slog::Index** ck_ansindex825;  slog::Index** ck_ansindex826;  slog::Index** ck_ansindex827;  slog::Index** arrowindex828;  slog::Index** appdelta829;  slog::Index** ckdelta830;  slog::Index** ckdelta831;  slog::Index** ckdelta832;  slog::Index** arrowdelta833;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord835({0, 1});
      slog::Relation* readrel836 = db->getRelation("ck_ans");
      head_index[0] = readrel836->getIndex(ord835, false);
      outer_rel = db->getRelation("$sup76879x16x0x0x0");
      std::vector<u16> ord837({0, 1, 2});
      slog::Relation* readrel838 = db->getRelation("ck");
      ckindex817 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 0});
      slog::Relation* readrel840 = db->getRelation("ck");
      ckindex818 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 2, 0});
      slog::Relation* readrel842 = db->getRelation("ck");
      ckindex819 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 2, 0});
      slog::Relation* readrel844 = db->getRelation("app");
      appindex820 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({1, 2, 0});
      slog::Relation* readrel846 = db->getRelation("app");
      appdelta829 = readrel846->getIndex(ord845, true);
      std::vector<u16> ord847({0, 1, 2});
      slog::Relation* readrel848 = db->getRelation("ck");
      ckindex821 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({0, 1, 2});
      slog::Relation* readrel850 = db->getRelation("ck");
      ckdelta830 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({1, 2, 0});
      slog::Relation* readrel852 = db->getRelation("ck");
      ckindex822 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 2, 0});
      slog::Relation* readrel854 = db->getRelation("ck");
      ckdelta831 = readrel854->getIndex(ord853, true);
      std::vector<u16> ord855({0, 1});
      slog::Relation* readrel856 = db->getRelation("ck_ans");
      ck_ansindex823 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 0});
      slog::Relation* readrel858 = db->getRelation("ck");
      ckindex824 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("ck");
      ckdelta832 = readrel860->getIndex(ord859, true);
      std::vector<u16> ord861({0, 1});
      slog::Relation* readrel862 = db->getRelation("ck_ans");
      ck_ansindex825 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({0, 1});
      slog::Relation* readrel864 = db->getRelation("ck_ans");
      ck_ansindex826 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({0, 1});
      slog::Relation* readrel866 = db->getRelation("ck_ans");
      ck_ansindex827 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({0, 1, 2});
      slog::Relation* readrel868 = db->getRelation("arrow");
      arrowindex828 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({0, 1, 2});
      slog::Relation* readrel870 = db->getRelation("arrow");
      arrowdelta833 = readrel870->getIndex(ord869, true);
  
    }
    ReadTask834(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c5 = _t[3];
        if (!slog::exists_probe<3,2>(ckindex817, std::array<u64,3>{v_c62, v_c5, 0})) return;
        if (!slog::exists_probe<3,2>(ckindex818, std::array<u64,3>{v_c5, v_c15, 0})) return;
        if (!slog::exists_probe<3,2>(ckindex819, std::array<u64,3>{v_c5, v_c14, 0})) return;
        slog::join_probe_old<3,2>(appindex820, appdelta829, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m871) {
          u64 v_c63 = m871[2];
          slog::join_probe_old<3,3>(ckindex821, ckdelta830, std::array<u64,3>{v_c62, v_c5, v_c63}, [&](const std::array<u64,3>& m872) {
            slog::join_probe_old<3,2>(ckindex822, ckdelta831, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m873) {
              u64 v_c60 = m873[2];
              if (!slog::exists_probe<2,1>(ck_ansindex823, std::array<u64,2>{v_c60, 0})) return;
              slog::join_probe_old<3,2>(ckindex824, ckdelta832, std::array<u64,3>{v_c5, v_c14, 0}, [&](const std::array<u64,3>& m874) {
                u64 v_c64 = m874[2];
                if (!slog::exists_probe<2,1>(ck_ansindex825, std::array<u64,2>{v_c64, 0})) return;
                slog::join_probe<2,1>(ck_ansindex826, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m875) {
                  u64 v_c61 = m875[1];
                  slog::join_probe<2,1>(ck_ansindex827, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m876) {
                    u64 v_c2 = m876[1];
                    slog::join_probe_old<3,2>(arrowindex828, arrowdelta833, std::array<u64,3>{v_c61, v_c2, 0}, [&](const std::array<u64,3>& m877) {
                      u64 v_c65 = m877[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c65}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:$sup76879x16x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask834* _cont = new ReadTask834(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask834(db,b), false);
}

